/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 15999 2007-03-25 22:32:02Z dts12 $
 */
#ifndef CLTDEVICEMODELTABLE_H
#define CLTDEVICEMODELTABLE_H

/*
 * function declarations 
 */
void            init_cltDeviceModelTable(void);
void            initialize_table_cltDeviceModelTable(void);
Netsnmp_Node_Handler cltDeviceModelTable_handler;
Netsnmp_First_Data_Point cltDeviceModelTable_get_first_data_point;
Netsnmp_Next_Data_Point cltDeviceModelTable_get_next_data_point;

int cltDeviceModelTable_load(void);


/*
 * column number definitions for table cltDeviceModelTable 
 */
#define COLUMN_CLTDEVICEMODELINDEX		1
#define COLUMN_CLTDEVICEMODELNAME		2
#define COLUMN_CLTDEVICEMODELIFNUMBER		3
#endif                          /* CLTDEVICEMODELTABLE_H */
