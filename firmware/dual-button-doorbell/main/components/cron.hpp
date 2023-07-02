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

#ifndef __cron_hpp__
#define __cron_hpp__

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_event.h"
#include "event/event_dispatcher.hpp"

namespace espena::components {

  class cron {

    static const char *LOG_TAG;
    static const configSTACK_DEPTH_TYPE CRON_TASK_STACK_DEPTH = 32768;
    
    typedef enum {
      cron_start
    } cron_task_message;

    typedef struct cron_task_queue_item_struct {
      cron_task_message message;
      void *arg;
    } cron_task_queue_item;

    QueueHandle_t m_message_queue;

    typedef struct cron_task_params_struct {
      cron *instance;
      TaskHandle_t task_handle;
      int delay_ms;
      int count;
    } cron_task_params;

    cron_task_params m_cron_task_params;

    public:

      typedef struct configuration_struct {
        std::string crontab_file;
      } configuration;

    private:

      const configuration &m_config;

      void on_message( cron_task_message, void * );

      void service_start();

    public:

      cron( const configuration & );
      ~cron();
  
      static void cron_task( void * );

      void start();

  }; // class cron

}; // namespace espena::components

#endif // __cron_hpp__