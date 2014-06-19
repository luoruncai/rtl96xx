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

MIB_TABLE_INFO_T gMibPriQTableInfo;
MIB_ATTR_INFO_T  gMibPriQAttrInfo[MIB_TABLE_PRIQ_ATTR_NUM];
MIB_TABLE_PRIQ_T gMibPriQDefRow;
MIB_TABLE_OPER_T gMibPriQOper;


GOS_ERROR_CODE PriQDumpMib(void* pData)
{
	MIB_TABLE_PRIQ_T *pQueue = (MIB_TABLE_PRIQ_T *)pData;
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"Priority-Q");
	OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"EntityID: %x",pQueue->EntityID);
    OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"QCfgOpt: %d",pQueue->QCfgOpt);
    OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"MaxQSize: %d",pQueue->MaxQSize);
    OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"AllocQSize: %d",pQueue->AllocQSize);
    OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"ResetInterval: %d",pQueue->ResetInterval);
    OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"Threshold: %d",pQueue->Threshold);
    OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"RelatedPort: %x",pQueue->RelatedPort);
    OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"SchedulerPtr: %x",pQueue->SchedulerPtr);
    OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"Weight: %d",pQueue->Weight);
    OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"BPOperation: %d",pQueue->BPOperation);
    OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"BPTime: %d",pQueue->BPTime);
    OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"BPOccThreshold: %d",pQueue->BPOccThreshold);
    OMCI_LOG(OMCI_LOG_LEVEL_HIGH,"BPClrThreshold: %d",pQueue->BPClrThreshold);
	
	return GOS_OK;
}


GOS_ERROR_CODE PriQDrvCfg(void* pOldRow,void* pNewRow,MIB_OPERA_TYPE  operationType)
{
	 GOS_ERROR_CODE     ret;
    MIB_TABLE_ONTG_T   ontg;
    MIB_TABLE_PRIQ_T* pNewQ;
    MIB_TABLE_PRIQ_T* pOldQ;


    pNewQ = (MIB_TABLE_TCONT_T *)pNewRow;
    pOldQ = (MIB_TABLE_TCONT_T *)pOldRow;

    ontg.EntityID = 0;
    ret = MIB_Get(MIB_TABLE_ONTG_INDEX, &ontg, sizeof(MIB_TABLE_ONTG_T));
	
    if (ret == OK)
    {
        switch (operationType)
        {
 
            case MIB_SET:
            {
                OMCI_LOG(OMCI_LOG_LEVEL_LOW,"Pri-Q ---- > SET: old priority [0x%x] new priority[0x%x]", pOldQ->RelatedPort, pNewQ->RelatedPort);
                ret = OMCI_wrapper_SetPriQueue(pNewQ);
       
                break;
            }
            
            default:
                return GOS_OK;
        }
    }
    return ret;
}


GOS_ERROR_CODE PriQ_Init(void)
{
    gMibPriQTableInfo.Name = "PriQ";
    gMibPriQTableInfo.Desc = "Priority Queue-G";
    gMibPriQTableInfo.MaxEntry = (UINT32)(168);
    gMibPriQTableInfo.ClassId = (UINT32)(277);
    gMibPriQTableInfo.InitType = (UINT32)(PON_ME_INIT_TYPE_AUTO);
    gMibPriQTableInfo.StdType = (UINT32)(PON_ME_STD_TYPE_STD);
    gMibPriQTableInfo.ActionType = (UINT32)(PON_ME_ACTION_SET | PON_ME_ACTION_GET);
    gMibPriQTableInfo.pAttributes = &(gMibPriQAttrInfo[0]);

	gMibPriQTableInfo.attrNum = MIB_TABLE_PRIQ_ATTR_NUM;
	gMibPriQTableInfo.entrySize = sizeof(MIB_TABLE_PRIQ_T);
	gMibPriQTableInfo.pDefaultRow = &gMibPriQDefRow;


    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].Name = "EntityID";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_QCFGOPT_INDEX - MIB_TABLE_FIRST_INDEX].Name = "QCfgOpt";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_MAXQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].Name = "MaxQSize";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ALLOCQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].Name = "AllocQSize";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RESETINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].Name = "ResetInterval";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_THRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].Name = "Threshold";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RELATEDPORT_INDEX - MIB_TABLE_FIRST_INDEX].Name = "RelatedPort";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_SCHEDULERPTR_INDEX - MIB_TABLE_FIRST_INDEX].Name = "SchedulerPtr";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_WEIGHT_INDEX - MIB_TABLE_FIRST_INDEX].Name = "Weight";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOPERATION_INDEX - MIB_TABLE_FIRST_INDEX].Name = "BPOperation";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPTIME_INDEX - MIB_TABLE_FIRST_INDEX].Name = "BPTime";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOCCTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].Name = "BPOccThreshold";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPCLRTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].Name = "BPClrThreshold";

    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Entity ID";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_QCFGOPT_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Queue Configuration Option";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_MAXQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Maximum Queue Size";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ALLOCQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Allocated Queue Size";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RESETINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Discard-cell/block-counter Reset Interval";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_THRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Threshold Value for Discarded Cells or Blocks due to Buffer Overflow";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RELATEDPORT_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Related Port";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_SCHEDULERPTR_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Traffic Scheduler-G Pointer";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_WEIGHT_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Weight";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOPERATION_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Back Pressure Operation";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPTIME_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Back Pressure Time";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOCCTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Back Pressure Occur Queue Threshold";
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPCLRTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].Desc = "Back Pressure Clear Queue Threshold";

    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT16;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_QCFGOPT_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_MAXQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT16;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ALLOCQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT16;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RESETINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT16;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_THRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT16;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RELATEDPORT_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT32;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_SCHEDULERPTR_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT16;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_WEIGHT_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT8;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOPERATION_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT16;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPTIME_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT32;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOCCTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT16;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPCLRTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].DataType = MIB_ATTR_TYPE_UINT16;

    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].Len = 2;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_QCFGOPT_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_MAXQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].Len = 2;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ALLOCQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].Len = 2;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RESETINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].Len = 2;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_THRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].Len = 2;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RELATEDPORT_INDEX - MIB_TABLE_FIRST_INDEX].Len = 4;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_SCHEDULERPTR_INDEX - MIB_TABLE_FIRST_INDEX].Len = 2;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_WEIGHT_INDEX - MIB_TABLE_FIRST_INDEX].Len = 1;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOPERATION_INDEX - MIB_TABLE_FIRST_INDEX].Len = 2;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPTIME_INDEX - MIB_TABLE_FIRST_INDEX].Len = 4;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOCCTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].Len = 2;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPCLRTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].Len = 2;

    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = TRUE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_QCFGOPT_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_MAXQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ALLOCQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RESETINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_THRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RELATEDPORT_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_SCHEDULERPTR_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_WEIGHT_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOPERATION_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPTIME_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOCCTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPCLRTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].IsIndex = FALSE;

    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_QCFGOPT_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_MAXQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ALLOCQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RESETINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_THRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RELATEDPORT_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_SCHEDULERPTR_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_WEIGHT_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOPERATION_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPTIME_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOCCTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPCLRTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].UsrAcc = MIB_ATTR_USR_READ_ONLY;

    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_QCFGOPT_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_MAXQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ALLOCQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RESETINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_THRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RELATEDPORT_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_SCHEDULERPTR_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_WEIGHT_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOPERATION_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPTIME_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOCCTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPCLRTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].MibSave = TRUE;

    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_HEX;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_QCFGOPT_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_MAXQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ALLOCQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RESETINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_THRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RELATEDPORT_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_HEX;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_SCHEDULERPTR_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_HEX;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_WEIGHT_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOPERATION_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPTIME_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOCCTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPCLRTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].OutStyle = MIB_ATTR_OUT_DEC;

    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_QCFGOPT_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_MAXQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ALLOCQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RESETINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_THRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RELATEDPORT_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_SCHEDULERPTR_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_WEIGHT_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOPERATION_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPTIME_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOCCTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPCLRTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].OltAcc = PON_ME_OLT_READ | PON_ME_OLT_WRITE;

    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_QCFGOPT_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_MAXQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ALLOCQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RESETINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_THRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RELATEDPORT_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_SCHEDULERPTR_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_WEIGHT_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOPERATION_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPTIME_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOCCTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPCLRTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].AvcFlag = FALSE;

    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ENTITYID_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_QCFGOPT_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_MAXQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_ALLOCQSIZE_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RESETINTERVAL_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_THRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_OPT_SUPPORT;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_RELATEDPORT_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_SCHEDULERPTR_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_WEIGHT_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOPERATION_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPTIME_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPOCCTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;
    gMibPriQAttrInfo[MIB_TABLE_PRIQ_BPCLRTHRESHOLD_INDEX - MIB_TABLE_FIRST_INDEX].OptionType = PON_ME_ATTR_MANDATORY;


    memset(&(gMibPriQDefRow.EntityID), 0x00, sizeof(gMibPriQDefRow.EntityID));
    memset(&(gMibPriQDefRow.QCfgOpt), 0x00, sizeof(gMibPriQDefRow.QCfgOpt));
    memset(&(gMibPriQDefRow.MaxQSize), 0x00, sizeof(gMibPriQDefRow.MaxQSize));
    memset(&(gMibPriQDefRow.AllocQSize), 0x00, sizeof(gMibPriQDefRow.AllocQSize));
    memset(&(gMibPriQDefRow.ResetInterval), 0x00, sizeof(gMibPriQDefRow.ResetInterval));
    memset(&(gMibPriQDefRow.Threshold), 0x00, sizeof(gMibPriQDefRow.Threshold));
    memset(&(gMibPriQDefRow.RelatedPort), 0x00, sizeof(gMibPriQDefRow.RelatedPort));
    memset(&(gMibPriQDefRow.SchedulerPtr), 0x00, sizeof(gMibPriQDefRow.SchedulerPtr));
    memset(&(gMibPriQDefRow.Weight), 0x00, sizeof(gMibPriQDefRow.Weight));
    memset(&(gMibPriQDefRow.BPOperation), 0x00, sizeof(gMibPriQDefRow.BPOperation));
    memset(&(gMibPriQDefRow.BPTime), 0x00, sizeof(gMibPriQDefRow.BPTime));
    memset(&(gMibPriQDefRow.BPOccThreshold), 0x00, sizeof(gMibPriQDefRow.BPOccThreshold));
    memset(&(gMibPriQDefRow.BPClrThreshold), 0x00, sizeof(gMibPriQDefRow.BPClrThreshold));

	gMibPriQOper.meOperDrvCfg = PriQDrvCfg;
	gMibPriQOper.meOperConnCheck = NULL;
	gMibPriQOper.meOperDump = PriQDumpMib;
	gMibPriQOper.meOperConnCfg = NULL;

	MIB_Register(MIB_TABLE_PRIQ_INDEX,&gMibPriQTableInfo,&gMibPriQOper);

    return GOS_OK;
}


