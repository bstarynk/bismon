// file measure_plugcc.cc
//  Copyright (C) 2017 Free Software Foundation, Inc.

/*
This measure_plugcc.cc file is a GCC plugin doing simple measures.
measure_plugcc.cc is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

measure_plugcc.cc is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#include <iostream>
#include <string>
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
#include "intl.h"
#include "plugin-version.h"
#include "diagnostic.h"
#include "context.h"


extern "C" int plugin_is_GPL_compatible;
int plugin_is_GPL_compatible=1;

static void
start_unit_cb(void *gcc_data, void *)
{
  inform(input_location, "start unit of measure_plugcc");
} // end start_unit_cb

static void
finish_unit_cb(void *gcc_data, void *)
{
  inform(input_location, "finish unit of measure_plugcc");
} // end finish_unit_cb

namespace
{

const pass_data pass_data_measure =
{
  GIMPLE_PASS, /* type */
  "measure_plugcc", /* name */
  OPTGROUP_NONE, /* optinfo_flags */
  TV_NONE, /* tv_id */
  PROP_ssa, /* properties_required */
  0, /* properties_provided */
  0, /* properties_destroyed */
  0, /* todo_flags_start */
  0, /* todo_flags_finish */
};


class pass_measure : public ipa_opt_pass_d
{
  static unsigned int measure_transform (struct cgraph_node *node);
public:
  pass_measure(gcc::context *ctxt)
    : ipa_opt_pass_d(pass_data_measure, ctxt,
                     NULL, /* generate_summary */
                     NULL, /* write_summary */
                     NULL, /* read_summary */
                     NULL, /* write_optimization_summary */
                     NULL, /* read_optimization_summary */
                     NULL, /* stmt_fixup */
                     0, /* function_transform_todo_flags_start */
                     measure_transform, /* function_transform */
                     NULL) /* variable_transform */
  {}

  /* opt_pass methods: */
  bool gate (function *)
  {
    return true;
  }
  virtual unsigned int execute (function *);

}; // class pass_measure

unsigned int
pass_measure::execute (function *fun)
{
  gimple_stmt_iterator gsi;
  basic_block bb;

  FOR_EACH_BB_FN (bb, fun)
  {
    for (gsi = gsi_start_bb (bb); !gsi_end_p (gsi); gsi_next (&gsi))
      {
        // warn_self_assign (gsi_stmt (gsi))
      };
  }

  return 0;
}

unsigned int pass_measure::measure_transform (struct cgraph_node *node)
{
  return 0;
} // end pass_measure::measure_transform

} // anon namespace

int
plugin_init (struct plugin_name_args *plugin_info,
             struct plugin_gcc_version *version)
{
  struct register_pass_info measure_pass_info =
  {
    .pass = nullptr,
    .reference_pass_name = "inline",
    .ref_pass_instance_number = 0,
    .pos_op = PASS_POS_INSERT_AFTER
  };
  plugin_info->version = "measure_plugcc " __DATE__;
  plugin_info->help = "measure_plugcc is measuring";
  if (!plugin_default_version_check (version, &gcc_version))
    return 1;
  register_callback(plugin_info->base_name, PLUGIN_START_UNIT,
                    start_unit_cb, nullptr);
  register_callback(plugin_info->base_name, PLUGIN_FINISH_UNIT,
                    finish_unit_cb, nullptr);
  /* Register the new pass.  */
  measure_pass_info.pass = new pass_measure(g);
#warning this does not work, dont know how to insert the pass
  register_callback (plugin_info->base_name, PLUGIN_PASS_MANAGER_SETUP,
                     nullptr, &measure_pass_info);
  return  0;
} // end plugin_init
