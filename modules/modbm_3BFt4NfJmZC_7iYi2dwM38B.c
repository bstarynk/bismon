// generated persistent module first_misc_module
// in file modbm_3BFt4NfJmZC_7iYi2dwM38B.c -- DONT EDIT
// this generated code is GPLv3+ licensed.


#include "bismon.h"

#ifdef BISMON_MODID
DECLARE_MODULE_BM (_3BFt4NfJmZC_7iYi2dwM38B);
extern moduleinit_sigBM modulinit_3BFt4NfJmZC_7iYi2dwM38B_BM;
#endif /*BISMON_MODID */



// declare 5 routines

extern const char *const routid_3BFt4NfJmZC_7iYi2dwM38B_BM[5 + 1];

extern objrout_sigBM crout_0YOXUe7rEJC_3jFMjOAQRs9_BM;  //#0 element_of_closed_minifunc

extern objrout_sigBM crout_3yQlckX4DRh_4b9l9FBSSSL_BM;  //#1 same_as_closed_minifunc

extern objrout_sigBM crout_4iEFTEcHxeb_6lH464uFkTC_BM;  //#2 equal_to_closed_minifunc

extern objrout_sigBM crout_82ho9wUUDji_4peMLha4PXl_BM;  //#3 findobj_scan_minifunc

extern objrout_sigBM crout_8imWClcIFKt_6w2H2ouB4I6_BM;  //#4 iterate_sequence_minifunc


// declare 6 constants
objectval_tyBM *constob_3BFt4NfJmZC_7iYi2dwM38B_BM[6 + 1];
const char *const constid_3BFt4NfJmZC_7iYi2dwM38B_BM[6 + 1];


// define 5 routines


value_tyBM crout_0YOXUe7rEJC_3jFMjOAQRs9_BM     //#0+
  (struct stackframe_stBM *stkf,        // element_of_closed_minifunc
   // 1 arguments
   const value_tyBM arg0,       // v_arg
   const value_tyBM arg1_ __attribute__ ((unused)),
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of element_of_closed_minifunc
  struct frame_0YOXUe7rEJC_3jFMjOAQRs9_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 4 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    value_tyBM v_4Q4WBLjAPTV_5WVLmhAvCJY;       // v_arg
    value_tyBM v_5EEITf6IFH7_4DbKG99zcPW;       // v1
    objectval_tyBM *o_97rnxb0KFqq_44veN75DG2E;  // o1
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_0YOXUe7rEJC_3jFMjOAQRs9_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 4;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[0] /*|element_of_closed_minifunc */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 1 arguments:
  _.v_4Q4WBLjAPTV_5WVLmhAvCJY = arg0;
  // fetched 1 arguments.
  {                             // fetch 1 closed values in element_of_closed_minifunc:
    const closure_tyBM *callclos_0YOXUe7rEJC_3jFMjOAQRs9 =
      (stkf && stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
      ? (closurecast_BM (stkf->stkfram_callfun)) : NULL;
    unsigned nbclosed_0YOXUe7rEJC_3jFMjOAQRs9 =
      closurewidth_BM ((const value_tyBM) callclos_0YOXUe7rEJC_3jFMjOAQRs9);
    if (nbclosed_0YOXUe7rEJC_3jFMjOAQRs9 > 0)
      _.v_5EEITf6IFH7_4DbKG99zcPW =
        callclos_0YOXUe7rEJC_3jFMjOAQRs9->nodt_sons[0];
  }                             // fetched 1 closed values in _0YOXUe7rEJC_3jFMjOAQRs9.
  // routine _0YOXUe7rEJC_3jFMjOAQRs9 body:

startblock__7gnMvoTqaQY_3kAwj2rwZEM:__attribute__ ((unused));
  {                             /* +block _7gnMvoTqaQY_3kAwj2rwZEM */
    _.o_97rnxb0KFqq_44veN75DG2E =       //assign _11EvX29IHDi_1da6fY8nL7Y  
/*val_to_object:*/ objectcast_BM (_.v_4Q4WBLjAPTV_5WVLmhAvCJY);


    if                          /*cond _0WAyTs536mS_7eZ58PLoYjP */
      /*when _2U8EKCOdizu_8BNXvpmwd43: */
      ((                        /*set_contains: */
         setcontains_BM ((_.v_5EEITf6IFH7_4DbKG99zcPW),
                         (_.o_97rnxb0KFqq_44veN75DG2E))))
      {
        /*return _4rFgWAf3aqA_0UBP8b4hESV: */ _.v_3qw9bnATIhq_8loBraLeXzQ =
          // returned  
          _.o_97rnxb0KFqq_44veN75DG2E;
        goto epilog_0YOXUe7rEJC_3jFMjOAQRs9;

      }                         //endwhen _2U8EKCOdizu_8BNXvpmwd43  
/*endcond _0WAyTs536mS_7eZ58PLoYjP*/

/* !endingblock _7gnMvoTqaQY_3kAwj2rwZEM */
    goto endblock__7gnMvoTqaQY_3kAwj2rwZEM;
  endblock__7gnMvoTqaQY_3kAwj2rwZEM:;
  }
  /*-block _7gnMvoTqaQY_3kAwj2rwZEM */

epilog_0YOXUe7rEJC_3jFMjOAQRs9:__attribute__ ((unused));
  // routine _0YOXUe7rEJC_3jFMjOAQRs9 epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _0YOXUe7rEJC_3jFMjOAQRs9 routine#0 element_of_closed_minifunc




value_tyBM crout_3yQlckX4DRh_4b9l9FBSSSL_BM     //#1+
  (struct stackframe_stBM * stkf,       // same_as_closed_minifunc
   // 1 arguments
   const value_tyBM arg0,       // v_arg
   const value_tyBM arg1_ __attribute__ ((unused)),
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of same_as_closed_minifunc
  struct frame_3yQlckX4DRh_4b9l9FBSSSL_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 3 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    value_tyBM v_4Q4WBLjAPTV_5WVLmhAvCJY;       // v_arg
    value_tyBM v_5EEITf6IFH7_4DbKG99zcPW;       // v1
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_3yQlckX4DRh_4b9l9FBSSSL_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 3;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[1] /*|same_as_closed_minifunc */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 1 arguments:
  _.v_4Q4WBLjAPTV_5WVLmhAvCJY = arg0;
  // fetched 1 arguments.
  {                             // fetch 1 closed values in same_as_closed_minifunc:
    const closure_tyBM *callclos_3yQlckX4DRh_4b9l9FBSSSL =
      (stkf && stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
      ? (closurecast_BM (stkf->stkfram_callfun)) : NULL;
    unsigned nbclosed_3yQlckX4DRh_4b9l9FBSSSL =
      closurewidth_BM ((const value_tyBM) callclos_3yQlckX4DRh_4b9l9FBSSSL);
    if (nbclosed_3yQlckX4DRh_4b9l9FBSSSL > 0)
      _.v_5EEITf6IFH7_4DbKG99zcPW =
        callclos_3yQlckX4DRh_4b9l9FBSSSL->nodt_sons[0];
  }                             // fetched 1 closed values in _3yQlckX4DRh_4b9l9FBSSSL.
  // routine _3yQlckX4DRh_4b9l9FBSSSL body:

startblock__8seRhfNtGTR_4rOgARd0hVM:__attribute__ ((unused));
  {                             /* +block _8seRhfNtGTR_4rOgARd0hVM */
    if                          /*cond _8aGb7reuzLX_3sgkigRSOpu */
      /*when _5Ad0ZdurQuC_1A6Kn7qopbm: */
      ((                        /*same_val: */
         (_.v_5EEITf6IFH7_4DbKG99zcPW) == (_.v_4Q4WBLjAPTV_5WVLmhAvCJY)))
      {
        /*return _1qFf9AUO2W9_8azcQljqB3I: */ _.v_3qw9bnATIhq_8loBraLeXzQ =
          // returned  
          _.v_4Q4WBLjAPTV_5WVLmhAvCJY;
        goto epilog_3yQlckX4DRh_4b9l9FBSSSL;

      }                         //endwhen _5Ad0ZdurQuC_1A6Kn7qopbm  
/*endcond _8aGb7reuzLX_3sgkigRSOpu*/

/* !endingblock _8seRhfNtGTR_4rOgARd0hVM */
    goto endblock__8seRhfNtGTR_4rOgARd0hVM;
  endblock__8seRhfNtGTR_4rOgARd0hVM:;
  }
  /*-block _8seRhfNtGTR_4rOgARd0hVM */

epilog_3yQlckX4DRh_4b9l9FBSSSL:__attribute__ ((unused));
  // routine _3yQlckX4DRh_4b9l9FBSSSL epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _3yQlckX4DRh_4b9l9FBSSSL routine#1 same_as_closed_minifunc




value_tyBM crout_4iEFTEcHxeb_6lH464uFkTC_BM     //#2+
  (struct stackframe_stBM * stkf,       // equal_to_closed_minifunc
   // 1 arguments
   const value_tyBM arg0,       // v_arg
   const value_tyBM arg1_ __attribute__ ((unused)),
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of equal_to_closed_minifunc
  struct frame_4iEFTEcHxeb_6lH464uFkTC_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 3 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    value_tyBM v_4Q4WBLjAPTV_5WVLmhAvCJY;       // v_arg
    value_tyBM v_5EEITf6IFH7_4DbKG99zcPW;       // v1
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_4iEFTEcHxeb_6lH464uFkTC_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 3;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[2] /*|equal_to_closed_minifunc */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 1 arguments:
  _.v_4Q4WBLjAPTV_5WVLmhAvCJY = arg0;
  // fetched 1 arguments.
  {                             // fetch 1 closed values in equal_to_closed_minifunc:
    const closure_tyBM *callclos_4iEFTEcHxeb_6lH464uFkTC =
      (stkf && stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
      ? (closurecast_BM (stkf->stkfram_callfun)) : NULL;
    unsigned nbclosed_4iEFTEcHxeb_6lH464uFkTC =
      closurewidth_BM ((const value_tyBM) callclos_4iEFTEcHxeb_6lH464uFkTC);
    if (nbclosed_4iEFTEcHxeb_6lH464uFkTC > 0)
      _.v_5EEITf6IFH7_4DbKG99zcPW =
        callclos_4iEFTEcHxeb_6lH464uFkTC->nodt_sons[0];
  }                             // fetched 1 closed values in _4iEFTEcHxeb_6lH464uFkTC.
  // routine _4iEFTEcHxeb_6lH464uFkTC body:

startblock__60FKeHfNUo3_9OSN4Cqm8zI:__attribute__ ((unused));
  {                             /* +block _60FKeHfNUo3_9OSN4Cqm8zI */
    if                          /*cond _7wPbopKi9ZB_1ifk5LEKSqu */
      /*when _8hUpJbSLQUS_88aqogJAi2Q: */
      ((                        /*equal_val: */
         valequal_BM ((_.v_5EEITf6IFH7_4DbKG99zcPW),
                      (_.v_4Q4WBLjAPTV_5WVLmhAvCJY))))
      {
        /*return _3dJ2b1hmBuw_7Pu5iDjauLr: */ _.v_3qw9bnATIhq_8loBraLeXzQ =
          // returned  
          _.v_5EEITf6IFH7_4DbKG99zcPW;
        goto epilog_4iEFTEcHxeb_6lH464uFkTC;

      }                         //endwhen _8hUpJbSLQUS_88aqogJAi2Q  
/*endcond _7wPbopKi9ZB_1ifk5LEKSqu*/

/* !endingblock _60FKeHfNUo3_9OSN4Cqm8zI */
    goto endblock__60FKeHfNUo3_9OSN4Cqm8zI;
  endblock__60FKeHfNUo3_9OSN4Cqm8zI:;
  }
  /*-block _60FKeHfNUo3_9OSN4Cqm8zI */

epilog_4iEFTEcHxeb_6lH464uFkTC:__attribute__ ((unused));
  // routine _4iEFTEcHxeb_6lH464uFkTC epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _4iEFTEcHxeb_6lH464uFkTC routine#2 equal_to_closed_minifunc




value_tyBM crout_82ho9wUUDji_4peMLha4PXl_BM     //#3+
  (struct stackframe_stBM * stkf,       // findobj_scan_minifunc
   // 1 arguments
   const value_tyBM arg0,       // o_scan
   const value_tyBM arg1_ __attribute__ ((unused)),
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of findobj_scan_minifunc
  struct frame_82ho9wUUDji_4peMLha4PXl_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 4 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    objectval_tyBM *o_4gykCX1QdLb_9Aooqa2FWTq;  // o_scan
    objectval_tyBM *o_4ITcQtvlMmO_30Pss9oAVDB;  // o_findobj
    objectval_tyBM *o_6Jkz6rphVkn_1KZto79j46r;  // o_vihset
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_82ho9wUUDji_4peMLha4PXl_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 4;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[4] /*|findobj_scan_minifunc */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 1 arguments:
  _.o_4gykCX1QdLb_9Aooqa2FWTq = objectcast_BM (arg0);
  // fetched 1 arguments.
  {                             // fetch 1 closed values in findobj_scan_minifunc:
    const closure_tyBM *callclos_82ho9wUUDji_4peMLha4PXl =
      (stkf && stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
      ? (closurecast_BM (stkf->stkfram_callfun)) : NULL;
    unsigned nbclosed_82ho9wUUDji_4peMLha4PXl =
      closurewidth_BM ((const value_tyBM) callclos_82ho9wUUDji_4peMLha4PXl);
    if (nbclosed_82ho9wUUDji_4peMLha4PXl > 0)
      _.o_4ITcQtvlMmO_30Pss9oAVDB =
        objectcast_BM (callclos_82ho9wUUDji_4peMLha4PXl->nodt_sons[0]);
  }                             // fetched 1 closed values in _82ho9wUUDji_4peMLha4PXl.
  // routine _82ho9wUUDji_4peMLha4PXl body:

startblock__6YnYKKsHo3f_9nIEOZMp744:__attribute__ ((unused));
  {                             /* +block _6YnYKKsHo3f_9nIEOZMp744 */

    {                           // run _7m9brpKxZkY_3BEI7YANJuJ 
      /*begin findobj_scan_minifunc */
      WEAKASSERT_BM (objectisinstance_BM
                     (_.o_4ITcQtvlMmO_30Pss9oAVDB,
                      (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[3]
                       /*|findrun_object */ )));;
    }                           // end run _7m9brpKxZkY_3BEI7YANJuJ 

/* !endingblock _6YnYKKsHo3f_9nIEOZMp744 */
    goto endblock__6YnYKKsHo3f_9nIEOZMp744;
  endblock__6YnYKKsHo3f_9nIEOZMp744:;
  }
  /*-block _6YnYKKsHo3f_9nIEOZMp744 */

epilog_82ho9wUUDji_4peMLha4PXl:__attribute__ ((unused));
  // routine _82ho9wUUDji_4peMLha4PXl epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _82ho9wUUDji_4peMLha4PXl routine#3 findobj_scan_minifunc




value_tyBM crout_8imWClcIFKt_6w2H2ouB4I6_BM     //#4+
  (struct stackframe_stBM * stkf,       // iterate_sequence_minifunc
   // 3 arguments
   const value_tyBM arg0,       // v_seq
   const value_tyBM arg1,       // v_fun
   const value_tyBM arg2,       // v_arg
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of iterate_sequence_minifunc
  struct frame_8imWClcIFKt_6w2H2ouB4I6_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 4 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    value_tyBM v_4Q4WBLjAPTV_5WVLmhAvCJY;       // v_arg
    value_tyBM v_8jKgolslEuE_4dxzrK5R2B4;       // v_fun
    value_tyBM v_9vc0quxdnhj_3zLw1MEwl1e;       // v_seq
    /// 2 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
  } _;
  memset (&_, 0, sizeof (struct frame_8imWClcIFKt_6w2H2ouB4I6_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 4;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[5] /*|iterate_sequence_minifunc */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 3 arguments:
  _.v_9vc0quxdnhj_3zLw1MEwl1e = arg0;
  _.v_8jKgolslEuE_4dxzrK5R2B4 = arg1;
  _.v_4Q4WBLjAPTV_5WVLmhAvCJY = arg2;
  // fetched 3 arguments.
  // no closed values in iterate_sequence_minifunc.
  // routine _8imWClcIFKt_6w2H2ouB4I6 body:

startblock__2W6NObLb2d4_6OfkP3dYlF3:__attribute__ ((unused));
  {                             /* +block _2W6NObLb2d4_6OfkP3dYlF3 */
    _.n_833x2jYqhZh_8vDIuJhwz1k =       //assign _3EakP4EXPLZ_10btDL0iqAt  
/*seqlength*/ sequencesize_BM (_.v_9vc0quxdnhj_3zLw1MEwl1e);


    _.n_2W7Ckt2WxEM_4NVYgEWE73B =       //assign _1Z2mN7VIEbD_4RJunrL2QcV  
      0;



  startblock__3vvVJBONOyK_3kn86nuYwr1:__attribute__ ((unused));
    {                           /* +loop _3vvVJBONOyK_3kn86nuYwr1 */
    startloop__3vvVJBONOyK_3kn86nuYwr1:__attribute__ ((unused));


      if                        /*cond _7pBaII8qZHM_8xoaIKeilBk */
        /*when _8qsLnTz2QdD_9nZub2hBMEb: */
        ((                      /*greaterequal_int: */
           (_.n_2W7Ckt2WxEM_4NVYgEWE73B) >= (_.n_833x2jYqhZh_8vDIuJhwz1k)))
        {
// exit _9dmQwUU17M1_1km5cSGzJly   
          goto endblock__3vvVJBONOyK_3kn86nuYwr1;

        }                       //endwhen _8qsLnTz2QdD_9nZub2hBMEb   
/*endcond _7pBaII8qZHM_8xoaIKeilBk*/



/* !endingloop _3vvVJBONOyK_3kn86nuYwr1 */
      goto startloop__3vvVJBONOyK_3kn86nuYwr1;
    endblock__3vvVJBONOyK_3kn86nuYwr1:__attribute__ ((unused));
    }
  /*-loop _3vvVJBONOyK_3kn86nuYwr1 */
/* !endingblock _2W6NObLb2d4_6OfkP3dYlF3 */
    goto endblock__2W6NObLb2d4_6OfkP3dYlF3;
  endblock__2W6NObLb2d4_6OfkP3dYlF3:;
  }
  /*-block _2W6NObLb2d4_6OfkP3dYlF3 */

epilog_8imWClcIFKt_6w2H2ouB4I6:__attribute__ ((unused));
  // routine _8imWClcIFKt_6w2H2ouB4I6 epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _8imWClcIFKt_6w2H2ouB4I6 routine#4 iterate_sequence_minifunc




// end of 5 generated routines


// the constant ids for 6 constants:
const char *const constid_3BFt4NfJmZC_7iYi2dwM38B_BM[6 + 1] = {
  /*0: */
  "_0YOXUe7rEJC_3jFMjOAQRs9",   //element_of_closed_minifunc
  "_3yQlckX4DRh_4b9l9FBSSSL",   //same_as_closed_minifunc
  "_4iEFTEcHxeb_6lH464uFkTC",   //equal_to_closed_minifunc
  "_64UbCFBD19G_43TeBXhcYMy",   //findrun_object
  "_82ho9wUUDji_4peMLha4PXl",   //findobj_scan_minifunc
  "_8imWClcIFKt_6w2H2ouB4I6",   //iterate_sequence_minifunc
  NULL
};                              // end 6 constant ids



// the routine ids for 5 routines:
const char *const routid_3BFt4NfJmZC_7iYi2dwM38B_BM[5 + 1] = {
  /*0: */
  "_0YOXUe7rEJC_3jFMjOAQRs9",   //element_of_closed_minifunc
  "_3yQlckX4DRh_4b9l9FBSSSL",   //same_as_closed_minifunc
  "_4iEFTEcHxeb_6lH464uFkTC",   //equal_to_closed_minifunc
  "_82ho9wUUDji_4peMLha4PXl",   //findobj_scan_minifunc
  "_8imWClcIFKt_6w2H2ouB4I6",   //iterate_sequence_minifunc

  NULL
};                              // end 5 routine ids



// basiclo*module initialization
#ifdef BISMON_MODID
value_tyBM
modulinit_3BFt4NfJmZC_7iYi2dwM38B_BM (struct stackframe_stBM *stkf,     //
                                      const value_tyBM arg1,    //
                                      const value_tyBM arg2,    //
                                      const value_tyBM arg3,    //
                                      void *dlh)
{
  return simple_module_initialize_BM (arg1, arg2, arg3, //
                                      "_3BFt4NfJmZC_7iYi2dwM38B",       //
                                      constob_3BFt4NfJmZC_7iYi2dwM38B_BM,       //
                                      constid_3BFt4NfJmZC_7iYi2dwM38B_BM,       //
                                      routid_3BFt4NfJmZC_7iYi2dwM38B_BM,        //
                                      dlh, stkf);
}                               // end modulinit_3BFt4NfJmZC_7iYi2dwM38B_BM
#endif /*BISMON_MODID */



// end of generated persistent module first_misc_module in file modbm_3BFt4NfJmZC_7iYi2dwM38B.c
