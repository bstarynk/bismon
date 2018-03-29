// file allocgc_BM.c

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

struct allalloc_stBM *allocationvec_vBM;
pthread_mutex_t allocationmutex_BM = PTHREAD_MUTEX_INITIALIZER;
atomic_bool want_garbage_collection_BM;
double last_gctime_BM;

pthread_t mainthreadid_BM;


void
initialize_garbage_collector_BM (void)
{
  mainthreadid_BM = pthread_self ();
  atomic_init (&want_garbage_collection_BM, false);
  pthread_mutex_init (&allocationmutex_BM, NULL);
  last_gctime_BM = clocktime_BM (CLOCK_REALTIME);
  unsigned alsiz = 2040;
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
  pthread_mutex_lock (&allocationmutex_BM);
  ASSERT_BM (allocationvec_vBM != NULL);
  unsigned long alloc_size = allocationvec_vBM->al_size;
  unsigned long alloc_nb = allocationvec_vBM->al_nb;
  if (alloc_nb + 3 >= alloc_size)
    {
      unsigned long new_alloc_size = ((4 * alloc_size / 3 + 600) | 511) - 2;
      struct allalloc_stBM *new_allocvec =
        calloc (1, sizeof (struct allalloc_stBM) +
                new_alloc_size * sizeof (void *));
      if (!new_allocvec)
        FATAL_BM ("failed reallocation of allocvec %ld (%m)", new_alloc_size);
      new_allocvec->al_size = new_alloc_size;
      new_allocvec->al_nb = alloc_nb;
      memcpy (new_allocvec->al_ptr, allocationvec_vBM->al_ptr,
              alloc_nb * sizeof (void *));
      free (allocationvec_vBM), allocationvec_vBM = new_allocvec;
      atomic_store (&want_garbage_collection_BM, true);
    }
  ASSERT_BM (sz > sizeof (typedhead_tyBM));
  ASSERT_BM (sz < MAXSIZE_BM * sizeof (double));
  typedhead_tyBM *newzon = malloc (sz);
  if (!newzon)
    FATAL_BM ("failed fresh GC allocation of new zone %zd bytes (%m)", sz);
  memset (newzon, 0, sz);
  newzon->htyp = type;
  allocationvec_vBM->al_ptr[alloc_nb++] = newzon;
  allocationvec_vBM->al_nb = alloc_nb;
  pthread_mutex_unlock (&allocationmutex_BM);
  return newzon;
}                               /* end allocgcty_BM */




void *
valuegcproc_BM (struct garbcoll_stBM *gc, value_tyBM val, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  if (!val)
    return NULL;
  if (depth >= MAXDEPTHGC_BM)
    FATAL_BM ("too deep %u valuegcproc_BM", depth);
  int ty = valtype_BM (val);
  if (!ty || ty == tyInt_BM)
    return val;
  uint8_t oldmark = ((typedhead_tyBM *) val)->hgc;
  if (oldmark)
    return val;
  switch (ty)
    {
    case tyString_BM:
      return stringgcproc_BM (gc, (stringval_tyBM *) val);
    case tyObject_BM:
      gcobjmark_BM (gc, val);
      return val;
    case tySet_BM:
      return setgcproc_BM (gc, (setval_tyBM *) val);
    case tyTuple_BM:
      return tuplegcproc_BM (gc, (tupleval_tyBM *) val);
    case tyNode_BM:
      return nodegcproc_BM (gc, (node_tyBM *) val, depth);
    case tyClosure_BM:
      return closuregcproc_BM (gc, (closure_tyBM *) val, depth);
    case tyUnspecified_BM:
      return val;
    case typayl_FailureHandler_BM:
      {
        struct failurehandler_stBM *fh = (struct failurehandler_stBM *) val;
        if (fh->failh_magic != FAILUREHANDLEMAGIC_BM)
          FATAL_BM ("valuegcproc_BM corrupted failurehandler @%p", val);
        fh->failh_reason = valuegcproc_BM (gc, fh->failh_reason, depth + 1);
        return val;
      }
    default:
      FATAL_BM ("valuegcproc_BM ty#%d (%s) unexpected for val@%p depth=%d\n",
                ty, typestring_BM (ty), val, depth);
    };
}                               /* end valuegcproc_BM */

void *
extendedgcproc_BM (struct garbcoll_stBM *gc, extendedval_tyBM xval, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  if (!xval)
    return NULL;
  if (depth >= MAXDEPTHGC_BM)
    FATAL_BM ("too deep %u gcextendedmark", depth);
  int ty = valtype_BM (xval);
  if (!ty || ty == tyInt_BM)
    return xval;
  uint8_t oldmark = ((typedhead_tyBM *) xval)->hgc;
  if (oldmark)
    return xval;
  switch (ty)
    {
    case tyString_BM:
      return stringgcproc_BM (gc, (stringval_tyBM *) xval);
    case tyUnspecified_BM:
      return xval;
    case tyObject_BM:
      gcobjmark_BM (gc, xval);
      return xval;
    case tySet_BM:
      return setgcproc_BM (gc, (setval_tyBM *) xval);
    case tyTuple_BM:
      return tuplegcproc_BM (gc, (tupleval_tyBM *) xval);
    case tyNode_BM:
      return nodegcproc_BM (gc, (node_tyBM *) xval, depth);
    case tyClosure_BM:
      return closuregcproc_BM (gc, (closure_tyBM *) xval, depth);
      ///
    case typayl_assocpairs_BM:
    case typayl_assocbucket_BM:
      return assocgcproc_BM (gc, (anyassoc_tyBM *) xval, depth);
    case typayl_hashsetobj_BM:
      hashsetgcmark_BM (gc, (struct hashsetobj_stBM *) xval);
      return xval;
    case typayl_listtop_BM:
      listgcmark_BM (gc, (struct listtop_stBM *) xval, depth);
      return xval;
    case typayl_strbuffer_BM:
      strbuffergcmark_BM (gc, (struct strbuffer_stBM *) xval, depth);
      return xval;
    case typayl_loader_BM:
      loadergcmark_BM (gc, (struct loader_stBM *) xval);
      return xval;
    case typayl_dumper_BM:
      dumpgcmark_BM (gc, (struct dumper_stBM *) xval);
      return xval;
    case typayl_quasinode_BM:
      return quasinodegcproc_BM (gc, (quasinode_tyBM *) xval, depth);
    case typayl_vectval_BM:
      return datavectgcproc_BM (gc, (struct datavectval_stBM *) xval, depth);
    case typayl_classinfo_BM:
      classinfogcmark_BM (gc, (struct classinfo_stBM *) xval, depth);
      return xval;
    case typayl_dict_BM:
      dictgcmark_BM (gc, (struct dict_stBM *) xval, depth);
      return xval;
    case typayl_hashsetval_BM:
      hashsetvalgcmark_BM (gc, (struct hashsetval_stBM *) xval, depth);
      return xval;
    case typayl_hashsetvbucket_BM:
      hashsetvbucketgcmark_BM (gc, (struct hashsetvbucket_stBM *) xval,
                               depth);
      return xval;
    case typayl_hashmapval_BM:
      hashmapvalgcmark_BM (gc, (struct hashmapval_stBM *) xval, depth);
      return xval;
    case typayl_hashmapbucket_BM:
      hashmapbucketgcmark_BM (gc, (struct hashmapbucket_stBM *) xval, depth);
      return xval;
    case typayl_FailureHandler_BM:
      {
        struct failurehandler_stBM *fh = (struct failurehandler_stBM *) xval;
        if (fh->failh_magic != FAILUREHANDLEMAGIC_BM)
          FATAL_BM ("extendedgcproc_BM corrupted failurehandler @%p", xval);
        fh->failh_reason = valuegcproc_BM (gc, fh->failh_reason, depth + 1);
        return xval;
      }
    default:
      FATAL_BM ("extendedgcproc_BM ty#%d unexpected for xval@%p depth=%d",
                ty, xval, depth);
    }
}                               /* end extendedgcproc_BM */


void
valgcdestroy_BM (struct garbcoll_stBM *gc, value_tyBM val)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  if (!val)
    return;
  int ty = valtype_BM (val);
  if (!ty || ty == tyInt_BM)
    return;
  ASSERT_BM (((typedhead_tyBM *) val)->hgc == CLEARMGC_BM);
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
    case typayl_assocpairs_BM:
      assocpairgcdestroy_BM (gc, (struct assocpairs_stBM *) val);
      return;
    case typayl_assocbucket_BM:
      assocbucketgcdestroy_BM (gc, (struct assocbucket_stBM *) val);
      return;
    case typayl_hashsetobj_BM:
      hashsetgcdestroy_BM (gc, (struct hashsetobj_stBM *) val);
      return;
    case typayl_listtop_BM:
      listgcdestroy_BM (gc, (struct listtop_stBM *) val);
      return;
    case typayl_strbuffer_BM:
      strbuffergcdestroy_BM (gc, (struct strbuffer_stBM *) val);
      return;
    case typayl_loader_BM:
      loadergcdestroy_BM (gc, (struct loader_stBM *) val);
      return;
    case typayl_vectval_BM:
      datavectgcdestroy_BM (gc, (struct datavectval_stBM *) val);
      return;
    case typayl_classinfo_BM:
      classinfogcdestroy_BM (gc, (struct classinfo_stBM *) val);
      return;
    case typayl_dict_BM:
      dictgcdestroy_BM (gc, (struct dict_stBM *) val);
      return;
    case typayl_parser_BM:
      parsergcdestroy_BM (gc, (struct parser_stBM *) val);
      return;
    case typayl_dumper_BM:
      dumpgcdestroy_BM (gc, (struct dumper_stBM *) val);
      return;
    case typayl_FailureHandler_BM:
      return;
    case typayl_hashsetval_BM:
      hashsetvalgcdestroy_BM (gc, (struct hashsetval_stBM *) val);
      return;
    case typayl_hashsetvbucket_BM:
      hashsetvbucketgcdestroy_BM (gc, (struct hashsetvbucket_stBM *) val);
      return;
    case typayl_hashmapval_BM:
      hashmapvalgcdestroy_BM (gc, (struct hashmapval_stBM *) val);
      return;
    case typayl_hashmapbucket_BM:
      hashmapbucketgcdestroy_BM (gc, (struct hashmapbucket_stBM *) val);
      return;
    default:
      FATAL_BM ("gcdestroy ty#%d unexpected for val@%p", ty, val);
    }
}                               /* end valgcdestroy_BM */



const char *
typestring_BM (int ty)
{
  switch (ty)
    {
    case tyInt_BM:
      return "Int";
    case tyNone_BM:
      return "None";
    case tyString_BM:
      return "String";
    case tyObject_BM:
      return "Object";
    case tySet_BM:
      return "Set";
    case tyTuple_BM:
      return "Tuple";
    case tyNode_BM:
      return "Node";
    case tyClosure_BM:
      return "Closure";
    case typayl_assocpairs_BM:
      return "payl_assocpairs";
    case typayl_assocbucket_BM:
      return "payl_assocbucket";
    case typayl_hashsetobj_BM:
      return "payl_hashsetobj";
    case typayl_listtop_BM:
      return "payl_listob";
    case typayl_strbuffer_BM:
      return "payl_strbuffer";
    case typayl_loader_BM:
      return "payl_loader";
    case typayl_vectval_BM:
      return "payl_vectval";
    case typayl_classinfo_BM:
      return "payl_classinfo";
    case typayl_dict_BM:
      return "payl_dict";
    case typayl_parser_BM:
      return "payl_parser";
    case typayl_dumper_BM:
      return "payl_dumper";
    case typayl_FailureHandler_BM:
      return "payl_FailureHandler";
    case typayl_SpecialFrame_BM:
      return "payl_SpecialFrame";
    case typayl_StackFrame_BM:
      return "payl_StackFrame";
    case typayl_hashsetval_BM:
      return "payl_hashsetval";
    case typayl_hashsetvbucket_BM:
      return "payl_hashsetbucket";
    case typayl_hashmapval_BM:
      return "payl_hashmapval";
    case typayl_hashmapbucket_BM:
      return "payl_hashmapbucket";
    default:
      {
        static char buf[32];
        snprintf (buf, sizeof (buf), "?ty#%d?", ty);
        return buf;
      }
    }
}                               /* end typestring_BM */

void
deleteobjectpayload_BM (objectval_tyBM * obj, extendedval_tyBM payl)
{
  ASSERT_BM (isobject_BM (obj));
  if (!payl)
    return;
  int ty = valtype_BM (payl);
  if (!ty || ty == tyInt_BM)
    return;
  switch (ty)
    {
    case tyString_BM:
    case tyObject_BM:
    case tySet_BM:
    case tyTuple_BM:
    case tyNode_BM:
    case tyClosure_BM:
      return;
    case typayl_assocpairs_BM:
      return;
    case typayl_assocbucket_BM:
      return;
    case typayl_hashsetobj_BM:
      return;
    case typayl_listtop_BM:
      return;
    case typayl_strbuffer_BM:
      return;
    case typayl_loader_BM:
      return;
    case typayl_vectval_BM:
      return;
    case typayl_classinfo_BM:
      return;
    case typayl_dict_BM:
      return;
    case typayl_parser_BM:
      return;
    case typayl_dumper_BM:
      return;
    default:
      FATAL_BM ("deleteobjectpayload_BM ty#%d unexpected for payl@%p", ty,
                payl);
    }
}                               /* end deleteobjectpayload_BM */


void
valgckeep_BM (struct garbcoll_stBM *gc, value_tyBM val)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  if (!val)
    return;
  int ty = valtype_BM (val);
  if (!ty || ty == tyInt_BM)
    return;
  ASSERT_BM (((typedhead_tyBM *) val)->hgc == MARKGC_BM);
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
    case typayl_assocpairs_BM:
      assocpairgckeep_BM (gc, (struct assocpairs_stBM *) val);
      return;
    case typayl_assocbucket_BM:
      assocbucketgckeep_BM (gc, (struct assocbucket_stBM *) val);
      return;
    case typayl_hashsetobj_BM:
      hashsetgckeep_BM (gc, (struct hashsetobj_stBM *) val);
      return;
    case typayl_listtop_BM:
      listgckeep_BM (gc, (struct listtop_stBM *) val);
      return;
    case typayl_strbuffer_BM:
      strbuffergckeep_BM (gc, (struct strbuffer_stBM *) val);
      return;
    case typayl_vectval_BM:
      datavectgckeep_BM (gc, (struct datavectval_stBM *) val);
      return;
    case typayl_loader_BM:
      loadergckeep_BM (gc, (struct loader_stBM *) val);
      return;
    case typayl_classinfo_BM:
      classinfogckeep_BM (gc, (struct classinfo_stBM *) val);
      return;
    case typayl_dict_BM:
      dictgckeep_BM (gc, (struct dict_stBM *) val);
      return;
    case typayl_parser_BM:
      parsergckeep_BM (gc, (struct parser_stBM *) val);
      return;
    case typayl_dumper_BM:
      dumpgckeep_BM (gc, (struct dumper_stBM *) val);
      return;
    case typayl_hashsetval_BM:
      hashsetvalgckeep_BM (gc, (struct hashsetval_stBM *) val);
      return;
    case typayl_hashsetvbucket_BM:
      hashsetvbucketgckeep_BM (gc, (struct hashsetvbucket_stBM *) val);
      return;
    case typayl_hashmapval_BM:
      hashmapvalgckeep_BM (gc, (struct hashmapval_stBM *) val);
      return;
    case typayl_hashmapbucket_BM:
      hashmapbucketgckeep_BM (gc, (struct hashmapbucket_stBM *) val);
      return;
    default:
      FATAL_BM ("gckeep ty#%d unexpected for val@%p", ty, val);
    }
}                               /* end valgckeep_BM */



void
gcobjmark_BM (struct garbcoll_stBM *gc, objectval_tyBM * obj)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  if (valtype_BM ((const value_tyBM) obj) != tyObject_BM)
    FATAL_BM ("gcobjmark bad obj@%p", obj);
  uint8_t oldmark = ((typedhead_tyBM *) obj)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) obj)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  ASSERT_BM (!hashsetobj_contains_BM (gc->gc_hset, obj));
  gc->gc_hset = hashsetobj_add_BM (gc->gc_hset, obj);
  ASSERT_BM (islist_BM (gc->gc_scanlist));
  listappend_BM (gc->gc_scanlist, obj);
}                               /* end gcobjmark_BM */

void
gcframemark_BM (struct garbcoll_stBM *gc, struct stackframe_stBM *stkfram,
                int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  if (depth >= MAXDEPTHGC_BM)
    FATAL_BM ("too deep %u gcframemark", depth);
  unsigned framcnt = 0;
  // it is on purpose that we don't test the oldmark or set it
  for (; stkfram; stkfram = stkfram->stkfram_prev)
    {
      // this really should never happen
      if (framcnt++ > MAXSIZE_BM / 4)
        FATAL_BM ("too big framcnt=%u, curfram=%p", framcnt, stkfram);
      if (((typedhead_tyBM *) stkfram)->htyp == typayl_StackFrame_BM)
        {
          if (stkfram->stkfram_descr)
            gcobjmark_BM (gc, stkfram->stkfram_descr);
          unsigned framsize = ((typedhead_tyBM *) stkfram)->rlen;
          if (framsize > MAXSIZE_BM / 2)
            FATAL_BM ("too big framesize %u, curfram=%p, framcnt#%d",
                      framsize, stkfram, framcnt);
          VALUEGCPROC_BM (gc, (stkfram->stkfram_callfun), depth + 1);
          for (unsigned ix = 0; ix < framsize; ix++)
            VALUEGCPROC_BM (gc, stkfram->stkfram_locals[ix], depth + 1);
        }
      else if (((typedhead_tyBM *) stkfram)->htyp == typayl_SpecialFrame_BM)
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



static unsigned long countgc_BM;
void
full_garbage_collection_BM (struct stackframe_stBM *stkfram)
{
  DBGPRINTF_BM
    ("start full_garbage_collection_BM tid#%ld elapsed %.3f s",
     (long) gettid_BM (), elapsedtime_BM ());
  ASSERT_BM (pthread_self () == mainthreadid_BM);
  int nbj = agenda_nb_work_jobs_BM ();
  DBGPRINTF_BM ("full_garbage_collection_BM nbj=%d", nbj);
  if (nbj > 0)
    {
      agenda_suspend_for_gc_BM ();
      DBGPRINTF_BM ("full_garbage_collection_BM after agendasuspend");
    };
  atomic_store (&want_garbage_collection_BM, false);
  struct garbcoll_stBM GCdata = { };
  memset (&GCdata, 0, sizeof (GCdata));
  GCdata.gc_magic = GCMAGIC_BM;
  GCdata.gc_startelapsedtime = elapsedtime_BM ();
  GCdata.gc_startcputime = cputime_BM ();
  ASSERT_BM (allocationvec_vBM != NULL);
  countgc_BM++;
  unsigned long alsiz = allocationvec_vBM->al_size;
  unsigned long alcnt = allocationvec_vBM->al_nb;
  unsigned long oldnbval = 0;
  ASSERT_BM (alcnt <= alsiz);
  ASSERT_BM (alcnt > 0);
  for (unsigned long ix = 0; ix < alcnt; ix++)
    {
      typedhead_tyBM *curp = allocationvec_vBM->al_ptr[ix];
      if (!curp)
        continue;
      if (curp->htyp < type_FIRST_BM || curp->htyp > typayl_LAST_BM)
        {
          fflush (NULL);
          FATAL_BM ("corrupted allocated#%ld @%p (htyp %d)", ix, curp,
                    (int) (curp->htyp));
        };
      ASSERT_BM (curp->htyp >= type_FIRST_BM && curp->htyp <= typayl_LAST_BM);
      curp->hgc = CLEARMGC_BM;
      oldnbval++;
    }
  GCdata.gc_scanlist = makelist_BM ();
  GCdata.gc_hset =              //
    hashsetobj_grow_BM (NULL, prime_above_BM (alcnt / 16 + 300));
  gcmarkpredefinedobjects_BM (&GCdata);
  gcmarkconstants_BM (&GCdata);
  gcmarkglobals_BM (&GCdata);
  if (!oldgui_BM)
    gcmarknewgui_BM (&GCdata);
  else
    gcmarkoldgui_BM (&GCdata);
  gcmarkdefergtk_BM (&GCdata);
  gcmarkagenda_BM (&GCdata);
  gcframemark_BM (&GCdata, stkfram, 0);
  unsigned long nbobjscan = 0;
  while (listlength_BM (GCdata.gc_scanlist) > 0)
    {
      value_tyBM firstv = listfirst_BM (GCdata.gc_scanlist);
      listpopfirst_BM (GCdata.gc_scanlist);
      ASSERT_BM (isobject_BM (firstv));
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
      ASSERT_BM (curp->htyp >= type_FIRST_BM && curp->htyp <= typayl_LAST_BM);
      if (curp->hgc == CLEARMGC_BM)
        {
          allocationvec_vBM->al_ptr[ix] = NULL;
          valgcdestroy_BM (&GCdata, (value_tyBM) curp);
          nbdestroy++;
        }
      else
        {
          ASSERT_BM (curp->hgc == MARKGC_BM);
          valgckeep_BM (&GCdata, (value_tyBM) curp);
          nbalive++;
        }
    };
  unsigned long newsizall = prime_above_BM (4L * nbalive / 3 + 200);
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
      ASSERT_BM (curp->htyp >= type_FIRST_BM && curp->htyp <= typayl_LAST_BM);
      newallvec->al_ptr[newcntall++] = curp;
      allocationvec_vBM->al_ptr[ix] = NULL;
    }
  newallvec->al_nb = newcntall;
  free (allocationvec_vBM), allocationvec_vBM = newallvec;
  double endelapsedtime = elapsedtime_BM ();
  double endcputime = cputime_BM ();
  char *buf = NULL;
  size_t siz = 0;
  FILE *fil = gui_is_running_BM ? open_memstream (&buf, &siz) : stderr;
  if (!fil)
    FATAL_BM ("bad fil in full_garbage_collection_BM (%m)");
  fprintf (fil,
           "@@garbage collection #%ld : %.4f elapsed, %.4f cpu seconds\n",
           countgc_BM, endelapsedtime - GCdata.gc_startelapsedtime,
           endcputime - GCdata.gc_startcputime);
  fprintf (fil,
           "number of values: %ld -> %ld (-%ld), %ld slots; %ld marks\n",
           oldnbval, newcntall, oldnbval - newcntall, alcnt,
           GCdata.gc_nbmarks);
  fprintf (fil, "%ld scanned, %ld kept, %ld static, %ld destroyed objects\n",
           nbobjscan, GCdata.gc_nbkeptobjects, (long) BM_NB_PREDEFINED,
           GCdata.gc_nbdestroyedobjects);
  {
    char keptbuf[40], freedbuf[40];
    memset (keptbuf, 0, sizeof (keptbuf));
    memset (freedbuf, 0, sizeof (freedbuf));
    long keptb = GCdata.gc_keptbytes;
    if (keptb < 128L * 1024)
      snprintf (keptbuf, sizeof (keptbuf), "%ld bytes", keptb);
    else if (keptb < 256L << 20)
      snprintf (keptbuf, sizeof (keptbuf), "%ld kilobytes", keptb >> 10);
    else
      snprintf (keptbuf, sizeof (keptbuf), "%ld megabytes", keptb >> 20);
    long freedb = GCdata.gc_freedbytes;
    if (freedb < 128L * 1024)
      snprintf (freedbuf, sizeof (freedbuf), "%ld bytes", freedb);
    else if (freedb < 256L << 20)
      snprintf (freedbuf, sizeof (freedbuf), "%ld kilobytes", freedb >> 10);
    else
      snprintf (freedbuf, sizeof (freedbuf), "%ld megabytes", freedb >> 20);
    fprintf (fil, "data memory: kept %s, freed %s\n", keptbuf, freedbuf);
  }
  {
    FILE *f = fopen ("/proc/self/statm", "r");
    if (f)
      {
        long psiz = 0, rss = 0, shared = 0, code = 0;
        long lib = 0, data = 0, dt = 0;
        long pagsiz = sysconf (_SC_PAGESIZE);
        if (fscanf (f, "%ld %ld %ld %ld %ld %ld %ld",
                    &psiz, &rss, &shared, &code, &lib, &data, &dt) >= 7)
          {
            long psizbytes = psiz * pagsiz;
            long rssbytes = rss * pagsiz;
            long databytes = data * pagsiz;
            char psizbuf[40], rssbuf[40], databuf[40];
            memset (psizbuf, 0, sizeof (psizbuf));
            memset (rssbuf, 0, sizeof (rssbuf));
            memset (databuf, 0, sizeof (databuf));
            if (psizbytes < 128L * 1024)
              snprintf (psizbuf, sizeof (psizbuf), "%ld bytes", psizbytes);
            else if (psizbytes < 256L << 20)
              snprintf (psizbuf, sizeof (psizbuf), "%ld kilobytes",
                        psizbytes >> 10);
            else
              snprintf (psizbuf, sizeof (psizbuf), "%ld megabytes",
                        psizbytes >> 20);
            if (rssbytes < 128L * 1024)
              snprintf (rssbuf, sizeof (rssbuf), "%ld bytes", rssbytes);
            else if (rssbytes < 256L << 20)
              snprintf (rssbuf, sizeof (rssbuf), "%ld kilobytes",
                        rssbytes >> 10);
            else
              snprintf (rssbuf, sizeof (rssbuf), "%ld megabytes",
                        rssbytes >> 20);

            if (databytes < 128L * 1024)
              snprintf (databuf, sizeof (databuf), "%ld bytes", databytes);
            else if (databytes < 256L << 20)
              snprintf (databuf, sizeof (databuf), "%ld kilobytes",
                        databytes >> 10);
            else
              snprintf (databuf, sizeof (databuf), "%ld megabytes",
                        databytes >> 20);
            fprintf (fil, "process [%d] vmem %s, rss %s, data %s\n",
                     (int) getpid (), psizbuf, rssbuf, databuf);
          }
        fclose (f);
      }
  }
  fprintf (fil, "-------\n\n");
  fflush (fil);
  last_gctime_BM = clocktime_BM (CLOCK_REALTIME);
  if (fil != stderr)
    {
      ASSERT_BM (gui_is_running_BM);
      ASSERT_BM (buf != NULL);
      fputs (buf, stderr);
      gui_gc_message_BM (buf);
      fclose (fil);
      free (buf), buf = NULL;
    };
  if (nbj > 0)
    {
      DBGPRINTF_BM
        ("full_garbage_collection_BM before continue_after_gc nbj=%d", nbj);
      agenda_continue_after_gc_BM ();
    };
  DBGPRINTF_BM ("full_garbage_collection_BM end tid#%ld\n\n",
                (long) gettid_BM ());
}                               /* end full_garbage_collection_BM */
