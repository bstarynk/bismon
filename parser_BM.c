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
  pars->pars_filesize = NULL;
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
  FILE *fil = fmemopen (filemem, size, "r");
  if (!fil)
    FATAL_BM ("fmemopen failed (%m)");
  struct parser_stBM *pars = makeparser_of_file_BM (fil);
  pars->pars_filemem = filemem;
  pars->pars_filesize = siz;
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
    gcmark_BM (pars->pars_cvalue);
}                               /* end parsergcmark_BM */
