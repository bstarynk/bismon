// file gui_BM.c
#include "bismon.h"

const char *
gobjectclassnamedbg_BM (GObject * ptr)
{
  if (!ptr)
    return "*nil*";
  return G_OBJECT_CLASS_NAME (G_OBJECT_GET_CLASS (ptr));
}

void
initialize_gui_BM (const char *builderfile)
{
  if (!builderfile)
    builderfile = "bismon.ui";
  GtkBuilder *bld = gtk_builder_new_from_file (builderfile);
  GtkWidget *mainwin = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  GtkWidget *mainvbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
  gtk_container_add (GTK_CONTAINER (mainwin), mainvbox);
  GtkWidget *mainmenubar = gtk_menu_bar_new ();
  gtk_box_pack_end (GTK_BOX (mainvbox), mainmenubar, /*expand= */ false,
                    /*fill= */ false, 4);
  GtkWidget *appmenu =
    GTK_WIDGET (gtk_builder_get_object (bld, "appmenu_id"));
  assert (GTK_IS_WIDGET (appmenu));
  gtk_menu_shell_append (GTK_MENU_SHELL (mainmenubar), appmenu);
  GtkWidget *editmenu =
    GTK_WIDGET (gtk_builder_get_object (bld, "editmenu_id"));
  assert (GTK_IS_WIDGET (editmenu));
  gtk_menu_shell_append (GTK_MENU_SHELL (mainmenubar), editmenu);
  gtk_window_set_title (GTK_WINDOW (mainwin), "bismon");
  //GTK_WINDOW (gtk_builder_get_object (bld, "mainwin_id"));
  gtk_window_set_default_size (GTK_WINDOW (mainwin), 560, 430);
  gtk_widget_show_all (GTK_WIDGET (mainwin));
}                               /* end initialize_gui_BM */
