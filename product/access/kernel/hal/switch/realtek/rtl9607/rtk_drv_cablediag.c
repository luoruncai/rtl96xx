/*****************************************************************************

                                                                             
*****************************************************************************/
#ifdef  __cplusplus
    extern "C"{
#endif
#include <lw_type.h>
#include "lw_drv_pub.h"
#include "lw_drv_req.h"
#include "hal_common.h"
/*realtek sdk include*/
#include <common/error.h>
#include <common/rt_error.h>
#include <rtk/port.h>

#include <linux/delay.h>
#include <linux/string.h>





/*****************************************************************************
    Func Name:  Hal_GetCableDiag
  Description:  get cable diag
        Input:  lport
                pstDiag
       Output: 
       Return:  DRV_ERR_PARA
                DRV_ERR_UNKNOW
                DRV_OK
      Caution: 
------------------------------------------------------------------------------
  Modification History                                                      
  DATE        NAME             DESCRIPTION                                  
  --------------------------------------------------------------------------
                                                                            
*****************************************************************************/
DRV_RET_E Hal_GetCableDiag(port_num_t lport, cable_diag_t *pstDiag)
{
    UINT32 i;
    logic_pmask_t lportMask;
    phy_pmask_t stPhyMask;
    INT retVal;
    rtk_rtctResult_t stRtctResult;
	UINT32 uiCnt = 0;
    UINT32 unit;
    UINT16 uiLen;
    UINT16 uiResidule;

	
    if(pstDiag == NULL)
    {
        return DRV_ERR_PARA;
    }

    if(!IsValidLgcPort(lport))
    {
        return DRV_ERR_PARA;
    }    

    memset(pstDiag, 0, sizeof(cable_diag_t));
    memset(&stRtctResult, 0, sizeof(rtk_rtctResult_t));
    ClrLgcMaskAll(&lportMask);
    SetLgcMaskBit(lport, &lportMask);
    MaskLogic2Phy(&lportMask, &stPhyMask);
    retVal = rtk_port_rtct_start(&(CHIPNMASK(0, &stPhyMask)));
    if(retVal != RT_ERR_OK)
    {
        return DRV_ERR_UNKNOW;
    }

    do
    {
        retVal = rtk_port_rtctResult_get(PortLogic2PhyPortId(lport), &stRtctResult);
		uiCnt++;
        if(retVal == RT_ERR_PHY_RTCT_NOT_FINISH)
        {
            msleep(1000);
        }
    }
	/* 014091 */
	while((retVal == RT_ERR_PHY_RTCT_NOT_FINISH) && (uiCnt <= 4));/* 限制最大时常4秒 */
    if(retVal != RT_ERR_OK)
    {
        return DRV_ERR_UNKNOW;
    }
    
    pstDiag->state = CABLE_STATE_OK;
    pstDiag->fuzz_len = 5;
    if((stRtctResult.linkType == PORT_SPEED_10M) || (stRtctResult.linkType == PORT_SPEED_100M))
    {
        pstDiag->npairs = 2;
		pstDiag->pair_len[0] =  (UINT16)(stRtctResult.fe_result.rxLen);
        pstDiag->pair_len[1] =  (UINT16)(stRtctResult.fe_result.txLen);        
        if(stRtctResult.fe_result.isRxShort)
        {
            pstDiag->pair_state[0] = CABLE_STATE_SHORT;
            pstDiag->state = CABLE_STATE_SHORT;
        }
        if(stRtctResult.fe_result.isTxShort)
        {
            pstDiag->pair_state[1] = CABLE_STATE_SHORT;
            pstDiag->state = CABLE_STATE_SHORT;
        }
        if(stRtctResult.fe_result.isRxOpen)
        {
            pstDiag->pair_state[0] = CABLE_STATE_OPEN;
            pstDiag->state = CABLE_STATE_OPEN;
        }
        if(stRtctResult.fe_result.isTxOpen)
        {
            pstDiag->pair_state[1] = CABLE_STATE_OPEN;
            pstDiag->state = CABLE_STATE_OPEN;
        }
		for(i = 0; i < (pstDiag->npairs); i++)
	    {
	        
	        uiLen = (pstDiag->pair_len[i])/100;
	        uiResidule = (pstDiag->pair_len[i])%100;
	        if(uiResidule >= 50)
	        {
	            uiLen++;
	        }
	        pstDiag->pair_len[i] = uiLen;			
	    }
    }
    else if(stRtctResult.linkType == PORT_SPEED_1000M)
    {
        pstDiag->npairs = 4;
        pstDiag->pair_len[0] =  (UINT16)(stRtctResult.ge_result.channelALen);
        pstDiag->pair_len[1] =  (UINT16)(stRtctResult.ge_result.channelBLen);
        pstDiag->pair_len[2] =  (UINT16)(stRtctResult.ge_result.channelCLen);
        pstDiag->pair_len[3] =  (UINT16)(stRtctResult.ge_result.channelDLen);
        if(stRtctResult.ge_result.channelAShort)
        {
            pstDiag->pair_state[0] = CABLE_STATE_SHORT;
            pstDiag->state = CABLE_STATE_SHORT;
        }
        if(stRtctResult.ge_result.channelBShort)
        {
            pstDiag->pair_state[1] = CABLE_STATE_SHORT;
            pstDiag->state = CABLE_STATE_SHORT;
        }
        if(stRtctResult.ge_result.channelCShort)
        {
            pstDiag->pair_state[2] = CABLE_STATE_SHORT;
            pstDiag->state = CABLE_STATE_SHORT;
        }
        if(stRtctResult.ge_result.channelDShort)
        {
            pstDiag->pair_state[3] = CABLE_STATE_SHORT;
            pstDiag->state = CABLE_STATE_SHORT;
        }
        if(stRtctResult.ge_result.channelAOpen)
        {
            pstDiag->pair_state[0] = CABLE_STATE_OPEN;
            pstDiag->state = CABLE_STATE_OPEN;
        }
        if(stRtctResult.ge_result.channelBOpen)
        {
            pstDiag->pair_state[1] = CABLE_STATE_OPEN;
            pstDiag->state = CABLE_STATE_OPEN;
        }
        if(stRtctResult.ge_result.channelCOpen)
        {
            pstDiag->pair_state[2] = CABLE_STATE_OPEN;
            pstDiag->state = CABLE_STATE_OPEN;
        }
        if(stRtctResult.ge_result.channelDOpen)
        {
            pstDiag->pair_state[3] = CABLE_STATE_OPEN;
            pstDiag->state = CABLE_STATE_OPEN;
        }
		for(i = 0; i < (pstDiag->npairs); i++)
	    {
	        pstDiag->pair_len[i] = (UINT16)((pstDiag->pair_len[i] * 25)/1000);
	    }
   
    }
    else
    {
        return DRV_ERR_UNKNOW;
    }
     return DRV_OK;
}


#ifdef  __cplusplus
}
#endif

