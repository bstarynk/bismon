// file jsonbismonlisp.c
// SPDX-License-Identifier: LGPL-3.0-or-later
/**
    BISMON 
    Copyright © 2022 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License v3.0 along with this program.  If not, see
    <http://www.gnu.org/licenses/>.

----
    Contact me (Basile Starynkevitch) by email
    basile@starynkevitch.net and/or basile.starynkevitch@cea.fr
**/
#include "minilispbismon.h"

#include <jansson.h>


Obj *Jsonv_True = &(Obj)
{.type = TJSONREF,.size = 0,    //
  .json_index = JSONMAG_true
};

Obj *Jsonv_False = &(Obj)
{.type = TJSONREF,.size = 0,    //
  .json_index = JSONMAG_false
};

Obj *Jsonv_Null = &(Obj)
{.type = TJSONREF,.size = 0,    //
  .json_index = JSONMAG_null
};


GHashTable *json_ghtbl;         /* an hashtable associating json_t pointers to intptr_t ranks */


struct
{
  json_t **jsv_arr;             /* array of pointers */
  bool *jsv_markarr;            /* array of GC marks */
  bool *jsv_decrefarr;          /* array of flags to json_decref */
  unsigned jsv_size;            /* allocated size */
  unsigned jsv_count;           /* used count */
} json_vect;

void
finalize_json (void)
{
  static bool finalized;
  if (finalized)
    return;
  if (!json_ghtbl)
    return;
  g_hash_table_destroy (json_ghtbl);
  json_ghtbl = NULL;
  if (json_vect.jsv_size > 0)
    {
      assert (json_vect.jsv_markarr != NULL);
      assert (json_vect.jsv_decrefarr != NULL);
      for (int ix = 0; ix < (int) json_vect.jsv_size; ix++)
        {
          json_t *curjs = json_vect.jsv_arr[ix];
          if (!curjs)
            continue;
          if (json_vect.jsv_decrefarr[ix])
            {
              json_vect.jsv_decrefarr[ix] = false;
              json_decref (curjs);
            }
        }
    }
  free (json_vect.jsv_arr), json_vect.jsv_arr = NULL;
  free (json_vect.jsv_markarr), json_vect.jsv_markarr = NULL;
  free (json_vect.jsv_decrefarr), json_vect.jsv_decrefarr = NULL;
  finalized = true;
}                               /* end finalize_json */

void
initialize_json (void)
{
  if (json_ghtbl)
    return;
  json_ghtbl = g_hash_table_new (g_direct_hash, g_direct_equal);
  unsigned inisiz = 128;
  json_vect.jsv_arr = calloc (inisiz, sizeof (json_t *));
  if (!json_vect.jsv_arr)
    {
      fprintf (stderr, "calloc failed for %u json_t* pointers (%s)", inisiz,
               strerror (errno));
      exit (EXIT_FAILURE);
    };
  json_vect.jsv_markarr = calloc (inisiz, sizeof (bool));
  if (!json_vect.jsv_markarr)
    {
      fprintf (stderr, "calloc failed for %u mark flags (%s)", inisiz,
               strerror (errno));
      free (json_vect.jsv_arr), json_vect.jsv_arr = NULL;
      exit (EXIT_FAILURE);
    };
  json_vect.jsv_decrefarr = calloc (inisiz, sizeof (bool));
  if (!json_vect.jsv_decrefarr)
    {
      fprintf (stderr, "calloc failed for %u jansson decref flags (%s)",
               inisiz, strerror (errno));
      free (json_vect.jsv_arr), json_vect.jsv_arr = NULL;
      free (json_vect.jsv_markarr), json_vect.jsv_markarr = NULL;
      exit (EXIT_FAILURE);
    };
  json_vect.jsv_count = 0;
  json_vect.jsv_size = inisiz;
  atexit (finalize_json);
}                               /* end initialize_json */


Obj *
make_json (void *root, json_t *js, bool doincref)
{
  Obj *res = NULL;
  assert (root != NULL);
  if (!js)
    error ("make_json with null JSON pointer");
  switch (js->type)
    {
    case JSON_TRUE:
      return Jsonv_True;
    case JSON_FALSE:
      return Jsonv_False;
    case JSON_NULL:
      return Jsonv_Null;
#warning make_json unimplemented for composite JSON; use g_hash_table_insert on json_ghtbl
    case JSON_OBJECT:
    case JSON_ARRAY:
    case JSON_STRING:
    case JSON_INTEGER:
    case JSON_REAL:
      if (json_ghtbl == NULL || json_vect.jsv_size == 0)
        {
          error ("make_json without JSON initialization");
          return NULL;
        };
      {
        /* use g_hash_table_insert, but think about json_t* refcount... */
        int jix = -99;
        if (doincref)
          json_incref (js);
        assert ((unsigned) g_hash_table_size (json_ghtbl) ==
                json_vect.jsv_count);
        int nbjs = (int) json_vect.jsv_count;
        gpointer jgptr = g_hash_table_lookup (json_ghtbl, js);
        if (jgptr)
          {
            jix = (int) (intptr_t) jgptr;
            assert (jix > 0 && json_vect.jsv_arr[jix] == js);
            json_vect.jsv_markarr[jix] = true;
          }
        else
          {
            if (json_vect.jsv_count + 2 >= json_vect.jsv_size)
              {
                unsigned newsiz =
                  ((4 * json_vect.jsv_count / 3 + 10) | 7) + 1;
                assert (newsiz > json_vect.jsv_size);
                json_t **newjsarr = calloc (newsiz, sizeof (json_t *));
                if (!newjsarr)
                  {
                    fprintf (stderr, "failed to grow json array to %u (%s)",
                             newsiz, strerror (errno));
                    exit (EXIT_FAILURE);
                  };
                memcpy (newjsarr, json_vect.jsv_arr,
                        sizeof (json_t *) * json_vect.jsv_count);
                bool *newmarkarr = calloc (newsiz, sizeof (bool));
                if (!newjsarr)
                  {
                    free (newjsarr);
                    fprintf (stderr,
                             "failed to grow jsonmark array to %u (%s)",
                             newsiz, strerror (errno));
                    exit (EXIT_FAILURE);
                  };
                memcpy (newmarkarr, json_vect.jsv_markarr,
                        sizeof (bool) * json_vect.jsv_count);
                bool *newdecrefarr = calloc (newsiz, sizeof (bool));
                if (!newjsarr)
                  {
                    free (newjsarr);
                    free (newmarkarr);
                    fprintf (stderr,
                             "failed to grow jsondecref array to %u (%s)",
                             newsiz, strerror (errno));
                    exit (EXIT_FAILURE);
                  };
                memcpy (newdecrefarr, json_vect.jsv_decrefarr,
                        sizeof (bool) * json_vect.jsv_count);
                free (json_vect.jsv_arr), json_vect.jsv_arr = newjsarr;
                free (json_vect.jsv_markarr),   //
                  json_vect.jsv_markarr = newmarkarr;
                free (json_vect.jsv_decrefarr), //
                  json_vect.jsv_decrefarr = newdecrefarr;
                json_vect.jsv_size = newsiz;
              }
            jix = nbjs + 1;
            g_hash_table_insert (json_ghtbl, js, (gpointer) (intptr_t) jix);
            json_vect.jsv_arr[jix] = js;
            json_vect.jsv_decrefarr[jix] = doincref;
            json_vect.jsv_markarr[jix] = true;
            json_vect.jsv_count++;
          }
        res = alloc (root, TJSONREF, sizeof (res->json_index));
        res->json_index = jix;
        return res;
      }
    default:
      error ("make_json with invalid Jansson type %d", (int) js->type);
    };
}                               /* end make_json */



json_t *
json_in_obj (Obj *obj)
{
  assert (obj != NULL);
  if (obj->type != TJSONREF)
    return NULL;
  int jsix = obj->json_index;
  switch (jsix)
    {
    case JSONMAG_true:
      return json_true ();
    case JSONMAG_false:
      return json_false ();
    case JSONMAG_null:
      return json_null ();
    default:
      {
        if (jsix > 0 && jsix < (int) json_vect.jsv_count)
          return json_vect.jsv_arr[jsix];
      }
    }
  return NULL;
}                               /* end json_in_obj */

/// this routine is called at start of the garbage collector to clear the GC marks for JSON references
void
clear_json_marks (void *root)
{
  assert (root != NULL);
  for (unsigned jix = 0; jix < json_vect.jsv_count; jix++)
    json_vect.jsv_markarr[jix] = false;
}                               /* end clear_gtk_json_marks */

// this routine is called by the garbage collector to clean all the
// json_t* which have not been marked by mark_json_ref
void
clean_gc_json (void *root)
{
  assert (root != NULL);
  int lastix = -1;
  assert (json_vect.jsv_count < json_vect.jsv_size);
  for (unsigned jix = 1; jix <= json_vect.jsv_count; jix++)
    {
      if (!json_vect.jsv_arr[jix])
        continue;
      if (json_vect.jsv_markarr[jix] == false)
        {
        }
    }
#warning unimplemented clean_gc_json
}                               /* end clean_gc_json */

json_t *
get_json (Obj *jsob)
{
  if (!jsob)
    return NULL;
  if (jsob->type != TJSONREF)
    return NULL;
  if (jsob == Jsonv_True)
    return json_true ();
  if (jsob == Jsonv_False)
    return json_false ();
  if (jsob == Jsonv_Null)
    return json_null ();
  int jsix = jsob->json_index;
  if (jsix > 0 && jsix <= json_vect.jsv_count)
    {
      assert (json_vect.jsv_arr);
      return json_vect.jsv_arr[jsix];
    }
  return NULL;
}                               /* end get_json */

void
mark_json_ref (void *root, Obj *jsob)
{
  int jsix = -1;
  assert (root != NULL);
  assert (jsob != NULL && jsob->type == TJSONREF);
  if (jsob == Jsonv_True || jsob == Jsonv_False || jsob == Jsonv_Null)
    return;
  jsix = jsob->json_index;
  if (jsix > 0 && jsix <= json_vect.jsv_count)
    json_vect.jsv_markarr[jsix] = true;
#warning unimplemented mark_json_ref
}                               /* end mark_json_ref */

Obj *
prim_json_eq (void *root, Obj **env, Obj **list)
{
  if (length (*list) != 2)
    error ("Malformed json_eq (%d args)", length (*list));
  Obj *values = eval_list (root, env, list);
  Obj *x = values->car;
  Obj *y = values->cdr->car;
  if (x->type == TJSONREF && y->type == TJSONREF)
    {
      int xix = x->json_index;
      int yix = y->json_index;
      if (xix == yix)
        return True;
      if (xix < 0 || yix < 0)
        return Nil;             /* some json_magic_en */
      assert (xix > 0 && xix <= (int) json_vect.jsv_count);
      assert (yix > 0 && yix <= (int) json_vect.jsv_count);
      if (json_vect.jsv_arr[xix] == json_vect.jsv_arr[yix])
        return True;
    }
  return Nil;
}                               /* end prim_json_eq */

Obj *
prim_json_type (void *root, Obj **env, Obj **list)
{
  if (length (*list) != 1)
    error ("Malformed json_type (%d args)", length (*list));
  Obj *values = eval_list (root, env, list);
  Obj *jv = values->car;
  json_t *js = get_json (jv);
  if (!js)
    return Nil;
  switch (json_typeof (js))
    {
    case JSON_OBJECT:
      return intern (root, "json_object");
    case JSON_ARRAY:
      return intern (root, "json_array");
    case JSON_STRING:
      return intern (root, "json_string");
    case JSON_TRUE:
      return intern (root, "json_true");
    case JSON_FALSE:
      return intern (root, "json_false");
    case JSON_INTEGER:
      return intern (root, "json_integer");
    case JSON_REAL:
      return intern (root, "json_real");
    case JSON_NULL:
      return intern (root, "json_null");
    default:
      error ("corrupted json type#%d", json_typeof (js));
      return Nil;
    }
}                               /* end prim_json_type */

void
define_json_primitives (void *root, Obj **env)
{
  add_primitive (root, env, "json_eq", prim_json_eq);
  add_primitive (root, env, "json_type", prim_json_type);
}                               /* end define_json_primitives */

/// this routine is called by the garbage collector to clean useless
/// JSON references
void
clean_gc_json (void *root)
{
  assert (root != NULL);
  int nbjsv = (int) json_vect.jsv_count;
  if (nbjsv == 0)
    return;
  assert (nbjsv < json_vect.jsv_size);
  assert (json_vect.jsv_arr != NULL);
  assert (json_vect.jsv_markarr != NULL);
  assert (json_vect.jsv_decrefarr != NULL);
  for (int jix = 1; jix <= nbjsv; jix++)
    {
      json_t *curjs = json_vect.jsv_arr[jix];
      if (!curjs)
        continue;
      if (json_vect.jsv_markarr[jix])
        continue;
      if (json_vect.jsv_decrefarr[jix])
        json_decref (curjs);
      json_vect.jsv_arr[jix] = NULL;
    }
  while (json_vect.jsv_count > 0
         && json_vect.jsv_arr[json_vect.jsv_count] == NULL)
    {
      json_vect.jsv_markarr[json_bect.jsv_count] = false;
      json_vect.jsv_decrefarr[json_bect.jsv_count] = false;
      json_vect.jsv_count--;
    }
}                               /* end clean_gc_json_gtk */

void
file_json_print (FILE * fil, Obj *obj, unsigned depth)
{
  assert (fil != NULL);
  assert (obj != NULL && obj->type == TJSONREF);
  int jix = obj->json_index;
  switch (jix)
    {
    case JSONMAG_true:
      fputs ("<json-true>", fil);
      break;
    case JSONMAG_false:
      fputs ("<json-false>", fil);
      break;
    case JSONMAG_null:
      fputs ("<json-null>", fil);
      break;
    default:
      {
        json_t *js = NULL;
        if (jix > 0 && jix <= (int) json_vect.jsv_count)
          {
            assert (json_vect.jsv_count < json_vect.jsv_size);
            assert (json_vect.jsv_arr != NULL);
            assert (json_vect.jsv_markarr != NULL);
            js = json_vect.jsv_arr[jix];
            if (js)
              json_vect.jsv_markarr[jix] = true;
          }
        if (!js)
          fprintf (fil, "<json#%d?nojs?>", jix);
        else
          {
            fprintf (fil, "<json#%d:", jix);
            fflush (fil);
            int failedj = json_dumpf (js, fil,
                                      JSON_INDENT (depth)
                                      | JSON_SORT_KEYS |
                                      JSON_REAL_PRECISION (8) | JSON_COMPACT |
                                      JSON_ENCODE_ANY);
            fputs (">", fil);
            if (failedj)
              error ("json_dumpf failed for json#%d", jix);
          }
      }
      break;
    }
  fflush (fil);
}                               /* end file_json_print */


//// For JSON notation; example #json { "a" : 1, "b" : [true,false,null]}
//// the #json has been read
Obj *
fread_json (FILE * fil, void *root)
{
  json_t *js = NULL;
  assert (fil != NULL);
  assert (root != NULL);
  if (!json_ghtbl || json_vect.jsv_arr == NULL)
    error ("fread_json without JSON initialization");
  json_error_t jerr = { };
  js = json_loadf (fil, JSON_DECODE_ANY
                   | JSON_DISABLE_EOF_CHECK | JSON_REJECT_DUPLICATES, &jerr);
  if (!js)
    {
      char errmsg[80];
      memset (errmsg, 0, sizeof (errmsg));
      strncpy (errmsg, jerr.text, sizeof (errmsg) - 1);
      if (strlen (errmsg) > 0)
        errmsg[strlen (errmsg) - 1] = (char) 0; // remove json_error_code
      error ("fread_json failed %s", errmsg);
      return NULL;
    };
  return make_json (root, js, KEEP_REFCNT_JANSSON);
}                               /* end fread_json */



/************
 ** for Emacs:
 ** Local Variables: ;;
 ** compile-command: "./build.sh" ;;
 ** End: ;;
 ************/

///// end of file bismon/gtkgui/jsonbismonlisp.c
