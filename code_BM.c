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
      strbufferprintf_BM (_.sbuf, " |transclos:| __");
      return _.sbuf;
    }
  char connidbuf[32];
  idtocbuf32_BM (objid_BM (_.connobj), connidbuf);
  strbufferprintf_BM (_.sbuf, "\t%% %s (", connidbuf);
  unsigned width = closurewidth_BM ((const value_tyBM) _.recv);
  strbuffermoreindent_BM (_.sbuf);
  for (unsigned six = 0; six < width; six++)
    {
      _.curson = closurenthson_BM ((const value_tyBM) _.recv, six);
      if (!dumpvalisdumpable_BM (_.du, _.curson))
        {
          strbufferprintf_BM (_.sbuf, "\t__");
          continue;
        }
      strbufferprintf_BM (_.sbuf, "\t");
      send3_BM (_.curson, BMP_dump_value,
                (struct stackframe_stBM *) &_,
                _.sbuf, _.du, taggedint_BM (depth + 1));
    }
  strbufferlessindent_BM (_.sbuf);
  strbufferprintf_BM (_.sbuf, ")");
  return _.sbuf;
}                               /* end ROUTINE _6jvRZetUz36_978V6SKIWZC */

////////////////////////////////////////////////////////////////
//// for the method to dump_value a string
extern objrout_sigBM ROUTINEOBJNAME_BM (_7mvOlkB1tAJ_3psVFz4QEAn);

value_tyBM
ROUTINEOBJNAME_BM (_7mvOlkB1tAJ_3psVFz4QEAn)
(const closure_tyBM * clos,
struct stackframe_stBM * stkf,
const value_tyBM arg1,
const value_tyBM arg2, const value_tyBM arg3, const quasinode_tyBM * restargs)
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  assert (isstring_BM (arg1));  // the string to dump
  assert (valtype_BM (arg2) == tydata_strbuffer_BM);
  assert (valtype_BM (arg3) == tydata_dumper_BM);
  assert (valtype_BM ((const value_tyBM) restargs) == tydata_quasinode_BM
          && treewidth_BM ((const value_tyBM) restargs) == 1);
  const value_tyBM arg4 = treenthson_BM ((const value_tyBM) restargs, 0);
  assert (istaggedint_BM (arg4));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const stringval_tyBM * recv; struct strbuffer_stBM *sbuf;
                 struct dumper_stBM *du; value_tyBM depthv; value_tyBM curson;
                 const objectval_tyBM * connobj;
    );
  _.recv = (arg1);
  _.sbuf = (struct strbuffer_stBM *) arg2;
  _.du = (struct dumper_stBM *) arg3;
  _.depthv = arg4;
  unsigned depth = getint_BM (_.depthv);
  assert (depth < MAXDEPTHMETHOD_BM);
  unsigned bsiz = lenstring_BM (_.recv);
  const char *bstr = bytstring_BM (_.recv);
  strbufferprintf_BM (_.sbuf, "\t\"");
  if (bsiz < STRBUFFERWANTEDWIDTH_BM)
    {
      strbufferencodedutf8_BM (_.sbuf, bstr, bsiz);
    }
  else
    {
      const char *bend = bstr + bsiz;
      const char *nextp = NULL;
      for (const char *ps = bstr; ps < bend && *ps; ps = nextp)
        {
          nextp = ps;
          gunichar uc = 0;
          for (int ix = STRBUFFERWANTEDWIDTH_BM / 2; ix > 0 && *nextp; ix--)
            nextp = g_utf8_next_char (nextp);
          for (int ix = STRBUFFERWANTEDWIDTH_BM / 2 - 4; ix > 0 && *nextp;
               ix--)
            {
              uc = g_utf8_get_char (nextp);
              if (g_unichar_isspace (uc))
                break;
              nextp = g_utf8_next_char (nextp);
            }
          strbufferencodedutf8_BM (_.sbuf, ps, nextp - ps);
          if (*nextp)
            {
              if (uc == '\n')
                {
                  strbufferprintf_BM (_.sbuf, "\"+\t\"");
                  nextp = g_utf8_next_char (nextp);
                }
              else
                strbufferprintf_BM (_.sbuf, "\"&\t\"");
            }
          else
            {
              if (uc == '\n')
                strbufferprintf_BM (_.sbuf, "\\n\"");
              else
                strbufferprintf_BM (_.sbuf, "\"");
            }
        }
    }
  strbufferprintf_BM (_.sbuf, "\"");
  return _.sbuf;
}                               /* end ROUTINE _7mvOlkB1tAJ_3psVFz4QEAn */




//// for the method to dump_scan a class
extern objrout_sigBM ROUTINEOBJNAME_BM (_4EBQMvthjcP_2OiZxZviSQc);

value_tyBM
ROUTINEOBJNAME_BM (_4EBQMvthjcP_2OiZxZviSQc)
(const closure_tyBM * clos,
struct stackframe_stBM * stkf,
const value_tyBM arg1,
const value_tyBM arg2, const value_tyBM arg3, const quasinode_tyBM * restargs)
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 struct dumper_stBM *du; const objectval_tyBM * supercl;
                 const setval_tyBM * selset; const objectval_tyBM * cursel;
                 value_tyBM curmeth;
    );
  assert (isobject_BM (arg1));
  _.recv = arg1;
  assert (valtype_BM (arg2) == tydata_dumper_BM);
  _.du = arg2;
  assert (valtype_BM (_.recv->ob_data) == tydata_classinfo_BM);
  assert (arg3 == NULL);
  assert (restargs == NULL);
  _.supercl = objgetclassinfosuperclass_BM ((const value_tyBM) _.recv);
  _.selset = objgetclassinfosetofselectors_BM ((const value_tyBM) _.recv);
  dumpscanobj_BM (_.du, _.supercl);
  dumpscanvalue_BM (_.du, (const value_tyBM) _.selset, 0);
  unsigned nbsel = setcardinal_BM (_.selset);
  for (unsigned six = 0; six < nbsel; six++)
    {
      _.cursel = setelemnth_BM (_.selset, six);
      if (!dumpobjisdumpable_BM (_.du, _.cursel))
        continue;
      _.curmeth = (value_tyBM) objgetclassinfomethod_BM (_.recv, _.cursel);
      assert (isclosure_BM (_.curmeth));
      dumpscanvalue_BM (_.du, _.curmeth, 0);
    }
  return (value_tyBM) _.recv;
}                               /* end ROUTINE _4EBQMvthjcP_2OiZxZviSQc */


//// for the method to dump_data a class
extern objrout_sigBM ROUTINEOBJNAME_BM (_67IapmpeTLU_8MQKtlK8iAD);

value_tyBM
ROUTINEOBJNAME_BM (_67IapmpeTLU_8MQKtlK8iAD)
(const closure_tyBM * clos,
struct stackframe_stBM * stkf,
const value_tyBM arg1,
const value_tyBM arg2, const value_tyBM arg3, const quasinode_tyBM * restargs)
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv; struct dumper_stBM *du;
                 struct strbuffer_stBM *sbuf; const objectval_tyBM * supercl;
                 const setval_tyBM * selset; const objectval_tyBM * cursel;
                 value_tyBM curmeth;
    );
  assert (isobject_BM (arg1));
  _.recv = arg1;
  assert (valtype_BM (arg2) == tydata_dumper_BM);
  _.du = arg2;
  assert (valtype_BM (arg3) == tydata_strbuffer_BM);
  assert (restargs == NULL);
  _.sbuf = arg3;
  _.supercl = objgetclassinfosuperclass_BM ((const value_tyBM) _.recv);
  if (!_.supercl)
    _.supercl = BMP_object;
  _.selset = objgetclassinfosetofselectors_BM ((const value_tyBM) _.recv);
  unsigned nbsel = setcardinal_BM (_.selset);
  strbufferprintf_BM (_.sbuf, "!~ class (~\t");
  strbuffermoreindent_BM (_.sbuf);
  if (dumpobjisdumpable_BM (_.du, _.supercl))
    {
      char superidbuf[32];
      memset (superidbuf, 0, sizeof (superidbuf));
      idtocbuf32_BM (objid_BM (_.supercl), superidbuf);
      const char *supername = findobjectname_BM (_.supercl);
      if (supername)
        strbufferprintf_BM (_.sbuf, "|supercl %s:| %s", supername,
                            superidbuf);
      else
        strbufferprintf_BM (_.sbuf, "|supercl=| %s", superidbuf);
    }
  else
    {
      strbufferprintf_BM (_.sbuf, "|nosuperclass| __");
    }
  for (unsigned six = 0; six < nbsel; six++)
    {
      _.cursel = setelemnth_BM (_.selset, six);
      if (!dumpobjisdumpable_BM (_.du, _.cursel))
        continue;
      _.curmeth = (value_tyBM) objgetclassinfomethod_BM (_.recv, _.cursel);
      assert (isclosure_BM (_.curmeth));
      if (!dumpvalisdumpable_BM (_.du, _.curmeth))
        continue;
      char selidbuf[32];
      memset (selidbuf, 0, sizeof (selidbuf));
      idtocbuf32_BM (objid_BM (_.cursel), selidbuf);
      const char *selname = findobjectname_BM (_.cursel);
      if (selname)
        strbufferprintf_BM (_.sbuf, "\n~: %s |=%s|\t", selidbuf, selname);
      else
        strbufferprintf_BM (_.sbuf, "\n~: %s\t", selidbuf);
      unsigned oldbuflen = strbufferlength_BM (_.sbuf);
      send3_BM (_.curmeth, BMP_dump_value,
                (struct stackframe_stBM *) &_,
                _.sbuf, _.du, taggedint_BM (1));
      unsigned newbuflen = strbufferlength_BM (_.sbuf);
      if (newbuflen == oldbuflen)
        strbufferprintf_BM (_.sbuf, "\t |nometh| __");
    }
  strbufferlessindent_BM (_.sbuf);
  strbufferappendcstr_BM (_.sbuf, "\n~)\n");
  return (value_tyBM) _.recv;
}                               /* end ROUTINE _67IapmpeTLU_8MQKtlK8iAD */


////////////////////////////////////////////////////////////////
//// for the method to dump_value an object or a class
extern objrout_sigBM ROUTINEOBJNAME_BM (_7fCcteNe7aR_3IKHeHjmzff);

value_tyBM
ROUTINEOBJNAME_BM (_7fCcteNe7aR_3IKHeHjmzff)
(const closure_tyBM * clos,
struct stackframe_stBM * stkf,
const value_tyBM arg1,
const value_tyBM arg2, const value_tyBM arg3, const quasinode_tyBM * restargs)
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  assert (isobject_BM (arg1));  // the object to dump
  assert (valtype_BM (arg2) == tydata_strbuffer_BM);
  assert (valtype_BM (arg3) == tydata_dumper_BM);
  assert (valtype_BM ((const value_tyBM) restargs) == tydata_quasinode_BM
          && treewidth_BM ((const value_tyBM) restargs) == 1);
  const value_tyBM arg4 = treenthson_BM ((const value_tyBM) restargs, 0);
  assert (istaggedint_BM (arg4));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv; struct strbuffer_stBM *sbuf;
                 struct dumper_stBM *du; value_tyBM depthv;
                 const objectval_tyBM * curobj;
    );
  _.recv = (arg1);
  _.sbuf = (struct strbuffer_stBM *) arg2;
  _.du = (struct dumper_stBM *) arg3;
  _.depthv = arg4;
  if (!dumpobjisdumpable_BM (_.du, _.recv))
    strbufferprintf_BM (_.sbuf, " __");
  else
    {
      char objidbuf[32];
      idtocbuf32_BM (objid_BM (_.recv), objidbuf);
      const char *n = findobjectname_BM (_.recv);
      if (n)
        strbufferprintf_BM (_.sbuf, "%s |=%s|\t", objidbuf, n);
      else
        strbufferprintf_BM (_.sbuf, "%s", objidbuf);
    };
  return _.sbuf;
}                               /* end ROUTINE _7fCcteNe7aR_3IKHeHjmzff */



//// for the method to dump_data a specially_dumpable
extern objrout_sigBM ROUTINEOBJNAME_BM (_6PmxiZR9WBe_13DwWExCALl);

value_tyBM
ROUTINEOBJNAME_BM (_6PmxiZR9WBe_13DwWExCALl)
(const closure_tyBM * clos,
struct stackframe_stBM * stkf,
const value_tyBM arg1,
const value_tyBM arg2, const value_tyBM arg3, const quasinode_tyBM * restargs)
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 struct dumper_stBM *du; struct strbuffer_stBM *sbuf;
                 value_tyBM closv;
    );
  assert (isobject_BM (arg1));
  _.recv = arg1;
  assert (valtype_BM (arg2) == tydata_dumper_BM);
  _.du = arg2;
  assert (valtype_BM (arg3) == tydata_strbuffer_BM);
  assert (restargs == NULL);
  _.sbuf = arg3;
  _.closv = objgetattr_BM (_.recv, BMP_dump_data);
  if (isclosure_BM (_.closv))
    return apply3_BM (_.closv, (struct stackframe_stBM *) &_,
                      (const value_tyBM) _.recv, _.du, _.sbuf);
  return (value_tyBM) _.recv;
}                               /* end ROUTINE _6PmxiZR9WBe_13DwWExCALl */





static int
cmpnamedpredef_BM (const void *p1, const void *p2)
{
  const objectval_tyBM *ob1 = *(const objectval_tyBM **) p1;
  const objectval_tyBM *ob2 = *(const objectval_tyBM **) p2;
  assert (ob1 != NULL);
  assert (ob2 != NULL);
  const char *n1 = findobjectname_BM (ob1);
  const char *n2 = findobjectname_BM (ob2);
  assert (n1 != NULL);
  assert (n2 != NULL);
  return strcmp (n1, n2);
}                               /* end cmpnamedpredef_BM */

//// for the closure to dump_data the predefined, inside dumper_of_predefined
extern objrout_sigBM ROUTINEOBJNAME_BM (_075tZNHCAMa_7XNNBaNM4qv);

value_tyBM
ROUTINEOBJNAME_BM (_075tZNHCAMa_7XNNBaNM4qv)
(const closure_tyBM * clos,
struct stackframe_stBM * stkf,
const value_tyBM arg1 __attribute__ ((unused)),
const value_tyBM arg2,
const value_tyBM arg3 __attribute__ ((unused)),
const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  assert (valtype_BM (arg2) == tydata_dumper_BM);
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 struct dumper_stBM *du;
                 struct strbuffer_stBM *sbuf;
                 struct strbuffer_stBM *prsbuf;
                 const stringval_tyBM * filnamv;
                 const setval_tyBM * prset; const objectval_tyBM * curpredef;
                 value_tyBM closv;
    );
  _.du = arg2;
  _.closv = (const value_tyBM) clos;
  _.prsbuf = strbuffermake_BM (512 * 1024);
  _.filnamv = closurenthson_BM (_.closv, 0);
  assert (isstring_BM ((const value_tyBM) _.filnamv));
  assert (valtype_BM (_.du) == tydata_dumper_BM);
  const char *basepath = bytstring_BM (_.filnamv);
  strbufferprintf_BM (_.prsbuf,
                      "// generated file for predefined %s\n", basepath);
  _.prset = setpredefinedobjects_BM ();
  unsigned nbpredef = setcardinal_BM (_.prset);
  const objectval_tyBM **arrnamed =
    calloc (nbpredef, sizeof (objectval_tyBM *));
  if (!arrnamed)
    FATAL_BM ("calloc failed for arrnamed (%u) - %m", nbpredef);
  strbufferreserve_BM (_.prsbuf, nbpredef * 512);
  strbufferprintf_BM (_.prsbuf,
                      "#if !defined(HAS_PREDEF_BM) && !defined(HAS_NAMED_PREDEF_BM)\n"
                      "#error missing HAS_PREDEF_BM or HAS_NAMED_PREDEF_BM\n"
                      "#endif\n");
  strbufferprintf_BM (_.prsbuf,
                      "#undef BM_NB_PREDEFINED\n"
                      "#define BM_NB_PREDEFINED %u\n\n", nbpredef);
  strbufferprintf_BM (_.prsbuf,
                      "#ifdef HAS_PREDEF_BM\n"
                      "//HAS_PREDEF_BM(Id,Hi,Lo,Hash)\n");
  unsigned nbnamed = 0;
  unsigned widthnames = 0;
  for (unsigned pix = 0; pix < nbpredef; pix++)
    {
      _.curpredef = setelemnth_BM (_.prset, pix);
      if (pix % 5 == 0)
        strbufferprintf_BM (_.prsbuf, "\n");
      char idbuf[32];
      memset (idbuf, 0, sizeof (idbuf));
      rawid_tyBM curid = objid_BM (_.curpredef);
      idtocbuf32_BM (curid, idbuf);
      strbufferprintf_BM (_.prsbuf, "HAS_PREDEF_BM(%s,%llu,%llu,%lu)",
                          idbuf, (unsigned long long) curid.id_hi,
                          (unsigned long long) curid.id_lo,
                          (unsigned long) hashid_BM (curid));
      const char *n = findobjectname_BM (_.curpredef);
      if (n)
        {
          strbufferprintf_BM (_.prsbuf, " /*=%s*/\n", n);
          arrnamed[nbnamed++] = _.curpredef;
          if (widthnames < strlen (n))
            widthnames = strlen (n);
        }
      else
        strbufferprintf_BM (_.prsbuf, "\n");
    }
  widthnames = (widthnames | 3) + 1;
  strbufferprintf_BM (_.prsbuf, "#undef HAS_PREDEF_BM\n"
                      "#endif /*HAS_PREDEF_BM*/\n");
  strbufferprintf_BM (_.prsbuf, "#undef BM_NB_NAMED_PREDEFINED\n"
                      "#define BM_NB_NAMED_PREDEFINED %u\n", nbnamed);
  qsort (arrnamed, nbnamed, sizeof (objectval_tyBM *), cmpnamedpredef_BM);
  for (unsigned nix = 0; nix < nbnamed; nix++)
    {
      _.curpredef = arrnamed[nix];
      if (nix % 5 == 0)
        strbufferprintf_BM (_.prsbuf, "\n");
      const char *n = findobjectname_BM (_.curpredef);
      assert (n != NULL);
      char idbuf[32];
      memset (idbuf, 0, sizeof (idbuf));
      rawid_tyBM curid = objid_BM (_.curpredef);
      idtocbuf32_BM (curid, idbuf);
      strbufferprintf_BM (_.prsbuf, "#undef BMP_%s\n#undef BMPNID_%s\n", n,
                          n);
      strbufferprintf_BM (_.prsbuf, "#define BMP_%s", n);
      for (int i = widthnames - strlen (n); i > 0; i--)
        strbufferappendcstr_BM (_.prsbuf, " ");
      strbufferprintf_BM (_.prsbuf, "PREDEF_BM(%s)\n", idbuf);
      strbufferprintf_BM (_.prsbuf, "#define BMPNID_%s", n);
      for (int i = widthnames - strlen (n); i > 0; i--)
        strbufferappendcstr_BM (_.prsbuf, " ");
      strbufferprintf_BM (_.prsbuf, "%s\n", idbuf);
    }
  strbufferprintf_BM (_.prsbuf, "\n\n#ifdef HAS_NAMED_PREDEF_BM\n"
                      "//HAS_NAMED_PREDEF_BM(Nam,Id)\n");
  for (unsigned nix = 0; nix < nbnamed; nix++)
    {
      _.curpredef = arrnamed[nix];
      if (nix % 5 == 0)
        strbufferprintf_BM (_.prsbuf, "\n");
      const char *n = findobjectname_BM (_.curpredef);
      assert (n != NULL);
      char idbuf[32];
      memset (idbuf, 0, sizeof (idbuf));
      rawid_tyBM curid = objid_BM (_.curpredef);
      idtocbuf32_BM (curid, idbuf);
      strbufferprintf_BM (_.prsbuf, "HAS_NAMED_PREDEF_BM(%s,%s)\n", n, idbuf);
    };
  strbufferprintf_BM (_.prsbuf, "\n#undef HAS_NAMED_PREDEF_BM\n"
                      "#endif/*HAS_NAMED_PREDEF_BM*/\n\n");
  strbufferprintf_BM (_.prsbuf, "// end of generated file %s\n", basepath);
  char *filpath = NULL;
  asprintf (&filpath, "%s/%s", bytstring_BM (_.du->dump_dir), basepath);
  if (!filpath)
    FATAL_BM ("asprintf failed for %s", basepath);
  strbufferwritetofile_BM (_.prsbuf, filpath);
  strbufferreset_BM (_.prsbuf);
  printf ("wrote predefined file %s\n", filpath);
  ((struct dumper_stBM *) _.du)->dump_wrotefilecount++;
  free (filpath);
  return _.closv;
}                               /* end ROUTINE _075tZNHCAMa_7XNNBaNM4qv */



//// for the closure to dump_data the globals, inside dumper_of_globals
extern objrout_sigBM ROUTINEOBJNAME_BM (_4ENXjApm7Qb_3bXo8F6Jg9z);

value_tyBM
ROUTINEOBJNAME_BM (_4ENXjApm7Qb_3bXo8F6Jg9z)
(const closure_tyBM * clos,
struct stackframe_stBM * stkf,
const value_tyBM arg1 __attribute__ ((unused)),
const value_tyBM arg2,
const value_tyBM arg3 __attribute__ ((unused)),
const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  assert (valtype_BM (arg2) == tydata_dumper_BM);
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 struct dumper_stBM *du;
                 struct strbuffer_stBM *sbuf;
                 struct strbuffer_stBM *prsbuf;
                 const stringval_tyBM * filnamv;
                 const node_tyBM * nodglobv;
                 const stringval_tyBM * curglobname;
                 value_tyBM closv;
    );
  _.du = arg2;
  _.closv = (const value_tyBM) clos;
  _.prsbuf = strbuffermake_BM (512 * 1024);
  _.filnamv = closurenthson_BM (_.closv, 0);
  _.nodglobv = nodeglobalnames_BM (BMP_node);
  assert (isstring_BM ((const value_tyBM) _.filnamv));
  assert (valtype_BM (_.du) == tydata_dumper_BM);
  const char *basepath = bytstring_BM (_.filnamv);
  strbufferprintf_BM (_.prsbuf,
                      "// generated file for globals %s\n", basepath);
  strbufferprintf_BM (_.prsbuf,
                      "#ifndef HAS_GLOBAL_BM\n"
                      "#error missing HAS_GLOBAL_BM\n" "#endif\n\n");
  unsigned nbglob = nodewidth_BM ((const value_tyBM) _.nodglobv);
  strbufferprintf_BM (_.prsbuf,
                      "#undef BM_NB_GLOBAL\n"
                      "#define BM_NB_GLOBAL %d\n", nbglob);
  for (unsigned gix = 0; gix < nbglob; gix++)
    {
      _.curglobname =           //
        (const stringval_tyBM *) nodenthson_BM ((const value_tyBM) _.nodglobv,
                                                gix);
      assert (isstring_BM ((const value_tyBM) _.curglobname));
      strbufferprintf_BM (_.prsbuf, "HAS_GLOBAL_BM(%s)\n",
                          bytstring_BM (_.curglobname));
    };
  strbufferprintf_BM (_.prsbuf, "\n#undef HAS_GLOBAL_BM\n");
  strbufferprintf_BM (_.prsbuf, "\n\n"
                      "// end of generated file %s\n", basepath);
  char *filpath = NULL;
  asprintf (&filpath, "%s/%s", bytstring_BM (_.du->dump_dir), basepath);
  if (!filpath)
    FATAL_BM ("asprintf failed for %s", basepath);
  strbufferwritetofile_BM (_.prsbuf, filpath);
  strbufferreset_BM (_.prsbuf);
  printf ("wrote globals file %s\n", filpath);
  ((struct dumper_stBM *) _.du)->dump_wrotefilecount++;
  free (filpath);
  return _.closv;
}                               /* end ROUTINE _4ENXjApm7Qb_3bXo8F6Jg9z */

//// for the method closure to put_method in class
extern objrout_sigBM ROUTINEOBJNAME_BM (_9imDBaAxOpp_2HI9AuWrEKD);

value_tyBM
ROUTINEOBJNAME_BM (_9imDBaAxOpp_2HI9AuWrEKD)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // recieving class
 const value_tyBM arg2,         // new selector
 const value_tyBM arg3,         // new closure
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; objectval_tyBM * obsel;
                 const closure_tyBM * methclo;
    );
  if (!isobject_BM (arg1))
    return NULL;
  _.recv = (objectval_tyBM *) arg1;
  if (!isobject_BM (arg2))
    return NULL;
  _.obsel = (objectval_tyBM *) arg2;
  if (!isclosure_BM (arg3) && arg3)
    return NULL;
  _.methclo = arg3;
  if (!objhasclassinfo_BM (_.recv))
    return NULL;
  if (_.methclo)
    objclassinfoputmethod_BM (_.recv, _.obsel, _.methclo);
  else
    objclassinforemovemethod_BM (_.recv, _.obsel);
  objtouchnow_BM (_.recv);
  return _.recv;
}                               /* end  ROUTINE _9imDBaAxOpp_2HI9AuWrEKD */

//// for the method closure to init_class in object
extern objrout_sigBM ROUTINEOBJNAME_BM (_2qppG2LJu79_9ljkbLS0eFQ);

value_tyBM
ROUTINEOBJNAME_BM (_2qppG2LJu79_9ljkbLS0eFQ)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // recieving class
 const value_tyBM arg2,         // new superclass
 const value_tyBM arg3 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; objectval_tyBM * obsuperclass;
    );
  if (!isobject_BM (arg1))
    return NULL;
  _.recv = (objectval_tyBM *) arg1;
  if (!isobject_BM (arg2))
    return NULL;
  _.obsuperclass = (objectval_tyBM *) arg2;
  if (objclass_BM (_.obsuperclass) != BMP_class)
    return NULL;
  objputclass_BM (_.recv, BMP_class);
  objputclassinfo_BM (_.recv, _.obsuperclass);
  objtouchnow_BM (_.recv);
  return _.recv;
}                               /* end ROUTINE _2qppG2LJu79_9ljkbLS0eFQ  */



/// for the routine to emit_module in plain_module-s

extern objrout_sigBM ROUTINEOBJNAME_BM (_1gME6zn82Kf_8hzWibLFRfz);

value_tyBM
ROUTINEOBJNAME_BM (_1gME6zn82Kf_8hzWibLFRfz)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // recieving module
 const value_tyBM arg2 __attribute__ ((unused)),
 const value_tyBM arg3 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  enum closureix_en
  {
    closix_simple_module_generation,
    closix_prepare_module,
    closix__LAST
  };
  assert (isclosure_BM ((const value_tyBM) clos));
  assert (closurewidth_BM ((const value_tyBM) clos) >= closix__LAST);
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv;
                 objectval_tyBM * modgenob;
                 objectval_tyBM * simple_module_generation;
                 objectval_tyBM * prepare_module;
                 value_tyBM result;
    );
  if (!isobject_BM (arg1))
    return NULL;
  _.recv = (objectval_tyBM *) arg1;
  _.modgenob = makeobj_BM ();
  _.simple_module_generation =
    objectcast_BM (closurenthson_BM
                   ((void *) clos, closix_simple_module_generation));
  assert (_.simple_module_generation != NULL);
  assert (objecthash_BM (_.simple_module_generation)    //
          == 512189275          /* simple_module_generation |=_2HlKptD03wA_7JJCG7lN5nS| */
    );
  _.prepare_module =
    objectcast_BM (closurenthson_BM ((void *) clos, closix_prepare_module));
  assert (_.prepare_module != NULL);
  assert (objecthash_BM (_.prepare_module)      //
          == 159908881 /* prepare_module |=_17mrxkMdNtH_2CduQ2WDIy5| */ );
  objputclass_BM (_.modgenob, _.prepare_module);
  _.modgenob->ob_data = strbuffermake_BM (1024 * 1024);
  objtouchnow_BM (_.modgenob);
  _.result = send1_BM (_.recv, _.prepare_module,
                       (struct stackframe_stBM *) &_, _.modgenob);
  if (!_.result)
    return NULL;
}                               /* end  ROUTINE _1gME6zn82Kf_8hzWibLFRfz */
