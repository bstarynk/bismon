// file obsolcode_BM.c 
// SPDX-License-Identifier: GPL-3.0-or-later

/***
    BISMON 
    Copyright © 2018 - 2021 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch (working at CEA, LIST, France)
    <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>

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

   This file obsolcode_BM.c contains routines which are dlsym-ed but
   should not be called anymore. These routines used to be in
   attic/guicode_BM.c
***/

#include "bismon.h"

////////////////
// commandhandler#,insert _01zabIzVKNR_8AGQGMBkSd7

extern objrout_sigBM ROUTINEOBJNAME_BM (_01zabIzVKNR_8AGQGMBkSd7);
value_tyBM
ROUTINEOBJNAME_BM (_01zabIzVKNR_8AGQGMBkSd7)    //commandhandler#,insert 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // object
 const value_tyBM arg2,         // rank 
 const value_tyBM arg3,         // value
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv;);
  _.recv = arg1;
  FATAL_BM
    ("°°obsolete commandhandler#,insert  _01zabIzVKNR_8AGQGMBkSd7 recv %s",
     objectdbg_BM (_.recv));
}                               /* endobsol commandhandler#,insert  _01zabIzVKNR_8AGQGMBkSd7 */

/// method to gtk_browse_data for class-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_09DxyieS5Wz_7pkad4F88FA);
value_tyBM
ROUTINEOBJNAME_BM (_09DxyieS5Wz_7pkad4F88FA)    // gtk_browse_data°class
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3 __attribute__((unused)), //
 const value_tyBM arg4 __attribute__((unused)), //
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv;);
  _.recv = arg1;
  FATAL_BM
    ("°°obsolete gtk_browse_data for class-s _09DxyieS5Wz_7pkad4F88FA recv %s",
     objectdbg_BM (_.recv));
}                               /* endobsol gtk_browse_data for class-s _09DxyieS5Wz_7pkad4F88FA */


//gtk_browse_data°assoc_object _0f1S28bCE26_3X6Vpz9lG4A
extern objrout_sigBM ROUTINEOBJNAME_BM (_0f1S28bCE26_3X6Vpz9lG4A);

value_tyBM
ROUTINEOBJNAME_BM (_0f1S28bCE26_3X6Vpz9lG4A)    //gtk_browse_data°assoc_object
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         //
 const value_tyBM arg2,         //
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ NULL, const objectval_tyBM * recv;
    );
  _.recv = arg1;
  FATAL_BM
    ("°°obsolete gtk_browse_data for assoc_object-s _0f1S28bCE26_3X6Vpz9lG4A recv %s",
     objectdbg_BM (_.recv));
}                               /* endobsol gtk_browse_data°assoc_object _0f1S28bCE26_3X6Vpz9lG4A */
