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
#include "i_file_io.hpp"

using namespace espena::components;

const char *logger::LOG_TAG = "logger";

logger::logger( const logger::configuration &config ) :
  m_config( config ),
  m_filesys( NULL )
{

}

logger::~logger() {

}

void logger::start( i_file_io *filesys ) {
  m_filesys = filesys;
}