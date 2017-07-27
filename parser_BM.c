// file parser_BM.c
#include "bismon.h"

#define RUNLEN_BM 16
#define RUNFMT_BM "%16[A-Za-z0-9]"

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
  pars->pars_path = "";
  unsigned inilinsiz = 256;
  char *linebuf = calloc (1, inilinsiz);
  if (!linebuf)
    FATAL_BM ("linebuf calloc failed %d bytes (%m)", inilinsiz);
  pars->pars_linebuf = linebuf;
  pars->pars_linesiz = inilinsiz;
  pars->pars_linebuf[0] = (char) 0;
  pars->pars_linelen = getline (&pars->pars_linebuf, &pars->pars_linesiz, f);
  if (pars->pars_linelen < 0)
    pars->pars_lineno = 0;
  else
    pars->pars_lineno = 1;
  if (!g_utf8_validate (pars->pars_linebuf, pars->pars_linelen, NULL))
    FATAL_BM ("invalid UTF8 line %s:%d", pars->pars_path, pars->pars_lineno);
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
      if (!g_utf8_validate (pars->pars_linebuf, pars->pars_linelen, NULL))
        FATAL_BM ("invalid UTF8 line %s:%d", pars->pars_path,
                  pars->pars_lineno);
      return true;
    }
  return false;
}                               /* end parsernextline_BM */

void
parserseek_BM (struct parser_stBM *pars, unsigned lineno, unsigned colpos)
{
  if (!isparser_BM (pars))
    return;
  if (lineno != pars->pars_lineno)
    {
      unsigned memolcnt = pars->pars_memolcount;
      unsigned lo = 0, hi = memolcnt;
      struct memolineoffset_stBM *memolines = pars->pars_memolines;
      while (lo + 8 < hi)
        {
          unsigned md = (lo + hi) / 2;
          if (memolines[md].memli_lineno < (int) lineno)
            lo = md;
          else
            hi = md;
        }
      long startoff = 0;
      int startlineno = 0;
      int ix = 0;
      for (ix = (int) (hi - 1); ix >= (int) lo; ix--)
        {
          if (memolines[ix].memli_lineno <= (int) lineno)
            {
              startoff = memolines[ix].memli_off;
              startlineno = memolines[ix].memli_lineno;
              break;
            }
        }
      if (fseek (pars->pars_file, SEEK_SET, startoff) < 0)
        FATAL_BM ("fseek startoff=%ld failure", startoff);
      pars->pars_lineno = startlineno;
      do
        {
          pars->pars_linelen =
            getline (&pars->pars_linebuf, &pars->pars_linesiz,
                     pars->pars_file);
          if (pars->pars_linelen < 0)
            FATAL_BM ("getline failed line#%d", pars->pars_lineno);
          if (pars->pars_lineno == lineno)
            break;
          pars->pars_lineno++;
        }
      while (lineno < pars->pars_lineno);
    }
  else
    {                           //lineno == pars->pars_lineno
      pars->pars_colindex = 0;
      pars->pars_colpos = 0;
    }
  if (!g_utf8_validate (pars->pars_linebuf, pars->pars_linelen, NULL))
    FATAL_BM ("invalid UTF8 line %s:%d", pars->pars_path, pars->pars_lineno);
  const char *curlin = pars->pars_linebuf;
  while (pars->pars_colpos < colpos)
    {
      if (pars->pars_colindex >= pars->pars_linelen)
        break;
      const char *pc = curlin + pars->pars_colindex;
      if (!*pc)
        break;
      const char *nextpc = g_utf8_next_char (pc);
      pars->pars_colindex = nextpc - curlin;
      pars->pars_colpos++;
    }
}                               /* end of parserseek_BM */

void
parsererrorprintf_BM (struct parser_stBM *pars, unsigned line, unsigned col,
                      const char *fmt, ...)
{
  if (!isparser_BM (pars))
    FATAL_BM ("non parser argument to parsererrorprintf_BM");
  va_list args;
  char *buf = NULL;
  va_start (args, fmt);
  vasprintf (&buf, fmt, args);
  if (!buf)
    FATAL_BM ("vasprintf failed");
  va_end (args);
  const struct parserops_stBM *parsops = pars->pars_ops;
  if (parsops)
    {
      assert (parsops->parsop_magic == PARSOPMAGIC_BM);
      if (parsops->parsop_error_rout)
        parsops->parsop_error_rout (pars, line, col, buf);
    };
  FATAL_BM ("parser error %s:%d:%d : %s", pars->pars_path, line, col, buf);
}                               /* end parsererrorprintf_BM */

void
parserskipspaces_BM (struct parser_stBM *pars)
{
  if (!isparser_BM (pars))
    return;
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (!parsops || parsops->parsop_magic == PARSOPMAGIC_BM);
  for (;;)
    {
      const char *restlines = parserrestline_BM (pars);
      if (!restlines)
        break;
      if (isspace (restlines[0]))
        {
          pars->pars_colpos++, pars->pars_colindex++;
          continue;
        }
      if (restlines[0] == '/' && restlines[1] == '/')
        {
          if (parsops->parsop_decorate_comment_sign_rout)
            parsops->parsop_decorate_comment_sign_rout  //
              (pars, pars->pars_colpos, 2);
          if (parsops->parsop_decorate_comment_inside_rout)
            parsops->parsop_decorate_comment_inside_rout        //
              (pars, pars->pars_colpos + 2,
               g_utf8_strlen (restlines + 2, -1));
          if (!parsernextline_BM (pars))
            return;
          continue;
        }
      else if (restlines[0] == '|')
        {
          if (parsops->parsop_decorate_comment_sign_rout)
            parsops->parsop_decorate_comment_sign_rout  //
              (pars, pars->pars_colpos, 1);
          unsigned curlineno = parserlineno_BM (pars);
          unsigned curcol = parsercolpos_BM (pars);
          for (;;)
            {
              if (!parseradvanceutf8_BM (pars, 1) || parsereol_BM (pars)
                  || parserendoffile_BM (pars))
                {
                  char begcomment[40] = { };
                  const gchar *endcomm = NULL;
                  strncpy (begcomment, restlines, sizeof (begcomment) - 1);
                  g_utf8_validate (begcomment, -1, &endcomm);
                  *(char *) endcomm = 0;
                  parsererrorprintf_BM (pars, curlineno, curcol,
                                        "unterminated comment %s",
                                        begcomment);
                }
              if (parserunichar_BM (pars) == (gunichar) '|')
                {
                  if (parsops->parsop_decorate_comment_sign_rout)
                    parsops->parsop_decorate_comment_sign_rout  //
                      (pars, pars->pars_colpos, 1);
                  if (parsops->parsop_decorate_comment_inside_rout)
                    parsops->parsop_decorate_comment_inside_rout        //
                      (pars, curcol + 1, pars->pars_colpos - curcol);
                  parseradvanceutf8_BM (pars, 1);
                  break;
                }
            }
        }
      else
        return;
    }
}                               /* end parserskipspaces_BM */



void
gctokenmark_BM (struct garbcoll_stBM *gc, struct parstoken_stBM *tok)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (tok != NULL);
  switch (tok->tok_kind)
    {
    case plex__NONE:
      FATAL_BM ("empty token @%p", (void *) tok);
    case plex_LLONG:
    case plex_DOUBLE:
    case plex_DELIM:
    case plex_ID:
      break;
    case plex_CNAME:
      gcmark_BM (gc, (void *) tok->tok_cname, 0);
      break;
    case plex_WORD:
      gcmark_BM (gc, (void *) tok->tok_word, 0);
      break;
    case plex_STRING:
      gcmark_BM (gc, (void *) tok->tok_string, 0);
      break;
    case plex_NAMEDOBJ:
      gcobjmark_BM (gc, (void *) tok->tok_namedobj);
      break;
    };
}                               /* end gctokenmark_BM */


// return the number of Unicode chars in the plain cord
static unsigned
parse_plain_cord_BM (struct parser_stBM *pars, FILE * memfil)
{
  assert (isparser_BM (pars));
  assert (memfil != NULL);
  const char *restlin = parserrestline_BM (pars);
  assert (restlin && *restlin == '"');
  const char *pc = restlin + 1;
  unsigned nbc = 0;
  while (*pc)
    {
      if (*pc == '"')
        break;
      else if (*pc == '\n')
        break;
      else if (*pc == '\\')
        {
          char nc = pc[1];
          int pos = -1;
          int b = 0;
          switch (nc)
            {
            case '\'':
            case '\"':
            case '\\':
              fputc (nc, memfil);
              nbc++;
              pc += 2;
              continue;
            case 'a':
              fputc ('\a', memfil);
              break;
            case 'b':
              fputc ('\b', memfil);
              break;
            case 'f':
              fputc ('\f', memfil);
              break;
            case 'n':
              fputc ('\n', memfil);
              break;
            case 'r':
              fputc ('\r', memfil);
              break;
            case 't':
              fputc ('\t', memfil);
              break;
            case 'v':
              fputc ('\v', memfil);
              break;
            case 'e':
              fputc ('\033' /* ESCAPE */ , memfil);;
              break;
            case 'x':
              if (sscanf (pc + 1, "%02x%n", &b, &pos) > 0 && pos == 2
                  && b > 0 && b <= 127)
                {
                  fputc (b, memfil);
                  pc += 3;
                  nbc++;
                  continue;
                }
              else
                parsererrorprintf_BM (pars, pars->pars_lineno,
                                      pars->pars_colpos, "bad hex escape %s",
                                      pc);
            case 'o':
              if (sscanf (pc + 1, "%03o%n", &b, &pos) > 0 && pos == 3
                  && b > 0 && b <= 127)
                {
                  fputc (b, memfil);
                  pc += 3;
                  nbc++;
                  continue;
                }
              else
                parsererrorprintf_BM (pars, pars->pars_lineno,
                                      pars->pars_colpos,
                                      "bad octal escape %s", pc);
            case 'u':
              if (sscanf (pc + 1, "%04x%n", &b, &pos) > 0 && pos == 4
                  && b > 0)
                {
                  char ebuf[8];
                  memset (ebuf, 0, sizeof (ebuf));
                  g_unichar_to_utf8 ((gunichar) b, ebuf);
                  fputs (ebuf, memfil);
                  nbc++;
                  pc += 5;
                  continue;
                }
              else
                parsererrorprintf_BM (pars, pars->pars_lineno,
                                      pars->pars_colpos,
                                      "bad unicode4 escape %s", pc);
            case 'U':
              if (sscanf (pc + 1, "%08x%n", &b, &pos) > 0 && pos == 8
                  && b > 0)
                {
                  char ebuf[8];
                  memset (ebuf, 0, sizeof (ebuf));
                  g_unichar_to_utf8 ((gunichar) b, ebuf);
                  fputs (ebuf, memfil);
                  nbc++;
                  pc += 9;
                  continue;
                }
              else
                parsererrorprintf_BM (pars, pars->pars_lineno,
                                      pars->pars_colpos,
                                      "bad unicode8 escape %s", pc);
            case '\0':
              parsererrorprintf_BM (pars, pars->pars_lineno,
                                    pars->pars_colpos, "bad null escape %s",
                                    pc);

            default:
              fputc (nc, memfil);
              nbc++;
              pc += 2;
              continue;
            }
        }
      else if (*pc >= ' ' && *pc < 127)
        {                       // ASCII char
          fputc (*pc, memfil);
          nbc++;
          pc++;
          continue;
        }
      else
        {                       // probably some multibyte UTF8 char
          const char *npc = g_utf8_next_char (pc);
          fwrite (pc, npc - pc, 1, memfil);
          nbc++;
          pc = npc;
          continue;
        }
    };
  if (*pc == '"')
    pc++;
  else
    parsererrorprintf_BM (pars, pars->pars_lineno, pars->pars_colpos,
                          "bad plain cord ending %s", pc);
  pars->pars_colpos += nbc + 2;
  pars->pars_colindex += pc - restlin;
  return nbc;
}                               /* end parse_plain_cord_BM */



// return the number of Unicode chars in the raw cord
static unsigned
parse_raw_cord_BM (struct parser_stBM *pars, const char *run, FILE * memfil)
{
  assert (isparser_BM (pars));
  assert (memfil != NULL);
  char endrunbuf[RUNLEN_BM + 8] = "";
  unsigned runlen = strlen (run);
  assert (runlen <= RUNLEN_BM);
  unsigned nbc = 0;
  const char *restlin = parserrestline_BM (pars);
  assert (restlin && restlin[0] == '/' && restlin[1] == '"'
          && !strncmp (restlin + 2, run, runlen)
          && restlin[runlen + 3] == '(');
  const char *curstart = restlin + runlen + 4;
  snprintf (endrunbuf, sizeof (endrunbuf), ")%s\"/", run);
  for (;;)
    {
      char *ends = strstr (curstart, endrunbuf);
      if (ends)
        {
          fwrite (curstart, ends - curstart, 1, memfil);
          unsigned plen = g_utf8_strlen (curstart, ends - curstart);
          nbc += plen;
          pars->pars_colindex += (ends - curstart) + strlen (endrunbuf);
          pars->pars_colpos += plen + strlen (endrunbuf);
          break;
        }
      else
        {
          fputs (curstart, memfil);
          unsigned plen = g_utf8_strlen (curstart, -1);
          pars->pars_colindex += strlen (curstart);
          pars->pars_colpos += plen;
          if (!parsernextline_BM (pars))
            parsererrorprintf_BM (pars, pars->pars_lineno, pars->pars_colpos,
                                  "unterminated raw cord");
          restlin = parserrestline_BM (pars);
          curstart = restlin;
          assert (restlin != NULL);
          continue;
        }
    };
  return nbc;
}                               /* end parse_raw_cord_BM */

static const stringval_tyBM *
parse_cords_BM (struct parser_stBM *pars)
{
  if (!isparser_BM ((const value_tyBM) pars))
    return NULL;
  parserskipspaces_BM (pars);
  const char *restlin = parserrestline_BM (pars);
  if (!restlin)
    return NULL;
  if (restlin[0] != '"' || (restlin[0] != '/' && restlin[1] != '"'))
    return NULL;
  char runbuf[RUNLEN_BM + 8] = "";
  int runlen = -1;
  size_t bufsiz = 256;
  char *cbuf = malloc (bufsiz);
  if (!cbuf)
    FATAL_BM ("malloc for cord of %ld failed (%m)", (long) bufsiz);
  memset (cbuf, 0, bufsiz);
  FILE *filmem = open_memstream (&cbuf, &bufsiz);
  if (!filmem)
    FATAL_BM ("open_memstream failed (%m)");
  bool againcord = false;
  unsigned long cumulchars = 0;
  do
    {
      againcord = false;
      restlin = parserrestline_BM (pars);
      if (!restlin)
        break;
      if (restlin[0] == '"')
        cumulchars += parse_plain_cord_BM (pars, filmem);
      else if (restlin[0] == '/' && restlin[1] == '"'
               && ((runlen = -1), (memset (runbuf, 0, sizeof (runbuf))),
                   sscanf (restlin, "/\"" RUNFMT_BM "(%n", runbuf,
                           &runlen) > 0) && runlen > 0)
        cumulchars += parse_raw_cord_BM (pars, runbuf, filmam);
      else
        {
          fclose (filmem);
          free (cbuf);
          parsererrorprintf_BM (pars, pars->pars_lineno, pars->pars_colpos,
                                "bad cord %s", restlin);
        }

      restlin = parserrestline_BM (pars);
      if (!restlin)
        break;
      if (restlin[0] == '&')
        {
          pars->pars_colpos++;
          pars->pars_colindex++;
          againcord = true;
        }
      else if (restlin[0] == '+')
        {
          pars->pars_colpos++;
          pars->pars_colindex++;
          fputc ('\n', filmem);
          cumulchars++;
          againcord = true;
        }
      else
        break;
      parserskipspaces_BM (pars);
      if (cumulchars >= MAXSIZE_BM)
        {
          fclose (filmem);
          free (cbuf);
          parsererrorprintf_BM (pars, pars->pars_lineno, pars->pars_colpos,
                                "too long string (%lu)", cumulchars);
        }
    }
  while (againcord);
  fputc ((char) 0, filmem);
  fflush (filmem);
  const stringval_tyBM *str = makestring_BM (cbuf);
  fclose (filmem);
  free (cbuf);
  return str;
}                               /* end parse_cords_BM */


parstoken_tyBM
parsertokenget_BM (struct parser_stBM * pars)
{
  if (!isparser_BM ((const value_tyBM) pars))
    return (parstoken_tyBM)
    {
      .tok_kind = plex__NONE,.tok_ptrs =
      {
      NULL, NULL}
    };
  const struct parserops_stBM *parsop = pars->pars_ops;
  assert (!parsop || parsop->parsop_magic == PARSOPMAGIC_BM);
  parserskipspaces_BM (pars);
  const char *restlin = parserrestline_BM (pars);
  if (!restlin)
    return (parstoken_tyBM)
    {
      .tok_kind = plex__NONE,.tok_ptrs =
      {
      NULL, NULL}
    };
  if (isdigit (restlin[0])
      || ((restlin[0] == '+' || restlin[0] == '-') && isdigit (restlin[1])))
    {
      char *endint = NULL;
      char *endflo = NULL;
      long long ll = strtoll (restlin, &endint, 0);
      if (strchr (restlin, '.'))
        {
          double x = strtod (restlin, &endflo);
          if (endflo > endint)
            {
              unsigned coldbl = g_utf8_strlen (restlin, endflo - restlin);
              if (parsop && parsop->parsop_decorate_number_rout)
                parsop->parsop_decorate_number_rout (pars, pars->pars_colpos,
                                                     coldbl);
              pars->pars_colindex += endflo - restlin;
              pars->pars_colpos += coldbl;
              return (parstoken_tyBM)
              {
              .tok_kind = plex_DOUBLE,.tok_dbl = x};
            }
        }
      if (endint > restlin)
        {
          unsigned colint = g_utf8_strlen (restlin, endint - restlin);
          if (parsop && parsop->parsop_decorate_number_rout)
            parsop->parsop_decorate_number_rout (pars, pars->pars_colpos,
                                                 colint);
          pars->pars_colindex += endint - restlin;
          pars->pars_colpos += colint;
          return (parstoken_tyBM)
          {
          .tok_kind = plex_LLONG,.tok_llong = ll};
        }
    }

  // parse ids
  else if (restlin[0] == '_' && isdigit (restlin[1]))
    {
      const char *endid = NULL;
      rawid_tyBM id = parse_rawid_BM (restlin, &endid);
      assert (endid == restlin + IDLEN_BM);
      if (id.id_hi != 0 && endid != NULL && endid > restlin)
        {
          if (parsop && parsop->parsop_decorate_id_rout)
            parsop->parsop_decorate_id_rout (pars, pars->pars_colpos,
                                             IDLEN_BM);
          pars->pars_colindex += IDLEN_BM;
          pars->pars_colpos += IDLEN_BM;
          return (parstoken_tyBM)
          {
          .tok_kind = plex_ID,.tok_id = id};
        }
      else
        parsererrorprintf_BM (pars, pars->pars_lineno, pars->pars_colpos,
                              "bad ident %s", restlin);
    }

  // parse nil id
  else if (restlin[0] == '_' && restlin[1] == '_'
           && !isalnum (restlin[2]) && restlin[2] != '_')
    {
      if (parsop && parsop->parsop_decorate_id_rout)
        parsop->parsop_decorate_id_rout (pars, pars->pars_colpos, 2);
      pars->pars_colindex += 2;
      pars->pars_colpos += 2;
      return (parstoken_tyBM)
      {
        .tok_kind = plex_ID,.tok_id =
        {
        0, 0}
      };
    }

  // parse names, either as named objects or as strings
  else if (isalpha (restlin[0]))
    {
      const char *endnam = restlin;
      while (isalnum (*endnam) || *endnam == '_')
        endnam++;
      unsigned namlen = endnam - restlin;
      char tinynambuf[TINYSIZE_BM] = "";
      char *nambuf =            //
        (namlen < TINYSIZE_BM)  //
        ? tinynambuf            //
        : malloc (prime_above_BM ((namlen) / 4 + 2) * 4);
      if (!namlen)
        FATAL_BM ("failed to malloc name for %d bytes", namlen);
      memcpy (nambuf, restlin, namlen);
      memcpy (tinynambuf, restlin,
              (namlen < TINYSIZE_BM) ? namlen : TINYSIZE_BM);
      nambuf[namlen] = (char) 0;
      if (!validname_BM (nambuf))
        {
          if (nambuf != tinynambuf)     // to avoid memory leaks
            free (nambuf);
          parsererrorprintf_BM (pars, pars->pars_lineno, pars->pars_colpos,
                                "bad ident %s%s", tinynambuf,
                                (namlen > TINYSIZE_BM) ? "..." : "");
        }
      const objectval_tyBM *namedobj =  //
        findnamedobj_BM (nambuf);
      if (namedobj)
        {
          if (nambuf != tinynambuf)
            free (nambuf);
          if (parsop && parsop->parsop_decorate_known_name_rout)
            parsop->parsop_decorate_known_name_rout     //
              (pars, pars->pars_colpos, namlen);
          pars->pars_colindex += namlen;
          pars->pars_colpos += namlen;
          return (parstoken_tyBM)
          {
          .tok_kind = plex_NAMEDOBJ,.tok_namedobj =
              (objectval_tyBM *) namedobj};
        }
      else
        {                       // new name
          const stringval_tyBM *newnam = makestring_BM (nambuf);
          if (nambuf != tinynambuf)
            free (nambuf);
          if (parsop && parsop->parsop_decorate_new_name_rout)
            parsop->parsop_decorate_new_name_rout       //
              (pars, pars->pars_colpos, namlen);
          pars->pars_colindex += namlen;
          pars->pars_colpos += namlen;
          return (parstoken_tyBM)
          {
          .tok_kind = plex_CNAME,.tok_cname = newnam};
        }
    }

  // special case for +NAN +INF -INF, in uppercases
  else if (((restlin[0] == '+') || (restlin[0] == '-'))
           && (!strncmp (restlin, "+NAN", 4)
               || !strncmp (restlin, "+INF", 4)
               || !strncmp (restlin, "-INF", 4)) && !isalnum (restlin[4]))
    {
      char specbuf[8] = { };
      memcpy (specbuf, restlin, 4);
      double x = strtod (specbuf, NULL);
      if (parsop && parsop->parsop_decorate_number_rout)
        parsop->parsop_decorate_number_rout (pars, pars->pars_colpos, 4);
      pars->pars_colindex += 4;
      pars->pars_colpos += 4;
      return (parstoken_tyBM)
      {
      .tok_kind = plex_DOUBLE,.tok_dbl = x};
    }

  else if (restlin[0] == '"')
    {
      const stringval_tyBM *str = parse_cords_BM (pars);
      return (parstoken_tyBM)
      {
      .tok_kind = plex_STRING,.tok_string = str};
    }

  else if (restlin[0] == '/' && restlin[1] == '"')
    {
      const stringval_tyBM *str = parse_cords_BM (pars);
      return (parstoken_tyBM)
      {
      .tok_kind = plex_STRING,.tok_string = str};
    }
  char delimstr[16];
  memset (delimstr, 0, sizeof (delimstr));
  enum lexdelim_enBM curdelim = delim__NONE;
#define HAS_DELIM_BM(Str,Nam) do {		\
    if (restlin[0] == (Str)[0]			\
	&& !strncmp(restlin, Str, strlen(Str))	\
	&& strlen(delimstr) < strlen(Str)) {	\
    curdelim = delim__##Nam;			\
    strcpy(delimstr, Str);			\
  }  while(0);
#include "_bm_delim.h"
  //
  if (curdelim == delim__NONE)
    parsererrorprintf_BM (pars, pars->pars_lineno, pars->pars_colpos,
                          "unexpected token %s", restlin);
  pars->pars_colindex += strlen (delimstr);
  pars->pars_colpos += g_utf8_strlen (delimstr, -1);
  return (parstoken_tyBM)
  {
  .tok_kind = plex_DELIM,.tok_delim = curdelim};
}                               /* end parsertokenget_BM */
