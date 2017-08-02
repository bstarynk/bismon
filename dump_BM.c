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
dump_scan_pass_BM (struct dumper_stBM *du, struct stackframe_stBM *stkf);

static void
dump_emit_pass_BM (struct dumper_stBM *du, struct stackframe_stBM *stkf);


void
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
  _.curdu->dump_scanlist = makelist_BM ();
  _.curdu->dump_todolist = makelist_BM ();
  _.duobj = makeobj_BM ();
  _.duobj->ob_data = _.curdu;
  _.curdu->dump_object = _.duobj;
  dump_scan_pass_BM (_.curdu, (struct stackframe_stBM *) &_);
#warning dump_BM unimplemented
}                               /* end dump_BM */

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
              (struct stackframe_stBM *) &_, du->dump_object);
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
    unsigned ucnt = ((typedsize_tyBM *) dhset)->size;
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
          asprintf (&oldpathbuf, "%s/store%u.bismon",
                    bytstring_BM (du->dump_dir), spix);
          asprintf (&backpathbuf, "%s/store%u.bismon~",
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
                 const setval_tyBM * setobjs;
                 const stringval_tyBM * pathv;
                 const stringval_tyBM * backupv;
                 const objectval_tyBM * curobj; //
    );
  FILE *spfil = NULL;
  _.curdu = du;
  _.curhspa = hspa;
  _.setobjs = hashsetobj_to_set_BM (hspa);
  _.pathv = sprintfstring_BM ("%s/store%u.bismon",
                              bytstring_BM (du->dump_dir), spix);
  _.backupv = sprintfstring_BM ("%s~", bytstring_BM (_.pathv));
  (void) rename (bytstring_BM (_.pathv), bytstring_BM (_.backupv));
  spfil = fopen (bytstring_BM (_.pathv), "w");
  if (!spfil)
    FATAL_BM ("dump_emit_space_BM cannot open %s (%m)",
              bytstring_BM (_.pathv));
  fprintf (spfil, "// generated file %s\n",
           basename (bytstring_BM (_.pathv)));
  fprintf (spfil, "// for %d objects\n", setcardinal_BM (_.setobjs));
  fprintf (stderr, "dump_emit_space_BM spix=%d unimplemented\n", spix);
#warning dump_emit_space_BM unimplemented
  fprintf (spfil, "\n// end of file %s\n", basename (bytstring_BM (_.pathv)));
  fclose (spfil);
}                               /* end  dump_emit_space_BM */
