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

GtkApplication *app_minilisp;
int *minilisp_pargc;
char **minilisp_argv;

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


bool
gtkref_recursive_equal (Obj *x, Obj *y, unsigned depth)
{
  if (x == y)
    return true;
  if (depth > MAX_RECURSIVE_DEPTH)
    return false;
  if (x->type == TGTKREF && y->type == TGTKREF)
    {
      int xix = x->gtk_index;
      int yix = y->gtk_index;
      if (xix == yix)
        return True;
    }
  return false;
}                               /* end gtkref_recursive_equal */

Obj *
prim_gtk_eq (void *root, Obj **env, Obj **list)
{
  if (length (*list) != 2)
    error ("Malformed = (gtk)");
  Obj *values = eval_list (root, env, list);
  Obj *x = values->car;
  Obj *y = values->cdr->car;
  if (x->type == TGTKREF && y->type == TGTKREF)
    return gtkref_recursive_equal (x, y, 0) ? True : Nil;
  return Nil;
}                               /* end prim_gtk_eq */

Obj *
prim_gtk_loop (void *root, Obj **env, Obj **list)
{
  if (!app_minilisp)
    error ("gtk_loop: no GTK application");
  if (length (*list) > 0)
    error ("gtk_loop needs no extra arguments, got %d", (int) length (*list));
  Obj *values = eval_list (root, env, list);
  int status =                  //
    g_application_run (G_APPLICATION (app_minilisp),
                       *minilisp_pargc, minilisp_argv);
  if (status == 0)
    return Nil;
  else
    return make_int (root, status);
}                               /* end prim_gtk_loop */

void
initialize_gtk (int *pargc, char ***pargv)
{
#warning notice that gtk_init is different in GTK 3 and GTK 4
  gtk_init (pargc, pargv);      /*the GTK3 one */
  minilisp_pargc = pargc;
  minilisp_argv = *pargv;
  app_minilisp = gtk_application_new ("fr.cea.www-list.bismon.guigtk", 0);
  g_application_add_main_option (G_APPLICATION (app_minilisp),
                                 /*long_name: */ "script",
                                 /*short_name: */ 'S',
                                 /*flags: */ G_OPTION_FLAG_FILENAME,
                                 /*arg: */ G_OPTION_ARG_FILENAME,
                                 /*description: */
                                 "load script file SCRIPTFILE",
                                 /*arg_description: */ "SCRIPTFILE");
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
  add_primitive (root, env, "gtk_loop", prim_gtk_loop);
}                               /* end define_gtk_primitives */


/************
 ** for Emacs:
 ** Local Variables: ;;
 ** compile-command: "./build.sh" ;;
 ** End: ;;
 ************/

///// end of file bismon/gtkgui/gtkbismonlisp.c
