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

#include "wifi.hpp"
#include <string>
#include <memory.h>
#include <algorithm>
#include "esp_wifi.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"
#include "nvs_flash.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"

#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1

using namespace espena::components;

EventGroupHandle_t wifi::m_wifi_event_group = xEventGroupCreate();

wifi::wifi() {
  m_message_queue = xQueueCreate( 10, sizeof( wifi_task_queue_item ) );
  m_wifi_task_params.instance = this;
  m_wifi_task_params.task_handle = NULL;
  xTaskCreate( &wifi::wifi_task,
               "wifi_task",
               WIFI_TASK_STACK_DEPTH,
               &m_wifi_task_params,
               2,
               &m_wifi_task_params.task_handle );
}

wifi::~wifi() {

}

void wifi::wifi_task( void *arg ) {
  wifi_task_params *params = reinterpret_cast<wifi_task_params *>( arg );
  wifi *inst = params->instance;
  wifi_task_queue_item item;
  while( 1 ) {
    if( xQueueReceive( inst->m_message_queue, &item, portMAX_DELAY ) ) {
      inst->on_message( item.message, item.arg );
    }
  }
}

void wifi::on_message( wifi_task_message msg, void *arg ) {
  switch( msg ) {
    case wifi_connect:
      connect();
      break;
  }
}

void wifi::event_handler( void *arg,
                          esp_event_base_t event_base,
                          int32_t event_id,
                          void *event_data )
{
  static int retries = 0;
  if( event_base == WIFI_EVENT ) {
    switch( event_id ) {
      case WIFI_EVENT_STA_START:
        esp_wifi_connect();
        break;
      case WIFI_EVENT_STA_DISCONNECTED:
        if( retries++ < 10 ) {
          esp_wifi_connect();
          ESP_LOGI( "wifi", "Retry connection to network" );
        }
        else {
          xEventGroupSetBits( m_wifi_event_group, WIFI_FAIL_BIT );
        }
        break;
    }
  }
  else if( event_base == IP_EVENT ) {
    switch( event_id ) {
      case IP_EVENT_STA_GOT_IP:
        ip_event_got_ip_t *e = reinterpret_cast<ip_event_got_ip_t *>( event_data );
        ESP_LOGI( "wifi", "Got ip:" IPSTR, IP2STR( &( e->ip_info.ip ) ) );
        retries = 0;
        xEventGroupSetBits( m_wifi_event_group, WIFI_CONNECTED_BIT );
        break;
    }
  }
}

void wifi::connect( std::string ssid,
                    std::string password )
{
  m_ssid = ssid;
  m_password = password;
  ESP_LOGI( "wifi", "Using SSID %s and PASSWORD %s", m_ssid.c_str(), m_password.c_str() );
  wifi_task_queue_item item = {
    .message = wifi_connect,
    .arg = this
  };
  xQueueSend( m_message_queue, &item, 1 );
}

void wifi::connect( void ) {

    ESP_LOGI( "wifi", "start wifi connect thread" );

    esp_err_t ret = nvs_flash_init();
    if ( ret == ESP_ERR_NVS_NO_FREE_PAGES ||
        ret == ESP_ERR_NVS_NEW_VERSION_FOUND )
    {
      ESP_LOGI( "wifi", "Erasing NVS mem" );
      ESP_ERROR_CHECK( nvs_flash_erase() );
      ret = nvs_flash_init();
    }  

    ESP_LOGI( "wifi", "Calling esp_wifi_init" );

    wifi_init_config_t config = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init( &config );

    ESP_LOGI( "wifi", "Calling esp_wifi_set_mode" );
    esp_wifi_set_mode( WIFI_MODE_STA );

    ESP_LOGI( "wifi", "Calling esp_netif_init" );
    esp_netif_init();

    ESP_LOGI( "wifi", "Calling esp_event_loop_create_default" );
    esp_event_loop_create_default();

    ESP_LOGI( "wifi", "Calling esp_netif_create_default_wifi_sta" );
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t wifi_ini = WIFI_INIT_CONFIG_DEFAULT();
    ESP_LOGI( "wifi", "Calling esp_wifi_init" );
    esp_wifi_init( &wifi_ini );

    ESP_LOGI( "wifi", "Register event handler for any ID" );
    esp_event_handler_instance_t instance_any_id;
    esp_event_handler_instance_register( WIFI_EVENT,
                                        ESP_EVENT_ANY_ID,
                                        &event_handler,
                                        NULL,
                                        &instance_any_id );

    ESP_LOGI( "wifi", "Register event handler for IP event" );
    esp_event_handler_instance_t instance_got_ip;
    esp_event_handler_instance_register( IP_EVENT,
                                        IP_EVENT_STA_GOT_IP,
                                        &event_handler,
                                        NULL,
                                        &instance_got_ip );


    ESP_LOGI( "wifi", "Fetch SSID and password" );
    wifi_config_t wifi_cfg;
    memset( &wifi_cfg, 0x00u, sizeof( wifi_config_t ) );

    const size_t n_ssid = sizeof( wifi_cfg.sta.ssid );
    const size_t n_password = sizeof( wifi_cfg.sta.password );

    ESP_LOGI( "wifi", "ssid: %s passwd: %s", wifi_cfg.sta.ssid, wifi_cfg.sta.password );

    strncpy( ( char * ) &wifi_cfg.sta.ssid, m_ssid.c_str(), n_ssid - 1 );
    strncpy( ( char * ) &wifi_cfg.sta.password, m_password.c_str(), n_password - 1 );

    wifi_cfg.sta.threshold.authmode = WIFI_AUTH_WPA2_PSK;
    wifi_cfg.sta.sae_pwe_h2e = WPA3_SAE_PWE_UNSPECIFIED;

    ESP_LOGI( "wifi", "Calling esp_wifi_set_mode" );
    esp_wifi_set_mode( WIFI_MODE_STA );

    ESP_LOGI( "wifi", "Calling esp_wifi_set_config" );
    esp_wifi_set_config( WIFI_IF_STA, &wifi_cfg );

    ESP_LOGI( "wifi", "Calling esp_wifi_start" );
    esp_wifi_start();

    ESP_LOGI( "wifi", "Calling xEventGroupWaitBits" );
    EventBits_t bits = xEventGroupWaitBits( m_wifi_event_group,
                                            WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
                                            pdFALSE,
                                            pdFALSE,
                                            portMAX_DELAY );

}