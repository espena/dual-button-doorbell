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

#include "mqtt.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
#include "esp_event.h"
#include "esp_tls.h"
#include "mqtt_client.h"
#include "i_file_io.hpp"

using namespace espena::components;

const char *mqtt::LOG_TAG = "mqtt";

mqtt::mqtt( const configuration &config ) :
  m_config( config ),
  m_cert( NULL ),
  m_cert_len( 0 ),
  m_filesys( NULL ),
  m_client( NULL )
{

  ESP_LOGI( LOG_TAG, "Initializing" );

  esp_log_level_set( "*", ESP_LOG_VERBOSE );
  m_message_queue = xQueueCreate( 10, sizeof( mqtt_task_queue_item ) );
  m_mqtt_task_params.instance = this;
  m_mqtt_task_params.task_handle = NULL;
  xTaskCreate( &mqtt::mqtt_task,
              "mqtt_task",
              MQTT_TASK_STACK_DEPTH,
              &m_mqtt_task_params,
              2,
              &m_mqtt_task_params.task_handle );
}

mqtt::~mqtt() {
  if( m_cert ) {
    free( m_cert );
  }
}

void mqtt::mqtt_task( void *arg ) {
  mqtt_task_params *params = static_cast<mqtt_task_params *>( arg );
  mqtt *inst = params->instance;
  mqtt_task_queue_item item;
  ESP_LOGI( LOG_TAG, "Entering task loop" );
  ESP_LOGI( LOG_TAG, "Free memory: %" PRIu32 " bytes", esp_get_free_heap_size() );
  while( 1 ) {
    if( xQueueReceive( inst->m_message_queue, &item, portMAX_DELAY ) ) {
      inst->on_message( item.message, item.arg );
    }
  }
}

void mqtt::event_handler( void *arg,
                          esp_event_base_t event_base,
                          int32_t event_id,
                          void *event_data )
{
  mqtt *instance = static_cast<mqtt *>( arg );
  instance->on_mqtt_event( static_cast<esp_mqtt_event_id_t>( event_id ),
                           static_cast<esp_mqtt_event_handle_t>( event_data ) );
}

void mqtt::on_mqtt_event( esp_mqtt_event_id_t event_id,
                          esp_mqtt_event_handle_t event )
{
  esp_mqtt_client_handle_t client = event->client;
  switch( event_id ) {
    case MQTT_EVENT_BEFORE_CONNECT:
      ESP_LOGI( LOG_TAG, "MQTT_EVENT_BEFORE_CONNECT" );
      break;
    case MQTT_EVENT_CONNECTED:
      ESP_LOGI( LOG_TAG, "MQTT_EVENT_CONNECTED" );
      break;
    case MQTT_EVENT_DISCONNECTED:
      ESP_LOGI( LOG_TAG, "MQTT_EVENT_DISCONNECTED" );
      break;
    case MQTT_EVENT_SUBSCRIBED:
      ESP_LOGI( LOG_TAG, "MQTT_EVENT_SUBSCRIBED, msg_id=%d", event->msg_id );
      break;
    case MQTT_EVENT_UNSUBSCRIBED:
      ESP_LOGI( LOG_TAG, "MQTT_EVENT_UNSUBSCRIBED, msg_id=%d", event->msg_id );
      break;
    case MQTT_EVENT_PUBLISHED:
      ESP_LOGI( LOG_TAG, "MQTT_EVENT_PUBLISHED, msg_id=%d", event->msg_id );
      break;
    case MQTT_EVENT_DATA:
      ESP_LOGI( LOG_TAG, "MQTT_EVENT_DATA" );
      printf( "TOPIC=%.*s\r\n", event->topic_len, event->topic );
      printf( "DATA=%.*s\r\n", event->data_len, event->data );
      break;
    case MQTT_EVENT_ERROR:
      ESP_LOGI( LOG_TAG, "MQTT_EVENT_ERROR" );
      if ( event->error_handle->error_type == MQTT_ERROR_TYPE_TCP_TRANSPORT ) {
        ESP_LOGI( LOG_TAG, "Last error code reported from esp-tls: 0x%x", event->error_handle->esp_tls_last_esp_err );
        ESP_LOGI( LOG_TAG, "Last tls stack error number: 0x%x", event->error_handle->esp_tls_stack_err );
        ESP_LOGI( LOG_TAG, "Last captured errno : %d (%s)",  event->error_handle->esp_transport_sock_errno,
                  strerror( event->error_handle->esp_transport_sock_errno ) );
      } else if ( event->error_handle->error_type == MQTT_ERROR_TYPE_CONNECTION_REFUSED ) {
        ESP_LOGI( LOG_TAG, "Connection refused error: 0x%x", event->error_handle->connect_return_code );
      } else {
        ESP_LOGW( LOG_TAG, "Unknown error type: 0x%x", event->error_handle->error_type );
      }
      break;
    default:
        ESP_LOGI( LOG_TAG, "Other event id:%d", event->event_id );
        break;
  }
}

void mqtt::on_message( mqtt_task_message msg, void *arg ) {
  switch( msg ) {
    case start_service:
      start();
      break;
    case push_notify:
      push( ( char * ) arg );
      break;
  }
}

void mqtt::init( const std::string server,
                 const std::string cert_file,
                 const std::string topic ) {

  m_server = server.empty()
           ? m_config.server.c_str() // Default
           : server.c_str();

  m_cert_file = cert_file.empty()
              ? m_config.cert_file.c_str() // Default
              : cert_file.c_str();

  m_topic = topic.empty()
          ? m_config.topic.c_str() // Default
          : topic.c_str();
}

void mqtt::get_cert() {
  ESP_LOGI( LOG_TAG, "Retrieve TLS certificate" );
  if( m_filesys ) {
    FILE *fp = m_filesys->open_file( m_cert_file.c_str(), "r" );
    if( fp ) {
      fseek( fp, 0, SEEK_END );
      m_cert_len = ftell( fp );
      fseek( fp, 0, SEEK_SET );
      m_cert = static_cast<unsigned char *>( malloc( m_cert_len + 1 ) );
      size_t bytes_read = fread( m_cert, 1, m_cert_len, fp );
      m_cert[ m_cert_len ] = '\0';
      m_filesys->close_file( fp );
      if( bytes_read != m_cert_len ) {
        ESP_LOGE( LOG_TAG,
                  "Error reading cert file. Assumed %d bytes but got %d bytes",
                  m_cert_len,
                  bytes_read );
        return;
      }
      ESP_LOGI( LOG_TAG, "Certificate loaded" );
    }
  }
  else {
    ESP_LOGE( LOG_TAG, "File system not configured" );
  }
}

void mqtt::push( char *data ) {
  const int msg_id = esp_mqtt_client_publish( m_client, m_topic.c_str(), data, 0, 0, 0 );
  ESP_LOGI( LOG_TAG, "Doorbell event successfully published, msg_id=%d", msg_id );
}

void mqtt::push_async( char *data ) {
  mqtt_task_queue_item item;
  item.message = push_notify;
  item.arg = data;
  xQueueSend( m_message_queue, &item, 1 );
}

void mqtt::start() {

  get_cert();

  memset( &m_mqtt_cfg, 0x00, sizeof( m_mqtt_cfg ) );
  m_mqtt_cfg.session.keepalive = 10800; // 3h
  m_mqtt_cfg.credentials.client_id = "dualbuttondoorbell";
  m_mqtt_cfg.broker.address.uri = m_server.c_str();
  m_mqtt_cfg.broker.verification.certificate = ( char * ) m_cert;

  m_client = esp_mqtt_client_init( &m_mqtt_cfg );
  esp_mqtt_client_register_event( m_client,
                                  static_cast<esp_mqtt_event_id_t>( ESP_EVENT_ANY_ID ),
                                  event_handler,
                                  this );
  ESP_LOGI( LOG_TAG, "Starting client, using %s", m_server.c_str() );
  esp_mqtt_client_start( m_client );

}

void mqtt::start_async( i_file_io *filesys ) {
  m_filesys = filesys;
  mqtt_task_queue_item item;
  item.message = start_service;
  item.arg = this;
  xQueueSend( m_message_queue, &item, 1 );
}
