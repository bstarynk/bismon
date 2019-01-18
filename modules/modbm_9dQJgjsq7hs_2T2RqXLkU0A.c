// generated persistent module webxhtml_module
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



// declare 2 routines

extern const char *const routid_9dQJgjsq7hs_2T2RqXLkU0A_BM[2+1];


// 8 failures

extern objrout_sigBM crout_5NH940lCHYJ_3nuRm3flnzc_BM; //#0 !emithtml_element (o_helem o_emitctx o_strbuf v_depth)

extern objrout_sigBM crout_8IYFtn8osS2_4t1U3wyROLW_BM; //#1 emit_xhtml


// declare 23 constants
objectval_tyBM* constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[23+1];
const char* const constid_9dQJgjsq7hs_2T2RqXLkU0A_BM[23+1];


// define 2 routines


value_tyBM crout_5NH940lCHYJ_3nuRm3flnzc_BM //#0
 (struct stackframe_stBM* stkf, //
//!emithtml_element (o_helem o_emitctx o_strbuf v_depth)
  // 4 arguments
  const value_tyBM arg0,  // o_helem
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
    /// 11 local values:
    value_tyBM v_0qTBOEAT5pa_2fz1SKfHrMV; // v_resemit
    value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
    objectval_tyBM* o_13K9OfeXRZR_84nyRTtoj81; // o_conn
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    value_tyBM v_5GhvzWWP1jl_41tgAIAAa2X; // v_resapp
    objectval_tyBM* o_6Ef2ORO1Mni_0tpNoRQGmrW; // o_helem
    objectval_tyBM* o_6Z4UU939WbU_8BK9xcKsXNb; // o_comp
    objectval_tyBM* o_7Ga6z7nroCG_3ikx3GHV41r; // o_spacing
    objectval_tyBM* o_9nXRmTATjN4_5F9V7RvvgW0; // o_emitctx
    /// 4 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
    intptr_t n_8SJIvFqUkH2_0UJyIX6eA9v; // indent
   } _;
   memset (&_, 0, sizeof(struct frame_5NH940lCHYJ_3nuRm3flnzc_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 11;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[11] /*|_5NH940lCHYJ_3nuRm3flnzc*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // locking 1:
    objectval_tyBM* locked_36l0VwmZ11o_8vCwWpg2xIB = NULL; // for o_helem
   // fetch 4 arguments:
   _.o_6Ef2ORO1Mni_0tpNoRQGmrW = objectcast_BM (arg0); // o_helem
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
/*debug emithtml_element start o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emithtml_element start €%.9s o_helem=%s o_emitctx=%s o_strbuf=%s/L%d depth#%ld",
 "_9W3ifZwUp2j_3cTOMwHevI1",
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (int) objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _9W3ifZwUp2j_3cTOMwHevI1 
 
//+ #2/4 of block _86w0oglm27k_4ULVduuJiC6 :: 
 
if /*cond _6VEZT6yN91n_1uTSi1gCAKy*/  
/*when _0li4T620kcV_4nC1fD477pu:*/ 
 (/*is_null:*/(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW)==NULL)) { //body when _0li4T620kcV_4nC1fD477pu  
//failure _2ekmsdDpheM_8iSH1r9pS9e   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode4_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[15] /*!failure_non_object*/)), 
 /*make_node 4 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[11] /*!_5NH940lCHYJ_3nuRm3flnzc*/)), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[1] /*|_2ekmsdDpheM_8iSH1r9pS9e*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _0li4T620kcV_4nC1fD477pu  
/*endcond _6VEZT6yN91n_1uTSi1gCAKy*/ 
 
 
 
{ // begin lockobj _36l0VwmZ11o_8vCwWpg2xIB 
  objectval_tyBM* curlockedob_36l0VwmZ11o_8vCwWpg2xIB = ( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW); 
if (objlock_BM (curlockedob_36l0VwmZ11o_8vCwWpg2xIB)) {  
locked_36l0VwmZ11o_8vCwWpg2xIB = curlockedob_36l0VwmZ11o_8vCwWpg2xIB;  
  
if /*cond _921fuoujPIF_4a0JqUqMOyG*/  
/*when _6HtsKDbq7Rx_3rZ8uRwGNj9:*/ 
 (/*not:*/ (! (/*objectisinstance:*/ objectisinstance_BM(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[18] /*!html_element_object*/)))))) { //body when _6HtsKDbq7Rx_3rZ8uRwGNj9  
//failure _5rs4UfgeATT_3s7r48scObY   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[6] /*!failure_bad_class*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[18] /*!html_element_object*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[9] /*|_5rs4UfgeATT_3s7r48scObY*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _6HtsKDbq7Rx_3rZ8uRwGNj9  
/*endcond _921fuoujPIF_4a0JqUqMOyG*/ 
  
 /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r = //assign _4gqzOn4YRA4_4DeoI7Me5mK  
/*val_to_object:*/objectcast_BM((send2_BM (( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), /*sel:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[19] /*!html_spacing*/)), ((struct stackframe_stBM*)&_),  
 ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),  (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))); 
  
//+ #2/16 of lockobj _36l0VwmZ11o_8vCwWpg2xIB ::  
 /*indent:*/_.n_8SJIvFqUkH2_0UJyIX6eA9v = //assign _4hBaaJCUqMH_1BMwNQy5oBI  
/*objstrbufferindentationpayl:*/ objstrbufferindentationpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy); 
  
 
{ // run _5jZtyuntuuZ_2Lx45h0TXVc 
/*debug emithtml_element o_helem o_spacing o_emitctx indent depth*/
DBGPRINTF_BM("debug emithtml_element €%.9s o_helem=%s o_spacing=%s o_emitctx=%s indent#%ld depth#%ld",
 "_5jZtyuntuuZ_2Lx45h0TXVc",
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r),
 objectdbg2_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 (long int) ( /*indent:*/_.n_8SJIvFqUkH2_0UJyIX6eA9v),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _5jZtyuntuuZ_2Lx45h0TXVc 
  
//+ #4/16 of lockobj _36l0VwmZ11o_8vCwWpg2xIB ::  
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _5HcDhrmVMP2_2FuMdxilvQ9  
(send3_BM (( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), /*sel:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[12] /*!emit_xhtml_open*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),  ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)))); 
  
if /*cond _4Vd3Fe3lriq_1maa3fRM0K5*/  
/*when _2vrXQXG9ekP_2af2adhJ59X:*/ 
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _2vrXQXG9ekP_2af2adhJ59X  
//failure _5xGV4qXFkqJ_4imeaugtTzv   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[8] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[0] /*!emit_xhtml_open_block*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[10] /*|_5xGV4qXFkqJ_4imeaugtTzv*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _2vrXQXG9ekP_2af2adhJ59X  
/*endcond _4Vd3Fe3lriq_1maa3fRM0K5*/ 
  
//+ #6/16 of lockobj _36l0VwmZ11o_8vCwWpg2xIB ::  
 
{ // run _5uHXmQzi0xh_3EeoqFXMNFU 
/*debug html_block after emit_xhtml_open v_resemit o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emithtml_element after emit_xhtml_open €%.9s v_resemit=%s o_helem=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_5uHXmQzi0xh_3EeoqFXMNFU",
 OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _5uHXmQzi0xh_3EeoqFXMNFU 
  
if /*cond _9xbwkyekv7y_1dtd6RJgaaT*/  
/*when _78CDl258ber_2OZ6iKkZQDj:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[2] /*!newline*/)))) { //body when _78CDl258ber_2OZ6iKkZQDj  
{ // start out _1wybjEqYoCm_7w8ES3jgUxS to o_strbuf   
/*out more_indent:*/ objstrbuffermoreindentpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);   
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);  
} // end out _1wybjEqYoCm_7w8ES3jgUxS  
  
} //endwhen _78CDl258ber_2OZ6iKkZQDj  
else if  
/*when _8gbKuVOJ00d_0iXBwlmG6jd:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[17] /*!nlsp*/)))) { //body when _8gbKuVOJ00d_0iXBwlmG6jd  
{ // start out _6nl4fxXo5P9_4aikEu7hcUs to o_strbuf   
/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);  
} // end out _6nl4fxXo5P9_4aikEu7hcUs  
  
} //endwhen _8gbKuVOJ00d_0iXBwlmG6jd  
else if  
/*when _0aSvuu44cW5_744SUn0a59q:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[3] /*!space*/)))) { //body when _0aSvuu44cW5_744SUn0a59q  
{ // start out _1B27ZtCrJSa_6rQN5QUVjoS to o_strbuf   
/*out space:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " ");  
} // end out _1B27ZtCrJSa_6rQN5QUVjoS  
  
} //endwhen _0aSvuu44cW5_744SUn0a59q  
/*endcond _9xbwkyekv7y_1dtd6RJgaaT*/ 
  
//+ #8/16 of lockobj _36l0VwmZ11o_8vCwWpg2xIB ::  
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _1O9tiQKy3ZB_4oLghWljER9  
/*objnbcomps:*/ objnbcomps_BM ( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW); 
  
{ //for-up _8QYxgALaJfV_49EojKGexX9  
intptr_t cnt_8QYxgALaJfV_49EojKGexX9 =  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k;  
for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_8QYxgALaJfV_49EojKGexX9;  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++) {  
// for-up _8QYxgALaJfV_49EojKGexX9 #0 :  
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _1e0bYiMflzj_5KajHdAnW2S   
/*objgetcomp:*/objgetcomp_BM (( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));  
  
// for-up _8QYxgALaJfV_49EojKGexX9 #1 :  
  
{ // run _8ARi1AYq5Oh_3DoCCtCI4sE  
/*debug  emithtml_element for-loop ii v_comp o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emithtml_element for-loop €%.9s ii#%ld v_comp=%s o_helem=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
"_8ARi1AYq5Oh_3DoCCtCI4sE",
 (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
 OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;  
} // end run _8ARi1AYq5Oh_3DoCCtCI4sE  
  
// for-up _8QYxgALaJfV_49EojKGexX9 #2 :  
if /*cond _9esS4NliRiB_2VgVZ0sULry*/   
/*when _2VEPlTDtufU_1OJU65eKBpP:*/  
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[2] /*!newline*/)))) { //body when _2VEPlTDtufU_1OJU65eKBpP   
{ // start out _8Nw9zJ5h0KD_02bjHvKfgQw to o_strbuf    
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);   
} // end out _8Nw9zJ5h0KD_02bjHvKfgQw   
   
} //endwhen _2VEPlTDtufU_1OJU65eKBpP   
else if   
/*when _9lQbBHyLisB_9RbsRinLVVi:*/  
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[17] /*!nlsp*/)))) { //body when _9lQbBHyLisB_9RbsRinLVVi   
{ // start out _0nMvmHfMjyF_5iZ1qqd9K8S to o_strbuf    
/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);   
} // end out _0nMvmHfMjyF_5iZ1qqd9K8S   
   
} //endwhen _9lQbBHyLisB_9RbsRinLVVi   
else if   
/*when _9BdaJn6vBWW_7n07rdHXudX:*/  
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[3] /*!space*/)))) { //body when _9BdaJn6vBWW_7n07rdHXudX   
{ // start out _6FxYfpCMqWj_2x1fBqLWf57 to o_strbuf    
/*out space:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " ");   
} // end out _6FxYfpCMqWj_2x1fBqLWf57   
   
} //endwhen _9BdaJn6vBWW_7n07rdHXudX   
/*endcond _9esS4NliRiB_2VgVZ0sULry*/  
  
// for-up _8QYxgALaJfV_49EojKGexX9 #3 :  
if /*cond _8lD3fxOhyG6_3hVtNFYOfvx*/   
/*when _2qY43EInXVz_24Rcm7E5Q5O:*/  
 (/*isclosure:*/isclosure_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe))) { //body when _2qY43EInXVz_24Rcm7E5Q5O   
 /*v_resapp:*/_.v_5GhvzWWP1jl_41tgAIAAa2X = //assign _2zwWUFpPkWs_9hzuHMCYLNN    
(apply5_BM (( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), ((struct stackframe_stBM*)&_), 
 ( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),  (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),  ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))));   
if /*cond _8H1nHa8jIS8_8ODAaGXBQ7r*/    
/*when _0duywt0q9ei_3bQRDA56iMe:*/   
 (/*is_null:*/(( /*v_resapp:*/_.v_5GhvzWWP1jl_41tgAIAAa2X)==NULL)) { //body when _0duywt0q9ei_3bQRDA56iMe    
//failure _6fuAy20JBMH_9E0Ba9SelrI     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[8] /*!failure_miss*/)), 
 /*make_node 8 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[11] /*!_5NH940lCHYJ_3nuRm3flnzc*/)), 
 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[5] /*!apply*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[14] /*|_6fuAy20JBMH_9E0Ba9SelrI*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _0duywt0q9ei_3bQRDA56iMe    
/*endcond _8H1nHa8jIS8_8ODAaGXBQ7r*/   
   
{ // run _0yeErAtJlXO_4iAmk9lGCg5   
/*debug emithtml_element v_resapp v_comp ii o_helem o_emitctx o_strbuf depth*/
 DBGPRINTF_BM("emithtml_element €%.9s v_resapp=%s v_comp=%s ii#%ld o_helem=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
  "_0yeErAtJlXO_4iAmk9lGCg5",
  OUTSTRVALUE_BM( /*v_resapp:*/_.v_5GhvzWWP1jl_41tgAIAAa2X),
  OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
  (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
  objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
  objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
  objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
  objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
  (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
 ;   
} // end run _0yeErAtJlXO_4iAmk9lGCg5   
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _1pc5iOxuecF_89k9yYR0OSD    
 /*v_resapp:*/_.v_5GhvzWWP1jl_41tgAIAAa2X;   
   
} //endwhen _2qY43EInXVz_24Rcm7E5Q5O   
/*endcond _8lD3fxOhyG6_3hVtNFYOfvx*/  
  
// for-up _8QYxgALaJfV_49EojKGexX9 #4 :  
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _9WzUvoIHCSM_4O5lNZm3jb2   
(apply4_BM (( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[21] /*!emit_xhtml*/)), ((struct stackframe_stBM*)&_), 
 ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));  
  
// for-up _8QYxgALaJfV_49EojKGexX9 #5 :  
if /*cond _6JhK96miaMx_3XLltRct5WU*/   
/*when _7yndBSvwm1J_9N5z0dJuXIM:*/  
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _7yndBSvwm1J_9N5z0dJuXIM   
//failure _51oIiJoCulz_1NyarSIagfB    
PLACEDFAILURE_BM(__LINE__,    
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[8] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[21] /*!emit_xhtml*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[7] /*|_51oIiJoCulz_1NyarSIagfB*/)),
                ((struct stackframe_stBM *) &_));
   
} //endwhen _7yndBSvwm1J_9N5z0dJuXIM   
/*endcond _6JhK96miaMx_3XLltRct5WU*/  
 
}} // end for-up _8QYxgALaJfV_49EojKGexX9 
  
//+ #10/16 of lockobj _36l0VwmZ11o_8vCwWpg2xIB ::  
{ // start cexpansion _11rqSXWIScp_7YYIjuSNRED - objstrbuffersetindentpayl  
/*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), ( /*indent:*/_.n_8SJIvFqUkH2_0UJyIX6eA9v));  
} // end cexpansion _11rqSXWIScp_7YYIjuSNRED - objstrbuffersetindentpayl  
  
if /*cond _8Vnn5fbTxZD_5r0Nn4OLpXW*/  
/*when _7Tqp9FaGOi6_1zlNZrsr3P4:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[2] /*!newline*/)))) { //body when _7Tqp9FaGOi6_1zlNZrsr3P4  
{ // start out _5xthhfX2qlp_6rUZ8Mn7fG9 to o_strbuf   
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);  
} // end out _5xthhfX2qlp_6rUZ8Mn7fG9  
  
} //endwhen _7Tqp9FaGOi6_1zlNZrsr3P4  
else if  
/*when _26hfrrkoYbw_0EsJYF6nzjS:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[17] /*!nlsp*/)))) { //body when _26hfrrkoYbw_0EsJYF6nzjS  
{ // start out _8ALxuahzjVn_9JyrNMc4dcs to o_strbuf   
/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);  
} // end out _8ALxuahzjVn_9JyrNMc4dcs  
  
} //endwhen _26hfrrkoYbw_0EsJYF6nzjS  
else if  
/*when _4c7whFwVYld_6KcIS6aV9Yf:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[3] /*!space*/)))) { //body when _4c7whFwVYld_6KcIS6aV9Yf  
{ // start out _74KTDkonWj7_1nFV9AC8hqV to o_strbuf   
/*out space:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " ");  
} // end out _74KTDkonWj7_1nFV9AC8hqV  
  
} //endwhen _4c7whFwVYld_6KcIS6aV9Yf  
/*endcond _8Vnn5fbTxZD_5r0Nn4OLpXW*/ 
  
//+ #12/16 of lockobj _36l0VwmZ11o_8vCwWpg2xIB ::  
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _57b6lxQ5kk0_1tnbFcSXWzZ  
(send3_BM (( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), /*sel:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[22] /*!emit_xhtml_close*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),  ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)))); 
  
if /*cond _3KuONWqujLf_2emaaopgisz*/  
/*when _91sBBNcteqP_4va0MZWNZTy:*/ 
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _91sBBNcteqP_4va0MZWNZTy  
//failure _6aE0EksoSSG_7KzxsTRdC3x   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[8] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[22] /*!emit_xhtml_close*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[13] /*|_6aE0EksoSSG_7KzxsTRdC3x*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _91sBBNcteqP_4va0MZWNZTy  
/*endcond _3KuONWqujLf_2emaaopgisz*/ 
  
//+ #14/16 of lockobj _36l0VwmZ11o_8vCwWpg2xIB ::  
 
{ // run _1k3HHXqIxKk_5nxA2F1eZlb 
/*debug end emithtml_element v_resemit o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("debug end emithtml_element €%.9s v_resemit=%s o_helem=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_1k3HHXqIxKk_5nxA2F1eZlb",
 OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _1k3HHXqIxKk_5nxA2F1eZlb 
  
/*return _6yMZoWmfClM_83bjcvRlPfN:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW; 
 goto epilog_5NH940lCHYJ_3nuRm3flnzc; 
  
objunlock_BM (locked_36l0VwmZ11o_8vCwWpg2xIB), locked_36l0VwmZ11o_8vCwWpg2xIB = NULL; 
} } // end objlock _36l0VwmZ11o_8vCwWpg2xIB 
/* !endingblock _86w0oglm27k_4ULVduuJiC6 */ 
goto endblock__86w0oglm27k_4ULVduuJiC6; 
endblock__86w0oglm27k_4ULVduuJiC6: ; 
} /*-block _86w0oglm27k_4ULVduuJiC6 */

 epilog_5NH940lCHYJ_3nuRm3flnzc: __attribute__ ((unused)); // routine _5NH940lCHYJ_3nuRm3flnzc epilogue:
   // unlocking 1:
    if (locked_36l0VwmZ11o_8vCwWpg2xIB != NULL)
       objunlock_BM(locked_36l0VwmZ11o_8vCwWpg2xIB), locked_36l0VwmZ11o_8vCwWpg2xIB = NULL; // for o_helem
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _5NH940lCHYJ_3nuRm3flnzc routine#0 _5NH940lCHYJ_3nuRm3flnzc




value_tyBM crout_8IYFtn8osS2_4t1U3wyROLW_BM //#1+
 (struct stackframe_stBM* stkf, // emit_xhtml
  // 4 arguments
  const value_tyBM arg0,  // v_html
  const value_tyBM arg1,  // o_emitctx
  const value_tyBM arg2,  // o_strbuf
  const value_tyBM arg3,  // v_depth
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of emit_xhtml
  struct frame_8IYFtn8osS2_4t1U3wyROLW_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 10 local values:
    value_tyBM v_0qTBOEAT5pa_2fz1SKfHrMV; // v_resemit
    value_tyBM v_0DmuWueFbx9_5bzv8xgw3fu; // v_html
    value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
    objectval_tyBM* o_13K9OfeXRZR_84nyRTtoj81; // o_conn
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    value_tyBM v_5GhvzWWP1jl_41tgAIAAa2X; // v_resapp
    objectval_tyBM* o_9nXRmTATjN4_5F9V7RvvgW0; // o_emitctx
    objectval_tyBM* o_9GjmuXWAb93_7ZScgIdlvkf; // o_html
    /// 3 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
   } _;
   memset (&_, 0, sizeof(struct frame_8IYFtn8osS2_4t1U3wyROLW_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 10;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[21] /*|emit_xhtml*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 4 arguments:
   _.v_0DmuWueFbx9_5bzv8xgw3fu = arg0; // v_html
   _.o_9nXRmTATjN4_5F9V7RvvgW0 = objectcast_BM (arg1); // o_emitctx
   _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg2); // o_strbuf
   _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
   // fetched 4 arguments.
   // no closed values in emit_xhtml.
   // routine _8IYFtn8osS2_4t1U3wyROLW body:

startblock__3DcbHfTP2te_8Zw8Uhy9eU6: __attribute__((unused));
{ /* +block _3DcbHfTP2te_8Zw8Uhy9eU6 */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _8uqITOuF3yu_9Uyyhkc1y9S  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 
{ // run _7KjUhmzgBEC_2FAElSuzMNO 
/*debug start emit_xhtml v_html o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emit_xhtml start €%.9s v_html=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_7KjUhmzgBEC_2FAElSuzMNO",
 OUTSTRVALUE_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),
 objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _7KjUhmzgBEC_2FAElSuzMNO 
 
//+ #2/4 of block _3DcbHfTP2te_8Zw8Uhy9eU6 :: 
 
if /*cond _8hRp9kZ7uvu_4MzyhRQIoRd*/  
/*when _70ZSzCpjqWE_1AjclUpwXjD:*/ 
 (/*objstrbufferispercentfullpayl:*/(intptr_t)objstrbufferispercentfullpayl_BM(( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),(int)( 90))) { //body when _70ZSzCpjqWE_1AjclUpwXjD  
//failure _8yowRQLZgzP_4vqWjo12OS4   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[4] /*!failure_full*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[21] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[20] /*|_8yowRQLZgzP_4vqWjo12OS4*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _70ZSzCpjqWE_1AjclUpwXjD  
/*endcond _8hRp9kZ7uvu_4MzyhRQIoRd*/ 
 
 
if /*cond _24sbIpdvwNd_9c4S4cSYLYE*/  
/*when _0lnsrM6CMWA_4PCoTTYLR3e:*/ 
 ((/*greater_int:*/( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) > ( 100))) { //body when _0lnsrM6CMWA_4PCoTTYLR3e  
//failure _79ub6Ngc5aa_42TtfuLTsPs   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[8] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[21] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[16] /*|_79ub6Ngc5aa_42TtfuLTsPs*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _0lnsrM6CMWA_4PCoTTYLR3e  
/*endcond _24sbIpdvwNd_9c4S4cSYLYE*/ 
 
/* !endingblock _3DcbHfTP2te_8Zw8Uhy9eU6 */ 
goto endblock__3DcbHfTP2te_8Zw8Uhy9eU6; 
endblock__3DcbHfTP2te_8Zw8Uhy9eU6: ; 
} /*-block _3DcbHfTP2te_8Zw8Uhy9eU6 */

 epilog_8IYFtn8osS2_4t1U3wyROLW: __attribute__ ((unused)); // routine _8IYFtn8osS2_4t1U3wyROLW epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _8IYFtn8osS2_4t1U3wyROLW routine#1 emit_xhtml




// end of 2 generated routines


// the constant ids for 23 constants:
const char* const constid_9dQJgjsq7hs_2T2RqXLkU0A_BM[23+1] = {
 /*0:*/
 "_22MieznSASY_8V0HbjohiyB",//emit_xhtml_open_block
 "_2ekmsdDpheM_8iSH1r9pS9e", //! fail non-object emithtml_element o_emitctx o_strbuf depth
 "_2wGWzItVmrN_2CBwG6iHWFO",//newline
 "_35gLacRFhq5_90zAPxiDIlh",//space
 "_3zzOJ9b7sUf_89ZOhP1HlUQ",//failure_full
 /*5:*/
 "_3Nl6LhfUZVb_1itsyWMBfYl",//apply
 "_4HgYLk6htvP_4Ac2FCPfQ1C",//failure_bad_class
 "_51oIiJoCulz_1NyarSIagfB", //! fail-miss emit_xhtml v_comp ii o_emitctx o_strbuf depth
 "_52XwytpOPVl_3ZjmQCtadbK",//failure_miss
 "_5rs4UfgeATT_3s7r48scObY", //! fail-bad-class html_element_object o_helem o_emitctx o_strbuf depth - emithtml_element
 /*10:*/
 "_5xGV4qXFkqJ_4imeaugtTzv", //! fail-miss emit_xhtml_open_block o_helem o_emitctx depth
 "_5NH940lCHYJ_3nuRm3flnzc", //! emithtml_element (o_helem o_emitctx o_strbuf v_depth)
 "_64Nwpjx4gnk_2y263bTCaB3",//emit_xhtml_open
 "_6aE0EksoSSG_7KzxsTRdC3x", //! fail-miss emit_xhtml_close o_helem o_emitctx o_strbuf depth
 "_6fuAy20JBMH_9E0Ba9SelrI", //! fail-miss emithtml_element apply v_comp o_helem ii o_emitctx o_strbuf depth
 /*15:*/
 "_6yWldsq3Rmk_01WqTfwSIDV",//failure_non_object
 "_79ub6Ngc5aa_42TtfuLTsPs", //! fail failure_miss emit_xhtml v_html o_emitctx depth // too deep
 "_7coI3Hezrvp_6CG1u3MlT83",//nlsp
 "_7FvfalQCaxj_24GCf5CtIWh",//html_element_object
 "_84d7WOdRsJh_4Ud9BryxYUr",//html_spacing
 /*20:*/
 "_8yowRQLZgzP_4vqWjo12OS4", //! fail failure_full emit_xhtml v_html o_emitctx depth
 "_8IYFtn8osS2_4t1U3wyROLW",//emit_xhtml
 "_9gZVGQz0y78_7TEf371aZqR",//emit_xhtml_close
 NULL}; // end 23 constant ids



// the routine ids for 2 routines:
const char* const routid_9dQJgjsq7hs_2T2RqXLkU0A_BM[2+1] = {
  /*0:*/
  "_5NH940lCHYJ_3nuRm3flnzc", //!emithtml_element (o_helem o_emitctx o_strbuf v_depth)
  "_8IYFtn8osS2_4t1U3wyROLW",//emit_xhtml

 NULL}; // end 2 routine ids



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



// end of generated persistent module webxhtml_module in file modbm_9dQJgjsq7hs_2T2RqXLkU0A.c
