// file code_BM.c
#include "bismon.h"


//// for the method to dump_value a tagged integer
extern objrout_sigBM ROUTINEOBJNAME_BM (_3kMqlEugRVW_7DgwjR4CBbP);

value_tyBM
ROUTINEOBJNAME_BM (_3kMqlEugRVW_7DgwjR4CBbP)
(const closure_tyBM * clos,
struct stackframe_stBM * stkf,
const value_tyBM arg1,
const value_tyBM arg2, const value_tyBM arg3, const quasinode_tyBM * restargs)
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  assert (istaggedint_BM (arg1));       // the integer to dump
  assert (valtype_BM (arg2) == tydata_strbuffer_BM);
  assert (valtype_BM (arg3) == tydata_dumper_BM);
  assert (valtype_BM ((const value_tyBM) restargs) == tydata_quasinode_BM
          && treewidth_BM ((const value_tyBM) restargs) == 1);
  const value_tyBM arg4 = treenthson_BM ((const value_tyBM) restargs, 0);
  assert (istaggedint_BM (arg4));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM recv;
                 struct strbuffer_stBM *sbuf; struct dumper_stBM *du;
                 value_tyBM depthv;
    );
  _.recv = arg1;
  _.sbuf = (struct strbuffer_stBM *) arg2;
  _.du = (struct dumper_stBM *) arg3;
  _.depthv = arg4;
  strbufferprintf_BM (_.sbuf, " %lld", (long long) getint_BM (_.recv));
  return _.sbuf;
}                               /* end ROUTINE _3kMqlEugRVW_7DgwjR4CBbP */

//// for the method to dump_value a set
extern objrout_sigBM ROUTINEOBJNAME_BM (_3Tc3E4uo2p5_4EXWCPwCR5b);

value_tyBM
ROUTINEOBJNAME_BM (_3Tc3E4uo2p5_4EXWCPwCR5b)
(const closure_tyBM * clos,
struct stackframe_stBM * stkf,
const value_tyBM arg1,
const value_tyBM arg2, const value_tyBM arg3, const quasinode_tyBM * restargs)
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  assert (isset_BM (arg1));     // the set to dump
  assert (valtype_BM (arg2) == tydata_strbuffer_BM);
  assert (valtype_BM (arg3) == tydata_dumper_BM);
  assert (valtype_BM ((const value_tyBM) restargs) == tydata_quasinode_BM
          && treewidth_BM ((const value_tyBM) restargs) == 1);
  const value_tyBM arg4 = treenthson_BM ((const value_tyBM) restargs, 0);
  assert (istaggedint_BM (arg4));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const setval_tyBM * recv;
                 struct strbuffer_stBM *sbuf;
                 struct dumper_stBM *du; value_tyBM depthv;
                 const objectval_tyBM * curobj;
    );
  _.recv = (arg1);
  _.sbuf = (struct strbuffer_stBM *) arg2;
  _.du = (struct dumper_stBM *) arg3;
  _.depthv = arg4;
  strbufferprintf_BM (_.sbuf, "\t{");
  strbuffermoreindent_BM (_.sbuf);
  unsigned card = setcardinal_BM (_.recv);
  for (unsigned ix = 0; ix < card; ix++)
    {
      _.curobj = setelemnth_BM (_.recv, ix);
      if (!dumpobjisdumpable_BM (_.du, _.curobj))
        continue;
      char curidbuf[32];
      idtocbuf32_BM (objid_BM (_.curobj), curidbuf);
      strbufferprintf_BM (_.sbuf, "\t%s", curidbuf);
    };
  strbufferlessindent_BM (_.sbuf);
  strbufferprintf_BM (_.sbuf, " }");
  return _.sbuf;
}                               /* end ROUTINE _3Tc3E4uo2p5_4EXWCPwCR5b */
