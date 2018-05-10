// file gencode_BM.c

/***
    BISMON 
    Copyright © 2018 Basile Starynkevitch (working at CEA, LIST, France)
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
#include "gencode_BM.const.h"

static const char *
asprintf_prev_module_BM (const char *srcdir, objectval_tyBM * obmodule)
{
  char *pathstr = NULL;
  char modulidbuf[32];
  memset (modulidbuf, 0, sizeof (modulidbuf));
  ASSERT_BM (srcdir && strlen (srcdir) > 0);
  ASSERT_BM (isobject_BM (obmodule));
  idtocbuf32_BM (objid_BM (obmodule), modulidbuf);
  asprintf (&pathstr, "%s/" MODULEPREFIX_BM "%s.c-p%d~",
            srcdir, modulidbuf, (int) getpid ());
  if (!pathstr)
    FATAL_BM ("failed asprintf_prev_module srcdir %s obmodule %s - %m",
              srcdir, objectdbg_BM (obmodule));
  return pathstr;
}                               /* end asprintf_prev_module_BM */




//// for the method emit_c_type:c_opaque
extern objrout_sigBM ROUTINEOBJNAME_BM (_6gRlN8loM4E_4pSsNmiCeIa);

value_tyBM
ROUTINEOBJNAME_BM (_6gRlN8loM4E_4pSsNmiCeIa)    // emit_c_type:c_opaque
(struct stackframe_stBM * stkf, const value_tyBM arg1,  //
 const value_tyBM arg2,         //
 const value_tyBM arg3_ __attribute__ ((unused)),       //
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM recv;
                 objectval_tyBM * bufob;
    );
  // retrieve arguments
  _.recv = /*ctype */ (arg1);
  WEAKASSERT_BM (isobject_BM (_.recv));
  _.bufob = objectcast_BM (arg2);
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.bufob));
  DBGPRINTF_BM
    ("start  emit_c_type:c_opaque _6gRlN8loM4E_4pSsNmiCeIa recv=%s",
     objectdbg_BM (_.recv));
  const char *nam = findobjectname_BM (_.recv);
  char idbuf[32] = { };
  idtocbuf32_BM (objid_BM (_.recv), idbuf);
  if (nam)
    {
      objstrbufferprintfpayl_BM (_.bufob, "\n// opaque named type\n");
      objstrbufferprintfpayl_BM (_.bufob, "typedef void* %s_TyBM;\n", nam);
      objstrbufferprintfpayl_BM (_.bufob, "#define %s_TyBM %s_TyBM\n", idbuf,
                                 nam);
    }
  else
    {
      objstrbufferprintfpayl_BM (_.bufob, "\n// opaque anonymous type\n");
      objstrbufferprintfpayl_BM (_.bufob, "typedef void* %s_TyBM;\n", idbuf);
    }
  LOCALRETURN_BM (_.recv);
}                               /* end emit_c_type:c_opaque _6gRlN8loM4E_4pSsNmiCeIa */




//// for the method emit_c_type:c_enum
extern objrout_sigBM ROUTINEOBJNAME_BM (_979hCujWp2g_9tjRbM8Ht1l);

value_tyBM
ROUTINEOBJNAME_BM (_979hCujWp2g_9tjRbM8Ht1l)    // emit_c_type:c_enum
(struct stackframe_stBM * stkf, const value_tyBM arg1,  //
 const value_tyBM arg2,         //
 const value_tyBM arg3_ __attribute__ ((unused)),       //
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM recv;
                 objectval_tyBM * prbufob;
                 const objectval_tyBM * extendingob;
                 const tupleval_tyBM * ownenumtup;
    );
  // retrieve arguments
  _.recv = /*ctype */ (arg1);
  WEAKASSERT_BM (isobject_BM (_.recv));
  WEAKASSERT_BM (objhasstrbufferpayl_BM (arg2));
  _.prbufob = objectcast_BM (arg2);
  DBGPRINTF_BM
    ("start emit_c_type:c_enum _979hCujWp2g_9tjRbM8Ht1l recv=%s",
     objectdbg_BM (_.recv));
  const objectval_tyBM *k_extending = BMK_2bqFfs5OYL2_0HRi4lcgFcu;
  const objectval_tyBM *k_own_enumeration = BMK_4ot0ZxxA31Y_8GVFlcbckIH;
  //const objectval_tyBM *k_enumeration = BMK_7BROpIWQHzA_8b1C6i49Pkz;
  //
  //const char *nam = findobjectname_BM (_.recv);
  char idbuf[32] = { };
  idtocbuf32_BM (objid_BM (_.recv), idbuf);
  _.extendingob = objectcast_BM (objgetattr_BM (_.recv, k_extending));
  _.ownenumtup = tuplecast_BM (objgetattr_BM (_.recv, k_own_enumeration));
#warning emit_c_type:c_enum _979hCujWp2g_9tjRbM8Ht1l unimplemented
  LOCALRETURN_BM (NULL);
}                               /* end emit_c_type:c_enum _979hCujWp2g_9tjRbM8Ht1l  */


////////////////


//// for the method prepare_routine°basiclo_minifunction
extern objrout_sigBM ROUTINEOBJNAME_BM (_07qYMXftJRR_9dde2ASz4e9);

value_tyBM
ROUTINEOBJNAME_BM (_07qYMXftJRR_9dde2ASz4e9)    //  prepare_routine°basiclo_minifunction
(struct stackframe_stBM * stkf, const value_tyBM arg1,  // reciever
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // prepvalset
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))     //
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * modgenob;
                 const setval_tyBM * prepvalset;
                 objectval_tyBM * curprepob;
                 objectval_tyBM * curtypob;
                 objectval_tyBM * routprepob;
                 objectval_tyBM * obhsetblock;
                 objectval_tyBM * typob;
                 objectval_tyBM * bodyob;
                 objectval_tyBM * obmodhsetconst;
                 objectval_tyBM * stmtpropob;
                 value_tyBM recv;
                 const tupleval_tyBM * tupargs;
                 const tupleval_tyBM * tupclosed;
                 objectval_tyBM * obresult;
                 const setval_tyBM * setlocals;
                 const setval_tyBM * setnumbers;
                 const setval_tyBM * setconsts; objectval_tyBM * curvar;
                 value_tyBM curol;
                 value_tyBM oldrol; value_tyBM bodyv; value_tyBM msblov;
                 value_tyBM causev;
                 value_tyBM errorv;
    );
  objectval_tyBM *k_c_type = BMK_83kM1HtO8K3_6k0F2KYQT3W;
  const objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  const objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  const objectval_tyBM *k_result = BMK_7bD9VtDkGSn_7lxHeYuuFLR;
  const objectval_tyBM *k_closed = BMK_2TwOyPJxIz8_1rIeqaN7oRz;
  const objectval_tyBM *k_locals = BMK_24sSVIADeHm_0Sx34wQfG7W;
  const objectval_tyBM *k_numbers = BMK_32eKNcTZ9HN_80t0nk47Mha;
  const objectval_tyBM *k_body = BMK_7DQyvJFMOrC_9IfC3CtYknn;
  const objectval_tyBM *k_simple_routine_preparation =
    BMK_80060zKi6Un_3isCStegT8A;
  const objectval_tyBM *k_hset_object = BMK_8c9otZ4pwR6_55k81qyyYV2;
  const objectval_tyBM *k_assoc_object = BMK_6ZQ05nCv3Ys_8LA6B5LkZgm;
  const objectval_tyBM *k_blocks = BMK_2lCuMosXupr_5GAoqVgJ8PZ;
  const objectval_tyBM *k_statement_properties = BMK_0OM3NoUpOBd_1nzwCJKw54A;
  const objectval_tyBM *k_prepare_routine = BMK_6qi1DW0Ygkl_4Aqdxq4n5IV;
  const objectval_tyBM *k_in = BMK_0eMGYofuNVh_8ZP2mXdhtHO;
  const objectval_tyBM *k_modgenob = BMK_0Bl5ro9usp6_1Hll14QwC8f;
  const objectval_tyBM *k_miniscan_block = BMK_2gthNYOWogO_4sVTU1JbmUH;
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  // retrieve arguments
  _.recv = objectcast_BM (arg1);
  WEAKASSERT_BM (isobject_BM (_.recv));
  _.modgenob = objectcast_BM (arg2);
  _.prepvalset = setcast_BM (arg3);     /// unneeded, set of all routines
  WEAKASSERT_BM (_.modgenob != NULL);
  _.obmodhsetconst = objectcast_BM (objgetattr_BM (_.modgenob, k_constants));
  WEAKASSERT_BM (_.prepvalset != NULL);
  unsigned nbprep = setcardinal_BM (_.prepvalset);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ;  _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("start prepare_routine°basiclo_minifunction recv=%s modgenob=%s nbprep=%u obmodhsetconst=%s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.modgenob), nbprep,
     objectdbg2_BM (_.obmodhsetconst));
  _.tupargs = tuplecast_BM (objgetattr_BM (_.recv, k_arguments));
  _.tupclosed = tuplecast_BM (objgetattr_BM (_.recv, k_closed));
  _.obresult = objectcast_BM (objgetattr_BM (_.recv, k_result));
  _.setlocals = setcast_BM (objgetattr_BM (_.recv, k_locals));
  _.setnumbers = setcast_BM (objgetattr_BM (_.recv, k_numbers));
  _.setconsts = setcast_BM (objgetattr_BM (_.recv, k_constants));
  DBGPRINTF_BM
    ("prepare_routine°basiclo_minifunction recv=%s tupargs=%s tupclosed=%s obresult=%s"
     "\n.. setlocals=%s setnumbers=%s setconsts=%s",
     objectdbg_BM (_.recv),
     debug_outstr_value_BM ((value_tyBM) _.tupargs, CURFRAME_BM, 0),
     debug_outstr_value_BM ((value_tyBM) _.tupclosed, CURFRAME_BM, 0),
     objectdbg2_BM (_.obresult),
     debug_outstr_value_BM ((value_tyBM) _.setlocals, CURFRAME_BM, 0),
     debug_outstr_value_BM ((value_tyBM) _.setnumbers, CURFRAME_BM, 0),
     debug_outstr_value_BM ((value_tyBM) _.setconsts, CURFRAME_BM, 0));
  _.bodyv = objgetattr_BM (_.recv, k_body);
  if (!isobject_BM (_.bodyv))
    {
      FAILHERE (makenode1_BM (k_body, _.bodyv));
    }
  _.bodyob = objectcast_BM (_.bodyv);
  if (!isobject_BM (_.obresult))
    FAILHERE (makenode1_BM (k_result, _.recv));
  WEAKASSERT_BM (_.bodyob);
  WEAKASSERT_BM (isobject_BM (_.obmodhsetconst)
                 && objhashashsetpayl_BM (_.obmodhsetconst));
  objhashsetaddpayl_BM (_.obmodhsetconst, _.recv);
  _.routprepob = makeobj_BM ();
  objputclass_BM (_.routprepob,
                  (objectval_tyBM *) k_simple_routine_preparation);
  objputattr_BM (_.routprepob, k_in, _.recv);
  objputattr_BM (_.routprepob, k_modgenob, _.modgenob);
  unsigned nbargs = tuplesize_BM (_.tupargs);
  unsigned nbclosed = tuplesize_BM (_.tupclosed);
  unsigned nblocals = setcardinal_BM (_.setlocals);
  unsigned nbnumbers = setcardinal_BM (_.setnumbers);
  unsigned nbconsts = setcardinal_BM (_.setconsts);
  DBGPRINTF_BM
    ("start prepare_routine°basiclo_minifunction recv %s routprepob %s nbargs=%u nbclosed=%u nblocals=%u nbnumbers=%u nbconsts=%u",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob), nbargs, nbclosed,
     nblocals, nbnumbers, nbconsts);
  objputassocpayl_BM (_.routprepob,
                      2 + nbargs + nbclosed + nblocals + nbnumbers +
                      nbconsts);
  objtouchnow_BM (_.routprepob);
  //// check and bind the result
  if (_.obresult)
    {
      objlock_BM (_.obresult);
      _.typob = objectcast_BM (objgetattr_BM (_.obresult, k_c_type));
      objunlock_BM (_.obresult);
      if (_.typob != BMP_value && _.typob != BMP_object)
        FAILHERE (makenode1_BM (k_result, _.obresult));
      objassocaddattrpayl_BM (_.routprepob, _.obresult,
                              (value_tyBM) k_result);
    }
  /// bind the arguments
  for (unsigned argix = 0; argix < nbargs; argix++)
    {
      _.curvar = tuplecompnth_BM (_.tupargs, argix);
      _.curtypob = NULL;
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction argix=%u argum curvar=%s",
         argix, objectdbg_BM (_.curvar));
      _.oldrol = objassocgetattrpayl_BM (_.routprepob, _.curvar);
      if (_.oldrol)
        FAILHERE (makenode2_BM (k_arguments, _.curvar, _.oldrol));
      objlock_BM (_.curvar);
      _.curtypob = objectcast_BM (objgetattr_BM (_.curvar, k_c_type));
      objunlock_BM (_.curvar);
      if (_.curtypob != BMP_value)
        FAILHERE (makenode2_BM (k_arguments, _.curvar, _.oldrol));

      _.curol = (value_tyBM) makenode1_BM (k_arguments, taggedint_BM (argix));
      objassocaddattrpayl_BM (_.routprepob, _.curvar, _.curol);
      _.curol = NULL;
    }
  /// bind the closed
  for (unsigned cloix = 0; cloix < nbclosed; cloix++)
    {
      _.curvar = tuplecompnth_BM (_.tupclosed, cloix);
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction cloix=%u closed curvar=%s",
         cloix, objectdbg_BM (_.curvar));
      _.oldrol = objassocgetattrpayl_BM (_.routprepob, _.curvar);
      if (_.oldrol)
        FAILHERE (makenode2_BM (k_closed, _.curvar, _.oldrol));
      _.curol = (value_tyBM) makenode1_BM (k_closed, taggedint_BM (cloix));
      objassocaddattrpayl_BM (_.routprepob, _.curvar, _.curol);
      _.curol = NULL;
    }
  /// bind the locals
  for (unsigned locix = 0; locix < nblocals; locix++)
    {
      _.curvar = setelemnth_BM (_.setlocals, locix);
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction locix=%u local curvar=%s",
         locix, objectdbg_BM (_.curvar));
      _.oldrol = objassocgetattrpayl_BM (_.routprepob, _.curvar);
      if (_.oldrol)
        {
          FAILHERE (makenode2_BM (k_locals, _.curvar, _.oldrol));
        }
      _.curol = (value_tyBM) makenode1_BM (k_locals, taggedint_BM (locix));
      objassocaddattrpayl_BM (_.routprepob, _.curvar, _.curol);
      _.curol = NULL;
    }
  // bind the number vars
  for (unsigned numix = 0; numix < nbnumbers; numix++)
    {
      _.curvar = setelemnth_BM (_.setnumbers, numix);
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction numix=%u number curvar=%s",
         numix, objectdbg_BM (_.curvar));
      _.oldrol = objassocgetattrpayl_BM (_.routprepob, _.curvar);
      if (_.oldrol)
        {
          FAILHERE (makenode2_BM (k_numbers, _.curvar, _.oldrol));
        }
      _.curol = (value_tyBM) makenode1_BM (k_numbers, taggedint_BM (numix));
      objassocaddattrpayl_BM (_.routprepob, _.curvar, _.curol);
      _.curol = NULL;
    }
  // bind the constants
  for (unsigned cstix = 0; cstix < nbconsts; cstix++)
    {
      _.curvar = setelemnth_BM (_.setconsts, cstix);
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction cstix=%u constant curvar=%s",
         cstix, objectdbg_BM (_.curvar));
      _.oldrol = objassocgetattrpayl_BM (_.routprepob, _.curvar);
      if (_.oldrol)
        {
          FAILHERE (makenode2_BM (k_constants, _.curvar, _.oldrol));
        }
      _.curol = (value_tyBM) makenode1_BM (k_constants, taggedint_BM (cstix));
      objassocaddattrpayl_BM (_.routprepob, _.curvar, _.curol);
      objhashsetaddpayl_BM (_.obmodhsetconst, _.curvar);
      _.curol = NULL;
    }
  _.obhsetblock = makeobj_BM ();
  objputhashsetpayl_BM (_.obhsetblock, 15);
  objputclass_BM (_.obhsetblock, (objectval_tyBM *) k_hset_object);
  objputattr_BM (_.routprepob, k_blocks, _.obhsetblock);
  objputattr_BM (_.routprepob, k_prepare_routine, _.recv);
  objputattr_BM (_.routprepob, k_in, _.modgenob);
  objputattr_BM (_.obhsetblock, k_in, _.routprepob);
  _.stmtpropob = makeobj_BM ();
  objputassocpayl_BM (_.stmtpropob, 15);
  objputclass_BM (_.stmtpropob, k_assoc_object);
  objputattr_BM (_.stmtpropob, k_in, _.routprepob);
  objputattr_BM (_.routprepob, k_statement_properties, _.stmtpropob);
  objtouchnow_BM (_.obhsetblock);
  objtouchnow_BM (_.routprepob);
  DBGPRINTF_BM
    ("prepare_routine°basiclo_minifunction before miniscan_block recv %s routprep %s bodyob %s of %s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob),
     objectdbg2_BM (_.bodyob), objectdbg3_BM (objclass_BM (_.bodyob)));
  {
    objlock_BM (_.bodyob);
    if (!objectisinstance_BM (_.bodyob, k_basiclo_block))
      {
        DBGPRINTF_BM
          ("prepare_routine°basiclo_minifunction recv %s bad bodyob %s of %s",
           objectdbg_BM (_.recv), objectdbg_BM (_.bodyob),
           objectdbg3_BM (objclass_BM (_.bodyob)));
        FAILHERE (makenode2_BM (k_body, _.bodyob, _.recv));
      }
    DBGPRINTF_BM
      ("prepare_routine°basiclo_minifunction recv %s before send miniscan_block to body %s routprepob %s",
       objectdbg_BM (_.recv), objectdbg1_BM (_.bodyob),
       objectdbg2_BM (_.routprepob));
    _.msblov =
      send3_BM (_.bodyob, k_miniscan_block, CURFRAME_BM, _.routprepob,
                taggedint_BM (0), _.recv);
    objunlock_BM (_.bodyob);
  }
  if (!_.msblov)
    {
      DBGPRINTF_BM
        ("prepare_routine°basiclo_minifunction failed miniscan_block bodyob=%s of %s",
         objectdbg_BM (_.bodyob), objectdbg1_BM (objclass_BM (_.bodyob)));
      FAILHERE (makenode1_BM (k_miniscan_block, _.bodyob));
    }
  DBGPRINTF_BM
    ("prepare_routine°basiclo_minifunction after miniscan_block recv %s routprep %s bodyob=%s msblov=%s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob),
     objectdbg2_BM (_.bodyob),
     debug_outstr_value_BM (_.msblov, CURFRAME_BM, 0));
  LOCALRETURN_BM (_.routprepob);
failure:
  _.errorv = (value_tyBM)
    makenode4_BM (k_prepare_routine, _.recv, _.modgenob,
                  (value_tyBM) _.prepvalset, _.causev);
  DBGPRINTF_BM
    ("failure prepare_routine°basiclo_minifunction  failin %d errorv %s",
     failin, debug_outstr_value_BM (_.errorv, CURFRAME_BM, 0));
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end prepare_routine°basiclo_minifunction  _07qYMXftJRR_9dde2ASz4e9  */





// return the ctype of a variable
extern objectval_tyBM *miniscan_var_BM (objectval_tyBM * varob,
                                        objectval_tyBM * routprepob,
                                        int depth, objectval_tyBM * fromob,
                                        struct stackframe_stBM *stkf);
// return the ctype of an expression
extern objectval_tyBM *miniscan_expr_BM (value_tyBM expv,
                                         objectval_tyBM * routprepob,
                                         int depth, objectval_tyBM * fromob,
                                         struct stackframe_stBM *stkf);

// test if two types are compatible and return their common supertype
extern objectval_tyBM *miniscan_compatype_BM (objectval_tyBM * typ1ob,
                                              objectval_tyBM * typ2ob,
                                              struct stackframe_stBM *stkf);



////////////////////////////////////////////////////////////////

objectval_tyBM *
miniscan_compatype_BM (objectval_tyBM * typ1ob, objectval_tyBM * typ2ob,
                       struct stackframe_stBM *stkf)
{
  if (!typ1ob || !typ2ob)
    return false;
  WEAKASSERT_BM (isobject_BM (typ1ob));
  WEAKASSERT_BM (isobject_BM (typ2ob));
  if (typ1ob == typ2ob)
    return typ1ob;
  objectval_tyBM *k_miniscan_compatype = BMK_82pYC6bEP7E_3cfHx6ELZFi;
  objectval_tyBM *k_object = BMK_7T9OwSFlgov_0wVJaK1eZbn;
  objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  //objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
  //objectval_tyBM *k_string = BMK_4T8am97muLl_5969SR22Ecq;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ k_miniscan_compatype,
                 objectval_tyBM * typ1ob;
                 objectval_tyBM * typ2ob;
    );
  _.typ1ob = typ1ob;
  _.typ2ob = typ2ob;
  if ((_.typ1ob == k_object && _.typ2ob == k_value)
      || (_.typ1ob == k_value && _.typ2ob == k_object))
    LOCALRETURN_BM (k_value);
  LOCALRETURN_BM (NULL);
}                               /* end miniscan_compatype_BM */



objectval_tyBM *
miniscan_var_BM (objectval_tyBM * varob,
                 objectval_tyBM * routprepob, int depth,
                 objectval_tyBM * fromob, struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_miniscan_var = BMK_6jh60mO0Cgd_84B0HiNphqA;
  objectval_tyBM *k_result = BMK_7bD9VtDkGSn_7lxHeYuuFLR;
  objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  objectval_tyBM *k_numbers = BMK_32eKNcTZ9HN_80t0nk47Mha;
  objectval_tyBM *k_locals = BMK_24sSVIADeHm_0Sx34wQfG7W;
  objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
  const objectval_tyBM *k_simple_routine_preparation =
    BMK_80060zKi6Un_3isCStegT8A;
  int failin = -1;
#define FAILHERE() do { failin = __LINE__ ; goto failure; } while(0)
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ k_miniscan_var,
                 objectval_tyBM * varob;
                 objectval_tyBM * routprepob; objectval_tyBM * fromob;
                 value_tyBM vrolv; objectval_tyBM * rolconnob;
                 value_tyBM errorv;
    );
  _.varob = objectcast_BM (varob);
  _.routprepob = objectcast_BM (routprepob);
  _.fromob = objectcast_BM (fromob);
  if (!_.varob)
    FAILHERE ();
  if (!_.routprepob)
    FAILHERE ();
  if (!_.fromob)
    FAILHERE ();
  DBGPRINTF_BM
    ("miniscan_var start varob=%s routprepob=%s depth#%d fromob=%s",
     objectdbg_BM (_.varob), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromob));
  WEAKASSERT_BM (objhasassocpayl_BM (_.routprepob));
  _.vrolv = objassocgetattrpayl_BM (_.routprepob, _.varob);
  DBGPRINTF_BM ("miniscan_var vrol=%s", //
                debug_outstr_value_BM (_.vrolv, CURFRAME_BM, 0));
  if (isnode_BM (_.vrolv))
    {
      _.rolconnob = nodeconn_BM (_.vrolv);
      if (_.rolconnob == k_arguments || _.rolconnob == k_locals)
        {
          LOCALRETURN_BM (k_value);
        }
      else if (_.rolconnob == k_constants)
        {
          LOCALRETURN_BM (BMP_object);
        }
      else if (_.rolconnob == k_numbers)
        {
          LOCALRETURN_BM (k_int);
        }
      else
        FAILHERE ();
    }
  else if (_.vrolv == k_result)
    {
      if (objectisinstance_BM (_.routprepob, k_simple_routine_preparation))
        LOCALRETURN_BM (k_value);
      else
        FAILHERE ();
    }
  else
    FAILHERE ();
#warning incomplete miniscan_var_BM
  DBGPRINTF_BM ("miniscan_var end varob=%s", objectdbg_BM (_.varob));
  LOCALRETURN_BM (NULL);
failure:
  _.errorv = (value_tyBM)
    makenode4_BM (k_miniscan_var, varob, routprepob, taggedint_BM (depth),
                  fromob);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end miniscan_var_BM */


objectval_tyBM *
miniscan_expr_BM (value_tyBM expv, objectval_tyBM * routprepob,
                  int depth, objectval_tyBM * fromob,
                  struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_miniscan_expr = BMK_7k3xb0vred0_9ZRHcZmhw77;
  objectval_tyBM *k_miniscan_node_conn = BMK_5EGLdtUAQxA_1nebCsDKqOF;
  objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
  objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  objectval_tyBM *k_string = BMK_4T8am97muLl_5969SR22Ecq;
  objectval_tyBM *k_basiclo_connective = BMK_3DQ7z3EuAiT_4faSRNsy2lr;
  objectval_tyBM *k_exclam = BMK_0e54seiZEXF_1Myf620cHoB;
  objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  objectval_tyBM *k_simple_routine_preparation = BMK_80060zKi6Un_3isCStegT8A;
  objectval_tyBM *k_simple_module_generation = BMK_2HlKptD03wA_7JJCG7lN5nS;
  // objectval_tyBM *k_hset_object = BMK_8c9otZ4pwR6_55k81qyyYV2;
  objectval_tyBM *k_modgenob = BMK_0Bl5ro9usp6_1Hll14QwC8f;
  int failin = -1;
#define FAILHERE() do { failin = __LINE__ ; goto failure; } while(0)
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ k_miniscan_expr,
                 value_tyBM expv;
                 value_tyBM resv; objectval_tyBM * routprepob;
                 objectval_tyBM * modgenob; objectval_tyBM * fromob;
                 objectval_tyBM * expob; objectval_tyBM * connob;
                 objectval_tyBM * exclamob; objectval_tyBM * consthsetobj;
                 value_tyBM avalv; objectval_tyBM * typob; value_tyBM errorv;
                 value_tyBM exclamsonv;
    );
  _.expv = expv;
  _.routprepob = objectcast_BM (routprepob);
  _.fromob = objectcast_BM (fromob);
  if (!_.routprepob)
    FAILHERE ();
  if (!_.fromob)
    FAILHERE ();
  DBGPRINTF_BM ("miniscan_expr start expv=%s routprepob=%s depth#%d fromob=%s", //
                debug_outstr_value_BM (_.expv, CURFRAME_BM, 0), //
                objectdbg1_BM (_.routprepob), depth,
                objectdbg2_BM (_.fromob));
  WEAKASSERT_BM (objectisinstance_BM (_.routprepob,
                                      k_simple_routine_preparation));
  _.modgenob = objgetattr_BM (_.routprepob, k_modgenob);
  WEAKASSERT_BM (objectisinstance_BM (_.modgenob,
                                      k_simple_module_generation));
  int ke = valtype_BM (_.expv);
  switch (ke)
    {
    case tyNone_BM:
      LOCALRETURN_BM (k_value);
    case tyInt_BM:
      LOCALRETURN_BM (k_int);
    case tyString_BM:
      LOCALRETURN_BM (k_string);
    case tySet_BM:
      FAILHERE ();
    case tyTuple_BM:
      FAILHERE ();
    case tyClosure_BM:
      FAILHERE ();
    case tyUnspecified_BM:
      FAILHERE ();
    case tyObject_BM:
      {
        _.expob = objectcast_BM (_.expv);
        _.avalv = objassocgetattrpayl_BM (_.routprepob, _.expob);
        DBGPRINTF_BM ("miniscan_expr expob=%s avalv=%s",
                      objectdbg_BM (_.expob),
                      debug_outstr_value_BM (_.avalv, CURFRAME_BM, 0));
        if (_.avalv != NULL)
          {
            _.typob =
              miniscan_var_BM (_.expob, _.routprepob, depth, _.fromob,
                               CURFRAME_BM);
            DBGPRINTF_BM ("miniscan_expr var expob=%s typob=%s",
                          objectdbg_BM (_.expob), objectdbg1_BM (_.typob));
            LOCALRETURN_BM (_.typob);
          }
        else
          FAILHERE ();
        break;
      }
    case tyNode_BM:
      {
        _.connob = nodeconn_BM (_.expv);
        unsigned arity = nodewidth_BM (_.expv);
        DBGPRINTF_BM
          ("miniscan_expr node expv=%s connob=%s arity#%d",
           debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
           objectdbg_BM (_.connob), arity);
        if (_.connob == k_exclam && arity == 1)
          {
            _.exclamsonv = nodenthson_BM (_.expv, 0);
            _.exclamob = objectcast_BM (_.exclamsonv);
            if (_.exclamob)
              {
                _.consthsetobj =
                  objectcast_BM (objgetattr_BM (_.modgenob, k_constants));
                DBGPRINTF_BM
                  ("miniscan_expr exclamob=%s routprepob=%s consthsetobj=%s",
                   objectdbg_BM (_.exclamob), objectdbg1_BM (_.routprepob),
                   objectdbg2_BM (_.consthsetobj));
                WEAKASSERT_BM (objhashashsetpayl_BM (_.consthsetobj));
                objhashsetaddpayl_BM (_.consthsetobj, _.exclamob);
                LOCALRETURN_BM (BMP_object);
              }
            else if (istaggedint_BM (_.exclamsonv))
              LOCALRETURN_BM (BMP_value);
            else
              FAILHERE ();
          }
        {
          objlock_BM (_.connob);
          if (objectisinstance_BM (_.connob, k_basiclo_connective))
            {
              DBGPRINTF_BM
                ("miniscan_expr miniscan_node_conn->%s arity %d routprepob %s fromob %s before",
                 objectdbg_BM (_.connob), arity, objectdbg1_BM (_.routprepob),
                 objectdbg2_BM (_.fromob));
              _.resv = send4_BM (_.connob, k_miniscan_node_conn,        //
                                 CURFRAME_BM,   //
                                 _.routprepob,
                                 taggedint_BM (depth), _.expv, _.fromob);
              DBGPRINTF_BM ("miniscan_expr miniscan_node_conn->%s done resv=%s",        //
                            objectdbg_BM (_.connob),    //
                            debug_outstr_value_BM (_.resv, CURFRAME_BM, 0));
              if (!_.resv)
                FAILHERE ();
              LOCALRETURN_BM (_.resv);
            }
          objunlock_BM (_.connob);
        }
        break;
      }
    default:
      FAILHERE ();
    }
#warning incomplete miniscan_expr_BM
  DBGPRINTF_BM ("miniscan_expr end expv=%s",    //
                debug_outstr_value_BM (_.expv, CURFRAME_BM, 0));
  LOCALRETURN_BM (NULL);
failure:
  DBGPRINTF_BM ("miniscan_expr failin %d", failin);
  _.errorv = (value_tyBM)
    makenode4_BM (k_miniscan_expr, _.expv, _.routprepob,
                  taggedint_BM (depth), _.fromob);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end miniscan_expr_BM */




////////////////////////////////////////////////////////////////
// for the method miniscan_stmt°basiclo_cond 
extern objrout_sigBM ROUTINEOBJNAME_BM (_0zzJJsAL6Qm_2uw3eoWQHEq);
value_tyBM
ROUTINEOBJNAME_BM (_0zzJJsAL6Qm_2uw3eoWQHEq)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving cond
 const value_tyBM arg2,         // routine preparation
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // containingblock
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv;
                 objectval_tyBM * routprepob; objectval_tyBM * fromblockob;
                 objectval_tyBM * compob; objectval_tyBM * seqcompob;
                 value_tyBM testexpv; value_tyBM resv;
                 value_tyBM errorv;
                 value_tyBM causev;
    );
  objectval_tyBM *k_basiclo_when = BMK_3fvdRZNCmJS_5bTAPr83mXg;
  objectval_tyBM *k_test = BMK_2j84OTHlFdJ_1pMyQfgsmAz;
  // objectval_tyBM *k_miniscan_expr = BMK_7k3xb0vred0_9ZRHcZmhw77;
  const objectval_tyBM *k_miniscan_block = BMK_2gthNYOWogO_4sVTU1JbmUH;
  const objectval_tyBM *k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_nb_conds = BMK_8dLpuaNoSGN_2tdmkpINCsu;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  int depth = 0;
  _.recv = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  depth = getint_BM (arg3);
  _.fromblockob = objectcast_BM (arg4);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev= (value_tyBM)(Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_cond start recv=%s routprepob=%s depth#%d fromblockob=%s start",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromblockob));
  objlock_BM (_.recv);
  unsigned nbsons = objnbcomps_BM (_.recv);
  int nbconds = getint_BM (objgetattr_BM (_.recv, k_nb_conds));
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_cond recv=%s nbconds=%d nbsons=%u",
     objectdbg_BM (_.recv), nbconds, nbsons);
  WEAKASSERT_BM ((int) nbconds <= (int) nbsons);
  for (int ix = 0; ix < nbconds; ix++)
    {
      _.compob = objectcast_BM (objgetcomp_BM (_.recv, ix));
      DBGPRINTF_BM
        ("miniscan_stmt°basiclo_cond recv=%s ix=%u compob=%s",
         objectdbg_BM (_.recv), ix, objectdbg1_BM (_.compob));
      WEAKASSERT_BM (isobject_BM (_.compob));
      objlock_BM (_.compob);
      if (objectisinstance_BM (_.compob, k_basiclo_when))
        {
          _.testexpv = objgetattr_BM (_.compob, k_test);
          miniscan_expr_BM (_.testexpv, _.routprepob, depth + 1, _.recv,
                            CURFRAME_BM);
          unsigned nbsubcomp = objnbcomps_BM (_.compob);
          for (unsigned cix = 0; cix < nbsubcomp; cix++)
            {
              _.seqcompob = objectcast_BM (objgetcomp_BM (_.compob, cix));
              WEAKASSERT_BM (isobject_BM (_.seqcompob));
              DBGPRINTF_BM
                ("miniscan_stmt°basiclo_cond recv=%s ix=%u compob=%s cix=%u seqcomp=%s",
                 objectdbg_BM (_.recv), ix, objectdbg1_BM (_.compob), cix,
                 objectdbg2_BM (_.seqcompob));
              objlock_BM (_.seqcompob);
              if (objectisinstance_BM (_.seqcompob, k_basiclo_block))
                {
                  DBGPRINTF_BM
                    ("miniscan_stmt°basiclo_cond seqcompob %s is block of %s",
                     objectdbg_BM (_.seqcompob),
                     objectdbg1_BM (objclass_BM (_.seqcompob)));
                  _.resv =
                    send3_BM (_.seqcompob, k_miniscan_block,
                              CURFRAME_BM, _.routprepob,
                              taggedint_BM (depth + 1), _.compob);
                  DBGPRINTF_BM
                    ("miniscan_stmt°basiclo_cond seqcompob after miniscan_block->%s resv=%s",
                     objectdbg_BM (_.seqcompob),
                     debug_outstr_value_BM (_.resv, CURFRAME_BM, 0));
                  if (!_.resv)
                    FAILHERE (makenode3_BM
                              (k_miniscan_block, _.seqcompob,
                               taggedint_BM (cix), taggedint_BM (ix)));
                }
              else if (objectisinstance_BM (_.seqcompob, k_basiclo_statement))
                {
                  DBGPRINTF_BM
                    ("miniscan_stmt°basiclo_cond seqcompob %s is statement of %s",
                     objectdbg_BM (_.seqcompob),
                     objectdbg1_BM (objclass_BM (_.seqcompob)));
                  _.resv =
                    send3_BM (_.seqcompob, k_miniscan_stmt,
                              CURFRAME_BM, _.routprepob,
                              taggedint_BM (depth + 1), _.compob);
                  DBGPRINTF_BM
                    ("miniscan_stmt°basiclo_cond seqcompob after miniscan_stmt->%s resv=%s",
                     objectdbg_BM (_.seqcompob),
                     debug_outstr_value_BM (_.resv, CURFRAME_BM, 0));
                  if (!_.resv)
                    FAILHERE (makenode3_BM
                              (k_miniscan_stmt, _.seqcompob,
                               taggedint_BM (cix), taggedint_BM (ix)));
                }
              objunlock_BM (_.seqcompob);

            }
        }
      else
        FAILHERE (makenode2_BM (k_curcomp, _.compob, taggedint_BM (ix)));
      objunlock_BM (_.compob);
      DBGPRINTF_BM
        ("miniscan_stmt°basiclo_cond recv=%s ix=%u done compob=%s",
         objectdbg_BM (_.recv), ix, objectdbg1_BM (_.compob));
    }
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_cond recv=%s remaining %d from nbconds %d to nbsons %d",
     objectdbg_BM (_.recv), nbsons - nbconds, nbconds, nbsons);
  for (unsigned ix = nbconds; ix < nbsons; ix++)
    {
      _.compob = objectcast_BM (objgetcomp_BM (_.recv, ix));
      DBGPRINTF_BM ("miniscan_stmt°basiclo_cond recv=%s ix=%u compob=%s",
                    objectdbg_BM (_.recv), ix, objectdbg1_BM (_.compob));
      WEAKASSERT_BM (isobject_BM (_.compob));
      objlock_BM (_.compob);
      if (objectisinstance_BM (_.compob, k_basiclo_statement))
        {
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_cond recv=%s compob %s #%d is statement",
             objectdbg_BM (_.recv), objectdbg1_BM (_.compob), ix);
          _.resv =
            send3_BM (_.compob, k_miniscan_stmt, CURFRAME_BM, _.routprepob,
                      taggedint_BM (depth + 1), _.recv);
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_cond after miniscan_stmt->%s resv=%s",
             objectdbg_BM (_.compob), debug_outstr_value_BM (_.resv,
                                                             CURFRAME_BM, 0));
          if (!_.resv)
            FAILHERE (makenode2_BM
                      (k_miniscan_stmt, _.compob, taggedint_BM (ix)));
        }
      else if (objectisinstance_BM (_.compob, k_basiclo_block))
        {
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_cond recv=%s compob %s #%d is block",
             objectdbg_BM (_.recv), objectdbg1_BM (_.compob), ix);
          _.resv =
            send3_BM (_.compob, k_miniscan_block, CURFRAME_BM, _.routprepob,
                      taggedint_BM (depth + 1), _.recv);
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_cond after miniscan_block->%s resv=%s",
             objectdbg_BM (_.compob), debug_outstr_value_BM (_.resv,
                                                             CURFRAME_BM, 0));
          if (!_.resv)
            FAILHERE (makenode2_BM
                      (k_miniscan_block, _.compob, taggedint_BM (ix)));
        }
      else
        FAILHERE (makenode2_BM (k_curcomp, _.compob, taggedint_BM (ix)));

    }
  objunlock_BM (_.recv);
  DBGPRINTF_BM ("miniscan_stmt°basiclo_cond ending recv=%s",
                objectdbg_BM (_.recv));
  LOCALRETURN_BM (_.recv);
failure:
  DBGPRINTF_BM ("miniscan_stmt°basiclo_cond  failin %d recv=%s", failin,
                objectdbg_BM (_.recv));
  _.errorv = (value_tyBM)
    makenode4_BM (k_miniscan_stmt, _.recv, _.routprepob, taggedint_BM (depth),
                  _.fromblockob);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end routine miniscan_stmt°basiclo_cond _0zzJJsAL6Qm_2uw3eoWQHEq */




// miniscan_stmt°basiclo_assign _7LNRlilrowp_0GG6ZLUFovu
extern objrout_sigBM ROUTINEOBJNAME_BM (_7LNRlilrowp_0GG6ZLUFovu);

value_tyBM
ROUTINEOBJNAME_BM (_7LNRlilrowp_0GG6ZLUFovu)    //miniscan_stmt°basiclo_assign
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving assign
 const value_tyBM arg2,         // routine preparation
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // containingblock
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_7LNRlilrowp_0GG6ZLUFovu,
                 objectval_tyBM * recv; //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromblockob;  //
                 objectval_tyBM * destob;       //
                 value_tyBM srcexpv;    //
                 objectval_tyBM * vartypob;     //
                 objectval_tyBM * srctypob;     //
                 value_tyBM resv;       //
    );
  int depth = 0;
  bool ok = false;
  _.recv = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  depth = getint_BM (arg3);
  _.fromblockob = objectcast_BM (arg4);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_assign start recv=%s routprepob=%s depth#%d fromblockob=%s start",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromblockob));
  objlock_BM (_.recv);
  WEAKASSERT_BM (objnbcomps_BM (_.recv) == 2);
  _.destob = objectcast_BM (objgetcomp_BM (_.recv, 0));
  _.srcexpv = objgetcomp_BM (_.recv, 1);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_assign recv=%s destob=%s of %s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.destob),
     objectdbg2_BM (objclass_BM (_.destob)));
  WEAKASSERT_BM (isobject_BM (_.destob));
  _.vartypob = miniscan_var_BM (_.destob, _.routprepob, depth + 1, _.recv,
                                CURFRAME_BM);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_assign after miniscan_var->%s vartypob=%s",
     objectdbg_BM (_.destob), objectdbg1_BM (_.vartypob));
  DBGPRINTF_BM ("miniscan_stmt°basiclo_assign recv=%s srcexpv=%s", objectdbg_BM (_.recv),      //
                debug_outstr_value_BM (_.srcexpv, CURFRAME_BM, 0));
  _.srctypob = miniscan_expr_BM (_.srcexpv, _.routprepob, depth + 1, _.recv,
                                 CURFRAME_BM);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_assign after miniscan_expr->%s srctypob=%s",
     debug_outstr_value_BM (_.srcexpv, CURFRAME_BM, 0),
     objectdbg_BM (_.srctypob));
  objunlock_BM (_.recv);
  if (_.srctypob == _.vartypob && _.srctypob != NULL)
    ok = true;
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_assign end recv=%s ok=%s",
     objectdbg_BM (_.recv), ok ? "true" : "false");
  if (ok)
    LOCALRETURN_BM (_.recv);
  else
    LOCALRETURN_BM (NULL);
}                               /* end miniscan_stmt°basiclo_assign _7LNRlilrowp_0GG6ZLUFovu */


// miniscan_stmt°basiclo_exit  _23F5sZIfO5Y_5m9O2FPHdzX

extern objrout_sigBM ROUTINEOBJNAME_BM (_23F5sZIfO5Y_5m9O2FPHdzX);

value_tyBM
ROUTINEOBJNAME_BM (_23F5sZIfO5Y_5m9O2FPHdzX)    // miniscan_stmt°basiclo_exit 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         //stmtob recieving exit 
 const value_tyBM arg2,         //routprepob
 const value_tyBM arg3,         //depth
 const value_tyBM arg4,         //fromob
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  objectval_tyBM *k_exit = BMK_41gbFesxqzD_3l56OLiNdl2;
  objectval_tyBM *k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  objectval_tyBM *k_blocks = BMK_2lCuMosXupr_5GAoqVgJ8PZ;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_23F5sZIfO5Y_5m9O2FPHdzX,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * exitob;       //
                 objectval_tyBM * hsetblockob;  //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
    );
  int depth = 0;
  bool ok = false;
  _.stmtob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  depth = getint_BM (arg3);
  _.fromob = objectcast_BM (arg4);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_exit start stmtob=%s routprepob=%s depth#%d fromob=%s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromob));
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev= (value_tyBM)(Cause); goto failure; } while(0)
  WEAKASSERT_BM (_.stmtob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (arg3) && depth >= 0);
  WEAKASSERT_BM (_.fromob);
  _.exitob = objectcast_BM (objgetattr_BM (_.stmtob, k_exit));
  _.hsetblockob = objectcast_BM (objgetattr_BM (_.routprepob, k_blocks));
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_exit stmtob=%s routprepob=%s exitob=%s hsetblockob=%s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),
     objectdbg2_BM (_.exitob), objectdbg3_BM (_.hsetblockob));
  if (!isobject_BM (_.exitob))
    FAILHERE (k_exit);
  if (!isobject_BM (_.hsetblockob))
    FAILHERE (k_blocks);
  if (!objhashashsetpayl_BM (_.hsetblockob))
    FAILHERE (makenode1_BM (k_blocks, _.hsetblockob));
  if (!objhashsetcontainspayl_BM (_.hsetblockob, _.exitob))
    {
      ("miniscan_stmt°basiclo_exit stmtob=%s exitob=%s not in hsetblockob=%s", objectdbg_BM (_.stmtob), objectdbg1_BM (_.exitob), objectdbg2_BM (_.hsetblockob));
      FAILHERE (makenode1_BM (k_exit, _.exitob));
    }
  LOCALRETURN_BM (_.exitob);
failure:
  DBGPRINTF_BM ("miniscan_stmt°basiclo_exit failin %d stmtob=%s causev=%s routprepob=%s",      //
                failin, objectdbg_BM (_.stmtob),        //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0),       //
                objectdbg1_BM (_.routprepob));
  _.errorv = (value_tyBM)
    makenode5_BM (k_miniscan_stmt, _.stmtob, _.routprepob,
                  taggedint_BM (depth), _.fromob, _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end miniscan_stmt°basiclo_exit  _23F5sZIfO5Y_5m9O2FPHdzX */



// miniscan_node_conn°basiclo_primitive  _1vuSUudDrEr_9UjFr4Pcy8r
extern objrout_sigBM ROUTINEOBJNAME_BM (_1vuSUudDrEr_9UjFr4Pcy8r);

value_tyBM
ROUTINEOBJNAME_BM (_1vuSUudDrEr_9UjFr4Pcy8r)    // miniscan_node_conn°basiclo_primitive
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // connob
 const value_tyBM arg2,         // routprepob
 const value_tyBM arg3,         // depthv
 const value_tyBM arg4,         // expv
 const quasinode_tyBM * restargs /*fromob. */ )
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_1vuSUudDrEr_9UjFr4Pcy8r,
                 objectval_tyBM * connob;       //
                 objectval_tyBM * routprepob;   //
                 value_tyBM expv;       //
                 objectval_tyBM * fromob;       //
                 value_tyBM connargsv;
                 objectval_tyBM * restypob; value_tyBM resultv;
                 value_tyBM errorv;
                 value_tyBM cursonv; objectval_tyBM * curargob;
                 objectval_tyBM * curtypob; objectval_tyBM * curargctypob;
                 objectval_tyBM * connrestypob; objectval_tyBM * curcomptypob;
                 value_tyBM extraerrorv;
    );
  int failin = -1;
#define FAILHERE(Xtra) do { failin = __LINE__ ; _.extraerrorv = (value_tyBM)(Xtra); goto failure; } while(0)
  objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  objectval_tyBM *k_result_type = BMK_8oZ9fPJGhmS_24c2sSYsdr2;
  objectval_tyBM *k_miniscan_node_conn = BMK_5EGLdtUAQxA_1nebCsDKqOF;
  objectval_tyBM *k_arity = BMK_6fPPUXnZhy5_8Lh5DOOe0Nu;
  objectval_tyBM *k_c_type = BMK_83kM1HtO8K3_6k0F2KYQT3W;
  _.connob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  int depth = getint_BM (arg3);
  _.expv = arg4;
  _.fromob = objectcast_BM (treenthson_BM ((value_tyBM) restargs, 0));
  DBGPRINTF_BM ("miniscan_node_conn°basiclo_primitive start connob %s" //
                "\n... routprepob %s depth %d expv %s fromob %s",       //
                objectdbg_BM (_.connob), objectdbg1_BM (_.routprepob), depth,   //
                debug_outstr_value_BM (_.expv, CURFRAME_BM, 0), //
                objectdbg2_BM (_.fromob));
  if (!_.routprepob)
    FAILHERE (NULL);
  if (!_.fromob)
    FAILHERE (NULL);
  {
    objlock_BM (_.connob);
    _.connargsv = objgetattr_BM (_.connob, k_arguments);
    _.connrestypob = objectcast_BM (objgetattr_BM (_.connob, k_result_type));
    objunlock_BM (_.connob);
  }
  DBGPRINTF_BM ("miniscan_node_conn°basiclo_primitive  connob %s"      //
                "\n... connargs %s connrestyp %s",      //
                objectdbg_BM (_.connob),        //
                debug_outstr_value_BM (_.connargsv, CURFRAME_BM, 0),    //
                objectdbg1_BM (_.connrestypob));        //
  if (!istuple_BM (_.connargsv))
    FAILHERE (k_arguments);
  unsigned nbconnargs = tuplesize_BM (_.connargsv);
  unsigned nbexpargs = nodewidth_BM (_.expv);
  if (nbconnargs != nbexpargs)
    FAILHERE (k_arity);
  if (!isobject_BM (_.connrestypob))
    FAILHERE (k_result_type);
  for (unsigned ix = 0; ix < nbconnargs; ix++)
    {
      _.cursonv = nodenthson_BM (_.expv, ix);
      _.curargob = tuplecompnth_BM (_.connargsv, ix);
      _.curargctypob = NULL;
      _.curtypob = NULL;
      objlock_BM (_.curargob);
      _.curargctypob = objgetattr_BM (_.curargob, k_c_type);
      objunlock_BM (_.curargob);
      DBGPRINTF_BM ("miniscan_node_conn°basiclo_primitive ix#%d cursonv=%s curargob=%s", ix,   //
                    debug_outstr_value_BM (_.cursonv, CURFRAME_BM, 0),  //
                    objectdbg_BM (_.curargob));
      _.curtypob =
        miniscan_expr_BM (_.cursonv, _.routprepob, depth + 1, _.fromob,
                          CURFRAME_BM);
      DBGPRINTF_BM ("miniscan_node_conn°basiclo_primitive ix#%d "      //
                    "curtypob %s curargob=%s curargctypob=%s",  //
                    ix, objectdbg_BM (_.curtypob), objectdbg1_BM (_.curargob),  //
                    objectdbg2_BM (_.curargctypob));
      _.curcomptypob = miniscan_compatype_BM (_.curargctypob, _.curtypob,
                                              CURFRAME_BM);
      if (!_.curcomptypob)
        FAILHERE (makenode1_BM (k_arguments, taggedint_BM (ix)));
    }
  DBGPRINTF_BM
    ("miniscan_node_conn°basiclo_primitive done expv=%s result connrestypob=%s",
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg_BM (_.connrestypob));
  LOCALRETURN_BM (_.connrestypob);
failure:
  DBGPRINTF_BM ("miniscan_node_conn°basiclo_primitive failin %d", failin);
  _.errorv = (value_tyBM)
    makenode5_BM (k_miniscan_node_conn, _.expv, _.routprepob,
                  taggedint_BM (depth), _.fromob, _.extraerrorv);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end miniscan_node_conn°basiclo_primitive  _1vuSUudDrEr_9UjFr4Pcy8r */



// miniscan_stmt°basiclo_return _7vlMCZ0yvva_6tx0lFlqBG8
extern objrout_sigBM ROUTINEOBJNAME_BM (_7vlMCZ0yvva_6tx0lFlqBG8);

value_tyBM
ROUTINEOBJNAME_BM (_7vlMCZ0yvva_6tx0lFlqBG8)    // miniscan_stmt°basiclo_return
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recv
 const value_tyBM arg2,         // routprep
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // containingblock
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_7vlMCZ0yvva_6tx0lFlqBG8,
                 objectval_tyBM * recv; objectval_tyBM * routprepob;
                 objectval_tyBM * fromblockob; value_tyBM retexpv;
                 objectval_tyBM * retypob; value_tyBM resultv;
                 value_tyBM errorv;
    );
  int failin = -1;
#define FAILHERE() do { failin = __LINE__ ; goto failure; } while(0)
  objectval_tyBM *k_return = BMK_2DH0ucElTgh_62vxjxLcfev;
  objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  int depth = 0;
  _.recv = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  depth = getint_BM (arg3);
  _.fromblockob = objectcast_BM (arg4);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_return start recv=%s routprepob=%s depth#%d fromblockob=%s start",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromblockob));
  objlock_BM (_.recv);
  _.retexpv = objgetattr_BM (_.recv, k_return);
  objunlock_BM (_.recv);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_return recv=%s retexpv=%s",
     objectdbg_BM (_.recv),
     debug_outstr_value_BM (_.retexpv, CURFRAME_BM, 0));
  _.retypob = miniscan_expr_BM (_.retexpv, _.routprepob, depth, _.recv,
                                CURFRAME_BM);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_return recv=%s retypob=%s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.retypob));
  // perhaps we could handle other cases, e.g. for something else than
  // basiclo_function-s.
  if (_.retypob != k_value && _.retypob != BMP_object)
    FAILHERE ();
  LOCALRETURN_BM (_.retypob);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("miniscan_stmt°basiclo_return failin %d", failin);
  _.errorv = (value_tyBM)
    makenode4_BM (k_return, _.retexpv, _.routprepob,
                  taggedint_BM (depth), _.recv);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end  miniscan_stmt°basiclo_return  _7vlMCZ0yvva_6tx0lFlqBG8 */


////////////////


// miniscan_stmt°basiclo_wrong _0Jvu8JxkNZZ_6K0zshkn9cP

extern objrout_sigBM ROUTINEOBJNAME_BM (_0Jvu8JxkNZZ_6K0zshkn9cP);

value_tyBM
ROUTINEOBJNAME_BM (_0Jvu8JxkNZZ_6K0zshkn9cP)    // miniscan_stmt°basiclo_wrong
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recvob
 const value_tyBM arg2,         // routprepob
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // fromob
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  const objectval_tyBM *k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  objectval_tyBM *k_origin = BMK_1xhcI0ZnQ6f_5xOLATXqawx;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_0Jvu8JxkNZZ_6K0zshkn9cP,
                 objectval_tyBM * recvob;       //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 value_tyBM resultv;    //
                 value_tyBM subexpv;    //
                 objectval_tyBM * subtypob;     //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
    );
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.recvob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  int depth = getint_BM (arg3);
  _.fromob = objectcast_BM (arg4);
  DBGPRINTF_BM ("miniscan_stmt°basiclo_wrong start recvob %s routprepob %s depth %d fromob %s", objectdbg1_BM (_.recvob), objectdbg2_BM (_.routprepob), depth, //
                objectdbg3_BM (_.fromob));
  if (!_.fromob)
    FAILHERE (k_origin);
  WEAKASSERT_BM (_.recvob);
  if (!_.routprepob)
    FAILHERE (NULL);
  WEAKASSERT_BM (_.routprepob);
  if (!_.routprepob)
    LOCALRETURN_BM (NULL);
  unsigned nbsons = objnbcomps_BM (_.recvob);
  for (unsigned ix = 0; ix < nbsons; ix++)
    {
      _.subexpv = objgetcomp_BM (_.recvob, ix);
      _.subtypob =
        miniscan_expr_BM (_.subexpv, _.routprepob, 0, _.recvob, CURFRAME_BM);
      if (!_.subtypob)
        FAILHERE (makenode2_BM (k_curcomp, _.subexpv, taggedint_BM (ix)));
    }
  DBGPRINTF_BM ("miniscan_stmt°basiclo_wrong end recvob %s",
                objectdbg_BM (_.recvob));
  LOCALRETURN_BM (_.recvob);
failure:
#undef FAILHERE
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_wrong failin %d recvob %s, routprepob %s, fromob %s, cause %s",
     failin, objectdbg_BM (_.recvob), objectdbg1_BM (_.routprepob),
     objectdbg2_BM (_.fromob), debug_outstr_value_BM (_.causev, CURFRAME_BM,
                                                      0));
  _.errorv =
    (value_tyBM) makenode4_BM (k_miniscan_stmt, _.recvob, _.routprepob,
                               _.fromob, _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniscan_stmt°basiclo_wrong _0Jvu8JxkNZZ_6K0zshkn9cP */



////////////////////////////////////////////////////////////////

// emit_declaration°simple_routine_preparation _9M3BqmOS7mA_96DTa52k7Xq
extern objrout_sigBM ROUTINEOBJNAME_BM (_9M3BqmOS7mA_96DTa52k7Xq);
value_tyBM
ROUTINEOBJNAME_BM (_9M3BqmOS7mA_96DTa52k7Xq)    // emit_declaration°simple_routine_preparation 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recv
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // index
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_9M3BqmOS7mA_96DTa52k7Xq,
                 objectval_tyBM * routprepob; objectval_tyBM * modgenob;
                 objectval_tyBM * routob; objectval_tyBM * hsetblockob;
                 value_tyBM blocksetv; objectval_tyBM * hsetvalob;
                 objectval_tyBM * hsetnumob; objectval_tyBM * keyob;
                 objectval_tyBM * bindconnob; value_tyBM resultv;
                 value_tyBM keysetv;
                 value_tyBM setv; value_tyBM keybindv; value_tyBM errorv;
                 value_tyBM errcausev;
    );
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.errcausev = (value_tyBM)(Cause); goto failure; } while(0)

  objectval_tyBM *k_blocks = BMK_2lCuMosXupr_5GAoqVgJ8PZ;
  objectval_tyBM *k_prepare_routine = BMK_6qi1DW0Ygkl_4Aqdxq4n5IV;
  objectval_tyBM *k_hset_object = BMK_8c9otZ4pwR6_55k81qyyYV2;
  objectval_tyBM *k_value_set = BMK_6Fl0Z0OTtV9_8QTsq3uDu4q;
  objectval_tyBM *k_number_set = BMK_5uPst3m4mdx_05Xl1AoTnZL;
  objectval_tyBM *k_in = BMK_0eMGYofuNVh_8ZP2mXdhtHO;
  objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  objectval_tyBM *k_locals = BMK_24sSVIADeHm_0Sx34wQfG7W;
  objectval_tyBM *k_numbers = BMK_32eKNcTZ9HN_80t0nk47Mha;
  objectval_tyBM *k_result = BMK_7bD9VtDkGSn_7lxHeYuuFLR;
  objectval_tyBM *k_closed = BMK_2TwOyPJxIz8_1rIeqaN7oRz;
  objectval_tyBM *k_binding = BMK_6zu0x6tqX60_8QhJjiAOwul;
  //objectval_tyBM *k_c_type = BMK_83kM1HtO8K3_6k0F2KYQT3W;
  objectval_tyBM *k_emit_declaration = BMK_3NGaoN3yhbn_8yUwbtZfvp9;
  WEAKASSERT_BM (isobject_BM (arg1));
  _.routprepob = objectcast_BM (arg1);
  WEAKASSERT_BM (isobject_BM (arg2));
  _.modgenob = objectcast_BM (arg2);
  WEAKASSERT_BM (istaggedint_BM (arg3));
  int rank = getint_BM (arg3);
  DBGPRINTF_BM
    ("emit_declaration°simple_routine_preparation start routprepob=%s modgenob=%s rank#%d",
     objectdbg_BM (_.routprepob), objectdbg1_BM (_.modgenob), rank);
  {
    objlock_BM (_.routprepob);
    _.routob =
      objectcast_BM (objgetattr_BM (_.routprepob, k_prepare_routine));
    _.hsetblockob = objectcast_BM (objgetattr_BM (_.routprepob, k_blocks));
    DBGPRINTF_BM
      ("emit_declaration°simple_routine_preparation routprepob=%s routob=%s hsetblockob=%s",
       objectdbg_BM (_.routprepob), objectdbg1_BM (_.routob),
       objectdbg2_BM (_.hsetblockob));
    {
      objlock_BM (_.hsetblockob);
      WEAKASSERT_BM (isobject_BM (_.hsetblockob));
      _.blocksetv = (value_tyBM) objhashsettosetpayl_BM (_.hsetblockob);
      objunlock_BM (_.hsetblockob);
      DBGPRINTF_BM
        ("emit_declaration°simple_routine_preparation routprepob=%s blocksetv=%s",
         objectdbg_BM (_.routprepob),
         debug_outstr_value_BM (_.blocksetv, CURFRAME_BM, 0));
      if (_.blocksetv)
        objputattr_BM (_.routprepob, k_blocks, _.blocksetv);
    }
    {
      _.hsetvalob = makeobj_BM ();
      objputclass_BM (_.hsetvalob, k_hset_object);
      objputattr_BM (_.routprepob, k_value_set, _.hsetvalob);
      objputattr_BM (_.hsetvalob, k_in, _.routprepob);
      objputhashsetpayl_BM (_.hsetvalob, 5);
      _.hsetnumob = makeobj_BM ();
      objputclass_BM (_.hsetnumob, k_hset_object);
      objputattr_BM (_.routprepob, k_number_set, _.hsetnumob);
      objputattr_BM (_.hsetnumob, k_in, _.routprepob);
      objputhashsetpayl_BM (_.hsetnumob, 11);
      _.keysetv = (value_tyBM) objassocsetattrspayl_BM (_.routprepob);
      DBGPRINTF_BM ("emit_declaration°simple_routine_preparation routprepob=%s hsetvalob=%s hsetnumob=%s keyset=%s", objectdbg_BM (_.routprepob), objectdbg1_BM (_.hsetvalob), objectdbg2_BM (_.hsetnumob),    //
                    debug_outstr_value_BM (_.keysetv, CURFRAME_BM, 0));
      unsigned nbkeys = setcardinal_BM (_.keysetv);
      for (unsigned kix = 0; kix < nbkeys; kix++)
        {
          _.bindconnob = NULL;
          _.keyob = setelemnth_BM (_.keysetv, kix);
          _.keybindv = objassocgetattrpayl_BM (_.routprepob, _.keyob);
          DBGPRINTF_BM
            ("emit_declaration°simple_routine_preparation routprepob=%s kix#%d keyob=%s keybind=%s",
             objectdbg_BM (_.routprepob), kix, objectdbg1_BM (_.keyob),
             debug_outstr_value_BM (_.keybindv, CURFRAME_BM, 0));
          WEAKASSERT_BM (_.keybindv == k_result || isnode_BM (_.keybindv));

          if (_.keybindv == k_result)
            {
              objhashsetaddpayl_BM (_.hsetvalob, _.keyob);
            }
          else if ((_.bindconnob = nodeconn_BM (_.keybindv))
                   && _.bindconnob == k_arguments)
            {
              objhashsetaddpayl_BM (_.hsetvalob, _.keyob);
            }
          else if (_.bindconnob == k_locals)
            {
              objhashsetaddpayl_BM (_.hsetvalob, _.keyob);
            }
          else if (_.bindconnob == k_closed)
            {
              objhashsetaddpayl_BM (_.hsetvalob, _.keyob);
            }
          else if (_.bindconnob == k_numbers)
            {
              objhashsetaddpayl_BM (_.hsetnumob, _.keyob);
            }
          else
            FAILHERE (makenode1_BM (k_binding, _.keybindv));
        }
      _.setv = (value_tyBM) objhashsettosetpayl_BM (_.hsetvalob);
      objputattr_BM (_.routprepob, k_value_set, _.setv);
      DBGPRINTF_BM ("emit_declaration°simple_routine_preparation routprepob=%s value_set %s",  //
                    objectdbg_BM (_.routprepob),        //
                    debug_outstr_value_BM (_.setv, CURFRAME_BM, 0));
      _.setv = (value_tyBM) objhashsettosetpayl_BM (_.hsetnumob);
      objputattr_BM (_.routprepob, k_number_set, _.setv);
      DBGPRINTF_BM ("emit_declaration°simple_routine_preparation routprepob=%s number_set %s", //
                    objectdbg_BM (_.routprepob),        //
                    debug_outstr_value_BM (_.setv, CURFRAME_BM, 0));
      _.setv = NULL;
    }
    objunlock_BM (_.routprepob);
  }
  WEAKASSERT_BM (isobject_BM (_.routob));
  {
    char routidbuf[32];
    memset (routidbuf, 0, sizeof (routidbuf));
    idtocbuf32_BM (objid_BM (_.routob), routidbuf);
    objlock_BM (_.modgenob);
    const char *routname = findobjectname_BM (_.routob);
    WEAKASSERT_BM (objhasstrbufferpayl_BM (_.modgenob));
    if (routname)
      objstrbufferprintfpayl_BM (_.modgenob, "\n"
                                 "extern objrout_sigBM crout%s_BM; //#%d %s\n",
                                 routidbuf, rank, routname);
    else
      objstrbufferprintfpayl_BM (_.modgenob, "\n"
                                 "extern objrout_sigBM crout%s_BM; //#%d\n",
                                 routidbuf, rank);
    objunlock_BM (_.modgenob);
  }
  DBGPRINTF_BM
    ("emit_declaration°simple_routine_preparation end routprepob %s",
     objectdbg1_BM (_.routprepob));
  LOCALRETURN_BM (_.routprepob);
failure:
  DBGPRINTF_BM
    ("emit_declaration°simple_routine_preparation failed failin %d errcause %s routprepob %s",
     failin, debug_outstr_value_BM (_.errcausev, CURFRAME_BM, 0),
     objectdbg1_BM (_.routprepob));
  _.errorv =
    (value_tyBM) makenode4_BM (k_emit_declaration, _.routprepob, _.modgenob,
                               taggedint_BM (rank), _.errcausev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end emit_declaration°simple_routine_preparation _9M3BqmOS7mA_96DTa52k7Xq */



extern void miniemit_expression_BM (struct stackframe_stBM *stkf,
                                    value_tyBM expv,
                                    objectval_tyBM * modgenob,
                                    objectval_tyBM * routprepob,
                                    objectval_tyBM * fromob, int depth);

extern void miniemit_var_BM (struct stackframe_stBM *stkf,
                             objectval_tyBM * refob,
                             objectval_tyBM * modgenob,
                             objectval_tyBM * routprepob,
                             objectval_tyBM * fromob, int depth);

///////
// emit_definition°simple_routine_preparation _2Lk2DjTDzQh_3aTEVKDE2Ip
extern objrout_sigBM ROUTINEOBJNAME_BM (_2Lk2DjTDzQh_3aTEVKDE2Ip);

value_tyBM
ROUTINEOBJNAME_BM (_2Lk2DjTDzQh_3aTEVKDE2Ip)    // emit_definition°simple_routine_preparation 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recv
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // index
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_2Lk2DjTDzQh_3aTEVKDE2Ip,
                 objectval_tyBM * routprepob; objectval_tyBM * modgenob;
                 objectval_tyBM * modulob; objectval_tyBM * routob;
                 objectval_tyBM * hsetblockob; value_tyBM blocksetv;
                 value_tyBM argtupv; objectval_tyBM * bodyob;
                 objectval_tyBM * resultob; value_tyBM setnumv;
                 value_tyBM setvalv;
                 value_tyBM setconstv; objectval_tyBM * varob;
                 value_tyBM emitv; objectval_tyBM * typob; value_tyBM errorv;
                 value_tyBM causev;
    );
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  char routidbuf[32];
  memset (routidbuf, 0, sizeof (routidbuf));
  char modulidbuf[32];
  memset (modulidbuf, 0, sizeof (modulidbuf));
  objectval_tyBM *k_emit_definition = BMK_1g8s9B96Irf_6Ix2Cyy8Hq0;
  //objectval_tyBM *k_blocks = BMK_2lCuMosXupr_5GAoqVgJ8PZ;
  objectval_tyBM *k_prepare_routine = BMK_6qi1DW0Ygkl_4Aqdxq4n5IV;
  objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  objectval_tyBM *k_body = BMK_7DQyvJFMOrC_9IfC3CtYknn;
  objectval_tyBM *k_result = BMK_7bD9VtDkGSn_7lxHeYuuFLR;
  objectval_tyBM *k_value_set = BMK_6Fl0Z0OTtV9_8QTsq3uDu4q;
  objectval_tyBM *k_number_set = BMK_5uPst3m4mdx_05Xl1AoTnZL;
  objectval_tyBM *k_c_type = BMK_83kM1HtO8K3_6k0F2KYQT3W;
  objectval_tyBM *k_object = BMK_7T9OwSFlgov_0wVJaK1eZbn;
  objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  //objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
  //objectval_tyBM *k_emit_expression = BMK_9lXSe7DrOl6_7hghYt0LhTF;
  //objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_emit_block = BMK_6mk5eos8067_1odgCpnWMOj;
  //objectval_tyBM *k_emit_reference = BMK_6qzzDyr2eIo_3SapnOUpg6S;
  objectval_tyBM *k_plain_module = BMK_8g1WBJBhDT9_1QK8IcuWYx2;
  const objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  WEAKASSERT_BM (isobject_BM (arg1));
  _.routprepob = objectcast_BM (arg1);
  WEAKASSERT_BM (isobject_BM (arg2));
  _.modgenob = objectcast_BM (arg2);
  WEAKASSERT_BM (istaggedint_BM (arg3));
  int rank = getint_BM (arg3);
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation start routprepob=%s modgenob=%s rank#%d",
     objectdbg_BM (_.routprepob), objectdbg1_BM (_.modgenob), rank);
  objlock_BM (_.modgenob);
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.modgenob));
  _.modulob = objectcast_BM (objgetattr_BM (_.modgenob, k_plain_module));
  _.setconstv = objgetattr_BM (_.modgenob, k_constants);
  WEAKASSERT_BM (_.modulob);
  WEAKASSERT_BM (isset_BM (_.setconstv));
  idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
  {
    objlock_BM (_.routprepob);
    _.routob =
      objectcast_BM (objgetattr_BM (_.routprepob, k_prepare_routine));
    _.setnumv =
      (value_tyBM) setcast_BM (objgetattr_BM (_.routprepob, k_number_set));
    _.setvalv =
      (value_tyBM) setcast_BM (objgetattr_BM (_.routprepob, k_value_set));
    objunlock_BM (_.routprepob);
    idtocbuf32_BM (objid_BM (_.routob), routidbuf);
  }
  DBGPRINTF_BM ("emit_definition°simple_routine_preparation routprepob=%s routob=%s modulob=%s\n"      //
                ".. setnum=%s setval=%s", objectdbg_BM (_.routprepob), objectdbg1_BM (_.routob),        //
                objectdbg2_BM (_.modulob), debug_outstr_value_BM (_.setnumv, CURFRAME_BM, 0),   //
                debug_outstr_value_BM (_.setvalv, CURFRAME_BM, 0));
  WEAKASSERT_BM (isobject_BM (_.routob));
  {
    objlock_BM (_.routob);
    _.argtupv = objgetattr_BM (_.routob, k_arguments);
    _.bodyob = objectcast_BM (objgetattr_BM (_.routob, k_body));
    _.resultob = objectcast_BM (objgetattr_BM (_.routob, k_result));
    objunlock_BM (_.routob);
  }
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation routob=%s rank#%d argtup=%s bodyob=%s resultob=%s",
     objectdbg_BM (_.routob),
     rank,
     debug_outstr_value_BM (_.argtupv, CURFRAME_BM, 0),
     objectdbg1_BM (_.bodyob), objectdbg2_BM (_.resultob));
  {
    objlock_BM (_.resultob);
    _.typob = objectcast_BM (objgetattr_BM (_.resultob, k_c_type));
    objunlock_BM (_.resultob);
  }
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation routprepob=%s rank#%d argtupv=%s bodyob=%s resultob=%s of type %s",
     objectdbg_BM (_.routprepob), rank,
     debug_outstr_value_BM (_.argtupv, CURFRAME_BM, 0),
     objectdbg1_BM (_.bodyob), objectdbg2_BM (_.resultob),
     objectdbg3_BM (_.typob));
  WEAKASSERT_BM (isobject_BM (_.resultob));
  int nbargs = tuplesize_BM (_.argtupv);
  {
    const char *routname = findobjectname_BM (_.routob);
    char routidbuf[32];
    memset (routidbuf, 0, sizeof (routidbuf));
    idtocbuf32_BM (objid_BM (_.routob), routidbuf);
    if (routname)
      objstrbufferprintfpayl_BM (_.modgenob, "\n\n"
                                 "value_tyBM crout%s_BM //#%d+\n"
                                 " (struct stackframe_stBM* stkf, // %s\n",
                                 routidbuf, rank, routname);
    else
      objstrbufferprintfpayl_BM (_.modgenob, "\n\n"
                                 "value_tyBM crout%s_BM //#%d\n"
                                 " (struct stackframe_stBM* stkf, //\n",
                                 routidbuf, rank);
    objstrbufferprintfpayl_BM (_.modgenob, "  // %d arguments\n", nbargs);
    for (int aix = 0; aix < 4; aix++)
      {
        if (aix < nbargs)
          objstrbufferprintfpayl_BM (_.modgenob,
                                     "  const value_tyBM arg%d,  // %s\n",
                                     aix,
                                     objectdbg_BM (tuplecompnth_BM
                                                   (_.argtupv, aix)));
        else
          objstrbufferprintfpayl_BM (_.modgenob,
                                     "  const value_tyBM arg%d_ __attribute__((unused)),\n",
                                     aix);
      };
    if (nbargs > 4)
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "  const quasinode_tyBM * restargs /* %d extrargs */)\n",
                                 nbargs - 4);
    else
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "  const quasinode_tyBM * restargs_ __attribute__((unused)))\n");
  }
  objstrbufferprintfpayl_BM (_.modgenob, "{ // start of %s\n",
                             objectdbg_BM (_.routob));
  objstrbufferprintfpayl_BM (_.modgenob, "  struct frame%s_BMst {\n",
                             routidbuf);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "    typedhead_tyBM stkfram_head;\n");
  objstrbufferprintfpayl_BM (_.modgenob,
                             "    struct stackframe_stBM *stkfram_prev;\n");
  objstrbufferprintfpayl_BM (_.modgenob,
                             "    objectval_tyBM *stkfram_descr;\n");
  objstrbufferprintfpayl_BM (_.modgenob, "    value_tyBM stkfram_callfun;\n");
  objstrbufferprintfpayl_BM (_.modgenob, "    int stkfram_state;\n");
  objstrbufferprintfpayl_BM (_.modgenob, "    int stkfram_extra;\n");
  unsigned nbval = setcardinal_BM (_.setvalv);
  objstrbufferprintfpayl_BM (_.modgenob, "    /// %d local values:\n", nbval);
  for (unsigned vix = 0; vix < nbval; vix++)
    {
      _.varob = setelemnth_BM (_.setvalv, vix);
      _.typob = NULL;
      DBGPRINTF_BM
        ("emit_definition°simple_routine_preparation routprepob=%s vix#%d value varob=%s",
         objectdbg_BM (_.routprepob), vix, objectdbg1_BM (_.varob));
      char varidbuf[32];
      memset (varidbuf, 0, sizeof (varidbuf));
      idtocbuf32_BM (objid_BM (_.varob), varidbuf);
      objlock_BM (_.varob);
      _.typob = objectcast_BM (objgetattr_BM (_.varob, k_c_type));
      objunlock_BM (_.varob);
      if (_.typob == k_value)
        objstrbufferprintfpayl_BM (_.modgenob, "    value_tyBM v%s; // %s\n",
                                   varidbuf, objectdbg_BM (_.varob));
      else if (_.typob == k_object)
        objstrbufferprintfpayl_BM (_.modgenob,
                                   "    objectval_tyBM* o%s; // %s\n",
                                   varidbuf, objectdbg_BM (_.varob));
      else
        WEAKASSERT_BM (false && "unexpected type of variable");
    }
  unsigned nbnum = setcardinal_BM (_.setnumv);
  objstrbufferprintfpayl_BM (_.modgenob, "    /// %d local numbers:\n",
                             nbnum);
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation routprepob=%s nbnum=%d bodyob=%s",
     objectdbg_BM (_.routprepob), nbnum, objectdbg1_BM (_.bodyob));
  for (unsigned vix = 0; vix < nbnum; vix++)
    {
      _.varob = setelemnth_BM (_.setnumv, vix);
      _.typob = NULL;
      DBGPRINTF_BM
        ("emit_definition°simple_routine_preparation routprepob=%s vix#%d number varob=%s",
         objectdbg_BM (_.routprepob), vix, objectdbg1_BM (_.varob));
      char varidbuf[32];
      memset (varidbuf, 0, sizeof (varidbuf));
      idtocbuf32_BM (objid_BM (_.varob), varidbuf);
      objstrbufferprintfpayl_BM (_.modgenob, "    intptr_t n%s; // %s\n",
                                 varidbuf, objectdbg_BM (_.varob));
    }
  objstrbufferprintfpayl_BM (_.modgenob, "   } _;\n");
  objstrbufferprintfpayl_BM (_.modgenob,
                             "   memset (&_, 0, sizeof(struct frame%s_BMst));\n",
                             routidbuf);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "   _.stkfram_head.htyp = typayl_StackFrame_BM;\n");
  objstrbufferprintfpayl_BM (_.modgenob, "   _.stkfram_head.hgc = 0;\n");
  objstrbufferprintfpayl_BM (_.modgenob, "   _.stkfram_head.rlen = %d;\n",
                             nbval);
  int kroutix = setelemindex_BM (_.setconstv, _.routob);
  WEAKASSERT_BM (kroutix >= 0);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "   _.stkfram_descr = " CONSTOBARRPREFIX_BM "%s"
                             ROUTINESUFFIX_BM
                             "[%d] /*|%s*/;\n", modulidbuf,
                             kroutix, objectdbg2_BM (_.routob));
  objstrbufferprintfpayl_BM (_.modgenob,
                             "   ASSERT_BM (!stkf\n"
                             "             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM\n"
                             "             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);\n");
  objstrbufferprintfpayl_BM (_.modgenob, "   _.stkfram_prev = stkf;\n");
  objstrbufferprintfpayl_BM (_.modgenob, "   // fetch %d arguments:\n",
                             nbargs);
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation routprepob=%s nbargs=%d bodyob=%s",
     objectdbg_BM (_.routprepob), nbargs, objectdbg1_BM (_.bodyob));
  if (nbargs > 4)
    objstrbufferprintfpayl_BM (_.modgenob,
                               "   unsigned nbrestargs = treewidth_BM(restargs);\n");
  for (int aix = 0; aix < nbargs; aix++)
    {
      _.varob = tuplecompnth_BM (_.argtupv, aix);
      _.typob = NULL;
      DBGPRINTF_BM
        ("emit_definition°simple_routine_preparation routprepob=%s aix#%d arg varob=%s bodyob=%s",
         objectdbg_BM (_.routprepob), aix, objectdbg1_BM (_.varob),
         objectdbg2_BM (_.bodyob));
      objlock_BM (_.varob);
      _.typob = objectcast_BM (objgetattr_BM (_.varob, k_c_type));
      objunlock_BM (_.varob);
      char varidbuf[32];
      memset (varidbuf, 0, sizeof (varidbuf));
      idtocbuf32_BM (objid_BM (_.varob), varidbuf);
      DBGPRINTF_BM
        ("emit_definition°simple_routine_preparation routprepob=%s arg varob=%s |%s typob=%s aix#%d",
         objectdbg_BM (_.routprepob), objectdbg1_BM (_.varob), varidbuf,
         objectdbg2_BM (_.typob), aix);
      WEAKASSERT_BM (_.typob == k_value || _.typob == k_object);
      if (aix < 4)
        {
          if (_.typob == k_value)
            objstrbufferprintfpayl_BM (_.modgenob, "   _.v%s = arg%d;\n",
                                       varidbuf, aix);
          else if (_.typob == k_object)
            objstrbufferprintfpayl_BM (_.modgenob,
                                       "   _.o%s = objectcast(arg%d);\n",
                                       varidbuf, aix);
          else
            {
              objstrbufferprintfpayl_BM (_.modgenob,
                                         "#error fail fetch #%d %s of type %s\n",
                                         aix, varidbuf,
                                         objectdbg_BM (_.typob));
              FAILHERE (makenode3_BM
                        (k_arguments, _.varob, _.typob, taggedint_BM (aix)));
            }
        }
      else
        {
          objstrbufferprintfpayl_BM (_.modgenob,
                                     "    if (nbrestargs >= %d)\n", aix - 4);
          if (_.typob == k_value)
            objstrbufferprintfpayl_BM (_.modgenob,
                                       "    _.v%s = restargs->nodt_sons[%d];\n",
                                       varidbuf, aix - 4);
          else if (_.typob == k_object)
            objstrbufferprintfpayl_BM (_.modgenob,
                                       "    _.o%s = objectcast(restargs->nodt_sons[%d]);\n",
                                       varidbuf, aix - 4);
          else
            {
              objstrbufferprintfpayl_BM (_.modgenob,
                                         "#error fail fetch xtra #%d %s of type %s\n",
                                         aix, varidbuf,
                                         objectdbg_BM (_.typob));
              FAILHERE (makenode3_BM
                        (k_arguments, _.varob, _.typob, taggedint_BM (aix)));
            }
        }
    }
  objstrbufferprintfpayl_BM (_.modgenob, "   // fetched %d arguments.\n",
                             nbargs);
  objstrbufferprintfpayl_BM (_.modgenob, "   // routine %s body:\n",
                             routidbuf);
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation routprepob=%s before emit_block bodyob=%s of %s",
     objectdbg_BM (_.routprepob), objectdbg1_BM (_.bodyob),
     objectdbg2_BM (objclass_BM (_.bodyob)));
  _.emitv = send3_BM (_.bodyob, k_emit_block, CURFRAME_BM,      //
                      _.modgenob, _.routprepob, taggedint_BM (0)        /*depth of block */
    );
  if (!_.emitv)
    FAILHERE (k_body);
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation routprepob=%s after emit_block bodyob=%s emitv=%s",
     objectdbg_BM (_.routprepob), objectdbg_BM (_.bodyob),
     debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
  objstrbuffersetindentpayl_BM (_.modgenob, 0);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob,
                             " epilog%s: __attribute__ ((unused)); // routine %s epilogue:\n",
                             routidbuf, routidbuf);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "   if (stkf) stkf->stkfram_callfun = NULL;\n");
  objstrbufferprintfpayl_BM (_.modgenob, "   return ");
  miniemit_var_BM (CURFRAME_BM, _.resultob, _.modgenob, _.routprepob,
                   _.routob, 0);
  objstrbufferprintfpayl_BM (_.modgenob,
                             ";\n" "} // end %s routine#%d %s\n\n\n",
                             routidbuf, rank, objectdbg_BM (_.routob));
  objunlock_BM (_.modgenob);
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation end routprepob=%s",
     objectdbg_BM (_.routprepob));
  LOCALRETURN_BM (_.routprepob);
failure:
#undef FAILHERE
  DBGPRINTF_BM ("emit_definition°simple_routine_preparation failin %d routprep %s cause %s",   //
                failin, objectdbg_BM (_.routprepob),    //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode4_BM (k_emit_definition, _.routprepob, _.modgenob,
                  taggedint_BM (rank), _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_definition°simple_routine_preparation  _2Lk2DjTDzQh_3aTEVKDE2Ip */



/////
//emit_block°basiclo_block  _8UGpvfrcKbM_99IeP3BuxA5
extern objrout_sigBM ROUTINEOBJNAME_BM (_8UGpvfrcKbM_99IeP3BuxA5);

value_tyBM
ROUTINEOBJNAME_BM (_8UGpvfrcKbM_99IeP3BuxA5)    // emit_block°basiclo_block
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // blockob reciever
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_emit_block = BMK_6mk5eos8067_1odgCpnWMOj;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_8UGpvfrcKbM_99IeP3BuxA5,
                 objectval_tyBM * blockob;      //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * stmtob;       //
                 value_tyBM resultv;    //
                 value_tyBM emitv;      //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
    );
  _.blockob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  int failin = -1;
  char blockidbuf[32];
  memset (blockidbuf, 0, sizeof (blockidbuf));
  idtocbuf32_BM (objid_BM (_.blockob), blockidbuf);
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("emit_block°basiclo_block start blockob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.blockob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  WEAKASSERT_BM (isobject_BM (_.blockob));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.routprepob));
  WEAKASSERT_BM (istaggedint_BM (arg4));
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.modgenob));
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n"
                             "startblock_%s: __attribute__((unused));\n"
                             "{ /* +block %s */", blockidbuf, blockidbuf);
  int indepth = depth + 1;
  unsigned blocklen = objnbcomps_BM (_.blockob);
  for (unsigned insix = 0; insix < blocklen; insix++)
    {
      _.stmtob = objectcast_BM (objgetcomp_BM (_.blockob, insix));
      DBGPRINTF_BM
        ("emit_block°basiclo_block blockob %s insix#%d stmtob %s of %s",
         objectdbg_BM (_.blockob), insix, objectdbg2_BM (_.stmtob),
         objectdbg3_BM (objclass_BM (_.stmtob)));
      WEAKASSERT_BM (isobject_BM (_.stmtob));
      {
        objlock_BM (_.stmtob);
        objstrbuffersetindentpayl_BM (_.modgenob, indepth);
        objstrbuffernewlinepayl_BM (_.modgenob);
        if (objectisinstance_BM (_.stmtob, k_basiclo_statement))
          {
            DBGPRINTF_BM
              ("emit_block°basiclo_block blockob %s insix#%d stmtob %s is statement",
               objectdbg_BM (_.blockob), insix, objectdbg2_BM (_.stmtob));
            _.emitv = send3_BM (_.stmtob, k_emit_statement, CURFRAME_BM,        //
                                _.modgenob, _.routprepob,
                                taggedint_BM (indepth));
            objstrbuffernewlinepayl_BM (_.modgenob);
            if (!_.emitv)
              FAILHERE (makenode2_BM
                        (k_emit_statement, _.stmtob, taggedint_BM (insix)));
          }
        else if (objectisinstance_BM (_.stmtob, k_basiclo_block))
          {
            DBGPRINTF_BM
              ("emit_block°basiclo_block blockob %s insix#%d stmtob %s is block",
               objectdbg_BM (_.blockob), insix, objectdbg2_BM (_.stmtob));
            _.emitv = send3_BM (_.stmtob, k_emit_block, CURFRAME_BM,    //
                                _.modgenob, _.routprepob,
                                taggedint_BM (indepth));
            if (!_.emitv)
              FAILHERE (makenode2_BM
                        (k_emit_block, _.stmtob, taggedint_BM (insix)));
          }
        else
          FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (insix), _.stmtob));
        objunlock_BM (_.stmtob);
      }
    }
  objstrbuffersetindentpayl_BM (_.modgenob, indepth);
  objstrbufferprintfpayl_BM (_.modgenob, "/* !endingblock %s */\n"
                             "goto endblock_%s;\n"
                             "endblock_%s: ;\n",
                             blockidbuf, blockidbuf, blockidbuf);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, "} /*-block %s */\n", blockidbuf);
  DBGPRINTF_BM
    ("emit_block°basiclo_block end blockob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.blockob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  LOCALRETURN_BM (_.blockob);
failure:
  DBGPRINTF_BM ("emit_block°basiclo_block failin %d routprep %s cause %s", failin, objectdbg_BM (_.routprepob),        //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode4_BM (k_emit_block, _.blockob, _.routprepob, _.modgenob,
                  _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_block°basiclo_block _8UGpvfrcKbM_99IeP3BuxA5 */

// emit_block°basiclo_loop _56pDwW9peiP_8flH2fMQUnD

extern objrout_sigBM ROUTINEOBJNAME_BM (_56pDwW9peiP_8flH2fMQUnD);

value_tyBM
ROUTINEOBJNAME_BM (_56pDwW9peiP_8flH2fMQUnD)    //emit_block°basiclo_loop
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recvob - loop
 const value_tyBM arg2,         // modgenob 
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_emit_block = BMK_6mk5eos8067_1odgCpnWMOj;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_56pDwW9peiP_8flH2fMQUnD,
                 objectval_tyBM * blockob;      //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * stmtob;       //
                 value_tyBM resultv;    //
                 value_tyBM emitv;      //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
    );
  _.blockob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  int failin = -1;
  char blockidbuf[32];
  memset (blockidbuf, 0, sizeof (blockidbuf));
  idtocbuf32_BM (objid_BM (_.blockob), blockidbuf);
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("emit_block°basiclo_loop start blockob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.blockob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  WEAKASSERT_BM (isobject_BM (_.blockob));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.routprepob));
  WEAKASSERT_BM (istaggedint_BM (arg4));
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.modgenob));
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n"
                             "startblock_%s: __attribute__((unused));\n"
                             "{ /* +loop %s */\n", blockidbuf, blockidbuf);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "  startloop_%s: __attribute__((unused));\n",
                             blockidbuf, blockidbuf);
  int indepth = depth + 1;
  unsigned blocklen = objnbcomps_BM (_.blockob);
  for (unsigned insix = 0; insix < blocklen; insix++)
    {
      _.stmtob = objectcast_BM (objgetcomp_BM (_.blockob, insix));
      DBGPRINTF_BM
        ("emit_block°basiclo_loop blockob %s insix#%d stmtob %s of %s",
         objectdbg_BM (_.blockob), insix, objectdbg2_BM (_.stmtob),
         objectdbg3_BM (objclass_BM (_.stmtob)));
      WEAKASSERT_BM (isobject_BM (_.stmtob));
      {
        objlock_BM (_.stmtob);
        objstrbuffersetindentpayl_BM (_.modgenob, indepth);
        objstrbuffernewlinepayl_BM (_.modgenob);
        {
          objlock_BM (_.stmtob);
          objstrbuffersetindentpayl_BM (_.modgenob, indepth);
          objstrbuffernewlinepayl_BM (_.modgenob);
          if (objectisinstance_BM (_.stmtob, k_basiclo_statement))
            {
              DBGPRINTF_BM
                ("emit_block°basiclo_loop blockob %s insix#%d stmtob %s is statement",
                 objectdbg_BM (_.blockob), insix, objectdbg2_BM (_.stmtob));
              _.emitv = send3_BM (_.stmtob, k_emit_statement, CURFRAME_BM,      //
                                  _.modgenob, _.routprepob,
                                  taggedint_BM (indepth));
              objstrbuffernewlinepayl_BM (_.modgenob);
              if (!_.emitv)
                FAILHERE (makenode2_BM
                          (k_emit_statement, _.stmtob, taggedint_BM (insix)));
            }
          else if (objectisinstance_BM (_.stmtob, k_basiclo_block))
            {
              DBGPRINTF_BM
                ("emit_block°basiclo_loop blockob %s insix#%d stmtob %s is block",
                 objectdbg_BM (_.blockob), insix, objectdbg2_BM (_.stmtob));
              _.emitv = send3_BM (_.stmtob, k_emit_block, CURFRAME_BM,  //
                                  _.modgenob, _.routprepob,
                                  taggedint_BM (indepth));
              if (!_.emitv)
                FAILHERE (makenode2_BM
                          (k_emit_block, _.stmtob, taggedint_BM (insix)));
            }
          else
            FAILHERE (makenode2_BM
                      (k_curcomp, taggedint_BM (insix), _.stmtob));
          objunlock_BM (_.stmtob);
        }
        objstrbuffernewlinepayl_BM (_.modgenob);
      }
      if (!_.emitv)
        FAILHERE (makenode1_BM (k_emit_statement, _.stmtob));
    }
  objstrbuffersetindentpayl_BM (_.modgenob, indepth);
  objstrbufferprintfpayl_BM (_.modgenob, "\n/* !endingloop %s */\n"
                             "goto startloop_%s;\n"
                             "endblock_%s: __attribute__((unused));\n",
                             blockidbuf, blockidbuf, blockidbuf);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, "} /*-loop %s */\n", blockidbuf);
  DBGPRINTF_BM
    ("emit_block°basiclo_loop end blockob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.blockob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  LOCALRETURN_BM (_.blockob);
failure:
  DBGPRINTF_BM ("emit_block°basiclo_loop failin %d routprep %s cause %s", failin, objectdbg_BM (_.routprepob), //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode4_BM (k_emit_block, _.blockob, _.routprepob, _.modgenob,
                  _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_block°basiclo_loop _56pDwW9peiP_8flH2fMQUnD */



// emit_statment°basiclo_cond _2gpamAdSc26_6d1JjCmKHyw

extern objrout_sigBM ROUTINEOBJNAME_BM (_2gpamAdSc26_6d1JjCmKHyw);

value_tyBM
ROUTINEOBJNAME_BM (_2gpamAdSc26_6d1JjCmKHyw)    //emit_statment°basiclo_cond 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // stmtob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_2gpamAdSc26_6d1JjCmKHyw,
                 objectval_tyBM * stmtob; objectval_tyBM * modgenob;
                 objectval_tyBM * routprepob; objectval_tyBM * compob;
                 value_tyBM tmpv; value_tyBM resultv; value_tyBM emitv;
                 value_tyBM causev;
                 value_tyBM errorv;
    );
  objectval_tyBM *k_emit_when = BMK_8BRpelfZZnA_85HsuPjg0G7;
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_basiclo_when = BMK_3fvdRZNCmJS_5bTAPr83mXg;
  objectval_tyBM *k_emit_block = BMK_6mk5eos8067_1odgCpnWMOj;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_nb_conds = BMK_8dLpuaNoSGN_2tdmkpINCsu;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  _.stmtob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  WEAKASSERT_BM (istaggedint_BM (arg4));
  char condidbuf[32];
  memset (condidbuf, 0, sizeof (condidbuf));
  idtocbuf32_BM (objid_BM (_.stmtob), condidbuf);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  int depth = getint_BM (arg4);
  WEAKASSERT_BM (isobject_BM (_.stmtob));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.routprepob));
  DBGPRINTF_BM
    ("emit_statment°basiclo_cond start stmtob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.stmtob), objectdbg2_BM (_.modgenob),
     objectdbg3_BM (_.routprepob), depth);
  int nbconds = -1;
  int stmtsiz = objnbcomps_BM (_.stmtob);
  {
    _.tmpv = objgetattr_BM (_.stmtob, k_nb_conds);
    WEAKASSERT_BM (istaggedint_BM (_.tmpv));
    nbconds = getint_BM (_.tmpv);
    _.tmpv = NULL;
  }
  DBGPRINTF_BM
    ("emit_statment°basiclo_cond stmtob=%s nbconds=%d stmtsiz=%d condidbuf=%s",
     objectdbg_BM (_.stmtob), nbconds, stmtsiz, condidbuf);
  for (int ix = 0; ix < nbconds; ix++)
    {
      _.compob = objectcast_BM (objgetcomp_BM (_.stmtob, ix));
      DBGPRINTF_BM
        ("emit_statment°basiclo_cond stmtob=%s ix#%d when compob=%s",
         objectdbg_BM (_.stmtob), ix, objectdbg2_BM (_.modgenob));
      WEAKASSERT_BM (isobject_BM (_.compob));
      objlock_BM (_.compob);
      if (objectisinstance_BM (_.compob, k_basiclo_when))
        {
          if (ix > 0)
            objstrbufferprintfpayl_BM (_.modgenob, "else if ");
          else
            objstrbufferprintfpayl_BM (_.modgenob, "if /*cond %s*/ ",
                                       condidbuf);
          _.emitv = send3_BM (_.compob, k_emit_when, CURFRAME_BM,       //
                              _.modgenob, _.routprepob, taggedint_BM (depth));
          DBGPRINTF_BM
            ("emit_statment°basiclo_cond stmtob=%s compob=%s emit_when -> %s",
             objectdbg_BM (_.stmtob), objectdbg2_BM (_.compob),
             debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
          if (!_.emitv)
            FAILHERE (makenode2_BM
                      (k_emit_when, taggedint_BM (ix), _.compob));
        }
      else
        FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (ix), _.compob));
      objunlock_BM (_.compob);
    }
  if (nbconds < stmtsiz)
    {
      int indepth = depth + 1;
      objstrbuffersetindentpayl_BM (_.modgenob, indepth);
      objstrbufferprintfpayl_BM (_.modgenob, "else { /*cond else %s*/\n",
                                 condidbuf);
      for (int ix = nbconds; ix < stmtsiz; ix++)
        {
          _.compob = objectcast_BM (objgetcomp_BM (_.stmtob, ix));
          objlock_BM (_.compob);
          DBGPRINTF_BM
            ("emit_statment°basiclo_cond stmtob=%s ix#%d else compob=%s",
             objectdbg_BM (_.stmtob), ix, objectdbg2_BM (_.modgenob));
          WEAKASSERT_BM (isobject_BM (_.compob));
          if (objectisinstance_BM (_.compob, k_basiclo_block))
            {
              _.emitv = send3_BM (_.compob, k_emit_block, CURFRAME_BM,  //
                                  _.modgenob, _.routprepob,
                                  taggedint_BM (depth));
              DBGPRINTF_BM
                ("emit_statment°basiclo_cond stmtob=%s compob=%s emit_block -> %s",
                 objectdbg_BM (_.stmtob), objectdbg2_BM (_.compob),
                 debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
              if (!_.emitv)
                FAILHERE (makenode2_BM
                          (k_emit_block, taggedint_BM (ix), _.compob));
            }
          else if (objectisinstance_BM (_.compob, k_basiclo_statement))
            {
              _.emitv = send3_BM (_.compob, k_emit_statement, CURFRAME_BM,      //
                                  _.modgenob, _.routprepob,
                                  taggedint_BM (depth));
              DBGPRINTF_BM
                ("emit_statment°basiclo_cond stmtob=%s compob=%s emit_statment -> %s",
                 objectdbg_BM (_.stmtob), objectdbg2_BM (_.compob),
                 debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
              if (!_.emitv)
                FAILHERE (makenode2_BM
                          (k_emit_statement, taggedint_BM (ix), _.compob));
            }
          else
            FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (ix), _.compob));
          objunlock_BM (_.compob);
        }
      objstrbuffersetindentpayl_BM (_.modgenob, indepth);
      objstrbufferprintfpayl_BM (_.modgenob, "} /*cond else %s*/\n",
                                 condidbuf);
    }
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, "/*endcond %s*/\n", condidbuf);
  LOCALRETURN_BM (_.stmtob);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("emit_statment°basiclo_cond failin %d routprep %s cause %s", failin, objectdbg_BM (_.routprepob),      //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode4_BM (k_emit_statement, _.stmtob, _.routprepob, _.modgenob,
                  _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_statment°basiclo_cond _2gpamAdSc26_6d1JjCmKHyw */

// emit_when°basiclo_when  _9Wk97VJLuH1_0FwsSpfatDg

extern objrout_sigBM ROUTINEOBJNAME_BM (_9Wk97VJLuH1_0FwsSpfatDg);

value_tyBM
ROUTINEOBJNAME_BM (_9Wk97VJLuH1_0FwsSpfatDg)    // emit_when°basiclo_when
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // whenob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_9Wk97VJLuH1_0FwsSpfatDg,
                 objectval_tyBM * whenob; objectval_tyBM * modgenob;
                 objectval_tyBM * routprepob; objectval_tyBM * compob;
                 value_tyBM tmpv;
                 value_tyBM resultv; value_tyBM emitv; value_tyBM causev;
                 value_tyBM testexpv;
                 value_tyBM errorv;
    );
  objectval_tyBM *k_emit_when = BMK_8BRpelfZZnA_85HsuPjg0G7;
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_emit_block = BMK_6mk5eos8067_1odgCpnWMOj;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_test = BMK_2j84OTHlFdJ_1pMyQfgsmAz;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  _.whenob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  WEAKASSERT_BM (istaggedint_BM (arg4));
  int depth = getint_BM (arg4);
  char whenidbuf[32];
  memset (whenidbuf, 0, sizeof (whenidbuf));
  idtocbuf32_BM (objid_BM (_.whenob), whenidbuf);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  WEAKASSERT_BM (isobject_BM (_.whenob));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.routprepob));
  _.testexpv = objgetattr_BM (_.whenob, k_test);
  DBGPRINTF_BM
    ("emit_when°basiclo_when start whenob=%s whenid=%s modgenob=%s routprepob=%s testexp=%s",
     objectdbg_BM (_.whenob), whenidbuf, objectdbg2_BM (_.modgenob),
     objectdbg3_BM (_.routprepob),
     debug_outstr_value_BM (_.testexpv, CURFRAME_BM, 0));
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  // whenob is locked by caller emit_statment°basiclo_cond
  objstrbufferprintfpayl_BM (_.modgenob, "/*when %s:*/ (",
                             objectdbg_BM (_.whenob));
  miniemit_expression_BM (CURFRAME_BM, _.testexpv, _.modgenob, _.routprepob,
                          _.whenob, depth);
  objstrbufferappendcstrpayl_BM (_.modgenob, ") {");
  int indepth = depth + 1;
  objstrbuffersetindentpayl_BM (_.modgenob, indepth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  int whenlen = objnbcomps_BM (_.whenob);
  DBGPRINTF_BM
    ("emit_when°basiclo_when whenob=%s whenlen=%d routprepob=%s",
     objectdbg_BM (_.whenob), whenlen, objectdbg1_BM (_.routprepob));
  for (int wix = 0; wix < whenlen; wix++)
    {
      _.compob = objectcast_BM (objgetcomp_BM (_.whenob, wix));
      DBGPRINTF_BM
        ("emit_when°basiclo_when whenob=%s wix#%d compob=%s of %s",
         objectdbg_BM (_.whenob), wix, objectdbg1_BM (_.compob),
         objectdbg2_BM (objclass_BM (_.compob)));
      if (objectisinstance_BM (_.compob, k_basiclo_block))
        {
          DBGPRINTF_BM
            ("emit_when°basiclo_when whenob=%s routprepob=%s before emit_block wix#%d compob=%s",
             objectdbg_BM (_.whenob), objectdbg1_BM (_.routprepob),
             wix, objectdbg2_BM (_.compob));
          _.emitv = send3_BM (_.compob, k_emit_block, CURFRAME_BM,      //
                              _.modgenob, _.routprepob,
                              taggedint_BM (depth + 1));
          DBGPRINTF_BM
            ("emit_when°basiclo_when whenob=%s after emit_block wix#%d compob=%s emitv=%s",
             objectdbg_BM (_.whenob), wix, objectdbg1_BM (_.compob),
             debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
          if (!_.emitv)
            FAILHERE (makenode2_BM
                      (k_emit_block, _.compob, taggedint_BM (wix)));

        }
      else if (objectisinstance_BM (_.compob, k_basiclo_statement))
        {
          DBGPRINTF_BM
            ("emit_when°basiclo_when whenob=%s routprepob=%s before emit_statment wix#%d compob=%s",
             objectdbg_BM (_.whenob), objectdbg1_BM (_.routprepob),
             wix, objectdbg2_BM (_.compob));
          _.emitv = send3_BM (_.compob, k_emit_statement, CURFRAME_BM,  //
                              _.modgenob, _.routprepob,
                              taggedint_BM (depth + 1));
          DBGPRINTF_BM
            ("emit_when°basiclo_when whenob=%s after emit_statment wix#%d compob=%s emitv=%s",
             objectdbg_BM (_.whenob), wix, objectdbg1_BM (_.compob),
             debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
          if (!_.emitv)
            FAILHERE (makenode2_BM
                      (k_emit_statement, _.compob, taggedint_BM (wix)));
        }
      else
        FAILHERE (makenode2_BM (k_curcomp, _.compob, taggedint_BM (wix)));
    }
  objstrbuffersetindentpayl_BM (_.modgenob, indepth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob, "} //endwhen %s\n", whenidbuf);
  DBGPRINTF_BM
    ("emit_when°basiclo_when end whenob=%s", objectdbg_BM (_.whenob));
  LOCALRETURN_BM (_.whenob);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("emit_when°basiclo_when failin %d whenob %s routprep %s cause %s",     //
                failin, objectdbg_BM (_.whenob), objectdbg2_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode4_BM (k_emit_when, _.whenob, _.routprepob, _.modgenob, _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_when°basiclo_when _9Wk97VJLuH1_0FwsSpfatDg */




extern void
miniemit_expression_BM (struct stackframe_stBM *stkf, value_tyBM expv,
                        objectval_tyBM * modgenob,
                        objectval_tyBM * routprepob, objectval_tyBM * fromob,
                        int depth)
{
  objectval_tyBM *k_emit_expression = BMK_9lXSe7DrOl6_7hghYt0LhTF;
  //objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
  //objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  //objectval_tyBM *k_string = BMK_4T8am97muLl_5969SR22Ecq;
  objectval_tyBM *k_miniemit_node_conn = BMK_7L782rSgJBB_9vjsBdqAoz7;
  objectval_tyBM *k_variable = BMK_5ucAZimYynS_4VA0XHvr1nW;
  objectval_tyBM *k_basiclo_connective = BMK_3DQ7z3EuAiT_4faSRNsy2lr;
  objectval_tyBM *k_exclam = BMK_0e54seiZEXF_1Myf620cHoB;
  objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  objectval_tyBM *k_plain_module = BMK_8g1WBJBhDT9_1QK8IcuWYx2;
  LOCALFRAME_BM (stkf, /*descr: */ k_emit_expression,
                 value_tyBM expv; value_tyBM avalv; objectval_tyBM * expob;
                 objectval_tyBM * modgenob; objectval_tyBM * modulob;
                 objectval_tyBM * typob; objectval_tyBM * routprepob;
                 objectval_tyBM * fromob; objectval_tyBM * connob;
                 value_tyBM exclamv; objectval_tyBM * exclamob;
                 value_tyBM errorv; value_tyBM causev;
                 value_tyBM resv;
                 value_tyBM constantsv;
    );
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.expv = expv;
  _.modgenob = objectcast_BM (modgenob);
  _.routprepob = objectcast_BM (routprepob);
  _.fromob = objectcast_BM (fromob);
  WEAKASSERTRET_BM (_.modgenob);
  WEAKASSERTRET_BM (_.routprepob);
  _.modulob = objgetattr_BM (_.modgenob, k_plain_module);
  DBGPRINTF_BM
    ("emit_expression start expv %s modgenob %s routprepob %s modulob %s",
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg_BM (_.modgenob), objectdbg1_BM (_.routprepob),
     objectdbg2_BM (_.modulob));
  int ke = valtype_BM (_.expv);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  switch (ke)
    {
    case tyNone_BM:
      objstrbufferprintfpayl_BM (_.modgenob, " NULL");
      LOCALJUSTRETURN_BM ();
    case tyInt_BM:
      objstrbufferprintfpayl_BM (_.modgenob, " %lld",
                                 (long long) getint_BM (_.expv));
      LOCALJUSTRETURN_BM ();
    case tyString_BM:
      objstrbufferappendcstrpayl_BM (_.modgenob, " \"");
      objstrbufferencodedcpayl_BM (_.modgenob, bytstring_BM (_.expv), -1);
      objstrbufferappendcstrpayl_BM (_.modgenob, "\"");
      LOCALJUSTRETURN_BM ();
    case tySet_BM:
      FAILHERE (BMP_set);
    case tyTuple_BM:
      FAILHERE (BMP_tuple);
    case tyClosure_BM:
      FAILHERE (BMP_closure);
    case tyUnspecified_BM:
      FAILHERE (BMP_unspecified);
#warning emit_expr very incomplete
    case tyObject_BM:
      {
        _.expob = objectcast_BM (_.expv);
        _.avalv = objassocgetattrpayl_BM (_.routprepob, _.expob);
        char varidbuf[32];
        memset (varidbuf, 0, sizeof (varidbuf));
        idtocbuf32_BM (objid_BM (_.expob), varidbuf);
        DBGPRINTF_BM ("emit_expr expob=%s avalv=%s routprepob=%s",
                      objectdbg_BM (_.expob),
                      debug_outstr_value_BM (_.avalv, CURFRAME_BM, 0),
                      objectdbg2_BM (_.routprepob));
        if (_.avalv != NULL)
          {
            _.typob =
              miniscan_var_BM (_.expob, _.routprepob, depth, _.fromob,
                               CURFRAME_BM);
            DBGPRINTF_BM ("emit_expr expob=%s avalv=%s typob=%s",
                          objectdbg_BM (_.expob),
                          debug_outstr_value_BM (_.avalv, CURFRAME_BM, 0),
                          objectdbg2_BM (_.typob));
            if (_.typob == BMP_value)
              {
                objstrbufferprintfpayl_BM (_.modgenob, " _.v%s", varidbuf);
              }
            else if (_.typob == BMP_object)
              {
                if (isnode_BM (_.avalv)
                    && nodeconn_BM (_.avalv) == k_constants)
                  {
                    char modulidbuf[32];
                    memset (modulidbuf, 0, sizeof (modulidbuf));
                    idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
                    _.constantsv = objgetattr_BM (_.modgenob, k_constants);
                    WEAKASSERTRET_BM (isset_BM (_.constantsv));
                    int kix =
                      setelemindex_BM (setcast_BM (_.constantsv), _.expob);
                    WEAKASSERTRET_BM (kix >= 0);
                    objstrbufferprintfpayl_BM (_.modgenob,
                                               " (" CONSTOBARRPREFIX_BM "%s"
                                               ROUTINESUFFIX_BM
                                               "[%d] /*|%s*/)", modulidbuf,
                                               kix, objectdbg2_BM (_.expob));
                  }
                else
                  objstrbufferprintfpayl_BM (_.modgenob, " _.o%s", varidbuf);
              }
            else if (_.typob == BMP_int)
              {
                objstrbufferprintfpayl_BM (_.modgenob, " _.n%s", varidbuf);
              }
            else
              FAILHERE (makenode2_BM (k_variable, _.expob, _.typob));
            LOCALJUSTRETURN_BM ();
          }
        else
          FAILHERE (BMP_object);
        break;
      }
    case tyNode_BM:
      {
        _.connob = nodeconn_BM (_.expv);
        objlock_BM (_.connob);
        unsigned arity = nodewidth_BM (_.expv);
        char modulidbuf[32];
        memset (modulidbuf, 0, sizeof (modulidbuf));
        idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
        DBGPRINTF_BM
          ("emit_expression connob %s arity %d routprepob %s modgenob %s fromob %s expv %s before",
           objectdbg_BM (_.connob), arity, objectdbg1_BM (_.routprepob),
           objectdbg2_BM (_.modgenob), objectdbg3_BM (_.fromob),
           debug_outstr_value_BM (_.expv, CURFRAME_BM, 0));
        if (_.connob == k_exclam && arity == 1)
          {
            _.exclamv = nodenthson_BM (_.expv, 0);
            if (isobject_BM (_.exclamv))
              {
                _.exclamob = (objectval_tyBM *) _.exclamv;
                _.constantsv = objgetattr_BM (_.modgenob, k_constants);
                DBGPRINTF_BM ("emit_expression !exclamob %s constants %s",
                              objectdbg_BM (_.exclamob),
                              debug_outstr_value_BM (_.constantsv,
                                                     CURFRAME_BM, 0));
                WEAKASSERTRET_BM (isset_BM (_.constantsv));
                int kix =
                  setelemindex_BM (setcast_BM (_.constantsv), _.exclamob);
                WEAKASSERTRET_BM (kix >= 0);
                objstrbufferprintfpayl_BM (_.modgenob,
                                           " (" CONSTOBARRPREFIX_BM "%s"
                                           ROUTINESUFFIX_BM "[%d] /*!%s*/)",
                                           modulidbuf, kix,
                                           objectdbg_BM (_.exclamob));
              }
            else if (istaggedint_BM (_.exclamv))
              {
                intptr_t numexclam = getint_BM (_.exclamv);
                objstrbufferprintfpayl_BM (_.modgenob,
                                           " ((value_ty)%#llx /*!%lld*/)",
                                           (long long) _.exclamv,
                                           (long long) numexclam);
              }
            else
              WEAKASSERTRET_BM (false
                                &&
                                "unimplemented miniemit_expression_BM exclam");
          }
        else if (objectisinstance_BM (_.connob, k_basiclo_connective))
          {
            _.resv = send5_BM (_.connob, k_miniemit_node_conn,  //
                               CURFRAME_BM,     //
                               _.expv,
                               _.modgenob,
                               _.routprepob, taggedint_BM (depth), _.fromob);
            DBGPRINTF_BM ("emit_expression miniscan_node_conn->%s done resv=%s",        //
                          objectdbg_BM (_.connob),      //
                          debug_outstr_value_BM (_.resv, CURFRAME_BM, 0));
            if (!_.resv)
              FAILHERE (NULL);
          }
        else
          FAILHERE (BMP_node);
        objunlock_BM (_.connob);
        LOCALJUSTRETURN_BM ();
      }
    default:
      FAILHERE (NULL);
    }
  DBGPRINTF_BM
    ("emit_expression unimplemented for expv %s modgen %s routprep %s",
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg_BM (_.modgenob), objectdbg1_BM (_.routprepob));
  WEAKASSERTRET_BM (false && "unimplemented miniemit_expression_BM");
#warning unimplemented miniemit_expression_BM
  LOCALJUSTRETURN_BM ();
failure:
#undef FAILHERE
  DBGPRINTF_BM ("miniemit_expression_BM failin %d expv %s routprep %s cause %s", failin, debug_outstr_value_BM (_.expv, CURFRAME_BM, 0), objectdbg2_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode4_BM (k_emit_expression, expv, _.routprepob, _.modgenob,
                  _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniemit_expression_BM */



void
miniemit_var_BM (struct stackframe_stBM *stkf, objectval_tyBM * refob,
                 objectval_tyBM * modgenob, objectval_tyBM * routprepob,
                 objectval_tyBM * fromob, int depth)
{
  objectval_tyBM *k_emit_reference = BMK_6qzzDyr2eIo_3SapnOUpg6S;
  objectval_tyBM *k_variable = BMK_5ucAZimYynS_4VA0XHvr1nW;
  //objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
  //objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  //objectval_tyBM *k_object = BMK_7T9OwSFlgov_0wVJaK1eZbn;
  LOCALFRAME_BM (stkf, /*descr: */ k_emit_reference,
                 objectval_tyBM * refob; objectval_tyBM * modgenob;
                 objectval_tyBM * routprepob; objectval_tyBM * fromob;
                 value_tyBM avalv; objectval_tyBM * connob;
                 objectval_tyBM * typob; value_tyBM errorv;
                 value_tyBM causev;
    );
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.refob = objectcast_BM (refob);
  _.modgenob = objectcast_BM (modgenob);
  _.routprepob = objectcast_BM (routprepob);
  _.fromob = objectcast_BM (fromob);
  WEAKASSERTRET_BM (_.refob);
  WEAKASSERTRET_BM (_.modgenob);
  WEAKASSERTRET_BM (_.routprepob);
  DBGPRINTF_BM
    ("miniemit_var_BM start refob %s modgen %s routprep %s depth %d",
     objectdbg_BM (_.refob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  _.avalv = objassocgetattrpayl_BM (_.routprepob, _.refob);
  DBGPRINTF_BM ("miniemit_var_BM refob %s avalv %s", objectdbg_BM (_.refob),    //
                debug_outstr_value_BM (_.avalv, CURFRAME_BM, 0));
  char varidbuf[32];
  memset (varidbuf, 0, sizeof (varidbuf));
  idtocbuf32_BM (objid_BM (_.refob), varidbuf);
  if (_.avalv != NULL)
    {
      _.typob =
        miniscan_var_BM (_.refob, _.routprepob, depth, _.fromob, CURFRAME_BM);
      DBGPRINTF_BM ("emit_var refob=%s avalv=%s typob=%s",
                    objectdbg_BM (_.refob),
                    debug_outstr_value_BM (_.avalv, CURFRAME_BM, 0),
                    objectdbg2_BM (_.typob));
      if (_.typob == BMP_value)
        {
          objstrbufferprintfpayl_BM (_.modgenob, " _.v%s", varidbuf);
        }
      else if (_.typob == BMP_object)
        {
          objstrbufferprintfpayl_BM (_.modgenob, " _.o%s", varidbuf);
        }
      else if (_.typob == BMP_int)
        {
          objstrbufferprintfpayl_BM (_.modgenob, " _.n%s", varidbuf);
        }
      else
        FAILHERE (makenode3_BM (k_variable, _.refob, _.avalv, _.typob));
    }
  else
    FAILHERE (NULL);
  LOCALJUSTRETURN_BM ();
failure:
#undef FAILHERE
  DBGPRINTF_BM ("miniemit_var_BM failin %d ref %s routprep %s cause %s",        //
                failin, objectdbg_BM (_.refob), objectdbg1_BM (_.routprepob),   //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode4_BM (k_emit_reference, refob, _.routprepob, _.modgenob,
                  _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniemit_var_BM */



//  miniemit_node_conn°basiclo_primitive _0BaXSIhDAHO_9x6t4zdbUhj

extern objrout_sigBM ROUTINEOBJNAME_BM (_0BaXSIhDAHO_9x6t4zdbUhj);

value_tyBM
ROUTINEOBJNAME_BM (_0BaXSIhDAHO_9x6t4zdbUhj)    // miniemit_node_conn°basiclo_primitive
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // connob
 const value_tyBM arg2,         // expv
 const value_tyBM arg3,         // modgenob
 const value_tyBM arg4,         // routprepob
 const quasinode_tyBM * restargs)       // depth, fromob
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_0BaXSIhDAHO_9x6t4zdbUhj,
                 value_tyBM resultv;
                 objectval_tyBM * connob;
                 value_tyBM expv;       //
                 value_tyBM cursubexpv; //
                 value_tyBM connargsv; value_tyBM conncexpansionv;
                 value_tyBM connchunkv; value_tyBM chunksonv;
                 objectval_tyBM * modgenob; objectval_tyBM * routprepob;
                 objectval_tyBM * fromob; objectval_tyBM * substob;
                 objectval_tyBM * varob; objectval_tyBM * curargob;
                 objectval_tyBM * chunkob; objectval_tyBM * emptybindhsetob;
                 value_tyBM errorv; value_tyBM causev;
    );
  int depth = -1;
  objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  objectval_tyBM *k_cexpansion = BMK_7yoiT31GmV4_2iTjHx3P2hb;
  objectval_tyBM *k_chunk = BMK_3pQnBS9ZjkQ_0uGmqUUhAum;
  objectval_tyBM *k_assoc_object = BMK_6ZQ05nCv3Ys_8LA6B5LkZgm;
  objectval_tyBM *k_hset_object = BMK_8c9otZ4pwR6_55k81qyyYV2;
  objectval_tyBM *k_variable = BMK_5ucAZimYynS_4VA0XHvr1nW;
  objectval_tyBM *k_emit_expression = BMK_9lXSe7DrOl6_7hghYt0LhTF;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.connob = objectcast_BM (arg1);
  _.expv = arg2;
  _.modgenob = objectcast_BM (arg3);
  _.routprepob = objectcast_BM (arg4);
  unsigned nbrestargs = treewidth_BM ((value_tyBM) restargs);
  if (nbrestargs >= 2)
    {
      if (istaggedint_BM (restargs->nodt_sons[0]))
        depth = getint_BM (restargs->nodt_sons[0]);
      _.fromob = objectcast_BM (restargs->nodt_sons[1]);
    }
  WEAKASSERT_BM (_.connob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (_.routprepob);
  DBGPRINTF_BM
    ("miniemit_node_conn°basiclo_primitive start connob=%s expv=%s modgenob=%s\n"
     ".. routprepob=%s depth#%d fromob=%s", objectdbg_BM (_.connob),
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg1_BM (_.modgenob), objectdbg2_BM (_.routprepob), depth,
     objectdbg3_BM (_.fromob));
  _.connargsv = objgetattr_BM (_.connob, k_arguments);
  _.conncexpansionv = objgetattr_BM (_.connob, k_cexpansion);
  DBGPRINTF_BM ("miniemit_node_conn°basiclo_primitive connob=%s connargs=%s conncexpansion=%s",        //
                objectdbg_BM (_.connob),        //
                debug_outstr_value_BM (_.connargsv, CURFRAME_BM, 0),
                debug_outstr_value_BM (_.conncexpansionv, CURFRAME_BM, 0));
  WEAKASSERT_BM (istuple_BM (_.connargsv));
  WEAKASSERT_BM (isnode_BM (_.conncexpansionv)
                 && nodeconn_BM (_.conncexpansionv) == k_chunk);
  unsigned nbargs = tuplesize_BM (_.connargsv);
  unsigned nbcexp = nodewidth_BM (_.conncexpansionv);
  _.substob = makeobj_BM ();
  objputclass_BM (_.substob, k_assoc_object);
  objputassocpayl_BM (_.substob, 3 * nbargs / 2 + 2);
  DBGPRINTF_BM
    ("miniemit_node_conn°basiclo_primitive connob=%s substob=%s nbargs=%d nbcexp=%d",
     objectdbg_BM (_.connob), objectdbg1_BM (_.substob), nbargs, nbcexp);
  for (unsigned aix = 0; aix < nbargs; aix++)
    {
      _.curargob = tuplecompnth_BM (_.connargsv, aix);
      _.cursubexpv = nodenthson_BM (_.expv, aix);
      DBGPRINTF_BM
        ("miniemit_node_conn°basiclo_primitive connob=%s aix#%d curargob=%s cursubexp=%s",
         objectdbg_BM (_.connob), aix, objectdbg1_BM (_.curargob),
         debug_outstr_value_BM (_.cursubexpv, CURFRAME_BM, 0));
      if (_.cursubexpv)
        objassocaddattrpayl_BM (_.substob, _.curargob, _.cursubexpv);
      else
        {
          if (!_.emptybindhsetob)
            {
              _.emptybindhsetob = makeobj_BM ();
              objputclass_BM (_.emptybindhsetob, k_hset_object);
              objputhashsetpayl_BM (_.emptybindhsetob, 5 * nbargs / 4 + 1);
            }
          objhashsetaddpayl_BM (_.emptybindhsetob, _.curargob);
        }
    };
  DBGPRINTF_BM
    ("miniemit_node_conn°basiclo_primitive connob=%s substob=%s emptybindhsetob=%s nbcexp#%d",
     objectdbg_BM (_.connob), objectdbg1_BM (_.substob),
     objectdbg2_BM (_.emptybindhsetob), nbcexp);
  for (unsigned cix = 0; cix < nbcexp; cix++)
    {
      _.chunksonv = nodenthson_BM (_.conncexpansionv, cix);
      if (isstring_BM (_.chunksonv))
        objstrbufferappendcstrpayl_BM (_.modgenob,
                                       bytstring_BM (_.chunksonv));
      else if (istaggedint_BM (_.chunksonv))
        objstrbufferprintfpayl_BM (_.modgenob, "%lld",
                                   (long long) getint_BM (_.chunksonv));
      else if (isobject_BM (_.chunksonv))
        {
          _.chunkob = (objectval_tyBM *) (_.chunksonv);
          DBGPRINTF_BM
            ("miniemit_node_conn°basiclo_primitive connob=%s cix#%d chunkob=%s",
             objectdbg_BM (_.connob), cix, objectdbg1_BM (_.chunkob));
          const char *chunkname = findobjectname_BM (_.chunkob);
          if (chunkname)
            objstrbufferappendcstrpayl_BM (_.modgenob, chunkname);
          else
            {
              char chunkidbuf[32];
              memset (chunkidbuf, 0, sizeof (chunkidbuf));
              idtocbuf32_BM (objid_BM (_.chunkob), chunkidbuf);
              objstrbufferappendcstrpayl_BM (_.modgenob, chunkidbuf);
            }
        }
      else if (isnode_BM (_.chunksonv)
               && nodeconn_BM (_.chunksonv) == k_variable
               && nodewidth_BM (_.chunksonv) == 1)
        {
          _.varob = objectcast_BM (nodenthson_BM (_.chunksonv, 0));
          WEAKASSERT_BM (_.varob);
          _.cursubexpv = objassocgetattrpayl_BM (_.substob, _.varob);
          if (_.cursubexpv)
            {
              miniemit_expression_BM (CURFRAME_BM, _.cursubexpv,
                                      _.modgenob,
                                      _.routprepob, _.fromob, depth + 1);
            }
          else if (objhashsetcontainspayl_BM (_.emptybindhsetob, _.varob))
            {
              objstrbufferprintfpayl_BM (_.modgenob, " NULL");
            }
          else
            {
              DBGPRINTF_BM
                ("miniemit_node_conn°basiclo_primitive connob=%s unbound varob=%s cix#%d",
                 objectdbg_BM (_.connob), objectdbg1_BM (_.varob), cix);
              WEAKASSERT_BM (false
                             &&
                             "unbound var in chunk _0BaXSIhDAHO_9x6t4zdbUhj routine");
            }
        }
      else
        FAILHERE (makenode2_BM (k_chunk, _.chunksonv, taggedint_BM (cix)));

    }
  DBGPRINTF_BM
    ("miniemit_node_conn°basiclo_primitive connob=%s exp=%s ended",
     objectdbg_BM (_.connob), debug_outstr_value_BM (_.expv, CURFRAME_BM, 0));
  LOCALRETURN_BM (_.connob);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("miniemit_node_conn°basiclo_primitive failin %d connob %s routprep %s cause %s",       //
                failin, objectdbg_BM (_.connob), objectdbg1_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode5_BM (k_emit_expression, _.connob, _.routprepob, _.modgenob,
                  _.expv, _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniemit_node_conn°basiclo_primitive _0BaXSIhDAHO_9x6t4zdbUhj */




//miniscan_node_conn°basiclo_simple_connective _2ROGZRBpeCl_6HhgOZ5Uj7F

extern objrout_sigBM ROUTINEOBJNAME_BM (_2ROGZRBpeCl_6HhgOZ5Uj7F);

value_tyBM
ROUTINEOBJNAME_BM (_2ROGZRBpeCl_6HhgOZ5Uj7F)    //miniscan_node_conn°basiclo_simple_connective
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // connob
 const value_tyBM arg2,         // routprepob
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // expv
 const quasinode_tyBM * restargs /*fromob. */ )
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_2ROGZRBpeCl_6HhgOZ5Uj7F,
                 objectval_tyBM * connob;       //
                 objectval_tyBM * routprepob;   //
                 value_tyBM expv;       //
                 objectval_tyBM * fromob;       //
                 value_tyBM resultv;    //
                 value_tyBM funv;       //
                 value_tyBM errorv;     //
                 value_tyBM causev;     //
    );
  objectval_tyBM *k_miniscan_node_conn = BMK_5EGLdtUAQxA_1nebCsDKqOF;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.connob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  int depth = getint_BM (arg3);
  _.expv = arg4;
  _.fromob = objectcast_BM (treenthson_BM ((value_tyBM) restargs, 0));
  DBGPRINTF_BM ("miniscan_node_conn°basiclo_simple_connective start connob %s" //
                "\n... routprepob %s depth %d expv %s fromob %s",       //
                objectdbg_BM (_.connob), objectdbg1_BM (_.routprepob), depth,   //
                debug_outstr_value_BM (_.expv, CURFRAME_BM, 0), //
                objectdbg2_BM (_.fromob));
  if (!_.routprepob)
    FAILHERE (NULL);
  if (!_.fromob)
    FAILHERE (NULL);
  objlock_BM (_.connob);
  _.funv = objgetattr_BM (_.connob, k_miniscan_node_conn);
  objunlock_BM (_.connob);
  if (!_.funv)
    FAILHERE (k_miniscan_node_conn);
  DBGPRINTF_BM
    ("miniscan_node_conn°basiclo_simple_connective connob %s has funv %s",
     objectdbg_BM (_.connob), debug_outstr_value_BM (_.funv, CURFRAME_BM, 0));
  if (!isobject_BM (_.funv) && !isclosure_BM (_.funv))
    FAILHERE (makenode1_BM (k_miniscan_node_conn, _.funv));
  _.resultv = apply4_BM (_.funv, CURFRAME_BM,
                         _.routprepob, taggedint_BM (depth), _.expv,
                         _.fromob);
  DBGPRINTF_BM ("miniscan_node_conn°basiclo_simple_connective connob %s expv %s routprepob %s resultv %s",     //
                objectdbg_BM (_.connob), debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),        //
                objectdbg1_BM (_.routprepob),
                debug_outstr_value_BM (_.resultv, CURFRAME_BM, 0));
  if (!_.resultv)
    FAILHERE (_.funv);
  LOCALRETURN_BM (_.resultv);
failure:
#undef FAILHERE
  DBGPRINTF_BM ("failure miniscan_node_conn°basiclo_simple_connective failin %d\n"     //
                ".. connob %s expv %s routprepob %s causev %s", failin, objectdbg_BM (_.connob),        //
                debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
                objectdbg1_BM (_.routprepob),
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode5_BM (k_miniscan_node_conn, _.expv, _.routprepob,
                  taggedint_BM (depth), _.fromob, _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniscan_node_conn°basiclo_simple_connective _2ROGZRBpeCl_6HhgOZ5Uj7F */



// miniemit_node_conn°basiclo_simple_connective _48l341uEMuG_3gJ2HHIwYhn

extern objrout_sigBM ROUTINEOBJNAME_BM (_48l341uEMuG_3gJ2HHIwYhn);

value_tyBM
ROUTINEOBJNAME_BM (_48l341uEMuG_3gJ2HHIwYhn)    //miniemit_node_conn°basiclo_simple_connective
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // connob
 const value_tyBM arg2,         // expv
 const value_tyBM arg3,         // modgenob
 const value_tyBM arg4,         // routprepob
 const quasinode_tyBM * restargs /*depth, fromob. */ )
{
  objectval_tyBM *k_emit_expression = BMK_9lXSe7DrOl6_7hghYt0LhTF;
  objectval_tyBM *k_miniemit_node_conn = BMK_7L782rSgJBB_9vjsBdqAoz7;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_48l341uEMuG_3gJ2HHIwYhn,
                 value_tyBM resultv;
                 objectval_tyBM * connob;
                 value_tyBM expv;       //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 value_tyBM funv;       //
                 value_tyBM errorv;     //
                 value_tyBM causev;
    );
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM) (Cause); goto failure; } while(0)
  _.connob = objectcast_BM (arg1);
  _.expv = arg2;
  _.modgenob = objectcast_BM (arg3);
  _.routprepob = objectcast_BM (arg4);
  unsigned nbrestargs = treewidth_BM ((value_tyBM) restargs);
  int depth = 0;
  if (nbrestargs >= 2)
    {
      if (istaggedint_BM (restargs->nodt_sons[0]))
        depth = getint_BM (restargs->nodt_sons[0]);
      _.fromob = objectcast_BM (restargs->nodt_sons[1]);
    }
  WEAKASSERT_BM (_.connob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (_.routprepob);
  DBGPRINTF_BM
    ("miniemit_node_conn°basiclo_simple_connective start connob=%s expv=%s modgenob=%s\n"
     ".. routprepob=%s depth#%d fromob=%s", objectdbg_BM (_.connob),
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth, objectdbg3_BM (_.fromob));
  objlock_BM (_.connob);
  _.funv = objgetattr_BM (_.connob, k_miniemit_node_conn);
  objunlock_BM (_.connob);
  if (!_.funv)
    FAILHERE (k_miniemit_node_conn);
  DBGPRINTF_BM
    ("miniemit_node_conn°basiclo_simple_connective connob %s has funv %s",
     objectdbg_BM (_.connob), debug_outstr_value_BM (_.funv, CURFRAME_BM, 0));
  if (!isobject_BM (_.funv) && !isclosure_BM (_.funv))
    FAILHERE (makenode1_BM (k_miniemit_node_conn, _.funv));
  _.resultv = apply5_BM (_.funv, CURFRAME_BM,
                         _.expv, _.modgenob, _.routprepob,
                         taggedint_BM (depth), _.fromob);
  DBGPRINTF_BM ("miniemit_node_conn°basiclo_simple_connective connob %s expv %s routprepob %s resultv %s",     //
                objectdbg_BM (_.connob),        //
                debug_outstr_value_BM (_.expv, CURFRAME_BM, 0), //
                objectdbg1_BM (_.routprepob),
                debug_outstr_value_BM (_.resultv, CURFRAME_BM, 0));
  if (!_.resultv)
    FAILHERE (_.funv);
  LOCALRETURN_BM (_.resultv);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("miniemit_node_conn°basiclo_simple_connective failin %d connob %s routprep %s cause %s",       //
                failin, objectdbg_BM (_.connob), objectdbg1_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode5_BM (k_emit_expression, _.connob, _.routprepob, _.modgenob,
                  _.expv, _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniemit_node_conn°basiclo_simple_connective _48l341uEMuG_3gJ2HHIwYhn */






// emit_statement°basiclo_assign _22wwtRd69oP_3IH6VRfTzu6
extern objrout_sigBM ROUTINEOBJNAME_BM (_22wwtRd69oP_3IH6VRfTzu6);

value_tyBM
ROUTINEOBJNAME_BM (_22wwtRd69oP_3IH6VRfTzu6)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // stmtob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_22wwtRd69oP_3IH6VRfTzu6,
                 objectval_tyBM * stmtob; objectval_tyBM * modgenob;
                 objectval_tyBM * routprepob; objectval_tyBM * destob;
                 value_tyBM srcexpv; value_tyBM resultv;
                 value_tyBM errorv;
                 value_tyBM causev;
    );
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  _.stmtob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  WEAKASSERT_BM (_.stmtob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (arg4));
  int depth = getint_BM (arg4);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("emit_statement°basiclo_assign start stmtob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  WEAKASSERT_BM (objnbcomps_BM (_.stmtob) == 2);
  _.destob = objectcast_BM (objgetcomp_BM (_.stmtob, 0));
  _.srcexpv = objgetcomp_BM (_.stmtob, 1);
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("emit_statement°basiclo_assign start stmtob=%s destob=%s srcexpv=%s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.destob),
     debug_outstr_value_BM (_.srcexpv, CURFRAME_BM, 0));
  miniemit_var_BM (CURFRAME_BM, _.destob, _.modgenob, _.routprepob, _.stmtob,
                   0);
  objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
  objstrbufferprintfpayl_BM (_.modgenob, " = //assign %s\n",
                             objectdbg_BM (_.stmtob));
  miniemit_expression_BM (CURFRAME_BM, _.srcexpv, _.modgenob, _.routprepob,
                          _.stmtob, 0);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, ";\n");
  LOCALRETURN_BM (_.stmtob);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("emit_statement°basiclo_assign failin %d stmtob %s routprep %s cause %s",      //
                failin, objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode5_BM (k_emit_statement, _.stmtob, _.routprepob, _.modgenob,
                  taggedint_BM (depth), _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_statement°basiclo_assign  _22wwtRd69oP_3IH6VRfTzu6 */



////
// emit_statement°basiclo_return 
extern objrout_sigBM ROUTINEOBJNAME_BM (_7DErEWkQBmz_5hPwF6ARmJ7);

value_tyBM
ROUTINEOBJNAME_BM (_7DErEWkQBmz_5hPwF6ARmJ7)    //emit_statement°basiclo_return 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // stmtob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ NULL,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * retvarob;     //
                 objectval_tyBM * routob;       //
                 value_tyBM srcexpv;    //
                 value_tyBM resultv;    //
                 value_tyBM errorv;     //
                 value_tyBM causev;     //
    );
  //objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_return = BMK_2DH0ucElTgh_62vxjxLcfev;
  objectval_tyBM *k_prepare_routine = BMK_6qi1DW0Ygkl_4Aqdxq4n5IV;
  const objectval_tyBM *k_result = BMK_7bD9VtDkGSn_7lxHeYuuFLR;
  _.stmtob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  WEAKASSERT_BM (_.stmtob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (arg4));
  int depth = getint_BM (arg4);
  DBGPRINTF_BM
    ("emit_statement°basiclo_return start stmtob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  _.srcexpv = objgetattr_BM (_.stmtob, k_return);
  DBGPRINTF_BM ("emit_statement°basiclo_return stmtob=%s srcexpv=%s", objectdbg_BM (_.stmtob), //
                debug_outstr_value_BM (_.srcexpv, CURFRAME_BM, 0));
  // compute the retvarob from routprepob...
  _.routob = objgetattr_BM (_.routprepob, k_prepare_routine);
  _.retvarob = objgetattr_BM (_.routob, k_result);
  char routidbuf[32];
  memset (routidbuf, 0, sizeof (routidbuf));
  idtocbuf32_BM (objid_BM (_.routob), routidbuf);
  /// we could need a *null() primitive...
  DBGPRINTF_BM ("emit_statement°basiclo_return stmtob=%s routob=%s retvarob=%s", objectdbg_BM (_.stmtob),      //
                objectdbg_BM (_.routob),        //
                objectdbg_BM (_.retvarob));
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, "/*return %s:*/ ",
                             objectdbg_BM (_.stmtob));
  if (_.srcexpv)
    {
      DBGPRINTF_BM
        ("emit_statement°basiclo_return stmtob=%s routprepob=%s retvarob=%s srcexp=%s",
         objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),
         objectdbg2_BM (_.retvarob), debug_outstr_value_BM (_.srcexpv,
                                                            CURFRAME_BM, 0));
      miniemit_var_BM (CURFRAME_BM, _.retvarob, _.modgenob, _.routprepob,
                       _.stmtob, depth);
      objstrbufferprintfpayl_BM (_.modgenob, " = // returned\n");
      objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
      miniemit_expression_BM (CURFRAME_BM, _.srcexpv, _.modgenob,
                              _.routprepob, _.stmtob, depth);
      objstrbuffersetindentpayl_BM (_.modgenob, depth);
      objstrbufferprintfpayl_BM (_.modgenob, ";\n");
    }
  objstrbufferprintfpayl_BM (_.modgenob, " goto epilog%s;\n", routidbuf);
  LOCALRETURN_BM (_.stmtob);
}                               /* end emit_statement°basiclo_return _7DErEWkQBmz_5hPwF6ARmJ7 */



// emit_statement°basiclo_exit _4hS1jncZQAY_9pGS66eIlw9

extern objrout_sigBM ROUTINEOBJNAME_BM (_4hS1jncZQAY_9pGS66eIlw9);

value_tyBM
ROUTINEOBJNAME_BM (_4hS1jncZQAY_9pGS66eIlw9)    //emit_statement°basiclo_exit
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // stmtob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_exit = BMK_41gbFesxqzD_3l56OLiNdl2;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_4hS1jncZQAY_9pGS66eIlw9,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * routob;       //
                 objectval_tyBM * exitob;       //
                 value_tyBM errorv;     //
                 value_tyBM causev;     //
    );
  _.stmtob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  bool gotmessage = false;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("emit_statement°basiclo_exit start stmtob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  _.exitob = objectcast_BM (objgetattr_BM (_.stmtob, k_exit));
  if (!_.exitob)
    FAILHERE (k_exit);
  char exitidbuf[32];
  memset (exitidbuf, 0, sizeof (exitidbuf));
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, "// exit %s\n",
                             objectdbg_BM (_.stmtob));
  idtocbuf32_BM (objid_BM (_.exitob), exitidbuf);
  objstrbufferprintfpayl_BM (_.modgenob, "goto endblock_%s;\n", exitidbuf);
  LOCALRETURN_BM (_.exitob);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("emit_statement°basiclo_exit failin %d stmtob %s routprep %s cause %s",        //
                failin, objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode5_BM (k_emit_statement, _.stmtob, _.routprepob, _.modgenob,
                  taggedint_BM (depth), _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_statement°basiclo_exit _4hS1jncZQAY_9pGS66eIlw9 */



// emit_statement°basiclo_wrong _1EFhqSytjSK_9Uchza7qmUD

extern objrout_sigBM ROUTINEOBJNAME_BM (_1EFhqSytjSK_9Uchza7qmUD);

value_tyBM
ROUTINEOBJNAME_BM (_1EFhqSytjSK_9Uchza7qmUD)    //emit_statement°basiclo_wrong 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // stmtob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  objectval_tyBM *k_wrong = BMK_2qtlhVU3gil_1SmwpjiT7Jm;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_1EFhqSytjSK_9Uchza7qmUD,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * routob;       //
                 value_tyBM * subexpv;  //
                 value_tyBM * firstsubexpv;     //
                 objectval_tyBM * subtypob;     //
                 value_tyBM resultv;    //
                 value_tyBM errorv;     //
                 value_tyBM causev;     //
    );
  _.stmtob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  bool gotmessage = false;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("emit_statement°basiclo_wrong start stmtob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  WEAKASSERT_BM (_.stmtob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (arg4));
  int stmtlen = objnbcomps_BM (_.stmtob);
  _.firstsubexpv = objgetcomp_BM (_.stmtob, 0);
  char stmtidbuf[32];
  memset (stmtidbuf, 0, sizeof (stmtidbuf));
  idtocbuf32_BM (objid_BM (_.stmtob), stmtidbuf);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob, "{ // wrong %s\n", stmtidbuf);
  if (isstring_BM (_.firstsubexpv))
    {
      gotmessage = true;
      objstrbufferprintfpayl_BM (_.modgenob, "#error wrong %s: ", stmtidbuf);
      objstrbufferencodedcpayl_BM (_.modgenob, bytstring_BM (_.firstsubexpv),
                                   lenstring_BM (_.firstsubexpv));
      objstrbuffernewlinepayl_BM (_.modgenob);
    }
  else
    {
      objstrbuffernewlinepayl_BM (_.modgenob);
      objstrbufferprintfpayl_BM (_.modgenob, "#error wrong %s\n", stmtidbuf);
    }
  for (int ix = gotmessage ? 1 : 0; ix < stmtlen; ix++)
    {
      _.subexpv = objgetcomp_BM (_.stmtob, ix);
      _.subtypob =
        miniscan_expr_BM (_.subexpv, _.routprepob, depth, _.stmtob,
                          CURFRAME_BM);
      if (!_.subtypob)
        FAILHERE (makenode2_BM (k_curcomp, _.subexpv, taggedint_BM (ix)));
      objstrbufferprintfpayl_BM (_.modgenob, "// wrong %s #%d typed %s:\n",
                                 stmtidbuf, ix, objectdbg_BM (_.subtypob));
      char *submsg =
        strdup (debug_outstr_value_BM (_.subexpv, CURFRAME_BM, 0));
      if (!submsg)
        FATAL_BM ("failed to strdup wrong %s arg #%d", stmtidbuf, ix);
      char *nextline = NULL;
      for (char *pc = submsg; pc != NULL && *pc != 0; pc = nextline)
        {
          nextline = NULL;
          const char *nl = strchr (pc, '\n');
          if (nl)
            nextline = (char *) nl + 1;
          const char *ret = strchr (pc, '\r');
          if (ret && ret < nextline)
            nextline = (char *) ret + 1;
          const char *ff = strchr (pc, '\f');
          if (ff && ff < nextline)
            nextline = (char *) ff + 1;
          if (nextline && nextline > submsg)
            nextline[-1] = (char) 0;
          objstrbufferprintfpayl_BM (_.modgenob, "//// %s\n", pc);
        }
      free (submsg);
    }
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob, "} // end wrong %s\n", stmtidbuf);
  LOCALRETURN_BM (_.stmtob);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("emit_statement°basiclo_wrong failin %d stmtob %s routprep %s cause %s",       //
                failin, objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode5_BM (k_emit_statement, _.stmtob, _.routprepob, _.modgenob,
                  taggedint_BM (depth), _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_statement°basiclo_wrong _1EFhqSytjSK_9Uchza7qmUD */


////////////////////////////////////////////////////////////////
/// for the routine to emit_module in plain_module-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_1gME6zn82Kf_8hzWibLFRfz);

value_tyBM
ROUTINEOBJNAME_BM (_1gME6zn82Kf_8hzWibLFRfz)    // emit_module°plain_module
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving module
 const value_tyBM arg2,         /* optional dumperob or prefix */
 const value_tyBM arg3,         // optional closgenv closure to process the module generator
 const value_tyBM arg4 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ BMK_1gME6zn82Kf_8hzWibLFRfz,
                 objectval_tyBM * modulob;      //
                 objectval_tyBM * modgenob;     //
                 value_tyBM resprep;    //
                 value_tyBM resgen;     //
                 value_tyBM prefixv;    //
                 objectval_tyBM * dumpob;
                 value_tyBM errorv;     //
                 value_tyBM closgenv;   //
                 value_tyBM srcdirstrv; //
                 value_tyBM causev;     //
    );
  // all these are heap allocated, e.g. strdup-ed or asprintf-ed
  char *srcdirstr = NULL;
  char *pardirstr = NULL;
  char *realpardirstr = NULL;
  char *realsrcdirstr = NULL;
  char *srcpathstr = NULL;
  char *prevsrcpathstr = NULL;
  objectval_tyBM *k_simple_module_generation = BMK_2HlKptD03wA_7JJCG7lN5nS;
  objectval_tyBM *k_prepare_module = BMK_17mrxkMdNtH_2CduQ2WDIy5;
  objectval_tyBM *k_plain_module = BMK_8g1WBJBhDT9_1QK8IcuWYx2;
  objectval_tyBM *k_generate_module = BMK_9mq0jsuz4XQ_4doHfd987Q6;
  objectval_tyBM *kk_deferred_compilation_of_module =
    BMK_9EqBenFWb40_86MuuXslynk;
  if (!isobject_BM (arg1))
    LOCALRETURN_BM (NULL);
  _.modulob = (objectval_tyBM *) arg1;
  _.prefixv = arg2;
  _.closgenv = arg3;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  char modulidbuf[32];
  memset (modulidbuf, 0, sizeof (modulidbuf));
  idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
  if (isstring_BM (_.prefixv))
    srcdirstr = strdup (bytstring_BM (_.prefixv));
  else if (isobject_BM (_.prefixv))
    {
      struct dumper_stBM *du =
        obdumpgetdumper_BM ((objectval_tyBM *) _.prefixv);
      if (du)
        {
          _.dumpob = (objectval_tyBM *) _.prefixv;
          asprintf (&srcdirstr, "%s/modules", bytstring_BM (du->dump_dir));
        }
      else
        FAILHERE (makenode1_BM (BMP_object, _.prefixv));
    }
  else
    srcdirstr = strdup ("modules");
  if (!srcdirstr)
    FATAL_BM ("failed to compute source dir for module %s - %m",
              objectdbg_BM (_.modulob));
  if (g_mkdir_with_parents (srcdirstr, 0750))
    {
      fprintf (stderr, "cannot mkdir with parents %s (%m)\n", srcdirstr);
      FAILHERE (makestring_BM (srcdirstr));
    }
  DBGPRINTF_BM ("emit_module°plain_module modulob %s /%s srcdirstr '%s'",
                objectdbg_BM (_.modulob), modulidbuf, srcdirstr);
  {
    realsrcdirstr = realpath (srcdirstr, NULL);
    if (!realsrcdirstr || !strchr (realsrcdirstr, '/'))
      FATAL_BM
        ("failed to compute real source dir for module %s from srcdirstr %s - %m",
         objectdbg_BM (_.modulob), srcdirstr);
    char *lastslash = strrchr (realsrcdirstr, '/');
    ASSERT_BM (lastslash != NULL);
    realpardirstr = malloc (lastslash - realsrcdirstr + 2);
    if (!realpardirstr)
      FATAL_BM ("failed to malloc realpardirstr of %d bytes",
                lastslash - realsrcdirstr + 2);
    memset (realpardirstr, 0, lastslash - realsrcdirstr + 2);
    memcpy (realpardirstr, realsrcdirstr, lastslash - realsrcdirstr);
  }
  DBGPRINTF_BM
    ("emit_module°plain_module modulob %s /%s realsrcdirstr '%s' realpardirstr '%s'",
     objectdbg_BM (_.modulob), modulidbuf, realsrcdirstr, realpardirstr);
  _.modgenob = makeobj_BM ();
  objputclass_BM (_.modgenob, k_simple_module_generation);
  objputattr_BM (_.modgenob, k_plain_module, _.modulob);
  objputstrbufferpayl_BM (_.modgenob, (1024 * 1024));
  objtouchnow_BM (_.modgenob);
  DBGPRINTF_BM
    ("@@emit_module°plain_module modulob=%s /%s made modgenob=%s *sbuf*",
     objectdbg_BM (_.modulob), modulidbuf, objectdbg1_BM (_.modgenob));
  if (isclosure_BM (_.closgenv))
    {
      DBGPRINTF_BM
        ("@@emit_module°plain_module modulob=%s closgenv=%s modgenob=%s",
         objectdbg_BM (_.modulob),
         debug_outstr_value_BM (_.closgenv, CURFRAME_BM, 0),
         objectdbg1_BM (_.modgenob));
      apply1_BM ((closure_tyBM *) _.closgenv, CURFRAME_BM, _.modgenob);
      DBGPRINTF_BM
        ("@@emit_module°plain_module modulob=%s after apply closgenv=%s modgenob=%s",
         objectdbg_BM (_.modulob),
         debug_outstr_value_BM (_.closgenv, CURFRAME_BM, 0),
         objectdbg1_BM (_.modgenob));
    }
  _.resprep = send1_BM (_.modulob, k_prepare_module, CURFRAME_BM, _.modgenob);
  DBGPRINTF_BM ("@@emit_module modulob=%s modgenob=%s resprep=%s",      //
                objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),   //
                debug_outstr_value_BM (_.resprep,       //
                                       CURFRAME_BM, 0));
  if (!_.resprep)
    {
      DBGPRINTF_BM ("@@emit_module modulob=%s prepare_module failed",
                    objectdbg_BM (_.modulob));
      LOCALRETURN_BM (NULL);
    }
  else
    DBGPRINTF_BM ("@@emit_module modulob=%s prepare_module done before generate_module modgenob=%s resprep=%s", //
                  objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob), //
                  debug_outstr_value_BM (_.resprep,     //
                                         CURFRAME_BM, 0));
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.modgenob));
  objstrbufferprintfpayl_BM (_.modgenob,
                             "// generated module %s in file " MODULEPREFIX_BM
                             "%s.c\n", objectdbg_BM (_.modulob), modulidbuf);

  _.resgen =
    send2_BM (_.modulob, k_generate_module, CURFRAME_BM, _.modgenob,
              _.resprep);
  if (!_.resgen)
    {
      DBGPRINTF_BM
        ("@@emit_module modulob=%s generate_module failed modgenob=%s sbuf.l%u '''\n%s\n'''\n",
         objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),
         objstrbufferlengthpayl_BM (_.modgenob),
         objstrbufferbytespayl_BM (_.modgenob));
      LOCALRETURN_BM (NULL);
    }
  else
    DBGPRINTF_BM
      ("@@emit_module°plain_module modulob=%s generate_module done resgen=%s",
       objectdbg_BM (_.modulob), debug_outstr_value_BM (_.resgen, CURFRAME_BM,
                                                        0));
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n\n" "// end of generated module %s in file "
                             MODULEPREFIX_BM "%s.c\n",
                             objectdbg_BM (_.modulob), modulidbuf);
  asprintf (&srcpathstr, "%s/" MODULEPREFIX_BM "%s.c", srcdirstr, modulidbuf);
  if (!srcpathstr)
    FATAL_BM ("failed to allocate srcpathstr dir %s modulidbuf %s", srcdirstr,
              modulidbuf);
  DBGPRINTF_BM
    ("emit_module°plain_module modulob %s /%s srcpathstr '%s' realsrcdirstr '%s'",
     objectdbg_BM (_.modulob), modulidbuf, srcpathstr, realsrcdirstr);
  if (!access (srcpathstr, F_OK))
    {
      char cwdbuf[80];
      memset (cwdbuf, 0, sizeof (cwdbuf));
      prevsrcpathstr = asprintf_prev_module_BM (realsrcdirstr, _.modulob);
      DBGPRINTF_BM
        ("emit_module°plain_module %s /%s rename srcpathstr '%s' -> prevsrcpathstr='%s' in %s",
         objectdbg_BM (_.modulob), modulidbuf,
         srcpathstr, prevsrcpathstr, (getcwd (cwdbuf, sizeof (cwdbuf))));
      if (rename (srcpathstr, prevsrcpathstr))
        FATAL_BM ("failed to rename '%s' -> '%s' in %s - %m", srcpathstr,
                  prevsrcpathstr, getcwd (cwdbuf, sizeof (cwdbuf)));
    }
  {
    char cwdbuf[80];
    DBGPRINTF_BM
      ("emit_module°plain_module %s /%s writing to srcpathstr '%s' in %s",
       objectdbg_BM (_.modulob), modulidbuf, srcpathstr,
       (memset (cwdbuf, 0, sizeof (cwdbuf)),
        getcwd (cwdbuf, sizeof (cwdbuf))));
  }
  objstrbufferwritetofilepayl_BM (_.modgenob, srcpathstr);
  {
    char *indentcmdstr = NULL;
    char *quotpardir = g_shell_quote (realpardirstr);
    if (prevsrcpathstr)
      {
        char *quotprev = g_shell_quote (prevsrcpathstr);
        asprintf (&indentcmdstr,
                  "make -f %s -C %s indentsinglemodule MODULEID=%s PREVIOUSMODULESOURCE=%s",
                  bismon_makefile, quotpardir, modulidbuf, quotprev);
        g_free (quotprev);
      }
    else
      asprintf (&indentcmdstr,
                "make -f %s -C %s indentsinglemodule MODULEID=%s",
                bismon_makefile, quotpardir, modulidbuf);
    if (!indentcmdstr)
      FATAL_BM ("failed to build indent command modulidbuf %s", modulidbuf);
    g_free (quotpardir), quotpardir = NULL;
    int fd = open (srcpathstr, O_RDONLY);
    if (fd < 0)
      FATAL_BM ("failed to open %s - %m", srcpathstr);
    flock (fd, LOCK_EX);
    DBGPRINTF_BM ("emit_module°plain_module indentcmdstr=%s", indentcmdstr);
    fflush (NULL);
    /// indent run quite quickly enough, often in a few dozens of milliseconds
    int cmdcod = system (indentcmdstr);
    if (cmdcod)
      {
        DBGPRINTF_BM
          ("emit_module°plain_module indentcmdstr=%s failed cmdcod=%d",
           indentcmdstr, cmdcod);
        FAILHERE (makestring_BM (indentcmdstr));
      }
    flock (fd, LOCK_UN);
    close (fd);
    free (indentcmdstr), indentcmdstr = NULL;
  }
  const char *modulname = findobjectname_BM (_.modulob);
  if (modulname)
    {
      char *linkstr = NULL;
      asprintf (&linkstr, "%s/_%s_.c", srcdirstr, modulname);
      if (!linkstr)
        FATAL_BM ("failed to build symlink in %s for %s", srcdirstr,
                  modulname);
      DBGPRINTF_BM ("emit_module°plain_module linkstr=%s", linkstr);
      symlink (basename (srcpathstr), linkstr);
      free (linkstr), linkstr = NULL;
    }
  /// 
  if (gui_is_running_BM)
    {
      _.srcdirstrv = (value_tyBM) makestring_BM (srcdirstr);
      DBGPRINTF_BM
        ("emit_module°plain_module srcdirstr %s modulob %s modgenob %s deferred_compilation_of_module %s",
         srcdirstr, objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),
         objectdbg2_BM (kk_deferred_compilation_of_module));
      gtk_defer_apply3_BM (kk_deferred_compilation_of_module, _.modulob,
                           _.modgenob, _.srcdirstrv, CURFRAME_BM);
    }
  if (srcdirstr)
    free (srcdirstr), srcdirstr = NULL;
  if (pardirstr)
    free (pardirstr), pardirstr = NULL;
  if (realpardirstr)
    free (realpardirstr), realpardirstr = NULL;
  if (realsrcdirstr)
    free (realsrcdirstr), realsrcdirstr = NULL;
  if (srcpathstr)
    free (srcpathstr), srcpathstr = NULL;
  if (prevsrcpathstr)
    free (prevsrcpathstr), prevsrcpathstr = NULL;
  LOCALRETURN_BM (_.modgenob);
failure:
  if (srcdirstr)
    free (srcdirstr), srcdirstr = NULL;
  if (pardirstr)
    free (pardirstr), pardirstr = NULL;
  if (realpardirstr)
    free (realpardirstr), realpardirstr = NULL;
  if (realsrcdirstr)
    free (realsrcdirstr), realsrcdirstr = NULL;
  if (srcpathstr)
    free (srcpathstr), srcpathstr = NULL;
  if (prevsrcpathstr)
    free (prevsrcpathstr), prevsrcpathstr = NULL;
  DBGPRINTF_BM ("emit_module°plain_module failin %d modulob %s cause %s",
                failin, objectdbg_BM (_.modulob),
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode3_BM (BMP_emit_module, _.modulob, _.modgenob,
                               _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end emit_module°plain_module _1gME6zn82Kf_8hzWibLFRfz */





////////////////
// for the method to prepare_module in basiclo_temporary_module &
// basiclo_dumpable_module -- prepare_module°basiclo*module

extern objrout_sigBM ROUTINEOBJNAME_BM (_8zNBXSMY2Ts_1VI5dmY4umA);      // prepare_module°basiclo*module 
value_tyBM
ROUTINEOBJNAME_BM (_8zNBXSMY2Ts_1VI5dmY4umA)    // prepare_module°basiclo*module
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving module
 const value_tyBM arg2,         // module generator
 const value_tyBM arg3 __attribute__ ((unused)),
 const value_tyBM arg4 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * modulob;
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * funhsetob;
                 objectval_tyBM * consthsetob;
                 objectval_tyBM * prepvecob;
                 objectval_tyBM * curfunob;
                 value_tyBM curcomp;    //
                 seqobval_tyBM * curseq;        //
                 value_tyBM partres;    //
                 setval_tyBM * setfun;
                 setval_tyBM * setconst; value_tyBM errorv;
                 value_tyBM causev;
    );
  objectval_tyBM *k_hset_object = BMK_8c9otZ4pwR6_55k81qyyYV2;
  objectval_tyBM *k_functions_set = BMK_9stpgEfdDDE_7LUgqylTeFI;
  objectval_tyBM *k_basiclo_function = BMK_2Ir1i8qnrA4_3jSkierlc5z;
  objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  objectval_tyBM *k_prepare_routine = BMK_6qi1DW0Ygkl_4Aqdxq4n5IV;
  objectval_tyBM *k_prepared_routines = BMK_9qn0Hp8HaF5_7yeAJiNYtp5;
  if (!isobject_BM (arg1))
    LOCALRETURN_BM (NULL);
  _.modulob = (objectval_tyBM *) arg1;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM) (Cause); goto failure; } while(0)
  DBGPRINTF_BM ("@@prepare_module°basiclo*module _8zNBXSMY2Ts_1VI5dmY4umA"
                "  modulob=%s\n" "... is a %s\n", objectdbg_BM (_.modulob),
                objectdbg1_BM (objclass_BM (_.modulob)));
  if (!isobject_BM (arg2))
    LOCALRETURN_BM (NULL);
  _.modgenob = (objectval_tyBM *) arg2;
  DBGPRINTF_BM ("@@prepare_module°basiclo*module modgenob=%s\n"
                ".... is a %s\n", objectdbg_BM (_.modgenob),
                objectdbg1_BM (objclass_BM (_.modgenob)));
  objectval_tyBM *k_simple_module_generation = BMK_2HlKptD03wA_7JJCG7lN5nS;
  if (!objectisinstance_BM (_.modgenob, k_simple_module_generation))
    FAILHERE (makenode1_BM (k_simple_module_generation, _.modgenob));
  _.funhsetob = makeobj_BM ();
  objputclass_BM (_.funhsetob, k_hset_object);
  objputhashsetpayl_BM (_.funhsetob, objnbcomps_BM (_.modulob) + 1);
  _.consthsetob = makeobj_BM ();
  objputclass_BM (_.consthsetob, k_hset_object);
  objputhashsetpayl_BM (_.consthsetob, 5 * objnbcomps_BM (_.modulob) + 10);
  objputattr_BM (_.modgenob, k_functions_set, _.funhsetob);
  objputattr_BM (_.modgenob, k_constants, _.consthsetob);
  DBGPRINTF_BM
    ("@@prepare_module°basiclo*module modgenob=%s funhsetob=%s consthsetob=%s",
     objectdbg_BM (_.modgenob), objectdbg1_BM (_.funhsetob),
     objectdbg2_BM (_.consthsetob));
  for (unsigned ix = 0; ix < objnbcomps_BM (_.modulob); ix++)
    {
      DBGPRINTF_BM ("@@prepare_module°basiclo*module ix=%u", ix);
      _.curcomp = objgetcomp_BM (_.modulob, ix);
      if (isobject_BM (_.curcomp))
        {
          DBGPRINTF_BM ("@@prepare_module°basiclo*module object at ix=%u",
                        ix);
          if (objectisinstance_BM (_.curcomp, k_basiclo_function))
            {
              objhashsetaddpayl_BM (_.funhsetob, _.curcomp);
              DBGPRINTF_BM
                ("@@prepare_module°basiclo*module adding curcomp %s",
                 objectdbg_BM ((objectval_tyBM *) _.curcomp));
            }
          else
            {
              DBGPRINTF_BM
                ("@@prepare_module°basiclo*module bad object curcomp %s",
                 objectdbg_BM ((objectval_tyBM *) _.curcomp));
              FAILHERE (makenode2_BM
                        (k_basiclo_function, _.curcomp, taggedint_BM (ix)));
            }
        }
      else if (issequence_BM (_.curcomp))
        {
          _.curseq = (seqobval_tyBM *) _.curcomp;
          unsigned sqlen = sequencesize_BM (_.curseq);
          DBGPRINTF_BM ("@@prepare_module°basiclo*module seqlen %u at ix=%u",
                        sqlen, ix);
          for (unsigned j = 0; j < sqlen; j++)
            {
              _.curcomp = sequencenthcomp_BM (_.curseq, j);
              if (objectisinstance_BM (_.curcomp, k_basiclo_function))
                {
                  DBGPRINTF_BM
                    ("@@prepare_module°basiclo*module adding curcomp %s",
                     objectdbg_BM ((objectval_tyBM *) _.curcomp));
                  objhashsetaddpayl_BM (_.funhsetob, _.curcomp);
                }
              else
                {
                  DBGPRINTF_BM
                    ("@@prepare_module°basiclo*module bad seq curcomp %s",
                     objectdbg_BM ((objectval_tyBM *) _.curcomp));
                  FAILHERE (makenode3_BM
                            (k_basiclo_function, _.curcomp, taggedint_BM (ix),
                             taggedint_BM (j)));
                }
            }
          DBGPRINTF_BM
            ("@@prepare_module°basiclo*module done seqlen %u at ix=%u",
             sqlen, ix);
        }
      else if (isclosure_BM (_.curcomp))
        {
          DBGPRINTF_BM ("@@prepare_module°basiclo*module closure at ix=%u",
                        ix);
          _.partres =
            apply2_BM ((closure_tyBM *) _.curcomp,
                       CURFRAME_BM, _.modulob, _.modgenob);
          if (isobject_BM (_.partres)
              && objectisinstance_BM (_.partres, k_basiclo_function))
            {
              DBGPRINTF_BM
                ("@@prepare_module°basiclo*module adding partres %s",
                 objectdbg_BM ((objectval_tyBM *) _.partres));
              objhashsetaddpayl_BM (_.funhsetob, _.partres);
            }
          else if (issequence_BM (_.partres))
            {
              _.curseq = (seqobval_tyBM *) _.partres;
              unsigned sqlen = sequencesize_BM (_.curseq);
              DBGPRINTF_BM
                ("@@prepare_module°basiclo*module ix=%u partres sqlen=%u",
                 ix, sqlen);
              for (unsigned j = 0; j < sqlen; j++)
                {
                  _.curcomp = sequencenthcomp_BM (_.curseq, j);
                  if (objectisinstance_BM (_.curcomp, k_basiclo_function))
                    {
                      DBGPRINTF_BM
                        ("@@prepare_module°basiclo*module adding curcomp %s",
                         objectdbg_BM ((objectval_tyBM *) _.curcomp));
                      objhashsetaddpayl_BM (_.funhsetob, _.curcomp);
                    }
                  else
                    {
                      DBGPRINTF_BM
                        ("@@prepare_module°basiclo*module ix=%u j=%u bad curcomp %s",
                         ix, j, objectdbg_BM ((objectval_tyBM *) _.curcomp));
                      FAILHERE (makenode3_BM
                                (k_basiclo_function, _.curcomp, _.partres,
                                 taggedint_BM (ix)));
                    }
                }
            }
          else
            {
              DBGPRINTF_BM
                ("@@prepare_module°basiclo*module ix=%u bad partres", ix);
              FAILHERE (makenode3_BM
                        (k_basiclo_function, _.curcomp, _.partres,
                         taggedint_BM (ix)));
            }
        }
      else
        {
          DBGPRINTF_BM ("@@prepare_module°basiclo*module ix=%u bad curcomp",
                        ix);
          FAILHERE (makenode2_BM
                    (k_basiclo_function, _.curcomp, taggedint_BM (ix)));
        }
    }
  _.setfun = (setval_tyBM *) objhashsettosetpayl_BM (_.funhsetob);
  DBGPRINTF_BM ("@@prepare_module°basiclo*module funhsetob %s setfun %s modgenob %s", objectdbg_BM (_.funhsetob),      //
                debug_outstr_value_BM (_.setfun, CURFRAME_BM, 0),
                objectdbg1_BM (_.modgenob));
  objputattr_BM (_.modgenob, k_functions_set, _.setfun);
  int nbfunc = setcardinal_BM (_.setfun);
  _.prepvecob = makeobj_BM ();
  objputclass_BM (_.prepvecob, BMP_vector_object);
  objputdatavectpayl_BM (_.prepvecob, nbfunc + 1);
  objputattr_BM (_.prepvecob, BMP_in, _.modgenob);
  objputattr_BM (_.modgenob, k_prepared_routines, _.prepvecob);
  DBGPRINTF_BM
    ("@@prepare_module°basiclo*module modulob %s modgenob %s prepvecob %s",
     objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.prepvecob));
  for (int fix = 0; fix < nbfunc; fix++)
    {
      _.curfunob = setelemnth_BM (_.setfun, fix);
      DBGPRINTF_BM
        ("@@prepare_module°basiclo*module modulob %s modgenob %s fix#%d curfunob %s",
         objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob), fix,
         objectdbg2_BM (_.curfunob));
      _.partres =
        send2_BM (_.curfunob, k_prepare_routine, CURFRAME_BM, _.modgenob,
                  _.setfun);
      DBGPRINTF_BM
        ("@@prepare_module°basiclo*module modulob %s curfunob %s fix#%d prepare_routine gave %s",
         objectdbg_BM (_.modulob), objectdbg1_BM (_.curfunob), fix,
         debug_outstr_value_BM (_.partres, CURFRAME_BM, 0));
      if (isobject_BM (_.partres))
        {
          objdatavectappendpayl_BM (_.prepvecob, _.partres);
        }
      else
        {
          FAILHERE (makenode3_BM
                    (k_prepare_routine, _.curfunob, taggedint_BM (fix),
                     _.partres));
        }
    }
  _.partres = NULL;
  _.curseq = (value_tyBM) objdatavecttotuplepayl_BM (_.prepvecob);
  objputattr_BM (_.modgenob, k_prepared_routines, _.curseq);
  DBGPRINTF_BM ("@@prepare_module°basiclo*module modulob %s modgenob %s prepvecob %s prepared routines %s consthsetob %s",     //
                objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),   //
                objectdbg2_BM (_.prepvecob),
                debug_outstr_value_BM (_.curseq, CURFRAME_BM, 0),
                objectdbg3_BM (_.consthsetob));
  _.setconst = (value_tyBM) objhashsettosetpayl_BM (_.consthsetob);
  DBGPRINTF_BM ("@@prepare_module°basiclo*module modulob %s modgenob %s setconst %s",  //
                objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),   //
                debug_outstr_value_BM (_.setconst, CURFRAME_BM, 0));
  objputattr_BM (_.modgenob, k_constants, _.setconst);
  DBGPRINTF_BM
    ("@@prepare_module°basiclo*module done complete_module modulob=%s modgenob=%s",
     objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob));
  LOCALRETURN_BM (_.modgenob);
failure:
  DBGPRINTF_BM ("prepare_module°basiclo*module  failin %d cause %s", failin,
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode3_BM (BMP_emit_module, _.modulob, _.modgenob,
                               _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end  prepare_module°basiclo*module _8zNBXSMY2Ts_1VI5dmY4umA */




// miniscan_block°basiclo_block _2PbDEXpkK5W_7MSfDy2pWkH

extern objrout_sigBM ROUTINEOBJNAME_BM (_2PbDEXpkK5W_7MSfDy2pWkH);

value_tyBM
ROUTINEOBJNAME_BM (_2PbDEXpkK5W_7MSfDy2pWkH)    // miniscan_block°basiclo_block 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // blockob
 const value_tyBM arg2,         // routprepob
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // fromob
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_2PbDEXpkK5W_7MSfDy2pWkH,
                 objectval_tyBM * blockob;
                 objectval_tyBM * routprepob; objectval_tyBM * fromob;
                 objectval_tyBM * blockshsetob; objectval_tyBM * compob;
                 value_tyBM subresv; value_tyBM resultv;
                 value_tyBM causev;
                 value_tyBM errorv;
    );
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  const objectval_tyBM *k_miniscan_block = BMK_2gthNYOWogO_4sVTU1JbmUH;
  const objectval_tyBM *k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  const objectval_tyBM *k_blocks = BMK_2lCuMosXupr_5GAoqVgJ8PZ;
  const objectval_tyBM *k_duplicate = BMK_2YrbiKQ6lxP_3KNUOnU6TF5;
  const objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  _.blockob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  int depth = getint_BM (arg3);
  _.fromob = objectcast_BM (arg4);
  WEAKASSERT_BM (_.blockob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (arg3));
  WEAKASSERT_BM (_.fromob);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM) (Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("miniscan_block°basiclo_block start blockob=%s of %s routprepob=%s depth=%d fromob=%s",
     objectdbg_BM (_.blockob), objectdbg1_BM (objclass_BM (_.blockob)),
     objectdbg2_BM (_.routprepob), depth, objectdbg3_BM (_.fromob));
  _.blockshsetob = objgetattr_BM (_.routprepob, k_blocks);
  DBGPRINTF_BM
    ("miniscan_block°basiclo_block blockob %s blockshsetob %s",
     objectdbg_BM (_.blockob), objectdbg1_BM (_.blockshsetob));
  WEAKASSERT_BM (objhashashsetpayl_BM (_.blockshsetob));
  bool duplicateblock = false;
  {
    objlock_BM (_.blockshsetob);
    duplicateblock = objhashsetcontainspayl_BM (_.blockshsetob, _.blockob);
    objhashsetaddpayl_BM (_.blockshsetob, _.blockob);
    objunlock_BM (_.blockshsetob);
  }
  if (duplicateblock)
    FAILHERE (k_duplicate);
  int nbcomp = objnbcomps_BM (_.blockob);
  for (int ix = 0; ix < nbcomp; ix++)
    {
      _.compob = objectcast_BM (objgetcomp_BM (_.blockob, ix));
      if (!_.compob)
        FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (ix), _.compob));
      objlock_BM (_.compob);
      if (objectisinstance_BM (_.compob, k_basiclo_block))
        {
          DBGPRINTF_BM
            ("miniscan_block°basiclo_block blockob %s ix#%d compob %s is block of %s",
             objectdbg_BM (_.blockob), ix, objectdbg1_BM (_.compob),
             objectdbg2_BM (objclass_BM (_.compob)));
          _.subresv =
            send3_BM (_.compob, k_miniscan_block,
                      CURFRAME_BM, _.routprepob,
                      taggedint_BM (depth + 1), _.blockob);
          DBGPRINTF_BM
            ("miniscan_block°basiclo_block blockob %s ix#%d compob %s miniscan_block gave %s",
             objectdbg_BM (_.blockob), ix, objectdbg1_BM (_.compob),
             debug_outstr_value_BM (_.subresv, CURFRAME_BM, 0));
          if (!_.subresv)
            FAILHERE (makenode3_BM
                      (k_miniscan_block, _.compob, taggedint_BM (ix),
                       _.blockob));

        }
      else if (objectisinstance_BM (_.compob, k_basiclo_statement))
        {
          DBGPRINTF_BM
            ("miniscan_block°basiclo_block blockob %s ix#%d compob %s is statement of %s",
             objectdbg_BM (_.blockob), ix, objectdbg1_BM (_.compob),
             objectdbg2_BM (objclass_BM (_.compob)));
          _.subresv =
            send3_BM (_.compob, k_miniscan_stmt,
                      CURFRAME_BM, _.routprepob,
                      taggedint_BM (depth + 1), _.blockob);
          DBGPRINTF_BM
            ("miniscan_block°basiclo_block blockob %s ix#%d compob %s miniscan_stmt gave %s",
             objectdbg_BM (_.blockob), ix, objectdbg1_BM (_.compob),
             debug_outstr_value_BM (_.subresv, CURFRAME_BM, 0));
          if (!_.subresv)
            FAILHERE (makenode3_BM
                      (k_miniscan_stmt, _.compob, taggedint_BM (ix),
                       _.blockob));
        }
      else
        {
          DBGPRINTF_BM
            ("miniscan_block°basiclo_block blockob %s ix#%d compob %s bad of %s",
             objectdbg_BM (_.blockob), ix, objectdbg1_BM (_.compob),
             objectdbg2_BM (objclass_BM (_.compob)));
          FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (ix), _.compob));
        }
      objunlock_BM (_.compob);
    }
  DBGPRINTF_BM
    ("miniscan_block°basiclo_block end blockob=%s routprepob=%s depth=%d fromob=%s",
     objectdbg_BM (_.blockob), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromob));
  LOCALRETURN_BM (_.blockob);
failure:
  DBGPRINTF_BM ("miniscan_block°basiclo_block  failin %d blockob %s cause %s", failin, objectdbg_BM (_.blockob),       //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode5_BM (k_miniscan_block, _.blockob, _.routprepob,
                  taggedint_BM (depth), _.fromob, _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end miniscan_block°basiclo_block _2PbDEXpkK5W_7MSfDy2pWkH */






// for the method to generate_module in basiclo_temporary_module &
// basiclo_dumpable_module/ generate_module°basiclo*module

extern objrout_sigBM ROUTINEOBJNAME_BM (_50d65bJypCN_6IJeVtssx9I);      // generate_module°basiclo*module

value_tyBM
ROUTINEOBJNAME_BM (_50d65bJypCN_6IJeVtssx9I)    // generate_module°basiclo*module
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving module
 const value_tyBM arg2,         // module generator
 const value_tyBM arg3,         // preparation
 const value_tyBM arg4 __attribute__ ((unused)),        //
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * modulob;
                 objectval_tyBM * curfunob; objectval_tyBM * curoutprepob;
                 objectval_tyBM * curconstob; objectval_tyBM * modgenob;
                 value_tyBM prepval; value_tyBM preproutval;
                 objectval_tyBM * vectprepob; value_tyBM preptupv;
                 value_tyBM prepmod;
                 value_tyBM emitv; value_tyBM constsetv; value_tyBM routsetv;
                 value_tyBM causev;
                 value_tyBM errorv;
    );
  _.modulob = arg1;
  //objectval_tyBM *k_prepare_routine = BMK_6qi1DW0Ygkl_4Aqdxq4n5IV;
  objectval_tyBM *k_prepared_routines = BMK_9qn0Hp8HaF5_7yeAJiNYtp5;
  //objectval_tyBM *k_vector_object = BMK_0Ie11LN3K5q_0mcL2jRBwgk;
  objectval_tyBM *k_emit_declaration = BMK_3NGaoN3yhbn_8yUwbtZfvp9;
  objectval_tyBM *k_emit_definition = BMK_1g8s9B96Irf_6Ix2Cyy8Hq0;
  objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  objectval_tyBM *k_functions_set = BMK_9stpgEfdDDE_7LUgqylTeFI;
  objectval_tyBM *k_generate_module = BMK_9mq0jsuz4XQ_4doHfd987Q6;
  const objectval_tyBM *k_modgenob = BMK_0Bl5ro9usp6_1Hll14QwC8f;
  ASSERT_BM (isobject_BM (_.modulob));
  char modulidbuf[32];
  memset (modulidbuf, 0, sizeof (modulidbuf));
  idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
  _.modgenob = objectcast_BM (arg2);
  _.prepval = arg3;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("@@generate_module°basiclo*module start modulob=%s /%s\n"
     "... is a %s, modgenob %s, prepval %s\n\n",
     objectdbg_BM (_.modulob), modulidbuf,
     objectdbg1_BM (objclass_BM (_.modulob)), objectdbg2_BM (_.modgenob),
     debug_outstr_value_BM (_.prepval, CURFRAME_BM, 0));
  if (!_.modgenob)
    {
      DBGPRINTF_BM ("@@generate_module°basiclo*module bad modgenob");
      FAILHERE (k_modgenob);
    };
  _.constsetv = objgetattr_BM (_.modgenob, k_constants);
  DBGPRINTF_BM ("@@generate_module°basiclo*module modgenob=%s is a %s prepval=%s constsetv=%s\n",      //
                objectdbg_BM (_.modgenob), objectdbg1_BM (objclass_BM (_.modgenob)),    //
                debug_outstr_value_BM ((value_tyBM) _.prepval, CURFRAME_BM, 1), //
                debug_outstr_value_BM ((value_tyBM) _.constsetv, CURFRAME_BM,
                                       1));
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.modgenob));
  WEAKASSERT_BM (!_.constsetv || isset_BM (_.constsetv));
  objstrbufferprintfpayl_BM (_.modgenob, "\n\n" "#include \"bismon.h\"\n\n");
  objstrbufferprintfpayl_BM (_.modgenob,
                             "#ifdef BISMON_MODID\n"
                             "DECLARE_MODULE_BM(%s);\n"
                             "extern moduleinit_sigBM " MODULEINITPREFIX_BM
                             "%s" MODULEINITSUFFIX_BM ";\n"
                             "#endif /*BISMON_MODID*/\n\n", modulidbuf,
                             modulidbuf);
  DBGPRINTF_BM
    ("@@generate_module°basiclo*module incomplete modgenob=%s prepmod=%s",
     objectdbg_BM (_.modgenob), debug_outstr_value_BM (_.prepmod, CURFRAME_BM,
                                                       0));
  _.routsetv = objgetattr_BM (_.modgenob, k_functions_set);
  _.preptupv = objgetattr_BM (_.modgenob, k_prepared_routines);
  unsigned nbrout = setcardinal_BM (_.routsetv);
  WEAKASSERT_BM (isset_BM (_.routsetv));
  WEAKASSERT_BM (istuple_BM (_.preptupv));
  WEAKASSERT_BM (nbrout == tuplesize_BM (_.preptupv));
  //////
  // we should now declare the routines
  objstrbufferprintfpayl_BM (_.modgenob, "\n\n// declare %u routines\n\n",
                             nbrout);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "extern const char *const " ROUTIDARRPREFIX_BM
                             "%s" ROUTINESUFFIX_BM "[%d+1];\n", modulidbuf,
                             nbrout);
  _.preproutval = NULL;
  // we should now emit each routine's declaration...
  for (unsigned routix = 0; routix < nbrout; routix++)
    {
      _.curfunob = setelemnth_BM (_.routsetv, routix);
      _.curoutprepob = tuplecompnth_BM (_.preptupv, routix);
      _.emitv = NULL;
      DBGPRINTF_BM
        ("@@generate_module°basiclo*module declaring routix#%d before emit_declaration"
         "\n ... curfunob %s curoutprepob %s modgenob %s",
         routix, objectdbg_BM (_.curfunob), objectdbg1_BM (_.curoutprepob),
         objectdbg2_BM (_.modgenob));
      WEAKASSERT_BM (isobject_BM (_.curfunob));
      WEAKASSERT_BM (isobject_BM (_.curoutprepob));
      _.emitv = send2_BM (_.curoutprepob, k_emit_declaration,
                          CURFRAME_BM, _.modgenob, taggedint_BM (routix));
      DBGPRINTF_BM
        ("@@generate_module°basiclo*module declared routix#%d curoutprepob %s curfunob %s emitv %s",
         routix, objectdbg_BM (_.curoutprepob), objectdbg1_BM (_.curfunob),
         debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
      if (!_.emitv)
        {
          DBGPRINTF_BM
            ("@@generate_module°basiclo*module emit_declaration of %s for %s failed",
             objectdbg_BM (_.curoutprepob), objectdbg1_BM (_.curfunob));
          FAILHERE (makenode3_BM
                    (k_emit_declaration, _.curoutprepob, _.curfunob,
                     taggedint_BM (routix)));
        }
    }
  //// we should now emit the declarations of constants and of their ids
  unsigned nbconst = setcardinal_BM (_.constsetv);
  objstrbufferprintfpayl_BM (_.modgenob, "\n\n// declare %u constants\n",
                             nbconst);
  if (nbconst > 0)
    {
      objstrbufferprintfpayl_BM (_.modgenob, "objectval_tyBM* "
                                 CONSTOBARRPREFIX_BM
                                 "%s" ROUTINESUFFIX_BM
                                 "[%d+1];\n", modulidbuf, nbconst);
      objstrbufferprintfpayl_BM (_.modgenob, "const char* const "
                                 CONSTIDARRPREFIX_BM
                                 "%s" ROUTINESUFFIX_BM
                                 "[%d+1];\n", modulidbuf, nbconst);
    }
  //////
  // we should now define the routines
  objstrbufferprintfpayl_BM (_.modgenob, "\n\n// define %u routines\n",
                             nbrout);
  _.preproutval = NULL;
  // we should now emit each routine's definition...
  for (unsigned routix = 0; routix < nbrout; routix++)
    {
      _.curfunob = setelemnth_BM (_.routsetv, routix);
      _.curoutprepob = tuplecompnth_BM (_.preptupv, routix);

      _.emitv = NULL;
      DBGPRINTF_BM
        ("@@generate_module°basiclo*module defining routix#%d curoutprepob %s curfunob %s",
         routix, objectdbg_BM (_.curoutprepob), objectdbg1_BM (_.curfunob));
      WEAKASSERT_BM (isobject_BM (_.curoutprepob));
      _.emitv = send2_BM (_.curoutprepob, k_emit_definition,
                          CURFRAME_BM, _.modgenob, taggedint_BM (routix));
      DBGPRINTF_BM
        ("@@generate_module°basiclo*module defined routix#%d curoutprepob %s curfunob %s emitv %s",
         routix, objectdbg_BM (_.curoutprepob), objectdbg1_BM (_.curfunob),
         debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
      if (!_.emitv)
        {
          DBGPRINTF_BM
            ("@@generate_module°basiclo*module emit_declaration of %s for %s failed routix#%d",
             objectdbg_BM (_.curoutprepob), objectdbg1_BM (_.curfunob),
             routix);
          FAILHERE (makenode3_BM
                    (k_emit_definition, _.curoutprepob, _.curfunob,
                     taggedint_BM (routix)));
        }
    }
  // ending comment of routines
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n\n// end of %u generated routines\n\n",
                             nbrout);
  // constant ids
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n// the constant ids for %d constants:\n",
                             nbconst);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "const char* const " CONSTIDARRPREFIX_BM "%s"
                             ROUTINESUFFIX_BM "[%d+1] = {", modulidbuf,
                             nbconst);
  for (int kix = 0; kix < (int) nbconst; kix++)
    {
      if (kix % 8 == 0)
        objstrbufferprintfpayl_BM (_.modgenob, "\n /*%d:*/", kix);
      _.curconstob = setelemnth_BM (_.constsetv, kix);
      const char *curconstname = findobjectname_BM (_.curconstob);
      char constidbuf[32];
      memset (constidbuf, 0, sizeof (constidbuf));
      idtocbuf32_BM (objid_BM (_.curconstob), constidbuf);
      if (curconstname)
        objstrbufferprintfpayl_BM (_.modgenob, "\n \"%s\",//%s",
                                   constidbuf, curconstname);
      else
        objstrbufferprintfpayl_BM (_.modgenob, "\n \"%s\",", constidbuf);
    }
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n NULL}; // end %d constant ids\n\n", nbconst);
  // routine ids
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n\n// the routine ids for %d routines:\n",
                             nbrout);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "const char* const " ROUTIDARRPREFIX_BM "%s"
                             ROUTINESUFFIX_BM "[%d+1] = {\n", modulidbuf,
                             nbrout);
  for (unsigned routix = 0; routix < nbrout; routix++)
    {
      _.curfunob = setelemnth_BM (_.routsetv, routix);
      if (routix % 8 == 0)
        objstrbufferprintfpayl_BM (_.modgenob, "  /*%d:*/\n", routix);
      const char *curfunname = findobjectname_BM (_.curfunob);
      char funidbuf[32];
      memset (funidbuf, 0, sizeof (funidbuf));
      idtocbuf32_BM (objid_BM (_.curfunob), funidbuf);
      if (curfunname)
        objstrbufferprintfpayl_BM (_.modgenob, "  \"%s\",//%s\n",
                                   funidbuf, curfunname);
      else
        objstrbufferprintfpayl_BM (_.modgenob, "  \"%s\",\n", funidbuf);
    }
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n NULL}; // end %d routine ids\n\n", nbrout);

  /// emit the module initialization
  objstrbufferprintfpayl_BM (_.modgenob, "\n\n// basiclo*module initialization\n"       //
                             "#ifdef BISMON_MODID\n"
                             "value_tyBM " MODULEINITPREFIX_BM "%s"
                             MODULEINITSUFFIX_BM "\n"
                             "  (struct stackframe_stBM *stkf, //\n"
                             "   const value_tyBM arg1, //\n"
                             "   const value_tyBM arg2, //\n"
                             "   const value_tyBM arg3, //\n"
                             "   void* dlh) {\n", modulidbuf);
  objstrbufferprintfpayl_BM (_.modgenob, "  return simple_module_initialize_BM(arg1, arg2, arg3, //\n"  //
                             "        \"%s\",//\n", modulidbuf);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "       " CONSTOBARRPREFIX_BM "%s"
                             ROUTINESUFFIX_BM ", //\n", modulidbuf);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "       " CONSTIDARRPREFIX_BM "%s"
                             ROUTINESUFFIX_BM ", //\n", modulidbuf);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "       " ROUTIDARRPREFIX_BM "%s"
                             ROUTINESUFFIX_BM ", //\n", modulidbuf);
  objstrbufferprintfpayl_BM (_.modgenob, "       dlh, stkf);\n");
  objstrbufferprintfpayl_BM (_.modgenob,
                             "} // end " MODULEINITPREFIX_BM "%s"
                             MODULEINITSUFFIX_BM "\n"
                             "#endif /*BISMON_MODID*/\n\n", modulidbuf);
  DBGPRINTF_BM
    ("@@generate_module°basiclo*module end modulob %s modgenob %s",
     objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob));
  LOCALRETURN_BM (_.modgenob);
failure:
#undef FAILHERE
  DBGPRINTF_BM
    ("@@generate_module°basiclo*module failure failin %d  modulob %s modgenob %s cause %s",
     failin, objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),
     debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode4_BM (k_generate_module, _.modulob, _.modgenob, _.prepval,
                  _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);

}                               /* end generate_module°basiclo*module  _50d65bJypCN_6IJeVtssx9I */



// defer-compilation-of-module  _9EqBenFWb40_86MuuXslynk
extern objrout_sigBM ROUTINEOBJNAME_BM (_9EqBenFWb40_86MuuXslynk);
value_tyBM
ROUTINEOBJNAME_BM (_9EqBenFWb40_86MuuXslynk)    // defer-compilation-of-module 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // modulob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // srcdirstrv
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  objectval_tyBM *kk_after_compilation_of_module =
    BMK_9le67LL7S9y_5VGpniEUNDA;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_9EqBenFWb40_86MuuXslynk,
                 value_tyBM resultv;
                 objectval_tyBM * modulob; objectval_tyBM * modgenob;
                 value_tyBM srcdirstrv; value_tyBM pardirstrv;
                 value_tyBM compilnodv; value_tyBM aftercompilclosv;
                 value_tyBM argstrarr[8];
    );
  _.modulob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.srcdirstrv = arg3;
  DBGPRINTF_BM
    ("defer-compilation-of-module start modulob %s modgenob %s srcdirstrv %s",
     objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),
     debug_outstr_value_BM (_.srcdirstrv, CURFRAME_BM, 0));
  WEAKASSERT_BM (_.modulob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (isstring_BM (_.srcdirstrv));
  WEAKASSERT_BM (pthread_self () == mainthreadid_BM);
  log_begin_message_BM ();
  log_puts_message_BM ("should compile module ");
  log_object_message_BM (_.modulob);
  log_puts_message_BM (" for generation ");
  log_object_message_BM (_.modgenob);
  log_printf_message_BM (" in source directory: %s.",
                         bytstring_BM (_.srcdirstrv));
  log_end_message_BM ();
  char cwdpath[128];
  memset (cwdpath, 0, sizeof (cwdpath));
  getcwd (cwdpath, sizeof (cwdpath));
  char *realsrcdir = realpath (bytstring_BM (_.srcdirstrv), NULL);
  if (!realsrcdir)
    FATAL_BM
      ("failed to get realsrcdir from %s in defer-compilation-of-module modulob %s modgenob %s",
       bytstring_BM (_.srcdirstrv), objectdbg_BM (_.modulob),
       objectdbg1_BM (_.modgenob));
  char *realpardir = NULL;
  {
    char *lastslash = strrchr (realsrcdir, '/');
    if (lastslash)
      {
        *lastslash = (char) 0;
        realpardir = strdup (realsrcdir);
        *lastslash = '/';
      }
  }
  DBGPRINTF_BM
    ("defer-compilation-of-module realsrcdir %s realpardir %s bismondir %s cwdpath %s",
     realsrcdir, realpardir, bismon_directory, cwdpath);
  if (!realpardir)
    FATAL_BM
      ("failed to compute real parent directory in defer-compilation-of-module"
       " modulob %s modgenob %s for realsrcdir %s", objectdbg_BM (_.modulob),
       objectdbg1_BM (_.modgenob), realsrcdir);
  char modulidbuf[32];
  memset (modulidbuf, 0, sizeof (modulidbuf));
  idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
  char *compilargs[8] = { };
  char buildscriptbuf[128];
  memset (buildscriptbuf, 0, sizeof (buildscriptbuf));
  snprintf (buildscriptbuf, sizeof (buildscriptbuf),
            "%s/build-bismon-module.sh", bismon_directory);
  compilargs[0] = buildscriptbuf;
  compilargs[1] = modulidbuf;
  int nbargs = 2;
  DBGPRINTF_BM ("defer-compilation-of-module nbargs=%d", nbargs);
  for (int ix = 0; ix < nbargs; ix++)
    DBGPRINTF_BM ("..[%d]: %s", ix, compilargs[ix]);
  memset (_.argstrarr, 0, sizeof (_.argstrarr));
  for (int ix = 0; ix < nbargs; ix++)
    _.argstrarr[ix] = (value_tyBM) makestring_BM (compilargs[ix]);
  _.compilnodv = (value_tyBM) makenode_BM (BMP_node, nbargs, _.argstrarr);
  _.pardirstrv = (value_tyBM) makestring_BM (realsrcdir);
  _.aftercompilclosv = (value_tyBM)
    makeclosure3_BM (kk_after_compilation_of_module, _.modulob, _.modgenob,
                     _.pardirstrv);
  DBGPRINTF_BM
    ("defer-compilation-of-module pardirstrv=%s compilnodv=%s aftercompilclosv=%s before queue_process_BM",
     debug_outstr_value_BM (_.pardirstrv, CURFRAME_BM, 0),
     debug_outstr_value_BM (_.compilnodv, CURFRAME_BM, 0),
     debug_outstr_value_BM (_.aftercompilclosv, CURFRAME_BM, 0));
  queue_process_BM (_.pardirstrv, _.compilnodv, _.aftercompilclosv,
                    CURFRAME_BM);
  LOCALRETURN_BM (_.aftercompilclosv);
}                               /* end  defer-compilation-of-module _9EqBenFWb40_86MuuXslynk */




// after-compilation-of-module _9le67LL7S9y_5VGpniEUNDA, closure called by process ending

extern objrout_sigBM ROUTINEOBJNAME_BM (_9le67LL7S9y_5VGpniEUNDA);

value_tyBM
ROUTINEOBJNAME_BM (_9le67LL7S9y_5VGpniEUNDA)    // after-compilation-of-module, process ending
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // outstr
 const value_tyBM arg2,         // status
 const value_tyBM arg3_ __attribute__ ((unused)),       //
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  objectval_tyBM *kk_after_load_of_module = BMK_0UHZG9vDlR2_2Aqx86LMFuq;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_9le67LL7S9y_5VGpniEUNDA,
                 value_tyBM outstrv; value_tyBM resultv;
                 value_tyBM callingclosv; objectval_tyBM * modulob;
                 value_tyBM postclosv; objectval_tyBM * modgenob;
                 value_tyBM moddirstrv;
    );
  int status = -1;
  _.outstrv = arg1;
  status = getint_BM (arg2);
  LOCALGETFUNV_BM (_.callingclosv);
  _.modulob = objectcast_BM (closurenthson_BM (_.callingclosv, 0));
  _.modgenob = objectcast_BM (closurenthson_BM (_.callingclosv, 1));
  _.moddirstrv = closurenthson_BM (_.callingclosv, 2);
  DBGPRINTF_BM ("start after-compilation-of-module status %d outstr %s callingclos %s\n"        //
                ".. modulob=%s modgenob=%s moddirstr=%s\n", status,     //
                debug_outstr_value_BM (_.outstrv, CURFRAME_BM, 0),      //
                debug_outstr_value_BM (_.callingclosv, CURFRAME_BM, 0), //
                objectdbg_BM (_.modulob), objectdbg2_BM (_.modgenob),   //
                debug_outstr_value_BM (_.moddirstrv, CURFRAME_BM, 0));
  WEAKASSERT_BM (_.modulob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (isstring_BM (_.moddirstrv));
  char modulidbuf[32];
  memset (modulidbuf, 0, sizeof (modulidbuf));
  idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
  WEAKASSERT_BM (isclosure_BM (_.callingclosv)
                 && closurewidth_BM (_.callingclosv) >= 2);
  ASSERT_BM (isstring_BM (_.outstrv));
  ASSERT_BM (istaggedint_BM (arg2));
  if (pthread_self () == mainthreadid_BM && gui_is_running_BM)
    {
      log_begin_message_BM ();
      log_printf_message_BM ("compilation of module ");
      log_object_message_BM (_.modulob);
      log_printf_message_BM (" /%s with module generation ", modulidbuf);
      log_object_message_BM (_.modgenob);
      log_printf_message_BM (" ");
      if (status)
        {
          if (WIFEXITED (status))
            log_printf_message_BM ("failed, exited %d.\n",
                                   WEXITSTATUS (status));
          else if (WIFSIGNALED (status))
            log_printf_message_BM ("failed, terminated %s.\n",
                                   strsignal (WTERMSIG (status)));
          else
            log_printf_message_BM ("failed (status %d=%#x).\n", status,
                                   status);
        }
      else
        {
          log_printf_message_BM (" successful.\n");
        }
      unsigned lenout = lenstring_BM (_.outstrv);
      if (lenout > 0)
        log_printf_message_BM
          ("+++++ (%d bytes)\n%s\n----- compile log of %s\n", lenout,
           bytstring_BM (_.outstrv), objectdbg_BM (_.modulob));
    }
  char *prevpathstr = NULL;
  char *srcpathstr = NULL;
  if (status)
    {
      int err = 0;
      char *badpathstr = NULL;
      const char *moddirstr = bytstring_BM (_.moddirstrv);
      asprintf (&srcpathstr, "%s/" MODULEPREFIX_BM "%s.c", moddirstr,
                modulidbuf);
      prevpathstr = asprintf_prev_module_BM (moddirstr, _.modulob);
      asprintf (&badpathstr, "%s/" MODULEPREFIX_BM "%s.c-p%d-bad~", moddirstr,
                modulidbuf, (int) getpid ());
      DBGPRINTF_BM
        ("after-compilation-of-module modulob %s moddirstr %s srcpathstr %s badpathstr %s prevpathstr %s",
         objectdbg_BM (_.modulob), moddirstr, srcpathstr, badpathstr,
         prevpathstr);
      fflush (NULL);
      {                         // for debugging only
        char *cmdbuf = NULL;
        asprintf (&cmdbuf,
                  "echo after-compilation-of-module modulob %s id %s; ls -l %s %s %s %s; pwd",
                  objectdbg_BM (_.modulob),
                  modulidbuf, moddirstr, srcpathstr, badpathstr, prevpathstr);
        system (cmdbuf);
        free (cmdbuf), cmdbuf = NULL;
      }
      rename (srcpathstr, badpathstr);
      if (rename (prevpathstr, srcpathstr))
        err = errno;
      fprintf (stderr, "compilation of module %s failed (%d=%#x);\n"
               "... restored previous %s from %s with bad new source in %s\n",
               objectdbg_BM (_.modulob), status, status, srcpathstr,
               prevpathstr, badpathstr);
      if (err > 0)
        {
          char cwdbuf[80];
          memset (cwdbuf, 0, sizeof (cwdbuf));
          getcwd (cwdbuf, sizeof (cwdbuf));
          DBGPRINTF_BM
            ("after-compilation-of-module %s failed renaming %s -> %s failed with #%d: %s in %s",
             objectdbg_BM (_.modulob), prevpathstr, srcpathstr, err,
             strerror (err), cwdbuf);
          fprintf (stderr, "... renaming %s -> %s failed with %s\n",
                   prevpathstr, srcpathstr, strerror (err));
        }
      if (pthread_self () == mainthreadid_BM && gui_is_running_BM)
        {
          log_printf_message_BM
            ("restored previous %s from %s,\n.. bad new source in %s.\n",
             srcpathstr, prevpathstr, badpathstr);
          if (err > 0)
            log_printf_message_BM
              ("... renaming %s -> %s failed with %s\n",
               prevpathstr, srcpathstr, strerror (err));
        }
      free (badpathstr), badpathstr = NULL;
    }
  else
    fprintf (stderr, "successful compilation of module %s\n",
             objectdbg_BM (_.modulob));
  if (pthread_self () == mainthreadid_BM && gui_is_running_BM)
    {
      log_end_message_BM ();
    }
  DBGPRINTF_BM
    ("after-compilation-of-module modulob %s modgenob %s status %d",
     objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob), status);
  if (prevpathstr && srcpathstr && !access (prevpathstr, F_OK))
    {
      char *bak1pathstr = NULL;
      char *bak2pathstr = NULL;
      asprintf (&bak1pathstr, "%s~%%", srcpathstr);
      asprintf (&bak2pathstr, "%s~%%~", srcpathstr);
      (void) rename (bak1pathstr, bak2pathstr);
      DBGPRINTF_BM
        ("after-compilation-of-module modulob %s prevpathstr %s bak1pathstr %s bak2pathstr %s",
         objectdbg_BM (_.modulob), prevpathstr, bak1pathstr, bak2pathstr);
      if (rename (prevpathstr, bak1pathstr))
        FATAL_BM
          ("after-compilation-of-modgenob %s failed to rename %s -> %s",
           objectdbg_BM (_.modulob), prevpathstr, bak1pathstr);
    }
  if (prevpathstr)
    free (prevpathstr), prevpathstr = NULL;
  if (srcpathstr)
    free (srcpathstr), srcpathstr = NULL;
  if (status)
    LOCALRETURN_BM (NULL);
  _.postclosv =
    makeclosure2_BM (kk_after_load_of_module, _.modulob, _.modgenob);
  DBGPRINTF_BM ("after-compilation-of-module modulob %s postclosv=%s before defer_module_load", objectdbg_BM (_.modulob),       //
                debug_outstr_value_BM (_.postclosv, CURFRAME_BM, 0));
  defer_module_load_BM (_.modulob, _.postclosv, _.modulob, _.modgenob, NULL,
                        CURFRAME_BM);
  DBGPRINTF_BM ("after-compilation-of-module modulob %s modgenob=%s end",
                objectdbg_BM (_.modulob), objectdbg_BM (_.modgenob));
  LOCALRETURN_BM (_.modgenob);
}                               /* end after-compilation-of-module _9le67LL7S9y_5VGpniEUNDA */


////////////////////////////////////////////////////////////////
// after-load-of-module _0UHZG9vDlR2_2Aqx86LMFuq
extern objrout_sigBM ROUTINEOBJNAME_BM (_0UHZG9vDlR2_2Aqx86LMFuq);

value_tyBM
ROUTINEOBJNAME_BM (_0UHZG9vDlR2_2Aqx86LMFuq)    // after-load-of-module
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // resmod
 const value_tyBM arg2_ __attribute__ ((unused)),       //
 const value_tyBM arg3_ __attribute__ ((unused)),       //
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_0UHZG9vDlR2_2Aqx86LMFuq,
                 value_tyBM resultv;    //
                 value_tyBM resmodv;    //
                 objectval_tyBM * modulob;      //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * taskletob;    //
                 value_tyBM callingclosv;       //
                 value_tyBM todoclosv;  //
    );
  objectval_tyBM *k_todo_after_module_load = BMK_5DXq2adUiam_4ySWA06AoyV;
  _.resmodv = arg1;
  LOCALGETFUNV_BM (_.callingclosv);
  _.modulob = objectcast_BM (closurenthson_BM (_.callingclosv, 0));
  _.modgenob = objectcast_BM (closurenthson_BM (_.callingclosv, 1));
  DBGPRINTF_BM ("after-load-of-module start resmodv=%s callingclosv=%s modulob=%s modgenob=%s ",        //
                debug_outstr_value_BM (_.resmodv, CURFRAME_BM, 0),      //
                debug_outstr_value_BM (_.callingclosv, CURFRAME_BM, 0), //
                objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.modulob));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (closurewidth_BM (_.callingclosv) >= 2);
  if (pthread_self () == mainthreadid_BM)
    {
      log_begin_message_BM ();
      log_puts_message_BM ("Loaded module ");
      log_object_message_BM (_.modulob);
      log_puts_message_BM (" with generation ");
      log_object_message_BM (_.modgenob);
      log_puts_message_BM (".");
      log_end_message_BM ();
    };
  fprintf (stderr, "loaded module %s with generation %s\n",
           objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob));
  {
    objlock_BM (_.modgenob);
    _.todoclosv = objgetattr_BM (_.modgenob, k_todo_after_module_load);
    objunlock_BM (_.modgenob);
  }
  DBGPRINTF_BM
    ("after-load-of-module modulob %s modgenob %s got todoclosv %s",
     objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),
     debug_outstr_value_BM (_.todoclosv, CURFRAME_BM, 0));
  if (_.todoclosv)
    {
      _.taskletob =
        objectcast_BM (apply3_BM
                       (_.todoclosv, CURFRAME_BM, _.modulob, _.modgenob,
                        _.resmodv));
      DBGPRINTF_BM
        ("after-load-of-module modulob %s +modgenob %s taskletob %s",
         objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),
         objectdbg2_BM (_.taskletob));
    }
  else
    {
      objlock_BM (_.modulob);
      _.todoclosv = objgetattr_BM (_.modulob, k_todo_after_module_load);
      objunlock_BM (_.modulob);
      _.taskletob =
        objectcast_BM (apply3_BM
                       (_.todoclosv, CURFRAME_BM, _.modulob, _.modgenob,
                        _.resmodv));
      DBGPRINTF_BM
        ("after-load-of-module +modulob %s modgenob %s taskletob %s",
         objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),
         objectdbg2_BM (_.taskletob));
    }
  if (_.taskletob)
    {
      agenda_add_very_high_priority_tasklet_BM (_.taskletob);
      LOCALRETURN_BM (_.taskletob);
    };
  DBGPRINTF_BM
    ("after-load-of-module modulob %s modgenob %s no taskletob resmodv %s",
     objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),
     debug_outstr_value_BM (_.resmodv, CURFRAME_BM, 0));
  LOCALRETURN_BM (_.resmodv);
}                               /* end after-load-of-module _0UHZG9vDlR2_2Aqx86LMFuq */




value_tyBM
simple_module_initialize_BM (const value_tyBM arg1,     //
                             const value_tyBM arg2,     //
                             const value_tyBM arg3,     //
                             const char *modulid,       //
                             objectval_tyBM ** constobjarr,     //
                             const char *const *constidarr,     //
                             const char *const *routidarr,      //
                             void *dlh, // dlopened handle
                             struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_simple_module_initialize = BMK_3XOzJccMA25_76EfdJqsCSL;
  LOCALFRAME_BM (stkf, /*descr: */ k_simple_module_initialize,
                 value_tyBM arg1v;
                 value_tyBM arg2v;
                 value_tyBM arg3v; value_tyBM constsetv; value_tyBM routupv;
                 objectval_tyBM * curob; objectval_tyBM * routob;
                 objectval_tyBM * modulob;
    );
  _.arg1v = arg1;
  _.arg2v = arg2;
  _.arg3v = arg3;
  NONPRINTF_BM
    ("simple_module_initialize start modulid %s arg1 %s arg2 %s arg3 %s",
     modulid, debug_outstr_value_BM (_.arg1v, CURFRAME_BM, 0),
     debug_outstr_value_BM (_.arg2v, CURFRAME_BM, 0),
     debug_outstr_value_BM (_.arg3v, CURFRAME_BM, 0));
  {
    rawid_tyBM modid = parse_rawid_BM (modulid, NULL);
    _.modulob = findobjofid_BM (modid);
    if (!_.modulob)
      FATAL_BM ("simple_module_initialize cannot find modulob of %s",
                modulid);
  }
  ASSERT_BM (constobjarr != NULL);
  ASSERT_BM (constidarr != NULL);
  ASSERT_BM (routidarr != NULL);
  unsigned nbconstid = 0;
  for (int ix = 0; ix < MAXSIZE_BM; ix++)
    if (constidarr[ix] == NULL)
      {
        nbconstid = ix;
        break;
      };
  unsigned nbroutid = 0;
  for (int ix = 0; ix < MAXSIZE_BM; ix++)
    if (routidarr[ix] == NULL)
      {
        nbroutid = ix;
        break;
      };
  NONPRINTF_BM
    ("simple_module_initialize modulid %s nbconstid %u, nbroutid %u.",
     modulid, nbconstid, nbroutid);
  for (unsigned oix = 0; oix < nbconstid; oix++)
    {
      _.curob = NULL;
      rawid_tyBM objid = parse_rawid_BM (constidarr[oix], NULL);
      ASSERT_BM (objid.id_hi != 0 && validid_BM (objid));
      _.curob = findobjofid_BM (objid);
      if (!_.curob)
        FATAL_BM
          ("simple_module_initialize: cannot find constant#%d %s for module %s",
           oix, constidarr[oix], objectdbg_BM (_.modulob));
      constobjarr[oix] = _.curob;
    }
  _.constsetv = makeset_BM ((objectval_tyBM **) constobjarr, nbconstid);
  objectval_tyBM **routarr = calloc (nbroutid + 1, sizeof (objectval_tyBM *));
  if (!routarr)
    FATAL_BM ("calloc failed for %d routines", nbroutid);
  for (unsigned rix = 0; rix < nbroutid; rix++)
    {
      _.routob = NULL;
      rawid_tyBM routid = parse_rawid_BM (routidarr[rix], NULL);
      ASSERT_BM (routid.id_hi != 0 && validid_BM (routid));
      _.routob = findobjofid_BM (routid);
      if (!_.routob)
        FATAL_BM
          ("simple_module_initialize: cannot find routine#%d %s for module %s",
           rix, routidarr[rix], objectdbg_BM (_.modulob));
      routarr[rix] = _.routob;
      ASSERT_BM (setcontains_BM (_.constsetv, _.routob));
      char routidbuf[32];
      memset (routidbuf, 0, sizeof (routidbuf));
      idtocbuf32_BM (objid_BM (_.routob), routidbuf);
      ASSERT_BM (!strcmp (routidbuf, routidarr[rix]));
      char routname[48];
      memset (routname, 0, sizeof (routname));
      snprintf (routname, sizeof (routname),
                ROUTINEOBJPREFIX_BM "%s" ROUTINESUFFIX_BM, routidbuf);
      objrout_sigBM *routr = (objrout_sigBM *) dlsym (dlh, routname);
      if (!routr)
        FATAL_BM
          ("simple_module_initialize: dlsym of %s in %s /%s failed: %s",
           routname, objectdbg_BM (_.modulob), modulid, dlerror ());
      _.routob->ob_rout = routr;
      _.routob->ob_sig = BMP_function_sig;
    }
  _.routupv = maketuple_BM (routarr, nbroutid);
  NONPRINTF_BM ("simple_module_initialize ending modulob %s modulid %s\n" ".. constset %s\n" ".. routup %s\n" ".. arg1 %s arg2 %s arg3 %s\n", objectdbg_BM (_.modulob), modulid,        //
                debug_outstr_value_BM (_.constsetv, CURFRAME_BM, 0),    //
                debug_outstr_value_BM (_.routupv, CURFRAME_BM, 0),      //
                debug_outstr_value_BM (_.arg1v, CURFRAME_BM, 0),        //
                debug_outstr_value_BM (_.arg2v, CURFRAME_BM, 0),        //
                debug_outstr_value_BM (_.arg3v, CURFRAME_BM, 0));
  free (routarr), routarr = NULL;
  fprintf (stderr,
           "initialized simple module %s /%s with %u constants and %u routines\n",
           objectdbg_BM (_.modulob), modulid, nbconstid, nbroutid);
  return (value_tyBM)
    makenode5_BM (k_simple_module_initialize, _.constsetv, _.routupv,
                  _.arg1v, _.arg2v, _.arg3v);
}                               /* end simple_module_initialize_BM */





// miniscan_node_conn#apply _1X94b6LizfY_2W2ODAL1F3D

extern objrout_sigBM ROUTINEOBJNAME_BM (_1X94b6LizfY_2W2ODAL1F3D);

value_tyBM
ROUTINEOBJNAME_BM (_1X94b6LizfY_2W2ODAL1F3D)    //miniscan_node_conn#apply
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // connob
 const value_tyBM arg2,         // routprepob
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // expv
 const quasinode_tyBM * restargs /*fromob. */ )
{
  objectval_tyBM *k_apply = BMK_3Nl6LhfUZVb_1itsyWMBfYl;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_1X94b6LizfY_2W2ODAL1F3D,
                 objectval_tyBM * connob;       //
                 objectval_tyBM * routprepob;   //
                 value_tyBM expv;       //
                 value_tyBM subexpv;    //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * subtypob;     //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
                 value_tyBM resultv;    //
    );
  int depth = -1;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  WEAKASSERT_BM (isobject_BM (arg1));
  _.connob = objectcast_BM (arg1);
  WEAKASSERT_BM (isobject_BM (arg2));
  _.routprepob = objectcast_BM (arg2);
  WEAKASSERT_BM (istaggedint_BM (arg3));
  depth = getint_BM (arg3);
  _.expv = arg4;
  if (restargs)
    _.fromob = objectcast_BM (treenthson_BM ((value_tyBM) restargs, 0));
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (_.fromob);
  DBGPRINTF_BM
    ("miniscan_node_conn#apply start routprepob %s depth %d exp %s fromob %s",
     objectdbg_BM (_.routprepob), depth, debug_outstr_value_BM (_.expv,
                                                                CURFRAME_BM,
                                                                0),
     objectdbg1_BM (_.fromob));
  int nbsons = (int) nodewidth_BM ((value_tyBM) _.expv);
  if (nbsons < 1)
    FAILHERE (BMP_node);
  if (nbsons >= MAXAPPLYARGS_BM)
    FAILHERE (BMP_node);
  for (int ix = 0; ix < nbsons; ix++)
    {
      _.subexpv = (value_tyBM) nodenthson_BM ((value_tyBM) _.expv, ix);
      _.subtypob =
        miniscan_expr_BM (_.subexpv, _.routprepob, depth + 1, _.fromob,
                          CURFRAME_BM);
      if (_.subtypob != BMP_object && _.subtypob != BMP_value)
        FAILHERE (makenode2_BM (BMP_node, taggedint_BM (ix), _.subtypob));
      _.subexpv = NULL;
      _.subtypob = NULL;
    }
  DBGPRINTF_BM ("miniscan_node_conn#apply end routprepob %s depth %d exp %s",
                objectdbg_BM (_.routprepob), depth,
                debug_outstr_value_BM (_.expv, CURFRAME_BM, 0));
  LOCALRETURN_BM (BMP_value);
failure:
  DBGPRINTF_BM
    ("miniscan_node_conn#apply failure failin %d exp %s routprepob %s cause %s",
     failin,
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg_BM (_.routprepob),
     debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode4_BM (k_apply, _.expv, _.routprepob, _.fromob, _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniscan_node_conn#apply _1X94b6LizfY_2W2ODAL1F3D */



// miniemit_node_conn#apply _6lTDbwKEMMc_0wsIKviDSce

extern objrout_sigBM ROUTINEOBJNAME_BM (_6lTDbwKEMMc_0wsIKviDSce);

value_tyBM
ROUTINEOBJNAME_BM (_6lTDbwKEMMc_0wsIKviDSce)    //miniemit_node_conn#apply 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // expv
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs /*fromob. */ )
{
  objectval_tyBM *k_apply = BMK_3Nl6LhfUZVb_1itsyWMBfYl;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_6lTDbwKEMMc_0wsIKviDSce,
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * modgenob;     //
                 value_tyBM expv;       //
                 value_tyBM subexpv;    //
                 objectval_tyBM * subtypob;
                 value_tyBM resultv;    //
                 value_tyBM funexpv;    //
                 value_tyBM causev;     //
                 value_tyBM errorv;
    );
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.expv = arg1;
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  if (restargs)
    _.fromob = objectcast_BM (treenthson_BM ((value_tyBM) restargs, 0));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.routprepob));
  int nbsons = nodewidth_BM ((value_tyBM) _.expv);
  bool many = false;
  if (nbsons == 0)
    FAILHERE (k_apply);
  else if (nbsons <= 9)
    {
      objstrbufferprintfpayl_BM (_.modgenob, "(apply%d_BM ((", nbsons);
    }
  else if (nbsons < MAXAPPLYARGS_BM)
    {
      many = true;
      objstrbufferprintfpayl_BM (_.modgenob, "(applymany_BM_BM ((");
    }
  else
    FAILHERE (k_apply);
  _.funexpv = nodenthson_BM (_.expv, 0);
  miniemit_expression_BM (CURFRAME_BM, _.funexpv, _.modgenob, _.routprepob,
                          _.fromob, depth + 1);
  _.funexpv = NULL;
  objstrbufferprintfpayl_BM (_.modgenob, "), ((struct stackframe_stBM*)&_)");
  if (many)
    objstrbufferprintfpayl_BM (_.modgenob, ", /*nbargs=*/%d", nbsons - 1);
  for (int ix = 1; ix < nbsons; ix++)
    {
      _.subexpv = nodenthson_BM (_.expv, ix);
      objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
      objstrbufferprintfpayl_BM (_.modgenob, ",\t (");
      miniemit_expression_BM (CURFRAME_BM, _.subexpv, _.modgenob,
                              _.routprepob, _.fromob, depth + 1);
      objstrbufferprintfpayl_BM (_.modgenob, ")");
    }
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, ")");
  LOCALRETURN_BM (_.expv);
failure:
#undef FAILHERE
  DBGPRINTF_BM
    ("miniemit_node_conn#apply failure failin %d exp %s routprepob %s cause %s",
     failin,
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg_BM (_.routprepob),
     debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode3_BM (k_apply, _.expv, _.routprepob, _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniemit_node_conn#apply _6lTDbwKEMMc_0wsIKviDSce */
