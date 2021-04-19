// file sequence_BM.c
// SPDX-License-Identifier: GPL-3.0-or-later
/***
    BISMON 
    Copyright © 2018, 2019 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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
        if (!isobject_BM ((value_tyBM) curob))
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


const tupleval_tyBM *
makesizedtuple_BM (unsigned nbargs, ...)
{
  objectval_tyBM *tinyarr[TINYSIZE_BM] = { };
  if (nbargs > MAXSIZE_BM / 2)
    FATAL_BM ("makesizedtuple_BM too big %u", nbargs);
  objectval_tyBM **arr = (nbargs < TINYSIZE_BM) ? tinyarr
    : calloc (prime_above_BM (nbargs), sizeof (objectval_tyBM *));
  if (!arr)
    FATAL_BM ("makesizedtuple_BM failed to calloc for %u arguments", nbargs);
  int cnt = 0;
  va_list args;
  va_start (args, nbargs);
  for (int ix = 0; ix < (int) nbargs; ix++)
    {
      objectval_tyBM *curob = objectcast_BM (va_arg (args, objectval_tyBM *));
      if (!curob)
        continue;
      arr[cnt++] = curob;
    }
  va_end (args);
  const tupleval_tyBM *restup = maketuple_BM (arr, cnt);
  if (arr != tinyarr)
    free (arr), arr = NULL;
  return restup;
}                               /* end makesizedtuple_BM */

const tupleval_tyBM *
maketuplecollect_BM (value_tyBM first, ...)
{
  int cnt = 0;
  va_list args;
  value_tyBM curarg = NULL;
  va_start (args, first);
  for (curarg = first; curarg; curarg = va_arg (args, value_tyBM))
    {
      if (curarg == HASHEMPTYSLOT_BM)
        continue;
      if (isobject_BM (curarg))
        cnt++;
      else if (issequence_BM (curarg))
        cnt += sequencesize_BM (curarg);
    }
  va_end (args);
  if (cnt > MAXSIZE_BM)
    FATAL_BM ("maketuplecollect_BM too big cnt %d", cnt);
  int siz = cnt;
  objectval_tyBM *tinyarr[TINYSIZE_BM] = { };
  objectval_tyBM **arr = (siz < TINYSIZE_BM) ? tinyarr
    : calloc (prime_above_BM (siz), sizeof (objectval_tyBM *));
  if (!arr)
    FATAL_BM ("maketuplecollect_BM failed to calloc for %u arguments", siz);
  va_start (args, first);
  cnt = 0;
  for (curarg = first; curarg; curarg = va_arg (args, value_tyBM))
    {
      if (isobject_BM (curarg))
        arr[cnt++] = (objectval_tyBM *) curarg;
      else if (issequence_BM (curarg))
        {
          unsigned seqlen = sequencesize_BM (curarg);
          for (int six = 0; six < (int) seqlen; six++)
            {
              arr[cnt++] = sequencenthcomp_BM (curarg, six);
            }
        }
      else
        continue;
    }
  va_end (args);
  ASSERT_BM (cnt == siz);
  const tupleval_tyBM *restup = maketuple_BM (arr, cnt);
  if (arr != tinyarr)
    free (arr), arr = NULL;
  return restup;
}                               /* end maketuplecollect_BM */


const tupleval_tyBM *
makesizedcollecttuple_BM (unsigned nbargs, ...)
{
  int cnt = 0;
  if (nbargs > MAXSIZE_BM / 2)
    FATAL_BM ("makesizedcollecttuple_BM too big nbargs %u", nbargs);
  va_list args;
  value_tyBM curarg = NULL;
  va_start (args, nbargs);
  for (unsigned ix = 0; ix < nbargs; ix++)
    {
      curarg = va_arg (args, value_tyBM);
      if (curarg == HASHEMPTYSLOT_BM)
        continue;
      if (isobject_BM (curarg))
        cnt++;
      else if (issequence_BM (curarg))
        cnt += sequencesize_BM (curarg);
    }
  va_end (args);
  if (cnt > MAXSIZE_BM)
    FATAL_BM ("makesizedcollecttuple_BM too big cnt %d", cnt);
  int siz = cnt;
  objectval_tyBM *tinyarr[TINYSIZE_BM] = { };
  objectval_tyBM **arr = (siz < TINYSIZE_BM) ? tinyarr
    : calloc (prime_above_BM (siz), sizeof (objectval_tyBM *));
  if (!arr)
    FATAL_BM ("makesizedcollecttuple_BM failed to calloc for %u arguments",
              siz);
  va_start (args, nbargs);
  cnt = 0;
  for (unsigned ix = 0; ix < nbargs; ix++)
    {
      curarg = va_arg (args, value_tyBM);
      if (curarg == HASHEMPTYSLOT_BM)
        continue;
      if (isobject_BM (curarg))
        arr[cnt++] = (objectval_tyBM *) curarg;
      else if (issequence_BM (curarg))
        {
          int seqlen = sequencesize_BM (curarg);
          for (int ix = 0; ix < seqlen; ix++)
            arr[cnt++] = sequencenthcomp_BM (curarg, ix);
        }
    }
  va_end (args);
  ASSERT_BM (cnt == siz);
  const tupleval_tyBM *restup = maketuple_BM (arr, cnt);
  if (arr != tinyarr)
    free (arr), arr = NULL;
  return restup;
}                               /* end makesizedcollecttuple_BM */

void
tuplegcdestroy_BM (struct garbcoll_stBM *gc, tupleval_tyBM * tup)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) tup)->htyp == tyTuple_BM);
  unsigned siz = ((typedsize_tyBM *) tup)->size;
  ASSERT_BM (siz < MAXSIZE_BM);
  unsigned long tupsiz = sizeof (tupleval_tyBM) //
    + ((siz > 0)                //
       ? (prime_above_BM (siz - 1) * sizeof (objectval_tyBM *)) : 0);
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
        if (!isobject_BM ((value_tyBM) arr[ix]))
          continue;
        siz++;
      };
  if (siz > MAXSIZE_BM)
    FATAL_BM ("makeset too big size %u", siz);
  if (siz < TINYSIZE_BM)
    tmparr = tinyarr;
  else
    tmparr = calloc (prime_above_BM (siz), sizeof (void *));
  if (!tmparr)
    FATAL_BM ("makeset cannot allocate tmparr siz=%u", siz);
  unsigned cnt = 0;
  for (unsigned ix = 0; ix < rawsiz; ix++)
    if (isobject_BM ((value_tyBM) arr[ix]))
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
  if (tmparr != tinyarr)
    free (tmparr);
  return set;
}                               /* end makeset_BM */



const setval_tyBM *
makesizedset_BM (unsigned nbargs, ...)
{
  if (nbargs > MAXSIZE_BM / 2)
    FATAL_BM ("makesizedset_BM too big %u", nbargs);
  objectval_tyBM *tinyarr[TINYSIZE_BM] = { };
  objectval_tyBM **arr = (nbargs < TINYSIZE_BM) ? tinyarr
    : calloc (prime_above_BM (nbargs), sizeof (objectval_tyBM *));
  if (!arr)
    FATAL_BM ("calloc failed in makesizedset_BM for %u elements", nbargs);
  va_list args;
  int cnt = 0;
  va_start (args, nbargs);
  for (unsigned ix = 0; ix < nbargs; ix++)
    {
      objectval_tyBM *curob = objectcast_BM (va_arg (args, value_tyBM *));
      if (!curob)
        continue;
      arr[cnt++] = curob;
    }
  va_end (args);
  const setval_tyBM *res = makeset_BM ((const objectval_tyBM **) arr, cnt);
  if (arr != tinyarr)
    free (arr), arr = NULL;
  return res;
}                               /* end makesizedset_BM */


const setval_tyBM *
makesetcollect_BM (value_tyBM first, ...)
{
  int cnt = 0;
  va_list args;
  value_tyBM curarg = NULL;
  value_tyBM nextarg = NULL;
  va_start (args, first);
  for (curarg = first; curarg != NULL; curarg = nextarg)
    {
      if (isobject_BM (curarg))
        cnt++;
      else if (issequence_BM (curarg))
        cnt += sequencesize_BM (curarg);
      nextarg = va_arg (args, value_tyBM);
    }
  va_end (args);
  if (cnt > MAXSIZE_BM)
    FATAL_BM ("makesetcollect_BM too big cnt %d", cnt);
  int siz = cnt;
  objectval_tyBM *tinyarr[TINYSIZE_BM] = { };
  objectval_tyBM **arr = (siz < TINYSIZE_BM) ? tinyarr
    : calloc (prime_above_BM (siz), sizeof (objectval_tyBM *));
  if (!arr)
    FATAL_BM ("maketuplecollect_BM failed to calloc for %u arguments", siz);
  va_start (args, first);
  cnt = 0;
  for (curarg = first; curarg; curarg = va_arg (args, value_tyBM))
    {
      if (isobject_BM (curarg))
        arr[cnt++] = (objectval_tyBM *) curarg;
      else if (issequence_BM (curarg))
        {
          unsigned seqlen = sequencesize_BM (curarg);
          for (int six = 0; six < (int) seqlen; six++)
            {
              arr[cnt++] = sequencenthcomp_BM (curarg, six);
            }
        }
      else
        continue;
    }
  va_end (args);
  ASSERT_BM (cnt == siz);
  const tupleval_tyBM *restup =
    makeset_BM ((const objectval_tyBM **) arr, cnt);
  if (arr != tinyarr)
    free (arr), arr = NULL;
  return restup;
}                               /* end makesetcollect_BM */



const setval_tyBM *
makesizedcollectset_BM (unsigned nbargs, ...)
{
  int cnt = 0;
  if (nbargs > MAXSIZE_BM / 2)
    FATAL_BM ("makesizedcollectset_BM too big nbargs %u", nbargs);
  va_list args;
  value_tyBM curarg = NULL;
  va_start (args, nbargs);
  for (unsigned ix = 0; ix < nbargs; ix++)
    {
      curarg = va_arg (args, value_tyBM);
      if (curarg == HASHEMPTYSLOT_BM)
        continue;
      if (isobject_BM (curarg))
        cnt++;
      else if (issequence_BM (curarg))
        cnt += sequencesize_BM (curarg);
    }
  va_end (args);
  if (cnt > MAXSIZE_BM)
    FATAL_BM ("makesizedcollectset_BM too big cnt %d", cnt);
  int siz = cnt;
  objectval_tyBM *tinyarr[TINYSIZE_BM] = { };
  objectval_tyBM **arr = (siz < TINYSIZE_BM) ? tinyarr
    : calloc (prime_above_BM (siz), sizeof (objectval_tyBM *));
  if (!arr)
    FATAL_BM ("makesizedcollectset_BM failed to calloc for %u arguments",
              siz);
  va_start (args, nbargs);
  cnt = 0;
  for (unsigned ix = 0; ix < nbargs; ix++)
    {
      curarg = va_arg (args, value_tyBM);
      if (curarg == HASHEMPTYSLOT_BM)
        continue;
      if (isobject_BM (curarg))
        arr[cnt++] = (objectval_tyBM *) curarg;
      else if (issequence_BM (curarg))
        {
          int seqlen = sequencesize_BM (curarg);
          for (int ix = 0; ix < seqlen; ix++)
            arr[cnt++] = sequencenthcomp_BM (curarg, ix);
        }
    }
  va_end (args);
  ASSERT_BM (cnt == siz);
  const setval_tyBM *rset = makeset_BM ((const objectval_tyBM **) arr, cnt);
  if (arr != tinyarr)
    free (arr), arr = NULL;
  return rset;
}                               /* end makesizedcollectset_BM */




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
        return md;
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

// allocated size:
#define DATAVECT_ASIZ_BM(Dvect) (((typedhead_tyBM *) (Dvect))->rlen)
// used length:
#define DATAVECT_ULEN_BM(Dvect)  (((typedsize_tyBM *) (Dvect))->size)

struct datavectval_stBM *
datavect_grow_BM (struct datavectval_stBM *dvec, unsigned gap)
{
  if (valtype_BM ((const value_tyBM) dvec) != typayl_vectval_BM)
    {
      unsigned siz = prime_above_BM (gap + ILOG2_BM (gap + 2));
      dvec =
        allocgcty_BM (typayl_vectval_BM,
                      sizeof (struct datavectval_stBM)
                      + siz * sizeof (void *));
      DATAVECT_ASIZ_BM (dvec) = siz;
      DATAVECT_ULEN_BM (dvec) = gap;
      return dvec;
    }
  unsigned oldasiz = DATAVECT_ASIZ_BM (dvec);
  unsigned oldulen = DATAVECT_ULEN_BM (dvec);
  memset (dvec->vec_data + oldulen, 0, gap * sizeof (void *));
  if (oldulen + gap <= oldasiz)
    return dvec;
  unsigned long newsiz =        //
    prime_above_BM (oldulen + gap + ILOG2_BM (oldulen + gap + 2));
  if (newsiz > MAXSIZE_BM)
    FATAL_BM ("too big datavect %ld", newsiz);
  if (newsiz <= oldasiz)
    return dvec;
  unsigned long vecsiz =
    sizeof (struct datavectval_stBM) + newsiz * sizeof (void *);
  ASSERT_BM (vecsiz < ((4L * MAXSIZE_BM / 3) + 5L) * sizeof (void *));
  struct datavectval_stBM *newdvec =    //
    allocgcty_BM (typayl_vectval_BM, vecsiz);
  DATAVECT_ASIZ_BM (newdvec) = newsiz;
  DATAVECT_ULEN_BM (newdvec) = oldulen + gap;
  return newdvec;
}                               /* end of datavect_grow_BM */



void
datavectgcdestroy_BM (struct garbcoll_stBM *gc, struct datavectval_stBM *dvec)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) dvec)->htyp == typayl_vectval_BM);
  unsigned asiz = DATAVECT_ASIZ_BM (dvec);
  ASSERT_BM (asiz <= MAXSIZE_BM);
  size_t bytsiz = sizeof (struct datavectval_stBM) + asiz * sizeof (void *);
  ASSERT_BM (bytsiz < ((4L * MAXSIZE_BM / 3) + 5L) * sizeof (void *));
  memset (dvec, 0, bytsiz);
  free (dvec);
  gc->gc_freedbytes += bytsiz;
}                               /* end datavectgcdestroy_BM */


void
datavectgckeep_BM (struct garbcoll_stBM *gc, struct datavectval_stBM *dvec)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) dvec)->htyp == typayl_vectval_BM);
  unsigned asiz = DATAVECT_ASIZ_BM (dvec);
  ASSERT_BM (asiz <= MAXSIZE_BM);
  size_t bytsiz = sizeof (struct datavectval_stBM) + asiz * sizeof (void *);
  ASSERT_BM (bytsiz < ((4L * MAXSIZE_BM / 3) + 5L) * sizeof (void *));
  gc->gc_keptbytes += bytsiz;
}                               /* end datavectgckeep_BM */


struct datavectval_stBM *
datavect_reserve_BM (struct datavectval_stBM *dvec, unsigned gap)
{
  if (valtype_BM ((const value_tyBM) dvec) != typayl_vectval_BM)
    {
      unsigned asiz = prime_above_BM (gap + ILOG2_BM (gap + 1));
      dvec =
        allocgcty_BM (typayl_vectval_BM,
                      sizeof (struct datavectval_stBM)
                      + asiz * sizeof (void *));
      DATAVECT_ASIZ_BM (dvec) = asiz;
      DATAVECT_ULEN_BM (dvec) = 0;
      return dvec;
    }
  unsigned oldasiz = DATAVECT_ASIZ_BM (dvec);
  unsigned oldulen = DATAVECT_ULEN_BM (dvec);
  if (oldulen + gap <= oldasiz)
    return dvec;
  unsigned long newasiz =
    prime_above_BM (oldulen + gap + ILOG2_BM (oldulen + gap + 2));
  if (newasiz > MAXSIZE_BM)
    FATAL_BM ("too big datavect %lu", newasiz);
  size_t bytsiz = sizeof (*dvec) + newasiz * sizeof (void *);
  ASSERT_BM (bytsiz < ((4L * MAXSIZE_BM / 3) + 5L) * sizeof (void *));
  if (newasiz <= oldasiz)
    return dvec;
  struct datavectval_stBM *newdvec =    //
    allocgcty_BM (typayl_vectval_BM, bytsiz);
  DATAVECT_ASIZ_BM (newdvec) = newasiz;
  DATAVECT_ULEN_BM (newdvec) = oldulen;
  memcpy (newdvec->vec_data, dvec->vec_data, oldulen * sizeof (void *));
  return newdvec;
}                               /* end of datavect_reserve_BM */



struct datavectval_stBM *
datavect_append_BM (struct datavectval_stBM *dvec, value_tyBM val)
{
  if (!isgenuineval_BM (val))
    val = NULL;
  if (valtype_BM ((const value_tyBM) dvec) != typayl_vectval_BM)
    {
      unsigned newsiz = TINYSIZE_BM / 2;
      dvec =
        allocgcty_BM (typayl_vectval_BM,
                      sizeof (struct datavectval_stBM)
                      + newsiz * sizeof (void *));
      DATAVECT_ASIZ_BM (dvec) = newsiz;
      DATAVECT_ULEN_BM (dvec) = 1;
      dvec->vec_data[0] = val;
      return dvec;
    }
  unsigned oldasiz = DATAVECT_ASIZ_BM (dvec);
  unsigned oldulen = DATAVECT_ULEN_BM (dvec);
  if (oldulen + 1 <= oldasiz)
    {
      dvec->vec_data[oldulen] = val;
      DATAVECT_ULEN_BM (dvec) = oldulen + 1;
      return dvec;
    }
  if (oldulen + 1 >= MAXSIZE_BM)
    FATAL_BM ("datavect_append too big %u", oldulen);
  unsigned newasiz =            //
    prime_above_BM (oldulen + oldulen / 16 + ILOG2_BM (oldulen + 2));
  if (newasiz <= oldasiz)
    return dvec;
  struct datavectval_stBM *newdvec =    //
    allocgcty_BM (typayl_vectval_BM,
                  sizeof (struct datavectval_stBM)
                  + newasiz * sizeof (void *));
  DATAVECT_ASIZ_BM (newdvec) = newasiz;
  DATAVECT_ULEN_BM (newdvec) = oldulen + 1;
  memcpy (newdvec->vec_data, dvec->vec_data, oldulen * sizeof (void *));
  newdvec->vec_data[oldulen] = val;
  return newdvec;
}                               /* end datavect_append_BM */



struct datavectval_stBM *
datavect_pop_BM (struct datavectval_stBM *dvec)
{
  if (valtype_BM ((const value_tyBM) dvec) != typayl_vectval_BM)
    return NULL;
  unsigned oldasiz = DATAVECT_ASIZ_BM (dvec);
  unsigned oldulen = DATAVECT_ULEN_BM (dvec);
  if (oldulen > 0)
    {
      dvec->vec_data[oldulen - 1] = NULL;
      oldulen--;
      DATAVECT_ULEN_BM (dvec) = oldulen;
    }
  else
    return dvec;
  if (oldulen > TINYSIZE_BM / 2 && 2 * oldulen + 1 < oldasiz)
    {
      unsigned newasiz =        //
        prime_above_BM (9 * oldulen / 8 + ILOG2_BM (oldulen + 2) + 2);
      if (newasiz < oldasiz)
        {
          struct datavectval_stBM *newdvec =    //
            allocgcty_BM (typayl_vectval_BM,
                          sizeof (struct datavectval_stBM)
                          + newasiz * sizeof (void *));
          DATAVECT_ASIZ_BM (newdvec) = newasiz;
          DATAVECT_ULEN_BM (newdvec) = oldulen;
          memcpy (newdvec->vec_data, dvec->vec_data,
                  oldulen * sizeof (void *));
          return newdvec;
        }
    }
  return dvec;
}                               /* end datavect_pop_BM */



struct datavectval_stBM *
datavect_removeone_BM (struct datavectval_stBM *dvec, int ix)
{
  if (valtype_BM ((const value_tyBM) dvec) != typayl_vectval_BM)
    return NULL;
  unsigned oldasiz = DATAVECT_ASIZ_BM (dvec);
  unsigned oldulen = DATAVECT_ULEN_BM (dvec);
  if (ix < 0)
    ix += oldulen;
  if (ix >= 0 && ix < (int) oldulen)
    {
      for (int j = ix; j < (int) oldulen - 1; j++)
        dvec->vec_data[j] = dvec->vec_data[j + 1];
      dvec->vec_data[oldulen - 1] = NULL;
      oldulen--;
      DATAVECT_ULEN_BM (dvec) = oldulen;
      if (oldulen > TINYSIZE_BM / 2 && 2 * oldulen + 1 < oldasiz)
        {
          unsigned newasiz =
            prime_above_BM (9 * oldulen / 8 + ILOG2_BM (oldulen + 2) + 1);
          if (newasiz < oldasiz)
            {
              struct datavectval_stBM *newdvec =        //
                allocgcty_BM (typayl_vectval_BM,
                              sizeof (struct datavectval_stBM)
                              + newasiz * sizeof (void *));
              DATAVECT_ASIZ_BM (newdvec) = newasiz;
              DATAVECT_ULEN_BM (newdvec) = oldulen;
              memcpy (newdvec->vec_data, dvec->vec_data,
                      oldulen * sizeof (void *));
              return newdvec;
            }
        }
    }
  return dvec;
}                               /* end datavect_removeone_BM */


struct datavectval_stBM *
datavect_insert_BM (struct datavectval_stBM *dvec,
                    int rk, value_tyBM * insvalarr, unsigned inslen)
{
  if (valtype_BM ((const value_tyBM) dvec) != typayl_vectval_BM)
    return NULL;
  if (inslen == 0 || insvalarr == NULL)
    return dvec;
  unsigned oldasiz = DATAVECT_ASIZ_BM (dvec);
  unsigned oldulen = DATAVECT_ULEN_BM (dvec);
  if (rk < 0)
    rk += (int) oldulen;
  if (rk < 0 || rk >= (int) oldulen)
    return dvec;
  if (oldulen + inslen >= MAXSIZE_BM)
    FATAL_BM ("datavect_insert too big %u, adding %u", oldulen, inslen);
  if (oldulen + inslen >= oldasiz)
    {
      unsigned newasiz =
        prime_above_BM (oldulen + inslen + inslen / 32 +
                        ILOG2_BM (oldulen + inslen + 1));
      struct datavectval_stBM *newdvec =        //
        allocgcty_BM (typayl_vectval_BM,
                      sizeof (struct datavectval_stBM)
                      + newasiz * sizeof (void *));
      DATAVECT_ASIZ_BM (newdvec) = newasiz;
      memcpy (newdvec->vec_data, dvec->vec_data, rk * sizeof (void *));
      for (unsigned ix = 0; ix < inslen; ix++)
        {
          value_tyBM curval = insvalarr[ix];
          if (!isgenuineval_BM (curval))
            curval = NULL;
          newdvec->vec_data[rk + ix] = curval;
        };
      memcpy (newdvec->vec_data + rk + inslen, dvec->vec_data + rk,
              (oldulen - rk) * sizeof (void *));
      DATAVECT_ULEN_BM (newdvec) = oldulen + inslen;
      return newdvec;
    }
  else                          // dont need to grow, insert in place
    {
      // we don't need to care about components 0 to rk-1 included, they don't change
      // we move to the right the components rk to rk+olducnt-1 into rk+inslen to rk+len+olducnt-1
      memmove (dvec->vec_data + rk + inslen,
               dvec->vec_data + rk, (oldulen - rk) * sizeof (void *));
      // we insert one by one the genuine values from insvalarr at rk
      for (unsigned insix = 0; insix < inslen; insix++)
        {
          value_tyBM curval = insvalarr[insix];
          if (!isgenuineval_BM (curval))
            curval = NULL;
          dvec->vec_data[rk + insix] = curval;
        }
      DATAVECT_ULEN_BM (dvec) = oldulen + inslen;
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
  unsigned oldasiz = DATAVECT_ASIZ_BM (dvec);
  unsigned oldulen = DATAVECT_ULEN_BM (dvec);
  if (rk < 0)
    rk += oldulen;
  if (rk < 0 || rk >= (int) oldulen)
    return dvec;
  if (len + rk > oldulen)
    len = oldulen - rk;
  if (oldulen > TINYSIZE_BM / 2 && oldulen - len < oldasiz / 2)
    {
      unsigned newasiz =
        prime_above_BM (9 * (oldulen - len) / 8 +
                        ILOG2_BM (oldulen - len + 2));
      if (newasiz < oldasiz)
        {
          struct datavectval_stBM *newdvec =    //
            allocgcty_BM (typayl_vectval_BM,
                          sizeof (struct datavectval_stBM)
                          + newasiz * sizeof (void *));
          DATAVECT_ASIZ_BM (newdvec) = newasiz;
          memcpy (newdvec->vec_data, dvec->vec_data, rk * sizeof (void *));
          memcpy (newdvec->vec_data + rk, dvec->vec_data + rk + len,
                  (oldulen - rk - len) * sizeof (void *));
          DATAVECT_ULEN_BM (newdvec) = oldulen - len;
          return newdvec;
        }
    }
  memmove (dvec->vec_data + rk, dvec->vec_data + rk + len,
           (oldulen - rk - len) * sizeof (void *));
  DATAVECT_ULEN_BM (dvec) = oldulen - len;
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

const tupleval_tyBM *
datavect_to_tuple_BM (struct datavectval_stBM *dvec)
{
  if (valtype_BM ((const value_tyBM) dvec) != typayl_vectval_BM)
    return NULL;
  unsigned cnt = ((typedsize_tyBM *) dvec)->size;
  const value_tyBM *valarr = dvec->vec_data;
  bool allobj = true;
  for (unsigned ix = 0; ix < cnt && allobj; ix++)
    if (valarr[ix] && !isobject_BM (valarr[ix]))
      allobj = false;
  if (allobj)
    return maketuple_BM ((objectval_tyBM **) valarr, cnt);
  objectval_tyBM **objarr =
    calloc (prime_above_BM (cnt), sizeof (objectval_tyBM *));
  if (!objarr)
    FATAL_BM ("failed to calloc for %d objects", cnt + 1);
  for (unsigned ix = 0; ix < cnt; ix++)
    objarr[ix] = objectcast_BM (valarr[ix]);
  const tupleval_tyBM *tup = maketuple_BM (objarr, cnt);
  free (objarr);
  return tup;
}                               /* end datavect_to_tuple_BM */

void *
datavectgcproc_BM (struct garbcoll_stBM *gc,
                   struct datavectval_stBM *dvec, objectval_tyBM * fromob,
                   int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((const value_tyBM) dvec) == typayl_vectval_BM);
  ASSERT_BM (!fromob || isobject_BM (fromob));
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





////////////////////////////////////////////////////////////////
///// decaying vector  payload
void
decayedvectorgcmark_BM (struct garbcoll_stBM *gc,
                        struct decayedvectpayl_stBM *dvec,
                        objectval_tyBM * fromob, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (isdecayedvect_BM ((const value_tyBM) dvec));
  ASSERT_BM (fromob == NULL || isobject_BM (fromob));
  uint8_t oldmark = ((typedhead_tyBM *) dvec)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) dvec)->hgc = MARKGC_BM;
  if (islivedecayedvect_BM ((const value_tyBM) dvec))
    {
      unsigned ucnt = DECAYEDVECTOR_UCNT_bm (dvec);
      unsigned asiz = DECAYEDVECTOR_ASIZ_bm (dvec);
      if (ucnt > asiz)
        FATAL_BM ("corrupted decayed vector @%p ucnt %u > asiz %u",
                  dvec, ucnt, asiz);
      value_tyBM *valarr = dvec->decayp_arr;
      for (unsigned ix = 0; ix < ucnt; ix++)
        {
          if (!valarr[ix])
            continue;
          VALUEGCPROC_BM (gc, valarr[ix], depth + 1);
        }
    }
  else
    {
      unsigned ucnt = DECAYEDVECTOR_UCNT_bm (dvec);
      ASSERT_BM (ucnt <= DECAYEDVECTOR_ASIZ_bm (dvec));
      value_tyBM *valarr = dvec->decayp_arr;
      for (unsigned ix = 0; ix < ucnt; ix++)
        {
          valarr[ix] = NULL;
        }
    }
  gc->gc_nbmarks++;
}                               /* end of decayedvectorgcmark_BM */

void
decayedvectordestroy_BM (struct garbcoll_stBM *gc,
                         struct decayedvectpayl_stBM *dvec)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (isdecayedvect_BM ((const value_tyBM) dvec));
  unsigned ucnt = DECAYEDVECTOR_UCNT_bm (dvec);
  unsigned asiz = DECAYEDVECTOR_ASIZ_bm (dvec);
  ASSERT_BM (ucnt <= asiz);
  value_tyBM *valarr = dvec->decayp_arr;
  for (unsigned ix = 0; ix < ucnt; ix++)
    {
      valarr[ix] = NULL;
    }
  free ((void *) dvec);
  gc->gc_freedbytes += sizeof (*dvec) + asiz * sizeof (value_tyBM);
}                               /* end of decayedvectordestroy_BM */

void
decayedvectorgckeep_BM (struct garbcoll_stBM *gc,
                        struct decayedvectpayl_stBM *dvec)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (isdecayedvect_BM ((const value_tyBM) dvec));
  unsigned ucnt = DECAYEDVECTOR_UCNT_bm (dvec);
  unsigned asiz = DECAYEDVECTOR_ASIZ_bm (dvec);
  ASSERT_BM (ucnt <= asiz);
  // const value_tyBM *valarr = dvec->decayp_arr;
  gc->gc_keptbytes += sizeof (*dvec) + asiz * sizeof (value_tyBM);
}                               /* end of decayedvectorgckeep_BM */



bool
objputdecayedvectorpayl_BM (objectval_tyBM * obj, unsigned asiz,
                            unsigned delayms)
{
  if (!isobject_BM ((value_tyBM) obj))
    return false;
  if (delayms < MINDELAY_DECAYED_MILLISECOND_BM)
    delayms = MINDELAY_DECAYED_MILLISECOND_BM;
  if (asiz > MAXSIZE_BM)
    FATAL_BM ("too big asiz %u in objputdecayedvectorpayl_BM", asiz);
  asiz = prime_above_BM (asiz);
  struct decayedvectpayl_stBM *dvec =   //
    allocgcty_BM (typayl_decayed_BM,
                  sizeof (*dvec) + asiz * sizeof (value_tyBM));
  if (dvec)
    {
      DECAYEDVECTOR_ASIZ_bm (dvec) = asiz;
      DECAYEDVECTOR_UCNT_bm (dvec) = 0;
      dvec->decayp_limitime = elapsedtime_BM () + 1.0e-3 * delayms;
      objputpayload_BM (obj, dvec);
      DBGPRINTF_BM ("objputdecayedvectorpayl_BM obj %s asiz %d\n"
                    ".. decayp_limitime %.4f (elasped + %.3f) dvec@%p",
                    objectdbg_BM (obj), asiz, dvec->decayp_limitime,
                    dvec->decayp_limitime - elapsedtime_BM (), (void *) dvec);
      DBGPRINTF_BM
        ("objputdecayedvectorpayl_BM obj %s dvec@%p DECAYEDVECTOR_ASIZ_bm@%p:%u DECAYEDVECTOR_UCNT_bm@%p:%u",
         objectdbg_BM (obj), dvec, &DECAYEDVECTOR_ASIZ_bm (dvec),
         DECAYEDVECTOR_ASIZ_bm (dvec), &DECAYEDVECTOR_UCNT_bm (dvec),
         DECAYEDVECTOR_UCNT_bm (dvec));
      return true;
    }
  return false;
}                               /* end objputdecayedvectorpayl_BM */


// end of file sequence_BM.c
