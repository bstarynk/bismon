// file node_BM.c
// SPDX-License-Identifier: GPL-3.0-or-later
/***
    BISMON 
    Copyright © 2018-2022 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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
    if (!closvalarr[ix] || valtype_BM (closvalarr[ix]))
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
      if (!curson || valtype_BM (curson))
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

const closure_tyBM *
makesizedclosure_BM (unsigned siz, const objectval_tyBM * connob, ...)
{
  if (!isobject_BM ((const value_tyBM) connob))
    return NULL;
  if (siz > MAXSIZE_BM)
    FATAL_BM ("too large closure size %u", siz);
  value_tyBM tinyarr[TINYSIZE_BM] = { };
  value_tyBM *arr =
    (siz < TINYSIZE_BM) ? tinyarr : calloc (siz, sizeof (value_tyBM));
  if (!arr)
    FATAL_BM ("calloc failure for %u - %m", siz);
  if (siz > 0)
    {
      va_list args;
      va_start (args, connob);
      for (unsigned ix = 0; ix < siz; ix++)
        arr[ix] = va_arg (args, value_tyBM);
      va_end (args);
    }
  const closure_tyBM *clo = makeclosure_BM (connob, siz, arr);
  if (arr != tinyarr)
    free (arr), arr = NULL;
  return clo;
}                               /* end makesizedclosure_BM */


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
    if (!sonvalarr[ix] || valtype_BM (sonvalarr[ix]))
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
      if (!curson || valtype_BM (curson))
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
makesizednode_BM (unsigned siz, const objectval_tyBM * connob, ...)
{
  if (!isobject_BM ((const value_tyBM) connob))
    return NULL;
  if (siz > MAXSIZE_BM)
    FATAL_BM ("too large node size %u", siz);
  value_tyBM tinyarr[TINYSIZE_BM] = { };
  value_tyBM *arr =
    (siz < TINYSIZE_BM) ? tinyarr : calloc (siz, sizeof (value_tyBM));
  if (!arr)
    FATAL_BM ("calloc failure for %u - %m", siz);
  if (siz > 0)
    {
      va_list args;
      va_start (args, connob);
      for (unsigned ix = 0; ix < siz; ix++)
        arr[ix] = va_arg (args, value_tyBM);
      va_end (args);
    }
  const node_tyBM *nod = makenode_BM (connob, siz, arr);
  if (arr != tinyarr)
    free (arr), arr = NULL;
  return nod;
}                               /* end makesizednode_BM */


/// make a node from the rest of some tree (node, closure or quasinode) value, with a starting index startix
const node_tyBM *
makenodetreerest_BM (const objectval_tyBM * connob, value_tyBM treev,
                     int startix)
{
  if (!isobject_BM ((const value_tyBM) connob))
    return NULL;
  if (!istree_BM ((const value_tyBM) treev))
    return NULL;
  unsigned w = treewidth_BM ((const value_tyBM) treev);
  if (startix < 0)
    startix += (int) w;
  if (startix >= 0 && startix < (int) w)
    return makenode_BM (connob, w - startix,
                        treecast_BM (treev)->nodt_sons + startix);
  else
    return NULL;
}                               /* end makenodetreerest_BM */


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
  const node_tyBM *nod = makenode_BM (connob, nbsons, arr);
  if (arr != tinyarr)
    free (arr), arr = NULL;
  return nod;
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
apply0_BM (const value_tyBM funv, struct stackframe_stBM *stkf)
{
  objectval_tyBM *ob = NULL;
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      ob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) ob));
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    {
      ob = (objectval_tyBM *) funv;
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    }
  else
    return NULL;
  if (ob && !rout)
    rout = try_dlsym_routine_BM (ob);
  if (!rout || rout == crashing_objrout_BM || rout == warning_objrout_BM)
    {
      if (ob)
        WARNPRINTF_BM ("apply0 funv: %s object %s with bad routine",
                       debug_outstr_value_BM (funv, stkf, 0),
                       objectdbg_BM (ob));
      else
        WARNPRINTF_BM ("apply0 funv: %s bad function",
                       debug_outstr_value_BM (funv, stkf, 0));
      if (!rout)
        return NULL;
    };
  stkf->stkfram_callfun = funv;
  return (*rout) (stkf, NULL, NULL, NULL, NULL, NULL);
}                               /* end apply0_BM */


value_tyBM
apply1_BM (const value_tyBM funv, struct stackframe_stBM *stkf,
           const value_tyBM arg1)
{
  objectval_tyBM *ob = NULL;
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      ob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) ob));
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    {
      ob = (objectval_tyBM *) funv;
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    }
  else
    return NULL;
  if (ob && !rout)
    rout = try_dlsym_routine_BM (ob);
  if (!rout || rout == crashing_objrout_BM || rout == warning_objrout_BM)
    {
      if (ob)
        WARNPRINTF_BM ("apply1 funv: %s arg1 %s object %s with bad routine",
                       debug_outstr_value_BM (funv, stkf, 0),
                       debug_outstr_value_BM (arg1, stkf, 0),
                       objectdbg_BM (ob));
      else
        WARNPRINTF_BM ("apply1 funv: %s arg1 %s bad function",
                       debug_outstr_value_BM (funv, stkf, 0),
                       debug_outstr_value_BM (arg1, stkf, 0));
      if (!rout)
        return NULL;
    }
  stkf->stkfram_callfun = funv;
  return (*rout) (stkf, arg1, NULL, NULL, NULL, NULL);
}                               /* end apply1_BM */


value_tyBM
apply2_BM (const value_tyBM funv, struct stackframe_stBM *stkf,
           const value_tyBM arg1, const value_tyBM arg2)
{
  objectval_tyBM *ob = NULL;
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      ob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) ob));
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    {
      ob = (objectval_tyBM *) funv;
      rout = (objrout_sigBM *) objroutaddr_BM (funv, BMP_function_sig);
    }
  else
    return NULL;
  if (ob && !rout)
    rout = try_dlsym_routine_BM (ob);
  if (!rout || rout == crashing_objrout_BM || rout == warning_objrout_BM)
    {
      if (ob)
        WARNPRINTF_BM
          ("apply2 funv: %s arg1 %s arg2 %s object %s with bad routine",
           debug_outstr_value_BM (funv, stkf, 0), debug_outstr_value_BM (arg1,
                                                                         stkf,
                                                                         0),
           debug_outstr_value_BM (arg2, stkf, 0), objectdbg_BM (ob));
      else
        WARNPRINTF_BM ("apply2 funv: %s arg1 %s arg2 %s bad function",
                       debug_outstr_value_BM (funv, stkf, 0),
                       debug_outstr_value_BM (arg1, stkf, 0),
                       debug_outstr_value_BM (arg2, stkf, 0));
      if (!rout)
        return NULL;
    }
  stkf->stkfram_callfun = funv;
  return (*rout) (stkf, arg1, arg2, NULL, NULL, NULL);
}                               /* end apply2_BM */


value_tyBM
apply3_BM (const value_tyBM funv, struct stackframe_stBM *stkf,
           const value_tyBM arg1, const value_tyBM arg2,
           const value_tyBM arg3)
{
  objectval_tyBM *ob = NULL;
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      ob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) ob));
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    {
      ob = (objectval_tyBM *) funv;
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    }
  else
    return NULL;
  if (ob && !rout)
    rout = try_dlsym_routine_BM (ob);
  if (!rout || rout == crashing_objrout_BM || rout == warning_objrout_BM)
    {
      if (ob)
        WARNPRINTF_BM
          ("apply2 funv: %s arg1 %s arg2 %s object %s with bad routine",
           debug_outstr_value_BM (funv, stkf, 0), debug_outstr_value_BM (arg1,
                                                                         stkf,
                                                                         0),
           debug_outstr_value_BM (arg2, stkf, 0), objectdbg_BM (ob));
      else
        WARNPRINTF_BM ("apply2 funv: %s arg1: %s, arg2: %s, bad function",
                       debug_outstr_value_BM (funv, stkf, 0),
                       debug_outstr_value_BM (arg1, stkf, 0),
                       debug_outstr_value_BM (arg2, stkf, 0));
      if (!rout)
        return NULL;
    }
  stkf->stkfram_callfun = funv;
  return (*rout) (stkf, arg1, arg2, arg3, NULL, NULL);
}                               /* end apply3_BM */


value_tyBM
apply4_BM (const value_tyBM funv, struct stackframe_stBM *stkf,
           const value_tyBM arg1, const value_tyBM arg2,
           const value_tyBM arg3, const value_tyBM arg4)
{
  objectval_tyBM *ob = NULL;
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      ob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) ob));
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    {
      ob = (objectval_tyBM *) funv;
      rout = (objrout_sigBM *) objroutaddr_BM (funv, BMP_function_sig);
    }
  else
    return NULL;
  if (ob && !rout)
    rout = try_dlsym_routine_BM (ob);
  if (!rout || rout == crashing_objrout_BM || rout == warning_objrout_BM)
    {
      if (ob)
        WARNPRINTF_BM
          ("apply4 funv: %s arg1: %s, arg2: %s, arg3: %s, arg4: %s, object %s with bad routine",
           debug_outstr_value_BM (funv, stkf, 0),
           debug_outstr_value_BM (arg1, stkf, 0),
           debug_outstr_value_BM (arg2, stkf, 0),
           debug_outstr_value_BM (arg3, stkf, 0),
           debug_outstr_value_BM (arg4, stkf, 0), objectdbg_BM (ob));
      if (!rout)
        return NULL;
    }
  stkf->stkfram_callfun = funv;
  return (*rout) (stkf, arg1, arg2, arg3, arg4, NULL);
}                               /* end apply4_BM */


value_tyBM
apply4more_BM (const value_tyBM funv, struct stackframe_stBM *stkf,
               const value_tyBM arg1, const value_tyBM arg2,
               const value_tyBM arg3, const value_tyBM arg4,
               const value_tyBM argmore)
{
  objectval_tyBM *ob = NULL;
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  if (isclosure_BM (funv))
    {
      ob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) ob));
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    {
      ob = (objectval_tyBM *) funv;
      rout = (objrout_sigBM *) objroutaddr_BM (funv, BMP_function_sig);
    }
  else
    return NULL;
  value_tyBM morev = (value_tyBM) treecast_BM (argmore);
  if (ob && !rout)
    rout = try_dlsym_routine_BM (ob);
  if (!rout || rout == crashing_objrout_BM || rout == warning_objrout_BM)
    {
      if (ob)
        WARNPRINTF_BM
          ("apply4more_BM funv: %s arg1 %s arg2 %s arg3 %s arg4 %s morev %s object %s with bad routine",
           debug_outstr_value_BM (funv, stkf, 0),
           debug_outstr_value_BM (arg1, stkf, 0),
           debug_outstr_value_BM (arg2, stkf, 0),
           debug_outstr_value_BM (arg3, stkf, 0),
           debug_outstr_value_BM (arg4, stkf, 0),
           debug_outstr_value_BM (morev, stkf, 0), objectdbg_BM (ob));
      if (!rout)
        return NULL;
    }
  stkf->stkfram_callfun = funv;
  return (*rout) (stkf, arg1, arg2, arg3, arg4, morev);
}                               /* end apply4more_BM */


value_tyBM
apply5_BM (const value_tyBM funv, struct stackframe_stBM *stkf,
           const value_tyBM arg1, const value_tyBM arg2,
           const value_tyBM arg3, const value_tyBM arg4,
           const value_tyBM arg5)
{
  objectval_tyBM *ob = NULL;
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      ob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) ob));
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    {
      ob = (objectval_tyBM *) funv;
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    }
  if (ob && !rout)
    rout = try_dlsym_routine_BM (ob);
  LOCALQNODESIZED_BM (qno, NULL, 1);
  qno.qsons[0] = arg5;
  if (!rout || rout == crashing_objrout_BM || rout == warning_objrout_BM)
    {
      if (ob)
        WARNPRINTF_BM
          ("apply5_BM funv: %s arg1: %s, arg2: %s, arg3: %s, arg4: %s, arg5: %s object %s with bad routine",
           debug_outstr_value_BM (funv, stkf, 0),
           debug_outstr_value_BM (arg1, stkf, 0),
           debug_outstr_value_BM (arg2, stkf, 0),
           debug_outstr_value_BM (arg3, stkf, 0),
           debug_outstr_value_BM (arg4, stkf, 0),
           debug_outstr_value_BM (arg5, stkf, 0), objectdbg_BM (ob));
      else if (ob)
        WARNPRINTF_BM
          ("apply5_BM funv: %s arg1: %s, arg2: %s, arg3: %s, arg4: %s, arg5: %s bad routine",
           debug_outstr_value_BM (funv, stkf, 0),
           debug_outstr_value_BM (arg1, stkf, 0),
           debug_outstr_value_BM (arg2, stkf, 0),
           debug_outstr_value_BM (arg3, stkf, 0),
           debug_outstr_value_BM (arg4, stkf, 0),
           debug_outstr_value_BM (arg5, stkf, 0));
      if (!rout)
        return NULL;
    }
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
  objectval_tyBM *ob = NULL;
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      ob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) ob));
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    {
      ob = (objectval_tyBM *) funv;
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    };
  if (ob && !rout)
    rout = try_dlsym_routine_BM (ob);
  LOCALQNODESIZED_BM (qno, NULL, 2);
  qno.qsons[0] = arg5;
  qno.qsons[1] = arg6;
  if (!rout || rout == crashing_objrout_BM || rout == warning_objrout_BM)
    {
      if (ob)
        WARNPRINTF_BM ("apply6_BM funv: %s arg1: %s, arg2: %s, arg3: %s, arg4: %s, arg5: %s, arg6: %s object %s with bad routine", debug_outstr_value_BM (funv, stkf, 0), debug_outstr_value_BM (arg1, stkf, 0), debug_outstr_value_BM (arg2, stkf, 0), debug_outstr_value_BM (arg3, stkf, 0), debug_outstr_value_BM (arg4, stkf, 0), debug_outstr_value_BM (arg5, stkf, 0), debug_outstr_value_BM (arg6, stkf, 0),     //
                       objectdbg_BM (ob));
      else if (ob)
        WARNPRINTF_BM
          ("apply6_BM funv: %s arg1: %s, arg2: %s, arg3: %s, arg4: %s, arg5: %s, arg6: %s bad routine",
           debug_outstr_value_BM (funv, stkf, 0),
           debug_outstr_value_BM (arg1, stkf, 0),
           debug_outstr_value_BM (arg2, stkf, 0),
           debug_outstr_value_BM (arg3, stkf, 0),
           debug_outstr_value_BM (arg4, stkf, 0),
           debug_outstr_value_BM (arg5, stkf, 0),
           debug_outstr_value_BM (arg6, stkf, 0));
      if (!rout)
        return NULL;
    }
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
  objectval_tyBM *ob = NULL;
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      ob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) ob));
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    {
      ob = (objectval_tyBM *) funv;
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    };
  if (ob && !rout)
    rout = try_dlsym_routine_BM (ob);
  if (!rout || rout == crashing_objrout_BM || rout == warning_objrout_BM)
    {
      if (ob)
        WARNPRINTF_BM
          ("apply7_BM funv: %s arg1: %s, arg2: %s, arg3: %s, arg4: %s, arg5: %s, arg6: %s, arg7: %s object %s with bad routine",
           debug_outstr_value_BM (funv, stkf, 0),
           debug_outstr_value_BM (arg1, stkf, 0),
           debug_outstr_value_BM (arg2, stkf, 0),
           debug_outstr_value_BM (arg3, stkf, 0),
           debug_outstr_value_BM (arg4, stkf, 0),
           debug_outstr_value_BM (arg5, stkf, 0),
           debug_outstr_value_BM (arg6, stkf, 0),
           debug_outstr_value_BM (arg7, stkf, 0), objectdbg_BM (ob));
      else if (ob)
        WARNPRINTF_BM
          ("apply7_BM funv: %s arg1: %s, arg2: %s, arg3: %s, arg4: %s, arg5: %s, arg6: %s, arg7: %s bad routine",
           debug_outstr_value_BM (funv, stkf, 0),
           debug_outstr_value_BM (arg1, stkf, 0),
           debug_outstr_value_BM (arg2, stkf, 0),
           debug_outstr_value_BM (arg3, stkf, 0),
           debug_outstr_value_BM (arg4, stkf, 0),
           debug_outstr_value_BM (arg5, stkf, 0),
           debug_outstr_value_BM (arg6, stkf, 0),
           debug_outstr_value_BM (arg7, stkf, 0));
      if (!rout)
        return NULL;
    }
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
  objectval_tyBM *ob = NULL;
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      ob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) ob));
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    {
      ob = (objectval_tyBM *) funv;
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    };
  if (ob && !rout)
    rout = try_dlsym_routine_BM (ob);
  if (!rout || rout == crashing_objrout_BM || rout == warning_objrout_BM)
    {
      if (ob)
        WARNPRINTF_BM
          ("apply8_BM funv: %s arg1: %s, arg2: %s, arg3: %s, arg4: %s, arg5: %s, arg6: %s, arg7: %s, arg8: %s object %s with bad routine",
           debug_outstr_value_BM (funv, stkf, 0),
           debug_outstr_value_BM (arg1, stkf, 0),
           debug_outstr_value_BM (arg2, stkf, 0),
           debug_outstr_value_BM (arg3, stkf, 0),
           debug_outstr_value_BM (arg4, stkf, 0),
           debug_outstr_value_BM (arg5, stkf, 0),
           debug_outstr_value_BM (arg6, stkf, 0),
           debug_outstr_value_BM (arg7, stkf, 0),
           debug_outstr_value_BM (arg8, stkf, 0), objectdbg_BM (ob));
      else if (ob)
        WARNPRINTF_BM
          ("apply8_BM funv: %s arg1: %s, arg2: %s, arg3: %s, arg4: %s, arg5: %s, arg6: %s, arg7: %s, arg8: %s bad routine",
           debug_outstr_value_BM (funv, stkf, 0),
           debug_outstr_value_BM (arg1, stkf, 0),
           debug_outstr_value_BM (arg2, stkf, 0),
           debug_outstr_value_BM (arg3, stkf, 0),
           debug_outstr_value_BM (arg4, stkf, 0),
           debug_outstr_value_BM (arg5, stkf, 0),
           debug_outstr_value_BM (arg6, stkf, 0),
           debug_outstr_value_BM (arg7, stkf, 0),
           debug_outstr_value_BM (arg8, stkf, 0));
      if (!rout)
        return NULL;
    }
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
  objectval_tyBM *ob = NULL;
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      ob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) ob));
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    {
      ob = ((closure_tyBM *) funv)->nodt_conn;
      rout = (objrout_sigBM *) objroutaddr_BM (funv, BMP_function_sig);
    };
  if (ob && !rout)
    rout = try_dlsym_routine_BM (ob);
  if (!rout || rout == crashing_objrout_BM || rout == warning_objrout_BM)
    {
      if (ob)
        WARNPRINTF_BM
          ("apply9_BM funv: %s arg1: %s, arg2: %s, arg3: %s, arg4: %s, arg5: %s, arg6: %s, arg7: %s, arg8: %s, arg9: %s object %s with bad routine",
           debug_outstr_value_BM (funv, stkf, 0),
           debug_outstr_value_BM (arg1, stkf, 0),
           debug_outstr_value_BM (arg2, stkf, 0),
           debug_outstr_value_BM (arg3, stkf, 0),
           debug_outstr_value_BM (arg4, stkf, 0),
           debug_outstr_value_BM (arg5, stkf, 0),
           debug_outstr_value_BM (arg6, stkf, 0),
           debug_outstr_value_BM (arg7, stkf, 0),
           debug_outstr_value_BM (arg8, stkf, 0),
           debug_outstr_value_BM (arg9, stkf, 0), objectdbg_BM (ob));
      else if (ob)
        WARNPRINTF_BM
          ("apply9_BM funv: %s arg1: %s, arg2: %s, arg3: %s, arg4: %s, arg5: %s, arg6: %s, arg7: %s, arg8: %s, arg9: %s bad routine",
           debug_outstr_value_BM (funv, stkf, 0),
           debug_outstr_value_BM (arg1, stkf, 0),
           debug_outstr_value_BM (arg2, stkf, 0),
           debug_outstr_value_BM (arg3, stkf, 0),
           debug_outstr_value_BM (arg4, stkf, 0),
           debug_outstr_value_BM (arg5, stkf, 0),
           debug_outstr_value_BM (arg6, stkf, 0),
           debug_outstr_value_BM (arg7, stkf, 0),
           debug_outstr_value_BM (arg8, stkf, 0),
           debug_outstr_value_BM (arg9, stkf, 0));
      if (!rout)
        return NULL;
    }
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
  objectval_tyBM *ob = NULL;
  if (nbargs > MAXAPPLYARGS_BM)
    return NULL;
  if (nbargs > 0 && !argarr)
    return NULL;
  ASSERT_BM (stkf && ((typedhead_tyBM *) stkf)->htyp == typayl_StackFrame_BM);
  objrout_sigBM *rout = NULL;
  if (isclosure_BM (funv))
    {
      ob = ((closure_tyBM *) funv)->nodt_conn;
      ASSERT_BM (isobject_BM ((const value_tyBM) ob));
      rout = (objrout_sigBM *) objroutaddr_BM (ob, BMP_function_sig);
    }
  else if (isobject_BM (funv))
    {
      ob = (objectval_tyBM *) funv;
      rout = (objrout_sigBM *) objroutaddr_BM (funv, BMP_function_sig);
    };
  if (ob && !rout)
    rout = try_dlsym_routine_BM (ob);
  if (!rout || rout == crashing_objrout_BM || rout == warning_objrout_BM)
    {
      if (ob)
        WARNPRINTF_BM
          ("applyvar_BM funv: %s, object %s with bad routine (%u arguments)",
           debug_outstr_value_BM (funv, stkf, 0), objectdbg_BM (ob), nbargs);
      else if (ob)
        WARNPRINTF_BM
          ("applyvar_BM funv: %s has bad routine (%u arguments)",
           debug_outstr_value_BM (funv, stkf, 0), nbargs);
      for (int ix = 0; ix < (int) nbargs; ix++)
        WARNPRINTF_BM ("applyvar_BM arg#%d: %s", ix,
                       debug_outstr_value_BM (argarr[ix], stkf, 0));
      if (!rout)
        return NULL;
    }
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

value_tyBM
applymany_BM (const value_tyBM funv, struct stackframe_stBM *stkf,
              unsigned nbargs, ...)
{
  /* since we call applyvar_BM, there is no need for warnings here.... */
  if (nbargs > MAXAPPLYARGS_BM)
    FATAL_BM ("applymany_BM too many %u arguments", nbargs);
  value_tyBM tinyarr[TINYSIZE_BM] = { };
  value_tyBM *arr = (nbargs < TINYSIZE_BM) ? tinyarr
    : calloc (prime_above_BM (nbargs), sizeof (value_tyBM));
  if (!arr)
    FATAL_BM ("applymany failed to calloc for %u arguments", nbargs);
  va_list arglist;
  va_start (arglist, nbargs);
  for (unsigned ix = 0; ix < nbargs; ix++)
    arr[ix] = va_arg (arglist, value_tyBM);
  va_end (arglist);
  value_tyBM res = applyvar_BM (funv, stkf, nbargs, arr);
  if (arr != tinyarr)
    free (arr);
  return res;
}                               /* end applymany_BM */


/****************
 **                           for Emacs...
 ** Local Variables: ;;
 ** compile-command: "./Build" ;;
 ** End: ;;
 ****************/
/**** end of file node_BM.c ****/
