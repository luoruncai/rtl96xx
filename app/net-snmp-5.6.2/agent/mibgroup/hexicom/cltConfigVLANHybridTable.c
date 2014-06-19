/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 15999 2007-03-25 22:32:02Z dts12 $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "cltConfigVLANHybridTable.h"


#include "hexicomTC.h"

#undef DBGID
#define DBGID  "hc:clthybridtable"

#ifndef DBGID
#define DBGID "defalut"
#endif 


LOCAL_COMMIT_DECLARE();

#define local_commit()  LOCAL_COMMIT(500, cltConfigVLANHybridTable_commit, NULL)



/** Initializes the cltConfigVLANHybridTable module */
void
init_cltConfigVLANHybridTable(void)
{
    /*
     * here we initialize all the tables we're planning on supporting 
     */
    initialize_table_cltConfigVLANHybridTable();
}

//# Determine the first/last column names

/** Initialize the cltConfigVLANHybridTable table by defining its contents and how it's structured */
void
initialize_table_cltConfigVLANHybridTable(void)
{
    static oid      cltConfigVLANHybridTable_oid[] =
        { 1, 3, 6, 1, 4, 1, 36368, 1, 1, 1, 1, 2, 3, 6 };
    size_t          cltConfigVLANHybridTable_oid_len =
        OID_LENGTH(cltConfigVLANHybridTable_oid);
    netsnmp_handler_registration *reg;
    netsnmp_iterator_info *iinfo;
    netsnmp_table_registration_info *table_info;

	DEBUGMSGTL((DBGID, "Initializing\n"));

    reg =
        netsnmp_create_handler_registration("cltConfigVLANHybridTable",
                                            cltConfigVLANHybridTable_handler,
                                            cltConfigVLANHybridTable_oid,
                                            cltConfigVLANHybridTable_oid_len,
                                            HANDLER_CAN_RWRITE);

    table_info = SNMP_MALLOC_TYPEDEF(netsnmp_table_registration_info);
    netsnmp_table_helper_add_indexes(table_info, ASN_INTEGER,   /* index: cltConfigVLANHybridIndex */
                                     0);
    table_info->min_column = COLUMN_CLTCONFIGVLANHYBRIDINDEX;
    table_info->max_column = COLUMN_CLTCONFIGVLANHYBRIDROWSTATUS;

    iinfo = SNMP_MALLOC_TYPEDEF(netsnmp_iterator_info);
    iinfo->get_first_data_point =
        cltConfigVLANHybridTable_get_first_data_point;
    iinfo->get_next_data_point =
        cltConfigVLANHybridTable_get_next_data_point;
    iinfo->table_reginfo = table_info;

    netsnmp_register_table_iterator(reg, iinfo);


    netsnmp_inject_handler( reg,
		    netsnmp_get_cache_handler(HC_CACHE_TIMEOUT,
			   		cltConfigVLANHybridTable_load, cltConfigVLANHybridTable_free,
					cltConfigVLANHybridTable_oid, OID_LENGTH(cltConfigVLANHybridTable_oid)));
    DEBUGMSGTL((DBGID,
                "initialize cltConfigVLANHybridTable\n"));    

    /*
     * Initialise the contents of the table here 
     */
}

    /*
     * Typical data structure for a row entry 
     */
struct cltConfigVLANHybridTable_entry {
    /*
     * Index values 
     */
    long            cltConfigVLANHybridIndex;

    /*
     * Column values 
     */
//    long            cltConfigVLANHybridIndex;
    long            cltConfigVLANHybridPortID;
    char            cltConfigVLANHybridPortName[HC_IFNAME_SIZE];
    size_t          cltConfigVLANHybridPortName_len;
    long            cltConfigVLANHybridPVID;
    long            old_cltConfigVLANHybridPVID;
    char            cltConfigVLANHybridTagged[1];
    size_t          cltConfigVLANHybridTagged_len;
    char            old_cltConfigVLANHybridTagged[1];
    size_t          old_cltConfigVLANHybridTagged_len;
    char            cltConfigVLANHybridUntagged[1];
    size_t          cltConfigVLANHybridUntagged_len;
    char            old_cltConfigVLANHybridUntagged[1];
    size_t          old_cltConfigVLANHybridUntagged_len;
    long            cltConfigVLANHybridRowStatus;

    /*
     * Illustrate using a simple linked list 
     */
    int             valid;
    struct cltConfigVLANHybridTable_entry *next;
};

struct cltConfigVLANHybridTable_entry *cltConfigVLANHybridTable_head;
struct cltConfigVLANHybridTable_entry *cltConfigVLANHybridTable_commit_head;

/*
 * create a new row in the (unsorted) table 
 */
struct cltConfigVLANHybridTable_entry *
cltConfigVLANHybridTable_createEntry(long cltConfigVLANHybridIndex,
		struct cltConfigVLANHybridTable_entry *cltConfigVLANHybridTable)
{
    struct cltConfigVLANHybridTable_entry *entry;

    entry = SNMP_MALLOC_TYPEDEF(struct cltConfigVLANHybridTable_entry);
    if (!entry)
        return NULL;

	memcpy(entry, cltConfigVLANHybridTable, sizeof(*entry));

    entry->cltConfigVLANHybridIndex = cltConfigVLANHybridIndex;
    entry->next = cltConfigVLANHybridTable_head;
    cltConfigVLANHybridTable_head = entry;
    return entry;
}

/*
 * remove a row from the table 
 */
void
cltConfigVLANHybridTable_removeEntry(struct cltConfigVLANHybridTable_entry
                                     *entry)
{
    struct cltConfigVLANHybridTable_entry *ptr, *prev;

    if (!entry)
        return;                 /* Nothing to remove */

    for (ptr = cltConfigVLANHybridTable_head, prev = NULL;
         ptr != NULL; prev = ptr, ptr = ptr->next) {
        if (ptr == entry)
            break;
    }
    if (!ptr)
        return;                 /* Can't find it */

    if (prev == NULL)
        cltConfigVLANHybridTable_head = ptr->next;
    else
        prev->next = ptr->next;

    SNMP_FREE(entry);           /* XXX - release any other internal resources */
}


void cltConfigVLANHybridTable_removeAllEntry(void )
{
    struct cltConfigVLANHybridTable_entry *ptr, *pnext;

    for (ptr = cltConfigVLANHybridTable_head; ptr != NULL; ptr = pnext) {
		 pnext = ptr->next;
		 SNMP_FREE(ptr); 
    }
	cltConfigVLANHybridTable_head = NULL;
}


void cltConfigVLANHybridTable_setEntry(
				struct cltConfigVLANHybridTable_entry *entry, 
				int portid,
				char* portname,
				int pvid,
				int inservice
				)
{
	entry->cltConfigVLANHybridPortID = portid;
	safe_strncpy(entry->cltConfigVLANHybridPortName, portname, sizeof(entry->cltConfigVLANHybridPortName));
	entry->cltConfigVLANHybridPortName_len = strlen(entry->cltConfigVLANHybridPortName);
	entry->cltConfigVLANHybridPVID = pvid; 
	entry->cltConfigVLANHybridRowStatus = inservice ? RowStatus_active : RowStatus_notInService;
	entry->cltConfigVLANHybridTagged[0] = 0;
	entry->cltConfigVLANHybridTagged_len = 0;
	entry->cltConfigVLANHybridUntagged[0] = 0;
	entry->cltConfigVLANHybridUntagged_len = 0;	
}


struct cltConfigVLANHybridTable_entry *
cltConfigVLANHybridTable_backupCommitEntry(
				struct cltConfigVLANHybridTable_entry *cltConfigVLANHybridTable)
{
    struct cltConfigVLANHybridTable_entry *entry, *next;

    for (entry = cltConfigVLANHybridTable_commit_head; entry != NULL; entry = entry->next) {
		if (entry->cltConfigVLANHybridIndex == cltConfigVLANHybridTable->cltConfigVLANHybridIndex){
			break;
		}		
    }	

	if (!entry){
		entry = SNMP_MALLOC_TYPEDEF(struct cltConfigVLANHybridTable_entry);
		if (!entry)
			return NULL;
		entry->next = cltConfigVLANHybridTable_commit_head;
		cltConfigVLANHybridTable_commit_head = entry;
	}

	
	next = entry->next;
	memcpy(entry, cltConfigVLANHybridTable, sizeof(*entry));
	entry->next = next;
	
    return entry;	
}


void cltConfigVLANHybridTable_removeAllCommitEntry(void )
{
    struct cltConfigVLANHybridTable_entry *ptr, *pnext;

    for (ptr = cltConfigVLANHybridTable_commit_head; ptr != NULL; ptr = pnext) {
		 pnext = ptr->next;
		 SNMP_FREE(ptr); 
    }
	cltConfigVLANHybridTable_commit_head = NULL;
}



/*
 * Example iterator hook routines - using 'get_next' to do most of the work 
 */
netsnmp_variable_list *
cltConfigVLANHybridTable_get_first_data_point(void **my_loop_context,
                                              void **my_data_context,
                                              netsnmp_variable_list *
                                              put_index_data,
                                              netsnmp_iterator_info
                                              *mydata)
{
    *my_loop_context = cltConfigVLANHybridTable_head;
    return cltConfigVLANHybridTable_get_next_data_point(my_loop_context,
                                                        my_data_context,
                                                        put_index_data,
                                                        mydata);
}

netsnmp_variable_list *
cltConfigVLANHybridTable_get_next_data_point(void **my_loop_context,
                                             void **my_data_context,
                                             netsnmp_variable_list *
                                             put_index_data,
                                             netsnmp_iterator_info *mydata)
{
    struct cltConfigVLANHybridTable_entry *entry =
        (struct cltConfigVLANHybridTable_entry *) *my_loop_context;
    netsnmp_variable_list *idx = put_index_data;

    if (entry) {
        snmp_set_var_typed_integer(idx, ASN_INTEGER,
                                   entry->cltConfigVLANHybridIndex);
        idx = idx->next_variable;
        *my_data_context = (void *) entry;
        *my_loop_context = (void *) entry->next;
        return put_index_data;
    } else {
        return NULL;
    }
}


/** handles requests for the cltConfigVLANHybridTable table */
int
cltConfigVLANHybridTable_handler(netsnmp_mib_handler *handler,
                                 netsnmp_handler_registration *reginfo,
                                 netsnmp_agent_request_info *reqinfo,
                                 netsnmp_request_info *requests)
{
	int ret;
    netsnmp_request_info *request;
    netsnmp_table_request_info *table_info;
    struct cltConfigVLANHybridTable_entry *table_entry;
	netsnmp_variable_list *requestvb;	

    if (((reqinfo->mode == MODE_GET) || (reqinfo->mode == MODE_SET_ACTION)) 
		&& !netsnmp_cache_is_valid(reqinfo, reginfo->handlerName)) {
        netsnmp_assert(!"cache == valid"); /* always false */
        cltConfigVLANHybridTable_load( NULL, NULL );	/* XXX - check for failure */
    }

    DEBUGMSGTL((DBGID, "Handler - mode %s\n",
                    se_find_label_in_slist("agent_mode", reqinfo->mode)));

    switch (reqinfo->mode) {
        /*
         * Read-support (also covers GetNext requests)
         */
    case MODE_GET:
        for (request = requests; request; request = request->next) {
            table_entry = (struct cltConfigVLANHybridTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);
			requestvb = request->requestvb;
			HC_DBG_OID(requestvb);				

            switch (table_info->colnum) {
            case COLUMN_CLTCONFIGVLANHYBRIDINDEX:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltConfigVLANHybridIndex);
                break;
            case COLUMN_CLTCONFIGVLANHYBRIDPORTID:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltConfigVLANHybridPortID);
                break;
            case COLUMN_CLTCONFIGVLANHYBRIDPORTNAME:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_value(request->requestvb, ASN_OCTET_STR,
                                         (u_char *) table_entry->
                                         cltConfigVLANHybridPortName,
                                         table_entry->
                                         cltConfigVLANHybridPortName_len);
                break;
            case COLUMN_CLTCONFIGVLANHYBRIDPVID:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltConfigVLANHybridPVID);
                break;
            case COLUMN_CLTCONFIGVLANHYBRIDTAGGED:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_value(request->requestvb, ASN_OCTET_STR,
                                         (u_char *) table_entry->
                                         cltConfigVLANHybridTagged,
                                         table_entry->
                                         cltConfigVLANHybridTagged_len);
                break;
            case COLUMN_CLTCONFIGVLANHYBRIDUNTAGGED:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_value(request->requestvb, ASN_OCTET_STR,
                                         (u_char *) table_entry->
                                         cltConfigVLANHybridUntagged,
                                         table_entry->
                                         cltConfigVLANHybridUntagged_len);
                break;
            case COLUMN_CLTCONFIGVLANHYBRIDROWSTATUS:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->
                                           cltConfigVLANHybridRowStatus);
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
            table_entry = (struct cltConfigVLANHybridTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);

			requestvb = request->requestvb;
			HC_DBG_OID(requestvb);	

            switch (table_info->colnum) {
            case COLUMN_CLTCONFIGVLANHYBRIDPVID:
                /*
                 * or possibly 'netsnmp_check_vb_int_range' 
                 */
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
				if (vlan_in_transparent_mode() ||!vlan_exist(vb_int(request->requestvb), NULL)){
                    netsnmp_set_request_error(reqinfo, request, SNMP_ERR_WRONGVALUE);
                    return SNMP_ERR_NOERROR;						
				}
								
                break;
            case COLUMN_CLTCONFIGVLANHYBRIDTAGGED:
                /*
                 * or possiblc 'netsnmp_check_vb_type_and_size' 
                 *//*
                ret =
                    netsnmp_check_vb_type_and_max_size(request->requestvb,
                                                       ASN_OCTET_STR,
                                                       sizeof(table_entry->
                                                              cltConfigVLANHybridTagged));*/
               // if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, SNMP_ERR_WRONGVALUE);
                    return SNMP_ERR_NOERROR;
                //}
                break;
            case COLUMN_CLTCONFIGVLANHYBRIDUNTAGGED:
                /*
                 * or possiblc 'netsnmp_check_vb_type_and_size' 
                 *//*
                ret =
                    netsnmp_check_vb_type_and_max_size(request->requestvb,
                                                       ASN_OCTET_STR,
                                                       sizeof(table_entry->
                                                              cltConfigVLANHybridUntagged));*/
//                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, SNMP_ERR_WRONGVALUE);
                    return SNMP_ERR_NOERROR;
  //              }
                break;
            case COLUMN_CLTCONFIGVLANHYBRIDROWSTATUS:
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
				if (vlan_in_transparent_mode()
					|| !validRowStatus(vb_int(request->requestvb)) 
					|| (vb_int(request->requestvb) != RowStatus_active) 
					|| (vb_int(request->requestvb) != RowStatus_notInService)){
                    netsnmp_set_request_error(reqinfo, request, SNMP_ERR_WRONGVALUE);
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
            table_entry = (struct cltConfigVLANHybridTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);
			requestvb = request->requestvb;
			HC_DBG_OID(requestvb);	
			

            switch (table_info->colnum) {
            case COLUMN_CLTCONFIGVLANHYBRIDPVID:
                table_entry->old_cltConfigVLANHybridPVID =
                    table_entry->cltConfigVLANHybridPVID;
                table_entry->cltConfigVLANHybridPVID =
                    *request->requestvb->val.integer;
                break;
            case COLUMN_CLTCONFIGVLANHYBRIDTAGGED:/*
                memcpy(table_entry->old_cltConfigVLANHybridTagged,
                       table_entry->cltConfigVLANHybridTagged,
                       sizeof(table_entry->cltConfigVLANHybridTagged));
                table_entry->old_cltConfigVLANHybridTagged_len =
                    table_entry->cltConfigVLANHybridTagged_len;
                memset(table_entry->cltConfigVLANHybridTagged, 0,
                       sizeof(table_entry->cltConfigVLANHybridTagged));
                memcpy(table_entry->cltConfigVLANHybridTagged,
                       request->requestvb->val.string,
                       request->requestvb->val_len);
                table_entry->cltConfigVLANHybridTagged_len =
                    request->requestvb->val_len;*/
                break;
            case COLUMN_CLTCONFIGVLANHYBRIDUNTAGGED:/*
                memcpy(table_entry->old_cltConfigVLANHybridUntagged,
                       table_entry->cltConfigVLANHybridUntagged,
                       sizeof(table_entry->cltConfigVLANHybridUntagged));
                table_entry->old_cltConfigVLANHybridUntagged_len =
                    table_entry->cltConfigVLANHybridUntagged_len;
                memset(table_entry->cltConfigVLANHybridUntagged, 0,
                       sizeof(table_entry->cltConfigVLANHybridUntagged));
                memcpy(table_entry->cltConfigVLANHybridUntagged,
                       request->requestvb->val.string,
                       request->requestvb->val_len);
                table_entry->cltConfigVLANHybridUntagged_len =
                    request->requestvb->val_len;*/
                break;
			case COLUMN_CLTCONFIGVLANHYBRIDROWSTATUS:
                table_entry->cltConfigVLANHybridRowStatus =
                    *request->requestvb->val.integer;

				break;				
            }
        }
        /*
         * Check the internal consistency of an active row 
       
        for (request = requests; request; request = request->next) {
            table_entry = (struct cltConfigVLANHybridTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);

            switch (table_info->colnum) {
            case COLUMN_CLTCONFIGVLANHYBRIDROWSTATUS:
                switch (*request->requestvb->val.integer) {
                case RS_ACTIVE:
                case RS_CREATEANDGO:
                    if ( 0 ) {
                        netsnmp_set_request_error(reqinfo, request,
                                                  SNMP_ERR_INCONSISTENTVALUE);
                        return SNMP_ERR_NOERROR;
                    }
                }
            }
          }*/
        break;

    case MODE_SET_UNDO:
        for (request = requests; request; request = request->next) {
            table_entry = (struct cltConfigVLANHybridTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);
			requestvb = request->requestvb;
			HC_DBG_OID(requestvb);	

            switch (table_info->colnum) {
            case COLUMN_CLTCONFIGVLANHYBRIDPVID:
                table_entry->cltConfigVLANHybridPVID =
                    table_entry->old_cltConfigVLANHybridPVID;
                table_entry->old_cltConfigVLANHybridPVID = 0;
                break;
            case COLUMN_CLTCONFIGVLANHYBRIDTAGGED:
            /*    memcpy(table_entry->cltConfigVLANHybridTagged,
                       table_entry->old_cltConfigVLANHybridTagged,
                       sizeof(table_entry->cltConfigVLANHybridTagged));
                memset(table_entry->old_cltConfigVLANHybridTagged, 0,
                       sizeof(table_entry->cltConfigVLANHybridTagged));
                table_entry->cltConfigVLANHybridTagged_len =
                    table_entry->old_cltConfigVLANHybridTagged_len;*/
                break;
            case COLUMN_CLTCONFIGVLANHYBRIDUNTAGGED:/*
                memcpy(table_entry->cltConfigVLANHybridUntagged,
                       table_entry->old_cltConfigVLANHybridUntagged,
                       sizeof(table_entry->cltConfigVLANHybridUntagged));
                memset(table_entry->old_cltConfigVLANHybridUntagged, 0,
                       sizeof(table_entry->cltConfigVLANHybridUntagged));
                table_entry->cltConfigVLANHybridUntagged_len =
                    table_entry->old_cltConfigVLANHybridUntagged_len;*/
                break;
            case COLUMN_CLTCONFIGVLANHYBRIDROWSTATUS:/*
                switch (*request->requestvb->val.integer) {
                case RS_CREATEANDGO:
                case RS_CREATEANDWAIT:
                    if (table_entry && !table_entry->valid) {
                        cltConfigVLANHybridTable_removeEntry(table_data,
                                                             table_row);
                    }
                }*/
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


int cltConfigVLANHybridTable_load(netsnmp_cache *cache, void *vmagic)
{
	int ret, i;
	char *show_if[] = {VLAN_IFLIST, NULL};
	
	struct cltConfigVLANHybridTable_entry entry;
	switch_vlan_interface_t *vlanif;
	
		
	ret = vlan_interface_update();
	
    if (HC_IPC_ERROR(ret)) {
		CLR_VALID();
		DEBUGMSGTL((DBGID, "Failed to load cltConfigVLANHybridTable Group\n"));
    } else {
		SET_VALID();
        DEBUGMSGTL((DBGID, "Loaded cltConfigVLANHybridTable Group\n"));
    }

	HC_IPC_ASSERT(ret);

	if (sys_vlan_mode.mode == VLAN_MODE_8021Q){
		for (i = 0; show_if[i]; i ++){
			vlanif = dot1q_vlanif_search(show_if[i]);
			if (vlanif){
				cltConfigVLANHybridTable_setEntry(&entry, i  + 1,
						interface_fancy_name(show_if[i]), 
						vlanif->pvid, 
						(vlanif->mode == ETH_SWITCHPORT_HYBRID) ? 1 : 0);
				cltConfigVLANHybridTable_createEntry(i, &entry);
			}
		}
	}else {
		for (i = 0; show_if[i]; i ++){
			cltConfigVLANHybridTable_setEntry(&entry, i	+ 1,
					interface_fancy_name(show_if[i]), 
					1, 
					0);
			cltConfigVLANHybridTable_createEntry(i, &entry);
		}
	}

    return ret; 	
} 

void cltConfigVLANHybridTable_free(netsnmp_cache *cache, void *magic)
{
	DEBUGMSGTL((DBGID, "Free cltConfigVLANHybridTable Group\n"));  
	
	cltConfigVLANHybridTable_removeAllEntry();
}


void cltConfigVLANHybridTable_commit(unsigned int regNo, void *clientargs)
{
	int i, ifid,  ret, ifmode;
	char *show_if[] = {VLAN_IFLIST, NULL};
	struct cltConfigVLANHybridTable_entry *ptr;
	switch_vlan_interface_t *vlanif[MAX_CLT_ETH_PORTS], *vi, *v;
	int vlanif_size, vlanif_cnt;
	
	if (sys_vlan_mode.mode == VLAN_MODE_TRANSPARENT){
		cltConfigVLANHybridTable_removeAllCommitEntry();	
		return;
	}
	// 802.1q

	memset(vlanif, 0, sizeof(vlanif));
	vlanif_size = 0;
	vlanif_cnt = 0;
	for (ptr = cltConfigVLANHybridTable_commit_head; ptr != NULL; ptr = ptr->next){
		ifid = ptr->cltConfigVLANHybridIndex - 1;
		vlanif[ifid] = dot1q_vlanif_dup(show_if[ifid]);
		if (vlanif[ifid]){
			vlanif[ifid]->pvid = ptr->cltConfigVLANHybridPVID ;
			ifmode = (ptr->cltConfigVLANHybridRowStatus == RowStatus_active) ? ETH_SWITCHPORT_HYBRID : ETH_SWITCHPORT_ACCESS;
			if (ifmode != vlanif[ifid]->mode){
				vlanif[ifid]->count = 0;
			}
			vlanif_cnt ++;			
			vlanif_size += sizeof_vlan_interface(vlanif[ifid]->trunk_hybrid, vlanif[ifid]->count);
		}
	}

	cltConfigVLANHybridTable_removeAllCommitEntry();
		

	if ((vlanif_size > 0) && (vlanif_cnt > 0)){
		vi = (switch_vlan_interface_t *)malloc(vlanif_size);

		if (vi == NULL){
			for (i = 0; i < MAX_CLT_ETH_PORTS; i ++){
				if (vlanif[i]){
					free(vlanif[i]);
				}
			}
			HC_NOMEM_ASSERT1(vi);
		}
		v = vi;
		for (i = 0; i < MAX_CLT_ETH_PORTS; i ++){
			if (vlanif[i]){
				memcpy(v, vlanif[i], sizeof_vlan_interface(vlanif[i]->trunk_hybrid,vlanif[i]->count));
				v = vlan_interface_to_next(v);
			}
		}
		// free all vlanif 
		for (i = 0; i < MAX_CLT_ETH_PORTS; i ++){
			if (vlanif[i]){
				free(vlanif[i]);
			}
		}
		// commit all
		ret = ipc_set_vlan_interface(vi, vlanif_cnt);

		free(vi);

		if (HC_IPC_ERROR(ret)){
			DEBUGMSGTL((DBGID, "Failed to commit cltConfigVLANHybridTable Group\n"));
		} else {
			DEBUGMSGTL((DBGID, "Commited cltConfigVLANHybridTable Group\n"));
		}
		HC_IPC_ASSERT1(ret);
	}
}


