// file scalar_BM.c
#include "bismon.h"

const typedhead_tyBM unspecifieddata_BM = {
  .htyp = tyUnspecified_BM,
  .hgc = 0
};

//// string support

hash_tyBM
stringhash_BM (const char *cstr)
{
  if (!cstr)
    return 0;
  assert (g_utf8_validate (cstr, -1, NULL));
  long ll = strlen (cstr);
  if (ll >= MAXSIZE_BM)
    FATAL_BM ("too long string %ld", ll);
  int l = ll;
  const char *str = cstr;
  hash_tyBM h1 = l % 13, h2 = l, h = 0;
  while (l > 4)
    {
      h1 =
        (509 * h2 +
         307 * ((signed char *) str)[0]) ^ (1319 * ((signed char *) str)[1]);
      h2 =
        (17 * l + 5 + 5309 * h2) ^ ((3313 * ((signed char *) str)[2]) +
                                    9337 * ((signed char *) str)[3] + 517);
      l -= 4;
      str += 4;
    }
  if (l > 0)
    {
      h1 = (h1 * 7703) ^ (503 * ((signed char *) str)[0]);
      if (l > 1)
        {
          h2 = (h2 * 7717) ^ (509 * ((signed char *) str)[1]);
          if (l > 2)
            {
              h1 = (h1 * 9323) ^ (11 + 523 * ((signed char *) str)[2]);
              if (l > 3)
                {
                  h2 =
                    (h2 * 7727 + 127) ^ (313 +
                                         547 * ((signed char *) str)[3]);
                }
            }
        }
    }
  h = (h1 * 29311 + 59) ^ (h2 * 7321 + 120501);
  if (!h)
    {
      h = h1;
      if (!h)
        {
          h = h2;
          if (!h)
            h = (ll & 0xffffff) + 11;
        }
    }
  return h;
}                               /* end stringhash_BM */

extern const stringval_tyBM *
makestring_BM (const char *cstr)
{
  if (!cstr)
    return NULL;
  size_t sll = strlen (cstr);
  if (sll > MAXSIZE_BM)
    FATAL_BM ("makestring too long %ld string", (long) sll);
  if (!g_utf8_validate (cstr, -1, NULL))
    FATAL_BM ("makestring invalid string");
  int l = sll;
  hash_tyBM h = stringhash_BM (cstr);
  stringval_tyBM *strv =
    allocgcty_BM (tyString_BM, sizeof (stringval_tyBM) + (sll | 0xf) + 1);
  ((typedhead_tyBM *) strv)->hash = h;
  ((typedsize_tyBM *) strv)->size = l;
  memcpy (strv->strv_bytes, cstr, l);
  return strv;
}                               /* end makestring_BM */

extern const stringval_tyBM *
sprintfstring_BM (const char *fmt, ...)
{
  va_list args;
  char *buf = NULL;
  int ln = 0;
  if (!fmt)
    return NULL;
  if (!fmt[0])
    return makestring_BM ("");
  va_start (args, fmt);
  ln = vasprintf (&buf, fmt, args);
  va_end (args);
  if (ln < 0 || buf == NULL)
    FATAL_BM ("sprintfstring failure %m");
  const stringval_tyBM *res = makestring_BM (buf);
  free (buf);
  return res;
}                               /* end sprintfstring_BM */

int
lenstring_BM (const stringval_tyBM * strv)
{
  if (!strv || ((intptr_t) strv & 3)
      || ((typedhead_tyBM *) strv)->htyp != tyString_BM)
    return 0;
  return ((typedsize_tyBM *) strv)->size;
}                               /* end lenstring_BM */

const char *
bytstring_BM (const stringval_tyBM * strv)
{
  if (!strv || ((intptr_t) strv & 3)
      || ((typedhead_tyBM *) strv)->htyp != tyString_BM)
    return NULL;
  return strv->strv_bytes;
}                               /* end bytstring_BM */


bool
valsamecontent_BM (const value_tyBM v1, const value_tyBM v2)
{
  if (v1 == v2)
    return true;
  int ty1 = valtype_BM (v1);
  int ty2 = valtype_BM (v2);
  if (ty1 != ty2)
    return false;
  hash_tyBM h1 = valhash_BM (v1);
  hash_tyBM h2 = valhash_BM (v2);
  if (h1 != h2)
    return false;
  switch (ty1)                  /* same as ty2 */
    {
    case tyInt_BM:
      return true;
    case tyString_BM:
      return (((const typedsize_tyBM *) v1)->size ==
              ((const typedsize_tyBM *) v1)->size)
        && !strcmp (((stringval_tyBM *) v1)->strv_bytes,
                    ((stringval_tyBM *) v2)->strv_bytes);
    case tySet_BM:
    case tyTuple_BM:
      {
        const seqobval_tyBM *seq1 = v1;
        const seqobval_tyBM *seq2 = v2;
        if (((const typedsize_tyBM *) seq1)->size !=
            ((const typedsize_tyBM *) seq2)->size)
          return false;
        for (int ix = (int)(((const typedsize_tyBM *)seq1)->size) - 1;
             ix >= 0; ix--)
          if (seq1->seq_objs[ix] != seq2->seq_objs[ix])
            return false;
      }
      return true;
    case tyNode_BM:
    case tyClosure_BM:
      {
        const tree_tyBM *tr1 = v1;
        const tree_tyBM *tr2 = v2;
        if (tr1->nodt_conn != tr2->nodt_conn)
          return false;
        if (((const typedsize_tyBM *) tr1)->size !=
            ((const typedsize_tyBM *) tr2)->size)
          return false;
        for (int ix = (int)(((const typedsize_tyBM *)tr1)->size) - 1; ix >= 0;
             ix--)
          {
            if (tr1->nodt_sons[ix] == tr2->nodt_sons[ix])
              continue;
            if (!valequal_BM (tr1->nodt_sons[ix], tr2->nodt_sons[ix]))
              return false;
          }
      }
      return true;
    case tyObject_BM:
    default:
      return false;
    }
}                               /* end valsamecontent_BM */
