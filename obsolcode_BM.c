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

#define OBSOLETEROUTINE_BM(Oid) ROUTINEOBJNAME_BM(Oid)
////////////////
// commandhandler#,insert _01zabIzVKNR_8AGQGMBkSd7

extern objrout_sigBM ROUTINEOBJNAME_BM (_01zabIzVKNR_8AGQGMBkSd7);
value_tyBM
OBSOLETEROUTINE_BM (_01zabIzVKNR_8AGQGMBkSd7)   //commandhandler#,insert 
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
OBSOLETEROUTINE_BM (_09DxyieS5Wz_7pkad4F88FA)   // gtk_browse_data°class
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
OBSOLETEROUTINE_BM (_0f1S28bCE26_3X6Vpz9lG4A)   //gtk_browse_data°assoc_object
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

/// command handler for ,remove
extern objrout_sigBM ROUTINEOBJNAME_BM (_0zf6nSKwSlU_6Cv3LMh1MmV);
value_tyBM
OBSOLETEROUTINE_BM (_0zf6nSKwSlU_6Cv3LMh1MmV)   //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the attr or index
 const value_tyBM arg3_ __attribute__((unused)),        // 
 const value_tyBM arg4_ __attribute__((unused)),        // 
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; value_tyBM attv;
    );
  _.recv = arg1;
  FATAL_BM
    ("°°obsolete ,remove command handler _0f1S28bCE26_3X6Vpz9lG4A recv %s",
     objectdbg_BM (_.recv));
}                               /* endobsol remove command handler  _0f1S28bCE26_3X6Vpz9lG4A  */

/// method to gtk_browse_value for tuple-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_0B1PYH9bN34_3RZdP24AVyt);
value_tyBM
OBSOLETEROUTINE_BM (_0B1PYH9bN34_3RZdP24AVyt)   // gtk_browse_value°tuple
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3,         // the current depth
 const value_tyBM arg4_ __attribute__((unused)),
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const tupleval_tyBM * tupbrows;
                 const objectval_tyBM * objbrows;);
  _.tupbrows = (const tupleval_tyBM *) arg1;
  FATAL_BM
    ("°°obsolete gtk_browse_value for tuple _0f1S28bCE26_3X6Vpz9lG4A recv %s",
     OUTSTRVALUE_BM (_.tupbrows));
}                               /* endobsol  gtk_browse_value for tuple-s _0B1PYH9bN34_3RZdP24AVyt */

/// method to gtk_browse_value for object-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_0BAnB0xjs23_0WEOCOi5Nbe);
value_tyBM
OBSOLETEROUTINE_BM (_0BAnB0xjs23_0WEOCOi5Nbe)   // gtk_browse_value°object
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3,         // the current depth
 const value_tyBM arg4 __attribute__((unused)),
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows;       //
    );
  _.objbrows = (const objectval_tyBM *) arg1;
  FATAL_BM
    ("°°obsolete gtk_browse_value for object _0BAnB0xjs23_0WEOCOi5Nbe recv %s",
     objectdbg_BM (_.objbrows));
}                               /* endobsol   gtk_browse_value for object-s _0BAnB0xjs23_0WEOCOi5Nbe */

// command_handler#find_object _0FdMKAvShgD_7itPSCL8D6P

/// ,find_object (criteria moreobjects predicateskip)
extern objrout_sigBM ROUTINEOBJNAME_BM (_0FdMKAvShgD_7itPSCL8D6P);

value_tyBM
OBSOLETEROUTINE_BM (_0FdMKAvShgD_7itPSCL8D6P)   // command_handler#find_object
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // criterv
 const value_tyBM arg2,         // moreobjv
 const value_tyBM arg3,         // predskipv
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;   //
    );
  _.recv = arg1;
  FATAL_BM
    ("°°obsolete  command_handler#find_object recv %s",
     objectdbg_BM (_.recv));
}                               /* endobsol  command_handler#find_object_0FdMKAvShgD_  */


/// method to gtk_browse_value for int-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_0HBMCM5CeLn_7L5YEV2jO7Y);
value_tyBM
OBSOLETEROUTINE_BM (_0HBMCM5CeLn_7L5YEV2jO7Y)   // gtk_browse_value°int
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3,         // the current depth
 const value_tyBM arg4 __attribute__((unused)), //
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  FATAL_BM ("°°obsolete gtk_browse_value for int %ld",
            (long) getint_BM (arg1));
}                               /* endobsol gtk_browse_value for int-s _0HBMCM5CeLn_7L5YEV2jO7Y */


// gtk_browse_data°hashmapval_object _0M2jApBzFAy_8H8cpCjGpTi
extern objrout_sigBM ROUTINEOBJNAME_BM (_0M2jApBzFAy_8H8cpCjGpTi);

value_tyBM
OBSOLETEROUTINE_BM (_0M2jApBzFAy_8H8cpCjGpTi)   //gtk_browse_data°hashmapval_object 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // object
 const value_tyBM arg2,         // depth
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, NULL,
                 const objectval_tyBM * recv;   //
    );
  _.recv = arg1;
  FATAL_BM
    ("°°obsolete gtk_browse_data°hashmapval_object _0M2jApBzFAy_8H8cpCjGpTi recv %s",
     objectdbg_BM (_.recv));
}                               /* endobsol gtk_browse_data°hashmapval_object _0M2jApBzFAy_8H8cpCjGpTi  */



////////////////////////////////////////////////////////////////
// test_agenda command_handler _1eQ1a8KHixZ_1XDNH5iTQ0I
extern objrout_sigBM ROUTINEOBJNAME_BM (_1eQ1a8KHixZ_1XDNH5iTQ0I);
value_tyBM
OBSOLETEROUTINE_BM (_1eQ1a8KHixZ_1XDNH5iTQ0I)   //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // object
 const value_tyBM arg2,         // depth
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;   //
    );
  _.recv = arg1;
  FATAL_BM
    ("°°obsolete test_agenda command_handler _1eQ1a8KHixZ_1XDNH5iTQ0I recv %s",
     objectdbg_BM (_.recv));
}                               /* endobsol  test_agenda command_handler _1eQ1a8KHixZ_1XDNH5iTQ0I */

// code for _1tcgbIFhbTu_9WdGaq8NHWp gtk_browse_data°websession_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_1tcgbIFhbTu_9WdGaq8NHWp);

value_tyBM
OBSOLETEROUTINE_BM (_1tcgbIFhbTu_9WdGaq8NHWp)   //
(struct stackframe_stBM * stkf, // //
 const value_tyBM arg1,         // object
 const value_tyBM arg2,         // depth
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;   //
    );
  _.recv = arg1;
  FATAL_BM
    ("°°obsolete gtk_browse_data°websession_object _1tcgbIFhbTu_9WdGaq8NHWp recv %s",
     objectdbg_BM (_.recv));
}                               /* endobsol  gtk_browse_data°websession_object _1tcgbIFhbTu_9WdGaq8NHWp */

/// command handler for ,put
extern objrout_sigBM ROUTINEOBJNAME_BM (_1Xc5XJ7S5r7_3nYIzlf2XAw);
value_tyBM
OBSOLETEROUTINE_BM (_1Xc5XJ7S5r7_3nYIzlf2XAw)   // ,put commandhandler
(struct stackframe_stBM * stkf, // //
 const value_tyBM arg1,         // object
 const value_tyBM arg2,         // depth
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;   //
    );
  _.recv = arg1;
  FATAL_BM
    ("°°obsolete ,put commandhandler _1tcgbIFhbTu_9WdGaq8NHWp recv %s",
     objectdbg_BM (_.recv));
}                               /* endobsol ,put commandhandler _1tcgbIFhbTu_9WdGaq8NHWp */

/// method to gtk_browse_in_object°object-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_23ViGouPnAg_15P5mpG9x3d);
value_tyBM
OBSOLETEROUTINE_BM (_23ViGouPnAg_15P5mpG9x3d)   //gtk_browse_in_object°object
(struct stackframe_stBM * stkf, // //
 const value_tyBM arg1,         // object
 const value_tyBM arg2,         // depth
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;   //
    );
  _.recv = arg1;
  FATAL_BM
    ("°°obsolete gtk_browse_in_object°object _23ViGouPnAg_15P5mpG9x3d  recv %s",
     objectdbg_BM (_.recv));
}                               /* endobsol gtk_browse_in_object°object _23ViGouPnAg_15P5mpG9x3d */

// emit_module command_handler  _2bzzB0nZuUO_2xfj3rDb3DN

extern objrout_sigBM ROUTINEOBJNAME_BM (_2bzzB0nZuUO_2xfj3rDb3DN);

value_tyBM
OBSOLETEROUTINE_BM (_2bzzB0nZuUO_2xfj3rDb3DN)   // emit_module#command_handler
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // modulob
 const value_tyBM arg2,         //
 const value_tyBM arg3,         //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;   //
    );
  _.recv = arg1;
  FATAL_BM
    ("°°obsolete emit_module#command_handler_23ViGouPnAg_15P5mpG9x3d  recv %s",
     objectdbg_BM (_.recv));
}                               /* endobsol  emit_module#command_handler _2bzzB0nZuUO_2xfj3rDb3DN */

// method gtk_browse_data°list_object _2EtVNhr2mHz_8CsOQJdYeCE
extern objrout_sigBM ROUTINEOBJNAME_BM (_2EtVNhr2mHz_8CsOQJdYeCE);

value_tyBM
OBSOLETEROUTINE_BM (_2EtVNhr2mHz_8CsOQJdYeCE)   // gtk_browse_data°list_object
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // 
 const value_tyBM arg2,         //
 const value_tyBM arg3,         //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;   //
    );
  _.recv = arg1;
  FATAL_BM
    ("°°obsolete gtk_browse_data°list_object _23ViGouPnAg_15P5mpG9x3d  recv %s",
     objectdbg_BM (_.recv));
}                               /* endobsol gtk_browse_data°list_object _2EtVNhr2mHz_8CsOQJdYeCE */


//// gtk_browse_data°json_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_2SwBWHiHN6V_64WhvTifJL4);

value_tyBM
OBSOLETEROUTINE_BM (_2SwBWHiHN6V_64WhvTifJL4)   // gtk_browse_data°json_object
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // 
 const value_tyBM arg2,         //
 const value_tyBM arg3,         //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;   //
    );
  _.recv = arg1;
  FATAL_BM
    ("°°obsolete gtk_browse_data°jsonobject _2SwBWHiHN6V_64WhvTifJL4  recv %s",
     objectdbg_BM (_.recv));
}                               /* endobsol  gtk_browse_data°jsonobject _2SwBWHiHN6V_64WhvTifJL4  */

//  command_handler#transient _2WuloCaOgGk_9oQOcW9c5Je
extern objrout_sigBM ROUTINEOBJNAME_BM (_2WuloCaOgGk_9oQOcW9c5Je);

value_tyBM
OBSOLETEROUTINE_BM (_2WuloCaOgGk_9oQOcW9c5Je)   //  command_handler#transient
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // 
 const value_tyBM arg2,         //
 const value_tyBM arg3,         //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;   //
    );
  _.recv = arg1;
  FATAL_BM
    ("°°obsolete command_handler#transient _2WuloCaOgGk_9oQOcW9c5Je recv %s",
     OUTSTRVALUE_BM (_.recv));
}                               /* endobsol  command_handler#transient _2WuloCaOgGk_9oQOcW9c5Je  */

/// method to gtk_browse_value for set-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_3rne4qbpnV9_0pywzeJp3Qr);
value_tyBM
OBSOLETEROUTINE_BM (_3rne4qbpnV9_0pywzeJp3Qr)   //gtk_browse_value°set
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // 
 const value_tyBM arg2,         //
 const value_tyBM arg3,         //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;   //
    );
  _.recv = arg1;
  FATAL_BM
    ("°°obsolete gtk_browse_value°set _3rne4qbpnV9_0pywzeJp3Qr recv %s",
     OUTSTRVALUE_BM (_.recv));
}                               /* endobsol  gtk_browse_value°set _3rne4qbpnV9_0pywzeJp3Qr  */


//_browse_data°hset_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_4IshjBIv6ol_5korHKUIjeK);
value_tyBM
OBSOLETEROUTINE_BM (_4IshjBIv6ol_5korHKUIjeK)   // gtk_browse_data°hset_object
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // 
 const value_tyBM arg2,         //
 const value_tyBM arg3,         //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ NULL,        //
                 const objectval_tyBM * recv;   //
    );
  _.recv = arg1;
  FATAL_BM
    ("°°obsolete gtk_browse_data°hset_object _4IshjBIv6ol_5korHKUIjeK recv %s",
     objectdbg_BM (_.recv));
}                               /* endobsol  gtk_browse_data°hset_object _4IshjBIv6ol_5korHKUIjeK  */

/*** TODO:
 more obsolete routines should be added by running ./Build then make
 redump ; if it fails with a ./bismon: undefined symbol: crout_XXX
 message add that obsolete routine from attic/guicode_GTKBM.c
***/
