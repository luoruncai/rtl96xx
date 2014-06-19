/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.scalar.conf 11805 2005-01-07 09:37:18Z dts12 $
 */
#ifndef EOCCLTSYSTEMINFO_H
#define EOCCLTSYSTEMINFO_H


#define CLTINFOPRODUCTMODEL  1
#define CLTINFOMACADDRESS   2
#define CLTINFOLOCALTIME   3
#define CLTINFOSOFTWAREVERSION  4
#define CLTINFOHARDWAREVERSION  5
#define CLTINFOMIBVERSION  6 
#define CLTINFOCABLEMACADDRESS 7
#define CLTINFOTEMPERATURE  8
#define CLTINFOOEMID    9
/*
 * function declarations 
 */
void            init_eocCLTSystemInfo(void);

Netsnmp_Node_Handler 	eocCLTSystemInfo_handler;
NetsnmpCacheLoad 		eocCLTSystemInfo_load;
NetsnmpCacheFree 		eocCLTSystemInfo_free;

void eocCLTSystemInfo_get(netsnmp_variable_list *requestvb, oid subid);



#endif                          /* EOCCLTSYSTEMINFO_H */
