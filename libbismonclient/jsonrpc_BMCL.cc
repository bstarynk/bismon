// file libbismonclient/jsonrpc_BMCL.cc in BISMON

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

#include "bismonclient.hh"

BMC_jsonrpc_request::BMC_jsonrpc_request(const std::string& path, const Json::Value &json)
  : BMC_request::BMC_request(path, json)
{
} // end constructor BMC_jsonrpc_request::BMC_jsonrpc_request


BMC_jsonrpc_request::~BMC_jsonrpc_request()
{
} // end destructor BMC_jsonrpc_request::~BMC_jsonrpc_request


Json::Value
BMC_jsonrpc_request::do_request()
{
  std::lock_guard<std::mutex> gu(req_mtx);
} // end BMC_jsonrpc_request::run_request
