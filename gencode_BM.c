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




//// for the method prepare_routine:basiclo_function
extern objrout_sigBM ROUTINEOBJNAME_BM (_5mnsT1wsdWs_2Qnqsf3wqaP);

value_tyBM
ROUTINEOBJNAME_BM (_5mnsT1wsdWs_2Qnqsf3wqaP)    // prepare_routine:basiclo_function
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recv
 const value_tyBM arg2,         // modgen
 const value_tyBM arg3,         // prepval
 const value_tyBM arg4_ __attribute__ ((unused)),
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM recv;
                 objectval_tyBM * modgenob;
                 value_tyBM args; value_tyBM curarg;
                 objectval_tyBM * routprepob; value_tyBM prepvalset;
                 objectval_tyBM * bindob; value_tyBM errorv;
                 value_tyBM causev;
    );
  const objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  const objectval_tyBM *k_block = BMK_2U8Sj78DMbl_5eerKpaJsNq;
  const objectval_tyBM *k_locals = BMK_24sSVIADeHm_0Sx34wQfG7W;
  const objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  const objectval_tyBM *k_simple_routine_preparation =
    BMK_80060zKi6Un_3isCStegT8A;
  //const objectval_tyBM *k_body = BMK_7DQyvJFMOrC_9IfC3CtYknn;
  const objectval_tyBM *k_bindings = BMK_1zpi50AYid5_0j6it2DwVqm;
  objectval_tyBM *k_binding = BMK_6zu0x6tqX60_8QhJjiAOwul;
  objectval_tyBM *k_prepare_routine = BMK_6qi1DW0Ygkl_4Aqdxq4n5IV;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (Cause); goto failure; } while(0)
  // retrieve arguments
  _.recv = /*function object */ (arg1);
  _.modgenob = /*module generation object */ objectcast_BM (arg2);
  _.prepvalset = /* set of routines */ (value_tyBM) setcast_BM (arg3);
  DBGPRINTF_BM
    ("start prepare_routine:basiclo_function recv=%s modgen=%s prepval=%s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.modgenob),
     debug_outstr_value_BM (_.prepvalset, CURFRAME_BM, 0));
  DBGPRINTF_BM
    ("prepare_routine:basiclo_function modgenob=%s is a %s\n",
     objectdbg_BM (_.modgenob), objectdbg1_BM (objclass_BM (_.modgenob)));
  _.routprepob = makeobj_BM ();
  _.bindob = makeobj_BM ();
  objputclass_BM (_.bindob, k_binding);
  objtouchnow_BM (_.bindob);
  objputattr_BM (_.routprepob, k_bindings, _.bindob);
  DBGPRINTF_BM
    ("prepare_routine:basiclo_function recv %s new routprepob %s new bindob %s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob),
     objectdbg2_BM (_.bindob));
  _.args = objgetattr_BM (_.recv, k_arguments);
  unsigned nbargs = tuplesize_BM (_.args);
  for (unsigned curargix = 0; curargix < nbargs; curargix++)
    {
      _.curarg = tuplecompnth_BM (_.args, curargix);
      DBGPRINTF_BM
        ("prepare_routine:basiclo_function recv %s curargix#%d curarg %s",
         objectdbg_BM (_.recv), curargix, objectdbg1_BM (_.curarg));
      //if (assoc_getattr_BM (_.assocbind, _.curarg))
      {
      }
    }
  DBGPRINTF_BM
    ("prepare_routine:basiclo_function end recv %s", objectdbg_BM (_.recv));
#warning incomplete  prepare_routine:basiclo_function
  WEAKASSERT_BM (false && "prepare_routine:basiclo_function incomplete");
  LOCALRETURN_BM (NULL);
failure:
  DBGPRINTF_BM ("prepare_routine:basiclo_function failin %d cause %s", failin,
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    makenode4_BM (k_prepare_routine, _.recv, _.modgenob, _.prepvalset,
                  _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end  prepare_routine:basiclo_function _5mnsT1wsdWs_2Qnqsf3wqaP */



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
(struct stackframe_stBM * stkf,
 const value_tyBM arg1,
 const value_tyBM arg2, const value_tyBM arg3, const value_tyBM arg4,
 const quasinode_tyBM * restargs)
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
  const objectval_tyBM *k_enumeration = BMK_7BROpIWQHzA_8b1C6i49Pkz;
  //
  const char *nam = findobjectname_BM (_.recv);
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
 const value_tyBM arg2,         // modgen
 const value_tyBM arg3,         // prepvalset
 const value_tyBM arg4, const quasinode_tyBM * restargs)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * modgen;
                 setval_tyBM * prepvalset;
                 objectval_tyBM * curprepob;
                 objectval_tyBM * curtypob;
                 objectval_tyBM * routprep;
                 objectval_tyBM * obhsetblock;
                 objectval_tyBM * typob;
                 value_tyBM recv;
                 const tupleval_tyBM * tupargs;
                 const tupleval_tyBM * tupclosed;
                 objectval_tyBM * obresult;
                 const setval_tyBM * setlocals;
                 const setval_tyBM * setnumbers;
                 const setval_tyBM * setconsts; objectval_tyBM * curvar;
                 value_tyBM curol;
                 value_tyBM oldrol; value_tyBM bodyv; value_tyBM collbl;
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
  const objectval_tyBM *k_blocks = BMK_2lCuMosXupr_5GAoqVgJ8PZ;
  const objectval_tyBM *k_prepare_routine = BMK_6qi1DW0Ygkl_4Aqdxq4n5IV;
  const objectval_tyBM *k_in = BMK_0eMGYofuNVh_8ZP2mXdhtHO;
  const objectval_tyBM *k_collect_blocks = BMK_99lWaExo3Bc_4J3HkjJOIJy;
  const objectval_tyBM *k_modgenob = BMK_0Bl5ro9usp6_1Hll14QwC8f;
  // retrieve arguments
  _.recv = objectcast_BM (arg1);
  WEAKASSERT_BM (isobject_BM (_.recv));
  _.modgen = objectcast_BM (arg2);
  _.prepvalset = setcast_BM (arg3);     /// unneeded, set of all routines
  WEAKASSERT_BM (_.modgen != NULL);
  WEAKASSERT_BM (_.prepvalset != NULL);
  unsigned nbprep = setcardinal_BM (_.prepvalset);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ;  _.causev = (Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("start prepare_routine°basiclo_minifunction recv=%s modgen=%s nbprep=%u",
     objectdbg_BM (_.recv), objectdbg1_BM (_.modgen), nbprep);
  _.tupargs = tuplecast_BM (objgetattr_BM (_.recv, k_arguments));
  _.tupclosed = tuplecast_BM (objgetattr_BM (_.recv, k_closed));
  _.obresult = objectcast_BM (objgetattr_BM (_.recv, k_result));
  _.setlocals = setcast_BM (objgetattr_BM (_.recv, k_locals));
  _.setnumbers = setcast_BM (objgetattr_BM (_.recv, k_numbers));
  _.setconsts = setcast_BM (objgetattr_BM (_.recv, k_constants));
  DBGPRINTF_BM
    ("prepare_routine°basiclo_minifunction recv=%s routprep=%s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprep));
  _.bodyv = objgetattr_BM (_.recv, k_body);
  if (!isobject_BM (_.bodyv))
    {
      FAILHERE (k_body);
    }
  _.routprep = makeobj_BM ();
  objputclass_BM (_.routprep,
                  (objectval_tyBM *) k_simple_routine_preparation);
  objputattr_BM (_.routprep, k_in, _.recv);
  objputattr_BM (_.routprep, k_modgenob, _.modgen);
  unsigned nbargs = tuplesize_BM (_.tupargs);
  unsigned nbclosed = tuplesize_BM (_.tupclosed);
  unsigned nblocals = setcardinal_BM (_.setlocals);
  unsigned nbnumbers = setcardinal_BM (_.setnumbers);
  unsigned nbconsts = setcardinal_BM (_.setconsts);
  DBGPRINTF_BM
    ("start prepare_routine°basiclo_minifunction recv %s nbargs=%u nbclosed=%u nblocals=%u nbnumbers=%u nbconsts=%u",
     objectdbg_BM (_.recv), nbargs, nbclosed, nblocals, nbnumbers, nbconsts);
  objputassocpayl_BM (_.routprep,
                      2 + nbargs + nbclosed + nblocals + nbnumbers +
                      nbconsts);
  objtouchnow_BM (_.routprep);
  //// check and bind the result
  if (_.obresult)
    {
      objlock_BM (_.obresult);
      _.typob = objectcast_BM (objgetattr_BM (_.obresult, k_c_type));
      objunlock_BM (_.obresult);
      if (_.typob != BMP_value && _.typob != BMP_object)
        FAILHERE (makenode1_BM (k_result, _.obresult));
      objassocaddattrpayl_BM (_.routprep, _.obresult, k_result);
    }
  /// bind the arguments
  for (unsigned argix = 0; argix < nbargs; argix++)
    {
      _.curvar = tuplecompnth_BM (_.tupargs, argix);
      _.curtypob = NULL;
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction argix=%u argum curvar=%s",
         argix, objectdbg_BM (_.curvar));
      _.oldrol = objassocgetattrpayl_BM (_.routprep, _.curvar);
      if (_.oldrol)
        FAILHERE (makenode2_BM (k_arguments, _.curvar, _.oldrol));
      objlock_BM (_.curvar);
      _.curtypob = objectcast_BM (objgetattr_BM (_.curvar, k_c_type));
      objunlock_BM (_.curvar);
      if (_.curtypob != BMP_value)
        FAILHERE (makenode2_BM (k_arguments, _.curvar, _.oldrol));

      _.curol = makenode1_BM (k_arguments, taggedint_BM (argix));
      objassocaddattrpayl_BM (_.routprep, _.curvar, _.curol);
      _.curol = NULL;
    }
  /// bind the closed
  for (unsigned cloix = 0; cloix < nbclosed; cloix++)
    {
      _.curvar = tuplecompnth_BM (_.tupclosed, cloix);
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction cloix=%u closed curvar=%s",
         cloix, objectdbg_BM (_.curvar));
      _.oldrol = objassocgetattrpayl_BM (_.routprep, _.curvar);
      if (_.oldrol)
        FAILHERE (makenode2_BM (k_closed, _.curvar, _.oldrol));
      _.curol = makenode1_BM (k_closed, taggedint_BM (cloix));
      objassocaddattrpayl_BM (_.routprep, _.curvar, _.curol);
      _.curol = NULL;
    }
  /// bind the locals
  for (unsigned locix = 0; locix < nblocals; locix++)
    {
      _.curvar = setelemnth_BM (_.setlocals, locix);
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction locix=%u local curvar=%s",
         locix, objectdbg_BM (_.curvar));
      _.oldrol = objassocgetattrpayl_BM (_.routprep, _.curvar);
      if (_.oldrol)
        {
          FAILHERE (makenode2_BM (k_locals, _.curvar, _.oldrol));
        }
      _.curol = makenode1_BM (k_locals, taggedint_BM (locix));
      objassocaddattrpayl_BM (_.routprep, _.curvar, _.curol);
      _.curol = NULL;
    }
  // bind the number vars
  for (unsigned numix = 0; numix < nbnumbers; numix++)
    {
      _.curvar = setelemnth_BM (_.setnumbers, numix);
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction numix=%u number curvar=%s",
         numix, objectdbg_BM (_.curvar));
      _.oldrol = objassocgetattrpayl_BM (_.routprep, _.curvar);
      if (_.oldrol)
        {
          FAILHERE (makenode2_BM (k_numbers, _.curvar, _.oldrol));
        }
      _.curol = makenode1_BM (k_numbers, taggedint_BM (numix));
      objassocaddattrpayl_BM (_.routprep, _.curvar, _.curol);
      _.curol = NULL;
    }
  // bind the constants
  for (unsigned cstix = 0; cstix < nbconsts; cstix++)
    {
      _.curvar = setelemnth_BM (_.setconsts, cstix);
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction cstix=%u constant curvar=%s",
         cstix, objectdbg_BM (_.curvar));
      _.oldrol = objassocgetattrpayl_BM (_.routprep, _.curvar);
      if (_.oldrol)
        {
          FAILHERE (makenode2_BM (k_constants, _.curvar, _.oldrol));
        }
      _.curol = makenode1_BM (k_constants, taggedint_BM (cstix));
      objassocaddattrpayl_BM (_.routprep, _.curvar, _.curol);
      _.curol = NULL;
    }
  _.obhsetblock = makeobj_BM ();
  objputpayload_BM (_.obhsetblock, hashsetobj_grow_BM (NULL, 15));
  objputclass_BM (_.obhsetblock, (objectval_tyBM *) k_hset_object);
  objputattr_BM (_.routprep, k_blocks, _.obhsetblock);
  objputattr_BM (_.routprep, k_prepare_routine, _.recv);
  objputattr_BM (_.routprep, k_in, _.modgen);
  objputattr_BM (_.obhsetblock, k_in, _.routprep);
  objtouchnow_BM (_.obhsetblock);
  objtouchnow_BM (_.routprep);
  DBGPRINTF_BM
    ("prepare_routine°basiclo_minifunction before collect_blocks recv %s routprep %s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprep));
  _.collbl = send2_BM (_.bodyv, k_collect_blocks,
                       CURFRAME_BM, _.routprep, taggedint_BM (0));
  if (!_.collbl)
    {
      FAILHERE (k_collect_blocks);
    }
  DBGPRINTF_BM
    ("prepare_routine°basiclo_minifunction after collect_blocks recv %s routprep %s collbl=%s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprep),
     debug_outstr_value_BM (_.collbl, CURFRAME_BM, 0));
  LOCALRETURN_BM (_.routprep);
failure:
  _.errorv =
    makenode4_BM (k_prepare_routine, _.recv, _.modgen, _.prepvalset,
                  _.causev);
  DBGPRINTF_BM
    ("failure prepare_routine°basiclo_minifunction  failin %d errorv %s",
     failin, debug_outstr_value_BM (_.errorv, CURFRAME_BM, 0));
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end prepare_routine°basiclo_minifunction  _07qYMXftJRR_9dde2ASz4e9  */




// for the method to complete_module in basiclo_temporary_module &
// basiclo_dumpable_module

extern objrout_sigBM ROUTINEOBJNAME_BM (_10XOFm9ui6R_06F8qZQynnA);
value_tyBM
ROUTINEOBJNAME_BM (_10XOFm9ui6R_06F8qZQynnA)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving module
 const value_tyBM arg2,         // module generator
 const value_tyBM arg3,         // preparation
 const value_tyBM arg4 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM recv;
                 value_tyBM modgen;
                 value_tyBM funset; objectval_tyBM * plainmod;
                 objectval_tyBM * curfun;
    );
  // retrieve arguments
  _.recv = (arg1);
  WEAKASSERT_BM (isobject_BM (_.recv));
  _.modgen = (arg2);
  WEAKASSERT_BM (isobject_BM (_.modgen));
  const objectval_tyBM *k_functions_set = BMK_9stpgEfdDDE_7LUgqylTeFI;
  const objectval_tyBM *k_plain_module = BMK_8g1WBJBhDT9_1QK8IcuWYx2;
  const objectval_tyBM *k_basiclo_minifunction = BMK_2Z04aTH1OXJ_4ekKKdOCiOM;
  DBGPRINTF_BM ("complete_module°basiclo*module start recv=%s modgen=%s",
                objectdbg_BM (_.recv), objectdbg1_BM (_.modgen));
  _.funset = setcast_BM (objgetattr_BM (_.modgen, k_functions_set));
  unsigned nbfuns = setcardinal_BM (_.funset);
  _.plainmod = objectcast_BM (objgetattr_BM (_.modgen, k_plain_module));
  DBGPRINTF_BM
    ("complete_module°basiclo*module nbfuns=%u plainmod=%s",
     nbfuns, objectdbg_BM (_.plainmod));
  unsigned nbtinyfuns = 0;
  for (unsigned ix = 0; ix < nbfuns; ix++)
    {
      _.curfun = setelemnth_BM (_.funset, ix);
      if (objectisinstance_BM (_.curfun, k_basiclo_minifunction))
        {
          nbtinyfuns++;
        }
    }
  if (nbtinyfuns == nbfuns)
    {
      DBGPRINTF_BM
        ("complete_module°basiclo*module gives all %u tinyfuncs recv=%s modgen=%s",
         nbtinyfuns, objectdbg_BM (_.recv), objectdbg1_BM (_.modgen));
      LOCALRETURN_BM (_.funset);
    }
  DBGPRINTF_BM
    ("complete_module°basiclo*module nbtinyfuns=%u < nbfuns=%u incomplete",
     nbtinyfuns, nbfuns);
#warning complete_module°basiclo*module unimplemented
  LOCALRETURN_BM (NULL);
}                               /* end complete_module°basiclo*module _10XOFm9ui6R_06F8qZQynnA  */


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

// for the method to collect_blocks in basiclo_block-s 
extern objrout_sigBM ROUTINEOBJNAME_BM (_0gkYrIdnOg2_0wLEAh1QuYu);
value_tyBM
ROUTINEOBJNAME_BM (_0gkYrIdnOg2_0wLEAh1QuYu)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving block
 const value_tyBM arg2,         // routine preparation
 const value_tyBM arg3,         // depth
 const value_tyBM arg4 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  int failin = -1;
  enum
  {
    closix_nbvars,
    closix_nbargs,
    closix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * closv;
                 objectval_tyBM * recv; objectval_tyBM * routprep;
                 objectval_tyBM * curob; value_tyBM curexp;
                 value_tyBM resv;
                 objectval_tyBM * typob; objectval_tyBM * blockhsetob;
                 value_tyBM errorv;
    );
  LOCALGETFUNV_BM (_.closv);
  if (!isclosure_BM (_.closv) || closurewidth_BM (_.closv) != closix__LAST)
    LOCALRETURN_BM (NULL);
  const objectval_tyBM *k_blocks = BMK_2lCuMosXupr_5GAoqVgJ8PZ;
  const objectval_tyBM *k_miniscan_block = BMK_2gthNYOWogO_4sVTU1JbmUH;
  const objectval_tyBM *k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  const objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  const objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  // retrieve arguments
  _.recv = objectcast_BM (arg1);
  WEAKASSERT_BM (isobject_BM (_.recv));
  _.routprep = objectcast_BM (arg2);
  WEAKASSERT_BM (isobject_BM (_.routprep));
  WEAKASSERT_BM (istaggedint_BM (arg3));
  int depth = getint_BM (arg3);
  int nbvars = 0, nbargs = 0;
  // retrieve closed integers
  WEAKASSERT_BM (closurewidth_BM ((const value_tyBM) _.closv) >=
                 closix__LAST);
  {
    value_tyBM nbvarsv =
      closurenthson_BM ((const value_tyBM) _.closv, closix_nbvars);
    WEAKASSERT_BM (istaggedint_BM (nbvarsv));
    nbvars = getint_BM (nbvarsv);
  }
  {
    value_tyBM nbargsv =
      closurenthson_BM ((const value_tyBM) _.closv, closix_nbargs);
    WEAKASSERT_BM (istaggedint_BM (nbargsv));
    nbargs = getint_BM (nbargsv);
  }
  _.blockhsetob = objectcast_BM (objgetattr_BM (_.routprep, k_blocks));
  DBGPRINTF_BM
    ("collect_blocks°basiclo_block start recv=%s routprep=%s depth=%d nbvar=%d nbargs=%d blockhsetob=%s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprep), depth, (int) nbargs,
     (int) nbvars, objectdbg2_BM (_.blockhsetob));
  WEAKASSERT_BM (objhasassocpayl_BM (_.routprep));
  {
    objlock_BM (_.blockhsetob);
    WEAKASSERT_BM (objhashashsetpayl_BM (_.blockhsetob));
    objhashsetaddpayl_BM (_.blockhsetob, _.recv);
    objunlock_BM (_.blockhsetob);
  }
  if (!objhasassocpayl_BM (_.routprep))
    {
      fprintf (stderr, "collect_blocks°basiclo_block bad routprep %s\n",
               objectdbg_BM (_.routprep));
      LOCALRETURN_BM (NULL);
    }

  for (int varix = 0; varix < nbvars; varix++)
    {
      _.curob = objectcast_BM (objgetcomp_BM (_.recv, varix));
      DBGPRINTF_BM
        ("collect_blocks°basiclo_block recv %s varix#%d curob %s",
         objectdbg_BM (_.recv), varix, objectdbg1_BM (_.curob));
      if (!_.curob)
        {
          fprintf (stderr,
                   "collect_blocks°basiclo_block bad variable for varix#%d\n",
                   varix);
          LOCALRETURN_BM (NULL);
        }
      if (!objassocgetattrpayl_BM (_.routprep, _.curob))
        {
          fprintf (stderr,
                   "collect_blocks°basiclo_block unknown variable %s for varix#%d\n",
                   objectdbg_BM (_.curob), varix);
          LOCALRETURN_BM (NULL);
        }
      miniscan_var_BM (_.curob, _.routprep, depth, _.recv, CURFRAME_BM);
    }
  for (int argix = 0; argix < nbargs; argix++)
    {
      _.curexp = (objgetcomp_BM (_.recv, argix + nbvars));
      DBGPRINTF_BM ("collect_blocks°basiclo_block argix#%d curexp %s",
                    argix, debug_outstr_value_BM (_.curexp, CURFRAME_BM, 0));
      miniscan_expr_BM (_.curexp, _.routprep, depth, _.recv, CURFRAME_BM);
    }
  int off = nbvars + nbargs;
  int nbblocks = objnbcomps_BM (_.recv) - off;
  for (int blockix = 0; blockix < nbblocks; blockix++)
    {
      _.curob = objectcast_BM (objgetcomp_BM (_.recv, blockix + off));
      DBGPRINTF_BM
        ("collect_blocks°basiclo_block recv %s blockix#%d curob %s",
         objectdbg_BM (_.recv), blockix, objectdbg1_BM (_.curob));
      if (!_.curob)
        {
          fprintf (stderr,
                   "collect_blocks°basiclo_block bad block for blockix#%d\n",
                   blockix);
          LOCALRETURN_BM (NULL);
        }
      if (objectisinstance_BM (_.curob, k_basiclo_block))
        {
          /// should send k_miniscan_block
          DBGPRINTF_BM
            ("collect_blocks°basiclo_block recv %s miniscan_block-> %s",
             objectdbg_BM (_.recv), objectdbg1_BM (_.curob));
          _.resv =
            send3_BM (_.curob, k_miniscan_block,
                      CURFRAME_BM, _.routprep, taggedint_BM (depth), _.recv);
          if (!_.resv)
            {
              fprintf (stderr,
                       "collect_blocks°basiclo_block miniscan_block for %s blockix#%d failed\n",
                       objectdbg_BM (_.curob), blockix);
              LOCALRETURN_BM (NULL);
            }
        }
      else if (objectisinstance_BM (_.curob, k_basiclo_statement))
        {
          DBGPRINTF_BM
            ("collect_blocks°basiclo_block recv %s miniscan_stmt-> %s",
             objectdbg_BM (_.recv), objectdbg1_BM (_.curob));
          /// should send k_miniscan_stmt
          _.resv = send3_BM (_.curob,
                             k_miniscan_stmt,
                             CURFRAME_BM,
                             _.routprep, taggedint_BM (depth), _.recv);
          if (!_.resv)
            {
              fprintf (stderr,
                       "collect_blocks°basiclo_block miniscan_stmt for %s blockix#%d failed\n",
                       objectdbg_BM (_.curob), blockix);
              LOCALRETURN_BM (NULL);
            }
        }
      else
        {
          fprintf (stderr,
                   "collect_blocks°basiclo_block invalid block %s for blockix#%d\n",
                   objectdbg_BM (_.curob), blockix);
          LOCALRETURN_BM (NULL);
        }
      DBGPRINTF_BM
        ("collect_blocks°basiclo_block recv %s blockix#%d done curob %s",
         objectdbg_BM (_.recv), blockix, objectdbg1_BM (_.curob));
    }
  DBGPRINTF_BM
    ("collect_blocks°basiclo_block done recv=%s routprep=%s depth %d",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprep), depth);
  LOCALRETURN_BM (_.routprep);
}                               /* end collect_blocks°basiclo_block _0gkYrIdnOg2_0wLEAh1QuYu */




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
  objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
  objectval_tyBM *k_string = BMK_4T8am97muLl_5969SR22Ecq;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ k_miniscan_compatype,
                 objectval_tyBM * typ1ob;
                 objectval_tyBM * typ2ob;
    );
  _.typ1ob = typ1ob;
  _.typ2ob = typ2ob;
  if (_.typ1ob == k_object && _.typ2ob == k_value
      || _.typ1ob == k_value && _.typ2ob == k_object)
    LOCALRETURN_BM (k_value);
  LOCALRETURN_BM (NULL);
}                               /* end miniscan_compatype_BM */



objectval_tyBM *
miniscan_var_BM (objectval_tyBM * varob,
                 objectval_tyBM * routprepob, int depth,
                 objectval_tyBM * fromob, struct stackframe_stBM *stkf)
{
  const objectval_tyBM *k_miniscan_var = BMK_6jh60mO0Cgd_84B0HiNphqA;
  objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  objectval_tyBM *k_numbers = BMK_32eKNcTZ9HN_80t0nk47Mha;
  objectval_tyBM *k_locals = BMK_24sSVIADeHm_0Sx34wQfG7W;
  objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
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
      if (_.rolconnob == k_arguments || _.rolconnob == k_locals
          || _.rolconnob == k_constants)
        {
          LOCALRETURN_BM (k_value);
        }
      else if (_.rolconnob == k_numbers)
        {
          LOCALRETURN_BM (k_int);
        }
      else
        FAILHERE ();
    }
#warning incomplete miniscan_var_BM
  DBGPRINTF_BM ("miniscan_var end varob=%s", objectdbg_BM (_.varob));
  LOCALRETURN_BM (NULL);
failure:
  _.errorv =
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
  int failin = -1;
#define FAILHERE() do { failin = __LINE__ ; goto failure; } while(0)
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ k_miniscan_expr,
                 value_tyBM expv; value_tyBM resv;
                 objectval_tyBM * routprepob; objectval_tyBM * fromob;
                 objectval_tyBM * expob; objectval_tyBM * connob;
                 value_tyBM avalv; objectval_tyBM * typob;
                 value_tyBM errorv;
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
          ("miniscan_expr miniscan_node_conn->%s arity %d routprepob %s fromob %s before",
           objectdbg_BM (_.connob), arity, objectdbg1_BM (_.routprepob),
           objectdbg2_BM (_.fromob));
        _.resv = send4_BM (_.connob, k_miniscan_node_conn,      //
                           CURFRAME_BM, //
                           _.routprepob,
                           taggedint_BM (depth), _.expv, _.fromob);
        DBGPRINTF_BM ("miniscan_expr miniscan_node_conn->%s done resv=%s",      //
                      objectdbg_BM (_.connob),  //
                      debug_outstr_value_BM (_.resv, CURFRAME_BM, 0));
        if (!_.resv)
          FAILHERE ();
        LOCALRETURN_BM (_.resv);
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
  _.errorv =
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
                 objectval_tyBM * recv; objectval_tyBM * routprepob;
                 objectval_tyBM * fromblockob; objectval_tyBM * compob;
                 objectval_tyBM * seqcompob; value_tyBM testexpv;
                 value_tyBM resv;
    );
  objectval_tyBM *k_basiclo_when = BMK_3fvdRZNCmJS_5bTAPr83mXg;
  objectval_tyBM *k_test = BMK_2j84OTHlFdJ_1pMyQfgsmAz;
  // objectval_tyBM *k_miniscan_expr = BMK_7k3xb0vred0_9ZRHcZmhw77;
  const objectval_tyBM *k_miniscan_block = BMK_2gthNYOWogO_4sVTU1JbmUH;
  const objectval_tyBM *k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  int depth = 0;
  bool badson = false;
  _.recv = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  depth = getint_BM (arg3);
  _.fromblockob = objectcast_BM (arg4);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_cond start recv=%s routprepob=%s depth#%d fromblockob=%s start",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromblockob));
  objlock_BM (_.recv);
  unsigned nbsons = objnbcomps_BM (_.recv);
  for (unsigned ix = 0; ix < nbsons && !badson; ix++)
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
          for (unsigned cix = 0; cix < nbsubcomp && !badson; cix++)
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
                    badson = true;
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
                    badson = true;
                }
              objunlock_BM (_.seqcompob);

            }
        }
      else
        badson = true;
      objunlock_BM (_.compob);
      DBGPRINTF_BM
        ("miniscan_stmt°basiclo_cond recv=%s ix=%u done compob=%s badson %s",
         objectdbg_BM (_.recv), ix, objectdbg1_BM (_.compob),
         badson ? "true" : "false");
    }
  objunlock_BM (_.recv);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_cond ending recv=%s badson %s",
     objectdbg_BM (_.recv), badson ? "true" : "false");
  if (badson)
    LOCALRETURN_BM (NULL);
  else
    LOCALRETURN_BM (_.recv);
}                               /* end routine miniscan_stmt°basiclo_cond _0zzJJsAL6Qm_2uw3eoWQHEq */




// miniscan_stmt°basiclo_assign _7LNRlilrowp_0GG6ZLUFovu
extern objrout_sigBM ROUTINEOBJNAME_BM (_7LNRlilrowp_0GG6ZLUFovu);

value_tyBM
ROUTINEOBJNAME_BM (_7LNRlilrowp_0GG6ZLUFovu)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving assign
 const value_tyBM arg2,         // routine preparation
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // containingblock
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_7LNRlilrowp_0GG6ZLUFovu,
                 objectval_tyBM * recv;
                 objectval_tyBM * routprepob; objectval_tyBM * fromblockob;
                 objectval_tyBM * destob; value_tyBM srcexpv;
                 objectval_tyBM * vartypob; objectval_tyBM * srctypob;
                 value_tyBM resv;
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



// miniscan_node_conn°basiclo_primitive  _1vuSUudDrEr_9UjFr4Pcy8r
extern objrout_sigBM ROUTINEOBJNAME_BM (_1vuSUudDrEr_9UjFr4Pcy8r);

value_tyBM
ROUTINEOBJNAME_BM (_1vuSUudDrEr_9UjFr4Pcy8r)    // miniscan_node_conn°basiclo_primitive
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // connob
 const value_tyBM arg2,         // routprepob
 const value_tyBM arg3,         // depthv
 const value_tyBM arg4,         // expv
 const quasinode_tyBM * restargs /*fromob */ )
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_1vuSUudDrEr_9UjFr4Pcy8r,
                 objectval_tyBM * connob;
                 objectval_tyBM * routprepob; value_tyBM expv;
                 objectval_tyBM * fromob; value_tyBM connargsv;
                 objectval_tyBM * restypob; value_tyBM resultv;
                 value_tyBM errorv;
                 value_tyBM cursonv; objectval_tyBM * curargob;
                 objectval_tyBM * curtypob; objectval_tyBM * curargctypob;
                 objectval_tyBM * connrestypob; objectval_tyBM * curcomptypob;
                 value_tyBM extraerrorv;
    );
  int failin = -1;
#define FAILHERE(Xtra) do { failin = __LINE__ ; _.extraerrorv = (Xtra); goto failure; } while(0)
  objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  objectval_tyBM *k_result_type = BMK_8oZ9fPJGhmS_24c2sSYsdr2;
  objectval_tyBM *k_miniscan_node_conn = BMK_5EGLdtUAQxA_1nebCsDKqOF;
  objectval_tyBM *k_arity = BMK_6fPPUXnZhy5_8Lh5DOOe0Nu;
  objectval_tyBM *k_c_type = BMK_83kM1HtO8K3_6k0F2KYQT3W;
  _.connob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  int depth = getint_BM (arg3);
  _.expv = arg4;
  _.fromob = objectcast_BM (treenthson_BM (restargs, 0));
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
  _.errorv =
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
  if (_.retypob != k_value)
    FAILHERE ();
  LOCALRETURN_BM (_.retypob);
failure:
  DBGPRINTF_BM ("miniscan_stmt°basiclo_return failin %d", failin);
  _.errorv =
    makenode4_BM (k_return, _.retexpv, _.routprepob,
                  taggedint_BM (depth), _.recv);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end  miniscan_stmt°basiclo_return  _7vlMCZ0yvva_6tx0lFlqBG8 */





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
#define FAILHERE(Cause) do { failin = __LINE__ ; errcausev = (Cause); goto failure; } while(0)

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
  objectval_tyBM *k_c_type = BMK_83kM1HtO8K3_6k0F2KYQT3W;
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
      _.blocksetv = objhashsettosetpayl_BM (_.hsetblockob);
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
      _.keysetv = objassocsetattrspayl_BM (_.routprepob);
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
        }
      _.setv = objhashsettosetpayl_BM (_.hsetvalob);
      objputattr_BM (_.routprepob, k_value_set, _.setv);
      DBGPRINTF_BM ("emit_declaration°simple_routine_preparation routprepob=%s value_set %s",  //
                    objectdbg_BM (_.routprepob),        //
                    debug_outstr_value_BM (_.setv, CURFRAME_BM, 0));
      _.setv = objhashsettosetpayl_BM (_.hsetnumob);
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
    char *routname = findobjectname_BM (_.routob);
    WEAKASSERT_BM (objhasstrbufferpayl_BM (_.modgenob));
    if (routname)
      objstrbufferprintfpayl_BM (_.modgenob, "\n"
                                 "extern objrout_sigBM crout%s_BM; // %s\n",
                                 routidbuf, routname);
    else
      objstrbufferprintfpayl_BM (_.modgenob, "\n"
                                 "extern objrout_sigBM crout%s_BM;\n",
                                 routidbuf);
    objunlock_BM (_.modgenob);
  }
  LOCALRETURN_BM (_.routprepob);
failure:
  _.errorv =
    makenode4_BM (k_emit_declaration, _.routprepob, _.modgenob,
                  taggedint_BM (rank), _.errcausev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end emit_declaration°simple_routine_preparation _9M3BqmOS7mA_96DTa52k7Xq */



extern void emit_expression_BM (struct stackframe_stBM *stkf, value_tyBM expv,
                                objectval_tyBM * modgenob,
                                objectval_tyBM * routprepob,
                                objectval_tyBM * fromob, int depth);

extern void emit_var_BM (struct stackframe_stBM *stkf,
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
                 objectval_tyBM * routob; objectval_tyBM * hsetblockob;
                 value_tyBM blocksetv; value_tyBM argtupv;
                 objectval_tyBM * bodyob; objectval_tyBM * resultob;
                 value_tyBM setnumv; value_tyBM setvalv;
                 objectval_tyBM * varob;
                 value_tyBM emitv; objectval_tyBM * typob; value_tyBM errorv;
                 value_tyBM causev;
    );
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (Cause); goto failure; } while(0)
  char routidbuf[32];
  memset (routidbuf, 0, sizeof (routidbuf));
  objectval_tyBM *k_emit_definition = BMK_1g8s9B96Irf_6Ix2Cyy8Hq0;
  objectval_tyBM *k_blocks = BMK_2lCuMosXupr_5GAoqVgJ8PZ;
  objectval_tyBM *k_prepare_routine = BMK_6qi1DW0Ygkl_4Aqdxq4n5IV;
  objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  objectval_tyBM *k_body = BMK_7DQyvJFMOrC_9IfC3CtYknn;
  objectval_tyBM *k_result = BMK_7bD9VtDkGSn_7lxHeYuuFLR;
  objectval_tyBM *k_value_set = BMK_6Fl0Z0OTtV9_8QTsq3uDu4q;
  objectval_tyBM *k_number_set = BMK_5uPst3m4mdx_05Xl1AoTnZL;
  objectval_tyBM *k_c_type = BMK_83kM1HtO8K3_6k0F2KYQT3W;
  objectval_tyBM *k_object = BMK_7T9OwSFlgov_0wVJaK1eZbn;
  objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
  objectval_tyBM *k_emit_expression = BMK_9lXSe7DrOl6_7hghYt0LhTF;
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_emit_block = BMK_6mk5eos8067_1odgCpnWMOj;
  objectval_tyBM *k_emit_reference = BMK_6qzzDyr2eIo_3SapnOUpg6S;
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
  {
    objlock_BM (_.routprepob);
    _.routob =
      objectcast_BM (objgetattr_BM (_.routprepob, k_prepare_routine));
    _.setnumv = setcast_BM (objgetattr_BM (_.routprepob, k_number_set));
    _.setvalv = setcast_BM (objgetattr_BM (_.routprepob, k_value_set));
    objunlock_BM (_.routprepob);
    idtocbuf32_BM (objid_BM (_.routob), routidbuf);
  }
  DBGPRINTF_BM ("emit_definition°simple_routine_preparation routprepob=%s routob=%s\n" //
                ".. setnum=%s setval=%s", objectdbg_BM (_.routprepob), objectdbg1_BM (_.routob),        //
                debug_outstr_value_BM (_.setnumv, CURFRAME_BM, 0),      //
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
    ("emit_definition°simple_routine_preparation routob=%s argtup=%s bodyob=%s resultob=%s",
     objectdbg_BM (_.routob), debug_outstr_value_BM (_.argtupv, CURFRAME_BM,
                                                     0),
     objectdbg1_BM (_.bodyob), objectdbg2_BM (_.resultob));
  {
    objlock_BM (_.resultob);
    _.typob = objectcast_BM (objgetattr_BM (_.resultob, k_c_type));
    objunlock_BM (_.resultob);
  }
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation routprepob=%s argtupv=%s bodyob=%s resultob=%s of type %s",
     objectdbg_BM (_.routprepob),
     debug_outstr_value_BM (_.argtupv, CURFRAME_BM, 0),
     objectdbg1_BM (_.bodyob), objectdbg2_BM (_.resultob),
     objectdbg3_BM (_.typob));
  WEAKASSERT_BM (isobject_BM (_.resultob));
  int nbargs = tuplesize_BM (_.argtupv);
  {
    char *routname = findobjectname_BM (_.routob);
    char routidbuf[32];
    memset (routidbuf, 0, sizeof (routidbuf));
    idtocbuf32_BM (objid_BM (_.routob), routidbuf);
    if (routname)
      objstrbufferprintfpayl_BM (_.modgenob, "\n"
                                 "value_tyBM crout%s_BM\n"
                                 " (struct stackframe_stBM* stkf, //+ %s\n",
                                 routidbuf, routname);
    else
      objstrbufferprintfpayl_BM (_.modgenob, "\n"
                                 "value_tyBM crout%s_BM\n"
                                 " (struct stackframe_stBM* stkf,\n",
                                 routidbuf);
    objstrbufferprintfpayl_BM ("  // %d arguments\n", nbargs);
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
  objstrbufferprintfpayl_BM (_.modgenob,
                             "    struct stackframe_stBM *stkfram_descr;\n");
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
  objstrbufferprintfpayl_BM (_.modgenob, "   _.stkfram_prev = stkf;\n");
  objstrbufferprintfpayl_BM (_.modgenob, "   // fetch %d arguments:\n",
                             nbargs);
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation routprepob=%s nbargs=%d bodyob=%s",
     objectdbg_BM (_.routprepob), nbargs, objectdbg1_BM (_.bodyob));
  if (nbargs > 4)
    objstrbufferprintfpayl_BM (_.modgenob,
                               "   unsigned nbrestargs = treewidth_BM(restargs);\n");
  for (unsigned aix = 0; aix < nbargs; aix++)
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
            objstrbufferprintfpayl_BM (_.modgenob,
                                       "#error fail fetch #%d %s of type %s\n",
                                       aix, varidbuf, objectdbg_BM (_.typob));
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
            objstrbufferprintfpayl_BM (_.modgenob,
                                       "#error fail fetch xtra #%d %s of type %s\n",
                                       aix, varidbuf, objectdbg_BM (_.typob));
        }
    }
  objstrbufferprintfpayl_BM (_.modgenob, "   // fetched %d arguments.\n",
                             nbargs);
  objstrbufferprintfpayl_BM (_.modgenob, "   // routine body:\n");
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
  objunlock_BM (_.modgenob);

#warning unimplemented emit_definition°simple_routine_preparation routine
  WEAKASSERT_BM (false
                 &&
                 "unimplemented emit_definition°simple_routine_preparation routine");
failure:
  DBGPRINTF_BM ("emit_definition°simple_routine_preparation failin %d routprep %s cause %s",   //
                failin, objectdbg_BM (_.routprepob),    //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
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
  LOCALFRAME_BM (stkf, /*descr: */ BMK_8UGpvfrcKbM_99IeP3BuxA5,
                 objectval_tyBM * blockob; objectval_tyBM * modgenob;
                 objectval_tyBM * routprepob; objectval_tyBM * stmtob;
                 value_tyBM resultv; value_tyBM emitv;
                 value_tyBM causev;
                 value_tyBM errorv;
    );
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_emit_block = BMK_6mk5eos8067_1odgCpnWMOj;
  _.blockob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("emit_block°basiclo_block start blockob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.blockob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  WEAKASSERT_BM (isobject_BM (_.blockob));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.routprepob));
  WEAKASSERT_BM (istaggedint_BM (arg4));
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.modgenob));
  char blockidbuf[32];
  memset (blockidbuf, 0, sizeof (blockidbuf));
  idtocbuf32_BM (objid_BM (_.blockob), blockidbuf);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n"
                             "startblock_%s: __attribute__((unused))\n"
                             "{ /* +block %s */", blockidbuf);
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
        _.emitv = send3_BM (_.stmtob, k_emit_statement, CURFRAME_BM,    //
                            _.modgenob, _.routprepob, taggedint_BM (indepth));
        objstrbuffernewlinepayl_BM (_.modgenob);
        objunlock_BM (_.stmtob);
      }
      if (!_.emitv)
        FAILHERE (makenode1_BM (k_emit_statement, _.stmtob));
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
  _.errorv =
    makenode4_BM (k_emit_block, _.blockob, _.routprepob, _.modgenob,
                  _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_block°basiclo_block _8UGpvfrcKbM_99IeP3BuxA5 */



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
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (Cause); goto failure; } while(0)
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
  _.errorv =
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
  _.whenob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  WEAKASSERT_BM (istaggedint_BM (arg4));
  int depth = getint_BM (arg4);
  char whenidbuf[32];
  memset (whenidbuf, 0, sizeof (whenidbuf));
  idtocbuf32_BM (objid_BM (_.whenob), whenidbuf);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (Cause); goto failure; } while(0)
  WEAKASSERT_BM (isobject_BM (_.whenob));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.routprepob));
  _.testexpv = objgetattr_BM (_.whenob, k_test);
  DBGPRINTF_BM
    ("emit_when°basiclo_when start whenob=%s whenid=%s modgenob=%s routprepob=%s testexp=%s",
     objectdbg_BM (_.whenob), whenidbuf, objectdbg2_BM (_.modgenob),
     objectdbg3_BM (_.routprepob),
     debug_outstr_value_BM (_.testexpv, CURFRAME_BM, 0));
  // whenob is locked by caller emit_statment°basiclo_cond
  objstrbufferprintfpayl_BM (_.modgenob, "/*when %s:*/ (",
                             objectdbg_BM (_.whenob));
  emit_expression_BM (CURFRAME_BM, _.testexpv, _.modgenob, _.routprepob,
                      _.whenob, depth);
  objstrbufferappendcstrpayl_BM (_.modgenob, ") {");
  int indepth = depth + 1;
  objstrbuffersetindentpayl_BM (_.modgenob, indepth);
  objstrbuffernewlinepayl_BM (_.modgenob);
#warning unimplemented emit_when°basiclo_when _9Wk97VJLuH1_0FwsSpfatDg routine
  WEAKASSERT_BM (false
                 &&
                 "unimplemented  emit_when°basiclo_when _9Wk97VJLuH1_0FwsSpfatDg routine");
  LOCALRETURN_BM (_.resultv);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("emit_when°basiclo_when failin %d whenob %s routprep %s cause %s", failin, objectdbg_BM (_.whenob), objectdbg2_BM (_.routprepob),      //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    makenode4_BM (k_emit_when, _.whenob, _.routprepob, _.modgenob, _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_when°basiclo_when _9Wk97VJLuH1_0FwsSpfatDg */




extern void
emit_expression_BM (struct stackframe_stBM *stkf, value_tyBM expv,
                    objectval_tyBM * modgenob, objectval_tyBM * routprepob,
                    objectval_tyBM * fromob, int depth)
{
  objectval_tyBM *k_emit_expression = BMK_9lXSe7DrOl6_7hghYt0LhTF;
  objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
  objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  objectval_tyBM *k_string = BMK_4T8am97muLl_5969SR22Ecq;
  objectval_tyBM *k_miniemit_node_conn = BMK_7L782rSgJBB_9vjsBdqAoz7;
  LOCALFRAME_BM (stkf, /*descr: */ k_emit_expression,
                 value_tyBM expv;
                 value_tyBM avalv;
                 objectval_tyBM * expob; objectval_tyBM * modgenob;
                 objectval_tyBM * routprepob; objectval_tyBM * fromob;
                 objectval_tyBM * connob; value_tyBM errorv;
                 value_tyBM causev;
                 value_tyBM resv;
    );
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (Cause); goto failure; } while(0)
  _.expv = expv;
  _.modgenob = objectcast_BM (modgenob);
  _.routprepob = objectcast_BM (routprepob);
  _.fromob = objectcast_BM (fromob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (_.routprepob);
  DBGPRINTF_BM ("emit_expression start expv %s modgen %s routprep %s",
                debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
                objectdbg_BM (_.modgenob), objectdbg1_BM (_.routprepob));
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
        DBGPRINTF_BM ("emit_expr expob=%s avalv=%s",
                      objectdbg_BM (_.expob),
                      debug_outstr_value_BM (_.avalv, CURFRAME_BM, 0));
        if (_.avalv != NULL)
          {
            WEAKASSERT_BM (false && "unimplemented emit_expr object");
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
        DBGPRINTF_BM
          ("emit_expression connob %s arity %d routprepob %s fromob %s before",
           objectdbg_BM (_.connob), arity, objectdbg1_BM (_.routprepob),
           objectdbg2_BM (_.fromob));
        _.resv = send5_BM (_.connob, k_miniemit_node_conn,      //
                           CURFRAME_BM, //
                           _.expv,
                           _.modgenob,
                           _.routprepob, taggedint_BM (depth), _.fromob);
        DBGPRINTF_BM ("emit_expression miniscan_node_conn->%s done resv=%s",    //
                      objectdbg_BM (_.connob),  //
                      debug_outstr_value_BM (_.resv, CURFRAME_BM, 0));
        if (!_.resv)
          FAILHERE (NULL);
        objunlock_BM (_.connob);
        LOCALRETURN_BM (NULL);
      }
    default:
      FAILHERE (NULL);
    }
  WEAKASSERT_BM (false && "unimplemented emit_expression_BM");
#warning unimplemented emit_expression_BM
  LOCALJUSTRETURN_BM ();
failure:
  DBGPRINTF_BM ("emit_expression_BM failin %d expv %s routprep %s cause %s", failin, debug_outstr_value_BM (_.expv, CURFRAME_BM, 0), objectdbg2_BM (_.routprepob),      //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    makenode4_BM (k_emit_expression, expv, _.routprepob, _.modgenob,
                  _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_expression_BM */



void
emit_var_BM (struct stackframe_stBM *stkf, objectval_tyBM * refob,
             objectval_tyBM * modgenob, objectval_tyBM * routprepob,
             objectval_tyBM * fromob, int depth)
{
  objectval_tyBM *k_emit_reference = BMK_6qzzDyr2eIo_3SapnOUpg6S;
  LOCALFRAME_BM (stkf, /*descr: */ k_emit_reference,
                 objectval_tyBM * refob;
                 objectval_tyBM * modgenob; objectval_tyBM * routprepob;
                 objectval_tyBM * fromob; value_tyBM errorv;
                 value_tyBM causev;
    );
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (Cause); goto failure; } while(0)
  _.refob = objectcast_BM (refob);
  _.modgenob = objectcast_BM (modgenob);
  _.routprepob = objectcast_BM (routprepob);
  _.fromob = objectcast_BM (fromob);
  WEAKASSERT_BM (_.refob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (_.routprepob);
  DBGPRINTF_BM
    ("emit_var_BM start refob %s modgen %s routprep %s depth %d",
     objectdbg_BM (_.refob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  WEAKASSERT_BM (false && "unimplemented emit_var_BM");
#warning unimplemented emit_var_BM
  LOCALJUSTRETURN_BM ();
failure:
  DBGPRINTF_BM ("emit_var_BM failin %d ref %s routprep %s cause %s", failin, objectdbg_BM (_.refob), objectdbg1_BM (_.routprepob),      //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    makenode4_BM (k_emit_reference, refob, _.routprepob, _.modgenob,
                  _.causev);
  FAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_var_BM */



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
                 value_tyBM expv;
                 value_tyBM connargsv;
                 value_tyBM conncexpansionv; value_tyBM connchunkv;
                 objectval_tyBM * modgenob; objectval_tyBM * routprepob;
                 objectval_tyBM * fromob;
    );
  int depth = -1;
  objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  objectval_tyBM *k_cexpansion = BMK_7yoiT31GmV4_2iTjHx3P2hb;
  objectval_tyBM *k_chunk = BMK_3pQnBS9ZjkQ_0uGmqUUhAum;
  _.connob = objectcast_BM (arg1);
  _.expv = arg2;
  _.modgenob = objectcast_BM (arg3);
  _.routprepob = objectcast_BM (arg4);
  unsigned nbrestargs = treewidth_BM (restargs);
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
  DBGPRINTF_BM ("miniemit_node_conn°basiclo_primitive connob=%s connargs=%s conncexpansion=%s", objectdbg_BM (_.connob),       //
                debug_outstr_value_BM (_.connargsv, CURFRAME_BM, 0),
                debug_outstr_value_BM (_.conncexpansionv, CURFRAME_BM, 0));
  WEAKASSERT_BM (istuple_BM (_.connargsv));
  WEAKASSERT_BM (isnode_BM (_.conncexpansionv)
                 && nodeconn_BM (_.conncexpansionv) == k_chunk);
#warning unimplemented _0BaXSIhDAHO_9x6t4zdbUhj routine
  WEAKASSERT_BM (false && "unimplemented _0BaXSIhDAHO_9x6t4zdbUhj routine");
  LOCALRETURN_BM (_.resultv);
}                               /* end miniemit_node_conn°basiclo_primitive _0BaXSIhDAHO_9x6t4zdbUhj */
