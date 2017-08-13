// file gui_BM.c
#include "bismon.h"

GtkWidget *mainwin_BM;


//////////////// browser
GtkTextTagTable *browsertagtable_BM;
GtkTextBuffer *browserbuf_BM;
GtkWidget *browserview_BM;
GtkTextIter browserit_BM;
GtkTextMark *browserendtitlem_BM;
GtkTextTag *pagetitle_brotag_BM;
GtkTextTag *objtitle_brotag_BM;
GtkTextTag *objcommtitle_brotag_BM;
GtkTextTag *objnametitle_brotag_BM;
GtkTextTag *objidtitle_brotag_BM;
GtkTextTag *objid_brotag_BM;
GtkTextTag *objname_brotag_BM;
GtkTextTag *objrefcomm_brotag_BM;
GtkTextTag *nest_brotag_BM;


/// the browsed objects
unsigned browserobsize_BM;      /* allocated size */
unsigned browserobulen_BM;      /* used length */
int browserobcurix_BM;          /* current index in browsedobj_BM */
struct browsedobj_stBM
{
  const objectval_tyBM *brow_obj;
  GtkTextMark *brow_ostartm;
  GtkTextMark *brow_oendm;
  int brow_depth;
};
struct browsedobj_stBM *browsedobj_BM;

/// the browsed named values
unsigned browsernvsize_BM;      /* allocated size */
unsigned browsernvulen_BM;      /* unsigned length */
int browsernvcurix_BM;
struct browsedval_stBM
{
  const stringval_tyBM *brow_name;
  const value_tyBM brow_val;
  GtkTextMark *brow_vstartm;
  GtkTextMark *brow_vendm;
};
struct browsedval_stBM *browsedval_BM;

//////////////// command
GtkTextTagTable *commandtagtable_BM;
GtkTextBuffer *commandbuf_BM;
GtkWidget *commandview_BM;

GtkTextTagTable *logtagtable_BM;
GtkTextBuffer *logbuf_BM;
GtkWidget *logview_BM;

GtkWidget *msglab_BM;

GtkTextTag *errored_cmdtag_BM;
GtkTextTag *commentinside_cmdtag_BM;
GtkTextTag *commentsign_cmdtag_BM;
GtkTextTag *delim_cmdtag_BM;
GtkTextTag *knowname_cmdtag_BM;
GtkTextTag *newname_cmdtag_BM;
GtkTextTag *id_cmdtag_BM;
GtkTextTag *nesting_cmdtag_BM;

#define CMD_MAXNEST_BM 64
GtkTextTag *open_cmdtags_BM[CMD_MAXNEST_BM];
GtkTextTag *close_cmdtags_BM[CMD_MAXNEST_BM];
GtkTextTag *xtra_cmdtags_BM[CMD_MAXNEST_BM];

#define BROWSE_MAXDEPTH_BM 48

static void start_browse_object_BM (const objectval_tyBM * obj, int depth);

const char *
gobjectclassnamedbg_BM (GObject * ptr)
{
  if (!ptr)
    return "*nil*";
  return G_OBJECT_CLASS_NAME (G_OBJECT_GET_CLASS (ptr));
}                               /* end gobjectclassnamedbg_BM */


void
start_browse_object_BM (const objectval_tyBM * obj, int depth)
{
  assert (isobject_BM ((const value_tyBM) obj));
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
      if (mdobj == obj)
        break;
      int cmp = objectnamedcmp_BM (mdobj, obj);
      if (cmp < 0)
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
          GtkTextIter startit, endit;
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM,
                                            &startit,
                                            browsedobj_BM[md].brow_ostartm);
          gtk_text_buffer_get_iter_at_mark (browserbuf_BM,
                                            &endit,
                                            browsedobj_BM[md].brow_oendm);
          gtk_text_buffer_delete (browserbuf_BM, &startit, &endit);
          gtk_text_buffer_move_mark (browserbuf_BM,
                                     browsedobj_BM[md].brow_ostartm,
                                     &startit);
          browsedobj_BM[md].brow_depth = depth;
          browserit_BM = startit;
          browserobcurix_BM = md;
          return;
        }
      else if (objectnamedcmp_BM (obj, mdobj) < 0)
        {
          GtkTextIter it;
          if (md > 0)
            gtk_text_buffer_get_iter_at_mark (browserbuf_BM,
                                              &it,
                                              browsedobj_BM[md -
                                                            1].brow_oendm);
          else
            gtk_text_buffer_get_iter_at_mark (browserbuf_BM,
                                              &it, browserendtitlem_BM);
          for (int ix = browserobulen_BM + 1; ix > md; ix--)
            browsedobj_BM[ix] = browsedobj_BM[ix - 1];
          browserobulen_BM++;
          browsedobj_BM[md].brow_obj = obj;
          browsedobj_BM[md].brow_ostartm =      //
            gtk_text_buffer_create_mark (browserbuf_BM, NULL, &it, FALSE);
          browsedobj_BM[md].brow_oendm =        //
            gtk_text_buffer_create_mark (browserbuf_BM, NULL, &it, FALSE);
          browsedobj_BM[md].brow_depth = depth;
          browserobcurix_BM = md;
          browserit_BM = it;
          return;
        }
    };
  assert (browserobulen_BM == 0);
  GtkTextIter it;
  gtk_text_buffer_get_iter_at_mark (browserbuf_BM, &it, browserendtitlem_BM);
  browserobulen_BM = 1;
  browsedobj_BM[0].brow_obj = obj;
  browsedobj_BM[0].brow_ostartm =       //
    gtk_text_buffer_create_mark (browserbuf_BM, NULL, &it, FALSE);
  browsedobj_BM[0].brow_oendm = //
    gtk_text_buffer_create_mark (browserbuf_BM, NULL, &it, FALSE);
  browsedobj_BM[0].brow_depth = depth;
  browserobcurix_BM = 0;
  browserit_BM = it;
}                               /* end start_browse_object_BM */


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
  start_browse_object_BM (objbrows, browsdepth);
  const char *nambrows = findobjectname_BM (objbrows);
  gtk_text_buffer_insert_with_tags
    (browserbuf_BM, &browserit_BM,
     "\342\201\202 " /* U+2042 ASTERISM ⁂ */ , -1,
     objtitle_brotag_BM, NULL);
  char idbuf[32];
  memset (idbuf, 0, sizeof (idbuf));
  idtocbuf32_BM (objid_BM (objbrows), idbuf);
  if (nambrows)
    {
      gtk_text_buffer_insert_with_tags
        (browserbuf_BM, &browserit_BM,
         nambrows, -1, objtitle_brotag_BM, objnametitle_brotag_BM, NULL);
      gtk_text_buffer_insert_with_tags
        (browserbuf_BM, &browserit_BM,
         " |=", -1, objtitle_brotag_BM, objcommtitle_brotag_BM, NULL);
      gtk_text_buffer_insert_with_tags
        (browserbuf_BM, &browserit_BM,
         idbuf, -1,
         objtitle_brotag_BM,
         objcommtitle_brotag_BM, objidtitle_brotag_BM, NULL);
      gtk_text_buffer_insert_with_tags
        (browserbuf_BM, &browserit_BM,
         "|", -1, objtitle_brotag_BM, objcommtitle_brotag_BM, NULL);
    }
  else
    {                           /// anonymous browsed object
      gtk_text_buffer_insert_with_tags
        (browserbuf_BM, &browserit_BM,
         idbuf, -1, objtitle_brotag_BM, objidtitle_brotag_BM, NULL);
    };
  gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", -1);
  send1_BM ((const value_tyBM) objbrows, objsel,
            (struct stackframe_stBM *) &_, taggedint_BM (browsdepth));
  gtk_text_buffer_insert (browserbuf_BM, &browserit_BM, "\n", -1);
  gtk_text_buffer_move_mark (browserbuf_BM,
                             browsedobj_BM[browserobcurix_BM].brow_oendm,
                             &browserit_BM);
}                               /* end browse_object_gui_BM */



void quit_BM (void);
void
quit_BM (void)
{
  //  printf ("quit_BM\n");
  GtkWidget *quitdialog =       //
    gtk_message_dialog_new_with_markup  //
    (GTK_WINDOW (mainwin_BM),
     GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
     GTK_MESSAGE_QUESTION,
     GTK_BUTTONS_OK_CANCEL,
     "Quit without dumping?");
  int resp = gtk_dialog_run (GTK_DIALOG (quitdialog));
  if (resp == GTK_RESPONSE_OK)
    gtk_main_quit ();
  gtk_widget_destroy (quitdialog);
}                               /* end quit_BM */

void exit_BM (void);
void
exit_BM (void)
{
  extern char *dump_dir_bm;
  dump_BM (dump_dir_bm, NULL);
  gtk_main_quit ();
}                               /* end exit_BM */

void do_dump_BM (void);
void
do_dump_BM (void)
{
  extern char *dump_dir_bm;
  dump_BM (dump_dir_bm, NULL);
}                               /* end do_dump_BM */

bool deletemainwin_BM (GtkWidget *, GdkEvent *, gpointer);
bool
deletemainwin_BM (GtkWidget * widget __attribute__ ((unused)),
                  GdkEvent * ev __attribute__ ((unused)),
                  gpointer data __attribute__ ((unused)))
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

static jmp_buf jmperrorcmd_BM;

static parser_error_sigBM parserrorcmd_BM;
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
  .parsop_decorate_comment_sign_rout = parscommentsigncmd_BM,
  .parsop_decorate_comment_inside_rout = parscommentinsidecmd_BM,
  .parsop_decorate_delimiter_rout = parsdelimcmd_BM,
  .parsop_decorate_id_rout = parsidcmd_BM,
  .parsop_decorate_known_name_rout = parsknownamecmd_BM,
  .parsop_decorate_new_name_rout = parsnewnamecmd_BM,
  .parsop_decorate_nesting_rout = parsnestingcmd_BM,
  .parsop_decorate_start_nesting_rout = parsstartnestingcmd_BM,
};



void
parserrorcmd_BM (struct parser_stBM *pars,
                 unsigned lineno, unsigned colpos, char *msg)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  char *errmsg = g_markup_printf_escaped ("<b>command error L%dC%d:</b>\n"
                                          "%s",
                                          lineno, colpos, msg);
  gtk_label_set_markup (GTK_LABEL (msglab_BM), errmsg);
  GtkTextIter it;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit;
  gtk_text_buffer_get_end_iter (commandbuf_BM, &endit);
  gtk_text_buffer_apply_tag (commandbuf_BM, errored_cmdtag_BM, &it, &endit);
  free (msg);
  g_free (errmsg);
  longjmp (jmperrorcmd_BM, 1);
}                               /* end parserrorcmd_BM */


void
parscommentinsidecmd_BM (struct parser_stBM *pars,
                         unsigned colpos, unsigned signlen)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  unsigned lineno = parserlineno_BM (pars);
  GtkTextIter it;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, signlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, commentinside_cmdtag_BM,
                             &it, &endit);
}                               /* end parscommentinsidecmd_BM */


void
parscommentsigncmd_BM (struct parser_stBM *pars,
                       unsigned colpos, unsigned signlen)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  unsigned lineno = parserlineno_BM (pars);
  GtkTextIter it;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, signlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, commentsign_cmdtag_BM,
                             &it, &endit);
}                               /* end parscommentsigncmd_BM */

void
parsdelimcmd_BM (struct parser_stBM *pars, unsigned colpos, unsigned delimlen)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  unsigned lineno = parserlineno_BM (pars);
  GtkTextIter it;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, delimlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, delim_cmdtag_BM, &it, &endit);
}                               /* end parsdelimcmd_BM */

void
parsknownamecmd_BM (struct parser_stBM *pars,
                    unsigned colpos, unsigned namlen)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it;
  unsigned lineno = parserlineno_BM (pars);
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, namlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, knowname_cmdtag_BM, &it, &endit);
}                               /* end parsknownamecmd_BM */


void
parsnewnamecmd_BM (struct parser_stBM *pars, unsigned colpos, unsigned namlen)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it;
  unsigned lineno = parserlineno_BM (pars);
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, namlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, newname_cmdtag_BM, &it, &endit);
}                               /* end parsnewnamecmd_BM */


void
parsidcmd_BM (struct parser_stBM *pars, unsigned colpos, unsigned idlen)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  GtkTextIter it;
  unsigned lineno = parserlineno_BM (pars);
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &it, lineno);
  gtk_text_iter_forward_chars (&it, colpos);
  GtkTextIter endit = it;
  gtk_text_iter_forward_chars (&endit, idlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, id_cmdtag_BM, &it, &endit);
}                               /* end parsidcmd_BM */


void
parsnestingcmd_BM (struct parser_stBM *pars, int depth,
                   enum lexdelim_enBM opendelim, unsigned openlinpos,
                   unsigned opencolpos, enum lexdelim_enBM closedelim,
                   unsigned closelinpos, unsigned closecolpos)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  const char *opendelstr = delimstr_BM (opendelim);
  const char *closedelstr = delimstr_BM (closedelim);
  GtkTextIter openit, endopenit;
  GtkTextIter closeit, stacloseit;
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &openit, openlinpos);
  gtk_text_iter_forward_chars (&openit, opencolpos);
  endopenit = openit;
  int openoff = gtk_text_iter_get_offset (&openit);
  int openlen = g_utf8_strlen (opendelstr, -1);
  gtk_text_iter_forward_chars (&endopenit, openlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, nesting_cmdtag_BM,
                             &openit, &endopenit);
  if (depth < CMD_MAXNEST_BM)
    gtk_text_buffer_apply_tag (commandbuf_BM, open_cmdtags_BM[depth],
                               &openit, &endopenit);
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &closeit, closelinpos);
  gtk_text_iter_forward_chars (&closeit, closecolpos);
  stacloseit = closeit;
  int closelen = g_utf8_strlen (closedelstr, -1);
  int closeoff = gtk_text_iter_get_offset (&closeit);
  gtk_text_iter_backward_chars (&stacloseit, closelen);
  gtk_text_buffer_apply_tag (commandbuf_BM, nesting_cmdtag_BM,
                             &stacloseit, &closeit);
  if (depth < CMD_MAXNEST_BM)
    gtk_text_buffer_apply_tag (commandbuf_BM, close_cmdtags_BM[depth],
                               &stacloseit, &closeit);
  struct parenoffset_stBM po = {        //
    .paroff_open = openoff,
    .paroff_close = closeoff,
    .paroff_xtra = -1,
    .paroff_openlen = openlen,
    .paroff_closelen = closelen,
    .paroff_xtralen = 0,
    .paroff_depth = depth
  };
  cmd_add_parens_BM (&po);
}                               /* end parsnestingcmd_BM */


void
parsstartnestingcmd_BM (struct parser_stBM *pars, int depth,
                        enum lexdelim_enBM xtradelim, unsigned xtralinpos,
                        unsigned xtracolpos, enum lexdelim_enBM opendelim,
                        unsigned openlinpos, unsigned opencolpos,
                        enum lexdelim_enBM closedelim, unsigned closelinpos,
                        unsigned closecolpos)
{
  assert (isparser_BM (pars));
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (parsops && parsops->parsop_magic == PARSOPMAGIC_BM);
  const char *xtradelstr = delimstr_BM (xtradelim);
  const char *opendelstr = delimstr_BM (opendelim);
  const char *closedelstr = delimstr_BM (closedelim);
  GtkTextIter xtrait, endxtrait;
  GtkTextIter openit, endopenit;
  GtkTextIter closeit, stacloseit;
  //
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &xtrait, xtralinpos);
  gtk_text_iter_forward_chars (&xtrait, xtracolpos);
  endxtrait = xtrait;
  int xtraoff = gtk_text_iter_get_offset (&xtrait);
  int xtralen = g_utf8_strlen (xtradelstr, -1);
  gtk_text_iter_forward_chars (&endxtrait, xtralen);
  gtk_text_buffer_apply_tag (commandbuf_BM, nesting_cmdtag_BM,
                             &xtrait, &endxtrait);
  if (depth < CMD_MAXNEST_BM)
    gtk_text_buffer_apply_tag (commandbuf_BM, xtra_cmdtags_BM[depth],
                               &xtrait, &endxtrait);
  //
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &openit, openlinpos);
  gtk_text_iter_forward_chars (&openit, opencolpos);
  endopenit = openit;
  int openoff = gtk_text_iter_get_offset (&openit);
  int openlen = g_utf8_strlen (opendelstr, -1);
  gtk_text_iter_forward_chars (&endopenit, openlen);
  gtk_text_buffer_apply_tag (commandbuf_BM, nesting_cmdtag_BM,
                             &openit, &endopenit);
  if (depth < CMD_MAXNEST_BM)
    gtk_text_buffer_apply_tag (commandbuf_BM, open_cmdtags_BM[depth],
                               &openit, &endopenit);
  //
  gtk_text_buffer_get_iter_at_line (commandbuf_BM, &closeit, closelinpos);
  gtk_text_iter_forward_chars (&closeit, closecolpos);
  stacloseit = closeit;
  int closelen = g_utf8_strlen (closedelstr, -1);
  int closeoff = gtk_text_iter_get_offset (&closeit);
  gtk_text_iter_backward_chars (&stacloseit, closelen);
  gtk_text_buffer_apply_tag (commandbuf_BM, nesting_cmdtag_BM,
                             &stacloseit, &closeit);
  if (depth < CMD_MAXNEST_BM)
    gtk_text_buffer_apply_tag (commandbuf_BM, close_cmdtags_BM[depth],
                               &stacloseit, &closeit);
  struct parenoffset_stBM po = {        //
    .paroff_open = openoff,
    .paroff_close = closeoff,
    .paroff_xtra = xtraoff,
    .paroff_openlen = openlen,
    .paroff_closelen = closelen,
    .paroff_xtralen = xtralen,
    .paroff_depth = depth
  };
  cmd_add_parens_BM (&po);

}                               /* end parsstartnestingcmd_BM */


void
parsercommandbuf_BM (struct parser_stBM *pars, struct stackframe_stBM *stkf)
{
  if (!isparser_BM (pars))
    return;
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (!parsops || parsops->parsop_magic == PARSOPMAGIC_BM);
  bool nobuild = parsops && parsops->parsop_nobuild;
  int nbloop = 0;
  for (;;)
    {
      parserskipspaces_BM (pars);
      if (nbloop++ > MAXSIZE_BM / 32)
        parsererrorprintf_BM (pars, pars->pars_lineno, pars->pars_colpos,
                              "too many %d loops", nbloop);
      if (parserendoffile_BM (pars))
        break;
      parstoken_tyBM tok = parsertokenget_BM (pars);
#warning parsercommandbuf_BM incomplete
    }
}                               /* end parsercommandbuf_BM */

void
parse_command_gui_BM (bool nobuild)
{
  /// should create a parser from the content of the command textview
  /// call longjmp for error catching, then call parsercommandbuf_BM
#warning parse_command_gui_BM unimplemented
}                               /* end parse_command_gui_BM */

void
initialize_gui_BM (const char *builderfile)
{
  if (!builderfile)
    builderfile = "bismon.ui";
  GtkBuilder *bld = gtk_builder_new_from_file (builderfile);
  //gtk_builder_add_callback_symbols (bld, "quitaction_BM", quit_BM, NULL);
  mainwin_BM = gtk_window_new (GTK_WINDOW_TOPLEVEL);
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
  ////////////////
  errored_cmdtag_BM =           //
    gtk_text_tag_table_lookup (commandtagtable_BM, "errored_cmdtag");
  if (!errored_cmdtag_BM)
    FATAL_BM ("cannot find errored_cmdtag");
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
  nesting_cmdtag_BM =           //
    gtk_text_tag_table_lookup (commandtagtable_BM, "nesting_cmdtag");
  if (!nesting_cmdtag_BM)
    FATAL_BM ("cannot find nesting_cmdtag");
  GtkWidget *mainvbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
  gtk_container_add (GTK_CONTAINER (mainwin_BM), mainvbox);
  GtkWidget *mainmenubar = gtk_menu_bar_new ();
  gtk_box_pack_start (GTK_BOX (mainvbox), mainmenubar, /*expand= */ false,
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
  GtkWidget *appmenu =
    GTK_WIDGET (gtk_builder_get_object (bld, "menuapp_id"));
  assert (GTK_IS_WIDGET (appmenu));
  gtk_menu_shell_append (GTK_MENU_SHELL (mainmenubar), appmenu);
  GtkWidget *editmenu =
    GTK_WIDGET (gtk_builder_get_object (bld, "menuedit_id"));
  assert (GTK_IS_WIDGET (editmenu));
  gtk_menu_shell_append (GTK_MENU_SHELL (mainmenubar), editmenu);
  GtkWidget *sep1 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_box_pack_start (GTK_BOX (mainvbox), sep1, /*expand= */ false,
                      /*fill= */ false, 2);
  GtkWidget *paned1 = gtk_paned_new (GTK_ORIENTATION_VERTICAL);
  gtk_paned_set_wide_handle (GTK_PANED (paned1), true);
  gtk_box_pack_start (GTK_BOX (mainvbox), paned1, /*expand= */ true,
                      /*fill= */ true, 2);
  browserbuf_BM = gtk_text_buffer_new (browsertagtable_BM);
  {
    GtkTextIter brit;
    gtk_text_buffer_get_start_iter (browserbuf_BM, &brit);
    gtk_text_buffer_insert_with_tags (browserbuf_BM, &brit,
                                      "BROWSER", -1,
                                      pagetitle_brotag_BM, NULL);
    gtk_text_buffer_insert (browserbuf_BM, &brit, "\n", 1);
    browserendtitlem_BM =       //
      gtk_text_buffer_create_mark (browserbuf_BM, "endtitle_bromk",
                                   &brit, false);
  }
  browserview_BM = gtk_text_view_new_with_buffer (browserbuf_BM);
  gtk_text_view_set_editable (GTK_TEXT_VIEW (browserview_BM), false);
  GtkWidget *browserscrolw = gtk_scrolled_window_new (NULL, NULL);
  gtk_container_add (GTK_CONTAINER (browserscrolw), browserview_BM);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (browserscrolw),
                                  GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  browserobsize_BM = 13;
  browserobulen_BM = 0;
  browsedobj_BM = calloc (browserobsize_BM, sizeof (struct browsedobj_stBM));
  if (!browsedobj_BM)
    FATAL_BM ("calloc failed for %u browsed objects (%m)", browserobsize_BM);
  browsernvsize_BM = 7;
  browsernvulen_BM = 0;
  browsedval_BM = calloc (browsernvsize_BM, sizeof (struct browsedval_stBM));
  if (!browsedval_BM)
    FATAL_BM ("calloc failed for %u browsed values (%m)", browsernvsize_BM);
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
  gtk_text_view_set_editable (GTK_TEXT_VIEW (commandview_BM), true);
  gtk_widget_set_tooltip_markup
    (GTK_WIDGET (commandview_BM), "<big><b>command view</b></big>\n");
  gtk_text_buffer_insert_at_cursor (commandbuf_BM, "|command|\n", -1);
  GtkWidget *commandscrolw = gtk_scrolled_window_new (NULL, NULL);
  gtk_container_add (GTK_CONTAINER (commandscrolw), commandview_BM);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (commandscrolw),
                                  GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  //
  logbuf_BM = gtk_text_buffer_new (logtagtable_BM);
  logview_BM = gtk_text_view_new_with_buffer (logbuf_BM);
  gtk_text_view_set_editable (GTK_TEXT_VIEW (logview_BM), false);
  gtk_text_buffer_insert_at_cursor (logbuf_BM, "*log*\n", -1);
  GtkWidget *logscrolw = gtk_scrolled_window_new (NULL, NULL);
  gtk_container_add (GTK_CONTAINER (logscrolw), logview_BM);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (logscrolw),
                                  GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  //
  gtk_paned_add1 (GTK_PANED (paned1), browserscrolw);
  GtkWidget *paned2 = gtk_paned_new (GTK_ORIENTATION_VERTICAL);
  gtk_paned_set_wide_handle (GTK_PANED (paned2), true);
  gtk_paned_add2 (GTK_PANED (paned1), paned2);
  gtk_paned_add1 (GTK_PANED (paned2), commandscrolw);
  gtk_paned_add2 (GTK_PANED (paned2), logscrolw);
  msglab_BM = gtk_label_new ("-");
  gtk_box_pack_start (GTK_BOX (mainvbox), msglab_BM, /*expand= */ false,
                      /*fill= */ false, 3);
  gtk_window_set_title (GTK_WINDOW (mainwin_BM), "bismon");
  gtk_window_set_default_size (GTK_WINDOW (mainwin_BM), 560, 430);
  gtk_widget_show_all (GTK_WIDGET (mainwin_BM));
}                               /* end initialize_gui_BM */


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
    );
  _.objbrows = (const objectval_tyBM *) arg1;
  int depth = getint_BM (arg2);
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
                 const objectval_tyBM * objbrows;
    );
  _.objbrows = (const objectval_tyBM *) arg1;
  int maxdepth = getint_BM (arg2);
  int curdepth = getint_BM (arg3);
  assert (curdepth <= maxdepth);
  const char *objnam = findobjectname_BM (_.objbrows);
  char idbuf[32];
  memset (idbuf, 0, sizeof (idbuf));
  idtocbuf32_BM (objid_BM (_.objbrows), idbuf);
  if (objnam)
    {
      gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,   //
                                        objnam, -1, objname_brotag_BM, NULL);
      gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,   //
                                        " |=", -1, objrefcomm_brotag_BM,
                                        NULL);
      gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,   //
                                        idbuf, -1, objrefcomm_brotag_BM,
                                        NULL);
      gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM, "|", -1,
                                        objrefcomm_brotag_BM, NULL);
    }
  else
    {                           // anonymous
      gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,   //
                                        idbuf, -1, objid_brotag_BM, NULL);
    }
}                               /* end  ROUTINEOBJNAME_BM (_0BAnB0xjs23_0WEOCOi5Nbe) */


/// method to browse_value for tuple-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_0B1PYH9bN34_3RZdP24AVyt);

value_tyBM
ROUTINEOBJNAME_BM (_0BAnB0xjs23_0WEOCOi5Nb)     //
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
                 const objectval_tyBM * objbrows;
    );
  _.tupbrows = (const tupleval_tyBM *) arg1;
  int maxdepth = getint_BM (arg2);
  int curdepth = getint_BM (arg3);
  assert (curdepth <= maxdepth);
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,       //
                                    "[", -1, nest_brotag_BM, NULL);
#warning unimplemented  method to browse_value for tuple-s _0BAnB0xjs23_0WEOCOi5Nb
  gtk_text_buffer_insert_with_tags (browserbuf_BM, &browserit_BM,       //
                                    "]", -1, nest_brotag_BM, NULL);
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
    );
  _.setbrows = (const setval_tyBM *) arg1;
  int maxdepth = getint_BM (arg2);
  int curdepth = getint_BM (arg3);
  assert (curdepth <= maxdepth);
#warning unimplemented  method to browse_value for set-s _3rne4qbpnV9_0pywzeJp3Qr
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
  int maxdepth = getint_BM (arg2);
  int curdepth = getint_BM (arg3);
  assert (curdepth <= maxdepth);
#warning unimplemented  method to browse_value for int-s _0HBMCM5CeLn_7L5YEV2jO7Y
}                               /* end ROUTINEOBJNAME_BM (_0HBMCM5CeLn_7L5YEV2jO7Y)  */



/// method to browse_value for string-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_63ZPkXUI2Uv_6Cp3qmh6Uud);

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
                 const stringval_tyBM * strbrows;
    );
  _.strbrows = arg1;
  int maxdepth = getint_BM (arg2);
  int curdepth = getint_BM (arg3);
  assert (curdepth <= maxdepth);
#warning unimplemented  method to browse_value for string-s _63ZPkXUI2Uv_6Cp3qmh6Uud
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
    );
  _.nodbrows = arg1;
  int maxdepth = getint_BM (arg2);
  int curdepth = getint_BM (arg3);
  assert (curdepth <= maxdepth);
#warning unimplemented  method to browse_value for node-s _7fJKfG4SN0U_1QTu5J832xg

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
    );
  _.clobrows = arg1;
  int maxdepth = getint_BM (arg2);
  int curdepth = getint_BM (arg3);
  assert (curdepth <= maxdepth);
#warning unimplemented  method to browse_value for closure-s _7CohjJ9tkfZ_4UMAIZCgwac
}                               /* end ROUTINEOBJNAME_BM ( _7CohjJ9tkfZ_4UMAIZCgwac) */
