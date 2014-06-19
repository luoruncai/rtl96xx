/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.scalar.conf 11805 2005-01-07 09:37:18Z dts12 $
 */
#ifndef CLTCONFIGREMOTEUPGRADE_H
#define CLTCONFIGREMOTEUPGRADE_H

#define CLTCONFIGUPGRADEENABLE 1
#define CLTCONFIGUPGRADEURL 2
#define CLTCONFIGUPGRADELOGINUSERNAME 3
#define CLTCONFIGUPGRADELOGINPASSWORD 4
#define CLTCONFIGUPGRADESUBMIT 5
#define CLTCONFIGUPGRADEINTERVAL 6

/*
 * function declarations 
 */
void            init_cltConfigRemoteUpgrade(void);
Netsnmp_Node_Handler 	cltConfigRemoteUpgrade_handler;
NetsnmpCacheLoad 		cltConfigRemoteUpgrade_load;
NetsnmpCacheFree 		cltConfigRemoteUpgrade_free;
SNMPAlarmCallback 		cltConfigRemoteUpgrade_commit;


#endif                          /* CLTCONFIGREMOTEUPGRADE_H */
