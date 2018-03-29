// file sequence_BM.c

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
  ASSERT_BM (siz < MAXSIZE_BM);
  unsigned long tupsiz =        //
    sizeof (tupleval_tyBM)      //
    + ((siz > 0)                //
       ? (prime_above_BM (siz - 1) * sizeof (objectval_tyBM *)) : 0);
  ASSERT_BM (tupsiz < (4L * MAXSIZE_BM / 3 + 5L) * sizeof (void *));
  tupleval_tyBM *tup =          //
    allocgcty_BM (tyTuple_BM, tupsiz);
  unsigned cnt = 0;
  hash_tyBM h1 = 0, h2 = siz;
  for (unsigned ix = 0; ix < rawsiz; ix++)
    if (arr[ix])
      {
        const objectval_tyBM *curob = arr[ix];
        if (!isobject_BM (curob))
          continue;
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
  ASSERT_BM (h > 0);
  ((typedsize_tyBM *) tup)->size = siz;
  ((typedhead_tyBM *) tup)->hash = h;
  return tup;
}                               /* end maketuple_BM */

void
tuplegcdestroy_BM (struct garbcoll_stBM *gc, tupleval_tyBM * tup)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) tup)->htyp == tyTuple_BM);
  unsigned siz = ((typedsize_tyBM *) tup)->size;
  ASSERT_BM (siz < MAXSIZE_BM);
  unsigned long tupsiz = sizeof (tupleval_tyBM) + ((siz > 0)    //
                                                   ? (prime_above_BM (siz - 1)
                                                      *
                                                      sizeof (objectval_tyBM
                                                              *)) : 0);
  ASSERT_BM (tupsiz < (4L * MAXSIZE_BM / 3 + 5L) * sizeof (void *));
  memset (tup, 0, sizeof (*tup) + siz * sizeof (void *));
  free (tup);
  gc->gc_freedbytes += tupsiz;
}                               /* end tuplegcdestroy_BM */

void
tuplegckeep_BM (struct garbcoll_stBM *gc, tupleval_tyBM * tup)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) tup)->htyp == tyTuple_BM);
  unsigned siz = ((typedsize_tyBM *) tup)->size;
  ASSERT_BM (siz < MAXSIZE_BM);
  unsigned long tupsiz = sizeof (tupleval_tyBM) + ((siz > 0)    //
                                                   ? (prime_above_BM (siz - 1)
                                                      *
                                                      sizeof (objectval_tyBM
                                                              *)) : 0);
  ASSERT_BM (tupsiz < (4L * MAXSIZE_BM / 3 + 5L) * sizeof (void *));
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

void *
tuplegcproc_BM (struct garbcoll_stBM *gc, tupleval_tyBM * tup)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((const value_tyBM) tup) == tyTuple_BM);
#warning tuplegcproc_BM should forward
  uint8_t oldmark = ((typedhead_tyBM *) tup)->hgc;
  if (oldmark)
    return tup;
  ((typedhead_tyBM *) tup)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  unsigned siz = ((typedsize_tyBM *) tup)->size;
  for (unsigned ix = 0; ix < siz; ix++)
    gcobjmark_BM (gc, (objectval_tyBM *) tup->seq_objs[ix]);
  return tup;
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
        if (!isobject_BM (arr[ix]))
          continue;
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
    if (isobject_BM (arr[ix]))
      tmparr[cnt++] = arr[ix];
  ASSERT_BM (cnt == siz);
  sortobjarr_BM ((objectval_tyBM **) tmparr, siz);
  int nbdup = 0;
  setval_tyBM *set = NULL;
  for (unsigned nix = 1; nix < siz; nix++)
    if (tmparr[nix] == tmparr[nix - 1])
      nbdup++;
  if (nbdup > 0)
    {
      ASSERT_BM (nbdup < (int) siz);
      unsigned dupsiz = siz;
      siz = dupsiz - nbdup;
      ASSERT_BM (siz < MAXSIZE_BM);
      unsigned long setsiz = sizeof (setval_tyBM) +     //
        ((siz > 0)
         ? ((prime_above_BM (siz - 1) * sizeof (objectval_tyBM *))) : 0);
      ASSERT_BM (setsiz < ((4L * MAXSIZE_BM) / 3 + 5L) * sizeof (void *));
      set =                     //
        allocgcty_BM (tySet_BM, setsiz);
      set->seq_objs[0] = tmparr[0];
      unsigned cnt = 1;
      for (unsigned dix = 1; dix < dupsiz; dix++)
        {
          if (tmparr[dix] != set->seq_objs[cnt - 1])
            set->seq_objs[cnt++] = tmparr[dix];
        }
      ASSERT_BM (cnt == siz);
    }
  else                          // nbdup == 0
    {
      ASSERT_BM (siz < MAXSIZE_BM);
      unsigned long setsiz = sizeof (setval_tyBM) +     //
        ((siz > 0)
         ? ((prime_above_BM (siz - 1) * sizeof (objectval_tyBM *))) : 0);
      ASSERT_BM (setsiz < ((4L * MAXSIZE_BM) / 3 + 5L) * sizeof (void *));
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
  ASSERT_BM (h > 0);
  ((typedhead_tyBM *) set)->hash = h;
  return set;
}                               /* end makeset_BM */

void
setgcdestroy_BM (struct garbcoll_stBM *gc, setval_tyBM * set)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) set)->htyp == tySet_BM);
  unsigned siz = ((typedsize_tyBM *) set)->size;
  ASSERT_BM (siz < MAXSIZE_BM);
  unsigned long setsiz = sizeof (setval_tyBM) + //
    ((siz > 0)
     ? ((prime_above_BM (siz - 1) * sizeof (objectval_tyBM *))) : 0);
  ASSERT_BM (setsiz < ((4L * MAXSIZE_BM) / 3 + 5L) * sizeof (void *));
  memset (set, 0, sizeof (*set) + siz * sizeof (void *));
  free (set);
  gc->gc_freedbytes += setsiz;
}                               /* end setgcdestroy_BM */

void
setgckeep_BM (struct garbcoll_stBM *gc, setval_tyBM * set)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) set)->htyp == tySet_BM);
  unsigned siz = ((typedsize_tyBM *) set)->size;
  ASSERT_BM (siz < MAXSIZE_BM);
  unsigned long setsiz = sizeof (setval_tyBM) + //
    ((siz > 0)
     ? ((prime_above_BM (siz - 1) * sizeof (objectval_tyBM *))) : 0);
  ASSERT_BM (setsiz < ((4L * MAXSIZE_BM) / 3 + 5L) * sizeof (void *));
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
      ASSERT_BM (mdob != NULL
                 && ((typedhead_tyBM *) mdob)->htyp == tyObject_BM);
      if (obelem == mdob)
        return true;
      int cmp = objectcmp_BM (obelem, mdob);
      if (cmp < 0)
        hi = md;
      else
        {
          ASSERT_BM (cmp > 0);
          lo = md;
        }
    };
  for (md = lo; md < hi; md++)
    {
      const objectval_tyBM *mdob = setv->seq_objs[md];
      ASSERT_BM (mdob != NULL
                 && ((typedhead_tyBM *) mdob)->htyp == tyObject_BM);
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

const tupleval_tyBM *
settonamedsortedtuple_BM (const setval_tyBM * setv)
{
  const tupleval_tyBM *tup = NULL;
  if (!setv || ((intptr_t) setv & 3))
    return NULL;
  if (((typedhead_tyBM *) setv)->htyp != tySet_BM)
    return NULL;
  unsigned siz = ((typedsize_tyBM *) setv)->size;
  objectval_tyBM *tinyarr[TINYSIZE_BM] = { 0 };
  objectval_tyBM **arr = (siz < TINYSIZE_BM) ? tinyarr :
    calloc (prime_above_BM (siz), sizeof (objectval_tyBM *));
  if (!arr)
    FATAL_BM ("failed to alloc array of size %u",
              (unsigned) prime_above_BM (siz));
  memcpy (arr, setv->seq_objs, siz * sizeof (objectval_tyBM *));
  sortnamedobjarr_BM (arr, siz);
  tup = maketuple_BM (arr, siz);
  if (arr != tinyarr)
    free (arr);
  return tup;
}                               /* end settonamedsortedtuple_BM */

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

void *
setgcproc_BM (struct garbcoll_stBM *gc, setval_tyBM * set)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((const value_tyBM) set) == tySet_BM);
#warning setgcproc_BM should sometimes forward
  uint8_t oldmark = ((typedhead_tyBM *) set)->hgc;
  if (oldmark)
    return set;
  ((typedhead_tyBM *) set)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  unsigned siz = ((typedsize_tyBM *) set)->size;
  for (unsigned ix = 0; ix < siz; ix++)
    gcobjmark_BM (gc, (objectval_tyBM *) set->seq_objs[ix]);
  return set;
}                               /* end setgcmark_BM */


////////////////////////////////////////////////////////////////

struct datavectval_stBM *
datavect_grow_BM (struct datavectval_stBM *dvec, unsigned gap)
{
  if (valtype_BM ((const value_tyBM) dvec) != typayl_vectval_BM)
    {
      unsigned siz = prime_above_BM (gap);
      dvec =
        allocgcty_BM (typayl_vectval_BM,
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
  unsigned long siz = prime_above_BM (oldlen + gap + (oldcnt + gap) / 32 + 2);
  if (siz > MAXSIZE_BM)
    FATAL_BM ("too big datavect %ld", siz);
  unsigned long vecsiz =
    sizeof (struct datavectval_stBM) + siz * sizeof (void *);
  ASSERT_BM (vecsiz < ((4L * MAXSIZE_BM / 3) + 5L) * sizeof (void *));
  struct datavectval_stBM *newdvec =    //
    allocgcty_BM (typayl_vectval_BM, vecsiz);
  ((typedhead_tyBM *) newdvec)->rlen = siz;
  ((typedsize_tyBM *) newdvec)->size = oldcnt + gap;
  memcpy (newdvec->vec_data, dvec->vec_data, oldcnt * sizeof (void *));
  return newdvec;
}                               /* end of datavect_grow_BM */

void
datavectgcdestroy_BM (struct garbcoll_stBM *gc, struct datavectval_stBM *dvec)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) dvec)->htyp == typayl_vectval_BM);
  unsigned siz = ((typedhead_tyBM *) dvec)->rlen;
  ASSERT_BM (siz < MAXSIZE_BM);
  unsigned long vecsiz =
    sizeof (struct datavectval_stBM) + siz * sizeof (void *);
  ASSERT_BM (vecsiz < ((4L * MAXSIZE_BM / 3) + 5L) * sizeof (void *));
  memset (dvec, 0, sizeof (*dvec) + siz * sizeof (void *));
  free (dvec);
  gc->gc_freedbytes += vecsiz;
}                               /* end datavectgcdestroy_BM */


void
datavectgckeep_BM (struct garbcoll_stBM *gc, struct datavectval_stBM *dvec)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) dvec)->htyp == typayl_vectval_BM);
  unsigned siz = ((typedhead_tyBM *) dvec)->rlen;
  ASSERT_BM (siz < MAXSIZE_BM);
  unsigned long vecsiz =
    sizeof (struct datavectval_stBM) + siz * sizeof (void *);
  ASSERT_BM (vecsiz < ((4L * MAXSIZE_BM / 3) + 5L) * sizeof (void *));
  gc->gc_keptbytes += vecsiz;
}                               /* end datavectgckeep_BM */


struct datavectval_stBM *
datavect_reserve_BM (struct datavectval_stBM *dvec, unsigned gap)
{
  if (valtype_BM ((const value_tyBM) dvec) != typayl_vectval_BM)
    {
      unsigned siz = prime_above_BM (gap);
      dvec =
        allocgcty_BM (typayl_vectval_BM,
                      sizeof (struct datavectval_stBM)
                      + siz * sizeof (void *));
      ((typedhead_tyBM *) dvec)->rlen = siz;
      return dvec;
    }
  unsigned oldlen = ((typedhead_tyBM *) dvec)->rlen;
  unsigned oldcnt = ((typedsize_tyBM *) dvec)->size;
  if (oldcnt + gap <= oldlen)
    return dvec;
  unsigned long siz = prime_above_BM (oldlen + gap + (oldcnt + gap) / 32 + 2);
  if (siz > MAXSIZE_BM)
    FATAL_BM ("too big datavect %ld", siz);
  unsigned long vecsiz = sizeof (*dvec) + siz * sizeof (void *);
  ASSERT_BM (vecsiz < ((4L * MAXSIZE_BM / 3) + 5L) * sizeof (void *));
  struct datavectval_stBM *newdvec =    //
    allocgcty_BM (typayl_vectval_BM, vecsiz);
  ((typedhead_tyBM *) newdvec)->rlen = siz;
  ((typedsize_tyBM *) newdvec)->size = oldcnt;
  memcpy (newdvec->vec_data, dvec->vec_data, oldcnt * sizeof (void *));
  return newdvec;
}                               /* end of datavect_reserve_BM */



struct datavectval_stBM *
datavect_append_BM (struct datavectval_stBM *dvec, value_tyBM val)
{
  if (valtype_BM ((const value_tyBM) dvec) != typayl_vectval_BM)
    {
      unsigned siz = TINYSIZE_BM / 2;
      dvec =
        allocgcty_BM (typayl_vectval_BM,
                      sizeof (struct datavectval_stBM)
                      + siz * sizeof (void *));
      ((typedhead_tyBM *) dvec)->rlen = siz;
      ((typedsize_tyBM *) dvec)->size = 1;
      dvec->vec_data[0] = val;
      return dvec;
    }
  if (!isgenuineval_BM (val))
    val = NULL;
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
  unsigned newsiz = prime_above_BM (oldcnt + oldcnt / 5 + 4);
  struct datavectval_stBM *newdvec =    //
    allocgcty_BM (typayl_vectval_BM,
                  sizeof (struct datavectval_stBM)
                  + newsiz * sizeof (void *));
  ((typedhead_tyBM *) newdvec)->rlen = newsiz;
  ((typedsize_tyBM *) newdvec)->size = oldcnt + 1;
  memcpy (newdvec->vec_data, dvec->vec_data, oldcnt * sizeof (void *));
  newdvec->vec_data[oldcnt] = val;
  return newdvec;
}                               /* end datavect_append_BM */

struct datavectval_stBM *
datavect_pop_BM (struct datavectval_stBM *dvec)
{
  if (valtype_BM ((const value_tyBM) dvec) != typayl_vectval_BM)
    return NULL;
  unsigned oldlen = ((typedhead_tyBM *) dvec)->rlen;
  unsigned oldcnt = ((typedsize_tyBM *) dvec)->size;
  if (oldcnt > 0)
    {
      dvec->vec_data[oldcnt - 1] = NULL;
      ((typedsize_tyBM *) dvec)->size = --oldcnt;
    };
  if (oldlen > 6 && 2 * oldcnt < oldlen)
    {
      unsigned newlen =
        prime_above_BM (9 * oldcnt / 8 + ILOG2_BM (oldcnt + 2) + 3);
      if (newlen < oldlen)
        {
          struct datavectval_stBM *newdvec =    //
            allocgcty_BM (typayl_vectval_BM,
                          sizeof (struct datavectval_stBM)
                          + newlen * sizeof (void *));
          ((typedhead_tyBM *) newdvec)->rlen = newlen;
          ((typedsize_tyBM *) newdvec)->size = oldcnt;
          memcpy (newdvec->vec_data, dvec->vec_data,
                  oldcnt * sizeof (void *));
          return newdvec;
        }
    }
  return dvec;
}                               /* end datavect_pop_BM */

struct datavectval_stBM *
datavect_insert_BM (struct datavectval_stBM *dvec,
                    int rk, value_tyBM * valarr, unsigned len)
{
  if (valtype_BM ((const value_tyBM) dvec) != typayl_vectval_BM)
    return NULL;
  if (len == 0 || valarr == NULL)
    return dvec;
  unsigned oldlen = ((typedhead_tyBM *) dvec)->rlen;
  unsigned oldcnt = ((typedsize_tyBM *) dvec)->size;
  if (rk < 0)
    rk += (int) oldcnt;
  if (rk < 0 || rk >= (int) oldcnt)
    return dvec;
  if (oldlen + len >= MAXSIZE_BM)
    FATAL_BM ("datavect_insert too big %u", oldlen);
  if (oldcnt + len >= oldlen)
    {
      unsigned newsiz =
        prime_above_BM (oldcnt + len + oldcnt / 16 + len / 32 + 1);
      struct datavectval_stBM *newdvec =        //
        allocgcty_BM (typayl_vectval_BM,
                      sizeof (struct datavectval_stBM)
                      + newsiz * sizeof (void *));
      ((typedhead_tyBM *) newdvec)->rlen = newsiz;
      memcpy (newdvec->vec_data, dvec->vec_data, rk * sizeof (void *));
      for (unsigned ix = 0; ix < len; ix++)
        {
          value_tyBM curval = valarr[ix];
          if (!isgenuineval_BM (curval))
            curval = NULL;
          newdvec->vec_data[rk + ix] = curval;
        };
      memcpy (newdvec->vec_data + rk + len, dvec->vec_data + rk,
              (oldcnt - rk) * sizeof (void *));
      ((typedsize_tyBM *) newdvec)->size = oldcnt + len;
      return newdvec;
    }
  else
    {
      memmove (dvec->vec_data + rk + oldcnt, dvec->vec_data + rk,
               (oldcnt - rk) * sizeof (void *));
      for (unsigned ix = 0; ix < len; ix++)
        {
          value_tyBM curval = valarr[ix];
          if (!isgenuineval_BM (curval))
            curval = NULL;
          dvec->vec_data[rk + ix] = curval;
        };
      memcpy (dvec->vec_data + rk, valarr, len * sizeof (void *));
      ((typedsize_tyBM *) dvec)->size = oldcnt + len;
      return dvec;
    }
}                               /* end datavect_insert_BM */


struct datavectval_stBM *
datavect_remove_BM (struct datavectval_stBM *dvec, int rk, unsigned len)
{
  if (valtype_BM ((const value_tyBM) dvec) != typayl_vectval_BM)
    return NULL;
  if (len == 0)
    return dvec;
  unsigned oldlen = ((typedhead_tyBM *) dvec)->rlen;
  unsigned oldcnt = ((typedsize_tyBM *) dvec)->size;
  if (rk < 0)
    rk += oldcnt;
  if (rk < 0 || rk >= (int) oldcnt)
    return dvec;
  if (len + rk > oldcnt)
    len = oldcnt - rk;
  if (oldcnt > TINYSIZE_BM / 2 && oldcnt - rk < oldlen / 2)
    {
      unsigned newsiz = prime_above_BM (9 * (oldcnt - rk) / 8 + 1);
      if (newsiz < oldlen)
        {
          struct datavectval_stBM *newdvec =    //
            allocgcty_BM (typayl_vectval_BM,
                          sizeof (struct datavectval_stBM)
                          + newsiz * sizeof (void *));
          ((typedhead_tyBM *) newdvec)->rlen = newsiz;
          memcpy (newdvec->vec_data, dvec->vec_data, rk * sizeof (void *));
          memcpy (newdvec->vec_data + rk, dvec->vec_data + rk + len,
                  (oldcnt - rk - len) * sizeof (void *));
          ((typedsize_tyBM *) newdvec)->size = oldcnt - len;
          return newdvec;
        }
    }
  memmove (dvec->vec_data + rk, dvec->vec_data + rk + len,
           (oldcnt - rk - len) * sizeof (void *));
  ((typedsize_tyBM *) dvec)->size = oldcnt - len;
  return dvec;
}                               /* end datavect_remove_BM */


const node_tyBM *
datavect_to_node_BM (struct datavectval_stBM *dvec,
                     const objectval_tyBM * obconn)
{
  if (valtype_BM ((const value_tyBM) dvec) != typayl_vectval_BM)
    return NULL;
  if (!isobject_BM ((const value_tyBM) obconn))
    return NULL;
  unsigned cnt = ((typedsize_tyBM *) dvec)->size;
  const value_tyBM *valarr = dvec->vec_data;
  return makenode_BM (obconn, cnt, valarr);
}                               /* end datavect_to_node_BM */


void *
datavectgcproc_BM (struct garbcoll_stBM *gc,
                   struct datavectval_stBM *dvec, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((const value_tyBM) dvec) == typayl_vectval_BM);
  uint8_t oldmark = ((typedhead_tyBM *) dvec)->hgc;
  if (oldmark)
    return dvec;
  ((typedhead_tyBM *) dvec)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  unsigned dlen = ((typedhead_tyBM *) dvec)->rlen;
  unsigned dcnt = ((typedsize_tyBM *) dvec)->size;
  ASSERT_BM (dcnt <= dlen);
  for (unsigned ix = 0; ix < dcnt; ix++)
    VALUEGCPROC_BM (gc, dvec->vec_data[ix], depth + 1);
  return dvec;
}                               /* end datavectgcproc_BM  */
