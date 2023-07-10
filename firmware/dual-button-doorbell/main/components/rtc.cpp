#include <memory.h>
#include <time.h>
#include <sys/time.h>
#include "rtc.hpp"
#include "driver/i2c.h"
#include "esp_log.h"
#include "../io.h"

using namespace espena::components;

const char *rtc::LOG_TAG = "rtc";

rtc::rtc( const rtc::configuration &config ) : m_config( config ) {
  save_current_timezone();
  memset( &m_i2c_config, 0x00, sizeof( m_i2c_config ) );
  m_i2c_config = {
    .mode = I2C_MODE_MASTER,
    .sda_io_num = config.gpio_sda,
    .scl_io_num = config.gpio_scl,
    .sda_pullup_en = GPIO_PULLUP_ENABLE,
    .scl_pullup_en = GPIO_PULLUP_ENABLE,
    .master = {
      .clk_speed = 400000
    },
    .clk_flags = 0
  };
  esp_err_t ret;
  ret = i2c_param_config( I2C_NUM_0, &m_i2c_config );
  if( ret == ESP_OK ) {
    ESP_LOGI( LOG_TAG, "Config OK!" );
  }
  else {
    ESP_LOGE( LOG_TAG, "Error in config" );
  }
  ret = i2c_driver_install( I2C_NUM_0, m_i2c_config.mode, 0, 0, 0 );
  if( ret == ESP_OK ) {
    ESP_LOGI( LOG_TAG, "Initialization OK!" );
  }
  else {
    ESP_LOGE( LOG_TAG, "Initialization failed." );
  }

}

rtc::~rtc() {
  
}

void rtc::sync_from_systime() {

  time_t t = time( NULL );
  tm *now = gmtime( &t );
  uint8_t data[ 7 ];

  data[ 0 ] = dec2bcd( now->tm_sec );
  data[ 1 ] = dec2bcd( now->tm_min );
  data[ 2 ] = dec2bcd( now->tm_hour );
  data[ 3 ] = dec2bcd( now->tm_wday );
  data[ 4 ] = dec2bcd( now->tm_mday );
  data[ 5 ] = dec2bcd( now->tm_mon );
  data[ 6 ] = dec2bcd( now->tm_year );

  i2c_cmd_handle_t cmd = i2c_cmd_link_create();
  i2c_master_start( cmd );
  i2c_master_write_byte( cmd, 0xd0, true );
  i2c_master_write_byte( cmd, 0x00, true );
  i2c_master_write( cmd, data, 7, true );
  i2c_master_stop( cmd );
  esp_err_t ret = i2c_master_cmd_begin( I2C_NUM_0, cmd, pdMS_TO_TICKS( 100 ) );
  if( ret != ESP_OK ) {
    ESP_LOGE( LOG_TAG, "Failed to execute commands" );
  }
  else {
    ESP_LOGI( LOG_TAG, "Holy crap, it went through!" );
  }
  i2c_cmd_link_delete( cmd );
}

void rtc::get_time( tm &rtc_tm ) {

  uint8_t data[ 7 ];
  memset( data, 0x00, sizeof( data ) );

  i2c_cmd_handle_t cmd = i2c_cmd_link_create();
  i2c_master_start( cmd );
  i2c_master_write_byte( cmd, 0xd0, true );
  i2c_master_write_byte( cmd, 0x00, true );
  i2c_master_start( cmd );
  i2c_master_write_byte( cmd, 0xd1, true );
  i2c_master_read( cmd, data, 7, I2C_MASTER_LAST_NACK );
  i2c_master_stop( cmd );
  esp_err_t ret = i2c_master_cmd_begin( I2C_NUM_0, cmd, pdMS_TO_TICKS( 1000 ) );
  if( ret != ESP_OK ) {
    ESP_LOGE( LOG_TAG, "Failed to execute commands" );
    return;
  }
  i2c_cmd_link_delete( cmd );

  rtc_tm.tm_sec = bcd2dec( data[ 0 ] );
  rtc_tm.tm_min = bcd2dec( data[ 1 ] );
  rtc_tm.tm_hour = bcd2dec( data[ 2 ] );
  rtc_tm.tm_wday = bcd2dec( data[ 3 ] );
  rtc_tm.tm_mday = bcd2dec( data[ 4 ] );
  rtc_tm.tm_mon = bcd2dec( data[ 5 ] );
  rtc_tm.tm_year = bcd2dec( data[ 6 ] );

}

void rtc::get_time_string( char *buf, size_t len, tm *t ) {
  memset( buf, 0x00, len );
  strftime( buf, len - 1, "%Y-%m-%d %H:%M:%S", t );
}

void rtc::save_current_timezone() {
  const char *tzutc = "UTC+0";
  const char *etz = getenv( "TZ" );
  strncpy( m_tz, etz ? etz : tzutc, sizeof( m_tz ) );
}

// Temporarily swap to UTC
void rtc::utc_push() {
  save_current_timezone();
  setenv( "TZ", "UTC+0", 1 );
  tzset();
}

// Go back to previous TZ
void rtc::utc_pop() {
  setenv( "TZ", m_tz, 1 );
  tzset();
}

void rtc::sync_to_systime() {
  utc_push();
  tm t;
  memset( &t, 0x00, sizeof( t ) );
  get_time( t );
  time_t rtctime = mktime( &t );
  char rtctimestr[ 100 ];
  get_time_string( rtctimestr, sizeof( rtctimestr ), &t );
  timeval tv = {
    .tv_sec = rtctime,
    .tv_usec = 0
  };
  settimeofday( &tv, NULL );
  utc_pop();
  ESP_LOGI( LOG_TAG, "System time adjusted (UTC %s)", rtctimestr );
}

void rtc::print_time() {
  tm rtctime;
  memset( &rtctime, 0x00, sizeof( rtctime ) );
  get_time( rtctime );
  char time_str[ 100 ];
  get_time_string( time_str, sizeof( time_str ), &rtctime );
  ESP_LOGI( LOG_TAG, "RTC time: %s", time_str );
}

uint8_t rtc::dec2bcd( uint8_t val ) {
  return ( ( val / 10 ) << 4 ) + ( val % 10 );
}

uint8_t rtc::bcd2dec( uint8_t val ) {
  return ( val >> 4 ) * 10 + ( val & 0x0f );
}
