// generated persistent module first_misc_module
// in file modbm_3BFt4NfJmZC_7iYi2dwM38B.c -- DONT EDIT
// this generated code is GPLv3+ licensed.


#include "bismon.h"

#ifdef BISMON_MODID
DECLARE_MODULE_BM (_3BFt4NfJmZC_7iYi2dwM38B);
extern moduleinit_sigBM modulinit_3BFt4NfJmZC_7iYi2dwM38B_BM;
#endif /*BISMON_MODID */



// declare 10 routines

extern const char *const routid_3BFt4NfJmZC_7iYi2dwM38B_BM[10 + 1];

extern objrout_sigBM crout_0JktC4mAHCa_1KNr6uMIqIi_BM;  //#0

extern objrout_sigBM crout_0SinERsgdvQ_57dLCP63i9r_BM;  //#1

extern objrout_sigBM crout_0YOXUe7rEJC_3jFMjOAQRs9_BM;  //#2 element_of_closed_minifunc

extern objrout_sigBM crout_3iiht57Wrs1_5NbiUi27oBn_BM;  //#3

extern objrout_sigBM crout_3yQlckX4DRh_4b9l9FBSSSL_BM;  //#4 same_as_closed_minifunc

extern objrout_sigBM crout_4iEFTEcHxeb_6lH464uFkTC_BM;  //#5 equal_to_closed_minifunc

extern objrout_sigBM crout_4M7lr5cU6VD_5hxmeH3baBf_BM;  //#6

extern objrout_sigBM crout_5j8LpQULt1p_9oeOaqmfYYr_BM;  //#7

extern objrout_sigBM crout_82ho9wUUDji_4peMLha4PXl_BM;  //#8 findobj_scan_minifunc

extern objrout_sigBM crout_8imWClcIFKt_6w2H2ouB4I6_BM;  //#9 iterate_sequence_minifunc


// declare 14 constants
objectval_tyBM *constob_3BFt4NfJmZC_7iYi2dwM38B_BM[14 + 1];
const char *const constid_3BFt4NfJmZC_7iYi2dwM38B_BM[14 + 1];


// define 10 routines


value_tyBM crout_0JktC4mAHCa_1KNr6uMIqIi_BM     //#0
  (struct stackframe_stBM *stkf,        //
//!dump_scan°list_object minifunc for list_object o1 & dumperobj o2
   // 2 arguments
   const value_tyBM arg0,       // o1
   const value_tyBM arg1,       // o2
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _0JktC4mAHCa_1KNr6uMIqIi
  struct frame_0JktC4mAHCa_1KNr6uMIqIi_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 4 local values:
    value_tyBM v_2BkOxf2KbS8_3bswrKbmgjy;       // v_node
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    objectval_tyBM *o_93FBSk1ML0f_2WjSuKa9TNU;  // o2
    objectval_tyBM *o_97rnxb0KFqq_44veN75DG2E;  // o1
    /// 2 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
  } _;
  memset (&_, 0, sizeof (struct frame_0JktC4mAHCa_1KNr6uMIqIi_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 4;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[0] /*|_0JktC4mAHCa_1KNr6uMIqIi */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 2 arguments:
  _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0);
  _.o_93FBSk1ML0f_2WjSuKa9TNU = objectcast_BM (arg1);
  // fetched 2 arguments.
  // no closed values in _0JktC4mAHCa_1KNr6uMIqIi.
  // routine _0JktC4mAHCa_1KNr6uMIqIi body:

startblock__9xHQlk4snoU_6unWwGT6PcG:__attribute__ ((unused));
  {                             /* +block _9xHQlk4snoU_6unWwGT6PcG */
    _.v_2BkOxf2KbS8_3bswrKbmgjy =       //assign _8ggHPTQI1iG_02hVE5KybEL  
      /*objlisttonodepayl: */
      (value_tyBM)
      objlisttonodepayl_BM ((_.o_97rnxb0KFqq_44veN75DG2E),
                            ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[11]
                              /*|node */ )));


    _.n_833x2jYqhZh_8vDIuJhwz1k =       //assign _0zhpGzEVWGP_7WoL4LJocuS  
/*nodewidth:*/ (intptr_t) nodewidth_BM (_.v_2BkOxf2KbS8_3bswrKbmgjy);


    _.n_2W7Ckt2WxEM_4NVYgEWE73B =       //assign _0fygl91r6x5_8b3aCDptjAi  
      0;



//// +while _1w1gkKpMOzk_6mZXddz3Y4L 
  startblock__1w1gkKpMOzk_6mZXddz3Y4L: /*+!while */ ;
    {                           /* +while _1w1gkKpMOzk_6mZXddz3Y4L */
      if (!( /*while _1w1gkKpMOzk_6mZXddz3Y4L cond: */ ( /*less_int: */ (_.n_2W7Ckt2WxEM_4NVYgEWE73B) < (_.n_833x2jYqhZh_8vDIuJhwz1k))))        //: testwhile _1w1gkKpMOzk_6mZXddz3Y4L failing   
        goto endblock__1w1gkKpMOzk_6mZXddz3Y4L; //failwhile   
// while _1w1gkKpMOzk_6mZXddz3Y4L body:   
// while _1w1gkKpMOzk_6mZXddz3Y4L comp#0:  
      {                         // start cexpansion _4048rnGI686_6URARAINwQH - obdumpscanvalue   
        /*obdumpscanvalue: */
        obdumpscanvalue_BM ((_.o_93FBSk1ML0f_2WjSuKa9TNU), (    /*nodenthson: */
                                                             nodenthson_BM ((_.v_2BkOxf2KbS8_3bswrKbmgjy), (_.n_2W7Ckt2WxEM_4NVYgEWE73B))), (0));
      }                         // end cexpansion _4048rnGI686_6URARAINwQH - obdumpscanvalue   
// while _1w1gkKpMOzk_6mZXddz3Y4L comp#1:  
      _.n_2W7Ckt2WxEM_4NVYgEWE73B =     //assign _5fibWpWyCTN_8xn6wySOLhA   
/*add_int:*/ ((_.n_2W7Ckt2WxEM_4NVYgEWE73B) + (1));

      goto startblock__1w1gkKpMOzk_6mZXddz3Y4L; // repeatwhile  
    endblock__1w1gkKpMOzk_6mZXddz3Y4L: /*endingwhile */ ;
    }
  /*-while _1w1gkKpMOzk_6mZXddz3Y4L */

/* !endingblock _9xHQlk4snoU_6unWwGT6PcG */
    goto endblock__9xHQlk4snoU_6unWwGT6PcG;
  endblock__9xHQlk4snoU_6unWwGT6PcG:;
  }
  /*-block _9xHQlk4snoU_6unWwGT6PcG */

epilog_0JktC4mAHCa_1KNr6uMIqIi:__attribute__ ((unused));
  // routine _0JktC4mAHCa_1KNr6uMIqIi epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _0JktC4mAHCa_1KNr6uMIqIi routine#0 _0JktC4mAHCa_1KNr6uMIqIi




value_tyBM crout_0SinERsgdvQ_57dLCP63i9r_BM     //#1
  (struct stackframe_stBM * stkf,       //
//!forgetname#command_handler
   // 1 arguments
   const value_tyBM arg0,       // v_arg
   const value_tyBM arg1_ __attribute__ ((unused)),
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _0SinERsgdvQ_57dLCP63i9r
  struct frame_0SinERsgdvQ_57dLCP63i9r_BMst
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
    objectval_tyBM *o_7daWyW7jPyL_0EvyGgObjJm;  // o_arg
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_0SinERsgdvQ_57dLCP63i9r_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 3;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[1] /*|_0SinERsgdvQ_57dLCP63i9r */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 1 arguments:
  _.v_4Q4WBLjAPTV_5WVLmhAvCJY = arg0;
  // fetched 1 arguments.
  // no closed values in _0SinERsgdvQ_57dLCP63i9r.
  // routine _0SinERsgdvQ_57dLCP63i9r body:

startblock__84ATc5kpHjd_2wlYHZEUoeb:__attribute__ ((unused));
  {                             /* +block _84ATc5kpHjd_2wlYHZEUoeb */
    if                          /*cond _0Vnb5tJpsaA_9C18YQWoCmH */
      /*when _7aRr2DYoXS7_0jbH59RVcFR: */
      ( /*is_objectv */ isobject_BM (_.v_4Q4WBLjAPTV_5WVLmhAvCJY))
      {
        _.o_7daWyW7jPyL_0EvyGgObjJm =   //assign _1eDeH7xPojd_3uCQMEEBsHc   
/*val_to_object:*/ objectcast_BM (_.v_4Q4WBLjAPTV_5WVLmhAvCJY);

        {                       // run _5cqLFnQUJtD_2QMjkdfqr6q  
          forgetnamedobject_BM (_.o_7daWyW7jPyL_0EvyGgObjJm);
        }                       // end run _5cqLFnQUJtD_2QMjkdfqr6q  

        {                       // run _8y60zCwYsj4_4MKReQrfwGI  
          if (pthread_self () == mainthreadid_BM)
            {
              log_begin_message_BM ();
              log_puts_message_BM ("Forgot name of object ");
              log_object_message_BM (_.o_7daWyW7jPyL_0EvyGgObjJm);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
          ;
        }                       // end run _8y60zCwYsj4_4MKReQrfwGI  
        /*return _8X0BDdDTJe6_8OoRGA5RDeF: */ _.v_3qw9bnATIhq_8loBraLeXzQ =
          // returned  
          _.o_7daWyW7jPyL_0EvyGgObjJm;
        goto epilog_0SinERsgdvQ_57dLCP63i9r;

      }                         //endwhen _7aRr2DYoXS7_0jbH59RVcFR  
    else if
      /*when _3674ULyT2hz_5gMJA95w9aB: */
      ( /*issequence: */ issequence_BM (_.v_4Q4WBLjAPTV_5WVLmhAvCJY))
      {

        {                       // run _2Gx3OIyj6WH_36HZRfp3Slv  
          (apply1_BM (((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[13]
                        /*!iterate_sequence_minifunc */ )),
                      ((struct stackframe_stBM *) &_),
                      ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[1]
                        /*!_0SinERsgdvQ_57dLCP63i9r */ ))));
        }                       // end run _2Gx3OIyj6WH_36HZRfp3Slv  

      }                         //endwhen _3674ULyT2hz_5gMJA95w9aB  
/*endcond _0Vnb5tJpsaA_9C18YQWoCmH*/

/* !endingblock _84ATc5kpHjd_2wlYHZEUoeb */
    goto endblock__84ATc5kpHjd_2wlYHZEUoeb;
  endblock__84ATc5kpHjd_2wlYHZEUoeb:;
  }
  /*-block _84ATc5kpHjd_2wlYHZEUoeb */

epilog_0SinERsgdvQ_57dLCP63i9r:__attribute__ ((unused));
  // routine _0SinERsgdvQ_57dLCP63i9r epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _0SinERsgdvQ_57dLCP63i9r routine#1 _0SinERsgdvQ_57dLCP63i9r




value_tyBM crout_0YOXUe7rEJC_3jFMjOAQRs9_BM     //#2+
  (struct stackframe_stBM * stkf,       // element_of_closed_minifunc
//!return argument if it is contained in the closed set
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[2] /*|element_of_closed_minifunc */ ;
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
}                               // end _0YOXUe7rEJC_3jFMjOAQRs9 routine#2 element_of_closed_minifunc




value_tyBM crout_3iiht57Wrs1_5NbiUi27oBn_BM     //#3
  (struct stackframe_stBM * stkf,       //
//!prepend°list_object minifunc
   // 2 arguments
   const value_tyBM arg0,       // o1
   const value_tyBM arg1,       // v2
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _3iiht57Wrs1_5NbiUi27oBn
  struct frame_3iiht57Wrs1_5NbiUi27oBn_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 3 local values:
    value_tyBM v_09RxU8xDco3_2Zxwfb13oDZ;       // v2
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    objectval_tyBM *o_97rnxb0KFqq_44veN75DG2E;  // o1
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_3iiht57Wrs1_5NbiUi27oBn_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 3;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[5] /*|_3iiht57Wrs1_5NbiUi27oBn */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 2 arguments:
  _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0);
  _.v_09RxU8xDco3_2Zxwfb13oDZ = arg1;
  // fetched 2 arguments.
  // no closed values in _3iiht57Wrs1_5NbiUi27oBn.
  // routine _3iiht57Wrs1_5NbiUi27oBn body:

startblock__9BLJq5DadtZ_6I89t7ioVRS:__attribute__ ((unused));
  {                             /* +block _9BLJq5DadtZ_6I89t7ioVRS */
    if                          /*cond _2cKxScfQVIk_8j9yMA8y0D2 */
      /*when _9Eu315oGSiW_2T0LUr58JnT: */
      (                         /*objhaslistpayl: */
        objhaslistpayl_BM ((_.o_97rnxb0KFqq_44veN75DG2E)))
      {
        {                       // start cexpansion _8K97qV68UiQ_0ssdaZQW9h5 - objlistprependpayl   
/*objlistprependpayl:*/
          objlistprependpayl_BM ((_.o_97rnxb0KFqq_44veN75DG2E),
                                 (_.v_09RxU8xDco3_2Zxwfb13oDZ));
        }                       // end cexpansion _8K97qV68UiQ_0ssdaZQW9h5 - objlistprependpayl   
        /*return _3Hj8WH5oi59_3L07vytBdDJ: */ _.v_3qw9bnATIhq_8loBraLeXzQ =
          // returned  
          _.o_97rnxb0KFqq_44veN75DG2E;
        goto epilog_3iiht57Wrs1_5NbiUi27oBn;

      }                         //endwhen _9Eu315oGSiW_2T0LUr58JnT  
/*endcond _2cKxScfQVIk_8j9yMA8y0D2*/

/* !endingblock _9BLJq5DadtZ_6I89t7ioVRS */
    goto endblock__9BLJq5DadtZ_6I89t7ioVRS;
  endblock__9BLJq5DadtZ_6I89t7ioVRS:;
  }
  /*-block _9BLJq5DadtZ_6I89t7ioVRS */

epilog_3iiht57Wrs1_5NbiUi27oBn:__attribute__ ((unused));
  // routine _3iiht57Wrs1_5NbiUi27oBn epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _3iiht57Wrs1_5NbiUi27oBn routine#3 _3iiht57Wrs1_5NbiUi27oBn




value_tyBM crout_3yQlckX4DRh_4b9l9FBSSSL_BM     //#4+
  (struct stackframe_stBM * stkf,       // same_as_closed_minifunc
//!return argument if it is the same as the closed value
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[6] /*|same_as_closed_minifunc */ ;
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
}                               // end _3yQlckX4DRh_4b9l9FBSSSL routine#4 same_as_closed_minifunc




value_tyBM crout_4iEFTEcHxeb_6lH464uFkTC_BM     //#5+
  (struct stackframe_stBM * stkf,       // equal_to_closed_minifunc
//!return argument if it is the same as the closed value
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[7] /*|equal_to_closed_minifunc */ ;
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
}                               // end _4iEFTEcHxeb_6lH464uFkTC routine#5 equal_to_closed_minifunc




value_tyBM crout_4M7lr5cU6VD_5hxmeH3baBf_BM     //#6
  (struct stackframe_stBM * stkf,       //
//!append°list_object minifunction
   // 2 arguments
   const value_tyBM arg0,       // o1
   const value_tyBM arg1,       // v2
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _4M7lr5cU6VD_5hxmeH3baBf
  struct frame_4M7lr5cU6VD_5hxmeH3baBf_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 3 local values:
    value_tyBM v_09RxU8xDco3_2Zxwfb13oDZ;       // v2
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    objectval_tyBM *o_97rnxb0KFqq_44veN75DG2E;  // o1
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_4M7lr5cU6VD_5hxmeH3baBf_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 3;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[8] /*|_4M7lr5cU6VD_5hxmeH3baBf */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 2 arguments:
  _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0);
  _.v_09RxU8xDco3_2Zxwfb13oDZ = arg1;
  // fetched 2 arguments.
  // no closed values in _4M7lr5cU6VD_5hxmeH3baBf.
  // routine _4M7lr5cU6VD_5hxmeH3baBf body:

startblock__883QaWUOedh_9zmHk2A3RPm:__attribute__ ((unused));
  {                             /* +block _883QaWUOedh_9zmHk2A3RPm */
    if                          /*cond _9l1kqklfeho_8gvTSpVHJs0 */
      /*when _4bt3mp8e1a2_7XsOs7auvrU: */
      (                         /*objhaslistpayl: */
        objhaslistpayl_BM ((_.o_97rnxb0KFqq_44veN75DG2E)))
      {
        {                       // start cexpansion _8WKnIBYQNvy_0t8M4F48joR - objlistappendpayl   
/*objlistappendpayl:*/
          objlistappendpayl_BM ((_.o_97rnxb0KFqq_44veN75DG2E),
                                (_.v_09RxU8xDco3_2Zxwfb13oDZ));
        }                       // end cexpansion _8WKnIBYQNvy_0t8M4F48joR - objlistappendpayl   
        /*return _86rGd2LLytX_4xsXHoCmw1Y: */ _.v_3qw9bnATIhq_8loBraLeXzQ =
          // returned  
          _.o_97rnxb0KFqq_44veN75DG2E;
        goto epilog_4M7lr5cU6VD_5hxmeH3baBf;

      }                         //endwhen _4bt3mp8e1a2_7XsOs7auvrU  
/*endcond _9l1kqklfeho_8gvTSpVHJs0*/

/* !endingblock _883QaWUOedh_9zmHk2A3RPm */
    goto endblock__883QaWUOedh_9zmHk2A3RPm;
  endblock__883QaWUOedh_9zmHk2A3RPm:;
  }
  /*-block _883QaWUOedh_9zmHk2A3RPm */

epilog_4M7lr5cU6VD_5hxmeH3baBf:__attribute__ ((unused));
  // routine _4M7lr5cU6VD_5hxmeH3baBf epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _4M7lr5cU6VD_5hxmeH3baBf routine#6 _4M7lr5cU6VD_5hxmeH3baBf




value_tyBM crout_5j8LpQULt1p_9oeOaqmfYYr_BM     //#7
  (struct stackframe_stBM * stkf,       //
//!dump_data°list_object minifunc;
   // 3 arguments
   const value_tyBM arg0,       // o1
   const value_tyBM arg1,       // o2
   const value_tyBM arg2,       // o3
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _5j8LpQULt1p_9oeOaqmfYYr
  struct frame_5j8LpQULt1p_9oeOaqmfYYr_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 5 local values:
    objectval_tyBM *o_1Bl1iFQ8boR_1xM6MOfHV1N;  // o3
    value_tyBM v_2BkOxf2KbS8_3bswrKbmgjy;       // v_node
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    objectval_tyBM *o_93FBSk1ML0f_2WjSuKa9TNU;  // o2
    objectval_tyBM *o_97rnxb0KFqq_44veN75DG2E;  // o1
    /// 2 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
  } _;
  memset (&_, 0, sizeof (struct frame_5j8LpQULt1p_9oeOaqmfYYr_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 5;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[9] /*|_5j8LpQULt1p_9oeOaqmfYYr */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 3 arguments:
  _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0);
  _.o_93FBSk1ML0f_2WjSuKa9TNU = objectcast_BM (arg1);
  _.o_1Bl1iFQ8boR_1xM6MOfHV1N = objectcast_BM (arg2);
  // fetched 3 arguments.
  // no closed values in _5j8LpQULt1p_9oeOaqmfYYr.
  // routine _5j8LpQULt1p_9oeOaqmfYYr body:

startblock__9Hf4n8AnqR7_7ve3Bi3kWMV:__attribute__ ((unused));
  {                             /* +block _9Hf4n8AnqR7_7ve3Bi3kWMV */
    _.v_2BkOxf2KbS8_3bswrKbmgjy =       //assign _8ggHPTQI1iG_02hVE5KybEL  
      /*objlisttonodepayl: */
      (value_tyBM)
      objlisttonodepayl_BM ((_.o_97rnxb0KFqq_44veN75DG2E),
                            ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[11]
                              /*|node */ )));


    _.n_833x2jYqhZh_8vDIuJhwz1k =       //assign _0zhpGzEVWGP_7WoL4LJocuS  
/*nodewidth:*/ (intptr_t) nodewidth_BM (_.v_2BkOxf2KbS8_3bswrKbmgjy);


    _.n_2W7Ckt2WxEM_4NVYgEWE73B =       //assign _0fygl91r6x5_8b3aCDptjAi  
      0;

/* !endingblock _9Hf4n8AnqR7_7ve3Bi3kWMV */
    goto endblock__9Hf4n8AnqR7_7ve3Bi3kWMV;
  endblock__9Hf4n8AnqR7_7ve3Bi3kWMV:;
  }
  /*-block _9Hf4n8AnqR7_7ve3Bi3kWMV */

epilog_5j8LpQULt1p_9oeOaqmfYYr:__attribute__ ((unused));
  // routine _5j8LpQULt1p_9oeOaqmfYYr epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _5j8LpQULt1p_9oeOaqmfYYr routine#7 _5j8LpQULt1p_9oeOaqmfYYr




value_tyBM crout_82ho9wUUDji_4peMLha4PXl_BM     //#8+
  (struct stackframe_stBM * stkf,       // findobj_scan_minifunc
//!findobj_scan_minifunc scans, with the closed and locked o_findobj, the argument object o_scan; give NULL if o_scan was already scanned
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[12] /*|findobj_scan_minifunc */ ;
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
                      (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[10]
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
}                               // end _82ho9wUUDji_4peMLha4PXl routine#8 findobj_scan_minifunc




value_tyBM crout_8imWClcIFKt_6w2H2ouB4I6_BM     //#9+
  (struct stackframe_stBM * stkf,       // iterate_sequence_minifunc
//!iterate on sequence v_seq the function v_fun with 2nd argument v_arg
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[13] /*|iterate_sequence_minifunc */ ;
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
}                               // end _8imWClcIFKt_6w2H2ouB4I6 routine#9 iterate_sequence_minifunc




// end of 10 generated routines


// the constant ids for 14 constants:
const char *const constid_3BFt4NfJmZC_7iYi2dwM38B_BM[14 + 1] = {
  /*0: */
  "_0JktC4mAHCa_1KNr6uMIqIi",
  "_0SinERsgdvQ_57dLCP63i9r",
  "_0YOXUe7rEJC_3jFMjOAQRs9",   //element_of_closed_minifunc
  "_1dzZlwqKdLH_8HjkBsL9Mar",   //add
  "_1FEnnpEkGdI_5DAcVDL5XHG",   //dump_value
  "_3iiht57Wrs1_5NbiUi27oBn",
  "_3yQlckX4DRh_4b9l9FBSSSL",   //same_as_closed_minifunc
  "_4iEFTEcHxeb_6lH464uFkTC",   //equal_to_closed_minifunc
  /*8: */
  "_4M7lr5cU6VD_5hxmeH3baBf",
  "_5j8LpQULt1p_9oeOaqmfYYr",
  "_64UbCFBD19G_43TeBXhcYMy",   //findrun_object
  "_7D8xcWnEiys_8oqOVSkCxkA",   //node
  "_82ho9wUUDji_4peMLha4PXl",   //findobj_scan_minifunc
  "_8imWClcIFKt_6w2H2ouB4I6",   //iterate_sequence_minifunc
  NULL
};                              // end 14 constant ids



// the routine ids for 10 routines:
const char *const routid_3BFt4NfJmZC_7iYi2dwM38B_BM[10 + 1] = {
  /*0: */
  "_0JktC4mAHCa_1KNr6uMIqIi",
  "_0SinERsgdvQ_57dLCP63i9r",
  "_0YOXUe7rEJC_3jFMjOAQRs9",   //element_of_closed_minifunc
  "_3iiht57Wrs1_5NbiUi27oBn",
  "_3yQlckX4DRh_4b9l9FBSSSL",   //same_as_closed_minifunc
  "_4iEFTEcHxeb_6lH464uFkTC",   //equal_to_closed_minifunc
  "_4M7lr5cU6VD_5hxmeH3baBf",
  "_5j8LpQULt1p_9oeOaqmfYYr",
  /*8: */
  "_82ho9wUUDji_4peMLha4PXl",   //findobj_scan_minifunc
  "_8imWClcIFKt_6w2H2ouB4I6",   //iterate_sequence_minifunc

  NULL
};                              // end 10 routine ids



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
