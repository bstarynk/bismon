// file code_BM.c
// SPDX-License-Identifier: GPL-3.0-or-later

/***
    BISMON 
    Copyright © 2018 - 2022 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch (working at CEA, LIST, France)
    <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
***/

#include "bismon.h"
#include "code_BM.const.h"

//// for the method to dump_value a tagged integer
extern objrout_sigBM ROUTINEOBJNAME_BM (_3kMqlEugRVW_7DgwjR4CBbP);

value_tyBM
ROUTINEOBJNAME_BM (_3kMqlEugRVW_7DgwjR4CBbP)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,
 const value_tyBM arg2, const value_tyBM arg3, const value_tyBM arg4,
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  ASSERT_BM (istaggedint_BM (arg1));    // the integer to dump
  // arg2 is the bufob
  // arg3 is the obdumper
  // arg4 is the depth
  ASSERT_BM (istaggedint_BM (arg4));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM recv;
                 objectval_tyBM * bufob; objectval_tyBM * dumpob;
                 value_tyBM depthv;
    );
  _.recv = arg1;
  WEAKASSERT_BM (objhasstrbufferpayl_BM (arg2));
  _.bufob = objectcast_BM (arg2);
  _.dumpob = objectcast_BM (arg3);
  WEAKASSERT_BM (!_.dumpob || obdumpgetdumper_BM (_.dumpob) != NULL);
  _.depthv = arg4;
  objstrbufferprintfpayl_BM (_.bufob, " %lld",
                             (long long) getint_BM (_.recv));
  LOCALRETURN_BM (_.bufob);
}                               /* end ROUTINE _3kMqlEugRVW_7DgwjR4CBbP */



////////////////////////////////////////////////////////////////
//// for the method to dump_value a set
extern objrout_sigBM ROUTINEOBJNAME_BM (_3Tc3E4uo2p5_4EXWCPwCR5b);

value_tyBM
ROUTINEOBJNAME_BM (_3Tc3E4uo2p5_4EXWCPwCR5b)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // set
 const value_tyBM arg2,         // bufob
 const value_tyBM arg3,         // dumpob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  ASSERT_BM (isset_BM (arg1));  // the set to dump
  // arg2 is the bufob
  // arg3 is the obdump
  ASSERT_BM (istaggedint_BM (arg4));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const setval_tyBM * recv; objectval_tyBM * dumpob;
                 objectval_tyBM * bufob; value_tyBM depthv;
                 const objectval_tyBM * curobj;
    );
  _.recv = (arg1);
  _.bufob = objectcast_BM (arg2);
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.bufob));
  _.dumpob = objectcast_BM (arg3);
  WEAKASSERT_BM (!_.dumpob || obdumpgetdumper_BM (_.dumpob) != NULL);
  _.depthv = arg4;
  objstrbufferprintfpayl_BM (_.bufob, "\t{");
  objstrbuffermoreindentpayl_BM (_.bufob);
  unsigned card = setcardinal_BM (_.recv);
  unsigned cnt = 0;
  if (card > 2)
    objstrbuffernewlinepayl_BM (_.bufob);
  for (unsigned ix = 0; ix < card; ix++)
    {
      _.curobj = setelemnth_BM (_.recv, ix);
      if (_.dumpob && !obdumpobjisdumpable_BM (_.dumpob, _.curobj))
        continue;
      char curidbuf[32];
      idtocbuf32_BM (objid_BM (_.curobj), curidbuf);
      if (cnt > 0 && cnt % 3 == 0)
        objstrbuffernewlinepayl_BM (_.bufob);
      objstrbufferprintfpayl_BM (_.bufob, "\t%s", curidbuf);
      cnt++;
    };
  objstrbufferlessindentpayl_BM (_.bufob);
  objstrbufferprintfpayl_BM (_.bufob, " }");
  LOCALRETURN_BM (_.bufob);
}                               /* end ROUTINE _3Tc3E4uo2p5_4EXWCPwCR5b */


////////////////////////////////////////////////////////////////
//// for the method to dump_value a tuple
extern objrout_sigBM ROUTINEOBJNAME_BM (_5D9kkPHSPxq_8suDXpjlzjE);

value_tyBM
ROUTINEOBJNAME_BM (_5D9kkPHSPxq_8suDXpjlzjE)    // dump_value tuple
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // tup
 const value_tyBM arg2,         // bufob
 const value_tyBM arg3,         // dumpob
 const value_tyBM arg4,         // depthv
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  ASSERT_BM (istuple_BM (arg1));        // the tuple to dump
  // arg2 is the bufob
  // arg3 is the obdump
  ASSERT_BM (istaggedint_BM (arg4));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const tupleval_tyBM * recv; objectval_tyBM * bufob;
                 objectval_tyBM * dumpob; value_tyBM depthv;
                 const objectval_tyBM * curobj;
    );
  _.recv = (arg1);
  _.bufob = objectcast_BM (arg2);
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.bufob));
  _.dumpob = objectcast_BM (arg3);
  WEAKASSERT_BM (!_.dumpob || obdumpgetdumper_BM (_.dumpob) != NULL);
  _.depthv = arg4;
  objstrbufferprintfpayl_BM (_.bufob, "\t[");
  objstrbuffermoreindentpayl_BM (_.bufob);
  unsigned tsiz = tuplesize_BM (_.recv);
  unsigned cnt = 0;
  if (tsiz > 2)
    objstrbuffernewlinepayl_BM (_.bufob);
  for (unsigned ix = 0; ix < tsiz; ix++)
    {
      _.curobj = tuplecompnth_BM (_.recv, ix);
      if (_.dumpob && !obdumpobjisdumpable_BM (_.dumpob, _.curobj))
        continue;
      char curidbuf[32];
      idtocbuf32_BM (objid_BM (_.curobj), curidbuf);
      if (cnt > 0 && cnt % 3 == 0)
        objstrbuffernewlinepayl_BM (_.bufob);
      objstrbufferprintfpayl_BM (_.bufob, "\t%s", curidbuf);
      cnt++;
    };
  objstrbufferlessindentpayl_BM (_.bufob);
  objstrbufferprintfpayl_BM (_.bufob, " ]");
  LOCALRETURN_BM (_.bufob);
}                               /* end ROUTINE _5D9kkPHSPxq_8suDXpjlzjE */


////////////////////////////////////////////////////////////////
//// for the method to dump_value a node
extern objrout_sigBM ROUTINEOBJNAME_BM (_5v30KC0IMxx_53ZzXprJTM6);

value_tyBM
ROUTINEOBJNAME_BM (_5v30KC0IMxx_53ZzXprJTM6)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // nod
 const value_tyBM arg2,         // bufob
 const value_tyBM arg3,         // dumpob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_transient_connective_object        //
    = BMK_5NXebtEFXd3_17ziuxzTfC1;
  ASSERT_BM (isnode_BM (arg1)); // the node to dump
  // arg2 is the bufob
  // arg3 is the obdumper
  ASSERT_BM (istaggedint_BM (arg4));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const node_tyBM * recv; objectval_tyBM * dumpob;
                 objectval_tyBM * bufob; value_tyBM depthv; value_tyBM curson;
                 const objectval_tyBM * connobj;
    );
  _.recv = (arg1);
  _.bufob = objectcast_BM (arg2);
  _.dumpob = objectcast_BM (arg3);
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.bufob));
  WEAKASSERT_BM (!_.dumpob || obdumpgetdumper_BM (_.dumpob) != NULL);
  _.depthv = arg4;
  unsigned depth = getint_BM (_.depthv);
  _.connobj = nodeconn_BM ((const value_tyBM) _.recv);
  if (_.dumpob && !obdumpobjisdumpable_BM (_.dumpob, _.connobj))
    {
      objstrbufferprintfpayl_BM (_.bufob, " __");
      LOCALRETURN_BM (_.bufob);
    }
  if (objectisinstance_BM (_.connobj, k_transient_connective_object))
    {
      objstrbufferprintfpayl_BM (_.bufob, " __");
      LOCALRETURN_BM (_.bufob);
    }
  char connidbuf[32];
  idtocbuf32_BM (objid_BM (_.connobj), connidbuf);
  const char *n = findobjectname_BM (_.connobj);
  if (n && depth < 5 && !_.dumpob)
    objstrbufferprintfpayl_BM (_.bufob, "\t* %s |=%s| (", connidbuf, n);
  else
    objstrbufferprintfpayl_BM (_.bufob, "\t* %s (", connidbuf);
  unsigned width = nodewidth_BM ((const value_tyBM) _.recv);
  objstrbuffermoreindentpayl_BM (_.bufob);
  unsigned cnt = 0;
  for (unsigned six = 0; six < width; six++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.recv, six);
      if (!_.curson)
        {
          objstrbufferprintfpayl_BM (_.bufob, "\t__");
          continue;
        }
      if (_.dumpob && !obdumpvalisdumpable_BM (_.dumpob, _.curson))
        {
          objstrbufferprintfpayl_BM (_.bufob, "\t__");
          continue;
        }
      if (cnt > 0 && cnt % 4 == 0)
        objstrbuffernewlinepayl_BM (_.bufob);
      objstrbufferprintfpayl_BM (_.bufob, "\t");
      send3_BM (_.curson, BMP_dump_value,
                CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (depth + 1));
      cnt++;
    }
  objstrbufferlessindentpayl_BM (_.bufob);
  objstrbufferprintfpayl_BM (_.bufob, ")");
  LOCALRETURN_BM (_.bufob);
}                               /* end ROUTINE _5v30KC0IMxx_53ZzXprJTM6 */

////////////////////////////////////////////////////////////////
//// for the method to dump_value a closure
extern objrout_sigBM ROUTINEOBJNAME_BM (_6jvRZetUz36_978V6SKIWZC);

value_tyBM
ROUTINEOBJNAME_BM (_6jvRZetUz36_978V6SKIWZC)    //
(struct stackframe_stBM * stkf, const value_tyBM arg1,  // clos
 const value_tyBM arg2,         // bufob
 const value_tyBM arg3,         // dumpob
 const value_tyBM arg4,         // depthv
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_transient_connective_object        //
    = BMK_5NXebtEFXd3_17ziuxzTfC1;
  ASSERT_BM (isclosure_BM (arg1));      // the closure to dump
  // arg2 is the bufob
  ASSERT_BM (istaggedint_BM (arg4));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * recv;
                 objectval_tyBM * dumpob; objectval_tyBM * bufob;
                 value_tyBM depthv; value_tyBM curson;
                 const objectval_tyBM * connobj;
    );
  _.recv = (arg1);
  _.bufob = objectcast_BM (arg2);
  _.dumpob = objectcast_BM (arg3);
  WEAKASSERT_BM (!_.dumpob || obdumpgetdumper_BM (_.dumpob) != NULL);
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.bufob));
  _.depthv = arg4;
  unsigned depth = getint_BM (_.depthv);
  _.connobj = closureconn_BM ((const value_tyBM) _.recv);
  if (objectisinstance_BM (_.connobj, k_transient_connective_object))
    {
      objstrbufferprintfpayl_BM (_.bufob, " __");
      LOCALRETURN_BM (_.bufob);
    }
  if (_.dumpob && !obdumpobjisdumpable_BM (_.dumpob, _.connobj))
    {
      objstrbufferprintfpayl_BM (_.bufob, " |transclos:| __");
      LOCALRETURN_BM (_.bufob);
    }
  char connidbuf[32];
  idtocbuf32_BM (objid_BM (_.connobj), connidbuf);
  objstrbufferprintfpayl_BM (_.bufob, "\t%% %s (", connidbuf);
  unsigned width = closurewidth_BM ((const value_tyBM) _.recv);
  objstrbuffermoreindentpayl_BM (_.bufob);
  unsigned cnt = 0;
  for (unsigned six = 0; six < width; six++)
    {
      _.curson = closurenthson_BM ((const value_tyBM) _.recv, six);
      if (!_.curson)
        {
          objstrbufferprintfpayl_BM (_.bufob, "\t__");
          continue;
        }
      if (_.dumpob && !obdumpvalisdumpable_BM (_.dumpob, _.curson))
        {
          objstrbufferprintfpayl_BM (_.bufob, "\t__");
          continue;
        }
      if (cnt > 0 && cnt % 4 == 0)
        objstrbuffernewlinepayl_BM (_.bufob);
      objstrbufferprintfpayl_BM (_.bufob, "\t");
      send3_BM (_.curson, BMP_dump_value,
                CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (depth + 1));
      cnt++;
    }
  objstrbufferlessindentpayl_BM (_.bufob);
  objstrbufferprintfpayl_BM (_.bufob, ")");
  LOCALRETURN_BM (_.bufob);
}                               /* end ROUTINE _6jvRZetUz36_978V6SKIWZC */

////////////////////////////////////////////////////////////////
//// for the method to dump_value a string
extern objrout_sigBM ROUTINEOBJNAME_BM (_7mvOlkB1tAJ_3psVFz4QEAn);

value_tyBM
ROUTINEOBJNAME_BM (_7mvOlkB1tAJ_3psVFz4QEAn)    //
(struct stackframe_stBM * stkf, const value_tyBM arg1,  // strv
 const value_tyBM arg2,         // bufob
 const value_tyBM arg3,         // dumpb
 const value_tyBM arg4,         // depthv
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  ASSERT_BM (isstring_BM (arg1));       // the string to dump
  // arg2 is the bufob
  // arg3 is the dumpob
  ASSERT_BM (istaggedint_BM (arg4));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const stringval_tyBM * recv;   //
                 objectval_tyBM * dumpob;       //
                 objectval_tyBM * bufob;        //
                 value_tyBM depthv;     //
                 value_tyBM curson;     //
                 const objectval_tyBM * connobj;        //
    );
  _.recv = (arg1);
  _.bufob = objectcast_BM (arg2);
  _.dumpob = objectcast_BM (arg3);
  WEAKASSERT_BM (!_.dumpob || obdumpgetdumper_BM (_.dumpob) != NULL);
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.bufob));
  _.depthv = arg4;
  unsigned depth = getint_BM (_.depthv);
  ASSERT_BM (depth < MAXDEPTHMETHOD_BM);
  unsigned bsiz = lenstring_BM (_.recv);
  const char *bstr = bytstring_BM (_.recv);
  objstrbufferprintfpayl_BM (_.bufob, "\t\"");
  if (bsiz < STRBUFFERWANTEDWIDTH_BM)
    {
      objstrbufferencodedutf8payl_BM (_.bufob, bstr, bsiz);
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
          objstrbufferencodedutf8payl_BM (_.bufob, ps, nextp - ps);
          if (*nextp)
            {
              if (uc == '\n')
                {
                  objstrbufferprintfpayl_BM (_.bufob, "\"+\t\"");
                  nextp = g_utf8_next_char (nextp);
                }
              else
                objstrbufferprintfpayl_BM (_.bufob, "\"&\t\"");
            }
          else if (nextp < bend)
            {
              if (uc == '\n')
                objstrbufferprintfpayl_BM (_.bufob, "\\n\"");
              else
                objstrbufferprintfpayl_BM (_.bufob, "\"");
            }
        }
    }
  objstrbufferprintfpayl_BM (_.bufob, "\"");
  LOCALRETURN_BM (_.bufob);
}                               /* end dump_value°string ROUTINE _7mvOlkB1tAJ_3psVFz4QEAn */




//// for the method to dump_scan°class
extern objrout_sigBM ROUTINEOBJNAME_BM (_4EBQMvthjcP_2OiZxZviSQc);

value_tyBM
ROUTINEOBJNAME_BM (_4EBQMvthjcP_2OiZxZviSQc)    // dump_scan°class 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // reciever
 const value_tyBM arg2,         // dumpob
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 objectval_tyBM * dumpob; const objectval_tyBM * supercl;
                 const setval_tyBM * selset; const objectval_tyBM * cursel;
                 value_tyBM curmeth;
    );
  ASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  // arg2 is the dumpob
  _.dumpob = objectcast_BM (arg2);
  WEAKASSERT_BM (obdumpgetdumper_BM (_.dumpob) != NULL);
  WEAKASSERT_BM (objhasclassinfo_BM (_.recv));
  ASSERT_BM (arg3_ == NULL);
  ASSERT_BM (restargs_ == NULL);
  _.supercl = objgetclassinfosuperclass_BM ((const value_tyBM) _.recv);
  _.selset = objgetclassinfosetofselectors_BM ((const value_tyBM) _.recv);
  obdumpscanobj_BM (_.dumpob, _.supercl);
  obdumpscanvalue_BM (_.dumpob, (const value_tyBM) _.selset, 0);
  unsigned nbsel = setcardinal_BM (_.selset);
  for (unsigned six = 0; six < nbsel; six++)
    {
      _.cursel = setelemnth_BM (_.selset, six);
      if (!obdumpobjisdumpable_BM (_.dumpob, _.cursel))
        continue;
      _.curmeth = (value_tyBM) objgetclassinfomethod_BM (_.recv, _.cursel);
      ASSERT_BM (isclosure_BM (_.curmeth));
      obdumpscanvalue_BM (_.dumpob, _.curmeth, 0);
    }
  LOCALRETURN_BM ((value_tyBM) _.recv);
}                               /* end ROUTINE _4EBQMvthjcP_2OiZxZviSQc dump_scan°class */


//// for the method to dump_data°class
extern objrout_sigBM ROUTINEOBJNAME_BM (_67IapmpeTLU_8MQKtlK8iAD);

value_tyBM
ROUTINEOBJNAME_BM (_67IapmpeTLU_8MQKtlK8iAD)    // dump_data°class
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // reciever
 const value_tyBM arg2,         // dumpob
 const value_tyBM arg3,         // strbufob
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv; objectval_tyBM * dumpob;
                 objectval_tyBM * bufob; const objectval_tyBM * supercl;
                 const setval_tyBM * selset; const objectval_tyBM * cursel;
                 value_tyBM curmeth;
    );
  ASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  _.dumpob = objectcast_BM (arg2);
  WEAKASSERT_BM (obdumpgetdumper_BM (_.dumpob) != NULL);
  _.bufob = objectcast_BM (arg3);
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.bufob));
  ASSERT_BM (restargs_ == NULL);
  _.supercl = objgetclassinfosuperclass_BM ((const value_tyBM) _.recv);
  if (!_.supercl)
    _.supercl = BMP_object;
  _.selset = objgetclassinfosetofselectors_BM ((const value_tyBM) _.recv);
  unsigned nbsel = setcardinal_BM (_.selset);
  objstrbufferprintfpayl_BM (_.bufob, "!~ class (~\t");
  objstrbuffermoreindentpayl_BM (_.bufob);
  if (obdumpobjisdumpable_BM (_.dumpob, _.supercl))
    {
      char superidbuf[32];
      memset (superidbuf, 0, sizeof (superidbuf));
      idtocbuf32_BM (objid_BM (_.supercl), superidbuf);
      const char *supername = findobjectname_BM (_.supercl);
      if (supername)
        objstrbufferprintfpayl_BM (_.bufob, "|supercl %s:| %s", supername,
                                   superidbuf);
      else
        objstrbufferprintfpayl_BM (_.bufob, "|supercl=| %s", superidbuf);
    }
  else
    {
      objstrbufferprintfpayl_BM (_.bufob, "|nosuperclass| __");
    }
  for (unsigned six = 0; six < nbsel; six++)
    {
      _.cursel = setelemnth_BM (_.selset, six);
      if (!obdumpobjisdumpable_BM (_.dumpob, _.cursel))
        continue;
      _.curmeth = (value_tyBM) objgetclassinfomethod_BM (_.recv, _.cursel);
      ASSERT_BM (isclosure_BM (_.curmeth));
      if (!obdumpvalisdumpable_BM (_.dumpob, _.curmeth))
        continue;
      char selidbuf[32];
      memset (selidbuf, 0, sizeof (selidbuf));
      idtocbuf32_BM (objid_BM (_.cursel), selidbuf);
      const char *selname = findobjectname_BM (_.cursel);
      if (selname && !_.dumpob)
        objstrbufferprintfpayl_BM (_.bufob, "\n~: %s |=%s|\t", selidbuf,
                                   selname);
      else
        objstrbufferprintfpayl_BM (_.bufob, "\n~: %s\t", selidbuf);
      unsigned oldbuflen = objstrbufferlengthpayl_BM (_.bufob);
      send3_BM (_.curmeth, BMP_dump_value,
                CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (1));
      unsigned newbuflen = objstrbufferlengthpayl_BM (_.bufob);
      if (newbuflen == oldbuflen)
        objstrbufferprintfpayl_BM (_.bufob, "\t |nometh| __");
    }
  objstrbufferlessindentpayl_BM (_.bufob);
  objstrbufferappendcstrpayl_BM (_.bufob, " ~)\n");
  LOCALRETURN_BM ((value_tyBM) _.recv);
}                               /* end ROUTINE _67IapmpeTLU_8MQKtlK8iAD */



//// for the method to dump_scan°hset_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_4DvEF1tVGFD_6VVLpFn6FPW);

value_tyBM
ROUTINEOBJNAME_BM (_4DvEF1tVGFD_6VVLpFn6FPW)    //  dump_scan°hset_object
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // reciever
 const value_tyBM arg2,         // dumpob
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv;
                 objectval_tyBM * dumpob; const setval_tyBM * setv;
    );
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  _.dumpob = objectcast_BM (arg2);
  WEAKASSERT_BM (arg3_ == NULL);
  WEAKASSERT_BM (restargs_ == NULL);
  WEAKASSERT_BM (isobject_BM (_.dumpob));
  WEAKASSERT_BM (obdumpgetdumper_BM (_.dumpob) != NULL);
  WEAKASSERT_BM (objhashashsetpayl_BM (_.recv));
  _.setv = objhashsettosetpayl_BM (_.recv);
  NONPRINTF_BM ("dump_scan°hset_object recv=%s setv=%s",
                objectdbg_BM (_.recv),
                debug_outstr_value_BM ((value_tyBM) _.setv, CURFRAME_BM, 1));
  obdumpscanvalue_BM (_.dumpob, (value_tyBM) _.setv, 0);
  LOCALRETURN_BM ((value_tyBM) _.recv);
}                               /* end dump_scan°hset_object ROUTINE _4DvEF1tVGFD_6VVLpFn6FPW */



//// for the method to dump_data°hset_object

extern objrout_sigBM ROUTINEOBJNAME_BM (_7GMLV81ntO3_4NHTv7fCL0A);

value_tyBM
ROUTINEOBJNAME_BM (_7GMLV81ntO3_4NHTv7fCL0A)    // dump_data°hset_object
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // reciever
 const value_tyBM arg2,         // dumpob
 const value_tyBM arg3,         // strbufob
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_dump_value = BMK_1FEnnpEkGdI_5DAcVDL5XHG;
  ASSERT_BM (k_dump_value != NULL);
  objectval_tyBM *k_put = BMK_9pvzBeIKHXF_8YDPCrQ6OEK;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 value_tyBM funv; objectval_tyBM * dumpob;
                 objectval_tyBM * bufob; const setval_tyBM * setv;
                 value_tyBM dumpres;
    );
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  _.dumpob = objectcast_BM (arg2);
  WEAKASSERT_BM (obdumpgetdumper_BM (_.dumpob));
  _.bufob = objectcast_BM (arg3);
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.bufob));
  WEAKASSERT_BM (restargs_ == NULL);
  WEAKASSERT_BM (valtype_BM (objpayload_BM (_.recv)) == typayl_hashsetobj_BM);
  ASSERT_BM (restargs_ == NULL);
  // emit todo (put {elements....})
  _.setv = hashsetobj_to_set_BM (objpayload_BM (_.recv));
  objstrbufferprintfpayl_BM (_.bufob, "!~ todo (~\t");
  objstrbuffermoreindentpayl_BM (_.bufob);
  _.dumpres = send3_BM (k_put, BMP_dump_value,
                        CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (0));
  objstrbufferprintfpayl_BM (_.bufob, "\t");
  _.dumpres = send3_BM ((value_tyBM) _.setv, BMP_dump_value,
                        CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (0));
  objstrbufferlessindentpayl_BM (_.bufob);
  objstrbufferappendcstrpayl_BM (_.bufob, "\n~)\n");
  LOCALRETURN_BM (_.recv);
}                               /* end dump_data hset_object ROUTINE _7GMLV81ntO3_4NHTv7fCL0A  */



//// for the method to get°hset_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_26FUvWKvkYr_5hyqhhV8NEh);

value_tyBM
ROUTINEOBJNAME_BM (_26FUvWKvkYr_5hyqhhV8NEh)    // get°hset_object
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         /* reciever */
 const value_tyBM arg2 /*elem */ ,
 const value_tyBM arg3 __attribute__((unused)),
 const value_tyBM arg4 __attribute__((unused)),
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv;
                 value_tyBM elem; objectval_tyBM * curob;
                 const setval_tyBM * setv;
    );
  struct hashsetobj_stBM *hset = NULL;
  if (!isobject_BM (arg1))
    LOCALRETURN_BM (NULL);
  _.recv = arg1;
  _.elem = arg2;
  hset = hashsetobjcast_BM (objpayload_BM (_.recv));
  if (!hset)
    LOCALRETURN_BM (NULL);
  if (isobject_BM (_.elem))
    {
      if (hashsetobj_contains_BM (hset, _.elem))
        LOCALRETURN_BM (_.elem);
      LOCALRETURN_BM (NULL);
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
      LOCALRETURN_BM (_.setv);
    }
  else if (!_.elem)
    {
      _.setv = hashsetobj_to_set_BM (hset);
      LOCALRETURN_BM (_.setv);
    }
  LOCALRETURN_BM (NULL);
}                               /* end ROUTINE _26FUvWKvkYr_5hyqhhV8NEh get°hset_object */



//// for the method to put°hset_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_91iTl2vqF09_72WJj4swbNi);

value_tyBM
ROUTINEOBJNAME_BM (_91iTl2vqF09_72WJj4swbNi)    // put°hset_object
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         /* reciever */
 const value_tyBM arg2 /*putseq */ ,
 const value_tyBM arg3 __attribute__((unused)),
 const value_tyBM arg4 __attribute__((unused)),
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv;
                 const seqobval_tyBM * putseqv; objectval_tyBM * curob;
    );
  if (!isobject_BM (arg1))
    LOCALRETURN_BM (NULL);
  _.recv = arg1;
  if (!issequence_BM (arg2))
    LOCALRETURN_BM (NULL);
  _.putseqv = arg2;
  unsigned lnseq = sequencesize_BM (_.putseqv);
  objputhashsetpayl_BM (_.recv, 9 * lnseq / 8 + 2);
  for (unsigned ix = 0; ix < lnseq; ix++)
    {
      _.curob = sequencenthcomp_BM (_.putseqv, ix);
      if (!_.curob)
        continue;
      objhashsetaddpayl_BM (_.recv, _.curob);
    };
  LOCALRETURN_BM (_.recv);
}                               /* end ROUTINE _91iTl2vqF09_72WJj4swbNi put°hset_object */


//// for the method to add°hset_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_2juH5YMCcog_8pQGCuE5mod);

value_tyBM
ROUTINEOBJNAME_BM (_2juH5YMCcog_8pQGCuE5mod)    // add°hset_object
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         /* reciever */
 const value_tyBM arg2 /*addend */ ,
 const value_tyBM arg3 __attribute__((unused)),
 const value_tyBM arg4 __attribute__((unused)),
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; value_tyBM addend;
                 const seqobval_tyBM * putseqv; objectval_tyBM * curob;
    );
  if (!isobject_BM (arg1))
    LOCALRETURN_BM (NULL);
  _.recv = arg1;
  if (!objhashashsetpayl_BM (_.recv))
    {
      NONPRINTF_BM ("add°hset_object bad recv %s", objectdbg_BM (_.recv));
      LOCALRETURN_BM (NULL);
    }
  NONPRINTF_BM ("add°hset_object recv %s start", objectdbg_BM (_.recv));
  _.addend = arg2;
  if (isobject_BM (_.addend))
    {
      objhashsetaddpayl_BM (_.recv, _.addend);
      NONPRINTF_BM ("add°hset_object recv %s addob %s",
                    objectdbg_BM (_.recv),
                    objectdbg1_BM ((objectval_tyBM *) _.addend));
      LOCALRETURN_BM (_.recv);
    }
  else if (issequence_BM (_.addend))
    {
      unsigned nbadd = sequencesize_BM (_.addend);
      DBGPRINTF_BM ("add°hset_object recv %s addseq nbadd=%d",
                    objectdbg_BM (_.recv), nbadd);
      objhashsetgrowpayl_BM (_.recv, nbadd + 1);
      for (unsigned ix = 0; ix < nbadd; ix++)
        {
          _.curob = sequencenthcomp_BM (_.addend, ix);
          DBGPRINTF_BM ("add°hset_object recv %s curob %s",
                        objectdbg_BM (_.recv),
                        objectdbg1_BM ((objectval_tyBM *) _.curob));
          objhashsetaddpayl_BM (_.recv, _.curob);
        };
      LOCALRETURN_BM (_.recv);
    }
  LOCALRETURN_BM (NULL);
}                               /* end ROUTINE _2juH5YMCcog_8pQGCuE5mod add°hset_object */



// for the method remove°hset_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_5hedSPIXD0o_5ef69rR2kzb);

value_tyBM
ROUTINEOBJNAME_BM (_5hedSPIXD0o_5ef69rR2kzb)    // remove°hset_object
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         /* reciever */
 const value_tyBM arg2 /*removedv */ ,
 const value_tyBM arg3 __attribute__((unused)),
 const value_tyBM arg4 __attribute__((unused)),
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; value_tyBM removedv;
                 const seqobval_tyBM * putseqv; objectval_tyBM * curob;
    );
  if (!isobject_BM (arg1))
    LOCALRETURN_BM (NULL);
  _.recv = arg1;
  if (!objhashashsetpayl_BM (_.recv))
    LOCALRETURN_BM (NULL);
  _.removedv = arg2;
  if (isobject_BM (_.removedv))
    {
      objhashsetremovepayl_BM (_.recv, _.removedv);
      LOCALRETURN_BM (_.recv);
    }
  else if (issequence_BM (_.removedv))
    {
      unsigned nbrem = sequencesize_BM (_.removedv);
      for (unsigned ix = 0; ix < nbrem; ix++)
        {
          _.curob = sequencenthcomp_BM (_.removedv, ix);
          objhashsetremovepayl_BM (_.recv, _.curob);
        };
      if (nbrem > TINYSIZE_BM)
        objhashsetgrowpayl_BM (_.recv, 1);      /* could reorganize the hset */
      LOCALRETURN_BM (_.recv);
    }
  else
    LOCALRETURN_BM (NULL);
}                               /* end ROUTINE _5hedSPIXD0o_5ef69rR2kzb  remove°hset_object */



//// for the method to give the set°hset_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_88cUYsDqSFO_0DKwKLSOmpm);

value_tyBM
ROUTINEOBJNAME_BM (_88cUYsDqSFO_0DKwKLSOmpm)    //
(struct stackframe_stBM * stkf, const value_tyBM arg1,  /* reciever */
 const value_tyBM arg2 __attribute__((unused)), //
 const value_tyBM arg3 __attribute__((unused)), //
 const value_tyBM arg4 __attribute__((unused)), //
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 const setval_tyBM * setv;
    );
  _.recv = arg1;
  if (!isobject_BM (arg1))
    LOCALRETURN_BM (NULL);
  if (valtype_BM (objpayload_BM (_.recv)) != typayl_hashsetobj_BM)
    LOCALRETURN_BM (NULL);
  _.setv = hashsetobj_to_set_BM (objpayload_BM (_.recv));
  LOCALRETURN_BM (_.setv);
}                               /* end ROUTINE _88cUYsDqSFO_0DKwKLSOmpm set of hset_object */

/****************************************************************/

//// for the method to dump_scan°vector_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_99PsYq2Nw3w_9q4BJNeQ6Re);

value_tyBM
ROUTINEOBJNAME_BM (_99PsYq2Nw3w_9q4BJNeQ6Re)    //  dump_scan°vector_object
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // reciever
 const value_tyBM arg2,         // dumpob
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; objectval_tyBM * dumpob;
                 value_tyBM compv;
    );
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  _.dumpob = objectcast_BM (arg2);
  WEAKASSERT_BM (obdumpgetdumper_BM (_.dumpob) != NULL);
  WEAKASSERT_BM (objhasdatavectpayl_BM (_.recv));
  extendedval_tyBM payl = objpayload_BM (_.recv);
  WEAKASSERT_BM (valtype_BM (payl) == typayl_vectval_BM);
  ASSERT_BM (arg3_ == NULL);
  unsigned dvlen = objdatavectlengthpayl_BM (_.recv);
  for (unsigned ix = 0; ix < dvlen; ix++)
    {
      _.compv = objdatavectnthpayl_BM (_.recv, dvlen);
      if (!_.compv)
        continue;
      obdumpscanvalue_BM (_.dumpob, (value_tyBM) _.compv, 0);
    }
  _.compv = NULL;
  LOCALRETURN_BM ((value_tyBM) _.recv);
}                               /* end dump_scan°vector_object ROUTINE _99PsYq2Nw3w_9q4BJNeQ6Re */


//// for the method to dump_data°vector_object

extern objrout_sigBM ROUTINEOBJNAME_BM (_0y90r6nyAYP_2MmfH2V00B1);

value_tyBM
ROUTINEOBJNAME_BM (_0y90r6nyAYP_2MmfH2V00B1)    // dump_data°vector_object
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // reciever
 const value_tyBM arg2,         // dumpob 
 const value_tyBM arg3,         // strbufob
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_dump_value = BMK_1FEnnpEkGdI_5DAcVDL5XHG;
  ASSERT_BM (k_dump_value != NULL);
  objectval_tyBM *k_fill = BMK_8pmtJTuEbBF_4xNgNCOElwL;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv;
                 objectval_tyBM * dumpob; objectval_tyBM * bufob;
                 value_tyBM dumpres; value_tyBM nodv;
    );
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  _.dumpob = objectcast_BM (arg2);
  WEAKASSERT_BM (obdumpgetdumper_BM (_.dumpob));
  _.bufob = objectcast_BM (arg3);
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.bufob));
  WEAKASSERT_BM (restargs_ == NULL);
  WEAKASSERT_BM (objhasdatavectpayl_BM (_.recv));
  ASSERT_BM (arg3 == NULL);
  ASSERT_BM (restargs_ == NULL);
  // emit todo (fill *node (vectcomp...))
  _.nodv = (value_tyBM) objdatavecttonodepayl_BM (_.recv, BMP_node);
  objstrbufferprintfpayl_BM (_.bufob, "!~ todo (~\t");
  objstrbuffermoreindentpayl_BM (_.bufob);
  _.dumpres = send3_BM (k_fill, BMP_dump_value,
                        CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (0));
  objstrbufferprintfpayl_BM (_.bufob, "\t");
  _.dumpres = send3_BM ((value_tyBM) _.nodv, BMP_dump_value,
                        CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (0));
  objstrbufferlessindentpayl_BM (_.bufob);
  objstrbufferappendcstrpayl_BM (_.bufob, "\n~)\n");
  LOCALRETURN_BM (_.recv);
}                               /* end dump_data vector_object ROUTINE_0y90r6nyAYP_2MmfH2V00B1  */


// method fill°vector_object _7BhZWKS2grS_3TnuK6o8ZFH

extern objrout_sigBM ROUTINEOBJNAME_BM (_7BhZWKS2grS_3TnuK6o8ZFH);

value_tyBM
ROUTINEOBJNAME_BM (_7BhZWKS2grS_3TnuK6o8ZFH)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // reciever
 const value_tyBM arg2,         // content
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_7BhZWKS2grS_3TnuK6o8ZFH,
                 objectval_tyBM * recv; value_tyBM contv;
                 value_tyBM compv;
                 value_tyBM resultv;
    );
  _.recv = objectcast_BM (arg1);
  _.contv = arg2;
  unsigned ilen = 0;
  if (istaggedint_BM (_.contv))
    {
      ilen = getint_BM (_.contv);
      if (ilen < 3)
        ilen = 3;
      else if (ilen > MAXSIZE_BM / 4)
        ilen = MAXSIZE_BM / 4;
    }
  else if (isnode_BM (_.contv))
    ilen = nodewidth_BM (_.contv) + 1;
  else if (issequence_BM (_.contv))
    ilen = sequencesize_BM (_.contv) + 1;
  else
    LOCALRETURN_BM (NULL);
  objputdatavectpayl_BM (_.recv, ilen);
  if (isnode_BM (_.contv))
    {
      unsigned nw = nodewidth_BM (_.contv);
      for (int ix = 0; ix < (int) nw; ix++)
        {
          _.compv = nodenthson_BM (_.contv, ix);
          objdatavectappendpayl_BM (_.recv, _.compv);
        }
    }
  else if (issequence_BM (_.contv))
    {
      unsigned siz = sequencesize_BM (_.contv);
      for (int ix = 0; ix < (int) siz; ix++)
        {
          _.compv = sequencenthcomp_BM (_.contv, ix);
          objdatavectappendpayl_BM (_.recv, _.compv);
        }
    }
  LOCALRETURN_BM (_.recv);
}                               /* end fill°vector_object  _7BhZWKS2grS_3TnuK6o8ZFH */


/****************************************************************/

//// for the method to dump_scan°assoc_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_8MU0cEcpEYN_5SVe0jrv36o);

value_tyBM
ROUTINEOBJNAME_BM (_8MU0cEcpEYN_5SVe0jrv36o)    //  dump_scan°assoc_object
(struct stackframe_stBM * stkf, const value_tyBM arg1,  // recv
 const value_tyBM arg2,         // dumpob
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 const objectval_tyBM * curattrob; value_tyBM curval;
                 objectval_tyBM * dumpob; const setval_tyBM * setv;
    );
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  WEAKASSERT_BM (obdumpgetdumper_BM (arg2) != NULL);
  _.dumpob = arg2;
  NONPRINTF_BM
    ("dump_scan°assoc_object _8MU0cEcpEYN_5SVe0jrv36o recv=%s dumpob=%s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.dumpob));
  WEAKASSERT_BM (objhasassocpayl_BM (_.recv));
  anyassoc_tyBM *assoc = assoccast_BM (objpayload_BM (_.recv));
  if (!assoc)
    LOCALRETURN_BM (NULL);
  ASSERT_BM (arg3_ == NULL);
  ASSERT_BM (restargs == NULL);
  _.setv = assoc_setattrs_BM (assoc);
  obdumpscanvalue_BM (_.dumpob, (const value_tyBM) _.setv, 0);
  unsigned nbattr = setcardinal_BM (_.setv);
  for (unsigned ix = 0; ix < nbattr; ix++)
    {
      _.curattrob = setelemnth_BM (_.setv, ix);
      NONPRINTF_BM
        ("dump_scan°assoc_object ix#%d recv=%s curattrob=%s",
         ix, objectdbg_BM (_.recv), objectdbg1_BM (_.curattrob));
      if (!obdumpobjisdumpable_BM (_.dumpob, _.curattrob))
        continue;
      _.curval = assoc_getattr_BM (assoc, _.curattrob);
      obdumpscanvalue_BM (_.dumpob, _.curval, 0);
    }
  _.dumpob = arg2;
  NONPRINTF_BM
    ("dump_scan°assoc_object end _8MU0cEcpEYN_5SVe0jrv36o recv=%s dumpob=%s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.dumpob));
  LOCALRETURN_BM (_.recv);
}                               /* end dump_scan°assoc_object ROUTINE _8MU0cEcpEYN_5SVe0jrv36o */


////////////////

//// for the method to dump_data°assoc_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_9EytjXNb76D_1ZP3iSk9cuu);

value_tyBM
ROUTINEOBJNAME_BM (_9EytjXNb76D_1ZP3iSk9cuu)    // dump_data°assoc_object
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // reciever
 const value_tyBM arg2,         // dumpob
 const value_tyBM arg3,         // strbufob
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv; objectval_tyBM * dumpob;
                 objectval_tyBM * bufob; const setval_tyBM * setv;
                 objectval_tyBM * curattrob; value_tyBM curval;
                 value_tyBM dumpres;
    );
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  WEAKASSERT_BM (obdumpgetdumper_BM (arg2) != NULL);
  _.dumpob = arg2;
  _.bufob = objectcast_BM (arg3);
  NONPRINTF_BM
    ("dump_data°assoc_object _9EytjXNb76D_1ZP3iSk9cuu recv=%s dumpob=%s bufob=%s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.dumpob),
     objectdbg2_BM (_.bufob));
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.bufob));
  WEAKASSERT_BM (restargs_ == NULL);
  objectval_tyBM *k_dump_value = BMK_1FEnnpEkGdI_5DAcVDL5XHG;
  ASSERT_BM (k_dump_value != NULL);
  objectval_tyBM *k_put = BMK_9pvzBeIKHXF_8YDPCrQ6OEK;
  ASSERT_BM (k_put != NULL);
  WEAKASSERT_BM (isobject_BM ((value_tyBM) _.recv));
  WEAKASSERT_BM (isassoc_BM (objpayload_BM (_.recv)));
  anyassoc_tyBM *assoc = assoccast_BM (objpayload_BM (_.recv));
  if (!assoc)
    LOCALRETURN_BM (NULL);
  _.setv = assoc_setattrs_BM (assoc);
  unsigned nbattr = setcardinal_BM (_.setv);
  int cnt = 0;
  objstrbufferprintfpayl_BM (_.bufob, "!~ todo (~\t");
  objstrbuffermoreindentpayl_BM (_.bufob);
  for (unsigned ix = 0; ix < nbattr; ix++)
    {
      _.curattrob = setelemnth_BM (_.setv, ix);
      if (!obdumpobjisdumpable_BM (_.dumpob, _.curattrob))
        continue;
      _.curval = assoc_getattr_BM (assoc, _.curattrob);
      if (cnt > 0)
        objstrbufferprintfpayl_BM (_.bufob, "\n!& ");
      else
        objstrbufferprintfpayl_BM (_.bufob, " ");
      _.dumpres = send3_BM (k_put, BMP_dump_value,
                            CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (0));
      objstrbufferprintfpayl_BM (_.bufob, "\t");
      _.dumpres = send3_BM (_.curattrob, BMP_dump_value,
                            CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (0));
      objstrbufferprintfpayl_BM (_.bufob, "\t");
      _.dumpres = send3_BM (_.curval, BMP_dump_value,
                            CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (0));
      cnt++;
    };
  objstrbufferlessindentpayl_BM (_.bufob);
  objstrbufferappendcstrpayl_BM (_.bufob, "\n~)\n");
  LOCALRETURN_BM (_.recv);
}                               /* end ROUTINE _9EytjXNb76D_1ZP3iSk9cuu dump_data°assoc_object */


//// for the method set°assoc_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_4zaM2Itdsuq_9qNJK0HbcQI);

value_tyBM
ROUTINEOBJNAME_BM (_4zaM2Itdsuq_9qNJK0HbcQI)    //  set°assoc_object
(struct stackframe_stBM * stkf, const value_tyBM arg1,  /*recv */
 const value_tyBM arg2 __attribute__((unused)),
 const value_tyBM arg3 __attribute__((unused)),
 const value_tyBM arg4 __attribute__((unused)),
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv; const closure_tyBM * clos;
                 const setval_tyBM * setv;
    );
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  anyassoc_tyBM *assoc = assoccast_BM (objpayload_BM (_.recv));
  if (!assoc)
    LOCALRETURN_BM (NULL);
  _.setv = assoc_setattrs_BM (assoc);
  LOCALRETURN_BM (_.setv);
}                               /* end ROUTINE _4zaM2Itdsuq_9qNJK0HbcQ   set°assoc_object */



//// for the method get°assoc_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_4icYJnKsN0o_4xm5UbQOMTe);

value_tyBM
ROUTINEOBJNAME_BM (_4icYJnKsN0o_4xm5UbQOMTe)    //  get°assoc_object
(struct stackframe_stBM * stkf, const value_tyBM arg1,  /* recv */
 const value_tyBM arg2,         /* obattr */
 const value_tyBM arg3 __attribute__((unused)),
 const value_tyBM arg4 __attribute__((unused)),
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 const objectval_tyBM * obattr; const closure_tyBM * clos;
                 value_tyBM resuv;
    );
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  anyassoc_tyBM *assoc = assoccast_BM (objpayload_BM (_.recv));
  if (!assoc)
    LOCALRETURN_BM (NULL);
  if (!isobject_BM (arg2))
    LOCALRETURN_BM (NULL);
  _.obattr = objectcast_BM (arg2);
  _.resuv = assoc_getattr_BM (assoc, _.obattr);
  LOCALRETURN_BM (_.resuv);
}                               /* end ROUTINE _4icYJnKsN0o_4xm5UbQOMTe get°assoc_object */



//// for the method put°assoc_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_6eD9Y1qYcnj_8uVDhxjBpG8);

value_tyBM
ROUTINEOBJNAME_BM (_6eD9Y1qYcnj_8uVDhxjBpG8)    //  put°assoc_object
(struct stackframe_stBM * stkf, const value_tyBM arg1,  /* recv */
 const value_tyBM arg2,         /* obattr */
 const value_tyBM arg3,         /* val */
 const value_tyBM arg4 __attribute__((unused)),
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv;
                 const objectval_tyBM * obattr; const closure_tyBM * clos;
                 value_tyBM valattr;
    );
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  if (!isobject_BM ((value_tyBM) _.recv))
    LOCALRETURN_BM (NULL);
  anyassoc_tyBM *assoc = assoccast_BM (objpayload_BM (_.recv));
  if (!isobject_BM (arg2))
    LOCALRETURN_BM (NULL);
  _.obattr = objectcast_BM (arg2);
  _.valattr = arg3;
  assoc = assoc_addattr_BM (assoc, _.obattr, _.valattr);
  objputpayload_BM (_.recv, assoc);
  LOCALRETURN_BM (_.recv);
}                               /* end ROUTINE _6eD9Y1qYcnj_8uVDhxjBpG8   put°assoc_object */



//// for the method remove°assoc_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_0ekJdzLOqAI_8mejMqkwuKQ);

value_tyBM
ROUTINEOBJNAME_BM (_0ekJdzLOqAI_8mejMqkwuKQ)    //  remove°assoc_object
(struct stackframe_stBM * stkf, const value_tyBM arg1,  /* recv */
 const value_tyBM arg2,         /* attrs */
 const value_tyBM arg3 __attribute__((unused)),
 const value_tyBM arg4 __attribute__((unused)),
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; objectval_tyBM * obattr;
                 value_tyBM attr; const closure_tyBM * clos;
    );
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  if (!isobject_BM ((value_tyBM) _.recv))
    LOCALRETURN_BM (NULL);
  anyassoc_tyBM *assoc = assoccast_BM (objpayload_BM (_.recv));
  if (!isobject_BM (arg2))
    LOCALRETURN_BM (NULL);
  _.attr = (arg2);
  if (isobject_BM (_.attr))
    {
      assoc = assoc_removeattr_BM (assoc, _.attr);
      objputpayload_BM (_.recv, assoc);
      LOCALRETURN_BM (_.recv);
    }
  else if (issequence_BM (_.attr))
    {
      unsigned ln = sequencesize_BM (_.attr);
      for (unsigned ix = 0; ix < ln; ix++)
        {
          _.obattr = sequencenthcomp_BM (_.attr, ix);
          assoc = assoc_removeattr_BM (assoc, _.obattr);
        }
      objputpayload_BM (_.recv, assoc);
      LOCALRETURN_BM (_.recv);
    }
  LOCALRETURN_BM (NULL);
}                               /* end ROUTINE _0ekJdzLOqAI_8mejMqkwuKQ remove°assoc_object */


////////////////////////////////////////////////////////////////
//// for the method to dump_value°object
extern objrout_sigBM ROUTINEOBJNAME_BM (_7fCcteNe7aR_3IKHeHjmzff);

value_tyBM
ROUTINEOBJNAME_BM (_7fCcteNe7aR_3IKHeHjmzff)    // dump_value°object
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // obj
 const value_tyBM arg2,         // bufob
 const value_tyBM arg3,         // dumpob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  ASSERT_BM (isobject_BM (arg1));       // the object to dump
  // arg2 is the bufob
  ASSERT_BM (istaggedint_BM (arg4));
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv; objectval_tyBM * bufob;
                 value_tyBM depthv; objectval_tyBM * dumpob;
                 const objectval_tyBM * curobj;
    );
  _.recv = (arg1);
  _.bufob = objectcast_BM (arg2);
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.bufob));
  _.dumpob = objectcast_BM (arg3);
  WEAKASSERT_BM (!_.dumpob || obdumpgetdumper_BM (_.dumpob) != NULL);
  _.depthv = arg4;
  if (_.dumpob && !obdumpobjisdumpable_BM (_.dumpob, _.recv))
    objstrbufferprintfpayl_BM (_.bufob, " __");
  else
    {
      char objidbuf[32];
      idtocbuf32_BM (objid_BM (_.recv), objidbuf);
      const char *n = findobjectname_BM (_.recv);
      if (n && !_.dumpob)
        objstrbufferprintfpayl_BM (_.bufob, "%s |=%s|\t", objidbuf, n);
      else
        objstrbufferprintfpayl_BM (_.bufob, "%s", objidbuf);
    };
  LOCALRETURN_BM (_.bufob);
}                               /* end ROUTINE _7fCcteNe7aR_3IKHeHjmzff */



//// for the method to dump_data a specially_dumpable
extern objrout_sigBM ROUTINEOBJNAME_BM (_6PmxiZR9WBe_13DwWExCALl);

value_tyBM
ROUTINEOBJNAME_BM (_6PmxiZR9WBe_13DwWExCALl)    //
(struct stackframe_stBM * stkf, const value_tyBM arg1,  // reciever
 const value_tyBM arg2,         // dumpob
 const value_tyBM arg3,         // strbufob
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 objectval_tyBM * dumpob; objectval_tyBM * bufob;
                 value_tyBM closv;
                 value_tyBM resuv;
    );
  ASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  WEAKASSERT_BM (obdumpgetdumper_BM (arg2) != NULL);
  _.dumpob = arg2;
  WEAKASSERT_BM (objhasstrbufferpayl_BM (arg3));
  _.bufob = arg3;
  ASSERT_BM (arg4_ == NULL);
  ASSERT_BM (restargs_ == NULL);
  _.closv = objgetattr_BM (_.recv, BMP_dump_data);
  if (isclosure_BM (_.closv))
    {
      _.resuv = apply3_BM (_.closv, CURFRAME_BM,
                           (const value_tyBM) _.recv, _.dumpob, _.bufob);
      LOCALRETURN_BM (_.resuv);
    }
  LOCALRETURN_BM (_.recv);
}                               /* end dump_data°specially_dumpable _6PmxiZR9WBe_13DwWExCALl */


//// for the method to dump_data a basiclo_function or any object with a value data
extern objrout_sigBM ROUTINEOBJNAME_BM (_7D36kHemyWQ_0YfwWnUhR9Y);

value_tyBM
ROUTINEOBJNAME_BM (_7D36kHemyWQ_0YfwWnUhR9Y)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // reciever
 const value_tyBM arg2,         // dumpob
 const value_tyBM arg3,         // strbufob
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 objectval_tyBM * dumpob; objectval_tyBM * bufob;
                 value_tyBM obval;
    );
  ASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  WEAKASSERT_BM (obdumpgetdumper_BM (arg2) != NULL);
  _.dumpob = arg2;
  _.bufob = objectcast_BM (arg3);
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.bufob));
  ASSERT_BM (restargs_ == NULL);
  _.obval = objpayload_BM (_.recv);
  int tyval = valtype_BM (_.obval);
  if (tyval >= type_FIRST_BM && tyval <= type_LASTREAL_BM)
    {
      objstrbufferprintfpayl_BM (_.bufob, "\n" "!~value (~ ");
      unsigned oldbuflen = objstrbufferlengthpayl_BM (_.bufob);
      send3_BM (_.obval, BMP_dump_value,
                CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (1));
      unsigned newbuflen = objstrbufferlengthpayl_BM (_.bufob);
      if (newbuflen == oldbuflen)
        objstrbufferprintfpayl_BM (_.bufob, "\t |novalue| __");
      objstrbufferprintfpayl_BM (_.bufob, " ~)\n");
      LOCALRETURN_BM (_.recv);
    }
  LOCALRETURN_BM (NULL);
}                               /* end ROUTINE _7D36kHemyWQ_0YfwWnUhR9Y */


//// for the method to dump_scan a basiclo_function or any object with a genuine value as data
extern objrout_sigBM ROUTINEOBJNAME_BM (_9UhDZeDdg2r_55lUqYDPUiF);

value_tyBM
ROUTINEOBJNAME_BM (_9UhDZeDdg2r_55lUqYDPUiF)
(struct stackframe_stBM * stkf,
const value_tyBM arg1,
const value_tyBM arg2, const value_tyBM arg3, const value_tyBM arg4_
__attribute__((unused)), const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv; objectval_tyBM * dumpob;
                 value_tyBM obval;
    );
  ASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  WEAKASSERT_BM (obdumpgetdumper_BM (arg2) != NULL);
  _.dumpob = arg2;
  ASSERT_BM (arg3 == NULL);
  ASSERT_BM (restargs_ == NULL);
  _.obval = objpayload_BM (_.recv);
  int tyval = valtype_BM (_.obval);
  if (tyval >= type_FIRST_BM && tyval <= type_LASTREAL_BM)
    {
      obdumpscanvalue_BM (_.dumpob, (const value_tyBM) _.obval, 0);
      LOCALRETURN_BM (_.recv);
    }
  LOCALRETURN_BM (NULL);
}                               /* end ROUTINE _9UhDZeDdg2r_55lUqYDPUiF */


/// for todo_send closures 

extern objrout_sigBM ROUTINEOBJNAME_BM (_9mdRnBqdqf5_9UvgSFA7wIY);

value_tyBM
ROUTINEOBJNAME_BM (_9mdRnBqdqf5_9UvgSFA7wIY)
(struct stackframe_stBM * stkf,
const value_tyBM arg1 __attribute__((unused)),
const value_tyBM arg2 __attribute__((unused)),
const value_tyBM arg3 __attribute__((unused)),
const value_tyBM arg4 __attribute__((unused)),
const quasinode_tyBM * restargs __attribute__((unused)))
{
  enum
  { closix_ldobj,
    closix_obsel,
    closix__REST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * ldobj;
                 objectval_tyBM * obsel; value_tyBM resuv;
                 const closure_tyBM * clos;
    );
  LOCALGETFUNV_BM (_.clos);
  if (!isclosure_BM ((const value_tyBM) _.clos))
    FATAL_BM ("todo_send _9mdRnBqdqf5_9UvgSFA7wIY non-closure called");
  ASSERT_BM (isclosure_BM ((const value_tyBM) _.clos)
             && closurewidth_BM ((const value_tyBM) _.clos) >= closix__REST);
  unsigned wclos = closurewidth_BM ((const value_tyBM) _.clos);
  _.ldobj =
    objectcast_BM (closurenthson_BM
                   ((const value_tyBM) _.clos, closix_ldobj));
  _.obsel =
    objectcast_BM (closurenthson_BM
                   ((const value_tyBM) _.clos, closix_obsel));
  const value_tyBM *args = _.clos->nodt_sons + closix__REST;
  unsigned nbargs = wclos - closix__REST;
  switch (nbargs)
    {
    case 0:
      LOCALRETURN_BM (send0_BM (_.ldobj, _.obsel, CURFRAME_BM));
    case 1:
      LOCALRETURN_BM (send1_BM (_.ldobj, _.obsel, CURFRAME_BM, args[0]));
    case 2:
      LOCALRETURN_BM (send2_BM
                      (_.ldobj, _.obsel, CURFRAME_BM, args[0], args[1]));
    case 3:
      LOCALRETURN_BM (send3_BM
                      (_.ldobj, _.obsel, CURFRAME_BM,
                       args[0], args[1], args[2]));
    case 4:
      LOCALRETURN_BM (send4_BM
                      (_.ldobj, _.obsel, CURFRAME_BM,
                       args[0], args[1], args[2], args[3]));
    case 5:
      LOCALRETURN_BM (send5_BM
                      (_.ldobj, _.obsel, CURFRAME_BM,
                       args[0], args[1], args[2], args[3], args[4]));
    case 6:
      LOCALRETURN_BM (send6_BM
                      (_.ldobj, _.obsel, CURFRAME_BM,
                       args[0], args[1], args[2], args[3], args[4], args[5]));
    case 7:
      LOCALRETURN_BM (send7_BM
                      (_.ldobj, _.obsel, CURFRAME_BM,
                       args[0], args[1], args[2], args[3], args[4], args[5],
                       args[6]));
    case 8:
      LOCALRETURN_BM (send8_BM
                      (_.ldobj, _.obsel, CURFRAME_BM,
                       args[0], args[1], args[2], args[3], args[4], args[5],
                       args[6], args[7]));
    default:;
    }
  FATAL_BM ("too many %u arguments in todo_send", nbargs);
}                               /* end ROUTINE todo_send _9mdRnBqdqf5_9UvgSFA7wIY */


/// for todo_apply closures 

extern objrout_sigBM ROUTINEOBJNAME_BM (_3W8d51P1dJh_3b1BrOW6pua);

value_tyBM
ROUTINEOBJNAME_BM (_3W8d51P1dJh_3b1BrOW6pua)
(struct stackframe_stBM * stkf,
const value_tyBM arg1 __attribute__((unused)),
const value_tyBM arg2 __attribute__((unused)),
const value_tyBM arg3 __attribute__((unused)),
const value_tyBM arg4 __attribute__((unused)),
const quasinode_tyBM * restargs __attribute__((unused)))
{
  enum
  {
    closix_closure,
    closix_ldobj,
    closix__REST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * cclos; const closure_tyBM * closv;
                 objectval_tyBM * ldobj;
    );
  LOCALGETFUNV_BM (_.cclos);
  if (!isclosure_BM ((const value_tyBM) _.cclos)
      || closurewidth_BM ((const value_tyBM) _.cclos) >= closix__REST)
    FATAL_BM ("todo_apply _3W8d51P1dJh_3b1BrOW6pua bad closure");
  unsigned wclos = closurewidth_BM ((const value_tyBM) _.cclos);
  _.closv =
    closurecast_BM (closurenthson_BM
                    ((const value_tyBM) _.cclos, closix_closure));
  _.ldobj =
    objectcast_BM (closurenthson_BM
                   ((const value_tyBM) _.cclos, closix_ldobj));
  const value_tyBM *args = _.cclos->nodt_sons + closix__REST;
  unsigned nbargs = wclos - closix__REST;
  switch (nbargs)
    {
    case 0:
      LOCALRETURN_BM (apply1_BM ((value_tyBM) _.closv, CURFRAME_BM, _.ldobj));
    case 1:
      LOCALRETURN_BM (apply2_BM
                      ((value_tyBM) _.closv, CURFRAME_BM, _.ldobj, args[0]));
    case 2:
      LOCALRETURN_BM (apply3_BM
                      ((value_tyBM) _.closv, CURFRAME_BM,
                       _.ldobj, args[0], args[1]));
    case 3:
      LOCALRETURN_BM (apply4_BM
                      ((value_tyBM) _.closv, CURFRAME_BM,
                       _.ldobj, args[0], args[1], args[2]));
    default:
      if (nbargs < MAXAPPLYARGS_BM - 1)
        {
          value_tyBM argarr[MAXAPPLYARGS_BM];
          memset (argarr, 0, sizeof (argarr));
          argarr[0] = _.ldobj;
          memcpy (argarr + 1, args, nbargs * sizeof (void *));
          LOCALRETURN_BM (applyvar_BM
                          ((value_tyBM) _.closv,
                           CURFRAME_BM, nbargs + 1, argarr));
        }
    }
  FATAL_BM ("too many %u arguments in todo_apply", nbargs);
}                               /* end ROUTINE todo_apply _3W8d51P1dJh_3b1BrOW6pua */


static int
cmpnamedpredef_BM (const void *p1, const void *p2)
{
  const objectval_tyBM *ob1 = *(const objectval_tyBM **) p1;
  const objectval_tyBM *ob2 = *(const objectval_tyBM **) p2;
  ASSERT_BM (ob1 != NULL);
  ASSERT_BM (ob2 != NULL);
  const char *n1 = findobjectname_BM (ob1);
  const char *n2 = findobjectname_BM (ob2);
  ASSERT_BM (n1 != NULL);
  ASSERT_BM (n2 != NULL);
  return strcmp (n1, n2);
}                               /* end cmpnamedpredef_BM */

//// for the closure to dump_data the predefined, inside dumper_of_predefined
extern objrout_sigBM ROUTINEOBJNAME_BM (_075tZNHCAMa_7XNNBaNM4qv);

value_tyBM
ROUTINEOBJNAME_BM (_075tZNHCAMa_7XNNBaNM4qv)
(struct stackframe_stBM * stkf,
const value_tyBM arg1 __attribute__((unused)),
const value_tyBM arg2,
const value_tyBM arg3 __attribute__((unused)),
const value_tyBM arg4 __attribute__((unused)),
const quasinode_tyBM * restargs __attribute__((unused)))
{
  enum
  {
    closix_filnamv,
    closix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 objectval_tyBM * dumpob; objectval_tyBM * bufob;
                 objectval_tyBM * prsbufob; const stringval_tyBM * filnamv;
                 const setval_tyBM * prset; const objectval_tyBM * curpredef;
                 value_tyBM cclos;
    );
  struct dumper_stBM *duptr = obdumpgetdumper_BM (arg2);
  WEAKASSERT_BM (duptr != NULL);
  _.dumpob = arg2;
  LOCALGETFUNV_BM (_.cclos);
  if (!isclosure_BM (_.cclos) || closurewidth_BM (_.cclos) != closix__LAST)
    FATAL_BM
      ("bad closure for _075tZNHCAMa_7XNNBaNM4qv dump_data of dumper_of_predefined");
  _.prsbufob = makeobj_BM ();
  objputstrbufferpayl_BM (_.prsbufob, 512 * 1024);
  _.filnamv = closurenthson_BM (_.cclos, closix_filnamv);
  ASSERT_BM (isstring_BM ((const value_tyBM) _.filnamv));
  const char *basepath = bytstring_BM (_.filnamv);
  objstrbufferprintfpayl_BM (_.prsbufob,
                             "// generated header file for predefined %s\n",
                             basepath);
  objstrbufferprintfpayl_BM (_.prsbufob,
                             "// this generated header file %s is GPLv3+ licensed\n",
                             basepath);
  _.prset = setpredefinedobjects_BM ();
  unsigned nbpredef = setcardinal_BM (_.prset);
  const objectval_tyBM **arrnamed =
    calloc (nbpredef, sizeof (objectval_tyBM *));
  if (!arrnamed)
    FATAL_BM ("calloc failed for arrnamed (%u) - %m", nbpredef);
  objstrbufferreservepayl_BM (_.prsbufob, nbpredef * 512);
  objstrbufferprintfpayl_BM (_.prsbufob,
                             "#if !defined(HAS_PREDEF_BM) && !defined(HAS_NAMED_PREDEF_BM)\n"
                             "#error missing HAS_PREDEF_BM or HAS_NAMED_PREDEF_BM\n"
                             "#endif\n");
  objstrbufferprintfpayl_BM (_.prsbufob,
                             "#undef BM_NB_PREDEFINED\n"
                             "#define BM_NB_PREDEFINED %u\n\n", nbpredef);
  objstrbufferprintfpayl_BM (_.prsbufob,
                             "#ifdef HAS_PREDEF_BM\n"
                             "//HAS_PREDEF_BM(Id,Hi,Lo,Hash)\n");
  unsigned nbnamed = 0;
  unsigned widthnames = 0;
  for (unsigned pix = 0; pix < nbpredef; pix++)
    {
      _.curpredef = setelemnth_BM (_.prset, pix);
      if (pix % 5 == 0)
        objstrbufferprintfpayl_BM (_.prsbufob, "\n");
      char idbuf[32];
      memset (idbuf, 0, sizeof (idbuf));
      rawid_tyBM curid = objid_BM (_.curpredef);
      idtocbuf32_BM (curid, idbuf);
      objstrbufferprintfpayl_BM (_.prsbufob,
                                 "HAS_PREDEF_BM(%s,%llu,%llu,%lu)", idbuf,
                                 (unsigned long long) curid.id_hi,
                                 (unsigned long long) curid.id_lo,
                                 (unsigned long) hashid_BM (curid));
      const char *n = findobjectname_BM (_.curpredef);
      if (n)
        {
          objstrbufferprintfpayl_BM (_.prsbufob, " /*=%s*/\n", n);
          arrnamed[nbnamed++] = _.curpredef;
          if (widthnames < strlen (n))
            widthnames = strlen (n);
        }
      else
        objstrbufferprintfpayl_BM (_.prsbufob, "\n");
    }
  widthnames = (widthnames | 3) + 1;
  objstrbufferprintfpayl_BM (_.prsbufob, "#undef HAS_PREDEF_BM\n"
                             "#endif /*HAS_PREDEF_BM*/\n");
  objstrbufferprintfpayl_BM (_.prsbufob, "#undef BM_NB_NAMED_PREDEFINED\n"
                             "#define BM_NB_NAMED_PREDEFINED %u\n", nbnamed);
  qsort (arrnamed, nbnamed, sizeof (objectval_tyBM *), cmpnamedpredef_BM);
  for (unsigned nix = 0; nix < nbnamed; nix++)
    {
      _.curpredef = arrnamed[nix];
      if (nix % 5 == 0)
        objstrbufferprintfpayl_BM (_.prsbufob, "\n");
      const char *n = findobjectname_BM (_.curpredef);
      ASSERT_BM (n != NULL);
      char idbuf[32];
      memset (idbuf, 0, sizeof (idbuf));
      rawid_tyBM curid = objid_BM (_.curpredef);
      idtocbuf32_BM (curid, idbuf);
      objstrbufferprintfpayl_BM (_.prsbufob,
                                 "#undef BMP_%s\n#undef BMPNID_%s\n", n, n);
      objstrbufferprintfpayl_BM (_.prsbufob, "#define BMP_%s", n);
      for (int i = widthnames - strlen (n); i > 0; i--)
        objstrbufferappendcstrpayl_BM (_.prsbufob, " ");
      objstrbufferprintfpayl_BM (_.prsbufob, "PREDEF_BM(%s)\n", idbuf);
      objstrbufferprintfpayl_BM (_.prsbufob, "#define BMPNID_%s", n);
      for (int i = widthnames - strlen (n); i > 0; i--)
        objstrbufferappendcstrpayl_BM (_.prsbufob, " ");
      objstrbufferprintfpayl_BM (_.prsbufob, "%s\n", idbuf);
    }
  objstrbufferprintfpayl_BM (_.prsbufob, "\n\n#ifdef HAS_NAMED_PREDEF_BM\n"
                             "//HAS_NAMED_PREDEF_BM(Nam,Id)\n");
  for (unsigned nix = 0; nix < nbnamed; nix++)
    {
      _.curpredef = arrnamed[nix];
      if (nix % 5 == 0)
        objstrbufferprintfpayl_BM (_.prsbufob, "\n");
      const char *n = findobjectname_BM (_.curpredef);
      ASSERT_BM (n != NULL);
      char idbuf[32];
      memset (idbuf, 0, sizeof (idbuf));
      rawid_tyBM curid = objid_BM (_.curpredef);
      idtocbuf32_BM (curid, idbuf);
      objstrbufferprintfpayl_BM (_.prsbufob, "HAS_NAMED_PREDEF_BM(%s,%s)\n",
                                 n, idbuf);
    };
  objstrbufferprintfpayl_BM (_.prsbufob, "\n#undef HAS_NAMED_PREDEF_BM\n"
                             "#endif/*HAS_NAMED_PREDEF_BM*/\n\n");
  objstrbufferprintfpayl_BM (_.prsbufob,
                             "// end of generated predefined file %s\n",
                             basepath);
  char *filpath = NULL;
  if (asprintf (&filpath, "%s/%s", bytstring_BM (duptr->dump_dir), basepath) <
      0 || !filpath)
    FATAL_BM ("asprintf failed for %s", basepath);
  objstrbufferwritetofilepayl_BM (_.prsbufob, filpath);
  objstrbufferresetpayl_BM (_.prsbufob);
  INFOPRINTF_BM ("wrote predefined file %s\n", filpath);
  duptr->dump_wrotefilecount++;
  free (filpath), filpath = NULL;
  LOCALRETURN_BM (_.cclos);
}                               /* end ROUTINE _075tZNHCAMa_7XNNBaNM4qv dumping predefined */



//// for the closure to dump_data the globals, inside dumper_of_globals
extern objrout_sigBM ROUTINEOBJNAME_BM (_4ENXjApm7Qb_3bXo8F6Jg9z);

value_tyBM
ROUTINEOBJNAME_BM (_4ENXjApm7Qb_3bXo8F6Jg9z)
(struct stackframe_stBM * stkf,
const value_tyBM arg1 __attribute__((unused)),
const value_tyBM arg2,
const value_tyBM arg3 __attribute__((unused)),
const value_tyBM arg4 __attribute__((unused)),
const quasinode_tyBM * restargs __attribute__((unused)))
{
  enum
  {
    closix_filnamv,
    closix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 objectval_tyBM * dumpob;
                 objectval_tyBM * sbufob;
                 objectval_tyBM * prsbufob;
                 const stringval_tyBM * filnamv;
                 const node_tyBM * nodglobv;
                 const stringval_tyBM * curglobname;
                 value_tyBM cclosv;
    );
  struct dumper_stBM *duptr = obdumpgetdumper_BM (arg2);
  WEAKASSERT_BM (duptr != NULL);
  LOCALGETFUNV_BM (_.cclosv);
  if (!isclosure_BM (_.cclosv) || closurewidth_BM (_.cclosv) != closix__LAST)
    FATAL_BM
      ("bad closure for _4ENXjApm7Qb_3bXo8F6Jg9z dump_data inside dumper_of_globals");
  _.dumpob = arg2;
  _.prsbufob = makeobj_BM ();
  objputstrbufferpayl_BM (_.prsbufob, 256 * 1024);
  _.filnamv = closurenthson_BM (_.cclosv, closix_filnamv);
  _.nodglobv = nodeglobalnames_BM (BMP_node);
  ASSERT_BM (isstring_BM ((const value_tyBM) _.filnamv));
  const char *basepath = bytstring_BM (_.filnamv);
  objstrbufferprintfpayl_BM (_.prsbufob,
                             "// generated code file for globals %s\n",
                             basepath);
  objstrbufferprintfpayl_BM (_.prsbufob,
                             "// this generated file %s is GPLv3+ licensed\n",
                             basepath);
  {
    time_t nowtim = 0;
    time (&nowtim);
    char nowtimbuf[64];
    memset (nowtimbuf, 0, sizeof (nowtimbuf));
    struct tm nowtm = { };
    gmtime_r (&nowtim, &nowtm);
    strftime (nowtimbuf, sizeof (nowtimbuf), "%Y, %b, %d", &nowtm);
    if (nowtimbuf[0])
      objstrbufferprintfpayl_BM (_.prsbufob,
                                 "// generated in %s\n", nowtimbuf);
  }
  objstrbufferprintfpayl_BM (_.prsbufob,
                             "#ifndef HAS_GLOBAL_BM\n"
                             "#error missing HAS_GLOBAL_BM\n" "#endif\n\n");
  unsigned nbglob = nodewidth_BM ((const value_tyBM) _.nodglobv);
  objstrbufferprintfpayl_BM (_.prsbufob,
                             "#undef BM_NB_GLOBAL\n"
                             "#define BM_NB_GLOBAL %d\n", nbglob);
  for (unsigned gix = 0; gix < nbglob; gix++)
    {
      _.curglobname =           //
        (const stringval_tyBM *) nodenthson_BM ((const value_tyBM) _.nodglobv,
                                                gix);
      ASSERT_BM (isstring_BM ((const value_tyBM) _.curglobname));
      objstrbufferprintfpayl_BM (_.prsbufob, "HAS_GLOBAL_BM(%s)\n",
                                 bytstring_BM (_.curglobname));
    };
  objstrbufferprintfpayl_BM (_.prsbufob, "\n#undef HAS_GLOBAL_BM\n");
  objstrbufferprintfpayl_BM (_.prsbufob, "\n\n"
                             "// end of generated file %s\n", basepath);
  char *filpath = NULL;
  if (asprintf (&filpath, "%s/%s", bytstring_BM (duptr->dump_dir), basepath) <
      0 || !filpath)
    FATAL_BM ("asprintf failed for %s", basepath);
  objstrbufferwritetofilepayl_BM (_.prsbufob, filpath);
  objstrbufferresetpayl_BM (_.prsbufob);
  INFOPRINTF_BM ("wrote globals file %s\n", filpath);
  duptr->dump_wrotefilecount++;
  free (filpath), filpath = NULL;
  LOCALRETURN_BM (_.cclosv);
}                               /* end ROUTINE _4ENXjApm7Qb_3bXo8F6Jg9z dumping globals */


//// for the closure to dump_data the types, inside dumper_of_types
extern objrout_sigBM ROUTINEOBJNAME_BM (_3yJPC4SxGtF_6ilaF37wdxG);

value_tyBM
ROUTINEOBJNAME_BM (_3yJPC4SxGtF_6ilaF37wdxG)    //
(struct stackframe_stBM * stkf, const value_tyBM arg1 __attribute__((unused)), const value_tyBM arg2,   //
 const value_tyBM arg3 __attribute__((unused)), //
 const value_tyBM arg4 __attribute__((unused)), //
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  enum closix_en
  {
    closix_filename,
    closix_tuptypes,
    closix__LAST
  };
  objectval_tyBM *k_c_type = NULL;
  objectval_tyBM *k_emit_c_type = NULL;
  objectval_tyBM *closconn = NULL;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const objectval_tyBM * recv;
                 value_tyBM closv;
                 objectval_tyBM * dumpob;
                 objectval_tyBM * sbufob;
                 objectval_tyBM * prsbufob;
                 const stringval_tyBM * filnamv;
                 const tupleval_tyBM * tuptypes; objectval_tyBM * curtype;
                 value_tyBM emittedv;
    );
  struct dumper_stBM *duptr = obdumpgetdumper_BM (arg2);
  WEAKASSERT_BM (duptr != NULL);
  _.dumpob = arg2;
  LOCALGETFUNV_BM (_.closv);
  WEAKASSERT_BM (closurewidth_BM ((const value_tyBM) _.closv) >=
                 closix__LAST);
  closconn = closureconn_BM ((const value_tyBM) _.closv);
  WEAKASSERT_BM (isobject_BM (closconn));
  k_c_type = BMK_83kM1HtO8K3_6k0F2KYQT3W;
  k_emit_c_type = BMK_0b4VyB0nxvZ_1RgKWePfQOx;
  _.filnamv = closurenthson_BM (_.closv, closix_filename);
  WEAKASSERT_BM (isstring_BM ((const value_tyBM) _.filnamv));
  _.tuptypes =
    tuplecast_BM (closurenthson_BM
                  ((const value_tyBM) _.closv, closix_tuptypes));
  WEAKASSERT_BM (_.tuptypes);
  unsigned nbtypes = tuplesize_BM (_.tuptypes);
  const char *basepath = bytstring_BM (_.filnamv);
  _.prsbufob = makeobj_BM ();
  objputstrbufferpayl_BM (_.prsbufob, 512 * 1024);
  objstrbufferprintfpayl_BM (_.prsbufob,
                             "// generated file for %u types %s\n", nbtypes,
                             basepath);
  objstrbufferprintfpayl_BM (_.prsbufob,
                             "// this generated file is GPLv3+ licensed\n");
  unsigned nbgoodtypes = 0;
  for (unsigned ix = 0; ix < nbtypes; ix++)
    {
      _.curtype = tuplecompnth_BM (_.tuptypes, ix);
      if (objectisinstance_BM (_.curtype, k_c_type))
        {
          DBGPRINTF_BM ("type #%d %s is a good c_type", ix,
                        objectdbg_BM (_.curtype));
          nbgoodtypes++;
        }
      else
        {
          DBGPRINTF_BM ("type #%d %s is not a c_type", ix,
                        objectdbg_BM (_.curtype));
          char idtyp[32];
          memset (idtyp, 0, sizeof (idtyp));
          idtocbuf32_BM (objid_BM (_.curtype), idtyp);
          const char *tynam = findobjectname_BM (_.curtype);
          if (tynam)
            objstrbufferprintfpayl_BM (_.prsbufob,
                                       "#error bad type #%d %s : %s\n", ix,
                                       idtyp, tynam);
          else
            objstrbufferprintfpayl_BM (_.prsbufob, "#error bad type #%d %s\n",
                                       ix, idtyp);
        }
    }
  if (nbgoodtypes != nbtypes)
    {
      WARNPRINTF_BM ("only %u good types out of %u for %s\n",
                     nbgoodtypes, nbtypes, basepath);
      LOCALRETURN_BM (NULL);
    }
  for (unsigned ix = 0; ix < nbtypes; ix++)
    {
      _.curtype = tuplecompnth_BM (_.tuptypes, ix);
      WEAKASSERT_BM (objectisinstance_BM (_.curtype, k_c_type));
      DBGPRINTF_BM ("good type #%d %s is a c_type", ix,
                    objectdbg_BM (_.curtype));
      char idtyp[32];
      memset (idtyp, 0, sizeof (idtyp));
      idtocbuf32_BM (objid_BM (_.curtype), idtyp);
      const char *tynam = findobjectname_BM (_.curtype);
      if (tynam)
        objstrbufferprintfpayl_BM (_.prsbufob, "\n\n"
                                   "// type #%d %s - %s\n", ix, idtyp, tynam);
      else
        objstrbufferprintfpayl_BM (_.prsbufob, "\n\n" "// type #%d %s *\n",
                                   ix, idtyp);
      /// emit the type
      _.emittedv = send2_BM (_.curtype, k_emit_c_type,
                             CURFRAME_BM, _.prsbufob, taggedint_BM (ix));
      if (!_.emittedv)
        {
          DBGPRINTF_BM ("failed to emit_c_type type #%d %s / of class %s", ix,
                        objectdbg_BM (_.curtype),
                        objectdbg1_BM (objclass_BM (_.curtype)));
          objstrbufferprintfpayl_BM (_.prsbufob,
                                     "\n"
                                     "#error emit_c_type failed for %s\n",
                                     idtyp);
          LOCALRETURN_BM (NULL);
        };
      if (tynam)
        objstrbufferprintfpayl_BM (_.prsbufob, "\n"
                                   "// end type #%d %s - %s\n\n", ix, idtyp,
                                   tynam);
      else
        objstrbufferprintfpayl_BM (_.prsbufob, "\n"
                                   "// end type #%d %s *\n\n", ix, idtyp);
      _.emittedv = NULL;
    };
  char *filpath = NULL;
  if (asprintf (&filpath, "%s/%s", bytstring_BM (duptr->dump_dir), basepath) <
      0 || !filpath)
    FATAL_BM ("asprintf failed for %s", basepath);
  objstrbufferwritetofilepayl_BM (_.prsbufob, filpath);
  objstrbufferresetpayl_BM (_.prsbufob);
  INFOPRINTF_BM ("wrote types file %s\n", filpath);
  duptr->dump_wrotefilecount++;
  free (filpath), filpath = NULL;
  LOCALRETURN_BM (_.closv);
}                               /* end of routine _3yJPC4SxGtF_6ilaF37wdxG dumping of ctypes */





////////////////
//// for the method closure to put_method in class
extern objrout_sigBM ROUTINEOBJNAME_BM (_9imDBaAxOpp_2HI9AuWrEKD);

value_tyBM
ROUTINEOBJNAME_BM (_9imDBaAxOpp_2HI9AuWrEKD)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving class
 const value_tyBM arg2,         // new selector
 const value_tyBM arg3,         // new closure
 const value_tyBM arg4 __attribute__((unused)), //
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; objectval_tyBM * obsel;
                 const closure_tyBM * methclo;
    );
  if (!isobject_BM (arg1))
    LOCALRETURN_BM (NULL);
  _.recv = (objectval_tyBM *) arg1;
  if (!isobject_BM (arg2))
    LOCALRETURN_BM (NULL);
  _.obsel = (objectval_tyBM *) arg2;
  if (!isclosure_BM (arg3) && arg3)
    LOCALRETURN_BM (NULL);
  _.methclo = arg3;
  if (!objhasclassinfo_BM (_.recv))
    LOCALRETURN_BM (NULL);
  if (_.methclo)
    objclassinfoputmethod_BM (_.recv, _.obsel, _.methclo);
  else
    objclassinforemovemethod_BM (_.recv, _.obsel);
  objtouchnow_BM (_.recv);
  LOCALRETURN_BM (_.recv);
}                               /* end  ROUTINE _9imDBaAxOpp_2HI9AuWrEKD */

//// for the method closure to init_class in object
extern objrout_sigBM ROUTINEOBJNAME_BM (_2qppG2LJu79_9ljkbLS0eFQ);

value_tyBM
ROUTINEOBJNAME_BM (_2qppG2LJu79_9ljkbLS0eFQ)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving class
 const value_tyBM arg2,         // new superclass
 const value_tyBM arg3 __attribute__((unused)), //
 const value_tyBM arg4 __attribute__((unused)), //
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; objectval_tyBM * obsuperclass;
    );
  if (!isobject_BM (arg1))
    LOCALRETURN_BM (NULL);
  _.recv = (objectval_tyBM *) arg1;
  if (!isobject_BM (arg2))
    LOCALRETURN_BM (NULL);
  _.obsuperclass = (objectval_tyBM *) arg2;
  if (objclass_BM (_.obsuperclass) != BMP_class)
    LOCALRETURN_BM (NULL);
  objputclass_BM (_.recv, BMP_class);
  objputclassinfo_BM (_.recv, _.obsuperclass);
  objtouchnow_BM (_.recv);
  LOCALRETURN_BM (_.recv);
}                               /* end init_class:object _2qppG2LJu79_9ljkbLS0eFQ  */








// for the method to put_data_value°basiclo_function

extern objrout_sigBM ROUTINEOBJNAME_BM (_60NdV04Lel2_5FSZVWKbSL7);
value_tyBM
ROUTINEOBJNAME_BM (_60NdV04Lel2_5FSZVWKbSL7)    // put_data_value°basiclo_function
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving function
 const value_tyBM arg2,         // new value
 const value_tyBM arg3 __attribute__((unused)),
 const value_tyBM arg4 __attribute__((unused)),
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv;
                 value_tyBM nval;
    );
  _.recv = arg1;
  _.nval = arg2;
  ASSERT_BM (isobject_BM (_.recv));
  ASSERT_BM (!objectisinstance_BM (_.recv, BMP_class));
  objputpayload_BM (_.recv, _.nval);
  objtouchnow_BM (_.recv);
  LOCALRETURN_BM (_.recv);
}                               /* end  put_data_value°basiclo_function _60NdV04Lel2_5FSZVWKbSL7 */







// for the const function (returning first closed value)

extern objrout_sigBM ROUTINEOBJNAME_BM (_5DDSY1YgVZr_6dOU4tiBldk);
value_tyBM
ROUTINEOBJNAME_BM (_5DDSY1YgVZr_6dOU4tiBldk)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1 __attribute__((unused)),
 const value_tyBM arg2 __attribute__((unused)),
 const value_tyBM arg3 __attribute__((unused)),
 const value_tyBM arg4 __attribute__((unused)),
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  enum
  { closix_constant,
    closix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM cclos;
    );
  LOCALGETFUNV_BM (_.cclos);
  if (!isclosure_BM (_.cclos) || closurewidth_BM (_.cclos) != closix__LAST)
    return NULL;
  LOCALRETURN_BM (closurenthson_BM
                  ((const value_tyBM) _.cclos, closix_constant));
}                               /* end ROUTINE _5DDSY1YgVZr_6dOU4tiBldk const */


// for the routine to dump_data a plain_dumpable_module
extern objrout_sigBM ROUTINEOBJNAME_BM (_5DyG7xVcxRI_1Ckpbj7b3QK);

value_tyBM
ROUTINEOBJNAME_BM (_5DyG7xVcxRI_1Ckpbj7b3QK)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving module
 const value_tyBM arg2,         // dumper
 const value_tyBM arg3,         // dump strbuf
 const value_tyBM arg4 __attribute__((unused)),
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL, objectval_tyBM * obmod;
                 objectval_tyBM * dumpob;
                 objectval_tyBM * bufob; value_tyBM res;
                 value_tyBM failreason; //
                 value_tyBM failplace;  //
    );
  ASSERT_BM (isobject_BM (arg1));
  _.obmod = arg1;
  WEAKASSERT_BM (obdumpgetdumper_BM (arg2) != NULL);
  _.dumpob = arg2;
  WEAKASSERT_BM (objhasstrbufferpayl_BM ((objectval_tyBM *) arg3));
  _.bufob = objectcast_BM (arg3);
  DBGPRINTF_BM
    ("@@dump_data°plain_dumpable_module obmod=%s\n****++++++++++++++++\n",
     objectdbg_BM (_.obmod));
  struct failurehandler_stBM *prevfailureh =
    (struct failurehandler_stBM *) curfailurehandle_BM;
  int failcod = 0;
  _.failreason = NULL;
  _.failplace = NULL;
  INFOPRINTF_BM
    ("dump_data°plain_dumpable_module start dumping module %s, with dumpob %s and bufob %s\n",
     objectdbg_BM (_.obmod), objectdbg1_BM (_.dumpob),
     objectdbg2_BM (_.bufob));
  struct failurelockset_stBM flockset = {
  };
  initialize_failurelockset_BM (&flockset, sizeof (flockset));
  LOCAL_FAILURE_HANDLE_BM (&flockset, lab_failuremodule, failcod,
                           _.failreason, _.failplace);
  _.res = send0_BM (_.obmod, BMP_emit_module, CURFRAME_BM);
  DBGPRINTF_BM ("@@dump_data°plain_dumpable_module emit_module succeess obmod %s res %s",      //
                objectdbg_BM (_.obmod), //
                debug_outstr_value_BM (_.res, CURFRAME_BM, 1));
  /// this won't be reached on failure; 
  destroy_failurelockset_BM (&flockset);
  curfailurehandle_BM = prevfailureh;
  DBGPRINTF_BM ("@@dump_data°plain_dumpable_module obmod %s failcod %d failreason %s res %s",  //
                objectdbg_BM (_.obmod), failcod,        //
                debug_outstr_value_BM (_.failreason, CURFRAME_BM, 1),   //
                debug_outstr_value_BM (_.res, CURFRAME_BM, 1));
  if (failcod > 0)
    // this is only reached by the label, with an internal goto in LOCAL_FAILURE_HANDLE_BM macro
  lab_failuremodule:{
      char idbuf[32];
      memset (idbuf, 0, sizeof (idbuf));
      idtocbuf32_BM (objid_BM (_.obmod), idbuf);
      objstrbufferprintfpayl_BM (_.bufob, "\n#error fail to emit module %s\n",
                                 idbuf);
      destroy_failurelockset_BM (&flockset);
      curfailurehandle_BM = prevfailureh;
      DBGPRINTF_BM ("@@dump_data°plain_dumpable_module failed obmod=%s failcod=%d failreason %s\n" "failplace %s\n" "****!!!!!!\n",    //
                    objectdbg_BM (_.obmod), failcod,    //
                    OUTSTRVALUE_BM (_.failreason),
                    OUTSTRVALUE_BM (_.failplace));
      LOCALRETURN_BM (NULL);
    }
  else if (_.res)
    {
      char idbuf[32];
      memset (idbuf, 0, sizeof (idbuf));
      idtocbuf32_BM (objid_BM (_.obmod), idbuf);
      objstrbufferprintfpayl_BM (_.bufob,
                                 "\n// emitted persistent module "
                                 MODULEPREFIX_BM "%s.c\n", idbuf);
      DBGPRINTF_BM
        ("@@dump_data°plain_dumpable_module emitted obmod=%s\n****----------------\n",
         objectdbg_BM (_.obmod));
    }
  LOCALRETURN_BM (_.res);

}                               /* end dump_data°plain_dumpable_module ROUTINE _5DyG7xVcxRI_1Ckpbj7b3QK */





/******************* command readmacros ***************/

// for the routine command_readmacro for block
extern objrout_sigBM ROUTINEOBJNAME_BM (_0kUyX0U19K2_5mcH4RCaBl9);

value_tyBM
ROUTINEOBJNAME_BM (_0kUyX0U19K2_5mcH4RCaBl9)    // block:readmacro
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const value_tyBM arg4,         // parsob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const node_tyBM * rnodv; objectval_tyBM * resobj;
                 objectval_tyBM * resclass; objectval_tyBM * curlab;
                 objectval_tyBM * parsob; value_tyBM curson;
                 value_tyBM inv;
    );
  objectval_tyBM *k_basiclo_block = NULL;
  objectval_tyBM *k_label = NULL;
  if (!isnode_BM (arg1))
    LOCALRETURN_BM (NULL);
  _.rnodv = arg1;
  k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  k_label = BMK_3XBrePAliOo_37VlAqBsb5C;
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  _.parsob = objectcast_BM (arg4);
  WEAKASSERT_BM (istaggedint_BM (arg2));
  WEAKASSERT_BM (istaggedint_BM (arg3));
  WEAKASSERT_BM (_.parsob);
  unsigned startix = 0;
  struct parser_stBM *pars = objparserpayload_BM (_.parsob);
  WEAKASSERT_BM (pars != NULL);
  unsigned nodwidth = nodewidth_BM ((value_tyBM) _.rnodv);
  _.resobj = NULL;
  DBGPRINTF_BM ("start readmacro:block"
                " lineno=%d colpos=%d nodwidth=%u", lineno, colpos, nodwidth);
  if (nodwidth > 0
      && (_.curson =
          nodenthson_BM ((const value_tyBM) _.rnodv, startix)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object `in` for block readmacro");
          LOCALRETURN_BM (NULL);
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
          parsererrorprintf_BM (pars,
                                CURFRAME_BM, lineno,
                                colpos,
                                "non-object `label` for block readmacro");
          LOCALRETURN_BM (NULL);
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
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object #%d comp for block readmacro",
                                  ix);
          LOCALRETURN_BM (NULL);
        }
    }
  objlock_BM (_.resobj);
  objresetcomps_BM (_.resobj, nodwidth - startix);
  objresetattrs_BM (_.resobj, 5);
  //objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  if (_.curlab)
    objputattr_BM (_.resobj, k_label, (const value_tyBM) _.curlab);
  for (unsigned ix = startix; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      objappendcomp_BM (_.resobj, _.curson);
    }
  objputclass_BM (_.resobj, _.resclass);
  objtouchnow_BM (_.resobj);
  objunlock_BM (_.resobj);
  LOCALRETURN_BM (_.resobj);
}                               /* end ROUTINE _0kUyX0U19K2_5mcH4RCaBl9 block:readmacro */


////////////////

// fail:read_macro _2NRUP36YT80_0SdozCZxyvv
extern objrout_sigBM ROUTINEOBJNAME_BM (_2NRUP36YT80_0SdozCZxyvv);

value_tyBM
ROUTINEOBJNAME_BM (_2NRUP36YT80_0SdozCZxyvv)    // fail:readmacro
(struct stackframe_stBM * stkf, //
 const value_tyBM nodarg,       //
 const value_tyBM linenoarg,    //
 const value_tyBM colposarg,    //
 const value_tyBM parsobarg,    //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_basiclo_fail = BMK_4UklN1FKPMy_43NQnifo7Mn;
  objectval_tyBM *k_fail = BMK_085lT8c13Ik_11pcWJfcLeM;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_2NRUP36YT80_0SdozCZxyvv,
                 const node_tyBM * rnodv;       //
                 objectval_tyBM * resob;        //
                 objectval_tyBM * parsob;       //
                 objectval_tyBM * classob;      //
                 value_tyBM resultv;    //
                 value_tyBM cursonv;    //
                 value_tyBM inv;        //
                 value_tyBM failexpv;   //
    );
  _.rnodv = nodarg;
  if (!isnode_BM (nodarg))
    LOCALRETURN_BM (NULL);
  int lineno = getint_BM (linenoarg);
  int colpos = getint_BM (colposarg);
  unsigned nodwidth = nodewidth_BM ((value_tyBM) _.rnodv);
  unsigned startix = 0;
  if (!isobject_BM (parsobarg))
    LOCALRETURN_BM (NULL);
  _.parsob = (objectval_tyBM *) parsobarg;
  struct parser_stBM *pars = objparserpayload_BM (_.parsob);
  if (!pars)
    LOCALRETURN_BM (NULL);
  if (nodwidth > 0
      && (_.cursonv = nodenthson_BM ((const value_tyBM) _.rnodv, 0)) != NULL
      && isnode_BM (_.cursonv) && nodeconn_BM (_.cursonv) == BMP_in)
    {
      _.inv = nodenthson_BM (_.cursonv, 0);
      if (!isobject_BM (_.inv))
        {
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object `in` for lockobj readmacro");
          LOCALRETURN_BM (NULL);
        }
      _.resob = _.inv;
      if (objectisinstance_BM (_.resob, k_basiclo_fail))
        _.classob = objclass_BM (_.resob);
      startix = 1;
    }
  else
    {
      startix = 0;
      _.resob = makeobj_BM ();
      objputspacenum_BM (_.resob, GlobalSp_BM);
    };

  if (startix + 1 > nodwidth)
    {
      if (pars)
        parsererrorprintf_BM (pars,
                              CURFRAME_BM, lineno,
                              colpos,
                              "missing failure expression for fail readmacro (startix=%u nodwidth=%u)",
                              startix, nodwidth);
      LOCALRETURN_BM (NULL);
    }
  _.failexpv = nodenthson_BM ((const value_tyBM) _.rnodv, startix);
  if (startix + 1 < nodwidth - 1 && pars)
    parsererrorprintf_BM (pars,
                          CURFRAME_BM, lineno,
                          colpos,
                          "fail readmacro should have one failure-expression argument (startix=%u nodwidth=%u)",
                          startix, nodwidth);

  if (!_.classob)
    _.classob = k_basiclo_fail;
  objlock_BM (_.resob);
  objresetcomps_BM (_.resob, 2);
  objresetattrs_BM (_.resob, 5);
  objputclass_BM (_.resob, _.classob);
  objputattr_BM (_.resob, k_fail, _.failexpv);
  objtouchnow_BM (_.resob);
  objunlock_BM (_.resob);
  DBGPRINTF_BM ("end fail:readmacro resobj %s", objectdbg_BM (_.resob));
  LOCALRETURN_BM (_.resob);
}                               /* end fail:readmacro _2NRUP36YT80_0SdozCZxyvv */


////////////////
// lockobj:readmacro _9QfwVBwmu2L_4mgyQ8AEwdt2
extern objrout_sigBM ROUTINEOBJNAME_BM (_9QfwVBwmu2L_4mgyQ8AEwdt);

value_tyBM
ROUTINEOBJNAME_BM (_9QfwVBwmu2L_4mgyQ8AEwdt)    //lockobj:readmacro
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const value_tyBM arg4,         //  parsob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_basiclo_lockobj = BMK_5w3nODhHPwk_4sXXZ1AEOPq;
  objectval_tyBM *k_lockobj = BMK_9dso3pFLYwm_3JwHqiJK3UL;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_9QfwVBwmu2L_4mgyQ8AEwdt,
                 const node_tyBM * rnodv;       //
                 objectval_tyBM * parsob;       //
                 objectval_tyBM * resob;        //
                 objectval_tyBM * classob;      //
                 objectval_tyBM * curob;        //
                 value_tyBM inv;        //
                 value_tyBM lockobexpv; //
                 value_tyBM destv;      //
                 value_tyBM resultv;    //
                 value_tyBM cursonv;    //
    );
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    LOCALRETURN_BM (NULL);
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  unsigned nodwidth = nodewidth_BM ((value_tyBM) _.rnodv);
  unsigned startix = 0;
  if (!isobject_BM (arg4))
    LOCALRETURN_BM (NULL);
  _.parsob = arg4;
  struct parser_stBM *pars = objparserpayload_BM (_.parsob);
  if (!pars)
    LOCALRETURN_BM (NULL);
  if (nodwidth > 0
      && (_.cursonv = nodenthson_BM ((const value_tyBM) _.rnodv, 0)) != NULL
      && isnode_BM (_.cursonv) && nodeconn_BM (_.cursonv) == BMP_in)
    {
      _.inv = nodenthson_BM (_.cursonv, 0);
      if (!isobject_BM (_.inv))
        {
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object `in` for lockobj readmacro");
          LOCALRETURN_BM (NULL);
        }
      _.resob = _.inv;
      if (objectisinstance_BM (_.resob, k_basiclo_lockobj))
        _.classob = objclass_BM (_.resob);
      startix = 1;
    }
  else
    startix = 0;
  if (startix + 1 >= nodwidth)
    {
      if (pars)
        parsererrorprintf_BM (pars,
                              CURFRAME_BM, lineno,
                              colpos,
                              "missing object expression for lockobj readmacro");
      LOCALRETURN_BM (NULL);
    }
  _.lockobexpv = nodenthson_BM ((const value_tyBM) _.rnodv, startix);
  for (int ix = startix + 1; ix < (int) nodwidth; ix++)
    {
      _.curob =
        objectcast_BM (nodenthson_BM ((const value_tyBM) _.rnodv, ix));
      if (!_.curob)
        {
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non object son #%d for lockobj readmacro",
                                  ix);
          LOCALRETURN_BM (NULL);
        }
    }
  if (!_.classob)
    _.classob = k_basiclo_lockobj;
  if (!_.resob)
    {
      _.resob = makeobj_BM ();
      objputclass_BM (_.resob, _.classob);
      objputspacenum_BM (_.resob, GlobalSp_BM);
    }
  WEAKASSERT_BM (_.resob != NULL);
  objlock_BM (_.resob);
  objreservecomps_BM (_.resob, nodwidth - startix);
  objputattr_BM (_.resob, k_lockobj, _.lockobexpv);
  for (int ix = startix + 1; ix < (int) nodwidth; ix++)
    {
      _.curob =
        objectcast_BM (nodenthson_BM ((const value_tyBM) _.rnodv, ix));
      WEAKASSERT_BM (_.curob != NULL);
      objappendcomp_BM (_.resob, _.curob);
    }
  objunlock_BM (_.resob);
  DBGPRINTF_BM ("lockobj:readmacro L%dC%d gives resob=%s", lineno, colpos,
                objectdbg_BM (_.resob));
  LOCALRETURN_BM (_.resob);
}                               /* end lockobj:readmacro _9QfwVBwmu2L_4mgyQ8AEwdt */




////////////////

// for the routine command_readmacro for assign
extern objrout_sigBM ROUTINEOBJNAME_BM (_1Geqz0vsOKB_2Dpdb1LDu23);

value_tyBM
ROUTINEOBJNAME_BM (_1Geqz0vsOKB_2Dpdb1LDu23)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const value_tyBM arg4,         //  parsob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const node_tyBM * rnodv;       //
                 objectval_tyBM * resobj;       // 
                 objectval_tyBM * parsob;       //
                 value_tyBM inv;        //
                 value_tyBM destv;      //
                 value_tyBM srcv;       //
                 value_tyBM curson;     //
    );
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    LOCALRETURN_BM (NULL);
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  unsigned nodwidth = nodewidth_BM ((value_tyBM) _.rnodv);
  if (!isobject_BM (arg4))
    LOCALRETURN_BM (NULL);
  _.parsob = arg4;
  struct parser_stBM *pars = objparserpayload_BM (_.parsob);
  if (!pars)
    LOCALRETURN_BM (NULL);
  const objectval_tyBM *k_basiclo_assign = BMK_3HIw09Tmj0d_3CrcFHrGJab;
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
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object `in` for assign readmacro");
          LOCALRETURN_BM (NULL);
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
      if (pars)
        parsererrorprintf_BM (pars,
                              CURFRAME_BM, lineno, colpos,
                              "assign readmacro wants two arguments");
      LOCALRETURN_BM (NULL);
    }
  _.destv = nodenthson_BM ((const value_tyBM) _.rnodv, startix);
  _.srcv = nodenthson_BM ((const value_tyBM) _.rnodv, startix + 1);
  if (!isobject_BM (_.destv))
    {
      if (pars)
        parsererrorprintf_BM (pars,
                              CURFRAME_BM, lineno, colpos,
                              "assign readmacro wants object as src");
      LOCALRETURN_BM (NULL);
    }
  objlock_BM (_.resobj);
  objresetcomps_BM (_.resobj, 2);
  objresetattrs_BM (_.resobj, 5);
  //objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  objappendcomp_BM (_.resobj, _.destv);
  objappendcomp_BM (_.resobj, _.srcv);
  objputclass_BM (_.resobj, (objectval_tyBM *) k_basiclo_assign);
  objtouchnow_BM (_.resobj);
  objunlock_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:assign resobj %s", objectdbg_BM (_.resobj));
  LOCALRETURN_BM (_.resobj);
}                               /* end ROUTINE _1Geqz0vsOKB_2Dpdb1LDu23 assign:readmacro */

////////////////

// for the routine command_readmacro for cond
extern objrout_sigBM ROUTINEOBJNAME_BM (_0XbMOJqLLPZ_1t2wg2TwPRA);

value_tyBM
ROUTINEOBJNAME_BM (_0XbMOJqLLPZ_1t2wg2TwPRA)    // readmacro#cond
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const value_tyBM arg4,         // parsob
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const node_tyBM * rnodv;
                 objectval_tyBM * resobj; const struct parser_stBM *pars;
                 value_tyBM inv; value_tyBM destv;
                 value_tyBM srcv;
                 objectval_tyBM * parsob;
                 union
                 {
                 value_tyBM curson; objectval_tyBM * curobj;
                 };
                 objectval_tyBM * prevobj;
    );
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    LOCALRETURN_BM (NULL);
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  DBGPRINTF_BM ("start readmacro:cond _0XbMOJqLLPZ_1t2wg2TwPRA"
                " lineno=%d colpos=%d nodwidth=%u", lineno, colpos, nodwidth);
  if (!isnode_BM (arg1))
    LOCALRETURN_BM (NULL);
  _.rnodv = arg1;
  if (!isobject_BM (arg4))
    LOCALRETURN_BM (NULL);
  _.parsob = arg4;
  struct parser_stBM *pars = objparserpayload_BM (_.parsob);
  if (!pars)
    LOCALRETURN_BM (NULL);
  objectval_tyBM *k_basiclo_cond = BMK_0eCRnBKQ0eQ_1atum3gUgEz;
  objectval_tyBM *k_basiclo_when = BMK_3fvdRZNCmJS_5bTAPr83mXg;
  objectval_tyBM *k_nb_conds = BMK_8dLpuaNoSGN_2tdmkpINCsu;
  unsigned startix = 0;
  _.resobj = NULL;
  if (nodwidth > 0
      && (_.curson = nodenthson_BM ((const value_tyBM) _.rnodv, 0)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object `in` for cond readmacro");
          LOCALRETURN_BM (NULL);
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
  int nbconds = 0;
  for (unsigned ix = startix; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      if (!isobject_BM (_.curson))
        {
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object arg#%d for cond readmacro", ix);
          LOCALRETURN_BM (NULL);
        }
      if (objectisinstance_BM ((objectval_tyBM *) _.curson, k_basiclo_when))
        {
          if (ix > startix
              &&
              !objectisinstance_BM (objectcast_BM
                                    (nodenthson_BM
                                     ((const value_tyBM) _.rnodv, ix - 1)),
                                    k_basiclo_when))
            {
              if (pars)
                parsererrorprintf_BM (pars,
                                      CURFRAME_BM, lineno,
                                      colpos,
                                      "non-consecutive when %s arg#%d for cond readmacro",
                                      objectdbg_BM ((objectval_tyBM *)
                                                    _.curson), ix);
              LOCALRETURN_BM (NULL);
            };
          nbconds++;
        };
    }
  objlock_BM (_.resobj);
  objresetcomps_BM (_.resobj, nodwidth - startix);
  objresetattrs_BM (_.resobj, 5);
  //objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  for (unsigned ix = startix; ix < nodwidth; ix++)
    {
      _.curobj =
        objectcast_BM (nodenthson_BM ((const value_tyBM) _.rnodv, ix));
      objappendcomp_BM (_.resobj, _.curobj);
    }
  objputclass_BM (_.resobj, k_basiclo_cond);
  objputattr_BM (_.resobj, k_nb_conds, taggedint_BM (nbconds));
  objtouchnow_BM (_.resobj);
  objunlock_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:cond resobj %s", objectdbg_BM (_.resobj));
  LOCALRETURN_BM (_.resobj);
}                               /* end ROUTINE _0XbMOJqLLPZ_1t2wg2TwPRA cond:readmacro */


// readmacro#wrong _5ZT4G2KhMyi_4mC2iDVPWQP

extern objrout_sigBM ROUTINEOBJNAME_BM (_5ZT4G2KhMyi_4mC2iDVPWQP);

value_tyBM
ROUTINEOBJNAME_BM (_5ZT4G2KhMyi_4mC2iDVPWQP)    //readmacro#wrong 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // node 
 const value_tyBM arg2,         // lineo
 const value_tyBM arg3,         // colpos
 const value_tyBM arg4,         // parsob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_basiclo_wrong = BMK_65wIF6z9pmQ_47VZsHJ6zdk;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_5ZT4G2KhMyi_4mC2iDVPWQP,
                 value_tyBM nodev;
                 objectval_tyBM * parsob; objectval_tyBM * resob;
                 value_tyBM cursonv;
                 value_tyBM inv;
    );
  _.nodev = (value_tyBM) nodecast_BM (arg1);
  if (!isnode_BM (_.nodev))
    LOCALRETURN_BM (NULL);
  WEAKASSERT_BM (istaggedint_BM (arg2));
  int lineno = getint_BM (arg2);
  WEAKASSERT_BM (istaggedint_BM (arg3));
  int colpos = getint_BM (arg3);
  _.parsob = objectcast_BM (arg4);
  WEAKASSERT_BM (_.parsob);
  struct parser_stBM *pars = objparserpayload_BM (_.parsob);
  if (!pars)
    LOCALRETURN_BM (NULL);
  unsigned startix = 0;
  _.resob = NULL;
  unsigned nodwidth = nodewidth_BM (_.nodev);
  if (nodwidth > 0
      && (_.cursonv = nodenthson_BM ((const value_tyBM) _.nodev, 0)) != NULL
      && isnode_BM (_.cursonv) && nodeconn_BM (_.cursonv) == BMP_in)
    {
      _.inv = nodenthson_BM (_.cursonv, 0);
      if (!isobject_BM (_.inv))
        {
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object `in` for ^wrong readmacro");
          LOCALRETURN_BM (NULL);
        }
      _.resob = (objectval_tyBM *) _.inv;
      startix = 1;
    }
  else
    {
      startix = 0;
      _.resob = makeobj_BM ();
      objputspacenum_BM (_.resob, GlobalSp_BM);
    };
  objlock_BM (_.resob);
  if (!objectisinstance_BM (_.resob, k_basiclo_wrong))
    objputclass_BM (_.resob, k_basiclo_wrong);
  objresetattrs_BM (_.resob, 5);
  objresetcomps_BM (_.resob, nodwidth - startix);
  //objputattr_BM (_.resob, BMP_origin, (const value_tyBM) _.nodev);
  for (unsigned ix = startix; ix < nodwidth; ix++)
    objappendcomp_BM (_.resob, nodenthson_BM (_.nodev, ix));
  objunlock_BM (_.resob);
  LOCALRETURN_BM (_.resob);
}                               /* end readmacro#wrong  _5ZT4G2KhMyi_4mC2iDVPWQP */



////////////////

// for the routine command_readmacro for intswitch
extern objrout_sigBM ROUTINEOBJNAME_BM (_7ko2VZaPpqD_1eEmEcp0VV3);

value_tyBM
ROUTINEOBJNAME_BM (_7ko2VZaPpqD_1eEmEcp0VV3)    // readmacro#intswitch
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const value_tyBM arg4,         // parsob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const node_tyBM * rnodv;       //
                 objectval_tyBM * parsob;       //
                 objectval_tyBM * resobj;       //
                 objectval_tyBM * classob;      //
                 objectval_tyBM * closconn;     //
                 value_tyBM curson;     //
                 value_tyBM inv;        //
    );
  objectval_tyBM *k_basiclo_intswitch = BMK_12QTszi1FF0_5S77twbSETI;
  objectval_tyBM *k_switch = BMK_5PJV21P82kA_2KfQTz95vdH;
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    LOCALRETURN_BM (NULL);
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  if (!isobject_BM (arg4))
    LOCALRETURN_BM (NULL);
  _.parsob = arg4;
  struct parser_stBM *pars = objparserpayload_BM (_.parsob);
  if (!pars)
    LOCALRETURN_BM (NULL);
  _.resobj = NULL;
  DBGPRINTF_BM ("start readmacro:intswitch  "
                " lineno=%d colpos=%d rnod %s", lineno, colpos,
                debug_outstr_value_BM ((value_tyBM) _.rnodv, CURFRAME_BM, 0));
  unsigned startix = 0;
  _.resobj = NULL;
  if (nodwidth > 0
      && (_.curson = nodenthson_BM ((const value_tyBM) _.rnodv, 0)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object `in` for intswitch readmacro");
          LOCALRETURN_BM (NULL);
        }
      _.resobj = _.inv;
      if (objectisinstance_BM (_.resobj, k_basiclo_intswitch))
        _.classob = objclass_BM (_.resobj);
      else
        _.classob = k_basiclo_intswitch;
      startix = 1;
    }
  else
    {
      startix = 0;
      _.resobj = makeobj_BM ();
      _.classob = k_basiclo_intswitch;
      objputspacenum_BM (_.resobj, GlobalSp_BM);
    };
  for (unsigned ix = startix; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      if (!isobject_BM (_.curson) && ix > startix)
        {
          parsererrorprintf_BM (pars,
                                CURFRAME_BM, lineno,
                                colpos,
                                "non-object arg#%d for intswitch readmacro",
                                ix);
          LOCALRETURN_BM (NULL);
        }
    }
  if (!_.classob)
    _.classob = k_basiclo_intswitch;
  objlock_BM (_.resobj);
  objresetcomps_BM (_.resobj, nodwidth - startix);
  objresetattrs_BM (_.resobj, 5);
  objputclass_BM (_.resobj, _.classob);
  //objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  objputattr_BM (_.resobj, k_switch,
                 nodenthson_BM ((const value_tyBM) _.rnodv, startix));
  for (unsigned ix = startix + 1; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      objappendcomp_BM (_.resobj, _.curson);
    }
  objputclass_BM (_.resobj, k_basiclo_intswitch);
  objtouchnow_BM (_.resobj);
  objunlock_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:intswitch L%dC%d resobj %s", lineno, colpos,
                objectdbg_BM (_.resobj));
  LOCALRETURN_BM (_.resobj);
}                               /* end ROUTINE  _7ko2VZaPpqD_1eEmEcp0VV3 intswitch:readmacro */



/////

// for the routine command_readmacro for objswitch
extern objrout_sigBM ROUTINEOBJNAME_BM (_8uFPIAUyvE6_36pUIgGwmbf);

value_tyBM
ROUTINEOBJNAME_BM (_8uFPIAUyvE6_36pUIgGwmbf)    // objswitch:readmacro
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const value_tyBM arg4,         // parsob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const node_tyBM * rnodv;
                 objectval_tyBM * resobj;       //
                 objectval_tyBM * parsob;       //
                 objectval_tyBM * classob;      //
                 value_tyBM curson;
                 value_tyBM inv;
    );
  objectval_tyBM *k_basiclo_objswitch = BMK_3votvybaW1d_35YcL4p51kp;
  objectval_tyBM *k_switch = BMK_5PJV21P82kA_2KfQTz95vdH;
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    LOCALRETURN_BM (NULL);
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  _.resobj = NULL;
  if (!isobject_BM (arg4))
    LOCALRETURN_BM (NULL);
  _.parsob = arg4;
  struct parser_stBM *pars = objparserpayload_BM (_.parsob);
  if (!pars)
    LOCALRETURN_BM (NULL);
  k_basiclo_objswitch = BMK_3votvybaW1d_35YcL4p51kp;
  DBGPRINTF_BM ("start readmacro:objswitch "
                " lineno=%d colpos=%d rnod=%s", lineno, colpos,
                debug_outstr_value_BM ((value_tyBM) _.rnodv, CURFRAME_BM, 0));
  unsigned startix = 0;
  _.resobj = NULL;
  if (nodwidth > 0
      && (_.curson = nodenthson_BM ((const value_tyBM) _.rnodv, 0)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object `in` for objswitch readmacro");
          LOCALRETURN_BM (NULL);
        }
      _.resobj = _.inv;
      if (objectisinstance_BM (_.resobj, k_basiclo_objswitch))
        _.classob = objclass_BM (_.resobj);
      else
        _.classob = k_basiclo_objswitch;
      startix = 1;
    }
  else
    {
      startix = 0;
      _.resobj = makeobj_BM ();
      _.classob = k_basiclo_objswitch;
      objputspacenum_BM (_.resobj, GlobalSp_BM);
    };
  for (unsigned ix = startix; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      if (!isobject_BM (_.curson) && ix > startix)
        {
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object arg#%d for objswitch readmacro",
                                  ix);
          LOCALRETURN_BM (NULL);
        }
    }
  if (!_.classob)
    _.classob = k_basiclo_objswitch;
  objlock_BM (_.resobj);
  objresetcomps_BM (_.resobj, nodwidth - startix);
  objresetattrs_BM (_.resobj, 5);
  objputclass_BM (_.resobj, _.classob);
  //objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  objputattr_BM (_.resobj, k_switch,
                 (value_tyBM) nodenthson_BM ((value_tyBM) _.rnodv, startix));
  for (unsigned ix = startix + 1; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      objappendcomp_BM (_.resobj, _.curson);
    }
  objputclass_BM (_.resobj, _.classob);
  objtouchnow_BM (_.resobj);
  objunlock_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:objswitch resobj %s", objectdbg_BM (_.resobj));
  LOCALRETURN_BM (_.resobj);
}                               /* end ROUTINE  _8uFPIAUyvE6_36pUIgGwmbf objswitch:readmacro */


/////

// for the routine command_readmacro for loop
extern objrout_sigBM ROUTINEOBJNAME_BM (_6SUnsQrN1BV_1WnLPm4QoOq);

value_tyBM
ROUTINEOBJNAME_BM (_6SUnsQrN1BV_1WnLPm4QoOq)    // loop:readmacro
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const value_tyBM arg4,         // parsob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const node_tyBM * rnodv;
                 value_tyBM curson; objectval_tyBM * resobj;
                 objectval_tyBM * resclass; objectval_tyBM * curlab;
                 objectval_tyBM * inv; objectval_tyBM * parsob;
    );
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    LOCALRETURN_BM (NULL);
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  if (!isobject_BM (arg4))
    LOCALRETURN_BM (NULL);
  _.parsob = arg4;
  struct parser_stBM *pars = objparserpayload_BM (_.parsob);
  if (!pars)
    LOCALRETURN_BM (NULL);
  const objectval_tyBM *k_basiclo_loop = BMK_2EjH1ebLzli_4rmA1ZPtIBL;
  const objectval_tyBM *k_label = BMK_3XBrePAliOo_37VlAqBsb5C;
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  DBGPRINTF_BM ("start readmacro:loop "
                " lineno=%d colpos=%d nodwidth=%u rnod %s", lineno, colpos,
                nodwidth, debug_outstr_value_BM ((value_tyBM) _.rnodv,
                                                 CURFRAME_BM, 0));
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
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object `in` for loop readmacro");
          LOCALRETURN_BM (NULL);
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
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object `label` for loop readmacro");
          LOCALRETURN_BM (NULL);
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
  DBGPRINTF_BM ("readmacro:loop L%dC%d resobj %s", lineno, colpos,
                objectdbg_BM (_.resobj));
  for (unsigned ix = startix; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      if (!isobject_BM (_.curson))
        {
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object #%d comp for loop readmacro",
                                  ix);
          LOCALRETURN_BM (NULL);
        }
    }
  objlock_BM (_.resobj);
  objresetcomps_BM (_.resobj, nodwidth - startix);
  objresetattrs_BM (_.resobj, 5);
  //objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  if (_.curlab)
    objputattr_BM (_.resobj, k_label, (const value_tyBM) _.curlab);
  for (unsigned ix = startix; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      objappendcomp_BM (_.resobj, _.curson);
    }
  objputclass_BM (_.resobj, _.resclass);
  objtouchnow_BM (_.resobj);
  objunlock_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:loop resobj %s", objectdbg_BM (_.resobj));
  LOCALRETURN_BM (_.resobj);
}                               /* end loop:readmacro  _6SUnsQrN1BV_1WnLPm4QoOq  */




/////

// for the routine command_readmacro for exit
extern objrout_sigBM ROUTINEOBJNAME_BM (_63Q0R4r8xa7_7XOAxxP5pi2);

value_tyBM
ROUTINEOBJNAME_BM (_63Q0R4r8xa7_7XOAxxP5pi2)    // exit:readmacro
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const value_tyBM arg4,         // parsob
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const node_tyBM * rnodv;       //
                 objectval_tyBM * parsob;       //
                 objectval_tyBM * resobj;       //
                 objectval_tyBM * resclass;     //
                 value_tyBM exitv;      //
                 value_tyBM curson;     //
                 value_tyBM inv;        //
    );
  objectval_tyBM *k_basiclo_exit = BMK_0Yis1n6EoBu_8nfbe8a8yKI;
  objectval_tyBM *k_exit = BMK_41gbFesxqzD_3l56OLiNdl2;
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    LOCALRETURN_BM (NULL);
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  if (!isobject_BM (arg4))
    LOCALRETURN_BM (NULL);
  _.parsob = arg4;
  struct parser_stBM *pars = objparserpayload_BM (_.parsob);
  if (!pars)
    LOCALRETURN_BM (NULL);
  _.resobj = NULL;
  DBGPRINTF_BM ("start readmacro:exit "
                " lineno=%d colpos=%d nodwidth=%u rnodv=%s", lineno, colpos,
                nodwidth, debug_outstr_value_BM ((value_tyBM) _.rnodv,
                                                 CURFRAME_BM, 0));
  unsigned startix = 0;
  if (nodwidth > 0
      && (_.curson =
          nodenthson_BM ((const value_tyBM) _.rnodv, startix)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object `in` for exit readmacro");
          LOCALRETURN_BM (NULL);
        }
      _.resobj = _.inv;
      if (objectisinstance_BM (_.resobj, k_basiclo_exit))
        _.resclass = objclass_BM (_.resobj);
      else
        _.resclass = k_basiclo_exit;
      startix++;
    }
  else
    _.resclass = k_basiclo_exit;
  if (nodwidth >= startix + 1)
    _.exitv = nodenthson_BM ((const value_tyBM) _.rnodv, startix);
  DBGPRINTF_BM ("readmacro:exit "
                " lineno=%d colpos=%d exitv %s", lineno, colpos,
                debug_outstr_value_BM (_.exitv, CURFRAME_BM, 0));
  if (!isobject_BM (_.exitv))
    {
      if (pars)
        parsererrorprintf_BM (pars,
                              CURFRAME_BM, lineno, colpos,
                              "non-object exit argument #%d for exit readmacro",
                              startix);
      LOCALRETURN_BM (NULL);
    }
  if (!_.resobj)
    {
      _.resobj = makeobj_BM ();
      objputspacenum_BM (_.resobj, GlobalSp_BM);
    }
  objlock_BM (_.resobj);
  objresetcomps_BM (_.resobj, 2);
  objresetattrs_BM (_.resobj, 5);
  //objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  if (_.exitv)
    objputattr_BM (_.resobj, k_exit, (const value_tyBM) _.exitv);
  if (!_.resclass)
    _.resclass = (objectval_tyBM *) k_basiclo_exit;
  objputclass_BM (_.resobj, _.resclass);
  objtouchnow_BM (_.resobj);
  objunlock_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:exit L%dC%d resobj %s for rnod %s", lineno,
                colpos, objectdbg_BM (_.resobj),
                debug_outstr_value_BM ((value_tyBM) _.rnodv, CURFRAME_BM, 0));
  LOCALRETURN_BM (_.resobj);
}                               /* end ROUTINE  _63Q0R4r8xa7_7XOAxxP5pi2 exit:readmacro */


/////

// for the routine command_readmacro for while
extern objrout_sigBM ROUTINEOBJNAME_BM (_1ufPZmTnWhp_7FX9NANZCAW);

value_tyBM
ROUTINEOBJNAME_BM (_1ufPZmTnWhp_7FX9NANZCAW)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const value_tyBM arg4,         // parsob
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const node_tyBM * rnodv; objectval_tyBM * resobj;
                 objectval_tyBM * resclass; objectval_tyBM * inv;
                 objectval_tyBM * curlab; objectval_tyBM * parsob;
                 value_tyBM curson; value_tyBM whilexpv;
    );
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    LOCALRETURN_BM (NULL);
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  _.resobj = NULL;
  if (!isobject_BM (arg4))
    LOCALRETURN_BM (NULL);
  _.parsob = arg4;
  struct parser_stBM *pars = objparserpayload_BM (_.parsob);
  if (!pars)
    LOCALRETURN_BM (NULL);
  const objectval_tyBM *k_basiclo_while = BMK_4Af5NOOf7Qe_7KQdGPoNdJ0;
  const objectval_tyBM *k_while = BMK_7GNnckYYtcH_7wtOnPP4eKU;
  const objectval_tyBM *k_label = BMK_3XBrePAliOo_37VlAqBsb5C;
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
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object `in` for while readmacro");
          LOCALRETURN_BM (NULL);
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
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object `label` for while readmacro");
          LOCALRETURN_BM (NULL);
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
  if (startix + 1 > nodwidth)
    {
      if (pars)
        parsererrorprintf_BM (pars,
                              CURFRAME_BM, lineno, colpos,
                              "too short %d while readmacro", nodwidth);
      LOCALRETURN_BM (NULL);
    }
  _.whilexpv = nodenthson_BM ((const value_tyBM) _.rnodv, startix);
  if (!_.whilexpv)
    {
      if (pars)
        parsererrorprintf_BM (pars,
                              CURFRAME_BM, lineno, colpos,
                              "nil cond in while readmacro");
    }
  for (unsigned ix = startix + 1; ix < nodwidth; ix++)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, ix);
      if (!isobject_BM (_.curson))
        {
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object #%d comp for while readmacro",
                                  ix);
          LOCALRETURN_BM (NULL);
        }
    }
  objlock_BM (_.resobj);
  objresetcomps_BM (_.resobj, nodwidth - startix);
  objresetattrs_BM (_.resobj, 5);
  //objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
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
  objunlock_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:while resobj %s", objectdbg_BM (_.resobj));
  LOCALRETURN_BM (_.resobj);
}                               /* end ROUTINE  _1ufPZmTnWhp_7FX9NANZCAW while:readmacro */


/////

// for the routine command_readmacro for return
extern objrout_sigBM ROUTINEOBJNAME_BM (_5788HpgOtVV_4zwZIr0jgmq);

value_tyBM
ROUTINEOBJNAME_BM (_5788HpgOtVV_4zwZIr0jgmq)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const value_tyBM arg4,         // parsob
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const node_tyBM * rnodv;
                 objectval_tyBM * resobj; objectval_tyBM * resclass;
                 objectval_tyBM * inv; value_tyBM curson; value_tyBM resexpv;
                 objectval_tyBM * parsob;
    );
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    LOCALRETURN_BM (NULL);
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  _.resobj = NULL;
  if (!isobject_BM (arg4))
    LOCALRETURN_BM (NULL);
  _.parsob = arg4;
  struct parser_stBM *pars = objparserpayload_BM (_.parsob);
  if (!pars)
    LOCALRETURN_BM (NULL);
  DBGPRINTF_BM ("start readmacro:return  _5788HpgOtVV_4zwZIr0jgmq"
                " lineno=%d colpos=%d nodwidth=%u", lineno, colpos, nodwidth);

  const objectval_tyBM *k_basiclo_return = BMK_6dfdSwPGgR8_2EaBHYhuZ5G;
  const objectval_tyBM *k_return = BMK_2DH0ucElTgh_62vxjxLcfev;
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
          parsererrorprintf_BM (pars,
                                CURFRAME_BM, lineno,
                                colpos,
                                "non-object `in` for return readmacro");
          LOCALRETURN_BM (NULL);
        }
      _.resobj = _.inv;
      if (objectisinstance_BM (_.resobj, k_basiclo_return))
        _.resclass = objclass_BM (_.resobj);
      startix++;
    }
  DBGPRINTF_BM ("start readmacro:return "
                " lineno=%d colpos=%d nodwidth=%u startix=%d",
                lineno, colpos, nodwidth, startix);
  if (startix + 1 < nodwidth)
    {
      parsererrorprintf_BM (pars,
                            CURFRAME_BM, lineno, colpos,
                            "too long %u return readmacro", nodwidth);
      LOCALRETURN_BM (NULL);
    }
  _.resexpv = nodenthson_BM ((const value_tyBM) _.rnodv, startix);
  if (!_.resclass)
    _.resclass = (objectval_tyBM *) k_basiclo_return;
  if (!_.resobj)
    {
      _.resobj = makeobj_BM ();
      objputspacenum_BM (_.resobj, GlobalSp_BM);
    };
  objlock_BM (_.resobj);
  objresetcomps_BM (_.resobj, 1);
  objresetattrs_BM (_.resobj, 5);
  //objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  if (_.resexpv)
    objputattr_BM (_.resobj, k_return, (const value_tyBM) _.resexpv);
  objputclass_BM (_.resobj, _.resclass);
  objtouchnow_BM (_.resobj);
  objunlock_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:return resobj %s", objectdbg_BM (_.resobj));
  LOCALRETURN_BM (_.resobj);
}                               /* end ROUTINE   _5788HpgOtVV_4zwZIr0jgmq return:readmacro */




/////

// for the routine command_readmacro for run
extern objrout_sigBM ROUTINEOBJNAME_BM (_7sg0DjYTA8n_66vhff9SgXH);

value_tyBM
ROUTINEOBJNAME_BM (_7sg0DjYTA8n_66vhff9SgXH)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const value_tyBM arg4,         // parsob 
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const node_tyBM * rnodv;
                 objectval_tyBM * resobj; objectval_tyBM * resclass;
                 objectval_tyBM * inv; value_tyBM curson; value_tyBM runexpv;
                 objectval_tyBM * parsob;
    );
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    LOCALRETURN_BM (NULL);
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  if (!isobject_BM (arg4))
    LOCALRETURN_BM (NULL);
  _.parsob = arg4;
  struct parser_stBM *pars = objparserpayload_BM (_.parsob);
  if (!pars)
    LOCALRETURN_BM (NULL);
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  _.resobj = NULL;
  DBGPRINTF_BM ("start readmacro:run "
                " lineno=%d colpos=%d nodwidth=%u rnod=%s",
                lineno, colpos, nodwidth,
                debug_outstr_value_BM ((value_tyBM) _.rnodv, CURFRAME_BM, 0));
  const objectval_tyBM *k_basiclo_run = BMK_4SHgzjNdlGo_1CxI9hBNDrC;
  const objectval_tyBM *k_run = BMK_4RFtYFUdfau_7Vm5jZ4Wm8e;
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
          parsererrorprintf_BM (pars,
                                CURFRAME_BM, lineno,
                                colpos, "non-object `in` for run readmacro");
          LOCALRETURN_BM (NULL);
        }
      _.resobj = _.inv;
      if (objectisinstance_BM (_.resobj, k_basiclo_run))
        _.resclass = objclass_BM (_.resobj);
      startix++;
    }
  DBGPRINTF_BM (" readmacro:run "
                " lineno=%d colpos=%d startix#%u nodwidth#%u", lineno, colpos,
                startix, nodwidth);
  if (startix + 1 < nodwidth)
    {
      parsererrorprintf_BM (pars,
                            CURFRAME_BM, lineno, colpos,
                            "too long %u run readmacro", nodwidth);
      LOCALRETURN_BM (NULL);
    }
  _.runexpv = nodenthson_BM ((const value_tyBM) _.rnodv, startix);
  if (!_.resclass)
    _.resclass = (objectval_tyBM *) k_basiclo_run;
  if (!_.resobj)
    {
      _.resobj = makeobj_BM ();
      objputspacenum_BM (_.resobj, GlobalSp_BM);
    };
  objlock_BM (_.resobj);
  objresetcomps_BM (_.resobj, 1);
  objresetattrs_BM (_.resobj, 5);
  //objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  if (_.runexpv)
    objputattr_BM (_.resobj, k_run, (const value_tyBM) _.runexpv);
  objputclass_BM (_.resobj, _.resclass);
  objtouchnow_BM (_.resobj);
  objunlock_BM (_.resobj);
  DBGPRINTF_BM ("end readmacro:run resobj %s", objectdbg_BM (_.resobj));
  LOCALRETURN_BM (_.resobj);
}                               /* end   _7sg0DjYTA8n_66vhff9SgXH run:readmacro */



///
// readmacro routine for cexpansion-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_42gEKfF4qca_6gGwxSFC1FO);

value_tyBM
ROUTINEOBJNAME_BM (_42gEKfF4qca_6gGwxSFC1FO)    // cexpansion#readmacro
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const value_tyBM arg4,         // parsob
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  enum
  {
    closix_curcexp,
    closix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos;     //
                 const node_tyBM * rnodv;       //
                 objectval_tyBM * resobj;       //
                 objectval_tyBM * resclass;     //
                 objectval_tyBM * inv;  //
                 value_tyBM curson;     //
                 value_tyBM runexpv;    //
                 value_tyBM argsv;      //
                 value_tyBM resultsv;   //
                 value_tyBM tupresultsv;        //
                 value_tyBM nodargsv;   //
                 objectval_tyBM * parsob;       //
    );
  LOCALGETFUNV_BM (_.clos);
  if (!isclosure_BM ((value_tyBM) _.clos)
      || closurewidth_BM ((value_tyBM) _.clos) != closix__LAST)
    LOCALRETURN_BM (NULL);
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    LOCALRETURN_BM (NULL);
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  if (!isobject_BM (arg4))
    LOCALRETURN_BM (NULL);
  _.parsob = arg4;
  struct parser_stBM *pars = objparserpayload_BM (_.parsob);
  if (!pars)
    LOCALRETURN_BM (NULL);
  _.resobj = NULL;
  DBGPRINTF_BM ("cexpansion#readmacro start "
                " lineno=%d colpos=%d nodwidth=%u rnod=%s", lineno, colpos,
                nodwidth, debug_outstr_value_BM ((value_tyBM) _.rnodv,
                                                 CURFRAME_BM, 0));

  const objectval_tyBM *closconn = closureconn_BM ((const value_tyBM) _.clos);
  ASSERT_BM (closconn != NULL);
  WEAKASSERT_BM (closurewidth_BM ((const value_tyBM) _.clos) >= closix__LAST);
  objectval_tyBM *cexpandob =   //
    objectcast_BM (closurenthson_BM ((const value_tyBM) _.clos,
                                     closix_curcexp));
  const objectval_tyBM *k_basiclo_cexpansion = BMK_4GJJnvyrLyW_5mhopCYvh8h;
  const objectval_tyBM *k_basiclo_cexpander = BMK_9pJUJ57N6RL_2nsXFzR6S3E;
  const objectval_tyBM *k_results = BMK_5ve5gbSjN0r_1n61nNRPtnN;
  const objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  const objectval_tyBM *k_expander = BMK_9OzBvYbDWm8_3XA4wkArOmo;
  if (!isobject_BM (cexpandob)
      || !objectisinstance_BM (cexpandob, k_basiclo_cexpander))
    {
      parsererrorprintf_BM (pars,
                            CURFRAME_BM, lineno, colpos,
                            "bad cexpander for cexpansion readmacro %s",
                            debug_outstr_value_BM ((value_tyBM) _.rnodv,
                                                   CURFRAME_BM, 0));
      LOCALRETURN_BM (NULL);
    };
  _.resultsv = objgetattr_BM (cexpandob, k_results);
  _.argsv = objgetattr_BM (cexpandob, k_arguments);
  int nbresults =               //
    istuple_BM (_.resultsv) ? tuplesize_BM (_.resultsv) :
    isobject_BM (_.resultsv) ? 1 : 0;
  int nbargs =                  //
    istuple_BM (_.argsv) ? tuplesize_BM (_.argsv) :
    isobject_BM (_.argsv) ? 1 : 0;
  DBGPRINTF_BM
    ("cexpansion#readmacro curexp %s nbresults#%d nbargs#%d rnod %s",
     objectdbg_BM (cexpandob), nbresults, nbargs,
     debug_outstr_value_BM ((value_tyBM) _.rnodv, CURFRAME_BM, 0));
  unsigned startix = 0;
  if (nodwidth > 0
      && (_.curson =
          nodenthson_BM ((const value_tyBM) _.rnodv, startix)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          parsererrorprintf_BM (pars,
                                CURFRAME_BM, lineno,
                                colpos,
                                "non-object `in` for cexpansion %s readmacro",
                                objectdbg_BM (cexpandob));
          LOCALRETURN_BM (NULL);
        }
      _.resobj = _.inv;
      if (objectisinstance_BM (_.resobj, k_basiclo_cexpansion))
        _.resclass = objclass_BM (_.resobj);
      startix++;
    }
  DBGPRINTF_BM ("cexpansion#readmacro expander %s startix=%d nbresults=%d nbargs=%d nodwidth=%d rnod %s", objectdbg_BM (cexpandob), startix, nbresults, nbargs, nodwidth,       //
                debug_outstr_value_BM ((value_tyBM) _.rnodv, CURFRAME_BM, 0));
  if (startix + nbresults + nbargs < nodwidth)
    {
      parsererrorprintf_BM (pars, CURFRAME_BM, lineno, colpos, "too short %s cexpansion (%u) readmacro (%d results, %d arguments) rnod %s", objectdbg_BM (cexpandob), nodwidth, nbresults, nbargs,      //
                            debug_outstr_value_BM ((value_tyBM) _.rnodv,
                                                   CURFRAME_BM, 0));
      LOCALRETURN_BM (NULL);
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
              parsererrorprintf_BM      //
                (pars,
                 CURFRAME_BM, lineno, colpos,
                 "non-object result#%d for cexpansion %s readmacro rnod %s",
                 ix, objectdbg_BM (cexpandob),
                 debug_outstr_value_BM ((value_tyBM) _.rnodv, CURFRAME_BM,
                                        0));
              LOCALRETURN_BM (NULL);
            }
        }
    }
  if (startix + nbresults + nbargs < nodwidth)
    {
      parsererrorprintf_BM      //
        (pars, CURFRAME_BM, lineno, colpos,     //
         "too wide %u cexpansion %s readmacro rnod %s", nodwidth, objectdbg_BM (cexpandob),     //
         debug_outstr_value_BM ((value_tyBM) _.rnodv, CURFRAME_BM, 0));
      LOCALRETURN_BM (NULL);
    }
  if (!_.resobj)
    {
      _.resobj = makeobj_BM ();
      objputspacenum_BM (_.resobj, GlobalSp_BM);
    };
  objlock_BM (_.resobj);
  objresetcomps_BM (_.resobj, 0);
  objresetattrs_BM (_.resobj, 5);
  //objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  objputattr_BM (_.resobj, k_expander, cexpandob);
  DBGPRINTF_BM ("cexpansion#readmacro cexpand %s k_expander= %s; resobj= %s; rnod= %s", objectdbg_BM (cexpandob), objectdbg1_BM (k_expander), objectdbg2_BM (_.resobj), //
                debug_outstr_value_BM ((value_tyBM) _.rnodv, CURFRAME_BM, 0));
  if (nbresults > 0)
    {
      objectval_tyBM *tinyarr[TINYSIZE_BM] = {
      };
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
      value_tyBM tinyarrv[TINYSIZE_BM] = {
      };
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
        free (arrv), arrv = NULL;
      objputattr_BM (_.resobj, k_arguments, _.nodargsv);
    }
  else
    objremoveattr_BM (_.resobj, k_arguments);
  objputclass_BM (_.resobj, _.resclass);
  objtouchnow_BM (_.resobj);
  objunlock_BM (_.resobj);
  DBGPRINTF_BM ("end cexpansion#readmacro resobj %s cexpandob %s",
                objectdbg_BM (_.resobj), objectdbg1_BM (cexpandob));
  LOCALRETURN_BM (_.resobj);
}                               /* end cexpansion#readmacro _42gEKfF4qca_6gGwxSFC1FO */




////////////////

///
// readmacro routine for when-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_6gwxdBT3Mhv_8Gtgu8feoy3);

value_tyBM
ROUTINEOBJNAME_BM (_6gwxdBT3Mhv_8Gtgu8feoy3)    // when#read_macro
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const value_tyBM arg4,         // parsob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const node_tyBM * rnodv;
                 objectval_tyBM * resobj; objectval_tyBM * curobj;
                 objectval_tyBM * resclass; value_tyBM testexpv;
                 value_tyBM * inv; value_tyBM curson, curarg;
                 objectval_tyBM * parsob;
    );
  _.rnodv = nodecast_BM (arg1);
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  _.resobj = NULL;
  if (!isobject_BM (arg4))
    LOCALRETURN_BM (NULL);
  _.parsob = arg4;
  struct parser_stBM *pars = objparserpayload_BM (_.parsob);
  if (!pars)
    LOCALRETURN_BM (NULL);
  DBGPRINTF_BM ("start when readmacro cexpansion €_42gEKfF4" " lineno=%d colpos=%d nodwidth=%u rnodv=%s", lineno, colpos, nodwidth,   //
                OUTSTRVALUE_BM ((value_tyBM *) _.rnodv));
  const objectval_tyBM *k_test = BMK_2j84OTHlFdJ_1pMyQfgsmAz;
  WEAKASSERT_BM (k_test != NULL);
  const objectval_tyBM *k_basiclo_when = BMK_3fvdRZNCmJS_5bTAPr83mXg;
  WEAKASSERT_BM (k_basiclo_when != NULL);
  ///
  const objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  WEAKASSERT_BM (k_basiclo_statement != NULL);
  ///
  const objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  WEAKASSERT_BM (k_basiclo_block != NULL);
  unsigned startix = 0;
  if (nodwidth > 0
      && (_.curson =
          nodenthson_BM ((const value_tyBM) _.rnodv, startix)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          parsererrorprintf_BM (pars,
                                CURFRAME_BM, lineno,
                                colpos, "non-object `in` for when readmacro");
          LOCALRETURN_BM (NULL);
        }
      _.resobj = (objectval_tyBM *) _.inv;
      if (objectisinstance_BM (_.resobj, k_basiclo_when))
        _.resclass = objclass_BM (_.resobj);
      startix++;
    }
  _.testexpv = nodenthson_BM ((const value_tyBM) _.rnodv, startix);
  NONPRINTF_BM ("when readmacro cexpansion"
                " lineno=%d colpos=%d nodwidth=%u startix=%d",
                lineno, colpos, nodwidth, startix);
  for (unsigned ix = startix + 1; ix < nodwidth; ix++)
    {
      _.curarg = nodenthson_BM ((value_tyBM) _.rnodv, ix);
      _.curobj = objectcast_BM (_.curarg);
      DBGPRINTF_BM ("when readmacro cexpansion"
                    " lineno=%d colpos=%d ix=%d\n... curarg=%s \n",
                    lineno, colpos, ix,
                    debug_outstr_value_BM (_.curarg, CURFRAME_BM, 2));
      if (!_.curobj
          || (!objectisinstance_BM (_.curobj, k_basiclo_statement)
              && !objectisinstance_BM (_.curobj, k_basiclo_block)))
        {
          parsererrorprintf_BM
            (pars,
             CURFRAME_BM, lineno,
             colpos,
             "bad arg #%d (%s) in when readmacro (not a basiclo_statement or basiclo_block)",
             ix, debug_outstr_value_BM (_.curarg, CURFRAME_BM, 0));
          LOCALRETURN_BM (NULL);
        };
      _.curarg = NULL;
      _.curobj = NULL;
    }
  if (!_.resclass)
    _.resclass = (objectval_tyBM *) k_basiclo_when;
  if (!_.resobj)
    {
      _.resobj = makeobj_BM ();
      objputspacenum_BM (_.resobj, GlobalSp_BM);
    };
  objlock_BM (_.resobj);
  objresetcomps_BM (_.resobj, nodwidth - startix);
  objresetattrs_BM (_.resobj, 5);
  //objputattr_BM (_.resobj, BMP_origin, (const value_tyBM) _.rnodv);
  if (_.testexpv)
    objputattr_BM (_.resobj, k_test, (const value_tyBM) _.testexpv);
  for (unsigned ix = startix + 1; ix < nodwidth; ix++)
    {
      _.curobj = objectcast_BM (nodenthson_BM ((value_tyBM) _.rnodv, ix));
      objappendcomp_BM (_.resobj, _.curobj);
      DBGPRINTF_BM
        ("when readmacro cexpansion resobj=%s /L%u ix=%d curobj=%s",
         objectdbg_BM (_.resobj), objnbcomps_BM (_.resobj), ix,
         objectdbg1_BM (_.curobj));
      _.curobj = NULL;
    };
  objputclass_BM (_.resobj, _.resclass);
  objtouchnow_BM (_.resobj);
  objunlock_BM (_.resobj);
  DBGPRINTF_BM ("when readmacro cexpansion"
                " lineno=%d colpos=%d gives %s /L%u",
                lineno, colpos, objectdbg_BM (_.resobj),
                objnbcomps_BM (_.resobj));
  LOCALRETURN_BM (_.resobj);
}                               // end when:readmacro _6gwxdBT3Mhv_8Gtgu8feoy3

//////


// assoc readmacro _7iKya0Q5Jii_0mjPPia0yib

extern objrout_sigBM ROUTINEOBJNAME_BM (_7iKya0Q5Jii_0mjPPia0yib);

value_tyBM
ROUTINEOBJNAME_BM (_7iKya0Q5Jii_0mjPPia0yib)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const value_tyBM arg4,         // parsob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_7iKya0Q5Jii_0mjPPia0yib,
                 value_tyBM rnodv;
                 value_tyBM inv; value_tyBM curson; objectval_tyBM * parsob;
                 objectval_tyBM * resobj;
    );
  objectval_tyBM *k_assoc_object = BMK_6ZQ05nCv3Ys_8LA6B5LkZgm;
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    LOCALRETURN_BM (NULL);
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  int startix = 0;
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  DBGPRINTF_BM ("start readmacro:assoc _7iKya0Q5Jii_0mjPPia0yib"
                " lineno=%d colpos=%d nodwidth=%u", lineno, colpos, nodwidth);
  if (!isobject_BM (arg4))
    LOCALRETURN_BM (NULL);
  _.parsob = arg4;
  struct parser_stBM *pars = objparserpayload_BM (_.parsob);
  if (!pars)
    LOCALRETURN_BM (NULL);
  if (nodwidth > 0
      && (_.curson = nodenthson_BM ((const value_tyBM) _.rnodv, 0)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM, lineno,
                                  colpos,
                                  "non-object `in` for assoc readmacro");
          LOCALRETURN_BM (NULL);
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
  unsigned assosiz = 0;
  if (startix + 1 < (int) nodwidth)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, startix + 1);
      if (istaggedint_BM (_.curson))
        assosiz = getint_BM (_.curson);
    }
  if (assosiz < 4)
    assosiz = 4;
  else if (assosiz > MAXSIZE_BM / 4)
    assosiz = MAXSIZE_BM / 4;
  {
    objlock_BM (_.resobj);
    objputclass_BM (_.resobj, k_assoc_object);
    objputassocpayl_BM (_.resobj, assosiz);
    objtouchnow_BM (_.resobj);
    objunlock_BM (_.resobj);
  }
  DBGPRINTF_BM ("readmacro:assoc resobj=%s assosiz=%u",
                objectdbg_BM (_.resobj), assosiz);
  LOCALRETURN_BM (_.resobj);
}                               /* end readmacro:assoc _7iKya0Q5Jii_0mjPPia0yib */



// readmacro:hset _2mWbSPeD8lw_8ea0EhwQUAa

extern objrout_sigBM ROUTINEOBJNAME_BM (_2mWbSPeD8lw_8ea0EhwQUAa);

value_tyBM
ROUTINEOBJNAME_BM (_2mWbSPeD8lw_8ea0EhwQUAa)    // readmacro:hset
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // node
 const value_tyBM arg2,         // lineno
 const value_tyBM arg3,         // colpos
 const value_tyBM arg4,         // parsob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_2mWbSPeD8lw_8ea0EhwQUAa,
                 value_tyBM rnodv;
                 value_tyBM inv; value_tyBM curson; objectval_tyBM * parsob;
                 objectval_tyBM * resobj;
    );
  objectval_tyBM *k_hset_object = BMK_8c9otZ4pwR6_55k81qyyYV2;
  _.rnodv = arg1;
  if (!isnode_BM (arg1))
    LOCALRETURN_BM (NULL);
  int lineno = getint_BM (arg2);
  int colpos = getint_BM (arg3);
  int startix = 0;
  unsigned nodwidth = nodewidth_BM ((const value_tyBM) _.rnodv);
  DBGPRINTF_BM ("start readmacro:hset 2mWbSPeD8lw_8ea0EhwQUAa"
                " lineno=%d colpos=%d nodwidth=%u", lineno, colpos, nodwidth);
  if (!isobject_BM (arg4))
    LOCALRETURN_BM (NULL);
  _.parsob = arg4;
  struct parser_stBM *pars = objparserpayload_BM (_.parsob);
  if (!pars)
    LOCALRETURN_BM (NULL);
  if (nodwidth > 0
      && (_.curson = nodenthson_BM ((const value_tyBM) _.rnodv, 0)) != NULL
      && isnode_BM (_.curson) && nodeconn_BM (_.curson) == BMP_in)
    {
      _.inv = nodenthson_BM (_.curson, 0);
      if (!isobject_BM (_.inv))
        {
          if (pars)
            parsererrorprintf_BM (pars,
                                  CURFRAME_BM,
                                  lineno, colpos,
                                  "non-object `in` for hset readmacro");
          LOCALRETURN_BM (NULL);
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
  unsigned hsetsiz = 0;
  if (startix + 1 < (int) nodwidth)
    {
      _.curson = nodenthson_BM ((const value_tyBM) _.rnodv, startix + 1);
      if (istaggedint_BM (_.curson))
        hsetsiz = getint_BM (_.curson);
    }
  if (hsetsiz < 5)
    hsetsiz = 5;
  else if (hsetsiz > MAXSIZE_BM / 4)
    hsetsiz = MAXSIZE_BM / 4;
  {
    objlock_BM (_.resobj);
    objputclass_BM (_.resobj, k_hset_object);
    objputhashsetpayl_BM (_.resobj, hsetsiz);
    objtouchnow_BM (_.resobj);
    objunlock_BM (_.resobj);
  }
  DBGPRINTF_BM ("readmacro:hset resobj=%s hsetsiz=%u",
                objectdbg_BM (_.resobj), hsetsiz);
  LOCALRETURN_BM (_.resobj);
}                               /* end readmacro:hset  _2mWbSPeD8lw_8ea0EhwQUAa */



//// for the method to dump_scan°hashsetval_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_8RsUtTTwcw0_9DjQfQrNouU);

value_tyBM
ROUTINEOBJNAME_BM (_8RsUtTTwcw0_9DjQfQrNouU)    //  dump_scan°hashsetval_object
(struct stackframe_stBM * stkf, const value_tyBM arg1,  // recv
 const value_tyBM arg2,         // dumpob
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ BMK_8RsUtTTwcw0_9DjQfQrNouU,
                 objectval_tyBM * recv;
                 objectval_tyBM * curattrob; value_tyBM curval;
                 objectval_tyBM * dumpob; const setval_tyBM * setv;
    );
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  WEAKASSERT_BM (obdumpgetdumper_BM (arg2) != NULL);
  _.dumpob = arg2;
  WEAKASSERT_BM (restargs_ == NULL);
  WEAKASSERT_BM (objhashashsetvalpayl_BM (_.recv));
  for (_.curval = objhashsetvalfirstpayl_BM (_.recv); _.curval != NULL;
       _.curval = objhashsetvalnextpayl_BM (_.recv, _.curval))
    {
      obdumpscanvalue_BM (_.dumpob, _.curval, 0);
    }
  LOCALRETURN_BM (_.recv);
}                               /* end dump_scan°hashsetval_object */


// dump_data°hashsetval_object
extern objrout_sigBM ROUTINEOBJNAME_BM (_6UxkFEHhNQS_0f65oUlZ7b5);

value_tyBM
ROUTINEOBJNAME_BM (_6UxkFEHhNQS_0f65oUlZ7b5)    // dump_data°hashsetval_object
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // reciever
 const value_tyBM arg2,         // dumpob
 const value_tyBM arg3,         // strbufob
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ BMK_6UxkFEHhNQS_0f65oUlZ7b5,
                 objectval_tyBM * recv;
                 objectval_tyBM * dumpob; objectval_tyBM * bufob;
                 const setval_tyBM * setv; objectval_tyBM * curattrob;
                 value_tyBM curval; value_tyBM contv;
                 value_tyBM dumpres;
    );
  objectval_tyBM *k_reserve = BMK_2pwKyMVQyvI_3PH8nIPXjW0;
  objectval_tyBM *k_add = BMK_1dzZlwqKdLH_8HjkBsL9Mar;
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  struct dumper_stBM *du = obdumpgetdumper_BM (arg2);
  WEAKASSERT_BM (du != NULL);
  _.dumpob = arg2;
  _.bufob = objectcast_BM (arg3);
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.bufob));
  WEAKASSERT_BM (objhashashsetvalpayl_BM (_.recv));
  _.contv = objhashsetvalmakenodepayl_BM (_.recv, BMP_node);
  unsigned nbcont = nodewidth_BM (_.contv);
  objstrbufferprintfpayl_BM (_.bufob, "!~ todo (~\t");
  objstrbuffermoreindentpayl_BM (_.bufob);
  _.dumpres = send3_BM (k_reserve, BMP_dump_value,
                        CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (0));
  objstrbufferprintfpayl_BM (_.bufob, " %ld\n",
                             (unsigned long) prime_above_BM (4 +
                                                             6 * nbcont / 5));
  for (unsigned ix = 0; ix < nbcont; ix++)
    {
      _.curval = nodenthson_BM (_.contv, ix);
      if (!obdumpvalisfullydumpable_BM (_.dumpob, _.curval))
        continue;
      objstrbufferprintfpayl_BM (_.bufob, "\n!& ");
      _.dumpres = send3_BM (k_add, BMP_dump_value,
                            CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (0));
      objstrbufferprintfpayl_BM (_.bufob, "\t ");
      _.dumpres = send3_BM (_.curval, BMP_dump_value,
                            CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (0));
    }
  objstrbufferlessindentpayl_BM (_.bufob);
  objstrbufferappendcstrpayl_BM (_.bufob, "\n~)\n");
  LOCALRETURN_BM (_.recv);
}                               /* end  dump_data°hashsetval_object _6UxkFEHhNQS_0f65oUlZ7b5 */

// method reserve°hashsetval_object _7IlDChYeWQk_1l1rM2cq5uj

extern objrout_sigBM ROUTINEOBJNAME_BM (_7IlDChYeWQk_1l1rM2cq5uj);

value_tyBM
ROUTINEOBJNAME_BM (_7IlDChYeWQk_1l1rM2cq5uj)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // reciever
 const value_tyBM arg2,         // sizev
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_7IlDChYeWQk_1l1rM2cq5uj,
                 objectval_tyBM * obrecv;
    );
  if (!isobject_BM (arg1))
    LOCALRETURN_BM (NULL);
  if (!istaggedint_BM (arg2))
    LOCALRETURN_BM (NULL);
  _.obrecv = (objectval_tyBM *) arg1;
  unsigned siz = getint_BM (arg2);
  if (siz > MAXSIZE_BM / 4)
    siz = MAXSIZE_BM / 4;
  else if (siz < 3)
    siz = 4;
  objlock_BM (_.obrecv);
  objputhashsetvalpayl_BM (_.obrecv, siz);
  objunlock_BM (_.obrecv);
  LOCALRETURN_BM (_.obrecv);
}                               /* end reserve°hashsetval_object _7IlDChYeWQk_1l1rM2cq5uj */

// method add°hashsetval_object _9O4E8Tcc2Fq_8MXrM73GJCM
extern objrout_sigBM ROUTINEOBJNAME_BM (_9O4E8Tcc2Fq_8MXrM73GJCM);

value_tyBM
ROUTINEOBJNAME_BM (_9O4E8Tcc2Fq_8MXrM73GJCM)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         //
 const value_tyBM arg2,         //
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_9O4E8Tcc2Fq_8MXrM73GJCM,
                 value_tyBM valv;
                 objectval_tyBM * obrecv;
    );
  _.obrecv = (objectval_tyBM *) arg1;
  _.valv = arg2;
  if (objhashashsetvalpayl_BM (_.obrecv))
    {
      objhashsetaddpayl_BM (_.obrecv, _.valv);
      LOCALRETURN_BM (_.obrecv);
    }
  LOCALRETURN_BM (NULL);
}                               /* end add°hashsetval_object _9O4E8Tcc2Fq_8MXrM73GJCM */



// method remove°hashsetval_object  _2WY2j1qroxH_1sjxiD6Yvad
extern objrout_sigBM ROUTINEOBJNAME_BM (_2WY2j1qroxH_1sjxiD6Yvad);

value_tyBM
ROUTINEOBJNAME_BM (_2WY2j1qroxH_1sjxiD6Yvad)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         //
 const value_tyBM arg2,         //
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_2WY2j1qroxH_1sjxiD6Yvad,
                 value_tyBM valv;
                 objectval_tyBM * obrecv;
    );
  _.obrecv = (objectval_tyBM *) arg1;
  _.valv = arg2;
  if (objhashashsetvalpayl_BM (_.obrecv))
    {
      objhashsetremovepayl_BM (_.obrecv, _.valv);
      LOCALRETURN_BM (_.obrecv);
    }
  LOCALRETURN_BM (NULL);
}                               /* end remove°hashsetval_object _2WY2j1qroxH_1sjxiD6Yvad */


////////////////
// reserve°hashmapval_object _1PXiQf6nwlO_8J54FkeCF9A
extern objrout_sigBM ROUTINEOBJNAME_BM (_1PXiQf6nwlO_8J54FkeCF9A);
value_tyBM
ROUTINEOBJNAME_BM (_1PXiQf6nwlO_8J54FkeCF9A)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // reciever
 const value_tyBM arg2,         // sizev
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_1PXiQf6nwlO_8J54FkeCF9A,
                 objectval_tyBM * obrecv;
    );
  if (!isobject_BM (arg1))
    LOCALRETURN_BM (NULL);
  if (!istaggedint_BM (arg2))
    LOCALRETURN_BM (NULL);
  _.obrecv = (objectval_tyBM *) arg1;
  unsigned siz = getint_BM (arg2);
  if (siz > MAXSIZE_BM / 4)
    siz = MAXSIZE_BM / 4;
  else if (siz < 3)
    siz = 4;
  objputhashmapvalpayl_BM (_.obrecv, siz);
  LOCALRETURN_BM (_.obrecv);
}                               /* end reserve°hashmapval_object _1PXiQf6nwlO_8J54FkeCF9A */



// method put°hashmapval_object  _8EqnYwr2sed_1Njis9lW96i
extern objrout_sigBM ROUTINEOBJNAME_BM (_8EqnYwr2sed_1Njis9lW96i);
value_tyBM
ROUTINEOBJNAME_BM (_8EqnYwr2sed_1Njis9lW96i)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // reciever
 const value_tyBM arg2,         // keyv
 const value_tyBM arg3,         // valv
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_8EqnYwr2sed_1Njis9lW96i,
                 objectval_tyBM * obrecv;
                 value_tyBM keyv;
                 value_tyBM valv;
    );
  if (!isobject_BM (arg1))
    LOCALRETURN_BM (NULL);
  if (!arg2)
    LOCALRETURN_BM (NULL);
  _.obrecv = (objectval_tyBM *) arg1;
  _.keyv = arg2;
  _.valv = arg3;
  if (objhashashmapvalpayl_BM (_.obrecv))
    {
      objhashmapvalputpayl_BM (_.obrecv, _.keyv, _.valv);
      LOCALRETURN_BM (_.obrecv);
    }
  LOCALRETURN_BM (NULL);
}                               /* end method put°hashmapval_object _8EqnYwr2sed_1Njis9lW96i */


// method dump_scan°hashmapval_object _5DQ2V9upFQv_3I4NiDiwsdf
extern objrout_sigBM ROUTINEOBJNAME_BM (_5DQ2V9upFQv_3I4NiDiwsdf);
value_tyBM
ROUTINEOBJNAME_BM (_5DQ2V9upFQv_3I4NiDiwsdf)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // reciever
 const value_tyBM arg2,         // dumpob
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_5DQ2V9upFQv_3I4NiDiwsdf,
                 objectval_tyBM * recv; objectval_tyBM * dumpob;
                 value_tyBM keyv;
                 value_tyBM valv;
    );
  _.recv = objectcast_BM (arg1);
  _.dumpob = objectcast_BM (arg2);
  WEAKASSERT_BM (obdumpgetdumper_BM (_.dumpob) != NULL);
  WEAKASSERT_BM (objhashashmapvalpayl_BM (_.recv));
  for (_.keyv = objhashmapvalfirstkeypayl_BM (_.recv);
       _.keyv != NULL; _.keyv = objhashmapvalnextkeypayl_BM (_.recv, _.keyv))
    {
      _.valv = objhashmapvalgetpayl_BM (_.recv, _.keyv);
      obdumpscanvalue_BM (_.dumpob, (value_tyBM) _.keyv, 0);
      obdumpscanvalue_BM (_.dumpob, (value_tyBM) _.valv, 0);
    }
  LOCALRETURN_BM (_.recv);
}                               /* end dump_scan°hashmapval_object _5DQ2V9upFQv_3I4NiDiwsdf */


// method dump_data°hashmapval_object _8AzRspWL4ws_3cdvWV4S1JH
extern objrout_sigBM ROUTINEOBJNAME_BM (_8AzRspWL4ws_3cdvWV4S1JH);

value_tyBM
ROUTINEOBJNAME_BM (_8AzRspWL4ws_3cdvWV4S1JH)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // reciever
 const value_tyBM arg2,         // dumpob
 const value_tyBM arg3,         // strbufob
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_8AzRspWL4ws_3cdvWV4S1JH,
                 objectval_tyBM * recv; //
                 objectval_tyBM * dumpob;       //
                 objectval_tyBM * bufob;        //
                 value_tyBM dumpres;    //
                 value_tyBM nodv;       //
                 value_tyBM keyv;       //
                 value_tyBM valv;       //
    );
  objectval_tyBM *k_reserve = BMK_2pwKyMVQyvI_3PH8nIPXjW0;
  objectval_tyBM *k_put = BMK_9pvzBeIKHXF_8YDPCrQ6OEK;
  WEAKASSERT_BM (isobject_BM (arg1));
  _.recv = arg1;
  _.dumpob = objectcast_BM (arg2);
  _.bufob = objectcast_BM (arg3);
  struct dumper_stBM *du = obdumpgetdumper_BM (_.dumpob);
  WEAKASSERT_BM (du != NULL);
  WEAKASSERT_BM (objhashashmapvalpayl_BM (_.recv));
  _.nodv = objhashmapvalmakenodeofkeyspayl_BM (_.recv, BMP_node);
  unsigned siz = nodewidth_BM (_.nodv);
  objstrbufferprintfpayl_BM (_.bufob, "!~ todo (~\t");
  objstrbuffermoreindentpayl_BM (_.bufob);
  _.dumpres = send3_BM (k_reserve, BMP_dump_value,
                        CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (0));
  objstrbufferprintfpayl_BM (_.bufob, " %ld\n",
                             (unsigned long) prime_above_BM (4 +
                                                             6 * siz / 5));
  for (unsigned ix = 0; ix < siz; ix++)
    {
      _.keyv = nodenthson_BM (_.nodv, ix);
      if (!obdumpvalisfullydumpable_BM (_.dumpob, _.keyv))
        continue;
      _.valv = objhashmapvalgetpayl_BM (_.recv, _.keyv);
      if (!obdumpvalisfullydumpable_BM (_.dumpob, _.valv))
        continue;
      objstrbufferprintfpayl_BM (_.bufob, "\n!& ");
      _.dumpres = send3_BM (k_put, BMP_dump_value,
                            CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (0));
      objstrbufferprintfpayl_BM (_.bufob, "\t ");
      _.dumpres = send3_BM (_.keyv, BMP_dump_value,
                            CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (0));
      objstrbufferprintfpayl_BM (_.bufob, "\t ");
      _.dumpres = send3_BM (_.valv, BMP_dump_value,
                            CURFRAME_BM, _.bufob, _.dumpob, taggedint_BM (0));
    }
  objstrbufferlessindentpayl_BM (_.bufob);
  objstrbufferappendcstrpayl_BM (_.bufob, "\n~)\n");
  LOCALRETURN_BM (_.recv);
}                               /* end dump_data°hashmapval_object _8AzRspWL4ws_3cdvWV4S1JH */


//////////////// list_object methods




////////////////////////////////////////////////////////////////

// todo function in our test_agenda  _7XDuHagbhi8_3V9zhBpbrrV
extern objrout_sigBM ROUTINEOBJNAME_BM (_7XDuHagbhi8_3V9zhBpbrrV);

value_tyBM
ROUTINEOBJNAME_BM (_7XDuHagbhi8_3V9zhBpbrrV)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // taskob
 const value_tyBM arg2_ __attribute__((unused)),        //
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_7XDuHagbhi8_3V9zhBpbrrV,
                 objectval_tyBM * taskob; value_tyBM resultv;
                 value_tyBM rankv;
    );
  objectval_tyBM *k_rank = BMK_8zRh2medTlP_0ImnPyO8NKH;
  objectval_tyBM *kk_defer_show = BMK_7rRjqfXs3QI_4Nwk2Lfm569;
  _.taskob = objectcast_BM (arg1);
  NONPRINTF_BM ("todo!test_agenda taskob %s", objectdbg_BM (_.taskob));
  WEAKASSERT_BM (_.taskob != NULL);
  objlock_BM (_.taskob);
  _.rankv = objgetattr_BM (_.taskob, k_rank);
  objunlock_BM (_.taskob);
  WEAKASSERT_BM (istaggedint_BM (_.rankv));
  int rk = getint_BM (_.rankv);
  NONPRINTF_BM ("todo!test_agenda taskob %s rk#%d", objectdbg_BM (_.taskob),
                rk);
  if (rk < 3 || (rk < 10 && rk % 2 == 0)
      || rk % 10000 == 0 || (rk % 64 == 0 && g_random_int () % 64 == 0))
    {
    }
  NONPRINTF_BM ("todo!test_agenda end taskob %s rk#%d",
                objectdbg_BM (_.taskob), rk);
  LOCALRETURN_BM (_.taskob);
}                               /* end todo in test_agenda _7XDuHagbhi8_3V9zhBpbrrV */




// sysdata command_handler _43m9jyNirvE_0wkbsL0Nvkp
extern objrout_sigBM ROUTINEOBJNAME_BM (_43m9jyNirvE_0wkbsL0Nvkp);

value_tyBM
ROUTINEOBJNAME_BM (_43m9jyNirvE_0wkbsL0Nvkp)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         //newob
 const value_tyBM arg2_ __attribute__((unused)),        //
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_43m9jyNirvE_0wkbsL0Nvkp,
                 value_tyBM arg1v;
                 objectval_tyBM * ob;
    );
  _.arg1v = arg1;
  _.ob = objectcast_BM (arg1);
  if (!_.ob)
    {
      WARNPRINTF_BM
        ("sysdata command_handler _43m9jyNirvE_0wkbsL0Nvkp wants an object, got %s",
         OUTSTRVALUE_BM (_.arg1v));
      LOCALRETURN_BM (NULL);
    }
  bool isnewob = false;
  {
    objlock_BM (BMP_the_system);
    isnewob = !objhashsetcontainspayl_BM (BMP_the_system, _.ob);
    if (isnewob)
      {
        objhashsetaddpayl_BM (BMP_the_system, _.ob);
        objtouchnow_BM (BMP_the_system);
      }
    objunlock_BM (BMP_the_system);
  }
  if (pthread_self () == mainthreadid_BM)
    {
      if (isnewob)
        {
          INFOPRINTF_BM (",sysdata added new object %s", objectdbg_BM (_.ob));
        }
      else
        {
          WARNPRINTF_BM (",sysdata did not add existing object %s",
                         objectdbg_BM (_.ob));
        }
    }
  if (isnewob)
    LOCALRETURN_BM (_.ob);
  else
    LOCALRETURN_BM (NULL);
}                               /* end  sysdata command_handler  _43m9jyNirvE_0wkbsL0Nvkp */


/****************
 **                           for Emacs...
 ** Local Variables: ;;
 ** compile-command: "./Build" ;;
 ** End: ;;
 ****************/
/**** end of file code_BM.c ***/
