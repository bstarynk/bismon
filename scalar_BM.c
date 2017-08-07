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
    allocgcty_BM (tyString_BM, (sizeof (stringval_tyBM) + (sll | 0xf) + 1));
  ((typedhead_tyBM *) strv)->hash = h;
  ((typedsize_tyBM *) strv)->size = l;
  memcpy (strv->strv_bytes, cstr, l);
  return strv;
}                               /* end makestring_BM */

void
stringgcdestroy_BM (struct garbcoll_stBM *gc, stringval_tyBM * str)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) str)->htyp == tyString_BM);
  long sll = ((typedsize_tyBM *) str)->size;
  memset (str, 0, sizeof (*str) + sll);
  free (str);
  gc->gc_freedbytes += sizeof (*str) + (sll | 0xf) + 1;
}                               /* end stringgcdestroy_BM */


void
stringgckeep_BM (struct garbcoll_stBM *gc, stringval_tyBM * str)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) str)->htyp == tyString_BM);
  long sll = ((typedsize_tyBM *) str)->size;
  gc->gc_keptbytes += sizeof (*str) + (sll | 0xf) + 1;
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

////////////////////////////////////////////////////////////////

void
strbuffergcmark_BM (struct garbcoll_stBM *gc, struct strbuffer_stBM *sbuf,
                    int depth __attribute__ ((unused)))
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) sbuf)->htyp == tydata_strbuffer_BM);
  assert (sbuf->sbuf_dbuf);
  assert (sbuf->sbuf_size > 0);
  assert (sbuf->sbuf_curp >= sbuf->sbuf_dbuf
          && sbuf->sbuf_curp < sbuf->sbuf_dbuf + sbuf->sbuf_size);
}                               /* end  strbuffergcmark_BM */


void
strbuffergcdestroy_BM (struct garbcoll_stBM *gc, struct strbuffer_stBM *sbuf)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) sbuf)->htyp == tydata_strbuffer_BM);
  assert (sbuf->sbuf_dbuf);
  size_t siz = sbuf->sbuf_size;
  assert (siz > 0);
  assert (sbuf->sbuf_curp >= sbuf->sbuf_dbuf
          && sbuf->sbuf_curp < sbuf->sbuf_dbuf + sbuf->sbuf_size);
  free (sbuf->sbuf_dbuf);
  gc->gc_freedbytes += sizeof (*sbuf) + siz;
  memset (sbuf, 0, sizeof (*sbuf));
  free (sbuf);
}                               /* end strbuffergcdestroy_BM */

void
strbuffergckeep_BM (struct garbcoll_stBM *gc, struct strbuffer_stBM *sbuf)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) sbuf)->htyp == tydata_strbuffer_BM);
  assert (sbuf->sbuf_dbuf);
  assert (sbuf->sbuf_size > 0);
  assert (sbuf->sbuf_curp >= sbuf->sbuf_dbuf
          && sbuf->sbuf_curp < sbuf->sbuf_dbuf + sbuf->sbuf_size);
  size_t siz = sbuf->sbuf_size;
  gc->gc_keptbytes += sizeof (*sbuf) + siz;
}                               /* end strbuffergckeep_BM */


struct strbuffer_stBM *
strbuffermake_BM (unsigned maxsize)
{
  if (maxsize > MAXSIZE_BM)
    FATAL_BM ("too big maxsize %u", maxsize);
  unsigned inisizew = (maxsize > 4096) ? 512 : 64;
  char *dbuf = malloc (inisizew * sizeof (void *));
  if (!dbuf)
    FATAL_BM ("malloc %zu bytes failed (%m)", inisizew * sizeof (void *));
  memset (dbuf, 0, inisizew * sizeof (void *));
  struct strbuffer_stBM *sbuf =
    allocgcty_BM (tydata_strbuffer_BM, sizeof (*sbuf));
  ((typedhead_tyBM *) sbuf)->rlen = maxsize;
  sbuf->sbuf_indent = 0;
  sbuf->sbuf_dbuf = dbuf;
  sbuf->sbuf_size = inisizew * sizeof (void *);
  sbuf->sbuf_curp = dbuf;
  sbuf->sbuf_lastnl = NULL;
  return sbuf;
}                               /* end strbuffermake_BM */

void
strbufferreserve_BM (struct strbuffer_stBM *sbuf, unsigned gap)
{
  if (!isstrbuffer_BM ((const value_tyBM) sbuf))
    return;
  assert (sbuf->sbuf_dbuf);
  assert (sbuf->sbuf_size > 0);
  assert (sbuf->sbuf_curp >= sbuf->sbuf_dbuf
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
          free (oldbuf);
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
          free (oldbuf);
          return;
        }
    }
}                               /* end of strbufferreserve_BM */


void
strbufferreset_BM (struct strbuffer_stBM *sbuf)
{
  if (!isstrbuffer_BM ((const value_tyBM) sbuf))
    return;
  memset (sbuf->sbuf_dbuf, 0, sbuf->sbuf_size);
  sbuf->sbuf_curp = sbuf->sbuf_dbuf;
  sbuf->sbuf_lastnl = NULL;
  sbuf->sbuf_indent = 0;
}                               /* end strbufferreset_BM */

unsigned
strbufferlength_BM (struct strbuffer_stBM *sbuf)
{
  if (!isstrbuffer_BM ((const value_tyBM) sbuf))
    return 0;
  assert (sbuf->sbuf_size < MAXSIZE_BM);
  assert (sbuf->sbuf_curp >= sbuf->sbuf_dbuf
          && sbuf->sbuf_curp < sbuf->sbuf_dbuf + sbuf->sbuf_size);
  return sbuf->sbuf_curp - sbuf->sbuf_dbuf;
}                               /* end strbufferlength_BM */

void
strbufferclearindent_BM (struct strbuffer_stBM *sbuf)
{
  if (!isstrbuffer_BM ((const value_tyBM) sbuf))
    return;
  sbuf->sbuf_indent = 0;
}                               /* end  strbufferclearindent_BM */



void
strbuffermoreindent_BM (struct strbuffer_stBM *sbuf)
{
  if (!isstrbuffer_BM ((const value_tyBM) sbuf))
    return;
  sbuf->sbuf_indent++;
}                               /* end  strbuffermoreindent_BM */


void
strbufferlessindent_BM (struct strbuffer_stBM *sbuf)
{
  if (!isstrbuffer_BM ((const value_tyBM) sbuf))
    return;
  sbuf->sbuf_indent--;
}                               /* end  strbufferlessindent_BM */


static void
strbufferunsafeappendcstr_BM (struct strbuffer_stBM *sbuf, const char *cstr)
{
  size_t len = strlen (cstr);
  assert (sbuf->sbuf_dbuf);
  size_t siz = sbuf->sbuf_size;
  unsigned maxsiz = ((typedhead_tyBM *) sbuf)->rlen;
  assert (siz > 0);
  assert (sbuf->sbuf_curp >= sbuf->sbuf_dbuf
          && sbuf->sbuf_curp < sbuf->sbuf_dbuf + sbuf->sbuf_size);
  if (sbuf->sbuf_curp + len + 3 >= sbuf->sbuf_dbuf + sbuf->sbuf_size)
    strbufferreserve_BM (sbuf, len + 2);
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
  if (maxsiz > 0 && sbuf->sbuf_curp - sbuf->sbuf_dbuf > maxsiz)
    FATAL_BM ("strbufferappendcstr overflow %ud", maxsiz);
}                               /* end strbufferunsafeappendcstr_BM  */


void
strbufferappendcstr_BM (struct strbuffer_stBM *sbuf, const char *cstr)
{
  if (!isstrbuffer_BM ((const value_tyBM) sbuf))
    return;
  if (!cstr || !cstr[0])
    return;
  strbufferunsafeappendcstr_BM (sbuf, cstr);
}                               /* end strbufferappendcstr_BM */

void
strbuffernewline_BM (struct strbuffer_stBM *sbuf)
{
  if (!isstrbuffer_BM ((const value_tyBM) sbuf))
    return;
  const char *nlb16 = "                \n";     // 16 spaces then newline
  int i = sbuf->sbuf_indent % 16;
  if (i < 0)
    i = 0;
  strbufferunsafeappendcstr_BM (sbuf, nlb16 + (16 - i));
}                               /* end of strbuffernewline_BM */

void
strbufferrawprintf_BM (struct strbuffer_stBM *sbuf, const char *fmt, ...)
{
  if (!isstrbuffer_BM ((const value_tyBM) sbuf))
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
  strbufferunsafeappendcstr_BM (sbuf, tmpbuf);
  free (tmpbuf);
}                               /* end strbufferrawprintf_BM  */


void
strbufferprintf_BM (struct strbuffer_stBM *sbuf, const char *fmt, ...)
{
  if (!isstrbuffer_BM ((const value_tyBM) sbuf))
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
  strbufferreserve_BM (sbuf, 9 * ln / 8 + ln / 64 + 2);
  char *prev = tmpbuf;
  for (char *pc = tmpbuf; *pc; pc++)
    {
      if (*pc == '\n')
        {
          *pc = (char) 0;
          strbufferappendcstr_BM (sbuf, prev);
          strbuffernewline_BM (sbuf);
          prev = pc + 1;
        }
      else if (*pc == '\t')
        {
          *pc = (char) 0;
          strbufferappendcstr_BM (sbuf, prev);
          if (sbuf->sbuf_lastnl
              && sbuf->sbuf_curp >
              sbuf->sbuf_lastnl + 1 + (5 * STRBUFFERWANTEDWIDTH_BM) / 6)
            strbuffernewline_BM (sbuf);
          else
            strbufferunsafeappendcstr_BM (sbuf, " ");
          prev = pc + 1;
        }
      else if (pc[1] == (char) 0)
        {
          strbufferunsafeappendcstr_BM (sbuf, prev);
        }
    }
  free (tmpbuf);
}                               /* end strbufferprintf_BM */

void
strbufferencodedutf8_BM (struct strbuffer_stBM *sbuf, const char *str,
                         ssize_t bytelen)
{
  if (!isstrbuffer_BM ((const value_tyBM) sbuf))
    return;
  if (!str)
    return;
  if (bytelen < 0)
    bytelen = strlen (str);
  if (!g_utf8_validate (str, bytelen, NULL))
    return;
  strbufferreserve_BM (sbuf, 9 * bytelen / 8 + 10);
  const char *ends = str + bytelen;
  for (const char *pc = str; pc < ends; pc = g_utf8_next_char (pc))
    {
      gunichar uc = g_utf8_get_char (pc);
      switch (uc)
        {
        case '\"':
          strbufferunsafeappendcstr_BM (sbuf, "\\\"");
          break;
        case '\'':
          strbufferunsafeappendcstr_BM (sbuf, "\\\'");
          break;
        case '\a':
          strbufferunsafeappendcstr_BM (sbuf, "\\a");
          break;
        case '\b':
          strbufferunsafeappendcstr_BM (sbuf, "\\b");
          break;
        case '\f':
          strbufferunsafeappendcstr_BM (sbuf, "\\f");
          break;
        case '\n':
          strbufferunsafeappendcstr_BM (sbuf, "\\n");
          break;
        case '\r':
          strbufferunsafeappendcstr_BM (sbuf, "\\r");
          break;
        case '\t':
          strbufferunsafeappendcstr_BM (sbuf, "\\t");
          break;
        case '\v':
          strbufferunsafeappendcstr_BM (sbuf, "\\v");
          break;
        case '\033' /*ESCAPE*/:
          strbufferunsafeappendcstr_BM (sbuf, "\\e");
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
            strbufferunsafeappendcstr_BM (sbuf, ubuf);
          }
          break;
        }
    }
}                               /* end strbufferencodedutf8_BM */




void
strbufferencodedc_BM (struct strbuffer_stBM *sbuf, const char *str,
                      ssize_t bytelen)
{
  if (!isstrbuffer_BM ((const value_tyBM) sbuf))
    return;
  if (!str)
    return;
  if (bytelen < 0)
    bytelen = strlen (str);
  strbufferreserve_BM (sbuf, 9 * bytelen / 8 + 10);
  const char *ends = str + bytelen;
  for (const char *pc = str; pc < ends; pc++)
    {
      switch (*pc)
        {
        case '\"':
          strbufferunsafeappendcstr_BM (sbuf, "\\\"");
          break;
        case '\'':
          strbufferunsafeappendcstr_BM (sbuf, "\\\'");
          break;
        case '\a':
          strbufferunsafeappendcstr_BM (sbuf, "\\a");
          break;
        case '\b':
          strbufferunsafeappendcstr_BM (sbuf, "\\b");
          break;
        case '\f':
          strbufferunsafeappendcstr_BM (sbuf, "\\f");
          break;
        case '\n':
          strbufferunsafeappendcstr_BM (sbuf, "\\n");
          break;
        case '\r':
          strbufferunsafeappendcstr_BM (sbuf, "\\r");
          break;
        case '\t':
          strbufferunsafeappendcstr_BM (sbuf, "\\t");
          break;
        case '\v':
          strbufferunsafeappendcstr_BM (sbuf, "\\v");
          break;
        case '\033' /*ESCAPE*/:
          strbufferunsafeappendcstr_BM (sbuf, "\\e");
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
            strbufferunsafeappendcstr_BM (sbuf, ubuf);
          };
          break;
        }
    }
}                               /* end strbufferencodedc_BM */



void
strbufferwritetofile_BM (struct strbuffer_stBM *sbuf, const char *filepath)
{
  if (!isstrbuffer_BM ((const value_tyBM) sbuf))
    return;
  if (!filepath || !filepath[0])
    return;
  assert (sbuf->sbuf_dbuf);
  size_t siz = sbuf->sbuf_size;
  unsigned maxsiz = ((typedhead_tyBM *) sbuf)->rlen;
  assert (siz > 0 && siz <= maxsiz);
  assert (sbuf->sbuf_curp >= sbuf->sbuf_dbuf
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
      free (backpath);
    }
  FILE *newfil = fopen (filepath, "w");
  if (!newfil)
    FATAL_BM ("fopen %s failed (%m)", filepath);
  if (fwrite (sbuf->sbuf_dbuf, len, 1, newfil) != 1)
    FATAL_BM ("fwrite into %s %u bytes failed (%m)", filepath,
              (unsigned) len);
  if (fclose (newfil))
    FATAL_BM ("fclose %s failed (%m)", filepath);
}                               /* end strbufferwritetofile_BM */
