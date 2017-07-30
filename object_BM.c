// file object_BM.c
#include "bismon.h"

/// the predefined have static memory
#define HAS_PREDEF_BM(Id,Hi,Lo,Hash) objectval_tyBM predefdata##Id##_BM = { \
 .pA = (typedhead_tyBM){.htyp= tyObject_BM, .hgc=0, .hash= Hash}, \
 .ob_id = (rawid_tyBM){.id_hi= Hi, .id_lo= Lo}, \
 .ob_space = PredefSp_BM, \
  }; \
  objectval_tyBM* predefptr##Id##_BM = &predefdata##Id##_BM;

#include "_bm_predef.h"



/// declare the globals
#define HAS_GLOBAL_BM(Gnam) objectval_tyBM* GLOBAL_BM(Gnam);

#include "_bm_global.h"


static struct hashsetobj_stBM *hashset_predefined_objects_BM;

// for qsort
static int
objptrqcmp_BM (const void *p1, const void *p2)
{
  return objectcmp_BM (*(const objectval_tyBM **) p1,
                       *(const objectval_tyBM **) p2);
}                               /* end objptrqcmp_BM */

void
sortobjarr_BM (const objectval_tyBM ** obarr, size_t arrsiz)
{
  if (obarr == NULL)
    arrsiz = 0;
  if (arrsiz > 1)
    qsort (obarr, arrsiz, sizeof (const objectval_tyBM *), objptrqcmp_BM);
}                               /* end sortobjarr_BM */



struct objbucket_stBM
{
  unsigned bucksize;            /* a prime number */
  unsigned buckcount;           // used count
  objectval_tyBM *buckobjs[];   // allocated size is bucksize
};

static struct objbucket_stBM *buckarr_BM[MAXBUCKETS_BM];


#define EMPTYSLOTOB_BM ((objectval_tyBM*)(-1))

extern objectval_tyBM *
findobjofid_BM (const rawid_tyBM id)
{
  if (!validid_BM (id))
    return NULL;
  unsigned bucknum = bucknumserial63_BM (id.id_hi);
  struct objbucket_stBM *curbuck = buckarr_BM[bucknum];
  if (!curbuck)
    return NULL;
  unsigned busiz = curbuck->bucksize;
  assert (busiz >= 4 && busiz % 2 != 0 && busiz % 3 != 0);
  assert (curbuck->buckcount < curbuck->bucksize);
  hash_tyBM h = hashid_BM (id);
  unsigned startix = h % busiz;
  for (unsigned ix = startix; ix < busiz; ix++)
    {
      objectval_tyBM *curob = curbuck->buckobjs[ix];
      if (!curob)
        return NULL;
      if (curob == EMPTYSLOTOB_BM)
        continue;
      if (equalid_BM (curob->ob_id, id))
        return curob;
    };
  for (unsigned ix = 0; ix < startix; ix++)
    {
      objectval_tyBM *curob = curbuck->buckobjs[ix];
      if (!curob)
        return NULL;
      if (curob == EMPTYSLOTOB_BM)
        continue;
      if (equalid_BM (curob->ob_id, id))
        return curob;
    };
  return NULL;
}                               /* end of findobjofid_BM */

static void
addtobucket_BM (struct objbucket_stBM *buck, objectval_tyBM * ob)
{
  assert (buck != NULL);
  assert (valtype_BM (ob) == tyObject_BM);
  hash_tyBM h = objecthash_BM (ob);
  assert (h > 0);
  unsigned busiz = buck->bucksize;
  assert (busiz % 2 != 0 && busiz % 3 != 0 && busiz % 5 != 0);
  assert (buck->buckcount < buck->bucksize);
  unsigned startix = h % busiz;
  int pos = -1;
  for (unsigned ix = startix; ix < busiz; ix++)
    {
      objectval_tyBM *curob = buck->buckobjs[ix];
      if (!curob)
        {
          if (pos < 0)
            pos = (int) ix;
          break;
        }
      else if (curob == EMPTYSLOTOB_BM)
        {
          if (pos < 0)
            pos = (int) ix;
          continue;
        }
      else if (curob == ob)
        return;
    }
  for (unsigned ix = 0; ix < startix; ix++)
    {
      objectval_tyBM *curob = buck->buckobjs[ix];
      if (!curob)
        {
          if (pos < 0)
            pos = (int) ix;
          break;
        }
      else if (curob == EMPTYSLOTOB_BM)
        {
          if (pos < 0)
            pos = (int) ix;
          continue;
        }
      else if (curob == ob)
        return;
    }
  if (pos < 0)
    FATAL_BM ("corrupted object bucket@%p", buck);
  buck->buckobjs[pos] = ob;
  buck->buckcount++;
}                               /* end addtobucket_BM */

static void
growobucket_BM (unsigned bucknum, unsigned gap)
{
  assert (bucknum < MAXBUCKETS_BM);
  struct objbucket_stBM *oldbuck = buckarr_BM[bucknum];
  unsigned oldsiz = oldbuck ? oldbuck->bucksize : 0;
  unsigned oldcnt = oldbuck ? oldbuck->buckcount : 0;
  unsigned long newsiz =
    prime_above_BM (4 * (oldcnt + gap) / 3 + gap / 64 + 4);
  struct objbucket_stBM *newbuck =
    malloc (sizeof (struct objbucket_stBM) + newsiz * sizeof (void *));
  if (!newbuck)
    FATAL_BM ("out of memory for newbuck#%d of newsiz %lu", bucknum, newsiz);
  memset (newbuck, 0,
          sizeof (struct objbucket_stBM) + newsiz * sizeof (void *));
  newbuck->bucksize = newsiz;
  newbuck->buckcount = 0;
  for (unsigned oix = 0; oix < oldsiz; oix++)
    {
      objectval_tyBM *oldob = oldbuck->buckobjs[oix];
      if (!oldob || oldob == EMPTYSLOTOB_BM)
        continue;
      addtobucket_BM (newbuck, oldob);
    }
  free (oldbuck);
  assert (newbuck->buckcount == oldcnt);
  buckarr_BM[bucknum] = newbuck;
}                               /* end growobucket_BM */


extern objectval_tyBM *
makeobjofid_BM (const rawid_tyBM id)
{
  if (!validid_BM (id))
    return NULL;
  objectval_tyBM *pob = findobjofid_BM (id);
  if (pob)
    return pob;
  unsigned bucknum = bucknumserial63_BM (id.id_hi);
  struct objbucket_stBM *curbuck = buckarr_BM[bucknum];
  unsigned oldsiz = curbuck ? curbuck->bucksize : 0;
  unsigned oldcnt = curbuck ? curbuck->buckcount : 0;
  if (!curbuck || 4 * oldcnt + 5 > 3 * oldsiz)
    {
      growobucket_BM (bucknum, 6);
      curbuck = buckarr_BM[bucknum];
      assert (curbuck);
    }
  pob = allocgcty_BM (tyObject_BM, sizeof (objectval_tyBM));
  pob->ob_id = id;
  ((typedhead_tyBM *) pob)->hash = hashid_BM (id);
  addtobucket_BM (curbuck, pob);
  return pob;
}                               /* end of makeobjofid_BM */

void
objectgcdestroy_BM (struct garbcoll_stBM *gc, objectval_tyBM * obj)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) obj)->htyp == tyObject_BM);
  // should remove the object name
  // should finalize the object's payloads
  // should remove the object from its bucket
#warning objectgcdestroy_BM incomplete
  FATAL_BM ("objectgcdestroy_BM incomplete obj@%p", obj);
  free (obj);
  gc->gc_freedbytes += sizeof (*obj);
}                               /* end objectgcdestroy_BM */

void
objectgckeep_BM (struct garbcoll_stBM *gc, objectval_tyBM * obj)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) obj)->htyp == tyObject_BM);
  gc->gc_keptbytes += sizeof (*obj);
}                               /* end objectgckeep_BM */

extern objectval_tyBM *
makeobj_BM (void)
{
  for (;;)
    {
      rawid_tyBM id = randomid_BM ();
      objectval_tyBM *pob = findobjofid_BM (id);
      if (pob)
        continue;
      return makeobjofid_BM (id);
    }
}                               /* end of makeobj_BM */

void
objectinteriorgcmark_BM (struct garbcoll_stBM *gc, objectval_tyBM * obj)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (isobject_BM (obj));
  assert (((typedhead_tyBM *) obj)->hgc == MARKGC_BM);
  if (obj->ob_class)
    gcobjmark_BM (gc, obj->ob_class);
  if (obj->ob_compvec)
    datavectgcmark_BM (gc, obj->ob_compvec, 0);
  if (obj->ob_attrassoc)
    assocgcmark_BM (gc, obj->ob_attrassoc, 0);
  if (obj->ob_data)
    gcmark_BM (gc, obj->ob_data, 0);
}                               /* end objectinteriorgcmark_BM */

////////////////////////////////////////////////////////////////

#define HASHSETEMPTYSLOT_BM ((void*)(-1))

static bool
hashsetobj_insert_BM (struct hashsetobj_stBM *hset,
                      const objectval_tyBM * obj)
{
  if (valtype_BM ((const value_tyBM) obj) != tyObject_BM)
    return false;
  if (valtype_BM ((const value_tyBM) hset) != tydata_hashsetobj_BM)
    return false;
  unsigned alsiz = ((typedhead_tyBM *) hset)->rlen;
  unsigned ucnt = ((typedsize_tyBM *) hset)->size;
  assert (ucnt < alsiz && alsiz > 3);
  hash_tyBM hob = objecthash_BM (obj);
  unsigned startix = hob % alsiz;
  int pos = -1;
  for (unsigned ix = startix; ix < alsiz; ix++)
    {
      objectval_tyBM *curobj = hset->hashset_objs[ix];
      if (curobj == obj)
        return true;
      if (!curobj)
        {
          if (pos < 0)
            pos = (int) ix;
          hset->hashset_objs[pos] = (objectval_tyBM *) obj;
          ((typedsize_tyBM *) hset)->size = ucnt + 1;
          return true;
        };
      if (curobj == HASHSETEMPTYSLOT_BM)
        {
          if (pos < 0)
            pos = (int) ix;
        };
    }
  for (unsigned ix = 0; ix < startix; ix++)
    {
      objectval_tyBM *curobj = hset->hashset_objs[ix];
      if (curobj == obj)
        return true;
      if (!curobj)
        {
          if (pos < 0)
            pos = (int) ix;
          hset->hashset_objs[pos] = (objectval_tyBM *) obj;
          ((typedsize_tyBM *) hset)->size = ucnt + 1;
          return true;
        };
      if (curobj == HASHSETEMPTYSLOT_BM)
        {
          if (pos < 0)
            pos = (int) ix;
        };
    }
  if (pos >= 0)
    {
      hset->hashset_objs[pos] = (objectval_tyBM *) obj;
      ((typedsize_tyBM *) hset)->size = ucnt + 1;
      return true;
    }
  return false;
}                               /* end hashsetobj_insert_BM */


struct hashsetobj_stBM *
hashsetobj_grow_BM (struct hashsetobj_stBM *hset, unsigned gap)
{
  if (valtype_BM ((const value_tyBM) hset) != tydata_hashsetobj_BM)
    {
      unsigned newsiz = prime_above_BM (4 * gap / 3 + 10);
      hset =                    //
        allocinternalty_BM (tydata_hashsetobj_BM,
                            sizeof (struct hashsetobj_stBM)
                            + newsiz * sizeof (void *));
      ((typedhead_tyBM *) hset)->rlen = newsiz;
      ((typedsize_tyBM *) hset)->size = 0;
      return hset;
    }
  unsigned alsiz = ((typedhead_tyBM *) hset)->rlen;
  unsigned ucnt = ((typedsize_tyBM *) hset)->size;
  if (4 * (ucnt + gap) + 5 < 3 * alsiz)
    return hset;
  unsigned newsiz = prime_above_BM ((4 * (ucnt + gap)) / 3 + 10);
  if (alsiz >= newsiz)
    return hset;
  struct hashsetobj_stBM *newhset =     //
    allocinternalty_BM (tydata_hashsetobj_BM,
                        sizeof (struct hashsetobj_stBM)
                        + newsiz * sizeof (void *));
  ((typedhead_tyBM *) newhset)->rlen = newsiz;
  ((typedsize_tyBM *) newhset)->size = 0;
  for (unsigned oix = 0; oix < alsiz; oix++)
    {
      const objectval_tyBM *oldobj = hset->hashset_objs[oix];
      if (!oldobj || oldobj == HASHSETEMPTYSLOT_BM)
        continue;
      if (!hashsetobj_insert_BM (newhset, oldobj))
        FATAL_BM ("corrupted hashset");
    }
  free (hset);
  return newhset;
}                               /* end hashsetobj_grow_BM */


bool
hashsetobj_contains_BM (struct hashsetobj_stBM * hset,
                        const objectval_tyBM * obj)
{
  if (valtype_BM ((const value_tyBM) obj) != tyObject_BM)
    return false;
  if (valtype_BM ((const value_tyBM) hset) != tydata_hashsetobj_BM)
    return false;
  unsigned alsiz = ((typedhead_tyBM *) hset)->rlen;
  unsigned ucnt = ((typedsize_tyBM *) hset)->size;
  assert (ucnt < alsiz && alsiz > 3);
  hash_tyBM hob = objecthash_BM (obj);
  unsigned startix = hob % alsiz;
  for (unsigned ix = startix; ix < alsiz; ix++)
    {
      objectval_tyBM *curobj = hset->hashset_objs[ix];
      if (curobj == obj)
        return true;
      if (!curobj)
        return false;
    };
  for (unsigned ix = 0; ix < startix; ix++)
    {
      objectval_tyBM *curobj = hset->hashset_objs[ix];
      if (curobj == obj)
        return true;
      if (!curobj)
        return false;
    };
  return false;
}                               /* end hashsetobj_contains_BM */


struct hashsetobj_stBM *
hashsetobj_add_BM (struct hashsetobj_stBM *hset, const objectval_tyBM * obj)
{
  if (valtype_BM ((const value_tyBM) hset) != tydata_hashsetobj_BM)
    {
      if (valtype_BM ((const value_tyBM) obj) != tyObject_BM)
        return NULL;
      hset = hashsetobj_grow_BM (NULL, TINYSIZE_BM / 2);
      if (!hashsetobj_insert_BM (hset, obj))
        FATAL_BM ("corrupted hashset");
      return hset;
    };
  if (valtype_BM ((const value_tyBM) obj) != tyObject_BM)
    return hset;
  unsigned alsiz = ((typedhead_tyBM *) hset)->rlen;
  unsigned ucnt = ((typedsize_tyBM *) hset)->size;
  assert (ucnt < alsiz && alsiz > 3);
  if (4 * ucnt + 8 >= 3 * alsiz)
    {
      hset = hashsetobj_grow_BM (hset, ucnt / 64 + 4);
      alsiz = ((typedhead_tyBM *) hset)->rlen;
      ucnt = ((typedsize_tyBM *) hset)->size;
    };
  if (!hashsetobj_insert_BM (hset, obj))
    FATAL_BM ("corrupted hashset");
  return hset;
}                               /* end hashsetobj_add_BM */


struct hashsetobj_stBM *
hashsetobj_remove_BM (struct hashsetobj_stBM *hset,
                      const objectval_tyBM * obj)
{
  if (valtype_BM ((const value_tyBM) hset) != tydata_hashsetobj_BM)
    return NULL;
  if (valtype_BM ((const value_tyBM) obj) != tyObject_BM)
    return hset;
  unsigned alsiz = ((typedhead_tyBM *) hset)->rlen;
  unsigned ucnt = ((typedsize_tyBM *) hset)->size;
  if (alsiz > TINYSIZE_BM && 3 * ucnt < alsiz)
    {
      struct hashsetobj_stBM *newhset =
        hashsetobj_grow_BM (NULL, (3 * ucnt / 2) + ucnt / 32 + 3);
      for (unsigned ix = 0; ix < alsiz; ix++)
        {
          objectval_tyBM *curobj = hset->hashset_objs[ix];
          if (curobj != NULL && curobj != HASHSETEMPTYSLOT_BM
              && curobj != obj)
            {
              if (!hashsetobj_insert_BM (newhset, obj))
                FATAL_BM ("corrupted hashset");
            }
        }
      free (hset);
      return newhset;
    }
  hash_tyBM hob = objecthash_BM (obj);
  unsigned startix = hob % alsiz;
  for (unsigned ix = startix; ix < alsiz; ix++)
    {
      objectval_tyBM *curobj = hset->hashset_objs[ix];
      if (curobj == obj)
        {
          hset->hashset_objs[ix] = HASHSETEMPTYSLOT_BM;
          ((typedsize_tyBM *) hset)->size = ucnt - 1;
          return hset;
        }
      if (!curobj)
        return hset;
    };
  for (unsigned ix = 0; ix < startix; ix++)
    {
      objectval_tyBM *curobj = hset->hashset_objs[ix];
      if (curobj == obj)
        {
          hset->hashset_objs[ix] = HASHSETEMPTYSLOT_BM;
          ((typedsize_tyBM *) hset)->size = ucnt - 1;
          return hset;
        }
      if (!curobj)
        return hset;
    };
  return hset;
}                               /* end hashsetobj_remove_BM  */

const setval_tyBM *
hashsetobj_to_set_BM (struct hashsetobj_stBM *hset)
{
  if (valtype_BM ((const value_tyBM) hset) != tydata_hashsetobj_BM)
    return NULL;
  unsigned alsiz = ((typedhead_tyBM *) hset)->rlen;
  unsigned ucnt = ((typedsize_tyBM *) hset)->size;
  if (ucnt == 0)
    return makeset_BM (NULL, 0);
  const objectval_tyBM **arr = calloc (ucnt, sizeof (objectval_tyBM *));
  if (!arr)
    FATAL_BM ("calloc %u objptrs failed %m", ucnt);
  unsigned elcnt = 0;
  for (unsigned ix = 0; ix < alsiz; ix++)
    {
      objectval_tyBM *curobj = hset->hashset_objs[ix];
      if (!curobj || curobj == HASHSETEMPTYSLOT_BM)
        continue;
      assert (valtype_BM ((const value_tyBM) curobj) == tyObject_BM);
      assert (elcnt < ucnt);
      arr[elcnt++] = (const objectval_tyBM *) curobj;
    };
  assert (elcnt == ucnt);
  const setval_tyBM *set = makeset_BM (arr, elcnt);
  free (arr);
  return set;
}                               /* end hashsetobj_to_set_BM */


void
hashsetgcmark_BM (struct garbcoll_stBM *gc, struct hashsetobj_stBM *hset)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (valtype_BM ((const value_tyBM) hset) == tydata_hashsetobj_BM);
  uint8_t oldmark = ((typedhead_tyBM *) hset)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) hset)->hgc = MARKGC_BM;
  unsigned alsiz = ((typedhead_tyBM *) hset)->rlen;
  unsigned ucnt = ((typedsize_tyBM *) hset)->size;
  unsigned elcnt = 0;
  for (unsigned ix = 0; ix < alsiz; ix++)
    {
      objectval_tyBM *curobj = hset->hashset_objs[ix];
      if (!curobj || curobj == HASHSETEMPTYSLOT_BM)
        continue;
      assert (valtype_BM ((const value_tyBM) curobj) == tyObject_BM);
      assert (elcnt < ucnt);
      gcobjmark_BM (gc, curobj);
      elcnt++;
    };
  assert (elcnt == ucnt);
}                               /* end hashsetgcmark_BM */

void
hashsetgcdestroy_BM (struct garbcoll_stBM *gc, struct hashsetobj_stBM *hset)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) hset)->htyp == tydata_hashsetobj_BM);
  unsigned alsiz = ((typedhead_tyBM *) hset)->rlen;
  memset (hset, 0, sizeof (*hset) + alsiz * sizeof (void *));
  free (hset);
  gc->gc_freedbytes += sizeof (*hset) + alsiz * sizeof (void *);
}                               /* end hashsetgcdestroy_BM */

void
hashsetgckeep_BM (struct garbcoll_stBM *gc, struct hashsetobj_stBM *hset)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) hset)->htyp == tydata_hashsetobj_BM);
  unsigned alsiz = ((typedhead_tyBM *) hset)->rlen;
  gc->gc_keptbytes += sizeof (*hset) + alsiz * sizeof (void *);
}                               /* end hashsetgckeep_BM */

////////////////////////////////////////////////////////////////
static void
register_predefined_object_BM (objectval_tyBM * pob)
{
  assert (valtype_BM ((const value_tyBM) pob) == tyObject_BM);
  assert (pob->ob_id.id_hi > 0 && pob->ob_id.id_lo > 0);
  assert (findobjofid_BM (pob->ob_id) == NULL);
  assert (((typedhead_tyBM *) pob)->hash == hashid_BM (pob->ob_id));
  unsigned bucknum = bucknumserial63_BM (pob->ob_id.id_hi);
  growobucket_BM (bucknum, 4);
  struct objbucket_stBM *curbuck = buckarr_BM[bucknum];
  assert (curbuck != NULL);
  addtobucket_BM (curbuck, pob);
  assert (curbuck->buckcount > 0 && curbuck->buckcount <= curbuck->bucksize);
  assert (findobjofid_BM (pob->ob_id) == pob);
  hashset_predefined_objects_BM =       //
    hashsetobj_add_BM (hashset_predefined_objects_BM, pob);
  char idbuf[32];
  memset (idbuf, 0, sizeof (idbuf));
  idtocbuf32_BM (pob->ob_id, idbuf);
  assert (idbuf[0] == '_' && isdigit (idbuf[1]));
  char nambuf[48];
  memset (nambuf, 0, sizeof (nambuf));
  snprintf (nambuf, sizeof (nambuf),    //
            ROUTINEOBJPREFIX_BM "%s" ROUTINEOBJSUFFIX_BM, idbuf);
  void *ad = dlsym (dlprog_BM, nambuf);
  if (ad)
    pob->ob_rout = (objrout_sigBM *) ad;
}                               /* end register_predefined_object_BM */

void
initialize_predefined_objects_BM (void)
{
  hashset_predefined_objects_BM =       //
    hashsetobj_grow_BM (NULL, 2 * BM_NB_PREDEFINED + 50);
  //
#define HAS_PREDEF_BM(Id,Hi,Lo,Hash)    {               \
    assert(hashid_BM((rawid_tyBM){Hi,Lo})==Hash);	\
    assert(equalid_BM(parse_rawid_BM(#Id,NULL),		\
		      (rawid_tyBM){Hi,Lo}));		\
    register_predefined_object_BM(PREDEF_BM(Id)); };
  //
#include "_bm_predef.h"
  //
  fflush (NULL);
  assert (findobjofid_BM (parse_rawid_BM ("_01h86SAfOfg_1q2oMegGRwW", NULL))
          == BMP_comment);
}                               /* end initialize_predefined_objects_BM */

const setval_tyBM *
setpredefinedobjects_BM (void)
{
  return hashsetobj_to_set_BM (hashset_predefined_objects_BM);
}                               /* end setpredefinedobjects_BM */


void
gcmarkpredefinedobjects_BM (struct garbcoll_stBM *gc)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  hashsetgcmark_BM (gc, hashset_predefined_objects_BM);
}                               /* end gcmarkpredefinedobjects_BM */


void
objputspace_BM (objectval_tyBM * obj, unsigned spanum)
{
  if (!isobject_BM ((const value_tyBM) obj))
    return;
  assert (spanum < LASTSPACE__BM);
  unsigned oldspanum = obj->ob_space;
  if (oldspanum == spanum)
    return;
  if (oldspanum == PredefSp_BM)
    {
      assert (hashsetobj_contains_BM (hashset_predefined_objects_BM, obj));
      hashset_predefined_objects_BM =   //
        hashsetobj_remove_BM (hashset_predefined_objects_BM, obj);
    };
  if (spanum == PredefSp_BM)
    {
      hashset_predefined_objects_BM =
        hashsetobj_add_BM (hashset_predefined_objects_BM, obj);
    }
  obj->ob_space = spanum;
}                               /* end objputspace_BM  */

void
objputattr_BM (objectval_tyBM * obj, objectval_tyBM * objattr,
               const value_tyBM valattr)
{
  if (!isobject_BM ((const value_tyBM) obj))
    return;
  if (!isobject_BM ((const value_tyBM) objattr))
    return;
  if (!valattr)
    obj->ob_attrassoc = assoc_removeattr_BM (obj->ob_attrassoc, objattr);
  else
    obj->ob_attrassoc =
      assoc_addattr_BM (obj->ob_attrassoc, objattr, valattr);
}                               /* end objputattr_BM */

void
objremoveattr_BM (objectval_tyBM * obj, objectval_tyBM * objattr)
{
  if (!isobject_BM ((const value_tyBM) obj))
    return;
  if (!isobject_BM ((const value_tyBM) objattr))
    return;
  obj->ob_attrassoc = assoc_removeattr_BM (obj->ob_attrassoc, objattr);
}                               /* end objremoveattr_BM */

void
classinfogcmark_BM (struct garbcoll_stBM *gc, struct classinfo_stBM *clinf,
                    int depth)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (valtype_BM ((const value_tyBM) clinf) == tydata_classinfo_BM);
  uint8_t oldmark = ((typedhead_tyBM *) clinf)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) clinf)->hgc = MARKGC_BM;
  if (clinf->clinf_superclass)
    gcobjmark_BM (gc, (objectval_tyBM *) clinf->clinf_superclass);
  if (clinf->clinf_dictmeth)
    assocgcmark_BM (gc, clinf->clinf_dictmeth, depth);
}                               /* end classinfogcmark_BM */

void
classinfogcdestroy_BM (struct garbcoll_stBM *gc, struct classinfo_stBM *clinf)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (valtype_BM ((const value_tyBM) clinf) == tydata_classinfo_BM);
  memset (clinf, 0, sizeof (*clinf));
  free (clinf);
  gc->gc_freedbytes += sizeof (*clinf);
}                               /* end classinfogcdestroy_BM */

void
classinfogckeep_BM (struct garbcoll_stBM *gc, struct classinfo_stBM *clinf)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (valtype_BM ((const value_tyBM) clinf) == tydata_classinfo_BM);
  gc->gc_keptbytes += sizeof (*clinf);
}                               /* end classinfogckeep_BM */

#warning missing routines to put a fresh classinfo in some object
