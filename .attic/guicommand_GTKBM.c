// file guicommand_GTKBM.c
// SPDX-License-Identifier: GPL-3.0-or-later
/***
    BISMON 
    Copyright © 2018 - 2020 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch (working at CEA, LIST, France)
    <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
***/
#include "gtkbismon.h"
#include "guicommand_GTKBM.const.h"

void
commandblinkstop_BM (void)
{
  if (commandblinkid_BM > 0)
    g_source_remove (commandblinkid_BM), commandblinkid_BM = 0;
  commandblinkoff_BM (NULL);
}                               /* end commandblinkstop_BM */

int
commandblinkoff_BM (gpointer data __attribute__((unused)))
{
  GtkTextIter startit = EMPTY_TEXT_ITER_BM;
  GtkTextIter endit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_bounds (commandbuf_BM, &startit, &endit);
  gtk_text_buffer_remove_tag (commandbuf_BM, blink_cmdtag_GTKBM, &startit,
                              &endit);
  return G_SOURCE_REMOVE;
}                               /* end commandblinkoff_BM */

int
commandblinkon_BM (gpointer data __attribute__((unused)))
{
  if (commandblinkparens_BM.paroff_open > 0
      && commandblinkparens_BM.paroff_openlen > 0)
    {
      GtkTextIter openstartit = EMPTY_TEXT_ITER_BM, openendit =
        EMPTY_TEXT_ITER_BM;
      gtk_text_buffer_get_iter_at_offset (commandbuf_BM, &openstartit,
                                          commandblinkparens_BM.paroff_open);
      openendit = openstartit;
      gtk_text_iter_forward_chars (&openendit,
                                   commandblinkparens_BM.paroff_openlen);
      gtk_text_buffer_apply_tag (commandbuf_BM, blink_cmdtag_GTKBM, &openstartit,
                                 &openendit);
    }
  if (commandblinkparens_BM.paroff_close > 0
      && commandblinkparens_BM.paroff_closelen > 0)
    {
      GtkTextIter closestartit = EMPTY_TEXT_ITER_BM;
      GtkTextIter closeendit = EMPTY_TEXT_ITER_BM;
      gtk_text_buffer_get_iter_at_offset (commandbuf_BM, &closeendit,
                                          commandblinkparens_BM.paroff_close);
      closestartit = closeendit;
      gtk_text_iter_backward_chars (&closestartit,
                                    commandblinkparens_BM.paroff_closelen);
      gtk_text_buffer_apply_tag (commandbuf_BM, blink_cmdtag_GTKBM,
                                 &closestartit, &closeendit);
    }
  if (commandblinkparens_BM.paroff_xtra > 0
      && commandblinkparens_BM.paroff_xtralen > 0)
    {
      GtkTextIter xtrastartit = EMPTY_TEXT_ITER_BM, xtraendit =
        EMPTY_TEXT_ITER_BM;
      gtk_text_buffer_get_iter_at_offset (commandbuf_BM, &xtrastartit,
                                          commandblinkparens_BM.paroff_xtra);
      xtraendit = xtrastartit;
      gtk_text_iter_forward_chars (&xtraendit,
                                   commandblinkparens_BM.paroff_xtralen);
      gtk_text_buffer_apply_tag (commandbuf_BM, blink_cmdtag_GTKBM, &xtrastartit,
                                 &xtraendit);
    }
  if (commandblinkid_BM > 0)
    {
      (void) g_timeout_add (UNBLINKDELAYMILLISEC_GTKBM, commandblinkoff_BM,
                            NULL);
      return G_SOURCE_CONTINUE;
    }
  return G_SOURCE_REMOVE;
}                               /* end commandblinkon_BM */


void
commandblinkstart_BM (void)
{
  if (commandblinkid_BM > 0)
    g_source_remove (commandblinkid_BM), commandblinkid_BM = 0;
  commandblinkoff_BM (NULL);
  commandblinkid_BM =
    g_timeout_add (BLINKDELAYMILLISEC_BM, commandblinkon_BM, NULL);
  commandblinkon_BM (NULL);
}                               /* end commandblinkstart_BM */


////////////////

// for "key-press-event" signal to commandview_BM
gboolean
handlekeypresscmd_BM (GtkWidget * widg, GdkEventKey * evk, gpointer data)
{
  ASSERT_BM (GTK_IS_TEXT_VIEW (widg));
  ASSERT_BM (evk != NULL);
  ASSERT_BM (data == NULL);
  // see <gdk/gdkkeysyms.h> for names of keysyms
  if (evk->keyval == GDK_KEY_Return)
    {
      GdkModifierType modmask = gtk_accelerator_get_default_mod_mask ();
      bool withctrl = (evk->state & modmask) == GDK_CONTROL_MASK;
      bool withshift = (evk->state & modmask) == GDK_SHIFT_MASK;
      if (withctrl)
        run_then_erase_command_BM ();
      else if (withshift)
        run_then_keep_command_BM ();
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
      DBGPRINTF_BM ("handlekeypresscmd_BM keyval %#x KEY_F%d %s%s",
                    evk->keyval, evk->keyval - (GDK_KEY_F1 - 1),
                    withctrl ? " ctrl" : "", withshift ? " shift" : "");
      return false;
    }
  return false;                 // propagate the event
}                               /* end handlekeypresscmd_BM */


static gboolean
timeoutrestoreopacitycmd_BM (gpointer data __attribute__((unused)))
{
  gtk_widget_set_opacity (commandview_BM, 1.0);
  return false;
}                               /* end timeoutrestoreopacitycmd_BM  */

static void replacecompletionbyidcmd_BM (GtkMenuItem * mit, gpointer data);
static void replacecompletionbynamecmd_BM (GtkMenuItem * mit, gpointer data);
static void replacecompletionbyprefixcmd_BM (void);
static void stopcompletionmenucmd_BM (GtkMenuItem * mit, gpointer data);
static gboolean keyrelcompletionmenucmd_cbBM (GtkWidget * w, GdkEventKey * ev,
                                              gpointer data);



#define MAXFUNCTIONKEY_BM 12
void
tabautocomplete_gui_cmd_BM (void)
{
#warning tabautocomplete_gui_cmd_BM may have wrong behavior
  GtkTextIter cursit = EMPTY_TEXT_ITER_BM;
  GtkTextIter beglinit = EMPTY_TEXT_ITER_BM;
  GtkTextIter endlinit = EMPTY_TEXT_ITER_BM;
  complcommonprefix_BM = NULL;
  gtk_text_buffer_get_iter_at_mark      //
    (commandbuf_BM, &cursit, gtk_text_buffer_get_insert (commandbuf_BM));
  DBGPRINTF_BM ("tabautocompletecmd_BM cursit=%s",
                textiterstrdbg_BM (&cursit));
  unsigned col = gtk_text_iter_get_line_offset (&cursit);
  int lin = gtk_text_iter_get_line (&cursit) + 1;
  {
    beglinit = cursit;
    while (gtk_text_iter_get_line (&beglinit) + 1 == lin
           && !gtk_text_iter_starts_line (&beglinit)
           && !gtk_text_iter_is_start (&beglinit))
      {
        gtk_text_iter_backward_char (&beglinit);
      }
  }
  DBGPRINTF_BM ("tabautocompletecmd_BM beglinit=%s",
                textiterstrdbg_BM (&beglinit));
  {
    endlinit = cursit;
    while (gtk_text_iter_get_line (&endlinit) + 1 == lin
           && !gtk_text_iter_ends_line (&endlinit)
           && !gtk_text_iter_is_end (&endlinit))
      {
        gtk_text_iter_forward_char (&endlinit);
      }
  }
  DBGPRINTF_BM ("tabautocompletecmd_BM endlinit=%s",
                textiterstrdbg_BM (&endlinit));
  const char *curlin = gtk_text_buffer_get_text (commandbuf_BM, &beglinit,
                                                 &endlinit, false);
  DBGPRINTF_BM ("tabautocompletecmd_BM curlin='%s' L%dC%d", curlin, lin, col);
  ASSERT_BM (col <= g_utf8_strlen (curlin, -1));
  const char *curstr = g_utf8_offset_to_pointer (curlin, col);
  const char *begname = curstr;
  const char *endname = curstr;
  while (begname > curlin && (isalnum (begname[-1]) || begname[-1] == '_'))
    begname--;
  while (*endname && (isalnum (endname[0]) || endname[0] == '_'))
    endname++;
  char smallwordbuf[48];
  memset (smallwordbuf, 0, sizeof (smallwordbuf));
  if (endname > begname
      && (int) (endname - begname) < (int) sizeof (smallwordbuf))
    strncpy (smallwordbuf, begname, endname - begname);
  bool gotextralnums = false;
  if (begname > curlin)
    {
      char *pc = g_utf8_prev_char (begname);
      gunichar puc = g_utf8_get_char (pc);
      if (g_unichar_isalnum (puc))
        gotextralnums = true;
    };
  if (endname && *endname)
    {
      gunichar puc = g_utf8_get_char (endname);
      if (g_unichar_isalnum (puc))
        gotextralnums = true;
    }
  if (begname == endname || gotextralnums)
    goto failure;
  if (isdigit (begname[0]))
    goto failure;
  const setval_tyBM *complsetv = NULL;
  complbyid_BM = false;
  if (endname >= begname + 3 && begname[0] == '_'
      && isdigit (begname[1]) && isalnum (begname[2])
      && endname < begname + 31)
    {
      char widbuf[32];
      memset (widbuf, 0, sizeof (widbuf));
      memcpy (widbuf, begname, endname - begname);
      complbyid_BM = true;
      DBGPRINTF_BM ("tabautocompletecmd_BM widbuf=%s", widbuf);
      complsetv = setobjectsofidprefixed_BM (widbuf);
    }
  else if (endname > begname && isalpha (begname[0]))
    {
      char tinyprefix[40];
      memset (tinyprefix, 0, sizeof (tinyprefix));
      complbyid_BM = false;
      char *prefix = tinyprefix;
      if (endname < begname + sizeof (tinyprefix) - 1)
        strncpy (tinyprefix, begname, endname - begname);
      else
        {
          prefix = calloc (prime_above_BM (endname - begname + 2), 1);
          if (!prefix)
            FATAL_BM ("failed to calloc prefix");
          strncpy (prefix, begname, endname - begname);
        }
      DBGPRINTF_BM ("tabautocompletecmd_BM prefix=%s", prefix);
      complsetv = setofprefixednamedobjects_BM (prefix);
      if (prefix != tinyprefix)
        free (prefix);
    }
  else
    goto failure;
  unsigned nbcompl = setcardinal_BM (complsetv);
  DBGPRINTF_BM
    ("tabautocompletecmd nbcompl=%d endname@%p curstr@%p begname@%p: '%s' complbyid %s",
     nbcompl, endname, curstr, begname, begname,
     complbyid_BM ? "true" : "false");
  for (int cix = 0; cix < (int) nbcompl; cix++)
    {
      const objectval_tyBM *curobcomp = setelemnth_BM (complsetv, cix);
      if (complbyid_BM)
        {
          char cidbuf[32];
          memset (cidbuf, 0, sizeof (cidbuf));
          idtocbuf32_BM (objid_BM (curobcomp), cidbuf);
          DBGPRINTF_BM ("tabautocompletecmd cix#%d obid %s", cix, cidbuf);
        }
      else
        DBGPRINTF_BM ("tabautocompletecmd cix#%d obj %s",
                      cix, objectdbg_BM (curobcomp));
    }
  if (nbcompl == 0)
    goto failure;
  else if (nbcompl == 1)
    {
      // special case when complsetv is a singleton
      char cidbuf[32];
      memset (cidbuf, 0, sizeof (cidbuf));
      const char *complword = NULL;
      const objectval_tyBM *obcomp = setelemnth_BM (complsetv, 0);
      ASSERT_BM (isobject_BM ((const value_tyBM) obcomp));
      if (complbyid_BM)
        {
          idtocbuf32_BM (objid_BM (obcomp), cidbuf);
          complword = cidbuf;
        }
      else
        complword = findobjectname_BM (obcomp);
      ASSERT_BM (complword && complword[0]);
      GtkTextIter begwit = cursit;
      GtkTextIter endwit = cursit;
      gtk_text_iter_forward_chars (&endwit, endname - curstr);
      gtk_text_iter_backward_chars (&begwit, curstr - begname);
      gtk_text_buffer_delete (commandbuf_BM, &begwit, &endwit);
      gtk_text_buffer_insert (commandbuf_BM, &begwit, complword, -1);
      gtk_text_buffer_place_cursor (commandbuf_BM, &begwit);
    }
  else
    {
      ASSERT_BM (nbcompl > 1);
      complseqcmd_BM = complsetv;
      GtkWidget *complmenu = gtk_menu_new ();
      GtkTextIter begwit = cursit;
      GtkTextIter endwit = cursit;
      gtk_text_iter_forward_chars (&endwit, endname - curstr);
      gtk_text_iter_backward_chars (&begwit, curstr - begname);
      compbegoffcmd_BM = gtk_text_iter_get_offset (&begwit);
      compendoffcmd_BM = gtk_text_iter_get_offset (&endwit);
      unsigned gotwidth = endname - begname;
      if (complbyid_BM)
        {                       /* complete by id */
          for (unsigned ix = 0; ix < nbcompl; ix++)
            {
              char cidbuf[32];
              memset (cidbuf, 0, sizeof (cidbuf));
              char cidprefix[32];
              memset (cidprefix, 0, sizeof (cidprefix));
              const objectval_tyBM *obcomp = setelemnth_BM (complsetv, ix);
              ASSERT_BM (isobject_BM ((const value_tyBM) obcomp));
              idtocbuf32_BM (objid_BM (obcomp), cidbuf);
              unsigned idwidth =
                gotwidth < strlen (cidbuf) ? gotwidth : strlen (cidbuf);
              strncpy (cidprefix, cidbuf, idwidth);
              GtkWidget *mit = gtk_menu_item_new_with_label ("?");
              GtkWidget *mlab = gtk_bin_get_child (GTK_BIN (mit));
              char *markup = NULL;
              if (ix < MAXFUNCTIONKEY_BM)
                markup =
                  g_markup_printf_escaped
                  ("<tt><b>%s</b>%s</tt> <small><i>(F%d)</i></small>",
                   cidprefix, cidbuf + idwidth, ix + 1);
              else
                markup = g_markup_printf_escaped ("<tt><b>%s</b>%s</tt>",
                                                  cidprefix,
                                                  cidbuf + idwidth);
              gtk_label_set_markup (GTK_LABEL (mlab), markup);
              g_free (markup), markup = NULL;
              gtk_menu_shell_append (GTK_MENU_SHELL (complmenu), mit);
              g_signal_connect (mit, "activate",
                                G_CALLBACK (replacecompletionbyidcmd_BM),
                                (gpointer) (intptr_t) ix);
            }
          {
            const objectval_tyBM *firstobcomp = setelemnth_BM (complsetv, 0);
            const objectval_tyBM *lastobcomp =
              setelemnth_BM (complsetv, nbcompl - 1);
            char firstcidbuf[32], lastcidbuf[32], commoncidbuf[32];
            memset (firstcidbuf, 0, sizeof (firstcidbuf));
            memset (lastcidbuf, 0, sizeof (lastcidbuf));
            memset (commoncidbuf, 0, sizeof (commoncidbuf));
            ASSERT_BM (isobject_BM ((const value_tyBM) firstobcomp));
            idtocbuf32_BM (objid_BM (firstobcomp), firstcidbuf);
            ASSERT_BM (isobject_BM ((const value_tyBM) lastobcomp));
            idtocbuf32_BM (objid_BM (lastobcomp), lastcidbuf);
            for (int i = 0; i < (int) sizeof (commoncidbuf); i++)
              if (firstcidbuf[i] != lastcidbuf[i])
                break;
              else
                commoncidbuf[i] = firstcidbuf[i];
            if (strlen (commoncidbuf) > 3)
              {
                complcommonprefix_BM = strdup (commoncidbuf);
                DBGPRINTF_BM
                  ("tabautocompletecmd complcommonprefix_BM=%s byid",
                   complcommonprefix_BM);
              }
          }
        }
      else
        {                       /* complete by name */
          unsigned gotwidth = endname - begname;
          objectval_tyBM *tinyarr[TINYSIZE_BM] = {
          };
          objectval_tyBM **arr =
            (nbcompl <
             TINYSIZE_BM) ? tinyarr : calloc (prime_above_BM (nbcompl),
                                              sizeof (void *));
          if (!arr)
            FATAL_BM ("failed to calloc arr for %d completions (%m)",
                      nbcompl);
          for (unsigned ix = 0; ix < nbcompl; ix++)
            arr[ix] = setelemnth_BM (complsetv, ix);
          sortnamedobjarr_BM (arr, nbcompl);
          complseqcmd_BM = maketuple_BM (arr, nbcompl);
          for (unsigned obix = 0; obix < nbcompl; obix++)
            {
              const objectval_tyBM *curob = arr[obix];
              ASSERT_BM (isobject_BM ((const value_tyBM) curob));
              const char *obname = findobjectname_BM (curob);
              ASSERT_BM (obname != NULL);
              unsigned obnamelen = strlen (obname);
              ASSERT_BM (obnamelen > 0);
              char *obprefix = calloc (1 + ((obnamelen + 1) | 7), 1);
              if (!obprefix)
                FATAL_BM ("failed to calloc obprefix (obnamelen=%u)",
                          obnamelen);
              unsigned prefwidth = gotwidth;
              if (prefwidth > obnamelen)
                prefwidth = obnamelen;
              strncpy (obprefix, obname, prefwidth);
              GtkWidget *mit = gtk_menu_item_new_with_label ("!");
              GtkWidget *mlab = gtk_bin_get_child (GTK_BIN (mit));
              char *markup = NULL;
              if (obix < MAXFUNCTIONKEY_BM)
                markup =
                  g_markup_printf_escaped
                  ("<b>%s</b>%s <small><i>(F%d)</i></small>", obprefix,
                   obname + prefwidth, obix + 1);
              else
                markup = g_markup_printf_escaped ("<b>%s</b>%s",
                                                  obprefix,
                                                  obname + prefwidth);
              gtk_label_set_markup (GTK_LABEL (mlab), markup);
              g_free (markup), markup = NULL;
              gtk_menu_shell_append (GTK_MENU_SHELL (complmenu), mit);
              g_signal_connect (mit, "activate",
                                G_CALLBACK (replacecompletionbynamecmd_BM),
                                (gpointer) (intptr_t) obix);
            }
          const objectval_tyBM *firstnamedob = arr[0];
          const objectval_tyBM *lastnamedob = arr[nbcompl - 1];
          const char *firstobname = findobjectname_BM (firstnamedob);
          const char *lastobname = findobjectname_BM (lastnamedob);
          DBGPRINTF_BM
            ("tabautocompletecmd firstobname=%s lastobname=%s nbcompl=%d",
             firstobname, lastobname, nbcompl);
          int comlen = 0;
          for (int ix = 0; firstobname[ix] && lastobname[ix]; ix++)
            if (firstobname[ix] != lastobname[ix])
              {
                comlen = ix;
                break;
              };
          if (comlen > 3)
            {
              complcommonprefix_BM = strndup (firstobname, comlen);
              DBGPRINTF_BM
                ("tabautocompletecmd complcommonprefix_BM=%s byname",
                 complcommonprefix_BM);
            };
          if (arr != tinyarr)
            free (arr), arr = NULL;
        }
      gulong cancelhdlid = g_signal_connect (complmenu, "cancel",
                                             G_CALLBACK
                                             (stopcompletionmenucmd_BM),
                                             "*Cancelled*");
      gulong deacthdlid = g_signal_connect (complmenu, "deactivate",
                                            G_CALLBACK
                                            (stopcompletionmenucmd_BM),
                                            "*Deactivated*");
      g_signal_connect (complmenu, "key-release-event",
                        G_CALLBACK (keyrelcompletionmenucmd_cbBM), NULL);
      gtk_widget_show_all (complmenu);
      gtk_menu_popup_at_pointer (GTK_MENU (complmenu), NULL);
      DBGPRINTF_BM ("tabautocompletecmd before gtk_main");
      gtk_main ();
      DBGPRINTF_BM ("tabautocompletecmd after gtk_main");
      g_signal_handler_disconnect (complmenu, cancelhdlid);
      g_signal_handler_disconnect (complmenu, deacthdlid);
      gtk_widget_destroy (complmenu);
      complseqcmd_BM = NULL;
      compbegoffcmd_BM = -1;
      compendoffcmd_BM = -1;
      free (complcommonprefix_BM), complcommonprefix_BM = NULL;
    }
  free ((char *) curlin);
  DBGPRINTF_BM ("tabautocompletecmd end");
  return;
failure:
  DBGPRINTF_BM ("tabautocompletecmd failure");
  // fail completion by beeping and blinking the commandview_BM
  {
    GdkWindow *dwin = gtk_widget_get_parent_window (commandview_BM);
    if (dwin)
      gdk_window_beep (dwin);
    gtk_widget_set_opacity (commandview_BM, 0.5);
    // delay the restore of 1.0 opacity
    g_timeout_add (125 /*milliseconds */ ,
                   timeoutrestoreopacitycmd_BM, NULL);
  }
  free ((char *) curlin);
  return;
}                               /* end tabautocompletecmd_BM */


void
replacecompletionbyidcmd_BM (GtkMenuItem * mit
                             __attribute__((unused)), gpointer data)
{
  unsigned ix = (unsigned) (intptr_t) data;
  ASSERT_BM (issequence_BM ((const value_tyBM) complseqcmd_BM));
  ASSERT_BM (ix < sequencesize_BM (complseqcmd_BM));
  const objectval_tyBM *ob = sequencenthcomp_BM (complseqcmd_BM, ix);
  ASSERT_BM (isobject_BM ((const value_tyBM) ob));
  char idbuf[32];
  memset (idbuf, 0, sizeof (idbuf));
  idtocbuf32_BM (objid_BM (ob), idbuf);
  GtkTextIter begwit = EMPTY_TEXT_ITER_BM;
  GtkTextIter endwit = EMPTY_TEXT_ITER_BM;
  DBGPRINTF_BM ("replacecompletionbyidcmd_BM ix#%d idbuf=%s", ix, idbuf);
  gtk_text_buffer_get_iter_at_offset (commandbuf_BM, &begwit,
                                      compbegoffcmd_BM);
  gtk_text_buffer_get_iter_at_offset (commandbuf_BM, &endwit,
                                      compendoffcmd_BM);
  gtk_text_buffer_delete (commandbuf_BM, &begwit, &endwit);
  gtk_text_buffer_insert (commandbuf_BM, &begwit, idbuf, -1);
  gtk_text_buffer_place_cursor (commandbuf_BM, &begwit);
  gtk_main_quit ();
}                               /* end replacecompletionbyidcmd_BM */

void
replacecompletionbynamecmd_BM (GtkMenuItem * mit
                               __attribute__((unused)), gpointer data)
{
  unsigned ix = (unsigned) (intptr_t) data;
  ASSERT_BM (issequence_BM ((const value_tyBM) complseqcmd_BM));
  ASSERT_BM (ix < sequencesize_BM (complseqcmd_BM));
  const objectval_tyBM *ob = sequencenthcomp_BM (complseqcmd_BM, ix);
  ASSERT_BM (isobject_BM ((const value_tyBM) ob));
  const char *obname = findobjectname_BM (ob);
  ASSERT_BM (obname != NULL);
  DBGPRINTF_BM ("replacecompletionbynamecmd_BM ix#%d obname=%s", ix, obname);
  GtkTextIter begwit = EMPTY_TEXT_ITER_BM;
  GtkTextIter endwit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_offset (commandbuf_BM, &begwit,
                                      compbegoffcmd_BM);
  gtk_text_buffer_get_iter_at_offset (commandbuf_BM, &endwit,
                                      compendoffcmd_BM);
  gtk_text_buffer_delete (commandbuf_BM, &begwit, &endwit);
  gtk_text_buffer_insert (commandbuf_BM, &begwit, obname, -1);
  gtk_text_buffer_place_cursor (commandbuf_BM, &begwit);
  gtk_main_quit ();
}                               /* end replacecompletionbynamecmd_BM */

void
replacecompletionbyprefixcmd_BM (void)
{
  DBGPRINTF_BM ("replacecompletionbyprefixcmd_BM complcommonprefix=%s",
                complcommonprefix_BM);
  GtkTextIter begwit = EMPTY_TEXT_ITER_BM;
  GtkTextIter endwit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_offset (commandbuf_BM, &begwit,
                                      compbegoffcmd_BM);
  gtk_text_buffer_get_iter_at_offset (commandbuf_BM, &endwit,
                                      compendoffcmd_BM);
  gtk_text_buffer_delete (commandbuf_BM, &begwit, &endwit);
  gtk_text_buffer_insert (commandbuf_BM, &begwit, complcommonprefix_BM, -1);
  gtk_text_buffer_place_cursor (commandbuf_BM, &begwit);
  gtk_main_quit ();
}                               /* end replacecompletionbyprefixcmd_BM */


void
stopcompletionmenucmd_BM (GtkMenuItem * mit
                          __attribute__((unused)),
                          gpointer data __attribute__((unused)))
{
  ASSERT_BM (issequence_BM ((const value_tyBM) complseqcmd_BM));
  if (complcommonprefix_BM)
    {
      DBGPRINTF_BM
        ("stopcompletionmenucmd_BM complcommonprefix_BM=%s compbegoffcmd_BM=%d compendoffcmd_BM=%d",
         complcommonprefix_BM, compbegoffcmd_BM, compendoffcmd_BM);
      GtkTextIter begwit = EMPTY_TEXT_ITER_BM;
      GtkTextIter endwit = EMPTY_TEXT_ITER_BM;
      gtk_text_buffer_get_iter_at_offset (commandbuf_BM, &begwit,
                                          compbegoffcmd_BM);
      gtk_text_buffer_get_iter_at_offset (commandbuf_BM, &endwit,
                                          compendoffcmd_BM);
      gtk_text_buffer_delete (commandbuf_BM, &begwit, &endwit);
      gtk_text_buffer_insert (commandbuf_BM, &begwit, complcommonprefix_BM,
                              -1);
      gtk_text_buffer_place_cursor (commandbuf_BM, &begwit);
    }
  else
    DBGPRINTF_BM ("stopcompletionmenucmd without complcommonprefix_BM");
  gtk_main_quit ();
}                               /* end stopcompletionmenucmd_BM */

gboolean
keyrelcompletionmenucmd_cbBM (GtkWidget * w, GdkEventKey * evk, gpointer data)
{
  ASSERT_BM (GTK_IS_MENU (w));
  ASSERT_BM (evk != NULL);
  ASSERT_BM (data == 0);
  GdkModifierType modmask = gtk_accelerator_get_default_mod_mask ();
  bool withctrl = (evk->state & modmask) == GDK_CONTROL_MASK;
  bool withshift = (evk->state & modmask) == GDK_SHIFT_MASK;
  char keybuf[32];
  memset (keybuf, 0, sizeof (keybuf));
  if (evk->keyval >= GDK_KEY_0 && evk->keyval <= GDK_KEY_9)
    snprintf (keybuf, sizeof (keybuf), "KEY_%d", evk->keyval - GDK_KEY_0);
  else if (evk->keyval >= GDK_KEY_KP_0 && evk->keyval <= GDK_KEY_KP_9)
    snprintf (keybuf, sizeof (keybuf), "KEY_KP_%d",
              evk->keyval - GDK_KEY_KP_0);
  else if (evk->keyval >= GDK_KEY_F1 && evk->keyval <= GDK_KEY_F35)
    snprintf (keybuf, sizeof (keybuf), "KEY_F%d",
              1 + (evk->keyval - GDK_KEY_F1));
  else if (evk->keyval >= GDK_KEY_A && evk->keyval <= GDK_KEY_Z)
    snprintf (keybuf, sizeof (keybuf), "KEY_%c (up)",
              'A' + (evk->keyval - GDK_KEY_A));
  else if (evk->keyval >= GDK_KEY_a && evk->keyval <= GDK_KEY_z)
    snprintf (keybuf, sizeof (keybuf), "KEY_%c (lo)",
              'a' + (evk->keyval - GDK_KEY_a));
  else if (evk->keyval == GDK_KEY_Tab)
    strcpy (keybuf, "KEY_Tab");
  else if (evk->keyval == GDK_KEY_Multi_key)
    strcpy (keybuf, "KEY_Multi_key");
  else if (evk->keyval == GDK_KEY_space)
    strcpy (keybuf, "KEY_space");
  else
    snprintf (keybuf, sizeof (keybuf), "key %d", evk->keyval);
  DBGPRINTF_BM ("keyrelcompletionmenucmd keyval %#x %s ctrl %s shift %s",
                evk->keyval, keybuf, withctrl ? "yes" : "no",
                withshift ? "yes" : "no");
  if (evk->keyval >= GDK_KEY_F1 && evk->keyval <= GDK_KEY_F12)
    {
      int keyix = evk->keyval - GDK_KEY_F1;
      if (complbyid_BM)
        replacecompletionbyidcmd_BM (NULL, (gpointer) keyix);
      else
        replacecompletionbynamecmd_BM (NULL, (gpointer) keyix);
      return TRUE;              // don't propagate the event
    }
  else if (evk->keyval == GDK_KEY_space)
    {
      replacecompletionbyprefixcmd_BM ();
      return TRUE;              // don't propagate the event
    }
  return FALSE;                 /* propagate the event */
}                               /* end keyrelcompletionmenucmd_cbBM */



////////////////

/// called by run_then_keep_command_BM & run_then_erase_command_BM
void
runcommand_BM (bool erase)
{
  GtkTextIter startit = EMPTY_TEXT_ITER_BM;
  GtkTextIter endit = EMPTY_TEXT_ITER_BM;
  DBGPRINTF_BM ("runcommand %s start elapsed %.3f s",
                erase ? "erase" : "keep", elapsedtime_BM ());
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
  LOCALFRAME_BM ( /*prev: */ NULL, /*descr: */ NULL,
                 objectval_tyBM * parsownob;);
  _.parsownob = makeobj_BM ();
  struct parser_stBM *cmdpars =
    makeparser_memopen_BM (cmdstr, -1, _.parsownob);
  cmdpars->pars_debug = true;
  int cmdlen = strlen (cmdstr);
  DBGPRINTF_BM
    ("runcommand %s start elapsed %.3f s, cmdlen %d cmdstr@%p:\n%s\n***\n",
     erase ? "erase" : "keep", elapsedtime_BM (), cmdlen, cmdstr, cmdstr);
  cmdpars->pars_ops = &parsop_command_build_BM;
  int errpars = setjmp (jmperrorcmd_BM);
  if (!errpars)
    {
      // should parse the command buffer, this could longjmp to jmperrorcmd_BM
      parsecommandbuf_BM (cmdpars, CURFRAME_BM);
      commandnumber_BM++;
      DBGPRINTF_BM ("runcommand %s *** parsed command#%d elapsed %.3f s\n",
                    erase ? "erase" : "keep", commandnumber_BM,
                    elapsedtime_BM ());
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
        (logbuf_BM, &it, commbuf, -1, comment_logtag_GTKBM, NULL);
      gtk_text_buffer_insert (logbuf_BM, &it, "\n", -1);
      gtk_text_buffer_insert_with_tags
        (logbuf_BM, &it, cmdstr, -1, command_logtag_GTKBM, NULL);
      if (cmdlen > 0 && cmdstr[cmdlen - 1] != '\n')
        gtk_text_buffer_insert (logbuf_BM, &it, "\n", -1);
      snprintf (commbuf, sizeof (commbuf), "///--%s end command #%d",
                serbuf, commandnumber_BM);
      gtk_text_buffer_insert_with_tags
        (logbuf_BM, &it, commbuf, -1, comment_logtag_GTKBM, NULL);
      gtk_text_buffer_insert (logbuf_BM, &it, "\n", -1);
      log_end_message_BM ();
    }
  else                          /* error */
    {
      DBGPRINTF_BM ("runcommand errored elapsed %.3f s", elapsedtime_BM ());
      // the errormessagedialog_BM was created in parserror_guicmd_BM
      if (errormessagedialog_BM)
        {
          gtk_dialog_run (GTK_DIALOG (errormessagedialog_BM));
          gtk_widget_destroy (errormessagedialog_BM),
            errormessagedialog_BM = NULL;
        }
      free (cmdstr);
      return;
    }
  free (cmdstr);
  if (erase)
    gtk_text_buffer_set_text (commandbuf_BM, "", 0);
  DBGPRINTF_BM ("runcommand %s end elapsed %.3f s", erase ? "erase" : "keep",
                elapsedtime_BM ());
}                               /* end runcommand_BM */


void
enduseractioncmd_BM (GtkTextBuffer * txbuf, gpointer data)
{
  ASSERT_BM (txbuf == commandbuf_BM);
  ASSERT_BM (data == NULL);
  GtkTextIter startit = EMPTY_TEXT_ITER_BM;
  GtkTextIter endit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_bounds (commandbuf_BM, &startit, &endit);
  gtk_text_buffer_remove_all_tags (commandbuf_BM, &startit, &endit);
  cmd_clear_parens_BM ();
  char *cmdstr = gtk_text_buffer_get_text (commandbuf_BM, &startit, &endit,
                                           false);
  LOCALFRAME_BM ( /*prev: */ NULL, /*descr: */ NULL,
                 objectval_tyBM * parsownob);
  _.parsownob = makeobj_BM ();
  struct parser_stBM *cmdpars =
    makeparser_memopen_BM (cmdstr, -1, _.parsownob);
  cmdpars->pars_ops = &parsop_command_nobuild_BM;
  int errpars = setjmp (jmperrorcmd_BM);
  if (!errpars)
    {
      // should parse the command buffer
      parsecommandbuf_BM (cmdpars, CURFRAME_BM);
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
  marksetcmd_BM (commandbuf_BM, &insit, insmk, NULL);
}                               /* end enduseractioncmd_BM */


void
populatepopupbrow_BM (GtkTextView * txview, GtkWidget * popup, gpointer data)
{
  ASSERT_BM (txview == GTK_TEXT_VIEW (browserview_BM));
  ASSERT_BM (GTK_IS_MENU (popup));
  ASSERT_BM (data == NULL);
  char cursinfobuf[32];
  memset (cursinfobuf, 0, sizeof (cursinfobuf));
  GtkTextIter cursit = EMPTY_TEXT_ITER_BM;
  if (!browserbuf_BM)
    {
      browserbuf_BM = newgui_get_browsebuf_BM ();
      if (!browserbuf_BM)
        return;
    };
  gtk_text_buffer_get_iter_at_mark      //
    (browserbuf_BM, &cursit, gtk_text_buffer_get_insert (browserbuf_BM));
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
  {
    GtkWidget *refreshmenuit = gtk_menu_item_new_with_label ("refresh");
    gtk_menu_shell_append (GTK_MENU_SHELL (popup), refreshmenuit);
    g_signal_connect (refreshmenuit, "activate",
                      G_CALLBACK (refresh_browse_BM), NULL);
  }
  gtk_widget_show_all (popup);
}                               /* end populatepopupbrow_BM */


void
populatepopupcmd_BM (GtkTextView * txview, GtkWidget * popup, gpointer data)
{
  ASSERT_BM (txview == GTK_TEXT_VIEW (commandview_BM));
  ASSERT_BM (GTK_IS_MENU (popup));
  ASSERT_BM (data == NULL);
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
                      G_CALLBACK (run_then_erase_command_BM), NULL);
  }
  {
    GtkWidget *runkeepmenit =   //
      gtk_menu_item_new_with_label ("run & keep");
    gtk_menu_shell_prepend (GTK_MENU_SHELL (popup), runkeepmenit);
    g_signal_connect (runkeepmenit, "activate",
                      G_CALLBACK (run_then_keep_command_BM), NULL);
  }
  gtk_widget_show_all (popup);
}                               /* end populatepopupcmd_BM */


static void clearlog_BM (void);
void
populatepopuplog_BM (GtkTextView * txview, GtkWidget * popup, gpointer data)
{
  ASSERT_BM (txview == GTK_TEXT_VIEW (logview_BM));
  ASSERT_BM (GTK_IS_MENU (popup));
  ASSERT_BM (data == NULL);
  gtk_menu_shell_append (GTK_MENU_SHELL (popup),
                         gtk_separator_menu_item_new ());
  GtkWidget *clearlogmenit = gtk_menu_item_new_with_label ("clear log");
  gtk_menu_shell_append (GTK_MENU_SHELL (popup), clearlogmenit);
  g_signal_connect (clearlogmenit, "activate", G_CALLBACK (clearlog_BM),
                    NULL);
  gtk_widget_show_all (popup);
}                               /* end populatepopuplog_BM */

void
clearlog_BM (void)
{
  GtkTextIter startit = EMPTY_TEXT_ITER_BM;
  GtkTextIter endit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_bounds (logbuf_BM, &startit, &endit);
  gtk_text_buffer_delete (logbuf_BM, &startit, &endit);
  log_begin_message_BM ();
  log_puts_message_BM ("log cleared");
  log_end_message_BM ();
}                               /* end clearlog_BM */


void
cssparsingerror_BM (GtkCssProvider * prov __attribute__((unused)),
                    GtkCssSection * section, GError * err,
                    gpointer data __attribute__((unused)))
{
  GFile *sfil = gtk_css_section_get_file (section);
  FATAL_BM ("CSS parsing error: %s [L%dC%d-L%dC%d] (%s#%d) %s",
            sfil ? g_file_get_path (sfil) : "*none*",
            gtk_css_section_get_start_line (section) + 1,
            gtk_css_section_get_start_position (section),
            gtk_css_section_get_end_line (section) + 1,
            gtk_css_section_get_end_position (section),
            g_quark_to_string (err->domain), err->code, err->message);
}                               /* end cssparsingerror_BM */

////////////////////////////////////////////////////////////////

void
initialize_gui_tags_BM (GtkBuilder * bld)
{
  browsertagtable_BM =          //
    GTK_TEXT_TAG_TABLE (gtk_builder_get_object (bld, "browsertagtable_id"));
  commandtagtable_BM =          //
    GTK_TEXT_TAG_TABLE (gtk_builder_get_object (bld, "commandtagtable_id"));
  logtagtable_BM =              //
    GTK_TEXT_TAG_TABLE (gtk_builder_get_object (bld, "logtagtable_id"));
  ////////////////
  pagetitle_brotag_GTKBM =         //
    gtk_text_tag_table_lookup (browsertagtable_BM, "pagetitle_brotag");
  if (!pagetitle_brotag_GTKBM)
    FATAL_BM ("cannot find pagetitle_brotag_GTKBM");
  objtitle_brotag_GTKBM =          //
    gtk_text_tag_table_lookup (browsertagtable_BM, "objtitle_brotag");
  if (!objtitle_brotag_GTKBM)
    FATAL_BM ("cannot find objtitle_brotag_GTKBM");
  valtitle_brotag_GTKBM =          //
    gtk_text_tag_table_lookup (browsertagtable_BM, "valtitle_brotag");
  if (!valtitle_brotag_GTKBM)
    FATAL_BM ("cannot find valtitle_brotag_GTKBM");
  focustitle_brotag_GTKBM =        //
    gtk_text_tag_table_lookup (browsertagtable_BM, "focustitle_brotag");
  if (!focustitle_brotag_GTKBM)
    FATAL_BM ("cannot find focustitle_brotag_GTKBM");
  objcommtitle_brotag_GTKBM =      //
    gtk_text_tag_table_lookup (browsertagtable_BM, "objcommtitle_brotag");
  if (!objcommtitle_brotag_GTKBM)
    FATAL_BM ("cannot find objcommtitle_brotag_GTKBM");
  objnametitle_brotag_GTKBM =      //
    gtk_text_tag_table_lookup (browsertagtable_BM, "objnametitle_brotag");
  if (!objnametitle_brotag_GTKBM)
    FATAL_BM ("cannot find objnametitle_brotag_GTKBM");
  objidtitle_brotag_GTKBM =        //
    gtk_text_tag_table_lookup (browsertagtable_BM, "objidtitle_brotag");
  if (!objidtitle_brotag_GTKBM)
    FATAL_BM ("cannot find objidtitle_brotag_GTKBM");
  objid_brotag_GTKBM =             //
    gtk_text_tag_table_lookup (browsertagtable_BM, "objid_brotag");
  if (!objid_brotag_GTKBM)
    FATAL_BM ("cannot find objid_brotag_GTKBM");
  objname_brotag_GTKBM =           //
    gtk_text_tag_table_lookup (browsertagtable_BM, "objname_brotag");
  if (!objname_brotag_GTKBM)
    FATAL_BM ("cannot find objname_brotag_GTKBM");
  objrefcomm_brotag_GTKBM =        //
    gtk_text_tag_table_lookup (browsertagtable_BM, "objrefcomm_brotag");
  if (!objrefcomm_brotag_GTKBM)
    FATAL_BM ("cannot find objrefcomm_brotag_GTKBM");
  nest_brotag_GTKBM =              //
    gtk_text_tag_table_lookup (browsertagtable_BM, "nest_brotag");
  if (!nest_brotag_GTKBM)
    FATAL_BM ("cannot find nest_brotag_GTKBM");
  blink_brotag_GTKBM =             //
    gtk_text_tag_table_lookup (browsertagtable_BM, "blink_brotag");
  if (!blink_brotag_GTKBM)
    FATAL_BM ("cannot find blink_brotag_GTKBM");
  num_brotag_GTKBM =               //
    gtk_text_tag_table_lookup (browsertagtable_BM, "num_brotag");
  if (!num_brotag_GTKBM)
    FATAL_BM ("cannot find num_brotag_GTKBM");
  toodeep_brotag_GTKBM =           //
    gtk_text_tag_table_lookup (browsertagtable_BM, "toodeep_brotag");
  if (!toodeep_brotag_GTKBM)
    FATAL_BM ("cannot find toodeep_brotag_GTKBM");
  str_brotag_GTKBM =               //
    gtk_text_tag_table_lookup (browsertagtable_BM, "str_brotag");
  if (!str_brotag_GTKBM)
    FATAL_BM ("cannot find str_brotag_GTKBM");
  stresc_brotag_GTKBM =            //
    gtk_text_tag_table_lookup (browsertagtable_BM, "stresc_brotag");
  if (!stresc_brotag_GTKBM)
    FATAL_BM ("cannot find stresc_brotag_GTKBM");
  miscomm_brotag_GTKBM =           //
    gtk_text_tag_table_lookup (browsertagtable_BM, "miscomm_brotag");
  if (!miscomm_brotag_GTKBM)
    FATAL_BM ("cannot find miscomm_brotag_GTKBM");
  epilogue_brotag_GTKBM =          //
    gtk_text_tag_table_lookup (browsertagtable_BM, "epilogue_brotag");
  if (!epilogue_brotag_GTKBM)
    FATAL_BM ("cannot find epilogue_brotag_GTKBM");
  ////////////////
  errored_cmdtag_GTKBM =           //
    gtk_text_tag_table_lookup (commandtagtable_BM, "errored_cmdtag");
  if (!errored_cmdtag_GTKBM)
    FATAL_BM ("cannot find errored_cmdtag");
  skipped_cmdtag_GTKBM =           //
    gtk_text_tag_table_lookup (commandtagtable_BM, "skipped_cmdtag");
  if (!skipped_cmdtag_GTKBM)
    FATAL_BM ("cannot find skipped_cmdtag");
  commentinside_cmdtag_GTKBM =     //
    gtk_text_tag_table_lookup (commandtagtable_BM, "commentinside_cmdtag");
  if (!commentinside_cmdtag_GTKBM)
    FATAL_BM ("cannot find commentinside_cmdtag");
  commentsign_cmdtag_GTKBM =       //
    gtk_text_tag_table_lookup (commandtagtable_BM, "commentsign_cmdtag");
  if (!commentsign_cmdtag_GTKBM)
    FATAL_BM ("cannot find commentsign_cmdtag");
  delim_cmdtag_GTKBM =             //
    gtk_text_tag_table_lookup (commandtagtable_BM, "delim_cmdtag");
  if (!delim_cmdtag_GTKBM)
    FATAL_BM ("cannot find delim_cmdtag");
  knowname_cmdtag_GTKBM =          //
    gtk_text_tag_table_lookup (commandtagtable_BM, "knowname_cmdtag");
  if (!knowname_cmdtag_GTKBM)
    FATAL_BM ("cannot find knowname_cmdtag");
  newname_cmdtag_GTKBM =           //
    gtk_text_tag_table_lookup (commandtagtable_BM, "newname_cmdtag");
  if (!newname_cmdtag_GTKBM)
    FATAL_BM ("cannot find newname_cmdtag");
  //
  id_cmdtag_GTKBM =                //
    gtk_text_tag_table_lookup (commandtagtable_BM, "id_cmdtag");
  if (!id_cmdtag_GTKBM)
    FATAL_BM ("cannot find id_cmdtag");
  //
  number_cmdtag_GTKBM =            //
    gtk_text_tag_table_lookup (commandtagtable_BM, "number_cmdtag");
  if (!number_cmdtag_GTKBM)
    FATAL_BM ("cannot find number_cmdtag");
  //
  stringsign_cmdtag_GTKBM =        //
    gtk_text_tag_table_lookup (commandtagtable_BM, "stringsign_cmdtag");
  if (!stringsign_cmdtag_GTKBM)
    FATAL_BM ("cannot find stringsign_cmdtag");
  //
  stringinside_cmdtag_GTKBM =      //
    gtk_text_tag_table_lookup (commandtagtable_BM, "stringinside_cmdtag");
  if (!stringinside_cmdtag_GTKBM)
    FATAL_BM ("cannot find stringinside_cmdtag");
  //
  dollar_cmdtag_GTKBM =            //
    gtk_text_tag_table_lookup (commandtagtable_BM, "dollar_cmdtag");
  if (!dollar_cmdtag_GTKBM)
    FATAL_BM ("cannot find dollar_cmdtag");
  nesting_cmdtag_GTKBM =           //
    gtk_text_tag_table_lookup (commandtagtable_BM, "nesting_cmdtag");
  if (!nesting_cmdtag_GTKBM)
    FATAL_BM ("cannot find nesting_cmdtag");
  blink_cmdtag_GTKBM =             //
    gtk_text_tag_table_lookup (commandtagtable_BM, "blink_cmdtag");
  if (!blink_cmdtag_GTKBM)
    FATAL_BM ("cannot find blink_cmdtag");
  ////////////////
  code_logtag_GTKBM =              //
    gtk_text_tag_table_lookup (logtagtable_BM, "code_logtag");
  if (!code_logtag_GTKBM)
    FATAL_BM ("cannot find code_logtag");
  error_logtag_GTKBM =             //
    gtk_text_tag_table_lookup (logtagtable_BM, "error_logtag");
  if (!error_logtag_GTKBM)
    FATAL_BM ("cannot find error_logtag");
  time_logtag_GTKBM =              //
    gtk_text_tag_table_lookup (logtagtable_BM, "time_logtag");
  if (!time_logtag_GTKBM)
    FATAL_BM ("cannot find time_logtag");
  id_logtag_GTKBM =                //
    gtk_text_tag_table_lookup (logtagtable_BM, "id_logtag");
  if (!id_logtag_GTKBM)
    FATAL_BM ("cannot find id_logtag");
  name_logtag_GTKBM =              //
    gtk_text_tag_table_lookup (logtagtable_BM, "name_logtag");
  if (!name_logtag_GTKBM)
    FATAL_BM ("cannot find name_logtag");
  comment_logtag_GTKBM =           //
    gtk_text_tag_table_lookup (logtagtable_BM, "comment_logtag");
  if (!comment_logtag_GTKBM)
    FATAL_BM ("cannot find comment_logtag");
  command_logtag_GTKBM =           //
    gtk_text_tag_table_lookup (logtagtable_BM, "command_logtag");
  if (!command_logtag_GTKBM)
    FATAL_BM ("cannot find command_logtag");
}                               /* end initialize_gui_tags_BM */

static void
appsubmenuactivated_cbBM (GtkMenu * menu,
                          gboolean force_hide, gpointer user_data);
void
appsubmenuactivated_cbBM (GtkMenu * menu,
                          gboolean force_hide, gpointer user_data)
{
  GtkWidget *debugmit = (GtkMenuItem *) user_data;
  ASSERT_BM (GTK_IS_CHECK_MENU_ITEM (debugmit));
  printf ("%s:%d appsubmenuactivated debugmsg %s\n", __FILE__, __LINE__,
          debugmsg_BM ? "true" : "false");
  gtk_check_menu_item_set_active (debugmit, debugmsg_BM);
}                               /* end appsubmenuactivated_cbBM */

static void
appdebugtoggled_cbBM (GtkCheckMenuItem * checkmenuitem, gpointer user_data);
static void
apptoggledparsedebug_cbBM (GtkCheckMenuItem * checkmenuitem,
                           gpointer user_data);
void
appdebugtoggled_cbBM (GtkCheckMenuItem * checkmenuitem, gpointer user_data)
{
  bool newdebug = gtk_check_menu_item_get_active (checkmenuitem);
  debugmsg_BM = newdebug;
  time_t nowt = 0;
  time (&nowt);
  struct tm nowtm = { };
  localtime_r (&nowt, &nowtm);
  char nowbuf[64];
  memset (nowbuf, 0, sizeof (nowbuf));
  strftime (nowbuf, sizeof (nowbuf), "%c", &nowtm);
  if (debugmsg_BM)
    {
      INFOPRINTF_BM ("\n**** debug messages enabled %s ***\n", nowbuf);
      log_begin_message_BM ();
      log_puts_message_BM ("debug messages enabled.");
      log_end_message_BM ();
    }
  else
    {
      INFOPRINTF_BM ("\n**** debug messages disabled %s **\n", nowbuf);
      log_begin_message_BM ();
      log_puts_message_BM ("debug messages disabled.");
      log_end_message_BM ();
    }
}                               /* end appdebugtoggled_cbBM */

void
apptoggledparsedebug_cbBM (GtkCheckMenuItem * checkmenuitem,
                           gpointer user_data)
{
  bool newdebug = gtk_check_menu_item_get_active (checkmenuitem);
  parsedebugmsg_BM = newdebug;
  time_t nowt = 0;
  time (&nowt);
  struct tm nowtm = { };
  localtime_r (&nowt, &nowtm);
  char nowbuf[64];
  memset (nowbuf, 0, sizeof (nowbuf));
  strftime (nowbuf, sizeof (nowbuf), "%c", &nowtm);
  if (parsedebugmsg_BM)
    {
      if (!debugmsg_BM)
        {
          debugmsg_BM = true;
          gtk_check_menu_item_set_active (appparsedebug_BM, true);
        }
      INFOPRINTF_BM ("\n**** parse debug messages enabled %s ***\n", nowbuf);
      log_begin_message_BM ();
      log_puts_message_BM ("parse debug messages enabled.");
      log_end_message_BM ();
    }
  else
    {
      INFOPRINTF_BM ("\n**** parse debug messages disabled %s **\n", nowbuf);
      log_begin_message_BM ();
      log_puts_message_BM ("parse debug messages disabled.");
      log_end_message_BM ();
    }
}                               /* end apptoggledparsedebug */

GtkWidget *
initialize_gui_menubar_BM (GtkWidget * mainvbox, GtkBuilder * bld)
{
  GtkWidget *mainmenubar = gtk_menu_bar_new ();
  gtk_box_pack_start (GTK_BOX (mainvbox), mainmenubar,
                      BOXNOEXPAND_BM, BOXNOFILL_BM, 2);
  GtkWidget *appquit =
    GTK_WIDGET (gtk_builder_get_object (bld, "appquit_id"));
  g_signal_connect (appquit, "activate", quitgui_BM, NULL);
  g_signal_connect (mainwin_BM, "delete-event",
                    (GCallback) deletemainwin_BM, NULL);
  GtkWidget *appexit =
    GTK_WIDGET (gtk_builder_get_object (bld, "appexit_id"));
  g_signal_connect (appexit, "activate", exitgui_BM, NULL);
  GtkWidget *appdump =
    GTK_WIDGET (gtk_builder_get_object (bld, "appdump_id"));
  g_signal_connect (appdump, "activate", dumpgui_BM, NULL);
  GtkWidget *appgarbcoll =
    GTK_WIDGET (gtk_builder_get_object (bld, "appgarbcoll_id"));
  appdebug_BM = GTK_WIDGET (gtk_builder_get_object (bld, "appdebug_id"));
  ASSERT_BM (GTK_IS_CHECK_MENU_ITEM (appdebug_BM));
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (appdebug_BM),
                                  debugmsg_BM | debug_after_load_BM);
  appparsedebug_BM =
    GTK_WIDGET (gtk_builder_get_object (bld, "appparsedebug_id"));
  GtkWidget *appsubmenu =
    GTK_WIDGET (gtk_builder_get_object (bld, "appsubmenu_id"));
  g_signal_connect (appsubmenu, "activate-current", appsubmenuactivated_cbBM,
                    appdebug_BM);
  g_signal_connect (appgarbcoll, "activate", garbage_collect_from_gui_BM,
                    NULL);
  g_signal_connect (appdebug_BM, "toggled", appdebugtoggled_cbBM, NULL);
  g_signal_connect (appparsedebug_BM, "toggled", apptoggledparsedebug_cbBM,
                    NULL);
  GtkWidget *appmenu =
    GTK_WIDGET (gtk_builder_get_object (bld, "menuapp_id"));
  ASSERT_BM (GTK_IS_WIDGET (appmenu));
  gtk_menu_shell_append (GTK_MENU_SHELL (mainmenubar), appmenu);
  GtkWidget *editmenu =
    GTK_WIDGET (gtk_builder_get_object (bld, "menuedit_id"));
  ASSERT_BM (GTK_IS_WIDGET (editmenu));
  gtk_menu_shell_append (GTK_MENU_SHELL (mainmenubar), editmenu);
  GtkWidget *sep1 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_box_pack_start (GTK_BOX (mainvbox), sep1,
                      BOXNOEXPAND_BM, BOXNOFILL_BM, 2);
  return mainmenubar;
}                               /* end initialize_gui_menubar_BM */




GtkWidget *
initialize_log_scrollview_BM (void)
{
  logbuf_BM = gtk_text_buffer_new (logtagtable_BM);
  logview_BM = gtk_text_view_new_with_buffer (logbuf_BM);
  gtk_widget_set_name (logview_BM, "logview");
  g_signal_connect (logview_BM, "populate-popup",
                    G_CALLBACK (populatepopuplog_BM), NULL);
  gtk_text_view_set_editable (GTK_TEXT_VIEW (logview_BM), false);
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (logview_BM),
                               GTK_WRAP_WORD_CHAR);
  GtkWidget *logscrolw = gtk_scrolled_window_new (NULL, NULL);
  gtk_container_add (GTK_CONTAINER (logscrolw), logview_BM);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (logscrolw),
                                  GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  if (gui_is_running_BM)
    {
      log_begin_message_BM ();
      log_printf_message_BM
        ("log of bismon (build %s,\n commit %s,\n checksum %s) pid %d",
         bismon_timestamp, bismon_lastgitcommit, bismon_checksum,
         (int) getpid ());
      log_end_message_BM ();
    }
  return logscrolw;
}                               /* end initialize_log_scrollview_BM */



void
marksetcmd_BM (GtkTextBuffer * txbuf, GtkTextIter * txit,
               GtkTextMark * txmark, gpointer data __attribute__((unused)))
{
  ASSERT_BM (txbuf == commandbuf_BM);
  if (txmark != gtk_text_buffer_get_insert (txbuf))
    return;
  unsigned off = gtk_text_iter_get_offset (txit);
  struct parenoffset_stBM *blinkpo = cmd_find_enclosing_parens_BM (off);
  commandblinkstop_BM ();
  if (!blinkpo)
    {
      memset (&commandblinkparens_BM, 0, sizeof (commandblinkparens_BM));
      return;
    }
  commandblinkparens_BM = *blinkpo;
  commandblinkstart_BM ();
}                               /* end marksetcmd_BM */




void
marksetbrows_BM (GtkTextBuffer * txbuf, GtkTextIter * txit,
                 GtkTextMark * txmark, gpointer data __attribute__((unused)))
{
  ASSERT_BM (txbuf == browserbuf_BM);
  if (txmark != gtk_text_buffer_get_insert (txbuf))
    return;
  unsigned off = gtk_text_iter_get_offset (txit);
  struct parenoffset_stBM *blinkpo = NULL;
  // do a dichotomical search on browsedobj_BM
  {
    unsigned oblo = 0, obhi = browserobulen_BM, obmd = 0;
    int obix = -1;
    while (oblo + 8 < obhi && obix < 0)
      {
        obmd = (oblo + obhi) / 2;
        struct browsedobj_stBM *mdbrob = browsedobj_BM + obmd;
        ASSERT_BM (mdbrob->brow_ostartm != NULL
                   && mdbrob->brow_oendm != NULL);
        GtkTextIter ostartit = EMPTY_TEXT_ITER_BM;
        GtkTextIter oendit = EMPTY_TEXT_ITER_BM;
        gtk_text_buffer_get_iter_at_mark (browserbuf_BM,
                                          &ostartit, mdbrob->brow_ostartm);
        int startcmp = gtk_text_iter_compare (txit, &ostartit);
        if (startcmp < 0)
          {
            obhi = obmd;
            continue;
          }
        gtk_text_buffer_get_iter_at_mark (browserbuf_BM,
                                          &oendit, mdbrob->brow_oendm);
        int endcmp = gtk_text_iter_compare (txit, &oendit);
        if (endcmp > 0)
          {
            oblo = obmd;
            continue;
          }
        if (gtk_text_iter_in_range (txit, &ostartit, &oendit))
          {
            obix = obmd;
            break;
          }
      }
    for (obmd = oblo; obmd < obhi && obix < 0; obmd++)
      {
        GtkTextIter ostartit = EMPTY_TEXT_ITER_BM;
        GtkTextIter oendit = EMPTY_TEXT_ITER_BM;
        struct browsedobj_stBM *mdbrob = browsedobj_BM + obmd;
        ASSERT_BM (mdbrob->brow_ostartm != NULL
                   && mdbrob->brow_oendm != NULL);
        gtk_text_buffer_get_iter_at_mark (browserbuf_BM, &ostartit,
                                          mdbrob->brow_ostartm);
        gtk_text_buffer_get_iter_at_mark (browserbuf_BM, &oendit,
                                          mdbrob->brow_oendm);
        if (gtk_text_iter_in_range (txit, &ostartit, &oendit))
          obix = obmd;
      }
    if (obix >= 0)
      {
        GtkTextIter ostartit = EMPTY_TEXT_ITER_BM;
        GtkTextIter oendit = EMPTY_TEXT_ITER_BM;
        struct browsedobj_stBM *brob = browsedobj_BM + obix;
        unsigned curnbparen = brob->brow_oparenulen;
        if (curnbparen == 0)
          return;
        gtk_text_buffer_get_iter_at_mark (browserbuf_BM, &ostartit,
                                          brob->brow_ostartm);
        gtk_text_buffer_get_iter_at_mark (browserbuf_BM, &oendit,
                                          brob->brow_oendm);
        guint ostartoff = gtk_text_iter_get_offset (&ostartit);
        int delta = off - ostartoff;
        ASSERT_BM (delta >= 0);
        for (unsigned pix = 0; pix < curnbparen; pix++)
          {
            struct parenoffset_stBM *curpo = brob->brow_oparenarr + pix;
            if (parens_surrounds_BM (curpo, delta))
              {
                if (!blinkpo ||
                    blinkpo->paroff_close - blinkpo->paroff_open
                    > curpo->paroff_close - curpo->paroff_open)
                  blinkpo = curpo;
              }
          }
        if (blinkpo)
          {
            browserblinkparens_BM = *blinkpo;
            if (blinkpo->paroff_open >= 0 && blinkpo->paroff_openlen > 0)
              browserblinkparens_BM.paroff_open += ostartoff;
            if (blinkpo->paroff_close >= 0 && blinkpo->paroff_closelen > 0)
              browserblinkparens_BM.paroff_close += ostartoff;
            if (blinkpo->paroff_xtra >= 0 && blinkpo->paroff_xtralen > 0)
              browserblinkparens_BM.paroff_xtra += ostartoff;
          }
      }
  }
  // do a dichotomical search on browsedval_BM
  if (!blinkpo && browsednvulen_BM > 0)
    {
      unsigned bvlo = 0, bvhi = browsednvulen_BM, bvmd = 0;
      int bvix = -1;
      while (bvlo + 8 < bvhi && bvix < 0)
        {
          bvmd = (bvlo + bvhi) / 2;
          struct browsedval_stBM *mdbrva = browsedval_BM + bvmd;
          ASSERT_BM (mdbrva->brow_vstartmk && mdbrva->brow_vendmk);
          GtkTextIter vstartit = EMPTY_TEXT_ITER_BM;
          GtkTextIter vendit = EMPTY_TEXT_ITER_BM;
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM,
                                            &vstartit, mdbrva->brow_vstartmk);
          int startcmp = gtk_text_iter_compare (txit, &vstartit);
          if (startcmp < 0)
            {
              bvhi = bvmd;
              continue;
            }
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM,
                                            &vendit, mdbrva->brow_vendmk);
          int endcmp = gtk_text_iter_compare (txit, &vendit);
          if (endcmp > 0)
            {
              bvlo = bvmd;
              continue;
            }
          if (gtk_text_iter_in_range (txit, &vstartit, &vendit))
            {
              bvix = bvmd;
              break;
            }
        }
      for (bvmd = bvlo; bvmd < bvhi && bvix < 0; bvmd++)
        {
          struct browsedval_stBM *mdbrva = browsedval_BM + bvmd;
          ASSERT_BM (mdbrva->brow_vstartmk && mdbrva->brow_vendmk);
          GtkTextIter vstartit = EMPTY_TEXT_ITER_BM;
          GtkTextIter vendit = EMPTY_TEXT_ITER_BM;
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM,
                                            &vstartit, mdbrva->brow_vstartmk);
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM, &vendit,
                                            mdbrva->brow_vendmk);
          if (gtk_text_iter_in_range (txit, &vstartit, &vendit))
            bvix = bvmd;
        }
      if (bvix >= 0)
        {
          struct browsedval_stBM *brva = browsedval_BM + bvix;
          GtkTextIter vstartit = EMPTY_TEXT_ITER_BM;
          GtkTextIter vendit = EMPTY_TEXT_ITER_BM;
          unsigned curnbparen = brva->brow_vparenulen;
          if (curnbparen == 0)
            return;
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM,
                                            &vstartit, brva->brow_vstartmk);
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM, &vendit,
                                            brva->brow_vendmk);
          guint vstartoff = gtk_text_iter_get_offset (&vstartit);
          int delta = off - vstartoff;
          ASSERT_BM (delta >= 0);
          for (unsigned pix = 0; pix < curnbparen; pix++)
            {
              struct parenoffset_stBM *curpo = brva->brow_vparenarr + pix;
              if (parens_surrounds_BM (curpo, delta))
                {
                  if (!blinkpo ||
                      blinkpo->paroff_close - blinkpo->paroff_open
                      > curpo->paroff_close - curpo->paroff_open)
                    blinkpo = curpo;
                }
            }
          if (blinkpo)
            {
              browserblinkparens_BM = *blinkpo;
              if (blinkpo->paroff_open >= 0 && blinkpo->paroff_openlen > 0)
                browserblinkparens_BM.paroff_open += vstartoff;
              if (blinkpo->paroff_close >= 0 && blinkpo->paroff_closelen > 0)
                browserblinkparens_BM.paroff_close += vstartoff;
              if (blinkpo->paroff_xtra >= 0 && blinkpo->paroff_xtralen > 0)
                browserblinkparens_BM.paroff_xtra += vstartoff;
            }
        }
    }
  browserblinkstop_BM ();
  if (blinkpo)
    {
      browserblinkstart_BM ();
    }
}                               /* end marksetbrows_BM */


extern bool did_deferred_BM (void);
gboolean
guiperiodicgarbagecollection_BM (gpointer data __attribute__((unused)))
{
  ASSERT_BM (data == NULL);
  did_deferred_BM ();
  if (atomic_load (&want_garbage_collection_BM) && gtk_main_level () <= 1)
    {
      full_garbage_collection_BM (NULL);
    }
  return G_SOURCE_CONTINUE;     // repeat again later
}                               /* end guiperiodicgarbagecollection_BM */

////////////////
static gboolean postponed_guigtk_cbBM (gpointer udata);
static guint postponed_timeoutid_bm;

static pthread_mutex_t postponedmtx_gtkbm = PTHREAD_MUTEX_INITIALIZER;

register_gui_postponed_BM (double nextimstamp)
{
#define MAX_POSTPONED_MILLISEC_BM 2500
#define MIN_POSTPONED_MILLISEC_BM 20
  pthread_mutex_lock (&postponedmtx_gtkbm);
  double deltat = nextimstamp - clocktime_BM (CLOCK_MONOTONIC);
  int deltams = 0;
  if (deltat > MAX_POSTPONED_MILLISEC_BM * 1.0e-3)
    deltams = MAX_POSTPONED_MILLISEC_BM;
  else
    deltams = (int) (deltat * 1.0e-3);
  if (deltams < MIN_POSTPONED_MILLISEC_BM)
    deltams = MIN_POSTPONED_MILLISEC_BM;
  if (postponed_timeoutid_bm > 0)
    g_source_remove (postponed_timeoutid_bm), postponed_timeoutid_bm = 0;
  postponed_timeoutid_bm =
    g_timeout_add (deltams, postponed_guigtk_cbBM, NULL);
  pthread_mutex_unlock (&postponedmtx_gtkbm);
}                               /* end register_gui_postponed_BM */



gboolean
postponed_guigtk_cbBM (gpointer udata)
{
  objectval_tyBM *k_postponed_guigtk = BMK_4DzpsR0MDLS_1GMNlJhyPX5;
  LOCALFRAME_BM ( /*prev: */ NULL,
                 /*descr: */ k_postponed_guigtk,
                 volatile value_tyBM failreason;        //
                 volatile value_tyBM failplace; //
                 value_tyBM postponedv; //
                 value_tyBM resv;       //
                 value_tyBM errorv;     //
                 objectval_tyBM * connob;       //
    );
  double timestamp = 0.0;
  ASSERT_BM (udata == NULL);
  ASSERT_BM (pthread_self () == mainthreadid_BM);
  struct failurehandler_stBM *prevfailureh = curfailurehandle_BM;
  int failcod = 0;
  _.failreason = NULL;
  _.failplace = NULL;
  struct failurelockset_stBM flockset = { };
  initialize_failurelockset_BM (&flockset, sizeof (flockset));
  LOCAL_FAILURE_HANDLE_BM (&flockset, lab_failurepostponed, failcod,
                           _.failreason, _.failplace);
  curfailurehandle_BM = prevfailureh;
  if (failcod)
  lab_failurepostponed:
    {
      DBGPRINTF_BM
        ("postponed_guigtk_cb failure: failcod#%d failreason %s failplace %s",
         failcod, OUTSTRVALUE_BM (_.failreason),
         OUTSTRVALUE_BM (_.failplace));
      WARNPRINTF_BM
        ("postponed_guigtk_cb failure: failcod#%d failreason %s failplace %s",
         failcod, OUTSTRVALUE_BM (_.failreason),
         OUTSTRVALUE_BM (_.failplace));
      log_begin_message_BM ();
      log_printf_message_BM
        ("postponed_guigtk_cb failure: failcod#%d, failreason: ", failcod);
      if (isobject_BM (_.failreason))
        {
          log_object_message_BM (objectcast_BM (_.failreason));
        }
      else
        {
          log_puts_message_BM (OUTSTRVALUE_BM (_.failreason));
        };
      log_puts_message_BM (";\n");
      log_puts_message_BM (".. failplace: ");
      if (isobject_BM (_.failplace))
        {
          log_object_message_BM (objectcast_BM (_.failplace));
        }
      else
        {
          log_puts_message_BM (OUTSTRVALUE_BM (_.failplace));
        };
      log_end_message_BM ();
    }
  else
    {                           /* no failcod: */
      timestamp = timestamp_newest_postpone_BM ();
      DBGPRINTF_BM ("postponed_guigtk newest timestamp=%g=now%+.4f",
                    timestamp, timestamp - clocktime_BM (CLOCK_MONOTONIC));
      if (timestamp >= clocktime_BM (CLOCK_MONOTONIC))
        {
          _.postponedv = pop_newest_postpone_BM (&timestamp, CURFRAME_BM);
          DBGPRINTF_BM
            ("postponed_guigtk postponedv=%s timestamp=%g=now%+.4f",
             OUTSTRVALUE_BM (_.postponedv), timestamp,
             timestamp - clocktime_BM (CLOCK_MONOTONIC));
          if (_.postponedv)
            {
              ASSERT_BM (isnode_BM (_.postponedv));
              _.resv = run_postponed_node_BM (_.postponedv, CURFRAME_BM);
              if (_.resv == NULL)
                {
                  WARNPRINTF_BM ("postponed_guigtk failed to run %s",
                                 OUTSTRVALUE_BM (_.postponedv));
                  fflush (NULL);
                  _.errorv = makenode1_BM (k_postponed_guigtk, _.postponedv);
                  PLAINFAILURE_BM (__LINE__, _.errorv, CURFRAME_BM);
                }
              double nexttimestamp = timestamp_newest_postpone_BM ();
              DBGPRINTF_BM ("postponed_guigtk nexttimestamp=%g=now%+.4f",
                            nexttimestamp,
                            nexttimestamp - clocktime_BM (CLOCK_MONOTONIC));
              if (nexttimestamp > 0)
                {
                  register_gui_postponed_BM (nexttimestamp);
                  return G_SOURCE_CONTINUE;
                }
            }
        }
      else
        return G_SOURCE_CONTINUE;
    }
  return G_SOURCE_REMOVE;
}                               /* end postponed_guigtk_cbBM */

/// end of file guicommand_GTKBM.c
