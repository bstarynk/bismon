// file gtkbismonlisp.c
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
#include <gtk/gtk.h>

Obj *
make_json (void *root, json_t * js)
{
  Obj *res = NULL;
  if (!js)
    error ("make_json with null JSON pointer");
  switch (js->type)
    {
    case JSON_OBJECT:
    case JSON_ARRAY:
    case JSON_STRING:
    case JSON_INTEGER:
    case JSON_REAL:
    case JSON_TRUE:
    case JSON_FALSE:
    case JSON_NULL:
    default:
      error ("make_json with invalid Jansson type %d", (int) js->type);
    };
}                               /* end make_json */

void
clear_gtk_json_marks (void *root)
{
  assert (root != NULL);
#warning unimplemented clear_gtk_json_marks
}                               /* end clear_gtk_json_marks */


void
mark_json_ref (void *root, Obj * jsob)
{
  assert (root != NULL);
  assert (jsob != NULL && jsob->type == TJSONREF);
#warning unimplemented mark_json_ref
}                               /* end mark_json_ref */


void
mark_gtk_ref (void *root, Obj * gtkob)
{
  assert (root != NULL);
  assert (gtkob != NULL && gtkob->type == TGTKREF);
#warning unimplemented mark_gtk_ref
}                               /* end mark_gtk_ref */



void
clean_gc_json_gtk (void *root)
{
  assert (root != NULL);
#warning clean_gc_json_gtk unimplemented
}                               /* end clean_gc_json_gtk */

void
file_json_print (FILE * fil, Obj * obj, unsigned depth)
{
  assert (fil != NULL);
  assert (obj != NULL && obj->type == TJSONREF);
  fprintf (fil, "<json#%d", obj->json_index);
#warning file_json_print unimplemented
  fprintf (fil, ">");
}                               /* end file_json_print */


void
file_gtk_print (FILE * fil, Obj * obj, unsigned depth)
{
  assert (fil != NULL);
  assert (obj != NULL && obj->type == TGTKREF);
  fprintf (fil, "<gtk#%d", obj->gtk_index);
#warning file_gtk_print unimplemented
  fprintf (fil, ">");
}

/************
 ** for Emacs:
 ** Local Variables: ;;
 ** compile-command: "./build.sh" ;;
 ** End: ;;
 ************/
