#include <linux/config.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include "led-generic.h"
#include "pushbutton.h"
#include "gpio.h"
//#include <asm/mach-realtek/rtl8672/platform.h>
/*linux-2.6.19*/ 
#include <bspchip.h>

#define LOW_ACTIVE	1
#if LOW_ACTIVE

#define GPIO_SET(w, op)  do { \
	gpioConfig(w, GPIO_FUNC_OUTPUT); \
	if (LED_ON==op) gpioClear(w); \
	else gpioSet(w); \
} while (0);

#define GPIO_READ(w) (!gpioRead(w))
		
#else

#define GPIO_SET(w, op)  do { \
	gpioConfig(w, GPIO_FUNC_OUTPUT); \
	if (LED_ON==op) gpioSet(w); \
	else gpioClear(w); \
} while (0);

#define GPIO_READ(w) (gpioRead(w))

#endif

#ifdef FWUPGRADE_LED
//jiunming, for telefonica, Recoverable Error during Firmware upgrade
extern unsigned char fwupgradeerrstate;
unsigned char flag_led_power_green;
unsigned char flag_led_power_red;
unsigned char flag_led_dsl;
unsigned char flag_led_internet_green;
unsigned char flag_led_internet_red;
unsigned char flag_led_wps_green;
unsigned char flag_led_wps_red;
unsigned char flag_led_wps_yellow;
#endif

void PCIE_reset_pin(int *reset){
	*reset = GPIO_H_2;
}
EXPORT_SYMBOL(PCIE_reset_pin);

static void board_08_handle_set(int which, int op) {
	//printk("%s: led %d op %d\n", __FUNCTION__, which, op);
	
	switch (which) {
#ifdef CONFIG_SW_USB_LED1
	case LED_USB_1:
		GPIO_SET(GPIO_F_6, op);
		break;
#endif //CONFIG_SW_USB_LED1
	case LED_DSL:	
		GPIO_SET(GPIO_H_3, op);
		break;
#ifdef CONFIG_SW_USB_LED0
	case LED_USB_0:
		GPIO_SET(GPIO_F_5, op);
		break;
#endif //CONFIG_SW_USB_LED0
	case LED_POWER_GREEN:
		GPIO_SET(GPIO_B_4, op);
		break;
	case LED_POWER_RED:
		GPIO_SET(GPIO_B_5, op);
		break;
	case LED_INTERNET_RED:
	case LED_PPP_RED:
		GPIO_SET(GPIO_B_6, op);
		break;
	case LED_WPS_GREEN:
		GPIO_SET(GPIO_C_3, op);
		break;
	case LED_WPS_RED:
		GPIO_SET(GPIO_C_4, op);
		break;
	case LED_WPS_YELLOW:
		GPIO_SET(GPIO_C_5, op);
		break;
	case LED_INTERNET_GREEN:
	case LED_PPP_GREEN:
		GPIO_SET(GPIO_D_1, op);
		break;
	default:
		led_handle_set(which, op);
	}
}

static void board_08_handle_init(void) {
	board_08_handle_set(LED_POWER_GREEN, LED_OFF);
	board_08_handle_set(LED_POWER_RED, LED_ON);
	board_08_handle_set(LED_DSL, LED_OFF);
	board_08_handle_set(LED_INTERNET_GREEN, LED_OFF);
	board_08_handle_set(LED_INTERNET_RED, LED_OFF);
	board_08_handle_set(LED_WPS_GREEN, LED_OFF);
	board_08_handle_set(LED_WPS_RED, LED_OFF);
	board_08_handle_set(LED_WPS_YELLOW, LED_OFF);
#ifdef CONFIG_SW_USB_LED1
	board_08_handle_set(LED_USB_1, LED_OFF);
#endif //CONFIG_SW_USB_LED1
#ifdef CONFIG_SW_USB_LED0
	board_08_handle_set(LED_USB_0, LED_OFF);
#endif //CONFIG_SW_USB_LED0

};

static struct led_operations board_08_operation = {
	.name = "board_08",
	.handle_init = board_08_handle_init,
	.handle_set = board_08_handle_set,
};


static void board_08_pb_init(void) {
};

static int board_08_pb_is_pushed(int which) {
	switch(which) {
#ifndef CONFIG_JTAG_USABLE
	case PB_RESET:
		return GPIO_READ(GPIO_G_7);

	case PB_WIFISW:
		return GPIO_READ(GPIO_H_0);
#endif //CONFIG_JTAG_USABLE
	case PB_WPS:
		return GPIO_READ(GPIO_C_6);
	}

	return 0;
}

static struct pushbutton_operations board_08_pb_op = {
	.handle_init = board_08_pb_init,
	.handle_is_pushed = board_08_pb_is_pushed,
};

static int __init board_08_led_init(void) {
#ifndef CONFIG_JTAG_USABLE
	unsigned int sicr;

	sicr = REG32(BSP_MISC_PINMUX);	
	if ( sicr & BSP_JTAG_GPIO_PINMUX ) {
		printk( "<<<<<<<disable GPIO JTAG function.\n" );
		REG32(BSP_MISC_PINMUX) = sicr & ~BSP_JTAG_GPIO_PINMUX;
	}
#endif //CONFIG_JTAG_USABLE
	REG32(BSP_MISC_PINMUX) &= ~(BSP_NANDF_GPIO
#ifdef CONFIG_SW_USB_LED1
		| BSP_USBLED1_GPF6
#endif //CONFIG_SW_USB_LED1
#ifdef CONFIG_SW_USB_LED0
		| BSP_USBLED0_GPF5
#endif //CONFIG_SW_USB_LED0
	);
	REG32(BSP_MISC_PINMUX) |= (BSP_LEDS1_GPH5 | BSP_LEDS2_GPH6 | BSP_LEDS3_GPH7 | BSP_LEDP0_GPF0);	//setup switch LED
	if (IS_8676V2)
		REG32(BSP_RGMII_PAD_CTRL) &= ~0x40000000; // Set to GPIO mode (USBLED1)
#ifdef CONFIG_RTK_VOIP_DRIVERS_PCM8676
	REG32(BSP_IP_SEL) |= (BSP_EN_PCM | BSP_EN_VOIPACC);
	REG32(BSP_MISC_PINMUX) |= BSP_VOIP_GPIO_PINMUX_G1;
#ifdef CONFIG_RTK_VOIP_8676_SPI_GPIO
	REG32(BSP_PCM_SPI_IND_CTRL) &= ~BSP_SPI_GPIO_G1; //G1 GPIO-simulated SPI
	REG32(BSP_VOIP_SPI_CS_IND_CTRL) &= ~BSP_VOIP_SPI_CS1; //GPIO-simulated SPI CS1
	REG32(BSP_VOIP_SPI_CS_IND_CTRL) &= ~BSP_VOIP_SPI_CS2; //GPIO-simulated SPI CS2
//#elif defined (CONFIG_RTK_VOIP_8676_ISI_ZSI)
//	REG32(BSP_MISC_PINMUX) |= (BSP_ZSI_ISI_PINMUX_C0 | BSP_ZSI_ISI_PINMUX_C1);
#endif
#endif
	led_register_operations(&board_08_operation);
	pb_register_operations(&board_08_pb_op);
	return 0;
}

static void __exit board_08_led_exit(void) {
}


module_init(board_08_led_init);
module_exit(board_08_led_exit);


MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("GPIO driver for Reload default");



