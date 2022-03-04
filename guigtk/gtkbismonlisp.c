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

enum gtk_pointer_kind_en
{
  MINILISPGTK_none,
  MINILISPGTK_WIDGET,           /* a GtkWidget* pointer */
  MINILISPGTK_GOBJECT,          /* some GObject* pointer */
};

struct
{
  void **gtkv_arr;              /* array of pointers */
  bool *gtkv_markarr;           /* array of GC marks */
  enum gtk_pointer_kind_en *gtkv_kindarr;
  unsigned gtkv_size;           /* allocated size */
  unsigned gtkv_count;          /* used count */
} gtk_vect;

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
          && gtk_vect.gtkv_kindarr);
  switch (gtk_vect.gtkv_kindarr[gtkix])
    {
    case MINILISPGTK_WIDGET:
      return (GtkWidget *) gtk_vect.gtkv_arr[gtkix];
    default:
      return NULL;
    }
  return NULL;
}                               /* end get_gtk_widget */



GObject *
get_g_object (Obj *ob)
{
  int gtkix = -1;
  if (ob == NULL)
    return NULL;
  if (ob->type != TGTKREF)
    return NULL;
  gtkix = ob->gtk_index;
  assert (gtkix > 0
          && gtkix < (int) gtk_vect.gtkv_count && gtk_vect.gtkv_arr
          && gtk_vect.gtkv_kindarr);
  switch (gtk_vect.gtkv_kindarr[gtkix])
    {
    case MINILISPGTK_GOBJECT:
      return (GObject *) gtk_vect.gtkv_arr[gtkix];
    default:
      break;
    };
  return NULL;
}                               /* end get_g_object */

void
file_gtk_print (FILE * fil, Obj *gtkob, unsigned depth)
{
  int gtkix = -1;
  assert (fil != NULL);
  assert (gtkob != NULL && gtkob->type == TGTKREF);
  gtkix = gtkob->gtk_index;
  assert (gtkix > 0 && gtkix < (int) gtk_vect.gtkv_count && gtk_vect.gtkv_arr
          && gtk_vect.gtkv_kindarr);
  switch (gtk_vect.gtkv_kindarr[gtkix])
    {
    case MINILISPGTK_WIDGET:
      {
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
      };
      break;
    case MINILISPGTK_GOBJECT:
      {
        fprintf (fil, "<gobj#%d", gtkix);
        GObject *gob = gtk_vect.gtkv_arr[gtkix];
        if (depth > MAX_RECURSIVE_DEPTH)
          {
            fputs ("…", fil);
            goto end;
          }
        assert (gob != NULL);
        const gchar *nam = G_OBJECT_TYPE_NAME (gob);
        if (nam)
          fprintf (fil, ":%s", nam);
      }
      break;
    default:
      assert (false);
    }
end:
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
      assert (xix > 0 && xix < (int) gtk_vect.gtkv_count
              && gtk_vect.gtkv_arr);
      assert (yix > 0 && yix < (int) gtk_vect.gtkv_count
              && gtk_vect.gtkv_arr);
      if (gtk_vect.gtkv_kindarr[xix] == MINILISPGTK_WIDGET
          && gtk_vect.gtkv_kindarr[yix] == MINILISPGTK_WIDGET)
        return gtk_vect.gtkv_arr[xix] == gtk_vect.gtkv_arr[yix];
      if (gtk_vect.gtkv_kindarr[xix] == MINILISPGTK_GOBJECT
          && gtk_vect.gtkv_kindarr[yix] == MINILISPGTK_GOBJECT)
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
      void *curad = gtk_vect.gtkv_arr[gix];
      if (curad == NULL)
        continue;
      if (gtk_vect.gtkv_markarr[gix])
        continue;
      if (gtk_vect.gtkv_kindarr[gix] == MINILISPGTK_WIDGET)
        {
          gtk_vect.gtkv_arr[gix] = NULL;
          gtk_widget_destroy ((GtkWidget *) curad);
        }
      else if (gtk_vect.gtkv_kindarr[gix] == MINILISPGTK_GOBJECT)
        {
          gtk_vect.gtkv_arr[gix] = NULL;
          g_object_unref ((GObject *) curad);
        };
    }
#warning unimplemented clean_gc_gtk
}                               /* end clean_gc_gtk */


void
define_gtk_primitives (void *root, Obj **env)
{
  add_primitive (root, env, "gtk_eq", prim_gtk_eq);
  add_primitive (root, env, "gtk_loop", prim_gtk_loop);
}                               /* end define_gtk_primitives */


void
finalize_gtk (void)
{
  if (gtk_vect.gtkv_count > 0)
    {
      assert (gtk_vect.gtkv_markarr != NULL);
      assert (gtk_vect.gtkv_arr != NULL);
      assert (gtk_vect.gtkv_kindarr != NULL);
      for (int ix = 0; ix < (int) gtk_vect.gtkv_count; ix++)
        {
          if (gtk_vect.gtkv_kindarr[ix] == MINILISPGTK_WIDGET)
            {
              if (gtk_vect.gtkv_arr[ix])
                gtk_widget_destroy ((GtkWidget *) gtk_vect.gtkv_arr[ix]);
              gtk_vect.gtkv_arr[ix] = NULL;
            }
          else if (gtk_vect.gtkv_kindarr[ix] == MINILISPGTK_GOBJECT)
            {
              if (gtk_vect.gtkv_arr[ix])
                g_object_unref ((GObject *) gtk_vect.gtkv_arr[ix]);
              gtk_vect.gtkv_arr[ix] = NULL;
            }
        }
      free (gtk_vect.gtkv_markarr);
      free (gtk_vect.gtkv_arr);
      free (gtk_vect.gtkv_kindarr);
      memset (&gtk_vect, 0, sizeof (gtk_vect));
    }
}                               /* end finalize_gtk */



/************
 ** for Emacs:
 ** Local Variables: ;;
 ** compile-command: "./build.sh" ;;
 ** End: ;;
 ************/

///// end of file bismon/gtkgui/gtkbismonlisp.c
