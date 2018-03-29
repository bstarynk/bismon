// file dump_BM.c

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

void
dumpgcmark_BM (struct garbcoll_stBM *gc, struct dumper_stBM *du)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) du)->htyp == typayl_dumper_BM);
  gcobjmark_BM (gc, (value_tyBM) du->dump_object);
  VALUEGCPROC_BM (gc, du->dump_dir, 0);
  EXTENDEDGCPROC_BM (gc, du->dump_hset, 0);
  EXTENDEDGCPROC_BM (gc, du->dump_scanlist, 0);
  EXTENDEDGCPROC_BM (gc, du->dump_todolist, 0);
}                               /* end dumpgcmark_BM */

void
dumpgcdestroy_BM (struct garbcoll_stBM *gc, struct dumper_stBM *du)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) du)->htyp == typayl_dumper_BM);
  /* dont free du here */

}                               /* end dumpgcdestroy_BM */


void
dumpgckeep_BM (struct garbcoll_stBM *gc, struct dumper_stBM *du)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (((typedhead_tyBM *) du)->htyp == typayl_dumper_BM);
}                               /* end dumpgckeep_BM */

bool
obdumpobjisdumpable_BM (objectval_tyBM * dumpob, const objectval_tyBM * obj)
{
  struct dumper_stBM *du = obdumpgetdumper_BM (dumpob);
  if (!du)
    return false;
  if (!isobject_BM ((const value_tyBM) obj))
    return false;
  return hashsetobj_contains_BM (du->dump_hset, obj);
}                               /* end dumpobjisdumpable_BM */

bool
obdumpvalisdumpable_BM (objectval_tyBM * dumpob, const value_tyBM val)
{
  struct dumper_stBM *du = obdumpgetdumper_BM (dumpob);
  if (!du)
    return false;
  if (val && !isobject_BM (val))
    return true;
  return obdumpobjisdumpable_BM (dumpob, (const objectval_tyBM *) val);
}                               /* end dumpvalisdumpable_BM */


static bool
obdumpvalisfullydumpabledepth_BM (struct dumper_stBM *du,
                                  const value_tyBM val, int depth);

bool
obdumpvalisfullydumpabledepth_BM (struct dumper_stBM *du,
                                  const value_tyBM val, int depth)
{
  ASSERT_BM (((typedhead_tyBM *) du)->htyp == typayl_dumper_BM);
  if (depth > MAXDEPTHGC_BM)
    return false;
  if (!val)
    return false;
  switch (valtype_BM (val))
    {
    case tyString_BM:
    case tyInt_BM:
    case tyUnspecified_BM:
      return true;
    case tySet_BM:
    case tyTuple_BM:
      {
        const seqobval_tyBM *seq = val;
        for (int ix = (int)(((const typedsize_tyBM *)seq)->size) - 1;
             ix >= 0; ix--)
          {
            const objectval_tyBM *curob = seq->seq_objs[ix];
            if (!curob || !hashsetobj_contains_BM (du->dump_hset, curob))
              return false;
          }
        return true;
      }
    case tyNode_BM:
    case tyClosure_BM:
      {
        const tree_tyBM *tree = val;
        if (!hashsetobj_contains_BM (du->dump_hset, tree->nodt_conn))
          return false;
        for (int ix = (int)(((const typedsize_tyBM *)tree)->size) - 1;
             ix >= 0; ix--)
          if (!obdumpvalisfullydumpabledepth_BM
              (du, tree->nodt_sons[ix], depth + 1))
            return false;
        return true;
      }
    case tyObject_BM:
      return hashsetobj_contains_BM (du->dump_hset, (objectval_tyBM *) val);
    }
  return false;
}                               /* end obdumpvalisfullydumpabledepth_BM */


bool
obdumpvalisfullydumpable_BM (objectval_tyBM * dumpob, const value_tyBM val)
{
  struct dumper_stBM *du = obdumpgetdumper_BM (dumpob);
  if (!du)
    return false;
  return obdumpvalisfullydumpabledepth_BM (du, val, 0);
}                               /* end obdumpvalisfullydumpable_BM */


void
obdumpscanobj_BM (objectval_tyBM * dumpob, const objectval_tyBM * obj)
{
  struct dumper_stBM *du = obdumpgetdumper_BM (dumpob);
  if (!du)
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
}                               /* end obdumpscanobj_BM */


void
obdumpscanvalue_BM (objectval_tyBM * dumpob, const value_tyBM val, int depth)
{
  struct dumper_stBM *du = obdumpgetdumper_BM (dumpob);
  if (!du)
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
          obdumpscanobj_BM (dumpob, ((seqobval_tyBM *) val)->seq_objs[ix]);
      }
      break;
    case tyNode_BM:
    case tyClosure_BM:
      {
        const tree_tyBM *tree = (const tree_tyBM *) val;
        obdumpscanobj_BM (dumpob, tree->nodt_conn);
        if (!obdumpobjisdumpable_BM (dumpob, tree->nodt_conn))
          return;
        unsigned siz = ((typedsize_tyBM *) val)->size;
        for (int ix = (int)siz - 1; ix >= 0; ix--)
          obdumpscanvalue_BM (dumpob, tree->nodt_sons[ix], depth + 1);
      }
      break;
    case tyObject_BM:
      obdumpscanobj_BM (dumpob, (const objectval_tyBM *) val);
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
                 objectval_tyBM * duobj;
                 const stringval_tyBM * dudirv;
    );
  if (!dirname || dirname[0] == (char) 0)
    dirname = ".";
  DBGPRINTF_BM ("dump_BM dirname %s start tid#%ld",
                dirname, (long) gettid_BM ());
  struct dumper_stBM *duptr = NULL;
  fprintf (stderr, "start dumping into %s\n", dirname);
  if (g_mkdir_with_parents (dirname, 0750))
    FATAL_BM ("failed to mkdir with parents %s", dirname);
  _.dudirv = makestring_BM (dirname);
  _.duobj = makeobj_BM ();
  duptr = allocgcty_BM (typayl_dumper_BM, sizeof (struct dumper_stBM));
  duptr->dump_state = dum_scan;
  duptr->dump_dir = _.dudirv;
  duptr->dump_hset = hashsetobj_grow_BM (NULL, 256);
  duptr->dump_randomid = randomid_BM ();
  duptr->dump_scanlist = makelist_BM ();
  duptr->dump_todolist = makelist_BM ();
  duptr->dump_startelapsedtime = elapsedtime_BM ();
  duptr->dump_startcputime = cputime_BM ();
  duptr->dump_object = _.duobj;
  objputpayload_BM (_.duobj, duptr);
  objputclass_BM (_.duobj, BMP_dumper_object);
  dump_scan_pass_BM (duptr, (struct stackframe_stBM *) &_);
  dump_run_todo_BM (duptr, (struct stackframe_stBM *) &_);
  garbage_collect_if_wanted_BM ((struct stackframe_stBM *) &_);
  dump_emit_pass_BM (duptr, (struct stackframe_stBM *) &_);
  garbage_collect_if_wanted_BM ((struct stackframe_stBM *) &_);
  dump_run_todo_BM (duptr, (struct stackframe_stBM *) &_);
  garbage_collect_if_wanted_BM ((struct stackframe_stBM *) &_);
  struct dumpinfo_stBM di;
  memset (&di, 0, sizeof (di));
  di.dumpinfo_scanedobjectcount = duptr->dump_scanedobjectcount;
  di.dumpinfo_emittedobjectcount = duptr->dump_emittedobjectcount;
  di.dumpinfo_todocount = duptr->dump_todocount;
  di.dumpinfo_wrotefilecount = duptr->dump_wrotefilecount;
  di.dumpinfo_elapsedtime = elapsedtime_BM () - duptr->dump_startelapsedtime;
  di.dumpinfo_cputime = cputime_BM () - duptr->dump_startcputime;
  DBGPRINTF_BM ("dump_BM dirname %s end tid#%ld\n",
                dirname, (long) gettid_BM ());
  return di;
}                               /* end dump_BM */


void
dump_run_todo_BM (struct dumper_stBM *du, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * curclo;
    );
  ASSERT_BM (valtype_BM ((const value_tyBM) du) == typayl_dumper_BM);
  while (listlength_BM (du->dump_todolist) > 0)
    {
      _.curclo = listfirst_BM (du->dump_todolist);
      listpopfirst_BM (du->dump_todolist);
      if (isclosure_BM ((const value_tyBM) _.curclo))
        {
          apply1_BM ((value_tyBM) _.curclo, (struct stackframe_stBM *) &_,
                     du);
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
                 objectval_tyBM * obdump;       //
                 objectval_tyBM * curobj;       //
                 const setval_tyBM * setattrs;  //
                 const objectval_tyBM * curattrobj;
                 value_tyBM curval;
    );
  ASSERT_BM (valtype_BM ((const value_tyBM) du) == typayl_dumper_BM);
  ASSERT_BM (valtype_BM ((const value_tyBM) objarg) == tyObject_BM);
  _.obdump = du->dump_object;
  _.curobj = (objectval_tyBM *) objarg;
  objlock_BM (_.curobj);
  // scan the class
  _.curattrobj = objclass_BM (_.curobj);
  if (_.curattrobj)
    obdumpscanobj_BM (_.obdump, _.curattrobj);
  // scan the signature
  _.curattrobj = objsignature_BM (_.curobj);
  if (_.curattrobj && objarg->ob_routaddr)
    obdumpscanobj_BM (_.obdump, _.curattrobj);
  // scan the attributes and their values
  _.curattrobj = NULL;
  _.setattrs = objsetattrs_BM ((objectval_tyBM *) _.curobj);
  unsigned nbattrs = objnbattrs_BM ((objectval_tyBM *) _.curobj);
  ASSERT_BM (nbattrs == setcardinal_BM (_.setattrs));
  for (int ix = 0; ix < (int) nbattrs; ix++)
    {
      _.curattrobj = setelemnth_BM (_.setattrs, ix);
      obdumpscanobj_BM (_.obdump, _.curattrobj);
      if (!obdumpobjisdumpable_BM (_.obdump, _.curattrobj))
        continue;
      _.curval =
        objgetattr_BM ((objectval_tyBM *) _.curobj,
                       (objectval_tyBM *) _.curattrobj);
      obdumpscanvalue_BM (_.obdump, _.curval, 0);
      _.curattrobj = NULL;
      _.curval = NULL;
    };
  _.setattrs = NULL;
  // scan the components
  unsigned nbcomps = objnbcomps_BM ((objectval_tyBM *) _.curobj);
  for (int ix = 0; ix < (int) nbcomps; ix++)
    {
      _.curval = objgetcomp_BM ((objectval_tyBM *) _.curobj, ix);
      obdumpscanvalue_BM (_.obdump, _.curval, 0);
      _.curval = NULL;
    }
  // perhaps we should send first, and use its result...
  extendedval_tyBM payl = objpayload_BM (_.curobj);
  if (payl)
    send1_BM ((value_tyBM) _.curobj, BMP_dump_scan,
              (struct stackframe_stBM *) &_, _.obdump);
  objunlock_BM (_.curobj);
  du->dump_scanedobjectcount++;
}                               /* end dump_scan_object_content_BM   */


static void
dump_scan_pass_BM (struct dumper_stBM *du, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const setval_tyBM * predefset; //
                 const setval_tyBM * globalset; //
                 const objectval_tyBM * curobj;
                 objectval_tyBM * obdump;
    );
  ASSERT_BM (valtype_BM ((const value_tyBM) du) == typayl_dumper_BM);
  _.obdump = du->dump_object;
  _.predefset = setpredefinedobjects_BM ();
  _.globalset = setglobalobjects_BM ();
  obdumpscanvalue_BM (_.obdump, (value_tyBM) _.predefset, 0);
  obdumpscanvalue_BM (_.obdump, (value_tyBM) _.globalset, 0);
  for (int kix = 0; kix < bmnbconsts; kix++)
    {
      if (*(bmconstaddrs[kix]))
        obdumpscanobj_BM (_.obdump, *(bmconstaddrs[kix]));
    };
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
                    objectval_tyBM * hspaob, struct stackframe_stBM *stkf);

void
dump_emit_pass_BM (struct dumper_stBM *du, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * curobj; //
                 objectval_tyBM * curhsetob;
                 objectval_tyBM * hsetspacob[LASTSPACE__BM];
    );
  ASSERT_BM (valtype_BM ((const value_tyBM) du) == typayl_dumper_BM);
  for (unsigned spix = PredefSp_BM; spix < LASTSPACE__BM; spix++)
    {
      _.curhsetob = makeobj_BM ();
      objputhashsetpayl_BM (_.curhsetob, 256);
      _.hsetspacob[spix] = _.curhsetob;
    };
  struct hashsetobj_stBM *dhset = du->dump_hset;
  ASSERT_BM (valtype_BM ((const value_tyBM) dhset) == typayl_hashsetobj_BM);
  {
    unsigned alsiz = ((typedhead_tyBM *) dhset)->rlen;
    for (unsigned ix = 0; ix < alsiz; ix++)
      {
        objectval_tyBM *curduob = dhset->hashset_objs[ix];
        if (!curduob || curduob == HASHEMPTYSLOT_BM)
          continue;
        _.curobj = curduob;
        int cursp = objspacenum_BM (curduob);
        ASSERT_BM (cursp >= PredefSp_BM && cursp < LASTSPACE__BM);
        objhashsetaddpayl_BM ((objectval_tyBM *) _.hsetspacob[cursp],
                              curduob);
      }
  }
  for (unsigned spix = PredefSp_BM; spix < LASTSPACE__BM; spix++)
    {
      unsigned spcard = objhashsetcardinalpayl_BM (_.hsetspacob[spix]);
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
          free (oldpathbuf), oldpathbuf =
            NULL, free (backpathbuf), backpathbuf = NULL;
        }
      else
        {
          dump_emit_space_BM (du, spix, _.hsetspacob[spix],
                              (struct stackframe_stBM *) &_);
        }
    }
}                               /* end dump_emit_pass_BM */


static void
dump_emit_object_BM (struct dumper_stBM *du, const objectval_tyBM * curobj,
                     FILE * spfil, struct stackframe_stBM *stkf);

void
dump_emit_space_BM (struct dumper_stBM *du, unsigned spix,
                    objectval_tyBM * hspob, struct stackframe_stBM *stkf)
{
  ASSERT_BM (valtype_BM ((const value_tyBM) du) == typayl_dumper_BM);
  ASSERT_BM (spix >= PredefSp_BM && spix < LASTSPACE__BM);
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * modhsetob;
                 objectval_tyBM * hspob;
                 const setval_tyBM * setobjs;
                 const stringval_tyBM * pathv;
                 const stringval_tyBM * backupv;
                 const stringval_tyBM * tempathv;
                 objectval_tyBM * curobj;       //
                 const objectval_tyBM * modobj; //
                 const setval_tyBM * setmodules;
    );
  FILE *spfil = NULL;
  _.hspob = hspob;
  _.setobjs = objhashsettosetpayl_BM (hspob);
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
  _.modhsetob = makeobj_BM ();
  objputhashsetpayl_BM (_.modhsetob, 2 + nbobj / 128);
  // compute the set of modules
  for (unsigned obix = 0; obix < nbobj; obix++)
    {
      _.curobj = setelemnth_BM (_.setobjs, obix);
      ASSERT_BM (_.curobj != NULL);
      objlock_BM (_.curobj);
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
                    objhashsetaddpayl_BM (_.modhsetob,
                                          (objectval_tyBM *) _.modobj);
                }
            }
        }
      objunlock_BM (_.curobj);
    }
  _.setmodules = objhashsettosetpayl_BM (_.modhsetob);
  unsigned nbmodules = setcardinal_BM (_.setmodules);
  fprintf (spfil, "// with %d modules\n", nbmodules);
  for (unsigned mix = 0; mix < nbmodules; mix++)
    {
      char curmodid[32] = "";
      _.modobj = setelemnth_BM (_.setmodules, mix);
      ASSERT_BM (_.modobj);
      idtocbuf32_BM (objid_BM (_.modobj), curmodid);
      fprintf (spfil, "!^%s\n", curmodid);
    };
  fputc ('\n', spfil);
  objectval_tyBM **objarr = calloc (prime_above_BM (nbobj), sizeof (void *));
  if (!objarr)
    FATAL_BM ("calloc failure for %d objects spix#%u", nbobj, spix);
  for (unsigned obix = 0; obix < nbobj; obix++)
    {
      _.curobj = setelemnth_BM (_.setobjs, obix);
      ASSERT_BM (isobject_BM ((const value_tyBM) _.curobj));
      objarr[obix] = _.curobj;
    };
  sortnamedobjarr_BM (objarr, nbobj);
  for (unsigned obix = 0; obix < nbobj; obix++)
    {
      _.curobj = objarr[obix];
      ASSERT_BM (_.curobj != NULL);
      dump_emit_object_BM (du, _.curobj, spfil,
                           (struct stackframe_stBM *) &_);
      if (obix % 64 == 0 && obix > 0)
        garbage_collect_if_wanted_BM ((struct stackframe_stBM *) &_);
    }
  free (objarr), objarr = NULL;
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

  ASSERT_BM (valtype_BM ((const value_tyBM) du) == typayl_dumper_BM);
  ASSERT_BM (valtype_BM ((const value_tyBM) curobj) == tyObject_BM);
  ASSERT_BM (spfil != NULL);
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * dumpob;       //
                 objectval_tyBM * curobj;       //
                 const objectval_tyBM * curattr;        //
                 value_tyBM curval;     //
                 const setval_tyBM * attrset;
                 objectval_tyBM * bufob;        //
                 value_tyBM dumpres;    //
    );
  _.dumpob = du->dump_object;
  _.curobj = (objectval_tyBM *) curobj;
  objlock_BM (_.curobj);
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
      && obdumpobjisdumpable_BM (_.dumpob, curobj->ob_sig))
    {
      _.curattr = curobj->ob_sig;
      if (_.curattr == BMP_function_sig)
        fprintf (spfil, "!|*\n");
      else
        {
          char cursigid[32] = "";
          idtocbuf32_BM (objid_BM (curobj->ob_sig), cursigid);
          const char *signam = findobjectname_BM (curobj->ob_sig);
          if (signam)
            fprintf (spfil, "!| %s |=%s|\n", cursigid, signam);
          else
            fprintf (spfil, "!| %s\n", cursigid);
        }
    }
  if (curobj->ob_mtime > 0)
    fprintf (spfil, "!@ %.2f\n", curobj->ob_mtime);
  if (curobj->ob_class && obdumpobjisdumpable_BM (_.dumpob, curobj->ob_class))
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
  _.bufob = makeobj_BM ();
  objputstrbufferpayl_BM (_.bufob, 0);
  /// dump the attributes
  unsigned nbattrs = setcardinal_BM (_.attrset);
  for (unsigned atix = 0; atix < nbattrs; atix++)
    {
      _.curattr = setelemnth_BM (_.attrset, atix);
      if (!obdumpobjisdumpable_BM (_.dumpob, _.curattr))
        continue;
      _.curval = objgetattr_BM (curobj, _.curattr);
      if (!obdumpvalisdumpable_BM (_.dumpob, _.curval))
        continue;
      objstrbufferresetpayl_BM (_.bufob);
      _.dumpres =
        send3_BM (_.curval, BMP_dump_value,
                  (struct stackframe_stBM *) &_,
                  _.bufob, _.dumpob, taggedint_BM (0));
      if (!_.dumpres || objstrbufferlengthpayl_BM (_.bufob) == 0)
        continue;
      char curattrid[32] = "";
      idtocbuf32_BM (objid_BM (_.curattr), curattrid);
      const char *attrnam = findobjectname_BM (_.curattr);
      if (attrnam)
        fprintf (spfil, "!: %s |=%s|\n", curattrid, attrnam);
      else
        fprintf (spfil, "!: %s\n", curattrid);
      fputs (objstrbufferbytespayl_BM (_.bufob), spfil);
      fputc ('\n', spfil);
    }
  objstrbufferresetpayl_BM (_.bufob);
  /// dump the components
  unsigned nbcomp = objnbcomps_BM (_.curobj);
  if (nbcomp > 0)
    {
      fprintf (spfil, "!# %u\n", nbcomp);
      for (unsigned cpix = 0; cpix < nbcomp; cpix++)
        {
          _.curval = objgetcomp_BM (_.curobj, cpix);
          if (obdumpvalisdumpable_BM (_.dumpob, _.curval))
            {
              objstrbufferresetpayl_BM (_.bufob);
              _.dumpres =
                send3_BM (_.curval, BMP_dump_value,
                          (struct stackframe_stBM *) &_,
                          _.bufob, _.dumpob, taggedint_BM (0));
              if (!_.dumpres || objstrbufferlengthpayl_BM (_.bufob) == 0)
                fputs ("!& __\n", spfil);
              else
                {
                  fputs ("!& ", spfil);
                  fputs (objstrbufferbytespayl_BM (_.bufob), spfil);
                  fputc ('\n', spfil);
                }
            }
          else
            {
              fputs ("!& __\n", spfil);
            }
        }
    }
  objstrbufferresetpayl_BM (_.bufob);
  /// dump the data
  _.dumpres = send2_BM ((const value_tyBM) _.curobj, BMP_dump_data,
                        (struct stackframe_stBM *) &_, _.dumpob, _.bufob);
  if (_.dumpres && objstrbufferlengthpayl_BM (_.bufob) > 0)
    {
      fputs (objstrbufferbytespayl_BM (_.bufob), spfil);
      fputc ('\n', spfil);
    }
  fprintf (spfil, "!)%s\n", curobjid);
  fputc ('\n', spfil);
  fputc ('\n', spfil);
  objunlock_BM (_.curobj);
  du->dump_emittedobjectcount++;
}                               /* end dump_emit_object_BM */


const char *
debug_outstr_value_BM (const value_tyBM val, struct stackframe_stBM *stkf,
                       int curdepth)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM valv;
                 objectval_tyBM * bufob;
    );
  _.valv = val;
  if (!val)
    return "__";
  WEAKASSERT_BM (valtype_BM (val) <= type_LASTREAL_BM);
  _.bufob = makeobj_BM ();
  objputstrbufferpayl_BM (_.bufob, 256 * 1024);
  if (!send3_BM (_.valv, BMP_dump_value,
                 (struct stackframe_stBM *) &_,
                 _.bufob, NULL, taggedint_BM (curdepth)))
    return "??";
  return objstrbufferbytespayl_BM (_.bufob);
}                               /* end debug_outstr_value_BM */
