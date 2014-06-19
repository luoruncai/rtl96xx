## globale information
## input image name, lpreloader_image preloader_image and bootloader, are overwriten by extra command
variable preloader_platform     luna_cli
#variable preloader_image      "plr.nand.img"
#variable bootloader_image     "u-boot.bin"
## output image name, final_image and loader_image, are overwriten by command line 
#variable final_image          "final.img"
#variable loader_image         "loader.img"
variable flash_type             spi_nor
#variable preloader_image        "plr.img"
variable padding_unit           4K

## retrive NOR SPI flash database
source $PARTS_DB_DIR/parts_for_nor_spi.tcl
add_model nor_spi MXIC_MX25L12835F
add_model nor_spi MXIC_MX25L25735E
# add_model nor_spi MXIC_MX25L25735E_SIO
add_model nor_spi WINBOND_W25Q128FV

## retrive dram gen2 database
source $PARTS_DB_DIR/parts_for_dram_gen2.tcl
namespace eval WINBOND_W631GG6KB {
		## ODT=100, OCD=60
    variable zq_setting             0x00000cfc
    variable tx_clk_phs_delay       0x0D
    variable clkm_delay             0x00
    variable clkm90_delay           0x00
    variable mrs_drv_strength       1          ;#(DDR3-OCD) 0->240/6=40 ohm, 1->240/7=34 ohm
    variable mrs_odt                120        ;#(DDR1) none, (DDR2) 0, 50, 75, 150; (DDR3-ntt_nom) 0, 20, 30, 40, 60, 120
    variable mrs_rtt_wr             120        ;#(DDR3) 0->disable, 60, 120

    variable static_cal_data_0      0x02000000
    variable static_cal_data_1      0x01000000
    variable static_cal_data_2      0x02000000
    variable static_cal_data_3      0x01000000
    variable static_cal_data_4      0x03000000
    variable static_cal_data_5      0x03000000
    variable static_cal_data_6      0x01000000
    variable static_cal_data_7      0x02000000
    variable static_cal_data_8      0x01000000
    variable static_cal_data_9      0x00000000
    variable static_cal_data_10     0x00000000
    variable static_cal_data_11     0x00000000
    variable static_cal_data_12     0x00000000
    variable static_cal_data_13     0x01000000
    variable static_cal_data_14     0x00000000
    variable static_cal_data_15     0x01000000
}
add_model dram_gen2 WINBOND_W971GG6JB25
#add_model dram_gen2 WINBOND_W971GG8JB25
add_model dram_gen2 WINBOND_W631GG6KB

## PLL information
# NOTE: when using "pin" in "set_by", the corresponding cpu/dsp/dram/lx clock 
#       should be correctly filled as some parameters passed to the preloader
#       are calculated respectively. (E.g., DRAM timer, UART clock divisor and etc) 
namespace eval rtk_pll_gen1 {
    #variable set_by                 pin
    variable set_by                 software
    variable cpu_clock_mhz          600
    variable dsp_clock_mhz          500
    variable dram_clock_mhz         300
    variable lx_clock_mhz           200
}
add_model pll_gen1 rtk_pll_gen1 

## peripheral information
namespace eval rtk_peri {
    variable uart_baudrate          115200
}
add_model peri rtk_peri

## mac info
namespace eval rtk_mac {
    variable address                "11:22:33:44:55:66"
}
add_model mac rtk_mac

##flash layout
# env:  booloader1(U-Boot) environment storage
# opt1: config (HS/CS/tr069 storage, mounted as jffs2)
namespace eval default_flash_layout {
    variable layout [subst {
        { follow    bootloader1 "$bootloader_image" }
        --runtime
        { 144K  env       -reserve 16K }
        { 160K  opt1      -reserve 384K }
        { 544K  kernel1   -reserve 2048K }
        { 2592K rootfs1   -reserve 5600K }
        { 8M    end }
    }]
    # the unit could be -in_byte, and -in_nor_erase 
}
add_model flash_layout default_flash_layout

## debug info
#cout "PARTS_DB_DIR=$PARTS_DB_DIR"
#cout "loader_image=$loader_image"
#cout "final_image=$final_image"
#cout "preloader_image=$preloader_image"
#cout "bootloader_image=$bootloader_image"
#cout "kernel_image=$kernel_image"
#cout "rootfs_image=$rootfs_image"
