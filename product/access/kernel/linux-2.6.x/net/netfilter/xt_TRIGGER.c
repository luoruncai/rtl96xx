/* Kernel module to match the port-ranges, trigger related port-ranges,
 * and alters the destination to a local IP address.
 *
 * Copyright (C) 2003, CyberTAN Corporation
 * All Rights Reserved.
 *
 * Description:
 *   This is kernel module for port-triggering.
 *
 *   The module follows the Netfilter framework, called extended packet 
 *   matching modules. 
 */

#if 0
#include <linux/types.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/timer.h>
#include <linux/module.h>
#include <linux/netfilter.h>
#include <linux/netdevice.h>
#include <linux/if.h>
#include <linux/inetdevice.h>
#include <net/protocol.h>
#include <net/checksum.h>

#include <linux/netfilter_ipv4.h>
#include <linux/netfilter_ipv4/ip_tables.h>
#include <linux/netfilter_ipv4/ip_conntrack.h>
#include <linux/netfilter_ipv4/ip_conntrack_core.h>
#include <linux/netfilter_ipv4/ip_conntrack_tuple.h>
#include <linux/netfilter_ipv4/ip_autofw.h>
#include <linux/netfilter_ipv4/lockhelp.h>
#include <linux/netfilter_ipv4/ip_nat_rule.h>
#include <linux/netfilter_ipv4/ipt_TRIGGER.h>
#include <linux/netfilter_ipv4/ip_nat.h>

#include <linux/netfilter_ipv4/ip_nat_rule.h>
#endif

#include <linux/module.h>
#include <linux/skbuff.h>
#include <linux/ip.h>
#include <net/checksum.h>

#include <linux/netfilter/x_tables.h>
#include <linux/netfilter/xt_TRIGGER.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Netfilter Core Team <coreteam@netfilter.org>");
MODULE_DESCRIPTION("iptables trigger target module");

/* This rwlock protects the main hash table, protocol/helper/expected
 *    registrations, conntrack timers*/
//#define ASSERT_READ_LOCK(x) MUST_BE_READ_LOCKED(&ip_conntrack_lock)
//#define ASSERT_WRITE_LOCK(x) MUST_BE_WRITE_LOCKED(&ip_conntrack_lock)
#define ASSERT_READ_LOCK(x) 
#define ASSERT_WRITE_LOCK(x) 
//#include <linux/netfilter_ipv4/listhelp.h>

#if 0
#define DEBUGP printk
#else
#define DEBUGP(format, args...)
#endif

struct ipt_trigger {
	struct list_head list;		/* Trigger list */
	struct timer_list timeout;	/* Timer for list destroying */
	u_int32_t srcip;		/* Outgoing source address */
	u_int32_t dstip;		/* Outgoing destination address */
	u_int16_t mproto;		/* Trigger protocol */
	u_int16_t rproto;		/* Related protocol */
	struct ipt_trigger_ports ports;	/* Trigger and related ports */
	u_int8_t reply;			/* Confirm a reply connection */
};

LIST_HEAD(trigger_list);
//DECLARE_LOCK(ip_trigger_lock);

#if 0   // To-do
static void trigger_refresh(struct ipt_trigger *trig, unsigned long extra_jiffies)
{
    DEBUGP("%s: \n", __FUNCTION__);
    IP_NF_ASSERT(trig);
    write_lock_bh(&ip_conntrack_lock);

    /* Need del_timer for race avoidance (may already be dying). */
    if (del_timer(&trig->timeout)) {
	trig->timeout.expires = jiffies + extra_jiffies;
	add_timer(&trig->timeout);
    }

    write_unlock_bh(&ip_conntrack_lock);
}


static void __del_trigger(struct ipt_trigger *trig)
{
    DEBUGP("%s: \n", __FUNCTION__);
    IP_NF_ASSERT(trig);
    ASSERT_WRITE_LOCK(&ip_conntrack_lock);

     /* delete from 'trigger_list' */
    list_del(&trig->list);
    kfree(trig);
}

static void trigger_timeout(unsigned long ul_trig)
{
    struct ipt_trigger *trig= (void *) ul_trig;

    DEBUGP("trigger list %p timed out\n", trig);
    write_lock_bh(&ip_conntrack_lock);
    __del_trigger(trig);
    write_unlock_bh(&ip_conntrack_lock);
}

static unsigned int
add_new_trigger(struct ipt_trigger *trig)
{
    struct ipt_trigger *new;

    DEBUGP("!!!!!!!!!!!! %s !!!!!!!!!!!\n", __FUNCTION__);
    write_lock_bh(&ip_conntrack_lock);
    new = (struct ipt_trigger *)
	kmalloc(sizeof(struct ipt_trigger), GFP_ATOMIC);

    if (!new) {
	write_unlock_bh(&ip_conntrack_lock);
	DEBUGP("%s: OOM allocating trigger list\n", __FUNCTION__);
	return -ENOMEM;
    }

    memset(new, 0, sizeof(*trig));
    INIT_LIST_HEAD(&new->list);
    memcpy(new, trig, sizeof(*trig));

    /* add to global table of trigger */
    list_prepend(&trigger_list, &new->list);
    /* add and start timer if required */
    init_timer(&new->timeout);
    new->timeout.data = (unsigned long)new;
    new->timeout.function = trigger_timeout;
    new->timeout.expires = jiffies + (TRIGGER_TIMEOUT * HZ);
    add_timer(&new->timeout);
	    
    write_unlock_bh(&ip_conntrack_lock);

    return 0;
}

static inline int trigger_out_matched(const struct ipt_trigger *i,
	const u_int16_t proto, const u_int16_t dport)
{
    DEBUGP("%s: i=%p, proto= %d, dport=%d.\n", __FUNCTION__, i, proto, dport);
    DEBUGP("%s: Got one, mproto= %d, mport[0..1]=%d, %d.\n", __FUNCTION__, 
	    i->mproto, i->ports.mport[0], i->ports.mport[1]);

    return ((i->mproto == proto) && (i->ports.mport[0] <= dport) 
	    && (i->ports.mport[1] >= dport));
}


static unsigned int
trigger_out(struct sk_buff *skb, const void *targinfo)
{
    const struct ipt_trigger_info *info = targinfo;
    struct ipt_trigger trig, *found;
    const struct iphdr *iph = ip_hdr(skb);
    struct tcphdr *tcph = (void *)iph + iph->ihl*4;	/* Might be TCP, UDP */

    DEBUGP("############# %s ############\n", __FUNCTION__);
    /* Check if the trigger range has already existed in 'trigger_list'. */

    found = LIST_FIND(&trigger_list, trigger_out_matched, struct ipt_trigger *, iph->protocol, ntohs(tcph->dest));

    if (found) {
	/* Yeah, it exists. We need to update(delay) the destroying timer. */
	trigger_refresh(found, TRIGGER_TIMEOUT * HZ);
	/* In order to allow multiple hosts use the same port range, we update
	   the 'saddr' after previous trigger has a reply connection. */
	if (found->reply)
	    found->srcip = iph->saddr;
    }
    else {
	/* Create new trigger */
	memset(&trig, 0, sizeof(trig));
	trig.srcip = iph->saddr;
	trig.mproto = iph->protocol;
	trig.rproto = info->proto;
	memcpy(&trig.ports, &info->ports, sizeof(struct ipt_trigger_ports));
	add_new_trigger(&trig);	/* Add the new 'trig' to list 'trigger_list'. */
	DEBUGP("new trigger:srcip=%d.%d.%d.%d mproto=%d rproto=%d mport[%d-%d] rport[%d-%d]\n",
		NIPQUAD(trig.srcip),trig.mproto,trig.rproto,trig.ports.mport[0],trig.ports.mport[1],
		trig.ports.rport[0],trig.ports.rport[1]);
    }

    return XT_CONTINUE;	/* We don't block any packet. */
}


static inline int trigger_in_matched(const struct ipt_trigger *i,
	const u_int16_t proto, const u_int16_t dport)
{
    DEBUGP("%s: i=%p, proto= %d, dport=%d.\n", __FUNCTION__, i, proto, dport);
    DEBUGP("%s: Got one, rproto= %d, rport[0..1]=%d, %d.\n", __FUNCTION__, 
	    i->rproto, i->ports.rport[0], i->ports.rport[1]);
    u_int16_t rproto = i->rproto;

    if (!rproto)
	rproto = proto;

    return ((rproto == proto) && (i->ports.rport[0] <= dport) 
	    && (i->ports.rport[1] >= dport));
}

static unsigned int
trigger_in(struct sk_buff **pskb,
		unsigned int hooknum,
		const struct net_device *in,
		const struct net_device *out,
		const void *targinfo)
{
    struct ipt_trigger *found;
    const struct iphdr *iph = (*pskb)->nh.iph;
    struct tcphdr *tcph = (void *)iph + iph->ihl*4;	/* Might be TCP, UDP */

    /* Check if the trigger-ed range has already existed in 'trigger_list'. */
    found = LIST_FIND(&trigger_list, trigger_in_matched,
	 struct ipt_trigger *, iph->protocol, ntohs(tcph->dest));
    if (found) {
	DEBUGP("############# %s ############\n", __FUNCTION__);
	/* Yeah, it exists. We need to update(delay) the destroying timer. */
	trigger_refresh(found, TRIGGER_TIMEOUT * HZ);
	return NF_ACCEPT;	/* Accept it, or the imcoming packet could be 
				   dropped in the FORWARD chain */
    }
 
    return IPT_CONTINUE;	/* Our job is the interception. */
}

static unsigned int
trigger_dnat(struct sk_buff **pskb,
		unsigned int hooknum,
		const struct net_device *in,
		const struct net_device *out,
		const void *targinfo)
{
    struct ipt_trigger *found;
    const struct iphdr *iph = (*pskb)->nh.iph;
    struct tcphdr *tcph = (void *)iph + iph->ihl*4;	/* Might be TCP, UDP */
    struct ip_conntrack *ct;
    enum ip_conntrack_info ctinfo;
    struct ip_nat_range newrange;

    IP_NF_ASSERT(hooknum == NF_IP_PRE_ROUTING);
    /* Check if the trigger-ed range has already existed in 'trigger_list'. */
    found = LIST_FIND(&trigger_list, trigger_in_matched,
	    struct ipt_trigger *, iph->protocol, ntohs(tcph->dest));

    if (!found || !found->srcip)
	return IPT_CONTINUE;	/* We don't block any packet. */

    DEBUGP("############# %s ############\n", __FUNCTION__);
    found->reply = 1;	/* Confirm there has been a reply connection. */
    ct = ip_conntrack_get(*pskb, &ctinfo);
    IP_NF_ASSERT(ct && (ctinfo == IP_CT_NEW));

    DEBUGP("%s: hooknum=%d got ", __FUNCTION__,hooknum);
    DUMP_TUPLE(&ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple);

    /* Alter the destination of imcoming packet. */
    newrange = ((struct ip_nat_range)
	    {   IP_NAT_RANGE_MAP_IPS,
	             found->srcip, found->srcip,
	             { 0 }, { 0 }
	            });
//add by ramen to let the packet through our modem 2008/03/06
	(*pskb)->nfctinfo=IP_CT_RELATED;
    /* Hand modified range to generic setup. */
    return ip_nat_setup_info(ct, &newrange, hooknum);
}
#endif


#if 0
static unsigned int
trigger_target(struct sk_buff **pskb,
		const struct net_device *in,
		const struct net_device *out,
		unsigned int hooknum,
		const struct xt_target *target,
		const void *targinfo)
#endif
static unsigned int
trigger_target(struct sk_buff *skb, const struct xt_target_param *par)
{
    const struct ipt_trigger_info *info = par->targinfo;
    const struct iphdr *iph = ip_hdr(skb);

    DEBUGP("%s: type = %s\n", __FUNCTION__, 
	    (info->type == IPT_TRIGGER_DNAT) ? "dnat" :
	    (info->type == IPT_TRIGGER_IN) ? "in" : "out"); 

    /* The Port-trigger only supports TCP and UDP. */
    if ((iph->protocol != IPPROTO_TCP) && (iph->protocol != IPPROTO_UDP))
	return XT_CONTINUE;

#if 0   // to-do
    if (info->type == IPT_TRIGGER_OUT)
	return trigger_out(skb, info);

    else if (info->type == IPT_TRIGGER_IN)
	return trigger_in(pskb, info);
    else if (info->type == IPT_TRIGGER_DNAT)
    	return trigger_dnat(pskb, info);
#endif

    return XT_CONTINUE;
}

#if 0
static int
trigger_check(const char *tablename,
	       const void *e,
	       const struct xt_target *target,
	       void *targinfo,
	       unsigned int hook_mask)
#endif
static bool trigger_check(const struct xt_tgchk_param *par)
{
	const struct ipt_trigger_info *info = par->targinfo;
	struct list_head *cur_item, *tmp_item;

#if 0
	if ((strcmp(tablename, "mangle") == 0)) {
		DEBUGP("trigger_check: bad table `%s'.\n", tablename);
		return 0;
	}
	/*if (targinfosize != IPT_ALIGN(sizeof(*info))) {
		DEBUGP("trigger_check: size %u.\n", targinfosize);
		return 0;
	}*/
	if (hook_mask & ~((1 << NF_IP_PRE_ROUTING) | (1 << NF_IP_FORWARD))) {
		DEBUGP("trigger_check: bad hooks %x.\n", hook_mask);
		return 0;
	}
	if (info->proto) {
	    if (info->proto != IPPROTO_TCP && info->proto != IPPROTO_UDP) {
		DEBUGP("trigger_check: bad proto %d.\n", info->proto);
		return 0;
	    }
	}
	if (info->type == IPT_TRIGGER_OUT) {
	    if (!info->ports.mport[0] || !info->ports.rport[0]) {
		DEBUGP("trigger_check: Try 'iptbles -j TRIGGER -h' for help.\n");
		return 0;
	    }
	}

	/* Empty the 'trigger_list' */
	list_for_each_safe(cur_item, tmp_item, &trigger_list) {
	    struct ipt_trigger *trig = (void *)cur_item;

	    DEBUGP("%s: list_for_each_safe(): %p.\n", __FUNCTION__, trig);
	    del_timer(&trig->timeout);
	    __del_trigger(trig);
	}
#endif
	return 1;
}

#if 0
static struct ipt_target trigger_reg = {
	.name		= "TRIGGER",
	.target		= trigger_target,
	.targetsize	= sizeof(struct ipt_trigger_info),
	.table		= "nat",
	.hooks		= (1 << NF_IP_PRE_ROUTING) | (1 << NF_IP_LOCAL_OUT),
	.checkentry	= trigger_check,
	.me		= THIS_MODULE,
};
#endif

static struct xt_target trigger_tg_reg[] __read_mostly = {
	{
		.name		= "TRIGGER",		
		.family		= NFPROTO_IPV4,		
		.checkentry	= trigger_check,
		.target		= trigger_target,
		.targetsize	= sizeof(struct ipt_trigger_info),
		.table		= "nat",
		.me		= THIS_MODULE,
	},
};

static int __init ipt_trigger_init(void)
{
	//return ipt_register_target(&trigger_reg);
	return xt_register_targets(trigger_tg_reg, ARRAY_SIZE(trigger_tg_reg));
}

static void __exit ipt_trigger_fini(void)
{
	//ipt_unregister_target(&trigger_reg);
	xt_unregister_targets(trigger_tg_reg, ARRAY_SIZE(trigger_tg_reg));
}

module_init(ipt_trigger_init);
module_exit(ipt_trigger_fini);

