// generated persistent module first_misc_module
// in file modbm_3BFt4NfJmZC_7iYi2dwM38B.c -- DONT EDIT
// this generated code is GPLv3+ licensed.


#include "bismon.h"

#ifdef BISMON_MODID
DECLARE_MODULE_BM(_3BFt4NfJmZC_7iYi2dwM38B);
extern moduleinit_sigBM modulinit_3BFt4NfJmZC_7iYi2dwM38B_BM;
#endif /*BISMON_MODID*/

#ifdef BISMON_MOMD5
const char modulmd5chksum_3BFt4NfJmZC_7iYi2dwM38B_BM[] = BISMON_MOMD5;
#endif /*BISMON_MOMD5*/



// declare 25 routines

extern const char *const routid_3BFt4NfJmZC_7iYi2dwM38B_BM[25+1];


// 19 failures

extern objrout_sigBM crout_08PMymoD6YJ_8rspWoCg4Xu_BM; //#0 !emit_statement°basiclo_outstmt < o_stmt (o_modgen o_routprep v_depth)

extern objrout_sigBM crout_0cUdonky1bM_4IVhwlVRBMk_BM; //#1 !webhandler testhello minifunc

extern objrout_sigBM crout_0g1CBaxjMIB_7NZdyHUikLG_BM; //#2 !out#readmacro (v_node v_lineno v_colpos o_parser)

extern objrout_sigBM crout_0vCFi47Ctm6_70R5Tci6JuH_BM; //#3 !emit_block°basiclo_for_up_loop  < o_block (o_modgen o_routprep v_depth)

extern objrout_sigBM crout_0JktC4mAHCa_1KNr6uMIqIi_BM; //#4 !dump_scan°list_object minifunc for list_object o1 & dumperobj o2

extern objrout_sigBM crout_0SinERsgdvQ_57dLCP63i9r_BM; //#5 !forgetname#command_handler

extern objrout_sigBM crout_0YOXUe7rEJC_3jFMjOAQRs9_BM; //#6 element_of_closed_minifunc

extern objrout_sigBM crout_1kz7viwMzTp_6PgLhdZzMEy_BM; //#7 !miniscan_stmt°basiclo_outstmt < o_stmt (o_routprep v_depth o_from)

extern objrout_sigBM crout_22Zd68WPKUO_6AoIuBcbUb2_BM; //#8 !dump_scan°dict_object minifunc for dict-object odict and dumperobj odumper

extern objrout_sigBM crout_2bZ4BfCci5V_3WTzG7V25y4_BM; //#9 !put°dict_object minifunc

extern objrout_sigBM crout_2nl9zcaSUwe_8UBiMp1OuMk_BM; //#10 identity_minifunc

extern objrout_sigBM crout_3iiht57Wrs1_5NbiUi27oBn_BM; //#11 !prepend°list_object minifunc

extern objrout_sigBM crout_3yQlckX4DRh_4b9l9FBSSSL_BM; //#12 same_as_closed_minifunc

extern objrout_sigBM crout_3HAeZZQ0q7b_7qyDsekaz7Y_BM; //#13 !clear°list_object minifunc

extern objrout_sigBM crout_4iEFTEcHxeb_6lH464uFkTC_BM; //#14 equal_to_closed_minifunc

extern objrout_sigBM crout_4qlegfkPzrC_17skUfJP7v8_BM; //#15 !dump_data°dict_object minifun

extern objrout_sigBM crout_4M7lr5cU6VD_5hxmeH3baBf_BM; //#16 !append°list_object minifunction

extern objrout_sigBM crout_5j8LpQULt1p_9oeOaqmfYYr_BM; //#17 !dump_data°list_object minifunc

extern objrout_sigBM crout_7MtjMTkmErH_2zSJ1YDKHVi_BM; //#18 !dump_value°double_float < v_dbl (o_strbuf o_dump v_depth)

extern objrout_sigBM crout_82ho9wUUDji_4peMLha4PXl_BM; //#19 findobj_scan_minifunc

extern objrout_sigBM crout_85xjvzYjcd6_9mNZNPF6i2J_BM; //#20 !miniscan_stmt°basiclo_countloop < o_stmt (o_routprep v_depth o_from)

extern objrout_sigBM crout_8dG7KZHgf3t_4ia32mWZqVQ_BM; //#21 !for_loop#readmacro (v_node v_lineno v_colpos o_parser)

extern objrout_sigBM crout_8imWClcIFKt_6w2H2ouB4I6_BM; //#22 iterate_sequence_minifunc

extern objrout_sigBM crout_8NgOdlJACWN_8pbYZXkHpCj_BM; //#23 !emit_block°basiclo_for_down_loop  < o_block (o_modgen o_routprep v_depth)

extern objrout_sigBM crout_9CG8SKNs6Ql_4PiHd8cnydn_BM; //#24 !clear°dict_object minifun


// declare 87 constants
objectval_tyBM* constob_3BFt4NfJmZC_7iYi2dwM38B_BM[87+1];
const char* const constid_3BFt4NfJmZC_7iYi2dwM38B_BM[87+1];


// define 25 routines


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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[0] /*|_08PMymoD6YJ_8rspWoCg4Xu*/;
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
   // routine _08PMymoD6YJ_8rspWoCg4Xu body:

startblock__2RXF4soNP1G_4lwKnhT9HXn: __attribute__((unused));
{ /* +block _2RXF4soNP1G_4lwKnhT9HXn */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _7qIppSwFGGb_2UJt4H9gKgS  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV = //assign _8snpX2CnOTZ_3s6SIUk6miJ  
/*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[7] /*!out*/)))); 
 
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
 objectval_tyBM* objswexp_88CClQZGP1N_57QoKCh6Ivj = ( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81);   
 switch (objecthash_BM (objswexp_88CClQZGP1N_57QoKCh6Ivj) % 64) {   
 case 0:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[29] /*|utf8_enc*/)) goto whenobj88CClQZG__3UQkLJVILrN_5fQkMJuOnaO;   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[51] /*|less_indent*/)) goto whenobj88CClQZG__0kARe298u9e_67xDUpdBBUc;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 2:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[69] /*|nlsp*/)) goto whenobj88CClQZG__87vVePujNkG_0JOq1ftTQok;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 5:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[63] /*|c_enc*/)) goto whenobj88CClQZG__5ET8jC0ulFr_8HwUqVh9ORX;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 6:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[26] /*|newline*/)) goto whenobj88CClQZG__9E2lY6UWtZc_1zqNjPXxrB1;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 11:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[72] /*|object*/)) goto whenobj88CClQZG__3EoeNMRpnqL_7axOMOBffnQ;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 15:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[36] /*|html_enc*/)) goto whenobj88CClQZG__6aA6aV2YRMt_1NEYDaXpeC7;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 19:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[15] /*|octa*/)) goto whenobj88CClQZG__1Okz8TmaK4w_1h2DwizxeUm;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 22:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[30] /*|space*/)) goto whenobj88CClQZG__114ixi5SECv_2Q1vNdDZoMs;   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[54] /*|json_indented*/)) goto whenobj88CClQZG__0z4pSxrVvjo_5sHi5Y1pLPY;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 30:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[5] /*|int*/)) goto whenobj88CClQZG__1x34ns9L1vc_0NkwFmpgSZo;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 31:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[68] /*|value*/)) goto whenobj88CClQZG__1zJdg4pQzkf_3a4FsTJjy8n;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 34:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[74] /*|hexa*/)) goto whenobj88CClQZG__0BVlPuwRd7W_2uZdnPJU4lL;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 36:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[4] /*|more_indent*/)) goto whenobj88CClQZG__7ZmgWpB8hAR_9ZTbneZMSU1;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 41:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[52] /*|literal_c_string*/)) goto whenobj88CClQZG__3s1tzo7j8uB_0du3hmckL9U;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 42:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[13] /*|name*/)) goto whenobj88CClQZG__5BIPiYugHNh_27cx9JETCA7;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 47:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[43] /*|json_compact*/)) goto whenobj88CClQZG__4fv6GoqMJ2j_5mL5sYAy1MA;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 51:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[27] /*|set_indent*/)) goto whenobj88CClQZG__7SJ5JXB8NNl_6AbPMP2VS1c;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
 case 55:   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[47] /*|string*/)) goto whenobj88CClQZG__9d7rWinZqTW_3HJB0Tm1DtZ;   
  if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[73] /*|id*/)) goto whenobj88CClQZG__0fRhe6eKSxc_717gH1gzxnY;   
  goto defobj_88CClQZGP1N_57QoKCh6Ivj;   
   
  default: defobj_88CClQZGP1N_57QoKCh6Ivj:;   
   
 // objswitch _88CClQZGP1N_57QoKCh6Ivj default#0 statement:    
//failure _3hMno2PB1II_6IrKetMkipy     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[48] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[0] /*!_08PMymoD6YJ_8rspWoCg4Xu*/)), 
 
( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[31] /*|_3hMno2PB1II_6IrKetMkipy*/)),
                ((struct stackframe_stBM *) &_));
    
break; // end objswitch _88CClQZGP1N_57QoKCh6Ivj default    
// objswitch _88CClQZGP1N_57QoKCh6Ivj with 20 whens:    
    
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
    
whenobj88CClQZG__114ixi5SECv_2Q1vNdDZoMs:; // when #4 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
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
    
    
break; // end when _114ixi5SECv_2Q1vNdDZoMs #4 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__1x34ns9L1vc_0NkwFmpgSZo:; // when #5 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
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
    
    
break; // end when _1x34ns9L1vc_0NkwFmpgSZo #5 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__1zJdg4pQzkf_3a4FsTJjy8n:; // when #6 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
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
    
    
break; // end when _1zJdg4pQzkf_3a4FsTJjy8n #6 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__1Okz8TmaK4w_1h2DwizxeUm:; // when #7 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
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
    
    
break; // end when _1Okz8TmaK4w_1h2DwizxeUm #7 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__3s1tzo7j8uB_0du3hmckL9U:; // when #8 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
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
    
    
break; // end when _3s1tzo7j8uB_0du3hmckL9U #8 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__3EoeNMRpnqL_7axOMOBffnQ:; // when #9 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
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
    
    
break; // end when _3EoeNMRpnqL_7axOMOBffnQ #9 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__3UQkLJVILrN_5fQkMJuOnaO:; // when #10 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
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
    
    
break; // end when _3UQkLJVILrN_5fQkMJuOnaO #10 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__4fv6GoqMJ2j_5mL5sYAy1MA:; // when #11 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
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
    
    
break; // end when _4fv6GoqMJ2j_5mL5sYAy1MA #11 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__5BIPiYugHNh_27cx9JETCA7:; // when #12 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
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
    
    
break; // end when _5BIPiYugHNh_27cx9JETCA7 #12 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__5ET8jC0ulFr_8HwUqVh9ORX:; // when #13 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
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
    
    
break; // end when _5ET8jC0ulFr_8HwUqVh9ORX #13 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__6aA6aV2YRMt_1NEYDaXpeC7:; // when #14 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
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
    
    
break; // end when _6aA6aV2YRMt_1NEYDaXpeC7 #14 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__7SJ5JXB8NNl_6AbPMP2VS1c:; // when #15 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
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
    
    
break; // end when _7SJ5JXB8NNl_6AbPMP2VS1c #15 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__7ZmgWpB8hAR_9ZTbneZMSU1:; // when #16 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
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
    
    
break; // end when _7ZmgWpB8hAR_9ZTbneZMSU1 #16 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__87vVePujNkG_0JOq1ftTQok:; // when #17 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
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
    
    
break; // end when _87vVePujNkG_0JOq1ftTQok #17 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__9d7rWinZqTW_3HJB0Tm1DtZ:; // when #18 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
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
    
    
break; // end when _9d7rWinZqTW_3HJB0Tm1DtZ #18 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
    
whenobj88CClQZG__9E2lY6UWtZc_1zqNjPXxrB1:; // when #19 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
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
    
    
break; // end when _9E2lY6UWtZc_1zqNjPXxrB1 #19 of objswitch _88CClQZGP1N_57QoKCh6Ivj    
   
} } // end objswitch _88CClQZGP1N_57QoKCh6Ivj   
   
} //endwhen _9snNxHFHKej_9go5H2wttwP   
else { /*cond else _4nOMpL7ofYO_7UI4gpk1cQz*/   
//failure _3RUddTzPPB8_5j4EYXKOe2g   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[48] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[0] /*!_08PMymoD6YJ_8rspWoCg4Xu*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[37] /*|_3RUddTzPPB8_5j4EYXKOe2g*/)),
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




value_tyBM crout_0cUdonky1bM_4IVhwlVRBMk_BM //#1
 (struct stackframe_stBM* stkf, //
//!webhandler testhello minifunc
  // 2 arguments
  const value_tyBM arg0,  // v_restpath
  const value_tyBM arg1,  // o_webex
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _0cUdonky1bM_4IVhwlVRBMk
  struct frame_0cUdonky1bM_4IVhwlVRBMk_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 5 local values:
    value_tyBM v_2nnQQ6Lvtpl_4oCJYx90FlI; // v_postbar
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_5JuT4FgNFFh_7McrTYeT3jx; // o_webex
    value_tyBM v_6QhNRfe1Cte_0niVlWfAlmO; // v_restpath
    value_tyBM v_8s5u19T0e2h_9ZqrO3YZDVS; // v_queryfoo
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_0cUdonky1bM_4IVhwlVRBMk_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 5;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[1] /*|_0cUdonky1bM_4IVhwlVRBMk*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 2 arguments:
   _.v_6QhNRfe1Cte_0niVlWfAlmO = arg0; // v_restpath
   _.o_5JuT4FgNFFh_7McrTYeT3jx = objectcast_BM (arg1); // o_webex
   // fetched 2 arguments.
   // no closed values in _0cUdonky1bM_4IVhwlVRBMk.
   // routine _0cUdonky1bM_4IVhwlVRBMk body:

startblock__8prn9eFlYZD_6JJKKh2b8KW: __attribute__((unused));
{ /* +block _8prn9eFlYZD_6JJKKh2b8KW */ 
 
{ // run _65239uTOHoM_0gCnjTxaNEB 
 /*Debug Web TestHello*/
DBGPRINTF_BM("start webhandler testhello o_webex= %s", objectdbg_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx));
; 
} // end run _65239uTOHoM_0gCnjTxaNEB 
 
 
 
startblock__4ZE2MUVTcHt_4lWsA1elKmS: __attribute__((unused)); 
{ /* +block _4ZE2MUVTcHt_4lWsA1elKmS */  
{ // start cexpansion _2CWJlYEwmaf_6nlLCxAfCx8 - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( "<!DOCTYPE html>\n<html><head><title>testhello bismon</title>\n"));   
} // end cexpansion _2CWJlYEwmaf_6nlLCxAfCx8 - objstrbufferappendcstrpayl   
   
  
{ // start out _3GUB2GqOMv5_9mLZQWLvac5 to o_webex   
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx, "<script src=\'jscript/jquery.js\'></script>\n");  
} // end out _3GUB2GqOMv5_9mLZQWLvac5  
  
//+ #2/4 of block _4ZE2MUVTcHt_4lWsA1elKmS ::  
  
{ // start cexpansion _07IfSVe5oBj_7I7w9nZbfgr - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( "</head>\n"));   
} // end cexpansion _07IfSVe5oBj_7I7w9nZbfgr - objstrbufferappendcstrpayl   
   
  
{ // start cexpansion _4ootClJhCCt_4B3yo2Szuwj - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( "<body>\n"));   
} // end cexpansion _4ootClJhCCt_4B3yo2Szuwj - objstrbufferappendcstrpayl   
   
/* !endingblock _4ZE2MUVTcHt_4lWsA1elKmS */  
goto endblock__4ZE2MUVTcHt_4lWsA1elKmS;  
endblock__4ZE2MUVTcHt_4lWsA1elKmS: ;  
} /*-block _4ZE2MUVTcHt_4lWsA1elKmS */ 
//+ #2/6 of block _8prn9eFlYZD_6JJKKh2b8KW :: 
 
 
startblock__3VVvcLyYqv8_9yci7GvqEEv: __attribute__((unused)); 
{ /* +block _3VVvcLyYqv8_9yci7GvqEEv */  
{ // start cexpansion _5lsoSuyLYE0_2cqb9QxFcos - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( "<h1>testhello bismon</h1>\n"));   
} // end cexpansion _5lsoSuyLYE0_2cqb9QxFcos - objstrbufferappendcstrpayl   
   
  
if /*cond _27HdixkwtUA_4tQyI0XopOj*/   
/*when _57I7rSuuKya_8AuIt3qlJI1:*/  
 (/*objwebexchangerequestispostpayl:*/ objwebexchangerequestispostpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx))) { //body when _57I7rSuuKya_8AuIt3qlJI1   
{ // start cexpansion _2AxVlhlfGNw_7PIs9S04rhK - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( "<p><tt>POST</tt> request!</p>\n"));    
} // end cexpansion _2AxVlhlfGNw_7PIs9S04rhK - objstrbufferappendcstrpayl    
   
} //endwhen _57I7rSuuKya_8AuIt3qlJI1   
/*endcond _27HdixkwtUA_4tQyI0XopOj*/  
  
//+ #2/13 of block _3VVvcLyYqv8_9yci7GvqEEv ::  
  
{ // start cexpansion _1gjXCT3HN6V_5SGgDufAmKf - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( "<p>session: <tt>"));   
} // end cexpansion _1gjXCT3HN6V_5SGgDufAmKf - objstrbufferappendcstrpayl   
   
  
{ // start cexpansion _1XzuICo9tMz_2FMOEMMgKHC - objstrbufferprintobjid   
/*objstrbufferprintobjid _1XzuICo9tMz_2FMOEMMgKHC:*/
objectval_tyBM *obsbuf__1XzuICo9tMz_2FMOEMMgKHC = ( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx);
objectval_tyBM *ob__1XzuICo9tMz_2FMOEMMgKHC = (/*objwebexchangesessionpayl:*/objwebexchangesessionpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx)));
if (objhasstrbufferpayl_BM(obsbuf__1XzuICo9tMz_2FMOEMMgKHC) && isobject_BM(ob__1XzuICo9tMz_2FMOEMMgKHC)) {
  char idbuf__1XzuICo9tMz_2FMOEMMgKHC [32];
 memset (idbuf__1XzuICo9tMz_2FMOEMMgKHC, 0, sizeof(idbuf__1XzuICo9tMz_2FMOEMMgKHC));
 idtocbuf32_BM (objid_BM (ob__1XzuICo9tMz_2FMOEMMgKHC), idbuf__1XzuICo9tMz_2FMOEMMgKHC);
 objstrbufferappendcstrpayl_BM(obsbuf__1XzuICo9tMz_2FMOEMMgKHC, idbuf__1XzuICo9tMz_2FMOEMMgKHC);
};
// end objstrbufferprintobjid _1XzuICo9tMz_2FMOEMMgKHC
;    
} // end cexpansion _1XzuICo9tMz_2FMOEMMgKHC - objstrbufferprintobjid    
    
//+ #4/13 of block _3VVvcLyYqv8_9yci7GvqEEv ::    
  
{ // start cexpansion _9osbAnIQdp8_6wVcWPdPIBQ - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( "</tt></p>\n"));   
} // end cexpansion _9osbAnIQdp8_6wVcWPdPIBQ - objstrbufferappendcstrpayl   
   
  
 /*v_queryfoo:*/_.v_8s5u19T0e2h_9ZqrO3YZDVS = //assign _5Aqv9Xln871_5IcSxT4moVS   
/*objwebexchangerequestcstrquerypayl:*/objwebexchangerequestcstrquerypayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx),( "foo"));  
  
//+ #6/13 of block _3VVvcLyYqv8_9yci7GvqEEv ::  
  
 /*v_postbar:*/_.v_2nnQQ6Lvtpl_4oCJYx90FlI = //assign _3vXdUQt5mey_5MeGY4lFI0J   
/*objwebexchangerequestcstrpostpayl:*/objwebexchangerequestcstrpostpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx),( "bar"));  
  
  
if /*cond _2THq8nc1q1F_4cGFcYCkXve*/   
/*when _60Hl1XdMfUK_1F8CwPaYrTV:*/  
 ( /*v_queryfoo:*/_.v_8s5u19T0e2h_9ZqrO3YZDVS) { //body when _60Hl1XdMfUK_1F8CwPaYrTV   
{ // start cexpansion _6QzWx6GgQRi_384FRK3jVwG - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( "<p>With <i>foo</i> query: <tt>"));    
} // end cexpansion _6QzWx6GgQRi_384FRK3jVwG - objstrbufferappendcstrpayl    
{ // start cexpansion _6KDkrFdjO9P_14wFqrvJOfp - objstrbufferprinthtmlstringval    
/*objstrbufferprinthtmlstringval:*/
if (objhasstrbufferpayl_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx) && isstring_BM( /*v_queryfoo:*/_.v_8s5u19T0e2h_9ZqrO3YZDVS))
  objstrbufferencodedhtmlpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), bytstring_BM( /*v_queryfoo:*/_.v_8s5u19T0e2h_9ZqrO3YZDVS), lenstring_BM( /*v_queryfoo:*/_.v_8s5u19T0e2h_9ZqrO3YZDVS));;    
} // end cexpansion _6KDkrFdjO9P_14wFqrvJOfp - objstrbufferprinthtmlstringval    
{ // start cexpansion _2vbuTjbZtsO_572Ywmb2g5P - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( "</tt></p>\n"));    
} // end cexpansion _2vbuTjbZtsO_572Ywmb2g5P - objstrbufferappendcstrpayl    
   
} //endwhen _60Hl1XdMfUK_1F8CwPaYrTV   
else { /*cond else _2THq8nc1q1F_4cGFcYCkXve*/   
{ // start cexpansion _6RNWoVxR1o8_1HcOAeanMtD - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( "<p><b>No</b> <i>foo</i> query!</p>\n"));   
} // end cexpansion _6RNWoVxR1o8_1HcOAeanMtD - objstrbufferappendcstrpayl   
} /*cond else _2THq8nc1q1F_4cGFcYCkXve*/   
/*endcond _2THq8nc1q1F_4cGFcYCkXve*/  
  
//+ #8/13 of block _3VVvcLyYqv8_9yci7GvqEEv ::  
  
if /*cond _057nvpyNs61_4NN6PpJ3blv*/   
/*when _3nPbGhqwKVU_6YbKeoirRRT:*/  
 ( /*v_postbar:*/_.v_2nnQQ6Lvtpl_4oCJYx90FlI) { //body when _3nPbGhqwKVU_6YbKeoirRRT   
{ // start cexpansion _8iDfqbg4KqL_76BIqjTrj3e - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( "<p>With <i>bar</i> query post: <tt>"));    
} // end cexpansion _8iDfqbg4KqL_76BIqjTrj3e - objstrbufferappendcstrpayl    
{ // start cexpansion _27sh4N25FsE_1pTCEF1T86V - objstrbufferprinthtmlstringval    
/*objstrbufferprinthtmlstringval:*/
if (objhasstrbufferpayl_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx) && isstring_BM( /*v_postbar:*/_.v_2nnQQ6Lvtpl_4oCJYx90FlI))
  objstrbufferencodedhtmlpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), bytstring_BM( /*v_postbar:*/_.v_2nnQQ6Lvtpl_4oCJYx90FlI), lenstring_BM( /*v_postbar:*/_.v_2nnQQ6Lvtpl_4oCJYx90FlI));;    
} // end cexpansion _27sh4N25FsE_1pTCEF1T86V - objstrbufferprinthtmlstringval    
{ // start cexpansion _8OWeFkBKHSs_8iHHVgkRKA9 - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( "</tt></p>\n"));    
} // end cexpansion _8OWeFkBKHSs_8iHHVgkRKA9 - objstrbufferappendcstrpayl    
   
} //endwhen _3nPbGhqwKVU_6YbKeoirRRT   
else { /*cond else _057nvpyNs61_4NN6PpJ3blv*/   
{ // start cexpansion _1KQI2bY1P58_8cNaZP3fXxP - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( "<p><b>No</b> <i>bar</i> post!</p>\n"));   
} // end cexpansion _1KQI2bY1P58_8cNaZP3fXxP - objstrbufferappendcstrpayl   
} /*cond else _057nvpyNs61_4NN6PpJ3blv*/   
/*endcond _057nvpyNs61_4NN6PpJ3blv*/  
  
  
{ // start cexpansion _1cxOV5GldRc_8pSs0K0x3sK - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( "<form method=\'post\'><i>bar:</i> <input type=\'text\' name=\'bar\'/> <input type=\'submit\' name=\'dosubmit\' value=\'do!\'/> </form>\n"));   
} // end cexpansion _1cxOV5GldRc_8pSs0K0x3sK - objstrbufferappendcstrpayl   
   
//+ #10/13 of block _3VVvcLyYqv8_9yci7GvqEEv ::   
  
{ // start cexpansion _5fVxVvN0D70_5iLoRUEbGnA - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( "<p>Generated at <i>"));   
} // end cexpansion _5fVxVvN0D70_5iLoRUEbGnA - objstrbufferappendcstrpayl   
   
  
{ // start cexpansion _6nzVdVGk8wB_0paW5wP6NFo - objstrbufferprinthtmlstringval   
/*objstrbufferprinthtmlstringval:*/
if (objhasstrbufferpayl_BM( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx) && isstring_BM(/*flocaltimestring:*/(value_tyBM) flocaltimestring_BM(( "%c"),(time_t)(/*timenow:*/(intptr_t)time(NULL)))))
  objstrbufferencodedhtmlpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), bytstring_BM(/*flocaltimestring:*/(value_tyBM) flocaltimestring_BM(( "%c"),(time_t)(/*timenow:*/(intptr_t)time(NULL)))), lenstring_BM(/*flocaltimestring:*/(value_tyBM) flocaltimestring_BM(( "%c"),(time_t)(/*timenow:*/(intptr_t)time(NULL)))));;    
} // end cexpansion _6nzVdVGk8wB_0paW5wP6NFo - objstrbufferprinthtmlstringval    
    
  
{ // start cexpansion _9xLEdrWsdEt_3HIoqy3EsOT - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( "</i>.</p>\n"));   
} // end cexpansion _9xLEdrWsdEt_3HIoqy3EsOT - objstrbufferappendcstrpayl   
   
/* !endingblock _3VVvcLyYqv8_9yci7GvqEEv */  
goto endblock__3VVvcLyYqv8_9yci7GvqEEv;  
endblock__3VVvcLyYqv8_9yci7GvqEEv: ;  
} /*-block _3VVvcLyYqv8_9yci7GvqEEv */ 
 
{ // start cexpansion _7JswZzcJki7_3B8LL8KLffZ - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( "</body>\n</html>"));  
} // end cexpansion _7JswZzcJki7_3B8LL8KLffZ - objstrbufferappendcstrpayl  
  
//+ #4/6 of block _8prn9eFlYZD_6JJKKh2b8KW ::  
 
{ // start cexpansion _0aLvox3qw9g_6O8WY6Cew3g - objwebexchangecompletepayl  
/*objwebexchangecompletepayl:*/ objwebexchangecompletepayl_BM(( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx), ( 200), ( "text/html; charset=utf-8"));  
} // end cexpansion _0aLvox3qw9g_6O8WY6Cew3g - objwebexchangecompletepayl  
  
 
/*return _8VHbQSvNRq4_44CGuKiIMLb:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx; 
 goto epilog_0cUdonky1bM_4IVhwlVRBMk; 
 
/* !endingblock _8prn9eFlYZD_6JJKKh2b8KW */ 
goto endblock__8prn9eFlYZD_6JJKKh2b8KW; 
endblock__8prn9eFlYZD_6JJKKh2b8KW: ; 
} /*-block _8prn9eFlYZD_6JJKKh2b8KW */

 epilog_0cUdonky1bM_4IVhwlVRBMk: __attribute__ ((unused)); // routine _0cUdonky1bM_4IVhwlVRBMk epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _0cUdonky1bM_4IVhwlVRBMk routine#1 _0cUdonky1bM_4IVhwlVRBMk




value_tyBM crout_0g1CBaxjMIB_7NZdyHUikLG_BM //#2
 (struct stackframe_stBM* stkf, //
//!out#readmacro (v_node v_lineno v_colpos o_parser)
  // 4 arguments
  const value_tyBM arg0,  // v_node
  const value_tyBM arg1,  // v_lineno
  const value_tyBM arg2,  // v_colpos
  const value_tyBM arg3,  // o_parser
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _0g1CBaxjMIB_7NZdyHUikLG
  struct frame_0g1CBaxjMIB_7NZdyHUikLG_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 9 local values:
    value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
    objectval_tyBM* o_13K9OfeXRZR_84nyRTtoj81; // o_conn
    value_tyBM v_20uyDk84Vub_7xsAwkSm7lL; // v_lineno
    value_tyBM v_2BkOxf2KbS8_3bswrKbmgjy; // v_node
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_44FTjgRn7Px_0AfVbgmgP6l; // o_varbuffer
    objectval_tyBM* o_4jyHvEiEzZ1_9ck99ShNTHx; // o_resobj
    objectval_tyBM* o_5fGGXIme43z_0mc4HIwzzMj; // o_parser
    value_tyBM v_7llbD3YIz2G_3vDyN1QuPCy; // v_colpos
    /// 5 local numbers:
    intptr_t n_2sygPI8PHgL_4RgFW0PkZbd; // i_colpos
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_4Dke6KoVx5r_1CoVhK8mVmc; // i_start
    intptr_t n_6x2LYnlYgQG_6FXtmtwODgo; // i_lineno
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
   } _;
   memset (&_, 0, sizeof(struct frame_0g1CBaxjMIB_7NZdyHUikLG_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 9;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[3] /*|_0g1CBaxjMIB_7NZdyHUikLG*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // locking 1:
    objectval_tyBM* locked_2JvEoBxMhy7_9DZyjgGfHlv = NULL; // for o_resobj
   // fetch 4 arguments:
   _.v_2BkOxf2KbS8_3bswrKbmgjy = arg0; // v_node
   _.v_20uyDk84Vub_7xsAwkSm7lL = arg1; // v_lineno
   _.v_7llbD3YIz2G_3vDyN1QuPCy = arg2; // v_colpos
   _.o_5fGGXIme43z_0mc4HIwzzMj = objectcast_BM (arg3); // o_parser
   // fetched 4 arguments.
   // no closed values in _0g1CBaxjMIB_7NZdyHUikLG.
   // routine _0g1CBaxjMIB_7NZdyHUikLG body:

startblock__8Zow03fhyT0_8uAZxZPDM5k: __attribute__((unused));
{ /* +block _8Zow03fhyT0_8uAZxZPDM5k */ 
 /*i_lineno:*/_.n_6x2LYnlYgQG_6FXtmtwODgo = //assign _67dfantiJB6_0raShkMRDHL  
 /* val_to_int */ getint_BM( /*v_lineno:*/_.v_20uyDk84Vub_7xsAwkSm7lL) ; 
 
 
 /*i_colpos:*/_.n_2sygPI8PHgL_4RgFW0PkZbd = //assign _7pGANo80KI0_7YOZDlNgX2W  
 /* val_to_int */ getint_BM( /*v_colpos:*/_.v_7llbD3YIz2G_3vDyN1QuPCy) ; 
 
//+ #2/14 of block _8Zow03fhyT0_8uAZxZPDM5k :: 
 
 
{ // run _8SHsRPR2LVk_8x3tbafZmza 
/*debug out#readmacro start  v_node lineno colpos o_parser*/
DBGPRINTF_BM("out#readmacro start €%.9s v_node=%s lineno#%ld colpos#%ld o_parser=%s",
 "_8SHsRPR2LVk_8x3tbafZmza",
 OUTSTRVALUE_BM( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),
 (long int)( /*i_lineno:*/_.n_6x2LYnlYgQG_6FXtmtwODgo),
 (long int) ( /*i_colpos:*/_.n_2sygPI8PHgL_4RgFW0PkZbd),
 objectdbg_BM( /*o_parser:*/_.o_5fGGXIme43z_0mc4HIwzzMj));; 
} // end run _8SHsRPR2LVk_8x3tbafZmza 
 
 
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _4Cj2wfMNdSb_4STaolxG6qN  
/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy); 
 
//+ #4/14 of block _8Zow03fhyT0_8uAZxZPDM5k :: 
 
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _210mSO8s3LZ_9iKjW7eaG6Q  
/*nodenthson:*/nodenthson_BM(( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)); 
 
 
 /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81 = //assign _7wn1KeIUJpE_8XLnDlRd9Wn  
/*nodeconn:*/nodeconn_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe); 
 
//+ #6/14 of block _8Zow03fhyT0_8uAZxZPDM5k :: 
 
if /*cond _9wmUQdGs520_80QjLaRO5pa*/  
/*when _1j5eDZEaK15_1f7jqPaTIVw:*/ 
 (/*equal_object:*/(( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81) == ( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[2] /*!in*/)))) { //body when _1j5eDZEaK15_1f7jqPaTIVw  
 /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx = //assign _0T7bvmg9y4B_6u9BnDCdOJK   
/*val_to_object:*/objectcast_BM(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0)));  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _0x6O4kjsMGP_6yqdEXIJI0J   
/*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1));  
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _4dAzkespyiw_5Rpy5MMVlOv   
/*nodenthson:*/nodenthson_BM(( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));  
 /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81 = //assign _9QoBtoGxJiH_9R9rdZ9gZVe   
/*nodeconn:*/nodeconn_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe);  
  
} //endwhen _1j5eDZEaK15_1f7jqPaTIVw  
/*endcond _9wmUQdGs520_80QjLaRO5pa*/ 
 
 
 /*o_varbuffer:*/_.o_44FTjgRn7Px_0AfVbgmgP6l = //assign _5Oe3n0McSTK_9Wa3aPWE2FN  
/*val_to_object:*/objectcast_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe); 
 
//+ #8/14 of block _8Zow03fhyT0_8uAZxZPDM5k :: 
 
if /*cond _3vYKetVH6Qm_1DQknEXgz82*/  
/*when _7J0ls8Ka2yx_3fBvjSLJUo1:*/ 
 (/*is_null:*/(( /*o_varbuffer:*/_.o_44FTjgRn7Px_0AfVbgmgP6l)==NULL)) { //body when _7J0ls8Ka2yx_3fBvjSLJUo1  
  
{ // run _8PSnZGiFcKI_0SN4CeFLS2d  
/*syntax-error no o_varbuffer*/
objparserrorprintf_BM( /*o_parser:*/_.o_5fGGXIme43z_0mc4HIwzzMj, CURFRAME_BM,  /*i_lineno:*/_.n_6x2LYnlYgQG_6FXtmtwODgo,  /*i_colpos:*/_.n_2sygPI8PHgL_4RgFW0PkZbd, "missing varbuffer in ^out([*in(...)] varbuffer outputs...)");
;  
} // end run _8PSnZGiFcKI_0SN4CeFLS2d  
  
} //endwhen _7J0ls8Ka2yx_3fBvjSLJUo1  
/*endcond _3vYKetVH6Qm_1DQknEXgz82*/ 
 
 
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _7fh7LUbhBaX_8aeMudPobHE  
/*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1)); 
 
//+ #10/14 of block _8Zow03fhyT0_8uAZxZPDM5k :: 
 
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _2mmddNFAEgd_4oaodbVOC2R  
/*nodenthson:*/nodenthson_BM(( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)); 
 
 
 /*i_start:*/_.n_4Dke6KoVx5r_1CoVhK8mVmc = //assign _4fVIgCrLJzj_8pmTR4KWfsE  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B; 
 
//+ #12/14 of block _8Zow03fhyT0_8uAZxZPDM5k :: 
 
if /*cond _0vn7ueI4Bxr_4hnicjlB78i*/  
/*when _6utotmA8SWn_4ZHG6JuneX9:*/ 
 (/*is_null:*/(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx)==NULL)) { //body when _6utotmA8SWn_4ZHG6JuneX9  
 /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx = //assign _6fXfi9x99V4_8dSOffH1aBN   
/*makeobj:*/makeobj_BM();  
{ // start cexpansion _2JM5j1QuRSt_5QR1vdsuXJf - objputglobalspace   
/*objputglobalspace:*/objputspacenum_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx), GlobalSp_BM);;   
} // end cexpansion _2JM5j1QuRSt_5QR1vdsuXJf - objputglobalspace   
  
} //endwhen _6utotmA8SWn_4ZHG6JuneX9  
/*endcond _0vn7ueI4Bxr_4hnicjlB78i*/ 
 
 
 
{ // begin lockobj _2JvEoBxMhy7_9DZyjgGfHlv 
  objectval_tyBM* curlockedob_2JvEoBxMhy7_9DZyjgGfHlv = ( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx); 
if (objlock_BM (curlockedob_2JvEoBxMhy7_9DZyjgGfHlv)) {  
locked_2JvEoBxMhy7_9DZyjgGfHlv = curlockedob_2JvEoBxMhy7_9DZyjgGfHlv;  
  
if /*cond _4YKlELDYVOV_8RhceZSyfIv*/  
/*when _8g6tUrNeSaK_9pEbME2mJdL:*/ 
 (/*not:*/ (! (/*objectisinstance:*/ objectisinstance_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[86] /*!basiclo_outstmt*/)))))) { //body when _8g6tUrNeSaK_9pEbME2mJdL  
{ // start cexpansion _8Zs5gF0Cjtl_8nrkFlDX8H6 - objputclass   
/*objputclass:*/objputclass_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[86] /*!basiclo_outstmt*/)));   
} // end cexpansion _8Zs5gF0Cjtl_8nrkFlDX8H6 - objputclass   
  
} //endwhen _8g6tUrNeSaK_9pEbME2mJdL  
/*endcond _4YKlELDYVOV_8RhceZSyfIv*/ 
  
{ // start cexpansion _5ZvpQtV9DIb_5eIJPzrSdXF - objresetattrs  
/*objresetattrs:*/ objresetattrs_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),(unsigned)(/*substract_int:*/(( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) - ( /*i_start:*/_.n_4Dke6KoVx5r_1CoVhK8mVmc))));   
} // end cexpansion _5ZvpQtV9DIb_5eIJPzrSdXF - objresetattrs   
  
//+ #2/8 of lockobj _2JvEoBxMhy7_9DZyjgGfHlv ::  
{ // start cexpansion _4j8Yw7eNafO_3G8sPVjnCN9 - objresetattrs  
/*objresetattrs:*/ objresetattrs_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),(unsigned)( 5));  
} // end cexpansion _4j8Yw7eNafO_3G8sPVjnCN9 - objresetattrs  
  
{ // start cexpansion _1WbhqznDBxp_9TvXYU0SNFk - objputattr  
/*objputattr:*/objputattr_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[7] /*!out*/)),( /*o_varbuffer:*/_.o_44FTjgRn7Px_0AfVbgmgP6l));  
} // end cexpansion _1WbhqznDBxp_9TvXYU0SNFk - objputattr  
  
//+ #4/8 of lockobj _2JvEoBxMhy7_9DZyjgGfHlv ::  
 
//// +while _3TURPJpX7th_5T3UCSyjzvv 
startblock__3TURPJpX7th_5T3UCSyjzvv:  /*+!while*/; 
{ /* +while _3TURPJpX7th_5T3UCSyjzvv */  
if (!(/*while _3TURPJpX7th_5T3UCSyjzvv cond:*/ (/*less_int:*/( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) < ( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k)))) //: testwhile _3TURPJpX7th_5T3UCSyjzvv failing   
  goto endblock__3TURPJpX7th_5T3UCSyjzvv; //failwhile   
// while _3TURPJpX7th_5T3UCSyjzvv body:   
// while _3TURPJpX7th_5T3UCSyjzvv comp#0:  
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _2JzmSXbqwbW_6p4oLUW30vv   
/*nodenthson:*/nodenthson_BM(( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));  
// while _3TURPJpX7th_5T3UCSyjzvv comp#1:  
  
{ // run _5zWYWtzwfjO_0F4myA3zQ0o  
/*debug loop out#readmacro ii v_comp v_node o_resobj*/
 DBGPRINTF_BM("loop out#readmacro €%.9s ii#%ld v_comp=%s v_node=%s o_resobj=%s",
 "_5zWYWtzwfjO_0F4myA3zQ0o",
 (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
 OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
 OUTSTRVALUE_BM( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),
 objectdbg_BM( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx));;  
} // end run _5zWYWtzwfjO_0F4myA3zQ0o  
// while _3TURPJpX7th_5T3UCSyjzvv comp#2:  
{ // start cexpansion _72SahaxYkMv_43rvkWpzaWy - objappendcomp   
/*objappendcomp:*/objappendcomp_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe));   
} // end cexpansion _72SahaxYkMv_43rvkWpzaWy - objappendcomp   
// while _3TURPJpX7th_5T3UCSyjzvv comp#3:  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _95oYoloIJKx_07EE4Ommri7   
/*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1));  
  
goto startblock__3TURPJpX7th_5T3UCSyjzvv; // repeatwhile  
endblock__3TURPJpX7th_5T3UCSyjzvv: /*endingwhile*/;  
} /*-endwhile _3TURPJpX7th_5T3UCSyjzvv */ 
 
  
{ // start cexpansion _4k7bXst8Ysh_6rBll1H8CUo - objtouchnow  
/*objtouchnow:*/objtouchnow_BM( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx);;  
} // end cexpansion _4k7bXst8Ysh_6rBll1H8CUo - objtouchnow  
  
//+ #6/8 of lockobj _2JvEoBxMhy7_9DZyjgGfHlv ::  
 
{ // run _0nQH8PHR97P_03T6CUirdCG 
/*debug out#readmacro end o_resobj*/
DBGPRINTF_BM("out#readmacro end €%.9s o_resobj=%s",
 "_0nQH8PHR97P_03T6CUirdCG",
 objectdbg_BM( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx));
; 
} // end run _0nQH8PHR97P_03T6CUirdCG 
  
/*return _0IHnwGG1GxP_4kooak9wiyM:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx; 
 goto epilog_0g1CBaxjMIB_7NZdyHUikLG; 
  
objunlock_BM (locked_2JvEoBxMhy7_9DZyjgGfHlv), locked_2JvEoBxMhy7_9DZyjgGfHlv = NULL; 
} } // end objlock _2JvEoBxMhy7_9DZyjgGfHlv 
/* !endingblock _8Zow03fhyT0_8uAZxZPDM5k */ 
goto endblock__8Zow03fhyT0_8uAZxZPDM5k; 
endblock__8Zow03fhyT0_8uAZxZPDM5k: ; 
} /*-block _8Zow03fhyT0_8uAZxZPDM5k */

 epilog_0g1CBaxjMIB_7NZdyHUikLG: __attribute__ ((unused)); // routine _0g1CBaxjMIB_7NZdyHUikLG epilogue:
   // unlocking 1:
    if (locked_2JvEoBxMhy7_9DZyjgGfHlv != NULL)
       objunlock_BM(locked_2JvEoBxMhy7_9DZyjgGfHlv), locked_2JvEoBxMhy7_9DZyjgGfHlv = NULL; // for o_resobj
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _0g1CBaxjMIB_7NZdyHUikLG routine#2 _0g1CBaxjMIB_7NZdyHUikLG




value_tyBM crout_0vCFi47Ctm6_70R5Tci6JuH_BM //#3
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[6] /*|_0vCFi47Ctm6_70R5Tci6JuH*/;
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
/*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[65] /*!index*/)))); 
  
 /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU = //assign _6LSBFvxlbNc_0rY6zQlblXq  
/*objgetattr:*/objgetattr_BM(( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[56] /*!count*/))); 
  
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
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[39] /*!basiclo_block*/)))) { //body when _0XHPA7cptAe_4i19aTf4Gxq    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _1FhisSY6VvV_9wuNntndHjA     
(send3_BM (( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), /*sel:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[62] /*!emit_block*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),  ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));    
    
} //endwhen _0XHPA7cptAe_4i19aTf4Gxq    
else if    
/*when _0H7JvNndU7R_1y4eLjc1NUL:*/   
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[41] /*!basiclo_statement*/)))) { //body when _0H7JvNndU7R_1y4eLjc1NUL    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _2mKWX3OmQZn_4ros3plkqLz     
(send3_BM (( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), /*sel:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[17] /*!emit_statement*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),  ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));    
    
} //endwhen _0H7JvNndU7R_1y4eLjc1NUL    
else { /*cond else _2EhWIVvxjvU_1ISxJRsN8RH*/    
//failure _6MTJtvsUEYW_9WuS0LnLfmm    
PLACEDFAILURE_BM(__LINE__,    
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[44] /*!failure_bad_class*/)), 
 /*make_node 5 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[6] /*!_0vCFi47Ctm6_70R5Tci6JuH*/)), 
 
( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), 
 
( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[66] /*|_6MTJtvsUEYW_9WuS0LnLfmm*/)),
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
 (/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[48] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[6] /*!_0vCFi47Ctm6_70R5Tci6JuH*/)), 
 
( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), 
 
( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[34] /*|_3CZ4Lq3VkJF_3Qt5nkQ9R3w*/)),
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
} // end _0vCFi47Ctm6_70R5Tci6JuH routine#3 _0vCFi47Ctm6_70R5Tci6JuH




value_tyBM crout_0JktC4mAHCa_1KNr6uMIqIi_BM //#4
 (struct stackframe_stBM* stkf, //
//!dump_scan°list_object minifunc for list_object o1 & dumperobj o2
  // 2 arguments
  const value_tyBM arg0,  // o1
  const value_tyBM arg1,  // o2
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _0JktC4mAHCa_1KNr6uMIqIi
  struct frame_0JktC4mAHCa_1KNr6uMIqIi_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 4 local values:
    value_tyBM v_2BkOxf2KbS8_3bswrKbmgjy; // v_node
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_93FBSk1ML0f_2WjSuKa9TNU; // o2
    objectval_tyBM* o_97rnxb0KFqq_44veN75DG2E; // o1
    /// 2 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
   } _;
   memset (&_, 0, sizeof(struct frame_0JktC4mAHCa_1KNr6uMIqIi_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 4;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[9] /*|_0JktC4mAHCa_1KNr6uMIqIi*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 2 arguments:
   _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0); // o1
   _.o_93FBSk1ML0f_2WjSuKa9TNU = objectcast_BM (arg1); // o2
   // fetched 2 arguments.
   // no closed values in _0JktC4mAHCa_1KNr6uMIqIi.
   // routine _0JktC4mAHCa_1KNr6uMIqIi body:

startblock__9xHQlk4snoU_6unWwGT6PcG: __attribute__((unused));
{ /* +block _9xHQlk4snoU_6unWwGT6PcG */ 
 /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy = //assign _8ggHPTQI1iG_02hVE5KybEL  
/*objlisttonodepayl:*/ (value_tyBM) objlisttonodepayl_BM(( /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[70] /*|node*/))); 
 
 
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _0zhpGzEVWGP_7WoL4LJocuS  
/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy); 
 
//+ #2/4 of block _9xHQlk4snoU_6unWwGT6PcG :: 
 
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _0fygl91r6x5_8b3aCDptjAi  
 0; 
 
 
 
//// +while _1w1gkKpMOzk_6mZXddz3Y4L 
startblock__1w1gkKpMOzk_6mZXddz3Y4L:  /*+!while*/; 
{ /* +while _1w1gkKpMOzk_6mZXddz3Y4L */  
if (!(/*while _1w1gkKpMOzk_6mZXddz3Y4L cond:*/ (/*less_int:*/( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) < ( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k)))) //: testwhile _1w1gkKpMOzk_6mZXddz3Y4L failing   
  goto endblock__1w1gkKpMOzk_6mZXddz3Y4L; //failwhile   
// while _1w1gkKpMOzk_6mZXddz3Y4L body:   
// while _1w1gkKpMOzk_6mZXddz3Y4L comp#0:  
{ // start cexpansion _4048rnGI686_6URARAINwQH - obdumpscanvalue   
/*obdumpscanvalue:*/ obdumpscanvalue_BM(( /*o2:*/_.o_93FBSk1ML0f_2WjSuKa9TNU), (/*nodenthson:*/nodenthson_BM(( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B))), ( 0));   
} // end cexpansion _4048rnGI686_6URARAINwQH - obdumpscanvalue   
// while _1w1gkKpMOzk_6mZXddz3Y4L comp#1:  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _5fibWpWyCTN_8xn6wySOLhA   
/*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1));  
  
goto startblock__1w1gkKpMOzk_6mZXddz3Y4L; // repeatwhile  
endblock__1w1gkKpMOzk_6mZXddz3Y4L: /*endingwhile*/;  
} /*-endwhile _1w1gkKpMOzk_6mZXddz3Y4L */ 
 
 
/* !endingblock _9xHQlk4snoU_6unWwGT6PcG */ 
goto endblock__9xHQlk4snoU_6unWwGT6PcG; 
endblock__9xHQlk4snoU_6unWwGT6PcG: ; 
} /*-block _9xHQlk4snoU_6unWwGT6PcG */

 epilog_0JktC4mAHCa_1KNr6uMIqIi: __attribute__ ((unused)); // routine _0JktC4mAHCa_1KNr6uMIqIi epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _0JktC4mAHCa_1KNr6uMIqIi routine#4 _0JktC4mAHCa_1KNr6uMIqIi




value_tyBM crout_0SinERsgdvQ_57dLCP63i9r_BM //#5
 (struct stackframe_stBM* stkf, //
//!forgetname#command_handler
  // 1 arguments
  const value_tyBM arg0,  // v_arg
  const value_tyBM arg1_ __attribute__((unused)),
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _0SinERsgdvQ_57dLCP63i9r
  struct frame_0SinERsgdvQ_57dLCP63i9r_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 3 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    value_tyBM v_4Q4WBLjAPTV_5WVLmhAvCJY; // v_arg
    objectval_tyBM* o_7daWyW7jPyL_0EvyGgObjJm; // o_arg
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_0SinERsgdvQ_57dLCP63i9r_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 3;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[10] /*|_0SinERsgdvQ_57dLCP63i9r*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 1 arguments:
   _.v_4Q4WBLjAPTV_5WVLmhAvCJY = arg0; // v_arg
   // fetched 1 arguments.
   // no closed values in _0SinERsgdvQ_57dLCP63i9r.
   // routine _0SinERsgdvQ_57dLCP63i9r body:

startblock__84ATc5kpHjd_2wlYHZEUoeb: __attribute__((unused));
{ /* +block _84ATc5kpHjd_2wlYHZEUoeb */ 
if /*cond _0Vnb5tJpsaA_9C18YQWoCmH*/  
/*when _7aRr2DYoXS7_0jbH59RVcFR:*/ 
 (/*is_objectv*/ isobject_BM( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY)) { //body when _7aRr2DYoXS7_0jbH59RVcFR  
 /*o_arg:*/_.o_7daWyW7jPyL_0EvyGgObjJm = //assign _1eDeH7xPojd_3uCQMEEBsHc   
/*val_to_object:*/objectcast_BM( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY);  
  
{ // run _5cqLFnQUJtD_2QMjkdfqr6q  
forgetnamedobject_BM( /*o_arg:*/_.o_7daWyW7jPyL_0EvyGgObjJm);  
} // end run _5cqLFnQUJtD_2QMjkdfqr6q  
  
{ // run _8y60zCwYsj4_4MKReQrfwGI  
if (pthread_self() == mainthreadid_BM) {
 log_begin_message_BM ();
 log_puts_message_BM ("Forgot name of object ");
 log_object_message_BM ( /*o_arg:*/_.o_7daWyW7jPyL_0EvyGgObjJm);
 log_puts_message_BM (".");
 log_end_message_BM ();
}
;  
} // end run _8y60zCwYsj4_4MKReQrfwGI  
/*return _8X0BDdDTJe6_8OoRGA5RDeF:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned  
 /*o_arg:*/_.o_7daWyW7jPyL_0EvyGgObjJm;  
 goto epilog_0SinERsgdvQ_57dLCP63i9r;  
  
} //endwhen _7aRr2DYoXS7_0jbH59RVcFR  
else if  
/*when _3674ULyT2hz_5gMJA95w9aB:*/ 
 (/*issequence:*/issequence_BM( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY)) { //body when _3674ULyT2hz_5gMJA95w9aB  
  
{ // run _2Gx3OIyj6WH_36HZRfp3Slv  
(apply1_BM (( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[78] /*!iterate_sequence_minifunc*/)), ((struct stackframe_stBM*)&_),    
 ( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[10] /*!_0SinERsgdvQ_57dLCP63i9r*/))));  
} // end run _2Gx3OIyj6WH_36HZRfp3Slv  
  
} //endwhen _3674ULyT2hz_5gMJA95w9aB  
/*endcond _0Vnb5tJpsaA_9C18YQWoCmH*/ 
 
/* !endingblock _84ATc5kpHjd_2wlYHZEUoeb */ 
goto endblock__84ATc5kpHjd_2wlYHZEUoeb; 
endblock__84ATc5kpHjd_2wlYHZEUoeb: ; 
} /*-block _84ATc5kpHjd_2wlYHZEUoeb */

 epilog_0SinERsgdvQ_57dLCP63i9r: __attribute__ ((unused)); // routine _0SinERsgdvQ_57dLCP63i9r epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _0SinERsgdvQ_57dLCP63i9r routine#5 _0SinERsgdvQ_57dLCP63i9r




value_tyBM crout_0YOXUe7rEJC_3jFMjOAQRs9_BM //#6+
 (struct stackframe_stBM* stkf, // element_of_closed_minifunc
//!return argument if it is contained in the closed set
  // 1 arguments
  const value_tyBM arg0,  // v_arg
  const value_tyBM arg1_ __attribute__((unused)),
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of element_of_closed_minifunc
  struct frame_0YOXUe7rEJC_3jFMjOAQRs9_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 4 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    value_tyBM v_4Q4WBLjAPTV_5WVLmhAvCJY; // v_arg
    value_tyBM v_5EEITf6IFH7_4DbKG99zcPW; // v1
    objectval_tyBM* o_97rnxb0KFqq_44veN75DG2E; // o1
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_0YOXUe7rEJC_3jFMjOAQRs9_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 4;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[11] /*|element_of_closed_minifunc*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 1 arguments:
   _.v_4Q4WBLjAPTV_5WVLmhAvCJY = arg0; // v_arg
   // fetched 1 arguments.
   { // fetch 1 closed values in element_of_closed_minifunc:
   const closure_tyBM* callclos_0YOXUe7rEJC_3jFMjOAQRs9 =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   unsigned nbclosed_0YOXUe7rEJC_3jFMjOAQRs9 = closurewidth_BM ((const value_tyBM) callclos_0YOXUe7rEJC_3jFMjOAQRs9);
   if (nbclosed_0YOXUe7rEJC_3jFMjOAQRs9 > 0)
      _.v_5EEITf6IFH7_4DbKG99zcPW = callclos_0YOXUe7rEJC_3jFMjOAQRs9->nodt_sons[0]; // v1
   } // fetched 1 closed values in _0YOXUe7rEJC_3jFMjOAQRs9.
   // routine _0YOXUe7rEJC_3jFMjOAQRs9 body:

startblock__7gnMvoTqaQY_3kAwj2rwZEM: __attribute__((unused));
{ /* +block _7gnMvoTqaQY_3kAwj2rwZEM */ 
 /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E = //assign _11EvX29IHDi_1da6fY8nL7Y  
/*val_to_object:*/objectcast_BM( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY); 
 
 
if /*cond _0WAyTs536mS_7eZ58PLoYjP*/  
/*when _2U8EKCOdizu_8BNXvpmwd43:*/ 
 ((/*set_contains:*/ setcontains_BM(( /*v1:*/_.v_5EEITf6IFH7_4DbKG99zcPW), ( /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E)))) { //body when _2U8EKCOdizu_8BNXvpmwd43  
/*return _4rFgWAf3aqA_0UBP8b4hESV:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned  
 /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E;  
 goto epilog_0YOXUe7rEJC_3jFMjOAQRs9;  
  
} //endwhen _2U8EKCOdizu_8BNXvpmwd43  
/*endcond _0WAyTs536mS_7eZ58PLoYjP*/ 
 
/* !endingblock _7gnMvoTqaQY_3kAwj2rwZEM */ 
goto endblock__7gnMvoTqaQY_3kAwj2rwZEM; 
endblock__7gnMvoTqaQY_3kAwj2rwZEM: ; 
} /*-block _7gnMvoTqaQY_3kAwj2rwZEM */

 epilog_0YOXUe7rEJC_3jFMjOAQRs9: __attribute__ ((unused)); // routine _0YOXUe7rEJC_3jFMjOAQRs9 epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _0YOXUe7rEJC_3jFMjOAQRs9 routine#6 element_of_closed_minifunc




value_tyBM crout_1kz7viwMzTp_6PgLhdZzMEy_BM //#7
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[14] /*|_1kz7viwMzTp_6PgLhdZzMEy*/;
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
   // routine _1kz7viwMzTp_6PgLhdZzMEy body:

startblock__2z5wZyWhJId_3qRwMQOiLBm: __attribute__((unused));
{ /* +block _2z5wZyWhJId_3qRwMQOiLBm */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _74XT4f1vWl9_7pfkRaZCCjn  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV = //assign _5nVWpRtEEts_2uWUDb4OAKl  
/*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[7] /*!out*/)))); 
 
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
 (/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[48] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[14] /*!_1kz7viwMzTp_6PgLhdZzMEy*/)), 
 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[7] /*!out*/)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
// make_node arg #4 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[16] /*|_1m5rw0BZl8f_4M9cndtjRl8*/)),
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
 (/*unequal_value*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[72] /*!object*/)))) { //body when _6wuhAPMNDcY_0RSyScYXYj6  
//failure _6cS5VddZd7n_9Nnn2wYWAeL   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[48] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[61] /*!miniscan_var*/)), 
 
( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1)))), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[59] /*|_6cS5VddZd7n_9Nnn2wYWAeL*/)),
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
 objectval_tyBM* objswexp_3WmrD9dWzVs_6l9CVwfdtYt = ( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81);   
 switch (objecthash_BM (objswexp_3WmrD9dWzVs_6l9CVwfdtYt) % 64) {   
 case 0:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[29] /*|utf8_enc*/)) goto whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z;   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[51] /*|less_indent*/)) goto whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 2:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[69] /*|nlsp*/)) goto whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 5:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[63] /*|c_enc*/)) goto whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 6:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[26] /*|newline*/)) goto whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 11:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[72] /*|object*/)) goto whenobj3WmrD9dW__1wFGt8trU1A_1Nb4JV3o0QV;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 15:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[36] /*|html_enc*/)) goto whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 19:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[15] /*|octa*/)) goto whenobj3WmrD9dW__3Q9LapaKOXA_9lQQ7ENfb8d;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 22:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[30] /*|space*/)) goto whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m;   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[54] /*|json_indented*/)) goto whenobj3WmrD9dW__0msPpd1UF1h_6Q13YXMYlaN;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 30:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[5] /*|int*/)) goto whenobj3WmrD9dW__3Q9LapaKOXA_9lQQ7ENfb8d;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 31:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[68] /*|value*/)) goto whenobj3WmrD9dW__5FrwHPgIxS4_6QYhDVrIvKP;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 34:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[74] /*|hexa*/)) goto whenobj3WmrD9dW__3Q9LapaKOXA_9lQQ7ENfb8d;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 36:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[4] /*|more_indent*/)) goto whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 41:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[52] /*|literal_c_string*/)) goto whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 42:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[13] /*|name*/)) goto whenobj3WmrD9dW__1wFGt8trU1A_1Nb4JV3o0QV;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 47:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[43] /*|json_compact*/)) goto whenobj3WmrD9dW__0msPpd1UF1h_6Q13YXMYlaN;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 51:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[27] /*|set_indent*/)) goto whenobj3WmrD9dW__3Q9LapaKOXA_9lQQ7ENfb8d;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
 case 55:   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[47] /*|string*/)) goto whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z;   
  if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[73] /*|id*/)) goto whenobj3WmrD9dW__1wFGt8trU1A_1Nb4JV3o0QV;   
  goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;   
   
  default: defobj_3WmrD9dWzVs_6l9CVwfdtYt:;   
   
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt default#0 statement:    
//failure _5J4f6u42le4_9UZMTZziEEw     
PLACEDFAILURE_BM(__LINE__,     
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[48] /*!failure_miss*/)), 
 /*make_node 6 sons:*/ 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
// make_node arg #4 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[55] /*|_5J4f6u42le4_9UZMTZziEEw*/)),
                ((struct stackframe_stBM *) &_));
    
break; // end objswitch _3WmrD9dWzVs_6l9CVwfdtYt default    
// objswitch _3WmrD9dWzVs_6l9CVwfdtYt with 6 whens:    
    
whenobj3WmrD9dW__0msPpd1UF1h_6Q13YXMYlaN:; // when #0 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _0msPpd1UF1h_6Q13YXMYlaN #0 statement:    
if /*cond _9yQol9uXYsR_59RMrumL33A*/     
/*when _2wErgMBgydm_19t3GtzTchr:*/    
 ((/*equal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) == ( 0))) { //body when _2wErgMBgydm_19t3GtzTchr     
//failure _8QmDbXEU8lU_33mrgrh3zUR      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[48] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[60] /*!arity*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[81] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _2wErgMBgydm_19t3GtzTchr     
else if     
/*when _5AOCJ23yr6D_7kvbaU8MJQi:*/    
 ((/*greater_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) > ( 2))) { //body when _5AOCJ23yr6D_7kvbaU8MJQi     
//failure _8QmDbXEU8lU_33mrgrh3zUR      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[48] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[60] /*!arity*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[81] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
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
 (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[68] /*!value*/)))) { //body when _3FcUnG66DXT_7sllObXQZl3     
//failure _9umIVqZhssC_2WJZljFrGaA      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[82] /*!failure_type_error*/)), 
 /*make_node 8 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[68] /*!value*/)), 
 
( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[84] /*|_9umIVqZhssC_2WJZljFrGaA*/)),
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
 (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[68] /*!value*/)))) { //body when _3FcUnG66DXT_7sllObXQZl3      
//failure _9umIVqZhssC_2WJZljFrGaA       
PLACEDFAILURE_BM(__LINE__,       
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[82] /*!failure_type_error*/)), 
 /*make_node 8 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[68] /*!value*/)), 
 
( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[84] /*|_9umIVqZhssC_2WJZljFrGaA*/)),
                ((struct stackframe_stBM *) &_));
      
} //endwhen _3FcUnG66DXT_7sllObXQZl3      
/*endcond _6m3V5fOZK2n_9AFeHjYt2ZV*/     
     
} //endwhen _5Cu0QpuvxD7_8rpyE1LiWIA     
/*endcond _3L9x4LFGCuY_3oHKGr2Cr7s*/    
    
    
break; // end when _0msPpd1UF1h_6Q13YXMYlaN #0 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
    
whenobj3WmrD9dW__1wFGt8trU1A_1Nb4JV3o0QV:; // when #1 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _1wFGt8trU1A_1Nb4JV3o0QV #0 statement:    
if /*cond _0tPLTqqQhJ7_9Tr1hT1PRhR*/     
/*when _2vEPbWPCAJU_1xk1toAGUy4:*/    
 ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 1))) { //body when _2vEPbWPCAJU_1xk1toAGUy4     
//failure _8QmDbXEU8lU_33mrgrh3zUR      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[48] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[60] /*!arity*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[81] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
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
 (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[72] /*!object*/)))) { //body when _3dZuGA19JWs_2g4uoKzoqro     
//failure _2eREyARXfUb_2mTxUngIL6Y      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[82] /*!failure_type_error*/)), 
 /*make_node 8 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[72] /*!object*/)), 
 
( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[23] /*|_2eREyARXfUb_2mTxUngIL6Y*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _3dZuGA19JWs_2g4uoKzoqro     
/*endcond _6wbaBUuIONg_9YGzdsfJjeb*/    
    
    
break; // end when _1wFGt8trU1A_1Nb4JV3o0QV #1 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
    
whenobj3WmrD9dW__3Q9LapaKOXA_9lQQ7ENfb8d:; // when #2 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _3Q9LapaKOXA_9lQQ7ENfb8d #0 statement:    
if /*cond _0tPLTqqQhJ7_9Tr1hT1PRhR*/     
/*when _2vEPbWPCAJU_1xk1toAGUy4:*/    
 ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 1))) { //body when _2vEPbWPCAJU_1xk1toAGUy4     
//failure _8QmDbXEU8lU_33mrgrh3zUR      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[48] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[60] /*!arity*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[81] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
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
 (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[5] /*!int*/)))) { //body when _8dLGLcW3TGC_4jPYDTI7ixi     
//failure _26UbzubL5aT_2vDJc23p59r      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[82] /*!failure_type_error*/)), 
 /*make_node 8 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[5] /*!int*/)), 
 
( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[21] /*|_26UbzubL5aT_2vDJc23p59r*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _8dLGLcW3TGC_4jPYDTI7ixi     
/*endcond _8oSBVSRNj1v_3bsqcnGUWLD*/    
    
    
break; // end when _3Q9LapaKOXA_9lQQ7ENfb8d #2 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
    
whenobj3WmrD9dW__5FrwHPgIxS4_6QYhDVrIvKP:; // when #3 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _5FrwHPgIxS4_6QYhDVrIvKP #0 statement:    
if /*cond _0tPLTqqQhJ7_9Tr1hT1PRhR*/     
/*when _2vEPbWPCAJU_1xk1toAGUy4:*/    
 ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 1))) { //body when _2vEPbWPCAJU_1xk1toAGUy4     
//failure _8QmDbXEU8lU_33mrgrh3zUR      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[48] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[60] /*!arity*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[81] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
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
 (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[68] /*!value*/)))) { //body when _3FcUnG66DXT_7sllObXQZl3     
//failure _9umIVqZhssC_2WJZljFrGaA      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[82] /*!failure_type_error*/)), 
 /*make_node 8 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[68] /*!value*/)), 
 
( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[84] /*|_9umIVqZhssC_2WJZljFrGaA*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _3FcUnG66DXT_7sllObXQZl3     
/*endcond _6m3V5fOZK2n_9AFeHjYt2ZV*/    
    
    
break; // end when _5FrwHPgIxS4_6QYhDVrIvKP #3 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
    
whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m:; // when #4 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _88RDzd8IqdR_360tNT6O81m #0 statement:    
if /*cond _5Z3dh9fajGI_8Mjr3quXaAc*/     
/*when _2ahnIdkMBrO_2xvuzm6XiD6:*/    
 ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 0))) { //body when _2ahnIdkMBrO_2xvuzm6XiD6     
//failure _8QmDbXEU8lU_33mrgrh3zUR      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[48] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[60] /*!arity*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[81] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _2ahnIdkMBrO_2xvuzm6XiD6     
/*endcond _5Z3dh9fajGI_8Mjr3quXaAc*/    
    
    
break; // end when _88RDzd8IqdR_360tNT6O81m #4 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
    
whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z:; // when #5 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
 // objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _8v0XmN9JZTY_0xJ6ntfrc0z #0 statement:    
if /*cond _0tPLTqqQhJ7_9Tr1hT1PRhR*/     
/*when _2vEPbWPCAJU_1xk1toAGUy4:*/    
 ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 1))) { //body when _2vEPbWPCAJU_1xk1toAGUy4     
//failure _8QmDbXEU8lU_33mrgrh3zUR      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[48] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[60] /*!arity*/)), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[81] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
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
 (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[47] /*!string*/)))) { //body when _9BPjp8ame7V_0AzorRD9WNm     
//failure _4HAZLawO9HO_91oo1k4Ajat      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (8U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[82] /*!failure_type_error*/)), 
 /*make_node 8 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[47] /*!string*/)), 
 
( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I), 
 
( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[45] /*|_4HAZLawO9HO_91oo1k4Ajat*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _9BPjp8ame7V_0AzorRD9WNm     
/*endcond _6cOi4TgZpEg_7mN9SsWpWte*/    
    
    
break; // end when _8v0XmN9JZTY_0xJ6ntfrc0z #5 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt    
   
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
} // end _1kz7viwMzTp_6PgLhdZzMEy routine#7 _1kz7viwMzTp_6PgLhdZzMEy




value_tyBM crout_22Zd68WPKUO_6AoIuBcbUb2_BM //#8
 (struct stackframe_stBM* stkf, //
//!dump_scan°dict_object minifunc for dict-object odict and dumperobj odumper
  // 2 arguments
  const value_tyBM arg0,  // odict
  const value_tyBM arg1,  // odumper
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _22Zd68WPKUO_6AoIuBcbUb2
  struct frame_22Zd68WPKUO_6AoIuBcbUb2_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 5 local values:
    value_tyBM v_167WczZjWtG_3FofhJxQWJi; // v_str
    objectval_tyBM* o_3cTC8W7d75H_1vteOyEoAao; // odumper
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    value_tyBM v_5jRQCD1qTko_61I0j04ugAA; // v_val
    objectval_tyBM* o_7n2SLLuWOjH_4ArhFUjmckz; // odict
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_22Zd68WPKUO_6AoIuBcbUb2_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 5;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[20] /*|_22Zd68WPKUO_6AoIuBcbUb2*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 2 arguments:
   _.o_7n2SLLuWOjH_4ArhFUjmckz = objectcast_BM (arg0); // odict
   _.o_3cTC8W7d75H_1vteOyEoAao = objectcast_BM (arg1); // odumper
   // fetched 2 arguments.
   // no closed values in _22Zd68WPKUO_6AoIuBcbUb2.
   // routine _22Zd68WPKUO_6AoIuBcbUb2 body:

startblock__7csjYG7rNV4_68bJZT4W2BO: __attribute__((unused));
{ /* +block _7csjYG7rNV4_68bJZT4W2BO */ 
 /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi = //assign _5mCmWSYOW7T_4G9YRC6tvRf  
/*objdictfirstkeypayl:*/ (value_tyBM) objdictfirstkeypayl_BM(( /*odict:*/_.o_7n2SLLuWOjH_4ArhFUjmckz)); 
 
 
 
//// +while _0SWi4IZCeP3_0VPExGvOasL 
startblock__0SWi4IZCeP3_0VPExGvOasL:  /*+!while*/; 
{ /* +while _0SWi4IZCeP3_0VPExGvOasL */  
if (!(/*while _0SWi4IZCeP3_0VPExGvOasL cond:*/  /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)) //: testwhile _0SWi4IZCeP3_0VPExGvOasL failing  
  goto endblock__0SWi4IZCeP3_0VPExGvOasL; //failwhile  
// while _0SWi4IZCeP3_0VPExGvOasL body:  
// while _0SWi4IZCeP3_0VPExGvOasL comp#0:  
 /*v_val:*/_.v_5jRQCD1qTko_61I0j04ugAA = //assign _2dCjJpUS20B_3NM9eVa84hQ   
/*objdictgetpayl:*/ objdictgetpayl_BM(( /*odict:*/_.o_7n2SLLuWOjH_4ArhFUjmckz), stringcast_BM( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi));  
// while _0SWi4IZCeP3_0VPExGvOasL comp#1:  
{ // start cexpansion _0LKRJrD5wqK_5ZE495IAA7d - obdumpscanvalue   
/*obdumpscanvalue:*/ obdumpscanvalue_BM(( /*odumper:*/_.o_3cTC8W7d75H_1vteOyEoAao), ( /*v_val:*/_.v_5jRQCD1qTko_61I0j04ugAA), ( 1));   
} // end cexpansion _0LKRJrD5wqK_5ZE495IAA7d - obdumpscanvalue   
// while _0SWi4IZCeP3_0VPExGvOasL comp#2:  
 /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi = //assign _5UiotUrFshh_9xWCmys30Pe   
/*objdictkeyafterpayl:*/ (value_tyBM) objdictkeyafterpayl_BM( ( /*odict:*/_.o_7n2SLLuWOjH_4ArhFUjmckz),
  stringcast_BM( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)) ;  
  
goto startblock__0SWi4IZCeP3_0VPExGvOasL; // repeatwhile  
endblock__0SWi4IZCeP3_0VPExGvOasL: /*endingwhile*/;  
} /*-endwhile _0SWi4IZCeP3_0VPExGvOasL */ 
 
 
 
/*return _8pmMgF3SSuE_2COzwjyI8lS:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*odict:*/_.o_7n2SLLuWOjH_4ArhFUjmckz; 
 goto epilog_22Zd68WPKUO_6AoIuBcbUb2; 
 
/* !endingblock _7csjYG7rNV4_68bJZT4W2BO */ 
goto endblock__7csjYG7rNV4_68bJZT4W2BO; 
endblock__7csjYG7rNV4_68bJZT4W2BO: ; 
} /*-block _7csjYG7rNV4_68bJZT4W2BO */

 epilog_22Zd68WPKUO_6AoIuBcbUb2: __attribute__ ((unused)); // routine _22Zd68WPKUO_6AoIuBcbUb2 epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _22Zd68WPKUO_6AoIuBcbUb2 routine#8 _22Zd68WPKUO_6AoIuBcbUb2




value_tyBM crout_2bZ4BfCci5V_3WTzG7V25y4_BM //#9
 (struct stackframe_stBM* stkf, //
//!put°dict_object minifunc
  // 3 arguments
  const value_tyBM arg0,  // odict
  const value_tyBM arg1,  // v_str
  const value_tyBM arg2,  // v_val
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _2bZ4BfCci5V_3WTzG7V25y4
  struct frame_2bZ4BfCci5V_3WTzG7V25y4_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 4 local values:
    value_tyBM v_167WczZjWtG_3FofhJxQWJi; // v_str
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    value_tyBM v_5jRQCD1qTko_61I0j04ugAA; // v_val
    objectval_tyBM* o_7n2SLLuWOjH_4ArhFUjmckz; // odict
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_2bZ4BfCci5V_3WTzG7V25y4_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 4;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[22] /*|_2bZ4BfCci5V_3WTzG7V25y4*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 3 arguments:
   _.o_7n2SLLuWOjH_4ArhFUjmckz = objectcast_BM (arg0); // odict
   _.v_167WczZjWtG_3FofhJxQWJi = arg1; // v_str
   _.v_5jRQCD1qTko_61I0j04ugAA = arg2; // v_val
   // fetched 3 arguments.
   // no closed values in _2bZ4BfCci5V_3WTzG7V25y4.
   // routine _2bZ4BfCci5V_3WTzG7V25y4 body:

startblock__0VJTIqFfNXf_5chzuIlqcJP: __attribute__((unused));
{ /* +block _0VJTIqFfNXf_5chzuIlqcJP */ 
if /*cond _838sw9thRfn_03qQ7lMn8Ij*/  
/*when _2aMZ0ZBgKj2_35QKBjbmq4w:*/ 
 (/*objhasdictpayl:*/ objhasdictpayl_BM(( /*odict:*/_.o_7n2SLLuWOjH_4ArhFUjmckz))) { //body when _2aMZ0ZBgKj2_35QKBjbmq4w  
if /*cond _58oNVcHAUe4_3Z3PsPWQQWC*/   
/*when _5Zj20zoTMgi_2wX9L155Qet:*/  
 (/*isstring:*/isstring_BM( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)) { //body when _5Zj20zoTMgi_2wX9L155Qet   
{ // start cexpansion _7T2FZv58UYu_1HHqslZTor2 - objdictputpayl    
/*objdictputpayl:*/ objdictputpayl_BM(( /*odict:*/_.o_7n2SLLuWOjH_4ArhFUjmckz), ( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi), ( /*v_val:*/_.v_5jRQCD1qTko_61I0j04ugAA));    
} // end cexpansion _7T2FZv58UYu_1HHqslZTor2 - objdictputpayl    
/*return _3Q8xwomyj4D_36oIs4VyEfB:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned   
 /*odict:*/_.o_7n2SLLuWOjH_4ArhFUjmckz;   
 goto epilog_2bZ4BfCci5V_3WTzG7V25y4;   
   
} //endwhen _5Zj20zoTMgi_2wX9L155Qet   
/*endcond _58oNVcHAUe4_3Z3PsPWQQWC*/  
  
} //endwhen _2aMZ0ZBgKj2_35QKBjbmq4w  
/*endcond _838sw9thRfn_03qQ7lMn8Ij*/ 
 
/* !endingblock _0VJTIqFfNXf_5chzuIlqcJP */ 
goto endblock__0VJTIqFfNXf_5chzuIlqcJP; 
endblock__0VJTIqFfNXf_5chzuIlqcJP: ; 
} /*-block _0VJTIqFfNXf_5chzuIlqcJP */

 epilog_2bZ4BfCci5V_3WTzG7V25y4: __attribute__ ((unused)); // routine _2bZ4BfCci5V_3WTzG7V25y4 epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _2bZ4BfCci5V_3WTzG7V25y4 routine#9 _2bZ4BfCci5V_3WTzG7V25y4




value_tyBM crout_2nl9zcaSUwe_8UBiMp1OuMk_BM //#10+
 (struct stackframe_stBM* stkf, // identity_minifunc
//!the identity minifunc, returning its first argument
  // 1 arguments
  const value_tyBM arg0,  // v_in
  const value_tyBM arg1_ __attribute__((unused)),
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of identity_minifunc
  struct frame_2nl9zcaSUwe_8UBiMp1OuMk_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 2 local values:
    value_tyBM v_16Y2isgiwOY_4kEIm87NkH2; // v_in
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_2nl9zcaSUwe_8UBiMp1OuMk_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 2;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[25] /*|identity_minifunc*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 1 arguments:
   _.v_16Y2isgiwOY_4kEIm87NkH2 = arg0; // v_in
   // fetched 1 arguments.
   // no closed values in identity_minifunc.
   // routine _2nl9zcaSUwe_8UBiMp1OuMk body:

startblock__3SCriDcyk4V_8JxBGUtl9lK: __attribute__((unused));
{ /* +block _3SCriDcyk4V_8JxBGUtl9lK */ 
/*return _7r8EbXcv6UI_01uYrCD2Myn:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*v_in:*/_.v_16Y2isgiwOY_4kEIm87NkH2; 
 goto epilog_2nl9zcaSUwe_8UBiMp1OuMk; 
 
/* !endingblock _3SCriDcyk4V_8JxBGUtl9lK */ 
goto endblock__3SCriDcyk4V_8JxBGUtl9lK; 
endblock__3SCriDcyk4V_8JxBGUtl9lK: ; 
} /*-block _3SCriDcyk4V_8JxBGUtl9lK */

 epilog_2nl9zcaSUwe_8UBiMp1OuMk: __attribute__ ((unused)); // routine _2nl9zcaSUwe_8UBiMp1OuMk epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _2nl9zcaSUwe_8UBiMp1OuMk routine#10 identity_minifunc




value_tyBM crout_3iiht57Wrs1_5NbiUi27oBn_BM //#11
 (struct stackframe_stBM* stkf, //
//!prepend°list_object minifunc
  // 2 arguments
  const value_tyBM arg0,  // o1
  const value_tyBM arg1,  // v2
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _3iiht57Wrs1_5NbiUi27oBn
  struct frame_3iiht57Wrs1_5NbiUi27oBn_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 3 local values:
    value_tyBM v_09RxU8xDco3_2Zxwfb13oDZ; // v2
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_97rnxb0KFqq_44veN75DG2E; // o1
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_3iiht57Wrs1_5NbiUi27oBn_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 3;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[32] /*|_3iiht57Wrs1_5NbiUi27oBn*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 2 arguments:
   _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0); // o1
   _.v_09RxU8xDco3_2Zxwfb13oDZ = arg1; // v2
   // fetched 2 arguments.
   // no closed values in _3iiht57Wrs1_5NbiUi27oBn.
   // routine _3iiht57Wrs1_5NbiUi27oBn body:

startblock__9BLJq5DadtZ_6I89t7ioVRS: __attribute__((unused));
{ /* +block _9BLJq5DadtZ_6I89t7ioVRS */ 
if /*cond _2cKxScfQVIk_8j9yMA8y0D2*/  
/*when _9Eu315oGSiW_2T0LUr58JnT:*/ 
 (/*objhaslistpayl:*/objhaslistpayl_BM(( /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E))) { //body when _9Eu315oGSiW_2T0LUr58JnT  
{ // start cexpansion _8K97qV68UiQ_0ssdaZQW9h5 - objlistprependpayl   
/*objlistprependpayl:*/objlistprependpayl_BM(( /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E),( /*v2:*/_.v_09RxU8xDco3_2Zxwfb13oDZ));   
} // end cexpansion _8K97qV68UiQ_0ssdaZQW9h5 - objlistprependpayl   
/*return _3Hj8WH5oi59_3L07vytBdDJ:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned  
 /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E;  
 goto epilog_3iiht57Wrs1_5NbiUi27oBn;  
  
} //endwhen _9Eu315oGSiW_2T0LUr58JnT  
/*endcond _2cKxScfQVIk_8j9yMA8y0D2*/ 
 
/* !endingblock _9BLJq5DadtZ_6I89t7ioVRS */ 
goto endblock__9BLJq5DadtZ_6I89t7ioVRS; 
endblock__9BLJq5DadtZ_6I89t7ioVRS: ; 
} /*-block _9BLJq5DadtZ_6I89t7ioVRS */

 epilog_3iiht57Wrs1_5NbiUi27oBn: __attribute__ ((unused)); // routine _3iiht57Wrs1_5NbiUi27oBn epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _3iiht57Wrs1_5NbiUi27oBn routine#11 _3iiht57Wrs1_5NbiUi27oBn




value_tyBM crout_3yQlckX4DRh_4b9l9FBSSSL_BM //#12+
 (struct stackframe_stBM* stkf, // same_as_closed_minifunc
//!return argument if it is the same as the closed value
  // 1 arguments
  const value_tyBM arg0,  // v_arg
  const value_tyBM arg1_ __attribute__((unused)),
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of same_as_closed_minifunc
  struct frame_3yQlckX4DRh_4b9l9FBSSSL_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 3 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    value_tyBM v_4Q4WBLjAPTV_5WVLmhAvCJY; // v_arg
    value_tyBM v_5EEITf6IFH7_4DbKG99zcPW; // v1
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_3yQlckX4DRh_4b9l9FBSSSL_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 3;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[33] /*|same_as_closed_minifunc*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 1 arguments:
   _.v_4Q4WBLjAPTV_5WVLmhAvCJY = arg0; // v_arg
   // fetched 1 arguments.
   { // fetch 1 closed values in same_as_closed_minifunc:
   const closure_tyBM* callclos_3yQlckX4DRh_4b9l9FBSSSL =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   unsigned nbclosed_3yQlckX4DRh_4b9l9FBSSSL = closurewidth_BM ((const value_tyBM) callclos_3yQlckX4DRh_4b9l9FBSSSL);
   if (nbclosed_3yQlckX4DRh_4b9l9FBSSSL > 0)
      _.v_5EEITf6IFH7_4DbKG99zcPW = callclos_3yQlckX4DRh_4b9l9FBSSSL->nodt_sons[0]; // v1
   } // fetched 1 closed values in _3yQlckX4DRh_4b9l9FBSSSL.
   // routine _3yQlckX4DRh_4b9l9FBSSSL body:

startblock__8seRhfNtGTR_4rOgARd0hVM: __attribute__((unused));
{ /* +block _8seRhfNtGTR_4rOgARd0hVM */ 
if /*cond _8aGb7reuzLX_3sgkigRSOpu*/  
/*when _5Ad0ZdurQuC_1A6Kn7qopbm:*/ 
 ((/*same_val:*/( /*v1:*/_.v_5EEITf6IFH7_4DbKG99zcPW) == ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY))) { //body when _5Ad0ZdurQuC_1A6Kn7qopbm  
/*return _1qFf9AUO2W9_8azcQljqB3I:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned  
 /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY;  
 goto epilog_3yQlckX4DRh_4b9l9FBSSSL;  
  
} //endwhen _5Ad0ZdurQuC_1A6Kn7qopbm  
/*endcond _8aGb7reuzLX_3sgkigRSOpu*/ 
 
/* !endingblock _8seRhfNtGTR_4rOgARd0hVM */ 
goto endblock__8seRhfNtGTR_4rOgARd0hVM; 
endblock__8seRhfNtGTR_4rOgARd0hVM: ; 
} /*-block _8seRhfNtGTR_4rOgARd0hVM */

 epilog_3yQlckX4DRh_4b9l9FBSSSL: __attribute__ ((unused)); // routine _3yQlckX4DRh_4b9l9FBSSSL epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _3yQlckX4DRh_4b9l9FBSSSL routine#12 same_as_closed_minifunc




value_tyBM crout_3HAeZZQ0q7b_7qyDsekaz7Y_BM //#13
 (struct stackframe_stBM* stkf, //
//!clear°list_object minifunc
  // 1 arguments
  const value_tyBM arg0,  // o1
  const value_tyBM arg1_ __attribute__((unused)),
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _3HAeZZQ0q7b_7qyDsekaz7Y
  struct frame_3HAeZZQ0q7b_7qyDsekaz7Y_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 2 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_97rnxb0KFqq_44veN75DG2E; // o1
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_3HAeZZQ0q7b_7qyDsekaz7Y_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 2;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[35] /*|_3HAeZZQ0q7b_7qyDsekaz7Y*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 1 arguments:
   _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0); // o1
   // fetched 1 arguments.
   // no closed values in _3HAeZZQ0q7b_7qyDsekaz7Y.
   // routine _3HAeZZQ0q7b_7qyDsekaz7Y body:

startblock__4wSCE1PqaMS_2XYzFgB0waZ: __attribute__((unused));
{ /* +block _4wSCE1PqaMS_2XYzFgB0waZ */ 
if /*cond _3eTPhEBroKh_3F8wQMduy1J*/  
/*when _0IRlnxNrCtM_6W21xnJjzmn:*/ 
 (/*objputlistpayl:*/objputlistpayl_BM( /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E)) { //body when _0IRlnxNrCtM_6W21xnJjzmn  
/*return _516tXf2eeNb_8VGPLYEode5:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned  
 /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E;  
 goto epilog_3HAeZZQ0q7b_7qyDsekaz7Y;  
  
} //endwhen _0IRlnxNrCtM_6W21xnJjzmn  
/*endcond _3eTPhEBroKh_3F8wQMduy1J*/ 
 
/* !endingblock _4wSCE1PqaMS_2XYzFgB0waZ */ 
goto endblock__4wSCE1PqaMS_2XYzFgB0waZ; 
endblock__4wSCE1PqaMS_2XYzFgB0waZ: ; 
} /*-block _4wSCE1PqaMS_2XYzFgB0waZ */

 epilog_3HAeZZQ0q7b_7qyDsekaz7Y: __attribute__ ((unused)); // routine _3HAeZZQ0q7b_7qyDsekaz7Y epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _3HAeZZQ0q7b_7qyDsekaz7Y routine#13 _3HAeZZQ0q7b_7qyDsekaz7Y




value_tyBM crout_4iEFTEcHxeb_6lH464uFkTC_BM //#14+
 (struct stackframe_stBM* stkf, // equal_to_closed_minifunc
//!return argument if it is the same as the closed value
  // 1 arguments
  const value_tyBM arg0,  // v_arg
  const value_tyBM arg1_ __attribute__((unused)),
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of equal_to_closed_minifunc
  struct frame_4iEFTEcHxeb_6lH464uFkTC_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 3 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    value_tyBM v_4Q4WBLjAPTV_5WVLmhAvCJY; // v_arg
    value_tyBM v_5EEITf6IFH7_4DbKG99zcPW; // v1
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_4iEFTEcHxeb_6lH464uFkTC_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 3;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[40] /*|equal_to_closed_minifunc*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 1 arguments:
   _.v_4Q4WBLjAPTV_5WVLmhAvCJY = arg0; // v_arg
   // fetched 1 arguments.
   { // fetch 1 closed values in equal_to_closed_minifunc:
   const closure_tyBM* callclos_4iEFTEcHxeb_6lH464uFkTC =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   unsigned nbclosed_4iEFTEcHxeb_6lH464uFkTC = closurewidth_BM ((const value_tyBM) callclos_4iEFTEcHxeb_6lH464uFkTC);
   if (nbclosed_4iEFTEcHxeb_6lH464uFkTC > 0)
      _.v_5EEITf6IFH7_4DbKG99zcPW = callclos_4iEFTEcHxeb_6lH464uFkTC->nodt_sons[0]; // v1
   } // fetched 1 closed values in _4iEFTEcHxeb_6lH464uFkTC.
   // routine _4iEFTEcHxeb_6lH464uFkTC body:

startblock__60FKeHfNUo3_9OSN4Cqm8zI: __attribute__((unused));
{ /* +block _60FKeHfNUo3_9OSN4Cqm8zI */ 
if /*cond _7wPbopKi9ZB_1ifk5LEKSqu*/  
/*when _8hUpJbSLQUS_88aqogJAi2Q:*/ 
 ((/*equal_val:*/valequal_BM(( /*v1:*/_.v_5EEITf6IFH7_4DbKG99zcPW),( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY)))) { //body when _8hUpJbSLQUS_88aqogJAi2Q  
/*return _3dJ2b1hmBuw_7Pu5iDjauLr:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned  
 /*v1:*/_.v_5EEITf6IFH7_4DbKG99zcPW;  
 goto epilog_4iEFTEcHxeb_6lH464uFkTC;  
  
} //endwhen _8hUpJbSLQUS_88aqogJAi2Q  
/*endcond _7wPbopKi9ZB_1ifk5LEKSqu*/ 
 
/* !endingblock _60FKeHfNUo3_9OSN4Cqm8zI */ 
goto endblock__60FKeHfNUo3_9OSN4Cqm8zI; 
endblock__60FKeHfNUo3_9OSN4Cqm8zI: ; 
} /*-block _60FKeHfNUo3_9OSN4Cqm8zI */

 epilog_4iEFTEcHxeb_6lH464uFkTC: __attribute__ ((unused)); // routine _4iEFTEcHxeb_6lH464uFkTC epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _4iEFTEcHxeb_6lH464uFkTC routine#14 equal_to_closed_minifunc




value_tyBM crout_4qlegfkPzrC_17skUfJP7v8_BM //#15
 (struct stackframe_stBM* stkf, //
//!dump_data°dict_object minifun
  // 3 arguments
  const value_tyBM arg0,  // odict
  const value_tyBM arg1,  // odumper
  const value_tyBM arg2,  // osbuf
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _4qlegfkPzrC_17skUfJP7v8
  struct frame_4qlegfkPzrC_17skUfJP7v8_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 6 local values:
    value_tyBM v_167WczZjWtG_3FofhJxQWJi; // v_str
    objectval_tyBM* o_3cTC8W7d75H_1vteOyEoAao; // odumper
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    value_tyBM v_5jRQCD1qTko_61I0j04ugAA; // v_val
    objectval_tyBM* o_6opEz55NyNu_3JKpBgxLijw; // osbuf
    objectval_tyBM* o_7n2SLLuWOjH_4ArhFUjmckz; // odict
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_4qlegfkPzrC_17skUfJP7v8_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 6;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[42] /*|_4qlegfkPzrC_17skUfJP7v8*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 3 arguments:
   _.o_7n2SLLuWOjH_4ArhFUjmckz = objectcast_BM (arg0); // odict
   _.o_3cTC8W7d75H_1vteOyEoAao = objectcast_BM (arg1); // odumper
   _.o_6opEz55NyNu_3JKpBgxLijw = objectcast_BM (arg2); // osbuf
   // fetched 3 arguments.
   // no closed values in _4qlegfkPzrC_17skUfJP7v8.
   // routine _4qlegfkPzrC_17skUfJP7v8 body:

startblock__3oMW0T4HlXx_8r7NLpyK1J8: __attribute__((unused));
{ /* +block _3oMW0T4HlXx_8r7NLpyK1J8 */ 
{ // start cexpansion _4QfB21rab5P_26PMGm9N4Dl - objstrbufferclearindentpayl  
/*objstrbufferclearindentpayl:*/objstrbufferclearindentpayl_BM(( /*osbuf:*/_.o_6opEz55NyNu_3JKpBgxLijw));  
} // end cexpansion _4QfB21rab5P_26PMGm9N4Dl - objstrbufferclearindentpayl  
  
 
{ // start cexpansion _15WmvoAu2Kx_9K4XFDxMyU4 - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*osbuf:*/_.o_6opEz55NyNu_3JKpBgxLijw), ( "!~ todo (~\n"));  
} // end cexpansion _15WmvoAu2Kx_9K4XFDxMyU4 - objstrbufferappendcstrpayl  
  
//+ #2/9 of block _3oMW0T4HlXx_8r7NLpyK1J8 ::  
 
 /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi = //assign _5mCmWSYOW7T_4G9YRC6tvRf  
/*objdictfirstkeypayl:*/ (value_tyBM) objdictfirstkeypayl_BM(( /*odict:*/_.o_7n2SLLuWOjH_4ArhFUjmckz)); 
 
 
{ // start cexpansion _3pnZ6MbNCtX_2IZKwMgn9y1 - objstrbuffersetindentpayl  
/*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*osbuf:*/_.o_6opEz55NyNu_3JKpBgxLijw), ( 1));  
} // end cexpansion _3pnZ6MbNCtX_2IZKwMgn9y1 - objstrbuffersetindentpayl  
  
//+ #4/9 of block _3oMW0T4HlXx_8r7NLpyK1J8 ::  
 
 
{ // run _40XgQGIUZQY_246JbHmppCN 
(send3_BM (( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[79] /*|clear*/)), /*sel:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[18] /*|dump_value*/)), ((struct stackframe_stBM*)&_),   
 ( /*osbuf:*/_.o_6opEz55NyNu_3JKpBgxLijw),  ( /*odumper:*/_.o_3cTC8W7d75H_1vteOyEoAao),   
 ( ((value_tyBM)0x3 /*!1*/)))); 
} // end run _40XgQGIUZQY_246JbHmppCN 
 
 
 
//// +while _9gJT0jotyox_8JQNlJn3qh6 
startblock__9gJT0jotyox_8JQNlJn3qh6:  /*+!while*/; 
{ /* +while _9gJT0jotyox_8JQNlJn3qh6 */  
if (!(/*while _9gJT0jotyox_8JQNlJn3qh6 cond:*/ /*isstring:*/isstring_BM( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi))) //: testwhile _9gJT0jotyox_8JQNlJn3qh6 failing   
  goto endblock__9gJT0jotyox_8JQNlJn3qh6; //failwhile   
// while _9gJT0jotyox_8JQNlJn3qh6 body:   
// while _9gJT0jotyox_8JQNlJn3qh6 comp#0:  
 /*v_val:*/_.v_5jRQCD1qTko_61I0j04ugAA = //assign _6mzawBHvh0i_13Wpf0Lmgig   
/*objdictgetpayl:*/ objdictgetpayl_BM(( /*odict:*/_.o_7n2SLLuWOjH_4ArhFUjmckz), stringcast_BM( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi));  
// while _9gJT0jotyox_8JQNlJn3qh6 comp#1:  
{ // start cexpansion _8QIiIH1xKGD_0ByaWRWwCAO - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*osbuf:*/_.o_6opEz55NyNu_3JKpBgxLijw), ( " !&\n"));   
} // end cexpansion _8QIiIH1xKGD_0ByaWRWwCAO - objstrbufferappendcstrpayl   
// while _9gJT0jotyox_8JQNlJn3qh6 comp#2:  
  
{ // run _4BOu5jhqyAD_3HGfVAY5hFx  
(send3_BM (( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[83] /*|put*/)), /*sel:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[18] /*|dump_value*/)), ((struct stackframe_stBM*)&_),    
 ( /*osbuf:*/_.o_6opEz55NyNu_3JKpBgxLijw),  ( /*odumper:*/_.o_3cTC8W7d75H_1vteOyEoAao),    
 ( ((value_tyBM)0x3 /*!1*/))));  
} // end run _4BOu5jhqyAD_3HGfVAY5hFx  
// while _9gJT0jotyox_8JQNlJn3qh6 comp#3:  
{ // start cexpansion _8TB4Kpuoc3f_0Dhb8Tm0xrJ - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*osbuf:*/_.o_6opEz55NyNu_3JKpBgxLijw), ( "\t"));   
} // end cexpansion _8TB4Kpuoc3f_0Dhb8Tm0xrJ - objstrbufferappendcstrpayl   
// while _9gJT0jotyox_8JQNlJn3qh6 comp#4:  
  
{ // run _634ecJogXve_7sycLMYAfdT  
(send3_BM (( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi), /*sel:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[18] /*|dump_value*/)), ((struct stackframe_stBM*)&_),    
 ( /*osbuf:*/_.o_6opEz55NyNu_3JKpBgxLijw),  ( /*odumper:*/_.o_3cTC8W7d75H_1vteOyEoAao),    
 ( ((value_tyBM)0x3 /*!1*/))));  
} // end run _634ecJogXve_7sycLMYAfdT  
// while _9gJT0jotyox_8JQNlJn3qh6 comp#5:  
{ // start cexpansion _3fFn9uY0hNS_2YU6fn9QOSh - objstrbuffernewlinepayl   
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*osbuf:*/_.o_6opEz55NyNu_3JKpBgxLijw);   
} // end cexpansion _3fFn9uY0hNS_2YU6fn9QOSh - objstrbuffernewlinepayl   
// while _9gJT0jotyox_8JQNlJn3qh6 comp#6:  
  
{ // run _1aLOinNfz2n_0WpWbC84CAL  
(send3_BM (( /*v_val:*/_.v_5jRQCD1qTko_61I0j04ugAA), /*sel:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[18] /*|dump_value*/)), ((struct stackframe_stBM*)&_),    
 ( /*osbuf:*/_.o_6opEz55NyNu_3JKpBgxLijw),  ( /*odumper:*/_.o_3cTC8W7d75H_1vteOyEoAao),    
 ( ((value_tyBM)0x3 /*!1*/))));  
} // end run _1aLOinNfz2n_0WpWbC84CAL  
// while _9gJT0jotyox_8JQNlJn3qh6 comp#7:  
 /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi = //assign _5VEaDZcNd5x_9CGhCudUvGs   
/*objdictkeyafterpayl:*/ (value_tyBM) objdictkeyafterpayl_BM( ( /*odict:*/_.o_7n2SLLuWOjH_4ArhFUjmckz),
  stringcast_BM( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)) ;  
  
goto startblock__9gJT0jotyox_8JQNlJn3qh6; // repeatwhile  
endblock__9gJT0jotyox_8JQNlJn3qh6: /*endingwhile*/;  
} /*-endwhile _9gJT0jotyox_8JQNlJn3qh6 */ 
 
 
//+ #6/9 of block _3oMW0T4HlXx_8r7NLpyK1J8 :: 
 
{ // start cexpansion _1UfGW420Q3X_3osvimj3Myj - objstrbufferclearindentpayl  
/*objstrbufferclearindentpayl:*/objstrbufferclearindentpayl_BM(( /*osbuf:*/_.o_6opEz55NyNu_3JKpBgxLijw));  
} // end cexpansion _1UfGW420Q3X_3osvimj3Myj - objstrbufferclearindentpayl  
  
 
{ // start cexpansion _3urNBgu4IsT_4oyZ9YgJmbx - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*osbuf:*/_.o_6opEz55NyNu_3JKpBgxLijw), ( "\n~)\n"));  
} // end cexpansion _3urNBgu4IsT_4oyZ9YgJmbx - objstrbufferappendcstrpayl  
  
 
/*return _9IH3fglmCon_9bHWhFstP4K:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*odict:*/_.o_7n2SLLuWOjH_4ArhFUjmckz; 
 goto epilog_4qlegfkPzrC_17skUfJP7v8; 
 
/* !endingblock _3oMW0T4HlXx_8r7NLpyK1J8 */ 
goto endblock__3oMW0T4HlXx_8r7NLpyK1J8; 
endblock__3oMW0T4HlXx_8r7NLpyK1J8: ; 
} /*-block _3oMW0T4HlXx_8r7NLpyK1J8 */

 epilog_4qlegfkPzrC_17skUfJP7v8: __attribute__ ((unused)); // routine _4qlegfkPzrC_17skUfJP7v8 epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _4qlegfkPzrC_17skUfJP7v8 routine#15 _4qlegfkPzrC_17skUfJP7v8




value_tyBM crout_4M7lr5cU6VD_5hxmeH3baBf_BM //#16
 (struct stackframe_stBM* stkf, //
//!append°list_object minifunction
  // 2 arguments
  const value_tyBM arg0,  // o1
  const value_tyBM arg1,  // v2
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _4M7lr5cU6VD_5hxmeH3baBf
  struct frame_4M7lr5cU6VD_5hxmeH3baBf_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 3 local values:
    value_tyBM v_09RxU8xDco3_2Zxwfb13oDZ; // v2
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_97rnxb0KFqq_44veN75DG2E; // o1
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_4M7lr5cU6VD_5hxmeH3baBf_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 3;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[46] /*|_4M7lr5cU6VD_5hxmeH3baBf*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 2 arguments:
   _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0); // o1
   _.v_09RxU8xDco3_2Zxwfb13oDZ = arg1; // v2
   // fetched 2 arguments.
   // no closed values in _4M7lr5cU6VD_5hxmeH3baBf.
   // routine _4M7lr5cU6VD_5hxmeH3baBf body:

startblock__883QaWUOedh_9zmHk2A3RPm: __attribute__((unused));
{ /* +block _883QaWUOedh_9zmHk2A3RPm */ 
if /*cond _9l1kqklfeho_8gvTSpVHJs0*/  
/*when _4bt3mp8e1a2_7XsOs7auvrU:*/ 
 (/*objhaslistpayl:*/objhaslistpayl_BM(( /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E))) { //body when _4bt3mp8e1a2_7XsOs7auvrU  
{ // start cexpansion _8WKnIBYQNvy_0t8M4F48joR - objlistappendpayl   
/*objlistappendpayl:*/objlistappendpayl_BM(( /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E),( /*v2:*/_.v_09RxU8xDco3_2Zxwfb13oDZ));   
} // end cexpansion _8WKnIBYQNvy_0t8M4F48joR - objlistappendpayl   
/*return _86rGd2LLytX_4xsXHoCmw1Y:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned  
 /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E;  
 goto epilog_4M7lr5cU6VD_5hxmeH3baBf;  
  
} //endwhen _4bt3mp8e1a2_7XsOs7auvrU  
/*endcond _9l1kqklfeho_8gvTSpVHJs0*/ 
 
/* !endingblock _883QaWUOedh_9zmHk2A3RPm */ 
goto endblock__883QaWUOedh_9zmHk2A3RPm; 
endblock__883QaWUOedh_9zmHk2A3RPm: ; 
} /*-block _883QaWUOedh_9zmHk2A3RPm */

 epilog_4M7lr5cU6VD_5hxmeH3baBf: __attribute__ ((unused)); // routine _4M7lr5cU6VD_5hxmeH3baBf epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _4M7lr5cU6VD_5hxmeH3baBf routine#16 _4M7lr5cU6VD_5hxmeH3baBf




value_tyBM crout_5j8LpQULt1p_9oeOaqmfYYr_BM //#17
 (struct stackframe_stBM* stkf, //
//!dump_data°list_object minifunc
  // 3 arguments
  const value_tyBM arg0,  // o1
  const value_tyBM arg1,  // o2
  const value_tyBM arg2,  // o3
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _5j8LpQULt1p_9oeOaqmfYYr
  struct frame_5j8LpQULt1p_9oeOaqmfYYr_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 5 local values:
    objectval_tyBM* o_1Bl1iFQ8boR_1xM6MOfHV1N; // o3
    value_tyBM v_2BkOxf2KbS8_3bswrKbmgjy; // v_node
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_93FBSk1ML0f_2WjSuKa9TNU; // o2
    objectval_tyBM* o_97rnxb0KFqq_44veN75DG2E; // o1
    /// 2 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
   } _;
   memset (&_, 0, sizeof(struct frame_5j8LpQULt1p_9oeOaqmfYYr_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 5;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[49] /*|_5j8LpQULt1p_9oeOaqmfYYr*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 3 arguments:
   _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0); // o1
   _.o_93FBSk1ML0f_2WjSuKa9TNU = objectcast_BM (arg1); // o2
   _.o_1Bl1iFQ8boR_1xM6MOfHV1N = objectcast_BM (arg2); // o3
   // fetched 3 arguments.
   // no closed values in _5j8LpQULt1p_9oeOaqmfYYr.
   // routine _5j8LpQULt1p_9oeOaqmfYYr body:

startblock__9Hf4n8AnqR7_7ve3Bi3kWMV: __attribute__((unused));
{ /* +block _9Hf4n8AnqR7_7ve3Bi3kWMV */ 
 /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy = //assign _8ggHPTQI1iG_02hVE5KybEL  
/*objlisttonodepayl:*/ (value_tyBM) objlisttonodepayl_BM(( /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[70] /*|node*/))); 
 
 
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _0zhpGzEVWGP_7WoL4LJocuS  
/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy); 
 
//+ #2/8 of block _9Hf4n8AnqR7_7ve3Bi3kWMV :: 
 
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _0fygl91r6x5_8b3aCDptjAi  
 0; 
 
 
{ // start cexpansion _6yLpzYpq8F0_4ogwWJhDGnH - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o3:*/_.o_1Bl1iFQ8boR_1xM6MOfHV1N), ( "!~ todo (~"));  
} // end cexpansion _6yLpzYpq8F0_4ogwWJhDGnH - objstrbufferappendcstrpayl  
  
//+ #4/8 of block _9Hf4n8AnqR7_7ve3Bi3kWMV ::  
 
 
//// +while _9xjh4MB97y4_2d8ffcaNFYt 
startblock__9xjh4MB97y4_2d8ffcaNFYt:  /*+!while*/; 
{ /* +while _9xjh4MB97y4_2d8ffcaNFYt */  
if (!(/*while _9xjh4MB97y4_2d8ffcaNFYt cond:*/ (/*less_int:*/( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) < ( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k)))) //: testwhile _9xjh4MB97y4_2d8ffcaNFYt failing   
  goto endblock__9xjh4MB97y4_2d8ffcaNFYt; //failwhile   
// while _9xjh4MB97y4_2d8ffcaNFYt body:   
// while _9xjh4MB97y4_2d8ffcaNFYt comp#0:  
{ // start cexpansion _63n9WJxlgsW_7aRQkxcfyFp - objstrbuffersetindentpayl   
/*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o3:*/_.o_1Bl1iFQ8boR_1xM6MOfHV1N), ( 1));   
} // end cexpansion _63n9WJxlgsW_7aRQkxcfyFp - objstrbuffersetindentpayl   
// while _9xjh4MB97y4_2d8ffcaNFYt comp#1:  
{ // start cexpansion _4L5hoWsh9Dl_112aUlLRWBa - objstrbuffernewlinepayl   
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o3:*/_.o_1Bl1iFQ8boR_1xM6MOfHV1N);   
} // end cexpansion _4L5hoWsh9Dl_112aUlLRWBa - objstrbuffernewlinepayl   
// while _9xjh4MB97y4_2d8ffcaNFYt comp#2:  
{ // start cexpansion _4ExmfQs4chn_6b5RsLwzSmp - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o3:*/_.o_1Bl1iFQ8boR_1xM6MOfHV1N), ( " &!"));   
} // end cexpansion _4ExmfQs4chn_6b5RsLwzSmp - objstrbufferappendcstrpayl   
// while _9xjh4MB97y4_2d8ffcaNFYt comp#3:  
  
{ // run _6HYDs1Zywvs_1w8OTn5XOZY  
(send3_BM ((/*nodenthson:*/nodenthson_BM(( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B))), /*sel:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[18] /*|dump_value*/)), ((struct stackframe_stBM*)&_),    
 ( /*o3:*/_.o_1Bl1iFQ8boR_1xM6MOfHV1N),  ( /*o2:*/_.o_93FBSk1ML0f_2WjSuKa9TNU),    
 ( ((value_tyBM)0x3 /*!1*/))));  
} // end run _6HYDs1Zywvs_1w8OTn5XOZY  
// while _9xjh4MB97y4_2d8ffcaNFYt comp#4:  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _4nPRrjCznxv_354tRTC5amu   
/*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1));  
  
goto startblock__9xjh4MB97y4_2d8ffcaNFYt; // repeatwhile  
endblock__9xjh4MB97y4_2d8ffcaNFYt: /*endingwhile*/;  
} /*-endwhile _9xjh4MB97y4_2d8ffcaNFYt */ 
 
 
 
{ // start cexpansion _39EI0paA4hR_8y7JANajq5t - objstrbuffernewlinepayl  
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o3:*/_.o_1Bl1iFQ8boR_1xM6MOfHV1N);  
} // end cexpansion _39EI0paA4hR_8y7JANajq5t - objstrbuffernewlinepayl  
  
//+ #6/8 of block _9Hf4n8AnqR7_7ve3Bi3kWMV ::  
 
{ // start cexpansion _5flu8xdOTMC_79tshj3uSa4 - objstrbuffersetindentpayl  
/*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o3:*/_.o_1Bl1iFQ8boR_1xM6MOfHV1N), ( 0));  
} // end cexpansion _5flu8xdOTMC_79tshj3uSa4 - objstrbuffersetindentpayl  
  
 
{ // start cexpansion _5YxDaNaTjQ7_0v9tZ2seGmF - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o3:*/_.o_1Bl1iFQ8boR_1xM6MOfHV1N), ( "~)"));  
} // end cexpansion _5YxDaNaTjQ7_0v9tZ2seGmF - objstrbufferappendcstrpayl  
  
/* !endingblock _9Hf4n8AnqR7_7ve3Bi3kWMV */ 
goto endblock__9Hf4n8AnqR7_7ve3Bi3kWMV; 
endblock__9Hf4n8AnqR7_7ve3Bi3kWMV: ; 
} /*-block _9Hf4n8AnqR7_7ve3Bi3kWMV */

 epilog_5j8LpQULt1p_9oeOaqmfYYr: __attribute__ ((unused)); // routine _5j8LpQULt1p_9oeOaqmfYYr epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _5j8LpQULt1p_9oeOaqmfYYr routine#17 _5j8LpQULt1p_9oeOaqmfYYr




value_tyBM crout_7MtjMTkmErH_2zSJ1YDKHVi_BM //#18
 (struct stackframe_stBM* stkf, //
//!dump_value°double_float < v_dbl (o_strbuf o_dump v_depth)
  // 4 arguments
  const value_tyBM arg0,  // v_dbl
  const value_tyBM arg1,  // o_strbuf
  const value_tyBM arg2,  // o_dump
  const value_tyBM arg3,  // v_depth
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _7MtjMTkmErH_2zSJ1YDKHVi
  struct frame_7MtjMTkmErH_2zSJ1YDKHVi_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 5 local values:
    objectval_tyBM* o_0iwWM98KNVX_0tO8Cz41val; // o_dump
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
    value_tyBM v_7m9aaeG1xHx_6pPkRL8xYYT; // v_dbl
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_7MtjMTkmErH_2zSJ1YDKHVi_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 5;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[71] /*|_7MtjMTkmErH_2zSJ1YDKHVi*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 4 arguments:
   _.v_7m9aaeG1xHx_6pPkRL8xYYT = arg0; // v_dbl
   _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg1); // o_strbuf
   _.o_0iwWM98KNVX_0tO8Cz41val = objectcast_BM (arg2); // o_dump
   _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
   // fetched 4 arguments.
   // no closed values in _7MtjMTkmErH_2zSJ1YDKHVi.
   // routine _7MtjMTkmErH_2zSJ1YDKHVi body:

startblock__2CQSAWSZYj5_98YYbJMAfN2: __attribute__((unused));
{ /* +block _2CQSAWSZYj5_98YYbJMAfN2 */ 
 
{ // run _61LFWdfV7PM_5veZwiRLC2y 

double d__61LFWdfV7PM_5veZwiRLC2y = getdouble_BM( /*v_dbl:*/_.v_7m9aaeG1xHx_6pPkRL8xYYT);
if (objstrbufferoutdoublepayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, d__61LFWdfV7PM_5veZwiRLC2y))
 objstrbufferprintfpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "|==%g| ", d__61LFWdfV7PM_5veZwiRLC2y);
else objstrbufferappendcstrpayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, " ");
; 
} // end run _61LFWdfV7PM_5veZwiRLC2y 
 
 
/*return _8SBPWoQTYFm_5EoKbU71sQi:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*v_dbl:*/_.v_7m9aaeG1xHx_6pPkRL8xYYT; 
 goto epilog_7MtjMTkmErH_2zSJ1YDKHVi; 
 
/* !endingblock _2CQSAWSZYj5_98YYbJMAfN2 */ 
goto endblock__2CQSAWSZYj5_98YYbJMAfN2; 
endblock__2CQSAWSZYj5_98YYbJMAfN2: ; 
} /*-block _2CQSAWSZYj5_98YYbJMAfN2 */

 epilog_7MtjMTkmErH_2zSJ1YDKHVi: __attribute__ ((unused)); // routine _7MtjMTkmErH_2zSJ1YDKHVi epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _7MtjMTkmErH_2zSJ1YDKHVi routine#18 _7MtjMTkmErH_2zSJ1YDKHVi




value_tyBM crout_82ho9wUUDji_4peMLha4PXl_BM //#19+
 (struct stackframe_stBM* stkf, // findobj_scan_minifunc
//!findobj_scan_minifunc scans, with the closed and locked o_findobj, the argument object o_scan; give NULL if o_scan was already scanned
  // 1 arguments
  const value_tyBM arg0,  // o_scan
  const value_tyBM arg1_ __attribute__((unused)),
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of findobj_scan_minifunc
  struct frame_82ho9wUUDji_4peMLha4PXl_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 4 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_4gykCX1QdLb_9Aooqa2FWTq; // o_scan
    objectval_tyBM* o_4ITcQtvlMmO_30Pss9oAVDB; // o_findobj
    objectval_tyBM* o_6Jkz6rphVkn_1KZto79j46r; // o_vihset
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_82ho9wUUDji_4peMLha4PXl_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 4;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[75] /*|findobj_scan_minifunc*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 1 arguments:
   _.o_4gykCX1QdLb_9Aooqa2FWTq = objectcast_BM (arg0); // o_scan
   // fetched 1 arguments.
   { // fetch 1 closed values in findobj_scan_minifunc:
   const closure_tyBM* callclos_82ho9wUUDji_4peMLha4PXl =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   unsigned nbclosed_82ho9wUUDji_4peMLha4PXl = closurewidth_BM ((const value_tyBM) callclos_82ho9wUUDji_4peMLha4PXl);
   if (nbclosed_82ho9wUUDji_4peMLha4PXl > 0)
      _.o_4ITcQtvlMmO_30Pss9oAVDB = objectcast_BM (callclos_82ho9wUUDji_4peMLha4PXl->nodt_sons[0]); // o_findobj
   } // fetched 1 closed values in _82ho9wUUDji_4peMLha4PXl.
   // routine _82ho9wUUDji_4peMLha4PXl body:

startblock__6YnYKKsHo3f_9nIEOZMp744: __attribute__((unused));
{ /* +block _6YnYKKsHo3f_9nIEOZMp744 */ 
 
{ // run _7m9brpKxZkY_3BEI7YANJuJ 
/*begin findobj_scan_minifunc*/ WEAKASSERT_BM(objectisinstance_BM ( /*o_findobj:*/_.o_4ITcQtvlMmO_30Pss9oAVDB,  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[58] /*|findrun_object*/))); ; 
} // end run _7m9brpKxZkY_3BEI7YANJuJ 
 
/* !endingblock _6YnYKKsHo3f_9nIEOZMp744 */ 
goto endblock__6YnYKKsHo3f_9nIEOZMp744; 
endblock__6YnYKKsHo3f_9nIEOZMp744: ; 
} /*-block _6YnYKKsHo3f_9nIEOZMp744 */

 epilog_82ho9wUUDji_4peMLha4PXl: __attribute__ ((unused)); // routine _82ho9wUUDji_4peMLha4PXl epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _82ho9wUUDji_4peMLha4PXl routine#19 findobj_scan_minifunc




value_tyBM crout_85xjvzYjcd6_9mNZNPF6i2J_BM //#20
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[76] /*|_85xjvzYjcd6_9mNZNPF6i2J*/;
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
   // routine _85xjvzYjcd6_9mNZNPF6i2J body:

startblock__0knuZ8Npcw8_6Jj2YIvenZB: __attribute__((unused));
{ /* +block _0knuZ8Npcw8_6Jj2YIvenZB */ 
 /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _74XT4f1vWl9_7pfkRaZCCjn  
 /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ; 
 
 
 /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4 = //assign _9pqI2UGxUWS_2CBJ8rAZ82i  
/*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[65] /*!index*/)))); 
 
//+ #2/15 of block _0knuZ8Npcw8_6Jj2YIvenZB :: 
 
 /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU = //assign _3432lagVKwU_591r9WA1UM7  
/*objgetattr:*/objgetattr_BM(( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[56] /*!count*/))); 
 
 
 
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
 (/*unequal_object:*/(( /*o_typcount:*/_.o_48tt3ewgFzG_8U9hwUq2GY6) != ( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[5] /*!int*/)))) { //body when _8Qv6mNnpd1C_5xmOXXiwNGC  
//failure _6Rc660mzjXf_6rWF1nupKVt   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[82] /*!failure_type_error*/)), 
 /*make_node 7 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[56] /*!count*/)), 
 
( /*o_typcount:*/_.o_48tt3ewgFzG_8U9hwUq2GY6), 
 
( /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[67] /*|_6Rc660mzjXf_6rWF1nupKVt*/)),
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
 (/*unequal_object:*/(( /*o_typindex:*/_.o_2nKz6bXzYe0_5F1HxV9bQRu) != ( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[5] /*!int*/)))) { //body when _25gAJE4HRuv_89hQbm1jNh8  
//failure _5zaZ8sDu1TQ_49hqJMJDKIq   
PLACEDFAILURE_BM(__LINE__,   
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[82] /*!failure_type_error*/)), 
 /*make_node 7 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[65] /*!index*/)), 
 
( /*o_typindex:*/_.o_2nKz6bXzYe0_5F1HxV9bQRu), 
 
( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)), 
 
( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[53] /*|_5zaZ8sDu1TQ_49hqJMJDKIq*/)),
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
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[41] /*!basiclo_statement*/)))) { //body when _2Hvz5h8r9Av_3Yv9HV7md5M    
 /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY = //assign _8sgR7i31pzL_42EKpWujqoM     
(send3_BM (( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2), /*sel:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[64] /*!miniscan_stmt*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1)))), 
 ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl)));    
if /*cond _4vZIvqj37yD_8V1cygCMbVf*/     
/*when _65JCkS6AuG7_6tVxePro2Ph:*/    
 (/*is_null:*/(( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY)==NULL)) { //body when _65JCkS6AuG7_6tVxePro2Ph     
//failure _227kofebdwq_9fj8R3qXt7B      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[48] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[76] /*!_85xjvzYjcd6_9mNZNPF6i2J*/)), 
 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[64] /*!miniscan_stmt*/)), 
 
( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[19] /*|_227kofebdwq_9fj8R3qXt7B*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _65JCkS6AuG7_6tVxePro2Ph     
/*endcond _4vZIvqj37yD_8V1cygCMbVf*/    
    
} //endwhen _2Hvz5h8r9Av_3Yv9HV7md5M    
else if    
/*when _8UhAB14P5OV_4SzOu2Seitj:*/   
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[39] /*!basiclo_block*/)))) { //body when _8UhAB14P5OV_4SzOu2Seitj    
 /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY = //assign _86xNO9NKgrq_1i3ph3xKuZk     
(send3_BM (( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2), /*sel:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[24] /*!miniscan_block*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1)))), 
 ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl)));    
if /*cond _7vA3sGtaCEa_4clk6xjbqLS*/     
/*when _2WH4J5GZlQ7_3gpZRxe8LNm:*/    
 (/*is_null:*/(( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY)==NULL)) { //body when _2WH4J5GZlQ7_3gpZRxe8LNm     
//failure _5oVb4fNe3eO_4GyCgc0vkQp      
PLACEDFAILURE_BM(__LINE__,      
          /*failreason:*/ (((value_tyBM) makesizednode_BM
 (7U,/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[48] /*!failure_miss*/)), 
 /*make_node 7 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[76] /*!_85xjvzYjcd6_9mNZNPF6i2J*/)), 
 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[24] /*!miniscan_block*/)), 
 
( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2), 
 
// make_node arg #4 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[50] /*|_5oVb4fNe3eO_4GyCgc0vkQp*/)),
                ((struct stackframe_stBM *) &_));
     
} //endwhen _2WH4J5GZlQ7_3gpZRxe8LNm     
/*endcond _7vA3sGtaCEa_4clk6xjbqLS*/    
    
} //endwhen _8UhAB14P5OV_4SzOu2Seitj    
else { /*cond else _8GpBvvm7FCj_8MezDXgKCOe*/    
//failure _0HZ6LhCuD3B_3wOqehpkD81    
PLACEDFAILURE_BM(__LINE__,    
          /*failreason:*/ (((value_tyBM) makenode6_BM
 (/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[44] /*!failure_bad_class*/)), 
 /*make_node 6 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[76] /*!_85xjvzYjcd6_9mNZNPF6i2J*/)), 
 
( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), 
 
( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 
(/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[8] /*|_0HZ6LhCuD3B_3wOqehpkD81*/)),
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
} // end _85xjvzYjcd6_9mNZNPF6i2J routine#20 _85xjvzYjcd6_9mNZNPF6i2J




value_tyBM crout_8dG7KZHgf3t_4ia32mWZqVQ_BM //#21
 (struct stackframe_stBM* stkf, //
//!for_loop#readmacro (v_node v_lineno v_colpos o_parser)
  // 4 arguments
  const value_tyBM arg0,  // v_node
  const value_tyBM arg1,  // v_lineno
  const value_tyBM arg2,  // v_colpos
  const value_tyBM arg3,  // o_parser
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _8dG7KZHgf3t_4ia32mWZqVQ
  struct frame_8dG7KZHgf3t_4ia32mWZqVQ_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 14 local values:
    objectval_tyBM* o_0yYNVlhznPw_115q5g6EYO0; // o_class
    value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
    objectval_tyBM* o_13K9OfeXRZR_84nyRTtoj81; // o_conn
    value_tyBM v_16Y2isgiwOY_4kEIm87NkH2; // v_in
    value_tyBM v_20uyDk84Vub_7xsAwkSm7lL; // v_lineno
    value_tyBM v_2BkOxf2KbS8_3bswrKbmgjy; // v_node
    objectval_tyBM* o_3aIzfMKBbIH_2z7FHf3JclZ; // o_verb
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_4jyHvEiEzZ1_9ck99ShNTHx; // o_resobj
    value_tyBM v_4leeeoANgjm_31PbCGhynlU; // v_countexp
    objectval_tyBM* o_4QkDiZYXmJR_8VofvgKqcu4; // o_varindex
    objectval_tyBM* o_5fGGXIme43z_0mc4HIwzzMj; // o_parser
    objectval_tyBM* o_79dADic8Iro_3skCK4hK3iW; // o_curlab
    value_tyBM v_7llbD3YIz2G_3vDyN1QuPCy; // v_colpos
    /// 5 local numbers:
    intptr_t n_2sygPI8PHgL_4RgFW0PkZbd; // i_colpos
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_4Dke6KoVx5r_1CoVhK8mVmc; // i_start
    intptr_t n_6x2LYnlYgQG_6FXtmtwODgo; // i_lineno
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
   } _;
   memset (&_, 0, sizeof(struct frame_8dG7KZHgf3t_4ia32mWZqVQ_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 14;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[77] /*|_8dG7KZHgf3t_4ia32mWZqVQ*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // locking 1:
    objectval_tyBM* locked_9Om1a31BzaS_5TkPLp6j4lV = NULL; // for o_resobj
   // fetch 4 arguments:
   _.v_2BkOxf2KbS8_3bswrKbmgjy = arg0; // v_node
   _.v_20uyDk84Vub_7xsAwkSm7lL = arg1; // v_lineno
   _.v_7llbD3YIz2G_3vDyN1QuPCy = arg2; // v_colpos
   _.o_5fGGXIme43z_0mc4HIwzzMj = objectcast_BM (arg3); // o_parser
   // fetched 4 arguments.
   { // fetch 2 closed values in _8dG7KZHgf3t_4ia32mWZqVQ:
   const closure_tyBM* callclos_8dG7KZHgf3t_4ia32mWZqVQ =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   unsigned nbclosed_8dG7KZHgf3t_4ia32mWZqVQ = closurewidth_BM ((const value_tyBM) callclos_8dG7KZHgf3t_4ia32mWZqVQ);
   if (nbclosed_8dG7KZHgf3t_4ia32mWZqVQ > 0)
      _.o_0yYNVlhznPw_115q5g6EYO0 = objectcast_BM (callclos_8dG7KZHgf3t_4ia32mWZqVQ->nodt_sons[0]); // o_class
   if (nbclosed_8dG7KZHgf3t_4ia32mWZqVQ > 1)
      _.o_3aIzfMKBbIH_2z7FHf3JclZ = objectcast_BM (callclos_8dG7KZHgf3t_4ia32mWZqVQ->nodt_sons[1]); // o_verb
   } // fetched 2 closed values in _8dG7KZHgf3t_4ia32mWZqVQ.
   // routine _8dG7KZHgf3t_4ia32mWZqVQ body:

startblock__5SooyVqYKIT_4dQpCFeTVkV: __attribute__((unused));
{ /* +block _5SooyVqYKIT_4dQpCFeTVkV */ 
 /*i_lineno:*/_.n_6x2LYnlYgQG_6FXtmtwODgo = //assign _67dfantiJB6_0raShkMRDHL  
 /* val_to_int */ getint_BM( /*v_lineno:*/_.v_20uyDk84Vub_7xsAwkSm7lL) ; 
 
 
 /*i_colpos:*/_.n_2sygPI8PHgL_4RgFW0PkZbd = //assign _7pGANo80KI0_7YOZDlNgX2W  
 /* val_to_int */ getint_BM( /*v_colpos:*/_.v_7llbD3YIz2G_3vDyN1QuPCy) ; 
 
//+ #2/18 of block _5SooyVqYKIT_4dQpCFeTVkV :: 
 
 
{ // run _90UqHX73obp_8XQ0EEfsW6q 
/*debug for_loop#readmacro start v_node lineno colpos o_parser o_class o_verb*/
DBGPRINTF_BM("for_loop#readmacro start €%.9s v_node=%s lineno#%ld colpos#%ld o_parser=%s o_class=%s o_verb=%s",
 "_90UqHX73obp_8XQ0EEfsW6q",
 OUTSTRVALUE_BM( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),
 (long int) ( /*i_lineno:*/_.n_6x2LYnlYgQG_6FXtmtwODgo),
 (long int) ( /*i_colpos:*/_.n_2sygPI8PHgL_4RgFW0PkZbd),
 objectdbg_BM( /*o_parser:*/_.o_5fGGXIme43z_0mc4HIwzzMj),
 objectdbg1_BM( /*o_class:*/_.o_0yYNVlhznPw_115q5g6EYO0),
 objectdbg2_BM( /*o_verb:*/_.o_3aIzfMKBbIH_2z7FHf3JclZ));; 
} // end run _90UqHX73obp_8XQ0EEfsW6q 
 
 
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _4Cj2wfMNdSb_4STaolxG6qN  
/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy); 
 
//+ #4/18 of block _5SooyVqYKIT_4dQpCFeTVkV :: 
 
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _6fyZzQUoppO_8VopYAJeuG9  
 0; 
 
 
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _210mSO8s3LZ_9iKjW7eaG6Q  
/*nodenthson:*/nodenthson_BM(( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)); 
 
//+ #6/18 of block _5SooyVqYKIT_4dQpCFeTVkV :: 
 
 /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81 = //assign _7wn1KeIUJpE_8XLnDlRd9Wn  
/*nodeconn:*/nodeconn_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe); 
 
 
if /*cond _9wmUQdGs520_80QjLaRO5pa*/  
/*when _1j5eDZEaK15_1f7jqPaTIVw:*/ 
 (/*equal_object:*/(( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81) == ( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[2] /*!in*/)))) { //body when _1j5eDZEaK15_1f7jqPaTIVw  
 /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx = //assign _0T7bvmg9y4B_6u9BnDCdOJK   
/*val_to_object:*/objectcast_BM(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0)));  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _0x6O4kjsMGP_6yqdEXIJI0J   
/*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1));  
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _4dAzkespyiw_5Rpy5MMVlOv   
/*nodenthson:*/nodenthson_BM(( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));  
 /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81 = //assign _9QoBtoGxJiH_9R9rdZ9gZVe   
/*nodeconn:*/nodeconn_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe);  
  
} //endwhen _1j5eDZEaK15_1f7jqPaTIVw  
/*endcond _9wmUQdGs520_80QjLaRO5pa*/ 
 
//+ #8/18 of block _5SooyVqYKIT_4dQpCFeTVkV :: 
 
if /*cond _74NGaPfSZlF_0iubWpQ8MfB*/  
/*when _8YCEgWraf8u_6RbayBBuUw2:*/ 
 (/*equal_object:*/(( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81) == ( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[38] /*!label*/)))) { //body when _8YCEgWraf8u_6RbayBBuUw2  
 /*o_curlab:*/_.o_79dADic8Iro_3skCK4hK3iW = //assign _2oLGfTIC3p3_5aXkVmeoQew   
/*val_to_object:*/objectcast_BM(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0)));  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _5PIoPfFxk3a_3kbj9xa2zBf   
/*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1));  
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _9MDYXnUneZC_55Zuplll9EL   
/*nodenthson:*/nodenthson_BM(( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));  
 /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81 = //assign _5AU8VvXYKZi_4SctVVKIMuJ   
/*nodeconn:*/nodeconn_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe);  
  
} //endwhen _8YCEgWraf8u_6RbayBBuUw2  
/*endcond _74NGaPfSZlF_0iubWpQ8MfB*/ 
 
 
 /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4 = //assign _7TkhikithqF_1AkAJAb7x0F  
/*val_to_object:*/objectcast_BM(/*nodenthson:*/nodenthson_BM(( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B))); 
 
//+ #10/18 of block _5SooyVqYKIT_4dQpCFeTVkV :: 
 
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _8279WDUMSye_2IKLmTEWTnL  
/*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1)); 
 
 
 /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU = //assign _99PVif8XeCx_8hVkInmD6H8  
/*nodenthson:*/nodenthson_BM(( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)); 
 
//+ #12/18 of block _5SooyVqYKIT_4dQpCFeTVkV :: 
 
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _0diYr9ji2Mr_3kb6QR3hxRC  
/*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1)); 
 
 
if /*cond _0vn7ueI4Bxr_4hnicjlB78i*/  
/*when _6utotmA8SWn_4ZHG6JuneX9:*/ 
 (/*is_null:*/(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx)==NULL)) { //body when _6utotmA8SWn_4ZHG6JuneX9  
 /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx = //assign _6fXfi9x99V4_8dSOffH1aBN   
/*makeobj:*/makeobj_BM();  
{ // start cexpansion _2JM5j1QuRSt_5QR1vdsuXJf - objputglobalspace   
/*objputglobalspace:*/objputspacenum_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx), GlobalSp_BM);;   
} // end cexpansion _2JM5j1QuRSt_5QR1vdsuXJf - objputglobalspace   
  
} //endwhen _6utotmA8SWn_4ZHG6JuneX9  
/*endcond _0vn7ueI4Bxr_4hnicjlB78i*/ 
 
//+ #14/18 of block _5SooyVqYKIT_4dQpCFeTVkV :: 
 
if /*cond _9zUzuF3PVd4_0iiDvhivXyX*/  
/*when _6bvk442PdYH_20YoMJsuair:*/ 
 (/*is_null:*/(( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4)==NULL)) { //body when _6bvk442PdYH_20YoMJsuair  
  
{ // run _8PjWlWqS45Y_8aY2Bsf4k6R  
/*syntax error no-varindex*/
objparserrorprintf_BM( /*o_parser:*/_.o_5fGGXIme43z_0mc4HIwzzMj, CURFRAME_BM,
 /*i_lineno:*/_.n_6x2LYnlYgQG_6FXtmtwODgo,  /*i_colpos:*/_.n_2sygPI8PHgL_4RgFW0PkZbd,
"missing varindex in for-count ^%s ( [*in(...)] [*label(...)] varindex countexp substmts...)",
objectdbg_BM( /*o_verb:*/_.o_3aIzfMKBbIH_2z7FHf3JclZ));;  
} // end run _8PjWlWqS45Y_8aY2Bsf4k6R  
  
} //endwhen _6bvk442PdYH_20YoMJsuair  
/*endcond _9zUzuF3PVd4_0iiDvhivXyX*/ 
 
 
if /*cond _4fv32pcF6Kd_963Su6eVxQg*/  
/*when _2BybqU6CWcr_8Njufk4aC0o:*/ 
 (/*is_null:*/(( /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU)==NULL)) { //body when _2BybqU6CWcr_8Njufk4aC0o  
  
{ // run _2FluLEIlzlQ_7HdZgyOqcUn  
/*syntax error no-countexp*/
objparserrorprintf_BM( /*o_parser:*/_.o_5fGGXIme43z_0mc4HIwzzMj, CURFRAME_BM,
 /*i_lineno:*/_.n_6x2LYnlYgQG_6FXtmtwODgo,  /*i_colpos:*/_.n_2sygPI8PHgL_4RgFW0PkZbd,
"missing countexp in for-count ^%s ( [*in(...)] [*label(...)] varindex countexp substmts...)",
objectdbg_BM( /*o_verb:*/_.o_3aIzfMKBbIH_2z7FHf3JclZ));;  
} // end run _2FluLEIlzlQ_7HdZgyOqcUn  
  
} //endwhen _2BybqU6CWcr_8Njufk4aC0o  
/*endcond _4fv32pcF6Kd_963Su6eVxQg*/ 
 
//+ #16/18 of block _5SooyVqYKIT_4dQpCFeTVkV :: 
 
 /*i_start:*/_.n_4Dke6KoVx5r_1CoVhK8mVmc = //assign _6yN8IRiJKaB_0Ynq7PFj9TC  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B; 
 
 
 
{ // begin lockobj _9Om1a31BzaS_5TkPLp6j4lV 
  objectval_tyBM* curlockedob_9Om1a31BzaS_5TkPLp6j4lV = ( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx); 
if (objlock_BM (curlockedob_9Om1a31BzaS_5TkPLp6j4lV)) {  
locked_9Om1a31BzaS_5TkPLp6j4lV = curlockedob_9Om1a31BzaS_5TkPLp6j4lV;  
  
 
{ // run _4AdqBDnuFGi_7lYJ3HxFm5x 
/*debug for_loop#readmacro v_node lineno colpos o_resobj*/
DBGPRINTF_BM("for_loop#readmacro €%.9s v_node=%s lineno#%ld colpos#%ld o_resobj=%s",
 "_4AdqBDnuFGi_7lYJ3HxFm5x",
 OUTSTRVALUE_BM( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),
 (long int) ( /*i_lineno:*/_.n_6x2LYnlYgQG_6FXtmtwODgo),
 (long int) ( /*i_colpos:*/_.n_2sygPI8PHgL_4RgFW0PkZbd),
 objectdbg_BM( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx));; 
} // end run _4AdqBDnuFGi_7lYJ3HxFm5x 
  
if /*cond _28fOzNY8Ck5_3m5Gj8j3ALy*/  
/*when _6Al3Bi72SRA_9nH9fFB9MUz:*/ 
 (/*not:*/ (! (/*objectisinstance:*/ objectisinstance_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( /*o_class:*/_.o_0yYNVlhznPw_115q5g6EYO0))))) { //body when _6Al3Bi72SRA_9nH9fFB9MUz  
{ // start cexpansion _0k4wLtqe1qE_0mEW2gFLfvy - objputclass   
/*objputclass:*/objputclass_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( /*o_class:*/_.o_0yYNVlhznPw_115q5g6EYO0));   
} // end cexpansion _0k4wLtqe1qE_0mEW2gFLfvy - objputclass   
  
} //endwhen _6Al3Bi72SRA_9nH9fFB9MUz  
/*endcond _28fOzNY8Ck5_3m5Gj8j3ALy*/ 
  
//+ #2/11 of lockobj _9Om1a31BzaS_5TkPLp6j4lV ::  
{ // start cexpansion _5ZvpQtV9DIb_5eIJPzrSdXF - objresetattrs  
/*objresetattrs:*/ objresetattrs_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),(unsigned)(/*substract_int:*/(( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) - ( /*i_start:*/_.n_4Dke6KoVx5r_1CoVhK8mVmc))));   
} // end cexpansion _5ZvpQtV9DIb_5eIJPzrSdXF - objresetattrs   
  
{ // start cexpansion _4j8Yw7eNafO_3G8sPVjnCN9 - objresetattrs  
/*objresetattrs:*/ objresetattrs_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),(unsigned)( 5));  
} // end cexpansion _4j8Yw7eNafO_3G8sPVjnCN9 - objresetattrs  
  
//+ #4/11 of lockobj _9Om1a31BzaS_5TkPLp6j4lV ::  
if /*cond _63g2w1NiAWP_7xZNFD9DXFo*/  
/*when _3DdyhRUe9dE_16cDuNVvrHq:*/ 
 ( /*o_curlab:*/_.o_79dADic8Iro_3skCK4hK3iW) { //body when _3DdyhRUe9dE_16cDuNVvrHq  
{ // start cexpansion _3wnQKoelMkT_4aZOgoixqhx - objputattr   
/*objputattr:*/objputattr_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[38] /*!label*/)),( /*o_curlab:*/_.o_79dADic8Iro_3skCK4hK3iW));   
} // end cexpansion _3wnQKoelMkT_4aZOgoixqhx - objputattr   
  
} //endwhen _3DdyhRUe9dE_16cDuNVvrHq  
/*endcond _63g2w1NiAWP_7xZNFD9DXFo*/ 
  
{ // start cexpansion _04Du9TPik7B_4c1jk59AMbA - objputattr  
/*objputattr:*/objputattr_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[56] /*!count*/)),( /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU));  
} // end cexpansion _04Du9TPik7B_4c1jk59AMbA - objputattr  
  
//+ #6/11 of lockobj _9Om1a31BzaS_5TkPLp6j4lV ::  
{ // start cexpansion _927qtIvWTqf_5RR3BZ5Ja2H - objputattr  
/*objputattr:*/objputattr_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[65] /*!index*/)),( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4));  
} // end cexpansion _927qtIvWTqf_5RR3BZ5Ja2H - objputattr  
  
 
//// +while _8kjbgwzFmjv_4jrW3mPyJAP 
startblock__8kjbgwzFmjv_4jrW3mPyJAP:  /*+!while*/; 
{ /* +while _8kjbgwzFmjv_4jrW3mPyJAP */  
if (!(/*while _8kjbgwzFmjv_4jrW3mPyJAP cond:*/ (/*less_int:*/( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) < ( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k)))) //: testwhile _8kjbgwzFmjv_4jrW3mPyJAP failing   
  goto endblock__8kjbgwzFmjv_4jrW3mPyJAP; //failwhile   
// while _8kjbgwzFmjv_4jrW3mPyJAP body:   
// while _8kjbgwzFmjv_4jrW3mPyJAP comp#0:  
 /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _06FkUnkHzVK_2RFUCedoKwa   
/*nodenthson:*/nodenthson_BM(( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));  
// while _8kjbgwzFmjv_4jrW3mPyJAP comp#1:  
  
{ // run _7iu73niFBdG_9sOu1kDiCGg  
/*debug for_loop#readmacro v_node o_resobj ii v_comp*/
DBGPRINTF_BM("for_loop#readmacro €%.9s v_node=%s o_resobj=%s ii#%ld v_comp=%s",
 "_7iu73niFBdG_9sOu1kDiCGg",
 OUTSTRVALUE_BM( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),
 objectdbg_BM( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),
 (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
 OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe));;  
} // end run _7iu73niFBdG_9sOu1kDiCGg  
// while _8kjbgwzFmjv_4jrW3mPyJAP comp#2:  
if /*cond _4DhnSVxzDqk_7H3ts7HyHC7*/   
/*when _1JZf5yCHQQe_9EJfiGR7PgJ:*/  
 (/*is_objectv*/ isobject_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) { //body when _1JZf5yCHQQe_9EJfiGR7PgJ   
{ // start cexpansion _72SahaxYkMv_43rvkWpzaWy - objappendcomp    
/*objappendcomp:*/objappendcomp_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe));    
} // end cexpansion _72SahaxYkMv_43rvkWpzaWy - objappendcomp    
   
} //endwhen _1JZf5yCHQQe_9EJfiGR7PgJ   
else if   
/*when _7hfwvOfsWF8_8i8a85HTGdB:*/  
 (/*is_null:*/(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)==NULL)) { //body when _7hfwvOfsWF8_8i8a85HTGdB   
{ // start cexpansion _6PQl0qnzf17_1MSNcVNLu73 - objappendcomp    
/*objappendcomp:*/objappendcomp_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( NULL));    
} // end cexpansion _6PQl0qnzf17_1MSNcVNLu73 - objappendcomp    
   
} //endwhen _7hfwvOfsWF8_8i8a85HTGdB   
else { /*cond else _4DhnSVxzDqk_7H3ts7HyHC7*/   
  
{ // run _48QzUalO2TC_3muK4hOY8o6  
/*syntaxerror lineno colpos o_verb bad v_comp ii v_node expecting object-stmt or nil*/
 objparserrorprintf_BM( /*o_parser:*/_.o_5fGGXIme43z_0mc4HIwzzMj, CURFRAME_BM,
 (unsigned)( /*i_lineno:*/_.n_6x2LYnlYgQG_6FXtmtwODgo), (unsigned)( /*i_colpos:*/_.n_2sygPI8PHgL_4RgFW0PkZbd),
 "^%s: bad component %s #%ld in %s, expecting object-statement or nil",
 objectdbg_BM( /*o_verb:*/_.o_3aIzfMKBbIH_2z7FHf3JclZ),
 OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
 (long int)( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
 OUTSTRVALUE_BM( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy));
;  
} // end run _48QzUalO2TC_3muK4hOY8o6  
} /*cond else _4DhnSVxzDqk_7H3ts7HyHC7*/   
/*endcond _4DhnSVxzDqk_7H3ts7HyHC7*/  
// while _8kjbgwzFmjv_4jrW3mPyJAP comp#3:  
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _70OHr2grpQb_0FNZSvGKd2q   
/*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1));  
  
goto startblock__8kjbgwzFmjv_4jrW3mPyJAP; // repeatwhile  
endblock__8kjbgwzFmjv_4jrW3mPyJAP: /*endingwhile*/;  
} /*-endwhile _8kjbgwzFmjv_4jrW3mPyJAP */ 
 
  
//+ #8/11 of lockobj _9Om1a31BzaS_5TkPLp6j4lV ::  
{ // start cexpansion _4k7bXst8Ysh_6rBll1H8CUo - objtouchnow  
/*objtouchnow:*/objtouchnow_BM( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx);;  
} // end cexpansion _4k7bXst8Ysh_6rBll1H8CUo - objtouchnow  
  
 
{ // run _9e8Dev69XH8_2fxJgWs8eaB 
/*debug for_loop#readmacro end o_resobj*/
DBGPRINTF_BM("for_loop#readmacro end €%.9s o_resobj=%s",
 "_9e8Dev69XH8_2fxJgWs8eaB",
 objectdbg_BM( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx));; 
} // end run _9e8Dev69XH8_2fxJgWs8eaB 
  
/*return _0IHnwGG1GxP_4kooak9wiyM:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx; 
 goto epilog_8dG7KZHgf3t_4ia32mWZqVQ; 
  
objunlock_BM (locked_9Om1a31BzaS_5TkPLp6j4lV), locked_9Om1a31BzaS_5TkPLp6j4lV = NULL; 
} } // end objlock _9Om1a31BzaS_5TkPLp6j4lV 
/* !endingblock _5SooyVqYKIT_4dQpCFeTVkV */ 
goto endblock__5SooyVqYKIT_4dQpCFeTVkV; 
endblock__5SooyVqYKIT_4dQpCFeTVkV: ; 
} /*-block _5SooyVqYKIT_4dQpCFeTVkV */

 epilog_8dG7KZHgf3t_4ia32mWZqVQ: __attribute__ ((unused)); // routine _8dG7KZHgf3t_4ia32mWZqVQ epilogue:
   // unlocking 1:
    if (locked_9Om1a31BzaS_5TkPLp6j4lV != NULL)
       objunlock_BM(locked_9Om1a31BzaS_5TkPLp6j4lV), locked_9Om1a31BzaS_5TkPLp6j4lV = NULL; // for o_resobj
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _8dG7KZHgf3t_4ia32mWZqVQ routine#21 _8dG7KZHgf3t_4ia32mWZqVQ




value_tyBM crout_8imWClcIFKt_6w2H2ouB4I6_BM //#22+
 (struct stackframe_stBM* stkf, // iterate_sequence_minifunc
//!iterate on sequence v_seq the function v_fun with 2nd argument v_arg
  // 3 arguments
  const value_tyBM arg0,  // v_seq
  const value_tyBM arg1,  // v_fun
  const value_tyBM arg2,  // v_arg
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of iterate_sequence_minifunc
  struct frame_8imWClcIFKt_6w2H2ouB4I6_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 4 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    value_tyBM v_4Q4WBLjAPTV_5WVLmhAvCJY; // v_arg
    value_tyBM v_8jKgolslEuE_4dxzrK5R2B4; // v_fun
    value_tyBM v_9vc0quxdnhj_3zLw1MEwl1e; // v_seq
    /// 2 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
   } _;
   memset (&_, 0, sizeof(struct frame_8imWClcIFKt_6w2H2ouB4I6_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 4;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[78] /*|iterate_sequence_minifunc*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 3 arguments:
   _.v_9vc0quxdnhj_3zLw1MEwl1e = arg0; // v_seq
   _.v_8jKgolslEuE_4dxzrK5R2B4 = arg1; // v_fun
   _.v_4Q4WBLjAPTV_5WVLmhAvCJY = arg2; // v_arg
   // fetched 3 arguments.
   // no closed values in iterate_sequence_minifunc.
   // routine _8imWClcIFKt_6w2H2ouB4I6 body:

startblock__2W6NObLb2d4_6OfkP3dYlF3: __attribute__((unused));
{ /* +block _2W6NObLb2d4_6OfkP3dYlF3 */ 
 /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _3EakP4EXPLZ_10btDL0iqAt  
/*seqlength*/sequencesize_BM ( /*v_seq:*/_.v_9vc0quxdnhj_3zLw1MEwl1e); 
 
 
 /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _1Z2mN7VIEbD_4RJunrL2QcV  
 0; 
 
 
 
startblock__3vvVJBONOyK_3kn86nuYwr1: __attribute__((unused)); 
{ /* +loop _3vvVJBONOyK_3kn86nuYwr1 */ 
  startloop__3vvVJBONOyK_3kn86nuYwr1: __attribute__((unused)); 
  
  
if /*cond _7pBaII8qZHM_8xoaIKeilBk*/   
/*when _8qsLnTz2QdD_9nZub2hBMEb:*/  
 ((/*greaterequal_int:*/( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) >= ( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k))) { //body when _8qsLnTz2QdD_9nZub2hBMEb   
// exit _9dmQwUU17M1_1km5cSGzJly   
goto endblock__3vvVJBONOyK_3kn86nuYwr1;   
   
} //endwhen _8qsLnTz2QdD_9nZub2hBMEb   
/*endcond _7pBaII8qZHM_8xoaIKeilBk*/  
  
  
  
/* !endingloop _3vvVJBONOyK_3kn86nuYwr1 */  
goto startloop__3vvVJBONOyK_3kn86nuYwr1;  
endblock__3vvVJBONOyK_3kn86nuYwr1: __attribute__((unused));  
} /*-loop _3vvVJBONOyK_3kn86nuYwr1 */ 
/* !endingblock _2W6NObLb2d4_6OfkP3dYlF3 */ 
goto endblock__2W6NObLb2d4_6OfkP3dYlF3; 
endblock__2W6NObLb2d4_6OfkP3dYlF3: ; 
} /*-block _2W6NObLb2d4_6OfkP3dYlF3 */

 epilog_8imWClcIFKt_6w2H2ouB4I6: __attribute__ ((unused)); // routine _8imWClcIFKt_6w2H2ouB4I6 epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _8imWClcIFKt_6w2H2ouB4I6 routine#22 iterate_sequence_minifunc




value_tyBM crout_8NgOdlJACWN_8pbYZXkHpCj_BM //#23
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[80] /*|_8NgOdlJACWN_8pbYZXkHpCj*/;
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
/*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[65] /*!index*/)))); 
  
 /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU = //assign _5seYtoR5pxJ_37Qi2lVAneY  
/*objgetattr:*/objgetattr_BM(( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[56] /*!count*/))); 
  
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
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[39] /*!basiclo_block*/)))) { //body when _4KA7D8V97uE_0GKeafNCOjg    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _7qms8dDaskD_9n8IbyY8sp0     
(send3_BM (( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), /*sel:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[62] /*!emit_block*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),  ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));    
    
} //endwhen _4KA7D8V97uE_0GKeafNCOjg    
else if    
/*when _5fJtp7BHeaI_3SdQy8HSkeb:*/   
 (/*objectisinstance:*/ objectisinstance_BM(( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[41] /*!basiclo_statement*/)))) { //body when _5fJtp7BHeaI_3SdQy8HSkeb    
 /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _7nNnwMcKtuN_455Z1RFw66Z     
(send3_BM (( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), /*sel:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[17] /*!emit_statement*/)), ((struct stackframe_stBM*)&_), 
 ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),  ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), 
 (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));    
    
} //endwhen _5fJtp7BHeaI_3SdQy8HSkeb    
else { /*cond else _91XVXtprccW_28DRbTiOzSR*/    
//failure _2MJKx6JJ45K_6rmHWbevG98    
PLACEDFAILURE_BM(__LINE__,    
          /*failreason:*/ (((value_tyBM) makenode5_BM
 (/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[44] /*!failure_bad_class*/)), 
 /*make_node 5 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[80] /*!_8NgOdlJACWN_8pbYZXkHpCj*/)), 
 
( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), 
 
( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[28] /*|_2MJKx6JJ45K_6rmHWbevG98*/)),
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
 (/*make_node conn:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[48] /*!failure_miss*/)), 
 /*make_node 5 sons:*/ 
( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[80] /*!_8NgOdlJACWN_8pbYZXkHpCj*/)), 
 
( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), 
 
(/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)), 
 
// make_node arg #4 
( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), 
 
( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW)))),
                /*failplace:*/ ( /*modconst:*/(constob_3BFt4NfJmZC_7iYi2dwM38B_BM[57] /*|_5XtoXsvceoR_1Q6dI4J6G4X*/)),
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
} // end _8NgOdlJACWN_8pbYZXkHpCj routine#23 _8NgOdlJACWN_8pbYZXkHpCj




value_tyBM crout_9CG8SKNs6Ql_4PiHd8cnydn_BM //#24
 (struct stackframe_stBM* stkf, //
//!clear°dict_object minifun
  // 1 arguments
  const value_tyBM arg0,  // odict
  const value_tyBM arg1_ __attribute__((unused)),
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _9CG8SKNs6Ql_4PiHd8cnydn
  struct frame_9CG8SKNs6Ql_4PiHd8cnydn_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 2 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_7n2SLLuWOjH_4ArhFUjmckz; // odict
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_9CG8SKNs6Ql_4PiHd8cnydn_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 2;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[85] /*|_9CG8SKNs6Ql_4PiHd8cnydn*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 1 arguments:
   _.o_7n2SLLuWOjH_4ArhFUjmckz = objectcast_BM (arg0); // odict
   // fetched 1 arguments.
   // no closed values in _9CG8SKNs6Ql_4PiHd8cnydn.
   // routine _9CG8SKNs6Ql_4PiHd8cnydn body:

startblock__1lmLI285f7p_4im4Ls4Xewh: __attribute__((unused));
{ /* +block _1lmLI285f7p_4im4Ls4Xewh */ 
if /*cond _58n2IHCyrnJ_19R71AKw5aF*/  
/*when _8QkV0tL7Jvt_9mc0QaZYbyv:*/ 
 (/*objputdictpayl:*/ objputdictpayl_BM(( /*odict:*/_.o_7n2SLLuWOjH_4ArhFUjmckz))) { //body when _8QkV0tL7Jvt_9mc0QaZYbyv  
/*return _2RCw0JQb23v_2NfFku112jv:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned  
 /*odict:*/_.o_7n2SLLuWOjH_4ArhFUjmckz;  
 goto epilog_9CG8SKNs6Ql_4PiHd8cnydn;  
  
} //endwhen _8QkV0tL7Jvt_9mc0QaZYbyv  
/*endcond _58n2IHCyrnJ_19R71AKw5aF*/ 
 
 
if /*cond _4QR8kuWiKxV_9oKMeD79KDQ*/  
/*when _8bCPs7gML9M_12nXMrdhzvW:*/ 
 (/*objputdictpayl:*/ objputdictpayl_BM(( /*odict:*/_.o_7n2SLLuWOjH_4ArhFUjmckz))) { //body when _8bCPs7gML9M_12nXMrdhzvW  
/*return _9198YxnrBs6_7u9nhmAA8Q6:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned  
 /*odict:*/_.o_7n2SLLuWOjH_4ArhFUjmckz;  
 goto epilog_9CG8SKNs6Ql_4PiHd8cnydn;  
  
} //endwhen _8bCPs7gML9M_12nXMrdhzvW  
/*endcond _4QR8kuWiKxV_9oKMeD79KDQ*/ 
 
/* !endingblock _1lmLI285f7p_4im4Ls4Xewh */ 
goto endblock__1lmLI285f7p_4im4Ls4Xewh; 
endblock__1lmLI285f7p_4im4Ls4Xewh: ; 
} /*-block _1lmLI285f7p_4im4Ls4Xewh */

 epilog_9CG8SKNs6Ql_4PiHd8cnydn: __attribute__ ((unused)); // routine _9CG8SKNs6Ql_4PiHd8cnydn epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _9CG8SKNs6Ql_4PiHd8cnydn routine#24 _9CG8SKNs6Ql_4PiHd8cnydn




// end of 25 generated routines


// the constant ids for 87 constants:
const char* const constid_3BFt4NfJmZC_7iYi2dwM38B_BM[87+1] = {
 /*0:*/
 "_08PMymoD6YJ_8rspWoCg4Xu", //! emit_statement°basiclo_outstmt < o_stmt (o_modgen o_routprep v_depth)
 "_0cUdonky1bM_4IVhwlVRBMk", //! webhandler testhello minifunc
 "_0eMGYofuNVh_8ZP2mXdhtHO",//in
 "_0g1CBaxjMIB_7NZdyHUikLG", //! out#readmacro (v_node v_lineno v_colpos o_parser)
 "_0o8bMUSb0El_8cRNhyRuvjD",//more_indent
 /*5:*/
 "_0vgCFjXblkx_4zCMhMAWjVK",//int
 "_0vCFi47Ctm6_70R5Tci6JuH", //! emit_block°basiclo_for_up_loop  < o_block (o_modgen o_routprep v_depth)
 "_0EmM9kH8Wgr_7fpd0oIo9xQ",//out
 "_0HZ6LhCuD3B_3wOqehpkD81", //! else fail bad-class miniscan_stmt°basiclo_countloop o_substmt ii o_stmt o_routprep depth
 "_0JktC4mAHCa_1KNr6uMIqIi", //! dump_scan°list_object minifunc for list_object o1 & dumperobj o2
 /*10:*/
 "_0SinERsgdvQ_57dLCP63i9r", //! forgetname#command_handler
 "_0YOXUe7rEJC_3jFMjOAQRs9",//element_of_closed_minifunc
 "_1dzZlwqKdLH_8HjkBsL9Mar",//add
 "_1jJjA6LcXiX_1V4ZcXlje09",//name
 "_1kz7viwMzTp_6PgLhdZzMEy", //! miniscan_stmt°basiclo_outstmt < o_stmt (o_routprep v_depth o_from)
 /*15:*/
 "_1lCz1IP7t5R_8NTFVv0tnOi",//octa
 "_1m5rw0BZl8f_4M9cndtjRl8", //! fail failure-miss out o_stmt o_routprep depth o_from
 "_1ERH9PxNhPb_2o869yOMuH0",//emit_statement
 "_1FEnnpEkGdI_5DAcVDL5XHG",//dump_value
 "_227kofebdwq_9fj8R3qXt7B", //! fail-miss  miniscan_stmt°basiclo_countloop miniscan_stmt o_substmt ii o_stmt o_routprep depth
 /*20:*/
 "_22Zd68WPKUO_6AoIuBcbUb2", //! dump_scan°dict_object minifunc for dict-object odict and dumperobj odumper
 "_26UbzubL5aT_2vDJc23p59r", //! fail-typerr int o_restype v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
 "_2bZ4BfCci5V_3WTzG7V25y4", //! put°dict_object minifunc
 "_2eREyARXfUb_2mTxUngIL6Y", //! fail-typerr object o_restype v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
 "_2gthNYOWogO_4sVTU1JbmUH",//miniscan_block
 /*25:*/
 "_2nl9zcaSUwe_8UBiMp1OuMk",//identity_minifunc
 "_2wGWzItVmrN_2CBwG6iHWFO",//newline
 "_2yhrFze2uwV_6G7BfGXfplP",//set_indent
 "_2MJKx6JJ45K_6rmHWbevG98", //! fail-bad-class emit_block°basiclo_for_down_loop o_comp ii o_modgen o_block
 "_2P7OoZumXdx_5sUQ9SPbVwn",//utf8_enc
 /*30:*/
 "_35gLacRFhq5_90zAPxiDIlh",//space
 "_3hMno2PB1II_6IrKetMkipy", //! else/bad o_conn fail-miss emit_statement°basiclo_outstmt unexpected o_conn v_comp ii o_stmt o_modgen o_routprep
 "_3iiht57Wrs1_5NbiUi27oBn", //! prepend°list_object minifunc
 "_3yQlckX4DRh_4b9l9FBSSSL",//same_as_closed_minifunc
 "_3CZ4Lq3VkJF_3Qt5nkQ9R3w", //! fail-miss emit_block°basiclo_for_up_loop o_comp ii o_modgen o_block
 /*35:*/
 "_3HAeZZQ0q7b_7qyDsekaz7Y", //! clear°list_object minifunc
 "_3QmxfIKpDVI_0C4Z01aFVxK",//html_enc
 "_3RUddTzPPB8_5j4EYXKOe2g", //! else fail-miss v_comp ii o_stmt o_modgen o_routprep in emit_statement°basiclo_outstmt
 "_3XBrePAliOo_37VlAqBsb5C",//label
 "_4bYUiDmxrKK_6nPPlEl8y8x",//basiclo_block
 /*40:*/
 "_4iEFTEcHxeb_6lH464uFkTC",//equal_to_closed_minifunc
 "_4lKK08v9A0t_0GGsir35UxP",//basiclo_statement
 "_4qlegfkPzrC_17skUfJP7v8", //! dump_data°dict_object minifun
 "_4wmsNr582JT_9YyamGEMhJk",//json_compact
 "_4HgYLk6htvP_4Ac2FCPfQ1C",//failure_bad_class
 /*45:*/
 "_4HAZLawO9HO_91oo1k4Ajat", //! fail-typerr string o_restype v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
 "_4M7lr5cU6VD_5hxmeH3baBf", //! append°list_object minifunction
 "_4T8am97muLl_5969SR22Ecq",//string
 "_52XwytpOPVl_3ZjmQCtadbK",//failure_miss
 "_5j8LpQULt1p_9oeOaqmfYYr", //! dump_data°list_object minifunc
 /*50:*/
 "_5oVb4fNe3eO_4GyCgc0vkQp", //! fail-miss  miniscan_stmt°basiclo_countloop miniscan_block o_substmt ii o_stmt o_routprep depth
 "_5t5nLVnGAqW_9IbjlqpPdp3",//less_indent
 "_5wNedaaTb99_3ZQe6xm9HNx",//literal_c_string
 "_5zaZ8sDu1TQ_49hqJMJDKIq", //! fail type-error index typindex varindex stmt routprep depth from
 "_5J3InN9BK1k_3C8vurQQEGh",//json_indented
 /*55:*/
 "_5J4f6u42le4_9UZMTZziEEw", //! else fail-miss v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
 "_5OiKmAdUjY5_9BPLOECag6g",//count
 "_5XtoXsvceoR_1Q6dI4J6G4X", //! fail-miss emit_block°basiclo_for_down_loop o_comp ii o_modgen o_block
 "_64UbCFBD19G_43TeBXhcYMy",//findrun_object
 "_6cS5VddZd7n_9Nnn2wYWAeL", //! fail-miss miniscan_var o_varout o_routprep depth+1 o_stmt o_from in miniscan_stmt°basiclo_outstmt
 /*60:*/
 "_6fPPUXnZhy5_8Lh5DOOe0Nu",//arity
 "_6jh60mO0Cgd_84B0HiNphqA",//miniscan_var
 "_6mk5eos8067_1odgCpnWMOj",//emit_block
 "_6xxbA8aTjZm_1sCJbVkU3Pm",//c_enc
 "_6DdZwyaWLyK_7tS2BmECOJ0",//miniscan_stmt
 /*65:*/
 "_6EG5W7z0BRb_4TBM1gyenqk",//index
 "_6MTJtvsUEYW_9WuS0LnLfmm", //! fail-bad-class emit_block°basiclo_for_up_loop o_comp ii o_modgen o_block
 "_6Rc660mzjXf_6rWF1nupKVt", //! fail type-error count countexp stmt routprep depth from
 "_7bbeIqUSje9_4jVgC7ZJmvx",//value
 "_7coI3Hezrvp_6CG1u3MlT83",//nlsp
 /*70:*/
 "_7D8xcWnEiys_8oqOVSkCxkA",//node
 "_7MtjMTkmErH_2zSJ1YDKHVi", //! dump_value°double_float < v_dbl (o_strbuf o_dump v_depth)
 "_7T9OwSFlgov_0wVJaK1eZbn",//object
 "_7WjaQkqwdaZ_6PRtbDrJHnf",//id
 "_7YmEzAVe2hC_9iA0FVXAIqp",//hexa
 /*75:*/
 "_82ho9wUUDji_4peMLha4PXl",//findobj_scan_minifunc
 "_85xjvzYjcd6_9mNZNPF6i2J", //! miniscan_stmt°basiclo_countloop < o_stmt (o_routprep v_depth o_from)
 "_8dG7KZHgf3t_4ia32mWZqVQ", //! for_loop#readmacro (v_node v_lineno v_colpos o_parser)
 "_8imWClcIFKt_6w2H2ouB4I6",//iterate_sequence_minifunc
 "_8lV53mLyu1H_3Z1SI8wDBK1",//clear
 /*80:*/
 "_8NgOdlJACWN_8pbYZXkHpCj", //! emit_block°basiclo_for_down_loop  < o_block (o_modgen o_routprep v_depth)
 "_8QmDbXEU8lU_33mrgrh3zUR", //! fail-miss arity v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
 "_95hdJENHNkN_3QuKIJTCQQQ",//failure_type_error
 "_9pvzBeIKHXF_8YDPCrQ6OEK",//put
 "_9umIVqZhssC_2WJZljFrGaA", //! fail-typerr value o_restype v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
 /*85:*/
 "_9CG8SKNs6Ql_4PiHd8cnydn", //! clear°dict_object minifun
 "_9LFIEAPDbzj_9zfBn99RgU4",//basiclo_outstmt
 NULL}; // end 87 constant ids



// the routine ids for 25 routines:
const char* const routid_3BFt4NfJmZC_7iYi2dwM38B_BM[25+1] = {
  /*0:*/
  "_08PMymoD6YJ_8rspWoCg4Xu", //!emit_statement°basiclo_outstmt < o_stmt (o_modgen o_routprep v_depth)
  "_0cUdonky1bM_4IVhwlVRBMk", //!webhandler testhello minifunc
  "_0g1CBaxjMIB_7NZdyHUikLG", //!out#readmacro (v_node v_lineno v_colpos o_parser)
  "_0vCFi47Ctm6_70R5Tci6JuH", //!emit_block°basiclo_for_up_loop  < o_block (o_modgen o_routprep v_depth)
  "_0JktC4mAHCa_1KNr6uMIqIi", //!dump_scan°list_object minifunc for list_object o1 & dumperobj o2
  "_0SinERsgdvQ_57dLCP63i9r", //!forgetname#command_handler
  "_0YOXUe7rEJC_3jFMjOAQRs9",//element_of_closed_minifunc
  "_1kz7viwMzTp_6PgLhdZzMEy", //!miniscan_stmt°basiclo_outstmt < o_stmt (o_routprep v_depth o_from)
  /*8:*/
  "_22Zd68WPKUO_6AoIuBcbUb2", //!dump_scan°dict_object minifunc for dict-object odict and dumperobj odumper
  "_2bZ4BfCci5V_3WTzG7V25y4", //!put°dict_object minifunc;
  "_2nl9zcaSUwe_8UBiMp1OuMk",//identity_minifunc
  "_3iiht57Wrs1_5NbiUi27oBn", //!prepend°list_object minifunc
  "_3yQlckX4DRh_4b9l9FBSSSL",//same_as_closed_minifunc
  "_3HAeZZQ0q7b_7qyDsekaz7Y", //!clear°list_object minifunc
  "_4iEFTEcHxeb_6lH464uFkTC",//equal_to_closed_minifunc
  "_4qlegfkPzrC_17skUfJP7v8", //!dump_data°dict_object minifunc
  /*16:*/
  "_4M7lr5cU6VD_5hxmeH3baBf", //!append°list_object minifunction
  "_5j8LpQULt1p_9oeOaqmfYYr", //!dump_data°list_object minifunc;
  "_7MtjMTkmErH_2zSJ1YDKHVi", //!dump_value°double_float < v_dbl (o_strbuf o_dump v_depth)
  "_82ho9wUUDji_4peMLha4PXl",//findobj_scan_minifunc
  "_85xjvzYjcd6_9mNZNPF6i2J", //!miniscan_stmt°basiclo_countloop < o_stmt (o_routprep v_depth o_from)
  "_8dG7KZHgf3t_4ia32mWZqVQ", //!for_loop#readmacro (v_node v_lineno v_colpos o_parser)
  "_8imWClcIFKt_6w2H2ouB4I6",//iterate_sequence_minifunc
  "_8NgOdlJACWN_8pbYZXkHpCj", //!emit_block°basiclo_for_down_loop  < o_block (o_modgen o_routprep v_depth)
  /*24:*/
  "_9CG8SKNs6Ql_4PiHd8cnydn", //!clear°dict_object minifunc

 NULL}; // end 25 routine ids



// basiclo*module initialization
#ifdef BISMON_MODID
value_tyBM modulinit_3BFt4NfJmZC_7iYi2dwM38B_BM
  (struct stackframe_stBM *stkf, //
   const value_tyBM arg1, //
   const value_tyBM arg2, //
   const value_tyBM arg3, //
   void* dlh) {
  return simple_module_initialize_BM(arg1, arg2, arg3, //
        "_3BFt4NfJmZC_7iYi2dwM38B",//
       constob_3BFt4NfJmZC_7iYi2dwM38B_BM, //
       constid_3BFt4NfJmZC_7iYi2dwM38B_BM, //
       routid_3BFt4NfJmZC_7iYi2dwM38B_BM, //
       dlh, stkf);
} // end modulinit_3BFt4NfJmZC_7iYi2dwM38B_BM
#endif /*BISMON_MODID*/



// end of generated persistent module first_misc_module in file modbm_3BFt4NfJmZC_7iYi2dwM38B.c
