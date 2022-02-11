// file bismonclient.hh
#ifndef BISMONCLIENT_INCLUDED
#define BISMONCLIENT_INCLUDED
// SPDX-License-Identifier: GPL-3.0-or-later
/**
    BISMON 
    Copyright © 2022 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

----
    Contact me (Basile Starynkevitch) by email
    basile@starynkevitch.net and/or basile.starynkevitch@cea.fr
**/

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <set>
#include <map>
#include <chrono>

#include "jsoncpp/json/json.h"

class BMC_request {
  std::string req_path;
  Json::Value req_json;
protected:
  BMC_request(const std::string& path, const Json::Value &json);
public:
  virtual ~BMC_request(void);
};				// end class BMC_request


class BMC_jsonrpc_request : public BMC_request {
protected:
  BMC_jsonrpc_request(const std::string& path, const Json::Value &json);
  virtual ~BMC_jsonrpc_request();
};				// end class  BMC_jsonrpc_request
#endif /*BISMONCLIENT_INCLUDED*/
