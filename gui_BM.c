// file gui_BM.c
#include "bismon.h"

GtkWidget *mainwin_BM;
GtkWidget *errormessagedialog_BM;
FILE *gui_command_log_file_BM;

// for readability, gravity argument to gtk_text_buffer_create_mark
#define RIGHT_GRAVITY_BM FALSE
#define LEFT_GRAVITY_BM TRUE
#define EMPTY_TEXT_ITER_BM (GtkTextIter){}
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

#define BLINKDELAYMILLISEC_BM 750
#define UNBLINKDELAYMILLISEC_BM 400

/// the browsed objects
unsigned browserobsize_BM;      /* allocated size of browsedobj_BM */
unsigned browserobulen_BM;      /* used length */
int browserobcurix_BM;          /* current index in browsedobj_BM */
struct browsedobj_stBM
{
  const objectval_tyBM *brow_obj;
  GtkTextMark *brow_ostartm;
  GtkTextMark *brow_oendm;
  int brow_depth;
  unsigned brow_parensize;      /* allocated size of brow_parenarr */
  unsigned brow_parenulen;      /* used length of brow_parenarr */
  struct parenoffset_stBM *brow_parenarr;
};
struct browsedobj_stBM *browsedobj_BM;

/// the browsed named values
unsigned browsednvsize_BM;      /* allocated size */
unsigned browsednvulen_BM;      /* unsigned length */
int browsednvcurix_BM;
struct browsedval_stBM
{
  const stringval_tyBM *brow_name;
  value_tyBM brow_val;
  GtkTextMark *brow_vstartmk;
  GtkTextMark *brow_vendmk;
  int brow_depth;
  unsigned brow_parensize;      /* allocated size of brow_parenarr */
  unsigned brow_parenulen;      /* used length of brow_parenarr */
  struct parenoffset_stBM *brow_parenarr;
};
struct browsedval_stBM *browsedval_BM;
guint browserblinkid_BM;
struct parenoffset_stBM browserblinkparens_BM;  /// offsets are absolute


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
const setval_tyBM *complsetcmd_BM;
/// begin and end offset for completion replacement
int compbegoffcmd_BM, compendoffcmd_BM;

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
GtkTextTag *command_logtag_BM;



GtkTextTag *errored_cmdtag_BM;
GtkTextTag *skipped_cmdtag_BM;
GtkTextTag *commentinside_cmdtag_BM;
GtkTextTag *commentsign_cmdtag_BM;
GtkTextTag *delim_cmdtag_BM;
GtkTextTag *knowname_cmdtag_BM;
GtkTextTag *newname_cmdtag_BM;
GtkTextTag *id_cmdtag_BM;
GtkTextTag *dollar_cmdtag_BM;
GtkTextTag *nesting_cmdtag_BM;
GtkTextTag *blink_cmdtag_BM;

#define CMD_MAXNEST_BM 64
GtkTextTag *open_cmdtags_BM[CMD_MAXNEST_BM];
GtkTextTag *close_cmdtags_BM[CMD_MAXNEST_BM];
GtkTextTag *xtra_cmdtags_BM[CMD_MAXNEST_BM];

#define BROWSE_MAXDEPTH_BM 48

// on cmd parse error, we setjmp to ....
static jmp_buf jmperrorcmd_BM;

// the periodic GC function
static gboolean guiperiodicgarbagecollection_BM (gpointer);

// the function to handle keypresses of cmd, for Return & Tab
static gboolean handlekeypresscmd_BM (GtkWidget *, GdkEventKey *, gpointer);
// the function to handle tabautocomplete in command
static void tabautocompletecmd_BM (void);

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


static parser_error_sigBM parserrorcmd_BM;
static parser_expand_dollarval_sigBM parsdollarvalcmd_BM;
static parser_expand_dollarobj_sigBM parsdollarobjcmd_BM;
static parser_expand_valexp_sigBM parsvalexpcmd_BM;
static parser_expand_objexp_sigBM parsobjexpcmd_BM;
static parser_expand_readmacro_sigBM parsreadmacroexpcmd_BM;
static parser_decorate_comment_sign_sigBM parscommentsigncmd_BM;
static parser_decorate_comment_inside_sigBM parscommentinsidecmd_BM;
static parser_decorate_delimiter_sigBM parsdelimcmd_BM;
static parser_decorate_id_sigBM parsidcmd_BM;
static parser_decorate_name_sigBM parsknownamecmd_BM;
static parser_decorate_name_sigBM parsnewnamecmd_BM;
static parser_decorate_nesting_sigBM parsnestingcmd_BM;
static parser_decorate_start_nesting_sigBM parsstartnestingcmd_BM;
const struct parserops_stBM parsop_command_build_BM = {
  .parsop_magic = PARSOPMAGIC_BM,
  .parsop_serial = 1,
  .parsop_nobuild = false,
  .parsop_error_rout = parserrorcmd_BM,
  .parsop_expand_dollarobj_rout = parsdollarobjcmd_BM,
  .parsop_expand_dollarval_rout = parsdollarvalcmd_BM,
  .parsop_expand_valexp_rout = parsvalexpcmd_BM,
  .parsop_expand_objexp_rout = parsobjexpcmd_BM,
  .parsop_expand_readmacro_rout = parsreadmacroexpcmd_BM,
  .parsop_decorate_comment_sign_rout = parscommentsigncmd_BM,
  .parsop_decorate_comment_inside_rout = parscommentinsidecmd_BM,
  .parsop_decorate_delimiter_rout = parsdelimcmd_BM,
  .parsop_decorate_id_rout = parsidcmd_BM,
  .parsop_decorate_known_name_rout = parsknownamecmd_BM,
  .parsop_decorate_new_name_rout = parsnewnamecmd_BM,
  .parsop_decorate_nesting_rout = parsnestingcmd_BM,
  .parsop_decorate_start_nesting_rout = parsstartnestingcmd_BM,
};

const struct parserops_stBM parsop_command_nobuild_BM = {
  .parsop_magic = PARSOPMAGIC_BM,
  .parsop_serial = 2,
  .parsop_nobuild = true,
  .parsop_error_rout = parserrorcmd_BM,
  .parsop_expand_dollarobj_rout = parsdollarobjcmd_BM,
  .parsop_expand_dollarval_rout = parsdollarvalcmd_BM,
  .parsop_expand_valexp_rout = parsvalexpcmd_BM,
  .parsop_expand_objexp_rout = parsobjexpcmd_BM,
  .parsop_expand_readmacro_rout = parsreadmacroexpcmd_BM,
  .parsop_decorate_comment_sign_rout = parscommentsigncmd_BM,
  .parsop_decorate_comment_inside_rout = parscommentinsidecmd_BM,
  .parsop_decorate_delimiter_rout = parsdelimcmd_BM,
  .parsop_decorate_id_rout = parsidcmd_BM,
  .parsop_decorate_known_name_rout = parsknownamecmd_BM,
  .parsop_decorate_new_name_rout = parsnewnamecmd_BM,
  .parsop_decorate_nesting_rout = parsnestingcmd_BM,
  .parsop_decorate_start_nesting_rout = parsstartnestingcmd_BM,
};

static void log_begin_message_BM (void);
static void log_object_message_BM (const objectval_tyBM * obj);
static void log_puts_message_BM (const char *msg);
static void log_printf_message_BM (const char *fmt, ...)
  __attribute__ ((format (printf, 1, 2)));
static void log_end_message_BM (void);


static void start_browse_object_BM (const objectval_tyBM * obj, int depth);

static void start_browse_named_value_BM (const stringval_tyBM * namev,
                                         const value_tyBM val, int depth);


static void browse_add_parens_BM (int openoff, int closeoff,
                                  int xtraoff, unsigned openlen,
                                  unsigned closelen, unsigned xtralen,
                                  int depth);

// starting offset of currently shown object or named value
static int browse_show_start_offset_BM (void);

static struct browsedobj_stBM *find_browsed_object_BM
  (const objectval_tyBM * obj);
static struct browsedval_stBM *find_browsed_named_value_BM
  (const char *valname);

static void runcommand_BM (bool erase);
static void run_then_erase_command_BM (void);
static void clear_command_BM (void);
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
gcmarkgui_BM (struct garbcoll_stBM *gc)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  if (browsedobj_BM)
    {
      for (unsigned ix = 0; ix < browserobulen_BM; ix++)
        gcmark_BM (gc, (value_tyBM) browsedobj_BM[ix].brow_obj, 0);
    };
  if (browsedval_BM)
    {
      for (unsigned ix = 0; ix < browsednvulen_BM; ix++)
        {
          gcmark_BM (gc, browsedval_BM[ix].brow_val, 0);
          gcmark_BM (gc, (value_tyBM) browsedval_BM[ix].brow_name, 0);
        }
    }
  if (complsetcmd_BM)
    gcmark_BM (gc, (value_tyBM) complsetcmd_BM, 0);
}                               /* end gcmarkgui_BM */

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
      GtkTextIter openstartit = EMPTY_TEXT_ITER_BM, openendit =
        EMPTY_TEXT_ITER_BM;
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
start_browse_object_BM (const objectval_tyBM * obj, int depth)
{
  browserblinkstop_BM ();
  assert (isobject_BM ((const value_tyBM) obj));
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
      assert (isobject_BM ((const value_tyBM) mdobj));
      int cmp = objectnamedcmp_BM (mdobj, obj);
      if (cmp <= 0)
        lo = md;
      else
        hi = md;
    }
  for (md = lo; md < hi; md++)
    {
      const objectval_tyBM *mdobj = browsedobj_BM[md].brow_obj;
      assert (isobject_BM ((const value_tyBM) mdobj));
      if (mdobj == obj)
        {                       // replacing existing object
          GtkTextIter startit = EMPTY_TEXT_ITER_BM, endit =
            EMPTY_TEXT_ITER_BM;
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
          browsedobj_BM[md].brow_depth = depth;
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
          browsedobj_BM[md].brow_depth = depth;
          browserobcurix_BM = md;
          browserit_BM = it;
          return;
        };
    };
  assert (browserobulen_BM == 0
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
  browsedobj_BM[browserobulen_BM].brow_depth = depth;
  browserobcurix_BM = 0;
  browserit_BM = it;
  browserobulen_BM++;
}                               /* end start_browse_object_BM */



struct browsedobj_stBM *
find_browsed_object_BM (const objectval_tyBM * obj)
{
  if (!isobject_BM ((const value_tyBM) obj))
    return NULL;
  int lo = 0, hi = browserobulen_BM, md = 0;
  while (lo + 8 < hi)
    {
      md = (lo + hi) / 2;
      const objectval_tyBM *mdobj = browsedobj_BM[md].brow_obj;
      assert (isobject_BM ((const value_tyBM) mdobj));
      int cmp = objectnamedcmp_BM (mdobj, obj);
      if (cmp <= 0)
        lo = md;
      else
        hi = md;
    }
  for (md = lo; md < hi; md++)
    {
      const objectval_tyBM *mdobj = browsedobj_BM[md].brow_obj;
      assert (isobject_BM ((const value_tyBM) mdobj));
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
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows;);
  _.objbrows = objbrows;
  int lo = 0, hi = browserobulen_BM, md = 0;
  while (lo + 8 < hi)
    {
      md = (lo + hi) / 2;
      const objectval_tyBM *mdobj = browsedobj_BM[md].brow_obj;
      assert (isobject_BM ((const value_tyBM) mdobj));
      int cmp = objectnamedcmp_BM (mdobj, objbrows);
      if (cmp <= 0)
        lo = md;
      else
        hi = md;
    }
  for (md = lo; md < hi; md++)
    {
      const objectval_tyBM *mdobj = browsedobj_BM[md].brow_obj;
      assert (isobject_BM ((const value_tyBM) mdobj));
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
          if (browsedobj_BM[md].brow_parenulen > 0)
            memset (browsedobj_BM[md].brow_parenarr, 0,
                    browsedobj_BM[md].brow_parenulen *
                    sizeof (struct parenoffset_stBM));
          free (browsedobj_BM[md].brow_parenarr);
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
      assert (isstring_BM ((const value_tyBM) browsedval_BM[md].brow_name));
      int cmp = strcmp (namstr, bytstring_BM (browsedval_BM[md].brow_name));
      if (cmp <= 0)
        lo = md;
      else
        hi = md;
    }
  for (md = lo; md < hi; md++)
    {
      struct browsedval_stBM *mdval = browsedval_BM + md;
      assert (isstring_BM ((const value_tyBM) mdval->brow_name));
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
          mdval->brow_depth = depth;
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
          mdval->brow_depth = depth;
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
  browsedval_BM[browsednvulen_BM].brow_depth = depth;
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
      assert (isstring_BM ((const value_tyBM) browsedval_BM[md].brow_name));
      int cmp = strcmp (namestr, bytstring_BM (browsedval_BM[md].brow_name));
      if (cmp <= 0)
        lo = md;
      else
        hi = md;
    }
  for (md = lo; md < hi; md++)
    {
      struct browsedval_stBM *mdval = browsedval_BM + md;
      assert (isstring_BM ((const value_tyBM) mdval->brow_name));
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
      assert (isstring_BM ((const value_tyBM) browsedval_BM[md].brow_name));
      int cmp = strcmp (namstr, bytstring_BM (browsedval_BM[md].brow_name));
      if (cmp <= 0)
        lo = md;
      else
        hi = md;
    }
  for (md = lo; md < hi; md++)
    {
      struct browsedval_stBM *mdval = browsedval_BM + md;
      assert (isstring_BM ((const value_tyBM) mdval->brow_name));
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
      assert (isstring_BM ((const value_tyBM) browsedval_BM[md].brow_name));
      int cmp = strcmp (namstr, bytstring_BM (browsedval_BM[md].brow_name));
      if (cmp <= 0)
        lo = md;
      else
        hi = md;
    }
  for (md = lo; md < hi; md++)
    {
      struct browsedval_stBM *mdval = browsedval_BM + md;
      assert (isstring_BM ((const value_tyBM) mdval->brow_name));
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
          if (mdval->brow_parenulen > 0)
            memset (mdval->brow_parenarr,
                    0,
                    mdval->brow_parenulen * sizeof (struct parenoffset_stBM));
          free (mdval->brow_parenarr);
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
  // exactly one of browserobcurix_BM or browsednvcurix_BM is active so >=0
  assert (browserobcurix_BM >= 0 || browsednvcurix_BM >= 0);
  assert (browserobcurix_BM < 0 || browsednvcurix_BM < 0);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  if (browserobcurix_BM >= 0)
    {
      assert (browserobcurix_BM < (int) browserobulen_BM);
      assert (browserobulen_BM <= browserobsize_BM);
      assert (browsednvcurix_BM < 0);
      assert (browsedobj_BM[browserobcurix_BM].brow_obj != NULL);
      assert (browsedobj_BM[browserobcurix_BM].brow_ostartm != NULL);
      assert (browsedobj_BM[browserobcurix_BM].brow_oendm != NULL);
      gtk_text_buffer_get_iter_at_mark
        (browserbuf_BM, &it, browsedobj_BM[browserobcurix_BM].brow_ostartm);
    }
  else if (browsednvcurix_BM >= 0)
    {
      assert (browsednvcurix_BM < (int) browsednvulen_BM);
      assert (browsednvulen_BM <= browsednvsize_BM);
      assert (browserobcurix_BM < 0);
      assert (browsedval_BM[browsednvcurix_BM].brow_name != NULL);
      assert (browsedval_BM[browsednvcurix_BM].brow_val != NULL);
      assert (browsedval_BM[browsednvcurix_BM].brow_vstartmk != NULL);
      assert (browsedval_BM[browsednvcurix_BM].brow_vendmk != NULL);
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
                      unsigned xtralen, int depth)
{
  assert ((browserobcurix_BM >= 0
           && browserobcurix_BM < (int) browserobulen_BM)
          || (browsednvcurix_BM >= 0
              && browsednvcurix_BM < (int) browsednvulen_BM));
  if (browserobcurix_BM >= 0)
    {
      assert (browsednvcurix_BM < 0);
      struct browsedobj_stBM *curbrob = browsedobj_BM + browserobcurix_BM;
      unsigned oldulen = curbrob->brow_parenulen;
      if (oldulen + 1 >= curbrob->brow_parensize)
        {
          unsigned newsiz = prime_above_BM (5 * oldulen / 4 + 7);
          struct parenoffset_stBM *newarr =
            calloc (newsiz, sizeof (struct parenoffset_stBM));
          if (!newarr)
            FATAL_BM ("calloc failed for %u parens (%m)", newsiz);
          if (oldulen > 0)
            memcpy (newarr, curbrob->brow_parenarr,
                    oldulen * sizeof (struct parenoffset_stBM));
          free (curbrob->brow_parenarr), curbrob->brow_parenarr = newarr;
          curbrob->brow_parensize = newsiz;
        }
      struct parenoffset_stBM *curpar = curbrob->brow_parenarr + oldulen;
      curpar->paroff_open = openoff;
      curpar->paroff_close = closeoff;
      curpar->paroff_xtra = xtraoff;
      curpar->paroff_openlen = openlen;
      curpar->paroff_closelen = closelen;
      curpar->paroff_xtralen = xtralen;
      curpar->paroff_depth = depth;
      curbrob->brow_parenulen = oldulen + 1;
    }
  else if (browsednvcurix_BM >= 0)
    {
      assert (browserobcurix_BM < 0);
      struct browsedval_stBM *curbrval = browsedval_BM + browsednvcurix_BM;
      unsigned oldulen = curbrval->brow_parenulen;
      if (oldulen + 1 >= curbrval->brow_parenulen)
        {
          unsigned newsiz = prime_above_BM (5 * oldulen / 4 + 7);
          struct parenoffset_stBM *newarr =
            calloc (newsiz, sizeof (struct parenoffset_stBM));
          if (!newarr)
            FATAL_BM ("calloc failed for %u parens (%m)", newsiz);
          if (oldulen > 0)
            memcpy (newarr, curbrval->brow_parenarr,
                    oldulen * sizeof (struct parenoffset_stBM));
          free (curbrval->brow_parenarr), curbrval->brow_parenarr = newarr;
          curbrval->brow_parensize = newsiz;
        }
      struct parenoffset_stBM *curpar = curbrval->brow_parenarr + oldulen;
      curpar->paroff_open = openoff;
      curpar->paroff_close = closeoff;
      curpar->paroff_xtra = xtraoff;
      curpar->paroff_openlen = openlen;
      curpar->paroff_closelen = closelen;
      curpar->paroff_xtralen = xtralen;
      curpar->paroff_depth = depth;
      curbrval->brow_parenulen = oldulen + 1;
    }
  else
    FATAL_BM ("no browsed object or named value");
}                               /* end browse_add_parens_BM */


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
  bool isfocused = (GLOBAL_BM (gui_focus_obj) == objbrows);
  _.objbrows = objbrows;
  _.objsel = objsel;
  start_browse_object_BM (objbrows, browsdepth);
  const char *nambrows = findobjectname_BM (objbrows);
  gtk_text_buffer_insert_with_tags      //
    (browserbuf_BM, &browserit_BM, "\342\201\202 " /* U+2042 ASTERISM ⁂ */ ,
     -1, isfocused ? focustitle_brotag_BM : objtitle_brotag_BM, NULL);
  char idbuf[32];
  memset (idbuf, 0, sizeof (idbuf));
  idtocbuf32_BM (objid_BM (objbrows), idbuf);
  if (nambrows)
    {
      gtk_text_buffer_insert_with_tags
        (browserbuf_BM, &browserit_BM,
         nambrows, -1,
         isfocused ? focustitle_brotag_BM : objtitle_brotag_BM,
         objnametitle_brotag_BM, NULL);
      gtk_text_buffer_insert_with_tags
        (browserbuf_BM, &browserit_BM,
         " |=", -1, objtitle_brotag_BM, objcommtitle_brotag_BM, NULL);
      gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                        &browserit_BM, idbuf, -1,
                                        isfocused ?
                                        focustitle_brotag_BM :
                                        objtitle_brotag_BM,
                                        objcommtitle_brotag_BM,
                                        objidtitle_brotag_BM, NULL);
      gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                        &browserit_BM, "|", -1,
                                        isfocused ?
                                        focustitle_brotag_BM :
                                        objtitle_brotag_BM,
                                        objcommtitle_brotag_BM, NULL);
    }
  else
    {                           /// anonymous browsed object
      gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                        &browserit_BM, idbuf, -1,
                                        isfocused ?
                                        focustitle_brotag_BM :
                                        objtitle_brotag_BM,
                                        objidtitle_brotag_BM, NULL);
    };
  gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", -1);
  send1_BM ((const value_tyBM) objbrows, objsel,
            (struct stackframe_stBM *) &_, taggedint_BM (browsdepth));
  gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", -1);
  gtk_text_buffer_move_mark (browserbuf_BM,
                             browsedobj_BM[browserobcurix_BM].brow_oendm,
                             &browserit_BM);
}                               /* end browse_object_gui_BM */



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
  assert (browsednvcurix_BM >= 0);
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM, "$", -1,
                                    valtitle_brotag_BM, NULL);
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,
                                    bytstring_BM (namev), -1,
                                    valtitle_brotag_BM, NULL);
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,
                                    "  \342\234\247"
                                    /* U+2727 WHITE FOUR POINTED STAR ✧ */ ,
                                    -1, objtitle_brotag_BM,
                                    // objcommtitle_brotag_BM,
                                    NULL);
  {
    char hcombuf[32];
    memset (hcombuf, 0, sizeof (hcombuf));
    snprintf (hcombuf, sizeof (hcombuf), " |h:%u|", valhash_BM (val));
    gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,
                                      hcombuf, -1,
                                      objcommtitle_brotag_BM, NULL);
  }
  gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", -1);
  send2_BM ((const value_tyBM) _.val, objsel, (struct stackframe_stBM *) &_,
            taggedint_BM (browsdepth), taggedint_BM (0));
  gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", -1);
  gtk_text_buffer_move_mark (browserbuf_BM,
                             browsedval_BM[browsednvcurix_BM].brow_vendmk,
                             &browserit_BM);
}                               /* end browse_named_value_gui_BM */



void quit_BM (void);
void
quit_BM (void)
{
  //  printf ("quit_BM\n");
  GtkWidget *quitdialog =       //
    gtk_message_dialog_new_with_markup  //
    (GTK_WINDOW (mainwin_BM),
     GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_QUESTION,
     GTK_BUTTONS_OK_CANCEL, "Quit without dumping?");
  int resp = gtk_dialog_run (GTK_DIALOG (quitdialog));
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
}                               /* end quit_BM */

void exit_BM (void);
void
exit_BM (void)
{
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
}                               /* end exit_BM */

void do_dump_BM (void);
void
do_dump_BM (void)
{
  extern char *dump_dir_bm;
  assert (dump_dir_bm != NULL);
  log_begin_message_BM ();
  log_printf_message_BM ("dumping into %s directory", dump_dir_bm);
  {
    char *rd = realpath (dump_dir_bm, NULL);
    if (rd)
      {
        log_printf_message_BM (" (%s)", rd);
        free (rd);
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
}                               /* end do_dump_BM */

static void do_garbcoll_BM (void);
void
do_garbcoll_BM (void)
{
  assert (mainthreadid_BM == pthread_self ());
  log_begin_message_BM ();
  log_puts_message_BM ("forced garbage collection");
  log_end_message_BM ();
  fullgarbagecollection_BM (NULL);
}                               /* end do_garbcoll_BM */

bool deletemainwin_BM (GtkWidget *, GdkEvent *, gpointer);
bool
deletemainwin_BM (GtkWidget * widget
                  __attribute__ ((unused)), GdkEvent * ev
                  __attribute__ ((unused)), gpointer data
                  __attribute__ ((unused)))
{
  // printf ("deletemainwin_BM\n");
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
}

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
      ln = vsnprintf (buf, ln + 1, fmt, args);
      va_end (args);
    }
  log_puts_message_BM (buf);
  if (buf != smallbuf)
    free (buf);
}                               /* end log_printf_message_BM */

void
parserrorcmd_BM (struct parser_stBM *pars,
                 unsigned lineno, unsigned colpos, char *msg)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
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
  longjmp (jmperrorcmd_BM, 1);
}                               /* end parserrorcmd_BM */



// for $<var>
value_tyBM
parsdollarvalcmd_BM (struct parser_stBM *pars,
                     unsigned lineno,
                     unsigned colpos,
                     const value_tyBM varname, struct stackframe_stBM *stkf)
{
  const char *varstr = NULL;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM val;);
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  bool nobuild = parsops && parsops->parsop_nobuild;
  if (isstring_BM (varname))
    varstr = bytstring_BM (varname);
  else if (isobject_BM (varname))
    varstr = findobjectname_BM (varname);
  if (!varstr)
    parsererrorprintf_BM (pars, lineno, colpos, "invalid $<var>");
  _.val = find_named_value_gui_BM (varstr);
  if (!_.val && !nobuild)
    parsererrorprintf_BM (pars, lineno, colpos, "not found $%s", varstr);
  GtkTextIter it = EMPTY_TEXT_ITER_BM, endit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  endit = it;
  gtk_text_iter_forward_chars (&endit, 1 + strlen (varstr));
  gtk_text_buffer_apply_tag (commandbuf_BM, dollar_cmdtag_BM, &it, &endit);
  return _.val;
}                               /* end parsdollarvalcmd_BM */


// for $:<var>
const objectval_tyBM *
parsdollarobjcmd_BM (struct parser_stBM *pars,
                     unsigned lineno, unsigned colpos,
                     const value_tyBM varname, struct stackframe_stBM *stkf)
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
  if (!varstr)
    parsererrorprintf_BM (pars, lineno, colpos, "invalid $:<var>");
  _.val = find_named_value_gui_BM (varstr);
  if (!_.val && !nobuild)
    parsererrorprintf_BM (pars, lineno, colpos, "not found $:%s", varstr);
  if (!isobject_BM (_.val) && !nobuild)
    parsererrorprintf_BM (pars, lineno, colpos, "non-object $:%s", varstr);
  GtkTextIter it = EMPTY_TEXT_ITER_BM, endit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  endit = it;
  gtk_text_iter_forward_chars (&endit, 2 + strlen (varstr));
  gtk_text_buffer_apply_tag (commandbuf_BM, dollar_cmdtag_BM, &it, &endit);
  return (const objectval_tyBM *) _.val;
}                               /* end parsdollarobjcmd_BM */

static bool
parseobjectcomplcmd_BM (struct parser_stBM *pars,
                        objectval_tyBM * obj, int depth,
                        struct stackframe_stBM *stkf,
                        struct parstoken_stBM *ptok);
#define MAXARGS_BM 9
bool
parseobjectcomplcmd_BM (struct parser_stBM *pars,
                        objectval_tyBM * targobj, int depth,
                        struct stackframe_stBM *stkf,
                        struct parstoken_stBM *ptok)
{
  if (!isparser_BM (pars))
    return false;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 struct parser_stBM * pars;
                 value_tyBM comp; objectval_tyBM * targobj;
                 objectval_tyBM * obattr; objectval_tyBM * obclass;
                 objectval_tyBM * obsel; const stringval_tyBM * name;
                 value_tyBM args[MAXARGS_BM];);
  _.pars = pars;
  _.targobj = targobj;
  struct parstoken_stBM tok = {
  };
  if (!ptok)
    {
      tok = parsertokenget_BM (pars);
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
        parsererrorprintf_BM (pars, lineno, colpos, "missing target for !&");
      bool gotval = false;
      _.comp = parsergetvalue_BM (pars, //
                                  (struct stackframe_stBM *) &_,        //
                                  depth + 1, &gotval);
      if (!gotval)
        parsererrorprintf_BM (pars, lineno, colpos, "missing value after !&");
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
        parsererrorprintf_BM (pars, lineno, colpos, "missing target for !:");
      parserskipspaces_BM (pars);
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
          struct parstoken_stBM tok = parsertokenget_BM (pars);
          if (tok.tok_kind == plex_LLONG)
            {
              gotindex = true;
              index = (int) tok.tok_llong;
            }
        }
      if (!gotattr && !gotindex)
        parsererrorprintf_BM (pars, lineno, colpos,
                              "missing attribute or index after !:");
      bool gotval = false;
      _.comp = parsergetvalue_BM (pars, //
                                  (struct stackframe_stBM *) &_,        //
                                  depth + 1, &gotval);
      if (!gotval)
        parsererrorprintf_BM (pars, lineno, colpos, "missing value after !:");
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
        parsererrorprintf_BM (pars, lineno, colpos, "missing target for !$");
      bool gotclass = false;
      _.obclass = parsergetobject_BM (pars,     //
                                      (struct stackframe_stBM *) &_,    //
                                      depth + 1, &gotclass);
      if (!gotclass)
        parsererrorprintf_BM (pars, lineno, colpos, "missing class after !$");
      if (!nobuild)
        {
          objputclass_BM (_.targobj, _.obclass);
          log_begin_message_BM ();
          log_puts_message_BM ("put class ");
          log_object_message_BM (_.obclass);
          log_puts_message_BM (" in object ");
          log_object_message_BM (_.targobj);
          log_puts_message_BM (".");
          log_end_message_BM ();
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
        parsererrorprintf_BM (pars, lineno, colpos, "missing target for !>");
      bool gotsel = false;
      _.obsel = parsergetobject_BM (pars,       //
                                    (struct stackframe_stBM *) &_,      //
                                    depth + 1, &gotsel);
      if (!gotsel)
        parsererrorprintf_BM (pars, arglineno,
                              argcolpos, "missing selector after !>");
      parserskipspaces_BM (pars);
      unsigned leftlineno = pars->pars_lineno;
      unsigned leftcolpos = pars->pars_colpos;
      tok = parsertokenget_BM (pars);
      if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_leftparen)
        parsererrorprintf_BM (pars, arglineno,
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
      tok = parsertokenget_BM (pars);
      if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_rightparen)
        parsererrorprintf_BM (pars, arglineno,
                              argcolpos,
                              "missing right paren after selector for !>");
      unsigned rightlineno = pars->pars_lineno;
      unsigned rightcolpos = pars->pars_colpos;
      parsnestingcmd_BM (pars, depth + 1, delim_leftparen,
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
              parsererrorprintf_BM (pars, arglineno, argcolpos,
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
        parsererrorprintf_BM (pars, lineno, colpos, "missing target for !-");
      bool gotattr = false;
      _.obattr = parsergetobject_BM (pars,      //
                                     (struct stackframe_stBM *) &_,     //
                                     0, &gotattr);
      if (!gotattr)
        parsererrorprintf_BM (pars, lineno, colpos,
                              "missing attribute after !-");
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
      tok = parsertokenget_BM (pars);
      if (tok.tok_kind != plex_NAMEDOBJ && tok.tok_kind != plex_CNAME)
        parsererrorprintf_BM (pars, lineno, colpos,
                              "no name to bind and show after $%%");
      if (!nobuild)
        {
          if (tok.tok_kind == plex_NAMEDOBJ)
            _.name = makestring_BM (findobjectname_BM (tok.tok_namedobj));
          else
            _.name = tok.tok_cname;
          assert (isstring_BM ((const value_tyBM) _.name));
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
        parsererrorprintf_BM (pars, lineno, colpos, "missing target for !^");
      tok = parsertokenget_BM (pars);
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
        parsererrorprintf_BM (pars, lineno, colpos, "bad space for !^");
    }
  else
    return false;
  return true;
}                               /* end parseobjectcomplcmd_BM */



// parse inside $(....)
value_tyBM
parsvalexpcmd_BM (struct parser_stBM * pars, unsigned lineno,
                  unsigned colpos, int depth, struct stackframe_stBM * stkf)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  bool nobuild = parsops && parsops->parsop_nobuild;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 struct parser_stBM *pars; value_tyBM resval;
                 value_tyBM srcval;
                 objectval_tyBM * obj; objectval_tyBM * obsel;
                 objectval_tyBM * obattr; closure_tyBM * clos;
                 value_tyBM otherval; const stringval_tyBM * name;
                 value_tyBM args[MAXARGS_BM];);
  _.pars = pars;
  unsigned srclineno = parserlineno_BM (pars);
  unsigned srccolpos = parsercolpos_BM (pars);
  bool gotsrcval = false;
  _.srcval =
    parsergetvalue_BM (pars, (struct stackframe_stBM *) &_, 0, &gotsrcval);
  if (!gotsrcval)
    parsererrorprintf_BM (pars, srclineno,
                          srccolpos, "expecting source value in $(...)");
  struct parstoken_stBM tok = {
  };
  for (;;)
    {
      parserskipspaces_BM (pars);
      tok = parsertokenget_BM (pars);
      if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_rightparen)
        {
          parsnestingcmd_BM (pars, depth, delim_dollarleftparen,
                             lineno, colpos, delim_rightparen,
                             parserlineno_BM (pars), parsercolpos_BM (pars));
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
            parsererrorprintf_BM (pars, lineno, colpos,
                                  "missing target for !>");
          bool gotsel = false;
          _.obsel = parsergetobject_BM (pars,   //
                                        (struct stackframe_stBM *) &_,  //
                                        0, &gotsel);
          if (!gotsel)
            parsererrorprintf_BM (pars, arglineno,
                                  argcolpos, "missing selector after !>");
          tok = parsertokenget_BM (pars);
          if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_leftparen)
            parsererrorprintf_BM (pars, arglineno,
                                  argcolpos,
                                  "missing left paren after selector for !>");
          int nbarg = 0;
          while (nbarg < MAXARGS_BM)
            {
              bool gotarg = false;
              _.args[nbarg] = parsergetvalue_BM (pars,  //
                                                 (struct stackframe_stBM *) &_, //
                                                 0, &gotarg);
              if (!gotarg)
                break;
              nbarg++;
            }
          tok = parsertokenget_BM (pars);
          if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_rightparen)
            parsererrorprintf_BM (pars, arglineno,
                                  argcolpos,
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
                  parsererrorprintf_BM (pars, arglineno, argcolpos,
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
            parsererrorprintf_BM (pars, lineno, colpos,
                                  "source value is not a closure for application");
          _.clos = (closure_tyBM *) _.srcval;
          int nbarg = 0;
          while (nbarg < MAXARGS_BM)
            {
              bool gotarg = false;
              _.args[nbarg] = parsergetvalue_BM (pars,  //
                                                 (struct stackframe_stBM *) &_, //
                                                 0, &gotarg);
              if (!gotarg)
                break;
              nbarg++;
            }
          tok = parsertokenget_BM (pars);
          if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_rightparen)
            parsererrorprintf_BM (pars, arglineno,
                                  argcolpos,
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
                  parsererrorprintf_BM (pars, arglineno, argcolpos,
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
      // !. <obattr> # to get a an attribute
      else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_exclamdot)
        {
          bool gotattr = false;
          parserskipspaces_BM (pars);
          unsigned atlineno = parserlineno_BM (pars);
          unsigned atcolpos = parsercolpos_BM (pars);
          if (!nobuild && !isobject_BM (_.srcval))
            parsererrorprintf_BM (pars, atlineno, atcolpos,
                                  "non object before !.");
          _.obattr =
            parsergetobject_BM (pars, (struct stackframe_stBM *) &_,
                                depth + 1, &gotattr);
          if (!gotattr)
            parsererrorprintf_BM (pars, atlineno, atcolpos,
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
          parserskipspaces_BM (pars);
          unsigned ixlineno = parserlineno_BM (pars);
          unsigned ixcolpos = parsercolpos_BM (pars);
          if (!nobuild && !isobject_BM (_.srcval))
            parsererrorprintf_BM (pars, ixlineno, ixcolpos,
                                  "non object before !@");
          _.otherval =
            parsergetvalue_BM (pars, (struct stackframe_stBM *) &_,
                               depth + 1, &gotindex);
          if (!gotindex)
            parsererrorprintf_BM (pars, ixlineno, ixcolpos,
                                  "expecting index value after !@");
          if (!nobuild)
            {
              if (!istaggedint_BM (_.otherval))
                parsererrorprintf_BM (pars, ixlineno, ixcolpos,
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
          tok = parsertokenget_BM (pars);
          if (tok.tok_kind != plex_NAMEDOBJ && tok.tok_kind != plex_CNAME)
            parsererrorprintf_BM (pars, lineno, colpos,
                                  "no name to bind and show after $%%");
          if (!nobuild)
            {
              if (tok.tok_kind == plex_NAMEDOBJ)
                _.name = makestring_BM (findobjectname_BM (tok.tok_namedobj));
              else
                _.name = tok.tok_cname;
              assert (isstring_BM ((const value_tyBM) _.name));
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
        parsererrorprintf_BM (pars, parserlineno_BM (pars),
                              parsercolpos_BM (pars),
                              "unexpected token in $(...)");
    }                           /* end for (;;) */
  return NULL;
}                               /* end parsvalexpcmd_BM */


// expand readmacro-s
value_tyBM parsreadmacroexpcmd_BM
  (struct parser_stBM * pars, unsigned lineno, unsigned colpos, int depth,
   const node_tyBM * nod, struct stackframe_stBM * stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 struct parser_stBM *pars;
                 value_tyBM resval; const node_tyBM * nod; value_tyBM crm;
                 const objectval_tyBM * conn;
    );
  _.pars = pars;
  _.nod = nod;
  if (depth > MAXDEPTHPARSE_BM)
    parsererrorprintf_BM (pars, lineno, colpos,
                          "too deep %d readmacro", depth);
  assert (isnode_BM ((const value_tyBM) nod));
  _.conn = nodeconn_BM ((const value_tyBM) _.nod);
  assert (isobject_BM ((const value_tyBM) _.conn));
  _.crm = objgetattr_BM (_.conn, BMP_command_readmacro);
  if (!isclosure_BM ((const value_tyBM) _.crm))
    {
      char crmidbuf[32];
      memset (crmidbuf, 0, sizeof (crmidbuf));
      idtocbuf32_BM (objid_BM (_.crm), crmidbuf);
      const char *crmname = findobjectname_BM (_.crm);
      if (crmname)
        parsererrorprintf_BM (pars, lineno, colpos,
                              "readmacro ^ %s |=%s| has bad `command_readmacro` attribute",
                              crmidbuf, crmname);
      else
        parsererrorprintf_BM (pars, lineno, colpos,
                              "readmacro ^ %s has bad `command_readmacro` attribute",
                              crmidbuf);
    }
  _.resval =                    //
    apply4_BM (_.crm, (struct stackframe_stBM *) &_,
               (value_tyBM) _.nod,
               taggedint_BM (lineno), taggedint_BM (colpos), pars);
  return _.resval;
}                               /* end parsreadmacroexpcmd_BM */



// parse inside $[...]
const objectval_tyBM *
parsobjexpcmd_BM (struct parser_stBM *pars,
                  unsigned lineno, unsigned colpos,
                  int depth, struct stackframe_stBM *stkf)
{
  const struct parserops_stBM *parsops = pars->pars_ops;
  bool nobuild = parsops && parsops->parsop_nobuild;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * obj; const stringval_tyBM * namev;
                 value_tyBM val;);
  assert (isparser_BM (pars));
  parserskipspaces_BM (pars);
  unsigned oblineno = parserlineno_BM (pars);
  unsigned obcolpos = parsercolpos_BM (pars);
  bool gotobj = false;
  struct parstoken_stBM tok = parsertokenget_BM (pars);
  // * <name> to create a new (userE) named object
  // !* <name> to create a new (global) named object
  if (tok.tok_kind == plex_DELIM
      && (tok.tok_delim == delim_exclamstar || tok.tok_delim == delim_star))
    {
      bool isglobal = (tok.tok_delim == delim_exclamstar);
      tok = parsertokenget_BM (pars);
      if (tok.tok_kind != plex_CNAME)
        parsererrorprintf_BM (pars, oblineno, obcolpos,
                              "expecting fresh name after * or !* in $[...]");
      _.namev = tok.tok_cname;
      gotobj = true;
      if (!nobuild)
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
        parsererrorprintf_BM (pars, oblineno, obcolpos,
                              "expecting $:<var> in $[...]");
    }
  //
  // ( <expr> ) to cast a value into an object
  else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_leftparen)
    {
      bool gotval = false;
      _.val =
        parsergetvalue_BM (pars, (struct stackframe_stBM *) &_, 0, &gotval);
      if (!gotval)
        parsererrorprintf_BM (pars, oblineno, obcolpos,
                              "expecting value after $[ (");
      tok = parsertokenget_BM (pars);
      if (tok.tok_kind != plex_DELIM || tok.tok_delim != delim_rightparen)
        parsererrorprintf_BM (pars,
                              pars->pars_lineno,
                              pars->pars_colpos,
                              "expecting right paren after $[ ( started at L%d:C%d",
                              oblineno, obcolpos);
      if (!nobuild && !isobject_BM (_.val))
        parsererrorprintf_BM (pars,
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
    parsererrorprintf_BM (pars, oblineno, obcolpos,
                          "expecting object at start of $[...]");
  while ((tok = parsertokenget_BM (pars)), tok.tok_kind != plex__NONE)
    {
      if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_rightbracket)
        {
          parsnestingcmd_BM (pars, depth, delim_dollarleftbracket,
                             lineno, colpos, delim_rightbracket,
                             parserlineno_BM (pars), parsercolpos_BM (pars));
          return _.obj;
        }
      bool gotcomp = parseobjectcomplcmd_BM (pars, _.obj, depth,
                                             (struct stackframe_stBM *) &_,
                                             &tok);
      if (!gotcomp)
        parsererrorprintf_BM (pars, pars->pars_lineno,
                              pars->pars_colpos,
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
  parsererrorprintf_BM (pars, pars->pars_lineno, pars->pars_colpos,
                        "invalid object expression for $[...] started L%d:C%d",
                        oblineno, obcolpos);
}                               /* end parsobjexpcmd_BM */



void
parsecommandbuf_BM (struct parser_stBM *pars, struct stackframe_stBM *stkf)
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
          if (!nobuild && !isobject_BM (GLOBAL_BM (gui_focus_obj)))
            parsererrorprintf_BM (pars, curlineno, curcolpos,
                                  "no focus object to complement");
          if (!parseobjectcomplcmd_BM
              (pars, (objectval_tyBM *) GLOBAL_BM (gui_focus_obj), 0,
               (struct stackframe_stBM *) &_, &tok))
            parsererrorprintf_BM (pars, curlineno, curcolpos,
                                  "invalid focus complement");
          if (!nobuild)
            {
              struct browsedobj_stBM *brfocusob =
                find_browsed_object_BM (GLOBAL_BM (gui_focus_obj));
              assert (brfocusob != NULL);
              browse_object_gui_BM (GLOBAL_BM (gui_focus_obj),
                                    BMP_browse_in_object,
                                    brfocusob->brow_depth,
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
          bool gotobject = false;
          _.obj = parsergetobject_BM (pars, (struct stackframe_stBM *) &_,      //
                                      0, &gotobject);
          if (!gotobject)
            parsererrorprintf_BM (pars, curlineno,
                                  curcolpos, "no new focus object after ?*");
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
                                        broldfocusob->brow_depth,
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
          bool gotobject = false;
          _.obj = parsergetobject_BM (pars, (struct stackframe_stBM *) &_,      //
                                      0, &gotobject);
          if (!gotobject || (!nobuild && !_.obj))
            parsererrorprintf_BM (pars, curlineno,
                                  curcolpos, "no displayed object after ?.");
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
          bool gotobject = false;
          parserseek_BM (pars, tok.tok_line, tok.tok_col);
          _.obj = parsergetobject_BM (pars, (struct stackframe_stBM *) &_,      //
                                      0, &gotobject);
          if (!gotobject || (!nobuild && !_.obj))
            parsererrorprintf_BM (pars, curlineno, curcolpos,
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
          bool gotobject = false;
          _.obj = parsergetobject_BM (pars, (struct stackframe_stBM *) &_,      //
                                      0, &gotobject);
          if (!gotobject)
            parsererrorprintf_BM (pars, curlineno,
                                  curcolpos, "no object to hide after ?-");
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
          tok = parsertokenget_BM (pars);
          if (tok.tok_kind != plex_NAMEDOBJ && tok.tok_kind != plex_CNAME)
            parsererrorprintf_BM (pars, curlineno,
                                  curcolpos,
                                  "no name to bind and show after ?$");
          if (!nobuild)
            {
              if (tok.tok_kind == plex_NAMEDOBJ)
                _.name = makestring_BM (findobjectname_BM (tok.tok_namedobj));
              else
                _.name = tok.tok_cname;
              assert (isstring_BM ((const value_tyBM) _.name));
            };
          bool gotval = false;
          _.comp =
            parsergetvalue_BM (pars, (struct stackframe_stBM *) &_, 0,
                               &gotval);
          if (!gotval)
            parsererrorprintf_BM (pars, curlineno, curcolpos,
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
          tok = parsertokenget_BM (pars);
          if (tok.tok_kind != plex_NAMEDOBJ && tok.tok_kind != plex_CNAME)
            parsererrorprintf_BM (pars, curlineno,
                                  curcolpos, "no name to hide after ?$-");
          if (!nobuild)
            {
              if (tok.tok_kind == plex_NAMEDOBJ)
                _.name = makestring_BM (findobjectname_BM (tok.tok_namedobj));
              else
                _.name = tok.tok_cname;
              assert (isstring_BM ((const value_tyBM) _.name));
              if (!find_browsed_named_value_BM (bytstring_BM (_.name)))
                parsererrorprintf_BM (pars, curlineno, curcolpos,
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
          tok = parsertokenget_BM (pars);
          if (tok.tok_kind != plex_LLONG)
            parsererrorprintf_BM (pars, curlineno, curcolpos,
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
      //
      // $( .... ) is displaying the named value $result
      else if (tok.tok_kind == plex_DELIM
               && tok.tok_delim == delim_dollarleftparen)
        {
          bool gotval = false;
          if (!_.result)
            _.result = makestring_BM ("result");
          parserseek_BM (pars, tok.tok_line, tok.tok_col);
          _.comp =
            parsergetvalue_BM (pars, (struct stackframe_stBM *) &_, 0,
                               &gotval);
          if (!gotval)
            parsererrorprintf_BM (pars, curlineno, curcolpos,
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
                parsererrorprintf_BM (pars, curlineno, curcolpos,
                                      "no result to display after $(");
            }
        }
      //
      else
        parsererrorprintf_BM (pars, curlineno, curcolpos,
                              "unexpected command");
    }
}                               /* end parsecommandbuf_BM */


void
parscommentinsidecmd_BM (struct parser_stBM *pars,
                         unsigned lineno, unsigned colpos, unsigned signlen)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, signlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, commentinside_cmdtag_BM, &it,
                             &endit);
}                               /* end parscommentinsidecmd_BM */


void
parscommentsigncmd_BM (struct parser_stBM *pars,
                       unsigned lineno, unsigned colpos, unsigned signlen)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, signlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, commentsign_cmdtag_BM, &it,
                             &endit);
}                               /* end parscommentsigncmd_BM */

void
parsdelimcmd_BM (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
                 unsigned delimlen)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, delimlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, delim_cmdtag_BM, &it, &endit);
}                               /* end parsdelimcmd_BM */

void
parsknownamecmd_BM (struct parser_stBM *pars, unsigned lineno,
                    unsigned colpos, unsigned namlen)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, namlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, knowname_cmdtag_BM, &it, &endit);
}                               /* end parsknownamecmd_BM */


void
parsnewnamecmd_BM (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
                   unsigned namlen)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, namlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, newname_cmdtag_BM, &it, &endit);
}                               /* end parsnewnamecmd_BM */


void
parsidcmd_BM (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
              unsigned idlen)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno - 1);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, idlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, id_cmdtag_BM, &it, &endit);
}                               /* end parsidcmd_BM */


void
parsnestingcmd_BM (struct parser_stBM *pars, int depth,
                   enum lexdelim_enBM opendelim,
                   unsigned openlinpos, unsigned opencolpos,
                   enum lexdelim_enBM closedelim,
                   unsigned closelinpos, unsigned closecolpos)
{
  assert (isparser_BM (pars));
  assert (openlinpos > 0 && closelinpos > 0 && openlinpos <= closelinpos);
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
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
}                               /* end parsnestingcmd_BM */


void
parsstartnestingcmd_BM (struct parser_stBM *pars, int depth,
                        enum lexdelim_enBM xtradelim,
                        unsigned xtralinpos,
                        unsigned xtracolpos,
                        enum lexdelim_enBM opendelim,
                        unsigned openlinpos,
                        unsigned opencolpos,
                        enum lexdelim_enBM closedelim,
                        unsigned closelinpos, unsigned closecolpos)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
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
}                               /* end parsstartnestingcmd_BM */


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
        run_then_erase_command_BM ();
      else if (withshift)
        run_then_keep_command_BM ();
      else                      // plain RETURN key, propagate it
        return false;
      return true;
    }
  else if (evk->keyval == GDK_KEY_Tab)
    {
      tabautocompletecmd_BM ();
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
static void stopcompletionmenucmd_BM (GtkMenuItem * mit, gpointer data);
void
tabautocompletecmd_BM (void)
{
  GtkTextIter cursit = EMPTY_TEXT_ITER_BM;
  GtkTextIter beglinit = EMPTY_TEXT_ITER_BM;
  GtkTextIter endlinit = EMPTY_TEXT_ITER_BM;
  gtk_text_buffer_get_iter_at_mark      //
    (commandbuf_BM, &cursit, gtk_text_buffer_get_insert (commandbuf_BM));
  unsigned col = gtk_text_iter_get_line_offset (&cursit);
  beglinit = cursit;
  gtk_text_iter_backward_line (&beglinit);
  endlinit = cursit;
  gtk_text_iter_forward_line (&endlinit);
  const char *curlin = gtk_text_buffer_get_text (commandbuf_BM, &beglinit,
                                                 &endlinit, false);
  assert (col <= g_utf8_strlen (curlin, -1));
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
  bool gotid = false;
  if (endname >= begname + 3 && begname[0] == '_'
      && isdigit (begname[1]) && isalnum (begname[2])
      && endname < begname + 31)
    {
      char widbuf[32];
      memset (widbuf, 0, sizeof (widbuf));
      memcpy (widbuf, begname, endname - begname);
      gotid = true;
      complsetv = setobjectsofidprefixed_BM (widbuf);
    }
  else if (endname > begname && isalpha (begname[0]))
    {
      char tinyprefix[40];
      memset (tinyprefix, 0, sizeof (tinyprefix));
      gotid = false;
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
      complsetv = setofprefixednamedobjects_BM (prefix);
      if (prefix != tinyprefix)
        free (prefix);
    }
  else
    goto failure;
  unsigned nbcompl = setcardinal_BM (complsetv);
  if (nbcompl == 0)
    goto failure;
  else if (nbcompl == 1)
    {
      // special case when complsetv is a singleton
      char cidbuf[32];
      memset (cidbuf, 0, sizeof (cidbuf));
      const char *complword = NULL;
      const objectval_tyBM *obcomp = setelemnth_BM (complsetv, 0);
      assert (isobject_BM ((const value_tyBM) obcomp));
      if (gotid)
        {
          idtocbuf32_BM (objid_BM (obcomp), cidbuf);
          complword = cidbuf;
        }
      else
        complword = findobjectname_BM (obcomp);
      assert (complword && complword[0]);
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
      assert (nbcompl > 1);
      complsetcmd_BM = complsetv;
      GtkWidget *complmenu = gtk_menu_new ();
      GtkTextIter begwit = cursit;
      GtkTextIter endwit = cursit;
      gtk_text_iter_forward_chars (&endwit, endname - curstr);
      gtk_text_iter_backward_chars (&begwit, curstr - begname);
      compbegoffcmd_BM = gtk_text_iter_get_offset (&begwit);
      compendoffcmd_BM = gtk_text_iter_get_offset (&endwit);
      if (gotid)
        {                       /* complete by id */
          for (unsigned ix = 0; ix < nbcompl; ix++)
            {
              char cidbuf[32];
              memset (cidbuf, 0, sizeof (cidbuf));
              const objectval_tyBM *obcomp = setelemnth_BM (complsetv, ix);
              assert (isobject_BM ((const value_tyBM) obcomp));
              idtocbuf32_BM (objid_BM (obcomp), cidbuf);
              GtkWidget *mit = gtk_menu_item_new_with_label (cidbuf);
              gtk_menu_shell_append (GTK_MENU_SHELL (complmenu), mit);
              g_signal_connect (mit, "activate",
                                G_CALLBACK (replacecompletionbyidcmd_BM),
                                (gpointer) (intptr_t) ix);
            }
        }
      else
        {                       /* complete by name */
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
          for (unsigned obix = 0; obix < nbcompl; obix++)
            {
              const objectval_tyBM *curob = arr[obix];
              assert (isobject_BM ((const value_tyBM) curob));
              int elix = setelemindex_BM (complsetv, curob);
              assert (elix >= 0);
              const char *obname = findobjectname_BM (curob);
              assert (obname != NULL);
              GtkWidget *mit = gtk_menu_item_new_with_label (obname);
              gtk_menu_shell_append (GTK_MENU_SHELL (complmenu), mit);
              g_signal_connect (mit, "activate",
                                G_CALLBACK (replacecompletionbynamecmd_BM),
                                (gpointer) (intptr_t) elix);
            }
        }
      gtk_widget_show_all (complmenu);
      /* not needed
         g_signal_connect (complmenu, "cancel",
         G_CALLBACK (stopcompletionmenucmd_BM), "*Cancelled*");
       */
      g_signal_connect (complmenu, "deactivate",
                        G_CALLBACK (stopcompletionmenucmd_BM),
                        "*Deactivated*");
      gtk_menu_popup_at_pointer (GTK_MENU (complmenu), NULL);
      gtk_main ();
      gtk_widget_destroy (complmenu);
      complsetcmd_BM = NULL;
      compbegoffcmd_BM = -1;
      compendoffcmd_BM = -1;
    }
  free ((char *) curlin);
  return;
failure:
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
  assert (isset_BM ((const value_tyBM) complsetcmd_BM));
  assert (ix < setcardinal_BM (complsetcmd_BM));
  const objectval_tyBM *ob = setelemnth_BM (complsetcmd_BM, ix);
  assert (isobject_BM ((const value_tyBM) ob));
  char idbuf[32];
  memset (idbuf, 0, sizeof (idbuf));
  idtocbuf32_BM (objid_BM (ob), idbuf);
  GtkTextIter begwit = EMPTY_TEXT_ITER_BM;
  GtkTextIter endwit = EMPTY_TEXT_ITER_BM;
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
  assert (isset_BM ((const value_tyBM) complsetcmd_BM));
  assert (ix < setcardinal_BM (complsetcmd_BM));
  const objectval_tyBM *ob = setelemnth_BM (complsetcmd_BM, ix);
  assert (isobject_BM ((const value_tyBM) ob));
  const char *obname = findobjectname_BM (ob);
  assert (obname != NULL);
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
stopcompletionmenucmd_BM (GtkMenuItem * mit
                          __attribute__ ((unused)),
                          gpointer data __attribute__ ((unused)))
{
  assert (isset_BM ((const value_tyBM) complsetcmd_BM));
  gtk_main_quit ();
}                               /* end stopcompletionmenucmd_BM */



/// called by run_then_keep_command_BM & run_then_erase_command_BM
void
runcommand_BM (bool erase)
{
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
      parsecommandbuf_BM (cmdpars, (struct stackframe_stBM *) &_);
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
}                               /* end runcommand_BM */


void
enduseractioncmd_BM (GtkTextBuffer * txbuf, gpointer data)
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
  assert (txview == GTK_TEXT_VIEW (browserview_BM));
  assert (GTK_IS_MENU (popup));
  assert (data == NULL);
  char cursinfobuf[32];
  memset (cursinfobuf, 0, sizeof (cursinfobuf));
  GtkTextIter cursit = EMPTY_TEXT_ITER_BM;
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
  gtk_widget_show_all (popup);
}                               /* end populatepopupbrow_BM */


void
populatepopupcmd_BM (GtkTextView * txview, GtkWidget * popup, gpointer data)
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
  assert (txview == GTK_TEXT_VIEW (logview_BM));
  assert (GTK_IS_MENU (popup));
  assert (data == NULL);
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

static void cssparsingerror_BM (GtkCssProvider *, GtkCssSection *, GError *,
                                gpointer) __attribute__ ((noreturn));

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
  //gtk_builder_add_callback_symbols (bld, "quitaction_BM", quit_BM, NULL);
  mainwin_BM = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_style_context_add_provider_for_screen
    (gtk_window_get_screen (GTK_WINDOW (mainwin_BM)),
     GTK_STYLE_PROVIDER (cssprovider),
     GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
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
  id_cmdtag_BM =                //
    gtk_text_tag_table_lookup (commandtagtable_BM, "id_cmdtag");
  if (!id_cmdtag_BM)
    FATAL_BM ("cannot find id_cmdtag");
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
  ////////////////
  GtkWidget *mainvbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
  gtk_container_add (GTK_CONTAINER (mainwin_BM), mainvbox);
  GtkWidget *mainmenubar = gtk_menu_bar_new ();
  gtk_box_pack_start (GTK_BOX (mainvbox), mainmenubar,
                      /*expand= */ false,
                      /*fill= */ false, 2);
  GtkWidget *appquit =
    GTK_WIDGET (gtk_builder_get_object (bld, "appquit_id"));
  g_signal_connect (appquit, "activate", quit_BM, NULL);
  g_signal_connect (mainwin_BM, "delete-event", (GCallback) deletemainwin_BM,
                    NULL);
  GtkWidget *appexit =
    GTK_WIDGET (gtk_builder_get_object (bld, "appexit_id"));
  g_signal_connect (appexit, "activate", exit_BM, NULL);
  GtkWidget *appdump =
    GTK_WIDGET (gtk_builder_get_object (bld, "appdump_id"));
  g_signal_connect (appdump, "activate", do_dump_BM, NULL);
  GtkWidget *appgarbcoll =
    GTK_WIDGET (gtk_builder_get_object (bld, "appgarbcoll_id"));
  g_signal_connect (appgarbcoll, "activate", do_garbcoll_BM, NULL);
  GtkWidget *appmenu =
    GTK_WIDGET (gtk_builder_get_object (bld, "menuapp_id"));
  assert (GTK_IS_WIDGET (appmenu));
  gtk_menu_shell_append (GTK_MENU_SHELL (mainmenubar), appmenu);
  GtkWidget *editmenu =
    GTK_WIDGET (gtk_builder_get_object (bld, "menuedit_id"));
  assert (GTK_IS_WIDGET (editmenu));
  gtk_menu_shell_append (GTK_MENU_SHELL (mainmenubar), editmenu);
  GtkWidget *sep1 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_box_pack_start (GTK_BOX (mainvbox), sep1, /*expand= */
                      false,
                      /*fill= */
                      false, 2);
  GtkWidget *paned1 = gtk_paned_new (GTK_ORIENTATION_VERTICAL);
  gtk_paned_set_wide_handle (GTK_PANED (paned1), true);
  gtk_paned_set_position (GTK_PANED (paned1), 330);
  gtk_box_pack_start (GTK_BOX (mainvbox), paned1,       /*expand= */
                      true,
                      /*fill= */
                      true, 2);
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
                    G_CALLBACK (handlekeypresscmd_BM), NULL);
  g_signal_connect (commandbuf_BM, "end-user-action",
                    G_CALLBACK (enduseractioncmd_BM), NULL);
  g_signal_connect (commandview_BM, "populate-popup",
                    G_CALLBACK (populatepopupcmd_BM), NULL);
  g_signal_connect (commandbuf_BM, "mark-set",
                    G_CALLBACK (marksetcmd_BM), NULL);
  gtk_widget_set_tooltip_markup (GTK_WIDGET (commandview_BM),
                                 "<big><b>command view</b></big>\n");
  GtkWidget *commandscrolw = gtk_scrolled_window_new (NULL, NULL);
  gtk_container_add (GTK_CONTAINER (commandscrolw), commandview_BM);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW
                                  (commandscrolw),
                                  GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  //
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
  assert (txbuf == commandbuf_BM);
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
  assert (txbuf == browserbuf_BM);
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
        assert (mdbrob->brow_ostartm != NULL && mdbrob->brow_oendm != NULL);
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
        assert (mdbrob->brow_ostartm != NULL && mdbrob->brow_oendm != NULL);
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
        unsigned curnbparen = brob->brow_parenulen;
        if (curnbparen == 0)
          return;
        gtk_text_buffer_get_iter_at_mark (browserbuf_BM, &ostartit,
                                          brob->brow_ostartm);
        gtk_text_buffer_get_iter_at_mark (browserbuf_BM, &oendit,
                                          brob->brow_oendm);
        guint ostartoff = gtk_text_iter_get_offset (&ostartit);
        int delta = off - ostartoff;
        assert (delta >= 0);
        for (unsigned pix = 0; pix < curnbparen; pix++)
          {
            struct parenoffset_stBM *curpo = brob->brow_parenarr + pix;
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
          assert (mdbrva->brow_vstartmk && mdbrva->brow_vendmk);
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
          assert (mdbrva->brow_vstartmk && mdbrva->brow_vendmk);
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
          unsigned curnbparen = brva->brow_parenulen;
          if (curnbparen == 0)
            return;
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM,
                                            &vstartit, brva->brow_vstartmk);
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM, &vendit,
                                            brva->brow_vendmk);
          guint vstartoff = gtk_text_iter_get_offset (&vstartit);
          int delta = off - vstartoff;
          assert (delta >= 0);
          for (unsigned pix = 0; pix < curnbparen; pix++)
            {
              struct parenoffset_stBM *curpo = brva->brow_parenarr + pix;
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


gboolean
guiperiodicgarbagecollection_BM (gpointer data __attribute__ ((unused)))
{
  assert (data == NULL);
  if (want_garbage_collection_BM && gtk_main_level () <= 1)
    {
      fullgarbagecollection_BM (NULL);
    }
  return TRUE;                  // repeat again later
}                               /* end guiperiodicgarbagecollection_BM */

static void
browsenewlinefordepth_BM (int depth)
{
  gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", 1);
  gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "                ",
                          (depth & 0xf));
}                               /* end browsenewlinefordepth_BM */


static void
browsespacefordepth_BM (int depth)
{
  if (gtk_text_iter_get_line_offset (&browserit_BM) > 64)
    browsenewlinefordepth_BM (depth);
  else
    gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, " ", 1);
}                               /* end browsespacefordepth_BM */


/// method to browse_in_object for object-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_23ViGouPnAg_15P5mpG9x3d);
value_tyBM
ROUTINEOBJNAME_BM (_23ViGouPnAg_15P5mpG9x3d)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the depth
 const value_tyBM arg3
 __attribute__ ((unused)), const quasinode_tyBM * restargs
 __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  assert (isobject_BM (arg1));
  assert (istaggedint_BM (arg2));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows;
                 const setval_tyBM * setattrs; const objectval_tyBM * curattr;
                 value_tyBM curval;);
  _.objbrows = (const objectval_tyBM *) arg1;
  int depth = getint_BM (arg2);
  ///
  //// show hi&lo id and hash
  {
    Dl_info di = { };
    if (_.objbrows->ob_rout
        && dladdr (_.objbrows->ob_rout, &di) && di.dli_fname && di.dli_sname)
      {
        char *commbuf = NULL;
        asprintf (&commbuf,
                  "|id:%lld,%lld; h:%d\n ... µ%s;%s @%p|",
                  (long long) _.objbrows->ob_id.id_hi,
                  (long long) _.objbrows->ob_id.id_lo,
                  objecthash_BM (_.objbrows),
                  di.dli_fname, di.dli_sname, (void *) _.objbrows->ob_rout);
        if (commbuf)
          gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,
                                            commbuf, -1, miscomm_brotag_BM,
                                            NULL);
        free (commbuf);
      }
    else
      {
        char idcomm[128];
        memset (idcomm, 0, sizeof (idcomm));
        snprintf (idcomm, sizeof (idcomm), "|id:%lld,%lld; h:%d|",
                  (long long) _.objbrows->ob_id.id_hi,
                  (long long) _.objbrows->ob_id.id_lo,
                  objecthash_BM (_.objbrows));
        gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,
                                          idcomm, -1, miscomm_brotag_BM,
                                          NULL);
      }
    gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", -1);
  }
  ///
  //// show mtime & space
  {
    char mbuf[64];
    double mtime = _.objbrows->ob_mtime;
    snprintf (mbuf, sizeof (mbuf), "!@ %.2f ", mtime);
    gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                      &browserit_BM, mbuf, -1, NULL, NULL);
    double now = clocktime_BM (CLOCK_REALTIME);
    time_t mtimt = (time_t) mtime;
    struct tm mtimtm = {
    };
    localtime_r (&mtimt, &mtimtm);
    char commbuf[96];
    memset (commbuf, 0, sizeof (commbuf));
    char spabuf[16];
    memset (spabuf, 0, sizeof (spabuf));
    switch (_.objbrows->ob_space)
      {
      case TransientSp_BM:
        strcpy (spabuf, "transient");
        break;
      case PredefSp_BM:
        strcpy (spabuf, "predefined");
        break;
      case GlobalSp_BM:
        strcpy (spabuf, "global");
        break;
      default:
        snprintf (spabuf, sizeof (spabuf), "user#%d", _.objbrows->ob_space);
        break;
      };
    if (mtime < now && mtime + 1.0e6 > now)     // a million second is about 11 days
      strftime (mbuf, sizeof (mbuf), "%a %d, %T %Z", &mtimtm);
    else if (mtime < now && mtime + 25e6 > now) // 25 million seconds is less than 10 months
      strftime (mbuf, sizeof (mbuf), "%a %d %b, %T %Z", &mtimtm);
    else
      strftime (mbuf, sizeof (mbuf), "%c", &mtimtm);
    snprintf (commbuf, sizeof (commbuf), "|mtim:%s space:%s|", mbuf, spabuf);
    gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                      &browserit_BM, commbuf, -1,
                                      miscomm_brotag_BM, NULL);
    gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", -1);
    if (_.objbrows->ob_class)
      {
        gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "!$ ", -1);
        browse_value_BM ((const value_tyBM) _.objbrows->ob_class,
                         (struct stackframe_stBM *) &_, 2, 0);
        gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", -1);
      };
  }
  ///
  //// show attributes
  {
    char commbuf[64];
    memset (commbuf, 0, sizeof (commbuf));
    _.setattrs = objsetattrs_BM (_.objbrows);
    unsigned nbattrs = setcardinal_BM (_.setattrs);
    snprintf (commbuf, sizeof (commbuf), "|%d attributes:|", nbattrs);
    gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                      &browserit_BM, commbuf, -1,
                                      miscomm_brotag_BM, NULL);
    gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", -1);
    const objectval_tyBM *tinyarr[TINYSIZE_BM] = {
    };
    const objectval_tyBM **arr = (nbattrs < TINYSIZE_BM) ? tinyarr      //
      : calloc (prime_above_BM (nbattrs),
                sizeof (const objectval_tyBM *));
    if (!arr)
      FATAL_BM ("failed to calloc arr for %d attrs", nbattrs);
    for (unsigned ix = 0; ix < nbattrs; ix++)
      arr[ix] = setelemnth_BM (_.setattrs, ix);
    sortnamedobjarr_BM (arr, nbattrs);
    for (unsigned aix = 0; aix < nbattrs; aix++)
      {
        _.curattr = arr[aix];
        _.curval = objgetattr_BM (_.objbrows, _.curattr);
        gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "!: ", -1);
        browse_value_BM ((const value_tyBM) _.curattr,
                         (struct stackframe_stBM *) &_, 2, 0);
        browsespacefordepth_BM (1);
        browse_value_BM ((const value_tyBM) _.curval,
                         (struct stackframe_stBM *) &_, depth, 1);
        gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", -1);
      };
    if (arr != tinyarr)
      free (arr), arr = NULL;
  }
  ///
  //// show the components
  {
    char commbuf[64];
    memset (commbuf, 0, sizeof (commbuf));
    unsigned nbcomps = objnbcomps_BM (_.objbrows);
    snprintf (commbuf, sizeof (commbuf), "|%d components:|", nbcomps);
    gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                      &browserit_BM, commbuf, -1,
                                      miscomm_brotag_BM, NULL);
    gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", -1);
    for (unsigned cix = 0; cix < nbcomps; cix++)
      {
        gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "!& ", -1);
        snprintf (commbuf, sizeof (commbuf), "|#%d:|", cix);
        gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                          &browserit_BM, commbuf, -1,
                                          miscomm_brotag_BM, NULL);
        _.curval = objgetcomp_BM (_.objbrows, cix);
        browsespacefordepth_BM (1);
        browse_value_BM ((const value_tyBM) _.curval,
                         (struct stackframe_stBM *) &_, depth, 1);
        gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", -1);
      }
  }
  ///
  // extra data
  if (_.objbrows->ob_data)
    {
      send1_BM ((const value_tyBM) _.objbrows, BMP_browse_data,
                (struct stackframe_stBM *) &_, taggedint_BM (depth));
      gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", -1);
    }
  /// return itself
  return (const value_tyBM) _.objbrows;
}                               /* end  ROUTINEOBJNAME_BM (_23ViGouPnAg_15P5mpG9x3d) */





/// method to browse_value for object-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_0BAnB0xjs23_0WEOCOi5Nbe);
value_tyBM
ROUTINEOBJNAME_BM (_0BAnB0xjs23_0WEOCOi5Nbe)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3,         // the current depth
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  if (!isobject_BM (arg1))
    FATAL_BM
      ("non-object for method to browse_value for object-s _0BAnB0xjs23_0WEOCOi5Nbe");
  assert (istaggedint_BM (arg2));
  assert (istaggedint_BM (arg3));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows;);
  _.objbrows = (const objectval_tyBM *) arg1;
  int maxdepth = getint_BM (arg2);
  assert (maxdepth > 0);
  int curdepth = getint_BM (arg3);
  //  assert (curdepth <= maxdepth);
  const char *objnam = findobjectname_BM (_.objbrows);
  char idbuf[32];
  memset (idbuf, 0, sizeof (idbuf));
  idtocbuf32_BM (objid_BM (_.objbrows), idbuf);
  if (objnam)
    {
      gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,   //
                                        objnam, -1, objname_brotag_BM, NULL);
      if (curdepth < 2)
        {
          gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,       //
                                            " |=", -1, objrefcomm_brotag_BM,
                                            NULL);
          gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,       //
                                            idbuf,
                                            -1, objrefcomm_brotag_BM, NULL);
          gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                            &browserit_BM, "|", -1,
                                            objrefcomm_brotag_BM, NULL);
        }
    }
  else
    {                           // anonymous
      gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,   //
                                        idbuf, -1, objid_brotag_BM, NULL);
    }
  return (const value_tyBM) _.objbrows;
}                               /* end  ROUTINEOBJNAME_BM (_0BAnB0xjs23_0WEOCOi5Nbe) */


/// method to browse_data for class-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_09DxyieS5Wz_7pkad4F88FA);
value_tyBM
ROUTINEOBJNAME_BM (_09DxyieS5Wz_7pkad4F88FA)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows; const setval_tyBM * setsel;   //
                 const objectval_tyBM * cursel;
                 const objectval_tyBM * supercla;
                 value_tyBM curval;);
  if (!isobject_BM (arg1))
    FATAL_BM
      ("non-object for method to browse_data for class-s _09DxyieS5Wz_7pkad4F88FA");
  _.objbrows = (const objectval_tyBM *) arg1;
  int depth = getint_BM (arg2);
  assert (isobject_BM ((const value_tyBM) _.objbrows));
  assert (objhasclassinfo_BM (_.objbrows));
  _.setsel = objgetclassinfosetofselectors_BM (_.objbrows);
  _.supercla = objgetclassinfosuperclass_BM (_.objbrows);
  unsigned nbmeth = setcardinal_BM (_.setsel);
  const objectval_tyBM *tinyarr[TINYSIZE_BM] = {
  };
  const objectval_tyBM **arr = (nbmeth < TINYSIZE_BM) ? tinyarr //
    : calloc (prime_above_BM (nbmeth),
              sizeof (const objectval_tyBM *));
  if (!arr)
    FATAL_BM ("failed to calloc arr for %d methods", nbmeth);
  for (unsigned ix = 0; ix < nbmeth; ix++)
    arr[ix] = setelemnth_BM (_.setsel, ix);
  sortnamedobjarr_BM (arr, nbmeth);
  gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                    &browserit_BM,
                                    "!~ class (~ ", -1, NULL, NULL);
  if (_.supercla)
    {
      gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                        &browserit_BM,
                                        "|superclass=|", -1,
                                        miscomm_brotag_BM, NULL);
      browse_value_BM ((const value_tyBM) _.supercla,
                       (struct stackframe_stBM *) &_, 2, 0);
    }
  else
    {
      gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                        &browserit_BM,
                                        "|nosuperclass|", -1,
                                        miscomm_brotag_BM, NULL);
      gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                        &browserit_BM, " __\n", -1,
                                        NULL, NULL);
    }
  for (unsigned ix = 0; ix < nbmeth; ix++)
    {
      _.cursel = arr[ix];
      _.curval = (value_tyBM) objgetclassinfomethod_BM (_.objbrows, _.cursel);
      browsenewlinefordepth_BM (1);
      gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                        &browserit_BM, "~: ", -1, NULL, NULL);
      gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                        &browserit_BM,
                                        "|selector:|", -1,
                                        miscomm_brotag_BM, NULL);
      gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                        &browserit_BM, " ", -1, NULL, NULL);
      browse_value_BM ((const value_tyBM) _.cursel,
                       (struct stackframe_stBM *) &_, 2, 1);
      browsespacefordepth_BM (1);
      browse_value_BM ((const value_tyBM) _.curval,
                       (struct stackframe_stBM *) &_, depth, 1);
      gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                        &browserit_BM, "\n", -1, NULL, NULL);
    }
  if (arr != tinyarr)
    free (arr), arr = NULL;
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM, "~)\n", -1,
                                    NULL, NULL);
  return (const value_tyBM) _.objbrows;
}                               /* end ROUTINEOBJNAME_BM (_09DxyieS5Wz_7pkad4F88FA) */


void
browse_value_BM (const value_tyBM val,
                 struct stackframe_stBM *stkf, int maxdepth, int curdepth)
{
  if (!val)
    gtk_text_buffer_insert_with_tags (browserbuf_BM,
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


/// method to browse_value for tuple-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_0B1PYH9bN34_3RZdP24AVyt);
value_tyBM
ROUTINEOBJNAME_BM (_0B1PYH9bN34_3RZdP24AVyt)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3,         // the current depth
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  if (!istuple_BM (arg1))
    FATAL_BM
      ("non-tuple for  method to browse_value for tuple-s _0BAnB0xjs23_0WEOCOi5Nb");
  assert (istaggedint_BM (arg2));
  assert (istaggedint_BM (arg3));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const tupleval_tyBM * tupbrows;
                 const objectval_tyBM * objbrows;);
  _.tupbrows = (const tupleval_tyBM *) arg1;
  int maxdepth = getint_BM (arg2);
  int curdepth = getint_BM (arg3);
  int oboff = browse_show_start_offset_BM ();
  assert (curdepth <= maxdepth);
  int openoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,       //
                                    "[", -1, nest_brotag_BM, NULL);
  unsigned tupsiz = tuplesize_BM (_.tupbrows);
  if (curdepth < maxdepth)
    {
      for (unsigned tix = 0; tix < tupsiz; tix++)
        {
          _.objbrows = tuplecompnth_BM (_.tupbrows, tix);
          if (tix > 0)
            browsespacefordepth_BM (curdepth + 1);
          browse_value_BM ((const value_tyBM) _.objbrows,
                           (struct stackframe_stBM *) &_,
                           (maxdepth), (curdepth + 1));
        }
    }
  else
    {
      char msgbuf[64];
      memset (msgbuf, 0, sizeof (msgbuf));
      snprintf (msgbuf, sizeof (msgbuf), "|\342\200\246"        /*U+2026 HORIZONTAL ELLIPSIS … */
                " %d objects in tuple|", tupsiz);
      gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,   //
                                        msgbuf, -1, toodeep_brotag_BM, NULL);
    }
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,       //
                                    "]", -1, nest_brotag_BM, NULL);
  int closeoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  browse_add_parens_BM (openoff, closeoff, -1, 1, 1, 0, curdepth);
  return (const value_tyBM) _.objbrows;
}                               /* end ROUTINEOBJNAME_BM (_0BAnB0xjs23_0WEOCOi5Nb)  */





/// method to browse_value for set-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_3rne4qbpnV9_0pywzeJp3Qr);
value_tyBM
ROUTINEOBJNAME_BM (_3rne4qbpnV9_0pywzeJp3Qr)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3,         // the current depth
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  if (!isset_BM (arg1))
    FATAL_BM
      ("non-set for  method to browse_value for set-s _3rne4qbpnV9_0pywzeJp3Qr");
  assert (istaggedint_BM (arg2));
  assert (istaggedint_BM (arg3));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const setval_tyBM * setbrows;
                 const objectval_tyBM * objbrows;);
  _.setbrows = (const setval_tyBM *) arg1;
  unsigned setcard = setcardinal_BM (_.setbrows);
  int maxdepth = getint_BM (arg2);
  int curdepth = getint_BM (arg3);
  assert (curdepth <= maxdepth);
  int oboff = browse_show_start_offset_BM ();
  int openoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,       //
                                    "{", -1, nest_brotag_BM, NULL);
  if (curdepth < maxdepth)
    {
      const objectval_tyBM *tinyarr[TINYSIZE_BM] = {
      };
      const objectval_tyBM **arr =      //
        (setcard < TINYSIZE_BM) ? tinyarr
        : calloc (setcard + 1, sizeof (const objectval_tyBM *));
      if (!arr)
        FATAL_BM ("calloc failed for %d elements", setcard);
      for (unsigned eix = 0; eix < setcard; eix++)
        arr[eix] = setelemnth_BM (_.setbrows, eix);
      sortnamedobjarr_BM (arr, setcard);
      for (unsigned eix = 0; eix < setcard; eix++)
        {
          _.objbrows = arr[eix];
          if (eix > 0)
            browsespacefordepth_BM (curdepth + 1);
          browse_value_BM ((const value_tyBM) _.objbrows,
                           (struct stackframe_stBM *) &_,
                           (maxdepth), (curdepth + 1));
        }
      if (arr != tinyarr)
        free (arr);
    }
  else
    {
      char msgbuf[64];
      memset (msgbuf, 0, sizeof (msgbuf));
      snprintf (msgbuf, sizeof (msgbuf), "|\342\200\246"        /*U+2026 HORIZONTAL ELLIPSIS … */
                " %d objects in set|", setcard);
      gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,   //
                                        msgbuf, -1, toodeep_brotag_BM, NULL);
    }
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,       //
                                    "}", -1, nest_brotag_BM, NULL);
  int closeoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  browse_add_parens_BM (openoff, closeoff, -1, 1, 1, 0, curdepth);
  return (const value_tyBM) _.objbrows;
}                               /* end ROUTINEOBJNAME_BM (_3rne4qbpnV9_0pywzeJp3Qr)  */





/// method to browse_value for int-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_0HBMCM5CeLn_7L5YEV2jO7Y);
value_tyBM
ROUTINEOBJNAME_BM (_0HBMCM5CeLn_7L5YEV2jO7Y)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3,         // the current depth
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  if (!istaggedint_BM (arg1))
    FATAL_BM
      ("non-int for method to browse_value for int-s _0HBMCM5CeLn_7L5YEV2jO7Y");
  assert (istaggedint_BM (arg2));
  assert (istaggedint_BM (arg3));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
    );
  intptr_t i = getint_BM (arg1);
  char ibuf[32];
  memset (ibuf, 0, sizeof (ibuf));
  snprintf (ibuf, sizeof (ibuf), "%lld", (long long) i);
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,       //
                                    ibuf, -1, num_brotag_BM, NULL);
  return (const value_tyBM) arg1;
}                               /* end ROUTINEOBJNAME_BM (_0HBMCM5CeLn_7L5YEV2jO7Y)  */



/// method to browse_value for string-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_63ZPkXUI2Uv_6Cp3qmh6Uud);
#define WANTEDLINEWIDTH_BM 64
value_tyBM
ROUTINEOBJNAME_BM (_63ZPkXUI2Uv_6Cp3qmh6Uud)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3,         // the current depth
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  if (!isstring_BM (arg1))
    FATAL_BM
      ("non-string for method to browse_value for string-s _63ZPkXUI2Uv_6Cp3qmh6Uud");
  assert (istaggedint_BM (arg2));
  assert (istaggedint_BM (arg3));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const stringval_tyBM * strbrows;);
  _.strbrows = arg1;
  int maxdepth = getint_BM (arg2);
  int curdepth = getint_BM (arg3);
  assert (curdepth <= maxdepth);
  unsigned l = lenstring_BM (_.strbrows);
  const char *str = bytstring_BM (_.strbrows);
  if (l >= WANTEDLINEWIDTH_BM / 2)
    browsespacefordepth_BM (curdepth);
  int oboff = browse_show_start_offset_BM ();
  int openoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,       //
                                    "\"", -1, stresc_brotag_BM, NULL);
  int ccnt = 0;
  int linecnt = 0;
#define WANTEDLINEWIDTH_BM 64
  for (const char *pc = str; *pc; pc = g_utf8_next_char (pc))
    {
      gunichar uc = g_utf8_get_char (pc);
      ccnt++;
      linecnt++;
#define ADDESCAPESTR_BM(S)						\
    gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,	\
				      (S), -1, stresc_brotag_BM, NULL)
      switch (uc)
        {
        case '\"':
          ADDESCAPESTR_BM ("\\\"");
          break;
        case '\'':
          ADDESCAPESTR_BM ("\\\'");
          break;
        case '\a':
          ADDESCAPESTR_BM ("\\a");
          break;
        case '\b':
          ADDESCAPESTR_BM ("\\b");
          break;
        case '\f':
          ADDESCAPESTR_BM ("\\f");
          break;
        case '\n':
          if (linecnt > 3 * WANTEDLINEWIDTH_BM / 4 && pc[1] && pc[2])
            {
              ADDESCAPESTR_BM ("\"+");
              browsenewlinefordepth_BM (curdepth);
              ADDESCAPESTR_BM ("\"");
              linecnt = 0;
            }
          else
            ADDESCAPESTR_BM ("\\n");
          break;
        case '\r':
          ADDESCAPESTR_BM ("\\r");
          break;
        case '\t':
          ADDESCAPESTR_BM ("\\t");
          break;
        case '\v':
          ADDESCAPESTR_BM ("\\v");
          break;
        case '\033' /*ESCAPE*/:
          ADDESCAPESTR_BM ("\\e");
          break;
        default:
          if (linecnt > 3 * WANTEDLINEWIDTH_BM / 4 && pc[1] && pc[2]
              && g_unichar_isspace (uc))
            {
              ADDESCAPESTR_BM ("\"&");
              browsenewlinefordepth_BM (curdepth);
              ADDESCAPESTR_BM ("\"");
              linecnt = 0;
            }
          else if (linecnt > WANTEDLINEWIDTH_BM && pc[1])
            {
              ADDESCAPESTR_BM ("\"&");
              browsenewlinefordepth_BM (curdepth);
              ADDESCAPESTR_BM ("\"");
              linecnt = 0;
            }
          if (g_unichar_isprint (uc))
            {
              char ubuf[8];
              memset (ubuf, 0, sizeof (ubuf));
              g_unichar_to_utf8 (uc, ubuf);
              gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                                &browserit_BM, ubuf, -1,
                                                str_brotag_BM, NULL);
            }
          else if (uc < 0xffff)
            {
              char ubuf[24];
              memset (ubuf, 0, sizeof (ubuf));
              snprintf (ubuf, sizeof (ubuf), "\\u%04x", uc);
              ADDESCAPESTR_BM (ubuf);
            }
          else
            {
              char ubuf[24];
              memset (ubuf, 0, sizeof (ubuf));
              snprintf (ubuf, sizeof (ubuf), "\\U%08x", uc);
              ADDESCAPESTR_BM (ubuf);
            }
          break;
        }
    }                           /* end for pc */
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,       //
                                    "\"", -1, stresc_brotag_BM, NULL);
  int closeoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  browse_add_parens_BM (openoff, closeoff, -1, 1, 1, 0, curdepth);
  if (ccnt >= WANTEDLINEWIDTH_BM / 2)
    browsespacefordepth_BM (curdepth);
  return (const value_tyBM) arg1;
}                               /* end ROUTINEOBJNAME_BM (_63ZPkXUI2Uv_6Cp3qmh6Uud) */



/// method to browse_value for node-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_7fJKfG4SN0U_1QTu5J832xg);
value_tyBM
ROUTINEOBJNAME_BM (_7fJKfG4SN0U_1QTu5J832xg)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3,         // the current depth
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  if (!isnode_BM (arg1))
    FATAL_BM
      ("non-node for method to browse_value for node-s _7fJKfG4SN0U_1QTu5J832xg");
  assert (istaggedint_BM (arg2));
  assert (istaggedint_BM (arg3));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const node_tyBM * nodbrows;
                 const objectval_tyBM * connob; value_tyBM curson;);
  _.nodbrows = arg1;
  int maxdepth = getint_BM (arg2);
  int curdepth = getint_BM (arg3);
  assert (curdepth <= maxdepth);
  unsigned nw = nodewidth_BM ((const value_tyBM) _.nodbrows);
  _.connob = nodeconn_BM ((const value_tyBM) _.nodbrows);
  assert (isobject_BM ((const value_tyBM) _.connob));
  int oboff = browse_show_start_offset_BM ();
  int xtraoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,       //
                                    "*", -1, nest_brotag_BM, NULL);
  gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, " ", 1);
  browse_value_BM ((const value_tyBM) _.connob, (struct stackframe_stBM *) &_,
                   (maxdepth), (curdepth + 1));
  browsespacefordepth_BM (curdepth + 1);
  int openoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,       //
                                    "(", -1, nest_brotag_BM, NULL);
  if (curdepth < maxdepth)
    {
      for (unsigned six = 0; six < nw; six++)
        {
          _.curson = nodenthson_BM ((const value_tyBM) _.nodbrows, six);
          if (six > 0)
            browsespacefordepth_BM (curdepth + 1);
          browse_value_BM ((const value_tyBM) _.curson,
                           (struct stackframe_stBM *) &_, (maxdepth),
                           (curdepth + 1));
        }
    }
  else
    {
      char msgbuf[64];
      memset (msgbuf, 0, sizeof (msgbuf));
      snprintf (msgbuf, sizeof (msgbuf), "|\342\200\246"        /*U+2026 HORIZONTAL ELLIPSIS … */
                " %d sons in node|", nw);
      gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,   //
                                        msgbuf, -1, toodeep_brotag_BM, NULL);
    }
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,       //
                                    ")", -1, nest_brotag_BM, NULL);
  int closeoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  browse_add_parens_BM (openoff, closeoff, xtraoff, 1, 1, 1, curdepth);
  return (const value_tyBM) arg1;
}                               /* end ROUTINEOBJNAME_BM (_7fJKfG4SN0U_1QTu5J832xg) */





/// method to browse_value for closure-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_7CohjJ9tkfZ_4UMAIZCgwac);
value_tyBM
ROUTINEOBJNAME_BM (_7CohjJ9tkfZ_4UMAIZCgwac)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3,         // the current depth
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  if (!isclosure_BM (arg1))
    FATAL_BM
      ("non-closure for method to browse_value for closure-s _7CohjJ9tkfZ_4UMAIZCgwac");
  assert (istaggedint_BM (arg2));
  assert (istaggedint_BM (arg3));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clobrows;
                 const objectval_tyBM * connob; value_tyBM curson;);
  _.clobrows = arg1;
  int maxdepth = getint_BM (arg2);
  int curdepth = getint_BM (arg3);
  assert (curdepth <= maxdepth);
  unsigned cw = closurewidth_BM ((const value_tyBM) _.clobrows);
  _.connob = closureconn_BM ((const value_tyBM) _.clobrows);
  assert (isobject_BM ((const value_tyBM) _.connob));
  int oboff = browse_show_start_offset_BM ();
  int xtraoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,       //
                                    "%", -1, nest_brotag_BM, NULL);
  gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, " ", 1);
  browse_value_BM ((const value_tyBM) _.connob, (struct stackframe_stBM *) &_,
                   (maxdepth), (curdepth + 1));
  browsespacefordepth_BM (curdepth + 1);
  int openoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,       //
                                    "(", -1, nest_brotag_BM, NULL);
  if (curdepth < maxdepth)
    {
      for (unsigned cix = 0; cix < cw; cix++)
        {
          _.curson = closurenthson_BM ((const value_tyBM) _.clobrows, cix);
          if (cix > 0)
            browsespacefordepth_BM (curdepth + 1);
          browse_value_BM ((const value_tyBM) _.curson,
                           (struct stackframe_stBM *) &_, (maxdepth),
                           (curdepth + 1));
        }
    }
  else
    {
      char msgbuf[64];
      memset (msgbuf, 0, sizeof (msgbuf));
      snprintf (msgbuf, sizeof (msgbuf), "|\342\200\246"        /*U+2026 HORIZONTAL ELLIPSIS … */
                " %d sons in closure|", cw);
      gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,   //
                                        msgbuf, -1, toodeep_brotag_BM, NULL);
    }
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,       //
                                    ")", -1, nest_brotag_BM, NULL);
  int closeoff = gtk_text_iter_get_offset (&browserit_BM) - oboff;
  browse_add_parens_BM (openoff, closeoff, xtraoff, 1, 1, 1, curdepth);
  return (const value_tyBM) arg1;
}                               /* end ROUTINEOBJNAME_BM ( _7CohjJ9tkfZ_4UMAIZCgwac) */



/// method to browse_data for basiclo_function-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_9zpvXnTuDeB_2B7ZiBtN8fA);
value_tyBM
ROUTINEOBJNAME_BM (_9zpvXnTuDeB_2B7ZiBtN8fA)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the browse maxdepth
 const value_tyBM arg3 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * objbrows;
                 value_tyBM curval;);
  if (!isobject_BM (arg1))
    FATAL_BM
      ("non-object for method to browse_data for basiclo_function-s _9zpvXnTuDeB_2B7ZiBtN8fA");
  _.objbrows = (const objectval_tyBM *) arg1;
  int depth = getint_BM (arg2);
  assert (isobject_BM ((const value_tyBM) _.objbrows));
  _.curval = _.objbrows->ob_data;
  int tyval = valtype_BM (_.curval);
  if (tyval == tyInt_BM
      || (tyval >= type_FIRST_BM && tyval <= type_LASTREAL_BM))
    {
      char vcommbuf[40];
      memset (vcommbuf, 0, sizeof (vcommbuf));
      snprintf (vcommbuf, sizeof (vcommbuf), "|valdata h=%u:| ",
                valhash_BM (_.curval));
      gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", -1);
      gtk_text_buffer_insert_with_tags (browserbuf_BM,
                                        &browserit_BM, vcommbuf, -1,
                                        miscomm_brotag_BM, NULL);
      browse_value_BM ((const value_tyBM) _.curval,
                       (struct stackframe_stBM *) &_, depth, 0);
      gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", -1);
    };
  return (const value_tyBM) _.objbrows;
}                               /* end ROUTINE _9zpvXnTuDeB_2B7ZiBtN8fA */
