/* 
 * Copyright (c) 2011 Qualcomm Atheros, Inc.. 
 * All Rights Reserved. 
 * Qualcomm Atheros Confidential and Proprietary. 
 *
 *
 * Header Name: opconn_usr_ioctl.h
 *
 *
 * Revision History:
 * Author        Date         Description of Changes
 * ---------   ------------  -------------------------
 * wfxu        2012/04/1      Initial Version	
 * ---------   ------------  -------------------------
 */


#ifndef __OPCONN_USR_IOCTL__
#define __OPCONN_USR_IOCTL__

#ifndef INOUT
#define IN      /* consider as comments near 'input' parameters */
#define OUT     /* consider as comments near 'output' parameters */
#define INOUT   /* consider as comments near 'input/output' parameters */
#endif

/* Definition */


/* macro definition*/

#define MAX_LASER_ON_TIME 		(0XFFFF)
#define MAX_LASER_OFF_TIME 		(0XFFFF)
#define MAX_SERDES_DELAY_TIME	(0XFF)

#define CLASSIFY_MAX_FIELD                   	32
#define CLASSIFY_MAX_ITEM_NUM			128
#define CLT_CLASSIFY_MAX_DSCP			64

/*classify start*/

/*from hw interface*/

#define TAB_CLS_MASK_LEN    					24
#define TAB_CLS_ADDR_LEN 	  					128	
#define TAB_CLS_RULE_LEN 	  					128
#define TAB_CLS_COUNTER_LEN				128
#define TAB_BRG_VTT_LEN  						16
#define TAB_PON_MAC_LEN						64

#define TAB_US_SHPBD_LEN						16 //respin
#define TAB_US_SHPBD_PIR_START						8
#define TAB_DS_SHPBD_LEN						9

#define TAB_US_WRED_LEN						8
#define TAB_DS_WRED_LEN						8

#define TAB_Q_CONF_STA_LEN					16
#define TAB_DMA0_RX_LEN						64
#define TAB_DMA0_TX_LEN						64
#define TAB_DMA1_RX_LEN						64
#define TAB_DMA1_TX_LEN						64

/*	all table records width 	*/
#define TAB_CLS_MASK_WIDTH    				7
#define TAB_CLS_ADDR_WIDTH	  				1
#define TAB_CLS_RULE_WIDTH   				8/*27*//*28*/
#define TAB_CLS_COUNTER_WIDTH			1
#define TAB_BRG_VTT_WIDTH 					1	
#define TAB_PON_MAC_WIDTH					2/*7*//*8*/
#define TAB_US_SHPBD_WIDTH					1
#define TAB_DS_SHPBD_WIDTH					1

#define TAB_US_WRED_WIDTH					2
#define TAB_DS_WRED_WIDTH					2

#define TAB_Q_CONF_STA_WIDTH				2
#define TAB_DMA0_RX_WIDTH					1
#define TAB_DMA0_TX_WIDTH					1
#define TAB_DMA1_RX_WIDTH					1
#define TAB_DMA1_TX_WIDTH					1

#define TAB_MAX_WIDTH							(10)

/*end from hw interface*/
#define ONLY_SUPPORT_SINGLE_TAG    1

#define CLASSIFY_ADDRESS_LENGTH        	 	0X7F
#define CLASSIFY_RULE_PUCKER_LEN       		12	 /*pucker 64 bytes rule into 16 bytes by XOR.*/
#define CLASSIFY_CAL_VALUE_LEN         	 	16
#define CLASSIFY_MAX_RULE_ENTRY          	TAB_CLS_RULE_LEN
#define CLASSIFY_MIN_MASK_ENTRY          	8
#define CLASSIFY_MAX_MASK_ENTRY          	TAB_CLS_MASK_LEN
#define CLASSIFY_MAX_ADDR_ENTRY          	TAB_CLS_ADDR_LEN
#define CLASSIFY_PACKET_HEADER_LEN       80  /*the first 80 bytes of the packet*/

#define CLASSIFY_6OFFSET_LENGTH          24  /*24Bytes,Total length of the six offset length*/
#define CLASSIFY_5OFFSET_LENGTH          20  /*20Bytes,Total length of the five offset length*/
#define CLASSIFY_4OFFSET_LENGTH          16  /*16Bytes,Total length of the four offset length*/
#define CLASSIFY_3OFFSET_LENGTH          12  /*12Bytes,Total length of the three offset length*/
#define CLASSIFY_2OFFSET_LENGTH          8   /*8Bytes,Total length of the two offset length*/
#define CLASSIFY_1OFFSET_LENGTH          4   /*4Bytes,Total length of the one offset length*/

#define CLASSIFY_KEYVALUE_LENGTH     	CLASSIFY_6OFFSET_LENGTH

#define CLASSIFY_RULE_TABLE_GROUP    	4 /*opconn only support 2 group*/ 
#define CLASSIFY_OFFSET_MAX_STEP_VALUE	 12
#define CLASSIFY_OFFSET_LEN		 		 	4
#define CLASSIFY_ENTRYS_PER_GROUP    32
#define CLASSIFY_FIELD_MS_BIT            	0x80000000  /*Most significant bit of the field map*/

#define CLASSIFY_MSEL_SET_FLAG           1
#define CLASSIFY_MSEL_CLR_FLAG           2

#define CLASSIFY_LOCAL_TBL               		1
#define CLASSIFY_HW_TBL                  		2
#define CLASSIFY_OFFSET_NUM            		CLASSIFY_FOFFSET_6

#define CLASSIFY_TRAN_ACTION_COPY		 			OPL_REG_BIT0
#define CLASSIFY_TRAN_ACTION_DROP		 			OPL_REG_BIT1
#define CLASSIFY_TRAN_ACTION_REDIRECTUNI 		OPL_REG_BIT2
#define CLASSIFY_TRAN_ACTION_REDIRECTALL 		OPL_REG_BIT3
#define CLASSIFY_TRAN_ACTION_MIRROR		 		OPL_REG_BIT4
#define CLASSIFY_TRAN_ACTION_NOTCOPY	 			OPL_REG_BIT5
#define CLASSIFY_TRAN_ACTION_NOTDROP	 			OPL_REG_BIT6

#define CLASSIFY_OPTRAN_ACTION_NOTCOPY	 		OPL_REG_BIT2
#define CLASSIFY_OPTRAN_ACTION_NOTDROP	 		OPL_REG_BIT3

#define CLASSIFY_RMK_ACTION_SET_DEI		 		 	OPL_REG_BIT0
#define CLASSIFY_RMK_ACTION_CHANGE_IDEI	 	OPL_REG_BIT1
#define CLASSIFY_RMK_ACTION_CHANGE_V4TOS		OPL_REG_BIT2
#define CLASSIFY_RMK_ACTION_CHANGE_V6TOS 	OPL_REG_BIT3
#define CLASSIFY_RMK_ACTION_CHANGE_ICOS  		OPL_REG_BIT4
#define CLASSIFY_RMK_ACTION_CHANGE_SCOS  		OPL_REG_BIT5
#define CLASSIFY_RMK_ACTION_CHANGE_CCOS  	OPL_REG_BIT6
#define CLASSIFY_RMK_ACTION_CHANGE_CVID  		OPL_REG_BIT7
#define CLASSIFY_RMK_ACTION_CHANGE_SVID  		OPL_REG_BIT8

#define CLASSIFY_RMK_IDEI_FROM_RULE      			0
#define CLASSIFY_RMK_IDEI_FROM_SCOS      			OPL_REG_BIT0
#define CLASSIFY_RMK_IDEI_FROM_V4DSCP    		OPL_REG_BIT1
#define CLASSIFY_RMK_IDEI_FROM_V6DSCP    		((OPL_REG_BIT0) | (OPL_REG_BIT1))

#define CLASSIFY_RMK_TOS_FROM_RULE       			0
#define CLASSIFY_RMK_TOS_FROM_SCOS       			OPL_REG_BIT0
#define CLASSIFY_RMK_TOS_FROM_CCOS       			OPL_REG_BIT1

#define CLASSIFY_RMK_ICOS_FROM_RULE      			0
#define CLASSIFY_RMK_ICOS_FROM_SCOS      			OPL_REG_BIT0
#define CLASSIFY_RMK_ICOS_FROM_V4DSCP    		OPL_REG_BIT1
#define CLASSIFY_RMK_ICOS_FROM_V6DSCP    		((OPL_REG_BIT0) | (OPL_REG_BIT1))

#define CLASSIFY_RMK_SCOS_FROM_RULE      			0
#define CLASSIFY_RMK_SCOS_FROM_CCOS      			OPL_REG_BIT0
#define CLASSIFY_RMK_SCOS_FROM_V4TOS     		OPL_REG_BIT1
#define CLASSIFY_RMK_SCOS_FROM_V6TOS     		((OPL_REG_BIT0) | (OPL_REG_BIT1))

#define CLASSIFY_RMK_CCOS_FROM_RULE      			0
#define CLASSIFY_RMK_CCOS_FROM_SCOS      			OPL_REG_BIT0
#define CLASSIFY_RMK_CCOS_FROM_V4TOS     		OPL_REG_BIT1
#define CLASSIFY_RMK_CCOS_FROM_V6TOS     		((OPL_REG_BIT0) | (OPL_REG_BIT1))

enum
{
	CLASSIFY_FOFFSET_1 = 1,
	CLASSIFY_FOFFSET_2,
	CLASSIFY_FOFFSET_3,
	CLASSIFY_FOFFSET_4,
	CLASSIFY_FOFFSET_5,
	CLASSIFY_FOFFSET_6
};


enum
{
	CLASSIFY_FOFFSET_VALUE_0,
	CLASSIFY_FOFFSET_VALUE_1,
	CLASSIFY_FOFFSET_VALUE_2,
	CLASSIFY_FOFFSET_VALUE_3,
	CLASSIFY_FOFFSET_VALUE_4,
	CLASSIFY_FOFFSET_VALUE_5,
	CLASSIFY_FOFFSET_VALUE_6,
	CLASSIFY_FOFFSET_VALUE_7,
	CLASSIFY_FOFFSET_VALUE_8,
	CLASSIFY_FOFFSET_VALUE_9,
	CLASSIFY_FOFFSET_VALUE_10,
	CLASSIFY_FOFFSET_VALUE_11,
};

enum
{
	OFFSET_FIND_MATCH_STARTBIT = 1,
	OFFSET_FIND_CLOSEST_STARTBIT,
	OFFSET_FIND_NONE,
};

enum
{
	OFFSET_WINDOWS_SEARCH_LOOP_1 = 1,
	OFFSET_WINDOWS_SEARCH_LOOP_2
};

enum                      /* Dest field */
{
	SET_DEI,
	CHANGE_IDEI,
	CHANGE_V4TOS,
	CHANGE_V6TOS,
	CHANGE_ICOS,
	CHANGE_SCOS,
	CHANGE_CCOS,
	CHANGE_CVID,
	CHANGE_SVID,
};

enum					 /* Src field */
{
	RULE_IDEI = 1,
	V4TOS,
	V6TOS,
	RULE_ICOS,
	SCOS,
	CCOS,
	RULE_SCOS,
	RULE_CCOS,
	RULE_TOS,
	V4DSCP,
	V6DSCP,	
};


/*classify end*/

#define MULTCAST_CLS_STARTID 		96
#define MAX_GROUP_NUM 					32

/* Begin Modified */
#if 0
#define MC_MAX_GROUP_NUM 					64
#else
#define MC_MAX_GROUP_NUM  ((ODM_NUM_OF_PORTS)*(ODM_MAX_GRUP_NUM_PER_PORT))
#endif
/* End   Modified of porting */


#define DAL_VTT_REC_INVALID				        (0)
#define DAL_VTT_REC_VALID					    (1)
#define DAL_VTT_FULL							(-100)

#define DAL_VTT_PORT_DEFAULT				    (0)   
#define DAL_VTT_PON_PORT_STRIP			        (1)
#define DAL_VTT_GE_PORT_STRIP			        (1)

#define DAL_TAG_STRIP_EN						(1)
#define DAL_TAG_STRIP_DIS						(0)
#define DAL_VTT_LOOKUPFAIL_BY_PASS		        (1)
#define DAL_VTT_LOOKUPFAIL_DROP				    (0)

#define DAL_PORT_DEFAULT_PVID					(1)

#define DAL_PORT_PVID_VTT_ENTRY_START_NUM       (11)
#define DAL_PORT_PVID_VTT_ENTRY_NUM             (1)

#define DAL_PORT_VTT_ENTRY_START_NUM            (0)
#define DAL_PORT_VTT_ENTRY_NUM                  (11)

#define DAL_PORT_MCAST_ENTRY_START_NUM          (12)
#define DAL_PORT_MCAST_ENTRY_NUM                (4)

#pragma pack(1)		/* pragma pack definition */


/* pon module struct */
typedef struct DAL_PON_STATUS_s{
    UINT32 bfGatePendingNum:5;
	UINT32 bfRsved0:8;
	UINT32 bfDiscLEvent:4;
	UINT32 bfDiscCEvent:4;
	UINT32 bfDiscLState:4;
	UINT32 bfDiscCState:4;
}DAL_PON_STATUS_t;

/* classify module struct */
enum
{
	CLASSIFY_NO_TAG 		= OPL_ZERO,
	CLASSIFY_ONE_TAG 	= 1,
	CLASSIFY_TWO_TAG
};

enum 
{
    CLASSIFY_PPPOE_IP   = 1,
    CLASSIFY_EII_IP,    
};

enum 
{
	CLASSIFY_DAL_TABLE,
	CLASSIFY_ASIC_TABLE,
	CLASSIFY_DAL_AND_ASIC_TABLE
};

enum 
{
    /*L2 address information for all type packet*/
    CLASSIFY_DESTINATIONMAC =0,   /*6Bytes*/
    CLASSIFY_SOURCEMAC,           /*6Bytes*/


    /*Tag information for single or double tag packet*/
    CLASSIFY_FIRST_TPID,       /*2Bytes*/
    CLASSIFY_FIRST_COS,        /*4Bits*/
    CLASSIFY_FIRST_VLAN,       /*12Bits*/
    #ifdef ONLY_SUPPORT_SINGLE_TAG	
    #else
    CLASSIFY_SECOND_TPID,      /*2Byts*/
    CLASSIFY_SECOND_COS,       /*4Bits  surpport Q-in-Q mode*/
    CLASSIFY_SECOND_VLAN,      /*12Bits surpport Q-in-Q mode*/
    #endif
    /*length or type field accord with ETHERNETII or 802.3 packet type*/
    CLASSIFY_TYPE_LENGTH,      /*2Bytes  This is the type or lenth field in the L2 head*/

    /*Below define IP head field*/
    CLASSIFY_VERSION,          /*4Bits*/
    /*CLASSIFY_HEAD_LENGTH,      4Bits*/
    CLASSIFY_TOS,              /*1Bytes*/
    /*CLASSIFY_PKT_LENGTH,       2Bytes*/
    /*CLASSIFY_IDENTIFIER,       2Bytes*/
    /*CLASSIFY_FLAG,             3Bits*/
    /*CLASSIFY_SLICE_OFF,        13Bits*/
    /*CLASSIFY_TTL,              1Bytes*/ 
    CLASSIFY_PRO_TYPE,         /*1Bytes This is protocol type field in the IP head*/
    /*CLASSIFY_CHECKSUM,         2Bytes */
    CLASSIFY_SOURCE_IP,        /*4Bytes*/
    CLASSIFY_DESTINATION_IP,   /*4Bytes*/ 

    /*layer4 port number*/
    CLASSIFY_SOURCE_PORT,      /*2Bytes L4 port*/
    CLASSIFY_DESTINATION_PORT, /*2Bytes L4 port*/

    /*other field define for user specify function*/
    CLASSIFY_USER_FIELD1,
    CLASSIFY_LAST_NULL_FIELD
};

enum 
{
    /*L2 address information for all type packet*/
    CLASSIFY_PPPOE_DESTINATIONMAC =0,   /*6Bytes*/
    CLASSIFY_PPPOE_SOURCEMAC,           /*6Bytes*/


    /*Tag information for single or double tag packet*/
    CLASSIFY_PPPOE_FIRST_TPID,       /*2Bytes*/
    CLASSIFY_PPPOE_FIRST_COS,        /*4Bits*/
    CLASSIFY_PPPOE_FIRST_VLAN,       /*12Bits*/
    CLASSIFY_PPPOE_SECOND_TPID,      /*2Byts*/
    CLASSIFY_PPPOE_SECOND_COS,       /*4Bits  surpport Q-in-Q mode*/
    CLASSIFY_PPPOE_SECOND_VLAN,      /*12Bits surpport Q-in-Q mode*/

    /*length or type field accord with ETHERNETII or 802.3 packet type*/
    CLASSIFY_PPPOE_TYPE_LENGTH,      /*2Bytes  This is the type or lenth field in the L2 head*/
    CLASSIFY_PPPOE_CODE,             /*1Bytes  This is the code field in the PPP head*/

    CLASSIFY_PPPOE_PPPPRO_TYPE,      /*2Bytes  This is the type or lenth field in the L2 head*/
    CLASSIFY_PPPOE_LCPIPCPCODE,      /*2Bytes  This is the type or lenth field in the L2 head*/
    CLASSIFY_PPPOE_IPVER,            /*2Bytes  This is the type or lenth field in the L2 head*/
    

    /*Below define IP head field*/
    /*CLASSIFY_PPPOE_HEAD_LENGTH,      4Bits*/
    CLASSIFY_PPPOE_TOS,              /*1Bytes*/
    /*CLASSIFY_PPPOE_PKT_LENGTH,       2Bytes*/
    /*CLASSIFY_PPPOE_IDENTIFIER,       2Bytes*/
    /*CLASSIFY_PPPOE_FLAG,             3Bits*/
    /*CLASSIFY_PPPOE_SLICE_OFF,        13Bits*/
    /*CLASSIFY_PPPOE_TTL,              1Bytes*/ 
    CLASSIFY_PPPOE_PRO_TYPE,         /*1Bytes This is protocol type field in the IP head*/
    /*CLASSIFY_PPPOE_CHECKSUM,         2Bytes */
    CLASSIFY_PPPOE_SOURCE_IP,        /*4Bytes*/
    CLASSIFY_PPPOE_DESTINATION_IP,   /*4Bytes*/ 

    /*layer4 port number*/
    CLASSIFY_PPPOE_SOURCE_PORT,      /*2Bytes L4 port*/
    CLASSIFY_PPPOE_DESTINATION_PORT, /*2Bytes L4 port*/

    /*other field define for user specify function*/
    CLASSIFY_PPPOE_USER_FIELD1,
    CLASSIFY_PPPOE_LAST_NULL_FIELD
};

typedef enum TRAF_ACTION_s
{
	COPY_PACKETS_TO_CPU = 1,
	DROP_PACKETS = 2,
	DO_NOT_COPY_TO_CPU = 4,
	DO_NOT_DROP = 8
}TRAF_ACTION_e;

typedef enum RMK_ACTION_s
{
	CHANGE_COS_FIELD = 1,
	CHANGE_ICOS_FIELD = 2,	
	DO_NOT_OP_VLAN0 = 0,
	DO_NOT_OP_VLAN1 = 4,
	INSERT_TAG_AFTER_SA = 8,
	CHANGE_VID_AS_RULE_VID = 0XC,
}RMK_ACTION_e;

typedef enum CTC_ETHER_PRI_s
{
	CTC_ETHER_PRI_0 = 0X00,
	CTC_ETHER_PRI_1 = 0X01,
	CTC_ETHER_PRI_2 = 0X02,
	CTC_ETHER_PRI_3 = 0X03,
	CTC_ETHER_PRI_4 = 0X04,
	CTC_ETHER_PRI_5 = 0X05,
	CTC_ETHER_PRI_6 = 0X06,
	CTC_ETHER_PRI_7 = 0X07,
	CTC_ETHER_PRI_END = 0XFF
}CTC_ETHER_PRI_e;

typedef enum CTC_QUEUE_MAP_s
{
	CTC_QUEUE_MAP_0 = 0X00,
	CTC_QUEUE_MAP_1 = 0X01,
	CTC_QUEUE_MAP_2 = 0X02,
	CTC_QUEUE_MAP_3 = 0X03,
	CTC_QUEUE_MAP_4 = 0X04,
	CTC_QUEUE_MAP_5 = 0X05,
	CTC_QUEUE_MAP_6 = 0X06,
	CTC_QUEUE_MAP_7 = 0X07,
	CTC_QUEUE_MAP_END = 0XFF
}CTC_QUEUE_MAP_e;

/* mac module struct*/
#if defined(ONU_4PORT_AR8327)
#define DAL_MAX_PORT_LEARN_LIMIT_NUM  1024

typedef enum tagFDB_MAC_TYPE_E
{
	FDB_MAC_INVALID,
	FDB_MAC_DYNAMIC,
	FDB_MAC_STATIC,
	FDB_MAC_DISCARD,
	FDB_MAC_TYPE_MAX
}FDB_MAC_TYPE_E;
#else
typedef enum tagFDB_MAC_TYPE_E
{
	FDB_MAC_INVALID,
	FDB_MAC_DYNAMIC,
	FDB_MAC_STATIC,
	FDB_MAC_TYPE_MAX
}FDB_MAC_TYPE_E;
#endif

typedef enum FDB_PORT_TYPE_e
{
	FDB_PORT_TYPE_GE,
	FDB_PORT_TYPE_PON,
	FDB_PORT_TYPE_MAX
}FDB_PORT_TYPE_t;

typedef struct tagFDB_MAC_ENTRY_INFO_S
{
	UINT16 usType;
    UINT16 usPortType;
	UINT16 usPortBitmap;
	UINT16 usVlanId;
	UINT8 aucMacAddress[6];
}FDB_MAC_ENTRY_INFO_S;

/* multicast module struct */
typedef struct GROUP_ADDR_CLS_INDEX_MAP_s{
	UINT8 	valid;
	UINT16 clsIndex;
	UINT8   mac[MAC_LENGTH];
       UINT16 vid;
       UINT32 ip;
}GROUP_ADDR_CLS_INDEX_MAP_t;


typedef struct CLASSIFY_ADDR_TBL_s
{
#ifdef OPCONN_BIG_ENDIAN
	UINT32 bfReserved:12;
	UINT32 bfAddr3:5;
	UINT32 bfAddr2:5;
   	UINT32 bfAddr1:5;
   	UINT32 bfAddr0:5;
#else
   	UINT32 bfAddr0:5;
	UINT32 bfAddr1:5;
	UINT32 bfAddr2:5;
	UINT32 bfAddr3:5;
	UINT32 bfReserved:12;
#endif
}CLASSIFY_ADDR_TBL_t;

typedef struct CLASSIFY_MASK_TBL_s										    
{
#ifdef OPCONN_BIG_ENDIAN
	UINT32 bfReserved:5;
	UINT32 bfValid:1;										/* Bits 218*/
	UINT32 bfImask:1;									/* Bits 217*/
	UINT32 bfEmask:1;									/* Bits 216*/
    UINT32 bfOffset6:4;                                     /* Bits 212-215 */
    UINT32 bfOffset5:4;                                     /* Bits 208-211 */
    UINT32 bfOffset4:4;                                     /* Bits 204-207 */
    UINT32 bfOffset3:4;                                     /* Bits 200-203 */
    UINT32 bfOffset2:4;                                     /* Bits 196-199 */
    UINT32 bfOffset1:4;                                     /* Bits 192-195 */                                /* Bits 256-259 */

    UINT8  Mask[CLASSIFY_KEYVALUE_LENGTH];                  /* Bits 0-191   */
#else
   UINT32 bfOffset1:4;
   UINT32 bfOffset2:4;
   UINT32 bfOffset3:4;
   UINT32 bfOffset4:4;
   UINT32 bfOffset5:4;
   UINT32 bfOffset6:4;
   UINT32 bfEmask:1;
   UINT32 bfImask:1;
   UINT32 bfValid:1;
   UINT32 bfReserved:5;

   UINT8  Mask[CLASSIFY_KEYVALUE_LENGTH];
#endif
} CLASSIFY_MASK_TBL_t;

typedef struct CLASSIFY_RULE_TBL_s
{
#ifdef OPCONN_BIG_ENDIAN
   	UINT32 bfReserved:31;
	UINT32 bfTranActH:1;				/* Bits 224*/
	
	UINT32 bfTranActL:3;				/* Bits 221-223*/
	UINT32 bfEgress:1;					/* Bits 220*/
	UINT32 bfIngress:1;					/* Bits 219*/
	UINT32 bfRmkAct:4;					/* Bits 215-218*/				
	UINT32 bfRmkCos:3;				/* Bits 212-214*/
	UINT32 bfRmkIcos:3;				/* Bits 209-211*/
	UINT32 bfRmkVid:12;				/* Bits 197-208*/
	UINT32 bfMsel:5;						/* Bits 192-196*/
	
   	UINT8  Rule[CLASSIFY_KEYVALUE_LENGTH];                  /* Bits 0-191   */
#else
	UINT32 bfTranActH:1;
	UINT32 bfReserved:31;

	UINT32 bfMsel:5;
	UINT32 bfRmkVid:12;
	UINT32 bfRmkIcos:3;
	UINT32 bfRmkCos:3;
	UINT32 bfRmkAct:4;
	UINT32 bfIngress:1;
	UINT32 bfEgress:1;
	UINT32 bfTranActL:3;

   	UINT8  Rule[CLASSIFY_KEYVALUE_LENGTH];                 
#endif
}CLASSIFY_RULE_TBL_t;

typedef struct CLASSIFY_ADDR_RULEHIT_s
{
#ifdef OPCONN_BIG_ENDIAN
	UINT32 bfReserved:8;
	UINT32 bfRuleHit:24;

#else
	UINT32 bfRuleHit:24;
	UINT32 bfReserved:8;
#endif
}CLASSIFY_ADDR_RULEHIT_t;
typedef struct CLASSIFY_METER_TBL_s
{
#ifdef OPCONN_BIG_ENDIAN
	UINT32 bfResv:12;
	UINT32 bfCir: 10;
	UINT32 bfCbs: 10;
#else
	UINT32 bfCbs: 10;
    	UINT32 bfCir: 10;
	UINT32 bfResv:12;
#endif
}CLASSIFY_METER_TBL_t;

typedef struct CLASSIFY_ADDR_ENTRY_s
{
    UINT16 ClasAddr[CLASSIFY_RULE_TABLE_GROUP];
}CLASSIFY_ADDR_ENTRY_t;

typedef struct CLASSIFY_MASK_ENTRY_s										    
{
	UINT32 bfReserved:5;
	UINT32 bfValid:1;										/* Bits 218*/
	UINT32 bfImask:1;									/* Bits 217*/	
	UINT32 bfEmask:1;									/* Bits 216*/
   	UINT32 bfOffset6:4;                                     /* Bits 212-215 */
   	UINT32 bfOffset5:4;                                     /* Bits 208-211 */
   	UINT32 bfOffset4:4;                                     /* Bits 204-207 */
   	UINT32 bfOffset3:4;                                     /* Bits 200-203 */
   	UINT32 bfOffset2:4;                                     /* Bits 196-199 */
   	UINT32 bfOffset1:4;                                     /* Bits 192-195 */

   	UINT8  Mask[CLASSIFY_KEYVALUE_LENGTH];                  /* Bits 0-191   */

	UINT8  maskPri;
   	UINT16 referenceCount;
} CLASSIFY_MASK_ENTRY_t;

typedef struct CLASSIFY_RULE_ENTRY_s
{
   	UINT32 bfReserved:31;												
	UINT32 bfTranActH:1;

	UINT32 bfTranActL:3;				/* Bits 221-223*/
	UINT32 bfEgress:1;					/* Bits 220*/
	UINT32 bfIngress:1;					/* Bits 219*/
	UINT32 bfRmkAct:4;					/* Bits 215-218*/				
	UINT32 bfRmkCos:3;				/* Bits 212-214*/
	UINT32 bfRmkIcos:3;				/* Bits 209-211*/
	UINT32 bfRmkVid:12;				/* Bits 197-208*/
	UINT32 bfMsel:5;						/* Bits 192-196*/
	
   	UINT8  Rule[CLASSIFY_KEYVALUE_LENGTH];                  /* Bits 0-191   */
}CLASSIFY_RULE_ENTRY_t;

typedef struct CLASSIFY_METER_s
{
	UINT8 used;
	UINT8 cbs;
	UINT8 cir;
}CLASSIFY_METER_t;

typedef struct CLASSIFY_RULE_MALLOC_s
{
    UINT8 mallocFlag;
    UINT8 modMselFlag;
}CLASSIFY_RULE_MALLOC_t; 

typedef struct CLASSIFY_OFFSET_SET_PAR_s
{
	UINT8		offsetSeq;			/* Offset windows from 1 to 8*/
	UINT8		searchLoop;			/* Searching offset windows from 1 to 8 is a loop */
	UINT16  	startBit;			/* */
	UINT16  	fieldLength;		    /* */
}CLASSIFY_OFFSET_SET_PAR_t;

typedef struct CLASSIFY_FIELD_ADDRLEN_s
{
    UINT16 	fieldOffset;
    UINT16 	fieldLength;
}CLASSIFY_FIELD_ADDRLEN_t;

typedef struct CLASSIFY_MASK_OFFSET_FIELD_s
{
    UINT8	offsetValue[6];   
}CLASSIFY_MASK_OFFSET_FIELD_t;

typedef union CLASSIFY_FIELD_MAP_s
{
    struct
    {
#ifdef OPCONN_BIG_ENDIAN
        UINT32 bfEnaDestMAC:1;
        UINT32 bfEnaSrcMAC:1;
        UINT32 bfEnaFirstTPID:1;
        UINT32 bfEnaFirstCOS:1;
        UINT32 bfEnaFirstTag:1;    
#ifdef ONLY_SUPPORT_SINGLE_TAG
#else
        UINT32 bfEnaSecondTPID:1;
        UINT32 bfEnaSecondCOS:1;
        UINT32 bfEnaSecondTAG:1;
#endif				
        UINT32 bfEnaLenorType:1;
        UINT32 bfEnaIpVer:1;
        UINT32 bfEnaIpTos:1;
        UINT32 bfEnaIpProType:1;
        UINT32 bfEnaSrcIP:1;
        UINT32 bfEnaDestIP:1;
        UINT32 bfEnaSrcPort:1;
        UINT32 bfEnaDestPort:1;
        UINT32 bfEnaUserDefine1:1;
#ifdef ONLY_SUPPORT_SINGLE_TAG
		 UINT32 :18;
#else
        UINT32 :15;
#endif
#else
#ifdef ONLY_SUPPORT_SINGLE_TAG
		 UINT32 :18;
#else
        UINT32 :15;
#endif
        UINT32 bfEnaUserDefine1:1;
        UINT32 bfEnaDestPort:1;
        UINT32 bfEnaSrcPort:1;
        UINT32 bfEnaDestIP:1;
        UINT32 bfEnaSrcIP:1;
        UINT32 bfEnaIpProType:1;
        UINT32 bfEnaIpTos:1;
        UINT32 bfEnaIpVer:1;
        UINT32 bfEnaLenorType:1;
#ifdef ONLY_SUPPORT_SINGLE_TAG	
#else
        UINT32 bfEnaSecondTAG:1;
        UINT32 bfEnaSecondCOS:1;
        UINT32 bfEnaSecondTPID:1;
#endif				
        UINT32 bfEnaFirstTag:1;    
        UINT32 bfEnaFirstCOS:1;
        UINT32 bfEnaFirstTPID:1;
        UINT32 bfEnaSrcMAC:1;
        UINT32 bfEnaDestMAC:1;
        
#endif
    }EIIField;


    struct
    {
#ifdef OPCONN_BIG_ENDIAN
        UINT32 bfEnaDestMAC:1;
        UINT32 bfEnaSrcMAC:1;
        UINT32 bfEnaFirstTPID:1;
        UINT32 bfEnaFirstCOS:1;
        UINT32 bfEnaFirstTag:1;  
#ifdef ONLY_SUPPORT_SINGLE_TAG		
#else
        UINT32 bfEnaSecondTPID:1;
        UINT32 bfEnaSecondCOS:1;
        UINT32 bfEnaSecondTAG:1;
#endif				
        UINT32 bfEnaLenorType:1;
        UINT32 bfEnaPPPCode:1;       
        UINT32 bfEnaPPPproType:1;
        UINT32 bfEnaLcpIpcp:1;
        UINT32 bfEnaIpVer:1;
        UINT32 bfEnaIpTos:1;
        UINT32 bfEnaIpProType:1;
        UINT32 bfEnaSrcIP:1;
        UINT32 bfEnaDestIP:1;
        UINT32 bfEnaSrcPort:1;
        UINT32 bfEnaDestPort:1;
        UINT32 bfEnaUserDefine1:1;
#ifdef ONLY_SUPPORT_SINGLE_TAG	
		 UINT32 :15;	
#else
        UINT32 :12;
#endif
#else
#ifdef ONLY_SUPPORT_SINGLE_TAG
		  UINT32 :15;
#else
        UINT32 :12;
#endif
        UINT32 bfEnaUserDefine1:1;
        UINT32 bfEnaDestPort:1;
        UINT32 bfEnaSrcPort:1;
        UINT32 bfEnaDestIP:1;
        UINT32 bfEnaSrcIP:1;
        UINT32 bfEnaIpProType:1;
        UINT32 bfEnaIpTos:1;
        UINT32 bfEnaIpVer:1;
        UINT32 bfEnaLcpIpcp:1;
        UINT32 bfEnaPPPproType:1;
        UINT32 bfEnaPPPCode:1;
        UINT32 bfEnaLenorType:1;
#ifdef ONLY_SUPPORT_SINGLE_TAG	
#else
        UINT32 bfEnaSecondTAG:1;
        UINT32 bfEnaSecondCOS:1;
        UINT32 bfEnaSecondTPID:1;
#endif				
        UINT32 bfEnaFirstTag:1;    
        UINT32 bfEnaFirstCOS:1;
        UINT32 bfEnaFirstTPID:1;
        UINT32 bfEnaSrcMAC:1;
        UINT32 bfEnaDestMAC:1;
        
#endif
    }PppoEField;
    

    UINT32 bitMap;
}CLASSIFY_FIELD_MAP_t;

typedef struct CLASSIFY_EII_s
{
#ifdef OPCONN_BIG_ENDIAN
    UINT8  DestMac[6];                         /*6Bytes*/
    UINT8  SrcMac[6];                          /*6Bytes*/
	
    UINT32 bfFirstTpid:             16;        /*2Bytes*/
    UINT32 bfFirstCos:		        3;         /*3Bits*/
    UINT32 bfReser_FirstCFI:        1;
    UINT32 bfFirstVlan:		        12;        /*12Bits*/
#ifdef ONLY_SUPPORT_SINGLE_TAG	
#else
    UINT32 bfSecondTpid:            16;        /*2Byts*/
    UINT32 bfSecondCos:		        3;         /*3Bits  surpport Q-in-Q mode*/
    UINT32 bfReser_SecondCFI:       1;
    UINT32 bfSecondVlan:	        12;        /*12Bits surpport Q-in-Q mode*/
#endif    
    UINT32 bfLenOrType:             16;        /*2Bytes  This is the type or
                                               *lenth field in the L2 head*/
    UINT32 bfIpVersion:	            4;         /*4Bits*/
    UINT32 bfReserved:	            4;
    UINT32 bfIpTos:                 8;         /*1Bytes*/

	UINT16 reser_IpPktLen;
    UINT16 reser_IpIdentify;
    
    UINT16 bfReser_IpSliceFlag:     3;
    UINT16 bfReser_IpSliceOffset:   13;
    
    UINT8  reser_IpTtl;
    UINT8  ipProType;                          /*1Bytes This is protocol type 
                                               *field in the IP head*/
    UINT16 reser_IpCheckSum;
    UINT32 srcIP;                              /*4Bytes*/              
    UINT32 destIP;                             /*4Bytes*/
    UINT16 srcPort;                            /*2Bytes L4 port*/
    UINT16 destPort;                           /*2Bytes L4 port*/
    UINT32 userDefine;
#else

    UINT8  DestMac[6];                         /*6Bytes*/
    UINT8  SrcMac[6];                          /*6Bytes*/

    UINT32 bfFirstVlan:		        12;        /*12Bits*/
    UINT32 bfReser_FirstCFI:        1;
    UINT32 bfFirstCos:		        3;         /*3Bits*/
	UINT32 bfFirstTpid:             16;        /*2Bytes*/
#ifdef ONLY_SUPPORT_SINGLE_TAG
#else
    UINT32 bfSecondVlan:	        12;        /*12Bits surpport Q-in-Q mode*/
    UINT32 bfReser_SecondCFI:       1;
    UINT32 bfSecondCos:		        3;         /*3Bits  surpport Q-in-Q mode*/
    UINT32 bfSecondTpid:            16;        /*2Byts*/
#endif	

    UINT32 bfIpTos:                 8;         /*1Bytes*/ 
    UINT32 bfReserved:	            4;
    UINT32 bfIpVersion:	            4;         /*4Bits*/
	UINT32 bfLenOrType:             16;        /*2Bytes  This is the type or 
                                               *lenth field in the L2 head*/
        
    UINT16 reser_IpPktLen;
    UINT16 reser_IpIdentify;
    
    UINT16 bfReser_IpSliceOffset:   13;
    UINT16 bfReser_IpSliceFlag:     3;   
    
    UINT8  reser_IpTtl;
    UINT8  ipProType;                          /*1Bytes This is protocol type
    											*field in the IP head*/
    UINT16 reser_IpCheckSum;
    UINT32 srcIP;                              /*4Bytes*/              
    UINT32 destIP;                             /*4Bytes*/
    UINT16 srcPort;                            /*2Bytes L4 port*/
    UINT16 destPort;                           /*2Bytes L4 port*/
    UINT32 userDefine;
#endif
}CLASSIFY_EII_t;

typedef struct CLASSIFY_PPPPOE_s
{
#ifdef OPCONN_BIG_ENDIAN
    UINT8  DestMac[6];                         /*6Bytes*/
    UINT8  SrcMac[6];                          /*6Bytes*/

	UINT32 bfFirstTpid:             16;        /*2Bytes*/
    UINT32 bfFirstCos:		        3;         /*3Bits*/
    UINT32 bfReser_FirstCFI:        1;
    UINT32 bfFirstVlan:		        12;        /*12Bits*/
#ifdef ONLY_SUPPORT_SINGLE_TAG
#else
    UINT32 bfSecondCos:		        3;         /*3Bits  surpport Q-in-Q mode*/
    UINT32 bfReser_SecondCFI:       1;
    UINT32 bfSecondVlan:	        12;        /*12Bits surpport Q-in-Q mode*/ 
    UINT32 bfSecondTpid:            16;        /*2Byts*/
#endif	
    UINT16 lenOrType;                          /*2Bytes  This is the type or 
                                               *lenth field in the L2 head*/

    UINT8  reserved;                           /*version,type.1Bytes*/
    UINT8  pppCode;				               /*1Byte*/
	UINT16 sessionId;			
	UINT16 length;              

	UINT32 pppProType:				16;
	UINT32 bfLcpIpcpCodeH:			4;
	UINT32 bfIpVer_lcpIpcpCodeL:	4;
	UINT32 ipTos:					8;

	UINT16 reser_PktLen;
	UINT16 reser_IpIdenty;

	UINT16 bfReser_IpSliceFlag:	3;
	UINT16 bfReser_IpSliceOffset:13;

	UINT8  reser_IpTtl;
	UINT8  ipProType;
	UINT16 reser_IpCheckSum;

    UINT32 srcIP;                              /*4Bytes*/              
    UINT32 destIP;                             /*4Bytes*/
    UINT16 srcPort;                            /*2Bytes L4 port*/
    UINT16 destPort;                           /*2Bytes L4 port*/   

    UINT32 userDefine;
#else
    UINT8  DestMac[6];                         /*6Bytes*/
    UINT8  SrcMac[6];                          /*6Bytes*/

    UINT32 bfFirstVlan:		        12;        /*12Bits*/
    UINT32 bfReser_FirstCFI:        1;
    UINT32 bfFirstCos:		        3;         /*3Bits*/
    UINT32 bfFirstTpid:             16;        /*2Bytes*/
#ifdef ONLY_SUPPORT_SINGLE_TAG	
#else
    UINT32 bfSecondVlan:		    12;        /*12Bits surpport Q-in-Q mode*/
	UINT32 bfReser_SecCFI:		    1;
    UINT32 bfSecondCos:			    3;         /*3Bits  surpport Q-in-Q mode*/    
    UINT32 bfSecondTpid:            16;        /*2Byts*/
#endif
	UINT16 lenOrType;                          /*2Bytes  This is the type or
                                               *lenth field in the L2 head*/

    UINT8  reserved;                           /*version,type.1Bytes*/
    UINT8  pppCode;					           /*1Byte*/
	UINT16 sessionId;
	UINT16 length;
	
	UINT32 ipTos:					8;
	UINT32 bfIpVer_lcpIpcpCodeL:	4;
	UINT32 bfLcpIpcpCodeH:			4;
	UINT32 pppProType:				16;

	UINT16 reser_PktLen;
	UINT16 reser_IpIdenty;

	UINT16 bfReser_IpSliceOffset:13;
	UINT16 bfReser_IpSliceFlag:	3;

	UINT8  reser_IpTtl;
	UINT8  ipProType;
	UINT16 reser_IpCheckSum;

    UINT32 srcIP;                              /*4Bytes*/              
    UINT32 destIP;                             /*4Bytes*/
    UINT16 srcPort;                            /*2Bytes L4 port*/
    UINT16 destPort;                           /*2Bytes L4 port*/   

    UINT32 userDefine;
#endif
    
}CLASSIFY_PPPOE_t;

typedef union
 {
	 CLASSIFY_EII_t 	EIIValue;	/*Values of EII packet fields for rule value usage*/
	 CLASSIFY_PPPOE_t	PPPoeValue; /*Values of PPPoE packet fields for rule value usage*/
 }ClsDataValue_t;

typedef struct CLASSIFY_PARAMETER_s
{
    	UINT8  pktType;
    	UINT8  egressMask;                /* Mask for egress port */
    	UINT8  ingressMask;	              /* Mask for ingress port */
    	UINT8  maskPri;
    	UINT16 cbs;                       /* CBS of meter configuration */
    	UINT16 cir;                        /* CIR of meter configuration */

    	CLASSIFY_FIELD_MAP_t   FieldMap;  /*Indicates each field is classified or not */
	CLASSIFY_RULE_ENTRY_t  RuleEntry; /*Input parameters in rule configuration*/
	ClsDataValue_t PktRuleValue;
    ClsDataValue_t PktUsrMask;

}CLASSIFY_PARAMETER_t;

typedef struct CLASSIFY_MASK_PARAMETER_s
{
    UINT8  pktType;

    UINT16 egressMask;
    UINT16 ingressMask;

    UINT16  maskID;

    CLASSIFY_FIELD_MAP_t   FieldMap;

    union
    {
        CLASSIFY_EII_t   EIIValue;
        CLASSIFY_PPPOE_t PPPoeValue;
    }RuleValue;

	union
	{
        CLASSIFY_EII_t   EIIUsrMask;
        CLASSIFY_PPPOE_t PPPoeUsrMask;
	}UsrMask;

}CLASSIFY_MASK_PARAMETER_t;

typedef struct CLASSIFY_RULE_PARAMETER_s
{
    	UINT8  pktType;
	UINT16 cbs;
	UINT16 cir;
    	UINT16 maskID;
	
	CLASSIFY_RULE_ENTRY_t  RuleEntry;
	
    union
    {
        CLASSIFY_EII_t   EIIValue;
        CLASSIFY_PPPOE_t PPPoeValue;
    }RuleValue;
	
}CLASSIFY_RULE_PARAMETER_t;

typedef struct CLASSIFY_MASKINFO_FOR_RULE_s
{
    CLASSIFY_MASK_OFFSET_FIELD_t MaskOffset;
    UINT16                       ingressMask;
    UINT16                       egressMask;
    UINT32                       fieldMap;
    UINT8                        Mask[CLASSIFY_KEYVALUE_LENGTH];
	
	union
	{
        CLASSIFY_EII_t   EIIUsrMask;
        CLASSIFY_PPPOE_t PPPoeUsrMask;
	}UsrMask;

}CLASSIFY_MASKINFO_FOR_RULE_t;

typedef struct opl_cls_hwtbl_s{
	UINT16 clsHwRuleID;   
	UINT16 clsHwMaskID; 
	UINT16 clsHwAddr;
    UINT16 clsHwOff;
}opl_cls_hwtbl_t;

typedef struct CLASSIFY_ITEM_s
{
	CLASSIFY_PARAMETER_t Parameter;
    	UINT16 classifyRuleID;   
	opl_cls_hwtbl_t shadowtbl;
	UINT8  valid;
}CLASSIFY_ITEM_t;

typedef struct CLS_CONFIG_INFO_s
{
#if defined(ONU_4PORT_AR8306)||defined(ONU_4PORT_AR8228)||defined(ONU_4PORT_AR8327)
	UINT8	name[64];	/* classify rule name */
	UINT8	ports[10];		/* port list */
#endif
	UINT8  valid  :1;
	UINT8  t_act  :4;/*transfer action*/
	UINT8  pad    :3;
    UINT8  rulePri;
	UINT8  queueMapId;
	UINT8  cosMapVal;
	UINT8  ingressmask;
	UINT8  bingress;
	UINT16 rmkvidOp:2;
/*add by ltang,for bug 3222 ---start---*/	
#if 1
	UINT16 rmkcoschange:1;
	UINT16 rmkicoschange:1;
#endif
/*add by ltang,for bug 3222 ---end---*/	
	UINT16 rmkvid:12;

    UINT32 dstMacFlag:1;
    UINT32 srcMacFlag:1;
    UINT32 etherPriFlag:1;
    UINT32 vlanIdFlag:1;
    UINT32 lenOrTypeFlag:1;
    UINT32 dstIpFlag:1;
    UINT32 srcIpFlag:1;
    UINT32 ipTypeFlag:1;
    UINT32 ipV4DscpFlag:1;
    UINT32 ipV6PreFlag:1;
    UINT32 srcL4PortFlag:1;
    UINT32 dstL4PortFlag:1;
    UINT32 rsvFlag:21;

	struct {
		UINT8 lowRange[6];
		UINT8 highRange[6];
	}dstMac;

	struct {
		UINT8 lowRange[6];
		UINT8 highRange[6];
	}srcMac;

	struct {
		UINT8 lowRange;
		UINT8 highRange;
	}etherPri;

	struct {
		UINT16 lowRange;
		UINT16 highRange;
	}vlanId;

	struct {
		UINT16 lowRange;
		UINT16 highRange;
	}lenOrType;
	
	struct {
		UINT32 lowRange;
		UINT32 highRange;
	}dstIp;

	struct {
		UINT32 lowRange;
		UINT32 highRange;
	}srcIp;

	struct {
		UINT8 lowRange;
		UINT8 highRange;
	}ipType;

	struct {
		UINT8 lowRange;
		UINT8 highRange;
	}ipV4Dscp;

	struct {
		UINT8 lowRange;
		UINT8 highRange;
	}ipV6Pre;

	struct {
		UINT16 lowRange;
		UINT16 highRange;
	}srcL4Port;

	struct {
		UINT16 lowRange;
		UINT16 highRange;
	}dstL4Port;
	
    UINT8 dstMacOp;
    UINT8 srcMacOp;
    UINT8 etherPriOp;
    UINT8 vlanIdOp;
    UINT8 lenOrTypeOp;
    UINT8 dstIpOp;
    UINT8 srcIpOp;
    UINT8 ipTypeOp;
    UINT8 ipV4DscpOp;
    UINT8 ipV6PreOp;
    UINT8 srcL4PortOp;
    UINT8 dstL4PortOp;
}CLS_CONFIG_INFO_t;

typedef struct opl_acl_list_s{
    struct list_head list;
    UINT16 ruleid;/*rule id */
    UINT16 tcnum;/*total list number*/
    UINT8 prinum;/*priority acl number*/
    UINT8 rulepri;/*0---normal acl, 1-8---oam acl */
    UINT16 dalindex;/*dal table index*/  
	opl_cls_hwtbl_t hwshadow;
	CLS_CONFIG_INFO_t stClassCfg;
    UINT8 status;
	UINT8  name[32];/*rule name ,independent*/
} opl_acl_list_t;


/* port module struct*/
typedef enum DAL_PORT_SPEED_s{
    DAL_10_MBPS     = 10,
    DAL_100_MBPS    = 100,
    DAL_1000_MBPS   = 1000,
    DAL_END_MBSP
}DAL_PORT_SPEED_e;

typedef enum DAL_DUPLEX_MODE_s
{
	DAL_HALF_DUPLEX = 0X01,
	DAL_FULL_DUPLEX  = 0X02	
}DAL_DUPLEX_MODE_e;

typedef enum DAL_AUTONEG_DONE_s
{
	DAL_AUTONEG_FAILED = 0X00,
	DAL_AUTONEG_COMPLETED  = 0X01	
}DAL_AUTONEG_DONE_e;


/* rstp module struct */
typedef enum tagRSTP_P2P_MODE
{
  RSTP_P2P_FORCE_TRUE,
  RSTP_P2P_FORCE_FALSE,
  RSTP_P2P_AUTO,
}RSTP_P2P_MODE_E;

/* vtt module struct*/

typedef enum VLAN_EGRESS_TYPE_S
{
    UNMODIFY = 0,
    UNTAG    = 1,
    TAG      = 2 
}VLAN_EGRESS_TYPE_E;

typedef enum
{
    UNMODIFY_EGRESS = 0,
    UNTAGGED_EGRESS,
    TAGGED_EGRESS,
    ADD_TAG
} PORT_EGRESS_MODE;

typedef enum
{
	DOT1Q_MODE_DISABLE = 0,
	DOT1Q_MODE_FALLBACK,
	DOT1Q_MODE_CHECK,
	DOT1Q_MODE_SECURE
} SW_DOT1Q_MODE;

typedef enum DAL_VTT_TYPE_s
{
	DAL_VTT_UC = 0, /* used for  mc */
	DAL_VTT_MC = 1,	/* used for  mc */
	DAL_VTT_END
}DAL_VTT_TYPE_e;

typedef struct VTT_RECORD_s
{
	UINT32 sVlanInfo;
	UINT32 cVlanInfo;
	UINT8	valid;
}VTT_RECORD_t;

typedef struct VLAN_CONFI_INFO_s
{
	UINT8 		vlanMode;
	UINT16 	    defaultVlanTag;
	UINT16 	    defaultTPID;
	UINT8   	defaultPRI;
	UINT8   	defaultCFI;
	UINT8		numOfVttRecords;
	VTT_RECORD_t vtt_record[DAL_PORT_VTT_ENTRY_NUM];
}VLAN_CONFI_INFO_t;




/* tm module struct */
typedef enum UP_DOWN_STREAM_s
{
	UP_STREAM = 0,
	DOWN_STREAM = 1,
	BOTH_STREAM = 2
}UP_DOWN_STREAM_e;

typedef enum UP_QUEUE_PRI_s
{
	UP_Q_PRI0 = 0,
	UP_Q_PRI1 = 1,
	UP_Q_PRI2 = 2,
	UP_Q_PRI3 = 3,
	UP_Q_PRI4 = 4,
	UP_Q_PRI5 = 5,
	UP_Q_PRI6 = 6,
	UP_Q_PRI7 = 7	
}UP_QUEUE_PRI_e;

typedef enum DOWN_QUEUE_PRI_s
{
	DOWN_Q_PRI0 = 0,
	DOWN_Q_PRI1 = 1,
	DOWN_Q_PRI2 = 2,
	DOWN_Q_PRI3 = 3,
	DOWN_Q_PRI4 = 4,
	DOWN_Q_PRI5 = 5,
	DOWN_Q_PRI6 = 6,
	DOWN_Q_PRI7 = 7	
}DOWN_QUEUE_PRI_e;

typedef enum TM_US_WRED_TYPE_s
{
	US_WRED_MINTH,
	US_WRED_MAXTH,
	US_WRED_WEIGHT,
	US_WRED_C1,
	US_WRED_END,
}TM_US_WRED_TYPE_e;

typedef enum TM_DS_WRED_TYPE_s{
	DS_WRED_MINTH,
	DS_WRED_MAXTH,
	DS_WRED_WEIGHT,
	DS_WRED_C1,
	DS_WRED_END,
}TM_DS_WRED_TYPE_e;

typedef struct TM_US_Q_CONF_STA_s
{
#ifdef OPCONN_BIG_ENDIAN
	UINT32 bfReserved0:5;
	UINT32 bfNumOfCell:14;
	UINT32 bfNumOfPkt:13;

	UINT32 bfReserved1:5;
	UINT32 bfMaxNumOfCell:14;
	UINT32 bfMaxNumOfPkt:13;
#else
	UINT32 bfNumOfPkt:13;
	UINT32 bfNumOfCell:14;
	UINT32 bfReserved0:5;

	UINT32 bfMaxNumOfPkt:13;
	UINT32 bfMaxNumOfCell:14;
	UINT32 bfReserved1:5;
#endif
}TM_US_Q_CONF_STA_t;

typedef struct TM_DS_Q_CONF_STA_s
{
#ifdef OPCONN_BIG_ENDIAN
	UINT32 bfReserved0:5;
	UINT32 bfNumOfCell:14;
	UINT32 bfNumOfPkt:13;

	UINT32 bfReserved2:5;
	UINT32 bfMaxNumOfCell:14;
	UINT32 bfMaxNumOfPkt:13;
#else
	UINT32 bfNumOfPkt:13;
	UINT32 bfNumOfCell:14;
	UINT32 bfReserved0:5;

	UINT32 bfMaxNumOfPkt:13;
	UINT32 bfMaxNumOfCell:14;
	UINT32 bfReserved2:5;
#endif
}TM_DS_Q_CONF_STA_t;

typedef struct TM_US_Q_SHAPER_PA1_s
{
#ifdef OPCONN_BIG_ENDIAN
	UINT32 bfReserved0:7;
	UINT32 bfPir:15;
	UINT32 bfPbs:10;
#else
	UINT32 bfPbs:10;
	UINT32 bfPir:15;
	UINT32 bfReserved0:7;
#endif
}TM_US_Q_SHAPER_PA1_t;

typedef struct TM_DS_Q_SHAPER_PA_s
{
#ifdef OPCONN_BIG_ENDIAN
	UINT32 bfReserved0:7;
	UINT32 bfCir:15;
	UINT32 bfCbs:10;
#else
	UINT32 bfCbs:10;
	UINT32 bfCir:15;
	UINT32 bfReserved0:7;
#endif
}TM_DS_Q_SHAPER_PA_t;

typedef struct TM_US_Q_SHAPER_PA_s
{
#ifdef OPCONN_BIG_ENDIAN
	UINT32 bfReserved0:7;
	UINT32 bfCir:15;
	UINT32 bfCbs:10;
#else
	UINT32 bfCbs:10;
	UINT32 bfCir:15;
	UINT32 bfReserved0:7;
#endif
}TM_US_Q_SHAPER_PA_t;

typedef struct TM_DS_WRED_PA_s
{
#ifdef OPCONN_BIG_ENDIAN
	UINT32 bfReserved0:16;
	UINT32 bfC1:4;
	UINT32 bfWeight:4;
	UINT32 bfMaxthH:8;

	UINT32 bfMaxthL:12;
	UINT32 bfMinth:20;
#else
	UINT32 bfMaxthH:8;
	UINT32 bfWeight:4;
	UINT32 bfC1:4;
	UINT32 bfReserved0:16;

	UINT32 bfMinth:20;
	UINT32 bfMaxthL:12;
#endif
}TM_DS_WRED_PA_t;

typedef struct TM_US_WRED_PA_s
{
#ifdef OPCONN_BIG_ENDIAN
	UINT32 bfReserved0:16;
	UINT32 bfC1:4;
	UINT32 bfWeight:4;
	UINT32 bfMaxthH:8;

	UINT32 bfMaxthL:12;
	UINT32 bfMinth:20;
#else
	UINT32 bfMaxthH:8;
	UINT32 bfWeight:4;
	UINT32 bfC1:4;
	UINT32 bfReserved0:16;

	UINT32 bfMinth:20;
	UINT32 bfMaxthL:12;	
#endif
}TM_US_WRED_PA_t;


/* phy module */
typedef enum PHY_SPEED_MODE_s
{
	PHY_SPEED_10M 	= 0X00,
	PHY_SPEED_100M 	= 0X01,
	PHY_SPEED_1000M	= 0X02,
	PHY_SPEED_RSV
}PHY_SPEED_MODE_e;

typedef enum PHY_DUPLEX_MODE_s
{
	PHY_HALF_DUPLEX = 0X00,
	PHY_FULL_DUPLEX  = 0X01	
}PHY_DUPLEX_MODE_e;

typedef enum PHY_AUTONEG_DONE_s
{
	PHY_AUTONEG_FAILED = 0X00,
	PHY_AUTONEG_COMPLETED = 0X01	
}PHY_AUTONEG_DONE_e;

#if 0

typedef enum OPCONN_TAB_s
{
	OPCONN_TAB_CLS_MASK = OPL_ZERO,
	OPCONN_TAB_CLS_ADDR,
	OPCONN_TAB_CLS_RULE,
	OPCONN_TAB_CLS_COUNTER,
	OPCONN_TAB_PON_MAC,
	OPCONN_TAB_US_SHPBD,
	OPCONN_TAB_DS_SHPBD,
	OPCONN_TAB_US_WRED,
	OPCONN_TAB_DS_WRED,
	OPCONN_TAB_Q_CONF_STA,
	OPCONN_TAB_DMA0_RX,
	OPCONN_TAB_DMA0_TX,
	OPCONN_TAB_DMA1_RX,
	OPCONN_TAB_DMA1_TX,
	OPCONN_TAB_END
}OPCONN_TAB_e;

#endif

/*pon module */

typedef struct PON_MPCP_DISC_STATUS_s
{
#ifdef OPCONN_BIG_ENDIAN
	UINT32 bfRsved1:3;
	UINT32 bfGatePendingNum:5;
	UINT32 bfRsved0:8;
	UINT32 bfDiscLEvent:4;
	UINT32 bfDiscCEvent:4;
	UINT32 bfDiscLState:4;
	UINT32 bfDiscCState:4;
#else
	UINT32 bfDiscCState:4;
	UINT32 bfDiscLState:4;
	UINT32 bfDiscCEvent:4;
	UINT32 bfDiscLEvent:4;
	UINT32 bfResved0:8;
	UINT32 bfGatePendingNum:5;
	UINT32 bfRsved1:3; 
#endif
}PON_MPCP_DISC_STATUS_t;

typedef enum PON_MPCP_EVENT_s
{
	EVENT_BEGIN,
	EVENT_REGISTER_EVENT_FROM_DISCAGENT,
	EVENT_INSIDE_DISCWINDOW,
	EVENT_DEREGISTER_FROM_DISCAGENT_AND_NOT_IN_DISCWINDOW,
	EVENT_OLT_PERMIT_REGISTER_AND_NOT_IN_DISCWINDOW,
	EVENT_OLT_DENY_REGISTER_AND_NOT_IN_DISCWINDOW,
	EVENT_NEW_DISCWINDOW,
	EVENT_PERMIT_ACK_EVENT_FROM_DISCAGENT,
	EVENT_DENY_ACK_EVENT_FROM_DISCAGENT,
	EVENT_REGISTER_FROM_OLT,
	EVENT_REGISTERED_AND_TIMSTAMP_DRIFT_EVENT,
	EVENT_DEREGISTER_EVENT_FROM_OLT,
	EVENT_DEREGISTER_EVENT_FROM_DISCAGENT_WHEN_ONU_IS_REGISTERED,
	EVENT_WATCHDOG_TIMEOUT,
	EVENT_END
}PON_MPCP_EVENT_e;


typedef enum PON_MPCP_STATE_s
{
	STATE_WAIT,
	STATE_REGISTERING,
	STATE_REGISTER_REQUEST,
	STATE_REGISTER_PENDING,
	STATE_DENIED,
	STATE_RETRY,
	STATE_REGISTER_ACK,
	STATE_NACK,
	STATE_REGISTERD,
	STATE_REMOTE_DEREGISTER,
	STATE_LOCAL_DEREGISTER,
	STATE_WATCHDOG_TIMEOUT,
	STATE_END
}PON_MPCP_STATE_e;


/*bridge mac module */

#define DAL_MAC_MAX_LPORT_NUM (1)
#define DAL_MAC_MAX_PHYPORT_NUM (0)
#define DAL_MAC_GE_PORT_BITMAP (0x2)
#define DAL_MAC_DEFAULT_AGING_TIME_IN_SEC (1200)

#define DONOT_DROP					(1<<3)
#define DONOT_COPY_TO_CPU	(1<<2)
#define DROP_PKTS						(1<<1)
#define COPY_PKTS_TO_CPU		(1)
#define RMK_INSERT_VID (2)
#define RMK_CHANGE_VID (3)

#define DAL_NUM_OF_PORTS    1 
#define MAX_NUM_OF_VLAN 4095

/*I2c module*/

#define OT_EPROM_I2C_ADDR          0x50
#define OT_I2C_ADDR                0x00

#if 0
typedef struct OPCONN_TAB_INFO_s
{
	UINT32 	tabId;
	UINT32  	numOfRec;
	UINT32 	widthOfRec;
	UINT8 		*desc;
}OPCONN_TAB_INFO_t;
#endif


/*interrupt module start */

#define OPL_MAX_NUM_OF_INTR_LEVEL2  32

typedef enum UPTM_INT_TYPE_s
{
	TMUS_QUEUE_FULL_INT_TYPE,
	TMUS_RD_ERR_INT_TYPE,
	TMUS_PKT_POS_ERR_INT_TYPE,
	TMUS_PKT_LEN_ERR_INT_TYPE,
	TMUS_LL_FULL_INT_TYPE,
	TMUS_RPT_ERR_INT_TYPE,
	TM_HEAD_DISORDER_INT_TYPE,
	TM_HEAD_OVFLW_INT_TYPE,
	TM_MPCP_SEND_FAIL_ERR_INT_TYPE,
	TM_MPCP_SEND_OK_ERR_INT_TYPE,
	TMUS_INT_TYPE_END
}UPTM_INT_TYPE_e;

typedef enum DNTM_INT_TYPE_s
{
	TMDS_QUEUE_FULL_INT_TYPE,
	TMDS_RD_ERR_INT_TYPE,
	TMDS_PKT_POS_ERR_INT_TYPE,
	TMDS_PKT_LEN_ERR_INT_TYPE,
	TMDS_LL_FULL_INT_TYPE,
	TMDS_INT_TYPE_END
}DNTM_INT_TYPE_e;

typedef enum BRG_INT_TYPE_s
{
	RX_DIS_DROP_INT_TYPE,	
	TX_DIS_DROP_INT_TYPE,
	RSV_MAC_DROP_INT_TYPE,
	USR_MAC_DROP_INT_TYPE,
	US_VTT_ERR_INT_TYPE,
	DS_VTT_ERR_INT_TYPE,
	US_TAG_ERR_INT_TYPE,
	DS_TAG_ERR_INT_TYPE,
	US_ARL_SMAC_CFL_INT_TYPE,
	DS_ARL_SMAC_CFL_INT_TYPE,
	US_ZERO_DA_DROP_INT_TYPE,
	DS_ZERO_DA_DROP_INT_TYPE,
	ARL_FULL_ARL_NEW_REQ_INT_TYPE,
	US_NON_UCST_DROP_INT_TYPE,
	DS_NON_UCST_DROP_INT_TYPE,
	BRG_INT_TYPE_END
}BRG_INT_TYPE_e;

typedef enum MPCP_INT_TYPE_s
{
	MPCP_STATE_INT_TYPE,
	MPCP_GATE_DISORDER_INT_TYPE,
	MPCP_ECHO_PENDING_ERR_INT_TYPE,
	MPCP_STATE_CHANGE_INT_TYPE,	
	MPCP_GRANT_LIST_FULL_INT_TYPE,
	MPCP_GATE_TIMEOUT_INT_TYPE,
	MPCP_LINK_UP_INT_TYPE,
	MPCP_LINK_DOWN_INT_TYPE,
	MPCP_INT_TYPE_END
}MPCP_INT_TYPE_e;

typedef enum MISC_INT_TYPE_s
{
	MISC_DATA_SPACE_FULL_INT_TYPE,
	MISC_TRAF_OVFLW_INT_TYPE,
	MISC_MPIS_UFLOW_INT_TYPE,
	MISC_LL_EMPTY_INT_TYPE,
	MISC_INT_TYPE_END
}MISC_INT_TYPE_e;

typedef enum PMAC_INT_TYPE_s
{
	SIGNAL_VAL_INT_TYPE,
    SYNC_ERR_RX_INT_TYPE,
    SYNC_ERR_TX_INT_TYPE,
    RXPLL_LCK_CHANGE_INT_TYPE,
    TXPLL_LCK_CHANGE_INT_TYPE,
    LINK_CHANGE_INT_TYPE,
	CRC8_ERR_INT_TYPE,
	LOS_IND_INT_TYPE,
	PMAC_INT_TYPE_END
}PMAC_INT_TYPE_e;

typedef enum PCM_INT_TYPE_s
{
    TX_FIFO_FULL_ERR_INT_TYPE,
    TX_FIFO_EMPTY_ERR_INT_TYPE,
    RX_FIFO_FULL_ERR_INT_TYPE,
    RX_FIFO_EMPTY_ERR_INT_TYPE,
	TX_FIFO_ALMOST_EMPTY_INT_TYPE,
	RX_FIFO_ALMOST_FULL_INT_TYPE,
	PCM_INT_TYPE_END
}PCM_INT_TYPE_e;

typedef enum OPL_INTR_L1_ID_s 
{
	OPL_IRQ0_INTR,
	OPL_IRQ1_INTR,
	OPL_IRQ2_INTR,
	OPL_IRQ3_INTR,
	OPL_IRQ4_INTR,
	OPL_IRQ5_INTR,
	OPL_IRQ6_INTR,
	OPL_IRQ7_INTR,
	OPL_IRQ8_INTR,
	OPL_IRQ9_INTR,
	OPL_IRQ10_INTR,
	OPL_IRQ11_INTR,
	OPL_MISC_INTR,
	OPL_BRG_INTR,
	OPL_UPTM_INTR,
	OPL_DNTM_INTR,
	OPL_MPCP_INTR,
	OPL_PMAC_INTR,
	OPL_GE_INTR,
	OPL_PCM_INTR,
	OPL_DMA0_INTR,
	OPL_DMA1_INTR,
	OPL_SPI_INTR,
	OPL_WDOG_INTR,
	OPL_RTC_INTR,
	OPL_TIMER0_INTR,
	OPL_TIMER1_INTR,
	OPL_TIMER2_INTR,
	OPL_TIMER3_INTR,
	OPL_I2C_INTR,
	OPL_UART0_INTR,
	OPL_UART1_INTR,
	OPL_END_INTR
}OPL_INTR_L1_ID_e;

typedef struct OPL_INT_LEVEL2_s
{
	INT16 	id;
	UINT8	*name;
	UINT32 	penAddr;
	UINT32 	penBit;
	INT32 		enAddr;
	UINT32 	enBit;
	UINT32 	counter;
	UINT32    	ulErrCnt;
}OPL_INT_LEVEL2_t;

typedef struct OPL_INT_s
{
	OPL_INTR_L1_ID_e 	 id;
	UINT8 						* name;
	UINT32 					counter;
	UINT32 					errCounter;
	OPL_INT_LEVEL2_t 	level2Int[OPL_MAX_NUM_OF_INTR_LEVEL2];
}OPL_INT_t;

/*bridge module start*/

#define BRG_RSV_MAC_NUM				33
#define PON_BRG_MAC_ENTRY_NUM    TAB_PON_MAC_LEN


#define GMAC_TBI_MODE			0
#define GMAC_GMII_MODE			1


typedef enum BRG_PORT_NUM_s
{
	BRG_PORT_GE = 0,
	BRG_PORT_PON = 1,
	BRG_PORT_CPU = 2,
	BRG_PORT_END
}BRG_PORT_NUM_e;

typedef enum BRG_PON_PORT_LINK_CONTROL_s
{
 	PON_PORT_TRSMT_EN,
	PON_PORT_TAG,
	PON_PORT_UNTAG,
	PON_PORT_I_COS,
	PON_PORT_I_ACTION,
	PON_PORT_PVID,
	PON_PORT_COS,
	PON_PORT_RSV,
	PON_PORT_LP,
	PON_PORT_LERN_LIMIT,
	PON_PORT_LERN_DROP,
	PON_PORT_LERN,
	PON_PORT_RCV_EN,
	PON_PORT_END
}BRG_PON_PORT_LINK_CONTROL_e;

typedef enum BRG_GE_PORT_LINK_CONTROL_s
{
	GE_PORT_TRSMT_EN,
	GE_PORT_TAG,
	GE_PORT_UNTAG,
	GE_PORT_I_COS,
	GE_PORT_I_ACTION,
	GE_PORT_PVID,
	GE_PORT_COS,
	GE_PORT_RSV,
	GE_PORT_LP,
	GE_PORT_LERN_LIMIT,
	GE_PORT_LERN_DROP,
	GE_PORT_LERN,
	GE_PORT_RCV_EN,
	GE_PORT_END
}BRG_GE_PORT_LINK_CONTROL_e;

typedef struct BRG_PORT_TAB_GE_s
{
#ifdef OPCONN_BIG_ENDIAN
	UINT32 reserved:4;
	UINT32 rcv_en:1;
	UINT32 lern:1;
	UINT32 lern_drop:1;
	UINT32 lern_limit:1;
	UINT32 lp:1;
	UINT32 rsv_en:1;
	UINT32 cos:3;
	UINT32 pvid:12;
	UINT32 i_action:1;
	UINT32 i_cos:3;
	UINT32 untag:1;
	UINT32 tag:1;
	UINT32 trsmt_en:1;
#else
	UINT32 trsmt_en:1;
	UINT32 tag:1;
	UINT32 untag:1;
	UINT32 i_cos:3;
	UINT32 i_action:1;
	UINT32 pvid:12;
	UINT32 cos:3;
	UINT32 rsv_en:1;
	UINT32 lp:1;
	UINT32 lern_limit:1;
	UINT32 lern_drop:1;
	UINT32 lern:1;
	UINT32 rcv_en:1;
	UINT32 reserved:4;
#endif
}BRG_PORT_TAB_GE_t;

typedef struct BRG_PORT_TAB_PON_s
{
#ifdef OPCONN_BIG_ENDIAN
	UINT32 reserved:4;
	UINT32 rcv_en:1;
	UINT32 lern:1;
	UINT32 lern_drop:1;
	UINT32 lern_limit:1;
	UINT32 lp:1;
	UINT32 rsv_en:1;
	UINT32 cos:3;
	UINT32 pvid:12;
	UINT32 i_action:1;
	UINT32 i_cos:3;
	UINT32 untag:1;
	UINT32 tag:1;
	UINT32 trsmt_en:1;
#else
	UINT32 trsmt_en:1;
	UINT32 tag:1;
	UINT32 untag:1;
	UINT32 i_cos:3;
	UINT32 i_action:1;
	UINT32 pvid:12;
	UINT32 cos:3;
	UINT32 rsv_en:1;
	UINT32 lp:1;
	UINT32 lern_limit:1;
	UINT32 lern_drop:1;
	UINT32 lern:1;
	UINT32 rcv_en:1;
	UINT32 reserved:4;
#endif
}BRG_PORT_TAB_PON_t;

typedef struct BRG_PORT_TAB_ENTRY_s
{
	union 
	{
		BRG_PORT_TAB_GE_t 	port_entry_ge;
		BRG_PORT_TAB_PON_t  port_entry_pon;
	}common;
}BRG_PORT_TAB_ENTRY_t;


#define DAL_CNT_POLL_GE_MASK		0x00000001
#define DAL_CNT_POLL_PON_MASK		0x00000002
#define DAL_CNT_POLL_FE_MASK		0x00000004
#define DAL_CNT_POLL_TM_MASK		0x00000008
#define DAL_CNT_POLL_CLE_MASK		0x00000010
#define DAL_CNT_POLL_BRG_MASK		0x00000020
#define DAL_CNT_POLL_MPCP_MASK		0x00000040
#define DAL_CNT_POLL_MARB_MASK		0x00000080
#define DAL_CNT_POLL_CPDMA_MASK		0x00000100
#define DAL_CNT_POLL_FEDMA_MASK		0x00000200
#define DAL_CNT_POLL_GEPARSER_MASK	0x00000400
#define DAL_CNT_POLL_CLEHIT_MASK	0x00000800
#define DAL_CNT_POLL_SWITCH_MASK	0x00001000

#define DAL_CNT_GE_NUM			38
#define DAL_CNT_PON_NUM			45
#define DAL_CNT_FE_NUM			9
#define DAL_CNT_TM_NUM			12
#define DAL_CNT_CLE_NUM			2
#define DAL_CNT_BRG_NUM			18
#define DAL_CNT_MPCP_NUM		17
#define DAL_CNT_MARB_NUM		6
#define DAL_CNT_CPDMA_NUM		11
#define DAL_CNT_FEDMA_NUM		7
#define DAL_CNT_GEPARSER_NUM	6
#define DAL_CNT_CLEHIT_NUM		128
#define DAL_CNT_MAX_NUM			128

typedef struct OPL_CNT_ADD_s
{
	UINT32 uiHigh;
	UINT32 uiLow;
}OPL_CNT_ADD_t;

typedef struct OPL_CNT_s
{
	UINT16			usId;
	UINT8			pucName[32];
	OPL_CNT_ADD_t	stAdded;
	UINT8			pucHelp[80];
}OPL_CNT_t;


/* PON Counter Special Treatment Index */
typedef enum OPL_PON_CNT_ST_IDX_e
{
    OPL_PON_CNT_ST_IDX_TxTotalPkts = 2,
    OPL_PON_CNT_ST_IDX_TxMACControlPkts = 6,
    OPL_PON_CNT_ST_IDX_TxOAMPkts = 15,
    OPL_PON_CNT_ST_IDX_RxTotalPkts = 22,
    OPL_PON_CNT_ST_IDX_RxMACControlPkts = 27,
    OPL_PON_CNT_ST_IDX_RxOAMPkts = 42
}OPL_PON_CNT_ST_IDX_t;


/* MPCP Counter Special Treatment Index */
typedef enum OPL_MPCP_CNT_ST_IDX_e
{
    OPL_MPCP_CNT_ST_IDX_REGREQ = 12,
    OPL_MPCP_CNT_ST_IDX_REGACK = 13
}OPL_MPCP_CNT_ST_IDX_t;

typedef struct ONU_PON_Port_Statistics_Get_1_s{
	UINT64 FramesTransmittedOK;			/* LLID端口发送帧计数*/
	UINT64 OctetsTransmittedOK;			/* LLID端口发送字节计数*/
	UINT64 MulticastFramesXmittedOK;	/* LLID端口发送组播帧计数*/
	UINT64 BroadcastFramesXmittedOK;	/* LLID端口发送广播包计数 */
	UINT64 PONPauseFramesTransmittedOk;	/* PON端口发送PAUSE帧计数*/
	UINT64 FramesReceivedOK;			/*LLID端口接收帧计数*/
	UINT64 OctetsReceivedOK;			/* LLID端口接收字节计数 */
	UINT64 MulticastFramesReceivedOK;	/* LLID端口接收组播帧计数*/
	UINT64 BroadcastFramesReceivedOK;	/* LLID端口接收广播包计数 */
	UINT64 PONPauseFramesReceivedOk;	/* PON端口接收PAUSE帧计数*/
	UINT64 SingleCollisionFrames;		/*单次帧碰撞计数*/
	UINT64 MultipleCollisionFrames;		/*多次帧碰撞计数*/ 	
	UINT64 AlignmentErrors;				/*对齐错误计数*/
	UINT64 FrameTooLongErrors;			/*帧超长计数*/
}ONU_PON_Port_Statistics_Get_1_t;

typedef struct ONU_PON_Port_Statistics_Get_2_s{
	UINT64 CRC8Errors;						/* CRC错误计数 */
	UINT64 FECCorrectedBlocks;				/* FEC正确块计数 */
	UINT64 FECUncorrectableBlocks;			/* FEC错误块计数 */
	UINT64 MPCPMACCtrlFramesTransmitted;	/* MPCP控制帧发送计数*/
	UINT64 MPCPMACCtrlFramesReceived;		/* MPCP控制帧接收计数*/
	UINT64 MPCPTxGate;						/* MPCP Tx Gate计数*/
	UINT64 MPCPTxRegAck;					/* MPCP Tx Reg Ack计数*/
	UINT64 MPCPTxRegister;					/* MPCP Tx Register计数*/
	UINT64 MPCPTxRegRequest;				/* MPCP Tx Registe Requestr计数  */
	UINT64 MPCPTxReport;					/* MPCP Tx Report计数 */
	UINT64 MPCPRxGate;						/*MPCP Rx Gate计数*/
	UINT64 MPCPRxRegAck;					/*MPCP Rx Reg Ack计数*/
	UINT64 MPCPRxRegister;					/*MPCP Rx Register计数*/
	UINT64 MPCPRxRegRequest;				/*MPCP Rx RegRequest计数*/
	UINT64 MPCPRxReport;					/*MPCP Rx Report计数*/	
}ONU_PON_Port_Statistics_Get_2_t;

typedef struct ONU_Port_Flux_Statistics_Counter_s{
	UINT64 ifInOctets;       /* 收到的上行包字节数 */
	UINT64 ifInUcastPkts;    /* 收到的上行单播包数目 */
	UINT64 ifInNUcastPkts;   /* 收到的上行组播包数目 */
	UINT64 ifInDiscards;     /* 丢弃的上行包数目 */
	UINT64 ifInErrors;       /* 收到的上行错误包数目  */
	UINT64 ifOutOctets;      /* 收到的下行包字节数  */
	UINT64 ifOutUcastPkts;   /* 收到的下行单播包数目  */
	UINT64 ifOutNUcastPkts;  /* 收到的下行组播包数目  */
	UINT64 ifOutDiscards;    /* 丢弃的下行包数目  */
	UINT64 ifOutErrors;      /* 收到的下行包数目  */
}ONU_Port_Flux_Statistics_Counter_t;


#pragma pack ()


/*interrupt module end*/
//extern int opconn_dal_ioctl( unsigned int cmd, unsigned int arg );

/* */
#if 0
OPL_STATUS dalPonMacIdSet( UINT8 * mac );

OPL_STATUS dalPonMacIdGet( UINT8 * mac );

OPL_STATUS dalPonPhyFecModeSet( UINT32 mode );

OPL_STATUS dalPonPhyFecModeGet( UINT32 * mode );

OPL_STATUS dalPonPhyTripleChuningModeSet( UINT32 mode );

OPL_STATUS dalPonPhyTripleChuningModeGet( UINT32 * mode );

OPL_STATUS dalPonPhyAesModeSet( UINT32 mode );

OPL_STATUS dalPonPhyAesModeGet( UINT32 * mode );

OPL_STATUS dalPonLaserOnCntSet( UINT32 count );

OPL_STATUS dalPonLaserOnCntGet( UINT32 * count );

OPL_STATUS dalPonLaserOffCntSet( UINT32 count );

OPL_STATUS dalPonLaserOffCntGet( UINT32 * count );

OPL_STATUS dalPonSyncTimeGet( UINT32 * count );

OPL_STATUS dalPonLlidGet( UINT32 * llid );

OPL_STATUS dalPonSerdesDelayCntSet( UINT32 count );

OPL_STATUS dalPonSerdesDelayCntGet( UINT32 * count );

OPL_STATUS dalPonSecurityModeSet( UINT32 channel, UINT32 mode );

OPL_STATUS dalPonSecurityModeGet( UINT32 channel, UINT32 * mode );

OPL_STATUS dalPonSecurityAesModeSet( UINT32 channel, UINT32 mode );

OPL_STATUS dalPonSecurityAesModeGet( UINT32 channel, UINT32 * mode );

OPL_STATUS dalPonUnicastTripleChurningKeyGet( UINT8 keyIndex, UINT8 * keyBuff );

OPL_STATUS dalPonScbTripleChurningKeySet( UINT8 keyIndex, UINT8 * keyBuff );

OPL_STATUS dalPonUnicastAesKeyGet( UINT8 keyIndex, UINT8 * keyBuff, UINT8 mode );

OPL_STATUS dalPonScbAesKeySet( UINT8 keyIndex, UINT8 * keyBuff, UINT8 mode );

OPL_STATUS dalPonTripleChurningModeGet( UINT8 * mode );

OPL_STATUS dalPonTripleChurningModeSet( UINT8 mode );

OPL_STATUS dalPonMpcpDbaAgentConfigAllSet( 
	UINT32 cpRptStaMode, 
	UINT32 cpMergeRptSendMode, 
	UINT32 cpRptSendMode, 
	UINT32 cpPktInitTimerCfg,
	UINT32 cpDeltaTxNormalNoFecTime, 
	UINT32 cpTxMpcpNoFecTime );

OPL_STATUS dalPonMpcpDbaAgentConfigAllGet( 
	UINT32 * cpRptStaMode, 
	UINT32 * cpMergeRptSendMode, 
	UINT32 * cpRptSendMode, 
	UINT32 * cpPktInitTimerCfg, 
	UINT32 * cpDeltaTxNormalNoFecTime, 
	UINT32 * cpTxMpcpNoFecTime );

OPL_STATUS dalPonDelayConfigAllSet( 
	UINT8 cpTxDlyEn, 
	UINT8 cpSyncEn, 
	UINT16 cpRptsentDelt, 
	UINT16 cpTxDly );

OPL_STATUS dalPonDelayConfigAllGet( 
	UINT32 * cpTxDlyEn, 
	UINT32 * cpSyncEn, 
	UINT32 * cpRptsentDelt, 
	UINT32 * cpTxDly );

OPL_STATUS dalPonMpcpStatusGet( DAL_PON_STATUS_t * ponStatus );

OPL_STATUS dalPonOamFinishedSet( UINT32 oamFinished );

OPL_STATUS dalPonMpcpFsmHoldOverCtrlSet( UINT32 enable );

OPL_STATUS dalPonMpcpFsmHoldOverCtrlGet( UINT32 * enable );

OPL_STATUS dalPonMpcpFsmHoldOverTimeSet( UINT32 holdTime );

OPL_STATUS dalPonMpcpFsmHoldOverTimeGet( UINT32 * holdTime );

OPL_STATUS dalClsTblEntryAdd( 
	CLASSIFY_MASK_ENTRY_t *pMaskEntry, 
	CLASSIFY_RULE_ENTRY_t *pRuleEntry, 
	UINT16 *pCruleID, opl_cls_hwtbl_t *pClshwtbl );

OPL_STATUS dalClsTblEntryDel( CLASSIFY_MASK_ENTRY_t *pMaskEntry, CLASSIFY_RULE_ENTRY_t *pRuleEntry, UINT16 *pCruleID );

OPL_STATUS dalClsMaskTblWr( CLASSIFY_MASK_ENTRY_t *pMask, UINT8 maskID );

OPL_STATUS dalClsRuleTblWr( CLASSIFY_RULE_ENTRY_t *pRule, UINT16 ruleID );

OPL_STATUS dalClsAddrTblWr( UINT16 address, UINT16 offset, UINT16 ruleId );

OPL_STATUS dalClsMaskHwWr( CLASSIFY_MASK_ENTRY_t *pMask, UINT8 maskID );

OPL_STATUS dalClsRuleHwWr( CLASSIFY_RULE_ENTRY_t *pRule, UINT16 ruleID );

OPL_STATUS dalClsAddrHwWr( UINT16 address, UINT16 offset, UINT16 ruleId );

OPL_STATUS dalClsRuleTblRd( CLASSIFY_RULE_ENTRY_t *pRule, UINT16 ruleID, UINT8 tblType );

OPL_STATUS dalClsAddrTblRd( UINT16 address, UINT16 offset, UINT16 *pRuleId, UINT8 tblType );

OPL_STATUS dalClsEntrySet( CLASSIFY_PARAMETER_t *pMaskRulePar, UINT16 *pCruleID, opl_cls_hwtbl_t *pCmaskID );

OPL_STATUS dalClsEntryMove( CLASSIFY_PARAMETER_t *pRulePar, UINT16 * pCruleID );

OPL_STATUS dalClsInit(  );

OPL_STATUS dalClsTranActSet( UINT16 classRuleID, UINT8 actValue );

OPL_STATUS dalClsRmkActSet( UINT16 classRuleID, UINT8 rmkactVal );

OPL_STATUS dalClsRmkCosSet( UINT16 classRuleID, UINT8 cosValue );

OPL_STATUS dalClsRmkIcosSet( UINT16 classRuleID, UINT8 iCosVal );

OPL_STATUS dalClsRmkVidSet( UINT16 classRuleID, UINT16 rmkVid );

OPL_STATUS dalClsEgressPortCfg( UINT16 classItemID, UINT8 pktType, UINT8 portID, UINT8 eMask, UINT8 bEnable );

OPL_STATUS dalClsIngressPortCfg( UINT16 classItemID, UINT8 pktType, UINT8 portID, UINT8 iMask, UINT8 bEnable );

OPL_STATUS dalClsTranActCfg( UINT16 classItemID, UINT8 pktType, UINT8 actValue );

OPL_STATUS dalClsRmkActCfg( UINT16 classItemID, UINT8 pktType, UINT8 rmkActVal );

OPL_STATUS dalClsRmkCosCfg( UINT16 classItemID, UINT8 pktType, UINT8 cosValue );

OPL_STATUS dalClsRmkIcosCfg( UINT16 classItemID, UINT8 pktType, UINT8 iCosValue );

OPL_STATUS dalClsRmkVidCfg( UINT16 classItemID, UINT8 pktType, UINT16 rmkVid );

OPL_STATUS dalClsMaskPrioCfg( UINT16 classItemID, UINT8 pktType, UINT8 maskPrio );

OPL_STATUS dalClsDestMacAddrCfg( UINT16 classItemID, UINT8 pktType, INT8 * pDestMac, INT8 * pUsrMask, UINT8 bEnable );

OPL_STATUS dalClsSrcMacAddrCfg( UINT16 classItemID, UINT8 pktType, INT8 * pSrcMac, INT8 * pUsrMask, UINT8 bEnable );

OPL_STATUS dalClsFirstCosCfg( UINT16 classItemID, UINT8 pktType, UINT8 cosVal, UINT8 usrMask, UINT8 bEnable );

OPL_STATUS dalClsFirstVidCfg( UINT16 classItemID, UINT8 pktType, UINT16 vlanID, UINT16 usrMask, UINT8 bEnable );

OPL_STATUS dalClsTypeLenCfg( UINT16 classItemID, UINT8 pktType, UINT16 typeLen, UINT16 usrMask, UINT8 bEnable );

OPL_STATUS dalClsDestIpCfg( UINT16 classItemID, UINT8 pktType, INT8 * pDestIp, INT8 * pUsrMask, UINT8 bEnable );

OPL_STATUS dalClsSrcIpCfg( UINT16 classItemID, UINT8 pktType, INT8 * pSrcIp, INT8 * pUsrMask, UINT8 bEnable );

OPL_STATUS dalClsIpTypeCfg( UINT16 classItemID, UINT8 pktType, UINT8 ipType, UINT8 usrMask, UINT8 bEnable );

OPL_STATUS dalClsIpTosCfg( UINT16 classItemID, UINT8 pktType, UINT8 ipTos, UINT8 usrMask, UINT8 bEnable );

OPL_STATUS dalClsL4DestPortCfg( UINT16 classItemID, UINT8 pktType, UINT16 L4DestPortID, UINT16 usrMask, UINT8 bEnable );

OPL_STATUS dalClsL4SrcPortCfg( UINT16 classItemID, UINT8 pktType, UINT16 L4SrcPortID, UINT16 usrMask, UINT8 bEnable );

#if 1/*wfxu*/
OPL_STATUS dalClsRuleEntryShow(UINT16 startId, UINT16 endId, UINT8 mode );
OPL_STATUS dalClsMaskEntryShow(UINT16 startId, UINT16 endId, UINT8 mode );
OPL_STATUS dalClsAddrEntryShow(UINT16 startId, UINT16 endId, UINT8 mode );
OPL_STATUS dalClsCfgShow(UINT16 usFirstItem,UINT16 usLastItem);
#endif

OPL_STATUS dalClsRuleDel( UINT16 classItemID );

OPL_STATUS dalClsConvertPara( CLASSIFY_ITEM_t *pClassItemInfo, CLS_CONFIG_INFO_t *stClassCfg, UINT8 pktType );

OPL_STATUS dalClsCtcInit(  );

OPL_STATUS dalClsValidEntryGet(UINT16 *puiClsId);

OPL_STATUS dalClsRuleCtcAdd( CLS_CONFIG_INFO_t *stClassCfg, UINT16 *ruleId );

OPL_STATUS dalClsRuleCtcDel( CLS_CONFIG_INFO_t *stClassCfg, UINT16 *ruleId );

OPL_STATUS dalClsRuleCtcClear(  );

OPL_STATUS dalExClsDelEntry( UINT32 ruleIndex );

OPL_STATUS dalChipReset(  );

OPL_STATUS dalDemonInit(  );

OPL_STATUS dalArlAgeTimeSet( UINT32 ageingTime );

OPL_STATUS dalArlAgeTimeGet( UINT32 *ageingTime );

OPL_STATUS dalArlMacAdd( UINT8 portNum, UINT8 *macAddress, UINT16 vlanIndex );

OPL_STATUS dalArlMacDel( UINT8 portNum, UINT8 *macAddress, UINT16 vlanIndex );

OPL_STATUS dalArlMacRemove( UINT8 *macAddress, UINT16 vlanIndex );

OPL_STATUS dalArlFlushDynamic(  );

OPL_STATUS dalArlFlushAll(  );

OPL_STATUS dalArlLearnEnSet( UINT8 enable );

OPL_STATUS dalArlLearnEnGet( UINT8 *enable );

OPL_STATUS dalArlSoftLearnEnSet( UINT8 enable );

OPL_STATUS dalArlSoftLearnEnGet( UINT8 *enable );

OPL_STATUS dalArlAgeEnableSet( UINT8 enable );

OPL_STATUS dalArlAgeEnableGet( UINT8 *enable );

OPL_STATUS dalArlMacNumLimitSet( UINT32 portID, UINT8 enable, UINT32 num );

OPL_STATUS dalArlMultiPortMacAdd( UINT32 uiPortNum, UINT32 * auiPortlist, UINT8 * aucMacAddress, UINT16 usVlanId );

OPL_STATUS dalArlMultiPortMacDel( UINT32 uiPortNum, UINT32 * auiPortlist, UINT8 * aucMacAddress, UINT16 usVlanId );

OPL_STATUS dalArlMacEntryFind( UINT8 * aucMacAddress, UINT16 usVlanId, FDB_MAC_ENTRY_INFO_S * pstMacEntryInfo, OPL_BOOL * pbFind );

OPL_STATUS dalArlMacEntryTraverse( UINT32 * puiStartMacEntryId, FDB_MAC_ENTRY_INFO_S * pstMacEntryInfo, OPL_BOOL * pbFind );

OPL_STATUS dalArlMacEntryShowOne( INT32 lFd, UINT8 * aucMacAddress, UINT16 usType, UINT32 uiPortNum, UINT32 * auiPortlist );

OPL_STATUS dalArlMacEntryShowAll( INT32 lFd, UINT16 usType, UINT32 uiPortNum, UINT32 * auiPortlist );

OPL_STATUS dalMulticastInit(  );

OPL_STATUS dalVttEntryTagAdd(UINT8 pon_strip_en,UINT8 ge_strip_en, UINT16 c_vid,UINT16 s_vid);

#if defined(ONU_4PORT_AR8327)
OPL_STATUS dalMulticastVlanAddPort( UINT8 portNum, UINT16 vlanId, UINT32 tag );
#else
OPL_STATUS dalMulticastVlanAddPort( UINT8 portNum, UINT16 vlanId );
#endif
OPL_STATUS dalMulticastVlanDelPort( UINT8 portNum, UINT16 vlanId );

OPL_STATUS dalMulticastVlanTagStripe( UINT8 portNum, UINT8 enable );

OPL_STATUS dalMulticastArlAddPort( UINT8 portNum, UINT8 * macAddr );

OPL_STATUS dalMulticastArlPortDel( UINT8 portNum, UINT8 * macAddr );

OPL_STATUS dalMulticastArlVlanAdd( UINT8 portNum, UINT16 vlanId, UINT8 * macAddr );

OPL_STATUS dalMulticastArlVlanDel( UINT8 portNum, UINT16 vlanId, UINT8 * macAddr );

OPL_STATUS dalMulticastArlTabFlush(  );

OPL_STATUS dalMulticastPortVlanMacAdd( UINT8 portNum, UINT16 vlanId, UINT8 * macAddr, OPL_BOOL fuzzy );

OPL_STATUS dalMulticastPortVlanMacDel( UINT8 portNum, UINT16 vlanId, UINT8 * macAddr, OPL_BOOL fuzzy );

OPL_STATUS dalMulticastPortVlanIpAdd( UINT8 portNum, UINT16 vlanId, UINT32 ip );

OPL_STATUS dalMulticastPortVlanIpDel( UINT8 portNum, UINT16 vlanId, UINT32 ip );

OPL_STATUS dalMulticastRuleDelAll(  );

OPL_STATUS dalMulticastDataFilterAdd(  );

OPL_STATUS dalMulticastDataFilterDel(  );

OPL_STATUS dalMulticastNumofRuleGet( UINT16 * numOfRule );

OPL_STATUS dalPortNumIsInvalid( UINT8 portId );


OPL_STATUS dalPortSpecificDuplexRead( UINT8 portId, UINT32 * duplex );


OPL_STATUS dalPhySpecificAutonegRead( UINT8 portId, UINT32 * state );


OPL_STATUS dalPortSpecificSpeedRead( UINT8 portId, UINT32 * portSpeed );


OPL_STATUS dalPortStateGet( UINT8 portId, UINT8 * status );


OPL_STATUS dalPortSpeedSet( UINT8 portId, UINT32 portSpeed );


OPL_STATUS dalPortSpeedGet( UINT8 portId, UINT32 * portSpeed );


OPL_STATUS dalPortDuplexSet( UINT8 portId, UINT32 duplex );


OPL_STATUS dalPortDuplexGet( UINT8 portId, UINT32 * duplex );


OPL_STATUS dalPortFlowcontrolSet( UINT8 portId, UINT8 enable );


OPL_STATUS dalPortFlowcontrolGet( UINT8 portId, UINT8 * enable );


OPL_STATUS dalPortLoopbackSet( UINT8 portId, UINT8 enable );


OPL_STATUS dalPortUsPolicingEnableSet( UINT8 portId, UINT8 enable );


OPL_STATUS dalPortUsPolicingCirSet( UINT8 portId, UINT32 cir );


OPL_STATUS dalPortUsPolicingCirGet( UINT8 portId, UINT32 * cir );


OPL_STATUS dalPortUsPolicingCbsSet( UINT8 portId, UINT32 cbs );


OPL_STATUS dalPortUsPolicingCbsGet( UINT8 portId, UINT32 * cbs );


OPL_STATUS dalPortUsPolicingEbsSet( UINT8 portId, UINT32 ebs );


OPL_STATUS dalPortUsPolicingEbsGet( UINT8 portId, UINT32 * ebs );


OPL_STATUS dalPortUsPolicingSet( UINT8 portId, UINT8 enable, UINT32 cir, UINT32 cbs, UINT32 ebs );


OPL_STATUS dalPortUsPolicingGet( UINT8 portId, UINT8 * enable, UINT32 * cir, UINT32 * cbs, UINT32 * ebs );


OPL_STATUS dalPortDsPolicingEnableSet( UINT8 portId, UINT8 enable );


OPL_STATUS dalPortDsPolicingEnableGet( UINT8 portId, UINT8 * enable );


OPL_STATUS dalPortDsPolicingCirSet( UINT8 portId, UINT32 cir );


OPL_STATUS dalPortDsPolicingCirGet( UINT8 portId, UINT32 * cir );


OPL_STATUS dalPortDsPolicingPirSet( UINT8 portId, UINT32 pir );


OPL_STATUS dalPortDsPolicingPirGet( UINT8 portId, UINT32 * pir );


OPL_STATUS dalPortDsPolicingSet( UINT8 portId, UINT8 enable, UINT32 cir, UINT32 pir );


OPL_STATUS dalPortDsPolicingGet( UINT8 portId, UINT8 * enable, UINT32 * cir, UINT32 * pir );


OPL_STATUS dalPhyAdminStateGet( UINT8 portId, UINT32 * state );


OPL_STATUS dalPhyAdminControlSet( UINT8 portId,UINT32 state );


OPL_STATUS dalPhyAutonegAdminStateGet( UINT8 portId, UINT32 * state );


OPL_STATUS dalPhyAutonegEnableSet( UINT8 portId,UINT32 enable );


OPL_STATUS dalPhyAutonegRestart( UINT8 portId );


OPL_STATUS dalPortInit(  );


OPL_STATUS dalRstpModeSet( IN OPL_BOOL bEnable );


OPL_STATUS dalRstpPortStateGet( IN UINT32 ulPortId, OUT UINT8 * pucPortState );


OPL_STATUS dalRstpPortStateSet( IN UINT32 ulPortId, IN UINT8 ucPortState );


OPL_STATUS dalRstpPortMacFlush( UINT32 ulPortid, BOOL_T bOnlyThisPort );


OPL_STATUS dalStormClsRuleAdd( UINT32 stormLimitType, UP_DOWN_STREAM_e streamType );


OPL_STATUS dalStormClsRuleDel( UINT32 stormLimitType, UP_DOWN_STREAM_e streamType );


OPL_STATUS dalStormCtrlFrameSet( UINT32 portId, UINT32 stormLimitType, UINT32 limitEnable );


OPL_STATUS dalStormCtrlFrameGet( UINT32 portId, UINT32 stormLimitType, UINT32 * limitEnable );


OPL_STATUS dalStormCtrlRateSet( UINT32 portId, UINT32 rateLimit );


OPL_STATUS dalStormCtrlRateGet( UINT32 portId, UINT32 * rateLimit );


OPL_STATUS oplVerStrGet( UINT8 * pString );


//OPL_STATUS oplVerNumGet( FLOAT32 * verNum );


//OPL_STATUS oplVerShow(  );


OPL_STATUS dalVttModeSet( UINT8 mode, UINT32 portId );


OPL_STATUS dalVttModeGet( UINT8 * mode, UINT32 portId );


OPL_STATUS dalVttTpidSet( UINT16 tpid, UINT32 portId );


OPL_STATUS dalVttTpidGet( UINT16 * tpid, UINT32 portId );


OPL_STATUS dalVttVidSet( UINT16 pvid, UINT32 portId );


OPL_STATUS dalVttVidGet( UINT16 * pvid, UINT32 portId );


OPL_STATUS dalVttDefaultPriSet( UINT8 etherPri, UINT32 portId );


OPL_STATUS dalVttDefaultPriGet( UINT8 * etherPri, UINT32 portId );


OPL_STATUS dalVttTagEntryAdd( UINT8 pStrip, UINT8 gStrip, UINT32 cVlan, UINT32 sVlan, UINT32 portId, UINT32 * pEntryIndex, UINT8 type );


OPL_STATUS dalVttTagEntryGet( UINT8 ValidRecordIndex, UINT32 * cVlan, UINT32 * sVlan, UINT32 portId );


OPL_STATUS dalVttTagEntryDel( UINT8 pStrip, UINT8 gStrip, UINT32 cVlan, UINT32 sVlan, UINT32 portId, UINT32 * pEntryIndex, UINT8 type );


OPL_STATUS dalVttNumOfRecordGet( UINT8 * numOfRecords, UINT32 portId );


OPL_STATUS dalVttMulticastEntryAdd( UINT8 pStrip, UINT8 gStrip, UINT32 cVlan, UINT32 sVlan, UINT32 portId );


OPL_STATUS dalVttMulticastEntryDel( UINT8 pStrip, UINT8 gStrip, UINT32 cVlan, UINT32 sVlan, UINT32 portId );


OPL_STATUS dalVttMulticastStripEnable( UINT8 portId, UINT32 enable );


OPL_STATUS dalVttMulticastInit( UINT8 portId );


OPL_STATUS dalVttMulticastNumOfRecordGet( UINT8 * numOfRecords );


OPL_STATUS dalVttInit(  );



OPL_STATUS tmGeShaperEnableHwWrite( UINT8 stream, UINT8 enable );


OPL_STATUS tmGeShaperEnableHwRead( UINT8 stream, UINT8 * enable );


OPL_STATUS tmQueueShaperEnableHwWrite( UINT8 stream, UINT8 Qid, UINT8 enable );


OPL_STATUS tmQueueShaperEnableHwRead( UINT8 stream, UINT8 Qid, UINT8 * enable );


OPL_STATUS tmQueuePriHwWrite( UINT8 stream, UINT8 Qid, UINT8 priority );


OPL_STATUS tmQueuePriHwRead( UINT8 stream, UINT8 Qid, UINT8 * priority );


OPL_STATUS tmQueueWeightHwWrite( UINT8 stream, UINT8 Qid, UINT32 weight );


OPL_STATUS tmQueueWeightHwRead( UINT8 stream, UINT8 Qid, UINT32 * weight );


OPL_STATUS tmGeCirHwWrite( UINT8 stream, UINT32 geCir );


OPL_STATUS tmGeCirHwRead( UINT8 stream, UINT32 * geCir );


OPL_STATUS tmGeCbsHwWrite( UINT8 stream, UINT32 geCbs );


OPL_STATUS tmGeCbsHwRead( UINT8 stream, UINT32 * geCbs );


OPL_STATUS tmCosIcosMapHwWrite( UINT8 stream, UINT8 cos, UINT8 icos );


OPL_STATUS tmCosIcosMapHwRead( UINT8 stream, UINT8 cos, UINT8 * icos );


OPL_STATUS tmQueueCbsHwWrite( UINT8 stream, UINT8 Qid, UINT32 cbs );


OPL_STATUS tmQueueCbsHwRead( UINT8 stream, UINT8 Qid, UINT32 * cbs );


OPL_STATUS tmQueueCirHwWrite( UINT8 stream, UINT8 Qid, UINT32 cir );


OPL_STATUS tmQueueCirHwRead( UINT8 stream, UINT8 Qid, UINT32 * cir );


OPL_STATUS tmWredCfgSet( UINT8 stream, UINT8 queueId, UINT8 type, UINT32 value );


OPL_STATUS tmWredEnableHwWrite( UINT8 stream, UINT8 queueId, UINT32 enable );


OPL_STATUS tmWredEnableHwRead( UINT8 stream, UINT8 queueId, UINT32 * enable );


OPL_STATUS tmUsShaperTabDirectHwWrite( UINT32 entryId, UINT32 cir, UINT32 cbs );


OPL_STATUS tmUsWredTabDirectHwWrite( UINT32 entryId, UINT32 weight, UINT32 minth, UINT32 maxth );


OPL_STATUS tmDsWredTabDirectHwWrite( UINT32 entryId, UINT32 weight, UINT32 minth, UINT32 maxth );


OPL_STATUS tmDsShaperTabDirectHwWrite( UINT32 entryId, UINT32 cir, UINT32 cbs );


OPL_STATUS tmQueueMaxCellNumHwWrite( UINT8 stream, UINT8 Qid, UINT16 maxCellNum );


OPL_STATUS tmWredCfgGet( UINT8 stream, UINT8 queueId, UINT8 type, UINT32 * value );


OPL_STATUS tmMaxpUsWredTabDirectHwWrite( UINT32 entryId, UINT8 c1, UINT32 weight, UINT32 minth, UINT32 maxth );


OPL_STATUS tmMaxpDsWredTabDirectHwWrite( UINT32 entryId, UINT8 c1, UINT32 weight, UINT32 minth, UINT32 maxth );

OPL_STATUS tmQueueShaperCirEnableHwWrite(UINT8 stream,UINT8 Qid,UINT8 enable);

OPL_STATUS tmUsShaperTabPirDirectHwWrite(UINT32 entryId,UINT32 pir,UINT32 pbs);

OPL_STATUS tmQueueMaxPktNumHwWrite(UINT8 stream,UINT8 Qid,UINT16 maxPktNum);

OPL_STATUS tmUsShaperTabCirDirectHwWrite(UINT32 entryId,UINT32 cir,UINT32 cbs);

OPL_STATUS tmQueueShaperPirEnableHwWrite(UINT8 stream,UINT8 Qid,UINT8 enable);

OPL_STATUS phySpeedHwWrite(UINT32 phySpeedMode);

OPL_STATUS phySpeedHwRead(PHY_SPEED_MODE_e *phySpeedMode);

OPL_STATUS phyDuplexHwWrite(PHY_DUPLEX_MODE_e phyDuplexMode);

OPL_STATUS phyDuplexHwRead(PHY_DUPLEX_MODE_e *phyDuplexMode);

OPL_STATUS phyAutoNegHwWrite(UINT8 enable);

OPL_STATUS phyAutoNegHwRead(UINT8 *enable);

OPL_STATUS phyRestartAutoNeg(void);

OPL_STATUS phyLoopbackEnableHwWrite(UINT8 enable);

OPL_STATUS phyLoopbackEnableHwRead(UINT8 *enable);

OPL_STATUS phyReset(void);

OPL_STATUS phyPowerDown(UINT8 enable);

OPL_STATUS phyLinkStatusHwRead(UINT8 *linkStatus);

OPL_STATUS phyFlowControlEnHwWrite(UINT8 enable);

OPL_STATUS phySpecificAutoRead(UINT32 *phyAutonegDone);

OPL_STATUS phySpecificSpeedRead(PHY_SPEED_MODE_e *phySpeed);

OPL_STATUS phySpecificDuplexRead(PHY_DUPLEX_MODE_e *phyDuplex);

OPL_STATUS oplRegRead(UINT32 regAddr,UINT32 *regVal);

OPL_STATUS oplRegWrite(UINT32 regAddr,UINT32 regVal);

OPL_STATUS oplRegFieldRead(UINT32 regAddr,UINT16 fieldOffset,UINT16 fieldWidth,UINT32 *data0);

OPL_STATUS oplRegFieldWrite(UINT32 regAddr,UINT16 fieldOffset,UINT16 fieldWidth,UINT32 data0);

OPL_STATUS oplTabRead(OPCONN_TAB_e region,UINT32 startId,UINT32 num,UINT32 *pVal);

OPL_STATUS oplTabWrite(OPCONN_TAB_e region,UINT32 startId,UINT32 num,UINT32 *pVal);

OPL_STATUS mdioRegisterRead(UINT8 deviceAddr,UINT8 regAddr,UINT16 *data0);

OPL_STATUS mdioRegisterWrite(UINT8 deviceAddr,UINT8 regAddr,UINT16 data0);

OPL_STATUS mdioRegisterFieldRead(UINT8 deviceAddr,UINT8 regAddr,UINT8 offset,UINT8 width,UINT16 *data0);

OPL_STATUS mdioRegisterFieldWrite(UINT8 deviceAddr,UINT8 regAddr,UINT8 offset,UINT8 width,UINT16 data0);

/* Begin Added */
OPL_STATUS MdioSwGlobalRegRead( UINT32 regAddr, UINT32 * regVal );
OPL_STATUS MdioSwGlobalRegWrite( UINT32 regAddr, UINT32 regVal );
/* End   Added of porting */

OPL_STATUS mdioRegisterInit();

OPL_STATUS chipReset(void);

OPL_STATUS chipAttrGet(UINT8 type,UINT32 *value);

OPL_STATUS chipInit(void);

OPL_STATUS respinInit(void);

OPL_STATUS linkListEnable(void);

OPL_STATUS gmacInit(void);

OPL_STATUS pmacInit(void);

OPL_STATUS dalClsDelEntry(UINT32 ruleid);

OPL_STATUS dalVoipClsDelEntry(UINT32 ruleid);

OPL_STATUS dalVttVlanAggDel(UINT16 egressPort, UINT16 targetVlan, UINT16 aggedVlan,UINT8 *aggedMac);

OPL_STATUS dalVttVlanAggAdd(UINT16 portId, UINT16 sVlan, UINT16 cVlan,UINT8 *aggedMac, UINT16* ruleId);

OPL_STATUS brgRsvMacCtrlHwRead(UINT8 macNum,UINT8 *icos,UINT8 *macCtl);

OPL_STATUS brgRsvMacCtrlHwWrite(UINT8 macNum,UINT8 icos,UINT8 macCtl);

OPL_STATUS dalMulticastEnable();

OPL_STATUS dalMulticastDisable();

int i2cInit (int i2cMode, int intMode, UINT8 slvAddr, int nRate);

int i2cReadRandom (UINT8 slvAddr, UINT8 staRegAddr, UINT32 nByte, UINT8 *pDataBuf );

OPL_STATUS dalOnuClsRuleCtcAdd(opl_acl_list_t *oamcls);

OPL_STATUS dalOnuClsRuleCtcChange(opl_acl_list_t *oamcls,UINT16 newmask);

OPL_STATUS dalOnuClsRuleCtcDel(opl_acl_list_t *oamcls);

OPL_STATUS dalVoipClsDelEntry(UINT32 ruleid);

OPL_STATUS dalClaCfgCheck(CLS_CONFIG_INFO_t *stClassCfg,UINT16 *ruleId);

OPL_STATUS dalPortPvidSet(UINT8 portId,UINT16 pvid);

OPL_STATUS dalPortPvidGet(UINT8 portId,UINT16 *pvid);

OPL_STATUS dalPortVlanModeSet(UINT8 portId,UINT8 mode);

OPL_STATUS dalPortVlanModeGet(UINT8 portId,UINT8 *mode);

OPL_STATUS dalPortDefaultPriSet(UINT8 portId,UINT8 defaultPri);

OPL_STATUS dalTrunkEntryAdd(UINT8 portId, UINT32 vlanId);

OPL_STATUS dalTrunkEntryDel(UINT8 portId, UINT32 vlanId);

OPL_STATUS dalTrunkEntryValueGet(UINT8 portId, UINT16 entryIndex, UINT16 *pVlanId);

OPL_STATUS dalTrunkEntryNumGet(UINT8 portId, UINT32 *pNum);

OPL_STATUS dalTrunkEntryClear(UINT8 portId);

OPL_STATUS dalCreateVlanID(UINT16 vid);

OPL_STATUS dalFlushVlanAll(void);

OPL_STATUS dalSetLocalSwitch(UINT8  lport,UINT8  enable);

OPL_STATUS dalClsRmkActGet(UINT16 classItemID,UINT8 pktType,UINT8 *rmkActVal);

OPL_STATUS dalPonInit(void);

OPL_STATUS dalDbaQueueThresholdSet(UINT8 qSetNum,UINT8 qNum,UINT16 thresholdVal);

OPL_STATUS dalDbaQueueThresholdGet(UINT8 qSetNum,UINT8 qNum,UINT16 *thresholdVal);

OPL_STATUS dalDbaReportModeSet(UINT32 mode);

OPL_STATUS dalDbaReportModeGet(UINT32 *mode);

OPL_STATUS dalOnuMtuSet(UINT32 mtuSize);

OPL_STATUS dalOnuMtuGet(UINT32 *mtuSize);

OPL_STATUS dalOnuPonLoopbackConfig(UINT32 uniorscb, UINT32 enable);

OPL_STATUS dalOnuPonTxPolarityConfig(UINT32 loworhigh);

OPL_STATUS brgUsrDefineRsvMacHwWrite(UINT8 num,UINT8 *mac);

OPL_STATUS brgUsrDefineRsvMacHwRead(UINT8 num,UINT8 *mac);

OPL_STATUS brgUsrDefineRsvMacCtrlHwWrite(UINT8 macNum,UINT8 icos,UINT8 macCtl);

OPL_STATUS brgUsrDefineRsvMacCtrlHwRead(UINT8 macNum,UINT8 *icos,UINT8 *macCtl);

OPL_STATUS dalPONPortStatisticsGet1(ONU_PON_Port_Statistics_Get_1_t * ponStats);

OPL_STATUS dalPONPortStatisticsGet2(ONU_PON_Port_Statistics_Get_2_t * ponStats);

OPL_STATUS dalPortFluxStatisticsCounterGet(ONU_Port_Flux_Statistics_Counter_t * portStats);

OPL_STATUS dalCounterGet( unsigned int moduleBit, OPL_CNT_t * oplCounter, unsigned int start, unsigned int num );

OPL_STATUS dalCounterEnable(unsigned int moduleBitmap);

OPL_STATUS dalCounterEnableGet(unsigned int *moduleBitmap);

OPL_STATUS dalCounterClear(unsigned int moduleBitmap);

OPL_STATUS dalArlDiscardMacAdd(UINT8 *macAddress);

OPL_STATUS dalArlDiscardMacDel(UINT8 *macAddress);

OPL_STATUS dalAclRstpAdd(UINT8 flg);

OPL_STATUS dalMulticastVlanCreate(UINT16 vlanId);

OPL_STATUS dalMulticastVlanDelete(UINT16 vlanId);

OPL_STATUS dalAclClsFindName(CLS_CONFIG_INFO_t *stClassCfg,UINT8 * name);

OPL_STATUS dalArlFlushAllByPort(UINT8 portId);

OPL_STATUS dalPortLearnEnableSet(UINT8 portId,UINT32 enable);

OPL_STATUS dalArlMacMove(UINT32 port, UINT32 toPort);

OPL_STATUS dalArlMacFilterAdd(UINT8 portId, UINT16 vlanId, UINT8 *macAddress);

OPL_STATUS dalArlMacFilterDel(UINT8 portId, UINT16 vlanId, UINT8 *macAddress);

OPL_STATUS dalArlMacDlfFilterEn(UINT8 portId, UINT8 enable);

OPL_STATUS dalArlMacPortLockDropEn(UINT8 portId, UINT8 enable);

OPL_STATUS dalMirPortSet(UINT8 portId);

OPL_STATUS dalMirPortGet(UINT8 * portId);

OPL_STATUS dalMirIngPortSet(UINT8 portId, UINT32 enable);

OPL_STATUS dalMirIngPortGet(UINT8 portId, UINT32 * enable);

OPL_STATUS dalMirEgPortSet(UINT8 portId, UINT32 enable);

OPL_STATUS dalMirEgPortGet(UINT8 portId, UINT32 * enable);

OPL_STATUS dalDeleteVlanID(UINT16 vid);

OPL_STATUS dalAddVlanPort(UINT8 portId, UINT16 vid, VLAN_EGRESS_TYPE_E type);

OPL_STATUS dalMoveVlanPort(UINT8 portId, UINT16 vid);

OPL_STATUS dalMibGet(UINT8 portId, void * mib);

OPL_STATUS isis_phy_get(UINT32 dev_id, UINT32 phy_addr,UINT32 reg, UINT16 *value);

OPL_STATUS isis_phy_set(UINT32 dev_id, UINT32 phy_addr,UINT32 reg, UINT16 value);

OPL_STATUS isis_reg_get(UINT32 dev_id, UINT32 reg_addr, UINT8 *value,UINT32 value_len);

OPL_STATUS isis_reg_set(UINT32 dev_id, UINT32 reg_addr, UINT8 *value,UINT32 value_len);

OPL_STATUS isis_reg_field_get(UINT32 dev_id, UINT32 reg_addr,UINT32 bit_offset, UINT32 field_len,UINT8 *value, UINT32 value_len);

OPL_STATUS isis_reg_field_set(UINT32 dev_id, UINT32 reg_addr,UINT32 bit_offset, UINT32 field_len,const UINT8 *value, UINT32 value_len);

OPL_STATUS isis_acl_rule_dump(UINT32 dev_id);

OPL_STATUS isis_acl_list_dump(UINT32 dev_id);

OPL_STATUS atheros_show_cnt(UINT32 port_id);

OPL_STATUS dalArVttShow(UINT32 portId);

OPL_STATUS dalVlanShow(UINT32	vid);

OPL_STATUS dalQinqPvidSet(UINT32 uiPvid, UINT32 uiPriority);

OPL_STATUS dalQinqPvidReSet(UINT32 uiPvid, UINT32 uiPriority);

OPL_STATUS dal25L90ImodSet(UINT32 uiModVal);

OPL_STATUS dal25L90ApcSet(UINT32 uiApcVal);

OPL_STATUS dal25L90FTOverSet(UINT32 FTOverFLAG);
#endif
#endif
