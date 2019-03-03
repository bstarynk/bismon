// generated persistent module webxhtml_module
// in file modbm_9dQJgjsq7hs_2T2RqXLkU0A.c -- DONT EDIT
// this generated code is GPLv3+ licensed.


#include "bismon.h"

#ifdef BISMON_MODID
DECLARE_MODULE_BM(_9dQJgjsq7hs_2T2RqXLkU0A);
extern moduleinit_sigBM moduleinit_9dQJgjsq7hs_2T2RqXLkU0A_BM;
#endif /*BISMON_MODID*/

#ifdef BISMON_MOMD5
const char modulmd5chksum_9dQJgjsq7hs_2T2RqXLkU0A_BM[] = BISMON_MOMD5;
#endif /*BISMON_MOMD5*/



// declare 6 routines

extern const char *const routid_9dQJgjsq7hs_2T2RqXLkU0A_BM[6+1];


// 11 failures

extern objrout_sigBM crout_0FRLxSGQlZ0_0qrrUZlEeKp_BM; //#0 !emitxhtml_void_element (o_helem o_emitctx o_strbuf v_depth)

extern objrout_sigBM crout_4I0ksnAasRT_1bREYU29xgL_BM; //#1 !emit-tagged-xhtml-open closed[v_htmltagstr v_htmlclass] (o_emitctx o_strbuf v_depth

extern objrout_sigBM crout_5NH940lCHYJ_3nuRm3flnzc_BM; //#2 !emitxhtml_element (o_helem o_emitctx o_strbuf v_depth)

extern objrout_sigBM crout_6TYtJU0rl2h_2z4md7DV06z_BM; //#3 !root-web-handler

extern objrout_sigBM crout_8IYFtn8osS2_4t1U3wyROLW_BM; //#4 emit_xhtml

extern objrout_sigBM crout_9hEreAemqXg_0uoN1Fr1ly4_BM; //#5 !emit-tagged-id-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget] (o_emitctx o_strbuf v_depth)


// declare 32 constants
objectval_tyBM* constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[32+1];
const char* const constid_9dQJgjsq7hs_2T2RqXLkU0A_BM[32+1];


// define 6 routines


value_tyBM crout_0FRLxSGQlZ0_0qrrUZlEeKp_BM //#0
 (struct stackframe_stBM* stkf, //
//!emitxhtml_void_element (o_helem o_emitctx o_strbuf v_depth)
  // 4 arguments
  const value_tyBM arg0,  // o_helem
  const value_tyBM arg1,  // o_emitctx
  const value_tyBM arg2,  // o_strbuf
  const value_tyBM arg3,  // v_depth
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _0FRLxSGQlZ0_0qrrUZlEeKp
  struct frame_0FRLxSGQlZ0_0qrrUZlEeKp_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 7 local values:
    value_tyBM v_0iT9NuqVo8P_188wxqHeyJZ; // v_tagstr
    value_tyBM v_0qTBOEAT5pa_2fz1SKfHrMV; // v_resemit
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    objectval_tyBM* o_6Ef2ORO1Mni_0tpNoRQGmrW; // o_helem
    objectval_tyBM* o_9nXRmTATjN4_5F9V7RvvgW0; // o_emitctx
    /// 1 local numbers:
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
   } _;
   memset (&_, 0, sizeof(struct frame_0FRLxSGQlZ0_0qrrUZlEeKp_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 7;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[0] /*|_0FRLxSGQlZ0_0qrrUZlEeKp*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // locking 1:
    objectval_tyBM* locked_5sxQbo4ocBH_0O96nRSvJV9 = NULL; // for o_helem
   // fetch 4 arguments:
   _.o_6Ef2ORO1Mni_0tpNoRQGmrW = objectcast_BM (arg0); // o_helem
   _.o_9nXRmTATjN4_5F9V7RvvgW0 = objectcast_BM (arg1); // o_emitctx
   _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg2); // o_strbuf
   _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
   // fetched 4 arguments.
   // no closed values in _0FRLxSGQlZ0_0qrrUZlEeKp.
   // routine _0FRLxSGQlZ0_0qrrUZlEeKp body:

startblock__5OqxK5JMgWp_4fzCg3OhXpz: __attribute__((unused));
{ /* +block _5OqxK5JMgWp_4fzCg3OhXpz */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _9MTOKrnDXFp_8VuIwpZq4ML  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
if /*cond _8M3YH8mCQmK_5hzOV7dlK6y*/  
/*when _70NLVhtnim4_46BJ6K9hmTk:*/ 
 (/*not:*/ (! (/*objectisinstance:*/ objectisinstance_BM(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[14] /*!html_void_element_object*/)))))) { //body when _70NLVhtnim4_46BJ6K9hmTk  
//failure _4nCl6kh6zgK_8WQFqxe24i2   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[30] /*!failure_type_error*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[14] /*!html_void_element_object*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[9] /*|_4nCl6kh6zgK_8WQFqxe24i2*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _70NLVhtnim4_46BJ6K9hmTk  
/*endcond _8M3YH8mCQmK_5hzOV7dlK6y*/ 
 
 
 
{ // begin lockobj _5sxQbo4ocBH_0O96nRSvJV9 
  objectval_tyBM* curlockedob_5sxQbo4ocBH_0O96nRSvJV9 = ( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW); 
if (objlock_BM (curlockedob_5sxQbo4ocBH_0O96nRSvJV9)) {  
locked_5sxQbo4ocBH_0O96nRSvJV9 = curlockedob_5sxQbo4ocBH_0O96nRSvJV9;  
  
 
{ // run _0YZHo35OESp_4FkmqT9KTF1 
/*debug emitxhtml_void_element start o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emitxhtml_void_element start €%.9s o_helem=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_0YZHo35OESp_4FkmqT9KTF1",
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _0YZHo35OESp_4FkmqT9KTF1 
  
if /*cond _4Wn7pRPmEIx_0mreF5MM3NE*/  
/*when _07EuRmnWGXF_5vxo4maeUAi:*/ 
 (/*not:*/ (! (/*objectisinstance:*/ objectisinstance_BM(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[14] /*!html_void_element_object*/)))))) { //body when _07EuRmnWGXF_5vxo4maeUAi  
//failure _3EfvM2lT7h3_8fHXQsltxSG   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[10] /*!failure_bad_class*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[0] /*!_0FRLxSGQlZ0_0qrrUZlEeKp*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[7] /*|_3EfvM2lT7h3_8fHXQsltxSG*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _07EuRmnWGXF_5vxo4maeUAi  
/*endcond _4Wn7pRPmEIx_0mreF5MM3NE*/ 
  
//+ #2/7 of lockobj _5sxQbo4ocBH_0O96nRSvJV9 ::  
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _5HcDhrmVMP2_2FuMdxilvQ9  
(send3_BM (( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), /*sel:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[19] /*!emit_xhtml_open*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),  ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)))); 
  
 
{ // run _2WwFxeI9iYR_4yuPUa9Qq27 
/*debug emitxhtml_void_element after emit_xhtml_open v_resemit o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emitxhtml_void_element after emit_xhtml_open €%.9s v_resemit=%s  o_helem=%s o_emitctx=%s o_strbuf=%s/L%u depth=%ld",
 "_2WwFxeI9iYR_4yuPUa9Qq27",
 OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _2WwFxeI9iYR_4yuPUa9Qq27 
  
//+ #4/7 of lockobj _5sxQbo4ocBH_0O96nRSvJV9 ::  
if /*cond _2jBO1fnZqEm_79Y6lkBP9by*/  
/*when _5F0HKbOS6EW_0GNnYHfFIKp:*/ 
 (/*is_stringv:*/ isstring_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)) { //body when _5F0HKbOS6EW_0GNnYHfFIKp  
 /*v_tagstr:*/_.v_0iT9NuqVo8P_188wxqHeyJZ = //assign _2hXpolEPauV_5oKhlb6Nheu   
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV;  
  
} //endwhen _5F0HKbOS6EW_0GNnYHfFIKp  
else if  
/*when _44cEV8LtWCy_4fX3McNsNmP:*/ 
 ( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV) { //body when _44cEV8LtWCy_4fX3McNsNmP  
//failure _3ECxU06gRdk_8uZReHKm10m   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[30] /*!failure_type_error*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[0] /*!_0FRLxSGQlZ0_0qrrUZlEeKp*/)), 
 
( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[8] /*|_3ECxU06gRdk_8uZReHKm10m*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _44cEV8LtWCy_4fX3McNsNmP  
else { /*cond else _2jBO1fnZqEm_79Y6lkBP9by*/  
//failure _33eRuL6abjL_4uGwIWu51cd  
PLACEDFAILURE_BM(__LINE__,  
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[13] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[0] /*!_0FRLxSGQlZ0_0qrrUZlEeKp*/)), 
 
( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[3] /*|_33eRuL6abjL_4uGwIWu51cd*/)),
                ((struct stackframe_stBM *) &_));
} /*cond else _2jBO1fnZqEm_79Y6lkBP9by*/  
/*endcond _2jBO1fnZqEm_79Y6lkBP9by*/ 
  
{ // start out _6NfpbgW4wOm_52tuQcDrHIf to o_strbuf  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "/>"); 
} // end out _6NfpbgW4wOm_52tuQcDrHIf 
  
/*return _1DWUkaqcmMj_5RSiyE41UAv:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*v_tagstr:*/_.v_0iT9NuqVo8P_188wxqHeyJZ; 
 goto epilog_0FRLxSGQlZ0_0qrrUZlEeKp; 
  
objunlock_BM (locked_5sxQbo4ocBH_0O96nRSvJV9), locked_5sxQbo4ocBH_0O96nRSvJV9 = NULL; 
} } // end objlock _5sxQbo4ocBH_0O96nRSvJV9 
/* !endingblock _5OqxK5JMgWp_4fzCg3OhXpz */ 
goto endblock__5OqxK5JMgWp_4fzCg3OhXpz; 
endblock__5OqxK5JMgWp_4fzCg3OhXpz: ; 
} /*-block _5OqxK5JMgWp_4fzCg3OhXpz */

 epilog_0FRLxSGQlZ0_0qrrUZlEeKp: __attribute__ ((unused)); // routine _0FRLxSGQlZ0_0qrrUZlEeKp epilogue:
   // unlocking 1:
    if (locked_5sxQbo4ocBH_0O96nRSvJV9 != NULL)
       objunlock_BM(locked_5sxQbo4ocBH_0O96nRSvJV9), locked_5sxQbo4ocBH_0O96nRSvJV9 = NULL; // for o_helem
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _0FRLxSGQlZ0_0qrrUZlEeKp routine#0 _0FRLxSGQlZ0_0qrrUZlEeKp




value_tyBM crout_4I0ksnAasRT_1bREYU29xgL_BM //#1
 (struct stackframe_stBM* stkf, //
//!emit-tagged-xhtml-open closed[v_htmltagstr v_htmlclass] (o_emitctx o_strbuf v_depth
  // 3 arguments
  const value_tyBM arg0,  // o_emitctx
  const value_tyBM arg1,  // o_strbuf
  const value_tyBM arg2,  // v_depth
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _4I0ksnAasRT_1bREYU29xgL
  struct frame_4I0ksnAasRT_1bREYU29xgL_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 8 local values:
    value_tyBM v_0wWVh40nozk_7OSKII1HZ6t; // v_htmlclass
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    value_tyBM v_6nmKmS2Auzh_04y9gBqgcDG; // v_htmltag
    value_tyBM v_6p6w3jZv5gy_58EzMDpOBQJ; // v_htmltagstr
    objectval_tyBM* o_9nXRmTATjN4_5F9V7RvvgW0; // o_emitctx
    value_tyBM v_9AuPELEBCEG_3r2aCy2y3Pc; // v_htmlclassstr
    /// 1 local numbers:
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
   } _;
   memset (&_, 0, sizeof(struct frame_4I0ksnAasRT_1bREYU29xgL_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 8;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[11] /*|_4I0ksnAasRT_1bREYU29xgL*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 3 arguments:
   _.o_9nXRmTATjN4_5F9V7RvvgW0 = objectcast_BM (arg0); // o_emitctx
   _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg1); // o_strbuf
   _.v_4nJKFtMqlkA_1teQSqofNux = arg2; // v_depth
   // fetched 3 arguments.
   { // fetch 2 closed values in _4I0ksnAasRT_1bREYU29xgL:
   const closure_tyBM* callclos_4I0ksnAasRT_1bREYU29xgL =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   unsigned nbclosed_4I0ksnAasRT_1bREYU29xgL = closurewidth_BM ((const value_tyBM) callclos_4I0ksnAasRT_1bREYU29xgL);
   if (nbclosed_4I0ksnAasRT_1bREYU29xgL > 0)
      _.v_6nmKmS2Auzh_04y9gBqgcDG = callclos_4I0ksnAasRT_1bREYU29xgL->nodt_sons[0]; // v_htmltag
   if (nbclosed_4I0ksnAasRT_1bREYU29xgL > 1)
      _.v_0wWVh40nozk_7OSKII1HZ6t = callclos_4I0ksnAasRT_1bREYU29xgL->nodt_sons[1]; // v_htmlclass
   } // fetched 2 closed values in _4I0ksnAasRT_1bREYU29xgL.
   // routine _4I0ksnAasRT_1bREYU29xgL body:

startblock__2PCK7wl7e0d_6aQ9RlUCxeL: __attribute__((unused));
{ /* +block _2PCK7wl7e0d_6aQ9RlUCxeL */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _4zMf8sV8fya_53ohURmAkaW  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 
{ // run _6XkQ3aFbGD7_5FNflVcnEs4 
/*debug emit-tagged-xhtml-open start [v_htmltag v_htmlclass] o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emit-tagged-xhtml-open start €%.9s [v_htmltag=%s v_htmlclass=%s] o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_6XkQ3aFbGD7_5FNflVcnEs4",
 OUTSTRVALUE_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG),
 OUTSTRVALUE_BM( /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t),
 objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _6XkQ3aFbGD7_5FNflVcnEs4 
 
//+ #2/6 of block _2PCK7wl7e0d_6aQ9RlUCxeL :: 
 
if /*cond _8hn8DdBoSyJ_1NJHIGIUSmC*/  
/*when _5m8rgu5ybDR_283DEYxs9JZ:*/ 
 (/*is_stringv:*/ isstring_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)) { //body when _5m8rgu5ybDR_283DEYxs9JZ  
 /*v_htmltagstr:*/_.v_6p6w3jZv5gy_58EzMDpOBQJ = //assign _12FBCA4Mpvy_0BXLkfklDpk   
 /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG;  
  
} //endwhen _5m8rgu5ybDR_283DEYxs9JZ  
else if  
/*when _41uV2yIAp43_2Yu4V5fz3ui:*/ 
 (/*is_objectv*/ isobject_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)) { //body when _41uV2yIAp43_2Yu4V5fz3ui  
 /*v_htmltagstr:*/_.v_6p6w3jZv5gy_58EzMDpOBQJ = //assign _78JdyxDQKal_4IDa5HpICUi   
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*val_to_object:*/objectcast_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[5] /*!html_tag*/))))));  
  
} //endwhen _41uV2yIAp43_2Yu4V5fz3ui  
/*endcond _8hn8DdBoSyJ_1NJHIGIUSmC*/ 
 
 
if /*cond _981Htnuqk2v_3f6kRQZBkNI*/  
/*when _5usxraGoWWN_2A5IJEfVFat:*/ 
 (/*is_stringv:*/ isstring_BM( /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t)) { //body when _5usxraGoWWN_2A5IJEfVFat  
 /*v_htmlclassstr:*/_.v_9AuPELEBCEG_3r2aCy2y3Pc = //assign _7YpZd8yYOAD_5IjRXGsTBUs   
 /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG;  
  
} //endwhen _5usxraGoWWN_2A5IJEfVFat  
else if  
/*when _3B2yJwjdy53_7VKdj7byIy6:*/ 
 (/*is_objectv*/ isobject_BM( /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t)) { //body when _3B2yJwjdy53_7VKdj7byIy6  
 /*v_htmlclassstr:*/_.v_9AuPELEBCEG_3r2aCy2y3Pc = //assign _2a9vb10NrAs_706MrL2b0eq   
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*val_to_object:*/objectcast_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[18] /*!html_class*/))))));  
  
} //endwhen _3B2yJwjdy53_7VKdj7byIy6  
/*endcond _981Htnuqk2v_3f6kRQZBkNI*/ 
 
//+ #4/6 of block _2PCK7wl7e0d_6aQ9RlUCxeL :: 
 
{ // start out _6r8MxUGERZ5_62WMoVCfmcU to o_strbuf  
/*out set_indent:*/ objstrbuffersetindentpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f);  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "<");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_htmltagstr:*/_.v_6p6w3jZv5gy_58EzMDpOBQJ)));  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " class=\'");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*strvalue:*/OUTSTRVALUE_BM((value_tyBM) /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t));  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "\' "); 
} // end out _6r8MxUGERZ5_62WMoVCfmcU 
 
 
/*return _7r8Nb0kzrtj_3ZwcXoiPUBk:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*v_htmltagstr:*/_.v_6p6w3jZv5gy_58EzMDpOBQJ; 
 goto epilog_4I0ksnAasRT_1bREYU29xgL; 
 
/* !endingblock _2PCK7wl7e0d_6aQ9RlUCxeL */ 
goto endblock__2PCK7wl7e0d_6aQ9RlUCxeL; 
endblock__2PCK7wl7e0d_6aQ9RlUCxeL: ; 
} /*-block _2PCK7wl7e0d_6aQ9RlUCxeL */

 epilog_4I0ksnAasRT_1bREYU29xgL: __attribute__ ((unused)); // routine _4I0ksnAasRT_1bREYU29xgL epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _4I0ksnAasRT_1bREYU29xgL routine#1 _4I0ksnAasRT_1bREYU29xgL




value_tyBM crout_5NH940lCHYJ_3nuRm3flnzc_BM //#2
 (struct stackframe_stBM* stkf, //
//!emitxhtml_element (o_helem o_emitctx o_strbuf v_depth)
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
    /// 12 local values:
    value_tyBM v_0iT9NuqVo8P_188wxqHeyJZ; // v_tagstr
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
   _.stkfram_head.rlen = 12;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[17] /*|_5NH940lCHYJ_3nuRm3flnzc*/;
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
/*debug emitxhtml_element start o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emitxhtml_element start €%.9s o_helem=%s o_emitctx=%s o_strbuf=%s/L%d depth#%ld",
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
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[20] /*!failure_non_object*/)), 
 /*make_node 4 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[17] /*!_5NH940lCHYJ_3nuRm3flnzc*/)), 
 
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
 (/*not:*/ (! (/*objectisinstance:*/ objectisinstance_BM(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[24] /*!html_element_object*/)))))) { //body when _6HtsKDbq7Rx_3rZ8uRwGNj9  
//failure _5rs4UfgeATT_3s7r48scObY   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[10] /*!failure_bad_class*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[24] /*!html_element_object*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[15] /*|_5rs4UfgeATT_3s7r48scObY*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _6HtsKDbq7Rx_3rZ8uRwGNj9  
/*endcond _921fuoujPIF_4a0JqUqMOyG*/ 
  
 /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r = //assign _4gqzOn4YRA4_4DeoI7Me5mK  
/*val_to_object:*/objectcast_BM((send2_BM (( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), /*sel:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[25] /*!html_spacing*/)), ((struct stackframe_stBM*)&_),  
 ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),  (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))); 
  
//+ #2/16 of lockobj _36l0VwmZ11o_8vCwWpg2xIB ::  
 /*indent:*/_.n_8SJIvFqUkH2_0UJyIX6eA9v = //assign _4hBaaJCUqMH_1BMwNQy5oBI  
/*objstrbufferindentationpayl:*/ objstrbufferindentationpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy); 
  
 
{ // run _5jZtyuntuuZ_2Lx45h0TXVc 
/*debug emitxhtml_element o_helem o_spacing o_emitctx indent depth*/
DBGPRINTF_BM("debug emitxhtml_element €%.9s o_helem=%s o_spacing=%s o_emitctx=%s indent#%ld depth#%ld",
 "_5jZtyuntuuZ_2Lx45h0TXVc",
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r),
 objectdbg2_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 (long int) ( /*indent:*/_.n_8SJIvFqUkH2_0UJyIX6eA9v),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _5jZtyuntuuZ_2Lx45h0TXVc 
  
//+ #4/16 of lockobj _36l0VwmZ11o_8vCwWpg2xIB ::  
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _5HcDhrmVMP2_2FuMdxilvQ9  
(send3_BM (( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), /*sel:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[19] /*!emit_xhtml_open*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),  ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)))); 
  
if /*cond _4Vd3Fe3lriq_1maa3fRM0K5*/  
/*when _2vrXQXG9ekP_2af2adhJ59X:*/ 
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _2vrXQXG9ekP_2af2adhJ59X  
//failure _5xGV4qXFkqJ_4imeaugtTzv   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[13] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[19] /*!emit_xhtml_open*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[16] /*|_5xGV4qXFkqJ_4imeaugtTzv*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _2vrXQXG9ekP_2af2adhJ59X  
else if  
/*when _0iLTTAPKDdM_4gInd3yL4do:*/ 
 (/*is_stringv:*/ isstring_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)) { //body when _0iLTTAPKDdM_4gInd3yL4do  
 /*v_tagstr:*/_.v_0iT9NuqVo8P_188wxqHeyJZ = //assign _0GEv7GVbDTY_97e6xWDQgBc   
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV;  
  
} //endwhen _0iLTTAPKDdM_4gInd3yL4do  
else { /*cond else _4Vd3Fe3lriq_1maa3fRM0K5*/  
//failure _8c3wK0SptYZ_6EpzaOaJVJc  
PLACEDFAILURE_BM(__LINE__,  
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[30] /*!failure_type_error*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[19] /*!emit_xhtml_open*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[26] /*|_8c3wK0SptYZ_6EpzaOaJVJc*/)),
                ((struct stackframe_stBM *) &_));
} /*cond else _4Vd3Fe3lriq_1maa3fRM0K5*/  
/*endcond _4Vd3Fe3lriq_1maa3fRM0K5*/ 
  
//+ #6/16 of lockobj _36l0VwmZ11o_8vCwWpg2xIB ::  
{ // start out _4WLSpdl7KlA_7HKN9l4ULP3 to o_strbuf  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, ">"); 
} // end out _4WLSpdl7KlA_7HKN9l4ULP3 
  
 
{ // run _5uHXmQzi0xh_3EeoqFXMNFU 
/*debug html_block after emit_xhtml_open v_resemit o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emitxhtml_element after emit_xhtml_open €%.9s v_resemit=%s o_helem=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_5uHXmQzi0xh_3EeoqFXMNFU",
 OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _5uHXmQzi0xh_3EeoqFXMNFU 
  
//+ #8/16 of lockobj _36l0VwmZ11o_8vCwWpg2xIB ::  
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
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[23] /*!nlsp*/)))) { //body when _8gbKuVOJ00d_0iXBwlmG6jd  
{ // start out _6nl4fxXo5P9_4aikEu7hcUs to o_strbuf   
/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);  
} // end out _6nl4fxXo5P9_4aikEu7hcUs  
  
} //endwhen _8gbKuVOJ00d_0iXBwlmG6jd  
else if  
/*when _0aSvuu44cW5_744SUn0a59q:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[4] /*!space*/)))) { //body when _0aSvuu44cW5_744SUn0a59q  
{ // start out _1B27ZtCrJSa_6rQN5QUVjoS to o_strbuf   
/*out space:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " ");  
} // end out _1B27ZtCrJSa_6rQN5QUVjoS  
  
} //endwhen _0aSvuu44cW5_744SUn0a59q  
/*endcond _9xbwkyekv7y_1dtd6RJgaaT*/ 
  
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _1O9tiQKy3ZB_4oLghWljER9  
/*objnbcomps:*/ objnbcomps_BM ( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW); 
  
//+ #10/16 of lockobj _36l0VwmZ11o_8vCwWpg2xIB ::  
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
/*debug  emitxhtml_element for-loop ii v_comp o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emitxhtml_element for-loop €%.9s ii#%ld v_comp=%s o_helem=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
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
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[23] /*!nlsp*/)))) { //body when _9lQbBHyLisB_9RbsRinLVVi   
{ // start out _0nMvmHfMjyF_5iZ1qqd9K8S to o_strbuf    
/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);   
} // end out _0nMvmHfMjyF_5iZ1qqd9K8S   
   
} //endwhen _9lQbBHyLisB_9RbsRinLVVi   
else if   
/*when _9BdaJn6vBWW_7n07rdHXudX:*/  
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[4] /*!space*/)))) { //body when _9BdaJn6vBWW_7n07rdHXudX   
{ // start out _6FxYfpCMqWj_2x1fBqLWf57 to o_strbuf    
/*out space:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " ");   
} // end out _6FxYfpCMqWj_2x1fBqLWf57   
   
} //endwhen _9BdaJn6vBWW_7n07rdHXudX   
/*endcond _9esS4NliRiB_2VgVZ0sULry*/  
  
// for-up _8QYxgALaJfV_49EojKGexX9 #3 :  
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _9WzUvoIHCSM_4O5lNZm3jb2   
(apply4_BM (( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[29] /*!emit_xhtml*/)), ((struct stackframe_stBM*)&_), 
 ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));  
  
// for-up _8QYxgALaJfV_49EojKGexX9 #4 :  
if /*cond _6JhK96miaMx_3XLltRct5WU*/   
/*when _7yndBSvwm1J_9N5z0dJuXIM:*/  
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _7yndBSvwm1J_9N5z0dJuXIM   
//failure _51oIiJoCulz_1NyarSIagfB    
PLACEDFAILURE_BM(__LINE__,    
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[13] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[29] /*!emit_xhtml*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[12] /*|_51oIiJoCulz_1NyarSIagfB*/)),
                ((struct stackframe_stBM *) &_));
   
} //endwhen _7yndBSvwm1J_9N5z0dJuXIM   
/*endcond _6JhK96miaMx_3XLltRct5WU*/  
 
}} // end for-up _8QYxgALaJfV_49EojKGexX9 
  
{ // start cexpansion _11rqSXWIScp_7YYIjuSNRED - objstrbuffersetindentpayl  
/*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), ( /*indent:*/_.n_8SJIvFqUkH2_0UJyIX6eA9v));  
} // end cexpansion _11rqSXWIScp_7YYIjuSNRED - objstrbuffersetindentpayl  
  
//+ #12/16 of lockobj _36l0VwmZ11o_8vCwWpg2xIB ::  
if /*cond _8Vnn5fbTxZD_5r0Nn4OLpXW*/  
/*when _7Tqp9FaGOi6_1zlNZrsr3P4:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[2] /*!newline*/)))) { //body when _7Tqp9FaGOi6_1zlNZrsr3P4  
{ // start out _5xthhfX2qlp_6rUZ8Mn7fG9 to o_strbuf   
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);  
} // end out _5xthhfX2qlp_6rUZ8Mn7fG9  
  
} //endwhen _7Tqp9FaGOi6_1zlNZrsr3P4  
else if  
/*when _26hfrrkoYbw_0EsJYF6nzjS:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[23] /*!nlsp*/)))) { //body when _26hfrrkoYbw_0EsJYF6nzjS  
{ // start out _8ALxuahzjVn_9JyrNMc4dcs to o_strbuf   
/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);  
} // end out _8ALxuahzjVn_9JyrNMc4dcs  
  
} //endwhen _26hfrrkoYbw_0EsJYF6nzjS  
else if  
/*when _4c7whFwVYld_6KcIS6aV9Yf:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[4] /*!space*/)))) { //body when _4c7whFwVYld_6KcIS6aV9Yf  
{ // start out _74KTDkonWj7_1nFV9AC8hqV to o_strbuf   
/*out space:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " ");  
} // end out _74KTDkonWj7_1nFV9AC8hqV  
  
} //endwhen _4c7whFwVYld_6KcIS6aV9Yf  
/*endcond _8Vnn5fbTxZD_5r0Nn4OLpXW*/ 
  
{ // start out _3hATsOiAE0P_5lR9awJKBzu to o_strbuf  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "</");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_tagstr:*/_.v_0iT9NuqVo8P_188wxqHeyJZ)));  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, ">"); 
} // end out _3hATsOiAE0P_5lR9awJKBzu 
  
//+ #14/16 of lockobj _36l0VwmZ11o_8vCwWpg2xIB ::  
 
{ // run _1k3HHXqIxKk_5nxA2F1eZlb 
/*debug end emitxhtml_element v_tagstr o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("debug end emitxhtml_element €%.9s v_tagstr=%s o_helem=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_1k3HHXqIxKk_5nxA2F1eZlb",
 OUTSTRVALUE_BM( /*v_tagstr:*/_.v_0iT9NuqVo8P_188wxqHeyJZ),
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
; 
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
} // end _5NH940lCHYJ_3nuRm3flnzc routine#2 _5NH940lCHYJ_3nuRm3flnzc




value_tyBM crout_6TYtJU0rl2h_2z4md7DV06z_BM //#3
 (struct stackframe_stBM* stkf, //
//!root-web-handler
  // 2 arguments
  const value_tyBM arg0,  // v_restpath
  const value_tyBM arg1,  // o_webex
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _6TYtJU0rl2h_2z4md7DV06z
  struct frame_6TYtJU0rl2h_2z4md7DV06z_BMst {
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
   memset (&_, 0, sizeof(struct frame_6TYtJU0rl2h_2z4md7DV06z_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 3;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[21] /*|_6TYtJU0rl2h_2z4md7DV06z*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 2 arguments:
   _.v_6QhNRfe1Cte_0niVlWfAlmO = arg0; // v_restpath
   _.o_5JuT4FgNFFh_7McrTYeT3jx = objectcast_BM (arg1); // o_webex
   // fetched 2 arguments.
   // no closed values in _6TYtJU0rl2h_2z4md7DV06z.
   // routine _6TYtJU0rl2h_2z4md7DV06z body:

startblock__6eHKA5eSoIV_4ajeKi1n1so: __attribute__((unused));
{ /* +block _6eHKA5eSoIV_4ajeKi1n1so */ 
 
{ // run _73hzmEhVjDY_2atb4XvtEi9 
/*debug root-web-handler start v_restpath o_webex*/
DBGPRINTF_BM("root-web-handler €%.9s start v_restpath=%s o_webex=%s",
"_73hzmEhVjDY_2atb4XvtEi9",
 OUTSTRVALUE_BM( /*v_restpath:*/_.v_6QhNRfe1Cte_0niVlWfAlmO),
 objectdbg_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx));
; 
} // end run _73hzmEhVjDY_2atb4XvtEi9 
 
/* !endingblock _6eHKA5eSoIV_4ajeKi1n1so */ 
goto endblock__6eHKA5eSoIV_4ajeKi1n1so; 
endblock__6eHKA5eSoIV_4ajeKi1n1so: ; 
} /*-block _6eHKA5eSoIV_4ajeKi1n1so */

 epilog_6TYtJU0rl2h_2z4md7DV06z: __attribute__ ((unused)); // routine _6TYtJU0rl2h_2z4md7DV06z epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _6TYtJU0rl2h_2z4md7DV06z routine#3 _6TYtJU0rl2h_2z4md7DV06z




value_tyBM crout_8IYFtn8osS2_4t1U3wyROLW_BM //#4+
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
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[29] /*|emit_xhtml*/;
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
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[6] /*!failure_full*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[29] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[28] /*|_8yowRQLZgzP_4vqWjo12OS4*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _70ZSzCpjqWE_1AjclUpwXjD  
/*endcond _8hRp9kZ7uvu_4MzyhRQIoRd*/ 
 
 
if /*cond _24sbIpdvwNd_9c4S4cSYLYE*/  
/*when _0lnsrM6CMWA_4PCoTTYLR3e:*/ 
 ((/*greater_int:*/( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) > ( 100))) { //body when _0lnsrM6CMWA_4PCoTTYLR3e  
//failure _79ub6Ngc5aa_42TtfuLTsPs   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[13] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[29] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[22] /*|_79ub6Ngc5aa_42TtfuLTsPs*/)),
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
} // end _8IYFtn8osS2_4t1U3wyROLW routine#4 emit_xhtml




value_tyBM crout_9hEreAemqXg_0uoN1Fr1ly4_BM //#5
 (struct stackframe_stBM* stkf, //
//!emit-tagged-id-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget] (o_emitctx o_strbuf v_depth)
  // 3 arguments
  const value_tyBM arg0,  // o_emitctx
  const value_tyBM arg1,  // o_strbuf
  const value_tyBM arg2,  // v_depth
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _9hEreAemqXg_0uoN1Fr1ly4
  struct frame_9hEreAemqXg_0uoN1Fr1ly4_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 11 local values:
    value_tyBM v_0wWVh40nozk_7OSKII1HZ6t; // v_htmlclass
    objectval_tyBM* o_1E1n1xq22bH_7JEWM863KYo; // o_idtarget
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    value_tyBM v_6nmKmS2Auzh_04y9gBqgcDG; // v_htmltag
    value_tyBM v_6p6w3jZv5gy_58EzMDpOBQJ; // v_htmltagstr
    value_tyBM v_6wh43lYjXiZ_9MUWTOiTsOl; // v_idprefixstr
    value_tyBM v_8VgHiZPlXwn_5i6tFD7vAVB; // v_idprefix
    objectval_tyBM* o_9nXRmTATjN4_5F9V7RvvgW0; // o_emitctx
    value_tyBM v_9AuPELEBCEG_3r2aCy2y3Pc; // v_htmlclassstr
    /// 1 local numbers:
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
   } _;
   memset (&_, 0, sizeof(struct frame_9hEreAemqXg_0uoN1Fr1ly4_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 11;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[31] /*|_9hEreAemqXg_0uoN1Fr1ly4*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 3 arguments:
   _.o_9nXRmTATjN4_5F9V7RvvgW0 = objectcast_BM (arg0); // o_emitctx
   _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg1); // o_strbuf
   _.v_4nJKFtMqlkA_1teQSqofNux = arg2; // v_depth
   // fetched 3 arguments.
   { // fetch 4 closed values in _9hEreAemqXg_0uoN1Fr1ly4:
   const closure_tyBM* callclos_9hEreAemqXg_0uoN1Fr1ly4 =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   unsigned nbclosed_9hEreAemqXg_0uoN1Fr1ly4 = closurewidth_BM ((const value_tyBM) callclos_9hEreAemqXg_0uoN1Fr1ly4);
   if (nbclosed_9hEreAemqXg_0uoN1Fr1ly4 > 0)
      _.v_6nmKmS2Auzh_04y9gBqgcDG = callclos_9hEreAemqXg_0uoN1Fr1ly4->nodt_sons[0]; // v_htmltag
   if (nbclosed_9hEreAemqXg_0uoN1Fr1ly4 > 1)
      _.v_0wWVh40nozk_7OSKII1HZ6t = callclos_9hEreAemqXg_0uoN1Fr1ly4->nodt_sons[1]; // v_htmlclass
   if (nbclosed_9hEreAemqXg_0uoN1Fr1ly4 > 2)
      _.v_8VgHiZPlXwn_5i6tFD7vAVB = callclos_9hEreAemqXg_0uoN1Fr1ly4->nodt_sons[2]; // v_idprefix
   if (nbclosed_9hEreAemqXg_0uoN1Fr1ly4 > 3)
      _.o_1E1n1xq22bH_7JEWM863KYo = objectcast_BM (callclos_9hEreAemqXg_0uoN1Fr1ly4->nodt_sons[3]); // o_idtarget
   } // fetched 4 closed values in _9hEreAemqXg_0uoN1Fr1ly4.
   // routine _9hEreAemqXg_0uoN1Fr1ly4 body:

startblock__0dR2udLAHI6_6XdsSwwp24Y: __attribute__((unused));
{ /* +block _0dR2udLAHI6_6XdsSwwp24Y */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _6R8abmMrOpU_5KYbLDXna5m  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 
{ // run _8iXI2RBp3Co_7oVgdUnvUGT 
/*debug start emit-tagged-id-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget] o_emitctx o_strbuf depth*/
DBGPRINTF_BM("start emit-tagged-id-xhtml-open €%.9s [v_htmltag=%s v_htmlclass=%s v_idprefix=%s o_idtarget=%s] o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_8iXI2RBp3Co_7oVgdUnvUGT",
 OUTSTRVALUE_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG),
 OUTSTRVALUE_BM( /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t),
 OUTSTRVALUE_BM( /*v_idprefix:*/_.v_8VgHiZPlXwn_5i6tFD7vAVB),
 objectdbg_BM( /*o_idtarget:*/_.o_1E1n1xq22bH_7JEWM863KYo),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
; 
} // end run _8iXI2RBp3Co_7oVgdUnvUGT 
 
//+ #2/8 of block _0dR2udLAHI6_6XdsSwwp24Y :: 
 
if /*cond _8hn8DdBoSyJ_1NJHIGIUSmC*/  
/*when _5m8rgu5ybDR_283DEYxs9JZ:*/ 
 (/*is_stringv:*/ isstring_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)) { //body when _5m8rgu5ybDR_283DEYxs9JZ  
 /*v_htmltagstr:*/_.v_6p6w3jZv5gy_58EzMDpOBQJ = //assign _12FBCA4Mpvy_0BXLkfklDpk   
 /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG;  
  
} //endwhen _5m8rgu5ybDR_283DEYxs9JZ  
else if  
/*when _41uV2yIAp43_2Yu4V5fz3ui:*/ 
 (/*is_objectv*/ isobject_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)) { //body when _41uV2yIAp43_2Yu4V5fz3ui  
 /*v_htmltagstr:*/_.v_6p6w3jZv5gy_58EzMDpOBQJ = //assign _78JdyxDQKal_4IDa5HpICUi   
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*val_to_object:*/objectcast_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[5] /*!html_tag*/))))));  
  
} //endwhen _41uV2yIAp43_2Yu4V5fz3ui  
/*endcond _8hn8DdBoSyJ_1NJHIGIUSmC*/ 
 
 
if /*cond _981Htnuqk2v_3f6kRQZBkNI*/  
/*when _5usxraGoWWN_2A5IJEfVFat:*/ 
 (/*is_stringv:*/ isstring_BM( /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t)) { //body when _5usxraGoWWN_2A5IJEfVFat  
 /*v_htmlclassstr:*/_.v_9AuPELEBCEG_3r2aCy2y3Pc = //assign _7YpZd8yYOAD_5IjRXGsTBUs   
 /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG;  
  
} //endwhen _5usxraGoWWN_2A5IJEfVFat  
else if  
/*when _3B2yJwjdy53_7VKdj7byIy6:*/ 
 (/*is_objectv*/ isobject_BM( /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t)) { //body when _3B2yJwjdy53_7VKdj7byIy6  
 /*v_htmlclassstr:*/_.v_9AuPELEBCEG_3r2aCy2y3Pc = //assign _2a9vb10NrAs_706MrL2b0eq   
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*val_to_object:*/objectcast_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[18] /*!html_class*/))))));  
  
} //endwhen _3B2yJwjdy53_7VKdj7byIy6  
/*endcond _981Htnuqk2v_3f6kRQZBkNI*/ 
 
//+ #4/8 of block _0dR2udLAHI6_6XdsSwwp24Y :: 
 
{ // start out _6r8MxUGERZ5_62WMoVCfmcU to o_strbuf  
/*out set_indent:*/ objstrbuffersetindentpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f);  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "<");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_htmltagstr:*/_.v_6p6w3jZv5gy_58EzMDpOBQJ)));  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " class=\'");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*strvalue:*/OUTSTRVALUE_BM((value_tyBM) /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t));  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "\' "); 
} // end out _6r8MxUGERZ5_62WMoVCfmcU 
 
 
if /*cond _9H0L8bKRxNs_6ZLNYQisXhr*/  
/*when _5hTO8jel9Ue_6QWB47yIsER:*/ 
 (/*is_stringv:*/ isstring_BM( /*v_idprefix:*/_.v_8VgHiZPlXwn_5i6tFD7vAVB)) { //body when _5hTO8jel9Ue_6QWB47yIsER  
 /*v_idprefixstr:*/_.v_6wh43lYjXiZ_9MUWTOiTsOl = //assign _62v6ixdHaSA_1TrwtLNRmOO   
 /*v_idprefix:*/_.v_8VgHiZPlXwn_5i6tFD7vAVB;  
  
} //endwhen _5hTO8jel9Ue_6QWB47yIsER  
else if  
/*when _8L1ziPttLIT_5je6y8T504n:*/ 
 (/*is_objectv*/ isobject_BM( /*v_idprefix:*/_.v_8VgHiZPlXwn_5i6tFD7vAVB)) { //body when _8L1ziPttLIT_5je6y8T504n  
 /*v_idprefixstr:*/_.v_6wh43lYjXiZ_9MUWTOiTsOl = //assign _5ZAPBREw0Vk_04Cwl67pjmm   
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*object_cast:*/(value_tyBM)objectcast_BM( /*v_idprefix:*/_.v_8VgHiZPlXwn_5i6tFD7vAVB)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[27] /*!html_idprefix*/))))));  
  
} //endwhen _8L1ziPttLIT_5je6y8T504n  
/*endcond _9H0L8bKRxNs_6ZLNYQisXhr*/ 
 
//+ #6/8 of block _0dR2udLAHI6_6XdsSwwp24Y :: 
 
if /*cond _2e8g1RnPvBb_8sEgpX6OvDV*/  
/*when _0ACVDQefshl_2vjIsEKkehH:*/ 
 () { //body when _0ACVDQefshl_2vjIsEKkehH  
{ // start out _3eX4xI1qz71_3l5LcBP4Yyh to o_strbuf   
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "id=\'");   
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_idprefixstr:*/_.v_6wh43lYjXiZ_9MUWTOiTsOl)));   
/*out id:*/ char idbuf_3eX4xI1qz71_3l5LcBP4Yyh_n2[32]={0};   
idtocbuf32_BM (objid_BM( /*o_idtarget:*/_.o_1E1n1xq22bH_7JEWM863KYo), idbuf_3eX4xI1qz71_3l5LcBP4Yyh_n2);   
objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, idbuf_3eX4xI1qz71_3l5LcBP4Yyh_n2);   
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "\' ");  
} // end out _3eX4xI1qz71_3l5LcBP4Yyh  
  
} //endwhen _0ACVDQefshl_2vjIsEKkehH  
/*endcond _2e8g1RnPvBb_8sEgpX6OvDV*/ 
 
 
/*return _7r8Nb0kzrtj_3ZwcXoiPUBk:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*v_htmltagstr:*/_.v_6p6w3jZv5gy_58EzMDpOBQJ; 
 goto epilog_9hEreAemqXg_0uoN1Fr1ly4; 
 
/* !endingblock _0dR2udLAHI6_6XdsSwwp24Y */ 
goto endblock__0dR2udLAHI6_6XdsSwwp24Y; 
endblock__0dR2udLAHI6_6XdsSwwp24Y: ; 
} /*-block _0dR2udLAHI6_6XdsSwwp24Y */

 epilog_9hEreAemqXg_0uoN1Fr1ly4: __attribute__ ((unused)); // routine _9hEreAemqXg_0uoN1Fr1ly4 epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _9hEreAemqXg_0uoN1Fr1ly4 routine#5 _9hEreAemqXg_0uoN1Fr1ly4




// end of 6 generated routines


// the constant ids for 32 constants:
const char* const constid_9dQJgjsq7hs_2T2RqXLkU0A_BM[32+1] = {
 /*0:*/
 "_0FRLxSGQlZ0_0qrrUZlEeKp", //! emitxhtml_void_element (o_helem o_emitctx o_strbuf v_depth)
 "_2ekmsdDpheM_8iSH1r9pS9e", //! fail non-object emitxhtml_element o_emitctx o_strbuf depth
 "_2wGWzItVmrN_2CBwG6iHWFO",//newline
 "_33eRuL6abjL_4uGwIWu51cd", //! else fail-miss emitxhtml_void_element v_resemit o_helem o_emitctx o_strbuf depth
 "_35gLacRFhq5_90zAPxiDIlh",//space
 /*5:*/
 "_3sJy6RT5X9u_1r0Sucfx4np",//html_tag
 "_3zzOJ9b7sUf_89ZOhP1HlUQ",//failure_full
 "_3EfvM2lT7h3_8fHXQsltxSG", //! fail-badclass emitxhtml_void_element 
 "_3ECxU06gRdk_8uZReHKm10m", //! fail-type_error emitxhtml_void_element v_resemit o_helem o_emitctx o_strbuf depth
 "_4nCl6kh6zgK_8WQFqxe24i2", //! fail-type_error html_void_element o_helem o_emitctx o_strbuf depth / emitxhtml_void_element
 /*10:*/
 "_4HgYLk6htvP_4Ac2FCPfQ1C",//failure_bad_class
 "_4I0ksnAasRT_1bREYU29xgL", //! emit-tagged-xhtml-open closed[v_htmltagstr v_htmlclass] (o_emitctx o_strbuf v_depth
 "_51oIiJoCulz_1NyarSIagfB", //! fail-miss emit_xhtml v_comp ii o_emitctx o_strbuf depth
 "_52XwytpOPVl_3ZjmQCtadbK",//failure_miss
 "_5ov2KpemmVg_0cMgvKrBTvJ",//html_void_element_object
 /*15:*/
 "_5rs4UfgeATT_3s7r48scObY", //! fail-bad-class html_element_object o_helem o_emitctx o_strbuf depth - emitxhtml_element
 "_5xGV4qXFkqJ_4imeaugtTzv", //! fail-miss emit_xhtml_open _helem o_emitctx depth
 "_5NH940lCHYJ_3nuRm3flnzc", //! emitxhtml_element (o_helem o_emitctx o_strbuf v_depth)
 "_5RD0QJ0X5kp_8vHHK68Qn2R",//html_class
 "_64Nwpjx4gnk_2y263bTCaB3",//emit_xhtml_open
 /*20:*/
 "_6yWldsq3Rmk_01WqTfwSIDV",//failure_non_object
 "_6TYtJU0rl2h_2z4md7DV06z", //! root-web-handler
 "_79ub6Ngc5aa_42TtfuLTsPs", //! fail failure_miss emit_xhtml v_html o_emitctx depth // too deep
 "_7coI3Hezrvp_6CG1u3MlT83",//nlsp
 "_7FvfalQCaxj_24GCf5CtIWh",//html_element_object
 /*25:*/
 "_84d7WOdRsJh_4Ud9BryxYUr",//html_spacing
 "_8c3wK0SptYZ_6EpzaOaJVJc", //! fail-type_error emit_xhtml_open o_helem o_emitctx o_strbuf depth /emitxhtml_element
 "_8mOOvH4LOKB_5gaXDGw68tw",//html_idprefix
 "_8yowRQLZgzP_4vqWjo12OS4", //! fail failure_full emit_xhtml v_html o_emitctx depth
 "_8IYFtn8osS2_4t1U3wyROLW",//emit_xhtml
 /*30:*/
 "_95hdJENHNkN_3QuKIJTCQQQ",//failure_type_error
 "_9hEreAemqXg_0uoN1Fr1ly4", //! emit-tagged-id-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget] (o_emitctx o_strbuf v_depth)
 NULL}; // end 32 constant ids



// the routine ids for 6 routines:
const char* const routid_9dQJgjsq7hs_2T2RqXLkU0A_BM[6+1] = {
  /*0:*/
  "_0FRLxSGQlZ0_0qrrUZlEeKp", //!emitxhtml_void_element (o_helem o_emitctx o_strbuf v_depth)
  "_4I0ksnAasRT_1bREYU29xgL", //!emit-tagged-xhtml-open closed[v_htmltagstr v_htmlclass] (o_emitctx o_strbuf v_depth
  "_5NH940lCHYJ_3nuRm3flnzc", //!emitxhtml_element (o_helem o_emitctx o_strbuf v_depth)
  "_6TYtJU0rl2h_2z4md7DV06z", //!root-web-handler
  "_8IYFtn8osS2_4t1U3wyROLW",//emit_xhtml
  "_9hEreAemqXg_0uoN1Fr1ly4", //!emit-tagged-id-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget] (o_emitctx o_strbuf v_depth)

 NULL}; // end 6 routine ids



// basiclo*module initialization
#ifdef BISMON_MODID
value_tyBM moduleinit_9dQJgjsq7hs_2T2RqXLkU0A_BM
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
} // end moduleinit_9dQJgjsq7hs_2T2RqXLkU0A_BM
#endif /*BISMON_MODID*/



// end of generated persistent module webxhtml_module in file modbm_9dQJgjsq7hs_2T2RqXLkU0A.c
