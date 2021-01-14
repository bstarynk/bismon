
/**
    BISMON related GCC10 metaplugin header gcc10-metaplugin.hh
    See https://github.com/bstarynk/bismon/

    Copyright © 2020 - 2021 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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

**/

#ifndef GCC10_METAPLUGIN_BISMON_INCLUDED_
#define  GCC10_METAPLUGIN_BISMON_INCLUDED_ 1

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

#include <cstdio>
#include <cassert>

#include <unistd.h>
#include <time.h>
#include <math.h>

#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>


#include <curl/curl.h>


#include "gcc-plugin.h"
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "stringpool.h"
#include "toplev.h"
#include "basic-block.h"
#include "hash-table.h"
#include "vec.h"
#include "ggc.h"
#include "basic-block.h"
#include "tree-ssa-alias.h"
#include "internal-fn.h"
#include "gimple-fold.h"
#include "tree-eh.h"
#include "gimple-expr.h"
#include "is-a.h"
#include "gimple.h"
#include "gimple-iterator.h"
#include "tree.h"
#include "tree-pass.h"
#include "toplev.h"
#include "intl.h"
#include "plugin-version.h"
#include "diagnostic.h"
#include "context.h"



extern "C" int plugin_is_GPL_compatible;



#endif /*GCC10_METAPLUGIN_BISMON_INCLUDED_*/
/* end of header file gcc10-metaplugin.hh */
