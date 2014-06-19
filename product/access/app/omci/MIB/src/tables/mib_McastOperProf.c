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

MIB_TABLE_INFO_T gMibMcastOperProfTableInfo;
MIB_ATTR_INFO_T  gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ATTR_NUM];
MIB_TABLE_MCASTOPERPROF_T gMibMcastOperProfDefRow;
MIB_TABLE_OPER_T gMibMcastOperProfOper;


GOS_ERROR_CODE McastOperProfDumpMib(void *pData)
{
	MIB_TABLE_MCASTOPERPROF_T *pMcastOperProf = (MIB_TABLE_MCASTOPERPROF_T*)pData;
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"%s", "McastOperProf");

	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"EntityId: 0x%02x", pMcastOperProf->EntityId);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"IGMPVersion: %d", pMcastOperProf->IGMPVersion);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"IGMPFun: %d", pMcastOperProf->IGMPFun);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"ImmediateLeave: %d", pMcastOperProf->ImmediateLeave);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"UsIGMPTci: 0x%02x", pMcastOperProf->UsIGMPTci);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"UsIGMPTagControl: %d", pMcastOperProf->UsIGMPTagControl);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"UsIGMPRate: %d", pMcastOperProf->UsIGMPRate);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"DyACLTable: %s", pMcastOperProf->DyACLTable);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"DiscussionOfTableSize: %d", pMcastOperProf->DiscussionOfTableSize);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"StaticACLTable: %s", pMcastOperProf->StaticACLTable);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"LostGroupListTable: %s", pMcastOperProf->LostGroupListTable);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"Robustness: %d", pMcastOperProf->Robustness);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"QuerierIpAddress: 0x%02x", pMcastOperProf->QuerierIpAddress);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"QueryInterval: %d", pMcastOperProf->QueryInterval);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"QueryMaxResponseTime: %d", pMcastOperProf->QueryMaxResponseTime);
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"LastMemberQueryInterval: %d", pMcastOperProf->LastMemberQueryInterval);

	return GOS_OK;
}

GOS_ERROR_CODE McastOperProfDrvCfg(MIB_TABLE_INDEX tableIdx, void* pOldRow, void* pNewRow, MIB_OPERA_TYPE operationType)
{
	OMCI_LOG(OMCI_LOG_LEVEL_LOW,"%s: process end\n", __FUNCTION__);
	return GOS_OK;
}

GOS_ERROR_CODE McastOperProf_Init(void)
{
    gMibMcastOperProfTableInfo.Name = "McastOperProf";
    gMibMcastOperProfTableInfo.Desc = "Multicast Operation Profile";
    gMibMcastOperProfTableInfo.MaxEntry = (UINT32)(32);
    gMibMcastOperProfTableInfo.ClassId = (UINT32)(309);
    gMibMcastOperProfTableInfo.InitType = (UINT32)(PON_ME_INIT_TYPE_BY_OLT);
    gMibMcastOperProfTableInfo.StdType = (UINT32)(PON_ME_STD_TYPE_STD);
    gMibMcastOperProfTableInfo.ActionType = (UINT32)(PON_ME_ACTION_CREATE | PON_ME_ACTION_DELETE | PON_ME_ACTION_SET | PON_ME_ACTION_GET | PON_ME_ACTION_GET_NEXT);
    gMibMcastOperProfTableInfo.pAttributes = &(gMibMcastOperProfAttrInfo[0]);

	gMibMcastOperProfTableInfo.attrNum = MIB_TABLE_MCASTOPERPROF_ATTR_NUM;
	gMibMcastOperProfTableInfo.entrySize = sizeof(MIB_TABLE_MCASTOPERPROF_T);
	gMibMcastOperProfTableInfo.pDefaultRow = &gMibMcastOperProfDefRow;

    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].Name = "EntityId";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPVERSION_INDEX - MIB_TABLE_FIRST_INDEX].Name = "IGMPVersion";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPFUN_INDEX - MIB_TABLE_FIRST_INDEX].Name = "IGMPFun";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IMMEDIATELEAVE_INDEX - MIB_TABLE_FIRST_INDEX].Name = "ImmediateLeave";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTCI_INDEX - MIB_TABLE_FIRST_INDEX].Name = "UsIGMPTci";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTAGCONTROL_INDEX - MIB_TABLE_FIRST_INDEX].Name = "UsIGMPTagControl";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPRATE_INDEX - MIB_TABLE_FIRST_INDEX].Name = "UsIGMPRate";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DYACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].Name = "DyACLTable";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DISCUSSIONOFTABLESIZE_INDEX - MIB_TABLE_FIRST_INDEX].Name = "DiscussionOfTableSize";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_STATICACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].Name = "StaticACLTable";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LOSTGROUPLISTTABLE_INDEX - MIB_TABLE_FIRST_INDEX].Name = "LostGroupListTable";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ROBUSTNESS_INDEX - MIB_TABLE_FIRST_INDEX].Name = "Robustness";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERIERIPADDRESS_INDEX - MIB_TABLE_FIRST_INDEX].Name = "QuerierIpAddress";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].Name = "QueryInterval";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYMAXRESPONSETIME_INDEX - MIB_TABLE_FIRST_INDEX].Name = "QueryMaxResponseTime";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LASTMEMBERQUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].Name = "LastMemberQueryInterval";

    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Entity ID";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPVERSION_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "IGMP version";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPFUN_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "IGMP function";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IMMEDIATELEAVE_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Support Immediate Leave";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTCI_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Upstream IGMP TCI";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTAGCONTROL_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Upstream IGMP Tag Control";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPRATE_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Upstream IGMP rate";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DYACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Dynamic Access Control List table";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DISCUSSIONOFTABLESIZE_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Discussion of table size";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_STATICACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Static Access control list table";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LOSTGROUPLISTTABLE_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Lost group list table";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ROBUSTNESS_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Robustness";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERIERIPADDRESS_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Querier IP Address";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Query interval";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYMAXRESPONSETIME_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Query max response time";
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LASTMEMBERQUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "IGMP function";

    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT16;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPVERSION_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPFUN_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IMMEDIATELEAVE_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTCI_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT16;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTAGCONTROL_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPRATE_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT32;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DYACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_STR;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DISCUSSIONOFTABLESIZE_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_STATICACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_STR;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LOSTGROUPLISTTABLE_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_STR;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ROBUSTNESS_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERIERIPADDRESS_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT32;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT32;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYMAXRESPONSETIME_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT32;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LASTMEMBERQUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT32;

    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].Len = 2;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPVERSION_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPFUN_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IMMEDIATELEAVE_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTCI_INDEX - MIB_TABLE_FIRST_INDEX].Len = 2;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTAGCONTROL_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPRATE_INDEX - MIB_TABLE_FIRST_INDEX].Len = 4;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DYACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].Len = 24;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DISCUSSIONOFTABLESIZE_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_STATICACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].Len = 24;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LOSTGROUPLISTTABLE_INDEX - MIB_TABLE_FIRST_INDEX].Len = 10;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ROBUSTNESS_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERIERIPADDRESS_INDEX - MIB_TABLE_FIRST_INDEX].Len = 4;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].Len = 4;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYMAXRESPONSETIME_INDEX - MIB_TABLE_FIRST_INDEX].Len = 4;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LASTMEMBERQUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].Len = 4;

    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = TRUE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPVERSION_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPFUN_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IMMEDIATELEAVE_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTCI_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTAGCONTROL_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPRATE_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DYACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DISCUSSIONOFTABLESIZE_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_STATICACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LOSTGROUPLISTTABLE_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ROBUSTNESS_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERIERIPADDRESS_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYMAXRESPONSETIME_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LASTMEMBERQUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;

    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPVERSION_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPFUN_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IMMEDIATELEAVE_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTCI_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTAGCONTROL_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPRATE_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DYACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DISCUSSIONOFTABLESIZE_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_STATICACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LOSTGROUPLISTTABLE_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ROBUSTNESS_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERIERIPADDRESS_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYMAXRESPONSETIME_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LASTMEMBERQUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_WRITE;

    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPVERSION_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPFUN_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IMMEDIATELEAVE_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTCI_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTAGCONTROL_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPRATE_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DYACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DISCUSSIONOFTABLESIZE_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_STATICACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LOSTGROUPLISTTABLE_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ROBUSTNESS_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERIERIPADDRESS_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYMAXRESPONSETIME_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LASTMEMBERQUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;

    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_HEX;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPVERSION_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPFUN_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IMMEDIATELEAVE_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTCI_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_HEX;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTAGCONTROL_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPRATE_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DYACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_CHAR;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DISCUSSIONOFTABLESIZE_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_STATICACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_CHAR;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LOSTGROUPLISTTABLE_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_CHAR;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ROBUSTNESS_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERIERIPADDRESS_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_HEX;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYMAXRESPONSETIME_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LASTMEMBERQUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;

    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPVERSION_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPFUN_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IMMEDIATELEAVE_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTCI_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTAGCONTROL_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPRATE_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DYACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DISCUSSIONOFTABLESIZE_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_STATICACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LOSTGROUPLISTTABLE_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ROBUSTNESS_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERIERIPADDRESS_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYMAXRESPONSETIME_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LASTMEMBERQUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;

    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPVERSION_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPFUN_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IMMEDIATELEAVE_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTCI_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTAGCONTROL_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPRATE_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DYACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DISCUSSIONOFTABLESIZE_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_STATICACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LOSTGROUPLISTTABLE_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = TRUE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ROBUSTNESS_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERIERIPADDRESS_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYMAXRESPONSETIME_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LASTMEMBERQUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;

    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPVERSION_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IGMPFUN_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_IMMEDIATELEAVE_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTCI_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPTAGCONTROL_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_USIGMPRATE_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DYACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_DISCUSSIONOFTABLESIZE_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_STATICACLTABLE_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LOSTGROUPLISTTABLE_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_ROBUSTNESS_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERIERIPADDRESS_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_QUERYMAXRESPONSETIME_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;
    gMibMcastOperProfAttrInfo[MIB_TABLE_MCASTOPERPROF_LASTMEMBERQUERYINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;

    memset(&(gMibMcastOperProfDefRow.EntityId), 0x00, sizeof(gMibMcastOperProfDefRow.EntityId));
    memset(&(gMibMcastOperProfDefRow.IGMPVersion), 0x02, sizeof(gMibMcastOperProfDefRow.IGMPVersion));
    memset(&(gMibMcastOperProfDefRow.IGMPFun), 0x00, sizeof(gMibMcastOperProfDefRow.IGMPFun));
    memset(&(gMibMcastOperProfDefRow.ImmediateLeave), 0x00, sizeof(gMibMcastOperProfDefRow.ImmediateLeave));
    memset(&(gMibMcastOperProfDefRow.UsIGMPTci), 0x00, sizeof(gMibMcastOperProfDefRow.UsIGMPTci));
    memset(&(gMibMcastOperProfDefRow.UsIGMPTagControl), 0x00, sizeof(gMibMcastOperProfDefRow.UsIGMPTagControl));
    memset(&(gMibMcastOperProfDefRow.UsIGMPRate), 0x00, sizeof(gMibMcastOperProfDefRow.UsIGMPRate));
    strncpy(&(gMibMcastOperProfDefRow.DyACLTable), "0", sizeof(gMibMcastOperProfDefRow.DyACLTable));
    memset(&(gMibMcastOperProfDefRow.DiscussionOfTableSize), 0x00, sizeof(gMibMcastOperProfDefRow.DiscussionOfTableSize));
    strncpy(&(gMibMcastOperProfDefRow.StaticACLTable), "0", sizeof(gMibMcastOperProfDefRow.StaticACLTable));
    strncpy(&(gMibMcastOperProfDefRow.LostGroupListTable), "0", sizeof(gMibMcastOperProfDefRow.LostGroupListTable));
    memset(&(gMibMcastOperProfDefRow.Robustness), 0x00, sizeof(gMibMcastOperProfDefRow.Robustness));
    memset(&(gMibMcastOperProfDefRow.QuerierIpAddress), 0x00, sizeof(gMibMcastOperProfDefRow.QuerierIpAddress));
    memset(&(gMibMcastOperProfDefRow.QueryInterval), 0x00, sizeof(gMibMcastOperProfDefRow.QueryInterval));
    memset(&(gMibMcastOperProfDefRow.QueryMaxResponseTime), 0x00, sizeof(gMibMcastOperProfDefRow.QueryMaxResponseTime));
    memset(&(gMibMcastOperProfDefRow.LastMemberQueryInterval), 0x10, sizeof(gMibMcastOperProfDefRow.LastMemberQueryInterval));

    gMibMcastOperProfOper.meOperDrvCfg = McastOperProfDrvCfg;
    gMibMcastOperProfOper.meOperConnCheck = NULL;
    gMibMcastOperProfOper.meOperDump = McastOperProfDumpMib;
	gMibMcastOperProfOper.meOperConnCfg = NULL;

    MIB_Register(MIB_TABLE_MCASTOPERPROF_INDEX, &gMibMcastOperProfTableInfo, &gMibMcastOperProfOper);

    return GOS_OK;
}

