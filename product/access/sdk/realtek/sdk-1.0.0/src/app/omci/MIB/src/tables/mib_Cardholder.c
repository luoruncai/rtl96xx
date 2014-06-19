/*
 * Copyright (C) 2012 Realtek Semiconductor Corp. 
 * All Rights Reserved.
 *
 * This program is the proprietary software of Realtek Semiconductor
 * Corporation and/or its licensors, and only be used, duplicated, 
 * modified or distributed under the authorized license from Realtek. 
 *
 * ANY USE OF THE SOFTWARE OTHER THAN AS AUTHORIZED UNDER 
 * THIS LICENSE OR COPYRIGHT LAW IS PROHIBITED. 
 *
 */


#include "app_basic.h"
#include "omci_defs.h"


MIB_TABLE_INFO_T gMibCardholderTableInfo;
MIB_ATTR_INFO_T  gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ATTR_NUM];
MIB_TABLE_CARDHOLDER_T gMibCardholderDefRow;
MIB_TABLE_OPER_T gMibCardholderOper;


GOS_ERROR_CODE CardholderDumpMib(void* pData)
{
	MIB_TABLE_CARDHOLDER_T *pCardHolder = (MIB_TABLE_CARDHOLDER_T*)pData;
	
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"%s\n","CardHolder");	
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"EntityID: 0x%02x",pCardHolder->EntityID);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"ActualEqtID: %s",pCardHolder->ActualEqtID);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"ActualType: %d",pCardHolder->ActualType);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"ExpectedEqtID: %d",pCardHolder->ExpectedEqtID);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"ExpectedPortCount: %d",pCardHolder->ExpectedPortCount);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"ExpectedType: %d",pCardHolder->ExpectedType);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"InvokeProtSwitch: %d",pCardHolder->InvokeProtSwitch);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"ProtPrfPtr: 0x%02x",pCardHolder->ProtPrfPtr);
	return GOS_OK;
}


GOS_ERROR_CODE CardholderDrvCfg(void* pOldRow,void* pNewRow,MIB_OPERA_TYPE  operationType)
{
	OMCI_LOG(OMCI_LOG_LEVEL_LOW,"%s: process end\n",__FUNCTION__);
	return GOS_OK;
}


GOS_ERROR_CODE Cardholder_Init(void)
{
    gMibCardholderTableInfo.Name = "Cardholder";
    gMibCardholderTableInfo.Desc = "Cardholder";
    gMibCardholderTableInfo.MaxEntry = (UINT32)(8);
    gMibCardholderTableInfo.ClassId = (UINT32)(5);
    gMibCardholderTableInfo.InitType = (UINT32)(PON_ME_INIT_TYPE_AUTO);
    gMibCardholderTableInfo.StdType = (UINT32)(PON_ME_STD_TYPE_STD);
    gMibCardholderTableInfo.ActionType = (UINT32)(PON_ME_ACTION_SET | PON_ME_ACTION_GET);
    gMibCardholderTableInfo.pAttributes = &(gMibCardholderAttrInfo[0]);
	gMibCardholderTableInfo.attrNum = MIB_TABLE_CARDHOLDER_ATTR_NUM;
	gMibCardholderTableInfo.entrySize = sizeof(MIB_TABLE_CARDHOLDER_T);
	gMibCardholderTableInfo.pDefaultRow = &gMibCardholderDefRow;

    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].Name = "EntityID";
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALTYPE_INDEX - MIB_TABLE_FIRST_INDEX].Name = "ActualType";
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDTYPE_INDEX - MIB_TABLE_FIRST_INDEX].Name = "ExpectedType";
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDPORTCOUNT_INDEX - MIB_TABLE_FIRST_INDEX].Name = "ExpectedPortCount";
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDEQTID_INDEX - MIB_TABLE_FIRST_INDEX].Name = "ExpectedEqtID";
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALEQTID_INDEX - MIB_TABLE_FIRST_INDEX].Name = "ActualEqtID";
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_PROTPRFPTR_INDEX - MIB_TABLE_FIRST_INDEX].Name = "ProtPrfPtr";
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_INVOKEPROTSWITCH_INDEX - MIB_TABLE_FIRST_INDEX].Name = "InvokeProtSwitch";

    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Entity ID";
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALTYPE_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Actual Plug-in unit Type";
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDTYPE_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Expected Plug-in unit Type";
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDPORTCOUNT_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Expected port count";
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDEQTID_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Expected equipment ID";
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALEQTID_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Actual equipment ID";
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_PROTPRFPTR_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Protection profile pointer";
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_INVOKEPROTSWITCH_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Invoke protection switch";

    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT16;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALTYPE_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDTYPE_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDPORTCOUNT_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDEQTID_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_STR;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALEQTID_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_STR;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_PROTPRFPTR_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_INVOKEPROTSWITCH_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;

    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].Len = 2;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALTYPE_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDTYPE_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDPORTCOUNT_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDEQTID_INDEX - MIB_TABLE_FIRST_INDEX].Len = 20;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALEQTID_INDEX - MIB_TABLE_FIRST_INDEX].Len = 20;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_PROTPRFPTR_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_INVOKEPROTSWITCH_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;

    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = TRUE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALTYPE_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDTYPE_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDPORTCOUNT_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDEQTID_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALEQTID_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_PROTPRFPTR_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_INVOKEPROTSWITCH_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;

    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALTYPE_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDTYPE_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDPORTCOUNT_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDEQTID_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALEQTID_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_PROTPRFPTR_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_INVOKEPROTSWITCH_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;

    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALTYPE_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = FALSE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDTYPE_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDPORTCOUNT_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDEQTID_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALEQTID_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = FALSE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_PROTPRFPTR_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_INVOKEPROTSWITCH_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;

    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_HEX;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALTYPE_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDTYPE_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDPORTCOUNT_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDEQTID_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_CHAR;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALEQTID_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_CHAR;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_PROTPRFPTR_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_INVOKEPROTSWITCH_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;

    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALTYPE_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDTYPE_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDPORTCOUNT_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDEQTID_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALEQTID_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_PROTPRFPTR_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_INVOKEPROTSWITCH_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;

    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALTYPE_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = TRUE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDTYPE_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDPORTCOUNT_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDEQTID_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALEQTID_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = TRUE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_PROTPRFPTR_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_INVOKEPROTSWITCH_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;

    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALTYPE_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDTYPE_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDPORTCOUNT_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_EXPECTEDEQTID_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_ACTUALEQTID_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_PROTPRFPTR_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_NOT_SUPPORT;
    gMibCardholderAttrInfo[MIB_TABLE_CARDHOLDER_INVOKEPROTSWITCH_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_NOT_SUPPORT;


    memset(&(gMibCardholderDefRow.EntityID), 0x00, sizeof(gMibCardholderDefRow.EntityID));
    memset(&(gMibCardholderDefRow.ActualType), 0x00, sizeof(gMibCardholderDefRow.ActualType));
    memset(&(gMibCardholderDefRow.ExpectedType), 0x00, sizeof(gMibCardholderDefRow.ExpectedType));
    memset(&(gMibCardholderDefRow.ExpectedPortCount), 0x00, sizeof(gMibCardholderDefRow.ExpectedPortCount));
    memset(gMibCardholderDefRow.ExpectedEqtID, ' ', MIB_TABLE_CARDHOLDER_EXPECTEDEQTID_LEN);
    gMibCardholderDefRow.ExpectedEqtID[MIB_TABLE_CARDHOLDER_EXPECTEDEQTID_LEN] = '\0';
    memset(gMibCardholderDefRow.ActualEqtID, ' ', MIB_TABLE_CARDHOLDER_ACTUALEQTID_LEN);
    gMibCardholderDefRow.ActualEqtID[MIB_TABLE_CARDHOLDER_ACTUALEQTID_LEN] = '\0';
    memset(&(gMibCardholderDefRow.ProtPrfPtr), 0x00, sizeof(gMibCardholderDefRow.ProtPrfPtr));
    memset(&(gMibCardholderDefRow.InvokeProtSwitch), 0x00, sizeof(gMibCardholderDefRow.InvokeProtSwitch));


	gMibCardholderOper.meOperDrvCfg = CardholderDrvCfg;
	gMibCardholderOper.meOperConnCheck = NULL;
	gMibCardholderOper.meOperDump = CardholderDumpMib;
	gMibCardholderOper.meOperConnCfg = NULL;

	MIB_Register(MIB_TABLE_CARDHOLDER_INDEX,&gMibCardholderTableInfo,&gMibCardholderOper);

    return GOS_OK;
}


