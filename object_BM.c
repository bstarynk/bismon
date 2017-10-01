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

static int
objnamedptrqcmp_BM (const void *p1, const void *p2)
{
  return objectnamedcmp_BM (*(const objectval_tyBM **) p1,
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


void
sortnamedobjarr_BM (const objectval_tyBM ** obarr, size_t arrsiz)
{
  if (obarr == NULL)
    arrsiz = 0;
  if (arrsiz > 1)
    qsort (obarr, arrsiz, sizeof (const objectval_tyBM *),
           objnamedptrqcmp_BM);
}                               /* end sortnamedobjarr_BM */



struct objbucket_stBM
{
  unsigned bucksize;            /* a prime number */
  unsigned buckcount;           // used count
  objectval_tyBM *buckobjs[];   // allocated size is bucksize
};

static struct objbucket_stBM *buckarr_BM[MAXBUCKETS_BM];

#define EMPTYSLOTOB_BM ((objectval_tyBM*)(-1))

const setval_tyBM *
setobjectsofidprefixed_BM (const char *prefix)
{
  const setval_tyBM *setv = NULL;
  if (!prefix || prefix[0] != '_' || !isdigit (prefix[1])
      || !isalnum (prefix[2]))
    return NULL;
  int prefixlen = strlen (prefix);
  if (prefixlen > 32)
    return NULL;
  const char *b62digits = B62DIGITS_BM;
  char *p = strchr (b62digits, prefix[2]);
  if (!p)
    return NULL;
  int bucknum = (prefix[1] - '0') * 62 + (p - b62digits);
  assert (bucknum >= 0 && bucknum < MAXBUCKETS_BM);
  struct objbucket_stBM *curbuck = buckarr_BM[bucknum];
  if (!curbuck)
    return NULL;
  const objectval_tyBM *tinyarr[TINYSIZE_BM] = { };
  const objectval_tyBM **arr = tinyarr;
  unsigned siz = TINYSIZE_BM;
  unsigned cnt = 0;
  unsigned busiz = curbuck->bucksize;
  for (unsigned ix = 0; ix < busiz; ix++)
    {
      objectval_tyBM *curob = curbuck->buckobjs[ix];
      if (!curob || curob == EMPTYSLOTOB_BM)
        continue;
      char curidbuf[32];
      memset (curidbuf, 0, sizeof (curidbuf));
      idtocbuf32_BM (curob->ob_id, curidbuf);
      assert (curidbuf[0] == '_'
              && curidbuf[1] == prefix[1] && curidbuf[2] == prefix[2]);
      if (!strncmp (curidbuf, prefix, prefixlen))
        {
          if (cnt >= siz)
            {
              unsigned newsiz =
                prime_above_BM (4 * cnt / 3 + TINYSIZE_BM + 2);
              const objectval_tyBM **newarr =
                calloc (newsiz, sizeof (void *));
              if (!newarr)
                FATAL_BM ("calloc failure for %u", newsiz);
              memcpy (newarr, arr, cnt * sizeof (void *));
              if (arr != tinyarr)
                free (arr);
              arr = newarr;
              siz = newsiz;
            };
          arr[cnt++] = curob;
        }
    }
  setv = makeset_BM (arr, cnt);
  if (arr != tinyarr)
    free (arr), arr = NULL;
  return setv;
}                               /* end setobjectsofidprefixed_BM */



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
  // remove the object name
  forgetnamedobject_BM (obj);
  obj->ob_space = TransientSp_BM;
  obj->ob_class = NULL;
  obj->ob_compvec = NULL;
  obj->ob_attrassoc = NULL;
  obj->ob_rout = NULL;
  obj->ob_data = NULL;
  // should remove the object from its bucket
  const rawid_tyBM id = obj->ob_id;
  assert (validid_BM (id));
  unsigned bucknum = bucknumserial63_BM (id.id_hi);
  struct objbucket_stBM *curbuck = buckarr_BM[bucknum];
  assert (curbuck != NULL);
  unsigned busiz = curbuck->bucksize;
  unsigned bucnt = curbuck->buckcount;
  assert (bucnt < busiz);
  hash_tyBM h = objecthash_BM (obj);
  assert (h > 0);
  unsigned startix = h % busiz;
  int pos = -1;
  for (unsigned ix = startix; ix < busiz && pos < 0; ix++)
    {
      objectval_tyBM *curob = curbuck->buckobjs[ix];
      if (!curob)
        break;
      if (curob == obj)
        pos = (int) ix;
    };
  for (unsigned ix = 0; ix < startix && pos < 0; ix++)
    {
      objectval_tyBM *curob = curbuck->buckobjs[ix];
      if (!curob)
        break;
      if (curob == obj)
        pos = (int) ix;
    };
  assert (pos >= 0);
  curbuck->buckobjs[pos] = EMPTYSLOTOB_BM;
  curbuck->buckcount--;
  memset (obj, 0, sizeof (*obj));
  free (obj);
  gc->gc_freedbytes += sizeof (*obj);
  gc->gc_nbdestroyedobjects++;
}                               /* end objectgcdestroy_BM */

void
objectgckeep_BM (struct garbcoll_stBM *gc, objectval_tyBM * obj)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) obj)->htyp == tyObject_BM);
  gc->gc_keptbytes += sizeof (*obj);
  gc->gc_nbkeptobjects++;
}                               /* end objectgckeep_BM */

const char *
iddbg_BM (rawid_tyBM id)
{
  if (id.id_hi == 0 && id.id_lo == 0)
    return "__";
  else
    {
      static char idbuf[32];
      memset (idbuf, 0, sizeof (idbuf));
      idtocbuf32_BM (id, idbuf);
      return idbuf;
    }
}                               /* end iddbg_BM */

const char *
iddbg1_BM (rawid_tyBM id)
{
  if (id.id_hi == 0 && id.id_lo == 0)
    return "__";
  else
    {
      static char idbuf[32];
      memset (idbuf, 0, sizeof (idbuf));
      idtocbuf32_BM (id, idbuf);
      return idbuf;
    }
}                               /* end iddbg1_BM */

const char *
iddbg2_BM (rawid_tyBM id)
{
  if (id.id_hi == 0 && id.id_lo == 0)
    return "__";
  else
    {
      static char idbuf[32];
      memset (idbuf, 0, sizeof (idbuf));
      idtocbuf32_BM (id, idbuf);
      return idbuf;
    }
}                               /* end iddbg2_BM */


const char *
objectdbg_BM (const objectval_tyBM * obj)
{
  if (!obj)
    return "__";
  if (!isobject_BM ((const value_tyBM) obj))
    return "*nonobject*";
  const char *n = findobjectname_BM (obj);
  if (n)
    return n;
  static char idbuf[32];
  memset (idbuf, 0, sizeof (idbuf));
  idtocbuf32_BM (obj->ob_id, idbuf);
  return idbuf;
}                               /* end objectdbg_BM */


const char *
objectdbg1_BM (const objectval_tyBM * obj)
{
  if (!obj)
    return "__";
  if (!isobject_BM ((const value_tyBM) obj))
    return "*nonobject*";
  const char *n = findobjectname_BM (obj);
  if (n)
    return n;
  static char idbuf[32];
  memset (idbuf, 0, sizeof (idbuf));
  idtocbuf32_BM (obj->ob_id, idbuf);
  return idbuf;
}                               /* end objectdbg1_BM */


const char *
objectdbg2_BM (const objectval_tyBM * obj)
{
  if (!obj)
    return "__";
  if (!isobject_BM ((const value_tyBM) obj))
    return "*nonobject*";
  const char *n = findobjectname_BM (obj);
  if (n)
    return n;
  static char idbuf[32];
  memset (idbuf, 0, sizeof (idbuf));
  idtocbuf32_BM (obj->ob_id, idbuf);
  return idbuf;
}                               /* end objectdbg2_BM */


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
        allocgcty_BM (tydata_hashsetobj_BM,
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
    allocgcty_BM (tydata_hashsetobj_BM,
                  sizeof (struct hashsetobj_stBM) + newsiz * sizeof (void *));
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
  gc->gc_nbmarks++;
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
  assert (alsiz < MAXSIZE_BM);
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
  char symbuf[48];
  memset (symbuf, 0, sizeof (symbuf));
  snprintf (symbuf, sizeof (symbuf),    //
            ROUTINEOBJPREFIX_BM "%s" ROUTINEOBJSUFFIX_BM, idbuf);
  void *ad = dlsym (dlprog_BM, symbuf);
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
  assert (valtype_BM (hashset_predefined_objects_BM) == tydata_hashsetobj_BM);
  // clear the mark of statically allocated predefined
#define HAS_PREDEF_BM(Id,Hi,Lo,Hash) {					\
    assert (valtype_BM(&predefdata##Id##_BM) == tyObject_BM);		\
    if (predefdata##Id##_BM.ob_space == PredefSp_BM)			\
      ((typedhead_tyBM*)&predefdata##Id##_BM)->hgc = CLEARMGC_BM;	\
  }
#include "_bm_predef.h"
  //
  hashsetgcmark_BM (gc, hashset_predefined_objects_BM);
}                               /* end gcmarkpredefinedobjects_BM */


void
objputspacenum_BM (objectval_tyBM * obj, unsigned spanum)
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
}                               /* end objputspacenum_BM  */


void
objputclass_BM (objectval_tyBM * obj, objectval_tyBM * objclass)
{
  if (!isobject_BM ((const value_tyBM) obj))
    return;
  if (objclass && !isobject_BM ((const value_tyBM) objclass))
    return;
  obj->ob_class = objclass;
}                               /* end objputclass_BM */

void
objputattr_BM (objectval_tyBM * obj, const objectval_tyBM * objattr,
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
objresetattrs_BM (objectval_tyBM * obj, unsigned nbattrhint)
{
  if (!isobject_BM ((const value_tyBM) obj))
    return;
  if (nbattrhint < 3)
    nbattrhint = 3;
  obj->ob_attrassoc = NULL;
  assoc_reorganize_BM (&obj->ob_attrassoc, nbattrhint);
}                               /* end objresetattrs_BM */

void
objremoveattr_BM (objectval_tyBM * obj, const objectval_tyBM * objattr)
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
  gc->gc_nbmarks++;
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

void
objputclassinfo_BM (objectval_tyBM * obj, objectval_tyBM * superclass)
{
  if (!isobject_BM ((const value_tyBM) obj))
    return;
  if (superclass && !isobject_BM ((const value_tyBM) superclass))
    return;
  struct classinfo_stBM *clinf =        //
    allocgcty_BM (tydata_classinfo_BM, sizeof (struct classinfo_stBM));
  clinf->clinf_superclass = superclass;
  clinf->clinf_dictmeth = NULL;
  obj->ob_data = clinf;
}                               /* end objputclassinfo_BM */


void
objclassinfoputmethod_BM (objectval_tyBM * obj, objectval_tyBM * obselector,
                          const closure_tyBM * clos)
{
  if (!isobject_BM ((const value_tyBM) obj))
    return;
  if (!isobject_BM ((const value_tyBM) obselector))
    return;
  if (!isclosure_BM ((const value_tyBM) clos))
    return;
  if (!objhasclassinfo_BM (obj))
    return;
  struct classinfo_stBM *clinf =        //
    (struct classinfo_stBM *) (obj->ob_data);
  assert (valtype_BM ((const value_tyBM) clinf) == tydata_classinfo_BM);
  clinf->clinf_dictmeth =       //
    assoc_addattr_BM (clinf->clinf_dictmeth, obselector, (value_tyBM) clos);
}                               /* end objclassinfoputmethod_BM */

void
objclassinforemovemethod_BM (objectval_tyBM * obj,
                             objectval_tyBM * obselector)
{
  if (!isobject_BM ((const value_tyBM) obj))
    return;
  if (!isobject_BM ((const value_tyBM) obselector))
    return;
  if (!objhasclassinfo_BM (obj))
    return;
  struct classinfo_stBM *clinf =        //
    (struct classinfo_stBM *) (obj->ob_data);
  assert (valtype_BM ((const value_tyBM) clinf) == tydata_classinfo_BM);
  clinf->clinf_dictmeth =       //
    assoc_removeattr_BM (clinf->clinf_dictmeth, obselector);
}                               /* end objclassinforemovemethod_BM */

bool
objclassinfoissubclass_BM (const objectval_tyBM * obj,
                           const objectval_tyBM * obclass)
{
  int count = 0;
  if (!isobject_BM ((const value_tyBM) obclass))
    return false;
  while (count < MAXDEPTHMETHOD_BM)
    {
      if (obj == obclass)
        return true;
      if (!isobject_BM ((const value_tyBM) obj))
        return false;
      if (!objhasclassinfo_BM (obj))
        return false;
      struct classinfo_stBM *clinf =    //
        (struct classinfo_stBM *) (obj->ob_data);
      obj = clinf->clinf_superclass;
      count++;
    }
  return false;
}                               /* end objclassinfoissubclass_BM */

const closure_tyBM *
valfindmethod_BM (const value_tyBM recv, const objectval_tyBM * obselector)
{
  if (!isobject_BM ((const value_tyBM) obselector))
    return NULL;
  objectval_tyBM *obclass = valclass_BM (recv);
  int loopcnt = 0;
  do
    {
      if (!obclass)
        return NULL;
      if (loopcnt > MAXDEPTHMETHOD_BM)
        return NULL;
      assert (isobject_BM (obclass));
      const closure_tyBM *mclos =
        objgetclassinfomethod_BM (obclass, obselector);
      if (mclos)
        {
          assert (isclosure_BM ((const value_tyBM) mclos));
          return mclos;
        };
      obclass = objgetclassinfosuperclass_BM (obclass);
      loopcnt++;
    }
  while (obclass);
  return NULL;
}                               /* end objfindmethod_BM */


value_tyBM
send0_BM (const value_tyBM recv, const objectval_tyBM * obselector,
          struct stackframe_stBM * stkf)
{
  if (!isobject_BM ((const value_tyBM) obselector))
    return NULL;
  const closure_tyBM *mclos = valfindmethod_BM (recv, obselector);
  if (!mclos)
    return NULL;
  assert (isclosure_BM ((const value_tyBM) mclos));
  return apply1_BM (mclos, stkf, recv);
}                               /* end send0_BM */


value_tyBM
send1_BM (const value_tyBM recv, const objectval_tyBM * obselector,
          struct stackframe_stBM * stkf, const value_tyBM arg1)
{
  if (!isobject_BM ((const value_tyBM) obselector))
    return NULL;
  const closure_tyBM *mclos = valfindmethod_BM (recv, obselector);
  if (!mclos)
    return NULL;
  assert (isclosure_BM ((const value_tyBM) mclos));
  return apply2_BM (mclos, stkf, recv, arg1);
}                               /* end send1_BM */


value_tyBM
send2_BM (const value_tyBM recv, const objectval_tyBM * obselector,
          struct stackframe_stBM * stkf, const value_tyBM arg1,
          const value_tyBM arg2)
{
  if (!isobject_BM ((const value_tyBM) obselector))
    return NULL;
  const closure_tyBM *mclos = valfindmethod_BM (recv, obselector);
  if (!mclos)
    return NULL;
  assert (isclosure_BM ((const value_tyBM) mclos));
  return apply3_BM (mclos, stkf, recv, arg1, arg2);
}                               /* end send2_BM */


value_tyBM
send3_BM (const value_tyBM recv, const objectval_tyBM * obselector,
          struct stackframe_stBM * stkf, const value_tyBM arg1,
          const value_tyBM arg2, const value_tyBM arg3)
{
  if (!isobject_BM ((const value_tyBM) obselector))
    return NULL;
  const closure_tyBM *mclos = valfindmethod_BM (recv, obselector);
  if (!mclos)
    return NULL;
  assert (isclosure_BM ((const value_tyBM) mclos));
  return apply4_BM (mclos, stkf, recv, arg1, arg2, arg3);
}                               /* end send3_BM */


value_tyBM
send4_BM (const value_tyBM recv, const objectval_tyBM * obselector,
          struct stackframe_stBM * stkf, const value_tyBM arg1,
          const value_tyBM arg2, const value_tyBM arg3, const value_tyBM arg4)
{
  if (!isobject_BM ((const value_tyBM) obselector))
    return NULL;
  const closure_tyBM *mclos = valfindmethod_BM (recv, obselector);
  if (!mclos)
    return NULL;
  assert (isclosure_BM ((const value_tyBM) mclos));
  return apply5_BM (mclos, stkf, recv, arg1, arg2, arg3, arg4);
}                               /* end send4_BM */


value_tyBM
send5_BM (const value_tyBM recv, const objectval_tyBM * obselector,
          struct stackframe_stBM * stkf, const value_tyBM arg1,
          const value_tyBM arg2, const value_tyBM arg3, const value_tyBM arg4,
          const value_tyBM arg5)
{
  if (!isobject_BM ((const value_tyBM) obselector))
    return NULL;
  const closure_tyBM *mclos = valfindmethod_BM (recv, obselector);
  if (!mclos)
    return NULL;
  assert (isclosure_BM ((const value_tyBM) mclos));
  return apply6_BM (mclos, stkf, recv, arg1, arg2, arg3, arg4, arg5);
}                               /* end send5_BM */


value_tyBM
send6_BM (const value_tyBM recv, const objectval_tyBM * obselector,
          struct stackframe_stBM * stkf, const value_tyBM arg1,
          const value_tyBM arg2, const value_tyBM arg3, const value_tyBM arg4,
          const value_tyBM arg5, const value_tyBM arg6)
{
  if (!isobject_BM ((const value_tyBM) obselector))
    return NULL;
  const closure_tyBM *mclos = valfindmethod_BM (recv, obselector);
  if (!mclos)
    return NULL;
  assert (isclosure_BM ((const value_tyBM) mclos));
  return apply7_BM (mclos, stkf, recv, arg1, arg2, arg3, arg4, arg5, arg6);
}                               /* end send6_BM */


value_tyBM
send7_BM (const value_tyBM recv, const objectval_tyBM * obselector,
          struct stackframe_stBM * stkf, const value_tyBM arg1,
          const value_tyBM arg2, const value_tyBM arg3, const value_tyBM arg4,
          const value_tyBM arg5, const value_tyBM arg6, const value_tyBM arg7)
{
  if (!isobject_BM ((const value_tyBM) obselector))
    return NULL;
  const closure_tyBM *mclos = valfindmethod_BM (recv, obselector);
  if (!mclos)
    return NULL;
  assert (isclosure_BM ((const value_tyBM) mclos));
  return apply8_BM (mclos, stkf, recv, arg1, arg2, arg3, arg4, arg5, arg6,
                    arg7);
}                               /* end send7_BM */


value_tyBM
send8_BM (const value_tyBM recv, const objectval_tyBM * obselector,
          struct stackframe_stBM * stkf, const value_tyBM arg1,
          const value_tyBM arg2, const value_tyBM arg3, const value_tyBM arg4,
          const value_tyBM arg5, const value_tyBM arg6, const value_tyBM arg7,
          const value_tyBM arg8)
{
  if (!isobject_BM ((const value_tyBM) obselector))
    return NULL;
  const closure_tyBM *mclos = valfindmethod_BM (recv, obselector);
  if (!mclos)
    return NULL;
  assert (isclosure_BM ((const value_tyBM) mclos));
  return apply9_BM (mclos, stkf, recv, arg1, arg2, arg3, arg4, arg5, arg6,
                    arg7, arg8);
}                               /* end send8_BM */
