/*++
Copyright (c) Realtek Semiconductor Corp. All rights reserved.

Module Name:
	Hal8192EAPwrSeqCmd.c
	
Abstract:
	This file includes all kinds of Power Action event for RTL8192E and 
	corresponding hardware configurtions which are released from HW SD.
	    
Major Change History:
	When       Who               What
	---------- ---------------   -------------------------------
	2012-04-16 Filen            Create.
	
--*/

#include "HalPrecomp.h"

/*
 *	drivers should parse below arrays and do the corresponding actions
 */

/*	Power on  Array	*/
WLAN_PWR_CFG rtl8192E_power_on_flow[RTL8192E_TRANS_CARDEMU_TO_ACT_STEPS+RTL8192E_TRANS_END_STEPS]=
{
	RTL8192E_TRANS_CARDEMU_TO_ACT
	RTL8192E_TRANS_END
};

/*	Radio off Array	*/
WLAN_PWR_CFG rtl8192E_radio_off_flow[RTL8192E_TRANS_ACT_TO_CARDEMU_STEPS+RTL8192E_TRANS_END_STEPS]=
{
	RTL8192E_TRANS_ACT_TO_CARDEMU
	RTL8192E_TRANS_END
};

/*	Card Disable Array	*/
WLAN_PWR_CFG rtl8192E_card_disable_flow[RTL8192E_TRANS_ACT_TO_CARDEMU_STEPS+RTL8192E_TRANS_CARDEMU_TO_PDN_STEPS+RTL8192E_TRANS_END_STEPS]=
{
	RTL8192E_TRANS_ACT_TO_CARDEMU
	RTL8192E_TRANS_CARDEMU_TO_CARDDIS
	RTL8192E_TRANS_END
};

/*	Card Enable Array	*/
WLAN_PWR_CFG rtl8192E_card_enable_flow[RTL8192E_TRANS_ACT_TO_CARDEMU_STEPS+RTL8192E_TRANS_CARDEMU_TO_PDN_STEPS+RTL8192E_TRANS_END_STEPS]=
{
	RTL8192E_TRANS_CARDDIS_TO_CARDEMU
	RTL8192E_TRANS_CARDEMU_TO_ACT
	RTL8192E_TRANS_END
};

/*	Suspend Array	*/
WLAN_PWR_CFG rtl8192E_suspend_flow[RTL8192E_TRANS_ACT_TO_CARDEMU_STEPS+RTL8192E_TRANS_CARDEMU_TO_SUS_STEPS+RTL8192E_TRANS_END_STEPS]=
{
	RTL8192E_TRANS_ACT_TO_CARDEMU
	RTL8192E_TRANS_CARDEMU_TO_SUS
	RTL8192E_TRANS_END
};

/*	Resume Array		*/
WLAN_PWR_CFG rtl8192E_resume_flow[RTL8192E_TRANS_ACT_TO_CARDEMU_STEPS+RTL8192E_TRANS_CARDEMU_TO_SUS_STEPS+RTL8192E_TRANS_END_STEPS]=
{
	RTL8192E_TRANS_SUS_TO_CARDEMU
	RTL8192E_TRANS_CARDEMU_TO_ACT
	RTL8192E_TRANS_END
};



/*	HWPDN Array		*/
WLAN_PWR_CFG rtl8192E_hwpdn_flow[RTL8192E_TRANS_ACT_TO_CARDEMU_STEPS+RTL8192E_TRANS_CARDEMU_TO_PDN_STEPS+RTL8192E_TRANS_END_STEPS]=
{
	RTL8192E_TRANS_ACT_TO_CARDEMU
	RTL8192E_TRANS_CARDEMU_TO_PDN	
	RTL8192E_TRANS_END
};

/*	Enter LPS 	*/
WLAN_PWR_CFG rtl8192E_enter_lps_flow[RTL8192E_TRANS_ACT_TO_LPS_STEPS+RTL8192E_TRANS_END_STEPS]=
{
	//FW behavior
	RTL8192E_TRANS_ACT_TO_LPS	
	RTL8192E_TRANS_END
};

/*	Leave LPS 	*/
WLAN_PWR_CFG rtl8192E_leave_lps_flow[RTL8192E_TRANS_LPS_TO_ACT_STEPS+RTL8192E_TRANS_END_STEPS]=
{
	//FW behavior
	RTL8192E_TRANS_LPS_TO_ACT
	RTL8192E_TRANS_END
};


