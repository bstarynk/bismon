// file allocgc_BM.c

#include "bismon.h"

struct allalloc_stBM *allocationvec_vBM;

static pthread_t mainthreadid_BM;

void
initialize_garbage_collector_BM (void)
{
  mainthreadid_BM = pthread_self ();
  unsigned alsiz = 1022;
  allocationvec_vBM =
    malloc (sizeof (struct allalloc_stBM) + alsiz * sizeof (void *));
  if (!allocationvec_vBM)
    FATAL_BM ("failed to malloc initial allocationvec_vBM of %u (%m)", alsiz);
  memset (allocationvec_vBM, 0,
          sizeof (struct allalloc_stBM) + alsiz * sizeof (void *));
  allocationvec_vBM->al_size = alsiz;
}                               /* end initialize_garbage_collector_BM */

void *
allocgcty_BM (unsigned type, size_t sz)
{
  assert (pthread_self () == mainthreadid_BM);
  assert (allocationvec_vBM != NULL);
  unsigned long alloc_size = allocationvec_vBM->al_size;
  unsigned long alloc_nb = allocationvec_vBM->al_nb;
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
  assert (sz < MAXSIZE_BM * sizeof (double));
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
      closuregcmark_BM (gc, (closure_tyBM *) val, depth);
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
    case tydata_strbuffer_BM:
      strbuffergcmark_BM (gc, (struct strbuffer_stBM *) val, depth);
      return;
    case tydata_loader_BM:
      loadergcmark_BM (gc, (struct loader_stBM *) val);
      return;
    case tydata_quasinode_BM:
      quasinodegcmark_BM (gc, (quasinode_tyBM *) val, depth);
      return;
    case tydata_vectval_BM:
      datavectgcmark_BM (gc, (struct datavectval_stBM *) val, depth);
      return;
    case tydata_classinfo_BM:
      classinfogcmark_BM (gc, (struct classinfo_stBM *) val, depth);
      return;
    case tydata_dict_BM:
      dictgcmark_BM (gc, (struct dict_stBM *) val, depth);
      return;
    default:
      FATAL_BM ("gcmark ty#%d unexpected for val@%p depth=%d",
                ty, val, depth);
    }
}                               /* end gcmark_BM */

void
valgcdestroy_BM (struct garbcoll_stBM *gc, value_tyBM val)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  if (!val)
    return;
  int ty = valtype_BM (val);
  if (!ty || ty == tyInt_BM)
    return;
  assert (((typedhead_tyBM *) val)->hgc == CLEARMGC_BM);
  switch (ty)
    {
    case tyString_BM:
      stringgcdestroy_BM (gc, (stringval_tyBM *) val);
      return;
    case tyObject_BM:
      objectgcdestroy_BM (gc, val);
      return;
    case tySet_BM:
      setgcdestroy_BM (gc, (setval_tyBM *) val);
      return;
    case tyTuple_BM:
      tuplegcdestroy_BM (gc, (tupleval_tyBM *) val);
      return;
    case tyNode_BM:
      nodegcdestroy_BM (gc, (node_tyBM *) val);
      return;
    case tyClosure_BM:
      closuregcdestroy_BM (gc, (closure_tyBM *) val);
      return;
    case tydata_assocpairs_BM:
      assocpairgcdestroy_BM (gc, (struct assocpairs_stBM *) val);
      return;
    case tydata_assocbucket_BM:
      assocbucketgcdestroy_BM (gc, (struct assocbucket_stBM *) val);
      return;
    case tydata_hashsetobj_BM:
      hashsetgcdestroy_BM (gc, (struct hashsetobj_stBM *) val);
      return;
    case tydata_listtop_BM:
      listgcdestroy_BM (gc, (struct listtop_stBM *) val);
      return;
    case tydata_strbuffer_BM:
      strbuffergcdestroy_BM (gc, (struct strbuffer_stBM *) val);
      return;
    case tydata_loader_BM:
      loadergcdestroy_BM (gc, (struct loader_stBM *) val);
      return;
    case tydata_vectval_BM:
      datavectgcdestroy_BM (gc, (struct datavectval_stBM *) val);
      return;
    case tydata_classinfo_BM:
      classinfogcdestroy_BM (gc, (struct classinfo_stBM *) val);
      return;
    case tydata_dict_BM:
      dictgcdestroy_BM (gc, (struct dict_stBM *) val);
      return;
    default:
      FATAL_BM ("gcdestroy ty#%d unexpected for val@%p", ty, val);
    }
}                               /* end valgcdestroy_BM */


void
valgckeep_BM (struct garbcoll_stBM *gc, value_tyBM val)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  if (!val)
    return;
  int ty = valtype_BM (val);
  if (!ty || ty == tyInt_BM)
    return;
  assert (((typedhead_tyBM *) val)->hgc == MARKGC_BM);
  switch (ty)
    {
    case tyString_BM:
      stringgckeep_BM (gc, (stringval_tyBM *) val);
      return;
    case tyObject_BM:
      objectgckeep_BM (gc, val);
      return;
    case tySet_BM:
      setgckeep_BM (gc, (setval_tyBM *) val);
      return;
    case tyTuple_BM:
      tuplegckeep_BM (gc, (tupleval_tyBM *) val);
      return;
    case tyNode_BM:
      nodegckeep_BM (gc, (node_tyBM *) val);
      return;
    case tyClosure_BM:
      closuregckeep_BM (gc, (closure_tyBM *) val);
      return;
    case tydata_assocpairs_BM:
      assocpairgckeep_BM (gc, (struct assocpairs_stBM *) val);
      return;
    case tydata_assocbucket_BM:
      assocbucketgckeep_BM (gc, (struct assocbucket_stBM *) val);
      return;
    case tydata_hashsetobj_BM:
      hashsetgckeep_BM (gc, (struct hashsetobj_stBM *) val);
      return;
    case tydata_listtop_BM:
      listgckeep_BM (gc, (struct listtop_stBM *) val);
      return;
    case tydata_strbuffer_BM:
      strbuffergckeep_BM (gc, (struct strbuffer_stBM *) val);
      return;
    case tydata_vectval_BM:
      datavectgckeep_BM (gc, (struct datavectval_stBM *) val);
      return;
    case tydata_loader_BM:
      loadergckeep_BM (gc, (struct loader_stBM *) val);
      return;
    case tydata_classinfo_BM:
      classinfogckeep_BM (gc, (struct classinfo_stBM *) val);
      return;
    case tydata_dict_BM:
      dictgckeep_BM (gc, (struct dict_stBM *) val);
      return;
    default:
      FATAL_BM ("gckeep ty#%d unexpected for val@%p", ty, val);
    }
}                               /* end valgckeep_BM */



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



void
fullgarbagecollection_BM (struct stackframe_stBM *stkfram)
{
  assert (pthread_self () == mainthreadid_BM);
  static unsigned long countgc;
  struct garbcoll_stBM GCdata = { };
  memset (&GCdata, 0, sizeof (GCdata));
  GCdata.gc_magic = GCMAGIC_BM;
  GCdata.gc_startelapsedtime = elapsedtime_BM ();
  GCdata.gc_startcputime = cputime_BM ();
  assert (allocationvec_vBM != NULL);
  countgc++;
  unsigned long alsiz = allocationvec_vBM->al_size;
  unsigned long alcnt = allocationvec_vBM->al_nb;
  unsigned long oldnbval = 0;
  assert (alcnt <= alsiz);
  assert (alcnt > 0);
  for (unsigned long ix = 0; ix < alcnt; ix++)
    {
      typedhead_tyBM *curp = allocationvec_vBM->al_ptr[ix];
      if (!curp)
        continue;
      curp->hgc = CLEARMGC_BM;
      oldnbval++;
    }
  GCdata.gc_scanlist = makelist_BM ();
  GCdata.gc_hset =              //
    hashsetobj_grow_BM (NULL, prime_above_BM (alcnt / 32 + 100));
  gcmarkpredefinedobjects_BM (&GCdata);
  gcmarkglobals_BM (&GCdata);
  gcframemark_BM (&GCdata, stkfram, 0);
  unsigned long nbobjscan = 0;
  while (listlength_BM (GCdata.gc_scanlist) > 0)
    {
      value_tyBM firstv = listfirst_BM (GCdata.gc_scanlist);
      listpopfirst_BM (GCdata.gc_scanlist);
      assert (isobject_BM (firstv));
      objectinteriorgcmark_BM (&GCdata, (objectval_tyBM *) firstv);
      nbobjscan++;
    }
  unsigned long nbalive = 0;
  unsigned long nbdestroy = 0;
  for (unsigned long ix = 0; ix < alcnt; ix++)
    {
      typedhead_tyBM *curp = allocationvec_vBM->al_ptr[ix];
      if (!curp)
        continue;
      if (curp->hgc == CLEARMGC_BM)
        {
          valgcdestroy_BM (&GCdata, (value_tyBM) curp);
          allocationvec_vBM->al_ptr[ix] = NULL;
          nbdestroy++;
        }
      else
        {
          valgckeep_BM (&GCdata, (value_tyBM) curp);
          nbalive++;
        }
    };
  unsigned long newsizall = prime_above_BM (4 * nbalive / 3 + 200);
  struct allalloc_stBM *newallvec =     //
    malloc (sizeof (struct allalloc_stBM) + newsizall * sizeof (void *));
  if (!newallvec)
    FATAL_BM ("failed to malloc allocationvec of %lu (%m)", newsizall);
  memset (newallvec, 0,
          sizeof (struct allalloc_stBM) + newsizall * sizeof (void *));
  newallvec->al_size = newsizall;
  unsigned long newcntall = 0;
  for (unsigned long ix = 0; ix < alcnt; ix++)
    {
      typedhead_tyBM *curp = allocationvec_vBM->al_ptr[ix];
      if (!curp)
        continue;
      newallvec->al_ptr[newcntall++] = curp;
    }
  newallvec->al_nb = newcntall;
  free (allocationvec_vBM), allocationvec_vBM = newallvec;
  double endelapsedtime = elapsedtime_BM ();
  double endcputime = cputime_BM ();
  fprintf (stderr,
           "@@garbage collection #%ld : %.4f elapsed, %.4f cpu seconds\n",
           countgc, endelapsedtime - GCdata.gc_startelapsedtime,
           endcputime - GCdata.gc_startcputime);
  fprintf (stderr,
           "number of values: %ld -> %ld (-%ld)\n", oldnbval, newcntall,
           newcntall - oldnbval);
  fprintf (stderr, "number of scanned objects: %ld\n", nbobjscan);
  fprintf (stderr,
           "data memory: kept %ld, freed %ld kilobytes\n",
           (GCdata.gc_keptbytes) / 1024, (GCdata.gc_freedbytes) / 1024);
  fprintf (stderr, "-------\n\n");
  fflush (stderr);
}                               /* end fullgarbagecollection_BM */
