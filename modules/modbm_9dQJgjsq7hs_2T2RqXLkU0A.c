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



// declare 12 routines

extern const char *const routid_9dQJgjsq7hs_2T2RqXLkU0A_BM[12+1];


// 23 failures

extern objrout_sigBM crout_0FRLxSGQlZ0_0qrrUZlEeKp_BM; //#0 !emitxhtml_void_element (o_helem o_emitctx o_strbuf v_depth)

extern objrout_sigBM crout_0NH2lnQIrTb_7Kt3mvQUoVu_BM; //#1 !emit_xhtml_open°simple_html_element_object < o_helem (o_emitctx o_strbuf v_depth)

extern objrout_sigBM crout_2Uksq9GtGL5_6mG06OtMZF1_BM; //#2 !emit-src-from-webssesion-web_theme (o_helem o_websess o_strbuf depth)

extern objrout_sigBM crout_4xwDKklt2v4_2lEbck0j4qs_BM; //#3 !html_spacing°simple*html*element < o_helem (o_emitctx v_depth)

extern objrout_sigBM crout_4I0ksnAasRT_1bREYU29xgL_BM; //#4 !emit-tagged-xhtml-open [v_htmltag v_htmlclass] (o_helem o_emitctx o_strbuf v_depth)

extern objrout_sigBM crout_5NH940lCHYJ_3nuRm3flnzc_BM; //#5 !emitxhtml_element (o_helem o_emitctx o_strbuf v_depth)

extern objrout_sigBM crout_6RtF29C4pij_9r269Lc0d0W_BM; //#6 !emit_xhtml_open°simple_void_html_element_object < o_helem (o_emitctx o_strbuf v_depth)

extern objrout_sigBM crout_6TYtJU0rl2h_2z4md7DV06z_BM; //#7 !root-web-handler (v_restpath o_webex)

extern objrout_sigBM crout_85938GaqS1z_3mZSenKG7GG_BM; //#8 !emit-tagged-id-more-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget v_more] (o_helem o_emitctx o_strbuf v_depth)

extern objrout_sigBM crout_8oKFbiPI4JW_7EPg4RP1e4Q_BM; //#9 !emit-raw-tag-xhtml-open [v_tagstr v_restagstr] (o_helem o_emitctx o_strbuf v_depth)

extern objrout_sigBM crout_8IYFtn8osS2_4t1U3wyROLW_BM; //#10 emit_xhtml

extern objrout_sigBM crout_9hEreAemqXg_0uoN1Fr1ly4_BM; //#11 !emit-tagged-id-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget] (o_helem o_emitctx o_strbuf v_depth)


// declare 74 constants
objectval_tyBM* constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[74+1];
const char* const constid_9dQJgjsq7hs_2T2RqXLkU0A_BM[74+1];


// define 12 routines


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
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[3] /*|_0FRLxSGQlZ0_0qrrUZlEeKp*/;
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
 (/*not:*/ (! (/*objectisinstance:*/ objectisinstance_BM(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[41] /*!html_void_element_object*/)))))) { //body when _70NLVhtnim4_46BJ6K9hmTk  
//failure _4nCl6kh6zgK_8WQFqxe24i2   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[71] /*!failure_type_error*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[41] /*!html_void_element_object*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[29] /*|_4nCl6kh6zgK_8WQFqxe24i2*/)),
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
 (/*not:*/ (! (/*objectisinstance:*/ objectisinstance_BM(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[41] /*!html_void_element_object*/)))))) { //body when _07EuRmnWGXF_5vxo4maeUAi  
//failure _3EfvM2lT7h3_8fHXQsltxSG   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[34] /*!failure_bad_class*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[3] /*!_0FRLxSGQlZ0_0qrrUZlEeKp*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[21] /*|_3EfvM2lT7h3_8fHXQsltxSG*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _07EuRmnWGXF_5vxo4maeUAi  
/*endcond _4Wn7pRPmEIx_0mreF5MM3NE*/ 
  
//+ #2/7 of lockobj _5sxQbo4ocBH_0O96nRSvJV9 ::  
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _5HcDhrmVMP2_2FuMdxilvQ9  
(send3_BM (( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), /*sel:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[46] /*!emit_xhtml_open*/)), ((struct stackframe_stBM*)&_), 
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
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[71] /*!failure_type_error*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[3] /*!_0FRLxSGQlZ0_0qrrUZlEeKp*/)), 
 
( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[22] /*|_3ECxU06gRdk_8uZReHKm10m*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _44cEV8LtWCy_4fX3McNsNmP  
else { /*cond else _2jBO1fnZqEm_79Y6lkBP9by*/  
//failure _33eRuL6abjL_4uGwIWu51cd  
PLACEDFAILURE_BM(__LINE__,  
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[40] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[3] /*!_0FRLxSGQlZ0_0qrrUZlEeKp*/)), 
 
( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[16] /*|_33eRuL6abjL_4uGwIWu51cd*/)),
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




value_tyBM crout_0NH2lnQIrTb_7Kt3mvQUoVu_BM //#1
 (struct stackframe_stBM* stkf, //
//!emit_xhtml_open°simple_html_element_object < o_helem (o_emitctx o_strbuf v_depth)
  // 4 arguments
  const value_tyBM arg0,  // o_helem
  const value_tyBM arg1,  // o_emitctx
  const value_tyBM arg2,  // o_strbuf
  const value_tyBM arg3,  // v_depth
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _0NH2lnQIrTb_7Kt3mvQUoVu
  struct frame_0NH2lnQIrTb_7Kt3mvQUoVu_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 8 local values:
    value_tyBM v_0qTBOEAT5pa_2fz1SKfHrMV; // v_resemit
    value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    objectval_tyBM* o_6Ef2ORO1Mni_0tpNoRQGmrW; // o_helem
    value_tyBM v_6KzoPNta5a2_7EsZceEn0Px; // v_clos
    objectval_tyBM* o_9nXRmTATjN4_5F9V7RvvgW0; // o_emitctx
    /// 1 local numbers:
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
   } _;
   memset (&_, 0, sizeof(struct frame_0NH2lnQIrTb_7Kt3mvQUoVu_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 8;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[4] /*|_0NH2lnQIrTb_7Kt3mvQUoVu*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 4 arguments:
   _.o_6Ef2ORO1Mni_0tpNoRQGmrW = objectcast_BM (arg0); // o_helem
   _.o_9nXRmTATjN4_5F9V7RvvgW0 = objectcast_BM (arg1); // o_emitctx
   _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg2); // o_strbuf
   _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
   // fetched 4 arguments.
   // no closed values in _0NH2lnQIrTb_7Kt3mvQUoVu.
   // routine _0NH2lnQIrTb_7Kt3mvQUoVu body:

startblock__5lJoYIhtFKG_8s9jow2GLIp: __attribute__((unused));
{ /* +block _5lJoYIhtFKG_8s9jow2GLIp */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _5cgc6snNLpL_6eLKUcOit2O  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px = //assign _7yAtINJUXoh_8n4bqYuxD2N  
/*closure_cast:*/(value_tyBM) closurecast_BM(/*objgetattr:*/objgetattr_BM(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[46] /*!emit_xhtml_open*/)))); 
 
//+ #2/7 of block _5lJoYIhtFKG_8s9jow2GLIp :: 
 
 
{ // run _1msgG5VfZi2_6cBVdsOpHC6 
/*debug emit_xhtml_open°simple_html_element_object start o_helem o_emitctx o_strbuf depth v_clos*/
DBGPRINTF_BM("emit_xhtml_open°simple_html_element_object start €%.9s o_helem=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld v_clos=%s",
 "_1msgG5VfZi2_6cBVdsOpHC6",
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
 OUTSTRVALUE_BM( /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px));; 
} // end run _1msgG5VfZi2_6cBVdsOpHC6 
 
 
if /*cond _60FShy2kmrm_6V6aO7tCgQR*/  
/*when _9XJqGBAn8gX_4Kg4UasfQqv:*/ 
 (/*is_null:*/(( /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px)==NULL)) { //body when _9XJqGBAn8gX_4Kg4UasfQqv  
//failure _6L4mPBNfWGs_5PaIqa8vfVo   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[40] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px)))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[50] /*|_6L4mPBNfWGs_5PaIqa8vfVo*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _9XJqGBAn8gX_4Kg4UasfQqv  
/*endcond _60FShy2kmrm_6V6aO7tCgQR*/ 
 
//+ #4/7 of block _5lJoYIhtFKG_8s9jow2GLIp :: 
 
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _65qrSACywrm_8v3f3wdrNZc  
(apply4_BM (( /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px), ((struct stackframe_stBM*)&_), 
 ( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)))); 
 
 
 
{ // run _9jbaFRMsnTE_68Vclk57gxs 
/*debug emit_xhtml_open°simple_html_element_object end v_resemit o_helem o_strbuf depth*/
DBGPRINTF_BM("emit_xhtml_open°simple_html_element_object end €%.9s v_resemit=%s o_helem=%s o_strbuf=%s/L%u depth#%ld",
 "_9jbaFRMsnTE_68Vclk57gxs",
 OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _9jbaFRMsnTE_68Vclk57gxs 
 
 
/*return _1QaljtTkdDu_6BGawawZys3:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV; 
 goto epilog_0NH2lnQIrTb_7Kt3mvQUoVu; 
 
/* !endingblock _5lJoYIhtFKG_8s9jow2GLIp */ 
goto endblock__5lJoYIhtFKG_8s9jow2GLIp; 
endblock__5lJoYIhtFKG_8s9jow2GLIp: ; 
} /*-block _5lJoYIhtFKG_8s9jow2GLIp */

 epilog_0NH2lnQIrTb_7Kt3mvQUoVu: __attribute__ ((unused)); // routine _0NH2lnQIrTb_7Kt3mvQUoVu epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _0NH2lnQIrTb_7Kt3mvQUoVu routine#1 _0NH2lnQIrTb_7Kt3mvQUoVu




value_tyBM crout_2Uksq9GtGL5_6mG06OtMZF1_BM //#2
 (struct stackframe_stBM* stkf, //
//!emit-src-from-webssesion-web_theme (o_helem o_websess o_strbuf depth)
  // 4 arguments
  const value_tyBM arg0,  // o_helem
  const value_tyBM arg1,  // o_websess
  const value_tyBM arg2,  // o_strbuf
  const value_tyBM arg3,  // v_depth
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _2Uksq9GtGL5_6mG06OtMZF1
  struct frame_2Uksq9GtGL5_6mG06OtMZF1_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 7 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    objectval_tyBM* o_6cRlOymtk44_3dId2Eescrt; // o_theme
    objectval_tyBM* o_6Ef2ORO1Mni_0tpNoRQGmrW; // o_helem
    value_tyBM v_7KirpiCMhmI_0IfcivXUJfQ; // v_filepath
    objectval_tyBM* o_7UzdV9wjuq2_2PRgXcyAlMi; // o_websess
    /// 1 local numbers:
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
   } _;
   memset (&_, 0, sizeof(struct frame_2Uksq9GtGL5_6mG06OtMZF1_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 7;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[14] /*|_2Uksq9GtGL5_6mG06OtMZF1*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 4 arguments:
   _.o_6Ef2ORO1Mni_0tpNoRQGmrW = objectcast_BM (arg0); // o_helem
   _.o_7UzdV9wjuq2_2PRgXcyAlMi = objectcast_BM (arg1); // o_websess
   _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg2); // o_strbuf
   _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
   // fetched 4 arguments.
   // no closed values in _2Uksq9GtGL5_6mG06OtMZF1.
   // routine _2Uksq9GtGL5_6mG06OtMZF1 body:

startblock__2Qv627ZT2Ot_42KOOsZ6KSp: __attribute__((unused));
{ /* +block _2Qv627ZT2Ot_42KOOsZ6KSp */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _4h9uPqBNnWr_3s6oq6U7FSm  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 
{ // run _2ex7cd3Qxpu_66AaUE18PBC 
/*debug start emit-src-from-webssesion-web_theme o_helem o_websess o_strbuf depth*/
DBGPRINTF_BM("debug start emit-src-from-webssesion-web_theme €%.9s o_helem=%s o_websess=%s o_strbuf=%s/L%u depth#%ld",
 "_2ex7cd3Qxpu_66AaUE18PBC",
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_websess:*/_.o_7UzdV9wjuq2_2PRgXcyAlMi),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
; 
} // end run _2ex7cd3Qxpu_66AaUE18PBC 
 
/* !endingblock _2Qv627ZT2Ot_42KOOsZ6KSp */ 
goto endblock__2Qv627ZT2Ot_42KOOsZ6KSp; 
endblock__2Qv627ZT2Ot_42KOOsZ6KSp: ; 
} /*-block _2Qv627ZT2Ot_42KOOsZ6KSp */

 epilog_2Uksq9GtGL5_6mG06OtMZF1: __attribute__ ((unused)); // routine _2Uksq9GtGL5_6mG06OtMZF1 epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _2Uksq9GtGL5_6mG06OtMZF1 routine#2 _2Uksq9GtGL5_6mG06OtMZF1




value_tyBM crout_4xwDKklt2v4_2lEbck0j4qs_BM //#3
 (struct stackframe_stBM* stkf, //
//!html_spacing°simple*html*element < o_helem (o_emitctx v_depth)
  // 3 arguments
  const value_tyBM arg0,  // o_helem
  const value_tyBM arg1,  // o_emitctx
  const value_tyBM arg2,  // v_depth
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _4xwDKklt2v4_2lEbck0j4qs
  struct frame_4xwDKklt2v4_2lEbck0j4qs_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 8 local values:
    value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
    value_tyBM v_2hXC8HRC8p6_0ma0OmYHXnB; // v_spacing
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    objectval_tyBM* o_6Ef2ORO1Mni_0tpNoRQGmrW; // o_helem
    value_tyBM v_6KzoPNta5a2_7EsZceEn0Px; // v_clos
    value_tyBM v_8HXPWMdva6A_2c7NOY8vxvZ; // v_respace
    objectval_tyBM* o_9nXRmTATjN4_5F9V7RvvgW0; // o_emitctx
    /// 1 local numbers:
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
   } _;
   memset (&_, 0, sizeof(struct frame_4xwDKklt2v4_2lEbck0j4qs_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 8;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[32] /*|_4xwDKklt2v4_2lEbck0j4qs*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 3 arguments:
   _.o_6Ef2ORO1Mni_0tpNoRQGmrW = objectcast_BM (arg0); // o_helem
   _.o_9nXRmTATjN4_5F9V7RvvgW0 = objectcast_BM (arg1); // o_emitctx
   _.v_4nJKFtMqlkA_1teQSqofNux = arg2; // v_depth
   // fetched 3 arguments.
   // no closed values in _4xwDKklt2v4_2lEbck0j4qs.
   // routine _4xwDKklt2v4_2lEbck0j4qs body:

startblock__8RQv0LoHOHD_9dRe3HS6ybs: __attribute__((unused));
{ /* +block _8RQv0LoHOHD_9dRe3HS6ybs */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _2iVQGQ5E98W_1PLw2pB5lLZ  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 /*v_spacing:*/_.v_2hXC8HRC8p6_0ma0OmYHXnB = //assign _6saK0DzUAG2_0RXYpmgVHXt  
/*objgetattr:*/objgetattr_BM(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[62] /*!html_spacing*/))); 
 
//+ #2/4 of block _8RQv0LoHOHD_9dRe3HS6ybs :: 
 
 
{ // run _1KltsNSWSMX_4Nsq22AomFo 
/*debug html_spacing°simple*html*element start o_helem o_emitctx depth v_spacing*/
DBGPRINTF_BM("html_spacing°simple*html*element start €%.9s o_helem=%s o_emitctx=%s depth#%ld v_spacing=%s",
 "_1KltsNSWSMX_4Nsq22AomFo",
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
 OUTSTRVALUE_BM( /*v_spacing:*/_.v_2hXC8HRC8p6_0ma0OmYHXnB));; 
} // end run _1KltsNSWSMX_4Nsq22AomFo 
 
 
if /*cond _1mznTN7oAXj_6pq1mjxzWC8*/  
/*when _1jv7Qmv9VQ2_5g8bfCOyoFV:*/ 
 (/*is_objectv*/ isobject_BM( /*v_spacing:*/_.v_2hXC8HRC8p6_0ma0OmYHXnB)) { //body when _1jv7Qmv9VQ2_5g8bfCOyoFV  
/*return _6vjGS3hZ4qx_8RyCnOCeWXA:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned  
 /*v_spacing:*/_.v_2hXC8HRC8p6_0ma0OmYHXnB;  
 goto epilog_4xwDKklt2v4_2lEbck0j4qs;  
  
} //endwhen _1jv7Qmv9VQ2_5g8bfCOyoFV  
else if  
/*when _42wBUkxLaHO_8YpPlJpPGtJ:*/ 
 (/*isclosure:*/isclosure_BM(( /*v_spacing:*/_.v_2hXC8HRC8p6_0ma0OmYHXnB))) { //body when _42wBUkxLaHO_8YpPlJpPGtJ  
 /*v_respace:*/_.v_8HXPWMdva6A_2c7NOY8vxvZ = //assign _0r8xlhrFrVp_9FsScgOWoZo   
(apply3_BM (( /*v_spacing:*/_.v_2hXC8HRC8p6_0ma0OmYHXnB), ((struct stackframe_stBM*)&_), 
 ( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))));  
  
{ // run _8wEfLKO119o_2pYSHmybx9J  
/*debug html_spacing°simple*html*element v_respace o_helem depth*/
DBGPRINTF_BM( "html_spacing°simple*html*element €%.9s v_respace=%s o_helem=%s depth#%ld",
 "_8wEfLKO119o_2pYSHmybx9J",
 OUTSTRVALUE_BM( /*v_respace:*/_.v_8HXPWMdva6A_2c7NOY8vxvZ),
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;  
} // end run _8wEfLKO119o_2pYSHmybx9J  
  
} //endwhen _42wBUkxLaHO_8YpPlJpPGtJ  
/*endcond _1mznTN7oAXj_6pq1mjxzWC8*/ 
 
/* !endingblock _8RQv0LoHOHD_9dRe3HS6ybs */ 
goto endblock__8RQv0LoHOHD_9dRe3HS6ybs; 
endblock__8RQv0LoHOHD_9dRe3HS6ybs: ; 
} /*-block _8RQv0LoHOHD_9dRe3HS6ybs */

 epilog_4xwDKklt2v4_2lEbck0j4qs: __attribute__ ((unused)); // routine _4xwDKklt2v4_2lEbck0j4qs epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _4xwDKklt2v4_2lEbck0j4qs routine#3 _4xwDKklt2v4_2lEbck0j4qs




value_tyBM crout_4I0ksnAasRT_1bREYU29xgL_BM //#4
 (struct stackframe_stBM* stkf, //
//!emit-tagged-xhtml-open [v_htmltag v_htmlclass] (o_helem o_emitctx o_strbuf v_depth)
  // 4 arguments
  const value_tyBM arg0,  // o_helem
  const value_tyBM arg1,  // o_emitctx
  const value_tyBM arg2,  // o_strbuf
  const value_tyBM arg3,  // v_depth
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _4I0ksnAasRT_1bREYU29xgL
  struct frame_4I0ksnAasRT_1bREYU29xgL_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 9 local values:
    value_tyBM v_0wWVh40nozk_7OSKII1HZ6t; // v_htmlclass
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    value_tyBM v_6nmKmS2Auzh_04y9gBqgcDG; // v_htmltag
    value_tyBM v_6p6w3jZv5gy_58EzMDpOBQJ; // v_htmltagstr
    objectval_tyBM* o_6Ef2ORO1Mni_0tpNoRQGmrW; // o_helem
    objectval_tyBM* o_9nXRmTATjN4_5F9V7RvvgW0; // o_emitctx
    value_tyBM v_9AuPELEBCEG_3r2aCy2y3Pc; // v_htmlclassstr
    /// 1 local numbers:
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
   } _;
   memset (&_, 0, sizeof(struct frame_4I0ksnAasRT_1bREYU29xgL_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 9;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[37] /*|_4I0ksnAasRT_1bREYU29xgL*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 4 arguments:
   _.o_6Ef2ORO1Mni_0tpNoRQGmrW = objectcast_BM (arg0); // o_helem
   _.o_9nXRmTATjN4_5F9V7RvvgW0 = objectcast_BM (arg1); // o_emitctx
   _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg2); // o_strbuf
   _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
   // fetched 4 arguments.
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
 
 
 
{ // run _3IPMHL4DXq5_3wKF7DoEbvk 
/*debug emit-tagged-xhtml-open start [v_htmltag v_htmlclass] o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emit-tagged-xhtml-open start €%.9s [v_htmltag=%s v_htmlclass=%s] o_helem=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_3IPMHL4DXq5_3wKF7DoEbvk",
 OUTSTRVALUE_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG),
 OUTSTRVALUE_BM( /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t),
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _3IPMHL4DXq5_3wKF7DoEbvk 
 
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
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*val_to_object:*/objectcast_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[19] /*!html_tag*/))))));  
  
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
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*val_to_object:*/objectcast_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[45] /*!html_class*/))))));  
  
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
} // end _4I0ksnAasRT_1bREYU29xgL routine#4 _4I0ksnAasRT_1bREYU29xgL




value_tyBM crout_5NH940lCHYJ_3nuRm3flnzc_BM //#5
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
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[44] /*|_5NH940lCHYJ_3nuRm3flnzc*/;
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
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_non_object*/)), 
 /*make_node 4 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[44] /*!_5NH940lCHYJ_3nuRm3flnzc*/)), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[9] /*|_2ekmsdDpheM_8iSH1r9pS9e*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _0li4T620kcV_4nC1fD477pu  
/*endcond _6VEZT6yN91n_1uTSi1gCAKy*/ 
 
 
 
{ // begin lockobj _36l0VwmZ11o_8vCwWpg2xIB 
  objectval_tyBM* curlockedob_36l0VwmZ11o_8vCwWpg2xIB = ( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW); 
if (objlock_BM (curlockedob_36l0VwmZ11o_8vCwWpg2xIB)) {  
locked_36l0VwmZ11o_8vCwWpg2xIB = curlockedob_36l0VwmZ11o_8vCwWpg2xIB;  
  
if /*cond _921fuoujPIF_4a0JqUqMOyG*/  
/*when _6HtsKDbq7Rx_3rZ8uRwGNj9:*/ 
 (/*not:*/ (! (/*objectisinstance:*/ objectisinstance_BM(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[57] /*!html_element_object*/)))))) { //body when _6HtsKDbq7Rx_3rZ8uRwGNj9  
//failure _5rs4UfgeATT_3s7r48scObY   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[34] /*!failure_bad_class*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[57] /*!html_element_object*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[42] /*|_5rs4UfgeATT_3s7r48scObY*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _6HtsKDbq7Rx_3rZ8uRwGNj9  
/*endcond _921fuoujPIF_4a0JqUqMOyG*/ 
  
 /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r = //assign _4gqzOn4YRA4_4DeoI7Me5mK  
/*val_to_object:*/objectcast_BM((send2_BM (( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), /*sel:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[62] /*!html_spacing*/)), ((struct stackframe_stBM*)&_),  
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
(send3_BM (( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), /*sel:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[46] /*!emit_xhtml_open*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),  ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)))); 
  
if /*cond _4Vd3Fe3lriq_1maa3fRM0K5*/  
/*when _2vrXQXG9ekP_2af2adhJ59X:*/ 
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _2vrXQXG9ekP_2af2adhJ59X  
//failure _5xGV4qXFkqJ_4imeaugtTzv   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[40] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[46] /*!emit_xhtml_open*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[43] /*|_5xGV4qXFkqJ_4imeaugtTzv*/)),
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
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[71] /*!failure_type_error*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[46] /*!emit_xhtml_open*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[64] /*|_8c3wK0SptYZ_6EpzaOaJVJc*/)),
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
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[11] /*!newline*/)))) { //body when _78CDl258ber_2OZ6iKkZQDj  
{ // start out _1wybjEqYoCm_7w8ES3jgUxS to o_strbuf   
/*out more_indent:*/ objstrbuffermoreindentpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);   
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);  
} // end out _1wybjEqYoCm_7w8ES3jgUxS  
  
} //endwhen _78CDl258ber_2OZ6iKkZQDj  
else if  
/*when _8gbKuVOJ00d_0iXBwlmG6jd:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[55] /*!nlsp*/)))) { //body when _8gbKuVOJ00d_0iXBwlmG6jd  
{ // start out _6nl4fxXo5P9_4aikEu7hcUs to o_strbuf   
/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);  
} // end out _6nl4fxXo5P9_4aikEu7hcUs  
  
} //endwhen _8gbKuVOJ00d_0iXBwlmG6jd  
else if  
/*when _0aSvuu44cW5_744SUn0a59q:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[17] /*!space*/)))) { //body when _0aSvuu44cW5_744SUn0a59q  
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
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[11] /*!newline*/)))) { //body when _2VEPlTDtufU_1OJU65eKBpP   
{ // start out _8Nw9zJ5h0KD_02bjHvKfgQw to o_strbuf    
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);   
} // end out _8Nw9zJ5h0KD_02bjHvKfgQw   
   
} //endwhen _2VEPlTDtufU_1OJU65eKBpP   
else if   
/*when _9lQbBHyLisB_9RbsRinLVVi:*/  
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[55] /*!nlsp*/)))) { //body when _9lQbBHyLisB_9RbsRinLVVi   
{ // start out _0nMvmHfMjyF_5iZ1qqd9K8S to o_strbuf    
/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);   
} // end out _0nMvmHfMjyF_5iZ1qqd9K8S   
   
} //endwhen _9lQbBHyLisB_9RbsRinLVVi   
else if   
/*when _9BdaJn6vBWW_7n07rdHXudX:*/  
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[17] /*!space*/)))) { //body when _9BdaJn6vBWW_7n07rdHXudX   
{ // start out _6FxYfpCMqWj_2x1fBqLWf57 to o_strbuf    
/*out space:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " ");   
} // end out _6FxYfpCMqWj_2x1fBqLWf57   
   
} //endwhen _9BdaJn6vBWW_7n07rdHXudX   
/*endcond _9esS4NliRiB_2VgVZ0sULry*/  
  
// for-up _8QYxgALaJfV_49EojKGexX9 #3 :  
  
{ // run _63u3t8z297Q_8sNjKGmTWLe  
/*debug emitxhtml_element before emit_xhtml: v_comp o_emitctx o_strbuf depth*/
DBGPRINTF_BM(" emitxhtml_element €%.9s before emit_xhtml: v_comp=%s o_emitctx=%s o_strbuf=%s/L%u depth=%ld",
"_63u3t8z297Q_8sNjKGmTWLe",
 OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
 objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;  
} // end run _63u3t8z297Q_8sNjKGmTWLe  
  
// for-up _8QYxgALaJfV_49EojKGexX9 #4 :  
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _9WzUvoIHCSM_4O5lNZm3jb2   
(apply4_BM (( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), ((struct stackframe_stBM*)&_), 
 ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));  
  
// for-up _8QYxgALaJfV_49EojKGexX9 #5 :  
  
{ // run _5RzQzmfNZTu_5nQjP7QfLLD  
/*debug emitxhtml_element after emit_xhtml: v_resemit v_comp ii o_emitctx o_strbuf depth*/
 DBGPRINTF_BM("emitxhtml_element after emit_xhtml €%.9s: v_resemit=%s v_comp=%s ii#%ld o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_5RzQzmfNZTu_5nQjP7QfLLD",
 OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
 OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
 (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
 objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
;  
} // end run _5RzQzmfNZTu_5nQjP7QfLLD  
  
// for-up _8QYxgALaJfV_49EojKGexX9 #6 :  
if /*cond _6JhK96miaMx_3XLltRct5WU*/   
/*when _7yndBSvwm1J_9N5z0dJuXIM:*/  
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _7yndBSvwm1J_9N5z0dJuXIM   
//failure _51oIiJoCulz_1NyarSIagfB    
PLACEDFAILURE_BM(__LINE__,    
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[40] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[39] /*|_51oIiJoCulz_1NyarSIagfB*/)),
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
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[11] /*!newline*/)))) { //body when _7Tqp9FaGOi6_1zlNZrsr3P4  
{ // start out _5xthhfX2qlp_6rUZ8Mn7fG9 to o_strbuf   
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);  
} // end out _5xthhfX2qlp_6rUZ8Mn7fG9  
  
} //endwhen _7Tqp9FaGOi6_1zlNZrsr3P4  
else if  
/*when _26hfrrkoYbw_0EsJYF6nzjS:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[55] /*!nlsp*/)))) { //body when _26hfrrkoYbw_0EsJYF6nzjS  
{ // start out _8ALxuahzjVn_9JyrNMc4dcs to o_strbuf   
/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);  
} // end out _8ALxuahzjVn_9JyrNMc4dcs  
  
} //endwhen _26hfrrkoYbw_0EsJYF6nzjS  
else if  
/*when _4c7whFwVYld_6KcIS6aV9Yf:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[17] /*!space*/)))) { //body when _4c7whFwVYld_6KcIS6aV9Yf  
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
} // end _5NH940lCHYJ_3nuRm3flnzc routine#5 _5NH940lCHYJ_3nuRm3flnzc




value_tyBM crout_6RtF29C4pij_9r269Lc0d0W_BM //#6
 (struct stackframe_stBM* stkf, //
//!emit_xhtml_open°simple_void_html_element_object < o_helem (o_emitctx o_strbuf v_depth)
  // 4 arguments
  const value_tyBM arg0,  // o_helem
  const value_tyBM arg1,  // o_emitctx
  const value_tyBM arg2,  // o_strbuf
  const value_tyBM arg3,  // v_depth
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _6RtF29C4pij_9r269Lc0d0W
  struct frame_6RtF29C4pij_9r269Lc0d0W_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 8 local values:
    value_tyBM v_0qTBOEAT5pa_2fz1SKfHrMV; // v_resemit
    value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    objectval_tyBM* o_6Ef2ORO1Mni_0tpNoRQGmrW; // o_helem
    value_tyBM v_6KzoPNta5a2_7EsZceEn0Px; // v_clos
    objectval_tyBM* o_9nXRmTATjN4_5F9V7RvvgW0; // o_emitctx
    /// 2 local numbers:
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
   } _;
   memset (&_, 0, sizeof(struct frame_6RtF29C4pij_9r269Lc0d0W_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 8;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[51] /*|_6RtF29C4pij_9r269Lc0d0W*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 4 arguments:
   _.o_6Ef2ORO1Mni_0tpNoRQGmrW = objectcast_BM (arg0); // o_helem
   _.o_9nXRmTATjN4_5F9V7RvvgW0 = objectcast_BM (arg1); // o_emitctx
   _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg2); // o_strbuf
   _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
   // fetched 4 arguments.
   // no closed values in _6RtF29C4pij_9r269Lc0d0W.
   // routine _6RtF29C4pij_9r269Lc0d0W body:

startblock__4zWEZFBIK5X_25cIifaeDB9: __attribute__((unused));
{ /* +block _4zWEZFBIK5X_25cIifaeDB9 */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _3TH81ZGZZo4_6ION2zs9zaQ  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px = //assign _7yAtINJUXoh_8n4bqYuxD2N  
/*closure_cast:*/(value_tyBM) closurecast_BM(/*objgetattr:*/objgetattr_BM(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[46] /*!emit_xhtml_open*/)))); 
 
//+ #2/7 of block _4zWEZFBIK5X_25cIifaeDB9 :: 
 
 
{ // run _4EhYqK8eYDG_8Y8nhtkRYZo 
/*debug emit_xhtml_open°simple_void_html_element_object start o_helem o_emitctx o_strbuf depth v_clos*/
DBGPRINTF_BM("emit_xhtml_open°simple_void_html_element_object start €%.9s o_helem=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld v_clos=%s",
 "_4EhYqK8eYDG_8Y8nhtkRYZo",
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
 OUTSTRVALUE_BM( /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px));
; 
} // end run _4EhYqK8eYDG_8Y8nhtkRYZo 
 
 
if /*cond _5J3YpupHFDo_2zuf7NsGD1w*/  
/*when _2SAhgKsu5KC_4DxDUopQ4TG:*/ 
 (/*is_null:*/(( /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px)==NULL)) { //body when _2SAhgKsu5KC_4DxDUopQ4TG  
//failure _7PgBB7uIPOd_65NhmUjoLJf   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[40] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px)))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[58] /*|_7PgBB7uIPOd_65NhmUjoLJf*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _2SAhgKsu5KC_4DxDUopQ4TG  
/*endcond _5J3YpupHFDo_2zuf7NsGD1w*/ 
 
//+ #4/7 of block _4zWEZFBIK5X_25cIifaeDB9 :: 
 
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _5OmfUP7qWIG_2CvEuuke6TQ  
(apply4_BM (( /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px), ((struct stackframe_stBM*)&_), 
 ( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)))); 
 
 
 
{ // run _4vmSDBlykVT_7J9WL5VUaRx 
/*debug emit_xhtml_open°simple_html_void_element_object end v_resemit o_helem o_strbuf depth*/
DBGPRINTF_BM("emit_xhtml_open°simple_html_void_element_object end €%.9s v_resemit=%s o_helem=%s o_strbuf=%s/L%u depth#%ld",
 "_4vmSDBlykVT_7J9WL5VUaRx",
 OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _4vmSDBlykVT_7J9WL5VUaRx 
 
 
/*return _1QaljtTkdDu_6BGawawZys3:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV; 
 goto epilog_6RtF29C4pij_9r269Lc0d0W; 
 
/* !endingblock _4zWEZFBIK5X_25cIifaeDB9 */ 
goto endblock__4zWEZFBIK5X_25cIifaeDB9; 
endblock__4zWEZFBIK5X_25cIifaeDB9: ; 
} /*-block _4zWEZFBIK5X_25cIifaeDB9 */

 epilog_6RtF29C4pij_9r269Lc0d0W: __attribute__ ((unused)); // routine _6RtF29C4pij_9r269Lc0d0W epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _6RtF29C4pij_9r269Lc0d0W routine#6 _6RtF29C4pij_9r269Lc0d0W




value_tyBM crout_6TYtJU0rl2h_2z4md7DV06z_BM //#7
 (struct stackframe_stBM* stkf, //
//!root-web-handler (v_restpath o_webex)
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
    /// 8 local values:
    value_tyBM v_0qTBOEAT5pa_2fz1SKfHrMV; // v_resemit
    value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_5JuT4FgNFFh_7McrTYeT3jx; // o_webex
    objectval_tyBM* o_6cRlOymtk44_3dId2Eescrt; // o_theme
    objectval_tyBM* o_6Ef2ORO1Mni_0tpNoRQGmrW; // o_helem
    value_tyBM v_6QhNRfe1Cte_0niVlWfAlmO; // v_restpath
    objectval_tyBM* o_7UzdV9wjuq2_2PRgXcyAlMi; // o_websess
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_6TYtJU0rl2h_2z4md7DV06z_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 8;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[52] /*|_6TYtJU0rl2h_2z4md7DV06z*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // locking 2:
    objectval_tyBM* locked_2GWBlUog6H9_8TLWmeV8dDa = NULL; // for __
    objectval_tyBM* locked_8woHIy7b2te_2999K8YXwmX = NULL; // for o_websess
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
 
 
{ // start out _0ElmKog957y_3K5W7qvSMfO to o_webex  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx, "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx, "<!DOCTYPE html>\n"); 
} // end out _0ElmKog957y_3K5W7qvSMfO 
 
//+ #2/10 of block _6eHKA5eSoIV_4ajeKi1n1so :: 
 
 /*o_websess:*/_.o_7UzdV9wjuq2_2PRgXcyAlMi = //assign _1DBMlWZKVWz_9dK3Y2P7W36  
/*objwebexchangesessionpayl:*/objwebexchangesessionpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx)); 
 
 
 /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW = //assign _8FJHJvnDQjZ_4kXI45kCcHt  
 (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[18] /*!_3poYCpSsBfJ_8W7XNwG50hS*/); 
 
//+ #4/10 of block _6eHKA5eSoIV_4ajeKi1n1so :: 
 
 
{ // run _2znMyOWdQVD_3yXIlsVORJc 
/*debug root-web-handler o_webex o_websess o_helem*/
DBGPRINTF_BM("root-web-handler €%.9s o_webex=%s/L%u o_websess=%s o_helem=%s",
"_2znMyOWdQVD_3yXIlsVORJc", objectdbg_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx),
 objstrbufferlengthpayl_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx),
 objectdbg1_BM( /*o_websess:*/_.o_7UzdV9wjuq2_2PRgXcyAlMi),
 objectdbg2_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW));; 
} // end run _2znMyOWdQVD_3yXIlsVORJc 
 
 
 
{ // begin lockobj _8woHIy7b2te_2999K8YXwmX 
  objectval_tyBM* curlockedob_8woHIy7b2te_2999K8YXwmX = ( /*o_websess:*/_.o_7UzdV9wjuq2_2PRgXcyAlMi); 
if (objlock_BM (curlockedob_8woHIy7b2te_2999K8YXwmX)) {  
locked_8woHIy7b2te_2999K8YXwmX = curlockedob_8woHIy7b2te_2999K8YXwmX;  
  
 /*o_theme:*/_.o_6cRlOymtk44_3dId2Eescrt = //assign _6XupMIHlADv_4kmfpHuGNgh  
/*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_websess:*/_.o_7UzdV9wjuq2_2PRgXcyAlMi),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[36] /*!web_theme*/)))); 
  
if /*cond _2qNMv03BDYW_3VaCIUscZIp*/  
/*when _5w7aizMRVG7_4mvxmUUhYmY:*/ 
 (/*is_null:*/(( /*o_theme:*/_.o_6cRlOymtk44_3dId2Eescrt)==NULL)) { //body when _5w7aizMRVG7_4mvxmUUhYmY  
  
{ // begin lockobj _2GWBlUog6H9_8TLWmeV8dDa  
  objectval_tyBM* curlockedob_2GWBlUog6H9_8TLWmeV8dDa = ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[1] /*!the_web_sessions*/));  
if (objlock_BM (curlockedob_2GWBlUog6H9_8TLWmeV8dDa)) {   
locked_2GWBlUog6H9_8TLWmeV8dDa = curlockedob_2GWBlUog6H9_8TLWmeV8dDa;   
   
 /*o_theme:*/_.o_6cRlOymtk44_3dId2Eescrt = //assign _2gT4zUoEUlR_6fkFhKFdWjg   
/*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[1] /*!the_web_sessions*/)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[30] /*!default_web_theme*/))));  
   
objunlock_BM (locked_2GWBlUog6H9_8TLWmeV8dDa), locked_2GWBlUog6H9_8TLWmeV8dDa = NULL;  
} } // end objlock _2GWBlUog6H9_8TLWmeV8dDa  
{ // start cexpansion _7aWYsOAJl3b_4zKUYhxHt3k - objputattr   
/*objputattr:*/objputattr_BM(( /*o_websess:*/_.o_7UzdV9wjuq2_2PRgXcyAlMi),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[36] /*!web_theme*/)),( /*o_theme:*/_.o_6cRlOymtk44_3dId2Eescrt));   
} // end cexpansion _7aWYsOAJl3b_4zKUYhxHt3k - objputattr   
  
{ // run _4Ifwi5c0FRB_5gs0g2j0ceO  
/*debug root-web-handler put o_theme in o_websess o_webex*/
DBGPRINTF_BM("root-web-handler €%.9s put o_theme=%s in o_websess=%s o_webex=%s",
 "_4Ifwi5c0FRB_5gs0g2j0ceO",
 objectdbg_BM( /*o_theme:*/_.o_6cRlOymtk44_3dId2Eescrt),
 objectdbg1_BM( /*o_websess:*/_.o_7UzdV9wjuq2_2PRgXcyAlMi),
 objectdbg2_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx));
 ;  
} // end run _4Ifwi5c0FRB_5gs0g2j0ceO  
  
} //endwhen _5w7aizMRVG7_4mvxmUUhYmY  
/*endcond _2qNMv03BDYW_3VaCIUscZIp*/ 
  
//+ #2/5 of lockobj _8woHIy7b2te_2999K8YXwmX ::  
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _3ODlWYfUwgB_60uE0qeNxCz  
(apply4_BM (( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[44] /*!_5NH940lCHYJ_3nuRm3flnzc*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),  ( /*o_websess:*/_.o_7UzdV9wjuq2_2PRgXcyAlMi), 
 ( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx),  (/*taggedint:*/ taggedint_BM ( 0)))); 
  
 
{ // run _19su0zeFPjT_3UNwwmuFUs3 
/*debug root-web-handler v_resemit o_webex o_websess o_helem o_theme*/
DBGPRINTF_BM("debug root-web-handler €%.9s v_resemit=%s o_webex=%s/L%u o_websess=%s o_helem=%s o_theme=%s",
 "_19su0zeFPjT_3UNwwmuFUs3",
 OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
 objectdbg_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx),
 objstrbufferlengthpayl_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx),
 objectdbg1_BM( /*o_websess:*/_.o_7UzdV9wjuq2_2PRgXcyAlMi),
 objectdbg2_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg3_BM( /*o_theme:*/_.o_6cRlOymtk44_3dId2Eescrt));
; 
} // end run _19su0zeFPjT_3UNwwmuFUs3 
  
if /*cond _7yqydEM9tDW_7REkbyJqGhi*/  
/*when _7fOlXQV1qei_1jblKqwdvUu:*/ 
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _7fOlXQV1qei_1jblKqwdvUu  
//failure _1P3gVK5iIH8_62cj5fqHcIv   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode3_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[40] /*!failure_miss*/)), 
 /*make_node 3 sons:*/ 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_websess:*/_.o_7UzdV9wjuq2_2PRgXcyAlMi), 
 
( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx)))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[8] /*|_1P3gVK5iIH8_62cj5fqHcIv*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _7fOlXQV1qei_1jblKqwdvUu  
/*endcond _7yqydEM9tDW_7REkbyJqGhi*/ 
  
objunlock_BM (locked_8woHIy7b2te_2999K8YXwmX), locked_8woHIy7b2te_2999K8YXwmX = NULL; 
} } // end objlock _8woHIy7b2te_2999K8YXwmX 
//+ #6/10 of block _6eHKA5eSoIV_4ajeKi1n1so :: 
 
{ // start out _1qF5JsX0Giz_1Y9rX4js1XY to o_webex  
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx);  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx, "<!-- end root-web-handler o_webex=");  
/*out id:*/ char idbuf_1qF5JsX0Giz_1Y9rX4js1XY_n2[32]={0};  
idtocbuf32_BM (objid_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), idbuf_1qF5JsX0Giz_1Y9rX4js1XY_n2);  
objstrbufferappendcstrpayl_BM ( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx, idbuf_1qF5JsX0Giz_1Y9rX4js1XY_n2);  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx, "; o_websess=");  
/*out id:*/ char idbuf_1qF5JsX0Giz_1Y9rX4js1XY_n4[32]={0};  
idtocbuf32_BM (objid_BM( /*o_websess:*/_.o_7UzdV9wjuq2_2PRgXcyAlMi), idbuf_1qF5JsX0Giz_1Y9rX4js1XY_n4);  
objstrbufferappendcstrpayl_BM ( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx, idbuf_1qF5JsX0Giz_1Y9rX4js1XY_n4);  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx, " at ");  
/*out local_time:*/objstrbufferencodelocaltimepayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), /*objwebexchangedbltime:*/objwebexchangedbltime_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx));  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx, " -->\n"); 
} // end out _1qF5JsX0Giz_1Y9rX4js1XY 
 
 
 
{ // run _3CEacq7ZagN_1ZXfwthwX0P 
/*debug end root-web-handler v_resemit o_webex*/
DBGPRINTF_BM("end root-web-handler €%.9s v_resemit=%s o_webex=%s/L%u:\n%s\n########\n",
 "_3CEacq7ZagN_1ZXfwthwX0P",
 OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
 objectdbg_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx),
 objstrbufferlengthpayl_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx),
 objstrbufferbytespayl_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx));
; 
} // end run _3CEacq7ZagN_1ZXfwthwX0P 
 
//+ #8/10 of block _6eHKA5eSoIV_4ajeKi1n1so :: 
 
{ // start cexpansion _3GNqxaIiNPt_2gUUJzEqzQN - objwebexchangecompletepayl  
/*objwebexchangecompletepayl:*/ objwebexchangecompletepayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), (/*chunk-constob HTTP_OK:*/(HTTP_OK)), ( "application/xhtml+xml"));  
} // end cexpansion _3GNqxaIiNPt_2gUUJzEqzQN - objwebexchangecompletepayl  
  
 
/*return _5wbwgEoYVpe_9Vlqsd7TbBg:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV; 
 goto epilog_6TYtJU0rl2h_2z4md7DV06z; 
 
/* !endingblock _6eHKA5eSoIV_4ajeKi1n1so */ 
goto endblock__6eHKA5eSoIV_4ajeKi1n1so; 
endblock__6eHKA5eSoIV_4ajeKi1n1so: ; 
} /*-block _6eHKA5eSoIV_4ajeKi1n1so */

 epilog_6TYtJU0rl2h_2z4md7DV06z: __attribute__ ((unused)); // routine _6TYtJU0rl2h_2z4md7DV06z epilogue:
   // unlocking 2:
    if (locked_2GWBlUog6H9_8TLWmeV8dDa != NULL)
       objunlock_BM(locked_2GWBlUog6H9_8TLWmeV8dDa), locked_2GWBlUog6H9_8TLWmeV8dDa = NULL;
    if (locked_8woHIy7b2te_2999K8YXwmX != NULL)
       objunlock_BM(locked_8woHIy7b2te_2999K8YXwmX), locked_8woHIy7b2te_2999K8YXwmX = NULL; // for o_websess
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _6TYtJU0rl2h_2z4md7DV06z routine#7 _6TYtJU0rl2h_2z4md7DV06z




value_tyBM crout_85938GaqS1z_3mZSenKG7GG_BM //#8
 (struct stackframe_stBM* stkf, //
//!emit-tagged-id-more-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget v_more] (o_helem o_emitctx o_strbuf v_depth)
  // 4 arguments
  const value_tyBM arg0,  // o_helem
  const value_tyBM arg1,  // o_emitctx
  const value_tyBM arg2,  // o_strbuf
  const value_tyBM arg3,  // v_depth
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _85938GaqS1z_3mZSenKG7GG
  struct frame_85938GaqS1z_3mZSenKG7GG_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 15 local values:
    value_tyBM v_09jnZdQe0uA_088LqcQDlbX; // v_more
    value_tyBM v_0qTBOEAT5pa_2fz1SKfHrMV; // v_resemit
    value_tyBM v_0wWVh40nozk_7OSKII1HZ6t; // v_htmlclass
    value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
    objectval_tyBM* o_1E1n1xq22bH_7JEWM863KYo; // o_idtarget
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    value_tyBM v_6nmKmS2Auzh_04y9gBqgcDG; // v_htmltag
    value_tyBM v_6p6w3jZv5gy_58EzMDpOBQJ; // v_htmltagstr
    value_tyBM v_6wh43lYjXiZ_9MUWTOiTsOl; // v_idprefixstr
    objectval_tyBM* o_6Ef2ORO1Mni_0tpNoRQGmrW; // o_helem
    value_tyBM v_8VgHiZPlXwn_5i6tFD7vAVB; // v_idprefix
    objectval_tyBM* o_9nXRmTATjN4_5F9V7RvvgW0; // o_emitctx
    value_tyBM v_9AuPELEBCEG_3r2aCy2y3Pc; // v_htmlclassstr
    /// 3 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
   } _;
   memset (&_, 0, sizeof(struct frame_85938GaqS1z_3mZSenKG7GG_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 15;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[63] /*|_85938GaqS1z_3mZSenKG7GG*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 4 arguments:
   _.o_6Ef2ORO1Mni_0tpNoRQGmrW = objectcast_BM (arg0); // o_helem
   _.o_9nXRmTATjN4_5F9V7RvvgW0 = objectcast_BM (arg1); // o_emitctx
   _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg2); // o_strbuf
   _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
   // fetched 4 arguments.
   { // fetch 5 closed values in _85938GaqS1z_3mZSenKG7GG:
   const closure_tyBM* callclos_85938GaqS1z_3mZSenKG7GG =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   unsigned nbclosed_85938GaqS1z_3mZSenKG7GG = closurewidth_BM ((const value_tyBM) callclos_85938GaqS1z_3mZSenKG7GG);
   if (nbclosed_85938GaqS1z_3mZSenKG7GG > 0)
      _.v_6nmKmS2Auzh_04y9gBqgcDG = callclos_85938GaqS1z_3mZSenKG7GG->nodt_sons[0]; // v_htmltag
   if (nbclosed_85938GaqS1z_3mZSenKG7GG > 1)
      _.v_0wWVh40nozk_7OSKII1HZ6t = callclos_85938GaqS1z_3mZSenKG7GG->nodt_sons[1]; // v_htmlclass
   if (nbclosed_85938GaqS1z_3mZSenKG7GG > 2)
      _.v_8VgHiZPlXwn_5i6tFD7vAVB = callclos_85938GaqS1z_3mZSenKG7GG->nodt_sons[2]; // v_idprefix
   if (nbclosed_85938GaqS1z_3mZSenKG7GG > 3)
      _.o_1E1n1xq22bH_7JEWM863KYo = objectcast_BM (callclos_85938GaqS1z_3mZSenKG7GG->nodt_sons[3]); // o_idtarget
   if (nbclosed_85938GaqS1z_3mZSenKG7GG > 4)
      _.v_09jnZdQe0uA_088LqcQDlbX = callclos_85938GaqS1z_3mZSenKG7GG->nodt_sons[4]; // v_more
   } // fetched 5 closed values in _85938GaqS1z_3mZSenKG7GG.
   // routine _85938GaqS1z_3mZSenKG7GG body:

startblock__0aMhdgQGit6_9yp9HB8SWvo: __attribute__((unused));
{ /* +block _0aMhdgQGit6_9yp9HB8SWvo */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _2SZByIWkrSr_00a8WjPOmYa  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 
{ // run _6wyVbP5mHws_8lY1isSulYj 
/*debug emit-tagged-id-more-xhtml-open start [v_htmltag v_htmlclass v_idprefix o_idtarget v_more] (o_helem o_emitctx o_strbuf depth)*/
DBGPRINTF_BM("emit-tagged-id-more-xhtml-open start €%.9s [v_htmltag=%s v_htmlclass=%s v_idprefix=%s o_idtarget=%s v_more=%s]\n.. (o_helem=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_6wyVbP5mHws_8lY1isSulYj",
 OUTSTRVALUE_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG),
 OUTSTRVALUE_BM( /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t),
 OUTSTRVALUE_BM( /*v_idprefix:*/_.v_8VgHiZPlXwn_5i6tFD7vAVB),
 objectdbg_BM( /*o_idtarget:*/_.o_1E1n1xq22bH_7JEWM863KYo),
 OUTSTRVALUE_BM( /*v_more:*/_.v_09jnZdQe0uA_088LqcQDlbX),
 objectdbg1_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg2_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg3_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _6wyVbP5mHws_8lY1isSulYj 
 
//+ #2/10 of block _0aMhdgQGit6_9yp9HB8SWvo :: 
 
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
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*val_to_object:*/objectcast_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[19] /*!html_tag*/))))));  
  
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
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*val_to_object:*/objectcast_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[45] /*!html_class*/))))));  
  
} //endwhen _3B2yJwjdy53_7VKdj7byIy6  
/*endcond _981Htnuqk2v_3f6kRQZBkNI*/ 
 
//+ #4/10 of block _0aMhdgQGit6_9yp9HB8SWvo :: 
 
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
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*object_cast:*/(value_tyBM)objectcast_BM( /*v_idprefix:*/_.v_8VgHiZPlXwn_5i6tFD7vAVB)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[66] /*!html_idprefix*/))))));  
  
} //endwhen _8L1ziPttLIT_5je6y8T504n  
/*endcond _9H0L8bKRxNs_6ZLNYQisXhr*/ 
 
//+ #6/10 of block _0aMhdgQGit6_9yp9HB8SWvo :: 
 
if /*cond _28OEq9p17rL_4fKBMly70SD*/  
/*when _9yrHHrw0SbZ_2da6hoDlbev:*/ 
 (/*is_null:*/(( /*o_idtarget:*/_.o_1E1n1xq22bH_7JEWM863KYo)==NULL)) { //body when _9yrHHrw0SbZ_2da6hoDlbev  
 /*o_idtarget:*/_.o_1E1n1xq22bH_7JEWM863KYo = //assign _1F7YZ8m4bvu_8fk0QAiXOx4   
 /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW;  
  
} //endwhen _9yrHHrw0SbZ_2da6hoDlbev  
/*endcond _28OEq9p17rL_4fKBMly70SD*/ 
 
 
if /*cond _2e8g1RnPvBb_8sEgpX6OvDV*/  
/*when _0ACVDQefshl_2vjIsEKkehH:*/ 
 (/*lazy and_then:*/ (intptr_t) (1 && ( /*v_idprefixstr:*/_.v_6wh43lYjXiZ_9MUWTOiTsOl) && ( /*o_idtarget:*/_.o_1E1n1xq22bH_7JEWM863KYo))) { //body when _0ACVDQefshl_2vjIsEKkehH  
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
 
//+ #8/10 of block _0aMhdgQGit6_9yp9HB8SWvo :: 
 
if /*cond _0HUpaLYud7t_4muHwMPSlJG*/  
/*when _3pBzyb7Hfaa_4nDOJLFNIsW:*/ 
 (/*is_null:*/(( /*v_more:*/_.v_09jnZdQe0uA_088LqcQDlbX)==NULL)) { //body when _3pBzyb7Hfaa_4nDOJLFNIsW  
  
{ // run _6d8DRoTkP6q_41zwG3AqyTM  
/*no-op v_more emit-tagged-id-more-xhtml-open _6d8DRoTkP6q_41zwG3AqyTM*/;  
} // end run _6d8DRoTkP6q_41zwG3AqyTM  
  
} //endwhen _3pBzyb7Hfaa_4nDOJLFNIsW  
else if  
/*when _8MCtQOZKHVk_7RAN0Fuzf4d:*/ 
 (/*is_stringv:*/ isstring_BM( /*v_more:*/_.v_09jnZdQe0uA_088LqcQDlbX)) { //body when _8MCtQOZKHVk_7RAN0Fuzf4d  
{ // start out _30unaF20yj1_8WVY0AQ2yWf to o_strbuf   
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_more:*/_.v_09jnZdQe0uA_088LqcQDlbX)));  
} // end out _30unaF20yj1_8WVY0AQ2yWf  
  
} //endwhen _8MCtQOZKHVk_7RAN0Fuzf4d  
else if  
/*when _9d8dzvcDCgQ_4aUw3iYoDqF:*/ 
 (/*isclosure:*/isclosure_BM(( /*v_more:*/_.v_09jnZdQe0uA_088LqcQDlbX))) { //body when _9d8dzvcDCgQ_4aUw3iYoDqF  
  
{ // run _1DPvTtOGoTT_5JOkK9cx25T  
/*emit-tagged-id-more-xhtml-open closure v_more o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emit-tagged-id-more-xhtml-open  closure €%.9s v_more=%s o_helem=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_1DPvTtOGoTT_5JOkK9cx25T",
 OUTSTRVALUE_BM( /*v_more:*/_.v_09jnZdQe0uA_088LqcQDlbX),
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int)  /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f);;  
} // end run _1DPvTtOGoTT_5JOkK9cx25T  
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _4tODk9fdjjB_7yUKEqmjaSY   
(apply4_BM (( /*v_more:*/_.v_09jnZdQe0uA_088LqcQDlbX), ((struct stackframe_stBM*)&_), 
 ( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))));  
  
{ // run _4pRUECXTDyV_2FwLcZ7YJNi  
/*debug emit-tagged-id-more-xhtml-open after-apply v_more v_resemit o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emit-tagged-id-more-xhtml-open after-apply €%.9s v_more=%s v_resemit=%s o_helem=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_4pRUECXTDyV_2FwLcZ7YJNi",
 OUTSTRVALUE_BM( /*v_more:*/_.v_09jnZdQe0uA_088LqcQDlbX),
 OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
;  
} // end run _4pRUECXTDyV_2FwLcZ7YJNi  
if /*cond _9Jo9BPIOkFx_3aCHDhdBVYO*/   
/*when _1QXX2qP3T02_6TInlg8LlSH:*/  
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _1QXX2qP3T02_6TInlg8LlSH   
//failure _3U4iMDjauSJ_350GrrqVStR    
PLACEDFAILURE_BM(__LINE__,    
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[40] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[23] /*!apply*/)), 
 
( /*v_more:*/_.v_09jnZdQe0uA_088LqcQDlbX), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[26] /*|_3U4iMDjauSJ_350GrrqVStR*/)),
                ((struct stackframe_stBM *) &_));
   
} //endwhen _1QXX2qP3T02_6TInlg8LlSH   
/*endcond _9Jo9BPIOkFx_3aCHDhdBVYO*/  
  
} //endwhen _9d8dzvcDCgQ_4aUw3iYoDqF  
else { /*cond else _0HUpaLYud7t_4muHwMPSlJG*/  
//failure _1LdXMeDLWFL_0df1wmR8KD7  
PLACEDFAILURE_BM(__LINE__,  
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[71] /*!failure_type_error*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[63] /*!_85938GaqS1z_3mZSenKG7GG*/)), 
 
( /*v_more:*/_.v_09jnZdQe0uA_088LqcQDlbX), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[7] /*|_1LdXMeDLWFL_0df1wmR8KD7*/)),
                ((struct stackframe_stBM *) &_));
} /*cond else _0HUpaLYud7t_4muHwMPSlJG*/  
/*endcond _0HUpaLYud7t_4muHwMPSlJG*/ 
 
 
/*return _7r8Nb0kzrtj_3ZwcXoiPUBk:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*v_htmltagstr:*/_.v_6p6w3jZv5gy_58EzMDpOBQJ; 
 goto epilog_85938GaqS1z_3mZSenKG7GG; 
 
/* !endingblock _0aMhdgQGit6_9yp9HB8SWvo */ 
goto endblock__0aMhdgQGit6_9yp9HB8SWvo; 
endblock__0aMhdgQGit6_9yp9HB8SWvo: ; 
} /*-block _0aMhdgQGit6_9yp9HB8SWvo */

 epilog_85938GaqS1z_3mZSenKG7GG: __attribute__ ((unused)); // routine _85938GaqS1z_3mZSenKG7GG epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _85938GaqS1z_3mZSenKG7GG routine#8 _85938GaqS1z_3mZSenKG7GG




value_tyBM crout_8oKFbiPI4JW_7EPg4RP1e4Q_BM //#9
 (struct stackframe_stBM* stkf, //
//!emit-raw-tag-xhtml-open [v_tagstr v_restagstr] (o_helem o_emitctx o_strbuf v_depth)
  // 4 arguments
  const value_tyBM arg0,  // o_helem
  const value_tyBM arg1,  // o_emitctx
  const value_tyBM arg2,  // o_strbuf
  const value_tyBM arg3,  // v_depth
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _8oKFbiPI4JW_7EPg4RP1e4Q
  struct frame_8oKFbiPI4JW_7EPg4RP1e4Q_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 7 local values:
    value_tyBM v_0iT9NuqVo8P_188wxqHeyJZ; // v_tagstr
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    objectval_tyBM* o_6Ef2ORO1Mni_0tpNoRQGmrW; // o_helem
    value_tyBM v_9cegxYI6jp7_38M0kzhUBGZ; // v_restagstr
    objectval_tyBM* o_9nXRmTATjN4_5F9V7RvvgW0; // o_emitctx
    /// 1 local numbers:
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
   } _;
   memset (&_, 0, sizeof(struct frame_8oKFbiPI4JW_7EPg4RP1e4Q_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 7;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[67] /*|_8oKFbiPI4JW_7EPg4RP1e4Q*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 4 arguments:
   _.o_6Ef2ORO1Mni_0tpNoRQGmrW = objectcast_BM (arg0); // o_helem
   _.o_9nXRmTATjN4_5F9V7RvvgW0 = objectcast_BM (arg1); // o_emitctx
   _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg2); // o_strbuf
   _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
   // fetched 4 arguments.
   { // fetch 2 closed values in _8oKFbiPI4JW_7EPg4RP1e4Q:
   const closure_tyBM* callclos_8oKFbiPI4JW_7EPg4RP1e4Q =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   unsigned nbclosed_8oKFbiPI4JW_7EPg4RP1e4Q = closurewidth_BM ((const value_tyBM) callclos_8oKFbiPI4JW_7EPg4RP1e4Q);
   if (nbclosed_8oKFbiPI4JW_7EPg4RP1e4Q > 0)
      _.v_0iT9NuqVo8P_188wxqHeyJZ = callclos_8oKFbiPI4JW_7EPg4RP1e4Q->nodt_sons[0]; // v_tagstr
   if (nbclosed_8oKFbiPI4JW_7EPg4RP1e4Q > 1)
      _.v_9cegxYI6jp7_38M0kzhUBGZ = callclos_8oKFbiPI4JW_7EPg4RP1e4Q->nodt_sons[1]; // v_restagstr
   } // fetched 2 closed values in _8oKFbiPI4JW_7EPg4RP1e4Q.
   // routine _8oKFbiPI4JW_7EPg4RP1e4Q body:

startblock__7KHtshQThGs_241rpVG5ROB: __attribute__((unused));
{ /* +block _7KHtshQThGs_241rpVG5ROB */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _4zMf8sV8fya_53ohURmAkaW  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 
{ // run _6wN1BBVklb1_7hPBRYc2ARV 
/*debug emit-raw-tag-xtml-open start v_tagstr v_restagstr o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emit-raw-tag-xtml-open start €%.9s v_tagstr=%s v_restagstr=%s o_helem=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_6wN1BBVklb1_7hPBRYc2ARV",
 OUTSTRVALUE_BM( /*v_tagstr:*/_.v_0iT9NuqVo8P_188wxqHeyJZ),
 OUTSTRVALUE_BM( /*v_restagstr:*/_.v_9cegxYI6jp7_38M0kzhUBGZ),
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
; 
} // end run _6wN1BBVklb1_7hPBRYc2ARV 
 
//+ #2/4 of block _7KHtshQThGs_241rpVG5ROB :: 
 
{ // start out _0YakDRP6oMW_1fmgsYHqttA to o_strbuf  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "<");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_tagstr:*/_.v_0iT9NuqVo8P_188wxqHeyJZ)));  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " ");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_restagstr:*/_.v_9cegxYI6jp7_38M0kzhUBGZ)));  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " "); 
} // end out _0YakDRP6oMW_1fmgsYHqttA 
 
 
/*return _96OlQ8gect6_5cLu4jJn0WG:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*v_tagstr:*/_.v_0iT9NuqVo8P_188wxqHeyJZ; 
 goto epilog_8oKFbiPI4JW_7EPg4RP1e4Q; 
 
/* !endingblock _7KHtshQThGs_241rpVG5ROB */ 
goto endblock__7KHtshQThGs_241rpVG5ROB; 
endblock__7KHtshQThGs_241rpVG5ROB: ; 
} /*-block _7KHtshQThGs_241rpVG5ROB */

 epilog_8oKFbiPI4JW_7EPg4RP1e4Q: __attribute__ ((unused)); // routine _8oKFbiPI4JW_7EPg4RP1e4Q epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _8oKFbiPI4JW_7EPg4RP1e4Q routine#9 _8oKFbiPI4JW_7EPg4RP1e4Q




value_tyBM crout_8IYFtn8osS2_4t1U3wyROLW_BM //#10+
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
    /// 13 local values:
    value_tyBM v_0qTBOEAT5pa_2fz1SKfHrMV; // v_resemit
    value_tyBM v_0DmuWueFbx9_5bzv8xgw3fu; // v_html
    value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
    objectval_tyBM* o_13K9OfeXRZR_84nyRTtoj81; // o_conn
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    value_tyBM v_5GhvzWWP1jl_41tgAIAAa2X; // v_resapp
    value_tyBM v_6KzoPNta5a2_7EsZceEn0Px; // v_clos
    objectval_tyBM* o_6Z4UU939WbU_8BK9xcKsXNb; // o_comp
    objectval_tyBM* o_7Ga6z7nroCG_3ikx3GHV41r; // o_spacing
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
   _.stkfram_head.rlen = 13;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*|emit_xhtml*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // locking 1:
    objectval_tyBM* locked_90WWBgxcOuU_9UT2wirExrs = NULL; // for o_html
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
 
//+ #2/7 of block _3DcbHfTP2te_8Zw8Uhy9eU6 :: 
 
if /*cond _8hRp9kZ7uvu_4MzyhRQIoRd*/  
/*when _70ZSzCpjqWE_1AjclUpwXjD:*/ 
 (/*objstrbufferispercentfullpayl:*/(intptr_t)objstrbufferispercentfullpayl_BM(( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),(int)( 90))) { //body when _70ZSzCpjqWE_1AjclUpwXjD  
//failure _8yowRQLZgzP_4vqWjo12OS4   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[20] /*!failure_full*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[68] /*|_8yowRQLZgzP_4vqWjo12OS4*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _70ZSzCpjqWE_1AjclUpwXjD  
/*endcond _8hRp9kZ7uvu_4MzyhRQIoRd*/ 
 
 
if /*cond _24sbIpdvwNd_9c4S4cSYLYE*/  
/*when _0lnsrM6CMWA_4PCoTTYLR3e:*/ 
 ((/*greater_int:*/( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) > ( 100))) { //body when _0lnsrM6CMWA_4PCoTTYLR3e  
//failure _79ub6Ngc5aa_42TtfuLTsPs   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[40] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[54] /*|_79ub6Ngc5aa_42TtfuLTsPs*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _0lnsrM6CMWA_4PCoTTYLR3e  
/*endcond _24sbIpdvwNd_9c4S4cSYLYE*/ 
 
//+ #4/7 of block _3DcbHfTP2te_8Zw8Uhy9eU6 :: 
 
if /*cond _23svN0ubUj6_7fLFEqkDSEu*/  
/*when _9cxwgaKvQ54_9K6aTU2AQzN:*/ 
 (/*is_stringv:*/ isstring_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu)) { //body when _9cxwgaKvQ54_9K6aTU2AQzN  
{ // start out _62fXPYzqGwr_5H0PGqpC14n to o_strbuf   
/*out html_enc:*/ objstrbufferencodedhtmlpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu)), -1);  
} // end out _62fXPYzqGwr_5H0PGqpC14n  
  
} //endwhen _9cxwgaKvQ54_9K6aTU2AQzN  
else if  
/*when _4RuQm2ZMfBZ_79wF6EY90Pa:*/ 
 (/*is_intv*/ istaggedint_BM (  /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu )) { //body when _4RuQm2ZMfBZ_79wF6EY90Pa  
{ // start out _1TvJfdrHius_77fMbfoQAr6 to o_strbuf   
/*out int:*/ objstrbufferprintfpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "%lld", (long long)  /* val_to_int */ getint_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu) );  
} // end out _1TvJfdrHius_77fMbfoQAr6  
  
} //endwhen _4RuQm2ZMfBZ_79wF6EY90Pa  
else if  
/*when _12aOmQZ7w1A_9zXnaBp4lvh:*/ 
 (/*is_null:*/(( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu)==NULL)) { //body when _12aOmQZ7w1A_9zXnaBp4lvh  
{ // start cexpansion _1h4VIGqtqjW_7FSgoLSbms4 - no_op   
/*no_op _1h4VIGqtqjW_7FSgoLSbms4*/;   
} // end cexpansion _1h4VIGqtqjW_7FSgoLSbms4 - no_op   
  
} //endwhen _12aOmQZ7w1A_9zXnaBp4lvh  
else if  
/*when _42nuxS0Drb8_9JCL7g50PlX:*/ 
 (/*is_doublev:*/isdouble_BM(( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu))) { //body when _42nuxS0Drb8_9JCL7g50PlX  
{ // start out _0yKyGAvWxxy_4BllWwOJyhU to o_strbuf   
/*out double_plain:*/ objstrbufferprintfpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "%g", /*val_to_double:*/getdouble_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu));  
} // end out _0yKyGAvWxxy_4BllWwOJyhU  
  
} //endwhen _42nuxS0Drb8_9JCL7g50PlX  
else if  
/*when _9TuXFcuSgTD_6Fd17aYrxkb:*/ 
 (/*is_objectv*/ isobject_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu)) { //body when _9TuXFcuSgTD_6Fd17aYrxkb  
 /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf = //assign _8gKMIBbWJoK_44yP55H6Yp4   
/*val_to_object:*/objectcast_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu);  
  
{ // begin objswitch _8lmPaSnQ7vo_33pxLUv2PDV  
//!objswitch! objswitch o_html ... in emit_xhtml .  
 objectval_tyBM* objswexp_8lmPaSnQ7vo_33pxLUv2PDV = ( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf);  
 switch (objecthash_BM (objswexp_8lmPaSnQ7vo_33pxLUv2PDV) % 16) {  
 case 2:  
  if (objswexp_8lmPaSnQ7vo_33pxLUv2PDV ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[55] /*|nlsp*/)) goto whenobj8lmPaSnQ__5TnmFtNZk83_8aW0nHP7fZX;  
  goto defobj_8lmPaSnQ7vo_33pxLUv2PDV;  
 case 6:  
  if (objswexp_8lmPaSnQ7vo_33pxLUv2PDV ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[11] /*|newline*/)) goto whenobj8lmPaSnQ__9thTL0gOefq_2PbnKHKqRc2;  
  if (objswexp_8lmPaSnQ7vo_33pxLUv2PDV ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[17] /*|space*/)) goto whenobj8lmPaSnQ__74lJynQT1Jc_1sbt3E0bmFG;  
  goto defobj_8lmPaSnQ7vo_33pxLUv2PDV;  
 case 9:  
  if (objswexp_8lmPaSnQ7vo_33pxLUv2PDV ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[6] /*|none*/)) goto whenobj8lmPaSnQ__4MR4gMierKM_7OBmIrhHfd8;  
  goto defobj_8lmPaSnQ7vo_33pxLUv2PDV;  
  
  default: defobj_8lmPaSnQ7vo_33pxLUv2PDV:;  
  
 // objswitch _8lmPaSnQ7vo_33pxLUv2PDV default#0 block:   
   
{ // begin lockobj _90WWBgxcOuU_9UT2wirExrs   
  objectval_tyBM* curlockedob_90WWBgxcOuU_9UT2wirExrs = ( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf);   
if (objlock_BM (curlockedob_90WWBgxcOuU_9UT2wirExrs)) {    
locked_90WWBgxcOuU_9UT2wirExrs = curlockedob_90WWBgxcOuU_9UT2wirExrs;    
    
   
{ // run _6FAdm53XsNC_8r8b5n1Wk9e   
/*debug emit_xhtml object o_html o_emitctx o_strbuf depth*/
   DBGPRINTF_BM("emit_xhtml object €%.9s o_html=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
   "_6FAdm53XsNC_8r8b5n1Wk9e",
   objectdbg_BM( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),
   objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
   objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
   ;   
} // end run _6FAdm53XsNC_8r8b5n1Wk9e   
    
if /*cond _6Hu5qCGphFo_1GJxMo7Jlkk*/    
/*when _4rO8088H2lW_18rRyGDz6EI:*/   
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[41] /*!html_void_element_object*/)))) { //body when _4rO8088H2lW_18rRyGDz6EI    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _8RmTnjiecvY_1e1Vf8MVokZ     
(apply4_BM (( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[3] /*!_0FRLxSGQlZ0_0qrrUZlEeKp*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))));    
    
{ // run _51QfdWxWnEC_5HSngQpViDj    
/*debug emit_xhtml after emitxhtml_void_element v_resemit o_html o_emitctx o_strbuf depth*/
   DBGPRINTF_BM("emit_xhtml after emitxhtml_void_element €%.9s v_resemit=%s o_html=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
   "_51QfdWxWnEC_5HSngQpViDj",
   OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
   objectdbg_BM( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),
   objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
   objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
   ;    
} // end run _51QfdWxWnEC_5HSngQpViDj    
if /*cond _9t0qbbenqEL_8XJtKd4Upqb*/     
/*when _41ZNn4BXqRJ_994z6o2Ab3x:*/    
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _41ZNn4BXqRJ_994z6o2Ab3x     
//failure _4veY1dO90jF_7ThxWXJ0cIl      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[40] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[3] /*!_0FRLxSGQlZ0_0qrrUZlEeKp*/)), 
 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[31] /*|_4veY1dO90jF_7ThxWXJ0cIl*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _41ZNn4BXqRJ_994z6o2Ab3x     
/*endcond _9t0qbbenqEL_8XJtKd4Upqb*/    
/*return _22GngskXfoL_8r0RCbldM5B:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV;    
 goto epilog_8IYFtn8osS2_4t1U3wyROLW;    
    
} //endwhen _4rO8088H2lW_18rRyGDz6EI    
else if    
/*when _4ZDiBjqE148_9SJqgtSgqjk:*/   
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[57] /*!html_element_object*/)))) { //body when _4ZDiBjqE148_9SJqgtSgqjk    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _5eOG5u6rqzs_8IcECCzClD6     
(apply4_BM (( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[44] /*!_5NH940lCHYJ_3nuRm3flnzc*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))));    
    
{ // run _6KUGtdzbZDq_5kEyhi5JGKY    
/*debug emit_xhtml after emitxhtml_element v_resemit o_html o_emitctx o_strbuf depth*/
   DBGPRINTF_BM("emit_xhtml after emitxhtml_element €%.9s v_resemit=%s o_html=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
   "_6KUGtdzbZDq_5kEyhi5JGKY",
   OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
   objectdbg_BM( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),
   objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
   objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
   ;    
} // end run _6KUGtdzbZDq_5kEyhi5JGKY    
if /*cond _11T1q3OMSxq_5u3kAcBoZUb*/     
/*when _4NI7aLXhyp4_1w0Je6uVAy8:*/    
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _4NI7aLXhyp4_1w0Je6uVAy8     
//failure _3O7E8gjmVNG_42OFG3GueZX      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[40] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[44] /*!_5NH940lCHYJ_3nuRm3flnzc*/)), 
 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[24] /*|_3O7E8gjmVNG_42OFG3GueZX*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _4NI7aLXhyp4_1w0Je6uVAy8     
/*endcond _11T1q3OMSxq_5u3kAcBoZUb*/    
/*return _1CS9B9875jz_7kDKAd9nve8:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV;    
 goto epilog_8IYFtn8osS2_4t1U3wyROLW;    
    
} //endwhen _4ZDiBjqE148_9SJqgtSgqjk    
else if    
/*when _2UYWFkodmko_0m3GeHsEJtj:*/   
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[53] /*!html_active_object*/)))) { //body when _2UYWFkodmko_0m3GeHsEJtj    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _8QXmQ57vzCG_4EwgpyHDJ14     
(send3_BM (( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), /*sel:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),  ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))));    
    
{ // run _6S70YEhf40k_70YLtQefVyc    
/*debug emit_xhtml sent to html_active_object v_resemit o_html o_emitctx o_strbuf depth*/
   DBGPRINTF_BM("emit_xhtml sent to html_active_object €%.9s v_resemit=%s o_html=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
   "_6S70YEhf40k_70YLtQefVyc",
   OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
   objectdbg_BM( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),
   objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
   objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
   ;    
} // end run _6S70YEhf40k_70YLtQefVyc    
if /*cond _5xqEwW1k6Yw_1AuYU1a30cp*/     
/*when _311HixMi74e_1qIu77Ib0dD:*/    
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _311HixMi74e_1qIu77Ib0dD     
//failure _4fUC5oegPuC_8hJQc9RBblV      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[40] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[53] /*!html_active_object*/)), 
 
( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[28] /*|_4fUC5oegPuC_8hJQc9RBblV*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _311HixMi74e_1qIu77Ib0dD     
/*endcond _5xqEwW1k6Yw_1AuYU1a30cp*/    
/*return _45LV6X6jH5p_2COyhr6KJHJ:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV;    
 goto epilog_8IYFtn8osS2_4t1U3wyROLW;    
    
} //endwhen _2UYWFkodmko_0m3GeHsEJtj    
else if    
/*when _2qeuoOXokje_4oj6X9P4qUV:*/   
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[56] /*!html_sequence_object*/)))) { //body when _2qeuoOXokje_4oj6X9P4qUV    
 /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r = //assign _5WKZTYK0s3r_7HMBFv257DD     
/*as_object:*/objectcast_BM((send2_BM (( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), /*sel:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[62] /*!html_spacing*/)), ((struct stackframe_stBM*)&_),  
 ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),  (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)))));    
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _2sIzIuXJ284_0FLejnQNFWi     
/*objnbcomps:*/ objnbcomps_BM ( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf);    
    
{ // run _2dWherm8Qq5_5dMySjMueb0    
/*debug emit_xhtml html_sequence_object o_html leni o_spacing o_emitctx o_strbuf depth*/
     DBGPRINTF_BM("emit_xhtml html_sequence_object  €%.9s o_html=%s leni#%ld o_spacing=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
     "_2dWherm8Qq5_5dMySjMueb0",
     objectdbg_BM( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),
     (long int) ( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k),
     objectdbg1_BM( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r),
     objectdbg2_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
     objectdbg3_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
     objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
     (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
     ;    
} // end run _2dWherm8Qq5_5dMySjMueb0    
{ //for-up _54XLb4cEefQ_4n5xPoePqN1     
intptr_t cnt_54XLb4cEefQ_4n5xPoePqN1 =  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k;     
for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;     
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_54XLb4cEefQ_4n5xPoePqN1;     
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++) {     
// for-up _54XLb4cEefQ_4n5xPoePqN1 #0 :     
if /*cond _3EDeEwM9fti_4HLOXeN3v92*/      
/*when _5icpCcWHLp9_3pKk7OH9VP9:*/     
 (/*lazy and_then:*/ (intptr_t) (1 && ((/*greater_int:*/( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) > ( 0))) && ( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r))) { //body when _5icpCcWHLp9_3pKk7OH9VP9      
      
{ // begin objswitch _0shUy80I2UQ_5UJrLOmsND6      
//!objswitch! objswitch o_spacing  // emit_xhtml for html_sequence_object .      
 objectval_tyBM* objswexp_0shUy80I2UQ_5UJrLOmsND6 = ( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r);      
 switch (objecthash_BM (objswexp_0shUy80I2UQ_5UJrLOmsND6) % 16) {      
 case 2:      
  if (objswexp_0shUy80I2UQ_5UJrLOmsND6 ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[55] /*|nlsp*/)) goto whenobj0shUy80I__1zz07iK23id_9u2MqG03Lmy;      
  goto defobj_0shUy80I2UQ_5UJrLOmsND6;      
 case 6:      
  if (objswexp_0shUy80I2UQ_5UJrLOmsND6 ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[11] /*|newline*/)) goto whenobj0shUy80I__1eRlKv9qmAR_0ikOOttDjM6;      
  if (objswexp_0shUy80I2UQ_5UJrLOmsND6 ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[17] /*|space*/)) goto whenobj0shUy80I__0fBdu6WjnyY_9E6TqmPfXBu;      
  goto defobj_0shUy80I2UQ_5UJrLOmsND6;      
      
  default: defobj_0shUy80I2UQ_5UJrLOmsND6:;      
      
break; // end objswitch _0shUy80I2UQ_5UJrLOmsND6 default       
// objswitch _0shUy80I2UQ_5UJrLOmsND6 with 3 whens:       
       
whenobj0shUy80I__0fBdu6WjnyY_9E6TqmPfXBu:; // when #0 of objswitch _0shUy80I2UQ_5UJrLOmsND6       
 // objswitch _0shUy80I2UQ_5UJrLOmsND6 when _0fBdu6WjnyY_9E6TqmPfXBu #0 statement:       
{ // start out _0sppzw256Sc_2AGjk1KvKEY to o_strbuf        
/*out space:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " ");       
} // end out _0sppzw256Sc_2AGjk1KvKEY       
       
       
break; // end when _0fBdu6WjnyY_9E6TqmPfXBu #0 of objswitch _0shUy80I2UQ_5UJrLOmsND6       
       
whenobj0shUy80I__1eRlKv9qmAR_0ikOOttDjM6:; // when #1 of objswitch _0shUy80I2UQ_5UJrLOmsND6       
 // objswitch _0shUy80I2UQ_5UJrLOmsND6 when _1eRlKv9qmAR_0ikOOttDjM6 #0 statement:       
{ // start out _1k6MXthFO5C_3tMuwBhjvLL to o_strbuf        
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);       
} // end out _1k6MXthFO5C_3tMuwBhjvLL       
       
       
break; // end when _1eRlKv9qmAR_0ikOOttDjM6 #1 of objswitch _0shUy80I2UQ_5UJrLOmsND6       
       
whenobj0shUy80I__1zz07iK23id_9u2MqG03Lmy:; // when #2 of objswitch _0shUy80I2UQ_5UJrLOmsND6       
 // objswitch _0shUy80I2UQ_5UJrLOmsND6 when _1zz07iK23id_9u2MqG03Lmy #0 statement:       
{ // start out _4M7FETiKvTY_8IoOjsNsq3w to o_strbuf        
/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);       
} // end out _4M7FETiKvTY_8IoOjsNsq3w       
       
       
break; // end when _1zz07iK23id_9u2MqG03Lmy #2 of objswitch _0shUy80I2UQ_5UJrLOmsND6       
      
} } // end objswitch _0shUy80I2UQ_5UJrLOmsND6      
      
} //endwhen _5icpCcWHLp9_3pKk7OH9VP9      
/*endcond _3EDeEwM9fti_4HLOXeN3v92*/     
     
// for-up _54XLb4cEefQ_4n5xPoePqN1 #1 :     
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _3gmkj26oGXz_2LaopZABjri      
/*objgetcomp:*/objgetcomp_BM (( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));     
     
// for-up _54XLb4cEefQ_4n5xPoePqN1 #2 :     
     
{ // run _4yiRAAvFoE9_80tCAWHcMMu     
/*debug emit_xhtml html_sequence_object ii v_comp o_html o_emitctx o_strbuf depth*/
     DBGPRINTF_BM("emit_xhtml html_sequence_object €%.9s ii#%ld v_comp=%s o_html=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
     "_4yiRAAvFoE9_80tCAWHcMMu",
     (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
     OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
     objectdbg_BM( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),
     objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
     objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
     objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
     (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
     ;     
} // end run _4yiRAAvFoE9_80tCAWHcMMu     
     
// for-up _54XLb4cEefQ_4n5xPoePqN1 #3 :     
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _6yJXzskdfaJ_3Vin16Ghsp5      
(apply4_BM (( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), ((struct stackframe_stBM*)&_), 
 ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));     
     
// for-up _54XLb4cEefQ_4n5xPoePqN1 #4 :     
     
{ // run _9zF7i2MzcJ9_8BdWPrpiXu5     
/*debug emit_xhtml for html_sequence_object v_resemit v_comp ii o_html o_emitctx o_strbuf depth*/
   DBGPRINTF_BM("emit_xhtml for html_sequence_object €%.9s v_resemit=%s v_comp=%s ii#%ld o_html=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
   "_9zF7i2MzcJ9_8BdWPrpiXu5",
   OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
   OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
   (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
   objectdbg_BM( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),
   objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
   objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
   ;     
} // end run _9zF7i2MzcJ9_8BdWPrpiXu5     
     
// for-up _54XLb4cEefQ_4n5xPoePqN1 #5 :     
if /*cond _9Y6Y5e5NOFQ_2PwCbfhLunh*/      
/*when _6IAvpG656Rv_6PkWylgif6b:*/     
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _6IAvpG656Rv_6PkWylgif6b      
//failure _650BGD0ANMH_4gN3duymnz3       
PLACEDFAILURE_BM(__LINE__,       
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[40] /*!failure_miss*/)), 
 /*make_node 8 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[56] /*!html_sequence_object*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[47] /*|_650BGD0ANMH_4gN3duymnz3*/)),
                ((struct stackframe_stBM *) &_));
      
} //endwhen _6IAvpG656Rv_6PkWylgif6b      
/*endcond _9Y6Y5e5NOFQ_2PwCbfhLunh*/     
    
}} // end for-up _54XLb4cEefQ_4n5xPoePqN1    
/*return _4UAxOC9QDXi_29LAzvD62YV:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV;    
 goto epilog_8IYFtn8osS2_4t1U3wyROLW;    
    
} //endwhen _2qeuoOXokje_4oj6X9P4qUV    
else { /*cond else _6Hu5qCGphFo_1GJxMo7Jlkk*/    
 /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px = //assign _9nlGqf1rNo5_1utp9oJKXbm    
/*objgetattr:*/objgetattr_BM(( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)));   
if /*cond _7p56FfOuvJs_9FeqUiGYAeh*/    
/*when _3eYq8a0OFYN_9mNd6nDdR0c:*/   
 ( /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px) { //body when _3eYq8a0OFYN_9mNd6nDdR0c    
    
{ // run _9dFWrdci8Hx_5L9U0q1WnTE    
/*emit_xhtml ordinary v_clos o_html o_emitctx o_strbuf depth*/
       DBGPRINTF_BM("emit_xhtml €%.9s ordinary v_clos=%s o_html=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
        "_9dFWrdci8Hx_5L9U0q1WnTE",
        OUTSTRVALUE_BM( /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px),
        objectdbg_BM( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),  objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
        objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
        (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
   ;    
} // end run _9dFWrdci8Hx_5L9U0q1WnTE    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _3TPB3xZxoql_5X5J7RdvF34     
(apply4_BM (( /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px), ((struct stackframe_stBM*)&_), 
 ( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));    
    
{ // run _8C4hm3Zp5k4_705ymFnj8CK    
/*emit_xhtml ordinary v_resemit o_html o_emitctx o_strbuf depth*/
       DBGPRINTF_BM("emit_xhtml €%.9s ordinary v_resemit=%s o_html=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
        "_8C4hm3Zp5k4_705ymFnj8CK",
        OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
        objectdbg_BM( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),  objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
        objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),   objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
        (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
   ;    
} // end run _8C4hm3Zp5k4_705ymFnj8CK    
if /*cond _5s4xAqnhamH_6JvlJDcrmQu*/     
/*when _25d5VIDZoHD_5TUaHaHbbol:*/    
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _25d5VIDZoHD_5TUaHaHbbol     
//failure _4Hsn8KettH9_38n6JYQgUiC      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[40] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px), 
 
( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[35] /*|_4Hsn8KettH9_38n6JYQgUiC*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _25d5VIDZoHD_5TUaHaHbbol     
/*endcond _5s4xAqnhamH_6JvlJDcrmQu*/    
    
} //endwhen _3eYq8a0OFYN_9mNd6nDdR0c    
else { /*cond else _7p56FfOuvJs_9FeqUiGYAeh*/    
{ // start out _3O7lZ9FpKWt_1K69hkQtd2b to o_strbuf    
/*out object:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, objectdbg_BM ( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf));   
} // end out _3O7lZ9FpKWt_1K69hkQtd2b   
} /*cond else _7p56FfOuvJs_9FeqUiGYAeh*/    
/*endcond _7p56FfOuvJs_9FeqUiGYAeh*/   
} /*cond else _6Hu5qCGphFo_1GJxMo7Jlkk*/    
/*endcond _6Hu5qCGphFo_1GJxMo7Jlkk*/   
    
objunlock_BM (locked_90WWBgxcOuU_9UT2wirExrs), locked_90WWBgxcOuU_9UT2wirExrs = NULL;   
} } // end objlock _90WWBgxcOuU_9UT2wirExrs   
break; // end objswitch _8lmPaSnQ7vo_33pxLUv2PDV default   
// objswitch _8lmPaSnQ7vo_33pxLUv2PDV with 4 whens:   
   
whenobj8lmPaSnQ__4MR4gMierKM_7OBmIrhHfd8:; // when #0 of objswitch _8lmPaSnQ7vo_33pxLUv2PDV   
 // objswitch _8lmPaSnQ7vo_33pxLUv2PDV when _4MR4gMierKM_7OBmIrhHfd8 #0 statement:   
   
{ // run _5u9UMIcHQQT_7DwvkbNUCpe   
/*no-op when none emit_xhtml*/;   
} // end run _5u9UMIcHQQT_7DwvkbNUCpe   
   
   
break; // end when _4MR4gMierKM_7OBmIrhHfd8 #0 of objswitch _8lmPaSnQ7vo_33pxLUv2PDV   
   
whenobj8lmPaSnQ__5TnmFtNZk83_8aW0nHP7fZX:; // when #1 of objswitch _8lmPaSnQ7vo_33pxLUv2PDV   
 // objswitch _8lmPaSnQ7vo_33pxLUv2PDV when _5TnmFtNZk83_8aW0nHP7fZX #0 statement:   
{ // start out _4yeOifqSCJS_2iE3ipgYM8m to o_strbuf    
/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);   
} // end out _4yeOifqSCJS_2iE3ipgYM8m   
   
   
break; // end when _5TnmFtNZk83_8aW0nHP7fZX #1 of objswitch _8lmPaSnQ7vo_33pxLUv2PDV   
   
whenobj8lmPaSnQ__74lJynQT1Jc_1sbt3E0bmFG:; // when #2 of objswitch _8lmPaSnQ7vo_33pxLUv2PDV   
 // objswitch _8lmPaSnQ7vo_33pxLUv2PDV when _74lJynQT1Jc_1sbt3E0bmFG #0 statement:   
{ // start out _13WJKLMhN6o_8MjYflQqoZS to o_strbuf    
/*out space:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " ");   
} // end out _13WJKLMhN6o_8MjYflQqoZS   
   
   
break; // end when _74lJynQT1Jc_1sbt3E0bmFG #2 of objswitch _8lmPaSnQ7vo_33pxLUv2PDV   
   
whenobj8lmPaSnQ__9thTL0gOefq_2PbnKHKqRc2:; // when #3 of objswitch _8lmPaSnQ7vo_33pxLUv2PDV   
 // objswitch _8lmPaSnQ7vo_33pxLUv2PDV when _9thTL0gOefq_2PbnKHKqRc2 #0 statement:   
{ // start out _9nRkS8GEl9G_2mv6l7bVrJd to o_strbuf    
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);   
} // end out _9nRkS8GEl9G_2mv6l7bVrJd   
   
   
break; // end when _9thTL0gOefq_2PbnKHKqRc2 #3 of objswitch _8lmPaSnQ7vo_33pxLUv2PDV   
  
} } // end objswitch _8lmPaSnQ7vo_33pxLUv2PDV  
  
} //endwhen _9TuXFcuSgTD_6Fd17aYrxkb  
else if  
/*when _0TcBev05JBd_3KDoGzpRVI6:*/ 
 (/*isnode:*/isnode_BM(( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu))) { //body when _0TcBev05JBd_3KDoGzpRVI6  
 /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81 = //assign _8mLV308aNE8_09Fp4By5gyJ   
/*nodeconn:*/nodeconn_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu);  
  
{ // run _85H5ux3Ioa4_0EafKQh3hja  
/*emit_xhtml node v_html o_conn o_emitctx o_strbuf depth*/
       DBGPRINTF_BM("emit_xhtml €%.9s node v_html=%s o_conn=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
        "_85H5ux3Ioa4_0EafKQh3hja",
        OUTSTRVALUE_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),
        objectdbg_BM( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),  objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
        objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),   objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
        (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
   ;  
} // end run _85H5ux3Ioa4_0EafKQh3hja  
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _9NylfF5tmgY_8hzqgAUkFOY   
/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe);  
  
{ // begin objswitch _4ySLl7UU6Hw_7pgQRbU4gFX  
//!objswitch! objswitch o_conn // emit_xhtml node .  
 objectval_tyBM* objswexp_4ySLl7UU6Hw_7pgQRbU4gFX = ( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81);  
 switch (objecthash_BM (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX) % 32) {  
 case 0:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[13] /*|utf8_enc*/)) goto whenobj4ySLl7UU__24qz4eJavv3_1P062j7RIWK;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 2:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[61] /*|hexa*/)) goto whenobj4ySLl7UU__2LXkoXMNcGg_6FWal4v09Nf;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 5:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[0] /*|comment*/)) goto whenobj4ySLl7UU__8SBMgF9WUmn_0k1vdQISETG;  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[48] /*|c_enc*/)) goto whenobj4ySLl7UU__7uiwyR9sfq3_1W9SQnuJLSz;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 9:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[15] /*|local_time*/)) goto whenobj4ySLl7UU__9aOs4PCRfQB_7wgCM2MmXMg;  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[27] /*|sequence*/)) goto whenobj4ySLl7UU__18MTh926lG6_7yBzKpdhNUt;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 11:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[59] /*|object*/)) goto whenobj4ySLl7UU__1dPD74MjKcz_4jtiBI8XE0Q;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 15:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[12] /*|raw_string*/)) goto whenobj4ySLl7UU__34JfZ8fuP0p_6pFQ2GljNtB;  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[25] /*|html_enc*/)) goto whenobj4ySLl7UU__6mGSw6UbZ62_2G1WgWKLI2x;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 18:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[33] /*|double_plain*/)) goto whenobj4ySLl7UU__63JazyO1dWC_8Y52ZEbX0AB;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 19:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[5] /*|octa*/)) goto whenobj4ySLl7UU__540K9iKhE21_8CfNTVKZFm2;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 20:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[38] /*|buffer*/)) goto whenobj4ySLl7UU__2ipfKe1iRAC_1L7DdWqaMNI;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 22:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[10] /*|double_float*/)) goto whenobj4ySLl7UU__83FAPFTeIAi_8I9ZDO0kn7L;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 23:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[60] /*|id*/)) goto whenobj4ySLl7UU__5NpWcVegQxj_1RHui16VqMR;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 30:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[2] /*|int*/)) goto whenobj4ySLl7UU__5mtc4t5tNdH_7cmF7sZJihN;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
  
  default: defobj_4ySLl7UU6Hw_7pgQRbU4gFX:;  
  
break; // end objswitch _4ySLl7UU6Hw_7pgQRbU4gFX default   
// objswitch _4ySLl7UU6Hw_7pgQRbU4gFX with 15 whens:   
   
whenobj4ySLl7UU__18MTh926lG6_7yBzKpdhNUt:; // when #0 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
break; // end when _18MTh926lG6_7yBzKpdhNUt #0 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__1dPD74MjKcz_4jtiBI8XE0Q:; // when #1 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
break; // end when _1dPD74MjKcz_4jtiBI8XE0Q #1 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__24qz4eJavv3_1P062j7RIWK:; // when #2 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _24qz4eJavv3_1P062j7RIWK #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[70] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[65] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
   
break; // end when _24qz4eJavv3_1P062j7RIWK #2 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__2ipfKe1iRAC_1L7DdWqaMNI:; // when #3 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _2ipfKe1iRAC_1L7DdWqaMNI #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[70] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[65] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _2ipfKe1iRAC_1L7DdWqaMNI #1 statement:   
 /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb = //assign _1S3rbyM1v7M_6FL7u4QeNxn    
/*val_to_object:*/objectcast_BM(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0)));   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _2ipfKe1iRAC_1L7DdWqaMNI #2 statement:   
{ // start out _3pnycj5xVLP_1YUbfKZZZaU to o_strbuf    
/*out html_enc:*/ objstrbufferencodedhtmlpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*objstrbufferbytespayl:*/objstrbufferbytespayl_BM( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), -1);   
} // end out _3pnycj5xVLP_1YUbfKZZZaU   
   
   
break; // end when _2ipfKe1iRAC_1L7DdWqaMNI #3 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__2LXkoXMNcGg_6FWal4v09Nf:; // when #4 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _2LXkoXMNcGg_6FWal4v09Nf #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[70] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[65] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _2LXkoXMNcGg_6FWal4v09Nf #1 statement:   
{ // start out _5iQWFM7g7Dk_2kc5q4nsdp1 to o_strbuf    
/*out hexa:*/ objstrbufferprintfpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "%llx", (long long)  /* val_to_int */ getint_BM(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0))) );   
} // end out _5iQWFM7g7Dk_2kc5q4nsdp1   
   
   
break; // end when _2LXkoXMNcGg_6FWal4v09Nf #4 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__34JfZ8fuP0p_6pFQ2GljNtB:; // when #5 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _34JfZ8fuP0p_6pFQ2GljNtB #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[70] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[65] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _34JfZ8fuP0p_6pFQ2GljNtB #1 statement:   
{ // start out _3jvq2V6NsBC_7LeoGHLIR1h to o_strbuf    
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0)))));   
} // end out _3jvq2V6NsBC_7LeoGHLIR1h   
   
   
break; // end when _34JfZ8fuP0p_6pFQ2GljNtB #5 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__540K9iKhE21_8CfNTVKZFm2:; // when #6 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _540K9iKhE21_8CfNTVKZFm2 #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[70] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[65] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
   
break; // end when _540K9iKhE21_8CfNTVKZFm2 #6 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__5mtc4t5tNdH_7cmF7sZJihN:; // when #7 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _5mtc4t5tNdH_7cmF7sZJihN #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[70] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[65] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
   
break; // end when _5mtc4t5tNdH_7cmF7sZJihN #7 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__5NpWcVegQxj_1RHui16VqMR:; // when #8 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _5NpWcVegQxj_1RHui16VqMR #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[70] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[65] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
   
break; // end when _5NpWcVegQxj_1RHui16VqMR #8 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__63JazyO1dWC_8Y52ZEbX0AB:; // when #9 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _63JazyO1dWC_8Y52ZEbX0AB #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[70] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[65] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _63JazyO1dWC_8Y52ZEbX0AB #1 statement:   
{ // start out _4hUnjsObgNm_7ZwBGfkBkis to o_strbuf    
/*out double_plain:*/ objstrbufferprintfpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "%g", /*val_to_double:*/getdouble_BM(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0))));   
} // end out _4hUnjsObgNm_7ZwBGfkBkis   
   
   
break; // end when _63JazyO1dWC_8Y52ZEbX0AB #9 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__6mGSw6UbZ62_2G1WgWKLI2x:; // when #10 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _6mGSw6UbZ62_2G1WgWKLI2x #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[70] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[65] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
   
break; // end when _6mGSw6UbZ62_2G1WgWKLI2x #10 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__7uiwyR9sfq3_1W9SQnuJLSz:; // when #11 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _7uiwyR9sfq3_1W9SQnuJLSz #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[70] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[65] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _7uiwyR9sfq3_1W9SQnuJLSz #1 statement:   
{ // start out _59mull0TRXy_9hXUrwSmKcD to o_strbuf    
/*out c_enc:*/ objstrbufferencodedcpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0)))), -1);   
} // end out _59mull0TRXy_9hXUrwSmKcD   
   
   
break; // end when _7uiwyR9sfq3_1W9SQnuJLSz #11 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__83FAPFTeIAi_8I9ZDO0kn7L:; // when #12 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _83FAPFTeIAi_8I9ZDO0kn7L #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[70] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[65] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _83FAPFTeIAi_8I9ZDO0kn7L #1 statement:   
{ // start out _1ULVfSCNpMe_1x4YuC8IcMP to o_strbuf    
/*out double_float:*/(void) objstrbufferoutdoublepayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*val_to_double:*/getdouble_BM(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0))));   
} // end out _1ULVfSCNpMe_1x4YuC8IcMP   
   
   
break; // end when _83FAPFTeIAi_8I9ZDO0kn7L #12 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__8SBMgF9WUmn_0k1vdQISETG:; // when #13 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _8SBMgF9WUmn_0k1vdQISETG #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[70] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[65] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _8SBMgF9WUmn_0k1vdQISETG #1 statement:   
{ // start out _53cWvliCIwT_8vm2uoHHKzw to o_strbuf    
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "<!--");    
/*out html_enc:*/ objstrbufferencodedhtmlpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0)))), -1);    
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "-->");   
} // end out _53cWvliCIwT_8vm2uoHHKzw   
   
   
break; // end when _8SBMgF9WUmn_0k1vdQISETG #13 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__9aOs4PCRfQB_7wgCM2MmXMg:; // when #14 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _9aOs4PCRfQB_7wgCM2MmXMg #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[70] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[65] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _9aOs4PCRfQB_7wgCM2MmXMg #1 statement:   
{ // start out _2VlJEMfhfGy_2Dqeddiju8Q to o_strbuf    
/*out local_time:*/objstrbufferencodelocaltimepayl_BM(( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), /*val_to_double:*/getdouble_BM(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0))));   
} // end out _2VlJEMfhfGy_2Dqeddiju8Q   
   
   
break; // end when _9aOs4PCRfQB_7wgCM2MmXMg #14 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
  
} } // end objswitch _4ySLl7UU6Hw_7pgQRbU4gFX  
  
} //endwhen _0TcBev05JBd_3KDoGzpRVI6  
else { /*cond else _23svN0ubUj6_7fLFEqkDSEu*/  
//failure _9ICwe1aOJtc_5TzmQ59QZrs  
PLACEDFAILURE_BM(__LINE__,  
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[71] /*!failure_type_error*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[73] /*|_9ICwe1aOJtc_5TzmQ59QZrs*/)),
                ((struct stackframe_stBM *) &_));
} /*cond else _23svN0ubUj6_7fLFEqkDSEu*/  
/*endcond _23svN0ubUj6_7fLFEqkDSEu*/ 
 
 
 
{ // run _1WjZ3R1QQhl_5JQ4Cqgmxcr 
/*debug end emit_xhtml v_html o_emitctx o_strbuf depth*/
DBGPRINTF_BM("end emit_xhtml €%.9s v_html=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_1WjZ3R1QQhl_5JQ4Cqgmxcr",
 OUTSTRVALUE_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),
 objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _1WjZ3R1QQhl_5JQ4Cqgmxcr 
 
 
/*return _2UF65p4uRmY_0YJFbtwQT6w:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu; 
 goto epilog_8IYFtn8osS2_4t1U3wyROLW; 
 
/* !endingblock _3DcbHfTP2te_8Zw8Uhy9eU6 */ 
goto endblock__3DcbHfTP2te_8Zw8Uhy9eU6; 
endblock__3DcbHfTP2te_8Zw8Uhy9eU6: ; 
} /*-block _3DcbHfTP2te_8Zw8Uhy9eU6 */

 epilog_8IYFtn8osS2_4t1U3wyROLW: __attribute__ ((unused)); // routine _8IYFtn8osS2_4t1U3wyROLW epilogue:
   // unlocking 1:
    if (locked_90WWBgxcOuU_9UT2wirExrs != NULL)
       objunlock_BM(locked_90WWBgxcOuU_9UT2wirExrs), locked_90WWBgxcOuU_9UT2wirExrs = NULL; // for o_html
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _8IYFtn8osS2_4t1U3wyROLW routine#10 emit_xhtml




value_tyBM crout_9hEreAemqXg_0uoN1Fr1ly4_BM //#11
 (struct stackframe_stBM* stkf, //
//!emit-tagged-id-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget] (o_helem o_emitctx o_strbuf v_depth)
  // 4 arguments
  const value_tyBM arg0,  // o_helem
  const value_tyBM arg1,  // o_emitctx
  const value_tyBM arg2,  // o_strbuf
  const value_tyBM arg3,  // v_depth
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _9hEreAemqXg_0uoN1Fr1ly4
  struct frame_9hEreAemqXg_0uoN1Fr1ly4_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 12 local values:
    value_tyBM v_0wWVh40nozk_7OSKII1HZ6t; // v_htmlclass
    objectval_tyBM* o_1E1n1xq22bH_7JEWM863KYo; // o_idtarget
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    value_tyBM v_6nmKmS2Auzh_04y9gBqgcDG; // v_htmltag
    value_tyBM v_6p6w3jZv5gy_58EzMDpOBQJ; // v_htmltagstr
    value_tyBM v_6wh43lYjXiZ_9MUWTOiTsOl; // v_idprefixstr
    objectval_tyBM* o_6Ef2ORO1Mni_0tpNoRQGmrW; // o_helem
    value_tyBM v_8VgHiZPlXwn_5i6tFD7vAVB; // v_idprefix
    objectval_tyBM* o_9nXRmTATjN4_5F9V7RvvgW0; // o_emitctx
    value_tyBM v_9AuPELEBCEG_3r2aCy2y3Pc; // v_htmlclassstr
    /// 1 local numbers:
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
   } _;
   memset (&_, 0, sizeof(struct frame_9hEreAemqXg_0uoN1Fr1ly4_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 12;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[72] /*|_9hEreAemqXg_0uoN1Fr1ly4*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 4 arguments:
   _.o_6Ef2ORO1Mni_0tpNoRQGmrW = objectcast_BM (arg0); // o_helem
   _.o_9nXRmTATjN4_5F9V7RvvgW0 = objectcast_BM (arg1); // o_emitctx
   _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg2); // o_strbuf
   _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
   // fetched 4 arguments.
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
 
 
 
{ // run _492Y24FWrWl_7SIfNCizDYt 
/*debug emit-tagged-id-xhtml-open start [v_htmltag v_htmlclass v_idprefix o_idtarget] o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emit-tagged-id-xhtml-open €%.9s start [v_htmltag=%s v_htmlclass=%s v_idprefix=%s o_idtarget=%s] o_helem=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_492Y24FWrWl_7SIfNCizDYt",
 OUTSTRVALUE_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG),
 OUTSTRVALUE_BM( /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t),
 OUTSTRVALUE_BM( /*v_idprefix:*/_.v_8VgHiZPlXwn_5i6tFD7vAVB),
 objectdbg_BM( /*o_idtarget:*/_.o_1E1n1xq22bH_7JEWM863KYo),
 objectdbg1_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg2_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg3_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _492Y24FWrWl_7SIfNCizDYt 
 
//+ #2/9 of block _0dR2udLAHI6_6XdsSwwp24Y :: 
 
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
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*val_to_object:*/objectcast_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[19] /*!html_tag*/))))));  
  
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
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*val_to_object:*/objectcast_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[45] /*!html_class*/))))));  
  
} //endwhen _3B2yJwjdy53_7VKdj7byIy6  
/*endcond _981Htnuqk2v_3f6kRQZBkNI*/ 
 
//+ #4/9 of block _0dR2udLAHI6_6XdsSwwp24Y :: 
 
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
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*object_cast:*/(value_tyBM)objectcast_BM( /*v_idprefix:*/_.v_8VgHiZPlXwn_5i6tFD7vAVB)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[66] /*!html_idprefix*/))))));  
  
} //endwhen _8L1ziPttLIT_5je6y8T504n  
/*endcond _9H0L8bKRxNs_6ZLNYQisXhr*/ 
 
//+ #6/9 of block _0dR2udLAHI6_6XdsSwwp24Y :: 
 
if /*cond _28OEq9p17rL_4fKBMly70SD*/  
/*when _9yrHHrw0SbZ_2da6hoDlbev:*/ 
 (/*is_null:*/(( /*o_idtarget:*/_.o_1E1n1xq22bH_7JEWM863KYo)==NULL)) { //body when _9yrHHrw0SbZ_2da6hoDlbev  
 /*o_idtarget:*/_.o_1E1n1xq22bH_7JEWM863KYo = //assign _1F7YZ8m4bvu_8fk0QAiXOx4   
 /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW;  
  
} //endwhen _9yrHHrw0SbZ_2da6hoDlbev  
/*endcond _28OEq9p17rL_4fKBMly70SD*/ 
 
 
if /*cond _2e8g1RnPvBb_8sEgpX6OvDV*/  
/*when _0ACVDQefshl_2vjIsEKkehH:*/ 
 (/*lazy and_then:*/ (intptr_t) (1 && ( /*v_idprefixstr:*/_.v_6wh43lYjXiZ_9MUWTOiTsOl) && ( /*o_idtarget:*/_.o_1E1n1xq22bH_7JEWM863KYo))) { //body when _0ACVDQefshl_2vjIsEKkehH  
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
} // end _9hEreAemqXg_0uoN1Fr1ly4 routine#11 _9hEreAemqXg_0uoN1Fr1ly4




// end of 12 generated routines


// the constant ids for 74 constants:
const char* const constid_9dQJgjsq7hs_2T2RqXLkU0A_BM[74+1] = {
 /*0:*/
 "_01h86SAfOfg_1q2oMegGRwW",//comment
 "_031bGeN8S0j_96cNAJfzYBE",//the_web_sessions
 "_0vgCFjXblkx_4zCMhMAWjVK",//int
 "_0FRLxSGQlZ0_0qrrUZlEeKp", //! emitxhtml_void_element (o_helem o_emitctx o_strbuf v_depth)
 "_0NH2lnQIrTb_7Kt3mvQUoVu", //! emit_xhtml_open°simple_html_element_object < o_helem (o_emitctx o_strbuf v_depth)
 /*5:*/
 "_1lCz1IP7t5R_8NTFVv0tnOi",//octa
 "_1JSykdLcLdl_8rWxtDBaPGN",//none
 "_1LdXMeDLWFL_0df1wmR8KD7", //! else fail-type-error  /emit-tagged-id-more-xhtml-open v_more o_helem o_emitctx o_strbuf depth
 "_1P3gVK5iIH8_62cj5fqHcIv", //! fail-miss o_helem o_websess o_webex //root-web-handler
 "_2ekmsdDpheM_8iSH1r9pS9e", //! fail non-object emitxhtml_element o_emitctx o_strbuf depth
 /*10:*/
 "_2qDaJRPDbEG_45AvdxtQXAM",//double_float
 "_2wGWzItVmrN_2CBwG6iHWFO",//newline
 "_2EDrV58DM9y_5GXjoUigj3r",//raw_string
 "_2P7OoZumXdx_5sUQ9SPbVwn",//utf8_enc
 "_2Uksq9GtGL5_6mG06OtMZF1", //! emit-src-from-webssesion-web_theme (o_helem o_websess o_strbuf depth)
 /*15:*/
 "_2W2LFnO44dr_973izSVn0hU",//local_time
 "_33eRuL6abjL_4uGwIWu51cd", //! else fail-miss emitxhtml_void_element v_resemit o_helem o_emitctx o_strbuf depth
 "_35gLacRFhq5_90zAPxiDIlh",//space
 "_3poYCpSsBfJ_8W7XNwG50hS", //! root-html-element
 "_3sJy6RT5X9u_1r0Sucfx4np",//html_tag
 /*20:*/
 "_3zzOJ9b7sUf_89ZOhP1HlUQ",//failure_full
 "_3EfvM2lT7h3_8fHXQsltxSG", //! fail-badclass emitxhtml_void_element 
 "_3ECxU06gRdk_8uZReHKm10m", //! fail-type_error emitxhtml_void_element v_resemit o_helem o_emitctx o_strbuf depth
 "_3Nl6LhfUZVb_1itsyWMBfYl",//apply
 "_3O7E8gjmVNG_42OFG3GueZX", //! fail-miss emitxhtml_element emit_xhtml o_html o_emitctx o_strbuf depth
 /*25:*/
 "_3QmxfIKpDVI_0C4Z01aFVxK",//html_enc
 "_3U4iMDjauSJ_350GrrqVStR", //! fail-miss emit-tagged-id-more-xhtml-open apply v_more o_helem o_emitctx o_strbuf depth
 "_47qleKxWAvS_0wCCWm6gtfa",//sequence
 "_4fUC5oegPuC_8hJQc9RBblV", //! fail-miss emit_xhtml html_active_object o_html o_emitctx o_strbuf depth
 "_4nCl6kh6zgK_8WQFqxe24i2", //! fail-type_error html_void_element o_helem o_emitctx o_strbuf depth / emitxhtml_void_element
 /*30:*/
 "_4uOuGQOR8oV_1fJJzlmYTHN",//default_web_theme
 "_4veY1dO90jF_7ThxWXJ0cIl", //! fail-miss emitxhtml_void_element emit_xhtml o_html o_emitctx o_strbuf depth
 "_4xwDKklt2v4_2lEbck0j4qs", //! html_spacing°simple*html*element < o_helem (o_emitctx v_depth)
 "_4BSjKuvOgrt_81MLC8NyKiS",//double_plain
 "_4HgYLk6htvP_4Ac2FCPfQ1C",//failure_bad_class
 /*35:*/
 "_4Hsn8KettH9_38n6JYQgUiC", //! fail-miss emit_xhtml v_clos o_html o_emitctx o_strbuf depth
 "_4HR54GlXs46_4rDg4Tb637x",//web_theme
 "_4I0ksnAasRT_1bREYU29xgL", //! emit-tagged-xhtml-open [v_htmltag v_htmlclass] (o_helem o_emitctx o_strbuf v_depth)
 "_4U5ZaR7UTwF_2LXJtkMOr6l",//buffer
 "_51oIiJoCulz_1NyarSIagfB", //! fail-miss emit_xhtml v_comp ii o_emitctx o_strbuf depth
 /*40:*/
 "_52XwytpOPVl_3ZjmQCtadbK",//failure_miss
 "_5ov2KpemmVg_0cMgvKrBTvJ",//html_void_element_object
 "_5rs4UfgeATT_3s7r48scObY", //! fail-bad-class html_element_object o_helem o_emitctx o_strbuf depth - emitxhtml_element
 "_5xGV4qXFkqJ_4imeaugtTzv", //! fail-miss emit_xhtml_open _helem o_emitctx depth
 "_5NH940lCHYJ_3nuRm3flnzc", //! emitxhtml_element (o_helem o_emitctx o_strbuf v_depth)
 /*45:*/
 "_5RD0QJ0X5kp_8vHHK68Qn2R",//html_class
 "_64Nwpjx4gnk_2y263bTCaB3",//emit_xhtml_open
 "_650BGD0ANMH_4gN3duymnz3", //! fail-miss emit_xhtml html_sequence_object v_comp ii o_html o_emitctx o_strbuf depth
 "_6xxbA8aTjZm_1sCJbVkU3Pm",//c_enc
 "_6yWldsq3Rmk_01WqTfwSIDV",//failure_non_object
 /*50:*/
 "_6L4mPBNfWGs_5PaIqa8vfVo", //! fail-miss  o_helem o_emitctx o_strbuf depth v_clos is nil /emit_xhtml_open°simple_html_element_object
 "_6RtF29C4pij_9r269Lc0d0W", //! emit_xhtml_open°simple_void_html_element_object < o_helem (o_emitctx o_strbuf v_depth)
 "_6TYtJU0rl2h_2z4md7DV06z", //! root-web-handler (v_restpath o_webex)
 "_77eAIoJ7YJJ_6zJy8HNioJC",//html_active_object
 "_79ub6Ngc5aa_42TtfuLTsPs", //! fail failure_miss emit_xhtml v_html o_emitctx depth // too deep
 /*55:*/
 "_7coI3Hezrvp_6CG1u3MlT83",//nlsp
 "_7gcGSxzwbaX_9tmqbEbjvo0",//html_sequence_object
 "_7FvfalQCaxj_24GCf5CtIWh",//html_element_object
 "_7PgBB7uIPOd_65NhmUjoLJf", //! fail-miss  o_helem o_emitctx o_strbuf depth v_clos is nil
 "_7T9OwSFlgov_0wVJaK1eZbn",//object
 /*60:*/
 "_7WjaQkqwdaZ_6PRtbDrJHnf",//id
 "_7YmEzAVe2hC_9iA0FVXAIqp",//hexa
 "_84d7WOdRsJh_4Ud9BryxYUr",//html_spacing
 "_85938GaqS1z_3mZSenKG7GG", //! emit-tagged-id-more-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget v_more] (o_helem o_emitctx o_strbuf v_depth)
 "_8c3wK0SptYZ_6EpzaOaJVJc", //! fail-type_error emit_xhtml_open o_helem o_emitctx o_strbuf depth /emitxhtml_element
 /*65:*/
 "_8i7m9bhUXQc_9cM9pXIykQh", //! fail-bad-rank emit_xhtml v_html o_emitctx o_strbuf depth
 "_8mOOvH4LOKB_5gaXDGw68tw",//html_idprefix
 "_8oKFbiPI4JW_7EPg4RP1e4Q", //! emit-raw-tag-xhtml-open [v_tagstr v_restagstr] (o_helem o_emitctx o_strbuf v_depth)
 "_8yowRQLZgzP_4vqWjo12OS4", //! fail failure_full emit_xhtml v_html o_emitctx depth
 "_8IYFtn8osS2_4t1U3wyROLW",//emit_xhtml
 /*70:*/
 "_8MFQuVGkedx_8OkpYlCQFip",//failure_bad_rank
 "_95hdJENHNkN_3QuKIJTCQQQ",//failure_type_error
 "_9hEreAemqXg_0uoN1Fr1ly4", //! emit-tagged-id-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget] (o_helem o_emitctx o_strbuf v_depth)
 "_9ICwe1aOJtc_5TzmQ59QZrs", //! else fail-typeerror emit_xhtml v_html o_emitctx o_strbuf depth
 NULL}; // end 74 constant ids



// the routine ids for 12 routines:
const char* const routid_9dQJgjsq7hs_2T2RqXLkU0A_BM[12+1] = {
  /*0:*/
  "_0FRLxSGQlZ0_0qrrUZlEeKp", //!emitxhtml_void_element (o_helem o_emitctx o_strbuf v_depth)
  "_0NH2lnQIrTb_7Kt3mvQUoVu", //!emit_xhtml_open°simple_html_element_object < o_helem (o_emitctx o_strbuf v_depth)
  "_2Uksq9GtGL5_6mG06OtMZF1", //!emit-src-from-webssesion-web_theme (o_helem o_websess o_strbuf depth)
  "_4xwDKklt2v4_2lEbck0j4qs", //!html_spacing°simple*html*element < o_helem (o_emitctx v_depth)
  "_4I0ksnAasRT_1bREYU29xgL", //!emit-tagged-xhtml-open [v_htmltag v_htmlclass] (o_helem o_emitctx o_strbuf v_depth)
  "_5NH940lCHYJ_3nuRm3flnzc", //!emitxhtml_element (o_helem o_emitctx o_strbuf v_depth)
  "_6RtF29C4pij_9r269Lc0d0W", //!emit_xhtml_open°simple_void_html_element_object < o_helem (o_emitctx o_strbuf v_depth)
  "_6TYtJU0rl2h_2z4md7DV06z", //!root-web-handler (v_restpath o_webex)
  /*8:*/
  "_85938GaqS1z_3mZSenKG7GG", //!emit-tagged-id-more-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget v_more] (o_helem o_emitctx o_strbuf v_depth)
  "_8oKFbiPI4JW_7EPg4RP1e4Q", //!emit-raw-tag-xhtml-open [v_tagstr v_restagstr] (o_helem o_emitctx o_strbuf v_depth)
  "_8IYFtn8osS2_4t1U3wyROLW",//emit_xhtml
  "_9hEreAemqXg_0uoN1Fr1ly4", //!emit-tagged-id-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget] (o_helem o_emitctx o_strbuf v_depth)

 NULL}; // end 12 routine ids



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



/************
 ** for Emacs:
 ** Local Variables: ;;
 ** compile-command: "make -k -j -C .. modules" ;;
 ** End: ;;
 ************/



// end of generated persistent module webxhtml_module in file modbm_9dQJgjsq7hs_2T2RqXLkU0A.c
