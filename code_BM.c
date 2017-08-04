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



////////////////////////////////////////////////////////////////
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
                 const setval_tyBM * recv; struct strbuffer_stBM *sbuf;
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

////////////////////////////////////////////////////////////////
//// for the method to dump_value a tuple
extern objrout_sigBM ROUTINEOBJNAME_BM (_5D9kkPHSPxq_8suDXpjlzjE);

value_tyBM
ROUTINEOBJNAME_BM (_5D9kkPHSPxq_8suDXpjlzjE)
(const closure_tyBM * clos,
struct stackframe_stBM * stkf,
const value_tyBM arg1,
const value_tyBM arg2, const value_tyBM arg3, const quasinode_tyBM * restargs)
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  assert (istuple_BM (arg1));   // the tuple to dump
  assert (valtype_BM (arg2) == tydata_strbuffer_BM);
  assert (valtype_BM (arg3) == tydata_dumper_BM);
  assert (valtype_BM ((const value_tyBM) restargs) == tydata_quasinode_BM
          && treewidth_BM ((const value_tyBM) restargs) == 1);
  const value_tyBM arg4 = treenthson_BM ((const value_tyBM) restargs, 0);
  assert (istaggedint_BM (arg4));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const tupleval_tyBM * recv; struct strbuffer_stBM *sbuf;
                 struct dumper_stBM *du; value_tyBM depthv;
                 const objectval_tyBM * curobj;
    );
  _.recv = (arg1);
  _.sbuf = (struct strbuffer_stBM *) arg2;
  _.du = (struct dumper_stBM *) arg3;
  _.depthv = arg4;
  strbufferprintf_BM (_.sbuf, "\t[");
  strbuffermoreindent_BM (_.sbuf);
  unsigned tsiz = tuplesize_BM (_.recv);
  for (unsigned ix = 0; ix < tsiz; ix++)
    {
      _.curobj = tuplecompnth_BM (_.recv, ix);
      if (!dumpobjisdumpable_BM (_.du, _.curobj))
        continue;
      char curidbuf[32];
      idtocbuf32_BM (objid_BM (_.curobj), curidbuf);
      strbufferprintf_BM (_.sbuf, "\t%s", curidbuf);
    };
  strbufferlessindent_BM (_.sbuf);
  strbufferprintf_BM (_.sbuf, " ]");
  return _.sbuf;
}                               /* end ROUTINE _5D9kkPHSPxq_8suDXpjlzjE */

////////////////////////////////////////////////////////////////
//// for the method to dump_value a node
extern objrout_sigBM ROUTINEOBJNAME_BM (_5v30KC0IMxx_53ZzXprJTM6);

value_tyBM
ROUTINEOBJNAME_BM (_5v30KC0IMxx_53ZzXprJTM6)
(const closure_tyBM * clos,
struct stackframe_stBM * stkf,
const value_tyBM arg1,
const value_tyBM arg2, const value_tyBM arg3, const quasinode_tyBM * restargs)
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  assert (isnode_BM (arg1));    // the node to dump
  assert (valtype_BM (arg2) == tydata_strbuffer_BM);
  assert (valtype_BM (arg3) == tydata_dumper_BM);
  assert (valtype_BM ((const value_tyBM) restargs) == tydata_quasinode_BM
          && treewidth_BM ((const value_tyBM) restargs) == 1);
  const value_tyBM arg4 = treenthson_BM ((const value_tyBM) restargs, 0);
  assert (istaggedint_BM (arg4));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const node_tyBM * recv; struct strbuffer_stBM *sbuf;
                 struct dumper_stBM *du; value_tyBM depthv; value_tyBM curson;
                 const objectval_tyBM * connobj;
    );
  _.recv = (arg1);
  _.sbuf = (struct strbuffer_stBM *) arg2;
  _.du = (struct dumper_stBM *) arg3;
  _.depthv = arg4;
  unsigned depth = getint_BM (_.depthv);
  _.connobj = nodeconn_BM ((const value_tyBM) _.recv);
  if (!dumpobjisdumpable_BM (_.du, _.connobj))
    {
      strbufferprintf_BM (_.sbuf, " __");
      return _.sbuf;
    }
  char connidbuf[32];
  idtocbuf32_BM (objid_BM (_.connobj), connidbuf);
  strbufferprintf_BM (_.sbuf, "\t* %s (", connidbuf);
  unsigned width = nodewidth_BM ((const value_tyBM) _.recv);
  strbuffermoreindent_BM (_.sbuf);
  for (unsigned six = 0; six < width; six++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.recv, six);
      if (!dumpvalisdumpable_BM (_.du, _.curson))
        continue;
      strbufferprintf_BM (_.sbuf, "\t");
      send3_BM (_.curson, BMP_dump_value,
                (struct stackframe_stBM *) &_,
                _.sbuf, _.du, taggedint_BM (depth + 1));
    }
  strbufferlessindent_BM (_.sbuf);
  strbufferprintf_BM (_.sbuf, ")");
  return _.sbuf;
}                               /* end ROUTINE _5v30KC0IMxx_53ZzXprJTM6 */

////////////////////////////////////////////////////////////////
//// for the method to dump_value a closure
extern objrout_sigBM ROUTINEOBJNAME_BM (_6jvRZetUz36_978V6SKIWZC);

value_tyBM
ROUTINEOBJNAME_BM (_6jvRZetUz36_978V6SKIWZC)
(const closure_tyBM * clos,
struct stackframe_stBM * stkf,
const value_tyBM arg1,
const value_tyBM arg2, const value_tyBM arg3, const quasinode_tyBM * restargs)
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  assert (isclosure_BM (arg1)); // the closure to dump
  assert (valtype_BM (arg2) == tydata_strbuffer_BM);
  assert (valtype_BM (arg3) == tydata_dumper_BM);
  assert (valtype_BM ((const value_tyBM) restargs) == tydata_quasinode_BM
          && treewidth_BM ((const value_tyBM) restargs) == 1);
  const value_tyBM arg4 = treenthson_BM ((const value_tyBM) restargs, 0);
  assert (istaggedint_BM (arg4));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * recv; struct strbuffer_stBM *sbuf;
                 struct dumper_stBM *du; value_tyBM depthv; value_tyBM curson;
                 const objectval_tyBM * connobj;
    );
  _.recv = (arg1);
  _.sbuf = (struct strbuffer_stBM *) arg2;
  _.du = (struct dumper_stBM *) arg3;
  _.depthv = arg4;
  unsigned depth = getint_BM (_.depthv);
  _.connobj = closureconn_BM ((const value_tyBM) _.recv);
  if (!dumpobjisdumpable_BM (_.du, _.connobj))
    {
      strbufferprintf_BM (_.sbuf, " __");
      return _.sbuf;
    }
  char connidbuf[32];
  idtocbuf32_BM (objid_BM (_.connobj), connidbuf);
  strbufferprintf_BM (_.sbuf, "\t* %s (", connidbuf);
  unsigned width = closurewidth_BM ((const value_tyBM) _.recv);
  strbuffermoreindent_BM (_.sbuf);
  for (unsigned six = 0; six < width; six++)
    {
      _.curson = closurenthson_BM ((const value_tyBM) _.recv, six);
      if (!dumpvalisdumpable_BM (_.du, _.curson))
        continue;
      strbufferprintf_BM (_.sbuf, "\t");
      send3_BM (_.curson, BMP_dump_value,
                (struct stackframe_stBM *) &_,
                _.sbuf, _.du, taggedint_BM (depth + 1));
    }
  strbufferlessindent_BM (_.sbuf);
  strbufferprintf_BM (_.sbuf, ")");
  return _.sbuf;
}                               /* end ROUTINE _6jvRZetUz36_978V6SKIWZC */
