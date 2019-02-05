// file jsonjansson_BM.c; support for JSON payload above jansson library
// see https://jansson.readthedocs.io/

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
#include "jsonjansson_BM.const.h"

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


bool
objputjansjsonpayl_BM (objectval_tyBM * obj, json_t * js)
{
  objectval_tyBM *k_json_object = BMK_7hNqn2hxg1M_3wNHCtOf9IF;
  if (!isobject_BM (obj))
    return false;
  if (objhasjansjsonpayl_BM (obj))
    {
      // special case for previously existing jansson payload
      struct jansjson_stBM *oldjjs = obj->ob_payl;
      ASSERT_BM (valtype_BM (oldjjs) == typayl_jansjson_BM);
      if (oldjjs->jansjson_ptr)
        json_decref (oldjjs->jansjson_ptr), oldjjs->jansjson_ptr = NULL;
      oldjjs->jansjson_ptr = js;
      return true;
    }
  struct jansjson_stBM *jjs =   //
    allocgcty_BM (typayl_jansjson_BM,
                  sizeof (*jjs));
  jjs->jansjson_ptr = js;
  objputpayload_BM (obj, jjs);
  if (!objectisinstance_BM (obj, k_json_object))
    objputclass_BM (obj, k_json_object);
  return true;
}                               /* end objputjansjsonpayl_BM */

bool
objputincrefjansjsonpayl_BM (objectval_tyBM * obj, json_t * js)
{
  objectval_tyBM *k_json_object = BMK_7hNqn2hxg1M_3wNHCtOf9IF;
  if (!isobject_BM (obj))
    return false;
  if (objhasjansjsonpayl_BM (obj))
    {
      // special case for previously existing jansson payload
      struct jansjson_stBM *oldjjs = obj->ob_payl;
      ASSERT_BM (valtype_BM (oldjjs) == typayl_jansjson_BM);
      if (oldjjs->jansjson_ptr)
        json_decref (oldjjs->jansjson_ptr), oldjjs->jansjson_ptr = NULL;
      oldjjs->jansjson_ptr = js;
      if (js)
        json_incref (js);
      return true;
    }
  struct jansjson_stBM *jjs =   //
    allocgcty_BM (typayl_jansjson_BM,
                  sizeof (*jjs));
  jjs->jansjson_ptr = js;
  if (js)
    json_incref (js);
  objputpayload_BM (obj, jjs);
  if (!objectisinstance_BM (obj, k_json_object))
    objputclass_BM (obj, k_json_object);
  return true;
}                               /* end objputincrefjansjsonpayl_BM */


objectval_tyBM *
objkindjansjsonpayl_BM (const objectval_tyBM * obj)
{
  objectval_tyBM *k_json_object = BMK_7hNqn2hxg1M_3wNHCtOf9IF;
  objectval_tyBM *k_json_array = BMK_56Om4CG9rer_8xF06AhNZ1I;
  objectval_tyBM *k_json_string = BMK_419If27jxwQ_3WQnLqU53iq;
  objectval_tyBM *k_json_integer = BMK_8jCh9loDpOL_4eR6Nzk21xp;
  objectval_tyBM *k_json_real = BMK_5ewBEYZh7EM_6dEinrBFpAE;
  objectval_tyBM *k_json_true = BMK_0ekuRPtKaIF_3nrHrhB59Kn;
  objectval_tyBM *k_json_false = BMK_1h1MMlmQi6f_2Z2g6rGMcPB;
  objectval_tyBM *k_json_null = BMK_6WOSg1mpNxQ_6Dw2klXZFSk;
  json_t *js = objgetjansjsonpayl_BM (obj);
  if (!js)
    return NULL;
  switch (json_typeof (js))
    {
    case JSON_OBJECT:
      return k_json_object;
    case JSON_ARRAY:
      return k_json_array;
    case JSON_STRING:
      return k_json_string;
    case JSON_INTEGER:
      return k_json_integer;
    case JSON_REAL:
      return k_json_real;
    case JSON_TRUE:
      return k_json_true;
    case JSON_FALSE:
      return k_json_false;
    case JSON_NULL:
      return k_json_null;
    default:
      return NULL;
    }
}                               /* end objkindjansjsonpayl_BM */


json_t *
jansjsonfromvalue_BM (value_tyBM val, int depth, struct stackframe_stBM *stkf)
{
}                               /* end jansjsonfromvalue_BM */

///// end of file jsonjansson_BM.c
