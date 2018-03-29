// file scalar_BM.c

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
  ASSERT_BM (g_utf8_validate (cstr, -1, NULL));
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

hash_tyBM
stringhashlen_BM (const char *cstr, long len)
{
  if (!cstr)
    return 0;
  if (len < 0)
    len = strlen (cstr);
  ASSERT_BM (g_utf8_validate (cstr, len, NULL));
  if (len >= MAXSIZE_BM)
    FATAL_BM ("too long string %ld", len);
  int l = len;
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
            h = (len & 0xffffff) + 11;
        }
    }
  return h;
}                               /* end stringhashlen_BM */


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
  stringval_tyBM *strv = allocgcty_BM (tyString_BM,
                                       (sizeof (stringval_tyBM) +
                                        (prime_above_BM (sll) | 0xf) + 1));
  ((typedhead_tyBM *) strv)->hash = h;
  ((typedsize_tyBM *) strv)->size = l;
  memcpy (strv->strv_bytes, cstr, l);
  return strv;
}                               /* end makestring_BM */


extern const stringval_tyBM *
makestringlen_BM (const char *cstr, long len)
{
  if (!cstr)
    return NULL;
  if (len < 0)
    len = strlen (cstr);
  if (len > MAXSIZE_BM)
    FATAL_BM ("makestringlen too long %ld string", len);
  if (!g_utf8_validate (cstr, len, NULL))
    FATAL_BM ("makestringlen invalid string");
  hash_tyBM h = stringhashlen_BM (cstr, len);
  unsigned long strsiz =
    sizeof (stringval_tyBM) + (prime_above_BM (len) | 0xf) + 1;
  ASSERT_BM (strsiz < (4L * MAXSIZE_BM / 3 + 5L) * sizeof (void *));
  stringval_tyBM *strv = allocgcty_BM (tyString_BM, strsiz);
  ((typedhead_tyBM *) strv)->hash = h;
  ((typedsize_tyBM *) strv)->size = len;
  memcpy (strv->strv_bytes, cstr, len);
  return strv;
}                               /* end makestringlen_BM */

void *
stringgcproc_BM (struct garbcoll_stBM *gc, stringval_tyBM * str)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) str)->htyp == tyString_BM);
  ((typedhead_tyBM *) str)->hgc = MARKGC_BM;
#warning stringgcproc_BM should forward when needed
  gc->gc_nbmarks++;
  return str;
}                               /* end stringgcproc_BM */

void
stringgcdestroy_BM (struct garbcoll_stBM *gc, stringval_tyBM * str)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) str)->htyp == tyString_BM);
  long sll = ((typedsize_tyBM *) str)->size;
  ASSERT_BM (sll < MAXSIZE_BM);
  unsigned long strsiz = sizeof (stringval_tyBM) + (sll | 0xf) + 1;
  ASSERT_BM (strsiz < (4L * MAXSIZE_BM / 3 + 5L) * sizeof (void *));
  memset (str, 0, sizeof (*str) + sll);
  free (str);
  gc->gc_freedbytes += strsiz;
}                               /* end stringgcdestroy_BM */


void
stringgckeep_BM (struct garbcoll_stBM *gc, stringval_tyBM * str)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) str)->htyp == tyString_BM);
  long sll = ((typedsize_tyBM *) str)->size;
  ASSERT_BM (sll < MAXSIZE_BM);
  unsigned long strsiz = sizeof (stringval_tyBM) + (sll | 0xf) + 1;
  ASSERT_BM (strsiz < (4L * MAXSIZE_BM / 3 + 5L) * sizeof (void *));
  gc->gc_keptbytes += strsiz;
}                               /* end stringgckeep_BM */


const stringval_tyBM *
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
  free (buf), buf = NULL;
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
valsamecontent_BM (const value_tyBM v1, const value_tyBM v2, int depth)
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
  if (depth + 2 > MAXDEPTHGC_BM)
    FATAL_BM ("too deep valsamecontent_BM depth %u", depth);
  switch (ty1)                  /* same as ty2 */
    {
    case tyInt_BM:
      return true;
    case tyString_BM:
      return (((const typedsize_tyBM *) v1)->size ==
              ((const typedsize_tyBM *) v2)->size)
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
            if (!valsamecontent_BM
                (tr1->nodt_sons[ix], tr2->nodt_sons[ix], depth + 1))
              return false;
          }
      }
      return true;
    case tyObject_BM:
    default:
      return false;
    }
}                               /* end valsamecontent_BM */



int
valcmpdepth_BM (const value_tyBM v1, const value_tyBM v2, int depth)
{
  if (v1 == v2)
    return 0;
  if (!v1)
    return -1;
  if (!v2)
    return +1;
  int ty1 = valtype_BM (v1);
  int ty2 = valtype_BM (v2);
  if (ty1 < ty2)
    return -1;
  else if (ty1 > ty2)
    return +1;
  if (depth > MAXDEPTHGC_BM)
    FATAL_BM ("too deep val compare %d", depth);
  switch (ty1)                  /* same as ty2 */
    {
    case tyInt_BM:
      {
        intptr_t i1 = ((intptr_t) v1) >> 1;
        intptr_t i2 = ((intptr_t) v2) >> 1;
        if (i1 < i2)
          return -1;
        else if (i1 > i2)
          return +1;
        FATAL_BM ("impossible case of same integers %lld & %lld",
                  (long long) i1, (long long) i2);
      }
    case tyString_BM:
      return strcmp (((stringval_tyBM *) v1)->strv_bytes,
                     ((stringval_tyBM *) v2)->strv_bytes);
    case tySet_BM:
    case tyTuple_BM:
      {
        const seqobval_tyBM *seq1 = v1;
        const seqobval_tyBM *seq2 = v2;
        unsigned siz1 = ((typedsize_tyBM *) seq1)->size;
        unsigned siz2 = ((typedsize_tyBM *) seq2)->size;
        unsigned minsiz = (siz1 < siz2) ? siz1 : siz2;
        for (unsigned ix = 0; ix < minsiz; ix++)
          {
            objectval_tyBM *comp1 = (objectval_tyBM *) seq1->seq_objs[ix];
            objectval_tyBM *comp2 = (objectval_tyBM *) seq2->seq_objs[ix];
            if (comp1 == comp2)
              continue;
            if (!comp1)
              return -1;
            if (!comp2)
              return +1;
            int cmpid = cmpid_BM (comp1->ob_id, comp2->ob_id);
            if (cmpid < 0)
              return -1;
            if (cmpid > 0)
              return +1;
            FATAL_BM
              ("corrupted components comp1@%p comp2@%p in seq1@%p seq2@%p ix#%u",
               (void *) comp1, (void *) comp2, (void *) seq1, (void *) seq2,
               ix);
          }
        if (siz1 == siz2)
          return 0;
        else if (siz1 < siz2)
          return -1;
        else
          return +1;
      }
    case tyObject_BM:
      {
        objectval_tyBM *ob1 = (objectval_tyBM *) v1;
        objectval_tyBM *ob2 = (objectval_tyBM *) v2;
        return cmpid_BM (ob1->ob_id, ob2->ob_id);
      }
    case tyClosure_BM:
    case tyNode_BM:
      {
        const tree_tyBM *tree1 = v1;
        const tree_tyBM *tree2 = v2;
        objectval_tyBM *conn1 = tree1->nodt_conn;
        objectval_tyBM *conn2 = tree2->nodt_conn;
        ASSERT_BM (isobject_BM (conn1));
        ASSERT_BM (isobject_BM (conn2));
        if (conn1 != conn2)
          return cmpid_BM (conn1->ob_id, conn2->ob_id);
        unsigned wid1 = ((const typedsize_tyBM *) tree1)->size;
        unsigned wid2 = ((const typedsize_tyBM *) tree2)->size;
        unsigned minwid = (wid1 < wid2) ? wid1 : wid2;
        for (unsigned ix = 0; ix < minwid; ix++)
          {
            const value_tyBM son1 = tree1->nodt_sons[ix];
            const value_tyBM son2 = tree2->nodt_sons[ix];
            if (son1 == son2 || valsamecontent_BM (son1, son2, depth + 1))
              continue;
            int cmp = valcmpdepth_BM (son1, son2, depth + 1);
            ASSERT_BM (cmp != 0);
            return cmp;
          }
        if (wid1 == wid2)
          return 0;
        else if (wid1 < wid2)
          return -1;
        else
          return +1;
      }
#warning incomplete valcmpdepth_BM
    }
  FATAL_BM ("uncomparable values @%p & @%p of type #%d",
            (void *) v1, (void *) v2, ty1);
}                               /* end valcmpdepth_BM */

int
valqcmp_BM (const void *p1, const void *p2)
{
  return valcmp_BM (*(value_tyBM *) p1, *(value_tyBM *) p2);
}                               /* end valqcmp_BM */

////////////////////////////////////////////////////////////////

void
strbuffergcmark_BM (struct garbcoll_stBM *gc, struct strbuffer_stBM *sbuf,
                    int depth __attribute__ ((unused)))
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) sbuf)->htyp == typayl_strbuffer_BM);
  ASSERT_BM (sbuf->sbuf_dbuf);
  ASSERT_BM (sbuf->sbuf_size > 0);
  ASSERT_BM (sbuf->sbuf_curp >= sbuf->sbuf_dbuf
             && sbuf->sbuf_curp < sbuf->sbuf_dbuf + sbuf->sbuf_size);
}                               /* end  strbuffergcmark_BM */


void
strbuffergcdestroy_BM (struct garbcoll_stBM *gc, struct strbuffer_stBM *sbuf)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) sbuf)->htyp == typayl_strbuffer_BM);
  ASSERT_BM (sbuf->sbuf_dbuf);
  size_t siz = sbuf->sbuf_size;
  ASSERT_BM (siz > 0 && siz < MAXSIZE_BM);
  unsigned long sbusiz = sizeof (*sbuf) + siz;
  ASSERT_BM (sbusiz < ((4L * MAXSIZE_BM) / 3 + 5L) * sizeof (void *));
  ASSERT_BM (sbuf->sbuf_curp >= sbuf->sbuf_dbuf
             && sbuf->sbuf_curp < sbuf->sbuf_dbuf + sbuf->sbuf_size);
  free (sbuf->sbuf_dbuf);
  gc->gc_freedbytes += sbusiz;
  memset (sbuf, 0, sizeof (*sbuf));
  free (sbuf);
}                               /* end strbuffergcdestroy_BM */


void
strbuffergckeep_BM (struct garbcoll_stBM *gc, struct strbuffer_stBM *sbuf)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) sbuf)->htyp == typayl_strbuffer_BM);
  ASSERT_BM (sbuf->sbuf_dbuf);
  size_t siz = sbuf->sbuf_size;
  ASSERT_BM (siz > 0 && siz < MAXSIZE_BM);
  ASSERT_BM (siz > 0 && siz < MAXSIZE_BM);
  unsigned long sbusiz = sizeof (*sbuf) + siz;
  ASSERT_BM (sbusiz < ((4L * MAXSIZE_BM) / 3 + 5L) * sizeof (void *));
  ASSERT_BM (sbuf->sbuf_curp >= sbuf->sbuf_dbuf
             && sbuf->sbuf_curp < sbuf->sbuf_dbuf + siz);
  gc->gc_keptbytes += sbusiz;
}                               /* end strbuffergckeep_BM */


bool
objputstrbufferpayl_BM (objectval_tyBM * obj, unsigned maxsize)
{
  if (!isobject_BM ((value_tyBM) obj))
    return false;
  if (maxsize > MAXSIZE_BM)
    FATAL_BM ("strbuffermake: too big maxsize %u for obj %s", maxsize,
              objectdbg_BM (obj));
  unsigned inisizew = (maxsize > 4096) ? 512 : 64;
  char *dbuf = malloc (inisizew * sizeof (void *));
  if (!dbuf)
    FATAL_BM ("malloc %zu bytes failed (%m)", inisizew * sizeof (void *));
  memset (dbuf, 0, inisizew * sizeof (void *));
  struct strbuffer_stBM *sbuf =
    allocgcty_BM (typayl_strbuffer_BM, sizeof (*sbuf));
  ((typedhead_tyBM *) sbuf)->rlen = maxsize;
  sbuf->sbuf_indent = 0;
  sbuf->sbuf_dbuf = dbuf;
  sbuf->sbuf_size = inisizew * sizeof (void *);
  sbuf->sbuf_curp = dbuf;
  sbuf->sbuf_lastnl = NULL;
  objputpayload_BM (obj, sbuf);
  if (objclass_BM (obj) == BMP_object)
    objputclass_BM (obj, BMP_sbuf_object);
  return true;
}                               /* end objputstrbufferpayl_BM */


const char *
objstrbufferbytespayl_BM (objectval_tyBM * obj)
{
  if (!isobject_BM ((value_tyBM) obj))
    return NULL;
  struct strbuffer_stBM *sbuf = objgetstrbufferpayl_BM (obj);
  if (!sbuf)
    return NULL;
  return sbuf->sbuf_dbuf;
}                               /* end objstrbufferbytespayl_BM */

void
objstrbufferreservepayl_BM (objectval_tyBM * obj, unsigned gap)
{
  struct strbuffer_stBM *sbuf = objgetstrbufferpayl_BM (obj);
  if (!sbuf)
    return;
  ASSERT_BM (sbuf->sbuf_dbuf);
  ASSERT_BM (sbuf->sbuf_size > 0);
  ASSERT_BM (sbuf->sbuf_curp >= sbuf->sbuf_dbuf
             && sbuf->sbuf_curp < sbuf->sbuf_dbuf + sbuf->sbuf_size);
  size_t siz = sbuf->sbuf_size;
  unsigned used = sbuf->sbuf_curp - sbuf->sbuf_dbuf;
  if (siz > 2048 && used + gap < siz / 2)
    {
      size_t newsiz = prime_above_BM ((used + gap) / 4 + used / 64 + 5) * 4;
      if (newsiz < siz)
        {
          char *newdbuf = malloc (newsiz);
          char *oldbuf = sbuf->sbuf_dbuf;
          if (!newdbuf)
            FATAL_BM ("malloc %zu failed", newsiz);
          memset (newdbuf, 0, newsiz);
          memcpy (newdbuf, oldbuf, used);
          if (sbuf->sbuf_lastnl)
            sbuf->sbuf_lastnl =
              newdbuf + (sbuf->sbuf_lastnl - sbuf->sbuf_dbuf);
          sbuf->sbuf_dbuf = newdbuf;
          sbuf->sbuf_curp = newdbuf + used;
          sbuf->sbuf_size = newsiz;
          free (oldbuf), oldbuf = NULL;
          return;
        }
    }
  else if (used + gap + 3 >= siz)
    {
      size_t newsiz =
        prime_above_BM ((used + gap) / 4 + used / 64 + gap / 128 + 6) * 4;
      if ((long) newsiz > 3 * (long) MAXSIZE_BM / 2)
        FATAL_BM ("too big newsiz %zd", newsiz);
      if (newsiz > siz)
        {
          char *newdbuf = malloc (newsiz);
          char *oldbuf = sbuf->sbuf_dbuf;
          if (!newdbuf)
            FATAL_BM ("malloc %zu failed", newsiz);
          memset (newdbuf, 0, newsiz);
          memcpy (newdbuf, oldbuf, used);
          if (sbuf->sbuf_lastnl)
            sbuf->sbuf_lastnl =
              newdbuf + (sbuf->sbuf_lastnl - sbuf->sbuf_dbuf);
          sbuf->sbuf_dbuf = newdbuf;
          sbuf->sbuf_curp = newdbuf + used;
          sbuf->sbuf_size = newsiz;
          free (oldbuf), oldbuf = NULL;
          return;
        }
    }
}                               /* end of objstrbufferreservepayl_BM */

int
objstrbufferindentationpayl_BM (objectval_tyBM * obj)
{
  struct strbuffer_stBM *sbuf = objgetstrbufferpayl_BM (obj);
  if (!sbuf)
    return 0;
  return sbuf->sbuf_indent;
}                               /* end objstrbufferindentationpayl_BM */

void
objstrbufferresetpayl_BM (objectval_tyBM * obj)
{
  struct strbuffer_stBM *sbuf = objgetstrbufferpayl_BM (obj);
  if (!sbuf)
    return;
  memset (sbuf->sbuf_dbuf, 0, sbuf->sbuf_size);
  sbuf->sbuf_curp = sbuf->sbuf_dbuf;
  sbuf->sbuf_lastnl = NULL;
  sbuf->sbuf_indent = 0;
}                               /* end objstrbufferresetpayl_BM */

unsigned
objstrbufferlengthpayl_BM (const objectval_tyBM * obj)
{
  struct strbuffer_stBM *sbuf =
    objgetstrbufferpayl_BM ((objectval_tyBM *) obj);
  if (!sbuf)
    return 0;
  ASSERT_BM (sbuf->sbuf_size < MAXSIZE_BM);
  ASSERT_BM (sbuf->sbuf_curp >= sbuf->sbuf_dbuf
             && sbuf->sbuf_curp < sbuf->sbuf_dbuf + sbuf->sbuf_size);
  return sbuf->sbuf_curp - sbuf->sbuf_dbuf;
}                               /* end objstrbufferlengthpayl_BM */

void
objstrbufferclearindentpayl_BM (objectval_tyBM * obj)
{
  struct strbuffer_stBM *sbuf = objgetstrbufferpayl_BM (obj);
  if (!sbuf)
    return;
  sbuf->sbuf_indent = 0;
}                               /* end  objstrbufferclearindentpayl_BM */



void
objstrbuffermoreindentpayl_BM (objectval_tyBM * obj)
{
  struct strbuffer_stBM *sbuf = objgetstrbufferpayl_BM (obj);
  if (!sbuf)
    return;
  sbuf->sbuf_indent++;
}                               /* end  objstrbuffermoreindentpayl_BM */


void
objstrbufferlessindentpayl_BM (objectval_tyBM * obj)
{
  struct strbuffer_stBM *sbuf = objgetstrbufferpayl_BM (obj);
  if (!sbuf)
    return;
  sbuf->sbuf_indent--;
}                               /* end  objstrbufferlessindent_BM */


static void
objstrbufferunsafeappendcstrpayl_BM (objectval_tyBM * obj, const char *cstr)
{
  struct strbuffer_stBM *sbuf = objgetstrbufferpayl_BM (obj);
  if (!sbuf)
    return;
  size_t len = strlen (cstr);
  ASSERT_BM (sbuf->sbuf_dbuf);
  size_t siz = sbuf->sbuf_size;
  unsigned maxsiz = ((typedhead_tyBM *) sbuf)->rlen;
  ASSERT_BM (siz > 0);
  ASSERT_BM (sbuf->sbuf_curp >= sbuf->sbuf_dbuf
             && sbuf->sbuf_curp < sbuf->sbuf_dbuf + sbuf->sbuf_size);
  if (sbuf->sbuf_curp + len + 3 >= sbuf->sbuf_dbuf + sbuf->sbuf_size)
    objstrbufferreservepayl_BM (obj, len + 2);
  int nloffset = -1;
  {
    char *lastnlcstr = strrchr (cstr, '\n');
    if (lastnlcstr)
      nloffset = lastnlcstr - cstr;
  }
  memcpy (sbuf->sbuf_curp, cstr, len);
  sbuf->sbuf_curp[len] = (char) 0;
  if (nloffset >= 0)
    sbuf->sbuf_lastnl = sbuf->sbuf_curp + nloffset;
  sbuf->sbuf_curp += len;
  *sbuf->sbuf_curp = (char) 0;
  if (maxsiz > 0 && sbuf->sbuf_curp - sbuf->sbuf_dbuf > maxsiz)
    FATAL_BM ("strbufferappendcstr overflow %ud", maxsiz);
}                               /* end objstrbufferunsafeappendcstr_BM  */


void
objstrbufferappendcstrpayl_BM (objectval_tyBM * obj, const char *cstr)
{
  if (!objhasstrbufferpayl_BM (obj))
    return;
  if (!cstr || !cstr[0])
    return;
  objstrbufferunsafeappendcstrpayl_BM (obj, cstr);
}                               /* end objstrbufferappendcstr_BM */

void
objstrbuffernewlinepayl_BM (objectval_tyBM * obj)
{
  struct strbuffer_stBM *sbuf = objgetstrbufferpayl_BM (obj);
  if (!sbuf)
    return;
  const char *nlb16 = "                \n";     // 16 spaces then newline
  int i = sbuf->sbuf_indent % 16;
  if (i < 0)
    i = 0;
  objstrbufferunsafeappendcstrpayl_BM (obj, nlb16 + (16 - i));
}                               /* end of objstrbuffernewline_BM */

void
objstrbufferrawprintfpayl_BM (objectval_tyBM * obj, const char *fmt, ...)
{
  struct strbuffer_stBM *sbuf = objgetstrbufferpayl_BM (obj);
  if (!sbuf)
    return;
  if (!fmt || !fmt[0])
    return;
  va_list args;
  char *tmpbuf = NULL;
  int ln = 0;
  va_start (args, fmt);
  ln = vasprintf (&tmpbuf, fmt, args);
  va_end (args);
  if (ln < 0 || tmpbuf == NULL)
    FATAL_BM ("strbufferrawprintf asprintf failure %m");
  objstrbufferunsafeappendcstrpayl_BM (obj, tmpbuf);
  free (tmpbuf), tmpbuf = NULL;
}                               /* end strbufferrawprintfpayl_BM  */


void
objstrbufferprintfpayl_BM (objectval_tyBM * obj, const char *fmt, ...)
{
  struct strbuffer_stBM *sbuf = objgetstrbufferpayl_BM (obj);
  if (!sbuf)
    return;
  if (!fmt || !fmt[0])
    return;
  va_list args;
  char *tmpbuf = NULL;
  int ln = 0;
  va_start (args, fmt);
  ln = vasprintf (&tmpbuf, fmt, args);
  va_end (args);
  if (ln < 0 || tmpbuf == NULL)
    FATAL_BM ("strbufferrawprintf asprintf failure %m");
  objstrbufferreservepayl_BM (obj, 9 * ln / 8 + ln / 64 + 2);
  char *prev = tmpbuf;
  for (char *pc = tmpbuf; *pc; pc++)
    {
      if (*pc == '\n')
        {
          *pc = (char) 0;
          objstrbufferappendcstrpayl_BM (obj, prev);
          objstrbuffernewlinepayl_BM (obj);
          prev = pc + 1;
        }
      else if (*pc == '\t')
        {
          *pc = (char) 0;
          objstrbufferappendcstrpayl_BM (obj, prev);
          if (sbuf->sbuf_lastnl
              && sbuf->sbuf_curp >
              sbuf->sbuf_lastnl + 1 + (5 * STRBUFFERWANTEDWIDTH_BM) / 6)
            objstrbuffernewlinepayl_BM (obj);
          else
            objstrbufferunsafeappendcstrpayl_BM (obj, " ");
          prev = pc + 1;
        }
      else if (pc[1] == (char) 0)
        {
          objstrbufferunsafeappendcstrpayl_BM (obj, prev);
        }
    }
  free (tmpbuf), tmpbuf = NULL;
}                               /* end objstrbufferprintfpayl_BM */

void
objstrbufferencodedutf8payl_BM (objectval_tyBM * obj, const char *str,
                                ssize_t bytelen)
{
  if (!str)
    return;
  struct strbuffer_stBM *sbuf = objgetstrbufferpayl_BM (obj);
  if (!sbuf)
    return;
  if (bytelen < 0)
    bytelen = strlen (str);
  if (!g_utf8_validate (str, bytelen, NULL))
    return;
  objstrbufferreservepayl_BM (obj, 9 * bytelen / 8 + 10);
  const char *ends = str + bytelen;
  for (const char *pc = str; pc < ends; pc = g_utf8_next_char (pc))
    {
      gunichar uc = g_utf8_get_char (pc);
      switch (uc)
        {
        case '\"':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\\"");
          break;
        case '\'':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\\'");
          break;
        case '\a':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\a");
          break;
        case '\b':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\b");
          break;
        case '\f':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\f");
          break;
        case '\n':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\n");
          break;
        case '\r':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\r");
          break;
        case '\t':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\t");
          break;
        case '\v':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\v");
          break;
        case '\033' /*ESCAPE*/:
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\e");
          break;
        default:
          {
            char ubuf[16];
            memset (ubuf, 0, sizeof (ubuf));
            if (uc >= ' ' && uc < 127)
              ubuf[0] = (char) uc;
            else if (uc < 0xffff)
              snprintf (ubuf, sizeof (ubuf), "\\u%04x", uc);
            else
              snprintf (ubuf, sizeof (ubuf), "\\U%08x", uc);
            objstrbufferunsafeappendcstrpayl_BM (obj, ubuf);
          }
          break;
        }
    }
}                               /* end objstrbufferencodedutf8_BM */




void
objstrbufferencodedc_BM (objectval_tyBM * obj, const char *str,
                         ssize_t bytelen)
{
  if (!str)
    return;
  struct strbuffer_stBM *sbuf = objgetstrbufferpayl_BM (obj);
  if (!sbuf)
    return;
  if (bytelen < 0)
    bytelen = strlen (str);
  objstrbufferreservepayl_BM (obj, 9 * bytelen / 8 + 10);
  const char *ends = str + bytelen;
  for (const char *pc = str; pc < ends; pc++)
    {
      switch (*pc)
        {
        case '\"':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\\"");
          break;
        case '\'':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\\'");
          break;
        case '\a':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\a");
          break;
        case '\b':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\b");
          break;
        case '\f':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\f");
          break;
        case '\n':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\n");
          break;
        case '\r':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\r");
          break;
        case '\t':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\t");
          break;
        case '\v':
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\v");
          break;
        case '\033' /*ESCAPE*/:
          objstrbufferunsafeappendcstrpayl_BM (obj, "\\e");
          break;
        default:
          {
            char ubuf[8] = "";
            if (*pc < 127 && *pc >= ' ')
              {
                ubuf[0] = *pc;
                ubuf[1] = (char) 0;
              }
            else
              snprintf (ubuf, sizeof (ubuf), "\\x%02x", *pc);
            objstrbufferunsafeappendcstrpayl_BM (obj, ubuf);
          };
          break;
        }
    }
}                               /* end strbufferencodedc_BM */



void
objstrbufferwritetofilepayl_BM (objectval_tyBM * obj, const char *filepath)
{
  if (!filepath || !filepath[0])
    return;
  struct strbuffer_stBM *sbuf = objgetstrbufferpayl_BM (obj);
  if (!sbuf)
    return;
  ASSERT_BM (sbuf->sbuf_dbuf);
  size_t siz = sbuf->sbuf_size;
  unsigned maxsiz = ((typedhead_tyBM *) sbuf)->rlen;
  ASSERT_BM (siz > 0 && siz <= maxsiz);
  ASSERT_BM (sbuf->sbuf_curp >= sbuf->sbuf_dbuf
             && sbuf->sbuf_curp < sbuf->sbuf_dbuf + sbuf->sbuf_size);
  unsigned len = sbuf->sbuf_curp - sbuf->sbuf_dbuf;
  FILE *oldfil = fopen (filepath, "r");
  bool samefile = (oldfil != NULL);
  if (oldfil)
    {
      struct stat oldstat = { };
      fstat (fileno (oldfil), &oldstat);
      if (oldstat.st_size != (unsigned) len)
        samefile = false;
      unsigned ix = 0;
      while (samefile)
        {
          int c = fgetc (oldfil);
          if (c == EOF)
            {
              samefile = (ix == len);
              break;
            };
          samefile = (c == sbuf->sbuf_dbuf[ix]);
          ix++;
        };
      fclose (oldfil);
    }
  if (samefile)
    return;
  if (strlen (filepath) < 3 * TINYSIZE_BM)
    {
      char backpath[3 * TINYSIZE_BM + 5];
      memset (backpath, 0, sizeof (backpath));
      snprintf (backpath, sizeof (backpath), "%s~", filepath);
      (void) rename (filepath, backpath);
    }
  else
    {
      char *backpath = NULL;
      asprintf (&backpath, "%s~", filepath);
      if (!backpath)
        FATAL_BM ("asprintf failure for backpath %s", filepath);
      if (rename (filepath, backpath))
        FATAL_BM ("failed to rename %s as %s (%m)", filepath, backpath);
      free (backpath), backpath = NULL;
    }
  FILE *newfil = fopen (filepath, "w");
  if (!newfil)
    FATAL_BM ("fopen %s failed (%m)", filepath);
  if (fwrite (sbuf->sbuf_dbuf, len, 1, newfil) != 1)
    FATAL_BM ("fwrite into %s %u bytes failed (%m)", filepath,
              (unsigned) len);
  if (fclose (newfil))
    FATAL_BM ("fclose %s failed (%m)", filepath);
}                               /* end objstrbufferwritetofilepayl_BM */
