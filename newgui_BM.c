/* file newgui_BM.c */
#include "bismon.h"

void
initialize_newgui_BM (const char *builderfile, const char *cssfile)
{
  if (!builderfile)
    builderfile = "bismon.ui";
  if (!cssfile)
    cssfile = "bismon.css";
  GtkBuilder *bld = gtk_builder_new_from_file (builderfile);
  GtkCssProvider *cssprovider = gtk_css_provider_get_default ();
  g_signal_connect (cssprovider, "parsing-error",
                    G_CALLBACK (cssparsingerror_BM), NULL);
  gtk_css_provider_load_from_path (cssprovider, cssfile, NULL);
  initialize_gui_tags_BM (bld);
  //gtk_builder_add_callback_symbols (bld, "quitaction_BM", quit_BM, NULL);
  mainwin_BM = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_style_context_add_provider_for_screen
    (gtk_window_get_screen (GTK_WINDOW (mainwin_BM)),
     GTK_STYLE_PROVIDER (cssprovider),
     GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
  ////////////////
  GtkWidget *mainvbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
  gtk_container_add (GTK_CONTAINER (mainwin_BM), mainvbox);
  ///////////////
  initialize_gui_menu_BM (mainvbox, bld);
  GtkWidget *paned = gtk_paned_new (GTK_ORIENTATION_VERTICAL);
  gtk_paned_set_wide_handle (GTK_PANED (paned), true);
  gtk_paned_set_position (GTK_PANED (paned), 250);
  gtk_box_pack_start (GTK_BOX (mainvbox), paned, BOXEXPAND_BM, BOXFILL_BM, 2);
  ///
#warning initialize_newgui_BM unimplemented
  fprintf (stderr, "initialize_newgui_BM builder %s css %s unimplemented",
           builderfile, cssfile);
  ///
  gtk_window_set_title (GTK_WINDOW (mainwin_BM), "new-bismon");
  gtk_window_set_default_size (GTK_WINDOW (mainwin_BM), 650, 720);
  // perhaps run the GC twice a second
  g_timeout_add (500, guiperiodicgarbagecollection_BM, NULL);
  gtk_widget_show_all (GTK_WIDGET (mainwin_BM));
}                               /* end initialize_newgui_BM */
