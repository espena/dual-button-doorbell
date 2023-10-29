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
#include "urldecode.hpp"
#include <memory.h>
#include <ctype.h>
#include <string>

std::string espena::utilities::urldecode( std::string url ) {
  std::string decoded;
  std::string::iterator it;
  bool hex_mode = false;
  for( it = url.begin(); it != url.end(); it++ ) {
    if( hex_mode ) {
      char hex[ 3 ] = { 0x00, 0x00, '\0' };
      hex[ 0 ] = *it;
      if( ++it == url.end() ) break;
      hex[ 1 ] = *it;
      decoded.push_back( static_cast<char>( strtol( hex, nullptr, 16 ) ) );
      hex_mode = false;
    }
    else {
      if( *it == '%' ) {
        hex_mode = true;
      }
      else {
        decoded.push_back( *it );
      }
    }
  }
  return decoded;
}