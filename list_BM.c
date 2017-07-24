// file list_BM.c
#include "bismon.h"

struct listtop_stBM *
makelist_BM (void)
{
  struct listtop_stBM *lis =    //
    allocinternalty_BM (tydata_listtop_BM,
                        sizeof (struct listtop_stBM));
  ((typedhead_tyBM *) lis)->rlen = 0;
  lis->list_first = NULL;
  lis->list_last = NULL;
  return lis;
}                               /* end makelist_BM */


void
listclear_BM (struct listtop_stBM *lis)
{
  if (!islist_BM (lis))
    return;
  struct listlink_stBM *curl = lis->list_first;
  while (curl != NULL)
    {
      struct listlink_stBM *nextl = curl->link_next;
      memset (curl, 0, sizeof (*curl));
      free (curl);
      curl = nextl;
    }
  lis->list_first = lis->list_last = NULL;
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
      assert (lis->list_first == NULL);
      assert (((typedhead_tyBM *) lis)->rlen == 0);
      struct listlink_stBM *newl =      //
        malloc (sizeof (struct listlink_stBM));
      if (!newl)
        FATAL_BM ("out of memory for listlink");
      memset (newl, 0, sizeof (*newl));
      lis->list_first = lis->list_last = newl;
      newl->link_mems[0] = val;
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
  assert (cntl > 0);
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
      assert (lis->list_last == NULL);
      assert (((typedhead_tyBM *) lis)->rlen == 0);
      struct listlink_stBM *newl =      //
        malloc (sizeof (struct listlink_stBM));
      if (!newl)
        FATAL_BM ("out of memory for listlink");
      memset (newl, 0, sizeof (*newl));
      lis->list_first = lis->list_last = newl;
      newl->link_mems[0] = val;
      ((typedhead_tyBM *) lis)->rlen = 1;
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
  assert (cntl > 1);
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
  assert (((typedhead_tyBM *) lis)->rlen > 0);
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
      ((typedhead_tyBM *) lis)->rlen = 0;
      return;
    }
  else
    {
      lis->list_first = firstl->link_next;
      memset (firstl, 0, sizeof (struct listlink_stBM));
      free (firstl);
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
  assert (((typedhead_tyBM *) lis)->rlen > 0);
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
      memset (lastl, 0, sizeof (struct listlink_stBM));
      free (lastl);
      lis->list_first = lis->list_last = NULL;
      ((typedhead_tyBM *) lis)->rlen = 0;
      return;
    }
  else
    {
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
#warning list_to_node_BM unimplemented
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
  for (struct listlink_stBM * link = lis->list_first;
       link != NULL; link = link->link_next)
    {
      for (unsigned ix = 0; ix < LINKSIZE_BM; ix++)
        {
          const value_tyBM val = link->link_mems[ix];
          if (valtype_BM (val) == tyObject_BM)
            {
              assert (cnt < len);
              arr[cnt++] = (objectval_tyBM *) val;
            }
        }
    }
  if (cnt > MAXSIZE_BM)
    FATAL_BM ("too huge list %u", cnt);
  tup = maketuple_BM (arr, cnt);
  if (arr != tinyarr)
    free (arr);
  return tup;
}                               /* end list_to_tuple_BM */


void
list_destroy_BM (struct listtop_stBM *lis)
{
  if (!islist_BM ((const value_tyBM) lis))
    return;
  listclear_BM (lis);
  memset (lis, 0, sizeof (*lis));
  free (lis);
}                               /* end list_destroy_BM */
