
/* This is RTL8328 driver files */
/*
 * ## Please DO NOT edit this file!! ##
 * This file is auto-generated from the register source files.
 * Any modifications to this file will be LOST when it is re-generated.
 *
 * ----------------------------------------------------------------
 * Copyright(c) Realtek Semiconductor Corporation, 2009
 * All rights reserved.
 *
 * Purpose : The APOLLO chip driver
 *
 * Feature : APOLLO chip driver
 *
 */

/*
 * Include Files
 */
#include <hal/chipdef/allreg.h>
#include <hal/chipdef/allmem.h>
#include <hal/chipdef/apollo/apollo_reg_struct.h>
#include <hal/chipdef/apollo/apollo_table_struct.h>
#include <hal/chipdef/apollo/apollo_tableField_list.h>
#include "hal/chipdef/chip.h"
#include "hal/chipdef/driver.h"
#include "hal/mac/drv.h"

extern rtk_table_t apollo_table_list[];

/* apollo mac driver service APIs */
rt_macdrv_t apollo_macdrv =
{
    apollo_init,          /* fMdrv_init        */
    apollo_miim_read,     /* fMdrv_miim_read   */
    apollo_miim_write,    /* fMdrv_miim_write  */
    apollo_table_read,    /* fMdrv_table_read  */
    apollo_table_write,   /* fMdrv_table_write */
}; /* end of apollo_macdrv */


/* Definition apollo major driver */
rt_driver_t apollo_driver =
{
    /* type            */ RT_DRIVER_APOLLO,
    /* RTL chip ID     */ APOLLO_CHIP_ID,
    /* RTL revision ID */ CHIP_REV_ID_0,
    /* register list   */ apollo_reg_list,
    /* table list      */ apollo_table_list,
    /* mac driver      */ &apollo_macdrv,
    /* reg index max   */ REG_LIST_END,
    /* regField index max */ REGFIELD_LIST_END,
    /* table index max */ TABLE_LIST_END,
}; /* end of apollo_driver */

/* Definition apollo major driver */
rt_driver_t apollo_driver_rev_b =
{
    /* type            */ RT_DRIVER_APOLLO_REV_B,
    /* RTL chip ID     */ APOLLO_CHIP_ID,
    /* RTL revision ID */ CHIP_REV_ID_A,
    /* register list   */ apollo_reg_list,
    /* table list      */ apollo_table_list,
    /* mac driver      */ &apollo_macdrv,
    /* reg index max   */ REG_LIST_END,
    /* regField index max */ REGFIELD_LIST_END,
    /* table index max */ TABLE_LIST_END,
}; /* end of apollo_driver */
