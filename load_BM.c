// file load_BM.c
// SPDX-License-Identifier: GPL-3.0-or-later
/***
    BISMON 
    Copyright © 2018 - 2022 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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

struct loader_stBM *firstloader_BM;

bool load_bismon_completed_BM;

void
loadergcmark_BM (struct garbcoll_stBM *gc, struct loader_stBM *ld)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((const value_tyBM) ld) == typayl_loader_BM);
  ASSERT_BM (ld->ld_magic == LOADERMAGIC_BM);
  uint8_t oldmark = ((typedhead_tyBM *) ld)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *) ld)->hgc = MARKGC_BM;
  gc->gc_nbmarks++;
  EXTENDEDGCPROC_BM (gc, ld->ld_objhset, NULL, 0);
  EXTENDEDGCPROC_BM (gc, ld->ld_modhset, NULL, 0);
  EXTENDEDGCPROC_BM (gc, ld->ld_todolist, NULL, 0);
}                               /* end loadergcmark_BM */

void
loadergcdestroy_BM (struct garbcoll_stBM *gc, struct loader_stBM *ld)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((const value_tyBM) ld) == typayl_loader_BM);
  ASSERT_BM (ld->ld_magic == LOADERMAGIC_BM);
  ASSERT_BM (!firstloader_BM || firstloader_BM == ld);
  INFOPRINTF_BM ("loadergcdestroy_BM called ld @%p\n", (void *) ld);
  if (firstloader_BM == ld)
    firstloader_BM = NULL;
  memset (ld, 0, sizeof (*ld));
  free (ld);
  gc->gc_freedbytes += sizeof (*ld);
}                               /* end loadergcdestroy_BM */

void
loadergckeep_BM (struct garbcoll_stBM *gc, struct loader_stBM *ld)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (valtype_BM ((const value_tyBM) ld) == typayl_loader_BM);
  ASSERT_BM (ld->ld_magic == LOADERMAGIC_BM);
  INFOPRINTF_BM ("loadergckeep_BM called ld @%p\n", (void *) ld);
  gc->gc_keptbytes += sizeof (struct loader_stBM);
}                               /* end loadergckeep_BM */

static void doload_BM (struct stackframe_stBM *fr, struct loader_stBM *ld);


#warning signature of resolve_load_object_routine_at_index_BM might change
/* Because we might use asprintf on a buffer allocated by the calling
   routine load_initial_BM, and that buffer should be passed... */
static void resolve_load_object_routine_at_index_BM (char **bufp,
                                                     struct loader_stBM *ld,
                                                     int ix);

void
resolve_load_object_routine_at_index_BM (char **bufp, struct loader_stBM *ld,
                                         int ix)
{
  char obidbuf[32];
  memset (obidbuf, 0, sizeof (obidbuf));
  ASSERT_BM (ld != NULL);
  ASSERT_BM (ld->ld_magic == LOADERMAGIC_BM);
  ASSERT_BM (bufp != NULL);
  if (*bufp == NULL)
    {
      int isiz = 64;
      *bufp = malloc (isiz);
      if (*bufp)
        memset (*bufp, 0, isiz);
      else
        FATAL_BM ("failed to malloc %d bytes", isiz);
    };
  ASSERT_BM (ld->ld_objroutarr != NULL);
  ASSERT_BM (ld->ld_count_objrout > 0);
  ASSERT_BM (ix >= 0 && ix < ld->ld_count_objrout);
  objectval_tyBM *curob = ld->ld_objroutarr[ix];
  ASSERT_BM (curob && isobject_BM ((value_tyBM) curob));
  rawid_tyBM curoid = objid_BM (curob);
  idtocbuf32_BM (curoid, obidbuf);
  ASSERT_BM (obidbuf[0] != (char) 0);
  char *obdb = objectdbg_BM (curob);
  ASSERT_BM (obdb != NULL);
  int ok = 0;
  if (ix > 0)
    {
      ok = asprintf (bufp, "%s & ", *bufp);
      if (ok < 0)
        FATAL_BM ("asprintf failed ('&')...");
    };
  ok = asprintf (bufp, "%s%s", *bufp, obdb);
  if (ok < 0)
    FATAL_BM ("asprintf failed (%s)...", obdb);
  if (isalpha (obdb[0]))
    {
      ok = asprintf (bufp, "%s=€%s", *bufp, obidbuf);
      if (ok < 0)
        FATAL_BM ("asprintf failed (€%s)...", obidbuf);
    }
}                               /* end resolve_load_object_routine_at_index_BM */


void
load_initial_BM (const char *ldirpath)
{
  if (!ldirpath)
    ldirpath = ".";
  DIR *ldir = opendir (ldirpath);
  char *projectstatefilename = NULL;
  if (!ldir)
    FATAL_BM ("load_initial failed to opendir %s : %m", ldirpath);
  if (project_name_BM)
    {
      if (asprintf
          (&projectstatefilename, "project-%s-BISMON.bmonp",
           project_name_BM) < 0)
        FATAL_BM ("load_initial fail to asprintf for project %s : %m",
                  project_name_BM);
    }
  ASSERT_BM (strlen (STORE_OBJECTOPEN_PREFIX_BM) ==
             strlen (STORE_OBJECTOPEN_ALTPREFIX_BM));
  ASSERT_BM (strlen (STORE_OBJECTCLOSE_PREFIX_BM) ==
             strlen (STORE_OBJECTCLOSE_ALTPREFIX_BM));
  ASSERT_BM (strlen (STORE_MODULE_PREFIX_BM) ==
             strlen (STORE_MODULE_ALTPREFIX_BM));
  ASSERT_BM (strlen (STORE_FUNSIGNATURE_PREFIX_BM) ==
             strlen (STORE_FUNSIGNATURE_ALTPREFIX_BM));
  struct dirent *de = NULL;
  char *todopath = NULL;
  int maxnum = 0;
  int nbfiles = 0;
  bool foundprojectfile = false;
  char *patharr[MAXLOADEDFILES_BM] = { };
  while ((de = readdir (ldir)) != NULL)
    {
      if (!isalpha (de->d_name[0]))
        continue;
      int num = 0;
      int pos = 0;
      if ((sscanf (de->d_name, "store%d-BISMON.bmon%n", &num, &pos) > 0
           && pos > 0) && num > 0 && de->d_name[pos] == 0)
        {
          if (num >= MAXLOADEDFILES_BM)
            FATAL_BM ("too high file number for %s in %s", de->d_name,
                      ldirpath);
          char *buf = NULL;
          if (asprintf (&buf, "%s/%s", ldirpath, de->d_name) > 0
              && buf != NULL)
            {
              struct stat fst = { };
              if (stat (buf, &fst))
                FATAL_BM ("failed to stat %s : %m", buf);
              if ((fst.st_mode & S_IFMT) != S_IFREG)
                FATAL_BM ("%s is not a plain file", buf);
              // detect store12.bmon and store+12.bmon or store0012.bmon
              if (patharr[num])
                FATAL_BM ("duplicate file %s for #%d in %s", buf, num,
                          ldirpath);
              if (num > maxnum)
                maxnum = num;
              nbfiles++;
            }
          else
            FATAL_BM ("asprintf failure (%m)");
          patharr[num] = buf;
        }
      else if (!strcmp (de->d_name, "store_todo.bmon"))
        {
          char *buf = NULL;
          if (asprintf (&buf, "%s/%s", ldirpath, de->d_name) > 0
              && buf != NULL)
            {
              struct stat fst = { };
              if (stat (buf, &fst))
                FATAL_BM ("failed to stat %s : %m", buf);
              if ((fst.st_mode & S_IFMT) != S_IFREG)
                FATAL_BM ("%s is not a plain file", buf);
            }
          else
            FATAL_BM ("asprintf failure (%m)");
          ASSERT_BM (patharr[0] == NULL);
          patharr[0] = buf;
        }
      else if (projectstatefilename
               && !strcmp (de->d_name, projectstatefilename))
        {
          foundprojectfile = true;
        }
    }
  closedir (ldir);
  if (maxnum > MAXLOADEDFILES_BM)
    FATAL_BM ("too many store files %d to load", maxnum);
  INFOPRINTF_BM ("got %d store files in loaded directory %s\n", nbfiles,
                 ldirpath);
  struct loader_stBM *ld =      //
    allocgcty_BM (typayl_loader_BM, sizeof (struct loader_stBM));
  // ((typedhead_tyBM *) ld)->htyp = typayl_loader_BM;
  // ((typedhead_tyBM *) ld)->hgc = 0;
  ((typedhead_tyBM *) ld)->rlen = 0;
  ld->ld_magic = LOADERMAGIC_BM;
  ld->ld_maxnum = maxnum;
  ld->ld_startelapsedtime = elapsedtime_BM ();
  ld->ld_startcputime = cputime_BM ();
  ld->ld_curspaceix = -__LINE__;
  ld->ld_passnum = -1;
  ld->ld_objhset =
    hashsetobj_grow_BM (NULL, 2 * BM_NB_PREDEFINED + maxnum * 100);
  ld->ld_modhset = hashsetobj_grow_BM (NULL, 2 * TINYSIZE_BM);
  ld->ld_todolist = makelist_BM ();
  ld->ld_storepatharr = calloc (maxnum + 2, sizeof (void *));
  if (!ld->ld_storepatharr)
    FATAL_BM ("cannot calloc for %d store files (%m)", maxnum);
  // should initialize the objroutarr vector
  {
    unsigned inirsiz = prime_above_BM (2 * BM_NB_PREDEFINED + 3);
    ld->ld_objroutarr = calloc (inirsiz, sizeof (objectval_tyBM *));
    if (!ld->ld_objroutarr)
      FATAL_BM ("failed to allocate for %u object routines", inirsiz);
    ld->ld_size_objroutarr = inirsiz;
    ld->ld_count_objrout = 0;
  };
  if (foundprojectfile)
    {
      if (asprintf
          (&ld->ld_projectstatepath, "%s/%s", ldirpath,
           projectstatefilename) < 0)
        FATAL_BM
          ("failed to make project state path for loaded directory %s and project file %s",
           ldirpath, projectstatefilename);
      free (projectstatefilename), projectstatefilename = NULL;
    }
  for (int ix = 1; ix <= maxnum; ix++)
    {
      char *pa = patharr[ix];
      if (pa)
        {
          ld->ld_storepatharr[ix] = pa;
          nbfiles++;
        };
    }
  ld->ld_parsarr = calloc (maxnum + 2, sizeof (void *));
  if (!ld->ld_parsarr)
    FATAL_BM ("cannot calloc for %d parsers (%m)", maxnum);
  ld->ld_storepatharr[0] = todopath;
  ld->ld_dir = strdup (ldirpath);
  if (!ld->ld_dir)
    FATAL_BM ("cannot strdup dir %s (%m)", ldirpath);
  firstloader_BM = ld;
  {
    LOCALFRAME_BM ( /*prev: */ NULL, /*descr: */ NULL,
                   struct loader_stBM *curld);
    _.curld = ld;
    doload_BM (CURFRAME_BM, ld);
  }
  {
    double deltaelapsed = elapsedtime_BM () - ld->ld_startelapsedtime;
    double deltacpu = cputime_BM () - ld->ld_startcputime;
    char *realp = realpath (ld->ld_dir, NULL);
    INFOPRINTF_BM
      ("*¤°°°¤* %s loaded %d files from %s (%s) with %ld objects,\n"
       "... %d modules, %d routines in %.4f cpu %.3f real seconds\n"
       "... (%.1f cpu, %.1f real µs/obj); on host %s pid %d\n",
       myprogname_BM, nbfiles, ld->ld_dir, realp, ld->ld_nbobjects,
       ld->ld_nbmodules, ld->ld_nbroutines, deltacpu, deltaelapsed,
       (deltacpu * 1.0e6) / ld->ld_nbobjects,
       (deltaelapsed * 1.0e6) / ld->ld_nbobjects, myhostname_BM,
       (int) getpid ());
    free (realp), realp = NULL;
  }
  firstloader_BM = NULL;
  free (ld->ld_dir), ld->ld_dir = NULL;
  for (int ix = 0; ix <= maxnum; ix++)
    {
      free (ld->ld_storepatharr[ix]), ld->ld_storepatharr[ix] = NULL;
      ld->ld_parsarr[ix] = NULL;
    }
  free (ld->ld_storepatharr), ld->ld_storepatharr = NULL;
  free (ld->ld_projectstatepath), ld->ld_projectstatepath = NULL;
  free (ld->ld_parsarr), ld->ld_parsarr = NULL;
  ld->ld_objhset = NULL;
  ld->ld_modhset = NULL;
  free (ld->ld_dir), ld->ld_dir = NULL;
  ld->ld_data = NULL;
  ld->ld_maxnum = 0;
  if (ld->ld_objroutarr)
    {
      if (showdebugmsg_BM)
        {
          char pmapcmd[64];
          memset (pmapcmd, 0, sizeof (pmapcmd));
          snprintf (pmapcmd, sizeof (pmapcmd), "/usr/bin/pmap %d",
                    (int) getpid ());
          DBGPRINTF_BM ("running %s", pmapcmd);
          fflush (NULL);
          system (pmapcmd);
        };
#warning probably missing code to resolve object routines
      if (ld->ld_count_objrout > 0)
        {
          char *buf = NULL;
          if (ld->ld_objroutarr[0] != NULL)
            {
              resolve_load_object_routine_at_index_BM (&buf, ld, 0);
            };
          if (ld->ld_objroutarr[1] != NULL)
            {
              resolve_load_object_routine_at_index_BM (&buf, ld, 1);
            };
          if (ld->ld_objroutarr[2] != NULL)
            {
              resolve_load_object_routine_at_index_BM (&buf, ld, 2);
            };
          if (ld->ld_objroutarr[3] != NULL)
            {
              resolve_load_object_routine_at_index_BM (&buf, ld, 3);
            };
          if (ld->ld_objroutarr[4] != NULL)
            {
              resolve_load_object_routine_at_index_BM (&buf, ld, 4);
            };
          if (ld->ld_objroutarr[5] != NULL)
            {
              resolve_load_object_routine_at_index_BM (&buf, ld, 5);
            };
          if (ld->ld_objroutarr[6] != NULL)
            {
              int ok = asprintf (&buf, "%s ...etc...", buf);
              if (ok < 0)
                FATAL_BM ("asprintf ...etc... fail");
            };
          WARNPRINTF_BM
            ("load_initial_BM: unresolved %u object routines (%s) with %d modules",
             ld->ld_count_objrout, buf, module_count_BM ());
        }
      free (ld->ld_objroutarr);
      ld->ld_objroutarr = NULL;
      ld->ld_count_objrout = 0;
      ld->ld_size_objroutarr = 0;
    };
  // keep the header of ld; it will become GC-ed later
  load_bismon_completed_BM = true;
}                               /* end load_initial_BM */

void
load_addtodo_BM (const closure_tyBM * clos)
{
  if (!firstloader_BM)
    FATAL_BM ("load_addtodo_BM called after loading");
  if (!isclosure_BM ((const value_tyBM) clos))
    FATAL_BM ("load_addtodo_BM called with non-closure");
  if (!islist_BM (firstloader_BM->ld_todolist))
    FATAL_BM ("missing todolist in loader for load_addtodo_BM");
  listappend_BM (firstloader_BM->ld_todolist, (value_tyBM) clos);
}                               /* end load_addtodo_BM */



static inline int
first_pass_got_delim_bm (const char *buf, const char *delimstr)
{
  ASSERT_BM (buf != NULL);
  if (!delimstr)
    return 0;
  int delimlen = strlen (delimstr);
  if (!strncmp (buf, delimstr, delimlen))
    return delimlen;
  else
    return 0;
}                               /* end of first_pass_got_delim_bm */



#define FIRST_PASS_HAS_DELIM_bm(LinBuf,DelimLen,StorDelim)      \
  (((DelimLen =                                                 \
    first_pass_got_delim_bm((LinBuf),                           \
                            StorDelim##_PREFIX_BM)) > 0)        \
  || ((DelimLen =                                               \
       first_pass_got_delim_bm((LinBuf),                        \
                               StorDelim##_ALTPREFIX_BM)) > 0)  \
  || ((DelimLen =                                               \
       first_pass_got_delim_bm((LinBuf),                        \
                               StorDelim##_TERPREFIX_BM)) > 0))


#warning TODO: loader should create missing C function stub in temporary_dir_BM

static void
load_first_pass_BM (struct loader_stBM *ld, int ix)
{
  ASSERT_BM (ld && ld->ld_magic == LOADERMAGIC_BM);
  ASSERT_BM ((ix >= 0 && ix <= (int) ld->ld_maxnum) || ix == ProjectSp_BM);
  ld->ld_passnum = 1;
  char *curldpath = NULL;
  if (ix >= 0 && ix <= (int) ld->ld_maxnum)
    curldpath = ld->ld_storepatharr[ix];
  else if (ix == ProjectSp_BM)
    curldpath = ld->ld_projectstatepath;
  ld->ld_curspaceix = ix;
  ASSERT_BM (curldpath != NULL);
  size_t linsiz = 256;
  char *linbuf = malloc (linsiz);
  if (!linbuf)
    FATAL_BM ("malloc failed linsiz=%zd (%m)", linsiz);
  memset (linbuf, 0, linsiz);
  FILE *fil = fopen (curldpath, "r");
  if (!fil)
    FATAL_BM ("fopen %s failed (%m)", curldpath);
  int lincnt = 0;
  int nbobjdef = 0;
  int nbrout = 0;
  objectval_tyBM *curloadedobj = NULL;
  do
    {
      ssize_t linlen = getline (&linbuf, &linsiz, fil);
      int delimlen = 0;
      if (linlen < 0)
        {
          if (!feof (fil))
            FATAL_BM ("getline %s:%d failed (%m)", curldpath, lincnt);
          break;
        }
      linbuf[linlen] = (char) 0;
      if (UNLIKELY_BM (lincnt == 0))
        {
          if (strncmp
              (linbuf, STORE_CONTENTMAGIC_PREFIX_BM,
               strlen (STORE_CONTENTMAGIC_PREFIX_BM)))
            WARNPRINTF_BM
              ("loaded persistent store file %s does not start with magic '%s' characters",
               curldpath, STORE_CONTENTMAGIC_PREFIX_BM);
        }
      lincnt++;
      // skip comment lines and empty lines
      if (linbuf[0] == '/' && linbuf[1] == '/')
        continue;
      if (!linbuf[0])
        continue;
      /* object definition starting lines are !(<oid> or «<oid> e.g. !(_7D8xcWnEiys_8oqOVSkCxkA */
      if (FIRST_PASS_HAS_DELIM_bm (linbuf, delimlen, STORE_OBJECTOPEN)
          && linbuf[delimlen] == '_' && isdigit (linbuf[delimlen + 1]))
        {
          DBGPRINTF_BM
            ("first_pass %s:%d got STORE_OBJECTOPEN linbuf='%s' delimlen=%d curloadedobj=%s",
             curldpath, lincnt, linbuf, delimlen,
             objectdbg_BM (curloadedobj));
          const char *endid = NULL;
          rawid_tyBM id = parse_rawid_BM (linbuf + 2, &endid);
          if (hashid_BM (id) && endid >= linbuf + 2 * SERIALDIGITS_BM
              && (*endid == (char) 0 || isspace (*endid)))
            {
              objectval_tyBM *newobj = makeobjofid_BM (id);
              curloadedobj = newobj;
              if (!newobj->ob_space)
                objputspacenum_BM (newobj, ix);
              char idbuf32[32] = "";
              idtocbuf32_BM (id, idbuf32);
              if (hashsetobj_contains_BM (ld->ld_objhset, newobj))
                {
                  FATAL_BM ("duplicate id %s near %s:%d", idbuf32, curldpath,
                            lincnt);
                };
              ld->ld_objhset = hashsetobj_add_BM (ld->ld_objhset, newobj);
              nbobjdef++;
            }
          else
            FATAL_BM ("invalid object definition line %s in file %s:%d",
                      linbuf, curldpath, lincnt);
        }
      //
      else
        /* object definition ending lines are like !)<oid> or »<oid> so e.g. »_7D8xcWnEiys_8oqOVSkCxkA */
      if (FIRST_PASS_HAS_DELIM_bm (linbuf, delimlen, STORE_OBJECTCLOSE)
            && linbuf[delimlen] == '_' && isdigit (linbuf[delimlen + 1]))
        {
          DBGPRINTF_BM
            ("first_pass %s:%d got STORE_OBJECTCLOSE linbuf='%s' delimlen=%d curloadedobj=%s",
             curldpath, lincnt, linbuf, delimlen,
             objectdbg_BM (curloadedobj));
          const char *endid = NULL;
          rawid_tyBM id = parse_rawid_BM (linbuf + 2, &endid);
          if (hashid_BM (id) && endid >= linbuf + 2 * SERIALDIGITS_BM
              && (*endid == (char) 0 || isspace (*endid)))
            {
              if (!curloadedobj)
                FATAL_BM ("unexpected end-of-object line %s in file %s:%d",
                          linbuf, curldpath, lincnt);
              if (!equalid_BM (id, curloadedobj->ob_id))
                {
                  char curldidbuf32[32] = "";
                  idtocbuf32_BM (curloadedobj->ob_id, curldidbuf32);
                  FATAL_BM
                    ("mismatched end-of-object line %s in file %s:%d, expecting %s",
                     linbuf, curldpath, lincnt, curldidbuf32);
                }
            }
          else
            FATAL_BM ("invalid end-of-object line %s in file %s:%d",
                      linbuf, curldpath, lincnt);
          // load a function_sig if it exists
          if (curloadedobj && !curloadedobj->ob_rout)
            {
              char curldidbuf32[32] = "";
              idtocbuf32_BM (curloadedobj->ob_id, curldidbuf32);
              char symbuf[48];
              memset (symbuf, 0, sizeof (symbuf));
              snprintf (symbuf, sizeof (symbuf),        //
                        ROUTINEOBJPREFIX_BM "%s" ROUTINESUFFIX_BM,
                        curldidbuf32);
              DBGPRINTF_BM ("dlsym-ing '%s' in whole program", symbuf);
              void *ad = dlsym (dlprog_BM, symbuf);
              if (ad)
                {
                  curloadedobj->ob_rout = ad;
                  curloadedobj->ob_sig = BMP_function_sig;
                  nbrout++;
                  printf
                    ("forced %d-th routine %s of function_sig for %s in file %s\n",
                     nbrout, symbuf, curldidbuf32, curldpath);
                }
              else              /* no ad, since dlsym failed: */
                {
                  int nbloadedmodules = module_count_BM ();
                  WARNPRINTF_BM
                    ("load_first_pass_BM failed dlsym-ing '%s' in whole program: %s;\n"
                     "... with already %d modules loaded\n", symbuf,
                     dlerror (), nbloadedmodules);
                  if (nbloadedmodules > 0)
                    {
                      if (backtracestate_BM != NULL
                          && pthread_self () == mainthreadid_BM)
                        {
                          backtrace_print_BM ((struct backtrace_state *)
                                              backtracestate_BM, 1, stderr);
                          fprintf (stderr,
                                   "*¤*load_first_pass_BM failing dlsym-ing '%s' at %s:%d with %d loaded modules**\n",
                                   symbuf, curldpath, lincnt,
                                   nbloadedmodules);
                          fflush (stderr);
                        }
                    }
                  if (ld->ld_count_objrout + 2 > ld->ld_size_objroutarr)
                    {
                      unsigned newsiz =
                        prime_above_BM (4 * ld->ld_count_objrout / 3 + 10);
                      ASSERT_BM (newsiz > ld->ld_size_objroutarr);
                      objectval_tyBM **newarr =
                        calloc (newsiz, sizeof (objectval_tyBM *));
                      if (!newarr)
                        FATAL_BM ("failed to allocate for %u object routines",
                                  newsiz);
                      memcpy (newarr, ld->ld_objroutarr,
                              ld->ld_count_objrout *
                              sizeof (objectval_tyBM *));
                      free (ld->ld_objroutarr);
                      ld->ld_objroutarr = newarr;
                      ld->ld_size_objroutarr = newsiz;
                    };
                  ld->ld_objroutarr[ld->ld_count_objrout++] = curloadedobj;
                }
            }
          curloadedobj = NULL;
        }
      //
      /* function_sig signature !|<signature> or Σ<signature> where
         the <signature> is * or an objid; but we only handle the *
         case in this first pass */
      else if (FIRST_PASS_HAS_DELIM_bm (linbuf, delimlen, STORE_FUNSIGNATURE))
        {
          DBGPRINTF_BM
            ("first_pass %s:%d got STORE_FUNSIGNATURE linbuf='%s' delimlen=%d curloadedobj=%s",
             curldpath, lincnt, linbuf, delimlen,
             objectdbg_BM (curloadedobj));
          char idbuf32[32] = "";
          if (!curloadedobj)
            FATAL_BM
              ("invalid function-sig line %s in file %s:%d, no current object",
               linbuf, curldpath, lincnt);
          idtocbuf32_BM (curloadedobj->ob_id, idbuf32);
          // if there is a routine for that object, bind it now
          char symbuf[48];
          memset (symbuf, 0, sizeof (symbuf));
          snprintf (symbuf, sizeof (symbuf),    //
                    ROUTINEOBJPREFIX_BM "%s" ROUTINESUFFIX_BM, idbuf32);
          DBGPRINTF_BM
            ("load_first_pass ix#%d dlsym-ing '%s' in whole program", ix,
             symbuf);
          void *ad = dlsym (dlprog_BM, symbuf);
          if (ad)
            {
              curloadedobj->ob_rout = ad;
              curloadedobj->ob_sig = BMP_function_sig;
              nbrout++;
            }
          else
            {
              char dlerrbuf[80];
              memset (dlerrbuf, 0, sizeof (dlerrbuf));
              strncpy (dlerrbuf, dlerror (), sizeof (dlerrbuf));
              /* the first store space is the predefined one, and we
                 need it to be correct... */
              if (ld->ld_curspaceix > 1)
                curloadedobj->ob_rout = warning_objrout_BM;
              else
                {
                  WARNPRINTF_BM
                    ("loader first space in buggy store file %s:%d, dlsym %s in whole program failed %s",
                     curldpath, lincnt, symbuf, dlerrbuf);
                  curloadedobj->ob_rout = crashing_objrout_BM;
                }
              curloadedobj->ob_sig = BMP_function_sig;
              /// if (sscanf (linbuf + delimlen, " *%n", &pos) >= 0 && pos > 0) 
            }
        }
      //
      /* module requirement lines are µ<mod-id> or !^<mod-id> */
      else
        if (FIRST_PASS_HAS_DELIM_bm (linbuf, delimlen, STORE_MODULE)
            && linbuf[delimlen] == '_' && isdigit (linbuf[delimlen + 1]))
        {
          DBGPRINTF_BM
            ("first_pass %s:%d got STORE_MODULE linbuf='%s' delimlen=%d curloadedobj=%s",
             curldpath, lincnt, linbuf, delimlen,
             objectdbg_BM (curloadedobj));
          const char *endid = NULL;
          rawid_tyBM modid = parse_rawid_BM (linbuf + delimlen, &endid);
          if (hashid_BM (modid) && endid >= linbuf + 2 * SERIALDIGITS_BM
              && (*endid == (char) 0 || isspace (*endid)))
            {
              if (!open_module_for_loader_BM (modid, ld, NULL))
                {
                  WARNPRINTF_BM
                    ("loader failed to open module for %s in %s line %d",
                     linbuf, curldpath, lincnt);
                  if (backtracestate_BM)
                    backtrace_print_BM
                      ((struct backtrace_state *) backtracestate_BM, 0,
                       stderr);
                }
            }
          else
            FATAL_BM ("invalid module requirement line %s in file %s:%d",
                      linbuf, curldpath, lincnt);
        }
    }
  while (!feof (fil));
  if (nbobjdef == 0 && ix > 0)
    FATAL_BM ("no object definition in %s\n", curldpath);
  free (linbuf), linbuf = 0;
  fclose (fil);
  ld->ld_nbobjects += nbobjdef;
  ld->ld_nbroutines += nbrout;
  ld->ld_curspaceix = -__LINE__;
  ld->ld_passnum = -__LINE__;
}                               /* end load_first_pass_BM */





static void
load_modif_class_BM (struct loader_stBM *ld, int ix,
                     struct stackframe_stBM *parstkfrm,
                     struct parser_stBM *ldpars, objectval_tyBM * argcurldobj)
{
  ASSERT_BM (ld && ld->ld_magic == LOADERMAGIC_BM);
  ASSERT_BM (ix >= 0 && ix <= (int) ld->ld_maxnum);
  char *curldpath = ld->ld_storepatharr[ix];
  ASSERT_BM (curldpath != NULL);
  ASSERT_BM (ldpars != NULL);
  ASSERT_BM (isobject_BM (argcurldobj));
  LOCALFRAME_BM (parstkfrm, NULL,       //
                 struct parser_stBM *ldparser;  //
                 objectval_tyBM * curldobj;     //
                 objectval_tyBM * superclassobj;        //
                 objectval_tyBM * selectorobj;  //
                 value_tyBM * methodv;  //
    );
  _.curldobj = argcurldobj;
  unsigned lineno = parserlineno_BM (ldpars);
  unsigned colpos = parsercolpos_BM (ldpars);
  parstoken_tyBM tokopen = parsertokenget_BM (ldpars, CURFRAME_BM);
  if (tokopen.tok_kind != plex_DELIM
      || tokopen.tok_delim != delim_leftparentilde)
    parsererrorprintf_BM (ldpars, CURFRAME_BM, lineno,
                          colpos, "expecting (~ after !~class");
  bool gotsuper = false;
  _.superclassobj =             //
    parsergetobject_BM (ldpars, CURFRAME_BM,    //
                        0, &gotsuper);
  if (!gotsuper)
    parsererrorprintf_BM (ldpars, CURFRAME_BM, lineno,
                          colpos, "expecting <superclass> after !~ class (~");
  objputclassinfo_BM (_.curldobj, _.superclassobj);
  parstoken_tyBM toknext = EMPTY_TOKEN_BM;
  unsigned nextlineno = 0;
  unsigned nextcolpos = 0;
  for (;;)
    {
      nextlineno = parserlineno_BM (ldpars);
      nextcolpos = parsercolpos_BM (ldpars);
      toknext = parsertokenget_BM (ldpars, CURFRAME_BM);
      if (toknext.tok_kind != plex_DELIM
          || toknext.tok_delim != delim_tildecolon)
        break;
      bool gotselectorobj = false;
      _.selectorobj = parsergetobject_BM (ldpars, CURFRAME_BM,  //
                                          0, &gotselectorobj);
      if (!gotselectorobj || !_.selectorobj)
        parsererrorprintf_BM    //
          (ldpars, CURFRAME_BM, nextlineno, nextcolpos,
           "expecting <selector> after ~: in class modification");
      bool gotmethodv = false;
      _.methodv =               //
        parsergetvalue_BM (ldpars, CURFRAME_BM, 0, &gotmethodv);
      if (!gotmethodv || valtype_BM (_.methodv) != tyClosure_BM)
        parsererrorprintf_BM (ldpars, CURFRAME_BM,
                              nextlineno, nextcolpos,
                              "expect method closure");
      objclassinfoputmethod_BM (_.curldobj, _.selectorobj,
                                (const closure_tyBM *) (_.methodv));
    }
  if (toknext.tok_kind != plex_DELIM
      || toknext.tok_delim != delim_tilderightparen)
    parsererrorprintf_BM (ldpars, CURFRAME_BM, nextlineno,
                          nextcolpos, "expect ~) ending class modification");
}                               /* end load_modif_class_BM */


static void
load_modif_name_BM (struct loader_stBM *ld, int ix,
                    struct stackframe_stBM *parstkfrm,
                    struct parser_stBM *ldpars, objectval_tyBM * argcurldobj)
{
  ASSERT_BM (ld && ld->ld_magic == LOADERMAGIC_BM);
  ASSERT_BM (ix >= 0 && ix <= (int) ld->ld_maxnum);
  char *curldpath = ld->ld_storepatharr[ix];
  ASSERT_BM (curldpath != NULL);
  ASSERT_BM (ldpars != NULL);
  ASSERT_BM (isobject_BM (argcurldobj));
  LOCALFRAME_BM (parstkfrm, NULL,       //
                 struct parser_stBM *ldparser;  //
                 objectval_tyBM * curldobj;     //
                 objectval_tyBM * superclassobj;        //
                 objectval_tyBM * selectorobj;  //
                 value_tyBM methodv;    //
                 value_tyBM namev;      //
    );
  _.curldobj = argcurldobj;
  unsigned lineno = parserlineno_BM (ldpars);
  unsigned colpos = parsercolpos_BM (ldpars);
  parstoken_tyBM tokopen = parsertokenget_BM (ldpars, CURFRAME_BM);
  if (tokopen.tok_kind != plex_DELIM
      || tokopen.tok_delim != delim_leftparentilde)
    parsererrorprintf_BM (ldpars, CURFRAME_BM, lineno,
                          colpos, "expecting (~ after !~name");
  parstoken_tyBM tokname = parsertokenget_BM (ldpars, CURFRAME_BM);
  const char *namestr = NULL;
  if (tokname.tok_kind == plex_NAMEDOBJ)
    {
      _.namev = (value_tyBM) tokname.tok_namedobj;
      namestr = findobjectname_BM (tokname.tok_namedobj);
    }
  else if (tokname.tok_kind == plex_CNAME)
    {
      _.namev = (value_tyBM) tokname.tok_cname;
      namestr = bytstring_BM (_.namev);
    }
  else
    parsererrorprintf_BM (ldpars, CURFRAME_BM, lineno,
                          colpos,
                          "expecting cname or namedobj after !~name (~");
  ASSERT_BM (namestr != NULL);
  const char *oldname = findobjectname_BM (_.curldobj);
  if (oldname && strcmp (oldname, namestr))
    {
      char idbuf[32];
      memset (idbuf, 0, sizeof (idbuf));
      idtocbuf32_BM (_.curldobj->ob_id, idbuf);
      parsererrorprintf_BM (ldpars, CURFRAME_BM, lineno,
                            colpos,
                            "already named '%s' object %s cannot get new name '%s'",
                            oldname, idbuf, namestr);
    };
  registername_BM (_.curldobj, namestr);
  parstoken_tyBM tokclose = parsertokenget_BM (ldpars, CURFRAME_BM);
  if (tokclose.tok_kind != plex_DELIM
      || tokclose.tok_delim != delim_tilderightparen)
    parsererrorprintf_BM (ldpars, CURFRAME_BM, lineno,
                          colpos, "expecting ~) ending !~name");
}                               /* end load_modif_name_BM */

static void
load_modif_value_BM (struct loader_stBM *ld, int ix,
                     struct stackframe_stBM *parstkfrm,
                     struct parser_stBM *ldpars, objectval_tyBM * argcurldobj)
{
  ASSERT_BM (ld && ld->ld_magic == LOADERMAGIC_BM);
  ASSERT_BM (ix >= 0 && ix <= (int) ld->ld_maxnum);
  char *curldpath = ld->ld_storepatharr[ix];
  ASSERT_BM (curldpath != NULL);
  ASSERT_BM (ldpars != NULL);
  ASSERT_BM (isobject_BM (argcurldobj));
  LOCALFRAME_BM (parstkfrm, NULL,       //
                 struct parser_stBM *ldparser;  //
                 objectval_tyBM * curldobj;     //
                 value_tyBM valv;);
  _.ldparser = ldpars;
  _.curldobj = argcurldobj;
  unsigned lineno = parserlineno_BM (ldpars);
  unsigned colpos = parsercolpos_BM (ldpars);
  parstoken_tyBM tokopen = parsertokenget_BM (ldpars, CURFRAME_BM);
  if (tokopen.tok_kind != plex_DELIM
      || tokopen.tok_delim != delim_leftparentilde)
    parsererrorprintf_BM (ldpars, CURFRAME_BM, lineno,
                          colpos, "expecting (~ after !~value");
  bool gotval = false;
  _.valv =                      //
    parsergetvalue_BM (ldpars, CURFRAME_BM, 0, &gotval);
  if (!gotval)
    parsererrorprintf_BM (ldpars, CURFRAME_BM,
                          tokopen.tok_line, tokopen.tok_col,
                          "expect value after !~value (~");
  parstoken_tyBM tokclose = parsertokenget_BM (ldpars, CURFRAME_BM);
  if (tokclose.tok_kind != plex_DELIM
      || tokclose.tok_delim != delim_tilderightparen)
    parsererrorprintf_BM (ldpars, CURFRAME_BM,
                          parserlineno_BM (ldpars),
                          parsercolpos_BM (ldpars),
                          "expect )~ after !~value (~ <value> ");
  objputpayload_BM (_.curldobj, _.valv);
}                               /* end load_modif_value_BM */


static void
load_modif_json_BM (struct loader_stBM *ld, int ix,
                    struct stackframe_stBM *parstkfrm,
                    struct parser_stBM *ldpars, objectval_tyBM * argcurldobj)
{
  ASSERT_BM (ld && ld->ld_magic == LOADERMAGIC_BM);
  ASSERT_BM (ix >= 0 && ix <= (int) ld->ld_maxnum);
  char *curldpath = ld->ld_storepatharr[ix];
  char *debugjson = getenv ("BISMON_DEBUG_JSON");
  INFOPRINTF_BM ("load_modif_json_BM debugjson=%s", debugjson);
  ASSERT_BM (curldpath != NULL);
  ASSERT_BM (ldpars != NULL);
  ASSERT_BM (isobject_BM (argcurldobj));
  LOCALFRAME_BM (parstkfrm, NULL,       //
                 struct parser_stBM *ldparser;  //
                 objectval_tyBM * curldobj;     //
                 value_tyBM valv;);
  _.ldparser = ldpars;
  _.curldobj = argcurldobj;
  unsigned lineno = parserlineno_BM (ldpars);
  unsigned colpos = parsercolpos_BM (ldpars);
  bool removedebug = false;
  if (debugjson && !showdebugmsg_BM)
    {
      showdebugmsg_BM = true;
      removedebug = true;
      DBGBACKTRACEPRINTF_BM ("load_modif_json_BM ix=%d L%uC%u debugjson=%s",
                             ix, lineno, colpos, debugjson);
    }
  parstoken_tyBM tokopen = parsertokenget_BM (ldpars, CURFRAME_BM);
  if (tokopen.tok_kind != plex_DELIM
      || tokopen.tok_delim != delim_leftparentilde)
    parsererrorprintf_BM (ldpars, CURFRAME_BM, lineno,
                          colpos, "expecting (~ after !~json");
  char *membuf = NULL;
  size_t memsiz = 0;
  FILE *memfil = open_memstream (&membuf, &memsiz);
  if (!memfil)
    FATAL_BM ("load_modif_json_BM L%uC%u %s failed to open_memstream",
              lineno, colpos, ldpars->pars_path);
  fputs (ldpars->pars_linebuf + tokopen.tok_col + 2, memfil);
  bool endjs = false;
  int nbjsline = 0;
  do
    {
      parsernextline_BM (ldpars);
      DBGPRINTF_BM
        ("load_modif_json_BM store%d-BISMON.bmon L%u linlen %ld linbuf '%s'",
         ix, lineno + nbjsline, ldpars->pars_linelen, ldpars->pars_linebuf);
      if (ldpars->pars_linelen <= 0
          || (ldpars->pars_linelen >= 2 && ldpars->pars_linebuf[0] == '~'
              && ldpars->pars_linebuf[1] == ')'))
        {
          endjs = true;
          break;
        }
      else
        {
          fputs (ldpars->pars_linebuf, memfil);
        }
      if (nbjsline > 0 && nbjsline % 64 == 0)
        {
          fflush (memfil);
          WARNPRINTF_BM
            ("load_modif_json_BM L%uC%u curldobj=%s, quite long (%d lines) JSON-membuf=\n%s\n//----\n",
             lineno, colpos, objectdbg_BM (_.curldobj), nbjsline, membuf);
        }
      nbjsline++;
    }
  while (!endjs);
  //
  fputc ('\n', memfil);
  fflush (memfil);
  long lnjs = ftell (memfil);
  DBGPRINTF_BM
    ("load_modif_json_BM L%uC%u curldobj=%s, JSON-membuf=\n%s\n//----\n",
     lineno, colpos, objectdbg_BM (_.curldobj), membuf);
  parstoken_tyBM tokclose = parsertokenget_BM (ldpars, CURFRAME_BM);
  if (tokclose.tok_kind != plex_DELIM
      || tokclose.tok_delim != delim_tilderightparen)
    parsererrorprintf_BM (ldpars, CURFRAME_BM,
                          parserlineno_BM (ldpars), parsercolpos_BM (ldpars),
                          "expect )~ after !~json (~ <JSON> ");
  json_error_t jserr = { };
  json_t *js = json_loadb (membuf, lnjs,
                           JSON_DISABLE_EOF_CHECK | JSON_REJECT_DUPLICATES |
                           JSON_DECODE_ANY, &jserr);
  if (!js)
    FATAL_BM ("load_modif_json_BM L%uC%u %s failed %s\n"
              "... JSON decoding %s (~L%uC%u)",
              lineno, colpos, ldpars->pars_path, objectdbg_BM (_.curldobj),
              jserr.text, lineno + jserr.line,
              (jserr.line >
               1) ? (int) jserr.column : (int) colpos + jserr.column);
  fclose (memfil);
  free (membuf), membuf = NULL;
  objputjansjsonpayl_BM (_.curldobj, js);
  if (removedebug)
    {
      char *strjs = json_dumps (js, JSON_SORT_KEYS | JSON_INDENT (1));
      DBGBACKTRACEPRINTF_BM
        ("load_modif_json_BM ix=%d L%uC%u end debugjson=%s curldobj=%s strjs=\n%s\n",
         ix, lineno, colpos, debugjson, objectdbg_BM (_.curldobj), strjs);
      free (strjs);
      showdebugmsg_BM = false;
    }
}                               /* end load_modif_json_BM */





#define TODO_MAXARGS_BM 5
static void
load_modif_todo_BM (struct loader_stBM *ld, int ix,
                    struct stackframe_stBM *parstkfrm,
                    struct parser_stBM *ldpars, objectval_tyBM * argcurldobj)
{
  ASSERT_BM (ld && ld->ld_magic == LOADERMAGIC_BM);
  ASSERT_BM (ix >= 0 && ix <= (int) ld->ld_maxnum);
  char *curldpath = ld->ld_storepatharr[ix];
  ASSERT_BM (curldpath != NULL);
  ASSERT_BM (ldpars != NULL);
  ASSERT_BM (isobject_BM (argcurldobj));
  LOCALFRAME_BM (parstkfrm, NULL,       //
                 struct parser_stBM *ldparser;  //
                 objectval_tyBM * curldobj;     //
                 value_tyBM valv;       //
                 value_tyBM todov;      //
                 const closure_tyBM * closv;    //
                 objectval_tyBM * obselv;       //
                 value_tyBM args[TODO_MAXARGS_BM];);
  _.ldparser = ldpars;
  _.curldobj = argcurldobj;
  unsigned lineno = parserlineno_BM (ldpars);
  unsigned colpos = parsercolpos_BM (ldpars);
  parstoken_tyBM tokopen = parsertokenget_BM (ldpars, CURFRAME_BM);
  if (tokopen.tok_kind != plex_DELIM
      || tokopen.tok_delim != delim_leftparentilde)
    parsererrorprintf_BM (ldpars, CURFRAME_BM, lineno,
                          colpos, "expecting (~ after !~todo");
  bool again;
  do
    {
      again = false;
      bool gotval = false;
      _.valv =                  //
        parsergetvalue_BM (ldpars, CURFRAME_BM, 0, &gotval);
      if (!gotval)
        parsererrorprintf_BM (ldpars, CURFRAME_BM,
                              tokopen.tok_line, tokopen.tok_col,
                              "expect value after !~todo (~");
      bool gottree = false;
      bool gotselector = false;
      if (istree_BM (_.valv))
        {
          gottree = true;
          _.closv = (const tree_tyBM *) _.valv;
        }
      else if (isobject_BM (_.valv))
        {
          gotselector = true;
          _.obselv = (objectval_tyBM *) _.valv;
        }
      else
        parsererrorprintf_BM (ldpars, CURFRAME_BM,
                              tokopen.tok_line, tokopen.tok_col,
                              "expect tree or selector after !~todo (~");
      int nbargs = 0;
      memset (_.args, 0, sizeof (_.args));
      while (nbargs < TODO_MAXARGS_BM)
        {
          bool gotval = false;
          _.valv =              //
            parsergetvalue_BM (ldpars, CURFRAME_BM, 0, &gotval);
          if (!gotval)
            break;
          _.args[nbargs++] = _.valv;
        };
      parstoken_tyBM tokclose = parsertokenget_BM (ldpars, CURFRAME_BM);
      if (tokclose.tok_kind == plex_DELIM
          && tokclose.tok_delim == delim_exclamand)
        again = true;
      else if (tokclose.tok_kind != plex_DELIM
               || tokclose.tok_delim != delim_tilderightparen)
        parsererrorprintf_BM (ldpars, CURFRAME_BM,
                              parserlineno_BM (ldpars),
                              parsercolpos_BM (ldpars),
                              "expect )~ after !~todo (~ <tree|selector> <%d-arguments> ",
                              nbargs);
      if (gotselector)
        {
          value_tyBM cloargs[3 + TODO_MAXARGS_BM];
          memset (cloargs, 0, sizeof (cloargs));
          cloargs[0] = argcurldobj;
          cloargs[1] = _.obselv;
          for (int ix = 0; ix < nbargs; ix++)
            cloargs[ix + 2] = _.args[ix];
          _.todov =
            (value_tyBM) makeclosure_BM (BMP_todo_send, nbargs + 2, cloargs);
        }
      else if (gottree)
        {
          value_tyBM cloargs[3 + TODO_MAXARGS_BM];
          memset (cloargs, 0, sizeof (cloargs));
          cloargs[0] = (value_tyBM) _.closv;
          cloargs[1] = argcurldobj;
          for (int ix = 0; ix < nbargs; ix++)
            cloargs[ix + 2] = _.args[ix];
          _.todov =
            (value_tyBM) makeclosure_BM (BMP_todo_apply, nbargs + 2, cloargs);
        }
      else
        FATAL_BM ("!~todo unexpected corruption");
      load_addtodo_BM (_.todov);
    }
  while (again);
}                               /* end load_modif_todo_BM */



static void
load_postpone_modif_BM (struct loader_stBM *ld, int ix,
                        struct stackframe_stBM *parstkfrm,
                        struct parser_stBM *ldpars,
                        objectval_tyBM * argcurldobj, const value_tyBM data)
{

  LOCALFRAME_BM (parstkfrm, NULL,       //
                 struct loader_stBM *ld; struct parser_stBM *ldparser;  //
                 objectval_tyBM * curldobj;     //
                 value_tyBM datav;      //
                 const closure_tyBM * clos;);
  ASSERT_BM (ld && ld->ld_magic == LOADERMAGIC_BM);
  ASSERT_BM (ix >= 0 && ix <= (int) ld->ld_maxnum);
  ASSERT_BM (data != NULL);
  unsigned lineno = parserlineno_BM (ldpars);
  unsigned colpos = parsercolpos_BM (ldpars);
  _.ld = ld;
  _.ldparser = ld->ld_parsarr[ix];
  _.curldobj = argcurldobj;
  _.clos = makeclosurevar_BM (BMP_postpone_load_modification,   //_7kMNgL8eJ09_6aEpofzWJDP
                              taggedint_BM (ix),
                              taggedint_BM (lineno),
                              taggedint_BM (colpos), argcurldobj, data, NULL);
  load_addtodo_BM (_.clos);
  for (;;)
    {
      parsernextline_BM (ldpars);
      lineno = parserlineno_BM (ldpars);
      colpos = parsercolpos_BM (ldpars);
      if (parserendoffile_BM (ldpars))
        parsererrorprintf_BM (ldpars, CURFRAME_BM, lineno,
                              colpos, "end of file reached in modification");
      if (ldpars->pars_linebuf[0] == '!' && ldpars->pars_linebuf[1] == ')')
        parsererrorprintf_BM (ldpars, CURFRAME_BM, lineno,
                              colpos,
                              "end of object reached in modification");
      if (ldpars->pars_linebuf[0] == '~' && ldpars->pars_linebuf[1] == ')')
        break;
    }
}                               /* end load_postpone_modif_BM */


static void
load_second_pass_BM (struct loader_stBM *ld, int ix,
                     struct stackframe_stBM *parstkfrm)
{
  ASSERT_BM (ld && ld->ld_magic == LOADERMAGIC_BM);
  ASSERT_BM ((ix >= 0 && ix <= (int) ld->ld_maxnum) || ix == ProjectSp_BM);
  ld->ld_passnum = 2;
  char *curldpath = NULL;
  if (ix >= 0 && ix <= (int) ld->ld_maxnum)
    curldpath = ld->ld_storepatharr[ix];
  else if (ix == ProjectSp_BM)
    curldpath = ld->ld_projectstatepath;
  ld->ld_curspaceix = ix;
  ASSERT_BM (curldpath != NULL);
  FILE *fil = fopen (curldpath, "r");
  if (!fil)
    FATAL_BM ("failed to fopen %s (%m)", curldpath);
  LOCALFRAME_BM (parstkfrm, NULL,       //
                 objectval_tyBM * ldparsownob;  //
                 objectval_tyBM * curldobj;     //
                 objectval_tyBM * attrobj;      //
                 value_tyBM routbuilder;        //
                 union
                 {
                 value_tyBM attrval;    //
                 value_tyBM compval;    //
                 objectval_tyBM * classobj;     //
                 };);
  _.ldparsownob = makeobj_BM ();
  struct parser_stBM *ldpars
    = makeparser_of_file_BM (fil, curldpath, _.ldparsownob);
  ASSERT_BM (ldpars != NULL);
  ld->ld_parsarr[ix] = ldpars;
  ldpars->pars_path = ld->ld_storepatharr[ix];
  ldpars->pars_warnunknownid = true;
  long nbdirectives = 0;
  for (;;)
    {
      parserskipspaces_BM (ldpars, CURFRAME_BM);
      unsigned lineno = parserlineno_BM (ldpars);
      unsigned colpos = parsercolpos_BM (ldpars);
      parstoken_tyBM tok = parsertokenget_BM (ldpars, CURFRAME_BM);
      //
      // !( <oid> or « <oid>  starts a new object
      if (tok.tok_kind == plex_DELIM
          // see STORE_OBJECTOPEN_PREFIX_BM & STORE_OBJECTOPEN_ALTPREFIX_BM
          && (tok.tok_delim == delim_exclamleft
              || tok.tok_delim == delim_dblanglequotleft))
        {
          bool gotldobj = false;
          _.curldobj =          //
            parsergetobject_BM (ldpars, CURFRAME_BM,    //
                                0, &gotldobj);
          if (!gotldobj)
            parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                  lineno, colpos,
                                  "expecting object after !( or «");
          DBGPRINTF_BM ("**!++!** current loaded object %s at %s:%d",
                        objectdbg_BM (_.curldobj), ldpars->pars_path, lineno);
        }
      //
      // !: <attrobj> <attrval> or  ↦  <attrobj> <attrval> adds an attribute and its value
      else if (tok.tok_kind == plex_DELIM
               //STORE_ATTRIBUTE_PREFIX_BM or STORE_ATTRIBUTE_ALTPREFIX_BM
               && (tok.tok_delim == delim_exclamcolon
                   || tok.tok_delim == delim_rightfrombar))
        {
          if (!_.curldobj)
            parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                  lineno, colpos,
                                  STORE_ATTRIBUTE_PREFIX_BM " or "
                                  STORE_ATTRIBUTE_ALTPREFIX_BM
                                  " outside of object");
          bool gotattr = false;
          _.attrobj =           //
            parsergetobject_BM (ldpars, CURFRAME_BM, 0, &gotattr);
          if (!gotattr)
            parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                  lineno, colpos,
                                  "expect attribute object after "
                                  STORE_ATTRIBUTE_PREFIX_BM " or "
                                  STORE_ATTRIBUTE_ALTPREFIX_BM);
          parserskipspaces_BM (ldpars, CURFRAME_BM);
          bool gotval = false;
          _.attrval =           //
            parsergetvalue_BM (ldpars, CURFRAME_BM, 0, &gotval);
          if (!gotval)
            parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                  lineno, colpos,
                                  "expect value of attribute after "
                                  STORE_ATTRIBUTE_PREFIX_BM " or "
                                  STORE_ATTRIBUTE_ALTPREFIX_BM);
          objputattr_BM (_.curldobj, _.attrobj, _.attrval);
          _.attrobj = NULL;
          _.attrval = NULL;
        }
      //
      // !# <size>   reserve space for components
      else if (tok.tok_kind == plex_DELIM
               && tok.tok_delim == delim_exclamhash)
        {
          if (!_.curldobj)
            parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                  lineno, colpos, "!# outside of object");
          parstoken_tyBM tokspa = parsertokenget_BM (ldpars, CURFRAME_BM);
          if (tokspa.tok_kind != plex_LLONG)
            parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                  lineno, colpos, "expecting long after !#");
          unsigned l = tokspa.tok_llong;
          objreservecomps_BM (_.curldobj, l);
        }
      //
      // !& <comp-value> or  ↳ <comp-value> append a component
      else if (tok.tok_kind == plex_DELIM
               // STORE_COMPONENT_PREFIX_BM or STORE_COMPONENT_ALTPREFIX_BM
               && (tok.tok_delim == delim_exclamand
                   || tok.tok_delim == delim_downtipright))
        {
          if (!_.curldobj)
            parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                  lineno, colpos,
                                  STORE_COMPONENT_PREFIX_BM " or "
                                  STORE_COMPONENT_ALTPREFIX_BM
                                  " outside of object");
          bool gotval = false;
          _.compval =           //
            parsergetvalue_BM (ldpars, CURFRAME_BM, 0, &gotval);
          if (!gotval)
            parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                  lineno, colpos,
                                  "expect component value after "
                                  STORE_COMPONENT_PREFIX_BM " or "
                                  STORE_COMPONENT_ALTPREFIX_BM);
          objappendcomp_BM (_.curldobj, _.compval);
          _.compval = NULL;
        }
      //
      // !@ <mtime-dbl> or ± <mtime-dbl> sets the mtime
      else if (tok.tok_kind == plex_DELIM
               // STORE_MODTIME_PREFIX_BM or STORE_MODTIME_ALTPREFIX_BM
               && (tok.tok_delim == delim_exclamat
                   || tok.tok_delim == delim_plusminus))
        {
          if (!_.curldobj)
            parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                  lineno, colpos,
                                  STORE_MODTIME_PREFIX_BM " or "
                                  STORE_MODTIME_ALTPREFIX_BM
                                  " outside of object");
          parstoken_tyBM tokmtim = parsertokenget_BM (ldpars, CURFRAME_BM);
          if (tokmtim.tok_kind != plex_DOUBLE)
            parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                  lineno, colpos,
                                  "expecting double modtime after "
                                  STORE_MODTIME_PREFIX_BM " or "
                                  STORE_MODTIME_ALTPREFIX_BM
                                  ", but got some %s",
                                  lexkindname_BM (tokmtim.tok_kind));
          double t = tokmtim.tok_dbl;
          objtouchmtime_BM (_.curldobj, t);
        }
      //
      // !$<class-obj> or ∈<class-obj> sets the class
      else if (tok.tok_kind == plex_DELIM
               // STORE_CLASS_PREFIX_BM or STORE_CLASS_ALTPREFIX_BM
               && (tok.tok_delim == delim_exclamdollar
                   || tok.tok_delim == delim_element))
        {
          if (!_.curldobj)
            parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                  lineno, colpos,
                                  STORE_CLASS_PREFIX_BM " or "
                                  STORE_CLASS_ALTPREFIX_BM
                                  " outside of object");
          bool gotclass = false;
          _.classobj =          //
            parsergetobject_BM (ldpars, CURFRAME_BM, 0, &gotclass);
          if (!gotclass)
            parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                  lineno, colpos,
                                  "expect [class] object after "
                                  STORE_CLASS_PREFIX_BM " or "
                                  STORE_CLASS_ALTPREFIX_BM);
          objputclass_BM (_.curldobj, _.classobj);
          _.classobj = NULL;
        }
      //
      // !)<oid> or »<oid>  terminates an object
      else if (tok.tok_kind == plex_DELIM
               // see STORE_OBJECTCLOSE_PREFIX_BM & STORE_OBJECTCLOSE_ALTPREFIX_BM
               && (tok.tok_delim == delim_exclamright
                   || tok.tok_delim == delim_dblanglequotright))
        {
          if (!_.curldobj)
            parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                  lineno, colpos,
                                  STORE_OBJECTCLOSE_PREFIX_BM " or "
                                  STORE_OBJECTCLOSE_ALTPREFIX_BM
                                  " outside of object");
          parstoken_tyBM tokid = parsertokenget_BM (ldpars, CURFRAME_BM);
          if (tokid.tok_kind != plex_ID)
            parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                  lineno, colpos,
                                  "expecting id after "
                                  STORE_OBJECTCLOSE_PREFIX_BM " or "
                                  STORE_OBJECTCLOSE_ALTPREFIX_BM);
          if (tokid.tok_id.id_hi
              && !equalid_BM (tokid.tok_id, objid_BM (_.curldobj)))
            {
              char idbuf[32];
              idtocbuf32_BM (objid_BM (_.curldobj), idbuf);
              parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                    lineno, colpos,
                                    "expecting id %s after "
                                    STORE_OBJECTCLOSE_PREFIX_BM " or "
                                    STORE_OBJECTCLOSE_ALTPREFIX_BM, idbuf);

            }
          DBGPRINTF_BM ("**!--!** ending loaded object %s at %s:%d\n\n",
                        objectdbg_BM (_.curldobj), ldpars->pars_path, lineno);
          _.curldobj = NULL;
        }
      //
      // !| or Σ starts a function signature followed by an object or a star
      else if (tok.tok_kind == plex_DELIM && (tok.tok_delim == delim_exclambar  /*STORE_FUNSIGNATURE_ALTPREFIX_BM */
                                              || tok.tok_delim ==
                                              delim_greekcapsigma
                                              /*STORE_FUNSIGNATURE_PREFIX_BM */
               ))
        {
          if (!_.curldobj)
            parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                  lineno, colpos,
                                  STORE_FUNSIGNATURE_PREFIX_BM " or "
                                  STORE_FUNSIGNATURE_ALTPREFIX_BM
                                  " outside of object");
          parstoken_tyBM toksig = parsertokenget_BM (ldpars, CURFRAME_BM);
          if (toksig.tok_kind == plex_DELIM && toksig.tok_delim == delim_star)
            {
              DBGPRINTF_BM (STORE_FUNSIGNATURE_PREFIX_BM " or "
                            STORE_FUNSIGNATURE_ALTPREFIX_BM
                            " followed by * ix#%d line %d for %s", ix,
                            toksig.tok_line, objectdbg_BM (_.curldobj));
              if (!objroutaddr_BM (_.curldobj, BMP_function_sig))
                parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                      lineno, colpos,
                                      "object %s without function_sig has "
                                      STORE_FUNSIGNATURE_PREFIX_BM " or "
                                      STORE_FUNSIGNATURE_ALTPREFIX_BM
                                      " followed by *",
                                      objectdbg_BM (_.curldobj));
            }
          else if (toksig.tok_kind == plex_ID)
            {
              _.attrobj = findobjofid_BM (toksig.tok_id);
              char curidbuf32[32] = "";
              idtocbuf32_BM (_.curldobj->ob_id, curidbuf32);
              char sigidbuf32[32] = "";
              idtocbuf32_BM (toksig.tok_id, sigidbuf32);
              /// temporary code:
              const char *obnam = findobjectname_BM (_.curldobj);
              if (!_.attrobj)
                {
                  parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                        lineno, colpos,
                                        "object %s with "
                                        STORE_FUNSIGNATURE_PREFIX_BM " or "
                                        STORE_FUNSIGNATURE_ALTPREFIX_BM
                                        " with bad function signature",
                                        objectdbg_BM (_.curldobj));
                };
              _.routbuilder = objgetattr_BM (_.attrobj, BMP_routine_builder);
              if (isstring_BM (_.routbuilder))
                {
                  char bufname[80];
                  memset (bufname, 0, sizeof (bufname));
                  char *buf = bufname;
                  if (snprintf
                      (bufname, sizeof (bufname), "%s%s" ROUTINESUFFIX_BM,
                       bytstring_BM (_.routbuilder),
                       curidbuf32) >= (int) sizeof (bufname))
                    {
                      buf = NULL;
                      if (asprintf (&buf, "%s%s" ROUTINESUFFIX_BM,
                                    bytstring_BM (_.routbuilder), curidbuf32))
                        FATAL_BM ("asprintf failure for %s+%s - %m",
                                  bytstring_BM (_.routbuilder), curidbuf32);
                    };
                  DBGPRINTF_BM ("dlsym-ing '%s' in whole program", buf);
                  void *ad = dlsym (dlprog_BM, buf);
                  if (ad)
                    {
                      _.curldobj->ob_rout = ad;
                      _.curldobj->ob_sig = _.attrobj;
                      ld->ld_nbroutines++;
                    }
                  else
                    FATAL_BM
                      ("bad function-sig in file %s:%d, dlsym %s failed in whole program %s",
                       curldpath, lineno, buf, dlerror ());
                  if (buf != bufname)
                    free (buf), buf = NULL;
                }
              //else if (isclosure_BM(_.routbuilder)) {
#warning general signature with !| * unimplemented and routine builder
              //}
              else
                /// we probably should get a prefix from the signature, etc...
                FATAL_BM
                  ("general signature %s with " STORE_FUNSIGNATURE_PREFIX_BM
                   " or " STORE_FUNSIGNATURE_ALTPREFIX_BM
                   " * or Σ for %s unexpected builder", sigidbuf32,
                   obnam ? obnam : curidbuf32);
            }
          else
            {
              char idbuf32[32] = "";
              idtocbuf32_BM (_.curldobj->ob_id, idbuf32);
              const char *obnam = findobjectname_BM (_.curldobj);
              if (obnam)
                parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                      lineno, colpos,
                                      "named object %s/%s with bad "
                                      STORE_FUNSIGNATURE_PREFIX_BM " or "
                                      STORE_FUNSIGNATURE_ALTPREFIX_BM
                                      " * for function signature", obnam,
                                      idbuf32);
              else
                parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                      lineno, colpos,
                                      "anonymous object %s with bad "
                                      STORE_FUNSIGNATURE_PREFIX_BM " or "
                                      STORE_FUNSIGNATURE_ALTPREFIX_BM
                                      " * for function signature", idbuf32);

            }
        }
      //
      // !~ <name> .... start a modification
      else if (tok.tok_kind == plex_DELIM
               && tok.tok_delim == delim_exclamtilde)
        {
          if (!_.curldobj)
            parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                  lineno, colpos, "!~ outside of object");
          parstoken_tyBM tokmodif = parsertokenget_BM (ldpars, CURFRAME_BM);
          /// class modification
          if (tokmodif.tok_kind == plex_NAMEDOBJ
              && tokmodif.tok_namedobj == BMP_class)
            load_modif_class_BM (ld, ix, CURFRAME_BM, ldpars, _.curldobj);
          /// name modification
          else if (tokmodif.tok_kind == plex_NAMEDOBJ
                   && tokmodif.tok_namedobj == BMP_name)
            load_modif_name_BM (ld, ix, CURFRAME_BM, ldpars, _.curldobj);

          /// value modification
          else if (tokmodif.tok_kind == plex_NAMEDOBJ
                   && tokmodif.tok_namedobj == BMP_value)
            load_modif_value_BM (ld, ix, CURFRAME_BM, ldpars, _.curldobj);


          /// todo modification
          else if (tokmodif.tok_kind == plex_NAMEDOBJ
                   && tokmodif.tok_namedobj == BMP_todo)
            load_modif_todo_BM (ld, ix, CURFRAME_BM, ldpars, _.curldobj);

          /// json modification
          else if (tokmodif.tok_kind == plex_NAMEDOBJ
                   && tokmodif.tok_namedobj == BMP_json)
            load_modif_json_BM (ld, ix, CURFRAME_BM, ldpars, _.curldobj);

          //
          // otherwise postponed modification
          else if (tokmodif.tok_kind == plex_NAMEDOBJ)
            {
              load_postpone_modif_BM (ld, ix,
                                      CURFRAME_BM,
                                      ldpars, _.curldobj,
                                      tokmodif.tok_namedobj);
            }
          else if (tokmodif.tok_kind == plex_CNAME)
            {
              load_postpone_modif_BM (ld, ix,
                                      CURFRAME_BM,
                                      ldpars, _.curldobj,
                                      (const value_tyBM) tokmodif.tok_cname);
            }
          else
            parsererrorprintf_BM (ldpars, CURFRAME_BM,
                                  lineno, colpos, "unexpected modification");

        }
      //
      // !^ <modulid> or µ <modulid> has been handled in first pass
      else if (tok.tok_kind == plex_DELIM
               // see STORE_MODULE_PREFIX_BM & STORE_MODULE_ALTPREFIX_BM
               && (tok.tok_delim == delim_exclamcaret
                   || tok.tok_delim == delim_mu))
        {
          parstoken_tyBM tokmodid = parsertokenget_BM (ldpars, CURFRAME_BM);
          ASSERT_BM (tokmodid.tok_kind == plex_ID);
        }

      //
      // eof
      else if (tok.tok_kind == plex__NONE && parserendoffile_BM (ldpars))
        break;
      //
      // otherwise, error
      else
        {
          const char *xtratok = "";
          char xtraid[32] = "";
          if (tok.tok_kind == plex_DELIM)
            xtratok = delimstr_BM (tok.tok_delim);
          else if (tok.tok_kind == plex_ID)
            {
              idtocbuf32_BM (tok.tok_id, xtraid);
              xtratok = xtraid;
            }
          parsererrorprintf_BM (ldpars, CURFRAME_BM, lineno,
                                colpos,
                                "unexpected token (kind %d %s) %s for loader",
                                (int) tok.tok_kind,
                                lexkindname_BM (tok.tok_kind), xtratok);
        }
      nbdirectives++;
    };
  ld->ld_curspaceix = -__LINE__;
  ld->ld_passnum = -__LINE__;
}                               /* end load_second_pass_BM */

////////////////////////////////////////////////////////////////

//// for the closure load_module, explicitly initialized in doload_BM
extern objrout_sigBM ROUTINEOBJNAME_BM (_3j4mbvFJZzA_9ucKetDMbdh);


void
doload_BM (struct stackframe_stBM *_parentframe, struct loader_stBM *ld)
{
  ASSERT_BM (ld && ld->ld_magic == LOADERMAGIC_BM);
  ASSERT_BM (_parentframe != NULL);
  LOCALFRAME_BM (_parentframe, NULL,    //
                 value_tyBM firsttodo;);
  /// run the first pass to create every object
  for (int ix = 1; ix <= (int) ld->ld_maxnum; ix++)
    if (ld->ld_storepatharr[ix])
      load_first_pass_BM (ld, ix);
  if (ld->ld_storepatharr[0])
    load_first_pass_BM (ld, 0);
  if (ld->ld_projectstatepath && !access (ld->ld_projectstatepath, R_OK))
    load_first_pass_BM (ld, ProjectSp_BM);
  /// set the constants
  for (int kix = 0; kix < bmnbconsts; kix++)
    {
      const char *kidstr = bmconstidstrings[kix];
      ASSERT_BM (kidstr != NULL && kidstr[0] == '_');
      rawid_tyBM kid = parse_rawid_BM (kidstr, NULL);
      objectval_tyBM *kobj = findobjofid_BM (kid);
      if (!kobj)
        FATAL_BM ("cannot find constant#%d %s in loaded dir %s", kix,
                  kidstr, ld->ld_dir);
      *(bmconstaddrs[kix]) = kobj;
    }
  /// ensure that BMP_load_module has its routine
  if (BMP_load_module->ob_rout == NULL)
    {
      WARNPRINTF_BM
        ("doload_BM without routine in BMP_load_module of id %s (loading directory %s with %u loaded modules)\n",
         objectdbg_BM (BMP_load_module), ld->ld_dir, module_count_BM ());
      BMP_load_module->ob_rout = ROUTINEOBJNAME_BM (_3j4mbvFJZzA_9ucKetDMbdh);
      BMP_load_module->ob_sig = BMP_function_sig;
    }
  if (ld->ld_count_objrout > 0)
    {
      unsigned nbmodu = module_count_BM ();
      WARNPRINTF_BM
        ("¤doload_BM with %u unsatisfied object routines and %u modules",
         ld->ld_count_objrout, nbmodu);
#warning FIXME: to dlsym again
    }
  /// run the second pass to fill objects
  for (int ix = 1; ix <= (int) ld->ld_maxnum; ix++)
    if (ld->ld_storepatharr[ix])
      load_second_pass_BM (ld, ix, CURFRAME_BM);
  if (ld->ld_storepatharr[0])
    load_second_pass_BM (ld, 0, CURFRAME_BM);
  if (ld->ld_projectstatepath && !access (ld->ld_projectstatepath, R_OK))
    load_second_pass_BM (ld, ProjectSp_BM, CURFRAME_BM);
  /// run the todo list
  long todocnt = 0;
  while (islist_BM (ld->ld_todolist) && listlength_BM (ld->ld_todolist) > 0)
    {
      _.firsttodo = listfirst_BM (ld->ld_todolist);
      ASSERT_BM (isclosure_BM (_.firsttodo) || isobject_BM (_.firsttodo));
      listpopfirst_BM (ld->ld_todolist);
      NONPRINTF_BM ("doload_BM firsttodo %s",
                    debug_outstr_value_BM (_.firsttodo, CURFRAME_BM, 0));
      apply0_BM ((value_tyBM) (_.firsttodo), CURFRAME_BM);
      todocnt++;
      if (todocnt % 128 == 0)
        full_garbage_collection_BM (CURFRAME_BM);
    }
  /// check and load contributors and passwords files
  {
    extern bool debug_after_load_BM;
    bool wasdebug = showdebugmsg_BM;
    if (debug_after_load_BM)
      {
        showdebugmsg_BM = true;
        INFOPRINTF_BM
          ("load force debugging (since --debug-after-load) for contributors and passwords files");
      }
    check_and_load_contributors_file_BM (ld, CURFRAME_BM);
    check_passwords_file_BM (ld, CURFRAME_BM);
    if (debug_after_load_BM && !wasdebug)
      {
        INFOPRINTF_BM
          ("load reset debugging after contributors and passwords files");
        showdebugmsg_BM = false;
      }
  }
  // close all files
  for (int ix = 0; ix <= (int) ld->ld_maxnum; ix++)
    {
      struct parser_stBM *curpars = ld->ld_parsarr[ix];
      if (!curpars)
        continue;
      if (curpars->pars_file)
        fclose (curpars->pars_file), curpars->pars_file = NULL;
      if (curpars->pars_linebuf)
        free (curpars->pars_linebuf), curpars->pars_linebuf = NULL;
      curpars->pars_curbyte = NULL;
      if (curpars->pars_memolines)
        free (curpars->pars_memolines), curpars->pars_memolines = NULL;
      curpars->pars_linesiz = curpars->pars_linelen = 0;
      curpars->pars_memolcount = curpars->pars_memolsize = 0;
      ld->ld_parsarr[ix] = NULL;
    }
  ld->ld_curspaceix = -__LINE__;
  ld->ld_passnum = 0;
}                               /* end doload_BM */


//// for the closure postpone_load_modification 
extern objrout_sigBM ROUTINEOBJNAME_BM (_7kMNgL8eJ09_6aEpofzWJDP);

value_tyBM
ROUTINEOBJNAME_BM (_7kMNgL8eJ09_6aEpofzWJDP)
(struct stackframe_stBM * stkf,
const value_tyBM arg1 __attribute__((unused)),
const value_tyBM arg2 __attribute__((unused)),
const value_tyBM arg3 __attribute__((unused)),
const value_tyBM arg4 __attribute__((unused)),
const quasinode_tyBM * restargs __attribute__((unused)))
{
  enum
  {
    closix_ix,
    closix_lineno,
    closix_colpos,
    closix_curldobj,
    closix_data,
    closix__LAST
  };
  LOCALFRAME_BM (stkf, BMP_postpone_load_modification,  //
                 objectval_tyBM * curldobj;
                 value_tyBM data; closure_tyBM * cclos;);
  LOCALGETFUNV_BM (_.cclos);
  WEAKASSERT_BM (isclosure_BM (_.cclos)
                 && closurewidth_BM ((value_tyBM) _.cclos) >= closix__LAST);
  ASSERT_BM (firstloader_BM != NULL);
  // clos0 is ix
  WEAKASSERT_BM (istaggedint_BM
                 (closurenthson_BM ((const value_tyBM) _.cclos, closix_ix)));
  unsigned ix =
    getint_BM (closurenthson_BM ((const value_tyBM) _.cclos, closix_ix));
  ASSERT_BM (ix < firstloader_BM->ld_maxnum);
  // clos1 is lineno
  WEAKASSERT_BM (istaggedint_BM
                 (closurenthson_BM
                  ((const value_tyBM) _.cclos, closix_lineno)));
  unsigned lineno =
    getint_BM (closurenthson_BM ((const value_tyBM) _.cclos, closix_lineno));
  // clos2 is colpos
  WEAKASSERT_BM (istaggedint_BM
                 (closurenthson_BM
                  ((const value_tyBM) _.cclos, closix_colpos)));
  unsigned colpos =
    getint_BM (closurenthson_BM ((const value_tyBM) _.cclos, closix_colpos));
  // clos3 is curldobj
  WEAKASSERT_BM (isobject_BM
                 (closurenthson_BM
                  ((const value_tyBM) _.cclos, closix_curldobj)));
  _.curldobj = closurenthson_BM ((const value_tyBM) _.cclos, closix_curldobj);
  // clos4 is data (cname or named object)
  _.data = closurenthson_BM ((const value_tyBM) _.cclos, closix_data);
  struct parser_stBM *ldpars = firstloader_BM->ld_parsarr[ix];
  ASSERT_BM (isparser_BM (ldpars));
  if (isobject_BM (_.data))
    {
      char idbuf[32];
      memset (idbuf, 0, sizeof (idbuf));
      idtocbuf32_BM (objid_BM (_.data), idbuf);
      const char *n = findobjectname_BM ((const objectval_tyBM *) _.data);
      if (n)
        parsererrorprintf_BM (ldpars, CURFRAME_BM, lineno,
                              colpos,
                              "unimplemented named load modification %s (%s)",
                              n, idbuf);
      else
        parsererrorprintf_BM (ldpars, CURFRAME_BM, lineno,
                              colpos,
                              "unimplemented anon load modification %s",
                              idbuf);
    }
  else if (isstring_BM (_.data))
    {
      parsererrorprintf_BM (ldpars, CURFRAME_BM, lineno,
                            colpos,
                            "unimplemented string load modification %s",
                            bytstring_BM (_.data));
    }
  else
    parsererrorprintf_BM (ldpars, CURFRAME_BM, lineno,
                          colpos, "unimplemented load modification");
#warning postpone_load_modification unimplemented
}                               // end ROUTINEOBJNAME_BM (_7kMNgL8eJ09_6aEpofzWJDP)  postpone_load_modification 




//// for the closure load_module
extern objrout_sigBM ROUTINEOBJNAME_BM (_3j4mbvFJZzA_9ucKetDMbdh);

// notice that BMP_load_module is _3j4mbvFJZzA_9ucKetDMbdh
value_tyBM
ROUTINEOBJNAME_BM (_3j4mbvFJZzA_9ucKetDMbdh)    // load_module
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1_ __attribute__((unused)),        //
 const value_tyBM arg2_ __attribute__((unused)),        //
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  extern void postpone_loader_module_BM (objectval_tyBM * modulob,
                                         struct stackframe_stBM *stkf);
  LOCALFRAME_BM (stkf, BMP_load_module, //
                 objectval_tyBM * modulob; value_tyBM callingclosv;);
  LOCALGETFUNV_BM (_.callingclosv);
  _.modulob = objectcast_BM (closurenthson_BM (_.callingclosv, 0));
  char modulidbuf[32];
  memset (modulidbuf, 0, sizeof (modulidbuf));
  idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
  DBGPRINTF_BM ("load_module start modulob %s id %s callingclos %s",
                objectdbg_BM (_.modulob), modulidbuf,
                OUTSTRVALUE_BM (_.callingclosv));
  ASSERT_BM (_.modulob);
  postpone_loader_module_BM (_.modulob, CURFRAME_BM);
  DBGPRINTF_BM ("load_module end modulob %s", objectdbg_BM (_.modulob));
  LOCALRETURN_BM (_.modulob);
}                               /* end load_module _3j4mbvFJZzA_9ucKetDMbdh */

/****************
 **                           for Emacs...
 ** Local Variables: ;;
 ** compile-command: "./Build" ;;
 ** End: ;;
 ****************/
/*** end of file load_BM.c ****/
