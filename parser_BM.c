// file parser_BM.c
#include "bismon.h"

struct parser_stBM *
makeparser_of_file_BM (FILE * f)
{
  if (!f)
    return NULL;
  struct parser_stBM *pars =    //
    allocinternalty_BM (tydata_parser_BM, sizeof (struct parser_stBM));
  pars->pars_file = f;
  pars->pars_filemem = NULL;
  pars->pars_filesize = 0;
  unsigned inilinsiz = 256;
  char *linebuf = calloc (1, inilinsiz);
  if (!linebuf)
    FATAL_BM ("linebuf calloc failed %d bytes (%m)", inilinsiz);
  pars->pars_linebuf = linebuf;
  pars->pars_linesiz = inilinsiz;
  pars->pars_linelen = getline (&pars->pars_linebuf, &pars->pars_linesiz, f);
  if (pars->pars_linelen < 0)
    pars->pars_lineno = 0;
  else
    pars->pars_lineno = 1;
  pars->pars_colindex = 0;
  pars->pars_colpos = 0;
  unsigned inimemosiz = 32;
  pars->pars_memolines =
    calloc (inimemosiz, sizeof (struct memolineoffset_stBM));
  if (!pars->pars_memolines)
    FATAL_BM ("memolines calloc failed for size %d (%m)", inimemosiz);
  pars->pars_memolsize = inimemosiz;
  pars->pars_memolcount = 0;
  return pars;
}                               /* end makeparser_BM */

struct parser_stBM *
makeparser_memopen_BM (const char *filemem, long size)
{
  if (!filemem)
    return NULL;
  if (size < 0)
    size = strlen (filemem);
  FILE *fil = fmemopen ((void *) filemem, size, "r");
  if (!fil)
    FATAL_BM ("fmemopen failed (%m)");
  struct parser_stBM *pars = makeparser_of_file_BM (fil);
  pars->pars_filemem = filemem;
  pars->pars_filesize = size;
  return pars;
}                               /* end makeparser_memopen_BM */


void
parsergcmark_BM (struct garbcoll_stBM *gc, struct parser_stBM *pars)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (isparser_BM (pars));
  uint8_t oldmark = ((typedhead_tyBM *) pars)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) pars)->hgc = MARKGC_BM;
  if (pars->pars_cvalue)
    gcmark_BM (gc, pars->pars_cvalue, 0);
}                               /* end parsergcmark_BM */

bool
parsernextline_BM (struct parser_stBM *pars)
{
  if (!isparser_BM (pars))
    return false;
  long curoff = ftell (pars->pars_file);
  pars->pars_linelen =
    getline (&pars->pars_linebuf, &pars->pars_linesiz, pars->pars_file);
  if (pars->pars_linelen > 0)
    {
      pars->pars_colindex = 0;
      pars->pars_colpos = 0;
      pars->pars_linebuf[pars->pars_linelen] = (char) 0;
      if ((pars->pars_lineno + 1) % PARSERMEMOLINERATIO_BM == 0)
        {
          unsigned curmemlcount = pars->pars_memolcount;
          if (curmemlcount + 1 >= pars->pars_memolsize)
            {
              unsigned newmemosize =
                prime_above_BM ((4 * curmemlcount) / 3 + 10);
              struct memolineoffset_stBM *newmemolines =        //
                calloc (newmemosize, sizeof (struct memolineoffset_stBM));
              if (!newmemolines)
                FATAL_BM ("calloc failed for newmemosize=%u", newmemosize);
              memcpy (newmemolines, pars->pars_memolines,       //
                      (pars->pars_memolcount) *
                      sizeof (struct memolineoffset_stBM));
              free (pars->pars_memolines);
              pars->pars_memolines = newmemolines;
              pars->pars_memolsize = newmemosize;
            };
          struct memolineoffset_stBM *curmemoline =
            pars->pars_memolines + curmemlcount;
          curmemoline->memli_off = curoff;
          curmemoline->memli_lineno = pars->pars_lineno;
          curmemoline->memli_linebylen = (unsigned) pars->pars_linelen;
          pars->pars_memolcount = curmemlcount + 1;
        }
      pars->pars_lineno++;
      return true;
    }
  return false;
}                               /* end parsernextline_BM */
