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
  ty_LAST_TYENUM_BM
};

// types of garbage collected data (non-first class)
enum gcdataenum_BM
{
  tydata_vectval_BM = ty_LAST_TYENUM_BM,
  tydata_assocbucket_BM,
  tydata_assocpairs_BM,
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
  objectval_tyBM *seq_objs[];
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

struct datavectval_BM;          /*forward */
struct assocbucket_BM;          /*forward */
struct assocpairs_BM;           /*forward */

typedef void anyassoc_tyBM;

struct object_stBM              /*tyObject_BM */
{
  typedhead_tyBM pA;
  rawid_tyBM ob_id;
  uint8_t ob_space;
  struct datavectval_BM *ob_compvec;
  anyassoc_tyBM *ob_attrassoc;
  // other fields are missing
};

struct datavectval_BM
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
  objectval_tyBM *asso_keyob;
  value_tyBM asso_val;
};

struct assocpairs_stBM
{                               /* tydata_assocpairs_BM */
  typedsize_tyBM pa;            // rlen is allocated size, size is used count
  struct assocentry_stBM apairs_ent[];
};
#endif /*TYPES_BM_INCLUDED */
