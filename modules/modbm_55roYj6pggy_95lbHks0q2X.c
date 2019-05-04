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



// declare 2 routines

extern const char *const routid_55roYj6pggy_95lbHks0q2X_BM[2+1];


// no failure

extern objrout_sigBM crout_0oA6AajbKuk_8rDrkR7F4jZ_BM; //#0 init_chariotdemo

extern objrout_sigBM crout_5603DuLsw8z_4ztK4e4aYMp_BM; //#1 !restchariot2q19-httphandler (v_restpath o_webex)


// declare 3 constants
objectval_tyBM* constob_55roYj6pggy_95lbHks0q2X_BM[3+1];
const char* const constid_55roYj6pggy_95lbHks0q2X_BM[3+1];


// define 2 routines


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




value_tyBM crout_5603DuLsw8z_4ztK4e4aYMp_BM //#1
 (struct stackframe_stBM* stkf, //
//!restchariot2q19-httphandler (v_restpath o_webex)
  // 2 arguments
  const value_tyBM arg0,  // v_restpath
  const value_tyBM arg1,  // o_webex
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _5603DuLsw8z_4ztK4e4aYMp
  struct frame_5603DuLsw8z_4ztK4e4aYMp_BMst {
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
   memset (&_, 0, sizeof(struct frame_5603DuLsw8z_4ztK4e4aYMp_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 3;
   _.stkfram_descr = constob_55roYj6pggy_95lbHks0q2X_BM[2] /*|_5603DuLsw8z_4ztK4e4aYMp*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 2 arguments:
   _.v_6QhNRfe1Cte_0niVlWfAlmO = arg0; // v_restpath
   _.o_5JuT4FgNFFh_7McrTYeT3jx = objectcast_BM (arg1); // o_webex
   // fetched 2 arguments.
   // no closed values in _5603DuLsw8z_4ztK4e4aYMp.
   const closure_tyBM* callclos_5603DuLsw8z_4ztK4e4aYMp __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_5603DuLsw8z_4ztK4e4aYMp  __attribute__((unused)) = 0;
   // routine _5603DuLsw8z_4ztK4e4aYMp body:

startblock__8CB2Do4OiFy_3dgoJSOayb7: __attribute__((unused));
{ /* +block _8CB2Do4OiFy_3dgoJSOayb7 */ 
 
{ // run _0nVw3Ihw1bt_675oHgyNYMg 
/*debug  restchariot2q19-httphandler start v_restpath o_webex*/
DBGPRINTF_BM("restchariot2q19-httphandler start €%.9s v_restpath=%s o_webex=%s",
 "_0nVw3Ihw1bt_675oHgyNYMg",
 OUTSTRVALUE_BM( /*v_restpath:*/_.v_6QhNRfe1Cte_0niVlWfAlmO),
 objectdbg_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx)); 
} // end run _0nVw3Ihw1bt_675oHgyNYMg 
 
 
 
startblock__2MGfs8R6LWT_3TXgL3gYxuP: __attribute__((unused)); 
{ /* +block _2MGfs8R6LWT_3TXgL3gYxuP */  
if /*cond _7XXRhHCoi55_7tQfMacQDc9*/   
/*when _3ia9CB9OTLD_7qmCT1GJ3Ni:*/  
 (/*has_string:*/hasstring_BM(( /*v_restpath:*/_.v_6QhNRfe1Cte_0niVlWfAlmO),( "/startchariot"))) { //body when _3ia9CB9OTLD_7qmCT1GJ3Ni   
   
{ // run _4K7kSR4Ut7B_6fF7sSUy1m0   
/*debug when /startchariot o_webex /:restchariot2q19-httphandler*/
DBGPRINTF_BM("when /startchariot €%.9s o_webex=%s /:restchariot2q19-httphandler",
 "_4K7kSR4Ut7B_6fF7sSUy1m0",
 objectdbg_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx));
 ;   
} // end run _4K7kSR4Ut7B_6fF7sSUy1m0   
   
} //endwhen _3ia9CB9OTLD_7qmCT1GJ3Ni   
/*endcond _7XXRhHCoi55_7tQfMacQDc9*/  
  
/* !endingblock _2MGfs8R6LWT_3TXgL3gYxuP */  
goto endblock__2MGfs8R6LWT_3TXgL3gYxuP;  
endblock__2MGfs8R6LWT_3TXgL3gYxuP: ;  
} /*-block _2MGfs8R6LWT_3TXgL3gYxuP */ 
//+ #2/5 of block _8CB2Do4OiFy_3dgoJSOayb7 :: 
 
 
{ // run _2j4uW6uN7uf_8DOo7iGaCMr 
/*debug restchariot2q19-httphandler ending v_restpath o_webex*/
DBGPRINTF_BM("debug restchariot2q19-httphandler ending €%.9s v_restpath=%s o_webex=%s (L%u, lin=%u, col=%u, last'%s')***\n%s\n***\n",
 "_2j4uW6uN7uf_8DOo7iGaCMr",
 OUTSTRVALUE_BM( /*v_restpath:*/_.v_6QhNRfe1Cte_0niVlWfAlmO),
 objectdbg_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx),
 objstrbufferlengthpayl_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx),
 objstrbufferlinecountpayl_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx),
 objstrbuffercolumnpayl_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx),
 objstrbuffercurrentlastlinepayl_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx),
 objstrbufferbytespayl_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx)
);; 
} // end run _2j4uW6uN7uf_8DOo7iGaCMr 
 
 
if /*cond _13zkrw8w8YT_3erup1bBeRM*/  
/*when _4fh1339mQXL_1tYitrVTLhj:*/ 
 (/*objstrbufferlengthpayl*/(intptr_t) objstrbufferlengthpayl_BM (( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx))) { //body when _4fh1339mQXL_1tYitrVTLhj  
{ // start cexpansion _0YYpqZYUPQg_2ju17tmSr0l - objwebexchangecompletepayl   
/*objwebexchangecompletepayl:*/ objwebexchangecompletepayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), (/*chunk-constob HTTP_OK:*/(HTTP_OK)), ( "application/json"));   
} // end cexpansion _0YYpqZYUPQg_2ju17tmSr0l - objwebexchangecompletepayl   
  
} //endwhen _4fh1339mQXL_1tYitrVTLhj  
else { /*cond else _13zkrw8w8YT_3erup1bBeRM*/  
{ // start out _0ymYxguPvQq_0vGvlue6w0I to o_webex  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx, "failed reschariot2q19 request ");  
/*out id:*/ char idbuf_0ymYxguPvQq_0vGvlue6w0I_n1[32]={0};  
idtocbuf32_BM (objid_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), idbuf_0ymYxguPvQq_0vGvlue6w0I_n1);  
objstrbufferappendcstrpayl_BM ( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx, idbuf_0ymYxguPvQq_0vGvlue6w0I_n1);  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx, "\n"); 
} // end out _0ymYxguPvQq_0vGvlue6w0I 
 
{ // run _0E4GHlCR1Ls_96gFoyMzQuS 
/*warn o_webex failure /restchariot2q19-httphandler*/
WARNPRINTF_BM ("restchariot2q19-httphandler failing €%.9s v_restpath=%s o_webex=%s '%s'",
"_0E4GHlCR1Ls_96gFoyMzQuS",
OUTSTRVALUE_BM( /*v_restpath:*/_.v_6QhNRfe1Cte_0niVlWfAlmO),
objectdbg_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx),
objstrbufferbytespayl_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx));
DBGBACKTRACEPRINTF_BM("restchariot2q19-httphandler failing €%.9s v_restpath=%s o_webex=%s",
"_0E4GHlCR1Ls_96gFoyMzQuS",
OUTSTRVALUE_BM( /*v_restpath:*/_.v_6QhNRfe1Cte_0niVlWfAlmO),
objectdbg_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx));
; 
} // end run _0E4GHlCR1Ls_96gFoyMzQuS 
{ // start cexpansion _1NPp5SdcXSf_0aVDpQjnsb5 - objwebexchangecompletepayl  
/*objwebexchangecompletepayl:*/ objwebexchangecompletepayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), (/*chunk-constob HTTP_NOT_FOUND:*/(HTTP_NOT_FOUND)), ( "text/plain"));  
} // end cexpansion _1NPp5SdcXSf_0aVDpQjnsb5 - objwebexchangecompletepayl  
} /*cond else _13zkrw8w8YT_3erup1bBeRM*/  
/*endcond _13zkrw8w8YT_3erup1bBeRM*/ 
 
 
/*return _5JZqcb5njTR_3TUFY6Ss0QU:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx; 
 goto epilog_5603DuLsw8z_4ztK4e4aYMp; 
 
/* !endingblock _8CB2Do4OiFy_3dgoJSOayb7 */ 
goto endblock__8CB2Do4OiFy_3dgoJSOayb7; 
endblock__8CB2Do4OiFy_3dgoJSOayb7: ; 
} /*-block _8CB2Do4OiFy_3dgoJSOayb7 */

 epilog_5603DuLsw8z_4ztK4e4aYMp: __attribute__ ((unused)); // routine _5603DuLsw8z_4ztK4e4aYMp epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _5603DuLsw8z_4ztK4e4aYMp routine#1 _5603DuLsw8z_4ztK4e4aYMp




// end of 2 generated routines


// the constant ids for 3 constants:
const char* const constid_55roYj6pggy_95lbHks0q2X_BM[3+1] = {
 /*0:*/
 "_0oA6AajbKuk_8rDrkR7F4jZ",//init_chariotdemo
 "_55roYj6pggy_95lbHks0q2X",//chariotdemo_module
 "_5603DuLsw8z_4ztK4e4aYMp", //! restchariot2q19-httphandler (v_restpath o_webex)
 NULL}; // end 3 constant ids



// the routine ids for 2 routines:
const char* const routid_55roYj6pggy_95lbHks0q2X_BM[2+1] = {
  /*0:*/
  "_0oA6AajbKuk_8rDrkR7F4jZ",//init_chariotdemo
  "_5603DuLsw8z_4ztK4e4aYMp", //!restchariot2q19-httphandler (v_restpath o_webex)

 NULL}; // end 2 routine ids



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
