/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 17695 2009-07-21 12:22:18Z dts12 $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "analogPropertyTable.h"

#include "../product_common/snmp_ipc_interface.h"
#include "../product_common/snmp_ipc_interfaceTC.h"

#define ANALOG_OID_LEN  13 

typedef struct {
    oid             analogParameterOID[MAX_OID_LEN];
    size_t          analogParameterOID_len;
    char            alarmEnable[SNMP_ENABLE_LEN];
    size_t          alarmEnable_len;
    char            old_alarmEnable[SNMP_ENABLE_LEN];
    size_t          old_alarmEnable_len;
    long            analogAlarmState;
    long            analogAlarmHIHI;
    long            old_analogAlarmHIHI;
    long            analogAlarmHI;
    long            old_analogAlarmHI;
    long            analogAlarmLO;
    long            old_analogAlarmLO;
    long            analogAlarmLOLO;
    long            old_analogAlarmLOLO;
    long            analogAlarmDeadband;
    long            old_analogAlarmDeadband;
}snmp_analogPropertyTable_t;
snmp_analogPropertyTable_t g_analogPropertyTable[ANALOGNODENUM];

const oid analogParOid[ANALOGNODENUM][ANALOG_OID_LEN] =
	{{1,3,6,1,4,1,17409,1,9,3,1,2,1},
    {1,3,6,1,4,1,17409,1,9,5,1,4,1},
    {1,3,6,1,4,1,17409,1,9,8,1,2,1}};

/** Initializes the analogPropertyTable module */
void
init_analogPropertyTable(void)
{
    /*
     * here we initialize all the tables we're planning on supporting 
     */
    initialize_table_analogPropertyTable();
}

//# Determine the first/last column names

/** Initialize the analogPropertyTable table by defining its contents and how it's structured */
void
initialize_table_analogPropertyTable(void)
{
    const oid       analogPropertyTable_oid[] =
        { 1, 3, 6, 1, 4, 1, 17409, 1, 1, 1 };
    const size_t    analogPropertyTable_oid_len =
        OID_LENGTH(analogPropertyTable_oid);
    netsnmp_handler_registration *reg;
    netsnmp_iterator_info *iinfo;
    netsnmp_table_registration_info *table_info;
	int i = 0;

    DEBUGMSGTL(("analogPropertyTable:init",
                "initializing table analogPropertyTable\n"));
	for(i = 0; i < ANALOGNODENUM; i++)
	{
		memcpy(g_analogPropertyTable[i].analogParameterOID, analogParOid[i], sizeof(analogParOid[i]));
		g_analogPropertyTable[i].analogParameterOID_len = sizeof(analogParOid[i]);			
		g_analogPropertyTable[i].alarmEnable[0] = 0x01;
		g_analogPropertyTable[i].alarmEnable_len = sizeof(g_analogPropertyTable[i].alarmEnable);
		g_analogPropertyTable[i].analogAlarmState = 1;	
	}	
	g_analogPropertyTable[0].analogAlarmHIHI = 20;	
	g_analogPropertyTable[0].analogAlarmHI = 10;	
	g_analogPropertyTable[0].analogAlarmLO = -70;
	g_analogPropertyTable[0].analogAlarmLOLO = -90;	
	g_analogPropertyTable[0].analogAlarmDeadband = 5;
	
	g_analogPropertyTable[1].analogAlarmHIHI = 880;	
	g_analogPropertyTable[1].analogAlarmHI = 850;	
	g_analogPropertyTable[1].analogAlarmLO = 750;
	g_analogPropertyTable[1].analogAlarmLOLO = 720;	
	g_analogPropertyTable[1].analogAlarmDeadband = 10;
	
	g_analogPropertyTable[2].analogAlarmHIHI = 140;	
	g_analogPropertyTable[2].analogAlarmHI = 130;	
	g_analogPropertyTable[2].analogAlarmLO = 110;
	g_analogPropertyTable[2].analogAlarmLOLO = 100;	
	g_analogPropertyTable[2].analogAlarmDeadband = 5;
	
    reg =
        netsnmp_create_handler_registration("analogPropertyTable",
                                            analogPropertyTable_handler,
                                            analogPropertyTable_oid,
                                            analogPropertyTable_oid_len,
                                            HANDLER_CAN_RWRITE);

    table_info = SNMP_MALLOC_TYPEDEF(netsnmp_table_registration_info);
    netsnmp_table_helper_add_indexes(table_info, ASN_OBJECT_ID, /* index: analogParameterOID */
                                     0);
    table_info->min_column = COLUMN_ANALOGPARAMETEROID;
    table_info->max_column = COLUMN_ANALOGALARMDEADBAND;

    iinfo = SNMP_MALLOC_TYPEDEF(netsnmp_iterator_info);
    iinfo->get_first_data_point = analogPropertyTable_get_first_data_point;
    iinfo->get_next_data_point = analogPropertyTable_get_next_data_point;
    iinfo->table_reginfo = table_info;

    netsnmp_register_table_iterator(reg, iinfo);
	netsnmp_inject_handler( reg,
						netsnmp_get_cache_handler(HC_CACHE_TIMEOUT,
								analogPropertyTable_load, analogPropertyTable_free,
								analogPropertyTable_oid, OID_LENGTH(analogPropertyTable_oid)));
				DEBUGMSGTL(("analogPropertyTable",
							"initialize analogPropertyTable\n")); 

    /*
     * Initialise the contents of the table here 
     */
}

    /*
     * Typical data structure for a row entry 
     */
struct analogPropertyTable_entry {
    /*
     * Index values 
     */
    oid             analogParameterOID[MAX_OID_LEN];
    size_t          analogParameterOID_len;

    /*
     * Column values 
     */
    //oid             analogParameterOID[NNN];
    //size_t          analogParameterOID_len;
    char            alarmEnable[SNMP_ENABLE_LEN];
    size_t          alarmEnable_len;
    char            old_alarmEnable[SNMP_ENABLE_LEN];
    size_t          old_alarmEnable_len;
    long            analogAlarmState;
    long            analogAlarmHIHI;
    long            old_analogAlarmHIHI;
    long            analogAlarmHI;
    long            old_analogAlarmHI;
    long            analogAlarmLO;
    long            old_analogAlarmLO;
    long            analogAlarmLOLO;
    long            old_analogAlarmLOLO;
    long            analogAlarmDeadband;
    long            old_analogAlarmDeadband;

    /*
     * Illustrate using a simple linked list 
     */
    int             valid;
    struct analogPropertyTable_entry *next;
};

struct analogPropertyTable_entry *analogPropertyTable_head;

/*
 * create a new row in the (unsorted) table 
 */
struct analogPropertyTable_entry *
analogPropertyTable_createEntry(struct analogPropertyTable_entry *analogPropertyTable)
{
    struct analogPropertyTable_entry *entry;

    entry = SNMP_MALLOC_TYPEDEF(struct analogPropertyTable_entry);
    if (!entry)
        return NULL;

    //memcpy(entry->analogParameterOID, analogParameterOID,
    //       analogParameterOID_len);
    //entry->analogParameterOID_len = analogParameterOID_len;
	memcpy(entry, analogPropertyTable, sizeof(*entry));
    entry->next = analogPropertyTable_head;
    analogPropertyTable_head = entry;
    return entry;
}

/*
 * remove a row from the table 
 */
void
analogPropertyTable_removeEntry(struct analogPropertyTable_entry *entry)
{
    struct analogPropertyTable_entry *ptr, *prev;

    if (!entry)
        return;                 /* Nothing to remove */

    for (ptr = analogPropertyTable_head, prev = NULL;
         ptr != NULL; prev = ptr, ptr = ptr->next) {
        if (ptr == entry)
            break;
    }
    if (!ptr)
        return;                 /* Can't find it */

    if (prev == NULL)
        analogPropertyTable_head = ptr->next;
    else
        prev->next = ptr->next;

    SNMP_FREE(entry);           /* XXX - release any other internal resources */
}

void analogPropertyTable_removeAllEntry(void )
{
    struct analogPropertyTable_entry *ptr, *pnext;

    for (ptr = analogPropertyTable_head; ptr != NULL; ptr = pnext) {
		 pnext = ptr->next;
		 SNMP_FREE(ptr); 
    }
	analogPropertyTable_head = NULL;
}

void analogPropertyTable_setEntry(
				struct analogPropertyTable_entry *entry, 
				snmp_analogPropertyTable_t *pinfo
				)
{

	memset(entry, 0, sizeof(struct analogPropertyTable_entry));

	memcpy(entry->analogParameterOID, pinfo->analogParameterOID, sizeof(entry->analogParameterOID));
	entry->analogParameterOID_len = pinfo->analogParameterOID_len;
	memcpy(entry->alarmEnable, pinfo->alarmEnable, sizeof(entry->alarmEnable));
	entry->alarmEnable_len = pinfo->alarmEnable_len;
	
	entry->analogAlarmState = pinfo->analogAlarmState;

	entry->analogAlarmHIHI = pinfo->analogAlarmHIHI;

	entry->analogAlarmHI = pinfo->analogAlarmHI;

	entry->analogAlarmLO = pinfo->analogAlarmLO;
	
	entry->analogAlarmLOLO = pinfo->analogAlarmLOLO; 

	entry->analogAlarmDeadband = pinfo->analogAlarmDeadband;
}

/*
 * Example iterator hook routines - using 'get_next' to do most of the work 
 */
netsnmp_variable_list *
analogPropertyTable_get_first_data_point(void **my_loop_context,
                                         void **my_data_context,
                                         netsnmp_variable_list *
                                         put_index_data,
                                         netsnmp_iterator_info *mydata)
{
    *my_loop_context = analogPropertyTable_head;
    return analogPropertyTable_get_next_data_point(my_loop_context,
                                                   my_data_context,
                                                   put_index_data, mydata);
}

netsnmp_variable_list *
analogPropertyTable_get_next_data_point(void **my_loop_context,
                                        void **my_data_context,
                                        netsnmp_variable_list *
                                        put_index_data,
                                        netsnmp_iterator_info *mydata)
{
    struct analogPropertyTable_entry *entry =
        (struct analogPropertyTable_entry *) *my_loop_context;
    netsnmp_variable_list *idx = put_index_data;

    if (entry) {
		/*
        snmp_set_var_value(idx, entry->analogParameterOID,
                           sizeof(entry->analogParameterOID));*/
		snmp_set_var_typed_value(idx, ASN_OBJECT_ID,
                                         (u_char *) entry->analogParameterOID,
                                         entry->analogParameterOID_len);
        idx = idx->next_variable;
        *my_data_context = (void *) entry;
        *my_loop_context = (void *) entry->next;
        return put_index_data;
    } else {
        return NULL;
    }
}


/** handles requests for the analogPropertyTable table */
int
analogPropertyTable_handler(netsnmp_mib_handler *handler,
                            netsnmp_handler_registration *reginfo,
                            netsnmp_agent_request_info *reqinfo,
                            netsnmp_request_info *requests)
{
	int ret = 0;
    netsnmp_request_info *request;
    netsnmp_table_request_info *table_info;
    struct analogPropertyTable_entry *table_entry;
	ipc_analogPropertyTable_ack_t *pack = NULL;
	ipc_analogPropertyTable_ack_t *pack_send = NULL;
	AnalogProperty_t pinfo;
	memset(&pinfo, 0, sizeof(AnalogProperty_t));
	
    DEBUGMSGTL(("analogPropertyTable:handler", "Processing request (%d)\n",
                reqinfo->mode));

    switch (reqinfo->mode) {
        /*
         * Read-support (also covers GetNext requests)
         */
    case MODE_GET:
        for (request = requests; request; request = request->next) {
            table_entry = (struct analogPropertyTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);

            switch (table_info->colnum) {
            case COLUMN_ANALOGPARAMETEROID:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_value(request->requestvb, ASN_OBJECT_ID,
                                         (u_char *) table_entry->analogParameterOID,
                                         table_entry->analogParameterOID_len);
                break;
            case COLUMN_ALARMENABLE:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_value(request->requestvb, ASN_OCTET_STR,
                                         (u_char *) table_entry->alarmEnable,
                                         table_entry->alarmEnable_len);
                break;
            case COLUMN_ANALOGALARMSTATE:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->analogAlarmState);
                break;
            case COLUMN_ANALOGALARMHIHI:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->analogAlarmHIHI);
                break;
            case COLUMN_ANALOGALARMHI:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->analogAlarmHI);
                break;
            case COLUMN_ANALOGALARMLO:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->analogAlarmLO);
                break;
            case COLUMN_ANALOGALARMLOLO:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->analogAlarmLOLO);
                break;
            case COLUMN_ANALOGALARMDEADBAND:
                if (!table_entry) {
                    netsnmp_set_request_error(reqinfo, request,
                                              SNMP_NOSUCHINSTANCE);
                    continue;
                }
                snmp_set_var_typed_integer(request->requestvb, ASN_INTEGER,
                                           table_entry->analogAlarmDeadband);
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
            table_entry = (struct analogPropertyTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);

            switch (table_info->colnum) {
            case COLUMN_ALARMENABLE:
                /*
                 * or possibly 'netsnmp_check_vb_type_and_size' 
                 */
                ret =
                    netsnmp_check_vb_type_and_max_size(request->requestvb,
                                                       ASN_OCTET_STR,
                                                       sizeof(table_entry->alarmEnable));
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            case COLUMN_ANALOGALARMHIHI:
                /*
                 * or possibly 'netsnmp_check_vb_int_range' 
                 */
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            case COLUMN_ANALOGALARMHI:
                /*
                 * or possibly 'netsnmp_check_vb_int_range' 
                 */
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            case COLUMN_ANALOGALARMLO:
                /*
                 * or possibly 'netsnmp_check_vb_int_range' 
                 */
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            case COLUMN_ANALOGALARMLOLO:
                /*
                 * or possibly 'netsnmp_check_vb_int_range' 
                 */
                ret = netsnmp_check_vb_int(request->requestvb);
                if (ret != SNMP_ERR_NOERROR) {
                    netsnmp_set_request_error(reqinfo, request, ret);
                    return SNMP_ERR_NOERROR;
                }
                break;
            case COLUMN_ANALOGALARMDEADBAND:
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
		pack = ipc_analogPropertyTable(ipc_fd, IPC_CONFIG_GET, IPC_APPLY_NONE, NULL);
		if(pack && pack->hdr.status == IPC_STATUS_OK) 
		{		
			memcpy(&pinfo, &pack->AnalogProperty, sizeof(AnalogProperty_t));
			if(pack)
			{
				free(pack);
			}
		}
		else
		{	
			if(pack)
			{
				free(pack);
			}
			return SNMP_ERR_GENERR;
		}
        for (request = requests; request; request = request->next) {
            table_entry = (struct analogPropertyTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);
            switch (table_info->colnum) {
            case COLUMN_ALARMENABLE:
                memcpy(table_entry->old_alarmEnable,
                       table_entry->alarmEnable,
                       sizeof(table_entry->alarmEnable));
                table_entry->old_alarmEnable_len =
                    table_entry->alarmEnable_len;
                memset(table_entry->alarmEnable, 0,
                       sizeof(table_entry->alarmEnable));
                memcpy(table_entry->alarmEnable,
                       request->requestvb->val.string,
                       request->requestvb->val_len);
                table_entry->alarmEnable_len = request->requestvb->val_len;
                break;
            case COLUMN_ANALOGALARMHIHI:
                table_entry->old_analogAlarmHIHI =
                    table_entry->analogAlarmHIHI;
                table_entry->analogAlarmHIHI =
                    *request->requestvb->val.integer;
                break;
            case COLUMN_ANALOGALARMHI:
                table_entry->old_analogAlarmHI =
                    table_entry->analogAlarmHI;
                table_entry->analogAlarmHI =
                    *request->requestvb->val.integer;
                break;
            case COLUMN_ANALOGALARMLO:
                table_entry->old_analogAlarmLO =
                    table_entry->analogAlarmLO;
                table_entry->analogAlarmLO =
                    *request->requestvb->val.integer;
                break;
            case COLUMN_ANALOGALARMLOLO:
                table_entry->old_analogAlarmLOLO =
                    table_entry->analogAlarmLOLO;
                table_entry->analogAlarmLOLO =
                    *request->requestvb->val.integer;
                break;
            case COLUMN_ANALOGALARMDEADBAND:
                table_entry->old_analogAlarmDeadband =
                    table_entry->analogAlarmDeadband;
                table_entry->analogAlarmDeadband =
                    *request->requestvb->val.integer;
                break;
            }

			if(3 == request->requestvb->name_loc[22])
				pinfo.index = 0;
			else if(5 == request->requestvb->name_loc[22])
				pinfo.index = 1;
			else if(8 == request->requestvb->name_loc[22])
				pinfo.index = 2;
        }		
			
		memcpy(pinfo.AnalogAlarmPropertyTable[pinfo.index].alarmEnable,table_entry->alarmEnable, sizeof(pinfo.AnalogAlarmPropertyTable[pinfo.index].alarmEnable));
		pinfo.AnalogAlarmPropertyTable[pinfo.index].analogAlarmHIHI = table_entry->analogAlarmHIHI;
		pinfo.AnalogAlarmPropertyTable[pinfo.index].analogAlarmHI = table_entry->analogAlarmHI;
		pinfo.AnalogAlarmPropertyTable[pinfo.index].analogAlarmLO = table_entry->analogAlarmLO;
		pinfo.AnalogAlarmPropertyTable[pinfo.index].analogAlarmLOLO = table_entry->analogAlarmLOLO;
		pinfo.AnalogAlarmPropertyTable[pinfo.index].analogAlarmDeadband = table_entry->analogAlarmDeadband;

		pack_send = ipc_analogPropertyTable(ipc_fd, IPC_CONFIG_SET, IPC_APPLY_NOW /*| IPC_APPLY_COMMIT*/, &pinfo);
		if(pack_send)
	    {
	    	free(pack_send);
	    }
		ret = ipc_system_request(IPC_SYS_NVRAM_COMMIT);
		if(IPC_STATUS_OK != ret)
	    {
	        printf("System running config saved to flash memory failed!");	   
		}
        break;

    case MODE_SET_UNDO:
        for (request = requests; request; request = request->next) {
            table_entry = (struct analogPropertyTable_entry *)
                netsnmp_extract_iterator_context(request);
            table_info = netsnmp_extract_table_info(request);

            switch (table_info->colnum) {
            case COLUMN_ALARMENABLE:
                memcpy(table_entry->alarmEnable,
                       table_entry->old_alarmEnable,
                       sizeof(table_entry->alarmEnable));
                memset(table_entry->old_alarmEnable, 0,
                       sizeof(table_entry->alarmEnable));
                table_entry->alarmEnable_len =
                    table_entry->old_alarmEnable_len;
                break;
            case COLUMN_ANALOGALARMHIHI:
                table_entry->analogAlarmHIHI =
                    table_entry->old_analogAlarmHIHI;
                table_entry->old_analogAlarmHIHI = 0;
                break;
            case COLUMN_ANALOGALARMHI:
                table_entry->analogAlarmHI =
                    table_entry->old_analogAlarmHI;
                table_entry->old_analogAlarmHI = 0;
                break;
            case COLUMN_ANALOGALARMLO:
                table_entry->analogAlarmLO =
                    table_entry->old_analogAlarmLO;
                table_entry->old_analogAlarmLO = 0;
                break;
            case COLUMN_ANALOGALARMLOLO:
                table_entry->analogAlarmLOLO =
                    table_entry->old_analogAlarmLOLO;
                table_entry->old_analogAlarmLOLO = 0;
                break;
            case COLUMN_ANALOGALARMDEADBAND:
                table_entry->analogAlarmDeadband =
                    table_entry->old_analogAlarmDeadband;
                table_entry->old_analogAlarmDeadband = 0;
                break;
            }
        }		
        break;

    case MODE_SET_COMMIT:
        break;
    }
    return SNMP_ERR_NOERROR;
}

int analogPropertyTable_load(netsnmp_cache *cache, void *vmagic)
{
	int ret = 0;
	int i = 0;
	struct analogPropertyTable_entry entry;

	snmp_analogPropertyTable_t *pinfo = NULL;
	int DCPower_num = 0;

	/* Free All */
	analogPropertyTable_removeAllEntry();
	//analogPropertyTable_removeEntry(&entry);

	DCPower_num = ANALOGNODENUM;
	/*alarms_num =ipc_snmp_alarm_num(&agent)*/
	if (DCPower_num == 0){
		DBG_ASSERT(0, "RxDCPower num is 0");
		return 0;
	}
	
	pinfo = g_analogPropertyTable;
	#if 1
	AnalogProperty_t info;
	ipc_analogPropertyTable_ack_t *pack = NULL;
	memset(&info , 0, sizeof(AnalogProperty_t));
	pack = ipc_analogPropertyTable(ipc_fd, IPC_CONFIG_GET, IPC_APPLY_NONE, NULL);
	if(pack && pack->hdr.status == IPC_STATUS_OK) 
	{		
		memcpy(&info , &pack->AnalogProperty, sizeof(AnalogProperty_t));
		
		for (i = 0; i < DCPower_num; i++)
		{			
			memcpy(pinfo[i].alarmEnable,info.AnalogAlarmPropertyTable[i].alarmEnable, sizeof(pinfo[i].alarmEnable));
			pinfo[i].analogAlarmState = info.AnalogAlarmPropertyTable[i].analogAlarmState;
			pinfo[i].analogAlarmHIHI = info.AnalogAlarmPropertyTable[i].analogAlarmHIHI;
			pinfo[i].analogAlarmHI = info.AnalogAlarmPropertyTable[i].analogAlarmHI;
			pinfo[i].analogAlarmLO = info.AnalogAlarmPropertyTable[i].analogAlarmLO;
			pinfo[i].analogAlarmLOLO = info.AnalogAlarmPropertyTable[i].analogAlarmLOLO;
			pinfo[i].analogAlarmDeadband = info.AnalogAlarmPropertyTable[i].analogAlarmDeadband;
		}
		if(pack)
		{
			free(pack);
		}
	}
	else
	{	
		if(pack)
		{
			free(pack);
		}		
		//DEBUGMSGTL((DBGTOKEN,"snmp get input_laser_power from master fail!\n"));
		return SNMP_ERR_GENERR;
	}
	#endif
	for (i = 0; i < DCPower_num; i++)
	{
		analogPropertyTable_setEntry(&entry, &pinfo[i]);	
		analogPropertyTable_createEntry(&entry);	
	}

safe_exit:
	
	HC_IPC_ASSERT(ret);
	
    return ret; 
} 


void analogPropertyTable_free(netsnmp_cache *cache, void *magic)
{
	DEBUGMSGTL(("analogPropertyTable", "Free analogPropertyTable Group\n"));  
}

