/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 15999 2007-03-25 22:32:02Z dts12 $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "cltTemplateInterfaceTable.h"

#include "ipc_interfaceTC.h"

#ifndef DBGID
#define DBGID  "hc:clttmpliftable"
#endif 

#ifndef DBGID
#define DBGID "defalut"
#endif 


LOCAL_COMMIT_DECLARE();

#define local_commit()  LOCAL_COMMIT(500, cltTemplateInterfaceTable_commit, NULL)


/** Initializes the cltTemplateInterfaceTable module */
void
init_cltTemplateInterfaceTable(void)
{
    /*
     * here we initialize all the tables we're planning on supporting 
     */
    initialize_table_cltTemplateInterfaceTable();
}

//# Determine the first/last column names

/** Initialize the cltTemplateInterfaceTable table by defining its contents and how it's structured */
void
initialize_table_cltTemplateInterfaceTable(void)
{
    static oid      cltTemplateInterfaceTable_oid[] =
        { 1, 3, 6, 1, 4, 1, 36368, 1, 1, 1, 1, 4, 2, 3 };
    size_t          cltTemplateInterfaceTable_oid_len =
        OID_LENGTH(cltTemplateInterfaceTable_oid);
    netsnmp_handler_registration *reg;
    netsnmp_iterator_info *iinfo;
    netsnmp_table_registration_info *table_info;

	DEBUGMSGTL((DBGID, "Initializing\n"));

    reg =
        netsnmp_create_handler_registration("cltTemplateInterfaceTable",
                                            cltTemplateInterfaceTable_handler,
                                            cltTemplateInterfaceTable_oid,
                                            cltTemplateInterfaceTable_oid_len,
                                            HANDLER_CAN_RWRITE);

    table_info = SNMP_MALLOC_TYPEDEF(netsnmp_table_registration_info);
    netsnmp_table_helper_add_indexes(table_info, ASN_INTEGER,   /* index: cltTemplateIndex */
                                     ASN_INTEGER,       /* index: cltTemplateIfIndex */
                                     0);
    table_info->min_column = COLUMN_CLTTEMPLATEIFTEMPLATEID;
    table_info->max_column = COLUMN_CLTTEMPLATEIFADMINSTATUS;

    iinfo = SNMP_MALLOC_TYPEDEF(netsnmp_iterator_info);
    iinfo->get_first_data_point =
        cltTemplateInterfaceTable_get_first_data_point;
    iinfo->get_next_data_point =
        cltTemplateInterfaceTable_get_next_data_point;
    iinfo->table_reginfo = table_info;

    netsnmp_register_table_iterator(reg, iinfo);

    netsnmp_inject_handler( reg,
		    netsnmp_get_cache_handler(HC_CACHE_TIMEOUT,
			   		cltTemplateInterfaceTable_load, cltTemplateInterfaceTable_free,
					cltTemplateInterfaceTable_oid, OID_LENGTH(cltTemplateInterfaceTable_oid)));
    DEBUGMSGTL((DBGID,
                "initialize cltTemplateInterfaceTable\n"));

    /*
     * Initialise the contents of the table here 
     */
}

    /*
     * Typical data structure for a row entry 
     */
struct cltTemplateInterfaceTable_entry {
    /*
     * Index values 
     */
    long            cltTemplateIndex;
    long            cltTemplateIfIndex;

    /*
     * Column values 
     */
    long            cltTemplateIfTemplateID;
//    long            cltTemplateIfIndex;
    char            cltTemplateIfName[HC_IFNAME_SIZE];
    size_t          cltTemplateIfName_len;
    long            cltTemplateIfType;
    long            cltTemplateIfVLANMode;
    long            old_cltTemplateIfVLANMode;
    long            cltTemplateIfPVID;
    long            old_cltTemplateIfPVID;
    long            cltTemplateIfSpeed;
    long            old_cltTemplateIfSpeed;
    long            cltTemplateIfDuplex;
    long            old_cltTemplateIfDuplex;
    long            cltTemplateIfPriority;
    long            old_cltTemplateIfPriority;
    long            cltTemplateIfFlowControl;
    long            old_cltTemplateIfFlowControl;
    long            cltTemplateIfIngressRateLimitation;
    long            old_cltTemplateIfIngressRateLimitation;
    long            cltTemplateIfEgressRateLimitation;
    long            old_cltTemplateIfEgressRateLimitation;
    long            cltTemplateIfAdminStatus;
    long            old_cltTemplateIfAdminStatus;

    /*
     * Illustrate using a simple linked list 
     */
    int             valid;
    struct cltTemplateInterfaceTable_entry *next;
};

struct cltTemplateInterfaceTable_entry *cltTemplateInterfaceTable_head;
struct cltTemplateInterfaceTable_entry *cltTemplateInterfaceTable_commit_head = NULL;


/*
 * create a new row in the (unsorted) table 
 */
struct cltTemplateInterfaceTable_entry *
cltTemplateInterfaceTable_createEntry(long cltTemplateIndex,
                                      long cltTemplateIfIndex,
                                      struct cltTemplateInterfaceTable_entry *cltTemplateInterfaceTable)
{
    struct cltTemplateInterfaceTable_entry *entry;

    entry = SNMP_MALLOC_TYPEDEF(struct cltTemplateInterfaceTable_entry);
    if (!entry)
        return NULL;

	memcpy(entry, cltTemplateInterfaceTable, sizeof(*entry));
	
    entry->cltTemplateIndex = cltTemplateIndex;
	entry->cltTemplateIfTemplateID = cltTemplateIndex;
	
    entry->cltTemplateIfIndex = cltTemplateIfIndex;
    entry->next = cltTemplateInterfaceTable_head;
    cltTemplateInterfaceTable_head = entry;
    return entry;
}

/*
 * remove a row from the table 
 */
void
cltTemplateInterfaceTable_removeEntry(struct
                                      cltTemplateInterfaceTable_entry
                                      *entry)
{
    struct cltTemplateInterfaceTable_entry *ptr, *prev;

    if (!entry)
        return;                 /* Nothing to remove */

    for (ptr = cltTemplateInterfaceTable_head, prev = NULL;
         ptr != NULL; prev = ptr, ptr = ptr->next) {
        if (ptr == entry)
            break;
    }
    if (!ptr)
        return;                 /* Can't find it */

    if (prev == NULL)
        cltTemplateInterfaceTable_head = ptr->next;
    else
        prev->next = ptr->next;

    SNMP_FREE(entry);           /* XXX - release any other internal resources */
}


struct cltTemplateInterfaceTable_entry *
cltTemplateInterfaceTable_getEntry(long cltTemplateIndex)
{
	struct cltTemplateInterfaceTable_entry *ptr;
	
    for (ptr = cltTemplateInterfaceTable_head;ptr != NULL; ptr = ptr->next) {
		if (ptr->cltTemplateIndex == cltTemplateIndex){
			return ptr;
		}
    }	
	return NULL;
}


void cltTemplateInterfaceTable_setEntry(
				struct cltTemplateInterfaceTable_entry *entry, 
				ipc_cnu_eth_port_cfg_t *port, int pid_b0)
{
	static char *ifname[] = {"Cable", "Ethernet 0", "Ethernet 1", "Ethernet 2", "Ethernet 3"};
	safe_strncpy(entry->cltTemplateIfName, ifname[pid_b0], sizeof(entry->cltTemplateIfName));
	entry->cltTemplateIfName_len = strlen(entry->cltTemplateIfName);
	entry->cltTemplateIfType = (pid_b0 == 0) ? IFType_cable : IFType_ethernet;
	entry->cltTemplateIfVLANMode = port->tagged ? VLANTAG_tagged : VLANTAG_untagged;
	entry->cltTemplateIfPVID = port->pvid;
	if (port->autoneg){
		entry->cltTemplateIfSpeed = IFSpeed_auto;
		entry->cltTemplateIfDuplex = IFDuplex_auto;
	}else {
		entry->cltTemplateIfSpeed = port->speed;
		entry->cltTemplateIfDuplex = port->duplex;
	}
	entry->cltTemplateIfPriority = port->priority;
	entry->cltTemplateIfFlowControl = port->flowctrl;
	entry->cltTemplateIfIngressRateLimitation = port->ingress_rate_limit;
	entry->cltTemplateIfEgressRateLimitation = port->egress_rate_limit;
	entry->cltTemplateIfAdminStatus = port->disabled ? IFAdmin_off : IFAdmin_on;
}


void cltTemplateInterfaceTable_removeAllEntry(void )
{
    struct cltTemplateInterfaceTable_entry *ptr, *pnext;

    for (ptr = cltTemplateInterfaceTable_head; ptr != NULL; ptr = pnext) {
		 pnext = ptr->next;
		 SNMP_FREE(ptr); 
    }
	cltTemplateInterfaceTable_head = NULL;
}


struct cltTemplateInterfaceTable_entry *
cltTemplateInterfaceTable_backupCommitEntry(
				struct cltTemplateInterfaceTable_entry *cltTemplateInterfaceTable)
{
    struct cltTemplateInterfaceTable_entry *entry, *next;

    for (entry = cltTemplateInterfaceTable_commit_head; entry != NULL; entry = entry->next) {
		if (entry->cltTemplateIndex == cltTemplateInterfaceTable->cltTemplateIndex){
			break;
		}		
    }	

	if (!entry){
		entry = SNMP_MALLOC_TYPEDEF(struct cltTemplateInterfaceTable_entry);
		if (!entry)
			return NULL;
		entry->next = cltTemplateInterfaceTable_commit_head;
		cltTemplateInterfaceTable_commit_head = entry;
	}

	
	next = entry->next;
	memcpy(entry, cltTemplateInterfaceTable, sizeof(*entry));
	entry->next = next;
	
    return entry;	
}


void cltTemplateInterfaceTable_removeAllCommitEntry(void )
{
    struct cltTemplateInterfaceTable_entry *ptr, *pnext;

    for (ptr = cltTemplateInterfaceTable_commit_head; ptr != NULL; ptr = pnext) {
		 pnext = ptr->next;
		 SNMP_FREE(ptr); 
    }
	cltTemplateInterfaceTable_commit_head = NULL;
}


/*
 * Example iterator hook routines - using 'get_next' to do most of the work 
 */
netsnmp_variable_list *
cltTemplateInterfaceTable_get_first_data_point(void **my_loop_context,
                                               void **my_data_context,
                                               netsnmp_variable_list *
                                               put_index_data,
                                               netsnmp_iterator_info
                                               *mydata)
{
    *my_loop_context = cltTemplateInterfaceTable_head;
    return cltTemplateInterfaceTable_get_next_data_point(my_loop_context,
                                                         my_data_context,
                                                         put_index_data,
                                                         mydata);
}

netsnmp_variable_list *
cltTemplateInterfaceTable_get_next_data_point(void **my_loop_context,
                                              void **my_data_context,
                                              netsnmp_variable_list *
                                              put_index_data,
                                              netsnmp_iterator_info
                                              *mydata)
{
    struct cltTemplateInterfaceTable_entry *entry =
        (struct cltTemplateInterfaceTable_entry *) *my_loop_context;
    netsnmp_variable_list *idx = put_index_data;

    if (entry) {
        snmp_set_var_typed_integer(idx, ASN_INTEGER,
                                   entry->cltTemplateIndex);
        idx = idx->next_variable;
        snmp_set_var_typed_integer(idx, ASN_INTEGER,
                                   entry->cltTemplateIfIndex);
        idx = idx->next_variable;
        *my_data_context = (void *) entry;
        *my_loop_context = (void *) entry->next;
        return put_index_data;
    } else {
        return NULL;
    }
}


/** handles requests for the cltTemplateInterfaceTable table */
int
cltTemplateInterfaceTable_handler(netsnmp_mib_handler *handler,
                                  netsnmp_handler_registration *reginfo,
                                  netsnmp_agent_request_info *reqinfo,
                                  netsnmp_request_info *requests)
{
	int ret;
    netsnmp_request_info *request;
    netsnmp_table_request_info *table_info;
    struct cltTemplateInterfaceTable_entry *table_entry;
	netsnmp_variable_list *requestvb;	

    if (((reqinfo->mode == MODE_GET) || (reqinfo->mode == MODE_SET_ACTION)) 
		&& !netsnmp_cache_is_valid(reqinfo, reginfo->handlerName)) {
        netsnmp_assert(!"cache == valid"); /* always false */
        cltTemplateInterfaceTable_load( NULL, NULL );	/* XXX - check for failure */
    }

    DEBUGMSGTL((DBGID, "Handler - mode %s\n",
                    se_find_label_in_slist("agent_mode", reqinfo->mode)));


    switch (reqinfo->mode) {
        /*
         * Read-support (also covers GetNext requests)
         */
    case MODE_GET:
        for (request = requests; request; request = request->next) {
            table_entry = (struct cltTemplateInterfaceTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);
			requestvb = request->requestvb;
			HC_DBG_OID(requestvb);	

            switch (table_info->colnum) {
            case COLUMN_CLTTEMPLATEIFTEMPLATEID:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltTemplateIfTemplateID);
                break;
            case COLUMN_CLTTEMPLATEIFINDEX:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltTemplateIfIndex);
                break;
            case COLUMN_CLTTEMPLATEIFNAME:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_value(request->requestvb, ASN_OCTET_STR,
                                         (u_char *) table_entry->
                                         cltTemplateIfName,
                                         table_entry->
                                         cltTemplateIfName_len);
                break;
            case COLUMN_CLTTEMPLATEIFTYPE:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->cltTemplateIfType);
                break;
            case COLUMN_CLTTEMPLATEIFVLANMODE:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltTemplateIfVLANMode);
                break;
            case COLUMN_CLTTEMPLATEIFPVID:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->cltTemplateIfPVID);
                break;
            case COLUMN_CLTTEMPLATEIFSPEED:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltTemplateIfSpeed);
                break;
            case COLUMN_CLTTEMPLATEIFDUPLEX:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltTemplateIfDuplex);
                break;
            case COLUMN_CLTTEMPLATEIFPRIORITY:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltTemplateIfPriority);
                break;
            case COLUMN_CLTTEMPLATEIFFLOWCONTROL:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltTemplateIfFlowControl);
                break;
            case COLUMN_CLTTEMPLATEIFINGRESSRATELIMITATION:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltTemplateIfIngressRateLimitation);
                break;
            case COLUMN_CLTTEMPLATEIFEGRESSRATELIMITATION:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltTemplateIfEgressRateLimitation);
                break;
            case COLUMN_CLTTEMPLATEIFADMINSTATUS:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltTemplateIfAdminStatus);
                break;
            default:
                netsnmp_set_request_error(reqinfo, request,
                                          SNMP_NOSUCHOBJECT);
                break;
            }
        }
        break;

        /*
         * Write-support
         */
    case MODE_SET_RESERVE1:
        for (request = requests; request; request = request->next) {
            table_entry = (struct cltTemplateInterfaceTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);
			requestvb = request->requestvb;
			HC_DBG_OID(requestvb);	

            switch (table_info->colnum) {
            case COLUMN_CLTTEMPLATEIFVLANMODE:
                /*
                 * or possibly 'netsnmp_check_vb_int_range' 
                 */
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            case COLUMN_CLTTEMPLATEIFPVID:
                /*
                 * or possibly 'netsnmp_check_vb_int_range' 
                 */
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            case COLUMN_CLTTEMPLATEIFSPEED:
                /*
                 * or possibly 'netsnmp_check_vb_int_range' 
                 */
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            case COLUMN_CLTTEMPLATEIFDUPLEX:
                /*
                 * or possibly 'netsnmp_check_vb_int_range' 
                 */
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            case COLUMN_CLTTEMPLATEIFPRIORITY:
                /*
                 * or possibly 'netsnmp_check_vb_int_range' 
                 */
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            case COLUMN_CLTTEMPLATEIFFLOWCONTROL:
                /*
                 * or possibly 'netsnmp_check_vb_int_range' 
                 */
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            case COLUMN_CLTTEMPLATEIFINGRESSRATELIMITATION:
                /*
                 * or possibly 'netsnmp_check_vb_int_range' 
                 */
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            case COLUMN_CLTTEMPLATEIFEGRESSRATELIMITATION:
                /*
                 * or possibly 'netsnmp_check_vb_int_range' 
                 */
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            case COLUMN_CLTTEMPLATEIFADMINSTATUS:
                /*
                 * or possibly 'netsnmp_check_vb_int_range' 
                 */
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            default:
                netsnmp_set_request_error(reqinfo, request,
                                          SNMP_ERR_NOTWRITABLE);
                return SNMP_ERR_NOERROR;
            }
        }
        break;

    case MODE_SET_RESERVE2:
        break;

    case MODE_SET_FREE:
        break;

    case MODE_SET_ACTION:
        for (request = requests; request; request = request->next) {
            table_entry = (struct cltTemplateInterfaceTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);
			requestvb = request->requestvb;
			HC_DBG_OID(requestvb);	

            switch (table_info->colnum) {
            case COLUMN_CLTTEMPLATEIFVLANMODE:
                table_entry->old_cltTemplateIfVLANMode =
                    table_entry->cltTemplateIfVLANMode;
                table_entry->cltTemplateIfVLANMode =
                    *request->requestvb->val.integer;
                break;
            case COLUMN_CLTTEMPLATEIFPVID:
                table_entry->old_cltTemplateIfPVID =
                    table_entry->cltTemplateIfPVID;
                table_entry->cltTemplateIfPVID =
                    *request->requestvb->val.integer;
                break;
            case COLUMN_CLTTEMPLATEIFSPEED:
                table_entry->old_cltTemplateIfSpeed =
                    table_entry->cltTemplateIfSpeed;
                table_entry->cltTemplateIfSpeed =
                    *request->requestvb->val.integer;
                break;
            case COLUMN_CLTTEMPLATEIFDUPLEX:
                table_entry->old_cltTemplateIfDuplex =
                    table_entry->cltTemplateIfDuplex;
                table_entry->cltTemplateIfDuplex =
                    *request->requestvb->val.integer;
                break;
            case COLUMN_CLTTEMPLATEIFPRIORITY:
                table_entry->old_cltTemplateIfPriority =
                    table_entry->cltTemplateIfPriority;
                table_entry->cltTemplateIfPriority =
                    *request->requestvb->val.integer;
                break;
            case COLUMN_CLTTEMPLATEIFFLOWCONTROL:
                table_entry->old_cltTemplateIfFlowControl =
                    table_entry->cltTemplateIfFlowControl;
                table_entry->cltTemplateIfFlowControl =
                    *request->requestvb->val.integer;
                break;
            case COLUMN_CLTTEMPLATEIFINGRESSRATELIMITATION:
                table_entry->old_cltTemplateIfIngressRateLimitation =
                    table_entry->cltTemplateIfIngressRateLimitation;
                table_entry->cltTemplateIfIngressRateLimitation =
                    *request->requestvb->val.integer;
                break;
            case COLUMN_CLTTEMPLATEIFEGRESSRATELIMITATION:
                table_entry->old_cltTemplateIfEgressRateLimitation =
                    table_entry->cltTemplateIfEgressRateLimitation;
                table_entry->cltTemplateIfEgressRateLimitation =
                    *request->requestvb->val.integer;
                break;
            case COLUMN_CLTTEMPLATEIFADMINSTATUS:
                table_entry->old_cltTemplateIfAdminStatus =
                    table_entry->cltTemplateIfAdminStatus;
                table_entry->cltTemplateIfAdminStatus =
                    *request->requestvb->val.integer;
                break;
            }
			cltTemplateInterfaceTable_backupCommitEntry(table_entry);			
        }
        break;

    case MODE_SET_UNDO:
        for (request = requests; request; request = request->next) {
            table_entry = (struct cltTemplateInterfaceTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);
			requestvb = request->requestvb;
			HC_DBG_OID(requestvb);	

            switch (table_info->colnum) {
            case COLUMN_CLTTEMPLATEIFVLANMODE:
                table_entry->cltTemplateIfVLANMode =
                    table_entry->old_cltTemplateIfVLANMode;
                table_entry->old_cltTemplateIfVLANMode = 0;
                break;
            case COLUMN_CLTTEMPLATEIFPVID:
                table_entry->cltTemplateIfPVID =
                    table_entry->old_cltTemplateIfPVID;
                table_entry->old_cltTemplateIfPVID = 0;
                break;
            case COLUMN_CLTTEMPLATEIFSPEED:
                table_entry->cltTemplateIfSpeed =
                    table_entry->old_cltTemplateIfSpeed;
                table_entry->old_cltTemplateIfSpeed = 0;
                break;
            case COLUMN_CLTTEMPLATEIFDUPLEX:
                table_entry->cltTemplateIfDuplex =
                    table_entry->old_cltTemplateIfDuplex;
                table_entry->old_cltTemplateIfDuplex = 0;
                break;
            case COLUMN_CLTTEMPLATEIFPRIORITY:
                table_entry->cltTemplateIfPriority =
                    table_entry->old_cltTemplateIfPriority;
                table_entry->old_cltTemplateIfPriority = 0;
                break;
            case COLUMN_CLTTEMPLATEIFFLOWCONTROL:
                table_entry->cltTemplateIfFlowControl =
                    table_entry->old_cltTemplateIfFlowControl;
                table_entry->old_cltTemplateIfFlowControl = 0;
                break;
            case COLUMN_CLTTEMPLATEIFINGRESSRATELIMITATION:
                table_entry->cltTemplateIfIngressRateLimitation =
                    table_entry->old_cltTemplateIfIngressRateLimitation;
                table_entry->old_cltTemplateIfIngressRateLimitation = 0;
                break;
            case COLUMN_CLTTEMPLATEIFEGRESSRATELIMITATION:
                table_entry->cltTemplateIfEgressRateLimitation =
                    table_entry->old_cltTemplateIfEgressRateLimitation;
                table_entry->old_cltTemplateIfEgressRateLimitation = 0;
                break;
            case COLUMN_CLTTEMPLATEIFADMINSTATUS:
                table_entry->cltTemplateIfAdminStatus =
                    table_entry->old_cltTemplateIfAdminStatus;
                table_entry->old_cltTemplateIfAdminStatus = 0;
                break;
            }
        }
        break;

    case MODE_SET_COMMIT:
		local_commit();
        break;
    }
    return SNMP_ERR_NOERROR;
}

int cltTemplateInterfaceTable_load(netsnmp_cache *cache, void *vmagic)
{

   long 		   ret = -1, i, p;
   struct cltTemplateInterfaceTable_entry entry;   
   
   ret = device_templates_update();
   if (HC_IPC_ERROR(ret)) {
	   CLR_VALID();
	   DEBUGMSGTL((DBGID, "Failed to update cltTemplateInterfaceTable Group\n"));
   } else {
	   SET_VALID();
	   DEBUGMSGTL((DBGID, "Updated cltTemplateInterfaceTable Group\n"));
   }
   
   HC_IPC_ASSERT(ret);    
   
   for (i = 0; i < device_templates_num; i ++){
   	   for (p = 0; p < device_templates[i].lsw_cfg.ports; p ++){
		   cltTemplateInterfaceTable_setEntry(&entry, 
		   	(p == 0) ? &device_templates[i].lsw_cfg.cab_port : &device_templates[i].lsw_cfg.eth_ports[p - 1], p);
		   cltTemplateInterfaceTable_createEntry(i + 1, p + 1, &entry);
	   }
   }
   
   return ret; 
} 

void cltTemplateInterfaceTable_free(netsnmp_cache *cache, void *magic)
{
	DEBUGMSGTL((DBGID, "Free cltTemplateInterfaceTable Group\n"));  
	
	cltTemplateInterfaceTable_removeAllEntry();
}

ipc_service_template_t *cltTemplateInterfaceTable_change_and_update(struct cltTemplateInterfaceTable_entry *entry)
{
	static ipc_service_template_t tmpl_c, *tmpl;
	ipc_cnu_eth_port_cfg_t *port;
	int tmpl_id = entry->cltTemplateIndex - 1;
	int if_id = entry->cltTemplateIfIndex - 1;
	int i;

	tmpl = &tmpl_c;

	//memset(tmpl, 0, sizeof(*tmpl));

	DBG_ASSERT((tmpl_id < device_templates_num), "Invalid tmplate ID");
	DBG_ASSERT((if_id == 0), "Invalid tmplate ID");
	
	if (tmpl_id < device_templates_num){
		memcpy(tmpl, &device_templates[tmpl_id], sizeof(*tmpl));
	}else {
		snmp_log(LOG_ERR, "tmpl_id >= device_templates_num\n");
		return NULL;
	}

	// neglect cable port
	if_id ++;
	entry = entry->next;
	for ( i = 0; i < tmpl->lsw_cfg.ports - 1; i ++){
		port = &tmpl->lsw_cfg.eth_ports[i];
		if ((entry->cltTemplateIfDuplex == IFDuplex_auto) || (entry->cltTemplateIfSpeed == IFSpeed_auto)){
			port->autoneg = 1;
		}else {
			if (entry->cltTemplateIfSpeed == IFSpeed_10m){
				port->speed = ETH_SPEED_10;
			}else {
				port->speed = ETH_SPEED_100;
			}
			if (entry->cltTemplateIfDuplex == IFDuplex_half){
				port->duplex = ETH_DUPLEX_HALF;
			}else {
				port->duplex = ETH_DUPLEX_FULL;
			}			
		}
		port->disabled = entry->cltTemplateIfAdminStatus == IFAdmin_on ? 0 : 1;
		port->flowctrl = entry->cltTemplateIfFlowControl;
		port->priority = entry->cltTemplateIfPriority;
		port->egress_rate_limit = entry->cltTemplateIfEgressRateLimitation;
		port->ingress_rate_limit = entry->cltTemplateIfIngressRateLimitation;
		port->pvid = entry->cltTemplateIfPVID;
		port->tagged = entry->cltTemplateIfVLANMode == VLANTAG_tagged ? 1 : 0;
		
	}

	if (!memcmp(tmpl, &device_templates[tmpl_id], sizeof(*tmpl))){
		// no change
		return NULL;
	}
	return tmpl;
}


void cltTemplateInterfaceTable_commit(unsigned int regNo, void *clientargs)
{
	
	/*
		We will handle row status first
		check every row status change.
		if any row status is destory, apply them and forget others changes
		else if any row status is to creat, and creat one for all and forget others
		else if any created row is to active , active the new one and forget others
		else if not row status change, apply row values change
	*/
	long ret;
	struct cltTemplateInterfaceTable_entry *ptr;
	ipc_service_template_t templates[EOC_MAX_TMPL_NUMS], *tmpl;
	int do_num = 0;
	
	HC_VALID_ASSERT();
	// apply all changes

#if 0
	ret = device_templates_update();
	if (HC_IPC_ERROR(ret)) {
		CLR_VALID();
		DEBUGMSGTL((DBGID, "Failed to update cltTemplateInterfaceTable Group\n"));
	} else {
		SET_VALID();
		DEBUGMSGTL((DBGID, "Updated cltTemplateInterfaceTable Group\n"));
	}
	
	HC_IPC_ASSERT1(ret);	
#endif 	

	for (ptr = cltTemplateInterfaceTable_commit_head; ptr != NULL; ptr = ptr->next) {
		if (ptr->cltTemplateIfIndex != 1){
			continue;
		}
		tmpl = cltTemplateInterfaceTable_change_and_update(ptr);
		if (tmpl){
			memcpy(&templates[do_num], tmpl, sizeof(*tmpl));
			do_num ++;
		}
	}

	cltTemplateInterfaceTable_removeAllCommitEntry();

	if (do_num){
		ret = ipc_set_template(templates, do_num);
		if (HC_IPC_ERROR(ret)) {
			DEBUGMSGTL((DBGID, "Failed to commit cltTemplateInterfaceTable Group\n"));
		} else {
			DEBUGMSGTL((DBGID, "Commited cltTemplateInterfaceTable Group\n"));
		}		
		HC_IPC_ASSERT1(ret);
	} 

}


