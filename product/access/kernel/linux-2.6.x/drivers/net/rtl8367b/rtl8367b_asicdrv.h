#ifndef _RTL8367B_ASICDRV_H_
#define _RTL8367B_ASICDRV_H_

#include "rtk_types.h"
#include "rtk_error.h"
#include "rtl8367b_reg.h"
#include "rtl8367b_base.h"
#include "rtl8367b_asicdrv_vlan_para.h"

#define RTL8367B_REGBITLENGTH               16
#define RTL8367B_REGDATAMAX                 0xFFFF

#define RTL8367B_VIDMAX                     RL6000_VLAN_NUM
#define RTL8367B_EVIDMAX                    0x1FFF
#define RTL8367B_CVIDXNO                    32
#define RTL8367B_CVIDXMAX                   (RTL8367B_CVIDXNO-1)

#define RTL8367B_PRIMAX                     7
#define RTL8367B_DSCPMAX    				63

#define RTL8367B_PORTNO                     8
#define RTL8367B_PORTIDMAX                  (RTL8367B_PORTNO-1)
#define RTL8367B_PMSKMAX                    ((1<<(RTL8367B_PORTNO))-1)
#define RTL8367B_PORTMASK                   0xFF

#define RTL8367B_PHYNO                      5
#define RTL8367B_PHYIDMAX                  (RTL8367B_PHYNO-1)

#define RTL8367B_SVIDXNO                    64
#define RTL8367B_SVIDXMAX                   (RTL8367B_SVIDXNO-1)
#define RTL8367B_MSTIMAX                    15

#define RTL8367B_METERNO                    32
#define RTL8367B_METERMAX                   (RTL8367B_METERNO-1)
#define RTL8367B_METERBUCKETSIZEMAX         0xFFFF

#define RTL8367B_QUEUENO                    8
#define RTL8367B_QIDMAX                     (RTL8367B_QUEUENO-1)

#define RTL8367B_PHY_BUSY_CHECK_COUNTER     1000

#define RTL8367B_QOS_GRANULARTY_MAX         0x1FFFF
#define RTL8367B_QOS_GRANULARTY_LSB_MASK    0xFFFF
#define RTL8367B_QOS_GRANULARTY_LSB_OFFSET  0
#define RTL8367B_QOS_GRANULARTY_MSB_MASK    0x10000
#define RTL8367B_QOS_GRANULARTY_MSB_OFFSET  16

#define RTL8367B_QOS_GRANULARTY_UNIT_KBPS   8

#define RTL8367B_QOS_RATE_INPUT_MAX         (0x1FFFF * 8)
#define RTL8367B_QOS_RATE_INPUT_MIN         8

#define RTL8367B_QUEUE_MASK                 0xFF

#define RTL8367B_EFIDMAX                    0x7
#define RTL8367B_FIDMAX                     0xF

#define RTL8367B_GPIOPINNO                  14
#define RTL8367B_GPIOPINMAX                 (RTL8367B_GPIOPINNO-1)

/* the above macro is generated by genDotH */
#define RTL8367B_VALID_REG_NO               3869


#define RTL8367B_LUT_LEARNLIMITMAX      (0x840)


/*=======================================================================
 *  Enum
 *========================================================================*/
enum RTL8367B_TABLE_ACCESS_OP
{
    TB_OP_READ = 0,
    TB_OP_WRITE
};

enum RTL8367B_TABLE_ACCESS_TARGET
{
    TB_TARGET_ACLRULE = 1,
    TB_TARGET_ACLACT,
    TB_TARGET_CVLAN,
    TB_TARGET_L2,
    TB_TARGET_IGMP_GROUP
};

#define RTL8367B_TABLE_ACCESS_REG_DATA(op, target)    ((op << 3) | target)

/*=======================================================================
 *  Structures
 *========================================================================*/


typedef struct   smi_ether_addr_s{

#ifdef _LITTLE_ENDIAN
    rtk_uint16  mac0:8;
    rtk_uint16  mac1:8;
    rtk_uint16  mac2:8;
    rtk_uint16  mac3:8;
    rtk_uint16  mac4:8;
    rtk_uint16  mac5:8;
#else
    rtk_uint16  mac1:8;
    rtk_uint16  mac0:8;
    rtk_uint16  mac3:8;
    rtk_uint16  mac2:8;
    rtk_uint16  mac5:8;
    rtk_uint16  mac4:8;
#endif

}smi_ether_addr_t;


#ifdef __cplusplus
extern "C" {
#endif
extern ret_t rtl8367b_setAsicRegBit(rtk_uint32 reg, rtk_uint32 bit, rtk_uint32 value);
extern ret_t rtl8367b_getAsicRegBit(rtk_uint32 reg, rtk_uint32 bit, rtk_uint32 *pValue);

extern ret_t rtl8367b_setAsicRegBits(rtk_uint32 reg, rtk_uint32 bits, rtk_uint32 value);
extern ret_t rtl8367b_getAsicRegBits(rtk_uint32 reg, rtk_uint32 bits, rtk_uint32 *pValue);

extern ret_t rtl8367b_setAsicReg(rtk_uint32 reg, rtk_uint32 value);
extern ret_t rtl8367b_getAsicReg(rtk_uint32 reg, rtk_uint32 *pValue);

#ifdef __cplusplus
}
#endif



#endif /*#ifndef _RTL8367B_ASICDRV_H_*/

