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
GSequence *json_gseq;           /* a sequence of json_t pointers */

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
      if (json_ghtbl == NULL || json_gseq == NULL)
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
                (unsigned) g_sequence_get_length (json_gseq));
        int nbjs = (int) g_sequence_get_length (json_gseq);
        gpointer jgptr = g_hash_table_lookup (json_ghtbl, js);
        if (jgptr)
          {
            jix = (int) (intptr_t) jgptr;
            assert (jix > 0);
          }
        else
          {
            jix = nbjs + 1;
            g_sequence_append (json_gseq, js);
            g_hash_table_insert (json_ghtbl, js, (gpointer) jix);
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
        gpointer ptr = NULL;
        GSequenceIter *sqit = NULL;
        if (!json_ghtbl)
          error ("no JSON hashtable");
        if (!json_gseq)
          error ("no JSON sequence");
        int nbjs = (int) g_sequence_get_length (json_gseq);
        if (jsix > 0 && jsix <= nbjs)
          sqit = g_sequence_get_iter_at_pos (json_gseq, (gint) (jsix - 1));
        if (sqit)
          ptr = g_sequence_get (sqit);
        return (json_t *) ptr;
      }
    }
}                               /* end json_in_obj */

/// this routine is called at start of the garbage collector to clear the GC marks for JSON references
void
clear_json_marks (void *root)
{
  assert (root != NULL);
#warning unimplemented clear_json_marks
}                               /* end clear_gtk_json_marks */


void
clean_gc_json (void *root)
{
  assert (root != NULL);
#warning unimplemented clean_gc_json
}                               /* end clean_gc_json */

void
mark_json_ref (void *root, Obj *jsob)
{
  int jsix = -1;
  assert (root != NULL);
  assert (jsob != NULL && jsob->type == TJSONREF);
  if (jsob == Jsonv_True || jsob == Jsonv_False || jsob == Jsonv_Null)
    return;
  jsix = jsob->json_index;
  error ("mark_json_ref unimplemented for JSON ref#%d", jsix);
#warning unimplemented mark_json_ref
}                               /* end mark_json_ref */


void
define_json_primitives (void *root, Obj **env)
{
  add_primitive (root, env, "json_eq", prim_json_eq);
}                               /* end define_json_primitives */

/// this routine is called by the garbage collector to clean useless GTK or JSON references
void
clean_gc_json_gtk (void *root)
{
  assert (root != NULL);
#warning clean_gc_json_gtk unimplemented
}                               /* end clean_gc_json_gtk */

void
file_json_print (FILE * fil, Obj *obj, unsigned depth)
{
  assert (fil != NULL);
  assert (obj != NULL && obj->type == TJSONREF);
  fprintf (fil, "<json#%d", obj->json_index);
#warning file_json_print unimplemented
  fprintf (fil, ">");
}                               /* end file_json_print */


//// For JSON notation; example #json { "a" : 1, "b" : [true,false,null]}
//// the #json has been read
Obj *
fread_json (FILE * fil, void *root)
{
  assert (fil != NULL);
  assert (root != NULL);
  if (!json_ghtbl)
    error ("fread_json without JSON initialization");
#warning fread_json unimplemented
  error ("fread_json unimplemented");
}                               /* end fread_json */


void
finalize_json (void)
{
  static bool finalized;
  if (finalized)
    return;
  if (!json_ghtbl || !json_gseq)
    return;
  g_hash_table_destroy (json_ghtbl);
  g_sequence_free (json_gseq);
  json_ghtbl = NULL;
  json_gseq = NULL;
  finalized = true;
}                               /* end finalize_json */

void
json_seq_remove (gpointer ptr)
{
  json_t *js = (json_t *) ptr;
  if (js == NULL)
    return;
}                               /* end json_seq_remove */

void
initialize_json (void)
{
  if (json_ghtbl)
    return;
  json_ghtbl = g_hash_table_new (g_direct_hash, g_direct_equal);
  json_gseq = g_sequence_new ((GDestroyNotify *) json_seq_remove);
  atexit (finalize_json);
}                               /* end initialize_json */


/************
 ** for Emacs:
 ** Local Variables: ;;
 ** compile-command: "./build.sh" ;;
 ** End: ;;
 ************/

///// end of file bismon/gtkgui/jsonbismonlisp.c
