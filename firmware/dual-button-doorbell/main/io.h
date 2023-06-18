#ifndef IO_H
#define IO_H

#include "driver/gpio.h"

#define IO_I2S_BCLK           GPIO_NUM_0
#define IO_I2S_LRCLK          GPIO_NUM_32
#define IO_I2S_DOUT           GPIO_NUM_33
#define IO_I2S_SD_MODE        GPIO_NUM_27

#define IO_RELAY              GPIO_NUM_2

#define IO_SDCARD_MOSI        GPIO_NUM_14
#define IO_SDCARD_MISO        GPIO_NUM_13
#define IO_SDCARD_CS          GPIO_NUM_26
#define IO_SDCARD_CLK         GPIO_NUM_15

#define IO_PANEL_S1_RED       GPIO_NUM_22
#define IO_PANEL_S1_GREEN     GPIO_NUM_23
#define IO_PANEL_S2_RED       GPIO_NUM_18
#define IO_PANEL_S2_GREEN     GPIO_NUM_19
#define IO_PANEL_S1_INPUT     GPIO_NUM_39
#define IO_PANEL_S2_INPUT     GPIO_NUM_36

#define IO_LED_RED            GPIO_NUM_21
#define IO_LED_GREEN          GPIO_NUM_25

#endif
