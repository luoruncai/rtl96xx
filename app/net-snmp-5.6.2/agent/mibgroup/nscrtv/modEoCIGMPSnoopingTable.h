/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 15999 2007-03-25 22:32:02Z dts12 $
 */
#ifndef MODEOCIGMPSNOOPINGTABLE_H
#define MODEOCIGMPSNOOPINGTABLE_H

/*
 * function declarations 
 */
void            init_modEoCIGMPSnoopingTable(void);
void            initialize_table_modEoCIGMPSnoopingTable(void);
Netsnmp_Node_Handler modEoCIGMPSnoopingTable_handler;
Netsnmp_First_Data_Point modEoCIGMPSnoopingTable_get_first_data_point;
Netsnmp_Next_Data_Point modEoCIGMPSnoopingTable_get_next_data_point;

/*
 * column number definitions for table modEoCIGMPSnoopingTable 
 */
#define COLUMN_MODEOCIGMPSNOOPINGCBATCARDINDEX		1
#define COLUMN_MODEOCIGMPSNOOPINGCNUINDEX		2
#define COLUMN_MODEOCIGMPSNOOPINGDEVMACADDRESS		3
#define COLUMN_MODEOCIGMPSNOOPINGEN		4
#endif                          /* MODEOCIGMPSNOOPINGTABLE_H */
