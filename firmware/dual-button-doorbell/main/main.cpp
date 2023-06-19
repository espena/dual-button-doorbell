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

#include "application.hpp"
#include "driver/gpio.h"
#include "io.h"

extern "C" void app_main() {

  using namespace espena;

  /* Main configuration */
  application::configuration config = {

    .led_green = {
      .gpio_num = IO_LED_GREEN },

    .led_red = {
      .gpio_num = IO_LED_RED },
    
    .relay = {
      .gpio_relay = IO_RELAY },
    
    .sound = {
      .gpio_i2s_sd_mode = IO_I2S_SD_MODE,
      .gpio_i2s_bclk = IO_I2S_BCLK,
      .gpio_i2s_lrclk = IO_I2S_LRCLK,
      .gpio_i2s_dout = IO_I2S_DOUT },

    .sdcard = {
      .gpio_sdspi_mosi = IO_SDCARD_MOSI,
      .gpio_sdspi_miso = IO_SDCARD_MISO,
      .gpio_sdspi_cs = IO_SDCARD_CS,
      .gpio_sdspi_clk = IO_SDCARD_CLK,
      .sdspi_bus = {
        .slot = 1 },
      .sdspi_max_transfer_sz = 4000,
      .sdspi_dma_channel = 1,
      .mount_point = "/sdcard" },

    .button_left = {
      .gpio_button = IO_PANEL_S1_INPUT,
      .gpio_led = IO_PANEL_S1_RED },

    .button_right = {
      .gpio_button = IO_PANEL_S2_INPUT,
      .gpio_led = IO_PANEL_S2_RED }
  };

  application app( config );
  app.run();
}
