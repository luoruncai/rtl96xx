/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 15999 2007-03-25 22:32:02Z dts12 $
 */
#ifndef MODEOCCNUWHITELISTTABLE_H
#define MODEOCCNUWHITELISTTABLE_H

/*
 * function declarations 
 */
void            init_modEoCCNUWhiteListTable(void);
void            initialize_table_modEoCCNUWhiteListTable(void);
Netsnmp_Node_Handler modEoCCNUWhiteListTable_handler;
Netsnmp_First_Data_Point modEoCCNUWhiteListTable_get_first_data_point;
Netsnmp_Next_Data_Point modEoCCNUWhiteListTable_get_next_data_point;

/*
 * column number definitions for table modEoCCNUWhiteListTable 
 */
#define COLUMN_MODEOCCNUWHITELISTINDEX		1
#define COLUMN_MODEOCCNUWHITELISTMACADDRESS		2
#define COLUMN_MODEOCCNUWHITELISTAUTHORIZATION		3
#define COLUMN_MODEOCCNUWHITELISTRFOUTPUTLEVEL		4
#define COLUMN_MODEOCCNUWHITELISTAUTOUPGRADEEN		5
#define COLUMN_MODEOCCNUWHITELISTREGISTERONLINESTATE		6
#define COLUMN_MODEOCCNUWHITELISTSTARTTIME		7
#define COLUMN_MODEOCCNUWHITELISTENDTIME		8
#define COLUMN_MODEOCCNUWHITELISTROWSTATUS		9
#endif                          /* MODEOCCNUWHITELISTTABLE_H */
