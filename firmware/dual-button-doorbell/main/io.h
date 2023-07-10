/*
 *  This file is part of the dual-button doorbell project.
 *  Copyright (C) 2023  Espen Andersen (espenandersen.no)
 *
 *  This is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __io_h__
#define __io_h__

#include "driver/gpio.h"

#define IO_I2S_BCLK           GPIO_NUM_0
#define IO_I2S_LRCLK          GPIO_NUM_32
#define IO_I2S_DOUT           GPIO_NUM_33
#define IO_I2S_SD_MODE        GPIO_NUM_27

#define IO_I2C_SCL            GPIO_NUM_4
#define IO_I2C_SDA            GPIO_NUM_5

#define IO_RTC_INT            GPIO_NUM_2

#define IO_RELAY              GPIO_NUM_12

#define IO_SDCARD_MOSI        GPIO_NUM_14
#define IO_SDCARD_MISO        GPIO_NUM_13
#define IO_SDCARD_CS          GPIO_NUM_26
#define IO_SDCARD_CLK         GPIO_NUM_15
#define IO_SDCARD_DET         GPIO_NUM_35

#define IO_PANEL_S1_RED       GPIO_NUM_22
#define IO_PANEL_S1_GREEN     GPIO_NUM_23
#define IO_PANEL_S2_RED       GPIO_NUM_18
#define IO_PANEL_S2_GREEN     GPIO_NUM_19
#define IO_PANEL_S1_INPUT     GPIO_NUM_39
#define IO_PANEL_S2_INPUT     GPIO_NUM_36

#define IO_LED_RED            GPIO_NUM_21
#define IO_LED_GREEN          GPIO_NUM_25

#endif // __io_h__
