// file funinline_BM.h
#ifndef FUNINLINE_BM_INCLUDED
#define FUNINLINE_BM_INCLUDED


bool
istaggedint_BM (value_BM v)
{
  return (uintptr_t) v & 1;
}                               /* end istaggedint_BM */

intptr_t
getint_BM (value_BM v)
{
  if (istaggedint_BM (v))
    return ((intptr_t) v) >> 1;
}                               /* end getint_BM */

value_BM
taggedint_BM (intptr_t i)
{
  return (value_BM) ((i << 1) | 1);
}                               /* end taggedint_BM */

int
valtype_BM (value_BM v)
{
  if (!v)
    return tyNone_BM;
  if (istaggedint_BM (v))
    return tyInt_BM;
  if (((uintptr_t) v & 3) == 0)
    {
      typedhead_tyBM *ht = (typedhead_tyBM *) v;
      assert (ht->htyp != 0);
      return ht->htyp;
    }
  return tyNone_BM;
}                               /* end valtype_BM */

bool
validserial63_BM (serial63_tyBM s)
{
  return (s > MINSERIAL_BM && s < MAXSERIAL_BM);
}                               /* end validserial63_BM */



bool
validid_BM (rawid_tyBM id)
{
  return (validserial63_BM (id.id_hi) && validserial63_BM (id.id_lo));
}                               /* end validid_BM */



hash_tyBM
hashid_BM (rawid_tyBM id)
{
  if (!validid_BM (id))
    return 0;
  hash_tyBM h = (id.id_hi % 1073741939) ^ (id.id_lo % 596789351);
  if (h == 0)
    h = (id.id_hi & 0xffffff) + (id.id_lo & 0x3ffffff) + 17;
  assert (h > 0);
  return h;
}                               /* end hashid_BM */



int
cmpid_BM (rawid_tyBM id1, rawid_tyBM id2)
{
  if (id1.id_hi == id2.id_hi)
    {
      if (id1.id_lo == id2.id_lo)
        return 0;
      else if (id1.id_lo < id2.id_lo)
        return -1;
      else
        return +1;
    }
  else if (id1.id_hi < id2.id_hi)
    return -1;
  else
    return +1;
}                               /* end cmpid_BM */


bool
equalid_BM (rawid_tyBM id1, rawid_tyBM id2)
{
  return id1.id_hi == id2.id_hi && id1.id_lo == id2.id_lo;
}                               /* end equalid_BM */



/// object support
hash_tyBM
objecthash_BM (const objectval_tyBM * pob)
{
  if (!pob || ((intptr_t) pob & 3))
    return 0;
  if (((typedhead_tyBM *) pob)->htyp != tyObject_BM)
    return 0;
  return ((typedhead_tyBM *) pob)->hash;
}                               /* end objecthash_BM */

int
objectcmp_BM (const objectval_tyBM * ob1, const objectval_tyBM * ob2)
{
  if (ob1 == ob2)
    return 0;
  if (ob1
      && (((intptr_t) ob1 & 3)
          || ((typedhead_tyBM *) ob1)->htyp != tyObject_BM))
    FATAL_BM ("bad ob1@%p for objectcmp_BM", ob1);
  if (ob2
      && (((intptr_t) ob1 & 3)
          || ((typedhead_tyBM *) ob2)->htyp != tyObject_BM))
    FATAL_BM ("bad ob2@%p for objectcmp_BM", ob2);
  if (!ob1)
    return -1;
  if (!ob2)
    return +1;
  return cmpid_BM (ob1->ob_id, ob2->ob_id);
}                               /* end objectcmp_BM */

bool
isassoc_BM (value_BM v)
{
  int ty = valtype_BM (v);
  return ty == tydata_assocbucket_BM || ty == tydata_assocpairs_BM;
}                               /* end isassoc_BM */

unsigned
assoc_nbkeys_BM (anyassoc_tyBM * assoc)
{
  int ty = valtype_BM (assoc);
  if (ty == tydata_assocpairs_BM)
    {
      struct assocpairs_stBM *apair = (struct assocpairs_stBM *) assoc;
      return ((typedsize_tyBM *) apair)->size;
    }
  else if (ty == tydata_assocbucket_BM)
    {
      struct assocbucket_stBM *abuck = (struct assocbucket_stBM *) assoc;
      return ((typedsize_tyBM *) abuck)->size;
    }
  return 0;
}                               /* end assoc_nbkeys_BM */

#endif /*FUNINLINE_BM_INCLUDED */
