#define SOC_SDMMC_USE_GPIO_MATRIX

#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include "esp_task_wdt.h"
#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "rom/gpio.h"
// #include "esp_adc/adc_oneshot.h"
//#include "driver/i2s_std.h"
#include "driver/i2s_std.h"
#include "esp_vfs_fat.h"
#include "sdmmc_cmd.h"
#include "io.h"
#include "dummy_sound.h"

void init_i2s( void ) {

  gpio_reset_pin( IO_I2S_SD_MODE );
  gpio_set_direction( IO_I2S_SD_MODE, GPIO_MODE_OUTPUT );

  i2s_chan_handle_t tx_handle;
  i2s_chan_config_t chan_cfg = I2S_CHANNEL_DEFAULT_CONFIG( I2S_NUM_0, I2S_ROLE_MASTER );

  i2s_new_channel( &chan_cfg, &tx_handle, NULL );

  i2s_std_config_t std_cfg = {
    .clk_cfg = I2S_STD_CLK_DEFAULT_CONFIG( 44100 ),
    .slot_cfg = I2S_STD_MSB_SLOT_DEFAULT_CONFIG( I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_MONO ),
    .gpio_cfg = {
      .mclk = I2S_GPIO_UNUSED,
      .bclk = IO_I2S_BCLK,
      .ws = IO_I2S_LRCLK,
      .dout = IO_I2S_DOUT,
      .invert_flags = {
        .mclk_inv = false,
        .bclk_inv = false,
        .ws_inv = false
      }
    }
  };

  FILE *fp = fopen( "/sdcard/ousse.wav", "rb" );

  static const size_t BUFFER_SIZE = 1024;

  typedef struct waw_hdr_prologue_st {
    char tag[ 4 ];
    union {
      char b[ 4 ];
      int16_t i;
    } len;
  } waw_hdr_prologue;
  
  if( fp ) {

    size_t chunk_size = 0;
    
    waw_hdr_prologue whp;
    fread( ( void * ) &whp, sizeof( whp ), 1, fp );
    if( memcmp( whp.tag, ( void * ) "RIFF", 4 ) != 0 ) {
      gpio_set_level( IO_LED_RED, 1 );
      return;
    }

    // Skip wav header and jump straight
    // to PCM section
    //fseek( fp, whp.len.i, SEEK_CUR );

    gpio_set_level( IO_LED_GREEN, 1 );

    char buf[ BUFFER_SIZE ];

    i2s_channel_init_std_mode( tx_handle, &std_cfg );
    i2s_channel_enable( tx_handle );
    gpio_set_level( IO_I2S_SD_MODE, 1 );

    gpio_set_level( IO_LED_RED, 1 );
    while( !feof( fp ) ) {
      chunk_size = fread( ( void * ) &buf, sizeof( char ), sizeof( buf ) / sizeof( buf[ 0 ] ), fp );
      size_t bytes_written = 0;
      while( bytes_written < chunk_size ) {
        i2s_channel_write( tx_handle, buf, chunk_size, &bytes_written, 2000 );
      }
    }
    gpio_set_level( IO_LED_RED, 0 );

    i2s_channel_disable( tx_handle );
    gpio_set_level( IO_LED_GREEN, 0 );

    fclose( fp );
  }
  else {
    gpio_set_level( IO_LED_RED, 1 );
  }

}

void init_i2c( void ) {

}

void init_jtag( void ) {

}

void init_uart( void ) {

}

void init_relay( void ) {
  gpio_reset_pin( IO_RELAY );
  gpio_set_direction( IO_RELAY, GPIO_MODE_OUTPUT );
}

void init_sdcard( void ) {

  esp_err_t ret;

  esp_vfs_fat_sdmmc_mount_config_t mount_config = {
    .format_if_mount_failed = true,
    .max_files = 5,
    .allocation_unit_size = 16 * 1024
  };
  
  sdmmc_card_t *card;

  const char mount_point[] = "/sdcard";

  sdmmc_host_t host = SDSPI_HOST_DEFAULT();

  host.slot = 1;

  spi_bus_config_t bus_cfg = {
    .mosi_io_num = IO_SDCARD_MOSI,
    .miso_io_num = IO_SDCARD_MISO,
    .sclk_io_num = IO_SDCARD_CLK,
    .quadwp_io_num = -1,
    .quadhd_io_num = -1,
    .max_transfer_sz = 4000
  };

  ret = spi_bus_initialize( host.slot, &bus_cfg, 1 );

  sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
  slot_config.gpio_cs = IO_SDCARD_CS;
  slot_config.host_id = host.slot;

  ret = esp_vfs_fat_sdspi_mount( mount_point, &host, &slot_config, &mount_config, &card );

  if( ret != ESP_OK ) {
    if( ret == ESP_FAIL ) {
      gpio_set_level( IO_LED_RED, 1 );
      gpio_set_level( IO_LED_GREEN, 1 );
    }
    else {
      gpio_set_level( IO_LED_RED, 1 );
      return;
    }
  }

  /*

  sdmmc_host_set_card_clk( 0, 20000 );
  
  sdmmc_host_t host = SDSPI_HOST_DEFAULT();

  sdmmc_slot_config_t slot_config = SDMMC_SLOT_CONFIG_DEFAULT();

  slot_config.width = 4;

  slot_config.clk = IO_SDCARD_CLK;
  slot_config.cmd = IO_SDCARD_CMD;
  slot_config.d0 = IO_SDCARD_SD0;
  slot_config.d1 = IO_SDCARD_SD1;
  slot_config.d2 = IO_SDCARD_SD2;
  slot_config.d3 = IO_SDCARD_SD3;

  slot_config.flags |= SDMMC_SLOT_FLAG_INTERNAL_PULLUP;

  esp_vfs_fat_sdmmc_mount_config_t mount_config = {
    .format_if_mount_failed = false,
    .max_files = 1,
    .allocation_unit_size = 16 * 1024
  };

  sdmmc_card_t *card;
  esp_err_t ret = esp_vfs_fat_sdmmc_mount( "/sdcard", &host, &slot_config, &mount_config, &card );

  if( ret == ESP_OK ) {
    gpio_set_level( IO_LED_GREEN, 1 );
  }
  else {
    gpio_set_level( IO_LED_RED, 1 );
  }

  */

  //sdmmc_card_print_info( stdout, card );

}

void init_panel( void ) {

  const gpio_num_t inputs[] = { IO_PANEL_S1_INPUT, IO_PANEL_S2_INPUT };

  const gpio_num_t outputs[] = { IO_PANEL_S1_RED, IO_PANEL_S1_GREEN,
                                 IO_PANEL_S2_RED, IO_PANEL_S2_GREEN };

  for( int i = 0; i < sizeof( inputs ) / sizeof( inputs[ 0 ] ); i++ ) {
    gpio_reset_pin( inputs[ i ] );
    gpio_set_direction( inputs[ i ], GPIO_MODE_INPUT );
  }

  for( int i = 0; i < sizeof( outputs ) / sizeof( outputs[ 0 ] ); i++ ) {
    gpio_reset_pin( outputs[ i ] );
    gpio_set_direction( outputs[ i ], GPIO_MODE_OUTPUT );
  }

}

void init_led( void ) {

  const gpio_num_t outputs[] = { IO_LED_RED, IO_LED_GREEN };

  for( int i = 0; i < sizeof( outputs ) / sizeof( outputs[ 0 ] ); i++ ) {
    gpio_reset_pin( outputs[ i ] );
    gpio_set_direction( outputs[ i ], GPIO_MODE_OUTPUT );
  }

}

void init( void ) {
  init_i2c();
  init_led();
  init_jtag();
  init_uart();
  init_relay();
  init_sdcard();
  init_i2s();
  init_panel();
}
