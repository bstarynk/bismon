// generated module first_test_module in file modbm_9oXtCgAbkqv_4y1xhhF5Nhz.c


#include "bismon.h"

#ifdef BISMON_MODID
DECLARE_MODULE_BM(_9oXtCgAbkqv_4y1xhhF5Nhz);
extern moduleinit_sigBM modulinit_9oXtCgAbkqv_4y1xhhF5Nhz_BM;
#endif /*BISMON_MODID*/



// declare 2 routines

extern const char *const routid_9oXtCgAbkqv_4y1xhhF5Nhz_BM[2+1];

extern objrout_sigBM crout_43Y25VLmh6s_3JRpERevcR4_BM; //#0 successor_test_minifunc

extern objrout_sigBM crout_9O2lgu1TweO_0mVlpTwrBG1_BM; //#1 second_test_minifunc


// declare 5 constants
objectval_tyBM* constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM[5+1];
const char* const constid_9oXtCgAbkqv_4y1xhhF5Nhz_BM[5+1];


// define 2 routines


value_tyBM crout_43Y25VLmh6s_3JRpERevcR4_BM
 (struct stackframe_stBM* stkf, //#0+ successor_test_minifunc
  const value_tyBM arg0,  // v_i
  const value_tyBM arg1_ __attribute__((unused)),
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of successor_test_minifunc
  struct frame_43Y25VLmh6s_3JRpERevcR4_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 2 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    value_tyBM v_3vRFuniDv1K_4bQ7DeekM2I; // v_i
    /// 1 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
   } _;
   memset (&_, 0, sizeof(struct frame_43Y25VLmh6s_3JRpERevcR4_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 2;
   _.stkfram_descr = constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM[1] /*|successor_test_minifunc*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 1 arguments:
   _.v_3vRFuniDv1K_4bQ7DeekM2I = arg0;
   // fetched 1 arguments.
   // routine _43Y25VLmh6s_3JRpERevcR4 body:

startblock__7XasLoEUKwe_9upxyFeheD5: __attribute__((unused))
{ /* +block _7XasLoEUKwe_9upxyFeheD5 */ 
if /*cond _1UM3ERNWFgo_6pqkY9UiIDv*/  
/*when _5mfKaUSS5M3_7TkY2bYFtdL:*/ (/*is_intv*/ istaggedint_BM (  _.v_3vRFuniDv1K_4bQ7DeekM2I )) {  
 _.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _4BlNNkRvjfq_3MnqGoiP3nH   
 /* val_to_int */ getint_BM( _.v_3vRFuniDv1K_4bQ7DeekM2I) ;  
/*return _860kWTaFg9p_8Jhm1G5uvqC:*/  _.v_3qw9bnATIhq_8loBraLeXzQ = // returned  
/*taggedint:*/ taggedint_BM (/*add_int:*/(( _.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1)));  
 goto epilog_43Y25VLmh6s_3JRpERevcR4;  
  
} //endwhen _5mfKaUSS5M3_7TkY2bYFtdL  
/*endcond _1UM3ERNWFgo_6pqkY9UiIDv*/ 
 
/* !endingblock _7XasLoEUKwe_9upxyFeheD5 */ 
goto endblock__7XasLoEUKwe_9upxyFeheD5; 
endblock__7XasLoEUKwe_9upxyFeheD5: ; 
} /*-block _7XasLoEUKwe_9upxyFeheD5 */

 epilog_43Y25VLmh6s_3JRpERevcR4: // routine _43Y25VLmh6s_3JRpERevcR4 epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  _.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _43Y25VLmh6s_3JRpERevcR4 routine#0 successor_test_minifunc




value_tyBM crout_9O2lgu1TweO_0mVlpTwrBG1_BM
 (struct stackframe_stBM* stkf, //#1+ second_test_minifunc
  const value_tyBM arg0,  // v1
  const value_tyBM arg1_ __attribute__((unused)),
  const value_tyBM arg2_ __attribute__((unused)),
  const value_tyBM arg3_ __attribute__((unused)),
  const quasinode_tyBM * restargs_ __attribute__((unused)))
{ // start of second_test_minifunc
  struct frame_9O2lgu1TweO_0mVlpTwrBG1_BMst {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 2 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
    value_tyBM v_5EEITf6IFH7_4DbKG99zcPW; // v1
    /// 0 local numbers:
   } _;
   memset (&_, 0, sizeof(struct frame_9O2lgu1TweO_0mVlpTwrBG1_BMst));
   _.stkfram_head.htyp = typayl_StackFrame_BM;
   _.stkfram_head.hgc = 0;
   _.stkfram_head.rlen = 2;
   _.stkfram_descr = constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM[4] /*|second_test_minifunc*/;
   ASSERT_BM (!stkf
             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
   _.stkfram_prev = stkf;
   // fetch 1 arguments:
   _.v_5EEITf6IFH7_4DbKG99zcPW = arg0;
   // fetched 1 arguments.
   // routine _9O2lgu1TweO_0mVlpTwrBG1 body:

startblock__8yXqsN7LuB3_0vODsT2M9Lh: __attribute__((unused))
{ /* +block _8yXqsN7LuB3_0vODsT2M9Lh */ 
if /*cond _1rIoTXPOfGY_2AFqgfS5G7T*/  
/*when _2rCc2usyvqv_1TUCxOmrdFs:*/ (/*is_intv*/ istaggedint_BM (  _.v_5EEITf6IFH7_4DbKG99zcPW )) {  
/*return _3g94RQiswhV_2O5raZogJao:*/  _.v_3qw9bnATIhq_8loBraLeXzQ = // returned  
 (constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM[0] /*!int*/);  
 goto epilog_9O2lgu1TweO_0mVlpTwrBG1;  
  
} //endwhen _2rCc2usyvqv_1TUCxOmrdFs  
else if  
/*when _8ICBYlvMuJw_9rv1czcQPGI:*/ (/*is_objectv*/ isobject_BM( _.v_5EEITf6IFH7_4DbKG99zcPW)) {  
/*return _4NQMyG7YDk8_44PdNNG87Sr:*/  _.v_3qw9bnATIhq_8loBraLeXzQ = // returned  
 (constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM[3] /*!object*/);  
 goto epilog_9O2lgu1TweO_0mVlpTwrBG1;  
  
} //endwhen _8ICBYlvMuJw_9rv1czcQPGI  
else { /*cond else _1rIoTXPOfGY_2AFqgfS5G7T*/  
/*return _6NBwHeONub1_23PSzwWuTsb:*/  _.v_3qw9bnATIhq_8loBraLeXzQ = // returned 
 (constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM[2] /*!value*/); 
 goto epilog_9O2lgu1TweO_0mVlpTwrBG1; 
} /*cond else _1rIoTXPOfGY_2AFqgfS5G7T*/  
/*endcond _1rIoTXPOfGY_2AFqgfS5G7T*/ 
 
/* !endingblock _8yXqsN7LuB3_0vODsT2M9Lh */ 
goto endblock__8yXqsN7LuB3_0vODsT2M9Lh; 
endblock__8yXqsN7LuB3_0vODsT2M9Lh: ; 
} /*-block _8yXqsN7LuB3_0vODsT2M9Lh */

 epilog_9O2lgu1TweO_0mVlpTwrBG1: // routine _9O2lgu1TweO_0mVlpTwrBG1 epilogue:
   if (stkf) stkf->stkfram_callfun = NULL;
   return  _.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _9O2lgu1TweO_0mVlpTwrBG1 routine#1 second_test_minifunc




// end of 2 generated routines


// the constant ids for 5 constants:
const char* const constid_9oXtCgAbkqv_4y1xhhF5Nhz_BM[5+1] = {
 /*0:*/
 "_0vgCFjXblkx_4zCMhMAWjVK",//int
 "_43Y25VLmh6s_3JRpERevcR4",//successor_test_minifunc
 "_7bbeIqUSje9_4jVgC7ZJmvx",//value
 "_7T9OwSFlgov_0wVJaK1eZbn",//object
 "_9O2lgu1TweO_0mVlpTwrBG1",//second_test_minifunc
 NULL}; // end 5 constant ids



// the routine ids for 2 routines:
const char* const routid_9oXtCgAbkqv_4y1xhhF5Nhz_BM[2+1] = {
  /*0:*/
  "_43Y25VLmh6s_3JRpERevcR4",//successor_test_minifunc
  "_9O2lgu1TweO_0mVlpTwrBG1",//second_test_minifunc

 NULL}; // end 2 routine ids



// basiclo*module initialization
#ifdef BISMON_MODID
void modulinit_9oXtCgAbkqv_4y1xhhF5Nhz_BM
  (struct stackframe_stBM *stkf, //
   const value_tyBM arg1, //
   const value_tyBM arg2, //
   const value_tyBM arg3, //
   void* dlh) {
   simple_module_initialize_BM(arg1, arg2, arg3, "_9oXtCgAbkqv_4y1xhhF5Nhz",//
       constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM, //
       constid_9oXtCgAbkqv_4y1xhhF5Nhz_BM, //
       routid_9oXtCgAbkqv_4y1xhhF5Nhz_BM, //
       dlh, stkf);
} // end modulinit_9oXtCgAbkqv_4y1xhhF5Nhz_BM
#endif /*BISMON_MODID*/



// end of generated module first_test_module in file modbm_9oXtCgAbkqv_4y1xhhF5Nhz.c
