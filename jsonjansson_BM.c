// file jsonjansson_BM.c; support for JSON payload above jansson library
// see https://jansson.readthedocs.io/
// SPDX-License-Identifier: GPL-3.0-or-later
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
  ASSERT_BM (fromob == NULL || isobject_BM (fromob));
  ASSERT_BM (depth >= 0);
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
objputjansjsoncstrpayl_BM (objectval_tyBM * obj, const char *jsonstr)
{
  if (!isobject_BM (obj))
    return false;
  if (!jsonstr || !jsonstr[0])
    return false;
  json_error_t jserr = { };
  json_t *js = json_loads (jsonstr,
                           JSON_DISABLE_EOF_CHECK | JSON_DECODE_ANY, &jserr);
  if (!js)
    {
      WARNPRINTF_BM
        ("failed to decode json string %.100s - L%dC%d - %s (#%d)", jsonstr,
         jserr.line, jserr.column, jserr.text, json_error_code (&jserr));
      return false;
    }
  return objputjansjsonpayl_BM (obj, js);
}                               /* end objputjsoncstrpayl_BM */



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



void
objputjanssonpayl_BM (objectval_tyBM * objarg, value_tyBM valarg,
                      value_tyBM ctxarg, struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_json = BMK_2gNQ6wSYLGz_9FkMuCIKfmv;
  LOCALFRAME_BM (stkf, /*descr: */ k_json,
                 objectval_tyBM * obj; value_tyBM valv; //
                 value_tyBM ctxv;       //
                 value_tyBM errorv;     //
    );
  _.obj = objectcast_BM (objarg);
  _.valv = valarg;
  _.ctxv = ctxarg;
  if (!_.obj)
    return;
  if (!objputjansjsonpayl_BM
      (_.obj, jansjsonfromvalue_BM (_.valv, _.valv, _.ctxv, 0, CURFRAME_BM)))
    {
      _.errorv = (value_tyBM) makenode3_BM (k_json, _.obj, _.valv, _.ctxv);
      PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
    }
}                               /* end objputjanssonpayl_BM */






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

static void
jansjson_add_to_json_object_bm (json_t * objs, value_tyBM val, value_tyBM src,
                                value_tyBM ctx, int depth,
                                struct stackframe_stBM *stkf);

json_t *
jansjsonifyobject_BM (objectval_tyBM * obj, struct stackframe_stBM *stkf)
{
  ASSERT_BM (stkf != NULL);
  WARNPRINTF_BM ("unimplemented jansjsonifyobject_BM for obj %s",
                 objectdbg_BM (obj));
  return NULL;
#warning unimplemented jansjsonifyobject_BM
}                               /* end jansjsonifyobject_BM */

json_t *
jansjsonifyvalue_BM (value_tyBM val, value_tyBM src,
                     value_tyBM ctx, int depth, struct stackframe_stBM *stkf)
{
  ASSERT_BM (stkf != NULL);
  LOCALFRAME_BM (stkf, /*descr: */ NULL,
    );
  WARNPRINTF_BM ("unimplemented jansjsonifyvalue_BM for val: %s src: %s ctx: %s depth#%d", OUTSTRVALUE_BM (val),        //
                 OUTSTRVALUE_BM (src),  //
                 OUTSTRVALUE_BM (ctx),  //
                 depth);
  return NULL;
#warning unimplemented jansjsonifyvalue_BM
}                               /* end jansjsonifyvalue_BM */

json_t *
jansjsonifynode_BM (value_tyBM val, value_tyBM src,
                    value_tyBM ctx, int depth, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM (stkf, /*descr: */ NULL,
    );
  WARNPRINTF_BM ("unimplemented jansjsonifynode_BM for val: %s src: %s ctx: %s depth#%d", OUTSTRVALUE_BM (val), //
                 OUTSTRVALUE_BM (src),  //
                 OUTSTRVALUE_BM (ctx),  //
                 depth);
  return NULL;
#warning unimplemented jansjsonifynode_BM
}                               /* end jansjsonifynode_BM */

json_t *
jansjsonifyclosure_BM (value_tyBM val, value_tyBM src,
                       value_tyBM ctx, int depth,
                       struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM (stkf, /*descr: */ NULL,
    );
  WARNPRINTF_BM ("unimplemented jansjsonifyclosure_BM for val: %s src: %s ctx: %s depth#%d", OUTSTRVALUE_BM (val),      //
                 OUTSTRVALUE_BM (src),  //
                 OUTSTRVALUE_BM (ctx),  //
                 depth);
  return NULL;
#warning unimplemented jansjsonifyclosure_BM
}                               /* end jansjsonifyclosure_BM */

#define MAXDEPTHJSON_BM 96
json_t *
jansjsonfromvalue_BM (value_tyBM val, value_tyBM src, value_tyBM ctx,
                      int depth, struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_object = BMK_7T9OwSFlgov_0wVJaK1eZbn;
  objectval_tyBM *k_json = BMK_2gNQ6wSYLGz_9FkMuCIKfmv;
  objectval_tyBM *k_json_object = BMK_7hNqn2hxg1M_3wNHCtOf9IF;
  objectval_tyBM *k_json_array = BMK_56Om4CG9rer_8xF06AhNZ1I;
  objectval_tyBM *k_json_string = BMK_419If27jxwQ_3WQnLqU53iq;
  objectval_tyBM *k_json_integer = BMK_8jCh9loDpOL_4eR6Nzk21xp;
  //objectval_tyBM *k_json_real = BMK_5ewBEYZh7EM_6dEinrBFpAE;
  objectval_tyBM *k_json_true = BMK_0ekuRPtKaIF_3nrHrhB59Kn;
  objectval_tyBM *k_json_false = BMK_1h1MMlmQi6f_2Z2g6rGMcPB;
  objectval_tyBM *k_json_null = BMK_6WOSg1mpNxQ_6Dw2klXZFSk;
  //objectval_tyBM *k_json_entry = BMK_78X6jYDHXpW_3opwNmDlnqc;
  objectval_tyBM *k_depth = BMK_17YdW6dWrBA_2mn4QmBjMNs;
  objectval_tyBM *k_apply = BMK_3Nl6LhfUZVb_1itsyWMBfYl;
  objectval_tyBM *k_closure = BMK_93zjUzZVAaj_9ppXv7C34GR;
  objectval_tyBM *k_id = BMK_7WjaQkqwdaZ_6PRtbDrJHnf;
  objectval_tyBM *k_name = BMK_1jJjA6LcXiX_1V4ZcXlje09;
#define HASHBM_json_object BMH_7hNqn2hxg1M_3wNHCtOf9IF
#define HASHBM_json_array BMH_56Om4CG9rer_8xF06AhNZ1I
#define HASHBM_json_string BMH_419If27jxwQ_3WQnLqU53iq
#define HASHBM_json_integer BMH_8jCh9loDpOL_4eR6Nzk21xp
#define HASHBM_json_real BMH_5ewBEYZh7EM_6dEinrBFpAE
#define HASHBM_json_true BMH_0ekuRPtKaIF_3nrHrhB59Kn
#define HASHBM_json_false BMH_1h1MMlmQi6f_2Z2g6rGMcPB
#define HASHBM_json_null BMH_6WOSg1mpNxQ_6Dw2klXZFSk
  LOCALFRAME_BM (stkf, /*descr: */ k_json,
                 value_tyBM valarg;     //
                 value_tyBM srcarg;     //
                 value_tyBM ctxarg;     //
                 value_tyBM resappv;    //
                 value_tyBM leftv;      //
                 objectval_tyBM * valob;        //
                 objectval_tyBM * leftob;       //
                 objectval_tyBM * compob;       //
                 objectval_tyBM * connob;       //
                 value_tyBM errorv;     //
                 value_tyBM failresv;   //
                 value_tyBM failplacev; //
    );
  _.valarg = val;
  _.srcarg = src;
  _.ctxarg = ctx;
  if (isobject_BM (_.valarg))
    {
      _.valob = objectcast_BM (_.valarg);
#define MAXHASH_JSOB 67
      switch (objecthash_BM (_.valob) % MAXHASH_JSOB)
        {
        case HASHBM_json_null % MAXHASH_JSOB:
          if (_.valob == k_json_null)
            return json_null ();
          break;
        case HASHBM_json_true % MAXHASH_JSOB:
          if (_.valob == k_json_true)
            return json_true ();
          break;
        case HASHBM_json_false % MAXHASH_JSOB:
          if (_.valob == k_json_false)
            return json_false ();
          break;
        default:
          break;
        }
      if (_.valob && objectisinstance_BM (_.valob, k_json_object)
          && objhasjansjsonpayl_BM (_.valob))
        {
          json_t *jscont = objgetjansjsonpayl_BM (_.valob);
          if (jscont)
            {
              json_incref (jscont);
              return jscont;
            }
          else
            return json_null ();
        }
      else if (_.valob)
        return json_string (objectdbg_BM (_.valob));
    }
  if (depth > MAXDEPTHJSON_BM)
    {
      _.errorv = (value_tyBM)
        makenode5_BM (k_json, k_depth, taggedint_BM (depth), _.valarg,
                      _.srcarg, _.ctxarg);
      PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
    }
  else if (isstring_BM (_.valarg))
    return json_string (bytstring_BM (_.valarg));
  else if (issequence_BM (_.valarg))
    {
      unsigned ln = sequencesize_BM (_.valarg);
      json_t *jarr = json_array ();
      for (int ix = 0; ix < (int) ln; ix++)
        {
          _.compob = sequencenthcomp_BM (_.valarg, ix);
          json_t *jcomp =
            jansjsonfromvalue_BM (_.compob, _.srcarg, _.ctxarg, depth + 1,
                                  CURFRAME_BM);
          if (jcomp)
            json_array_append (jarr, jcomp);
        }
      return jarr;
    }
  else if (isclosure_BM (_.valarg))
    {
      _.resappv =
        apply3_BM (_.valarg, _.srcarg, _.ctxarg, taggedint_BM (depth),
                   CURFRAME_BM);
      if (!_.resappv)
        {
          _.errorv = (value_tyBM)
            makenode5_BM (k_json, k_apply, taggedint_BM (depth), _.valarg,
                          _.srcarg, _.ctxarg);
          PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
        }
      else if (isclosure_BM (_.resappv))
        {
          _.errorv = (value_tyBM)
            makenode6_BM (k_json, k_closure, taggedint_BM (depth), _.resappv,
                          _.valarg, _.srcarg, _.ctxarg);
          PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
        }
    }
  else if (isnode_BM (_.valarg))
    {
      unsigned nodari = nodewidth_BM (_.valarg);
      _.connob = nodeconn_BM (_.valarg);
      /*** possible nodes
       * id(<object>) -> the string of that object
       * name(<object>) -> the name of that object, else fail
       * object(<object>) -> the name or id of that object
       * json_object([jsob], json_entry(<attr1>,<val1>), ....) -> the JSON object
       * json_array([jsarr], <comp1>,<comp2>,....) -> the JSON array
       *
       ***/
      if (nodari == 1
          && (_.connob == k_id || _.connob == k_name || _.connob == k_object))
        {
          _.leftv = nodenthson_BM (_.valarg, 0);
          if (isclosure_BM (_.leftv))
            {
              _.resappv =
                apply3_BM (_.leftv, _.srcarg, _.ctxarg, taggedint_BM (depth),
                           CURFRAME_BM);
              if (!_.resappv)
                {
                  _.errorv =
                    makenode5_BM (k_json, k_apply, taggedint_BM (depth),
                                  _.valarg, _.srcarg, _.ctxarg);
                  PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
                }
              else if (isclosure_BM (_.resappv))
                {
                  _.errorv = (value_tyBM)
                    makenode6_BM (k_json, k_closure, taggedint_BM (depth),
                                  _.resappv, _.valarg, _.srcarg, _.ctxarg);
                  PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
                }
              else
                _.leftv = _.resappv;
            };
          if (isobject_BM (_.leftv))
            {
              _.leftob = objectcast_BM (_.leftv);
              if (_.connob == k_id)
                {
                  char idbuf[32];
                  memset (idbuf, 0, sizeof (idbuf));
                  idtocbuf32_BM (objid_BM (_.leftob), idbuf);
                  return json_string (idbuf);
                }
              else if (_.connob == k_name)
                {
                  const char *obnam = findobjectname_BM (_.leftob);
                  if (obnam)
                    return json_string (obnam);
                  else
                    {
                      _.errorv = (value_tyBM)
                        makenode5_BM (k_json, k_name, taggedint_BM (depth),
                                      _.valarg, _.srcarg, _.ctxarg);
                      PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
                    }
                }
              else if (_.connob == k_object)
                {
                  return json_string (objectdbg_BM (_.leftob));
                }
              else              // cannot happen
                FATAL_BM
                  ("corruption jansjsonfromvalue_BM connob=%s valarg=%s",
                   objectdbg_BM (_.connob), OUTSTRVALUE_BM (_.valarg));
            }
          else
            {
              _.errorv =
                makenode5_BM (k_json, _.connob, taggedint_BM (depth),
                              _.valarg, _.srcarg, _.ctxarg);
              PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
            }
        }
      else if (_.connob == k_json_array)
        {
          int curix = 0;
          json_t *jsarr = NULL;
          if (nodari > 0 && (_.leftv = nodenthson_BM (_.valarg, 0)) != NULL
              && isobject_BM (_.leftv))
            {
              _.leftob = objectcast_BM (_.leftv);
              objlock_BM (_.leftob);
              jsarr = objgetjansjsonpayl_BM (_.leftob);
              objunlock_BM (_.leftob);
              if (!jsarr || !json_is_array (jsarr))
                {
                  if (jsarr)
                    json_decref (jsarr), jsarr = NULL;
                  _.errorv = (value_tyBM)
                    makenode5_BM (k_json, _.connob, taggedint_BM (depth),
                                  _.valarg, _.srcarg, _.ctxarg);
                  PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
                }
              else
                json_incref (jsarr);
            }
          else
            jsarr = json_array ();
          for (; curix < (int) nodari; curix++)
            {
              _.failresv = NULL;
              _.failplacev = NULL;
              _.leftv = nodenthson_BM (_.valarg, curix);
              int failcod = 0;
              struct failurelockset_stBM flockset = { };
              struct failurehandler_stBM *prevfailurehandle =
                (struct failurehandler_stBM *) curfailurehandle_BM;
              initialize_failurelockset_BM (&flockset, sizeof (flockset));
              LOCAL_FAILURE_HANDLE_BM (&flockset, lab_failurejsarr, failcod,
                                       _.failresv, _.failplacev);
              if (failcod > 0)
              lab_failurejsarr:
                {
                  json_decref (jsarr), jsarr = NULL;
                  curfailurehandle_BM = prevfailurehandle;
                  destroy_failurelockset_BM (&flockset);
                  PLACEDFAILURE_BM (failcod, _.failresv, _.failplacev,
                                    CURFRAME_BM);
                }
              else
                {
                  json_t *jscomp =
                    jansjsonfromvalue_BM (_.leftv, _.srcarg, _.ctxarg,
                                          depth + 1, CURFRAME_BM);
                  if (!jscomp)
                    {
                      _.errorv = (value_tyBM)
                        makenode5_BM (k_json, _.connob, taggedint_BM (depth),
                                      _.valarg, _.srcarg, _.ctxarg);
                      PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
                    }
                  else
                    json_array_append_new (jsarr, jscomp);
                }
            }
          return jsarr;
        }
      else if (_.connob == k_json_object)
        {
          int curix = 0;
          json_t *jsobj = NULL;
          if (nodari > 0 && (_.leftv = nodenthson_BM (_.valarg, 0)) != NULL
              && isobject_BM (_.leftv))
            {
              _.leftob = objectcast_BM (_.leftv);
              objlock_BM (_.leftob);
              jsobj = objgetjansjsonpayl_BM (_.leftob);
              objunlock_BM (_.leftob);
              if (!jsobj || !json_is_object (jsobj))
                {
                  if (jsobj)
                    json_decref (jsobj), jsobj = NULL;
                  _.errorv = (value_tyBM)
                    makenode5_BM (k_json, _.connob, taggedint_BM (depth),
                                  _.valarg, _.srcarg, _.ctxarg);
                  PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
                }
              else
                json_incref (jsobj);
            }
          else
            jsobj = json_object ();
          for (; curix < (int) nodari; curix++)
            {
              _.failresv = NULL;
              _.failplacev = NULL;
              _.leftv = nodenthson_BM (_.valarg, curix);
              int failcod = 0;
              struct failurelockset_stBM flockset = { };
              struct failurehandler_stBM *prevfailurehandle =
                (struct failurehandler_stBM *) curfailurehandle_BM;
              initialize_failurelockset_BM (&flockset, sizeof (flockset));
              LOCAL_FAILURE_HANDLE_BM (&flockset, lab_failurejsobj, failcod,
                                       _.failresv, _.failplacev);
              if (failcod > 0)
              lab_failurejsobj:
                {
                  json_decref (jsobj), jsobj = NULL;
                  curfailurehandle_BM = prevfailurehandle;
                  destroy_failurelockset_BM (&flockset);
                  PLACEDFAILURE_BM (failcod, _.failresv, _.failplacev,
                                    CURFRAME_BM);
                }
              else
                {
                  jansjson_add_to_json_object_bm (jsobj, _.leftv, _.srcarg,
                                                  _.ctxarg, depth + 1,
                                                  CURFRAME_BM);
                }
            }
          return jsobj;
        }
      else
        {
          _.errorv = (value_tyBM)
            makenode5_BM (k_json, _.connob, taggedint_BM (depth),
                          _.valarg, _.srcarg, _.ctxarg);
          PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
        }
    }
  _.errorv =
    makenode4_BM (k_json, taggedint_BM (depth), _.valarg, _.srcarg, _.ctxarg);
  PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
}                               /* end jansjsonfromvalue_BM */



void
jansjson_add_to_json_object_bm (json_t * objs, value_tyBM val, value_tyBM src,
                                value_tyBM ctx, int depth,
                                struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_json = BMK_2gNQ6wSYLGz_9FkMuCIKfmv;
  objectval_tyBM *k_json_entry = BMK_78X6jYDHXpW_3opwNmDlnqc;
  objectval_tyBM *k_json_attribute = BMK_2Xsji0gDHAg_6TTQQeKAnUY;
  objectval_tyBM *k_json_value = BMK_78X6jYDHXpW_3opwNmDlnqc;
  objectval_tyBM *k_depth = BMK_5LSPYWdN50R_3nt54XhyWMW;
  objectval_tyBM *k_connective = BMK_64FyzTwMoeT_9W2OIW95K2H;
  objectval_tyBM *k_apply = BMK_3Nl6LhfUZVb_1itsyWMBfYl;
  objectval_tyBM *k_closure = BMK_93zjUzZVAaj_9ppXv7C34GR;
  objectval_tyBM *k_json_object = BMK_7hNqn2hxg1M_3wNHCtOf9IF;
  LOCALFRAME_BM (stkf, /*descr: */ k_json,
                 value_tyBM valarg;     //
                 value_tyBM srcarg;     //
                 value_tyBM ctxarg;     //
                 value_tyBM resappv;    //
                 value_tyBM argleftv;   //
                 value_tyBM argrightv;  //
                 objectval_tyBM * valob;        //
                 objectval_tyBM * compob;       //
                 objectval_tyBM * connob;       //
                 value_tyBM errorv;     //
    );
  _.valarg = val;
  _.srcarg = src;
  _.ctxarg = ctx;
  WEAKASSERTRET_BM (objs && json_is_object (objs));
  if (depth > MAXDEPTHJSON_BM)
    {
      _.errorv = (value_tyBM)
        makenode5_BM (k_json, k_depth, taggedint_BM (depth), _.valarg,
                      _.srcarg, _.ctxarg);
      PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
    }
  if (isclosure_BM (_.valarg))
    {
      _.resappv =
        apply3_BM (_.valarg, _.srcarg, _.ctxarg, taggedint_BM (depth),
                   CURFRAME_BM);
      if (!_.resappv)
        {
          _.errorv = (value_tyBM)
            makenode5_BM (k_json, k_apply, taggedint_BM (depth), _.valarg,
                          _.srcarg, _.ctxarg);
          PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
        }
      else if (isclosure_BM (_.resappv))
        {
          _.errorv = (value_tyBM)
            makenode6_BM (k_json, k_closure, taggedint_BM (depth), _.resappv,
                          _.valarg, _.srcarg, _.ctxarg);
          PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
        }
      else
        _.valarg = _.resappv;
    };
  if (isnode_BM (_.valarg))
    {
      _.connob = nodeconn_BM (_.valarg);
      unsigned nodari = nodewidth_BM (_.valarg);
      if (nodari == 2 && _.connob == k_json_entry)
        {
          _.argleftv = nodenthson_BM (_.valarg, 0);
          _.argrightv = nodenthson_BM (_.valarg, 1);
          json_t *jsleft =      //
            jansjsonfromvalue_BM (_.argleftv, _.srcarg, _.ctxarg, depth + 1,
                                  CURFRAME_BM);
          if (!jsleft || !json_is_string (jsleft))
            {
              _.errorv =
                makenode5_BM (k_json, k_json_attribute, taggedint_BM (depth),
                              _.valarg, _.srcarg, _.ctxarg);
              PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
            }
          json_t *jsright =     //
            jansjsonfromvalue_BM (_.argrightv, _.srcarg, _.ctxarg, depth + 1,
                                  CURFRAME_BM);
          if (!jsright)
            {
              _.errorv = (value_tyBM)
                makenode5_BM (k_json, k_json_value, taggedint_BM (depth),
                              _.valarg, _.srcarg, _.ctxarg);
              PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
            }
          json_object_set_new (objs, json_string_value (jsleft), jsright);
          json_decref (jsleft), jsleft = NULL;
          jsright = NULL;
        }
      else if (nodari == 1 && _.connob == k_json_object)
        {
          _.argleftv = nodenthson_BM (_.valarg, 0);
          json_t *jsleft =      //
            jansjsonfromvalue_BM (_.argleftv, _.srcarg, _.ctxarg, depth + 1,
                                  CURFRAME_BM);
          if (!jsleft || !json_is_object (jsleft))
            {
              _.errorv = (value_tyBM)
                makenode5_BM (k_json, k_json_object, taggedint_BM (depth),
                              _.valarg, _.srcarg, _.ctxarg);
              PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
            }
          json_object_update (objs, jsleft);
          json_decref (jsleft), jsleft = NULL;
        }
      else
        {                       // unexpected connective or node
          _.errorv = (value_tyBM)
            makenode5_BM (k_json, k_connective, taggedint_BM (depth),
                          _.valarg, _.srcarg, _.ctxarg);
          PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
        }
    }                           /* end if valarg is a node */
  else
    {
      _.errorv = (value_tyBM)
        makenode4_BM (k_json_object, taggedint_BM (depth),
                      _.valarg, _.srcarg, _.ctxarg);
      PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
    }
}                               // end jansjson_add_to_json_object_bm

value_tyBM
value_of_json_BM (json_t * json, value_tyBM src,
                  value_tyBM ctx, int depth, struct stackframe_stBM *stkf)
{
  FATAL_BM ("unimplemented value_of_json_BM");
#warning unimplemented value_of_json_BM
}                               /* end of value_of_json_BM */


#define MAXJSONIFYDEPTH_BM 96
json_t *
canonjsonifyvalue_BM (value_tyBM valarg,
                      objectval_tyBM * ctxarg,
                      int depth, struct stackframe_stBM *stkf)
{
  json_t *jres = NULL;
  objectval_tyBM *k_json_value = BMK_78X6jYDHXpW_3opwNmDlnqc;
  LOCALFRAME_BM (stkf, /*descr: */ k_json_value,
                 value_tyBM valv;       //
                 objectval_tyBM * octxt;        //
                 objectval_tyBM * oconn;        //
                 union
                 {
                 value_tyBM * vcomp;    //
                 objectval_tyBM * ocomp;        //
                 };);
  _.valv = valarg;
  _.octxt = objectcast_BM (ctxarg);
  DBGPRINTF_BM ("canonjsonifyvalue start val=%s ctx=%s depth#%d",
                OUTSTRVALUE_BM (_.valv), objectdbg_BM (_.octxt), depth);
  int vty = valtype_BM (_.valv);
  if (depth < MAXDEPTHJSON_BM)
    switch (vty)
      {
      case tyInt_BM:
        jres = json_integer (getint_BM (_.valv));
        break;
      case tyNone_BM:
        break;
      case tyString_BM:
        jres = json_string (bytstring_BM (_.valv));
        break;
      case tyUnspecified_BM:
        jres = json_false ();
        break;
      case tySet_BM:
      case tyTuple_BM:
        {
          json_t *jarr = json_array ();
          bool isset = (vty == tySet_BM);
          unsigned ln = sequencesize_BM (_.valv);
          for (int ix = 0; ix < (int) ln; ix++)
            {
              _.ocomp = sequencenthcomp_BM (_.valv, ix);
              char idbuf[32];
              memset (idbuf, 0, sizeof (idbuf));
              idtocbuf32_BM (objid_BM (_.ocomp), idbuf);
              json_array_append_new (jarr, json_string (idbuf));
            }
          jres = json_pack ("{so}", isset ? "!set" : "!tup", jarr);
          break;
        }
        break;
      case tyNode_BM:
        {
          json_t *jconn = NULL;
          json_t *jarr = NULL;
          json_t *jcomp = NULL;
          _.oconn = nodeconn_BM (_.valv);
          unsigned ln = nodewidth_BM (_.valv);
          {
            char connbuf[32];
            memset (connbuf, 0, sizeof (connbuf));
            idtocbuf32_BM (objid_BM (_.oconn), connbuf);
            jconn = json_string (connbuf);
          }
          jarr = json_array ();
          for (int ix = 0; ix < (int) ln; ix++)
            {
              jcomp = NULL;
              _.vcomp = nodenthson_BM (_.valv, ix);
              jcomp =
                canonjsonifyvalue_BM (_.vcomp, _.octxt, depth + 1,
                                      CURFRAME_BM);
              if (!jcomp)
                {
                  json_decref (jarr);
                  json_decref (jconn);
                  return NULL;
                }
              json_array_append_new (jarr, jcomp);
            }
          jres = json_pack ("{soso}", "!node", jconn, "!sons", jarr);
        }
        break;
      case tyClosure_BM:
        {
          json_t *jconn = NULL;
          json_t *jarr = NULL;
          json_t *jcomp = NULL;
          _.oconn = closureconn_BM (_.valv);
          unsigned ln = closurewidth_BM (_.valv);
          {
            char connbuf[32];
            memset (connbuf, 0, sizeof (connbuf));
            idtocbuf32_BM (objid_BM (_.oconn), connbuf);
            jconn = json_string (connbuf);
          }
          jarr = json_array ();
          for (int ix = 0; ix < (int) ln; ix++)
            {
              jcomp = NULL;
              _.vcomp = closurenthson_BM (_.valv, ix);
              jcomp =
                canonjsonifyvalue_BM (_.vcomp, _.octxt, depth + 1,
                                      CURFRAME_BM);
              if (!jcomp)
                {
                  json_decref (jarr);
                  json_decref (jconn);
                  return NULL;
                }
              json_array_append_new (jarr, jcomp);
            }
          jres = json_pack ("{soso}", "!clos", jconn, "!cval", jarr);
        }
        break;
      case tyObject_BM:
        {
          char idbuf[32];
          memset (idbuf, 0, sizeof (idbuf));
          idtocbuf32_BM (objid_BM (objectcast_BM (_.valv)), idbuf);
          jres = json_pack ("{ss}", "!oid", idbuf);
        }
        break;
      default:
        jres = NULL;
      }
  return jres;
}                               /* end of canonjsonifyvalue_BM */


//// nodal decoding

enum nodaljsonvariantBM_en
{
  njv_none = 0,
};

//// the stack allocated structure holding some nodal decoding mode etc...
#define NODALJSON_MAGIC_BM 0x1e4a9b51   /*508205905 */
struct nodaljsonmode_st
{
  unsigned njs_magic;           // always NODALJSON_MAGIC_BM
  enum nodaljsonvariantBM_en njs_variant;
  void *njs_spare[6];
};


/****
  JSON related objects ~: "*json*"
 dumpable_json_object |=_6Iemb8Xs6aS_9quFFex4qwG|
 json |=_2gNQ6wSYLGz_9FkMuCIKfmv|
 json_array |=_56Om4CG9rer_8xF06AhNZ1I|
 json_attribute |=_2Xsji0gDHAg_6TTQQeKAnUY|
 json_compact |=_4wmsNr582JT_9YyamGEMhJk|
 json_entry |=_78X6jYDHXpW_3opwNmDlnqc|
 json_false |=_1h1MMlmQi6f_2Z2g6rGMcPB|
 json_indented |=_5J3InN9BK1k_3C8vurQQEGh|
 json_integer |=_8jCh9loDpOL_4eR6Nzk21xp|
 json_null |=_6WOSg1mpNxQ_6Dw2klXZFSk|
 json_object |=_7hNqn2hxg1M_3wNHCtOf9IF|
 json_real |=_5ewBEYZh7EM_6dEinrBFpAE|
 json_sequence |=_6QlgyfRKCyD_1g6EhKC55Vj|
 json_set |=_28Y5XSkBZZH_24NmhTCKRgd|
 json_string |=_419If27jxwQ_3WQnLqU53iq|
 json_true |=_0ekuRPtKaIF_3nrHrhB59Kn|
 json_tuple |=_7d0o00yB7Zs_1USaaS25hxl|
 json_value |=_5LSPYWdN50R_3nt54XhyWMW|
 jsonable_closure |=_7W0zh0WgGCU_5AfEDjZ7XVZ|
 jsonable_object |=_3j87xFrfAfb_84QdVpi4LDD|
 nodal_json_decode |=_9oFdE54tXks_0St3kmk7akH|
 objwebexchangejsonpayl |=_3v18bLdjMRP_4CrjvtrZteq|
 objwebsessionsendjsonwebsocketpayl |=_8k0A61NiezX_83vjEr6JmGf|
 value_to_json |=_0DYWTkQbFjG_1Ed0ex9v5xA|
***/

static value_tyBM
nodaljsonstring_BM (struct nodaljsonmode_st *njm, const char *str,
                    struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_json_null = BMK_6WOSg1mpNxQ_6Dw2klXZFSk;
  objectval_tyBM *k_json_true = BMK_0ekuRPtKaIF_3nrHrhB59Kn;
  objectval_tyBM *k_json_false = BMK_1h1MMlmQi6f_2Z2g6rGMcPB;
  objectval_tyBM *k_json_array = BMK_56Om4CG9rer_8xF06AhNZ1I;
  objectval_tyBM *k_json_object = BMK_7hNqn2hxg1M_3wNHCtOf9IF;
  objectval_tyBM *k_json_string = BMK_419If27jxwQ_3WQnLqU53iq;
  LOCALFRAME_BM (stkf, /*descr: */ k_json_string,
                 value_tyBM resv; value_tyBM setv; objectval_tyBM * ob;);
  ASSERT_BM (njm && njm->njs_magic == NODALJSON_MAGIC_BM);
  if (!str)
    return NULL;
  _.resv = NULL;
  rawid_tyBM id = { 0, 0 };
  char *end = NULL;
  int len_euro_underscore = strlen ("€_");
  if (str[0] == '_' && isdigit (str[1])
      && (id = parse_rawid_BM (str, &end)).id_hi != 0
      && end != NULL && *end == (char) 0
      && (_.ob = findobjofid_BM (id)) != NULL && !findobjectname_BM (_.ob))
    {
      return _.ob;
    }
  else if (isalpha (str[0]) && validname_BM (str) && (_.ob = findnamedobj_BM (str)) != NULL     //
           && _.ob != k_json_null       //
           && _.ob != k_json_true       //
           && _.ob != k_json_false      //
           && _.ob != k_json_array      //
           && _.ob != k_json_object     //
           && _.ob != k_json_string)
    {
      return _.ob;
    }
  else if (!strncmp (str, "€_", len_euro_underscore)
           && isdigit (str[len_euro_underscore + 1])
           && !isalnum (str[len_euro_underscore + 2])
           && !isalnum (str[len_euro_underscore + 3])
           && !isalnum (str[len_euro_underscore + 4]))
    {
      _.setv = setobjectsofidprefixed_BM (str + len_euro_underscore - 1);
      if (isset_BM (_.setv) && setcardinal_BM (_.setv) == 1)
        _.resv = setelemnth_BM (_.setv, 0);
    }
  if (!_.resv)
    _.resv = makestring_BM (str);
  return _.resv;
}                               /* end nodaljsonstring_BM */


static value_tyBM
nodaljsondecode_BM (struct nodaljsonmode_st *njm, json_t * js, int depth,
                    struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_nodal_json_decode = BMK_9oFdE54tXks_0St3kmk7akH;
  objectval_tyBM *k_json_null = BMK_6WOSg1mpNxQ_6Dw2klXZFSk;
  objectval_tyBM *k_json_true = BMK_0ekuRPtKaIF_3nrHrhB59Kn;
  objectval_tyBM *k_json_false = BMK_1h1MMlmQi6f_2Z2g6rGMcPB;
  objectval_tyBM *k_json_array = BMK_56Om4CG9rer_8xF06AhNZ1I;
  objectval_tyBM *k_json_object = BMK_7hNqn2hxg1M_3wNHCtOf9IF;
  objectval_tyBM *k_json_entry = BMK_78X6jYDHXpW_3opwNmDlnqc;
  ASSERT_BM (njm && njm->njs_magic == NODALJSON_MAGIC_BM);
  LOCALFRAME_BM (stkf, /*descr: */ k_nodal_json_decode,
                 value_tyBM resv;
                 value_tyBM tinarrv[TINYSIZE_BM]; objectval_tyBM * ob1;
                 value_tyBM vkey; value_tyBM vcomp; value_tyBM vnode;);
  if (!js)
    return NULL;
  if (depth > MAXDEPTHJSON_BM)
    return NULL;
  _.resv = NULL;
  if (json_is_null (js))
    {
      _.resv = k_json_null;
    }
  else if (json_is_true (js))
    {
      _.resv = k_json_true;
    }
  else if (json_is_false (js))
    {
      _.resv = k_json_false;
    }
  else if (json_is_integer (js))
    {
      _.resv = taggedint_BM (json_integer_value (js));
    }
  else if (json_is_real (js))
    {
      double d = json_real_value (js);
      _.resv = makedouble_BM (d);
    }
  else if (json_is_string (js))
    {
      _.resv = nodaljsonstring_BM (njm, json_string_value (js), CURFRAME_BM);
    }
  /// for JSON arrays
  else if (json_is_array (js))
    {
      unsigned lnj = json_array_size (js);
      if (lnj < TINYSIZE_BM)
        {
          memset (_.tinarrv, 0, sizeof (_.tinarrv));
          for (int ix = 0; ix < (int) lnj; ix++)
            {
              _.tinarrv[ix] =
                nodaljsondecode_BM (njm, json_array_get (js, ix), depth + 1,
                                    CURFRAME_BM);
            }
          _.resv = makenode_BM (k_json_array, lnj, _.tinarrv);
        }
      else
        {
          _.ob1 = makeobj_BM ();
          objreservecomps_BM (_.ob1, lnj);
          for (int ix = 0; ix < (int) lnj; ix++)
            {
              _.vcomp =
                nodaljsondecode_BM (njm, json_array_get (js, ix), depth + 1,
                                    CURFRAME_BM);
              objappendcomp_BM (_.ob1, _.vcomp);
            }
          _.resv = makenode_BM (k_json_array, lnj, objcompdata_BM (_.ob1));
        }
    }                           /* endif json_is_array */
  /// for JSON objects
  else if (json_is_object (js))
    {
      unsigned lnj = json_object_size (js);
      json_t *jkey = NULL;
      json_t *jval = NULL;
      if (lnj < TINYSIZE_BM)
        {
          int ix = 0;
          memset (_.tinarrv, 0, sizeof (_.tinarrv));
          json_object_foreach (js, jkey, jval)
          {
            ASSERT_BM (json_is_string (jkey));
            _.vkey = NULL;
            _.vcomp = NULL;
            _.vkey = nodaljsonstring_BM (njm, json_string_value (jkey),
                                         CURFRAME_BM);
            _.vcomp = nodaljsondecode_BM (njm, jval, depth + 1, CURFRAME_BM);
            _.vnode = makenode2_BM (k_json_entry, _.vkey, _.vcomp);
            _.tinarrv[ix++] = _.vnode;
          };
          valarrqsort_BM (_.tinarrv, ix);
          _.resv = makenode_BM (k_json_object, lnj, _.tinarrv);
        }
      else                      // lnj >= TINYSIZE_BM
        {
          _.ob1 = makeobj_BM ();
          objreservecomps_BM (_.ob1, lnj);
          int cnt = 0;
          json_object_foreach (js, jkey, jval)
          {
            ASSERT_BM (json_is_string (jkey));
            _.vkey = NULL;
            _.vcomp = NULL;
            _.vkey = nodaljsonstring_BM (njm, json_string_value (jkey),
                                         CURFRAME_BM);
            _.vcomp = nodaljsondecode_BM (njm, jval, depth + 1, CURFRAME_BM);
            _.vnode = makenode2_BM (k_json_entry, _.vkey, _.vcomp);
            objappendcomp_BM (_.ob1, _.vnode);
            cnt++;
          };
          valarrqsort_BM (objcompdata_BM (_.ob1), cnt);
          _.resv = makenode_BM (k_json_object, lnj, objcompdata_BM (_.ob1));
        };
    }                           /* endif json_is_object */
  return _.resv;
}                               /* end of nodaljsondecode_BM */

///// end of file jsonjansson_BM.c
