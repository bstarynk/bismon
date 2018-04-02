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
(struct stackframe_stBM * stkf, const value_tyBM arg1, const value_tyBM arg2, const value_tyBM arg3,    //
 const value_tyBM arg4_ __attribute__ ((unused)),
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM recv;
                 objectval_tyBM * modgenob;
                 value_tyBM args; value_tyBM curarg;
                 objectval_tyBM * routprepob; value_tyBM prepvalset;
                 objectval_tyBM * bindob;
    );
  const objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  const objectval_tyBM *k_block = BMK_2U8Sj78DMbl_5eerKpaJsNq;
  const objectval_tyBM *k_locals = BMK_24sSVIADeHm_0Sx34wQfG7W;
  const objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  const objectval_tyBM *k_simple_routine_preparation =
    BMK_80060zKi6Un_3isCStegT8A;
  const objectval_tyBM *k_body = BMK_7DQyvJFMOrC_9IfC3CtYknn;
  const objectval_tyBM *k_bindings = BMK_1zpi50AYid5_0j6it2DwVqm;
  objectval_tyBM *k_binding = BMK_6zu0x6tqX60_8QhJjiAOwul;
  // retrieve arguments
  _.recv = /*function object */ (arg1);
  _.modgenob = /*module generation object */ objectcast_BM (arg2);
  _.prepvalset = /* set of routines */ (value_tyBM) setcast_BM (arg3);
  DBGPRINTF_BM
    ("start prepare_routine:basiclo_function _5mnsT1wsdWs_2Qnqsf3wqaP recv=%s",
     objectdbg_BM (_.recv));
  DBGPRINTF_BM
    ("prepare_routine:basiclo_function modgenob=%s is a %s\n",
     objectdbg_BM (_.modgenob), objectdbg1_BM (objclass_BM (_.modgenob)));
  ////
  /// body: _36MhHxakHKT_1ZzV5Xoj5LX  
  /// assign _3jiDSyFdbdk_2PQpjqDkEUJ:
  _.routprepob = makeobj_BM ();
  /// assign _0cBpCT3lEHS_338HjZpF4UE:
  _.bindob = makeobj_BM ();
  objputclass_BM (_.bindob, k_binding);
  objtouchnow_BM (_.bindob);
  /// run _2hJWe55ydpv_5kaGdOUymFI:
  objputattr_BM (_.routprepob, k_bindings, _.bindob);
  //  objputattr_BM (_.routprepob, k_bindings, _.bindob);
  DBGPRINTF_BM
    ("prepare_routine:basiclo_function recv %s new routprepob %s new bindob %s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob),
     objectdbg2_BM (_.bindob));
  /// assign _9YS82HkgghD_71BLsDAKRfg
  _.args = objgetattr_BM (_.recv, k_arguments);
  /// foreach_in_tuple(args curarg curargix args ...) _0UqUZ7mQGG5_69QlCmcSwTi
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
#warning incomplete  prepare_routine:basiclo_function _5mnsT1wsdWs_2Qnqsf3wqaP
  LOCALRETURN_BM (NULL);
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
                 objectval_tyBM * routprep;
                 objectval_tyBM * obhsetblock;
                 value_tyBM recv;
                 const tupleval_tyBM * tupargs;
                 const tupleval_tyBM * tupclosed;
                 objectval_tyBM * obresult;
                 const setval_tyBM * setlocals;
                 const setval_tyBM * setnumbers;
                 const setval_tyBM * setconsts;
                 objectval_tyBM * curvar; value_tyBM curol; value_tyBM oldrol;
                 value_tyBM bodyv;
                 value_tyBM collbl;
    );
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
  DBGPRINTF_BM
    ("start prepare_routine°basiclo_minifunction recv=%s modgen=%s nbprep=%u",
     objectdbg_BM (_.recv), objectdbg1_BM (_.modgen), nbprep);
  _.tupargs = tuplecast_BM (objgetattr_BM (_.recv, k_arguments));
  _.tupclosed = tuplecast_BM (objgetattr_BM (_.recv, k_closed));
  _.obresult = objectcast_BM (objgetattr_BM (_.recv, k_result));
  _.setlocals = setcast_BM (objgetattr_BM (_.recv, k_locals));
  _.setnumbers = setcast_BM (objgetattr_BM (_.recv, k_numbers));
  _.setconsts = setcast_BM (objgetattr_BM (_.recv, k_constants));
  _.bodyv = objgetattr_BM (_.recv, k_body);
  if (!isobject_BM (_.bodyv))
    {
      fprintf (stderr, "bad body minifunction %s\n", objectdbg1_BM (_.recv));
      LOCALRETURN_BM (NULL);
    }
  _.routprep = makeobj_BM ();
  objputclass_BM (_.routprep,
                  (objectval_tyBM *) k_simple_routine_preparation);
  objputattr_BM (_.routprep, k_in, _.recv);
  objputattr_BM (_.routprep, k_modgenob, _.modgen);
  DBGPRINTF_BM
    ("start prepare_routine°basiclo_minifunction recv=%s routprep=%s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprep));
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
  /// bind the arguments
  for (unsigned argix = 0; argix < nbargs; argix++)
    {
      _.curvar = tuplecompnth_BM (_.tupargs, argix);
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction argix=%u argum curvar=%s",
         argix, objectdbg_BM (_.curvar));
      _.oldrol = objassocgetattrpayl_BM (_.routprep, _.curvar);
      if (_.oldrol)
        {
          fprintf (stderr, "argument#%u %s is not fresh in minifunction %s\n",
                   argix, objectdbg_BM (_.curvar), objectdbg1_BM (_.recv));
          LOCALRETURN_BM (NULL);
        }
      _.curol = makenodevar_BM (k_arguments, taggedint_BM (argix), NULL);
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
        {
          fprintf (stderr, "closed#%u %s is not fresh in minifunction %s\n",
                   cloix, objectdbg_BM (_.curvar), objectdbg1_BM (_.recv));
          LOCALRETURN_BM (NULL);
        }
      _.curol = makenodevar_BM (k_closed, taggedint_BM (cloix), NULL);
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
          fprintf (stderr, "local#%u %s is not fresh in minifunction %s\n",
                   locix, objectdbg_BM (_.curvar), objectdbg1_BM (_.recv));
          LOCALRETURN_BM (NULL);
        }
      _.curol = makenodevar_BM (k_locals, taggedint_BM (locix), NULL);
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
          fprintf (stderr, "number#%u %s is not fresh in minifunction %s\n",
                   numix, objectdbg_BM (_.curvar), objectdbg1_BM (_.recv));
          LOCALRETURN_BM (NULL);
        }
      _.curol = makenodevar_BM (k_numbers, taggedint_BM (numix), NULL);
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
          fprintf (stderr, "constant#%u %s is not fresh in minifunction %s\n",
                   cstix, objectdbg_BM (_.curvar), objectdbg1_BM (_.recv));
          LOCALRETURN_BM (NULL);
        }
      _.curol = makenodevar_BM (k_constants, taggedint_BM (cstix), NULL);
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
    ("start prepare_routine°basiclo_minifunction before collect_blocks recv %s routprep %s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprep));
  _.collbl = send2_BM (_.bodyv, k_collect_blocks,
                       (struct stackframe_stBM *) &_,
                       _.routprep, taggedint_BM (0));
  if (!_.collbl)
    {
      fprintf (stderr,
               "collect_blocks failed for block %s in minifunction %s with routprep %s\n",
               objectdbg_BM (_.bodyv), objectdbg1_BM (_.recv),
               objectdbg2_BM (_.routprep));
      LOCALRETURN_BM (NULL);
    }
  DBGPRINTF_BM
    ("start prepare_routine°basiclo_minifunction after collect_blocks recv %s routprep %s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprep));
  LOCALRETURN_BM (_.routprep);
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
  enum
  {
    closix_nbvars,
    closix_nbargs,
    closix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * closv;
                 objectval_tyBM * recv; objectval_tyBM * routprep;
                 objectval_tyBM * curob; value_tyBM curexp; value_tyBM resv;
                 objectval_tyBM * typob;
    );
  LOCALGETFUNV_BM (_.closv);
  if (!isclosure_BM (_.closv) || closurewidth_BM (_.closv) != closix__LAST)
    LOCALRETURN_BM (NULL);
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
  DBGPRINTF_BM
    ("collect_blocks°basiclo_block _0gkYrIdnOg2_0wLEAh1QuYu start recv=%s routprep=%s depth=%d nbvar=%d nbargs=%d",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprep), depth, (int) nbargs,
     (int) nbvars);
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
        ("collect_blocks°basiclo_block varix#%d curob %s", varix,
         objectdbg_BM (_.curob));
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
      miniscan_var_BM (_.curob, _.routprep, depth, _.recv,
                       (struct stackframe_stBM *) &_);
    }
  for (int argix = 0; argix < nbargs; argix++)
    {
      _.curexp = (objgetcomp_BM (_.recv, argix + nbvars));
      DBGPRINTF_BM ("collect_blocks°basiclo_block argix#%d curexp %s",
                    argix,
                    debug_outstr_value_BM (_.curexp,
                                           (struct stackframe_stBM *) &_, 0));
      miniscan_expr_BM (_.curexp, _.routprep, depth, _.recv,
                        (struct stackframe_stBM *) &_);
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
                      (struct stackframe_stBM *) &_, _.routprep,
                      taggedint_BM (depth), _.recv);
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
                             (struct stackframe_stBM *) &_,
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
miniscan_var_BM (objectval_tyBM * varob,
                 objectval_tyBM * routprepob, int depth,
                 objectval_tyBM * fromob, struct stackframe_stBM *stkf)
{
  const objectval_tyBM *k_miniscan_var = BMK_6jh60mO0Cgd_84B0HiNphqA;
  int failin = -1;
#define FAILHERE() do { failin = __LINE__ ; goto failure; } while(0)
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ k_miniscan_var,
                 objectval_tyBM * varob; objectval_tyBM * routprepob;
                 objectval_tyBM * fromob; value_tyBM vrolv;
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
                debug_outstr_value_BM (_.vrolv,
                                       (struct stackframe_stBM *) &_, 0));
#warning incomplete miniscan_var_BM
  DBGPRINTF_BM ("miniscan_var end varob=%s", objectdbg_BM (_.varob));
  LOCALJUSTRETURN_BM ();
failure:
  _.errorv =
    makenodevar_BM (k_miniscan_var, varob, routprepob, taggedint_BM (depth),
                    fromob, NULL);
  FAILURE_BM (failin, _.errorv, (struct stackframe_stBM *) &_);
#undef FAILHERE
}                               /* end miniscan_var_BM */


objectval_tyBM *
miniscan_expr_BM (value_tyBM expv, objectval_tyBM * routprepob,
                  int depth, objectval_tyBM * fromob,
                  struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_miniscan_expr = BMK_7k3xb0vred0_9ZRHcZmhw77;
  objectval_tyBM *k_miniscan_node_conn = BMK_5EGLdtUAQxA_1nebCsDKqOF;
  int failin = -1;
#define FAILHERE() do { failin = __LINE__ ; goto failure; } while(0)
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ k_miniscan_expr,
                 value_tyBM expv; value_tyBM resv;
                 objectval_tyBM * routprepob; objectval_tyBM * fromob;
                 objectval_tyBM * expob; objectval_tyBM * connob;
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
                debug_outstr_value_BM (_.expv, (struct stackframe_stBM *) &_, 0),       //
                objectdbg1_BM (_.routprepob), depth,
                objectdbg2_BM (_.fromob));
  int ke = valtype_BM (_.expv);
  switch (ke)
    {
    case tyInt_BM:
    case tyNone_BM:
    case tyString_BM:
      break;
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
        DBGPRINTF_BM ("miniscan_expr expob=%s", objectdbg_BM (_.expob));
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
                           (struct stackframe_stBM *) &_,       //
                           _.routprepob,
                           taggedint_BM (depth), _.expv, _.fromob);
        DBGPRINTF_BM ("miniscan_expr miniscan_node_conn->%s done resv=%s",      //
                      objectdbg_BM (_.connob),  //
                      debug_outstr_value_BM (_.resv,
                                             (struct stackframe_stBM *) &_,
                                             0));
        if (!_.resv)
          FAILHERE ();
        break;
      }
    default:
      FAILHERE ();
    }
#warning incomplete miniscan_expr_BM
  DBGPRINTF_BM ("miniscan_expr end expv=%s",    //
                debug_outstr_value_BM (_.expv,
                                       (struct stackframe_stBM *) &_, 0));
  LOCALJUSTRETURN_BM ();
failure:
  DBGPRINTF_BM ("miniscan_expr failin %d", failin);
  _.errorv =
    makenodevar_BM (k_miniscan_expr, _.expv, _.routprepob,
                    taggedint_BM (depth), _.fromob, NULL);
  FAILURE_BM (failin, _.errorv, (struct stackframe_stBM *) &_);
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
                            (struct stackframe_stBM *) &_);
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
                              (struct stackframe_stBM *) &_, _.routprepob,
                              taggedint_BM (depth + 1), _.compob);
                  DBGPRINTF_BM
                    ("miniscan_stmt°basiclo_cond seqcompob after miniscan_block->%s resv=%s",
                     objectdbg_BM (_.seqcompob),
                     debug_outstr_value_BM (_.resv,
                                            (struct stackframe_stBM *) &_,
                                            0));
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
                              (struct stackframe_stBM *) &_, _.routprepob,
                              taggedint_BM (depth + 1), _.compob);
                  DBGPRINTF_BM
                    ("miniscan_stmt°basiclo_cond seqcompob after miniscan_stmt->%s resv=%s",
                     objectdbg_BM (_.seqcompob),
                     debug_outstr_value_BM (_.resv,
                                            (struct stackframe_stBM *) &_,
                                            0));
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
    ("miniscan_stmt°basiclo_cond unimplemented end recv=%s",
     objectdbg_BM (_.recv));
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
  miniscan_var_BM (_.destob, _.routprepob, depth + 1, _.recv,
                   (struct stackframe_stBM *) &_);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_assign after miniscan_var->%s",
     objectdbg_BM (_.destob));
  DBGPRINTF_BM ("miniscan_stmt°basiclo_assign recv=%s srcexpv=%s", objectdbg_BM (_.recv),      //
                debug_outstr_value_BM (_.srcexpv,
                                       (struct stackframe_stBM *) &_, 0));
  miniscan_expr_BM (_.srcexpv, _.routprepob, depth + 1, _.recv,
                    (struct stackframe_stBM *) &_);
  DBGPRINTF_BM ("miniscan_stmt°basiclo_assign after miniscan_expr->%s",
                debug_outstr_value_BM (_.srcexpv,
                                       (struct stackframe_stBM *) &_, 0));
  objunlock_BM (_.recv);
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
                 objectval_tyBM * connob; objectval_tyBM * routprepob;
                 value_tyBM expv; objectval_tyBM * fromob;
                 value_tyBM connargsv;
                 objectval_tyBM * connrestypob; value_tyBM resultv;
                 value_tyBM errorv;
                 value_tyBM cursonv;
                 objectval_tyBM * curargob; objectval_tyBM * curtypob;
                 value_tyBM extraerrorv;
    );
  int failin = -1;
#define FAILHERE(Xtra) do { failin = __LINE__ ; _.extraerrorv = (Xtra); goto failure; } while(0)
  objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  objectval_tyBM *k_result_type = BMK_8oZ9fPJGhmS_24c2sSYsdr2;
  objectval_tyBM *k_miniscan_node_conn = BMK_5EGLdtUAQxA_1nebCsDKqOF;
  objectval_tyBM *k_arity = BMK_6fPPUXnZhy5_8Lh5DOOe0Nu;
  _.connob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  int depth = getint_BM (arg3);
  _.expv = arg4;
  _.fromob = objectcast_BM (treenthson_BM (restargs, 0));
  DBGPRINTF_BM ("miniscan_node_conn°basiclo_primitive start connob %s" //
                "\n... routprepob %s depth %d expv %s fromob %s",       //
                objectdbg_BM (_.connob), objectdbg1_BM (_.routprepob), depth,   //
                debug_outstr_value_BM (_.expv, (struct stackframe_stBM *) &_, 0),       //
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
                debug_outstr_value_BM (_.connargsv, (struct stackframe_stBM *) &_, 0),  //
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
      DBGPRINTF_BM ("miniscan_node_conn°basiclo_primitive ix#%d cursonv=%s curargob=%s", ix,   //
                    debug_outstr_value_BM (_.cursonv, (struct stackframe_stBM *) &_, 0),        //
                    objectdbg_BM (_.curargob));
      _.curtypob =
        miniscan_expr_BM (_.cursonv, _.routprepob, depth + 1, _.fromob,
                          (struct stackframe_stBM *) &_);
      DBGPRINTF_BM ("miniscan_node_conn°basiclo_primitive ix#%d curtypob %s",
                    ix, objectdbg_BM (_.curtypob));
    }
#warning unimplemented _1vuSUudDrEr_9UjFr4Pcy8r routine
  WEAKASSERT_BM (false
                 && "unimplemented miniscan_node_conn°basiclo_primitive");
  LOCALRETURN_BM (_.resultv);
failure:
  DBGPRINTF_BM ("miniscan_node_conn°basiclo_primitive failin %d", failin);
  _.errorv =
    makenodevar_BM (k_miniscan_node_conn, _.expv, _.routprepob,
                    taggedint_BM (depth), _.fromob, _.extraerrorv, NULL);
  FAILURE_BM (failin, _.errorv, (struct stackframe_stBM *) &_);
#undef FAILHERE
}                               /* end miniscan_node_conn°basiclo_primitive  _1vuSUudDrEr_9UjFr4Pcy8r */
