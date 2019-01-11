// generated persistent module webhtml_module
// in file modbm_9dQJgjsq7hs_2T2RqXLkU0A.c -- DONT EDIT
// this generated code is GPLv3+ licensed.


#include "bismon.h"

#ifdef BISMON_MODID
DECLARE_MODULE_BM(_9dQJgjsq7hs_2T2RqXLkU0A);
extern moduleinit_sigBM modulinit_9dQJgjsq7hs_2T2RqXLkU0A_BM;
#endif /*BISMON_MODID*/

#ifdef BISMON_MOMD5
const char modulmd5chksum_9dQJgjsq7hs_2T2RqXLkU0A_BM[] = BISMON_MOMD5;
#endif /*BISMON_MOMD5*/



// declare 1 routines

extern const char *const routid_9dQJgjsq7hs_2T2RqXLkU0A_BM[1+1];


// 2 failures

extern objrout_sigBM crout_5NH940lCHYJ_3nuRm3flnzc_BM; //#0 !emithtml_block (o_hblock o_emitctx o_strbuf v_depth)


// declare 6 constants
objectval_tyBM* constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[6+1];
const char* const constid_9dQJgjsq7hs_2T2RqXLkU0A_BM[6+1];


// define 1 routines


value_tyBM crout_5NH940lCHYJ_3nuRm3flnzc_BM //#0
 (struct stackframe_stBM* stkf, //
//!emithtml_block (o_hblock o_emitctx o_strbuf v_depth)
  // 4 arguments
  const value_tyBM arg0,  // o_hblock
  const value_tyBM arg1,  // o_emitctx
  const value_tyBM arg2,  // o_strbuf
  const value_tyBM arg3,  // v_depth
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _5NH940lCHYJ_3nuRm3flnzc
  struct frame_5NH940lCHYJ_3nuRm3flnzc_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 9 local values:
    value_tyBM v_0qTBOEAT5pa_2fz1SKfHrMV; // v_resemit
    value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
    objectval_tyBM* o_13K9OfeXRZR_84nyRTtoj81; // o_conn
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    objectval_tyBM* o_6Ef2ORO1Mni_0tpNoRQGmrW; // o_hblock
    objectval_tyBM* o_6Z4UU939WbU_8BK9xcKsXNb; // o_comp
    objectval_tyBM* o_9nXRmTATjN4_5F9V7RvvgW0; // o_emitctx
    /// 2 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
   } _;
   memset (&_, 0, sizeof(struct frame_5NH940lCHYJ_3nuRm3flnzc_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 9;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[4] /*|_5NH940lCHYJ_3nuRm3flnzc*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // locking 1:
    objectval_tyBM* locked_36l0VwmZ11o_8vCwWpg2xIB = NULL; // for o_hblock
   // fetch 4 arguments:
   _.o_6Ef2ORO1Mni_0tpNoRQGmrW = objectcast_BM (arg0); // o_hblock
   _.o_9nXRmTATjN4_5F9V7RvvgW0 = objectcast_BM (arg1); // o_emitctx
   _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg2); // o_strbuf
   _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
   // fetched 4 arguments.
   // no closed values in _5NH940lCHYJ_3nuRm3flnzc.
   // routine _5NH940lCHYJ_3nuRm3flnzc body:

startblock__86w0oglm27k_4ULVduuJiC6: __attribute__((unused));
{ /* +block _86w0oglm27k_4ULVduuJiC6 */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _7j8aQZXvf5R_12tuW3bNSTQ  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 
{ // run _9W3ifZwUp2j_3cTOMwHevI1 
/*debug emithtml_block start o_hblock o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emithtml_block start €%.9s o_hblock=%s o_emitctx=%s o_strbuf=%s/L%d depth#%ld",
 "_9W3ifZwUp2j_3cTOMwHevI1",
 objectdbg_BM( /*o_hblock:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (int) objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _9W3ifZwUp2j_3cTOMwHevI1 
 
//+ #2/4 of block _86w0oglm27k_4ULVduuJiC6 :: 
 
if /*cond _6VEZT6yN91n_1uTSi1gCAKy*/  
/*when _0li4T620kcV_4nC1fD477pu:*/ 
 (/*is_null:*/(( /*o_hblock:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW)==NULL)) { //body when _0li4T620kcV_4nC1fD477pu  
//failure _2ekmsdDpheM_8iSH1r9pS9e   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode4_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[5] /*!failure_non_object*/)), 
 /*make_node 4 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[4] /*!_5NH940lCHYJ_3nuRm3flnzc*/)), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[1] /*|_2ekmsdDpheM_8iSH1r9pS9e*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _0li4T620kcV_4nC1fD477pu  
/*endcond _6VEZT6yN91n_1uTSi1gCAKy*/ 
 
 
 
{ // begin lockobj _36l0VwmZ11o_8vCwWpg2xIB 
  objectval_tyBM* curlockedob_36l0VwmZ11o_8vCwWpg2xIB = ( /*o_hblock:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW); 
if (objlock_BM (curlockedob_36l0VwmZ11o_8vCwWpg2xIB)) {  
locked_36l0VwmZ11o_8vCwWpg2xIB = curlockedob_36l0VwmZ11o_8vCwWpg2xIB;  
  
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _5HcDhrmVMP2_2FuMdxilvQ9  
(send3_BM (( /*o_hblock:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), /*sel:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[0] /*!emit_html_open_block*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),  ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)))); 
  
if /*cond _4Vd3Fe3lriq_1maa3fRM0K5*/  
/*when _2vrXQXG9ekP_2af2adhJ59X:*/ 
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _2vrXQXG9ekP_2af2adhJ59X  
//failure _5xGV4qXFkqJ_4imeaugtTzv   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[2] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[0] /*!emit_html_open_block*/)), 
 
( /*o_hblock:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[3] /*|_5xGV4qXFkqJ_4imeaugtTzv*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _2vrXQXG9ekP_2af2adhJ59X  
/*endcond _4Vd3Fe3lriq_1maa3fRM0K5*/ 
  
 
{ // run _5uHXmQzi0xh_3EeoqFXMNFU 
/*debug emithtml_block after emit_html_open_block v_resemit o_hblock o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emithtml_block after emit_html_open_block €%.9s v_resemit=%s o_hblock=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_5uHXmQzi0xh_3EeoqFXMNFU", 
 OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
 objectdbg_BM( /*o_hblock:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
; 
} // end run _5uHXmQzi0xh_3EeoqFXMNFU 
  
objunlock_BM (locked_36l0VwmZ11o_8vCwWpg2xIB), locked_36l0VwmZ11o_8vCwWpg2xIB = NULL; 
} } // end objlock _36l0VwmZ11o_8vCwWpg2xIB 
/* !endingblock _86w0oglm27k_4ULVduuJiC6 */ 
goto endblock__86w0oglm27k_4ULVduuJiC6; 
endblock__86w0oglm27k_4ULVduuJiC6: ; 
} /*-block _86w0oglm27k_4ULVduuJiC6 */

 epilog_5NH940lCHYJ_3nuRm3flnzc: __attribute__ ((unused)); // routine _5NH940lCHYJ_3nuRm3flnzc epilogue:
   // unlocking 1:
    if (locked_36l0VwmZ11o_8vCwWpg2xIB != NULL)
       objunlock_BM(locked_36l0VwmZ11o_8vCwWpg2xIB), locked_36l0VwmZ11o_8vCwWpg2xIB = NULL; // for o_hblock
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _5NH940lCHYJ_3nuRm3flnzc routine#0 _5NH940lCHYJ_3nuRm3flnzc




// end of 1 generated routines


// the constant ids for 6 constants:
const char* const constid_9dQJgjsq7hs_2T2RqXLkU0A_BM[6+1] = {
 /*0:*/
 "_22MieznSASY_8V0HbjohiyB",//emit_html_open_block
 "_2ekmsdDpheM_8iSH1r9pS9e", //! fail non-object emithtml_block o_emitctx o_strbuf depth
 "_52XwytpOPVl_3ZjmQCtadbK",//failure_miss
 "_5xGV4qXFkqJ_4imeaugtTzv", //! fail-miss emit_html_open_block o_hblock o_emitctx depth
 "_5NH940lCHYJ_3nuRm3flnzc", //! emithtml_block (o_hblock o_emitctx o_strbuf v_depth)
 /*5:*/
 "_6yWldsq3Rmk_01WqTfwSIDV",//failure_non_object
 NULL}; // end 6 constant ids



// the routine ids for 1 routines:
const char* const routid_9dQJgjsq7hs_2T2RqXLkU0A_BM[1+1] = {
  /*0:*/
  "_5NH940lCHYJ_3nuRm3flnzc", //!emithtml_block (o_hblock o_emitctx o_strbuf v_depth)

 NULL}; // end 1 routine ids



// basiclo*module initialization
#ifdef BISMON_MODID
value_tyBM modulinit_9dQJgjsq7hs_2T2RqXLkU0A_BM
  (struct stackframe_stBM *stkf, //
   const value_tyBM arg1, //
   const value_tyBM arg2, //
   const value_tyBM arg3, //
   void* dlh) {
  return simple_module_initialize_BM(arg1, arg2, arg3, //
        "_9dQJgjsq7hs_2T2RqXLkU0A",//
       constob_9dQJgjsq7hs_2T2RqXLkU0A_BM, //
       constid_9dQJgjsq7hs_2T2RqXLkU0A_BM, //
       routid_9dQJgjsq7hs_2T2RqXLkU0A_BM, //
       dlh, stkf);
} // end modulinit_9dQJgjsq7hs_2T2RqXLkU0A_BM
#endif /*BISMON_MODID*/



// end of generated persistent module webhtml_module in file modbm_9dQJgjsq7hs_2T2RqXLkU0A.c
