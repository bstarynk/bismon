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
  assert (valtype_BM (_.recv->ob_data) == tydata_classinfo_BM);
  assert (valtype_BM (arg3) == tydata_strbuffer_BM);
  assert (restargs == NULL);
  _.sbuf = arg3;
  _.supercl = objgetclassinfosuperclass_BM ((const value_tyBM) _.recv);
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
  strbufferprintf_BM (_.sbuf, "\t~)");
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



//// for the closure to dump_data the predefined, inside dumper_of_predefined
extern objrout_sigBM ROUTINEOBJNAME_BM (_075tZNHCAMa_7XNNBaNM4qv);



value_tyBM
ROUTINEOBJNAME_BM (_075tZNHCAMa_7XNNBaNM4qv)
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
  _.closv = clos;
#warning should use strbufferwritetofile_BM
  printf ("_075tZNHCAMa_7XNNBaNM4qv should dump the predefined\n");
}                               /* end ROUTINE _075tZNHCAMa_7XNNBaNM4qv */
