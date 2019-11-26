// BISMON TESTPLUGIN  decayedob
// file drafts/testplugin_decayedob.c of http://github.com/bstarynk/bismon/

#include "bismon.h"

static objectval_tyBM *k_decaying_vector_object_bm;

void
decayedob_initest_BM (struct stackframe_stBM *stkf,
                      const char *pluginame, int pluginrk)
{
  DBGPRINTF_BM ("decayedob_initest_BM start pluginame %s pluginrk %d",
                pluginame, pluginrk);
  ASSERT_BM (stkf != NULL && valtype_BM (stkf) == typayl_StackFrame_BM);
  k_decaying_vector_object_bm = findnamedobj_BM ("decaying_vector_object");
  ASSERT_BM (k_decaying_vector_object_bm ==
             findobjofstrid_BM ("_87e9wrUSdIs_0tppKPUo41v"));
  DBGPRINTF_BM ("decayedob_initest_BM k_decaying_vector_object %s",
                objectdbg_BM (k_decaying_vector_object_bm));
}                               /* end of decayedob_initest_BM */

int
decayedob_runtest_BM (struct stackframe_stBM *stkf,
                      const char *pluginame, int pluginrk)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ k_decaying_vector_object_bm,
                 objectval_tyBM * tmpob;        //
    );
  _.tmpob = makeobj_BM ();
  DBGPRINTF_BM
    ("decayedob_runtest_BM start pluginame %s pluginrk %d tmpob %s",
     pluginame, pluginrk, objectdbg_BM (_.tmpob));
  objputclass_BM (_.tmpob, k_decaying_vector_object_bm);
  if (!objputdecayedvectorpayl_BM (_.tmpob, 2, 40 * 1000))
    FATAL_BM ("failed to put decaying vector in %s", objectdbg_BM (_.tmpob));
  objputattr_BM (BMP_the_system, k_decaying_vector_object_bm, _.tmpob);
  DBGPRINTF_BM ("decayedob_runtest_BM after putattr the_system tmpob %s",
                objectdbg_BM (_.tmpob));
  INFOPRINTF_BM
    ("decayedob_runtest_BM put in `the_system` attribute `decaying_vector_object` object %s",
     objectdbg_BM (_.tmpob));
  return 0;
}                               /* end of decayedob_runtest_BM */

// end file drafts/testplugin_decayedob.c
