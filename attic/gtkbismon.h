// file gtkbismon.h
#ifndef GTKBISMON_INCLUDED
#define GTKBISMON_INCLUDED
// SPDX-License-Identifier: GPL-3.0-or-later
/**
    BISMON 
    Copyright © 2018 - 2022 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch.

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

----
    Contact me (Basile Starynkevitch) by email
    basile@starynkevitch.net and/or basile.starynkevitch@cea.fr
**/

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <gtk/gtk.h>

#include "bismon.h"

#define BISMONGTK 1

/********************************* GUI **************/
extern char *gui_init_cmd_file_BM;
extern GtkTextIter browserit_BM;
extern GtkWidget *mainwin_BM;
extern GtkWidget *errormessagedialog_BM;
extern FILE *gui_command_log_file_BM;
extern int browserdepth_BM;
extern GtkTextTagTable *browsertagtable_BM;
extern GtkTextBuffer *browserbuf_BM;
extern GtkWidget *browserview_BM;
extern GtkTextIter browserit_BM;
extern int browserendtitleoffset_BM;
extern GtkTextTag *pagetitle_brotag_GTKBM;
extern GtkTextTag *objtitle_brotag_GTKBM;
extern GtkTextTag *valtitle_brotag_GTKBM;
extern GtkTextTag *focustitle_brotag_GTKBM;
extern GtkTextTag *objcommtitle_brotag_GTKBM;
extern GtkTextTag *objnametitle_brotag_GTKBM;
extern GtkTextTag *objidtitle_brotag_GTKBM;
extern GtkTextTag *objid_brotag_GTKBM;
extern GtkTextTag *objname_brotag_GTKBM;
extern GtkTextTag *objrefcomm_brotag_GTKBM;
extern GtkTextTag *nest_brotag_GTKBM;
extern GtkTextTag *blink_brotag_GTKBM;
extern GtkTextTag *num_brotag_GTKBM;
extern GtkTextTag *toodeep_brotag_GTKBM;
extern GtkTextTag *str_brotag_GTKBM;
extern GtkTextTag *stresc_brotag_GTKBM;
extern GtkTextTag *miscomm_brotag_GTKBM;
extern GtkTextTag *epilogue_brotag_GTKBM;

#define BLINKDELAYMILLISEC_GTKBM 750
#define UNBLINKDELAYMILLISEC_GTKBM 400

////////////////
/// the browsed objects
extern unsigned browserobsize_BM;       /* allocated size of browsedobj_BM */
extern unsigned browserobulen_BM;       /* used length */
extern int browserobcurix_BM;   /* current index in browsedobj_BM */
struct browsedobj_stBM
{
  objectval_tyBM *brow_obj;
  objectval_tyBM *brow_objsel;
  GtkTextMark *brow_ostartm;
  GtkTextMark *brow_oendm;
  void *brow_odata;             /* extra client data */
  int brow_odepth;
  unsigned brow_oparensize;     /* allocated size of brow_parenarr */
  unsigned brow_oparenulen;     /* used length of brow_parenarr */
  struct parenoffset_stBM *brow_oparenarr;
};
extern struct browsedobj_stBM *browsedobj_BM;


////////////////
/// the browsed named values
extern unsigned browsednvsize_BM;       /* allocated size */
extern unsigned browsednvulen_BM;       /* used length */
extern int browsednvcurix_BM;
struct browsedval_stBM
{
  const stringval_tyBM *brow_name;
  value_tyBM brow_val;
  GtkTextMark *brow_vstartmk;
  GtkTextMark *brow_vendmk;
  int brow_vdepth;
  void *brow_vdata;             /* extra client data */
  unsigned brow_vparensize;     /* allocated size of brow_parenarr */
  unsigned brow_vparenulen;     /* used length of brow_parenarr */
  struct parenoffset_stBM *brow_vparenarr;
};
extern struct browsedval_stBM *browsedval_BM;
extern guint browserblinkid_BM;
extern struct parenoffset_stBM browserblinkparens_BM;   /// offsets are absolute

////////////////
extern int commandnumber_BM;
/// the completion set - should be a GC root
extern const seqobval_tyBM *complseqcmd_BM;
/// begin and end offset for completion replacement
extern int compbegoffcmd_BM, compendoffcmd_BM;

//////////////// command
extern GtkTextTagTable *commandtagtable_BM;
extern GtkTextBuffer *commandbuf_BM;
extern GtkWidget *commandview_BM;

extern GtkTextTagTable *logtagtable_BM;
extern GtkTextBuffer *logbuf_BM;
extern GtkWidget *logview_BM;
extern GtkTextTag *error_logtag_GTKBM;
extern GtkTextTag *time_logtag_GTKBM;
extern GtkTextTag *id_logtag_GTKBM;
extern GtkTextTag *name_logtag_GTKBM;
extern GtkTextTag *comment_logtag_GTKBM;
extern GtkTextTag *command_logtag_GTKBM;
extern GtkTextTag *code_logtag_GTKBM;

extern GtkTextTag *errored_cmdtag_GTKBM;
extern GtkTextTag *skipped_cmdtag_GTKBM;
extern GtkTextTag *commentinside_cmdtag_GTKBM;
extern GtkTextTag *commentsign_cmdtag_GTKBM;
extern GtkTextTag *delim_cmdtag_GTKBM;
extern GtkTextTag *knowname_cmdtag_GTKBM;
extern GtkTextTag *newname_cmdtag_GTKBM;
extern GtkTextTag *id_cmdtag_GTKBM;
extern GtkTextTag *number_cmdtag_GTKBM;
extern GtkTextTag *stringsign_cmdtag_GTKBM;
extern GtkTextTag *stringinside_cmdtag_GTKBM;
extern GtkTextTag *dollar_cmdtag_GTKBM;
extern GtkTextTag *nesting_cmdtag_GTKBM;
extern GtkTextTag *blink_cmdtag_GTKBM;

#define CMD_MAXNEST_BM 64
extern GtkTextTag *open_cmdtags_BM[CMD_MAXNEST_BM];
extern GtkTextTag *close_cmdtags_BM[CMD_MAXNEST_BM];
extern GtkTextTag *xtra_cmdtags_BM[CMD_MAXNEST_BM];

#define BROWSE_MAXDEPTH_BM 48

// on cmd parse error, we setjmp to ....
extern jmp_buf jmperrorcmd_BM;
extern guint commandblinkid_BM;
extern struct parenoffset_stBM commandblinkparens_BM;   /// offsets are absolute
extern const struct parserops_stBM parsop_command_build_BM;
extern const struct parserops_stBM parsop_command_nobuild_BM;

struct parser_stBM;
// expand the $<var>, varname is the tok_cname or tok_namedobj
typedef value_tyBM parser_expand_dollarval_sigBM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
   const value_tyBM varname, struct stackframe_stBM *stkf);
// expand the $:<var>, varname is the tok_cname or tok_namedobj
typedef const objectval_tyBM *parser_expand_dollarobj_sigBM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
   const value_tyBM varname, struct stackframe_stBM *stkf);
// expand the $*<name> or €<name>
typedef const objectval_tyBM *parser_expand_newname_sigBM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
   const value_tyBM varname, struct stackframe_stBM *stkf);
// parse then expand $( .... ) value expression
typedef value_tyBM parser_expand_valexp_sigBM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos, int depth,
   struct stackframe_stBM *stkf);
// parse then expand $[ .... ] object expression
typedef const objectval_tyBM *parser_expand_objexp_sigBM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos, int depth,
   struct stackframe_stBM *stkf);
// parse then expand ^ oper ( ... ) readmacro expansion
typedef value_tyBM parser_expand_readmacro_sigBM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos, int depth,
   const node_tyBM * nod, struct stackframe_stBM *stkf);
// parse and accept unary * oper <arg> expansion
typedef bool parser_accept_unary_sigBM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos, int depth,
   objectval_tyBM * unconnob, struct stackframe_stBM *stkf);
// decorate the comment signs
typedef void parser_decorate_comment_sign_sigBM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
   unsigned signlen);
// decorate the comment inside
typedef void parser_decorate_comment_inside_sigBM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
   unsigned signlen);

// decorate the string signs
typedef void parser_decorate_string_sign_sigBM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
   unsigned signlen);
// decorate the string inside
typedef void parser_decorate_string_inside_sigBM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
   unsigned signlen);

// decorate numbers
typedef void parser_decorate_number_sigBM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
   unsigned numlen);

// decorate ids
typedef void parser_decorate_id_sigBM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
   unsigned idlen);

// decorate names, both known and unknown
typedef void parser_decorate_name_sigBM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
   unsigned namlen);

// decorate delimiters
typedef void parser_decorate_delimiter_sigBM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos,
   unsigned delimlen);

// decorate nesting (e.g. for sets & tuples) 
typedef void parser_decorate_nesting_sigBM
  (struct parser_stBM *pars, int depth,
   enum lexdelim_enBM opendelim, unsigned openlinpos, unsigned opencolpos,
   enum lexdelim_enBM closedelim, unsigned closelinpos, unsigned closecolpos);

// decorate start nesting (e.g. for nodes & closures)
typedef void parser_decorate_start_nesting_sigBM
  (struct parser_stBM *pars, int depth,
   enum lexdelim_enBM startdelim, unsigned startlinpos, unsigned startcolpos,
   enum lexdelim_enBM opendelim, unsigned openlinpos, unsigned opencolpos,
   enum lexdelim_enBM closedelim, unsigned closelinpos, unsigned closecolpos);

// signal parse error; the msg is a malloc-ed string which the error handling routine
// should free when it is doing a longjmp
typedef void parser_error_sigBM
  (struct parser_stBM *pars, struct stackframe_stBM *stkf,
   unsigned lineno, unsigned colpos, char *msg)
  /*__attribute__ ((noreturn))*/ ;




// decorate e.g. // or | with commentsign_cmdtag
extern parser_decorate_comment_sign_sigBM parscommentsign_guicmd_BM;

// decorate with commentinside_cmdtag
extern parser_decorate_comment_inside_sigBM parscommentinside_guicmd_BM;

// decorate with delim_cmdtag
extern parser_decorate_delimiter_sigBM parsdelim_guicmd_BM;

// decorate with id_cmdtag
extern parser_decorate_id_sigBM parsid_guicmd_BM;

// decorate with knowname_cmdtag
extern parser_decorate_name_sigBM parsknowname_guicmd_BM;

// decorate with newname_cmdtag
extern parser_decorate_name_sigBM parsnewname_guicmd_BM;

// decorate open/close with nesting_cmdtag & open/close tags
extern parser_decorate_nesting_sigBM parsnesting_guicmd_BM;

// decorate start/open/close with nesting_cmdtag & start/open/close tags
extern parser_decorate_start_nesting_sigBM parsstartnesting_guicmd_BM;

// decorate numbers
extern parser_decorate_number_sigBM parsnumber_guicmd_BM;

// decorate strings
extern parser_decorate_string_sign_sigBM parsstringsign_guicmd_BM;
extern parser_decorate_string_inside_sigBM parsstringinside_guicmd_BM;
#endif /* GTKBISMON_INCLUDED */
/// eof gtkbismon.h
