/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.scalar.conf 11805 2005-01-07 09:37:18Z dts12 $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "eocCLTSystemInfo.h"

#include "ipc_interfaceTC.h"

#ifndef DBGID
#define DBGID  "hc:cltinfo"
#endif

#ifndef DBGID
#define DBGID "defalut"
#endif 


typedef struct{
	char productmodel[HC_SYS_MODEL_SIZE];
	unsigned char mac_address[HC_MAC_ADDRESS_SIZE];
	uint32_t localtime;
	char sw_version[HC_SYS_VERSION_SIZE];
	char hw_version[HC_SYS_VERSION_SIZE];
	char mib_version[HC_MIB_VERSION_SIZE];
	unsigned char cable_mac_address[HC_MAC_ADDRESS_SIZE];
	int temperature;
    int oem_id;
}
eocCLTSystemInfo_t;

static eocCLTSystemInfo_t eocCLTSystemInfo;

static oid		eocCLTSystemInfo_oid[] = {HC_CLT_OBJ_OID, 1};


void init_eocCLTSystemInfo(void)
{
    netsnmp_handler_registration *reginfo;

    /*
     * register ourselves with the agent as a group of scalars...
     */
		
	DEBUGMSGTL((DBGID, "Initializing\n"));

    reginfo = netsnmp_create_handler_registration("eocCLTSystemInfo", eocCLTSystemInfo_handler,
		    eocCLTSystemInfo_oid, OID_LENGTH(eocCLTSystemInfo_oid), HANDLER_CAN_RONLY);
	
    netsnmp_register_scalar_group(reginfo, CLTINFOPRODUCTMODEL, CLTINFOOEMID);

    netsnmp_inject_handler( reginfo,
		    netsnmp_get_cache_handler(HC_CACHE_TIMEOUT,
			   		eocCLTSystemInfo_load, eocCLTSystemInfo_free,
					eocCLTSystemInfo_oid, OID_LENGTH(eocCLTSystemInfo_oid)));

}



int eocCLTSystemInfo_handler(netsnmp_mib_handler          *handler,
             netsnmp_handler_registration *reginfo,
             netsnmp_agent_request_info   *reqinfo,
             netsnmp_request_info         *requests)
{
    netsnmp_request_info  *request;
    netsnmp_variable_list *requestvb;
//    long     ret_value;
    oid      subid;

    /*
     * The cached data should already have been loaded by the
     *    cache handler, higher up the handler chain.
     * But just to be safe, check this and load it manually if necessary
     */

    if (!netsnmp_cache_is_valid(reqinfo, reginfo->handlerName)) {
        netsnmp_assert(!"cache == valid"); /* always false */
        eocCLTSystemInfo_load( NULL, NULL );	/* XXX - check for failure */
    }

    DEBUGMSGTL((DBGID, "Handler - mode %s\n",
                    se_find_label_in_slist("agent_mode", reqinfo->mode)));
    switch (reqinfo->mode) {
    case MODE_GET:
        for (request=requests; request; request=request->next) {
            requestvb = request->requestvb;
            subid = requestvb->name[OID_LENGTH(eocCLTSystemInfo_oid)];  /* XXX */
			HC_DBG_OID(requestvb);
			eocCLTSystemInfo_get(requestvb, subid);
       	}
        break;

    case MODE_GETNEXT:
    case MODE_GETBULK:
    case MODE_SET_RESERVE1:
    case MODE_SET_RESERVE2:
    case MODE_SET_ACTION:
    case MODE_SET_COMMIT:
    case MODE_SET_FREE:
    case MODE_SET_UNDO:
        snmp_log(LOG_WARNING, "eocCLTSystemInfo: Unsupported mode (%d)\n", reqinfo->mode);
        break;
    default:
        snmp_log(LOG_WARNING, "eocCLTSystemInfo: Unrecognised mode (%d)\n", reqinfo->mode);
        break;
   }
   return SNMP_ERR_NOERROR;
}



int eocCLTSystemInfo_load(netsnmp_cache *cache, void *vmagic)
{
    long            ret_value = -1;
	sys_info_t info;

	ret_value = ipc_get_sys_info(&info);

    if ( HC_IPC_ERROR(ret_value)) {
        DEBUGMSGTL((DBGID, "Failed to load eocCLTSystemInfo Group\n"));
    } else {
        DEBUGMSGTL((DBGID, "Loaded eocCLTSystemInfo Group\n"));
    }	

	HC_IPC_ASSERT(ret_value);

	safe_strncpy(eocCLTSystemInfo.productmodel, HC_PORD_MODEL, sizeof(eocCLTSystemInfo.productmodel));

	memcpy(eocCLTSystemInfo.mac_address, info.sysmac.octet, HC_MAC_ADDRESS_SIZE);
	memset(eocCLTSystemInfo.cable_mac_address, 0, 6);

	safe_strncpy(eocCLTSystemInfo.sw_version, info.sw_version, sizeof(eocCLTSystemInfo.sw_version));
	safe_strncpy(eocCLTSystemInfo.hw_version, info.hw_version, sizeof(eocCLTSystemInfo.hw_version));

	safe_strncpy(eocCLTSystemInfo.mib_version, HC_MIB_VERSION, sizeof(eocCLTSystemInfo.mib_version));
	
	eocCLTSystemInfo.localtime = info.uptime;
	eocCLTSystemInfo.temperature = 0;
	eocCLTSystemInfo.oem_id = HC_OEMID;
	
    return ret_value;
}


void eocCLTSystemInfo_free(netsnmp_cache *cache, void *magic)
{
   
}


void eocCLTSystemInfo_get(netsnmp_variable_list *requestvb, oid subid)
{

	switch (subid) {
	case CLTINFOPRODUCTMODEL:
		snmp_set_var_typed_value(requestvb, ASN_OCTET_STR,
							 (u_char *)eocCLTSystemInfo.productmodel, 
							 strlen(eocCLTSystemInfo.productmodel));
		break;
	case CLTINFOMACADDRESS:
		snmp_set_var_typed_value(requestvb, ASN_OCTET_STR,
							 (u_char *)eocCLTSystemInfo.mac_address, 
							 sizeof(eocCLTSystemInfo.mac_address));				
		break;
	case CLTINFOLOCALTIME:
		snmp_set_var_typed_value(requestvb, ASN_INTEGER,
							 (u_char *)&eocCLTSystemInfo.localtime, 
							 sizeof(eocCLTSystemInfo.localtime));
		break;				
	case CLTINFOSOFTWAREVERSION:
		snmp_set_var_typed_value(requestvb, ASN_OCTET_STR,
							 (u_char *)eocCLTSystemInfo.sw_version, 
							 strlen(eocCLTSystemInfo.sw_version));
		break;				
	case CLTINFOHARDWAREVERSION:
		snmp_set_var_typed_value(requestvb, ASN_OCTET_STR,
							 (u_char *)eocCLTSystemInfo.hw_version, 
							 strlen(eocCLTSystemInfo.hw_version));
		break;				
		
	case CLTINFOMIBVERSION:
		snmp_set_var_typed_value(requestvb, ASN_OCTET_STR,
							 (u_char *)eocCLTSystemInfo.mib_version, 
							 strlen(eocCLTSystemInfo.mib_version));
		break;				
		
	case CLTINFOCABLEMACADDRESS:
		snmp_set_var_typed_value(requestvb, ASN_OCTET_STR,
							 (u_char *)eocCLTSystemInfo.cable_mac_address, 
							 sizeof(eocCLTSystemInfo.cable_mac_address));
		break;				
		
	case CLTINFOTEMPERATURE:
		snmp_set_var_typed_value(requestvb, ASN_INTEGER,
							 (u_char *)&eocCLTSystemInfo.temperature, 
							 sizeof(eocCLTSystemInfo.temperature));
		break;	
	case CLTINFOOEMID:
		snmp_set_var_typed_value(requestvb, ASN_INTEGER,
							 (u_char *)&eocCLTSystemInfo.oem_id, 
							 sizeof(eocCLTSystemInfo.oem_id));
		break;				
	}
}

