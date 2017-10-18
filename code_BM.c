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
  unsigned cnt = 0;
  for (unsigned ix = 0; ix < card; ix++)
    {
      _.curobj = setelemnth_BM (_.recv, ix);
      if (!dumpobjisdumpable_BM (_.du, _.curobj))
        continue;
      char curidbuf[32];
      idtocbuf32_BM (objid_BM (_.curobj), curidbuf);
      if (cnt > 0 && cnt % 4 == 0)
        strbuffernewline_BM (_.sbuf);
      strbufferprintf_BM (_.sbuf, "\t%s", curidbuf);
      cnt++;
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
  unsigned cnt = 0;
  for (unsigned ix = 0; ix < tsiz; ix++)
    {
      _.curobj = tuplecompnth_BM (_.recv, ix);
      if (!dumpobjisdumpable_BM (_.du, _.curobj))
        continue;
      char curidbuf[32];
      idtocbuf32_BM (objid_BM (_.curobj), curidbuf);
      if (cnt > 0 && cnt % 4 == 0)
        strbuffernewline_BM (_.sbuf);
      strbufferprintf_BM (_.sbuf, "\t%s", curidbuf);
      cnt++;
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
  unsigned cnt = 0;
  for (unsigned six = 0; six < width; six++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.recv, six);
      if (!dumpvalisdumpable_BM (_.du, _.curson))
        continue;
      if (cnt > 0 && cnt % 5 == 0)
        strbuffernewline_BM (_.sbuf);
      strbufferprintf_BM (_.sbuf, "\t");
      send3_BM (_.curson, BMP_dump_value,
                (struct stackframe_stBM *) &_,
                _.sbuf, _.du, taggedint_BM (depth + 1));
      cnt++;
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
  unsigned cnt = 0;
  for (unsigned six = 0; six < width; six++)
    {
      _.curson = closurenthson_BM ((const value_tyBM) _.recv, six);
      if (!dumpvalisdumpable_BM (_.du, _.curson))
        {
          strbufferprintf_BM (_.sbuf, "\t__");
          continue;
        }
      if (cnt > 0 && cnt % 5 == 0)
        strbuffernewline_BM (_.sbuf);
      strbufferprintf_BM (_.sbuf, "\t");
      send3_BM (_.curson, BMP_dump_value,
                (struct stackframe_stBM *) &_,
                _.sbuf, _.du, taggedint_BM (depth + 1));
      cnt++;
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




//// for the method to dump_scan°class
extern objrout_sigBM ROUTINEOBJNAME_BM (_4EBQMvthjcP_2OiZxZviSQc);

value_tyBM
ROUTINEOBJNAME_BM (_4EBQMvthjcP_2OiZxZviSQc)    // dump_scan°class 
(const closure_tyBM * clos,
 struct stackframe_stBM * stkf,
 const value_tyBM arg1,
 const value_tyBM arg2, const value_tyBM arg3,
 const quasinode_tyBM * restargs)
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
}                               /* end ROUTINE _4EBQMvthjcP_2OiZxZviSQc dump_scan°class */


//// for the method to dump_data°class
extern objrout_sigBM ROUTINEOBJNAME_BM (_67IapmpeTLU_8MQKtlK8iAD);

value_tyBM
ROUTINEOBJNAME_BM (_67IapmpeTLU_8MQKtlK8iAD)    // dump_data°class
(const closure_tyBM * clos,
 struct stackframe_stBM * stkf,
 const value_tyBM arg1,
 const value_tyBM arg2, const value_tyBM arg3,
 const quasinode_tyBM * restargs)
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



//// for the method to dump_scan°hset_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_4DvEF1tVGFD_6VVLpFn6FPW);

value_tyBM
ROUTINEOBJNAME_BM (_4DvEF1tVGFD_6VVLpFn6FPW)    //  dump_scan°hset_object
(const closure_tyBM * clos,
 struct stackframe_stBM * stkf,
 const value_tyBM arg1,
 const value_tyBM arg2, const value_tyBM arg3,
 const quasinode_tyBM * restargs)
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 struct dumper_stBM *du; const setval_tyBM * setv;
    );
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  WEAKASSERT_BM (valtype_BM (arg2) == tydata_dumper_BM);
  _.du = arg2;
  WEAKASSERT_BM (valtype_BM (_.recv->ob_data) == tydata_hashsetobj_BM);
  assert (arg3 == NULL);
  assert (restargs == NULL);
  _.setv = hashsetobj_to_set_BM (_.recv->ob_data);
  dumpscanvalue_BM (_.du, (value_tyBM) _.setv, 0);
  return (value_tyBM) _.recv;
}                               /* end dump_scan°set_object ROUTINE _4DvEF1tVGFD_6VVLpFn6FPW */



//// for the method to dump_data°hset_object

extern objrout_sigBM ROUTINEOBJNAME_BM (_7GMLV81ntO3_4NHTv7fCL0A);

value_tyBM
ROUTINEOBJNAME_BM (_7GMLV81ntO3_4NHTv7fCL0A)    // dump_data°hset_object
(const closure_tyBM * clos,
 struct stackframe_stBM * stkf,
 const value_tyBM arg1,
 const value_tyBM arg2, const value_tyBM arg3,
 const quasinode_tyBM * restargs)
{
  enum constix_en
  {
    constix_dump_value,
    constix_put,
    constix__LAST
  };
  objectval_tyBM *k_dump_value = NULL;
  objectval_tyBM *k_put = NULL;
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 const closure_tyBM * clos; struct dumper_stBM *du;
                 struct strbuffer_stBM *sbuf; const setval_tyBM * setv;
                 value_tyBM dumpres;
    );
  objectval_tyBM *closconn = NULL;
  const node_tyBM *constnodv = NULL;
  _.clos = clos;
  closconn = closureconn_BM ((const value_tyBM) clos);
  assert (isobject_BM (closconn));
  constnodv = closconn->ob_data;
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  WEAKASSERT_BM (valtype_BM (arg2) == tydata_dumper_BM);
  _.du = arg2;
  WEAKASSERT_BM (valtype_BM (arg3) == tydata_strbuffer_BM);
  WEAKASSERT_BM (restargs == NULL);
  _.sbuf = arg3;
  WEAKASSERT_BM (valtype_BM (_.recv->ob_data) == tydata_hashsetobj_BM);
  assert (arg3 == NULL);
  assert (restargs == NULL);
  /** constnodv is 
     * const (dump_value put)
  **/
  WEAKASSERT_BM (isnode_BM ((const value_tyBM) constnodv)
                 && valhash_BM ((const value_tyBM) constnodv) == 3410673963
                 && nodewidth_BM ((const value_tyBM) constnodv) >=
                 constix__LAST);
  k_dump_value =
    objectcast_BM (nodenthson_BM ((void *) constnodv, constix_dump_value));
  WEAKASSERT_BM (k_dump_value == BMP_dump_value);
  k_put = objectcast_BM (nodenthson_BM ((void *) constnodv, constix_put));
  _.setv = hashsetobj_to_set_BM (_.recv->ob_data);
  strbufferprintf_BM (_.sbuf, "!~ todo (~\t");
  strbuffermoreindent_BM (_.sbuf);
  _.dumpres = send3_BM (k_put, BMP_dump_value,
                        (struct stackframe_stBM *) &_,
                        _.sbuf, _.du, taggedint_BM (0));
  strbufferprintf_BM (_.sbuf, "\t");
  _.dumpres = send3_BM ((value_tyBM) _.setv, BMP_dump_value,
                        (struct stackframe_stBM *) &_,
                        _.sbuf, _.du, taggedint_BM (0));
  strbufferlessindent_BM (_.sbuf);
  strbufferappendcstr_BM (_.sbuf, "\n~)\n");
  return (value_tyBM) _.recv;
}                               /* end dump_data hset_object ROUTINE _7GMLV81ntO3_4NHTv7fCL0A  */



//// for the method to get°hset_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_26FUvWKvkYr_5hyqhhV8NEh);

value_tyBM
ROUTINEOBJNAME_BM (_26FUvWKvkYr_5hyqhhV8NEh)    // get°hset_object
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         /* reciever */
 const value_tyBM arg2 /*elem */ ,
 const value_tyBM arg3 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; value_tyBM elem;
                 objectval_tyBM * curob; const closure_tyBM * clos;
                 const setval_tyBM * setv;
    );
  struct hashsetobj_stBM *hset = NULL;
  _.clos = clos;
  if (!isobject_BM (arg1))
    return NULL;
  _.recv = arg1;
  _.elem = arg2;
  hset = hashsetobjcast_BM (_.recv->ob_data);
  if (!hset)
    return NULL;
  if (isobject_BM (_.elem))
    {
      if (hashsetobj_contains_BM (hset, _.elem))
        return _.elem;
      return NULL;
    }
  else if (issequence_BM (_.elem))
    {
      unsigned lnseq = sequencesize_BM (_.elem);
      const objectval_tyBM *tinyarr[TINYSIZE_BM] = { };
      const objectval_tyBM **arr =
        (lnseq < TINYSIZE_BM) ? tinyarr
        : calloc (lnseq, sizeof (objectval_tyBM *));
      if (!arr)
        FATAL_BM ("calloc %u failure in get°hset_object", lnseq);
      unsigned cnt = 0;
      for (unsigned ix = 0; ix < lnseq; ix++)
        {
          _.curob = sequencenthcomp_BM (_.elem, ix);
          if (hashsetobj_contains_BM (hset, _.curob))
            arr[cnt++] = _.curob;
        };
      _.setv = makeset_BM (arr, cnt);
      if (arr != tinyarr)
        free (arr);
      return (value_tyBM) _.setv;
    }
  else if (!_.elem)
    {
      _.setv = hashsetobj_to_set_BM (hset);
      return (value_tyBM) _.setv;
    }
  return NULL;
}                               /* end ROUTINE _26FUvWKvkYr_5hyqhhV8NEh get°hset_object */



//// for the method to put°hset_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_91iTl2vqF09_72WJj4swbNi);

value_tyBM
ROUTINEOBJNAME_BM (_91iTl2vqF09_72WJj4swbNi)    // put°hset_object
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         /* reciever */
 const value_tyBM arg2 /*putseq */ ,
 const value_tyBM arg3 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv;
                 const seqobval_tyBM * putseqv; objectval_tyBM * curob;
                 const closure_tyBM * clos;
    );
  _.clos = clos;
  if (!isobject_BM (arg1))
    return NULL;
  _.recv = arg1;
  if (!issequence_BM (arg2))
    return NULL;
  _.putseqv = arg2;
  unsigned lnseq = sequencesize_BM (_.putseqv);
  _.recv->ob_data = hashsetobj_grow_BM (NULL, 9 * lnseq / 8 + 2);
  for (unsigned ix = 0; ix < lnseq; ix++)
    {
      _.curob = sequencenthcomp_BM (_.putseqv, ix);
      _.recv->ob_data = hashsetobj_add_BM (_.recv->ob_data, _.curob);
    };
  return _.recv;
}                               /* end ROUTINE _91iTl2vqF09_72WJj4swbNi put°hset_object */


//// for the method to add°hset_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_2juH5YMCcog_8pQGCuE5mod);

value_tyBM
ROUTINEOBJNAME_BM (_2juH5YMCcog_8pQGCuE5mod)    // add°hset_object
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         /* reciever */
 const value_tyBM arg2 /*addend */ ,
 const value_tyBM arg3 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; value_tyBM addend;
                 const seqobval_tyBM * putseqv; objectval_tyBM * curob;
                 const closure_tyBM * clos;
    );
  struct hashsetobj_stBM *hset = NULL;
  _.clos = clos;
  if (!isobject_BM (arg1))
    return NULL;
  _.recv = arg1;
  hset = hashsetobjcast_BM (_.recv->ob_data);
  _.addend = arg2;
  if (isobject_BM (_.addend))
    {
      _.recv->ob_data = hset =
        hashsetobj_add_BM (hset, (objectval_tyBM *) _.addend);
      return _.recv;
    }
  else if (issequence_BM (_.addend))
    {
      unsigned nbadd = sequencesize_BM (_.addend);
      _.recv->ob_data = hset = hashsetobj_grow_BM (hset, nbadd + 1);
      for (unsigned ix = 0; ix < nbadd; ix++)
        {
          _.curob = sequencenthcomp_BM (_.addend, ix);
          hset = hashsetobj_add_BM (hset, _.curob);
        };
      _.recv->ob_data = hset;
      return _.recv;
    }
  return NULL;
}                               /* end ROUTINE _2juH5YMCcog_8pQGCuE5mod add°hset_object */

// for the method remove°hset_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_5hedSPIXD0o_5ef69rR2kzb);

value_tyBM
ROUTINEOBJNAME_BM (_5hedSPIXD0o_5ef69rR2kzb)    // remove°hset_object
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         /* reciever */
 const value_tyBM arg2 /*removedv */ ,
 const value_tyBM arg3 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; value_tyBM removedv;
                 const seqobval_tyBM * putseqv; objectval_tyBM * curob;
                 const closure_tyBM * clos;
    );
  struct hashsetobj_stBM *hset = NULL;
  _.clos = clos;
  if (!isobject_BM (arg1))
    return NULL;
  _.recv = arg1;
  if (!_.recv->ob_data)
    return _.recv;
  hset = hashsetobjcast_BM (_.recv->ob_data);
  if (!hset)
    return NULL;
  _.removedv = arg2;
  if (isobject_BM (_.removedv))
    {
      _.recv->ob_data = hset = hashsetobj_remove_BM (hset, _.removedv);
      return _.recv;
    }
  else if (issequence_BM (_.removedv))
    {
      unsigned nbrem = sequencesize_BM (_.removedv);
      for (unsigned ix = 0; ix < nbrem; ix++)
        {
          _.curob = sequencenthcomp_BM (_.removedv, ix);
          hset = hashsetobj_remove_BM (hset, _.curob);
        };
      if (nbrem > TINYSIZE_BM)
        hset = hashsetobj_grow_BM (hset, 1);    /* could reorganize the hset */
      _.recv->ob_data = hset;
      return _.recv;
    }
  else
    return NULL;
}                               /* end ROUTINE _5hedSPIXD0o_5ef69rR2kzb  remove°hset_object */



//// for the method to give the set°hset_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_88cUYsDqSFO_0DKwKLSOmpm);

value_tyBM ROUTINEOBJNAME_BM (_88cUYsDqSFO_0DKwKLSOmpm) (const closure_tyBM * clos, struct stackframe_stBM * stkf, const value_tyBM arg1,       /* reciever */
                                                         const value_tyBM arg2
                                                         __attribute__ ((unused)), const value_tyBM arg3 __attribute__ ((unused)), const quasinode_tyBM * restargs __attribute__ ((unused)))
{;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv; const closure_tyBM * clos;
                 const setval_tyBM * setv;
    );
  _.clos = clos;
  _.recv = arg1;
  if (!isobject_BM (arg1))
    return NULL;
  if (valtype_BM (_.recv->ob_data) != tydata_hashsetobj_BM)
    return NULL;
  _.setv = hashsetobj_to_set_BM (_.recv->ob_data);
  return (value_tyBM) _.setv;
}                               /* end ROUTINE _88cUYsDqSFO_0DKwKLSOmpm set of hset_object */


/****************************************************************/

//// for the method to dump_scan°assoc_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_8MU0cEcpEYN_5SVe0jrv36o);

value_tyBM
ROUTINEOBJNAME_BM (_8MU0cEcpEYN_5SVe0jrv36o)    //  dump_scan°assoc_object
(const closure_tyBM * clos,
 struct stackframe_stBM * stkf,
 const value_tyBM arg1,
 const value_tyBM arg2, const value_tyBM arg3,
 const quasinode_tyBM * restargs)
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 const objectval_tyBM * curattrob; value_tyBM curval;
                 struct dumper_stBM *du; const setval_tyBM * setv;
    );
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  WEAKASSERT_BM (valtype_BM (arg2) == tydata_dumper_BM);
  _.du = arg2;
  if (!_.recv->ob_data)
    return (value_tyBM) _.recv;
  WEAKASSERT_BM (isassoc_BM (_.recv->ob_data));
  anyassoc_tyBM *assoc = assoccast_BM (_.recv->ob_data);
  if (!assoc)
    return NULL;
  assert (arg3 == NULL);
  assert (restargs == NULL);
  _.setv = assoc_setattrs_BM (assoc);
  dumpscanvalue_BM (_.du, (const value_tyBM) _.setv, 0);
  unsigned nbattr = setcardinal_BM (_.setv);
  for (unsigned ix = 0; ix < nbattr; ix++)
    {
      _.curattrob = setelemnth_BM (_.setv, ix);
      if (!dumpobjisdumpable_BM (_.du, _.curattrob))
        continue;
      _.curval = assoc_getattr_BM (assoc, _.curattrob);
      dumpscanvalue_BM (_.du, _.curval, 0);
    }
  return (value_tyBM) _.recv;
}                               /* end dump_scan°assoc_object ROUTINE _8MU0cEcpEYN_5SVe0jrv36o */


////////////////

//// for the method to dump_data°assoc_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_9EytjXNb76D_1ZP3iSk9cuu);

value_tyBM
ROUTINEOBJNAME_BM (_9EytjXNb76D_1ZP3iSk9cuu)    // dump_data°assoc_object
(const closure_tyBM * clos,
 struct stackframe_stBM * stkf,
 const value_tyBM arg1,
 const value_tyBM arg2, const value_tyBM arg3,
 const quasinode_tyBM * restargs)
{
  enum constix_en
  {
    constix_dump_value,
    constix_put,
    constix__LAST
  };
  objectval_tyBM *k_dump_value = NULL;
  objectval_tyBM *k_put = NULL;
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 const closure_tyBM * clos; struct dumper_stBM *du;
                 struct strbuffer_stBM *sbuf; const setval_tyBM * setv;
                 objectval_tyBM * curattrob; value_tyBM curval;
                 value_tyBM dumpres;
    );
  objectval_tyBM *closconn = NULL;
  const node_tyBM *constnodv = NULL;
  _.clos = clos;
  closconn = closureconn_BM ((const value_tyBM) clos);
  assert (isobject_BM (closconn));
  constnodv = closconn->ob_data;
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  WEAKASSERT_BM (valtype_BM (arg2) == tydata_dumper_BM);
  _.du = arg2;
  WEAKASSERT_BM (valtype_BM (arg3) == tydata_strbuffer_BM);
  WEAKASSERT_BM (restargs == NULL);
  _.sbuf = arg3;
  assert (arg3 == NULL);
  assert (restargs == NULL);
  /** constnodv is 
     * const (dump_value put)
  **/
  WEAKASSERT_BM (isnode_BM ((const value_tyBM) constnodv)
                 && valhash_BM ((const value_tyBM) constnodv) == 3410673963
                 && nodewidth_BM ((const value_tyBM) constnodv) >=
                 constix__LAST);
  k_dump_value =
    objectcast_BM (nodenthson_BM ((void *) constnodv, constix_dump_value));
  WEAKASSERT_BM (k_dump_value == BMP_dump_value);
  k_put = objectcast_BM (nodenthson_BM ((void *) constnodv, constix_put));
  WEAKASSERT_BM (isobject_BM ((value_tyBM) _.recv));
  WEAKASSERT_BM (isassoc_BM (_.recv->ob_data));
  anyassoc_tyBM *assoc = assoccast_BM (_.recv->ob_data);
  if (!assoc)
    return NULL;
  _.setv = assoc_setattrs_BM (assoc);
  unsigned nbattr = setcardinal_BM (_.setv);
  int cnt = 0;
  strbufferprintf_BM (_.sbuf, "!~ todo (~\t");
  strbuffermoreindent_BM (_.sbuf);
  for (unsigned ix = 0; ix < nbattr; ix++)
    {
      _.curattrob = setelemnth_BM (_.setv, ix);
      if (!dumpobjisdumpable_BM (_.du, _.curattrob))
        continue;
      _.curval = assoc_getattr_BM (assoc, _.curattrob);
      if (cnt > 0)
        strbufferprintf_BM (_.sbuf, "\n!& ");
      else
        strbufferprintf_BM (_.sbuf, " ");
      _.dumpres = send3_BM (k_put, BMP_dump_value,
                            (struct stackframe_stBM *) &_,
                            _.sbuf, _.du, taggedint_BM (0));
      strbufferprintf_BM (_.sbuf, "\t");
      _.dumpres = send3_BM (_.curattrob, BMP_dump_value,
                            (struct stackframe_stBM *) &_,
                            _.sbuf, _.du, taggedint_BM (0));
      strbufferprintf_BM (_.sbuf, "\t");
      _.dumpres = send3_BM (_.curval, BMP_dump_value,
                            (struct stackframe_stBM *) &_,
                            _.sbuf, _.du, taggedint_BM (0));
      cnt++;
    };
  strbufferlessindent_BM (_.sbuf);
  strbufferappendcstr_BM (_.sbuf, "\n~)\n");
  return (value_tyBM) _.recv;
}                               /* end ROUTINE _9EytjXNb76D_1ZP3iSk9cuu dump_data°assoc_object */


//// for the method set°assoc_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_4zaM2Itdsuq_9qNJK0HbcQI);

value_tyBM
ROUTINEOBJNAME_BM (_4zaM2Itdsuq_9qNJK0HbcQI)    //  set°assoc_object
(const closure_tyBM * clos, struct stackframe_stBM * stkf, const value_tyBM arg1,       /*recv */
 const value_tyBM arg2 __attribute__ ((unused)),
 const value_tyBM arg3 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv; const closure_tyBM * clos;
                 const setval_tyBM * setv;
    );
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  anyassoc_tyBM *assoc = assoccast_BM (_.recv->ob_data);
  if (!assoc)
    return NULL;
  _.setv = assoc_setattrs_BM (assoc);
  return (value_tyBM) _.setv;
}                               /* end ROUTINE _4zaM2Itdsuq_9qNJK0HbcQ   set°assoc_object */



//// for the method get°assoc_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_4icYJnKsN0o_4xm5UbQOMTe);

value_tyBM
ROUTINEOBJNAME_BM (_4icYJnKsN0o_4xm5UbQOMTe)    //  get°assoc_object
(const closure_tyBM * clos, struct stackframe_stBM * stkf, const value_tyBM arg1,       /* recv */
 const value_tyBM arg2,         /* obattr */
 const value_tyBM arg3 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv; const objectval_tyBM * obattr;
                 const closure_tyBM * clos;
    );
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  anyassoc_tyBM *assoc = assoccast_BM (_.recv->ob_data);
  if (!assoc)
    return NULL;
  if (!isobject_BM (arg2))
    return NULL;
  _.obattr = objectcast_BM (arg2);
  return assoc_getattr_BM (assoc, _.obattr);
}                               /* end ROUTINE _4icYJnKsN0o_4xm5UbQOMTe get°assoc_object */



//// for the method put°assoc_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_6eD9Y1qYcnj_8uVDhxjBpG8);

value_tyBM
ROUTINEOBJNAME_BM (_6eD9Y1qYcnj_8uVDhxjBpG8)    //  put°assoc_object
(const closure_tyBM * clos, struct stackframe_stBM * stkf, const value_tyBM arg1,       /* recv */
 const value_tyBM arg2,         /* obattr */
 const value_tyBM arg3,         /* val */
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv;
                 const objectval_tyBM * obattr; const closure_tyBM * clos;
                 value_tyBM valattr;
    );
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  if (!isobject_BM ((value_tyBM) _.recv))
    return NULL;
  anyassoc_tyBM *assoc = assoccast_BM (_.recv->ob_data);
  if (!isobject_BM (arg2))
    return NULL;
  _.obattr = objectcast_BM (arg2);
  _.valattr = arg3;
  _.recv->ob_data = assoc = assoc_addattr_BM (assoc, _.obattr, _.valattr);
  return _.recv;
}                               /* end ROUTINE _6eD9Y1qYcnj_8uVDhxjBpG8   put°assoc_object */



//// for the method remove°assoc_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_0ekJdzLOqAI_8mejMqkwuKQ);

value_tyBM
ROUTINEOBJNAME_BM (_0ekJdzLOqAI_8mejMqkwuKQ)    //  remove°assoc_object
(const closure_tyBM * clos, struct stackframe_stBM * stkf, const value_tyBM arg1,       /* recv */
 const value_tyBM arg2,         /* attrs */
 const value_tyBM arg3 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; objectval_tyBM * obattr;
                 value_tyBM attr; const closure_tyBM * clos;
    );
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  if (!isobject_BM ((value_tyBM) _.recv))
    return NULL;
  anyassoc_tyBM *assoc = assoccast_BM (_.recv->ob_data);
  if (!isobject_BM (arg2))
    return NULL;
  _.attr = (arg2);
  if (isobject_BM (_.attr))
    {
      _.recv->ob_data = assoc = assoc_removeattr_BM (assoc, _.attr);
      return _.recv;
    }
  else if (issequence_BM (_.attr))
    {
      unsigned ln = sequencesize_BM (_.attr);
      for (unsigned ix = 0; ix < ln; ix++)
        {
          _.obattr = sequencenthcomp_BM (_.attr, ix);
          assoc = assoc_removeattr_BM (assoc, _.obattr);
        }
      _.recv->ob_data = assoc;
      return _.recv;
    }
  return NULL;
}                               /* end ROUTINE _0ekJdzLOqAI_8mejMqkwuKQ remove°assoc_object */


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


//// for the method to dump_data a basiclo_function or any object with a value data
extern objrout_sigBM ROUTINEOBJNAME_BM (_7D36kHemyWQ_0YfwWnUhR9Y);

value_tyBM
ROUTINEOBJNAME_BM (_7D36kHemyWQ_0YfwWnUhR9Y)
(const closure_tyBM * clos,
struct stackframe_stBM * stkf,
const value_tyBM arg1,
const value_tyBM arg2, const value_tyBM arg3, const quasinode_tyBM * restargs)
{
  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 struct dumper_stBM *du; struct strbuffer_stBM *sbuf;
                 value_tyBM obval;
    );
  assert (isobject_BM (arg1));
  _.recv = arg1;
  assert (valtype_BM (arg2) == tydata_dumper_BM);
  _.du = arg2;
  assert (valtype_BM (arg3) == tydata_strbuffer_BM);
  assert (restargs == NULL);
  _.sbuf = arg3;
  _.obval = _.recv->ob_data;
  int tyval = valtype_BM (_.obval);
  if (tyval >= type_FIRST_BM && tyval <= type_LASTREAL_BM)
    {
      strbufferprintf_BM (_.sbuf, "\n" "!~value (~ ");
      unsigned oldbuflen = strbufferlength_BM (_.sbuf);
      send3_BM (_.obval, BMP_dump_value,
                (struct stackframe_stBM *) &_,
                _.sbuf, _.du, taggedint_BM (1));
      unsigned newbuflen = strbufferlength_BM (_.sbuf);
      if (newbuflen == oldbuflen)
        strbufferprintf_BM (_.sbuf, "\t |novalue| __");
      strbufferprintf_BM (_.sbuf, " ~)\n");
      return (value_tyBM) _.recv;
    }
  return NULL;
}                               /* end ROUTINE _7D36kHemyWQ_0YfwWnUhR9Y */


//// for the method to dump_scan a basiclo_function or any object with a genuine value as data
extern objrout_sigBM ROUTINEOBJNAME_BM (_9UhDZeDdg2r_55lUqYDPUiF);

value_tyBM
ROUTINEOBJNAME_BM (_9UhDZeDdg2r_55lUqYDPUiF)
(const closure_tyBM * clos,
struct stackframe_stBM * stkf,
const value_tyBM arg1,
const value_tyBM arg2, const value_tyBM arg3, const quasinode_tyBM * restargs)
{

  assert (!clos || isclosure_BM ((const value_tyBM) clos));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv; struct dumper_stBM *du;
                 value_tyBM obval;
    );
  assert (isobject_BM (arg1));
  _.recv = arg1;
  assert (valtype_BM (arg2) == tydata_dumper_BM);
  _.du = arg2;
  assert (arg3 == NULL);
  assert (restargs == NULL);
  _.obval = _.recv->ob_data;
  int tyval = valtype_BM (_.obval);
  if (tyval >= type_FIRST_BM && tyval <= type_LASTREAL_BM)
    {
      dumpscanvalue_BM (_.du, (const value_tyBM) _.obval, 0);
      return (value_tyBM) _.recv;
    }
  return NULL;
}                               /* end ROUTINE _9UhDZeDdg2r_55lUqYDPUiF */


/// for todo_send closures 

extern objrout_sigBM ROUTINEOBJNAME_BM (_9mdRnBqdqf5_9UvgSFA7wIY);

value_tyBM
ROUTINEOBJNAME_BM (_9mdRnBqdqf5_9UvgSFA7wIY)
(const closure_tyBM * clos,
struct stackframe_stBM * stkf,
const value_tyBM arg1 __attribute__ ((unused)),
const value_tyBM arg2 __attribute__ ((unused)),
const value_tyBM arg3 __attribute__ ((unused)),
const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  enum
  { closix_ldobj,
    closix_obsel,
    closix__REST
  };
  assert (isclosure_BM ((const value_tyBM) clos)
          && closurewidth_BM ((const value_tyBM) clos) >= closix__REST);
  unsigned wclos = closurewidth_BM ((const value_tyBM) clos);
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * ldobj;
                 objectval_tyBM * obsel;
    );
  _.ldobj =
    objectcast_BM (closurenthson_BM ((const value_tyBM) clos, closix_ldobj));
  _.obsel =
    objectcast_BM (closurenthson_BM ((const value_tyBM) clos, closix_obsel));
  const value_tyBM *args = clos->nodt_sons + closix__REST;
  unsigned nbargs = wclos - closix__REST;
  switch (nbargs)
    {
    case 0:
      return send0_BM (_.ldobj, _.obsel, (struct stackframe_stBM *) &_);
    case 1:
      return send1_BM (_.ldobj, _.obsel, (struct stackframe_stBM *) &_,
                       args[0]);
    case 2:
      return send2_BM (_.ldobj, _.obsel, (struct stackframe_stBM *) &_,
                       args[0], args[1]);
    case 3:
      return send3_BM (_.ldobj, _.obsel, (struct stackframe_stBM *) &_,
                       args[0], args[1], args[2]);
    case 4:
      return send4_BM (_.ldobj, _.obsel, (struct stackframe_stBM *) &_,
                       args[0], args[1], args[2], args[3]);
    case 5:
      return send5_BM (_.ldobj, _.obsel, (struct stackframe_stBM *) &_,
                       args[0], args[1], args[2], args[3], args[4]);
    case 6:
      return send6_BM (_.ldobj, _.obsel, (struct stackframe_stBM *) &_,
                       args[0], args[1], args[2], args[3], args[4], args[5]);
    case 7:
      return send7_BM (_.ldobj, _.obsel, (struct stackframe_stBM *) &_,
                       args[0], args[1], args[2], args[3], args[4], args[5],
                       args[6]);
    case 8:
      return send8_BM (_.ldobj, _.obsel, (struct stackframe_stBM *) &_,
                       args[0], args[1], args[2], args[3], args[4], args[5],
                       args[6], args[7]);
    default:;
    }
  FATAL_BM ("too many %u arguments in todo_send", nbargs);
}                               /* end ROUTINE todo_send _9mdRnBqdqf5_9UvgSFA7wIY */


/// for todo_apply closures 

extern objrout_sigBM ROUTINEOBJNAME_BM (_3W8d51P1dJh_3b1BrOW6pua);

value_tyBM
ROUTINEOBJNAME_BM (_3W8d51P1dJh_3b1BrOW6pua)
(const closure_tyBM * clos,
struct stackframe_stBM * stkf,
const value_tyBM arg1 __attribute__ ((unused)),
const value_tyBM arg2 __attribute__ ((unused)),
const value_tyBM arg3 __attribute__ ((unused)),
const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  enum
  {
    closix_closure,
    closix_ldobj,
    closix__REST
  };
  assert (isclosure_BM ((const value_tyBM) clos)
          && closurewidth_BM ((const value_tyBM) clos) >= closix__REST);
  unsigned wclos = closurewidth_BM ((const value_tyBM) clos);
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * closv;
                 objectval_tyBM * ldobj;
    );
  _.closv =
    closurecast_BM (closurenthson_BM
                    ((const value_tyBM) clos, closix_closure));
  _.ldobj =
    objectcast_BM (closurenthson_BM ((const value_tyBM) clos, closix_ldobj));
  const value_tyBM *args = clos->nodt_sons + closix__REST;
  unsigned nbargs = wclos - closix__REST;
  switch (nbargs)
    {
    case 0:
      return apply1_BM (_.closv, (struct stackframe_stBM *) &_, _.ldobj);
    case 1:
      return apply2_BM (_.closv, (struct stackframe_stBM *) &_, _.ldobj,
                        args[0]);
    case 2:
      return apply3_BM (_.closv, (struct stackframe_stBM *) &_, _.ldobj,
                        args[0], args[1]);
    case 3:
      return apply4_BM (_.closv, (struct stackframe_stBM *) &_, _.ldobj,
                        args[0], args[1], args[2]);
    case 4:
      return apply5_BM (_.closv, (struct stackframe_stBM *) &_, _.ldobj,
                        args[0], args[1], args[2], args[3]);
    case 5:
      return apply6_BM (_.closv, (struct stackframe_stBM *) &_, _.ldobj,
                        args[0], args[1], args[2], args[3], args[4]);
    case 6:
      return apply7_BM (_.closv, (struct stackframe_stBM *) &_, _.ldobj,
                        args[0], args[1], args[2], args[3], args[4], args[5]);
    case 7:
      return apply8_BM (_.closv, (struct stackframe_stBM *) &_, _.ldobj,
                        args[0], args[1], args[2], args[3], args[4], args[5],
                        args[6]);
    default:;
    }
  FATAL_BM ("too many %u arguments in todo_apply", nbargs);
}                               /* end ROUTINE todo_apply _3W8d51P1dJh_3b1BrOW6pua */


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
  enum constix_en
  {
    constix_simple_module_generation,
    constix_prepare_module,
    constix_plain_module,
    constix_generate_module,
    constix__LAST
  };
  enum closureix_en
  {
    closix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv;
                 const closure_tyBM * clos;
                 objectval_tyBM * closconn;
                 objectval_tyBM * modgenob;
                 objectval_tyBM * simple_module_generation;
                 objectval_tyBM * prepare_module;
                 objectval_tyBM * plain_module;
                 objectval_tyBM * generate_module;
                 value_tyBM resprep; value_tyBM resgen;
                 const node_tyBM * constnodv;
    );
  assert (isclosure_BM ((const value_tyBM) clos));
  _.clos = clos;
  // assert (closurewidth_BM ((const value_tyBM) clos) >= closix__LAST);
  _.closconn = closureconn_BM ((const value_tyBM) clos);
  assert (isobject_BM (_.closconn));
  _.constnodv = _.closconn->ob_data;
  /** constnodv is 
     * const (simple_module_generation
              prepare_module  plain_module generate_module)
  **/
  assert (isnode_BM ((const value_tyBM) _.constnodv)
          && valhash_BM ((const value_tyBM) _.constnodv) == 3356172998);
  assert (nodewidth_BM ((const value_tyBM) _.constnodv) >= constix__LAST);
  if (!isobject_BM (arg1))
    return NULL;
  _.recv = (objectval_tyBM *) arg1;
  DBGPRINTF_BM ("@@plain_module°emit_module recv=%s", objectdbg_BM (_.recv));
  _.modgenob = makeobj_BM ();
  _.simple_module_generation =
    objectcast_BM (nodenthson_BM
                   ((void *) _.constnodv, constix_simple_module_generation));
  assert (_.simple_module_generation != NULL);
  assert (objecthash_BM (_.simple_module_generation)    //
          == 512189275          /* simple_module_generation |=_2HlKptD03wA_7JJCG7lN5nS| */
    );
  _.prepare_module =
    objectcast_BM (nodenthson_BM
                   ((void *) _.constnodv, constix_prepare_module));
  assert (_.prepare_module != NULL);
  assert (objecthash_BM (_.prepare_module)      //
          == 159908881 /* prepare_module |=_17mrxkMdNtH_2CduQ2WDIy5| */ );
  _.plain_module =
    objectcast_BM (nodenthson_BM
                   ((void *) _.constnodv, constix_plain_module));
  assert (_.plain_module != NULL);
  assert (objecthash_BM (_.plain_module)        //
          == 1032996964 /* plain_module |=_8g1WBJBhDT9_1QK8IcuWYx2| */ );
  _.generate_module =
    objectcast_BM (nodenthson_BM
                   ((void *) _.constnodv, constix_generate_module));
  assert (_.generate_module != NULL);
  assert (objecthash_BM (_.generate_module)     //
          == 731255930 /* generate_module |=_9mq0jsuz4XQ_4doHfd987Q6| */ );
  objputclass_BM (_.modgenob, _.simple_module_generation);
  objputattr_BM (_.modgenob, _.plain_module, _.recv);
  _.modgenob->ob_data = strbuffermake_BM (1024 * 1024);
  objtouchnow_BM (_.modgenob);
  _.resprep = send1_BM (_.recv, _.prepare_module,
                        (struct stackframe_stBM *) &_, _.modgenob);
  if (!_.resprep)
    {
      DBGPRINTF_BM ("@@emit_module recv=%s prepare_module failed",
                    objectdbg_BM (_.recv));
      return NULL;
    }
  else
    DBGPRINTF_BM
      ("@@emit_module recv=%s prepare_module done before generate_module",
       objectdbg_BM (_.recv));
  _.resgen =
    send2_BM (_.recv, _.generate_module, (struct stackframe_stBM *) &_,
              _.modgenob, _.resprep);
  if (!_.resgen)
    {
      DBGPRINTF_BM ("@@emit_module recv=%s generate_module failed",
                    objectdbg_BM (_.recv));
      return NULL;
    }
  else
    DBGPRINTF_BM ("@@emit_module recv=%s generate_module done",
                  objectdbg_BM (_.recv));
  return _.recv;
#warning emit_module of plain_module incomplete
}                               /* end  ROUTINE _1gME6zn82Kf_8hzWibLFRfz */




// for the method to prepare_module in basiclo_temporary_module &
// basiclo_dumpable_module

extern objrout_sigBM ROUTINEOBJNAME_BM (_8zNBXSMY2Ts_1VI5dmY4umA);
value_tyBM
ROUTINEOBJNAME_BM (_8zNBXSMY2Ts_1VI5dmY4umA)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // recieving module
 const value_tyBM arg2,         // module generator
 const value_tyBM arg3 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  enum constix_en
  {
    constix_simple_module_generation,
    constix_functions_set,
    constix_basiclo_function,
    constix_complete_module,
    constix__LAST
  };
  enum closureix_en
  {
    closix__LAST
  };
  assert (isclosure_BM ((const value_tyBM) clos));
  //assert (closurewidth_BM ((const value_tyBM) clos) >= closix__LAST);
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv;
                 objectval_tyBM * closconn;
                 const node_tyBM * constnodv;
                 objectval_tyBM * modgen;       //
                 objectval_tyBM * simple_module_generation;
                 objectval_tyBM * functions_set;        //
                 objectval_tyBM * basiclo_function;
                 objectval_tyBM * complete_module;
                 struct hashsetobj_stBM *hset;
                 value_tyBM curcomp;    //
                 seqobval_tyBM * curseq;        //
                 value_tyBM partres;    //
                 setval_tyBM * setfun;
    );
  if (!isobject_BM (arg1))
    return NULL;
  _.recv = (objectval_tyBM *) arg1;
  DBGPRINTF_BM ("@@prepare_module°basiclo*module _8zNBXSMY2Ts_1VI5dmY4umA"
                "  recv=%s\n" "... is a %s\n", objectdbg_BM (_.recv),
                objectdbg1_BM (objclass_BM (_.recv)));
  if (!isobject_BM (arg2))
    return NULL;
  _.modgen = (objectval_tyBM *) arg2;
  DBGPRINTF_BM ("@@prepare_module°basiclo*module modgen=%s\n"
                ".... is a %s\n", objectdbg_BM (_.modgen),
                objectdbg1_BM (objclass_BM (_.modgen)));
  _.closconn = closureconn_BM ((const value_tyBM) clos);
  assert (isobject_BM (_.closconn));
  _.constnodv = _.closconn->ob_data;
  /** _.constnodv should be
      * const (simple_module_generation functions_set 
               basiclo_function complete_module)
   **/
  assert (isnode_BM ((const value_tyBM) _.constnodv)
          && valhash_BM ((const value_tyBM) _.constnodv) == 4245083367);
  _.simple_module_generation =
    objectcast_BM (nodenthson_BM
                   ((void *) _.constnodv, constix_simple_module_generation));
  assert (_.simple_module_generation != NULL);
  assert (objecthash_BM (_.simple_module_generation)    //
          == 512189275          /* simple_module_generation |=_2HlKptD03wA_7JJCG7lN5nS| */
    );
  if (!objectisinstance_BM (_.modgen, _.simple_module_generation))
    return NULL;
  _.functions_set =
    objectcast_BM (nodenthson_BM
                   ((void *) _.constnodv, constix_functions_set));
  assert (_.functions_set != NULL);
  assert (objecthash_BM (_.functions_set)       //
          == 721902257 /* functions_set |=_9stpgEfdDDE_7LUgqylTeFI| */ );
  _.basiclo_function =
    objectcast_BM (nodenthson_BM
                   ((void *) _.constnodv, constix_basiclo_function));
  assert (_.basiclo_function != NULL);
  assert (objecthash_BM (_.basiclo_function)    //
          == 382575019 /* basiclo_function |=_2Ir1i8qnrA4_3jSkierlc5z| */ );
  _.hset = hashsetobj_grow_BM (NULL, objnbcomps_BM (_.recv) + 1);
  for (unsigned ix = 0; ix < objnbcomps_BM (_.recv); ix++)
    {
      _.curcomp = objgetcomp_BM (_.recv, ix);
      if (isobject_BM (_.curcomp))
        {
          if (objectisinstance_BM (_.curcomp, _.basiclo_function))
            hashsetobj_add_BM (_.hset, _.curcomp);
          else
            return NULL;
        }
      else if (issequence_BM (_.curcomp))
        {
          _.curseq = (seqobval_tyBM *) _.curcomp;
          unsigned sqlen = sequencesize_BM (_.curseq);
          for (unsigned j = 0; j < sqlen; j++)
            {
              _.curcomp = sequencenthcomp_BM (_.curseq, j);
              if (objectisinstance_BM (_.curcomp, _.basiclo_function))
                hashsetobj_add_BM (_.hset, _.curcomp);
              else
                return NULL;
            }
        }
      else if (isclosure_BM (_.curcomp))
        {
          _.partres = apply2_BM ((closure_tyBM *) _.curcomp,
                                 (struct stackframe_stBM *) &_,
                                 _.recv, _.modgen);
          if (isobject_BM (_.partres)
              && objectisinstance_BM (_.partres, _.basiclo_function))
            hashsetobj_add_BM (_.hset, _.partres);
          else if (issequence_BM (_.partres))
            {
              _.curseq = (seqobval_tyBM *) _.partres;
              unsigned sqlen = sequencesize_BM (_.curseq);
              for (unsigned j = 0; j < sqlen; j++)
                {
                  _.curcomp = sequencenthcomp_BM (_.curseq, j);
                  if (objectisinstance_BM (_.curcomp, _.basiclo_function))
                    hashsetobj_add_BM (_.hset, _.curcomp);
                  else
                    return NULL;
                }
            }
          else
            return NULL;
        }
      else
        return NULL;
    }
  if (hashsetobj_cardinal_BM (_.hset) == 0)
    return NULL;
  _.setfun = (setval_tyBM *) hashsetobj_to_set_BM (_.hset);
  objputattr_BM (_.modgen, _.functions_set, _.setfun);
  _.partres = send1_BM (_.recv, _.complete_module,
                        (struct stackframe_stBM *) &_, _.modgen);
  if (isset_BM (_.partres))
    _.setfun = _.partres;
  return _.setfun;
}                               /* end ROUTINE _8zNBXSMY2Ts_1VI5dmY4umA prepare_module°basiclo*module */





// for the method to put_data_value in basiclo_function

extern objrout_sigBM ROUTINEOBJNAME_BM (_60NdV04Lel2_5FSZVWKbSL7);
value_tyBM
ROUTINEOBJNAME_BM (_60NdV04Lel2_5FSZVWKbSL7)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // recieving function
 const value_tyBM arg2,         // new value
 const value_tyBM arg3 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv;
                 const closure_tyBM * clos;     //
                 value_tyBM nval;
    );
  _.clos = clos;
  _.recv = arg1;
  _.nval = arg2;
  assert (isobject_BM (_.recv));
  assert (!objectisinstance_BM (_.recv, BMP_class));
  _.recv->ob_data = _.nval;
  objtouchnow_BM (_.recv);
  return _.recv;
}                               /* end ROUTINEOBJNAME_BM _60NdV04Lel2_5FSZVWKbSL7 */


// for the method to generate_module in basiclo_temporary_module &
// basiclo_dumpable_module

extern objrout_sigBM ROUTINEOBJNAME_BM (_50d65bJypCN_6IJeVtssx9I);
value_tyBM
ROUTINEOBJNAME_BM (_50d65bJypCN_6IJeVtssx9I)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // recieving module
 const value_tyBM arg2,         // module generator
 const value_tyBM arg3,         // preparation
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  enum constix_en
  {
    constix_prepare_routine,
    constix_prepared_routines,
    constix__LAST
  };

  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv;
                 objectval_tyBM * curout;
                 objectval_tyBM * modgen;
                 value_tyBM prepval;
                 value_tyBM preproutval;
                 const closure_tyBM * clos;
                 objectval_tyBM * closconn;
                 const node_tyBM * constnodv;
                 struct datavectval_stBM *vectprepr;
                 value_tyBM prepmod;
    );
  _.recv = arg1;
  _.clos = clos;
  objectval_tyBM *k_prepare_routine = NULL;
  objectval_tyBM *k_prepared_routines = NULL;
  assert (isobject_BM (_.recv));
  DBGPRINTF_BM
    ("@@generate_module°basiclo*module _50d65bJypCN_6IJeVtssx9I recv=%s\n"
     "... is a %s\n",
     objectdbg_BM (_.recv), objectdbg1_BM (objclass_BM (_.recv)));
  _.closconn = closureconn_BM ((const value_tyBM) clos);
  assert (isobject_BM (_.closconn));
  _.constnodv = _.closconn->ob_data;
  /** _.constnodv should be 
       * const (prepare_routine prepared_routines)
   **/
  assert (valhash_BM ((const value_tyBM) _.constnodv) == 903353174);
  k_prepare_routine =
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) _.constnodv, constix_prepare_routine));
  assert (objecthash_BM (k_prepare_routine) == 201958426
          /*prepare_routine |=_6qi1DW0Ygkl_4Aqdxq4n5IV| */ );
  k_prepared_routines =
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) _.constnodv,
                    constix_prepared_routines));
  assert (objecthash_BM (k_prepared_routines) == 815009282
          /*prepared_routines |=_9qn0Hp8HaF5_7yeAJiNYtp5| */ );
  _.modgen = arg2;
  _.prepval = arg3;
  if (!isobject_BM (_.modgen))
    {
      DBGPRINTF_BM ("@@generate_module°basiclo*module bad modgen");
      return NULL;
    };
  DBGPRINTF_BM ("@@generate_module°basiclo*module modgen=%s is a %s\n",
                objectdbg_BM (_.modgen),
                objectdbg1_BM (objclass_BM (_.modgen)));
  if (!isset_BM (_.prepval))
    {
      DBGPRINTF_BM ("@@generate_module°basiclo*module bad prepval");
      return NULL;
    }
  unsigned nbrout = setcardinal_BM ((const setval_tyBM *) _.prepval);
  DBGPRINTF_BM ("@@generate_module°basiclo*module nbrout=%u", nbrout);
  _.vectprepr = datavect_grow_BM (NULL, nbrout);
  for (unsigned ix = 0; ix < nbrout; ix++)
    {
      _.curout = setelemnth_BM ((const setval_tyBM *) _.prepval, ix);
      DBGPRINTF_BM ("@@generate_module°basiclo*module ix#%d\n"
                    "... curout %s is a %s\n",
                    ix, objectdbg_BM (_.curout),
                    objectdbg1_BM (objclass_BM (_.curout)));
      _.preproutval = send2_BM (_.curout, k_prepare_routine,
                                (struct stackframe_stBM *) &_, _.modgen,
                                _.prepval);
      if (!_.preproutval)
        {
          DBGPRINTF_BM
            ("@@generate_module°basiclo*module prepare_routine of %s failed",
             objectdbg_BM (_.curout));
          return NULL;
        }
      _.vectprepr = datavect_append_BM (_.vectprepr, _.preproutval);
    }
  _.prepmod =
    (const value_tyBM) datavect_to_node_BM (_.vectprepr, k_prepared_routines);
  objputattr_BM (_.modgen, k_prepared_routines, _.prepmod);
  objtouchnow_BM (_.modgen);
  // we should now emit each routine...
#warning generate_module°basiclo*module incomplete
  return NULL;
}                               /* end ROUTINE _50d65bJypCN_6IJeVtssx9I */





// for the const function (returning first closed value)

extern objrout_sigBM ROUTINEOBJNAME_BM (_5DDSY1YgVZr_6dOU4tiBldk);
value_tyBM
ROUTINEOBJNAME_BM (_5DDSY1YgVZr_6dOU4tiBldk)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1 __attribute__ ((unused)),
 const value_tyBM arg2 __attribute__ ((unused)),
 const value_tyBM arg3 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos;
    );
  _.clos = clos;
  assert (isclosure_BM ((const value_tyBM) clos));
  return closurenthson_BM ((const value_tyBM) clos, 0);
}                               /* end ROUTINE _5DDSY1YgVZr_6dOU4tiBldk const */


// for the routine to dump_data a plain_dumpable_module
extern objrout_sigBM ROUTINEOBJNAME_BM (_5DyG7xVcxRI_1Ckpbj7b3QK);

value_tyBM
ROUTINEOBJNAME_BM (_5DyG7xVcxRI_1Ckpbj7b3QK)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // recieving module
 const value_tyBM arg2,         // dumper
 const value_tyBM arg3,         // dump strbuf
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos; objectval_tyBM * obmod;
                 struct dumper_stBM *dumper; struct strbuffer_stBM *sbuf;
                 value_tyBM res;
    );
  _.clos = clos;
  assert (isobject_BM (arg1));
  _.obmod = arg1;
  assert (valtype_BM (arg2) == tydata_dumper_BM);
  _.dumper = arg2;
  assert (valtype_BM (arg3) == tydata_strbuffer_BM);
  _.sbuf = arg3;
  DBGPRINTF_BM ("@@dump_data°plain_dumpable_module obmod=%s",
                objectdbg_BM (_.obmod));
  _.res = send0_BM (_.obmod, BMP_emit_module, (struct stackframe_stBM *) &_);
  if (_.res)
    {
      char idbuf[32];
      memset (idbuf, 0, sizeof (idbuf));
      idtocbuf32_BM (objid_BM (_.obmod), idbuf);
      strbufferprintf_BM (_.sbuf, "\t// emitted module %s\n", idbuf);
      DBGPRINTF_BM ("@@dump_data°plain_dumpable_module emitted obmod=%s",
                    objectdbg_BM (_.obmod));
    }
  return _.res;

}                               /* end ROUTINE _5DyG7xVcxRI_1Ckpbj7b3QK */





/******************* command readmacros ***************/

// for the routine command_readmacro for block
extern objrout_sigBM ROUTINEOBJNAME_BM (_0kUyX0U19K2_5mcH4RCaBl9);

value_tyBM
ROUTINEOBJNAME_BM (_0kUyX0U19K2_5mcH4RCaBl9)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const quasinode_tyBM * restargs)
{
  enum constix_en
  {
    constix_basiclo_block,
    constix_label,
    constix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos;
                 const node_tyBM * rnodv; objectval_tyBM * resobj;
                 objectval_tyBM * resclass; objectval_tyBM * curlab;
                 const struct parser_stBM *pars; value_tyBM curson;
                 value_tyBM inv;
    );
  objectval_tyBM *k_basiclo_block = NULL;
  objectval_tyBM *k_label = NULL;
  objectval_tyBM *closconn = NULL;
  const node_tyBM *constnodv = NULL;
  _.clos = clos;
  closconn = closureconn_BM ((const value_tyBM) clos);
  assert (isobject_BM (closconn));
  constnodv = closconn->ob_data;
  if (!isnode_BM (arg1))
    return NULL;
  _.rnodv = arg1;
  /** constnodv is 
     * const (basiclo_block label)
  **/
  assert (isnode_BM ((const value_tyBM) constnodv)
          && valhash_BM ((const value_tyBM) constnodv) == 1875819651
          && nodewidth_BM ((const value_tyBM) constnodv) >= constix__LAST);
  k_basiclo_block =
    objectcast_BM (nodenthson_BM ((void *) constnodv, constix_basiclo_block));
  assert (k_basiclo_block != NULL);
  k_label = objectcast_BM (nodenthson_BM ((void *) constnodv, constix_label));
  assert (k_label != NULL);
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  unsigned startix = 0;
  _.pars = parsercast_BM (treenthson_BM ((value_tyBM) restargs, 0));
  unsigned nodwidth = nodewidth_BM ((value_tyBM) _.rnodv);
  _.resobj = NULL;
  DBGPRINTF_BM ("start readmacro:block _0kUyX0U19K2_5mcH4RCaBl9"
                " lineno=%d colpos=%d nodwidth=%u", lineno, colpos, nodwidth);
  if (nodwidth > 0
      && (_.curson =
          nodenthson_BM ((const value_tyBM) _.rnodv, startix)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object `in` for block readmacro");
          return NULL;
        }
      _.resobj = _.inv;
      if (objectisinstance_BM (_.resobj, k_basiclo_block))
        {
          _.resclass = objclass_BM (_.resobj);
        };
      startix++;
    }
  if (nodwidth > startix
      && (_.curson =
          nodenthson_BM ((const value_tyBM) _.rnodv, startix)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == k_label)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.curlab))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object `label` for block readmacro");
          return NULL;
        }
      _.curlab = _.inv;
      startix++;
    };
  if (!_.resclass)
    _.resclass = k_basiclo_block;
  if (!_.resobj)
    {
      _.resobj = makeobj_BM ();
      objputspacenum_BM (_.resobj, GlobalSp_BM);
    };
  for (unsigned ix = startix; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      if (!isobject_BM (_.curson))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object #%d comp for block readmacro",
                                  ix);
          return NULL;
        }
    }
  objresetcomps_BM (_.resobj, nodwidth - startix);
  objresetattrs_BM (_.resobj, 5);
  objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  if (_.curlab)
    objputattr_BM (_.resobj, k_label, (const value_tyBM) _.curlab);
  for (unsigned ix = startix; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      objappendcomp_BM (_.resobj, _.curson);
    }
  objputclass_BM (_.resobj, _.resclass);
  objtouchnow_BM (_.resobj);
  return _.resobj;
}                               /* end ROUTINE _0kUyX0U19K2_5mcH4RCaBl9 block:readmacro */


////////////////

// for the routine command_readmacro for assign
extern objrout_sigBM ROUTINEOBJNAME_BM (_1Geqz0vsOKB_2Dpdb1LDu23);

value_tyBM
ROUTINEOBJNAME_BM (_1Geqz0vsOKB_2Dpdb1LDu23)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const quasinode_tyBM * restargs)
{
  enum constix_en
  {
    constix_basiclo_assign,
    constix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos; const node_tyBM * rnodv;
                 objectval_tyBM * resobj; const struct parser_stBM *pars;
                 value_tyBM inv; value_tyBM destv;
                 value_tyBM srcv;
                 value_tyBM curson;
    );
  _.clos = clos;
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    return NULL;
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  unsigned nodwidth = nodewidth_BM ((value_tyBM) _.rnodv);
  _.pars = parsercast_BM (treenthson_BM ((const value_tyBM) restargs, 0));

  _.clos = clos;
  const objectval_tyBM *closconn = closureconn_BM ((const value_tyBM) clos);
  assert (isobject_BM ((const value_tyBM) closconn));
  const value_tyBM constnodv = closconn->ob_data;
  if (!isnode_BM (arg1))
    return NULL;
  _.rnodv = arg1;
  /** constnodv is 
     * const (basiclo_assign)
  **/
  WEAKASSERT_BM (isnode_BM ((const value_tyBM) constnodv)
                 && valhash_BM ((const value_tyBM) constnodv) == 849423390
                 && nodewidth_BM ((const value_tyBM) constnodv) >=
                 constix__LAST);
  const objectval_tyBM *k_basiclo_assign =
    objectcast_BM (nodenthson_BM
                   ((void *) constnodv, constix_basiclo_assign));
  assert (k_basiclo_assign != NULL);
  unsigned startix = 0;
  _.resobj = NULL;
  DBGPRINTF_BM ("start readmacro:assign _1Geqz0vsOKB_2Dpdb1LDu23"
                " lineno=%d colpos=%d nodwidth=%u", lineno, colpos, nodwidth);
  if (nodwidth > 0
      && (_.curson = nodenthson_BM ((const value_tyBM) _.rnodv, 0)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object `in` for assign readmacro");
          return NULL;
        }
      _.resobj = _.inv;
      startix = 1;
    }
  else
    {
      startix = 0;
      _.resobj = makeobj_BM ();
      objputspacenum_BM (_.resobj, GlobalSp_BM);
    };
  if (nodwidth != startix + 2)
    {
      if (_.pars)
        parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                              colpos, "assign readmacro wants two arguments");
      return NULL;
    }
  _.destv = nodenthson_BM ((const value_tyBM) _.rnodv, startix);
  _.srcv = nodenthson_BM ((const value_tyBM) _.rnodv, startix + 1);
  if (!isobject_BM (_.destv))
    {
      if (_.pars)
        parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                              colpos, "assign readmacro wants object as src");
      return NULL;
    }
  objresetcomps_BM (_.resobj, 2);
  objresetattrs_BM (_.resobj, 5);
  objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  objappendcomp_BM (_.resobj, _.destv);
  objappendcomp_BM (_.resobj, _.srcv);
  objputclass_BM (_.resobj, (objectval_tyBM *) k_basiclo_assign);
  objtouchnow_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:assign resobj %s", objectdbg_BM (_.resobj));
  return _.resobj;
}                               /* end ROUTINE _1Geqz0vsOKB_2Dpdb1LDu23 assign:readmacro */

////////////////

// for the routine command_readmacro for cond
extern objrout_sigBM ROUTINEOBJNAME_BM (_0XbMOJqLLPZ_1t2wg2TwPRA);

value_tyBM
ROUTINEOBJNAME_BM (_0XbMOJqLLPZ_1t2wg2TwPRA)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  enum constix_en
  {
    constix_basiclo_cond,
    constix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos;
                 const node_tyBM * rnodv;
                 const node_tyBM * constnodv;
                 objectval_tyBM * resobj;
                 objectval_tyBM * closconn;
                 objectval_tyBM * basiclo_cond;
                 const struct parser_stBM *pars;
                 value_tyBM inv; value_tyBM destv;
                 value_tyBM srcv;
                 value_tyBM curson;
    );
  _.clos = clos;
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    return NULL;
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  _.pars = parsercast_BM (treenthson_BM ((const value_tyBM) restargs, 0));

  _.clos = clos;
  _.closconn = closureconn_BM ((const value_tyBM) clos);
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  DBGPRINTF_BM ("start readmacro:cond _0XbMOJqLLPZ_1t2wg2TwPRA"
                " lineno=%d colpos=%d nodwidth=%u", lineno, colpos, nodwidth);
  assert (isobject_BM (_.closconn));
  _.constnodv = _.closconn->ob_data;
  if (!isnode_BM (arg1))
    return NULL;
  _.rnodv = arg1;
  _.constnodv = _.closconn->ob_data;
  /** constnodv is 
     * const (basiclo_cond)
  **/
  assert (isnode_BM ((const value_tyBM) _.constnodv)
          && valhash_BM ((const value_tyBM) _.constnodv) == 1270778085);
  assert (nodewidth_BM ((const value_tyBM) _.constnodv) >= constix__LAST);
  _.basiclo_cond =
    objectcast_BM (nodenthson_BM
                   ((void *) _.constnodv, constix_basiclo_cond));
  assert (_.basiclo_cond != NULL);
  unsigned startix = 0;
  _.resobj = NULL;
  if (nodwidth > 0
      && (_.curson = nodenthson_BM ((const value_tyBM) _.rnodv, 0)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object `in` for cond readmacro");
          return NULL;
        }
      _.resobj = _.inv;
      startix = 1;
    }
  else
    {
      startix = 0;
      _.resobj = makeobj_BM ();
      objputspacenum_BM (_.resobj, GlobalSp_BM);
    };
  for (unsigned ix = startix; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      if (!isobject_BM (_.curson))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object arg#%d for cond readmacro", ix);
          return NULL;
        }
    }
  objresetcomps_BM (_.resobj, nodwidth - startix);
  objresetattrs_BM (_.resobj, 5);
  objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  for (unsigned ix = startix; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      objappendcomp_BM (_.resobj, _.curson);
    }
  objputclass_BM (_.resobj, _.basiclo_cond);
  objtouchnow_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:cond resobj %s", objectdbg_BM (_.resobj));
  return _.resobj;
}                               /* end ROUTINE _0XbMOJqLLPZ_1t2wg2TwPRA cond:readmacro */




////////////////

// for the routine command_readmacro for intswitch
extern objrout_sigBM ROUTINEOBJNAME_BM (_7ko2VZaPpqD_1eEmEcp0VV3);

value_tyBM
ROUTINEOBJNAME_BM (_7ko2VZaPpqD_1eEmEcp0VV3)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const quasinode_tyBM * restargs)
{
  enum constix_en
  {
    constix_basiclo_intswitch,
    constix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos;
                 const node_tyBM * rnodv;
                 const struct parser_stBM *pars;
                 const node_tyBM * constnodv;
                 objectval_tyBM * resobj;
                 objectval_tyBM * closconn;
                 objectval_tyBM * basiclo_intswitch; value_tyBM curson;
                 value_tyBM inv;
    );
  _.clos = clos;
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    return NULL;
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  _.closconn = closureconn_BM ((const value_tyBM) clos);
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  _.pars = parsercast_BM (treenthson_BM ((const value_tyBM) restargs, 0));
  _.resobj = NULL;
  _.constnodv = _.closconn->ob_data;
  /** constnodv is 
     * const (basiclo_intswitch)
  **/
  assert (isnode_BM ((const value_tyBM) _.constnodv)
          && valhash_BM ((const value_tyBM) _.constnodv) == 760996907);
  assert (nodewidth_BM ((const value_tyBM) _.constnodv) >= constix__LAST);
  _.basiclo_intswitch =
    objectcast_BM (nodenthson_BM
                   ((void *) _.constnodv, constix_basiclo_intswitch));
  assert (_.basiclo_intswitch != NULL);
  DBGPRINTF_BM ("start readmacro:intswitch  _7ko2VZaPpqD_1eEmEcp0VV3"
                " lineno=%d colpos=%d nodwidth=%u", lineno, colpos, nodwidth);
  unsigned startix = 0;
  _.resobj = NULL;
  if (nodwidth > 0
      && (_.curson = nodenthson_BM ((const value_tyBM) _.rnodv, 0)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object `in` for intswitch readmacro");
          return NULL;
        }
      _.resobj = _.inv;
      startix = 1;
    }
  else
    {
      startix = 0;
      _.resobj = makeobj_BM ();
      objputspacenum_BM (_.resobj, GlobalSp_BM);
    };
  for (unsigned ix = startix; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      if (!isobject_BM (_.curson))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object arg#%d for cond readmacro", ix);
          return NULL;
        }
    }
  objresetcomps_BM (_.resobj, nodwidth - startix);
  objresetattrs_BM (_.resobj, 5);
  objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  for (unsigned ix = startix; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      objappendcomp_BM (_.resobj, _.curson);
    }
  objputclass_BM (_.resobj, _.basiclo_intswitch);
  objtouchnow_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:intswitch resobj %s", objectdbg_BM (_.resobj));
  return _.resobj;
}                               /* end ROUTINE  _7ko2VZaPpqD_1eEmEcp0VV3 intswitch:readmacro */



/////

// for the routine command_readmacro for objswitch
extern objrout_sigBM ROUTINEOBJNAME_BM (_8uFPIAUyvE6_36pUIgGwmbf);

value_tyBM
ROUTINEOBJNAME_BM (_8uFPIAUyvE6_36pUIgGwmbf)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  enum constix_en
  {
    constix_basiclo_objswitch,
    constix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos;
                 const node_tyBM * rnodv;
                 const struct parser_stBM *pars;
                 const node_tyBM * constnodv;
                 objectval_tyBM * resobj;
                 objectval_tyBM * closconn;
                 objectval_tyBM * basiclo_objswitch; value_tyBM curson;
                 value_tyBM inv;
    );
  _.clos = clos;
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    return NULL;
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  _.closconn = closureconn_BM ((const value_tyBM) clos);
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  _.pars = parsercast_BM (treenthson_BM ((const value_tyBM) restargs, 0));
  _.resobj = NULL;
  _.constnodv = _.closconn->ob_data;
  /** constnodv is 
     * const (basiclo_objswitch)
  **/
  assert (isnode_BM ((const value_tyBM) _.constnodv)
          && valhash_BM ((const value_tyBM) _.constnodv) == 3352429248);
  assert (nodewidth_BM ((const value_tyBM) _.constnodv) >= constix__LAST);
  _.basiclo_objswitch =
    objectcast_BM (nodenthson_BM
                   ((void *) _.constnodv, constix_basiclo_objswitch));
  assert (_.basiclo_objswitch != NULL);
  DBGPRINTF_BM ("start readmacro:objswitch _8uFPIAUyvE6_36pUIgGwmbf"
                " lineno=%d colpos=%d nodwidth=%u", lineno, colpos, nodwidth);
  unsigned startix = 0;
  _.resobj = NULL;
  if (nodwidth > 0
      && (_.curson = nodenthson_BM ((const value_tyBM) _.rnodv, 0)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object `in` for objswitch readmacro");
          return NULL;
        }
      _.resobj = _.inv;
      startix = 1;
    }
  else
    {
      startix = 0;
      _.resobj = makeobj_BM ();
      objputspacenum_BM (_.resobj, GlobalSp_BM);
    };
  for (unsigned ix = startix; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      if (!isobject_BM (_.curson))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object arg#%d for cond readmacro", ix);
          return NULL;
        }
    }
  objresetcomps_BM (_.resobj, nodwidth - startix);
  objresetattrs_BM (_.resobj, 5);
  objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  for (unsigned ix = startix; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      objappendcomp_BM (_.resobj, _.curson);
    }
  objputclass_BM (_.resobj, _.basiclo_objswitch);
  objtouchnow_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:objswitch resobj %s", objectdbg_BM (_.resobj));
  return _.resobj;
}                               /* end ROUTINE  _8uFPIAUyvE6_36pUIgGwmbf objswitch:readmacro */


/////

// for the routine command_readmacro for loop
extern objrout_sigBM ROUTINEOBJNAME_BM (_6SUnsQrN1BV_1WnLPm4QoOq);

value_tyBM
ROUTINEOBJNAME_BM (_6SUnsQrN1BV_1WnLPm4QoOq)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  enum constix_en
  {
    constix_basiclo_loop,
    constix_label,
    constix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos;
                 const node_tyBM * rnodv; value_tyBM curson;
                 objectval_tyBM * resobj; objectval_tyBM * resclass;
                 objectval_tyBM * curlab; objectval_tyBM * inv;
                 struct parser_stBM *pars;
    );
  _.clos = clos;
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    return NULL;
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  const objectval_tyBM *closconn = closureconn_BM ((const value_tyBM) clos);
  assert (closconn != NULL);
  const node_tyBM *constnod = nodecast_BM (closconn->ob_data);
  /*** constnod is
   * const (basiclo_loop label)
   ***/
  assert (isnode_BM ((const value_tyBM) constnod)
          && nodewidth_BM ((const value_tyBM) constnod) >= constix__LAST
          && valhash_BM ((const value_tyBM) constnod) == 1553076617);
  const objectval_tyBM *k_basiclo_loop =
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_basiclo_loop));
  const objectval_tyBM *k_label =
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_label));
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  DBGPRINTF_BM ("start readmacro:loop  _6SUnsQrN1BV_1WnLPm4QoOq"
                " lineno=%d colpos=%d nodwidth=%u", lineno, colpos, nodwidth);
  _.resobj = NULL;
  unsigned startix = 0;
  if (nodwidth > 0
      && (_.curson =
          nodenthson_BM ((const value_tyBM) _.rnodv, startix)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object `in` for loop readmacro");
          return NULL;
        }
      _.resobj = _.inv;
      if (objectisinstance_BM (_.resobj, k_basiclo_loop))
        _.resclass = objclass_BM (_.resobj);
      startix++;
    }
  if (nodwidth > startix
      && (_.curson =
          nodenthson_BM ((const value_tyBM) _.rnodv, startix)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == k_label)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object `label` for loop readmacro");
          return NULL;
        }
      _.curlab = _.inv;
      startix++;
    };
  if (!_.resclass)
    _.resclass = (objectval_tyBM *) k_basiclo_loop;
  if (!_.resobj)
    {
      _.resobj = makeobj_BM ();
      objputspacenum_BM (_.resobj, GlobalSp_BM);
    };
  for (unsigned ix = startix; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      if (!isobject_BM (_.curson))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object #%d comp for loop readmacro",
                                  ix);
          return NULL;
        }
    }
  objresetcomps_BM (_.resobj, nodwidth - startix);
  objresetattrs_BM (_.resobj, 5);
  objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  if (_.curlab)
    objputattr_BM (_.resobj, k_label, (const value_tyBM) _.curlab);
  for (unsigned ix = startix; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      objappendcomp_BM (_.resobj, _.curson);
    }
  objputclass_BM (_.resobj, _.resclass);
  objtouchnow_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:loop resobj %s", objectdbg_BM (_.resobj));
  return _.resobj;
}                               /* end ROUTINE  _6SUnsQrN1BV_1WnLPm4QoOq loop:readmacro */




/////

// for the routine command_readmacro for exit
extern objrout_sigBM ROUTINEOBJNAME_BM (_63Q0R4r8xa7_7XOAxxP5pi2);

value_tyBM
ROUTINEOBJNAME_BM (_63Q0R4r8xa7_7XOAxxP5pi2)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  enum
  {
    constix_basiclo_exit, constix_exit,
    constix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos; const node_tyBM * rnodv;
                 objectval_tyBM * resobj; objectval_tyBM * resclass;
                 value_tyBM exitv; value_tyBM curson; value_tyBM inv;
                 const struct parser_stBM *pars;
    );
  _.pars = parsercast_BM (treenthson_BM ((const value_tyBM) restargs, 0));
  const objectval_tyBM *closconn = closureconn_BM ((const value_tyBM) clos);
  assert (closconn != NULL);
  const node_tyBM *constnod = nodecast_BM (closconn->ob_data);
  /*** constnod is
   * const (basiclo_exit exit)
   ***/
  assert (isnode_BM ((const value_tyBM) constnod)
          && nodewidth_BM ((const value_tyBM) constnod) >= constix__LAST
          && valhash_BM ((const value_tyBM) constnod) == 756562056);
  const objectval_tyBM *k_basiclo_exit =
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_basiclo_exit));
  const objectval_tyBM *k_exit =
    objectcast_BM (nodenthson_BM ((const value_tyBM) constnod, constix_exit));
  _.clos = clos;
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    return NULL;
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  _.resobj = NULL;
  DBGPRINTF_BM ("start readmacro:exit  _63Q0R4r8xa7_7XOAxxP5pi2"
                " lineno=%d colpos=%d nodwidth=%u", lineno, colpos, nodwidth);
  unsigned startix = 0;
  if (nodwidth > 0
      && (_.curson =
          nodenthson_BM ((const value_tyBM) _.rnodv, startix)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object `in` for exit readmacro");
          return NULL;
        }
      _.resobj = _.inv;
      if (objectisinstance_BM (_.resobj, k_basiclo_exit))
        _.resclass = objclass_BM (_.resobj);
      startix++;
    }
  if (nodwidth > startix + 1)
    _.exitv = nodenthson_BM ((const value_tyBM) _.rnodv, startix);
  if (!isobject_BM (_.exitv))
    {
      if (_.pars)
        parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                              colpos,
                              "non-object exit argument for exit readmacro");
      return NULL;
    }
  objresetcomps_BM (_.resobj, 2);
  objresetattrs_BM (_.resobj, 5);
  objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  if (_.exitv)
    objputattr_BM (_.resobj, k_exit, (const value_tyBM) _.exitv);
  if (!_.resclass)
    _.resclass = (objectval_tyBM *) k_basiclo_exit;
  objputclass_BM (_.resobj, _.resclass);
  objtouchnow_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:exit resobj %s", objectdbg_BM (_.resobj));
  return _.resobj;
}                               /* end ROUTINE  _63Q0R4r8xa7_7XOAxxP5pi2 exit:readmacro */


/////

// for the routine command_readmacro for while
extern objrout_sigBM ROUTINEOBJNAME_BM (_1ufPZmTnWhp_7FX9NANZCAW);

value_tyBM
ROUTINEOBJNAME_BM (_1ufPZmTnWhp_7FX9NANZCAW)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  enum
  {
    constix_basiclo_while, constix_while, constix_label,
    constix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos; const node_tyBM * rnodv;
                 objectval_tyBM * resobj; objectval_tyBM * resclass;
                 objectval_tyBM * inv; objectval_tyBM * curlab;
                 value_tyBM curson; value_tyBM whilexpv;
                 const struct parser_stBM *pars;
    );
  _.clos = clos;
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    return NULL;
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  _.resobj = NULL;
  _.pars = parsercast_BM (treenthson_BM ((const value_tyBM) restargs, 0));
  const objectval_tyBM *closconn = closureconn_BM ((const value_tyBM) clos);
  assert (closconn != NULL);
  const node_tyBM *constnod = nodecast_BM (closconn->ob_data);
  /*** constnod is
   * const (basiclo_while while label)
   ***/
  assert (isnode_BM ((const value_tyBM) constnod)
          && nodewidth_BM ((const value_tyBM) constnod) >= constix__LAST
          && valhash_BM ((const value_tyBM) constnod) == 1165552647);
  const objectval_tyBM *k_basiclo_while =
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_basiclo_while));
  const objectval_tyBM *k_while =
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_while));
  const objectval_tyBM *k_label =
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_label));
  DBGPRINTF_BM ("start readmacro:while  _1ufPZmTnWhp_7FX9NANZCAW"
                " lineno=%d colpos=%d nodwidth=%u", lineno, colpos, nodwidth);
  unsigned startix = 0;
  if (nodwidth > 0
      && (_.curson =
          nodenthson_BM ((const value_tyBM) _.rnodv, startix)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object `in` for while readmacro");
          return NULL;
        }
      _.resobj = _.inv;
      if (objectisinstance_BM (_.resobj, k_basiclo_while))
        _.resclass = objclass_BM (_.resobj);
      startix++;
    }
  if (nodwidth > startix
      && (_.curson =
          nodenthson_BM ((const value_tyBM) _.rnodv, startix)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == k_label)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object `label` for while readmacro");
          return NULL;
        }
      _.curlab = _.inv;
      startix++;
    };
  if (!_.resclass)
    _.resclass = (objectval_tyBM *) k_basiclo_while;
  if (!_.resobj)
    {
      _.resobj = makeobj_BM ();
      objputspacenum_BM (_.resobj, GlobalSp_BM);
    };
  if (startix + 1 < nodwidth)
    {
      if (_.pars)
        parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                              colpos,
                              "too short %d while readmacro", nodwidth);
      return NULL;
    }
  _.whilexpv = nodenthson_BM ((const value_tyBM) _.rnodv, startix);
  if (!_.whilexpv)
    {
      if (_.pars)
        parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                              colpos, "nil cond in while readmacro");
    }
  for (unsigned ix = startix + 1; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      if (!isobject_BM (_.curson))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object #%d comp for while readmacro",
                                  ix);
          return NULL;
        }
    }
  objresetcomps_BM (_.resobj, nodwidth - startix);
  objresetattrs_BM (_.resobj, 5);
  objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  if (_.curlab)
    objputattr_BM (_.resobj, k_label, (const value_tyBM) _.curlab);
  objputattr_BM (_.resobj, k_while, (const value_tyBM) _.whilexpv);
  for (unsigned ix = startix + 1; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      objappendcomp_BM (_.resobj, _.curson);
    }
  objputclass_BM (_.resobj, _.resclass);
  objtouchnow_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:while resobj %s", objectdbg_BM (_.resobj));
  return _.resobj;
}                               /* end ROUTINE  _1ufPZmTnWhp_7FX9NANZCAW while:readmacro */


/////

// for the routine command_readmacro for return
extern objrout_sigBM ROUTINEOBJNAME_BM (_5788HpgOtVV_4zwZIr0jgmq);

value_tyBM
ROUTINEOBJNAME_BM (_5788HpgOtVV_4zwZIr0jgmq)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  enum
  {
    constix_basiclo_return, constix_return,
    constix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos; const node_tyBM * rnodv;
                 objectval_tyBM * resobj; objectval_tyBM * resclass;
                 objectval_tyBM * inv; value_tyBM curson; value_tyBM resexpv;
                 const struct parser_stBM *pars;
    );
  _.clos = clos;
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    return NULL;
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  _.resobj = NULL;
  _.pars = parsercast_BM (treenthson_BM ((const value_tyBM) restargs, 0));
  DBGPRINTF_BM ("start readmacro:return  _5788HpgOtVV_4zwZIr0jgmq"
                " lineno=%d colpos=%d nodwidth=%u", lineno, colpos, nodwidth);

  const objectval_tyBM *closconn = closureconn_BM ((const value_tyBM) clos);
  assert (closconn != NULL);
  const node_tyBM *constnod = nodecast_BM (closconn->ob_data);
  /*** constnod is
   * const (basiclo_return return)
   ***/
  assert (isnode_BM ((const value_tyBM) constnod)
          && nodewidth_BM ((const value_tyBM) constnod) >= constix__LAST
          && valhash_BM ((const value_tyBM) constnod) == 452647067);
  const objectval_tyBM *k_basiclo_return =
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_basiclo_return));
  const objectval_tyBM *k_return =
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_return));
  ///
  unsigned startix = 0;
  if (nodwidth > 0
      && (_.curson =
          nodenthson_BM ((const value_tyBM) _.rnodv, startix)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object `in` for return readmacro");
          return NULL;
        }
      _.resobj = _.inv;
      if (objectisinstance_BM (_.resobj, k_basiclo_return))
        _.resclass = objclass_BM (_.resobj);
      startix++;
    }
  if (startix + 1 > nodwidth)
    {
      if (_.pars)
        parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                              colpos,
                              "too long %u return readmacro", nodwidth);
      return NULL;
    }
  _.resexpv = nodenthson_BM ((const value_tyBM) _.rnodv, startix);
  if (!_.resclass)
    _.resclass = (objectval_tyBM *) k_basiclo_return;
  if (!_.resobj)
    {
      _.resobj = makeobj_BM ();
      objputspacenum_BM (_.resobj, GlobalSp_BM);
    };
  objresetcomps_BM (_.resobj, 1);
  objresetattrs_BM (_.resobj, 5);
  objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  if (_.resexpv)
    objputattr_BM (_.resobj, k_return, (const value_tyBM) _.resexpv);
  objputclass_BM (_.resobj, _.resclass);
  objtouchnow_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:return resobj %s", objectdbg_BM (_.resobj));
  return _.resobj;
}                               /* end ROUTINE   _5788HpgOtVV_4zwZIr0jgmq return:readmacro */




/////

// for the routine command_readmacro for run
extern objrout_sigBM ROUTINEOBJNAME_BM (_7sg0DjYTA8n_66vhff9SgXH);

value_tyBM
ROUTINEOBJNAME_BM (_7sg0DjYTA8n_66vhff9SgXH)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  enum
  {
    constix_basiclo_run, constix_run,
    constix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos; const node_tyBM * rnodv;
                 objectval_tyBM * resobj; objectval_tyBM * resclass;
                 objectval_tyBM * inv; value_tyBM curson; value_tyBM runexpv;
                 const struct parser_stBM *pars;
    );
  _.clos = clos;
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    return NULL;
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  _.resobj = NULL;
  _.pars = parsercast_BM (treenthson_BM ((const value_tyBM) restargs, 0));
  DBGPRINTF_BM ("start readmacro:run  _7sg0DjYTA8n_66vhff9SgXH"
                " lineno=%d colpos=%d nodwidth=%u", lineno, colpos, nodwidth);

  const objectval_tyBM *closconn = closureconn_BM ((const value_tyBM) clos);
  assert (closconn != NULL);
  const node_tyBM *constnod = nodecast_BM (closconn->ob_data);
  /*** constnod is
   * const (basiclo_run run)
   ***/
  WEAKASSERT_BM (isnode_BM ((const value_tyBM) constnod)
                 && nodewidth_BM ((const value_tyBM) constnod) >=
                 constix__LAST
                 && valhash_BM ((const value_tyBM) constnod) == 2311989027);
  const objectval_tyBM *k_basiclo_run =
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_basiclo_run));
  const objectval_tyBM *k_run =
    objectcast_BM (nodenthson_BM ((const value_tyBM) constnod, constix_run));
  ///
  unsigned startix = 0;
  if (nodwidth > 0
      && (_.curson =
          nodenthson_BM ((const value_tyBM) _.rnodv, startix)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object `in` for run readmacro");
          return NULL;
        }
      _.resobj = _.inv;
      if (objectisinstance_BM (_.resobj, k_basiclo_run))
        _.resclass = objclass_BM (_.resobj);
      startix++;
    }
  if (startix + 1 > nodwidth)
    {
      if (_.pars)
        parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                              colpos, "too long %u run readmacro", nodwidth);
      return NULL;
    }
  _.runexpv = nodenthson_BM ((const value_tyBM) _.rnodv, startix);
  if (!_.resclass)
    _.resclass = (objectval_tyBM *) k_basiclo_run;
  if (!_.resobj)
    {
      _.resobj = makeobj_BM ();
      objputspacenum_BM (_.resobj, GlobalSp_BM);
    };
  objresetcomps_BM (_.resobj, 1);
  objresetattrs_BM (_.resobj, 5);
  objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  if (_.runexpv)
    objputattr_BM (_.resobj, k_run, (const value_tyBM) _.runexpv);
  objputclass_BM (_.resobj, _.resclass);
  objtouchnow_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:run resobj %s", objectdbg_BM (_.resobj));
  return _.resobj;
}                               /* end ROUTINE   _7sg0DjYTA8n_66vhff9SgXH run:readmacro */



///
// readmacro routine for cexpansion-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_42gEKfF4qca_6gGwxSFC1FO);

value_tyBM
ROUTINEOBJNAME_BM (_42gEKfF4qca_6gGwxSFC1FO)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  enum
  {
    constix_basiclo_cexpansion,
    constix_basiclo_cexpander,
    constix_results,
    constix_arguments,
    constix_body,
    constix_expander,
    constix__LAST
  };
  enum
  {
    closix_curcexp,
    closix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos;
                 const node_tyBM * rnodv; objectval_tyBM * resobj;
                 objectval_tyBM * resclass; objectval_tyBM * inv;
                 value_tyBM curson;
                 value_tyBM runexpv; value_tyBM argsv; value_tyBM resultsv;
                 value_tyBM tupresultsv; value_tyBM nodargsv;
                 const struct parser_stBM *pars;
    );
  _.clos = clos;
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    return NULL;
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  _.resobj = NULL;
  _.pars = parsercast_BM (treenthson_BM ((const value_tyBM) restargs, 0));
  DBGPRINTF_BM ("start readmacro cexpansion _42gEKfF4qca_6gGwxSFC1FO"
                " lineno=%d colpos=%d nodwidth=%u", lineno, colpos, nodwidth);

  const objectval_tyBM *closconn = closureconn_BM ((const value_tyBM) clos);
  assert (closconn != NULL);
  WEAKASSERT_BM (closurewidth_BM ((const value_tyBM) clos) >= closix__LAST);
  objectval_tyBM *clos_curcexp =        //
    objectcast_BM (closurenthson_BM ((const value_tyBM) clos,
                                     closix_curcexp));
  const node_tyBM *constnod = nodecast_BM (closconn->ob_data);
  /*** constnod is
   * const (basiclo_cexpansion basiclo_cexpander results arguments body expander)
   ***/
  WEAKASSERT_BM (isnode_BM ((const value_tyBM) constnod)
                 && nodewidth_BM ((const value_tyBM) constnod) >=
                 constix__LAST
                 && valhash_BM ((const value_tyBM) constnod) == 2502446012);
  const objectval_tyBM *k_basiclo_cexpansion =
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_basiclo_cexpansion));
  WEAKASSERT_BM (k_basiclo_cexpansion != NULL);
  const objectval_tyBM *k_basiclo_cexpander =
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_basiclo_cexpander));
  WEAKASSERT_BM (k_basiclo_cexpander != NULL);
  const objectval_tyBM *k_results =
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_results));
  WEAKASSERT_BM (k_results != NULL);
  const objectval_tyBM *k_arguments =
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_arguments));
  WEAKASSERT_BM (k_arguments != NULL);
  const objectval_tyBM *k_body =
    objectcast_BM (nodenthson_BM ((const value_tyBM) constnod, constix_body));
  WEAKASSERT_BM (k_body != NULL);
  const objectval_tyBM *k_expander =
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_expander));
  WEAKASSERT_BM (k_expander != NULL);
  if (!isobject_BM (clos_curcexp)
      || !objectisinstance_BM (clos_curcexp, k_basiclo_cexpander))
    {
      if (_.pars)
        parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                              colpos,
                              "bad cexpander for cexpansion readmacro");
      return NULL;
    };
  _.resultsv = objgetattr_BM (clos_curcexp, k_results);
  _.argsv = objgetattr_BM (clos_curcexp, k_arguments);
  int nbresults =               //
    istuple_BM (_.resultsv) ? tuplesize_BM (_.resultsv) :
    isobject_BM (_.resultsv) ? 1 : 0;
  int nbargs =                  //
    istuple_BM (_.argsv) ? tuplesize_BM (_.argsv) :
    isobject_BM (_.argsv) ? 1 : 0;
  DBGPRINTF_BM ("readmacro cexpansion curexp %s nbresults#%d nbargs#%d",
                objectdbg_BM (clos_curcexp), nbresults, nbargs);
  unsigned startix = 0;
  if (nodwidth > 0
      && (_.curson =
          nodenthson_BM ((const value_tyBM) _.rnodv, startix)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object `in` for cexpansion %s readmacro",
                                  objectdbg_BM (clos_curcexp));
          return NULL;
        }
      _.resobj = _.inv;
      if (objectisinstance_BM (_.resobj, k_basiclo_cexpansion))
        _.resclass = objclass_BM (_.resobj);
      startix++;
    }
  DBGPRINTF_BM
    ("%s cexpansion  startix=%d nbresults=%d nbargs=%d nodwidth=%d",
     objectdbg_BM (clos_curcexp), startix, nbresults, nbargs, nodwidth);
  if (startix + nbresults + nbargs <= nodwidth)
    {
      if (_.pars)
        parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                              colpos,
                              "too short %s cexpansion (%u) readmacro (%d results, %d arguments)",
                              objectdbg_BM (clos_curcexp), nodwidth,
                              nbresults, nbargs);
      return NULL;
    }
  if (!_.resclass)
    _.resclass = (objectval_tyBM *) k_basiclo_cexpansion;
  if (nbresults > 0)
    {
      for (int ix = 0; ix < nbresults; ix++)
        {
          _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, startix + ix);
          if (!isobject_BM (_.curson))
            {
              if (_.pars)
                parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                      colpos,
                                      "non-object result#%d for cexpansion %s readmacro",
                                      ix, objectdbg_BM (clos_curcexp));
              return NULL;
            }
        }
    }
  for (int ix = startix + nbresults + nbargs; ix < (int) nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      if (!isobject_BM (_.curson))
        {
          if (_.pars)
            parsererrorprintf_BM ((struct parser_stBM *) _.pars, lineno,
                                  colpos,
                                  "non-object body component#%d for cexpansion %s readmacro",
                                  ix, objectdbg_BM (clos_curcexp));
          return NULL;
        }
    }
  if (!_.resobj)
    {
      _.resobj = makeobj_BM ();
      objputspacenum_BM (_.resobj, GlobalSp_BM);
    };
  objresetcomps_BM (_.resobj, 1 + nodwidth - nbresults + nbargs);
  objresetattrs_BM (_.resobj, 5);
  objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  if (nbresults > 0)
    {
      objectval_tyBM *tinyarr[TINYSIZE_BM] = { };
      objectval_tyBM **arr =
        (nbresults < TINYSIZE_BM) ? tinyarr
        : calloc (nbresults, sizeof (objectval_tyBM *));
      if (!arr)
        FATAL_BM ("failed to allocate array of %d results", nbresults);

      for (int ix = 0; ix < nbresults; ix++)
        {
          _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, startix + ix);
          arr[ix] = objectcast_BM (_.curson);
        };
      _.tupresultsv = (value_tyBM) maketuple_BM (arr, nbresults);
      if (arr != tinyarr)
        free (arr), arr = NULL;
      objputattr_BM (_.resobj, k_results, _.tupresultsv);
    }
  else
    objremoveattr_BM (_.resobj, k_results);
  if (nbargs > 0)
    {
      value_tyBM tinyarrv[TINYSIZE_BM] = { };
      value_tyBM *arrv =
        (nbargs < TINYSIZE_BM) ? tinyarrv
        : calloc (nbargs, sizeof (value_tyBM));
      if (!arrv)
        FATAL_BM ("failed to allocate array of %d arguments", nbargs);
      for (int ix = 0; ix < nbargs; ix++)
        {
          _.curson =
            nodenthson_BM ((const value_tyBM) _.rnodv,
                           startix + nbresults + ix);
          arrv[ix] = _.curson;
        };
      _.nodargsv = (value_tyBM) makenode_BM (k_arguments, nbargs, arrv);
      if (arrv != tinyarrv)
        free (arrv);
      objputattr_BM (_.resobj, k_arguments, _.nodargsv);
    }
  else
    objremoveattr_BM (_.resobj, k_arguments);
  for (int ix = startix + nbresults + nbargs; ix < (int) nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      assert (isobject_BM (_.curson));
      objappendcomp_BM (_.resobj, _.curson);
    }
  objputclass_BM (_.resobj, _.resclass);
  objtouchnow_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro cexpansion resobj %s",
                objectdbg_BM (_.resobj));
  return _.resobj;
}                               /* end routine readmacro cexpansion _42gEKfF4qca_6gGwxSFC1FO */
