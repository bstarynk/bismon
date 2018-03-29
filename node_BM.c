// file node_BM.c

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
  ASSERT_BM (cnt < MAXSIZE_BM);
  unsigned long closiz =
    sizeof (closure_tyBM)
    + ((cnt > 0) ? (prime_above_BM (cnt - 1) * sizeof (value_tyBM)) : 0);
  ASSERT_BM (closiz < (4L * MAXSIZE_BM / 3 + 5L) * sizeof (void *));
  closure_tyBM *clos =          //
    allocgcty_BM (tyClosure_BM, closiz);
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
  ASSERT_BM (h > 0);
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
  va_start (args, connob);
  while ((curv = va_arg (args, value_tyBM)) != NULL)
    {
      ASSERT_BM (cnt < nbsons);
      arr[cnt++] = curv;
    }
  va_end (args);
  const closure_tyBM *clos = makeclosure_BM (connob, nbsons, arr);
  if (arr != tinyarr)
    free (arr), arr = NULL;
  return clos;
}                               /* end makeclosurevar_BM */


void
closuregcdestroy_BM (struct garbcoll_stBM *gc, closure_tyBM * clos)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) clos)->htyp == tyClosure_BM);
  unsigned siz = ((typedsize_tyBM *) clos)->size;
  ASSERT_BM (siz < MAXSIZE_BM);
  memset (clos, 0, sizeof (*clos) + siz * sizeof (void *));
  free (clos), clos = NULL;
  unsigned long closiz =
    sizeof (*clos)
    + ((siz > 0) ? (prime_above_BM (siz - 1) * sizeof (value_tyBM)) : 0);
  ASSERT_BM (closiz < (4L * MAXSIZE_BM / 3 + 5L) * sizeof (void *));
  gc->gc_freedbytes += closiz;
}                               /* end closuregcdestroy_BM */

void
closuregckeep_BM (struct garbcoll_stBM *gc, closure_tyBM * clos)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) clos)->htyp == tyClosure_BM);
  unsigned siz = ((typedsize_tyBM *) clos)->size;
  ASSERT_BM (siz < MAXSIZE_BM);
  unsigned long closiz =
    sizeof (*clos)
    + ((siz > 0) ? (prime_above_BM (siz - 1) * sizeof (value_tyBM)) : 0);
  ASSERT_BM (closiz < (4L * MAXSIZE_BM / 3 + 5L) * sizeof (void *));
  gc->gc_keptbytes += closiz;
}                               /* end closuregckeep_BM */


void *
closuregcproc_BM (struct garbcoll_stBM *gc, closure_tyBM * clos, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((const value_tyBM) clos) == tyClosure_BM);
#warning closuregcproc_BM should forward when needed
  uint8_t oldmark = ((typedhead_tyBM *) clos)->hgc;
  if (oldmark)
    return clos;
  ((typedhead_tyBM *) clos)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  gcobjmark_BM (gc, clos->nodt_conn);
  unsigned size = ((typedsize_tyBM *) clos)->size;
  for (unsigned ix = 0; ix < size; ix++)
    VALUEGCPROC_BM (gc, clos->nodt_sons[ix], depth + 1);
  return clos;
}                               /* end nodegcproc_BM */





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
  ASSERT_BM (cnt < MAXSIZE_BM);
  unsigned long nodsiz =
    sizeof (node_tyBM)
    + ((cnt > 0) ? (prime_above_BM (cnt - 1) * sizeof (value_tyBM)) : 0);
  ASSERT_BM (nodsiz < (4L * MAXSIZE_BM / 3 + 5L) * sizeof (void *));
  closure_tyBM *node =          //
    allocgcty_BM (tyNode_BM, nodsiz);
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
  ASSERT_BM (h > 0);
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
  va_start (args, connob);
  while ((curv = va_arg (args, value_tyBM)) != NULL)
    {
      ASSERT_BM (cnt < nbsons);
      arr[cnt++] = curv;
    }
  va_end (args);
  const node_tyBM *clos = makenode_BM (connob, nbsons, arr);
  if (arr != tinyarr)
    free (arr), arr = NULL;
  return clos;
}                               /* end makenodevar_BM */


void
nodegcdestroy_BM (struct garbcoll_stBM *gc, node_tyBM * nod)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) nod)->htyp == tyNode_BM);
  unsigned siz = ((typedsize_tyBM *) nod)->size;
  ASSERT_BM (siz < MAXSIZE_BM);
  unsigned long nodsiz =
    sizeof (*nod) + ((siz > 0)
                     ? (prime_above_BM (siz - 1) * sizeof (value_tyBM)) : 0);
  ASSERT_BM (nodsiz < (4L * MAXSIZE_BM / 3 + 5L) * sizeof (void *));
  memset (nod, 0, sizeof (*nod) + siz * sizeof (void *));
  free (nod);
  gc->gc_freedbytes += nodsiz;
}                               /* end nodegcdestroy_BM */


void
nodegckeep_BM (struct garbcoll_stBM *gc, node_tyBM * nod)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) nod)->htyp == tyNode_BM);
  unsigned siz = ((typedsize_tyBM *) nod)->size;
  ASSERT_BM (siz < MAXSIZE_BM);
  unsigned long nodsiz =
    sizeof (*nod) + ((siz > 0)
                     ? (prime_above_BM (siz - 1) * sizeof (value_tyBM)) : 0);
  ASSERT_BM (nodsiz < (4L * MAXSIZE_BM / 3 + 5L) * sizeof (void *));
  gc->gc_keptbytes += nodsiz;
}                               /* end nodegckeep_BM */



void *
nodegcproc_BM (struct garbcoll_stBM *gc, node_tyBM * nod, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((const value_tyBM) nod) == tyNode_BM);
#warning nodegcproc_BM should forward when needed
  uint8_t oldmark = ((typedhead_tyBM *) nod)->hgc;
  if (oldmark)
    return nod;
  ((typedhead_tyBM *) nod)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  gcobjmark_BM (gc, nod->nodt_conn);
  unsigned size = ((typedsize_tyBM *) nod)->size;
  for (unsigned ix = 0; ix < size; ix++)
    VALUEGCPROC_BM (gc, nod->nodt_sons[ix], depth + 1);
  return nod;
}                               /* end nodegcmark_BM */

void *
quasinodegcproc_BM (struct garbcoll_stBM *gc, quasinode_tyBM * qnod,
                    int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (istree_BM (qnod));
  /// on purpose, don't mark me
  gcobjmark_BM (gc, qnod->nodt_conn);
  unsigned size = ((typedsize_tyBM *) qnod)->size;
  for (unsigned ix = 0; ix < size; ix++)
    VALUEGCPROC_BM (gc, qnod->nodt_sons[ix], depth + 1);
  return qnod;
}                               /* end quasinodegcproc_BM */


value_tyBM
apply0_BM (const value_tyBM funv, struct stackframe_stBM * stkf)
{
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      const objectval_tyBM *connob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) connob));
      rout = (objrout_sigBM *) objroutaddr_BM (connob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    rout = (objrout_sigBM *) objroutaddr_BM (funv, BMP_function_sig);
  else
    return NULL;
  if (!rout)
    return NULL;
  stkf->stkfram_callfun = funv;
  return (*rout) (stkf, NULL, NULL, NULL, NULL, NULL);
}                               /* end apply0_BM */


value_tyBM
apply1_BM (const value_tyBM funv, struct stackframe_stBM * stkf,
           const value_tyBM arg1)
{
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      const objectval_tyBM *connob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) connob));
      rout = (objrout_sigBM *) objroutaddr_BM (connob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    rout = (objrout_sigBM *) objroutaddr_BM (funv, BMP_function_sig);
  else
    return NULL;
  if (!rout)
    return NULL;
  stkf->stkfram_callfun = funv;
  return (*rout) (stkf, arg1, NULL, NULL, NULL, NULL);
}                               /* end apply1_BM */


value_tyBM
apply2_BM (const value_tyBM funv, struct stackframe_stBM * stkf,
           const value_tyBM arg1, const value_tyBM arg2)
{
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      const objectval_tyBM *connob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) connob));
      rout = (objrout_sigBM *) objroutaddr_BM (connob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    rout = (objrout_sigBM *) objroutaddr_BM (funv, BMP_function_sig);
  else
    return NULL;
  if (!rout)
    return NULL;
  stkf->stkfram_callfun = funv;
  return (*rout) (stkf, arg1, arg2, NULL, NULL, NULL);
}                               /* end apply2_BM */


value_tyBM
apply3_BM (const value_tyBM funv, struct stackframe_stBM * stkf,
           const value_tyBM arg1, const value_tyBM arg2,
           const value_tyBM arg3)
{
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      const objectval_tyBM *connob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) connob));
      rout = (objrout_sigBM *) objroutaddr_BM (connob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    rout = (objrout_sigBM *) objroutaddr_BM (funv, BMP_function_sig);
  else
    return NULL;
  if (!rout)
    return NULL;
  stkf->stkfram_callfun = funv;
  return (*rout) (stkf, arg1, arg2, arg3, NULL, NULL);
}                               /* end apply3_BM */


value_tyBM
apply4_BM (const value_tyBM funv, struct stackframe_stBM * stkf,
           const value_tyBM arg1, const value_tyBM arg2,
           const value_tyBM arg3, const value_tyBM arg4)
{
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      const objectval_tyBM *connob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) connob));
      rout = (objrout_sigBM *) objroutaddr_BM (connob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    rout = (objrout_sigBM *) objroutaddr_BM (funv, BMP_function_sig);
  else
    return NULL;
  if (!rout)
    return NULL;
  stkf->stkfram_callfun = funv;
  return (*rout) (stkf, arg1, arg2, arg3, arg4, NULL);
}                               /* end apply4_BM */


value_tyBM
apply5_BM (const value_tyBM funv, struct stackframe_stBM * stkf,
           const value_tyBM arg1, const value_tyBM arg2,
           const value_tyBM arg3, const value_tyBM arg4,
           const value_tyBM arg5)
{
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      const objectval_tyBM *connob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) connob));
      rout = (objrout_sigBM *) objroutaddr_BM (connob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    rout = (objrout_sigBM *) objroutaddr_BM (funv, BMP_function_sig);
  else
    return NULL;
  if (!rout)
    return NULL;
  LOCALQNODESIZED_BM (qno, NULL, 1);
  qno.qsons[0] = arg5;
  stkf->stkfram_callfun = funv;
  return (*rout) (stkf, arg1, arg2, arg3, arg4,
                  (const quasinode_tyBM *) &qno);
}                               /* end apply5_BM */


value_tyBM
apply6_BM (const value_tyBM funv, struct stackframe_stBM *stkf,
           const value_tyBM arg1, const value_tyBM arg2,
           const value_tyBM arg3, const value_tyBM arg4,
           const value_tyBM arg5, const value_tyBM arg6)
{
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      const objectval_tyBM *connob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) connob));
      rout = (objrout_sigBM *) objroutaddr_BM (connob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    rout = (objrout_sigBM *) objroutaddr_BM (funv, BMP_function_sig);
  else
    return NULL;
  if (!rout)
    return NULL;
  LOCALQNODESIZED_BM (qno, NULL, 2);
  qno.qsons[0] = arg5;
  qno.qsons[1] = arg6;
  stkf->stkfram_callfun = funv;
  return (*rout) (stkf, arg1, arg2, arg3, arg4,
                  (const quasinode_tyBM *) &qno);
}                               /* end apply6_BM */


value_tyBM
apply7_BM (const value_tyBM funv, struct stackframe_stBM *stkf,
           const value_tyBM arg1, const value_tyBM arg2,
           const value_tyBM arg3, const value_tyBM arg4,
           const value_tyBM arg5, const value_tyBM arg6,
           const value_tyBM arg7)
{
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      const objectval_tyBM *connob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) connob));
      rout = (objrout_sigBM *) objroutaddr_BM (connob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    rout = (objrout_sigBM *) objroutaddr_BM (funv, BMP_function_sig);
  else
    return NULL;
  if (!rout)
    return NULL;
  LOCALQNODESIZED_BM (qno, NULL, 3);
  qno.qsons[0] = arg5;
  qno.qsons[1] = arg6;
  qno.qsons[2] = arg7;
  stkf->stkfram_callfun = funv;
  return (*rout) (stkf, arg1, arg2, arg3, arg4,
                  (const quasinode_tyBM *) &qno);
}                               /* end apply7_BM */


value_tyBM
apply8_BM (const value_tyBM funv, struct stackframe_stBM *stkf,
           const value_tyBM arg1, const value_tyBM arg2,
           const value_tyBM arg3, const value_tyBM arg4,
           const value_tyBM arg5, const value_tyBM arg6,
           const value_tyBM arg7, const value_tyBM arg8)
{
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      const objectval_tyBM *connob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) connob));
      rout = (objrout_sigBM *) objroutaddr_BM (connob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    rout = (objrout_sigBM *) objroutaddr_BM (funv, BMP_function_sig);
  else
    return NULL;
  if (!rout)
    return NULL;
  LOCALQNODESIZED_BM (qno, NULL, 4);
  qno.qsons[0] = arg5;
  qno.qsons[1] = arg6;
  qno.qsons[2] = arg7;
  qno.qsons[3] = arg8;
  stkf->stkfram_callfun = funv;
  return (*rout) (stkf, arg1, arg2, arg3, arg4,
                  (const quasinode_tyBM *) &qno);
}                               /* end apply8_BM */


value_tyBM
apply9_BM (const value_tyBM funv, struct stackframe_stBM *stkf,
           const value_tyBM arg1, const value_tyBM arg2,
           const value_tyBM arg3, const value_tyBM arg4,
           const value_tyBM arg5, const value_tyBM arg6,
           const value_tyBM arg7, const value_tyBM arg8,
           const value_tyBM arg9)
{
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      const objectval_tyBM *connob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) connob));
      rout = (objrout_sigBM *) objroutaddr_BM (connob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    rout = (objrout_sigBM *) objroutaddr_BM (funv, BMP_function_sig);
  else
    return NULL;
  if (!rout)
    return NULL;
  LOCALQNODESIZED_BM (qno, NULL, 5);
  qno.qsons[0] = arg5;
  qno.qsons[1] = arg6;
  qno.qsons[2] = arg7;
  qno.qsons[3] = arg8;
  qno.qsons[4] = arg9;
  stkf->stkfram_callfun = funv;
  return (*rout) (stkf, arg1, arg2, arg3, arg4,
                  (const quasinode_tyBM *) &qno);
}                               /* end apply9_BM */


value_tyBM
applyvar_BM (const value_tyBM funv, struct stackframe_stBM *stkf,
             unsigned nbargs, const value_tyBM * argarr)
{
  if (nbargs > MAXAPPLYARGS_BM)
    return NULL;
  if (nbargs > 0 && !argarr)
    return NULL;
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      const objectval_tyBM *connob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) connob));
      rout = (objrout_sigBM *) objroutaddr_BM (connob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    rout = (objrout_sigBM *) objroutaddr_BM (funv, BMP_function_sig);
  else
    return NULL;
  if (!rout)
    return NULL;
  stkf->stkfram_callfun = funv;
  switch (nbargs)
    {
    case 0:
      return (*rout) (stkf, NULL, NULL, NULL, NULL, NULL);
    case 1:
      return (*rout) (stkf, argarr[0], NULL, NULL, NULL, NULL);
    case 2:
      return (*rout) (stkf, argarr[0], argarr[1], NULL, NULL, NULL);
    case 3:
      return (*rout) (stkf, argarr[0], argarr[1], argarr[2], NULL, NULL);
    case 4:
      return (*rout) (stkf, argarr[0], argarr[1], argarr[2], argarr[3], NULL);
    default:
      {
        LOCALQNODESIZED_BM (qno, NULL, MAXAPPLYARGS_BM - 3);
        memcpy (qno.qsons, argarr + 4, nbargs - 4);
        return (*rout) (stkf, argarr[0], argarr[1], argarr[2], argarr[3],
                        (const quasinode_tyBM *) &qno);
      }
    }
  return NULL;
}                               /* end applyvar_BM */
