// file allocgc_BM.c

#include "bismon.h"

struct allalloc_stBM *allocationvec_vBM;

void *
allocgcty_BM (unsigned type, size_t sz)
{
  unsigned long alloc_size =
    allocationvec_vBM ? allocationvec_vBM->al_size : 0;
  unsigned long alloc_nb = allocationvec_vBM ? allocationvec_vBM->al_nb : 0;
  if (alloc_nb + 2 >= alloc_size)
    {
      unsigned long new_alloc_size = ((4 * alloc_size / 3 + 600) | 511) - 2;
      struct allalloc_stBM *new_allocvec =
        malloc (sizeof (struct allalloc_stBM) +
                new_alloc_size * sizeof (void *));
      if (!new_allocvec)
        {
          FATAL_BM ("failed reallocation of allocvec %ld (%m)",
                    new_alloc_size);
        }
      new_allocvec->al_size = new_alloc_size;
      new_allocvec->al_nb = alloc_nb;
      memset (new_allocvec->al_ptr, 0, new_alloc_size * sizeof (void *));
      free (allocationvec_vBM);
      allocationvec_vBM = new_allocvec;
    }
  assert (sz > sizeof (typedhead_tyBM));
  typedhead_tyBM *newzon = malloc (sz);
  if (!newzon)
    FATAL_BM ("failed fresh GC allocation of new zone %zd bytes (%m)", sz);
  memset (newzon, 0, sz);
  newzon->htyp = type;
  allocationvec_vBM->al_ptr[alloc_nb++] = newzon;
  allocationvec_vBM->al_nb = alloc_nb;
  return newzon;
}                               /* end allocgcty_BM */



void *
allocinternalty_BM (unsigned type, size_t sz)
{
  assert (sz > sizeof (typedintern_tyBM));
  typedintern_tyBM *newizon = malloc (sz);
  if (!newizon)
    FATAL_BM ("failed internal allocation of %zd bytes (%m)", sz);
  memset (newizon, 0, sz);
  newizon->htyp = type;
  return newizon;
}                               /* end allocinternalty_BM  */



void
gcmark_BM (struct garbcoll_stBM *gc, value_tyBM val, int depth)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  if (!val)
    return;
  if (depth >= MAXDEPTHGC_BM)
    FATAL_BM ("too deep %u gcmark", depth);
  int ty = valtype_BM (val);
  if (!ty || ty == tyInt_BM)
    return;
  uint8_t oldmark = ((typedhead_tyBM *) val)->hgc;
  if (oldmark)
    return;
  switch (ty)
    {
    case tyString_BM:
      ((typedhead_tyBM *) val)->hgc = MARKGC_BM;
      return;
    case tyObject_BM:
      gcobjmark_BM (gc, val);
      return;
    case tySet_BM:
      setgcmark_BM (gc, (setval_tyBM *) val);
      return;
    case tyTuple_BM:
      tuplegcmark_BM (gc, (tupleval_tyBM *) val);
      return;
    case tyNode_BM:
      nodegcmark_BM (gc, (node_tyBM *) val, depth);
      return;
    case tyClosure_BM:
      closuregcmark_BM (gc, (node_tyBM *) val, depth);
      return;
    case tydata_assocpairs_BM:
    case tydata_assocbucket_BM:
      assocgcmark_BM (gc, (anyassoc_tyBM *) val, depth);
      return;
    case tydata_hashsetobj_BM:
      hashsetgcmark_BM (gc, (struct hashsetobj_stBM *) val);
      return;
    case tydata_listtop_BM:
      listgcmark_BM (gc, (struct listtop_stBM *) val, depth);
      return;
    case tydata_loader_BM:
      loadergcmark_BM (gc, (struct loader_stBM *) val);
      return;
    default:
      FATAL_BM ("gcmark ty#%d unexpected for val@%p depth=%d",
                ty, val, depth);
    }
}                               /* end gcmark_BM */


void
gcobjmark_BM (struct garbcoll_stBM *gc, objectval_tyBM * obj)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  if (valtype_BM ((const value_tyBM) obj) != tyObject_BM)
    FATAL_BM ("gcobjmark bad obj@%p", obj);
  uint8_t oldmark = ((typedhead_tyBM *) obj)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) obj)->hgc = MARKGC_BM;
  assert (!hashsetobj_contains_BM (gc->gc_hset, obj));
  gc->gc_hset = hashsetobj_add_BM (gc->gc_hset, obj);
  assert (islist_BM (gc->gc_scanlist));
  listappend_BM (gc->gc_scanlist, obj);
}                               /* end gcobjmark_BM */

void
gcframemark_BM (struct garbcoll_stBM *gc, struct stackframe_stBM *stkfram,
                int depth)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  if (depth >= MAXDEPTHGC_BM)
    FATAL_BM ("too deep %u gcframemark", depth);
  unsigned framcnt = 0;
  // it is on purpose that we don't test the oldmark or set it
  for (; stkfram; stkfram = stkfram->stkfram_prev)
    {
      // this really should never happen
      if (framcnt++ > MAXSIZE_BM / 4)
        FATAL_BM ("too big framcnt=%u, curfram=%p", framcnt, stkfram);
      if (((typedhead_tyBM *) stkfram)->htyp == tydata_StackFrame_BM)
        {
          if (stkfram->stkfram_descr)
            gcobjmark_BM (gc, stkfram->stkfram_descr);
          unsigned framsize = ((typedhead_tyBM *) stkfram)->rlen;
          if (framsize > MAXSIZE_BM / 2)
            FATAL_BM ("too big framesize %u, curfram=%p, framcnt#%d",
                      framsize, stkfram, framcnt);
          for (unsigned ix = 0; ix < framsize; ix++)
            gcmark_BM (gc, stkfram->stkfram_locals[ix], depth + 1);
        }
      else if (((typedhead_tyBM *) stkfram)->htyp == tydata_SpecialFrame_BM)
        {
          struct specialframe_stBM *specfram
            = (struct specialframe_stBM *) stkfram;
          if (specfram->specfram_descr)
            gcobjmark_BM (gc, specfram->specfram_descr);
          if (specfram->specfram_markerout)
            specfram->specfram_markerout (gc, specfram);
        }
      else
        FATAL_BM ("invalid stackframe @%p of type#%d", stkfram,
                  (((typedhead_tyBM *) stkfram)->htyp));
    };
}                               /* end gcframemark_BM */
