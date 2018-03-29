// file globals_BM.h

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

#ifndef GLOBALS_BM_INCLUDED
#define GLOBALS_BM_INCLUDED
// from generated _timestamp.c
extern const char bismon_timestamp[];
extern const unsigned long bismon_timelong;
extern const char bismon_lastgitcommit[];
extern const char bismon_lastgittag[];
extern const char bismon_checksum[];
extern const char bismon_directory[];
extern const char bismon_makefile[];

// from generated _bm_allconsts.c
extern const int bmnbconsts;
extern void **const bmconstaddrs[];
extern const char *bmconstidstrings[];

extern const char myhostname_BM[];
extern atomic_bool want_garbage_collection_BM;
extern bool gui_is_running_BM;
extern bool oldgui_BM;
extern FILE *gui_command_log_file_BM;

extern GtkTextIter browserit_BM;

extern pthread_t mainthreadid_BM;

extern void *dlprog_BM;         // dlopen of entire program
extern struct timespec startrealtimespec_BM;

// the loader, which is non-null only while loading
extern struct loader_stBM *firstloader_BM;

extern thread_local struct threadinfo_stBM *curthreadinfo_BM;
extern thread_local volatile struct failurehandler_stBM *curfailurehandle_BM;


extern struct allalloc_stBM *allocationvec_vBM /*¤ allocgc_BM.c */ ;
extern pthread_mutex_t allocationmutex_BM;
#define HAS_PREDEF_BM(Id,Hi,Lo,Hash) \
  extern objectval_tyBM predefdata##Id##_BM; \
  extern objectval_tyBM* predefptr##Id##_BM;
#include "_bm_predef.h"

#define PREDEF_BM(Id) (predefptr##Id##_BM)

extern const typedhead_tyBM unspecifieddata_BM;




/********************************* GUI **************/
extern GtkWidget *mainwin_BM;
extern GtkWidget *errormessagedialog_BM;
extern FILE *gui_command_log_file_BM;
extern int browserdepth_BM;
extern GtkTextTagTable *browsertagtable_BM;
extern GtkTextBuffer *browserbuf_BM;
extern GtkWidget *browserview_BM;
extern GtkTextIter browserit_BM;
extern int browserendtitleoffset_BM;
extern GtkTextTag *pagetitle_brotag_BM;
extern GtkTextTag *objtitle_brotag_BM;
extern GtkTextTag *valtitle_brotag_BM;
extern GtkTextTag *focustitle_brotag_BM;
extern GtkTextTag *objcommtitle_brotag_BM;
extern GtkTextTag *objnametitle_brotag_BM;
extern GtkTextTag *objidtitle_brotag_BM;
extern GtkTextTag *objid_brotag_BM;
extern GtkTextTag *objname_brotag_BM;
extern GtkTextTag *objrefcomm_brotag_BM;
extern GtkTextTag *nest_brotag_BM;
extern GtkTextTag *blink_brotag_BM;
extern GtkTextTag *num_brotag_BM;
extern GtkTextTag *toodeep_brotag_BM;
extern GtkTextTag *str_brotag_BM;
extern GtkTextTag *stresc_brotag_BM;
extern GtkTextTag *miscomm_brotag_BM;
extern GtkTextTag *epilogue_brotag_BM;


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
extern GtkTextTag *error_logtag_BM;
extern GtkTextTag *time_logtag_BM;
extern GtkTextTag *id_logtag_BM;
extern GtkTextTag *name_logtag_BM;
extern GtkTextTag *comment_logtag_BM;
extern GtkTextTag *command_logtag_BM;
extern GtkTextTag *code_logtag_BM;

extern GtkTextTag *errored_cmdtag_BM;
extern GtkTextTag *skipped_cmdtag_BM;
extern GtkTextTag *commentinside_cmdtag_BM;
extern GtkTextTag *commentsign_cmdtag_BM;
extern GtkTextTag *delim_cmdtag_BM;
extern GtkTextTag *knowname_cmdtag_BM;
extern GtkTextTag *newname_cmdtag_BM;
extern GtkTextTag *id_cmdtag_BM;
extern GtkTextTag *number_cmdtag_BM;
extern GtkTextTag *stringsign_cmdtag_BM;
extern GtkTextTag *stringinside_cmdtag_BM;
extern GtkTextTag *dollar_cmdtag_BM;
extern GtkTextTag *nesting_cmdtag_BM;
extern GtkTextTag *blink_cmdtag_BM;

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


/*****************************************************************/
#define UNSPECIFIED_BM ((void*)(&unspecifieddata_BM))

#define HAS_GLOBAL_BM(Nam) extern objectval_tyBM*globdata_##Nam##_BM;
#include "_bm_global.h"

#endif /*GLOBALS_BM_INCLUDED */
