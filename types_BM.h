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

struct stringval_stBM
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
  UserFsp_BM = 8,
  UserGsp_BM = 9,
};

struct datavectval_stBM;        /*forward */
struct assocbucket_stBM;        /*forward */
struct assocpairs_stBM;         /*forward */
struct loader_stBM;             /* forward */

typedef void anyassoc_tyBM;

struct object_stBM              /*tyObject_BM */
{
  typedhead_tyBM pA;
  rawid_tyBM ob_id;
  uint8_t ob_space;
  double ob_mtime;
  struct datavectval_stBM *ob_compvec;
  anyassoc_tyBM *ob_attrassoc;
  // other fields are missing
};

struct datavectval_stBM
{                               /* tydata_vectval_BM */
  typedsize_tyBM pA;            /// rlen is allocated size, siz is used length
  value_tyBM vec_data[];        // of rlen elements
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
  struct listlink_stBM *list_first;
  struct listlink_stBM *list_last;
};


struct nodetree_stBM
{                               // for tyNode_BM && tyClosure_BM
  typedsize_tyBM pA;            // size is the number of sons
  objectval_tyBM *nodt_conn;
  value_tyBM nodt_sons[];
};

typedef struct nodetree_stBM tree_tyBM; /* for tyClosure_BM or tyNode_BM */
typedef struct nodetree_stBM node_tyBM; /* for tyNode_BM */
typedef struct nodetree_stBM closure_tyBM;      /* for tyClosure_BM */

struct stackframe_stBM
{                               // for tydata_StackFrame_BM, sitting on the callstack
  typedsize_tyBM pA;            // size is the number of values
  struct stackframe_stBM *stkfram_next;
  objectval_tyBM *stkfram_descr;
  int stkfram_state;
  int stkfram_xtra;
  value_tyBM stkfram_locals[];
};

struct specialframe_stBM;
struct garbcoll_stBM;
typedef void specialframe_marker_sigBM (struct garbcoll_stBM *,
                                        struct specialframe_stBM *);
struct specialframe_stBM        // for tydata_SpecialFrame_BM
{
  typedsize_tyBM pA;            // size is unused
  struct stackframe_stBM *specfram_next;
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
  struct hashsetobj_stBM *ld_hset;      // hashset of objects by id
  char **ld_storepatharr;       /* calloc-ed array of malloc-ed string paths */
  char *ld_todopath;            // malloc-ed path of store_todo.bismon
  char *ld_dir;                 /* malloc-ed directory path */
};                              /* end loader_stBM */

struct garbcoll_stBM
{
  uint32_t gc_magic;
  uint32_t gc_spareunsigned;
  // the list of objects to be scanned
  struct listtop_stBM *gc_scanlist;
  // the hashset of objects added into previous list
  struct hashsetobj_stBM *gc_hset;
};
#endif /*TYPES_BM_INCLUDED */
