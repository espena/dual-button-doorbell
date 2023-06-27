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

#ifndef __button_hpp__
#define __button_hpp__

#include "driver/gpio.h"
#include "event/event_dispatcher.hpp"

namespace espena::components {

  class button : public event::i_event_dispatcher {

    public:

      static const esp_event_base_t event_base;

      typedef enum {
        ON_BTN_DOWN,
        ON_BTN_UP
      } event_id;

      typedef struct configuration_struct {
        int btn_id;
        gpio_num_t gpio_button;
        gpio_num_t gpio_led;
      } configuration;

      typedef struct isr_params_struct {
        button *instance;
      } isr_params;

    private:

      const configuration &m_config;
      ::espena::components::event::event_dispatcher m_event_dispatcher;
      QueueHandle_t m_message_queue;

      static void button_event_task( void * );
      void on_btn_event();

    public:

      button( const configuration & );
      ~button();

      static IRAM_ATTR void btn_isr_handler( void * );

      int get_id();

      void intr_disable();
      void intr_enable();

      void set_event_loop_handle( esp_event_loop_handle_t );
      void add_event_listener( event_id,
                               esp_event_handler_t );
  }; // class button

}; // namespace espena

#endif // __button_hpp__
