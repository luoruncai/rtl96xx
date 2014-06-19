/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 17695 2009-07-21 12:22:18Z dts12 $
 */
#ifndef DORDCPOWERTABLE_H
#define DORDCPOWERTABLE_H
config_add_mib(EPN104ZG-MIB-V1)
config_require(util_funcs/header_generic)
config_require(EPN104/dorDCPowerTable)

/*
 * function declarations 
 */
void            init_dorDCPowerTable(void);
void            initialize_table_dorDCPowerTable(void);
Netsnmp_Node_Handler dorDCPowerTable_handler;
Netsnmp_First_Data_Point dorDCPowerTable_get_first_data_point;
Netsnmp_Next_Data_Point dorDCPowerTable_get_next_data_point;
NetsnmpCacheLoad         dorDCPowerTable_load;
NetsnmpCacheFree         dorDCPowerTable_free;

/*
 * column number definitions for table dorDCPowerTable 
 */
#define COLUMN_DORDCPOWERINDEX		1
#define COLUMN_DORDCPOWERVOLTAGE		2
#define COLUMN_DORDCPOWERCURRENT		3
#define COLUMN_DORDCPOWERNAME		4
#endif                          /* DORDCPOWERTABLE_H */
