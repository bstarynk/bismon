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


void
mark_gtk_ref (void *root, Obj *gtkob)
{
  int gtkix = -1;
  assert (root != NULL);
  assert (gtkob != NULL && gtkob->type == TGTKREF);
  gtkix = gtkob->gtk_index;
  error ("mark_json_ref unimplemented for GTK ref#%d", gtkix);
#warning unimplemented mark_gtk_ref
}                               /* end mark_gtk_ref */


void
file_gtk_print (FILE * fil, Obj *obj, unsigned depth)
{
  assert (fil != NULL);
  assert (obj != NULL && obj->type == TGTKREF);
  fprintf (fil, "<gtk#%d", obj->gtk_index);
#warning file_gtk_print unimplemented
  fprintf (fil, ">");
}                               /* end file_gtk_print */

Obj *
prim_json_eq (void *root, Obj **env, Obj **list)
{
  if (length (*list) != 2)
    error ("Malformed = (json)");
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
#warning prim_json_eq unimplemented
      error ("prim_json_eq unimplemented json#%d & json#%d", xix, yix);
    }
  return Nil;
}                               /* end prim_json_eq */

Obj *
prim_gtk_eq (void *root, Obj **env, Obj **list)
{
  if (length (*list) != 2)
    error ("Malformed = (gtk)");
  Obj *values = eval_list (root, env, list);
  Obj *x = values->car;
  Obj *y = values->cdr->car;
  if (x->type == TGTKREF && y->type == TGTKREF)
    {
      int xix = x->gtk_index;
      int yix = y->gtk_index;
      if (xix == yix)
        return True;
#warning prim_gtk_eq unimplemented
      error ("prim_gtk_eq unimplemented gtk#%d & gtk#%d");
    }
  return Nil;
}                               /* end prim_json_eq */


void
initialize_gtk (int *pargc, char **argv)
{
}                               /* end initialize_gtk */

/// this routine is called at start of the garbage collector to clear the GC marks for GTK references
void
clear_gtk_marks (void *root)
{
  assert (root != NULL);
#warning unimplemented clear_gtk_marks
}                               /* end clear_gtk_marks */

void
clean_gc_gtk (void *root)
{
  assert (root != NULL);
#warning unimplemented clean_gc_gtk
}                               /* end clean_gc_gtk */


void
define_gtk_primitives (void *root, Obj **env)
{
  add_primitive (root, env, "gtk_eq", prim_gtk_eq);
}                               /* end define_gtk_primitives */


/************
 ** for Emacs:
 ** Local Variables: ;;
 ** compile-command: "./build.sh" ;;
 ** End: ;;
 ************/

///// end of file bismon/gtkgui/gtkbismonlisp.c
