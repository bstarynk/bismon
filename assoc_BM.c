// file assoc_BM.c
#include "bismon.h"

static struct assocpairs_stBM *
assocpair_put_BM (struct assocpairs_stBM *apairs, objectval_tyBM * keyob,
                  value_BM val)
{
  assert (valtype_BM (keyob) == tyObject_BM);
  assert (valtype_BM (val) != tyNone_BM);
  struct assocpairs_stBM *newpairs = NULL;
  if (!apairs)
    {
      unsigned newsiz = TINYSIZE_BM / 3;
      newpairs =
        allocinternalty_BM (tydata_assocpairs_BM,
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
        allocinternalty_BM (tydata_assocpairs_BM,
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
      // should find some empty slot
      assert (oldcnt < oldlen);
      for (unsigned ix = 0; ix < oldlen; ix++)
        {
          if (!apairs->apairs_ent[ix].asso_keyob
              && !apairs->apairs_ent[ix].asso_val)
            {
              apairs->apairs_ent[ix].asso_keyob = keyob;
              apairs->apairs_ent[ix].asso_val = val;
              ((typedsize_tyBM *) apairs)->size = oldcnt + 1;
              return apairs;
            }
        };
      // should never be reached
      FATAL_BM ("corrupted assocpair @%p", apairs);
    }
}                               /* end assocpair_put_BM */



void
assoc_reorganize_BM (anyassoc_tyBM ** passoc, unsigned gap)
{
  // anyassoc_tyBM *oldassoc = *passoc;
}                               /* end assoc_reorganize_BM */

const setval_tyBM *
assoc_setattr_BM (const anyassoc_tyBM * assoc)
{
}                               /* end assoc_setattr_BM */


value_BM
assoc_getattr_BM (anyassoc_tyBM * assoc, const objectval_tyBM * obattr)
{
}                               /* end assoc_getattr_BM */

anyassoc_tyBM *
assoc_addattr_BM (anyassoc_tyBM * assoc,
                  const objectval_tyBM * obattr, value_BM val)
{
}                               /* end assoc_addattr_BM */

anyassoc_tyBM *
assoc_removeattr_BM (anyassoc_tyBM * assoc, const objectval_tyBM * obattr)
{
}                               /* end assoc_removeattr_BM */
