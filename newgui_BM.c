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
#warning initialize_newgui_BM unimplemented
  FATAL_BM ("initialize_newgui_BM builder %s css %s unimplemented",
            builderfile, cssfile);
}                               /* end initialize_newgui_BM */
