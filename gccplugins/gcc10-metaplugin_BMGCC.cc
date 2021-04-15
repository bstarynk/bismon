
/**
    BISMON related GCC10 metaplugin gcc10-metaplugin_BMGCC.cc
    See https://github.com/bstarynk/bismon/
    Copyright © 2020 - 2021 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch and Franck Védrine

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

#include "gcc10-metaplugin.hh"

int plugin_is_GPL_compatible;


const pass_data BM_gimple_pass_data =
{
  GIMPLE_PASS, /* type */
  "BM_gimple_pass", /* name */
  OPTGROUP_NONE, /* optinfo_flags */
  TV_NONE, /* tv_id */
  ( PROP_ssa | PROP_cfg | PROP_gimple_leh ), /* properties_required */
  0, /* properties_provided */
  0, /* properties_destroyed */
  0, /* todo_flags_start */
  0, /* todo_flags_finish */
};    // end BM_gimple_pass_data

////////////////////////////////////////////////////////////////
int
plugin_init (struct plugin_name_args *plugin_info,
             struct plugin_gcc_version *version)
{
  const char *plugin_name = plugin_info->base_name;
  if (!plugin_default_version_check (version, &gcc_version))
    {
      warning(UNKNOWN_LOCATION, "BISMON GCC10 METAPLUGIN: fail version check for %s:"
              " got %s/%s/%s/%s wanted %s/%s/%s/%s", plugin_name,
              version->basever, version->datestamp, version->devphase, version->revision,
              gcc_version.basever, gcc_version.datestamp, gcc_version.devphase, gcc_version.revision);
      return 1;
    }

  ///
  inform(UNKNOWN_LOCATION, "Bismon GCC10 metaplugin built " __DATE__ " on " __TIME__ " process %d"
#ifdef PLUGINGITID
         " (gitid " PLUGINGITID ")"
#endif
         " (l@%d)",
         (int) getpid(), __LINE__);

  
  return 0;
} // end plugin_init

/****************
 **                           for Emacs...
 ** Local Variables: ;;
 ** compile-command: "./build-gcc10-metaplugin.sh" ;;
 ** End: ;;
 ****************/
////// end of file bismon/gccplugins/gcc10-metaplugin_BMGCC.cc
