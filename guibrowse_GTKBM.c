// file guibrowse_GTKBM.c
// SPDX-License-Identifier: GPL-3.0-or-later
/***
    BISMON 
    Copyright © 2018 - 2022 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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
#include "bismon.h"
#include "guibrowse_GTKBM.const.h"

GtkWidget *mainwin_BM;
GtkWidget *errormessagedialog_BM;
FILE *gui_command_log_file_BM;

//////////////// browser
int browserdepth_BM = 7;

GtkTextTagTable *browsertagtable_BM;
GtkTextBuffer *browserbuf_BM;
GtkWidget *browserview_BM;
GtkTextIter browserit_BM;
int browserendtitleoffset_BM;
GtkTextTag *pagetitle_brotag_BM;
GtkTextTag *objtitle_brotag_BM;
GtkTextTag *valtitle_brotag_BM;
GtkTextTag *focustitle_brotag_BM;
GtkTextTag *objcommtitle_brotag_BM;
GtkTextTag *objnametitle_brotag_BM;
GtkTextTag *objidtitle_brotag_BM;
GtkTextTag *objid_brotag_BM;
GtkTextTag *objname_brotag_BM;
GtkTextTag *objrefcomm_brotag_BM;
GtkTextTag *nest_brotag_BM;
GtkTextTag *blink_brotag_BM;
GtkTextTag *num_brotag_BM;
GtkTextTag *toodeep_brotag_BM;
GtkTextTag *str_brotag_BM;
GtkTextTag *stresc_brotag_BM;
GtkTextTag *miscomm_brotag_BM;
GtkTextTag *epilogue_brotag_BM;

GtkWidget *appdebug_BM;
GtkWidget *appparsedebug_BM;

/// the browsed objects
unsigned browserobsize_BM;      /* allocated size of browsedobj_BM */
unsigned browserobulen_BM;      /* used length */
int browserobcurix_BM;          /* current index in browsedobj_BM */
struct browsedobj_stBM *browsedobj_BM;

/// the browsed named values
unsigned browsednvsize_BM;      /* allocated size */
unsigned browsednvulen_BM;      /* unsigned length */
int browsednvcurix_BM;
struct browsedval_stBM *browsedval_BM;
guint browserblinkid_BM;
struct parenoffset_stBM browserblinkparens_BM;  /// offsets are absolute

// for $<var>, use find_named_value_gui_BM, show in  dollar_cmdtag.
static parser_expand_dollarval_sigBM parsdollarval_guicmd_BM;

// for $:<var>, use find_named_value_gui_BM, check that value is an
// object, show it in dollar_cmdtag
static parser_expand_dollarobj_sigBM parsdollarobj_guicmd_BM;

// parse €<name> or $*<name>
static parser_expand_newname_sigBM parsmakenewname_guicmd_BM;

// parse inside $(...),
// handle !> <obselector> (...) # to send a message for its result
// handle ( .... ) # to apply a function
// handle !. <obattr> # to get an attribute
// handle !@ <index> # to get a component
// handle $% <name>  # to show and bind to name
static parser_expand_valexp_sigBM parsvalexp_guicmd_BM;


// parse inside $[...],
// handle * <name> to create a new (userE) named object
// handle  !* <name> to create a new (global) named object
// handle : to create a new transient anonymous object
// handle ~ to create a new global anonymous object
// handle % to create a new (userE) anonymous object
// handle $:<var> to get the object registered as <var>
// handle ( <expr> ) to cast a value into an object
// handle <id> or <name> to  refer to an existing object
static parser_expand_objexp_sigBM parsobjexp_guicmd_BM;

// expand readmacros nodes with ^ macroname ( args )
// apply the `command_readmacro` closure from the connective macroname
static parser_expand_readmacro_sigBM parsreadmacroexp_guicmd_BM;

// error at parsing: color in error_cmdtag, show the error dialog,
// jongjmp to jmperrorcmd_BM
static parser_error_sigBM parserror_guicmd_BM;
int commandnumber_BM;


/// the completion set - should be a GC root
const seqobval_tyBM *complseqcmd_BM;
/// begin and end offset for completion replacement
int compbegoffcmd_BM, compendoffcmd_BM;
char *complcommonprefix_BM;
bool complbyid_BM;




//////////////// command
GtkTextTagTable *commandtagtable_BM;
GtkTextBuffer *commandbuf_BM;
GtkWidget *commandview_BM;

GtkTextTagTable *logtagtable_BM;
GtkTextBuffer *logbuf_BM;
GtkWidget *logview_BM;
GtkTextTag *error_logtag_BM;
GtkTextTag *time_logtag_BM;
GtkTextTag *id_logtag_BM;
GtkTextTag *name_logtag_BM;
GtkTextTag *comment_logtag_BM;
GtkTextTag *code_logtag_BM;
GtkTextTag *command_logtag_BM;



GtkTextTag *errored_cmdtag_BM;
GtkTextTag *skipped_cmdtag_BM;
GtkTextTag *commentinside_cmdtag_BM;
GtkTextTag *commentsign_cmdtag_BM;
GtkTextTag *delim_cmdtag_BM;
GtkTextTag *knowname_cmdtag_BM;
GtkTextTag *newname_cmdtag_BM;
GtkTextTag *id_cmdtag_BM;
GtkTextTag *number_cmdtag_BM;
GtkTextTag *stringsign_cmdtag_BM;
GtkTextTag *stringinside_cmdtag_BM;
GtkTextTag *dollar_cmdtag_BM;
GtkTextTag *nesting_cmdtag_BM;
GtkTextTag *blink_cmdtag_BM;

#define CMD_MAXNEST_BM 64
GtkTextTag *open_cmdtags_BM[CMD_MAXNEST_BM];
GtkTextTag *close_cmdtags_BM[CMD_MAXNEST_BM];
GtkTextTag *xtra_cmdtags_BM[CMD_MAXNEST_BM];

#define BROWSE_MAXDEPTH_BM 48

// on cmd parse error, we setjmp to ....
jmp_buf jmperrorcmd_BM;

// the function to handle keypresses of cmd, for Return & Tab
static gboolean handlekeypresscmd_BM (GtkWidget *, GdkEventKey *, gpointer);

// the function to handle "end-user-action" on commandbuf_BM
static void enduseractioncmd_BM (GtkTextBuffer *, gpointer);

// the function to handle "populate-popup" on commandview_BM
static void populatepopupcmd_BM (GtkTextView *, GtkWidget *, gpointer);
// the function to handle "populate-popup" on browserview_BM
static void populatepopupbrow_BM (GtkTextView *, GtkWidget *, gpointer);
// the function to handle "populate-popup" on logview_BM
static void populatepopuplog_BM (GtkTextView *, GtkWidget *, gpointer);

static void parsecommandbuf_BM (struct parser_stBM *pars,
                                struct stackframe_stBM *stkf);

guint commandblinkid_BM;
struct parenoffset_stBM commandblinkparens_BM;  /// offsets are absolute

/// stop completely the blinking
static void commandblinkstop_BM (void);

// unblink temporarily
static int commandblinkoff_BM (gpointer);
// blink temporarily
static int commandblinkon_BM (gpointer);

// start the blinking
static void commandblinkstart_BM (void);


const struct parserops_stBM parsop_command_build_BM = {
  .parsop_magic = PARSOPMAGIC_BM,
  .parsop_serial = 1,
  .parsop_nobuild = false,
  .parsop_error_rout = parserror_guicmd_BM,
  .parsop_expand_dollarobj_rout = parsdollarobj_guicmd_BM,
  .parsop_expand_dollarval_rout = parsdollarval_guicmd_BM,
  .parsop_expand_newname_rout = parsmakenewname_guicmd_BM,
  .parsop_expand_valexp_rout = parsvalexp_guicmd_BM,
  .parsop_expand_objexp_rout = parsobjexp_guicmd_BM,
  .parsop_expand_readmacro_rout = parsreadmacroexp_guicmd_BM,
  .parsop_decorate_comment_sign_rout = parscommentsign_guicmd_BM,
  .parsop_decorate_comment_inside_rout = parscommentinside_guicmd_BM,
  .parsop_decorate_delimiter_rout = parsdelim_guicmd_BM,
  .parsop_decorate_id_rout = parsid_guicmd_BM,
  .parsop_decorate_known_name_rout = parsknowname_guicmd_BM,
  .parsop_decorate_new_name_rout = parsnewname_guicmd_BM,
  .parsop_decorate_number_rout = parsnumber_guicmd_BM,
  .parsop_decorate_string_sign_rout = parsstringsign_guicmd_BM,
  .parsop_decorate_string_inside_rout = parsstringinside_guicmd_BM,
  .parsop_decorate_nesting_rout = parsnesting_guicmd_BM,
  .parsop_decorate_start_nesting_rout = parsstartnesting_guicmd_BM,
};

const struct parserops_stBM parsop_command_nobuild_BM = {
  .parsop_magic = PARSOPMAGIC_BM,
  .parsop_serial = 2,
  .parsop_nobuild = true,
  .parsop_error_rout = parserror_guicmd_BM,
  .parsop_expand_dollarobj_rout = parsdollarobj_guicmd_BM,
  .parsop_expand_dollarval_rout = parsdollarval_guicmd_BM,
  .parsop_expand_newname_rout = parsmakenewname_guicmd_BM,
  .parsop_expand_valexp_rout = parsvalexp_guicmd_BM,
  .parsop_expand_objexp_rout = parsobjexp_guicmd_BM,
  .parsop_expand_readmacro_rout = parsreadmacroexp_guicmd_BM,
  .parsop_decorate_comment_sign_rout = parscommentsign_guicmd_BM,
  .parsop_decorate_comment_inside_rout = parscommentinside_guicmd_BM,
  .parsop_decorate_delimiter_rout = parsdelim_guicmd_BM,
  .parsop_decorate_id_rout = parsid_guicmd_BM,
  .parsop_decorate_known_name_rout = parsknowname_guicmd_BM,
  .parsop_decorate_new_name_rout = parsnewname_guicmd_BM,
  .parsop_decorate_number_rout = parsnumber_guicmd_BM,
  .parsop_decorate_string_sign_rout = parsstringsign_guicmd_BM,
  .parsop_decorate_string_inside_rout = parsstringinside_guicmd_BM,
  .parsop_decorate_nesting_rout = parsnesting_guicmd_BM,
  .parsop_decorate_start_nesting_rout = parsstartnesting_guicmd_BM,
};




const char *
textiterstrdbg_BM (GtkTextIter * it)
{
  static char itinfobuf[32];
  memset (itinfobuf, 0, sizeof (itinfobuf));
  if (it)
    snprintf (itinfobuf, sizeof (itinfobuf), "L%dC%d/%d",
              gtk_text_iter_get_line (it) + 1,
              gtk_text_iter_get_line_offset (it),
              gtk_text_iter_get_offset (it));
  else
    strcpy (itinfobuf, "*niltextiter*");
  return itinfobuf;
}                               /* end textiterstrdbg_BM */




void
run_then_erase_command_BM (void)
{
  runcommand_BM (true);
}                               /* end run_then_erase_command_BM */

void
run_then_keep_command_BM (void)
{
  runcommand_BM (false);
}                               /* end run_then_keep_command_BM */

void
clear_command_BM (void)
{
  GtkTextIter startit = EMPTY_TEXT_ITER_BM;
  GtkTextIter endit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_bounds (commandbuf_BM, &startit, &endit);
  gtk_text_buffer_delete (commandbuf_BM, &startit, &endit);
  log_begin_message_BM ();
  log_puts_message_BM ("cleared commands");
  log_end_message_BM ();
}                               /* end clear_command_BM */




////////////////////////////////////////////////////////////////


void
browserblinkstop_BM (void)
{
  if (browserblinkid_BM > 0)
    g_source_remove (browserblinkid_BM), browserblinkid_BM = 0;
  browserblinkoff_BM (NULL);
}                               /* end browserblinkstop_BM */

int
browserblinkoff_BM (gpointer data __attribute__((unused)))
{
  GtkTextIter startit = EMPTY_TEXT_ITER_BM;
  GtkTextIter endit = EMPTY_TEXT_ITER_BM;
  if (!browserbuf_BM)
    {
      browserbuf_BM = newgui_get_browsebuf_BM ();
      if (!browserbuf_BM)
        return G_SOURCE_REMOVE;
    };
  gtk_text_buffer_get_bounds (browserbuf_BM, &startit, &endit);
  gtk_text_buffer_remove_tag (browserbuf_BM, blink_brotag_BM, &startit,
                              &endit);
  return G_SOURCE_REMOVE;
}                               /* end browserblinkoff_BM */

int
browserblinkon_BM (gpointer data __attribute__((unused)))
{
  if (browserblinkparens_BM.paroff_open > 0
      && browserblinkparens_BM.paroff_openlen > 0)
    {
      GtkTextIter openstartit = EMPTY_TEXT_ITER_BM;
      GtkTextIter openendit = EMPTY_TEXT_ITER_BM;
      if (!browserbuf_BM)
        {
          browserbuf_BM = newgui_get_browsebuf_BM ();
          if (!browserbuf_BM)
            return G_SOURCE_REMOVE;
        };
      gtk_text_buffer_get_iter_at_offset (browserbuf_BM, &openstartit,
                                          browserblinkparens_BM.paroff_open);
      openendit = openstartit;
      gtk_text_iter_forward_chars (&openendit,
                                   browserblinkparens_BM.paroff_openlen);
      gtk_text_buffer_apply_tag (browserbuf_BM, blink_brotag_BM, &openstartit,
                                 &openendit);
    }
  if (browserblinkparens_BM.paroff_close > 0
      && browserblinkparens_BM.paroff_closelen > 0)
    {
      GtkTextIter closestartit = EMPTY_TEXT_ITER_BM;
      GtkTextIter closeendit = EMPTY_TEXT_ITER_BM;
      gtk_text_buffer_get_iter_at_offset (browserbuf_BM, &closeendit,
                                          browserblinkparens_BM.paroff_close);
      closestartit = closeendit;
      gtk_text_iter_backward_chars (&closestartit,
                                    browserblinkparens_BM.paroff_closelen);
      gtk_text_buffer_apply_tag (browserbuf_BM, blink_brotag_BM,
                                 &closestartit, &closeendit);
    }
  if (browserblinkparens_BM.paroff_xtra > 0
      && browserblinkparens_BM.paroff_xtralen > 0)
    {
      GtkTextIter xtrastartit = EMPTY_TEXT_ITER_BM, xtraendit =
        EMPTY_TEXT_ITER_BM;
      gtk_text_buffer_get_iter_at_offset (browserbuf_BM, &xtrastartit,
                                          browserblinkparens_BM.paroff_xtra);
      xtraendit = xtrastartit;
      gtk_text_iter_forward_chars (&xtraendit,
                                   browserblinkparens_BM.paroff_xtralen);
      gtk_text_buffer_apply_tag (browserbuf_BM, blink_brotag_BM, &xtrastartit,
                                 &xtraendit);
    }
  if (browserblinkid_BM > 0)
    {
      (void) g_timeout_add (UNBLINKDELAYMILLISEC_BM, browserblinkoff_BM,
                            NULL);
      return G_SOURCE_CONTINUE;
    }
  return G_SOURCE_REMOVE;
}                               /* end browserblinkon_BM */


void
browserblinkstart_BM (void)
{
  if (browserblinkid_BM > 0)
    g_source_remove (browserblinkid_BM), browserblinkid_BM = 0;
  browserblinkoff_BM (NULL);
  browserblinkid_BM =
    g_timeout_add (BLINKDELAYMILLISEC_BM, browserblinkon_BM, NULL);
  browserblinkon_BM (NULL);
}                               /* end browserblinkstart_BM */

void
start_browse_object_BM (const objectval_tyBM * obj,
                        const objectval_tyBM * objsel, int depth)
{
  if (!browserbuf_BM)
    {
      browserbuf_BM = newgui_get_browsebuf_BM ();
      if (!browserbuf_BM)
        return;
    };
  browserblinkstop_BM ();
  ASSERT_BM (isobject_BM ((const value_tyBM) obj));
  ASSERT_BM (isobject_BM ((const value_tyBM) objsel));
  browsednvcurix_BM = -1;
  if (browserobulen_BM + 1 >= browserobsize_BM)
    {
      unsigned newsiz = prime_above_BM (4 * browserobulen_BM / 3 + 10);
      struct browsedobj_stBM *newarr =  //
        calloc (newsiz, sizeof (struct browsedobj_stBM));
      if (!newarr)
        FATAL_BM ("calloc failure for %u browsed objects", newsiz);
      memcpy (newarr, browsedobj_BM,
              browserobulen_BM * sizeof (struct browsedobj_stBM));
      free (browsedobj_BM);
      browsedobj_BM = newarr;
      browserobsize_BM = newsiz;
    }
  int lo = 0, hi = browserobulen_BM, md = 0;
  while (lo + 8 < hi)
    {
      md = (lo + hi) / 2;
      const objectval_tyBM *mdobj = browsedobj_BM[md].brow_obj;
      ASSERT_BM (isobject_BM ((const value_tyBM) mdobj));
      int cmp = objectnamedcmp_BM (mdobj, obj);
      if (cmp <= 0)
        lo = md;
      else
        hi = md;
    }
  for (md = lo; md < hi; md++)
    {
      const objectval_tyBM *mdobj = browsedobj_BM[md].brow_obj;
      ASSERT_BM (isobject_BM ((const value_tyBM) mdobj));
      if (mdobj == obj)
        {                       // replacing existing object
          GtkTextIter startit = EMPTY_TEXT_ITER_BM;
          GtkTextIter endit = EMPTY_TEXT_ITER_BM;
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM, &startit,
                                            browsedobj_BM[md].brow_ostartm);
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM, &endit,
                                            browsedobj_BM[md].brow_oendm);
          gtk_text_buffer_delete (browserbuf_BM, &startit, &endit);
          gtk_text_buffer_insert (browserbuf_BM, &endit, "\n", -1);
          startit = endit;
          gtk_text_iter_backward_char (&startit);
          gtk_text_buffer_move_mark (browserbuf_BM,
                                     browsedobj_BM[md].brow_ostartm,
                                     &startit);
          browsedobj_BM[md].brow_odepth = depth;
          browsedobj_BM[md].brow_objsel = objsel;
          browserit_BM = endit;
          browserobcurix_BM = md;
          return;
        }
      else if (objectnamedcmp_BM (obj, mdobj) < 0)
        {
          GtkTextIter it = EMPTY_TEXT_ITER_BM;
          GtkTextIter startit = EMPTY_TEXT_ITER_BM;
          for (int ix = browserobulen_BM + 1; ix > md; ix--)
            browsedobj_BM[ix] = browsedobj_BM[ix - 1];
          memset (browsedobj_BM + md, 0, sizeof (struct browsedobj_stBM));
          if (md > 0)
            {
              gtk_text_buffer_get_iter_at_mark  //
                (browserbuf_BM, &it, browsedobj_BM[md - 1].brow_oendm);
            }
          else
            {
              gtk_text_buffer_get_iter_at_offset (browserbuf_BM,
                                                  &it,
                                                  browserendtitleoffset_BM);
            }
          browserobulen_BM++;
          browsedobj_BM[md].brow_obj = obj;
          gtk_text_buffer_insert (browserbuf_BM, &it, "\n", -1);
          startit = it;
          gtk_text_iter_backward_char (&startit);
          browsedobj_BM[md].brow_ostartm =      //
            gtk_text_buffer_create_mark (browserbuf_BM, NULL, &startit,
                                         RIGHT_GRAVITY_BM);
          browsedobj_BM[md].brow_oendm =        //
            gtk_text_buffer_create_mark (browserbuf_BM, NULL, &it,
                                         RIGHT_GRAVITY_BM);
          browsedobj_BM[md].brow_odepth = depth;
          browsedobj_BM[md].brow_objsel = objsel;
          browserobcurix_BM = md;
          browserit_BM = it;
          return;
        };
    };
  ASSERT_BM (browserobulen_BM == 0
             ||
             objectnamedcmp_BM (browsedobj_BM
                                [browserobulen_BM - 1].brow_obj, obj) < 0);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  GtkTextIter startit = EMPTY_TEXT_ITER_BM;
  if (browserobulen_BM == 0)
    {
      gtk_text_buffer_get_iter_at_offset
        (browserbuf_BM, &it, browserendtitleoffset_BM);
    }
  else
    {
      gtk_text_buffer_get_iter_at_mark
        (browserbuf_BM, &it, browsedobj_BM[browserobulen_BM - 1].brow_oendm);
    }
  browsedobj_BM[browserobulen_BM].brow_obj = obj;
  gtk_text_buffer_insert (browserbuf_BM, &it, "\n", -1);
  startit = it;
  gtk_text_iter_backward_char (&startit);
  browsedobj_BM[browserobulen_BM].brow_ostartm =        //
    gtk_text_buffer_create_mark (browserbuf_BM, NULL, &startit,
                                 RIGHT_GRAVITY_BM);
  browsedobj_BM[browserobulen_BM].brow_oendm =  //
    gtk_text_buffer_create_mark (browserbuf_BM, NULL, &it, RIGHT_GRAVITY_BM);
  browsedobj_BM[browserobulen_BM].brow_odepth = depth;
  browsedobj_BM[browserobulen_BM].brow_objsel = objsel;
  browserobcurix_BM = 0;
  browserit_BM = it;
  browserobulen_BM++;
}                               /* end start_browse_object_BM */



struct browsedobj_stBM *
find_browsed_object_BM (const objectval_tyBM * obj)
{
  if (!isobject_BM ((const value_tyBM) obj))
    return NULL;
  if (!browserbuf_BM)
    {
      browserbuf_BM = newgui_get_browsebuf_BM ();
      if (!browserbuf_BM)
        return NULL;
    };
  int lo = 0, hi = browserobulen_BM, md = 0;
  while (lo + 8 < hi)
    {
      md = (lo + hi) / 2;
      const objectval_tyBM *mdobj = browsedobj_BM[md].brow_obj;
      ASSERT_BM (isobject_BM ((const value_tyBM) mdobj));
      int cmp = objectnamedcmp_BM (mdobj, obj);
      if (cmp <= 0)
        lo = md;
      else
        hi = md;
    }
  for (md = lo; md < hi; md++)
    {
      const objectval_tyBM *mdobj = browsedobj_BM[md].brow_obj;
      ASSERT_BM (isobject_BM ((const value_tyBM) mdobj));
      if (mdobj == obj)
        return browsedobj_BM + md;
    }
  return NULL;
}                               /* end find_browsed_object_BM */


void
hide_object_gui_BM (const objectval_tyBM * objbrows,
                    struct stackframe_stBM *stkf)
{
  if (!isobject_BM ((const value_tyBM) objbrows))
    return;
  if (!browserbuf_BM)
    {
      browserbuf_BM = newgui_get_browsebuf_BM ();
      if (!browserbuf_BM)
        return;
    };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows;
    );
  _.objbrows = objbrows;
  int lo = 0, hi = browserobulen_BM, md = 0;
  while (lo + 8 < hi)
    {
      md = (lo + hi) / 2;
      const objectval_tyBM *mdobj = browsedobj_BM[md].brow_obj;
      ASSERT_BM (isobject_BM ((const value_tyBM) mdobj));
      int cmp = objectnamedcmp_BM (mdobj, objbrows);
      if (cmp <= 0)
        lo = md;
      else
        hi = md;
    }
  for (md = lo; md < hi; md++)
    {
      const objectval_tyBM *mdobj = browsedobj_BM[md].brow_obj;
      ASSERT_BM (isobject_BM ((const value_tyBM) mdobj));
      if (mdobj == objbrows)
        {
          GtkTextIter startit = EMPTY_TEXT_ITER_BM, endit =
            EMPTY_TEXT_ITER_BM;
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM, &startit,
                                            browsedobj_BM[md].brow_ostartm);
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM, &endit,
                                            browsedobj_BM[md].brow_oendm);
          gtk_text_iter_forward_char (&endit);
          gtk_text_buffer_delete (browserbuf_BM, &startit, &endit);
          gtk_text_buffer_delete_mark (browserbuf_BM,
                                       browsedobj_BM[md].brow_ostartm);
          gtk_text_buffer_delete_mark (browserbuf_BM,
                                       browsedobj_BM[md].brow_oendm);
          if (browsedobj_BM[md].brow_oparenulen > 0)
            memset (browsedobj_BM[md].brow_oparenarr, 0,
                    browsedobj_BM[md].brow_oparenulen *
                    sizeof (struct parenoffset_stBM));
          free (browsedobj_BM[md].brow_oparenarr);
          memset (&browsedobj_BM[md], 0, sizeof (browsedobj_BM[md]));
          for (int ix = md; ix < (int) browserobulen_BM; ix++)
            browsedobj_BM[ix] = browsedobj_BM[ix + 1];
          memset (&browsedobj_BM[browserobulen_BM], 0,
                  (browserobsize_BM -
                   browserobulen_BM) * sizeof (struct browsedobj_stBM));
          browserobulen_BM--;
          browserobcurix_BM = -1;
          gtk_text_buffer_get_end_iter (browserbuf_BM, &browserit_BM);
          return;
        }
    }
}                               /* end hide_object_gui_BM */


////////////////
void
start_browse_named_value_BM (const stringval_tyBM * namev,
                             const value_tyBM val, int depth)
{
  if (!browserbuf_BM)
    {
      browserbuf_BM = newgui_get_browsebuf_BM ();
      if (!browserbuf_BM)
        return;
    };
  browserobcurix_BM = -1;
  browserblinkstop_BM ();
  if (!isstring_BM ((const value_tyBM) namev))
    FATAL_BM ("no name to start_browse_named_value_BM");
  if (!validname_BM (bytstring_BM ((const value_tyBM) namev)))
    FATAL_BM ("invalid name '%s' to start_browse_named_value_BM",
              bytstring_BM ((const value_tyBM) namev));
  if (!val)
    FATAL_BM
      ("name '%s' for nil value to start_browse_named_value_BM",
       bytstring_BM ((const value_tyBM) namev));
  if (depth < 0)
    FATAL_BM
      ("name '%s' with bad depth %d to start_browse_named_value_BM",
       bytstring_BM ((const value_tyBM) namev), depth);
  if (browsednvulen_BM + 1 >= browsednvsize_BM)
    {
      unsigned newsiz = prime_above_BM (4 * browsednvulen_BM / 3 + 5);
      struct browsedval_stBM *newarr =
        calloc (newsiz, sizeof (struct browsedval_stBM));
      if (!newarr)
        FATAL_BM ("cannot allocated for %d browsed named values", newsiz);
      if (browsednvulen_BM > 0)
        memcpy (newarr, browsedval_BM,
                browsednvulen_BM * sizeof (struct browsedval_stBM));
      free (browsedval_BM), browsedval_BM = newarr;
      browsednvsize_BM = newsiz;
    }
  unsigned lo = 0, hi = browsednvulen_BM, md = 0;
  const char *namstr = bytstring_BM (namev);
  while (lo + 8 < hi)
    {
      md = (lo + hi) / 2;
      ASSERT_BM (isstring_BM
                 ((const value_tyBM) browsedval_BM[md].brow_name));
      int cmp = strcmp (namstr, bytstring_BM (browsedval_BM[md].brow_name));
      if (cmp <= 0)
        lo = md;
      else
        hi = md;
    }
  for (md = lo; md < hi; md++)
    {
      struct browsedval_stBM *mdval = browsedval_BM + md;
      ASSERT_BM (isstring_BM ((const value_tyBM) mdval->brow_name));
      int cmp = strcmp (namstr, bytstring_BM (mdval->brow_name));
      if (cmp == 0)
        {                       /* replace existing named value */
          GtkTextIter startit = EMPTY_TEXT_ITER_BM;
          GtkTextIter endit = EMPTY_TEXT_ITER_BM;
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM,
                                            &startit, mdval->brow_vstartmk);
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM, &endit,
                                            mdval->brow_vendmk);
          gtk_text_buffer_delete (browserbuf_BM, &startit, &endit);
          browserit_BM = endit;
          gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", -1);
          startit = browserit_BM;
          gtk_text_iter_backward_char (&startit);
          gtk_text_buffer_move_mark (browserbuf_BM,
                                     mdval->brow_vstartmk, &startit);
          mdval->brow_vdepth = depth;
          browsednvcurix_BM = md;
          return;
        }
      else if (cmp < 0)
        {                       /* insert a new named value */
          GtkTextIter it = EMPTY_TEXT_ITER_BM;
          if (md > 0)
            {
              gtk_text_buffer_get_iter_at_mark  //
                (browserbuf_BM, &it, mdval[-1].brow_vendmk);;
            }
          else if (browserobulen_BM > 0)
            {
              gtk_text_buffer_get_iter_at_mark  //
                (browserbuf_BM, &it,
                 browsedobj_BM[browserobulen_BM - 1].brow_oendm);
            }
          else
            {
              gtk_text_buffer_get_iter_at_offset        //
                (browserbuf_BM, &it, browserendtitleoffset_BM);
            }
          for (unsigned ix = browsednvulen_BM; ix > md; ix--)
            browsedval_BM[ix] = browsedval_BM[ix - 1];
          memset (mdval, 0, sizeof (*mdval));
          mdval->brow_name = namev;
          mdval->brow_val = val;
          mdval->brow_vdepth = depth;
          gtk_text_buffer_insert (browserbuf_BM, &it, "\n", -1);
          GtkTextIter startit = it;
          gtk_text_iter_backward_char (&startit);
          mdval->brow_vstartmk =        //
            gtk_text_buffer_create_mark (browserbuf_BM, NULL, &startit,
                                         RIGHT_GRAVITY_BM);
          mdval->brow_vendmk =  //
            gtk_text_buffer_create_mark (browserbuf_BM, NULL, &it,
                                         RIGHT_GRAVITY_BM);
          browserit_BM = it;
          browsednvcurix_BM = md;
          return;
        };
    };
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  if (browsednvulen_BM > 0)
    gtk_text_buffer_get_iter_at_mark    //
      (browserbuf_BM, &it, browsedval_BM[browsednvulen_BM - 1].brow_vendmk);
  else if (browserobulen_BM > 0)
    gtk_text_buffer_get_iter_at_mark    //
      (browserbuf_BM, &it, browsedobj_BM[browserobulen_BM - 1].brow_oendm);
  else
    gtk_text_buffer_get_iter_at_offset  //
      (browserbuf_BM, &it, browserendtitleoffset_BM);
  gtk_text_buffer_insert (browserbuf_BM, &it, "\n", -1);
  GtkTextIter startit = it;
  gtk_text_iter_backward_char (&startit);
  browsedval_BM[browsednvulen_BM].brow_name = namev;
  browsedval_BM[browsednvulen_BM].brow_val = val;
  browsedval_BM[browsednvulen_BM].brow_vdepth = depth;
  browsedval_BM[browsednvulen_BM].brow_vstartmk =       //
    gtk_text_buffer_create_mark (browserbuf_BM, NULL, &startit,
                                 RIGHT_GRAVITY_BM);
  browsedval_BM[browsednvulen_BM].brow_vendmk = //
    gtk_text_buffer_create_mark (browserbuf_BM, NULL, &it, RIGHT_GRAVITY_BM);
  browserit_BM = it;
  browsednvcurix_BM = browsednvulen_BM;
  browsednvulen_BM++;
  return;
}                               /* end start_browse_named_value_BM */


struct browsedval_stBM *
find_browsed_named_value_BM (const char *namestr)
{
  if (!namestr || !validname_BM (namestr))
    return NULL;
  unsigned lo = 0, hi = browsednvulen_BM, md = 0;
  while (lo + 8 < hi)
    {
      md = (lo + hi) / 2;
      ASSERT_BM (isstring_BM
                 ((const value_tyBM) browsedval_BM[md].brow_name));
      int cmp = strcmp (namestr, bytstring_BM (browsedval_BM[md].brow_name));
      if (cmp <= 0)
        lo = md;
      else
        hi = md;
    }
  for (md = lo; md < hi; md++)
    {
      struct browsedval_stBM *mdval = browsedval_BM + md;
      ASSERT_BM (isstring_BM ((const value_tyBM) mdval->brow_name));
      if (!strcmp (namestr, bytstring_BM (mdval->brow_name)))
        return mdval;
    };
  return NULL;
}                               /* end find_browsed_named_value_BM */


value_tyBM
find_named_value_gui_BM (const char *namstr)
{
  if (!namstr || !validname_BM (namstr))
    return NULL;
  unsigned lo = 0, hi = browsednvulen_BM, md = 0;
  while (lo + 8 < hi)
    {
      md = (lo + hi) / 2;
      ASSERT_BM (isstring_BM
                 ((const value_tyBM) browsedval_BM[md].brow_name));
      int cmp = strcmp (namstr, bytstring_BM (browsedval_BM[md].brow_name));
      if (cmp <= 0)
        lo = md;
      else
        hi = md;
    }
  for (md = lo; md < hi; md++)
    {
      struct browsedval_stBM *mdval = browsedval_BM + md;
      ASSERT_BM (isstring_BM ((const value_tyBM) mdval->brow_name));
      int cmp = strcmp (namstr, bytstring_BM (mdval->brow_name));
      if (cmp == 0)
        return mdval->brow_val;
    };
  return NULL;
}                               /* end find_named_value_gui_BM */

void
hide_named_value_gui_BM (const stringval_tyBM * namev,
                         struct stackframe_stBM *stkf)
{
  if (!isstring_BM ((const value_tyBM) namev))
    return;
  if (!validname_BM (bytstring_BM ((const value_tyBM) namev)))
    return;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const stringval_tyBM * namev);
  _.namev = namev;
  unsigned lo = 0, hi = browsednvulen_BM, md = 0;
  const char *namstr = bytstring_BM (namev);
  while (lo + 8 < hi)
    {
      md = (lo + hi) / 2;
      ASSERT_BM (isstring_BM
                 ((const value_tyBM) browsedval_BM[md].brow_name));
      int cmp = strcmp (namstr, bytstring_BM (browsedval_BM[md].brow_name));
      if (cmp <= 0)
        lo = md;
      else
        hi = md;
    }
  for (md = lo; md < hi; md++)
    {
      struct browsedval_stBM *mdval = browsedval_BM + md;
      ASSERT_BM (isstring_BM ((const value_tyBM) mdval->brow_name));
      int cmp = strcmp (namstr, bytstring_BM (mdval->brow_name));
      if (cmp == 0)
        {
          GtkTextIter startit = EMPTY_TEXT_ITER_BM;
          GtkTextIter endit = EMPTY_TEXT_ITER_BM;
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM,
                                            &startit, mdval->brow_vstartmk);
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM, &endit,
                                            mdval->brow_vendmk);
          gtk_text_iter_forward_char (&endit);
          gtk_text_buffer_delete (browserbuf_BM, &startit, &endit);
          gtk_text_buffer_delete_mark (browserbuf_BM, mdval->brow_vstartmk);
          gtk_text_buffer_delete_mark (browserbuf_BM, mdval->brow_vendmk);
          if (mdval->brow_vparenulen > 0)
            memset (mdval->brow_vparenarr,
                    0,
                    mdval->brow_vparenulen *
                    sizeof (struct parenoffset_stBM));
          free (mdval->brow_vparenarr);
          for (int ix = md; ix < (int) browsednvulen_BM; ix++)
            browsedval_BM[ix] = browsedval_BM[ix + 1];
          memset (browsedval_BM + browsednvulen_BM, 0,
                  (browsednvsize_BM -
                   browsednvulen_BM) * sizeof (struct browsedval_stBM));
          browsednvulen_BM--;
          browsednvcurix_BM = -1;
          gtk_text_buffer_get_end_iter (browserbuf_BM, &browserit_BM);
          return;
        }
    }
}                               /* end hide_named_value_gui_BM */


int
browse_show_start_offset_BM (void)
{
  if (!browserbuf_BM)
    {
      browserbuf_BM = newgui_get_browsebuf_BM ();
      if (!browserbuf_BM)
        return -1;
    };
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  {
    ASSERT_BM (browserbuf_BM != NULL);
    gtk_text_buffer_get_start_iter (browserbuf_BM, &it);
    return gtk_text_iter_get_offset (&it);
  }
  // exactly one of browserobcurix_BM or browsednvcurix_BM is active so >=0
  ASSERT_BM (browserobcurix_BM >= 0 || browsednvcurix_BM >= 0);
  ASSERT_BM (browserobcurix_BM < 0 || browsednvcurix_BM < 0);
  if (browserobcurix_BM >= 0)
    {
      ASSERT_BM (browserobcurix_BM < (int) browserobulen_BM);
      ASSERT_BM (browserobulen_BM <= browserobsize_BM);
      ASSERT_BM (browsednvcurix_BM < 0);
      ASSERT_BM (browsedobj_BM[browserobcurix_BM].brow_obj != NULL);
      ASSERT_BM (browsedobj_BM[browserobcurix_BM].brow_ostartm != NULL);
      ASSERT_BM (browsedobj_BM[browserobcurix_BM].brow_oendm != NULL);
      gtk_text_buffer_get_iter_at_mark
        (browserbuf_BM, &it, browsedobj_BM[browserobcurix_BM].brow_ostartm);
    }
  else if (browsednvcurix_BM >= 0)
    {
      ASSERT_BM (browsednvcurix_BM < (int) browsednvulen_BM);
      ASSERT_BM (browsednvulen_BM <= browsednvsize_BM);
      ASSERT_BM (browserobcurix_BM < 0);
      ASSERT_BM (browsedval_BM[browsednvcurix_BM].brow_name != NULL);
      ASSERT_BM (browsedval_BM[browsednvcurix_BM].brow_val != NULL);
      ASSERT_BM (browsedval_BM[browsednvcurix_BM].brow_vstartmk != NULL);
      // we don't care about browsedval_BM[browsednvcurix_BM].brow_vendmk; it could be NULL
      gtk_text_buffer_get_iter_at_mark
        (browserbuf_BM, &it, browsedval_BM[browsednvcurix_BM].brow_vstartmk);
    }
  else
    FATAL_BM
      ("browse_show_start_offset_BM corruption browserobcurix_BM=%d browsednvcurix_BM=%d",
       browserobcurix_BM, browsednvcurix_BM);
  return gtk_text_iter_get_offset (&it);
}                               /* end browse_show_start_offset_BM */


void
browse_add_parens_BM (int openoff, int closeoff, int xtraoff,
                      unsigned openlen, unsigned closelen,
                      unsigned xtralen, int depth,
                      struct stackframe_stBM *stkf)
{
  NONPRINTF_BM ("browse_add_parens openoff=%d closeoff=%d xtraoff=%d\n"
                ".. openlen=%u closelen=%u xtralen=%u depth=%d",
                openoff, closeoff, xtraoff,
                openlen, closelen, xtralen, depth);
  ASSERT_BM ((browserobcurix_BM >= 0 && browserobcurix_BM < (int) browserobulen_BM)     //
             || (browsednvcurix_BM >= 0 && browsednvcurix_BM < (int) browsednvulen_BM)  //
             || true);
  if (browserobcurix_BM >= 0)
    {
      ASSERT_BM (browsednvcurix_BM < 0);
      struct browsedobj_stBM *curbrob = browsedobj_BM + browserobcurix_BM;
      unsigned oldulen = curbrob->brow_oparenulen;
      if (oldulen + 1 >= curbrob->brow_oparensize)
        {
          unsigned newsiz = prime_above_BM (5 * oldulen / 4 + 7);
          struct parenoffset_stBM *newarr =
            calloc (newsiz, sizeof (struct parenoffset_stBM));
          if (!newarr)
            FATAL_BM ("calloc failed for %u parens (%m)", newsiz);
          if (oldulen > 0)
            memcpy (newarr, curbrob->brow_oparenarr,
                    oldulen * sizeof (struct parenoffset_stBM));
          free (curbrob->brow_oparenarr), curbrob->brow_oparenarr = newarr;
          curbrob->brow_oparensize = newsiz;
        }
      struct parenoffset_stBM *curpar = curbrob->brow_oparenarr + oldulen;
      curpar->paroff_open = openoff;
      curpar->paroff_close = closeoff;
      curpar->paroff_xtra = xtraoff;
      curpar->paroff_openlen = openlen;
      curpar->paroff_closelen = closelen;
      curpar->paroff_xtralen = xtralen;
      curpar->paroff_depth = depth;
      curbrob->brow_oparenulen = oldulen + 1;
    }
  else if (browsednvcurix_BM >= 0)
    {
      ASSERT_BM (browserobcurix_BM < 0);
      struct browsedval_stBM *curbrval = browsedval_BM + browsednvcurix_BM;
      unsigned oldulen = curbrval->brow_vparenulen;
      if (oldulen + 1 >= curbrval->brow_vparenulen)
        {
          unsigned newsiz = prime_above_BM (5 * oldulen / 4 + 7);
          struct parenoffset_stBM *newarr =
            calloc (newsiz, sizeof (struct parenoffset_stBM));
          if (!newarr)
            FATAL_BM ("calloc failed for %u parens (%m)", newsiz);
          if (oldulen > 0)
            memcpy (newarr, curbrval->brow_vparenarr,
                    oldulen * sizeof (struct parenoffset_stBM));
          free (curbrval->brow_vparenarr), curbrval->brow_vparenarr = newarr;
          curbrval->brow_vparensize = newsiz;
        }
      struct parenoffset_stBM *curpar = curbrval->brow_vparenarr + oldulen;
      curpar->paroff_open = openoff;
      curpar->paroff_close = closeoff;
      curpar->paroff_xtra = xtraoff;
      curpar->paroff_openlen = openlen;
      curpar->paroff_closelen = closelen;
      curpar->paroff_xtralen = xtralen;
      curpar->paroff_depth = depth;
      curbrval->brow_vparenulen = oldulen + 1;
    }
  else
    {
      newgui_browse_add_parens_BM (openoff, closeoff, xtraoff,
                                   openlen, closelen, xtralen, depth, stkf);
    }
}                               /* end browse_add_parens_BM */




static void
browse_object_gui_content_BM (const objectval_tyBM * objbrows,
                              const objectval_tyBM * objsel,
                              int browsdepth, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows;
                 const objectval_tyBM * objsel;
    );
  _.objbrows = objbrows;
  _.objsel = objsel;
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  const char *nambrows = findobjectname_BM (objbrows);
  bool isfocused = (GLOBAL_BM (gui_focus_obj) == objbrows);
  gtk_text_buffer_insert_with_tags      //
    (brobuf, &browserit_BM, "\342\201\202 " /* U+2042 ASTERISM ⁂ */ ,
     -1, isfocused ? focustitle_brotag_BM : objtitle_brotag_BM, NULL);
  char idbuf[32];
  memset (idbuf, 0, sizeof (idbuf));
  idtocbuf32_BM (objid_BM (objbrows), idbuf);
  if (nambrows)
    {
      gtk_text_buffer_insert_with_tags
        (brobuf, &browserit_BM,
         nambrows, -1,
         isfocused ? focustitle_brotag_BM : objtitle_brotag_BM,
         objnametitle_brotag_BM, NULL);
      gtk_text_buffer_insert_with_tags
        (brobuf, &browserit_BM,
         " |=", -1, objtitle_brotag_BM, objcommtitle_brotag_BM, NULL);
      gtk_text_buffer_insert_with_tags (brobuf,
                                        &browserit_BM, idbuf, -1,
                                        isfocused ?
                                        focustitle_brotag_BM :
                                        objtitle_brotag_BM,
                                        objcommtitle_brotag_BM,
                                        objidtitle_brotag_BM, NULL);
      gtk_text_buffer_insert_with_tags (brobuf,
                                        &browserit_BM, "|", -1,
                                        isfocused ?
                                        focustitle_brotag_BM :
                                        objtitle_brotag_BM,
                                        objcommtitle_brotag_BM, NULL);
    }
  else
    {                           /// anonymous browsed object
      gtk_text_buffer_insert_with_tags (brobuf,
                                        &browserit_BM, idbuf, -1,
                                        isfocused ?
                                        focustitle_brotag_BM :
                                        objtitle_brotag_BM,
                                        objidtitle_brotag_BM, NULL);
    };
  gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  send1_BM ((const value_tyBM) objbrows, objsel,
            CURFRAME_BM, taggedint_BM (browsdepth));
  gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  gtk_text_buffer_move_mark (brobuf,
                             browsedobj_BM[browserobcurix_BM].brow_oendm,
                             &browserit_BM);
}                               /* end browse_object_gui_content_BM */

void
browse_object_gui_BM (const objectval_tyBM * objbrows,
                      const objectval_tyBM * objsel,
                      int browsdepth, struct stackframe_stBM *stkf)
{
  if (!isobject_BM ((const value_tyBM) objbrows))
    return;
  if (!isobject_BM ((const value_tyBM) objsel))
    return;
  if (browsdepth < 2)
    browsdepth = 2;
  else if (browsdepth > BROWSE_MAXDEPTH_BM)
    browsdepth = BROWSE_MAXDEPTH_BM;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows;
                 const objectval_tyBM * objsel;
    );
  _.objbrows = objbrows;
  _.objsel = objsel;
  start_browse_object_BM (objbrows, objsel, browsdepth);
  browse_object_gui_content_BM (objbrows, objsel, browsdepth, CURFRAME_BM);
}                               /* end browse_object_gui_BM */


static void
browse_value_gui_content_BM (const stringval_tyBM * namev,
                             const value_tyBM val,
                             const objectval_tyBM * objsel,
                             int browsdepth, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const stringval_tyBM * namev; value_tyBM val;
                 const objectval_tyBM * objsel;
    );
  _.namev = namev;
  _.val = (value_tyBM) val;
  _.objsel = objsel;
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  ASSERT_BM (browsednvcurix_BM >= 0);
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM, "$", -1,
                                    valtitle_brotag_BM, NULL);
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,
                                    bytstring_BM (namev), -1,
                                    valtitle_brotag_BM, NULL);
  gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM, "  \342\234\247"
                                    /* U+2727 WHITE FOUR POINTED STAR ✧ */ ,
                                    -1, objtitle_brotag_BM,
                                    // objcommtitle_brotag_BM,
                                    NULL);
  {
    char hcombuf[32];
    memset (hcombuf, 0, sizeof (hcombuf));
    snprintf (hcombuf, sizeof (hcombuf), " |h:%u|", valhash_BM (val));
    gtk_text_buffer_insert_with_tags (brobuf, &browserit_BM,
                                      hcombuf, -1,
                                      objcommtitle_brotag_BM, NULL);
  }
  gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  send2_BM ((const value_tyBM) _.val, objsel, CURFRAME_BM,
            taggedint_BM (browsdepth), taggedint_BM (0));
  gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", -1);
  gtk_text_buffer_move_mark (brobuf,
                             browsedval_BM[browsednvcurix_BM].brow_vendmk,
                             &browserit_BM);
}                               /* end browse_value_gui_content_BM */

void
browse_named_value_gui_BM (const stringval_tyBM * namev,
                           const value_tyBM val,
                           const objectval_tyBM * objsel,
                           int browsdepth, struct stackframe_stBM *stkf)
{
  if (!isstring_BM ((const value_tyBM) namev))
    return;
  if (!isobject_BM ((const value_tyBM) objsel))
    return;
  if (!val)
    return;
  if (browsdepth < 2)
    browsdepth = 2;
  else if (browsdepth > BROWSE_MAXDEPTH_BM)
    browsdepth = BROWSE_MAXDEPTH_BM;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const stringval_tyBM * namev; value_tyBM val;
                 const objectval_tyBM * objsel;
    );
  _.namev = namev;
  _.val = (value_tyBM) val;
  _.objsel = objsel;
  browsednvcurix_BM = -1;
  start_browse_named_value_BM (namev, val, browsdepth);
  browse_value_gui_content_BM (namev, val, objsel, browsdepth, CURFRAME_BM);
}                               /* end browse_named_value_gui_BM */




void
refresh_browse_BM (struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows;
                 const objectval_tyBM * objsel;
                 value_tyBM valbrows; const stringval_tyBM * valname;);
  DBGPRINTF_BM ("refresh_browse_BM start");
  browserblinkstop_BM ();
  /// reinitialize the browsed objects
  for (unsigned boix = 0; boix < browserobulen_BM; boix++)
    {
      struct browsedobj_stBM *curbrob = browsedobj_BM + boix;
      gtk_text_buffer_delete_mark (browserbuf_BM, curbrob->brow_ostartm),
        curbrob->brow_ostartm = NULL;
      gtk_text_buffer_delete_mark (browserbuf_BM, curbrob->brow_oendm),
        curbrob->brow_oendm = NULL;
      memset (curbrob->brow_oparenarr, 0,
              curbrob->brow_oparensize * sizeof (struct parenoffset_stBM));
      curbrob->brow_oparenulen = 0;
    }
  /// reinitialize the browsed named values
  for (unsigned bvix = 0; bvix < browsednvulen_BM; bvix++)
    {
      struct browsedval_stBM *curbval = browsedval_BM + bvix;
      gtk_text_buffer_delete_mark (browserbuf_BM, curbval->brow_vstartmk),
        curbval->brow_vstartmk = NULL;
      gtk_text_buffer_delete_mark (browserbuf_BM, curbval->brow_vendmk),
        curbval->brow_vendmk = NULL;
      memset (curbval->brow_vparenarr, 0,
              curbval->brow_vparensize * sizeof (struct parenoffset_stBM));
      curbval->brow_vparenulen = 0;
    }
  gtk_text_buffer_set_text (browserbuf_BM, "", 0);
  {
    GtkTextIter brit = EMPTY_TEXT_ITER_BM;
    GtkTextIter endtit = EMPTY_TEXT_ITER_BM;
    gtk_text_buffer_get_start_iter (browserbuf_BM, &brit);
    gtk_text_buffer_insert_with_tags (browserbuf_BM, &brit, "** BROWSER **",
                                      -1, pagetitle_brotag_BM, NULL);
    gtk_text_buffer_insert (browserbuf_BM, &brit, "\n\n", 2);
    endtit = brit;
    browserit_BM = brit;
    gtk_text_iter_backward_char (&endtit);
    browserendtitleoffset_BM =  //
      gtk_text_iter_get_offset (&endtit);
  }
  DBGPRINTF_BM ("refreshing initial browserit:%s",
                textiterstrdbg_BM (&browserit_BM));
  /// redisplay objects
  for (unsigned boix = 0; boix < browserobulen_BM; boix++)
    {
      gtk_text_buffer_get_end_iter (browserbuf_BM, &browserit_BM);
      DBGPRINTF_BM ("refreshing boix#%d browserit:%s",
                    boix, textiterstrdbg_BM (&browserit_BM));
      GtkTextIter it = browserit_BM;
      struct browsedobj_stBM *curbrob = browsedobj_BM + boix;
      _.objbrows = curbrob->brow_obj;
      _.objsel = curbrob->brow_objsel;
      int curdepth = curbrob->brow_odepth;
      ASSERT_BM (isobject_BM ((value_tyBM) _.objbrows));
      ASSERT_BM (isobject_BM ((value_tyBM) _.objsel));
      browserobcurix_BM = boix;
      GtkTextIter startit = it;
      gtk_text_buffer_insert (browserbuf_BM, &it, "\n", -1);
      startit = it;
      gtk_text_iter_backward_char (&startit);
      curbrob->brow_ostartm =   //
        gtk_text_buffer_create_mark (browserbuf_BM, NULL, &startit,
                                     RIGHT_GRAVITY_BM);
      curbrob->brow_oendm =     //
        gtk_text_buffer_create_mark (browserbuf_BM, NULL, &it,
                                     RIGHT_GRAVITY_BM);
      gtk_text_buffer_get_end_iter (browserbuf_BM, &browserit_BM);
      browse_object_gui_content_BM (_.objbrows, _.objsel, curdepth,
                                    CURFRAME_BM);
      DBGPRINTF_BM ("refreshed boix#%d browserit:%s",
                    boix, textiterstrdbg_BM (&browserit_BM));
      browserobcurix_BM = -1;
      _.objbrows = NULL;
      _.objsel = NULL;
    }
  DBGPRINTF_BM ("refreshing before values browserit:%s",
                textiterstrdbg_BM (&browserit_BM));
  /// then redisplay named values
  for (unsigned bvix = 0; bvix < browsednvulen_BM; bvix++)
    {
      gtk_text_buffer_get_end_iter (browserbuf_BM, &browserit_BM);
      DBGPRINTF_BM ("refreshing bvix#%d browserit:%s",
                    bvix, textiterstrdbg_BM (&browserit_BM));
      GtkTextIter it = browserit_BM;
      struct browsedval_stBM *curbval = browsedval_BM + bvix;
      _.valbrows = curbval->brow_val;
      _.valname = curbval->brow_name;
      browsednvcurix_BM = bvix;
      GtkTextIter startit = it;
      gtk_text_buffer_insert (browserbuf_BM, &it, "\n", -1);
      startit = it;
      gtk_text_iter_backward_char (&startit);
      curbval->brow_vstartmk =  //
        gtk_text_buffer_create_mark (browserbuf_BM, NULL, &startit,
                                     RIGHT_GRAVITY_BM);
      curbval->brow_vendmk =    //
        gtk_text_buffer_create_mark (browserbuf_BM, NULL, &it,
                                     RIGHT_GRAVITY_BM);
      gtk_text_buffer_get_end_iter (browserbuf_BM, &browserit_BM);
      browse_value_gui_content_BM (_.valname, _.valbrows,
                                   BMP_gtk_browse_value, curbval->brow_vdepth,
                                   CURFRAME_BM);
      DBGPRINTF_BM ("refreshed bvix#%d browserit:%s", bvix,
                    textiterstrdbg_BM (&browserit_BM));
      browsednvcurix_BM = -1;
      _.valbrows = NULL;
    };
  DBGPRINTF_BM ("end refresh_browse_BM %d objects, %d named values, %s",
                browserobulen_BM, browsednvulen_BM,
                textiterstrdbg_BM (&browserit_BM));
  gtk_text_buffer_get_end_iter (browserbuf_BM, &browserit_BM);
#warning check that refresh_browse_BM is good
}                               /* end refresh_browse_BM */


static bool unconfirmdebugdump_BM (const char *reason);

void
quitgui_BM (void)
{
  //  printf ("quitgui_BM\n");
  DBGPRINTF_BM ("quitgui start tid#%ld", (long) gettid_BM ());
  GtkWidget *quitdialog =       //
    gtk_message_dialog_new_with_markup  //
    (GTK_WINDOW (mainwin_BM),
     GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_QUESTION,
     GTK_BUTTONS_OK_CANCEL, "Quit without dumping?");
  int resp = gtk_dialog_run (GTK_DIALOG (quitdialog));
  DBGPRINTF_BM ("quitgui  tid#%ld resp=%d %s", (long) gettid_BM (),
                resp, (resp == GTK_RESPONSE_OK) ? "ok" : "...");
  if (resp == GTK_RESPONSE_OK)
    {
      gtk_main_quit ();
      if (gui_command_log_file_BM)
        {
          time_t nowtim = time (NULL);
          struct tm nowtm = { };
          localtime_r (&nowtim, &nowtm);
          char nowbuf[64];
          memset (nowbuf, 0, sizeof (nowbuf));
          strftime (nowbuf, sizeof (nowbuf), "%c", &nowtm);
          fprintf (gui_command_log_file_BM, "\n//// quit at %s\n\n", nowbuf);
          fflush (gui_command_log_file_BM);
        }
    }
  gtk_widget_destroy (quitdialog);
  DBGPRINTF_BM ("quitgui end tid#%ld", (long) gettid_BM ());
}                               /* end quitgui_BM */

void
exitgui_BM (void)
{
  DBGPRINTF_BM ("exitgui start tid#%ld elapsed %.3f s",
                (long) gettid_BM (), elapsedtime_BM ());
  extern char *dump_dir_bm;
  if (debugmsg_BM && unconfirmdebugdump_BM ("exit"))
    return;
  struct dumpinfo_stBM di = dump_BM (dump_dir_BM, NULL);
  gtk_main_quit ();
  if (gui_command_log_file_BM)
    {
      time_t nowtim = time (NULL);
      struct tm nowtm = { };
      localtime_r (&nowtim, &nowtm);
      char nowbuf[64];
      memset (nowbuf, 0, sizeof (nowbuf));
      strftime (nowbuf, sizeof (nowbuf), "%c", &nowtm);
      fprintf (gui_command_log_file_BM,
               "\n//// at exit dumped %ld objects, %ld files to %s at %s\n\n",
               di.dumpinfo_emittedobjectcount, di.dumpinfo_wrotefilecount,
               dump_dir_BM, nowbuf);
      fflush (gui_command_log_file_BM);
    }
  DBGPRINTF_BM ("exitgui end tid#%ld elapsed %.3f s",
                (long) gettid_BM (), elapsedtime_BM ());
}                               /* end exitgui_BM */


void
dumpgui_BM (void)
{
  DBGPRINTF_BM ("dumpgui start tid#%ld", (long) gettid_BM ());
  ASSERT_BM (dump_dir_BM != NULL);
  if (debugmsg_BM && unconfirmdebugdump_BM ("dump"))
    return;
  log_begin_message_BM ();
  log_printf_message_BM ("dumping into %s directory", dump_dir_BM);
  {
    char *rd = realpath (dump_dir_BM, NULL);
    if (rd)
      {
        log_printf_message_BM (" (%s)", rd);
        free (rd), rd = NULL;
      }
  }
  log_puts_message_BM (".\n");
  struct dumpinfo_stBM di = dump_BM (dump_dir_BM, NULL);
  log_printf_message_BM ("dump: scanned %ld, emitted %ld objects\n",
                         di.dumpinfo_scanedobjectcount,
                         di.dumpinfo_emittedobjectcount);
  log_printf_message_BM ("did %ld todos, wrote %ld files\n",
                         di.dumpinfo_todocount, di.dumpinfo_wrotefilecount);
  log_printf_message_BM ("in %.3f elapsed, %.4f cpu seconds.\n",
                         di.dumpinfo_elapsedtime, di.dumpinfo_cputime);
  log_end_message_BM ();
  if (gui_command_log_file_BM)
    {
      time_t nowtim = time (NULL);
      struct tm nowtm = { };
      localtime_r (&nowtim, &nowtm);
      char nowbuf[64];
      memset (nowbuf, 0, sizeof (nowbuf));
      char *rd = realpath (dump_dir_BM, NULL);
      strftime (nowbuf, sizeof (nowbuf), "%c", &nowtm);
      fprintf (gui_command_log_file_BM,
               "\n////! dumped %ld objects, %ld files to %s i.e. %s at %s\n\n",
               di.dumpinfo_emittedobjectcount, di.dumpinfo_wrotefilecount,
               dump_dir_BM, rd, nowbuf);
      free (rd);
      fflush (gui_command_log_file_BM);
    }
  DBGPRINTF_BM ("dumpgui end tid#%ld", (long) gettid_BM ());
}                               /* end dumpgui_BM */




bool
unconfirmdebugdump_BM (const char *reason)
{
  bool result = false;
  DBGPRINTF_BM ("unconfirmdebugdump reason='%s' start", reason);
  GtkWidget *confirmdialog =    //
    gtk_message_dialog_new_with_markup  //
    (GTK_WINDOW (mainwin_BM),
     GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_QUESTION,
     GTK_BUTTONS_OK_CANCEL, "Confirm dumping with debug for %s?", reason);
  int resp = gtk_dialog_run (GTK_DIALOG (confirmdialog));
  time_t nowtim = time (NULL);
  struct tm nowtm = { };
  localtime_r (&nowtim, &nowtm);
  char nowbuf[64];
  memset (nowbuf, 0, sizeof (nowbuf));
  strftime (nowbuf, sizeof (nowbuf), "%c", &nowtm);
  if (resp == GTK_RESPONSE_OK)
    {
      log_begin_message_BM ();
      log_printf_message_BM ("confirmed debug dump for '%s'", reason);
      log_end_message_BM ();
      if (gui_command_log_file_BM)
        {
          fprintf (gui_command_log_file_BM,
                   "\n//// confirmed debug dump '%s' at %s\n\n", nowbuf,
                   reason);
          fflush (gui_command_log_file_BM);
        }
    }
  else
    {
      log_begin_message_BM ();
      log_printf_message_BM ("cancelled debug dump for '%s'", reason);
      log_end_message_BM ();
      if (gui_command_log_file_BM)
        {
          fprintf (gui_command_log_file_BM,
                   "\n//// cancelled debug dump '%s' at %s\n\n", nowbuf,
                   reason);
          fflush (gui_command_log_file_BM);
        }
      result = true;
    }
  gtk_widget_destroy (confirmdialog);
  return result;
}                               /* end unconfirmdebugdump_BM */




void
garbage_collect_from_gui_BM (void)
{
  DBGPRINTF_BM ("garbage_collect_from_gui start tid#%ld",
                (long) gettid_BM ());
  ASSERT_BM (mainthreadid_BM == pthread_self ());
  if (debugmsg_BM)
    {
      GtkWidget *confirmdialog =        //
        gtk_message_dialog_new_with_markup      //
        (GTK_WINDOW (mainwin_BM),
         GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
         GTK_MESSAGE_QUESTION,
         GTK_BUTTONS_OK_CANCEL, "Confirm garbage collection with debug?");
      int resp = gtk_dialog_run (GTK_DIALOG (confirmdialog));
      gtk_widget_destroy (confirmdialog);
      if (resp != GTK_RESPONSE_OK)
        {
          log_begin_message_BM ();
          log_printf_message_BM ("cancelled debug garbage collection");
          log_end_message_BM ();
          if (gui_command_log_file_BM)
            {
              time_t nowtim = time (NULL);
              struct tm nowtm = { };
              localtime_r (&nowtim, &nowtm);
              char nowbuf[64];
              memset (nowbuf, 0, sizeof (nowbuf));
              strftime (nowbuf, sizeof (nowbuf), "%c", &nowtm);
              fprintf (gui_command_log_file_BM,
                       "\n//// cancelled GUI debug garbage collection at %s\n\n",
                       nowbuf);
              fflush (gui_command_log_file_BM);
            };
          return;
        }
    }
  log_begin_message_BM ();
  request_delayed_garbage_collection_BM ();
  log_puts_message_BM ("forced garbage collection");
  log_end_message_BM ();
  full_garbage_collection_BM (NULL);
  DBGPRINTF_BM ("garbage_collect_from_gui end tid#%ld", (long) gettid_BM ());
}                               /* end garbage_collect_from_gui_BM */

bool
deletemainwin_BM (GtkWidget * widget __attribute__((unused)),   //
                  GdkEvent * ev __attribute__((unused)),        //
                  gpointer data __attribute__((unused)))
{
  // printf ("deletemainwin_BM\n");
  DBGPRINTF_BM ("deletemainwin_BM tid#%ld", (long) gettid_BM ());
  GtkWidget *quitdialog =       //
    gtk_message_dialog_new_with_markup  //
    (GTK_WINDOW (mainwin_BM),
     GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
     GTK_MESSAGE_QUESTION,
     GTK_BUTTONS_OK_CANCEL,
     "Quit (after delete) without dumping?");
  int resp = gtk_dialog_run (GTK_DIALOG (quitdialog));
  if (resp == GTK_RESPONSE_OK)
    {
      gtk_main_quit ();
      gtk_widget_destroy (quitdialog);
      return false;             // to let the window be destroyed
    }
  else
    {
      gtk_widget_destroy (quitdialog);
      return true;
    }
}                               /* end deletemainwin_BM */

void
gui_gc_message_BM (const char *msg)
{
  log_begin_message_BM ();
  log_puts_message_BM (msg);
  log_end_message_BM ();
}                               /* end gui_gc_message_BM */

void
gtk_log_begin_message_BM (void)
{
  static long logcnt;
  logcnt++;
  double now = clocktime_BM (CLOCK_REALTIME);
  time_t nowt = (time_t) floor (now);
  double nowfrac = now - (double) nowt;
  struct tm nowtm = {
  };
  localtime_r (&nowt, &nowtm);
  char nowtibuf[40];
  memset (nowtibuf, 0, sizeof (nowtibuf));
  strftime (nowtibuf, sizeof (nowtibuf), "%T", &nowtm);
  char nowfracbuf[8];
  memset (nowfracbuf, 0, sizeof (nowfracbuf));
  snprintf (nowfracbuf, sizeof (nowfracbuf), "%.2f", nowfrac);
  char nowcntbuf[16];
  memset (nowcntbuf, 0, sizeof (nowcntbuf));
  snprintf (nowcntbuf, sizeof (nowcntbuf), " #%ld", logcnt);
  char logmbuf[80];
  memset (logmbuf, 0, sizeof (logmbuf));
  snprintf (logmbuf, sizeof (logmbuf), "%s%s%s", nowtibuf,
            nowfracbuf + 1, nowcntbuf);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_end_iter (logbuf_BM, &it);
  gtk_text_buffer_insert (logbuf_BM, &it, "\n", 1);
  gtk_text_buffer_insert_with_tags (logbuf_BM, &it, logmbuf, -1,
                                    time_logtag_BM, NULL);
  gtk_text_buffer_insert (logbuf_BM, &it, "\n", 1);
}                               /* end log_begin_message_BM */


void
gtk_log_end_message_BM (void)
{
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_end_iter (logbuf_BM, &it);
  gtk_text_buffer_insert (logbuf_BM, &it, "\n", 1);
  gtk_text_view_scroll_to_iter (GTK_TEXT_VIEW (logview_BM),
                                &it, 0.1, false, 0.3, 0.92);
}                               /* end log_end_message_BM */


void
gtk_log_object_message_BM (const objectval_tyBM * obj)
{
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_end_iter (logbuf_BM, &it);
  if (!obj)
    {
      gtk_text_buffer_insert (logbuf_BM, &it, "__", 2);
      return;
    };
  if (valtype_BM ((const value_tyBM) obj) != tyObject_BM)
    FATAL_BM ("invalid argument @%p to log_object_message_BM", obj);
  const char *objname = findobjectname_BM (obj);
  char idbuf[32];
  memset (idbuf, 0, sizeof (idbuf));
  idtocbuf32_BM (objid_BM (obj), idbuf);
  if (objname)
    {
      gtk_text_buffer_insert_with_tags
        (logbuf_BM, &it, objname, -1, name_logtag_BM, NULL);
      gtk_text_buffer_insert (logbuf_BM, &it, " |=", -1);
      gtk_text_buffer_insert_with_tags
        (logbuf_BM, &it, idbuf, -1, id_logtag_BM, NULL);
      gtk_text_buffer_insert (logbuf_BM, &it, "|", -1);
    }
  else
    {
      gtk_text_buffer_insert_with_tags
        (logbuf_BM, &it, idbuf, -1, id_logtag_BM, NULL);
    }
}                               /* end log_object_message_BM */

void
gtk_log_puts_message_BM (const char *msg)
{
  if (!msg || !msg[0])
    return;
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_end_iter (logbuf_BM, &it);
  gtk_text_buffer_insert (logbuf_BM, &it, msg, -1);
}                               /* end log_puts_message_BM */


void
browsenewlinefordepth_BM (int depth)
{
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  gtk_text_buffer_insert (brobuf, &browserit_BM, "\n", 1);
  gtk_text_buffer_insert (brobuf, &browserit_BM, "                ",
                          (depth & 0xf));
}                               /* end browsenewlinefordepth_BM */


void
browsespacefordepth_BM (int depth)
{
  if (gtk_text_iter_get_line_offset (&browserit_BM) > 64)
    browsenewlinefordepth_BM (depth);
  else
    {
      GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
      gtk_text_buffer_insert (brobuf, &browserit_BM, " ", 1);
    };
}                               /* end browsespacefordepth_BM */


void
browse_value_BM (const value_tyBM val,
                 struct stackframe_stBM *stkf, int maxdepth, int curdepth)
{
  GtkTextBuffer *brobuf = gtk_text_iter_get_buffer (&browserit_BM);
  if (!val)
    gtk_text_buffer_insert_with_tags (brobuf,
                                      &browserit_BM, "__", 2,
                                      nest_brotag_BM, NULL);
  else
    {
      LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                     value_tyBM val);
      _.val = val;
      send2_BM ((const value_tyBM) _.val, BMP_gtk_browse_value,
                CURFRAME_BM,
                taggedint_BM (maxdepth), taggedint_BM (curdepth));
    }
}                               /* end browse_value_BM */

//// end of file guibrowse_GTKBM.c
