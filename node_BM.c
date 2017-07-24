// file node_BM.c
#include "bismon.h"

const closure_tyBM *
makeclosure_BM (const objectval_tyBM * connob, unsigned nbclos,
                const value_tyBM * closvalarr)
{
  if (!isobject_BM (connob))
    return NULL;
  if (closvalarr == NULL)
    nbclos = 0;
  if (nbclos >= MAXSIZE_BM)
    FATAL_BM ("too wide closure %u", nbclos);
  closure_tyBM *clos =          //
    allocgcty_BM (tyClosure_BM,
                  sizeof (closure_tyBM) + nbclos * sizeof (value_tyBM));
#warning incomplete makeclosure_BM
}                               /* end makeclosure_BM */

#warning empty node_BM.c
