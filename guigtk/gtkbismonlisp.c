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

#include <gtk/gtk.h>

#include <math.h>


GtkApplication *app_minilisp;
int *minilisp_pargc;
char **minilisp_argv;

GHashTable *gtk_ghtbl;          /* an hashtable associating Gtk pointers to intptr_t ranks */

GHashTable *glib_ghtbl;         /* an hashtable associating GObject pointers to intptr_t ranks */

struct
{
  GtkWidget **gtkv_arr;         /* array of GTK pointers */
  bool *gtkv_markarr;           /* array of GC marks */
  unsigned gtkv_size;           /* allocated size */
  unsigned gtkv_count;          /* used count */
} gtk_vect;

struct
{
  GObject **glibv_arr;          /* array of GTK pointers */
  bool *glibv_markarr;          /* array of GC marks */
  unsigned glibv_size;          /* allocated size */
  unsigned glibv_count;         /* used count */
} glib_vect;

void
mark_gtk_ref (void *root, Obj *gtkob)
{
  int gtkix = -1;
  assert (root != NULL);
  assert (gtkob != NULL && gtkob->type == TGTKREF);
  assert (gtk_vect.gtkv_count <= gtk_vect.gtkv_size);
  gtkix = gtkob->gtk_index;
  if (gtkix > 0 && gtkix < (int) gtk_vect.gtkv_count && gtk_vect.gtkv_arr)
    {
      gtk_vect.gtkv_markarr[gtkix] = true;
    }
}                               /* end mark_gtk_ref */

void
mark_glib_ref (void *root, Obj *glibob)
{
  int glibix = -1;
  assert (root != NULL);
  assert (glibob != NULL && glibob->type == TGLIBREF);
  assert (glib_vect.glibv_count <= glib_vect.glibv_size);
  glibix = glibob->glib_index;
  if (glibix > 0 && glibix < (int) glib_vect.glibv_count
      && glib_vect.glibv_arr)
    {
      glib_vect.glibv_markarr[glibix] = true;
    }
}                               /* end mark_glib_ref */

GtkWidget *
get_gtk_widget (Obj *ob)
{
  int gtkix = -1;
  if (ob == NULL)
    return NULL;
  if (ob->type != TGTKREF)
    return NULL;
  gtkix = ob->gtk_index;
  assert (gtkix > 0
          && gtkix < (int) gtk_vect.gtkv_count && gtk_vect.gtkv_arr
          && gtk_vect.gtkv_markarr);
  return (GtkWidget *) gtk_vect.gtkv_arr[gtkix];
  return NULL;
}                               /* end get_gtk_widget */



GObject *
get_g_object (Obj *ob)
{
  int glibix = -1;
  if (ob == NULL)
    return NULL;
  if (ob->type != TGLIBREF)
    return NULL;
  glibix = ob->glib_index;
  assert (glibix > 0
          && glibix < (int) glib_vect.glibv_count && glib_vect.glibv_arr);
  return (GObject *) glib_vect.glibv_arr[glibix];
}                               /* end get_g_object */



void
file_gtk_print (FILE * fil, Obj *gtkob, unsigned depth)
{
  int gtkix = -1;
  assert (fil != NULL);
  assert (gtkob != NULL && gtkob->type == TGTKREF);
  gtkix = gtkob->gtk_index;
  assert (gtkix > 0 && gtkix < (int) gtk_vect.gtkv_count && gtk_vect.gtkv_arr
          && gtk_vect.gtkv_markarr);
  fprintf (fil, "<gtkw#%d", gtkix);
  if (depth > MAX_RECURSIVE_DEPTH)
    {
      fputs ("…", fil);
      goto end;
    }
  GtkWidget *widg = gtk_vect.gtkv_arr[gtkix];
  assert (widg != NULL);
  const gchar *widname = gtk_widget_get_name (widg);
  if (widname)
    fprintf (fil, "/%s", widname);
  else
    fprintf (fil, "@%p", (void *) widname);
  const gchar *cssname =
    gtk_widget_class_get_css_name (GTK_WIDGET_GET_CLASS (widg));
  if (cssname)
    fprintf (fil, ".%s", cssname);


  /***
      case MINILISPGTK_GOBJECT:
      {
  ***/

end:
  fprintf (fil, ">");
}                               /* end file_gtk_print */



void
file_glib_print (FILE * fil, Obj *glibob, unsigned depth)
{
  int glibix = -1;
  assert (fil != NULL);
  assert (glibob != NULL && glibob->type == TGLIBREF);
  glibix = glibob->glib_index;
  assert (glibix > 0 && glibix < (int) glib_vect.glibv_count
          && glib_vect.glibv_arr && glib_vect.glibv_markarr);
  fprintf (fil, "<glib#%d", glibix);
  if (depth > MAX_RECURSIVE_DEPTH)
    {
      fputs ("…", fil);
      goto end;
    }
  GObject *gob = glib_vect.glibv_arr[glibix];
  if (depth > MAX_RECURSIVE_DEPTH)
    {
      fputs ("…", fil);
      goto end;
    }
  if (!gob)
    {
      fputs ("?nilGlib?", fil);
      goto end;
    }
  assert (gob != NULL);
  const gchar *nam = G_OBJECT_TYPE_NAME (gob);
  if (nam)
    fprintf (fil, ":%s", nam);
end:
  fputs (">", fil);
}                               /* end file_glib_print */


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
      assert (xix > 0 && xix < (int) gtk_vect.gtkv_count
              && gtk_vect.gtkv_arr);
      assert (yix > 0 && yix < (int) gtk_vect.gtkv_count
              && gtk_vect.gtkv_arr);
      return gtk_vect.gtkv_arr[xix] == gtk_vect.gtkv_arr[yix];
    }
  return false;
}                               /* end gtkref_recursive_equal */

Obj *
prim_gtk_eq (void *root, Obj **env, Obj **list)
{
  if (length (*list) != 2)
    error ("Malformed = (gtk)");
  DEFINE1 (args);
  *args = eval_list (root, env, list);
  Obj *x = (*args)->car;
  Obj *y = (*args)->cdr->car;
  if (x->type == TGTKREF && y->type == TGTKREF)
    return gtkref_recursive_equal (x, y, 0) ? True : Nil;
  return Nil;
}                               /* end prim_gtk_eq */

Obj *
prim_gtk_builder (void *root, Obj **env, Obj **list)
{
  if (length (*list) != 1)
    error ("Malformed gtk_builder, need one argument");
  DEFINE2 (args, res);
  *args = eval_list (root, env, list);
  Obj *strv = (*args)->car;
  if (!strv)
    {
      error ("gtk_builder expects a string argument, got none");
      return Nil;
    }
  else if (strv->type != TSTRING)
    {
      error ("gtk_builder expects a string argument, got type %s",
             minilisp_type_name (strv->type));
      return Nil;
    }
  const char *str = utf8string_in_obj (strv);
  assert (str != NULL);
  GtkBuilder *gbuilder = gtk_builder_new_from_string (str, -1);
  if (!gbuilder)
    {
      fprintf (stderr,
               "gtk_builder primitive fails gtk_builder_new_from_string on\n%s\n",
               str);
      show_backtrace_stderr ();
      fflush (stderr);
      return Nil;
    }
}                               /* end prim_gtk_builder */

static void *gtk_cur_root;
static Obj **gtk_cur_env;
static Obj **gtk_cur_list;

Obj *
eval_in_gtk_callback (Obj **obj)
{
  if (pthread_self () != main_pthread)
    {
      fprintf (stderr, "eval_in_gtk_callback called from non-main pthread\n");
      show_backtrace_stderr ();
      return Nil;
    }
  if (!gtk_cur_root || !gtk_cur_env || !gtk_cur_list)
    {
      fprintf (stderr, "eval_in_gtk_callback badly called\n");
      show_backtrace_stderr ();
      return Nil;
    }
  return eval (gtk_cur_root, gtk_cur_env, obj);
}                               /* end eval_in_gtk_callback */

Obj *
eval_list_in_gtk_callback (Obj **env, Obj **list)
{
  if (pthread_self () != main_pthread)
    {
      fprintf (stderr,
               "eval_list_in_gtk_callback called from non-main pthread\n");
      show_backtrace_stderr ();
      return Nil;
    }
  if (gtk_cur_root == NULL)
    {
      fprintf (stderr,
               "eval_list_in_gtk_callback called without gtk_cur_root\n");
      show_backtrace_stderr ();
      return Nil;
    }
  if (!env)
    env = gtk_cur_env;
  if (!list)
    list = gtk_cur_list;
  return eval_list (gtk_cur_root, env, list);
}                               /* end eval_list_in_gtk_callback */


Obj *
make_glib_object (void *root, GObject * glibob)
{
  assert (root != NULL);
  assert (glibob != NULL);
  Obj *res = NULL;
  res = alloc (root, TGLIBREF, sizeof (GObject *));
}                               /* end make_glib_object */

Obj *
make_gtk_object (void *root, GtkWidget * widg)
{
  assert (root != NULL);
  assert (widg != NULL);
  Obj *res = NULL;
  res = alloc (root, TGTKREF, sizeof (GtkWidget *));
}                               /* end make_gtk_object */

Obj *
prim_gtk_loop (void *root, Obj **env, Obj **list)
{
  if (pthread_self () != main_pthread)
    {
      fprintf (stderr, "gtk_loop primitive called from non-main pthread\n");
      show_backtrace_stderr ();
      return Nil;
    }
  if (!app_minilisp)
    error ("gtk_loop: no GTK application");
  if (length (*list) > 0)
    error ("gtk_loop needs no extra arguments, got %d", (int) length (*list));
  // not needed, since no arguments:
  // Obj *values = eval_list (root, env, list);
  DEFINE2 (prev_env, prev_list);
  *prev_env = *env;
  *prev_list = *list;
  void *old_gtk_root = gtk_cur_root;
  Obj **old_gtk_env = gtk_cur_env;
  Obj **old_gtk_cur_list = gtk_cur_list;
  gtk_cur_root = root;
  gtk_cur_env = env;
  gtk_cur_list = list;
  int status =                  //
    g_application_run (G_APPLICATION (app_minilisp),
                       *minilisp_pargc, minilisp_argv);
  gtk_cur_root = old_gtk_root;
  gtk_cur_env = old_gtk_env;
  gtk_cur_list = old_gtk_cur_list;
  if (status == 0)
    return Nil;
  else
    return make_int (root, status);
}                               /* end prim_gtk_loop */


extern void finalize_gtk (void);
void
initialize_gtk (int *pargc, char ***pargv)
{
#warning notice that gtk_init is different in GTK 3 and GTK 4
  gtk_init (pargc, pargv);      /*the GTK3 one */
  minilisp_pargc = pargc;
  minilisp_argv = *pargv;
  main_pthread = pthread_self ();
  app_minilisp = gtk_application_new ("fr.cea.www-list.bismon.guigtk", 0);
  g_application_add_main_option (G_APPLICATION (app_minilisp),
                                 /*long_name: */ "script",
                                 /*short_name: */ 'S',
                                 /*flags: */ G_OPTION_FLAG_NONE,
                                 /*arg: */ G_OPTION_ARG_FILENAME,
                                 /*description: */
                                 "load script file SCRIPTFILE",
                                 /*arg_description: */ "SCRIPTFILE");
  atexit (finalize_gtk);
  gtk_ghtbl = g_hash_table_new (g_direct_hash, g_direct_equal);
  unsigned inisiz = 128;
  gtk_vect.gtkv_arr = calloc (inisiz, sizeof (GtkWidget *));
  if (!gtk_vect.gtkv_arr)
    {
      fprintf (stderr, "calloc failed for %u GtkWidget* pointers (%s)",
               inisiz, strerror (errno));
      show_backtrace_stderr ();
      exit (EXIT_FAILURE);
    };
  gtk_vect.gtkv_markarr = calloc (inisiz, sizeof (bool));
  if (!gtk_vect.gtkv_markarr)
    {
      fprintf (stderr, "calloc failed for %u mark flags (%s)", inisiz,
               strerror (errno));
      free (gtk_vect.gtkv_arr), gtk_vect.gtkv_arr = NULL;
      show_backtrace_stderr ();
      exit (EXIT_FAILURE);
    };
  gtk_vect.gtkv_size = inisiz;
}                               /* end initialize_gtk */


/// this routine is called at start of the garbage collector to clear
/// the GC marks for GTK references
void
clear_gtk_marks (void *root)
{
  assert (root != NULL);
  if (gtk_vect.gtkv_markarr == NULL)
    return;
  for (int gix = 0; gix < (int) gtk_vect.gtkv_count; gix++)
    {
      if (gtk_vect.gtkv_arr[gix] == NULL)
        continue;
      gtk_vect.gtkv_markarr[gix] = false;
    }
}                               /* end clear_gtk_marks */


//// This routine is called from garbage collector (function gc in
//// file minilisp.c), and should remove GTK objects or Glib gobjects
//// which have not been marked.
void
clean_gc_gtk (void *root)
{
  assert (root != NULL);
  if (gtk_vect.gtkv_markarr == NULL)
    return;
  for (int gix = 0; gix < (int) gtk_vect.gtkv_count; gix++)
    {
      GtkWidget *widg = gtk_vect.gtkv_arr[gix];
      if (widg == NULL)
        continue;
      if (gtk_vect.gtkv_markarr[gix])
        continue;
      gtk_vect.gtkv_arr[gix] = NULL;
      gtk_widget_destroy (widg);
    }
}                               /* end clean_gc_gtk */

void
clean_gc_glib (void *root)
{
  assert (root != NULL);
  if (glib_vect.glibv_markarr == NULL)
    return;
  for (int gix = 0; gix < (int) glib_vect.glibv_count; gix++)
    {
      GObject *gob = glib_vect.glibv_arr[gix];
      if (gob == NULL)
        continue;
      if (glib_vect.glibv_markarr[gix])
        continue;
      glib_vect.glibv_arr[gix] = NULL;
      g_object_unref (gob);
    }
}                               /* end clean_gc_glib */


void
define_gtk_primitives (void *root, Obj **env)
{
  add_primitive (root, env, "gtk_eq", prim_gtk_eq);
  add_primitive (root, env, "gtk_loop", prim_gtk_loop);
  add_primitive (root, env, "gtk_builder", prim_gtk_builder);
}                               /* end define_gtk_primitives */


void
finalize_gtk (void)
{
  if (gtk_vect.gtkv_count == 0)
    return;
  assert (gtk_vect.gtkv_markarr != NULL);
  assert (gtk_vect.gtkv_arr != NULL);
  for (int ix = 0; ix < (int) gtk_vect.gtkv_count; ix++)
    {
      if (gtk_vect.gtkv_arr[ix])
        gtk_widget_destroy ((GtkWidget *) gtk_vect.gtkv_arr[ix]);
      gtk_vect.gtkv_arr[ix] = NULL;
      free (gtk_vect.gtkv_markarr);
      free (gtk_vect.gtkv_arr);
      memset (&gtk_vect, 0, sizeof (gtk_vect));
    }
}                               /* end finalize_gtk */


extern void finalize_glib (void);
void
initialize_glib (void)
{
  atexit (finalize_glib);
  glib_ghtbl = g_hash_table_new (g_direct_hash, g_direct_equal);
  unsigned inisiz = 128;
  glib_vect.glibv_arr = calloc (inisiz, sizeof (GObject *));
  if (!glib_vect.glibv_arr)
    {
      fprintf (stderr, "calloc failed for %u GObject* pointers (%s)", inisiz,
               strerror (errno));
      show_backtrace_stderr ();
      exit (EXIT_FAILURE);
    };
  glib_vect.glibv_markarr = calloc (inisiz, sizeof (bool));
  if (!glib_vect.glibv_markarr)
    {
      fprintf (stderr, "calloc failed for %u mark flags (%s)", inisiz,
               strerror (errno));
      free (glib_vect.glibv_arr), glib_vect.glibv_arr = NULL;
      show_backtrace_stderr ();
      exit (EXIT_FAILURE);
    };
  glib_vect.glibv_size = inisiz;
}                               /* end initialize_glib */


void
finalize_glib (void)
{
  if (glib_vect.glibv_count == 0)
    return;
  assert (glib_vect.glibv_markarr != NULL);
  assert (glib_vect.glibv_arr != NULL);
  for (int ix = 0; ix < (int) glib_vect.glibv_count; ix++)
    {
      if (glib_vect.glibv_arr[ix])
        g_object_unref (glib_vect.glibv_arr[ix]);
      glib_vect.glibv_arr[ix] = NULL;
      free (glib_vect.glibv_markarr);
      free (glib_vect.glibv_arr);
      memset (&glib_vect, 0, sizeof (glib_vect));
    };
}                               /* end finalize_glib */



/************
 ** for Emacs:
 ** Local Variables: ;;
 ** compile-command: "./build.sh" ;;
 ** End: ;;
 ************/

///// end of file bismon/gtkgui/gtkbismonlisp.c
