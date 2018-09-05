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



// declare 25 routines

extern const char *const routid_3BFt4NfJmZC_7iYi2dwM38B_BM[25 + 1];


// 14 failures

extern objrout_sigBM crout_09Hug4WGnPK_7PpZby8pz84_BM;  //#0 !emit_epilogue_jsmodule°jsmodule_generation_object

extern objrout_sigBM crout_0cUdonky1bM_4IVhwlVRBMk_BM;  //#1 !webhandler testhello minifunc

extern objrout_sigBM crout_0JktC4mAHCa_1KNr6uMIqIi_BM;  //#2 !dump_scan°list_object minifunc for list_object o1 & dumperobj o2

extern objrout_sigBM crout_0SinERsgdvQ_57dLCP63i9r_BM;  //#3 !forgetname#command_handler

extern objrout_sigBM crout_0YOXUe7rEJC_3jFMjOAQRs9_BM;  //#4 element_of_closed_minifunc

extern objrout_sigBM crout_1HZc1VBbjdB_96aQTEPgEX0_BM;  //#5 !emit_prologue_jsmodule°jsmodule_generation_object

extern objrout_sigBM crout_22Zd68WPKUO_6AoIuBcbUb2_BM;  //#6 !dump_scan°dict_object minifunc for dict-object odict and dumperobj odumper

extern objrout_sigBM crout_2bZ4BfCci5V_3WTzG7V25y4_BM;  //#7 !put°dict_object minifunc

extern objrout_sigBM crout_3iiht57Wrs1_5NbiUi27oBn_BM;  //#8 !prepend°list_object minifunc

extern objrout_sigBM crout_3vI0Qc3FHQG_1g4fmHYkxSA_BM;  //#9 !compile_to_javascript°jsmodule_object (o_jsmodule, o_strbuf)

extern objrout_sigBM crout_3yQlckX4DRh_4b9l9FBSSSL_BM;  //#10 same_as_closed_minifunc

extern objrout_sigBM crout_3HAeZZQ0q7b_7qyDsekaz7Y_BM;  //#11 !clear°list_object minifunc

extern objrout_sigBM crout_44Xro7p814I_406P69WFbq4_BM;  //#12 !prepare_for_jsmodule°jscript_topvardef_object <o_jscurcomp (o_jsgenmod)

extern objrout_sigBM crout_4iEFTEcHxeb_6lH464uFkTC_BM;  //#13 equal_to_closed_minifunc

extern objrout_sigBM crout_4qlegfkPzrC_17skUfJP7v8_BM;  //#14 !dump_data°dict_object minifun

extern objrout_sigBM crout_4M7lr5cU6VD_5hxmeH3baBf_BM;  //#15 !append°list_object minifunction

extern objrout_sigBM crout_5j8LpQULt1p_9oeOaqmfYYr_BM;  //#16 !dump_data°list_object minifunc

extern objrout_sigBM crout_74TaCoUa4dg_2bmUAanJYIJ_BM;  //#17 !emit_jstoplevel°jscript_topvardef_object <o_jscurcomp (o_jsgenmod o_strbuf v_i)

extern objrout_sigBM crout_7TK5bvNNTIg_4pzieotiEq8_BM;  //#18 !prepare_for_jsmodule°jscript_topfunction_object <o_jscurcomp (o_jsgenmod)

extern objrout_sigBM crout_82ho9wUUDji_4peMLha4PXl_BM;  //#19 findobj_scan_minifunc

extern objrout_sigBM crout_83faYJmqTAm_5Um8Vj0myAd_BM;  //#20 !emit_jstoplevel°jscript_topfunction_object <o_jscurcomp (o_jsgenmod o_strbuf v_i)

extern objrout_sigBM crout_8imWClcIFKt_6w2H2ouB4I6_BM;  //#21 iterate_sequence_minifunc

extern objrout_sigBM crout_8Kh2MKilKO4_5qPRBWX9W3a_BM;  //#22 !jsemit_expression°jsvar_object >o_jsexpr (o_strbuf o_jsgenmod o_jsgenfun o_paren)

extern objrout_sigBM crout_8VtkXEUFfhk_5RxrpY6JHI6_BM;  //#23 !webhandler javascript-compile

extern objrout_sigBM crout_9CG8SKNs6Ql_4PiHd8cnydn_BM;  //#24 !clear°dict_object minifun


// declare 71 constants
objectval_tyBM *constob_3BFt4NfJmZC_7iYi2dwM38B_BM[71 + 1];
const char *const constid_3BFt4NfJmZC_7iYi2dwM38B_BM[71 + 1];


// define 25 routines


value_tyBM crout_09Hug4WGnPK_7PpZby8pz84_BM     //#0
  (struct stackframe_stBM *stkf,        //
//!emit_epilogue_jsmodule°jsmodule_generation_object
   // 2 arguments
   const value_tyBM arg0,       // o_jsgenmod
   const value_tyBM arg1,       // o_strbuf
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _09Hug4WGnPK_7PpZby8pz84
  struct frame_09Hug4WGnPK_7PpZby8pz84_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 4 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    objectval_tyBM *o_41F1rKwGbaA_30OJWKsqNWy;  // o_strbuf
    objectval_tyBM *o_4JKd986pvM4_6yBzeeI40vW;  // o_jsgenmod
    objectval_tyBM *o_5V0w37YnN4F_8dZ6I79V60O;  // o_jsmodule
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_09Hug4WGnPK_7PpZby8pz84_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 4;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[0] /*|_09Hug4WGnPK_7PpZby8pz84 */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 2 arguments:
  _.o_4JKd986pvM4_6yBzeeI40vW = objectcast_BM (arg0);   // o_jsgenmod
  _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg1);   // o_strbuf
  // fetched 2 arguments.
  // no closed values in _09Hug4WGnPK_7PpZby8pz84.
  // routine _09Hug4WGnPK_7PpZby8pz84 body:

startblock__1hpDu2PfgvV_90ZIZrNWtpj:__attribute__ ((unused));
  {                             /* +block _1hpDu2PfgvV_90ZIZrNWtpj */

    {                           // run _6U1zmaYm7Us_0uCHp2sLm1N 
/*debug start emit_epilogue_jsmodule°jsmodule_generation_object o_jsgenmod o_strbuf*/
      DBGPRINTF_BM
        ("emit_epilogue_jsmodule°jsmodule_generation_object start %.7s o_jsgenmod=%s o_strbuf=%s",
         "_6U1zmaYm7Us_0uCHp2sLm1N",
         objectdbg_BM ( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW),
         objectdbg1_BM ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy));
      ;
    }                           // end run _6U1zmaYm7Us_0uCHp2sLm1N 


    {                           // start cexpansion _3URReLScf0F_6KuinIraIHY - objstrbuffernewlinepayl  
                                                                        /*objstrbuffernewlinepayl: */ objstrbuffernewlinepayl_BM (
                                                                        /*o_strbuf: */
                                                                                                                                   _.o_41F1rKwGbaA_30OJWKsqNWy);
    }                           // end cexpansion _3URReLScf0F_6KuinIraIHY - objstrbuffernewlinepayl  


    {                           // start cexpansion _1smwkzMAMAi_5asL8fzyE2l - objstrbuffernewlinepayl  
                                                                        /*objstrbuffernewlinepayl: */ objstrbuffernewlinepayl_BM (
                                                                        /*o_strbuf: */
                                                                                                                                   _.o_41F1rKwGbaA_30OJWKsqNWy);
    }                           // end cexpansion _1smwkzMAMAi_5asL8fzyE2l - objstrbuffernewlinepayl  


    {                           // start cexpansion _4F0wlQRdgli_8WyjSZIrnuT - objstrbuffernewlinepayl  
                                                                        /*objstrbuffernewlinepayl: */ objstrbuffernewlinepayl_BM (
                                                                        /*o_strbuf: */
                                                                                                                                   _.o_41F1rKwGbaA_30OJWKsqNWy);
    }                           // end cexpansion _4F0wlQRdgli_8WyjSZIrnuT - objstrbuffernewlinepayl  


    {                           // start cexpansion _5RlCj0t94LE_9rN6Pwfmd1s - objstrbufferappendcstrpayl  
      /*objstrbufferappendcstrpayl: */
      objstrbufferappendcstrpayl_BM (( /*o_strbuf: */ _.
                                      o_41F1rKwGbaA_30OJWKsqNWy),
                                     ("// end of generated javascript "));
    }                           // end cexpansion _5RlCj0t94LE_9rN6Pwfmd1s - objstrbufferappendcstrpayl  


    /*o_jsmodule: */ _.o_5V0w37YnN4F_8dZ6I79V60O =
      //assign _7iGHPb51S38_3lYsZJW2NtA  
      /*val_to_object: */
      objectcast_BM (           /*objgetattr: */
                      objgetattr_BM (( /*o_jsgenmod: */ _.
                                      o_4JKd986pvM4_6yBzeeI40vW),
                                     ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[16]
                                       /*!for */ ))));


    {                           // start cexpansion _7gRgC1DEyqx_3PyfHWuBEFS - objstrbufferprintobject  
/*objstrbufferprintobject _7gRgC1DEyqx_3PyfHWuBEFS:*/
      objectval_tyBM *obsbuf_7gRgC1DEyqx_3PyfHWuBEFS =
        ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy);
      objectval_tyBM *ob_7gRgC1DEyqx_3PyfHWuBEFS =
        ( /*o_jsmodule: */ _.o_5V0w37YnN4F_8dZ6I79V60O);
      if (objhasstrbufferpayl_BM (obsbuf_7gRgC1DEyqx_3PyfHWuBEFS)
          && isobject_BM (ob_7gRgC1DEyqx_3PyfHWuBEFS))
        objstrbufferappendcstrpayl_BM (obsbuf_7gRgC1DEyqx_3PyfHWuBEFS,
                                       objectdbg_BM
                                       (ob_7gRgC1DEyqx_3PyfHWuBEFS));
// end objstrbufferprintobject _7gRgC1DEyqx_3PyfHWuBEFS
      ;
    }                           // end cexpansion _7gRgC1DEyqx_3PyfHWuBEFS - objstrbufferprintobject  


    {                           // start cexpansion _0quawvjFeRb_4leUSIVpwgL - objstrbuffernewlinepayl  
                                                                        /*objstrbuffernewlinepayl: */ objstrbuffernewlinepayl_BM (
                                                                        /*o_strbuf: */
                                                                                                                                   _.o_41F1rKwGbaA_30OJWKsqNWy);
    }                           // end cexpansion _0quawvjFeRb_4leUSIVpwgL - objstrbuffernewlinepayl  


    /*return _9ZKmVBJo4zI_0gOqfgVNKDF: *//*v_r: */ _.
      v_3qw9bnATIhq_8loBraLeXzQ =
      // returned 
      /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW;
    goto epilog_09Hug4WGnPK_7PpZby8pz84;

/* !endingblock _1hpDu2PfgvV_90ZIZrNWtpj */
    goto endblock__1hpDu2PfgvV_90ZIZrNWtpj;
  endblock__1hpDu2PfgvV_90ZIZrNWtpj:;
  }
  /*-block _1hpDu2PfgvV_90ZIZrNWtpj */

epilog_09Hug4WGnPK_7PpZby8pz84:__attribute__ ((unused));
  // routine _09Hug4WGnPK_7PpZby8pz84 epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _09Hug4WGnPK_7PpZby8pz84 routine#0 _09Hug4WGnPK_7PpZby8pz84




value_tyBM crout_0cUdonky1bM_4IVhwlVRBMk_BM     //#1
  (struct stackframe_stBM * stkf,       //
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[2] /*|_0cUdonky1bM_4IVhwlVRBMk */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 2 arguments:
  _.v_6QhNRfe1Cte_0niVlWfAlmO = arg0;   // v_restpath
  _.o_5JuT4FgNFFh_7McrTYeT3jx = objectcast_BM (arg1);   // o_webex
  // fetched 2 arguments.
  // no closed values in _0cUdonky1bM_4IVhwlVRBMk.
  // routine _0cUdonky1bM_4IVhwlVRBMk body:

startblock__8prn9eFlYZD_6JJKKh2b8KW:__attribute__ ((unused));
  {                             /* +block _8prn9eFlYZD_6JJKKh2b8KW */

    {                           // run _65239uTOHoM_0gCnjTxaNEB 
      /*Debug Web TestHello */
      DBGPRINTF_BM ("start webhandler testhello o_webex= %s",
                    objectdbg_BM ( /*o_webex: */ _.
                                  o_5JuT4FgNFFh_7McrTYeT3jx));
      ;
    }                           // end run _65239uTOHoM_0gCnjTxaNEB 



  startblock__3VVvcLyYqv8_9yci7GvqEEv:__attribute__ ((unused));
    {                           /* +block _3VVvcLyYqv8_9yci7GvqEEv */
      {                         // start cexpansion _5lsoSuyLYE0_2cqb9QxFcos - objstrbufferappendcstrpayl   
        /*objstrbufferappendcstrpayl: */
        objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                        o_5JuT4FgNFFh_7McrTYeT3jx),
                                       ("<h1>testhello bismon</h1>\n"));
      }                         // end cexpansion _5lsoSuyLYE0_2cqb9QxFcos - objstrbufferappendcstrpayl   


      if                        /*cond _27HdixkwtUA_4tQyI0XopOj */
/*when _57I7rSuuKya_8AuIt3qlJI1:*/
        (                       /*objwebexchangerequestispostpayl: */
          objwebexchangerequestispostpayl_BM (( /*o_webex: */ _.
                                               o_5JuT4FgNFFh_7McrTYeT3jx)))
        {                       //body when _57I7rSuuKya_8AuIt3qlJI1   
          {                     // start cexpansion _2AxVlhlfGNw_7PIs9S04rhK - objstrbufferappendcstrpayl    
            /*objstrbufferappendcstrpayl: */
            objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                            o_5JuT4FgNFFh_7McrTYeT3jx),
                                           ("<p><tt>POST</tt> request!</p>\n"));
          }                     // end cexpansion _2AxVlhlfGNw_7PIs9S04rhK - objstrbufferappendcstrpayl    

        }                       //endwhen _57I7rSuuKya_8AuIt3qlJI1   
/*endcond _27HdixkwtUA_4tQyI0XopOj*/


      {                         // start cexpansion _1gjXCT3HN6V_5SGgDufAmKf - objstrbufferappendcstrpayl   
        /*objstrbufferappendcstrpayl: */
        objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                        o_5JuT4FgNFFh_7McrTYeT3jx),
                                       ("<p>session: <tt>"));
      }                         // end cexpansion _1gjXCT3HN6V_5SGgDufAmKf - objstrbufferappendcstrpayl   


      {                         // start cexpansion _1XzuICo9tMz_2FMOEMMgKHC - objstrbufferprintobjid   
/*objstrbufferprintobjid _1XzuICo9tMz_2FMOEMMgKHC:*/
        objectval_tyBM *obsbuf__1XzuICo9tMz_2FMOEMMgKHC =
          ( /*o_webex: */ _.o_5JuT4FgNFFh_7McrTYeT3jx);
        objectval_tyBM *ob__1XzuICo9tMz_2FMOEMMgKHC = ( /*objwebexchangesessionpayl: */
                                                        objwebexchangesessionpayl_BM
                                                        (( /*o_webex: */ _.
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
        /*objstrbufferappendcstrpayl: */
        objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                        o_5JuT4FgNFFh_7McrTYeT3jx),
                                       ("</tt></p>\n"));
      }                         // end cexpansion _9osbAnIQdp8_6wVcWPdPIBQ - objstrbufferappendcstrpayl   


      /*v_queryfoo: */ _.v_8s5u19T0e2h_9ZqrO3YZDVS =
        //assign _5Aqv9Xln871_5IcSxT4moVS   
        /*objwebexchangerequestcstrquerypayl: */
        objwebexchangerequestcstrquerypayl_BM (( /*o_webex: */ _.
                                                o_5JuT4FgNFFh_7McrTYeT3jx),
                                               ("foo"));


      /*v_postbar: */ _.v_2nnQQ6Lvtpl_4oCJYx90FlI =
        //assign _3vXdUQt5mey_5MeGY4lFI0J   
        /*objwebexchangerequestcstrpostpayl: */
        objwebexchangerequestcstrpostpayl_BM (( /*o_webex: */ _.
                                               o_5JuT4FgNFFh_7McrTYeT3jx),
                                              ("bar"));


      if                        /*cond _2THq8nc1q1F_4cGFcYCkXve */
/*when _60Hl1XdMfUK_1F8CwPaYrTV:*/
        ( /*v_queryfoo: */ _.v_8s5u19T0e2h_9ZqrO3YZDVS)
        {                       //body when _60Hl1XdMfUK_1F8CwPaYrTV   
          {                     // start cexpansion _6QzWx6GgQRi_384FRK3jVwG - objstrbufferappendcstrpayl    
            /*objstrbufferappendcstrpayl: */
            objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                            o_5JuT4FgNFFh_7McrTYeT3jx),
                                           ("<p>With <i>foo</i> query: <tt>"));
          }                     // end cexpansion _6QzWx6GgQRi_384FRK3jVwG - objstrbufferappendcstrpayl    
          {                     // start cexpansion _6KDkrFdjO9P_14wFqrvJOfp - objstrbufferprinthtmlstringval    
/*objstrbufferprinthtmlstringval:*/
            if (objhasstrbufferpayl_BM
                ( /*o_webex: */ _.o_5JuT4FgNFFh_7McrTYeT3jx)
                && isstring_BM ( /*v_queryfoo: */ _.
                                v_8s5u19T0e2h_9ZqrO3YZDVS))
              objstrbufferencodedhtmlpayl_BM (( /*o_webex: */ _.
                                               o_5JuT4FgNFFh_7McrTYeT3jx), bytstring_BM (       /*v_queryfoo: */
                                                                                          _.v_8s5u19T0e2h_9ZqrO3YZDVS), lenstring_BM (  /*v_queryfoo: */
                                                                                                                                       _.v_8s5u19T0e2h_9ZqrO3YZDVS));;
          }                     // end cexpansion _6KDkrFdjO9P_14wFqrvJOfp - objstrbufferprinthtmlstringval    
          {                     // start cexpansion _2vbuTjbZtsO_572Ywmb2g5P - objstrbufferappendcstrpayl    
            /*objstrbufferappendcstrpayl: */
            objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                            o_5JuT4FgNFFh_7McrTYeT3jx),
                                           ("</tt></p>\n"));
          }                     // end cexpansion _2vbuTjbZtsO_572Ywmb2g5P - objstrbufferappendcstrpayl    

        }                       //endwhen _60Hl1XdMfUK_1F8CwPaYrTV   
      else
        {                       /*cond else _2THq8nc1q1F_4cGFcYCkXve */
          {                     // start cexpansion _6RNWoVxR1o8_1HcOAeanMtD - objstrbufferappendcstrpayl   
            /*objstrbufferappendcstrpayl: */
            objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                            o_5JuT4FgNFFh_7McrTYeT3jx),
                                           ("<p><b>No</b> <i>foo</i> query!</p>\n"));
          }                     // end cexpansion _6RNWoVxR1o8_1HcOAeanMtD - objstrbufferappendcstrpayl   
        }                       /*cond else _2THq8nc1q1F_4cGFcYCkXve */
/*endcond _2THq8nc1q1F_4cGFcYCkXve*/


      if                        /*cond _057nvpyNs61_4NN6PpJ3blv */
/*when _3nPbGhqwKVU_6YbKeoirRRT:*/
        ( /*v_postbar: */ _.v_2nnQQ6Lvtpl_4oCJYx90FlI)
        {                       //body when _3nPbGhqwKVU_6YbKeoirRRT   
          {                     // start cexpansion _8iDfqbg4KqL_76BIqjTrj3e - objstrbufferappendcstrpayl    
            /*objstrbufferappendcstrpayl: */
            objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                            o_5JuT4FgNFFh_7McrTYeT3jx),
                                           ("<p>With <i>bar</i> query post: <tt>"));
          }                     // end cexpansion _8iDfqbg4KqL_76BIqjTrj3e - objstrbufferappendcstrpayl    
          {                     // start cexpansion _27sh4N25FsE_1pTCEF1T86V - objstrbufferprinthtmlstringval    
/*objstrbufferprinthtmlstringval:*/
            if (objhasstrbufferpayl_BM
                ( /*o_webex: */ _.o_5JuT4FgNFFh_7McrTYeT3jx)
                && isstring_BM ( /*v_postbar: */ _.v_2nnQQ6Lvtpl_4oCJYx90FlI))
              objstrbufferencodedhtmlpayl_BM (( /*o_webex: */ _.
                                               o_5JuT4FgNFFh_7McrTYeT3jx), bytstring_BM (       /*v_postbar: */
                                                                                          _.v_2nnQQ6Lvtpl_4oCJYx90FlI), lenstring_BM (  /*v_postbar: */
                                                                                                                                       _.v_2nnQQ6Lvtpl_4oCJYx90FlI));;
          }                     // end cexpansion _27sh4N25FsE_1pTCEF1T86V - objstrbufferprinthtmlstringval    
          {                     // start cexpansion _8OWeFkBKHSs_8iHHVgkRKA9 - objstrbufferappendcstrpayl    
            /*objstrbufferappendcstrpayl: */
            objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                            o_5JuT4FgNFFh_7McrTYeT3jx),
                                           ("</tt></p>\n"));
          }                     // end cexpansion _8OWeFkBKHSs_8iHHVgkRKA9 - objstrbufferappendcstrpayl    

        }                       //endwhen _3nPbGhqwKVU_6YbKeoirRRT   
      else
        {                       /*cond else _057nvpyNs61_4NN6PpJ3blv */
          {                     // start cexpansion _1KQI2bY1P58_8cNaZP3fXxP - objstrbufferappendcstrpayl   
            /*objstrbufferappendcstrpayl: */
            objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                            o_5JuT4FgNFFh_7McrTYeT3jx),
                                           ("<p><b>No</b> <i>bar</i> post!</p>\n"));
          }                     // end cexpansion _1KQI2bY1P58_8cNaZP3fXxP - objstrbufferappendcstrpayl   
        }                       /*cond else _057nvpyNs61_4NN6PpJ3blv */
/*endcond _057nvpyNs61_4NN6PpJ3blv*/


      {                         // start cexpansion _1cxOV5GldRc_8pSs0K0x3sK - objstrbufferappendcstrpayl   
        /*objstrbufferappendcstrpayl: */
        objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                        o_5JuT4FgNFFh_7McrTYeT3jx),
                                       ("<form method=\'post\'><i>bar:</i> <input type=\'text\' name=\'bar\'/> <input type=\'submit\' name=\'dosubmit\' value=\'do!\'/> </form>\n"));
      }                         // end cexpansion _1cxOV5GldRc_8pSs0K0x3sK - objstrbufferappendcstrpayl   


      {                         // start cexpansion _5fVxVvN0D70_5iLoRUEbGnA - objstrbufferappendcstrpayl   
        /*objstrbufferappendcstrpayl: */
        objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                        o_5JuT4FgNFFh_7McrTYeT3jx),
                                       ("<p>Generated at <i>"));
      }                         // end cexpansion _5fVxVvN0D70_5iLoRUEbGnA - objstrbufferappendcstrpayl   


      {                         // start cexpansion _6nzVdVGk8wB_0paW5wP6NFo - objstrbufferprinthtmlstringval   
/*objstrbufferprinthtmlstringval:*/
        if (objhasstrbufferpayl_BM
            ( /*o_webex: */ _.o_5JuT4FgNFFh_7McrTYeT3jx)
            && isstring_BM ( /*flocaltimestring: */ (value_tyBM)
                            flocaltimestring_BM (("%c"), (time_t) (     /*timenow: */
                                                                    (intptr_t)
                                                                    time
                                                                    (NULL)))))
          objstrbufferencodedhtmlpayl_BM (( /*o_webex: */ _.
                                           o_5JuT4FgNFFh_7McrTYeT3jx),
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
        /*objstrbufferappendcstrpayl: */
        objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                        o_5JuT4FgNFFh_7McrTYeT3jx),
                                       ("</i>.</p>\n"));
      }                         // end cexpansion _9xLEdrWsdEt_3HIoqy3EsOT - objstrbufferappendcstrpayl   

/* !endingblock _3VVvcLyYqv8_9yci7GvqEEv */
      goto endblock__3VVvcLyYqv8_9yci7GvqEEv;
    endblock__3VVvcLyYqv8_9yci7GvqEEv:;
    }
  /*-block _3VVvcLyYqv8_9yci7GvqEEv */

    {                           // start cexpansion _7JswZzcJki7_3B8LL8KLffZ - objstrbufferappendcstrpayl  
      /*objstrbufferappendcstrpayl: */
      objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                      o_5JuT4FgNFFh_7McrTYeT3jx),
                                     ("</body>\n</html>"));
    }                           // end cexpansion _7JswZzcJki7_3B8LL8KLffZ - objstrbufferappendcstrpayl  


    {                           // start cexpansion _0aLvox3qw9g_6O8WY6Cew3g - objwebexchangecompletepayl  
      /*objwebexchangecompletepayl: */
      objwebexchangecompletepayl_BM (( /*o_webex: */ _.
                                      o_5JuT4FgNFFh_7McrTYeT3jx), (200),
                                     ("text/html; charset=utf-8"));
    }                           // end cexpansion _0aLvox3qw9g_6O8WY6Cew3g - objwebexchangecompletepayl  


    /*return _8VHbQSvNRq4_44CGuKiIMLb: *//*v_r: */ _.
      v_3qw9bnATIhq_8loBraLeXzQ =
      // returned 
      /*o_webex: */ _.o_5JuT4FgNFFh_7McrTYeT3jx;
    goto epilog_0cUdonky1bM_4IVhwlVRBMk;



  startblock__4ZE2MUVTcHt_4lWsA1elKmS:__attribute__ ((unused));
    {                           /* +block _4ZE2MUVTcHt_4lWsA1elKmS */
      {                         // start cexpansion _2CWJlYEwmaf_6nlLCxAfCx8 - objstrbufferappendcstrpayl   
        /*objstrbufferappendcstrpayl: */
        objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                        o_5JuT4FgNFFh_7McrTYeT3jx),
                                       ("<!DOCTYPE html>\n<html><head><title>testhello bismon</title>\n"));
      }                         // end cexpansion _2CWJlYEwmaf_6nlLCxAfCx8 - objstrbufferappendcstrpayl   


      {                         // start cexpansion _07IfSVe5oBj_7I7w9nZbfgr - objstrbufferappendcstrpayl   
        /*objstrbufferappendcstrpayl: */
        objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                        o_5JuT4FgNFFh_7McrTYeT3jx),
                                       ("</head>\n"));
      }                         // end cexpansion _07IfSVe5oBj_7I7w9nZbfgr - objstrbufferappendcstrpayl   


      {                         // start cexpansion _4ootClJhCCt_4B3yo2Szuwj - objstrbufferappendcstrpayl   
        /*objstrbufferappendcstrpayl: */
        objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                        o_5JuT4FgNFFh_7McrTYeT3jx),
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
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _0cUdonky1bM_4IVhwlVRBMk routine#1 _0cUdonky1bM_4IVhwlVRBMk




value_tyBM crout_0JktC4mAHCa_1KNr6uMIqIi_BM     //#2
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[6] /*|_0JktC4mAHCa_1KNr6uMIqIi */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 2 arguments:
  _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0);   // o1
  _.o_93FBSk1ML0f_2WjSuKa9TNU = objectcast_BM (arg1);   // o2
  // fetched 2 arguments.
  // no closed values in _0JktC4mAHCa_1KNr6uMIqIi.
  // routine _0JktC4mAHCa_1KNr6uMIqIi body:

startblock__9xHQlk4snoU_6unWwGT6PcG:__attribute__ ((unused));
  {                             /* +block _9xHQlk4snoU_6unWwGT6PcG */
    /*v_node: */ _.v_2BkOxf2KbS8_3bswrKbmgjy =
      //assign _8ggHPTQI1iG_02hVE5KybEL  
      /*objlisttonodepayl: */
      (value_tyBM)
      objlisttonodepayl_BM (( /*o1: */ _.o_97rnxb0KFqq_44veN75DG2E),
                            ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[53]
                              /*|node */ )));


    /*leni: */ _.n_833x2jYqhZh_8vDIuJhwz1k =
      //assign _0zhpGzEVWGP_7WoL4LJocuS  
      /*nodewidth: */
      (intptr_t) nodewidth_BM ( /*v_node: */ _.v_2BkOxf2KbS8_3bswrKbmgjy);


    /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B =
      //assign _0fygl91r6x5_8b3aCDptjAi  
      0;



//// +while _1w1gkKpMOzk_6mZXddz3Y4L 
  startblock__1w1gkKpMOzk_6mZXddz3Y4L: /*+!while */ ;
    {                           /* +while _1w1gkKpMOzk_6mZXddz3Y4L */
      if (!( /*while _1w1gkKpMOzk_6mZXddz3Y4L cond: */ ( /*less_int: */ ( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B) < ( /*leni: */ _.n_833x2jYqhZh_8vDIuJhwz1k))))  //: testwhile _1w1gkKpMOzk_6mZXddz3Y4L failing   
        goto endblock__1w1gkKpMOzk_6mZXddz3Y4L; //failwhile   
// while _1w1gkKpMOzk_6mZXddz3Y4L body:   
// while _1w1gkKpMOzk_6mZXddz3Y4L comp#0:  
      {                         // start cexpansion _4048rnGI686_6URARAINwQH - obdumpscanvalue   
        /*obdumpscanvalue: */
        obdumpscanvalue_BM (( /*o2: */ _.o_93FBSk1ML0f_2WjSuKa9TNU),
                            (   /*nodenthson: */
                              nodenthson_BM (( /*v_node: */ _.
                                              v_2BkOxf2KbS8_3bswrKbmgjy),
                                             ( /*ii: */ _.
                                              n_2W7Ckt2WxEM_4NVYgEWE73B))),
                            (0));
      }                         // end cexpansion _4048rnGI686_6URARAINwQH - obdumpscanvalue   
// while _1w1gkKpMOzk_6mZXddz3Y4L comp#1:  
      /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B =
        //assign _5fibWpWyCTN_8xn6wySOLhA   
        /*add_int: */ (( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B) + (1));

      goto startblock__1w1gkKpMOzk_6mZXddz3Y4L; // repeatwhile  
    endblock__1w1gkKpMOzk_6mZXddz3Y4L: /*endingwhile */ ;
    }
  /*-endwhile _1w1gkKpMOzk_6mZXddz3Y4L */


/* !endingblock _9xHQlk4snoU_6unWwGT6PcG */
    goto endblock__9xHQlk4snoU_6unWwGT6PcG;
  endblock__9xHQlk4snoU_6unWwGT6PcG:;
  }
  /*-block _9xHQlk4snoU_6unWwGT6PcG */

epilog_0JktC4mAHCa_1KNr6uMIqIi:__attribute__ ((unused));
  // routine _0JktC4mAHCa_1KNr6uMIqIi epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _0JktC4mAHCa_1KNr6uMIqIi routine#2 _0JktC4mAHCa_1KNr6uMIqIi




value_tyBM crout_0SinERsgdvQ_57dLCP63i9r_BM     //#3
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[8] /*|_0SinERsgdvQ_57dLCP63i9r */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 1 arguments:
  _.v_4Q4WBLjAPTV_5WVLmhAvCJY = arg0;   // v_arg
  // fetched 1 arguments.
  // no closed values in _0SinERsgdvQ_57dLCP63i9r.
  // routine _0SinERsgdvQ_57dLCP63i9r body:

startblock__84ATc5kpHjd_2wlYHZEUoeb:__attribute__ ((unused));
  {                             /* +block _84ATc5kpHjd_2wlYHZEUoeb */
    if                          /*cond _0Vnb5tJpsaA_9C18YQWoCmH */
/*when _7aRr2DYoXS7_0jbH59RVcFR:*/
      (                         /*is_objectv */
        isobject_BM ( /*v_arg: */ _.v_4Q4WBLjAPTV_5WVLmhAvCJY))
      {                         //body when _7aRr2DYoXS7_0jbH59RVcFR  
        /*o_arg: */ _.o_7daWyW7jPyL_0EvyGgObjJm =
          //assign _1eDeH7xPojd_3uCQMEEBsHc   
          /*val_to_object: */
          objectcast_BM ( /*v_arg: */ _.v_4Q4WBLjAPTV_5WVLmhAvCJY);

        {                       // run _5cqLFnQUJtD_2QMjkdfqr6q  
          forgetnamedobject_BM ( /*o_arg: */ _.o_7daWyW7jPyL_0EvyGgObjJm);
        }                       // end run _5cqLFnQUJtD_2QMjkdfqr6q  

        {                       // run _8y60zCwYsj4_4MKReQrfwGI  
          if (pthread_self () == mainthreadid_BM)
            {
              log_begin_message_BM ();
              log_puts_message_BM ("Forgot name of object ");
              log_object_message_BM ( /*o_arg: */ _.
                                     o_7daWyW7jPyL_0EvyGgObjJm);
              log_puts_message_BM (".");
              log_end_message_BM ();
            }
          ;
        }                       // end run _8y60zCwYsj4_4MKReQrfwGI  
        /*return _8X0BDdDTJe6_8OoRGA5RDeF: *//*v_r: */ _.
          v_3qw9bnATIhq_8loBraLeXzQ =
          // returned  
          /*o_arg: */ _.o_7daWyW7jPyL_0EvyGgObjJm;
        goto epilog_0SinERsgdvQ_57dLCP63i9r;

      }                         //endwhen _7aRr2DYoXS7_0jbH59RVcFR  
    else if
/*when _3674ULyT2hz_5gMJA95w9aB:*/
      (                         /*issequence: */
        issequence_BM ( /*v_arg: */ _.v_4Q4WBLjAPTV_5WVLmhAvCJY))
      {                         //body when _3674ULyT2hz_5gMJA95w9aB  

        {                       // run _2Gx3OIyj6WH_36HZRfp3Slv  
          (apply1_BM (((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[60]
                        /*!iterate_sequence_minifunc */ )),
                      ((struct stackframe_stBM *) &_),
                      ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[8]
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
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _0SinERsgdvQ_57dLCP63i9r routine#3 _0SinERsgdvQ_57dLCP63i9r




value_tyBM crout_0YOXUe7rEJC_3jFMjOAQRs9_BM     //#4+
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[10] /*|element_of_closed_minifunc */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 1 arguments:
  _.v_4Q4WBLjAPTV_5WVLmhAvCJY = arg0;   // v_arg
  // fetched 1 arguments.
  {                             // fetch 1 closed values in element_of_closed_minifunc:
    const closure_tyBM *callclos_0YOXUe7rEJC_3jFMjOAQRs9 =
      (stkf && stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
      ? (closurecast_BM (stkf->stkfram_callfun)) : NULL;
    unsigned nbclosed_0YOXUe7rEJC_3jFMjOAQRs9 =
      closurewidth_BM ((const value_tyBM) callclos_0YOXUe7rEJC_3jFMjOAQRs9);
    if (nbclosed_0YOXUe7rEJC_3jFMjOAQRs9 > 0)
      _.v_5EEITf6IFH7_4DbKG99zcPW = callclos_0YOXUe7rEJC_3jFMjOAQRs9->nodt_sons[0];     // v1
  }                             // fetched 1 closed values in _0YOXUe7rEJC_3jFMjOAQRs9.
  // routine _0YOXUe7rEJC_3jFMjOAQRs9 body:

startblock__7gnMvoTqaQY_3kAwj2rwZEM:__attribute__ ((unused));
  {                             /* +block _7gnMvoTqaQY_3kAwj2rwZEM */
    /*o1: */ _.o_97rnxb0KFqq_44veN75DG2E =
      //assign _11EvX29IHDi_1da6fY8nL7Y  
      /*val_to_object: */
      objectcast_BM ( /*v_arg: */ _.v_4Q4WBLjAPTV_5WVLmhAvCJY);


    if                          /*cond _0WAyTs536mS_7eZ58PLoYjP */
/*when _2U8EKCOdizu_8BNXvpmwd43:*/
      ((                        /*set_contains: */
         setcontains_BM (( /*v1: */ _.v_5EEITf6IFH7_4DbKG99zcPW),
                         ( /*o1: */ _.o_97rnxb0KFqq_44veN75DG2E))))
      {                         //body when _2U8EKCOdizu_8BNXvpmwd43  
        /*return _4rFgWAf3aqA_0UBP8b4hESV: *//*v_r: */ _.
          v_3qw9bnATIhq_8loBraLeXzQ =
          // returned  
          /*o1: */ _.o_97rnxb0KFqq_44veN75DG2E;
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
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _0YOXUe7rEJC_3jFMjOAQRs9 routine#4 element_of_closed_minifunc




value_tyBM crout_1HZc1VBbjdB_96aQTEPgEX0_BM     //#5
  (struct stackframe_stBM * stkf,       //
//!emit_prologue_jsmodule°jsmodule_generation_object
   // 2 arguments
   const value_tyBM arg0,       // o_jsgenmod
   const value_tyBM arg1,       // o_strbuf
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _1HZc1VBbjdB_96aQTEPgEX0
  struct frame_1HZc1VBbjdB_96aQTEPgEX0_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 5 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    objectval_tyBM *o_41F1rKwGbaA_30OJWKsqNWy;  // o_strbuf
    objectval_tyBM *o_4JKd986pvM4_6yBzeeI40vW;  // o_jsgenmod
    objectval_tyBM *o_5HkpTupRRIK_8iCooVukjb3;  // o_bindings
    objectval_tyBM *o_5V0w37YnN4F_8dZ6I79V60O;  // o_jsmodule
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_1HZc1VBbjdB_96aQTEPgEX0_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 5;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[15] /*|_1HZc1VBbjdB_96aQTEPgEX0 */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 2 arguments:
  _.o_4JKd986pvM4_6yBzeeI40vW = objectcast_BM (arg0);   // o_jsgenmod
  _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg1);   // o_strbuf
  // fetched 2 arguments.
  // no closed values in _1HZc1VBbjdB_96aQTEPgEX0.
  // routine _1HZc1VBbjdB_96aQTEPgEX0 body:

startblock__97aF43R1sX0_4RGoHiXCqjO:__attribute__ ((unused));
  {                             /* +block _97aF43R1sX0_4RGoHiXCqjO */

    {                           // run _8vBskZZJ2Hf_1jdBnECZUSJ 

/*debug  emit_prologue_jsmodule°jsmodule_generation_object start*/
      DBGPRINTF_BM
        ("emit_prologue_jsmodule°jsmodule_generation_object start o_jsgenmod %s, o_strbuf %s",
         objectdbg_BM ( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW),
         objectdbg1_BM ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy));
      ;
    }                           // end run _8vBskZZJ2Hf_1jdBnECZUSJ 


    {                           // start cexpansion _0AUttc9DFqB_2C7fGlBJAxC - objstrbufferappendcstrpayl  
      /*objstrbufferappendcstrpayl: */
      objstrbufferappendcstrpayl_BM (( /*o_strbuf: */ _.
                                      o_41F1rKwGbaA_30OJWKsqNWy),
                                     ("// generated javascript from "));
    }                           // end cexpansion _0AUttc9DFqB_2C7fGlBJAxC - objstrbufferappendcstrpayl  


    /*o_jsmodule: */ _.o_5V0w37YnN4F_8dZ6I79V60O =
      //assign _4Yn8XDOP2nB_0L3V8U88UpE  
      /*val_to_object: */
      objectcast_BM (           /*objgetattr: */
                      objgetattr_BM (( /*o_jsgenmod: */ _.
                                      o_4JKd986pvM4_6yBzeeI40vW),
                                     ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[16]
                                       /*!for */ ))));


    {                           // start cexpansion _5YHmdVKNtkY_4sPvxIu308j - objstrbufferprintobject  
/*objstrbufferprintobject _5YHmdVKNtkY_4sPvxIu308j:*/
      objectval_tyBM *obsbuf_5YHmdVKNtkY_4sPvxIu308j =
        ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy);
      objectval_tyBM *ob_5YHmdVKNtkY_4sPvxIu308j =
        ( /*o_jsmodule: */ _.o_5V0w37YnN4F_8dZ6I79V60O);
      if (objhasstrbufferpayl_BM (obsbuf_5YHmdVKNtkY_4sPvxIu308j)
          && isobject_BM (ob_5YHmdVKNtkY_4sPvxIu308j))
        objstrbufferappendcstrpayl_BM (obsbuf_5YHmdVKNtkY_4sPvxIu308j,
                                       objectdbg_BM
                                       (ob_5YHmdVKNtkY_4sPvxIu308j));
// end objstrbufferprintobject _5YHmdVKNtkY_4sPvxIu308j
      ;
    }                           // end cexpansion _5YHmdVKNtkY_4sPvxIu308j - objstrbufferprintobject  


    {                           // start cexpansion _6CzjvS4ZeEd_3jgRd8wIaO3 - objstrbufferappendcstrpayl  
      /*objstrbufferappendcstrpayl: */
      objstrbufferappendcstrpayl_BM (( /*o_strbuf: */ _.
                                      o_41F1rKwGbaA_30OJWKsqNWy),
                                     (" - generated script under GPLv3+ licence\n"));
    }                           // end cexpansion _6CzjvS4ZeEd_3jgRd8wIaO3 - objstrbufferappendcstrpayl  


    {                           // start cexpansion _9qubKXDFJ9a_06d4mGhbGcD - objstrbufferappendcstrpayl  
      /*objstrbufferappendcstrpayl: */
      objstrbufferappendcstrpayl_BM (( /*o_strbuf: */ _.
                                      o_41F1rKwGbaA_30OJWKsqNWy),
                                     ("// with "));
    }                           // end cexpansion _9qubKXDFJ9a_06d4mGhbGcD - objstrbufferappendcstrpayl  


    {                           // start cexpansion _5QvtZKje3kD_3tHLU6QnZ4Z - objstrbufferprintint  
      /*objstrbufferprintint: */
      if (objhasstrbufferpayl_BM
          ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy))
        {
          char buf_5QvtZKje3kD_3tHLU6QnZ4Z[32];
          memset (buf_5QvtZKje3kD_3tHLU6QnZ4Z, 0,
                  sizeof (buf_5QvtZKje3kD_3tHLU6QnZ4Z));
          snprintf (buf_5QvtZKje3kD_3tHLU6QnZ4Z,
                    sizeof (buf_5QvtZKje3kD_3tHLU6QnZ4Z), "%lld",
                    (long long) /*objnbcomps: */ objnbcomps_BM ( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW));
          objstrbufferappendcstrpayl_BM (( /*o_strbuf: */ _.
                                          o_41F1rKwGbaA_30OJWKsqNWy),
                                         buf_5QvtZKje3kD_3tHLU6QnZ4Z);
        }                       //end objstrbufferprintint _5QvtZKje3kD_3tHLU6QnZ4Z
      ;
    }                           // end cexpansion _5QvtZKje3kD_3tHLU6QnZ4Z - objstrbufferprintint  


    {                           // start cexpansion _40NemiO6zBn_3j7KYbIOPUv - objstrbufferappendcstrpayl  
      /*objstrbufferappendcstrpayl: */
      objstrbufferappendcstrpayl_BM (( /*o_strbuf: */ _.
                                      o_41F1rKwGbaA_30OJWKsqNWy),
                                     (" components:"));
    }                           // end cexpansion _40NemiO6zBn_3j7KYbIOPUv - objstrbufferappendcstrpayl  


    {                           // start cexpansion _3AEDXT43wEP_2xOTOn1ZvkA - objstrbuffernewlinepayl  
                                                                        /*objstrbuffernewlinepayl: */ objstrbuffernewlinepayl_BM (
                                                                        /*o_strbuf: */
                                                                                                                                   _.o_41F1rKwGbaA_30OJWKsqNWy);
    }                           // end cexpansion _3AEDXT43wEP_2xOTOn1ZvkA - objstrbuffernewlinepayl  


    {                           // start cexpansion _5myPgr3VSsm_4V8dUGh1pWs - objstrbuffernewlinepayl  
                                                                        /*objstrbuffernewlinepayl: */ objstrbuffernewlinepayl_BM (
                                                                        /*o_strbuf: */
                                                                                                                                   _.o_41F1rKwGbaA_30OJWKsqNWy);
    }                           // end cexpansion _5myPgr3VSsm_4V8dUGh1pWs - objstrbuffernewlinepayl  


    {                           // start cexpansion _03Bdhkaqibd_6iFalfaX0oB - objstrbuffernewlinepayl  
                                                                        /*objstrbuffernewlinepayl: */ objstrbuffernewlinepayl_BM (
                                                                        /*o_strbuf: */
                                                                                                                                   _.o_41F1rKwGbaA_30OJWKsqNWy);
    }                           // end cexpansion _03Bdhkaqibd_6iFalfaX0oB - objstrbuffernewlinepayl  


    /*return _0sVzIFrQLiD_3p3KzEwJBW0: *//*v_r: */ _.
      v_3qw9bnATIhq_8loBraLeXzQ =
      // returned 
      /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW;
    goto epilog_1HZc1VBbjdB_96aQTEPgEX0;

/* !endingblock _97aF43R1sX0_4RGoHiXCqjO */
    goto endblock__97aF43R1sX0_4RGoHiXCqjO;
  endblock__97aF43R1sX0_4RGoHiXCqjO:;
  }
  /*-block _97aF43R1sX0_4RGoHiXCqjO */

epilog_1HZc1VBbjdB_96aQTEPgEX0:__attribute__ ((unused));
  // routine _1HZc1VBbjdB_96aQTEPgEX0 epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _1HZc1VBbjdB_96aQTEPgEX0 routine#5 _1HZc1VBbjdB_96aQTEPgEX0




value_tyBM crout_22Zd68WPKUO_6AoIuBcbUb2_BM     //#6
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[17] /*|_22Zd68WPKUO_6AoIuBcbUb2 */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 2 arguments:
  _.o_7n2SLLuWOjH_4ArhFUjmckz = objectcast_BM (arg0);   // odict
  _.o_3cTC8W7d75H_1vteOyEoAao = objectcast_BM (arg1);   // odumper
  // fetched 2 arguments.
  // no closed values in _22Zd68WPKUO_6AoIuBcbUb2.
  // routine _22Zd68WPKUO_6AoIuBcbUb2 body:

startblock__7csjYG7rNV4_68bJZT4W2BO:__attribute__ ((unused));
  {                             /* +block _7csjYG7rNV4_68bJZT4W2BO */
    /*v_str: */ _.v_167WczZjWtG_3FofhJxQWJi =
      //assign _5mCmWSYOW7T_4G9YRC6tvRf  
      /*objdictfirstkeypayl: */
      (value_tyBM)
      objdictfirstkeypayl_BM (( /*odict: */ _.o_7n2SLLuWOjH_4ArhFUjmckz));



//// +while _0SWi4IZCeP3_0VPExGvOasL 
  startblock__0SWi4IZCeP3_0VPExGvOasL: /*+!while */ ;
    {                           /* +while _0SWi4IZCeP3_0VPExGvOasL */
      if (!( /*while _0SWi4IZCeP3_0VPExGvOasL cond: *//*v_str: */ _.v_167WczZjWtG_3FofhJxQWJi)) //: testwhile _0SWi4IZCeP3_0VPExGvOasL failing  
        goto endblock__0SWi4IZCeP3_0VPExGvOasL; //failwhile  
// while _0SWi4IZCeP3_0VPExGvOasL body:  
// while _0SWi4IZCeP3_0VPExGvOasL comp#0:  
      /*v_val: */ _.v_5jRQCD1qTko_61I0j04ugAA =
        //assign _2dCjJpUS20B_3NM9eVa84hQ   
        /*objdictgetpayl: */
        objdictgetpayl_BM (( /*odict: */ _.o_7n2SLLuWOjH_4ArhFUjmckz),
                           stringcast_BM ( /*v_str: */ _.
                                          v_167WczZjWtG_3FofhJxQWJi));
// while _0SWi4IZCeP3_0VPExGvOasL comp#1:  
      {                         // start cexpansion _0LKRJrD5wqK_5ZE495IAA7d - obdumpscanvalue   
        /*obdumpscanvalue: */
        obdumpscanvalue_BM (( /*odumper: */ _.o_3cTC8W7d75H_1vteOyEoAao),
                            ( /*v_val: */ _.v_5jRQCD1qTko_61I0j04ugAA),
                            (1));
      }                         // end cexpansion _0LKRJrD5wqK_5ZE495IAA7d - obdumpscanvalue   
// while _0SWi4IZCeP3_0VPExGvOasL comp#2:  
      /*v_str: */ _.v_167WczZjWtG_3FofhJxQWJi =
        //assign _5UiotUrFshh_9xWCmys30Pe   
        /*objdictkeyafterpayl: */
        (value_tyBM)
        objdictkeyafterpayl_BM (( /*odict: */ _.o_7n2SLLuWOjH_4ArhFUjmckz),
                                stringcast_BM ( /*v_str: */ _.
                                               v_167WczZjWtG_3FofhJxQWJi));

      goto startblock__0SWi4IZCeP3_0VPExGvOasL; // repeatwhile  
    endblock__0SWi4IZCeP3_0VPExGvOasL: /*endingwhile */ ;
    }
  /*-endwhile _0SWi4IZCeP3_0VPExGvOasL */



    /*return _8pmMgF3SSuE_2COzwjyI8lS: *//*v_r: */ _.
      v_3qw9bnATIhq_8loBraLeXzQ =
      // returned 
      /*odict: */ _.o_7n2SLLuWOjH_4ArhFUjmckz;
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
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _22Zd68WPKUO_6AoIuBcbUb2 routine#6 _22Zd68WPKUO_6AoIuBcbUb2




value_tyBM crout_2bZ4BfCci5V_3WTzG7V25y4_BM     //#7
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[20] /*|_2bZ4BfCci5V_3WTzG7V25y4 */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 3 arguments:
  _.o_7n2SLLuWOjH_4ArhFUjmckz = objectcast_BM (arg0);   // odict
  _.v_167WczZjWtG_3FofhJxQWJi = arg1;   // v_str
  _.v_5jRQCD1qTko_61I0j04ugAA = arg2;   // v_val
  // fetched 3 arguments.
  // no closed values in _2bZ4BfCci5V_3WTzG7V25y4.
  // routine _2bZ4BfCci5V_3WTzG7V25y4 body:

startblock__0VJTIqFfNXf_5chzuIlqcJP:__attribute__ ((unused));
  {                             /* +block _0VJTIqFfNXf_5chzuIlqcJP */
    if                          /*cond _838sw9thRfn_03qQ7lMn8Ij */
/*when _2aMZ0ZBgKj2_35QKBjbmq4w:*/
      (                         /*objhasdictpayl: */
        objhasdictpayl_BM (( /*odict: */ _.o_7n2SLLuWOjH_4ArhFUjmckz)))
      {                         //body when _2aMZ0ZBgKj2_35QKBjbmq4w  
        if                      /*cond _58oNVcHAUe4_3Z3PsPWQQWC */
/*when _5Zj20zoTMgi_2wX9L155Qet:*/
          (                     /*isstring: */
            isstring_BM ( /*v_str: */ _.v_167WczZjWtG_3FofhJxQWJi))
          {                     //body when _5Zj20zoTMgi_2wX9L155Qet   
            {                   // start cexpansion _7T2FZv58UYu_1HHqslZTor2 - objdictputpayl    
              /*objdictputpayl: */
              objdictputpayl_BM (( /*odict: */ _.o_7n2SLLuWOjH_4ArhFUjmckz),
                                 ( /*v_str: */ _.v_167WczZjWtG_3FofhJxQWJi),
                                 ( /*v_val: */ _.
                                  v_5jRQCD1qTko_61I0j04ugAA));
            }                   // end cexpansion _7T2FZv58UYu_1HHqslZTor2 - objdictputpayl    
            /*return _3Q8xwomyj4D_36oIs4VyEfB: *//*v_r: */ _.
              v_3qw9bnATIhq_8loBraLeXzQ =
              // returned   
              /*odict: */ _.o_7n2SLLuWOjH_4ArhFUjmckz;
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
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _2bZ4BfCci5V_3WTzG7V25y4 routine#7 _2bZ4BfCci5V_3WTzG7V25y4




value_tyBM crout_3iiht57Wrs1_5NbiUi27oBn_BM     //#8
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[23] /*|_3iiht57Wrs1_5NbiUi27oBn */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 2 arguments:
  _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0);   // o1
  _.v_09RxU8xDco3_2Zxwfb13oDZ = arg1;   // v2
  // fetched 2 arguments.
  // no closed values in _3iiht57Wrs1_5NbiUi27oBn.
  // routine _3iiht57Wrs1_5NbiUi27oBn body:

startblock__9BLJq5DadtZ_6I89t7ioVRS:__attribute__ ((unused));
  {                             /* +block _9BLJq5DadtZ_6I89t7ioVRS */
    if                          /*cond _2cKxScfQVIk_8j9yMA8y0D2 */
/*when _9Eu315oGSiW_2T0LUr58JnT:*/
      (                         /*objhaslistpayl: */
        objhaslistpayl_BM (( /*o1: */ _.o_97rnxb0KFqq_44veN75DG2E)))
      {                         //body when _9Eu315oGSiW_2T0LUr58JnT  
        {                       // start cexpansion _8K97qV68UiQ_0ssdaZQW9h5 - objlistprependpayl   
          /*objlistprependpayl: */
          objlistprependpayl_BM (( /*o1: */ _.o_97rnxb0KFqq_44veN75DG2E),
                                 ( /*v2: */ _.v_09RxU8xDco3_2Zxwfb13oDZ));
        }                       // end cexpansion _8K97qV68UiQ_0ssdaZQW9h5 - objlistprependpayl   
        /*return _3Hj8WH5oi59_3L07vytBdDJ: *//*v_r: */ _.
          v_3qw9bnATIhq_8loBraLeXzQ =
          // returned  
          /*o1: */ _.o_97rnxb0KFqq_44veN75DG2E;
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
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _3iiht57Wrs1_5NbiUi27oBn routine#8 _3iiht57Wrs1_5NbiUi27oBn




value_tyBM crout_3vI0Qc3FHQG_1g4fmHYkxSA_BM     //#9
  (struct stackframe_stBM * stkf,       //
//!compile_to_javascript°jsmodule_object (o_jsmodule, o_strbuf)
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
    /// 9 local values:
    value_tyBM v_0qTBOEAT5pa_2fz1SKfHrMV;       // v_resemit
    objectval_tyBM *o_2TaoEvH5OQU_8nKYBgAvkmW;  // o_jscurcomp
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    objectval_tyBM *o_41F1rKwGbaA_30OJWKsqNWy;  // o_strbuf
    objectval_tyBM *o_4JKd986pvM4_6yBzeeI40vW;  // o_jsgenmod
    objectval_tyBM *o_5HkpTupRRIK_8iCooVukjb3;  // o_bindings
    objectval_tyBM *o_5V0w37YnN4F_8dZ6I79V60O;  // o_jsmodule
    objectval_tyBM *o_6Z4UU939WbU_8BK9xcKsXNb;  // o_comp
    value_tyBM v_7nytuRkZkOz_8T9QMYQtGps;       // v_resprep
    /// 4 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_7W30qK9YBqp_7HSwYPdVkKi; // lenres
    intptr_t n_81BTKsrnoY8_2DoVevLPfsN; // jj
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
  } _;
  memset (&_, 0, sizeof (struct frame_3vI0Qc3FHQG_1g4fmHYkxSA_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 9;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[24] /*|_3vI0Qc3FHQG_1g4fmHYkxSA */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // locking 4:
  objectval_tyBM *locked_1flY7i4N8iV_5T74FnYd6Ee = NULL;        // for o_jsmodule
  objectval_tyBM *locked_3bsFDNiUKNe_9NjWM3BxFSt = NULL;        // for o_jsgenmod
  objectval_tyBM *locked_4eIUh34K2C1_9Nhx6LdYEdp = NULL;        // for o_jscurcomp
  objectval_tyBM *locked_6mmsQZI3VuT_9OYUPR9OrsR = NULL;        // for o_jscurcomp
  // fetch 2 arguments:
  _.o_5V0w37YnN4F_8dZ6I79V60O = objectcast_BM (arg0);   // o_jsmodule
  _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg1);   // o_strbuf
  // fetched 2 arguments.
  // no closed values in _3vI0Qc3FHQG_1g4fmHYkxSA.
  // routine _3vI0Qc3FHQG_1g4fmHYkxSA body:

startblock__7pji8vKR2XX_3psoWkfPtL2:__attribute__ ((unused));
  {                             /* +block _7pji8vKR2XX_3psoWkfPtL2 */

    {                           // run _38PFPbvZ5xw_5Mu74JCp6p5 
/*start of jsmodule compiler*/
      DBGPRINTF_BM ("jsmodule compiler start: o_jsmodule=%s o_strbuf=%s",
                    objectdbg_BM ( /*o_jsmodule: */ _.
                                  o_5V0w37YnN4F_8dZ6I79V60O),
                    objectdbg1_BM ( /*o_strbuf: */ _.
                                   o_41F1rKwGbaA_30OJWKsqNWy));;
    }                           // end run _38PFPbvZ5xw_5Mu74JCp6p5 


    /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW =
      //assign _553O5e7mqRq_0Dfxte6gVmp  
/*makeobj:*/ makeobj_BM ();


    {                           // start cexpansion _5aEEfO7SZge_3wLzFCRCBpn - objputclass  
      /*objputclass: */
      objputclass_BM (( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW),
                      ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[69]
                        /*|jsmodule_generation_object */ )));
    }                           // end cexpansion _5aEEfO7SZge_3wLzFCRCBpn - objputclass  


    {                           // start cexpansion _1LQNZfT8P4L_3LBZMwCIKGf - objputattr  
      /*objputattr: */
      objputattr_BM (( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW),
                     ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[39] /*!sbuf */ )),
                     ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy));
    }                           // end cexpansion _1LQNZfT8P4L_3LBZMwCIKGf - objputattr  


    {                           // start cexpansion _8owvpghf95c_70WEDPAsJGV - objputattr  
      /*objputattr: */
      objputattr_BM (( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW),
                     ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[16] /*!for */ )),
                     ( /*o_jsmodule: */ _.o_5V0w37YnN4F_8dZ6I79V60O));
    }                           // end cexpansion _8owvpghf95c_70WEDPAsJGV - objputattr  



    {                           // begin lockobj _1flY7i4N8iV_5T74FnYd6Ee 
      objectval_tyBM *curlockedob_1flY7i4N8iV_5T74FnYd6Ee =
        ( /*o_jsmodule: */ _.o_5V0w37YnN4F_8dZ6I79V60O);
      if (objlock_BM (curlockedob_1flY7i4N8iV_5T74FnYd6Ee))
        {
          locked_1flY7i4N8iV_5T74FnYd6Ee =
            curlockedob_1flY7i4N8iV_5T74FnYd6Ee;


          {                     // begin lockobj _3bsFDNiUKNe_9NjWM3BxFSt 
            objectval_tyBM *curlockedob_3bsFDNiUKNe_9NjWM3BxFSt =
              ( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW);
            if (objlock_BM (curlockedob_3bsFDNiUKNe_9NjWM3BxFSt))
              {
                locked_3bsFDNiUKNe_9NjWM3BxFSt =
                  curlockedob_3bsFDNiUKNe_9NjWM3BxFSt;


                {               // run _8g9Ms38jPls_58zTM8Ayy1u 
/*dbgprintf after lock o_jsgenmod*/
                  DBGPRINTF_BM
                    ("jsmodule compiler: after lock o_jsmodule=%s (of %s); o_jsgenmod=%s (of %s)",
                     objectdbg_BM ( /*o_jsmodule: */ _.
                                   o_5V0w37YnN4F_8dZ6I79V60O),
                     objectdbg1_BM (objclass_BM ( /*o_jsmodule: */ _.
                                                 o_5V0w37YnN4F_8dZ6I79V60O)),
                     objectdbg2_BM ( /*o_jsgenmod: */ _.
                                    o_4JKd986pvM4_6yBzeeI40vW),
                     objectdbg3_BM (objclass_BM ( /*o_jsgenmod: */ _.
                                                 o_4JKd986pvM4_6yBzeeI40vW)));
                  ;
                }               // end run _8g9Ms38jPls_58zTM8Ayy1u 

                /*o_bindings: */ _.o_5HkpTupRRIK_8iCooVukjb3 =
                  //assign _01mnkHkCsDV_7oYUAfljlz0  
/*makeobj:*/ makeobj_BM ();

                {               // start cexpansion _1HYefveHUlj_3w6vbAI4HIv - objputclass  
                  /*objputclass: */
                  objputclass_BM (( /*o_bindings: */ _.
                                   o_5HkpTupRRIK_8iCooVukjb3),
                                  ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[47]
                                    /*!assoc_object */ )));
                }               // end cexpansion _1HYefveHUlj_3w6vbAI4HIv - objputclass  

                {               // start cexpansion _7Uill32vOpW_9wlNaomdHOF - objputattr  
                  /*objputattr: */
                  objputattr_BM (( /*o_bindings: */ _.
                                  o_5HkpTupRRIK_8iCooVukjb3),
                                 ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[3]
                                   /*!in */ )),
                                 ( /*o_jsgenmod: */ _.
                                  o_4JKd986pvM4_6yBzeeI40vW));
                }               // end cexpansion _7Uill32vOpW_9wlNaomdHOF - objputattr  


                {               // run _0ACW8XdRvUP_5WPy2xnm92L 
                                                                /*objputassocpayl: */ objputassocpayl_BM (
                                                                /*o_bindings: */
                                                                                                           _.o_5HkpTupRRIK_8iCooVukjb3,
                                                                                                           /*add_int: */
                                                                                                           ((5) + ( /*objnbcomps: */ objnbcomps_BM ( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW))));
                }               // end run _0ACW8XdRvUP_5WPy2xnm92L 

                {               // start cexpansion _8g10UR3mZt1_78B4Sk9h3pN - objtouchnow  
                  /*objtouchnow: */ objtouchnow_BM ( /*o_bindings: */ _.
                                                    o_5HkpTupRRIK_8iCooVukjb3);;
                }               // end cexpansion _8g10UR3mZt1_78B4Sk9h3pN - objtouchnow  

                {               // start cexpansion _7HtsE5OFzme_6zwAgEsDtTN - objputattr  
                  /*objputattr: */
                  objputattr_BM (( /*o_jsgenmod: */ _.
                                  o_4JKd986pvM4_6yBzeeI40vW),
                                 ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[1]
                                   /*!jsmodule_bindings */ )),
                                 ( /*o_bindings: */ _.
                                  o_5HkpTupRRIK_8iCooVukjb3));
                }               // end cexpansion _7HtsE5OFzme_6zwAgEsDtTN - objputattr  

                /*leni: */ _.n_833x2jYqhZh_8vDIuJhwz1k =
                  //assign _0qK1TfyxaEU_0sLvlnHs4UT  
                  /*objnbcomps: */
                  objnbcomps_BM ( /*o_jsmodule: */ _.
                                 o_5V0w37YnN4F_8dZ6I79V60O);

                /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B =
                  //assign _4opDguH6Knp_1NiX0hlpo7s  
                  0;


//// +while _839zJGrmf26_2hQq2r1ehkR 
              startblock__839zJGrmf26_2hQq2r1ehkR:     /*+!while */
                ;
                {               /* +while _839zJGrmf26_2hQq2r1ehkR */
                  if (!( /*while _839zJGrmf26_2hQq2r1ehkR cond: */ ( /*less_int: */ ( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B) < ( /*leni: */ _.n_833x2jYqhZh_8vDIuJhwz1k))))      //: testwhile _839zJGrmf26_2hQq2r1ehkR failing   
                    goto endblock__839zJGrmf26_2hQq2r1ehkR;     //failwhile   
// while _839zJGrmf26_2hQq2r1ehkR body:   
// while _839zJGrmf26_2hQq2r1ehkR comp#0:  
                  /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW =
                    //assign _0pkGibtvusS_9tl9TNLRL7F   
                    /*val_to_object: */
                    objectcast_BM (     /*objgetcomp: */
                                    objgetcomp_BM (( /*o_jsmodule: */ _.
                                                    o_5V0w37YnN4F_8dZ6I79V60O),
                                                   ( /*ii: */ _.
                                                    n_2W7Ckt2WxEM_4NVYgEWE73B)));
// while _839zJGrmf26_2hQq2r1ehkR comp#1:  
                  if            /*cond _4Y28SaFq44X_6qJmQdN4DMt */
/*when _71N9lq8UKd3_9zYq6i873Dp:*/
                    (           /*not: */
                      (!(       /*is_objectv */
                          isobject_BM ( /*o_jscurcomp: */ _.
                                       o_2TaoEvH5OQU_8nKYBgAvkmW))))
                    {           //body when _71N9lq8UKd3_9zYq6i873Dp   
//failure _6pp3g7GLuae_7OF8KezKzvx    
                      PLACEDFAILURE_BM (__LINE__,
                                        /*failreason: */
                                        ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM
                                          [45] /*|failure_non_object */ )),
                                        /*failplace: */
                                        (       /*modconst: */
                                          (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[44]       /*|_6pp3g7GLuae_7OF8KezKzvx */
                                          )),
                                        ((struct stackframe_stBM *) &_));

                    }           //endwhen _71N9lq8UKd3_9zYq6i873Dp   
/*endcond _4Y28SaFq44X_6qJmQdN4DMt*/
// while _839zJGrmf26_2hQq2r1ehkR comp#2:  

                  {             // begin lockobj _6mmsQZI3VuT_9OYUPR9OrsR  
                    objectval_tyBM *curlockedob_6mmsQZI3VuT_9OYUPR9OrsR =
                      ( /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW);
                    if (objlock_BM (curlockedob_6mmsQZI3VuT_9OYUPR9OrsR))
                      {
                        locked_6mmsQZI3VuT_9OYUPR9OrsR =
                          curlockedob_6mmsQZI3VuT_9OYUPR9OrsR;


                        {       // run _5GmYFaClzSx_4eFHnP1tYxl  
                          DBGPRINTF_BM
                            ("jsmodule compiler: o_jsmodule=%s ii=%d o_jscurcomp=%s",
                             objectdbg_BM ( /*o_jsmodule: */ _.
                                           o_5V0w37YnN4F_8dZ6I79V60O),
                             (int) /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B,
                             objectdbg1_BM ( /*o_jscurcomp: */ _.
                                            o_2TaoEvH5OQU_8nKYBgAvkmW));;
                        }       // end run _5GmYFaClzSx_4eFHnP1tYxl  

                        if      /*cond _2d1yOe9s0xF_5zIO2nTexNd */
/*when _1icbJmDuvUd_03TJdGfrgqp:*/
                          (     /*not: */
                            (!( /*objectisinstance: */
                                objectisinstance_BM (( /*o_jscurcomp: */ _.
                                                      o_2TaoEvH5OQU_8nKYBgAvkmW),
                                                     ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[55] /*!jscript_toplevel_object */ ))))))
                          {     //body when _1icbJmDuvUd_03TJdGfrgqp   
//failure _4jwFGdaECBb_6dsBLTMoG9j    
                            PLACEDFAILURE_BM (__LINE__,
                                              /*failreason: */ (((value_tyBM) makenode2_BM
                                                                 (
                                                                   /*make_node conn: */
                                                                   ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[34] /*!failure_bad_class */ )),
/*make_node 2 sons: */
                                                                   ( /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW),
                                                                   ( /*taggedint: */ taggedint_BM ( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B))))),
                                              /*failplace: */
                                              ( /*modconst: */
                                                (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[31]
                                                 /*|_4jwFGdaECBb_6dsBLTMoG9j */
                                                 )),
                                              ((struct stackframe_stBM *)
                                               &_));

                          }     //endwhen _1icbJmDuvUd_03TJdGfrgqp   
                        else
                          {     /*cond else _2d1yOe9s0xF_5zIO2nTexNd */
                            /*v_resprep: */ _.v_7nytuRkZkOz_8T9QMYQtGps =
                              //assign _5kpEtfBlQQa_9ma0UXCajFp   
                              (send2_BM (( /*o_jscurcomp: */ _.
                                          o_2TaoEvH5OQU_8nKYBgAvkmW),   /*sel: */
                                         ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM
                                           [52]
                                           /*!prepare_for_jsmodule */ )),
                                         ((struct stackframe_stBM *) &_),
                                         ( /*o_jsgenmod: */ _.
                                          o_4JKd986pvM4_6yBzeeI40vW), ( /*taggedint: */
                                                                        taggedint_BM
                                                                        ( /*ii: */ _.
                                                                         n_2W7Ckt2WxEM_4NVYgEWE73B))));

                            {   // run _751OHscCCsT_1Kzky9o1pRk  
                              DBGPRINTF_BM
                                ("jsmodule compiler: ii=%d o_jscurcomp=%s v_resprep=%s",
                                 (int) /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B,
                                 objectdbg_BM ( /*o_jscurcomp: */ _.
                                               o_2TaoEvH5OQU_8nKYBgAvkmW),
                                 debug_outstr_value_BM ( /*v_resprep: */ _.
                                                        v_7nytuRkZkOz_8T9QMYQtGps,
                                                        CURFRAME_BM, 0));;
                            }   // end run _751OHscCCsT_1Kzky9o1pRk  
                            if  /*cond _1HknjNLZ7L3_1nUgvAJK6xV */
/*when _3KLb54en912_65r4DOVLCQt:*/
                              ( /*issequence: */
                                issequence_BM ( /*v_resprep: */ _.
                                               v_7nytuRkZkOz_8T9QMYQtGps))
                              { //body when _3KLb54en912_65r4DOVLCQt   
                                /*lenres: */ _.n_7W30qK9YBqp_7HSwYPdVkKi =
                                  //assign _2iBg4Qc42kA_0OZTv02D247    
                                  /*sequencesize: */
                                  sequencesize_BM ( /*v_resprep: */ _.
                                                   v_7nytuRkZkOz_8T9QMYQtGps);
                                /*jj: */ _.n_81BTKsrnoY8_2DoVevLPfsN =
                                  //assign _3Z2yIPkoeSH_2OzLSKO3phv    
                                  0;

//// +while _9MmVsIQi0Gu_8lv339Vx7z8   
                              startblock__9MmVsIQi0Gu_8lv339Vx7z8:     /*+!while */
                                ;
                                {       /* +while _9MmVsIQi0Gu_8lv339Vx7z8 */
                                  if (!( /*while _9MmVsIQi0Gu_8lv339Vx7z8 cond: */ ( /*less_int: */ ( /*jj: */ _.n_81BTKsrnoY8_2DoVevLPfsN) < ( /*lenres: */ _.n_7W30qK9YBqp_7HSwYPdVkKi))))    //: testwhile _9MmVsIQi0Gu_8lv339Vx7z8 failing     
                                    goto endblock__9MmVsIQi0Gu_8lv339Vx7z8;     //failwhile     
// while _9MmVsIQi0Gu_8lv339Vx7z8 body:     
// while _9MmVsIQi0Gu_8lv339Vx7z8 comp#0:    
                                  /*o_comp: */ _.o_6Z4UU939WbU_8BK9xcKsXNb =
                                    //assign _2wctxoT0H2b_6wS53ggKTfT     
                                    /*sequencenthcomp: */
                                    sequencenthcomp_BM ((const seqobval_tyBM *) (       /*v_resprep: */
                                                                                  _.v_7nytuRkZkOz_8T9QMYQtGps),
                                                        ( /*jj: */ _.
                                                         n_81BTKsrnoY8_2DoVevLPfsN));
// while _9MmVsIQi0Gu_8lv339Vx7z8 comp#1:    
                                  if    /*cond _6DijivRwkfZ_5fWccBG7vUP */
/*when _5QjLSnWJiiN_5zZRuID1CD7:*/
                                    ( /*o_comp: */ _.
                                     o_6Z4UU939WbU_8BK9xcKsXNb)
                                    {   //body when _5QjLSnWJiiN_5zZRuID1CD7     
                                      { // start cexpansion _9gV5BlKkZpK_5gAUcbpl1z3 - objappendcomp      
                                        /*objappendcomp: */
                                        objappendcomp_BM ((     /*o_jsgenmod: */
                                                            _.o_4JKd986pvM4_6yBzeeI40vW),
                                                          ( /*o_comp: */ _.
                                                           o_6Z4UU939WbU_8BK9xcKsXNb));
                                      } // end cexpansion _9gV5BlKkZpK_5gAUcbpl1z3 - objappendcomp      

                                    }   //endwhen _5QjLSnWJiiN_5zZRuID1CD7     
/*endcond _6DijivRwkfZ_5fWccBG7vUP*/
// while _9MmVsIQi0Gu_8lv339Vx7z8 comp#2:    
                                  /*jj: */ _.n_81BTKsrnoY8_2DoVevLPfsN =
                                    //assign _75QP6E8qyJj_95dxAYRTNy9     
                                    /*add_int: */
                                    (( /*jj: */ _.n_81BTKsrnoY8_2DoVevLPfsN) +
                                     (1));

                                  goto startblock__9MmVsIQi0Gu_8lv339Vx7z8;     // repeatwhile    
                                endblock__9MmVsIQi0Gu_8lv339Vx7z8:     /*endingwhile */
                                  ;
                                }
  /*-endwhile _9MmVsIQi0Gu_8lv339Vx7z8 */


                              } //endwhen _3KLb54en912_65r4DOVLCQt   
                            else if
/*when _2lfY1iJq9lF_4jhGHjj0J9i:*/
                              ( /*is_objectv */
                                isobject_BM ( /*v_resprep: */ _.
                                             v_7nytuRkZkOz_8T9QMYQtGps))
                              { //body when _2lfY1iJq9lF_4jhGHjj0J9i   
                                {       // start cexpansion _8uqjR202JN1_4HW0y79tOFG - objappendcomp    
                                  /*objappendcomp: */
                                  objappendcomp_BM (( /*o_jsgenmod: */ _.
                                                     o_4JKd986pvM4_6yBzeeI40vW), (      /*val_to_object: */
                                                                                   objectcast_BM
                                                                                   ( /*v_resprep: */ _.v_7nytuRkZkOz_8T9QMYQtGps)));
                                }       // end cexpansion _8uqjR202JN1_4HW0y79tOFG - objappendcomp     

                              } //endwhen _2lfY1iJq9lF_4jhGHjj0J9i   
                            else
                              { /*cond else _1HknjNLZ7L3_1nUgvAJK6xV */
//failure _0Lk9WQfjqpU_0XROvsMVANm   
                                PLACEDFAILURE_BM (__LINE__,
                                                  /*failreason: */
                                                  (((value_tyBM) makenode4_BM ( /*make_node conn: */
                                                                                ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[45] /*!failure_non_object */ )),
                                                                                /*make_node 4 sons: */
                                                                                ( /*v_resprep: */ _.
                                                                                 v_7nytuRkZkOz_8T9QMYQtGps),
                                                                                ( /*o_jscurcomp: */ _.
                                                                                 o_2TaoEvH5OQU_8nKYBgAvkmW), (  /*taggedint: */
                                                                                                               taggedint_BM (   /*ii: */
                                                                                                                              _.n_2W7Ckt2WxEM_4NVYgEWE73B)),
                                                                                ( /*o_jsgenmod: */ _.
                                                                                 o_4JKd986pvM4_6yBzeeI40vW)))),
                                                  /*failplace: */
                                                  (     /*modconst: */
                                                    (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[7]
                                                     /*|_0Lk9WQfjqpU_0XROvsMVANm */
                                                     )),
                                                  ((struct stackframe_stBM *)
                                                   &_));
                              } /*cond else _1HknjNLZ7L3_1nUgvAJK6xV */
/*endcond _1HknjNLZ7L3_1nUgvAJK6xV*/
                          }     /*cond else _2d1yOe9s0xF_5zIO2nTexNd */
/*endcond _2d1yOe9s0xF_5zIO2nTexNd*/

                        objunlock_BM (locked_6mmsQZI3VuT_9OYUPR9OrsR),
                          locked_6mmsQZI3VuT_9OYUPR9OrsR = NULL;
                      }
                  }             // end objlock _6mmsQZI3VuT_9OYUPR9OrsR  
// while _839zJGrmf26_2hQq2r1ehkR comp#3:  
                  /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B =
                    //assign _19wgFNpJoH0_35pJHJ4sMLm   
                    /*add_int: */
                    (( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B) + (1));

                  goto startblock__839zJGrmf26_2hQq2r1ehkR;     // repeatwhile  
                endblock__839zJGrmf26_2hQq2r1ehkR:     /*endingwhile */
                  ;
                }
  /*-endwhile _839zJGrmf26_2hQq2r1ehkR */


                /*v_resemit: */ _.v_0qTBOEAT5pa_2fz1SKfHrMV =
                  //assign _70ikqGyudad_7VauPdWkySh  
                  (send1_BM (( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW),
                             /*sel: */
                             ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[37]
                               /*!emit_prologue_jsmodule */ )),
                             ((struct stackframe_stBM *) &_),
                             ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy)));

                if              /*cond _8HiULT2zhTE_7CfIm97BpV8 */
/*when _1c7c99xtpkW_893Go0pwc1d:*/
                  (             /*is_null: */
                    (( /*v_resemit: */ _.v_0qTBOEAT5pa_2fz1SKfHrMV) == NULL))
                  {             //body when _1c7c99xtpkW_893Go0pwc1d  
//failure _401XcQg0VWc_1SG4xaaQ3mU   
                    PLACEDFAILURE_BM (__LINE__,
                                      /*failreason: */ (((value_tyBM) makenode1_BM
                                                         (
                                                           /*make_node conn: */
                                                           ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[37] /*!emit_prologue_jsmodule */ )),
/*make_node 1 sons: */
                                                           ( /*o_jsgenmod: */
                                                            _.
                                                            o_4JKd986pvM4_6yBzeeI40vW)))),
                                      /*failplace: */
                                      ( /*modconst: */
                                        (constob_3BFt4NfJmZC_7iYi2dwM38B_BM
                                         [28]
                                         /*|_401XcQg0VWc_1SG4xaaQ3mU */ )),
                                      ((struct stackframe_stBM *) &_));

                  }             //endwhen _1c7c99xtpkW_893Go0pwc1d  
/*endcond _8HiULT2zhTE_7CfIm97BpV8*/

                /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B =
                  //assign _50kGK7AP8lP_9EQplRiiZb7  
                  0;

                /*leni: */ _.n_833x2jYqhZh_8vDIuJhwz1k =
                  //assign _3BorPL79IE6_68JsQ2rTBM1  
                  /*objnbcomps: */
                  objnbcomps_BM ( /*o_jsgenmod: */ _.
                                 o_4JKd986pvM4_6yBzeeI40vW);


//// +while _2g9fVMX8xE9_8YSV476XAcf 
              startblock__2g9fVMX8xE9_8YSV476XAcf:     /*+!while */
                ;
                {               /* +while _2g9fVMX8xE9_8YSV476XAcf */
                  if (!( /*while _2g9fVMX8xE9_8YSV476XAcf cond: */ ( /*less_int: */ ( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B) < ( /*leni: */ _.n_833x2jYqhZh_8vDIuJhwz1k))))      //: testwhile _2g9fVMX8xE9_8YSV476XAcf failing   
                    goto endblock__2g9fVMX8xE9_8YSV476XAcf;     //failwhile   
// while _2g9fVMX8xE9_8YSV476XAcf body:   
// while _2g9fVMX8xE9_8YSV476XAcf comp#0:  
                  /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW =
                    //assign _9pZtoHpgUnw_0ioNZOl7gSy   
                    /*val_to_object: */
                    objectcast_BM (     /*objgetcomp: */
                                    objgetcomp_BM (( /*o_jsgenmod: */ _.
                                                    o_4JKd986pvM4_6yBzeeI40vW),
                                                   ( /*ii: */ _.
                                                    n_2W7Ckt2WxEM_4NVYgEWE73B)));
// while _2g9fVMX8xE9_8YSV476XAcf comp#1:  

                  {             // begin lockobj _4eIUh34K2C1_9Nhx6LdYEdp  
                    objectval_tyBM *curlockedob_4eIUh34K2C1_9Nhx6LdYEdp =
                      ( /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW);
                    if (objlock_BM (curlockedob_4eIUh34K2C1_9Nhx6LdYEdp))
                      {
                        locked_4eIUh34K2C1_9Nhx6LdYEdp =
                          curlockedob_4eIUh34K2C1_9Nhx6LdYEdp;


                        {       // run _2we9tWsEm78_8u1lMyPXfoS  
/*debug o_jscurcomp*/
                          DBGPRINTF_BM ("jscompile ii=%d o_jscurcomp=%s",
                                        (int) ( /*ii: */ _.
                                               n_2W7Ckt2WxEM_4NVYgEWE73B),
                                        objectdbg_BM ( /*o_jscurcomp: */ _.
                                                      o_2TaoEvH5OQU_8nKYBgAvkmW));;
                        }       // end run _2we9tWsEm78_8u1lMyPXfoS  

                        {       // start cexpansion _7PtLQyHzEtT_9uNchCVMZNN - objstrbuffernewlinepayl   
                          /*objstrbuffernewlinepayl: */
                          objstrbuffernewlinepayl_BM ( /*o_strbuf: */ _.
                                                      o_41F1rKwGbaA_30OJWKsqNWy);
                        }       // end cexpansion _7PtLQyHzEtT_9uNchCVMZNN - objstrbuffernewlinepayl   

                        {       // start cexpansion _58EVKWx2he4_3MQtKB8HQWY - objstrbuffernewlinepayl   
                          /*objstrbuffernewlinepayl: */
                          objstrbuffernewlinepayl_BM ( /*o_strbuf: */ _.
                                                      o_41F1rKwGbaA_30OJWKsqNWy);
                        }       // end cexpansion _58EVKWx2he4_3MQtKB8HQWY - objstrbuffernewlinepayl   

                        {       // start cexpansion _30VCwMspa4c_5QfIOmCi9CM - objstrbufferappendcstrpayl   
                          /*objstrbufferappendcstrpayl: */
                          objstrbufferappendcstrpayl_BM (( /*o_strbuf: */ _.
                                                          o_41F1rKwGbaA_30OJWKsqNWy),
                                                         ("//jscomp "));
                        }       // end cexpansion _30VCwMspa4c_5QfIOmCi9CM - objstrbufferappendcstrpayl   

                        {       // start cexpansion _2f0WZrkdCj1_5fGG17DXa2I - objstrbufferprintint   
                          /*objstrbufferprintint: */
                          if (objhasstrbufferpayl_BM
                              ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy))
                            {
                              char buf_2f0WZrkdCj1_5fGG17DXa2I[32];
                              memset (buf_2f0WZrkdCj1_5fGG17DXa2I, 0,
                                      sizeof (buf_2f0WZrkdCj1_5fGG17DXa2I));
                              snprintf (buf_2f0WZrkdCj1_5fGG17DXa2I,
                                        sizeof (buf_2f0WZrkdCj1_5fGG17DXa2I),
                                        "%lld", (long long) /*ii: */ _.
                                        n_2W7Ckt2WxEM_4NVYgEWE73B);
                              objstrbufferappendcstrpayl_BM ((  /*o_strbuf: */
                                                               _.o_41F1rKwGbaA_30OJWKsqNWy),
                                                             buf_2f0WZrkdCj1_5fGG17DXa2I);
                            }   //end objstrbufferprintint _2f0WZrkdCj1_5fGG17DXa2I
                          ;
                        }       // end cexpansion _2f0WZrkdCj1_5fGG17DXa2I - objstrbufferprintint   

                        {       // start cexpansion _5HtkxaZe0Hj_8JFrh9TFIqS - objstrbufferappendcstrpayl   
                          /*objstrbufferappendcstrpayl: */
                          objstrbufferappendcstrpayl_BM (( /*o_strbuf: */ _.
                                                          o_41F1rKwGbaA_30OJWKsqNWy),
                                                         (" "));
                        }       // end cexpansion _5HtkxaZe0Hj_8JFrh9TFIqS - objstrbufferappendcstrpayl   

                        {       // start cexpansion _0AZNOAPJanx_3ob1vyOlO8t - objstrbufferprintobjid   
/*objstrbufferprintobjid _0AZNOAPJanx_3ob1vyOlO8t:*/
                          objectval_tyBM *obsbuf__0AZNOAPJanx_3ob1vyOlO8t =
                            ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy);
                          objectval_tyBM *ob__0AZNOAPJanx_3ob1vyOlO8t =
                            ( /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW);
                          if (objhasstrbufferpayl_BM
                              (obsbuf__0AZNOAPJanx_3ob1vyOlO8t)
                              && isobject_BM (ob__0AZNOAPJanx_3ob1vyOlO8t))
                            {
                              char idbuf__0AZNOAPJanx_3ob1vyOlO8t[32];
                              memset (idbuf__0AZNOAPJanx_3ob1vyOlO8t, 0,
                                      sizeof
                                      (idbuf__0AZNOAPJanx_3ob1vyOlO8t));
                              idtocbuf32_BM (objid_BM
                                             (ob__0AZNOAPJanx_3ob1vyOlO8t),
                                             idbuf__0AZNOAPJanx_3ob1vyOlO8t);
                              objstrbufferappendcstrpayl_BM
                                (obsbuf__0AZNOAPJanx_3ob1vyOlO8t,
                                 idbuf__0AZNOAPJanx_3ob1vyOlO8t);
                            };
// end objstrbufferprintobjid _0AZNOAPJanx_3ob1vyOlO8t
                          ;
                        }       // end cexpansion _0AZNOAPJanx_3ob1vyOlO8t - objstrbufferprintobjid   

                        {       // start cexpansion _5kW1s42uEGN_4vbxExJpqpN - objstrbuffernewlinepayl   
                          /*objstrbuffernewlinepayl: */
                          objstrbuffernewlinepayl_BM ( /*o_strbuf: */ _.
                                                      o_41F1rKwGbaA_30OJWKsqNWy);
                        }       // end cexpansion _5kW1s42uEGN_4vbxExJpqpN - objstrbuffernewlinepayl   

                        /*v_resemit: */ _.v_0qTBOEAT5pa_2fz1SKfHrMV =
                          //assign _4c7mLUaGU0h_63ljLGyOBQX   
                          (send3_BM
                           (( /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW),
                            /*sel: */
                            ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[59]
                              /*!emit_jstoplevel */ )),
                            ((struct stackframe_stBM *) &_),
                            ( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW),
                            ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy),
                            (   /*taggedint: */
                              taggedint_BM ( /*ii: */ _.
                                            n_2W7Ckt2WxEM_4NVYgEWE73B))));


                        {       // run _6q9PrZRKTxh_6OG01D5gkin  
/*debug after emitjstoplevel*/
                          DBGPRINTF_BM
                            ("after emit_jstoplevel €%.7s o_jscurcomp=%s ii=%d o_jsgenmod=%s v_resemit=%s",
                             "_6q9PrZRKTxh_6OG01D5gkin",
                             objectdbg_BM ( /*o_jscurcomp: */ _.
                                           o_2TaoEvH5OQU_8nKYBgAvkmW),
                             (int) ( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B),
                             objectdbg1_BM ( /*o_jsgenmod: */ _.
                                            o_4JKd986pvM4_6yBzeeI40vW),
                             OUTSTRVALUE_BM ( /*v_resemit: */ _.
                                             v_0qTBOEAT5pa_2fz1SKfHrMV));
                          ;
                        }       // end run _6q9PrZRKTxh_6OG01D5gkin  

                        if      /*cond _90P1zCvpr9Q_1DMgI5of4Vm */
/*when _1oT4wI1xxr0_6N4Xe9ZM0UT:*/
                          (     /*is_null: */
                            (( /*v_resemit: */ _.v_0qTBOEAT5pa_2fz1SKfHrMV) ==
                             NULL))
                          {     //body when _1oT4wI1xxr0_6N4Xe9ZM0UT   
//failure _4lj3ntdp7xH_5LiKY8h0lHl    
                            PLACEDFAILURE_BM (__LINE__,
                                              /*failreason: */ (((value_tyBM) makenode3_BM
                                                                 (
                                                                   /*make_node conn: */
                                                                   ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[59] /*!emit_jstoplevel */ )),
/*make_node 3 sons: */
                                                                   ( /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW),
                                                                   ( /*taggedint: */ taggedint_BM ( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B)),
                                                                   ( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW)))),
                                              /*failplace: */
                                              ( /*modconst: */
                                                (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[32]
                                                 /*|_4lj3ntdp7xH_5LiKY8h0lHl */
                                                 )),
                                              ((struct stackframe_stBM *)
                                               &_));

                          }     //endwhen _1oT4wI1xxr0_6N4Xe9ZM0UT   
/*endcond _90P1zCvpr9Q_1DMgI5of4Vm*/

                        objunlock_BM (locked_4eIUh34K2C1_9Nhx6LdYEdp),
                          locked_4eIUh34K2C1_9Nhx6LdYEdp = NULL;
                      }
                  }             // end objlock _4eIUh34K2C1_9Nhx6LdYEdp  
// while _2g9fVMX8xE9_8YSV476XAcf comp#2:  
                  /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B =
                    //assign _9zi1Kmm4u72_6EIuoyYYCSj   
                    /*add_int: */
                    (( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B) + (1));

                  goto startblock__2g9fVMX8xE9_8YSV476XAcf;     // repeatwhile  
                endblock__2g9fVMX8xE9_8YSV476XAcf:     /*endingwhile */
                  ;
                }
  /*-endwhile _2g9fVMX8xE9_8YSV476XAcf */


                {               // start cexpansion _6ibKqCzpT1y_8BJA0e28wx4 - objstrbufferappendcstrpayl  
                  /*objstrbufferappendcstrpayl: */
                  objstrbufferappendcstrpayl_BM (( /*o_strbuf: */ _.
                                                  o_41F1rKwGbaA_30OJWKsqNWy),
                                                 ("\n\n/// epilogue jsmodule "));
                }               // end cexpansion _6ibKqCzpT1y_8BJA0e28wx4 - objstrbufferappendcstrpayl  

                {               // start cexpansion _7JB1R4MHBUk_0U5c5KdLtO6 - objstrbufferprintobjid  
/*objstrbufferprintobjid _7JB1R4MHBUk_0U5c5KdLtO6:*/
                  objectval_tyBM *obsbuf__7JB1R4MHBUk_0U5c5KdLtO6 =
                    ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy);
                  objectval_tyBM *ob__7JB1R4MHBUk_0U5c5KdLtO6 =
                    ( /*o_jsmodule: */ _.o_5V0w37YnN4F_8dZ6I79V60O);
                  if (objhasstrbufferpayl_BM (obsbuf__7JB1R4MHBUk_0U5c5KdLtO6)
                      && isobject_BM (ob__7JB1R4MHBUk_0U5c5KdLtO6))
                    {
                      char idbuf__7JB1R4MHBUk_0U5c5KdLtO6[32];
                      memset (idbuf__7JB1R4MHBUk_0U5c5KdLtO6, 0,
                              sizeof (idbuf__7JB1R4MHBUk_0U5c5KdLtO6));
                      idtocbuf32_BM (objid_BM (ob__7JB1R4MHBUk_0U5c5KdLtO6),
                                     idbuf__7JB1R4MHBUk_0U5c5KdLtO6);
                      objstrbufferappendcstrpayl_BM
                        (obsbuf__7JB1R4MHBUk_0U5c5KdLtO6,
                         idbuf__7JB1R4MHBUk_0U5c5KdLtO6);
                    };
// end objstrbufferprintobjid _7JB1R4MHBUk_0U5c5KdLtO6
                  ;
                }               // end cexpansion _7JB1R4MHBUk_0U5c5KdLtO6 - objstrbufferprintobjid  

                {               // start cexpansion _5QbraFr74iN_8oD2wesuij2 - objstrbufferappendcstrpayl  
                  /*objstrbufferappendcstrpayl: */
                  objstrbufferappendcstrpayl_BM (( /*o_strbuf: */ _.
                                                  o_41F1rKwGbaA_30OJWKsqNWy),
                                                 ("\n\n"));
                }               // end cexpansion _5QbraFr74iN_8oD2wesuij2 - objstrbufferappendcstrpayl  

                /*v_resemit: */ _.v_0qTBOEAT5pa_2fz1SKfHrMV =
                  //assign _9NCZAKVZV1F_4b1tg5oNMHD  
                  (send1_BM (( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW),
                             /*sel: */
                             ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[66]
                               /*!emit_epilogue_jsmodule */ )),
                             ((struct stackframe_stBM *) &_),
                             ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy)));

                if              /*cond _11ovjN6N9uY_3B2eKLxolqc */
/*when _10qy9ZVTEVY_2ApRzne5Svx:*/
                  (             /*is_null: */
                    (( /*v_resemit: */ _.v_0qTBOEAT5pa_2fz1SKfHrMV) == NULL))
                  {             //body when _10qy9ZVTEVY_2ApRzne5Svx  
//failure _75mkz7wH3u3_0ZQRFajA44k   
                    PLACEDFAILURE_BM (__LINE__,
                                      /*failreason: */ (((value_tyBM) makenode1_BM
                                                         (
                                                           /*make_node conn: */
                                                           ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[66] /*!emit_epilogue_jsmodule */ )),
/*make_node 1 sons: */
                                                           ( /*o_jsgenmod: */
                                                            _.
                                                            o_4JKd986pvM4_6yBzeeI40vW)))),
                                      /*failplace: */
                                      ( /*modconst: */
                                        (constob_3BFt4NfJmZC_7iYi2dwM38B_BM
                                         [49]
                                         /*|_75mkz7wH3u3_0ZQRFajA44k */ )),
                                      ((struct stackframe_stBM *) &_));

                  }             //endwhen _10qy9ZVTEVY_2ApRzne5Svx  
/*endcond _11ovjN6N9uY_3B2eKLxolqc*/

                /*return _1naTxcXF5Cp_7usMslj4poG: *//*v_r: */ _.
                  v_3qw9bnATIhq_8loBraLeXzQ =
                  // returned 
                  /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW;
                goto epilog_3vI0Qc3FHQG_1g4fmHYkxSA;

                objunlock_BM (locked_3bsFDNiUKNe_9NjWM3BxFSt),
                  locked_3bsFDNiUKNe_9NjWM3BxFSt = NULL;
              }
          }                     // end objlock _3bsFDNiUKNe_9NjWM3BxFSt 

          objunlock_BM (locked_1flY7i4N8iV_5T74FnYd6Ee),
            locked_1flY7i4N8iV_5T74FnYd6Ee = NULL;
        }
    }                           // end objlock _1flY7i4N8iV_5T74FnYd6Ee 
/* !endingblock _7pji8vKR2XX_3psoWkfPtL2 */
    goto endblock__7pji8vKR2XX_3psoWkfPtL2;
  endblock__7pji8vKR2XX_3psoWkfPtL2:;
  }
  /*-block _7pji8vKR2XX_3psoWkfPtL2 */

epilog_3vI0Qc3FHQG_1g4fmHYkxSA:__attribute__ ((unused));
  // routine _3vI0Qc3FHQG_1g4fmHYkxSA epilogue:
  // unlocking 4:
  if (locked_1flY7i4N8iV_5T74FnYd6Ee != NULL)
    objunlock_BM (locked_1flY7i4N8iV_5T74FnYd6Ee), locked_1flY7i4N8iV_5T74FnYd6Ee = NULL;       // for o_jsmodule
  if (locked_3bsFDNiUKNe_9NjWM3BxFSt != NULL)
    objunlock_BM (locked_3bsFDNiUKNe_9NjWM3BxFSt), locked_3bsFDNiUKNe_9NjWM3BxFSt = NULL;       // for o_jsgenmod
  if (locked_4eIUh34K2C1_9Nhx6LdYEdp != NULL)
    objunlock_BM (locked_4eIUh34K2C1_9Nhx6LdYEdp), locked_4eIUh34K2C1_9Nhx6LdYEdp = NULL;       // for o_jscurcomp
  if (locked_6mmsQZI3VuT_9OYUPR9OrsR != NULL)
    objunlock_BM (locked_6mmsQZI3VuT_9OYUPR9OrsR), locked_6mmsQZI3VuT_9OYUPR9OrsR = NULL;       // for o_jscurcomp
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _3vI0Qc3FHQG_1g4fmHYkxSA routine#9 _3vI0Qc3FHQG_1g4fmHYkxSA




value_tyBM crout_3yQlckX4DRh_4b9l9FBSSSL_BM     //#10+
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[25] /*|same_as_closed_minifunc */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 1 arguments:
  _.v_4Q4WBLjAPTV_5WVLmhAvCJY = arg0;   // v_arg
  // fetched 1 arguments.
  {                             // fetch 1 closed values in same_as_closed_minifunc:
    const closure_tyBM *callclos_3yQlckX4DRh_4b9l9FBSSSL =
      (stkf && stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
      ? (closurecast_BM (stkf->stkfram_callfun)) : NULL;
    unsigned nbclosed_3yQlckX4DRh_4b9l9FBSSSL =
      closurewidth_BM ((const value_tyBM) callclos_3yQlckX4DRh_4b9l9FBSSSL);
    if (nbclosed_3yQlckX4DRh_4b9l9FBSSSL > 0)
      _.v_5EEITf6IFH7_4DbKG99zcPW = callclos_3yQlckX4DRh_4b9l9FBSSSL->nodt_sons[0];     // v1
  }                             // fetched 1 closed values in _3yQlckX4DRh_4b9l9FBSSSL.
  // routine _3yQlckX4DRh_4b9l9FBSSSL body:

startblock__8seRhfNtGTR_4rOgARd0hVM:__attribute__ ((unused));
  {                             /* +block _8seRhfNtGTR_4rOgARd0hVM */
    if                          /*cond _8aGb7reuzLX_3sgkigRSOpu */
/*when _5Ad0ZdurQuC_1A6Kn7qopbm:*/
      ((                        /*same_val: */
         ( /*v1: */ _.v_5EEITf6IFH7_4DbKG99zcPW) ==
         ( /*v_arg: */ _.v_4Q4WBLjAPTV_5WVLmhAvCJY)))
      {                         //body when _5Ad0ZdurQuC_1A6Kn7qopbm  
        /*return _1qFf9AUO2W9_8azcQljqB3I: *//*v_r: */ _.
          v_3qw9bnATIhq_8loBraLeXzQ =
          // returned  
          /*v_arg: */ _.v_4Q4WBLjAPTV_5WVLmhAvCJY;
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
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _3yQlckX4DRh_4b9l9FBSSSL routine#10 same_as_closed_minifunc




value_tyBM crout_3HAeZZQ0q7b_7qyDsekaz7Y_BM     //#11
  (struct stackframe_stBM * stkf,       //
//!clear°list_object minifunc
   // 1 arguments
   const value_tyBM arg0,       // o1
   const value_tyBM arg1_ __attribute__ ((unused)),
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _3HAeZZQ0q7b_7qyDsekaz7Y
  struct frame_3HAeZZQ0q7b_7qyDsekaz7Y_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 2 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    objectval_tyBM *o_97rnxb0KFqq_44veN75DG2E;  // o1
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_3HAeZZQ0q7b_7qyDsekaz7Y_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 2;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[27] /*|_3HAeZZQ0q7b_7qyDsekaz7Y */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 1 arguments:
  _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0);   // o1
  // fetched 1 arguments.
  // no closed values in _3HAeZZQ0q7b_7qyDsekaz7Y.
  // routine _3HAeZZQ0q7b_7qyDsekaz7Y body:

startblock__4wSCE1PqaMS_2XYzFgB0waZ:__attribute__ ((unused));
  {                             /* +block _4wSCE1PqaMS_2XYzFgB0waZ */
    if                          /*cond _3eTPhEBroKh_3F8wQMduy1J */
/*when _0IRlnxNrCtM_6W21xnJjzmn:*/
      (                         /*objputlistpayl: */
        objputlistpayl_BM ( /*o1: */ _.o_97rnxb0KFqq_44veN75DG2E))
      {                         //body when _0IRlnxNrCtM_6W21xnJjzmn  
        /*return _516tXf2eeNb_8VGPLYEode5: *//*v_r: */ _.
          v_3qw9bnATIhq_8loBraLeXzQ =
          // returned  
          /*o1: */ _.o_97rnxb0KFqq_44veN75DG2E;
        goto epilog_3HAeZZQ0q7b_7qyDsekaz7Y;

      }                         //endwhen _0IRlnxNrCtM_6W21xnJjzmn  
/*endcond _3eTPhEBroKh_3F8wQMduy1J*/

/* !endingblock _4wSCE1PqaMS_2XYzFgB0waZ */
    goto endblock__4wSCE1PqaMS_2XYzFgB0waZ;
  endblock__4wSCE1PqaMS_2XYzFgB0waZ:;
  }
  /*-block _4wSCE1PqaMS_2XYzFgB0waZ */

epilog_3HAeZZQ0q7b_7qyDsekaz7Y:__attribute__ ((unused));
  // routine _3HAeZZQ0q7b_7qyDsekaz7Y epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _3HAeZZQ0q7b_7qyDsekaz7Y routine#11 _3HAeZZQ0q7b_7qyDsekaz7Y




value_tyBM crout_44Xro7p814I_406P69WFbq4_BM     //#12
  (struct stackframe_stBM * stkf,       //
//!prepare_for_jsmodule°jscript_topvardef_object <o_jscurcomp (o_jsgenmod)
   // 2 arguments
   const value_tyBM arg0,       // o_jscurcomp
   const value_tyBM arg1,       // o_jsgenmod
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _44Xro7p814I_406P69WFbq4
  struct frame_44Xro7p814I_406P69WFbq4_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 6 local values:
    objectval_tyBM *o_2TaoEvH5OQU_8nKYBgAvkmW;  // o_jscurcomp
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    objectval_tyBM *o_4JKd986pvM4_6yBzeeI40vW;  // o_jsgenmod
    objectval_tyBM *o_5HkpTupRRIK_8iCooVukjb3;  // o_bindings
    objectval_tyBM *o_7safxUAyjq9_7LcGUlnwwD1;  // o_variable
    value_tyBM v_9JoiltNOdGQ_2KSHcb1mz6s;       // v_prevbind
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_44Xro7p814I_406P69WFbq4_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 6;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[29] /*|_44Xro7p814I_406P69WFbq4 */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 2 arguments:
  _.o_2TaoEvH5OQU_8nKYBgAvkmW = objectcast_BM (arg0);   // o_jscurcomp
  _.o_4JKd986pvM4_6yBzeeI40vW = objectcast_BM (arg1);   // o_jsgenmod
  // fetched 2 arguments.
  // no closed values in _44Xro7p814I_406P69WFbq4.
  // routine _44Xro7p814I_406P69WFbq4 body:

startblock__2kanmkRxrZV_3xnDrbqgMjR:__attribute__ ((unused));
  {                             /* +block _2kanmkRxrZV_3xnDrbqgMjR */

    {                           // run _9d3xraR1Ehe_25Knbao41ye 
/*debug start prepare_for_jsmodule°jscript_topvardef_object*/
      DBGPRINTF_BM
        ("prepare_for_jsmodule°jscript_topvardef_object start o_jscurcomp=%s o_jsgenmod=%s",
         objectdbg_BM ( /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW),
         objectdbg1_BM ( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW));;
    }                           // end run _9d3xraR1Ehe_25Knbao41ye 


    /*o_variable: */ _.o_7safxUAyjq9_7LcGUlnwwD1 =
      //assign _4Nxi5Wwj408_6xaQvOAEE2n  
      /*val_to_object: */
      objectcast_BM (           /*objgetattr: */
                      objgetattr_BM (( /*o_jscurcomp: */ _.
                                      o_2TaoEvH5OQU_8nKYBgAvkmW),
                                     ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[40]
                                       /*!variable */ ))));


    /*o_bindings: */ _.o_5HkpTupRRIK_8iCooVukjb3 =
      //assign _2BeQNBwbX0Q_4tvR9U1pfIX  
      /*val_to_object: */
      objectcast_BM (           /*objgetattr: */
                      objgetattr_BM (( /*o_jsgenmod: */ _.
                                      o_4JKd986pvM4_6yBzeeI40vW),
                                     ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[1]
                                       /*!jsmodule_bindings */ ))));


    if                          /*cond _9C8ILqwa3IT_8fYmMLlUesU */
/*when _1zVy4aWJZ59_1TzU666WFqB:*/
      (                         /*is_null: */
        (( /*o_variable: */ _.o_7safxUAyjq9_7LcGUlnwwD1) == NULL))
      {                         //body when _1zVy4aWJZ59_1TzU666WFqB  
//failure _8Nb7qSIbE8N_7xJDtsS0rdb   
        PLACEDFAILURE_BM (__LINE__,
                          /*failreason: */ (((value_tyBM) makenode3_BM
                                             (  /*make_node conn: */
                                               ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[46] /*!is_null */ )),
                                               /*make_node 3 sons: */
                                               ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[40] /*!variable */ )),
                                               ( /*o_jscurcomp: */ _.
                                                o_2TaoEvH5OQU_8nKYBgAvkmW),
                                               ( /*o_jsgenmod: */ _.
                                                o_4JKd986pvM4_6yBzeeI40vW)))),
                          /*failplace: */
                          (     /*modconst: */
                            (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[63]
                             /*|_8Nb7qSIbE8N_7xJDtsS0rdb */ )),
                          ((struct stackframe_stBM *) &_));

      }                         //endwhen _1zVy4aWJZ59_1TzU666WFqB  
    else if
/*when _4yZW46frHxN_6EbkzZ0uHHJ:*/
      (                         /*not: */
        (!(                     /*objectisinstance: */
            objectisinstance_BM (( /*o_variable: */ _.
                                  o_7safxUAyjq9_7LcGUlnwwD1),
                                 ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[9]
                                   /*!jsvar_object */ ))))))
      {                         //body when _4yZW46frHxN_6EbkzZ0uHHJ  
//failure _3fycBOpG51y_7Jfx9BLe3U2   
        PLACEDFAILURE_BM (__LINE__,
                          /*failreason: */ (((value_tyBM) makenode3_BM
                                             (  /*make_node conn: */
                                               ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[34] /*!failure_bad_class */ )),
                                               /*make_node 3 sons: */
                                               ( /*o_variable: */ _.
                                                o_7safxUAyjq9_7LcGUlnwwD1),
                                               ( /*o_jscurcomp: */ _.
                                                o_2TaoEvH5OQU_8nKYBgAvkmW),
                                               ( /*o_jsgenmod: */ _.
                                                o_4JKd986pvM4_6yBzeeI40vW)))),
                          /*failplace: */
                          (     /*modconst: */
                            (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[22]
                             /*|_3fycBOpG51y_7Jfx9BLe3U2 */ )),
                          ((struct stackframe_stBM *) &_));

      }                         //endwhen _4yZW46frHxN_6EbkzZ0uHHJ  
/*endcond _9C8ILqwa3IT_8fYmMLlUesU*/


    /*v_prevbind: */ _.v_9JoiltNOdGQ_2KSHcb1mz6s =
      //assign _8epdEXJDMdJ_7AwQP3WUobl  
      /*objassocgetattrpayl: */
      objassocgetattrpayl_BM (( /*o_bindings: */ _.o_5HkpTupRRIK_8iCooVukjb3),
                              ( /*o_variable: */ _.
                               o_7safxUAyjq9_7LcGUlnwwD1));


    if                          /*cond _5yl90o1XTPz_43TqpfRTYUP */
/*when _5GiN0sCD3DA_7WRSBxYqQAD:*/
      ( /*v_prevbind: */ _.v_9JoiltNOdGQ_2KSHcb1mz6s)
      {                         //body when _5GiN0sCD3DA_7WRSBxYqQAD  
//failure _68ynNIWu3mp_1Th7hFVKtoO   
        PLACEDFAILURE_BM (__LINE__,
                          /*failreason: */ (((value_tyBM) makenode4_BM
                                             (  /*make_node conn: */
                                               ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[21] /*!duplicate */ )),
                                               /*make_node 4 sons: */
                                               ( /*o_variable: */ _.
                                                o_7safxUAyjq9_7LcGUlnwwD1),
                                               ( /*o_jscurcomp: */ _.
                                                o_2TaoEvH5OQU_8nKYBgAvkmW),
                                               ( /*o_jsgenmod: */ _.
                                                o_4JKd986pvM4_6yBzeeI40vW),
                                               ( /*o_bindings: */ _.
                                                o_5HkpTupRRIK_8iCooVukjb3)))),
                          /*failplace: */
                          (     /*modconst: */
                            (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[43]
                             /*|_68ynNIWu3mp_1Th7hFVKtoO */ )),
                          ((struct stackframe_stBM *) &_));

      }                         //endwhen _5GiN0sCD3DA_7WRSBxYqQAD  
/*endcond _5yl90o1XTPz_43TqpfRTYUP*/


    {                           // start cexpansion _3ORaU0LvWmw_3mofUWNHO9Q - objassocaddattrpayl  
      /*objassocaddattrpayl: */
      objassocaddattrpayl_BM (( /*o_bindings: */ _.
                               o_5HkpTupRRIK_8iCooVukjb3),
                              ( /*o_variable: */ _.
                               o_7safxUAyjq9_7LcGUlnwwD1), (((value_tyBM) makenode1_BM (        /*make_node conn: */
                                                                                         ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[18]
                                                                                           /*!jscript_variable */
                                                                                           )),
                                                                                         /*make_node 1 sons: */
                                                                                         ( /*o_jscurcomp: */ _.
                                                                                          o_2TaoEvH5OQU_8nKYBgAvkmW)))));
    }                           // end cexpansion _3ORaU0LvWmw_3mofUWNHO9Q - objassocaddattrpayl  



    {                           // run _2fCLTOH2aaY_8dawB4UbMuF 

/*debug end prepare_for_jsmodule°jscript_topvardef_object */
      DBGPRINTF_BM
        ("end prepare_for_jsmodule°jscript_topvardef_object  o_jscurcomp=%s, o_variable=%s, o_bindings=%s, o_jsgenmod=%s",
         objectdbg_BM ( /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW),
         objectdbg1_BM ( /*o_variable: */ _.o_7safxUAyjq9_7LcGUlnwwD1),
         objectdbg2_BM ( /*o_bindings: */ _.o_5HkpTupRRIK_8iCooVukjb3),
         objectdbg3_BM ( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW));
      ;
    }                           // end run _2fCLTOH2aaY_8dawB4UbMuF 


    /*return _0wUo5cKndJT_0xbbASzSb0k: *//*v_r: */ _.
      v_3qw9bnATIhq_8loBraLeXzQ =
      // returned 
      /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW;
    goto epilog_44Xro7p814I_406P69WFbq4;

/* !endingblock _2kanmkRxrZV_3xnDrbqgMjR */
    goto endblock__2kanmkRxrZV_3xnDrbqgMjR;
  endblock__2kanmkRxrZV_3xnDrbqgMjR:;
  }
  /*-block _2kanmkRxrZV_3xnDrbqgMjR */

epilog_44Xro7p814I_406P69WFbq4:__attribute__ ((unused));
  // routine _44Xro7p814I_406P69WFbq4 epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _44Xro7p814I_406P69WFbq4 routine#12 _44Xro7p814I_406P69WFbq4




value_tyBM crout_4iEFTEcHxeb_6lH464uFkTC_BM     //#13+
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[30] /*|equal_to_closed_minifunc */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 1 arguments:
  _.v_4Q4WBLjAPTV_5WVLmhAvCJY = arg0;   // v_arg
  // fetched 1 arguments.
  {                             // fetch 1 closed values in equal_to_closed_minifunc:
    const closure_tyBM *callclos_4iEFTEcHxeb_6lH464uFkTC =
      (stkf && stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
      ? (closurecast_BM (stkf->stkfram_callfun)) : NULL;
    unsigned nbclosed_4iEFTEcHxeb_6lH464uFkTC =
      closurewidth_BM ((const value_tyBM) callclos_4iEFTEcHxeb_6lH464uFkTC);
    if (nbclosed_4iEFTEcHxeb_6lH464uFkTC > 0)
      _.v_5EEITf6IFH7_4DbKG99zcPW = callclos_4iEFTEcHxeb_6lH464uFkTC->nodt_sons[0];     // v1
  }                             // fetched 1 closed values in _4iEFTEcHxeb_6lH464uFkTC.
  // routine _4iEFTEcHxeb_6lH464uFkTC body:

startblock__60FKeHfNUo3_9OSN4Cqm8zI:__attribute__ ((unused));
  {                             /* +block _60FKeHfNUo3_9OSN4Cqm8zI */
    if                          /*cond _7wPbopKi9ZB_1ifk5LEKSqu */
/*when _8hUpJbSLQUS_88aqogJAi2Q:*/
      ((                        /*equal_val: */
         valequal_BM (( /*v1: */ _.v_5EEITf6IFH7_4DbKG99zcPW),
                      ( /*v_arg: */ _.v_4Q4WBLjAPTV_5WVLmhAvCJY))))
      {                         //body when _8hUpJbSLQUS_88aqogJAi2Q  
        /*return _3dJ2b1hmBuw_7Pu5iDjauLr: *//*v_r: */ _.
          v_3qw9bnATIhq_8loBraLeXzQ =
          // returned  
          /*v1: */ _.v_5EEITf6IFH7_4DbKG99zcPW;
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
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _4iEFTEcHxeb_6lH464uFkTC routine#13 equal_to_closed_minifunc




value_tyBM crout_4qlegfkPzrC_17skUfJP7v8_BM     //#14
  (struct stackframe_stBM * stkf,       //
//!dump_data°dict_object minifun
   // 3 arguments
   const value_tyBM arg0,       // odict
   const value_tyBM arg1,       // odumper
   const value_tyBM arg2,       // osbuf
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _4qlegfkPzrC_17skUfJP7v8
  struct frame_4qlegfkPzrC_17skUfJP7v8_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 6 local values:
    value_tyBM v_167WczZjWtG_3FofhJxQWJi;       // v_str
    objectval_tyBM *o_3cTC8W7d75H_1vteOyEoAao;  // odumper
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    value_tyBM v_5jRQCD1qTko_61I0j04ugAA;       // v_val
    objectval_tyBM *o_6opEz55NyNu_3JKpBgxLijw;  // osbuf
    objectval_tyBM *o_7n2SLLuWOjH_4ArhFUjmckz;  // odict
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_4qlegfkPzrC_17skUfJP7v8_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 6;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[33] /*|_4qlegfkPzrC_17skUfJP7v8 */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 3 arguments:
  _.o_7n2SLLuWOjH_4ArhFUjmckz = objectcast_BM (arg0);   // odict
  _.o_3cTC8W7d75H_1vteOyEoAao = objectcast_BM (arg1);   // odumper
  _.o_6opEz55NyNu_3JKpBgxLijw = objectcast_BM (arg2);   // osbuf
  // fetched 3 arguments.
  // no closed values in _4qlegfkPzrC_17skUfJP7v8.
  // routine _4qlegfkPzrC_17skUfJP7v8 body:

startblock__3oMW0T4HlXx_8r7NLpyK1J8:__attribute__ ((unused));
  {                             /* +block _3oMW0T4HlXx_8r7NLpyK1J8 */
    {                           // start cexpansion _4QfB21rab5P_26PMGm9N4Dl - objstrbufferclearindentpayl  
      /*objstrbufferclearindentpayl: */
      objstrbufferclearindentpayl_BM (( /*osbuf: */ _.
                                       o_6opEz55NyNu_3JKpBgxLijw));
    }                           // end cexpansion _4QfB21rab5P_26PMGm9N4Dl - objstrbufferclearindentpayl  


    {                           // start cexpansion _15WmvoAu2Kx_9K4XFDxMyU4 - objstrbufferappendcstrpayl  
      /*objstrbufferappendcstrpayl: */
      objstrbufferappendcstrpayl_BM (( /*osbuf: */ _.
                                      o_6opEz55NyNu_3JKpBgxLijw),
                                     ("!~ todo (~\n"));
    }                           // end cexpansion _15WmvoAu2Kx_9K4XFDxMyU4 - objstrbufferappendcstrpayl  


    /*v_str: */ _.v_167WczZjWtG_3FofhJxQWJi =
      //assign _5mCmWSYOW7T_4G9YRC6tvRf  
      /*objdictfirstkeypayl: */
      (value_tyBM)
      objdictfirstkeypayl_BM (( /*odict: */ _.o_7n2SLLuWOjH_4ArhFUjmckz));


    {                           // start cexpansion _3pnZ6MbNCtX_2IZKwMgn9y1 - objstrbuffersetindentpayl  
      /*objstrbuffersetindentpayl: */
      objstrbuffersetindentpayl_BM (( /*osbuf: */ _.
                                     o_6opEz55NyNu_3JKpBgxLijw), (1));
    }                           // end cexpansion _3pnZ6MbNCtX_2IZKwMgn9y1 - objstrbuffersetindentpayl  



    {                           // run _40XgQGIUZQY_246JbHmppCN 
      (send3_BM (((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[61] /*|clear */ )),
                 /*sel: */ 
                 ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[14] /*|dump_value */ )),
                 ((struct stackframe_stBM *) &_),
                 ( /*osbuf: */ _.o_6opEz55NyNu_3JKpBgxLijw),
                 ( /*odumper: */ _.o_3cTC8W7d75H_1vteOyEoAao),
                 (((value_tyBM) 0x3 /*!1 */ ))));
    }                           // end run _40XgQGIUZQY_246JbHmppCN 



//// +while _9gJT0jotyox_8JQNlJn3qh6 
  startblock__9gJT0jotyox_8JQNlJn3qh6: /*+!while */ ;
    {                           /* +while _9gJT0jotyox_8JQNlJn3qh6 */
      if (!( /*while _9gJT0jotyox_8JQNlJn3qh6 cond: *//*isstring: */ isstring_BM ( /*v_str: */ _.v_167WczZjWtG_3FofhJxQWJi)))   //: testwhile _9gJT0jotyox_8JQNlJn3qh6 failing   
        goto endblock__9gJT0jotyox_8JQNlJn3qh6; //failwhile   
// while _9gJT0jotyox_8JQNlJn3qh6 body:   
// while _9gJT0jotyox_8JQNlJn3qh6 comp#0:  
      /*v_val: */ _.v_5jRQCD1qTko_61I0j04ugAA =
        //assign _6mzawBHvh0i_13Wpf0Lmgig   
        /*objdictgetpayl: */
        objdictgetpayl_BM (( /*odict: */ _.o_7n2SLLuWOjH_4ArhFUjmckz),
                           stringcast_BM ( /*v_str: */ _.
                                          v_167WczZjWtG_3FofhJxQWJi));
// while _9gJT0jotyox_8JQNlJn3qh6 comp#1:  
      {                         // start cexpansion _8QIiIH1xKGD_0ByaWRWwCAO - objstrbufferappendcstrpayl   
        /*objstrbufferappendcstrpayl: */
        objstrbufferappendcstrpayl_BM (( /*osbuf: */ _.
                                        o_6opEz55NyNu_3JKpBgxLijw),
                                       (" !&\n"));
      }                         // end cexpansion _8QIiIH1xKGD_0ByaWRWwCAO - objstrbufferappendcstrpayl   
// while _9gJT0jotyox_8JQNlJn3qh6 comp#2:  

      {                         // run _4BOu5jhqyAD_3HGfVAY5hFx  
        (send3_BM (((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[68] /*|put */ )),
                   /*sel: */
                   ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[14] /*|dump_value */
                     )), ((struct stackframe_stBM *) &_),
                   ( /*osbuf: */ _.o_6opEz55NyNu_3JKpBgxLijw),
                   ( /*odumper: */ _.o_3cTC8W7d75H_1vteOyEoAao),
                   (((value_tyBM) 0x3 /*!1 */ ))));
      }                         // end run _4BOu5jhqyAD_3HGfVAY5hFx  
// while _9gJT0jotyox_8JQNlJn3qh6 comp#3:  
      {                         // start cexpansion _8TB4Kpuoc3f_0Dhb8Tm0xrJ - objstrbufferappendcstrpayl   
        /*objstrbufferappendcstrpayl: */
        objstrbufferappendcstrpayl_BM (( /*osbuf: */ _.
                                        o_6opEz55NyNu_3JKpBgxLijw), ("\t"));
      }                         // end cexpansion _8TB4Kpuoc3f_0Dhb8Tm0xrJ - objstrbufferappendcstrpayl   
// while _9gJT0jotyox_8JQNlJn3qh6 comp#4:  

      {                         // run _634ecJogXve_7sycLMYAfdT  
        (send3_BM (( /*v_str: */ _.v_167WczZjWtG_3FofhJxQWJi),  /*sel: */
                   ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[14] /*|dump_value */
                     )),
                   ((struct stackframe_stBM *) &_),
                   ( /*osbuf: */ _.o_6opEz55NyNu_3JKpBgxLijw),
                   ( /*odumper: */ _.o_3cTC8W7d75H_1vteOyEoAao),
                   (((value_tyBM) 0x3 /*!1 */ ))));
      }                         // end run _634ecJogXve_7sycLMYAfdT  
// while _9gJT0jotyox_8JQNlJn3qh6 comp#5:  
      {                         // start cexpansion _3fFn9uY0hNS_2YU6fn9QOSh - objstrbuffernewlinepayl   
                                                                        /*objstrbuffernewlinepayl: */ objstrbuffernewlinepayl_BM (
                                                                        /*osbuf: */
                                                                                                                                   _.o_6opEz55NyNu_3JKpBgxLijw);
      }                         // end cexpansion _3fFn9uY0hNS_2YU6fn9QOSh - objstrbuffernewlinepayl   
// while _9gJT0jotyox_8JQNlJn3qh6 comp#6:  

      {                         // run _1aLOinNfz2n_0WpWbC84CAL  
        (send3_BM (( /*v_val: */ _.v_5jRQCD1qTko_61I0j04ugAA),  /*sel: */
                   ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[14] /*|dump_value */
                     )),
                   ((struct stackframe_stBM *) &_),
                   ( /*osbuf: */ _.o_6opEz55NyNu_3JKpBgxLijw),
                   ( /*odumper: */ _.o_3cTC8W7d75H_1vteOyEoAao),
                   (((value_tyBM) 0x3 /*!1 */ ))));
      }                         // end run _1aLOinNfz2n_0WpWbC84CAL  
// while _9gJT0jotyox_8JQNlJn3qh6 comp#7:  
      /*v_str: */ _.v_167WczZjWtG_3FofhJxQWJi =
        //assign _5VEaDZcNd5x_9CGhCudUvGs   
        /*objdictkeyafterpayl: */
        (value_tyBM)
        objdictkeyafterpayl_BM (( /*odict: */ _.o_7n2SLLuWOjH_4ArhFUjmckz),
                                stringcast_BM ( /*v_str: */ _.
                                               v_167WczZjWtG_3FofhJxQWJi));

      goto startblock__9gJT0jotyox_8JQNlJn3qh6; // repeatwhile  
    endblock__9gJT0jotyox_8JQNlJn3qh6: /*endingwhile */ ;
    }
  /*-endwhile _9gJT0jotyox_8JQNlJn3qh6 */



    {                           // start cexpansion _1UfGW420Q3X_3osvimj3Myj - objstrbufferclearindentpayl  
      /*objstrbufferclearindentpayl: */
      objstrbufferclearindentpayl_BM (( /*osbuf: */ _.
                                       o_6opEz55NyNu_3JKpBgxLijw));
    }                           // end cexpansion _1UfGW420Q3X_3osvimj3Myj - objstrbufferclearindentpayl  


    {                           // start cexpansion _3urNBgu4IsT_4oyZ9YgJmbx - objstrbufferappendcstrpayl  
      /*objstrbufferappendcstrpayl: */
      objstrbufferappendcstrpayl_BM (( /*osbuf: */ _.
                                      o_6opEz55NyNu_3JKpBgxLijw), ("\n~)\n"));
    }                           // end cexpansion _3urNBgu4IsT_4oyZ9YgJmbx - objstrbufferappendcstrpayl  


    /*return _9IH3fglmCon_9bHWhFstP4K: *//*v_r: */ _.
      v_3qw9bnATIhq_8loBraLeXzQ =
      // returned 
      /*odict: */ _.o_7n2SLLuWOjH_4ArhFUjmckz;
    goto epilog_4qlegfkPzrC_17skUfJP7v8;

/* !endingblock _3oMW0T4HlXx_8r7NLpyK1J8 */
    goto endblock__3oMW0T4HlXx_8r7NLpyK1J8;
  endblock__3oMW0T4HlXx_8r7NLpyK1J8:;
  }
  /*-block _3oMW0T4HlXx_8r7NLpyK1J8 */

epilog_4qlegfkPzrC_17skUfJP7v8:__attribute__ ((unused));
  // routine _4qlegfkPzrC_17skUfJP7v8 epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _4qlegfkPzrC_17skUfJP7v8 routine#14 _4qlegfkPzrC_17skUfJP7v8




value_tyBM crout_4M7lr5cU6VD_5hxmeH3baBf_BM     //#15
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[35] /*|_4M7lr5cU6VD_5hxmeH3baBf */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 2 arguments:
  _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0);   // o1
  _.v_09RxU8xDco3_2Zxwfb13oDZ = arg1;   // v2
  // fetched 2 arguments.
  // no closed values in _4M7lr5cU6VD_5hxmeH3baBf.
  // routine _4M7lr5cU6VD_5hxmeH3baBf body:

startblock__883QaWUOedh_9zmHk2A3RPm:__attribute__ ((unused));
  {                             /* +block _883QaWUOedh_9zmHk2A3RPm */
    if                          /*cond _9l1kqklfeho_8gvTSpVHJs0 */
/*when _4bt3mp8e1a2_7XsOs7auvrU:*/
      (                         /*objhaslistpayl: */
        objhaslistpayl_BM (( /*o1: */ _.o_97rnxb0KFqq_44veN75DG2E)))
      {                         //body when _4bt3mp8e1a2_7XsOs7auvrU  
        {                       // start cexpansion _8WKnIBYQNvy_0t8M4F48joR - objlistappendpayl   
          /*objlistappendpayl: */
          objlistappendpayl_BM (( /*o1: */ _.o_97rnxb0KFqq_44veN75DG2E),
                                ( /*v2: */ _.v_09RxU8xDco3_2Zxwfb13oDZ));
        }                       // end cexpansion _8WKnIBYQNvy_0t8M4F48joR - objlistappendpayl   
        /*return _86rGd2LLytX_4xsXHoCmw1Y: *//*v_r: */ _.
          v_3qw9bnATIhq_8loBraLeXzQ =
          // returned  
          /*o1: */ _.o_97rnxb0KFqq_44veN75DG2E;
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
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _4M7lr5cU6VD_5hxmeH3baBf routine#15 _4M7lr5cU6VD_5hxmeH3baBf




value_tyBM crout_5j8LpQULt1p_9oeOaqmfYYr_BM     //#16
  (struct stackframe_stBM * stkf,       //
//!dump_data°list_object minifunc
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[38] /*|_5j8LpQULt1p_9oeOaqmfYYr */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 3 arguments:
  _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0);   // o1
  _.o_93FBSk1ML0f_2WjSuKa9TNU = objectcast_BM (arg1);   // o2
  _.o_1Bl1iFQ8boR_1xM6MOfHV1N = objectcast_BM (arg2);   // o3
  // fetched 3 arguments.
  // no closed values in _5j8LpQULt1p_9oeOaqmfYYr.
  // routine _5j8LpQULt1p_9oeOaqmfYYr body:

startblock__9Hf4n8AnqR7_7ve3Bi3kWMV:__attribute__ ((unused));
  {                             /* +block _9Hf4n8AnqR7_7ve3Bi3kWMV */
    /*v_node: */ _.v_2BkOxf2KbS8_3bswrKbmgjy =
      //assign _8ggHPTQI1iG_02hVE5KybEL  
      /*objlisttonodepayl: */
      (value_tyBM)
      objlisttonodepayl_BM (( /*o1: */ _.o_97rnxb0KFqq_44veN75DG2E),
                            ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[53]
                              /*|node */ )));


    /*leni: */ _.n_833x2jYqhZh_8vDIuJhwz1k =
      //assign _0zhpGzEVWGP_7WoL4LJocuS  
      /*nodewidth: */
      (intptr_t) nodewidth_BM ( /*v_node: */ _.v_2BkOxf2KbS8_3bswrKbmgjy);


    /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B =
      //assign _0fygl91r6x5_8b3aCDptjAi  
      0;


    {                           // start cexpansion _6yLpzYpq8F0_4ogwWJhDGnH - objstrbufferappendcstrpayl  
      /*objstrbufferappendcstrpayl: */
      objstrbufferappendcstrpayl_BM (( /*o3: */ _.
                                      o_1Bl1iFQ8boR_1xM6MOfHV1N),
                                     ("!~ todo (~"));
    }                           // end cexpansion _6yLpzYpq8F0_4ogwWJhDGnH - objstrbufferappendcstrpayl  



//// +while _9xjh4MB97y4_2d8ffcaNFYt 
  startblock__9xjh4MB97y4_2d8ffcaNFYt: /*+!while */ ;
    {                           /* +while _9xjh4MB97y4_2d8ffcaNFYt */
      if (!( /*while _9xjh4MB97y4_2d8ffcaNFYt cond: */ ( /*less_int: */ ( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B) < ( /*leni: */ _.n_833x2jYqhZh_8vDIuJhwz1k))))  //: testwhile _9xjh4MB97y4_2d8ffcaNFYt failing   
        goto endblock__9xjh4MB97y4_2d8ffcaNFYt; //failwhile   
// while _9xjh4MB97y4_2d8ffcaNFYt body:   
// while _9xjh4MB97y4_2d8ffcaNFYt comp#0:  
      {                         // start cexpansion _63n9WJxlgsW_7aRQkxcfyFp - objstrbuffersetindentpayl   
        /*objstrbuffersetindentpayl: */
        objstrbuffersetindentpayl_BM (( /*o3: */ _.
                                       o_1Bl1iFQ8boR_1xM6MOfHV1N), (1));
      }                         // end cexpansion _63n9WJxlgsW_7aRQkxcfyFp - objstrbuffersetindentpayl   
// while _9xjh4MB97y4_2d8ffcaNFYt comp#1:  
      {                         // start cexpansion _4L5hoWsh9Dl_112aUlLRWBa - objstrbuffernewlinepayl   
        /*objstrbuffernewlinepayl: */ objstrbuffernewlinepayl_BM ( /*o3: */ _.
                                                                  o_1Bl1iFQ8boR_1xM6MOfHV1N);
      }                         // end cexpansion _4L5hoWsh9Dl_112aUlLRWBa - objstrbuffernewlinepayl   
// while _9xjh4MB97y4_2d8ffcaNFYt comp#2:  
      {                         // start cexpansion _4ExmfQs4chn_6b5RsLwzSmp - objstrbufferappendcstrpayl   
        /*objstrbufferappendcstrpayl: */
        objstrbufferappendcstrpayl_BM (( /*o3: */ _.
                                        o_1Bl1iFQ8boR_1xM6MOfHV1N), (" &!"));
      }                         // end cexpansion _4ExmfQs4chn_6b5RsLwzSmp - objstrbufferappendcstrpayl   
// while _9xjh4MB97y4_2d8ffcaNFYt comp#3:  

      {                         // run _6HYDs1Zywvs_1w8OTn5XOZY  
        (send3_BM ((            /*nodenthson: */
                     nodenthson_BM (( /*v_node: */ _.
                                     v_2BkOxf2KbS8_3bswrKbmgjy),
                                    ( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B))),  /*sel: */
                   ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[14] /*|dump_value */
                     )),
                   ((struct stackframe_stBM *) &_),
                   ( /*o3: */ _.o_1Bl1iFQ8boR_1xM6MOfHV1N),
                   ( /*o2: */ _.o_93FBSk1ML0f_2WjSuKa9TNU),
                   (((value_tyBM) 0x3 /*!1 */ ))));
      }                         // end run _6HYDs1Zywvs_1w8OTn5XOZY  
// while _9xjh4MB97y4_2d8ffcaNFYt comp#4:  
      /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B =
        //assign _4nPRrjCznxv_354tRTC5amu   
        /*add_int: */ (( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B) + (1));

      goto startblock__9xjh4MB97y4_2d8ffcaNFYt; // repeatwhile  
    endblock__9xjh4MB97y4_2d8ffcaNFYt: /*endingwhile */ ;
    }
  /*-endwhile _9xjh4MB97y4_2d8ffcaNFYt */



    {                           // start cexpansion _39EI0paA4hR_8y7JANajq5t - objstrbuffernewlinepayl  
      /*objstrbuffernewlinepayl: */ objstrbuffernewlinepayl_BM ( /*o3: */ _.
                                                                o_1Bl1iFQ8boR_1xM6MOfHV1N);
    }                           // end cexpansion _39EI0paA4hR_8y7JANajq5t - objstrbuffernewlinepayl  


    {                           // start cexpansion _5flu8xdOTMC_79tshj3uSa4 - objstrbuffersetindentpayl  
      /*objstrbuffersetindentpayl: */
      objstrbuffersetindentpayl_BM (( /*o3: */ _.o_1Bl1iFQ8boR_1xM6MOfHV1N),
                                    (0));
    }                           // end cexpansion _5flu8xdOTMC_79tshj3uSa4 - objstrbuffersetindentpayl  


    {                           // start cexpansion _5YxDaNaTjQ7_0v9tZ2seGmF - objstrbufferappendcstrpayl  
      /*objstrbufferappendcstrpayl: */
      objstrbufferappendcstrpayl_BM (( /*o3: */ _.
                                      o_1Bl1iFQ8boR_1xM6MOfHV1N), ("~)"));
    }                           // end cexpansion _5YxDaNaTjQ7_0v9tZ2seGmF - objstrbufferappendcstrpayl  

/* !endingblock _9Hf4n8AnqR7_7ve3Bi3kWMV */
    goto endblock__9Hf4n8AnqR7_7ve3Bi3kWMV;
  endblock__9Hf4n8AnqR7_7ve3Bi3kWMV:;
  }
  /*-block _9Hf4n8AnqR7_7ve3Bi3kWMV */

epilog_5j8LpQULt1p_9oeOaqmfYYr:__attribute__ ((unused));
  // routine _5j8LpQULt1p_9oeOaqmfYYr epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _5j8LpQULt1p_9oeOaqmfYYr routine#16 _5j8LpQULt1p_9oeOaqmfYYr




value_tyBM crout_74TaCoUa4dg_2bmUAanJYIJ_BM     //#17
  (struct stackframe_stBM * stkf,       //
//!emit_jstoplevel°jscript_topvardef_object <o_jscurcomp (o_jsgenmod o_strbuf v_i)
   // 4 arguments
   const value_tyBM arg0,       // o_jscurcomp
   const value_tyBM arg1,       // o_jsgenmod
   const value_tyBM arg2,       // o_strbuf
   const value_tyBM arg3,       // v_i
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _74TaCoUa4dg_2bmUAanJYIJ
  struct frame_74TaCoUa4dg_2bmUAanJYIJ_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 7 local values:
    value_tyBM v_0qTBOEAT5pa_2fz1SKfHrMV;       // v_resemit
    objectval_tyBM *o_2TaoEvH5OQU_8nKYBgAvkmW;  // o_jscurcomp
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    value_tyBM v_3vRFuniDv1K_4bQ7DeekM2I;       // v_i
    objectval_tyBM *o_41F1rKwGbaA_30OJWKsqNWy;  // o_strbuf
    objectval_tyBM *o_4JKd986pvM4_6yBzeeI40vW;  // o_jsgenmod
    objectval_tyBM *o_7safxUAyjq9_7LcGUlnwwD1;  // o_variable
    /// 1 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
  } _;
  memset (&_, 0, sizeof (struct frame_74TaCoUa4dg_2bmUAanJYIJ_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 7;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[48] /*|_74TaCoUa4dg_2bmUAanJYIJ */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 4 arguments:
  _.o_2TaoEvH5OQU_8nKYBgAvkmW = objectcast_BM (arg0);   // o_jscurcomp
  _.o_4JKd986pvM4_6yBzeeI40vW = objectcast_BM (arg1);   // o_jsgenmod
  _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg2);   // o_strbuf
  _.v_3vRFuniDv1K_4bQ7DeekM2I = arg3;   // v_i
  // fetched 4 arguments.
  // no closed values in _74TaCoUa4dg_2bmUAanJYIJ.
  // routine _74TaCoUa4dg_2bmUAanJYIJ body:

startblock__89UMgXRvAgw_8wA2kYCSWVS:__attribute__ ((unused));
  {                             /* +block _89UMgXRvAgw_8wA2kYCSWVS */
    /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B =
      //assign _0c1UQDoiMc9_7MORr2syzgQ  
      /*val_to_int_default: */
      getintdefault_BM (( /*v_i: */ _.v_3vRFuniDv1K_4bQ7DeekM2I), (-1));



    {                           // run _86czVcSeu24_3V8OEbAeLs1 
/*debug start emit_jstoplevel°jscript_topvardef_object*/
      DBGPRINTF_BM
        ("start emit_jstoplevel°jscript_topvardef_object €%.7s o_jscurcomp=%s o_jsgenmod=%s o_strbuf=%s ii=%d",
         "_86czVcSeu24_3V8OEbAeLs1",
         objectdbg_BM ( /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW),
         objectdbg1_BM ( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW),
         objectdbg2_BM ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy),
         (int) ( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B));;
    }                           // end run _86czVcSeu24_3V8OEbAeLs1 


    /*o_variable: */ _.o_7safxUAyjq9_7LcGUlnwwD1 =
      //assign _9RTKyfIWIZm_3k5PZARRiLo  
      /*val_to_object: */
      objectcast_BM (           /*objgetattr: */
                      objgetattr_BM (( /*o_jscurcomp: */ _.
                                      o_2TaoEvH5OQU_8nKYBgAvkmW),
                                     ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[40]
                                       /*!variable */ ))));


    if                          /*cond _3wD146RHTck_70wiyGziPvP */
/*when _0sXD3odjYPT_3812FqDKo12:*/
      (                         /*not: */
        (!(                     /*objectisinstance: */
            objectisinstance_BM (( /*o_variable: */ _.
                                  o_7safxUAyjq9_7LcGUlnwwD1),
                                 ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[9]
                                   /*!jsvar_object */ ))))))
      {                         //body when _0sXD3odjYPT_3812FqDKo12  
//failure _3BFLweNp6f9_4v8sSIEqDFa   
        PLACEDFAILURE_BM (__LINE__,
                          /*failreason: */ (((value_tyBM) makenode3_BM
                                             (  /*make_node conn: */
                                               ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[34] /*!failure_bad_class */ )),
                                               /*make_node 3 sons: */
                                               ( /*o_variable: */ _.
                                                o_7safxUAyjq9_7LcGUlnwwD1),
                                               ( /*o_jscurcomp: */ _.
                                                o_2TaoEvH5OQU_8nKYBgAvkmW),
                                               ( /*o_jsgenmod: */ _.
                                                o_4JKd986pvM4_6yBzeeI40vW)))),
                          /*failplace: */
                          (     /*modconst: */
                            (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[26]
                             /*|_3BFLweNp6f9_4v8sSIEqDFa */ )),
                          ((struct stackframe_stBM *) &_));

      }                         //endwhen _0sXD3odjYPT_3812FqDKo12  
/*endcond _3wD146RHTck_70wiyGziPvP*/


    {                           // start cexpansion _1NIzHT7WYH5_6WbLybB6OjW - objstrbufferappendcstrpayl  
      /*objstrbufferappendcstrpayl: */
      objstrbufferappendcstrpayl_BM (( /*o_strbuf: */ _.
                                      o_41F1rKwGbaA_30OJWKsqNWy), ("var "));
    }                           // end cexpansion _1NIzHT7WYH5_6WbLybB6OjW - objstrbufferappendcstrpayl  


    /*v_resemit: */ _.v_0qTBOEAT5pa_2fz1SKfHrMV =
      //assign _32yBjb2MIGM_88lWbXGY4GA  
      (send4_BM (( /*o_variable: */ _.o_7safxUAyjq9_7LcGUlnwwD1),       /*sel: */
                 ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[36]
                   /*!jsemit_expression */ )),
                 ((struct stackframe_stBM *) &_),
                 ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy),
                 ( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW),
                 (NULL), (NULL)));


    if                          /*cond _3KykrSoqKMY_1YtOqq8cWeV */
/*when _8F24xMlHnlo_0z7XVdFOMIK:*/
      (                         /*is_null: */
        (( /*v_resemit: */ _.v_0qTBOEAT5pa_2fz1SKfHrMV) == NULL))
      {                         //body when _8F24xMlHnlo_0z7XVdFOMIK  
//failure _934Sfmj7uik_3F2IvtzKrgM   
        PLACEDFAILURE_BM (__LINE__,
                          /*failreason: */ (((value_tyBM) makenode3_BM
                                             (  /*make_node conn: */
                                               ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[36] /*!jsemit_expression */ )),
                                               /*make_node 3 sons: */
                                               ( /*o_variable: */ _.
                                                o_7safxUAyjq9_7LcGUlnwwD1),
                                               ( /*o_strbuf: */ _.
                                                o_41F1rKwGbaA_30OJWKsqNWy),
                                               ( /*o_jsgenmod: */ _.
                                                o_4JKd986pvM4_6yBzeeI40vW)))),
                          /*failplace: */
                          (     /*modconst: */
                            (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[65]
                             /*|_934Sfmj7uik_3F2IvtzKrgM */ )),
                          ((struct stackframe_stBM *) &_));

      }                         //endwhen _8F24xMlHnlo_0z7XVdFOMIK  
/*endcond _3KykrSoqKMY_1YtOqq8cWeV*/



    {                           // run _4iAi5PunIPi_6wzOSbQ5RbQ 
/*debug v_resemit o_variable o_strbuf o_jsgenmod*/
      DBGPRINTF_BM
        ("emit_jstoplevel°jscript_topvardef_object €%.7s v_resemit=%s o_variable=%s o_strbuf=%s o_jsgenmod=%s",
         "_4iAi5PunIPi_6wzOSbQ5RbQ",
         OUTSTRVALUE_BM ( /*v_resemit: */ _.v_0qTBOEAT5pa_2fz1SKfHrMV),
         objectdbg_BM ( /*o_variable: */ _.o_7safxUAyjq9_7LcGUlnwwD1),
         objectdbg1_BM ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy),
         objectdbg2_BM ( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW));
      ;
    }                           // end run _4iAi5PunIPi_6wzOSbQ5RbQ 


    {                           // start cexpansion _6NZUH24hnks_79xuKP2tLP7 - objstrbufferappendcstrpayl  
      /*objstrbufferappendcstrpayl: */
      objstrbufferappendcstrpayl_BM (( /*o_strbuf: */ _.
                                      o_41F1rKwGbaA_30OJWKsqNWy), (";\n"));
    }                           // end cexpansion _6NZUH24hnks_79xuKP2tLP7 - objstrbufferappendcstrpayl  


    /*return _3eaqLjcG5kX_0l9vAzr3BgO: *//*v_r: */ _.
      v_3qw9bnATIhq_8loBraLeXzQ =
      // returned 
      /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW;
    goto epilog_74TaCoUa4dg_2bmUAanJYIJ;

/* !endingblock _89UMgXRvAgw_8wA2kYCSWVS */
    goto endblock__89UMgXRvAgw_8wA2kYCSWVS;
  endblock__89UMgXRvAgw_8wA2kYCSWVS:;
  }
  /*-block _89UMgXRvAgw_8wA2kYCSWVS */

epilog_74TaCoUa4dg_2bmUAanJYIJ:__attribute__ ((unused));
  // routine _74TaCoUa4dg_2bmUAanJYIJ epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _74TaCoUa4dg_2bmUAanJYIJ routine#17 _74TaCoUa4dg_2bmUAanJYIJ




value_tyBM crout_7TK5bvNNTIg_4pzieotiEq8_BM     //#18
  (struct stackframe_stBM * stkf,       //
//!prepare_for_jsmodule°jscript_topfunction_object <o_jscurcomp (o_jsgenmod)
   // 2 arguments
   const value_tyBM arg0,       // o_jscurcomp
   const value_tyBM arg1,       // o_jsgenmod
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _7TK5bvNNTIg_4pzieotiEq8
  struct frame_7TK5bvNNTIg_4pzieotiEq8_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 8 local values:
    objectval_tyBM *o_2LvSvKJFCCF_3QyFpcrySIi;  // o_curvar
    objectval_tyBM *o_2TaoEvH5OQU_8nKYBgAvkmW;  // o_jscurcomp
    value_tyBM v_3lXKQCJ5IpM_1W5tqNbhFtx;       // v_locals
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    objectval_tyBM *o_4JKd986pvM4_6yBzeeI40vW;  // o_jsgenmod
    objectval_tyBM *o_5D1GbyYKAgk_9ureezAahw3;  // o_prepjfun
    value_tyBM v_8pbpqrN1W4l_7mZmRSPBjYz;       // v_arguments
    value_tyBM v_9vVgSDTP8MG_7UPh9UN91Xh;       // v_body
    /// 2 local numbers:
    intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
    intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
  } _;
  memset (&_, 0, sizeof (struct frame_7TK5bvNNTIg_4pzieotiEq8_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 8;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[56] /*|_7TK5bvNNTIg_4pzieotiEq8 */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // locking 2:
  objectval_tyBM *locked_78OahSJuxQQ_3PS1bVuLz1Y = NULL;        // for o_prepjfun
  objectval_tyBM *locked_9JK68akzlk7_5gjJfMCUAhq = NULL;        // for o_curvar
  // fetch 2 arguments:
  _.o_2TaoEvH5OQU_8nKYBgAvkmW = objectcast_BM (arg0);   // o_jscurcomp
  _.o_4JKd986pvM4_6yBzeeI40vW = objectcast_BM (arg1);   // o_jsgenmod
  // fetched 2 arguments.
  // no closed values in _7TK5bvNNTIg_4pzieotiEq8.
  // routine _7TK5bvNNTIg_4pzieotiEq8 body:

startblock__0Z73bFupVPc_5IIGLp2FEwc:__attribute__ ((unused));
  {                             /* +block _0Z73bFupVPc_5IIGLp2FEwc */

    {                           // run _1ukG2M9NPuZ_2sIG8oHLDHp 
/*debug start prepare_for_jsmodule°jscript_topfunction_object o_jscurcomp o_jsgenmod*/
      DBGPRINTF_BM ("debug start €%.7s prepare_for_jsmodule°jscript_topfunction_object o_jscurcomp=%s o_jsgenmod=%s", "_1ukG2M9NPuZ_2sIG8oHLDHp", objectdbg_BM ( /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW), objectdbg1_BM ( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW));     /*here */
      ;
    }                           // end run _1ukG2M9NPuZ_2sIG8oHLDHp 


    /*v_arguments: */ _.v_8pbpqrN1W4l_7mZmRSPBjYz =
      //assign _1w3JgPmiAfF_48yvQuvGHsk  
      /*objgetattr: */
      objgetattr_BM (( /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW),
                     ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[4]    /*!arguments */
                      )));


    /*v_locals: */ _.v_3lXKQCJ5IpM_1W5tqNbhFtx =
      //assign _9R4IEwtCZAA_4FUAfgVpsiG  
      /*objgetattr: */
      objgetattr_BM (( /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW),
                     ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[19]   /*!locals */
                      )));


    /*v_body: */ _.v_9vVgSDTP8MG_7UPh9UN91Xh =
      //assign _5iCBTtIjSko_5Q0RtreqOjB  
      /*objgetattr: */
      objgetattr_BM (( /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW),
                     ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[54] /*!body */ )));


    /*o_prepjfun: */ _.o_5D1GbyYKAgk_9ureezAahw3 =
      //assign _6DuGAgyCNes_129XCoRTqWa  
/*makeobj:*/ makeobj_BM ();


    {                           // start cexpansion _2XRJevENsym_2Ea3mnMrmYR - objputclass  
      /*objputclass: */
      objputclass_BM (( /*o_prepjfun: */ _.o_5D1GbyYKAgk_9ureezAahw3),
                      ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[5]
                        /*!jsfun_preparation_object */ )));
    }                           // end cexpansion _2XRJevENsym_2Ea3mnMrmYR - objputclass  


    {                           // start cexpansion _67dU9VrW0XH_0JBGgMjnwDg - objputattr  
      /*objputattr: */
      objputattr_BM (( /*o_prepjfun: */ _.o_5D1GbyYKAgk_9ureezAahw3),
                     ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[16] /*!for */ )),
                     ( /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW));
    }                           // end cexpansion _67dU9VrW0XH_0JBGgMjnwDg - objputattr  


    {                           // start cexpansion _1SmBG69REro_23Y5EpTU8n0 - objputattr  
      /*objputattr: */
      objputattr_BM (( /*o_prepjfun: */ _.o_5D1GbyYKAgk_9ureezAahw3),
                     ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[3] /*!in */ )),
                     ( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW));
    }                           // end cexpansion _1SmBG69REro_23Y5EpTU8n0 - objputattr  



    {                           // run _2VVgYaTxYnt_65w95Yz9VEb 
/*debug prepare_for_jsmodule°jscript_topfunction_object o_jscurcomp v_arguments v_locals v_body o_prepjfun*/
      DBGPRINTF_BM
        ("prepare_for_jsmodule°jscript_topfunction_object €%.8s o_jscurcomp=%s v_arguments=%s v_locals=%s v_body=%s o_prepjfun=%s",
         "_2VVgYaTxYnt_65w95Yz9VEb",
         objectdbg_BM ( /*o_jscurcomp: */ _.o_2TaoEvH5OQU_8nKYBgAvkmW),
         OUTSTRVALUE_BM ( /*v_arguments: */ _.v_8pbpqrN1W4l_7mZmRSPBjYz),
         OUTSTRVALUE_BM ( /*v_locals: */ _.v_3lXKQCJ5IpM_1W5tqNbhFtx),
         OUTSTRVALUE_BM ( /*v_body: */ _.v_9vVgSDTP8MG_7UPh9UN91Xh),
         objectdbg1_BM ( /*o_prepjfun: */ _.o_5D1GbyYKAgk_9ureezAahw3));
      ;
    }                           // end run _2VVgYaTxYnt_65w95Yz9VEb 



    {                           // begin lockobj _78OahSJuxQQ_3PS1bVuLz1Y 
      objectval_tyBM *curlockedob_78OahSJuxQQ_3PS1bVuLz1Y =
        ( /*o_prepjfun: */ _.o_5D1GbyYKAgk_9ureezAahw3);
      if (objlock_BM (curlockedob_78OahSJuxQQ_3PS1bVuLz1Y))
        {
          locked_78OahSJuxQQ_3PS1bVuLz1Y =
            curlockedob_78OahSJuxQQ_3PS1bVuLz1Y;

          if                    /*cond _97A35sEceVZ_0wS1TFpkI0A */
/*when _66yVbSMIfvB_76CaTvxn748:*/
            (                   /*issequence: */
              issequence_BM ( /*v_arguments: */ _.v_8pbpqrN1W4l_7mZmRSPBjYz))
            {                   //body when _66yVbSMIfvB_76CaTvxn748  
              /*leni: */ _.n_833x2jYqhZh_8vDIuJhwz1k =
                //assign _7GrOZkoA89A_7j5WKalChMI   
                /*sequencesize: */
                sequencesize_BM ( /*v_arguments: */ _.
                                 v_8pbpqrN1W4l_7mZmRSPBjYz);
              /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B =
                //assign _5vZvb0lv60X_1cHSYJ7a2yW   
                0;

//// +while _1j3PQ4ubZBl_3XUtmloyhnl  
            startblock__1j3PQ4ubZBl_3XUtmloyhnl:       /*+!while */ ;
              {                 /* +while _1j3PQ4ubZBl_3XUtmloyhnl */
                if (!( /*while _1j3PQ4ubZBl_3XUtmloyhnl cond: */ ( /*less_int: */ ( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B) < ( /*leni: */ _.n_833x2jYqhZh_8vDIuJhwz1k))))        //: testwhile _1j3PQ4ubZBl_3XUtmloyhnl failing    
                  goto endblock__1j3PQ4ubZBl_3XUtmloyhnl;       //failwhile    
// while _1j3PQ4ubZBl_3XUtmloyhnl body:    
// while _1j3PQ4ubZBl_3XUtmloyhnl comp#0:   
                /*o_curvar: */ _.o_2LvSvKJFCCF_3QyFpcrySIi =
                  //assign _6Uw3qANxFib_5ab0YttFaOP    
                  /*sequencenthcomp: */
                  sequencenthcomp_BM ((const seqobval_tyBM *) ( /*v_arguments: */ _.v_8pbpqrN1W4l_7mZmRSPBjYz), ( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B));
// while _1j3PQ4ubZBl_3XUtmloyhnl comp#1:   
                if              /*cond _0ZJpQKuWAS2_6aTHa5YYBxM */
/*when _9MM8bc2ZyKw_5pC7YybQrgr:*/
                  (             /*is_null: */
                    (( /*o_curvar: */ _.o_2LvSvKJFCCF_3QyFpcrySIi) == NULL))
                  {             //body when _9MM8bc2ZyKw_5pC7YybQrgr    
//failure _7lrEc2aXmp8_6MlRQh2foQF     
                    PLACEDFAILURE_BM (__LINE__,
                                      /*failreason: */ (((value_tyBM) makenode3_BM
                                                         (
                                                           /*make_node conn: */
                                                           ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[40] /*!variable */ )),
/*make_node 3 sons: */
                                                           ( /*v_arguments: */
                                                            _.
                                                            v_8pbpqrN1W4l_7mZmRSPBjYz),
                                                           ( /*taggedint: */
                                                            taggedint_BM ( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B)),
                                                           ( /*o_jscurcomp: */
                                                            _.
                                                            o_2TaoEvH5OQU_8nKYBgAvkmW)))),
                                      /*failplace: */
                                      ( /*modconst: */
                                        (constob_3BFt4NfJmZC_7iYi2dwM38B_BM
                                         [51]
                                         /*|_7lrEc2aXmp8_6MlRQh2foQF */ )),
                                      ((struct stackframe_stBM *) &_));

                  }             //endwhen _9MM8bc2ZyKw_5pC7YybQrgr    
                else
                  {             /*cond else _0ZJpQKuWAS2_6aTHa5YYBxM */

                    {           // begin lockobj _9JK68akzlk7_5gjJfMCUAhq   
                      objectval_tyBM *curlockedob_9JK68akzlk7_5gjJfMCUAhq =
                        ( /*o_curvar: */ _.o_2LvSvKJFCCF_3QyFpcrySIi);
                      if (objlock_BM (curlockedob_9JK68akzlk7_5gjJfMCUAhq))
                        {
                          locked_9JK68akzlk7_5gjJfMCUAhq =
                            curlockedob_9JK68akzlk7_5gjJfMCUAhq;


                          {     // run _54mOgbkFXma_6bR6VE5ug9B   
/*debug argument ii o_curvar*/
                            DBGPRINTF_BM
                              ("debug €%.8s prepare_for_jsmodule°jscript_topfunction_object argument ii=%ld o_curvar=%s",
                               "_54mOgbkFXma_6bR6VE5ug9B",
                               (long) ( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B),
                               objectdbg_BM ( /*o_curvar: */ _.
                                             o_2LvSvKJFCCF_3QyFpcrySIi));
                            ;
                          }     // end run _54mOgbkFXma_6bR6VE5ug9B   

                          objunlock_BM (locked_9JK68akzlk7_5gjJfMCUAhq),
                            locked_9JK68akzlk7_5gjJfMCUAhq = NULL;
                        }
                    }           // end objlock _9JK68akzlk7_5gjJfMCUAhq   
                  }             /*cond else _0ZJpQKuWAS2_6aTHa5YYBxM */
/*endcond _0ZJpQKuWAS2_6aTHa5YYBxM*/
// while _1j3PQ4ubZBl_3XUtmloyhnl comp#2:   
                /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B =
                  //assign _1tNw9mabnUz_4m1FupFJnLA    
                  /*add_int: */
                  (( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B) + (1));

                goto startblock__1j3PQ4ubZBl_3XUtmloyhnl;       // repeatwhile   
              endblock__1j3PQ4ubZBl_3XUtmloyhnl:       /*endingwhile */
                ;
              }
  /*-endwhile _1j3PQ4ubZBl_3XUtmloyhnl */


            }                   //endwhen _66yVbSMIfvB_76CaTvxn748  
          else if
/*when _3eGpKatdyfH_2ZTISlI2D6R:*/
            ( /*v_arguments: */ _.v_8pbpqrN1W4l_7mZmRSPBjYz)
            {                   //body when _3eGpKatdyfH_2ZTISlI2D6R  
//failure _9onbEiQdZKJ_2CGamshEWbT   
              PLACEDFAILURE_BM (__LINE__,
                                /*failreason: */ (((value_tyBM) makenode3_BM
                                                   (    /*make_node conn: */
                                                     ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[4] /*!arguments */ )),
                                                     /*make_node 3 sons: */
                                                     ( /*o_jscurcomp: */ _.
                                                      o_2TaoEvH5OQU_8nKYBgAvkmW),
                                                     ( /*o_jsgenmod: */ _.
                                                      o_4JKd986pvM4_6yBzeeI40vW),
                                                     ( /*v_arguments: */ _.
                                                      v_8pbpqrN1W4l_7mZmRSPBjYz)))),
                                /*failplace: */
                                (       /*modconst: */
                                  (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[67]
                                   /*|_9onbEiQdZKJ_2CGamshEWbT */ )),
                                ((struct stackframe_stBM *) &_));

            }                   //endwhen _3eGpKatdyfH_2ZTISlI2D6R  
/*endcond _97A35sEceVZ_0wS1TFpkI0A*/

          objunlock_BM (locked_78OahSJuxQQ_3PS1bVuLz1Y),
            locked_78OahSJuxQQ_3PS1bVuLz1Y = NULL;
        }
    }                           // end objlock _78OahSJuxQQ_3PS1bVuLz1Y 
/* !endingblock _0Z73bFupVPc_5IIGLp2FEwc */
    goto endblock__0Z73bFupVPc_5IIGLp2FEwc;
  endblock__0Z73bFupVPc_5IIGLp2FEwc:;
  }
  /*-block _0Z73bFupVPc_5IIGLp2FEwc */

epilog_7TK5bvNNTIg_4pzieotiEq8:__attribute__ ((unused));
  // routine _7TK5bvNNTIg_4pzieotiEq8 epilogue:
  // unlocking 2:
  if (locked_78OahSJuxQQ_3PS1bVuLz1Y != NULL)
    objunlock_BM (locked_78OahSJuxQQ_3PS1bVuLz1Y), locked_78OahSJuxQQ_3PS1bVuLz1Y = NULL;       // for o_prepjfun
  if (locked_9JK68akzlk7_5gjJfMCUAhq != NULL)
    objunlock_BM (locked_9JK68akzlk7_5gjJfMCUAhq), locked_9JK68akzlk7_5gjJfMCUAhq = NULL;       // for o_curvar
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _7TK5bvNNTIg_4pzieotiEq8 routine#18 _7TK5bvNNTIg_4pzieotiEq8




value_tyBM crout_82ho9wUUDji_4peMLha4PXl_BM     //#19+
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[57] /*|findobj_scan_minifunc */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 1 arguments:
  _.o_4gykCX1QdLb_9Aooqa2FWTq = objectcast_BM (arg0);   // o_scan
  // fetched 1 arguments.
  {                             // fetch 1 closed values in findobj_scan_minifunc:
    const closure_tyBM *callclos_82ho9wUUDji_4peMLha4PXl =
      (stkf && stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
      ? (closurecast_BM (stkf->stkfram_callfun)) : NULL;
    unsigned nbclosed_82ho9wUUDji_4peMLha4PXl =
      closurewidth_BM ((const value_tyBM) callclos_82ho9wUUDji_4peMLha4PXl);
    if (nbclosed_82ho9wUUDji_4peMLha4PXl > 0)
      _.o_4ITcQtvlMmO_30Pss9oAVDB = objectcast_BM (callclos_82ho9wUUDji_4peMLha4PXl->nodt_sons[0]);     // o_findobj
  }                             // fetched 1 closed values in _82ho9wUUDji_4peMLha4PXl.
  // routine _82ho9wUUDji_4peMLha4PXl body:

startblock__6YnYKKsHo3f_9nIEOZMp744:__attribute__ ((unused));
  {                             /* +block _6YnYKKsHo3f_9nIEOZMp744 */

    {                           // run _7m9brpKxZkY_3BEI7YANJuJ 
      /*begin findobj_scan_minifunc */
      WEAKASSERT_BM (objectisinstance_BM
                     ( /*o_findobj: */ _.o_4ITcQtvlMmO_30Pss9oAVDB,
                      (constob_3BFt4NfJmZC_7iYi2dwM38B_BM[42]
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
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _82ho9wUUDji_4peMLha4PXl routine#19 findobj_scan_minifunc




value_tyBM crout_83faYJmqTAm_5Um8Vj0myAd_BM     //#20
  (struct stackframe_stBM * stkf,       //
//!emit_jstoplevel°jscript_topfunction_object <o_jscurcomp (o_jsgenmod o_strbuf v_i)
   // 3 arguments
   const value_tyBM arg0,       // o_jsgenmod
   const value_tyBM arg1,       // o_strbuf
   const value_tyBM arg2,       // v_i
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _83faYJmqTAm_5Um8Vj0myAd
  struct frame_83faYJmqTAm_5Um8Vj0myAd_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 4 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    value_tyBM v_3vRFuniDv1K_4bQ7DeekM2I;       // v_i
    objectval_tyBM *o_41F1rKwGbaA_30OJWKsqNWy;  // o_strbuf
    objectval_tyBM *o_4JKd986pvM4_6yBzeeI40vW;  // o_jsgenmod
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_83faYJmqTAm_5Um8Vj0myAd_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 4;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[58] /*|_83faYJmqTAm_5Um8Vj0myAd */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 3 arguments:
  _.o_4JKd986pvM4_6yBzeeI40vW = objectcast_BM (arg0);   // o_jsgenmod
  _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg1);   // o_strbuf
  _.v_3vRFuniDv1K_4bQ7DeekM2I = arg2;   // v_i
  // fetched 3 arguments.
  // no closed values in _83faYJmqTAm_5Um8Vj0myAd.
  // routine _83faYJmqTAm_5Um8Vj0myAd body:

startblock__0tcJ6ukv6Ir_2lDrl0IhO5H:__attribute__ ((unused));
  {                             /* +block _0tcJ6ukv6Ir_2lDrl0IhO5H */

    {                           // run _0qRSsplMyOg_8dI6CY6J2PY 
/*debug start emit_jstoplevel°jscript_topfunction_object (o_jsgenmod o_strbuf v_i)*/
      DBGPRINTF_BM
        ("debug start €%.7s emit_jstoplevel°jscript_topfunction_object o_jsgenmod=%s o_strbuf=%s v_i=%s",
         "_0qRSsplMyOg_8dI6CY6J2PY",
         objectdbg_BM ( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW),
         objectdbg1_BM ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy),
         OUTSTRVALUE_BM ( /*v_i: */ _.v_3vRFuniDv1K_4bQ7DeekM2I));
      ;
    }                           // end run _0qRSsplMyOg_8dI6CY6J2PY 

/* !endingblock _0tcJ6ukv6Ir_2lDrl0IhO5H */
    goto endblock__0tcJ6ukv6Ir_2lDrl0IhO5H;
  endblock__0tcJ6ukv6Ir_2lDrl0IhO5H:;
  }
  /*-block _0tcJ6ukv6Ir_2lDrl0IhO5H */

epilog_83faYJmqTAm_5Um8Vj0myAd:__attribute__ ((unused));
  // routine _83faYJmqTAm_5Um8Vj0myAd epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _83faYJmqTAm_5Um8Vj0myAd routine#20 _83faYJmqTAm_5Um8Vj0myAd




value_tyBM crout_8imWClcIFKt_6w2H2ouB4I6_BM     //#21+
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
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[60] /*|iterate_sequence_minifunc */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 3 arguments:
  _.v_9vc0quxdnhj_3zLw1MEwl1e = arg0;   // v_seq
  _.v_8jKgolslEuE_4dxzrK5R2B4 = arg1;   // v_fun
  _.v_4Q4WBLjAPTV_5WVLmhAvCJY = arg2;   // v_arg
  // fetched 3 arguments.
  // no closed values in iterate_sequence_minifunc.
  // routine _8imWClcIFKt_6w2H2ouB4I6 body:

startblock__2W6NObLb2d4_6OfkP3dYlF3:__attribute__ ((unused));
  {                             /* +block _2W6NObLb2d4_6OfkP3dYlF3 */
    /*leni: */ _.n_833x2jYqhZh_8vDIuJhwz1k =
      //assign _3EakP4EXPLZ_10btDL0iqAt  
      /*seqlength */
      sequencesize_BM ( /*v_seq: */ _.v_9vc0quxdnhj_3zLw1MEwl1e);


    /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B =
      //assign _1Z2mN7VIEbD_4RJunrL2QcV  
      0;



  startblock__3vvVJBONOyK_3kn86nuYwr1:__attribute__ ((unused));
    {                           /* +loop _3vvVJBONOyK_3kn86nuYwr1 */
    startloop__3vvVJBONOyK_3kn86nuYwr1:__attribute__ ((unused));


      if                        /*cond _7pBaII8qZHM_8xoaIKeilBk */
/*when _8qsLnTz2QdD_9nZub2hBMEb:*/
        ((                      /*greaterequal_int: */
           ( /*ii: */ _.n_2W7Ckt2WxEM_4NVYgEWE73B) >=
           ( /*leni: */ _.n_833x2jYqhZh_8vDIuJhwz1k)))
        {                       //body when _8qsLnTz2QdD_9nZub2hBMEb   
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
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _8imWClcIFKt_6w2H2ouB4I6 routine#21 iterate_sequence_minifunc




value_tyBM crout_8Kh2MKilKO4_5qPRBWX9W3a_BM     //#22
  (struct stackframe_stBM * stkf,       //
//!jsemit_expression°jsvar_object >o_jsexpr (o_strbuf o_jsgenmod o_jsgenfun o_paren)
   // 5 arguments
   const value_tyBM arg0,       // o_jsexpr
   const value_tyBM arg1,       // o_strbuf
   const value_tyBM arg2,       // o_jsgenmod
   const value_tyBM arg3,       // o_jsgenfun
   const quasinode_tyBM * restargs /* 1 extrargs */ )
{                               // start of _8Kh2MKilKO4_5qPRBWX9W3a
  struct frame_8Kh2MKilKO4_5qPRBWX9W3a_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 6 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    objectval_tyBM *o_41F1rKwGbaA_30OJWKsqNWy;  // o_strbuf
    objectval_tyBM *o_4JKd986pvM4_6yBzeeI40vW;  // o_jsgenmod
    objectval_tyBM *o_5Lg7fb6zE3H_6ijQo6GbPN4;  // o_jsgenfun
    objectval_tyBM *o_7ewC6QwZE7K_1LyFtggGrGW;  // o_jsexpr
    objectval_tyBM *o_7N9BaY4jXQb_2V4VMnRwsGD;  // o_paren
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_8Kh2MKilKO4_5qPRBWX9W3a_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 6;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[62] /*|_8Kh2MKilKO4_5qPRBWX9W3a */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 5 arguments:
  unsigned nbrestargs = treewidth_BM ((value_tyBM) restargs);
  _.o_7ewC6QwZE7K_1LyFtggGrGW = objectcast_BM (arg0);   // o_jsexpr
  _.o_41F1rKwGbaA_30OJWKsqNWy = objectcast_BM (arg1);   // o_strbuf
  _.o_4JKd986pvM4_6yBzeeI40vW = objectcast_BM (arg2);   // o_jsgenmod
  _.o_5Lg7fb6zE3H_6ijQo6GbPN4 = objectcast_BM (arg3);   // o_jsgenfun
  if (nbrestargs > 0)
    _.o_7N9BaY4jXQb_2V4VMnRwsGD = objectcast_BM (restargs->nodt_sons[0]);       // o_paren
  // fetched 5 arguments.
  // no closed values in _8Kh2MKilKO4_5qPRBWX9W3a.
  // routine _8Kh2MKilKO4_5qPRBWX9W3a body:

startblock__3FmlgpoQDOO_5eAL3UuBax6:__attribute__ ((unused));
  {                             /* +block _3FmlgpoQDOO_5eAL3UuBax6 */

    {                           // run _3OnfwHME8u1_83OjQFPJ0AX 
/*debug start jsemit_expression°jsvar_object*/
      DBGPRINTF_BM
        ("€%.8s start jsemit_expression°jsvar_object o_jsexpr=%s o_strbuf=%s o_jsgenmod=%s o_jsgenfun=%s o_paren=%s",
         "_3OnfwHME8u1_83OjQFPJ0AX",
         objectdbg_BM ( /*o_jsexpr: */ _.o_7ewC6QwZE7K_1LyFtggGrGW),
         objectdbg1_BM ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy),
         objectdbg2_BM ( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW),
         objectdbg3_BM ( /*o_jsgenfun: */ _.o_5Lg7fb6zE3H_6ijQo6GbPN4),
         objectdbg4_BM ( /*o_paren: */ _.o_7N9BaY4jXQb_2V4VMnRwsGD));
      ;
    }                           // end run _3OnfwHME8u1_83OjQFPJ0AX 


    {                           // start cexpansion _8V1yCkRdpdT_2aFikMmHFDs - objstrbufferappendcstrpayl  
      /*objstrbufferappendcstrpayl: */
      objstrbufferappendcstrpayl_BM (( /*o_strbuf: */ _.
                                      o_41F1rKwGbaA_30OJWKsqNWy), (" jsvar"));
    }                           // end cexpansion _8V1yCkRdpdT_2aFikMmHFDs - objstrbufferappendcstrpayl  


    {                           // start cexpansion _9KVLuxKJ7WT_0WiGnkMOipU - objstrbufferprintobjid  
/*objstrbufferprintobjid _9KVLuxKJ7WT_0WiGnkMOipU:*/
      objectval_tyBM *obsbuf__9KVLuxKJ7WT_0WiGnkMOipU =
        ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy);
      objectval_tyBM *ob__9KVLuxKJ7WT_0WiGnkMOipU =
        ( /*o_jsexpr: */ _.o_7ewC6QwZE7K_1LyFtggGrGW);
      if (objhasstrbufferpayl_BM (obsbuf__9KVLuxKJ7WT_0WiGnkMOipU)
          && isobject_BM (ob__9KVLuxKJ7WT_0WiGnkMOipU))
        {
          char idbuf__9KVLuxKJ7WT_0WiGnkMOipU[32];
          memset (idbuf__9KVLuxKJ7WT_0WiGnkMOipU, 0,
                  sizeof (idbuf__9KVLuxKJ7WT_0WiGnkMOipU));
          idtocbuf32_BM (objid_BM (ob__9KVLuxKJ7WT_0WiGnkMOipU),
                         idbuf__9KVLuxKJ7WT_0WiGnkMOipU);
          objstrbufferappendcstrpayl_BM (obsbuf__9KVLuxKJ7WT_0WiGnkMOipU,
                                         idbuf__9KVLuxKJ7WT_0WiGnkMOipU);
        };
// end objstrbufferprintobjid _9KVLuxKJ7WT_0WiGnkMOipU
      ;
    }                           // end cexpansion _9KVLuxKJ7WT_0WiGnkMOipU - objstrbufferprintobjid  


    if                          /*cond _9HMXY0EZtXo_6MLUAUEw1UL */
/*when _41gDFw6Q34S_0tgSSCzuiwX:*/
      (                         /*object_has_name: */
        (intptr_t)
        (findobjectname_BM ( /*o_jsexpr: */ _.o_7ewC6QwZE7K_1LyFtggGrGW) !=
         NULL))
      {                         //body when _41gDFw6Q34S_0tgSSCzuiwX  
        {                       // start cexpansion _4CkwVXeK6hz_2U6X00XcK4r - objstrbufferappendcstrpayl   
          /*objstrbufferappendcstrpayl: */
          objstrbufferappendcstrpayl_BM (( /*o_strbuf: */ _.
                                          o_41F1rKwGbaA_30OJWKsqNWy),
                                         ("/*:"));
        }                       // end cexpansion _4CkwVXeK6hz_2U6X00XcK4r - objstrbufferappendcstrpayl   
        {                       // start cexpansion _7RBawjBQCzu_0EsH0axRw2Z - objstrbufferprintobject   
/*objstrbufferprintobject _7RBawjBQCzu_0EsH0axRw2Z:*/
          objectval_tyBM *obsbuf_7RBawjBQCzu_0EsH0axRw2Z =
            ( /*o_strbuf: */ _.o_41F1rKwGbaA_30OJWKsqNWy);
          objectval_tyBM *ob_7RBawjBQCzu_0EsH0axRw2Z =
            ( /*o_jsexpr: */ _.o_7ewC6QwZE7K_1LyFtggGrGW);
          if (objhasstrbufferpayl_BM (obsbuf_7RBawjBQCzu_0EsH0axRw2Z)
              && isobject_BM (ob_7RBawjBQCzu_0EsH0axRw2Z))
            objstrbufferappendcstrpayl_BM (obsbuf_7RBawjBQCzu_0EsH0axRw2Z,
                                           objectdbg_BM
                                           (ob_7RBawjBQCzu_0EsH0axRw2Z));
// end objstrbufferprintobject _7RBawjBQCzu_0EsH0axRw2Z
          ;
        }                       // end cexpansion _7RBawjBQCzu_0EsH0axRw2Z - objstrbufferprintobject   
        {                       // start cexpansion _6Rp0SzCgwFQ_078JzGSsqk0 - objstrbufferappendcstrpayl   
          /*objstrbufferappendcstrpayl: */
          objstrbufferappendcstrpayl_BM (( /*o_strbuf: */ _.
                                          o_41F1rKwGbaA_30OJWKsqNWy),
                                         ("*/ "));
        }                       // end cexpansion _6Rp0SzCgwFQ_078JzGSsqk0 - objstrbufferappendcstrpayl   

      }                         //endwhen _41gDFw6Q34S_0tgSSCzuiwX  
    else
      {                         /*cond else _9HMXY0EZtXo_6MLUAUEw1UL */
        {                       // start cexpansion _9B0uU7lqmlq_1TK6O7sJfGh - objstrbufferappendcstrpayl  
          /*objstrbufferappendcstrpayl: */
          objstrbufferappendcstrpayl_BM (( /*o_strbuf: */ _.
                                          o_41F1rKwGbaA_30OJWKsqNWy), (" "));
        }                       // end cexpansion _9B0uU7lqmlq_1TK6O7sJfGh - objstrbufferappendcstrpayl  
      }                         /*cond else _9HMXY0EZtXo_6MLUAUEw1UL */
/*endcond _9HMXY0EZtXo_6MLUAUEw1UL*/


    /*return _2Mwj2UU5zMN_4XQkijImdbO: *//*v_r: */ _.
      v_3qw9bnATIhq_8loBraLeXzQ =
      // returned 
      /*o_jsexpr: */ _.o_7ewC6QwZE7K_1LyFtggGrGW;
    goto epilog_8Kh2MKilKO4_5qPRBWX9W3a;

/* !endingblock _3FmlgpoQDOO_5eAL3UuBax6 */
    goto endblock__3FmlgpoQDOO_5eAL3UuBax6;
  endblock__3FmlgpoQDOO_5eAL3UuBax6:;
  }
  /*-block _3FmlgpoQDOO_5eAL3UuBax6 */

epilog_8Kh2MKilKO4_5qPRBWX9W3a:__attribute__ ((unused));
  // routine _8Kh2MKilKO4_5qPRBWX9W3a epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _8Kh2MKilKO4_5qPRBWX9W3a routine#22 _8Kh2MKilKO4_5qPRBWX9W3a




value_tyBM crout_8VtkXEUFfhk_5RxrpY6JHI6_BM     //#23
  (struct stackframe_stBM * stkf,       //
//!webhandler javascript-compile
   // 2 arguments
   const value_tyBM arg0,       // v_restpath
   const value_tyBM arg1,       // o_webex
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _8VtkXEUFfhk_5RxrpY6JHI6
  struct frame_8VtkXEUFfhk_5RxrpY6JHI6_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 5 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    objectval_tyBM *o_4JKd986pvM4_6yBzeeI40vW;  // o_jsgenmod
    objectval_tyBM *o_5JuT4FgNFFh_7McrTYeT3jx;  // o_webex
    objectval_tyBM *o_5V0w37YnN4F_8dZ6I79V60O;  // o_jsmodule
    value_tyBM v_6QhNRfe1Cte_0niVlWfAlmO;       // v_restpath
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_8VtkXEUFfhk_5RxrpY6JHI6_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 5;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[64] /*|_8VtkXEUFfhk_5RxrpY6JHI6 */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // locking 2:
  objectval_tyBM *locked_4Yw5RJIrSwj_4NezE0gdaiQ = NULL;        // for o_webex
  objectval_tyBM *locked_6GIm9xpffcv_5ZeeEELYWND = NULL;        // for o_jsmodule
  // fetch 2 arguments:
  _.v_6QhNRfe1Cte_0niVlWfAlmO = arg0;   // v_restpath
  _.o_5JuT4FgNFFh_7McrTYeT3jx = objectcast_BM (arg1);   // o_webex
  // fetched 2 arguments.
  {                             // fetch 1 closed values in _8VtkXEUFfhk_5RxrpY6JHI6:
    const closure_tyBM *callclos_8VtkXEUFfhk_5RxrpY6JHI6 =
      (stkf && stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
      ? (closurecast_BM (stkf->stkfram_callfun)) : NULL;
    unsigned nbclosed_8VtkXEUFfhk_5RxrpY6JHI6 =
      closurewidth_BM ((const value_tyBM) callclos_8VtkXEUFfhk_5RxrpY6JHI6);
    if (nbclosed_8VtkXEUFfhk_5RxrpY6JHI6 > 0)
      _.o_5V0w37YnN4F_8dZ6I79V60O = objectcast_BM (callclos_8VtkXEUFfhk_5RxrpY6JHI6->nodt_sons[0]);     // o_jsmodule
  }                             // fetched 1 closed values in _8VtkXEUFfhk_5RxrpY6JHI6.
  // routine _8VtkXEUFfhk_5RxrpY6JHI6 body:

startblock__0n6WAcuQ159_6cO0bI9OjvI:__attribute__ ((unused));
  {                             /* +block _0n6WAcuQ159_6cO0bI9OjvI */

    {                           // begin lockobj _4Yw5RJIrSwj_4NezE0gdaiQ 
      objectval_tyBM *curlockedob_4Yw5RJIrSwj_4NezE0gdaiQ =
        ( /*o_webex: */ _.o_5JuT4FgNFFh_7McrTYeT3jx);
      if (objlock_BM (curlockedob_4Yw5RJIrSwj_4NezE0gdaiQ))
        {
          locked_4Yw5RJIrSwj_4NezE0gdaiQ =
            curlockedob_4Yw5RJIrSwj_4NezE0gdaiQ;

          {                     // start cexpansion _163LYFoPRpv_6YhLXnmvvcf - objputattr  
            /*objputattr: */
            objputattr_BM (( /*o_webex: */ _.o_5JuT4FgNFFh_7McrTYeT3jx),
                           ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[12]
                             /*!web_rest_path */ )),
                           ( /*v_restpath: */ _.v_6QhNRfe1Cte_0niVlWfAlmO));
          }                     // end cexpansion _163LYFoPRpv_6YhLXnmvvcf - objputattr  


          {                     // begin lockobj _6GIm9xpffcv_5ZeeEELYWND 
            objectval_tyBM *curlockedob_6GIm9xpffcv_5ZeeEELYWND =
              ( /*o_jsmodule: */ _.o_5V0w37YnN4F_8dZ6I79V60O);
            if (objlock_BM (curlockedob_6GIm9xpffcv_5ZeeEELYWND))
              {
                locked_6GIm9xpffcv_5ZeeEELYWND =
                  curlockedob_6GIm9xpffcv_5ZeeEELYWND;

                {               // start cexpansion _0KB15AvyxFZ_4I5rT8hdFvI - objstrbufferappendcstrpayl  
                  /*objstrbufferappendcstrpayl: */
                  objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                                  o_5JuT4FgNFFh_7McrTYeT3jx),
                                                 ("// generated jsmodule "));
                }               // end cexpansion _0KB15AvyxFZ_4I5rT8hdFvI - objstrbufferappendcstrpayl  

                {               // start cexpansion _1asQYb8sf6I_26hiF0qzmD5 - objstrbufferprintobjid  
/*objstrbufferprintobjid _1asQYb8sf6I_26hiF0qzmD5:*/
                  objectval_tyBM *obsbuf__1asQYb8sf6I_26hiF0qzmD5 =
                    ( /*o_webex: */ _.o_5JuT4FgNFFh_7McrTYeT3jx);
                  objectval_tyBM *ob__1asQYb8sf6I_26hiF0qzmD5 =
                    ( /*o_jsmodule: */ _.o_5V0w37YnN4F_8dZ6I79V60O);
                  if (objhasstrbufferpayl_BM (obsbuf__1asQYb8sf6I_26hiF0qzmD5)
                      && isobject_BM (ob__1asQYb8sf6I_26hiF0qzmD5))
                    {
                      char idbuf__1asQYb8sf6I_26hiF0qzmD5[32];
                      memset (idbuf__1asQYb8sf6I_26hiF0qzmD5, 0,
                              sizeof (idbuf__1asQYb8sf6I_26hiF0qzmD5));
                      idtocbuf32_BM (objid_BM (ob__1asQYb8sf6I_26hiF0qzmD5),
                                     idbuf__1asQYb8sf6I_26hiF0qzmD5);
                      objstrbufferappendcstrpayl_BM
                        (obsbuf__1asQYb8sf6I_26hiF0qzmD5,
                         idbuf__1asQYb8sf6I_26hiF0qzmD5);
                    };
// end objstrbufferprintobjid _1asQYb8sf6I_26hiF0qzmD5
                  ;
                }               // end cexpansion _1asQYb8sf6I_26hiF0qzmD5 - objstrbufferprintobjid  

                {               // start cexpansion _3wwLQjWB3gd_1hBELsx2uQh - objstrbufferappendcstrpayl  
                  /*objstrbufferappendcstrpayl: */
                  objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                                  o_5JuT4FgNFFh_7McrTYeT3jx),
                                                 (" generated on "));
                }               // end cexpansion _3wwLQjWB3gd_1hBELsx2uQh - objstrbufferappendcstrpayl  

                {               // start cexpansion _4Td6Y7BXGce_3ur9tSNjAcl - objstrbufferprintstringval  
/*objstrbufferprintstringval:*/
                  if (objhasstrbufferpayl_BM
                      ( /*o_webex: */ _.o_5JuT4FgNFFh_7McrTYeT3jx)
                      && isstring_BM ( /*flocaltimestring: */ (value_tyBM)
                                      flocaltimestring_BM (("%c %Z"), (time_t) (
                                                                                 /*timenow: */
                                                                                 (intptr_t) time (NULL)))))
                    objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                                    o_5JuT4FgNFFh_7McrTYeT3jx),
                                                   bytstring_BM ((const
                                                                  stringval_tyBM
                                                                  *) (
                                                                          /*flocaltimestring: */
                                                                          (value_tyBM) flocaltimestring_BM (("%c %Z"), (time_t) (
                                                                                                                                  /*timenow: */
                                                                                                                                  (intptr_t) time (NULL))))));;
                }               // end cexpansion _4Td6Y7BXGce_3ur9tSNjAcl - objstrbufferprintstringval   

                {               // start cexpansion _0WDhX5koqTV_8hamJbCagx0 - objstrbuffernewlinepayl  
                  /*objstrbuffernewlinepayl: */ objstrbuffernewlinepayl_BM ( /*o_webex: */ _.o_5JuT4FgNFFh_7McrTYeT3jx);
                }               // end cexpansion _0WDhX5koqTV_8hamJbCagx0 - objstrbuffernewlinepayl  


                {               // run _6s18x01H2kW_95VyfrjuDcx 
/*debug o_jsmodule*/
                  DBGPRINTF_BM
                    ("webhandler javascript-compile o_webex=%s before compilation of o_jsmodule=%s",
                     objectdbg_BM ( /*o_webex: */ _.
                                   o_5JuT4FgNFFh_7McrTYeT3jx),
                     objectdbg1_BM ( /*o_jsmodule: */ _.
                                    o_5V0w37YnN4F_8dZ6I79V60O));;
                }               // end run _6s18x01H2kW_95VyfrjuDcx 

                /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW =
                  //assign _9ufTIz2pjEe_60rVNzMY1yR  
                  /*val_to_object: */
                  objectcast_BM ((send1_BM (( /*o_jsmodule: */ _.
                                             o_5V0w37YnN4F_8dZ6I79V60O),        /*sel: */
                                            ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[50]
                                              /*!compile_to_javascript */ )),
                                            ((struct stackframe_stBM *) &_),
                                            ( /*o_webex: */ _.
                                             o_5JuT4FgNFFh_7McrTYeT3jx))));

                if              /*cond _834nxcKsieW_1MtErfqEz3M */
/*when _8wB9CPMDqLU_50GKqZfe8ms:*/
                  (             /*is_null: */
                    (( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW) == NULL))
                  {             //body when _8wB9CPMDqLU_50GKqZfe8ms  
//failure _5YZZHXQmxrc_3SVoZ26utAx   
                    PLACEDFAILURE_BM (__LINE__,
                                      /*failreason: */ (((value_tyBM) makenode1_BM
                                                         (
                                                           /*make_node conn: */
                                                           ((constob_3BFt4NfJmZC_7iYi2dwM38B_BM[50] /*!compile_to_javascript */ )),
/*make_node 1 sons: */
                                                           ( /*o_jsmodule: */
                                                            _.
                                                            o_5V0w37YnN4F_8dZ6I79V60O)))),
                                      /*failplace: */
                                      ( /*modconst: */
                                        (constob_3BFt4NfJmZC_7iYi2dwM38B_BM
                                         [41]
                                         /*|_5YZZHXQmxrc_3SVoZ26utAx */ )),
                                      ((struct stackframe_stBM *) &_));

                  }             //endwhen _8wB9CPMDqLU_50GKqZfe8ms  
/*endcond _834nxcKsieW_1MtErfqEz3M*/


                {               // run _7VusVpVj5C6_40OJ8iWNjbT 
/*debug o_jsgenmod o_jsmodule o_webex*/
                  DBGPRINTF_BM
                    ("webhandler javascript after compile_to_javascript o_jsgenmod=%s o_jsmodule=%s o_webex=%s",
                     objectdbg_BM ( /*o_jsgenmod: */ _.
                                   o_4JKd986pvM4_6yBzeeI40vW),
                     objectdbg1_BM ( /*o_jsmodule: */ _.
                                    o_5V0w37YnN4F_8dZ6I79V60O),
                     objectdbg2_BM ( /*o_webex: */ _.
                                    o_5JuT4FgNFFh_7McrTYeT3jx));
                  ;
                }               // end run _7VusVpVj5C6_40OJ8iWNjbT 

                {               // start cexpansion _0vogp7Ejh5z_0BJLzVAzBEs - objstrbuffernewlinepayl  
                  /*objstrbuffernewlinepayl: */ objstrbuffernewlinepayl_BM ( /*o_webex: */ _.o_5JuT4FgNFFh_7McrTYeT3jx);
                }               // end cexpansion _0vogp7Ejh5z_0BJLzVAzBEs - objstrbuffernewlinepayl  

                {               // start cexpansion _02N8YyDubv0_4iLf4iVb08b - objstrbuffernewlinepayl  
                  /*objstrbuffernewlinepayl: */ objstrbuffernewlinepayl_BM ( /*o_webex: */ _.o_5JuT4FgNFFh_7McrTYeT3jx);
                }               // end cexpansion _02N8YyDubv0_4iLf4iVb08b - objstrbuffernewlinepayl  

                {               // start cexpansion _0ixvvbvycpg_6XwGIwBWqgT - objstrbufferappendcstrpayl  
                  /*objstrbufferappendcstrpayl: */
                  objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                                  o_5JuT4FgNFFh_7McrTYeT3jx),
                                                 ("// end javascript generation "));
                }               // end cexpansion _0ixvvbvycpg_6XwGIwBWqgT - objstrbufferappendcstrpayl  

                {               // start cexpansion _4TtArYe1OZr_6h7qpeLoXhc - objstrbufferprintobjid  
/*objstrbufferprintobjid _4TtArYe1OZr_6h7qpeLoXhc:*/
                  objectval_tyBM *obsbuf__4TtArYe1OZr_6h7qpeLoXhc =
                    ( /*o_webex: */ _.o_5JuT4FgNFFh_7McrTYeT3jx);
                  objectval_tyBM *ob__4TtArYe1OZr_6h7qpeLoXhc =
                    ( /*o_jsgenmod: */ _.o_4JKd986pvM4_6yBzeeI40vW);
                  if (objhasstrbufferpayl_BM (obsbuf__4TtArYe1OZr_6h7qpeLoXhc)
                      && isobject_BM (ob__4TtArYe1OZr_6h7qpeLoXhc))
                    {
                      char idbuf__4TtArYe1OZr_6h7qpeLoXhc[32];
                      memset (idbuf__4TtArYe1OZr_6h7qpeLoXhc, 0,
                              sizeof (idbuf__4TtArYe1OZr_6h7qpeLoXhc));
                      idtocbuf32_BM (objid_BM (ob__4TtArYe1OZr_6h7qpeLoXhc),
                                     idbuf__4TtArYe1OZr_6h7qpeLoXhc);
                      objstrbufferappendcstrpayl_BM
                        (obsbuf__4TtArYe1OZr_6h7qpeLoXhc,
                         idbuf__4TtArYe1OZr_6h7qpeLoXhc);
                    };
// end objstrbufferprintobjid _4TtArYe1OZr_6h7qpeLoXhc
                  ;
                }               // end cexpansion _4TtArYe1OZr_6h7qpeLoXhc - objstrbufferprintobjid  

                {               // start cexpansion _7shOFK0VXhy_8SUN2RB5UL3 - objstrbufferappendcstrpayl  
                  /*objstrbufferappendcstrpayl: */
                  objstrbufferappendcstrpayl_BM (( /*o_webex: */ _.
                                                  o_5JuT4FgNFFh_7McrTYeT3jx),
                                                 (" for o_jsmodule="));
                }               // end cexpansion _7shOFK0VXhy_8SUN2RB5UL3 - objstrbufferappendcstrpayl  

                {               // start cexpansion _6A1LVu1jMbs_1uJY58z11HY - objstrbufferprintobject  
/*objstrbufferprintobject _6A1LVu1jMbs_1uJY58z11HY:*/
                  objectval_tyBM *obsbuf_6A1LVu1jMbs_1uJY58z11HY =
                    ( /*o_webex: */ _.o_5JuT4FgNFFh_7McrTYeT3jx);
                  objectval_tyBM *ob_6A1LVu1jMbs_1uJY58z11HY =
                    ( /*o_jsmodule: */ _.o_5V0w37YnN4F_8dZ6I79V60O);
                  if (objhasstrbufferpayl_BM (obsbuf_6A1LVu1jMbs_1uJY58z11HY)
                      && isobject_BM (ob_6A1LVu1jMbs_1uJY58z11HY))
                    objstrbufferappendcstrpayl_BM
                      (obsbuf_6A1LVu1jMbs_1uJY58z11HY,
                       objectdbg_BM (ob_6A1LVu1jMbs_1uJY58z11HY));
// end objstrbufferprintobject _6A1LVu1jMbs_1uJY58z11HY
                  ;
                }               // end cexpansion _6A1LVu1jMbs_1uJY58z11HY - objstrbufferprintobject  

                {               // start cexpansion _8cBldF2E4sS_6nEYi5Fubih - objstrbuffernewlinepayl  
                  /*objstrbuffernewlinepayl: */ objstrbuffernewlinepayl_BM ( /*o_webex: */ _.o_5JuT4FgNFFh_7McrTYeT3jx);
                }               // end cexpansion _8cBldF2E4sS_6nEYi5Fubih - objstrbuffernewlinepayl  

                {               // start cexpansion _2aNdEppQolr_46RGo9i35gr - objstrbuffernewlinepayl  
                  /*objstrbuffernewlinepayl: */ objstrbuffernewlinepayl_BM ( /*o_webex: */ _.o_5JuT4FgNFFh_7McrTYeT3jx);
                }               // end cexpansion _2aNdEppQolr_46RGo9i35gr - objstrbuffernewlinepayl  

                {               // start cexpansion _3Ik736kQ5Uw_5WxtZn5mvBq - objwebexchangecompletepayl  
                  /*objwebexchangecompletepayl: */
                  objwebexchangecompletepayl_BM (( /*o_webex: */ _.
                                                  o_5JuT4FgNFFh_7McrTYeT3jx),
                                                 (200),
                                                 ("application/javascript; charset=utf-8"));
                }               // end cexpansion _3Ik736kQ5Uw_5WxtZn5mvBq - objwebexchangecompletepayl  

                /*return _5IknCErYDMv_1AeqYkXvrSL: *//*v_r: */ _.
                  v_3qw9bnATIhq_8loBraLeXzQ =
                  // returned 
                  /*o_webex: */ _.o_5JuT4FgNFFh_7McrTYeT3jx;
                goto epilog_8VtkXEUFfhk_5RxrpY6JHI6;

                objunlock_BM (locked_6GIm9xpffcv_5ZeeEELYWND),
                  locked_6GIm9xpffcv_5ZeeEELYWND = NULL;
              }
          }                     // end objlock _6GIm9xpffcv_5ZeeEELYWND 

          objunlock_BM (locked_4Yw5RJIrSwj_4NezE0gdaiQ),
            locked_4Yw5RJIrSwj_4NezE0gdaiQ = NULL;
        }
    }                           // end objlock _4Yw5RJIrSwj_4NezE0gdaiQ 
/* !endingblock _0n6WAcuQ159_6cO0bI9OjvI */
    goto endblock__0n6WAcuQ159_6cO0bI9OjvI;
  endblock__0n6WAcuQ159_6cO0bI9OjvI:;
  }
  /*-block _0n6WAcuQ159_6cO0bI9OjvI */

epilog_8VtkXEUFfhk_5RxrpY6JHI6:__attribute__ ((unused));
  // routine _8VtkXEUFfhk_5RxrpY6JHI6 epilogue:
  // unlocking 2:
  if (locked_4Yw5RJIrSwj_4NezE0gdaiQ != NULL)
    objunlock_BM (locked_4Yw5RJIrSwj_4NezE0gdaiQ), locked_4Yw5RJIrSwj_4NezE0gdaiQ = NULL;       // for o_webex
  if (locked_6GIm9xpffcv_5ZeeEELYWND != NULL)
    objunlock_BM (locked_6GIm9xpffcv_5ZeeEELYWND), locked_6GIm9xpffcv_5ZeeEELYWND = NULL;       // for o_jsmodule
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _8VtkXEUFfhk_5RxrpY6JHI6 routine#23 _8VtkXEUFfhk_5RxrpY6JHI6




value_tyBM crout_9CG8SKNs6Ql_4PiHd8cnydn_BM     //#24
  (struct stackframe_stBM * stkf,       //
//!clear°dict_object minifun
   // 1 arguments
   const value_tyBM arg0,       // odict
   const value_tyBM arg1_ __attribute__ ((unused)),
   const value_tyBM arg2_ __attribute__ ((unused)),
   const value_tyBM arg3_ __attribute__ ((unused)),
   const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{                               // start of _9CG8SKNs6Ql_4PiHd8cnydn
  struct frame_9CG8SKNs6Ql_4PiHd8cnydn_BMst
  {
    typedhead_tyBM stkfram_head;
    struct stackframe_stBM *stkfram_prev;
    objectval_tyBM *stkfram_descr;
    value_tyBM stkfram_callfun;
    int stkfram_state;
    int stkfram_extra;
    /// 2 local values:
    value_tyBM v_3qw9bnATIhq_8loBraLeXzQ;       // v_r
    objectval_tyBM *o_7n2SLLuWOjH_4ArhFUjmckz;  // odict
    /// 0 local numbers:
  } _;
  memset (&_, 0, sizeof (struct frame_9CG8SKNs6Ql_4PiHd8cnydn_BMst));
  _.stkfram_head.htyp = typayl_StackFrame_BM;
  _.stkfram_head.hgc = 0;
  _.stkfram_head.rlen = 2;
  _.stkfram_descr =
    constob_3BFt4NfJmZC_7iYi2dwM38B_BM[70] /*|_9CG8SKNs6Ql_4PiHd8cnydn */ ;
  ASSERT_BM (!stkf || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
  _.stkfram_prev = stkf;
  // fetch 1 arguments:
  _.o_7n2SLLuWOjH_4ArhFUjmckz = objectcast_BM (arg0);   // odict
  // fetched 1 arguments.
  // no closed values in _9CG8SKNs6Ql_4PiHd8cnydn.
  // routine _9CG8SKNs6Ql_4PiHd8cnydn body:

startblock__1lmLI285f7p_4im4Ls4Xewh:__attribute__ ((unused));
  {                             /* +block _1lmLI285f7p_4im4Ls4Xewh */
    if                          /*cond _58n2IHCyrnJ_19R71AKw5aF */
/*when _8QkV0tL7Jvt_9mc0QaZYbyv:*/
      (                         /*objputdictpayl: */
        objputdictpayl_BM (( /*odict: */ _.o_7n2SLLuWOjH_4ArhFUjmckz)))
      {                         //body when _8QkV0tL7Jvt_9mc0QaZYbyv  
        /*return _2RCw0JQb23v_2NfFku112jv: *//*v_r: */ _.
          v_3qw9bnATIhq_8loBraLeXzQ =
          // returned  
          /*odict: */ _.o_7n2SLLuWOjH_4ArhFUjmckz;
        goto epilog_9CG8SKNs6Ql_4PiHd8cnydn;

      }                         //endwhen _8QkV0tL7Jvt_9mc0QaZYbyv  
/*endcond _58n2IHCyrnJ_19R71AKw5aF*/


    if                          /*cond _4QR8kuWiKxV_9oKMeD79KDQ */
/*when _8bCPs7gML9M_12nXMrdhzvW:*/
      (                         /*objputdictpayl: */
        objputdictpayl_BM (( /*odict: */ _.o_7n2SLLuWOjH_4ArhFUjmckz)))
      {                         //body when _8bCPs7gML9M_12nXMrdhzvW  
        /*return _9198YxnrBs6_7u9nhmAA8Q6: *//*v_r: */ _.
          v_3qw9bnATIhq_8loBraLeXzQ =
          // returned  
          /*odict: */ _.o_7n2SLLuWOjH_4ArhFUjmckz;
        goto epilog_9CG8SKNs6Ql_4PiHd8cnydn;

      }                         //endwhen _8bCPs7gML9M_12nXMrdhzvW  
/*endcond _4QR8kuWiKxV_9oKMeD79KDQ*/

/* !endingblock _1lmLI285f7p_4im4Ls4Xewh */
    goto endblock__1lmLI285f7p_4im4Ls4Xewh;
  endblock__1lmLI285f7p_4im4Ls4Xewh:;
  }
  /*-block _1lmLI285f7p_4im4Ls4Xewh */

epilog_9CG8SKNs6Ql_4PiHd8cnydn:__attribute__ ((unused));
  // routine _9CG8SKNs6Ql_4PiHd8cnydn epilogue:
  if (stkf)
    stkf->stkfram_callfun = NULL;
  return /*v_r: */ _.v_3qw9bnATIhq_8loBraLeXzQ;
}                               // end _9CG8SKNs6Ql_4PiHd8cnydn routine#24 _9CG8SKNs6Ql_4PiHd8cnydn




// end of 25 generated routines


// the constant ids for 71 constants:
const char *const constid_3BFt4NfJmZC_7iYi2dwM38B_BM[71 + 1] = {
  /*0: */
  "_09Hug4WGnPK_7PpZby8pz84",   //! emit_epilogue_jsmodule°jsmodule_generation_object
  "_0cRampCGHNI_3i998lc5QJ5",   //jsmodule_bindings
  "_0cUdonky1bM_4IVhwlVRBMk",   //! webhandler testhello minifunc
  "_0eMGYofuNVh_8ZP2mXdhtHO",   //in
  "_0jFqaPPHgYH_5JpjOPxQ67p",   //arguments
  /*5: */
  "_0G2hYx4ZxhG_4bujYGDgno0",   //jsfun_preparation_object
  "_0JktC4mAHCa_1KNr6uMIqIi",   //! dump_scan°list_object minifunc for list_object o1 & dumperobj o2
  "_0Lk9WQfjqpU_0XROvsMVANm",   //! otherwise fail since v_resprep bad
  "_0SinERsgdvQ_57dLCP63i9r",   //! forgetname#command_handler
  "_0YanmudmN6Q_0JCzJElBQ7u",   //jsvar_object
  /*10: */
  "_0YOXUe7rEJC_3jFMjOAQRs9",   //element_of_closed_minifunc
  "_1dzZlwqKdLH_8HjkBsL9Mar",   //add
  "_1v8IW7POMtj_8PSZo0ZuSlN",   //web_rest_path
  "_1DGcmfymxyC_2TiD1HX0HU5",   //emit_for_jsmodule
  "_1FEnnpEkGdI_5DAcVDL5XHG",   //dump_value
  /*15: */
  "_1HZc1VBbjdB_96aQTEPgEX0",   //! emit_prologue_jsmodule°jsmodule_generation_object
  "_1SolDiQA2WM_4IDOJKBiPFc",   //for
  "_22Zd68WPKUO_6AoIuBcbUb2",   //! dump_scan°dict_object minifunc for dict-object odict and dumperobj odumper
  "_24bEb3kwyYA_1mHv1lX7cp6",   //jscript_variable
  "_24sSVIADeHm_0Sx34wQfG7W",   //locals
  /*20: */
  "_2bZ4BfCci5V_3WTzG7V25y4",   //! put°dict_object minifunc
  "_2YrbiKQ6lxP_3KNUOnU6TF5",   //duplicate
  "_3fycBOpG51y_7Jfx9BLe3U2",   //! fail since o_varialbe not instance of jsvar_object
  "_3iiht57Wrs1_5NbiUi27oBn",   //! prepend°list_object minifunc
  "_3vI0Qc3FHQG_1g4fmHYkxSA",   //! compile_to_javascript°jsmodule_object (o_jsmodule, o_strbuf)
  /*25: */
  "_3yQlckX4DRh_4b9l9FBSSSL",   //same_as_closed_minifunc
  "_3BFLweNp6f9_4v8sSIEqDFa",   //! fail with bad_class for o_variable o_jsexpr o_jsgenmod
  "_3HAeZZQ0q7b_7qyDsekaz7Y",   //! clear°list_object minifunc
  "_401XcQg0VWc_1SG4xaaQ3mU",   //! fail because v_resemit null after emit_prologue_jsmodule
  "_44Xro7p814I_406P69WFbq4",   //! prepare_for_jsmodule°jscript_topvardef_object <o_jscurcomp (o_jsgenmod)
  /*30: */
  "_4iEFTEcHxeb_6lH464uFkTC",   //equal_to_closed_minifunc
  "_4jwFGdaECBb_6dsBLTMoG9j",   //! fail badclass o_jscurcomp
  "_4lj3ntdp7xH_5LiKY8h0lHl",   //! fail emit_jstoplevel (o_jscurcomp ii o_jsgenmod)
  "_4qlegfkPzrC_17skUfJP7v8",   //! dump_data°dict_object minifun
  "_4HgYLk6htvP_4Ac2FCPfQ1C",   //failure_bad_class
  /*35: */
  "_4M7lr5cU6VD_5hxmeH3baBf",   //! append°list_object minifunction
  "_4NpdCbcwwBV_9f3dbfoieTG",   //jsemit_expression
  "_54fNPWQdMQd_4bZQKbcUvkR",   //emit_prologue_jsmodule
  "_5j8LpQULt1p_9oeOaqmfYYr",   //! dump_data°list_object minifunc
  "_5qJ7wfXtzlW_30GNcoDmv10",   //sbuf
  /*40: */
  "_5ucAZimYynS_4VA0XHvr1nW",   //variable
  "_5YZZHXQmxrc_3SVoZ26utAx",   //! fail compile_to_javascript o_jsmodule
  "_64UbCFBD19G_43TeBXhcYMy",   //findrun_object
  "_68ynNIWu3mp_1Th7hFVKtoO",   //! fail duplicate o_variable o_jscurcomp os_jgenmod o_bindings
  "_6pp3g7GLuae_7OF8KezKzvx",   //! fail non-object
  /*45: */
  "_6yWldsq3Rmk_01WqTfwSIDV",   //failure_non_object
  "_6EJRQxPiepy_50fow66D4Qn",   //is_null
  "_6ZQ05nCv3Ys_8LA6B5LkZgm",   //assoc_object
  "_74TaCoUa4dg_2bmUAanJYIJ",   //! emit_jstoplevel°jscript_topvardef_object <o_jscurcomp (o_jsgenmod o_strbuf v_i)
  "_75mkz7wH3u3_0ZQRFajA44k",   //! fail since v_resemit null, giving o_jsgenmod
  /*50: */
  "_7icWqFMdb4f_2Z6ymmBVulP",   //compile_to_javascript
  "_7lrEc2aXmp8_6MlRQh2foQF",   //! fail because o_curvar is null in v_arguments[ii]
  "_7zLaPay40r6_5iPrtG8Hiq4",   //prepare_for_jsmodule
  "_7D8xcWnEiys_8oqOVSkCxkA",   //node
  "_7DQyvJFMOrC_9IfC3CtYknn",   //body
  /*55: */
  "_7KpOCu7pOza_0ApwnGaS3DP",   //jscript_toplevel_object
  "_7TK5bvNNTIg_4pzieotiEq8",   //! prepare_for_jsmodule°jscript_topfunction_object <o_jscurcomp (o_jsgenmod)
  "_82ho9wUUDji_4peMLha4PXl",   //findobj_scan_minifunc
  "_83faYJmqTAm_5Um8Vj0myAd",   //! emit_jstoplevel°jscript_topfunction_object <o_jscurcomp (o_jsgenmod o_strbuf v_i)
  "_8dgEp1oxLMz_5iGP2Eq1wn7",   //emit_jstoplevel
  /*60: */
  "_8imWClcIFKt_6w2H2ouB4I6",   //iterate_sequence_minifunc
  "_8lV53mLyu1H_3Z1SI8wDBK1",   //clear
  "_8Kh2MKilKO4_5qPRBWX9W3a",   //! jsemit_expression°jsvar_object >o_jsexpr (o_strbuf o_jsgenmod o_jsgenfun o_paren)
  "_8Nb7qSIbE8N_7xJDtsS0rdb",   //! fail since o_variable null
  "_8VtkXEUFfhk_5RxrpY6JHI6",   //! webhandler javascript-compile
  /*65: */
  "_934Sfmj7uik_3F2IvtzKrgM",   //! fail jsemit_expression o_variable o_strbuf o_jsgenmod
  "_93zDz6jmlVq_8ckLb59DDIl",   //emit_epilogue_jsmodule
  "_9onbEiQdZKJ_2CGamshEWbT",   //! fail arguments(o_jscurcomp o_jsgenmod v_arguments) when strange v_arguments
  "_9pvzBeIKHXF_8YDPCrQ6OEK",   //put
  "_9zzGR0VqDpm_259EJDSFYyu",   //jsmodule_generation_object
  /*70: */
  "_9CG8SKNs6Ql_4PiHd8cnydn",   //! clear°dict_object minifun
  NULL
};                              // end 71 constant ids



// the routine ids for 25 routines:
const char *const routid_3BFt4NfJmZC_7iYi2dwM38B_BM[25 + 1] = {
  /*0: */
  "_09Hug4WGnPK_7PpZby8pz84",   //!emit_epilogue_jsmodule°jsmodule_generation_object
  "_0cUdonky1bM_4IVhwlVRBMk",   //!webhandler testhello minifunc
  "_0JktC4mAHCa_1KNr6uMIqIi",   //!dump_scan°list_object minifunc for list_object o1 & dumperobj o2
  "_0SinERsgdvQ_57dLCP63i9r",   //!forgetname#command_handler
  "_0YOXUe7rEJC_3jFMjOAQRs9",   //element_of_closed_minifunc
  "_1HZc1VBbjdB_96aQTEPgEX0",   //!emit_prologue_jsmodule°jsmodule_generation_object
  "_22Zd68WPKUO_6AoIuBcbUb2",   //!dump_scan°dict_object minifunc for dict-object odict and dumperobj odumper
  "_2bZ4BfCci5V_3WTzG7V25y4",   //!put°dict_object minifunc;
  /*8: */
  "_3iiht57Wrs1_5NbiUi27oBn",   //!prepend°list_object minifunc
  "_3vI0Qc3FHQG_1g4fmHYkxSA",   //!compile_to_javascript°jsmodule_object (o_jsmodule, o_strbuf)
  "_3yQlckX4DRh_4b9l9FBSSSL",   //same_as_closed_minifunc
  "_3HAeZZQ0q7b_7qyDsekaz7Y",   //!clear°list_object minifunc
  "_44Xro7p814I_406P69WFbq4",   //!prepare_for_jsmodule°jscript_topvardef_object <o_jscurcomp (o_jsgenmod)
  "_4iEFTEcHxeb_6lH464uFkTC",   //equal_to_closed_minifunc
  "_4qlegfkPzrC_17skUfJP7v8",   //!dump_data°dict_object minifunc
  "_4M7lr5cU6VD_5hxmeH3baBf",   //!append°list_object minifunction
  /*16: */
  "_5j8LpQULt1p_9oeOaqmfYYr",   //!dump_data°list_object minifunc;
  "_74TaCoUa4dg_2bmUAanJYIJ",   //!emit_jstoplevel°jscript_topvardef_object <o_jscurcomp (o_jsgenmod o_strbuf v_i)
  "_7TK5bvNNTIg_4pzieotiEq8",   //!prepare_for_jsmodule°jscript_topfunction_object <o_jscurcomp (o_jsgenmod)
  "_82ho9wUUDji_4peMLha4PXl",   //findobj_scan_minifunc
  "_83faYJmqTAm_5Um8Vj0myAd",   //!emit_jstoplevel°jscript_topfunction_object <o_jscurcomp (o_jsgenmod o_strbuf v_i)
  "_8imWClcIFKt_6w2H2ouB4I6",   //iterate_sequence_minifunc
  "_8Kh2MKilKO4_5qPRBWX9W3a",   //!jsemit_expression°jsvar_object >o_jsexpr (o_strbuf o_jsgenmod o_jsgenfun o_paren)
  "_8VtkXEUFfhk_5RxrpY6JHI6",   //!webhandler javascript-compile
  /*24: */
  "_9CG8SKNs6Ql_4PiHd8cnydn",   //!clear°dict_object minifunc

  NULL
};                              // end 25 routine ids



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
