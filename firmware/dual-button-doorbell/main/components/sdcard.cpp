#include "sdcard.hpp"
#include "esp_vfs_fat.h"
#include "driver/spi_common.h"
#include "../io.h"

// IDF's C structs with unions are incompatible with this warning
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

using namespace espena::components;

sdcard::sdcard( const configuration &config ) : m_config( config ) {
  
}

sdcard::~sdcard() {

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

  esp_err_t ret = spi_bus_initialize( m_config.sdspi_bus.id, &bus_cfg, m_config.sdspi_dma_channel );

  sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
  slot_config.gpio_cs = m_config.gpio_sdspi_cs;
  slot_config.host_id = m_config.sdspi_bus.id;

  esp_vfs_fat_sdspi_mount( 
    m_config.mount_point.c_str(),
    &host,
    &slot_config,
    &mount_config,
    &card );

}

FILE * sdcard::open_file( const std::string name, const std::string access ) {
  return fopen( ( m_config.mount_point + "/" + name ).c_str(), access.c_str() );
}

void sdcard::close_file( FILE * fp ) {
  fclose( fp );
}
