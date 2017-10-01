// file sequence_BM.c
#include "bismon.h"


//// tuple support

const tupleval_tyBM *
maketuple_BM (objectval_tyBM ** arr, unsigned rawsiz)
{
  if (!arr)
    rawsiz = 0;
  if (rawsiz > MAXSIZE_BM)
    FATAL_BM ("maketuple too wide %ld raw array", (long) rawsiz);
  unsigned siz = 0;
  for (unsigned ix = 0; ix < rawsiz; ix++)
    if (arr[ix])
      siz++;
  unsigned long tupsiz = sizeof (tupleval_tyBM) + ((siz > 0)    //
                                                   ? (prime_above_BM (siz - 1)
                                                      *
                                                      sizeof (objectval_tyBM
                                                              *)) : 0);
  assert (tupsiz < (4L * MAXSIZE_BM / 3 + 5L) * sizeof (void *));
  tupleval_tyBM *tup =          //
    allocgcty_BM (tyTuple_BM, tupsiz);
  unsigned cnt = 0;
  hash_tyBM h1 = 0, h2 = siz;
  for (unsigned ix = 0; ix < rawsiz; ix++)
    if (arr[ix])
      {
        const objectval_tyBM *curob = arr[ix];
        hash_tyBM curhash = objecthash_BM (curob);
        if (curhash == 0)
          FATAL_BM ("invalid object#%d in tuple", ix);
        if (cnt % 2 == 0)
          h1 = (121453 * h1 + ix + 17) ^ (curhash * 5483);
        else
          h2 = (421973 * h2) ^ (curhash * 8971 - 7 * ix);
        tup->seq_objs[cnt++] = (objectval_tyBM *) curob;
      };
  hash_tyBM h = h1 ^ h2;
  if (!h)                       /* so h1 == h2 */
    h = (h1 & 0xffffff) + (h2 % 138571) + 3 * (siz & 0xffff) + 35;
  assert (h > 0);
  ((typedsize_tyBM *) tup)->size = siz;
  ((typedhead_tyBM *) tup)->hash = h;
  return tup;
}                               /* end maketuple_BM */

void
tuplegcdestroy_BM (struct garbcoll_stBM *gc, tupleval_tyBM * tup)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) tup)->htyp == tyTuple_BM);
  unsigned siz = ((typedsize_tyBM *) tup)->size;
  assert (siz < MAXSIZE_BM);
  unsigned long tupsiz = sizeof (tupleval_tyBM) + ((siz > 0)    //
                                                   ? (prime_above_BM (siz - 1)
                                                      *
                                                      sizeof (objectval_tyBM
                                                              *)) : 0);
  assert (tupsiz < (4L * MAXSIZE_BM / 3 + 5L) * sizeof (void *));
  memset (tup, 0, sizeof (*tup) + siz * sizeof (void *));
  free (tup);
  gc->gc_freedbytes += tupsiz;
}                               /* end tuplegcdestroy_BM */

void
tuplegckeep_BM (struct garbcoll_stBM *gc, tupleval_tyBM * tup)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) tup)->htyp == tyTuple_BM);
  unsigned siz = ((typedsize_tyBM *) tup)->size;
  assert (siz < MAXSIZE_BM);
  unsigned long tupsiz = sizeof (tupleval_tyBM) + ((siz > 0)    //
                                                   ? (prime_above_BM (siz - 1)
                                                      *
                                                      sizeof (objectval_tyBM
                                                              *)) : 0);
  assert (tupsiz < (4L * MAXSIZE_BM / 3 + 5L) * sizeof (void *));
  gc->gc_keptbytes += tupsiz;
}                               /* end tuplegckeep_BM */

unsigned
tuplesize_BM (const tupleval_tyBM * tup)
{
  if (!tup || ((intptr_t) tup & 3))
    return 0;
  if (((typedhead_tyBM *) tup)->htyp != tyTuple_BM)
    return 0;
  return ((typedsize_tyBM *) tup)->size;
}                               /* end tuplesize_BM */

objectval_tyBM *
tuplecompnth_BM (const tupleval_tyBM * tup, int rk)
{
  if (!tup || ((intptr_t) tup & 3))
    return NULL;
  if (((typedhead_tyBM *) tup)->htyp != tyTuple_BM)
    return NULL;
  unsigned siz = ((typedsize_tyBM *) tup)->size;
  if (rk < 0)
    rk += siz;
  if (rk < 0 || rk >= (int) siz)
    return NULL;
  return (objectval_tyBM *) tup->seq_objs[rk];
}                               /* end tuplecompnth_BM */

void
tuplegcmark_BM (struct garbcoll_stBM *gc, tupleval_tyBM * tup)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (valtype_BM ((const value_tyBM) tup) == tyTuple_BM);
  uint8_t oldmark = ((typedhead_tyBM *) tup)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) tup)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  unsigned siz = ((typedsize_tyBM *) tup)->size;
  for (unsigned ix = 0; ix < siz; ix++)
    gcobjmark_BM (gc, (objectval_tyBM *) tup->seq_objs[ix]);
}                               /* end tuplegcmark_BM */

////////////////////////////////////////////////////////////////
///// set support

extern const setval_tyBM *
makeset_BM (const objectval_tyBM ** arr, unsigned rawsiz)
{
  const objectval_tyBM *tinyarr[TINYSIZE_BM];
  const objectval_tyBM **tmparr = NULL;
  memset (tinyarr, 0, sizeof (tinyarr));
  if (!arr)
    rawsiz = 0;
  if (rawsiz > MAXSIZE_BM)
    FATAL_BM ("makeset too wide %ld raw array", (long) rawsiz);
  unsigned siz = 0;
  for (unsigned ix = 0; ix < rawsiz; ix++)
    if (arr[ix])
      {
        siz++;
      };
  if (siz > MAXSIZE_BM)
    FATAL_BM ("makeset too big size %u", siz);
  if (siz < TINYSIZE_BM)
    tmparr = tinyarr;
  else
    tmparr = calloc (siz + 1, sizeof (void *));
  if (!tmparr)
    FATAL_BM ("makeset cannot allocate tmparr siz=%u", siz);
  unsigned cnt = 0;
  for (unsigned ix = 0; ix < rawsiz; ix++)
    if (arr[ix])
      tmparr[cnt++] = arr[ix];
  assert (cnt == siz);
  sortobjarr_BM ((const objectval_tyBM **) tmparr, siz);
  int nbdup = 0;
  setval_tyBM *set = NULL;
  for (unsigned nix = 1; nix < siz; nix++)
    if (tmparr[nix] == tmparr[nix - 1])
      nbdup++;
  if (nbdup > 0)
    {
      assert (nbdup < (int) siz);
      unsigned dupsiz = siz;
      siz = dupsiz - nbdup;
      assert (siz < MAXSIZE_BM);
      unsigned long setsiz = sizeof (setval_tyBM) +     //
        ((siz > 0)
         ? ((prime_above_BM (siz - 1) * sizeof (objectval_tyBM *))) : 0);
      assert (setsiz < ((4L * MAXSIZE_BM) / 3 + 5L) * sizeof (void *));
      set =                     //
        allocgcty_BM (tySet_BM, setsiz);
      set->seq_objs[0] = tmparr[0];
      unsigned cnt = 1;
      for (unsigned dix = 1; dix < dupsiz; dix++)
        {
          if (tmparr[dix] != set->seq_objs[cnt - 1])
            set->seq_objs[cnt++] = tmparr[dix];
        }
      assert (cnt == siz);
    }
  else                          // nbdup == 0
    {
      assert (siz < MAXSIZE_BM);
      unsigned long setsiz = sizeof (setval_tyBM) +     //
        ((siz > 0)
         ? ((prime_above_BM (siz - 1) * sizeof (objectval_tyBM *))) : 0);
      assert (setsiz < ((4L * MAXSIZE_BM) / 3 + 5L) * sizeof (void *));
      set =                     //
        allocgcty_BM (tySet_BM, setsiz);
      memcpy (set->seq_objs, tmparr, siz * sizeof (objectval_tyBM *));
    };
  ((typedsize_tyBM *) set)->size = siz;
  // compute the hash
  hash_tyBM h1 = 31 + siz / 3, h2 = 5 + siz, h = 0;
  for (unsigned ix = 0; ix < siz; ix++)
    {
      const objectval_tyBM *curob = set->seq_objs[ix];
      hash_tyBM curhash = objecthash_BM (curob);
      if (curhash == 0)
        FATAL_BM ("invalid object#%d in set", ix);
      if (ix % 2 == 0)
        h1 = (156707 * h1 - 19 * ix + 180) ^ (curhash * 6337);
      else
        h2 = (363179 * h2) ^ (curhash * 12433 - 13 * ix);
    }
  h = h1 ^ (h2 * 31 - siz);
  if (!h)
    h = (h1 & 0xffffff) + 3 * (h2 % 138599) + 11 * (siz & 0xffff) + 59;
  assert (h > 0);
  ((typedhead_tyBM *) set)->hash = h;
  return set;
}                               /* end makeset_BM */

void
setgcdestroy_BM (struct garbcoll_stBM *gc, setval_tyBM * set)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) set)->htyp == tySet_BM);
  unsigned siz = ((typedsize_tyBM *) set)->size;
  assert (siz < MAXSIZE_BM);
  unsigned long setsiz = sizeof (setval_tyBM) + //
    ((siz > 0)
     ? ((prime_above_BM (siz - 1) * sizeof (objectval_tyBM *))) : 0);
  assert (setsiz < ((4L * MAXSIZE_BM) / 3 + 5L) * sizeof (void *));
  memset (set, 0, sizeof (*set) + siz * sizeof (void *));
  free (set);
  gc->gc_freedbytes += setsiz;
}                               /* end setgcdestroy_BM */

void
setgckeep_BM (struct garbcoll_stBM *gc, setval_tyBM * set)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) set)->htyp == tySet_BM);
  unsigned siz = ((typedsize_tyBM *) set)->size;
  assert (siz < MAXSIZE_BM);
  unsigned long setsiz = sizeof (setval_tyBM) + //
    ((siz > 0)
     ? ((prime_above_BM (siz - 1) * sizeof (objectval_tyBM *))) : 0);
  assert (setsiz < ((4L * MAXSIZE_BM) / 3 + 5L) * sizeof (void *));
  gc->gc_keptbytes += setsiz;
}                               /* end setgckeep_BM */

int
setelemindex_BM (const setval_tyBM * setv, const objectval_tyBM * obelem)
{
  if (!isset_BM ((const value_tyBM) setv)
      || !isobject_BM ((const value_tyBM) obelem))
    return -1;
  unsigned card = ((typedsize_tyBM *) setv)->size;
  unsigned lo = 0, hi = card, md = 0;
  while (lo + 15 < hi)
    {
      md = (lo + hi) / 2;
      const objectval_tyBM *mdob = setv->seq_objs[md];
      assert (mdob != NULL && ((typedhead_tyBM *) mdob)->htyp == tyObject_BM);
      if (obelem == mdob)
        return true;
      int cmp = objectcmp_BM (obelem, mdob);
      if (cmp < 0)
        hi = md;
      else
        {
          assert (cmp > 0);
          lo = md;
        }
    };
  for (md = lo; md < hi; md++)
    {
      const objectval_tyBM *mdob = setv->seq_objs[md];
      assert (mdob != NULL && ((typedhead_tyBM *) mdob)->htyp == tyObject_BM);
      if (obelem == mdob)
        return md;
    }
  return -1;
}                               /* end setelemindex_BM */

unsigned
setcardinal_BM (const setval_tyBM * setv)
{
  if (!isset_BM ((const value_tyBM) setv))
    return 0;
  return ((typedsize_tyBM *) setv)->size;
}                               /* end setcardinal_BM */

objectval_tyBM *
setelemnth_BM (const setval_tyBM * set, int rk)
{
  if (!set || ((intptr_t) set & 3))
    return NULL;
  if (((typedhead_tyBM *) set)->htyp != tySet_BM)
    return NULL;
  unsigned siz = ((typedsize_tyBM *) set)->size;
  if (rk < 0)
    rk += siz;
  if (rk < 0 || rk >= (int) siz)
    return NULL;
  return (objectval_tyBM *) set->seq_objs[rk];
}                               /* end setelemnth_BM */

unsigned
sequencesize_BM (const seqobval_tyBM * sq)
{
  if (!issequence_BM ((const value_tyBM) sq))
    return 0;
  return ((typedsize_tyBM *) sq)->size;
}                               /* end sequencesize_BM */

objectval_tyBM *
sequencenthcomp_BM (const seqobval_tyBM * sq, int rk)
{
  if (!issequence_BM ((const value_tyBM) sq))
    return NULL;
  unsigned siz = ((typedsize_tyBM *) sq)->size;
  if (rk < 0)
    rk += siz;
  if (rk >= 0 && rk < (int) siz)
    return (objectval_tyBM *) sq->seq_objs[rk];
  return NULL;
}                               /* end sequencenthcomp_BM */

void
setgcmark_BM (struct garbcoll_stBM *gc, setval_tyBM * set)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (valtype_BM ((const value_tyBM) set) == tySet_BM);
  uint8_t oldmark = ((typedhead_tyBM *) set)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) set)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  unsigned siz = ((typedsize_tyBM *) set)->size;
  for (unsigned ix = 0; ix < siz; ix++)
    gcobjmark_BM (gc, (objectval_tyBM *) set->seq_objs[ix]);
}                               /* end setgcmark_BM */


////////////////////////////////////////////////////////////////

struct datavectval_stBM *
datavect_grow_BM (struct datavectval_stBM *dvec, unsigned gap)
{
  if (valtype_BM ((const value_tyBM) dvec) != tydata_vectval_BM)
    {
      unsigned siz = prime_above_BM (gap);
      dvec =
        allocgcty_BM (tydata_vectval_BM,
                      sizeof (struct datavectval_stBM)
                      + siz * sizeof (void *));
      ((typedhead_tyBM *) dvec)->rlen = siz;
      ((typedsize_tyBM *) dvec)->size = gap;
      return dvec;
    }
  unsigned oldlen = ((typedhead_tyBM *) dvec)->rlen;
  unsigned oldcnt = ((typedsize_tyBM *) dvec)->size;
  if (oldcnt + gap <= oldlen)
    return dvec;
  unsigned long siz = prime_above_BM (oldlen + gap);
  if (siz > MAXSIZE_BM)
    FATAL_BM ("too big datavect %ld", siz);
  unsigned long vecsiz =
    sizeof (struct datavectval_stBM) + siz * sizeof (void *);
  assert (vecsiz < ((4L * MAXSIZE_BM / 3) + 5L) * sizeof (void *));
  struct datavectval_stBM *newdvec =    //
    allocgcty_BM (tydata_vectval_BM, vecsiz);
  ((typedhead_tyBM *) newdvec)->rlen = siz;
  ((typedsize_tyBM *) newdvec)->size = oldcnt + gap;
  memcpy (newdvec->vec_data, dvec->vec_data, oldcnt * sizeof (void *));
  free (dvec);
  return newdvec;
}                               /* end of datavect_grow_BM */

void
datavectgcdestroy_BM (struct garbcoll_stBM *gc, struct datavectval_stBM *dvec)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) dvec)->htyp == tydata_vectval_BM);
  unsigned siz = ((typedhead_tyBM *) dvec)->rlen;
  assert (siz < MAXSIZE_BM);
  unsigned long vecsiz =
    sizeof (struct datavectval_stBM) + siz * sizeof (void *);
  assert (vecsiz < ((4L * MAXSIZE_BM / 3) + 5L) * sizeof (void *));
  memset (dvec, 0, sizeof (*dvec) + siz * sizeof (void *));
  free (dvec);
  gc->gc_freedbytes += vecsiz;
}                               /* end datavectgcdestroy_BM */


void
datavectgckeep_BM (struct garbcoll_stBM *gc, struct datavectval_stBM *dvec)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) dvec)->htyp == tydata_vectval_BM);
  unsigned siz = ((typedhead_tyBM *) dvec)->rlen;
  assert (siz < MAXSIZE_BM);
  unsigned long vecsiz =
    sizeof (struct datavectval_stBM) + siz * sizeof (void *);
  assert (vecsiz < ((4L * MAXSIZE_BM / 3) + 5L) * sizeof (void *));
  gc->gc_keptbytes += vecsiz;
}                               /* end datavectgckeep_BM */


struct datavectval_stBM *
datavect_reserve_BM (struct datavectval_stBM *dvec, unsigned gap)
{
  if (valtype_BM ((const value_tyBM) dvec) != tydata_vectval_BM)
    {
      unsigned siz = prime_above_BM (gap);
      dvec =
        allocgcty_BM (tydata_vectval_BM,
                      sizeof (struct datavectval_stBM)
                      + siz * sizeof (void *));
      ((typedhead_tyBM *) dvec)->rlen = siz;
      return dvec;
    }
  unsigned oldlen = ((typedhead_tyBM *) dvec)->rlen;
  unsigned oldcnt = ((typedsize_tyBM *) dvec)->size;
  if (oldcnt + gap <= oldlen)
    return dvec;
  unsigned long siz = prime_above_BM (oldlen + gap);
  if (siz > MAXSIZE_BM)
    FATAL_BM ("too big datavect %ld", siz);
  unsigned long vecsiz = sizeof (*dvec) + siz * sizeof (void *);
  assert (vecsiz < ((4L * MAXSIZE_BM / 3) + 5L) * sizeof (void *));
  struct datavectval_stBM *newdvec =    //
    allocgcty_BM (tydata_vectval_BM, vecsiz);
  ((typedhead_tyBM *) newdvec)->rlen = siz;
  ((typedsize_tyBM *) newdvec)->size = oldcnt;
  memcpy (newdvec->vec_data, dvec->vec_data, oldcnt * sizeof (void *));
  free (dvec);
  return newdvec;
}                               /* end of datavect_reserve_BM */

struct datavectval_stBM *
datavect_append_BM (struct datavectval_stBM *dvec, value_tyBM val)
{
  if (valtype_BM ((const value_tyBM) dvec) != tydata_vectval_BM)
    {
      unsigned siz = TINYSIZE_BM / 2;
      dvec =
        allocgcty_BM (tydata_vectval_BM,
                      sizeof (struct datavectval_stBM)
                      + siz * sizeof (void *));
      ((typedhead_tyBM *) dvec)->rlen = siz;
      ((typedsize_tyBM *) dvec)->size = 1;
      dvec->vec_data[0] = val;
      return dvec;
    }
  unsigned oldlen = ((typedhead_tyBM *) dvec)->rlen;
  unsigned oldcnt = ((typedsize_tyBM *) dvec)->size;
  if (oldcnt + 1 <= oldlen)
    {
      dvec->vec_data[oldcnt] = val;
      ((typedsize_tyBM *) dvec)->size = oldcnt + 1;
      return dvec;
    }
  if (oldlen + 1 >= MAXSIZE_BM)
    FATAL_BM ("datavect_append too big %u", oldlen);
  unsigned newsiz = prime_above_BM (oldlen + oldcnt / 16 + 3);
  struct datavectval_stBM *newdvec =    //
    allocgcty_BM (tydata_vectval_BM,
                  sizeof (struct datavectval_stBM)
                  + newsiz * sizeof (void *));
  ((typedhead_tyBM *) newdvec)->rlen = newsiz;
  ((typedsize_tyBM *) newdvec)->size = oldcnt + 1;
  memcpy (newdvec->vec_data, dvec->vec_data, oldcnt * sizeof (void *));
  newdvec->vec_data[oldcnt] = val;
  free (dvec);
  return newdvec;
}                               /* end datavect_append_BM */


const node_tyBM *
datavect_to_node_BM (struct datavectval_stBM *dvec,
                     const objectval_tyBM * obconn)
{
  if (valtype_BM ((const value_tyBM) dvec) != tydata_vectval_BM)
    return NULL;
  if (!isobject_BM ((const value_tyBM) obconn))
    return NULL;
  unsigned cnt = ((typedsize_tyBM *) dvec)->size;
  const value_tyBM *valarr = dvec->vec_data;
  return makenode_BM (obconn, cnt, valarr);
}                               /* end datavect_to_node_BM */


void
datavectgcmark_BM (struct garbcoll_stBM *gc,
                   const struct datavectval_stBM *dvec, int depth)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (valtype_BM ((const value_tyBM) dvec) == tydata_vectval_BM);
  uint8_t oldmark = ((typedhead_tyBM *) dvec)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) dvec)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  unsigned dlen = ((typedhead_tyBM *) dvec)->rlen;
  unsigned dcnt = ((typedsize_tyBM *) dvec)->size;
  assert (dcnt <= dlen);
  for (unsigned ix = 0; ix < dcnt; ix++)
    gcmark_BM (gc, dvec->vec_data[ix], depth + 1);
}                               /* end datavectgcmark_BM  */
