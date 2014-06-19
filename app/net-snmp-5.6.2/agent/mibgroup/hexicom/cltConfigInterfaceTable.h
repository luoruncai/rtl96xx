/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 15999 2007-03-25 22:32:02Z dts12 $
 */
#ifndef CLTCONFIGINTERFACETABLE_H
#define CLTCONFIGINTERFACETABLE_H

/*
 * function declarations 
 */
void            init_cltConfigInterfaceTable(void);
void            initialize_table_cltConfigInterfaceTable(void);
Netsnmp_Node_Handler cltConfigInterfaceTable_handler;
Netsnmp_First_Data_Point cltConfigInterfaceTable_get_first_data_point;
Netsnmp_Next_Data_Point cltConfigInterfaceTable_get_next_data_point;


NetsnmpCacheLoad         cltConfigInterfaceTable_load;
NetsnmpCacheFree         cltConfigInterfaceTable_free;
void cltConfigInterfaceTable_commit(unsigned int regNo, void *clientargs);



/*
 * column number definitions for table cltConfigInterfaceTable 
 */
#define COLUMN_CLTCONFIGIFINDEX		1
#define COLUMN_CLTCONFIGIFTYPE		2
#define COLUMN_CLTCONFIGIFNAME		3
#define COLUMN_CLTCONFIGIFADMINSTATUS		4
#define COLUMN_CLTCONFIGIFDUPLEXMODE		5
#define COLUMN_CLTCONFIGIFSPEEDMODE		6
#define COLUMN_CLTCONFIGIFFLOWCONTROL		7
#define COLUMN_CLTCONFIGIFPRIORITY		8
#define COLUMN_CLTCONFIGIFINGRESSRATELIMITATION		9
#define COLUMN_CLTCONFIGIFEGRESSRATELIMITATION		10
#define COLUMN_CLTCONFIGIFPVID		11
#define COLUMN_CLTCONFIGIFLINKSTATUS		12
#define COLUMN_CLTCONFIGIFLINKSPEEDMODE		13
#define COLUMN_CLTCONFIGIFLINKDUPLEXMODE		14
#endif                          /* CLTCONFIGINTERFACETABLE_H */
