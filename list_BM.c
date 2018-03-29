// file list_BM.c

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

struct listtop_stBM *
makelist_BM (void)
{
  struct listtop_stBM *lis =    //
    allocgcty_BM (typayl_listtop_BM,
                  sizeof (struct listtop_stBM));
  ((typedhead_tyBM *) lis)->rlen = 0;
  lis->list_nblinks = 0;
  lis->list_first = NULL;
  lis->list_last = NULL;
  return lis;
}                               /* end makelist_BM */

void
listgcdestroy_BM (struct garbcoll_stBM *gc, struct listtop_stBM *lis)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) lis)->htyp == typayl_listtop_BM);
  size_t frsiz = 0;
  struct listlink_stBM *curl = lis->list_first;
  unsigned linkscnt = 0;
  unsigned nblinks = lis->list_nblinks;
  while (curl != NULL)
    {
      struct listlink_stBM *nextl = curl->link_next;
      memset (curl, 0, sizeof (*curl));
      frsiz += sizeof (*curl);
      free (curl);
      curl = nextl;
      linkscnt++;
    }
  if (linkscnt != nblinks)
    FATAL_BM ("corrupted list @%p, nblinks=%u linkscnt=%u", lis, nblinks,
              linkscnt);
  memset (lis, 0, sizeof (*lis));
  free (lis);
  gc->gc_freedbytes += sizeof (*lis) + frsiz;
}                               /* end listgcdestroy_BM */

void
listgckeep_BM (struct garbcoll_stBM *gc, struct listtop_stBM *lis)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) lis)->htyp == typayl_listtop_BM);
  unsigned nblinks = lis->list_nblinks;
  ASSERT_BM (nblinks < MAXSIZE_BM);
  gc->gc_keptbytes +=           //
    sizeof (*lis) + nblinks * sizeof (struct listlink_stBM);
}                               /* end listgckeep_BM */


void
listclear_BM (struct listtop_stBM *lis)
{
  if (!islist_BM (lis))
    return;
  struct listlink_stBM *curl = lis->list_first;
  unsigned linkscnt = 0;
  unsigned nblinks = lis->list_nblinks;
  while (curl != NULL)
    {
      struct listlink_stBM *nextl = curl->link_next;
      memset (curl, 0, sizeof (*curl));
      free (curl);
      curl = nextl;
      linkscnt++;
    }
  if (linkscnt != nblinks)
    FATAL_BM ("corrupted list @%p, nblinks=%u linkscnt=%u", lis, nblinks,
              linkscnt);
  lis->list_first = lis->list_last = NULL;
  lis->list_nblinks = 0;
  ((typedhead_tyBM *) lis)->rlen = 0;
}                               /* end listclear_BM */

void
listappend_BM (struct listtop_stBM *lis, value_tyBM val)
{
  if (!islist_BM ((const value_tyBM) lis))
    return;
  if (!val)
    return;
  struct listlink_stBM *lastl = lis->list_last;
  if (!lastl)
    {
      ASSERT_BM (lis->list_first == NULL);
      ASSERT_BM (lis->list_nblinks == 0);
      ASSERT_BM (((typedhead_tyBM *) lis)->rlen == 0);
      struct listlink_stBM *newl =      //
        malloc (sizeof (struct listlink_stBM));
      if (!newl)
        FATAL_BM ("out of memory for listlink");
      memset (newl, 0, sizeof (*newl));
      lis->list_first = lis->list_last = newl;
      newl->link_mems[0] = val;
      lis->list_nblinks = 1;
      ((typedhead_tyBM *) lis)->rlen = 1;
      return;
    }
  value_tyBM lvals[LINKSIZE_BM] = { };
  unsigned cntl = 0;
  for (unsigned ix = 0; ix < LINKSIZE_BM; ix++)
    {
      const value_tyBM v = lastl->link_mems[ix];
      if (v)
        {
          lvals[cntl++] = v;
        }
    };
  ASSERT_BM (cntl > 0);
  if (cntl < LINKSIZE_BM)
    {
      lvals[cntl++] = val;
      memcpy (lastl->link_mems, lvals, LINKSIZE_BM * sizeof (value_tyBM));
      ((typedhead_tyBM *) lis)->rlen++;
      return;
    }
  struct listlink_stBM *newl =  //
    malloc (sizeof (struct listlink_stBM));
  if (!newl)
    FATAL_BM ("out of memory for listlink");
  memset (newl, 0, sizeof (*newl));
  lastl->link_next = newl;
  newl->link_prev = lastl;
  newl->link_mems[0] = val;
  ((typedhead_tyBM *) lis)->rlen++;
  lis->list_nblinks++;
  lis->list_last = newl;
}                               /* end listappend_BM */

void
listprepend_BM (struct listtop_stBM *lis, value_tyBM val)
{
  if (!islist_BM ((const value_tyBM) lis))
    return;
  if (!val)
    return;
  struct listlink_stBM *firstl = lis->list_first;
  if (!firstl)
    {
      ASSERT_BM (lis->list_last == NULL);
      ASSERT_BM (lis->list_nblinks == 0);
      ASSERT_BM (((typedhead_tyBM *) lis)->rlen == 0);
      struct listlink_stBM *newl =      //
        malloc (sizeof (struct listlink_stBM));
      if (!newl)
        FATAL_BM ("out of memory for listlink");
      memset (newl, 0, sizeof (*newl));
      lis->list_first = lis->list_last = newl;
      newl->link_mems[0] = val;
      ((typedhead_tyBM *) lis)->rlen = 1;
      lis->list_nblinks = 1;
      return;
    }
  value_tyBM lvals[LINKSIZE_BM + 1] = { };
  unsigned cntl = 1;
  lvals[0] = val;
  for (unsigned ix = 0; ix < LINKSIZE_BM; ix++)
    {
      const value_tyBM v = firstl->link_mems[ix];
      if (v)
        {
          lvals[cntl++] = v;
        }
    };
  ASSERT_BM (cntl > 1);
  if (cntl <= LINKSIZE_BM)
    {
      memcpy (firstl->link_mems, lvals, LINKSIZE_BM * sizeof (value_tyBM));
      ((typedhead_tyBM *) lis)->rlen++;
      return;
    }
  struct listlink_stBM *newl =  //
    malloc (sizeof (struct listlink_stBM));
  if (!newl)
    FATAL_BM ("out of memory for listlink");
  memset (newl, 0, sizeof (*newl));
  newl->link_next = firstl;
  firstl->link_prev = newl;
  lis->list_first = newl;
  lis->list_nblinks++;
  ((typedhead_tyBM *) lis)->rlen++;
}                               /* end listprepend_BM */

void
listpopfirst_BM (struct listtop_stBM *lis)
{
  if (!islist_BM ((const value_tyBM) lis))
    return;
  struct listlink_stBM *firstl = lis->list_first;
  if (!firstl)
    return;
  ASSERT_BM (((typedhead_tyBM *) lis)->rlen > 0);
  unsigned cntl = 0;
  value_tyBM lvals[LINKSIZE_BM + 1] = { };
  for (unsigned ix = 0; ix < LINKSIZE_BM; ix++)
    {
      const value_tyBM v = firstl->link_mems[ix];
      if (v)
        {
          if (cntl > 0)
            lvals[cntl - 1] = v;
          cntl++;
        }
    };
  if (cntl > 1)
    {
      memcpy (firstl->link_mems, lvals, LINKSIZE_BM * sizeof (void *));
      ((typedhead_tyBM *) lis)->rlen--;
      return;
    }
  else if (lis->list_last == firstl)
    {
      memset (firstl, 0, sizeof (struct listlink_stBM));
      free (firstl);
      lis->list_first = lis->list_last = NULL;
      lis->list_nblinks = 0;
      ((typedhead_tyBM *) lis)->rlen = 0;
      return;
    }
  else
    {
      lis->list_first = firstl->link_next;
      memset (firstl, 0, sizeof (struct listlink_stBM));
      free (firstl);
      lis->list_nblinks--;
      ((typedhead_tyBM *) lis)->rlen--;
      return;
    }
}                               /* end listpopfirst_BM */

void
listpoplast_BM (struct listtop_stBM *lis)
{
  if (!islist_BM ((const value_tyBM) lis))
    return;
  struct listlink_stBM *lastl = lis->list_last;
  if (!lastl)
    return;
  ASSERT_BM (((typedhead_tyBM *) lis)->rlen > 0);
  unsigned cntl = 0;
  value_tyBM lvals[LINKSIZE_BM] = { };
  for (unsigned ix = 0; ix < LINKSIZE_BM; ix++)
    {
      const value_tyBM v = lastl->link_mems[ix];
      if (v)
        lvals[cntl++] = v;
    };
  if (cntl > 1)
    {
      lvals[cntl] = NULL;
      memcpy (lastl->link_mems, lvals, LINKSIZE_BM * sizeof (void *));
      ((typedhead_tyBM *) lis)->rlen--;
      return;
    }
  else if (lis->list_first == lastl)
    {
      ASSERT_BM (lis->list_nblinks == 1);
      memset (lastl, 0, sizeof (struct listlink_stBM));
      free (lastl);
      lis->list_first = lis->list_last = NULL;
      ((typedhead_tyBM *) lis)->rlen = 0;
      lis->list_nblinks = 0;
      return;
    }
  else
    {
      lis->list_nblinks--;
      lis->list_last = lastl->link_prev;
      memset (lastl, 0, sizeof (struct listlink_stBM));
      free (lastl);
      ((typedhead_tyBM *) lis)->rlen--;
      return;
    }
}                               /* end listpoplast_BM */


const node_tyBM *
list_to_node_BM (const struct listtop_stBM *lis,
                 const objectval_tyBM * connobj)
{
  if (!islist_BM ((const value_tyBM) lis))
    return NULL;
  if (valtype_BM ((const value_tyBM) connobj) != tyObject_BM)
    return NULL;
  unsigned cnt = 0;
  unsigned nblinks = 0;
  for (struct listlink_stBM * link = lis->list_first;
       link != NULL; link = link->link_next)
    {
      for (unsigned ix = 0; ix < LINKSIZE_BM; ix++)
        {
          const value_tyBM val = link->link_mems[ix];
          if (valtype_BM (val))
            cnt++;
        }
      if (nblinks++ > MAXSIZE_BM)
        FATAL_BM ("too many %u links, cnt=%u", nblinks, cnt);
    }
  ASSERT_BM (nblinks == lis->list_nblinks);
  if (cnt > MAXSIZE_BM)
    FATAL_BM ("too huge list %u", cnt);
  value_tyBM *valarr = calloc (prime_above_BM (cnt + 1), sizeof (void *));
  if (!valarr)
    FATAL_BM ("calloc failed for %lld (%m)",
              (long long) prime_above_BM (cnt + 1));
  unsigned vacnt = 0;
  for (struct listlink_stBM * link = lis->list_first;
       link != NULL; link = link->link_next)
    {
      for (unsigned ix = 0; ix < LINKSIZE_BM; ix++)
        {
          const value_tyBM val = link->link_mems[ix];
          if (valtype_BM (val))
            valarr[vacnt++] = val;
        }
    }
  ASSERT_BM (vacnt == cnt);
  const node_tyBM *nod = makenode_BM (connobj, cnt, valarr);
  memset (valarr, 0, cnt * sizeof (void *));
  free (valarr), valarr = NULL;
  return nod;
}                               /* end list_to_node_BM */

const tupleval_tyBM *
list_to_tuple_BM (const struct listtop_stBM *lis)
{
  const tupleval_tyBM *tup = NULL;
  if (!islist_BM ((const value_tyBM) lis))
    return NULL;
  unsigned len = ((typedhead_tyBM *) lis)->rlen;
  unsigned siz = prime_above_BM (len + 1);
  objectval_tyBM *tinyarr[TINYSIZE_BM] = { };
  objectval_tyBM **arr =
    (len < TINYSIZE_BM) ? tinyarr : calloc (siz, sizeof (void *));
  if (!arr)
    FATAL_BM ("out of memory for %u pointers (%m)", siz);
  unsigned cnt = 0;
  unsigned nblinks = 0;
  for (struct listlink_stBM * link = lis->list_first;
       link != NULL; link = link->link_next)
    {
      for (unsigned ix = 0; ix < LINKSIZE_BM; ix++)
        {
          const value_tyBM val = link->link_mems[ix];
          if (valtype_BM (val) == tyObject_BM)
            {
              ASSERT_BM (cnt < len);
              arr[cnt++] = (objectval_tyBM *) val;
            }
        }
      if (nblinks++ > MAXSIZE_BM)
        FATAL_BM ("too many %u links, cnt=%u", nblinks, cnt);
    }
  ASSERT_BM (nblinks == lis->list_nblinks);
  if (cnt > MAXSIZE_BM)
    FATAL_BM ("too huge list %u", cnt);
  tup = maketuple_BM (arr, cnt);
  if (arr != tinyarr)
    free (arr), arr = NULL;
  return tup;
}                               /* end list_to_tuple_BM */

void
listgcmark_BM (struct garbcoll_stBM *gc, struct listtop_stBM *lis, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((const value_tyBM) lis) == typayl_listtop_BM);
  uint8_t oldmark = ((typedhead_tyBM *) lis)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) lis)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  unsigned cnt = 0;
  unsigned nblinks = 0;
  for (struct listlink_stBM * link = lis->list_first;
       link != NULL; link = link->link_next)
    {
      for (unsigned ix = 0; ix < LINKSIZE_BM; ix++)
        {
          VALUEGCPROC_BM (gc, link->link_mems[ix], depth + 1);
          cnt++;
          if (cnt > MAXSIZE_BM)
            FATAL_BM ("huge or circular list %u with %d links", cnt, nblinks);
        };
      nblinks++;
    }
  ASSERT_BM (nblinks == lis->list_nblinks);
}                               /* end listgcmark_BM  */
