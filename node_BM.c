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
          hash_tyBM curh = valhash_BM (curson);
          if (newcnt % 2)
            h1 = (h1 * 5653 + newcnt) ^ (curh * 8677);
          else
            h2 = (h2 * 7681 - 4 * newcnt) ^ (curh * 18661);
          clos->nodt_sons[newcnt++] = curson;
        }
    }
  hash_tyBM h = h1 ^ h2;
  if (!h)
    h = (11 * (h1 & 0xfffff) + (h2 % 38611)) + (newcnt & 0xf) + 13;
  assert (h > 0);
  ((typedhead_tyBM *) clos)->hash = h;
  return clos;
}                               /* end makeclosure_BM */


void
closuregcmark_BM (struct garbcoll_stBM *gc, closure_tyBM * clos, int depth)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (valtype_BM ((const value_tyBM) clos) == tyClosure_BM);
  uint8_t oldmark = ((typedhead_tyBM *) clos)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) clos)->hgc = MARKGC_BM;
  gcobjmark_BM (gc, clos->nodt_conn);
  unsigned size = ((typedsize_tyBM *) clos)->size;
  for (unsigned ix = 0; ix < size; ix++)
    gcmark_BM (gc, clos->nodt_sons[ix], depth + 1);
}                               /* end nodegcmark_BM */




const node_tyBM *
makenode_BM (const objectval_tyBM * connob, unsigned nbval,
             const value_tyBM * sonvalarr)
{
  if (!isobject_BM ((const value_tyBM) connob))
    return NULL;
  if (sonvalarr == NULL)
    nbval = 0;
  if (nbval >= MAXSIZE_BM)
    FATAL_BM ("too wide node %u", nbval);
  unsigned cnt = 0;
  for (unsigned ix = 0; ix < nbval; ix++)
    if (valtype_BM (sonvalarr[ix]))
      cnt++;
  closure_tyBM *node =          //
    allocgcty_BM (tyNode_BM,
                  sizeof (node_tyBM)
                  + (cnt > 0)
                  ? (prime_above_BM (cnt - 1) * sizeof (value_tyBM)) : 0);
  hash_tyBM h1 = objecthash_BM (connob);
  hash_tyBM h2 = cnt;
  ((typedsize_tyBM *) node)->size = cnt;
  node->nodt_conn = connob;
  unsigned newcnt = 0;
  for (unsigned ix = 0; ix < nbval; ix++)
    {
      value_tyBM curson = sonvalarr[ix];
      if (valtype_BM (curson))
        {
          hash_tyBM curh = valhash_BM (curson);
          if (newcnt % 2)
            h1 = (h1 * 4561 + 5 * newcnt + (curh & 0xff)) ^ (curh * 5897);
          else
            h2 = (h2 * 18457 - 17 * newcnt) ^ (curh * 12487);
          node->nodt_sons[newcnt++] = curson;
        }
    }
  hash_tyBM h = h1 ^ h2;
  if (!h)                       /* so h1 == h2 */
    h = (17 * (h1 & 0x1fffff) + 3 * (h2 % 21503)) + (newcnt & 0xf) + 120;
  assert (h > 0);
  ((typedhead_tyBM *) node)->hash = h;
  return node;
}                               /* end makenode_BM */



void
nodegcmark_BM (struct garbcoll_stBM *gc, node_tyBM * nod, int depth)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (valtype_BM ((const value_tyBM) nod) == tyNode_BM);
  uint8_t oldmark = ((typedhead_tyBM *) nod)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) nod)->hgc = MARKGC_BM;
  gcobjmark_BM (gc, nod->nodt_conn);
  unsigned size = ((typedsize_tyBM *) nod)->size;
  for (unsigned ix = 0; ix < size; ix++)
    gcmark_BM (gc, nod->nodt_sons[ix], depth + 1);
}                               /* end nodegcmark_BM */
