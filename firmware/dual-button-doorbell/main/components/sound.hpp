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

#ifndef __sound_hpp__
#define __sound_hpp__

#include <string>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_task.h"
#include "driver/gpio.h"
#include "driver/i2s_std.h"
#include "esp_event.h"
#include "event/event_dispatcher.hpp"

namespace espena::components {

  class sound : public event::i_event_dispatcher {

    static const char *LOG_TAG;

    public:

      static const esp_event_base_t event_base;

      typedef enum {
        ON_PLAY_START,
        ON_PLAY_END
      } event_id;

      typedef struct configuration_struct {
        gpio_num_t gpio_i2s_sd_mode;
        gpio_num_t gpio_i2s_bclk;
        gpio_num_t gpio_i2s_lrclk;
        gpio_num_t gpio_i2s_dout;
      } configuration;

    private:

      volatile bool m_stop;

      typedef struct wave_hdr_struct {
        char  w_fileid[ 4 ];            /* chunk id 'RIFF'            */
        uint32_t w_chunksize;           /* chunk size                 */
        char  w_waveid[ 4 ];            /* wave chunk id 'WAVE'       */
        char  w_fmtid[ 4 ];             /* format chunk id 'fmt '     */
        uint32_t w_fmtchunksize;        /* format chunk size          */
        uint16_t  w_fmttag;             /* format tag, 1 for PCM      */
        uint16_t  w_nchannels;          /* number of channels         */
        uint32_t w_samplespersec;       /* sample rate in hz          */
        uint32_t w_navgbytespersec;     /* average bytes per second   */
        uint16_t  w_nblockalign;        /* number of bytes per sample */
        uint16_t  w_nbitspersample;     /* number of bits in a sample */
        char  w_datachunkid[ 4 ];       /* data chunk id 'data'       */
        uint32_t w_datachunksize;       /* length of data chunk       */
      } wave_hdr;

      const configuration &m_config;
      i2s_chan_handle_t m_i2s_tx_handle;
      i2s_std_config_t m_i2s_std_cfg;
      ::espena::components::event::event_dispatcher m_event_dispatcher;

      static const configSTACK_DEPTH_TYPE SOUND_TASK_STACK_DEPTH = 32768;
      
      typedef struct sound_task_params_struct {
        sound *instance;
        TaskHandle_t task_handle;
      } sound_task_params;

      typedef enum {
        sound_play
      } sound_task_message;

      typedef struct sound_task_queue_item_struct {
        sound_task_message message;
        void *arg;
      } sound_task_queue_item;

      QueueHandle_t m_message_queue;

      void on_message( sound_task_message, void * );

      static void sound_task( void * );

      sound_task_params m_sound_task_params;

      void initialize();

      void play( FILE * );
      void stop();

    public:

      sound( const configuration & );
      ~sound();

      void play_async( FILE * );
      void stop_async();

      void set_event_loop_handle( esp_event_loop_handle_t );
      void add_event_listener( event_id,
                               esp_event_handler_t );

  }; // class sound

}; // namespace espena::components

#endif // __sound_hpp__