// file types_BM.h
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
#ifndef TYPES_BM_INCLUDED
#define TYPES_BM_INCLUDED


typedef void *value_tyBM;

typedef void *extendedval_tyBM;

// types of garbage collected values
enum gctyenum_BM
{
  tyInt_BM = -1,                /* actually a tagged int */
  tyNone_BM = 0,                /* e.g. for nil */
#define type_FIRST_BM tyString_BM
  tyString_BM = 1,              /* boxed strings */
  tyDouble_BM = 2,              /* single boxed double - never a NaN */
  tySet_BM = 3,                 /* boxed set of objects */
  tyTuple_BM = 4,               /* boxed tuple of objects */
  tyNode_BM = 5,                /* boxed node */
  tyClosure_BM = 6,             /* boxed closure */
  tyObject_BM = 7,              /* boxed object */
  tyUnspecified_BM = 8,         /* the single unspecified value */
#define type_LASTREAL_BM tyUnspecified_BM
  ty_SpareA_BM = 8,
  ty_SpareB_BM = 9,
  ty_SpareC_BM = 10,
  ty_SpareD_BM = 11,
  ty_SpareE_BM = 12,
  ty_SpareF_BM = 13,
  ty_SpareG_BM = 14,
  ty_SpareH_BM = 15,
  typayl_vectval_BM,
#define typayl_FIRST_BM typayl_vectval_BM
  typayl_assoctable_BM,
  typayl_assocpairs_BM,
  typayl_hashsetobj_BM,
  typayl_listtop_BM,
  typayl_loader_BM,
  typayl_parser_BM,
  typayl_classinfo_BM,
  typayl_strbuffer_BM,
  typayl_dumper_BM,
  typayl_hashsetval_BM,
  typayl_hashsetvbucket_BM,
  typayl_hashmapval_BM,
  typayl_hashmapbucket_BM,
  // for JSONRPC service client socket
  typayl_jsonrpcservice_BM,
  ///
  typayl_jansjson_BM,
  typayl_user_BM,
  typayl_dict_BM,
  typayl_decayed_BM,
#define typayl_LAST_BM typayl_decayed_BM
  typayl__SpareA_BM,
  typayl__SpareB_BM,
  typayl__SpareC_BM,
  typayl__SpareD_BM,
  typayl__SpareE_BM,
  typayl__SpareF_BM,
  typayl__SpareG_BM,
  typayl__SpareH_BM,
  typayl__SpareI_BM,
  typayl__SpareJ_BM,
  typayl__SpareK_BM,
  typayl__SpareL_BM,
  typayl__SpareM_BM,
  typayl__SpareN_BM,
  typayl__SpareO_BM,
  typayl__SpareP_BM,
  typayl__SpareQ_BM,
  typayl__SpareR_BM,
  typayl__SpareS_BM,
  typayl__SpareT_BM,
  typayl__SpareU_BM,
  typayl__SpareV_BM,
  typayl__SpareW_BM,
  typayl__SpareX_BM,
  typayl__SpareY_BM,
  typayl__SpareZ_BM,
  ///
  typayl_quasinode_BM = 0xee00, // 60928, stack allocated!
  //
  //
  typayl_FailureHandler_BM = 0xfffd,
  typayl_SpecialFrame_BM = 0xfffe,
  typayl_StackFrame_BM = 0xffff
};
struct typedhead_stBM
{
  enum gctyenum_BM htyp:24;
  unsigned hgc:8;
  union
  {
    hash_tyBM hash;
    uint32_t rlen;
  };
};
typedef struct typedhead_stBM typedhead_tyBM;
typedef struct typedhead_stBM typedintern_tyBM;



struct typedsize_stBM
{
  typedhead_tyBM pA;
  uint32_t size;
};
typedef struct typedsize_stBM typedsize_tyBM;

/// could be used in a forwarding, copying, GC
struct typedforward_stBM
{
  typedsize_tyBM pS;
  void *forwardptr;
};
typedef struct typedforward_stBM typedforward_tyBM;


struct doubleval_stBM           // for tyDouble_BM
{
  typedhead_tyBM pH;
  double dbl_num;
};
typedef struct doubleval_stBM doubleval_tyBM;   /*tyDouble_BM */

struct allalloc_stBM
{
  unsigned long al_size;        /* allocated size of al_ptr */
  unsigned long al_nb;          /* user number of al_ptr */
  void *al_ptr[];
};

struct stringval_stBM           /* the size field is the length in bytes */
{
  typedforward_tyBM pA;
  char strv_bytes[];
};
typedef struct stringval_stBM stringval_tyBM;   /*tyString_BM */

// forward declaration
typedef struct object_stBM objectval_tyBM;      /*tyObject_BM */

struct seqobval_stBM
{
  typedforward_tyBM pA;
  const objectval_tyBM *seq_objs[];
};

typedef struct seqobval_stBM seqobval_tyBM;
typedef struct seqobval_stBM tupleval_tyBM;     /*tySet_BM */
typedef struct seqobval_stBM setval_tyBM;       /*tyTuple_BM */

enum space_enBM
{
  TransientSp_BM = 0,
  PredefSp_BM = 1,
  GlobalSp_BM = 2,
  UserASp_BM = 3,
  UserBSp_BM = 4,
  UserCsp_BM = 5,
  UserDsp_BM = 6,
  UserEsp_BM = 7,
  ProjectSp_BM = 254,
  LASTSPACE__BM
};

struct datavectval_stBM;        /*forward */
struct assoctable_stBM;         /*forward */
struct assocpairs_stBM;         /*forward */
struct loader_stBM;             /* forward */
struct classinfo_stBM;          /* forward */
struct strbuffer_stBM;          /* forward */
struct dumper_stBM;             /* forward */
struct dict_stBM;               /* forward */
struct user_stBM;               /* forward */
struct decayedvectpayl_stBM;    /* forward */

typedef void anyassoc_tyBM;


struct datavectval_stBM
{                               /* typayl_vectval_BM */
  typedsize_tyBM pA;            /// rlen is allocated size, size is used length
  value_tyBM vec_data[];        // of rlen elements
};

struct strbuffer_stBM           /* for typayl_strbuffer_BM, in scalar_BM.c */
{
  typedhead_tyBM pA;            // rlen is maximal length
  int sbuf_indent;              /* current indentation */
  int sbuf_linecount;           /* count of lines */
  char *sbuf_dbuf;              /* malloc-ed buffer */
  size_t sbuf_size;             /* malloc-ed size */
  char *sbuf_curp;              /* current position in the buffer, never nil */
  char *sbuf_lastnl;            /* last newline in buffer, or NULL if none */
};

struct assoctable_stBM
{                               /* typayl_assoctable_BM */
  typedsize_tyBM pA;
  // rlen is allocated size of abuck_pairs,
  // size is total count of entries
  struct assocpairs_stBM *abuck_pairs[];        // of rlen assocpairs
};

struct assocentry_stBM
{
  const objectval_tyBM *asso_keyob;
  value_tyBM asso_val;
};

struct assocpairs_stBM
{                               /* typayl_assocpairs_BM */
  typedsize_tyBM pa;            // rlen is allocated size, size is used count
  struct assocentry_stBM apairs_ent[];
};

struct hashsetobj_stBM
{                               /* typayl_hashsetobj_BM */
  typedsize_tyBM pa;            // rlen is allocated size, size is used count
  objectval_tyBM *hashset_objs[];
};

// hash set of values
struct hashsetbucket_stBM;
struct hashsetval_stBM          /* typayl_hashsetval_BM */
{
  typedsize_tyBM pa;            // rlen is allocated size, size is used count, i.e. cardinal of the hashset
  struct hashsetvbucket_stBM *hashval_vbuckets[];
};

struct hashsetvbucket_stBM      /* typayl_hashsetvbucket_BM */
{
  typedsize_tyBM pa;            // rlen is allocated size, size is used count
  value_tyBM vbuck_arr[];
};


// hash map associating values to values
struct hashmapbucket_stBM;
struct hashmapval_stBM          /* typayl_hashmapval_BM */
{
  typedsize_tyBM pa;            // rlen is allocated size, size is
  // used count, i.e. number of filled
  // entries in the hashmap
  struct hashmapbucket_stBM *hashmap_vbuckets[];
};                              /* end struct hashmapval_stBM */

struct hashmapentry_stBM
{
  value_tyBM hmap_keyv;
  value_tyBM hmap_valv;
};                              /* end struct hashmapentry_stBM */

struct hashmapbucket_stBM       /* typayl_hashmapbucket_BM */
{
  typedsize_tyBM pa;            // rlen is allocated size, size is used count
  struct hashmapentry_stBM vbent_arr[];
};

struct classinfo_stBM
{
  typedhead_tyBM pA;            // rlen & hash are unused
  objectval_tyBM *clinf_superclass;
  anyassoc_tyBM *clinf_dictmeth;
};

enum dumpstate_enBM
{
  dum__none,
  dum_scan,
  dum_emit
};

struct dumper_stBM
{
  typedhead_tyBM pA;            // rlen & hash are unused
  enum dumpstate_enBM dump_state;
  FILE* dump_lockfile;
  objectval_tyBM *dump_object;
  const stringval_tyBM *dump_dir;
  struct hashsetobj_stBM *dump_hset;
  struct listtop_stBM *dump_scanlist;
  struct listtop_stBM *dump_todolist;
  rawid_tyBM dump_randomid;
  long dump_scanedobjectcount;
  long dump_emittedobjectcount;
  long dump_todocount;
  long dump_wrotefilecount;
  double dump_startelapsedtime;
  double dump_startcputime;
};

// the result of dump_BM
struct dumpinfo_stBM
{
  long dumpinfo_scanedobjectcount;
  long dumpinfo_emittedobjectcount;
  long dumpinfo_todocount;
  long dumpinfo_wrotefilecount;
  double dumpinfo_elapsedtime;
  double dumpinfo_cputime;
};

#define LINKSIZE_BM 14
struct listlink_stBM            ///internal, not a value
{
  struct listlink_stBM *link_next;
  struct listlink_stBM *link_prev;
  value_tyBM link_mems[LINKSIZE_BM];
};

struct listtop_stBM
{                               // for  typayl_listtop_BM
  typedhead_tyBM pa;            // rlen is number of values in the list
  unsigned list_nblinks;        // number of struct listlink_stBM
  struct listlink_stBM *list_first;
  struct listlink_stBM *list_last;
};

struct parenoffset_stBM
{                               /// internal, not a value
  int paroff_open;              // relative offset before open parenthesis-like
  int paroff_close;             // relative offset after close parenthesis-like
  int paroff_xtra;              // relative offset of xtra sign, such as the *, or -1
  uint8_t paroff_openlen;       // length in UTF-8 chars of opening sign
  uint8_t paroff_closelen;      // length in UTF-8 chars of closing sign
  uint8_t paroff_xtralen;       // length in UTF-8 chars of xtra sign
  uint8_t paroff_depth;         // depth
};

struct nodetree_stBM
{                               // for tyNode_BM && tyClosure_BM
  typedforward_tyBM pA;         // size is the number of sons
  objectval_tyBM *nodt_conn;
  value_tyBM nodt_sons[];
};

typedef struct nodetree_stBM tree_tyBM; /* for tyClosure_BM or tyNode_BM or typayl_quasinode_BM */
typedef struct nodetree_stBM node_tyBM; /* for tyNode_BM */
typedef struct nodetree_stBM closure_tyBM;      /* for tyClosure_BM */
typedef struct nodetree_stBM quasinode_tyBM;    /* for typayl_quasinode_BM */


struct stackframe_stBM;

// the x86-64 ABI passes six arguments thru registers
typedef value_tyBM objrout_sigBM (struct stackframe_stBM *stkf,
                                  const value_tyBM arg1,
                                  const value_tyBM arg2,
                                  const value_tyBM arg3,
                                  const value_tyBM arg4,
                                  const quasinode_tyBM * restargs);
/* see related crashing_objrout_BM and warning_objrout_BM functions */


// signature of module initialization; the returned value should also refer to constants inside that module
typedef value_tyBM moduleinit_sigBM (struct stackframe_stBM *stkf,
                                     const value_tyBM arg1,
                                     const value_tyBM arg2,
                                     const value_tyBM arg3,
                                     void *dlh /*dlopen handle of module */ );

typedef void deferredaftergc_sigBM (value_tyBM * valarr, unsigned nbval,
                                    void *data);


/// signature of testplugin initialization; a testplugin FOO may have
/// a FOO_initest_BM function of signature
typedef void testplugininit_sigBM (struct stackframe_stBM *stkf,
                                   const char *pluginame, int pluginrk);
/// signature of testplugin run; a testplugin FOO should have a FOO_runtest_BM function of signature
typedef int testpluginrun_sigBM (struct stackframe_stBM *stkf,
                                 const char *pluginame, int pluginrk);
/// if that FOO_runtest_BM returns non-zero it has failed.
struct object_stBM              /*tyObject_BM */
{
  typedhead_tyBM pA;
  rawid_tyBM ob_id;
  uint8_t ob_space;
  double ob_mtime;
  pthread_mutex_t ob_mutex;
#ifdef __cplusplus
    std::atomic < objectval_tyBM * >ob_classatomic;
#else
  objectval_tyBM *_Atomic volatile ob_aclass;
#endif /*__cplusplus*/
  struct datavectval_stBM *ob_compvec;
  anyassoc_tyBM *ob_attrassoc;
  union
  {
    objrout_sigBM *ob_rout;
    void *ob_routaddr;
  };
  objectval_tyBM *ob_sig;
  extendedval_tyBM ob_payl;
};


/// user information, could be relevant to GDPR.  See explanations in
/// userlogin.md
struct user_stBM                // for typayl_user_BM 
{
  typedhead_tyBM pA;            // rlen & hash are unused
  objectval_tyBM *user_ownobj;  /* owning object */
  const stringval_tyBM *user_namev;     /* the user name, e.g. First Lastname */
  const stringval_tyBM *user_emailv;    /* the user primary email */
};                              /* end user_stBM */




#define STACKFRAMEFIELDS_BM			\
  typedhead_tyBM stkfram_pA;			\
  struct stackframe_stBM *stkfram_prev;		\
  objectval_tyBM *stkfram_descr;		\
  value_tyBM stkfram_callfun;			\
  int stkfram_state;				\
  int stkfram_xtra
struct stackframe_stBM
{                               // for typayl_StackFrame_BM, sitting on the callstack
  STACKFRAMEFIELDS_BM;
  value_tyBM stkfram_locals[];
};

struct emptystackframe_stBM
{
  STACKFRAMEFIELDS_BM;
};

// LOCALFRAME_BM is in cmacros_BM.h

struct specialframe_stBM;
struct garbcoll_stBM;
typedef void specialframe_marker_sigBM (struct garbcoll_stBM *,
                                        struct specialframe_stBM *);
struct specialframe_stBM        // for typayl_SpecialFrame_BM
{
  typedhead_tyBM pA;            // rlen is unused
  struct stackframe_stBM *specfram_prev;
  objectval_tyBM *specfram_descr;
  specialframe_marker_sigBM *specfram_markerout;
  intptr_t specfram_intp;
  void *specfram_cdata[];
};

struct failurelockset_stBM;     // an opaque type

#ifndef __cplusplus
struct failurelockset_stBM
{
  long __flockset_dummy[16];
};
#endif /*__cplusplus */

struct failurehandler_stBM      // for typayl_FailureHandler_BM,
                                  // should be on stack
{
  typedhead_tyBM pA;            // rlen is unused
  unsigned failh_magic;         // always FAILUREHANDLEMAGIC_BM
  bool failh_silent;
  struct failurelockset_stBM *failh_lockset;
  value_tyBM failh_reason;
  value_tyBM failh_place;
  jmp_buf failh_jmpbuf;
};                              /* end of failurehandler_stBM */

struct loader_stBM              // malloc-ed then free-d at load time
{                               // for typayl_loader_BM
  typedhead_tyBM pa;            // rlen is unused
  unsigned ld_magic;            /* always LOADERMAGIC_BM */
  unsigned ld_maxnum;           /* highest number of store*.bmon files */
  int ld_curspaceix;		/* a space number, or < 0 if none */
  int ld_passnum;		/* 1 for the first pass, 2 for the second pass, < 0 for none */
  double ld_startelapsedtime;
  double ld_startcputime;
  unsigned long ld_nbobjects;
  unsigned ld_nbmodules, ld_nbroutines;
  struct hashsetobj_stBM *ld_objhset;   // hashset of loaded objects
  struct hashsetobj_stBM *ld_modhset;   // hashset of loaded module objects
  struct listtop_stBM *ld_todolist;
  // in the store arrays below, index 0 is for the store_todo
  char **ld_storepatharr;       /* calloc-ed array of malloc-ed string paths */
  char*ld_projectstatepath; /* malloc-ed string containing the project state */
  struct parser_stBM **ld_parsarr;      /* calloc-ed array of parsers */
  value_tyBM ld_data;           /* common data */
  objectval_tyBM**ld_objroutarr; /* calloced array of object whose routine was not dlsym-ed */
  unsigned ld_size_objroutarr;	 /* its allocated size */
  unsigned ld_count_objrout;	 /* its used count */
  char *ld_dir;                 /* malloc-ed directory path */
};                              /* end struct loader_stBM */

struct memolineoffset_stBM
{
  long memli_off;               /* offset in file */
  int memli_lineno;             /* current file number */
  int memli_linebylen;          /* length of current file */
};


enum parslexkind_enBM
{
  plex__NONE,
  plex_LLONG,                   /// an integer number
  plex_DOUBLE,                  /// a float number having a dot, or +NAN or +INF or -INF
  plex_DELIM,
  plex_ID,
  plex_NAMEDOBJ,
  plex_CNAME,
  plex_WORD,
  plex_STRING,
};

enum lexdelim_enBM
{
  delim__NONE,
#define HAS_DELIM_BM(Str,Delimname) delim_##Delimname,
#include "bm_delim.h"
  delim__LAST
};                              /* end lexdelim_enBM */

// tokens are NOT garbage collected, but may contain a GC-ed value
struct parstoken_stBM
{
  enum parslexkind_enBM tok_kind;
  int tok_line, tok_col;
  union
  {
    void *tok_ptr;
    long long tok_llong;        // for plex_LLONG
    double tok_dbl;             // for plex_DOUBLE
    rawid_tyBM tok_id;          // for plex_ID
    objectval_tyBM *tok_namedobj;       // for plex_NAMEDOBJ
    enum lexdelim_enBM tok_delim;       // for plex_DELIM
    const stringval_tyBM *tok_cname;    // for plex_CNAME
    const stringval_tyBM *tok_word;     // for plex_WORD
    const stringval_tyBM *tok_string;   // for plex_STRING
  };
};                              /* end struct parstoken_stBM */
typedef struct parstoken_stBM parstoken_tyBM;

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


// not heap allocated, but constant and often in text segment
struct parserops_stBM
{
  const unsigned parsop_magic;  /* always PARSOPMAGIC_BM */
  const unsigned short parsop_serial;   /* some number, often unused */
  const bool parsop_nobuild;    /* if set, don't build any value */
  // error processing
  parser_error_sigBM *parsop_error_rout;
  // expansion of $<var> for values
  parser_expand_dollarval_sigBM *parsop_expand_dollarval_rout;
  // expansion of $:<var> for object
  parser_expand_dollarobj_sigBM *parsop_expand_dollarobj_rout;
  // expansion of $*<name> or €<name> for new names
  parser_expand_newname_sigBM *parsop_expand_newname_rout;
  // parse then expand $(...) value expression
  parser_expand_valexp_sigBM *parsop_expand_valexp_rout;
  // parse then expand $[...] object expression
  parser_expand_objexp_sigBM *parsop_expand_objexp_rout;
  // parse then expand ^ object (....) readmacro
  parser_expand_readmacro_sigBM *parsop_expand_readmacro_rout;
  // parse & accept unary node
  parser_accept_unary_sigBM *parsop_accept_unary_rout;
  // decoration of comments
  parser_decorate_comment_sign_sigBM *parsop_decorate_comment_sign_rout;
  parser_decorate_comment_inside_sigBM *parsop_decorate_comment_inside_rout;
  // decoration of numbers
  parser_decorate_number_sigBM *parsop_decorate_number_rout;
  // decoration of strings
  parser_decorate_string_sign_sigBM *parsop_decorate_string_sign_rout;
  parser_decorate_string_inside_sigBM *parsop_decorate_string_inside_rout;
  // decoration of delimiters
  parser_decorate_delimiter_sigBM *parsop_decorate_delimiter_rout;
  // decoration of identifiers
  parser_decorate_id_sigBM *parsop_decorate_id_rout;
  // decoration of both known and unknown names
  parser_decorate_name_sigBM *parsop_decorate_known_name_rout;
  parser_decorate_name_sigBM *parsop_decorate_new_name_rout;
  // decoration of nesting & start-nesting
  parser_decorate_nesting_sigBM *parsop_decorate_nesting_rout;
  parser_decorate_start_nesting_sigBM *parsop_decorate_start_nesting_rout;
};

struct parser_stBM              /* for typayl_parser_BM */
{
  typedhead_tyBM pa;            // rlen is unused
  const struct parserops_stBM *pars_ops;
  FILE *pars_file;
  bool pars_debug;
  bool pars_warnunknownid;      /* if set, an unknown-id gives a warning, not a parser error */
  const char *pars_path;
  value_tyBM pars_cvalue;       /* client value */
  objectval_tyBM *pars_ownob;   /* owner object */
  const char *pars_filemem;     /* when using fmemopen */
  size_t pars_filesize;         /* when using fmemopen */
  char *pars_linebuf;           /* given by getline */
  const char *pars_curbyte;     /* current byte in the line */
  size_t pars_linesiz;          /* for getline */
  ssize_t pars_linelen;         /* result of getline */
  unsigned pars_lineno;         /* line number of pars_linebuf */
  unsigned pars_colpos;         /* UTF-8 position in current line */
  unsigned pars_memolsize;      /* allocated size of pars_memolines  */
  unsigned pars_memolcount;     /* used count of pars_memolines  */
  struct memolineoffset_stBM *pars_memolines;   // calloc-ed
  void *pars_clientdata;        /* client data, for parsing routines */
};                              /* end struct parser_stBM */

struct dict_stBM
{
  typedhead_tyBM pa;
  uintptr_t dict_data[8];       /* actually a C++ std::map, see misc_BM.cc */
};

struct jansjson_stBM
{
  typedhead_tyBM pa;
  json_t *jansjson_ptr;
};


// a decayed payload vector auto-destroys itself after some elapsed limiting time
struct decayedvectpayl_stBM     // for typayl_decayed_BM, see file sequence_BM.c
{
  typedforward_tyBM pa;         /// rlen is allocated size, size is used length
  double decayp_limitime;
  value_tyBM decayp_arr[];      // of rlen elements
};

// allocated size:
#define DECAYEDVECTOR_ASIZ_bm(Dvec)   ((typedhead_tyBM*)(Dvec))->rlen
// used count:
#define DECAYEDVECTOR_UCNT_bm(Dvec)   ((typedsize_tyBM*)(Dvec))->size



////////////////////////////////////////////////////////////////
////// JsonRpc Unix Socket related payload

#define BISMON_JSONRPCSERV_MAGICNUM 652590229 /*0x26e5bc95 */
struct jsonrpcservicedata_stBM { /* for typayl_jsonrpcservice_BM */
  typedhead_tyBM jsonrpcserv_head;  // rlen is unused
  unsigned jsonrpcserv_magic;       /* always BISMON_JSONRPCSERV_MAGICNUM */
  int jsonrpcserv_sockfd;	    /* listening Unix socket */
  char* jsonrpcserv_buffer;	    /* incoming buffer, for perhaps partial JSON... */
  unsigned jsonrpcserv_sizbuf;	/* allocated buffer size */
  unsigned jsonrpcserv_buflen;	/* used buffer length, always less that buffer size */
  const closure_tyBM *jsonrpcserv_clos;
  value_tyBM jsonrpcserv_mainval;
  value_tyBM jsonrpcserv_xtraval;
};



////////////////////////////////////////////////////////////////
////// web related

/// inspired by my (Basile Starynkevitch's) previous code in
/// https://github.com/bstarynk/old-melt-monitor/ files monimelt.h &
/// web-onion.c

/// both websessiondata & webexchangedata payloads and their owning
/// objects are only created by the web infrastructure. So there is no
/// public function to create them, or put them as a payload

////////////////////////////////////////////////////////////////
/// NB: struct browsedval_stBM & struct browsedobj_stBM are in globals_BM.h
struct garbcoll_stBM
{
  uint32_t gc_magic;
  uint32_t gc_spareunsigned;
  /* both data structures below can be GC allocated, because they
     would never be scanned by the GC. */
  // the list of objects to be scanned
  struct listtop_stBM *gc_scanlist;
  // the hashset of objects added into previous list
  struct hashsetobj_stBM *gc_hset;
  // the amount of freed memory in bytes
  size_t gc_freedbytes;
  // the amount of kept memory in bytes
  size_t gc_keptbytes;
  // the number of marked values
  long gc_nbmarks;
  // the number of kept objects
  long gc_nbkeptobjects;
  // the number of destroyed objects
  long gc_nbdestroyedobjects;
  // start elapsed and cpu time
  double gc_startelapsedtime;
  double gc_startcputime;
};




////////////////////////////////////////////////////////////////
//// We could have a few child processes (running GCC compilation
//// commands, shell commands, shell scripts, indenters, printers,
//// ....) à la batch(1). Their stdin is /dev/null ...
//////////////////////////////////////////////////////////////////////////
/// For process queue running processes; See comment in fundecl_BM.h
/// about function queue_process_BM, and mutex pendingrunproc_mtx_BM for exclusive access.
struct processdescr_stBM
{
  /* if the process is running its pid, otherwise 0: */
  pid_t rp_pid;
  /* if process is running, the file descriptor of its output pipe for its stdout/stderr, read by Bismon: */
  int rp_outpipe;
  /* The directory into which the process should be run before fork(2)-ing it: */
  const stringval_tyBM *rp_dirstrv;
  /* The node giving the strings (argv for execve(2), first string being the executable...) */
  const node_tyBM *rp_cmdnodv;
  /* The closure which, once the process has terminated, gets the status etc... */
  const closure_tyBM *rp_closv;
  /* The object containing the buffer for output */
  objectval_tyBM *rp_bufob;
};				/* end struct processdescr_stBM */
#endif /*TYPES_BM_INCLUDED */
