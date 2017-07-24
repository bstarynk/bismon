// file node_BM.c
#include "bismon.h"

const closure_tyBM *
makeclosure_BM (const objectval_tyBM * connob, unsigned nbval,
                const value_tyBM * closvalarr)
{
  if (!isobject_BM ((const value_tyBM) connob))
    return NULL;
  if (closvalarr == NULL)
    nbval = 0;
  if (nbval >= MAXSIZE_BM)
    FATAL_BM ("too wide closure %u", nbval);
  unsigned cnt = 0;
  for (unsigned ix = 0; ix < nbval; ix++)
    if (valtype_BM (closvalarr[ix]))
      cnt++;
  closure_tyBM *clos =          //
    allocgcty_BM (tyClosure_BM,
                  sizeof (closure_tyBM)
                  + (cnt > 0)
                  ? (prime_above_BM (cnt - 1) * sizeof (value_tyBM)) : 0);
  hash_tyBM h1 = objecthash_BM (connob);
  hash_tyBM h2 = cnt;
  ((typedsize_tyBM *) clos)->size = cnt;
  clos->nodt_conn = connob;
  unsigned newcnt = 0;
  for (unsigned ix = 0; ix < nbval; ix++)
    {
      value_tyBM curson = closvalarr[ix];
      if (valtype_BM (curson))
        {
          // should compute hash of curson
          clos->nodt_sons[newcnt++] = curson;
        }
    }
#warning incomplete makeclosure_BM
}                               /* end makeclosure_BM */

#warning empty node_BM.c
