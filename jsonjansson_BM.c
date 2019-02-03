// file jsonjansson_BM.c

/***
    BISMON 
    Copyright © 2019 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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
***/
#include "bismon.h"

void
jansjsongcmark_BM (struct garbcoll_stBM *gc,
                   struct jansjson_stBM *jjs,
                   objectval_tyBM * fromob, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (!fromob || isobject_BM (fromob));
  ASSERT_BM (((typedhead_tyBM *) jjs)->htyp == typayl_jansjson_BM);
  uint8_t oldmark = ((typedhead_tyBM *) jjs)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) jjs)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
}                               /* end jansjsongcmark_BM */

void
jansjsongcdestroy_BM (struct garbcoll_stBM *gc, struct jansjson_stBM *jjs)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) jjs)->htyp == typayl_jansjson_BM);
  if (jjs->jansjson_ptr)
    {
      json_t *js = jjs->jansjson_ptr;
      jjs->jansjson_ptr = NULL;
      json_decref (js);
    }
  gc->gc_freedbytes += sizeof (*jjs);
  memset (jjs, 0, sizeof (*jjs));
  free (jjs);
}                               /* end jansjsongcdestroy_BM */

void
jansjsongckeep_BM (struct garbcoll_stBM *gc, struct jansjson_stBM *jjs)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) jjs)->htyp == typayl_jansjson_BM);
  gc->gc_keptbytes += sizeof (*jjs);
}                               /* end jansjsongckeep_BM */

///// end of file jsonjansson_BM.c
