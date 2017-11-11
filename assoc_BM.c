// file assoc_BM.c
#include "bismon.h"

static struct assocpairs_stBM *
assocpair_put_BM (struct assocpairs_stBM *apairs,
                  const objectval_tyBM * keyob, value_tyBM val)
{
  assert (valtype_BM ((const value_tyBM) keyob) == tyObject_BM);
  assert (valtype_BM (val) != tyNone_BM);
  struct assocpairs_stBM *newpairs = NULL;
  if (!apairs)
    {
      unsigned newsiz = TINYSIZE_BM / 3;
      newpairs =
        allocgcty_BM (tydata_assocpairs_BM,
                      sizeof (struct assocpairs_stBM) +
                      newsiz * sizeof (struct assocentry_stBM));
      ((typedhead_tyBM *) newpairs)->rlen = newsiz;
      ((typedsize_tyBM *) newpairs)->size = 1;
      memset (newpairs->apairs_ent, 0,
              newsiz * sizeof (struct assocentry_stBM));
      newpairs->apairs_ent[0].asso_keyob = keyob;
      newpairs->apairs_ent[0].asso_val = val;
      return newpairs;
    };
  assert (valtype_BM (apairs) == tydata_assocpairs_BM);
  unsigned oldlen = ((typedhead_tyBM *) apairs)->rlen;
  unsigned oldcnt = ((typedsize_tyBM *) apairs)->size;
  assert (oldcnt <= oldlen);
  if (oldcnt == oldlen)
    {
      // if key was here, put new value in entry
      for (unsigned ix = 0; ix < oldlen; ix++)
        {
          if (apairs->apairs_ent[ix].asso_keyob == keyob)
            {
              apairs->apairs_ent[ix].asso_val = val;
              return apairs;
            }
        }
      // should grow
      unsigned long newlen =
        prime_above_BM (4 * oldlen / 3 + oldlen / 64 + 2);
      if (newlen >= MAXSIZE_BM)
        FATAL_BM ("too big assocpairs %lu for oldlen %u", newlen, oldlen);
      newpairs =
        allocgcty_BM (tydata_assocpairs_BM,
                      sizeof (struct assocpairs_stBM) +
                      newlen * sizeof (struct assocentry_stBM));
      ((typedhead_tyBM *) newpairs)->rlen = newlen;
      unsigned cnt = 0;
      for (unsigned ix = 0; ix < oldlen; ix++)
        {
          if (apairs->apairs_ent[ix].asso_keyob
              && apairs->apairs_ent[ix].asso_val)
            {
              newpairs->apairs_ent[cnt++] = apairs->apairs_ent[ix];
              assert (cnt < newlen);
            }
        };
      assert (cnt == oldcnt);
      newpairs->apairs_ent[cnt].asso_keyob = keyob;
      newpairs->apairs_ent[cnt].asso_val = val;
      cnt++;
      ((typedsize_tyBM *) newpairs)->size = cnt;
      return newpairs;
    }
  else
    {
      // should find some empty slot - or the existing one
      assert (oldcnt < oldlen);
      for (unsigned ix = 0; ix < oldlen; ix++)
        {
          struct assocentry_stBM *curent = apairs->apairs_ent + ix;
          if (!curent->asso_keyob)
            {
              assert (!curent->asso_val);
              curent->asso_keyob = keyob;
              curent->asso_val = val;
              ((typedsize_tyBM *) apairs)->size = oldcnt + 1;
              return apairs;
            }
          else if (curent->asso_keyob == keyob)
            {
              assert (curent->asso_val != NULL);
              curent->asso_val = val;
              return apairs;
            }
        };
      // should never be reached
      FATAL_BM ("corrupted assocpair @%p", apairs);
    }
}                               /* end assocpair_put_BM */

static unsigned
assoc_buckix_for_key_BM (const struct assocbucket_stBM *abuck,
                         const objectval_tyBM * obkey)
{
  assert (valtype_BM ((const value_tyBM) abuck) == tydata_assocbucket_BM);
  assert (valtype_BM ((const value_tyBM) obkey) == tyObject_BM);
  hash_tyBM hkey = objecthash_BM (obkey);
  assert (hkey != 0);
  unsigned nbuckets = ((typedhead_tyBM *) abuck)->rlen;
  assert (nbuckets > 2 && nbuckets % 2 != 0);
  return hkey % nbuckets;
}                               /* end assoc_buckix_for_key_BM */

void
assoc_reorganize_BM (anyassoc_tyBM ** passoc, unsigned gap)
{
  assert (passoc != NULL);
  anyassoc_tyBM *oldassoc = *passoc;
  bool oldassocisbucket = valtype_BM (oldassoc) == tydata_assocbucket_BM;
  bool oldassocispairs = valtype_BM (oldassoc) == tydata_assocpairs_BM;
  assert (!oldassoc || isassoc_BM (oldassoc));
  unsigned oldcnt = assoc_nbkeys_BM (oldassoc);
  unsigned long newish = (oldcnt + gap + oldcnt / 128 + gap / 64);
  if (newish <= TINYSIZE_BM)
    {
      unsigned newpairsiz = 0;
      if (newish == 0)
        newpairsiz = 0;
      else if (newish <= TINYSIZE_BM / 3)
        newpairsiz = TINYSIZE_BM / 3;
      else if (newish < 2 * TINYSIZE_BM / 3)
        newpairsiz = 2 * TINYSIZE_BM / 3;
      else
        newpairsiz = TINYSIZE_BM;
      struct assocpairs_stBM *newpairs = newpairsiz ?
        allocgcty_BM (tydata_assocpairs_BM,
                      sizeof (struct assocpairs_stBM) +
                      newpairsiz * sizeof (struct assocentry_stBM)) : NULL;
      if (newpairs)
        {
          ((typedhead_tyBM *) newpairs)->rlen = newpairsiz;
          ((typedsize_tyBM *) newpairs)->size = 0;
        }
      if (oldassocisbucket)
        {
          unsigned newpaircnt = 0;
          unsigned nbuckets = ((typedhead_tyBM *) oldassoc)->rlen;
          for (unsigned buckix = 0; buckix < nbuckets; buckix++)
            {
              struct assocpairs_stBM *curbuckpair =
                ((struct assocbucket_stBM *) oldassoc)->abuck_pairs[buckix];
              if (curbuckpair)
                {
                  assert (valtype_BM (curbuckpair) == tydata_assocpairs_BM);
                  unsigned bucklen = ((typedhead_tyBM *) curbuckpair)->rlen;
                  for (unsigned pix = 0; pix < bucklen; pix++)
                    {
                      const objectval_tyBM *curkeyob =
                        curbuckpair->apairs_ent[pix].asso_keyob;
                      value_tyBM curval =
                        curbuckpair->apairs_ent[pix].asso_val;
                      if (curkeyob && curval)
                        {
                          assert (newpairs && newpaircnt < newpairsiz);
                          assert (valtype_BM ((const value_tyBM) curkeyob) ==
                                  tyObject_BM);
                          assert (valtype_BM (curval) != tyNone_BM);
                          newpairs->apairs_ent[newpaircnt].asso_keyob =
                            curkeyob;
                          newpairs->apairs_ent[newpaircnt].asso_val = curval;
                          newpaircnt++;
                        }
                    }
                  assert (newpaircnt == oldcnt);
                  ((typedsize_tyBM *) newpairs)->size = newpaircnt;
                  ((struct assocbucket_stBM *) oldassoc)->abuck_pairs[buckix]
                    = NULL;
                }
            }
          *passoc = newpairs;
        }
      else if (oldassocispairs)
        {
          struct assocpairs_stBM *oldpairs = oldassoc;
          assert (valtype_BM (oldpairs) == tydata_assocpairs_BM);
          unsigned bucklen = ((typedhead_tyBM *) oldpairs)->rlen;
          unsigned newpaircnt = 0;
          for (unsigned pix = 0; pix < bucklen; pix++)
            {
              const objectval_tyBM *curkeyob =
                oldpairs->apairs_ent[pix].asso_keyob;
              value_tyBM curval = oldpairs->apairs_ent[pix].asso_val;
              if (curkeyob && curval)
                {
                  assert (newpairs && newpaircnt < newpairsiz);
                  assert (valtype_BM ((const value_tyBM) curkeyob) ==
                          tyObject_BM);
                  assert (valtype_BM (curval) != tyNone_BM);
                  newpairs->apairs_ent[newpaircnt].asso_keyob = curkeyob;
                  newpairs->apairs_ent[newpaircnt].asso_val = curval;
                  newpaircnt++;
                }
            }
          assert (newpaircnt == oldcnt);
          *passoc = newpairs;
        }
      else
        *passoc = newpairs;
      return;
    }
  if (newish > MAXSIZE_BM)
    FATAL_BM ("new assoc wish %lu too big", newish);
  unsigned newnbuckets =
    prime_above_BM (newish / (TINYSIZE_BM - 3) + gap / 128 + 4);
  struct assocbucket_stBM *newbuckets = allocgcty_BM (tydata_assocbucket_BM,
                                                      sizeof (struct
                                                              assocbucket_stBM)
                                                      +
                                                      newnbuckets *
                                                      sizeof (void *));
  ((typedhead_tyBM *) newbuckets)->rlen = newnbuckets;
  if (oldassocisbucket)
    {
      unsigned addedcnt = 0;
      unsigned nbuckets = ((typedhead_tyBM *) oldassoc)->rlen;
      for (unsigned buckix = 0; buckix < nbuckets; buckix++)
        {
          struct assocpairs_stBM *curbuckpair =
            ((struct assocbucket_stBM *) oldassoc)->abuck_pairs[buckix];
          if (curbuckpair)
            {
              assert (valtype_BM (curbuckpair) == tydata_assocpairs_BM);
              unsigned bucklen = ((typedhead_tyBM *) curbuckpair)->rlen;
              for (unsigned pix = 0; pix < bucklen; pix++)
                {
                  const objectval_tyBM *curkeyob =
                    curbuckpair->apairs_ent[pix].asso_keyob;
                  value_tyBM curval = curbuckpair->apairs_ent[pix].asso_val;
                  if (curkeyob && curval)
                    {
                      unsigned newbuckix =
                        assoc_buckix_for_key_BM (newbuckets, curkeyob);
                      struct assocpairs_stBM *prevnewpairs =
                        newbuckets->abuck_pairs[newbuckix];
                      struct assocpairs_stBM *updatednewpairs
                        = assocpair_put_BM (prevnewpairs, curkeyob, curval);
                      if (updatednewpairs != prevnewpairs)
                        newbuckets->abuck_pairs[newbuckix] = updatednewpairs;
                      addedcnt++;
                    }
                }
              ((struct assocbucket_stBM *) oldassoc)->abuck_pairs[buckix] =
                NULL;
            }
        }
      assert (addedcnt == oldcnt);
      ((typedsize_tyBM *) newbuckets)->size = addedcnt;
    }
  else if (oldassocispairs)
    {
      struct assocpairs_stBM *oldpairs = oldassoc;
      assert (valtype_BM (oldpairs) == tydata_assocpairs_BM);
      unsigned bucklen = ((typedhead_tyBM *) oldpairs)->rlen;
      unsigned addedcnt = 0;
      for (unsigned pix = 0; pix < bucklen; pix++)
        {
          const objectval_tyBM *curkeyob =
            oldpairs->apairs_ent[pix].asso_keyob;
          value_tyBM curval = oldpairs->apairs_ent[pix].asso_val;
          if (curkeyob && curval)
            {
              unsigned newbuckix =
                assoc_buckix_for_key_BM (newbuckets, curkeyob);
              struct assocpairs_stBM *prevnewpairs =
                newbuckets->abuck_pairs[newbuckix];
              struct assocpairs_stBM *updatednewpairs
                = assocpair_put_BM (prevnewpairs, curkeyob, curval);
              if (updatednewpairs != prevnewpairs)
                newbuckets->abuck_pairs[newbuckix] = updatednewpairs;
              addedcnt++;
            }
        }
      assert (addedcnt == oldcnt);
      ((typedsize_tyBM *) newbuckets)->size = addedcnt;
    }
  *passoc = newbuckets;
}                               /* end assoc_reorganize_BM */

void
assocpairgcdestroy_BM (struct garbcoll_stBM *gc, struct assocpairs_stBM *assp)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) assp)->htyp == tydata_assocpairs_BM);
  unsigned len = ((typedhead_tyBM *) assp)->rlen;
  memset (assp, 0, sizeof (*assp) + len * sizeof (struct assocentry_stBM));
  free (assp);
  gc->gc_freedbytes += sizeof (*assp) + len * sizeof (struct assocentry_stBM);
}                               /* end assocpairgcdestroy_BM */

void
assocpairgckeep_BM (struct garbcoll_stBM *gc, struct assocpairs_stBM *assp)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) assp)->htyp == tydata_assocpairs_BM);
  unsigned len = ((typedhead_tyBM *) assp)->rlen;
  assert (len < MAXSIZE_BM);
  gc->gc_keptbytes += sizeof (*assp) + len * sizeof (struct assocentry_stBM);
}                               /* end assocpairgckeep_BM */

void
assocbucketgcdestroy_BM (struct garbcoll_stBM *gc,
                         struct assocbucket_stBM *abuck)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) abuck)->htyp == tydata_assocbucket_BM);
  unsigned nbuckets = ((typedhead_tyBM *) abuck)->rlen;
  memset (abuck, 0, sizeof (*abuck) + nbuckets * sizeof (void *));
  free (abuck);
  gc->gc_freedbytes += sizeof (*abuck) + nbuckets * sizeof (void *);
}                               /*end assocbucketgcdestroy_BM */


void
assocbucketgckeep_BM (struct garbcoll_stBM *gc,
                      struct assocbucket_stBM *abuck)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) abuck)->htyp == tydata_assocbucket_BM);
  unsigned nbuckets = ((typedhead_tyBM *) abuck)->rlen;
  assert (nbuckets < MAXSIZE_BM);
  gc->gc_keptbytes += sizeof (*abuck) + nbuckets * sizeof (void *);
}                               /* end assocbucketgckeep_BM */


const setval_tyBM *
assoc_setattrs_BM (const anyassoc_tyBM * assoc)
{
  if (!assoc)
    return makeset_BM (NULL, 0);
  if (!isassoc_BM ((const value_tyBM) assoc))
    return NULL;
  unsigned nbkeys = assoc_nbkeys_BM (assoc);
  if (nbkeys == 0)
    return makeset_BM (NULL, 0);
  const objectval_tyBM *tinyarr[TINYSIZE_BM] = { };
  const objectval_tyBM **arr =
    (nbkeys < TINYSIZE_BM) ? tinyarr : calloc (nbkeys, sizeof (void *));
  if (!arr)
    FATAL_BM ("out of memory for %u keys in assoc", nbkeys);
  unsigned keycnt = 0;
  if (valtype_BM ((const value_tyBM) assoc) == tydata_assocbucket_BM)
    {
      unsigned nbuckets = ((typedhead_tyBM *) assoc)->rlen;
      for (unsigned buckix = 0; buckix < nbuckets; buckix++)
        {
          struct assocpairs_stBM *curbuckpair =
            ((struct assocbucket_stBM *) assoc)->abuck_pairs[buckix];
          if (curbuckpair)
            {
              assert (valtype_BM (curbuckpair) == tydata_assocpairs_BM);
              unsigned bucklen = ((typedhead_tyBM *) curbuckpair)->rlen;
              for (unsigned pix = 0; pix < bucklen; pix++)
                {
                  const objectval_tyBM *curkeyob =
                    curbuckpair->apairs_ent[pix].asso_keyob;
                  value_tyBM curval = curbuckpair->apairs_ent[pix].asso_val;
                  if (curkeyob && curval)
                    {
                      assert (keycnt < nbkeys);
                      arr[keycnt++] = curkeyob;
                    }
                }
            }
        }
    }
  else if (valtype_BM ((const value_tyBM) assoc) == tydata_assocpairs_BM)
    {
      const struct assocpairs_stBM *curpairs = assoc;
      unsigned bucklen = ((typedhead_tyBM *) curpairs)->rlen;
      for (unsigned pix = 0; pix < bucklen; pix++)
        {
          const objectval_tyBM *curkeyob =
            curpairs->apairs_ent[pix].asso_keyob;
          value_tyBM curval = curpairs->apairs_ent[pix].asso_val;
          if (curkeyob && curval)
            {
              assert (keycnt < nbkeys);
              arr[keycnt++] = curkeyob;
            }
        }
    }
  else
    FATAL_BM ("unexpected assoc @%p", assoc);
  assert (keycnt == nbkeys);
  const setval_tyBM *keyset = makeset_BM (arr, keycnt);
  assert (setcardinal_BM (keyset) == nbkeys);
  if (arr != tinyarr)
    free (arr);
  return keyset;
}                               /* end assoc_setattrs_BM */


value_tyBM
assoc_getattr_BM (const anyassoc_tyBM * assoc, const objectval_tyBM * obattr)
{
  if (!isassoc_BM ((const value_tyBM) assoc))
    return NULL;
  if (valtype_BM ((const value_tyBM) obattr) != tyObject_BM)
    return NULL;
  const struct assocpairs_stBM *curpairs = NULL;
  if (valtype_BM ((const value_tyBM) assoc) == tydata_assocbucket_BM)
    {
      unsigned buckix = assoc_buckix_for_key_BM (assoc, obattr);
      curpairs =
        ((const struct assocbucket_stBM *) assoc)->abuck_pairs[buckix];
      assert (!curpairs
              || valtype_BM ((const value_tyBM) curpairs) ==
              tydata_assocpairs_BM);
    }
  else if (valtype_BM ((const value_tyBM) assoc) == tydata_assocpairs_BM)
    curpairs = assoc;
  if (!curpairs)
    return NULL;
  unsigned nbent = ((typedhead_tyBM *) curpairs)->rlen;
  for (unsigned pix = 0; pix < nbent; pix++)
    {
      const objectval_tyBM *curkeyob = curpairs->apairs_ent[pix].asso_keyob;
      value_tyBM curval = curpairs->apairs_ent[pix].asso_val;
      if (curkeyob == obattr)
        return curval;
    }
  return NULL;
}                               /* end assoc_getattr_BM */

anyassoc_tyBM *
assoc_addattr_BM (anyassoc_tyBM * assoc,
                  const objectval_tyBM * obattr, value_tyBM val)
{
  if (valtype_BM ((const value_tyBM) obattr) != tyObject_BM || !val)
    {
      if (!isassoc_BM (assoc))
        return NULL;
      return assoc;
    }
  if (!isassoc_BM (assoc))
    {
      return assocpair_put_BM (NULL, obattr, val);
    }
  unsigned nbkeys = assoc_nbkeys_BM (assoc);
  if (valtype_BM ((const value_tyBM) assoc) == tydata_assocpairs_BM)
    {
      struct assocpairs_stBM *curpairs = assoc;
      if (nbkeys < TINYSIZE_BM)
        {
          return assocpair_put_BM (curpairs, obattr, val);
        };
      assoc_reorganize_BM (&assoc, 2 + nbkeys / 8);
    };
  if (valtype_BM ((const value_tyBM) assoc) == tydata_assocbucket_BM)
    {
      struct assocbucket_stBM *abuck = (struct assocbucket_stBM *) assoc;
      unsigned nbbuckets = ((typedhead_tyBM *) abuck)->rlen;
      if (nbkeys > nbbuckets * TINYSIZE_BM)
        assoc_reorganize_BM (&assoc, 3 + nbkeys / 64);
    };
  if (valtype_BM ((const value_tyBM) assoc) == tydata_assocpairs_BM)
    {
      return assocpair_put_BM ((struct assocpairs_stBM *) assoc, obattr, val);
    }
  else if (valtype_BM ((const value_tyBM) assoc) == tydata_assocbucket_BM)
    {
      unsigned buckix = assoc_buckix_for_key_BM (assoc, obattr);
      struct assocpairs_stBM *curpairs =
        ((const struct assocbucket_stBM *) assoc)->abuck_pairs[buckix];
      assert (!curpairs
              || valtype_BM ((const value_tyBM) curpairs) ==
              tydata_assocpairs_BM);
      unsigned oldpaircnt =
        curpairs ? ((typedsize_tyBM *) curpairs)->size : 0;
      struct assocpairs_stBM *newpairs =
        assocpair_put_BM (curpairs, obattr, val);
      if (newpairs != curpairs)
        ((struct assocbucket_stBM *) assoc)->abuck_pairs[buckix] = newpairs;
      unsigned newpaircnt =
        newpairs ? ((typedsize_tyBM *) newpairs)->size : 0;
      if (newpaircnt > oldpaircnt)
        {
          assert (newpaircnt == oldpaircnt + 1);
          ((typedsize_tyBM *) assoc)->size = nbkeys + 1;
        }
      return assoc;
    }
  // should never be reached
  FATAL_BM ("something corrupted in assoc@%p", assoc);
}                               /* end assoc_addattr_BM */



anyassoc_tyBM *
assoc_removeattr_BM (anyassoc_tyBM * assoc, const objectval_tyBM * obattr)
{
  if (!isassoc_BM (assoc))
    return NULL;
  if (valtype_BM ((const value_tyBM) obattr) != tyObject_BM)
    return assoc;
  unsigned nbkeys = assoc_nbkeys_BM (assoc);
  if (valtype_BM ((const value_tyBM) assoc) == tydata_assocbucket_BM)
    {
      struct assocbucket_stBM *abuck = (struct assocbucket_stBM *) assoc;
      unsigned nbbuckets = ((typedhead_tyBM *) abuck)->rlen;
      if (nbkeys < (nbbuckets * TINYSIZE_BM) / 2)
        assoc_reorganize_BM (&assoc, 2);
      if (valtype_BM ((const value_tyBM) assoc) == tydata_assocbucket_BM)
        {
          unsigned buckix = assoc_buckix_for_key_BM (assoc, obattr);
          struct assocpairs_stBM *curpairs =
            ((const struct assocbucket_stBM *) assoc)->abuck_pairs[buckix];
          assert (!curpairs
                  || valtype_BM ((const value_tyBM) curpairs) ==
                  tydata_assocpairs_BM);
          if (curpairs)
            {
              unsigned nbent = ((typedhead_tyBM *) curpairs)->rlen;
              for (unsigned pix = 0; pix < nbent; pix++)
                {
                  const objectval_tyBM *curkeyob =
                    curpairs->apairs_ent[pix].asso_keyob;
                  if (curkeyob == obattr)
                    {
                      curpairs->apairs_ent[pix].asso_keyob = NULL;
                      curpairs->apairs_ent[pix].asso_val = NULL;
                      ((typedsize_tyBM *) curpairs)->size--;
                      ((typedsize_tyBM *) abuck)->size--;
                      return assoc;
                    }
                }
            }
        }
    }
  if (valtype_BM ((const value_tyBM) assoc) == tydata_assocpairs_BM)
    {
      struct assocpairs_stBM *curpairs = assoc;
      unsigned nbent = ((typedhead_tyBM *) curpairs)->rlen;
      unsigned cnt = ((typedsize_tyBM *) curpairs)->size;
      if (cnt < TINYSIZE_BM / 2)
        {
          assoc_reorganize_BM (&assoc, 1);
          assert (valtype_BM ((const value_tyBM) assoc) ==
                  tydata_assocpairs_BM);
          curpairs = assoc;
        }
      nbent = ((typedhead_tyBM *) curpairs)->rlen;
      for (unsigned pix = 0; pix < nbent; pix++)
        {
          const objectval_tyBM *curkeyob =
            curpairs->apairs_ent[pix].asso_keyob;
          if (curkeyob == obattr)
            {
              assert (cnt > 0);
              curpairs->apairs_ent[pix].asso_keyob = NULL;
              curpairs->apairs_ent[pix].asso_val = NULL;
              ((typedsize_tyBM *) curpairs)->size = cnt - 1;
              return curpairs;
            }
        }
    }
  return assoc;                 // key not found
}                               /* end assoc_removeattr_BM */

void
assocgcmark_BM (struct garbcoll_stBM *gc, anyassoc_tyBM * assoc, int depth)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (isassoc_BM (assoc));
  uint8_t oldmark = ((typedhead_tyBM *) assoc)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) assoc)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  if (valtype_BM ((const value_tyBM) assoc) == tydata_assocbucket_BM)
    {
      unsigned nbuckets = ((typedhead_tyBM *) assoc)->rlen;
      for (unsigned buckix = 0; buckix < nbuckets; buckix++)
        {
          struct assocpairs_stBM *curbuckpair =
            ((struct assocbucket_stBM *) assoc)->abuck_pairs[buckix];
          if (curbuckpair)
            {
              assert (valtype_BM (curbuckpair) == tydata_assocpairs_BM);
              uint8_t oldbuckmark = ((typedhead_tyBM *) curbuckpair)->hgc;
              if (oldbuckmark)
                continue;
              if (((typedhead_tyBM *) curbuckpair)->hgc == MARKGC_BM)
                continue;
              ((typedhead_tyBM *) curbuckpair)->hgc = MARKGC_BM;
              gc->gc_nbmarks++;
              unsigned bucklen = ((typedhead_tyBM *) curbuckpair)->rlen;
              for (unsigned pix = 0; pix < bucklen; pix++)
                {
                  const objectval_tyBM *curkeyob =
                    curbuckpair->apairs_ent[pix].asso_keyob;
                  value_tyBM curval = curbuckpair->apairs_ent[pix].asso_val;
                  if (curkeyob && curval)
                    {
                      gcobjmark_BM (gc, (objectval_tyBM *) curkeyob);
                      gcmark_BM (gc, curval, depth + 1);
                    }
                }
            }
        }
    }
  else if (valtype_BM ((const value_tyBM) assoc) == tydata_assocpairs_BM)
    {
      const struct assocpairs_stBM *curpairs = assoc;
      unsigned bucklen = ((typedhead_tyBM *) curpairs)->rlen;
      for (unsigned pix = 0; pix < bucklen; pix++)
        {
          const objectval_tyBM *curkeyob =
            curpairs->apairs_ent[pix].asso_keyob;
          value_tyBM curval = curpairs->apairs_ent[pix].asso_val;
          if (curkeyob && curval)
            {
              gcobjmark_BM (gc, (objectval_tyBM *) curkeyob);
              gcmark_BM (gc, curval, depth + 1);
            }
        }
    }
  else
    FATAL_BM ("unexpected assoc @%p", assoc);
}                               /* end assocgcmark_BM */
