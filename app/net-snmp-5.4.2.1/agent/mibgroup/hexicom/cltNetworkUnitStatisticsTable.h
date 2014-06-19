/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 15999 2007-03-25 22:32:02Z dts12 $
 */
#ifndef CLTNETWORKUNITSTATISTICSTABLE_H
#define CLTNETWORKUNITSTATISTICSTABLE_H

/*
 * function declarations 
 */
void            init_cltNetworkUnitStatisticsTable(void);
void            initialize_table_cltNetworkUnitStatisticsTable(void);
Netsnmp_Node_Handler cltNetworkUnitStatisticsTable_handler;
Netsnmp_First_Data_Point
    cltNetworkUnitStatisticsTable_get_first_data_point;
Netsnmp_Next_Data_Point cltNetworkUnitStatisticsTable_get_next_data_point;

NetsnmpCacheLoad         cltNetworkUnitStatisticsTable_load;
NetsnmpCacheFree         cltNetworkUnitStatisticsTable_free;
void cltNetworkUnitStatisticsTable_commit(unsigned int regNo, void *clientargs);



/*
 * column number definitions for table cltNetworkUnitStatisticsTable 
 */
#define COLUMN_CLTNETWORKUNITPREFECBITSERRORRATE		1
#define COLUMN_CLTNETWORKUNITBITSPERCARRIER		2
#define COLUMN_CLTNETWORKUNITSNRPERCARRIER		3
#define COLUMN_CLTNETWORKUNITTXPBCRCERRORRATE		4
#define COLUMN_CLTNETWORKUNITRXPBCRCERRORRATE		5
#define COLUMN_CLTNETWORKUNITATTENUATION		6
#define COLUMN_CLTNETWORKUNITOUTPUTPOWER		7
#define COLUMN_CLTNETWORKUNITRXPKTSTOTAL		8
#define COLUMN_CLTNETWORKUNITRXPKTSERRORTOTAL		9
#define COLUMN_CLTNETWORKUNITTXPKTSTOTAL		10
#define COLUMN_CLTNETWORKUNITTXPKTSERRORTOTAL		11
#define COLUMN_CLTNETWORKUNITHWADDR		12
#define COLUMN_CLTNETWORKUNITSTATISTICSSTATUS		13
#endif                          /* CLTNETWORKUNITSTATISTICSTABLE_H */
