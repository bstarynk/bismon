// file gui_BM.c
#include "bismon.h"

void
initialize_gui_BM (const char *builderfile)
{
  if (!builderfile)
    builderfile = "bismon.ui";
  GtkBuilder *bld = gtk_builder_new_from_file (builderfile);
  GtkWindow *mainwin =
    GTK_WINDOW (gtk_builder_get_object (bld, "mainwin_id"));
  gtk_window_set_default_size (mainwin, 560, 430);
  gtk_widget_show_all (GTK_WIDGET (mainwin));
}                               /* end initialize_gui_BM */
