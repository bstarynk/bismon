// generated module first_test_module in file modbm_9oXtCgAbkqv_4y1xhhF5Nhz.c

#include "bismon.h"



// declare 1 routines

extern objrout_sigBM crout_43Y25VLmh6s_3JRpERevcR4_BM;  // successor_test_minifunc


// declare 0 constants


// define 1 routines

value_tyBM
crout_43Y25VLmh6s_3JRpERevcR4_BM (struct stackframe_stBM *stkf, //+ successor_test_minifunc
                                  const value_tyBM arg0,        // v_i
                                  const value_tyBM arg1_
                                  __attribute__ ((unused)),
                                  const value_tyBM arg2_
                                  __attribute__ ((unused)),
                                  const value_tyBM arg3_
                                  __attribute__ ((unused)),
                                  const quasinode_tyBM * restargs_
                                  __attribute__ ((unused)))
{                               // start of successor_test_minifunc
  struct frame_43Y25VLmh6s_3JRpERevcR4_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    struct stackframe_stBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 2 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    value_tyBM v_3vRFuniDv1K_4bQ7DeekM2I;       // v_i
    /// 1 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
  } _;
  memset (&_, 0, sizeof (struct frame_43Y25VLmh6s_3JRpERevcR4_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 2;
  ASSERT_BM (!stkf
             || stkf->htyp == typayl_StackFrame_BM
             || stkf->htyp == typayl_SpecialFrame_BM) _.stkfram_prev = stkf;
  // fetch 1 arguments:
  _.v_3vRFuniDv1K_4bQ7DeekM2I = arg0;
  // fetched 1 arguments.
  // routine _43Y25VLmh6s_3JRpERevcR4 body:

startblock__7XasLoEUKwe_9upxyFeheD5:__attribute__ ((unused))
  {                             /* +block _7XasLoEUKwe_9upxyFeheD5 */
    if                          /*cond _1UM3ERNWFgo_6pqkY9UiIDv */
      /*when _5mfKaUSS5M3_7TkY2bYFtdL: */
      ( /*is_intv */ istaggedint_BM (v_3vRFuniDv1K_4bQ7DeekM2I))
      {
        n_2W7Ckt2WxEM_4NVYgEWE73B =     //assign _4BlNNkRvjfq_3MnqGoiP3nH   
          /* val_to_int */ getint_BM (v_3vRFuniDv1K_4bQ7DeekM2I);
        /*return _860kWTaFg9p_8Jhm1G5uvqC: */ v_3qw9bnATIhq_8loBraLeXzQ =
          // returned  
          /*taggedint: */
          taggedint_BM ( /*add_int: */ ((n_2W7Ckt2WxEM_4NVYgEWE73B) + (1)));
        goto epilog_43Y25VLmh6s_3JRpERevcR4;

      }                         //endwhen _5mfKaUSS5M3_7TkY2bYFtdL  
/*endcond _1UM3ERNWFgo_6pqkY9UiIDv*/

/* !endingblock _7XasLoEUKwe_9upxyFeheD5 */
    goto endblock__7XasLoEUKwe_9upxyFeheD5;
  endblock__7XasLoEUKwe_9upxyFeheD5:;
  }
  /*-block _7XasLoEUKwe_9upxyFeheD5 */

epilog_43Y25VLmh6s_3JRpERevcR4:        // routine _43Y25VLmh6s_3JRpERevcR4 epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _43Y25VLmh6s_3JRpERevcR4



// end of 1 generated routines


// end of generated module first_test_module in file modbm_9oXtCgAbkqv_4y1xhhF5Nhz.c
