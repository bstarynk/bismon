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



// declare 17 routines

extern const char *const routid_9dQJgjsq7hs_2T2RqXLkU0A_BM[17+1];


// 35 failures

extern objrout_sigBM crout_0FRLxSGQlZ0_0qrrUZlEeKp_BM; //#0 !emitxhtml_void_element (o_helem o_emitctx o_strbuf v_depth)

extern objrout_sigBM crout_0NH2lnQIrTb_7Kt3mvQUoVu_BM; //#1 !emit_xhtml_open°simple_html_element_object < o_helem (o_emitctx o_strbuf v_depth)

extern objrout_sigBM crout_2Uksq9GtGL5_6mG06OtMZF1_BM; //#2 !emit-href-from-webssesion-web_theme (o_helem o_websess o_strbuf depth)

extern objrout_sigBM crout_3owspX08bkm_6vBzqS5jskf_BM; //#3 !emit-websession-contributor (o_emitctx o_strbuf depth)

extern objrout_sigBM crout_4xwDKklt2v4_2lEbck0j4qs_BM; //#4 !html_spacing°simple*html*element < o_helem (o_emitctx v_depth)

extern objrout_sigBM crout_4I0ksnAasRT_1bREYU29xgL_BM; //#5 !emit-tagged-xhtml-open [v_htmltag v_htmlclass] (o_helem o_emitctx o_strbuf v_depth)

extern objrout_sigBM crout_5NH940lCHYJ_3nuRm3flnzc_BM; //#6 !emitxhtml_element (o_helem o_emitctx o_strbuf v_depth)

extern objrout_sigBM crout_5T8fxyaeOFA_4UrB3BPbWdn_BM; //#7 !emit-websession-cookie (o_emitctx o_strbuf depth)

extern objrout_sigBM crout_6aWaLxHQBv4_9bcZim3ljEh_BM; //#8 !_forgotemail-webhandler (v_restpath o_webex)

extern objrout_sigBM crout_6RtF29C4pij_9r269Lc0d0W_BM; //#9 !emit_xhtml_open°simple_void_html_element_object < o_helem (o_emitctx o_strbuf v_depth)

extern objrout_sigBM crout_6STwOZTcBwM_6wz4Akuletb_BM; //#10 !forgotemailsender (o_contrib o_decayemail)

extern objrout_sigBM crout_6TYtJU0rl2h_2z4md7DV06z_BM; //#11 !root-web-handler (v_restpath o_webex)

extern objrout_sigBM crout_85938GaqS1z_3mZSenKG7GG_BM; //#12 !emit-tagged-id-more-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget v_more] (o_helem o_emitctx o_strbuf v_depth)

extern objrout_sigBM crout_8oKFbiPI4JW_7EPg4RP1e4Q_BM; //#13 !emit-raw-tag-xhtml-open [v_tagstr v_restagstr] (o_helem o_emitctx o_strbuf v_depth)

extern objrout_sigBM crout_8sdgc5Y7vPU_9Nvj5CtRqaQ_BM; //#14 !doapp-web-handler (v_restpath o_webex)

extern objrout_sigBM crout_8IYFtn8osS2_4t1U3wyROLW_BM; //#15 emit_xhtml

extern objrout_sigBM crout_9hEreAemqXg_0uoN1Fr1ly4_BM; //#16 !emit-tagged-id-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget] (o_helem o_emitctx o_strbuf v_depth)


// declare 98 constants
objectval_tyBM* constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[98+1];
const char* const constid_9dQJgjsq7hs_2T2RqXLkU0A_BM[98+1];


// define 17 routines


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
   const closure_tyBM* callclos_0FRLxSGQlZ0_0qrrUZlEeKp __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_0FRLxSGQlZ0_0qrrUZlEeKp  __attribute__((unused)) = 0;
   // routine _0FRLxSGQlZ0_0qrrUZlEeKp body:

startblock__5OqxK5JMgWp_4fzCg3OhXpz: __attribute__((unused));
{ /* +block _5OqxK5JMgWp_4fzCg3OhXpz */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _9MTOKrnDXFp_8VuIwpZq4ML  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
if /*cond _8M3YH8mCQmK_5hzOV7dlK6y*/  
/*when _70NLVhtnim4_46BJ6K9hmTk:*/ 
 (/*not:*/ (! (/*objectisinstance:*/ objectisinstance_BM(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[50] /*!html_void_element_object*/)))))) { //body when _70NLVhtnim4_46BJ6K9hmTk  
//failure _4nCl6kh6zgK_8WQFqxe24i2   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[93] /*!failure_type_error*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[50] /*!html_void_element_object*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[38] /*|_4nCl6kh6zgK_8WQFqxe24i2*/)),
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
 (/*not:*/ (! (/*objectisinstance:*/ objectisinstance_BM(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[50] /*!html_void_element_object*/)))))) { //body when _07EuRmnWGXF_5vxo4maeUAi  
//failure _3EfvM2lT7h3_8fHXQsltxSG   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[43] /*!failure_bad_class*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[3] /*!_0FRLxSGQlZ0_0qrrUZlEeKp*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[29] /*|_3EfvM2lT7h3_8fHXQsltxSG*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _07EuRmnWGXF_5vxo4maeUAi  
/*endcond _4Wn7pRPmEIx_0mreF5MM3NE*/ 
  
//+ #2/7 of lockobj _5sxQbo4ocBH_0O96nRSvJV9 ::  
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _5HcDhrmVMP2_2FuMdxilvQ9  
(send3_BM (( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), /*sel:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[56] /*!emit_xhtml_open*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),  ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)))); 
  
 
{ // run _2WwFxeI9iYR_4yuPUa9Qq27 
/*debug emitxhtml_void_element after emit_xhtml_open v_resemit o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emitxhtml_void_element after emit_xhtml_open €%.9s v_resemit=%s  o_helem=%s o_emitctx=%s\n... o_strbuf=%s/L%u (lin:%d, col:%d, last'%s') depth=%ld",
"_2WwFxeI9iYR_4yuPUa9Qq27",
 OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
objstrbufferlinecountpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
objstrbuffercolumnpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
objstrbuffercurrentlastlinepayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
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
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[93] /*!failure_type_error*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[3] /*!_0FRLxSGQlZ0_0qrrUZlEeKp*/)), 
 
( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[30] /*|_3ECxU06gRdk_8uZReHKm10m*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _44cEV8LtWCy_4fX3McNsNmP  
else { /*cond else _2jBO1fnZqEm_79Y6lkBP9by*/  
//failure _33eRuL6abjL_4uGwIWu51cd  
PLACEDFAILURE_BM(__LINE__,  
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[3] /*!_0FRLxSGQlZ0_0qrrUZlEeKp*/)), 
 
( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[21] /*|_33eRuL6abjL_4uGwIWu51cd*/)),
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
   const closure_tyBM* callclos_0NH2lnQIrTb_7Kt3mvQUoVu __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_0NH2lnQIrTb_7Kt3mvQUoVu  __attribute__((unused)) = 0;
   // routine _0NH2lnQIrTb_7Kt3mvQUoVu body:

startblock__5lJoYIhtFKG_8s9jow2GLIp: __attribute__((unused));
{ /* +block _5lJoYIhtFKG_8s9jow2GLIp */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _5cgc6snNLpL_6eLKUcOit2O  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px = //assign _7yAtINJUXoh_8n4bqYuxD2N  
/*closure_cast:*/(value_tyBM) closurecast_BM(/*objgetattr:*/objgetattr_BM(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[56] /*!emit_xhtml_open*/)))); 
 
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
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px)))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[63] /*|_6L4mPBNfWGs_5PaIqa8vfVo*/)),
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
//!emit-href-from-webssesion-web_theme (o_helem o_websess o_strbuf depth)
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
    /// 8 local values:
    value_tyBM v_167WczZjWtG_3FofhJxQWJi; // v_str
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
   _.stkfram_head.rlen = 8;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[19] /*|_2Uksq9GtGL5_6mG06OtMZF1*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // locking 1:
    objectval_tyBM* locked_0DZ90FBZM3E_4v3rw8AWUQU = NULL; // for o_theme
   // fetch 4 arguments:
   _.o_6Ef2ORO1Mni_0tpNoRQGmrW = objectcast_BM (arg0); // o_helem
   _.o_7UzdV9wjuq2_2PRgXcyAlMi = objectcast_BM (arg1); // o_websess
   _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg2); // o_strbuf
   _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
   // fetched 4 arguments.
   { // fetch 1 closed values in _2Uksq9GtGL5_6mG06OtMZF1:
   const closure_tyBM* callclos_2Uksq9GtGL5_6mG06OtMZF1 =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_2Uksq9GtGL5_6mG06OtMZF1 = closurewidth_BM ((const value_tyBM) callclos_2Uksq9GtGL5_6mG06OtMZF1);
   if (nbclosed_2Uksq9GtGL5_6mG06OtMZF1 > 0)
      _.v_167WczZjWtG_3FofhJxQWJi = callclos_2Uksq9GtGL5_6mG06OtMZF1->nodt_sons[0]; // v_str
   } // fetched 1 closed values in _2Uksq9GtGL5_6mG06OtMZF1.
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
 
//+ #2/5 of block _2Qv627ZT2Ot_42KOOsZ6KSp :: 
 
 /*o_theme:*/_.o_6cRlOymtk44_3dId2Eescrt = //assign _14ODgzLXGJi_4WPP5o1IPw8  
/*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_websess:*/_.o_7UzdV9wjuq2_2PRgXcyAlMi),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[45] /*!web_theme*/)))); 
 
 
if /*cond _9Z3pgLmUxDv_9ycILed4IbA*/  
/*when _1Skqf2rJDgC_5Apaxca8yuU:*/ 
 (/*is_null:*/(( /*o_theme:*/_.o_6cRlOymtk44_3dId2Eescrt)==NULL)) { //body when _1Skqf2rJDgC_5Apaxca8yuU  
//failure _1TLjn3qChsY_0RCEhuUWUyo   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[19] /*!_2Uksq9GtGL5_6mG06OtMZF1*/)), 
 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[45] /*!web_theme*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
// make_node arg #4 
( /*o_websess:*/_.o_7UzdV9wjuq2_2PRgXcyAlMi), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[10] /*|_1TLjn3qChsY_0RCEhuUWUyo*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _1Skqf2rJDgC_5Apaxca8yuU  
/*endcond _9Z3pgLmUxDv_9ycILed4IbA*/ 
 
 
 
{ // begin lockobj _0DZ90FBZM3E_4v3rw8AWUQU 
  objectval_tyBM* curlockedob_0DZ90FBZM3E_4v3rw8AWUQU = ( /*o_theme:*/_.o_6cRlOymtk44_3dId2Eescrt); 
if (objlock_BM (curlockedob_0DZ90FBZM3E_4v3rw8AWUQU)) {  
locked_0DZ90FBZM3E_4v3rw8AWUQU = curlockedob_0DZ90FBZM3E_4v3rw8AWUQU;  
  
 /*v_filepath:*/_.v_7KirpiCMhmI_0IfcivXUJfQ = //assign _1mpU1RoQ986_1ZazlJp6N5X  
/*objgetattr:*/objgetattr_BM(( /*o_theme:*/_.o_6cRlOymtk44_3dId2Eescrt),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[70] /*!file_path*/))); 
  
 
{ // run _5YxbrdpgPxz_9SQkKYoIxHz 
/*debug emit-src-from-webssession-web_theme o_theme v_filepath v_str o_helem o_strbuf o_websess depth*/
DBGPRINTF_BM("emit-src-from-webssession-web_theme €%.9s o_theme=%s v_filepath=%s v_str=%s o_helem=%s o_strbuf=%s/L%u o_websess=%s depth#%ld",
 "_5YxbrdpgPxz_9SQkKYoIxHz",
 objectdbg_BM( /*o_theme:*/_.o_6cRlOymtk44_3dId2Eescrt),
 OUTSTRVALUE_BM( /*v_filepath:*/_.v_7KirpiCMhmI_0IfcivXUJfQ),
 OUTSTRVALUE_BM( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi),
 objectdbg1_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objectdbg3_BM( /*o_websess:*/_.o_7UzdV9wjuq2_2PRgXcyAlMi),
(long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _5YxbrdpgPxz_9SQkKYoIxHz 
  
//+ #2/4 of lockobj _0DZ90FBZM3E_4v3rw8AWUQU ::  
{ // start out _8U4tim0A3AW_9Er3kDyv0dN to o_strbuf  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " href=\'");  
/*out html_enc:*/ objstrbufferencodedhtmlpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_filepath:*/_.v_7KirpiCMhmI_0IfcivXUJfQ)), -1);  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "\' ");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi))); 
} // end out _8U4tim0A3AW_9Er3kDyv0dN 
  
/*return _5DDFmWpJoFf_4scNstrHt5Z:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*o_theme:*/_.o_6cRlOymtk44_3dId2Eescrt; 
 goto epilog_2Uksq9GtGL5_6mG06OtMZF1; 
  
objunlock_BM (locked_0DZ90FBZM3E_4v3rw8AWUQU), locked_0DZ90FBZM3E_4v3rw8AWUQU = NULL; 
} } // end objlock _0DZ90FBZM3E_4v3rw8AWUQU 
/* !endingblock _2Qv627ZT2Ot_42KOOsZ6KSp */ 
goto endblock__2Qv627ZT2Ot_42KOOsZ6KSp; 
endblock__2Qv627ZT2Ot_42KOOsZ6KSp: ; 
} /*-block _2Qv627ZT2Ot_42KOOsZ6KSp */

 epilog_2Uksq9GtGL5_6mG06OtMZF1: __attribute__ ((unused)); // routine _2Uksq9GtGL5_6mG06OtMZF1 epilogue:
   // unlocking 1:
    if (locked_0DZ90FBZM3E_4v3rw8AWUQU != NULL)
       objunlock_BM(locked_0DZ90FBZM3E_4v3rw8AWUQU), locked_0DZ90FBZM3E_4v3rw8AWUQU = NULL; // for o_theme
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _2Uksq9GtGL5_6mG06OtMZF1 routine#2 _2Uksq9GtGL5_6mG06OtMZF1




value_tyBM crout_3owspX08bkm_6vBzqS5jskf_BM //#3
 (struct stackframe_stBM* stkf, //
//!emit-websession-contributor (o_emitctx o_strbuf depth)
  // 3 arguments
  const value_tyBM arg0,  // o_emitctx
  const value_tyBM arg1,  // o_strbuf
  const value_tyBM arg2,  // v_depth
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _3owspX08bkm_6vBzqS5jskf
  struct frame_3owspX08bkm_6vBzqS5jskf_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 7 local values:
    value_tyBM v_167WczZjWtG_3FofhJxQWJi; // v_str
    value_tyBM v_2BkOxf2KbS8_3bswrKbmgjy; // v_node
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    objectval_tyBM* o_4oqlg02xVwJ_918wypibNLb; // o_contrib
    objectval_tyBM* o_9nXRmTATjN4_5F9V7RvvgW0; // o_emitctx
    /// 1 local numbers:
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
   } _;
   memset (&_, 0, sizeof(struct frame_3owspX08bkm_6vBzqS5jskf_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 7;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[24] /*|_3owspX08bkm_6vBzqS5jskf*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 3 arguments:
   _.o_9nXRmTATjN4_5F9V7RvvgW0 = objectcast_BM (arg0); // o_emitctx
   _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg1); // o_strbuf
   _.v_4nJKFtMqlkA_1teQSqofNux = arg2; // v_depth
   // fetched 3 arguments.
   // no closed values in _3owspX08bkm_6vBzqS5jskf.
   const closure_tyBM* callclos_3owspX08bkm_6vBzqS5jskf __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_3owspX08bkm_6vBzqS5jskf  __attribute__((unused)) = 0;
   // routine _3owspX08bkm_6vBzqS5jskf body:

startblock__65J5FzsDIO3_5PX2gmEwGgr: __attribute__((unused));
{ /* +block _65J5FzsDIO3_5PX2gmEwGgr */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _7yntMI9NCfu_9gjVGtYh9WY  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 
{ // run _35Y4KBGZ15o_19Ibtlf08FM 
/*debug emit-websession-contributor start o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emit-websession-contributor start €%.9s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_35Y4KBGZ15o_19Ibtlf08FM",
 objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _35Y4KBGZ15o_19Ibtlf08FM 
 
//+ #2/6 of block _65J5FzsDIO3_5PX2gmEwGgr :: 
 
 /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb = //assign _6VPaKSmKKEW_5MEayuitmn4  
/*objwebsessioncontributorpayl:*/ objwebsessioncontributorpayl_BM(( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0)); 
 
 
 /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi = //assign _1LwbsfT5HfX_2FpPcYhdcmN  
/*objcontributornamepayl:*/((value_tyBM)(objcontributornamepayl_BM(( /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb)))); 
 
//+ #4/6 of block _65J5FzsDIO3_5PX2gmEwGgr :: 
 
 
{ // run _599xVemz14G_7IzBwDJnFP6 
/*debug emit-websession-contributor o_contrib v_str o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emit-websession-contributor €%.9s o_contrib=%s v_str=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_599xVemz14G_7IzBwDJnFP6",
 objectdbg_BM( /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb),
 OUTSTRVALUE_BM( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _599xVemz14G_7IzBwDJnFP6 
 
 
/*return _0T3SlzkUiNj_8ybdudQP1N2:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi; 
 goto epilog_3owspX08bkm_6vBzqS5jskf; 
 
/* !endingblock _65J5FzsDIO3_5PX2gmEwGgr */ 
goto endblock__65J5FzsDIO3_5PX2gmEwGgr; 
endblock__65J5FzsDIO3_5PX2gmEwGgr: ; 
} /*-block _65J5FzsDIO3_5PX2gmEwGgr */

 epilog_3owspX08bkm_6vBzqS5jskf: __attribute__ ((unused)); // routine _3owspX08bkm_6vBzqS5jskf epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _3owspX08bkm_6vBzqS5jskf routine#3 _3owspX08bkm_6vBzqS5jskf




value_tyBM crout_4xwDKklt2v4_2lEbck0j4qs_BM //#4
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
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[41] /*|_4xwDKklt2v4_2lEbck0j4qs*/;
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
   const closure_tyBM* callclos_4xwDKklt2v4_2lEbck0j4qs __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_4xwDKklt2v4_2lEbck0j4qs  __attribute__((unused)) = 0;
   // routine _4xwDKklt2v4_2lEbck0j4qs body:

startblock__8RQv0LoHOHD_9dRe3HS6ybs: __attribute__((unused));
{ /* +block _8RQv0LoHOHD_9dRe3HS6ybs */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _2iVQGQ5E98W_1PLw2pB5lLZ  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 /*v_spacing:*/_.v_2hXC8HRC8p6_0ma0OmYHXnB = //assign _6saK0DzUAG2_0RXYpmgVHXt  
/*objgetattr:*/objgetattr_BM(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[79] /*!html_spacing*/))); 
 
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
} // end _4xwDKklt2v4_2lEbck0j4qs routine#4 _4xwDKklt2v4_2lEbck0j4qs




value_tyBM crout_4I0ksnAasRT_1bREYU29xgL_BM //#5
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
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[46] /*|_4I0ksnAasRT_1bREYU29xgL*/;
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
   const unsigned nbclosed_4I0ksnAasRT_1bREYU29xgL = closurewidth_BM ((const value_tyBM) callclos_4I0ksnAasRT_1bREYU29xgL);
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
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*val_to_object:*/objectcast_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[26] /*!html_tag*/))))));  
  
} //endwhen _41uV2yIAp43_2Yu4V5fz3ui  
/*endcond _8hn8DdBoSyJ_1NJHIGIUSmC*/ 
 
 
if /*cond _981Htnuqk2v_3f6kRQZBkNI*/  
/*when _5usxraGoWWN_2A5IJEfVFat:*/ 
 (/*is_stringv:*/ isstring_BM( /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t)) { //body when _5usxraGoWWN_2A5IJEfVFat  
 /*v_htmlclassstr:*/_.v_9AuPELEBCEG_3r2aCy2y3Pc = //assign _7YpZd8yYOAD_5IjRXGsTBUs   
 /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t;  
  
} //endwhen _5usxraGoWWN_2A5IJEfVFat  
else if  
/*when _3B2yJwjdy53_7VKdj7byIy6:*/ 
 (/*is_objectv*/ isobject_BM( /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t)) { //body when _3B2yJwjdy53_7VKdj7byIy6  
 /*v_htmlclassstr:*/_.v_9AuPELEBCEG_3r2aCy2y3Pc = //assign _2a9vb10NrAs_706MrL2b0eq   
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*val_to_object:*/objectcast_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[54] /*!html_class*/))))));  
  
} //endwhen _3B2yJwjdy53_7VKdj7byIy6  
/*endcond _981Htnuqk2v_3f6kRQZBkNI*/ 
 
//+ #4/6 of block _2PCK7wl7e0d_6aQ9RlUCxeL :: 
 
{ // start out _6r8MxUGERZ5_62WMoVCfmcU to o_strbuf  
/*out set_indent:*/ objstrbuffersetindentpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f);  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "<");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_htmltagstr:*/_.v_6p6w3jZv5gy_58EzMDpOBQJ)));  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " class=\'");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_htmlclassstr:*/_.v_9AuPELEBCEG_3r2aCy2y3Pc)));  
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
} // end _4I0ksnAasRT_1bREYU29xgL routine#5 _4I0ksnAasRT_1bREYU29xgL




value_tyBM crout_5NH940lCHYJ_3nuRm3flnzc_BM //#6
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
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[53] /*|_5NH940lCHYJ_3nuRm3flnzc*/;
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
   const closure_tyBM* callclos_5NH940lCHYJ_3nuRm3flnzc __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_5NH940lCHYJ_3nuRm3flnzc  __attribute__((unused)) = 0;
   // routine _5NH940lCHYJ_3nuRm3flnzc body:

startblock__86w0oglm27k_4ULVduuJiC6: __attribute__((unused));
{ /* +block _86w0oglm27k_4ULVduuJiC6 */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _7j8aQZXvf5R_12tuW3bNSTQ  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 
{ // run _91ODIOIPXiS_7W461JEwQaX 
/*debug emitxhtml_element start o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emitxhtml_element start €%.9s o_helem=%s o_emitctx=%s\n... o_strbuf=%s/L%u (lin:%u,col:%u last'%s') depth#%ld",
 "_91ODIOIPXiS_7W461JEwQaX",
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlinecountpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbuffercolumnpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbuffercurrentlastlinepayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
; 
} // end run _91ODIOIPXiS_7W461JEwQaX 
 
//+ #2/4 of block _86w0oglm27k_4ULVduuJiC6 :: 
 
if /*cond _6VEZT6yN91n_1uTSi1gCAKy*/  
/*when _0li4T620kcV_4nC1fD477pu:*/ 
 (/*is_null:*/(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW)==NULL)) { //body when _0li4T620kcV_4nC1fD477pu  
//failure _2ekmsdDpheM_8iSH1r9pS9e   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode4_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[61] /*!failure_non_object*/)), 
 /*make_node 4 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[53] /*!_5NH940lCHYJ_3nuRm3flnzc*/)), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[12] /*|_2ekmsdDpheM_8iSH1r9pS9e*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _0li4T620kcV_4nC1fD477pu  
/*endcond _6VEZT6yN91n_1uTSi1gCAKy*/ 
 
 
 
{ // begin lockobj _36l0VwmZ11o_8vCwWpg2xIB 
  objectval_tyBM* curlockedob_36l0VwmZ11o_8vCwWpg2xIB = ( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW); 
if (objlock_BM (curlockedob_36l0VwmZ11o_8vCwWpg2xIB)) {  
locked_36l0VwmZ11o_8vCwWpg2xIB = curlockedob_36l0VwmZ11o_8vCwWpg2xIB;  
  
if /*cond _921fuoujPIF_4a0JqUqMOyG*/  
/*when _6HtsKDbq7Rx_3rZ8uRwGNj9:*/ 
 (/*not:*/ (! (/*objectisinstance:*/ objectisinstance_BM(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[73] /*!html_element_object*/)))))) { //body when _6HtsKDbq7Rx_3rZ8uRwGNj9  
//failure _5rs4UfgeATT_3s7r48scObY   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[43] /*!failure_bad_class*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[73] /*!html_element_object*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[51] /*|_5rs4UfgeATT_3s7r48scObY*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _6HtsKDbq7Rx_3rZ8uRwGNj9  
/*endcond _921fuoujPIF_4a0JqUqMOyG*/ 
  
 /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r = //assign _4gqzOn4YRA4_4DeoI7Me5mK  
/*val_to_object:*/objectcast_BM((send2_BM (( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), /*sel:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[79] /*!html_spacing*/)), ((struct stackframe_stBM*)&_),  
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
(send3_BM (( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), /*sel:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[56] /*!emit_xhtml_open*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),  ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)))); 
  
if /*cond _4Vd3Fe3lriq_1maa3fRM0K5*/  
/*when _2vrXQXG9ekP_2af2adhJ59X:*/ 
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _2vrXQXG9ekP_2af2adhJ59X  
//failure _5xGV4qXFkqJ_4imeaugtTzv   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[56] /*!emit_xhtml_open*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[52] /*|_5xGV4qXFkqJ_4imeaugtTzv*/)),
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
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[93] /*!failure_type_error*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[56] /*!emit_xhtml_open*/)), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[81] /*|_8c3wK0SptYZ_6EpzaOaJVJc*/)),
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
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[14] /*!newline*/)))) { //body when _78CDl258ber_2OZ6iKkZQDj  
{ // start out _1wybjEqYoCm_7w8ES3jgUxS to o_strbuf   
/*out more_indent:*/ objstrbuffermoreindentpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);   
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);  
} // end out _1wybjEqYoCm_7w8ES3jgUxS  
  
} //endwhen _78CDl258ber_2OZ6iKkZQDj  
else if  
/*when _8gbKuVOJ00d_0iXBwlmG6jd:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[71] /*!nlsp*/)))) { //body when _8gbKuVOJ00d_0iXBwlmG6jd  
{ // start out _6nl4fxXo5P9_4aikEu7hcUs to o_strbuf   
/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);  
} // end out _6nl4fxXo5P9_4aikEu7hcUs  
  
} //endwhen _8gbKuVOJ00d_0iXBwlmG6jd  
else if  
/*when _0aSvuu44cW5_744SUn0a59q:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[22] /*!space*/)))) { //body when _0aSvuu44cW5_744SUn0a59q  
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
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[14] /*!newline*/)))) { //body when _2VEPlTDtufU_1OJU65eKBpP   
{ // start out _8Nw9zJ5h0KD_02bjHvKfgQw to o_strbuf    
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);   
} // end out _8Nw9zJ5h0KD_02bjHvKfgQw   
   
} //endwhen _2VEPlTDtufU_1OJU65eKBpP   
else if   
/*when _9lQbBHyLisB_9RbsRinLVVi:*/  
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[71] /*!nlsp*/)))) { //body when _9lQbBHyLisB_9RbsRinLVVi   
{ // start out _0nMvmHfMjyF_5iZ1qqd9K8S to o_strbuf    
/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);   
} // end out _0nMvmHfMjyF_5iZ1qqd9K8S   
   
} //endwhen _9lQbBHyLisB_9RbsRinLVVi   
else if   
/*when _9BdaJn6vBWW_7n07rdHXudX:*/  
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[22] /*!space*/)))) { //body when _9BdaJn6vBWW_7n07rdHXudX   
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
(apply4_BM (( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), ((struct stackframe_stBM*)&_), 
 ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));  
  
// for-up _8QYxgALaJfV_49EojKGexX9 #5 :  
  
{ // run _5RzQzmfNZTu_5nQjP7QfLLD  
 
/*debug emitxhtml_element after emit_xhtml: v_resemit v_comp ii o_emitctx o_strbuf depth*/
 DBGPRINTF_BM("emitxhtml_element after emit_xhtml €%.9s: v_resemit=%s v_comp=%s ii#%ld o_emitctx=%s\n... o_strbuf=%s/L%u (lin:%d, col:%d, last'%s') depth#%ld",
 "_5RzQzmfNZTu_5nQjP7QfLLD",
 OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
 OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
 (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
 objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlinecountpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbuffercolumnpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbuffercurrentlastlinepayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;  
} // end run _5RzQzmfNZTu_5nQjP7QfLLD  
  
// for-up _8QYxgALaJfV_49EojKGexX9 #6 :  
if /*cond _6JhK96miaMx_3XLltRct5WU*/   
/*when _7yndBSvwm1J_9N5z0dJuXIM:*/  
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _7yndBSvwm1J_9N5z0dJuXIM   
//failure _51oIiJoCulz_1NyarSIagfB    
PLACEDFAILURE_BM(__LINE__,    
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[48] /*|_51oIiJoCulz_1NyarSIagfB*/)),
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
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[14] /*!newline*/)))) { //body when _7Tqp9FaGOi6_1zlNZrsr3P4  
{ // start out _5xthhfX2qlp_6rUZ8Mn7fG9 to o_strbuf   
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);  
} // end out _5xthhfX2qlp_6rUZ8Mn7fG9  
  
} //endwhen _7Tqp9FaGOi6_1zlNZrsr3P4  
else if  
/*when _26hfrrkoYbw_0EsJYF6nzjS:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[71] /*!nlsp*/)))) { //body when _26hfrrkoYbw_0EsJYF6nzjS  
{ // start out _8ALxuahzjVn_9JyrNMc4dcs to o_strbuf   
/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);  
} // end out _8ALxuahzjVn_9JyrNMc4dcs  
  
} //endwhen _26hfrrkoYbw_0EsJYF6nzjS  
else if  
/*when _4c7whFwVYld_6KcIS6aV9Yf:*/ 
 (/*equal_object:*/(( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r) == ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[22] /*!space*/)))) { //body when _4c7whFwVYld_6KcIS6aV9Yf  
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
} // end _5NH940lCHYJ_3nuRm3flnzc routine#6 _5NH940lCHYJ_3nuRm3flnzc




value_tyBM crout_5T8fxyaeOFA_4UrB3BPbWdn_BM //#7
 (struct stackframe_stBM* stkf, //
//!emit-websession-cookie (o_emitctx o_strbuf depth)
  // 3 arguments
  const value_tyBM arg0,  // o_emitctx
  const value_tyBM arg1,  // o_strbuf
  const value_tyBM arg2,  // v_depth
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _5T8fxyaeOFA_4UrB3BPbWdn
  struct frame_5T8fxyaeOFA_4UrB3BPbWdn_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 5 local values:
    value_tyBM v_167WczZjWtG_3FofhJxQWJi; // v_str
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    objectval_tyBM* o_9nXRmTATjN4_5F9V7RvvgW0; // o_emitctx
    /// 1 local numbers:
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
   } _;
   memset (&_, 0, sizeof(struct frame_5T8fxyaeOFA_4UrB3BPbWdn_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 5;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[55] /*|_5T8fxyaeOFA_4UrB3BPbWdn*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 3 arguments:
   _.o_9nXRmTATjN4_5F9V7RvvgW0 = objectcast_BM (arg0); // o_emitctx
   _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg1); // o_strbuf
   _.v_4nJKFtMqlkA_1teQSqofNux = arg2; // v_depth
   // fetched 3 arguments.
   // no closed values in _5T8fxyaeOFA_4UrB3BPbWdn.
   const closure_tyBM* callclos_5T8fxyaeOFA_4UrB3BPbWdn __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_5T8fxyaeOFA_4UrB3BPbWdn  __attribute__((unused)) = 0;
   // routine _5T8fxyaeOFA_4UrB3BPbWdn body:

startblock__78vz52rnuig_4hIRsFAb9sT: __attribute__((unused));
{ /* +block _78vz52rnuig_4hIRsFAb9sT */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _5pr2dQiyigB_3ISBWGcEjsk  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 
{ // run _8LwX544DBCD_0OWmXrqpf79 
/*start emit-websession-cookie o_emitctx o_strbuf depth*/
DBGPRINTF_BM("start emit-websession-cookie €%.9s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_8LwX544DBCD_0OWmXrqpf79",
 objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _8LwX544DBCD_0OWmXrqpf79 
 
//+ #2/6 of block _78vz52rnuig_4hIRsFAb9sT :: 
 
 /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi = //assign _0RoQHgRlPSs_9jNriJnIB7r  
/*objwebsessioncookiestringpayl:*/ objwebsessioncookiestringpayl_BM (( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), ( "BISMONCOOKIE=")) ; 
 
 
{ // start out _03cK6NGcBcK_1NUQGdki0UX to o_strbuf  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi))); 
} // end out _03cK6NGcBcK_1NUQGdki0UX 
 
//+ #4/6 of block _78vz52rnuig_4hIRsFAb9sT :: 
 
 
{ // run _9NRb7bhSErg_814ZzCFbREk 
/*emit-websession-cookie end v_str o_emitctx o_strbuf depth*/
DBGBACKTRACEPRINTF_BM("emit-websession-cookie end €%.9s v_str=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_9NRb7bhSErg_814ZzCFbREk",
 OUTSTRVALUE_BM( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi),
 objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _9NRb7bhSErg_814ZzCFbREk 
 
 
/*return _944c8LCmtWx_38bk5zIryO1:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[7] /*!none*/); 
 goto epilog_5T8fxyaeOFA_4UrB3BPbWdn; 
 
/* !endingblock _78vz52rnuig_4hIRsFAb9sT */ 
goto endblock__78vz52rnuig_4hIRsFAb9sT; 
endblock__78vz52rnuig_4hIRsFAb9sT: ; 
} /*-block _78vz52rnuig_4hIRsFAb9sT */

 epilog_5T8fxyaeOFA_4UrB3BPbWdn: __attribute__ ((unused)); // routine _5T8fxyaeOFA_4UrB3BPbWdn epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _5T8fxyaeOFA_4UrB3BPbWdn routine#7 _5T8fxyaeOFA_4UrB3BPbWdn




value_tyBM crout_6aWaLxHQBv4_9bcZim3ljEh_BM //#8
 (struct stackframe_stBM* stkf, //
//!_forgotemail-webhandler (v_restpath o_webex)
  // 2 arguments
  const value_tyBM arg0,  // v_restpath
  const value_tyBM arg1,  // o_webex
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _6aWaLxHQBv4_9bcZim3ljEh
  struct frame_6aWaLxHQBv4_9bcZim3ljEh_BMst {
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
   memset (&_, 0, sizeof(struct frame_6aWaLxHQBv4_9bcZim3ljEh_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 3;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[58] /*|_6aWaLxHQBv4_9bcZim3ljEh*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 2 arguments:
   _.v_6QhNRfe1Cte_0niVlWfAlmO = arg0; // v_restpath
   _.o_5JuT4FgNFFh_7McrTYeT3jx = objectcast_BM (arg1); // o_webex
   // fetched 2 arguments.
   // no closed values in _6aWaLxHQBv4_9bcZim3ljEh.
   const closure_tyBM* callclos_6aWaLxHQBv4_9bcZim3ljEh __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_6aWaLxHQBv4_9bcZim3ljEh  __attribute__((unused)) = 0;
   // routine _6aWaLxHQBv4_9bcZim3ljEh body:

startblock__5PRyZSIifoB_0wQbMIOsxDI: __attribute__((unused));
{ /* +block _5PRyZSIifoB_0wQbMIOsxDI */ 
 
{ // run _2ilkN4Z1AkN_5IqmVEk5M7P 
/*debug start _forgotemail-webhandler (v_restpath o_webex)*/
DBGPRINTF_BM("start _forgotemail-webhandler €%.9s v_restpath=%s o_webex=%s",
 "_2ilkN4Z1AkN_5IqmVEk5M7P", OUTSTRVALUE_BM( /*v_restpath:*/_.v_6QhNRfe1Cte_0niVlWfAlmO), objectdbg_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx));
; 
} // end run _2ilkN4Z1AkN_5IqmVEk5M7P 
 
/* !endingblock _5PRyZSIifoB_0wQbMIOsxDI */ 
goto endblock__5PRyZSIifoB_0wQbMIOsxDI; 
endblock__5PRyZSIifoB_0wQbMIOsxDI: ; 
} /*-block _5PRyZSIifoB_0wQbMIOsxDI */

 epilog_6aWaLxHQBv4_9bcZim3ljEh: __attribute__ ((unused)); // routine _6aWaLxHQBv4_9bcZim3ljEh epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _6aWaLxHQBv4_9bcZim3ljEh routine#8 _6aWaLxHQBv4_9bcZim3ljEh




value_tyBM crout_6RtF29C4pij_9r269Lc0d0W_BM //#9
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
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[65] /*|_6RtF29C4pij_9r269Lc0d0W*/;
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
   const closure_tyBM* callclos_6RtF29C4pij_9r269Lc0d0W __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_6RtF29C4pij_9r269Lc0d0W  __attribute__((unused)) = 0;
   // routine _6RtF29C4pij_9r269Lc0d0W body:

startblock__4zWEZFBIK5X_25cIifaeDB9: __attribute__((unused));
{ /* +block _4zWEZFBIK5X_25cIifaeDB9 */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _3TH81ZGZZo4_6ION2zs9zaQ  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px = //assign _7yAtINJUXoh_8n4bqYuxD2N  
/*closure_cast:*/(value_tyBM) closurecast_BM(/*objgetattr:*/objgetattr_BM(( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[56] /*!emit_xhtml_open*/)))); 
 
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
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px)))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[74] /*|_7PgBB7uIPOd_65NhmUjoLJf*/)),
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
} // end _6RtF29C4pij_9r269Lc0d0W routine#9 _6RtF29C4pij_9r269Lc0d0W




value_tyBM crout_6STwOZTcBwM_6wz4Akuletb_BM //#10
 (struct stackframe_stBM* stkf, //
//!forgotemailsender (o_contrib o_decayemail)
  // 2 arguments
  const value_tyBM arg0,  // o_contrib
  const value_tyBM arg1,  // o_decayemail
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _6STwOZTcBwM_6wz4Akuletb
  struct frame_6STwOZTcBwM_6wz4Akuletb_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 5 local values:
    value_tyBM v_167WczZjWtG_3FofhJxQWJi; // v_str
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    objectval_tyBM* o_4oqlg02xVwJ_918wypibNLb; // o_contrib
    objectval_tyBM* o_8Xesa6KOGm4_8rC68xDuR2P; // o_decayemail
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_6STwOZTcBwM_6wz4Akuletb_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 5;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[66] /*|_6STwOZTcBwM_6wz4Akuletb*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 2 arguments:
   _.o_4oqlg02xVwJ_918wypibNLb = objectcast_BM (arg0); // o_contrib
   _.o_8Xesa6KOGm4_8rC68xDuR2P = objectcast_BM (arg1); // o_decayemail
   // fetched 2 arguments.
   // no closed values in _6STwOZTcBwM_6wz4Akuletb.
   const closure_tyBM* callclos_6STwOZTcBwM_6wz4Akuletb __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_6STwOZTcBwM_6wz4Akuletb  __attribute__((unused)) = 0;
   // routine _6STwOZTcBwM_6wz4Akuletb body:

startblock__160pmVixE1q_0RLuDpytNXw: __attribute__((unused));
{ /* +block _160pmVixE1q_0RLuDpytNXw */ 
 
{ // run _8XhQ2Jjwe95_1SIty2jCPZQ 
/* debug forgotemailsender o_contrib o_decayemail start*/
DBGPRINTF_BM("forgotemailsender start €%.9s o_contrib=%s o_decayemail=%s",
 "_8XhQ2Jjwe95_1SIty2jCPZQ", objectdbg_BM( /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb), objectdbg1_BM( /*o_decayemail:*/_.o_8Xesa6KOGm4_8rC68xDuR2P));
; 
} // end run _8XhQ2Jjwe95_1SIty2jCPZQ 
 
 
 
{ // run _1lvpq8N4FRd_91GxvUgbsYc 
/*weakasserts forgotemailsender on o_contrib & o_decayemail*/
WEAKASSERT_BM(objhascontributorpayl_BM( /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb));
WEAKASSERT_BM(objhasdecayedvectorpayl_BM( /*o_decayemail:*/_.o_8Xesa6KOGm4_8rC68xDuR2P));
; 
} // end run _1lvpq8N4FRd_91GxvUgbsYc 
 
//+ #2/25 of block _160pmVixE1q_0RLuDpytNXw :: 
 
 
{ // run _78ltVdIuAm5_3a1ivM8UyQy 
/* debug forgotemailsender o_contrib o_decayemail 3 sons*/
DBGPRINTF_BM("forgotemailsender €%.9s o_contrib=%s o_decayemail=%s\n"
 ".. decayed sons #0: %s, #1: %s, #2: %s, len#%d",
 "_78ltVdIuAm5_3a1ivM8UyQy", objectdbg_BM( /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb), objectdbg1_BM( /*o_decayemail:*/_.o_8Xesa6KOGm4_8rC68xDuR2P),
 OUTSTRVALUE_BM (objdecayedvectornthpayl_BM ( /*o_decayemail:*/_.o_8Xesa6KOGm4_8rC68xDuR2P, 0)),
 OUTSTRVALUE_BM (objdecayedvectornthpayl_BM ( /*o_decayemail:*/_.o_8Xesa6KOGm4_8rC68xDuR2P, 1)),
 OUTSTRVALUE_BM (objdecayedvectornthpayl_BM ( /*o_decayemail:*/_.o_8Xesa6KOGm4_8rC68xDuR2P, 2)),
  objdecayedvectlenpayl_BM ( /*o_decayemail:*/_.o_8Xesa6KOGm4_8rC68xDuR2P)
);
; 
} // end run _78ltVdIuAm5_3a1ivM8UyQy 
 
 
 /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy = //assign _4hysUSjl0ph_065P1rITUyN  
/*makeobj:*/makeobj_BM(); 
 
//+ #4/25 of block _160pmVixE1q_0RLuDpytNXw :: 
 
 
{ // run _0Vl5o9Qpmkj_29jEKIkXF8X 
/*objputstrbufferpayl:*/objputstrbufferpayl_BM (( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),(/*chunk-constob _2zA2gehRNpj_87XNZoZ1mt8:*/((/*initial size of forgotemail strbuffer €_2zA2gehRN:*/32768)))); 
} // end run _0Vl5o9Qpmkj_29jEKIkXF8X 
 
 
 
{ // run _0dLuQ3ORKYd_6Ij9NW8eWz0 
/*debug forgotemailsender o_contrib o_decayemail o_strbuf*/
DBGPRINTF_BM("debug forgotemailsender €%.9s o_contrib=%s o_decayemail=%s o_strbuf=%s",
"_0dLuQ3ORKYd_6Ij9NW8eWz0", objectdbg_BM( /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb), objectdbg1_BM( /*o_decayemail:*/_.o_8Xesa6KOGm4_8rC68xDuR2P), objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy));
; 
} // end run _0dLuQ3ORKYd_6Ij9NW8eWz0 
 
//+ #6/25 of block _160pmVixE1q_0RLuDpytNXw :: 
 
{ // start out _7z4eboeZqpE_7SBD4WIWIMS to o_strbuf  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "<!DOCTYPE html>\n<html>\n<head>\n<title>forgotten password to Bismon</title>\n<meta charset=\"utf-8\">\n<style>\n  body { background-color: lightcyan; }\n  p.tinyinfo_cl { background-color: azure; font-size: 80% }\n  p.explain_cl { background-color: lavenderblush; font-size: 105%; }\n  span.smallspan_cl { background-color: ivory; font-size: 90% }\n  label.expl_cl { background-color: peachpuff; foreground-color: navy; font-size: 75%; font-family: Serif }\n  a.contact_cl { bachground-color: oldlace };\n </style>\n</head>\n"); 
} // end out _7z4eboeZqpE_7SBD4WIWIMS 
 
 
{ // start out _5c85Zj4Yce8_9k1Iswn4rve to o_strbuf  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "<body>\n<h1>forgotten Bismon password on "); 
} // end out _5c85Zj4Yce8_9k1Iswn4rve 
 
//+ #8/25 of block _160pmVixE1q_0RLuDpytNXw :: 
 
{ // start out _7vep5dXJezn_18BtFE9nTy6 to o_strbuf  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*chunk-constob bismon_host:*/(/*bismon_host:*/myhostname_BM)); 
} // end out _7vep5dXJezn_18BtFE9nTy6 
 
 
{ // start out _2D7txnLCuVk_6PrIlbRb7Cy to o_strbuf  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  " for "); 
} // end out _2D7txnLCuVk_6PrIlbRb7Cy 
 
//+ #10/25 of block _160pmVixE1q_0RLuDpytNXw :: 
 
{ // start out _0CrkCn91CRa_1eUa5y89hmW to o_strbuf  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)(/*objcontributornamepayl:*/((value_tyBM)(objcontributornamepayl_BM(( /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb))))))); 
} // end out _0CrkCn91CRa_1eUa5y89hmW 
 
 
{ // start out _9iYDGpvmr5S_9Eezx9H7ypj to o_strbuf  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "</h1>\n<p>Someone, probably you "); 
} // end out _9iYDGpvmr5S_9Eezx9H7ypj 
 
//+ #12/25 of block _160pmVixE1q_0RLuDpytNXw :: 
 
{ // start out _2EdAEc6bss9_2veL1O5WSzN to o_strbuf  
/*out html_enc:*/ objstrbufferencodedhtmlpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)(/*objcontributornamepayl:*/((value_tyBM)(objcontributornamepayl_BM(( /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb)))))), -1); 
} // end out _2EdAEc6bss9_2veL1O5WSzN 
 
 
{ // start out _9WW7zjFS88b_6HhF3rsglGw to o_strbuf  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  " at <tt>");  
/*out html_enc:*/ objstrbufferencodedhtmlpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)(/*objcontributoremailpayl:*/((value_tyBM)(objcontributoremailpayl_BM(( /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb)))))), -1);  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "</tt> (of oid <tt>");  
/*out id:*/ char idbuf_9WW7zjFS88b_6HhF3rsglGw_n3[32]={0};  
idtocbuf32_BM (objid_BM( /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb), idbuf_9WW7zjFS88b_6HhF3rsglGw_n3);  
objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, idbuf_9WW7zjFS88b_6HhF3rsglGw_n3);  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "</tt>),\n"); 
} // end out _9WW7zjFS88b_6HhF3rsglGw 
 
//+ #14/25 of block _160pmVixE1q_0RLuDpytNXw :: 
 
{ // start out _9hhu81QF0ns_0Dga4kpRj11 to o_strbuf  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "claim to have forgotten the login password for\nthe <a href=\'https://github.com/bstarynk/bismon\'>bismon</a> process\n");  
/*out int:*/ objstrbufferprintfpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "%lld", (long long) /*bismon_pid:*/((intptr_t)(getpid())));  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  " on <tt>");  
/*out html_enc:*/ objstrbufferencodedhtmlpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*chunk-constob bismon_host:*/(/*bismon_host:*/myhostname_BM), -1);  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "</tt>.\n"); 
} // end out _9hhu81QF0ns_0Dga4kpRj11 
 
 
 /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi = //assign _2HA5GVtfcW3_25FsJWG0E8P  
/*forgotpasswd_urlstring:*/(forgotpasswd_urlstring_BM(( /*o_decayemail:*/_.o_8Xesa6KOGm4_8rC68xDuR2P), CURFRAME_BM)); 
 
//+ #16/25 of block _160pmVixE1q_0RLuDpytNXw :: 
 
{ // start out _6RNwjqF0Ibs_3s4LjYNbTr8 to o_strbuf  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "If indeed you want to change your password, visit "); 
} // end out _6RNwjqF0Ibs_3s4LjYNbTr8 
 
 
 
{ // run _4Jls0A0Ns0m_5IrxiK9tzuG 
/*debug forgotemailsender URL o_contrib o_decayemail v_str o_strbuf*/
DBGPRINTF_BM("debug forgotemailsender €%.9s URL o_contrib=%s o_decayemail=%s v_str=%s o_strbuf=%s/L%u:\n%s\n",
 "_4Jls0A0Ns0m_5IrxiK9tzuG",
 objectdbg_BM( /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb),
 objectdbg1_BM( /*o_decayemail:*/_.o_8Xesa6KOGm4_8rC68xDuR2P),
 OUTSTRVALUE_BM( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferbytespayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy));
; 
} // end run _4Jls0A0Ns0m_5IrxiK9tzuG 
 
//+ #18/25 of block _160pmVixE1q_0RLuDpytNXw :: 
 
{ // start out _8kbSLWduQ6m_0najSnzSniJ to o_strbuf  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "<a href=\'");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)));  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "\'>");  
/*out html_enc:*/ objstrbufferencodedhtmlpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)), -1);  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "</a> within ten minutes.</p>\n"); 
} // end out _8kbSLWduQ6m_0najSnzSniJ 
 
 
{ // start out _3iSZp8KpRjI_4kJ9QaX0yPu to o_strbuf  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "<p class=\'tinyinfo_cl\'><i>this particular</i> <tt>Bismon</tt> server is managed by "); 
} // end out _3iSZp8KpRjI_4kJ9QaX0yPu 
 
//+ #20/25 of block _160pmVixE1q_0RLuDpytNXw :: 
 
{ // start out _2XnGApRnkDF_3ndj0kOtved to o_strbuf  
/*out html_enc:*/ objstrbufferencodedhtmlpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*chunk-constob contact_name:*/((/*contact_name:*/contact_name_BM)), -1);  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  ", who can be contacted by email to <a class=\'contact_cl\' href=\'mailto:");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*chunk-constob contact_email:*/((/*contact_email:*/contact_email_BM)));  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "\'>");  
/*out html_enc:*/ objstrbufferencodedhtmlpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*chunk-constob contact_email:*/((/*contact_email:*/contact_email_BM)), -1);  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "</a>, notably for help.</p>\n"); 
} // end out _2XnGApRnkDF_3ndj0kOtved 
 
 
{ // start out _78YkbFGzIxo_4wO60wDXjMw to o_strbuf  
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "<p class=\'tinyinfo_cl\'>Automatically generated message, on <i>");  
/*out local_time:*/objstrbufferencodelocaltimepayl_BM(( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), (/*now_double_time:*/clocktime_BM(CLOCK_REALTIME)));  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "</i>. <b>Do not reply!</b>.<p>\n");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "<p class=\'tinyinfo_cl\'>To customize this message, edit <tt>\xe2\x82\xac");  
/*out_half_id:*/ char idbuf_78YkbFGzIxo_4wO60wDXjMw_n5[32]={0};  
idtocbuf32_BM (objid_BM( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[5] /*!_160pmVixE1q_0RLuDpytNXw*/)), idbuf_78YkbFGzIxo_4wO60wDXjMw_n5);  
objstrbufferprintfpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "%.12s", idbuf_78YkbFGzIxo_4wO60wDXjMw_n5);  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "</tt>.</p>\n");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  "</body></html>\n");  
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy); 
} // end out _78YkbFGzIxo_4wO60wDXjMw 
 
//+ #22/25 of block _160pmVixE1q_0RLuDpytNXw :: 
 
 
{ // run _2tID18D0P5q_55DA1kEp9My 
/*debug final forgotemailsender o_contrib o_decayemail o_strbuf*/
DBGPRINTF_BM("debug final forgotemailsender €%.9s o_contrib=%s o_decayemail=%s"
     " o_strbuf=%s/L%u:\n%s\n",
 "_2tID18D0P5q_55DA1kEp9My",
 objectdbg_BM( /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb),
 objectdbg1_BM( /*o_decayemail:*/_.o_8Xesa6KOGm4_8rC68xDuR2P),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferbytespayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy));
; 
} // end run _2tID18D0P5q_55DA1kEp9My 
 
 
 
{ // run _3JxtnJWYQF3_9qoPcnRFhm7 
/*send forgotten password email o_strbuf to o_contrib*/
send_html_email_to_contributor_BM("Forgotten Bismon passwrd",
 objstrbufferbytespayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 NULL,
  /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb,
 CURFRAME_BM);
; 
} // end run _3JxtnJWYQF3_9qoPcnRFhm7 
 
 
/*return _4o0GJ79Vi2Z_4cxSZbzUBlp:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy; 
 goto epilog_6STwOZTcBwM_6wz4Akuletb; 
 
/* !endingblock _160pmVixE1q_0RLuDpytNXw */ 
goto endblock__160pmVixE1q_0RLuDpytNXw; 
endblock__160pmVixE1q_0RLuDpytNXw: ; 
} /*-block _160pmVixE1q_0RLuDpytNXw */

 epilog_6STwOZTcBwM_6wz4Akuletb: __attribute__ ((unused)); // routine _6STwOZTcBwM_6wz4Akuletb epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _6STwOZTcBwM_6wz4Akuletb routine#10 _6STwOZTcBwM_6wz4Akuletb




value_tyBM crout_6TYtJU0rl2h_2z4md7DV06z_BM //#11
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
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[67] /*|_6TYtJU0rl2h_2z4md7DV06z*/;
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
   const closure_tyBM* callclos_6TYtJU0rl2h_2z4md7DV06z __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_6TYtJU0rl2h_2z4md7DV06z  __attribute__((unused)) = 0;
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
 (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[25] /*!_3poYCpSsBfJ_8W7XNwG50hS*/); 
 
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
/*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_websess:*/_.o_7UzdV9wjuq2_2PRgXcyAlMi),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[45] /*!web_theme*/)))); 
  
if /*cond _2qNMv03BDYW_3VaCIUscZIp*/  
/*when _5w7aizMRVG7_4mvxmUUhYmY:*/ 
 (/*is_null:*/(( /*o_theme:*/_.o_6cRlOymtk44_3dId2Eescrt)==NULL)) { //body when _5w7aizMRVG7_4mvxmUUhYmY  
  
{ // begin lockobj _2GWBlUog6H9_8TLWmeV8dDa  
  objectval_tyBM* curlockedob_2GWBlUog6H9_8TLWmeV8dDa = ( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[1] /*!the_web_sessions*/));  
if (objlock_BM (curlockedob_2GWBlUog6H9_8TLWmeV8dDa)) {   
locked_2GWBlUog6H9_8TLWmeV8dDa = curlockedob_2GWBlUog6H9_8TLWmeV8dDa;   
   
 /*o_theme:*/_.o_6cRlOymtk44_3dId2Eescrt = //assign _2gT4zUoEUlR_6fkFhKFdWjg   
/*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[1] /*!the_web_sessions*/)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[39] /*!default_web_theme*/))));  
   
objunlock_BM (locked_2GWBlUog6H9_8TLWmeV8dDa), locked_2GWBlUog6H9_8TLWmeV8dDa = NULL;  
} } // end objlock _2GWBlUog6H9_8TLWmeV8dDa  
{ // start cexpansion _7aWYsOAJl3b_4zKUYhxHt3k - objputattr   
/*objputattr:*/objputattr_BM(( /*o_websess:*/_.o_7UzdV9wjuq2_2PRgXcyAlMi),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[45] /*!web_theme*/)),( /*o_theme:*/_.o_6cRlOymtk44_3dId2Eescrt));   
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
(apply4_BM (( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[53] /*!_5NH940lCHYJ_3nuRm3flnzc*/)), ((struct stackframe_stBM*)&_), 
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
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 3 sons:*/ 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
( /*o_websess:*/_.o_7UzdV9wjuq2_2PRgXcyAlMi), 
 
( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx)))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[9] /*|_1P3gVK5iIH8_62cj5fqHcIv*/)),
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
} // end _6TYtJU0rl2h_2z4md7DV06z routine#11 _6TYtJU0rl2h_2z4md7DV06z




value_tyBM crout_85938GaqS1z_3mZSenKG7GG_BM //#12
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
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[80] /*|_85938GaqS1z_3mZSenKG7GG*/;
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
   const unsigned nbclosed_85938GaqS1z_3mZSenKG7GG = closurewidth_BM ((const value_tyBM) callclos_85938GaqS1z_3mZSenKG7GG);
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
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*val_to_object:*/objectcast_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[26] /*!html_tag*/))))));  
  
} //endwhen _41uV2yIAp43_2Yu4V5fz3ui  
/*endcond _8hn8DdBoSyJ_1NJHIGIUSmC*/ 
 
 
if /*cond _981Htnuqk2v_3f6kRQZBkNI*/  
/*when _5usxraGoWWN_2A5IJEfVFat:*/ 
 (/*is_stringv:*/ isstring_BM( /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t)) { //body when _5usxraGoWWN_2A5IJEfVFat  
 /*v_htmlclassstr:*/_.v_9AuPELEBCEG_3r2aCy2y3Pc = //assign _7YpZd8yYOAD_5IjRXGsTBUs   
 /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t;  
  
} //endwhen _5usxraGoWWN_2A5IJEfVFat  
else if  
/*when _3B2yJwjdy53_7VKdj7byIy6:*/ 
 (/*is_objectv*/ isobject_BM( /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t)) { //body when _3B2yJwjdy53_7VKdj7byIy6  
 /*v_htmlclassstr:*/_.v_9AuPELEBCEG_3r2aCy2y3Pc = //assign _2a9vb10NrAs_706MrL2b0eq   
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*val_to_object:*/objectcast_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[54] /*!html_class*/))))));  
  
} //endwhen _3B2yJwjdy53_7VKdj7byIy6  
/*endcond _981Htnuqk2v_3f6kRQZBkNI*/ 
 
//+ #4/10 of block _0aMhdgQGit6_9yp9HB8SWvo :: 
 
if /*cond _3Wn4eMrYInK_5hxe6aYhYlR*/  
/*when _3IdCniEGOdw_5psqjJtiXYb:*/ 
 ( /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t) { //body when _3IdCniEGOdw_5psqjJtiXYb  
{ // start out _6r8MxUGERZ5_62WMoVCfmcU to o_strbuf   
/*out set_indent:*/ objstrbuffersetindentpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f);   
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "<");   
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_htmltagstr:*/_.v_6p6w3jZv5gy_58EzMDpOBQJ)));   
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " class=\'");   
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_htmlclassstr:*/_.v_9AuPELEBCEG_3r2aCy2y3Pc)));   
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "\' ");  
} // end out _6r8MxUGERZ5_62WMoVCfmcU  
  
} //endwhen _3IdCniEGOdw_5psqjJtiXYb  
else { /*cond else _3Wn4eMrYInK_5hxe6aYhYlR*/  
{ // start out _9BHMSndJQWA_3rDFuwoYjeg to o_strbuf  
/*out set_indent:*/ objstrbuffersetindentpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f);  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "<");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_htmltagstr:*/_.v_6p6w3jZv5gy_58EzMDpOBQJ))); 
} // end out _9BHMSndJQWA_3rDFuwoYjeg 
} /*cond else _3Wn4eMrYInK_5hxe6aYhYlR*/  
/*endcond _3Wn4eMrYInK_5hxe6aYhYlR*/ 
 
 
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
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*object_cast:*/(value_tyBM)objectcast_BM( /*v_idprefix:*/_.v_8VgHiZPlXwn_5i6tFD7vAVB)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[84] /*!html_idprefix*/))))));  
  
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
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[31] /*!apply*/)), 
 
( /*v_more:*/_.v_09jnZdQe0uA_088LqcQDlbX), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[34] /*|_3U4iMDjauSJ_350GrrqVStR*/)),
                ((struct stackframe_stBM *) &_));
   
} //endwhen _1QXX2qP3T02_6TInlg8LlSH   
/*endcond _9Jo9BPIOkFx_3aCHDhdBVYO*/  
  
} //endwhen _9d8dzvcDCgQ_4aUw3iYoDqF  
else { /*cond else _0HUpaLYud7t_4muHwMPSlJG*/  
//failure _1LdXMeDLWFL_0df1wmR8KD7  
PLACEDFAILURE_BM(__LINE__,  
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[93] /*!failure_type_error*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[80] /*!_85938GaqS1z_3mZSenKG7GG*/)), 
 
( /*v_more:*/_.v_09jnZdQe0uA_088LqcQDlbX), 
 
( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[8] /*|_1LdXMeDLWFL_0df1wmR8KD7*/)),
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
} // end _85938GaqS1z_3mZSenKG7GG routine#12 _85938GaqS1z_3mZSenKG7GG




value_tyBM crout_8oKFbiPI4JW_7EPg4RP1e4Q_BM //#13
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
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[85] /*|_8oKFbiPI4JW_7EPg4RP1e4Q*/;
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
   const unsigned nbclosed_8oKFbiPI4JW_7EPg4RP1e4Q = closurewidth_BM ((const value_tyBM) callclos_8oKFbiPI4JW_7EPg4RP1e4Q);
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
} // end _8oKFbiPI4JW_7EPg4RP1e4Q routine#13 _8oKFbiPI4JW_7EPg4RP1e4Q




value_tyBM crout_8sdgc5Y7vPU_9Nvj5CtRqaQ_BM //#14
 (struct stackframe_stBM* stkf, //
//!doapp-web-handler (v_restpath o_webex)
  // 2 arguments
  const value_tyBM arg0,  // v_restpath
  const value_tyBM arg1,  // o_webex
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _8sdgc5Y7vPU_9Nvj5CtRqaQ
  struct frame_8sdgc5Y7vPU_9Nvj5CtRqaQ_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 4 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_5JuT4FgNFFh_7McrTYeT3jx; // o_webex
    value_tyBM v_6QhNRfe1Cte_0niVlWfAlmO; // v_restpath
    objectval_tyBM* o_6Z4UU939WbU_8BK9xcKsXNb; // o_comp
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_8sdgc5Y7vPU_9Nvj5CtRqaQ_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 4;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[86] /*|_8sdgc5Y7vPU_9Nvj5CtRqaQ*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 2 arguments:
   _.v_6QhNRfe1Cte_0niVlWfAlmO = arg0; // v_restpath
   _.o_5JuT4FgNFFh_7McrTYeT3jx = objectcast_BM (arg1); // o_webex
   // fetched 2 arguments.
   // no closed values in _8sdgc5Y7vPU_9Nvj5CtRqaQ.
   const closure_tyBM* callclos_8sdgc5Y7vPU_9Nvj5CtRqaQ __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_8sdgc5Y7vPU_9Nvj5CtRqaQ  __attribute__((unused)) = 0;
   // routine _8sdgc5Y7vPU_9Nvj5CtRqaQ body:

startblock__2My9clwDFne_7Xnyb4KcTnv: __attribute__((unused));
{ /* +block _2My9clwDFne_7Xnyb4KcTnv */ 
 
{ // run _03K3qtb7kKu_1e5bIrYvndB 
/*doapp-web-handler start v_restpath o_webex*/
DBGPRINTF_BM("doapp-web-handler start €%.9s v_restpath=%s o_webex=%s",
 "_03K3qtb7kKu_1e5bIrYvndB",
 OUTSTRVALUE_BM( /*v_restpath:*/_.v_6QhNRfe1Cte_0niVlWfAlmO),
 objectdbg_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx));; 
} // end run _03K3qtb7kKu_1e5bIrYvndB 
 
/* !endingblock _2My9clwDFne_7Xnyb4KcTnv */ 
goto endblock__2My9clwDFne_7Xnyb4KcTnv; 
endblock__2My9clwDFne_7Xnyb4KcTnv: ; 
} /*-block _2My9clwDFne_7Xnyb4KcTnv */

 epilog_8sdgc5Y7vPU_9Nvj5CtRqaQ: __attribute__ ((unused)); // routine _8sdgc5Y7vPU_9Nvj5CtRqaQ epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _8sdgc5Y7vPU_9Nvj5CtRqaQ routine#14 _8sdgc5Y7vPU_9Nvj5CtRqaQ




value_tyBM crout_8IYFtn8osS2_4t1U3wyROLW_BM //#15+
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
    /// 16 local values:
    value_tyBM v_0qTBOEAT5pa_2fz1SKfHrMV; // v_resemit
    value_tyBM v_0DmuWueFbx9_5bzv8xgw3fu; // v_html
    value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
    objectval_tyBM* o_13K9OfeXRZR_84nyRTtoj81; // o_conn
    value_tyBM v_167WczZjWtG_3FofhJxQWJi; // v_str
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    value_tyBM v_4SOQrigJUMt_1u4UPeMXDKV; // v_emitopen
    value_tyBM v_5GhvzWWP1jl_41tgAIAAa2X; // v_resapp
    value_tyBM v_6KzoPNta5a2_7EsZceEn0Px; // v_clos
    objectval_tyBM* o_6Z4UU939WbU_8BK9xcKsXNb; // o_comp
    objectval_tyBM* o_7Ga6z7nroCG_3ikx3GHV41r; // o_spacing
    value_tyBM v_84WR8ns7LTz_1jFA1gd1apD; // v_emitnode
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
   _.stkfram_head.rlen = 16;
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*|emit_xhtml*/;
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
   const closure_tyBM* callclos_8IYFtn8osS2_4t1U3wyROLW __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_8IYFtn8osS2_4t1U3wyROLW  __attribute__((unused)) = 0;
   // routine _8IYFtn8osS2_4t1U3wyROLW body:

startblock__3DcbHfTP2te_8Zw8Uhy9eU6: __attribute__((unused));
{ /* +block _3DcbHfTP2te_8Zw8Uhy9eU6 */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _8uqITOuF3yu_9Uyyhkc1y9S  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 
{ // run _77pFBDGOZZQ_7iw2p047w0a 
/*debug start emit_xhtml v_html o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emit_xhtml start €%.9s v_html=%s o_emitctx=%s\n... o_strbuf=%s/L%u (lin:%u col:%u last'%s') depth#%ld",
"_77pFBDGOZZQ_7iw2p047w0a",
OUTSTRVALUE_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),
objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
objstrbufferlinecountpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
objstrbuffercolumnpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
objstrbuffercurrentlastlinepayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
(long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _77pFBDGOZZQ_7iw2p047w0a 
 
//+ #2/7 of block _3DcbHfTP2te_8Zw8Uhy9eU6 :: 
 
if /*cond _8hRp9kZ7uvu_4MzyhRQIoRd*/  
/*when _70ZSzCpjqWE_1AjclUpwXjD:*/ 
 (/*objstrbufferispercentfullpayl:*/(intptr_t)objstrbufferispercentfullpayl_BM(( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),(int)( 90))) { //body when _70ZSzCpjqWE_1AjclUpwXjD  
//failure _8yowRQLZgzP_4vqWjo12OS4   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[28] /*!failure_full*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[87] /*|_8yowRQLZgzP_4vqWjo12OS4*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _70ZSzCpjqWE_1AjclUpwXjD  
/*endcond _8hRp9kZ7uvu_4MzyhRQIoRd*/ 
 
 
if /*cond _24sbIpdvwNd_9c4S4cSYLYE*/  
/*when _0lnsrM6CMWA_4PCoTTYLR3e:*/ 
 ((/*greater_int:*/( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) > ( 100))) { //body when _0lnsrM6CMWA_4PCoTTYLR3e  
//failure _79ub6Ngc5aa_42TtfuLTsPs   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[69] /*|_79ub6Ngc5aa_42TtfuLTsPs*/)),
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
  if (objswexp_8lmPaSnQ7vo_33pxLUv2PDV ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[71] /*|nlsp*/)) goto whenobj8lmPaSnQ__5TnmFtNZk83_8aW0nHP7fZX;  
  goto defobj_8lmPaSnQ7vo_33pxLUv2PDV;  
 case 6:  
  if (objswexp_8lmPaSnQ7vo_33pxLUv2PDV ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[14] /*|newline*/)) goto whenobj8lmPaSnQ__9thTL0gOefq_2PbnKHKqRc2;  
  if (objswexp_8lmPaSnQ7vo_33pxLUv2PDV ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[22] /*|space*/)) goto whenobj8lmPaSnQ__74lJynQT1Jc_1sbt3E0bmFG;  
  goto defobj_8lmPaSnQ7vo_33pxLUv2PDV;  
 case 9:  
  if (objswexp_8lmPaSnQ7vo_33pxLUv2PDV ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[7] /*|none*/)) goto whenobj8lmPaSnQ__4MR4gMierKM_7OBmIrhHfd8;  
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
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[50] /*!html_void_element_object*/)))) { //body when _4rO8088H2lW_18rRyGDz6EI    
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
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[3] /*!_0FRLxSGQlZ0_0qrrUZlEeKp*/)), 
 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[40] /*|_4veY1dO90jF_7ThxWXJ0cIl*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _41ZNn4BXqRJ_994z6o2Ab3x     
/*endcond _9t0qbbenqEL_8XJtKd4Upqb*/    
/*return _22GngskXfoL_8r0RCbldM5B:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV;    
 goto epilog_8IYFtn8osS2_4t1U3wyROLW;    
    
} //endwhen _4rO8088H2lW_18rRyGDz6EI    
else if    
/*when _4ZDiBjqE148_9SJqgtSgqjk:*/   
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[73] /*!html_element_object*/)))) { //body when _4ZDiBjqE148_9SJqgtSgqjk    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _5eOG5u6rqzs_8IcECCzClD6     
(apply4_BM (( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[53] /*!_5NH940lCHYJ_3nuRm3flnzc*/)), ((struct stackframe_stBM*)&_), 
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
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[53] /*!_5NH940lCHYJ_3nuRm3flnzc*/)), 
 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[32] /*|_3O7E8gjmVNG_42OFG3GueZX*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _4NI7aLXhyp4_1w0Je6uVAy8     
/*endcond _11T1q3OMSxq_5u3kAcBoZUb*/    
/*return _1CS9B9875jz_7kDKAd9nve8:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV;    
 goto epilog_8IYFtn8osS2_4t1U3wyROLW;    
    
} //endwhen _4ZDiBjqE148_9SJqgtSgqjk    
else if    
/*when _2UYWFkodmko_0m3GeHsEJtj:*/   
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[68] /*!html_active_object*/)))) { //body when _2UYWFkodmko_0m3GeHsEJtj    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _8QXmQ57vzCG_4EwgpyHDJ14     
(send3_BM (( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), /*sel:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), ((struct stackframe_stBM*)&_), 
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
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[68] /*!html_active_object*/)), 
 
( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[37] /*|_4fUC5oegPuC_8hJQc9RBblV*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _311HixMi74e_1qIu77Ib0dD     
/*endcond _5xqEwW1k6Yw_1AuYU1a30cp*/    
/*return _45LV6X6jH5p_2COyhr6KJHJ:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV;    
 goto epilog_8IYFtn8osS2_4t1U3wyROLW;    
    
} //endwhen _2UYWFkodmko_0m3GeHsEJtj    
else if    
/*when _2qeuoOXokje_4oj6X9P4qUV:*/   
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[72] /*!html_sequence_object*/)))) { //body when _2qeuoOXokje_4oj6X9P4qUV    
 /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r = //assign _5WKZTYK0s3r_7HMBFv257DD     
/*as_object:*/objectcast_BM((send2_BM (( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), /*sel:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[79] /*!html_spacing*/)), ((struct stackframe_stBM*)&_),  
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
  if (objswexp_0shUy80I2UQ_5UJrLOmsND6 ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[71] /*|nlsp*/)) goto whenobj0shUy80I__1zz07iK23id_9u2MqG03Lmy;      
  goto defobj_0shUy80I2UQ_5UJrLOmsND6;      
 case 6:      
  if (objswexp_0shUy80I2UQ_5UJrLOmsND6 ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[14] /*|newline*/)) goto whenobj0shUy80I__1eRlKv9qmAR_0ikOOttDjM6;      
  if (objswexp_0shUy80I2UQ_5UJrLOmsND6 ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[22] /*|space*/)) goto whenobj0shUy80I__0fBdu6WjnyY_9E6TqmPfXBu;      
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
(apply4_BM (( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), ((struct stackframe_stBM*)&_), 
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
 (8U,/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 8 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[72] /*!html_sequence_object*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[57] /*|_650BGD0ANMH_4gN3duymnz3*/)),
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
/*objgetattr:*/objgetattr_BM(( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)));   
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
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_clos:*/_.v_6KzoPNta5a2_7EsZceEn0Px), 
 
( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[44] /*|_4Hsn8KettH9_38n6JYQgUiC*/)),
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
       DBGPRINTF_BM("emit_xhtml €%.9s node v_html=%s o_conn=%s o_emitctx=%s\n... o_strbuf=%s/L%u  (lin:%u col:%u last'%s') depth#%ld",
        "_85H5ux3Ioa4_0EafKQh3hja",
        OUTSTRVALUE_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),
        objectdbg_BM( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),  objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
        objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),   objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
        objstrbufferlinecountpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
        objstrbuffercolumnpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
        objstrbuffercurrentlastlinepayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
        (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
   ;  
} // end run _85H5ux3Ioa4_0EafKQh3hja  
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _9NylfF5tmgY_8hzqgAUkFOY   
/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe);  
  
{ // begin objswitch _4ySLl7UU6Hw_7pgQRbU4gFX  
//!objswitch! objswitch o_conn // emit_xhtml node .  
 objectval_tyBM* objswexp_4ySLl7UU6Hw_7pgQRbU4gFX = ( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81);  
 switch (objecthash_BM (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX) % 64) {  
 case 0:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[18] /*|utf8_enc*/)) goto whenobj4ySLl7UU__24qz4eJavv3_1P062j7RIWK;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 2:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[71] /*|nlsp*/)) goto whenobj4ySLl7UU__0SFfKhzb4pm_7RK67LGwrJz;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 5:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[59] /*|c_enc*/)) goto whenobj4ySLl7UU__7uiwyR9sfq3_1W9SQnuJLSz;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 6:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[14] /*|newline*/)) goto whenobj4ySLl7UU__2pklfVqX1ZE_8wPD1xPoPFV;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 9:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[35] /*|sequence*/)) goto whenobj4ySLl7UU__18MTh926lG6_7yBzKpdhNUt;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 11:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[75] /*|object*/)) goto whenobj4ySLl7UU__1dPD74MjKcz_4jtiBI8XE0Q;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 15:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[16] /*|raw_string*/)) goto whenobj4ySLl7UU__34JfZ8fuP0p_6pFQ2GljNtB;  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[33] /*|html_enc*/)) goto whenobj4ySLl7UU__6mGSw6UbZ62_2G1WgWKLI2x;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 18:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[42] /*|double_plain*/)) goto whenobj4ySLl7UU__63JazyO1dWC_8Y52ZEbX0AB;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 19:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[6] /*|octa*/)) goto whenobj4ySLl7UU__540K9iKhE21_8CfNTVKZFm2;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 22:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[22] /*|space*/)) goto whenobj4ySLl7UU__4xEPE1lbFOl_12yQbp8UM1B;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 30:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[2] /*|int*/)) goto whenobj4ySLl7UU__5mtc4t5tNdH_7cmF7sZJihN;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 34:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[77] /*|hexa*/)) goto whenobj4ySLl7UU__2LXkoXMNcGg_6FWal4v09Nf;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 37:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[0] /*|comment*/)) goto whenobj4ySLl7UU__8SBMgF9WUmn_0k1vdQISETG;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 41:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[20] /*|local_time*/)) goto whenobj4ySLl7UU__9aOs4PCRfQB_7wgCM2MmXMg;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 52:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[47] /*|buffer*/)) goto whenobj4ySLl7UU__2ipfKe1iRAC_1L7DdWqaMNI;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 54:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[13] /*|double_float*/)) goto whenobj4ySLl7UU__83FAPFTeIAi_8I9ZDO0kn7L;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
 case 55:  
  if (objswexp_4ySLl7UU6Hw_7pgQRbU4gFX ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[76] /*|id*/)) goto whenobj4ySLl7UU__5NpWcVegQxj_1RHui16VqMR;  
  goto defobj_4ySLl7UU6Hw_7pgQRbU4gFX;  
  
  default: defobj_4ySLl7UU6Hw_7pgQRbU4gFX:;  
  
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX default#0 statement:   
 /*v_emitnode:*/_.v_84WR8ns7LTz_1jFA1gd1apD = //assign _6NCIEVNBT9h_50bclPP5L9t    
/*objgetattr:*/objgetattr_BM(( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[27] /*!emit_xhtml_node*/)));   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX default#1 statement:   
 /*v_emitopen:*/_.v_4SOQrigJUMt_1u4UPeMXDKV = //assign _7Cx6dtbUrNN_6DmPjSF1PJV    
/*objgetattr:*/objgetattr_BM(( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[62] /*!emit_xhtml_connective_open*/)));   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX default#2 statement:   
   
{ // run _45vEcDvYxPl_5vrQyoffxPS   
/*debug emit_xhtml node else o_conn v_emitnode v_emitopen v_html o_emitctx o_strbuf depth*/
      DBGPRINTF_BM("emit_xhtml node else €%.9s o_conn=%s v_emitnode=%s v_emitopen=%s v_html=%s o_emitctx=%s\n... o_strbuf=%s/L%u  (lin:%u col:%u last'%s') depth#%ld",
      "_45vEcDvYxPl_5vrQyoffxPS",
      objectdbg_BM( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),
      OUTSTRVALUE_BM( /*v_emitnode:*/_.v_84WR8ns7LTz_1jFA1gd1apD),
      OUTSTRVALUE_BM( /*v_emitopen:*/_.v_4SOQrigJUMt_1u4UPeMXDKV),
      OUTSTRVALUE_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),
      objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
      objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
      objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
      objstrbufferlinecountpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
      objstrbuffercolumnpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
      objstrbuffercurrentlastlinepayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
      (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;   
} // end run _45vEcDvYxPl_5vrQyoffxPS   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX default#3 statement:   
if /*cond _71d8h6bNs5r_8msmxGXSF6A*/    
/*when _0ytfspi16XV_8rdRqvotJPH:*/   
 (/*lazy and_then:*/ (intptr_t) (1 && ( /*v_emitnode:*/_.v_84WR8ns7LTz_1jFA1gd1apD) && ( /*v_emitopen:*/_.v_4SOQrigJUMt_1u4UPeMXDKV))) { //body when _0ytfspi16XV_8rdRqvotJPH    
//failure _3602vaaly3m_2GoqnKUc8u3     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[78] /*!failure_both*/)), 
 /*make_node 5 sons:*/ 
( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[23] /*|_3602vaaly3m_2GoqnKUc8u3*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _0ytfspi16XV_8rdRqvotJPH    
else if    
/*when _50QjUSjFk24_3XW3mz4nn8n:*/   
 (/*isclosure:*/isclosure_BM(( /*v_emitnode:*/_.v_84WR8ns7LTz_1jFA1gd1apD))) { //body when _50QjUSjFk24_3XW3mz4nn8n    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _1MMYyXzkv7K_1Or9aigIsmP     
(apply5_BM (( /*v_emitnode:*/_.v_84WR8ns7LTz_1jFA1gd1apD), ((struct stackframe_stBM*)&_), 
 ( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1)))), 
 ( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu)));    
    
{ // run _7lCqfMMW0XT_0WuzCxjUFLQ    
/*debug emit_xhtml v_resemit o_conn v_emitnode o_emitctx o_strbuf depth v_html*/
          DBGPRINTF_BM("emit_xhtml node else €%.9s v_resemit=%s o_conn=%s v_emitnode=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld v_html=%s",
          "_7lCqfMMW0XT_0WuzCxjUFLQ",
          OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
          objectdbg_BM( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),
          OUTSTRVALUE_BM( /*v_emitnode:*/_.v_84WR8ns7LTz_1jFA1gd1apD),
          objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
          objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
          objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
          (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
          OUTSTRVALUE_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu));;    
} // end run _7lCqfMMW0XT_0WuzCxjUFLQ    
if /*cond _8559s6hLutN_06N4cO2W0bL*/     
/*when _3E872Y092sm_01rO9wAGePj:*/    
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _3E872Y092sm_01rO9wAGePj     
//failure _6yc00QTj7DW_2epaxvQ7ttJ      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[27] /*!emit_xhtml_node*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[60] /*|_6yc00QTj7DW_2epaxvQ7ttJ*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _3E872Y092sm_01rO9wAGePj     
/*endcond _8559s6hLutN_06N4cO2W0bL*/    
/*return _2mM6y3HOk4z_9otdj1AOuQR:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV;    
 goto epilog_8IYFtn8osS2_4t1U3wyROLW;    
    
} //endwhen _50QjUSjFk24_3XW3mz4nn8n    
else if    
/*when _38ZpexnnIRL_3ouPoNUMAlj:*/   
 (/*isclosure:*/isclosure_BM(( /*v_emitopen:*/_.v_4SOQrigJUMt_1u4UPeMXDKV))) { //body when _38ZpexnnIRL_3ouPoNUMAlj    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _4a5C2WSlU8F_17UrTFdQSwV     
(apply5_BM (( /*v_emitopen:*/_.v_4SOQrigJUMt_1u4UPeMXDKV), ((struct stackframe_stBM*)&_), 
 ( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1)))), 
 ( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu)));    
    
{ // run _3BX79RQaOFi_3fmZ7MuycAN    
/*debug emit_xhtml v_resemit o_conn v_emitopen o_emitctx o_strbuf depth v_html*/
 DBGPRINTF_BM("emit_xhtml node else €%.9s v_resemit=%s o_conn=%s v_emitnode=%s o_emitctx=%s\n... o_strbuf=%s/L%u (lin:%u, col:%u last'%s') depth#%ld v_html=%s",
"_3BX79RQaOFi_3fmZ7MuycAN",
 OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
 objectdbg_BM( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),
 OUTSTRVALUE_BM( /*v_emitnode:*/_.v_84WR8ns7LTz_1jFA1gd1apD),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlinecountpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbuffercolumnpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbuffercurrentlastlinepayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
 OUTSTRVALUE_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu));;    
} // end run _3BX79RQaOFi_3fmZ7MuycAN    
 /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi = //assign _0hDwqcnDdxB_5ugLoH0Usns     
/*null_value:*/ ((value_tyBM)NULL);    
if /*cond _6hOiHOAsYP8_9hIzimk3sQo*/     
/*when _2fIJPjeyn2e_0cwTkOx3Bu3:*/    
 (/*is_stringv:*/ isstring_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)) { //body when _2fIJPjeyn2e_0cwTkOx3Bu3     
 /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi = //assign _0IZnMaB0JDb_3BYdPl5iiA4      
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV;     
     
} //endwhen _2fIJPjeyn2e_0cwTkOx3Bu3     
else { /*cond else _6hOiHOAsYP8_9hIzimk3sQo*/     
//failure _8XlKCYnNu3S_6KsoDHN7IEF     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[93] /*!failure_type_error*/)), 
 /*make_node 8 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[62] /*!emit_xhtml_connective_open*/)), 
 
( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV), 
 
( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81), 
 
// make_node arg #4 
( /*v_emitopen:*/_.v_4SOQrigJUMt_1u4UPeMXDKV), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu)))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[91] /*|_8XlKCYnNu3S_6KsoDHN7IEF*/)),
                ((struct stackframe_stBM *) &_));
} /*cond else _6hOiHOAsYP8_9hIzimk3sQo*/     
/*endcond _6hOiHOAsYP8_9hIzimk3sQo*/    
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _1odyel0kOnS_0GiCIcy69cM     
/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu);    
 /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r = //assign _4eT7RpBLOP7_5mrd1w4rw3D     
/*as_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[79] /*!html_spacing*/))));    
{ //for-up _9cLjQkZ0xdW_9LXq9TMz1lA     
intptr_t cnt_9cLjQkZ0xdW_9LXq9TMz1lA =  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k;     
for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;     
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_9cLjQkZ0xdW_9LXq9TMz1lA;     
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++) {     
// for-up _9cLjQkZ0xdW_9LXq9TMz1lA #0 :     
if /*cond _7mVfh7XGCVu_548mwgiZwtm*/      
/*when _2a0paNaNLEH_8A6QQP636Et:*/     
 (/*lazy and_then:*/ (intptr_t) (1 && ((/*greater_int:*/( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) > ( 0))) && ( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r))) { //body when _2a0paNaNLEH_8A6QQP636Et      
      
{ // begin objswitch _6HlKcVMHYaN_32tjsarkAo8      
//!objswitch! objswitch o_spacing  // emit_xhtml emit_xhtml_connective_open .      
 objectval_tyBM* objswexp_6HlKcVMHYaN_32tjsarkAo8 = ( /*o_spacing:*/_.o_7Ga6z7nroCG_3ikx3GHV41r);      
 switch (objecthash_BM (objswexp_6HlKcVMHYaN_32tjsarkAo8) % 16) {      
 case 2:      
  if (objswexp_6HlKcVMHYaN_32tjsarkAo8 ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[71] /*|nlsp*/)) goto whenobj6HlKcVMH__3GOXd38vL3X_9BRI13rLUHp;      
  goto defobj_6HlKcVMHYaN_32tjsarkAo8;      
 case 6:      
  if (objswexp_6HlKcVMHYaN_32tjsarkAo8 ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[14] /*|newline*/)) goto whenobj6HlKcVMH__0KoNfqIMUAF_4JFd39un1ka;      
  if (objswexp_6HlKcVMHYaN_32tjsarkAo8 ==  (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[22] /*|space*/)) goto whenobj6HlKcVMH__5SMSbWfD51l_13IaJsX66LB;      
  goto defobj_6HlKcVMHYaN_32tjsarkAo8;      
      
  default: defobj_6HlKcVMHYaN_32tjsarkAo8:;      
      
break; // end objswitch _6HlKcVMHYaN_32tjsarkAo8 default       
// objswitch _6HlKcVMHYaN_32tjsarkAo8 with 3 whens:       
       
whenobj6HlKcVMH__0KoNfqIMUAF_4JFd39un1ka:; // when #0 of objswitch _6HlKcVMHYaN_32tjsarkAo8       
 // objswitch _6HlKcVMHYaN_32tjsarkAo8 when _0KoNfqIMUAF_4JFd39un1ka #0 statement:       
{ // start out _4cWQQ58pHWh_97m4buiwg3R to o_strbuf        
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);       
} // end out _4cWQQ58pHWh_97m4buiwg3R       
       
       
break; // end when _0KoNfqIMUAF_4JFd39un1ka #0 of objswitch _6HlKcVMHYaN_32tjsarkAo8       
       
whenobj6HlKcVMH__3GOXd38vL3X_9BRI13rLUHp:; // when #1 of objswitch _6HlKcVMHYaN_32tjsarkAo8       
 // objswitch _6HlKcVMHYaN_32tjsarkAo8 when _3GOXd38vL3X_9BRI13rLUHp #0 statement:       
{ // start out _0P1rF9F00KK_1xlFZeUMFBF to o_strbuf        
/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);       
} // end out _0P1rF9F00KK_1xlFZeUMFBF       
       
       
break; // end when _3GOXd38vL3X_9BRI13rLUHp #1 of objswitch _6HlKcVMHYaN_32tjsarkAo8       
       
whenobj6HlKcVMH__5SMSbWfD51l_13IaJsX66LB:; // when #2 of objswitch _6HlKcVMHYaN_32tjsarkAo8       
 // objswitch _6HlKcVMHYaN_32tjsarkAo8 when _5SMSbWfD51l_13IaJsX66LB #0 statement:       
{ // start out _31ytSsCz6ud_2IZgv00PGJe to o_strbuf        
/*out space:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " ");       
} // end out _31ytSsCz6ud_2IZgv00PGJe       
       
       
break; // end when _5SMSbWfD51l_13IaJsX66LB #2 of objswitch _6HlKcVMHYaN_32tjsarkAo8       
      
} } // end objswitch _6HlKcVMHYaN_32tjsarkAo8      
      
} //endwhen _2a0paNaNLEH_8A6QQP636Et      
/*endcond _7mVfh7XGCVu_548mwgiZwtm*/     
     
// for-up _9cLjQkZ0xdW_9LXq9TMz1lA #1 :     
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _9pxPpTXqjkG_0NXDGSBu6pn      
/*nodenthson:*/nodenthson_BM(( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));     
     
// for-up _9cLjQkZ0xdW_9LXq9TMz1lA #2 :     
     
{ // run _3nyxNy3ODMm_1oqSKyPjp8V     
/*debug emit_xhtml for loop emit_xhtml_connective_open v_resemit v_comp ii o_html o_emitctx o_strbuf depth*/
   DBGPRINTF_BM("emit_xhtml for loop emit_xhtml_connective_open €%.9s v_resemit=%s v_comp=%s ii#%ld o_html=%s o_emitctx=%s\n... o_strbuf=%s/L%u  (lin:%u col:%u last'%s')  depth#%ld",
   "_3nyxNy3ODMm_1oqSKyPjp8V",
   OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
   OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
   (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
   objectdbg_BM( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),
   objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
   objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   objstrbufferlinecountpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   objstrbuffercolumnpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   objstrbuffercurrentlastlinepayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
;     
} // end run _3nyxNy3ODMm_1oqSKyPjp8V     
     
// for-up _9cLjQkZ0xdW_9LXq9TMz1lA #3 :     
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _5Y4wc2UOE5M_1pkyjxrfhZo      
(apply4_BM (( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), ((struct stackframe_stBM*)&_), 
 ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));     
     
// for-up _9cLjQkZ0xdW_9LXq9TMz1lA #4 :     
     
{ // run _1ZMpPpsEkZu_8BzpGTXUglc     
/*debug emit_xhtml for loop emit_xhtml_connective_open v_resemit v_comp ii o_html o_emitctx o_strbuf depth*/
   DBGPRINTF_BM("emit_xhtml for loop emit_xhtml_connective_open €%.9s v_resemit=%s v_comp=%s ii#%ld o_html=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
   "_1ZMpPpsEkZu_8BzpGTXUglc",
   OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
   OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
   (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
   objectdbg_BM( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),
   objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
   objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
   ;     
} // end run _1ZMpPpsEkZu_8BzpGTXUglc     
     
// for-up _9cLjQkZ0xdW_9LXq9TMz1lA #5 :     
if /*cond _2ce87qAzpTJ_2zcC8Qa4hub*/      
/*when _2uiNVrfPulM_6Y4VluZ6D3s:*/     
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _2uiNVrfPulM_6Y4VluZ6D3s      
//failure _4dpEDjJFo47_1WU3n2D3esH       
PLACEDFAILURE_BM(__LINE__,       
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[62] /*!emit_xhtml_connective_open*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[36] /*|_4dpEDjJFo47_1WU3n2D3esH*/)),
                ((struct stackframe_stBM *) &_));
      
} //endwhen _2uiNVrfPulM_6Y4VluZ6D3s      
/*endcond _2ce87qAzpTJ_2zcC8Qa4hub*/     
    
}} // end for-up _9cLjQkZ0xdW_9LXq9TMz1lA    
{ // start out _6qT8Bs0VFWp_9rAYiEehf8z to o_strbuf     
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "</");     
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)));     
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, ">");    
} // end out _6qT8Bs0VFWp_9rAYiEehf8z    
    
} //endwhen _38ZpexnnIRL_3ouPoNUMAlj    
/*endcond _71d8h6bNs5r_8msmxGXSF6A*/   
   
break; // end objswitch _4ySLl7UU6Hw_7pgQRbU4gFX default   
// objswitch _4ySLl7UU6Hw_7pgQRbU4gFX with 18 whens:   
   
whenobj4ySLl7UU__0SFfKhzb4pm_7RK67LGwrJz:; // when #0 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _0SFfKhzb4pm_7RK67LGwrJz #0 statement:   
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _3ZIKPBvKOTb_0hFn5hLVVx5    
/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu);   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _0SFfKhzb4pm_7RK67LGwrJz #1 block:   
{ //for-up _4J34HGTqTy4_66SCBcnaZey    
intptr_t cnt_4J34HGTqTy4_66SCBcnaZey =  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k;    
for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;    
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_4J34HGTqTy4_66SCBcnaZey;    
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++) {    
// for-up _4J34HGTqTy4_66SCBcnaZey #0 :    
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _9nmnedFlmwv_7NFXDbCCmN6     
/*nodenthson:*/nodenthson_BM(( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));    
    
// for-up _4J34HGTqTy4_66SCBcnaZey #1 :    
    
{ // run _68QCY0hVNTQ_8m9JvLEP7DV    
/*debug emit_xhtml node-nlsp v_html ii v_comp o_emitctx o_strbuf depth*/
           DBGPRINTF_BM("debug emit_xhtml node-nlsp €%.9s v_html=%s ii#%ld v_comp=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
           "_68QCY0hVNTQ_8m9JvLEP7DV",
           OUTSTRVALUE_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),
           (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
           OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
           objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
           objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
           objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
           (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;    
} // end run _68QCY0hVNTQ_8m9JvLEP7DV    
    
// for-up _4J34HGTqTy4_66SCBcnaZey #2 :    
if /*cond _2A0sWNylTxY_73c0CvmEv7l*/     
/*when _7v3pnYrF5p8_9M8nrxqrHpp:*/    
 ((/*greater_int:*/( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) > ( 0))) { //body when _7v3pnYrF5p8_9M8nrxqrHpp     
{ // start out _9XFNI30yupO_3z5yrcHnnDF to o_strbuf      
/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);     
} // end out _9XFNI30yupO_3z5yrcHnnDF     
     
} //endwhen _7v3pnYrF5p8_9M8nrxqrHpp     
/*endcond _2A0sWNylTxY_73c0CvmEv7l*/    
    
// for-up _4J34HGTqTy4_66SCBcnaZey #3 :    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _5p72WnRjsAG_78DcKwtWA8B     
(apply4_BM (( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), ((struct stackframe_stBM*)&_), 
 ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));    
    
// for-up _4J34HGTqTy4_66SCBcnaZey #4 :    
    
{ // run _1WtG5aFhLF7_7M5XarvITEp    
/*debug emit_xhtml node-nlsp v_resemit v_comp ii o_html o_emitctx o_strbuf depth*/
            DBGPRINTF_BM("emit_xhtml node-nlsp €%.9s v_resemit=%s v_comp=%s ii#%ld o_html=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
          "_1WtG5aFhLF7_7M5XarvITEp",
          OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
          OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
          (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
          objectdbg_BM( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),
          objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
          objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
          objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
          (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
         ;    
} // end run _1WtG5aFhLF7_7M5XarvITEp    
    
// for-up _4J34HGTqTy4_66SCBcnaZey #5 :    
if /*cond _28ecnirVHcp_7KBOhbhNWhR*/     
/*when _7LY4sQ6kdfW_3PIOuFNdirP:*/    
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _7LY4sQ6kdfW_3PIOuFNdirP     
//failure _8cVgBa3uZXJ_3az91mVporu      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 8 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[71] /*!nlsp*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[82] /*|_8cVgBa3uZXJ_3az91mVporu*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _7LY4sQ6kdfW_3PIOuFNdirP     
/*endcond _28ecnirVHcp_7KBOhbhNWhR*/    
   
}} // end for-up _4J34HGTqTy4_66SCBcnaZey   
   
break; // end when _0SFfKhzb4pm_7RK67LGwrJz #0 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__18MTh926lG6_7yBzKpdhNUt:; // when #1 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _18MTh926lG6_7yBzKpdhNUt #0 statement:   
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _3ZIKPBvKOTb_0hFn5hLVVx5    
/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu);   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _18MTh926lG6_7yBzKpdhNUt #1 block:   
{ //for-up _6Qo2UMjnJYt_9LY57zD2Qlv    
intptr_t cnt_6Qo2UMjnJYt_9LY57zD2Qlv =  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k;    
for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;    
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_6Qo2UMjnJYt_9LY57zD2Qlv;    
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++) {    
// for-up _6Qo2UMjnJYt_9LY57zD2Qlv #0 :    
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _1UowDuXhOP4_2wrBi4rqtQR     
/*nodenthson:*/nodenthson_BM(( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));    
    
// for-up _6Qo2UMjnJYt_9LY57zD2Qlv #1 :    
    
{ // run _4wRX6MkXF4K_9GIufdivUrz    
/*debug emit_xhtml node-sequence v_html ii v_comp o_emitctx o_strbuf depth*/
    DBGPRINTF_BM("debug emit_xhtml node-sequence €%.9s v_html=%s ii#%ld v_comp=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
    "_4wRX6MkXF4K_9GIufdivUrz",
    OUTSTRVALUE_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),
    (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
    OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
    objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
    objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
    objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
    (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;    
} // end run _4wRX6MkXF4K_9GIufdivUrz    
    
// for-up _6Qo2UMjnJYt_9LY57zD2Qlv #2 :    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _87Lpy2ad4Wg_6GK4XGrN71Z     
(apply4_BM (( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), ((struct stackframe_stBM*)&_), 
 ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));    
    
// for-up _6Qo2UMjnJYt_9LY57zD2Qlv #3 :    
    
{ // run _0pPnX0uE75r_8vritLwQHdA    
/*debug emit_xhtml node-sequence v_resemit v_comp ii o_html o_emitctx o_strbuf depth*/
            DBGPRINTF_BM("emit_xhtml node-sequence €%.9s v_resemit=%s v_comp=%s ii#%ld o_html=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
          "_0pPnX0uE75r_8vritLwQHdA",
          OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
          OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
          (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
          objectdbg_BM( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),
          objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
          objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
          objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
          (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
         ;    
} // end run _0pPnX0uE75r_8vritLwQHdA    
    
// for-up _6Qo2UMjnJYt_9LY57zD2Qlv #4 :    
if /*cond _5P4QnjeLcFc_3AtJ1Gd1zUh*/     
/*when _7ESzGxRB6H4_6tCVm1YRpI2:*/    
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _7ESzGxRB6H4_6tCVm1YRpI2     
//failure _6OqEXCUrL6F_240nUUctLBX      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 8 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[35] /*!sequence*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[64] /*|_6OqEXCUrL6F_240nUUctLBX*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _7ESzGxRB6H4_6tCVm1YRpI2     
/*endcond _5P4QnjeLcFc_3AtJ1Gd1zUh*/    
   
}} // end for-up _6Qo2UMjnJYt_9LY57zD2Qlv   
   
break; // end when _18MTh926lG6_7yBzKpdhNUt #1 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__1dPD74MjKcz_4jtiBI8XE0Q:; // when #2 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
break; // end when _1dPD74MjKcz_4jtiBI8XE0Q #2 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__24qz4eJavv3_1P062j7RIWK:; // when #3 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _24qz4eJavv3_1P062j7RIWK #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[90] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[83] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
   
break; // end when _24qz4eJavv3_1P062j7RIWK #3 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__2ipfKe1iRAC_1L7DdWqaMNI:; // when #4 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _2ipfKe1iRAC_1L7DdWqaMNI #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[90] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[83] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
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
   
   
break; // end when _2ipfKe1iRAC_1L7DdWqaMNI #4 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__2pklfVqX1ZE_8wPD1xPoPFV:; // when #5 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _2pklfVqX1ZE_8wPD1xPoPFV #0 statement:   
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _3ZIKPBvKOTb_0hFn5hLVVx5    
/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu);   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _2pklfVqX1ZE_8wPD1xPoPFV #1 block:   
{ //for-up _4l0WplxDvr6_0eKlHUSRqXn    
intptr_t cnt_4l0WplxDvr6_0eKlHUSRqXn =  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k;    
for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;    
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_4l0WplxDvr6_0eKlHUSRqXn;    
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++) {    
// for-up _4l0WplxDvr6_0eKlHUSRqXn #0 :    
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _3Y98z8Qiqlv_1neMNtYblX5     
/*nodenthson:*/nodenthson_BM(( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));    
    
// for-up _4l0WplxDvr6_0eKlHUSRqXn #1 :    
    
{ // run _3O3g1RNnKcs_7aGgO0ZsLD9    
/*debug emit_xhtml node-newline v_html ii v_comp o_emitctx o_strbuf depth*/
           DBGPRINTF_BM("debug emit_xhtml node-newline €%.9s v_html=%s ii#%ld v_comp=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
           "_3O3g1RNnKcs_7aGgO0ZsLD9",
           OUTSTRVALUE_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),
           (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
           OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
           objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
           objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
           objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
           (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;    
} // end run _3O3g1RNnKcs_7aGgO0ZsLD9    
    
// for-up _4l0WplxDvr6_0eKlHUSRqXn #2 :    
if /*cond _2EeFgs3zhwD_1lUpBwOj2RC*/     
/*when _8mdLCY8IzT1_5njkT9FO4oB:*/    
 ((/*greater_int:*/( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) > ( 0))) { //body when _8mdLCY8IzT1_5njkT9FO4oB     
{ // start out _1nIXl8AGeBk_6M9VFZCpN62 to o_strbuf      
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);     
} // end out _1nIXl8AGeBk_6M9VFZCpN62     
     
} //endwhen _8mdLCY8IzT1_5njkT9FO4oB     
/*endcond _2EeFgs3zhwD_1lUpBwOj2RC*/    
    
// for-up _4l0WplxDvr6_0eKlHUSRqXn #3 :    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _5VdelxBYboz_0OMr8BEzpGh     
(apply4_BM (( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), ((struct stackframe_stBM*)&_), 
 ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));    
    
// for-up _4l0WplxDvr6_0eKlHUSRqXn #4 :    
    
{ // run _2zpnLMawggN_4g2YyiGB7Dx    
/*debug emit_xhtml node-newline v_resemit v_comp ii o_html o_emitctx o_strbuf depth*/
            DBGPRINTF_BM("emit_xhtml node-newline €%.9s v_resemit=%s v_comp=%s ii#%ld o_html=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
          "_2zpnLMawggN_4g2YyiGB7Dx",
          OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
          OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
          (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
          objectdbg_BM( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),
          objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
          objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
          objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
          (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
         ;    
} // end run _2zpnLMawggN_4g2YyiGB7Dx    
    
// for-up _4l0WplxDvr6_0eKlHUSRqXn #5 :    
if /*cond _0Cx77dfDSha_5Z0sqyJ1a64*/     
/*when _7QVWwCSqvsr_3xUNFgDr9YK:*/    
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _7QVWwCSqvsr_3xUNFgDr9YK     
//failure _1TYnCEX7OSe_1Ar0cZHkxis      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 8 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[14] /*!newline*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[11] /*|_1TYnCEX7OSe_1Ar0cZHkxis*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _7QVWwCSqvsr_3xUNFgDr9YK     
/*endcond _0Cx77dfDSha_5Z0sqyJ1a64*/    
   
}} // end for-up _4l0WplxDvr6_0eKlHUSRqXn   
   
break; // end when _2pklfVqX1ZE_8wPD1xPoPFV #5 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__2LXkoXMNcGg_6FWal4v09Nf:; // when #6 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _2LXkoXMNcGg_6FWal4v09Nf #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[90] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[83] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _2LXkoXMNcGg_6FWal4v09Nf #1 statement:   
{ // start out _5iQWFM7g7Dk_2kc5q4nsdp1 to o_strbuf    
/*out hexa:*/ objstrbufferprintfpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "%llx", (long long)  /* val_to_int */ getint_BM(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0))) );   
} // end out _5iQWFM7g7Dk_2kc5q4nsdp1   
   
   
break; // end when _2LXkoXMNcGg_6FWal4v09Nf #6 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__34JfZ8fuP0p_6pFQ2GljNtB:; // when #7 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _34JfZ8fuP0p_6pFQ2GljNtB #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[90] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[83] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _34JfZ8fuP0p_6pFQ2GljNtB #1 statement:   
{ // start out _3jvq2V6NsBC_7LeoGHLIR1h to o_strbuf    
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0)))));   
} // end out _3jvq2V6NsBC_7LeoGHLIR1h   
   
   
break; // end when _34JfZ8fuP0p_6pFQ2GljNtB #7 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__4xEPE1lbFOl_12yQbp8UM1B:; // when #8 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _4xEPE1lbFOl_12yQbp8UM1B #0 statement:   
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _3ZIKPBvKOTb_0hFn5hLVVx5    
/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu);   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _4xEPE1lbFOl_12yQbp8UM1B #1 block:   
{ //for-up _76hxCg5xWfV_4jJsIGYErv5    
intptr_t cnt_76hxCg5xWfV_4jJsIGYErv5 =  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k;    
for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;    
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_76hxCg5xWfV_4jJsIGYErv5;    
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++) {    
// for-up _76hxCg5xWfV_4jJsIGYErv5 #0 :    
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _32dVyuDFrnE_6Dkc1IXCX0E     
/*nodenthson:*/nodenthson_BM(( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));    
    
// for-up _76hxCg5xWfV_4jJsIGYErv5 #1 :    
    
{ // run _4J8nO2ztPeM_41qxImGu8UI    
/*debug emit_xhtml node-space v_html ii v_comp o_emitctx o_strbuf depth*/
           DBGPRINTF_BM("debug emit_xhtml node-space €%.9s v_html=%s ii#%ld v_comp=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
           "_4J8nO2ztPeM_41qxImGu8UI",
           OUTSTRVALUE_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),
           (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
           OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
           objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
           objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
           objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
           (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;    
} // end run _4J8nO2ztPeM_41qxImGu8UI    
    
// for-up _76hxCg5xWfV_4jJsIGYErv5 #2 :    
if /*cond _3FAokZZ35KX_3xTdcRYjNYH*/     
/*when _7UrHchq7sps_3aUJDmsB9Ow:*/    
 ((/*greater_int:*/( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) > ( 0))) { //body when _7UrHchq7sps_3aUJDmsB9Ow     
{ // start out _9PsPYnBDy18_5puD3TFsXZH to o_strbuf      
/*out space:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " ");     
} // end out _9PsPYnBDy18_5puD3TFsXZH     
     
} //endwhen _7UrHchq7sps_3aUJDmsB9Ow     
/*endcond _3FAokZZ35KX_3xTdcRYjNYH*/    
    
// for-up _76hxCg5xWfV_4jJsIGYErv5 #3 :    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _96dlANghyiV_8NF8rDvFGap     
(apply4_BM (( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), ((struct stackframe_stBM*)&_), 
 ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));    
    
// for-up _76hxCg5xWfV_4jJsIGYErv5 #4 :    
    
{ // run _4Vt3y6pJx9H_7RfLb8whrps    
/*debug emit_xhtml node-space v_resemit v_comp ii o_html o_emitctx o_strbuf depth*/
            DBGPRINTF_BM("emit_xhtml node-space €%.9s v_resemit=%s v_comp=%s ii#%ld o_html=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
          "_4Vt3y6pJx9H_7RfLb8whrps",
          OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
          OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
          (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
          objectdbg_BM( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf),
          objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
          objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
          objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
          (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
         ;    
} // end run _4Vt3y6pJx9H_7RfLb8whrps    
    
// for-up _76hxCg5xWfV_4jJsIGYErv5 #5 :    
if /*cond _9SWyMMpkKC9_9BmIIPT0sC5*/     
/*when _4qnPIzPNrRM_6ZEJvaKcNmT:*/    
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _4qnPIzPNrRM_6ZEJvaKcNmT     
//failure _2EvLzORL4da_9CnxX7Kz62G      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 8 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[22] /*!space*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_html:*/_.o_9GjmuXWAb93_7ZScgIdlvkf), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[15] /*|_2EvLzORL4da_9CnxX7Kz62G*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _4qnPIzPNrRM_6ZEJvaKcNmT     
/*endcond _9SWyMMpkKC9_9BmIIPT0sC5*/    
   
}} // end for-up _76hxCg5xWfV_4jJsIGYErv5   
   
break; // end when _4xEPE1lbFOl_12yQbp8UM1B #8 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__540K9iKhE21_8CfNTVKZFm2:; // when #9 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _540K9iKhE21_8CfNTVKZFm2 #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[90] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[83] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
   
break; // end when _540K9iKhE21_8CfNTVKZFm2 #9 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__5mtc4t5tNdH_7cmF7sZJihN:; // when #10 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _5mtc4t5tNdH_7cmF7sZJihN #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[90] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[83] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
   
break; // end when _5mtc4t5tNdH_7cmF7sZJihN #10 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__5NpWcVegQxj_1RHui16VqMR:; // when #11 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _5NpWcVegQxj_1RHui16VqMR #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[90] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[83] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
   
break; // end when _5NpWcVegQxj_1RHui16VqMR #11 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__63JazyO1dWC_8Y52ZEbX0AB:; // when #12 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _63JazyO1dWC_8Y52ZEbX0AB #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[90] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[83] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _63JazyO1dWC_8Y52ZEbX0AB #1 statement:   
{ // start out _4hUnjsObgNm_7ZwBGfkBkis to o_strbuf    
/*out double_plain:*/ objstrbufferprintfpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "%g", /*val_to_double:*/getdouble_BM(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0))));   
} // end out _4hUnjsObgNm_7ZwBGfkBkis   
   
   
break; // end when _63JazyO1dWC_8Y52ZEbX0AB #12 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__6mGSw6UbZ62_2G1WgWKLI2x:; // when #13 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _6mGSw6UbZ62_2G1WgWKLI2x #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[90] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[83] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
   
break; // end when _6mGSw6UbZ62_2G1WgWKLI2x #13 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__7uiwyR9sfq3_1W9SQnuJLSz:; // when #14 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _7uiwyR9sfq3_1W9SQnuJLSz #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[90] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[83] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _7uiwyR9sfq3_1W9SQnuJLSz #1 statement:   
{ // start out _59mull0TRXy_9hXUrwSmKcD to o_strbuf    
/*out c_enc:*/ objstrbufferencodedcpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0)))), -1);   
} // end out _59mull0TRXy_9hXUrwSmKcD   
   
   
break; // end when _7uiwyR9sfq3_1W9SQnuJLSz #14 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__83FAPFTeIAi_8I9ZDO0kn7L:; // when #15 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _83FAPFTeIAi_8I9ZDO0kn7L #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[90] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[83] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _83FAPFTeIAi_8I9ZDO0kn7L #1 statement:   
{ // start out _1ULVfSCNpMe_1x4YuC8IcMP to o_strbuf    
/*out double_float:*/(void) objstrbufferoutdoublepayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*val_to_double:*/getdouble_BM(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0))));   
} // end out _1ULVfSCNpMe_1x4YuC8IcMP   
   
   
break; // end when _83FAPFTeIAi_8I9ZDO0kn7L #15 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__8SBMgF9WUmn_0k1vdQISETG:; // when #16 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _8SBMgF9WUmn_0k1vdQISETG #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[90] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[83] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _8SBMgF9WUmn_0k1vdQISETG #1 statement:   
{ // start out _53cWvliCIwT_8vm2uoHHKzw to o_strbuf    
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "<!--");    
/*out html_enc:*/ objstrbufferencodedhtmlpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0)))), -1);    
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "-->");   
} // end out _53cWvliCIwT_8vm2uoHHKzw   
   
   
break; // end when _8SBMgF9WUmn_0k1vdQISETG #16 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
   
whenobj4ySLl7UU__9aOs4PCRfQB_7wgCM2MmXMg:; // when #17 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _9aOs4PCRfQB_7wgCM2MmXMg #0 statement:   
if /*cond _6kMu9FzjNaV_81NFYpU63dZ*/    
/*when _2UrMXUkmSru_3wmMLxYIl9M:*/   
 ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1))) { //body when _2UrMXUkmSru_3wmMLxYIl9M    
//failure _8i7m9bhUXQc_9cM9pXIykQh     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[90] /*!failure_bad_rank*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[83] /*|_8i7m9bhUXQc_9cM9pXIykQh*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _2UrMXUkmSru_3wmMLxYIl9M    
/*endcond _6kMu9FzjNaV_81NFYpU63dZ*/   
   
 // objswitch _4ySLl7UU6Hw_7pgQRbU4gFX when _9aOs4PCRfQB_7wgCM2MmXMg #1 statement:   
{ // start out _2VlJEMfhfGy_2Dqeddiju8Q to o_strbuf    
/*out local_time:*/objstrbufferencodelocaltimepayl_BM(( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), /*val_to_double:*/getdouble_BM(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0))));   
} // end out _2VlJEMfhfGy_2Dqeddiju8Q   
   
   
break; // end when _9aOs4PCRfQB_7wgCM2MmXMg #17 of objswitch _4ySLl7UU6Hw_7pgQRbU4gFX   
  
} } // end objswitch _4ySLl7UU6Hw_7pgQRbU4gFX  
  
} //endwhen _0TcBev05JBd_3KDoGzpRVI6  
else if  
/*when _2zIx3cm1VDP_6iMKf9MSCFc:*/ 
 (/*isclosure:*/isclosure_BM(( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu))) { //body when _2zIx3cm1VDP_6iMKf9MSCFc  
  
{ // run _99WAlxYH1SR_8IW8HiU059Z  
/*debug closure  v_html o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emit_xhtml €%.9s closure v_html=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_99WAlxYH1SR_8IW8HiU059Z",
 OUTSTRVALUE_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),
 objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;  
} // end run _99WAlxYH1SR_8IW8HiU059Z  
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _7VuxFufYIIA_1CuXosHo5uz   
(apply3_BM (( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), ((struct stackframe_stBM*)&_), 
 ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),  ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));  
  
{ // run _1NwA3t1RT4y_4jAhhYtyhq5  
/*debug after closure v_resemit v_html o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emit_xhtml €%.9s after closure v_resemit=%s v_html=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld",
 "_1NwA3t1RT4y_4jAhhYtyhq5",
 OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
 OUTSTRVALUE_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),
 objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;  
} // end run _1NwA3t1RT4y_4jAhhYtyhq5  
if /*cond _73DcaFzzrzZ_1y8o5H2pRkx*/   
/*when _2alU2egozIo_2JGsKfuMxvl:*/  
 (/*isclosure:*/isclosure_BM(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV))) { //body when _2alU2egozIo_2JGsKfuMxvl   
//failure _2FNk4F7cVdX_3c7wLj7NaKo    
PLACEDFAILURE_BM(__LINE__,    
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[93] /*!failure_type_error*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[92] /*!closure*/)), 
 
( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[17] /*|_2FNk4F7cVdX_3c7wLj7NaKo*/)),
                ((struct stackframe_stBM *) &_));
   
} //endwhen _2alU2egozIo_2JGsKfuMxvl   
else if   
/*when _7Tm3SaqITAB_7FjAFBmgHFi:*/  
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _7Tm3SaqITAB_7FjAFBmgHFi   
//failure _9BnClw26jr7_7AZtUCFn3Qg    
PLACEDFAILURE_BM(__LINE__,    
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[92] /*!closure*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[96] /*|_9BnClw26jr7_7AZtUCFn3Qg*/)),
                ((struct stackframe_stBM *) &_));
   
} //endwhen _7Tm3SaqITAB_7FjAFBmgHFi   
/*endcond _73DcaFzzrzZ_1y8o5H2pRkx*/  
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _8vNml5uMC0m_2vGIOtMygY3   
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV;  
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _6roYZ0BqbWo_7vWl1xqQQ6n   
(apply4_BM (( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), ((struct stackframe_stBM*)&_), 
 ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),  ( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));  
  
{ // run _5JehRXufCKr_0L7eGX5Wemo  
/*debug closure after emit_xhtml v_resemit v_comp o_emitctx o_strbuf depth*/
  DBGPRINTF_BM("closure after emit_xhtml €%.9s v_resemit=%s v_comp=%s o_emitctx=%s o_strbuf=%s/L%u depth#%ld /emit_xhtml",
   "_5JehRXufCKr_0L7eGX5Wemo",
   OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
   OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
   objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
   objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
   (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
  ;  
} // end run _5JehRXufCKr_0L7eGX5Wemo  
if /*cond _3Ua80zB4LYL_1wnpgWR5utO*/   
/*when _0DshVxAxb6a_3I1VHeh1lh2:*/  
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _0DshVxAxb6a_3I1VHeh1lh2   
//failure _8zNKAZDtdWY_5UJDDoGynAg    
PLACEDFAILURE_BM(__LINE__,    
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[49] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
// make_node arg #4 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[88] /*|_8zNKAZDtdWY_5UJDDoGynAg*/)),
                ((struct stackframe_stBM *) &_));
   
} //endwhen _0DshVxAxb6a_3I1VHeh1lh2   
/*endcond _3Ua80zB4LYL_1wnpgWR5utO*/  
/*return _8oLlhYNOYFR_9nxph2FBFRd:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned  
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV;  
 goto epilog_8IYFtn8osS2_4t1U3wyROLW;  
  
} //endwhen _2zIx3cm1VDP_6iMKf9MSCFc  
else { /*cond else _23svN0ubUj6_7fLFEqkDSEu*/  
//failure _9ICwe1aOJtc_5TzmQ59QZrs  
PLACEDFAILURE_BM(__LINE__,  
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[93] /*!failure_type_error*/)), 
 /*make_node 5 sons:*/ 
( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[89] /*!emit_xhtml*/)), 
 
( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu), 
 
( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0), 
 
// make_node arg #4 
( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[97] /*|_9ICwe1aOJtc_5TzmQ59QZrs*/)),
                ((struct stackframe_stBM *) &_));
} /*cond else _23svN0ubUj6_7fLFEqkDSEu*/  
/*endcond _23svN0ubUj6_7fLFEqkDSEu*/ 
 
 
 
{ // run _1WjZ3R1QQhl_5JQ4Cqgmxcr 
/*debug end emit_xhtml v_html o_emitctx o_strbuf depth*/
DBGPRINTF_BM("emit_xhtml end €%.9s v_html=%s o_emitctx=%s\n... o_strbuf=%s/L%u (lin:%u col:%u last'%s') depth#%ld",
"_1WjZ3R1QQhl_5JQ4Cqgmxcr",
OUTSTRVALUE_BM( /*v_html:*/_.v_0DmuWueFbx9_5bzv8xgw3fu),
objectdbg_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
objectdbg1_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
objstrbufferlinecountpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
objstrbuffercolumnpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
objstrbuffercurrentlastlinepayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
(long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
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
} // end _8IYFtn8osS2_4t1U3wyROLW routine#15 emit_xhtml




value_tyBM crout_9hEreAemqXg_0uoN1Fr1ly4_BM //#16
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
   _.stkfram_descr = constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[95] /*|_9hEreAemqXg_0uoN1Fr1ly4*/;
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
   const unsigned nbclosed_9hEreAemqXg_0uoN1Fr1ly4 = closurewidth_BM ((const value_tyBM) callclos_9hEreAemqXg_0uoN1Fr1ly4);
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
 
//+ #2/10 of block _0dR2udLAHI6_6XdsSwwp24Y :: 
 
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
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*val_to_object:*/objectcast_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[26] /*!html_tag*/))))));  
  
} //endwhen _41uV2yIAp43_2Yu4V5fz3ui  
/*endcond _8hn8DdBoSyJ_1NJHIGIUSmC*/ 
 
 
if /*cond _981Htnuqk2v_3f6kRQZBkNI*/  
/*when _5usxraGoWWN_2A5IJEfVFat:*/ 
 (/*is_stringv:*/ isstring_BM( /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t)) { //body when _5usxraGoWWN_2A5IJEfVFat  
 /*v_htmlclassstr:*/_.v_9AuPELEBCEG_3r2aCy2y3Pc = //assign _7YpZd8yYOAD_5IjRXGsTBUs   
 /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t;  
  
} //endwhen _5usxraGoWWN_2A5IJEfVFat  
else if  
/*when _3B2yJwjdy53_7VKdj7byIy6:*/ 
 (/*is_objectv*/ isobject_BM( /*v_htmlclass:*/_.v_0wWVh40nozk_7OSKII1HZ6t)) { //body when _3B2yJwjdy53_7VKdj7byIy6  
 /*v_htmlclassstr:*/_.v_9AuPELEBCEG_3r2aCy2y3Pc = //assign _2a9vb10NrAs_706MrL2b0eq   
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*val_to_object:*/objectcast_BM( /*v_htmltag:*/_.v_6nmKmS2Auzh_04y9gBqgcDG)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[54] /*!html_class*/))))));  
  
} //endwhen _3B2yJwjdy53_7VKdj7byIy6  
/*endcond _981Htnuqk2v_3f6kRQZBkNI*/ 
 
//+ #4/10 of block _0dR2udLAHI6_6XdsSwwp24Y :: 
 
{ // start out _6r8MxUGERZ5_62WMoVCfmcU to o_strbuf  
/*out set_indent:*/ objstrbuffersetindentpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy,  /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f);  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "<");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_htmltagstr:*/_.v_6p6w3jZv5gy_58EzMDpOBQJ)));  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " class=\'");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_htmlclassstr:*/_.v_9AuPELEBCEG_3r2aCy2y3Pc)));  
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
/*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM((/*object_cast:*/(value_tyBM)objectcast_BM( /*v_idprefix:*/_.v_8VgHiZPlXwn_5i6tFD7vAVB)),( (constob_9dQJgjsq7hs_2T2RqXLkU0A_BM[84] /*!html_idprefix*/))))));  
  
} //endwhen _8L1ziPttLIT_5je6y8T504n  
/*endcond _9H0L8bKRxNs_6ZLNYQisXhr*/ 
 
//+ #6/10 of block _0dR2udLAHI6_6XdsSwwp24Y :: 
 
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
 
//+ #8/10 of block _0dR2udLAHI6_6XdsSwwp24Y :: 
 
 
{ // run _8m90hPZpNWM_7eUa1YgrU1u 
/*debug emit-tagged-id-xhtml-open end v_htmltagstr o_helem o_emitctx o_strbuf depth*/
DBGPRINTF_BM("debug emit-tagged-id-xhtml-open end €%.9s v_htmltagstr=%s o_helem=%s o_emitctx=%s\n... o_strbuf=%s/L%u (lin:%u col:%u last'%s') depth#%ld",
 "_8m90hPZpNWM_7eUa1YgrU1u",
 OUTSTRVALUE_BM( /*v_htmltagstr:*/_.v_6p6w3jZv5gy_58EzMDpOBQJ),
 objectdbg_BM( /*o_helem:*/_.o_6Ef2ORO1Mni_0tpNoRQGmrW),
 objectdbg1_BM( /*o_emitctx:*/_.o_9nXRmTATjN4_5F9V7RvvgW0),
 objectdbg2_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlengthpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbufferlinecountpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbuffercolumnpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 objstrbuffercurrentlastlinepayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _8m90hPZpNWM_7eUa1YgrU1u 
 
 
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
} // end _9hEreAemqXg_0uoN1Fr1ly4 routine#16 _9hEreAemqXg_0uoN1Fr1ly4




// end of 17 generated routines


// the constant ids for 98 constants:
const char* const constid_9dQJgjsq7hs_2T2RqXLkU0A_BM[98+1] = {
 /*0:*/
 "_01h86SAfOfg_1q2oMegGRwW",//comment
 "_031bGeN8S0j_96cNAJfzYBE",//the_web_sessions
 "_0vgCFjXblkx_4zCMhMAWjVK",//int
 "_0FRLxSGQlZ0_0qrrUZlEeKp", //! emitxhtml_void_element (o_helem o_emitctx o_strbuf v_depth)
 "_0NH2lnQIrTb_7Kt3mvQUoVu", //! emit_xhtml_open°simple_html_element_object < o_helem (o_emitctx o_strbuf v_depth)
 /*5:*/
 "_160pmVixE1q_0RLuDpytNXw", //! body of forgotemailsender
 "_1lCz1IP7t5R_8NTFVv0tnOi",//octa
 "_1JSykdLcLdl_8rWxtDBaPGN",//none
 "_1LdXMeDLWFL_0df1wmR8KD7", //! else fail-type-error  /emit-tagged-id-more-xhtml-open v_more o_helem o_emitctx o_strbuf depth
 "_1P3gVK5iIH8_62cj5fqHcIv", //! fail-miss o_helem o_websess o_webex //root-web-handler
 /*10:*/
 "_1TLjn3qChsY_0RCEhuUWUyo", //! fail-miss emit-href-from-webssesion-web_theme web_theme o_helem o_websess o_strbuf depth
 "_1TYnCEX7OSe_1Ar0cZHkxis", //! fail-miss emit_xhtml newline v_comp ii o_html o_emitctx o_strbuf depth
 "_2ekmsdDpheM_8iSH1r9pS9e", //! fail non-object emitxhtml_element o_emitctx o_strbuf depth
 "_2qDaJRPDbEG_45AvdxtQXAM",//double_float
 "_2wGWzItVmrN_2CBwG6iHWFO",//newline
 /*15:*/
 "_2EvLzORL4da_9CnxX7Kz62G", //! fail-miss emit_xhtml space v_comp ii o_html o_emitctx o_strbuf depth
 "_2EDrV58DM9y_5GXjoUigj3r",//raw_string
 "_2FNk4F7cVdX_3c7wLj7NaKo", //! fail-type_error closure v_resemit v_html o_emitctx o_strbuf depth /emit_xhtml
 "_2P7OoZumXdx_5sUQ9SPbVwn",//utf8_enc
 "_2Uksq9GtGL5_6mG06OtMZF1", //! emit-href-from-webssesion-web_theme (o_helem o_websess o_strbuf depth)
 /*20:*/
 "_2W2LFnO44dr_973izSVn0hU",//local_time
 "_33eRuL6abjL_4uGwIWu51cd", //! else fail-miss emitxhtml_void_element v_resemit o_helem o_emitctx o_strbuf depth
 "_35gLacRFhq5_90zAPxiDIlh",//space
 "_3602vaaly3m_2GoqnKUc8u3", //! fail-both emit_xhtml_node & emit_xhtml_open in o_conn  v_html o_emitctx o_strbuf depth /emit_xhtml node else
 "_3owspX08bkm_6vBzqS5jskf", //! emit-websession-contributor (o_emitctx o_strbuf depth)
 /*25:*/
 "_3poYCpSsBfJ_8W7XNwG50hS", //! root-html-element
 "_3sJy6RT5X9u_1r0Sucfx4np",//html_tag
 "_3yiACzSlNbu_55MjgO9bSLz",//emit_xhtml_node
 "_3zzOJ9b7sUf_89ZOhP1HlUQ",//failure_full
 "_3EfvM2lT7h3_8fHXQsltxSG", //! fail-badclass emitxhtml_void_element 
 /*30:*/
 "_3ECxU06gRdk_8uZReHKm10m", //! fail-type_error emitxhtml_void_element v_resemit o_helem o_emitctx o_strbuf depth
 "_3Nl6LhfUZVb_1itsyWMBfYl",//apply
 "_3O7E8gjmVNG_42OFG3GueZX", //! fail-miss emitxhtml_element emit_xhtml o_html o_emitctx o_strbuf depth
 "_3QmxfIKpDVI_0C4Z01aFVxK",//html_enc
 "_3U4iMDjauSJ_350GrrqVStR", //! fail-miss emit-tagged-id-more-xhtml-open apply v_more o_helem o_emitctx o_strbuf depth
 /*35:*/
 "_47qleKxWAvS_0wCCWm6gtfa",//sequence
 "_4dpEDjJFo47_1WU3n2D3esH", //! fail-miss emit_xhtml emit_xhtml_connective_open v_comp ii o_html o_emitctx o_strbuf depth
 "_4fUC5oegPuC_8hJQc9RBblV", //! fail-miss emit_xhtml html_active_object o_html o_emitctx o_strbuf depth
 "_4nCl6kh6zgK_8WQFqxe24i2", //! fail-type_error html_void_element o_helem o_emitctx o_strbuf depth / emitxhtml_void_element
 "_4uOuGQOR8oV_1fJJzlmYTHN",//default_web_theme
 /*40:*/
 "_4veY1dO90jF_7ThxWXJ0cIl", //! fail-miss emitxhtml_void_element emit_xhtml o_html o_emitctx o_strbuf depth
 "_4xwDKklt2v4_2lEbck0j4qs", //! html_spacing°simple*html*element < o_helem (o_emitctx v_depth)
 "_4BSjKuvOgrt_81MLC8NyKiS",//double_plain
 "_4HgYLk6htvP_4Ac2FCPfQ1C",//failure_bad_class
 "_4Hsn8KettH9_38n6JYQgUiC", //! fail-miss emit_xhtml v_clos o_html o_emitctx o_strbuf depth
 /*45:*/
 "_4HR54GlXs46_4rDg4Tb637x",//web_theme
 "_4I0ksnAasRT_1bREYU29xgL", //! emit-tagged-xhtml-open [v_htmltag v_htmlclass] (o_helem o_emitctx o_strbuf v_depth)
 "_4U5ZaR7UTwF_2LXJtkMOr6l",//buffer
 "_51oIiJoCulz_1NyarSIagfB", //! fail-miss emit_xhtml v_comp ii o_emitctx o_strbuf depth
 "_52XwytpOPVl_3ZjmQCtadbK",//failure_miss
 /*50:*/
 "_5ov2KpemmVg_0cMgvKrBTvJ",//html_void_element_object
 "_5rs4UfgeATT_3s7r48scObY", //! fail-bad-class html_element_object o_helem o_emitctx o_strbuf depth - emitxhtml_element
 "_5xGV4qXFkqJ_4imeaugtTzv", //! fail-miss emit_xhtml_open _helem o_emitctx depth
 "_5NH940lCHYJ_3nuRm3flnzc", //! emitxhtml_element (o_helem o_emitctx o_strbuf v_depth)
 "_5RD0QJ0X5kp_8vHHK68Qn2R",//html_class
 /*55:*/
 "_5T8fxyaeOFA_4UrB3BPbWdn", //! emit-websession-cookie (o_emitctx o_strbuf depth)
 "_64Nwpjx4gnk_2y263bTCaB3",//emit_xhtml_open
 "_650BGD0ANMH_4gN3duymnz3", //! fail-miss emit_xhtml html_sequence_object v_comp ii o_html o_emitctx o_strbuf depth
 "_6aWaLxHQBv4_9bcZim3ljEh", //! _forgotemail-webhandler (v_restpath o_webex)
 "_6xxbA8aTjZm_1sCJbVkU3Pm",//c_enc
 /*60:*/
 "_6yc00QTj7DW_2epaxvQ7ttJ", //! fail-miss emit_xhtml_node  v_html o_emitctx o_strbuf depth /emit_xhtml other node
 "_6yWldsq3Rmk_01WqTfwSIDV",//failure_non_object
 "_6DRTSnSILai_5h2aK5DTLAu",//emit_xhtml_connective_open
 "_6L4mPBNfWGs_5PaIqa8vfVo", //! fail-miss  o_helem o_emitctx o_strbuf depth v_clos is nil /emit_xhtml_open°simple_html_element_object
 "_6OqEXCUrL6F_240nUUctLBX", //! fail-miss emit_xhtml sequence v_comp ii o_html o_emitctx o_strbuf depth
 /*65:*/
 "_6RtF29C4pij_9r269Lc0d0W", //! emit_xhtml_open°simple_void_html_element_object < o_helem (o_emitctx o_strbuf v_depth)
 "_6STwOZTcBwM_6wz4Akuletb", //! forgotemailsender (o_contrib o_decayemail)
 "_6TYtJU0rl2h_2z4md7DV06z", //! root-web-handler (v_restpath o_webex)
 "_77eAIoJ7YJJ_6zJy8HNioJC",//html_active_object
 "_79ub6Ngc5aa_42TtfuLTsPs", //! fail failure_miss emit_xhtml v_html o_emitctx depth // too deep
 /*70:*/
 "_7brFPQS8mP9_4K0sGjTwZ3T",//file_path
 "_7coI3Hezrvp_6CG1u3MlT83",//nlsp
 "_7gcGSxzwbaX_9tmqbEbjvo0",//html_sequence_object
 "_7FvfalQCaxj_24GCf5CtIWh",//html_element_object
 "_7PgBB7uIPOd_65NhmUjoLJf", //! fail-miss  o_helem o_emitctx o_strbuf depth v_clos is nil
 /*75:*/
 "_7T9OwSFlgov_0wVJaK1eZbn",//object
 "_7WjaQkqwdaZ_6PRtbDrJHnf",//id
 "_7YmEzAVe2hC_9iA0FVXAIqp",//hexa
 "_82VLSjbMBWQ_0T9PzaxvTKV",//failure_both
 "_84d7WOdRsJh_4Ud9BryxYUr",//html_spacing
 /*80:*/
 "_85938GaqS1z_3mZSenKG7GG", //! emit-tagged-id-more-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget v_more] (o_helem o_emitctx o_strbuf v_depth)
 "_8c3wK0SptYZ_6EpzaOaJVJc", //! fail-type_error emit_xhtml_open o_helem o_emitctx o_strbuf depth /emitxhtml_element
 "_8cVgBa3uZXJ_3az91mVporu", //! fail-miss emit_xhtml nlsp v_comp ii o_html o_emitctx o_strbuf depth
 "_8i7m9bhUXQc_9cM9pXIykQh", //! fail-bad-rank emit_xhtml v_html o_emitctx o_strbuf depth
 "_8mOOvH4LOKB_5gaXDGw68tw",//html_idprefix
 /*85:*/
 "_8oKFbiPI4JW_7EPg4RP1e4Q", //! emit-raw-tag-xhtml-open [v_tagstr v_restagstr] (o_helem o_emitctx o_strbuf v_depth)
 "_8sdgc5Y7vPU_9Nvj5CtRqaQ", //! doapp-web-handler (v_restpath o_webex)
 "_8yowRQLZgzP_4vqWjo12OS4", //! fail failure_full emit_xhtml v_html o_emitctx depth
 "_8zNKAZDtdWY_5UJDDoGynAg", //! fail-miss emit_xhtml v_comp  v_html o_emitctx o_strbuf depth /emit_xhtml
 "_8IYFtn8osS2_4t1U3wyROLW",//emit_xhtml
 /*90:*/
 "_8MFQuVGkedx_8OkpYlCQFip",//failure_bad_rank
 "_8XlKCYnNu3S_6KsoDHN7IEF", //! else fail-type emit_xhtml_connective_open v_resemit o_conn v_emitopen  o_emitctx o_strbuf depth v_html
 "_93zjUzZVAaj_9ppXv7C34GR",//closure
 "_95hdJENHNkN_3QuKIJTCQQQ",//failure_type_error
 "_9dQJgjsq7hs_2T2RqXLkU0A",//webxhtml_module
 /*95:*/
 "_9hEreAemqXg_0uoN1Fr1ly4", //! emit-tagged-id-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget] (o_helem o_emitctx o_strbuf v_depth)
 "_9BnClw26jr7_7AZtUCFn3Qg", //! fail-miss closure  v_html o_emitctx o_strbuf depth /emit_xhtml
 "_9ICwe1aOJtc_5TzmQ59QZrs", //! else fail-typeerror emit_xhtml v_html o_emitctx o_strbuf depth
 NULL}; // end 98 constant ids



// the routine ids for 17 routines:
const char* const routid_9dQJgjsq7hs_2T2RqXLkU0A_BM[17+1] = {
  /*0:*/
  "_0FRLxSGQlZ0_0qrrUZlEeKp", //!emitxhtml_void_element (o_helem o_emitctx o_strbuf v_depth)
  "_0NH2lnQIrTb_7Kt3mvQUoVu", //!emit_xhtml_open°simple_html_element_object < o_helem (o_emitctx o_strbuf v_depth)
  "_2Uksq9GtGL5_6mG06OtMZF1", //!emit-href-from-webssesion-web_theme (o_helem o_websess o_strbuf depth)
  "_3owspX08bkm_6vBzqS5jskf", //!emit-websession-contributor (o_emitctx o_strbuf depth)
  "_4xwDKklt2v4_2lEbck0j4qs", //!html_spacing°simple*html*element < o_helem (o_emitctx v_depth)
  "_4I0ksnAasRT_1bREYU29xgL", //!emit-tagged-xhtml-open [v_htmltag v_htmlclass] (o_helem o_emitctx o_strbuf v_depth)
  "_5NH940lCHYJ_3nuRm3flnzc", //!emitxhtml_element (o_helem o_emitctx o_strbuf v_depth)
  "_5T8fxyaeOFA_4UrB3BPbWdn", //!emit-websession-cookie (o_emitctx o_strbuf depth)
  /*8:*/
  "_6aWaLxHQBv4_9bcZim3ljEh", //!_forgotemail-webhandler (v_restpath o_webex)
  "_6RtF29C4pij_9r269Lc0d0W", //!emit_xhtml_open°simple_void_html_element_object < o_helem (o_emitctx o_strbuf v_depth)
  "_6STwOZTcBwM_6wz4Akuletb", //!forgotemailsender (o_contrib o_decayemail)
  "_6TYtJU0rl2h_2z4md7DV06z", //!root-web-handler (v_restpath o_webex)
  "_85938GaqS1z_3mZSenKG7GG", //!emit-tagged-id-more-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget v_more] (o_helem o_emitctx o_strbuf v_depth)
  "_8oKFbiPI4JW_7EPg4RP1e4Q", //!emit-raw-tag-xhtml-open [v_tagstr v_restagstr] (o_helem o_emitctx o_strbuf v_depth)
  "_8sdgc5Y7vPU_9Nvj5CtRqaQ", //!doapp-web-handler (v_restpath o_webex)
  "_8IYFtn8osS2_4t1U3wyROLW",//emit_xhtml
  /*16:*/
  "_9hEreAemqXg_0uoN1Fr1ly4", //!emit-tagged-id-xhtml-open [v_htmltag v_htmlclass v_idprefix o_idtarget] (o_helem o_emitctx o_strbuf v_depth)

 NULL}; // end 17 routine ids



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
