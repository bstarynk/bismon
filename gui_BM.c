// file gui_BM.c

/***
    BISMON 
    Copyright © 2018 Basile Starynkevitch (working at CEA, LIST, France)
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
#include "gui_BM.const.h"

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

#define BLINKDELAYMILLISEC_BM 750
#define UNBLINKDELAYMILLISEC_BM 400

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
/// stop completely the blinking
static void browserblinkstop_BM (void);

// unblink temporarily
static int browserblinkoff_BM (gpointer);
// blink temporarily
static int browserblinkon_BM (gpointer);

// start the blinking
static void browserblinkstart_BM (void);


/// the completion set - should be a GC root
const seqobval_tyBM *complseqcmd_BM;
/// begin and end offset for completion replacement
int compbegoffcmd_BM, compendoffcmd_BM;
char *complcommonprefix_BM;
bool complbyid_BM;

// browse the named value
static void browse_named_value_gui_BM (const stringval_tyBM * namev,
                                       const value_tyBM val,
                                       const objectval_tyBM * objsel,
                                       int browsdepth,
                                       struct stackframe_stBM *stkf);
// hide the named value
static void hide_named_value_gui_BM (const stringval_tyBM * namev,
                                     struct stackframe_stBM *stkf);

// find the named value
static value_tyBM find_named_value_gui_BM (const char *name);


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



static void start_browse_object_BM (const objectval_tyBM * obj,
                                    const objectval_tyBM * objsel, int depth);

static void start_browse_named_value_BM (const stringval_tyBM * namev,
                                         const value_tyBM val, int depth);


static void refresh_browse_BM (struct stackframe_stBM *);

static void runcommand_BM (bool erase);
static void run_then_erase_command_BM (void);
static void run_then_keep_command_BM (void);
static void marksetcmd_BM (GtkTextBuffer *, GtkTextIter *, GtkTextMark *,
                           gpointer);
static void marksetbrows_BM (GtkTextBuffer *, GtkTextIter *, GtkTextMark *,
                             gpointer);

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
gcmarkoldgui_BM (struct garbcoll_stBM *gc)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  if (browsedobj_BM)
    {
      for (unsigned ix = 0; ix < browserobulen_BM; ix++)
        {
          gcobjmark_BM (gc, browsedobj_BM[ix].brow_obj);
          gcobjmark_BM (gc, browsedobj_BM[ix].brow_objsel);
        }
    };
  if (browsedval_BM)
    {
      for (unsigned ix = 0; ix < browsednvulen_BM; ix++)
        {
          VALUEGCPROC_BM (gc, browsedval_BM[ix].brow_val, 0);
          VALUEGCPROC_BM (gc, browsedval_BM[ix].brow_name, 0);
        }
    }
  if (complseqcmd_BM)
    VALUEGCPROC_BM (gc, complseqcmd_BM, 0);
}                               /* end gcmarkoldgui_BM */



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




const char *
gobjectclassnamedbg_BM (GObject * ptr)
{
  if (!ptr)
    return "*nil*";
  return G_OBJECT_CLASS_NAME (G_OBJECT_GET_CLASS (ptr));
}                               /* end gobjectclassnamedbg_BM */



////////////////////////////////////////////////////////////////


void
browserblinkstop_BM (void)
{
  if (browserblinkid_BM > 0)
    g_source_remove (browserblinkid_BM), browserblinkid_BM = 0;
  browserblinkoff_BM (NULL);
}                               /* end browserblinkstop_BM */

int
browserblinkoff_BM (gpointer data __attribute__ ((unused)))
{
  GtkTextIter startit = EMPTY_TEXT_ITER_BM;
  GtkTextIter endit = EMPTY_TEXT_ITER_BM;
  if (!browserbuf_BM)
    {
      if (!oldgui_BM)
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
browserblinkon_BM (gpointer data __attribute__ ((unused)))
{
  if (browserblinkparens_BM.paroff_open > 0
      && browserblinkparens_BM.paroff_openlen > 0)
    {
      GtkTextIter openstartit = EMPTY_TEXT_ITER_BM;
      GtkTextIter openendit = EMPTY_TEXT_ITER_BM;
      if (!browserbuf_BM)
        {
          if (!oldgui_BM)
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
      if (!oldgui_BM)
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
      if (!oldgui_BM)
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
      if (!oldgui_BM)
        browserbuf_BM = newgui_get_browsebuf_BM ();
      if (!browserbuf_BM)
        return;
    };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows;);
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
      if (!oldgui_BM)
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
      if (!oldgui_BM)
        browserbuf_BM = newgui_get_browsebuf_BM ();
      if (!browserbuf_BM)
        return -1;
    };
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  if (!oldgui_BM)
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
             || !oldgui_BM);
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
  else if (!oldgui_BM)
    {
      newgui_browse_add_parens_BM (openoff, closeoff, xtraoff,
                                   openlen, closelen, xtralen, depth, stkf);
    }
  else
    FATAL_BM ("no browsed object or named value");
}                               /* end browse_add_parens_BM */




static void
browse_object_gui_content_BM (const objectval_tyBM * objbrows,
                              const objectval_tyBM * objsel,
                              int browsdepth, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows;
                 const objectval_tyBM * objsel;);
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
            (struct stackframe_stBM *) &_, taggedint_BM (browsdepth));
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
                 const objectval_tyBM * objsel;);
  _.objbrows = objbrows;
  _.objsel = objsel;
  start_browse_object_BM (objbrows, objsel, browsdepth);
  browse_object_gui_content_BM (objbrows, objsel, browsdepth,
                                (struct stackframe_stBM *) &_);
}                               /* end browse_object_gui_BM */


static void
browse_value_gui_content_BM (const stringval_tyBM * namev,
                             const value_tyBM val,
                             const objectval_tyBM * objsel,
                             int browsdepth, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const stringval_tyBM * namev;
                 value_tyBM val; const objectval_tyBM * objsel;);
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
  send2_BM ((const value_tyBM) _.val, objsel, (struct stackframe_stBM *) &_,
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
                 const stringval_tyBM * namev;
                 value_tyBM val; const objectval_tyBM * objsel;);
  _.namev = namev;
  _.val = (value_tyBM) val;
  _.objsel = objsel;
  browsednvcurix_BM = -1;
  start_browse_named_value_BM (namev, val, browsdepth);
  browse_value_gui_content_BM (namev, val, objsel, browsdepth,
                               (struct stackframe_stBM *) &_);
}                               /* end browse_named_value_gui_BM */




void
refresh_browse_BM (struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows;
                 const objectval_tyBM * objsel; value_tyBM valbrows;
                 const stringval_tyBM * valname;
    );
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
                                    (struct stackframe_stBM *) &_);
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
      browse_value_gui_content_BM (_.valname, _.valbrows, BMP_browse_value,
                                   curbval->brow_vdepth,
                                   (struct stackframe_stBM *) &_);
      DBGPRINTF_BM ("refreshed bvix#%d browserit:%s",
                    bvix, textiterstrdbg_BM (&browserit_BM));
      browsednvcurix_BM = -1;
      _.valbrows = NULL;
    };
  DBGPRINTF_BM ("end refresh_browse_BM %d objects, %d named values, %s",
                browserobulen_BM, browsednvulen_BM,
                textiterstrdbg_BM (&browserit_BM));
  gtk_text_buffer_get_end_iter (browserbuf_BM, &browserit_BM);
#warning check that refresh_browse_BM is good
}                               /* end refresh_browse_BM */

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
  struct dumpinfo_stBM di = dump_BM (dump_dir_bm, NULL);
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
               dump_dir_bm, nowbuf);
      fflush (gui_command_log_file_BM);
    }
  DBGPRINTF_BM ("exitgui end tid#%ld elapsed %.3f s",
                (long) gettid_BM (), elapsedtime_BM ());
}                               /* end exitgui_BM */


void
dumpgui_BM (void)
{
  DBGPRINTF_BM ("dumpgui start tid#%ld", (long) gettid_BM ());
  extern char *dump_dir_bm;
  ASSERT_BM (dump_dir_bm != NULL);
  log_begin_message_BM ();
  log_printf_message_BM ("dumping into %s directory", dump_dir_bm);
  {
    char *rd = realpath (dump_dir_bm, NULL);
    if (rd)
      {
        log_printf_message_BM (" (%s)", rd);
        free (rd), rd = NULL;
      }
  }
  log_puts_message_BM (".\n");
  struct dumpinfo_stBM di = dump_BM (dump_dir_bm, NULL);
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
      strftime (nowbuf, sizeof (nowbuf), "%c", &nowtm);
      fprintf (gui_command_log_file_BM,
               "\n//// dumped %ld objects, %ld files to %s at %s\n\n",
               di.dumpinfo_emittedobjectcount, di.dumpinfo_wrotefilecount,
               dump_dir_bm, nowbuf);
      fflush (gui_command_log_file_BM);
    }
  DBGPRINTF_BM ("dumpgui end tid#%ld", (long) gettid_BM ());
}                               /* end dumpgui_BM */

void
garbcollgui_BM (void)
{
  DBGPRINTF_BM ("garbcollgui start tid#%ld", (long) gettid_BM ());
  ASSERT_BM (mainthreadid_BM == pthread_self ());
  log_begin_message_BM ();
  atomic_store (&want_garbage_collection_BM, true);
  log_puts_message_BM ("forced garbage collection");
  log_end_message_BM ();
  full_garbage_collection_BM (NULL);
  DBGPRINTF_BM ("garbcollgui end tid#%ld", (long) gettid_BM ());
}                               /* end garbcollgui_BM */

bool
deletemainwin_BM (GtkWidget * widget __attribute__ ((unused)),  //
                  GdkEvent * ev __attribute__ ((unused)),       //
                  gpointer data __attribute__ ((unused)))
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
log_begin_message_BM (void)
{
  static long logcnt;
  logcnt++;
  double now = clocktime_BM (CLOCK_REALTIME);
  time_t nowt = (time_t) floor (now);
  double nowfrac = now - (double) nowt;
  struct tm nowtm = {
  };
  localtime_r (&nowt, &nowtm);
  char nowtibuf[32];
  memset (nowtibuf, 0, sizeof (nowtibuf));
  strftime (nowtibuf, sizeof (nowtibuf), "%T", &nowtm);
  char nowfracbuf[8];
  memset (nowfracbuf, 0, sizeof (nowfracbuf));
  snprintf (nowfracbuf, sizeof (nowfracbuf), "%.2f", nowfrac);
  char nowcntbuf[16];
  memset (nowcntbuf, 0, sizeof (nowcntbuf));
  snprintf (nowcntbuf, sizeof (nowcntbuf), " #%ld", logcnt);
  char logmbuf[64];
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
log_end_message_BM (void)
{
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_end_iter (logbuf_BM, &it);
  gtk_text_buffer_insert (logbuf_BM, &it, "\n", 1);
}                               /* end log_end_message_BM */


void
log_object_message_BM (const objectval_tyBM * obj)
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
log_puts_message_BM (const char *msg)
{
  if (!msg || !msg[0])
    return;
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_end_iter (logbuf_BM, &it);
  gtk_text_buffer_insert (logbuf_BM, &it, msg, -1);
}                               /* end log_puts_message_BM */

void
log_printf_message_BM (const char *fmt, ...)
{
  char smallbuf[64];
  memset (smallbuf, 0, sizeof (smallbuf));
  va_list args;
  char *buf = smallbuf;
  va_start (args, fmt);
  int ln = vsnprintf (smallbuf, sizeof (smallbuf), fmt, args);
  va_end (args);
  if (ln >= (int) sizeof (smallbuf) - 1)
    {
      buf = calloc ((prime_above_BM (ln + 2) | 7) + 1, 1);
      if (!buf)
        FATAL_BM ("failed to calloc for %d bytes (%m)", ln);
      va_start (args, fmt);
      vsnprintf (buf, ln + 1, fmt, args);
      va_end (args);
    }
  log_puts_message_BM (buf);
  if (buf != smallbuf)
    free (buf);
}                               /* end log_printf_message_BM */

void
parserror_guicmd_BM (struct parser_stBM *pars, struct stackframe_stBM *stkf,
                     unsigned lineno, unsigned colpos, char *msg)
{
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  bool nobuild = parsops && parsops->parsop_nobuild;
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_end_iter (commandbuf_BM, &endit);
  gtk_text_buffer_apply_tag (commandbuf_BM, errored_cmdtag_BM, &it, &endit);
  if (!nobuild)
    {
      log_begin_message_BM ();
      char errbuf[64];
      snprintf (errbuf, sizeof (errbuf), "command error L%dC%d:",
                lineno, colpos);
      GtkTextIter logit = EMPTY_TEXT_ITER_BM;
      gtk_text_buffer_get_end_iter (logbuf_BM, &logit);
      gtk_text_buffer_insert_with_tags
        (logbuf_BM, &logit, errbuf, -1, error_logtag_BM, NULL);
      log_puts_message_BM (msg);
      log_end_message_BM ();
      gtk_text_view_scroll_to_iter (GTK_TEXT_VIEW (commandview_BM),
                                    &it, 0.1, false, 0.5, 0.2);
      errormessagedialog_BM = gtk_message_dialog_new_with_markup        //
        (GTK_WINDOW (mainwin_BM),
         GTK_DIALOG_DESTROY_WITH_PARENT,
         GTK_MESSAGE_ERROR,
         GTK_BUTTONS_CLOSE,
         "<b>command error</b> L%dC%d:\n" "%s", lineno, colpos, msg);
      gtk_widget_show_all (errormessagedialog_BM);
      fflush (NULL);
      /// errormessagedialog_BM is run in runcommand_BM 
    }
  free (msg);
#warning should use failure in parserror_guicmd_BM
  longjmp (jmperrorcmd_BM, 1);
}                               /* end parserror_guicmd_BM */



// for $<var>
value_tyBM
parsdollarval_guicmd_BM (struct parser_stBM *pars,
                         unsigned lineno,
                         unsigned colpos,
                         const value_tyBM varname,
                         struct stackframe_stBM *stkf)
{
  const char *varstr = NULL;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM val;);
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  bool nobuild = parsops && parsops->parsop_nobuild;
  if (isstring_BM (varname))
    varstr = bytstring_BM (varname);
  else if (isobject_BM (varname))
    varstr = findobjectname_BM (varname);
  else if (varname == NULL)
    varstr = BMK_7bD9VtDkGSn_7lxHeYuuFLR;       // result
  if (!varstr)
    parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno, colpos,
                          "invalid $<var>");
  _.val = find_named_value_gui_BM (varstr);
  if (!_.val && !nobuild)
    parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno, colpos,
                          "not found $%s", varstr);
  GtkTextIter it = EMPTY_TEXT_ITER_BM, endit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  endit = it;
  gtk_text_iter_forward_chars (&endit, 1 + strlen (varstr));
  gtk_text_buffer_apply_tag (commandbuf_BM, dollar_cmdtag_BM, &it, &endit);
  return _.val;
}                               /* end parsdollarval_guicmd_BM */


// for $:<var>
const objectval_tyBM *
parsdollarobj_guicmd_BM (struct parser_stBM *pars,
                         unsigned lineno, unsigned colpos,
                         const value_tyBM varname,
                         struct stackframe_stBM *stkf)
{

  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM val;);
  const struct parserops_stBM *parsops = pars->pars_ops;
  bool nobuild = parsops && parsops->parsop_nobuild;
  const char *varstr = NULL;
  if (isstring_BM (varname))
    varstr = bytstring_BM (varname);
  else if (isobject_BM (varname))
    varstr = findobjectname_BM (varname);
  else if (varname == NULL)
    varstr = BMK_7bD9VtDkGSn_7lxHeYuuFLR;       /* result */
  if (!varstr)
    parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno, colpos,
                          "invalid $:<var>");
  _.val = find_named_value_gui_BM (varstr);
  if (!_.val && !nobuild)
    parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno, colpos,
                          "not found $:%s", varstr);
  if (!isobject_BM (_.val) && !nobuild)
    parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno, colpos,
                          "non-object $:%s", varstr);
  GtkTextIter it = EMPTY_TEXT_ITER_BM, endit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  endit = it;
  gtk_text_iter_forward_chars (&endit, 2 + strlen (varstr));
  gtk_text_buffer_apply_tag (commandbuf_BM, dollar_cmdtag_BM, &it, &endit);
  return (const objectval_tyBM *) _.val;
}                               /* end parsdollarobj_guicmd_BM */


// for €<newname> or $*<newname>
const objectval_tyBM *parsmakenewname_guicmd_BM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
   const value_tyBM varname, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * namedobj;
                 const stringval_tyBM * strnam; objectval_tyBM * parsob;
    );
  if (!isparser_BM (pars))
    return NULL;
  _.parsob = checkedparserowner_BM (pars);
  ASSERT_BM (isstring_BM (varname));
  _.strnam = varname;
  if (!validname_BM (bytstring_BM (varname)))
    parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno, colpos,
                          "invalid new name %s", bytstring_BM (varname));
  _.namedobj = findnamedobj_BM (bytstring_BM (varname));
  if (_.namedobj)
    return _.namedobj;
  _.namedobj = makeobj_BM ();
  objtouchnow_BM (_.namedobj);
  objputspacenum_BM (_.namedobj, GlobalSp_BM);
  registername_BM (_.namedobj, bytstring_BM (_.strnam));
  log_begin_message_BM ();
  log_puts_message_BM ("created global new named object ");
  log_object_message_BM (_.namedobj);
  log_end_message_BM ();
  return _.namedobj;
}                               /* end parsmakenewname_guicmd_BM */

static bool
parseobjectcompl_guicmd_BM (struct parser_stBM *pars,
                            objectval_tyBM * obj, int depth,
                            struct stackframe_stBM *stkf,
                            struct parstoken_stBM *ptok);
#define MAXARGS_BM 9
bool
parseobjectcompl_guicmd_BM (struct parser_stBM *pars,
                            objectval_tyBM * targobj, int depth,
                            struct stackframe_stBM *stkf,
                            struct parstoken_stBM *ptok)
{
  if (!isparser_BM (pars))
    return false;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM comp;
                 objectval_tyBM * targobj; objectval_tyBM * obattr;
                 objectval_tyBM * obclass; objectval_tyBM * obsel;
                 const stringval_tyBM * name; objectval_tyBM * parsob;
                 value_tyBM args[MAXARGS_BM];);
  _.parsob = checkedparserowner_BM (pars);
  _.targobj = targobj;
  struct parstoken_stBM tok = {
  };
  if (!ptok)
    {
      tok = parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
      ptok = &tok;
    };
  const struct parserops_stBM *parsops = pars->pars_ops;
  bool nobuild = parsops && parsops->parsop_nobuild;
  unsigned lineno = pars->pars_lineno;
  unsigned colpos = pars->pars_colpos;
  //
  // !& <comp>   # append a component to target object
  if (ptok->tok_kind == plex_DELIM && ptok->tok_delim == delim_exclamand)
    {
      if (!nobuild && !isobject_BM (targobj))
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                              colpos, "missing target for !&");
      bool gotval = false;
      _.comp = parsergetvalue_BM (pars, //
                                  (struct stackframe_stBM *) &_,        //
                                  depth + 1, &gotval);
      if (!gotval)
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                              colpos, "missing value after !&");
      if (!nobuild)
        {
          objappendcomp_BM (_.targobj, _.comp);
          log_begin_message_BM ();
          log_puts_message_BM ("appended to ");
          log_object_message_BM (_.targobj);
          log_puts_message_BM (".");
          log_end_message_BM ();
          objtouchnow_BM (_.targobj);
        }
    }
  //
  // !: <attr> <val> # put an attribute in target object
  // !: <index> <val> # put a component at given index in target object
  else
    if (ptok->tok_kind == plex_DELIM && ptok->tok_delim == delim_exclamcolon)
    {
      if (!nobuild && !isobject_BM (targobj))
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                              colpos, "missing target for !:");
      parserskipspaces_BM (pars, (struct stackframe_stBM *) &_);
      lineno = pars->pars_lineno;
      colpos = pars->pars_colpos;
      bool gotattr = false;
      bool gotindex = false;
      int index = -1;
      _.obattr = parsergetobject_BM (pars,      //
                                     (struct stackframe_stBM *) &_,     //
                                     depth + 1, &gotattr);
      if (!gotattr)
        {
          parserseek_BM (pars, lineno, colpos);
          struct parstoken_stBM tok =
            parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
          if (tok.tok_kind == plex_LLONG)
            {
              gotindex = true;
              index = (int) tok.tok_llong;
            }
        }
      if (!gotattr && !gotindex)
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                              colpos, "missing attribute or index after !:");
      bool gotval = false;
      _.comp = parsergetvalue_BM (pars, //
                                  (struct stackframe_stBM *) &_,        //
                                  depth + 1, &gotval);
      if (!gotval)
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                              colpos, "missing value after !:");
      if (!nobuild && gotattr)
        {
          objputattr_BM (_.targobj, _.obattr, _.comp);
          log_begin_message_BM ();
          log_puts_message_BM ("put attribute ");
          log_object_message_BM (_.obattr);
          log_puts_message_BM (" in object ");
          log_object_message_BM (_.targobj);
          log_puts_message_BM (".");
          log_end_message_BM ();
          objtouchnow_BM (_.targobj);
        }
      else if (!nobuild && gotindex)
        {
          objputcomp_BM (_.targobj, index, _.comp);
          log_begin_message_BM ();
          log_printf_message_BM ("put comp#%d in object ", index);
          log_object_message_BM (_.targobj);
          log_puts_message_BM (".");
          log_end_message_BM ();
          objtouchnow_BM (_.targobj);
        }
    }
  //
  // !$ <class>           # set the class of target object
  else
    if (ptok->tok_kind == plex_DELIM && ptok->tok_delim == delim_exclamdollar)
    {
      if (!nobuild && !isobject_BM (targobj))
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                              colpos, "missing target for !$");
      bool gotclass = false;
      _.obclass = parsergetobject_BM (pars,     //
                                      (struct stackframe_stBM *) &_,    //
                                      depth + 1, &gotclass);
      if (!gotclass)
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                              colpos, "missing class after !$");
      if (!nobuild)
        {
          objectval_tyBM *k_basiclo_function = BMK_2Ir1i8qnrA4_3jSkierlc5z;
          objputclass_BM (_.targobj, _.obclass);
          log_begin_message_BM ();
          log_puts_message_BM ("put class ");
          log_object_message_BM (_.obclass);
          log_puts_message_BM (" in object ");
          log_object_message_BM (_.targobj);
          log_puts_message_BM (".");
          log_end_message_BM ();
          if (_.obclass == k_basiclo_function)
            {
              log_begin_message_BM ();
              log_puts_message_BM ("\n");
              gint codestartoff = 0;
              {
                GtkTextIter it = EMPTY_TEXT_ITER_BM;
                gtk_text_buffer_get_end_iter (logbuf_BM, &it);
                codestartoff = gtk_text_iter_get_offset (&it);
              }
              log_puts_message_BM ("\n");
              log_puts_message_BM ("// possible code for ");
              log_object_message_BM (_.targobj);
              log_printf_message_BM ("\n\n"
                                     "extern objrout_sigBM ROUTINEOBJNAME_BM (");
              log_object_message_BM (_.targobj);
              log_printf_message_BM (");\n\n"
                                     "value_tyBM\n" "ROUTINEOBJNAME_BM (");
              log_object_message_BM (_.targobj);
              log_printf_message_BM (")\n"
                                     "(struct stackframe_stBM* stkf, //\n"
                                     " const value_tyBM arg1, //\n"
                                     " const value_tyBM arg2, //\n"
                                     " const value_tyBM arg3, //\n"
                                     " const value_tyBM arg4, //\n"
                                     " const quasinode_tyBM* restargs __attribute__((unused)))\n"
                                     "{\n" "  LOCALFRAME_BM (stkf, /*descr ");
              log_object_message_BM (_.targobj);
              log_printf_message_BM ("::*/ NULL,\n"
                                     "   value_tyBM resultv;\n" "  );\n");
              log_printf_message_BM ("#warning unimplemented ");
              log_object_message_BM (_.targobj);
              log_printf_message_BM (" routine\n");
              log_printf_message_BM
                ("  WEAKASSERT_BM(false && \"unimplemented ");
              log_object_message_BM (_.targobj);
              log_printf_message_BM (" routine\");\n");
              log_printf_message_BM ("  LOCALRETURN_BM(_.resultv);\n");
              log_printf_message_BM ("} /* end routine ");
              log_object_message_BM (_.targobj);
              log_printf_message_BM ("*/\n\n");
              {
                GtkTextIter begit = EMPTY_TEXT_ITER_BM;
                GtkTextIter endit = EMPTY_TEXT_ITER_BM;
                gtk_text_buffer_get_iter_at_offset (logbuf_BM, &begit,
                                                    codestartoff);
                gtk_text_buffer_get_end_iter (logbuf_BM, &endit);
                gtk_text_buffer_apply_tag (logbuf_BM, code_logtag_BM, &begit,
                                           &endit);
              }
              log_puts_message_BM ("\n");
              if (!_.targobj->ob_rout && !_.targobj->ob_sig)
                {
                  _.targobj->ob_sig = BMP_function_sig;
                  _.targobj->ob_rout = objrout_placeholder_BM;
                  log_printf_message_BM ("** added placeholder for ");
                  log_object_message_BM (_.targobj);
                }
              log_end_message_BM ();
            }
          objtouchnow_BM (_.targobj);
        }
    }
  //
  // !> <obselector> ( ... ) # to send a side-effecting message
  else
    if (ptok->tok_kind == plex_DELIM
        && ptok->tok_delim == delim_exclamgreater)
    {
      unsigned arglineno = pars->pars_lineno;
      unsigned argcolpos = pars->pars_colpos;
      if (!nobuild && !isobject_BM (targobj))
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                              colpos, "missing target for !>");
      bool gotsel = false;
      _.obsel = parsergetobject_BM (pars,       //
                                    (struct stackframe_stBM *) &_,      //
                                    depth + 1, &gotsel);
      if (!gotsel)
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, arglineno,
                              argcolpos, "missing selector after !>");
      parserskipspaces_BM (pars, (struct stackframe_stBM *) &_);
      unsigned leftlineno = pars->pars_lineno;
      unsigned leftcolpos = pars->pars_colpos;
      tok = parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
      if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_leftparen)
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, arglineno,
                              argcolpos,
                              "missing left paren after selector for !>");
      int nbarg = 0;
      while (nbarg < MAXARGS_BM)
        {
          bool gotarg = false;
          _.args[nbarg] =       //
            parsergetvalue_BM (pars,    //
                               (struct stackframe_stBM *) &_,   //
                               depth + 1, &gotarg);
          if (!gotarg)
            break;
          nbarg++;
        }
      tok = parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
      if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_rightparen)
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, arglineno,
                              argcolpos,
                              "missing right paren after selector for !>");
      unsigned rightlineno = pars->pars_lineno;
      unsigned rightcolpos = pars->pars_colpos;
      parsnesting_guicmd_BM (pars, depth + 1, delim_leftparen,
                             leftlineno, leftcolpos, delim_rightparen,
                             rightlineno, rightcolpos);
      if (!nobuild)
        {
          bool failsend = false;
          switch (nbarg)
            {
            case 0:
              _.comp =
                send0_BM (_.targobj, _.obsel, (struct stackframe_stBM *) &_);
              break;
            case 1:
              _.comp =
                send1_BM (_.targobj, _.obsel, (struct stackframe_stBM *) &_,
                          _.args[0]);
              break;
            case 2:
              _.comp =
                send2_BM (_.targobj, _.obsel, (struct stackframe_stBM *) &_,
                          _.args[0], _.args[1]);
              break;
            case 3:
              _.comp =
                send3_BM (_.targobj, _.obsel, (struct stackframe_stBM *) &_,
                          _.args[0], _.args[1], _.args[2]);
              break;
            case 4:
              _.comp =
                send4_BM (_.targobj, _.obsel, (struct stackframe_stBM *) &_,
                          _.args[0], _.args[1], _.args[2], _.args[3]);
              break;
            case 5:
              _.comp =
                send5_BM (_.targobj, _.obsel, (struct stackframe_stBM *) &_,
                          _.args[0], _.args[1], _.args[2], _.args[3],
                          _.args[4]);
              break;
            case 6:
              _.comp =
                send6_BM (_.targobj, _.obsel, (struct stackframe_stBM *) &_,
                          _.args[0], _.args[1], _.args[2], _.args[3],
                          _.args[4], _.args[5]);
              break;
            case 7:
              _.comp =
                send7_BM (_.targobj, _.obsel, (struct stackframe_stBM *) &_,
                          _.args[0], _.args[1], _.args[2], _.args[3],
                          _.args[4], _.args[5], _.args[6]);
              break;
            case 8:
              _.comp =
                send8_BM (_.targobj, _.obsel, (struct stackframe_stBM *) &_,
                          _.args[0], _.args[1], _.args[2], _.args[3],
                          _.args[4], _.args[5], _.args[6], _.args[7]);
              break;
            default:
              _.comp = NULL;
              failsend = true;
              break;
            }
          if ((_.comp == NULL) || failsend)
            {
              char targidbuf[32];
              const char *targname = findobjectname_BM (_.targobj);
              idtocbuf32_BM (objid_BM (_.targobj), targidbuf);
              char selidbuf[32];
              const char *selname = findobjectname_BM (_.obsel);
              idtocbuf32_BM (objid_BM (_.obsel), selidbuf);
              parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                    arglineno, argcolpos,
                                    "failed to send %s to target %s",
                                    selname ? : selidbuf,
                                    targname ? : targidbuf);
            }
          log_begin_message_BM ();
          log_puts_message_BM ("sent message ");
          log_object_message_BM (_.obsel);
          log_printf_message_BM (" with %d arguments to object ", nbarg);
          log_object_message_BM (_.targobj);
          log_puts_message_BM (".");
          log_end_message_BM ();
        }
    }                           // end !> 
  //
  // !- <attr>  # remove an attribute in target object
  else
    if (ptok->tok_kind == plex_DELIM && ptok->tok_delim == delim_exclamminus)
    {
      if (!nobuild && !isobject_BM (targobj))
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                              colpos, "missing target for !-");
      bool gotattr = false;
      _.obattr = parsergetobject_BM (pars,      //
                                     (struct stackframe_stBM *) &_,     //
                                     0, &gotattr);
      if (!gotattr)
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                              colpos, "missing attribute after !-");
      if (!nobuild)
        {
          objremoveattr_BM (_.targobj, _.obattr);
          log_begin_message_BM ();
          log_puts_message_BM ("remove attribute ");
          log_object_message_BM (_.obattr);
          log_puts_message_BM (" in object ");
          log_object_message_BM (_.targobj);
          log_puts_message_BM (".");
          log_end_message_BM ();
          objtouchnow_BM (_.targobj);
        }
    }
  //
  // $% <name> # to show and bind to name
  else
    if (ptok->tok_kind == plex_DELIM
        && ptok->tok_delim == delim_dollarpercent)
    {
      tok = parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
      if (tok.tok_kind != plex_NAMEDOBJ && tok.tok_kind != plex_CNAME)
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                              colpos, "no name to bind and show after $%%");
      if (!nobuild)
        {
          if (tok.tok_kind == plex_NAMEDOBJ)
            _.name = makestring_BM (findobjectname_BM (tok.tok_namedobj));
          else
            _.name = tok.tok_cname;
          ASSERT_BM (isstring_BM ((const value_tyBM) _.name));
          browse_named_value_gui_BM (_.name, _.targobj,
                                     BMP_browse_value, browserdepth_BM,
                                     (struct stackframe_stBM *) &_);
          log_begin_message_BM ();
          log_printf_message_BM ("bound name $%s to object ",
                                 bytstring_BM (_.name));
          log_object_message_BM (_.targobj);
          log_puts_message_BM (".");
          log_end_message_BM ();
        };
    }
  //
  // !^ <space> # to move to given space
  else
    if (ptok->tok_kind == plex_DELIM && ptok->tok_delim == delim_exclamcaret)
    {
      if (!nobuild && !isobject_BM (targobj))
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                              colpos, "missing target for !^");
      tok = parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
      if (tok.tok_kind == plex_LLONG && tok.tok_llong >= 0
          && tok.tok_llong < LASTSPACE__BM)
        {
          if (!nobuild)
            {
              objputspacenum_BM (_.targobj, tok.tok_llong);
              log_begin_message_BM ();
              log_printf_message_BM ("put in space#%d object ",
                                     (int) tok.tok_llong);
              log_object_message_BM (_.targobj);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }
      // !^ *   to make global
      else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_star)
        {
          if (!nobuild)
            {
              objputspacenum_BM (_.targobj, GlobalSp_BM);
              log_begin_message_BM ();
              log_puts_message_BM ("put in global space the object ");
              log_object_message_BM (_.targobj);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }
      // !^ :   to make userA
      else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_colon)
        {
          if (!nobuild)
            {
              objputspacenum_BM (_.targobj, UserASp_BM);
              log_begin_message_BM ();
              log_puts_message_BM ("put in userA space the object ");
              log_object_message_BM (_.targobj);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }
      // !^ ;   to make userB
      else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_semicolon)
        {
          if (!nobuild)
            {
              objputspacenum_BM (_.targobj, UserBSp_BM);
              log_begin_message_BM ();
              log_puts_message_BM ("put in userB space the object ");
              log_object_message_BM (_.targobj);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }
      // !^ %   to make transient
      else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_percent)
        {
          if (!nobuild)
            {
              objputspacenum_BM (_.targobj, TransientSp_BM);
              log_begin_message_BM ();
              log_puts_message_BM ("put in transient space the object ");
              log_object_message_BM (_.targobj);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }
      // !^ !$   to make predefined
      else if (tok.tok_kind == plex_DELIM
               && tok.tok_delim == delim_exclamdollar)
        {
          if (!nobuild)
            {
              objputspacenum_BM (_.targobj, PredefSp_BM);
              log_begin_message_BM ();
              log_puts_message_BM ("put in predefined space the object ");
              log_object_message_BM (_.targobj);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }
      else
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                              colpos, "bad space for !^");
    }
  else
    return false;
  return true;
}                               /* end parseobjectcompl_guicmd_BM */



// parse inside $(....)
value_tyBM
parsvalexp_guicmd_BM (struct parser_stBM * pars, unsigned lineno,
                      unsigned colpos, int depth,
                      struct stackframe_stBM * stkf)
{
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  bool nobuild = parsops && parsops->parsop_nobuild;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM resval; value_tyBM srcval; objectval_tyBM * obj;
                 objectval_tyBM * obsel; objectval_tyBM * parsob;
                 objectval_tyBM * obattr; closure_tyBM * clos;
                 value_tyBM otherval; const stringval_tyBM * name;
                 value_tyBM args[MAXARGS_BM];);
  _.parsob = checkedparserowner_BM (pars);
  unsigned srclineno = parserlineno_BM (pars);
  unsigned srccolpos = parsercolpos_BM (pars);
  bool gotsrcval = false;
  _.srcval =
    parsergetvalue_BM (pars, (struct stackframe_stBM *) &_, 0, &gotsrcval);
  if (!gotsrcval)
    parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, srclineno,
                          srccolpos, "expecting source value in $(...)");
  struct parstoken_stBM tok = {
  };
  for (;;)
    {
      parserskipspaces_BM (pars, (struct stackframe_stBM *) &_);
      tok = parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
      if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_rightparen)
        {
          parsnesting_guicmd_BM (pars, depth, delim_dollarleftparen,
                                 lineno, colpos, delim_rightparen,
                                 parserlineno_BM (pars),
                                 parsercolpos_BM (pars));
          return _.srcval;
        }
      //
      // !> <obselector> ( ...) # to send a message for its result
      else
        if (tok.tok_kind == plex_DELIM
            && tok.tok_delim == delim_exclamgreater)
        {
          unsigned arglineno = pars->pars_lineno;
          unsigned argcolpos = pars->pars_colpos;
          if (!nobuild && !_.srcval)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                                  colpos, "missing target for !>");
          bool gotsel = false;
          _.obsel = parsergetobject_BM (pars,   //
                                        (struct stackframe_stBM *) &_,  //
                                        0, &gotsel);
          if (!gotsel)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  arglineno, argcolpos,
                                  "missing selector after !>");
          tok = parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
          if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_leftparen)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  arglineno, argcolpos,
                                  "missing left paren after selector for !>");
          int nbarg = 0;
          while (nbarg < MAXARGS_BM)
            {
              bool gotarg = false;
              _.args[nbarg] = parsergetvalue_BM (pars, (struct stackframe_stBM *) &_,   //
                                                 0, &gotarg);
              if (!gotarg)
                break;
              nbarg++;
            }
          tok = parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
          if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_rightparen)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  arglineno, argcolpos,
                                  "missing right paren after selector for !>");
          if (!nobuild)
            {
              bool failsend = false;
              switch (nbarg)
                {
                case 0:
                  _.resval =
                    send0_BM (_.srcval, _.obsel,
                              (struct stackframe_stBM *) &_);
                  break;
                case 1:
                  _.resval =
                    send1_BM (_.srcval, _.obsel,
                              (struct stackframe_stBM *) &_, _.args[0]);
                  break;
                case 2:
                  _.resval =
                    send2_BM (_.srcval, _.obsel,
                              (struct stackframe_stBM *) &_, _.args[0],
                              _.args[1]);
                  break;
                case 3:
                  _.resval =
                    send3_BM (_.srcval, _.obsel,
                              (struct stackframe_stBM *) &_, _.args[0],
                              _.args[1], _.args[2]);
                  break;
                case 4:
                  _.resval =
                    send4_BM (_.srcval, _.obsel,
                              (struct stackframe_stBM *) &_, _.args[0],
                              _.args[1], _.args[2], _.args[3]);
                  break;
                case 5:
                  _.resval =
                    send5_BM (_.srcval, _.obsel,
                              (struct stackframe_stBM *) &_, _.args[0],
                              _.args[1], _.args[2], _.args[3], _.args[4]);
                  break;
                case 6:
                  _.resval =
                    send6_BM (_.srcval, _.obsel,
                              (struct stackframe_stBM *) &_, _.args[0],
                              _.args[1], _.args[2], _.args[3], _.args[4],
                              _.args[5]);
                  break;
                case 7:
                  _.resval =
                    send7_BM (_.srcval, _.obsel,
                              (struct stackframe_stBM *) &_, _.args[0],
                              _.args[1], _.args[2], _.args[3], _.args[4],
                              _.args[5], _.args[6]);
                  break;
                case 8:
                  _.resval =
                    send8_BM (_.srcval, _.obsel,
                              (struct stackframe_stBM *) &_, _.args[0],
                              _.args[1], _.args[2], _.args[3], _.args[4],
                              _.args[5], _.args[6], _.args[7]);
                  break;
                default:
                  _.resval = NULL;
                  failsend = true;
                  break;
                }
              if ((_.resval == NULL) || failsend)
                {
                  char selidbuf[32];
                  const char *selname = findobjectname_BM (_.obsel);
                  idtocbuf32_BM (objid_BM (_.obsel), selidbuf);
                  parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                        arglineno, argcolpos,
                                        "failed to send %s",
                                        selname ? : selidbuf);
                }
              log_begin_message_BM ();
              log_puts_message_BM ("sent message ");
              log_object_message_BM (_.obsel);
              log_printf_message_BM (" with %d arguments to value.", nbarg);
              log_end_message_BM ();
            }
        }                       // end !> 
      //
      //  ( ...) # to apply a functon
      else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_leftparen)
        {
          unsigned arglineno = pars->pars_lineno;
          unsigned argcolpos = pars->pars_colpos;
          if (!nobuild && !isclosure_BM (_.srcval))
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                                  colpos,
                                  "source value is not a closure for application");
          _.clos = (closure_tyBM *) _.srcval;
          int nbarg = 0;
          while (nbarg < MAXARGS_BM)
            {
              bool gotarg = false;
              _.args[nbarg] = parsergetvalue_BM (pars, (struct stackframe_stBM *) &_,   //
                                                 0, &gotarg);
              if (!gotarg)
                break;
              nbarg++;
            }
          tok = parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
          if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_rightparen)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  arglineno, argcolpos,
                                  "missing right paren after application");
          if (!nobuild)
            {
              bool failapply = false;
              switch (nbarg)
                {
                case 0:
                  _.resval =
                    apply0_BM (_.clos, (struct stackframe_stBM *) &_);
                  break;
                case 1:
                  _.resval =
                    apply1_BM (_.clos, (struct stackframe_stBM *) &_,
                               _.args[0]);
                  break;
                case 2:
                  _.resval =
                    apply2_BM (_.clos, (struct stackframe_stBM *) &_,
                               _.args[0], _.args[1]);
                  break;
                case 3:
                  _.resval =
                    apply3_BM (_.clos, (struct stackframe_stBM *) &_,
                               _.args[0], _.args[1], _.args[2]);
                  break;
                case 4:
                  _.resval =
                    apply4_BM (_.clos, (struct stackframe_stBM *) &_,
                               _.args[0], _.args[1], _.args[2], _.args[3]);
                  break;
                case 5:
                  _.resval =
                    apply5_BM (_.clos, (struct stackframe_stBM *) &_,
                               _.args[0], _.args[1], _.args[2], _.args[3],
                               _.args[4]);
                  break;
                case 6:
                  _.resval =
                    apply6_BM (_.clos, (struct stackframe_stBM *) &_,
                               _.args[0], _.args[1], _.args[2], _.args[3],
                               _.args[4], _.args[5]);
                  break;
                case 7:
                  _.resval =
                    apply7_BM (_.clos, (struct stackframe_stBM *) &_,
                               _.args[0], _.args[1], _.args[2], _.args[3],
                               _.args[4], _.args[5], _.args[6]);
                  break;
                case 8:
                  _.resval =
                    apply8_BM (_.clos, (struct stackframe_stBM *) &_,
                               _.args[0], _.args[1], _.args[2], _.args[3],
                               _.args[4], _.args[5], _.args[6], _.args[7]);
                  break;
                case 9:
                  _.resval =
                    apply9_BM (_.clos, (struct stackframe_stBM *) &_,
                               _.args[0], _.args[1], _.args[2], _.args[3],
                               _.args[4], _.args[5], _.args[6], _.args[7],
                               _.args[8]);
                  break;
                default:
                  _.resval = NULL;
                  failapply = true;
                  break;
                }
              if ((_.resval == NULL) || failapply)
                {
                  char selidbuf[32];
                  idtocbuf32_BM (objid_BM (_.obsel), selidbuf);
                  parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                        arglineno, argcolpos,
                                        "failed to apply with %d arguments",
                                        nbarg);
                }
              log_begin_message_BM ();
              log_printf_message_BM ("applied with %d arguments to value.",
                                     nbarg);
              log_end_message_BM ();
              _.srcval = _.resval;
            }
        }                       // end application ( ... )
      //
      // !. <obattr> # to get an attribute
      else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_exclamdot)
        {
          bool gotattr = false;
          parserskipspaces_BM (pars, (struct stackframe_stBM *) &_);
          unsigned atlineno = parserlineno_BM (pars);
          unsigned atcolpos = parsercolpos_BM (pars);
          if (!nobuild && !isobject_BM (_.srcval))
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  atlineno, atcolpos, "non object before !.");
          _.obattr =
            parsergetobject_BM (pars, (struct stackframe_stBM *) &_,
                                depth + 1, &gotattr);
          if (!gotattr)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  atlineno, atcolpos,
                                  "expecting object attribute after !.");
          if (!nobuild)
            {
              _.resval =
                objgetattr_BM ((objectval_tyBM *) _.srcval, _.obattr);
              log_begin_message_BM ();
              log_puts_message_BM ("got attribute ");
              log_object_message_BM (_.obsel);
              log_puts_message_BM (" from value object ");
              log_object_message_BM ((objectval_tyBM *) _.srcval);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }                       /* end !. */
      //
      // !@ <index> # to get a component
      else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_exclamat)
        {
          bool gotindex = false;
          parserskipspaces_BM (pars, (struct stackframe_stBM *) &_);
          unsigned ixlineno = parserlineno_BM (pars);
          unsigned ixcolpos = parsercolpos_BM (pars);
          if (!nobuild && !isobject_BM (_.srcval))
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  ixlineno, ixcolpos, "non object before !@");
          _.otherval =
            parsergetvalue_BM (pars, (struct stackframe_stBM *) &_, depth + 1,
                               &gotindex);
          if (!gotindex)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  ixlineno, ixcolpos,
                                  "expecting index value after !@");
          if (!nobuild)
            {
              if (!istaggedint_BM (_.otherval))
                parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                      ixlineno, ixcolpos,
                                      "expecting integer index after !@");
              _.resval =
                objgetcomp_BM ((objectval_tyBM *) _.srcval,
                               getint_BM (_.otherval));
              log_begin_message_BM ();
              log_printf_message_BM
                ("got component #%ld from object value ",
                 (long) getint_BM (_.otherval));
              log_object_message_BM ((objectval_tyBM *) _.srcval);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }                       /* end !@ */
      //
      // $% <name> # to show and bind to name
      else
        if (tok.tok_kind == plex_DELIM
            && tok.tok_delim == delim_dollarpercent)
        {
          tok = parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
          if (tok.tok_kind != plex_NAMEDOBJ && tok.tok_kind != plex_CNAME)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                                  colpos,
                                  "no name to bind and show after $%%");
          if (!nobuild)
            {
              if (tok.tok_kind == plex_NAMEDOBJ)
                _.name = makestring_BM (findobjectname_BM (tok.tok_namedobj));
              else
                _.name = tok.tok_cname;
              ASSERT_BM (isstring_BM ((const value_tyBM) _.name));
              browse_named_value_gui_BM (_.name, _.srcval,
                                         BMP_browse_value, browserdepth_BM,
                                         (struct stackframe_stBM *) &_);
              log_begin_message_BM ();
              log_printf_message_BM ("bound and show name $%s to value.",
                                     bytstring_BM (_.name));
              log_end_message_BM ();
            };
        }
      //
      // otherwise error
      else
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                              parserlineno_BM (pars), parsercolpos_BM (pars),
                              "unexpected token in $(...)");
    }                           /* end for (;;) */
  return NULL;
}                               /* end parsvalexp_guicmd_BM */


// expand readmacro-s
value_tyBM parsreadmacroexp_guicmd_BM
  (struct parser_stBM * pars, unsigned lineno, unsigned colpos, int depth,
   const node_tyBM * nod, struct stackframe_stBM * stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM resval;
                 const node_tyBM * nod;
                 value_tyBM crm; const objectval_tyBM * conn;
                 objectval_tyBM * parsob;
    );
  _.parsob = checkedparserowner_BM (pars);
  _.nod = nod;
  if (depth > MAXDEPTHPARSE_BM)
    parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno, colpos,
                          "too deep %d readmacro", depth);
  ASSERT_BM (isnode_BM ((const value_tyBM) nod));
  _.conn = nodeconn_BM ((const value_tyBM) _.nod);
  ASSERT_BM (isobject_BM ((const value_tyBM) _.conn));
  _.crm = objgetattr_BM (_.conn, BMP_command_readmacro);
  if (!isclosure_BM ((const value_tyBM) _.crm))
    {
      char crmidbuf[32];
      memset (crmidbuf, 0, sizeof (crmidbuf));
      idtocbuf32_BM (objid_BM (_.crm), crmidbuf);
      const char *crmname = findobjectname_BM (_.crm);
      if (crmname)
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                              colpos,
                              "readmacro ^ %s |=%s| has bad `command_readmacro` attribute",
                              crmidbuf, crmname);
      else
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, lineno,
                              colpos,
                              "readmacro ^ %s has bad `command_readmacro` attribute",
                              crmidbuf);
    }
  _.resval =                    //
    apply4_BM (_.crm, (struct stackframe_stBM *) &_,
               (value_tyBM) _.nod,
               taggedint_BM (lineno), taggedint_BM (colpos), _.parsob);
  return _.resval;
}                               /* end parsreadmacroexp_guicmd_BM */



// parse inside $[...]
const objectval_tyBM *
parsobjexp_guicmd_BM (struct parser_stBM *pars,
                      unsigned lineno, unsigned colpos,
                      int depth, struct stackframe_stBM *stkf)
{
  const struct parserops_stBM *parsops = pars->pars_ops;
  bool nobuild = parsops && parsops->parsop_nobuild;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * obj;
                 const stringval_tyBM * namev; objectval_tyBM * oldnamedob;
                 value_tyBM val;);
  ASSERT_BM (isparser_BM (pars));
  parserskipspaces_BM (pars, (struct stackframe_stBM *) &_);
  unsigned oblineno = parserlineno_BM (pars);
  unsigned obcolpos = parsercolpos_BM (pars);
  bool gotobj = false;
  struct parstoken_stBM tok =
    parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
  // * <name> to create a new (userE) named object
  // !* <name> to create a new (global) named object
  if (tok.tok_kind == plex_DELIM
      && (tok.tok_delim == delim_exclamstar || tok.tok_delim == delim_star))
    {
      bool isglobal = (tok.tok_delim == delim_exclamstar);
      tok = parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
      if (tok.tok_kind == plex_CNAME)
        {
          _.namev = tok.tok_cname;
        }
      else if (tok.tok_kind == plex_NAMEDOBJ)
        {
          _.oldnamedob = tok.tok_namedobj;
        }
      else
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, oblineno,
                              obcolpos,
                              "expecting name after * or !* in $[...]");
      gotobj = true;
      if (!nobuild)
        {
          if (_.namev)
            {
              _.obj = makeobj_BM ();
              objtouchnow_BM (_.obj);
              objputspacenum_BM (_.obj, isglobal ? GlobalSp_BM : UserEsp_BM);
              registername_BM (_.obj, bytstring_BM (_.namev));
              log_begin_message_BM ();
              log_puts_message_BM (isglobal
                                   ? "created global named object "
                                   : "created userE named object ");
              log_object_message_BM (_.obj);
              log_end_message_BM ();
            }
          else if (_.oldnamedob)
            {
              _.obj = _.oldnamedob;
              log_begin_message_BM ();
              log_puts_message_BM ("reusing named object ");
              log_object_message_BM (_.obj);
              log_end_message_BM ();
            }
          else
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  oblineno, obcolpos,
                                  "expecting some name after * or !* in $[...]");
        }
    }
  // : to create a new transient anonymous object
  else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_colon)
    {
      gotobj = true;
      if (!nobuild)
        {
          _.obj = makeobj_BM ();
          objtouchnow_BM (_.obj);
          objputspacenum_BM (_.obj, TransientSp_BM);
          log_begin_message_BM ();
          log_puts_message_BM ("created transient anonymous object ");
          log_object_message_BM (_.obj);
          log_end_message_BM ();
        }
    }
  // ~ to create a new global anonymous object
  else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_tilde)
    {
      gotobj = true;
      if (!nobuild)
        {
          _.obj = makeobj_BM ();
          objtouchnow_BM (_.obj);
          objputspacenum_BM (_.obj, GlobalSp_BM);
          log_begin_message_BM ();
          log_puts_message_BM ("created global anonymous object ");
          log_object_message_BM (_.obj);
          log_end_message_BM ();
        }
    }
  // % to create a new (userE) anonymous object
  else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_percent)
    {
      gotobj = true;
      if (!nobuild)
        {
          _.obj = makeobj_BM ();
          objtouchnow_BM (_.obj);
          objputspacenum_BM (_.obj, UserEsp_BM);
          log_begin_message_BM ();
          log_puts_message_BM ("created userE anonymous object ");
          log_object_message_BM (_.obj);
          log_end_message_BM ();
        }
    }
  //
  // $:<var>
  else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_dollarcolon)
    {
      parserseek_BM (pars, oblineno, obcolpos);
      _.obj =
        parsergetobject_BM (pars, (struct stackframe_stBM *) &_, 0, &gotobj);
      if (!gotobj)
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, oblineno,
                              obcolpos, "expecting $:<var> in $[...]");
    }
  //
  // ( <expr> ) to cast a value into an object
  else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_leftparen)
    {
      bool gotval = false;
      _.val =
        parsergetvalue_BM (pars, (struct stackframe_stBM *) &_, 0, &gotval);
      if (!gotval)
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, oblineno,
                              obcolpos, "expecting value after $[ (");
      tok = parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
      if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_rightparen)
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                              pars->pars_lineno,
                              pars->pars_colpos,
                              "expecting right paren after $[ ( started at L%d:C%d",
                              oblineno, obcolpos);
      if (!nobuild && !isobject_BM (_.val))
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                              oblineno,
                              obcolpos, "non-object value after $[ (...");
    }
  //
  // <id> or <name> to refer to an existing object
  else if (tok.tok_kind == plex_ID || tok.tok_kind == plex_NAMEDOBJ)
    {
      parserseek_BM (pars, oblineno, obcolpos);
      _.obj =
        parsergetobject_BM (pars, (struct stackframe_stBM *) &_, 0, &gotobj);
    }
  if (!gotobj)
    parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, oblineno,
                          obcolpos, "expecting object at start of $[...]");
  while ((tok =
          parsertokenget_BM (pars, (struct stackframe_stBM *) &_)),
         tok.tok_kind != plex__NONE)
    {
      if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_rightbracket)
        {
          parsnesting_guicmd_BM (pars, depth, delim_dollarleftbracket,
                                 lineno, colpos, delim_rightbracket,
                                 parserlineno_BM (pars),
                                 parsercolpos_BM (pars));
          return _.obj;
        }
      bool gotcomp = parseobjectcompl_guicmd_BM (pars, _.obj, depth,
                                                 (struct stackframe_stBM *)
                                                 &_,
                                                 &tok);
      if (!gotcomp)
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                              pars->pars_lineno, pars->pars_colpos,
                              "bad object complement (for $[...] started L%d:C%d",
                              oblineno, obcolpos);
      if (!nobuild)
        {
          log_begin_message_BM ();
          log_puts_message_BM ("updated object ");
          log_object_message_BM (_.obj);
          log_puts_message_BM (".");
          log_end_message_BM ();
        }
      return _.obj;
    };
  parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                        pars->pars_lineno, pars->pars_colpos,
                        "invalid object expression for $[...] started L%d:C%d",
                        oblineno, obcolpos);
}                               /* end parsobjexp_guicmd_BM */


////////////////
void
parsecommandbuf_BM (struct parser_stBM *pars, struct stackframe_stBM *stkf)
{
  if (!isparser_BM (pars))
    return;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM comp;
                 objectval_tyBM * obj; objectval_tyBM * parsob;
                 objectval_tyBM * oldfocusobj; const stringval_tyBM * name;
                 const stringval_tyBM * result;
    );
  _.parsob = checkedparserowner_BM (pars);
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (!parsops || parsops->parsop_magic == PARSOPMAGIC_BM);
  bool nobuild = parsops && parsops->parsop_nobuild;
  int nbloop = 0;
  for (;;)
    {
      parserskipspaces_BM (pars, (struct stackframe_stBM *) &_);
      if (nbloop++ > MAXSIZE_BM / 32)
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                              pars->pars_lineno, pars->pars_colpos,
                              "too many %d loops", nbloop);
      if (parserendoffile_BM (pars))
        break;
      unsigned curlineno = parserlineno_BM (pars);
      unsigned curcolpos = parsercolpos_BM (pars);
      parstoken_tyBM tok =
        parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
      //// double semicolon stops the parsing and skip the rest
      if (tok.tok_kind == plex_DELIM
          && tok.tok_delim == delim_doublesemicolon)
        {
          unsigned toklin = tok.tok_line;
          unsigned tokcol = tok.tok_col;
          GtkTextIter skipit = EMPTY_TEXT_ITER_BM;
          GtkTextIter endit = EMPTY_TEXT_ITER_BM;
          gtk_text_buffer_get_iter_at_line (commandbuf_BM, &skipit, toklin);
          gtk_text_iter_forward_chars (&skipit, tokcol);
          gtk_text_buffer_get_end_iter (commandbuf_BM, &endit);
          gtk_text_buffer_apply_tag (commandbuf_BM, skipped_cmdtag_BM,
                                     &skipit, &endit);
          break;
        }
      // object complement applies to focus
      if (tok.tok_kind == plex_DELIM
          && (tok.tok_delim == delim_exclamand
              || tok.tok_delim == delim_exclamcolon
              || tok.tok_delim == delim_exclamdollar
              || tok.tok_delim == delim_exclamgreater
              || tok.tok_delim == delim_exclamminus
              || tok.tok_delim == delim_exclamcaret))
        {

          if (!browserbuf_BM)
            {
              if (!oldgui_BM)
                browserbuf_BM = newgui_get_browsebuf_BM ();
              if (!browserbuf_BM)
                return;
            };
          if (!nobuild && !isobject_BM (GLOBAL_BM (gui_focus_obj)))
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  curlineno, curcolpos,
                                  "no focus object to complement");
          if (!parseobjectcompl_guicmd_BM
              (pars, (objectval_tyBM *) GLOBAL_BM (gui_focus_obj), 0,
               (struct stackframe_stBM *) &_, &tok))
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  curlineno, curcolpos,
                                  "invalid focus complement");
          if (!nobuild)
            {
              struct browsedobj_stBM *brfocusob =
                find_browsed_object_BM (GLOBAL_BM (gui_focus_obj));
              ASSERT_BM (brfocusob != NULL);
              browse_object_gui_BM (GLOBAL_BM (gui_focus_obj),
                                    BMP_browse_in_object,
                                    brfocusob->brow_odepth,
                                    (struct stackframe_stBM *) &_);
              log_begin_message_BM ();
              log_puts_message_BM ("[re-]browsing object ");
              log_object_message_BM (GLOBAL_BM (gui_focus_obj));
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }
      //
      // ?* <object> # to focus and display an object
      else
        if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_questionstar)
        {

          if (!browserbuf_BM)
            {
              if (!oldgui_BM)
                browserbuf_BM = newgui_get_browsebuf_BM ();
              if (!browserbuf_BM)
                return;
            };
          bool gotobject = false;
          _.obj = parsergetobject_BM (pars, (struct stackframe_stBM *) &_,      //
                                      0, &gotobject);
          if (!gotobject)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  curlineno, curcolpos,
                                  "no new focus object after ?*");
          if (!nobuild)
            {
              _.oldfocusobj = GLOBAL_BM (gui_focus_obj);
              struct browsedobj_stBM *broldfocusob =
                find_browsed_object_BM (_.oldfocusobj);
              GLOBAL_BM (gui_focus_obj) = _.obj;
              if (_.obj)
                {
                  browse_object_gui_BM (GLOBAL_BM (gui_focus_obj),
                                        BMP_browse_in_object,
                                        browserdepth_BM,
                                        (struct stackframe_stBM *) &_);
                  log_begin_message_BM ();
                  log_puts_message_BM ("showing and focusing object ");
                  log_object_message_BM (GLOBAL_BM (gui_focus_obj));
                  log_printf_message_BM (" at depth %d.", browserdepth_BM);
                  log_end_message_BM ();
                }
              if (broldfocusob && _.oldfocusobj != _.obj)
                {
                  browse_object_gui_BM (_.oldfocusobj,
                                        BMP_browse_in_object,
                                        broldfocusob->brow_odepth,
                                        (struct stackframe_stBM *) &_);
                  log_begin_message_BM ();
                  log_puts_message_BM ("defocusing object ");
                  log_object_message_BM (_.oldfocusobj);
                  log_puts_message_BM (".");
                  log_end_message_BM ();
                }
            }
        }
      //
      // ?. <object> # to display an object without focusing on it
      else
        if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_questiondot)
        {
          if (!browserbuf_BM)
            {
              if (!oldgui_BM)
                browserbuf_BM = newgui_get_browsebuf_BM ();
              if (!browserbuf_BM)
                return;
            };
          bool gotobject = false;
          _.obj = parsergetobject_BM (pars, (struct stackframe_stBM *) &_,      //
                                      0, &gotobject);
          if (!gotobject || (!nobuild && !_.obj))
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  curlineno, curcolpos,
                                  "no displayed object after ?.");
          if (!browserbuf_BM)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  curlineno, curcolpos, "no browser buffer");
          if (!nobuild)
            {
              browse_object_gui_BM (_.obj,
                                    BMP_browse_in_object,
                                    browserdepth_BM,
                                    (struct stackframe_stBM *) &_);
              log_begin_message_BM ();
              log_puts_message_BM ("displaying object ");
              log_object_message_BM (_.obj);
              log_printf_message_BM (" at depth %d.", browserdepth_BM);
              log_end_message_BM ();
            }
        }
      //
      // <id>, <name>, $[...], $:<obj> is displaying an object without focus
      else if (tok.tok_kind == plex_ID || tok.tok_kind == plex_NAMEDOBJ
               || (tok.tok_kind == plex_DELIM
                   && (tok.tok_delim == delim_dollarcolon
                       || tok.tok_delim == delim_dollarleftbracket)))
        {

          if (!browserbuf_BM)
            {
              if (!oldgui_BM)
                browserbuf_BM = newgui_get_browsebuf_BM ();
            };
          if (!browserbuf_BM)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  curlineno, curcolpos, "no browser buffer");
          bool gotobject = false;
          parserseek_BM (pars, tok.tok_line, tok.tok_col);
          _.obj = parsergetobject_BM (pars, (struct stackframe_stBM *) &_,      //
                                      0, &gotobject);
          if (!gotobject || (!nobuild && !_.obj))
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  curlineno, curcolpos,
                                  "expecting object to display");
          if (!nobuild)
            {
              browse_object_gui_BM (_.obj,
                                    BMP_browse_in_object,
                                    browserdepth_BM,
                                    (struct stackframe_stBM *) &_);
              log_begin_message_BM ();
              log_puts_message_BM ("displaying object ");
              log_object_message_BM (_.obj);
              log_printf_message_BM (" at depth %d.", browserdepth_BM);
              log_end_message_BM ();
            }
        }
      //
      // ?- <object> # to hide an object
      else
        if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_questionstar)
        {
          if (!browserbuf_BM)
            {
              if (!oldgui_BM)
                browserbuf_BM = newgui_get_browsebuf_BM ();
            };
          if (!browserbuf_BM)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  curlineno, curcolpos, "no browser buffer");
          bool gotobject = false;
          _.obj = parsergetobject_BM (pars, (struct stackframe_stBM *) &_,      //
                                      0, &gotobject);
          if (!gotobject)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  curlineno, curcolpos,
                                  "no object to hide after ?-");
          if (!nobuild)
            {
              if (_.obj == GLOBAL_BM (gui_focus_obj))
                GLOBAL_BM (gui_focus_obj) = NULL;
              hide_object_gui_BM (_.obj, (struct stackframe_stBM *) &_);
              log_begin_message_BM ();
              log_puts_message_BM ("hiding object ");
              log_object_message_BM (_.obj);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
        }
      //
      // ?$ <name> <value> # to display and bind a named value
      else
        if (tok.tok_kind == plex_DELIM
            && tok.tok_delim == delim_questiondollar)
        {
          tok = parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
          if (tok.tok_kind != plex_NAMEDOBJ && tok.tok_kind != plex_CNAME)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  curlineno, curcolpos,
                                  "no name to bind and show after ?$");
          if (!nobuild)
            {
              if (tok.tok_kind == plex_NAMEDOBJ)
                _.name = makestring_BM (findobjectname_BM (tok.tok_namedobj));
              else
                _.name = tok.tok_cname;
              ASSERT_BM (isstring_BM ((const value_tyBM) _.name));
            };
          bool gotval = false;
          _.comp =
            parsergetvalue_BM (pars, (struct stackframe_stBM *) &_, 0,
                               &gotval);
          if (!gotval)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  curlineno, curcolpos,
                                  "no value to bind and show after ?$");
          if (!nobuild)
            {
              if (_.comp)
                {
                  log_begin_message_BM ();
                  log_printf_message_BM
                    ("binding & showing named value $%s at depth %d.",
                     bytstring_BM (_.name), browserdepth_BM);
                  log_end_message_BM ();
                  browse_named_value_gui_BM (_.name, _.comp,
                                             BMP_browse_value,
                                             browserdepth_BM,
                                             (struct stackframe_stBM *) &_);
                }
              else
                {
                  log_begin_message_BM ();
                  log_printf_message_BM ("hiding named value $%s.",
                                         bytstring_BM (_.name));
                  log_end_message_BM ();
                  hide_named_value_gui_BM (_.name,
                                           (struct stackframe_stBM *) &_);
                }
            }
        }
      // ?$- <name>  # to hide and unbind a named value
      else
        if (tok.tok_kind == plex_DELIM
            && tok.tok_delim == delim_questiondollar)
        {
          tok = parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
          if (tok.tok_kind != plex_NAMEDOBJ && tok.tok_kind != plex_CNAME)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  curlineno, curcolpos,
                                  "no name to hide after ?$-");
          if (!nobuild)
            {
              if (tok.tok_kind == plex_NAMEDOBJ)
                _.name = makestring_BM (findobjectname_BM (tok.tok_namedobj));
              else
                _.name = tok.tok_cname;
              ASSERT_BM (isstring_BM ((const value_tyBM) _.name));
              if (!find_browsed_named_value_BM (bytstring_BM (_.name)))
                parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                      curlineno, curcolpos,
                                      "name %s is not of a shown value",
                                      bytstring_BM (_.name));
              hide_named_value_gui_BM (_.name, (struct stackframe_stBM *) &_);
              log_begin_message_BM ();
              log_printf_message_BM ("hiding named value $%s.",
                                     bytstring_BM (_.name));
              log_end_message_BM ();
            };
        }
      //
      // ?# <depth> # to change the browse depth
      else
        if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_questionhash)
        {
          tok = parsertokenget_BM (pars, (struct stackframe_stBM *) &_);
          if (tok.tok_kind != plex_LLONG)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  curlineno, curcolpos,
                                  "?# should be followed by browse depth number");
          int newdepth = browserdepth_BM;
          if (tok.tok_llong < 2)
            newdepth = 2;
          else if (tok.tok_llong > BROWSE_MAXDEPTH_BM)
            newdepth = BROWSE_MAXDEPTH_BM;
          else
            newdepth = (int) tok.tok_llong;
          if (!nobuild)
            {
              log_begin_message_BM ();
              log_printf_message_BM ("changing browse depth to %d.",
                                     newdepth);
              log_end_message_BM ();
              browserdepth_BM = newdepth;
            }
        }
      // various value-starting delimiters
      else if (tok.tok_kind == plex_DELIM
               && (tok.tok_delim == delim_hashleftbrace
                   || tok.tok_delim == delim_leftbracket
                   || tok.tok_delim == delim_leftbrace
                   || tok.tok_delim == delim_tildecolon
                   || tok.tok_delim == delim_star
                   || tok.tok_delim == delim_percent
                   || tok.tok_delim == delim_caret
                   || tok.tok_delim == delim_dollar
                   || tok.tok_delim == delim_dollarcolon
                   || tok.tok_delim == delim_dollarleftbracket
                   || tok.tok_delim == delim_dollarleftparen))
        {
          bool gotval = false;
          if (!_.result)
            _.result = makestring_BM ("result");
          parserseek_BM (pars, tok.tok_line, tok.tok_col);
          _.comp =
            parsergetvalue_BM (pars, (struct stackframe_stBM *) &_, 0,
                               &gotval);
          if (!gotval)
            parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                  curlineno, curcolpos,
                                  "no value to display as $result after $(");
          if (!nobuild)
            {
              if (_.comp)
                {
                  log_begin_message_BM ();
                  log_printf_message_BM
                    ("binding & showing $result at depth %d.",
                     browserdepth_BM);
                  log_end_message_BM ();
                  browse_named_value_gui_BM (_.result, _.comp,
                                             BMP_browse_value,
                                             browserdepth_BM,
                                             (struct stackframe_stBM *) &_);
                }
              else
                parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_,
                                      curlineno, curcolpos,
                                      "no result to display after $(");
            }
        }
      //
      else
        parsererrorprintf_BM (pars, (struct stackframe_stBM *) &_, curlineno,
                              curcolpos, "unexpected command");
    }
}                               /* end parsecommandbuf_BM */


void
parscommentinside_guicmd_BM (struct parser_stBM *pars,
                             unsigned lineno, unsigned colpos,
                             unsigned signlen)
{
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, signlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, commentinside_cmdtag_BM, &it,
                             &endit);
}                               /* end parscommentinside_guicmd_BM */


void
parscommentsign_guicmd_BM (struct parser_stBM *pars,
                           unsigned lineno, unsigned colpos, unsigned signlen)
{
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, signlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, commentsign_cmdtag_BM, &it,
                             &endit);
}                               /* end parscommentsign_guicmd_BM */

void
parsdelim_guicmd_BM (struct parser_stBM *pars, unsigned lineno,
                     unsigned colpos, unsigned delimlen)
{
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, delimlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, delim_cmdtag_BM, &it, &endit);
}                               /* end parsdelim_guicmd_BM */

void
parsknowname_guicmd_BM (struct parser_stBM *pars, unsigned lineno,
                        unsigned colpos, unsigned namlen)
{
  char *buf = NULL;
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, namlen);
  if (pars->pars_debug)
    DBGPRINTF_BM ("parsknownname L%uC%u w%u: '%s'", lineno, colpos, namlen,
                  (buf =
                   gtk_text_buffer_get_text (commandbuf_BM, &it, &endit,
                                             false)));
  free (buf);
  gtk_text_buffer_apply_tag (commandbuf_BM, knowname_cmdtag_BM, &it, &endit);
}                               /* end parsknowname_guicmd_BM */


void
parsnewname_guicmd_BM (struct parser_stBM *pars, unsigned lineno,
                       unsigned colpos, unsigned namlen)
{
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, namlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, newname_cmdtag_BM, &it, &endit);
}                               /* end parsnewname_guicmd_BM */

// decorate numbers
void
parsnumber_guicmd_BM (struct parser_stBM *pars, unsigned lineno,
                      unsigned colpos, unsigned numlen)
{
  ASSERT_BM (isparser_BM (pars));
  char *buf = NULL;
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, numlen);
  if (pars->pars_debug)
    DBGPRINTF_BM ("parsnumbergui L%uC%u w%u: '%s'", lineno, colpos, numlen,
                  (buf =
                   gtk_text_buffer_get_text (commandbuf_BM, &it, &endit,
                                             false)));
  free (buf);
  gtk_text_buffer_apply_tag (commandbuf_BM, number_cmdtag_BM, &it, &endit);
}                               /* end parsnumber_guicmd_BM  */


// decorate string signs, notably outside quotes
void
parsstringsign_guicmd_BM (struct parser_stBM *pars, unsigned lineno,
                          unsigned colpos, unsigned signlen)
{
  ASSERT_BM (isparser_BM (pars));
  char *buf = NULL;
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, signlen);
  if (pars->pars_debug)
    DBGPRINTF_BM ("parsstringsign L%uC%u w%u: '%s'", lineno, colpos, signlen,
                  (buf =
                   gtk_text_buffer_get_text (commandbuf_BM, &it, &endit,
                                             false)));
  free (buf);
  gtk_text_buffer_apply_tag (commandbuf_BM, stringsign_cmdtag_BM, &it,
                             &endit);
}                               /* end parsstringsign_guicmd_BM */


// decorate string inside characters
void
  parsstringinside_guicmd_BM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
   unsigned signlen)
{
  ASSERT_BM (isparser_BM (pars));
  char *buf = NULL;
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, signlen);
  if (pars->pars_debug)
    DBGPRINTF_BM ("parsstringinside L%uC%u w%u: '%s'", lineno, colpos,
                  signlen, (buf =
                            gtk_text_buffer_get_text (commandbuf_BM, &it,
                                                      &endit, false)));
  free (buf);
  gtk_text_buffer_apply_tag (commandbuf_BM, stringinside_cmdtag_BM, &it,
                             &endit);
}                               /* end parsstringinside_guicmd_BM */


void
parsid_guicmd_BM (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
                  unsigned idlen)
{
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, idlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, id_cmdtag_BM, &it, &endit);
}                               /* end parsid_guicmd_BM */


void
parsnesting_guicmd_BM (struct parser_stBM *pars, int depth,
                       enum lexdelim_enBM opendelim,
                       unsigned openlinpos, unsigned opencolpos,
                       enum lexdelim_enBM closedelim,
                       unsigned closelinpos, unsigned closecolpos)
{
  ASSERT_BM (isparser_BM (pars));
  ASSERT_BM (openlinpos > 0 && closelinpos > 0 && openlinpos <= closelinpos);
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  const char *opendelstr = delimstr_BM (opendelim);
  const char *closedelstr = delimstr_BM (closedelim);
  GtkTextIter openit = EMPTY_TEXT_ITER_BM, endopenit = EMPTY_TEXT_ITER_BM;
  GtkTextIter closeit = EMPTY_TEXT_ITER_BM, stacloseit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &openit, openlinpos - 1);
  gtk_text_iter_forward_chars (&openit, opencolpos);
  endopenit = openit;
  int openoff = gtk_text_iter_get_offset (&openit);
  int openlen = g_utf8_strlen (opendelstr, -1);
  gtk_text_iter_forward_chars (&endopenit, openlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, nesting_cmdtag_BM,
                             &openit, &endopenit);
  if (depth < CMD_MAXNEST_BM)
    gtk_text_buffer_apply_tag (commandbuf_BM,
                               open_cmdtags_BM[depth], &openit, &endopenit);
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &stacloseit,
                                    closelinpos - 1);
  gtk_text_iter_forward_chars (&stacloseit, closecolpos);
  closeit = stacloseit;
  int closelen = g_utf8_strlen (closedelstr, -1);
  int closeoff = gtk_text_iter_get_offset (&closeit);
  gtk_text_iter_forward_chars (&closeit, closelen);
  gtk_text_buffer_apply_tag (commandbuf_BM, nesting_cmdtag_BM,
                             &stacloseit, &closeit);
  if (depth < CMD_MAXNEST_BM)
    gtk_text_buffer_apply_tag (commandbuf_BM,
                               close_cmdtags_BM[depth],
                               &stacloseit, &closeit);
  struct parenoffset_stBM po = {        //
    .paroff_open = openoff,.paroff_close = closeoff + closelen,
    .paroff_xtra = -1,
    .paroff_openlen = openlen,.paroff_closelen = closelen,
    .paroff_xtralen = 0,.paroff_depth = depth
  };
  cmd_add_parens_BM (&po);
  return;
}                               /* end parsnesting_guicmd_BM */


void
parsstartnesting_guicmd_BM (struct parser_stBM *pars, int depth,
                            enum lexdelim_enBM xtradelim,
                            unsigned xtralinpos,
                            unsigned xtracolpos,
                            enum lexdelim_enBM opendelim,
                            unsigned openlinpos,
                            unsigned opencolpos,
                            enum lexdelim_enBM closedelim,
                            unsigned closelinpos, unsigned closecolpos)
{
  ASSERT_BM (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  ASSERT_BM (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  const char *xtradelstr = delimstr_BM (xtradelim);
  const char *opendelstr = delimstr_BM (opendelim);
  const char *closedelstr = delimstr_BM (closedelim);
  GtkTextIter xtrait = EMPTY_TEXT_ITER_BM, endxtrait = EMPTY_TEXT_ITER_BM;
  GtkTextIter openit = EMPTY_TEXT_ITER_BM, endopenit = EMPTY_TEXT_ITER_BM;
  GtkTextIter closeit = EMPTY_TEXT_ITER_BM, stacloseit = EMPTY_TEXT_ITER_BM;
  //
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &xtrait, xtralinpos - 1);
  gtk_text_iter_forward_chars (&xtrait, xtracolpos);
  endxtrait = xtrait;
  int xtraoff = gtk_text_iter_get_offset (&xtrait);
  int xtralen = g_utf8_strlen (xtradelstr, -1);
  gtk_text_iter_forward_chars (&endxtrait, xtralen);
  gtk_text_buffer_apply_tag (commandbuf_BM, nesting_cmdtag_BM,
                             &xtrait, &endxtrait);
  if (depth < CMD_MAXNEST_BM)
    gtk_text_buffer_apply_tag (commandbuf_BM,
                               xtra_cmdtags_BM[depth], &xtrait, &endxtrait);
  //
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &openit, openlinpos - 1);
  gtk_text_iter_forward_chars (&openit, opencolpos);
  endopenit = openit;
  int openoff = gtk_text_iter_get_offset (&openit);
  int openlen = g_utf8_strlen (opendelstr, -1);
  gtk_text_iter_forward_chars (&endopenit, openlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, nesting_cmdtag_BM,
                             &openit, &endopenit);
  if (depth < CMD_MAXNEST_BM)
    gtk_text_buffer_apply_tag (commandbuf_BM,
                               open_cmdtags_BM[depth], &openit, &endopenit);
  //
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &stacloseit,
                                    closelinpos - 1);
  gtk_text_iter_forward_chars (&stacloseit, closecolpos);
  closeit = stacloseit;
  int closelen = g_utf8_strlen (closedelstr, -1);
  gtk_text_iter_forward_chars (&closeit, closelen);
  int closeoff = gtk_text_iter_get_offset (&closeit);
  gtk_text_buffer_apply_tag (commandbuf_BM, nesting_cmdtag_BM,
                             &stacloseit, &closeit);
  if (depth < CMD_MAXNEST_BM)
    gtk_text_buffer_apply_tag (commandbuf_BM,
                               close_cmdtags_BM
                               [depth], &stacloseit, &closeit);
  struct parenoffset_stBM po = {        //
    .paroff_open = openoff,.paroff_close = closeoff + closelen,.paroff_xtra =
      xtraoff,.paroff_openlen = openlen,.paroff_closelen =
      closelen,.paroff_xtralen = xtralen,.paroff_depth = depth
  };
  cmd_add_parens_BM (&po);
}                               /* end parsstartnesting_guicmd_BM */


////////////////////////////////////////////////////////////////


void
commandblinkstop_BM (void)
{
  if (commandblinkid_BM > 0)
    g_source_remove (commandblinkid_BM), commandblinkid_BM = 0;
  commandblinkoff_BM (NULL);
}                               /* end commandblinkstop_BM */

int
commandblinkoff_BM (gpointer data __attribute__ ((unused)))
{
  GtkTextIter startit = EMPTY_TEXT_ITER_BM;
  GtkTextIter endit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_bounds (commandbuf_BM, &startit, &endit);
  gtk_text_buffer_remove_tag (commandbuf_BM, blink_cmdtag_BM, &startit,
                              &endit);
  return G_SOURCE_REMOVE;
}                               /* end commandblinkoff_BM */

int
commandblinkon_BM (gpointer data __attribute__ ((unused)))
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
      gtk_text_buffer_apply_tag (commandbuf_BM, blink_cmdtag_BM, &openstartit,
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
      gtk_text_buffer_apply_tag (commandbuf_BM, blink_cmdtag_BM,
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
      gtk_text_buffer_apply_tag (commandbuf_BM, blink_cmdtag_BM, &xtrastartit,
                                 &xtraendit);
    }
  if (commandblinkid_BM > 0)
    {
      (void) g_timeout_add (UNBLINKDELAYMILLISEC_BM, commandblinkoff_BM,
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
timeoutrestoreopacitycmd_BM (gpointer data __attribute__ ((unused)))
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
          const objectval_tyBM *tinyarr[TINYSIZE_BM] = {
          };
          const objectval_tyBM **arr =
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
                             __attribute__ ((unused)), gpointer data)
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
                               __attribute__ ((unused)), gpointer data)
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
                          __attribute__ ((unused)),
                          gpointer data __attribute__ ((unused)))
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
        replacecompletionbyidcmd_BM (NULL, keyix);
      else
        replacecompletionbynamecmd_BM (NULL, keyix);
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
                 objectval_tyBM * parsownob;
    );
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
      parsecommandbuf_BM (cmdpars, (struct stackframe_stBM *) &_);
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
      parsecommandbuf_BM (cmdpars, (struct stackframe_stBM *) &_);
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
      if (!oldgui_BM)
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
cssparsingerror_BM (GtkCssProvider * prov __attribute__ ((unused)),
                    GtkCssSection * section, GError * err,
                    gpointer data __attribute__ ((unused)))
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
  pagetitle_brotag_BM =         //
    gtk_text_tag_table_lookup (browsertagtable_BM, "pagetitle_brotag");
  if (!pagetitle_brotag_BM)
    FATAL_BM ("cannot find pagetitle_brotag_BM");
  objtitle_brotag_BM =          //
    gtk_text_tag_table_lookup (browsertagtable_BM, "objtitle_brotag");
  if (!objtitle_brotag_BM)
    FATAL_BM ("cannot find objtitle_brotag_BM");
  valtitle_brotag_BM =          //
    gtk_text_tag_table_lookup (browsertagtable_BM, "valtitle_brotag");
  if (!valtitle_brotag_BM)
    FATAL_BM ("cannot find valtitle_brotag_BM");
  focustitle_brotag_BM =        //
    gtk_text_tag_table_lookup (browsertagtable_BM, "focustitle_brotag");
  if (!focustitle_brotag_BM)
    FATAL_BM ("cannot find focustitle_brotag_BM");
  objcommtitle_brotag_BM =      //
    gtk_text_tag_table_lookup (browsertagtable_BM, "objcommtitle_brotag");
  if (!objcommtitle_brotag_BM)
    FATAL_BM ("cannot find objcommtitle_brotag_BM");
  objnametitle_brotag_BM =      //
    gtk_text_tag_table_lookup (browsertagtable_BM, "objnametitle_brotag");
  if (!objnametitle_brotag_BM)
    FATAL_BM ("cannot find objnametitle_brotag_BM");
  objidtitle_brotag_BM =        //
    gtk_text_tag_table_lookup (browsertagtable_BM, "objidtitle_brotag");
  if (!objidtitle_brotag_BM)
    FATAL_BM ("cannot find objidtitle_brotag_BM");
  objid_brotag_BM =             //
    gtk_text_tag_table_lookup (browsertagtable_BM, "objid_brotag");
  if (!objid_brotag_BM)
    FATAL_BM ("cannot find objid_brotag_BM");
  objname_brotag_BM =           //
    gtk_text_tag_table_lookup (browsertagtable_BM, "objname_brotag");
  if (!objname_brotag_BM)
    FATAL_BM ("cannot find objname_brotag_BM");
  objrefcomm_brotag_BM =        //
    gtk_text_tag_table_lookup (browsertagtable_BM, "objrefcomm_brotag");
  if (!objrefcomm_brotag_BM)
    FATAL_BM ("cannot find objrefcomm_brotag_BM");
  nest_brotag_BM =              //
    gtk_text_tag_table_lookup (browsertagtable_BM, "nest_brotag");
  if (!nest_brotag_BM)
    FATAL_BM ("cannot find nest_brotag_BM");
  blink_brotag_BM =             //
    gtk_text_tag_table_lookup (browsertagtable_BM, "blink_brotag");
  if (!blink_brotag_BM)
    FATAL_BM ("cannot find blink_brotag_BM");
  num_brotag_BM =               //
    gtk_text_tag_table_lookup (browsertagtable_BM, "num_brotag");
  if (!num_brotag_BM)
    FATAL_BM ("cannot find num_brotag_BM");
  toodeep_brotag_BM =           //
    gtk_text_tag_table_lookup (browsertagtable_BM, "toodeep_brotag");
  if (!toodeep_brotag_BM)
    FATAL_BM ("cannot find toodeep_brotag_BM");
  str_brotag_BM =               //
    gtk_text_tag_table_lookup (browsertagtable_BM, "str_brotag");
  if (!str_brotag_BM)
    FATAL_BM ("cannot find str_brotag_BM");
  stresc_brotag_BM =            //
    gtk_text_tag_table_lookup (browsertagtable_BM, "stresc_brotag");
  if (!stresc_brotag_BM)
    FATAL_BM ("cannot find stresc_brotag_BM");
  miscomm_brotag_BM =           //
    gtk_text_tag_table_lookup (browsertagtable_BM, "miscomm_brotag");
  if (!miscomm_brotag_BM)
    FATAL_BM ("cannot find miscomm_brotag_BM");
  epilogue_brotag_BM =          //
    gtk_text_tag_table_lookup (browsertagtable_BM, "epilogue_brotag");
  if (!epilogue_brotag_BM)
    FATAL_BM ("cannot find epilogue_brotag_BM");
  ////////////////
  errored_cmdtag_BM =           //
    gtk_text_tag_table_lookup (commandtagtable_BM, "errored_cmdtag");
  if (!errored_cmdtag_BM)
    FATAL_BM ("cannot find errored_cmdtag");
  skipped_cmdtag_BM =           //
    gtk_text_tag_table_lookup (commandtagtable_BM, "skipped_cmdtag");
  if (!skipped_cmdtag_BM)
    FATAL_BM ("cannot find skipped_cmdtag");
  commentinside_cmdtag_BM =     //
    gtk_text_tag_table_lookup (commandtagtable_BM, "commentinside_cmdtag");
  if (!commentinside_cmdtag_BM)
    FATAL_BM ("cannot find commentinside_cmdtag");
  commentsign_cmdtag_BM =       //
    gtk_text_tag_table_lookup (commandtagtable_BM, "commentsign_cmdtag");
  if (!commentsign_cmdtag_BM)
    FATAL_BM ("cannot find commentsign_cmdtag");
  delim_cmdtag_BM =             //
    gtk_text_tag_table_lookup (commandtagtable_BM, "delim_cmdtag");
  if (!delim_cmdtag_BM)
    FATAL_BM ("cannot find delim_cmdtag");
  knowname_cmdtag_BM =          //
    gtk_text_tag_table_lookup (commandtagtable_BM, "knowname_cmdtag");
  if (!knowname_cmdtag_BM)
    FATAL_BM ("cannot find knowname_cmdtag");
  newname_cmdtag_BM =           //
    gtk_text_tag_table_lookup (commandtagtable_BM, "newname_cmdtag");
  if (!newname_cmdtag_BM)
    FATAL_BM ("cannot find newname_cmdtag");
  //
  id_cmdtag_BM =                //
    gtk_text_tag_table_lookup (commandtagtable_BM, "id_cmdtag");
  if (!id_cmdtag_BM)
    FATAL_BM ("cannot find id_cmdtag");
  //
  number_cmdtag_BM =            //
    gtk_text_tag_table_lookup (commandtagtable_BM, "number_cmdtag");
  if (!number_cmdtag_BM)
    FATAL_BM ("cannot find number_cmdtag");
  //
  stringsign_cmdtag_BM =        //
    gtk_text_tag_table_lookup (commandtagtable_BM, "stringsign_cmdtag");
  if (!stringsign_cmdtag_BM)
    FATAL_BM ("cannot find stringsign_cmdtag");
  //
  stringinside_cmdtag_BM =      //
    gtk_text_tag_table_lookup (commandtagtable_BM, "stringinside_cmdtag");
  if (!stringinside_cmdtag_BM)
    FATAL_BM ("cannot find stringinside_cmdtag");
  //
  dollar_cmdtag_BM =            //
    gtk_text_tag_table_lookup (commandtagtable_BM, "dollar_cmdtag");
  if (!dollar_cmdtag_BM)
    FATAL_BM ("cannot find dollar_cmdtag");
  nesting_cmdtag_BM =           //
    gtk_text_tag_table_lookup (commandtagtable_BM, "nesting_cmdtag");
  if (!nesting_cmdtag_BM)
    FATAL_BM ("cannot find nesting_cmdtag");
  blink_cmdtag_BM =             //
    gtk_text_tag_table_lookup (commandtagtable_BM, "blink_cmdtag");
  if (!blink_cmdtag_BM)
    FATAL_BM ("cannot find blink_cmdtag");
  ////////////////
  code_logtag_BM =              //
    gtk_text_tag_table_lookup (logtagtable_BM, "code_logtag");
  if (!code_logtag_BM)
    FATAL_BM ("cannot find code_logtag");
  error_logtag_BM =             //
    gtk_text_tag_table_lookup (logtagtable_BM, "error_logtag");
  if (!error_logtag_BM)
    FATAL_BM ("cannot find error_logtag");
  time_logtag_BM =              //
    gtk_text_tag_table_lookup (logtagtable_BM, "time_logtag");
  if (!time_logtag_BM)
    FATAL_BM ("cannot find time_logtag");
  id_logtag_BM =                //
    gtk_text_tag_table_lookup (logtagtable_BM, "id_logtag");
  if (!id_logtag_BM)
    FATAL_BM ("cannot find id_logtag");
  name_logtag_BM =              //
    gtk_text_tag_table_lookup (logtagtable_BM, "name_logtag");
  if (!name_logtag_BM)
    FATAL_BM ("cannot find name_logtag");
  comment_logtag_BM =           //
    gtk_text_tag_table_lookup (logtagtable_BM, "comment_logtag");
  if (!comment_logtag_BM)
    FATAL_BM ("cannot find comment_logtag");
  command_logtag_BM =           //
    gtk_text_tag_table_lookup (logtagtable_BM, "command_logtag");
  if (!command_logtag_BM)
    FATAL_BM ("cannot find command_logtag");
}                               /* end initialize_gui_tags_BM */

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
  g_signal_connect (appgarbcoll, "activate", garbcollgui_BM, NULL);
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
initialize_oldgui_command_scrollview_BM (void)
{
  commandbuf_BM = gtk_text_buffer_new (commandtagtable_BM);
  ASSERT_BM (GTK_IS_TEXT_BUFFER (commandbuf_BM));
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
                    G_CALLBACK (handlekeypresscmd_BM), NULL);
  g_signal_connect (commandbuf_BM, "end-user-action",
                    G_CALLBACK (enduseractioncmd_BM), NULL);
  g_signal_connect (commandview_BM, "populate-popup",
                    G_CALLBACK (populatepopupcmd_BM), NULL);
  g_signal_connect (commandbuf_BM, "mark-set",
                    G_CALLBACK (marksetcmd_BM), NULL);
  GtkWidget *commandscrolw = gtk_scrolled_window_new (NULL, NULL);
  gtk_container_add (GTK_CONTAINER (commandscrolw), commandview_BM);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW
                                  (commandscrolw),
                                  GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  return commandscrolw;
}                               /* end initialize_oldgui_command_scollview_BM */



GtkWidget *
initialize_log_scrollview_BM (void)
{
  logbuf_BM = gtk_text_buffer_new (logtagtable_BM);
  logview_BM = gtk_text_view_new_with_buffer (logbuf_BM);
  gtk_widget_set_name (logview_BM, "logview");
  g_signal_connect (logview_BM, "populate-popup",
                    G_CALLBACK (populatepopuplog_BM), NULL);
  gtk_text_view_set_editable (GTK_TEXT_VIEW (logview_BM), false);
  GtkWidget *logscrolw = gtk_scrolled_window_new (NULL, NULL);
  gtk_container_add (GTK_CONTAINER (logscrolw), logview_BM);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW
                                  (logscrolw),
                                  GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
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
initialize_gui_BM (const char *builderfile, const char *cssfile)
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
  //gtk_builder_add_callback_symbols (bld, "quitaction_BM", quitgui_BM, NULL);
  mainwin_BM = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_style_context_add_provider_for_screen
    (gtk_window_get_screen (GTK_WINDOW (mainwin_BM)),
     GTK_STYLE_PROVIDER (cssprovider),
     GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
  ////////////////
  GtkWidget *mainvbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
  gtk_container_add (GTK_CONTAINER (mainwin_BM), mainvbox);
  ///////////////
  (void) initialize_gui_menubar_BM (mainvbox, bld);
  ///////////////
  GtkWidget *paned1 = gtk_paned_new (GTK_ORIENTATION_VERTICAL);
  gtk_paned_set_wide_handle (GTK_PANED (paned1), true);
  gtk_paned_set_position (GTK_PANED (paned1), 330);
  gtk_box_pack_start (GTK_BOX (mainvbox), paned1,
                      BOXEXPAND_BM, BOXFILL_BM, 2);
  browserbuf_BM = gtk_text_buffer_new (browsertagtable_BM);
  {
    GtkTextIter brit = EMPTY_TEXT_ITER_BM;
    GtkTextIter endtit = EMPTY_TEXT_ITER_BM;
    gtk_text_buffer_get_start_iter (browserbuf_BM, &brit);
    gtk_text_buffer_insert_with_tags (browserbuf_BM, &brit, "** BROWSER **",
                                      -1, pagetitle_brotag_BM, NULL);
    gtk_text_buffer_insert (browserbuf_BM, &brit, "\n\n", 2);
    endtit = brit;
    gtk_text_iter_backward_char (&endtit);
    browserendtitleoffset_BM =  //
      gtk_text_iter_get_offset (&endtit);
  }
  browserview_BM = gtk_text_view_new_with_buffer (browserbuf_BM);
  gtk_widget_set_name (browserview_BM, "browserview");
  gtk_text_view_set_editable (GTK_TEXT_VIEW (browserview_BM), false);
  g_signal_connect (browserbuf_BM, "mark-set",
                    G_CALLBACK (marksetbrows_BM), NULL);
  g_signal_connect (browserview_BM, "populate-popup",
                    G_CALLBACK (populatepopupbrow_BM), NULL);
  GtkWidget *browserscrolw = gtk_scrolled_window_new (NULL, NULL);
  gtk_container_add (GTK_CONTAINER (browserscrolw), browserview_BM);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW
                                  (browserscrolw),
                                  GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  browserobsize_BM = 13;
  browserobulen_BM = 0;
  browsedobj_BM = calloc (browserobsize_BM, sizeof (struct browsedobj_stBM));
  if (!browsedobj_BM)
    FATAL_BM ("calloc failed for %u browsed objects (%m)", browserobsize_BM);
  browsednvsize_BM = 7;
  browsednvulen_BM = 0;
  browsedval_BM = calloc (browsednvsize_BM, sizeof (struct browsedval_stBM));
  if (!browsedval_BM)
    FATAL_BM ("calloc failed for %u browsed values (%m)", browsednvsize_BM);
  //
  GtkWidget *commandscrolw = initialize_oldgui_command_scrollview_BM ();
  GtkWidget *logscrolw = initialize_log_scrollview_BM ();
  //
  gtk_paned_add1 (GTK_PANED (paned1), browserscrolw);
  GtkWidget *paned2 = gtk_paned_new (GTK_ORIENTATION_VERTICAL);
  gtk_paned_set_wide_handle (GTK_PANED (paned2), true);
  gtk_paned_set_position (GTK_PANED (paned2), 200);
  gtk_paned_add2 (GTK_PANED (paned1), paned2);
  gtk_paned_add1 (GTK_PANED (paned2), commandscrolw);
  gtk_paned_add2 (GTK_PANED (paned2), logscrolw);
  gtk_window_set_title (GTK_WINDOW (mainwin_BM), "bismon");
  gtk_window_set_default_size (GTK_WINDOW (mainwin_BM), 650, 720);
  // perhaps run the GC twice a second
  g_timeout_add (500, guiperiodicgarbagecollection_BM, NULL);
  gtk_widget_show_all (GTK_WIDGET (mainwin_BM));
}                               /* end initialize_gui_BM */




void
marksetcmd_BM (GtkTextBuffer * txbuf, GtkTextIter * txit,
               GtkTextMark * txmark, gpointer data __attribute__ ((unused)))
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
                 GtkTextMark * txmark, gpointer data __attribute__ ((unused)))
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


extern bool did_deferredgtk_BM (void);
gboolean
guiperiodicgarbagecollection_BM (gpointer data __attribute__ ((unused)))
{
  ASSERT_BM (data == NULL);
  did_deferredgtk_BM ();
  if (atomic_load (&want_garbage_collection_BM) && gtk_main_level () <= 1)
    {
      full_garbage_collection_BM (NULL);
    }
  return TRUE;                  // repeat again later
}                               /* end guiperiodicgarbagecollection_BM */

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
      send2_BM ((const value_tyBM) _.val, BMP_browse_value,
                (struct stackframe_stBM *) &_,
                taggedint_BM (maxdepth), taggedint_BM (curdepth));
    }
}                               /* end browse_value_BM */


// eof gui_BM.c
