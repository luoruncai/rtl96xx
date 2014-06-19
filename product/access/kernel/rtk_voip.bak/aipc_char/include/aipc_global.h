#ifndef _AIPC_GLOBAL_H_
#define _AIPC_GLOBAL_H_

/*
*	Reserve SRAM 128KB for GPON use
*/
#define GPON_RESV		1
#if !defined(CONFIG_RTL8686_ASIC_TEST_IP)
#define INTQ_READY 		1
#endif
/*
*	IPC control plane and data plane test
*/
//#define AIPC_CACHE_FLUSH	1

#define QUEUE_OPERATION_CNT	1

/*
*	IPC module parameters
*/
#define AIPC_MODULE_VOIP_IP_ENABLE		1
#define AIPC_MODULE_VOIP_SET_PCM_FS		1
#define AIPC_MODULE_INIT_ZONE_ENTRY		1
#define AIPC_MODULE_DISALBE_WDOG		1
#define AIPC_MODULE_UART1_PINMUX		1


/*
*	IPC control plane and data plane test
*/
#ifdef CONFIG_RTL8686_IPC_TEST_THREAD
#define CPU_CTRL_TEST	1
#define CPU_DATA_TEST	1
#define DSP_CTRL_TEST	1
#define DSP_DATA_TEST	1

#define CPU_SEND_NOFBK	1
#define CPU_SEND_FBK	1
#endif

#define INT_NOTIFY_DATA_2CPU	1
//#define INT_NOTIFY_DATA_2DSP	1		//disabled by default.

/*
*	DSP use DSR for handling
*/
#define CPU_DSR_SUPPORT		1
#define DSP_DSR_SUPPORT		1


/*
*	Parameter definitions
*/
#define MUL		1		//Multiplication of thread execution period time
//#define MUL		100		//Use 100 for print message test. 10 for high speed test



/*
*	Boot DSP delay
*/
//#define BOOT_DSP_DELAY
#ifdef BOOT_DSP_DELAY
#define BOOT_DSP_DELAY_TIME	3000
#endif

#define KICK_DSP_DELAY_TIME	4
#define RESET_SLIC_DELAY_TIME 5
#define KERNEL_BOOT_DELAY_TIME 5000

/*
*	Concurrent lock for IPC
*/
#define MBOX_LOCK
#define INTQ_LOCK
#define IRQ_LOCK
#define CTRL_LOCK
//#define ISR_DSR_LOCK


#define IRQ_LOOP_PROTECT
//#define CTRL_MORE_THREADS
#define CTRL_WAIT_PROC

#define INT_COUNT

/*
*	Reboot Test Thread
*/
//#define REBOOT_THREAD

/*
*	Statistics
*/
#define	STATS_RETRY
#ifdef  STATS_RETRY
#define STATS_CTRL_RETRY_MAX    0xffff
#endif

/*
*	CTRL Limit
*/
#define CTRL_SEND_LIMIT
#ifdef  CTRL_SEND_LIMIT
#define CTRL_SEND_RETRY_MAX     0xffff
#endif

/*
*	HW MUTEX
*/
//#define IPC_HW_MUTEX_ASM	1
//#define IPC_HW_MUTEX_CCODE	1



/*
*	Refine
*/
//#define INT_QUEUE_FLUSH			1
#define SCAN_INT_LOW_QUEUE		1

#define REFINE_SHM_NOTIFY		1

#ifdef CONFIG_RTL8686_SHM_NOTIFY
#define CPU_DSR_RX_CNT			0x20
#endif

/*
*	VoIP config
*/
#define ROM_MAP_ADDR	0x94000000

/*
*	Check alloc
*/
//#define CHECK_ALLOC
#define CHECK_TIME_ALLOC			1


/*
*	DSP log
*/
#ifdef CONFIG_RTL8686_IPC_RECORD_DSP_LOG
#define RECORD_DSP_LOG_ENABLE			1
#define RECORD_DSP_LOG_DISABLE			0
#define RECORD_DSP_LOG_SIZE				(128*1024)
#define MAX_PRINT_BUF_SIZE				(3*1024)
#endif

#endif /* _AIPC_GLOBAL_H_ */

