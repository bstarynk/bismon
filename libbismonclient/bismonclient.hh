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
#include <mutex>
#include <string>

/// JSONCPP from https://github.com/open-source-parsers/jsoncpp
#include "jsoncpp/json/json.h"

/// BAD, since don't compile.
/// JSON from https://github.com/nlohmann/json.git
/// a single include file....
/// BAD include "nlohmann/json.hpp"

/// BAD, since don't compile. JSONRCPCXX from
/// https://github.com/jsonrpcx/json-rpc-cxx.git
/// BAD include "jsonrpccxx/client.hpp"

class BMC_request
{
  std::string req_path;
  Json::Value req_json;
  static std::string req_port_string;
protected:
  static std::mutex req_mtx;
  BMC_request(const std::string& path, const Json::Value &json);
public:
  static const char*git_id()
  {
    return BISMONCL_GITID;
  };
  virtual Json::Value do_request(void) =0;
  virtual ~BMC_request(void);
};				// end class BMC_request


class BMC_jsonrpc_request : public BMC_request
{
protected:
  BMC_jsonrpc_request(const std::string& path, const Json::Value &json);
  virtual ~BMC_jsonrpc_request();
public:
  virtual Json::Value do_request(void);
};				// end class  BMC_jsonrpc_request
#endif /*BISMONCLIENT_INCLUDED*/
