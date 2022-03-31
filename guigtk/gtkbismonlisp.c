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

#include <gtk/gtk.h>

#include <math.h>

#include "bismon-gui-minilisp.h"

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

static void *gtk_cur_root;
static Obj **gtk_cur_env;
static Obj **gtk_cur_list;

void
forward_gtk_objects (void)
{
  if (gtk_cur_env)
    *gtk_cur_env = forward_for_gc (*gtk_cur_env);
  if (gtk_cur_list)
    *gtk_cur_list = forward_for_gc (*gtk_cur_list);
}                               /* end forward_gtk_objects */

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
          && gtkix <= (int) gtk_vect.gtkv_count && gtk_vect.gtkv_arr
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
          && glibix <= (int) glib_vect.glibv_count && glib_vect.glibv_arr);
  return (GObject *) glib_vect.glibv_arr[glibix];
}                               /* end get_g_object */



void
file_gtk_print (FILE * fil, Obj *gtkob, unsigned depth)
{
  int gtkix = -1;
  assert (fil != NULL);
  assert (gtkob != NULL && gtkob->type == TGTKREF);
  gtkix = gtkob->gtk_index;
  assert (gtkix > 0 && gtkix <= (int) gtk_vect.gtkv_count && gtk_vect.gtkv_arr
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
    fprintf (fil, "@%p", (void *) widg);
  const gchar *cssname =
    gtk_widget_class_get_css_name (GTK_WIDGET_GET_CLASS (widg));
  if (cssname)
    fprintf (fil, ".%s", cssname);
  if (depth == 0)
    {
      if (gtk_widget_get_realized (widg))
        fprintf (fil, "°realized");
      if (gtk_widget_get_visible (widg))
        fprintf (fil, "°visible");
      if (gtk_widget_get_mapped (widg))
        fprintf (fil, "°mapped");
      {
        int allow = gtk_widget_get_allocated_width (widg);
        int alloh = gtk_widget_get_allocated_height (widg);
        if (allow > 0 && alloh > 0)
          fprintf (fil, "°alw=%d,alh=%d", allow, alloh);
      }
      if (gtk_widget_get_no_show_all (widg))
        fprintf (fil, "°noshowall");
    }
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
  assert (glibix > 0 && glibix <= (int) glib_vect.glibv_count
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
  *res = make_glib_object (root, (GObject *) gbuilder);
  return *res;
}                               /* end prim_gtk_builder */

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
  if (!obj)
    {
      fprintf (stderr, "eval_in_gtk_callback nothing to eval\n");
      show_backtrace_stderr ();
      return Nil;
    }
  return eval (gtk_cur_root, gtk_cur_env, obj);
}                               /* end eval_in_gtk_callback */

Obj *
eval_list_in_gtk_callback (Obj **list)
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
  return eval_list (gtk_cur_root, gtk_cur_env, list);
}                               /* end eval_list_in_gtk_callback */


Obj *
make_glib_object (void *root, GObject *glibob)
{
  Obj *res = NULL;
  assert (root != NULL);
  assert (glibob != NULL);
  intptr_t glix = 0;
  if (!glib_ghtbl)
    return Nil;
  res = alloc (root, TGLIBREF, sizeof (res->glib_index));
  intptr_t ix = (intptr_t) g_hash_table_lookup (glib_ghtbl, glibob);
  if (ix > 0)
    glix = ix;
  else
    {
      if (glib_vect.glibv_count + 2 >= glib_vect.glibv_size)
        {                       // nearly full
          if (glib_vect.glibv_size > 2 * MAX_VECTOR_LEN)
            {
              error ("make_glib with too many objects %zd",
                     glib_vect.glibv_size);
              return Nil;
            }
          unsigned newsiz =
            1 +
            ((glib_vect.glibv_count + 10 + glib_vect.glibv_size / 4) | 0x1f);
          assert (newsiz > glib_vect.glibv_size);
          GObject **newarr = calloc (newsiz, sizeof (GObject *));
          if (!newarr)
            {
              fprintf (stderr, "calloc failed for %u GObject* pointers (%s)",
                       newsiz, strerror (errno));
              show_backtrace_stderr ();
              exit (EXIT_FAILURE);
            };
          if (glib_vect.glibv_arr)
            {
              memcpy (newarr, glib_vect.glibv_arr,
                      glib_vect.glibv_count * sizeof (GObject *));
              free (glib_vect.glibv_arr);
            };
          glib_vect.glibv_arr = newarr;
          bool *newmarkarr = calloc (newsiz, sizeof (bool));
          if (!newmarkarr)
            {
              fprintf (stderr,
                       "calloc failed for %u mark flags for GObject-s (%s)",
                       newsiz, strerror (errno));
              show_backtrace_stderr ();
              exit (EXIT_FAILURE);
            };
          if (glib_vect.glibv_markarr)
            {
              memcpy (newmarkarr, glib_vect.glibv_markarr,
                      glib_vect.glibv_count * sizeof (bool));
              free (glib_vect.glibv_markarr);
            }
          glib_vect.glibv_markarr = newmarkarr;
          glib_vect.glibv_size = newsiz;
        };                      /* end if nearly full */
      glix = ++glib_vect.glibv_count;
      glib_vect.glibv_markarr[glix] = true;
      glib_vect.glibv_arr[glix] = glibob;
      g_hash_table_insert (glib_ghtbl, glibob, (void *) glix);
    }
  res->glib_index = glix;
  return res;
}                               /* end make_glib_object */



Obj *
make_gtk_object (void *root, GtkWidget *widg)
{
  Obj *res = NULL;
  assert (root != NULL);
  assert (widg != NULL);
  if (!gtk_ghtbl)
    return Nil;
  res = alloc (root, TGTKREF, sizeof (res->gtk_index));
  intptr_t gtkix = 0;
  intptr_t ix = (intptr_t) g_hash_table_lookup (gtk_ghtbl, widg);
  if (ix > 0)
    gtkix = ix;
  else
    {
      if (gtk_vect.gtkv_count + 2 >= gtk_vect.gtkv_size)
        {                       // nearly full
          if (gtk_vect.gtkv_size > 2 * MAX_VECTOR_LEN)
            {
              error ("make_gtk with too many objects %zd",
                     gtk_vect.gtkv_size);
              return Nil;
            }
          unsigned newsiz =
            1 + ((gtk_vect.gtkv_count + 10 + gtk_vect.gtkv_size / 4) | 0x1f);
          assert (newsiz > gtk_vect.gtkv_size);
          GtkWidget **newarr = calloc (newsiz, sizeof (GObject *));
          if (!newarr)
            {
              fprintf (stderr, "calloc failed for %u GObject* pointers (%s)",
                       newsiz, strerror (errno));
              show_backtrace_stderr ();
              exit (EXIT_FAILURE);
            };
          if (gtk_vect.gtkv_arr)
            {
              memcpy (newarr, gtk_vect.gtkv_arr,
                      gtk_vect.gtkv_count * sizeof (GObject *));
              free (gtk_vect.gtkv_arr);
            };
          gtk_vect.gtkv_arr = newarr;
          bool *newmarkarr = calloc (newsiz, sizeof (bool));
          if (!newmarkarr)
            {
              fprintf (stderr,
                       "calloc failed for %u mark flags for GObject-s (%s)",
                       newsiz, strerror (errno));
              show_backtrace_stderr ();
              exit (EXIT_FAILURE);
            };
          if (gtk_vect.gtkv_markarr)
            {
              memcpy (newmarkarr, gtk_vect.gtkv_markarr,
                      gtk_vect.gtkv_count * sizeof (bool));
              free (gtk_vect.gtkv_markarr);
            }
          gtk_vect.gtkv_markarr = newmarkarr;
          gtk_vect.gtkv_size = newsiz;
        };                      /* end if nearly full */
      gtkix = ++gtk_vect.gtkv_count;
      gtk_vect.gtkv_markarr[gtkix] = true;
      gtk_vect.gtkv_arr[gtkix] = widg;
      g_hash_table_insert (gtk_ghtbl, widg, (void *) gtkix);
    }
  res->gtk_index = gtkix;
  return res;
}                               /* end make_gtk_object */


/// (gtk_loop)
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
  if (verbose_ilisp)
    printf (";;gtk_loop running application\n");
  int status =                  //
    g_application_run (G_APPLICATION (app_minilisp),
                       *minilisp_pargc, minilisp_argv);
  if (verbose_ilisp)
    printf (";;gtk_loop did run application\n");
  gtk_cur_root = old_gtk_root;
  gtk_cur_env = old_gtk_env;
  gtk_cur_list = old_gtk_cur_list;
  if (status == 0)
    return Nil;
  else
    return make_int (root, status);
}                               /* end prim_gtk_loop */


/// gives a boxed GTK widget or nil
/// (gtk_builder_get <builder> <name>)
Obj *
prim_gtk_builder_get (void *root, Obj **env, Obj **list)
{
  const char *namestr = NULL;
  GObject *buildgob = NULL;
  GObject *gotgob = NULL;
  DEFINE2 (builderob, nameob);
  if (pthread_self () != main_pthread)
    {
      fprintf (stderr,
               "gtk_builder_get primitive called from non-main pthread\n");
      show_backtrace_stderr ();
      return Nil;
    }
  if (!app_minilisp)
    error ("gtk_builder_get: no GTK application");
  Obj *args = eval_list (root, env, list);
  if (length (args) != 2)
    error ("gtk_builder_get needs two arguments <builder> <name>, got %d",
           (int) length (args));
  *builderob = args->car;
  *nameob = args->cdr->car;
  if ((*builderob)->type != TGLIBREF)
    error ("gtk_builder_get needs a TGLIBREF first argument, but got %s",
           minilisp_type_name ((*builderob)->type));
  buildgob = get_g_object (*builderob);
  assert (buildgob != NULL);
  if ((*nameob)->type == TSTRING)
    namestr = (*nameob)->utf8_cstring;
  else if ((*nameob)->type == TSYMBOL)
    namestr = (*nameob)->sy_name;
  else
    error
      ("gtk_builder_get needs a string or symbol second argument, but got %s",
       minilisp_type_name ((*nameob)->type));
  assert (namestr != NULL);
  if (!GTK_IS_BUILDER (buildgob))
    error ("gtk_builder_get needs a GtkBuilder as first argument");
  gotgob = gtk_builder_get_object (GTK_BUILDER (buildgob), namestr);
  if (!gotgob)
    return Nil;
  if (GTK_IS_WIDGET (gotgob))
    return make_gtk_object (root, GTK_WIDGET (gotgob));
  return make_glib_object (root, gotgob);
}                               /* end prim_gtk_builder_get */


/// show a window widget
/// (gtk_widget_show_all <widget>)
Obj *
prim_gtk_widget_show_all (void *root, Obj **env, Obj **list)
{
  GtkWidget *widg = NULL;
  DEFINE1 (widgob);
  if (pthread_self () != main_pthread)
    {
      fprintf (stderr,
               "gtk_builder_get primitive called from non-main pthread\n");
      show_backtrace_stderr ();
      return Nil;
    }
  if (!app_minilisp)
    error ("gtk_widget_show_all: no GTK application");
  Obj *args = eval_list (root, env, list);
  if (length (args) != 1)
    error ("gtk_widget_show_all one argument <widget>, got %d",
           (int) length (args));
  *widgob = args->car;
  widg = get_gtk_widget (*widgob);
  if (widg)
    gtk_widget_show_all (widg);
  else
    error ("gtk_widget_show_all without GtkWidget object");
  return *widgob;
}                               /* end prim_gtk_widget_show_all */



/// the expressions are evaluated when the application is activated 
/// (gtk_application_activate <expr> ....) 
Obj *
prim_gtk_application_activate (void *root, Obj **env, Obj **list)
{
  if (pthread_self () != main_pthread)
    {
      fprintf (stderr,
               "gtk_application_activate primitive called from non-main pthread\n");
      show_backtrace_stderr ();
      return Nil;
    }
  if (gtk_cur_root)
    error ("gtk_application_activate cannot recurse (gtk_cur_root)");
  if (gtk_cur_env)
    error ("gtk_application_activate cannot recurse (gtk_cur_env)");
  if (gtk_cur_list)
    error ("gtk_application_activate cannot recurse (gtk_cur_list)");
  if (!env)
    error ("gtk_application_activate without environment");
  if (!list || length (*list) == 0)
    error ("gtk_application_activate without arguments");
  gtk_cur_root = root;
  gtk_cur_env = env;
  gtk_cur_list = list;
  return *list;
}                               /* end prim_gtk_application_activate */


extern void finalize_gtk (void);
extern void activate_app_minilisp (GApplication * app, gpointer data);

void
initialize_gtk (int *pargc, char ***pargv)
{
  GError *perr = NULL;
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
  g_signal_connect (G_APPLICATION (app_minilisp), "activate",
                    G_CALLBACK (activate_app_minilisp), NULL);
  if (!g_application_register (G_APPLICATION (app_minilisp), NULL, &perr))
    {
      fprintf (stderr, "%s: failed to register application: %s\n",
               program_name, perr ? (perr->message) : "???");
      exit (EXIT_FAILURE);
    };
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



void
activate_app_minilisp (GApplication * app, gpointer data)
{
  if (verbose_ilisp)
    printf ("application @%p is activated with data %p (%s:%d)\n",
            (void *) app, (void *) data, __FILE__, __LINE__);
  if (pthread_self () != main_pthread)
    {
      fprintf (stderr,
               "gtk_application_activate primitive called from non-main pthread\n");
      show_backtrace_stderr ();
      return;
    }
  if (!gtk_cur_root)
    {
      fprintf (stderr, "activate_app_minilisp without gtk_cur_root\n");
      show_backtrace_stderr ();
      return;
    }
  if (!gtk_cur_env)
    {
      fprintf (stderr, "activate_app_minilisp without gtk_cur_env\n");
      show_backtrace_stderr ();
      return;
    }
  if (!gtk_cur_list)
    {
      fprintf (stderr, "activate_app_minilisp without gtk_cur_list\n");
      show_backtrace_stderr ();
      return;
    }
  eval_list_in_gtk_callback (gtk_cur_list);
}                               /* end activate_app_minilisp */





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
  add_primitive (root, env, "gtk_builder_get", prim_gtk_builder_get);
  add_primitive (root, env, "gtk_widget_show_all", prim_gtk_widget_show_all);
  add_primitive (root, env, "gtk_application_activate",
                 prim_gtk_application_activate);
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
    };
  if (app_minilisp)
    g_object_unref (app_minilisp), app_minilisp = NULL;
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
