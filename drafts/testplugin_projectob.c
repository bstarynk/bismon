// BISMON TESTPLUGIN  projectob
// file drafts/testplugin_projectob.c of http://github.com/bstarynk/bismon/

#include "bismon.h"

static objectval_tyBM *k_project_class_BM;

void
projectob_initest_BM (struct stackframe_stBM *stkf,
                      const char *pluginame, int pluginrk)
{
  DBGPRINTF_BM ("projectob_initest_BM start pluginame %s pluginrk %d",
                pluginame, pluginrk);
  ASSERT_BM (stkf != NULL && valtype_BM (stkf) == typayl_StackFrame_BM);
}                               /* end of projectob_initest_BM */

int
projectob_runtest_BM (struct stackframe_stBM *stkf,
                      const char *pluginame, int pluginrk)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * projclassob;        //
		  objectval_tyBM *hashsetvalob; //
		  objectval_tyBM *selinitclassob; //
		  value_tyBM initclassresv; // 
    );
  _.projclassob = makeobj_BM ();
  _.hashsetvalob = BMP_hashsetval_object;
  _.selinitclassob = lockedfindobjofstrid_BM("_75gnoii3mMp_41wgHkvJVyN");
  DBGPRINTF_BM
    ("projectob_runtest_BM start pluginame %s pluginrk %d projclassob %s hashsetvalob %s selinitclassob %s",
     pluginame, pluginrk, objectdbg_BM (_.projclassob),
     objectdbg1_BM(_.hashsetvalob), objectdbg2_BM(_.selinitclassob));
  ASSERT_BM(_.hashsetvalob != NULL);
  /// should send init_class (<superclass>) to projclassob
  WARNPRINTF_BM("projectob_runtest_BM is incomplete");
#warning projectob_runtest_BM should create the project_class object...
#if 0
  objputclass_BM (_.tmpob, k_decaying_vector_object_bm);
  if (!objputdecayedvectorpayl_BM (_.tmpob, 2, 40 * 1000))
    FATAL_BM ("failed to put decaying vector in %s", objectdbg_BM (_.tmpob));
  objputattr_BM (BMP_the_system, k_decaying_vector_object_bm, _.tmpob);
  DBGPRINTF_BM ("projectob_runtest_BM after putattr the_system tmpob %s",
                objectdbg_BM (_.tmpob));
  INFOPRINTF_BM
    ("projectob_runtest_BM put in `the_system` attribute `decaying_vector_object` object %s",
     objectdbg_BM (_.tmpob));
  #endif
  return 0;
}                               /* end of projectob_runtest_BM */

// end file drafts/testplugin_projectob.c
