// BISMON TESTPLUGIN  decayedob
// file drafts/testplugin_decayedob.c of http://github.com/bstarynk/bismon/

#include "bismon.h"

void
decayedob_initest_BM (struct stackframe_stBM *stkf,
                      const char *pluginame, int pluginrk)
{
  DBGPRINTF_BM ("decayedob_initest_BM start pluginame %s pluginrk %d",
                pluginame, pluginrk);
}                               /* end of decayedob_initest_BM */

void
decayedob_runtest_BM (struct stackframe_stBM *stkf,
                      const char *pluginame, int pluginrk)
{
  DBGPRINTF_BM ("decayedob_runtest_BM start pluginame %s pluginrk %d",
                pluginame, pluginrk);
}                               /* end of decayedob_runtest_BM */

// end file drafts/testplugin_decayedob.c
