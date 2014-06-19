/*
 * Realtek Semiconductor Corp.
 *
 * bspcpu.h:
 *
 * Tony Wu (tonywu@realtek.com.tw)
 * Dec. 7, 2007
 */
#ifndef __BSPCPU_H_
#define __BSPCPU_H_

#define cpu_scache_size     0
#define cpu_dcache_size     ( 16 << 10)
#define cpu_icache_size     ( 32 << 10)
#define cpu_scache_line     0
#define cpu_dcache_line     16
#define cpu_icache_line     16
#define cpu_tlb_entry       64
#define cpu_mem_size        (32 << 20)

#define cpu_imem_size       0
#define cpu_dmem_size       0
#define cpu_smem_size       0

#endif
