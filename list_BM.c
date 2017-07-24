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
    }
}                               /* end listappend_BM */

void
listprepend_BM (struct listtop_stBM *lis, value_tyBM val)
{
  if (!islist_BM ((const value_tyBM) lis))
    return;
  if (!val)
    return;
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
