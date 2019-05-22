// generated persistent module code_generator_module
// in file modbm_1lhXvXtIyPu_3nhuy4kN3wd.c -- DONT EDIT
// this generated code is GPLv3+ licensed.


#include "bismon.h"

#ifdef BISMON_MODID
DECLARE_MODULE_BM(_1lhXvXtIyPu_3nhuy4kN3wd);
extern moduleinit_sigBM moduleinit_1lhXvXtIyPu_3nhuy4kN3wd_BM;
#endif /*BISMON_MODID*/

#ifdef BISMON_MOMD5
const char modulmd5chksum_1lhXvXtIyPu_3nhuy4kN3wd_BM[] = BISMON_MOMD5;
#endif /*BISMON_MOMD5*/



// declare 5 routines

extern const char *const routid_1lhXvXtIyPu_3nhuy4kN3wd_BM[5+1];


// 20 failures

extern objrout_sigBM crout_08PMymoD6YJ_8rspWoCg4Xu_BM; //#0 !emit_statement°basiclo_outstmt < o_stmt (o_modgen o_routprep v_depth)

extern objrout_sigBM crout_0vCFi47Ctm6_70R5Tci6JuH_BM; //#1 !emit_block°basiclo_for_up_loop  < o_block (o_modgen o_routprep v_depth)

extern objrout_sigBM crout_1kz7viwMzTp_6PgLhdZzMEy_BM; //#2 !miniscan_stmt°basiclo_outstmt < o_stmt (o_routprep v_depth o_from)

extern objrout_sigBM crout_85xjvzYjcd6_9mNZNPF6i2J_BM; //#3 !miniscan_stmt°basiclo_countloop < o_stmt (o_routprep v_depth o_from)

extern objrout_sigBM crout_8NgOdlJACWN_8pbYZXkHpCj_BM; //#4 !emit_block°basiclo_for_down_loop  < o_block (o_modgen o_routprep v_depth)


// declare 65 constants
objectval_tyBM* constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[65+1];
const char* const constid_1lhXvXtIyPu_3nhuy4kN3wd_BM[65+1];


// define 5 routines


value_tyBM crout_08PMymoD6YJ_8rspWoCg4Xu_BM //#0
 (struct stackframe_stBM* stkf, //
//!emit_statement°basiclo_outstmt < o_stmt (o_modgen o_routprep v_depth)
  // 4 arguments
  const value_tyBM arg0,  // o_stmt
  const value_tyBM arg1,  // o_modgen
  const value_tyBM arg2,  // o_routprep
  const value_tyBM arg3,  // v_depth
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _08PMymoD6YJ_8rspWoCg4Xu
  struct frame_08PMymoD6YJ_8rspWoCg4Xu_BMst {
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
    objectval_tyBM* o_2RUj1oyJ2rf_1ICZWr844Sv; // o_modgen
    objectval_tyBM* o_34Qtvf1thwK_9rziG6sk6Vl; // o_stmt
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    value_tyBM v_4Q4WBLjAPTV_5WVLmhAvCJY; // v_arg
    objectval_tyBM* o_68pH0LfBXQ1_9SRMhSZJlQV; // o_varout
    objectval_tyBM* o_6RpSqxAOt2p_35laNqeU6KH; // o_routprep
    value_tyBM v_96vo6uBKhke_6E1vyN3kIKD; // v_expctx
    /// 3 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
   } _;
   memset (&_, 0, sizeof(struct frame_08PMymoD6YJ_8rspWoCg4Xu_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 11;
   _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[0] /*|_08PMymoD6YJ_8rspWoCg4Xu*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 4 arguments:
   _.o_34Qtvf1thwK_9rziG6sk6Vl = objectcast_BM (arg0); // o_stmt
   _.o_2RUj1oyJ2rf_1ICZWr844Sv = objectcast_BM (arg1); // o_modgen
   _.o_6RpSqxAOt2p_35laNqeU6KH = objectcast_BM (arg2); // o_routprep
   _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
   // fetched 4 arguments.
   // no closed values in _08PMymoD6YJ_8rspWoCg4Xu.
   const closure_tyBM* callclos_08PMymoD6YJ_8rspWoCg4Xu __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_08PMymoD6YJ_8rspWoCg4Xu  __attribute__((unused)) = 0;
   // routine _08PMymoD6YJ_8rspWoCg4Xu body:

startblock__2RXF4soNP1G_4lwKnhT9HXn: __attribute__((unused));
{ /* +block _2RXF4soNP1G_4lwKnhT9HXn */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _7qIppSwFGGb_2UJt4H9gKgS  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV = //assign _8snpX2CnOTZ_3s6SIUk6miJ  
/*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[5] /*!out*/)))); 
 
//+ #2/16 of block _2RXF4soNP1G_4lwKnhT9HXn :: 
 
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _4xM35iNaxz2_7KPR8ZEUBBR  
/*objnbcomps:*/ objnbcomps_BM ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl); 
 
 
 
{ // run _1nXXMqpXgYw_8ISpDakhyIi 
/*debug start emit_statement°basiclo_outstmt o_stmt o_modgen o_routprep depth o_varout leni*/
DBGPRINTF_BM("emit_statement°basiclo_outstmt start €%.9s o_stmt=%s o_modgen=%s/L%u o_routprep=%s depth#%ld o_varout=%s leni#%ld",
 "_1nXXMqpXgYw_8ISpDakhyIi",
 objectdbg_BM( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),
 objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
 objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
 objectdbg2_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
 objectdbg3_BM( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV),
 (long int) ( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k));; 
} // end run _1nXXMqpXgYw_8ISpDakhyIi 
 
//+ #4/16 of block _2RXF4soNP1G_4lwKnhT9HXn :: 
 
{ // start cexpansion _8c3f40N9oIJ_2NpErXp5pgD - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "{ // start out "));  
} // end cexpansion _8c3f40N9oIJ_2NpErXp5pgD - objstrbufferappendcstrpayl  
  
 
{ // start cexpansion _0EqgqGcTjMg_0BBJAIABGb2 - objstrbufferprintobject  
/*objstrbufferprintobject _0EqgqGcTjMg_0BBJAIABGb2:*/
 objectval_tyBM* obsbuf_0EqgqGcTjMg_0BBJAIABGb2 = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
 objectval_tyBM* ob_0EqgqGcTjMg_0BBJAIABGb2 = ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);
 if (objhasstrbufferpayl_BM(obsbuf_0EqgqGcTjMg_0BBJAIABGb2) && isobject_BM(ob_0EqgqGcTjMg_0BBJAIABGb2))
  objstrbufferappendcstrpayl_BM(obsbuf_0EqgqGcTjMg_0BBJAIABGb2, objectdbg_BM(ob_0EqgqGcTjMg_0BBJAIABGb2));
// end objstrbufferprintobject _0EqgqGcTjMg_0BBJAIABGb2
;  
} // end cexpansion _0EqgqGcTjMg_0BBJAIABGb2 - objstrbufferprintobject  
  
//+ #6/16 of block _2RXF4soNP1G_4lwKnhT9HXn ::  
 
{ // start cexpansion _3zo9bjbpfF9_3s0ClphWCMz - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " to "));  
} // end cexpansion _3zo9bjbpfF9_3s0ClphWCMz - objstrbufferappendcstrpayl  
  
 
{ // start cexpansion _15Lqqaw1RwE_3WYODjv24bI - objstrbufferprintobject  
/*objstrbufferprintobject _15Lqqaw1RwE_3WYODjv24bI:*/
 objectval_tyBM* obsbuf_15Lqqaw1RwE_3WYODjv24bI = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
 objectval_tyBM* ob_15Lqqaw1RwE_3WYODjv24bI = ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV);
 if (objhasstrbufferpayl_BM(obsbuf_15Lqqaw1RwE_3WYODjv24bI) && isobject_BM(ob_15Lqqaw1RwE_3WYODjv24bI))
  objstrbufferappendcstrpayl_BM(obsbuf_15Lqqaw1RwE_3WYODjv24bI, objectdbg_BM(ob_15Lqqaw1RwE_3WYODjv24bI));
// end objstrbufferprintobject _15Lqqaw1RwE_3WYODjv24bI
;  
} // end cexpansion _15Lqqaw1RwE_3WYODjv24bI - objstrbufferprintobject  
  
//+ #8/16 of block _2RXF4soNP1G_4lwKnhT9HXn ::  
 
{ //for-up _3584humjRT7_5DRf4EbSEPp  
intptr_t cnt_3584humjRT7_5DRf4EbSEPp =  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k;  
for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_3584humjRT7_5DRf4EbSEPp;  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++) {  
// for-up _3584humjRT7_5DRf4EbSEPp #0 :  
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _1anzE3Jqqe6_6LhycgiaIC1   
/*objgetcomp:*/objgetcomp_BM (( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));  
  
// for-up _3584humjRT7_5DRf4EbSEPp #1 :  
  
{ // run _2EhsAjpzrKw_7oYghtMEgPV  
/*debug emit_statement°basiclo_outstmt v_comp ii o_stmt o_modgen*/
 DBGPRINTF_BM("emit_statement°basiclo_outstmt €%.9s v_comp=%s ii#%ld o_stmt=%s o_modgen=%s/L%u",
 "_2EhsAjpzrKw_7oYghtMEgPV",
 OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
 (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
 objectdbg_BM( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),
 objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
 objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv));;  
} // end run _2EhsAjpzrKw_7oYghtMEgPV  
  
// for-up _3584humjRT7_5DRf4EbSEPp #2 :  
{ // start cexpansion _20LtVgnHAm6_4soICKMimrK - objstrbuffersetindentpayl   
/*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));    
} // end cexpansion _20LtVgnHAm6_4soICKMimrK - objstrbuffersetindentpayl    
  
// for-up _3584humjRT7_5DRf4EbSEPp #3 :  
{ // start cexpansion _0ca6ncURG9Y_2Q3UrCgnMPd - objstrbuffernewlinepayl   
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);   
} // end cexpansion _0ca6ncURG9Y_2Q3UrCgnMPd - objstrbuffernewlinepayl   
  
// for-up _3584humjRT7_5DRf4EbSEPp #4 :  
if /*cond _4nOMpL7ofYO_7UI4gpk1cQz*/   
/*when _4OeL63MMdi0_9vl6tIFdfP8:*/  
 (/*isstring:*/isstring_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) { //body when _4OeL63MMdi0_9vl6tIFdfP8   
{ // start cexpansion _5pqvkyAt4zS_4qUOQ9ii7vq - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out literal:*/ objstrbufferappendcstrpayl_BM ("));    
} // end cexpansion _5pqvkyAt4zS_4qUOQ9ii7vq - objstrbufferappendcstrpayl    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var    
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));     
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
{ // start cexpansion _4IWQHWbVUsi_0KTMpVjEt4J - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", \""));    
} // end cexpansion _4IWQHWbVUsi_0KTMpVjEt4J - objstrbufferappendcstrpayl    
{ // start cexpansion _9lwtvhuODYD_7t02oTfRaaW - objstrbufferencvalcpayl    
/*objstrbufferencvalcpayl:*/objstrbufferencodedcpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), 
 bytstring_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), -1);    
} // end cexpansion _9lwtvhuODYD_7t02oTfRaaW - objstrbufferencvalcpayl    
{ // start cexpansion _1MTN8uOGzRk_1x5mYDtTjQS - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "\");"));    
} // end cexpansion _1MTN8uOGzRk_1x5mYDtTjQS - objstrbufferappendcstrpayl    
   
} //endwhen _4OeL63MMdi0_9vl6tIFdfP8   
else if   
/*when _9snNxHFHKej_9go5H2wttwP:*/  
 (/*isnode:*/isnode_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe))) { //body when _9snNxHFHKej_9go5H2wttwP   
 /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81 = //assign _1jCOq9F7UCX_1hgQ2hHtGGN    
/*nodeconn:*/nodeconn_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe);   
   
{ // begin objswitch _88CClQZGP1N_57QoKCh6Ivj   
//!objswitch! objswitch o_conn .. emit_statement°basiclo_outstmt .   
 objectval_tyBM* objswexp_88CClQZGP1N_57QoKCh6Ivj = ( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81);   
 switch (objecthash_BM (objswexp_88CClQZGP1N_57QoKCh6Ivj) % 64) {   
 case 0:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[22] /*|utf8_enc*/)) goto whenobj88CClQZG__3UQkLJVILrN_5fQkMJuOnaO;   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[39] /*|less_indent*/)) goto whenobj88CClQZG__0kARe298u9e_67xDUpdBBUc;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 2:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[56] /*|nlsp*/)) goto whenobj88CClQZG__87vVePujNkG_0JOq1ftTQok;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 5:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[50] /*|c_enc*/)) goto whenobj88CClQZG__5ET8jC0ulFr_8HwUqVh9ORX;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 6:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[19] /*|newline*/)) goto whenobj88CClQZG__9E2lY6UWtZc_1zqNjPXxrB1;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 11:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[57] /*|object*/)) goto whenobj88CClQZG__3EoeNMRpnqL_7axOMOBffnQ;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 15:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[27] /*|html_enc*/)) goto whenobj88CClQZG__6aA6aV2YRMt_1NEYDaXpeC7;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 18:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[18] /*|half_id*/)) goto whenobj88CClQZG__9r5C2b73vHL_1dnbWS5hq8o;   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[32] /*|double_plain*/)) goto whenobj88CClQZG__7JbKDvDLX46_6AdksGCnIrD;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 19:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[10] /*|octa*/)) goto whenobj88CClQZG__1Okz8TmaK4w_1h2DwizxeUm;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 22:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[24] /*|space*/)) goto whenobj88CClQZG__114ixi5SECv_2Q1vNdDZoMs;   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[42] /*|json_indented*/)) goto whenobj88CClQZG__0z4pSxrVvjo_5sHi5Y1pLPY;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 30:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[2] /*|int*/)) goto whenobj88CClQZG__1x34ns9L1vc_0NkwFmpgSZo;   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[4] /*|prefixed_lines*/)) goto whenobj88CClQZG__6ynq7YzdPfg_1NP6KTYRGay;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 31:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[55] /*|value*/)) goto whenobj88CClQZG__1zJdg4pQzkf_3a4FsTJjy8n;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 34:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[59] /*|hexa*/)) goto whenobj88CClQZG__0BVlPuwRd7W_2uZdnPJU4lL;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 36:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[1] /*|more_indent*/)) goto whenobj88CClQZG__7ZmgWpB8hAR_9ZTbneZMSU1;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 41:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[23] /*|local_time*/)) goto whenobj88CClQZG__0ZOcGG4RgXt_4xRCcPIiCqy;   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[40] /*|literal_c_string*/)) goto whenobj88CClQZG__3s1tzo7j8uB_0du3hmckL9U;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 42:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[7] /*|name*/)) goto whenobj88CClQZG__5BIPiYugHNh_27cx9JETCA7;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 47:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[31] /*|json_compact*/)) goto whenobj88CClQZG__4fv6GoqMJ2j_5mL5sYAy1MA;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 51:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[20] /*|set_indent*/)) goto whenobj88CClQZG__7SJ5JXB8NNl_6AbPMP2VS1c;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 54:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[17] /*|double_float*/)) goto whenobj88CClQZG__4l6z1cQM0MF_99OZOIu8g9n;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 55:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[35] /*|string*/)) goto whenobj88CClQZG__9d7rWinZqTW_3HJB0Tm1DtZ;   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[58] /*|id*/)) goto whenobj88CClQZG__0fRhe6eKSxc_717gH1gzxnY;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
   
  default: defobj_88CClQZGP1N_57QoKCh6Ivj:;   
   
 // objswitch _88CClQZGP1N_57QoKCh6Ivj default#0 statement:    
//failure _3hMno2PB1II_6IrKetMkipy     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[0] /*!_08PMymoD6YJ_8rspWoCg4Xu*/)), 
 
( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[25] /*|_3hMno2PB1II_6IrKetMkipy*/)),
                ((struct stackframe_stBM *) &_));
    
break; // end objswitch _88CClQZGP1N_57QoKCh6Ivj default    
// objswitch _88CClQZGP1N_57QoKCh6Ivj with 25 whens:    
    
whenobj88CClQZG__0fRhe6eKSxc_717gH1gzxnY:; // when #0 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #0 statement:    
{ // start cexpansion _0zKnZUvuFlU_5okP2gbCUIH - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out id:*/ char idbuf"));     
} // end cexpansion _0zKnZUvuFlU_5okP2gbCUIH - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #1 statement:    
{ // start cexpansion _7O1a8HkPkwu_2DmU02OwFX3 - objstrbufferprintobjid     
/*objstrbufferprintobjid _7O1a8HkPkwu_2DmU02OwFX3:*/
objectval_tyBM *obsbuf__7O1a8HkPkwu_2DmU02OwFX3 = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
objectval_tyBM *ob__7O1a8HkPkwu_2DmU02OwFX3 = ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);
if (objhasstrbufferpayl_BM(obsbuf__7O1a8HkPkwu_2DmU02OwFX3) && isobject_BM(ob__7O1a8HkPkwu_2DmU02OwFX3)) {
  char idbuf__7O1a8HkPkwu_2DmU02OwFX3 [32];
 memset (idbuf__7O1a8HkPkwu_2DmU02OwFX3, 0, sizeof(idbuf__7O1a8HkPkwu_2DmU02OwFX3));
 idtocbuf32_BM (objid_BM (ob__7O1a8HkPkwu_2DmU02OwFX3), idbuf__7O1a8HkPkwu_2DmU02OwFX3);
 objstrbufferappendcstrpayl_BM(obsbuf__7O1a8HkPkwu_2DmU02OwFX3, idbuf__7O1a8HkPkwu_2DmU02OwFX3);
};
// end objstrbufferprintobjid _7O1a8HkPkwu_2DmU02OwFX3
;     
} // end cexpansion _7O1a8HkPkwu_2DmU02OwFX3 - objstrbufferprintobjid     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #2 statement:    
{ // start cexpansion _5plJt7DVZpn_0n7pcOxdarb - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "_n"));     
} // end cexpansion _5plJt7DVZpn_0n7pcOxdarb - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #3 statement:    
{ // start cexpansion _4h9yvmB4ieF_7JRJFLhvJG3 - objstrbufferprintint     
/*objstrbufferprintint:*/if (objhasstrbufferpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv)) {
 char buf_4h9yvmB4ieF_7JRJFLhvJG3[32]; 
 memset (buf_4h9yvmB4ieF_7JRJFLhvJG3, 0, sizeof(buf_4h9yvmB4ieF_7JRJFLhvJG3));
 snprintf(buf_4h9yvmB4ieF_7JRJFLhvJG3, sizeof(buf_4h9yvmB4ieF_7JRJFLhvJG3), "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
 objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), buf_4h9yvmB4ieF_7JRJFLhvJG3);
} //end objstrbufferprintint _4h9yvmB4ieF_7JRJFLhvJG3
;     
} // end cexpansion _4h9yvmB4ieF_7JRJFLhvJG3 - objstrbufferprintint     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #4 statement:    
{ // start cexpansion _7vLMy8bPNE3_2qd7oURm8L2 - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "[32]={0};"));     
} // end cexpansion _7vLMy8bPNE3_2qd7oURm8L2 - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #5 statement:    
{ // start cexpansion _6amT3YRmLU6_0TKFKJ5FILi - objstrbuffernewlinepayl     
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);     
} // end cexpansion _6amT3YRmLU6_0TKFKJ5FILi - objstrbuffernewlinepayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #6 statement:    
{ // start cexpansion _39vto2jXSds_1XdPjo0Amkd - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "idtocbuf32_BM (objid_BM("));     
} // end cexpansion _39vto2jXSds_1XdPjo0Amkd - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #7 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #8 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #9 statement:    
{ // start cexpansion _0MonCV0Az8f_2rBRV72dJJz - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "), idbuf"));     
} // end cexpansion _0MonCV0Az8f_2rBRV72dJJz - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #10 statement:    
{ // start cexpansion _5TRr3zS3FxR_8vswQ44kQaj - objstrbufferprintobjid     
/*objstrbufferprintobjid _5TRr3zS3FxR_8vswQ44kQaj:*/
objectval_tyBM *obsbuf__5TRr3zS3FxR_8vswQ44kQaj = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
objectval_tyBM *ob__5TRr3zS3FxR_8vswQ44kQaj = ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);
if (objhasstrbufferpayl_BM(obsbuf__5TRr3zS3FxR_8vswQ44kQaj) && isobject_BM(ob__5TRr3zS3FxR_8vswQ44kQaj)) {
  char idbuf__5TRr3zS3FxR_8vswQ44kQaj [32];
 memset (idbuf__5TRr3zS3FxR_8vswQ44kQaj, 0, sizeof(idbuf__5TRr3zS3FxR_8vswQ44kQaj));
 idtocbuf32_BM (objid_BM (ob__5TRr3zS3FxR_8vswQ44kQaj), idbuf__5TRr3zS3FxR_8vswQ44kQaj);
 objstrbufferappendcstrpayl_BM(obsbuf__5TRr3zS3FxR_8vswQ44kQaj, idbuf__5TRr3zS3FxR_8vswQ44kQaj);
};
// end objstrbufferprintobjid _5TRr3zS3FxR_8vswQ44kQaj
;     
} // end cexpansion _5TRr3zS3FxR_8vswQ44kQaj - objstrbufferprintobjid     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #11 statement:    
{ // start cexpansion _9Dsiwu9HSkE_5pX9EvKmSxK - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "_n"));     
} // end cexpansion _9Dsiwu9HSkE_5pX9EvKmSxK - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #12 statement:    
{ // start cexpansion _3wD29vlN70k_7xekhtrZYmH - objstrbufferprintint     
/*objstrbufferprintint:*/if (objhasstrbufferpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv)) {
 char buf_3wD29vlN70k_7xekhtrZYmH[32]; 
 memset (buf_3wD29vlN70k_7xekhtrZYmH, 0, sizeof(buf_3wD29vlN70k_7xekhtrZYmH));
 snprintf(buf_3wD29vlN70k_7xekhtrZYmH, sizeof(buf_3wD29vlN70k_7xekhtrZYmH), "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
 objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), buf_3wD29vlN70k_7xekhtrZYmH);
} //end objstrbufferprintint _3wD29vlN70k_7xekhtrZYmH
;     
} // end cexpansion _3wD29vlN70k_7xekhtrZYmH - objstrbufferprintint     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #13 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #14 statement:    
{ // start cexpansion _9awyi1AxUBB_6rpdX1tcR4h - objstrbuffernewlinepayl     
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);     
} // end cexpansion _9awyi1AxUBB_6rpdX1tcR4h - objstrbuffernewlinepayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #15 statement:    
{ // start cexpansion _88sQAzm7Hff_3y6DR1EQBqT - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "objstrbufferappendcstrpayl_BM ("));     
} // end cexpansion _88sQAzm7Hff_3y6DR1EQBqT - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #16 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #17 statement:    
{ // start cexpansion _6qgE1Z1OLuR_5RbYdfDOWgx - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", idbuf"));     
} // end cexpansion _6qgE1Z1OLuR_5RbYdfDOWgx - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #18 statement:    
{ // start cexpansion _7PqxrFwaRKk_0McIex9mtVH - objstrbufferprintobjid     
/*objstrbufferprintobjid _7PqxrFwaRKk_0McIex9mtVH:*/
objectval_tyBM *obsbuf__7PqxrFwaRKk_0McIex9mtVH = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
objectval_tyBM *ob__7PqxrFwaRKk_0McIex9mtVH = ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);
if (objhasstrbufferpayl_BM(obsbuf__7PqxrFwaRKk_0McIex9mtVH) && isobject_BM(ob__7PqxrFwaRKk_0McIex9mtVH)) {
  char idbuf__7PqxrFwaRKk_0McIex9mtVH [32];
 memset (idbuf__7PqxrFwaRKk_0McIex9mtVH, 0, sizeof(idbuf__7PqxrFwaRKk_0McIex9mtVH));
 idtocbuf32_BM (objid_BM (ob__7PqxrFwaRKk_0McIex9mtVH), idbuf__7PqxrFwaRKk_0McIex9mtVH);
 objstrbufferappendcstrpayl_BM(obsbuf__7PqxrFwaRKk_0McIex9mtVH, idbuf__7PqxrFwaRKk_0McIex9mtVH);
};
// end objstrbufferprintobjid _7PqxrFwaRKk_0McIex9mtVH
;     
} // end cexpansion _7PqxrFwaRKk_0McIex9mtVH - objstrbufferprintobjid     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #19 statement:    
{ // start cexpansion _8BHbQc7VIDi_6l9uywyF08i - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "_n"));     
} // end cexpansion _8BHbQc7VIDi_6l9uywyF08i - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #20 statement:    
{ // start cexpansion _8HZgeYRcjX6_46BfRf4vkk4 - objstrbufferprintint     
/*objstrbufferprintint:*/if (objhasstrbufferpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv)) {
 char buf_8HZgeYRcjX6_46BfRf4vkk4[32]; 
 memset (buf_8HZgeYRcjX6_46BfRf4vkk4, 0, sizeof(buf_8HZgeYRcjX6_46BfRf4vkk4));
 snprintf(buf_8HZgeYRcjX6_46BfRf4vkk4, sizeof(buf_8HZgeYRcjX6_46BfRf4vkk4), "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
 objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), buf_8HZgeYRcjX6_46BfRf4vkk4);
} //end objstrbufferprintint _8HZgeYRcjX6_46BfRf4vkk4
;     
} // end cexpansion _8HZgeYRcjX6_46BfRf4vkk4 - objstrbufferprintint     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #21 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _0fRhe6eKSxc_717gH1gzxnY #0 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__0kARe298u9e_67xDUpdBBUc:; // when #1 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0kARe298u9e_67xDUpdBBUc #0 statement:    
{ // start cexpansion _3dGPVpTiurT_56WuV3rTn2V - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out less_indent:*/ objstrbufferlessindentpayl_BM ("));     
} // end cexpansion _3dGPVpTiurT_56WuV3rTn2V - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0kARe298u9e_67xDUpdBBUc #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0kARe298u9e_67xDUpdBBUc #2 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _0kARe298u9e_67xDUpdBBUc #1 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__0z4pSxrVvjo_5sHi5Y1pLPY:; // when #2 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0z4pSxrVvjo_5sHi5Y1pLPY #0 statement:    
{ // start cexpansion _5EhDjG9YW4s_69w0DX91fbr - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out json_indented:*/ objstrbufferoutputjsonindentedvaluepayl_BM\n ("));     
} // end cexpansion _5EhDjG9YW4s_69w0DX91fbr - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0z4pSxrVvjo_5sHi5Y1pLPY #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0z4pSxrVvjo_5sHi5Y1pLPY #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0z4pSxrVvjo_5sHi5Y1pLPY #3 statement:    
 /*v_expctx:*/_.v_96vo6uBKhke_6E1vyN3kIKD = //assign _6oZEzVBmSDO_3aT8VEOtLuL     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 1));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0z4pSxrVvjo_5sHi5Y1pLPY #4 statement:    
{ // start cexpansion _3jUYZjxeQEu_0VEUs1jwV0g - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", ("));     
} // end cexpansion _3jUYZjxeQEu_0VEUs1jwV0g - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0z4pSxrVvjo_5sHi5Y1pLPY #5 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0z4pSxrVvjo_5sHi5Y1pLPY #6 statement:    
{ // start cexpansion _56nRoV0ayU1_2mHr757EZze - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "), "));     
} // end cexpansion _56nRoV0ayU1_2mHr757EZze - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0z4pSxrVvjo_5sHi5Y1pLPY #7 statement:    
if /*cond _4gQhnk40o3L_8bQpaOIGGME*/     
/*when _4HOkXA3muiK_7Huv8OmP5f8:*/    
 ( /*v_expctx:*/_.v_96vo6uBKhke_6E1vyN3kIKD) { //body when _4HOkXA3muiK_7Huv8OmP5f8     
{ // start cexpansion _7C0QRz3WhO0_6jEBkIOjtqM - objstrbufferappendcstrpayl      
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " ("));      
} // end cexpansion _7C0QRz3WhO0_6jEBkIOjtqM - objstrbufferappendcstrpayl      
{ // start cexpansion _6Dt0zHQ4v7x_5po6RQnOh2u - miniemit_expression      
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_expctx:*/_.v_96vo6uBKhke_6E1vyN3kIKD), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));       
} // end cexpansion _6Dt0zHQ4v7x_5po6RQnOh2u - miniemit_expression       
{ // start cexpansion _56nRoV0ayU1_2mHr757EZze - objstrbufferappendcstrpayl      
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "), "));      
} // end cexpansion _56nRoV0ayU1_2mHr757EZze - objstrbufferappendcstrpayl      
     
} //endwhen _4HOkXA3muiK_7Huv8OmP5f8     
else { /*cond else _4gQhnk40o3L_8bQpaOIGGME*/     
{ // start cexpansion _6j2UwMz66NM_9H0arT8ZnoK - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*no outctx json*/NULL,"));     
} // end cexpansion _6j2UwMz66NM_9H0arT8ZnoK - objstrbufferappendcstrpayl     
} /*cond else _4gQhnk40o3L_8bQpaOIGGME*/     
/*endcond _4gQhnk40o3L_8bQpaOIGGME*/    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0z4pSxrVvjo_5sHi5Y1pLPY #8 statement:    
{ // start cexpansion _8xKcG5ujBdQ_8JfhWpEJkqn - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " CURFRAME_BM);"));     
} // end cexpansion _8xKcG5ujBdQ_8JfhWpEJkqn - objstrbufferappendcstrpayl     
    
    
break; // end when _0z4pSxrVvjo_5sHi5Y1pLPY #2 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__0BVlPuwRd7W_2uZdnPJU4lL:; // when #3 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0BVlPuwRd7W_2uZdnPJU4lL #0 statement:    
{ // start cexpansion _74YOQyHb4Nd_7FicacoZZan - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out hexa:*/ objstrbufferprintfpayl_BM ("));     
} // end cexpansion _74YOQyHb4Nd_7FicacoZZan - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0BVlPuwRd7W_2uZdnPJU4lL #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0BVlPuwRd7W_2uZdnPJU4lL #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0BVlPuwRd7W_2uZdnPJU4lL #3 statement:    
{ // start cexpansion _0APoeium6EX_1BVXu0HmWIQ - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", \"%llx\", (long long) "));     
} // end cexpansion _0APoeium6EX_1BVXu0HmWIQ - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0BVlPuwRd7W_2uZdnPJU4lL #4 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0BVlPuwRd7W_2uZdnPJU4lL #5 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _0BVlPuwRd7W_2uZdnPJU4lL #3 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__0ZOcGG4RgXt_4xRCcPIiCqy:; // when #4 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0ZOcGG4RgXt_4xRCcPIiCqy #0 statement:    
{ // start cexpansion _5ZRPfyn9MY8_2i1glfVxaCL - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out local_time:*/objstrbufferencodelocaltimepayl_BM(("));     
} // end cexpansion _5ZRPfyn9MY8_2i1glfVxaCL - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0ZOcGG4RgXt_4xRCcPIiCqy #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0ZOcGG4RgXt_4xRCcPIiCqy #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0ZOcGG4RgXt_4xRCcPIiCqy #3 statement:    
{ // start cexpansion _8kTCqAbHYLm_4c21TsrClwG - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "), "));     
} // end cexpansion _8kTCqAbHYLm_4c21TsrClwG - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0ZOcGG4RgXt_4xRCcPIiCqy #4 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _0ZOcGG4RgXt_4xRCcPIiCqy #5 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _0ZOcGG4RgXt_4xRCcPIiCqy #4 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__114ixi5SECv_2Q1vNdDZoMs:; // when #5 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _114ixi5SECv_2Q1vNdDZoMs #0 statement:    
{ // start cexpansion _0xL7VGIpR2r_1vJiJ88GK3r - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out space:*/ objstrbufferappendcstrpayl_BM ("));     
} // end cexpansion _0xL7VGIpR2r_1vJiJ88GK3r - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _114ixi5SECv_2Q1vNdDZoMs #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _114ixi5SECv_2Q1vNdDZoMs #2 statement:    
{ // start cexpansion _7seosCpGZ8h_0P1JbrQ4QNK - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", \" \");"));     
} // end cexpansion _7seosCpGZ8h_0P1JbrQ4QNK - objstrbufferappendcstrpayl     
    
    
break; // end when _114ixi5SECv_2Q1vNdDZoMs #5 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__1x34ns9L1vc_0NkwFmpgSZo:; // when #6 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1x34ns9L1vc_0NkwFmpgSZo #0 statement:    
{ // start cexpansion _9VCJIJGsAvX_1529ZKGJAO4 - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out int:*/ objstrbufferprintfpayl_BM ("));     
} // end cexpansion _9VCJIJGsAvX_1529ZKGJAO4 - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1x34ns9L1vc_0NkwFmpgSZo #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1x34ns9L1vc_0NkwFmpgSZo #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1x34ns9L1vc_0NkwFmpgSZo #3 statement:    
{ // start cexpansion _8VsFpTwtckK_3bDjtkhIoU7 - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", \"%lld\", (long long) "));     
} // end cexpansion _8VsFpTwtckK_3bDjtkhIoU7 - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1x34ns9L1vc_0NkwFmpgSZo #4 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1x34ns9L1vc_0NkwFmpgSZo #5 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _1x34ns9L1vc_0NkwFmpgSZo #6 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__1zJdg4pQzkf_3a4FsTJjy8n:; // when #7 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1zJdg4pQzkf_3a4FsTJjy8n #0 statement:    
{ // start cexpansion _81o0x9Oe3Ja_5HLdL6RBIpJ - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out value:*/ objstrbufferappendcstrpayl_BM ("));     
} // end cexpansion _81o0x9Oe3Ja_5HLdL6RBIpJ - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1zJdg4pQzkf_3a4FsTJjy8n #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1zJdg4pQzkf_3a4FsTJjy8n #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1zJdg4pQzkf_3a4FsTJjy8n #3 statement:    
{ // start cexpansion _5reMpeYmKml_13RfKNLG91N - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", OUTSTRVALUE_BM ("));     
} // end cexpansion _5reMpeYmKml_13RfKNLG91N - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1zJdg4pQzkf_3a4FsTJjy8n #4 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1zJdg4pQzkf_3a4FsTJjy8n #5 statement:    
{ // start cexpansion _2dvWAKMXgbg_7Elpq2AoBIo - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "));"));     
} // end cexpansion _2dvWAKMXgbg_7Elpq2AoBIo - objstrbufferappendcstrpayl     
    
    
break; // end when _1zJdg4pQzkf_3a4FsTJjy8n #7 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__1Okz8TmaK4w_1h2DwizxeUm:; // when #8 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1Okz8TmaK4w_1h2DwizxeUm #0 statement:    
{ // start cexpansion _3XwncgqEs5D_9Ht74luwrmx - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out octa:*/ objstrbufferprintfpayl_BM ("));     
} // end cexpansion _3XwncgqEs5D_9Ht74luwrmx - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1Okz8TmaK4w_1h2DwizxeUm #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1Okz8TmaK4w_1h2DwizxeUm #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1Okz8TmaK4w_1h2DwizxeUm #3 statement:    
{ // start cexpansion _0zmQelH00Up_6fR1xIGtzy0 - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", \"%llo\", (long long) "));     
} // end cexpansion _0zmQelH00Up_6fR1xIGtzy0 - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1Okz8TmaK4w_1h2DwizxeUm #4 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _1Okz8TmaK4w_1h2DwizxeUm #5 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _1Okz8TmaK4w_1h2DwizxeUm #8 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__3s1tzo7j8uB_0du3hmckL9U:; // when #9 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3s1tzo7j8uB_0du3hmckL9U #0 statement:    
{ // start cexpansion _9vR2Fv4CLhC_12QZ3haFfpt - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out literal_c_string:*/ objstrbufferliteralcstringpayl_BM ("));     
} // end cexpansion _9vR2Fv4CLhC_12QZ3haFfpt - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3s1tzo7j8uB_0du3hmckL9U #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3s1tzo7j8uB_0du3hmckL9U #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3s1tzo7j8uB_0du3hmckL9U #3 statement:    
{ // start cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));     
} // end cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3s1tzo7j8uB_0du3hmckL9U #4 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3s1tzo7j8uB_0du3hmckL9U #5 statement:    
{ // start cexpansion _0xTYoGypzrv_9WaOYz6kK8x - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", -1"));     
} // end cexpansion _0xTYoGypzrv_9WaOYz6kK8x - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3s1tzo7j8uB_0du3hmckL9U #6 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _3s1tzo7j8uB_0du3hmckL9U #9 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__3EoeNMRpnqL_7axOMOBffnQ:; // when #10 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3EoeNMRpnqL_7axOMOBffnQ #0 statement:    
{ // start cexpansion _2hyA1E4kwkD_4gm3vaEYWhp - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out object:*/ objstrbufferappendcstrpayl_BM ("));     
} // end cexpansion _2hyA1E4kwkD_4gm3vaEYWhp - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3EoeNMRpnqL_7axOMOBffnQ #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3EoeNMRpnqL_7axOMOBffnQ #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3EoeNMRpnqL_7axOMOBffnQ #3 statement:    
{ // start cexpansion _6arx4mZK5LK_8usC9XqgLg5 - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", objectdbg_BM ("));     
} // end cexpansion _6arx4mZK5LK_8usC9XqgLg5 - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3EoeNMRpnqL_7axOMOBffnQ #4 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3EoeNMRpnqL_7axOMOBffnQ #5 statement:    
{ // start cexpansion _9SmJNBQeMc1_43sJXOwBGe4 - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "));"));     
} // end cexpansion _9SmJNBQeMc1_43sJXOwBGe4 - objstrbufferappendcstrpayl     
    
    
break; // end when _3EoeNMRpnqL_7axOMOBffnQ #10 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__3UQkLJVILrN_5fQkMJuOnaO:; // when #11 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3UQkLJVILrN_5fQkMJuOnaO #0 statement:    
{ // start cexpansion _4LgbVp40GWp_7QqWs5tViuk - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out utf8_enc:*/ objstrbufferencodedutf8payl_BM ("));     
} // end cexpansion _4LgbVp40GWp_7QqWs5tViuk - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3UQkLJVILrN_5fQkMJuOnaO #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3UQkLJVILrN_5fQkMJuOnaO #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3UQkLJVILrN_5fQkMJuOnaO #3 statement:    
{ // start cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));     
} // end cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3UQkLJVILrN_5fQkMJuOnaO #4 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3UQkLJVILrN_5fQkMJuOnaO #5 statement:    
{ // start cexpansion _0xTYoGypzrv_9WaOYz6kK8x - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", -1"));     
} // end cexpansion _0xTYoGypzrv_9WaOYz6kK8x - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _3UQkLJVILrN_5fQkMJuOnaO #6 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _3UQkLJVILrN_5fQkMJuOnaO #11 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__4fv6GoqMJ2j_5mL5sYAy1MA:; // when #12 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _4fv6GoqMJ2j_5mL5sYAy1MA #0 statement:    
{ // start cexpansion _5jjZtFPH22M_4PdvtvwmHYi - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out json_compact:*/ objstrbufferoutputjsoncompactedvaluepayl_BM\n ("));     
} // end cexpansion _5jjZtFPH22M_4PdvtvwmHYi - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _4fv6GoqMJ2j_5mL5sYAy1MA #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _4fv6GoqMJ2j_5mL5sYAy1MA #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _4fv6GoqMJ2j_5mL5sYAy1MA #3 statement:    
 /*v_expctx:*/_.v_96vo6uBKhke_6E1vyN3kIKD = //assign _6oZEzVBmSDO_3aT8VEOtLuL     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 1));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _4fv6GoqMJ2j_5mL5sYAy1MA #4 statement:    
{ // start cexpansion _3jUYZjxeQEu_0VEUs1jwV0g - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", ("));     
} // end cexpansion _3jUYZjxeQEu_0VEUs1jwV0g - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _4fv6GoqMJ2j_5mL5sYAy1MA #5 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _4fv6GoqMJ2j_5mL5sYAy1MA #6 statement:    
{ // start cexpansion _56nRoV0ayU1_2mHr757EZze - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "), "));     
} // end cexpansion _56nRoV0ayU1_2mHr757EZze - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _4fv6GoqMJ2j_5mL5sYAy1MA #7 statement:    
if /*cond _4gQhnk40o3L_8bQpaOIGGME*/     
/*when _4HOkXA3muiK_7Huv8OmP5f8:*/    
 ( /*v_expctx:*/_.v_96vo6uBKhke_6E1vyN3kIKD) { //body when _4HOkXA3muiK_7Huv8OmP5f8     
{ // start cexpansion _7C0QRz3WhO0_6jEBkIOjtqM - objstrbufferappendcstrpayl      
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " ("));      
} // end cexpansion _7C0QRz3WhO0_6jEBkIOjtqM - objstrbufferappendcstrpayl      
{ // start cexpansion _6Dt0zHQ4v7x_5po6RQnOh2u - miniemit_expression      
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_expctx:*/_.v_96vo6uBKhke_6E1vyN3kIKD), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));       
} // end cexpansion _6Dt0zHQ4v7x_5po6RQnOh2u - miniemit_expression       
{ // start cexpansion _56nRoV0ayU1_2mHr757EZze - objstrbufferappendcstrpayl      
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "), "));      
} // end cexpansion _56nRoV0ayU1_2mHr757EZze - objstrbufferappendcstrpayl      
     
} //endwhen _4HOkXA3muiK_7Huv8OmP5f8     
else { /*cond else _4gQhnk40o3L_8bQpaOIGGME*/     
{ // start cexpansion _6j2UwMz66NM_9H0arT8ZnoK - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*no outctx json*/NULL,"));     
} // end cexpansion _6j2UwMz66NM_9H0arT8ZnoK - objstrbufferappendcstrpayl     
} /*cond else _4gQhnk40o3L_8bQpaOIGGME*/     
/*endcond _4gQhnk40o3L_8bQpaOIGGME*/    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _4fv6GoqMJ2j_5mL5sYAy1MA #8 statement:    
{ // start cexpansion _8xKcG5ujBdQ_8JfhWpEJkqn - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " CURFRAME_BM);"));     
} // end cexpansion _8xKcG5ujBdQ_8JfhWpEJkqn - objstrbufferappendcstrpayl     
    
    
break; // end when _4fv6GoqMJ2j_5mL5sYAy1MA #12 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__4l6z1cQM0MF_99OZOIu8g9n:; // when #13 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _4l6z1cQM0MF_99OZOIu8g9n #0 statement:    
{ // start cexpansion _3PJ0ZiTpF6M_4qFzUpO9Y8w - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out double_float:*/(void) objstrbufferoutdoublepayl_BM("));     
} // end cexpansion _3PJ0ZiTpF6M_4qFzUpO9Y8w - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _4l6z1cQM0MF_99OZOIu8g9n #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _4l6z1cQM0MF_99OZOIu8g9n #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _4l6z1cQM0MF_99OZOIu8g9n #3 statement:    
{ // start cexpansion _3pcbCfZccyh_2fRLzjL6lQj - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));     
} // end cexpansion _3pcbCfZccyh_2fRLzjL6lQj - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _4l6z1cQM0MF_99OZOIu8g9n #4 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _4l6z1cQM0MF_99OZOIu8g9n #5 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _4l6z1cQM0MF_99OZOIu8g9n #13 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__5BIPiYugHNh_27cx9JETCA7:; // when #14 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _5BIPiYugHNh_27cx9JETCA7 #0 statement:    
{ // start cexpansion _9d3lEURT0ug_7LCapWY9hBT - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out name:*/ objstrbufferappendcstrpayl_BM ("));     
} // end cexpansion _9d3lEURT0ug_7LCapWY9hBT - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _5BIPiYugHNh_27cx9JETCA7 #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _5BIPiYugHNh_27cx9JETCA7 #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _5BIPiYugHNh_27cx9JETCA7 #3 statement:    
{ // start cexpansion _4d466jMJhQd_4FWABdphr9y - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", findobjectname_BM ("));     
} // end cexpansion _4d466jMJhQd_4FWABdphr9y - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _5BIPiYugHNh_27cx9JETCA7 #4 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _5BIPiYugHNh_27cx9JETCA7 #5 statement:    
{ // start cexpansion _44lPnWohZT3_4XBFP6of9h7 - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "));"));     
} // end cexpansion _44lPnWohZT3_4XBFP6of9h7 - objstrbufferappendcstrpayl     
    
    
break; // end when _5BIPiYugHNh_27cx9JETCA7 #14 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__5ET8jC0ulFr_8HwUqVh9ORX:; // when #15 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _5ET8jC0ulFr_8HwUqVh9ORX #0 statement:    
{ // start cexpansion _1ILRF99oJKp_9uh1JVhh4Ir - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out c_enc:*/ objstrbufferencodedcpayl_BM ("));     
} // end cexpansion _1ILRF99oJKp_9uh1JVhh4Ir - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _5ET8jC0ulFr_8HwUqVh9ORX #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _5ET8jC0ulFr_8HwUqVh9ORX #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _5ET8jC0ulFr_8HwUqVh9ORX #3 statement:    
{ // start cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));     
} // end cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _5ET8jC0ulFr_8HwUqVh9ORX #4 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _5ET8jC0ulFr_8HwUqVh9ORX #5 statement:    
{ // start cexpansion _0xTYoGypzrv_9WaOYz6kK8x - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", -1"));     
} // end cexpansion _0xTYoGypzrv_9WaOYz6kK8x - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _5ET8jC0ulFr_8HwUqVh9ORX #6 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _5ET8jC0ulFr_8HwUqVh9ORX #15 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__6aA6aV2YRMt_1NEYDaXpeC7:; // when #16 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _6aA6aV2YRMt_1NEYDaXpeC7 #0 statement:    
{ // start cexpansion _3vqzjGxC2GM_2m5r0xbbxBS - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out html_enc:*/ objstrbufferencodedhtmlpayl_BM ("));     
} // end cexpansion _3vqzjGxC2GM_2m5r0xbbxBS - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _6aA6aV2YRMt_1NEYDaXpeC7 #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _6aA6aV2YRMt_1NEYDaXpeC7 #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _6aA6aV2YRMt_1NEYDaXpeC7 #3 statement:    
{ // start cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));     
} // end cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _6aA6aV2YRMt_1NEYDaXpeC7 #4 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _6aA6aV2YRMt_1NEYDaXpeC7 #5 statement:    
{ // start cexpansion _0xTYoGypzrv_9WaOYz6kK8x - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", -1"));     
} // end cexpansion _0xTYoGypzrv_9WaOYz6kK8x - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _6aA6aV2YRMt_1NEYDaXpeC7 #6 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _6aA6aV2YRMt_1NEYDaXpeC7 #16 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__6ynq7YzdPfg_1NP6KTYRGay:; // when #17 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #0 statement:    
{ // start cexpansion _7tRdjZA1xGU_66rNHqMnoVh - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out prefixed_lines:*/objstrbufferoutputprefixlinespayl_BM ("));     
} // end cexpansion _7tRdjZA1xGU_66rNHqMnoVh - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #3 statement:    
{ // start cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));     
} // end cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #4 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #5 statement:    
{ // start cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));     
} // end cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #6 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _6P24oZ9lBmf_6uQcEYnne94     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 1));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #7 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #8 statement:    
{ // start cexpansion _9QlMhbIzTEX_20hleVtDJyt - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _9QlMhbIzTEX_20hleVtDJyt - objstrbufferappendcstrpayl     
    
    
break; // end when _6ynq7YzdPfg_1NP6KTYRGay #17 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__7JbKDvDLX46_6AdksGCnIrD:; // when #18 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _7JbKDvDLX46_6AdksGCnIrD #0 statement:    
{ // start cexpansion _1hAp5OxsRGD_92R3L2BJtlG - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out double_plain:*/ objstrbufferprintfpayl_BM("));     
} // end cexpansion _1hAp5OxsRGD_92R3L2BJtlG - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _7JbKDvDLX46_6AdksGCnIrD #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _7JbKDvDLX46_6AdksGCnIrD #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _7JbKDvDLX46_6AdksGCnIrD #3 statement:    
{ // start cexpansion _6e4LRuNu6ll_7OjJblfFR8d - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", \"%g\", "));     
} // end cexpansion _6e4LRuNu6ll_7OjJblfFR8d - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _7JbKDvDLX46_6AdksGCnIrD #4 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _7JbKDvDLX46_6AdksGCnIrD #5 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _7JbKDvDLX46_6AdksGCnIrD #18 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__7SJ5JXB8NNl_6AbPMP2VS1c:; // when #19 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _7SJ5JXB8NNl_6AbPMP2VS1c #0 statement:    
{ // start cexpansion _0255NhyJ7Dq_2SDnpSnNtCD - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out set_indent:*/ objstrbuffersetindentpayl_BM ("));     
} // end cexpansion _0255NhyJ7Dq_2SDnpSnNtCD - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _7SJ5JXB8NNl_6AbPMP2VS1c #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _7SJ5JXB8NNl_6AbPMP2VS1c #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _7SJ5JXB8NNl_6AbPMP2VS1c #3 statement:    
{ // start cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));     
} // end cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _7SJ5JXB8NNl_6AbPMP2VS1c #4 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _7SJ5JXB8NNl_6AbPMP2VS1c #5 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _7SJ5JXB8NNl_6AbPMP2VS1c #19 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__7ZmgWpB8hAR_9ZTbneZMSU1:; // when #20 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _7ZmgWpB8hAR_9ZTbneZMSU1 #0 statement:    
{ // start cexpansion _2aoeNtEqRs3_3YZD8N5RQ3h - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out more_indent:*/ objstrbuffermoreindentpayl_BM ("));     
} // end cexpansion _2aoeNtEqRs3_3YZD8N5RQ3h - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _7ZmgWpB8hAR_9ZTbneZMSU1 #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _7ZmgWpB8hAR_9ZTbneZMSU1 #2 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _7ZmgWpB8hAR_9ZTbneZMSU1 #20 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__87vVePujNkG_0JOq1ftTQok:; // when #21 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _87vVePujNkG_0JOq1ftTQok #0 statement:    
{ // start cexpansion _1zDV3OgdBWQ_7fM8urCKgoi - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ("));     
} // end cexpansion _1zDV3OgdBWQ_7fM8urCKgoi - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _87vVePujNkG_0JOq1ftTQok #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _87vVePujNkG_0JOq1ftTQok #2 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _87vVePujNkG_0JOq1ftTQok #21 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__9d7rWinZqTW_3HJB0Tm1DtZ:; // when #22 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9d7rWinZqTW_3HJB0Tm1DtZ #0 statement:    
{ // start cexpansion _4iBLhIFQ0RT_6uR07KGUqiB - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out string:*/ objstrbufferappendcstrpayl_BM ("));     
} // end cexpansion _4iBLhIFQ0RT_6uR07KGUqiB - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9d7rWinZqTW_3HJB0Tm1DtZ #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9d7rWinZqTW_3HJB0Tm1DtZ #2 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9d7rWinZqTW_3HJB0Tm1DtZ #3 statement:    
{ // start cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));     
} // end cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9d7rWinZqTW_3HJB0Tm1DtZ #4 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9d7rWinZqTW_3HJB0Tm1DtZ #5 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _9d7rWinZqTW_3HJB0Tm1DtZ #22 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__9r5C2b73vHL_1dnbWS5hq8o:; // when #23 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #0 statement:    
{ // start out _5VxRkdpRDpG_4sfwsfc5lRZ to o_modgen     
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "/*out_half_id:*/ char idbuf");    
} // end out _5VxRkdpRDpG_4sfwsfc5lRZ    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #1 statement:    
{ // start cexpansion _7O1a8HkPkwu_2DmU02OwFX3 - objstrbufferprintobjid     
/*objstrbufferprintobjid _7O1a8HkPkwu_2DmU02OwFX3:*/
objectval_tyBM *obsbuf__7O1a8HkPkwu_2DmU02OwFX3 = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
objectval_tyBM *ob__7O1a8HkPkwu_2DmU02OwFX3 = ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);
if (objhasstrbufferpayl_BM(obsbuf__7O1a8HkPkwu_2DmU02OwFX3) && isobject_BM(ob__7O1a8HkPkwu_2DmU02OwFX3)) {
  char idbuf__7O1a8HkPkwu_2DmU02OwFX3 [32];
 memset (idbuf__7O1a8HkPkwu_2DmU02OwFX3, 0, sizeof(idbuf__7O1a8HkPkwu_2DmU02OwFX3));
 idtocbuf32_BM (objid_BM (ob__7O1a8HkPkwu_2DmU02OwFX3), idbuf__7O1a8HkPkwu_2DmU02OwFX3);
 objstrbufferappendcstrpayl_BM(obsbuf__7O1a8HkPkwu_2DmU02OwFX3, idbuf__7O1a8HkPkwu_2DmU02OwFX3);
};
// end objstrbufferprintobjid _7O1a8HkPkwu_2DmU02OwFX3
;     
} // end cexpansion _7O1a8HkPkwu_2DmU02OwFX3 - objstrbufferprintobjid     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #2 statement:    
{ // start cexpansion _5plJt7DVZpn_0n7pcOxdarb - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "_n"));     
} // end cexpansion _5plJt7DVZpn_0n7pcOxdarb - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #3 statement:    
{ // start cexpansion _4h9yvmB4ieF_7JRJFLhvJG3 - objstrbufferprintint     
/*objstrbufferprintint:*/if (objhasstrbufferpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv)) {
 char buf_4h9yvmB4ieF_7JRJFLhvJG3[32]; 
 memset (buf_4h9yvmB4ieF_7JRJFLhvJG3, 0, sizeof(buf_4h9yvmB4ieF_7JRJFLhvJG3));
 snprintf(buf_4h9yvmB4ieF_7JRJFLhvJG3, sizeof(buf_4h9yvmB4ieF_7JRJFLhvJG3), "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
 objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), buf_4h9yvmB4ieF_7JRJFLhvJG3);
} //end objstrbufferprintint _4h9yvmB4ieF_7JRJFLhvJG3
;     
} // end cexpansion _4h9yvmB4ieF_7JRJFLhvJG3 - objstrbufferprintint     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #4 statement:    
{ // start cexpansion _7vLMy8bPNE3_2qd7oURm8L2 - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "[32]={0};"));     
} // end cexpansion _7vLMy8bPNE3_2qd7oURm8L2 - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #5 statement:    
{ // start cexpansion _6amT3YRmLU6_0TKFKJ5FILi - objstrbuffernewlinepayl     
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);     
} // end cexpansion _6amT3YRmLU6_0TKFKJ5FILi - objstrbuffernewlinepayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #6 statement:    
{ // start cexpansion _39vto2jXSds_1XdPjo0Amkd - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "idtocbuf32_BM (objid_BM("));     
} // end cexpansion _39vto2jXSds_1XdPjo0Amkd - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #7 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #8 statement:    
{ // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression     
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #9 statement:    
{ // start cexpansion _0MonCV0Az8f_2rBRV72dJJz - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "), idbuf"));     
} // end cexpansion _0MonCV0Az8f_2rBRV72dJJz - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #10 statement:    
{ // start cexpansion _5TRr3zS3FxR_8vswQ44kQaj - objstrbufferprintobjid     
/*objstrbufferprintobjid _5TRr3zS3FxR_8vswQ44kQaj:*/
objectval_tyBM *obsbuf__5TRr3zS3FxR_8vswQ44kQaj = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
objectval_tyBM *ob__5TRr3zS3FxR_8vswQ44kQaj = ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);
if (objhasstrbufferpayl_BM(obsbuf__5TRr3zS3FxR_8vswQ44kQaj) && isobject_BM(ob__5TRr3zS3FxR_8vswQ44kQaj)) {
  char idbuf__5TRr3zS3FxR_8vswQ44kQaj [32];
 memset (idbuf__5TRr3zS3FxR_8vswQ44kQaj, 0, sizeof(idbuf__5TRr3zS3FxR_8vswQ44kQaj));
 idtocbuf32_BM (objid_BM (ob__5TRr3zS3FxR_8vswQ44kQaj), idbuf__5TRr3zS3FxR_8vswQ44kQaj);
 objstrbufferappendcstrpayl_BM(obsbuf__5TRr3zS3FxR_8vswQ44kQaj, idbuf__5TRr3zS3FxR_8vswQ44kQaj);
};
// end objstrbufferprintobjid _5TRr3zS3FxR_8vswQ44kQaj
;     
} // end cexpansion _5TRr3zS3FxR_8vswQ44kQaj - objstrbufferprintobjid     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #11 statement:    
{ // start cexpansion _9Dsiwu9HSkE_5pX9EvKmSxK - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "_n"));     
} // end cexpansion _9Dsiwu9HSkE_5pX9EvKmSxK - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #12 statement:    
{ // start cexpansion _3wD29vlN70k_7xekhtrZYmH - objstrbufferprintint     
/*objstrbufferprintint:*/if (objhasstrbufferpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv)) {
 char buf_3wD29vlN70k_7xekhtrZYmH[32]; 
 memset (buf_3wD29vlN70k_7xekhtrZYmH, 0, sizeof(buf_3wD29vlN70k_7xekhtrZYmH));
 snprintf(buf_3wD29vlN70k_7xekhtrZYmH, sizeof(buf_3wD29vlN70k_7xekhtrZYmH), "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
 objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), buf_3wD29vlN70k_7xekhtrZYmH);
} //end objstrbufferprintint _3wD29vlN70k_7xekhtrZYmH
;     
} // end cexpansion _3wD29vlN70k_7xekhtrZYmH - objstrbufferprintint     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #13 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #14 statement:    
{ // start cexpansion _9awyi1AxUBB_6rpdX1tcR4h - objstrbuffernewlinepayl     
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);     
} // end cexpansion _9awyi1AxUBB_6rpdX1tcR4h - objstrbuffernewlinepayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #15 statement:    
{ // start out _9qmoxwsdBMF_1cBJhqeFE5Z to o_modgen     
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "objstrbufferprintfpayl_BM (");    
} // end out _9qmoxwsdBMF_1cBJhqeFE5Z    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #16 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #17 statement:    
{ // start out _8VPucIDSd8J_1G0LnGwTrSJ to o_modgen     
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, ", \"%.12s\", idbuf");    
} // end out _8VPucIDSd8J_1G0LnGwTrSJ    
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #18 statement:    
{ // start cexpansion _5TRr3zS3FxR_8vswQ44kQaj - objstrbufferprintobjid     
/*objstrbufferprintobjid _5TRr3zS3FxR_8vswQ44kQaj:*/
objectval_tyBM *obsbuf__5TRr3zS3FxR_8vswQ44kQaj = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
objectval_tyBM *ob__5TRr3zS3FxR_8vswQ44kQaj = ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);
if (objhasstrbufferpayl_BM(obsbuf__5TRr3zS3FxR_8vswQ44kQaj) && isobject_BM(ob__5TRr3zS3FxR_8vswQ44kQaj)) {
  char idbuf__5TRr3zS3FxR_8vswQ44kQaj [32];
 memset (idbuf__5TRr3zS3FxR_8vswQ44kQaj, 0, sizeof(idbuf__5TRr3zS3FxR_8vswQ44kQaj));
 idtocbuf32_BM (objid_BM (ob__5TRr3zS3FxR_8vswQ44kQaj), idbuf__5TRr3zS3FxR_8vswQ44kQaj);
 objstrbufferappendcstrpayl_BM(obsbuf__5TRr3zS3FxR_8vswQ44kQaj, idbuf__5TRr3zS3FxR_8vswQ44kQaj);
};
// end objstrbufferprintobjid _5TRr3zS3FxR_8vswQ44kQaj
;     
} // end cexpansion _5TRr3zS3FxR_8vswQ44kQaj - objstrbufferprintobjid     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #19 statement:    
{ // start cexpansion _9Dsiwu9HSkE_5pX9EvKmSxK - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "_n"));     
} // end cexpansion _9Dsiwu9HSkE_5pX9EvKmSxK - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #20 statement:    
{ // start cexpansion _8HZgeYRcjX6_46BfRf4vkk4 - objstrbufferprintint     
/*objstrbufferprintint:*/if (objhasstrbufferpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv)) {
 char buf_8HZgeYRcjX6_46BfRf4vkk4[32]; 
 memset (buf_8HZgeYRcjX6_46BfRf4vkk4, 0, sizeof(buf_8HZgeYRcjX6_46BfRf4vkk4));
 snprintf(buf_8HZgeYRcjX6_46BfRf4vkk4, sizeof(buf_8HZgeYRcjX6_46BfRf4vkk4), "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
 objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), buf_8HZgeYRcjX6_46BfRf4vkk4);
} //end objstrbufferprintint _8HZgeYRcjX6_46BfRf4vkk4
;     
} // end cexpansion _8HZgeYRcjX6_46BfRf4vkk4 - objstrbufferprintint     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #21 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _9r5C2b73vHL_1dnbWS5hq8o #23 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__9E2lY6UWtZc_1zqNjPXxrB1:; // when #24 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9E2lY6UWtZc_1zqNjPXxrB1 #0 statement:    
{ // start cexpansion _7dXnrwZwpMJ_5m6aSmqnq4b - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out newline:*/ objstrbuffernewlinepayl_BM ("));     
} // end cexpansion _7dXnrwZwpMJ_5m6aSmqnq4b - objstrbufferappendcstrpayl     
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9E2lY6UWtZc_1zqNjPXxrB1 #1 statement:    
{ // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var     
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));      
} // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var      
    
 // objswitch _88CClQZGP1N_57QoKCh6Ivj when _9E2lY6UWtZc_1zqNjPXxrB1 #2 statement:    
{ // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));     
} // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl     
    
    
break; // end when _9E2lY6UWtZc_1zqNjPXxrB1 #24 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
   
} } // end objswitch _88CClQZGP1N_57QoKCh6Ivj   
   
} //endwhen _9snNxHFHKej_9go5H2wttwP   
else { /*cond else _4nOMpL7ofYO_7UI4gpk1cQz*/   
//failure _3RUddTzPPB8_5j4EYXKOe2g   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[0] /*!_08PMymoD6YJ_8rspWoCg4Xu*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[28] /*|_3RUddTzPPB8_5j4EYXKOe2g*/)),
                ((struct stackframe_stBM *) &_));
} /*cond else _4nOMpL7ofYO_7UI4gpk1cQz*/   
/*endcond _4nOMpL7ofYO_7UI4gpk1cQz*/  
 
}} // end for-up _3584humjRT7_5DRf4EbSEPp 
 
{ // start cexpansion _1PZEZj2fb0B_1pU56ft4Ca0 - objstrbuffersetindentpayl  
/*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));  
} // end cexpansion _1PZEZj2fb0B_1pU56ft4Ca0 - objstrbuffersetindentpayl  
  
//+ #10/16 of block _2RXF4soNP1G_4lwKnhT9HXn ::  
 
{ // start cexpansion _0qwKnmv5GHv_81ky3FnB9La - objstrbuffernewlinepayl  
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);  
} // end cexpansion _0qwKnmv5GHv_81ky3FnB9La - objstrbuffernewlinepayl  
  
 
{ // start cexpansion _4uMCgKrJauH_7kInVSNwYHm - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "} // end out "));  
} // end cexpansion _4uMCgKrJauH_7kInVSNwYHm - objstrbufferappendcstrpayl  
  
//+ #12/16 of block _2RXF4soNP1G_4lwKnhT9HXn ::  
 
{ // start cexpansion _2Oq5DJsc44Q_2O4dNlPq85M - objstrbufferprintobject  
/*objstrbufferprintobject _2Oq5DJsc44Q_2O4dNlPq85M:*/
 objectval_tyBM* obsbuf_2Oq5DJsc44Q_2O4dNlPq85M = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
 objectval_tyBM* ob_2Oq5DJsc44Q_2O4dNlPq85M = ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);
 if (objhasstrbufferpayl_BM(obsbuf_2Oq5DJsc44Q_2O4dNlPq85M) && isobject_BM(ob_2Oq5DJsc44Q_2O4dNlPq85M))
  objstrbufferappendcstrpayl_BM(obsbuf_2Oq5DJsc44Q_2O4dNlPq85M, objectdbg_BM(ob_2Oq5DJsc44Q_2O4dNlPq85M));
// end objstrbufferprintobject _2Oq5DJsc44Q_2O4dNlPq85M
;  
} // end cexpansion _2Oq5DJsc44Q_2O4dNlPq85M - objstrbufferprintobject  
  
 
{ // start cexpansion _5uqRz6AHI0d_5f4Tgcp2keq - objstrbuffernewlinepayl  
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);  
} // end cexpansion _5uqRz6AHI0d_5f4Tgcp2keq - objstrbuffernewlinepayl  
  
//+ #14/16 of block _2RXF4soNP1G_4lwKnhT9HXn ::  
 
 
{ // run _5EhMM2h3lya_7VX0vMYKsQt 
/*debug end emit_statement°basiclo_outstmt o_stmt o_modgen o_routprep depth*/
DBGPRINTF_BM("end emit_statement°basiclo_outstmt €%.9s o_stmt=%s o_modgen=%s/L%u o_routprep=%s depth#%ld",
 "_5EhMM2h3lya_7VX0vMYKsQt",
 objectdbg_BM( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),
 objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
 objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
 objectdbg2_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
; 
} // end run _5EhMM2h3lya_7VX0vMYKsQt 
 
 
/*return _1FeST1CIIGF_4YITXGbnL0Q:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl; 
 goto epilog_08PMymoD6YJ_8rspWoCg4Xu; 
 
/* !endingblock _2RXF4soNP1G_4lwKnhT9HXn */ 
goto endblock__2RXF4soNP1G_4lwKnhT9HXn; 
endblock__2RXF4soNP1G_4lwKnhT9HXn: ; 
} /*-block _2RXF4soNP1G_4lwKnhT9HXn */

 epilog_08PMymoD6YJ_8rspWoCg4Xu: __attribute__ ((unused)); // routine _08PMymoD6YJ_8rspWoCg4Xu epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _08PMymoD6YJ_8rspWoCg4Xu routine#0 _08PMymoD6YJ_8rspWoCg4Xu




value_tyBM crout_0vCFi47Ctm6_70R5Tci6JuH_BM //#1
 (struct stackframe_stBM* stkf, //
//!emit_block°basiclo_for_up_loop  < o_block (o_modgen o_routprep v_depth)
  // 4 arguments
  const value_tyBM arg0,  // o_block
  const value_tyBM arg1,  // o_modgen
  const value_tyBM arg2,  // o_routprep
  const value_tyBM arg3,  // v_depth
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _0vCFi47Ctm6_70R5Tci6JuH
  struct frame_0vCFi47Ctm6_70R5Tci6JuH_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 9 local values:
    value_tyBM v_0qTBOEAT5pa_2fz1SKfHrMV; // v_resemit
    objectval_tyBM* o_2RUj1oyJ2rf_1ICZWr844Sv; // o_modgen
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    value_tyBM v_4leeeoANgjm_31PbCGhynlU; // v_countexp
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    objectval_tyBM* o_4QkDiZYXmJR_8VofvgKqcu4; // o_varindex
    objectval_tyBM* o_5XGKMg1Kevs_6eAce4ib9XW; // o_block
    objectval_tyBM* o_6RpSqxAOt2p_35laNqeU6KH; // o_routprep
    objectval_tyBM* o_6Z4UU939WbU_8BK9xcKsXNb; // o_comp
    /// 3 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
   } _;
   memset (&_, 0, sizeof(struct frame_0vCFi47Ctm6_70R5Tci6JuH_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 9;
   _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[3] /*|_0vCFi47Ctm6_70R5Tci6JuH*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // locking 2:
    objectval_tyBM* locked_6Yjljnt0m8g_6LWfXAh0c3u = NULL; // for o_comp
    objectval_tyBM* locked_8rkMLIm7zSu_1cmUNDHOEwG = NULL; // for o_block
   // fetch 4 arguments:
   _.o_5XGKMg1Kevs_6eAce4ib9XW = objectcast_BM (arg0); // o_block
   _.o_2RUj1oyJ2rf_1ICZWr844Sv = objectcast_BM (arg1); // o_modgen
   _.o_6RpSqxAOt2p_35laNqeU6KH = objectcast_BM (arg2); // o_routprep
   _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
   // fetched 4 arguments.
   // no closed values in _0vCFi47Ctm6_70R5Tci6JuH.
   const closure_tyBM* callclos_0vCFi47Ctm6_70R5Tci6JuH __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_0vCFi47Ctm6_70R5Tci6JuH  __attribute__((unused)) = 0;
   // routine _0vCFi47Ctm6_70R5Tci6JuH body:

startblock__6Jnvc0ZxFCj_9aOT6FGpvp2: __attribute__((unused));
{ /* +block _6Jnvc0ZxFCj_9aOT6FGpvp2 */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _6NXI94hE78R_31gCNvG9obz  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 
{ // run _1y5LOd8TMK1_4Evm0WxnUBJ 
/*debug emit_block°basiclo_for_up_loop start o_block o_modgen o_routprep depth*/
DBGPRINTF_BM("emit_block°basiclo_for_up_loop start €%.9s o_block=%s o_modgen=%s/L%u o_routprep=%s depth#%ld",
 "_1y5LOd8TMK1_4Evm0WxnUBJ",
 objectdbg_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),
 objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), 
 objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
 objectdbg2_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _1y5LOd8TMK1_4Evm0WxnUBJ 
 
 
 
{ // begin lockobj _8rkMLIm7zSu_1cmUNDHOEwG 
  objectval_tyBM* curlockedob_8rkMLIm7zSu_1cmUNDHOEwG = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW); 
if (objlock_BM (curlockedob_8rkMLIm7zSu_1cmUNDHOEwG)) {  
locked_8rkMLIm7zSu_1cmUNDHOEwG = curlockedob_8rkMLIm7zSu_1cmUNDHOEwG;  
  
 /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4 = //assign _7ZXI6Zdr37M_9tDIRYKWyAS  
/*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[52] /*!index*/)))); 
  
 /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU = //assign _6LSBFvxlbNc_0rY6zQlblXq  
/*objgetattr:*/objgetattr_BM(( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[44] /*!count*/))); 
  
//+ #2/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::  
 
{ // run _9RlrVeqVaJ4_7Q2XB4mXHj3 
/*debug emit_block°basiclo_for_up_loop o_block o_varindex v_countexp depth*/
 DBGPRINTF_BM("emit_block°basiclo_for_up_loop €%.9s o_block=%s o_varindex=%s v_countexp=%s depth#%ld",
 "_9RlrVeqVaJ4_7Q2XB4mXHj3",
 objectdbg_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),
 objectdbg1_BM( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4),
 OUTSTRVALUE_BM( /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _9RlrVeqVaJ4_7Q2XB4mXHj3 
  
{ // start cexpansion _18JuYhtt3U6_1G2hLBZKcLY - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "{ //for-up "));  
} // end cexpansion _18JuYhtt3U6_1G2hLBZKcLY - objstrbufferappendcstrpayl  
  
//+ #4/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::  
{ // start cexpansion _9GpOgboir8I_171IKtULnOE - objstrbufferprintobject  
/*objstrbufferprintobject _9GpOgboir8I_171IKtULnOE:*/
 objectval_tyBM* obsbuf_9GpOgboir8I_171IKtULnOE = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
 objectval_tyBM* ob_9GpOgboir8I_171IKtULnOE = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
 if (objhasstrbufferpayl_BM(obsbuf_9GpOgboir8I_171IKtULnOE) && isobject_BM(ob_9GpOgboir8I_171IKtULnOE))
  objstrbufferappendcstrpayl_BM(obsbuf_9GpOgboir8I_171IKtULnOE, objectdbg_BM(ob_9GpOgboir8I_171IKtULnOE));
// end objstrbufferprintobject _9GpOgboir8I_171IKtULnOE
;  
} // end cexpansion _9GpOgboir8I_171IKtULnOE - objstrbufferprintobject  
  
{ // start cexpansion _7wZBpo5VBr6_6jSVDUVjePE - objstrbuffersetindentpayl  
/*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));   
} // end cexpansion _7wZBpo5VBr6_6jSVDUVjePE - objstrbuffersetindentpayl   
  
//+ #6/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::  
{ // start cexpansion _5933FfICfAg_8KivZyDlzYL - objstrbuffernewlinepayl  
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);  
} // end cexpansion _5933FfICfAg_8KivZyDlzYL - objstrbuffernewlinepayl  
  
{ // start cexpansion _7mlzwCbTf8a_9MWM2yGWjXl - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "intptr_t cnt"));  
} // end cexpansion _7mlzwCbTf8a_9MWM2yGWjXl - objstrbufferappendcstrpayl  
  
//+ #8/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::  
{ // start cexpansion _8wf8lanEjIc_7Pkvsh2ZPzV - objstrbufferprintobjid  
/*objstrbufferprintobjid _8wf8lanEjIc_7Pkvsh2ZPzV:*/
objectval_tyBM *obsbuf__8wf8lanEjIc_7Pkvsh2ZPzV = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
objectval_tyBM *ob__8wf8lanEjIc_7Pkvsh2ZPzV = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
if (objhasstrbufferpayl_BM(obsbuf__8wf8lanEjIc_7Pkvsh2ZPzV) && isobject_BM(ob__8wf8lanEjIc_7Pkvsh2ZPzV)) {
  char idbuf__8wf8lanEjIc_7Pkvsh2ZPzV [32];
 memset (idbuf__8wf8lanEjIc_7Pkvsh2ZPzV, 0, sizeof(idbuf__8wf8lanEjIc_7Pkvsh2ZPzV));
 idtocbuf32_BM (objid_BM (ob__8wf8lanEjIc_7Pkvsh2ZPzV), idbuf__8wf8lanEjIc_7Pkvsh2ZPzV);
 objstrbufferappendcstrpayl_BM(obsbuf__8wf8lanEjIc_7Pkvsh2ZPzV, idbuf__8wf8lanEjIc_7Pkvsh2ZPzV);
};
// end objstrbufferprintobjid _8wf8lanEjIc_7Pkvsh2ZPzV
;  
} // end cexpansion _8wf8lanEjIc_7Pkvsh2ZPzV - objstrbufferprintobjid  
  
{ // start cexpansion _6HS1ctWa2cx_8kR6FVRd5gz - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " = "));  
} // end cexpansion _6HS1ctWa2cx_8kR6FVRd5gz - objstrbufferappendcstrpayl  
  
//+ #10/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::  
{ // start cexpansion _8Ux2RkzGGBL_1jntmBiiFTE - miniemit_expression  
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));   
} // end cexpansion _8Ux2RkzGGBL_1jntmBiiFTE - miniemit_expression   
  
{ // start cexpansion _2B5X8R9i8ty_1ucz1kI8GDH - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ";"));  
} // end cexpansion _2B5X8R9i8ty_1ucz1kI8GDH - objstrbufferappendcstrpayl  
  
//+ #12/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::  
{ // start cexpansion _0vpJQXO13zS_2L5lG1Mj9Jl - objstrbuffernewlinepayl  
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);  
} // end cexpansion _0vpJQXO13zS_2L5lG1Mj9Jl - objstrbuffernewlinepayl  
  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _61MCdztYidF_16139B2zGKg  
 0; 
  
//+ #14/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::  
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _5aEMMsDVPT8_5OOBY9RA7UT  
/*objnbcomps:*/ objnbcomps_BM ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW); 
  
{ // start cexpansion _4j0SrCTPKX5_578JTKzM0IO - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "for ("));  
} // end cexpansion _4j0SrCTPKX5_578JTKzM0IO - objstrbufferappendcstrpayl  
  
//+ #16/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::  
{ // start cexpansion _9VLKy0D7b3d_3C7v96GTfEI - miniemit_var  
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));  
} // end cexpansion _9VLKy0D7b3d_3C7v96GTfEI - miniemit_var  
  
{ // start cexpansion _1bVTR9o3Bsm_4S0wt09vteL - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " =0;"));  
} // end cexpansion _1bVTR9o3Bsm_4S0wt09vteL - objstrbufferappendcstrpayl  
  
//+ #18/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::  
{ // start cexpansion _3dqnISCnpKV_9cd4oa4lD8e - objstrbuffernewlinepayl  
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);  
} // end cexpansion _3dqnISCnpKV_9cd4oa4lD8e - objstrbuffernewlinepayl  
  
{ // start cexpansion _7FhLjwiMrkL_0S5nfILsPPH - miniemit_var  
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));  
} // end cexpansion _7FhLjwiMrkL_0S5nfILsPPH - miniemit_var  
  
//+ #20/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::  
{ // start cexpansion _87dePnNzTl4_0O8JWYSX5zV - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " < cnt"));  
} // end cexpansion _87dePnNzTl4_0O8JWYSX5zV - objstrbufferappendcstrpayl  
  
{ // start cexpansion _9o0MX6Ie2We_0ErK51uBv2S - objstrbufferprintobjid  
/*objstrbufferprintobjid _9o0MX6Ie2We_0ErK51uBv2S:*/
objectval_tyBM *obsbuf__9o0MX6Ie2We_0ErK51uBv2S = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
objectval_tyBM *ob__9o0MX6Ie2We_0ErK51uBv2S = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
if (objhasstrbufferpayl_BM(obsbuf__9o0MX6Ie2We_0ErK51uBv2S) && isobject_BM(ob__9o0MX6Ie2We_0ErK51uBv2S)) {
  char idbuf__9o0MX6Ie2We_0ErK51uBv2S [32];
 memset (idbuf__9o0MX6Ie2We_0ErK51uBv2S, 0, sizeof(idbuf__9o0MX6Ie2We_0ErK51uBv2S));
 idtocbuf32_BM (objid_BM (ob__9o0MX6Ie2We_0ErK51uBv2S), idbuf__9o0MX6Ie2We_0ErK51uBv2S);
 objstrbufferappendcstrpayl_BM(obsbuf__9o0MX6Ie2We_0ErK51uBv2S, idbuf__9o0MX6Ie2We_0ErK51uBv2S);
};
// end objstrbufferprintobjid _9o0MX6Ie2We_0ErK51uBv2S
;  
} // end cexpansion _9o0MX6Ie2We_0ErK51uBv2S - objstrbufferprintobjid  
  
//+ #22/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::  
{ // start cexpansion _0v5VUOseyTZ_0GTuiDe6qjP - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ";"));  
} // end cexpansion _0v5VUOseyTZ_0GTuiDe6qjP - objstrbufferappendcstrpayl  
  
{ // start cexpansion _0ajssbXBH1t_86eb7MoTPzX - objstrbuffernewlinepayl  
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);  
} // end cexpansion _0ajssbXBH1t_86eb7MoTPzX - objstrbuffernewlinepayl  
  
//+ #24/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::  
{ // start cexpansion _2fEiBwWFSaE_0vU58gZVuk2 - miniemit_var  
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));  
} // end cexpansion _2fEiBwWFSaE_0vU58gZVuk2 - miniemit_var  
  
{ // start cexpansion _6nRAx5X9S18_4ndrVCGDGid - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "++) {"));  
} // end cexpansion _6nRAx5X9S18_4ndrVCGDGid - objstrbufferappendcstrpayl  
  
//+ #26/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::  
 
//// +while _8azNt3uvDua_0vznLIRcXQ7 
startblock__8azNt3uvDua_0vznLIRcXQ7:  /*+!while*/; 
{ /* +while _8azNt3uvDua_0vznLIRcXQ7 */  
if (!(/*while _8azNt3uvDua_0vznLIRcXQ7 cond:*/ (/*less_int:*/( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) < ( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k)))) //: testwhile _8azNt3uvDua_0vznLIRcXQ7 failing   
  goto endblock__8azNt3uvDua_0vznLIRcXQ7; //failwhile   
// while _8azNt3uvDua_0vznLIRcXQ7 body:   
// while _8azNt3uvDua_0vznLIRcXQ7 comp#0:  
 /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb = //assign _3ILFBLwMl1u_6ucVMPW4LUg   
/*val_to_object:*/objectcast_BM(/*objgetcomp:*/objgetcomp_BM (( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)));  
// while _8azNt3uvDua_0vznLIRcXQ7 comp#1:  
if /*cond _3KcGmQSYuqY_1dj3Tb5qQwT*/   
/*when _9NZCCksbBTL_1lELN9cqwB6:*/  
 ( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb) { //body when _9NZCCksbBTL_1lELN9cqwB6   
   
{ // run _6yU6G9JLfzp_7ifGjU3aSQy   
/*debug emit_block°basiclo_for_up_loop ii o_comp o_modgen o_block*/
DBGPRINTF_BM("emit_block°basiclo_for_up_loop €%.9s ii#%ld o_comp=%s o_modgen=%s/L%u o_block=%s",
 "_6yU6G9JLfzp_7ifGjU3aSQy",
  (long int)( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
  objectdbg_BM( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),
  objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
  objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
  objectdbg2_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW));
    ;   
} // end run _6yU6G9JLfzp_7ifGjU3aSQy   
{ // start cexpansion _0DPBIFwbcm4_4l1ir7iZTuR - objstrbuffersetindentpayl    
/*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));     
} // end cexpansion _0DPBIFwbcm4_4l1ir7iZTuR - objstrbuffersetindentpayl     
{ // start cexpansion _99sshqy7Sjj_0hU1fNbVw2x - objstrbuffernewlinepayl    
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);    
} // end cexpansion _99sshqy7Sjj_0hU1fNbVw2x - objstrbuffernewlinepayl    
{ // start cexpansion _5vgsLFSo0RQ_0yFxUpyUa6k - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "// for-up "));    
} // end cexpansion _5vgsLFSo0RQ_0yFxUpyUa6k - objstrbufferappendcstrpayl    
{ // start cexpansion _4fwDvpq5srl_8hN8Q4lxInc - objstrbufferprintobjid    
/*objstrbufferprintobjid _4fwDvpq5srl_8hN8Q4lxInc:*/
objectval_tyBM *obsbuf__4fwDvpq5srl_8hN8Q4lxInc = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
objectval_tyBM *ob__4fwDvpq5srl_8hN8Q4lxInc = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
if (objhasstrbufferpayl_BM(obsbuf__4fwDvpq5srl_8hN8Q4lxInc) && isobject_BM(ob__4fwDvpq5srl_8hN8Q4lxInc)) {
  char idbuf__4fwDvpq5srl_8hN8Q4lxInc [32];
 memset (idbuf__4fwDvpq5srl_8hN8Q4lxInc, 0, sizeof(idbuf__4fwDvpq5srl_8hN8Q4lxInc));
 idtocbuf32_BM (objid_BM (ob__4fwDvpq5srl_8hN8Q4lxInc), idbuf__4fwDvpq5srl_8hN8Q4lxInc);
 objstrbufferappendcstrpayl_BM(obsbuf__4fwDvpq5srl_8hN8Q4lxInc, idbuf__4fwDvpq5srl_8hN8Q4lxInc);
};
// end objstrbufferprintobjid _4fwDvpq5srl_8hN8Q4lxInc
;    
} // end cexpansion _4fwDvpq5srl_8hN8Q4lxInc - objstrbufferprintobjid    
{ // start cexpansion _3dJQpojlpw0_5d9iHzwxHt0 - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " #"));    
} // end cexpansion _3dJQpojlpw0_5d9iHzwxHt0 - objstrbufferappendcstrpayl    
{ // start cexpansion _2AQKWLCUFvL_1nhtg5qyMOW - objstrbufferprintint    
/*objstrbufferprintint:*/if (objhasstrbufferpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv)) {
 char buf_2AQKWLCUFvL_1nhtg5qyMOW[32]; 
 memset (buf_2AQKWLCUFvL_1nhtg5qyMOW, 0, sizeof(buf_2AQKWLCUFvL_1nhtg5qyMOW));
 snprintf(buf_2AQKWLCUFvL_1nhtg5qyMOW, sizeof(buf_2AQKWLCUFvL_1nhtg5qyMOW), "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
 objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), buf_2AQKWLCUFvL_1nhtg5qyMOW);
} //end objstrbufferprintint _2AQKWLCUFvL_1nhtg5qyMOW
;    
} // end cexpansion _2AQKWLCUFvL_1nhtg5qyMOW - objstrbufferprintint    
{ // start cexpansion _78NeiHidc0B_0v6yK8esTnj - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " :"));    
} // end cexpansion _78NeiHidc0B_0v6yK8esTnj - objstrbufferappendcstrpayl    
{ // start cexpansion _9ZltE2hANvA_7WHBrdvAnhY - objstrbuffernewlinepayl    
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);    
} // end cexpansion _9ZltE2hANvA_7WHBrdvAnhY - objstrbuffernewlinepayl    
   
{ // begin lockobj _6Yjljnt0m8g_6LWfXAh0c3u   
  objectval_tyBM* curlockedob_6Yjljnt0m8g_6LWfXAh0c3u = ( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb);   
if (objlock_BM (curlockedob_6Yjljnt0m8g_6LWfXAh0c3u)) {    
locked_6Yjljnt0m8g_6LWfXAh0c3u = curlockedob_6Yjljnt0m8g_6LWfXAh0c3u;    
    
if /*cond _2EhWIVvxjvU_1ISxJRsN8RH*/    
/*when _0XHPA7cptAe_4i19aTf4Gxq:*/   
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[29] /*!basiclo_block*/)))) { //body when _0XHPA7cptAe_4i19aTf4Gxq    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _1FhisSY6VvV_9wuNntndHjA     
(send3_BM (( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), /*sel:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[49] /*!emit_block*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),  ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));    
    
} //endwhen _0XHPA7cptAe_4i19aTf4Gxq    
else if    
/*when _0H7JvNndU7R_1y4eLjc1NUL:*/   
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[30] /*!basiclo_statement*/)))) { //body when _0H7JvNndU7R_1y4eLjc1NUL    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _2mKWX3OmQZn_4ros3plkqLz     
(send3_BM (( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), /*sel:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[12] /*!emit_statement*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),  ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));    
    
} //endwhen _0H7JvNndU7R_1y4eLjc1NUL    
else { /*cond else _2EhWIVvxjvU_1ISxJRsN8RH*/    
//failure _6MTJtvsUEYW_9WuS0LnLfmm    
PLACEDFAILURE_BM(__LINE__,    
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[33] /*!failure_bad_class*/)), 
 /*make_node 5 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[3] /*!_0vCFi47Ctm6_70R5Tci6JuH*/)), 
 
( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), 
 
( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[53] /*|_6MTJtvsUEYW_9WuS0LnLfmm*/)),
                ((struct stackframe_stBM *) &_));
} /*cond else _2EhWIVvxjvU_1ISxJRsN8RH*/    
/*endcond _2EhWIVvxjvU_1ISxJRsN8RH*/   
    
   
{ // run _0iLVtU6WXeV_1Q97ZeNzYpy   
/*debug emit_block°basiclo_for_up_loop v_resemit=%s ii o_comp o_modgen*/
DBGPRINTF_BM("emit_block°basiclo_for_up_loop €%.9s v_resemit=%s ii#%ld o_comp=%s o_modgen=%s/L%u",
 "_0iLVtU6WXeV_1Q97ZeNzYpy",
  OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
  (long int)( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
  objectdbg_BM( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),
  objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
  objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv));
    ;   
} // end run _0iLVtU6WXeV_1Q97ZeNzYpy   
    
if /*cond _6lacdJDQoOJ_2mjBKMBpZVX*/    
/*when _7erONaq08kk_4kMHqRc79hd:*/   
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _7erONaq08kk_4kMHqRc79hd    
//failure _3CZ4Lq3VkJF_3Qt5nkQ9R3w     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[3] /*!_0vCFi47Ctm6_70R5Tci6JuH*/)), 
 
( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), 
 
( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[26] /*|_3CZ4Lq3VkJF_3Qt5nkQ9R3w*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _7erONaq08kk_4kMHqRc79hd    
/*endcond _6lacdJDQoOJ_2mjBKMBpZVX*/   
    
objunlock_BM (locked_6Yjljnt0m8g_6LWfXAh0c3u), locked_6Yjljnt0m8g_6LWfXAh0c3u = NULL;   
} } // end objlock _6Yjljnt0m8g_6LWfXAh0c3u   
   
} //endwhen _9NZCCksbBTL_1lELN9cqwB6   
/*endcond _3KcGmQSYuqY_1dj3Tb5qQwT*/  
// while _8azNt3uvDua_0vznLIRcXQ7 comp#2:  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _894QWyZSi2X_11HWCDneRlh   
/*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1));  
  
goto startblock__8azNt3uvDua_0vznLIRcXQ7; // repeatwhile  
endblock__8azNt3uvDua_0vznLIRcXQ7: /*endingwhile*/;  
} /*-endwhile _8azNt3uvDua_0vznLIRcXQ7 */ 
 
  
{ // start cexpansion _5seJMeyVMag_6jwlAf81tPv - objstrbuffersetindentpayl  
/*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));  
} // end cexpansion _5seJMeyVMag_6jwlAf81tPv - objstrbuffersetindentpayl  
  
//+ #28/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::  
{ // start cexpansion _86q4oBOlppk_1830Im1NZjk - objstrbuffernewlinepayl  
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);  
} // end cexpansion _86q4oBOlppk_1830Im1NZjk - objstrbuffernewlinepayl  
  
{ // start cexpansion _5EtdhJgLlVL_5U1X2vmfp0y - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "}} // end for-up "));  
} // end cexpansion _5EtdhJgLlVL_5U1X2vmfp0y - objstrbufferappendcstrpayl  
  
//+ #30/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::  
{ // start cexpansion _0d5SVBzCltH_1ZscGvcgwrx - objstrbufferprintobjid  
/*objstrbufferprintobjid _0d5SVBzCltH_1ZscGvcgwrx:*/
objectval_tyBM *obsbuf__0d5SVBzCltH_1ZscGvcgwrx = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
objectval_tyBM *ob__0d5SVBzCltH_1ZscGvcgwrx = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
if (objhasstrbufferpayl_BM(obsbuf__0d5SVBzCltH_1ZscGvcgwrx) && isobject_BM(ob__0d5SVBzCltH_1ZscGvcgwrx)) {
  char idbuf__0d5SVBzCltH_1ZscGvcgwrx [32];
 memset (idbuf__0d5SVBzCltH_1ZscGvcgwrx, 0, sizeof(idbuf__0d5SVBzCltH_1ZscGvcgwrx));
 idtocbuf32_BM (objid_BM (ob__0d5SVBzCltH_1ZscGvcgwrx), idbuf__0d5SVBzCltH_1ZscGvcgwrx);
 objstrbufferappendcstrpayl_BM(obsbuf__0d5SVBzCltH_1ZscGvcgwrx, idbuf__0d5SVBzCltH_1ZscGvcgwrx);
};
// end objstrbufferprintobjid _0d5SVBzCltH_1ZscGvcgwrx
;  
} // end cexpansion _0d5SVBzCltH_1ZscGvcgwrx - objstrbufferprintobjid  
  
{ // start cexpansion _0YqaJV0TdmB_1bQnzdTXMfo - objstrbuffernewlinepayl  
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);  
} // end cexpansion _0YqaJV0TdmB_1bQnzdTXMfo - objstrbuffernewlinepayl  
  
//+ #32/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::  
 
{ // run _49h6SrVH7Ar_2cjBCTsDzF4 
/*debug end emit_block°basiclo_for_up_loopo_modgen o_block*/
DBGPRINTF_BM("emit_block°basiclo_for_up_loop €%.9s end o_modgen=%s/L%u o_block=%s",
 "_49h6SrVH7Ar_2cjBCTsDzF4",
  objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
  objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
  objectdbg2_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW));
    ; 
} // end run _49h6SrVH7Ar_2cjBCTsDzF4 
  
/*return _6XhFBVH9rZI_1lhge6f8lDW:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW; 
 goto epilog_0vCFi47Ctm6_70R5Tci6JuH; 
  
objunlock_BM (locked_8rkMLIm7zSu_1cmUNDHOEwG), locked_8rkMLIm7zSu_1cmUNDHOEwG = NULL; 
} } // end objlock _8rkMLIm7zSu_1cmUNDHOEwG 
/* !endingblock _6Jnvc0ZxFCj_9aOT6FGpvp2 */ 
goto endblock__6Jnvc0ZxFCj_9aOT6FGpvp2; 
endblock__6Jnvc0ZxFCj_9aOT6FGpvp2: ; 
} /*-block _6Jnvc0ZxFCj_9aOT6FGpvp2 */

 epilog_0vCFi47Ctm6_70R5Tci6JuH: __attribute__ ((unused)); // routine _0vCFi47Ctm6_70R5Tci6JuH epilogue:
   // unlocking 2:
    if (locked_6Yjljnt0m8g_6LWfXAh0c3u != NULL)
       objunlock_BM(locked_6Yjljnt0m8g_6LWfXAh0c3u), locked_6Yjljnt0m8g_6LWfXAh0c3u = NULL; // for o_comp
    if (locked_8rkMLIm7zSu_1cmUNDHOEwG != NULL)
       objunlock_BM(locked_8rkMLIm7zSu_1cmUNDHOEwG), locked_8rkMLIm7zSu_1cmUNDHOEwG = NULL; // for o_block
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _0vCFi47Ctm6_70R5Tci6JuH routine#1 _0vCFi47Ctm6_70R5Tci6JuH




value_tyBM crout_1kz7viwMzTp_6PgLhdZzMEy_BM //#2
 (struct stackframe_stBM* stkf, //
//!miniscan_stmt°basiclo_outstmt < o_stmt (o_routprep v_depth o_from)
  // 4 arguments
  const value_tyBM arg0,  // o_stmt
  const value_tyBM arg1,  // o_routprep
  const value_tyBM arg2,  // v_depth
  const value_tyBM arg3,  // o_from
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _1kz7viwMzTp_6PgLhdZzMEy
  struct frame_1kz7viwMzTp_6PgLhdZzMEy_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 12 local values:
    objectval_tyBM* o_0uATzRk8Ajt_6bIBwn6a86I; // o_restype
    value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
    objectval_tyBM* o_13K9OfeXRZR_84nyRTtoj81; // o_conn
    objectval_tyBM* o_34Qtvf1thwK_9rziG6sk6Vl; // o_stmt
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    value_tyBM v_4Q4WBLjAPTV_5WVLmhAvCJY; // v_arg
    value_tyBM v_5wKdFyGNJ5j_50nIjxm7LLY; // v_scanres
    objectval_tyBM* o_68pH0LfBXQ1_9SRMhSZJlQV; // o_varout
    objectval_tyBM* o_6RpSqxAOt2p_35laNqeU6KH; // o_routprep
    objectval_tyBM* o_89nz0KaXXZh_8eSgMmqnK37; // o_from
    value_tyBM v_96vo6uBKhke_6E1vyN3kIKD; // v_expctx
    /// 3 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
   } _;
   memset (&_, 0, sizeof(struct frame_1kz7viwMzTp_6PgLhdZzMEy_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 12;
   _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[8] /*|_1kz7viwMzTp_6PgLhdZzMEy*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // locking 1:
    objectval_tyBM* locked_1mO4b6i93tJ_8qQI7qdBqdy = NULL; // for o_varout
   // fetch 4 arguments:
   _.o_34Qtvf1thwK_9rziG6sk6Vl = objectcast_BM (arg0); // o_stmt
   _.o_6RpSqxAOt2p_35laNqeU6KH = objectcast_BM (arg1); // o_routprep
   _.v_4nJKFtMqlkA_1teQSqofNux = arg2; // v_depth
   _.o_89nz0KaXXZh_8eSgMmqnK37 = objectcast_BM (arg3); // o_from
   // fetched 4 arguments.
   // no closed values in _1kz7viwMzTp_6PgLhdZzMEy.
   const closure_tyBM* callclos_1kz7viwMzTp_6PgLhdZzMEy __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_1kz7viwMzTp_6PgLhdZzMEy  __attribute__((unused)) = 0;
   // routine _1kz7viwMzTp_6PgLhdZzMEy body:

startblock__2z5wZyWhJId_3qRwMQOiLBm: __attribute__((unused));
{ /* +block _2z5wZyWhJId_3qRwMQOiLBm */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _74XT4f1vWl9_7pfkRaZCCjn  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV = //assign _5nVWpRtEEts_2uWUDb4OAKl  
/*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[5] /*!out*/)))); 
 
//+ #2/9 of block _2z5wZyWhJId_3qRwMQOiLBm :: 
 
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _1a4rnGQ9X5p_4tJnSawMpZZ  
/*objnbcomps:*/ objnbcomps_BM ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl); 
 
 
 
{ // run _1mcZijyVnzr_1xEWETupmkp 
/*debug miniscan_stmt°basiclo_outstmt start o_stmt o_routprep depth o_from o_varout leni*/
DBGPRINTF_BM("miniscan_stmt°basiclo_outstmt start €%.9s o_stmt=%s o_routprep=%s depth#%ld o_from=%s o_varout=%s leni#%ld",
 "_1mcZijyVnzr_1xEWETupmkp",
 objectdbg_BM( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),
 objectdbg1_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
 objectdbg2_BM( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37),
 objectdbg3_BM( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV),
 (long int)( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k));; 
} // end run _1mcZijyVnzr_1xEWETupmkp 
 
//+ #4/9 of block _2z5wZyWhJId_3qRwMQOiLBm :: 
 
if /*cond _5VxN0iVhyqn_26Sl2TGladQ*/  
/*when _9AQ254qOzzB_9MWUVdb8wEe:*/ 
 (/*is_null:*/(( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV)==NULL)) { //body when _9AQ254qOzzB_9MWUVdb8wEe  
//failure _1m5rw0BZl8f_4M9cndtjRl8   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[8] /*!_1kz7viwMzTp_6PgLhdZzMEy*/)), 
 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[5] /*!out*/)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
// make_node arg #4 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[11] /*|_1m5rw0BZl8f_4M9cndtjRl8*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _9AQ254qOzzB_9MWUVdb8wEe  
/*endcond _5VxN0iVhyqn_26Sl2TGladQ*/ 
 
 
 
{ // begin lockobj _1mO4b6i93tJ_8qQI7qdBqdy 
  objectval_tyBM* curlockedob_1mO4b6i93tJ_8qQI7qdBqdy = ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV); 
if (objlock_BM (curlockedob_1mO4b6i93tJ_8qQI7qdBqdy)) {  
locked_1mO4b6i93tJ_8qQI7qdBqdy = curlockedob_1mO4b6i93tJ_8qQI7qdBqdy;  
  
 /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I = //assign _0cq3euqLSO5_6Ucuzrr3vxl  
/*miniscan_var:*/ miniscan_var_BM (( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM); 
  
 
{ // run _4RKeQdff5vV_0dyAyd7S7dt 
/*debug miniscan_stmt°basiclo_outstmt o_restype o_varout o_routprep depth o_stmt*/
DBGPRINTF_BM("miniscan_stmt°basiclo_outstmt €%.9s o_restype=%s o_varout=%s o_routprep=%s depth#%ld o_stmt=%s",
 "_4RKeQdff5vV_0dyAyd7S7dt",
 objectdbg_BM( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I),
 objectdbg1_BM( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV),
 objectdbg3_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
 objectdbg3_BM( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl));
; 
} // end run _4RKeQdff5vV_0dyAyd7S7dt 
  
if /*cond _4eHwSv2Q87p_02OWtoIcKUc*/  
/*when _6wuhAPMNDcY_0RSyScYXYj6:*/ 
 (/*unequal_value*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[57] /*!object*/)))) { //body when _6wuhAPMNDcY_0RSyScYXYj6  
//failure _6cS5VddZd7n_9Nnn2wYWAeL   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[48] /*!miniscan_var*/)), 
 
( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1)))), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[46] /*|_6cS5VddZd7n_9Nnn2wYWAeL*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _6wuhAPMNDcY_0RSyScYXYj6  
/*endcond _4eHwSv2Q87p_02OWtoIcKUc*/ 
  
objunlock_BM (locked_1mO4b6i93tJ_8qQI7qdBqdy), locked_1mO4b6i93tJ_8qQI7qdBqdy = NULL; 
} } // end objlock _1mO4b6i93tJ_8qQI7qdBqdy 
//+ #6/9 of block _2z5wZyWhJId_3qRwMQOiLBm :: 
 
{ //for-up _0tD16ZfI6r2_4QaWuN6poQA  
intptr_t cnt_0tD16ZfI6r2_4QaWuN6poQA =  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k;  
for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_0tD16ZfI6r2_4QaWuN6poQA;  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++) {  
// for-up _0tD16ZfI6r2_4QaWuN6poQA #0 :  
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _8wqqyJEwgUf_7TGATyKMLYH   
/*objgetcomp:*/objgetcomp_BM (( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));  
  
// for-up _0tD16ZfI6r2_4QaWuN6poQA #1 :  
  
{ // run _2lDiLBXEGvY_3QGIrHwVlgs  
/*debug miniscan_stmt°basiclo_outstmt v_comp ii o_stmt o_routprep depth o_from*/
 DBGPRINTF_BM("debug miniscan_stmt°basiclo_outstmt €%.9s v_comp=%s ii#%ld o_stmt=%s o_routprep=%s depth#%ld o_from=%s",
  "_2lDiLBXEGvY_3QGIrHwVlgs",
  OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
  (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
  objectdbg_BM( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),
  objectdbg1_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
  (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
  objectdbg2_BM( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37));;  
} // end run _2lDiLBXEGvY_3QGIrHwVlgs  
  
// for-up _0tD16ZfI6r2_4QaWuN6poQA #2 :  
if /*cond _10BvirGtJ7c_4nWC6tymo1Z*/   
/*when _3kHUgpOuycP_0n0jO2VY4Dh:*/  
 (/*is_stringv:*/ isstring_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) { //body when _3kHUgpOuycP_0n0jO2VY4Dh   
   
{ // run _0jQHXwEYl0E_6pSxiLZ4MGZ   
/*debug miniscan_stmt°basiclo_outstmt string v_comp ii o_stmt*/
 DBGPRINTF_BM("debug miniscan_stmt°basiclo_outstmt €%.9s string v_comp=%s ii#%ld o_stmt=%s",
 "_0jQHXwEYl0E_6pSxiLZ4MGZ",
 OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
 (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
 objectdbg_BM( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl));;   
} // end run _0jQHXwEYl0E_6pSxiLZ4MGZ   
   
} //endwhen _3kHUgpOuycP_0n0jO2VY4Dh   
else if   
/*when _7gliKK4XRvp_9hHvC2gJHKE:*/  
 (/*isnode:*/isnode_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe))) { //body when _7gliKK4XRvp_9hHvC2gJHKE   
 /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81 = //assign _4yPhtDSXsAM_5IfJKyK2c05    
/*nodeconn:*/nodeconn_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe);   
   
{ // begin objswitch _3WmrD9dWzVs_6l9CVwfdtYt   
//!objswitch! obj-switch o_conn .. miniscan_stmt°basiclo_outstmt .   
 objectval_tyBM* objswexp_3WmrD9dWzVs_6l9CVwfdtYt = ( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81);   
 switch (objecthash_BM (objswexp_3WmrD9dWzVs_6l9CVwfdtYt) % 64) {   
 case 0:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[22] /*|utf8_enc*/)) goto whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z;   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[39] /*|less_indent*/)) goto whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 2:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[56] /*|nlsp*/)) goto whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 5:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[50] /*|c_enc*/)) goto whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 6:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[19] /*|newline*/)) goto whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 11:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[57] /*|object*/)) goto whenobj3WmrD9dW__1wFGt8trU1A_1Nb4JV3o0QV;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 15:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[27] /*|html_enc*/)) goto whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 18:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[18] /*|half_id*/)) goto whenobj3WmrD9dW__1wFGt8trU1A_1Nb4JV3o0QV;   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[32] /*|double_plain*/)) goto whenobj3WmrD9dW__157NBYH3VXp_1nEo0skjEyQ;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 19:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[10] /*|octa*/)) goto whenobj3WmrD9dW__3Q9LapaKOXA_9lQQ7ENfb8d;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 22:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[24] /*|space*/)) goto whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m;   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[42] /*|json_indented*/)) goto whenobj3WmrD9dW__0msPpd1UF1h_6Q13YXMYlaN;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 30:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[2] /*|int*/)) goto whenobj3WmrD9dW__3Q9LapaKOXA_9lQQ7ENfb8d;   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[4] /*|prefixed_lines*/)) goto whenobj3WmrD9dW__3S5MXOVnhRg_2OUoTkvbDYP;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 31:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[55] /*|value*/)) goto whenobj3WmrD9dW__5FrwHPgIxS4_6QYhDVrIvKP;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 34:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[59] /*|hexa*/)) goto whenobj3WmrD9dW__3Q9LapaKOXA_9lQQ7ENfb8d;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 36:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[1] /*|more_indent*/)) goto whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 41:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[23] /*|local_time*/)) goto whenobj3WmrD9dW__157NBYH3VXp_1nEo0skjEyQ;   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[40] /*|literal_c_string*/)) goto whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 42:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[7] /*|name*/)) goto whenobj3WmrD9dW__1wFGt8trU1A_1Nb4JV3o0QV;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 47:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[31] /*|json_compact*/)) goto whenobj3WmrD9dW__0msPpd1UF1h_6Q13YXMYlaN;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 51:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[20] /*|set_indent*/)) goto whenobj3WmrD9dW__3Q9LapaKOXA_9lQQ7ENfb8d;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 54:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[17] /*|double_float*/)) goto whenobj3WmrD9dW__157NBYH3VXp_1nEo0skjEyQ;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 55:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[35] /*|string*/)) goto whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z;   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[58] /*|id*/)) goto whenobj3WmrD9dW__1wFGt8trU1A_1Nb4JV3o0QV;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
   
  default: defobj_3WmrD9dWzVs_6l9CVwfdtYt:;   
   
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt default#0 statement:    
//failure _5J4f6u42le4_9UZMTZziEEw     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
// make_node arg #4 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[43] /*|_5J4f6u42le4_9UZMTZziEEw*/)),
                ((struct stackframe_stBM *) &_));
    
break; // end objswitch _3WmrD9dWzVs_6l9CVwfdtYt default    
// objswitch _3WmrD9dWzVs_6l9CVwfdtYt with 8 whens:    
    
whenobj3WmrD9dW__0msPpd1UF1h_6Q13YXMYlaN:; // when #0 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _0msPpd1UF1h_6Q13YXMYlaN #0 statement:    
if /*cond _9yQol9uXYsR_59RMrumL33A*/     
/*when _2wErgMBgydm_19t3GtzTchr:*/    
 ((/*equal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) == ( 0))) { //body when _2wErgMBgydm_19t3GtzTchr     
//failure _8QmDbXEU8lU_33mrgrh3zUR      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[47] /*!arity*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[62] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _2wErgMBgydm_19t3GtzTchr     
else if     
/*when _5AOCJ23yr6D_7kvbaU8MJQi:*/    
 ((/*greater_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) > ( 2))) { //body when _5AOCJ23yr6D_7kvbaU8MJQi     
//failure _8QmDbXEU8lU_33mrgrh3zUR      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[47] /*!arity*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[62] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _5AOCJ23yr6D_7kvbaU8MJQi     
/*endcond _9yQol9uXYsR_59RMrumL33A*/    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _0msPpd1UF1h_6Q13YXMYlaN #1 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _4osMLGlPBTq_8rkCT8pCoQZ     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _0msPpd1UF1h_6Q13YXMYlaN #2 statement:    
 /*v_expctx:*/_.v_96vo6uBKhke_6E1vyN3kIKD = //assign _33q3zXHuCff_4eYP4unG1XX     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 1));    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _0msPpd1UF1h_6Q13YXMYlaN #3 statement:    
    
{ // run _9ZN4tL5btf4_8In65Qnv7Q0    
/*debug miniscan_stmt°basiclo_outstmt o_conn v_arg v_expctx ii o_stmt o_routprep depth / for json* */
DBGPRINTF_BM("miniscan_stmt°basiclo_outstmt €%.9s o_conn=%s v_arg=%s v_expctx=%s ii#%ld o_stmt=%s o_routprep=%s depth#%ld / for json",
 "_9ZN4tL5btf4_8In65Qnv7Q0",
 objectdbg_BM( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),
 OUTSTRVALUE_BM( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY),
 OUTSTRVALUE_BM( /*v_expctx:*/_.v_96vo6uBKhke_6E1vyN3kIKD),
 (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
 objectdbg1_BM( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),
 objectdbg2_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;    
} // end run _9ZN4tL5btf4_8In65Qnv7Q0    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _0msPpd1UF1h_6Q13YXMYlaN #4 statement:    
 /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I = //assign _4reSlAwcFGJ_7dlcpvtEwM7     
/*miniscan_expr:*/miniscan_expr_BM (( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM);    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _0msPpd1UF1h_6Q13YXMYlaN #5 statement:    
if /*cond _6m3V5fOZK2n_9AFeHjYt2ZV*/     
/*when _3FcUnG66DXT_7sllObXQZl3:*/    
 (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[55] /*!value*/)))) { //body when _3FcUnG66DXT_7sllObXQZl3     
//failure _9umIVqZhssC_2WJZljFrGaA      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[63] /*!failure_type_error*/)), 
 /*make_node 8 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[55] /*!value*/)), 
 
( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[64] /*|_9umIVqZhssC_2WJZljFrGaA*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _3FcUnG66DXT_7sllObXQZl3     
/*endcond _6m3V5fOZK2n_9AFeHjYt2ZV*/    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _0msPpd1UF1h_6Q13YXMYlaN #6 statement:    
if /*cond _3L9x4LFGCuY_3oHKGr2Cr7s*/     
/*when _5Cu0QpuvxD7_8rpyE1LiWIA:*/    
 ( /*v_expctx:*/_.v_96vo6uBKhke_6E1vyN3kIKD) { //body when _5Cu0QpuvxD7_8rpyE1LiWIA     
 /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I = //assign _3sn46xmHUCY_3garOQ6etZ2      
/*miniscan_expr:*/miniscan_expr_BM (( /*v_expctx:*/_.v_96vo6uBKhke_6E1vyN3kIKD), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM);     
if /*cond _6m3V5fOZK2n_9AFeHjYt2ZV*/      
/*when _3FcUnG66DXT_7sllObXQZl3:*/     
 (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[55] /*!value*/)))) { //body when _3FcUnG66DXT_7sllObXQZl3      
//failure _9umIVqZhssC_2WJZljFrGaA       
PLACEDFAILURE_BM(__LINE__,       
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[63] /*!failure_type_error*/)), 
 /*make_node 8 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[55] /*!value*/)), 
 
( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[64] /*|_9umIVqZhssC_2WJZljFrGaA*/)),
                ((struct stackframe_stBM *) &_));
      
} //endwhen _3FcUnG66DXT_7sllObXQZl3      
/*endcond _6m3V5fOZK2n_9AFeHjYt2ZV*/     
     
} //endwhen _5Cu0QpuvxD7_8rpyE1LiWIA     
/*endcond _3L9x4LFGCuY_3oHKGr2Cr7s*/    
    
    
break; // end when _0msPpd1UF1h_6Q13YXMYlaN #0 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
    
whenobj3WmrD9dW__157NBYH3VXp_1nEo0skjEyQ:; // when #1 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _157NBYH3VXp_1nEo0skjEyQ #0 statement:    
if /*cond _0tPLTqqQhJ7_9Tr1hT1PRhR*/     
/*when _2vEPbWPCAJU_1xk1toAGUy4:*/    
 ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 1))) { //body when _2vEPbWPCAJU_1xk1toAGUy4     
//failure _8QmDbXEU8lU_33mrgrh3zUR      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[47] /*!arity*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[62] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _2vEPbWPCAJU_1xk1toAGUy4     
/*endcond _0tPLTqqQhJ7_9Tr1hT1PRhR*/    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _157NBYH3VXp_1nEo0skjEyQ #1 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _4osMLGlPBTq_8rkCT8pCoQZ     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _157NBYH3VXp_1nEo0skjEyQ #2 statement:    
 /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I = //assign _4reSlAwcFGJ_7dlcpvtEwM7     
/*miniscan_expr:*/miniscan_expr_BM (( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM);    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _157NBYH3VXp_1nEo0skjEyQ #3 statement:    
if /*cond _662Hp5KuXpF_9TsL9wOchLw*/     
/*when _7aBjoERVXzl_1NNbIyjvx42:*/    
 (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[17] /*!double_float*/)))) { //body when _7aBjoERVXzl_1NNbIyjvx42     
//failure _4WkaKNhBpsa_9VlfEzlClhm      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[63] /*!failure_type_error*/)), 
 /*make_node 8 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[17] /*!double_float*/)), 
 
( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[36] /*|_4WkaKNhBpsa_9VlfEzlClhm*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _7aBjoERVXzl_1NNbIyjvx42     
/*endcond _662Hp5KuXpF_9TsL9wOchLw*/    
    
    
break; // end when _157NBYH3VXp_1nEo0skjEyQ #1 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
    
whenobj3WmrD9dW__1wFGt8trU1A_1Nb4JV3o0QV:; // when #2 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _1wFGt8trU1A_1Nb4JV3o0QV #0 statement:    
if /*cond _0tPLTqqQhJ7_9Tr1hT1PRhR*/     
/*when _2vEPbWPCAJU_1xk1toAGUy4:*/    
 ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 1))) { //body when _2vEPbWPCAJU_1xk1toAGUy4     
//failure _8QmDbXEU8lU_33mrgrh3zUR      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[47] /*!arity*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[62] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _2vEPbWPCAJU_1xk1toAGUy4     
/*endcond _0tPLTqqQhJ7_9Tr1hT1PRhR*/    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _1wFGt8trU1A_1Nb4JV3o0QV #1 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _4osMLGlPBTq_8rkCT8pCoQZ     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _1wFGt8trU1A_1Nb4JV3o0QV #2 statement:    
 /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I = //assign _4reSlAwcFGJ_7dlcpvtEwM7     
/*miniscan_expr:*/miniscan_expr_BM (( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM);    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _1wFGt8trU1A_1Nb4JV3o0QV #3 statement:    
if /*cond _6wbaBUuIONg_9YGzdsfJjeb*/     
/*when _3dZuGA19JWs_2g4uoKzoqro:*/    
 (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[57] /*!object*/)))) { //body when _3dZuGA19JWs_2g4uoKzoqro     
//failure _2eREyARXfUb_2mTxUngIL6Y      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[63] /*!failure_type_error*/)), 
 /*make_node 8 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[57] /*!object*/)), 
 
( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[15] /*|_2eREyARXfUb_2mTxUngIL6Y*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _3dZuGA19JWs_2g4uoKzoqro     
/*endcond _6wbaBUuIONg_9YGzdsfJjeb*/    
    
    
break; // end when _1wFGt8trU1A_1Nb4JV3o0QV #2 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
    
whenobj3WmrD9dW__3Q9LapaKOXA_9lQQ7ENfb8d:; // when #3 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _3Q9LapaKOXA_9lQQ7ENfb8d #0 statement:    
if /*cond _0tPLTqqQhJ7_9Tr1hT1PRhR*/     
/*when _2vEPbWPCAJU_1xk1toAGUy4:*/    
 ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 1))) { //body when _2vEPbWPCAJU_1xk1toAGUy4     
//failure _8QmDbXEU8lU_33mrgrh3zUR      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[47] /*!arity*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[62] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _2vEPbWPCAJU_1xk1toAGUy4     
/*endcond _0tPLTqqQhJ7_9Tr1hT1PRhR*/    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _3Q9LapaKOXA_9lQQ7ENfb8d #1 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _4osMLGlPBTq_8rkCT8pCoQZ     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _3Q9LapaKOXA_9lQQ7ENfb8d #2 statement:    
 /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I = //assign _4reSlAwcFGJ_7dlcpvtEwM7     
/*miniscan_expr:*/miniscan_expr_BM (( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM);    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _3Q9LapaKOXA_9lQQ7ENfb8d #3 statement:    
if /*cond _8oSBVSRNj1v_3bsqcnGUWLD*/     
/*when _8dLGLcW3TGC_4jPYDTI7ixi:*/    
 (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[2] /*!int*/)))) { //body when _8dLGLcW3TGC_4jPYDTI7ixi     
//failure _26UbzubL5aT_2vDJc23p59r      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[63] /*!failure_type_error*/)), 
 /*make_node 8 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[2] /*!int*/)), 
 
( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[14] /*|_26UbzubL5aT_2vDJc23p59r*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _8dLGLcW3TGC_4jPYDTI7ixi     
/*endcond _8oSBVSRNj1v_3bsqcnGUWLD*/    
    
    
break; // end when _3Q9LapaKOXA_9lQQ7ENfb8d #3 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
    
whenobj3WmrD9dW__3S5MXOVnhRg_2OUoTkvbDYP:; // when #4 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _3S5MXOVnhRg_2OUoTkvbDYP #0 statement:    
if /*cond _5H81hkR38QC_0dH3bxpWZjc*/     
/*when _8ZHaOXIAYpR_5zTFuaj29yH:*/    
 ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 2))) { //body when _8ZHaOXIAYpR_5zTFuaj29yH     
//failure _8QmDbXEU8lU_33mrgrh3zUR      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[47] /*!arity*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[62] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _8ZHaOXIAYpR_5zTFuaj29yH     
/*endcond _5H81hkR38QC_0dH3bxpWZjc*/    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _3S5MXOVnhRg_2OUoTkvbDYP #1 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _4osMLGlPBTq_8rkCT8pCoQZ     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _3S5MXOVnhRg_2OUoTkvbDYP #2 statement:    
 /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I = //assign _4reSlAwcFGJ_7dlcpvtEwM7     
/*miniscan_expr:*/miniscan_expr_BM (( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM);    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _3S5MXOVnhRg_2OUoTkvbDYP #3 statement:    
if /*cond _6cOi4TgZpEg_7mN9SsWpWte*/     
/*when _9BPjp8ame7V_0AzorRD9WNm:*/    
 (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[35] /*!string*/)))) { //body when _9BPjp8ame7V_0AzorRD9WNm     
//failure _4HAZLawO9HO_91oo1k4Ajat      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[63] /*!failure_type_error*/)), 
 /*make_node 8 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[35] /*!string*/)), 
 
( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[34] /*|_4HAZLawO9HO_91oo1k4Ajat*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _9BPjp8ame7V_0AzorRD9WNm     
/*endcond _6cOi4TgZpEg_7mN9SsWpWte*/    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _3S5MXOVnhRg_2OUoTkvbDYP #4 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _9dzhW0pXvXk_42iYvzbccd3     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 1));    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _3S5MXOVnhRg_2OUoTkvbDYP #5 statement:    
 /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I = //assign _4reSlAwcFGJ_7dlcpvtEwM7     
/*miniscan_expr:*/miniscan_expr_BM (( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM);    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _3S5MXOVnhRg_2OUoTkvbDYP #6 statement:    
if /*cond _6cOi4TgZpEg_7mN9SsWpWte*/     
/*when _9BPjp8ame7V_0AzorRD9WNm:*/    
 (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[35] /*!string*/)))) { //body when _9BPjp8ame7V_0AzorRD9WNm     
//failure _4HAZLawO9HO_91oo1k4Ajat      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[63] /*!failure_type_error*/)), 
 /*make_node 8 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[35] /*!string*/)), 
 
( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[34] /*|_4HAZLawO9HO_91oo1k4Ajat*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _9BPjp8ame7V_0AzorRD9WNm     
/*endcond _6cOi4TgZpEg_7mN9SsWpWte*/    
    
    
break; // end when _3S5MXOVnhRg_2OUoTkvbDYP #4 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
    
whenobj3WmrD9dW__5FrwHPgIxS4_6QYhDVrIvKP:; // when #5 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _5FrwHPgIxS4_6QYhDVrIvKP #0 statement:    
if /*cond _0tPLTqqQhJ7_9Tr1hT1PRhR*/     
/*when _2vEPbWPCAJU_1xk1toAGUy4:*/    
 ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 1))) { //body when _2vEPbWPCAJU_1xk1toAGUy4     
//failure _8QmDbXEU8lU_33mrgrh3zUR      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[47] /*!arity*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[62] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _2vEPbWPCAJU_1xk1toAGUy4     
/*endcond _0tPLTqqQhJ7_9Tr1hT1PRhR*/    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _5FrwHPgIxS4_6QYhDVrIvKP #1 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _4osMLGlPBTq_8rkCT8pCoQZ     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _5FrwHPgIxS4_6QYhDVrIvKP #2 statement:    
 /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I = //assign _4reSlAwcFGJ_7dlcpvtEwM7     
/*miniscan_expr:*/miniscan_expr_BM (( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM);    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _5FrwHPgIxS4_6QYhDVrIvKP #3 statement:    
if /*cond _6m3V5fOZK2n_9AFeHjYt2ZV*/     
/*when _3FcUnG66DXT_7sllObXQZl3:*/    
 (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[55] /*!value*/)))) { //body when _3FcUnG66DXT_7sllObXQZl3     
//failure _9umIVqZhssC_2WJZljFrGaA      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[63] /*!failure_type_error*/)), 
 /*make_node 8 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[55] /*!value*/)), 
 
( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[64] /*|_9umIVqZhssC_2WJZljFrGaA*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _3FcUnG66DXT_7sllObXQZl3     
/*endcond _6m3V5fOZK2n_9AFeHjYt2ZV*/    
    
    
break; // end when _5FrwHPgIxS4_6QYhDVrIvKP #5 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
    
whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m:; // when #6 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _88RDzd8IqdR_360tNT6O81m #0 statement:    
if /*cond _5Z3dh9fajGI_8Mjr3quXaAc*/     
/*when _2ahnIdkMBrO_2xvuzm6XiD6:*/    
 ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 0))) { //body when _2ahnIdkMBrO_2xvuzm6XiD6     
//failure _8QmDbXEU8lU_33mrgrh3zUR      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[47] /*!arity*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[62] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _2ahnIdkMBrO_2xvuzm6XiD6     
/*endcond _5Z3dh9fajGI_8Mjr3quXaAc*/    
    
    
break; // end when _88RDzd8IqdR_360tNT6O81m #6 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
    
whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z:; // when #7 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _8v0XmN9JZTY_0xJ6ntfrc0z #0 statement:    
if /*cond _0tPLTqqQhJ7_9Tr1hT1PRhR*/     
/*when _2vEPbWPCAJU_1xk1toAGUy4:*/    
 ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 1))) { //body when _2vEPbWPCAJU_1xk1toAGUy4     
//failure _8QmDbXEU8lU_33mrgrh3zUR      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[47] /*!arity*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[62] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _2vEPbWPCAJU_1xk1toAGUy4     
/*endcond _0tPLTqqQhJ7_9Tr1hT1PRhR*/    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _8v0XmN9JZTY_0xJ6ntfrc0z #1 statement:    
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _4osMLGlPBTq_8rkCT8pCoQZ     
/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _8v0XmN9JZTY_0xJ6ntfrc0z #2 statement:    
 /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I = //assign _4reSlAwcFGJ_7dlcpvtEwM7     
/*miniscan_expr:*/miniscan_expr_BM (( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM);    
    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _8v0XmN9JZTY_0xJ6ntfrc0z #3 statement:    
if /*cond _6cOi4TgZpEg_7mN9SsWpWte*/     
/*when _9BPjp8ame7V_0AzorRD9WNm:*/    
 (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[35] /*!string*/)))) { //body when _9BPjp8ame7V_0AzorRD9WNm     
//failure _4HAZLawO9HO_91oo1k4Ajat      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[63] /*!failure_type_error*/)), 
 /*make_node 8 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[35] /*!string*/)), 
 
( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[34] /*|_4HAZLawO9HO_91oo1k4Ajat*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _9BPjp8ame7V_0AzorRD9WNm     
/*endcond _6cOi4TgZpEg_7mN9SsWpWte*/    
    
    
break; // end when _8v0XmN9JZTY_0xJ6ntfrc0z #7 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
   
} } // end objswitch _3WmrD9dWzVs_6l9CVwfdtYt   
   
} //endwhen _7gliKK4XRvp_9hHvC2gJHKE   
/*endcond _10BvirGtJ7c_4nWC6tymo1Z*/  
  
// for-up _0tD16ZfI6r2_4QaWuN6poQA #3 :  
  
{ // run _5D1l5MRqI8v_7r77JwJEhQz  
/*debug miniscan_stmt°basiclo_outstmt handled v_comp ii o_stmt o_routprep depth o_from*/
DBGPRINTF_BM("miniscan_stmt°basiclo_outstmt €%.9s handled v_comp=%s ii#%ld o_stmt=%s o_routprep=%s depth#%ld o_from=%s\n",
 "_5D1l5MRqI8v_7r77JwJEhQz",
 OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
 (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
 objectdbg_BM( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),
 objectdbg1_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
 objectdbg2_BM( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37));
;  
} // end run _5D1l5MRqI8v_7r77JwJEhQz  
 
}} // end for-up _0tD16ZfI6r2_4QaWuN6poQA 
 
 
{ // run _5Tgt53DTTR4_2cLi9xyVDWE 
/*debug miniscan_stmt°basiclo_outstmt end o_stmt o_routprep depth o_from*/
DBGPRINTF_BM("miniscan_stmt°basiclo_outstmt end €%.9s o_stmt=%s o_routprep=%s depth#%ld o_from=%s",
 "_5Tgt53DTTR4_2cLi9xyVDWE",
 objectdbg_BM( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),
 objectdbg1_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
 (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
 objectdbg2_BM( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37));; 
} // end run _5Tgt53DTTR4_2cLi9xyVDWE 
 
 
/*return _6eMTc045d3X_9tGa3wPlS7e:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl; 
 goto epilog_1kz7viwMzTp_6PgLhdZzMEy; 
 
/* !endingblock _2z5wZyWhJId_3qRwMQOiLBm */ 
goto endblock__2z5wZyWhJId_3qRwMQOiLBm; 
endblock__2z5wZyWhJId_3qRwMQOiLBm: ; 
} /*-block _2z5wZyWhJId_3qRwMQOiLBm */

 epilog_1kz7viwMzTp_6PgLhdZzMEy: __attribute__ ((unused)); // routine _1kz7viwMzTp_6PgLhdZzMEy epilogue:
   // unlocking 1:
    if (locked_1mO4b6i93tJ_8qQI7qdBqdy != NULL)
       objunlock_BM(locked_1mO4b6i93tJ_8qQI7qdBqdy), locked_1mO4b6i93tJ_8qQI7qdBqdy = NULL; // for o_varout
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _1kz7viwMzTp_6PgLhdZzMEy routine#2 _1kz7viwMzTp_6PgLhdZzMEy




value_tyBM crout_85xjvzYjcd6_9mNZNPF6i2J_BM //#3
 (struct stackframe_stBM* stkf, //
//!miniscan_stmt°basiclo_countloop < o_stmt (o_routprep v_depth o_from)
  // 4 arguments
  const value_tyBM arg0,  // o_stmt
  const value_tyBM arg1,  // o_routprep
  const value_tyBM arg2,  // v_depth
  const value_tyBM arg3,  // o_from
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _85xjvzYjcd6_9mNZNPF6i2J
  struct frame_85xjvzYjcd6_9mNZNPF6i2J_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 11 local values:
    objectval_tyBM* o_1NOlyGkbWyD_5JUfiTznxM2; // o_substmt
    objectval_tyBM* o_2nKz6bXzYe0_5F1HxV9bQRu; // o_typindex
    objectval_tyBM* o_34Qtvf1thwK_9rziG6sk6Vl; // o_stmt
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_48tt3ewgFzG_8U9hwUq2GY6; // o_typcount
    value_tyBM v_4leeeoANgjm_31PbCGhynlU; // v_countexp
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    objectval_tyBM* o_4QkDiZYXmJR_8VofvgKqcu4; // o_varindex
    value_tyBM v_5wKdFyGNJ5j_50nIjxm7LLY; // v_scanres
    objectval_tyBM* o_6RpSqxAOt2p_35laNqeU6KH; // o_routprep
    objectval_tyBM* o_89nz0KaXXZh_8eSgMmqnK37; // o_from
    /// 3 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
   } _;
   memset (&_, 0, sizeof(struct frame_85xjvzYjcd6_9mNZNPF6i2J_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 11;
   _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[60] /*|_85xjvzYjcd6_9mNZNPF6i2J*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // locking 1:
    objectval_tyBM* locked_5pCnYlCZrUY_5zgmm9wjYdu = NULL; // for o_substmt
   // fetch 4 arguments:
   _.o_34Qtvf1thwK_9rziG6sk6Vl = objectcast_BM (arg0); // o_stmt
   _.o_6RpSqxAOt2p_35laNqeU6KH = objectcast_BM (arg1); // o_routprep
   _.v_4nJKFtMqlkA_1teQSqofNux = arg2; // v_depth
   _.o_89nz0KaXXZh_8eSgMmqnK37 = objectcast_BM (arg3); // o_from
   // fetched 4 arguments.
   // no closed values in _85xjvzYjcd6_9mNZNPF6i2J.
   const closure_tyBM* callclos_85xjvzYjcd6_9mNZNPF6i2J __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_85xjvzYjcd6_9mNZNPF6i2J  __attribute__((unused)) = 0;
   // routine _85xjvzYjcd6_9mNZNPF6i2J body:

startblock__0knuZ8Npcw8_6Jj2YIvenZB: __attribute__((unused));
{ /* +block _0knuZ8Npcw8_6Jj2YIvenZB */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _74XT4f1vWl9_7pfkRaZCCjn  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4 = //assign _9pqI2UGxUWS_2CBJ8rAZ82i  
/*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[52] /*!index*/)))); 
 
//+ #2/15 of block _0knuZ8Npcw8_6Jj2YIvenZB :: 
 
 /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU = //assign _3432lagVKwU_591r9WA1UM7  
/*objgetattr:*/objgetattr_BM(( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[44] /*!count*/))); 
 
 
 
{ // run _87LNOwdCnqL_9Z0b3QKGp5B 
/*debug miniscan_stmt°basiclo_countloop start o_stmt o_routprep depth o_from o_varindex v_countexp*/
  DBGPRINTF_BM("miniscan_stmt°basiclo_countloop start €%.9s o_stmt=%s o_routprep=%s depth#%ld o_from=%s o_varindex=%s v_countexp=%s",
   "_87LNOwdCnqL_9Z0b3QKGp5B",
   objectdbg_BM( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),
   objectdbg1_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
   (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
   objectdbg2_BM( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37),
   objectdbg3_BM( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4),
   OUTSTRVALUE_BM( /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU));; 
} // end run _87LNOwdCnqL_9Z0b3QKGp5B 
 
//+ #4/15 of block _0knuZ8Npcw8_6Jj2YIvenZB :: 
 
 /*o_typcount:*/_.o_48tt3ewgFzG_8U9hwUq2GY6 = //assign _0pg30NIiY38_4OYvjSkm7he  
/*miniscan_expr:*/miniscan_expr_BM (( /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM); 
 
 
 
{ // run _3PEOwbhRvWp_6hH8N2yKT9y 
/*debug miniscan_stmt°basiclo_countloop o_typcount v_countexp depth o_routprep*/
DBGPRINTF_BM("miniscan_stmt°basiclo_countloop €%.9s o_typcount=%s for v_countexp=%s depth#%ld o_routprep=%s",
 "_3PEOwbhRvWp_6hH8N2yKT9y",
 objectdbg_BM( /*o_typcount:*/_.o_48tt3ewgFzG_8U9hwUq2GY6),
 OUTSTRVALUE_BM( /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
 objectdbg1_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH));; 
} // end run _3PEOwbhRvWp_6hH8N2yKT9y 
 
//+ #6/15 of block _0knuZ8Npcw8_6Jj2YIvenZB :: 
 
if /*cond _7KmS6tYm3q4_1IcuMa7JPp8*/  
/*when _8Qv6mNnpd1C_5xmOXXiwNGC:*/ 
 (/*unequal_object:*/(( /*o_typcount:*/_.o_48tt3ewgFzG_8U9hwUq2GY6) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[2] /*!int*/)))) { //body when _8Qv6mNnpd1C_5xmOXXiwNGC  
//failure _6Rc660mzjXf_6rWF1nupKVt   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[63] /*!failure_type_error*/)), 
 /*make_node 7 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[44] /*!count*/)), 
 
( /*o_typcount:*/_.o_48tt3ewgFzG_8U9hwUq2GY6), 
 
( /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[54] /*|_6Rc660mzjXf_6rWF1nupKVt*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _8Qv6mNnpd1C_5xmOXXiwNGC  
/*endcond _7KmS6tYm3q4_1IcuMa7JPp8*/ 
 
 
 /*o_typindex:*/_.o_2nKz6bXzYe0_5F1HxV9bQRu = //assign _0ULwQ3GvZnM_9zrslX7LdFF  
/*miniscan_var:*/ miniscan_var_BM (( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM); 
 
//+ #8/15 of block _0knuZ8Npcw8_6Jj2YIvenZB :: 
 
 
{ // run _9kNbtEAA7uz_7q5zk1aGoci 
/*debug miniscan_stmt°basiclo_countloop o_typindex o_varindex depth o_routprep*/
DBGPRINTF_BM("miniscan_stmt°basiclo_countloop €%.9s o_typindex=%s for o_varindex=%s depth#%ld o_routprep=%s",
 "_9kNbtEAA7uz_7q5zk1aGoci",
 objectdbg_BM( /*o_typindex:*/_.o_2nKz6bXzYe0_5F1HxV9bQRu),
 objectdbg1_BM( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
 objectdbg2_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH));; 
} // end run _9kNbtEAA7uz_7q5zk1aGoci 
 
 
if /*cond _9TZl5n6VpSi_23EyCgDDXIV*/  
/*when _25gAJE4HRuv_89hQbm1jNh8:*/ 
 (/*unequal_object:*/(( /*o_typindex:*/_.o_2nKz6bXzYe0_5F1HxV9bQRu) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[2] /*!int*/)))) { //body when _25gAJE4HRuv_89hQbm1jNh8  
//failure _5zaZ8sDu1TQ_49hqJMJDKIq   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[63] /*!failure_type_error*/)), 
 /*make_node 7 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[52] /*!index*/)), 
 
( /*o_typindex:*/_.o_2nKz6bXzYe0_5F1HxV9bQRu), 
 
( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[41] /*|_5zaZ8sDu1TQ_49hqJMJDKIq*/)),
                ((struct stackframe_stBM *) &_));
  
} //endwhen _25gAJE4HRuv_89hQbm1jNh8  
/*endcond _9TZl5n6VpSi_23EyCgDDXIV*/ 
 
//+ #10/15 of block _0knuZ8Npcw8_6Jj2YIvenZB :: 
 
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _3B2nXC7wOSF_59wekNL1jnX  
/*objnbcomps:*/ objnbcomps_BM ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl); 
 
 
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _9j4OGu2G78c_835xhA3kBqS  
 0; 
 
//+ #12/15 of block _0knuZ8Npcw8_6Jj2YIvenZB :: 
 
 
//// +while _5BJGeu6Rib0_1jHW94atiIm 
startblock__5BJGeu6Rib0_1jHW94atiIm:  /*+!while*/; 
{ /* +while _5BJGeu6Rib0_1jHW94atiIm */  
if (!(/*while _5BJGeu6Rib0_1jHW94atiIm cond:*/ (/*less_int:*/( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) < ( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k)))) //: testwhile _5BJGeu6Rib0_1jHW94atiIm failing   
  goto endblock__5BJGeu6Rib0_1jHW94atiIm; //failwhile   
// while _5BJGeu6Rib0_1jHW94atiIm body:   
// while _5BJGeu6Rib0_1jHW94atiIm comp#0:  
 /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2 = //assign _6kPpR9K4hYf_4vVcztNjQgZ   
/*val_to_object:*/objectcast_BM(/*objgetcomp:*/objgetcomp_BM (( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)));  
// while _5BJGeu6Rib0_1jHW94atiIm comp#1:  
  
{ // run _2cjXG3IXlV2_5AQnd3JjO3Y  
/*debug miniscan_stmt°basiclo_countloop o_substmt ii o_stmt o_routprep depth*/
DBGPRINTF_BM("miniscan_stmt°basiclo_countloop €%.9s o_substmt=%s ii#%ld o_stmt=%s o_routprep=%s depth#%ld",
 "_2cjXG3IXlV2_5AQnd3JjO3Y",
  objectdbg_BM( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2),
  (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
  objectdbg1_BM( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),
  objectdbg2_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
  (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
;  
} // end run _2cjXG3IXlV2_5AQnd3JjO3Y  
// while _5BJGeu6Rib0_1jHW94atiIm comp#2:  
if /*cond _1ibJngatIV4_0zFDxkfo8GR*/   
/*when _7lA4UB4g8lU_55OVWFQNpIA:*/  
 ( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2) { //body when _7lA4UB4g8lU_55OVWFQNpIA   
   
{ // begin lockobj _5pCnYlCZrUY_5zgmm9wjYdu   
  objectval_tyBM* curlockedob_5pCnYlCZrUY_5zgmm9wjYdu = ( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2);   
if (objlock_BM (curlockedob_5pCnYlCZrUY_5zgmm9wjYdu)) {    
locked_5pCnYlCZrUY_5zgmm9wjYdu = curlockedob_5pCnYlCZrUY_5zgmm9wjYdu;    
    
if /*cond _8GpBvvm7FCj_8MezDXgKCOe*/    
/*when _2Hvz5h8r9Av_3Yv9HV7md5M:*/   
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[30] /*!basiclo_statement*/)))) { //body when _2Hvz5h8r9Av_3Yv9HV7md5M    
 /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY = //assign _8sgR7i31pzL_42EKpWujqoM     
(send3_BM (( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2), /*sel:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[51] /*!miniscan_stmt*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1)))), 
 ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl)));    
if /*cond _4vZIvqj37yD_8V1cygCMbVf*/     
/*when _65JCkS6AuG7_6tVxePro2Ph:*/    
 (/*is_null:*/(( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY)==NULL)) { //body when _65JCkS6AuG7_6tVxePro2Ph     
//failure _227kofebdwq_9fj8R3qXt7B      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[60] /*!_85xjvzYjcd6_9mNZNPF6i2J*/)), 
 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[51] /*!miniscan_stmt*/)), 
 
( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[13] /*|_227kofebdwq_9fj8R3qXt7B*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _65JCkS6AuG7_6tVxePro2Ph     
/*endcond _4vZIvqj37yD_8V1cygCMbVf*/    
    
} //endwhen _2Hvz5h8r9Av_3Yv9HV7md5M    
else if    
/*when _8UhAB14P5OV_4SzOu2Seitj:*/   
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[29] /*!basiclo_block*/)))) { //body when _8UhAB14P5OV_4SzOu2Seitj    
 /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY = //assign _86xNO9NKgrq_1i3ph3xKuZk     
(send3_BM (( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2), /*sel:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[16] /*!miniscan_block*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1)))), 
 ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl)));    
if /*cond _7vA3sGtaCEa_4clk6xjbqLS*/     
/*when _2WH4J5GZlQ7_3gpZRxe8LNm:*/    
 (/*is_null:*/(( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY)==NULL)) { //body when _2WH4J5GZlQ7_3gpZRxe8LNm     
//failure _5oVb4fNe3eO_4GyCgc0vkQp      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[60] /*!_85xjvzYjcd6_9mNZNPF6i2J*/)), 
 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[16] /*!miniscan_block*/)), 
 
( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[38] /*|_5oVb4fNe3eO_4GyCgc0vkQp*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _2WH4J5GZlQ7_3gpZRxe8LNm     
/*endcond _7vA3sGtaCEa_4clk6xjbqLS*/    
    
} //endwhen _8UhAB14P5OV_4SzOu2Seitj    
else { /*cond else _8GpBvvm7FCj_8MezDXgKCOe*/    
//failure _0HZ6LhCuD3B_3wOqehpkD81    
PLACEDFAILURE_BM(__LINE__,    
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[33] /*!failure_bad_class*/)), 
 /*make_node 6 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[60] /*!_85xjvzYjcd6_9mNZNPF6i2J*/)), 
 
( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[6] /*|_0HZ6LhCuD3B_3wOqehpkD81*/)),
                ((struct stackframe_stBM *) &_));
} /*cond else _8GpBvvm7FCj_8MezDXgKCOe*/    
/*endcond _8GpBvvm7FCj_8MezDXgKCOe*/   
    
objunlock_BM (locked_5pCnYlCZrUY_5zgmm9wjYdu), locked_5pCnYlCZrUY_5zgmm9wjYdu = NULL;   
} } // end objlock _5pCnYlCZrUY_5zgmm9wjYdu   
   
} //endwhen _7lA4UB4g8lU_55OVWFQNpIA   
/*endcond _1ibJngatIV4_0zFDxkfo8GR*/  
// while _5BJGeu6Rib0_1jHW94atiIm comp#3:  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _9joCoPDJZPz_78kcVz01COq   
/*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1));  
  
goto startblock__5BJGeu6Rib0_1jHW94atiIm; // repeatwhile  
endblock__5BJGeu6Rib0_1jHW94atiIm: /*endingwhile*/;  
} /*-endwhile _5BJGeu6Rib0_1jHW94atiIm */ 
 
 
 
 
{ // run _3VHKozAi0fc_0sPZAQQdLWv 
/*debug miniscan_stmt°basiclo_countloop end o_stmt o_routprep depth*/
DBGPRINTF_BM("miniscan_stmt°basiclo_countloop end €%.9s o_stmt=%s o_routprep=%s depth#%ld",
 "_3VHKozAi0fc_0sPZAQQdLWv",
 objectdbg_BM( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),
 objectdbg1_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _3VHKozAi0fc_0sPZAQQdLWv 
 
 
/*return _6gr47UobaET_13RD7eynIoK:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl; 
 goto epilog_85xjvzYjcd6_9mNZNPF6i2J; 
 
/* !endingblock _0knuZ8Npcw8_6Jj2YIvenZB */ 
goto endblock__0knuZ8Npcw8_6Jj2YIvenZB; 
endblock__0knuZ8Npcw8_6Jj2YIvenZB: ; 
} /*-block _0knuZ8Npcw8_6Jj2YIvenZB */

 epilog_85xjvzYjcd6_9mNZNPF6i2J: __attribute__ ((unused)); // routine _85xjvzYjcd6_9mNZNPF6i2J epilogue:
   // unlocking 1:
    if (locked_5pCnYlCZrUY_5zgmm9wjYdu != NULL)
       objunlock_BM(locked_5pCnYlCZrUY_5zgmm9wjYdu), locked_5pCnYlCZrUY_5zgmm9wjYdu = NULL; // for o_substmt
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _85xjvzYjcd6_9mNZNPF6i2J routine#3 _85xjvzYjcd6_9mNZNPF6i2J




value_tyBM crout_8NgOdlJACWN_8pbYZXkHpCj_BM //#4
 (struct stackframe_stBM* stkf, //
//!emit_block°basiclo_for_down_loop  < o_block (o_modgen o_routprep v_depth)
  // 4 arguments
  const value_tyBM arg0,  // o_block
  const value_tyBM arg1,  // o_modgen
  const value_tyBM arg2,  // o_routprep
  const value_tyBM arg3,  // v_depth
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _8NgOdlJACWN_8pbYZXkHpCj
  struct frame_8NgOdlJACWN_8pbYZXkHpCj_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 9 local values:
    value_tyBM v_0qTBOEAT5pa_2fz1SKfHrMV; // v_resemit
    objectval_tyBM* o_2RUj1oyJ2rf_1ICZWr844Sv; // o_modgen
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    value_tyBM v_4leeeoANgjm_31PbCGhynlU; // v_countexp
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    objectval_tyBM* o_4QkDiZYXmJR_8VofvgKqcu4; // o_varindex
    objectval_tyBM* o_5XGKMg1Kevs_6eAce4ib9XW; // o_block
    objectval_tyBM* o_6RpSqxAOt2p_35laNqeU6KH; // o_routprep
    objectval_tyBM* o_6Z4UU939WbU_8BK9xcKsXNb; // o_comp
    /// 3 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
   } _;
   memset (&_, 0, sizeof(struct frame_8NgOdlJACWN_8pbYZXkHpCj_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 9;
   _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*|_8NgOdlJACWN_8pbYZXkHpCj*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // locking 2:
    objectval_tyBM* locked_0Wp7h8yI3oe_8LDnl3npXfl = NULL; // for o_comp
    objectval_tyBM* locked_4a5PI4Gi0yN_0Vg2cbkuXjE = NULL; // for o_block
   // fetch 4 arguments:
   _.o_5XGKMg1Kevs_6eAce4ib9XW = objectcast_BM (arg0); // o_block
   _.o_2RUj1oyJ2rf_1ICZWr844Sv = objectcast_BM (arg1); // o_modgen
   _.o_6RpSqxAOt2p_35laNqeU6KH = objectcast_BM (arg2); // o_routprep
   _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
   // fetched 4 arguments.
   // no closed values in _8NgOdlJACWN_8pbYZXkHpCj.
   const closure_tyBM* callclos_8NgOdlJACWN_8pbYZXkHpCj __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_8NgOdlJACWN_8pbYZXkHpCj  __attribute__((unused)) = 0;
   // routine _8NgOdlJACWN_8pbYZXkHpCj body:

startblock__0V7X1Z5gIQp_4SZI2S9RSG0: __attribute__((unused));
{ /* +block _0V7X1Z5gIQp_4SZI2S9RSG0 */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _1MOZNoNsgVi_3UmtfBE7TEv  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 
{ // run _79GhuWKrhVL_5bSNNKWwje4 
/*debug emit_block°basiclo_for_down_loop  start o_block o_modgen o_routprep depth*/
DBGPRINTF_BM("emit_block°basiclo_for_down_loop  start €%.9s o_block=%s o_modgen=%s/L%u o_routprep=%s depth#%ld",
 "_79GhuWKrhVL_5bSNNKWwje4",
 objectdbg_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),
 objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
 objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
 objectdbg2_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));; 
} // end run _79GhuWKrhVL_5bSNNKWwje4 
 
 
 
{ // begin lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE 
  objectval_tyBM* curlockedob_4a5PI4Gi0yN_0Vg2cbkuXjE = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW); 
if (objlock_BM (curlockedob_4a5PI4Gi0yN_0Vg2cbkuXjE)) {  
locked_4a5PI4Gi0yN_0Vg2cbkuXjE = curlockedob_4a5PI4Gi0yN_0Vg2cbkuXjE;  
  
 /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4 = //assign _0ueKJsCvh64_2RNLZqdlw0A  
/*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[52] /*!index*/)))); 
  
 /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU = //assign _5seYtoR5pxJ_37Qi2lVAneY  
/*objgetattr:*/objgetattr_BM(( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[44] /*!count*/))); 
  
//+ #2/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::  
 
{ // run _1mTrwgoPbKF_8mcsO9qzS13 
/*debug emit_block°basiclo_for_down_loop o_varindex v_countexp o_block o_modgen*/
DBGPRINTF_BM("emit_block°basiclo_for_down_loop €%.9s o_varindex=%s v_countexp=%s o_block=%s o_modgen=%s/L%u",
 "_1mTrwgoPbKF_8mcsO9qzS13",
 objectdbg_BM( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4),
 OUTSTRVALUE_BM( /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU),
 objectdbg1_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),
 objectdbg2_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
 objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv)
); ; 
} // end run _1mTrwgoPbKF_8mcsO9qzS13 
  
{ // start cexpansion _5hGkE3qmw8e_3lVUu6wesD5 - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "{ //for-down "));  
} // end cexpansion _5hGkE3qmw8e_3lVUu6wesD5 - objstrbufferappendcstrpayl  
  
//+ #4/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::  
{ // start cexpansion _2xnAOqlCcPw_5Bzey6lbzTC - objstrbufferprintobject  
/*objstrbufferprintobject _2xnAOqlCcPw_5Bzey6lbzTC:*/
 objectval_tyBM* obsbuf_2xnAOqlCcPw_5Bzey6lbzTC = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
 objectval_tyBM* ob_2xnAOqlCcPw_5Bzey6lbzTC = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
 if (objhasstrbufferpayl_BM(obsbuf_2xnAOqlCcPw_5Bzey6lbzTC) && isobject_BM(ob_2xnAOqlCcPw_5Bzey6lbzTC))
  objstrbufferappendcstrpayl_BM(obsbuf_2xnAOqlCcPw_5Bzey6lbzTC, objectdbg_BM(ob_2xnAOqlCcPw_5Bzey6lbzTC));
// end objstrbufferprintobject _2xnAOqlCcPw_5Bzey6lbzTC
;  
} // end cexpansion _2xnAOqlCcPw_5Bzey6lbzTC - objstrbufferprintobject  
  
{ // start cexpansion _9oPXYiXVx3z_4QMTusazjXN - objstrbuffersetindentpayl  
/*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));   
} // end cexpansion _9oPXYiXVx3z_4QMTusazjXN - objstrbuffersetindentpayl   
  
//+ #6/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::  
{ // start cexpansion _9aqYHQ1DxPz_1yUEPlMNMi3 - objstrbuffernewlinepayl  
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);  
} // end cexpansion _9aqYHQ1DxPz_1yUEPlMNMi3 - objstrbuffernewlinepayl  
  
{ // start cexpansion _3zgSe1zf9an_9zcqOCriaRf - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "intptr_t cnt"));  
} // end cexpansion _3zgSe1zf9an_9zcqOCriaRf - objstrbufferappendcstrpayl  
  
//+ #8/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::  
{ // start cexpansion _9pAN1UadjT9_4HQXK5j1f2m - objstrbufferprintobjid  
/*objstrbufferprintobjid _9pAN1UadjT9_4HQXK5j1f2m:*/
objectval_tyBM *obsbuf__9pAN1UadjT9_4HQXK5j1f2m = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
objectval_tyBM *ob__9pAN1UadjT9_4HQXK5j1f2m = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
if (objhasstrbufferpayl_BM(obsbuf__9pAN1UadjT9_4HQXK5j1f2m) && isobject_BM(ob__9pAN1UadjT9_4HQXK5j1f2m)) {
  char idbuf__9pAN1UadjT9_4HQXK5j1f2m [32];
 memset (idbuf__9pAN1UadjT9_4HQXK5j1f2m, 0, sizeof(idbuf__9pAN1UadjT9_4HQXK5j1f2m));
 idtocbuf32_BM (objid_BM (ob__9pAN1UadjT9_4HQXK5j1f2m), idbuf__9pAN1UadjT9_4HQXK5j1f2m);
 objstrbufferappendcstrpayl_BM(obsbuf__9pAN1UadjT9_4HQXK5j1f2m, idbuf__9pAN1UadjT9_4HQXK5j1f2m);
};
// end objstrbufferprintobjid _9pAN1UadjT9_4HQXK5j1f2m
;  
} // end cexpansion _9pAN1UadjT9_4HQXK5j1f2m - objstrbufferprintobjid  
  
{ // start cexpansion _6HS1ctWa2cx_8kR6FVRd5gz - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " = "));  
} // end cexpansion _6HS1ctWa2cx_8kR6FVRd5gz - objstrbufferappendcstrpayl  
  
//+ #10/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::  
{ // start cexpansion _8Ux2RkzGGBL_1jntmBiiFTE - miniemit_expression  
/*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM, 
  ( /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));   
} // end cexpansion _8Ux2RkzGGBL_1jntmBiiFTE - miniemit_expression   
  
{ // start cexpansion _2B5X8R9i8ty_1ucz1kI8GDH - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ";"));  
} // end cexpansion _2B5X8R9i8ty_1ucz1kI8GDH - objstrbufferappendcstrpayl  
  
//+ #12/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::  
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _5aEMMsDVPT8_5OOBY9RA7UT  
/*objnbcomps:*/ objnbcomps_BM ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW); 
  
{ // start cexpansion _0vpJQXO13zS_2L5lG1Mj9Jl - objstrbuffernewlinepayl  
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);  
} // end cexpansion _0vpJQXO13zS_2L5lG1Mj9Jl - objstrbuffernewlinepayl  
  
//+ #14/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::  
{ // start cexpansion _4j0SrCTPKX5_578JTKzM0IO - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "for ("));  
} // end cexpansion _4j0SrCTPKX5_578JTKzM0IO - objstrbufferappendcstrpayl  
  
{ // start cexpansion _9VLKy0D7b3d_3C7v96GTfEI - miniemit_var  
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));  
} // end cexpansion _9VLKy0D7b3d_3C7v96GTfEI - miniemit_var  
  
//+ #16/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::  
{ // start cexpansion _1sg4pwsDKCo_25auC3DIdDb - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " = cnt"));  
} // end cexpansion _1sg4pwsDKCo_25auC3DIdDb - objstrbufferappendcstrpayl  
  
{ // start cexpansion _9o0MX6Ie2We_0ErK51uBv2S - objstrbufferprintobjid  
/*objstrbufferprintobjid _9o0MX6Ie2We_0ErK51uBv2S:*/
objectval_tyBM *obsbuf__9o0MX6Ie2We_0ErK51uBv2S = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
objectval_tyBM *ob__9o0MX6Ie2We_0ErK51uBv2S = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
if (objhasstrbufferpayl_BM(obsbuf__9o0MX6Ie2We_0ErK51uBv2S) && isobject_BM(ob__9o0MX6Ie2We_0ErK51uBv2S)) {
  char idbuf__9o0MX6Ie2We_0ErK51uBv2S [32];
 memset (idbuf__9o0MX6Ie2We_0ErK51uBv2S, 0, sizeof(idbuf__9o0MX6Ie2We_0ErK51uBv2S));
 idtocbuf32_BM (objid_BM (ob__9o0MX6Ie2We_0ErK51uBv2S), idbuf__9o0MX6Ie2We_0ErK51uBv2S);
 objstrbufferappendcstrpayl_BM(obsbuf__9o0MX6Ie2We_0ErK51uBv2S, idbuf__9o0MX6Ie2We_0ErK51uBv2S);
};
// end objstrbufferprintobjid _9o0MX6Ie2We_0ErK51uBv2S
;  
} // end cexpansion _9o0MX6Ie2We_0ErK51uBv2S - objstrbufferprintobjid  
  
//+ #18/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::  
{ // start cexpansion _5PHQZpCbyj0_0Qu4OPP8J7O - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " - 1;"));  
} // end cexpansion _5PHQZpCbyj0_0Qu4OPP8J7O - objstrbufferappendcstrpayl  
  
{ // start cexpansion _3dqnISCnpKV_9cd4oa4lD8e - objstrbuffernewlinepayl  
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);  
} // end cexpansion _3dqnISCnpKV_9cd4oa4lD8e - objstrbuffernewlinepayl  
  
//+ #20/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::  
{ // start cexpansion _7FhLjwiMrkL_0S5nfILsPPH - miniemit_var  
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));  
} // end cexpansion _7FhLjwiMrkL_0S5nfILsPPH - miniemit_var  
  
{ // start cexpansion _9wHUn8AEJW0_5mpOZSxpfOb - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " >= 0;"));  
} // end cexpansion _9wHUn8AEJW0_5mpOZSxpfOb - objstrbufferappendcstrpayl  
  
//+ #22/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::  
{ // start cexpansion _0ajssbXBH1t_86eb7MoTPzX - objstrbuffernewlinepayl  
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);  
} // end cexpansion _0ajssbXBH1t_86eb7MoTPzX - objstrbuffernewlinepayl  
  
{ // start cexpansion _2fEiBwWFSaE_0vU58gZVuk2 - miniemit_var  
/*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
 ( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));  
} // end cexpansion _2fEiBwWFSaE_0vU58gZVuk2 - miniemit_var  
  
//+ #24/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::  
{ // start cexpansion _2pOCIPB2UNg_05FSSKyZG7P - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " --) {"));  
} // end cexpansion _2pOCIPB2UNg_05FSSKyZG7P - objstrbufferappendcstrpayl  
  
{ //for-up _4pQc5GTSQCv_6wQlgOgKiCo  
intptr_t cnt_4pQc5GTSQCv_6wQlgOgKiCo =  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k;  
for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_4pQc5GTSQCv_6wQlgOgKiCo;  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++) {  
// for-up _4pQc5GTSQCv_6wQlgOgKiCo #0 :  
 /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb = //assign _8Y4SyGKKT8Y_4ppoSkatlDr   
/*val_to_object:*/objectcast_BM(/*objgetcomp:*/objgetcomp_BM (( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)));  
  
// for-up _4pQc5GTSQCv_6wQlgOgKiCo #1 :  
if /*cond _69InabNi0ZZ_8nrzCwNE4PJ*/   
/*when _8TSxMYEi7d2_5ZZyFEsVt4h:*/  
 ( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb) { //body when _8TSxMYEi7d2_5ZZyFEsVt4h   
   
{ // begin lockobj _0Wp7h8yI3oe_8LDnl3npXfl   
  objectval_tyBM* curlockedob_0Wp7h8yI3oe_8LDnl3npXfl = ( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb);   
if (objlock_BM (curlockedob_0Wp7h8yI3oe_8LDnl3npXfl)) {    
locked_0Wp7h8yI3oe_8LDnl3npXfl = curlockedob_0Wp7h8yI3oe_8LDnl3npXfl;    
    
   
{ // run _9Pt0y2rYY9X_1zywHJQtSbK   
/*debug emit_block°basiclo_for_down_loop o_comp ii o_modgen o_block*/
 DBGPRINTF_BM("emit_block°basiclo_for_down_loop €%.9s o_comp=%s ii#%ld o_modgen=%s/L%u o_block=%s",
 "_9Pt0y2rYY9X_1zywHJQtSbK",
 objectdbg_BM( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),
 (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
 objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
 objstrbufferlengthpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
 objectdbg2_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW));;   
} // end run _9Pt0y2rYY9X_1zywHJQtSbK   
    
{ // start cexpansion _1M8S2Mwfvvt_7b0TSkcWxHp - objstrbuffersetindentpayl    
/*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));     
} // end cexpansion _1M8S2Mwfvvt_7b0TSkcWxHp - objstrbuffersetindentpayl     
    
//+ #2/11 of lockobj _0Wp7h8yI3oe_8LDnl3npXfl ::    
{ // start cexpansion _7slZIyHc2bf_6tUhk6lWWlE - objstrbuffernewlinepayl    
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);    
} // end cexpansion _7slZIyHc2bf_6tUhk6lWWlE - objstrbuffernewlinepayl    
    
{ // start cexpansion _1WlvridOvCE_4nfoeo6qsSE - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "// for-down "));    
} // end cexpansion _1WlvridOvCE_4nfoeo6qsSE - objstrbufferappendcstrpayl    
    
//+ #4/11 of lockobj _0Wp7h8yI3oe_8LDnl3npXfl ::    
{ // start cexpansion _59NJcWlZqo7_5IZY8Qh9pKe - objstrbufferprintobject    
/*objstrbufferprintobject _59NJcWlZqo7_5IZY8Qh9pKe:*/
 objectval_tyBM* obsbuf_59NJcWlZqo7_5IZY8Qh9pKe = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
 objectval_tyBM* ob_59NJcWlZqo7_5IZY8Qh9pKe = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
 if (objhasstrbufferpayl_BM(obsbuf_59NJcWlZqo7_5IZY8Qh9pKe) && isobject_BM(ob_59NJcWlZqo7_5IZY8Qh9pKe))
  objstrbufferappendcstrpayl_BM(obsbuf_59NJcWlZqo7_5IZY8Qh9pKe, objectdbg_BM(ob_59NJcWlZqo7_5IZY8Qh9pKe));
// end objstrbufferprintobject _59NJcWlZqo7_5IZY8Qh9pKe
;    
} // end cexpansion _59NJcWlZqo7_5IZY8Qh9pKe - objstrbufferprintobject    
    
{ // start cexpansion _67MGFrqvi8V_86YtGUqOXlD - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " #"));    
} // end cexpansion _67MGFrqvi8V_86YtGUqOXlD - objstrbufferappendcstrpayl    
    
//+ #6/11 of lockobj _0Wp7h8yI3oe_8LDnl3npXfl ::    
{ // start cexpansion _2YxyEcSJdKJ_9HEGTRUj9Wq - objstrbufferprintint    
/*objstrbufferprintint:*/if (objhasstrbufferpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv)) {
 char buf_2YxyEcSJdKJ_9HEGTRUj9Wq[32]; 
 memset (buf_2YxyEcSJdKJ_9HEGTRUj9Wq, 0, sizeof(buf_2YxyEcSJdKJ_9HEGTRUj9Wq));
 snprintf(buf_2YxyEcSJdKJ_9HEGTRUj9Wq, sizeof(buf_2YxyEcSJdKJ_9HEGTRUj9Wq), "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
 objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), buf_2YxyEcSJdKJ_9HEGTRUj9Wq);
} //end objstrbufferprintint _2YxyEcSJdKJ_9HEGTRUj9Wq
;    
} // end cexpansion _2YxyEcSJdKJ_9HEGTRUj9Wq - objstrbufferprintint    
    
{ // start cexpansion _9yBQYtAaH9M_8ktwf6cYm1k - objstrbuffernewlinepayl    
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);    
} // end cexpansion _9yBQYtAaH9M_8ktwf6cYm1k - objstrbuffernewlinepayl    
    
//+ #8/11 of lockobj _0Wp7h8yI3oe_8LDnl3npXfl ::    
if /*cond _91XVXtprccW_28DRbTiOzSR*/    
/*when _4KA7D8V97uE_0GKeafNCOjg:*/   
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[29] /*!basiclo_block*/)))) { //body when _4KA7D8V97uE_0GKeafNCOjg    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _7qms8dDaskD_9n8IbyY8sp0     
(send3_BM (( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), /*sel:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[49] /*!emit_block*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),  ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));    
    
} //endwhen _4KA7D8V97uE_0GKeafNCOjg    
else if    
/*when _5fJtp7BHeaI_3SdQy8HSkeb:*/   
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[30] /*!basiclo_statement*/)))) { //body when _5fJtp7BHeaI_3SdQy8HSkeb    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _7nNnwMcKtuN_455Z1RFw66Z     
(send3_BM (( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), /*sel:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[12] /*!emit_statement*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),  ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));    
    
} //endwhen _5fJtp7BHeaI_3SdQy8HSkeb    
else { /*cond else _91XVXtprccW_28DRbTiOzSR*/    
//failure _2MJKx6JJ45K_6rmHWbevG98    
PLACEDFAILURE_BM(__LINE__,    
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[33] /*!failure_bad_class*/)), 
 /*make_node 5 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!_8NgOdlJACWN_8pbYZXkHpCj*/)), 
 
( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), 
 
( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[21] /*|_2MJKx6JJ45K_6rmHWbevG98*/)),
                ((struct stackframe_stBM *) &_));
} /*cond else _91XVXtprccW_28DRbTiOzSR*/    
/*endcond _91XVXtprccW_28DRbTiOzSR*/   
    
   
{ // run _3iEKJp3QXd7_3utjt3P1kWR   
/*debug emit_block°basiclo_for_down_loop v_resemit=%s ii o_comp o_modgen*/
DBGPRINTF_BM("emit_block°basiclo_for_down_loop €%.9s v_resemit=%s ii#%ld o_comp=%s o_modgen=%s/L%u",
 "_3iEKJp3QXd7_3utjt3P1kWR",
  OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
  (long int)( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
  objectdbg_BM( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),
  objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
  objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv));
    ;   
} // end run _3iEKJp3QXd7_3utjt3P1kWR   
    
if /*cond _0D25uP6R82R_6ALVU5tS9tk*/    
/*when _9HjGiFLRWyt_58OpYxNuI1N:*/   
 (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL)) { //body when _9HjGiFLRWyt_58OpYxNuI1N    
//failure _5XtoXsvceoR_1Q6dI4J6G4X     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!_8NgOdlJACWN_8pbYZXkHpCj*/)), 
 
( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), 
 
( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW)))),
                /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[45] /*|_5XtoXsvceoR_1Q6dI4J6G4X*/)),
                ((struct stackframe_stBM *) &_));
    
} //endwhen _9HjGiFLRWyt_58OpYxNuI1N    
/*endcond _0D25uP6R82R_6ALVU5tS9tk*/   
    
objunlock_BM (locked_0Wp7h8yI3oe_8LDnl3npXfl), locked_0Wp7h8yI3oe_8LDnl3npXfl = NULL;   
} } // end objlock _0Wp7h8yI3oe_8LDnl3npXfl   
   
} //endwhen _8TSxMYEi7d2_5ZZyFEsVt4h   
/*endcond _69InabNi0ZZ_8nrzCwNE4PJ*/  
 
}} // end for-up _4pQc5GTSQCv_6wQlgOgKiCo 
  
//+ #26/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::  
{ // start cexpansion _8nSFXfKkUWb_6LwNMKTP35B - objstrbuffersetindentpayl  
/*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));  
} // end cexpansion _8nSFXfKkUWb_6LwNMKTP35B - objstrbuffersetindentpayl  
  
{ // start cexpansion _1cf6xfCgklr_6Z5cYDvFYA1 - objstrbuffernewlinepayl  
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);  
} // end cexpansion _1cf6xfCgklr_6Z5cYDvFYA1 - objstrbuffernewlinepayl  
  
//+ #28/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::  
{ // start cexpansion _67oLoMEzzaW_7lq2nZFaC5i - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "} } // end for-down "));  
} // end cexpansion _67oLoMEzzaW_7lq2nZFaC5i - objstrbufferappendcstrpayl  
  
{ // start cexpansion _4oHFEaEwUEh_47ScLMAXHby - objstrbufferprintobject  
/*objstrbufferprintobject _4oHFEaEwUEh_47ScLMAXHby:*/
 objectval_tyBM* obsbuf_4oHFEaEwUEh_47ScLMAXHby = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
 objectval_tyBM* ob_4oHFEaEwUEh_47ScLMAXHby = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
 if (objhasstrbufferpayl_BM(obsbuf_4oHFEaEwUEh_47ScLMAXHby) && isobject_BM(ob_4oHFEaEwUEh_47ScLMAXHby))
  objstrbufferappendcstrpayl_BM(obsbuf_4oHFEaEwUEh_47ScLMAXHby, objectdbg_BM(ob_4oHFEaEwUEh_47ScLMAXHby));
// end objstrbufferprintobject _4oHFEaEwUEh_47ScLMAXHby
;  
} // end cexpansion _4oHFEaEwUEh_47ScLMAXHby - objstrbufferprintobject  
  
//+ #30/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::  
{ // start cexpansion _6QxKswSMMuI_7eAKQJNPnX4 - objstrbuffernewlinepayl  
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);  
} // end cexpansion _6QxKswSMMuI_7eAKQJNPnX4 - objstrbuffernewlinepayl  
  
 
{ // run _5o3ckSOo8Ob_0C7nhOZEQa5 
/*debug emit_block°basiclo_for_down_loop end o_block o_modgen depth*/
DBGPRINTF_BM("emit_block°basiclo_for_down_loop end €%.9s o_block=%s o_modgen=%s/L%u depth#%ld",
 "_5o3ckSOo8Ob_0C7nhOZEQa5",
 objectdbg_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),
 objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
 objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
 (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
; 
} // end run _5o3ckSOo8Ob_0C7nhOZEQa5 
  
/*return _2MonNj2qprO_7byuS0j5fDE:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW; 
 goto epilog_8NgOdlJACWN_8pbYZXkHpCj; 
  
objunlock_BM (locked_4a5PI4Gi0yN_0Vg2cbkuXjE), locked_4a5PI4Gi0yN_0Vg2cbkuXjE = NULL; 
} } // end objlock _4a5PI4Gi0yN_0Vg2cbkuXjE 
/* !endingblock _0V7X1Z5gIQp_4SZI2S9RSG0 */ 
goto endblock__0V7X1Z5gIQp_4SZI2S9RSG0; 
endblock__0V7X1Z5gIQp_4SZI2S9RSG0: ; 
} /*-block _0V7X1Z5gIQp_4SZI2S9RSG0 */

 epilog_8NgOdlJACWN_8pbYZXkHpCj: __attribute__ ((unused)); // routine _8NgOdlJACWN_8pbYZXkHpCj epilogue:
   // unlocking 2:
    if (locked_0Wp7h8yI3oe_8LDnl3npXfl != NULL)
       objunlock_BM(locked_0Wp7h8yI3oe_8LDnl3npXfl), locked_0Wp7h8yI3oe_8LDnl3npXfl = NULL; // for o_comp
    if (locked_4a5PI4Gi0yN_0Vg2cbkuXjE != NULL)
       objunlock_BM(locked_4a5PI4Gi0yN_0Vg2cbkuXjE), locked_4a5PI4Gi0yN_0Vg2cbkuXjE = NULL; // for o_block
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _8NgOdlJACWN_8pbYZXkHpCj routine#4 _8NgOdlJACWN_8pbYZXkHpCj




// end of 5 generated routines


// the constant ids for 65 constants:
const char* const constid_1lhXvXtIyPu_3nhuy4kN3wd_BM[65+1] = {
 /*0:*/
 "_08PMymoD6YJ_8rspWoCg4Xu", //! emit_statement°basiclo_outstmt < o_stmt (o_modgen o_routprep v_depth)
 "_0o8bMUSb0El_8cRNhyRuvjD",//more_indent
 "_0vgCFjXblkx_4zCMhMAWjVK",//int
 "_0vCFi47Ctm6_70R5Tci6JuH", //! emit_block°basiclo_for_up_loop  < o_block (o_modgen o_routprep v_depth)
 "_0xjHtHT70tB_7ABtNzelPi8",//prefixed_lines
 /*5:*/
 "_0EmM9kH8Wgr_7fpd0oIo9xQ",//out
 "_0HZ6LhCuD3B_3wOqehpkD81", //! else fail bad-class miniscan_stmt°basiclo_countloop o_substmt ii o_stmt o_routprep depth
 "_1jJjA6LcXiX_1V4ZcXlje09",//name
 "_1kz7viwMzTp_6PgLhdZzMEy", //! miniscan_stmt°basiclo_outstmt < o_stmt (o_routprep v_depth o_from)
 "_1lhXvXtIyPu_3nhuy4kN3wd",//code_generator_module
 /*10:*/
 "_1lCz1IP7t5R_8NTFVv0tnOi",//octa
 "_1m5rw0BZl8f_4M9cndtjRl8", //! fail failure-miss out o_stmt o_routprep depth o_from
 "_1ERH9PxNhPb_2o869yOMuH0",//emit_statement
 "_227kofebdwq_9fj8R3qXt7B", //! fail-miss  miniscan_stmt°basiclo_countloop miniscan_stmt o_substmt ii o_stmt o_routprep depth
 "_26UbzubL5aT_2vDJc23p59r", //! fail-typerr int o_restype v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
 /*15:*/
 "_2eREyARXfUb_2mTxUngIL6Y", //! fail-typerr object o_restype v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
 "_2gthNYOWogO_4sVTU1JbmUH",//miniscan_block
 "_2qDaJRPDbEG_45AvdxtQXAM",//double_float
 "_2u9YAFmxxSj_1WizQTT1BHQ",//half_id
 "_2wGWzItVmrN_2CBwG6iHWFO",//newline
 /*20:*/
 "_2yhrFze2uwV_6G7BfGXfplP",//set_indent
 "_2MJKx6JJ45K_6rmHWbevG98", //! fail-bad-class emit_block°basiclo_for_down_loop o_comp ii o_modgen o_block
 "_2P7OoZumXdx_5sUQ9SPbVwn",//utf8_enc
 "_2W2LFnO44dr_973izSVn0hU",//local_time
 "_35gLacRFhq5_90zAPxiDIlh",//space
 /*25:*/
 "_3hMno2PB1II_6IrKetMkipy", //! else/bad o_conn fail-miss emit_statement°basiclo_outstmt unexpected o_conn v_comp ii o_stmt o_modgen o_routprep
 "_3CZ4Lq3VkJF_3Qt5nkQ9R3w", //! fail-miss emit_block°basiclo_for_up_loop o_comp ii o_modgen o_block
 "_3QmxfIKpDVI_0C4Z01aFVxK",//html_enc
 "_3RUddTzPPB8_5j4EYXKOe2g", //! else fail-miss v_comp ii o_stmt o_modgen o_routprep in emit_statement°basiclo_outstmt
 "_4bYUiDmxrKK_6nPPlEl8y8x",//basiclo_block
 /*30:*/
 "_4lKK08v9A0t_0GGsir35UxP",//basiclo_statement
 "_4wmsNr582JT_9YyamGEMhJk",//json_compact
 "_4BSjKuvOgrt_81MLC8NyKiS",//double_plain
 "_4HgYLk6htvP_4Ac2FCPfQ1C",//failure_bad_class
 "_4HAZLawO9HO_91oo1k4Ajat", //! fail-typerr string o_restype v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
 /*35:*/
 "_4T8am97muLl_5969SR22Ecq",//string
 "_4WkaKNhBpsa_9VlfEzlClhm", //! fail-typerr double_float o_restype v_cimp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
 "_52XwytpOPVl_3ZjmQCtadbK",//failure_miss
 "_5oVb4fNe3eO_4GyCgc0vkQp", //! fail-miss  miniscan_stmt°basiclo_countloop miniscan_block o_substmt ii o_stmt o_routprep depth
 "_5t5nLVnGAqW_9IbjlqpPdp3",//less_indent
 /*40:*/
 "_5wNedaaTb99_3ZQe6xm9HNx",//literal_c_string
 "_5zaZ8sDu1TQ_49hqJMJDKIq", //! fail type-error index typindex varindex stmt routprep depth from
 "_5J3InN9BK1k_3C8vurQQEGh",//json_indented
 "_5J4f6u42le4_9UZMTZziEEw", //! else fail-miss v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
 "_5OiKmAdUjY5_9BPLOECag6g",//count
 /*45:*/
 "_5XtoXsvceoR_1Q6dI4J6G4X", //! fail-miss emit_block°basiclo_for_down_loop o_comp ii o_modgen o_block
 "_6cS5VddZd7n_9Nnn2wYWAeL", //! fail-miss miniscan_var o_varout o_routprep depth+1 o_stmt o_from in miniscan_stmt°basiclo_outstmt
 "_6fPPUXnZhy5_8Lh5DOOe0Nu",//arity
 "_6jh60mO0Cgd_84B0HiNphqA",//miniscan_var
 "_6mk5eos8067_1odgCpnWMOj",//emit_block
 /*50:*/
 "_6xxbA8aTjZm_1sCJbVkU3Pm",//c_enc
 "_6DdZwyaWLyK_7tS2BmECOJ0",//miniscan_stmt
 "_6EG5W7z0BRb_4TBM1gyenqk",//index
 "_6MTJtvsUEYW_9WuS0LnLfmm", //! fail-bad-class emit_block°basiclo_for_up_loop o_comp ii o_modgen o_block
 "_6Rc660mzjXf_6rWF1nupKVt", //! fail type-error count countexp stmt routprep depth from
 /*55:*/
 "_7bbeIqUSje9_4jVgC7ZJmvx",//value
 "_7coI3Hezrvp_6CG1u3MlT83",//nlsp
 "_7T9OwSFlgov_0wVJaK1eZbn",//object
 "_7WjaQkqwdaZ_6PRtbDrJHnf",//id
 "_7YmEzAVe2hC_9iA0FVXAIqp",//hexa
 /*60:*/
 "_85xjvzYjcd6_9mNZNPF6i2J", //! miniscan_stmt°basiclo_countloop < o_stmt (o_routprep v_depth o_from)
 "_8NgOdlJACWN_8pbYZXkHpCj", //! emit_block°basiclo_for_down_loop  < o_block (o_modgen o_routprep v_depth)
 "_8QmDbXEU8lU_33mrgrh3zUR", //! fail-miss arity v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
 "_95hdJENHNkN_3QuKIJTCQQQ",//failure_type_error
 "_9umIVqZhssC_2WJZljFrGaA", //! fail-typerr value o_restype v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
 NULL}; // end 65 constant ids



// the routine ids for 5 routines:
const char* const routid_1lhXvXtIyPu_3nhuy4kN3wd_BM[5+1] = {
  /*0:*/
  "_08PMymoD6YJ_8rspWoCg4Xu", //!emit_statement°basiclo_outstmt < o_stmt (o_modgen o_routprep v_depth)
  "_0vCFi47Ctm6_70R5Tci6JuH", //!emit_block°basiclo_for_up_loop  < o_block (o_modgen o_routprep v_depth)
  "_1kz7viwMzTp_6PgLhdZzMEy", //!miniscan_stmt°basiclo_outstmt < o_stmt (o_routprep v_depth o_from)
  "_85xjvzYjcd6_9mNZNPF6i2J", //!miniscan_stmt°basiclo_countloop < o_stmt (o_routprep v_depth o_from)
  "_8NgOdlJACWN_8pbYZXkHpCj", //!emit_block°basiclo_for_down_loop  < o_block (o_modgen o_routprep v_depth)

 NULL}; // end 5 routine ids



// basiclo*module initialization
#ifdef BISMON_MODID
value_tyBM moduleinit_1lhXvXtIyPu_3nhuy4kN3wd_BM
  (struct stackframe_stBM *stkf, //
   const value_tyBM arg1, //
   const value_tyBM arg2, //
   const value_tyBM arg3, //
   void* dlh) {
  return simple_module_initialize_BM(arg1, arg2, arg3, //
        "_1lhXvXtIyPu_3nhuy4kN3wd",//
       constob_1lhXvXtIyPu_3nhuy4kN3wd_BM, //
       constid_1lhXvXtIyPu_3nhuy4kN3wd_BM, //
       routid_1lhXvXtIyPu_3nhuy4kN3wd_BM, //
       dlh, stkf);
} // end moduleinit_1lhXvXtIyPu_3nhuy4kN3wd_BM
#endif /*BISMON_MODID*/



/************
 ** for Emacs:
 ** Local Variables: ;;
 ** compile-command: "make -k -j -C .. modules" ;;
 ** End: ;;
 ************/



// end of generated persistent module code_generator_module in file modbm_1lhXvXtIyPu_3nhuy4kN3wd.c
