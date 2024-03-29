
/**
    BISMON related GCC12 metaplugin header gcc12_metaplugin_BMGCC.hh
    See https://github.com/bstarynk/bismon/

    Copyright © 2020 - 2022 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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

#ifndef GCC12_METAPLUGIN_BISMON_INCLUDED_
#define  GCC12_METAPLUGIN_BISMON_INCLUDED_ 1

//// the conventional prefix or suffix in names is BMP - for BisMon Plugin

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif


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
#include "attribs.h"
#include "errors.h"


/// FIXME: perhaps BMPCC_gcc_function should be a trivial subclass of function from GCC?
typedef function BMPCC_gcc_function;

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <functional>

#include <cstdio>
#include <cassert>

#include <unistd.h>
#include <time.h>
#include <math.h>

#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>


#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>


extern "C" int plugin_is_GPL_compatible;

extern "C" std::string bismon_url_prefix_BMPCC;
extern "C" std::string bismon_project_BMPCC;
extern "C" std::string bismon_cookie_file_BMPCC;
extern "C" std::string bismon_line_prefix_BMPCC;
extern "C" pid_t bismon_pid_BMPCC;


extern "C" const pass_data BMP_gimple_pass_data;

// for GCC plugin event PLUGIN_START_UNIT
extern "C" void BMP_start_unit_handler(void*gccdata,void*userdata);

// for GCC plugin event PLUGIN_ALL_PASSES_END
extern "C" void BMP_all_passes_end_handler(void*gccdata,void*userdata);

// for GCC plugin event PLUGIN_FINISH
extern "C" void BMP_finish_handler(void*gccdata,void*userdata);

// for GCC plugin event PLUGIN_INCLUDE_FILE
extern "C" void BMP_include_file_handler(void*gccdata,void*userdata);

class BMP_gimple_pass : public gimple_opt_pass
{
public:
  BMP_gimple_pass(gcc::context* ctxt)
    : gimple_opt_pass(BMP_gimple_pass_data, ctxt)
  {
  };
  /* opt_pass methods: */
  opt_pass* clone();
  virtual bool gate (function *);
  virtual unsigned int execute(function*);
};				// end BMP_gimple_pass

class BMP_set_of_functions;
extern void gt_ggc_mx(BMP_set_of_functions*);
extern void gt_pch_nx(BMP_set_of_functions*);
extern void gt_pcx_nx(BMP_set_of_functions*, gt_pointer_operator op, void*cookie);

class GTY((user)) BMP_set_of_functions
{
  static constexpr unsigned setfun_required_magic = 135889017; /*0x8198079*/
  unsigned set_magic;
  std::set<BMPCC_gcc_function*> set_funptr;
  friend void gt_ggc_mx(BMP_set_of_functions*);
  friend void gt_pch_nx(BMP_set_of_functions*);
  friend void gt_pcx_nx(BMP_set_of_functions*, gt_pointer_operator op, void*cookie);
public:
  typedef void do_functionptr_plain_t(function*);
  BMP_set_of_functions() : set_magic(setfun_required_magic), set_funptr() {};
  ~BMP_set_of_functions()
  {
    set_magic = 0;
    set_funptr.clear();
  };
  void check_magic(void) const
  {
    if (set_magic != setfun_required_magic)
      fatal_error(UNKNOWN_LOCATION, "corrupted bismon set of functions");
  };
  void add_funptr(BMPCC_gcc_function*func)
  {
    gcc_assert(func != nullptr);
    set_funptr.insert(func);
  };
  void every_funptr_do(do_functionptr_plain_t*do_f)
  {
    for (BMPCC_gcc_function* funptr : set_funptr)
      {
        gcc_assert(funptr != nullptr);
        (*do_f)(funptr);
      }
  };
  void every_funptr_do_lambda(std::function<void(BMPCC_gcc_function*)> do_it)
  {
    for (BMPCC_gcc_function* funptr : set_funptr)
      {
        gcc_assert(funptr != nullptr);
        do_it(funptr);
      }
  }
};				// end class BMP_set_of_functions


/// do a POST HTTP request to Bismon
class BMP_post_jsoncurl
{
  Json::Value pjs_jsonval;
protected:
  BMP_post_jsoncurl(const Json::Value&jv) :
    pjs_jsonval(jv) {};
  virtual ~BMP_post_jsoncurl() = default;
  BMP_post_jsoncurl(const BMP_post_jsoncurl&) = default;
  BMP_post_jsoncurl(BMP_post_jsoncurl&&) = default;
public:
  void do_post();
};				// end class BMP_post_jsoncurl

#warning we may need types with Gty annotations here, and extern variables...
/* see comments in file build-gcc12_metaplugin.sh */
#endif /*GCC12_METAPLUGIN_BISMON_INCLUDED_*/
/****************
 **                           for Emacs...
 ** Local Variables: ;;
 ** compile-command: "./build-gcc12_metaplugin.sh" ;;
 ** End: ;;
 ****************/
/* end of header file gcc12_metaplugin_BMGCC.hh */
