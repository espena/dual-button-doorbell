/*
 *  This file is part of the dual-http_context_config doorbell project.
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

#ifndef __http_context_config_hpp__
#define __http_context_config_hpp__

namespace espena::components {

  class http_context_config {

    static const char *LOG_TAG;

    public:

      http_context_config();
      ~http_context_config();

      const char * response();

  }; // class http_context_config

}; // namespace espena

#endif // __http_context_config_hpp__
