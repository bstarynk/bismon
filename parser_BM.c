// file parser_BM.c
#include "bismon.h"

#define RUNLEN_BM 16
#define RUNFMT_BM "%16[A-Za-z0-9]"

static const char *const lexkindnamearr_BM[] = {
  [plex__NONE] = "_NONE",
  [plex_LLONG] = "LLONG",
  [plex_DOUBLE] = "DOUBLE",
  [plex_DELIM] = "DELIM",
  [plex_ID] = "ID",
  [plex_CNAME] = "CNAME",
  [plex_WORD] = "WORD",
  [plex_STRING] = "STRING",
};

const char *
lexkindname_BM (enum parslexkind_enBM k)
{
  if ((unsigned) k <
      (unsigned) (sizeof (lexkindnamearr_BM) / sizeof (lexkindnamearr_BM[0])))
    return lexkindnamearr_BM[k];
  return "?";
}                               /* end of lexkindname_BM */

static const char *const delimnamearr_BM[] = {
#define HAS_DELIM_BM(Str,Delimname) [delim_##Delimname] = #Str,
#include "_bm_delim.h"
};

const char *
delimstr_BM (enum lexdelim_enBM d)
{
  if ((unsigned) d <
      (unsigned) (sizeof (delimnamearr_BM) / sizeof (delimnamearr_BM[0])))
    return delimnamearr_BM[d];
  return "?";
}                               /* end of delimstr_BM */


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
    {
      pars->pars_lineno = 0;
      pars->pars_curbyte = NULL;
    }
  else
    pars->pars_lineno = 1;
  if (!g_utf8_validate (pars->pars_linebuf, pars->pars_linelen, NULL))
    FATAL_BM ("invalid UTF8 line %s:%d", pars->pars_path, pars->pars_lineno);
  pars->pars_curbyte = pars->pars_linebuf;
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
      pars->pars_curbyte = pars->pars_linebuf;
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
  else if (pars->pars_linelen < 0)
    {
      pars->pars_curbyte = NULL;
      pars->pars_colpos = 0;
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
      pars->pars_curbyte = pars->pars_linebuf;
      pars->pars_colpos = 0;
    }
  if (!g_utf8_validate (pars->pars_linebuf, pars->pars_linelen, NULL))
    FATAL_BM ("invalid UTF8 line %s:%d", pars->pars_path, pars->pars_lineno);
  while (pars->pars_colpos < colpos)
    {
      if (!pars->pars_curbyte
          || *pars->pars_curbyte == (char) 0
          || pars->pars_curbyte >= pars->pars_linebuf + pars->pars_linelen)
        break;
      const char *pc = pars->pars_curbyte;
      if (!*pc)
        break;
      const char *nextpc = g_utf8_next_char (pc);
      pars->pars_curbyte = nextpc;
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
      if (parsops && parsops->parsop_error_rout)
        parsops->parsop_error_rout (pars, line, col, buf);
    };
  FATAL_BM ("%s:%d:%d: PARSER ERROR : %s", pars->pars_path, line, col, buf);
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
          pars->pars_colpos++, pars->pars_curbyte++;
          continue;
        }
      if (restlines[0] == (char) 0)
        {
          if (!parsernextline_BM (pars))
            return;
          continue;
        }
      if (restlines[0] == '/' && restlines[1] == '/')
        {
          if (parsops && parsops->parsop_decorate_comment_sign_rout)
            parsops->parsop_decorate_comment_sign_rout  //
              (pars, pars->pars_colpos, 2);
          if (parsops && parsops->parsop_decorate_comment_inside_rout)
            parsops->parsop_decorate_comment_inside_rout        //
              (pars, pars->pars_colpos + 2,
               g_utf8_strlen (restlines + 2, -1));
          if (!parsernextline_BM (pars))
            return;
          continue;
        }
      else if (restlines[0] == '|')
        {
          if (parsops && parsops->parsop_decorate_comment_sign_rout)
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
                  if (parsops && parsops->parsop_decorate_comment_sign_rout)
                    parsops->parsop_decorate_comment_sign_rout  //
                      (pars, pars->pars_colpos, 1);
                  if (parsops && parsops->parsop_decorate_comment_inside_rout)
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
  const struct parserops_stBM *parsop = pars->pars_ops;
  const char *restlin = parserrestline_BM (pars);
  assert (restlin && *restlin == '"');
  assert (!parsop || parsop->parsop_magic == PARSOPMAGIC_BM);
  if (parsop && parsop->parsop_decorate_string_sign_rout)
    parsop->parsop_decorate_string_sign_rout (pars, pars->pars_colpos, 1);
  const char *pc = restlin + 1;
  const char *startplain = restlin + 1;
  unsigned nbc = 0;
  while (*pc)
    {
      if (*pc == '"')
        break;
      else if (*pc == '\n')
        break;
      else if (*pc == '\\')
        {
          if (parsop && parsop->parsop_decorate_string_inside_rout
              && startplain < pc)
            {
              parsop->parsop_decorate_string_inside_rout        //
                (pars,
                 pars->pars_colpos + g_utf8_strlen (restlin, pc - restlin),
                 g_utf8_strlen (startplain, pc - startplain));
            }
          const char *oldpc = pc;
          char nc = pc[1];
          int pos = -1;
          int b = 0;
          switch (nc)
            {
            case '\'':
            case '\"':
            case '\\':
              b = nc;
              fputc (nc, memfil);
              nbc++;
              pc += 2;
              startplain = pc;
              continue;
            case 'a':
              b = '\a';
              fputc (b, memfil);
              nbc++;
              pc += 2;
              startplain = pc;
              break;
            case 'b':
              b = '\b';
              fputc (b, memfil);
              nbc++;
              pc += 2;
              startplain = pc;
              break;
            case 'f':
              b = '\f';
              fputc (b, memfil);
              nbc++;
              pc += 2;
              startplain = pc;
              break;
            case 'n':
              b = '\n';
              fputc (b, memfil);
              nbc++;
              pc += 2;
              startplain = pc;
              break;
            case 'r':
              b = '\r';
              fputc (b, memfil);
              nbc++;
              pc += 2;
              startplain = pc;
              break;
            case 't':
              b = '\t';
              fputc (b, memfil);
              nbc++;
              pc += 2;
              startplain = pc;
              break;
            case 'v':
              b = '\v';
              fputc (b, memfil);
              nbc++;
              pc += 2;
              startplain = pc;
              break;
            case 'e':
              b = '\033' /*ESCAPE*/;
              fputc (b, memfil);;
              break;
            case 'x':
              if (sscanf (pc + 1, "%02x%n", &b, &pos) > 0 && pos == 2
                  && b > 0 && b <= 127)
                {
                  fputc (b, memfil);
                  pc += 3;
                  nbc++;
                  startplain = pc;
                  break;
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
                  startplain = pc;
                  break;
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
                  startplain = pc;
                  break;
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
                  startplain = pc;
                  break;
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
              b = nc;
              fputc (b, memfil);
              nbc++;
              pc += 2;
              startplain = pc;
              break;
            }                   /* end switch nc */
          if (b && parsop && parsop->parsop_decorate_string_sign_rout)
            parsop->parsop_decorate_string_sign_rout    //
              (pars,
               pars->pars_colpos + g_utf8_strlen (restlin, oldpc - restlin),
               g_utf8_strlen (oldpc, pc - oldpc));
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
    {
      if (parsop && parsop->parsop_decorate_string_inside_rout
          && startplain < pc)
        {
          parsop->parsop_decorate_string_inside_rout    //
            (pars,
             pars->pars_colpos + g_utf8_strlen (restlin, pc - restlin),
             g_utf8_strlen (startplain, pc - startplain));
        }
      if (parsop && parsop->parsop_decorate_string_sign_rout)
        parsop->parsop_decorate_string_sign_rout
          (pars,
           pars->pars_colpos + g_utf8_strlen (restlin, pc - restlin), 1);
      pc++;
    }
  else
    parsererrorprintf_BM (pars, pars->pars_lineno, pars->pars_colpos,
                          "bad plain cord ending %s", pc);
  pars->pars_colpos += g_utf8_strlen (restlin, pc - restlin);
  pars->pars_curbyte = pc;
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
          pars->pars_curbyte += (ends - curstart) + strlen (endrunbuf);
          pars->pars_colpos += plen + strlen (endrunbuf);
          break;
        }
      else
        {
          fputs (curstart, memfil);
          unsigned plen = g_utf8_strlen (curstart, -1);
          pars->pars_curbyte += strlen (curstart);
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
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (!parsops || parsops->parsop_magic == PARSOPMAGIC_BM);
  bool nobuild = parsops && parsops->parsop_nobuild;
  parserskipspaces_BM (pars);
  const char *restlin = parserrestline_BM (pars);
  if (!restlin)
    return NULL;
  if (restlin[0] != '"' && (restlin[0] != '/' && restlin[1] != '"'))
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
        cumulchars += parse_raw_cord_BM (pars, runbuf, filmem);
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
          pars->pars_curbyte++;
          againcord = true;
        }
      else if (restlin[0] == '+')
        {
          pars->pars_colpos++;
          pars->pars_curbyte++;
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
  const stringval_tyBM *str = nobuild ? NULL : (makestring_BM (cbuf));
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
  bool nobuild = parsop && parsop->parsop_nobuild;
  const char *restlin = NULL;
again:
  parserskipspaces_BM (pars);
  restlin = parserrestline_BM (pars);
  if (restlin && restlin[0] == (char) 0)
    {
      if (parserendoffile_BM (pars))
        return (parstoken_tyBM)
        {
          .tok_kind = plex__NONE,.tok_ptrs =
          {
          NULL, NULL}
        };
      goto again;
    }
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
              pars->pars_curbyte = endflo;
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
          pars->pars_curbyte = endint;
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
          pars->pars_curbyte += IDLEN_BM;
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
      pars->pars_curbyte += 2;
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
          pars->pars_curbyte += namlen;
          pars->pars_colpos += namlen;
          return (parstoken_tyBM)
          {
          .tok_kind = plex_NAMEDOBJ,.tok_namedobj =
              (objectval_tyBM *) namedobj};
        }
      else
        {                       // new name
          const stringval_tyBM *newnam =        //
            nobuild ? NULL : makestring_BM (nambuf);
          if (nambuf != tinynambuf)
            free (nambuf);
          if (parsop && parsop->parsop_decorate_new_name_rout)
            parsop->parsop_decorate_new_name_rout       //
              (pars, pars->pars_colpos, namlen);
          pars->pars_curbyte += namlen;
          pars->pars_colpos += namlen;
          return (parstoken_tyBM)
          {
          .tok_kind = plex_CNAME,.tok_cname = newnam};
        }
    }

  // special case for +NAN +INF -INF, in uppercases
  else if (((restlin[0] == '+') || (restlin[0] == '-'))
           && (restlin[1] == 'N' || restlin[1] == 'I')
           && (!strncmp (restlin, "+NAN", 4)
               || !strncmp (restlin, "+INF", 4)
               || !strncmp (restlin, "-INF", 4)) && !isalnum (restlin[4]))
    {
      char specbuf[8] = { };
      memcpy (specbuf, restlin, 4);
      double x = strtod (specbuf, NULL);
      if (parsop && parsop->parsop_decorate_number_rout)
        parsop->parsop_decorate_number_rout (pars, pars->pars_colpos, 4);
      pars->pars_curbyte += 4;
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
    curdelim = delim_##Nam;			\
    strcpy(delimstr, Str);			\
    }}  while(0);
  //
#include "_bm_delim.h"
  //
  if (curdelim == delim__NONE)
    parsererrorprintf_BM (pars, pars->pars_lineno, pars->pars_colpos,
                          "unexpected token %s", restlin);
  pars->pars_curbyte += strlen (delimstr);
  pars->pars_colpos += g_utf8_strlen (delimstr, -1);
  return (parstoken_tyBM)
  {
  .tok_kind = plex_DELIM,.tok_delim = curdelim};
}                               /* end parsertokenget_BM */


objectval_tyBM *
parsergetobject_BM (struct parser_stBM * pars,
                    struct stackframe_stBM * prevstkf, int depth,
                    bool * pgotobj)
{
  if (!isparser_BM ((const value_tyBM) pars))
    FATAL_BM ("bad parser");
  if (!pgotobj)
    FATAL_BM ("missing pgotobj");
  LOCALFRAME_BM (prevstkf, NULL, objectval_tyBM * resobj);
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (!parsops || parsops->parsop_magic == PARSOPMAGIC_BM);
  bool nobuild = parsops && parsops->parsop_nobuild;
  parserskipspaces_BM (pars);
  unsigned lineno = parserlineno_BM (pars);
  unsigned colpos = parsercolpos_BM (pars);
  if (depth > MAXDEPTHPARSE_BM)
    parsererrorprintf_BM (pars, lineno, colpos, //
                          "too deep (%d) object", depth);
  parstoken_tyBM tok = parsertokenget_BM (pars);
  if (tok.tok_kind == plex__NONE)
    goto failure;
  else if (tok.tok_kind == plex_NAMEDOBJ)
    {
      assert (tok.tok_namedobj != NULL);
      *pgotobj = true;
      return tok.tok_namedobj;
    }
  else if (tok.tok_kind == plex_ID)
    {
      if (tok.tok_id.id_hi == 0 && tok.tok_id.id_lo == 0)
        {
          *pgotobj = true;
          return NULL;
        };
      objectval_tyBM *obid = _.resobj   //
        = nobuild ? NULL : (findobjofid_BM (tok.tok_id));
      if (!obid && !nobuild)
        {
          char idbuf[32];
          memset (idbuf, 0, sizeof (idbuf));
          idtocbuf32_BM (tok.tok_id, idbuf);
          parsererrorprintf_BM (pars, lineno, colpos,   //
                                "unknown id %s", idbuf);
        };
      *pgotobj = true;
      return obid;
    }
  // perhaps should be able to compute an object
failure:
  parserseek_BM (pars, lineno, colpos);
  *pgotobj = false;
  return NULL;
}                               /* end parsergetobject_BM */



////////////////
value_tyBM
parsergetvalue_BM (struct parser_stBM * pars,
                   struct stackframe_stBM * prevstkf, int depth,
                   bool * pgotval)
{
  if (!isparser_BM ((const value_tyBM) pars))
    FATAL_BM ("bad parser");
  if (!pgotval)
    FATAL_BM ("missing pgotval");
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (!parsops || parsops->parsop_magic == PARSOPMAGIC_BM);
  bool nobuild = parsops && parsops->parsop_nobuild;
  LOCALFRAME_BM                 //
    (prevstkf, NULL,            //
     value_tyBM resval;
     objectval_tyBM * connobj;
     union
     {
     objectval_tyBM * elemobj; objectval_tyBM * compobj; value_tyBM sonval;
     };
     struct datavectval_stBM *contdvec);
  parserskipspaces_BM (pars);
  unsigned lineno = parserlineno_BM (pars);
  unsigned colpos = parsercolpos_BM (pars);
  if (depth > MAXDEPTHPARSE_BM)
    parsererrorprintf_BM (pars, lineno, colpos, //
                          "too deep (%d) value", depth);
  parstoken_tyBM tok = parsertokenget_BM (pars);
  if (tok.tok_kind == plex__NONE)
    goto failure;
  //
  // parse numbers
  else if (tok.tok_kind == plex_LLONG)
    {
      *pgotval = true;
      return taggedint_BM (tok.tok_llong);
    }
  //
  // parse strings
  else if (tok.tok_kind == plex_STRING)
    {
      *pgotval = true;
      return nobuild ? NULL : (value_tyBM) tok.tok_string;
    }
  // parse objects given by id
  else if (tok.tok_kind == plex_ID)
    {
      if (tok.tok_id.id_hi == 0 && tok.tok_id.id_lo == 0)
        {
          *pgotval = true;
          return NULL;
        };
      objectval_tyBM *obid = _.compobj  //
        = nobuild ? NULL : (findobjofid_BM (tok.tok_id));
      if (!obid && !nobuild)
        {
          char idbuf[32];
          memset (idbuf, 0, sizeof (idbuf));
          idtocbuf32_BM (tok.tok_id, idbuf);
          parsererrorprintf_BM (pars, lineno, colpos,   //
                                "unknown id %s", idbuf);
        };
      *pgotval = true;
      return obid;
    }
  // parse objects given by name
  else if (tok.tok_kind == plex_NAMEDOBJ)
    {
      parserseek_BM (pars, lineno, colpos);
      bool gotobj = false;
      _.compobj =
        parsergetobject_BM (pars, (struct stackframe_stBM *) &_, depth + 1,
                            &gotobj);
      *pgotval = gotobj;
      return nobuild ? NULL : ((value_tyBM) _.compobj);
    }
  // parse code chunks
  else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_hashleftbrace)
    {
      bool gotchunk = false;
      _.compobj =
        parsergetchunk_BM (pars, (struct stackframe_stBM *) &_, depth + 1,
                           &gotchunk);
      *pgotval = gotchunk;
      return nobuild ? NULL : ((value_tyBM) _.compobj);
    }
  //
  // parse tuples
  else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_leftbracket)
    {
      // a tuple : [ obj1 .... objn ]
      bool gotcompobj = false;
      _.contdvec = nobuild ? NULL : datavect_grow_BM (NULL, 5);
      while ((gotcompobj = false),      //
             (_.compobj =       //
              parsergetobject_BM        //
              (pars,            //
               (struct stackframe_stBM *) &_,   //
               depth + 1, &gotcompobj)),        //
             gotcompobj)
        {
          if (!nobuild)
            _.contdvec = datavect_append_BM (_.contdvec, _.compobj);
        }
      unsigned endlineno = parserlineno_BM (pars);
      unsigned endcolpos = parsercolpos_BM (pars);
      parstoken_tyBM endtok = parsertokenget_BM (pars);
      if (endtok.tok_kind != plex_DELIM
          || endtok.tok_delim != delim_rightbracket)
        parsererrorprintf_BM (pars, lineno, colpos,     //
                              "missing closing bracket for tuple");
      if (parsops && parsops->parsop_decorate_nesting_rout)
        parsops->parsop_decorate_nesting_rout
          (pars, depth,
           delim_leftbracket, lineno, colpos,
           delim_rightbracket, endlineno, endcolpos);
      if (!nobuild)
        _.resval = (value_tyBM)
          maketuple_BM ((objectval_tyBM **) (_.contdvec->vec_data),
                        datavectlen_BM (_.contdvec));
      else
        _.resval = NULL;
      *pgotval = true;
      return _.resval;
    }
  //
  // parse sets
  else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_leftbrace)
    {
      // a set : { obj1 .... objn }
      bool gotelemobj = false;
      _.contdvec = nobuild ? NULL : datavect_grow_BM (NULL, 5);
      while ((gotelemobj = false),      //
             (_.elemobj =       //
              parsergetobject_BM        //
              (pars,            //
               (struct stackframe_stBM *) &_,   //
               depth + 1, &gotelemobj)),        //
             gotelemobj)
        {
          if (!nobuild)
            _.contdvec = datavect_append_BM (_.contdvec, _.elemobj);
        }
      unsigned endlineno = parserlineno_BM (pars);
      unsigned endcolpos = parsercolpos_BM (pars);
      parstoken_tyBM endtok = parsertokenget_BM (pars);
      if (endtok.tok_kind != plex_DELIM
          || endtok.tok_delim != delim_rightbrace)
        parsererrorprintf_BM (pars, lineno, colpos,     //
                              "missing closing brace for set");
      if (parsops && parsops->parsop_decorate_nesting_rout)
        parsops->parsop_decorate_nesting_rout
          (pars, depth,
           delim_leftbrace, lineno, colpos,
           delim_rightbrace, endlineno, endcolpos);
      if (!nobuild)
        _.resval = (value_tyBM)
          makeset_BM ((const objectval_tyBM **) (_.contdvec->vec_data),
                      datavectlen_BM (_.contdvec));
      else
        _.resval = NULL;
      *pgotval = true;
      return _.resval;
    }
  //
  // parse nodes
  else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_star)
    {
      // a node: * connobj ( son1 ... sonn )
      bool gotconnobj = false;
      _.connobj =               //
        parsergetobject_BM      //
        (pars,                  //
         (struct stackframe_stBM *) &_, //
         depth + 1, &gotconnobj);
      if (!gotconnobj)
        parsererrorprintf_BM (pars, lineno, colpos,     //
                              "missing connective object of node after *");
      unsigned leftlineno = parserlineno_BM (pars);
      unsigned leftcolpos = parsercolpos_BM (pars);
      parstoken_tyBM lefttok = parsertokenget_BM (pars);
      if (lefttok.tok_kind != plex_DELIM
          || lefttok.tok_delim != delim_leftparen)
        parsererrorprintf_BM (pars, lineno, colpos,     //
                              "missing left parenthesis for node");
      _.contdvec = nobuild ? NULL : datavect_grow_BM (NULL, 3);
      bool gotson = false;
      while ((gotson = false),  //
             (_.sonval =        //
              parsergetvalue_BM //
              (pars,            //
               (struct stackframe_stBM *) &_,   //
               depth + 1, &gotson)),    //
             gotson)
        {
          if (!nobuild)
            _.contdvec = datavect_append_BM (_.contdvec, _.sonval);
        }
      unsigned endlineno = parserlineno_BM (pars);
      unsigned endcolpos = parsercolpos_BM (pars);
      parstoken_tyBM endtok = parsertokenget_BM (pars);
      if (endtok.tok_kind != plex_DELIM
          || endtok.tok_delim != delim_rightparen)
        parsererrorprintf_BM (pars, lineno, colpos,     //
                              "missing right parenthesis for node");
      if (parsops && parsops->parsop_decorate_start_nesting_rout)
        parsops->parsop_decorate_start_nesting_rout
          (pars, depth,
           delim_star, lineno, colpos,
           delim_leftbrace, leftlineno, leftcolpos,
           delim_rightbrace, endlineno, endcolpos);
      if (!nobuild)
        _.resval = (value_tyBM)
          makenode_BM (_.connobj,
                       datavectlen_BM (_.contdvec),
                       (const value_tyBM *) (_.contdvec->vec_data));
      else
        _.resval = NULL;
      *pgotval = true;
      return _.resval;
    }
  //
  // parse closures
  else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_percent)
    {
      // a closure: % connobj ( son1 ... sonn )
      bool gotconnobj = false;
      _.connobj =               //
        parsergetobject_BM      //
        (pars,                  //
         (struct stackframe_stBM *) &_, //
         depth + 1, &gotconnobj);
      if (!gotconnobj)
        parsererrorprintf_BM    //
          (pars, lineno, colpos,        //
           "missing connective object of closure after %%");
      unsigned leftlineno = parserlineno_BM (pars);
      unsigned leftcolpos = parsercolpos_BM (pars);
      parstoken_tyBM lefttok = parsertokenget_BM (pars);
      if (lefttok.tok_kind != plex_DELIM
          || lefttok.tok_delim != delim_leftparen)
        parsererrorprintf_BM (pars, lineno, colpos,     //
                              "missing left parenthesis for closure");
      _.contdvec = nobuild ? NULL : datavect_grow_BM (NULL, 3);
      bool gotson = false;
      while ((gotson = false),  //
             (_.sonval =        //
              parsergetvalue_BM //
              (pars,            //
               (struct stackframe_stBM *) &_,   //
               depth + 1, &gotson)),    //
             gotson)
        {
          if (!nobuild)
            _.contdvec = datavect_append_BM (_.contdvec, _.sonval);
        }
      unsigned endlineno = parserlineno_BM (pars);
      unsigned endcolpos = parsercolpos_BM (pars);
      parstoken_tyBM endtok = parsertokenget_BM (pars);
      if (endtok.tok_kind != plex_DELIM
          || endtok.tok_delim != delim_rightparen)
        parsererrorprintf_BM (pars, lineno, colpos,     //
                              "missing right parenthesis for closure");
      if (parsops && parsops->parsop_decorate_start_nesting_rout)
        parsops->parsop_decorate_start_nesting_rout
          (pars, depth,
           delim_star, lineno, colpos,
           delim_leftbrace, leftlineno, leftcolpos,
           delim_rightbrace, endlineno, endcolpos);
      if (!nobuild)
        _.resval = (value_tyBM)
          makeclosure_BM (_.connobj,
                          datavectlen_BM (_.contdvec),
                          (const value_tyBM *) (_.contdvec->vec_data));
      else
        _.resval = NULL;
      *pgotval = true;
      return _.resval;
    }
  //////
failure:
  parserseek_BM (pars, lineno, colpos);
  *pgotval = false;
  return NULL;
}                               /* end of parsergetvalue_BM */


value_tyBM
  parsergetchunk_BM
  (struct parser_stBM * pars,
   struct stackframe_stBM * prevstkf, int depth, bool * pgotchunk)
{
  if (!isparser_BM ((const value_tyBM) pars))
    FATAL_BM ("bad parser");
  if (!pgotchunk)
    FATAL_BM ("missing pgotchunk");
  const struct parserops_stBM *parsops = pars->pars_ops;
  assert (!parsops || parsops->parsop_magic == PARSOPMAGIC_BM);
  unsigned startlineno = parserlineno_BM (pars);
  unsigned startcolpos = parsercolpos_BM (pars);
  bool nobuild = parsops && parsops->parsop_nobuild;
  LOCALFRAME_BM                 //
    (prevstkf, NULL,            //
     value_tyBM resval;
     struct datavectval_stBM *chunkvec; objectval_tyBM * obj;
     value_tyBM compv;
    );
  _.chunkvec = nobuild ? NULL : datavect_grow_BM (NULL, 5);
  const char *prev = parserrestline_BM (pars);
  const char *end = NULL;
  gunichar puc = 0;
  if (prev)
    puc = g_utf8_get_char (prev);
  bool gotalnum = (prev && *prev < 127 && (isalnum (*prev) || *prev == '_'));
  bool gotword = (prev && (puc == '_' || g_unichar_isalnum (puc)));
  bool gotspace = (prev && g_unichar_isspace (puc));
  bool gotpunct = (prev && g_unichar_ispunct (puc));
  bool gotend = false;
  int loopcnt = 0;
  do
    {
      unsigned curlineno = parserlineno_BM (pars);
      unsigned curcolpos = parsercolpos_BM (pars);
      char *curpc = (char *) parserrestline_BM (pars);
      if (loopcnt++ > MAXSIZE_BM / 8)
        parsererrorprintf_BM (pars, curlineno, curcolpos,
                              "too many loops %d : %s", loopcnt, curpc);
      if (parserendoffile_BM (pars))
        parsererrorprintf_BM (pars, curlineno, curcolpos,       //
                              "end of file in chunk");
      if (parsereol_BM (pars))
        {
          parsernextline_BM (pars);
          continue;
        }
      gunichar uc = g_utf8_get_char (curpc);
      if (gotalnum && uc < 127 && (isalnum (uc) || uc == '_'))
        {
          parseradvanceutf8_BM (pars, 1);
          continue;
        }
      if ((gotword || gotalnum) && (uc == '_' || g_unichar_isalnum (uc)))
        {
          parseradvanceutf8_BM (pars, 1);
          gotword = true;
          gotalnum = false;
          continue;
        }
      if (gotspace && g_unichar_isspace (uc))
        {
          parseradvanceutf8_BM (pars, 1);
          continue;
        }
      if (gotpunct && uc != '$' && g_unichar_ispunct (uc))
        {
          parseradvanceutf8_BM (pars, 1);
          continue;
        }
      if (curpc && uc == '}' && curpc[1] == '#')
        {
          end = curpc;
          gotend = true;
          parseradvanceutf8_BM (pars, 2);
        }
      if (prev < curpc)
        {
          char oldc = *curpc;
          *curpc = (char) 0;
          rawid_tyBM id = { 0, 0 };
          const char *endt = NULL;
          long long l = 0;
          char numbuf[32];
          if (gotalnum && prev && prev[0] == '_' && isdigit (prev[1])
              && (id = parse_rawid_BM (prev, &endt)).id_hi
              && endt == curpc && (_.obj = findobjofid_BM (id)) != NULL)
            {
              _.chunkvec = datavect_append_BM (_.chunkvec, _.obj);
              *curpc = oldc;
            }
          else if (gotalnum && prev && isdigit (prev[0])
                   && (memset (numbuf, 0, sizeof (numbuf)),
                       (l =
                        strtoll (prev, (char **) &endt, 10)), endt == curpc
                       && snprintf (numbuf, sizeof (numbuf), "%lld", l) > 0
                       && l < LLONG_MAX / 2 && !strcmp (prev, numbuf)))
            {
              _.compv = taggedint_BM (l);
              _.chunkvec = datavect_append_BM (_.chunkvec, _.compv);
              *curpc = oldc;
              prev = curpc;
            }
          else if (gotalnum && isalpha (prev[0]) && validname_BM (prev))
            {
              _.compv = (const value_tyBM) findnamedobj_BM (prev);
              if (!_.compv)
                _.compv = (const value_tyBM) makestring_BM (prev);
              _.chunkvec = datavect_append_BM (_.chunkvec, _.compv);
              *curpc = oldc;
              prev = curpc;
            }
          else if (gotword)
            {
              _.compv = (const value_tyBM) makestring_BM (prev);
              _.chunkvec = datavect_append_BM (_.chunkvec, _.compv);
              *curpc = oldc;
              prev = curpc;
            }
          else if (gotspace)
            {
              _.compv = (const value_tyBM) makestring_BM (prev);
              _.chunkvec = datavect_append_BM (_.chunkvec, _.compv);
              *curpc = oldc;
              prev = curpc;
            }
          else if (gotpunct)
            {
              bool got2doll = false;
              if (oldc == '$' && curpc[1] == '$')
                {
                  curpc[0] = '$';
                  curpc[1] = (char) 0;
                  got2doll = true;
                }
              _.compv = (const value_tyBM) makestring_BM (prev);
              _.chunkvec = datavect_append_BM (_.chunkvec, _.compv);
              *curpc = oldc;
              if (got2doll)
                curpc += 2;
              prev = curpc;
            }
          else
            {
              _.compv = (const value_tyBM) makestring_BM (prev);
              _.chunkvec = datavect_append_BM (_.chunkvec, _.compv);
              *curpc = oldc;
              prev = curpc;
            }
        }                       /* end if prev < curpc */
      if (uc == '$')
        {
        }

      if (prev == curpc)
        {
          puc = g_utf8_get_char (prev);
          gotalnum = (prev && *prev < 127
                      && (isalnum (*prev) || *prev == '_'));
          gotword = (prev && (puc == '_' || g_unichar_isalnum (puc)));
          gotspace = (prev && g_unichar_isspace (puc));
          gotpunct = (prev && g_unichar_ispunct (puc));
        }
    }
  while (!gotend);
}                               /* end parsergetchunk_BM */
