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

#include "sdcard.hpp"
#include "esp_event.h"
#include "esp_vfs_fat.h"
#include "driver/spi_common.h"
#include "../io.h"

// IDF's C structs with unions are incompatible with this warning
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

using namespace espena::components;

const esp_event_base_t sdcard::event_base = "SDCARD_EVENT";

sdcard::sdcard( const configuration &config ) : m_config( config )
{

}

sdcard::~sdcard() {

}

void sdcard::set_event_loop_handle( esp_event_loop_handle_t event_loop_handle ) {
  m_event_dispatcher.set_event_loop_handle( event_loop_handle );
}

void sdcard::add_event_listener( event_id event_id,
                                 esp_event_handler_t event_handler,
                                 void *event_params )
{
  m_event_dispatcher.add_event_listener( sdcard::event_base,
                                         event_id,
                                         event_handler,
                                         event_params );
}

void sdcard::mount() {

  esp_vfs_fat_sdmmc_mount_config_t mount_config = {
    .format_if_mount_failed = false,
    .max_files = 5,
    .allocation_unit_size = 16 * 1024,
    .disk_status_check_enable = false
  };

  sdmmc_card_t *card;
  sdmmc_host_t host = SDSPI_HOST_DEFAULT();
  host.slot = m_config.sdspi_bus.slot;

  spi_bus_config_t bus_cfg = {
    .mosi_io_num = m_config.gpio_sdspi_mosi,
    .miso_io_num = m_config.gpio_sdspi_miso,
    .sclk_io_num = m_config.gpio_sdspi_clk,
    .quadwp_io_num = -1,
    .quadhd_io_num = -1,
    .max_transfer_sz = m_config.sdspi_max_transfer_sz
  };

  spi_bus_initialize( m_config.sdspi_bus.id, &bus_cfg, m_config.sdspi_dma_channel );

  sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
  slot_config.gpio_cs = m_config.gpio_sdspi_cs;
  slot_config.host_id = m_config.sdspi_bus.id;

  esp_err_t ret = esp_vfs_fat_sdspi_mount( 
    m_config.mount_point.c_str(),
    &host,
    &slot_config,
    &mount_config,
    &card );

  if( ret == ESP_OK ) {
    m_event_dispatcher.dispatch( sdcard::event_base, ON_MOUNT_OK, NULL );
  }
  else {
    m_event_dispatcher.dispatch( sdcard::event_base, ON_MOUNT_FAILED, NULL );
    return;
  }

}

FILE * sdcard::open_file( const std::string name, const std::string access ) {
  return fopen( ( m_config.mount_point + "/" + name ).c_str(), access.c_str() );
}

void sdcard::close_file( FILE * fp ) {
  fclose( fp );
}
