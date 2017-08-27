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
                  + ((cnt > 0)
                     ? (prime_above_BM (cnt - 1) * sizeof (value_tyBM)) : 0));
  hash_tyBM h1 = objecthash_BM (connob);
  hash_tyBM h2 = cnt;
  ((typedsize_tyBM *) clos)->size = cnt;
  clos->nodt_conn = (objectval_tyBM *) connob;
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

const closure_tyBM *
makeclosurevar_BM (const objectval_tyBM * connob, ...)
{
  if (!isobject_BM ((const value_tyBM) connob))
    return NULL;
  va_list args;
  unsigned nbsons = 0;
  va_start (args, connob);
  while (va_arg (args, value_tyBM) != NULL)
    nbsons++;
  va_end (args);
  if (nbsons >= MAXSIZE_BM)
    FATAL_BM ("too many sons %u", nbsons);
  value_tyBM tinyarr[TINYSIZE_BM] = { };
  value_tyBM *arr =
    (nbsons < TINYSIZE_BM) ? tinyarr : calloc (nbsons, sizeof (value_tyBM));
  if (!arr)
    FATAL_BM ("calloc failure for %u - %m", nbsons);
  unsigned cnt = 0;
  value_tyBM curv = NULL;
  while ((curv = va_arg (args, value_tyBM)) != NULL)
    {
      assert (cnt < nbsons);
      arr[cnt++] = curv;
    }
  const closure_tyBM *clos = makeclosure_BM (connob, nbsons, arr);
  if (arr != tinyarr)
    free (arr);
  return clos;
}                               /* end makeclosurevar_BM */


void
closuregcdestroy_BM (struct garbcoll_stBM *gc, closure_tyBM * clos)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) clos)->htyp == tyClosure_BM);
  unsigned siz = ((typedsize_tyBM *) clos)->size;
  assert (siz < MAXSIZE_BM);
  memset (clos, 0, sizeof (*clos) + siz * sizeof (void *));
  free (clos);
  gc->gc_freedbytes +=          //
    sizeof (*clos) + (siz > 0)
    ? (prime_above_BM (siz - 1) * sizeof (value_tyBM)) : 0;
}                               /* end closuregcdestroy_BM */

void
closuregckeep_BM (struct garbcoll_stBM *gc, closure_tyBM * clos)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) clos)->htyp == tyClosure_BM);
  unsigned siz = ((typedsize_tyBM *) clos)->size;
  assert (siz < MAXSIZE_BM);
  gc->gc_keptbytes +=           //
    sizeof (*clos) + (siz > 0)
    ? (prime_above_BM (siz - 1) * sizeof (value_tyBM)) : 0;
}                               /* end closuregckeep_BM */


void
closuregcmark_BM (struct garbcoll_stBM *gc, closure_tyBM * clos, int depth)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (valtype_BM ((const value_tyBM) clos) == tyClosure_BM);
  uint8_t oldmark = ((typedhead_tyBM *) clos)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) clos)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
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
                  + ((cnt > 0)
                     ? (prime_above_BM (cnt - 1) * sizeof (value_tyBM)) : 0));
  hash_tyBM h1 = objecthash_BM (connob);
  hash_tyBM h2 = cnt;
  ((typedsize_tyBM *) node)->size = cnt;
  node->nodt_conn = (objectval_tyBM *) connob;
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


const node_tyBM *
makenodevar_BM (const objectval_tyBM * connob, ...)
{
  if (!isobject_BM ((const value_tyBM) connob))
    return NULL;
  va_list args;
  unsigned nbsons = 0;
  va_start (args, connob);
  while (va_arg (args, value_tyBM) != NULL)
    nbsons++;
  va_end (args);
  if (nbsons >= MAXSIZE_BM)
    FATAL_BM ("too many sons %u", nbsons);
  value_tyBM tinyarr[TINYSIZE_BM] = { };
  value_tyBM *arr =
    (nbsons < TINYSIZE_BM) ? tinyarr : calloc (nbsons, sizeof (value_tyBM));
  if (!arr)
    FATAL_BM ("calloc failure for %u - %m", nbsons);
  unsigned cnt = 0;
  value_tyBM curv = NULL;
  while ((curv = va_arg (args, value_tyBM)) != NULL)
    {
      assert (cnt < nbsons);
      arr[cnt++] = curv;
    }
  const node_tyBM *clos = makenode_BM (connob, nbsons, arr);
  if (arr != tinyarr)
    free (arr);
  return clos;
}                               /* end makenodevar_BM */


void
nodegcdestroy_BM (struct garbcoll_stBM *gc, node_tyBM * nod)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) nod)->htyp == tyNode_BM);
  unsigned siz = ((typedsize_tyBM *) nod)->size;
  assert (siz < MAXSIZE_BM);
  memset (nod, 0, sizeof (*nod) + siz * sizeof (void *));
  free (nod);
  gc->gc_freedbytes +=          //
    sizeof (*nod) + (siz > 0)
    ? (prime_above_BM (siz - 1) * sizeof (value_tyBM)) : 0;
}                               /* end nodegcdestroy_BM */


void
nodegckeep_BM (struct garbcoll_stBM *gc, node_tyBM * nod)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) nod)->htyp == tyNode_BM);
  unsigned siz = ((typedsize_tyBM *) nod)->size;
  assert (siz < MAXSIZE_BM);
  gc->gc_keptbytes +=           //
    sizeof (*nod) + (siz > 0)
    ? (prime_above_BM (siz - 1) * sizeof (value_tyBM)) : 0;
}                               /* end nodegckeep_BM */



void
nodegcmark_BM (struct garbcoll_stBM *gc, node_tyBM * nod, int depth)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (valtype_BM ((const value_tyBM) nod) == tyNode_BM);
  uint8_t oldmark = ((typedhead_tyBM *) nod)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) nod)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  gcobjmark_BM (gc, nod->nodt_conn);
  unsigned size = ((typedsize_tyBM *) nod)->size;
  for (unsigned ix = 0; ix < size; ix++)
    gcmark_BM (gc, nod->nodt_sons[ix], depth + 1);
}                               /* end nodegcmark_BM */

void
quasinodegcmark_BM (struct garbcoll_stBM *gc, quasinode_tyBM * qnod,
                    int depth)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (istree_BM (qnod));
  /// on purpose, don't mark me
  gcobjmark_BM (gc, qnod->nodt_conn);
  unsigned size = ((typedsize_tyBM *) qnod)->size;
  for (unsigned ix = 0; ix < size; ix++)
    gcmark_BM (gc, qnod->nodt_sons[ix], depth + 1);
}                               /* end quasinodegcmark_BM */


value_tyBM
apply0_BM (const closure_tyBM * clos, struct stackframe_stBM *stkf)
{
  if (!isclosure_BM ((const value_tyBM) clos))
    return NULL;
  const objectval_tyBM *connob = clos->nodt_conn;
  assert (isobject_BM ((const value_tyBM) connob));
  objrout_sigBM *rout = connob->ob_rout;
  if (!rout)
    return NULL;
  return (*rout) (clos, stkf, NULL, NULL, NULL, NULL);
}                               /* end apply0_BM */


value_tyBM
apply1_BM (const closure_tyBM * clos, struct stackframe_stBM * stkf,
           const value_tyBM arg1)
{
  if (!isclosure_BM ((const value_tyBM) clos))
    return NULL;
  const objectval_tyBM *connob = clos->nodt_conn;
  assert (isobject_BM ((const value_tyBM) connob));
  objrout_sigBM *rout = connob->ob_rout;
  if (!rout)
    return NULL;
  return (*rout) (clos, stkf, arg1, NULL, NULL, NULL);
}                               /* end apply1_BM */


value_tyBM
apply2_BM (const closure_tyBM * clos, struct stackframe_stBM * stkf,
           const value_tyBM arg1, const value_tyBM arg2)
{
  if (!isclosure_BM ((const value_tyBM) clos))
    return NULL;
  const objectval_tyBM *connob = clos->nodt_conn;
  assert (isobject_BM ((const value_tyBM) connob));
  objrout_sigBM *rout = connob->ob_rout;
  if (!rout)
    return NULL;
  return (*rout) (clos, stkf, arg1, arg2, NULL, NULL);
}                               /* end apply2_BM */


value_tyBM
apply3_BM (const closure_tyBM * clos, struct stackframe_stBM * stkf,
           const value_tyBM arg1, const value_tyBM arg2,
           const value_tyBM arg3)
{
  if (!isclosure_BM ((const value_tyBM) clos))
    return NULL;
  const objectval_tyBM *connob = clos->nodt_conn;
  assert (isobject_BM ((const value_tyBM) connob));
  objrout_sigBM *rout = connob->ob_rout;
  if (!rout)
    return NULL;
  return (*rout) (clos, stkf, arg1, arg2, arg3, NULL);
}                               /* end apply3_BM */


value_tyBM
apply4_BM (const closure_tyBM * clos, struct stackframe_stBM * stkf,
           const value_tyBM arg1, const value_tyBM arg2,
           const value_tyBM arg3, const value_tyBM arg4)
{
  if (!isclosure_BM ((const value_tyBM) clos))
    return NULL;
  const objectval_tyBM *connob = clos->nodt_conn;
  assert (isobject_BM ((const value_tyBM) connob));
  objrout_sigBM *rout = connob->ob_rout;
  if (!rout)
    return NULL;
  LOCALQNODESIZED_BM (qno, NULL, 1);
  qno.qsons[0] = arg4;
  return (*rout) (clos, stkf, arg1, arg2, arg3,
                  (const quasinode_tyBM *) &qno);
}                               /* end apply4_BM */


value_tyBM
apply5_BM (const closure_tyBM * clos, struct stackframe_stBM *stkf,
           const value_tyBM arg1, const value_tyBM arg2,
           const value_tyBM arg3, const value_tyBM arg4,
           const value_tyBM arg5)
{
  if (!isclosure_BM ((const value_tyBM) clos))
    return NULL;
  const objectval_tyBM *connob = clos->nodt_conn;
  assert (isobject_BM ((const value_tyBM) connob));
  objrout_sigBM *rout = connob->ob_rout;
  if (!rout)
    return NULL;
  LOCALQNODESIZED_BM (qno, NULL, 2);
  qno.qsons[0] = arg4;
  qno.qsons[1] = arg5;
  return (*rout) (clos, stkf, arg1, arg2, arg3,
                  (const quasinode_tyBM *) &qno);
}                               /* end apply5_BM */


value_tyBM
apply6_BM (const closure_tyBM * clos, struct stackframe_stBM *stkf,
           const value_tyBM arg1, const value_tyBM arg2,
           const value_tyBM arg3, const value_tyBM arg4,
           const value_tyBM arg5, const value_tyBM arg6)
{
  if (!isclosure_BM ((const value_tyBM) clos))
    return NULL;
  const objectval_tyBM *connob = clos->nodt_conn;
  assert (isobject_BM ((const value_tyBM) connob));
  objrout_sigBM *rout = connob->ob_rout;
  if (!rout)
    return NULL;
  LOCALQNODESIZED_BM (qno, NULL, 3);
  qno.qsons[0] = arg4;
  qno.qsons[1] = arg5;
  qno.qsons[2] = arg6;
  return (*rout) (clos, stkf, arg1, arg2, arg3,
                  (const quasinode_tyBM *) &qno);
}                               /* end apply6_BM */


value_tyBM
apply7_BM (const closure_tyBM * clos, struct stackframe_stBM *stkf,
           const value_tyBM arg1, const value_tyBM arg2,
           const value_tyBM arg3, const value_tyBM arg4,
           const value_tyBM arg5, const value_tyBM arg6,
           const value_tyBM arg7)
{
  if (!isclosure_BM ((const value_tyBM) clos))
    return NULL;
  const objectval_tyBM *connob = clos->nodt_conn;
  assert (isobject_BM ((const value_tyBM) connob));
  objrout_sigBM *rout = connob->ob_rout;
  if (!rout)
    return NULL;
  LOCALQNODESIZED_BM (qno, NULL, 4);
  qno.qsons[0] = arg4;
  qno.qsons[1] = arg5;
  qno.qsons[2] = arg6;
  qno.qsons[3] = arg7;
  return (*rout) (clos, stkf, arg1, arg2, arg3,
                  (const quasinode_tyBM *) &qno);
}                               /* end apply7_BM */


value_tyBM
apply8_BM (const closure_tyBM * clos, struct stackframe_stBM *stkf,
           const value_tyBM arg1, const value_tyBM arg2,
           const value_tyBM arg3, const value_tyBM arg4,
           const value_tyBM arg5, const value_tyBM arg6,
           const value_tyBM arg7, const value_tyBM arg8)
{
  if (!isclosure_BM ((const value_tyBM) clos))
    return NULL;
  const objectval_tyBM *connob = clos->nodt_conn;
  assert (isobject_BM ((const value_tyBM) connob));
  objrout_sigBM *rout = connob->ob_rout;
  if (!rout)
    return NULL;
  LOCALQNODESIZED_BM (qno, NULL, 4);
  qno.qsons[0] = arg4;
  qno.qsons[1] = arg5;
  qno.qsons[2] = arg6;
  qno.qsons[3] = arg7;
  qno.qsons[4] = arg8;
  return (*rout) (clos, stkf, arg1, arg2, arg3,
                  (const quasinode_tyBM *) &qno);
}                               /* end apply8_BM */


value_tyBM
apply9_BM (const closure_tyBM * clos, struct stackframe_stBM *stkf,
           const value_tyBM arg1, const value_tyBM arg2,
           const value_tyBM arg3, const value_tyBM arg4,
           const value_tyBM arg5, const value_tyBM arg6,
           const value_tyBM arg7, const value_tyBM arg8,
           const value_tyBM arg9)
{
  if (!isclosure_BM ((const value_tyBM) clos))
    return NULL;
  const objectval_tyBM *connob = clos->nodt_conn;
  assert (isobject_BM ((const value_tyBM) connob));
  objrout_sigBM *rout = connob->ob_rout;
  if (!rout)
    return NULL;
  LOCALQNODESIZED_BM (qno, NULL, 5);
  qno.qsons[0] = arg4;
  qno.qsons[1] = arg5;
  qno.qsons[2] = arg6;
  qno.qsons[3] = arg7;
  qno.qsons[4] = arg8;
  qno.qsons[5] = arg9;
  return (*rout) (clos, stkf, arg1, arg2, arg3,
                  (const quasinode_tyBM *) &qno);
}                               /* end apply9_BM */
