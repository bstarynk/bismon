// generated persistent module first_misc_module
// in file modbm_3BFt4NfJmZC_7iYi2dwM38B.c -- DONT EDIT
// this generated code is GPLv3+ licensed.


#include "bismon.h"

#ifdef BISMON_MODID
DECLARE_MODULE_BM (_3BFt4NfJmZC_7iYi2dwM38B);
extern moduleinit_sigBM modulinit_3BFt4NfJmZC_7iYi2dwM38B_BM;
#endif /*BISMON_MODID */

#ifdef BISMON_MOMD5
const char modulmd5chksum_3BFt4NfJmZC_7iYi2dwM38B_BM[] = BISMON_MOMD5;
#endif /*BISMON_MOMD5 */



// declare 17 routines

extern const char *const routid_3BFt4NfJmZC_7iYi2dwM38B_BM[17 + 1];


// no failure

extern objrout_sigBM crout_0cUdonky1bM_4IVhwlVRBMk_BM;  //#0 !webhandler testhello minifunc

extern objrout_sigBM crout_0JktC4mAHCa_1KNr6uMIqIi_BM;  //#1 !dump_scan°list_object minifunc for list_object o1 & dumperobj o2

extern objrout_sigBM crout_0SinERsgdvQ_57dLCP63i9r_BM;  //#2 !forgetname#command_handler

extern objrout_sigBM crout_0YOXUe7rEJC_3jFMjOAQRs9_BM;  //#3 element_of_closed_minifunc

extern objrout_sigBM crout_22Zd68WPKUO_6AoIuBcbUb2_BM;  //#4 !dump_scan°dict_object minifunc for dict-object odict and dumperobj odumper

extern objrout_sigBM crout_2bZ4BfCci5V_3WTzG7V25y4_BM;  //#5 !put°dict_object minifunc

extern objrout_sigBM crout_3iiht57Wrs1_5NbiUi27oBn_BM;  //#6 !prepend°list_object minifunc

extern objrout_sigBM crout_3vI0Qc3FHQG_1g4fmHYkxSA_BM;  //#7 !jsmodule compiler: compile o_jsmodule into o_strbuf

extern objrout_sigBM crout_3yQlckX4DRh_4b9l9FBSSSL_BM;  //#8 same_as_closed_minifunc

extern objrout_sigBM crout_3HAeZZQ0q7b_7qyDsekaz7Y_BM;  //#9 !clear°list_object minifunc

extern objrout_sigBM crout_4iEFTEcHxeb_6lH464uFkTC_BM;  //#10 equal_to_closed_minifunc

extern objrout_sigBM crout_4qlegfkPzrC_17skUfJP7v8_BM;  //#11 !dump_data°dict_object minifun

extern objrout_sigBM crout_4M7lr5cU6VD_5hxmeH3baBf_BM;  //#12 !append°list_object minifunction

extern objrout_sigBM crout_5j8LpQULt1p_9oeOaqmfYYr_BM;  //#13 !dump_data°list_object minifunc

extern objrout_sigBM crout_82ho9wUUDji_4peMLha4PXl_BM;  //#14 findobj_scan_minifunc

extern objrout_sigBM crout_8imWClcIFKt_6w2H2ouB4I6_BM;  //#15 iterate_sequence_minifunc

extern objrout_sigBM crout_9CG8SKNs6Ql_4PiHd8cnydn_BM;  //#16 !clear°dict_object minifun


// declare 32 constants
objectval_tyBM *constob_3BFt4NfJmZC_7iYi2dwM38B_BM[32 + 1];
const char *const constid_3BFt4NfJmZC_7iYi2dwM38B_BM[32 + 1];


// define 17 routines


value_tyBM crout_0cUdonky1bM_4IVhwlVRBMk_BM     //#0
  (struct stackframe_stBM *stkf,        //
//!webhandler testhello minifunc
   // 2 arguments
   const value_tyBM arg0,       // v_restpath
   const value_tyBM arg1,       // o_webex
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _0cUdonky1bM_4IVhwlVRBMk
  struct frame_0cUdonky1bM_4IVhwlVRBMk_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 5 local values:
    value_tyBM v_2nnQQ6Lvtpl_4oCJYx90FlI;       // v_postbar
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    objectval_tyBM *o_5JuT4FgNFFh_7McrTYeT3jx;  // o_webex
    value_tyBM v_6QhNRfe1Cte_0niVlWfAlmO;       // v_restpath
    value_tyBM v_8s5u19T0e2h_9ZqrO3YZDVS;       // v_queryfoo
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_0cUdonky1bM_4IVhwlVRBMk_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 5;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[0] /*|_0cUdonky1bM_4IVhwlVRBMk */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 2 arguments:
  _.v_6QhNRfe1Cte_0niVlWfAlmO = arg0;
  _.o_5JuT4FgNFFh_7McrTYeT3jx = objectcast_BM (arg1);
  // fetched 2 arguments.
  // no closed values in _0cUdonky1bM_4IVhwlVRBMk.
  // routine _0cUdonky1bM_4IVhwlVRBMk body:

startblock__8prn9eFlYZD_6JJKKh2b8KW:__attribute__ ((unused));
  {                             /* +block _8prn9eFlYZD_6JJKKh2b8KW */

    {                           // run _65239uTOHoM_0gCnjTxaNEB 
      /*Debug Web TestHello */
      DBGPRINTF_BM ("start webhandler testhello o_webex= %s",
                    objectdbg_BM (_.o_5JuT4FgNFFh_7McrTYeT3jx));
      ;
    }                           // end run _65239uTOHoM_0gCnjTxaNEB 



  startblock__3VVvcLyYqv8_9yci7GvqEEv:__attribute__ ((unused));
    {                           /* +block _3VVvcLyYqv8_9yci7GvqEEv */
      {                         // start cexpansion _5lsoSuyLYE0_2cqb9QxFcos - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/
        objstrbufferappendcstrpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                       ("<h1>testhello bismon</h1>\n"));
      }                         // end cexpansion _5lsoSuyLYE0_2cqb9QxFcos - objstrbufferappendcstrpayl   


      if                        /*cond _27HdixkwtUA_4tQyI0XopOj */
        /*when _57I7rSuuKya_8AuIt3qlJI1: */
        (                       /*objwebexchangerequestispostpayl: */
          objwebexchangerequestispostpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx)))
        {
          {                     // start cexpansion _2AxVlhlfGNw_7PIs9S04rhK - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/
            objstrbufferappendcstrpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                           ("<p><tt>POST</tt> request!</p>\n"));
          }                     // end cexpansion _2AxVlhlfGNw_7PIs9S04rhK - objstrbufferappendcstrpayl    

        }                       //endwhen _57I7rSuuKya_8AuIt3qlJI1   
/*endcond _27HdixkwtUA_4tQyI0XopOj*/


      {                         // start cexpansion _1gjXCT3HN6V_5SGgDufAmKf - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/
        objstrbufferappendcstrpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                       ("<p>session: <tt>"));
      }                         // end cexpansion _1gjXCT3HN6V_5SGgDufAmKf - objstrbufferappendcstrpayl   


      {                         // start cexpansion _1XzuICo9tMz_2FMOEMMgKHC - objstrbufferprintobjid   
/*objstrbufferprintobjid _1XzuICo9tMz_2FMOEMMgKHC:*/
        objectval_tyBM *obsbuf__1XzuICo9tMz_2FMOEMMgKHC =
          (_.o_5JuT4FgNFFh_7McrTYeT3jx);
        objectval_tyBM *ob__1XzuICo9tMz_2FMOEMMgKHC = ( /*objwebexchangesessionpayl: */
                                                        objwebexchangesessionpayl_BM
                                                        ((_.
                                                          o_5JuT4FgNFFh_7McrTYeT3jx)));
        if (objhasstrbufferpayl_BM (obsbuf__1XzuICo9tMz_2FMOEMMgKHC)
            && isobject_BM (ob__1XzuICo9tMz_2FMOEMMgKHC))
          {
            char idbuf__1XzuICo9tMz_2FMOEMMgKHC[32];
            memset (idbuf__1XzuICo9tMz_2FMOEMMgKHC, 0,
                    sizeof (idbuf__1XzuICo9tMz_2FMOEMMgKHC));
            idtocbuf32_BM (objid_BM (ob__1XzuICo9tMz_2FMOEMMgKHC),
                           idbuf__1XzuICo9tMz_2FMOEMMgKHC);
            objstrbufferappendcstrpayl_BM (obsbuf__1XzuICo9tMz_2FMOEMMgKHC,
                                           idbuf__1XzuICo9tMz_2FMOEMMgKHC);
          };
// end objstrbufferprintobjid _1XzuICo9tMz_2FMOEMMgKHC
        ;
      }                         // end cexpansion _1XzuICo9tMz_2FMOEMMgKHC - objstrbufferprintobjid    


      {                         // start cexpansion _9osbAnIQdp8_6wVcWPdPIBQ - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/
        objstrbufferappendcstrpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                       ("</tt></p>\n"));
      }                         // end cexpansion _9osbAnIQdp8_6wVcWPdPIBQ - objstrbufferappendcstrpayl   


      _.v_8s5u19T0e2h_9ZqrO3YZDVS =     //assign _5Aqv9Xln871_5IcSxT4moVS   
/*objwebexchangerequestcstrquerypayl:*/
        objwebexchangerequestcstrquerypayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                               ("foo"));


      _.v_2nnQQ6Lvtpl_4oCJYx90FlI =     //assign _3vXdUQt5mey_5MeGY4lFI0J   
/*objwebexchangerequestcstrpostpayl:*/
        objwebexchangerequestcstrpostpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                              ("bar"));


      if                        /*cond _2THq8nc1q1F_4cGFcYCkXve */
/*when _60Hl1XdMfUK_1F8CwPaYrTV:*/ (_.v_8s5u19T0e2h_9ZqrO3YZDVS)
        {
          {                     // start cexpansion _6QzWx6GgQRi_384FRK3jVwG - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/
            objstrbufferappendcstrpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                           ("<p>With <i>foo</i> query: <tt>"));
          }                     // end cexpansion _6QzWx6GgQRi_384FRK3jVwG - objstrbufferappendcstrpayl    
          {                     // start cexpansion _6KDkrFdjO9P_14wFqrvJOfp - objstrbufferprinthtmlstringval    
/*objstrbufferprinthtmlstringval:*/
            if (objhasstrbufferpayl_BM (_.o_5JuT4FgNFFh_7McrTYeT3jx)
                && isstring_BM (_.v_8s5u19T0e2h_9ZqrO3YZDVS))
              objstrbufferencodedhtmlpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                              bytstring_BM
                                              (_.v_8s5u19T0e2h_9ZqrO3YZDVS),
                                              lenstring_BM
                                              (_.v_8s5u19T0e2h_9ZqrO3YZDVS));;
          }                     // end cexpansion _6KDkrFdjO9P_14wFqrvJOfp - objstrbufferprinthtmlstringval    
          {                     // start cexpansion _2vbuTjbZtsO_572Ywmb2g5P - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/
            objstrbufferappendcstrpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                           ("</tt></p>\n"));
          }                     // end cexpansion _2vbuTjbZtsO_572Ywmb2g5P - objstrbufferappendcstrpayl    

        }                       //endwhen _60Hl1XdMfUK_1F8CwPaYrTV   
      else
        {                       /*cond else _2THq8nc1q1F_4cGFcYCkXve */
          {                     // start cexpansion _6RNWoVxR1o8_1HcOAeanMtD - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/
            objstrbufferappendcstrpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                           ("<p><b>No</b> <i>foo</i> query!</p>\n"));
          }                     // end cexpansion _6RNWoVxR1o8_1HcOAeanMtD - objstrbufferappendcstrpayl   
        }                       /*cond else _2THq8nc1q1F_4cGFcYCkXve */
/*endcond _2THq8nc1q1F_4cGFcYCkXve*/


      if                        /*cond _057nvpyNs61_4NN6PpJ3blv */
/*when _3nPbGhqwKVU_6YbKeoirRRT:*/ (_.v_2nnQQ6Lvtpl_4oCJYx90FlI)
        {
          {                     // start cexpansion _8iDfqbg4KqL_76BIqjTrj3e - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/
            objstrbufferappendcstrpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                           ("<p>With <i>bar</i> query post: <tt>"));
          }                     // end cexpansion _8iDfqbg4KqL_76BIqjTrj3e - objstrbufferappendcstrpayl    
          {                     // start cexpansion _27sh4N25FsE_1pTCEF1T86V - objstrbufferprinthtmlstringval    
/*objstrbufferprinthtmlstringval:*/
            if (objhasstrbufferpayl_BM (_.o_5JuT4FgNFFh_7McrTYeT3jx)
                && isstring_BM (_.v_2nnQQ6Lvtpl_4oCJYx90FlI))
              objstrbufferencodedhtmlpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                              bytstring_BM
                                              (_.v_2nnQQ6Lvtpl_4oCJYx90FlI),
                                              lenstring_BM
                                              (_.v_2nnQQ6Lvtpl_4oCJYx90FlI));;
          }                     // end cexpansion _27sh4N25FsE_1pTCEF1T86V - objstrbufferprinthtmlstringval    
          {                     // start cexpansion _8OWeFkBKHSs_8iHHVgkRKA9 - objstrbufferappendcstrpayl    
/*objstrbufferappendcstrpayl:*/
            objstrbufferappendcstrpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                           ("</tt></p>\n"));
          }                     // end cexpansion _8OWeFkBKHSs_8iHHVgkRKA9 - objstrbufferappendcstrpayl    

        }                       //endwhen _3nPbGhqwKVU_6YbKeoirRRT   
      else
        {                       /*cond else _057nvpyNs61_4NN6PpJ3blv */
          {                     // start cexpansion _1KQI2bY1P58_8cNaZP3fXxP - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/
            objstrbufferappendcstrpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                           ("<p><b>No</b> <i>bar</i> post!</p>\n"));
          }                     // end cexpansion _1KQI2bY1P58_8cNaZP3fXxP - objstrbufferappendcstrpayl   
        }                       /*cond else _057nvpyNs61_4NN6PpJ3blv */
/*endcond _057nvpyNs61_4NN6PpJ3blv*/


      {                         // start cexpansion _1cxOV5GldRc_8pSs0K0x3sK - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/
        objstrbufferappendcstrpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                       ("<form method=\'post\'><i>bar:</i> <input type=\'text\' name=\'bar\'/> <input type=\'submit\' name=\'dosubmit\' value=\'do!\'/> </form>\n"));
      }                         // end cexpansion _1cxOV5GldRc_8pSs0K0x3sK - objstrbufferappendcstrpayl   


      {                         // start cexpansion _5fVxVvN0D70_5iLoRUEbGnA - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/
        objstrbufferappendcstrpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                       ("<p>Generated at <i>"));
      }                         // end cexpansion _5fVxVvN0D70_5iLoRUEbGnA - objstrbufferappendcstrpayl   


      {                         // start cexpansion _6nzVdVGk8wB_0paW5wP6NFo - objstrbufferprinthtmlstringval   
/*objstrbufferprinthtmlstringval:*/
        if (objhasstrbufferpayl_BM (_.o_5JuT4FgNFFh_7McrTYeT3jx)
            && isstring_BM ( /*flocaltimestring: */ (value_tyBM)
                            flocaltimestring_BM (("%c"), (time_t) (     /*timenow: */
                                                                    (intptr_t)
                                                                    time
                                                                    (NULL)))))
          objstrbufferencodedhtmlpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                          bytstring_BM (
                                                          /*flocaltimestring: */
                                          (value_tyBM)
                                                          flocaltimestring_BM
                                                          (("%c"), (time_t) (
                                                                               /*timenow: */
                                                                               (intptr_t) time (NULL)))), lenstring_BM ( /*flocaltimestring: */ (value_tyBM)
                                                                                                                        flocaltimestring_BM
                                                                                                                        (("%c"), (time_t) ( /*timenow: */ (intptr_t)
                                                                                                                                           time
                                                                                                                                           (NULL)))));;
      }                         // end cexpansion _6nzVdVGk8wB_0paW5wP6NFo - objstrbufferprinthtmlstringval    


      {                         // start cexpansion _9xLEdrWsdEt_3HIoqy3EsOT - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/
        objstrbufferappendcstrpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                       ("</i>.</p>\n"));
      }                         // end cexpansion _9xLEdrWsdEt_3HIoqy3EsOT - objstrbufferappendcstrpayl   

/* !endingblock _3VVvcLyYqv8_9yci7GvqEEv */
      goto endblock__3VVvcLyYqv8_9yci7GvqEEv;
    endblock__3VVvcLyYqv8_9yci7GvqEEv:;
    }
  /*-block _3VVvcLyYqv8_9yci7GvqEEv */

    {                           // start cexpansion _7JswZzcJki7_3B8LL8KLffZ - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/
      objstrbufferappendcstrpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                     ("</body>\n</html>"));
    }                           // end cexpansion _7JswZzcJki7_3B8LL8KLffZ - objstrbufferappendcstrpayl  


    {                           // start cexpansion _0aLvox3qw9g_6O8WY6Cew3g - objwebexchangecompletepayl  
/*objwebexchangecompletepayl:*/
      objwebexchangecompletepayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                     (200), ("text/html; charset=utf-8"));
    }                           // end cexpansion _0aLvox3qw9g_6O8WY6Cew3g - objwebexchangecompletepayl  


    /*return _8VHbQSvNRq4_44CGuKiIMLb: */ _.v_3qw9bnATIhq_8loBraLeXzQ =
      // returned 
      _.o_5JuT4FgNFFh_7McrTYeT3jx;
    goto epilog_0cUdonky1bM_4IVhwlVRBMk;



  startblock__4ZE2MUVTcHt_4lWsA1elKmS:__attribute__ ((unused));
    {                           /* +block _4ZE2MUVTcHt_4lWsA1elKmS */
      {                         // start cexpansion _2CWJlYEwmaf_6nlLCxAfCx8 - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/
        objstrbufferappendcstrpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                       ("<!DOCTYPE html>\n<html><head><title>testhello bismon</title>\n"));
      }                         // end cexpansion _2CWJlYEwmaf_6nlLCxAfCx8 - objstrbufferappendcstrpayl   


      {                         // start cexpansion _07IfSVe5oBj_7I7w9nZbfgr - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/
        objstrbufferappendcstrpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                       ("</head>\n"));
      }                         // end cexpansion _07IfSVe5oBj_7I7w9nZbfgr - objstrbufferappendcstrpayl   


      {                         // start cexpansion _4ootClJhCCt_4B3yo2Szuwj - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/
        objstrbufferappendcstrpayl_BM ((_.o_5JuT4FgNFFh_7McrTYeT3jx),
                                       ("<body>\n"));
      }                         // end cexpansion _4ootClJhCCt_4B3yo2Szuwj - objstrbufferappendcstrpayl   

/* !endingblock _4ZE2MUVTcHt_4lWsA1elKmS */
      goto endblock__4ZE2MUVTcHt_4lWsA1elKmS;
    endblock__4ZE2MUVTcHt_4lWsA1elKmS:;
    }
  /*-block _4ZE2MUVTcHt_4lWsA1elKmS */
/* !endingblock _8prn9eFlYZD_6JJKKh2b8KW */
    goto endblock__8prn9eFlYZD_6JJKKh2b8KW;
  endblock__8prn9eFlYZD_6JJKKh2b8KW:;
  }
  /*-block _8prn9eFlYZD_6JJKKh2b8KW */

epilog_0cUdonky1bM_4IVhwlVRBMk:__attribute__ ((unused));
  // routine _0cUdonky1bM_4IVhwlVRBMk epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _0cUdonky1bM_4IVhwlVRBMk routine#0 _0cUdonky1bM_4IVhwlVRBMk




value_tyBM crout_0JktC4mAHCa_1KNr6uMIqIi_BM     //#1
  (struct stackframe_stBM * stkf,       //
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[1] /*|_0JktC4mAHCa_1KNr6uMIqIi */ ;
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
      (value_tyBM) objlisttonodepayl_BM ((_.o_97rnxb0KFqq_44veN75DG2E), ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[1] /*|node */
                                                                         )));


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
}                               // end _0JktC4mAHCa_1KNr6uMIqIi routine#1 _0JktC4mAHCa_1KNr6uMIqIi




value_tyBM crout_0SinERsgdvQ_57dLCP63i9r_BM     //#2
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[2] /*|_0SinERsgdvQ_57dLCP63i9r */ ;
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
          (apply1_BM (((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[27]
                        /*!iterate_sequence_minifunc */ )),
                      ((struct stackframe_stBM *) &_),
                      ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[2]
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
}                               // end _0SinERsgdvQ_57dLCP63i9r routine#2 _0SinERsgdvQ_57dLCP63i9r




value_tyBM crout_0YOXUe7rEJC_3jFMjOAQRs9_BM     //#3+
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[3] /*|element_of_closed_minifunc */ ;
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
}                               // end _0YOXUe7rEJC_3jFMjOAQRs9 routine#3 element_of_closed_minifunc




value_tyBM crout_22Zd68WPKUO_6AoIuBcbUb2_BM     //#4
  (struct stackframe_stBM * stkf,       //
//!dump_scan°dict_object minifunc for dict-object odict and dumperobj odumper
   // 2 arguments
   const value_tyBM arg0,       // odict
   const value_tyBM arg1,       // odumper
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _22Zd68WPKUO_6AoIuBcbUb2
  struct frame_22Zd68WPKUO_6AoIuBcbUb2_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 5 local values:
    value_tyBM v_167WczZjWtG_3FofhJxQWJi;       // v_str
    objectval_tyBM *o_3cTC8W7d75H_1vteOyEoAao;  // odumper
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    value_tyBM v_5jRQCD1qTko_61I0j04ugAA;       // v_val
    objectval_tyBM *o_7n2SLLuWOjH_4ArhFUjmckz;  // odict
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_22Zd68WPKUO_6AoIuBcbUb2_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 5;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[1] /*|_22Zd68WPKUO_6AoIuBcbUb2 */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 2 arguments:
  _.o_7n2SLLuWOjH_4ArhFUjmckz = objectcast_BM (arg0);
  _.o_3cTC8W7d75H_1vteOyEoAao = objectcast_BM (arg1);
  // fetched 2 arguments.
  // no closed values in _22Zd68WPKUO_6AoIuBcbUb2.
  // routine _22Zd68WPKUO_6AoIuBcbUb2 body:

startblock__7csjYG7rNV4_68bJZT4W2BO:__attribute__ ((unused));
  {                             /* +block _7csjYG7rNV4_68bJZT4W2BO */
    _.v_167WczZjWtG_3FofhJxQWJi =       //assign _5mCmWSYOW7T_4G9YRC6tvRf  
/*objdictfirstkeypayl:*/
      (value_tyBM) objdictfirstkeypayl_BM ((_.o_7n2SLLuWOjH_4ArhFUjmckz));



//// +while _0SWi4IZCeP3_0VPExGvOasL 
  startblock__0SWi4IZCeP3_0VPExGvOasL: /*+!while */ ;
    {                           /* +while _0SWi4IZCeP3_0VPExGvOasL */
      if (!( /*while _0SWi4IZCeP3_0VPExGvOasL cond: */ _.v_167WczZjWtG_3FofhJxQWJi))    //: testwhile _0SWi4IZCeP3_0VPExGvOasL failing  
        goto endblock__0SWi4IZCeP3_0VPExGvOasL; //failwhile  
// while _0SWi4IZCeP3_0VPExGvOasL body:  
// while _0SWi4IZCeP3_0VPExGvOasL comp#0:  
      _.v_5jRQCD1qTko_61I0j04ugAA =     //assign _2dCjJpUS20B_3NM9eVa84hQ   
/*objdictgetpayl:*/ objdictgetpayl_BM ((_.o_7n2SLLuWOjH_4ArhFUjmckz),
                                       stringcast_BM
                                       (_.v_167WczZjWtG_3FofhJxQWJi));
// while _0SWi4IZCeP3_0VPExGvOasL comp#1:  
      {                         // start cexpansion _0LKRJrD5wqK_5ZE495IAA7d - obdumpscanvalue   
/*obdumpscanvalue:*/
        obdumpscanvalue_BM ((_.o_3cTC8W7d75H_1vteOyEoAao),
                            (_.v_5jRQCD1qTko_61I0j04ugAA), (1));
      }                         // end cexpansion _0LKRJrD5wqK_5ZE495IAA7d - obdumpscanvalue   
// while _0SWi4IZCeP3_0VPExGvOasL comp#2:  
      _.v_167WczZjWtG_3FofhJxQWJi =     //assign _5UiotUrFshh_9xWCmys30Pe   
/*objdictkeyafterpayl:*/
        (value_tyBM) objdictkeyafterpayl_BM ((_.o_7n2SLLuWOjH_4ArhFUjmckz),
                                             stringcast_BM
                                             (_.v_167WczZjWtG_3FofhJxQWJi));

      goto startblock__0SWi4IZCeP3_0VPExGvOasL; // repeatwhile  
    endblock__0SWi4IZCeP3_0VPExGvOasL: /*endingwhile */ ;
    }
  /*-while _0SWi4IZCeP3_0VPExGvOasL */


    /*return _8pmMgF3SSuE_2COzwjyI8lS: */ _.v_3qw9bnATIhq_8loBraLeXzQ =
      // returned 
      _.o_7n2SLLuWOjH_4ArhFUjmckz;
    goto epilog_22Zd68WPKUO_6AoIuBcbUb2;

/* !endingblock _7csjYG7rNV4_68bJZT4W2BO */
    goto endblock__7csjYG7rNV4_68bJZT4W2BO;
  endblock__7csjYG7rNV4_68bJZT4W2BO:;
  }
  /*-block _7csjYG7rNV4_68bJZT4W2BO */

epilog_22Zd68WPKUO_6AoIuBcbUb2:__attribute__ ((unused));
  // routine _22Zd68WPKUO_6AoIuBcbUb2 epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _22Zd68WPKUO_6AoIuBcbUb2 routine#4 _22Zd68WPKUO_6AoIuBcbUb2




value_tyBM crout_2bZ4BfCci5V_3WTzG7V25y4_BM     //#5
  (struct stackframe_stBM * stkf,       //
//!put°dict_object minifunc
   // 3 arguments
   const value_tyBM arg0,       // odict
   const value_tyBM arg1,       // v_str
   const value_tyBM arg2,       // v_val
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _2bZ4BfCci5V_3WTzG7V25y4
  struct frame_2bZ4BfCci5V_3WTzG7V25y4_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 4 local values:
    value_tyBM v_167WczZjWtG_3FofhJxQWJi;       // v_str
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    value_tyBM v_5jRQCD1qTko_61I0j04ugAA;       // v_val
    objectval_tyBM *o_7n2SLLuWOjH_4ArhFUjmckz;  // odict
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_2bZ4BfCci5V_3WTzG7V25y4_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 4;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[9] /*|_2bZ4BfCci5V_3WTzG7V25y4 */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 3 arguments:
  _.o_7n2SLLuWOjH_4ArhFUjmckz = objectcast_BM (arg0);
  _.v_167WczZjWtG_3FofhJxQWJi = arg1;
  _.v_5jRQCD1qTko_61I0j04ugAA = arg2;
  // fetched 3 arguments.
  // no closed values in _2bZ4BfCci5V_3WTzG7V25y4.
  // routine _2bZ4BfCci5V_3WTzG7V25y4 body:

startblock__0VJTIqFfNXf_5chzuIlqcJP:__attribute__ ((unused));
  {                             /* +block _0VJTIqFfNXf_5chzuIlqcJP */
    if                          /*cond _838sw9thRfn_03qQ7lMn8Ij */
      /*when _2aMZ0ZBgKj2_35QKBjbmq4w: */
      (                         /*objhasdictpayl: */
        objhasdictpayl_BM ((_.o_7n2SLLuWOjH_4ArhFUjmckz)))
      {
        if                      /*cond _58oNVcHAUe4_3Z3PsPWQQWC */
          /*when _5Zj20zoTMgi_2wX9L155Qet: */
          ( /*isstring: */ isstring_BM (_.v_167WczZjWtG_3FofhJxQWJi))
          {
            {                   // start cexpansion _7T2FZv58UYu_1HHqslZTor2 - objdictputpayl    
/*objdictputpayl:*/
              objdictputpayl_BM ((_.o_7n2SLLuWOjH_4ArhFUjmckz),
                                 (_.v_167WczZjWtG_3FofhJxQWJi),
                                 (_.v_5jRQCD1qTko_61I0j04ugAA));
            }                   // end cexpansion _7T2FZv58UYu_1HHqslZTor2 - objdictputpayl    
            /*return _3Q8xwomyj4D_36oIs4VyEfB: */ _.
              v_3qw9bnATIhq_8loBraLeXzQ =
              // returned   
              _.o_7n2SLLuWOjH_4ArhFUjmckz;
            goto epilog_2bZ4BfCci5V_3WTzG7V25y4;

          }                     //endwhen _5Zj20zoTMgi_2wX9L155Qet   
/*endcond _58oNVcHAUe4_3Z3PsPWQQWC*/

      }                         //endwhen _2aMZ0ZBgKj2_35QKBjbmq4w  
/*endcond _838sw9thRfn_03qQ7lMn8Ij*/

/* !endingblock _0VJTIqFfNXf_5chzuIlqcJP */
    goto endblock__0VJTIqFfNXf_5chzuIlqcJP;
  endblock__0VJTIqFfNXf_5chzuIlqcJP:;
  }
  /*-block _0VJTIqFfNXf_5chzuIlqcJP */

epilog_2bZ4BfCci5V_3WTzG7V25y4:__attribute__ ((unused));
  // routine _2bZ4BfCci5V_3WTzG7V25y4 epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _2bZ4BfCci5V_3WTzG7V25y4 routine#5 _2bZ4BfCci5V_3WTzG7V25y4




value_tyBM crout_3iiht57Wrs1_5NbiUi27oBn_BM     //#6
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[10] /*|_3iiht57Wrs1_5NbiUi27oBn */ ;
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
}                               // end _3iiht57Wrs1_5NbiUi27oBn routine#6 _3iiht57Wrs1_5NbiUi27oBn




value_tyBM crout_3vI0Qc3FHQG_1g4fmHYkxSA_BM     //#7
  (struct stackframe_stBM * stkf,       //
//!jsmodule compiler: compile o_jsmodule into o_strbuf
   // 2 arguments
   const value_tyBM arg0,       // o_jsmodule
   const value_tyBM arg1,       // o_strbuf
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _3vI0Qc3FHQG_1g4fmHYkxSA
  struct frame_3vI0Qc3FHQG_1g4fmHYkxSA_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 5 local values:
    objectval_tyBM *o_2TaoEvH5OQU_8nKYBgAvkmW;  // o_jscurcomp
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    objectval_tyBM *o_41F1rKwGbaA_30OJWKsqNWy;  // o_strbuf
    objectval_tyBM *o_4JKd986pvM4_6yBzeeI40vW;  // o_jsprepmod
    objectval_tyBM *o_5V0w37YnN4F_8dZ6I79V60O;  // o_jsmodule
    /// 2 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
  } _;
  memset (&_, 0, sizeof (struct frame_3vI0Qc3FHQG_1g4fmHYkxSA_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 5;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[11] /*|_3vI0Qc3FHQG_1g4fmHYkxSA */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // locking 3:
  objectval_tyBM *locked_1flY7i4N8iV_5T74FnYd6Ee = NULL;        // _1flY7i4N8iV_5T74FnYd6Ee
  objectval_tyBM *locked_3bsFDNiUKNe_9NjWM3BxFSt = NULL;        // _3bsFDNiUKNe_9NjWM3BxFSt
  objectval_tyBM *locked_6mmsQZI3VuT_9OYUPR9OrsR = NULL;        // _6mmsQZI3VuT_9OYUPR9OrsR
  // fetch 2 arguments:
  _.o_5V0w37YnN4F_8dZ6I79V60O = objectcast_BM (arg0);
  _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg1);
  // fetched 2 arguments.
  // no closed values in _3vI0Qc3FHQG_1g4fmHYkxSA.
  // routine _3vI0Qc3FHQG_1g4fmHYkxSA body:

startblock__7pji8vKR2XX_3psoWkfPtL2:__attribute__ ((unused));
  {                             /* +block _7pji8vKR2XX_3psoWkfPtL2 */

    {                           // run _38PFPbvZ5xw_5Mu74JCp6p5 
/*start of jsmodule compiler*/
      DBGPRINTF_BM ("jsmodule compiler start: o_jsmodule=%s o_strbuf=%s",
                    objectdbg_BM (_.o_5V0w37YnN4F_8dZ6I79V60O),
                    objectdbg1_BM (_.o_41F1rKwGbaA_30OJWKsqNWy));;
    }                           // end run _38PFPbvZ5xw_5Mu74JCp6p5 


    _.o_4JKd986pvM4_6yBzeeI40vW =       //assign _553O5e7mqRq_0Dfxte6gVmp  
/*makeobj:*/ makeobj_BM ();


    {                           // start cexpansion _5aEEfO7SZge_3wLzFCRCBpn - objputclass  
      /*objputclass: */ objputclass_BM ((_.o_4JKd986pvM4_6yBzeeI40vW),
                                        ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM
                                          [30]
                                          /*|jsmodule_preparation_object */
                                         )));
    }                           // end cexpansion _5aEEfO7SZge_3wLzFCRCBpn - objputclass  


    {                           // start cexpansion _8owvpghf95c_70WEDPAsJGV - objputattr  
      /*objputattr: */ objputattr_BM ((_.o_4JKd986pvM4_6yBzeeI40vW),
                                      ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[7]
                                        /*!for */ )),
                                      (_.o_5V0w37YnN4F_8dZ6I79V60O));
    }                           // end cexpansion _8owvpghf95c_70WEDPAsJGV - objputattr  



    {                           // begin lockobj _1flY7i4N8iV_5T74FnYd6Ee 
      objectval_tyBM *curlockedob_1flY7i4N8iV_5T74FnYd6Ee =
        (_.o_5V0w37YnN4F_8dZ6I79V60O);
      if (objlock_BM (curlockedob_1flY7i4N8iV_5T74FnYd6Ee))
        {
          locked_1flY7i4N8iV_5T74FnYd6Ee =
            curlockedob_1flY7i4N8iV_5T74FnYd6Ee;


          {                     // begin lockobj _3bsFDNiUKNe_9NjWM3BxFSt 
            objectval_tyBM *curlockedob_3bsFDNiUKNe_9NjWM3BxFSt =
              (_.o_4JKd986pvM4_6yBzeeI40vW);
            if (objlock_BM (curlockedob_3bsFDNiUKNe_9NjWM3BxFSt))
              {
                locked_3bsFDNiUKNe_9NjWM3BxFSt =
                  curlockedob_3bsFDNiUKNe_9NjWM3BxFSt;


                {               // run _8g9Ms38jPls_58zTM8Ayy1u 
/*dbgprintf after lock o_jsprepmod*/
                  DBGPRINTF_BM
                    ("jsmodule compiler: after lock o_jsmodule=%s o_jsprepmod=%s",
                     objectdbg_BM (_.o_5V0w37YnN4F_8dZ6I79V60O),
                     objectdbg1_BM (_.o_4JKd986pvM4_6yBzeeI40vW));
                }               // end run _8g9Ms38jPls_58zTM8Ayy1u 

                _.n_833x2jYqhZh_8vDIuJhwz1k =   //assign _0qK1TfyxaEU_0sLvlnHs4UT  
/*objnbcomps:*/ objnbcomps_BM (_.o_5V0w37YnN4F_8dZ6I79V60O);

                _.n_2W7Ckt2WxEM_4NVYgEWE73B =   //assign _4opDguH6Knp_1NiX0hlpo7s  
                  0;


//// +while _839zJGrmf26_2hQq2r1ehkR 
              startblock__839zJGrmf26_2hQq2r1ehkR:     /*+!while */
                ;
                {               /* +while _839zJGrmf26_2hQq2r1ehkR */
                  if (!( /*while _839zJGrmf26_2hQq2r1ehkR cond: */ ( /*less_int: */ (_.n_2W7Ckt2WxEM_4NVYgEWE73B) < (_.n_833x2jYqhZh_8vDIuJhwz1k))))    //: testwhile _839zJGrmf26_2hQq2r1ehkR failing   
                    goto endblock__839zJGrmf26_2hQq2r1ehkR;     //failwhile   
// while _839zJGrmf26_2hQq2r1ehkR body:   
// while _839zJGrmf26_2hQq2r1ehkR comp#0:  
                  _.o_2TaoEvH5OQU_8nKYBgAvkmW = //assign _0pkGibtvusS_9tl9TNLRL7F   
                    /*val_to_object: */
                    objectcast_BM (     /*objgetcomp: */
                                    objgetcomp_BM ((_.o_5V0w37YnN4F_8dZ6I79V60O), (_.n_2W7Ckt2WxEM_4NVYgEWE73B)));
// while _839zJGrmf26_2hQq2r1ehkR comp#1:  
                  if            /*cond _4Y28SaFq44X_6qJmQdN4DMt */
                                                                /*when _71N9lq8UKd3_9zYq6i873Dp: */ (
                                                                /*not: */
                                                                                                      (!(       /*is_objectv */
                                                                                                          isobject_BM
                                                                                                          (_.
                                                                                                           o_2TaoEvH5OQU_8nKYBgAvkmW))))
                    {
//failure _6pp3g7GLuae_7OF8KezKzvx    
                      PLACEDFAILURE_BM (__LINE__,       /*failreason: */
                                        ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM
                                          [22] /*|failure_non_object */ )),
                                        /*failplace: */
                                        (       /*modconst: */
                                          (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[21]       /*|_6pp3g7GLuae_7OF8KezKzvx */
                                          )),
                                        ((struct stackframe_stBM *) &_));

                    }           //endwhen _71N9lq8UKd3_9zYq6i873Dp   
/*endcond _4Y28SaFq44X_6qJmQdN4DMt*/
// while _839zJGrmf26_2hQq2r1ehkR comp#2:  

                  {             // begin lockobj _6mmsQZI3VuT_9OYUPR9OrsR  
                    objectval_tyBM *curlockedob_6mmsQZI3VuT_9OYUPR9OrsR =
                      (_.o_2TaoEvH5OQU_8nKYBgAvkmW);
                    if (objlock_BM (curlockedob_6mmsQZI3VuT_9OYUPR9OrsR))
                      {
                        locked_6mmsQZI3VuT_9OYUPR9OrsR =
                          curlockedob_6mmsQZI3VuT_9OYUPR9OrsR;

                        if      /*cond _2d1yOe9s0xF_5zIO2nTexNd */
                                                                /*when _1icbJmDuvUd_03TJdGfrgqp: */ (
                                                                /*not: */
                                                                                                      (!(       /*objectisinstance: */
                                                                                                          objectisinstance_BM
                                                                                                          ((_.o_2TaoEvH5OQU_8nKYBgAvkmW), ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[25] /*!jscript_toplevel_object */ ))))))
                          {
//failure _4jwFGdaECBb_6dsBLTMoG9j    
                            PLACEDFAILURE_BM (__LINE__, /*failreason: */
                                              (((value_tyBM) makenode3_BM (
                                                                            /*make_node conn: */
                                                                            ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[17] /*!failure_bad_class */ )),
                                                                            (_.o_2TaoEvH5OQU_8nKYBgAvkmW), ( /*taggedint: */ taggedint_BM (_.n_2W7Ckt2WxEM_4NVYgEWE73B)))),
                                               /*failplace: */
                                               (        /*modconst: */
                                                 (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[15]
                                                  /*|_4jwFGdaECBb_6dsBLTMoG9j */
                                                  )),
                                               ((struct stackframe_stBM *)
                                                &_));
                                              } //endwhen _1icbJmDuvUd_03TJdGfrgqp   
/*endcond _2d1yOe9s0xF_5zIO2nTexNd*/

                                              objunlock_BM
                                              (locked_6mmsQZI3VuT_9OYUPR9OrsR),
                                              locked_6mmsQZI3VuT_9OYUPR9OrsR =
                                              NULL;
                                              }
                                              } // end objlock _6mmsQZI3VuT_9OYUPR9OrsR  

                                              goto startblock__839zJGrmf26_2hQq2r1ehkR; // repeatwhile  
                endblock__839zJGrmf26_2hQq2r1ehkR:     /*endingwhile */
                                              ;}
  /*-while _839zJGrmf26_2hQq2r1ehkR */

                                              objunlock_BM
                                              (locked_3bsFDNiUKNe_9NjWM3BxFSt),
                                              locked_3bsFDNiUKNe_9NjWM3BxFSt =
                                              NULL;
                                              }
                                              } // end objlock _3bsFDNiUKNe_9NjWM3BxFSt 

                                              objunlock_BM
                                              (locked_1flY7i4N8iV_5T74FnYd6Ee),
                                              locked_1flY7i4N8iV_5T74FnYd6Ee =
                                              NULL;
                                              }
                                              } // end objlock _1flY7i4N8iV_5T74FnYd6Ee 
/* !endingblock _7pji8vKR2XX_3psoWkfPtL2 */
                                              goto
                                              endblock__7pji8vKR2XX_3psoWkfPtL2;
  endblock__7pji8vKR2XX_3psoWkfPtL2:         ;
                                              }
  /*-block _7pji8vKR2XX_3psoWkfPtL2 */

epilog_3vI0Qc3FHQG_1g4fmHYkxSA:              __attribute__ ((unused)); // routine _3vI0Qc3FHQG_1g4fmHYkxSA epilogue:
                                              // unlocking 3:
                                              if (locked_1flY7i4N8iV_5T74FnYd6Ee != NULL) objunlock_BM (locked_1flY7i4N8iV_5T74FnYd6Ee), locked_1flY7i4N8iV_5T74FnYd6Ee = NULL; // _1flY7i4N8iV_5T74FnYd6Ee
                                              if (locked_3bsFDNiUKNe_9NjWM3BxFSt != NULL) objunlock_BM (locked_3bsFDNiUKNe_9NjWM3BxFSt), locked_3bsFDNiUKNe_9NjWM3BxFSt = NULL; // _3bsFDNiUKNe_9NjWM3BxFSt
                                              if (locked_6mmsQZI3VuT_9OYUPR9OrsR != NULL) objunlock_BM (locked_6mmsQZI3VuT_9OYUPR9OrsR), locked_6mmsQZI3VuT_9OYUPR9OrsR = NULL; // _6mmsQZI3VuT_9OYUPR9OrsR
                                              if (stkf) stkf->stkfram_callfun = NULL; return _.v_3qw9bnATIhq_8loBraLeXzQ;}      // end _3vI0Qc3FHQG_1g4fmHYkxSA routine#7 _3vI0Qc3FHQG_1g4fmHYkxSA




                                              value_tyBM crout_3yQlckX4DRh_4b9l9FBSSSL_BM       //#8+
                                              (struct stackframe_stBM * stkf,   // same_as_closed_minifunc
//!return argument if it is the same as the closed value
                                               // 1 arguments
                                               const value_tyBM arg0,   // v_arg
                                               const value_tyBM arg1_
                                               __attribute__ ((unused)),
                                               const value_tyBM arg2_
                                               __attribute__ ((unused)),
                                               const value_tyBM arg3_
                                               __attribute__ ((unused)),
                                               const quasinode_tyBM *
                                               restargs_
                                               __attribute__ ((unused)))
                                              { // start of same_as_closed_minifunc
                                              struct frame_3yQlckX4DRh_4b9l9FBSSSL_BMst
                                              {
                                              typedhead_tyBM stkfram_head;
                                              struct stackframe_stBM
                                              *stkfram_prev;
                                              objectval_tyBM * stkfram_descr;
                                              value_tyBM stkfram_callfun;
                                              int stkfram_state;
                                              int stkfram_extra;
                                              /// 3 local values:
                                              value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;     // v_r
                                              value_tyBM v_4Q4WBLjAPTV_5WVLmhAvCJY;     // v_arg
                                              value_tyBM v_5EEITf6IFH7_4DbKG99zcPW;     // v1
                                              /// 0 local numbers:
                                              } _;
                                              memset (&_, 0,
                                                      sizeof (struct
                                                              frame_3yQlckX4DRh_4b9l9FBSSSL_BMst));
                                              _.stkfram_head.htyp =
                                              typayl_StackFrame_BM;
                                              _.stkfram_head.hgc = 0;
                                              _.stkfram_head.rlen = 3;
                                              _.stkfram_descr =
                                              constob_3BFt4NfJmZC_7iYi2dwM38B_BM
                                              [12]
                                              /*|same_as_closed_minifunc */ ;
                                              ASSERT_BM (!stkf
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_StackFrame_BM
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_SpecialFrame_BM);
                                              _.stkfram_prev = stkf;
                                              // fetch 1 arguments:
                                              _.v_4Q4WBLjAPTV_5WVLmhAvCJY =
                                              arg0;
                                              // fetched 1 arguments.
                                              { // fetch 1 closed values in same_as_closed_minifunc:
                                              const closure_tyBM * callclos_3yQlckX4DRh_4b9l9FBSSSL = (stkf && stkf->stkfram_pA.htyp == typayl_StackFrame_BM) ? (closurecast_BM (stkf->stkfram_callfun)) : NULL; unsigned nbclosed_3yQlckX4DRh_4b9l9FBSSSL = closurewidth_BM ((const value_tyBM) callclos_3yQlckX4DRh_4b9l9FBSSSL); if (nbclosed_3yQlckX4DRh_4b9l9FBSSSL > 0) _.v_5EEITf6IFH7_4DbKG99zcPW = callclos_3yQlckX4DRh_4b9l9FBSSSL->nodt_sons[0];}    // fetched 1 closed values in _3yQlckX4DRh_4b9l9FBSSSL.
                                              // routine _3yQlckX4DRh_4b9l9FBSSSL body:

startblock__8seRhfNtGTR_4rOgARd0hVM:         __attribute__ ((unused));
                                              { /* +block _8seRhfNtGTR_4rOgARd0hVM */
                                              if        /*cond _8aGb7reuzLX_3sgkigRSOpu */
                                              /*when _5Ad0ZdurQuC_1A6Kn7qopbm: */
                                              ((        /*same_val: */
                                                 (_.
                                                  v_5EEITf6IFH7_4DbKG99zcPW)
                                                 ==
                                                 (_.
                                                  v_4Q4WBLjAPTV_5WVLmhAvCJY)))
                                              {
                                              /*return _1qFf9AUO2W9_8azcQljqB3I: */
                                              _.v_3qw9bnATIhq_8loBraLeXzQ =
                                              // returned  
                                              _.v_4Q4WBLjAPTV_5WVLmhAvCJY; goto epilog_3yQlckX4DRh_4b9l9FBSSSL;}        //endwhen _5Ad0ZdurQuC_1A6Kn7qopbm  
/*endcond _8aGb7reuzLX_3sgkigRSOpu*/

/* !endingblock _8seRhfNtGTR_4rOgARd0hVM */
goto endblock__8seRhfNtGTR_4rOgARd0hVM; endblock__8seRhfNtGTR_4rOgARd0hVM:;}
  /*-block _8seRhfNtGTR_4rOgARd0hVM */

epilog_3yQlckX4DRh_4b9l9FBSSSL:              __attribute__ ((unused)); // routine _3yQlckX4DRh_4b9l9FBSSSL epilogue:
                                              if (stkf) stkf->stkfram_callfun = NULL; return _.v_3qw9bnATIhq_8loBraLeXzQ;}      // end _3yQlckX4DRh_4b9l9FBSSSL routine#8 same_as_closed_minifunc




                                              value_tyBM crout_3HAeZZQ0q7b_7qyDsekaz7Y_BM       //#9
                                              (struct stackframe_stBM * stkf,   //
//!clear°list_object minifunc
                                               // 1 arguments
                                               const value_tyBM arg0,   // o1
                                               const value_tyBM arg1_
                                               __attribute__ ((unused)),
                                               const value_tyBM arg2_
                                               __attribute__ ((unused)),
                                               const value_tyBM arg3_
                                               __attribute__ ((unused)),
                                               const quasinode_tyBM *
                                               restargs_
                                               __attribute__ ((unused)))
                                              { // start of _3HAeZZQ0q7b_7qyDsekaz7Y
                                              struct frame_3HAeZZQ0q7b_7qyDsekaz7Y_BMst
                                              {
                                              typedhead_tyBM stkfram_head;
                                              struct stackframe_stBM
                                              *stkfram_prev;
                                              objectval_tyBM * stkfram_descr;
                                              value_tyBM stkfram_callfun;
                                              int stkfram_state;
                                              int stkfram_extra;
                                              /// 2 local values:
                                              value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;     // v_r
                                              objectval_tyBM * o_97rnxb0KFqq_44veN75DG2E;       // o1
                                              /// 0 local numbers:
                                              } _;
                                              memset (&_, 0,
                                                      sizeof (struct
                                                              frame_3HAeZZQ0q7b_7qyDsekaz7Y_BMst));
                                              _.stkfram_head.htyp =
                                              typayl_StackFrame_BM;
                                              _.stkfram_head.hgc = 0;
                                              _.stkfram_head.rlen = 2;
                                              _.stkfram_descr =
                                              constob_3BFt4NfJmZC_7iYi2dwM38B_BM
                                              [13]
                                              /*|_3HAeZZQ0q7b_7qyDsekaz7Y */ ;
                                              ASSERT_BM (!stkf
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_StackFrame_BM
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_SpecialFrame_BM);
                                              _.stkfram_prev = stkf;
                                              // fetch 1 arguments:
                                              _.o_97rnxb0KFqq_44veN75DG2E =
                                              objectcast_BM (arg0);
                                              // fetched 1 arguments.
                                              // no closed values in _3HAeZZQ0q7b_7qyDsekaz7Y.
                                              // routine _3HAeZZQ0q7b_7qyDsekaz7Y body:
startblock__4wSCE1PqaMS_2XYzFgB0waZ:         __attribute__ ((unused));
                                              { /* +block _4wSCE1PqaMS_2XYzFgB0waZ */
                                              if        /*cond _3eTPhEBroKh_3F8wQMduy1J */
                                              /*when _0IRlnxNrCtM_6W21xnJjzmn: */
                                              ( /*objputlistpayl: */
                                               objputlistpayl_BM (_.
                                                                  o_97rnxb0KFqq_44veN75DG2E))
                                              {
                                              /*return _516tXf2eeNb_8VGPLYEode5: */
                                              _.v_3qw9bnATIhq_8loBraLeXzQ =
                                              // returned  
                                              _.o_97rnxb0KFqq_44veN75DG2E; goto epilog_3HAeZZQ0q7b_7qyDsekaz7Y;}        //endwhen _0IRlnxNrCtM_6W21xnJjzmn  
/*endcond _3eTPhEBroKh_3F8wQMduy1J*/

/* !endingblock _4wSCE1PqaMS_2XYzFgB0waZ */
goto endblock__4wSCE1PqaMS_2XYzFgB0waZ; endblock__4wSCE1PqaMS_2XYzFgB0waZ:;}
  /*-block _4wSCE1PqaMS_2XYzFgB0waZ */

epilog_3HAeZZQ0q7b_7qyDsekaz7Y:              __attribute__ ((unused)); // routine _3HAeZZQ0q7b_7qyDsekaz7Y epilogue:
                                              if (stkf) stkf->stkfram_callfun = NULL; return _.v_3qw9bnATIhq_8loBraLeXzQ;}      // end _3HAeZZQ0q7b_7qyDsekaz7Y routine#9 _3HAeZZQ0q7b_7qyDsekaz7Y




                                              value_tyBM crout_4iEFTEcHxeb_6lH464uFkTC_BM       //#10+
                                              (struct stackframe_stBM * stkf,   // equal_to_closed_minifunc
//!return argument if it is the same as the closed value
                                               // 1 arguments
                                               const value_tyBM arg0,   // v_arg
                                               const value_tyBM arg1_
                                               __attribute__ ((unused)),
                                               const value_tyBM arg2_
                                               __attribute__ ((unused)),
                                               const value_tyBM arg3_
                                               __attribute__ ((unused)),
                                               const quasinode_tyBM *
                                               restargs_
                                               __attribute__ ((unused)))
                                              { // start of equal_to_closed_minifunc
                                              struct frame_4iEFTEcHxeb_6lH464uFkTC_BMst
                                              {
                                              typedhead_tyBM stkfram_head;
                                              struct stackframe_stBM
                                              *stkfram_prev;
                                              objectval_tyBM * stkfram_descr;
                                              value_tyBM stkfram_callfun;
                                              int stkfram_state;
                                              int stkfram_extra;
                                              /// 3 local values:
                                              value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;     // v_r
                                              value_tyBM v_4Q4WBLjAPTV_5WVLmhAvCJY;     // v_arg
                                              value_tyBM v_5EEITf6IFH7_4DbKG99zcPW;     // v1
                                              /// 0 local numbers:
                                              } _;
                                              memset (&_, 0,
                                                      sizeof (struct
                                                              frame_4iEFTEcHxeb_6lH464uFkTC_BMst));
                                              _.stkfram_head.htyp =
                                              typayl_StackFrame_BM;
                                              _.stkfram_head.hgc = 0;
                                              _.stkfram_head.rlen = 3;
                                              _.stkfram_descr =
                                              constob_3BFt4NfJmZC_7iYi2dwM38B_BM
                                              [14]
                                              /*|equal_to_closed_minifunc */ ;
                                              ASSERT_BM (!stkf
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_StackFrame_BM
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_SpecialFrame_BM);
                                              _.stkfram_prev = stkf;
                                              // fetch 1 arguments:
                                              _.v_4Q4WBLjAPTV_5WVLmhAvCJY =
                                              arg0;
                                              // fetched 1 arguments.
                                              { // fetch 1 closed values in equal_to_closed_minifunc:
                                              const closure_tyBM * callclos_4iEFTEcHxeb_6lH464uFkTC = (stkf && stkf->stkfram_pA.htyp == typayl_StackFrame_BM) ? (closurecast_BM (stkf->stkfram_callfun)) : NULL; unsigned nbclosed_4iEFTEcHxeb_6lH464uFkTC = closurewidth_BM ((const value_tyBM) callclos_4iEFTEcHxeb_6lH464uFkTC); if (nbclosed_4iEFTEcHxeb_6lH464uFkTC > 0) _.v_5EEITf6IFH7_4DbKG99zcPW = callclos_4iEFTEcHxeb_6lH464uFkTC->nodt_sons[0];}    // fetched 1 closed values in _4iEFTEcHxeb_6lH464uFkTC.
                                              // routine _4iEFTEcHxeb_6lH464uFkTC body:

startblock__60FKeHfNUo3_9OSN4Cqm8zI:         __attribute__ ((unused));
                                              { /* +block _60FKeHfNUo3_9OSN4Cqm8zI */
                                              if        /*cond _7wPbopKi9ZB_1ifk5LEKSqu */
                                              /*when _8hUpJbSLQUS_88aqogJAi2Q: */
                                              ((        /*equal_val: */
                                                 valequal_BM ((_.
                                                               v_5EEITf6IFH7_4DbKG99zcPW),
                                                              (_.
                                                               v_4Q4WBLjAPTV_5WVLmhAvCJY))))
                                              {
                                              /*return _3dJ2b1hmBuw_7Pu5iDjauLr: */
                                              _.v_3qw9bnATIhq_8loBraLeXzQ =
                                              // returned  
                                              _.v_5EEITf6IFH7_4DbKG99zcPW; goto epilog_4iEFTEcHxeb_6lH464uFkTC;}        //endwhen _8hUpJbSLQUS_88aqogJAi2Q  
/*endcond _7wPbopKi9ZB_1ifk5LEKSqu*/

/* !endingblock _60FKeHfNUo3_9OSN4Cqm8zI */
goto endblock__60FKeHfNUo3_9OSN4Cqm8zI; endblock__60FKeHfNUo3_9OSN4Cqm8zI:;}
  /*-block _60FKeHfNUo3_9OSN4Cqm8zI */

epilog_4iEFTEcHxeb_6lH464uFkTC:              __attribute__ ((unused)); // routine _4iEFTEcHxeb_6lH464uFkTC epilogue:
                                              if (stkf) stkf->stkfram_callfun = NULL; return _.v_3qw9bnATIhq_8loBraLeXzQ;}      // end _4iEFTEcHxeb_6lH464uFkTC routine#10 equal_to_closed_minifunc




                                              value_tyBM crout_4qlegfkPzrC_17skUfJP7v8_BM       //#11
                                              (struct stackframe_stBM * stkf,   //
//!dump_data°dict_object minifun
                                               // 3 arguments
                                               const value_tyBM arg0,   // odict
                                               const value_tyBM arg1,   // odumper
                                               const value_tyBM arg2,   // osbuf
                                               const value_tyBM arg3_
                                               __attribute__ ((unused)),
                                               const quasinode_tyBM *
                                               restargs_
                                               __attribute__ ((unused)))
                                              { // start of _4qlegfkPzrC_17skUfJP7v8
                                              struct frame_4qlegfkPzrC_17skUfJP7v8_BMst
                                              {
                                              typedhead_tyBM stkfram_head;
                                              struct stackframe_stBM
                                              *stkfram_prev;
                                              objectval_tyBM * stkfram_descr;
                                              value_tyBM stkfram_callfun;
                                              int stkfram_state;
                                              int stkfram_extra;
                                              /// 6 local values:
                                              value_tyBM v_167WczZjWtG_3FofhJxQWJi;     // v_str
                                              objectval_tyBM * o_3cTC8W7d75H_1vteOyEoAao;       // odumper
                                              value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;     // v_r
                                              value_tyBM v_5jRQCD1qTko_61I0j04ugAA;     // v_val
                                              objectval_tyBM * o_6opEz55NyNu_3JKpBgxLijw;       // osbuf
                                              objectval_tyBM * o_7n2SLLuWOjH_4ArhFUjmckz;       // odict
                                              /// 0 local numbers:
                                              } _;
                                              memset (&_, 0,
                                                      sizeof (struct
                                                              frame_4qlegfkPzrC_17skUfJP7v8_BMst));
                                              _.stkfram_head.htyp =
                                              typayl_StackFrame_BM;
                                              _.stkfram_head.hgc = 0;
                                              _.stkfram_head.rlen = 6;
                                              _.stkfram_descr =
                                              constob_3BFt4NfJmZC_7iYi2dwM38B_BM
                                              [1]
                                              /*|_4qlegfkPzrC_17skUfJP7v8 */ ;
                                              ASSERT_BM (!stkf
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_StackFrame_BM
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_SpecialFrame_BM);
                                              _.stkfram_prev = stkf;
                                              // fetch 3 arguments:
                                              _.o_7n2SLLuWOjH_4ArhFUjmckz =
                                              objectcast_BM (arg0);
                                              _.o_3cTC8W7d75H_1vteOyEoAao =
                                              objectcast_BM (arg1);
                                              _.o_6opEz55NyNu_3JKpBgxLijw =
                                              objectcast_BM (arg2);
                                              // fetched 3 arguments.
                                              // no closed values in _4qlegfkPzrC_17skUfJP7v8.
                                              // routine _4qlegfkPzrC_17skUfJP7v8 body:
startblock__3oMW0T4HlXx_8r7NLpyK1J8:         __attribute__ ((unused));
                                              { /* +block _3oMW0T4HlXx_8r7NLpyK1J8 */
                                              { // start cexpansion _4QfB21rab5P_26PMGm9N4Dl - objstrbufferclearindentpayl  
/*objstrbufferclearindentpayl:*/
                                              objstrbufferclearindentpayl_BM ((_.o_6opEz55NyNu_3JKpBgxLijw));}  // end cexpansion _4QfB21rab5P_26PMGm9N4Dl - objstrbufferclearindentpayl  


                                              { // start cexpansion _15WmvoAu2Kx_9K4XFDxMyU4 - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/
                                              objstrbufferappendcstrpayl_BM ((_.o_6opEz55NyNu_3JKpBgxLijw), ("!~ todo (~\n"));} // end cexpansion _15WmvoAu2Kx_9K4XFDxMyU4 - objstrbufferappendcstrpayl  


                                              _.v_167WczZjWtG_3FofhJxQWJi =     //assign _5mCmWSYOW7T_4G9YRC6tvRf  
/*objdictfirstkeypayl:*/
                                              (value_tyBM)
                                              objdictfirstkeypayl_BM ((_.
                                                                       o_7n2SLLuWOjH_4ArhFUjmckz));
                                              { // start cexpansion _3pnZ6MbNCtX_2IZKwMgn9y1 - objstrbuffersetindentpayl  
/*objstrbuffersetindentpayl:*/
                                              objstrbuffersetindentpayl_BM ((_.o_6opEz55NyNu_3JKpBgxLijw), (1));}       // end cexpansion _3pnZ6MbNCtX_2IZKwMgn9y1 - objstrbuffersetindentpayl  



                                              { // run _40XgQGIUZQY_246JbHmppCN 
                                              (send3_BM
                                               (((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[28] /*|clear */ )), /*sel: */ ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[6] /*|dump_value */ )), ((struct stackframe_stBM *) &_),
                                                (_.o_6opEz55NyNu_3JKpBgxLijw), (_.o_3cTC8W7d75H_1vteOyEoAao), (((value_tyBM) 0x3        /*!1 */
                                                                                                               ))));}   // end run _40XgQGIUZQY_246JbHmppCN 



//// +while _9gJT0jotyox_8JQNlJn3qh6 
  startblock__9gJT0jotyox_8JQNlJn3qh6: /*+!while */
                                              ;
                                              { /* +while _9gJT0jotyox_8JQNlJn3qh6 */
                                              if (!( /*while _9gJT0jotyox_8JQNlJn3qh6 cond: *//*isstring: */ isstring_BM (_.v_167WczZjWtG_3FofhJxQWJi)))        //: testwhile _9gJT0jotyox_8JQNlJn3qh6 failing   
                                              goto endblock__9gJT0jotyox_8JQNlJn3qh6;   //failwhile   
// while _9gJT0jotyox_8JQNlJn3qh6 body:   
// while _9gJT0jotyox_8JQNlJn3qh6 comp#0:  
                                              _.v_5jRQCD1qTko_61I0j04ugAA =     //assign _6mzawBHvh0i_13Wpf0Lmgig   
/*objdictgetpayl:*/
                                              objdictgetpayl_BM
                                              ((_.o_7n2SLLuWOjH_4ArhFUjmckz),
                                               stringcast_BM (_.
                                                              v_167WczZjWtG_3FofhJxQWJi));
// while _9gJT0jotyox_8JQNlJn3qh6 comp#1:  
                                              { // start cexpansion _8QIiIH1xKGD_0ByaWRWwCAO - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/
                                              objstrbufferappendcstrpayl_BM ((_.o_6opEz55NyNu_3JKpBgxLijw), (" !&\n"));}        // end cexpansion _8QIiIH1xKGD_0ByaWRWwCAO - objstrbufferappendcstrpayl   
// while _9gJT0jotyox_8JQNlJn3qh6 comp#2:  

                                              { // run _4BOu5jhqyAD_3HGfVAY5hFx  
                                              (send3_BM
                                               (((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[29] /*|put */ )), /*sel: */ ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[6] /*|dump_value */ )), ((struct stackframe_stBM *) &_),
                                                (_.o_6opEz55NyNu_3JKpBgxLijw), (_.o_3cTC8W7d75H_1vteOyEoAao), (((value_tyBM) 0x3        /*!1 */
                                                                                                               ))));}   // end run _4BOu5jhqyAD_3HGfVAY5hFx  
// while _9gJT0jotyox_8JQNlJn3qh6 comp#3:  
                                              { // start cexpansion _8TB4Kpuoc3f_0Dhb8Tm0xrJ - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/
                                              objstrbufferappendcstrpayl_BM ((_.o_6opEz55NyNu_3JKpBgxLijw), ("\t"));}   // end cexpansion _8TB4Kpuoc3f_0Dhb8Tm0xrJ - objstrbufferappendcstrpayl   
// while _9gJT0jotyox_8JQNlJn3qh6 comp#4:  

                                              { // run _634ecJogXve_7sycLMYAfdT  
                                              (send3_BM
                                               ((_.v_167WczZjWtG_3FofhJxQWJi),
                                                /*sel: */
                                                ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[6] /*|dump_value */ )),
                                                ((struct stackframe_stBM *) &_), (_.o_6opEz55NyNu_3JKpBgxLijw), (_.o_3cTC8W7d75H_1vteOyEoAao), (((value_tyBM) 0x3       /*!1 */
                                                                                                                                                ))));}  // end run _634ecJogXve_7sycLMYAfdT  
// while _9gJT0jotyox_8JQNlJn3qh6 comp#5:  
                                              { // start cexpansion _3fFn9uY0hNS_2YU6fn9QOSh - objstrbuffernewlinepayl   
/*objstrbuffernewlinepayl:*/
                                              objstrbuffernewlinepayl_BM (_.o_6opEz55NyNu_3JKpBgxLijw);}        // end cexpansion _3fFn9uY0hNS_2YU6fn9QOSh - objstrbuffernewlinepayl   
// while _9gJT0jotyox_8JQNlJn3qh6 comp#6:  

                                              { // run _1aLOinNfz2n_0WpWbC84CAL  
                                              (send3_BM
                                               ((_.v_5jRQCD1qTko_61I0j04ugAA),
                                                /*sel: */
                                                ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[6] /*|dump_value */ )),
                                                ((struct stackframe_stBM *) &_), (_.o_6opEz55NyNu_3JKpBgxLijw), (_.o_3cTC8W7d75H_1vteOyEoAao), (((value_tyBM) 0x3       /*!1 */
                                                                                                                                                ))));}  // end run _1aLOinNfz2n_0WpWbC84CAL  
// while _9gJT0jotyox_8JQNlJn3qh6 comp#7:  
                                              _.v_167WczZjWtG_3FofhJxQWJi =     //assign _5VEaDZcNd5x_9CGhCudUvGs   
/*objdictkeyafterpayl:*/
                                              (value_tyBM) objdictkeyafterpayl_BM ((_.o_7n2SLLuWOjH_4ArhFUjmckz), stringcast_BM (_.v_167WczZjWtG_3FofhJxQWJi)); goto startblock__9gJT0jotyox_8JQNlJn3qh6;       // repeatwhile  
    endblock__9gJT0jotyox_8JQNlJn3qh6: /*endingwhile */
                                              ;}
  /*-while _9gJT0jotyox_8JQNlJn3qh6 */


                                              { // start cexpansion _1UfGW420Q3X_3osvimj3Myj - objstrbufferclearindentpayl  
/*objstrbufferclearindentpayl:*/
                                              objstrbufferclearindentpayl_BM ((_.o_6opEz55NyNu_3JKpBgxLijw));}  // end cexpansion _1UfGW420Q3X_3osvimj3Myj - objstrbufferclearindentpayl  


                                              { // start cexpansion _3urNBgu4IsT_4oyZ9YgJmbx - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/
                                              objstrbufferappendcstrpayl_BM ((_.o_6opEz55NyNu_3JKpBgxLijw), ("\n~)\n"));}       // end cexpansion _3urNBgu4IsT_4oyZ9YgJmbx - objstrbufferappendcstrpayl  


                                              /*return _9IH3fglmCon_9bHWhFstP4K: */
                                              _.v_3qw9bnATIhq_8loBraLeXzQ =
                                              // returned 
                                              _.o_7n2SLLuWOjH_4ArhFUjmckz;
                                              goto
                                              epilog_4qlegfkPzrC_17skUfJP7v8;
/* !endingblock _3oMW0T4HlXx_8r7NLpyK1J8 */
goto endblock__3oMW0T4HlXx_8r7NLpyK1J8; endblock__3oMW0T4HlXx_8r7NLpyK1J8:;}
  /*-block _3oMW0T4HlXx_8r7NLpyK1J8 */

epilog_4qlegfkPzrC_17skUfJP7v8:              __attribute__ ((unused)); // routine _4qlegfkPzrC_17skUfJP7v8 epilogue:
                                              if (stkf) stkf->stkfram_callfun = NULL; return _.v_3qw9bnATIhq_8loBraLeXzQ;}      // end _4qlegfkPzrC_17skUfJP7v8 routine#11 _4qlegfkPzrC_17skUfJP7v8




                                              value_tyBM crout_4M7lr5cU6VD_5hxmeH3baBf_BM       //#12
                                              (struct stackframe_stBM * stkf,   //
//!append°list_object minifunction
                                               // 2 arguments
                                               const value_tyBM arg0,   // o1
                                               const value_tyBM arg1,   // v2
                                               const value_tyBM arg2_
                                               __attribute__ ((unused)),
                                               const value_tyBM arg3_
                                               __attribute__ ((unused)),
                                               const quasinode_tyBM *
                                               restargs_
                                               __attribute__ ((unused)))
                                              { // start of _4M7lr5cU6VD_5hxmeH3baBf
                                              struct frame_4M7lr5cU6VD_5hxmeH3baBf_BMst
                                              {
                                              typedhead_tyBM stkfram_head;
                                              struct stackframe_stBM
                                              *stkfram_prev;
                                              objectval_tyBM * stkfram_descr;
                                              value_tyBM stkfram_callfun;
                                              int stkfram_state;
                                              int stkfram_extra;
                                              /// 3 local values:
                                              value_tyBM v_09RxU8xDco3_2Zxwfb13oDZ;     // v2
                                              value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;     // v_r
                                              objectval_tyBM * o_97rnxb0KFqq_44veN75DG2E;       // o1
                                              /// 0 local numbers:
                                              } _;
                                              memset (&_, 0,
                                                      sizeof (struct
                                                              frame_4M7lr5cU6VD_5hxmeH3baBf_BMst));
                                              _.stkfram_head.htyp =
                                              typayl_StackFrame_BM;
                                              _.stkfram_head.hgc = 0;
                                              _.stkfram_head.rlen = 3;
                                              _.stkfram_descr =
                                              constob_3BFt4NfJmZC_7iYi2dwM38B_BM
                                              [18]
                                              /*|_4M7lr5cU6VD_5hxmeH3baBf */ ;
                                              ASSERT_BM (!stkf
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_StackFrame_BM
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_SpecialFrame_BM);
                                              _.stkfram_prev = stkf;
                                              // fetch 2 arguments:
                                              _.o_97rnxb0KFqq_44veN75DG2E =
                                              objectcast_BM (arg0);
                                              _.v_09RxU8xDco3_2Zxwfb13oDZ =
                                              arg1;
                                              // fetched 2 arguments.
                                              // no closed values in _4M7lr5cU6VD_5hxmeH3baBf.
                                              // routine _4M7lr5cU6VD_5hxmeH3baBf body:
startblock__883QaWUOedh_9zmHk2A3RPm:         __attribute__ ((unused));
                                              { /* +block _883QaWUOedh_9zmHk2A3RPm */
                                              if        /*cond _9l1kqklfeho_8gvTSpVHJs0 */
                                              /*when _4bt3mp8e1a2_7XsOs7auvrU: */
                                              ( /*objhaslistpayl: */
                                                objhaslistpayl_BM ((_.
                                                                    o_97rnxb0KFqq_44veN75DG2E)))
                                              {
                                              { // start cexpansion _8WKnIBYQNvy_0t8M4F48joR - objlistappendpayl   
/*objlistappendpayl:*/
                                              objlistappendpayl_BM ((_.o_97rnxb0KFqq_44veN75DG2E), (_.v_09RxU8xDco3_2Zxwfb13oDZ));}     // end cexpansion _8WKnIBYQNvy_0t8M4F48joR - objlistappendpayl   
                                              /*return _86rGd2LLytX_4xsXHoCmw1Y: */
                                              _.v_3qw9bnATIhq_8loBraLeXzQ =
                                              // returned  
                                              _.o_97rnxb0KFqq_44veN75DG2E; goto epilog_4M7lr5cU6VD_5hxmeH3baBf;}        //endwhen _4bt3mp8e1a2_7XsOs7auvrU  
/*endcond _9l1kqklfeho_8gvTSpVHJs0*/

/* !endingblock _883QaWUOedh_9zmHk2A3RPm */
goto endblock__883QaWUOedh_9zmHk2A3RPm; endblock__883QaWUOedh_9zmHk2A3RPm:;}
  /*-block _883QaWUOedh_9zmHk2A3RPm */

epilog_4M7lr5cU6VD_5hxmeH3baBf:              __attribute__ ((unused)); // routine _4M7lr5cU6VD_5hxmeH3baBf epilogue:
                                              if (stkf) stkf->stkfram_callfun = NULL; return _.v_3qw9bnATIhq_8loBraLeXzQ;}      // end _4M7lr5cU6VD_5hxmeH3baBf routine#12 _4M7lr5cU6VD_5hxmeH3baBf




                                              value_tyBM crout_5j8LpQULt1p_9oeOaqmfYYr_BM       //#13
                                              (struct stackframe_stBM * stkf,   //
//!dump_data°list_object minifunc
                                               // 3 arguments
                                               const value_tyBM arg0,   // o1
                                               const value_tyBM arg1,   // o2
                                               const value_tyBM arg2,   // o3
                                               const value_tyBM arg3_
                                               __attribute__ ((unused)),
                                               const quasinode_tyBM *
                                               restargs_
                                               __attribute__ ((unused)))
                                              { // start of _5j8LpQULt1p_9oeOaqmfYYr
                                              struct frame_5j8LpQULt1p_9oeOaqmfYYr_BMst
                                              {
                                              typedhead_tyBM stkfram_head;
                                              struct stackframe_stBM
                                              *stkfram_prev;
                                              objectval_tyBM * stkfram_descr;
                                              value_tyBM stkfram_callfun;
                                              int stkfram_state;
                                              int stkfram_extra;
                                              /// 5 local values:
                                              objectval_tyBM * o_1Bl1iFQ8boR_1xM6MOfHV1N;       // o3
                                              value_tyBM v_2BkOxf2KbS8_3bswrKbmgjy;     // v_node
                                              value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;     // v_r
                                              objectval_tyBM * o_93FBSk1ML0f_2WjSuKa9TNU;       // o2
                                              objectval_tyBM * o_97rnxb0KFqq_44veN75DG2E;       // o1
                                              /// 2 local numbers:
                                              intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B;       // ii
                                              intptr_t n_833x2jYqhZh_8vDIuJhwz1k;       // leni
                                              } _;
                                              memset (&_, 0,
                                                      sizeof (struct
                                                              frame_5j8LpQULt1p_9oeOaqmfYYr_BMst));
                                              _.stkfram_head.htyp =
                                              typayl_StackFrame_BM;
                                              _.stkfram_head.hgc = 0;
                                              _.stkfram_head.rlen = 5;
                                              _.stkfram_descr =
                                              constob_3BFt4NfJmZC_7iYi2dwM38B_BM
                                              [19]
                                              /*|_5j8LpQULt1p_9oeOaqmfYYr */ ;
                                              ASSERT_BM (!stkf
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_StackFrame_BM
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_SpecialFrame_BM);
                                              _.stkfram_prev = stkf;
                                              // fetch 3 arguments:
                                              _.o_97rnxb0KFqq_44veN75DG2E =
                                              objectcast_BM (arg0);
                                              _.o_93FBSk1ML0f_2WjSuKa9TNU =
                                              objectcast_BM (arg1);
                                              _.o_1Bl1iFQ8boR_1xM6MOfHV1N =
                                              objectcast_BM (arg2);
                                              // fetched 3 arguments.
                                              // no closed values in _5j8LpQULt1p_9oeOaqmfYYr.
                                              // routine _5j8LpQULt1p_9oeOaqmfYYr body:
startblock__9Hf4n8AnqR7_7ve3Bi3kWMV:         __attribute__ ((unused));
                                              { /* +block _9Hf4n8AnqR7_7ve3Bi3kWMV */
                                              _.v_2BkOxf2KbS8_3bswrKbmgjy =     //assign _8ggHPTQI1iG_02hVE5KybEL  
                                              /*objlisttonodepayl: */
                                              (value_tyBM)
                                              objlisttonodepayl_BM ((_.
                                                                     o_97rnxb0KFqq_44veN75DG2E),
                                                                    ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[1] /*|node */ )));
                                              _.n_833x2jYqhZh_8vDIuJhwz1k =     //assign _0zhpGzEVWGP_7WoL4LJocuS  
/*nodewidth:*/
                                              (intptr_t) nodewidth_BM (_.v_2BkOxf2KbS8_3bswrKbmgjy); _.n_2W7Ckt2WxEM_4NVYgEWE73B =      //assign _0fygl91r6x5_8b3aCDptjAi  
                                              0;
                                              { // start cexpansion _6yLpzYpq8F0_4ogwWJhDGnH - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/
                                              objstrbufferappendcstrpayl_BM ((_.o_1Bl1iFQ8boR_1xM6MOfHV1N), ("!~ todo (~"));}   // end cexpansion _6yLpzYpq8F0_4ogwWJhDGnH - objstrbufferappendcstrpayl  



//// +while _9xjh4MB97y4_2d8ffcaNFYt 
  startblock__9xjh4MB97y4_2d8ffcaNFYt: /*+!while */
                                              ;
                                              { /* +while _9xjh4MB97y4_2d8ffcaNFYt */
                                              if (!( /*while _9xjh4MB97y4_2d8ffcaNFYt cond: */ ( /*less_int: */ (_.n_2W7Ckt2WxEM_4NVYgEWE73B) < (_.n_833x2jYqhZh_8vDIuJhwz1k))))        //: testwhile _9xjh4MB97y4_2d8ffcaNFYt failing   
                                              goto endblock__9xjh4MB97y4_2d8ffcaNFYt;   //failwhile   
// while _9xjh4MB97y4_2d8ffcaNFYt body:   
// while _9xjh4MB97y4_2d8ffcaNFYt comp#0:  
                                              { // start cexpansion _63n9WJxlgsW_7aRQkxcfyFp - objstrbuffersetindentpayl   
/*objstrbuffersetindentpayl:*/
                                              objstrbuffersetindentpayl_BM ((_.o_1Bl1iFQ8boR_1xM6MOfHV1N), (1));}       // end cexpansion _63n9WJxlgsW_7aRQkxcfyFp - objstrbuffersetindentpayl   
// while _9xjh4MB97y4_2d8ffcaNFYt comp#1:  
                                              { // start cexpansion _4L5hoWsh9Dl_112aUlLRWBa - objstrbuffernewlinepayl   
/*objstrbuffernewlinepayl:*/
                                              objstrbuffernewlinepayl_BM (_.o_1Bl1iFQ8boR_1xM6MOfHV1N);}        // end cexpansion _4L5hoWsh9Dl_112aUlLRWBa - objstrbuffernewlinepayl   
// while _9xjh4MB97y4_2d8ffcaNFYt comp#2:  
                                              { // start cexpansion _4ExmfQs4chn_6b5RsLwzSmp - objstrbufferappendcstrpayl   
/*objstrbufferappendcstrpayl:*/
                                              objstrbufferappendcstrpayl_BM ((_.o_1Bl1iFQ8boR_1xM6MOfHV1N), (" &!"));}  // end cexpansion _4ExmfQs4chn_6b5RsLwzSmp - objstrbufferappendcstrpayl   
// while _9xjh4MB97y4_2d8ffcaNFYt comp#3:  

                                              { // run _6HYDs1Zywvs_1w8OTn5XOZY  
                                              (send3_BM ((      /*nodenthson: */
                                                           nodenthson_BM ((_.v_2BkOxf2KbS8_3bswrKbmgjy), (_.n_2W7Ckt2WxEM_4NVYgEWE73B))),
                                                         /*sel: */
                                                         ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[6] /*|dump_value */ )),
                                                         ((struct stackframe_stBM *) &_), (_.o_1Bl1iFQ8boR_1xM6MOfHV1N), (_.o_93FBSk1ML0f_2WjSuKa9TNU), (((value_tyBM) 0x3      /*!1 */
                                                                                                                                                         ))));} // end run _6HYDs1Zywvs_1w8OTn5XOZY  
// while _9xjh4MB97y4_2d8ffcaNFYt comp#4:  
                                              _.n_2W7Ckt2WxEM_4NVYgEWE73B =     //assign _4nPRrjCznxv_354tRTC5amu   
/*add_int:*/
                                              ((_.n_2W7Ckt2WxEM_4NVYgEWE73B) + (1)); goto startblock__9xjh4MB97y4_2d8ffcaNFYt;  // repeatwhile  
    endblock__9xjh4MB97y4_2d8ffcaNFYt: /*endingwhile */
                                              ;}
  /*-while _9xjh4MB97y4_2d8ffcaNFYt */


                                              { // start cexpansion _39EI0paA4hR_8y7JANajq5t - objstrbuffernewlinepayl  
/*objstrbuffernewlinepayl:*/
                                              objstrbuffernewlinepayl_BM (_.o_1Bl1iFQ8boR_1xM6MOfHV1N);}        // end cexpansion _39EI0paA4hR_8y7JANajq5t - objstrbuffernewlinepayl  


                                              { // start cexpansion _5flu8xdOTMC_79tshj3uSa4 - objstrbuffersetindentpayl  
/*objstrbuffersetindentpayl:*/
                                              objstrbuffersetindentpayl_BM ((_.o_1Bl1iFQ8boR_1xM6MOfHV1N), (0));}       // end cexpansion _5flu8xdOTMC_79tshj3uSa4 - objstrbuffersetindentpayl  


                                              { // start cexpansion _5YxDaNaTjQ7_0v9tZ2seGmF - objstrbufferappendcstrpayl  
/*objstrbufferappendcstrpayl:*/
                                              objstrbufferappendcstrpayl_BM ((_.o_1Bl1iFQ8boR_1xM6MOfHV1N), ("~)"));}   // end cexpansion _5YxDaNaTjQ7_0v9tZ2seGmF - objstrbufferappendcstrpayl  

/* !endingblock _9Hf4n8AnqR7_7ve3Bi3kWMV */
goto endblock__9Hf4n8AnqR7_7ve3Bi3kWMV; endblock__9Hf4n8AnqR7_7ve3Bi3kWMV:;}
  /*-block _9Hf4n8AnqR7_7ve3Bi3kWMV */

epilog_5j8LpQULt1p_9oeOaqmfYYr:              __attribute__ ((unused)); // routine _5j8LpQULt1p_9oeOaqmfYYr epilogue:
                                              if (stkf) stkf->stkfram_callfun = NULL; return _.v_3qw9bnATIhq_8loBraLeXzQ;}      // end _5j8LpQULt1p_9oeOaqmfYYr routine#13 _5j8LpQULt1p_9oeOaqmfYYr




                                              value_tyBM crout_82ho9wUUDji_4peMLha4PXl_BM       //#14+
                                              (struct stackframe_stBM * stkf,   // findobj_scan_minifunc
//!findobj_scan_minifunc scans, with the closed and locked o_findobj, the argument object o_scan; give NULL if o_scan was already scanned
                                               // 1 arguments
                                               const value_tyBM arg0,   // o_scan
                                               const value_tyBM arg1_
                                               __attribute__ ((unused)),
                                               const value_tyBM arg2_
                                               __attribute__ ((unused)),
                                               const value_tyBM arg3_
                                               __attribute__ ((unused)),
                                               const quasinode_tyBM *
                                               restargs_
                                               __attribute__ ((unused)))
                                              { // start of findobj_scan_minifunc
                                              struct frame_82ho9wUUDji_4peMLha4PXl_BMst
                                              {
                                              typedhead_tyBM stkfram_head;
                                              struct stackframe_stBM
                                              *stkfram_prev;
                                              objectval_tyBM * stkfram_descr;
                                              value_tyBM stkfram_callfun;
                                              int stkfram_state;
                                              int stkfram_extra;
                                              /// 4 local values:
                                              value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;     // v_r
                                              objectval_tyBM * o_4gykCX1QdLb_9Aooqa2FWTq;       // o_scan
                                              objectval_tyBM * o_4ITcQtvlMmO_30Pss9oAVDB;       // o_findobj
                                              objectval_tyBM * o_6Jkz6rphVkn_1KZto79j46r;       // o_vihset
                                              /// 0 local numbers:
                                              } _; memset (&_, 0, sizeof (struct frame_82ho9wUUDji_4peMLha4PXl_BMst)); _.stkfram_head.htyp = typayl_StackFrame_BM; _.stkfram_head.hgc = 0; _.stkfram_head.rlen = 4; _.stkfram_descr = constob_3BFt4NfJmZC_7iYi2dwM38B_BM[26]    /*|findobj_scan_minifunc */
                                              ;
                                              ASSERT_BM (!stkf
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_StackFrame_BM
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_SpecialFrame_BM);
                                              _.stkfram_prev = stkf;
                                              // fetch 1 arguments:
                                              _.o_4gykCX1QdLb_9Aooqa2FWTq =
                                              objectcast_BM (arg0);
                                              // fetched 1 arguments.
                                              { // fetch 1 closed values in findobj_scan_minifunc:
                                              const closure_tyBM * callclos_82ho9wUUDji_4peMLha4PXl = (stkf && stkf->stkfram_pA.htyp == typayl_StackFrame_BM) ? (closurecast_BM (stkf->stkfram_callfun)) : NULL; unsigned nbclosed_82ho9wUUDji_4peMLha4PXl = closurewidth_BM ((const value_tyBM) callclos_82ho9wUUDji_4peMLha4PXl); if (nbclosed_82ho9wUUDji_4peMLha4PXl > 0) _.o_4ITcQtvlMmO_30Pss9oAVDB = objectcast_BM (callclos_82ho9wUUDji_4peMLha4PXl->nodt_sons[0]);}    // fetched 1 closed values in _82ho9wUUDji_4peMLha4PXl.
                                              // routine _82ho9wUUDji_4peMLha4PXl body:

startblock__6YnYKKsHo3f_9nIEOZMp744:         __attribute__ ((unused));
                                              { /* +block _6YnYKKsHo3f_9nIEOZMp744 */

                                              { // run _7m9brpKxZkY_3BEI7YANJuJ 
                                              /*begin findobj_scan_minifunc */
                                              WEAKASSERT_BM (objectisinstance_BM (_.o_4ITcQtvlMmO_30Pss9oAVDB, (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[20]  /*|findrun_object */
                                                                                  )));;}        // end run _7m9brpKxZkY_3BEI7YANJuJ 

/* !endingblock _6YnYKKsHo3f_9nIEOZMp744 */
goto endblock__6YnYKKsHo3f_9nIEOZMp744; endblock__6YnYKKsHo3f_9nIEOZMp744:;}
  /*-block _6YnYKKsHo3f_9nIEOZMp744 */

epilog_82ho9wUUDji_4peMLha4PXl:              __attribute__ ((unused)); // routine _82ho9wUUDji_4peMLha4PXl epilogue:
                                              if (stkf) stkf->stkfram_callfun = NULL; return _.v_3qw9bnATIhq_8loBraLeXzQ;}      // end _82ho9wUUDji_4peMLha4PXl routine#14 findobj_scan_minifunc




                                              value_tyBM crout_8imWClcIFKt_6w2H2ouB4I6_BM       //#15+
                                              (struct stackframe_stBM * stkf,   // iterate_sequence_minifunc
//!iterate on sequence v_seq the function v_fun with 2nd argument v_arg
                                               // 3 arguments
                                               const value_tyBM arg0,   // v_seq
                                               const value_tyBM arg1,   // v_fun
                                               const value_tyBM arg2,   // v_arg
                                               const value_tyBM arg3_
                                               __attribute__ ((unused)),
                                               const quasinode_tyBM *
                                               restargs_
                                               __attribute__ ((unused)))
                                              { // start of iterate_sequence_minifunc
                                              struct frame_8imWClcIFKt_6w2H2ouB4I6_BMst
                                              {
                                              typedhead_tyBM stkfram_head;
                                              struct stackframe_stBM
                                              *stkfram_prev;
                                              objectval_tyBM * stkfram_descr;
                                              value_tyBM stkfram_callfun;
                                              int stkfram_state;
                                              int stkfram_extra;
                                              /// 4 local values:
                                              value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;     // v_r
                                              value_tyBM v_4Q4WBLjAPTV_5WVLmhAvCJY;     // v_arg
                                              value_tyBM v_8jKgolslEuE_4dxzrK5R2B4;     // v_fun
                                              value_tyBM v_9vc0quxdnhj_3zLw1MEwl1e;     // v_seq
                                              /// 2 local numbers:
                                              intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B;       // ii
                                              intptr_t n_833x2jYqhZh_8vDIuJhwz1k;       // leni
                                              } _;
                                              memset (&_, 0,
                                                      sizeof (struct
                                                              frame_8imWClcIFKt_6w2H2ouB4I6_BMst));
                                              _.stkfram_head.htyp =
                                              typayl_StackFrame_BM;
                                              _.stkfram_head.hgc = 0;
                                              _.stkfram_head.rlen = 4;
                                              _.stkfram_descr =
                                              constob_3BFt4NfJmZC_7iYi2dwM38B_BM
                                              [27]
                                              /*|iterate_sequence_minifunc */
                                              ;
                                              ASSERT_BM (!stkf
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_StackFrame_BM
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_SpecialFrame_BM);
                                              _.stkfram_prev = stkf;
                                              // fetch 3 arguments:
                                              _.v_9vc0quxdnhj_3zLw1MEwl1e =
                                              arg0;
                                              _.v_8jKgolslEuE_4dxzrK5R2B4 =
                                              arg1;
                                              _.v_4Q4WBLjAPTV_5WVLmhAvCJY =
                                              arg2;
                                              // fetched 3 arguments.
                                              // no closed values in iterate_sequence_minifunc.
                                              // routine _8imWClcIFKt_6w2H2ouB4I6 body:
startblock__2W6NObLb2d4_6OfkP3dYlF3:         __attribute__ ((unused));
                                              { /* +block _2W6NObLb2d4_6OfkP3dYlF3 */
                                              _.n_833x2jYqhZh_8vDIuJhwz1k =     //assign _3EakP4EXPLZ_10btDL0iqAt  
/*seqlength*/
                                              sequencesize_BM (_.v_9vc0quxdnhj_3zLw1MEwl1e); _.n_2W7Ckt2WxEM_4NVYgEWE73B =      //assign _1Z2mN7VIEbD_4RJunrL2QcV  
  0; startblock__3vvVJBONOyK_3kn86nuYwr1:    __attribute__ ((unused));
                                              { /* +loop _3vvVJBONOyK_3kn86nuYwr1 */
    startloop__3vvVJBONOyK_3kn86nuYwr1:      __attribute__ ((unused)); if      /*cond _7pBaII8qZHM_8xoaIKeilBk */
                                              /*when _8qsLnTz2QdD_9nZub2hBMEb: */
                                              ((        /*greaterequal_int: */
                                                 (_.
                                                  n_2W7Ckt2WxEM_4NVYgEWE73B)
                                                 >=
                                                 (_.
                                                  n_833x2jYqhZh_8vDIuJhwz1k)))
                                              {
// exit _9dmQwUU17M1_1km5cSGzJly   
                                              goto endblock__3vvVJBONOyK_3kn86nuYwr1;}  //endwhen _8qsLnTz2QdD_9nZub2hBMEb   
/*endcond _7pBaII8qZHM_8xoaIKeilBk*/



/* !endingloop _3vvVJBONOyK_3kn86nuYwr1 */
  goto startloop__3vvVJBONOyK_3kn86nuYwr1; endblock__3vvVJBONOyK_3kn86nuYwr1:__attribute__ ((unused));}
  /*-loop _3vvVJBONOyK_3kn86nuYwr1 */
/* !endingblock _2W6NObLb2d4_6OfkP3dYlF3 */
goto endblock__2W6NObLb2d4_6OfkP3dYlF3; endblock__2W6NObLb2d4_6OfkP3dYlF3:;}
  /*-block _2W6NObLb2d4_6OfkP3dYlF3 */

epilog_8imWClcIFKt_6w2H2ouB4I6:              __attribute__ ((unused)); // routine _8imWClcIFKt_6w2H2ouB4I6 epilogue:
                                              if (stkf) stkf->stkfram_callfun = NULL; return _.v_3qw9bnATIhq_8loBraLeXzQ;}      // end _8imWClcIFKt_6w2H2ouB4I6 routine#15 iterate_sequence_minifunc




                                              value_tyBM crout_9CG8SKNs6Ql_4PiHd8cnydn_BM       //#16
                                              (struct stackframe_stBM * stkf,   //
//!clear°dict_object minifun
                                               // 1 arguments
                                               const value_tyBM arg0,   // odict
                                               const value_tyBM arg1_
                                               __attribute__ ((unused)),
                                               const value_tyBM arg2_
                                               __attribute__ ((unused)),
                                               const value_tyBM arg3_
                                               __attribute__ ((unused)),
                                               const quasinode_tyBM *
                                               restargs_
                                               __attribute__ ((unused)))
                                              { // start of _9CG8SKNs6Ql_4PiHd8cnydn
                                              struct frame_9CG8SKNs6Ql_4PiHd8cnydn_BMst
                                              {
                                              typedhead_tyBM stkfram_head;
                                              struct stackframe_stBM
                                              *stkfram_prev;
                                              objectval_tyBM * stkfram_descr;
                                              value_tyBM stkfram_callfun;
                                              int stkfram_state;
                                              int stkfram_extra;
                                              /// 2 local values:
                                              value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;     // v_r
                                              objectval_tyBM * o_7n2SLLuWOjH_4ArhFUjmckz;       // odict
                                              /// 0 local numbers:
                                              } _;
                                              memset (&_, 0,
                                                      sizeof (struct
                                                              frame_9CG8SKNs6Ql_4PiHd8cnydn_BMst));
                                              _.stkfram_head.htyp =
                                              typayl_StackFrame_BM;
                                              _.stkfram_head.hgc = 0;
                                              _.stkfram_head.rlen = 2;
                                              _.stkfram_descr =
                                              constob_3BFt4NfJmZC_7iYi2dwM38B_BM
                                              [31]
                                              /*|_9CG8SKNs6Ql_4PiHd8cnydn */ ;
                                              ASSERT_BM (!stkf
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_StackFrame_BM
                                                         || stkf->
                                                         stkfram_pA.htyp ==
                                                         typayl_SpecialFrame_BM);
                                              _.stkfram_prev = stkf;
                                              // fetch 1 arguments:
                                              _.o_7n2SLLuWOjH_4ArhFUjmckz =
                                              objectcast_BM (arg0);
                                              // fetched 1 arguments.
                                              // no closed values in _9CG8SKNs6Ql_4PiHd8cnydn.
                                              // routine _9CG8SKNs6Ql_4PiHd8cnydn body:
startblock__1lmLI285f7p_4im4Ls4Xewh:         __attribute__ ((unused));
                                              { /* +block _1lmLI285f7p_4im4Ls4Xewh */
                                              if        /*cond _58n2IHCyrnJ_19R71AKw5aF */
                                              /*when _8QkV0tL7Jvt_9mc0QaZYbyv: */
                                              ( /*objputdictpayl: */
                                                objputdictpayl_BM ((_.
                                                                    o_7n2SLLuWOjH_4ArhFUjmckz)))
                                              {
                                              /*return _2RCw0JQb23v_2NfFku112jv: */
                                              _.v_3qw9bnATIhq_8loBraLeXzQ =
                                              // returned  
                                              _.o_7n2SLLuWOjH_4ArhFUjmckz; goto epilog_9CG8SKNs6Ql_4PiHd8cnydn;}        //endwhen _8QkV0tL7Jvt_9mc0QaZYbyv  
/*endcond _58n2IHCyrnJ_19R71AKw5aF*/


                                              if        /*cond _4QR8kuWiKxV_9oKMeD79KDQ */
                                              /*when _8bCPs7gML9M_12nXMrdhzvW: */
                                              ( /*objputdictpayl: */
                                                objputdictpayl_BM ((_.
                                                                    o_7n2SLLuWOjH_4ArhFUjmckz)))
                                              {
                                              /*return _9198YxnrBs6_7u9nhmAA8Q6: */
                                              _.v_3qw9bnATIhq_8loBraLeXzQ =
                                              // returned  
                                              _.o_7n2SLLuWOjH_4ArhFUjmckz; goto epilog_9CG8SKNs6Ql_4PiHd8cnydn;}        //endwhen _8bCPs7gML9M_12nXMrdhzvW  
/*endcond _4QR8kuWiKxV_9oKMeD79KDQ*/

/* !endingblock _1lmLI285f7p_4im4Ls4Xewh */
goto endblock__1lmLI285f7p_4im4Ls4Xewh; endblock__1lmLI285f7p_4im4Ls4Xewh:;}
  /*-block _1lmLI285f7p_4im4Ls4Xewh */

epilog_9CG8SKNs6Ql_4PiHd8cnydn:              __attribute__ ((unused)); // routine _9CG8SKNs6Ql_4PiHd8cnydn epilogue:
                                              if (stkf) stkf->stkfram_callfun = NULL; return _.v_3qw9bnATIhq_8loBraLeXzQ;}      // end _9CG8SKNs6Ql_4PiHd8cnydn routine#16 _9CG8SKNs6Ql_4PiHd8cnydn




// end of 17 generated routines


// the constant ids for 32 constants:
                                              const char *const
                                              constid_3BFt4NfJmZC_7iYi2dwM38B_BM
                                              [32 + 1] =
                                              {
                                              /*0: */
                                              "_0cUdonky1bM_4IVhwlVRBMk", "_0JktC4mAHCa_1KNr6uMIqIi", "_0SinERsgdvQ_57dLCP63i9r", "_0YOXUe7rEJC_3jFMjOAQRs9",   //element_of_closed_minifunc
                                              "_1dzZlwqKdLH_8HjkBsL9Mar",       //add
                                              "_1DGcmfymxyC_2TiD1HX0HU5",       //emit_for_jsmodule
                                              "_1FEnnpEkGdI_5DAcVDL5XHG",       //dump_value
                                              "_1SolDiQA2WM_4IDOJKBiPFc",       //for
                                              /*8: */
                                              "_22Zd68WPKUO_6AoIuBcbUb2", "_2bZ4BfCci5V_3WTzG7V25y4", "_3iiht57Wrs1_5NbiUi27oBn", "_3vI0Qc3FHQG_1g4fmHYkxSA", "_3yQlckX4DRh_4b9l9FBSSSL",       //same_as_closed_minifunc
                                              "_3HAeZZQ0q7b_7qyDsekaz7Y", "_4iEFTEcHxeb_6lH464uFkTC",   //equal_to_closed_minifunc
                                              "_4jwFGdaECBb_6dsBLTMoG9j",
                                              /*16: */
                                              "_4qlegfkPzrC_17skUfJP7v8", "_4HgYLk6htvP_4Ac2FCPfQ1C",   //failure_bad_class
                                              "_4M7lr5cU6VD_5hxmeH3baBf", "_5j8LpQULt1p_9oeOaqmfYYr", "_64UbCFBD19G_43TeBXhcYMy",       //findrun_object
                                              "_6pp3g7GLuae_7OF8KezKzvx", "_6yWldsq3Rmk_01WqTfwSIDV",   //failure_non_object
                                              "_7zLaPay40r6_5iPrtG8Hiq4",       //prepare_for_jsmodule
                                              /*24: */
                                              "_7D8xcWnEiys_8oqOVSkCxkA",       //node
                                              "_7KpOCu7pOza_0ApwnGaS3DP",       //jscript_toplevel_object
                                              "_82ho9wUUDji_4peMLha4PXl",       //findobj_scan_minifunc
                                              "_8imWClcIFKt_6w2H2ouB4I6",       //iterate_sequence_minifunc
                                              "_8lV53mLyu1H_3Z1SI8wDBK1",       //clear
                                              "_9pvzBeIKHXF_8YDPCrQ6OEK",       //put
                                              "_9zzGR0VqDpm_259EJDSFYyu",       //jsmodule_preparation_object
                                              "_9CG8SKNs6Ql_4PiHd8cnydn", NULL};        // end 32 constant ids

// the routine ids for 17 routines:
                                              const char *const
                                              routid_3BFt4NfJmZC_7iYi2dwM38B_BM
                                              [17 + 1] =
                                              {
                                              /*0: */
                                              "_0cUdonky1bM_4IVhwlVRBMk",       //!webhandler testhello minifunc
                                              "_0JktC4mAHCa_1KNr6uMIqIi",       //!dump_scan°list_object minifunc for list_object o1 & dumperobj o2
                                              "_0SinERsgdvQ_57dLCP63i9r",       //!forgetname#command_handler
                                              "_0YOXUe7rEJC_3jFMjOAQRs9",       //element_of_closed_minifunc
                                              "_22Zd68WPKUO_6AoIuBcbUb2",       //!dump_scan°dict_object minifunc for dict-object odict and dumperobj odumper
                                              "_2bZ4BfCci5V_3WTzG7V25y4",       //!put°dict_object minifunc;
                                              "_3iiht57Wrs1_5NbiUi27oBn",       //!prepend°list_object minifunc
                                              "_3vI0Qc3FHQG_1g4fmHYkxSA",       //!jsmodule compiler: compile o_jsmodule into o_strbuf
                                              /*8: */
                                              "_3yQlckX4DRh_4b9l9FBSSSL",       //same_as_closed_minifunc
                                              "_3HAeZZQ0q7b_7qyDsekaz7Y",       //!clear°list_object minifunc
                                              "_4iEFTEcHxeb_6lH464uFkTC",       //equal_to_closed_minifunc
                                              "_4qlegfkPzrC_17skUfJP7v8",       //!dump_data°dict_object minifunc
                                              "_4M7lr5cU6VD_5hxmeH3baBf",       //!append°list_object minifunction
                                              "_5j8LpQULt1p_9oeOaqmfYYr",       //!dump_data°list_object minifunc;
                                              "_82ho9wUUDji_4peMLha4PXl",       //findobj_scan_minifunc
                                              "_8imWClcIFKt_6w2H2ouB4I6",       //iterate_sequence_minifunc
                                              /*16: */
                                              "_9CG8SKNs6Ql_4PiHd8cnydn",       //!clear°dict_object minifunc
                                              NULL};    // end 17 routine ids

// basiclo*module initialization
#ifdef BISMON_MODID
                                              value_tyBM modulinit_3BFt4NfJmZC_7iYi2dwM38B_BM (struct stackframe_stBM *stkf,    //
                                                                                               const value_tyBM arg1,   //
                                                                                               const value_tyBM arg2,   //
                                                                                               const value_tyBM arg3,   //
                                                                                               void
                                                                                               *dlh)
                                              {
                                              return simple_module_initialize_BM (arg1, arg2, arg3,     //
                                                                                  "_3BFt4NfJmZC_7iYi2dwM38B",   //
                                                                                  constob_3BFt4NfJmZC_7iYi2dwM38B_BM,   //
                                                                                  constid_3BFt4NfJmZC_7iYi2dwM38B_BM,   //
                                                                                  routid_3BFt4NfJmZC_7iYi2dwM38B_BM,    //
                                                                                  dlh, stkf);}  // end modulinit_3BFt4NfJmZC_7iYi2dwM38B_BM
#endif /*BISMON_MODID */



// end of generated persistent module first_misc_module in file modbm_3BFt4NfJmZC_7iYi2dwM38B.c
