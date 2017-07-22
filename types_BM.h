// file types_BM.h
#ifndef TYPES_BM_INCLUDED
#define TYPES_BM_INCLUDED

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
typedef struct stringval_stBM stringval_tyBM;

// forward
typedef struct object_stBM objectval_tyBM;

struct seqobval_stBM
{
  typedsize_tyBM pA;
  objectval_tyBM *seq_objs[];
};

typedef struct seqobval_stBM seqobval_tyBM;
typedef struct seqobval_stBM tupleval_tyBM;
typedef struct seqobval_stBM setval_tyBM;

struct object_stBM
{
  typedhead_tyBM pA;
  rawid_tyBM ob_id;
  // other fields are missing
};


// types of garbage collected values
enum gctyenum_BM
{
  tyInt_BM = -1,                /* actually a tagged int */
  tyNone_BM = 0,                /* e.g. for nil */
  tyString_BM = 1,
  tySet_BM = 2,
  tyTuple_BM = 3,
  tyNode_BM = 4,
  tyClosure_BM = 5,
  tyObject_BM = 6,
};
#endif /*TYPES_BM_INCLUDED */
