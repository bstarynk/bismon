// file dump_BM.c
#include "bismon.h"

void
dumpgcmark_BM (struct garbcoll_stBM *gc, struct dumper_stBM *du)
{
  assert (gc && gc->gc_magic == GCMAGIC_BM);
  assert (((typedhead_tyBM *) du)->htyp == tydata_dumper_BM);
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
                 struct dumper_stBM *curdu);
  FATAL_BM ("dump_BM unimplemented dirname=%s", dirname);
#warning dump_BM unimplemented
}                               /* end dump_BM */
