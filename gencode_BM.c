// file gencode_BM.c
#include "bismon.h"


//// for the method prepare_routine:basiclo_function
extern objrout_sigBM ROUTINEOBJNAME_BM (_5mnsT1wsdWs_2Qnqsf3wqaP);

value_tyBM
ROUTINEOBJNAME_BM (_5mnsT1wsdWs_2Qnqsf3wqaP)    // prepare_routine:basiclo_function
(const closure_tyBM * clos,
 struct stackframe_stBM * stkf,
 const value_tyBM arg1,
 const value_tyBM arg2, const value_tyBM arg3,
 const quasinode_tyBM * restargs)
{
  enum
  {
    constix_arguments,
    constix_block,
    constix_locals,
    constix_constants,
    constix_simple_routine_preparation,
    constix_body,
    constix_bindings,
    constix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos; value_tyBM recv;
                 objectval_tyBM * modgenob;
                 value_tyBM args; value_tyBM curarg;
                 objectval_tyBM * routprepob; value_tyBM prepvalset;
                 anyassoc_tyBM * assocbind;
    );
  assert (isclosure_BM ((const value_tyBM) clos));
  _.clos = clos;
  const objectval_tyBM *closconn = closureconn_BM ((const value_tyBM) clos);
  assert (closconn != NULL);
  const node_tyBM *constnod = nodecast_BM (closconn->ob_data);
  /*** constnod is
      * const (arguments block locals constants simple_routine_preparation)
   ***/
  WEAKASSERT_BM (isnode_BM ((value_tyBM) constnod)
                 && valhash_BM ((value_tyBM) constnod) == 286038615
                 && nodewidth_BM ((value_tyBM) constnod) == constix__LAST);
  const objectval_tyBM *k_arguments =   //
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_arguments));
  const objectval_tyBM *k_block =       //
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_block));
  const objectval_tyBM *k_locals =      //
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_locals));
  const objectval_tyBM *k_constants =   //
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_constants));
  const objectval_tyBM *k_simple_routine_preparation =  //
    objectcast_BM (nodenthson_BM ((const value_tyBM) constnod,
                                  constix_simple_routine_preparation));
  const objectval_tyBM *k_body =        //
    objectcast_BM (nodenthson_BM ((const value_tyBM) constnod,
                                  constix_body));
  const objectval_tyBM *k_bindings =    //
    objectcast_BM (nodenthson_BM ((const value_tyBM) constnod,
                                  constix_bindings));
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
  _.assocbind = make_assoc_BM (10);
  /// run _2hJWe55ydpv_5kaGdOUymFI:
  objputattr_BM (_.routprepob, k_bindings, _.assocbind);
  /// assign _9YS82HkgghD_71BLsDAKRfg
  _.args = objgetattr_BM (_.recv, k_arguments);
  /// foreach_in_tuple(args curarg curargix args ...) _0UqUZ7mQGG5_69QlCmcSwTi
  unsigned nbargs = tuplesize_BM (_.args);
  for (unsigned curargix = 0; curargix < nbargs; curargix++)
    {
      _.curarg = tuplecompnth_BM (_.args, curargix);
      if (assoc_getattr_BM (_.assocbind, _.curarg))
        {
        }
    }
#warning incomplete  prepare_routine:basiclo_function _5mnsT1wsdWs_2Qnqsf3wqaP
  return NULL;
}                               /* end  prepare_routine:basiclo_function _5mnsT1wsdWs_2Qnqsf3wqaP */



//// for the method emit_c_type:c_opaque
extern objrout_sigBM ROUTINEOBJNAME_BM (_6gRlN8loM4E_4pSsNmiCeIa);

value_tyBM
ROUTINEOBJNAME_BM (_6gRlN8loM4E_4pSsNmiCeIa)    // emit_c_type:c_opaque
(const closure_tyBM * clos,
 struct stackframe_stBM * stkf,
 const value_tyBM arg1,
 const value_tyBM arg2, const value_tyBM arg3,
 const quasinode_tyBM * restargs)
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos; value_tyBM recv;
                 struct strbuffer_stBM *prsbuf;
    );
  assert (isclosure_BM ((const value_tyBM) clos));
  _.clos = clos;
  // retrieve arguments
  _.recv = /*ctype */ (arg1);
  WEAKASSERT_BM (isobject_BM (_.recv));
  _.prsbuf = strbuffercast_BM (arg2);
  WEAKASSERT_BM (_.prsbuf != NULL);
  DBGPRINTF_BM
    ("start  emit_c_type:c_opaque _6gRlN8loM4E_4pSsNmiCeIa recv=%s",
     objectdbg_BM (_.recv));
  const char *nam = findobjectname_BM (_.recv);
  char idbuf[32] = { };
  idtocbuf32_BM (objid_BM (_.recv), idbuf);
  if (nam)
    {
      strbufferprintf_BM (_.prsbuf, "\n// opaque named type\n");
      strbufferprintf_BM (_.prsbuf, "typedef void* %s_TyBM;\n", nam);
      strbufferprintf_BM (_.prsbuf, "#define %s_TyBM %s_TyBM\n", idbuf, nam);
    }
  else
    {
      strbufferprintf_BM (_.prsbuf, "\n// opaque anonymous type\n");
      strbufferprintf_BM (_.prsbuf, "typedef void* %s_TyBM;\n", idbuf);
    }
  return _.recv;
}                               /* end emit_c_type:c_opaque _6gRlN8loM4E_4pSsNmiCeIa */




//// for the method emit_c_type:c_enum
extern objrout_sigBM ROUTINEOBJNAME_BM (_979hCujWp2g_9tjRbM8Ht1l);

value_tyBM
ROUTINEOBJNAME_BM (_979hCujWp2g_9tjRbM8Ht1l)    // emit_c_type:c_enum
(const closure_tyBM * clos,
 struct stackframe_stBM * stkf,
 const value_tyBM arg1,
 const value_tyBM arg2, const value_tyBM arg3,
 const quasinode_tyBM * restargs)
{
  enum
  {
    constix_extending,
    constix_own_enumeration,
    constix_enumeration,
    constix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos;
                 value_tyBM recv;
                 struct strbuffer_stBM *prsbuf;
                 const objectval_tyBM * extendingob;
                 const tupleval_tyBM * ownenumtup;
    );
  assert (isclosure_BM ((const value_tyBM) clos));
  _.clos = clos;
  // retrieve arguments
  _.recv = /*ctype */ (arg1);
  WEAKASSERT_BM (isobject_BM (_.recv));
  _.prsbuf = strbuffercast_BM (arg2);
  WEAKASSERT_BM (_.prsbuf != NULL);
  DBGPRINTF_BM
    ("start emit_c_type:c_enum _979hCujWp2g_9tjRbM8Ht1l recv=%s",
     objectdbg_BM (_.recv));
  const objectval_tyBM *closconn = closureconn_BM ((const value_tyBM) clos);
  assert (closconn != NULL);
  const node_tyBM *constnod = nodecast_BM (closconn->ob_data);
  /*** constnod is
      * const (extending own_enumeration enumeration)
   ***/
  WEAKASSERT_BM (isnode_BM ((value_tyBM) constnod)
                 && valhash_BM ((value_tyBM) constnod) == 1519557249
                 && nodewidth_BM ((value_tyBM) constnod) == constix__LAST);
  const objectval_tyBM *k_extending =   //
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_extending));
  const objectval_tyBM *k_own_enumeration =     //
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_own_enumeration));
  const objectval_tyBM *k_enumeration = //
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_enumeration));
  //
  const char *nam = findobjectname_BM (_.recv);
  char idbuf[32] = { };
  idtocbuf32_BM (objid_BM (_.recv), idbuf);
  _.extendingob = objectcast_BM (objgetattr_BM (_.recv, k_extending));
  _.ownenumtup = tuplecast_BM (objgetattr_BM (_.recv, k_own_enumeration));
#warning emit_c_type:c_enum _979hCujWp2g_9tjRbM8Ht1l unimplemented
  return NULL;
}                               /* end emit_c_type:c_enum _979hCujWp2g_9tjRbM8Ht1l  */


////////////////

//// for the method prepare_routine°basiclo_minifunction
extern objrout_sigBM ROUTINEOBJNAME_BM (_07qYMXftJRR_9dde2ASz4e9);

value_tyBM
ROUTINEOBJNAME_BM (_07qYMXftJRR_9dde2ASz4e9)    //  prepare_routine°basiclo_minifunction
(const closure_tyBM * clos,
 struct stackframe_stBM * stkf,
 const value_tyBM arg1,
 const value_tyBM arg2, const value_tyBM arg3,
 const quasinode_tyBM * restargs)
{
  enum
  {
    constix_arguments,
    constix_constants,
    constix_result,
    constix_closed,
    constix_locals,
    constix_numbers,
    constix_body,
    constix_simple_routine_preparation,
    constix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos;
                 objectval_tyBM * modgen;
                 setval_tyBM * prepvalset;
                 objectval_tyBM * curprepob;
                 objectval_tyBM * routprep;
                 value_tyBM recv;
                 anyassoc_tyBM * routassoc;
                 const tupleval_tyBM * tupargs;
                 const tupleval_tyBM * tupclosed;
                 objectval_tyBM * obresult;
                 const setval_tyBM * setlocals;
                 const setval_tyBM * setnumbers;
                 const setval_tyBM * setconsts;
                 objectval_tyBM * curvar; value_tyBM curol;
                 value_tyBM oldrol;
                 value_tyBM bodyv;
    );
  assert (isclosure_BM ((const value_tyBM) clos));
  _.clos = clos;
  const objectval_tyBM *closconn = closureconn_BM ((const value_tyBM) clos);
  assert (closconn != NULL);
  const node_tyBM *constnod = nodecast_BM (closconn->ob_data);
  /*** constnod is
      * const (arguments result constants closed locals numbers 
               body simple_routine_preparation)
   ***/
  WEAKASSERT_BM (isnode_BM ((value_tyBM) constnod)
                 && valhash_BM ((value_tyBM) constnod) == 2487156868
                 && nodewidth_BM ((value_tyBM) constnod) == constix__LAST);
  const objectval_tyBM *k_arguments =   //
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_arguments));
  const objectval_tyBM *k_constants =   //
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_constants));
  const objectval_tyBM *k_result =      //
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_result));
  const objectval_tyBM *k_closed =      //
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_closed));
  const objectval_tyBM *k_locals =      //
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_locals));
  const objectval_tyBM *k_numbers =     //
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_numbers));
  const objectval_tyBM *k_body =        //
    objectcast_BM (nodenthson_BM ((const value_tyBM) constnod, constix_body));
  const objectval_tyBM *k_simple_routine_preparation =  //
    objectcast_BM (nodenthson_BM ((const value_tyBM) constnod,
                                  constix_simple_routine_preparation));
  // retrieve arguments
  _.recv = (arg1);
  WEAKASSERT_BM (isobject_BM (_.recv));
  _.modgen = objectcast_BM (arg2);
  _.prepvalset = setcast_BM (arg3);     /// unneeded, set of all routines
  WEAKASSERT_BM (_.modgen != NULL);
  WEAKASSERT_BM (_.prepvalset != NULL);
  unsigned nbprep = setcardinal_BM (_.prepvalset);
  DBGPRINTF_BM
    ("start prepare_routine°basiclo_minifunction _07qYMXftJRR_9dde2ASz4e9 recv=%s modgen=%s nbprep=%u",
     objectdbg_BM (_.recv), objectdbg1_BM (_.modgen), nbprep);
  _.tupargs = tuplecast_BM (objgetattr_BM (_.recv, k_arguments));
  _.tupclosed = tuplecast_BM (objgetattr_BM (_.recv, k_closed));
  _.obresult = objectcast_BM (objgetattr_BM (_.recv, k_result));
  _.setlocals = setcast_BM (objgetattr_BM (_.recv, k_locals));
  _.setnumbers = setcast_BM (objgetattr_BM (_.recv, k_numbers));
  _.setconsts = setcast_BM (objgetattr_BM (_.recv, k_constants));
  _.bodyv = objgetattr_BM (_.recv, k_body);
  if (!isobject_BM (_.bodyv) && !istuple_BM (_.bodyv))
    {
      fprintf (stderr, "bad body minifunction %s\n", objectdbg1_BM (_.recv));
      return NULL;
    }
  _.routprep = makeobj_BM ();
  objputclass_BM (_.routprep, k_simple_routine_preparation);
  unsigned nbargs = tuplesize_BM (_.tupargs);
  unsigned nbclosed = tuplesize_BM (_.tupclosed);
  unsigned nblocals = setcardinal_BM (_.setlocals);
  unsigned nbnumbers = setcardinal_BM (_.setnumbers);
  unsigned nbconsts = setcardinal_BM (_.setconsts);
  DBGPRINTF_BM
    ("start prepare_routine°basiclo_minifunction recv %s nbargs=%u nbclosed=%u nblocals=%u nbnumbers=%u nbconsts=%u",
     objectdbg_BM (_.recv), nbargs, nbclosed, nblocals, nbnumbers, nbconsts);
  _.routassoc =
    make_assoc_BM (2 + nbargs + nbclosed + nblocals + nbnumbers + nbconsts);
  /// bind the arguments
  for (unsigned argix = 0; argix < nbargs; argix++)
    {
      _.curvar = tuplecompnth_BM (_.tupargs, argix);
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction argix=%u argum curvar=%s",
         argix, objectdbg_BM (_.curvar));
      _.oldrol = assoc_getattr_BM (_.routassoc, _.curvar);
      if (_.oldrol)
        {
          fprintf (stderr, "argument#%u %s is not fresh in minifunction %s\n",
                   argix, objectdbg_BM (_.curvar), objectdbg1_BM (_.recv));
          return NULL;
        }
      _.curol = makenodevar_BM (k_arguments, taggedint_BM (argix), NULL);
      _.routassoc = assoc_addattr_BM (_.routassoc, _.curvar, _.curol);
      _.curol = NULL;
    }
  /// bind the closed
  for (unsigned cloix = 0; cloix < nbclosed; cloix++)
    {
      _.curvar = tuplecompnth_BM (_.tupclosed, cloix);
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction cloix=%u closed curvar=%s",
         cloix, objectdbg_BM (_.curvar));
      _.oldrol = assoc_getattr_BM (_.routassoc, _.curvar);
      if (_.oldrol)
        {
          fprintf (stderr, "closed#%u %s is not fresh in minifunction %s\n",
                   cloix, objectdbg_BM (_.curvar), objectdbg1_BM (_.recv));
          return NULL;
        }
      _.curol = makenodevar_BM (k_closed, taggedint_BM (cloix), NULL);
      _.routassoc = assoc_addattr_BM (_.routassoc, _.curvar, _.curol);
      _.curol = NULL;
    }
  /// bind the locals
  for (unsigned locix = 0; locix < nblocals; locix++)
    {
      _.curvar = setelemnth_BM (_.setlocals, locix);
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction locix=%u local curvar=%s",
         locix, objectdbg_BM (_.curvar));
      _.oldrol = assoc_getattr_BM (_.routassoc, _.curvar);
      if (_.oldrol)
        {
          fprintf (stderr, "local#%u %s is not fresh in minifunction %s\n",
                   locix, objectdbg_BM (_.curvar), objectdbg1_BM (_.recv));
          return NULL;
        }
      _.curol = makenodevar_BM (k_locals, taggedint_BM (locix), NULL);
      _.routassoc = assoc_addattr_BM (_.routassoc, _.curvar, _.curol);
      _.curol = NULL;
    }
  // bind the numbers
  for (unsigned numix = 0; numix < nbnumbers; numix++)
    {
      _.curvar = setelemnth_BM (_.setnumbers, numix);
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction numix=%u number curvar=%s",
         numix, objectdbg_BM (_.curvar));
      _.oldrol = assoc_getattr_BM (_.routassoc, _.curvar);
      if (_.oldrol)
        {
          fprintf (stderr, "number#%u %s is not fresh in minifunction %s\n",
                   numix, objectdbg_BM (_.curvar), objectdbg1_BM (_.recv));
          return NULL;
        }
      _.curol = makenodevar_BM (k_numbers, taggedint_BM (numix), NULL);
      _.routassoc = assoc_addattr_BM (_.routassoc, _.curvar, _.curol);
      _.curol = NULL;
    }
  // bind the constants
  for (unsigned constix = 0; constix < nbconsts; constix++)
    {
      _.curvar = setelemnth_BM (_.setconsts, constix);
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction constix=%u constant curvar=%s",
         constix, objectdbg_BM (_.curvar));
      _.oldrol = assoc_getattr_BM (_.routassoc, _.curvar);
      if (_.oldrol)
        {
          fprintf (stderr, "constant#%u %s is not fresh in minifunction %s\n",
                   constix, objectdbg_BM (_.curvar), objectdbg1_BM (_.recv));
          return NULL;
        }
      _.curol = makenodevar_BM (k_constants, taggedint_BM (constix), NULL);
      _.routassoc = assoc_addattr_BM (_.routassoc, _.curvar, _.curol);
      _.curol = NULL;
    }
  _.routprep->ob_data = _.routassoc;
  DBGPRINTF_BM
    ("start prepare_routine°basiclo_minifunction done recv %s routprep %s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprep));
  return _.routprep;
}                               /* end prepare_routine°basiclo_minifunction  _07qYMXftJRR_9dde2ASz4e9  */



// for the method to complete_module in basiclo_temporary_module &
// basiclo_dumpable_module

extern objrout_sigBM ROUTINEOBJNAME_BM (_10XOFm9ui6R_06F8qZQynnA);
value_tyBM
ROUTINEOBJNAME_BM (_10XOFm9ui6R_06F8qZQynnA)    //
(const closure_tyBM * clos, struct stackframe_stBM * stkf,      //
 const value_tyBM arg1,         // recieving module
 const value_tyBM arg2,         // module generator
 const value_tyBM arg3,         // preparation
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  enum
  {
    constix_functions_set,
    constix_plain_module,
    constix_basiclo_minifunction,
    constix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos; value_tyBM recv;
                 value_tyBM modgen;
                 value_tyBM funset; objectval_tyBM * plainmod;
                 objectval_tyBM * curfun;
    );
  assert (isclosure_BM ((const value_tyBM) clos));
  _.clos = clos;
  const objectval_tyBM *closconn = closureconn_BM ((const value_tyBM) clos);
  assert (closconn != NULL);
  // retrieve arguments
  _.recv = (arg1);
  WEAKASSERT_BM (isobject_BM (_.recv));
  _.modgen = (arg2);
  WEAKASSERT_BM (isobject_BM (_.modgen));
  const node_tyBM *constnod = nodecast_BM (closconn->ob_data);
  /*** constnod is
      * const (functions_set plain_module basiclo_minifunction)
   ***/
  WEAKASSERT_BM (isnode_BM ((value_tyBM) constnod)
                 && valhash_BM ((value_tyBM) constnod) == 2107755858
                 && nodewidth_BM ((value_tyBM) constnod) == constix__LAST);
  const objectval_tyBM *k_functions_set =       //
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_functions_set));
  const objectval_tyBM *k_plain_module =        //
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_plain_module));
  const objectval_tyBM *k_basiclo_minifunction =        //
    objectcast_BM (nodenthson_BM ((const value_tyBM) constnod,
                                  constix_basiclo_minifunction));
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
      return _.funset;
    }
  DBGPRINTF_BM
    ("complete_module°basiclo*module nbtinyfuns=%u < nbfuns=%u incomplete",
     nbtinyfuns, nbfuns);
#warning complete_module°basiclo*module unimplemented
  return NULL;
}                               /* end complete_module°basiclo*module _10XOFm9ui6R_06F8qZQynnA  */
