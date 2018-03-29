// file assoc_BM.c

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

static struct assocpairs_stBM *
assocpair_put_BM (struct assocpairs_stBM *apairs,
                  const objectval_tyBM * keyob, value_tyBM val)
{
  ASSERT_BM (valtype_BM ((const value_tyBM) keyob) == tyObject_BM);
  ASSERT_BM (valtype_BM (val) != tyNone_BM);
  struct assocpairs_stBM *newpairs = NULL;
  if (!apairs)
    {
      unsigned newsiz = TINYSIZE_BM / 3;
      newpairs =
        allocgcty_BM (typayl_assocpairs_BM,
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
  ASSERT_BM (valtype_BM (apairs) == typayl_assocpairs_BM);
  unsigned oldlen = ((typedhead_tyBM *) apairs)->rlen;
  unsigned oldcnt = ((typedsize_tyBM *) apairs)->size;
  ASSERT_BM (oldcnt <= oldlen);
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
        prime_above_BM (4 * oldlen / 3 + oldlen / 64 + ILOG2_BM (oldlen + 2) +
                        3);
      if (newlen >= MAXSIZE_BM)
        FATAL_BM ("too big assocpairs %lu for oldlen %u", newlen, oldlen);
      newpairs =
        allocgcty_BM (typayl_assocpairs_BM,
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
              ASSERT_BM (cnt < newlen);
            }
        };
      ASSERT_BM (cnt == oldcnt);
      newpairs->apairs_ent[cnt].asso_keyob = keyob;
      newpairs->apairs_ent[cnt].asso_val = val;
      cnt++;
      ((typedsize_tyBM *) newpairs)->size = cnt;
      return newpairs;
    }
  else
    {
      // should find some empty slot - or the existing one
      ASSERT_BM (oldcnt < oldlen);
      for (unsigned ix = 0; ix < oldlen; ix++)
        {
          struct assocentry_stBM *curent = apairs->apairs_ent + ix;
          if (!curent->asso_keyob)
            {
              ASSERT_BM (!curent->asso_val);
              curent->asso_keyob = keyob;
              curent->asso_val = val;
              ((typedsize_tyBM *) apairs)->size = oldcnt + 1;
              return apairs;
            }
          else if (curent->asso_keyob == keyob)
            {
              ASSERT_BM (curent->asso_val != NULL);
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
  ASSERT_BM (valtype_BM ((const value_tyBM) abuck) == typayl_assocbucket_BM);
  ASSERT_BM (valtype_BM ((const value_tyBM) obkey) == tyObject_BM);
  hash_tyBM hkey = objecthash_BM (obkey);
  ASSERT_BM (hkey != 0);
  unsigned nbuckets = ((typedhead_tyBM *) abuck)->rlen;
  ASSERT_BM (nbuckets > 2 && nbuckets % 2 != 0);
  return hkey % nbuckets;
}                               /* end assoc_buckix_for_key_BM */

void
assoc_reorganize_BM (anyassoc_tyBM ** passoc, unsigned gap)
{
  ASSERT_BM (passoc != NULL);
  anyassoc_tyBM *oldassoc = *passoc;
  bool oldassocisbucket = valtype_BM (oldassoc) == typayl_assocbucket_BM;
  bool oldassocispairs = valtype_BM (oldassoc) == typayl_assocpairs_BM;
  ASSERT_BM (!oldassoc || isassoc_BM (oldassoc));
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
        allocgcty_BM (typayl_assocpairs_BM,
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
                  ASSERT_BM (valtype_BM (curbuckpair) ==
                             typayl_assocpairs_BM);
                  unsigned bucklen = ((typedhead_tyBM *) curbuckpair)->rlen;
                  for (unsigned pix = 0; pix < bucklen; pix++)
                    {
                      const objectval_tyBM *curkeyob =
                        curbuckpair->apairs_ent[pix].asso_keyob;
                      value_tyBM curval =
                        curbuckpair->apairs_ent[pix].asso_val;
                      if (curkeyob && curval)
                        {
                          ASSERT_BM (newpairs && newpaircnt < newpairsiz);
                          ASSERT_BM (valtype_BM ((const value_tyBM) curkeyob)
                                     == tyObject_BM);
                          ASSERT_BM (valtype_BM (curval) != tyNone_BM);
                          newpairs->apairs_ent[newpaircnt].asso_keyob =
                            curkeyob;
                          newpairs->apairs_ent[newpaircnt].asso_val = curval;
                          newpaircnt++;
                        }
                    }
                  ASSERT_BM (newpaircnt == oldcnt);
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
          ASSERT_BM (valtype_BM (oldpairs) == typayl_assocpairs_BM);
          unsigned bucklen = ((typedhead_tyBM *) oldpairs)->rlen;
          unsigned newpaircnt = 0;
          for (unsigned pix = 0; pix < bucklen; pix++)
            {
              const objectval_tyBM *curkeyob =
                oldpairs->apairs_ent[pix].asso_keyob;
              value_tyBM curval = oldpairs->apairs_ent[pix].asso_val;
              if (curkeyob && curval)
                {
                  ASSERT_BM (newpairs && newpaircnt < newpairsiz);
                  ASSERT_BM (valtype_BM ((const value_tyBM) curkeyob) ==
                             tyObject_BM);
                  ASSERT_BM (valtype_BM (curval) != tyNone_BM);
                  newpairs->apairs_ent[newpaircnt].asso_keyob = curkeyob;
                  newpairs->apairs_ent[newpaircnt].asso_val = curval;
                  newpaircnt++;
                }
            }
          ASSERT_BM (newpaircnt == oldcnt);
          *passoc = newpairs;
        }
      else
        *passoc = newpairs;
      return;
    }
  if (newish > MAXSIZE_BM)
    FATAL_BM ("new assoc wish %lu too big", newish);
  unsigned newnbuckets =
    prime_above_BM (newish / (TINYSIZE_BM - 3) + gap / 128 +
                    ILOG2_BM (oldcnt + gap + 1) / 4 + 4);
  if (newnbuckets > MAXSIZE_BM)
    FATAL_BM ("too big #buckets %u in assoc", newnbuckets);
  struct assocbucket_stBM *newbuckets = //
    allocgcty_BM (typayl_assocbucket_BM,
                  sizeof (struct assocbucket_stBM)
                  + newnbuckets * sizeof (newbuckets->abuck_pairs[0]));
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
              ASSERT_BM (valtype_BM (curbuckpair) == typayl_assocpairs_BM);
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
      ASSERT_BM (addedcnt == oldcnt);
      ((typedsize_tyBM *) newbuckets)->size = addedcnt;
    }
  else if (oldassocispairs)
    {
      struct assocpairs_stBM *oldpairs = oldassoc;
      ASSERT_BM (valtype_BM (oldpairs) == typayl_assocpairs_BM);
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
      ASSERT_BM (addedcnt == oldcnt);
      ((typedsize_tyBM *) newbuckets)->size = addedcnt;
    }
  *passoc = newbuckets;
}                               /* end assoc_reorganize_BM */

void
assocpairgcdestroy_BM (struct garbcoll_stBM *gc, struct assocpairs_stBM *assp)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) assp)->htyp == typayl_assocpairs_BM);
  unsigned len = ((typedhead_tyBM *) assp)->rlen;
  memset (assp, 0, sizeof (*assp) + len * sizeof (struct assocentry_stBM));
  free (assp);
  gc->gc_freedbytes += sizeof (*assp) + len * sizeof (struct assocentry_stBM);
}                               /* end assocpairgcdestroy_BM */

void
assocpairgckeep_BM (struct garbcoll_stBM *gc, struct assocpairs_stBM *assp)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) assp)->htyp == typayl_assocpairs_BM);
  unsigned len = ((typedhead_tyBM *) assp)->rlen;
  ASSERT_BM (len < MAXSIZE_BM);
  gc->gc_keptbytes += sizeof (*assp) + len * sizeof (struct assocentry_stBM);
}                               /* end assocpairgckeep_BM */

void
assocbucketgcdestroy_BM (struct garbcoll_stBM *gc,
                         struct assocbucket_stBM *abuck)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) abuck)->htyp == typayl_assocbucket_BM);
  unsigned nbuckets = ((typedhead_tyBM *) abuck)->rlen;
  memset (abuck, 0, sizeof (*abuck) + nbuckets * sizeof (void *));
  free (abuck);
  gc->gc_freedbytes += sizeof (*abuck) + nbuckets * sizeof (void *);
}                               /*end assocbucketgcdestroy_BM */


void
assocbucketgckeep_BM (struct garbcoll_stBM *gc,
                      struct assocbucket_stBM *abuck)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) abuck)->htyp == typayl_assocbucket_BM);
  unsigned nbuckets = ((typedhead_tyBM *) abuck)->rlen;
  ASSERT_BM (nbuckets < MAXSIZE_BM);
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
    (nbkeys < TINYSIZE_BM) ? tinyarr : calloc (prime_above_BM (nbkeys + 1),
                                               sizeof (void *));
  if (!arr)
    FATAL_BM ("out of memory for %u keys in assoc", nbkeys);
  unsigned keycnt = 0;
  if (valtype_BM ((const value_tyBM) assoc) == typayl_assocbucket_BM)
    {
      unsigned nbuckets = ((typedhead_tyBM *) assoc)->rlen;
      for (unsigned buckix = 0; buckix < nbuckets; buckix++)
        {
          struct assocpairs_stBM *curbuckpair =
            ((struct assocbucket_stBM *) assoc)->abuck_pairs[buckix];
          if (curbuckpair)
            {
              ASSERT_BM (valtype_BM (curbuckpair) == typayl_assocpairs_BM);
              unsigned bucklen = ((typedhead_tyBM *) curbuckpair)->rlen;
              for (unsigned pix = 0; pix < bucklen; pix++)
                {
                  const objectval_tyBM *curkeyob =
                    curbuckpair->apairs_ent[pix].asso_keyob;
                  value_tyBM curval = curbuckpair->apairs_ent[pix].asso_val;
                  if (curkeyob && curval)
                    {
                      ASSERT_BM (keycnt < nbkeys);
                      arr[keycnt++] = curkeyob;
                    }
                }
            }
        }
    }
  else if (valtype_BM ((const value_tyBM) assoc) == typayl_assocpairs_BM)
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
              ASSERT_BM (keycnt < nbkeys);
              arr[keycnt++] = curkeyob;
            }
        }
    }
  else
    FATAL_BM ("unexpected assoc @%p", assoc);
  ASSERT_BM (keycnt == nbkeys);
  const setval_tyBM *keyset = makeset_BM (arr, keycnt);
  ASSERT_BM (setcardinal_BM (keyset) == nbkeys);
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
  if (valtype_BM ((const value_tyBM) assoc) == typayl_assocbucket_BM)
    {
      unsigned buckix = assoc_buckix_for_key_BM (assoc, obattr);
      curpairs =
        ((const struct assocbucket_stBM *) assoc)->abuck_pairs[buckix];
      ASSERT_BM (!curpairs
                 || valtype_BM ((const value_tyBM) curpairs) ==
                 typayl_assocpairs_BM);
    }
  else if (valtype_BM ((const value_tyBM) assoc) == typayl_assocpairs_BM)
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
  if (valtype_BM ((const value_tyBM) obattr) != tyObject_BM
      || !isgenuineval_BM (val))
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
  if (valtype_BM ((const value_tyBM) assoc) == typayl_assocpairs_BM)
    {
      struct assocpairs_stBM *curpairs = assoc;
      if (nbkeys < TINYSIZE_BM)
        {
          return assocpair_put_BM (curpairs, obattr, val);
        };
      assoc_reorganize_BM (&assoc, 2 + nbkeys / 8);
    };
  if (valtype_BM ((const value_tyBM) assoc) == typayl_assocbucket_BM)
    {
      struct assocbucket_stBM *abuck = (struct assocbucket_stBM *) assoc;
      unsigned nbbuckets = ((typedhead_tyBM *) abuck)->rlen;
      if (nbkeys > nbbuckets * TINYSIZE_BM)
        assoc_reorganize_BM (&assoc, 3 + nbkeys / 64);
    };
  if (valtype_BM ((const value_tyBM) assoc) == typayl_assocpairs_BM)
    {
      return assocpair_put_BM ((struct assocpairs_stBM *) assoc, obattr, val);
    }
  else if (valtype_BM ((const value_tyBM) assoc) == typayl_assocbucket_BM)
    {
      unsigned buckix = assoc_buckix_for_key_BM (assoc, obattr);
      struct assocpairs_stBM *curpairs =
        ((const struct assocbucket_stBM *) assoc)->abuck_pairs[buckix];
      ASSERT_BM (!curpairs
                 || valtype_BM ((const value_tyBM) curpairs) ==
                 typayl_assocpairs_BM);
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
          ASSERT_BM (newpaircnt == oldpaircnt + 1);
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
  if (valtype_BM ((const value_tyBM) assoc) == typayl_assocbucket_BM)
    {
      struct assocbucket_stBM *abuck = (struct assocbucket_stBM *) assoc;
      unsigned nbbuckets = ((typedhead_tyBM *) abuck)->rlen;
      if (nbkeys < (nbbuckets * TINYSIZE_BM) / 2)
        assoc_reorganize_BM (&assoc, 2);
      if (valtype_BM ((const value_tyBM) assoc) == typayl_assocbucket_BM)
        {
          unsigned buckix = assoc_buckix_for_key_BM (assoc, obattr);
          struct assocpairs_stBM *curpairs =
            ((const struct assocbucket_stBM *) assoc)->abuck_pairs[buckix];
          ASSERT_BM (!curpairs
                     || valtype_BM ((const value_tyBM) curpairs) ==
                     typayl_assocpairs_BM);
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
  if (valtype_BM ((const value_tyBM) assoc) == typayl_assocpairs_BM)
    {
      struct assocpairs_stBM *curpairs = assoc;
      unsigned nbent = ((typedhead_tyBM *) curpairs)->rlen;
      unsigned cnt = ((typedsize_tyBM *) curpairs)->size;
      if (cnt < TINYSIZE_BM / 2)
        {
          assoc_reorganize_BM (&assoc, 1);
          ASSERT_BM (valtype_BM ((const value_tyBM) assoc) ==
                     typayl_assocpairs_BM);
          curpairs = assoc;
        }
      nbent = ((typedhead_tyBM *) curpairs)->rlen;
      for (unsigned pix = 0; pix < nbent; pix++)
        {
          const objectval_tyBM *curkeyob =
            curpairs->apairs_ent[pix].asso_keyob;
          if (curkeyob == obattr)
            {
              ASSERT_BM (cnt > 0);
              curpairs->apairs_ent[pix].asso_keyob = NULL;
              curpairs->apairs_ent[pix].asso_val = NULL;
              ((typedsize_tyBM *) curpairs)->size = cnt - 1;
              return curpairs;
            }
        }
    }
  return assoc;                 // key not found
}                               /* end assoc_removeattr_BM */

void *
assocgcproc_BM (struct garbcoll_stBM *gc, anyassoc_tyBM * assoc, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (isassoc_BM (assoc));
  uint8_t oldmark = ((typedhead_tyBM *) assoc)->hgc;
  if (oldmark)
    return assoc;
  ((typedhead_tyBM *) assoc)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  if (valtype_BM ((const value_tyBM) assoc) == typayl_assocbucket_BM)
    {
      unsigned nbuckets = ((typedhead_tyBM *) assoc)->rlen;
      for (unsigned buckix = 0; buckix < nbuckets; buckix++)
        {
          struct assocpairs_stBM *curbuckpair =
            ((struct assocbucket_stBM *) assoc)->abuck_pairs[buckix];
          if (curbuckpair)
            {
              ASSERT_BM (valtype_BM (curbuckpair) == typayl_assocpairs_BM);
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
                      VALUEGCPROC_BM (gc, curval, depth + 1);
                      curbuckpair->apairs_ent[pix].asso_val = curval;
                    }
                }
            }
        }
      return assoc;
    }
  else if (valtype_BM ((const value_tyBM) assoc) == typayl_assocpairs_BM)
    {
      struct assocpairs_stBM *curpairs = assoc;
      unsigned bucklen = ((typedhead_tyBM *) curpairs)->rlen;
      for (unsigned pix = 0; pix < bucklen; pix++)
        {
          const objectval_tyBM *curkeyob =
            curpairs->apairs_ent[pix].asso_keyob;
          value_tyBM curval = curpairs->apairs_ent[pix].asso_val;
          if (curkeyob && curval)
            {
              gcobjmark_BM (gc, (objectval_tyBM *) curkeyob);
              VALUEGCPROC_BM (gc, curval, depth + 1);
              curpairs->apairs_ent[pix].asso_val = curval;
            }
        }
      return assoc;
    }
  else
    FATAL_BM ("unexpected assoc @%p", assoc);
}                               /* end assocgcproc_BM */


///// ASSOC PAYLOAD

bool
objputassocpayl_BM (objectval_tyBM * obj, unsigned maxsize)
{
  if (!isobject_BM ((value_tyBM) obj))
    return false;
  if (maxsize > MAXSIZE_BM)
    FATAL_BM ("objputassocpayl_BM too big maxsize %u for obj %s", maxsize,
              objectdbg_BM (obj));
  anyassoc_tyBM *asso = make_assoc_BM (maxsize);
  objputpayload_BM (obj, asso);
  if (objclass_BM (obj) == BMP_object)
    objputclass_BM (obj, BMP_assoc_object);
  return true;
}                               /* end objputassocpayl_BM */

/*********** HASH SET VALUES **********/
void
hashsetvalgcmark_BM (struct garbcoll_stBM *gc, struct hashsetval_stBM *hsv,
                     int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (ishashsetval_BM ((value_tyBM) hsv));
  uint8_t oldmark = ((typedhead_tyBM *) hsv)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) hsv)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  unsigned siz = ((typedsize_tyBM *) hsv)->size;
  for (unsigned ix = 0; ix < siz; ix++)
    {
      struct hashsetvbucket_stBM *vbu = hsv->hashval_vbuckets[ix];
      if (!vbu || vbu == HASHEMPTYSLOT_BM)
        continue;
      ASSERT_BM (valtype_BM ((value_tyBM) vbu) == typayl_hashsetvbucket_BM);
      EXTENDEDGCPROC_BM (gc, vbu, depth + 1);
    }
}                               /* end hashsetvalgcmark_BM */

void
hashsetvbucketgcmark_BM (struct garbcoll_stBM *gc,
                         struct hashsetvbucket_stBM *hvb, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (ishashsetvbucket_BM ((value_tyBM) hvb));
  uint8_t oldmark = ((typedhead_tyBM *) hvb)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) hvb)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  unsigned siz = ((typedsize_tyBM *) hvb)->size;
  for (unsigned ix = 0; ix < siz; ix++)
    {
      value_tyBM cval = hvb->vbuck_arr[ix];
      if (!cval || cval == HASHEMPTYSLOT_BM)
        continue;
      VALUEGCPROC_BM (gc, hvb->vbuck_arr[ix], depth + 1);
    }
}                               /* end hashsetvbucketgcmark_BM */

void
hashsetvalgcdestroy_BM (struct garbcoll_stBM *gc, struct hashsetval_stBM *hsv)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) hsv)->htyp == typayl_hashsetval_BM);
  unsigned len = ((typedhead_tyBM *) hsv)->rlen;
  memset (hsv, 0,
          sizeof (*hsv) + len * sizeof (struct hashsetvbucket_stBM *));
  free (hsv);
  gc->gc_freedbytes +=
    sizeof (*hsv) + len * sizeof (struct hashsetvbucket_stBM *);
}                               /* end  hashsetvalgcdestroy_BM */

void
hashsetvbucketgcdestroy_BM (struct garbcoll_stBM *gc,
                            struct hashsetvbucket_stBM *hvb)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) hvb)->htyp == typayl_hashsetvbucket_BM);
  unsigned len = ((typedhead_tyBM *) hvb)->rlen;
  memset (hvb, 0, sizeof (*hvb) + len * sizeof (value_tyBM));
  free (hvb);
  gc->gc_freedbytes += sizeof (*hvb) + len * sizeof (value_tyBM);
}                               /* end hashsetvbucketgcdsestroy_BM */

void
hashsetvalgckeep_BM (struct garbcoll_stBM *gc, struct hashsetval_stBM *hsv)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) hsv)->htyp == typayl_hashsetval_BM);
  unsigned len = ((typedhead_tyBM *) hsv)->rlen;
  ASSERT_BM (len < MAXSIZE_BM);
  gc->gc_keptbytes +=
    sizeof (*hsv) + len * sizeof (struct hashsetvbucket_stBM *);
}                               /* end  hashsetvalgckeep_BM */

void
hashsetvbucketgckeep_BM (struct garbcoll_stBM *gc,
                         struct hashsetvbucket_stBM *hvb)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) hvb)->htyp == typayl_hashsetvbucket_BM);
  unsigned len = ((typedhead_tyBM *) hvb)->rlen;
  ASSERT_BM (len < MAXSIZE_BM);
  gc->gc_keptbytes += sizeof (*hvb) + len * sizeof (value_tyBM);
}                               /* end hashsetvbucketgckeep_BM */

#define HASHRATIO_BM 7
#define HASHTHRESHOLD_BM (5*HASHRATIO_BM/3+2)

struct hashpairindexes_stBM
{
  int hvi_buckix;               /* index of bucket */
  int hvi_compix;               /* index of component */
};
#define EMPTYPAIRINDEXES_BM ((struct hashpairindexes_stBM){-1,-1})
// give the indexes of a value; if the value is present, give the
// actual indexes; if the value is absent, give the index where it
// should go
static struct hashpairindexes_stBM
hashsetvalfindindexes_BM (struct hashsetval_stBM *hsv, value_tyBM val)
{
  ASSERT_BM (hsv && ((typedhead_tyBM *) hsv)->htyp == typayl_hashsetval_BM);
  if (!val)
    return EMPTYPAIRINDEXES_BM;
  unsigned len = ((typedhead_tyBM *) hsv)->rlen;
  ASSERT_BM (len < MAXSIZE_BM && len > 2);
  hash_tyBM hva = valhash_BM (val);
  unsigned bix = hva % len;
  struct hashsetvbucket_stBM *curbuck = hsv->hashval_vbuckets[bix];
  if (!curbuck)
    return (struct hashpairindexes_stBM)
    {
      .hvi_buckix = bix,        //
    .hvi_compix = -1};
  ASSERT_BM (((typedhead_tyBM *) curbuck)->htyp == typayl_hashsetvbucket_BM);
  unsigned bucklen = ((typedhead_tyBM *) curbuck)->rlen;
  int buckpos = -1;
  for (unsigned vix = 0; vix < bucklen; vix++)
    {
      value_tyBM curval = curbuck->vbuck_arr[vix];
      if (!curval)
        {
          if (buckpos < 0)
            buckpos = (int) vix;
          return (struct hashpairindexes_stBM)
          {
            .hvi_buckix = bix,  //
          .hvi_compix = vix};
        }
      else if (curval == (value_tyBM) HASHEMPTYSLOT_BM)
        {
          if (buckpos < 0)
            buckpos = (int) vix;
          continue;
        }
      else if (curval == val || valequal_BM (curval, val))
        {
          return (struct hashpairindexes_stBM)
          {
            .hvi_buckix = bix,  //
          .hvi_compix = vix};
        }
    }
  return EMPTYPAIRINDEXES_BM;
}                               /* end hashsetvalfindindexes_BM */

bool
hashsetvalcontains_BM (struct hashsetval_stBM * hsv, value_tyBM val)
{
  if (!hsv || valtype_BM ((value_tyBM) hsv) != typayl_hashsetval_BM)
    return false;
  if (!val)
    return false;
  struct hashpairindexes_stBM hvindexes = hashsetvalfindindexes_BM (hsv, val);
  int bix = hvindexes.hvi_buckix;
  int compix = hvindexes.hvi_compix;
  if (bix < 0 || compix < 0)
    return false;
  unsigned hslen = ((typedhead_tyBM *) hsv)->rlen;
  ASSERT_BM (bix < (int) hslen);
  struct hashsetvbucket_stBM *curbuck = hsv->hashval_vbuckets[bix];
  ASSERT_BM (curbuck != NULL);
  unsigned bucklen = ((typedhead_tyBM *) curbuck)->rlen;
  ASSERT_BM (compix < (int) bucklen);
  value_tyBM curval = curbuck->vbuck_arr[compix];
  if (curval && curval != (value_tyBM) HASHEMPTYSLOT_BM
      && (curval == val || valequal_BM (curval, val)))
    return true;
  return false;
}                               /* end hashsetvalcontains_BM */


#define HASHSETVAL_INITBUCKETSIZE_BM 5
static void hashsetvalrawadd_BM (struct hashsetval_stBM *hsv, value_tyBM val);

static void
hashsetvalrawadd_BM (struct hashsetval_stBM *hsv, value_tyBM val)
{
  if (!hsv || valtype_BM ((value_tyBM) hsv) != typayl_hashsetval_BM)
    return;
  if (!val)
    return;
  struct hashpairindexes_stBM hvindexes = hashsetvalfindindexes_BM (hsv, val);
  int bix = hvindexes.hvi_buckix;
  int compix = hvindexes.hvi_compix;
  if (bix < 0)
    return;
  unsigned hslen = ((typedhead_tyBM *) hsv)->rlen;
  ASSERT_BM (bix < (int) hslen);
  struct hashsetvbucket_stBM *curbuck = hsv->hashval_vbuckets[bix];
  if (!curbuck)
    {
      ASSERT_BM (compix < 0);
      unsigned newsiz = HASHSETVAL_INITBUCKETSIZE_BM;
      struct hashsetvbucket_stBM *newbuck
        = allocgcty_BM (typayl_hashsetvbucket_BM,
                        sizeof (struct hashsetvbucket_stBM) +
                        newsiz * sizeof (value_tyBM));
      ((typedhead_tyBM *) newbuck)->rlen = newsiz;
      hsv->hashval_vbuckets[bix] = newbuck;
      newbuck->vbuck_arr[0] = val;
      ((struct typedsize_stBM *) newbuck)->size = 1;
      ((struct typedsize_stBM *) hsv)->size++;
      return;
    }
  unsigned bucklen = ((typedhead_tyBM *) curbuck)->rlen;
  if (compix >= 0)
    {
      ASSERT_BM (compix < (int) bucklen);
      if (curbuck->vbuck_arr[compix] == NULL
          || curbuck->vbuck_arr[compix] == (value_tyBM) HASHEMPTYSLOT_BM)
        {
          curbuck->vbuck_arr[compix] = val;
          ((struct typedsize_stBM *) curbuck)->size++;
          ((struct typedsize_stBM *) hsv)->size++;
        }
      else
        {
          ASSERT_BM (curbuck->vbuck_arr[compix] == val
                     || valequal_BM (curbuck->vbuck_arr[compix], val));
          return;
        }
    }
  else
    {                           /* should grow the bucket */
      ASSERT_BM (((struct typedsize_stBM *) curbuck)->size == bucklen);
      unsigned newsiz =
        prime_above_BM (5 * bucklen / 4 + bucklen / 32 +
                        ILOG2_BM (hslen + 1) / 4 + 3);
      if (newsiz > MAXSIZE_BM)
        FATAL_BM ("too huge hashsetval bucket for bucklen %d", bucklen);
      struct hashsetvbucket_stBM *newbuck
        = allocgcty_BM (typayl_hashsetvbucket_BM,
                        sizeof (struct hashsetvbucket_stBM) +
                        newsiz * sizeof (value_tyBM));
      ((typedhead_tyBM *) newbuck)->rlen = newsiz;
      unsigned newbuckcnt = 0;
      for (unsigned oldbix = 0; oldbix < bucklen; oldbix++)
        {
          value_tyBM oldval = curbuck->vbuck_arr[oldbix];
          if (!oldval || oldval == (value_tyBM) HASHEMPTYSLOT_BM)
            continue;
          newbuck->vbuck_arr[newbuckcnt++] = oldval;
        }
      ASSERT_BM (newbuckcnt < newsiz);
      ((struct typedsize_stBM *) newbuck)->size = newbuckcnt;
      hsv->hashval_vbuckets[bix] = newbuck;
      ((struct typedsize_stBM *) hsv)->size++;
    }
}                               /* end hashsetvalrawadd_BM */


struct hashsetval_stBM *
hashsetvalreorganize_BM (struct hashsetval_stBM *hsv, unsigned gap)
{
  if (valtype_BM ((value_tyBM) hsv) != typayl_hashsetval_BM)
    hsv = NULL;
  unsigned oldhsiz = hsv ? (((struct typedsize_stBM *) hsv)->size) : 0;
  unsigned oldhlen = hsv ? (((struct typedhead_stBM *) hsv)->rlen) : 0;
  unsigned newsiz =
    prime_above_BM ((oldhsiz + gap) / HASHRATIO_BM
                    + ILOG2_BM (oldhsiz + gap + 2) + 3);
  if (newsiz > MAXSIZE_BM)
    FATAL_BM ("too big hashset new size %u", newsiz);
  struct hashsetval_stBM *newhsv =      //
    allocgcty_BM (typayl_hashsetval_BM,
                  sizeof (struct hashsetval_stBM) +
                  newsiz * sizeof (struct hashsetvbucket_stBM *));
  ((typedhead_tyBM *) newhsv)->rlen = newsiz;
  if (!oldhsiz)
    return newhsv;
  for (unsigned oldbix = 0; oldbix < oldhlen; oldbix++)
    {
      struct hashsetvbucket_stBM *oldbuck = hsv->hashval_vbuckets[oldbix];
      if (!oldbuck)
        continue;
      unsigned oldbucklen = ((typedhead_tyBM *) oldbuck)->rlen;
      for (unsigned oldelix = 0; oldelix < oldbucklen; oldelix++)
        {
          value_tyBM oldval = oldbuck->vbuck_arr[oldelix];
          if (!oldval || oldval == (value_tyBM) HASHEMPTYSLOT_BM)
            continue;
          hashsetvalrawadd_BM (newhsv, oldval);
        }
    }
  ASSERT_BM (oldhsiz == (((struct typedsize_stBM *) newhsv)->size));
  return newhsv;
}                               /* end hashsetvalreorganize_BM */

struct hashsetval_stBM *
hashsetvalput_BM (struct hashsetval_stBM *hsv, value_tyBM val)
{
  if (!val)
    return ishashsetval_BM ((value_tyBM) hsv) ? hsv : NULL;
  if (!ishashsetval_BM ((value_tyBM) hsv))
    hsv = hashsetvalreorganize_BM (NULL, 3);
  ASSERT_BM (ishashsetval_BM (hsv));
  {
    unsigned oldhsiz = ((struct typedsize_stBM *) hsv)->size;
    unsigned oldhlen = ((struct typedhead_stBM *) hsv)->rlen;
    if (oldhsiz > oldhlen * HASHTHRESHOLD_BM + 2)
      hsv = hashsetvalreorganize_BM (hsv, 4 + ILOG2_BM (oldhsiz + 2) / 4);
    else if (oldhsiz
             > oldhlen
             * (HASHRATIO_BM + (HASHTHRESHOLD_BM - HASHRATIO_BM) / 2) +
             ILOG2_BM (oldhlen + 3))
      {
        if (g_random_int () % HASHTHRESHOLD_BM == 0)
          hsv = hashsetvalreorganize_BM (hsv, 4 + ILOG2_BM (oldhsiz + 2) / 6);
      }
  }
  hashsetvalrawadd_BM (hsv, val);
  return hsv;
}                               /* end hashsetvalput_BM */

struct hashsetval_stBM *
hashsetvalremove_BM (struct hashsetval_stBM *hsv, value_tyBM val)
{
  if (!val)
    return ishashsetval_BM ((value_tyBM) hsv) ? hsv : NULL;
  if (!ishashsetval_BM ((value_tyBM) hsv))
    return NULL;
  struct hashpairindexes_stBM hvindexes = hashsetvalfindindexes_BM (hsv, val);
  int bix = hvindexes.hvi_buckix;
  int compix = hvindexes.hvi_compix;
  if (bix < 0 || compix < 0)
    return hsv;
  unsigned hslen = ((typedhead_tyBM *) hsv)->rlen;
  ASSERT_BM (bix < (int) hslen);
  struct hashsetvbucket_stBM *curbuck = hsv->hashval_vbuckets[bix];
  ASSERT_BM (curbuck != NULL);
  unsigned bucklen = ((typedhead_tyBM *) curbuck)->rlen;
  ASSERT_BM (compix < (int) bucklen);
  if (curbuck->vbuck_arr[compix] == NULL
      || curbuck->vbuck_arr[compix] == (value_tyBM) HASHEMPTYSLOT_BM)
    return hsv;
  ASSERT_BM (curbuck->vbuck_arr[compix] == val
             || valequal_BM (curbuck->vbuck_arr[compix], val));
  curbuck->vbuck_arr[compix] = HASHEMPTYSLOT_BM;;
  ((struct typedsize_stBM *) curbuck)->size--;
  ((struct typedsize_stBM *) hsv)->size++;
  unsigned oldhsiz = ((struct typedsize_stBM *) hsv)->size;
  unsigned oldhlen = ((struct typedhead_stBM *) hsv)->rlen;
  if (oldhsiz > 2 * HASHTHRESHOLD_BM
      && oldhsiz < oldhlen * (HASHRATIO_BM / 2 + 1) + 2)
    hsv = hashsetvalreorganize_BM (hsv, 4 + ILOG2_BM (oldhsiz) / 4);
  return hsv;
}                               /* end hashsetvalremove_BM */

value_tyBM
hashsetvalfirst_BM (struct hashsetval_stBM * hsv)
{
  if (!ishashsetval_BM ((value_tyBM) hsv))
    return NULL;
  unsigned hslen = ((typedhead_tyBM *) hsv)->rlen;
  for (unsigned bix = 0; bix < hslen; bix++)
    {
      struct hashsetvbucket_stBM *curbuck = hsv->hashval_vbuckets[bix];
      if (!curbuck)
        continue;
      ASSERT_BM (valtype_BM (curbuck) == typayl_hashsetvbucket_BM);
      unsigned bucklen = ((typedhead_tyBM *) curbuck)->rlen;
      for (unsigned compix = 0; compix < bucklen; compix++)
        {
          value_tyBM curval = curbuck->vbuck_arr[compix];
          if (curval == HASHEMPTYSLOT_BM)
            continue;
          if (!curval)
            break;
          return curval;
        }
    }
  return NULL;
}                               /* end hashsetvalfirst_BM */

value_tyBM
hashsetvalnext_BM (struct hashsetval_stBM * hsv, value_tyBM prev)
{
  if (!ishashsetval_BM ((value_tyBM) hsv))
    return NULL;
  if (!prev || prev == HASHEMPTYSLOT_BM)
    return NULL;
  struct hashpairindexes_stBM hvindexes =
    hashsetvalfindindexes_BM (hsv, prev);
  int bix = hvindexes.hvi_buckix;
  int compix = hvindexes.hvi_compix;
  if (bix < 0 || compix < 0)
    return NULL;
  unsigned hslen = ((typedhead_tyBM *) hsv)->rlen;
  ASSERT_BM (bix < (int) hslen);
  struct hashsetvbucket_stBM *curbuck = hsv->hashval_vbuckets[bix];
  ASSERT_BM (curbuck != NULL
             && valtype_BM (curbuck) == typayl_hashsetvbucket_BM);
  unsigned bucklen = ((typedhead_tyBM *) curbuck)->rlen;
  for (; compix < (int) bucklen; compix++)
    {
      value_tyBM curval = curbuck->vbuck_arr[compix];
      if (curval == HASHEMPTYSLOT_BM)
        continue;
      if (!curval)
        break;
      return curval;
    }
  for (bix = bix + 1; bix < (int) hslen; bix++)
    {
      curbuck = hsv->hashval_vbuckets[bix];
      if (!curbuck)
        continue;
      ASSERT_BM (valtype_BM (curbuck) == typayl_hashsetvbucket_BM);
      bucklen = ((typedhead_tyBM *) curbuck)->rlen;
      for (compix = 0; compix < (int) bucklen; compix++)
        {
          value_tyBM curval = curbuck->vbuck_arr[compix];
          if (curval == HASHEMPTYSLOT_BM)
            continue;
          if (!curval)
            break;
          return curval;
        }
    }
  return NULL;
}                               /* end hashsetvalnext_BM */

value_tyBM
hashsetvalmakenode_BM (struct hashsetval_stBM * hsv, objectval_tyBM * connob)
{
  value_tyBM resv = NULL;
  if (!ishashsetval_BM ((value_tyBM) hsv))
    return NULL;
  if (!isobject_BM (connob))
    return NULL;
  unsigned hslen = ((typedhead_tyBM *) hsv)->rlen;
  unsigned hsiz = ((struct typedsize_stBM *) hsv)->size;
  value_tyBM tinyarr[TINYSIZE_BM] = { 0 };
  value_tyBM *arr = (hsiz < TINYSIZE_BM) ? tinyarr
    : calloc (prime_above_BM (hsiz + 1), sizeof (value_tyBM));
  if (!arr)
    FATAL_BM ("hashsetmakenode_BM calloc %d failure", hsiz);
  unsigned cnt = 0;
  for (unsigned bix = 0; bix < hslen; bix++)
    {
      struct hashsetvbucket_stBM *curbuck = hsv->hashval_vbuckets[bix];
      if (!curbuck)
        continue;
      ASSERT_BM (valtype_BM (curbuck) == typayl_hashsetvbucket_BM);
      unsigned bucklen = ((typedhead_tyBM *) curbuck)->rlen;
      for (unsigned compix = 0; compix < bucklen; compix++)
        {
          value_tyBM curval = curbuck->vbuck_arr[compix];
          if (curval == HASHEMPTYSLOT_BM)
            continue;
          if (!curval)
            break;
          ASSERT_BM (cnt < hsiz);
          arr[cnt++] = curval;
        }
    }
  ASSERT_BM (cnt == hsiz);
  valarrqsort_BM (arr, cnt);
  resv = (value_tyBM) makenode_BM (connob, cnt, arr);
  if (arr != tinyarr)
    free (arr), arr = NULL;
  return resv;
}                               /* end hashsetvalmakenode_BM */





/******** HASH MAPS ASSOCIATING VALUES TO VALUES ********/


void
hashmapvalgcmark_BM (struct garbcoll_stBM *gc, struct hashmapval_stBM *hmv,
                     int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (ishashmapval_BM ((value_tyBM) hmv));
  uint8_t oldmark = ((typedhead_tyBM *) hmv)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) hmv)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  unsigned siz = ((typedsize_tyBM *) hmv)->size;
  for (unsigned ix = 0; ix < siz; ix++)
    {
      struct hashmapbucket_stBM *vbu = hmv->hashmap_vbuckets[ix];
      if (!vbu || vbu == HASHEMPTYSLOT_BM)
        continue;
      ASSERT_BM (valtype_BM ((value_tyBM) vbu) == typayl_hashmapbucket_BM);
      EXTENDEDGCPROC_BM (gc, vbu, depth + 1);
    }
}                               /* end hashmapvalgcmark_BM */

void
hashmapbucketgcmark_BM (struct garbcoll_stBM *gc,
                        struct hashmapbucket_stBM *hvb, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (ishashmapbucket_BM ((value_tyBM) hvb));
  uint8_t oldmark = ((typedhead_tyBM *) hvb)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) hvb)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  unsigned siz = ((typedsize_tyBM *) hvb)->size;
  for (unsigned ix = 0; ix < siz; ix++)
    {
      value_tyBM cval = hvb->vbent_arr[ix].hmap_keyv;
      if (!cval || cval == HASHEMPTYSLOT_BM)
        continue;
      VALUEGCPROC_BM (gc, hvb->vbent_arr[ix].hmap_keyv, depth + 1);
      VALUEGCPROC_BM (gc, hvb->vbent_arr[ix].hmap_valv, depth + 1);
    }
}                               /* end hashmapbucketgcmark_BM */

void
hashmapvalgcdestroy_BM (struct garbcoll_stBM *gc, struct hashmapval_stBM *hsv)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) hsv)->htyp == typayl_hashmapval_BM);
  unsigned len = ((typedhead_tyBM *) hsv)->rlen;
  memset (hsv, 0,
          sizeof (*hsv) + len * sizeof (struct hashmapvbucket_stBM *));
  free (hsv);
  gc->gc_freedbytes +=
    sizeof (*hsv) + len * sizeof (struct hashmapvbucket_stBM *);
}                               /* end  hashmapvalgcdestroy_BM */

void
hashmapbucketgcdestroy_BM (struct garbcoll_stBM *gc,
                           struct hashmapbucket_stBM *hvb)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) hvb)->htyp == typayl_hashmapbucket_BM);
  unsigned len = ((typedhead_tyBM *) hvb)->rlen;
  memset (hvb, 0, sizeof (*hvb) + len * sizeof (value_tyBM));
  free (hvb);
  gc->gc_freedbytes += sizeof (*hvb)
    + len * sizeof (struct hashmapentry_stBM);
}                               /* end hashmapbucketgcdsestroy_BM */

void
hashmapvalgckeep_BM (struct garbcoll_stBM *gc, struct hashmapval_stBM *hsv)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) hsv)->htyp == typayl_hashmapval_BM);
  unsigned len = ((typedhead_tyBM *) hsv)->rlen;
  ASSERT_BM (len < MAXSIZE_BM);
  gc->gc_keptbytes +=
    sizeof (*hsv) + len * sizeof (struct hashmapvbucket_stBM *);
}                               /* end  hashmapvalgckeep_BM */

void
hashmapbucketgckeep_BM (struct garbcoll_stBM *gc,
                        struct hashmapbucket_stBM *hvb)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) hvb)->htyp == typayl_hashmapbucket_BM);
  unsigned len = ((typedhead_tyBM *) hvb)->rlen;
  ASSERT_BM (len < MAXSIZE_BM);
  gc->gc_keptbytes += sizeof (*hvb) + len * sizeof (struct hashmapentry_stBM);
}                               /* end hashmapvbucketgckeep_BM */

static struct hashpairindexes_stBM
hashmapvalfindindexes_BM (struct hashmapval_stBM *hmv, value_tyBM val)
{
  ASSERT_BM (hmv && ((typedhead_tyBM *) hmv)->htyp == typayl_hashmapval_BM);
  if (!val)
    return EMPTYPAIRINDEXES_BM;
  unsigned len = ((typedhead_tyBM *) hmv)->rlen;
  ASSERT_BM (len < MAXSIZE_BM && len > 2);
  hash_tyBM hva = valhash_BM (val);
  unsigned bix = hva % len;
  struct hashmapbucket_stBM *curbuck = hmv->hashmap_vbuckets[bix];
  if (!curbuck)
    return (struct hashpairindexes_stBM)
    {
      .hvi_buckix = bix,        //
    .hvi_compix = -1};
  ASSERT_BM (((typedhead_tyBM *) curbuck)->htyp == typayl_hashmapbucket_BM);
  unsigned bucklen = ((typedhead_tyBM *) curbuck)->rlen;
  int buckpos = -1;
  for (unsigned vix = 0; vix < bucklen; vix++)
    {
      value_tyBM curkey = curbuck->vbent_arr[vix].hmap_keyv;
      if (!curkey)
        {
          if (buckpos < 0)
            buckpos = (int) vix;
          return (struct hashpairindexes_stBM)
          {
            .hvi_buckix = bix,  //
          .hvi_compix = vix};
        }
      else if (curkey == (value_tyBM) HASHEMPTYSLOT_BM)
        {
          if (buckpos < 0)
            buckpos = (int) vix;
          continue;
        }
      else if (curkey == val || valequal_BM (curkey, val))
        {
          return (struct hashpairindexes_stBM)
          {
            .hvi_buckix = bix,  //
          .hvi_compix = vix};
        }
    }
  return EMPTYPAIRINDEXES_BM;
}                               /* end hashmapvalfindindexes_BM */


value_tyBM
hashmapvalget_BM (struct hashmapval_stBM * hmv, value_tyBM keyv)
{
  if (!hmv || valtype_BM ((value_tyBM) hmv) != typayl_hashmapval_BM)
    return false;
  if (!keyv)
    return false;
  struct hashpairindexes_stBM hvindexes =
    hashmapvalfindindexes_BM (hmv, keyv);
  int bix = hvindexes.hvi_buckix;
  int compix = hvindexes.hvi_compix;
  if (bix < 0 || compix < 0)
    return NULL;
  unsigned hslen = ((typedhead_tyBM *) hmv)->rlen;
  ASSERT_BM (bix < (int) hslen);
  struct hashmapbucket_stBM *curbuck = hmv->hashmap_vbuckets[bix];
  ASSERT_BM (curbuck != NULL);
  unsigned bucklen = ((typedhead_tyBM *) curbuck)->rlen;
  ASSERT_BM (compix < (int) bucklen);
  value_tyBM curkey = curbuck->vbent_arr[compix].hmap_keyv;
  if (curkey && curkey != (value_tyBM) HASHEMPTYSLOT_BM)
    {
      ASSERT_BM (curkey == keyv || valequal_BM (curkey, keyv));
      return curbuck->vbent_arr[compix].hmap_valv;
    }
  return NULL;
}                               /* end hashmapvalget_BM */


#define HASHMAPVAL_INITBUCKETSIZE_BM 5
static void hashmapvalrawput_BM (struct hashmapval_stBM *hmv, value_tyBM keyv,
                                 value_tyBM valv);

static void
hashmapvalrawput_BM (struct hashmapval_stBM *hmv, value_tyBM keyv,
                     value_tyBM valv)
{
  if (!hmv || valtype_BM ((value_tyBM) hmv) != typayl_hashmapval_BM)
    return;
  if (!keyv)
    return;
  if (!valv)
    return;
  struct hashpairindexes_stBM hvindexes =
    hashmapvalfindindexes_BM (hmv, keyv);
  int bix = hvindexes.hvi_buckix;
  int compix = hvindexes.hvi_compix;
  if (bix < 0)
    return;
  unsigned hslen = ((typedhead_tyBM *) hmv)->rlen;
  ASSERT_BM (bix < (int) hslen);
  struct hashmapbucket_stBM *curbuck = hmv->hashmap_vbuckets[bix];
  if (!curbuck)
    {
      ASSERT_BM (compix < 0);
      unsigned newsiz = HASHMAPVAL_INITBUCKETSIZE_BM;
      struct hashmapbucket_stBM *newbuck
        = allocgcty_BM (typayl_hashmapbucket_BM,
                        sizeof (struct hashmapbucket_stBM)
                        + newsiz * sizeof (struct hashmapentry_stBM));
      ((typedhead_tyBM *) newbuck)->rlen = newsiz;
      ((struct typedsize_stBM *) newbuck)->size = 1;
      newbuck->vbent_arr[0].hmap_keyv = keyv;
      newbuck->vbent_arr[0].hmap_valv = valv;
      hmv->hashmap_vbuckets[bix] = newbuck;
      ((struct typedsize_stBM *) hmv)->size++;
      return;
    }
  else if (compix < 0)
    {
      // curbuck is full, grow it
      unsigned oldbucklen = ((typedhead_tyBM *) curbuck)->rlen;
      ASSERT_BM (oldbucklen == ((struct typedsize_stBM *) curbuck)->size);
      unsigned newsiz =
        prime_above_BM (4 * oldbucklen / 3 + 3 + ILOG2_BM (hslen + 1) / 4);
      if (newsiz > MAXSIZE_BM)
        FATAL_BM ("too big bucket size %u", newsiz);
      struct hashmapbucket_stBM *newbuck =
        allocgcty_BM (typayl_hashmapbucket_BM,
                      sizeof (struct hashmapbucket_stBM) +
                      newsiz * sizeof (struct hashmapentry_stBM));
      ((typedhead_tyBM *) newbuck)->rlen = newsiz;
      memcpy (newbuck->vbent_arr, curbuck->vbent_arr,
              oldbucklen * sizeof (struct hashmapentry_stBM));
      newbuck->vbent_arr[oldbucklen].hmap_keyv = keyv;
      newbuck->vbent_arr[oldbucklen].hmap_valv = valv;
      ((typedsize_tyBM *) newbuck)->size = oldbucklen + 1;
      hmv->hashmap_vbuckets[bix] = newbuck;
      ((struct typedsize_stBM *) hmv)->size++;
      return;
    }
  unsigned bucklen = ((typedhead_tyBM *) curbuck)->rlen;
  ASSERT_BM (compix >= 0 && compix < (int) bucklen);
  value_tyBM oldkeyv = curbuck->vbent_arr[compix].hmap_keyv;
  if (!oldkeyv || oldkeyv == HASHEMPTYSLOT_BM)
    {
      curbuck->vbent_arr[compix].hmap_keyv = keyv;
      curbuck->vbent_arr[compix].hmap_valv = valv;
      ((typedsize_tyBM *) curbuck)->size = bucklen + 1;
      ((struct typedsize_stBM *) hmv)->size++;
      return;
    }
  ASSERT_BM (oldkeyv == keyv || valequal_BM (oldkeyv, keyv));
  curbuck->vbent_arr[compix].hmap_valv = valv;
  return;
}                               /* end hashmapvalrawput_BM */




struct hashmapval_stBM *
hashmapvalreorganize_BM (struct hashmapval_stBM *hmv, unsigned gap)
{
  if (valtype_BM ((value_tyBM) hmv) != typayl_hashmapval_BM)
    hmv = NULL;
  unsigned oldhsiz = hmv ? (((struct typedsize_stBM *) hmv)->size) : 0;
  unsigned oldhlen = hmv ? (((struct typedhead_stBM *) hmv)->rlen) : 0;
  unsigned newsiz =
    prime_above_BM ((oldhsiz + gap) / HASHRATIO_BM +
                    ILOG2_BM (oldhsiz + gap + 2) + 3);
  if (newsiz > MAXSIZE_BM)
    FATAL_BM ("too big new size %u for hashmapval", newsiz);
  struct hashmapval_stBM *newhmv =      //
    allocgcty_BM (typayl_hashsetval_BM,
                  sizeof (struct hashmapval_stBM) +
                  newsiz * sizeof (struct hashmapbucket_stBM *));
  ((typedhead_tyBM *) newhmv)->rlen = newsiz;
  if (!oldhsiz)
    return newhmv;
  for (unsigned oldbix = 0; oldbix < oldhlen; oldbix++)
    {
      struct hashmapbucket_stBM *oldbuck = hmv->hashmap_vbuckets[oldbix];
      if (!oldbuck)
        continue;
      unsigned oldbucklen = ((typedhead_tyBM *) oldbuck)->rlen;
      for (unsigned oldelix = 0; oldelix < oldbucklen; oldelix++)
        {
          value_tyBM oldkeyv = oldbuck->vbent_arr[oldelix].hmap_keyv;
          if (!oldkeyv)
            break;
          if (oldkeyv == HASHEMPTYSLOT_BM)
            continue;
          value_tyBM oldvalv = oldbuck->vbent_arr[oldelix].hmap_valv;
          ASSERT_BM (oldvalv != NULL);
          hashmapvalrawput_BM (newhmv, oldkeyv, oldvalv);
        }
    }
  return newhmv;
}                               /* end of hashmapvalreorganize_BM */


struct hashmapval_stBM *
hashmapvalput_BM (struct hashmapval_stBM *hmv, value_tyBM keyv,
                  value_tyBM valv)
{
  if (!keyv)
    return ishashmapval_BM ((value_tyBM) hmv) ? hmv : NULL;
  if (!valv)
    return hashmapvalremove_BM (hmv, keyv);
  if (!ishashmapval_BM ((value_tyBM) hmv))
    hmv = hashmapvalreorganize_BM (NULL, 3);
  ASSERT_BM (ishashmapval_BM (hmv));
  {
    unsigned oldhsiz = ((struct typedsize_stBM *) hmv)->size;
    unsigned oldhlen = ((struct typedhead_stBM *) hmv)->rlen;
    if (oldhsiz > oldhlen * HASHTHRESHOLD_BM + 2)
      hmv = hashmapvalreorganize_BM (hmv, 4 + ILOG2_BM (oldhsiz + 2) / 4);
    else if (oldhsiz
             > oldhlen
             * (HASHRATIO_BM + (HASHTHRESHOLD_BM - HASHRATIO_BM) / 2) +
             ILOG2_BM (oldhlen + 3))
      {
        if (g_random_int () % HASHTHRESHOLD_BM == 0)
          hmv = hashmapvalreorganize_BM (hmv, 4 + ILOG2_BM (oldhsiz + 2) / 6);
      }
  }
  hashmapvalrawput_BM (hmv, keyv, valv);
  return hmv;
}                               /* end hashmapvalput_BM */

struct hashmapval_stBM *
hashmapvalremove_BM (struct hashmapval_stBM *hmv, value_tyBM keyv)
{
  if (!keyv)
    return ishashmapval_BM ((value_tyBM) hmv) ? hmv : NULL;
  if (!ishashmapval_BM ((value_tyBM) hmv))
    return NULL;
  struct hashpairindexes_stBM hvindexes =
    hashmapvalfindindexes_BM (hmv, keyv);
  int bix = hvindexes.hvi_buckix;
  int compix = hvindexes.hvi_compix;
  if (bix < 0 || compix < 0)
    return hmv;
  unsigned hslen = ((typedhead_tyBM *) hmv)->rlen;
  ASSERT_BM (bix < (int) hslen);
  struct hashmapbucket_stBM *curbuck = hmv->hashmap_vbuckets[bix];
  ASSERT_BM (curbuck != NULL);
  unsigned bucklen = ((typedhead_tyBM *) curbuck)->rlen;
  ASSERT_BM (compix < (int) bucklen);
  value_tyBM curkeyv = curbuck->vbent_arr[compix].hmap_keyv;
  if (curkeyv == NULL || curkeyv == (value_tyBM) HASHEMPTYSLOT_BM)
    return hmv;
  curbuck->vbent_arr[compix].hmap_keyv = HASHEMPTYSLOT_BM;
  curbuck->vbent_arr[compix].hmap_valv = NULL;
  ((struct typedsize_stBM *) curbuck)->size--;
  ((struct typedsize_stBM *) hmv)->size++;
  unsigned oldhsiz = ((struct typedsize_stBM *) hmv)->size;
  unsigned oldhlen = ((struct typedhead_stBM *) hmv)->rlen;
  if (oldhsiz > 2 * HASHTHRESHOLD_BM
      && oldhsiz < oldhlen * (HASHRATIO_BM / 2 + 1) + 2)
    hmv = hashmapvalreorganize_BM (hmv, 4 + ILOG2_BM (oldhsiz) / 3);
  return hmv;
}                               /* end hashmapvalremove_BM */


value_tyBM
hashmapvalfirstkey_BM (struct hashmapval_stBM * hmv)
{
  if (!ishashmapval_BM ((value_tyBM) hmv))
    return NULL;
  unsigned hslen = ((typedhead_tyBM *) hmv)->rlen;
  for (unsigned bix = 0; bix < hslen; bix++)
    {
      struct hashmapbucket_stBM *curbuck = hmv->hashmap_vbuckets[bix];
      if (!curbuck || curbuck == HASHEMPTYSLOT_BM)
        continue;
      ASSERT_BM (((typedhead_tyBM *) curbuck)->htyp ==
                 typayl_hashmapbucket_BM);
      unsigned bucklen = ((typedhead_tyBM *) curbuck)->rlen;
      for (unsigned enix = 0; enix < bucklen; enix++)
        {
          value_tyBM curkey = curbuck->vbent_arr[enix].hmap_keyv;
          if (!curkey)
            break;
          else if (curkey == HASHEMPTYSLOT_BM)
            continue;
          return curkey;
        }
    }
  return NULL;
}                               /* end hashmapvalfirstkey_BM */


value_tyBM
hashmapvalnextkey_BM (struct hashmapval_stBM * hmv, value_tyBM keyv)
{
  if (!ishashmapval_BM ((value_tyBM) hmv) || !keyv)
    return NULL;
  struct hashpairindexes_stBM hvindexes =
    hashmapvalfindindexes_BM (hmv, keyv);
  int bix = hvindexes.hvi_buckix;
  int compix = hvindexes.hvi_compix;
  if (bix < 0 || compix < 0)
    return NULL;
  unsigned hslen = ((typedhead_tyBM *) hmv)->rlen;
  struct hashmapbucket_stBM *curbuck = NULL;
  ASSERT_BM (bix < (int) hslen);
  curbuck = hmv->hashmap_vbuckets[bix];
  if (!curbuck || curbuck == HASHEMPTYSLOT_BM)
    return NULL;
  ASSERT_BM (((typedhead_tyBM *) curbuck)->htyp == typayl_hashmapbucket_BM);
  unsigned bucklen = ((typedhead_tyBM *) curbuck)->rlen;
  for (unsigned enix = compix + 1; enix < bucklen; enix++)
    {
      value_tyBM curkey = curbuck->vbent_arr[enix].hmap_keyv;
      if (!curkey)
        break;
      else if (curkey == HASHEMPTYSLOT_BM)
        continue;
      return curkey;
    }
  for (bix = bix + 1; bix < (int) hslen; bix++)
    {
      curbuck = hmv->hashmap_vbuckets[bix];
      if (!curbuck || curbuck == HASHEMPTYSLOT_BM)
        continue;
      ASSERT_BM (((typedhead_tyBM *) curbuck)->htyp ==
                 typayl_hashmapbucket_BM);
      unsigned bucklen = ((typedhead_tyBM *) curbuck)->rlen;
      for (unsigned enix = 0; enix < bucklen; enix++)
        {
          value_tyBM curkey = curbuck->vbent_arr[enix].hmap_keyv;
          if (!curkey)
            break;
          else if (curkey == HASHEMPTYSLOT_BM)
            continue;
          return curkey;
        }
    }
  return NULL;
}                               /* end of hashmapvalnextkey_BM */


value_tyBM
  hashmapvalmakenodeofkeys_BM
  (struct hashmapval_stBM * hmv, objectval_tyBM * connob)
{
  if (!ishashmapval_BM ((value_tyBM) hmv))
    return NULL;
  if (!isobject_BM ((value_tyBM) connob))
    return NULL;
  unsigned hmlen = ((typedhead_tyBM *) hmv)->rlen;
  unsigned hmsiz = ((typedsize_tyBM *) hmv)->size;
  value_tyBM tinyarr[TINYSIZE_BM] = { 0 };
  value_tyBM *keyarr =
    (hmsiz < TINYSIZE_BM)
    ? tinyarr : calloc (prime_above_BM (hmsiz + 1), sizeof (value_tyBM));
  if (!keyarr)
    FATAL_BM ("failed to calloc for %u values", hmsiz + 1);
  unsigned keycnt = 0;
  for (unsigned bix = 0; bix < hmlen; bix++)
    {
      struct hashmapbucket_stBM *curbuck = hmv->hashmap_vbuckets[bix];
      if (!curbuck || curbuck == HASHEMPTYSLOT_BM)
        continue;
      ASSERT_BM (((typedhead_tyBM *) curbuck)->htyp ==
                 typayl_hashmapbucket_BM);
      unsigned bucklen = ((typedhead_tyBM *) curbuck)->rlen;
      for (unsigned enix = 0; enix < bucklen; enix++)
        {
          value_tyBM curkey = curbuck->vbent_arr[enix].hmap_keyv;
          if (!curkey)
            break;
          else if (curkey == HASHEMPTYSLOT_BM)
            continue;
          ASSERT_BM (keycnt < hmsiz);
          keyarr[keycnt] = curkey;
          keycnt++;
        }
    }
  ASSERT_BM (keycnt == hmsiz);
  valarrqsort_BM (keyarr, keycnt);
  value_tyBM resv = (value_tyBM) makenode_BM (connob, keycnt, keyarr);
  if (keyarr != tinyarr)
    free (keyarr), keyarr = NULL;
  return resv;

}                               /* end hashmapvalmakenodeofkeys_BM */

#warning more needed on hashsets, hashmaps, etc....
