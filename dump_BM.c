// file dump_BM.c
#include "bismon.h"

void
dumpgcmark_BM (struct garbcoll_stBM *gc, struct dumper_stBM *du)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) du)->htyp == tydata_dumper_BM);
  gcmark_BM (gc, du->dump_dir, 0);
  gcmark_BM (gc, du->dump_hset, 0);
  gcmark_BM (gc, du->dump_scanlist, 0);
  gcmark_BM (gc, du->dump_todolist, 0);
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
dump_BM (const char *dirname, struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 struct dumper_stBM *curdu; objectval_tyBM * duobj;
                 stringval_tyBM * dudirv;
    );
  if (!dirname || dirname[0] == (char) 0)
    dirname = ".";
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
#warning dump_BM unimplemented
}                               /* end dump_BM */
