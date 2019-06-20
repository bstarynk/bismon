// generated persistent module first_misc_module
// in file modbm_3BFt4NfJmZC_7iYi2dwM38B.c -- DONT EDIT
// this generated code is GPLv3+ licensed.


#include "bismon.h"

#ifdef BISMON_MODID
DECLARE_MODULE_BM(_3BFt4NfJmZC_7iYi2dwM38B);
extern moduleinit_sigBM moduleinit_3BFt4NfJmZC_7iYi2dwM38B_BM;
#endif /*BISMON_MODID*/

#ifdef BISMON_MOMD5
const char modulmd5chksum_3BFt4NfJmZC_7iYi2dwM38B_BM[] = BISMON_MOMD5;
#endif /*BISMON_MOMD5*/



// declare 21 routines

extern const char *const routid_3BFt4NfJmZC_7iYi2dwM38B_BM[21+1];


// no failure

extern objrout_sigBM crout_0cUdonky1bM_4IVhwlVRBMk_BM; //#0 !webhandler testhello minifunc

extern objrout_sigBM crout_0g1CBaxjMIB_7NZdyHUikLG_BM; //#1 !out#readmacro (v_node v_lineno v_colpos o_parser)

extern objrout_sigBM crout_0JktC4mAHCa_1KNr6uMIqIi_BM; //#2 !dump_scan°list_object minifunc for list_object o1 & dumperobj o2

extern objrout_sigBM crout_0SinERsgdvQ_57dLCP63i9r_BM; //#3 !forgetname#command_handler

extern objrout_sigBM crout_0YOXUe7rEJC_3jFMjOAQRs9_BM; //#4 element_of_closed_minifunc

extern objrout_sigBM crout_110awzb480c_0n4frovb2yV_BM; //#5 !dump_data°contributor_class<o_contrib (o_dumper o_strbuf)

extern objrout_sigBM crout_22Zd68WPKUO_6AoIuBcbUb2_BM; //#6 !dump_scan°dict_object minifunc for dict-object odict and dumperobj odumper

extern objrout_sigBM crout_2bZ4BfCci5V_3WTzG7V25y4_BM; //#7 !put°dict_object minifunc

extern objrout_sigBM crout_2nl9zcaSUwe_8UBiMp1OuMk_BM; //#8 identity_minifunc

extern objrout_sigBM crout_3iiht57Wrs1_5NbiUi27oBn_BM; //#9 !prepend°list_object minifunc

extern objrout_sigBM crout_3yQlckX4DRh_4b9l9FBSSSL_BM; //#10 same_as_closed_minifunc

extern objrout_sigBM crout_3HAeZZQ0q7b_7qyDsekaz7Y_BM; //#11 !clear°list_object minifunc

extern objrout_sigBM crout_4iEFTEcHxeb_6lH464uFkTC_BM; //#12 equal_to_closed_minifunc

extern objrout_sigBM crout_4qlegfkPzrC_17skUfJP7v8_BM; //#13 !dump_data°dict_object minifun

extern objrout_sigBM crout_4M7lr5cU6VD_5hxmeH3baBf_BM; //#14 !append°list_object minifunction

extern objrout_sigBM crout_5j8LpQULt1p_9oeOaqmfYYr_BM; //#15 !dump_data°list_object minifunc

extern objrout_sigBM crout_7MtjMTkmErH_2zSJ1YDKHVi_BM; //#16 !dump_value°double_float < v_dbl (o_strbuf o_dump v_depth)

extern objrout_sigBM crout_82ho9wUUDji_4peMLha4PXl_BM; //#17 findobj_scan_minifunc

extern objrout_sigBM crout_8dG7KZHgf3t_4ia32mWZqVQ_BM; //#18 !for_loop#readmacro (v_node v_lineno v_colpos o_parser)

extern objrout_sigBM crout_8imWClcIFKt_6w2H2ouB4I6_BM; //#19 iterate_sequence_minifunc

extern objrout_sigBM crout_9CG8SKNs6Ql_4PiHd8cnydn_BM; //#20 !clear°dict_object minifun


// declare 34 constants
objectval_tyBM* constob_3BFt4NfJmZC_7iYi2dwM38B_BM[34+1];
const char* const constid_3BFt4NfJmZC_7iYi2dwM38B_BM[34+1];


// define 21 routines


value_tyBM crout_0cUdonky1bM_4IVhwlVRBMk_BM //#0
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[0] /*|_0cUdonky1bM_4IVhwlVRBMk*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 2 arguments:
   _.v_6QhNRfe1Cte_0niVlWfAlmO = arg0; // v_restpath
   _.o_5JuT4FgNFFh_7McrTYeT3jx = objectcast_BM (arg1); // o_webex
   // fetched 2 arguments.
   // no closed values in _0cUdonky1bM_4IVhwlVRBMk.
   const closure_tyBM* callclos_0cUdonky1bM_4IVhwlVRBMk __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_0cUdonky1bM_4IVhwlVRBMk  __attribute__((unused)) = 0;
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
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_webex:*/_.o_5JuT4FgNFFh_7McrTYeT3jx, "<script src=\'/jscript/jquery.js\'></script>\n");  
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
} // end _0cUdonky1bM_4IVhwlVRBMk routine#0 _0cUdonky1bM_4IVhwlVRBMk




value_tyBM crout_0g1CBaxjMIB_7NZdyHUikLG_BM //#1
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[2] /*|_0g1CBaxjMIB_7NZdyHUikLG*/;
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
   const closure_tyBM* callclos_0g1CBaxjMIB_7NZdyHUikLG __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_0g1CBaxjMIB_7NZdyHUikLG  __attribute__((unused)) = 0;
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
 (/*equal_object:*/(( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81) == ( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[1] /*!in*/)))) { //body when _1j5eDZEaK15_1f7jqPaTIVw  
 /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx = //assign _0T7bvmg9y4B_6u9BnDCdOJK   
/*val_to_object:*/objectcast_BM(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0)));  
{ // start cexpansion _7lC3JY25pke_03Q6D8X9cOR - objresetattrs   
/*objresetattrs:*/ objresetattrs_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),(unsigned)( 4));   
} // end cexpansion _7lC3JY25pke_03Q6D8X9cOR - objresetattrs   
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
 (/*not:*/ (! (/*objectisinstance:*/ objectisinstance_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[33] /*!basiclo_outstmt*/)))))) { //body when _8g6tUrNeSaK_9pEbME2mJdL  
{ // start cexpansion _8Zs5gF0Cjtl_8nrkFlDX8H6 - objputclass   
/*objputclass:*/objputclass_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[33] /*!basiclo_outstmt*/)));   
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
/*objputattr:*/objputattr_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[3] /*!out*/)),( /*o_varbuffer:*/_.o_44FTjgRn7Px_0AfVbgmgP6l));  
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
} // end _0g1CBaxjMIB_7NZdyHUikLG routine#1 _0g1CBaxjMIB_7NZdyHUikLG




value_tyBM crout_0JktC4mAHCa_1KNr6uMIqIi_BM //#2
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[4] /*|_0JktC4mAHCa_1KNr6uMIqIi*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 2 arguments:
   _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0); // o1
   _.o_93FBSk1ML0f_2WjSuKa9TNU = objectcast_BM (arg1); // o2
   // fetched 2 arguments.
   // no closed values in _0JktC4mAHCa_1KNr6uMIqIi.
   const closure_tyBM* callclos_0JktC4mAHCa_1KNr6uMIqIi __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_0JktC4mAHCa_1KNr6uMIqIi  __attribute__((unused)) = 0;
   // routine _0JktC4mAHCa_1KNr6uMIqIi body:

startblock__9xHQlk4snoU_6unWwGT6PcG: __attribute__((unused));
{ /* +block _9xHQlk4snoU_6unWwGT6PcG */ 
 /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy = //assign _8ggHPTQI1iG_02hVE5KybEL  
/*objlisttonodepayl:*/ (value_tyBM) objlisttonodepayl_BM(( /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[25] /*|node*/))); 
 
 
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
} // end _0JktC4mAHCa_1KNr6uMIqIi routine#2 _0JktC4mAHCa_1KNr6uMIqIi




value_tyBM crout_0SinERsgdvQ_57dLCP63i9r_BM //#3
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[5] /*|_0SinERsgdvQ_57dLCP63i9r*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 1 arguments:
   _.v_4Q4WBLjAPTV_5WVLmhAvCJY = arg0; // v_arg
   // fetched 1 arguments.
   // no closed values in _0SinERsgdvQ_57dLCP63i9r.
   const closure_tyBM* callclos_0SinERsgdvQ_57dLCP63i9r __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_0SinERsgdvQ_57dLCP63i9r  __attribute__((unused)) = 0;
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
(apply1_BM (( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[29] /*!iterate_sequence_minifunc*/)), ((struct stackframe_stBM*)&_),    
 ( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[5] /*!_0SinERsgdvQ_57dLCP63i9r*/))));  
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
} // end _0SinERsgdvQ_57dLCP63i9r routine#3 _0SinERsgdvQ_57dLCP63i9r




value_tyBM crout_0YOXUe7rEJC_3jFMjOAQRs9_BM //#4+
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[6] /*|element_of_closed_minifunc*/;
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
   const unsigned nbclosed_0YOXUe7rEJC_3jFMjOAQRs9 = closurewidth_BM ((const value_tyBM) callclos_0YOXUe7rEJC_3jFMjOAQRs9);
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
} // end _0YOXUe7rEJC_3jFMjOAQRs9 routine#4 element_of_closed_minifunc




value_tyBM crout_110awzb480c_0n4frovb2yV_BM //#5
 (struct stackframe_stBM* stkf, //
//!dump_data°contributor_class<o_contrib (o_dumper o_strbuf)
  // 3 arguments
  const value_tyBM arg0,  // o_contrib
  const value_tyBM arg1,  // o_dump
  const value_tyBM arg2,  // o_strbuf
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of _110awzb480c_0n4frovb2yV
  struct frame_110awzb480c_0n4frovb2yV_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 5 local values:
    objectval_tyBM* o_0iwWM98KNVX_0tO8Cz41val; // o_dump
    value_tyBM v_167WczZjWtG_3FofhJxQWJi; // v_str
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
    objectval_tyBM* o_4oqlg02xVwJ_918wypibNLb; // o_contrib
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_110awzb480c_0n4frovb2yV_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 5;
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[7] /*|_110awzb480c_0n4frovb2yV*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 3 arguments:
   _.o_4oqlg02xVwJ_918wypibNLb = objectcast_BM (arg0); // o_contrib
   _.o_0iwWM98KNVX_0tO8Cz41val = objectcast_BM (arg1); // o_dump
   _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg2); // o_strbuf
   // fetched 3 arguments.
   // no closed values in _110awzb480c_0n4frovb2yV.
   const closure_tyBM* callclos_110awzb480c_0n4frovb2yV __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_110awzb480c_0n4frovb2yV  __attribute__((unused)) = 0;
   // routine _110awzb480c_0n4frovb2yV body:

startblock__9Bl7iL3Qmc1_6IRbnbmMUJq: __attribute__((unused));
{ /* +block _9Bl7iL3Qmc1_6IRbnbmMUJq */ 
 
{ // run _2mZ2rKmc7Mo_1SZ28mRdggC 
/*debug dump_data°contributor_class start o_contrib o_dump o_strbuf*/
DBGPRINTF_BM("dump_data°contributor_class start €%.9s o_contrib=%s o_dump=%s o_strbuf=" FMTOBJSTRBUF_BM,
 "_2mZ2rKmc7Mo_1SZ28mRdggC",
 objectdbg_BM( /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb), objectdbg1_BM( /*o_dump:*/_.o_0iwWM98KNVX_0tO8Cz41val), OBJ2STRBUFOUT_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy));
; 
} // end run _2mZ2rKmc7Mo_1SZ28mRdggC 
 
 
{ // start out _1qaaJG5UYhn_5j3TgEyZ2tp to o_strbuf  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "//");  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "@@CONTRIBUTOR \xe2\x82\xac");  
/*out_half_id:*/ char idbuf_1qaaJG5UYhn_5j3TgEyZ2tp_n2[32]={0};  
idtocbuf32_BM (objid_BM( /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb), idbuf_1qaaJG5UYhn_5j3TgEyZ2tp_n2);  
objstrbufferprintfpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "%.12s", idbuf_1qaaJG5UYhn_5j3TgEyZ2tp_n2);  
/*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, ":: ");  
/*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, /*bytstring:*/bytstring_BM((const stringval_tyBM*)(/*objcontributornamepayl:*/((value_tyBM)(objcontributornamepayl_BM(( /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb)))))));  
/*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy); 
} // end out _1qaaJG5UYhn_5j3TgEyZ2tp 
 
 
/*return _74M1FckZwVg_6lzAfAc8gdR:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 /*o_contrib:*/_.o_4oqlg02xVwJ_918wypibNLb; 
 goto epilog_110awzb480c_0n4frovb2yV; 
 
/* !endingblock _9Bl7iL3Qmc1_6IRbnbmMUJq */ 
goto endblock__9Bl7iL3Qmc1_6IRbnbmMUJq; 
endblock__9Bl7iL3Qmc1_6IRbnbmMUJq: ; 
} /*-block _9Bl7iL3Qmc1_6IRbnbmMUJq */

 epilog_110awzb480c_0n4frovb2yV: __attribute__ ((unused)); // routine _110awzb480c_0n4frovb2yV epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _110awzb480c_0n4frovb2yV routine#5 _110awzb480c_0n4frovb2yV




value_tyBM crout_22Zd68WPKUO_6AoIuBcbUb2_BM //#6
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[10] /*|_22Zd68WPKUO_6AoIuBcbUb2*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 2 arguments:
   _.o_7n2SLLuWOjH_4ArhFUjmckz = objectcast_BM (arg0); // odict
   _.o_3cTC8W7d75H_1vteOyEoAao = objectcast_BM (arg1); // odumper
   // fetched 2 arguments.
   // no closed values in _22Zd68WPKUO_6AoIuBcbUb2.
   const closure_tyBM* callclos_22Zd68WPKUO_6AoIuBcbUb2 __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_22Zd68WPKUO_6AoIuBcbUb2  __attribute__((unused)) = 0;
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
} // end _22Zd68WPKUO_6AoIuBcbUb2 routine#6 _22Zd68WPKUO_6AoIuBcbUb2




value_tyBM crout_2bZ4BfCci5V_3WTzG7V25y4_BM //#7
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[11] /*|_2bZ4BfCci5V_3WTzG7V25y4*/;
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
   const closure_tyBM* callclos_2bZ4BfCci5V_3WTzG7V25y4 __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_2bZ4BfCci5V_3WTzG7V25y4  __attribute__((unused)) = 0;
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
} // end _2bZ4BfCci5V_3WTzG7V25y4 routine#7 _2bZ4BfCci5V_3WTzG7V25y4




value_tyBM crout_2nl9zcaSUwe_8UBiMp1OuMk_BM //#8+
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[12] /*|identity_minifunc*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 1 arguments:
   _.v_16Y2isgiwOY_4kEIm87NkH2 = arg0; // v_in
   // fetched 1 arguments.
   // no closed values in identity_minifunc.
   const closure_tyBM* callclos_2nl9zcaSUwe_8UBiMp1OuMk __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_2nl9zcaSUwe_8UBiMp1OuMk  __attribute__((unused)) = 0;
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
} // end _2nl9zcaSUwe_8UBiMp1OuMk routine#8 identity_minifunc




value_tyBM crout_3iiht57Wrs1_5NbiUi27oBn_BM //#9
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[13] /*|_3iiht57Wrs1_5NbiUi27oBn*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 2 arguments:
   _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0); // o1
   _.v_09RxU8xDco3_2Zxwfb13oDZ = arg1; // v2
   // fetched 2 arguments.
   // no closed values in _3iiht57Wrs1_5NbiUi27oBn.
   const closure_tyBM* callclos_3iiht57Wrs1_5NbiUi27oBn __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_3iiht57Wrs1_5NbiUi27oBn  __attribute__((unused)) = 0;
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
} // end _3iiht57Wrs1_5NbiUi27oBn routine#9 _3iiht57Wrs1_5NbiUi27oBn




value_tyBM crout_3yQlckX4DRh_4b9l9FBSSSL_BM //#10+
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[14] /*|same_as_closed_minifunc*/;
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
   const unsigned nbclosed_3yQlckX4DRh_4b9l9FBSSSL = closurewidth_BM ((const value_tyBM) callclos_3yQlckX4DRh_4b9l9FBSSSL);
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
} // end _3yQlckX4DRh_4b9l9FBSSSL routine#10 same_as_closed_minifunc




value_tyBM crout_3HAeZZQ0q7b_7qyDsekaz7Y_BM //#11
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[16] /*|_3HAeZZQ0q7b_7qyDsekaz7Y*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 1 arguments:
   _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0); // o1
   // fetched 1 arguments.
   // no closed values in _3HAeZZQ0q7b_7qyDsekaz7Y.
   const closure_tyBM* callclos_3HAeZZQ0q7b_7qyDsekaz7Y __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_3HAeZZQ0q7b_7qyDsekaz7Y  __attribute__((unused)) = 0;
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
} // end _3HAeZZQ0q7b_7qyDsekaz7Y routine#11 _3HAeZZQ0q7b_7qyDsekaz7Y




value_tyBM crout_4iEFTEcHxeb_6lH464uFkTC_BM //#12+
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[18] /*|equal_to_closed_minifunc*/;
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
   const unsigned nbclosed_4iEFTEcHxeb_6lH464uFkTC = closurewidth_BM ((const value_tyBM) callclos_4iEFTEcHxeb_6lH464uFkTC);
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
} // end _4iEFTEcHxeb_6lH464uFkTC routine#12 equal_to_closed_minifunc




value_tyBM crout_4qlegfkPzrC_17skUfJP7v8_BM //#13
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[19] /*|_4qlegfkPzrC_17skUfJP7v8*/;
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
   const closure_tyBM* callclos_4qlegfkPzrC_17skUfJP7v8 __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_4qlegfkPzrC_17skUfJP7v8  __attribute__((unused)) = 0;
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
(send3_BM (( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[30] /*|clear*/)), /*sel:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[9] /*|dump_value*/)), ((struct stackframe_stBM*)&_),   
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
(send3_BM (( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[31] /*|put*/)), /*sel:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[9] /*|dump_value*/)), ((struct stackframe_stBM*)&_),    
 ( /*osbuf:*/_.o_6opEz55NyNu_3JKpBgxLijw),  ( /*odumper:*/_.o_3cTC8W7d75H_1vteOyEoAao),    
 ( ((value_tyBM)0x3 /*!1*/))));  
} // end run _4BOu5jhqyAD_3HGfVAY5hFx  
// while _9gJT0jotyox_8JQNlJn3qh6 comp#3:  
{ // start cexpansion _8TB4Kpuoc3f_0Dhb8Tm0xrJ - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*osbuf:*/_.o_6opEz55NyNu_3JKpBgxLijw), ( "\t"));   
} // end cexpansion _8TB4Kpuoc3f_0Dhb8Tm0xrJ - objstrbufferappendcstrpayl   
// while _9gJT0jotyox_8JQNlJn3qh6 comp#4:  
  
{ // run _634ecJogXve_7sycLMYAfdT  
(send3_BM (( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi), /*sel:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[9] /*|dump_value*/)), ((struct stackframe_stBM*)&_),    
 ( /*osbuf:*/_.o_6opEz55NyNu_3JKpBgxLijw),  ( /*odumper:*/_.o_3cTC8W7d75H_1vteOyEoAao),    
 ( ((value_tyBM)0x3 /*!1*/))));  
} // end run _634ecJogXve_7sycLMYAfdT  
// while _9gJT0jotyox_8JQNlJn3qh6 comp#5:  
{ // start cexpansion _3fFn9uY0hNS_2YU6fn9QOSh - objstrbuffernewlinepayl   
/*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*osbuf:*/_.o_6opEz55NyNu_3JKpBgxLijw);   
} // end cexpansion _3fFn9uY0hNS_2YU6fn9QOSh - objstrbuffernewlinepayl   
// while _9gJT0jotyox_8JQNlJn3qh6 comp#6:  
  
{ // run _1aLOinNfz2n_0WpWbC84CAL  
(send3_BM (( /*v_val:*/_.v_5jRQCD1qTko_61I0j04ugAA), /*sel:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[9] /*|dump_value*/)), ((struct stackframe_stBM*)&_),    
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
} // end _4qlegfkPzrC_17skUfJP7v8 routine#13 _4qlegfkPzrC_17skUfJP7v8




value_tyBM crout_4M7lr5cU6VD_5hxmeH3baBf_BM //#14
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[20] /*|_4M7lr5cU6VD_5hxmeH3baBf*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 2 arguments:
   _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0); // o1
   _.v_09RxU8xDco3_2Zxwfb13oDZ = arg1; // v2
   // fetched 2 arguments.
   // no closed values in _4M7lr5cU6VD_5hxmeH3baBf.
   const closure_tyBM* callclos_4M7lr5cU6VD_5hxmeH3baBf __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_4M7lr5cU6VD_5hxmeH3baBf  __attribute__((unused)) = 0;
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
} // end _4M7lr5cU6VD_5hxmeH3baBf routine#14 _4M7lr5cU6VD_5hxmeH3baBf




value_tyBM crout_5j8LpQULt1p_9oeOaqmfYYr_BM //#15
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[21] /*|_5j8LpQULt1p_9oeOaqmfYYr*/;
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
   const closure_tyBM* callclos_5j8LpQULt1p_9oeOaqmfYYr __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_5j8LpQULt1p_9oeOaqmfYYr  __attribute__((unused)) = 0;
   // routine _5j8LpQULt1p_9oeOaqmfYYr body:

startblock__9Hf4n8AnqR7_7ve3Bi3kWMV: __attribute__((unused));
{ /* +block _9Hf4n8AnqR7_7ve3Bi3kWMV */ 
 /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy = //assign _8ggHPTQI1iG_02hVE5KybEL  
/*objlisttonodepayl:*/ (value_tyBM) objlisttonodepayl_BM(( /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[25] /*|node*/))); 
 
 
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
(send3_BM ((/*nodenthson:*/nodenthson_BM(( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B))), /*sel:*/( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[9] /*|dump_value*/)), ((struct stackframe_stBM*)&_),    
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
} // end _5j8LpQULt1p_9oeOaqmfYYr routine#15 _5j8LpQULt1p_9oeOaqmfYYr




value_tyBM crout_7MtjMTkmErH_2zSJ1YDKHVi_BM //#16
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[26] /*|_7MtjMTkmErH_2zSJ1YDKHVi*/;
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
   const closure_tyBM* callclos_7MtjMTkmErH_2zSJ1YDKHVi __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_7MtjMTkmErH_2zSJ1YDKHVi  __attribute__((unused)) = 0;
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
} // end _7MtjMTkmErH_2zSJ1YDKHVi routine#16 _7MtjMTkmErH_2zSJ1YDKHVi




value_tyBM crout_82ho9wUUDji_4peMLha4PXl_BM //#17+
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[27] /*|findobj_scan_minifunc*/;
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
   const unsigned nbclosed_82ho9wUUDji_4peMLha4PXl = closurewidth_BM ((const value_tyBM) callclos_82ho9wUUDji_4peMLha4PXl);
   if (nbclosed_82ho9wUUDji_4peMLha4PXl > 0)
      _.o_4ITcQtvlMmO_30Pss9oAVDB = objectcast_BM (callclos_82ho9wUUDji_4peMLha4PXl->nodt_sons[0]); // o_findobj
   } // fetched 1 closed values in _82ho9wUUDji_4peMLha4PXl.
   // routine _82ho9wUUDji_4peMLha4PXl body:

startblock__6YnYKKsHo3f_9nIEOZMp744: __attribute__((unused));
{ /* +block _6YnYKKsHo3f_9nIEOZMp744 */ 
 
{ // run _7m9brpKxZkY_3BEI7YANJuJ 
/*begin findobj_scan_minifunc*/ WEAKASSERT_BM(objectisinstance_BM ( /*o_findobj:*/_.o_4ITcQtvlMmO_30Pss9oAVDB,  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[23] /*|findrun_object*/))); ; 
} // end run _7m9brpKxZkY_3BEI7YANJuJ 
 
/* !endingblock _6YnYKKsHo3f_9nIEOZMp744 */ 
goto endblock__6YnYKKsHo3f_9nIEOZMp744; 
endblock__6YnYKKsHo3f_9nIEOZMp744: ; 
} /*-block _6YnYKKsHo3f_9nIEOZMp744 */

 epilog_82ho9wUUDji_4peMLha4PXl: __attribute__ ((unused)); // routine _82ho9wUUDji_4peMLha4PXl epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _82ho9wUUDji_4peMLha4PXl routine#17 findobj_scan_minifunc




value_tyBM crout_8dG7KZHgf3t_4ia32mWZqVQ_BM //#18
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[28] /*|_8dG7KZHgf3t_4ia32mWZqVQ*/;
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
   const unsigned nbclosed_8dG7KZHgf3t_4ia32mWZqVQ = closurewidth_BM ((const value_tyBM) callclos_8dG7KZHgf3t_4ia32mWZqVQ);
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
 (/*equal_object:*/(( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81) == ( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[1] /*!in*/)))) { //body when _1j5eDZEaK15_1f7jqPaTIVw  
 /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx = //assign _0T7bvmg9y4B_6u9BnDCdOJK   
/*val_to_object:*/objectcast_BM(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0)));  
{ // start cexpansion _7lC3JY25pke_03Q6D8X9cOR - objresetattrs   
/*objresetattrs:*/ objresetattrs_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),(unsigned)( 4));   
} // end cexpansion _7lC3JY25pke_03Q6D8X9cOR - objresetattrs   
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
 (/*equal_object:*/(( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81) == ( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[17] /*!label*/)))) { //body when _8YCEgWraf8u_6RbayBBuUw2  
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
/*objputattr:*/objputattr_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[17] /*!label*/)),( /*o_curlab:*/_.o_79dADic8Iro_3skCK4hK3iW));   
} // end cexpansion _3wnQKoelMkT_4aZOgoixqhx - objputattr   
  
} //endwhen _3DdyhRUe9dE_16cDuNVvrHq  
/*endcond _63g2w1NiAWP_7xZNFD9DXFo*/ 
  
{ // start cexpansion _04Du9TPik7B_4c1jk59AMbA - objputattr  
/*objputattr:*/objputattr_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[22] /*!count*/)),( /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU));  
} // end cexpansion _04Du9TPik7B_4c1jk59AMbA - objputattr  
  
//+ #6/11 of lockobj _9Om1a31BzaS_5TkPLp6j4lV ::  
{ // start cexpansion _927qtIvWTqf_5RR3BZ5Ja2H - objputattr  
/*objputattr:*/objputattr_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[24] /*!index*/)),( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4));  
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
} // end _8dG7KZHgf3t_4ia32mWZqVQ routine#18 _8dG7KZHgf3t_4ia32mWZqVQ




value_tyBM crout_8imWClcIFKt_6w2H2ouB4I6_BM //#19+
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[29] /*|iterate_sequence_minifunc*/;
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
   const closure_tyBM* callclos_8imWClcIFKt_6w2H2ouB4I6 __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_8imWClcIFKt_6w2H2ouB4I6  __attribute__((unused)) = 0;
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
} // end _8imWClcIFKt_6w2H2ouB4I6 routine#19 iterate_sequence_minifunc




value_tyBM crout_9CG8SKNs6Ql_4PiHd8cnydn_BM //#20
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
   _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[32] /*|_9CG8SKNs6Ql_4PiHd8cnydn*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 1 arguments:
   _.o_7n2SLLuWOjH_4ArhFUjmckz = objectcast_BM (arg0); // odict
   // fetched 1 arguments.
   // no closed values in _9CG8SKNs6Ql_4PiHd8cnydn.
   const closure_tyBM* callclos_9CG8SKNs6Ql_4PiHd8cnydn __attribute__((unused)) =
     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
   const unsigned nbclosed_9CG8SKNs6Ql_4PiHd8cnydn  __attribute__((unused)) = 0;
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
} // end _9CG8SKNs6Ql_4PiHd8cnydn routine#20 _9CG8SKNs6Ql_4PiHd8cnydn




// end of 21 generated routines


// the constant ids for 34 constants:
const char* const constid_3BFt4NfJmZC_7iYi2dwM38B_BM[34+1] = {
 /*0:*/
 "_0cUdonky1bM_4IVhwlVRBMk", //! webhandler testhello minifunc
 "_0eMGYofuNVh_8ZP2mXdhtHO",//in
 "_0g1CBaxjMIB_7NZdyHUikLG", //! out#readmacro (v_node v_lineno v_colpos o_parser)
 "_0EmM9kH8Wgr_7fpd0oIo9xQ",//out
 "_0JktC4mAHCa_1KNr6uMIqIi", //! dump_scan°list_object minifunc for list_object o1 & dumperobj o2
 /*5:*/
 "_0SinERsgdvQ_57dLCP63i9r", //! forgetname#command_handler
 "_0YOXUe7rEJC_3jFMjOAQRs9",//element_of_closed_minifunc
 "_110awzb480c_0n4frovb2yV", //! dump_data°contributor_class<o_contrib (o_dumper o_strbuf)
 "_1dzZlwqKdLH_8HjkBsL9Mar",//add
 "_1FEnnpEkGdI_5DAcVDL5XHG",//dump_value
 /*10:*/
 "_22Zd68WPKUO_6AoIuBcbUb2", //! dump_scan°dict_object minifunc for dict-object odict and dumperobj odumper
 "_2bZ4BfCci5V_3WTzG7V25y4", //! put°dict_object minifunc
 "_2nl9zcaSUwe_8UBiMp1OuMk",//identity_minifunc
 "_3iiht57Wrs1_5NbiUi27oBn", //! prepend°list_object minifunc
 "_3yQlckX4DRh_4b9l9FBSSSL",//same_as_closed_minifunc
 /*15:*/
 "_3BFt4NfJmZC_7iYi2dwM38B",//first_misc_module
 "_3HAeZZQ0q7b_7qyDsekaz7Y", //! clear°list_object minifunc
 "_3XBrePAliOo_37VlAqBsb5C",//label
 "_4iEFTEcHxeb_6lH464uFkTC",//equal_to_closed_minifunc
 "_4qlegfkPzrC_17skUfJP7v8", //! dump_data°dict_object minifun
 /*20:*/
 "_4M7lr5cU6VD_5hxmeH3baBf", //! append°list_object minifunction
 "_5j8LpQULt1p_9oeOaqmfYYr", //! dump_data°list_object minifunc
 "_5OiKmAdUjY5_9BPLOECag6g",//count
 "_64UbCFBD19G_43TeBXhcYMy",//findrun_object
 "_6EG5W7z0BRb_4TBM1gyenqk",//index
 /*25:*/
 "_7D8xcWnEiys_8oqOVSkCxkA",//node
 "_7MtjMTkmErH_2zSJ1YDKHVi", //! dump_value°double_float < v_dbl (o_strbuf o_dump v_depth)
 "_82ho9wUUDji_4peMLha4PXl",//findobj_scan_minifunc
 "_8dG7KZHgf3t_4ia32mWZqVQ", //! for_loop#readmacro (v_node v_lineno v_colpos o_parser)
 "_8imWClcIFKt_6w2H2ouB4I6",//iterate_sequence_minifunc
 /*30:*/
 "_8lV53mLyu1H_3Z1SI8wDBK1",//clear
 "_9pvzBeIKHXF_8YDPCrQ6OEK",//put
 "_9CG8SKNs6Ql_4PiHd8cnydn", //! clear°dict_object minifun
 "_9LFIEAPDbzj_9zfBn99RgU4",//basiclo_outstmt
 NULL}; // end 34 constant ids



// the routine ids for 21 routines:
const char* const routid_3BFt4NfJmZC_7iYi2dwM38B_BM[21+1] = {
  /*0:*/
  "_0cUdonky1bM_4IVhwlVRBMk", //!webhandler testhello minifunc
  "_0g1CBaxjMIB_7NZdyHUikLG", //!out#readmacro (v_node v_lineno v_colpos o_parser)
  "_0JktC4mAHCa_1KNr6uMIqIi", //!dump_scan°list_object minifunc for list_object o1 & dumperobj o2
  "_0SinERsgdvQ_57dLCP63i9r", //!forgetname#command_handler
  "_0YOXUe7rEJC_3jFMjOAQRs9",//element_of_closed_minifunc
  "_110awzb480c_0n4frovb2yV", //!dump_data°contributor_class<o_contrib (o_dumper o_strbuf)
  "_22Zd68WPKUO_6AoIuBcbUb2", //!dump_scan°dict_object minifunc for dict-object odict and dumperobj odumper
  "_2bZ4BfCci5V_3WTzG7V25y4", //!put°dict_object minifunc;
  /*8:*/
  "_2nl9zcaSUwe_8UBiMp1OuMk",//identity_minifunc
  "_3iiht57Wrs1_5NbiUi27oBn", //!prepend°list_object minifunc
  "_3yQlckX4DRh_4b9l9FBSSSL",//same_as_closed_minifunc
  "_3HAeZZQ0q7b_7qyDsekaz7Y", //!clear°list_object minifunc
  "_4iEFTEcHxeb_6lH464uFkTC",//equal_to_closed_minifunc
  "_4qlegfkPzrC_17skUfJP7v8", //!dump_data°dict_object minifunc
  "_4M7lr5cU6VD_5hxmeH3baBf", //!append°list_object minifunction
  "_5j8LpQULt1p_9oeOaqmfYYr", //!dump_data°list_object minifunc;
  /*16:*/
  "_7MtjMTkmErH_2zSJ1YDKHVi", //!dump_value°double_float < v_dbl (o_strbuf o_dump v_depth)
  "_82ho9wUUDji_4peMLha4PXl",//findobj_scan_minifunc
  "_8dG7KZHgf3t_4ia32mWZqVQ", //!for_loop#readmacro (v_node v_lineno v_colpos o_parser)
  "_8imWClcIFKt_6w2H2ouB4I6",//iterate_sequence_minifunc
  "_9CG8SKNs6Ql_4PiHd8cnydn", //!clear°dict_object minifunc

 NULL}; // end 21 routine ids



// basiclo*module initialization
#ifdef BISMON_MODID
value_tyBM moduleinit_3BFt4NfJmZC_7iYi2dwM38B_BM
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
} // end moduleinit_3BFt4NfJmZC_7iYi2dwM38B_BM
#endif /*BISMON_MODID*/



/************
 ** for Emacs:
 ** Local Variables: ;;
 ** compile-command: "make -k -j -C .. modules" ;;
 ** End: ;;
 ************/



// end of generated persistent module first_misc_module in file modbm_3BFt4NfJmZC_7iYi2dwM38B.c
