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
    constix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos;
                 value_tyBM recv;
    );
  assert (isclosure_BM ((const value_tyBM) clos));
  _.clos = clos;
  const objectval_tyBM *closconn = closureconn_BM ((const value_tyBM) clos);
  assert (closconn != NULL);
  // retrieve arguments
  _.recv = (arg1);
  WEAKASSERT_BM (isobject_BM (_.recv));
  DBGPRINTF_BM
    ("start prepare_routine°basiclo_minifunction _07qYMXftJRR_9dde2ASz4e9 recv=%s",
     objectdbg_BM (_.recv));
#warning prepare_routine°basiclo_minifunction unimplemented
  return NULL;
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
    constix__LAST
  };
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 const closure_tyBM * clos;
                 value_tyBM recv; value_tyBM modgen; value_tyBM funset;
                 objectval_tyBM * plainmod;
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
      * const (functions_set plain_module)
   ***/
  WEAKASSERT_BM (isnode_BM ((value_tyBM) constnod)
                 && valhash_BM ((value_tyBM) constnod) == 2163271555
                 && nodewidth_BM ((value_tyBM) constnod) == constix__LAST);
  const objectval_tyBM *k_functions_set =       //
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_functions_set));
  const objectval_tyBM *k_plain_module =        //
    objectcast_BM (nodenthson_BM
                   ((const value_tyBM) constnod, constix_plain_module));
  DBGPRINTF_BM
    ("complete_module°basiclo*module start recv=%s modgen=%s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.modgen));
  _.funset = setcast_BM (objgetattr_BM (_.modgen, k_functions_set));
  unsigned nbfuns = setcardinal_BM (_.funset);
  _.plainmod = objectcast_BM (objgetattr_BM (_.modgen, k_plain_module));
  DBGPRINTF_BM
    ("complete_module°basiclo*module nbfuns=%u plainmod=%s",
     nbfuns, objectdbg_BM (_.plainmod));
#warning complete_module°basiclo*module unimplemented
  return NULL;
}                               /* end complete_module°basiclo*module _10XOFm9ui6R_06F8qZQynnA  */
