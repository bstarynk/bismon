// generated persistent module sometests_module
// in file modbm_8oL3Mr0lJtL_5DdSEr80iHP.c -- DONT EDIT
// this generated code is GPLv3+ licensed.


#include "bismon.h"

#ifdef BISMON_MODID
DECLARE_MODULE_BM(_8oL3Mr0lJtL_5DdSEr80iHP);
extern moduleinit_sigBM moduleinit_8oL3Mr0lJtL_5DdSEr80iHP_BM;
#endif /*BISMON_MODID*/

#ifdef BISMON_MOMD5
const char modulmd5chksum_8oL3Mr0lJtL_5DdSEr80iHP_BM[] = BISMON_MOMD5;
#endif /*BISMON_MOMD5*/



// declare 2 routines

extern const char *const routid_8oL3Mr0lJtL_5DdSEr80iHP_BM[2+1];


// no failure

extern objrout_sigBM crout_24HgO9VzdQK_5jmxGYUgdi4_BM; //#0 !rest-test-jsonextract-httphandler (v_restpath o_webex)

extern objrout_sigBM crout_63V5uVLvCcf_1VxMlB8V538_BM; //#1 init_testjsonextract


// declare 3 constants
objectval_tyBM* constob_8oL3Mr0lJtL_5DdSEr80iHP_BM[3+1];
const char* const constid_8oL3Mr0lJtL_5DdSEr80iHP_BM[3+1];


// define 2 routines


value_tyBM crout_24HgO9VzdQK_5jmxGYUgdi4_BM //#0
 (struct stackframe_stBM* stkf, //
//!rest-test-jsonextract-httphandler (v_restpath o_webex)
  // 2 arguments
  const value_tyBM arg0,  // v_restpath
  const value_tyBM arg1,  // o_webex
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _24HgO9VzdQK_5jmxGYUgdi4
  struct frame_24HgO9VzdQK_5jmxGYUgdi4_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 3 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_5JuT4FgNFFh_7McrTYeT3jx; // o_webex
    value_tyBM v_6QhNRfe1Cte_0niVlWfAlmO; // v_restpath
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_24HgO9VzdQK_5jmxGYUgdi4_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 3;
   _.stkfram_descr = constob_8oL3Mr0lJtL_5DdSEr80iHP_BM[0] /*|_24HgO9VzdQK_5jmxGYUgdi4*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 2 arguments:
   _.v_6QhNRfe1Cte_0niVlWfAlmO = arg0; // v_restpath
   _.o_5JuT4FgNFFh_7McrTYeT3jx = objectcast_BM (arg1); // o_webex
   // fetched 2 arguments.
   // no closed values in _24HgO9VzdQK_5jmxGYUgdi4.
   const closure_tyBM* callclos_24HgO9VzdQK_5jmxGYUgdi4 __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_24HgO9VzdQK_5jmxGYUgdi4  __attribute__((unused)) = 0;
   // routine _24HgO9VzdQK_5jmxGYUgdi4 body:

startblock__6ZnPB3sdFWL_6hMysLssv5h: __attribute__((unused));
{ /* +block _6ZnPB3sdFWL_6hMysLssv5h */ 
 
{ // run _0hLP6ssXFIv_2rHw8yK5GMR 
/*debug start rest-test-jsonextract-httphandler v_restpath o_webex*/
DBGPRINTF_BM("start rest-test-jsonextract-httphandler €%.9s v_restpath=%s o_webex=%s",
 "_0hLP6ssXFIv_2rHw8yK5GMR", 
 OUTSTRVALUE_BM( /*v_restpath:*/_.v_6QhNRfe1Cte_0niVlWfAlmO),
 objectdbg_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx));
; 
} // end run _0hLP6ssXFIv_2rHw8yK5GMR 
 
/* !endingblock _6ZnPB3sdFWL_6hMysLssv5h */ 
goto endblock__6ZnPB3sdFWL_6hMysLssv5h; 
endblock__6ZnPB3sdFWL_6hMysLssv5h: ; 
} /*-block _6ZnPB3sdFWL_6hMysLssv5h */

 epilog_24HgO9VzdQK_5jmxGYUgdi4: __attribute__ ((unused)); // routine _24HgO9VzdQK_5jmxGYUgdi4 epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _24HgO9VzdQK_5jmxGYUgdi4 routine#0 _24HgO9VzdQK_5jmxGYUgdi4




value_tyBM crout_63V5uVLvCcf_1VxMlB8V538_BM //#1+
 (struct stackframe_stBM* stkf, // init_testjsonextract
//!init routine for testing json extraction, see misc/test-jsonextract.sh script
  // 0 arguments
  const value_tyBM arg0_ __attribute__((unused)),
  const value_tyBM arg1_ __attribute__((unused)),
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of init_testjsonextract
  struct frame_63V5uVLvCcf_1VxMlB8V538_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 3 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    value_tyBM v_5GhvzWWP1jl_41tgAIAAa2X; // v_resapp
    objectval_tyBM* o_6Z4UU939WbU_8BK9xcKsXNb; // o_comp
    /// 1 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
   } _;
   memset (&_, 0, sizeof(struct frame_63V5uVLvCcf_1VxMlB8V538_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 3;
   _.stkfram_descr = constob_8oL3Mr0lJtL_5DdSEr80iHP_BM[1] /*|init_testjsonextract*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 0 arguments:
   // fetched 0 arguments.
   // no closed values in init_testjsonextract.
   const closure_tyBM* callclos_63V5uVLvCcf_1VxMlB8V538 __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_63V5uVLvCcf_1VxMlB8V538  __attribute__((unused)) = 0;
   // routine _63V5uVLvCcf_1VxMlB8V538 body:

startblock__8tAj8saPk7W_72rBxTK7KXk: __attribute__((unused));
{ /* +block _8tAj8saPk7W_72rBxTK7KXk */ 
 
{ // run _5aVIbUZVVtV_4m1UhgUJaXs 
/*infoprint start init_testjsonextract*/
INFOPRINTF_BM("start init_testjsonextract €%.9s",
"_5aVIbUZVVtV_4m1UhgUJaXs");
; 
} // end run _5aVIbUZVVtV_4m1UhgUJaXs 
 
 
 
startblock__8l3UBEKzzDl_7qN30RQrNd3: __attribute__((unused)); 
{ /* +block _8l3UBEKzzDl_7qN30RQrNd3 *//* !endingblock _8l3UBEKzzDl_7qN30RQrNd3 */  
goto endblock__8l3UBEKzzDl_7qN30RQrNd3;  
endblock__8l3UBEKzzDl_7qN30RQrNd3: ;  
} /*-block _8l3UBEKzzDl_7qN30RQrNd3 */ 
//+ #2/4 of block _8tAj8saPk7W_72rBxTK7KXk :: 
 
 
{ // run _89cUQMyOk6x_3BktMXXI88t 
/*debug end init_testjsonextract*/
DBGPRINTF_BM("end init_testjsonextract €%.9s",
 "_89cUQMyOk6x_3BktMXXI88t");
; 
} // end run _89cUQMyOk6x_3BktMXXI88t 
 
 
/*return _8vAq3sHvz0Y_2k0khg31ZkV:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 (constob_8oL3Mr0lJtL_5DdSEr80iHP_BM[1] /*!init_testjsonextract*/); 
 goto epilog_63V5uVLvCcf_1VxMlB8V538; 
 
/* !endingblock _8tAj8saPk7W_72rBxTK7KXk */ 
goto endblock__8tAj8saPk7W_72rBxTK7KXk; 
endblock__8tAj8saPk7W_72rBxTK7KXk: ; 
} /*-block _8tAj8saPk7W_72rBxTK7KXk */

 epilog_63V5uVLvCcf_1VxMlB8V538: __attribute__ ((unused)); // routine _63V5uVLvCcf_1VxMlB8V538 epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _63V5uVLvCcf_1VxMlB8V538 routine#1 init_testjsonextract




// end of 2 generated routines


// the constant ids for 3 constants:
const char* const constid_8oL3Mr0lJtL_5DdSEr80iHP_BM[3+1] = {
 /*0:*/
 "_24HgO9VzdQK_5jmxGYUgdi4", //! rest-test-jsonextract-httphandler (v_restpath o_webex)
 "_63V5uVLvCcf_1VxMlB8V538",//init_testjsonextract
 "_8oL3Mr0lJtL_5DdSEr80iHP",//sometests_module
 NULL}; // end 3 constant ids



// the routine ids for 2 routines:
const char* const routid_8oL3Mr0lJtL_5DdSEr80iHP_BM[2+1] = {
  /*0:*/
  "_24HgO9VzdQK_5jmxGYUgdi4", //!rest-test-jsonextract-httphandler (v_restpath o_webex)
  "_63V5uVLvCcf_1VxMlB8V538",//init_testjsonextract

 NULL}; // end 2 routine ids



// basiclo*module initialization
#ifdef BISMON_MODID
value_tyBM moduleinit_8oL3Mr0lJtL_5DdSEr80iHP_BM
  (struct stackframe_stBM *stkf, //
   const value_tyBM arg1, //
   const value_tyBM arg2, //
   const value_tyBM arg3, //
   void* dlh) {
  return simple_module_initialize_BM(arg1, arg2, arg3, //
        "_8oL3Mr0lJtL_5DdSEr80iHP",//
       constob_8oL3Mr0lJtL_5DdSEr80iHP_BM, //
       constid_8oL3Mr0lJtL_5DdSEr80iHP_BM, //
       routid_8oL3Mr0lJtL_5DdSEr80iHP_BM, //
       dlh, stkf);
} // end moduleinit_8oL3Mr0lJtL_5DdSEr80iHP_BM
#endif /*BISMON_MODID*/



/************
 ** for Emacs:
 ** Local Variables: ;;
 ** compile-command: "make -k -j -C .. modules" ;;
 ** End: ;;
 ************/



// end of generated persistent module sometests_module in file modbm_8oL3Mr0lJtL_5DdSEr80iHP.c
