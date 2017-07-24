// file list_BM.c
#include "bismon.h"

struct listtop_stBM *
listmake_BM (void)
{
  struct listtop_stBM *lis =    //
    allocinternalty_BM (tydata_listtop_BM,
                        sizeof (struct listtop_stBM));
  ((typedhead_tyBM *) lis)->rlen = 0;
  lis->list_first = NULL;
  lis->list_last = NULL;
  return lis;
}                               /* end listmake_BM */


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
listpopfirst (struct listtop_stBM *lis)
{
  if (!islist_BM ((const value_tyBM) lis))
    return;
}                               /* end listpopfirst */

void
listpoplast (struct listtop_stBM *lis)
{
  if (!islist_BM ((const value_tyBM) lis))
    return;
}                               /* end listpoplast */

const node_tyBM *
list_to_node_BM (const struct listtop_stBM *lis,
                 const objectval_tyBM * connobj)
{
  if (!islist_BM ((const value_tyBM) lis))
    return NULL;
  if (valtype_BM ((const value_tyBM) connobj) != tyObject_BM)
    return lis;
}                               /* end list_to_node_BM */

void
list_destroy_BM (struct listtop_stBM *lis)
{
  if (!islist_BM ((const value_tyBM) lis))
    return;
  listclear_BM (lis);
  free (lis);
}                               /* end list_destroy_BM */
