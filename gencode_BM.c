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
    );
  assert (isclosure_BM ((const value_tyBM) clos));
  _.clos = clos;
  // retrieve arguments
  _.recv = /*function object */ (arg1);
#warning incomplete emit_c_type:c_opaque _6gRlN8loM4E_4pSsNmiCeIa
  DBGPRINTF_BM
    ("start  emit_c_type:c_opaque _6gRlN8loM4E_4pSsNmiCeIa recv=%s",
     objectdbg_BM (_.recv));
  return NULL;
}                               /* end emit_c_type:c_opaque _6gRlN8loM4E_4pSsNmiCeIa */
