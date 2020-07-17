// file BM_compmod_guile.cc on https://github.com/bstarynk/bismon/
// SPDX-License-Identifier: GPL-3.0-or-later

/***
    BISMON
    Copyright © 2020 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch (working at CEA, LIST, France)
    <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>

    BM_compile_module: a standalone program to compile a BISMON
    generated module or GCC plugin. This file BM_compmod_guile.cc
    contains GNU guile primitives. See
    https://www.gnu.org/software/guile/ for more about GNU guile.

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

***/

#include "BM_compmod.hh"

static SCM
bmc_scm_help (SCM) {
  std::clog << ";; lisp of BM_compile_module Guile primitives." << std::endl;
  std::clog << "(bmc:help) ;; gives this help" << std::endl;
  return SCM_UNSPECIFIED;
} // end bmc_scm_help

void*
bmc_run_guile(void*vec)
{
  assert (vec == &bmc_guile_vec);
  /// define our extra Guile primitives
  scm_c_define_gsubr("bmc:help", /*requested:*/0, /*optional:*/0, /*rest:*/0,
		     (scm_t_subr)bmc_scm_help);
} // end of bmc_run_guile

// end of file BM_compmod_guile.cc
