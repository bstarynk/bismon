/* file newgui_BM.c */
#include "bismon.h"

// the function to handle keypresses of cmd, for Return & Tab
static gboolean handlekeypress_newgui_cmd_BM (GtkWidget *, GdkEventKey *,
                                              gpointer);

// the function to handle "end-user-action" on commandbuf_BM
static void enduseraction_newgui_cmd_BM (GtkTextBuffer *, gpointer);
// the function to handle "populate-popup" on commandview_BM
static void populatepopup_newgui_cmd_BM (GtkTextView *, GtkWidget *,
                                         gpointer);

static void runcommand_newgui_BM (bool erase);
static void run_then_erase_newgui_command_BM (void);
static void run_then_keep_newgui_command_BM (void);

static void markset_newgui_cmd_BM (GtkTextBuffer *, GtkTextIter *,
                                   GtkTextMark *, gpointer);

static void parsecommandbuf_newgui_BM (struct parser_stBM *pars,
                                       struct stackframe_stBM *stkf);


GtkWidget *
initialize_newgui_command_scrollview_BM (void)
{
  commandbuf_BM = gtk_text_buffer_new (commandtagtable_BM);
  assert (GTK_IS_TEXT_BUFFER (commandbuf_BM));
  for (int depth = 0; depth < CMD_MAXNEST_BM; depth++)
    {
      char opennamebuf[24];
      snprintf (opennamebuf, sizeof (opennamebuf), "open%d_cmdtag", depth);
      open_cmdtags_BM[depth] =  //
        gtk_text_buffer_create_tag (commandbuf_BM, opennamebuf, NULL);
      char closenamebuf[24];
      snprintf (closenamebuf, sizeof (closenamebuf), "close%d_cmdtag", depth);
      close_cmdtags_BM[depth] = //
        gtk_text_buffer_create_tag (commandbuf_BM, closenamebuf, NULL);
      char xtranamebuf[24];
      snprintf (xtranamebuf, sizeof (xtranamebuf), "xtra%d_cmdtag", depth);
      xtra_cmdtags_BM[depth] =  //
        gtk_text_buffer_create_tag (commandbuf_BM, xtranamebuf, NULL);
    };
  commandview_BM = gtk_text_view_new_with_buffer (commandbuf_BM);
  gtk_widget_set_name (commandview_BM, "commandview");
  gtk_text_view_set_editable (GTK_TEXT_VIEW (commandview_BM), true);
  gtk_text_view_set_accepts_tab (GTK_TEXT_VIEW (commandview_BM), FALSE);
  g_signal_connect (commandview_BM, "key-press-event",
                    G_CALLBACK (handlekeypress_newgui_cmd_BM), NULL);
  g_signal_connect (commandbuf_BM, "end-user-action",
                    G_CALLBACK (enduseraction_newgui_cmd_BM), NULL);
  g_signal_connect (commandview_BM, "populate-popup",
                    G_CALLBACK (populatepopup_newgui_cmd_BM), NULL);
  g_signal_connect (commandbuf_BM, "mark-set",
                    G_CALLBACK (markset_newgui_cmd_BM), NULL);
  GtkWidget *commandscrolw = gtk_scrolled_window_new (NULL, NULL);
  gtk_container_add (GTK_CONTAINER (commandscrolw), commandview_BM);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (commandscrolw),
                                  GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  return commandscrolw;
}                               /* end initialize_newgui_command_scrollview_BM */


// for "key-press-event" signal to commandview_BM
gboolean
handlekeypress_newgui_cmd_BM (GtkWidget * widg, GdkEventKey * evk,
                              gpointer data)
{
  assert (GTK_IS_TEXT_VIEW (widg));
  assert (evk != NULL);
  assert (data == NULL);
  // see <gdk/gdkkeysyms.h> for names of keysyms
  if (evk->keyval == GDK_KEY_Return)
    {
      GdkModifierType modmask = gtk_accelerator_get_default_mod_mask ();
      bool withctrl = (evk->state & modmask) == GDK_CONTROL_MASK;
      bool withshift = (evk->state & modmask) == GDK_SHIFT_MASK;
      if (withctrl)
        {
          run_then_erase_newgui_command_BM ();
        }
      else if (withshift)
        {
          run_then_keep_newgui_command_BM ();
        }
      else                      // plain RETURN key, propagate it
        return false;
      return true;
    }
  else if (evk->keyval == GDK_KEY_Tab)
    {
      tabautocomplete_gui_cmd_BM ();
      return true;
    }
  else if (evk->keyval >= GDK_KEY_F1 && evk->keyval <= GDK_KEY_F10)
    {
      GdkModifierType modmask = gtk_accelerator_get_default_mod_mask ();
      bool withctrl = (evk->state & modmask) == GDK_CONTROL_MASK;
      bool withshift = (evk->state & modmask) == GDK_SHIFT_MASK;
      DBGPRINTF_BM ("handlekeypress_newgui_cmd_BM keyval %#x KEY_F%d %s%s",
                    evk->keyval, evk->keyval - (GDK_KEY_F1 - 1),
                    withctrl ? " ctrl" : "", withshift ? " shift" : "");
      return false;
    }
  return false;                 // propagate the event
}                               /* end handlekeypresscmd_BM */


void
populatepopup_newgui_cmd_BM (GtkTextView * txview, GtkWidget * popup,
                             gpointer data)
{
  assert (txview == GTK_TEXT_VIEW (commandview_BM));
  assert (GTK_IS_MENU (popup));
  assert (data == NULL);
  char cursinfobuf[32];
  memset (cursinfobuf, 0, sizeof (cursinfobuf));
  GtkTextIter cursit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_mark      //
    (commandbuf_BM, &cursit, gtk_text_buffer_get_insert (commandbuf_BM));
  snprintf (cursinfobuf, sizeof (cursinfobuf), "* L%dC%d/%d",
            gtk_text_iter_get_line (&cursit) + 1,
            gtk_text_iter_get_line_offset (&cursit),
            gtk_text_iter_get_offset (&cursit));
  gtk_menu_shell_append (GTK_MENU_SHELL (popup),
                         gtk_separator_menu_item_new ());
  {
    GtkWidget *cursinfomenit =  //
      gtk_menu_item_new_with_label (cursinfobuf);
    gtk_widget_set_sensitive (cursinfomenit, false);
    gtk_menu_shell_append (GTK_MENU_SHELL (popup), cursinfomenit);
  }
  gtk_menu_shell_prepend (GTK_MENU_SHELL (popup),
                          gtk_separator_menu_item_new ());
  {
    GtkWidget *clearmenit =     //
      gtk_menu_item_new_with_label ("clear command");
    gtk_menu_shell_prepend (GTK_MENU_SHELL (popup), clearmenit);
    g_signal_connect (clearmenit, "activate",
                      G_CALLBACK (clear_command_BM), NULL);
  }
  {
    GtkWidget *runerasemenit =  //
      gtk_menu_item_new_with_label ("run & erase");
    gtk_menu_shell_prepend (GTK_MENU_SHELL (popup), runerasemenit);
    g_signal_connect (runerasemenit, "activate",
                      G_CALLBACK (run_then_erase_newgui_command_BM), NULL);
  }
  {
    GtkWidget *runkeepmenit =   //
      gtk_menu_item_new_with_label ("run & keep");
    gtk_menu_shell_prepend (GTK_MENU_SHELL (popup), runkeepmenit);
    g_signal_connect (runkeepmenit, "activate",
                      G_CALLBACK (run_then_keep_newgui_command_BM), NULL);
  }
  gtk_widget_show_all (popup);
}                               /* end populatepopup_newgui_cmd_BM */



void
run_then_erase_newgui_command_BM (void)
{
  runcommand_newgui_BM (true);
}                               /* end run_then_erase_newgui_command_BM */

void
run_then_keep_newgui_command_BM (void)
{
  runcommand_newgui_BM (false);
}                               /* end run_then_keep_newgui_command_BM */

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
  //
  GtkWidget *commandscrolw = initialize_newgui_command_scrollview_BM ();
  GtkWidget *logscrolw = initialize_log_scrollview_BM ();
  gtk_paned_add1 (GTK_PANED (paned), commandscrolw);
  gtk_paned_add2 (GTK_PANED (paned), logscrolw);
  ///
#warning initialize_newgui_BM unimplemented
  fprintf (stderr, "initialize_newgui_BM builder %s css %s unimplemented\n",
           builderfile, cssfile);
  ///
  gtk_window_set_title (GTK_WINDOW (mainwin_BM), "new-bismon");
  gtk_window_set_default_size (GTK_WINDOW (mainwin_BM), 650, 720);
  // perhaps run the GC twice a second
  g_timeout_add (500, guiperiodicgarbagecollection_BM, NULL);
  gtk_widget_show_all (GTK_WIDGET (mainwin_BM));
}                               /* end initialize_newgui_BM */

GtkTextBuffer *
newgui_get_browsebuf_BM (void)
{
  fprintf (stderr, "newgui_get_browsebuf_BM unimplemented\n");
#warning newgui_get_browsebuf_BM unimplemented
  return NULL;
}                               /* end newgui_get_browsebuf_BM */


void
runcommand_newgui_BM (bool erase)
{
  DBGPRINTF_BM ("runcommand_newgui_BM start erase=%s", erase ? "yes" : "no");
  GtkTextIter startit = EMPTY_TEXT_ITER_BM;
  GtkTextIter endit = EMPTY_TEXT_ITER_BM;
  cmd_clear_parens_BM ();
  if (errormessagedialog_BM)
    {
      gtk_widget_destroy (errormessagedialog_BM), errormessagedialog_BM =
        NULL;
    };
  gtk_text_buffer_get_bounds (commandbuf_BM, &startit, &endit);
  gtk_text_buffer_remove_all_tags (commandbuf_BM, &startit, &endit);
  char *cmdstr = gtk_text_buffer_get_text (commandbuf_BM, &startit, &endit,
                                           false);
  bool gotffortab = false;
  for (char *pc = cmdstr; *pc; pc++)
    {
      if (*pc == '\t')
        {
          gotffortab = true;
          *pc = ' ';
        }
      else if (*pc == '\f')
        {
          gotffortab = true;
          *pc = '\n';
        };
    };
  if (gotffortab)
    {
      gtk_text_buffer_set_text (commandbuf_BM, cmdstr, -1);
    }
  struct parser_stBM *cmdpars = makeparser_memopen_BM (cmdstr, -1);
  int cmdlen = strlen (cmdstr);
  cmdpars->pars_ops = &parsop_command_build_BM;
  LOCALFRAME_BM ( /*prev: */ NULL, /*descr: */ NULL,
                 struct parser_stBM *cmdpars;);
  _.cmdpars = cmdpars;
  int errpars = setjmp (jmperrorcmd_BM);
  if (!errpars)
    {
      // should parse the command buffer, this could longjmp to jmperrorcmd_BM
      parsecommandbuf_newgui_BM (cmdpars, (struct stackframe_stBM *) &_);
      commandnumber_BM++;
      serial63_tyBM sercmd = randomserial63_BM ();
      char serbuf[16];
      memset (serbuf, 0, sizeof (serbuf));
      serial63tocbuf16_BM (sercmd, serbuf);
      if (gui_command_log_file_BM)
        {
          fprintf (gui_command_log_file_BM, "///++%s command #%d,l%d:\n",
                   serbuf, commandnumber_BM, cmdlen);
          fputs (cmdstr, gui_command_log_file_BM);
          if (cmdlen > 0 && cmdstr[cmdlen - 1] != '\n')
            putc ('\n', gui_command_log_file_BM);
          fprintf (gui_command_log_file_BM, "///--%s end command #%d\n\f\n",
                   serbuf, commandnumber_BM);
          fflush (gui_command_log_file_BM);
        }
      log_begin_message_BM ();
      log_printf_message_BM
        ("run %s command #%d successfully:\n",
         erase ? "erased" : "kept", commandnumber_BM);
      char commbuf[80];
      memset (commbuf, 0, sizeof (commbuf));
      snprintf (commbuf, sizeof (commbuf), "///++%s command #%d,l%d:",
                serbuf, commandnumber_BM, cmdlen);
      GtkTextIter it = EMPTY_TEXT_ITER_BM;
      gtk_text_buffer_get_end_iter (logbuf_BM, &it);
      gtk_text_buffer_insert_with_tags
        (logbuf_BM, &it, commbuf, -1, comment_logtag_BM, NULL);
      gtk_text_buffer_insert (logbuf_BM, &it, "\n", -1);
      gtk_text_buffer_insert_with_tags
        (logbuf_BM, &it, cmdstr, -1, command_logtag_BM, NULL);
      if (cmdlen > 0 && cmdstr[cmdlen - 1] != '\n')
        gtk_text_buffer_insert (logbuf_BM, &it, "\n", -1);
      snprintf (commbuf, sizeof (commbuf), "///--%s end command #%d",
                serbuf, commandnumber_BM);
      gtk_text_buffer_insert_with_tags
        (logbuf_BM, &it, commbuf, -1, comment_logtag_BM, NULL);
      gtk_text_buffer_insert (logbuf_BM, &it, "\n", -1);
      log_end_message_BM ();
    }
  else                          /* error */
    {
      // the errormessagedialog_BM was created in parserrorcmd_BM
      if (errormessagedialog_BM)
        {
          gtk_dialog_run (GTK_DIALOG (errormessagedialog_BM));
          gtk_widget_destroy (errormessagedialog_BM), errormessagedialog_BM =
            NULL;
        }
      free (cmdstr);
      return;
    }
  free (cmdstr);
  if (erase)
    gtk_text_buffer_set_text (commandbuf_BM, "", 0);
}                               /* end runcommand_newgui_BM */

void
markset_newgui_cmd_BM (GtkTextBuffer * tbuf, GtkTextIter * titer,
                       GtkTextMark * tmark, gpointer cdata)
{
}                               /* end markset_newgui_cmd_BM */

void
enduseraction_newgui_cmd_BM (GtkTextBuffer * txbuf, gpointer data)
{
  assert (txbuf == commandbuf_BM);
  assert (data == NULL);
  GtkTextIter startit = EMPTY_TEXT_ITER_BM;
  GtkTextIter endit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_bounds (commandbuf_BM, &startit, &endit);
  gtk_text_buffer_remove_all_tags (commandbuf_BM, &startit, &endit);
  cmd_clear_parens_BM ();
  char *cmdstr = gtk_text_buffer_get_text (commandbuf_BM, &startit, &endit,
                                           false);
  struct parser_stBM *cmdpars = makeparser_memopen_BM (cmdstr, -1);
  cmdpars->pars_ops = &parsop_command_nobuild_BM;
  LOCALFRAME_BM ( /*prev: */ NULL, /*descr: */ NULL,
                 struct parser_stBM *cmdpars;);
  _.cmdpars = cmdpars;
  int errpars = setjmp (jmperrorcmd_BM);
  if (!errpars)
    {
      // should parse the command buffer
      parsecommandbuf_newgui_BM (cmdpars, (struct stackframe_stBM *) &_);
    }
  else
    {
      // got an error while parsing
    }
  free (cmdstr);
  // for parenthesis blinking
  GtkTextMark *insmk = gtk_text_buffer_get_insert (commandbuf_BM);
  GtkTextIter insit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_mark (commandbuf_BM, &insit, insmk);
  markset_newgui_cmd_BM (commandbuf_BM, &insit, insmk, NULL);
}                               /* end enduseraction_newgui_cmd_BM */

void
parsecommandbuf_newgui_BM (struct parser_stBM *pars,
                           struct stackframe_stBM *stkf)
{
  if (!isparser_BM (pars))
    return;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 struct parser_stBM * pars;
                 value_tyBM comp; objectval_tyBM * obj;
                 objectval_tyBM * oldfocusobj; const stringval_tyBM * name;
                 const stringval_tyBM * result;
    );
  _.pars = pars;
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (!parsops || parsops->parsop_magic == PARSOPMAGIC_BM);
  bool nobuild = parsops && parsops->parsop_nobuild;
  int nbloop = 0;
  for (;;)
    {
      parserskipspaces_BM (pars);
      if (nbloop++ > MAXSIZE_BM / 32)
        parsererrorprintf_BM (pars, pars->pars_lineno,
                              pars->pars_colpos, "too many %d loops", nbloop);
      if (parserendoffile_BM (pars))
        break;
      unsigned curlineno = parserlineno_BM (pars);
      unsigned curcolpos = parsercolpos_BM (pars);
      parstoken_tyBM tok = parsertokenget_BM (pars);
      DBGPRINTF_BM ("parsecommandbuf_newgui_BM nbloop#%d tok~%s L%dC%d",
                    nbloop, lexkindname_BM (tok.tok_kind),
                    curlineno, curcolpos);
    }
}                               /* end parsecommandbuf_newgui_BM */
