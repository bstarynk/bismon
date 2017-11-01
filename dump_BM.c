// file dump_BM.c
#include "bismon.h"

void
dumpgcmark_BM (struct garbcoll_stBM *gc, struct dumper_stBM *du)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) du)->htyp == tydata_dumper_BM);
  gcmark_BM (gc, (value_tyBM) du->dump_object, 0);
  gcmark_BM (gc, (value_tyBM) du->dump_dir, 0);
  gcmark_BM (gc, (value_tyBM) du->dump_hset, 0);
  gcmark_BM (gc, (value_tyBM) du->dump_scanlist, 0);
  gcmark_BM (gc, (value_tyBM) du->dump_todolist, 0);
}                               /* end dumpgcmark_BM */

void
dumpgcdestroy_BM (struct garbcoll_stBM *gc, struct dumper_stBM *du)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) du)->htyp == tydata_dumper_BM);
}                               /* end dumpgcdestroy_BM */

void
dumpgckeep_BM (struct garbcoll_stBM *gc, struct dumper_stBM *du)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) du)->htyp == tydata_dumper_BM);
}                               /* end dumpgckeep_BM */

bool
dumpobjisdumpable_BM (struct dumper_stBM *du, const objectval_tyBM * obj)
{
  if (valtype_BM ((const value_tyBM) du) != tydata_dumper_BM)
    return false;
  if (!isobject_BM ((const value_tyBM) obj))
    return false;
  return hashsetobj_contains_BM (du->dump_hset, obj);
}                               /* end dumpobjisdumpable_BM */

bool
dumpvalisdumpable_BM (struct dumper_stBM * du, const value_tyBM val)
{
  if (valtype_BM ((const value_tyBM) du) != tydata_dumper_BM)
    return false;
  if (val && !isobject_BM (val))
    return true;
  return dumpobjisdumpable_BM (du, (const objectval_tyBM *) val);
}                               /* end dumpvalisdumpable_BM */

void
dumpscanobj_BM (struct dumper_stBM *du, const objectval_tyBM * obj)
{
  if (valtype_BM ((const value_tyBM) du) != tydata_dumper_BM)
    return;
  if (!isobject_BM ((const value_tyBM) obj))
    return;
  if (du->dump_state != dum_scan)
    return;
  if (objspacenum_BM (obj) >= LASTSPACE__BM)
    {
      char idbuf[32];
      idtocbuf32_BM (objid_BM (obj), idbuf);
      FATAL_BM ("invalid space for object@%p %s", obj, idbuf);
    };
  if (objspacenum_BM (obj) == TransientSp_BM)
    return;
  if (hashsetobj_contains_BM (du->dump_hset, obj))
    return;
  du->dump_hset = hashsetobj_add_BM (du->dump_hset, obj);
  listappend_BM (du->dump_scanlist, (value_tyBM) obj);
}                               /* end dumpscanobj_BM */


void
dumpscanvalue_BM (struct dumper_stBM *du, const value_tyBM val, int depth)
{
  if (valtype_BM ((const value_tyBM) du) != tydata_dumper_BM)
    return;
  if (depth > MAXDEPTHGC_BM)
    FATAL_BM ("too deep depth %d", depth);
  int ty = valtype_BM ((const value_tyBM) val);
  switch (ty)
    {
    case tySet_BM:
    case tyTuple_BM:
      {
        unsigned siz = ((typedsize_tyBM *) val)->size;
        for (int ix = (int)siz - 1; ix >= 0; ix--)
          dumpscanobj_BM (du, ((seqobval_tyBM *) val)->seq_objs[ix]);
      }
      break;
    case tyNode_BM:
    case tyClosure_BM:
      {
        const tree_tyBM *tree = (const tree_tyBM *) val;
        dumpscanobj_BM (du, tree->nodt_conn);
        if (!dumpobjisdumpable_BM (du, tree->nodt_conn))
          return;
        unsigned siz = ((typedsize_tyBM *) val)->size;
        for (int ix = (int)siz - 1; ix >= 0; ix--)
          dumpscanvalue_BM (du, tree->nodt_sons[ix], depth + 1);
      }
      break;
    case tyObject_BM:
      dumpscanobj_BM (du, (const objectval_tyBM *) val);
      break;
    default:
      return;
    }
}                               /* end dumpscanvalue_BM */

static void
dump_run_todo_BM (struct dumper_stBM *du, struct stackframe_stBM *stkf);

static void
dump_scan_pass_BM (struct dumper_stBM *du, struct stackframe_stBM *stkf);

static void
dump_emit_pass_BM (struct dumper_stBM *du, struct stackframe_stBM *stkf);



struct dumpinfo_stBM
dump_BM (const char *dirname, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 struct dumper_stBM *curdu; objectval_tyBM * duobj;
                 const stringval_tyBM * dudirv;
    );
  if (!dirname || dirname[0] == (char) 0)
    dirname = ".";
  fprintf (stderr, "start dumping into %s\n", dirname);
  if (g_mkdir_with_parents (dirname, 0750))
    FATAL_BM ("failed to mkdir with parents %s", dirname);
  _.dudirv = makestring_BM (dirname);
  _.curdu = allocgcty_BM (tydata_dumper_BM, sizeof (struct dumper_stBM));
  _.curdu->dump_state = dum_scan;
  _.curdu->dump_dir = _.dudirv;
  _.curdu->dump_hset = hashsetobj_grow_BM (NULL, 256);
  _.curdu->dump_randomid = randomid_BM ();
  _.curdu->dump_scanlist = makelist_BM ();
  _.curdu->dump_todolist = makelist_BM ();
  _.curdu->dump_startelapsedtime = elapsedtime_BM ();
  _.curdu->dump_startcputime = cputime_BM ();
  _.duobj = makeobj_BM ();
  _.duobj->ob_data = _.curdu;
  _.curdu->dump_object = _.duobj;
  dump_scan_pass_BM (_.curdu, (struct stackframe_stBM *) &_);
  dump_run_todo_BM (_.curdu, (struct stackframe_stBM *) &_);
  garbage_collect_if_wanted_BM ((struct stackframe_stBM *) &_);
  dump_emit_pass_BM (_.curdu, (struct stackframe_stBM *) &_);
  garbage_collect_if_wanted_BM ((struct stackframe_stBM *) &_);
  dump_run_todo_BM (_.curdu, (struct stackframe_stBM *) &_);
  garbage_collect_if_wanted_BM ((struct stackframe_stBM *) &_);
  struct dumpinfo_stBM di;
  memset (&di, 0, sizeof (di));
  di.dumpinfo_scanedobjectcount = _.curdu->dump_scanedobjectcount;
  di.dumpinfo_emittedobjectcount = _.curdu->dump_emittedobjectcount;
  di.dumpinfo_todocount = _.curdu->dump_todocount;
  di.dumpinfo_wrotefilecount = _.curdu->dump_wrotefilecount;
  di.dumpinfo_elapsedtime =
    elapsedtime_BM () - _.curdu->dump_startelapsedtime;
  di.dumpinfo_cputime = cputime_BM () - _.curdu->dump_startcputime;
  return di;
}                               /* end dump_BM */


void
dump_run_todo_BM (struct dumper_stBM *du, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 struct dumper_stBM *curdu;
                 const closure_tyBM * curclo;
    );
  assert (valtype_BM ((const value_tyBM) du) == tydata_dumper_BM);
  _.curdu = du;
  while (listlength_BM (du->dump_todolist) > 0)
    {
      _.curclo = listfirst_BM (du->dump_todolist);
      listpopfirst_BM (du->dump_todolist);
      if (isclosure_BM ((const value_tyBM) _.curclo))
        {
          apply1_BM (_.curclo, (struct stackframe_stBM *) &_, du);
          du->dump_todocount++;
        }
    }
}                               /* end dump_run_todo_BM */



static void
dump_scan_object_content_BM (struct dumper_stBM *du,
                             const objectval_tyBM * objarg,
                             struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 struct dumper_stBM *curdu;     //
                 const objectval_tyBM * curobj; //
                 const setval_tyBM * setattrs;  //
                 const objectval_tyBM * curattrobj;
                 value_tyBM curval;
    );
  assert (valtype_BM ((const value_tyBM) du) == tydata_dumper_BM);
  assert (valtype_BM ((const value_tyBM) objarg) == tyObject_BM);
  _.curdu = du;
  _.curobj = objarg;
  // scan the class
  _.curattrobj = objclass_BM (_.curobj);
  if (_.curattrobj)
    dumpscanobj_BM (_.curdu, _.curattrobj);
  // scan the signature
  _.curattrobj = objsignature_BM (_.curobj);
  if (_.curattrobj && objarg->ob_routaddr)
    dumpscanobj_BM (_.curdu, _.curattrobj);
  // scan the attributes and their values
  _.curattrobj = NULL;
  _.setattrs = objsetattrs_BM ((objectval_tyBM *) _.curobj);
  unsigned nbattrs = objnbattrs_BM ((objectval_tyBM *) _.curobj);
  assert (nbattrs == setcardinal_BM (_.setattrs));
  for (int ix = 0; ix < (int) nbattrs; ix++)
    {
      _.curattrobj = setelemnth_BM (_.setattrs, ix);
      dumpscanobj_BM (_.curdu, _.curattrobj);
      if (!dumpobjisdumpable_BM (_.curdu, _.curattrobj))
        continue;
      _.curval =
        objgetattr_BM ((objectval_tyBM *) _.curobj,
                       (objectval_tyBM *) _.curattrobj);
      dumpscanvalue_BM (_.curdu, _.curval, 0);
      _.curattrobj = NULL;
      _.curval = NULL;
    };
  _.setattrs = NULL;
  // scan the components
  unsigned nbcomps = objnbcomps_BM ((objectval_tyBM *) _.curobj);
  for (int ix = 0; ix < (int) nbcomps; ix++)
    {
      _.curval = objgetcomp_BM ((objectval_tyBM *) _.curobj, ix);
      dumpscanvalue_BM (_.curdu, _.curval, 0);

      _.curval = NULL;
    }
  // perhaps we should send first, and use its result...
  if (_.curobj->ob_data)
    send1_BM ((value_tyBM) _.curobj, BMP_dump_scan,
              (struct stackframe_stBM *) &_, du);
  du->dump_scanedobjectcount++;
}                               /* end dump_scan_object_content_BM   */


static void
dump_scan_pass_BM (struct dumper_stBM *du, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 struct dumper_stBM *curdu;     //
                 const setval_tyBM * predefset; //
                 const setval_tyBM * globalset; //
                 const objectval_tyBM * curobj;
    );
  _.curdu = du;
  assert (valtype_BM ((const value_tyBM) du) == tydata_dumper_BM);
  _.predefset = setpredefinedobjects_BM ();
  _.globalset = setglobalobjects_BM ();
  dumpscanvalue_BM (du, (value_tyBM) _.predefset, 0);
  dumpscanvalue_BM (du, (value_tyBM) _.globalset, 0);
  while (listlength_BM (du->dump_scanlist) > 0)
    {
      _.curobj = listfirst_BM (du->dump_scanlist);
      listpopfirst_BM (du->dump_scanlist);
      dump_scan_object_content_BM (du, _.curobj,
                                   (struct stackframe_stBM *) &_);
      if (du->dump_scanedobjectcount > 0
          && du->dump_scanedobjectcount % 32 == 0)
        garbage_collect_if_wanted_BM ((struct stackframe_stBM *) &_);
    }
}                               /* end dump_scan_pass_BM */


static void
dump_emit_space_BM (struct dumper_stBM *du, unsigned spix,
                    struct hashsetobj_stBM *hspa,
                    struct stackframe_stBM *stkf);

void
dump_emit_pass_BM (struct dumper_stBM *du, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 struct dumper_stBM *curdu;     //
                 const objectval_tyBM * curobj; //
                 struct hashsetobj_stBM *hsetspace[LASTSPACE__BM];
    );
  _.curdu = du;
  assert (valtype_BM ((const value_tyBM) du) == tydata_dumper_BM);
  for (unsigned spix = PredefSp_BM; spix < LASTSPACE__BM; spix++)
    _.hsetspace[spix] = hashsetobj_grow_BM (NULL, 80);
  struct hashsetobj_stBM *dhset = du->dump_hset;
  assert (valtype_BM ((const value_tyBM) dhset) == tydata_hashsetobj_BM);
  {
    unsigned alsiz = ((typedhead_tyBM *) dhset)->rlen;
    for (unsigned ix = 0; ix < alsiz; ix++)
      {
        objectval_tyBM *curduob = dhset->hashset_objs[ix];
        if (!curduob || curduob == HASHSETEMPTYSLOT_BM)
          continue;
        _.curobj = curduob;
        int cursp = objspacenum_BM (curduob);
        assert (cursp >= PredefSp_BM && cursp < LASTSPACE__BM);
        _.hsetspace[cursp] = hashsetobj_add_BM (_.hsetspace[cursp], curduob);
      }
  }
  for (unsigned spix = PredefSp_BM; spix < LASTSPACE__BM; spix++)
    {
      unsigned spcard = hashsetobj_cardinal_BM (_.hsetspace[spix]);
      if (spcard == 0)
        {
          char *oldpathbuf = NULL;
          char *backpathbuf = NULL;
          asprintf (&oldpathbuf, "%s/store%u.bmon",
                    bytstring_BM (du->dump_dir), spix);
          asprintf (&backpathbuf, "%s/store%u.bmon~",
                    bytstring_BM (du->dump_dir), spix);
          if (oldpathbuf && backpathbuf)
            (void) rename (oldpathbuf, backpathbuf);
          free (oldpathbuf), free (backpathbuf);
        }
      else
        {
          dump_emit_space_BM (du, spix, _.hsetspace[spix],
                              (struct stackframe_stBM *) &_);
        }
    }
}                               /* end dump_emit_pass_BM */


static void
dump_emit_object_BM (struct dumper_stBM *du, const objectval_tyBM * curobj,
                     FILE * spfil, struct stackframe_stBM *stkf);

void
dump_emit_space_BM (struct dumper_stBM *du, unsigned spix,
                    struct hashsetobj_stBM *hspa,
                    struct stackframe_stBM *stkf)
{
  assert (valtype_BM ((const value_tyBM) du) == tydata_dumper_BM);
  assert (valtype_BM ((const value_tyBM) hspa) == tydata_hashsetobj_BM);
  assert (spix >= PredefSp_BM && spix < LASTSPACE__BM);
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 struct dumper_stBM *curdu;     //
                 struct hashsetobj_stBM *curhspa;
                 struct hashsetobj_stBM *modhset;
                 const setval_tyBM * setobjs;
                 const stringval_tyBM * pathv;
                 const stringval_tyBM * backupv;
                 const stringval_tyBM * tempathv;
                 const objectval_tyBM * curobj; //
                 const objectval_tyBM * modobj; //
                 const setval_tyBM * setmodules;
    );
  FILE *spfil = NULL;
  _.curdu = du;
  _.curhspa = hspa;
  _.setobjs = hashsetobj_to_set_BM (hspa);
  char randidbuf[32];
  memset (randidbuf, 0, sizeof (randidbuf));
  idtocbuf32_BM (du->dump_randomid, randidbuf);
  _.pathv = sprintfstring_BM ("%s/store%u.bmon",
                              bytstring_BM (du->dump_dir), spix);
  _.tempathv =
    sprintfstring_BM ("%s+%s%%", bytstring_BM (_.pathv), randidbuf);
  _.backupv = sprintfstring_BM ("%s~", bytstring_BM (_.pathv));
  spfil = fopen (bytstring_BM (_.tempathv), "w");
  if (!spfil)
    FATAL_BM ("dump_emit_space_BM cannot open %s (%m)",
              bytstring_BM (_.pathv));
  fprintf (spfil, "// generated file %s\n",
           basename (bytstring_BM (_.pathv)));
  unsigned nbobj = setcardinal_BM (_.setobjs);
  fprintf (spfil, "// for %u objects\n", nbobj);
  _.modhset = hashsetobj_grow_BM (NULL, 2 + nbobj / 128);
  // compute the set of modules
  for (unsigned obix = 0; obix < nbobj; obix++)
    {
      _.curobj = setelemnth_BM (_.setobjs, obix);
      assert (_.curobj != NULL);
      if (_.curobj->ob_rout)
        {
          Dl_info di = { };
          if (dladdr (_.curobj->ob_rout, &di) && di.dli_fname)
            {
              char modidbuf[32];
              memset (modidbuf, 0, sizeof (modidbuf));
              const char *bn = basename (di.dli_fname);
              int pos = -1;
              rawid_tyBM modid = { 0, 0 };
              const char *endid = NULL;
              if (sscanf
                  (bn, MODULEPREFIX_BM "%30[A-Za-z0-9_].so%n", modidbuf,
                   &pos) > 0 && pos > 0
                  && (modid = parse_rawid_BM (modidbuf, &endid)).id_hi > 0)
                {
                  _.modobj = findobjofid_BM (modid);
                  if (_.modobj)
                    _.modhset = hashsetobj_add_BM (_.modhset, _.modobj);
                }
            }
        }
    }
  _.setmodules = hashsetobj_to_set_BM (_.modhset);
  unsigned nbmodules = setcardinal_BM (_.setmodules);
  fprintf (spfil, "// with %d modules\n", nbmodules);
  for (unsigned mix = 0; mix < nbmodules; mix++)
    {
      char curmodid[32] = "";
      _.modobj = setelemnth_BM (_.setmodules, mix);
      assert (_.modobj);
      idtocbuf32_BM (objid_BM (_.modobj), curmodid);
      fprintf (spfil, "!^%s\n", curmodid);
    };
  fputc ('\n', spfil);
  const objectval_tyBM **objarr
    = calloc (prime_above_BM (nbobj), sizeof (void *));
  if (!objarr)
    FATAL_BM ("calloc failure for %d objects spix#%u", nbobj, spix);
  for (unsigned obix = 0; obix < nbobj; obix++)
    {
      _.curobj = setelemnth_BM (_.setobjs, obix);
      assert (isobject_BM ((const value_tyBM) _.curobj));
      objarr[obix] = _.curobj;
    };
  sortnamedobjarr_BM (objarr, nbobj);
  for (unsigned obix = 0; obix < nbobj; obix++)
    {
      _.curobj = objarr[obix];
      assert (_.curobj != NULL);
      dump_emit_object_BM (du, _.curobj, spfil,
                           (struct stackframe_stBM *) &_);
      if (obix % 64 == 0 && obix > 0)
        garbage_collect_if_wanted_BM ((struct stackframe_stBM *) &_);
    }
  free (objarr);
  fprintf (spfil, "\n// end of file %s\n", basename (bytstring_BM (_.pathv)));
  fclose (spfil);
  (void) rename (bytstring_BM (_.pathv), bytstring_BM (_.backupv));
  if (rename (bytstring_BM (_.tempathv), bytstring_BM (_.pathv)))
    FATAL_BM ("rename failure %s -> %s for dump of spix#%u",
              bytstring_BM (_.tempathv), bytstring_BM (_.pathv), spix);
  du->dump_wrotefilecount++;
}                               /* end  dump_emit_space_BM */

void
dump_emit_object_BM (struct dumper_stBM *du, const objectval_tyBM * curobj,
                     FILE * spfil, struct stackframe_stBM *stkf)
{

  assert (valtype_BM ((const value_tyBM) du) == tydata_dumper_BM);
  assert (valtype_BM ((const value_tyBM) curobj) == tyObject_BM);
  assert (spfil != NULL);
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 struct dumper_stBM *curdu;     //
                 const objectval_tyBM * curobj; //
                 const objectval_tyBM * curattr;        //
                 value_tyBM curval;     //
                 const setval_tyBM * attrset;
                 struct strbuffer_stBM *sbuf;
                 value_tyBM dumpres;    //
    );
  _.curdu = du;
  _.curobj = curobj;
  char curobjid[32] = "";
  idtocbuf32_BM (objid_BM (curobj), curobjid);
  fputc ('\n', spfil);
  fprintf (spfil, "!(%s", curobjid);
  {
    const char *obnam = findobjectname_BM (curobj);
    if (obnam)
      fprintf (spfil, " |=%s|\n" "!~ name (~ %s\n~)\n", obnam, obnam);
    else
      fputc ('\n', spfil);
  }
  if (curobj->ob_sig && curobj->ob_routaddr
      && dumpobjisdumpable_BM (du, curobj->ob_sig))
    {
      _.curattr = curobj->ob_sig;
      if (_.curattr == BMP_function_sig)
        fprintf (spfil, "!^*\n");
      else
        {
          char cursigid[32] = "";
          idtocbuf32_BM (objid_BM (curobj->ob_sig), cursigid);
          const char *signam = findobjectname_BM (curobj->ob_sig);
          if (signam)
            fprintf (spfil, "!^ %s |=%s|\n", cursigid, signam);
          else
            fprintf (spfil, "!^ %s\n", cursigid);
        }
    }
  if (curobj->ob_mtime > 0)
    fprintf (spfil, "!@ %.2f\n", curobj->ob_mtime);
  if (curobj->ob_class && dumpobjisdumpable_BM (du, curobj->ob_class))
    {
      char curclassid[32] = "";
      idtocbuf32_BM (objid_BM (curobj->ob_class), curclassid);
      const char *clanam = findobjectname_BM (curobj->ob_class);
      if (clanam)
        fprintf (spfil, "!$%s |=%s|\n", curclassid, clanam);
      else
        fprintf (spfil, "!$%s\n", curclassid);
    }
  _.attrset = objsetattrs_BM (curobj);
  _.sbuf = strbuffermake_BM (0);
  /// dump the attributes
  unsigned nbattrs = setcardinal_BM (_.attrset);
  for (unsigned atix = 0; atix < nbattrs; atix++)
    {
      _.curattr = setelemnth_BM (_.attrset, atix);
      if (!dumpobjisdumpable_BM (du, _.curattr))
        continue;
      _.curval = objgetattr_BM (curobj, _.curattr);
      if (!dumpvalisdumpable_BM (du, _.curval))
        continue;
      strbufferreset_BM (_.sbuf);
      _.dumpres =
        send3_BM (_.curval, BMP_dump_value,
                  (struct stackframe_stBM *) &_,
                  _.sbuf, du, taggedint_BM (0));
      if (!_.dumpres || strbufferlength_BM (_.sbuf) == 0)
        continue;
      char curattrid[32] = "";
      idtocbuf32_BM (objid_BM (_.curattr), curattrid);
      const char *attrnam = findobjectname_BM (_.curattr);
      if (attrnam)
        fprintf (spfil, "!: %s |=%s|\n", curattrid, attrnam);
      else
        fprintf (spfil, "!: %s\n", curattrid);
      fputs (strbufferbytes_BM (_.sbuf), spfil);
      fputc ('\n', spfil);
    }
  strbufferreset_BM (_.sbuf);
  /// dump the components
  unsigned nbcomp = objnbcomps_BM (_.curobj);
  if (nbcomp > 0)
    {
      fprintf (spfil, "!# %u\n", nbcomp);
      for (unsigned cpix = 0; cpix < nbcomp; cpix++)
        {
          _.curval = objgetcomp_BM (_.curobj, cpix);
          if (dumpvalisdumpable_BM (du, _.curval))
            {
              strbufferreset_BM (_.sbuf);
              _.dumpres =
                send3_BM (_.curval, BMP_dump_value,
                          (struct stackframe_stBM *) &_,
                          _.sbuf, du, taggedint_BM (0));
              if (!_.dumpres || strbufferlength_BM (_.sbuf) == 0)
                fputs ("!& __\n", spfil);
              else
                {
                  fputs ("!& ", spfil);
                  fputs (strbufferbytes_BM (_.sbuf), spfil);
                  fputc ('\n', spfil);
                }
            }
          else
            {
              fputs ("!& __\n", spfil);
            }
        }
    }
  strbufferreset_BM (_.sbuf);
  /// dump the data
  _.dumpres = send2_BM ((const value_tyBM) _.curobj, BMP_dump_data,
                        (struct stackframe_stBM *) &_, du, _.sbuf);
  if (_.dumpres && strbufferlength_BM (_.sbuf) > 0)
    {
      fputs (strbufferbytes_BM (_.sbuf), spfil);
      fputc ('\n', spfil);
    }
  fprintf (spfil, "!)%s\n", curobjid);
  fputc ('\n', spfil);
  fputc ('\n', spfil);
  du->dump_emittedobjectcount++;
}                               /* end dump_emit_object_BM */
