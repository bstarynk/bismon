// generated module erroneous_test_module in file modbm_9kQRAaOWJ97_99Im2N6Lv0O.c


#include "bismon.h"

#ifdef BISMON_MODID
DECLARE_MODULE_BM (_9kQRAaOWJ97_99Im2N6Lv0O);
extern moduleinit_sigBM modulinit_9kQRAaOWJ97_99Im2N6Lv0O_BM;
#endif /*BISMON_MODID */



// declare 1 routines

extern const char *const routid_9kQRAaOWJ97_99Im2N6Lv0O_BM[1 + 1];

extern objrout_sigBM crout_2nl9zcaSUwe_8UBiMp1OuMk_BM;  //#0 identity_minifunc


// declare 1 constants
objectval_tyBM *constob_9kQRAaOWJ97_99Im2N6Lv0O_BM[1 + 1];
const char *const constid_9kQRAaOWJ97_99Im2N6Lv0O_BM[1 + 1];


// define 1 routines


value_tyBM crout_2nl9zcaSUwe_8UBiMp1OuMk_BM     //#0+
  (struct stackframe_stBM *stkf,        // identity_minifunc
   // 1 arguments
   const value_tyBM arg0,       // v_i
   const value_tyBM arg1_ __attribute__ ((unused)),
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of identity_minifunc
  struct frame_2nl9zcaSUwe_8UBiMp1OuMk_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 2 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    value_tyBM v_3vRFuniDv1K_4bQ7DeekM2I;       // v_i
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_2nl9zcaSUwe_8UBiMp1OuMk_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 2;
  _.stkfram_descr =
    constob_9kQRAaOWJ97_99Im2N6Lv0O_BM[0] /*|identity_minifunc */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 1 arguments:
  _.v_3vRFuniDv1K_4bQ7DeekM2I = arg0;
  // fetched 1 arguments.
  // routine _2nl9zcaSUwe_8UBiMp1OuMk body:

startblock__0CsCkIkpNX6_52gRCYPcnW2:__attribute__ ((unused))
  {                             /* +block _0CsCkIkpNX6_52gRCYPcnW2 */
    /*return _01p2tksvq9A_1b8os2WLues: */ _.v_3qw9bnATIhq_8loBraLeXzQ =
      // returned 
      _.v_3vRFuniDv1K_4bQ7DeekM2I;
    goto epilog_2nl9zcaSUwe_8UBiMp1OuMk;

/* !endingblock _0CsCkIkpNX6_52gRCYPcnW2 */
    goto endblock__0CsCkIkpNX6_52gRCYPcnW2;
  endblock__0CsCkIkpNX6_52gRCYPcnW2:;
  }
  /*-block _0CsCkIkpNX6_52gRCYPcnW2 */

epilog_2nl9zcaSUwe_8UBiMp1OuMk:        // routine _2nl9zcaSUwe_8UBiMp1OuMk epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _2nl9zcaSUwe_8UBiMp1OuMk routine#0 identity_minifunc




// end of 1 generated routines


// the constant ids for 1 constants:
const char *const constid_9kQRAaOWJ97_99Im2N6Lv0O_BM[1 + 1] = {
  /*0: */
  "_2nl9zcaSUwe_8UBiMp1OuMk",   //identity_minifunc
  NULL
};                              // end 1 constant ids



// the routine ids for 1 routines:
const char *const routid_9kQRAaOWJ97_99Im2N6Lv0O_BM[1 + 1] = {
  /*0: */
  "_2nl9zcaSUwe_8UBiMp1OuMk",   //identity_minifunc

  NULL
};                              // end 1 routine ids



// basiclo*module initialization
#ifdef BISMON_MODID
value_tyBM
modulinit_9kQRAaOWJ97_99Im2N6Lv0O_BM (struct stackframe_stBM *stkf,     //
                                      const value_tyBM arg1,    //
                                      const value_tyBM arg2,    //
                                      const value_tyBM arg3,    //
                                      void *dlh)
{
  return simple_module_initialize_BM (arg1, arg2, arg3, //
                                      "_9kQRAaOWJ97_99Im2N6Lv0O",       //
                                      constob_9kQRAaOWJ97_99Im2N6Lv0O_BM,       //
                                      constid_9kQRAaOWJ97_99Im2N6Lv0O_BM,       //
                                      routid_9kQRAaOWJ97_99Im2N6Lv0O_BM,        //
                                      dlh, stkf);
}                               // end modulinit_9kQRAaOWJ97_99Im2N6Lv0O_BM
#endif /*BISMON_MODID */



// end of generated module erroneous_test_module in file modbm_9kQRAaOWJ97_99Im2N6Lv0O.c
