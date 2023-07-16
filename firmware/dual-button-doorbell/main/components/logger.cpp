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

#include "logger.hpp"
#include "esp_log.h"
#include "string.h"
#include "time.h"
#include "i_file_io.hpp"

using namespace espena::components;

const char *logger::LOG_TAG = "logger";

logger::logger( const logger::configuration &config ) :
  m_config( config ),
  m_max_file_size_mb( config.max_file_size_mb ), // Default value
  m_filesys( NULL )
{

}

logger::~logger() {

}

void logger::init( i_file_io *filesys,
                   size_t max_file_size_mb )
{
  m_filesys = filesys;
  if( max_file_size_mb > 0 ) {
    m_max_file_size_mb = max_file_size_mb;
  }
}

void logger::write( const entry &e ) {
  ESP_LOGI( LOG_TAG,
            "Writing log entry: Btn ID %d, Btn Label: %s, Mode: %s",
            e.btn_id,
            e.btn_label.c_str(),
            e.mode.c_str() );
  if( m_filesys ) {
    FILE *fp = m_filesys->open_file( m_config.filename.c_str(), "a+" );
    size_t log_len = ftell( fp );
    ESP_LOGI( LOG_TAG, "Current log file length: %d bytes", log_len );
    if( fp && log_len < ( m_max_file_size_mb * 1000000 ) ) {
      static const size_t max_line_len = 200;
      char log_line[ max_line_len + 1 ]; // Make room for newline at end
      tm *time_tm = localtime( &e.timestamp );
      char time_str[ 20 ];
      memset( &time_str, 0x00, sizeof( time_str ) );
      strftime( time_str, sizeof( time_str ), "%Y-%m-%d %H:%M:%S", time_tm );
      snprintf( log_line,
                max_line_len, "%s Button %d: %s - Mode: %s",
                time_str,
                e.btn_id,
                e.btn_label.c_str(),
                e.mode.c_str() );
      fputs( strncat( log_line, "\n", 2 ), fp );
      m_filesys->close_file( fp );
    }
    else {
      ESP_LOGW( 
        LOG_TAG,
        "Maximum log size of %d MB exceeded, write operation aborted",
        m_max_file_size_mb );
    }
  }
  else {
    ESP_LOGE( LOG_TAG, "File system not initialized" );
  }
}