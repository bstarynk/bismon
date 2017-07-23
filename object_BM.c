// file object_BM.c
#include "bismon.h"

#define HAS_PREDEF_BM(Id,Hi,Lo,Hash) objectval_tyBM predefdata##Id##_BM = { \
 .pA = (typedhead_tyBM){.htyp= tyObject_BM, .hgc=0, .hash= Hash}, \
 .ob_id = (rawid_tyBM){.id_hi= Hi, .id_lo= Lo}, \
 .ob_space = PredefSp_BM, \
  }; \
  objectval_tyBM* predefptr##Id##_BM = &predefdata##Id##_BM;

#include "_bm_predef.h"

// for qsort
static int
objptrqcmp_BM (const void *p1, const void *p2)
{
  return objectcmp_BM (*(const objectval_tyBM **) p1,
                       *(const objectval_tyBM **) p2);
}                               /* end objptrqcmp_BM */

void
sortobjarr_BM (const objectval_tyBM ** obarr, size_t arrsiz)
{
  if (obarr == NULL)
    arrsiz = 0;
  if (arrsiz > 1)
    qsort (obarr, arrsiz, sizeof (const objectval_tyBM *), objptrqcmp_BM);
}                               /* end sortobjarr_BM */



struct objbucket_stBM
{
  unsigned bucksize;            /* a prime number */
  unsigned buckcount;           // used count
  objectval_tyBM *buckobjs[];   // allocated size is bucksize
};

static struct objbucket_stBM *buckarr_BM[MAXBUCKETS_BM];


#define EMPTYSLOTOB_BM ((objectval_tyBM*)(-1))

extern objectval_tyBM *
findobjofid_BM (const rawid_tyBM id)
{
  if (!validid_BM (id))
    return NULL;
  unsigned bucknum = bucknumserial63_BM (id.id_hi);
  struct objbucket_stBM *curbuck = buckarr_BM[bucknum];
  if (!curbuck)
    return NULL;
  unsigned busiz = curbuck->bucksize;
  assert (busiz % 2 != 0 && busiz % 3 != 0 && busiz % 5 != 0);
  assert (curbuck->buckcount < curbuck->bucksize);
  hash_tyBM h = hashid_BM (id);
  unsigned startix = h % busiz;
  for (unsigned ix = startix; ix < busiz; ix++)
    {
      objectval_tyBM *curob = curbuck->buckobjs[ix];
      if (!curob)
        return NULL;
      if (curob == EMPTYSLOTOB_BM)
        continue;
      if (equalid_BM (curob->ob_id, id))
        return curob;
    };
  for (unsigned ix = 0; ix < startix; ix++)
    {
      objectval_tyBM *curob = curbuck->buckobjs[ix];
      if (!curob)
        return NULL;
      if (curob == EMPTYSLOTOB_BM)
        continue;
      if (equalid_BM (curob->ob_id, id))
        return curob;
    };
  return NULL;
}                               /* end of findobjofid_BM */

static void
addtobucket_BM (struct objbucket_stBM *buck, objectval_tyBM * ob)
{
  assert (buck != NULL);
  assert (valtype_BM (ob) == tyObject_BM);
  hash_tyBM h = objecthash_BM (ob);
  unsigned busiz = buck->bucksize;
  assert (busiz % 2 != 0 && busiz % 3 != 0 && busiz % 5 != 0);
  assert (buck->buckcount < buck->bucksize);
  unsigned startix = h % busiz;
  int pos = -1;
  for (unsigned ix = startix; ix < busiz; ix++)
    {
      objectval_tyBM *curob = buck->buckobjs[ix];
      if (!curob)
        {
          if (pos < 0)
            pos = (int) ix;
          break;
        }
      else if (curob == EMPTYSLOTOB_BM)
        {
          if (pos < 0)
            pos = (int) ix;
          continue;
        }
      else if (curob == ob)
        return;
    }
  for (unsigned ix = 0; ix < startix; ix++)
    {
      objectval_tyBM *curob = buck->buckobjs[ix];
      if (!curob)
        {
          if (pos < 0)
            pos = (int) ix;
          break;
        }
      else if (curob == EMPTYSLOTOB_BM)
        {
          if (pos < 0)
            pos = (int) ix;
          continue;
        }
      else if (curob == ob)
        return;
    }
  if (pos < 0)
    FATAL_BM ("corrupted object bucket@%p", buck);
  buck->buckobjs[pos] = ob;
  buck->buckcount++;
}                               /* end addtobucket_BM */

static void
growobucket_BM (unsigned bucknum, unsigned gap)
{
  assert (bucknum < MAXBUCKETS_BM);
  struct objbucket_stBM *oldbuck = buckarr_BM[bucknum];
  unsigned oldsiz = oldbuck ? oldbuck->bucksize : 0;
  unsigned oldcnt = oldbuck ? oldbuck->buckcount : 0;
  unsigned long newsiz =
    prime_above_BM (4 * (oldcnt + gap) / 3 + gap / 64 + 20);
  struct objbucket_stBM *newbuck =
    malloc (sizeof (struct objbucket_stBM) + newsiz * sizeof (void *));
  if (!newbuck)
    FATAL_BM ("out of memory for newbuck#%d of newsiz %lu", bucknum, newsiz);
  memset (newbuck, 0,
          sizeof (struct objbucket_stBM) + newsiz * sizeof (void *));
  newbuck->bucksize = newsiz;
  newbuck->buckcount = 0;
  for (unsigned oix = 0; oix < oldsiz; oix++)
    {
      objectval_tyBM *oldob = oldbuck->buckobjs[oix];
      if (!oldob || oldob == EMPTYSLOTOB_BM)
        continue;
      addtobucket_BM (newbuck, oldob);
    }
  free (oldbuck);
  buckarr_BM[bucknum] = newbuck;
}                               /* end growobucket_BM */


extern objectval_tyBM *
makeobjofid_BM (const rawid_tyBM id)
{
  if (!validid_BM (id))
    return NULL;
  objectval_tyBM *pob = findobjofid_BM (id);
  if (pob)
    return pob;
  unsigned bucknum = bucknumserial63_BM (id.id_hi);
  struct objbucket_stBM *curbuck = buckarr_BM[bucknum];
  unsigned oldsiz = curbuck ? curbuck->bucksize : 0;
  unsigned oldcnt = curbuck ? curbuck->buckcount : 0;
  if (!curbuck || 4 * oldcnt + 5 > 3 * oldsiz)
    {
      growobucket_BM (bucknum, 6);
      curbuck = buckarr_BM[bucknum];
      assert (curbuck);
    }
  pob = allocgcty_BM (tyObject_BM, sizeof (objectval_tyBM));
  pob->ob_id = id;
  addtobucket_BM (curbuck, pob);
  return pob;
}                               /* end of makeobjofid_BM */

extern objectval_tyBM *
makeobj_BM (void)
{
  for (;;)
    {
      rawid_tyBM id = randomid_BM ();
      objectval_tyBM *pob = findobjofid_BM (id);
      if (pob)
        continue;
      return makeobjofid_BM (id);
    }
}                               /* end of makeobj_BM */

static void
register_predefined_object_BM (objectval_tyBM * pob)
{
  assert (valtype_BM ((const value_tyBM) pob) == tyObject_BM);
  assert (findobjofid_BM (pob->ob_id) == NULL);
  unsigned bucknum = bucknumserial63_BM (pob->ob_id.id_hi);
  growobucket_BM (bucknum, 6);
  struct objbucket_stBM *curbuck = buckarr_BM[bucknum];
  assert (curbuck != NULL);
  addtobucket_BM (curbuck, pob);
}                               /* end register_predefined_object_BM */

void
initialize_predefined_objects_BM (void)
{
#define HAS_PREDEF_BM(Id,Hi,Lo,Hash) \
  register_predefined_object_BM(PREDEF_BM(Id));
#include "_bm_predef.h"
}                               /* end initialize_predefined_objects_BM */
