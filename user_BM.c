// file user_BM.c; management of European GDPR related personal data; see userlogin.md

/***
    BISMON 
    Copyright © 2018 Basile Starynkevitch (working at CEA, LIST, France)
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
***/
#include "bismon.h"
#include "user_BM.const.h"

objectval_tyBM *
add_contributor_user_BM (const char *str, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * userob;       //
    );
  FATAL_BM ("unimplemented add_contributor_user_BM str %s", str);
#warning unimplemented add_contributor_user_BM
}                               /* end add_contributor_user_BM */

objectval_tyBM *
remove_contributor_user_by_string_BM (const char *str,
                                      struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * userob;       //
    );
  FATAL_BM ("unimplemented remove_contributor_user_by_string_BM str %s", str);
#warning unimplemented remove_contributor_user_by_string_BM
}                               /* end remove_contributor_user_by_string_BM */
