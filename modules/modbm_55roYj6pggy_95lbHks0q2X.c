// generated persistent module chariotdemo_module
// in file modbm_55roYj6pggy_95lbHks0q2X.c -- DONT EDIT
// this generated code is GPLv3+ licensed.


#include "bismon.h"

#ifdef BISMON_MODID
DECLARE_MODULE_BM(_55roYj6pggy_95lbHks0q2X);
extern moduleinit_sigBM moduleinit_55roYj6pggy_95lbHks0q2X_BM;
#endif /*BISMON_MODID*/

#ifdef BISMON_MOMD5
const char modulmd5chksum_55roYj6pggy_95lbHks0q2X_BM[] = BISMON_MOMD5;
#endif /*BISMON_MOMD5*/



// declare 1 routines

extern const char *const routid_55roYj6pggy_95lbHks0q2X_BM[1+1];


// no failure

extern objrout_sigBM crout_0oA6AajbKuk_8rDrkR7F4jZ_BM; //#0 init_chariotdemo


// declare 2 constants
objectval_tyBM* constob_55roYj6pggy_95lbHks0q2X_BM[2+1];
const char* const constid_55roYj6pggy_95lbHks0q2X_BM[2+1];


// define 1 routines


value_tyBM crout_0oA6AajbKuk_8rDrkR7F4jZ_BM //#0+
 (struct stackframe_stBM* stkf, // init_chariotdemo
//!init routine for CHARIOT demo
  // 0 arguments
  const value_tyBM arg0_ __attribute__((unused)),
  const value_tyBM arg1_ __attribute__((unused)),
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of init_chariotdemo
  struct frame_0oA6AajbKuk_8rDrkR7F4jZ_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 2 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_6Z4UU939WbU_8BK9xcKsXNb; // o_comp
    /// 1 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
   } _;
   memset (&_, 0, sizeof(struct frame_0oA6AajbKuk_8rDrkR7F4jZ_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 2;
   _.stkfram_descr = constob_55roYj6pggy_95lbHks0q2X_BM[0] /*|init_chariotdemo*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 0 arguments:
   // fetched 0 arguments.
   // no closed values in init_chariotdemo.
   const closure_tyBM* callclos_0oA6AajbKuk_8rDrkR7F4jZ __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_0oA6AajbKuk_8rDrkR7F4jZ  __attribute__((unused)) = 0;
   // routine _0oA6AajbKuk_8rDrkR7F4jZ body:

startblock__2KLVzxCNqMd_2qnmhKI8PhM: __attribute__((unused));
{ /* +block _2KLVzxCNqMd_2qnmhKI8PhM */ 
 
{ // run _38RZobUaaQ3_2WZL2X2Cmx3 
/*inform init_chariotdemo start*/
DBGPRINTF_BM("initchariot_demo start €%.9s (in €_2KLVzxC)",
 "_38RZobUaaQ3_2WZL2X2Cmx3");
INFOPRINTF_BM("initchariot_demo starting €%.8s...", "_38RZobUaaQ3_2WZL2X2Cmx3");
; 
} // end run _38RZobUaaQ3_2WZL2X2Cmx3 
 
/* !endingblock _2KLVzxCNqMd_2qnmhKI8PhM */ 
goto endblock__2KLVzxCNqMd_2qnmhKI8PhM; 
endblock__2KLVzxCNqMd_2qnmhKI8PhM: ; 
} /*-block _2KLVzxCNqMd_2qnmhKI8PhM */

 epilog_0oA6AajbKuk_8rDrkR7F4jZ: __attribute__ ((unused)); // routine _0oA6AajbKuk_8rDrkR7F4jZ epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _0oA6AajbKuk_8rDrkR7F4jZ routine#0 init_chariotdemo




// end of 1 generated routines


// the constant ids for 2 constants:
const char* const constid_55roYj6pggy_95lbHks0q2X_BM[2+1] = {
 /*0:*/
 "_0oA6AajbKuk_8rDrkR7F4jZ",//init_chariotdemo
 "_55roYj6pggy_95lbHks0q2X",//chariotdemo_module
 NULL}; // end 2 constant ids



// the routine ids for 1 routines:
const char* const routid_55roYj6pggy_95lbHks0q2X_BM[1+1] = {
  /*0:*/
  "_0oA6AajbKuk_8rDrkR7F4jZ",//init_chariotdemo

 NULL}; // end 1 routine ids



// basiclo*module initialization
#ifdef BISMON_MODID
value_tyBM moduleinit_55roYj6pggy_95lbHks0q2X_BM
  (struct stackframe_stBM *stkf, //
   const value_tyBM arg1, //
   const value_tyBM arg2, //
   const value_tyBM arg3, //
   void* dlh) {
  return simple_module_initialize_BM(arg1, arg2, arg3, //
        "_55roYj6pggy_95lbHks0q2X",//
       constob_55roYj6pggy_95lbHks0q2X_BM, //
       constid_55roYj6pggy_95lbHks0q2X_BM, //
       routid_55roYj6pggy_95lbHks0q2X_BM, //
       dlh, stkf);
} // end moduleinit_55roYj6pggy_95lbHks0q2X_BM
#endif /*BISMON_MODID*/



/************
 ** for Emacs:
 ** Local Variables: ;;
 ** compile-command: "make -k -j -C .. modules" ;;
 ** End: ;;
 ************/



// end of generated persistent module chariotdemo_module in file modbm_55roYj6pggy_95lbHks0q2X.c
