
/**
    BISMON related GCC10 metaplugin gcc10-metaplugin_BMGCC.cc
    See https://github.com/bstarynk/bismon/
    Copyright © 2020 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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

int plugin_is_GPL_compatible;

////////////////////////////////////////////////////////////////
int
plugin_init (struct plugin_name_args *plugin_info,
             struct plugin_gcc_version *version)
{
  const char *plugin_name = plugin_info->base_name;
  if (!plugin_default_version_check (version, &gcc_version))
    {
      warning(UNKNOWN_LOCATION, "BISMON_GCC10_METAPLUGIN: fail version check for %s:\n"
              " got %s/%s/%s/%s wanted %s/%s/%s/%s", plugin_name,
              version->basever, version->datestamp, version->devphase, version->revision,
              gcc_version.basever, gcc_version.datestamp, gcc_version.devphase, gcc_version.revision);
      return 1;
    }

  ///
  inform(UNKNOWN_LOCATION, "BISMON_GCC10_METAPLUGIN: built " __DATE__ " on " __TIME__ " process %d"
#ifdef PLUGINGITID
         "\n(gitid " PLUGINGITID ") "
#endif
         " (l@%d)\n",
         (int) getpid(), __LINE__);

  return 0;
} // end plugin_init

////// end of file bismon/gccplugins/gcc10-metaplugin_BMGCC.cc
