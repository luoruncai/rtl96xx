/*
 * This program is the proprietary software of Realtek Semiconductor
 * Corporation and/or its licensors, and only be used, duplicated,
 * modified or distributed under the authorized license from Realtek.
 *
 * ANY USE OF THE SOFTWARE OTHER THAN AS AUTHORIZED UNDER
 * THIS LICENSE OR COPYRIGHT LAW IS PROHIBITED.
 *
 *
 * *
 * $Revision: 39101 $
 * $Date: 2012-08-07
 *
 * Purpose : GPON MAC register access APIs
 *
 * Feature : Provide the APIs to access GPON MAC
 *
 */
#ifndef _GPON_V2_H_
#define _GPON_V2_H_

#include <common/rt_error.h>
#include <common/rt_type.h>
#include <rtk/port.h>



#define GPON_REG_STATUS_CLEAR				0
#define GPON_REG_STATUS_SET				1
#define GPON_REG_16BITS_LOW                     	0
#define GPON_REG_16BITS_HIGH                    	8

#define GPON_REG_OPERRATION_NO             	0
#define GPON_REG_OPERRATION_WRITE		1
#define GPON_REG_OPERRATION_READ          	2
#define GPON_REG_OPERRATION_CLEAN      		3

typedef enum rtk_gpon_dsGtc_pmMiscType_e{
    GPON_REG_DSGTCPMMISC_BIP_BLOCK_ERR = 0,
    GPON_REG_DSGTCPMMISC_BIP_BITS_ERR,
    GPON_REG_DSGTCPMMISC_FEC_CORRECTED_BITS,
    GPON_REG_DSGTCPMMISC_FEC_CORRECTED_BYTES,
    /* Rename from XXX_BLOCKS to XXX_CWS in GPON_MAC_SWIO_r1.1 */
    GPON_REG_DSGTCPMMISC_FEC_CORRETED_CWS,
    GPON_REG_DSGTCPMMISC_FEC_UNCOR_CWS,
    GPON_REG_DSGTCPMMISC_LOM,
    GPON_REG_DSGTCPMMISC_PLOAM_ACCEPT,
    GPON_REG_DSGTCPMMISC_PLOAM_FAIL,
    GPON_REG_DSGTCPMMISC_BWMAP_FAIL,
    GPON_REG_DSGTCPMMISC_BWMAP_INV,
    GPON_REG_DSGTCPMMISC_ACTIVE,
    GPON_REG_DSGTCPMMISC_BWMAP_ACPT,
    GPON_REG_DSGTCPMMISC_GEM_LOS,
    GPON_REG_DSGTCPMMISC_HEC_COR,
    GPON_REG_DSGTCPMMISC_GEM_IDLE,
    GPON_REG_DSGTCPMMISC_GEM_FAIL,
    GPON_REG_DSGTCPMMISC_RX_GEM_NON_IDLE,
    GPON_REG_DSGTCPMMISC_PLEND_CORRECTIONS,
    GPON_REG_DSGTCPMMISC_END,

}rtk_gpon_dsGtc_pmMiscType_t;

typedef enum rtk_gpon_dsGem_pmMiscType_e{
    GPON_REG_DSGEMPMMISC_MULTICAST_RX = 0,
    GPON_REG_DSGEMPMMISC_UNICAST_RX = 1,
    GPON_REG_DSGEMPMMISC_MULTICAST_FWD = 2,
    GPON_REG_DSGEMPMMISC_MULTICAST_LEAK = 3,
    GPON_REG_DSGEMPMMISC_ETH_CRC_ERR = 4,
    GPON_REG_DSGEMPMMISC_OVER_INTERLEAV = 5,
    GPON_REG_DSGEMPMMISC_OMCI_RX = 6,
    GPON_REG_DSGEMPMMISC_END,
}rtk_gpon_dsGem_pmMiscType_t;

typedef enum rtk_gpon_usGtc_pmMiscType_e{
    GPON_REG_USGTCPMMISC_PLOAM_BOH_TX = 0,
    GPON_REG_USGTCPMMISC_GEM_DBRU_TX = 1,
    GPON_REG_USGTCPMMISC_PLOAM_CPU_TX = 2,
    GPON_REG_USGTCPMMISC_PLOAM_AUTO_TX = 3,
    GPON_REG_USGTCPMMISC_GEM_BYTE_TX = 4,
    GPON_REG_USGTCPMMISC_END,
}rtk_gpon_usGtc_pmMiscType_t;




typedef enum rtk_gpon_intrType_e{
	GPON_INTR_GEM_US=0,
	GPON_INTR_GTC_US,
	GPON_INTR_GEM_DS,
	GPON_INTR_AES_DECRYPT,
	GPON_INTR_GTC_DS_CAP,
	GPON_INTR_GTC_DS,
	GPON_INTR_ALL,
	GPON_INTR_END
}rtk_gpon_intrType_t;


typedef enum rtk_gpon_gtcDsIntrType_e{
	GPON_GTC_DS_INTR=0,
	GPON_PLM_BUF_REQ,
	GPON_RNG_REQ_HIS,
	GPON_SN_REQ_HIS,
	GPON_LOM_DLT,
	GPON_DS_FEC_STS_DLT,
	GPON_LOF_DLT,
	GPON_LOS_DLT,
	GPON_GTC_DS_INTR_ALL,
	GPON_GTC_DS_INTR_END
}rtk_gpon_gtcDsIntrType_t;



typedef enum rtk_gpon_onuState_e{
	GPON_STATE_UNKNOWN=0,
	GPON_STATE_O1,
	GPON_STATE_O2,
	GPON_STATE_O3,
	GPON_STATE_O4,
	GPON_STATE_O5,
	GPON_STATE_O6,
	GPON_STATE_O7,
	GPON_STATE_END
}rtk_gpon_onuState_t;



typedef enum rtk_gpon_gtcUsIntrType_e{
	GPON_GTC_US_INTR=0,
	GPON_OPTIC_SD_MISM,
	GPON_OPTIC_SD_TOOLONG,
	GPON_PLM_URG_EMPTY,
	GPON_PLM_NRM_EMPTY,
	GPON_US_FEC_STS,
	GPON_DG_MSG_TX,
	GPON_GTC_US_INTR_ALL,
	GPON_GTC_US_INTR_END
}rtk_gpon_gtcUsIntrType_t;


typedef enum rtk_gpon_gemUsIntrType_e{
	GPON_GEM_US_INTR=0,
	GPON_SD_VALID_LONG,
	GPON_SD_DIFF_HUGE,
	GPON_REQUEST_DELAY,
	GPON_BC_LESS6,
	GPON_ERR_PLI,
	GPON_BURST_TM_LARGER_GTC,
	GPON_BANK_TOO_MUCH_AT_END,
	GPON_BANK_REMAIN_AFRD,
	GPON_BANK_OVERFL,
	GPON_BANK_UNDERFL,
	GPON_GEM_US_INTR_ALL,
	GPON_GEM_US_INTR_END
}rtk_gpon_gemUsIntrType_t;


/*
 * GPON MAC Laser Status
 */
typedef enum rtk_gpon_laser_status_e{
    RTK_GPON_LASER_STATUS_NORMAL = 0,
    RTK_GPON_LASER_STATUS_FORCE_ON = 1,
    RTK_GPON_LASER_STATUS_FORCE_OFF = 2,
    RTK_GPON_LASER_STATUS_END
}rtk_gpon_laser_status_t;


typedef enum rtk_gpon_polarity_e{
    GPON_POLARITY_LOW=0,
    GPON_POLARITY_HIGH,
    GPON_POLARITY_END
}rtk_gpon_polarity_t;


typedef enum rtk_gpon_usAutoPloamType_e{
    GPON_REG_USAUTOPLOAM_NOMSG = 0,
    GPON_REG_USAUTOPLOAM_SN = 1,
    GPON_REG_USAUTOPLOAM_DYINGGASP = 2,
    GPON_REG_USAUTOPOLAM_END
}rtk_gpon_usAutoPloamType_t;


/*
 * GPON MAC MACAddress Table Operation Mode
 */
typedef enum rtk_gpon_macTable_exclude_mode_e{
    RTK_GPON_MACTBL_MODE_INCLUDE = 0,
    RTK_GPON_MACTBL_MODE_EXCLUDE,
    RTK_GPON_MACTBL_MODE_END
}rtk_gpon_macTable_exclude_mode_t;

/*
 * GPON MAC MACAddress filter Operation Mode
 */
typedef enum rtk_gpon_mc_force_mode_e{
    RTK_GPON_MCFORCE_MODE_NORMAL = 0,
    RTK_GPON_MCFORCE_MODE_PASS,
    RTK_GPON_MCFORCE_MODE_DROP,
    RTK_GPON_MCFORCE_MODE_END
}rtk_gpon_mc_force_mode_t;

typedef enum rtk_gpon_ipVer_e{
	GPON_IP_VER_V4=0,
	GPON_IP_VER_V6,
	GPON_IP_VER_END
}rtk_gpon_ipVer_t;


typedef struct rtk_gem_cfg_s{
	uint32 	     gemPortId;
	rtk_enable_t isMulticast;
	rtk_enable_t isEthernet;
	rtk_enable_t isOMCI;
	rtk_enable_t enAES;
}rtk_gem_cfg_t;


typedef enum rtk_gpon_tx_ptn_mode_e{
    RTK_GPON_TX_PTN_MODE_NORMAL = 0,
    RTK_GPON_TX_PTN_MODE_PRBS = 1,
    RTK_GPON_TX_PTN_MODE_CUSTOM = 2,
    RTK_GPON_TX_PTN_MODE_NONE = 3

}rtk_gpon_tx_ptn_mode_t;

/* Function Name:
 *      rtk_gpon_init
 * Description:
 *      gpon register level initial function
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_init(void);  



/* Function Name:
 *      rtk_gpon_resetState_set
 * Description:
 *      reset gpon register
 * Input:
 *	  state: enable for reset gpon register
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_resetState_set(rtk_enable_t state);


/* Function Name:
 *      rtk_gpon_resetDoneState_get
 * Description:
 *      get the reset status 
 * Input:
 *
 * Output:
 *      pState: point of reset status
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_resetDoneState_get(rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_macVersion_get
 * Description:
 *      Read the gpon version
 * Input:
 *
 * Output:
 *      pVersion: point for get gpon version
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_macVersion_get(uint32 *pVersion);

/* Function Name:
 *      rtk_gpon_test_get
 * Description:
 *      For test get gpon test data
 * Input:
 *
 * Output:
 *      pTestData: point for get test data
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_test_get(uint32 *pTestData);

/* Function Name:
 *      rtk_gpon_test_set
 * Description:
 *      For test set gpon test data
 * Input:
 *      testData: assign test data
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_test_set(uint32 testData);

/* Function Name:
 *      rtk_gpon_topIntrMask_get
 * Description:
 *      Get GPON Top level interrupt mask
 * Input:
 *	  topIntrType: type of top interrupt
 * Output:
 *      pState: point of get interrupt state
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_topIntrMask_get(rtk_gpon_intrType_t topIntrType,rtk_enable_t *pState);


/* Function Name:
 *      rtk_gpon_topIntrMask_set
 * Description:
 *      Set GPON Top level interrupt mask
 * Input:
 * 	  topIntrType: type of top interrupt
 *      state: set interrupt mask state
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_topIntrMask_set(rtk_gpon_intrType_t topIntrType,rtk_enable_t state);




/* Function Name:
 *      rtk_gpon_topIntr_get
 * Description:
 *      Set GPON Top level interrupt state
 * Input:
 * 	  topIntrType: type of top interrupt
 * Output:
 *      pState: point for get  interrupt state
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_topIntr_get(rtk_gpon_intrType_t topIntrType,rtk_enable_t *pState);


/* Function Name:
 *      rtk_gpon_topIntr_disableAll
 * Description:
 *      Disable all of top interrupt for GPON
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_topIntr_disableAll(void);  

/*
 
page 0x01 */

/* Function Name:
 *      rtk_gpon_gtcDsIntr_get
 * Description:
 *      Get GTC DS interrupt
 * Input:
 *	   gtcIntrType: type of gtc interrupt type
 * Output:
 *      pState: point for get gtc interrupt  state
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_gtcDsIntr_get(rtk_gpon_gtcDsIntrType_t gtcIntrType,rtk_enable_t *pState);


/* Function Name:
 *      rtk_gpon_gtcDsIntrDlt_get
 * Description:
 *      Get GTC DS interrupt indicator
 * Input:
 *	   gtcIntrType: type of gtc interrupt type
 * Output:
 *      pState: point for get gtc interrupt  state
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_gtcDsIntrDlt_get(rtk_gpon_gtcDsIntrType_t gtcIntrType,rtk_enable_t *pState);


/* Function Name:
 *      rtk_gpon_gtcDsIntrMask_get
 * Description:
 *      Get GTC DS Interrupt Mask state
 * Input:
 *       gtcIntrType: type of gtc interrupt type
 * Output:
 *      pState: point for get gtc interrupt  mask state
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_gtcDsIntrMask_get(rtk_gpon_gtcDsIntrType_t gtcIntrType,rtk_enable_t  *pState);

/* Function Name:
 *      rtk_gpon_gtcDsIntrMask_set
 * Description:
 *      Set GTC DS Interrupt Mask state
 * Input:
 *	   gtcIntrType: type of gtc interrupt type
 *       state: set gtc interrupt  mask state
 * Output:
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_gtcDsIntrMask_set(rtk_gpon_gtcDsIntrType_t gtcIntrType,rtk_enable_t  state);


/* Function Name:
 *      rtk_gpon_onuId_set
 * Description:
 *      Set GPON ONU ID
 * Input:
 *      onuId: value of ONUID
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_onuId_set(uint8 onuId);  

/* Function Name:
 *      rtk_gpon_onuId_set
 * Description:
 *      Set GPON ONU ID
 * Input:
 *      onuId: value of ONUID
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_onuId_get(uint8 *pOnuId);  

/* Function Name:
 *      rtk_gpon_onuState_set
 * Description:
 *      Set ONU State .
 * Input:
 *      onuState: onu state
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_onuState_set(rtk_gpon_onuState_t  onuState);

/* Function Name:
 *      rtk_gpon_onuState_get
 * Description:
 *      Get ONU State
 * Input:
 *
 * Output:
 *      pOnuState: point for get onu state
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_onuState_get(rtk_gpon_onuState_t  *pOnuState);

/* Function Name:
 *      rtk_gpon_dsBwmapCrcCheckState_set
 * Description:
 *      Set DS Bandwidth map CRC check enable 
 * Input:
 *      state: enable or disable DS Bandwidth map CRC check
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED     - Failed
 * Note:
 */
extern int32 rtk_gpon_dsBwmapCrcCheckState_set(rtk_enable_t state);

/* Function Name:
 *      rtk_gpon_dsBwmapCrcCheckState_get
 * Description:
 *      Get DS Bandwidth map CRC check enable 
 * Input:
 *
 * Output:
 *      pState: point for get enable or disable of DS Bandwidth map CRC check
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsBwmapCrcCheckState_get(rtk_enable_t *pState);

/* Added in GPON_MAC_SWIO_v1.1 */

/* Function Name:
 *      rtk_gpon_dsBwmapFilterOnuIdState_set
 * Description:
 *      Set DS bandwidth map filter oun state
 * Input:
 *      state: state of DS bandwidth map filter oun
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsBwmapFilterOnuIdState_set(rtk_enable_t state);


/* Function Name:
 *      rtk_gpon_dsBwmapFilterOnuIdState_get
 * Description:
 *      Get DS bandwidth map filter oun state
 * Input:
 *
 * Output:
 *      pState: point for get DS bandwidth map filter oun state
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
 extern int32 rtk_gpon_dsBwmapFilterOnuIdState_get(rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_dsPlendStrictMode_set
 * Description:
 *      Set DS Plen Strict Mode
 * Input:
 *      state: state of DS Plen Strict Mode
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsPlendStrictMode_set(rtk_enable_t state);

/* Function Name:
 *      rtk_gpon_dsPlendStrictMode_get
 * Description:
 *      Get DS Plen Strict Mode
 * Input:
 *
 * Output:
 *      pState: point of state
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsPlendStrictMode_get(rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_dsScrambleState_set
 * Description:
 *      Set DS scramble
 * Input:
 *      state: state of DS scramble
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsScrambleState_set(rtk_enable_t state);

/* Function Name:
 *      rtk_gpon_dsScrambleState_get
 * Description:
 *      Get DS scramble
 * Input:
 *    
 * Output:
 *        pState: state of DS scramble
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsScrambleState_get(rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_dsFecBypass_set
 * Description:
 *      Set DS FEC bypass
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsFecBypass_set(rtk_enable_t state);

/* Function Name:
 *      rtk_gpon_dsFecBypass_get
 * Description:
 *      Get DS FEC bypass
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsFecBypass_get(rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_dsFecThrd_set
 * Description:
 *      Set DS Fec threshhold
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsFecThrd_set(uint8 fecThrdValue);

/* Function Name:
 *      rtk_gpon_dsFecThrd_get
 * Description:
 *      Get DS Fec threshhold
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsFecThrd_get(uint8 *pFecThrdValue);

/* Function Name:
 *      rtk_gpon_extraSnTxTimes_set
 * Description:
 *      Set extra serial number tx times
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_extraSnTxTimes_set(uint8 exSnTxTimes);


/* Function Name:
 *      rtk_gpon_extraSnTxTimes_get
 * Description:
 *      Get extra serial number tx times
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_extraSnTxTimes_get(uint8 *pExSnTxTimes);

/* Function Name:
 *      rtk_gpon_topGemUsIntr_get
 * Description:
 *      Set DS PLOAM no message
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsPloamNomsg_set(uint8 ploamNoMsgValue);


/* Function Name:
 *      rtk_gpon_dsPloamNomsg_get
 * Description:
 *      Get DS PLOAM no message
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsPloamNomsg_get(uint8 *pPloamNoMsgValue);

/* Function Name:
 *      rtk_gpon_dsPloamOnuIdFilterState_set
 * Description:
 *      Set DS PLOAM ONU ID Filter state
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsPloamOnuIdFilterState_set(rtk_enable_t state);

/* Function Name:
 *      rtk_gpon_dsPloamOnuIdFilterState_get
 * Description:
 *      Get DS PLOAM ONUID Filter state
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsPloamOnuIdFilterState_get(rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_dsPloamBcAcceptState_set
 * Description:
 *      Set DS PLAOM Boardcast accept state
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsPloamBcAcceptState_set(rtk_enable_t state);

/* Function Name:
 *      rtk_gpon_dsPloamBcAcceptState_get
 * Description:
 *    Get DS PLAOM Boardcast accept state
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsPloamBcAcceptState_get(rtk_enable_t *pState);

/* Added in GPON_MAC_SWIO_v1.1 */


/* Function Name:
 *      rtk_gpon_dsPloamDropCrcState_set
 * Description:
 *      Set DS PLOAM Drop crc state
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsPloamDropCrcState_set(rtk_enable_t state);

/* Function Name:
 *      rtk_gpon_dsPloamDropCrcState_get
 * Description:
 *      Get DS PLOAM Drop crc state
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsPloamDropCrcState_get(rtk_enable_t *pState);




/* Function Name:
 *      rtk_gpon_cdrLosStatus_get
 * Description:
 *      Get CDR LOS status
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_cdrLosStatus_get(rtk_enable_t *pState);




/* Function Name:
 *      rtk_gpon_optLosStatus_get
 * Description:
 *      GET OPT LOS Status
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_optLosStatus_get(rtk_enable_t *pState);


/* Function Name:
 *      rtk_gpon_topGemUsIntr_get
 * Description:
 *      Set LOS configuration
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_losCfg_set(rtk_enable_t opten, int32 optpolar, rtk_enable_t cdren, int32 cdrpolar, rtk_enable_t filter);

/* Function Name:
 *      rtk_gpon_topGemUsIntr_get
 * Description:
 *      Get LOS configuration
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_losCfg_get(int32 *opten, int32 *optpolar, int32 *cdren, int32 *cdrpolar, int32 *filter);

/* Function Name:
 *      rtk_gpon_dsPloam_get
 * Description:
 *      Get DS PLOAM data
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsPloam_get(uint8 *pPloamData);

/* Function Name:
 *      rtk_gpon_usTcont_get
 * Description:
 *      Get Tcont allocate Id
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_usTcont_get(uint32 tcontId, uint32 *pAllocateId);

/* Function Name:
 *      rtk_gpon_usTcont_set
 * Description:
 *      Set TCONT allocate Id
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_usTcont_set(uint32 tcontId, uint32 allocateId);

/* Function Name:
 *      rtk_gpon_usTcont_del
 * Description:
 *      Delete TCONT
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_usTcont_del(uint32 tcontId);

/* Function Name:
 *      rtk_gpon_dsGemPort_get
 * Description:
 *      Get DS gem port configure
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPort_get(uint32 idx, rtk_gem_cfg_t *pGemCfg);

/* Function Name:
 *      rtk_gpon_dsGemPort_set
 * Description:
 *      Set DS gem port configure
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPort_set(uint32 idx, rtk_gem_cfg_t gemCfg);

/* Function Name:
 *      rtk_gpon_dsGemPort_del
 * Description:
 *      Delete DS Gem pot 
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPort_del(uint32 idx);

/* Function Name:
 *      rtk_gpon_dsGemPortPktCnt_get
 * Description:
 *      Get DS Gem port packet counter
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortPktCnt_get(uint32 idx, uint32 *pktCnt);


/* Function Name:
 *      rtk_gpon_dsGemPortByteCnt_get
 * Description:
 *      Get DS Gem port byte counter
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortByteCnt_get(uint32 idx, uint32 *byteCnt);


/* Function Name:
 *      rtk_gpon_dsGemPortByteCnt_get
 * Description:
 *      Get DS Gem port misc counter
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGtcMiscCnt_get(rtk_gpon_dsGtc_pmMiscType_t dsGtcPmMiscType, uint32 *miscCnt);


/* Function Name:
 *      rtk_gpon_dsOmciPti_set
 * Description:
 *      Set DS OMCI PTI value
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsOmciPti_set(uint32 mask, uint32 end);


/* Function Name:
 *      rtk_gpon_dsOmciPti_get
 * Description:
 *      Get DS OMCI PTI value
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsOmciPti_get(uint32 *pMask, uint32 *pEnd);



/* Function Name:
 *      rtk_gpon_dsEthPti_set
 * Description:
 *      Set DS Ethernet PTI value
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsEthPti_set(uint32 mask, uint32 end);

/* Function Name:
 *      rtk_gpon_dsEthPti_get
 * Description:
 *      Get DS Ethernet PTI value
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dsEthPti_get(uint32 *pMask, uint32 *pEnd);


/* Function Name:
 *      rtk_gpon_aesKeySwitch_set
 * Description:
 *      Set AES key switch value(superframe value)
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_aesKeySwitch_set(uint32 superframe);



/* Function Name:
 *      rtk_gpon_aesKeySwitch_get
 * Description:
 *      Get AES key switch value(superframe value)
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_aesKeySwitch_get(uint32 *pSuperframe);


/* Function Name:
 *      rtk_gpon_aesKeyWord_set
 * Description:
 *      Set AES keyword value
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_aesKeyWord_set(uint32 *keyword);


/* Function Name:
 *      rtk_gpon_irq_get
 * Description:
 *      Get global irq status
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_irq_get(rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_dsGemPortEthRxCnt_get
 * Description:
 *      Get DS Gemport Ethernet RX counter
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortEthRxCnt_get(uint32 idx,uint32 *pEthRxCnt);


/* Function Name:
 *      rtk_gpon_dsGemPortEthFwdCnt_get
 * Description:
 *      Get GPON DS Gemport Ethernet Forward counter
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortEthFwdCnt_get(uint32 idx,uint32 *pEthFwdCnt);


/* Function Name:
 *      rtk_gpon_dsGemPortMiscCnt_get
 * Description:
 *      Get GPON DS Gemport MISC counter
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortMiscCnt_get(rtk_gpon_dsGem_pmMiscType_t idx,uint32 *pMiscCnt);


/* Function Name:
 *      rtk_gpon_dsGemPortFcsCheckState_get
 * Description:
 *      Get GPON DS Gemport FCS check state
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortFcsCheckState_get(rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_dsGemPortFcsCheckState_set
 * Description:
 *      Get GPON DS Gemport FCS check state
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortFcsCheckState_set(rtk_enable_t state);


/* Function Name:
 *      rtk_gpon_dsGemPortBcPassState_set
 * Description:
 *      Set GPON DS Gemport Boardcast pass state
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortBcPassState_set(rtk_enable_t state);

/* Function Name:
 *      rtk_gpon_dsGemPortBcPassState_get
 * Description:
 *      Get GPON DS Gemport Boardcast pass state
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortBcPassState_get(rtk_enable_t *pState);


/* Function Name:
 *      rtk_gpon_dsGemPortNonMcPassState_set
 * Description:
 *      Set GPON DS Gemport None Multicast pass state
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortNonMcPassState_set(rtk_enable_t state);

/* Function Name:
 *      rtk_gpon_dsGemPortNonMcPassState_get
 * Description:
 *      Get GPON DS Gemport None Multicast pass state
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortNonMcPassState_get(rtk_enable_t *pState);


/* Function Name:
 *      rtk_gpon_dsGemPortMacFilterMode_set
 * Description:
 *      Set GPON DS Gemport MAC filter mode 
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortMacFilterMode_set(rtk_gpon_macTable_exclude_mode_t macFilterMode);

/* Function Name:
 *      rtk_gpon_dsGemPortMacFilterMode_get
 * Description:
 *      Get GPON DS Gemport MAC filter mode 
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortMacFilterMode_get(rtk_gpon_macTable_exclude_mode_t *pMacFilterMode);

/* Function Name:
 *      rtk_gpon_dsGemPortMacForceMode_set
 * Description:
 *      Set GPON DS Gemport MAC force mode 
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortMacForceMode_set(rtk_gpon_ipVer_t ipVer,rtk_gpon_mc_force_mode_t macForceMode);

/* Function Name:
 *      rtk_gpon_dsGemPortMacForceMode_get
 * Description:
 *      Get GPON DS Gemport MAC force mode 
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortMacForceMode_get(rtk_gpon_ipVer_t ipVer,rtk_gpon_mc_force_mode_t *pMacForceMode);


/* Function Name:
 *      rtk_gpon_dsGemPortMacEntry_set
 * Description:
 *      Set GPON DS Gemport MAC filter MAC entry
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortMacEntry_set(uint32 idx, rtk_mac_t mac);


/* Function Name:
 *      rtk_gpon_dsGemPortMacEntry_get
 * Description:
 *     Get GPON DS Gemport MAC filter MAC entry
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortMacEntry_get(uint32 idx, rtk_mac_t *pMac);


/* Function Name:
 *      rtk_gpon_dsGemPortMacEntry_del
 * Description:
 *     Delete GPON DS Gemport MAC filter MAC entry
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortMacEntry_del(uint32 idx);



/* Function Name:
 *      rtk_gpon_dsGemPortFrameTimeOut_set
 * Description:
 *      Set GPON DS Gemport Frame Time out value
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortFrameTimeOut_set(uint32 timeOutValue);


/* Function Name:
 *      rtk_gpon_dsGemPortFrameTimeOut_get
 * Description:
 *      Get GPON DS Gemport Frame Time out value
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_dsGemPortFrameTimeOut_get(uint32 *pTimeOutValue);


/* Function Name:
 *      rtk_gpon_ipv6McAddrPtn_get
 * Description:
 *      Get GPON IPv6 MC address prefix
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
*/

extern int32 rtk_gpon_ipv4McAddrPtn_get(uint32 *pPrefix);


/* Function Name:
 *      rtk_gpon_ipv6McAddrPtn_set
 * Description:
 *      Set GPON IPv6 MC address prefix
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
*/

extern int32 rtk_gpon_ipv4McAddrPtn_set(uint32 prefix);

/* Function Name:
 *      rtk_gpon_ipv6McAddrPtn_get
 * Description:
 *      Get GPON IPv6 MC address prefix
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
*/

extern int32 rtk_gpon_ipv6McAddrPtn_get(uint32 *pPrefix);


/* Function Name:
 *      rtk_gpon_ipv6McAddrPtn_set
 * Description:
 *      Set GPON IPv6 MC address prefix
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
*/

extern int32 rtk_gpon_ipv6McAddrPtn_set(uint32 prefix);


/* page 0x05 */

/* Function Name:
 *      rtk_gpon_gtcUsIntr_get
 * Description:
 *      Get US GTC interrupt state
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_gtcUsIntr_get(rtk_gpon_gtcUsIntrType_t gtcUsIntrType,rtk_enable_t *pState);


/* Function Name:
 *      rtk_gpon_gtcUsIntrDlt_get
 * Description:
 *      Get US GTC interrupt status state
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_gtcUsIntrDlt_get(rtk_gpon_gtcUsIntrType_t gtcUsIntrType,rtk_enable_t *pState);


/* Function Name:
 *      rtk_gpon_gtcUsIntrMask_get
 * Description:
 *      Get US GTC Interrupt mask
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_gtcUsIntrMask_get(rtk_gpon_gtcUsIntrType_t gtcUsIntrType,rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_gtcUsIntrMask_set
 * Description:
 *      Set US Interrupt mask 
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32  rtk_gpon_gtcUsIntrMask_set(rtk_gpon_gtcUsIntrType_t gtcUsIntrType,rtk_enable_t state);


/* Function Name:
 *      rtk_gpon_forceLaser_set
 * Description:
 *      Set Force Laser status
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32  rtk_gpon_forceLaser_set(rtk_gpon_laser_status_t laserStatus);

/* Function Name:
 *      rtk_gpon_forceLaser_get
 * Description:
 *      Get Force Laser status
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_forceLaser_get(rtk_gpon_laser_status_t *plaserStatus);

/* Function Name:
 *      rtk_gpon_ploamState_set
 * Description:
 *      Set PLOAM state 
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32  rtk_gpon_ploamState_set(rtk_enable_t state);

/* Function Name:
 *      rtk_gpon_ploamState_get
 * Description:
 *      Get PLOAM State
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_ploamState_get(rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_indNrmPloamState_set
 * Description:
 *      Set Ind normal PLOAM state
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32  rtk_gpon_indNrmPloamState_set(rtk_enable_t state);

/* Function Name:
 *      rtk_gpon_indNrmPloamState_get
 * Description:
 *     Get Ind normal PLOAM state
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_indNrmPloamState_get(rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_dbruState_set
 * Description:
 *      Set DBRu state
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32  rtk_gpon_dbruState_set(rtk_enable_t state);

/* Function Name:
 *      rtk_gpon_dbruState_get
 * Description:
 *       Get DBRu state
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_dbruState_get(rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_topGemUsIntr_get
 * Description:
 *      Set US scramble state
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32  rtk_gpon_usScrambleState_set(rtk_enable_t state);;

/* Function Name:
 *      rtk_gpon_topGemUsIntr_get
 * Description:
 *      Get US scramble state
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_usScrambleState_get(rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_usBurstPolarity_set
 * Description:
 *      Set US burst polarity value
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32  rtk_gpon_usBurstPolarity_set(rtk_gpon_polarity_t polarityValue);

/* Function Name:
 *      rtk_gpon_usBurstPolarity_get
 * Description:
 *      Get US burst polarity value
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_usBurstPolarity_get(rtk_gpon_polarity_t *pPolarityValue);

/* Function Name:
 *      rtk_gpon_eqd_set
 * Description:
 *      Set Eqd value
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32  rtk_gpon_eqd_set(uint32 value,int32 offset);

/* Function Name:
 *      rtk_gpon_laserTime_set
 * Description:
 *      Set laserTime value
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32  rtk_gpon_laserTime_set(uint8 on, uint8 off);

/* Function Name:
 *      rtk_gpon_laserTime_get
 * Description:
 *      Get laser Time value
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_laserTime_get(uint8 *on, uint8 *off);

/* Function Name:
 *      rtk_gpon_burstOverhead_set
 * Description:
 *      Set BOH value
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32  rtk_gpon_burstOverhead_set(uint8 rep, uint8 len, uint8 size, uint8 *oh);

/* Function Name:
 *      rtk_gpon_usPloam_set
 * Description:
 *      Set US PLOAM
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_usPloam_set(rtk_enable_t isUrgent, uint8 *ploamValue);

/* Function Name:
 *      rtk_gpon_usAutoPloam_set
 * Description:
 *      Set US auto ploam
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32  rtk_gpon_usAutoPloam_set(rtk_gpon_usAutoPloamType_t usAutoPloamType, uint8 *ploamValue);

/* Function Name:
 *      rtk_gpon_usPloamCrcGenState_set
 * Description:
 *      Set us PLOAM CRC  State
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32  rtk_gpon_usPloamCrcGenState_set(rtk_enable_t state);

/* Function Name:
 *      rtk_gpon_topGemUsIntr_get
 * Description:
 *     Get us PLOAM CRC state
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_usPloamCrcGenState_get(rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_usPloamOnuIdFilterState_set
 * Description:
 *      Set US PLOAM ONUID Filter State 
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32  rtk_gpon_usPloamOnuIdFilterState_set(rtk_enable_t state);

/* Function Name:
 *      rtk_gpon_usPloamOnuIdFilter_get
 * Description:
 *      Get US PLOAM ONUID Filter state 
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_usPloamOnuIdFilter_get(rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_usPloamBuf_flush
 * Description:
 *      Flush us PLOAM buffer
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32  rtk_gpon_usPloamBuf_flush(void);



/* Function Name:
 *      rtk_gpon_usGtcMiscCnt_get
 * Description:
 *      Get US GTC Misc conuter
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_usGtcMiscCnt_get(rtk_gpon_usGtc_pmMiscType_t pmMiscType, uint32 *pValue);

/* Function Name:
 *      rtk_gpon_rdi_set
 * Description:
 *      Set RDI vlaue
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32  rtk_gpon_rdi_set(int32 value);

/* Function Name:
 *      rtk_gpon_rdi_get
 * Description:
 *      Get RDI value
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_rdi_get(int32 *value);

/* Function Name:
 *      rtk_gpon_topGemUsIntr_get
 * Description:
 *      Set US smals start proc state 
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32  rtk_gpon_usSmalSstartProcState_set(rtk_enable_t state);

/* Function Name:
 *      rtk_gpon_usSmalSstartProcState_get
 * Description:
 *      Get US smals start proc state 
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_usSmalSstartProcState_get(rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_usSuppressLaserState_set
 * Description:
 *      Set US supper press laser state 
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32  rtk_gpon_usSuppressLaserState_set(rtk_enable_t state);

/* Function Name:
 *      rtk_gpon_usSuppressLaserState_get
 * Description:
 *      Get US supper press laser state 
 * Input:
 *
 * Output:
 *      
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_usSuppressLaserState_get(rtk_enable_t *pState);


/* page 0x06 */
/* Function Name:
 *      rtk_gpon_gemUsIntr_get
 * Description:
 *      Get US GEM interrupt state
 * Input:
 *      reg_addr 	- void
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_gemUsIntr_get(rtk_gpon_gemUsIntrType_t gemUsIntrType,rtk_enable_t *pState);


/* Function Name:
 *      rtk_gpon_gemUsIntrMask_get
 * Description:
 *      Get US GEM interrutp mask state
 * Input:
 *      None
 * Output:
 *      pValue              - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_gemUsIntrMask_get(rtk_gpon_gemUsIntrType_t gemUsIntrType,rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_gemUsIntrMask_set
 * Description:
 *      Set US GEM interrutp mask state
 * Input:
 *      value       - interrupt mask value
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 *      RT_ERR_OUT_OF_RANGE - input parameter out of range
 * Note:
 */
extern int32 rtk_gpon_gemUsIntrMask_set(rtk_gpon_gemUsIntrType_t gemUsIntrType,rtk_enable_t state);



/* Function Name:
 *      rtk_gpon_gemUsForceIdleState_set
 * Description:
 *      Turn on/off force to send IDLE GEM only.
 * Input:
 *      value       - on/off value
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 *      RT_ERR_OUT_OF_RANGE - input parameter out of range
 * Note:
 */
extern int32 rtk_gpon_gemUsForceIdleState_set(rtk_enable_t state);

/* Function Name:
 *      rtk_gpon_gemUsForceIdleState_get
 * Description:
 *      Read the setting of force IDLE GEM.
 * Input:
 *      None
 * Output:
 *      pValue      - return value of status
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_gemUsForceIdleState_get(rtk_enable_t *pState);

/* Function Name:
 *      rtk_gpon_gemUsPtiVector_set
 * Description:
 *      Set the PTI value vector mapping base on (OMCI,END_FRAG).
 * Input:
 *      pti_v0       - the PTI value base on (OMCI,END_FRAG)=(0,0)
 *      pti_v1       - the PTI value  base on (OMCI,END_FRAG)=(0,1)
 *      pti_v2       - the PTI value  base on (OMCI,END_FRAG)=(1,0)
 *      pti_v3       - the PTI value  base on (OMCI,END_FRAG)=(1,1)
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 *      RT_ERR_OUT_OF_RANGE - input parameter out of range
 * Note:
 */
extern int32 rtk_gpon_gemUsPtiVector_set(uint8 pti_v0, uint8 pti_v1, uint8 pti_v2, uint8 pti_v3);

/* Function Name:
 *      rtk_gpon_gemUsPtiVector_get
 * Description:
 *      Read the setting of force IDLE GEM.
 * Input:
 *      None
 * Output:
 *      pPti_v0             - the PTI vector 0
 *      pPti_v1             - the PTI vector 1
 *      pPti_v2             - the PTI vector 2
 *      pPti_v3             - the PTI vector 3
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_gemUsPtiVector_get(uint8 *pPti_v0, uint8 *pPti_v1, uint8 *pPti_v2, uint8 *pPti_v3);


/* Function Name:
 *      rtk_gpon_gemUsEthCnt_get
 * Description:
 *      Read the ether counter for local port.
 * Input:
 *      local_idx           - local port index
 * Output:
 *      pEth_cntr           - counter value
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 *      RT_ERR_OUT_OF_RANGE - input parameter out of range
 *      RT_ERR_NULL_POINTER - input parameter is null pointer
 * Note:
 */
extern int32 rtk_gpon_gemUsEthCnt_get(uint32 idx, uint32 *pEthCntr);

/* Function Name:
 *      rtk_gpon_gemUsGemCnt_read
 * Description:
 *      Read the ether counter for local port.
 * Input:
 *      local_idx           - local port index
 * Output:
 *      pGem_cntr           - counter value
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 *      RT_ERR_OUT_OF_RANGE - input parameter out of range
 *      RT_ERR_NULL_POINTER - input parameter is null pointer
 * Note:
 */
extern int32 rtk_gpon_gemUsGemCnt_get(uint32 idx, uint32 *pGemCntr);

/* Function Name:
 *      rtk_gpon_gemUsPortCfg_set
 * Description:
 *      Set the mapping of local_idx and gem_port_id.
 * Input:
 *      cycle       - specify the cycle value
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK           - OK
 *      Others              - Failed
 * Note:
 */
extern int32 rtk_gpon_gemUsPortCfg_set(uint32 idx, uint32 gemPortId);

/* Function Name:
 *      rtk_gpon_gemUsPortCfg_get
 * Description:
 *      Read the mapping of local_idx and gem_port_id.
 * Input:
 *      None
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 *      RT_ERR_OUT_OF_RANGE - input parameter out of range
 *      RT_ERR_NULL_POINTER - input parameter is null pointer
 * Note:
 */
extern int32 rtk_gpon_gemUsPortCfg_get(uint32 idx, uint32 *pGemPortId);

/* Function Name:
 *      rtk_gpon_gemUsDataByteCnt_get
 * Description:
 *      Read the data byte counter for local port.
 * Input:
 *      local_idx           - local port index
 * Output:
 *      pByte_cntr          - counter value
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 *      RT_ERR_OUT_OF_RANGE - input parameter out of range
 *      RT_ERR_NULL_POINTER - input parameter is null pointer
 * Note:
 */
extern int32 rtk_gpon_gemUsDataByteCnt_get(uint32 idx, uint64 *pByteCntr);

/* Function Name:
 *      rtk_gpon_gemUsIdleByteCnt_read
 * Description:
 *      Read the IDLE byte counter for TCONT.
 * Input:
 *      local_idx           - local TCONT index
 * Output:
 *      pIdle_cntr          - counter value
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 *      RT_ERR_OUT_OF_RANGE - input parameter out of range
 *      RT_ERR_NULL_POINTER - input parameter is null pointer
 * Note:
 */
extern int32 rtk_gpon_gemUsIdleByteCnt_get(uint32 idx, uint64 *pIdleCntr);


/* Function Name:
 *      rtk_gpon_dbruPeriod_set
 * Description:
 *      Read the data byte counter for local port.
 * Input:
 *      periodTime           - dbru period time
 * Output:
 *      None         
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 *      RT_ERR_OUT_OF_RANGE - input parameter out of range
 *      RT_ERR_NULL_POINTER - input parameter is null pointer
 * Note:
 */
extern int32 rtk_gpon_dbruPeriod_set(uint32 periodTime);

/* Function Name:
 *      dal_apollomp_gpon_dbruPeriod_get
 * Description:
 *      Read the data byte counter for local port.
 * Input:
 *      None
 * Output:
 *      *pPeriodTime		- point of period time
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 *      RT_ERR_OUT_OF_RANGE - input parameter out of range
 *      RT_ERR_NULL_POINTER - input parameter is null pointer
 * Note:
 */
extern int32 rtk_gpon_dbruPeriod_get(uint32 *pPeriodTime);



/* Function Name:
 *      rtk_gpon_portMacForceMode_set
 * Description:
 *      Set MAC focre mode for PON port
 * Input:
 *       None
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_portMacForceMode_set(rtk_port_linkStatus_t linkStatus);


/* Function Name:
 *      rtk_gpon_port_get
 * Description:
 *      Get GPON port id
 * Input:
 *       None
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_port_get(rtk_port_t *ponPort);


/* Function Name:
 *      rtk_gpon_gtcDsIntrDlt_check
 * Description:
 *      Check GTC DS interrupt
 * Input:
 *	   gtcIntrType: type of gtc interrupt type
 * Output:
 *      pState: point for get gtc interrupt  state
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_gtcDsIntrDlt_check(rtk_gpon_gtcDsIntrType_t gtcDsIntrType,uint32 gtcDsIntrDltValue,rtk_enable_t *pState);


/* Function Name:
 *      rtk_gpon_gtcUsIntrDlt_check
 * Description:
 *      Check GTC US interrupt
 * Input:
 *	   gtcIntrType: type of gtc interrupt type
 * Output:
 *      pState: point for get gtc interrupt  state
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_gtcUsIntrDlt_check(rtk_gpon_gtcUsIntrType_t gtcUsIntrType,uint32 gtcUsIntrDltValue,rtk_enable_t *pState);


/* Function Name:
 *      rtk_gpon_gemUsIntrDlt_check
 * Description:
 *      Check GTC DS interrupt
 * Input:
 *	   gtcIntrType: type of gtc interrupt type
 * Output:
 *      pState: point for get gtc interrupt  state
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_gemUsIntrDlt_check(rtk_gpon_gemUsIntrType_t gemIntrType,uint32 gemUsIntrDltValue,rtk_enable_t *pState);


/* Function Name:
 *      rtk_gpon_rogueOnt_set
 * Description:
 *      Config Rogue ONT 
 * Input:
 *	   rogOntState - enable or disable rogue ont 
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_rogueOnt_set(rtk_enable_t rogOntState);


/* Function Name:
 *      rtk_gpon_drainOutDefaultQueue_set
 * Description:
 *      Drain Out GPON default Queue
 * Input:
 *	   rogOntState - enable or disable rogue ont 
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_drainOutDefaultQueue_set(void);


/* Function Name:
 *      rtk_gpon_autoDisTx_set
 * Description:
 *      nable or Disable auto disable Tx function
 * Input:
 *	   autoDisTxState - enable or disable rogue ont 
 * Output:
 *      None
 * Return:
 *      RT_ERR_OK           - OK
 *      RT_ERR_FAILED       - Failed
 * Note:
 */
extern int32 rtk_gpon_autoDisTx_set(rtk_enable_t autoDisTxState);


#endif /*#ifndef _GPON_V2_H_*/
