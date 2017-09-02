// file load_BM.c
#include "bismon.h"

struct loader_stBM *firstloader_BM;

void
loadergcmark_BM (struct garbcoll_stBM *gc, struct loader_stBM *ld)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (valtype_BM ((const value_tyBM) ld) == tydata_loader_BM);
  assert (ld->ld_magic == LOADERMAGIC_BM);
  gcmark_BM (gc, ld->ld_objhset, 0);
  gcmark_BM (gc, ld->ld_modhset, 0);
  gcmark_BM (gc, ld->ld_todolist, 0);
}                               /* end loadergcmark_BM */

void
loadergcdestroy_BM (struct garbcoll_stBM *gc, struct loader_stBM *ld)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (valtype_BM ((const value_tyBM) ld) == tydata_loader_BM);
  assert (ld->ld_magic == LOADERMAGIC_BM);
  fprintf (stderr, "loadergcdestroy_BM called ld @%p\n", (void *) ld);
  memset (ld, 0, sizeof (*ld));
  free (ld);
  gc->gc_freedbytes += sizeof (*ld);
}                               /* end loadergcdestroy_BM */

void
loadergckeep_BM (struct garbcoll_stBM *gc, struct loader_stBM *ld)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (valtype_BM ((const value_tyBM) ld) == tydata_loader_BM);
  assert (ld->ld_magic == LOADERMAGIC_BM);
  fprintf (stderr, "loadergckeep_BM called ld @%p\n", (void *) ld);
  gc->gc_keptbytes += sizeof (struct loader_stBM);
}                               /* end loadergckeep_BM */

static void doload_BM (struct stackframe_stBM *fr, struct loader_stBM *ld);

void
load_initial_BM (const char *ldirpath)
{
  if (!ldirpath)
    ldirpath = ".";
  DIR *ldir = opendir (ldirpath);
  if (!ldir)
    FATAL_BM ("load_initial failed to opendir %s : %m", ldirpath);
  struct dirent *de = NULL;
  char *todopath = NULL;
  int maxnum = 0;
  int nbfiles = 0;
  char *patharr[MAXLOADEDFILES_BM] = { };
  while ((de = readdir (ldir)) != NULL)
    {
      if (!isalpha (de->d_name[0]))
        continue;
      int num = 0;
      int pos = 0;
      if ((sscanf (de->d_name, "store%d.bismon%n", &num, &pos) > 0
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
              // detect store12.bismon and store+12.bismon or store0012.bismon
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
      else if (!strcmp (de->d_name, "store_todo.bismon"))
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
          assert (patharr[0] == NULL);
          patharr[0] = buf;
        }
    }
  closedir (ldir);
  if (maxnum > MAXLOADEDFILES_BM)
    FATAL_BM ("too many store files %d to load", maxnum);
  printf ("got %d store files in loaded directory %s\n", nbfiles, ldirpath);
  struct loader_stBM *ld =      //
    allocgcty_BM (tydata_loader_BM, sizeof (struct loader_stBM));
  // ((typedhead_tyBM *) ld)->htyp = tydata_loader_BM;
  // ((typedhead_tyBM *) ld)->hgc = 0;
  ((typedhead_tyBM *) ld)->rlen = 0;
  ld->ld_magic = LOADERMAGIC_BM;
  ld->ld_maxnum = maxnum;
  ld->ld_objhset =
    hashsetobj_grow_BM (NULL, 2 * BM_NB_PREDEFINED + maxnum * 100);
  ld->ld_modhset = hashsetobj_grow_BM (NULL, 2 * TINYSIZE_BM);
  ld->ld_todolist = makelist_BM ();
  ld->ld_storepatharr = calloc (maxnum + 2, sizeof (void *));
  if (!ld->ld_storepatharr)
    FATAL_BM ("cannot calloc for %d store files (%m)", maxnum);
  for (int ix = 1; ix <= maxnum; ix++)
    {
      char *pa = patharr[ix];
      if (pa)
        ld->ld_storepatharr[ix] = pa;
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
    doload_BM ((struct stackframe_stBM *) &_, ld);
  }
  firstloader_BM = NULL;
  free (ld->ld_dir), ld->ld_dir = NULL;
  for (int ix = 0; ix <= maxnum; ix++)
    {
      free (ld->ld_storepatharr[ix]), ld->ld_storepatharr[ix] = NULL;
      ld->ld_parsarr[ix] = NULL;
    }
  free (ld->ld_storepatharr), ld->ld_storepatharr = NULL;
  free (ld->ld_parsarr), ld->ld_parsarr = NULL;
  ld->ld_objhset = NULL;
  ld->ld_modhset = NULL;
  free (ld->ld_dir), ld->ld_dir = NULL;
  ld->ld_data = NULL;
  ld->ld_maxnum = 0;
  // keep the header of ld
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


static void
load_first_pass_BM (struct loader_stBM *ld, int ix)
{
  assert (ld && ld->ld_magic == LOADERMAGIC_BM);
  assert (ix >= 0 && ix <= (int) ld->ld_maxnum);
  char *curldpath = ld->ld_storepatharr[ix];
  assert (curldpath != NULL);
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
  do
    {
      ssize_t linlen = getline (&linbuf, &linsiz, fil);
      if (linlen < 0)
        {
          if (!feof (fil))
            FATAL_BM ("getline %s:%d failed (%m)", curldpath, lincnt);
          break;
        }
      linbuf[linlen] = (char) 0;
      lincnt++;
      /* object definition lines are !(<id> e.g. !*_7D8xcWnEiys_8oqOVSkCxkA */
      if (linbuf[0] == '!' && linbuf[1] == '('
          && linbuf[2] == '_' && isdigit (linbuf[3]))
        {
          const char *endid = NULL;
          rawid_tyBM id = parse_rawid_BM (linbuf + 2, &endid);
          if (hashid_BM (id) && endid >= linbuf + 2 * SERIALDIGITS_BM
              && (*endid == (char) 0 || isspace (*endid)))
            {
              objectval_tyBM *newobj = makeobjofid_BM (id);
              if (!newobj->ob_space)
                objputspacenum_BM (newobj, ix);
              char idbuf32[32] = "";
              idtocbuf32_BM (id, idbuf32);
              if (hashsetobj_contains_BM (ld->ld_objhset, newobj))
                {
                  FATAL_BM ("duplicate id %s near %s:%d", idbuf32, curldpath,
                            lincnt);
                };
              // if there is a routine for that object, bind it now
              char symbuf[48];
              memset (symbuf, 0, sizeof (symbuf));
              snprintf (symbuf, sizeof (symbuf),        //
                        ROUTINEOBJPREFIX_BM "%s" ROUTINEOBJSUFFIX_BM,
                        idbuf32);
              void *ad = dlsym (dlprog_BM, symbuf);
              if (ad)
                {
                  newobj->ob_rout = ad;
                  nbrout++;
                };
              ld->ld_objhset = hashsetobj_add_BM (ld->ld_objhset, newobj);
              nbobjdef++;
            }
          else
            FATAL_BM ("invalid object definition line %s in file %s:%d",
                      linbuf, curldpath, lincnt);
        }
      //
      /* module requirement lines are !^<mod-id> */
      else if (linbuf[0] == '!' && linbuf[1] == '^'
               && linbuf[2] == '_' && isdigit (linbuf[3]))
        {
          const char *endid = NULL;
          rawid_tyBM modid = parse_rawid_BM (linbuf + 2, &endid);
          if (hashid_BM (modid) && endid >= linbuf + 2 * SERIALDIGITS_BM
              && (*endid == (char) 0 || isspace (*endid)))
            {
              if (!openmoduleforloader_BM (modid, ld, NULL))
                FATAL_BM ("loader failed to open module for %s", linbuf);
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
  if (nbrout > 0)
    {
      fprintf (stderr, "load first pass #%d: %s found %d routines\n", ix,
               curldpath, nbrout);
    };
}                               /* end load_first_pass_BM */

static void
load_modif_class_BM (struct loader_stBM *ld, int ix,
                     struct stackframe_stBM *parstkfrm,
                     struct parser_stBM *ldpars, objectval_tyBM * argcurldobj)
{
  assert (ld && ld->ld_magic == LOADERMAGIC_BM);
  assert (ix >= 0 && ix <= (int) ld->ld_maxnum);
  char *curldpath = ld->ld_storepatharr[ix];
  assert (curldpath != NULL);
  assert (ldpars != NULL);
  assert (isobject_BM (argcurldobj));
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
  parstoken_tyBM tokopen = parsertokenget_BM (ldpars);
  if (tokopen.tok_kind != plex_DELIM
      || tokopen.tok_delim != delim_leftparentilde)
    parsererrorprintf_BM (ldpars, lineno, colpos,
                          "expecting (~ after !~class");
  bool gotsuper = false;
  _.superclassobj =             //
    parsergetobject_BM          //
    (ldpars,                    //
     (struct stackframe_stBM *) &_,     //
     0, &gotsuper);
  if (!gotsuper)
    parsererrorprintf_BM (ldpars, lineno, colpos,
                          "expecting <superclass> after !~ class (~");
  objputclassinfo_BM (_.curldobj, _.superclassobj);
  parstoken_tyBM toknext = EMPTY_TOKEN_BM;
  unsigned nextlineno = 0;
  unsigned nextcolpos = 0;
  for (;;)
    {
      nextlineno = parserlineno_BM (ldpars);
      nextcolpos = parsercolpos_BM (ldpars);
      toknext = parsertokenget_BM (ldpars);
      if (toknext.tok_kind != plex_DELIM
          || toknext.tok_delim != delim_tildecolon)
        break;
      bool gotselectorobj = false;
      _.selectorobj =           //
        parsergetobject_BM      //
        (ldpars,                //
         (struct stackframe_stBM *) &_, //
         0, &gotselectorobj);
      if (!gotselectorobj || !_.selectorobj)
        parsererrorprintf_BM    //
          (ldpars, nextlineno, nextcolpos,
           "expecting <selector> after ~: in class modification");
      bool gotmethodv = false;
      _.methodv =               //
        parsergetvalue_BM (ldpars, (struct stackframe_stBM *) (&_),
                           0, &gotmethodv);
      if (!gotmethodv || valtype_BM (_.methodv) != tyClosure_BM)
        parsererrorprintf_BM (ldpars, nextlineno, nextcolpos,
                              "expect method closure");
      objclassinfoputmethod_BM (_.curldobj, _.selectorobj,
                                (const closure_tyBM *) (_.methodv));
    }
  if (toknext.tok_kind != plex_DELIM
      || toknext.tok_delim != delim_tilderightparen)
    parsererrorprintf_BM (ldpars, nextlineno, nextcolpos,
                          "expect ~) ending class modification");
}                               /* end load_modif_class_BM */


static void
load_modif_name_BM (struct loader_stBM *ld, int ix,
                    struct stackframe_stBM *parstkfrm,
                    struct parser_stBM *ldpars, objectval_tyBM * argcurldobj)
{
  assert (ld && ld->ld_magic == LOADERMAGIC_BM);
  assert (ix >= 0 && ix <= (int) ld->ld_maxnum);
  char *curldpath = ld->ld_storepatharr[ix];
  assert (curldpath != NULL);
  assert (ldpars != NULL);
  assert (isobject_BM (argcurldobj));
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
  parstoken_tyBM tokopen = parsertokenget_BM (ldpars);
  if (tokopen.tok_kind != plex_DELIM
      || tokopen.tok_delim != delim_leftparentilde)
    parsererrorprintf_BM (ldpars, lineno, colpos,
                          "expecting (~ after !~name");
  parstoken_tyBM tokname = parsertokenget_BM (ldpars);
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
    parsererrorprintf_BM (ldpars, lineno, colpos,
                          "expecting cname or namedobj after !~name (~");
  assert (namestr != NULL);
  const char *oldname = findobjectname_BM (_.curldobj);
  if (oldname && strcmp (oldname, namestr))
    {
      char idbuf[32];
      memset (idbuf, 0, sizeof (idbuf));
      idtocbuf32_BM (_.curldobj->ob_id, idbuf);
      parsererrorprintf_BM (ldpars, lineno, colpos,
                            "already named '%s' object %s cannot get new name '%s'",
                            oldname, idbuf, namestr);
    };
  registername_BM (_.curldobj, namestr);
  parstoken_tyBM tokclose = parsertokenget_BM (ldpars);
  if (tokclose.tok_kind != plex_DELIM
      || tokclose.tok_delim != delim_tilderightparen)
    parsererrorprintf_BM (ldpars, lineno, colpos,
                          "expecting ~) ending !~name");
}                               /* end load_modif_name_BM */


static void
load_postpone_modif_BM (struct loader_stBM *ld, int ix,
                        struct stackframe_stBM *parstkfrm,
                        struct parser_stBM *ldpars,
                        objectval_tyBM * argcurldobj, const value_tyBM data)
{

  LOCALFRAME_BM (parstkfrm, NULL,       //
                 struct loader_stBM *ld;
                 struct parser_stBM *ldparser;  //
                 objectval_tyBM * curldobj;     //
                 value_tyBM datav;      //
                 const closure_tyBM * clos;
    );
  assert (ld && ld->ld_magic == LOADERMAGIC_BM);
  assert (ix >= 0 && ix <= (int) ld->ld_maxnum);
  assert (data != NULL);
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
        parsererrorprintf_BM (ldpars, lineno, colpos,
                              "end of file reached in modification");
      if (ldpars->pars_linebuf[0] == '!' && ldpars->pars_linebuf[1] == ')')
        parsererrorprintf_BM (ldpars, lineno, colpos,
                              "end of object reached in modification");
      if (ldpars->pars_linebuf[0] == '~' && ldpars->pars_linebuf[1] == ')')
        break;
    }
}                               /* end load_postpone_modif_BM */


static void
load_second_pass_BM (struct loader_stBM *ld, int ix,
                     struct stackframe_stBM *parstkfrm)
{
  assert (ld && ld->ld_magic == LOADERMAGIC_BM);
  assert (ix >= 0 && ix <= (int) ld->ld_maxnum);
  char *curldpath = ld->ld_storepatharr[ix];
  assert (curldpath != NULL);
  fprintf (stderr, "load_second_pass_BM ix=%d path=%s incomplete\n",
           ix, curldpath);
  FILE *fil = fopen (curldpath, "r");
  if (!fil)
    FATAL_BM ("failed to fopen %s (%m)", curldpath);
  LOCALFRAME_BM (parstkfrm, NULL,       //
                 struct parser_stBM *ldparser; objectval_tyBM * curldobj;
                 objectval_tyBM * attrobj;
                 union
                 {
                 value_tyBM attrval; value_tyBM compval;
                 objectval_tyBM * classobj;
                 };
    );
  struct parser_stBM *ldpars = _.ldparser = makeparser_of_file_BM (fil);
  assert (ldpars != NULL);
  ld->ld_parsarr[ix] = ldpars;
  ldpars->pars_path = ld->ld_storepatharr[ix];
  long nbdirectives = 0;
  for (;;)
    {
      parserskipspaces_BM (ldpars);
      unsigned lineno = parserlineno_BM (ldpars);
      unsigned colpos = parsercolpos_BM (ldpars);
      parstoken_tyBM tok = parsertokenget_BM (ldpars);
      //
      // !( <id>   starts a new object
      if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_exclamleft)
        {
          bool gotldobj = false;
          _.curldobj =          //
            parsergetobject_BM  //
            (ldpars,            //
             (struct stackframe_stBM *) &_,     //
             0, &gotldobj);
          if (!gotldobj)
            parsererrorprintf_BM (ldpars, lineno, colpos,
                                  "expecting object after !(");
        }
      //
      // !: <attrobj> <attrval>   adds an attribute and its value
      else if (tok.tok_kind == plex_DELIM
               && tok.tok_delim == delim_exclamcolon)
        {
          if (!_.curldobj)
            parsererrorprintf_BM (ldpars, lineno, colpos,
                                  "!: outside of object");
          bool gotattr = false;
          _.attrobj =           //
            parsergetobject_BM (ldpars, (struct stackframe_stBM *) (&_),
                                0, &gotattr);
          if (!gotattr)
            parsererrorprintf_BM (ldpars, lineno, colpos,
                                  "expect attribute object after !:");
          parserskipspaces_BM (ldpars);
          bool gotval = false;
          _.attrval =           //
            parsergetvalue_BM (ldpars, (struct stackframe_stBM *) (&_),
                               0, &gotval);
          if (!gotval)
            parsererrorprintf_BM (ldpars, lineno, colpos,
                                  "expect value of attribute after !:");
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
            parsererrorprintf_BM (ldpars, lineno, colpos,
                                  "!# outside of object");
          parstoken_tyBM tokspa = parsertokenget_BM (ldpars);
          if (tokspa.tok_kind != plex_LLONG)
            parsererrorprintf_BM (ldpars, lineno, colpos,
                                  "expecting long after !#");
          unsigned l = tokspa.tok_llong;
          objreservecomps_BM (_.curldobj, l);
        }
      //
      // !& <comp-value>   append a component
      else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_exclamand)
        {
          if (!_.curldobj)
            parsererrorprintf_BM (ldpars, lineno, colpos,
                                  "!& outside of object");
          bool gotval = false;
          _.compval =           //
            parsergetvalue_BM (ldpars, (struct stackframe_stBM *) (&_),
                               0, &gotval);
          if (!gotval)
            parsererrorprintf_BM (ldpars, lineno, colpos,
                                  "expect component value after !&");
          objappendcomp_BM (_.curldobj, _.compval);
          _.compval = NULL;
        }
      //
      // !@ <mtime-dbl>  sets the mtime
      else if (tok.tok_kind == plex_DELIM && tok.tok_delim == delim_exclamat)
        {
          if (!_.curldobj)
            parsererrorprintf_BM (ldpars, lineno, colpos,
                                  "!@ outside of object");
          parstoken_tyBM tokmtim = parsertokenget_BM (ldpars);
          if (tokmtim.tok_kind != plex_DOUBLE)
            parsererrorprintf_BM (ldpars, lineno, colpos,
                                  "expecting double after !@");
          double t = tokmtim.tok_dbl;
          objtouchmtime_BM (_.curldobj, t);
        }
      //
      // !$ <class-obj>  sets the class
      else if (tok.tok_kind == plex_DELIM
               && tok.tok_delim == delim_exclamdollar)
        {
          if (!_.curldobj)
            parsererrorprintf_BM (ldpars, lineno, colpos,
                                  "!$ outside of object");
          bool gotclass = false;
          _.classobj =          //
            parsergetobject_BM (ldpars, (struct stackframe_stBM *) (&_),
                                0, &gotclass);
          if (!gotclass)
            parsererrorprintf_BM (ldpars, lineno, colpos,
                                  "expect [class] object after !$");
          objputclass_BM (_.curldobj, _.classobj);
          _.classobj = NULL;
        }
      //
      // !) <id>   terminates an object
      else if (tok.tok_kind == plex_DELIM
               && tok.tok_delim == delim_exclamright)
        {
          if (!_.curldobj)
            parsererrorprintf_BM (ldpars, lineno, colpos,
                                  "!) outside of object");
          parstoken_tyBM tokid = parsertokenget_BM (ldpars);
          if (tokid.tok_kind != plex_ID)
            parsererrorprintf_BM (ldpars, lineno, colpos,
                                  "expecting id after !)");
          if (tokid.tok_id.id_hi
              && !equalid_BM (tokid.tok_id, objid_BM (_.curldobj)))
            {
              char idbuf[32];
              idtocbuf32_BM (objid_BM (_.curldobj), idbuf);
              parsererrorprintf_BM (ldpars, lineno, colpos,
                                    "expecting id %s after !)", idbuf);

            }
          _.curldobj = NULL;
        }
      //
      // !~ <name> .... start a modification
      else if (tok.tok_kind == plex_DELIM
               && tok.tok_delim == delim_exclamtilde)
        {
          if (!_.curldobj)
            parsererrorprintf_BM (ldpars, lineno, colpos,
                                  "!~ outside of object");
          parstoken_tyBM tokmodif = parsertokenget_BM (ldpars);
          /// class modification
          if (tokmodif.tok_kind == plex_NAMEDOBJ
              && tokmodif.tok_namedobj == BMP_class)
            load_modif_class_BM (ld, ix,
                                 (struct stackframe_stBM *) (&_),
                                 ldpars, _.curldobj);
          /// name modification
          else if (tokmodif.tok_kind == plex_NAMEDOBJ
                   && tokmodif.tok_namedobj == BMP_name)
            load_modif_name_BM (ld, ix,
                                (struct stackframe_stBM *) (&_),
                                ldpars, _.curldobj);
          //
          else if (tokmodif.tok_kind == plex_NAMEDOBJ)
            {
              load_postpone_modif_BM (ld, ix,
                                      (struct stackframe_stBM *) (&_),
                                      ldpars, _.curldobj,
                                      tokmodif.tok_namedobj);
            }
          else if (tokmodif.tok_kind == plex_CNAME)
            {
              load_postpone_modif_BM (ld, ix,
                                      (struct stackframe_stBM *) (&_),
                                      ldpars, _.curldobj,
                                      (const value_tyBM) tokmodif.tok_cname);
            }
          else
            parsererrorprintf_BM (ldpars, lineno, colpos,
                                  "unexpected modification");

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
          parsererrorprintf_BM (ldpars, lineno, colpos,
                                "unexpected token (kind %d %s) %s for loader",
                                (int) tok.tok_kind,
                                lexkindname_BM (tok.tok_kind), xtratok);
        }
      nbdirectives++;
    };
  fprintf (stderr, "load_second_pass_BM ix=%d path=%s nbdirectives=%ld\n",
           ix, curldpath, nbdirectives);
#warning should parse for loading
}                               /* end load_second_pass_BM */

void
doload_BM (struct stackframe_stBM *_parentframe, struct loader_stBM *ld)
{
  assert (ld && ld->ld_magic == LOADERMAGIC_BM);
  assert (_parentframe != NULL);
  LOCALFRAME_BM (_parentframe, NULL, value_tyBM firsttodo;
    );
  /// run the first pass to create every object
  for (int ix = 1; ix <= (int) ld->ld_maxnum; ix++)
    if (ld->ld_storepatharr[ix])
      load_first_pass_BM (ld, ix);
  if (ld->ld_storepatharr[0])
    load_first_pass_BM (ld, 0);
  /// run the second pass to fill objects
  for (int ix = 1; ix <= (int) ld->ld_maxnum; ix++)
    if (ld->ld_storepatharr[ix])
      load_second_pass_BM (ld, ix, _parentframe);
  if (ld->ld_storepatharr[0])
    load_second_pass_BM (ld, 0, _parentframe);
  /// run the todo list
  long todocnt = 0;
  while (islist_BM (ld->ld_todolist) && listlength_BM (ld->ld_todolist) > 0)
    {
      _.firsttodo = listfirst_BM (ld->ld_todolist);
      assert (isclosure_BM (_.firsttodo));
      listpopfirst_BM (ld->ld_todolist);
      apply0_BM ((const closure_tyBM *) (_.firsttodo),
                 (struct stackframe_stBM *) &_);
      todocnt++;
      if (todocnt % 128 == 0)
        fullgarbagecollection_BM ((struct stackframe_stBM *) &_);
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
}                               /* end doload_BM */


//// for the closure postpone_load_modification 
extern objrout_sigBM ROUTINEOBJNAME_BM (_7kMNgL8eJ09_6aEpofzWJDP);

value_tyBM
ROUTINEOBJNAME_BM (_7kMNgL8eJ09_6aEpofzWJDP)
(const closure_tyBM * clos,
struct stackframe_stBM * stkf,
const value_tyBM arg1 __attribute__ ((unused)),
const value_tyBM arg2 __attribute__ ((unused)),
const value_tyBM arg3 __attribute__ ((unused)),
const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM (stkf, BMP_postpone_load_modification,  //
                 objectval_tyBM * curldobj;
                 value_tyBM data;
    );
  assert (closurewidth_BM ((value_tyBM) clos) >= 5);
  assert (firstloader_BM != NULL);
  // clos0 is ix
  assert (istaggedint_BM (closurenthson_BM ((const value_tyBM) clos, 0)));
  unsigned ix = getint_BM (closurenthson_BM ((const value_tyBM) clos, 0));
  assert (ix < firstloader_BM->ld_maxnum);
  // clos1 is lineno
  assert (istaggedint_BM (closurenthson_BM ((const value_tyBM) clos, 1)));
  unsigned lineno = getint_BM (closurenthson_BM ((const value_tyBM) clos, 1));
  // clos2 is colpos
  assert (istaggedint_BM (closurenthson_BM ((const value_tyBM) clos, 2)));
  unsigned colpos = getint_BM (closurenthson_BM ((const value_tyBM) clos, 2));
  // clos3 is curldobj
  assert (isobject_BM (closurenthson_BM ((const value_tyBM) clos, 3)));
  _.curldobj = closurenthson_BM ((const value_tyBM) clos, 3);
  // clos4 is data (cname or named object)
  _.data = closurenthson_BM ((const value_tyBM) clos, 4);
  struct parser_stBM *ldpars = firstloader_BM->ld_parsarr[ix];
  assert (isparser_BM (ldpars));
  if (isobject_BM (_.data))
    {
      char idbuf[32];
      memset (idbuf, 0, sizeof (idbuf));
      idtocbuf32_BM (objid_BM (_.data), idbuf);
      const char *n = findobjectname_BM ((const objectval_tyBM *) _.data);
      if (n)
        parsererrorprintf_BM (ldpars, lineno, colpos,
                              "unimplemented named load modification %s (%s)",
                              n, idbuf);
      else
        parsererrorprintf_BM (ldpars, lineno, colpos,
                              "unimplemented anon load modification %s",
                              idbuf);
    }
  else if (isstring_BM (_.data))
    {
      parsererrorprintf_BM (ldpars, lineno, colpos,
                            "unimplemented string load modification %s",
                            bytstring_BM (_.data));
    }
  else
    parsererrorprintf_BM (ldpars, lineno, colpos,
                          "unimplemented load modification");
#warning postpone_load_modification unimplemented
}                               // end ROUTINEOBJNAME_BM (_7kMNgL8eJ09_6aEpofzWJDP)  postpone_load_modification 
