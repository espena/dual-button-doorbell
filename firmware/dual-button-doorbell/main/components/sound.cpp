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

#include "sound.hpp"
#include "esp_log.h"
#include "esp_event.h"
#include "memory.h"
#include "driver/gpio.h"
#include "driver/i2s_std.h"
#include "../dummy_sound.h"
#include "../io.h"

using namespace espena::components;

const esp_event_base_t sound::event_base = "SOUND_EVENT";

sound::sound( const sound::configuration &config ) :
  m_config( config ),
  m_i2s_std_cfg( {
    .clk_cfg = I2S_STD_CLK_DEFAULT_CONFIG( 44100 ),
    .slot_cfg = I2S_STD_MSB_SLOT_DEFAULT_CONFIG( I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_MONO ),
    .gpio_cfg = {
      .mclk = I2S_GPIO_UNUSED,
      .bclk = config.gpio_i2s_bclk,
      .ws = config.gpio_i2s_lrclk,
      .dout = config.gpio_i2s_dout,
      .din = I2S_GPIO_UNUSED,
      .invert_flags = {
        .mclk_inv = false,
        .bclk_inv = false,
        .ws_inv = false
      }
    }
  } ) {
  gpio_reset_pin( config.gpio_i2s_sd_mode );
  gpio_set_direction( config.gpio_i2s_sd_mode, GPIO_MODE_OUTPUT );
  i2s_chan_config_t chan_cfg = I2S_CHANNEL_DEFAULT_CONFIG( I2S_NUM_0, I2S_ROLE_MASTER );
  i2s_new_channel( &chan_cfg, &m_i2s_tx_handle, NULL );
  i2s_channel_init_std_mode( m_i2s_tx_handle, &m_i2s_std_cfg );
}

sound::~sound() {

}

void sound::play( FILE * fp ) {
  static const size_t BUFFER_SIZE = 1024;
  if( fp ) {
    wav_hdr_prologue whp;
    fread( ( void * ) &whp, sizeof( whp ), 1, fp );
    if( memcmp( whp.tag, ( void * ) "RIFF", 4 ) != 0 ) {
      return;
    }
    i2s_channel_enable( m_i2s_tx_handle );
    gpio_set_level( m_config.gpio_i2s_sd_mode, 1 );
    char buf[ BUFFER_SIZE ] = { 0 };
    while( !feof( fp ) ) {
      size_t chunk_size = fread( ( void * ) &buf, 1, sizeof( buf ) / sizeof( buf[ 0 ] ), fp );
      size_t bytes_written = 0;
      while( bytes_written < chunk_size ) {
        i2s_channel_write( m_i2s_tx_handle, buf, chunk_size, &bytes_written, 2000 );
        vTaskDelay( 1 );
      }
    }
    i2s_channel_disable( m_i2s_tx_handle );
    fclose( fp );
    m_event_dispatcher.dispatch( sound::event_base, ON_PLAY_END, NULL, 0 );
  }
}

void sound::set_event_loop_handle( esp_event_loop_handle_t event_loop_handle ) {
  m_event_dispatcher.set_event_loop_handle( event_loop_handle );
}

void sound::add_event_listener( event_id event_id,
                                esp_event_handler_t event_handler )
{
  m_event_dispatcher.add_event_listener( sound::event_base,
                                          event_id,
                                          event_handler );
}
