// file assoc_BM.c
// SPDX-License-Identifier: GPL-3.0-or-later
/***
    BISMON 
    Copyright © 2018, 2019 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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

/******** ASSOCIATIONS FROM OBJECTS TO VALUES ********/

/// assocpairs for individual buckets, or small associations
// allocated size of typayl_assocpairs_BM
#define ASSOCPAIRSIZE_BM(Asp) ((typedhead_tyBM*)(Asp))->rlen
// used count of typayl_assocpairs_BM
#define ASSOCPAIRUCNT_BM(Asp)  ((typedsize_tyBM*)(Asp))->size

/// assoctables for larger associations, pointing to assocpairs (buckets)
// allocated size of typayl_assoctable_BM
#define ASSOCTABLESIZE_BM(Asb) ((typedhead_tyBM*)(Asb))->rlen
// cumulated count - totals of used counts in the many assocpairs
#define ASSOCTABLECUMCNT_BM(Asb)  ((typedsize_tyBM*)(Asb))->size

unsigned
assoc_nbkeys_BM (const anyassoc_tyBM * assoc)
{
  if (!assoc)
    return 0;
  int ty = valtype_BM ((value_tyBM) assoc);
  if (ty == typayl_assocpairs_BM)
    {
      struct assocpairs_stBM *apair = (struct assocpairs_stBM *) assoc;
      return ASSOCPAIRUCNT_BM (apair);
    }
  else if (ty == typayl_assoctable_BM)
    {
      struct assoctable_stBM *atbl = (struct assoctable_stBM *) assoc;
      return ASSOCTABLECUMCNT_BM (atbl);
    }
  return 0;
}                               /* end assoc_nbkeys_BM */




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
      ASSOCPAIRSIZE_BM (newpairs) = newsiz;
      ASSOCPAIRUCNT_BM (newpairs) = 1;
      newpairs->apairs_ent[0].asso_keyob = keyob;
      newpairs->apairs_ent[0].asso_val = val;
      return newpairs;
    };
  ASSERT_BM (valtype_BM (apairs) == typayl_assocpairs_BM);
  unsigned oldsiz = ASSOCPAIRSIZE_BM (apairs);
  unsigned oldcnt = ASSOCPAIRUCNT_BM (apairs);
  ASSERT_BM (oldcnt <= oldsiz);
  if (oldcnt == oldsiz)
    {
      // if key was here, put new value in entry
      for (unsigned ix = 0; ix < oldsiz; ix++)
        {
          if (apairs->apairs_ent[ix].asso_keyob == keyob)
            {
              apairs->apairs_ent[ix].asso_val = val;
              return apairs;
            }
        }
      // should grow
      unsigned long newsiz =
        prime_above_BM (4 * oldsiz / 3 + oldsiz / 64 + ILOG2_BM (oldsiz + 2) +
                        3);
      if (newsiz >= MAXSIZE_BM)
        FATAL_BM ("too big assocpairs %lu for oldsiz %u", newsiz, oldsiz);
      newpairs =
        allocgcty_BM (typayl_assocpairs_BM,
                      sizeof (struct assocpairs_stBM) +
                      newsiz * sizeof (struct assocentry_stBM));
      ASSOCPAIRSIZE_BM (newpairs) = newsiz;
      unsigned cnt = 0;
      for (unsigned ix = 0; ix < oldsiz; ix++)
        {
          if (apairs->apairs_ent[ix].asso_keyob
              && apairs->apairs_ent[ix].asso_val)
            {
              newpairs->apairs_ent[cnt++] = apairs->apairs_ent[ix];
              ASSERT_BM (cnt < newsiz);
            }
        };
      ASSERT_BM (cnt == oldcnt);
      newpairs->apairs_ent[cnt].asso_keyob = keyob;
      newpairs->apairs_ent[cnt].asso_val = val;
      cnt++;
      ASSOCPAIRUCNT_BM (newpairs) = cnt;
      return newpairs;
    }
  else
    {
      // should find some empty slot - or the existing one
      ASSERT_BM (oldcnt < oldsiz);
      for (unsigned ix = 0; ix < oldsiz; ix++)
        {
          struct assocentry_stBM *curent = apairs->apairs_ent + ix;
          if (!curent->asso_keyob)
            {
              ASSERT_BM (!curent->asso_val);
              curent->asso_keyob = keyob;
              curent->asso_val = val;
              ASSOCPAIRUCNT_BM (apairs) = oldcnt + 1;
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
assoc_buckix_for_key_BM (const struct assoctable_stBM *atble,
                         const objectval_tyBM * obkey)
{
  ASSERT_BM (valtype_BM ((const value_tyBM) atble) == typayl_assoctable_BM);
  ASSERT_BM (valtype_BM ((const value_tyBM) obkey) == tyObject_BM);
  hash_tyBM hkey = objecthash_BM (obkey);
  ASSERT_BM (hkey != 0);
  unsigned nbuckets = ASSOCTABLESIZE_BM (atble);
  ASSERT_BM (nbuckets > 2 && nbuckets % 2 != 0);
  return hkey % nbuckets;
}                               /* end assoc_buckix_for_key_BM */



void
assoc_reorganize_BM (anyassoc_tyBM ** passoc, unsigned gap)
{
  ASSERT_BM (passoc != NULL);
  anyassoc_tyBM *oldassoc = *passoc;
  bool oldassocistable = valtype_BM (oldassoc) == typayl_assoctable_BM;
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
      if (oldassocispairs && newpairsiz == ASSOCPAIRSIZE_BM (oldassoc))
        return;
      struct assocpairs_stBM *newpairs = newpairsiz ?
        allocgcty_BM (typayl_assocpairs_BM,
                      sizeof (struct assocpairs_stBM) +
                      newpairsiz * sizeof (struct assocentry_stBM)) : NULL;
      if (newpairs)
        {
          ASSOCPAIRSIZE_BM (newpairs) = newpairsiz;
          ASSOCPAIRUCNT_BM (newpairs) = 0;
        }
      if (oldassocistable)
        {
          unsigned newpaircnt = 0;
          unsigned nbuckets = ASSOCTABLESIZE_BM (oldassoc);
          for (unsigned buckix = 0; buckix < nbuckets; buckix++)
            {
              struct assocpairs_stBM *curbuckpair =
                ((struct assoctable_stBM *) oldassoc)->abuck_pairs[buckix];
              if (curbuckpair)
                {
                  ASSERT_BM (valtype_BM (curbuckpair) ==
                             typayl_assocpairs_BM);
                  unsigned bucksiz = ASSOCPAIRSIZE_BM (curbuckpair);
                  for (unsigned pix = 0; pix < bucksiz; pix++)
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
                  ASSOCPAIRUCNT_BM (newpairs) = newpaircnt;
                  ((struct assoctable_stBM *) oldassoc)->abuck_pairs[buckix]
                    = NULL;
                }
            }
          *passoc = newpairs;
        }                       /* end if oldassocistable */
      else if (oldassocispairs)
        {
          struct assocpairs_stBM *oldpairs = oldassoc;
          ASSERT_BM (valtype_BM (oldpairs) == typayl_assocpairs_BM);
          unsigned bucksiz = ASSOCPAIRSIZE_BM (oldpairs);
          unsigned newpaircnt = 0;
          for (unsigned pix = 0; pix < bucksiz; pix++)
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
          ASSOCPAIRUCNT_BM (newpairs) = newpaircnt;
          *passoc = newpairs;
        }                       /* end if oldassocispairs */
      else
        *passoc = newpairs;
      return;
    }                           /* end if newish  <= TINYSIZE_BM */
  if (newish > MAXSIZE_BM)
    FATAL_BM ("new assoc wish %lu too big", newish);
  unsigned newnbuckets =
    prime_above_BM (newish / (TINYSIZE_BM - 3) + gap / 128 +
                    ILOG2_BM (oldcnt + gap + 1) / 4 + 4);
  if (newnbuckets > MAXSIZE_BM)
    FATAL_BM ("too big #buckets %u in assoc", newnbuckets);
  struct assoctable_stBM *newtable =    //
    allocgcty_BM (typayl_assoctable_BM,
                  sizeof (struct assoctable_stBM)
                  + newnbuckets * sizeof (newtable->abuck_pairs[0]));
  ASSOCTABLESIZE_BM (newtable) = newnbuckets;
  ASSOCTABLECUMCNT_BM (newtable) = 0;
  if (oldassocistable)
    {
      unsigned addedcnt = 0;
      unsigned nbuckets = ASSOCTABLESIZE_BM (oldassoc);
      for (unsigned buckix = 0; buckix < nbuckets; buckix++)
        {
          struct assocpairs_stBM *curbuckpair =
            ((struct assoctable_stBM *) oldassoc)->abuck_pairs[buckix];
          if (curbuckpair)
            {
              ASSERT_BM (valtype_BM (curbuckpair) == typayl_assocpairs_BM);
              unsigned bucklen = ASSOCPAIRSIZE_BM (curbuckpair);
              for (unsigned pix = 0; pix < bucklen; pix++)
                {
                  const objectval_tyBM *curkeyob =
                    curbuckpair->apairs_ent[pix].asso_keyob;
                  value_tyBM curval = curbuckpair->apairs_ent[pix].asso_val;
                  if (curkeyob && curval)
                    {
                      unsigned newbuckix =
                        assoc_buckix_for_key_BM (newtable, curkeyob);
                      struct assocpairs_stBM *prevnewpairs =
                        newtable->abuck_pairs[newbuckix];
                      struct assocpairs_stBM *updatednewpairs
                        = assocpair_put_BM (prevnewpairs, curkeyob, curval);
                      if (updatednewpairs != prevnewpairs)
                        newtable->abuck_pairs[newbuckix] = updatednewpairs;
                      addedcnt++;
                    }
                }
              ((struct assoctable_stBM *) oldassoc)->abuck_pairs[buckix] =
                NULL;
            }
        }
      ASSERT_BM (addedcnt == oldcnt);
      ASSOCTABLECUMCNT_BM (newtable) = addedcnt;
    }
  else if (oldassocispairs)
    {
      struct assocpairs_stBM *oldpairs = oldassoc;
      ASSERT_BM (valtype_BM (oldpairs) == typayl_assocpairs_BM);
      unsigned bucklen = ASSOCPAIRSIZE_BM (oldpairs);
      unsigned addedcnt = 0;
      for (unsigned pix = 0; pix < bucklen; pix++)
        {
          const objectval_tyBM *curkeyob =
            oldpairs->apairs_ent[pix].asso_keyob;
          value_tyBM curval = oldpairs->apairs_ent[pix].asso_val;
          if (curkeyob && curval)
            {
              unsigned newbuckix =
                assoc_buckix_for_key_BM (newtable, curkeyob);
              struct assocpairs_stBM *prevnewpairs =
                newtable->abuck_pairs[newbuckix];
              struct assocpairs_stBM *updatednewpairs
                = assocpair_put_BM (prevnewpairs, curkeyob, curval);
              if (updatednewpairs != prevnewpairs)
                newtable->abuck_pairs[newbuckix] = updatednewpairs;
              addedcnt++;
            }
        }
      ASSERT_BM (addedcnt == oldcnt);
      ASSOCTABLECUMCNT_BM (newtable) = addedcnt;
    }
  *passoc = newtable;
}                               /* end assoc_reorganize_BM */



void
assocpairgcdestroy_BM (struct garbcoll_stBM *gc, struct assocpairs_stBM *assp)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) assp)->htyp == typayl_assocpairs_BM);
  unsigned len = ASSOCPAIRSIZE_BM (assp);
  memset (assp, 0, sizeof (*assp) + len * sizeof (struct assocentry_stBM));
  free (assp);
  gc->gc_freedbytes += sizeof (*assp) + len * sizeof (struct assocentry_stBM);
}                               /* end assocpairgcdestroy_BM */

void
assocpairgckeep_BM (struct garbcoll_stBM *gc, struct assocpairs_stBM *assp)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) assp)->htyp == typayl_assocpairs_BM);
  unsigned len = ASSOCPAIRSIZE_BM (assp);
  ASSERT_BM (len < MAXSIZE_BM);
  gc->gc_keptbytes += sizeof (*assp) + len * sizeof (struct assocentry_stBM);
}                               /* end assocpairgckeep_BM */

void
assoctablegcdestroy_BM (struct garbcoll_stBM *gc,
                        struct assoctable_stBM *abuck)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) abuck)->htyp == typayl_assoctable_BM);
  unsigned nbuckets = ASSOCTABLESIZE_BM (abuck);
  memset (abuck, 0, sizeof (*abuck) + nbuckets * sizeof (void *));
  free (abuck);
  gc->gc_freedbytes += sizeof (*abuck) + nbuckets * sizeof (void *);
}                               /*end assoctablegcdestroy_BM */


void
assoctablegckeep_BM (struct garbcoll_stBM *gc, struct assoctable_stBM *abuck)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) abuck)->htyp == typayl_assoctable_BM);
  unsigned nbuckets = ASSOCTABLESIZE_BM (abuck);
  ASSERT_BM (nbuckets < MAXSIZE_BM);
  gc->gc_keptbytes += sizeof (*abuck) + nbuckets * sizeof (void *);
}                               /* end assoctablegckeep_BM */


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
  if (valtype_BM ((const value_tyBM) assoc) == typayl_assoctable_BM)
    {
      unsigned nbuckets = ((typedhead_tyBM *) assoc)->rlen;
      for (unsigned buckix = 0; buckix < nbuckets; buckix++)
        {
          struct assocpairs_stBM *curbuckpair =
            ((struct assoctable_stBM *) assoc)->abuck_pairs[buckix];
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
      unsigned bucklen = ASSOCPAIRSIZE_BM (curpairs);
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
  if (valtype_BM ((const value_tyBM) assoc) == typayl_assoctable_BM)
    {
      unsigned buckix = assoc_buckix_for_key_BM (assoc, obattr);
      curpairs =
        ((const struct assoctable_stBM *) assoc)->abuck_pairs[buckix];
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
  if (valtype_BM ((const value_tyBM) assoc) == typayl_assoctable_BM)
    {
      struct assoctable_stBM *abuck = (struct assoctable_stBM *) assoc;
      unsigned nbbuckets = ((typedhead_tyBM *) abuck)->rlen;
      if (nbkeys > nbbuckets * TINYSIZE_BM)
        assoc_reorganize_BM (&assoc, 3 + nbkeys / 64);
    };
  if (valtype_BM ((const value_tyBM) assoc) == typayl_assocpairs_BM)
    {
      return assocpair_put_BM ((struct assocpairs_stBM *) assoc, obattr, val);
    }
  else if (valtype_BM ((const value_tyBM) assoc) == typayl_assoctable_BM)
    {
      unsigned buckix = assoc_buckix_for_key_BM (assoc, obattr);
      struct assocpairs_stBM *curpairs =
        ((const struct assoctable_stBM *) assoc)->abuck_pairs[buckix];
      ASSERT_BM (!curpairs
                 || valtype_BM ((const value_tyBM) curpairs) ==
                 typayl_assocpairs_BM);
      unsigned oldpaircnt =
        curpairs ? ((typedsize_tyBM *) curpairs)->size : 0;
      struct assocpairs_stBM *newpairs =
        assocpair_put_BM (curpairs, obattr, val);
      if (newpairs != curpairs)
        ((struct assoctable_stBM *) assoc)->abuck_pairs[buckix] = newpairs;
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
  int assotyp = valtype_BM ((const value_tyBM) assoc);
  if (assotyp == typayl_assoctable_BM)
    {
      struct assoctable_stBM *atable = (struct assoctable_stBM *) assoc;
      unsigned buckix = assoc_buckix_for_key_BM (assoc, obattr);
      struct assocpairs_stBM *curpairs =
        ((const struct assoctable_stBM *) assoc)->abuck_pairs[buckix];
      ASSERT_BM (!curpairs
                 || valtype_BM ((const value_tyBM) curpairs) ==
                 typayl_assocpairs_BM);
      if (curpairs)
        {
          unsigned busiz = ASSOCPAIRSIZE_BM (curpairs);
          for (unsigned pix = 0; pix < busiz; pix++)
            {
              const objectval_tyBM *curkeyob =
                curpairs->apairs_ent[pix].asso_keyob;
              if (curkeyob == obattr)
                {
                  curpairs->apairs_ent[pix].asso_keyob = NULL;
                  curpairs->apairs_ent[pix].asso_val = NULL;
                  ASSOCPAIRUCNT_BM (curpairs)--;
                  ASSOCTABLECUMCNT_BM (atable)--;
                  nbkeys--;
                  goto perhapsreorganize;
                }
            }
        };
      return atable;
    }
  else if (assotyp == typayl_assocpairs_BM)
    {
      struct assocpairs_stBM *curpairs = assoc;
      unsigned pairsiz = ASSOCPAIRSIZE_BM (curpairs);
      unsigned cnt = ASSOCPAIRUCNT_BM (curpairs);
      for (unsigned pix = 0; pix < pairsiz; pix++)
        {
          const objectval_tyBM *curkeyob =
            curpairs->apairs_ent[pix].asso_keyob;
          if (curkeyob == obattr)
            {
              ASSERT_BM (cnt > 0);
              curpairs->apairs_ent[pix].asso_keyob = NULL;
              curpairs->apairs_ent[pix].asso_val = NULL;
              ASSOCPAIRUCNT_BM (curpairs) = cnt - 1;
              nbkeys--;
              goto perhapsreorganize;
            }
        };
      return curpairs;
    }
  else
    FATAL_BM ("assoc_removeattr_BM: invalid assotyp #%d assoc@%p", assotyp,
              (void *) assoc);
perhapsreorganize:
  if (assotyp == typayl_assoctable_BM)
    {
      if (ASSOCTABLECUMCNT_BM (assoc) <= 2 * TINYSIZE_BM
          || (3 * ASSOCTABLECUMCNT_BM (assoc)) / 2 <
          TINYSIZE_BM * ASSOCTABLESIZE_BM (assoc))
        {
          unsigned aucnt = ASSOCTABLECUMCNT_BM (assoc);
          unsigned apsiz = ASSOCTABLESIZE_BM (assoc);
          ASSERT_BM (aucnt == nbkeys);
          ASSERT_BM (aucnt < apsiz);
          unsigned gap = 1 + ILOG2_BM (aucnt + 1);
          assoc_reorganize_BM (&assoc, gap);
          return assoc;
        }
    }
  else
    {
      ASSERT_BM (assotyp == typayl_assocpairs_BM);
      unsigned aucnt = ASSOCPAIRUCNT_BM (assoc);
      unsigned apsiz = ASSOCPAIRSIZE_BM (assoc);
      ASSERT_BM (aucnt <= apsiz);
      if (aucnt < 3 * apsiz)
        {
          ASSERT_BM (aucnt == nbkeys);
          unsigned gap = 2 + aucnt / 64 + ILOG2_BM (aucnt + 1);
          assoc_reorganize_BM (&assoc, gap);
          return assoc;
        }
    }
  return assoc;
}                               /* end assoc_removeattr_BM */



void *
assocpairsgcproc_BM (struct garbcoll_stBM *gc,
                     struct assocpairs_stBM *apairs,
                     objectval_tyBM * fromob, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM (apairs) == typayl_assocpairs_BM);
  ASSERT_BM (!fromob || isobject_BM (fromob));
  uint8_t oldmark = ((typedhead_tyBM *) apairs)->hgc;
  if (oldmark)
    return apairs;
  ((typedhead_tyBM *) apairs)->hgc = MARKGC_BM;
  unsigned pairsiz = ASSOCPAIRSIZE_BM (apairs);
  for (unsigned pix = 0; pix < pairsiz; pix++)
    {
      const objectval_tyBM *curkeyob = apairs->apairs_ent[pix].asso_keyob;
      if (!curkeyob || curkeyob == HASHEMPTYSLOT_BM)
        {
          apairs->apairs_ent[pix].asso_val = NULL;
          continue;
        };
      gcobjmark_BM (gc, (objectval_tyBM *) curkeyob);
      value_tyBM curval = apairs->apairs_ent[pix].asso_val;
      if (curval)
        {
          VALUEGCPROC_BM (gc, curval, depth + 1);
          apairs->apairs_ent[pix].asso_val = curval;
        }
    }
  gc->gc_nbmarks++;
  return apairs;
}                               /* end assocpairsgcproc_BM */



void *
assoctablegcproc_BM (struct garbcoll_stBM *gc,
                     struct assoctable_stBM *atable,
                     objectval_tyBM * fromob, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM (atable) == typayl_assoctable_BM);
  ASSERT_BM (!fromob || isobject_BM (fromob));
  unsigned tblsiz = ASSOCTABLESIZE_BM (atable);
  for (unsigned bix = 0; bix < tblsiz; bix++)
    {
      struct assocpairs_stBM *curbuckpair = atable->abuck_pairs[bix];
      if (!curbuckpair)
        continue;
      ASSERT_BM (valtype_BM (curbuckpair) == typayl_assocpairs_BM);
      uint8_t oldbuckmark = ((typedhead_tyBM *) curbuckpair)->hgc;
      if (oldbuckmark)
        continue;
      ((typedhead_tyBM *) curbuckpair)->hgc = MARKGC_BM;
      gc->gc_nbmarks++;
      unsigned bucksiz = ASSOCPAIRSIZE_BM (curbuckpair);
      for (unsigned pix = 0; pix < bucksiz; pix++)
        {
          const objectval_tyBM *curkeyob =
            curbuckpair->apairs_ent[pix].asso_keyob;
          if (!curkeyob || curkeyob == HASHEMPTYSLOT_BM)
            {
              curbuckpair->apairs_ent[pix].asso_val = NULL;
              continue;
            }
          gcobjmark_BM (gc, (objectval_tyBM *) curkeyob);
          value_tyBM curval = curbuckpair->apairs_ent[pix].asso_val;
          if (curval)
            {
              VALUEGCPROC_BM (gc, curval, depth + 1);
              curbuckpair->apairs_ent[pix].asso_val = curval;
            }
        }
    }
  return atable;
}                               /* end assoctablegcproc_BM */


void *
assocgcproc_BM (struct garbcoll_stBM *gc, anyassoc_tyBM * assoc,
                objectval_tyBM * fromob, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (!fromob || isobject_BM (fromob));
  int aty = valtype_BM (assoc);
  if (aty == typayl_assoctable_BM)
    return assoctablegcproc_BM (gc, (struct assoctable_stBM *) assoc, fromob,
                                depth);
  else if (aty == typayl_assocpairs_BM)
    return assocpairsgcproc_BM (gc, (struct assocpairs_stBM *) assoc, fromob,
                                depth);
  else
    FATAL_BM ("assogcproc_BM: invalid assoc@%p type#%d fromob %s, depth#%d",
              (void *) assoc, aty, objectdbg_BM (fromob), depth);
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
                     objectval_tyBM * fromob, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (ishashsetval_BM ((value_tyBM) hsv));
  ASSERT_BM (fromob != NULL || isobject_BM(fromob));
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
      EXTENDEDGCPROC_BM (gc, vbu, fromob, depth + 1);
    }
}                               /* end hashsetvalgcmark_BM */

void
hashsetvbucketgcmark_BM (struct garbcoll_stBM *gc,
                         struct hashsetvbucket_stBM *hvb,
                         objectval_tyBM * fromob, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (ishashsetvbucket_BM ((value_tyBM) hvb));
  ASSERT_BM (fromob == NULL || isobject_BM (fromob));
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
      .hvi_compix = -1
    };
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
            .hvi_compix = vix
          };
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
            .hvi_compix = vix
          };
        }
    }
  return EMPTYPAIRINDEXES_BM;
}                               /* end hashsetvalfindindexes_BM */

bool
hashsetvalcontains_BM (struct hashsetval_stBM *hsv, value_tyBM val)
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
hashsetvalfirst_BM (struct hashsetval_stBM *hsv)
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
hashsetvalnext_BM (struct hashsetval_stBM *hsv, value_tyBM prev)
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
hashsetvalmakenode_BM (struct hashsetval_stBM *hsv, objectval_tyBM * connob)
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

// on hashmapval-s
//// the allocated size, number of buckets
#define HASHMAPVALSIZE_BM(Hmv) ((typedhead_tyBM*)(Hmv))->rlen
//// the total number of entries, cumulated in buckets
#define HASHMAPVALUCNT_BM(Hmv) ((typedsize_tyBM*)(Hmv))->size
// on hashmapbucket-s
#define HASHMAPBUCKSIZE_BM(Hmb) ((typedhead_tyBM*)(Hmb))->rlen
#define HASHMAPBUCKUCNT_BM(Hmb) ((typedsize_tyBM*)(Hmb))->size

void
hashmapvalgcmark_BM (struct garbcoll_stBM *gc, struct hashmapval_stBM *hmv,
                     objectval_tyBM * fromob, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (ishashmapval_BM ((value_tyBM) hmv));
  ASSERT_BM (!fromob || isobject_BM (fromob));
  uint8_t oldmark = ((typedhead_tyBM *) hmv)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) hmv)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  unsigned siz = HASHMAPVALSIZE_BM (hmv);
  for (unsigned ix = 0; ix < siz; ix++)
    {
      struct hashmapbucket_stBM *vbu = hmv->hashmap_vbuckets[ix];
      if (!vbu || vbu == HASHEMPTYSLOT_BM)
        continue;
      ASSERT_BM (valtype_BM ((value_tyBM) vbu) == typayl_hashmapbucket_BM);
      EXTENDEDGCPROC_BM (gc, vbu, fromob, depth + 1);
    }
}                               /* end hashmapvalgcmark_BM */

void
hashmapbucketgcmark_BM (struct garbcoll_stBM *gc,
                        struct hashmapbucket_stBM *hvb,
                        objectval_tyBM * fromob, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (ishashmapbucket_BM ((value_tyBM) hvb));
  ASSERT_BM (!fromob || isobject_BM (fromob));
  uint8_t oldmark = ((typedhead_tyBM *) hvb)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) hvb)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  unsigned ucnt = HASHMAPBUCKUCNT_BM (hvb);
  unsigned siz = HASHMAPBUCKSIZE_BM (hvb);
  ASSERT_BM (ucnt <= siz);
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
  unsigned siz = HASHMAPVALSIZE_BM (hsv);
  memset (hsv, 0,
          sizeof (*hsv) + siz * sizeof (struct hashmapvbucket_stBM *));
  free (hsv);
  gc->gc_freedbytes +=
    sizeof (*hsv) + siz * sizeof (struct hashmapvbucket_stBM *);
}                               /* end  hashmapvalgcdestroy_BM */

void
hashmapbucketgcdestroy_BM (struct garbcoll_stBM *gc,
                           struct hashmapbucket_stBM *hvb)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) hvb)->htyp == typayl_hashmapbucket_BM);
  unsigned siz = HASHMAPBUCKSIZE_BM (hvb);
  memset (hvb, 0, sizeof (*hvb) + siz * sizeof (value_tyBM));
  free (hvb);
  gc->gc_freedbytes += sizeof (*hvb)
    + siz * sizeof (struct hashmapentry_stBM);
}                               /* end hashmapbucketgcdsestroy_BM */

void
hashmapvalgckeep_BM (struct garbcoll_stBM *gc, struct hashmapval_stBM *hsv)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) hsv)->htyp == typayl_hashmapval_BM);
  unsigned ucnt = HASHMAPVALUCNT_BM (hsv);
  unsigned siz = HASHMAPVALSIZE_BM (hsv);
  ASSERT_BM (siz < MAXSIZE_BM && ucnt < MAXSIZE_BM);
  gc->gc_keptbytes +=
    sizeof (*hsv) + siz * sizeof (struct hashmapvbucket_stBM *);
}                               /* end  hashmapvalgckeep_BM */

void
hashmapbucketgckeep_BM (struct garbcoll_stBM *gc,
                        struct hashmapbucket_stBM *hvb)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) hvb)->htyp == typayl_hashmapbucket_BM);
  unsigned siz = HASHMAPBUCKSIZE_BM (hvb);
  ASSERT_BM (siz < MAXSIZE_BM);
  gc->gc_keptbytes += sizeof (*hvb) + siz * sizeof (struct hashmapentry_stBM);
}                               /* end hashmapvbucketgckeep_BM */


static struct hashpairindexes_stBM
hashmapvalfindindexes_BM (struct hashmapval_stBM *hmv, value_tyBM val)
{
  ASSERT_BM (hmv && ((typedhead_tyBM *) hmv)->htyp == typayl_hashmapval_BM);
  if (!val)
    return EMPTYPAIRINDEXES_BM;
  unsigned siz = HASHMAPVALSIZE_BM (hmv);
  ASSERT_BM (siz < MAXSIZE_BM && siz > 2);
  hash_tyBM hva = valhash_BM (val);
  unsigned bix = hva % siz;
  struct hashmapbucket_stBM *curbuck = hmv->hashmap_vbuckets[bix];
  if (!curbuck)
    return (struct hashpairindexes_stBM)
    {
      .hvi_buckix = bix,        //
      .hvi_compix = -1
    };
  ASSERT_BM (((typedhead_tyBM *) curbuck)->htyp == typayl_hashmapbucket_BM);
  unsigned bucksiz = HASHMAPBUCKSIZE_BM (curbuck);
  int buckpos = -1;
  for (unsigned vix = 0; vix < bucksiz; vix++)
    {
      value_tyBM curkey = curbuck->vbent_arr[vix].hmap_keyv;
      if (!curkey)
        {
          if (buckpos < 0)
            buckpos = (int) vix;
          return (struct hashpairindexes_stBM)
          {
            .hvi_buckix = bix,  //
            .hvi_compix = vix
          };
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
            .hvi_compix = vix
          };
        }
    }
  return EMPTYPAIRINDEXES_BM;
}                               /* end hashmapvalfindindexes_BM */


value_tyBM
hashmapvalget_BM (struct hashmapval_stBM *hmv, value_tyBM keyv)
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
  unsigned hmsiz = HASHMAPVALSIZE_BM (hmv);
  ASSERT_BM (bix < (int) hmsiz);
  struct hashmapbucket_stBM *curbuck = hmv->hashmap_vbuckets[bix];
  ASSERT_BM (curbuck != NULL);
  unsigned bucksiz = HASHMAPBUCKSIZE_BM (curbuck);
  ASSERT_BM (compix < (int) bucksiz);
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
  unsigned hmsiz = HASHMAPVALSIZE_BM (hmv);
  ASSERT_BM (bix < (int) hmsiz);
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
      ASSERT_BM (valtype_BM ((value_tyBM) curbuck) ==
                 typayl_hashmapbucket_BM);
      unsigned oldbucksiz = HASHMAPBUCKSIZE_BM (curbuck);
      ASSERT_BM (oldbucksiz == HASHMAPBUCKUCNT_BM (curbuck));
      unsigned newbucksiz =
        prime_above_BM (4 * oldbucksiz / 3 + 3 +
                        ILOG2_BM (oldbucksiz + 1) / 4);
      if (newbucksiz > MAXSIZE_BM)
        FATAL_BM ("too big bucket size %u", newbucksiz);
      struct hashmapbucket_stBM *newbuck =
        allocgcty_BM (typayl_hashmapbucket_BM,
                      sizeof (struct hashmapbucket_stBM) +
                      newbucksiz * sizeof (struct hashmapentry_stBM));
      HASHMAPBUCKSIZE_BM (newbuck) = newbucksiz;
      memcpy (newbuck->vbent_arr, curbuck->vbent_arr,
              oldbucksiz * sizeof (struct hashmapentry_stBM));
      newbuck->vbent_arr[oldbucksiz].hmap_keyv = keyv;
      newbuck->vbent_arr[oldbucksiz].hmap_valv = valv;
      HASHMAPBUCKUCNT_BM (newbuck) = oldbucksiz + 1;
      hmv->hashmap_vbuckets[bix] = newbuck;
      HASHMAPVALUCNT_BM (hmv)++;
      return;
    }
  ASSERT_BM (valtype_BM ((value_tyBM) curbuck) == typayl_hashmapbucket_BM);
  unsigned bucksiz = HASHMAPBUCKSIZE_BM (curbuck);
  ASSERT_BM (compix >= 0 && compix < (int) bucksiz);
  value_tyBM oldkeyv = curbuck->vbent_arr[compix].hmap_keyv;
  if (!oldkeyv || oldkeyv == HASHEMPTYSLOT_BM)
    {
      curbuck->vbent_arr[compix].hmap_keyv = keyv;
      curbuck->vbent_arr[compix].hmap_valv = valv;
      HASHMAPBUCKUCNT_BM (curbuck)++;
      HASHMAPVALUCNT_BM (hmv)++;
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
  unsigned oldhsiz = hmv ? HASHMAPVALSIZE_BM (hmv) : 0;
  unsigned oldhlen = hmv ? HASHMAPVALUCNT_BM (hmv) : 0;
  unsigned newsiz =
    prime_above_BM ((oldhlen + gap) / HASHRATIO_BM +
                    ILOG2_BM (oldhlen + gap + 2) + 3);
  if (newsiz > MAXSIZE_BM)
    FATAL_BM ("too big new size %u for hashmapval", newsiz);
  struct hashmapval_stBM *newhmv =      //
    allocgcty_BM (typayl_hashmapval_BM,
                  sizeof (struct hashmapval_stBM) +
                  newsiz * sizeof (struct hashmapbucket_stBM *));
  HASHMAPVALSIZE_BM (newhmv) = newsiz;
  if (!oldhsiz)
    return newhmv;
  for (unsigned oldbix = 0; oldbix < oldhsiz; oldbix++)
    {
      struct hashmapbucket_stBM *oldbuck = hmv->hashmap_vbuckets[oldbix];
      if (!oldbuck)
        continue;
      ASSERT_BM (valtype_BM ((value_tyBM) oldbuck) ==
                 typayl_hashmapbucket_BM);
      unsigned oldbucksiz = HASHMAPBUCKSIZE_BM (oldbuck);
      for (unsigned oldelix = 0; oldelix < oldbucksiz; oldelix++)
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
    unsigned oldhsiz = HASHMAPVALSIZE_BM (hmv);
    unsigned oldhcnt = HASHMAPVALUCNT_BM (hmv);
    if (oldhsiz * HASHTHRESHOLD_BM > oldhcnt + 2)
      hmv = hashmapvalreorganize_BM (hmv, 4 + ILOG2_BM (oldhcnt + 2) / 4);
    else if (oldhsiz
             > oldhcnt
             * (HASHRATIO_BM + (HASHTHRESHOLD_BM - HASHRATIO_BM) / 2) +
             ILOG2_BM (oldhcnt + 3))
      {
        if (g_random_int () % HASHTHRESHOLD_BM == 0)
          hmv = hashmapvalreorganize_BM (hmv, 4 + ILOG2_BM (oldhcnt + 2) / 6);
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
  unsigned hsiz = HASHMAPVALSIZE_BM (hmv);
  ASSERT_BM (bix < (int) hsiz);
  struct hashmapbucket_stBM *curbuck = hmv->hashmap_vbuckets[bix];
  ASSERT_BM (curbuck != NULL
             && valtype_BM (curbuck) == typayl_hashmapbucket_BM);
  unsigned bucksiz = HASHMAPBUCKSIZE_BM (curbuck);
  ASSERT_BM (compix < (int) bucksiz);
  value_tyBM curkeyv = curbuck->vbent_arr[compix].hmap_keyv;
  if (curkeyv == NULL || curkeyv == (value_tyBM) HASHEMPTYSLOT_BM)
    return hmv;
  curbuck->vbent_arr[compix].hmap_keyv = HASHEMPTYSLOT_BM;
  curbuck->vbent_arr[compix].hmap_valv = NULL;
  HASHMAPBUCKUCNT_BM (curbuck)--;
  HASHMAPVALUCNT_BM (hmv)--;
  unsigned hcnt = HASHMAPVALUCNT_BM (hmv);
  if (hsiz > 2 * HASHTHRESHOLD_BM
      && hsiz < HASHMAPVALUCNT_BM (hmv) * (HASHRATIO_BM / 2 + 1) + 2)
    hmv = hashmapvalreorganize_BM (hmv, 4 + ILOG2_BM (hcnt + 2) / 3);
  return hmv;
}                               /* end hashmapvalremove_BM */


value_tyBM
hashmapvalfirstkey_BM (struct hashmapval_stBM *hmv)
{
  if (!ishashmapval_BM ((value_tyBM) hmv))
    return NULL;
  unsigned hsiz = HASHMAPVALSIZE_BM (hmv);
  for (unsigned bix = 0; bix < hsiz; bix++)
    {
      struct hashmapbucket_stBM *curbuck = hmv->hashmap_vbuckets[bix];
      if (!curbuck || curbuck == HASHEMPTYSLOT_BM)
        continue;
      ASSERT_BM (((typedhead_tyBM *) curbuck)->htyp ==
                 typayl_hashmapbucket_BM);
      unsigned bucksiz = HASHMAPBUCKSIZE_BM (curbuck);
      for (unsigned enix = 0; enix < bucksiz; enix++)
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
hashmapvalnextkey_BM (struct hashmapval_stBM *hmv, value_tyBM keyv)
{
  if (!ishashmapval_BM ((value_tyBM) hmv) || !keyv)
    return NULL;
  struct hashpairindexes_stBM hvindexes =
    hashmapvalfindindexes_BM (hmv, keyv);
  int bix = hvindexes.hvi_buckix;
  int compix = hvindexes.hvi_compix;
  if (bix < 0 || compix < 0)
    return NULL;
  unsigned hsiz = HASHMAPVALSIZE_BM (hmv);
  struct hashmapbucket_stBM *curbuck = NULL;
  ASSERT_BM (bix < (int) hsiz);
  curbuck = hmv->hashmap_vbuckets[bix];
  if (!curbuck || curbuck == HASHEMPTYSLOT_BM)
    return NULL;
  ASSERT_BM (((typedhead_tyBM *) curbuck)->htyp == typayl_hashmapbucket_BM);
  unsigned bucksiz = HASHMAPBUCKSIZE_BM (curbuck);
  for (unsigned enix = compix + 1; enix < bucksiz; enix++)
    {
      value_tyBM curkey = curbuck->vbent_arr[enix].hmap_keyv;
      if (!curkey)
        break;
      else if (curkey == HASHEMPTYSLOT_BM)
        continue;
      return curkey;
    }
  for (bix = bix + 1; bix < (int) bucksiz; bix++)
    {
      curbuck = hmv->hashmap_vbuckets[bix];
      if (!curbuck || curbuck == HASHEMPTYSLOT_BM)
        continue;
      ASSERT_BM (((typedhead_tyBM *) curbuck)->htyp ==
                 typayl_hashmapbucket_BM);
      unsigned bucksiz = HASHMAPBUCKSIZE_BM (curbuck);
      for (unsigned enix = 0; enix < bucksiz; enix++)
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
  (struct hashmapval_stBM *hmv, objectval_tyBM * connob)
{
  if (!ishashmapval_BM ((value_tyBM) hmv))
    return NULL;
  if (!isobject_BM ((value_tyBM) connob))
    return NULL;
  unsigned hmcnt = HASHMAPVALUCNT_BM (hmv);
  unsigned hmsiz = HASHMAPVALSIZE_BM (hmv);
  value_tyBM tinyarr[TINYSIZE_BM] = { 0 };
  value_tyBM *keyarr =
    (hmcnt < TINYSIZE_BM)
    ? tinyarr : calloc (prime_above_BM (hmcnt + 1), sizeof (value_tyBM));
  if (!keyarr)
    FATAL_BM ("failed to calloc for %u values", hmcnt + 1);
  unsigned keycnt = 0;
  for (unsigned bix = 0; bix < hmsiz; bix++)
    {
      struct hashmapbucket_stBM *curbuck = hmv->hashmap_vbuckets[bix];
      if (!curbuck || curbuck == HASHEMPTYSLOT_BM)
        continue;
      ASSERT_BM (((typedhead_tyBM *) curbuck)->htyp ==
                 typayl_hashmapbucket_BM);
      unsigned bucksiz = HASHMAPBUCKSIZE_BM (curbuck);
      for (unsigned enix = 0; enix < bucksiz; enix++)
        {
          value_tyBM curkey = curbuck->vbent_arr[enix].hmap_keyv;
          if (!curkey)
            break;
          else if (curkey == HASHEMPTYSLOT_BM)
            continue;
          ASSERT_BM (keycnt < hmcnt);
          keyarr[keycnt] = curkey;
          keycnt++;
        }
    }
  ASSERT_BM (keycnt == hmcnt);
  valarrqsort_BM (keyarr, keycnt);
  value_tyBM resv = (value_tyBM) makenode_BM (connob, keycnt, keyarr);
  if (keyarr != tinyarr)
    free (keyarr), keyarr = NULL;
  return resv;

}                               /* end hashmapvalmakenodeofkeys_BM */

#warning more needed on hashsets, hashmaps, etc....

/**** end of file assoc_BM.c ****/
