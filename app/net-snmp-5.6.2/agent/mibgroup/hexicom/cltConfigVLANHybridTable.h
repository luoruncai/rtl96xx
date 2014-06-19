/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 15999 2007-03-25 22:32:02Z dts12 $
 */
#ifndef CLTCONFIGVLANHYBRIDTABLE_H
#define CLTCONFIGVLANHYBRIDTABLE_H

/*
 * function declarations 
 */
void            init_cltConfigVLANHybridTable(void);
void            initialize_table_cltConfigVLANHybridTable(void);
Netsnmp_Node_Handler cltConfigVLANHybridTable_handler;
Netsnmp_First_Data_Point cltConfigVLANHybridTable_get_first_data_point;
Netsnmp_Next_Data_Point cltConfigVLANHybridTable_get_next_data_point;


NetsnmpCacheLoad         cltConfigVLANHybridTable_load;
NetsnmpCacheFree         cltConfigVLANHybridTable_free;
void cltConfigVLANHybridTable_commit(unsigned int regNo, void *clientargs);


/*
 * column number definitions for table cltConfigVLANHybridTable 
 */
#define COLUMN_CLTCONFIGVLANHYBRIDINDEX		1
#define COLUMN_CLTCONFIGVLANHYBRIDPORTID		2
#define COLUMN_CLTCONFIGVLANHYBRIDPORTNAME		3
#define COLUMN_CLTCONFIGVLANHYBRIDPVID		4
#define COLUMN_CLTCONFIGVLANHYBRIDTAGGED		5
#define COLUMN_CLTCONFIGVLANHYBRIDUNTAGGED		6
#define COLUMN_CLTCONFIGVLANHYBRIDROWSTATUS		7
#endif                          /* CLTCONFIGVLANHYBRIDTABLE_H */
