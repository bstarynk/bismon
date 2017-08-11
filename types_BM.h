// file types_BM.h
#ifndef TYPES_BM_INCLUDED
#define TYPES_BM_INCLUDED


typedef void *value_tyBM;

typedef uint32_t hash_tyBM;
struct typedhead_stBM
{
  unsigned htyp:24;
  unsigned hgc:8;
  union
  {
    hash_tyBM hash;
    uint32_t rlen;
  };
};
typedef struct typedhead_stBM typedhead_tyBM;
typedef struct typedhead_stBM typedintern_tyBM;

// types of garbage collected first-class values
enum gctyenum_BM
{
  tyInt_BM = -1,                /* actually a tagged int */
  tyNone_BM = 0,                /* e.g. for nil */
  tyString_BM = 1,              /* boxed strings */
  tySet_BM = 2,                 /* boxed set of objects */
  tyTuple_BM = 3,               /* boxed tuple of objects */
  tyNode_BM = 4,                /* boxed node */
  tyClosure_BM = 5,             /* boxed closure */
  tyObject_BM = 6,              /* boxed object */
  tyUnspecified_BM = 7,         /* the single unspecified value */
  ty_SpareA_BM = 8,
  ty_SpareB_BM = 9,
  ty_SpareC_BM = 10,
  ty_SpareD_BM = 11,
  ty_SpareE_BM = 12,
  ty_SpareF_BM = 13,
  ty_SpareG_BM = 14,
  ty_SpareH_BM = 15,
  ty_LAST_TYENUM_BM
};

// types of garbage collected data (non-first class)
enum gcdataenum_BM
{
  tydata_vectval_BM = ty_LAST_TYENUM_BM,
  tydata_assocbucket_BM,
  tydata_assocpairs_BM,
  tydata_hashsetobj_BM,
  tydata_listtop_BM,
  tydata_loader_BM,
  tydata_parser_BM,
  tydata_classinfo_BM,
  tydata_strbuffer_BM,
  tydata_dumper_BM,
  tydata_dict_BM,
  ///
  tydata_quasinode_BM,          // stack allocated!
  //
  tydata__SpareA_BM,
  tydata__SpareB_BM,
  tydata__SpareC_BM,
  tydata__SpareD_BM,
  tydata__SpareE_BM,
  tydata__SpareF_BM,
  tydata__SpareG_BM,
  tydata__SpareH_BM,
  tydata__SpareI_BM,
  tydata__SpareJ_BM,
  tydata__SpareK_BM,
  tydata__SpareL_BM,
  tydata__SpareM_BM,
  tydata__SpareN_BM,
  tydata__SpareO_BM,
  tydata__SpareP_BM,
  tydata__SpareQ_BM,
  tydata__SpareR_BM,
  tydata__SpareS_BM,
  tydata__SpareT_BM,
  tydata__SpareU_BM,
  tydata__SpareV_BM,
  tydata__SpareW_BM,
  tydata__SpareX_BM,
  tydata__SpareY_BM,
  tydata__SpareZ_BM,
  //
  tydata_SpecialFrame_BM = 0xfffe,
  tydata_StackFrame_BM = 0xffff
};

struct typedsize_stBM
{
  typedhead_tyBM pA;
  uint32_t size;
};
typedef struct typedsize_stBM typedsize_tyBM;

typedef uint64_t serial63_tyBM;

struct rawid_stBM
{
  serial63_tyBM id_hi;
  serial63_tyBM id_lo;
};
typedef struct rawid_stBM rawid_tyBM;

struct allalloc_stBM
{
  unsigned long al_size;        /* allocated size of al_ptr */
  unsigned long al_nb;          /* user number of al_ptr */
  void *al_ptr[];
};

struct stringval_stBM           /* the size field is the length in bytes */
{
  typedsize_tyBM pA;
  char strv_bytes[];
};
typedef struct stringval_stBM stringval_tyBM;   /*tyString_BM */

// forward
typedef struct object_stBM objectval_tyBM;      /*tyObject_BM */

struct seqobval_stBM
{
  typedsize_tyBM pA;
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
  LASTSPACE__BM
};

struct datavectval_stBM;        /*forward */
struct assocbucket_stBM;        /*forward */
struct assocpairs_stBM;         /*forward */
struct loader_stBM;             /* forward */
struct classinfo_stBM;          /* forward */
struct strbuffer_stBM;          /* forward */
struct dumper_stBM;             /* forward */
struct dict_stBM;               /* forward */

typedef void anyassoc_tyBM;


struct datavectval_stBM
{                               /* tydata_vectval_BM */
  typedsize_tyBM pA;            /// rlen is allocated size, siz is used length
  value_tyBM vec_data[];        // of rlen elements
};

struct strbuffer_stBM           /* for tydata_strbuffer_BM, in scalar.c */
{
  typedhead_tyBM pA;            // rlen is maximal length
  int sbuf_indent;              /* current indentation */
  char *sbuf_dbuf;              /* malloc-ed buffer */
  size_t sbuf_size;             /* malloc-ed size */
  char *sbuf_curp;              /* current position in the buffer, never nil */
  char *sbuf_lastnl;            /* last newline in buffer, or NULL if none */
};

struct assocbucket_stBM
{                               /* tydata_assocbucket_BM */
  typedsize_tyBM pA;
  // rlen is allocated length of abuck_pairs,
  // size is total count of entries
  struct assocpairs_stBM *abuck_pairs[];        // of rlen assocpairs
};

struct assocentry_stBM
{
  const objectval_tyBM *asso_keyob;
  value_tyBM asso_val;
};

struct assocpairs_stBM
{                               /* tydata_assocpairs_BM */
  typedsize_tyBM pa;            // rlen is allocated size, size is used count
  struct assocentry_stBM apairs_ent[];
};

struct hashsetobj_stBM
{                               /* tydata_hashsetobj_BM */
  typedsize_tyBM pa;            // rlen is allocated size, size is used count
  objectval_tyBM *hashset_objs[];
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
  objectval_tyBM *dump_object;
  const stringval_tyBM *dump_dir;
  struct hashsetobj_stBM *dump_hset;
  struct listtop_stBM *dump_scanlist;
  struct listtop_stBM *dump_todolist;
};

#define LINKSIZE_BM 14
struct listlink_stBM
{
  struct listlink_stBM *link_next;
  struct listlink_stBM *link_prev;
  value_tyBM link_mems[LINKSIZE_BM];
};

struct listtop_stBM
{                               // for  tydata_listtop_BM
  typedhead_tyBM pa;            // rlen is number of values in the list
  unsigned list_nblinks;        // number of struct listlink_stBM
  struct listlink_stBM *list_first;
  struct listlink_stBM *list_last;
};


struct nodetree_stBM
{                               // for tyNode_BM && tyClosure_BM
  typedsize_tyBM pA;            // size is the number of sons
  objectval_tyBM *nodt_conn;
  value_tyBM nodt_sons[];
};

typedef struct nodetree_stBM tree_tyBM; /* for tyClosure_BM or tyNode_BM or tydata_quasinode_BM */
typedef struct nodetree_stBM node_tyBM; /* for tyNode_BM */
typedef struct nodetree_stBM closure_tyBM;      /* for tyClosure_BM */
typedef struct nodetree_stBM quasinode_tyBM;    /* for tydata_quasinode_BM */


struct stackframe_stBM;

// the x86-64 ABI passes six arguments thru registers
typedef value_tyBM objrout_sigBM (const closure_tyBM * clos,
                                  struct stackframe_stBM *stkf,
                                  const value_tyBM arg1,
                                  const value_tyBM arg2,
                                  const value_tyBM arg3,
                                  const quasinode_tyBM * restargs);

struct object_stBM              /*tyObject_BM */
{
  typedhead_tyBM pA;
  rawid_tyBM ob_id;
  uint8_t ob_space;
  double ob_mtime;
  objectval_tyBM *ob_class;
  struct datavectval_stBM *ob_compvec;
  anyassoc_tyBM *ob_attrassoc;
  objrout_sigBM *ob_rout;
  value_tyBM ob_data;
};

struct stackframe_stBM
{                               // for tydata_StackFrame_BM, sitting on the callstack
  typedhead_tyBM stkfram_pA;    // rlen is the number of values
  struct stackframe_stBM *stkfram_prev;
  objectval_tyBM *stkfram_descr;
  int stkfram_state;
  int stkfram_xtra;
  value_tyBM stkfram_locals[];
};

// LOCALFRAME_BM is in cmacros_BM.h

struct specialframe_stBM;
struct garbcoll_stBM;
typedef void specialframe_marker_sigBM (struct garbcoll_stBM *,
                                        struct specialframe_stBM *);
struct specialframe_stBM        // for tydata_SpecialFrame_BM
{
  typedhead_tyBM pA;            // rlen is unused
  struct stackframe_stBM *specfram_prev;
  objectval_tyBM *specfram_descr;
  specialframe_marker_sigBM *specfram_markerout;
  intptr_t specfram_intp;
  void *specfram_cdata[];
};

struct loader_stBM              // malloc-ed then free-d at load time
{                               // for tydata_loader_BM
  typedhead_tyBM pa;            // rlen is unused
  unsigned ld_magic;            /* always LOADERMAGIC_BM */
  unsigned ld_maxnum;           /* highest number of store*.bismon files */
  struct hashsetobj_stBM *ld_objhset;   // hashset of loaded objects
  struct hashsetobj_stBM *ld_modhset;   // hashset of loaded module objects
  struct listtop_stBM *ld_todolist;
  // in the store arrays below, index 0 is for the store_todo
  char **ld_storepatharr;       /* calloc-ed array of malloc-ed string paths */
  long *ld_startoffarr;         /* calloc-ed array of offset of start */
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
#include "_bm_delim.h"
  delim__LAST
};                              /* end lexdelim_enBM */

// tokens are NOT garbage collected, but may contain a GC-ed value
struct parstoken_stBM
{
  enum parslexkind_enBM tok_kind;
  union
  {
    void *tok_ptrs[2];
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
// decorate the comment signs
typedef void parser_decorate_comment_sign_sigBM
  (struct parser_stBM *pars, unsigned colpos, unsigned signlen);
// decorate the comment inside
typedef void parser_decorate_comment_inside_sigBM
  (struct parser_stBM *pars, unsigned colpos, unsigned signlen);

// decorate the string signs
typedef void parser_decorate_string_sign_sigBM
  (struct parser_stBM *pars, unsigned colpos, unsigned signlen);
// decorate the string inside
typedef void parser_decorate_string_inside_sigBM
  (struct parser_stBM *pars, unsigned colpos, unsigned signlen);

// decorate numbers
typedef void parser_decorate_number_sigBM
  (struct parser_stBM *pars, unsigned colpos, unsigned numlen);

// decorate ids
typedef void parser_decorate_id_sigBM
  (struct parser_stBM *pars, unsigned colpos, unsigned idlen);

// decorate names, both known and unknown
typedef void parser_decorate_name_sigBM
  (struct parser_stBM *pars, unsigned colpos, unsigned namlen);

// decorate delimiters
typedef void parser_decorate_delimiter_sigBM
  (struct parser_stBM *pars, unsigned colpos, unsigned delimlen);

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

// signal parse error; the msg is a malloc-ed string which the routine
// should free when it is doing a longjmp
typedef void parser_error_sigBM
  (struct parser_stBM *pars, unsigned lineno, unsigned colpos, char *msg)
  /*__attribute__ ((noreturn))*/ ;


// not heap allocated, but constant and often in text segment
struct parserops_stBM
{
  const unsigned parsop_magic;  /* always PARSOPMAGIC_BM */
  const unsigned short parsop_serial;   /* some number, often unused */
  const bool parsop_nobuild;    /* if set, don't build any value */
  // error processing
  parser_error_sigBM *parsop_error_rout;
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

struct parser_stBM              /* for tydata_parser_BM */
{
  typedhead_tyBM pa;            // rlen is unused
  const struct parserops_stBM *pars_ops;
  FILE *pars_file;
  const char *pars_path;
  value_tyBM pars_cvalue;       /* client value */
  void *pars_xtradata;          /* extra client data */
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
};                              /* end struct parser_stBM */

struct dict_stBM
{
  typedhead_tyBM pa;
  uintptr_t dict_data[8];       /* actually a std::map */
};

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
  // start elapsed and cpu time
  double gc_startelapsedtime;
  double gc_startcputime;
};
#endif /*TYPES_BM_INCLUDED */
