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



// declare 14 routines

extern const char *const routid_1lhXvXtIyPu_3nhuy4kN3wd_BM[14+1];


// 38 failures

extern objrout_sigBM crout_08PMymoD6YJ_8rspWoCg4Xu_BM; //#0 !emit_statement°basiclo_outstmt < o_stmt (o_modgen o_routprep v_depth)

extern objrout_sigBM crout_09YrB2RcKY0_8qXAVUhGxat_BM; //#1 !emit_label°basiclo_jsonex_label < o_label (o_modgen o_routprep depth)

extern objrout_sigBM crout_0eLqstoeREp_44oHD9QEdRx_BM; //#2 !emit_block°basiclo_labeled_block [v_with_label] < o_block (o_modgen o_routprep v_depth)

extern objrout_sigBM crout_0jZB3m3ntxR_7JPnMzyIoBg_BM; //#3 !extract_json#readmacro(v_node v_lineno v_colpos o_parser)

extern objrout_sigBM crout_0vCFi47Ctm6_70R5Tci6JuH_BM; //#4 !emit_block°basiclo_for_up_loop  < o_block (o_modgen o_routprep v_depth)

extern objrout_sigBM crout_0UTjJP38fIh_02d0wLwrdAc_BM; //#5 !miniscan_node_conn#lazy-bool (o_conn  o_routprep v_depth v_expr o_from)

extern objrout_sigBM crout_17b3bhqLPeu_04FWlRjdMvD_BM; //#6 !miniscan_block°basiclo_labeled_block < o_block (o_routprep v_depth o_from)

extern objrout_sigBM crout_1kz7viwMzTp_6PgLhdZzMEy_BM; //#7 !miniscan_stmt°basiclo_outstmt < o_stmt (o_routprep v_depth o_from)

extern objrout_sigBM crout_55k0ot2Zxca_48c9pjWuNWQ_BM; //#8 !emit_statement°basiclo_extractjsonstmt <o_stmt(o_modgen o_routprep v_depth)

extern objrout_sigBM crout_5x0WWw3QRXe_8u5OLA7sKJG_BM; //#9 !miniscan_stmt°basiclo_extractjsonstmt < o_stmt (o_routprep v_depth o_from)

extern objrout_sigBM crout_73hC7TDRQc7_7AAWITxnirb_BM; //#10 !miniscan_json_extractor(v_extractor o_vihset v_depth)

extern objrout_sigBM crout_7IvnLvG7HVK_2qnOaIBtgVh_BM; //#11 !miniemit_node_conn#lazy-bool [v_init v_separ] (o_conn v_expr o_modgen o_routprep v_depth o_from)

extern objrout_sigBM crout_85xjvzYjcd6_9mNZNPF6i2J_BM; //#12 !miniscan_stmt°basiclo_countloop < o_stmt (o_routprep v_depth o_from)

extern objrout_sigBM crout_8NgOdlJACWN_8pbYZXkHpCj_BM; //#13 !emit_block°basiclo_for_down_loop  < o_block (o_modgen o_routprep v_depth)


// declare 124 constants
objectval_tyBM* constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[124+1];
const char* const constid_1lhXvXtIyPu_3nhuy4kN3wd_BM[124+1];


// define 14 routines


value_tyBM crout_08PMymoD6YJ_8rspWoCg4Xu_BM //#0
(struct stackframe_stBM* stkf, //
//!emit_statement°basiclo_outstmt < o_stmt (o_modgen o_routprep v_depth)
 // 4 arguments
 const value_tyBM arg0,  // o_stmt
 const value_tyBM arg1,  // o_modgen
 const value_tyBM arg2,  // o_routprep
 const value_tyBM arg3,  // v_depth
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
    // start of _08PMymoD6YJ_8rspWoCg4Xu
    struct frame_08PMymoD6YJ_8rspWoCg4Xu_BMst
    {
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
        /// 0 scalar values:
    } _;
    memset (&_, 0, sizeof(struct frame_08PMymoD6YJ_8rspWoCg4Xu_BMst));
    _.stkfram_head.htyp = typayl_StackFrame_BM;
    _.stkfram_head.hgc = 0;
    _.stkfram_head.rlen = 11;
    _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[1] /*|_08PMymoD6YJ_8rspWoCg4Xu*/;
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

startblock__2RXF4soNP1G_4lwKnhT9HXn:
    __attribute__((unused));
    {
        /* +block _2RXF4soNP1G_4lwKnhT9HXn */
        /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _7qIppSwFGGb_2UJt4H9gKgS
            /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ;


        /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV = //assign _8snpX2CnOTZ_3s6SIUk6miJ
            /*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[11] /*!out*/))));

//+ #2/16 of block _2RXF4soNP1G_4lwKnhT9HXn ::

        /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _4xM35iNaxz2_7KPR8ZEUBBR
            /*objnbcomps:*/ objnbcomps_BM ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);



        {
            // run _1nXXMqpXgYw_8ISpDakhyIi
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

        {
            // start cexpansion _8c3f40N9oIJ_2NpErXp5pgD - objstrbufferappendcstrpayl
            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "{ // start out "));
        } // end cexpansion _8c3f40N9oIJ_2NpErXp5pgD - objstrbufferappendcstrpayl


        {
            // start cexpansion _0EqgqGcTjMg_0BBJAIABGb2 - objstrbufferprintobject
            /*objstrbufferprintobject _0EqgqGcTjMg_0BBJAIABGb2:*/
            objectval_tyBM* obsbuf_0EqgqGcTjMg_0BBJAIABGb2 = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
            objectval_tyBM* ob_0EqgqGcTjMg_0BBJAIABGb2 = ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);
            if (objhasstrbufferpayl_BM(obsbuf_0EqgqGcTjMg_0BBJAIABGb2) && isobject_BM(ob_0EqgqGcTjMg_0BBJAIABGb2))
                objstrbufferappendcstrpayl_BM(obsbuf_0EqgqGcTjMg_0BBJAIABGb2, objectdbg_BM(ob_0EqgqGcTjMg_0BBJAIABGb2));
// end objstrbufferprintobject _0EqgqGcTjMg_0BBJAIABGb2
            ;
        } // end cexpansion _0EqgqGcTjMg_0BBJAIABGb2 - objstrbufferprintobject

//+ #6/16 of block _2RXF4soNP1G_4lwKnhT9HXn ::

        {
            // start cexpansion _3zo9bjbpfF9_3s0ClphWCMz - objstrbufferappendcstrpayl
            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " to "));
        } // end cexpansion _3zo9bjbpfF9_3s0ClphWCMz - objstrbufferappendcstrpayl


        {
            // start cexpansion _15Lqqaw1RwE_3WYODjv24bI - objstrbufferprintobject
            /*objstrbufferprintobject _15Lqqaw1RwE_3WYODjv24bI:*/
            objectval_tyBM* obsbuf_15Lqqaw1RwE_3WYODjv24bI = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
            objectval_tyBM* ob_15Lqqaw1RwE_3WYODjv24bI = ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV);
            if (objhasstrbufferpayl_BM(obsbuf_15Lqqaw1RwE_3WYODjv24bI) && isobject_BM(ob_15Lqqaw1RwE_3WYODjv24bI))
                objstrbufferappendcstrpayl_BM(obsbuf_15Lqqaw1RwE_3WYODjv24bI, objectdbg_BM(ob_15Lqqaw1RwE_3WYODjv24bI));
// end objstrbufferprintobject _15Lqqaw1RwE_3WYODjv24bI
            ;
        } // end cexpansion _15Lqqaw1RwE_3WYODjv24bI - objstrbufferprintobject

//+ #8/16 of block _2RXF4soNP1G_4lwKnhT9HXn ::

        {
            //for-up _3584humjRT7_5DRf4EbSEPp
            intptr_t cnt_3584humjRT7_5DRf4EbSEPp =  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k;
            for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;
                         /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_3584humjRT7_5DRf4EbSEPp;
                         /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++)
                {
// for-up _3584humjRT7_5DRf4EbSEPp #0 :
                    /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _1anzE3Jqqe6_6LhycgiaIC1
                        /*objgetcomp:*/objgetcomp_BM (( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));

// for-up _3584humjRT7_5DRf4EbSEPp #1 :

                    {
                        // run _2EhsAjpzrKw_7oYghtMEgPV
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
                    {
                        // start cexpansion _20LtVgnHAm6_4soICKMimrK - objstrbuffersetindentpayl
                        /*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                    } // end cexpansion _20LtVgnHAm6_4soICKMimrK - objstrbuffersetindentpayl

// for-up _3584humjRT7_5DRf4EbSEPp #3 :
                    {
                        // start cexpansion _0ca6ncURG9Y_2Q3UrCgnMPd - objstrbuffernewlinepayl
                        /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                    } // end cexpansion _0ca6ncURG9Y_2Q3UrCgnMPd - objstrbuffernewlinepayl

// for-up _3584humjRT7_5DRf4EbSEPp #4 :
                    if /*cond _4nOMpL7ofYO_7UI4gpk1cQz*/
                    /*when _4OeL63MMdi0_9vl6tIFdfP8:*/
                    (/*isstring:*/isstring_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe))   //body when _4OeL63MMdi0_9vl6tIFdfP8
                        {
                            {
                                // start cexpansion _5pqvkyAt4zS_4qUOQ9ii7vq - objstrbufferappendcstrpayl
                                /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out literal:*/ objstrbufferappendcstrpayl_BM ("));
                            } // end cexpansion _5pqvkyAt4zS_4qUOQ9ii7vq - objstrbufferappendcstrpayl
                            {
                                // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                   ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                            } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                            {
                                // start cexpansion _4IWQHWbVUsi_0KTMpVjEt4J - objstrbufferappendcstrpayl
                                /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", \""));
                            } // end cexpansion _4IWQHWbVUsi_0KTMpVjEt4J - objstrbufferappendcstrpayl
                            {
                                // start cexpansion _9lwtvhuODYD_7t02oTfRaaW - objstrbufferencvalcpayl
                                /*objstrbufferencvalcpayl:*/objstrbufferencodedcpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                                        bytstring_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), -1);
                            } // end cexpansion _9lwtvhuODYD_7t02oTfRaaW - objstrbufferencvalcpayl
                            {
                                // start cexpansion _1MTN8uOGzRk_1x5mYDtTjQS - objstrbufferappendcstrpayl
                                /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "\");"));
                            } // end cexpansion _1MTN8uOGzRk_1x5mYDtTjQS - objstrbufferappendcstrpayl

                        } //endwhen _4OeL63MMdi0_9vl6tIFdfP8
                    else if
                    /*when _9snNxHFHKej_9go5H2wttwP:*/
                    (/*isnode:*/isnode_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)))   //body when _9snNxHFHKej_9go5H2wttwP
                        {
                            /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81 = //assign _1jCOq9F7UCX_1hgQ2hHtGGN
                                /*nodeconn:*/nodeconn_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe);

                            {
                                // begin objswitch _88CClQZGP1N_57QoKCh6Ivj
//!objswitch! objswitch o_conn .. emit_statement°basiclo_outstmt .
                                objectval_tyBM* objswexp_88CClQZGP1N_57QoKCh6Ivj = ( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81);
                                switch (objecthash_BM (objswexp_88CClQZGP1N_57QoKCh6Ivj) % 64)
                                    {
                                    case 0:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*|utf8_enc*/)) goto whenobj88CClQZG__3UQkLJVILrN_5fQkMJuOnaO;
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[67] /*|less_indent*/)) goto whenobj88CClQZG__0kARe298u9e_67xDUpdBBUc;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 2:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[98] /*|nlsp*/)) goto whenobj88CClQZG__87vVePujNkG_0JOq1ftTQok;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 5:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[84] /*|c_enc*/)) goto whenobj88CClQZG__5ET8jC0ulFr_8HwUqVh9ORX;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 6:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[32] /*|newline*/)) goto whenobj88CClQZG__9E2lY6UWtZc_1zqNjPXxrB1;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 11:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[105] /*|object*/)) goto whenobj88CClQZG__3EoeNMRpnqL_7axOMOBffnQ;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 15:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[45] /*|html_enc*/)) goto whenobj88CClQZG__6aA6aV2YRMt_1NEYDaXpeC7;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 18:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[31] /*|half_id*/)) goto whenobj88CClQZG__9r5C2b73vHL_1dnbWS5hq8o;
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[55] /*|double_plain*/)) goto whenobj88CClQZG__7JbKDvDLX46_6AdksGCnIrD;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 19:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[20] /*|octa*/)) goto whenobj88CClQZG__1Okz8TmaK4w_1h2DwizxeUm;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 22:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[41] /*|space*/)) goto whenobj88CClQZG__114ixi5SECv_2Q1vNdDZoMs;
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[72] /*|json_indented*/)) goto whenobj88CClQZG__0z4pSxrVvjo_5sHi5Y1pLPY;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 30:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[8] /*|int*/)) goto whenobj88CClQZG__1x34ns9L1vc_0NkwFmpgSZo;
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[10] /*|prefixed_lines*/)) goto whenobj88CClQZG__6ynq7YzdPfg_1NP6KTYRGay;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 31:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[97] /*|value*/)) goto whenobj88CClQZG__1zJdg4pQzkf_3a4FsTJjy8n;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 34:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[109] /*|hexa*/)) goto whenobj88CClQZG__0BVlPuwRd7W_2uZdnPJU4lL;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 36:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[7] /*|more_indent*/)) goto whenobj88CClQZG__7ZmgWpB8hAR_9ZTbneZMSU1;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 41:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[38] /*|local_time*/)) goto whenobj88CClQZG__0ZOcGG4RgXt_4xRCcPIiCqy;
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[68] /*|literal_c_string*/)) goto whenobj88CClQZG__3s1tzo7j8uB_0du3hmckL9U;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 42:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[17] /*|name*/)) goto whenobj88CClQZG__5BIPiYugHNh_27cx9JETCA7;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 47:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[53] /*|json_compact*/)) goto whenobj88CClQZG__4fv6GoqMJ2j_5mL5sYAy1MA;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 51:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[33] /*|set_indent*/)) goto whenobj88CClQZG__7SJ5JXB8NNl_6AbPMP2VS1c;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 54:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[30] /*|double_float*/)) goto whenobj88CClQZG__4l6z1cQM0MF_99OZOIu8g9n;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;
                                    case 55:
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[59] /*|string*/)) goto whenobj88CClQZG__9d7rWinZqTW_3HJB0Tm1DtZ;
                                        if (objswexp_88CClQZGP1N_57QoKCh6Ivj ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[107] /*|id*/)) goto whenobj88CClQZG__0fRhe6eKSxc_717gH1gzxnY;
                                        goto defobj_88CClQZGP1N_57QoKCh6Ivj;

                                    default:
defobj_88CClQZGP1N_57QoKCh6Ivj:
                                        ;

// objswitch _88CClQZGP1N_57QoKCh6Ivj default#0 statement:
//failure _3hMno2PB1II_6IrKetMkipy
                                        PLACEDFAILURE_BM(__LINE__,
                                                         /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                           (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                            /*make_node 7 sons:*/
                                                                            ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[1] /*!_08PMymoD6YJ_8rspWoCg4Xu*/)),

                                                                            ( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),

                                                                            ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

// make_node arg #4
                                                                            (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

                                                                            ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                            ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),

                                                                            ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH)))),
                                                         /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[42] /*|_3hMno2PB1II_6IrKetMkipy*/)),
                                                         ((struct stackframe_stBM *) &_));

                                        break; // end objswitch _88CClQZGP1N_57QoKCh6Ivj default
// objswitch _88CClQZGP1N_57QoKCh6Ivj with 25 whens:

whenobj88CClQZG__0fRhe6eKSxc_717gH1gzxnY:; // when #0 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #0 statement:
                                        {
                                            // start cexpansion _0zKnZUvuFlU_5okP2gbCUIH - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out id:*/ char idbuf"));
                                        } // end cexpansion _0zKnZUvuFlU_5okP2gbCUIH - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #1 statement:
                                        {
                                            // start cexpansion _7O1a8HkPkwu_2DmU02OwFX3 - objstrbufferprintobjid
                                            /*objstrbufferprintobjid _7O1a8HkPkwu_2DmU02OwFX3:*/
                                            objectval_tyBM *obsbuf__7O1a8HkPkwu_2DmU02OwFX3 = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                                            objectval_tyBM *ob__7O1a8HkPkwu_2DmU02OwFX3 = ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);
                                            if (objhasstrbufferpayl_BM(obsbuf__7O1a8HkPkwu_2DmU02OwFX3) && isobject_BM(ob__7O1a8HkPkwu_2DmU02OwFX3))
                                                {
                                                    char idbuf__7O1a8HkPkwu_2DmU02OwFX3 [32];
                                                    memset (idbuf__7O1a8HkPkwu_2DmU02OwFX3, 0, sizeof(idbuf__7O1a8HkPkwu_2DmU02OwFX3));
                                                    idtocbuf32_BM (objid_BM (ob__7O1a8HkPkwu_2DmU02OwFX3), idbuf__7O1a8HkPkwu_2DmU02OwFX3);
                                                    objstrbufferappendcstrpayl_BM(obsbuf__7O1a8HkPkwu_2DmU02OwFX3, idbuf__7O1a8HkPkwu_2DmU02OwFX3);
                                                };
// end objstrbufferprintobjid _7O1a8HkPkwu_2DmU02OwFX3
                                            ;
                                        } // end cexpansion _7O1a8HkPkwu_2DmU02OwFX3 - objstrbufferprintobjid

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #2 statement:
                                        {
                                            // start cexpansion _5plJt7DVZpn_0n7pcOxdarb - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "_n"));
                                        } // end cexpansion _5plJt7DVZpn_0n7pcOxdarb - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #3 statement:
                                        {
                                            // start cexpansion _4h9yvmB4ieF_7JRJFLhvJG3 - objstrbufferprintint
                                            /*objstrbufferprintint:*/if (objhasstrbufferpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv))
                                                {
                                                    char buf_4h9yvmB4ieF_7JRJFLhvJG3[32];
                                                    memset (buf_4h9yvmB4ieF_7JRJFLhvJG3, 0, sizeof(buf_4h9yvmB4ieF_7JRJFLhvJG3));
                                                    snprintf(buf_4h9yvmB4ieF_7JRJFLhvJG3, sizeof(buf_4h9yvmB4ieF_7JRJFLhvJG3), "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
                                                    objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), buf_4h9yvmB4ieF_7JRJFLhvJG3);
                                                } //end objstrbufferprintint _4h9yvmB4ieF_7JRJFLhvJG3
                                            ;
                                        } // end cexpansion _4h9yvmB4ieF_7JRJFLhvJG3 - objstrbufferprintint

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #4 statement:
                                        {
                                            // start cexpansion _7vLMy8bPNE3_2qd7oURm8L2 - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "[32]={0};"));
                                        } // end cexpansion _7vLMy8bPNE3_2qd7oURm8L2 - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #5 statement:
                                        {
                                            // start cexpansion _6amT3YRmLU6_0TKFKJ5FILi - objstrbuffernewlinepayl
                                            /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                                        } // end cexpansion _6amT3YRmLU6_0TKFKJ5FILi - objstrbuffernewlinepayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #6 statement:
                                        {
                                            // start cexpansion _39vto2jXSds_1XdPjo0Amkd - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "idtocbuf32_BM (objid_BM("));
                                        } // end cexpansion _39vto2jXSds_1XdPjo0Amkd - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #7 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #8 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #9 statement:
                                        {
                                            // start cexpansion _0MonCV0Az8f_2rBRV72dJJz - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "), idbuf"));
                                        } // end cexpansion _0MonCV0Az8f_2rBRV72dJJz - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #10 statement:
                                        {
                                            // start cexpansion _5TRr3zS3FxR_8vswQ44kQaj - objstrbufferprintobjid
                                            /*objstrbufferprintobjid _5TRr3zS3FxR_8vswQ44kQaj:*/
                                            objectval_tyBM *obsbuf__5TRr3zS3FxR_8vswQ44kQaj = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                                            objectval_tyBM *ob__5TRr3zS3FxR_8vswQ44kQaj = ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);
                                            if (objhasstrbufferpayl_BM(obsbuf__5TRr3zS3FxR_8vswQ44kQaj) && isobject_BM(ob__5TRr3zS3FxR_8vswQ44kQaj))
                                                {
                                                    char idbuf__5TRr3zS3FxR_8vswQ44kQaj [32];
                                                    memset (idbuf__5TRr3zS3FxR_8vswQ44kQaj, 0, sizeof(idbuf__5TRr3zS3FxR_8vswQ44kQaj));
                                                    idtocbuf32_BM (objid_BM (ob__5TRr3zS3FxR_8vswQ44kQaj), idbuf__5TRr3zS3FxR_8vswQ44kQaj);
                                                    objstrbufferappendcstrpayl_BM(obsbuf__5TRr3zS3FxR_8vswQ44kQaj, idbuf__5TRr3zS3FxR_8vswQ44kQaj);
                                                };
// end objstrbufferprintobjid _5TRr3zS3FxR_8vswQ44kQaj
                                            ;
                                        } // end cexpansion _5TRr3zS3FxR_8vswQ44kQaj - objstrbufferprintobjid

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #11 statement:
                                        {
                                            // start cexpansion _9Dsiwu9HSkE_5pX9EvKmSxK - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "_n"));
                                        } // end cexpansion _9Dsiwu9HSkE_5pX9EvKmSxK - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #12 statement:
                                        {
                                            // start cexpansion _3wD29vlN70k_7xekhtrZYmH - objstrbufferprintint
                                            /*objstrbufferprintint:*/if (objhasstrbufferpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv))
                                                {
                                                    char buf_3wD29vlN70k_7xekhtrZYmH[32];
                                                    memset (buf_3wD29vlN70k_7xekhtrZYmH, 0, sizeof(buf_3wD29vlN70k_7xekhtrZYmH));
                                                    snprintf(buf_3wD29vlN70k_7xekhtrZYmH, sizeof(buf_3wD29vlN70k_7xekhtrZYmH), "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
                                                    objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), buf_3wD29vlN70k_7xekhtrZYmH);
                                                } //end objstrbufferprintint _3wD29vlN70k_7xekhtrZYmH
                                            ;
                                        } // end cexpansion _3wD29vlN70k_7xekhtrZYmH - objstrbufferprintint

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #13 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #14 statement:
                                        {
                                            // start cexpansion _9awyi1AxUBB_6rpdX1tcR4h - objstrbuffernewlinepayl
                                            /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                                        } // end cexpansion _9awyi1AxUBB_6rpdX1tcR4h - objstrbuffernewlinepayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #15 statement:
                                        {
                                            // start cexpansion _88sQAzm7Hff_3y6DR1EQBqT - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "objstrbufferappendcstrpayl_BM ("));
                                        } // end cexpansion _88sQAzm7Hff_3y6DR1EQBqT - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #16 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #17 statement:
                                        {
                                            // start cexpansion _6qgE1Z1OLuR_5RbYdfDOWgx - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", idbuf"));
                                        } // end cexpansion _6qgE1Z1OLuR_5RbYdfDOWgx - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #18 statement:
                                        {
                                            // start cexpansion _7PqxrFwaRKk_0McIex9mtVH - objstrbufferprintobjid
                                            /*objstrbufferprintobjid _7PqxrFwaRKk_0McIex9mtVH:*/
                                            objectval_tyBM *obsbuf__7PqxrFwaRKk_0McIex9mtVH = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                                            objectval_tyBM *ob__7PqxrFwaRKk_0McIex9mtVH = ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);
                                            if (objhasstrbufferpayl_BM(obsbuf__7PqxrFwaRKk_0McIex9mtVH) && isobject_BM(ob__7PqxrFwaRKk_0McIex9mtVH))
                                                {
                                                    char idbuf__7PqxrFwaRKk_0McIex9mtVH [32];
                                                    memset (idbuf__7PqxrFwaRKk_0McIex9mtVH, 0, sizeof(idbuf__7PqxrFwaRKk_0McIex9mtVH));
                                                    idtocbuf32_BM (objid_BM (ob__7PqxrFwaRKk_0McIex9mtVH), idbuf__7PqxrFwaRKk_0McIex9mtVH);
                                                    objstrbufferappendcstrpayl_BM(obsbuf__7PqxrFwaRKk_0McIex9mtVH, idbuf__7PqxrFwaRKk_0McIex9mtVH);
                                                };
// end objstrbufferprintobjid _7PqxrFwaRKk_0McIex9mtVH
                                            ;
                                        } // end cexpansion _7PqxrFwaRKk_0McIex9mtVH - objstrbufferprintobjid

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #19 statement:
                                        {
                                            // start cexpansion _8BHbQc7VIDi_6l9uywyF08i - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "_n"));
                                        } // end cexpansion _8BHbQc7VIDi_6l9uywyF08i - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #20 statement:
                                        {
                                            // start cexpansion _8HZgeYRcjX6_46BfRf4vkk4 - objstrbufferprintint
                                            /*objstrbufferprintint:*/if (objhasstrbufferpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv))
                                                {
                                                    char buf_8HZgeYRcjX6_46BfRf4vkk4[32];
                                                    memset (buf_8HZgeYRcjX6_46BfRf4vkk4, 0, sizeof(buf_8HZgeYRcjX6_46BfRf4vkk4));
                                                    snprintf(buf_8HZgeYRcjX6_46BfRf4vkk4, sizeof(buf_8HZgeYRcjX6_46BfRf4vkk4), "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
                                                    objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), buf_8HZgeYRcjX6_46BfRf4vkk4);
                                                } //end objstrbufferprintint _8HZgeYRcjX6_46BfRf4vkk4
                                            ;
                                        } // end cexpansion _8HZgeYRcjX6_46BfRf4vkk4 - objstrbufferprintint

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0fRhe6eKSxc_717gH1gzxnY #21 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _0fRhe6eKSxc_717gH1gzxnY #0 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__0kARe298u9e_67xDUpdBBUc:; // when #1 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0kARe298u9e_67xDUpdBBUc #0 statement:
                                        {
                                            // start cexpansion _3dGPVpTiurT_56WuV3rTn2V - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out less_indent:*/ objstrbufferlessindentpayl_BM ("));
                                        } // end cexpansion _3dGPVpTiurT_56WuV3rTn2V - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0kARe298u9e_67xDUpdBBUc #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0kARe298u9e_67xDUpdBBUc #2 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _0kARe298u9e_67xDUpdBBUc #1 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__0z4pSxrVvjo_5sHi5Y1pLPY:; // when #2 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0z4pSxrVvjo_5sHi5Y1pLPY #0 statement:
                                        {
                                            // start cexpansion _5EhDjG9YW4s_69w0DX91fbr - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out json_indented:*/ objstrbufferoutputjsonindentedvaluepayl_BM\n ("));
                                        } // end cexpansion _5EhDjG9YW4s_69w0DX91fbr - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0z4pSxrVvjo_5sHi5Y1pLPY #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
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
                                        {
                                            // start cexpansion _3jUYZjxeQEu_0VEUs1jwV0g - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", ("));
                                        } // end cexpansion _3jUYZjxeQEu_0VEUs1jwV0g - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0z4pSxrVvjo_5sHi5Y1pLPY #5 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0z4pSxrVvjo_5sHi5Y1pLPY #6 statement:
                                        {
                                            // start cexpansion _56nRoV0ayU1_2mHr757EZze - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "), "));
                                        } // end cexpansion _56nRoV0ayU1_2mHr757EZze - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0z4pSxrVvjo_5sHi5Y1pLPY #7 statement:
                                        if /*cond _4gQhnk40o3L_8bQpaOIGGME*/
                                        /*when _4HOkXA3muiK_7Huv8OmP5f8:*/
                                        ( /*v_expctx:*/_.v_96vo6uBKhke_6E1vyN3kIKD)   //body when _4HOkXA3muiK_7Huv8OmP5f8
                                            {
                                                {
                                                    // start cexpansion _7C0QRz3WhO0_6jEBkIOjtqM - objstrbufferappendcstrpayl
                                                    /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " ("));
                                                } // end cexpansion _7C0QRz3WhO0_6jEBkIOjtqM - objstrbufferappendcstrpayl
                                                {
                                                    // start cexpansion _6Dt0zHQ4v7x_5po6RQnOh2u - miniemit_expression
                                                    /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                            ( /*v_expctx:*/_.v_96vo6uBKhke_6E1vyN3kIKD), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                                } // end cexpansion _6Dt0zHQ4v7x_5po6RQnOh2u - miniemit_expression
                                                {
                                                    // start cexpansion _56nRoV0ayU1_2mHr757EZze - objstrbufferappendcstrpayl
                                                    /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "), "));
                                                } // end cexpansion _56nRoV0ayU1_2mHr757EZze - objstrbufferappendcstrpayl

                                            } //endwhen _4HOkXA3muiK_7Huv8OmP5f8
                                        else   /*cond else _4gQhnk40o3L_8bQpaOIGGME*/
                                            {
                                                {
                                                    // start cexpansion _6j2UwMz66NM_9H0arT8ZnoK - objstrbufferappendcstrpayl
                                                    /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*no outctx json*/NULL,"));
                                                } // end cexpansion _6j2UwMz66NM_9H0arT8ZnoK - objstrbufferappendcstrpayl
                                            } /*cond else _4gQhnk40o3L_8bQpaOIGGME*/
                                        /*endcond _4gQhnk40o3L_8bQpaOIGGME*/

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0z4pSxrVvjo_5sHi5Y1pLPY #8 statement:
                                        {
                                            // start cexpansion _8xKcG5ujBdQ_8JfhWpEJkqn - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " CURFRAME_BM);"));
                                        } // end cexpansion _8xKcG5ujBdQ_8JfhWpEJkqn - objstrbufferappendcstrpayl


                                        break; // end when _0z4pSxrVvjo_5sHi5Y1pLPY #2 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__0BVlPuwRd7W_2uZdnPJU4lL:; // when #3 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0BVlPuwRd7W_2uZdnPJU4lL #0 statement:
                                        {
                                            // start cexpansion _74YOQyHb4Nd_7FicacoZZan - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out hexa:*/ objstrbufferprintfpayl_BM ("));
                                        } // end cexpansion _74YOQyHb4Nd_7FicacoZZan - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0BVlPuwRd7W_2uZdnPJU4lL #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0BVlPuwRd7W_2uZdnPJU4lL #2 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0BVlPuwRd7W_2uZdnPJU4lL #3 statement:
                                        {
                                            // start cexpansion _0APoeium6EX_1BVXu0HmWIQ - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", \"%llx\", (long long) "));
                                        } // end cexpansion _0APoeium6EX_1BVXu0HmWIQ - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0BVlPuwRd7W_2uZdnPJU4lL #4 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0BVlPuwRd7W_2uZdnPJU4lL #5 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _0BVlPuwRd7W_2uZdnPJU4lL #3 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__0ZOcGG4RgXt_4xRCcPIiCqy:; // when #4 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0ZOcGG4RgXt_4xRCcPIiCqy #0 statement:
                                        {
                                            // start cexpansion _5ZRPfyn9MY8_2i1glfVxaCL - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out local_time:*/objstrbufferencodelocaltimepayl_BM(("));
                                        } // end cexpansion _5ZRPfyn9MY8_2i1glfVxaCL - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0ZOcGG4RgXt_4xRCcPIiCqy #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0ZOcGG4RgXt_4xRCcPIiCqy #2 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0ZOcGG4RgXt_4xRCcPIiCqy #3 statement:
                                        {
                                            // start cexpansion _8kTCqAbHYLm_4c21TsrClwG - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "), "));
                                        } // end cexpansion _8kTCqAbHYLm_4c21TsrClwG - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0ZOcGG4RgXt_4xRCcPIiCqy #4 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _0ZOcGG4RgXt_4xRCcPIiCqy #5 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _0ZOcGG4RgXt_4xRCcPIiCqy #4 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__114ixi5SECv_2Q1vNdDZoMs:; // when #5 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _114ixi5SECv_2Q1vNdDZoMs #0 statement:
                                        {
                                            // start cexpansion _0xL7VGIpR2r_1vJiJ88GK3r - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out space:*/ objstrbufferappendcstrpayl_BM ("));
                                        } // end cexpansion _0xL7VGIpR2r_1vJiJ88GK3r - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _114ixi5SECv_2Q1vNdDZoMs #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _114ixi5SECv_2Q1vNdDZoMs #2 statement:
                                        {
                                            // start cexpansion _7seosCpGZ8h_0P1JbrQ4QNK - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", \" \");"));
                                        } // end cexpansion _7seosCpGZ8h_0P1JbrQ4QNK - objstrbufferappendcstrpayl


                                        break; // end when _114ixi5SECv_2Q1vNdDZoMs #5 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__1x34ns9L1vc_0NkwFmpgSZo:; // when #6 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1x34ns9L1vc_0NkwFmpgSZo #0 statement:
                                        {
                                            // start cexpansion _9VCJIJGsAvX_1529ZKGJAO4 - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out int:*/ objstrbufferprintfpayl_BM ("));
                                        } // end cexpansion _9VCJIJGsAvX_1529ZKGJAO4 - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1x34ns9L1vc_0NkwFmpgSZo #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1x34ns9L1vc_0NkwFmpgSZo #2 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1x34ns9L1vc_0NkwFmpgSZo #3 statement:
                                        {
                                            // start cexpansion _8VsFpTwtckK_3bDjtkhIoU7 - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", \"%lld\", (long long) "));
                                        } // end cexpansion _8VsFpTwtckK_3bDjtkhIoU7 - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1x34ns9L1vc_0NkwFmpgSZo #4 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1x34ns9L1vc_0NkwFmpgSZo #5 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _1x34ns9L1vc_0NkwFmpgSZo #6 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__1zJdg4pQzkf_3a4FsTJjy8n:; // when #7 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1zJdg4pQzkf_3a4FsTJjy8n #0 statement:
                                        {
                                            // start cexpansion _81o0x9Oe3Ja_5HLdL6RBIpJ - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out value:*/ objstrbufferappendcstrpayl_BM ("));
                                        } // end cexpansion _81o0x9Oe3Ja_5HLdL6RBIpJ - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1zJdg4pQzkf_3a4FsTJjy8n #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1zJdg4pQzkf_3a4FsTJjy8n #2 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1zJdg4pQzkf_3a4FsTJjy8n #3 statement:
                                        {
                                            // start cexpansion _5reMpeYmKml_13RfKNLG91N - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", OUTSTRVALUE_BM ("));
                                        } // end cexpansion _5reMpeYmKml_13RfKNLG91N - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1zJdg4pQzkf_3a4FsTJjy8n #4 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1zJdg4pQzkf_3a4FsTJjy8n #5 statement:
                                        {
                                            // start cexpansion _2dvWAKMXgbg_7Elpq2AoBIo - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "));"));
                                        } // end cexpansion _2dvWAKMXgbg_7Elpq2AoBIo - objstrbufferappendcstrpayl


                                        break; // end when _1zJdg4pQzkf_3a4FsTJjy8n #7 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__1Okz8TmaK4w_1h2DwizxeUm:; // when #8 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1Okz8TmaK4w_1h2DwizxeUm #0 statement:
                                        {
                                            // start cexpansion _3XwncgqEs5D_9Ht74luwrmx - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out octa:*/ objstrbufferprintfpayl_BM ("));
                                        } // end cexpansion _3XwncgqEs5D_9Ht74luwrmx - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1Okz8TmaK4w_1h2DwizxeUm #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1Okz8TmaK4w_1h2DwizxeUm #2 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1Okz8TmaK4w_1h2DwizxeUm #3 statement:
                                        {
                                            // start cexpansion _0zmQelH00Up_6fR1xIGtzy0 - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", \"%llo\", (long long) "));
                                        } // end cexpansion _0zmQelH00Up_6fR1xIGtzy0 - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1Okz8TmaK4w_1h2DwizxeUm #4 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _1Okz8TmaK4w_1h2DwizxeUm #5 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _1Okz8TmaK4w_1h2DwizxeUm #8 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__3s1tzo7j8uB_0du3hmckL9U:; // when #9 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3s1tzo7j8uB_0du3hmckL9U #0 statement:
                                        {
                                            // start cexpansion _9vR2Fv4CLhC_12QZ3haFfpt - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out literal_c_string:*/ objstrbufferliteralcstringpayl_BM ("));
                                        } // end cexpansion _9vR2Fv4CLhC_12QZ3haFfpt - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3s1tzo7j8uB_0du3hmckL9U #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3s1tzo7j8uB_0du3hmckL9U #2 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3s1tzo7j8uB_0du3hmckL9U #3 statement:
                                        {
                                            // start cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));
                                        } // end cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3s1tzo7j8uB_0du3hmckL9U #4 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3s1tzo7j8uB_0du3hmckL9U #5 statement:
                                        {
                                            // start cexpansion _0xTYoGypzrv_9WaOYz6kK8x - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", -1"));
                                        } // end cexpansion _0xTYoGypzrv_9WaOYz6kK8x - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3s1tzo7j8uB_0du3hmckL9U #6 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _3s1tzo7j8uB_0du3hmckL9U #9 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__3EoeNMRpnqL_7axOMOBffnQ:; // when #10 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3EoeNMRpnqL_7axOMOBffnQ #0 statement:
                                        {
                                            // start cexpansion _2hyA1E4kwkD_4gm3vaEYWhp - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out object:*/ objstrbufferappendcstrpayl_BM ("));
                                        } // end cexpansion _2hyA1E4kwkD_4gm3vaEYWhp - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3EoeNMRpnqL_7axOMOBffnQ #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3EoeNMRpnqL_7axOMOBffnQ #2 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3EoeNMRpnqL_7axOMOBffnQ #3 statement:
                                        {
                                            // start cexpansion _6arx4mZK5LK_8usC9XqgLg5 - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", objectdbg_BM ("));
                                        } // end cexpansion _6arx4mZK5LK_8usC9XqgLg5 - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3EoeNMRpnqL_7axOMOBffnQ #4 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3EoeNMRpnqL_7axOMOBffnQ #5 statement:
                                        {
                                            // start cexpansion _9SmJNBQeMc1_43sJXOwBGe4 - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "));"));
                                        } // end cexpansion _9SmJNBQeMc1_43sJXOwBGe4 - objstrbufferappendcstrpayl


                                        break; // end when _3EoeNMRpnqL_7axOMOBffnQ #10 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__3UQkLJVILrN_5fQkMJuOnaO:; // when #11 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3UQkLJVILrN_5fQkMJuOnaO #0 statement:
                                        {
                                            // start cexpansion _4LgbVp40GWp_7QqWs5tViuk - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out utf8_enc:*/ objstrbufferencodedutf8payl_BM ("));
                                        } // end cexpansion _4LgbVp40GWp_7QqWs5tViuk - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3UQkLJVILrN_5fQkMJuOnaO #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3UQkLJVILrN_5fQkMJuOnaO #2 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3UQkLJVILrN_5fQkMJuOnaO #3 statement:
                                        {
                                            // start cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));
                                        } // end cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3UQkLJVILrN_5fQkMJuOnaO #4 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3UQkLJVILrN_5fQkMJuOnaO #5 statement:
                                        {
                                            // start cexpansion _0xTYoGypzrv_9WaOYz6kK8x - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", -1"));
                                        } // end cexpansion _0xTYoGypzrv_9WaOYz6kK8x - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _3UQkLJVILrN_5fQkMJuOnaO #6 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _3UQkLJVILrN_5fQkMJuOnaO #11 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__4fv6GoqMJ2j_5mL5sYAy1MA:; // when #12 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _4fv6GoqMJ2j_5mL5sYAy1MA #0 statement:
                                        {
                                            // start cexpansion _5jjZtFPH22M_4PdvtvwmHYi - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out json_compact:*/ objstrbufferoutputjsoncompactedvaluepayl_BM\n ("));
                                        } // end cexpansion _5jjZtFPH22M_4PdvtvwmHYi - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _4fv6GoqMJ2j_5mL5sYAy1MA #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
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
                                        {
                                            // start cexpansion _3jUYZjxeQEu_0VEUs1jwV0g - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", ("));
                                        } // end cexpansion _3jUYZjxeQEu_0VEUs1jwV0g - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _4fv6GoqMJ2j_5mL5sYAy1MA #5 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _4fv6GoqMJ2j_5mL5sYAy1MA #6 statement:
                                        {
                                            // start cexpansion _56nRoV0ayU1_2mHr757EZze - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "), "));
                                        } // end cexpansion _56nRoV0ayU1_2mHr757EZze - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _4fv6GoqMJ2j_5mL5sYAy1MA #7 statement:
                                        if /*cond _4gQhnk40o3L_8bQpaOIGGME*/
                                        /*when _4HOkXA3muiK_7Huv8OmP5f8:*/
                                        ( /*v_expctx:*/_.v_96vo6uBKhke_6E1vyN3kIKD)   //body when _4HOkXA3muiK_7Huv8OmP5f8
                                            {
                                                {
                                                    // start cexpansion _7C0QRz3WhO0_6jEBkIOjtqM - objstrbufferappendcstrpayl
                                                    /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " ("));
                                                } // end cexpansion _7C0QRz3WhO0_6jEBkIOjtqM - objstrbufferappendcstrpayl
                                                {
                                                    // start cexpansion _6Dt0zHQ4v7x_5po6RQnOh2u - miniemit_expression
                                                    /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                            ( /*v_expctx:*/_.v_96vo6uBKhke_6E1vyN3kIKD), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                                } // end cexpansion _6Dt0zHQ4v7x_5po6RQnOh2u - miniemit_expression
                                                {
                                                    // start cexpansion _56nRoV0ayU1_2mHr757EZze - objstrbufferappendcstrpayl
                                                    /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "), "));
                                                } // end cexpansion _56nRoV0ayU1_2mHr757EZze - objstrbufferappendcstrpayl

                                            } //endwhen _4HOkXA3muiK_7Huv8OmP5f8
                                        else   /*cond else _4gQhnk40o3L_8bQpaOIGGME*/
                                            {
                                                {
                                                    // start cexpansion _6j2UwMz66NM_9H0arT8ZnoK - objstrbufferappendcstrpayl
                                                    /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*no outctx json*/NULL,"));
                                                } // end cexpansion _6j2UwMz66NM_9H0arT8ZnoK - objstrbufferappendcstrpayl
                                            } /*cond else _4gQhnk40o3L_8bQpaOIGGME*/
                                        /*endcond _4gQhnk40o3L_8bQpaOIGGME*/

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _4fv6GoqMJ2j_5mL5sYAy1MA #8 statement:
                                        {
                                            // start cexpansion _8xKcG5ujBdQ_8JfhWpEJkqn - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " CURFRAME_BM);"));
                                        } // end cexpansion _8xKcG5ujBdQ_8JfhWpEJkqn - objstrbufferappendcstrpayl


                                        break; // end when _4fv6GoqMJ2j_5mL5sYAy1MA #12 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__4l6z1cQM0MF_99OZOIu8g9n:; // when #13 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _4l6z1cQM0MF_99OZOIu8g9n #0 statement:
                                        {
                                            // start cexpansion _3PJ0ZiTpF6M_4qFzUpO9Y8w - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out double_float:*/(void) objstrbufferoutdoublepayl_BM("));
                                        } // end cexpansion _3PJ0ZiTpF6M_4qFzUpO9Y8w - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _4l6z1cQM0MF_99OZOIu8g9n #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _4l6z1cQM0MF_99OZOIu8g9n #2 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _4l6z1cQM0MF_99OZOIu8g9n #3 statement:
                                        {
                                            // start cexpansion _3pcbCfZccyh_2fRLzjL6lQj - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));
                                        } // end cexpansion _3pcbCfZccyh_2fRLzjL6lQj - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _4l6z1cQM0MF_99OZOIu8g9n #4 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _4l6z1cQM0MF_99OZOIu8g9n #5 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _4l6z1cQM0MF_99OZOIu8g9n #13 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__5BIPiYugHNh_27cx9JETCA7:; // when #14 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _5BIPiYugHNh_27cx9JETCA7 #0 statement:
                                        {
                                            // start cexpansion _9d3lEURT0ug_7LCapWY9hBT - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out name:*/ objstrbufferappendcstrpayl_BM ("));
                                        } // end cexpansion _9d3lEURT0ug_7LCapWY9hBT - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _5BIPiYugHNh_27cx9JETCA7 #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _5BIPiYugHNh_27cx9JETCA7 #2 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _5BIPiYugHNh_27cx9JETCA7 #3 statement:
                                        {
                                            // start cexpansion _4d466jMJhQd_4FWABdphr9y - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", findobjectname_BM ("));
                                        } // end cexpansion _4d466jMJhQd_4FWABdphr9y - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _5BIPiYugHNh_27cx9JETCA7 #4 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _5BIPiYugHNh_27cx9JETCA7 #5 statement:
                                        {
                                            // start cexpansion _44lPnWohZT3_4XBFP6of9h7 - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "));"));
                                        } // end cexpansion _44lPnWohZT3_4XBFP6of9h7 - objstrbufferappendcstrpayl


                                        break; // end when _5BIPiYugHNh_27cx9JETCA7 #14 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__5ET8jC0ulFr_8HwUqVh9ORX:; // when #15 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _5ET8jC0ulFr_8HwUqVh9ORX #0 statement:
                                        {
                                            // start cexpansion _1ILRF99oJKp_9uh1JVhh4Ir - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out c_enc:*/ objstrbufferencodedcpayl_BM ("));
                                        } // end cexpansion _1ILRF99oJKp_9uh1JVhh4Ir - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _5ET8jC0ulFr_8HwUqVh9ORX #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _5ET8jC0ulFr_8HwUqVh9ORX #2 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _5ET8jC0ulFr_8HwUqVh9ORX #3 statement:
                                        {
                                            // start cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));
                                        } // end cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _5ET8jC0ulFr_8HwUqVh9ORX #4 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _5ET8jC0ulFr_8HwUqVh9ORX #5 statement:
                                        {
                                            // start cexpansion _0xTYoGypzrv_9WaOYz6kK8x - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", -1"));
                                        } // end cexpansion _0xTYoGypzrv_9WaOYz6kK8x - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _5ET8jC0ulFr_8HwUqVh9ORX #6 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _5ET8jC0ulFr_8HwUqVh9ORX #15 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__6aA6aV2YRMt_1NEYDaXpeC7:; // when #16 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _6aA6aV2YRMt_1NEYDaXpeC7 #0 statement:
                                        {
                                            // start cexpansion _3vqzjGxC2GM_2m5r0xbbxBS - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out html_enc:*/ objstrbufferencodedhtmlpayl_BM ("));
                                        } // end cexpansion _3vqzjGxC2GM_2m5r0xbbxBS - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _6aA6aV2YRMt_1NEYDaXpeC7 #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _6aA6aV2YRMt_1NEYDaXpeC7 #2 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _6aA6aV2YRMt_1NEYDaXpeC7 #3 statement:
                                        {
                                            // start cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));
                                        } // end cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _6aA6aV2YRMt_1NEYDaXpeC7 #4 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _6aA6aV2YRMt_1NEYDaXpeC7 #5 statement:
                                        {
                                            // start cexpansion _0xTYoGypzrv_9WaOYz6kK8x - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", -1"));
                                        } // end cexpansion _0xTYoGypzrv_9WaOYz6kK8x - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _6aA6aV2YRMt_1NEYDaXpeC7 #6 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _6aA6aV2YRMt_1NEYDaXpeC7 #16 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__6ynq7YzdPfg_1NP6KTYRGay:; // when #17 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #0 statement:
                                        {
                                            // start cexpansion _7tRdjZA1xGU_66rNHqMnoVh - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out prefixed_lines:*/objstrbufferoutputprefixlinespayl_BM ("));
                                        } // end cexpansion _7tRdjZA1xGU_66rNHqMnoVh - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #2 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #3 statement:
                                        {
                                            // start cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));
                                        } // end cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #4 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #5 statement:
                                        {
                                            // start cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));
                                        } // end cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #6 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _6P24oZ9lBmf_6uQcEYnne94
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 1));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #7 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _6ynq7YzdPfg_1NP6KTYRGay #8 statement:
                                        {
                                            // start cexpansion _9QlMhbIzTEX_20hleVtDJyt - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _9QlMhbIzTEX_20hleVtDJyt - objstrbufferappendcstrpayl


                                        break; // end when _6ynq7YzdPfg_1NP6KTYRGay #17 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__7JbKDvDLX46_6AdksGCnIrD:; // when #18 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _7JbKDvDLX46_6AdksGCnIrD #0 statement:
                                        {
                                            // start cexpansion _1hAp5OxsRGD_92R3L2BJtlG - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out double_plain:*/ objstrbufferprintfpayl_BM("));
                                        } // end cexpansion _1hAp5OxsRGD_92R3L2BJtlG - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _7JbKDvDLX46_6AdksGCnIrD #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _7JbKDvDLX46_6AdksGCnIrD #2 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _7JbKDvDLX46_6AdksGCnIrD #3 statement:
                                        {
                                            // start cexpansion _6e4LRuNu6ll_7OjJblfFR8d - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", \"%g\", "));
                                        } // end cexpansion _6e4LRuNu6ll_7OjJblfFR8d - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _7JbKDvDLX46_6AdksGCnIrD #4 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _7JbKDvDLX46_6AdksGCnIrD #5 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _7JbKDvDLX46_6AdksGCnIrD #18 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__7SJ5JXB8NNl_6AbPMP2VS1c:; // when #19 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _7SJ5JXB8NNl_6AbPMP2VS1c #0 statement:
                                        {
                                            // start cexpansion _0255NhyJ7Dq_2SDnpSnNtCD - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out set_indent:*/ objstrbuffersetindentpayl_BM ("));
                                        } // end cexpansion _0255NhyJ7Dq_2SDnpSnNtCD - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _7SJ5JXB8NNl_6AbPMP2VS1c #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _7SJ5JXB8NNl_6AbPMP2VS1c #2 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _7SJ5JXB8NNl_6AbPMP2VS1c #3 statement:
                                        {
                                            // start cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));
                                        } // end cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _7SJ5JXB8NNl_6AbPMP2VS1c #4 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _7SJ5JXB8NNl_6AbPMP2VS1c #5 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _7SJ5JXB8NNl_6AbPMP2VS1c #19 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__7ZmgWpB8hAR_9ZTbneZMSU1:; // when #20 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _7ZmgWpB8hAR_9ZTbneZMSU1 #0 statement:
                                        {
                                            // start cexpansion _2aoeNtEqRs3_3YZD8N5RQ3h - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out more_indent:*/ objstrbuffermoreindentpayl_BM ("));
                                        } // end cexpansion _2aoeNtEqRs3_3YZD8N5RQ3h - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _7ZmgWpB8hAR_9ZTbneZMSU1 #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _7ZmgWpB8hAR_9ZTbneZMSU1 #2 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _7ZmgWpB8hAR_9ZTbneZMSU1 #20 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__87vVePujNkG_0JOq1ftTQok:; // when #21 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _87vVePujNkG_0JOq1ftTQok #0 statement:
                                        {
                                            // start cexpansion _1zDV3OgdBWQ_7fM8urCKgoi - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out nlsp:*/ objstrbufferspaceornewlinepayl_BM ("));
                                        } // end cexpansion _1zDV3OgdBWQ_7fM8urCKgoi - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _87vVePujNkG_0JOq1ftTQok #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _87vVePujNkG_0JOq1ftTQok #2 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _87vVePujNkG_0JOq1ftTQok #21 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__9d7rWinZqTW_3HJB0Tm1DtZ:; // when #22 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9d7rWinZqTW_3HJB0Tm1DtZ #0 statement:
                                        {
                                            // start cexpansion _4iBLhIFQ0RT_6uR07KGUqiB - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out string:*/ objstrbufferappendcstrpayl_BM ("));
                                        } // end cexpansion _4iBLhIFQ0RT_6uR07KGUqiB - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9d7rWinZqTW_3HJB0Tm1DtZ #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9d7rWinZqTW_3HJB0Tm1DtZ #2 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9d7rWinZqTW_3HJB0Tm1DtZ #3 statement:
                                        {
                                            // start cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ", "));
                                        } // end cexpansion _6vPWb8w0spb_10ffMJKa3OH - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9d7rWinZqTW_3HJB0Tm1DtZ #4 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9d7rWinZqTW_3HJB0Tm1DtZ #5 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _9d7rWinZqTW_3HJB0Tm1DtZ #22 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__9r5C2b73vHL_1dnbWS5hq8o:; // when #23 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #0 statement:
                                        {
                                            // start out _5VxRkdpRDpG_4sfwsfc5lRZ to o_modgen
                                            /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "/*out_half_id:*/ char idbuf");
                                        } // end out _5VxRkdpRDpG_4sfwsfc5lRZ

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #1 statement:
                                        {
                                            // start cexpansion _7O1a8HkPkwu_2DmU02OwFX3 - objstrbufferprintobjid
                                            /*objstrbufferprintobjid _7O1a8HkPkwu_2DmU02OwFX3:*/
                                            objectval_tyBM *obsbuf__7O1a8HkPkwu_2DmU02OwFX3 = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                                            objectval_tyBM *ob__7O1a8HkPkwu_2DmU02OwFX3 = ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);
                                            if (objhasstrbufferpayl_BM(obsbuf__7O1a8HkPkwu_2DmU02OwFX3) && isobject_BM(ob__7O1a8HkPkwu_2DmU02OwFX3))
                                                {
                                                    char idbuf__7O1a8HkPkwu_2DmU02OwFX3 [32];
                                                    memset (idbuf__7O1a8HkPkwu_2DmU02OwFX3, 0, sizeof(idbuf__7O1a8HkPkwu_2DmU02OwFX3));
                                                    idtocbuf32_BM (objid_BM (ob__7O1a8HkPkwu_2DmU02OwFX3), idbuf__7O1a8HkPkwu_2DmU02OwFX3);
                                                    objstrbufferappendcstrpayl_BM(obsbuf__7O1a8HkPkwu_2DmU02OwFX3, idbuf__7O1a8HkPkwu_2DmU02OwFX3);
                                                };
// end objstrbufferprintobjid _7O1a8HkPkwu_2DmU02OwFX3
                                            ;
                                        } // end cexpansion _7O1a8HkPkwu_2DmU02OwFX3 - objstrbufferprintobjid

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #2 statement:
                                        {
                                            // start cexpansion _5plJt7DVZpn_0n7pcOxdarb - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "_n"));
                                        } // end cexpansion _5plJt7DVZpn_0n7pcOxdarb - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #3 statement:
                                        {
                                            // start cexpansion _4h9yvmB4ieF_7JRJFLhvJG3 - objstrbufferprintint
                                            /*objstrbufferprintint:*/if (objhasstrbufferpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv))
                                                {
                                                    char buf_4h9yvmB4ieF_7JRJFLhvJG3[32];
                                                    memset (buf_4h9yvmB4ieF_7JRJFLhvJG3, 0, sizeof(buf_4h9yvmB4ieF_7JRJFLhvJG3));
                                                    snprintf(buf_4h9yvmB4ieF_7JRJFLhvJG3, sizeof(buf_4h9yvmB4ieF_7JRJFLhvJG3), "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
                                                    objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), buf_4h9yvmB4ieF_7JRJFLhvJG3);
                                                } //end objstrbufferprintint _4h9yvmB4ieF_7JRJFLhvJG3
                                            ;
                                        } // end cexpansion _4h9yvmB4ieF_7JRJFLhvJG3 - objstrbufferprintint

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #4 statement:
                                        {
                                            // start cexpansion _7vLMy8bPNE3_2qd7oURm8L2 - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "[32]={0};"));
                                        } // end cexpansion _7vLMy8bPNE3_2qd7oURm8L2 - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #5 statement:
                                        {
                                            // start cexpansion _6amT3YRmLU6_0TKFKJ5FILi - objstrbuffernewlinepayl
                                            /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                                        } // end cexpansion _6amT3YRmLU6_0TKFKJ5FILi - objstrbuffernewlinepayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #6 statement:
                                        {
                                            // start cexpansion _39vto2jXSds_1XdPjo0Amkd - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "idtocbuf32_BM (objid_BM("));
                                        } // end cexpansion _39vto2jXSds_1XdPjo0Amkd - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #7 statement:
                                        /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY = //assign _5a1ZtPFXtZ4_2MFRQSKhbKt
                                            /*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0));

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #8 statement:
                                        {
                                            // start cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression
                                            /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                                    ( /*v_arg:*/_.v_4Q4WBLjAPTV_5WVLmhAvCJY), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _9P3jczeYo4m_5gpelMQi4Be - miniemit_expression

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #9 statement:
                                        {
                                            // start cexpansion _0MonCV0Az8f_2rBRV72dJJz - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "), idbuf"));
                                        } // end cexpansion _0MonCV0Az8f_2rBRV72dJJz - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #10 statement:
                                        {
                                            // start cexpansion _5TRr3zS3FxR_8vswQ44kQaj - objstrbufferprintobjid
                                            /*objstrbufferprintobjid _5TRr3zS3FxR_8vswQ44kQaj:*/
                                            objectval_tyBM *obsbuf__5TRr3zS3FxR_8vswQ44kQaj = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                                            objectval_tyBM *ob__5TRr3zS3FxR_8vswQ44kQaj = ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);
                                            if (objhasstrbufferpayl_BM(obsbuf__5TRr3zS3FxR_8vswQ44kQaj) && isobject_BM(ob__5TRr3zS3FxR_8vswQ44kQaj))
                                                {
                                                    char idbuf__5TRr3zS3FxR_8vswQ44kQaj [32];
                                                    memset (idbuf__5TRr3zS3FxR_8vswQ44kQaj, 0, sizeof(idbuf__5TRr3zS3FxR_8vswQ44kQaj));
                                                    idtocbuf32_BM (objid_BM (ob__5TRr3zS3FxR_8vswQ44kQaj), idbuf__5TRr3zS3FxR_8vswQ44kQaj);
                                                    objstrbufferappendcstrpayl_BM(obsbuf__5TRr3zS3FxR_8vswQ44kQaj, idbuf__5TRr3zS3FxR_8vswQ44kQaj);
                                                };
// end objstrbufferprintobjid _5TRr3zS3FxR_8vswQ44kQaj
                                            ;
                                        } // end cexpansion _5TRr3zS3FxR_8vswQ44kQaj - objstrbufferprintobjid

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #11 statement:
                                        {
                                            // start cexpansion _9Dsiwu9HSkE_5pX9EvKmSxK - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "_n"));
                                        } // end cexpansion _9Dsiwu9HSkE_5pX9EvKmSxK - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #12 statement:
                                        {
                                            // start cexpansion _3wD29vlN70k_7xekhtrZYmH - objstrbufferprintint
                                            /*objstrbufferprintint:*/if (objhasstrbufferpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv))
                                                {
                                                    char buf_3wD29vlN70k_7xekhtrZYmH[32];
                                                    memset (buf_3wD29vlN70k_7xekhtrZYmH, 0, sizeof(buf_3wD29vlN70k_7xekhtrZYmH));
                                                    snprintf(buf_3wD29vlN70k_7xekhtrZYmH, sizeof(buf_3wD29vlN70k_7xekhtrZYmH), "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
                                                    objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), buf_3wD29vlN70k_7xekhtrZYmH);
                                                } //end objstrbufferprintint _3wD29vlN70k_7xekhtrZYmH
                                            ;
                                        } // end cexpansion _3wD29vlN70k_7xekhtrZYmH - objstrbufferprintint

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #13 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #14 statement:
                                        {
                                            // start cexpansion _9awyi1AxUBB_6rpdX1tcR4h - objstrbuffernewlinepayl
                                            /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                                        } // end cexpansion _9awyi1AxUBB_6rpdX1tcR4h - objstrbuffernewlinepayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #15 statement:
                                        {
                                            // start out _9qmoxwsdBMF_1cBJhqeFE5Z to o_modgen
                                            /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "objstrbufferprintfpayl_BM (");
                                        } // end out _9qmoxwsdBMF_1cBJhqeFE5Z

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #16 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #17 statement:
                                        {
                                            // start out _8VPucIDSd8J_1G0LnGwTrSJ to o_modgen
                                            /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, ", \"%.12s\", idbuf");
                                        } // end out _8VPucIDSd8J_1G0LnGwTrSJ

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #18 statement:
                                        {
                                            // start cexpansion _5TRr3zS3FxR_8vswQ44kQaj - objstrbufferprintobjid
                                            /*objstrbufferprintobjid _5TRr3zS3FxR_8vswQ44kQaj:*/
                                            objectval_tyBM *obsbuf__5TRr3zS3FxR_8vswQ44kQaj = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                                            objectval_tyBM *ob__5TRr3zS3FxR_8vswQ44kQaj = ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);
                                            if (objhasstrbufferpayl_BM(obsbuf__5TRr3zS3FxR_8vswQ44kQaj) && isobject_BM(ob__5TRr3zS3FxR_8vswQ44kQaj))
                                                {
                                                    char idbuf__5TRr3zS3FxR_8vswQ44kQaj [32];
                                                    memset (idbuf__5TRr3zS3FxR_8vswQ44kQaj, 0, sizeof(idbuf__5TRr3zS3FxR_8vswQ44kQaj));
                                                    idtocbuf32_BM (objid_BM (ob__5TRr3zS3FxR_8vswQ44kQaj), idbuf__5TRr3zS3FxR_8vswQ44kQaj);
                                                    objstrbufferappendcstrpayl_BM(obsbuf__5TRr3zS3FxR_8vswQ44kQaj, idbuf__5TRr3zS3FxR_8vswQ44kQaj);
                                                };
// end objstrbufferprintobjid _5TRr3zS3FxR_8vswQ44kQaj
                                            ;
                                        } // end cexpansion _5TRr3zS3FxR_8vswQ44kQaj - objstrbufferprintobjid

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #19 statement:
                                        {
                                            // start cexpansion _9Dsiwu9HSkE_5pX9EvKmSxK - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "_n"));
                                        } // end cexpansion _9Dsiwu9HSkE_5pX9EvKmSxK - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #20 statement:
                                        {
                                            // start cexpansion _8HZgeYRcjX6_46BfRf4vkk4 - objstrbufferprintint
                                            /*objstrbufferprintint:*/if (objhasstrbufferpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv))
                                                {
                                                    char buf_8HZgeYRcjX6_46BfRf4vkk4[32];
                                                    memset (buf_8HZgeYRcjX6_46BfRf4vkk4, 0, sizeof(buf_8HZgeYRcjX6_46BfRf4vkk4));
                                                    snprintf(buf_8HZgeYRcjX6_46BfRf4vkk4, sizeof(buf_8HZgeYRcjX6_46BfRf4vkk4), "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
                                                    objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), buf_8HZgeYRcjX6_46BfRf4vkk4);
                                                } //end objstrbufferprintint _8HZgeYRcjX6_46BfRf4vkk4
                                            ;
                                        } // end cexpansion _8HZgeYRcjX6_46BfRf4vkk4 - objstrbufferprintint

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9r5C2b73vHL_1dnbWS5hq8o #21 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _9r5C2b73vHL_1dnbWS5hq8o #23 of objswitch _88CClQZGP1N_57QoKCh6Ivj

whenobj88CClQZG__9E2lY6UWtZc_1zqNjPXxrB1:; // when #24 of objswitch _88CClQZGP1N_57QoKCh6Ivj
// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9E2lY6UWtZc_1zqNjPXxrB1 #0 statement:
                                        {
                                            // start cexpansion _7dXnrwZwpMJ_5m6aSmqnq4b - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "/*out newline:*/ objstrbuffernewlinepayl_BM ("));
                                        } // end cexpansion _7dXnrwZwpMJ_5m6aSmqnq4b - objstrbufferappendcstrpayl

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9E2lY6UWtZc_1zqNjPXxrB1 #1 statement:
                                        {
                                            // start cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var
                                            /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                                               ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                        } // end cexpansion _7il9W2D3X8q_9zzCW4kDBba - miniemit_var

// objswitch _88CClQZGP1N_57QoKCh6Ivj when _9E2lY6UWtZc_1zqNjPXxrB1 #2 statement:
                                        {
                                            // start cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl
                                            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ");"));
                                        } // end cexpansion _0PBD9V6Bt7u_3TVTWHbNtLI - objstrbufferappendcstrpayl


                                        break; // end when _9E2lY6UWtZc_1zqNjPXxrB1 #24 of objswitch _88CClQZGP1N_57QoKCh6Ivj

                                    }
                            } // end objswitch _88CClQZGP1N_57QoKCh6Ivj

                        } //endwhen _9snNxHFHKej_9go5H2wttwP
                    else   /*cond else _4nOMpL7ofYO_7UI4gpk1cQz*/
                        {
//failure _3RUddTzPPB8_5j4EYXKOe2g
                            PLACEDFAILURE_BM(__LINE__,
                                             /*failreason:*/ (((value_tyBM) makenode6_BM
                                                               (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                       /*make_node 6 sons:*/
                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[1] /*!_08PMymoD6YJ_8rspWoCg4Xu*/)),

                                                                       ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

                                                                       (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                       ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                       ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),

                                                                       ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH)))),
                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[46] /*|_3RUddTzPPB8_5j4EYXKOe2g*/)),
                                             ((struct stackframe_stBM *) &_));
                        } /*cond else _4nOMpL7ofYO_7UI4gpk1cQz*/
                    /*endcond _4nOMpL7ofYO_7UI4gpk1cQz*/

                }
        } // end for-up _3584humjRT7_5DRf4EbSEPp

        {
            // start cexpansion _1PZEZj2fb0B_1pU56ft4Ca0 - objstrbuffersetindentpayl
            /*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
        } // end cexpansion _1PZEZj2fb0B_1pU56ft4Ca0 - objstrbuffersetindentpayl

//+ #10/16 of block _2RXF4soNP1G_4lwKnhT9HXn ::

        {
            // start cexpansion _0qwKnmv5GHv_81ky3FnB9La - objstrbuffernewlinepayl
            /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
        } // end cexpansion _0qwKnmv5GHv_81ky3FnB9La - objstrbuffernewlinepayl


        {
            // start cexpansion _4uMCgKrJauH_7kInVSNwYHm - objstrbufferappendcstrpayl
            /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "} // end out "));
        } // end cexpansion _4uMCgKrJauH_7kInVSNwYHm - objstrbufferappendcstrpayl

//+ #12/16 of block _2RXF4soNP1G_4lwKnhT9HXn ::

        {
            // start cexpansion _2Oq5DJsc44Q_2O4dNlPq85M - objstrbufferprintobject
            /*objstrbufferprintobject _2Oq5DJsc44Q_2O4dNlPq85M:*/
            objectval_tyBM* obsbuf_2Oq5DJsc44Q_2O4dNlPq85M = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
            objectval_tyBM* ob_2Oq5DJsc44Q_2O4dNlPq85M = ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);
            if (objhasstrbufferpayl_BM(obsbuf_2Oq5DJsc44Q_2O4dNlPq85M) && isobject_BM(ob_2Oq5DJsc44Q_2O4dNlPq85M))
                objstrbufferappendcstrpayl_BM(obsbuf_2Oq5DJsc44Q_2O4dNlPq85M, objectdbg_BM(ob_2Oq5DJsc44Q_2O4dNlPq85M));
// end objstrbufferprintobject _2Oq5DJsc44Q_2O4dNlPq85M
            ;
        } // end cexpansion _2Oq5DJsc44Q_2O4dNlPq85M - objstrbufferprintobject


        {
            // start cexpansion _5uqRz6AHI0d_5f4Tgcp2keq - objstrbuffernewlinepayl
            /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
        } // end cexpansion _5uqRz6AHI0d_5f4Tgcp2keq - objstrbuffernewlinepayl

//+ #14/16 of block _2RXF4soNP1G_4lwKnhT9HXn ::


        {
            // run _5EhMM2h3lya_7VX0vMYKsQt
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
endblock__2RXF4soNP1G_4lwKnhT9HXn:
        ;
    } /*-block _2RXF4soNP1G_4lwKnhT9HXn */

epilog_08PMymoD6YJ_8rspWoCg4Xu:
    __attribute__ ((unused)); // routine _08PMymoD6YJ_8rspWoCg4Xu epilogue:
    if (stkf) stkf->stkfram_callfun = NULL;
    return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _08PMymoD6YJ_8rspWoCg4Xu routine#0 _08PMymoD6YJ_8rspWoCg4Xu




value_tyBM crout_09YrB2RcKY0_8qXAVUhGxat_BM //#1
(struct stackframe_stBM* stkf, //
//!emit_label°basiclo_jsonex_label < o_label (o_modgen o_routprep depth)
 // 4 arguments
 const value_tyBM arg0,  // o_label
 const value_tyBM arg1,  // o_modgen
 const value_tyBM arg2,  // o_routprep
 const value_tyBM arg3,  // v_depth
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
    // start of _09YrB2RcKY0_8qXAVUhGxat
    struct frame_09YrB2RcKY0_8qXAVUhGxat_BMst
    {
        typedhead_tyBM stkfram_head;
        struct stackframe_stBM *stkfram_prev;
        objectval_tyBM *stkfram_descr;
        value_tyBM stkfram_callfun;
        int stkfram_state;
        int stkfram_extra;
        /// 8 local values:
        objectval_tyBM* o_0H23AXQRcQ6_5Vw1gVzCjxh; // o_label
        value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
        objectval_tyBM* o_2RUj1oyJ2rf_1ICZWr844Sv; // o_modgen
        value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
        value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
        objectval_tyBM* o_6RpSqxAOt2p_35laNqeU6KH; // o_routprep
        objectval_tyBM* o_89nz0KaXXZh_8eSgMmqnK37; // o_from
        value_tyBM v_9L1R3E9dI8L_6D8VI16BtDm; // v_extractor
        /// 3 local numbers:
        intptr_t n_2tUYLYs6CDE_5SlPd7sgYtY; // i_rank
        intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
        intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
        /// 0 scalar values:
    } _;
    memset (&_, 0, sizeof(struct frame_09YrB2RcKY0_8qXAVUhGxat_BMst));
    _.stkfram_head.htyp = typayl_StackFrame_BM;
    _.stkfram_head.hgc = 0;
    _.stkfram_head.rlen = 8;
    _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[2] /*|_09YrB2RcKY0_8qXAVUhGxat*/;
    ASSERT_BM (!stkf
               || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
               || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
    _.stkfram_prev = stkf;
    // locking 1:
    objectval_tyBM* locked_4L5rTNmbMca_9wVIMVwG8t7 = NULL; // for o_label
    // fetch 4 arguments:
    _.o_0H23AXQRcQ6_5Vw1gVzCjxh = objectcast_BM (arg0); // o_label
    _.o_2RUj1oyJ2rf_1ICZWr844Sv = objectcast_BM (arg1); // o_modgen
    _.o_6RpSqxAOt2p_35laNqeU6KH = objectcast_BM (arg2); // o_routprep
    _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
    // fetched 4 arguments.
    // no closed values in _09YrB2RcKY0_8qXAVUhGxat.
    const closure_tyBM* callclos_09YrB2RcKY0_8qXAVUhGxat __attribute__((unused)) =
        (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
        ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
    const unsigned nbclosed_09YrB2RcKY0_8qXAVUhGxat  __attribute__((unused)) = 0;
    // routine _09YrB2RcKY0_8qXAVUhGxat body:

startblock__2CbZoFeBvMY_65RpOWAwrai:
    __attribute__((unused));
    {
        /* +block _2CbZoFeBvMY_65RpOWAwrai */
        /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _7qIppSwFGGb_2UJt4H9gKgS
            /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ;



        {
            // run _7Ge2prH9fPN_4UjpoRCF5UK
            /*debug emit_label°basiclo_jsonex_label start: o_label o_modgen o_routprep depth*/
            DBGPRINTF_BM("emit_label°basiclo_jsonex_label start €%.9s: o_label=%s o_modgen=%s/L%u (lin:%d, col:%d, last'%s')\n... o_routprep=%s depth#%ld",
                         "_7Ge2prH9fPN_4UjpoRCF5UK",
                         objectdbg_BM( /*o_label:*/_.o_0H23AXQRcQ6_5Vw1gVzCjxh),
                         objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objstrbufferlinecountpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objstrbuffercolumnpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objstrbuffercurrentlastlinepayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objectdbg2_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                         (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;
        } // end run _7Ge2prH9fPN_4UjpoRCF5UK



        {
            // begin lockobj _4L5rTNmbMca_9wVIMVwG8t7
            objectval_tyBM* curlockedob_4L5rTNmbMca_9wVIMVwG8t7 = ( /*o_label:*/_.o_0H23AXQRcQ6_5Vw1gVzCjxh);
            if (objlock_BM (curlockedob_4L5rTNmbMca_9wVIMVwG8t7))
                {
                    locked_4L5rTNmbMca_9wVIMVwG8t7 = curlockedob_4L5rTNmbMca_9wVIMVwG8t7;

                    /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm = //assign _4IQB8qL1JJ1_3sKG8x9R2dI
                        /*objgetattr:*/objgetattr_BM(( /*o_label:*/_.o_0H23AXQRcQ6_5Vw1gVzCjxh),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[86] /*!extract_json*/)));

                    /*i_rank:*/_.n_2tUYLYs6CDE_5SlPd7sgYtY = //assign _4aM1U57Pxe2_2xzqbw3ZDGo
                        /* val_to_int */ getint_BM(/*objgetattr:*/objgetattr_BM(( /*o_label:*/_.o_0H23AXQRcQ6_5Vw1gVzCjxh),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[112] /*!rank*/)))) ;

//+ #2/6 of lockobj _4L5rTNmbMca_9wVIMVwG8t7 ::
                    /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37 = //assign _1KKDoXE4Ig7_1Oh5lfmrA5H
                        /*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_label:*/_.o_0H23AXQRcQ6_5Vw1gVzCjxh),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[23] /*!from*/))));


                    {
                        // run _6KsXNJ7Y8GV_5sEZhkPmwhm
                        /*emit_label°basiclo_jsonex_label o_label v_extractor o_from rank o_modgen depth*/
                        DBGPRINTF_BM("emit_label°basiclo_jsonex_label €%.9s o_label=%s v_extractor=%s o_from=%s rank#%ld  o_modgen=%s depth#%ld",
                                     "_6KsXNJ7Y8GV_5sEZhkPmwhm",
                                     objectdbg_BM( /*o_label:*/_.o_0H23AXQRcQ6_5Vw1gVzCjxh),
                                     OUTSTRVALUE_BM( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),
                                     objectdbg1_BM( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37),
                                     (long int) ( /*i_rank:*/_.n_2tUYLYs6CDE_5SlPd7sgYtY),
                                     objectdbg2_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                                     (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
                        ;
                    } // end run _6KsXNJ7Y8GV_5sEZhkPmwhm

//+ #4/6 of lockobj _4L5rTNmbMca_9wVIMVwG8t7 ::
                    {
                        // start out _3zlVg7hRDTb_3PT9yIoUL78 to o_modgen
                        /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, " labjsonx");
                        /*out_half_id:*/ char idbuf_3zlVg7hRDTb_3PT9yIoUL78_n1[32]= {0};
                        idtocbuf32_BM (objid_BM( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37), idbuf_3zlVg7hRDTb_3PT9yIoUL78_n1);
                        objstrbufferprintfpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "%.12s", idbuf_3zlVg7hRDTb_3PT9yIoUL78_n1);
                        /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "_rk");
                        /*out int:*/ objstrbufferprintfpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "%lld", (long long)  /*i_rank:*/_.n_2tUYLYs6CDE_5SlPd7sgYtY);
                        /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, " ");
                    } // end out _3zlVg7hRDTb_3PT9yIoUL78

                    /*return _9ujwvyJ1Xoi_9T5297PanEW:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned
                        /*o_label:*/_.o_0H23AXQRcQ6_5Vw1gVzCjxh;
                    goto epilog_09YrB2RcKY0_8qXAVUhGxat;

                    objunlock_BM (locked_4L5rTNmbMca_9wVIMVwG8t7), locked_4L5rTNmbMca_9wVIMVwG8t7 = NULL;
                }
        } // end objlock _4L5rTNmbMca_9wVIMVwG8t7
        /* !endingblock _2CbZoFeBvMY_65RpOWAwrai */
        goto endblock__2CbZoFeBvMY_65RpOWAwrai;
endblock__2CbZoFeBvMY_65RpOWAwrai:
        ;
    } /*-block _2CbZoFeBvMY_65RpOWAwrai */

epilog_09YrB2RcKY0_8qXAVUhGxat:
    __attribute__ ((unused)); // routine _09YrB2RcKY0_8qXAVUhGxat epilogue:
    // unlocking 1:
    if (locked_4L5rTNmbMca_9wVIMVwG8t7 != NULL)
        objunlock_BM(locked_4L5rTNmbMca_9wVIMVwG8t7), locked_4L5rTNmbMca_9wVIMVwG8t7 = NULL; // for o_label
    if (stkf) stkf->stkfram_callfun = NULL;
    return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _09YrB2RcKY0_8qXAVUhGxat routine#1 _09YrB2RcKY0_8qXAVUhGxat




value_tyBM crout_0eLqstoeREp_44oHD9QEdRx_BM //#2
(struct stackframe_stBM* stkf, //
//!emit_block°basiclo_labeled_block [v_with_label] < o_block (o_modgen o_routprep v_depth)
 // 4 arguments
 const value_tyBM arg0,  // o_block
 const value_tyBM arg1,  // o_modgen
 const value_tyBM arg2,  // o_routprep
 const value_tyBM arg3,  // v_depth
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
    // start of _0eLqstoeREp_44oHD9QEdRx
    struct frame_0eLqstoeREp_44oHD9QEdRx_BMst
    {
        typedhead_tyBM stkfram_head;
        struct stackframe_stBM *stkfram_prev;
        objectval_tyBM *stkfram_descr;
        value_tyBM stkfram_callfun;
        int stkfram_state;
        int stkfram_extra;
        /// 12 local values:
        value_tyBM v_0qTBOEAT5pa_2fz1SKfHrMV; // v_resemit
        objectval_tyBM* o_0H23AXQRcQ6_5Vw1gVzCjxh; // o_label
        value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
        value_tyBM v_14bZuNJeHA7_1reECNXu6Ly; // v_with_label
        value_tyBM v_167WczZjWtG_3FofhJxQWJi; // v_str
        objectval_tyBM* o_2RUj1oyJ2rf_1ICZWr844Sv; // o_modgen
        value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
        objectval_tyBM* o_41F1rKwGbaA_30OJWKsqNWy; // o_strbuf
        value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
        objectval_tyBM* o_5XGKMg1Kevs_6eAce4ib9XW; // o_block
        objectval_tyBM* o_6RpSqxAOt2p_35laNqeU6KH; // o_routprep
        objectval_tyBM* o_6Z4UU939WbU_8BK9xcKsXNb; // o_comp
        /// 4 local numbers:
        intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
        intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
        intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
        intptr_t n_8SJIvFqUkH2_0UJyIX6eA9v; // indent
        /// 0 scalar values:
    } _;
    memset (&_, 0, sizeof(struct frame_0eLqstoeREp_44oHD9QEdRx_BMst));
    _.stkfram_head.htyp = typayl_StackFrame_BM;
    _.stkfram_head.hgc = 0;
    _.stkfram_head.rlen = 12;
    _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[4] /*|_0eLqstoeREp_44oHD9QEdRx*/;
    ASSERT_BM (!stkf
               || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
               || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
    _.stkfram_prev = stkf;
    // fetch 4 arguments:
    _.o_5XGKMg1Kevs_6eAce4ib9XW = objectcast_BM (arg0); // o_block
    _.o_2RUj1oyJ2rf_1ICZWr844Sv = objectcast_BM (arg1); // o_modgen
    _.o_6RpSqxAOt2p_35laNqeU6KH = objectcast_BM (arg2); // o_routprep
    _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
    // fetched 4 arguments.
    {
        // fetch 1 closed values in _0eLqstoeREp_44oHD9QEdRx:
        const closure_tyBM* callclos_0eLqstoeREp_44oHD9QEdRx =
            (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
            ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
        const unsigned nbclosed_0eLqstoeREp_44oHD9QEdRx = closurewidth_BM ((const value_tyBM) callclos_0eLqstoeREp_44oHD9QEdRx);
        if (nbclosed_0eLqstoeREp_44oHD9QEdRx > 0)
            _.v_14bZuNJeHA7_1reECNXu6Ly = callclos_0eLqstoeREp_44oHD9QEdRx->nodt_sons[0]; // v_with_label
    } // fetched 1 closed values in _0eLqstoeREp_44oHD9QEdRx.
    // routine _0eLqstoeREp_44oHD9QEdRx body:

startblock__9AZmqeWa3GC_66poljZwrQQ:
    __attribute__((unused));
    {
        /* +block _9AZmqeWa3GC_66poljZwrQQ */
        /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _9UCpWRXllpw_4ClutKIdNOG
            /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ;


        /*o_label:*/_.o_0H23AXQRcQ6_5Vw1gVzCjxh = //assign _2W62CJuEWP3_9vAOkJtrogd
            /*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[47] /*!label*/))));

//+ #2/14 of block _9AZmqeWa3GC_66poljZwrQQ ::

        /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi = //assign _4q4hoTcrG24_6vFEpYFk9Of
            /*string_cast:*/((value_tyBM)stringcast_BM((value_tyBM)(/*objgetattr:*/objgetattr_BM(( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[120] /*!prefix_string*/))))));



        {
            // run _1XOzF1BKvQN_8JQAkUduDw5
            /*debug emit_block°basiclo_labeled_block start [v_with_label] o_block o_modgen o_routprep depth; o_label v_str*/
            DBGPRINTF_BM("emit_block°basiclo_labeled_block start €%.9s [v_with_label=%s] o_block=%s\n... o_modgen=%s/L%u (lin%d, col%d, cur'%s')\n"
                         "... o_routprep=%s depth#%ld; o_label=%s v_str=%s",
                         "_1XOzF1BKvQN_8JQAkUduDw5",
                         OUTSTRVALUE_BM( /*v_with_label:*/_.v_14bZuNJeHA7_1reECNXu6Ly),
                         objectdbg_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),
                         objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objstrbufferlinecountpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objstrbuffercolumnpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objstrbuffercurrentlastlinepayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objectdbg2_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                         (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
                         objectdbg3_BM( /*o_label:*/_.o_0H23AXQRcQ6_5Vw1gVzCjxh),
                         OUTSTRVALUE_BM( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi));
            ;
        } // end run _1XOzF1BKvQN_8JQAkUduDw5

//+ #4/14 of block _9AZmqeWa3GC_66poljZwrQQ ::

        if /*cond _8qahSw43Vxt_8QeDwy5u4JG*/
        /*when _9LjzYGO0lqo_0hHe8rvBFG6:*/
        (/*is_null:*/(( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)==NULL))   //body when _9LjzYGO0lqo_0hHe8rvBFG6
            {
                /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy = //assign _5IIDrsW5esr_7bafdigO23Q
                    /*makeobj:*/makeobj_BM();

                {
                    // run _7qtNAvo0cgG_5OywpaRn6op
                    /*objputstrbufferpayl:*/objputstrbufferpayl_BM (( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy),( 80));
                } // end run _7qtNAvo0cgG_5OywpaRn6op
                {
                    // start out _8sw1LMsJy9n_3hf1qUhpk21 to o_strbuf
                    /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "blk");
                    /*out_half_id:*/ char idbuf_8sw1LMsJy9n_3hf1qUhpk21_n1[32]= {0};
                    idtocbuf32_BM (objid_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW), idbuf_8sw1LMsJy9n_3hf1qUhpk21_n1);
                    objstrbufferprintfpayl_BM ( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy, "%.12s", idbuf_8sw1LMsJy9n_3hf1qUhpk21_n1);
                } // end out _8sw1LMsJy9n_3hf1qUhpk21
                /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi = //assign _6bzqosdGRc7_6QpiOXbOWQK
                    /*objstrbuffertostringvaluepayl:*/objstrbuffertostringvaluepayl_BM( /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy);
                /*o_strbuf:*/_.o_41F1rKwGbaA_30OJWKsqNWy = //assign _0b1veu9oFjr_4g2CPBntCyL
                    /*null_object:*/ ((objectval_tyBM*)NULL);

            } //endwhen _9LjzYGO0lqo_0hHe8rvBFG6
        /*endcond _8qahSw43Vxt_8QeDwy5u4JG*/


        /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _3wclejPqT2c_2h69aZswsNx
            /*objnbcomps:*/ objnbcomps_BM ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);

//+ #6/14 of block _9AZmqeWa3GC_66poljZwrQQ ::

        {
            // start out _2VlNHzD5hiQ_1OmrtI2vNad to o_modgen
            /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "{ //startblock ");
            /*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)));
            /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, " ln:");
            /*out int:*/ objstrbufferprintfpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "%lld", (long long)  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k);
            /*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
        } // end out _2VlNHzD5hiQ_1OmrtI2vNad


        if /*cond _5p4JK4RzSQD_2yuuiLQ1v76*/
        /*when _4uBq8sX37KX_5KytQMG14XX:*/
        (/*lazy and_then:*/ (intptr_t) (1 && ( /*v_with_label:*/_.v_14bZuNJeHA7_1reECNXu6Ly) && (/*objectisinstance:*/ objectisinstance_BM(( /*o_label:*/_.o_0H23AXQRcQ6_5Vw1gVzCjxh),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[83] /*!basiclo_label*/))))))   //body when _4uBq8sX37KX_5KytQMG14XX
            {
                {
                    // start out _0GWWZidF8Tk_9tyJ4UP2KBp to o_modgen
                    /*out prefixed_lines:*/objstrbufferoutputprefixlinespayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv,  "//labeled ", /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)));
                } // end out _0GWWZidF8Tk_9tyJ4UP2KBp
                /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _8nvDp50PLf1_6oN67iQ5q7i
                    (send3_BM (( /*o_label:*/_.o_0H23AXQRcQ6_5Vw1gVzCjxh), /*sel:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[101] /*!emit_label*/)), ((struct stackframe_stBM*)&_),
                               ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),  ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                               (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));
                {
                    // start out _1t0VAXJSuBK_2htneozTT3L to o_modgen
                    /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, ":");
                    /*out prefixed_lines:*/objstrbufferoutputprefixlinespayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv,  "//label ", /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)));
                } // end out _1t0VAXJSuBK_2htneozTT3L

            } //endwhen _4uBq8sX37KX_5KytQMG14XX
        else if
        /*when _5DTrJhTigFQ_5lg7yw2ahgD:*/
        ( /*v_with_label:*/_.v_14bZuNJeHA7_1reECNXu6Ly)   //body when _5DTrJhTigFQ_5lg7yw2ahgD
            {
//failure _5GBZ4ZkvOUP_4710156ZNKJ
                PLACEDFAILURE_BM(__LINE__,
                                 /*failreason:*/ (((value_tyBM) makenode6_BM
                                                   (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                           /*make_node 6 sons:*/
                                                           ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[47] /*!label*/)),

                                                           ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[4] /*!_0eLqstoeREp_44oHD9QEdRx*/)),

                                                           ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),

// make_node arg #4
                                                           ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),

                                                           ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                           (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[71] /*|_5GBZ4ZkvOUP_4710156ZNKJ*/)),
                                 ((struct stackframe_stBM *) &_));

            } //endwhen _5DTrJhTigFQ_5lg7yw2ahgD
        /*endcond _5p4JK4RzSQD_2yuuiLQ1v76*/

//+ #8/14 of block _9AZmqeWa3GC_66poljZwrQQ ::

        /*indent:*/_.n_8SJIvFqUkH2_0UJyIX6eA9v = //assign _5m1nYbWWvCl_5X0ErcGXY0U
            /*objstrbufferindentationpayl:*/ objstrbufferindentationpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);


        {
            //for-up _6lpXvoI7gMt_3VDber9zZ99
            intptr_t cnt_6lpXvoI7gMt_3VDber9zZ99 =  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k;
            for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;
                         /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_6lpXvoI7gMt_3VDber9zZ99;
                         /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++)
                {
// for-up _6lpXvoI7gMt_3VDber9zZ99 #0 :
                    /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _3y0G3XxTN5O_2keav30qYqL
                        /*objgetcomp:*/objgetcomp_BM (( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));

// for-up _6lpXvoI7gMt_3VDber9zZ99 #1 :

                    {
                        // run _8wXjADSLtUN_58c7MZ3YmTI
                        /*debug emit_block°basiclo_labeled_block o_block ii o_modgen o_routprep depth v_comp*/
                        DBGPRINTF_BM("emit_block°basiclo_labeled_block €%.9s o_block=%s ii#%ld o_modgen=%s o_routprep=%s depth#%ld v_comp=%s",
                                     "_8wXjADSLtUN_58c7MZ3YmTI",
                                     objectdbg_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),
                                     (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
                                     objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                                     objectdbg2_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                                     (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
                                     OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe));
                        ;
                    } // end run _8wXjADSLtUN_58c7MZ3YmTI

// for-up _6lpXvoI7gMt_3VDber9zZ99 #2 :
                    /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb = //assign _98zRO3obw4c_2IOEU4h2Ahs
                        /*val_to_object:*/objectcast_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe);

// for-up _6lpXvoI7gMt_3VDber9zZ99 #3 :
                    {
                        // start out _3nmr5PuHerz_5TVxaQSR9RZ to o_modgen
                        /*out set_indent:*/ objstrbuffersetindentpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, /*add_int:*/(( /*indent:*/_.n_8SJIvFqUkH2_0UJyIX6eA9v) + ( 1)));
                        /*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                    } // end out _3nmr5PuHerz_5TVxaQSR9RZ

// for-up _6lpXvoI7gMt_3VDber9zZ99 #4 :
                    if /*cond _0115eSyvePl_4dvw1VNcH9r*/
                    /*when _5nVUGqjqCqZ_8OOZcnSFErE:*/
                    (/*lazy and_then:*/ (intptr_t) (1 && (/*is_null:*/(( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb)==NULL)) && ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)))   //body when _5nVUGqjqCqZ_8OOZcnSFErE
                        {
//failure _9NMJjOqScc9_5rvKgT8VMEx
                            PLACEDFAILURE_BM(__LINE__,
                                             /*failreason:*/ (((value_tyBM) makenode6_BM
                                                               (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[85] /*!failure_non_object*/)),
                                                                       /*make_node 6 sons:*/
                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[4] /*!_0eLqstoeREp_44oHD9QEdRx*/)),

                                                                       ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

                                                                       (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                       ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),

                                                                       ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                       (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[121] /*|_9NMJjOqScc9_5rvKgT8VMEx*/)),
                                             ((struct stackframe_stBM *) &_));

                        } //endwhen _5nVUGqjqCqZ_8OOZcnSFErE
                    /*endcond _0115eSyvePl_4dvw1VNcH9r*/

// for-up _6lpXvoI7gMt_3VDber9zZ99 #5 :
                    if /*cond _91IJ64HPzlR_7nE0iicfjNR*/
                    /*when _71UVwlkWUpR_1Y8PclhkfLS:*/
                    (/*is_null:*/(( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb)==NULL))   //body when _71UVwlkWUpR_1Y8PclhkfLS
                        {

                            {
                                // run _8UTsnXu2eq0_1zenF0jBjti
                                /*no-op*/;
                            } // end run _8UTsnXu2eq0_1zenF0jBjti
                            /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _0EfDc5hscyJ_1jZ3CMHpFU2
                                (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[89] /*!is_null*/);

                        } //endwhen _71UVwlkWUpR_1Y8PclhkfLS
                    else if
                    /*when _2fNojFoFKvo_8htsgot0o0j:*/
                    (/*objectisinstance:*/ objectisinstance_BM(( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[49] /*!basiclo_block*/))))   //body when _2fNojFoFKvo_8htsgot0o0j
                        {
                            {
                                // start out _8JDrCZMRgRv_0wm7l71XJUj to o_modgen
                                /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "//+ #");
                                /*out int:*/ objstrbufferprintfpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
                                /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "/");
                                /*out int:*/ objstrbufferprintfpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "%lld", (long long)  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k);
                                /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, " of ");
                                /*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)));
                                /*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                            } // end out _8JDrCZMRgRv_0wm7l71XJUj
                            /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _3eBapbkAKKo_1kHUr39EhG1
                                (send4_BM (( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), /*sel:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[81] /*!emit_block*/)), ((struct stackframe_stBM*)&_),
                                           ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),  ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                                           (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1)))),
                                           ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW)));

                        } //endwhen _2fNojFoFKvo_8htsgot0o0j
                    else if
                    /*when _6xQK7wpB0jQ_7kNRVtPFXCy:*/
                    (/*objectisinstance:*/ objectisinstance_BM(( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[51] /*!basiclo_statement*/))))   //body when _6xQK7wpB0jQ_7kNRVtPFXCy
                        {
                            {
                                // start out _8JDrCZMRgRv_0wm7l71XJUj to o_modgen
                                /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "//+ #");
                                /*out int:*/ objstrbufferprintfpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
                                /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "/");
                                /*out int:*/ objstrbufferprintfpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "%lld", (long long)  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k);
                                /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, " of ");
                                /*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)));
                                /*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                            } // end out _8JDrCZMRgRv_0wm7l71XJUj
                            /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _9ASCHmQGqPV_2YyyB5sH3OJ
                                (send4_BM (( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), /*sel:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[22] /*!emit_statement*/)), ((struct stackframe_stBM*)&_),
                                           ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),  ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                                           (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1)))),
                                           ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW)));

                        } //endwhen _6xQK7wpB0jQ_7kNRVtPFXCy
                    /*endcond _91IJ64HPzlR_7nE0iicfjNR*/

// for-up _6lpXvoI7gMt_3VDber9zZ99 #6 :

                    {
                        // run _4TbYFB0gFhA_1hMmKsNFCsx
                        /*debug emit_block°basiclo_labeled_block v_resemit o_comp ii o_block o_modgen depth*/
                        DBGPRINTF_BM("debug emit_block°basiclo_labeled_block €%.9s v_resemit=%s o_comp=%s ii#%ld o_block=%s\n"
                                     " ... o_modgen=" FMTOBJSTRBUF_BM " depth#%ld",
                                     "_4TbYFB0gFhA_1hMmKsNFCsx",
                                     OUTSTRVALUE_BM( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV),
                                     objectdbg_BM( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),
                                     (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
                                     objectdbg1_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),
                                     OBJSTRBUFOUT_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                                     (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
                        ;
                    } // end run _4TbYFB0gFhA_1hMmKsNFCsx

// for-up _6lpXvoI7gMt_3VDber9zZ99 #7 :
                    if /*cond _1ugyDNU86KM_6aHu3t3oFaB*/
                    /*when _0T5VpU8gULE_7seqB0w6zfl:*/
                    (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL))   //body when _0T5VpU8gULE_7seqB0w6zfl
                        {
//failure _4dP92aF5D9l_4ROvrH6SnE3
                            PLACEDFAILURE_BM(__LINE__,
                                             /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                               (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                /*make_node 8 sons:*/
                                                                ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[76] /*!send*/)),

                                                                ( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),

                                                                (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),

                                                                ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),

                                                                ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                ( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)))),
                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[50] /*|_4dP92aF5D9l_4ROvrH6SnE3*/)),
                                             ((struct stackframe_stBM *) &_));

                        } //endwhen _0T5VpU8gULE_7seqB0w6zfl
                    /*endcond _1ugyDNU86KM_6aHu3t3oFaB*/

                }
        } // end for-up _6lpXvoI7gMt_3VDber9zZ99
//+ #10/14 of block _9AZmqeWa3GC_66poljZwrQQ ::

        {
            // start cexpansion _9D8OYPbINqa_07ejEVIeR5u - objstrbuffersetindentpayl
            /*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*indent:*/_.n_8SJIvFqUkH2_0UJyIX6eA9v));
        } // end cexpansion _9D8OYPbINqa_07ejEVIeR5u - objstrbuffersetindentpayl


        {
            // start out _73P3lwyVsIA_3AZX701UJcX to o_modgen
            /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "//endingblock ");
            /*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)));
            /*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
            /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, " goto endblock");
            /*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)));
            /*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
            /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "endblock");
            /*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)));
            /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, ":;");
            /*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
            /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "} //end block ");
            /*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi)));
            /*out newline:*/ objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
        } // end out _73P3lwyVsIA_3AZX701UJcX

//+ #12/14 of block _9AZmqeWa3GC_66poljZwrQQ ::


        {
            // run _1P68rY6TU7I_6ABhrccxshn
            /*debug emit_block°basiclo_labeled_block end o_block o_label v_str o_modgen depth*/
            DBGPRINTF_BM("emit_block°basiclo_labeled_block end €%.9s o_block=%s o_label=%s v_str=%s\n... o_modgen="  FMTOBJSTRBUF_BM
                         ", depth#%ld",
                         "_1P68rY6TU7I_6ABhrccxshn",
                         objectdbg_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),
                         objectdbg1_BM( /*o_label:*/_.o_0H23AXQRcQ6_5Vw1gVzCjxh),
                         OUTSTRVALUE_BM( /*v_str:*/_.v_167WczZjWtG_3FofhJxQWJi),
                         OBJ2STRBUFOUT_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;
        } // end run _1P68rY6TU7I_6ABhrccxshn


        /*return _1gpBOvVrDgp_2j6Mbq1LxrP:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned
            /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW;
        goto epilog_0eLqstoeREp_44oHD9QEdRx;

        /* !endingblock _9AZmqeWa3GC_66poljZwrQQ */
        goto endblock__9AZmqeWa3GC_66poljZwrQQ;
endblock__9AZmqeWa3GC_66poljZwrQQ:
        ;
    } /*-block _9AZmqeWa3GC_66poljZwrQQ */

epilog_0eLqstoeREp_44oHD9QEdRx:
    __attribute__ ((unused)); // routine _0eLqstoeREp_44oHD9QEdRx epilogue:
    if (stkf) stkf->stkfram_callfun = NULL;
    return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _0eLqstoeREp_44oHD9QEdRx routine#2 _0eLqstoeREp_44oHD9QEdRx




value_tyBM crout_0jZB3m3ntxR_7JPnMzyIoBg_BM //#3
(struct stackframe_stBM* stkf, //
//!extract_json#readmacro(v_node v_lineno v_colpos o_parser)
 // 4 arguments
 const value_tyBM arg0,  // v_node
 const value_tyBM arg1,  // v_lineno
 const value_tyBM arg2,  // v_colpos
 const value_tyBM arg3,  // o_parser
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
    // start of _0jZB3m3ntxR_7JPnMzyIoBg
    struct frame_0jZB3m3ntxR_7JPnMzyIoBg_BMst
    {
        typedhead_tyBM stkfram_head;
        struct stackframe_stBM *stkfram_prev;
        objectval_tyBM *stkfram_descr;
        value_tyBM stkfram_callfun;
        int stkfram_state;
        int stkfram_extra;
        /// 11 local values:
        value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
        objectval_tyBM* o_13K9OfeXRZR_84nyRTtoj81; // o_conn
        value_tyBM v_20uyDk84Vub_7xsAwkSm7lL; // v_lineno
        value_tyBM v_2BkOxf2KbS8_3bswrKbmgjy; // v_node
        objectval_tyBM* o_2FRfGeiauCO_9CdjKseaigc; // o_jsvar
        value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
        objectval_tyBM* o_4jyHvEiEzZ1_9ck99ShNTHx; // o_resobj
        objectval_tyBM* o_5fGGXIme43z_0mc4HIwzzMj; // o_parser
        objectval_tyBM* o_6Z4UU939WbU_8BK9xcKsXNb; // o_comp
        value_tyBM v_7llbD3YIz2G_3vDyN1QuPCy; // v_colpos
        value_tyBM v_9L1R3E9dI8L_6D8VI16BtDm; // v_extractor
        /// 5 local numbers:
        intptr_t n_2sygPI8PHgL_4RgFW0PkZbd; // i_colpos
        intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
        intptr_t n_4Dke6KoVx5r_1CoVhK8mVmc; // i_start
        intptr_t n_6x2LYnlYgQG_6FXtmtwODgo; // i_lineno
        intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
        /// 0 scalar values:
    } _;
    memset (&_, 0, sizeof(struct frame_0jZB3m3ntxR_7JPnMzyIoBg_BMst));
    _.stkfram_head.htyp = typayl_StackFrame_BM;
    _.stkfram_head.hgc = 0;
    _.stkfram_head.rlen = 11;
    _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[6] /*|_0jZB3m3ntxR_7JPnMzyIoBg*/;
    ASSERT_BM (!stkf
               || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
               || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
    _.stkfram_prev = stkf;
    // locking 1:
    objectval_tyBM* locked_0kZ9svhUUIT_2zI3SPQhfGs = NULL; // for o_resobj
    // fetch 4 arguments:
    _.v_2BkOxf2KbS8_3bswrKbmgjy = arg0; // v_node
    _.v_20uyDk84Vub_7xsAwkSm7lL = arg1; // v_lineno
    _.v_7llbD3YIz2G_3vDyN1QuPCy = arg2; // v_colpos
    _.o_5fGGXIme43z_0mc4HIwzzMj = objectcast_BM (arg3); // o_parser
    // fetched 4 arguments.
    // no closed values in _0jZB3m3ntxR_7JPnMzyIoBg.
    const closure_tyBM* callclos_0jZB3m3ntxR_7JPnMzyIoBg __attribute__((unused)) =
        (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
        ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
    const unsigned nbclosed_0jZB3m3ntxR_7JPnMzyIoBg  __attribute__((unused)) = 0;
    // routine _0jZB3m3ntxR_7JPnMzyIoBg body:

startblock__1L7vF06qZON_9wSPaww8E2X:
    __attribute__((unused));
    {
        /* +block _1L7vF06qZON_9wSPaww8E2X */
        /*i_lineno:*/_.n_6x2LYnlYgQG_6FXtmtwODgo = //assign _67dfantiJB6_0raShkMRDHL
            /* val_to_int */ getint_BM( /*v_lineno:*/_.v_20uyDk84Vub_7xsAwkSm7lL) ;


        /*i_colpos:*/_.n_2sygPI8PHgL_4RgFW0PkZbd = //assign _7pGANo80KI0_7YOZDlNgX2W
            /* val_to_int */ getint_BM( /*v_colpos:*/_.v_7llbD3YIz2G_3vDyN1QuPCy) ;

//+ #2/16 of block _1L7vF06qZON_9wSPaww8E2X ::


        {
            // run _25GOMx4RRU0_6pMpSEMw1gN
            /*debug extract_json#readmacro start v_node lineno colpos o_parser*/
            DBGPRINTF_BM("extract_json#readmacro start €%.9s v_node=%s lineno#%ld colpos#%ld o_parser=%s",
                         "_25GOMx4RRU0_6pMpSEMw1gN",
                         OUTSTRVALUE_BM( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),
                         (long int) ( /*i_lineno:*/_.n_6x2LYnlYgQG_6FXtmtwODgo),
                         (long int) ( /*i_colpos:*/_.n_2sygPI8PHgL_4RgFW0PkZbd),
                         objectdbg_BM( /*o_parser:*/_.o_5fGGXIme43z_0mc4HIwzzMj));;
        } // end run _25GOMx4RRU0_6pMpSEMw1gN


        /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _4Cj2wfMNdSb_4STaolxG6qN
            /*nodewidth:*/(intptr_t)nodewidth_BM( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy);

//+ #4/16 of block _1L7vF06qZON_9wSPaww8E2X ::

        /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _210mSO8s3LZ_9iKjW7eaG6Q
            /*nodenthson:*/nodenthson_BM(( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));


        /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81 = //assign _7wn1KeIUJpE_8XLnDlRd9Wn
            /*nodeconn:*/nodeconn_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe);

//+ #6/16 of block _1L7vF06qZON_9wSPaww8E2X ::

        if /*cond _9wmUQdGs520_80QjLaRO5pa*/
        /*when _1j5eDZEaK15_1f7jqPaTIVw:*/
        (/*equal_object:*/(( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81) == ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[5] /*!in*/))))   //body when _1j5eDZEaK15_1f7jqPaTIVw
            {
                /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx = //assign _0T7bvmg9y4B_6u9BnDCdOJK
                    /*val_to_object:*/objectcast_BM(/*nodenthson:*/nodenthson_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),( 0)));
                {
                    // start cexpansion _7lC3JY25pke_03Q6D8X9cOR - objresetattrs
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


        /*o_jsvar:*/_.o_2FRfGeiauCO_9CdjKseaigc = //assign _33jgv55H3Ve_5YocCFDKVuW
            /*val_to_object:*/objectcast_BM(/*nodenthson:*/nodenthson_BM(( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)));

//+ #8/16 of block _1L7vF06qZON_9wSPaww8E2X ::

        if /*cond _8Bem5jzwjXO_3xhe52uV3WF*/
        /*when _4opSMt5aQPn_1HPsSA45WVu:*/
        (/*is_null:*/(( /*o_jsvar:*/_.o_2FRfGeiauCO_9CdjKseaigc)==NULL))   //body when _4opSMt5aQPn_1HPsSA45WVu
            {

                {
                    // run _0lLwyPX6IIy_6lKA4ELeuej
                    /*syntax-error no o_jsvar*/
                    objparserrorprintf_BM( /*o_parser:*/_.o_5fGGXIme43z_0mc4HIwzzMj, CURFRAME_BM,
                                                        /*i_lineno:*/_.n_6x2LYnlYgQG_6FXtmtwODgo,  /*i_colpos:*/_.n_2sygPI8PHgL_4RgFW0PkZbd,
                                                        "missing o_jsvar in ^extract_json({*in(...)] o_jsvar v_extractor stmts...) // €%s",
                                                        "_0lLwyPX6IIy_6lKA4ELeuej");
                    ;
                } // end run _0lLwyPX6IIy_6lKA4ELeuej

            } //endwhen _4opSMt5aQPn_1HPsSA45WVu
        /*endcond _8Bem5jzwjXO_3xhe52uV3WF*/


        /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _7fh7LUbhBaX_8aeMudPobHE
            /*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1));

//+ #10/16 of block _1L7vF06qZON_9wSPaww8E2X ::

        /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm = //assign _0rvyHC1WSMI_8EmUZPLbC9h
            /*nodenthson:*/nodenthson_BM(( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));


        /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _6p0g8pmTxXT_9epMMKC7fDB
            /*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1));

//+ #12/16 of block _1L7vF06qZON_9wSPaww8E2X ::

        /*i_start:*/_.n_4Dke6KoVx5r_1CoVhK8mVmc = //assign _0dwlk6o42FG_2A4WwEF3ISA
            /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B;


        if /*cond _3pUJ8P4c1Ju_9HzgHfD0sh1*/
        /*when _8FXWOPy2K9D_921lrdYBmtS:*/
        (/*not:*/ (! (/*isnode:*/isnode_BM(( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm)))))   //body when _8FXWOPy2K9D_921lrdYBmtS
            {

                {
                    // run _9TWRUevaQSK_0Sf5a7Qwva0
                    /*syntax error bad v_extractor*/
                    objparserrorprintf_BM( /*o_parser:*/_.o_5fGGXIme43z_0mc4HIwzzMj, CURFRAME_BM,
                                                        /*i_lineno:*/_.n_6x2LYnlYgQG_6FXtmtwODgo,  /*i_colpos:*/_.n_2sygPI8PHgL_4RgFW0PkZbd,
                                                        "bad non-node extractor in ^extract_json(o_jsvar=%s v_extractor ...) €%.9s",
                                                        objectdbg_BM( /*o_jsvar:*/_.o_2FRfGeiauCO_9CdjKseaigc),
                                                        "_9TWRUevaQSK_0Sf5a7Qwva0");
                    ;
                } // end run _9TWRUevaQSK_0Sf5a7Qwva0

            } //endwhen _8FXWOPy2K9D_921lrdYBmtS
        /*endcond _3pUJ8P4c1Ju_9HzgHfD0sh1*/

//+ #14/16 of block _1L7vF06qZON_9wSPaww8E2X ::

        if /*cond _5fvHoN4utBt_83Mn8QcNqPD*/
        /*when _56xGWj8ZP8U_73U7RwAnrIR:*/
        (/*is_null:*/(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx)==NULL))   //body when _56xGWj8ZP8U_73U7RwAnrIR
            {
                /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx = //assign _7FTMhAwLNH1_9Pvu14cy4oO
                    /*makeobj:*/makeobj_BM();
                {
                    // start cexpansion _3HdFVOIjHjP_3jpt2QY0ujo - objputglobalspace
                    /*objputglobalspace:*/objputspacenum_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx), GlobalSp_BM);;
                } // end cexpansion _3HdFVOIjHjP_3jpt2QY0ujo - objputglobalspace

            } //endwhen _56xGWj8ZP8U_73U7RwAnrIR
        /*endcond _5fvHoN4utBt_83Mn8QcNqPD*/



        {
            // begin lockobj _0kZ9svhUUIT_2zI3SPQhfGs
            objectval_tyBM* curlockedob_0kZ9svhUUIT_2zI3SPQhfGs = ( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx);
            if (objlock_BM (curlockedob_0kZ9svhUUIT_2zI3SPQhfGs))
                {
                    locked_0kZ9svhUUIT_2zI3SPQhfGs = curlockedob_0kZ9svhUUIT_2zI3SPQhfGs;


                    {
                        // run _7Gcop8vDYZT_7m7qR3MuU0P
                        /*debug extract_json#readmacro o_resobj lineno colpos o_jsvar v_extractor o_parser*/
                        DBGPRINTF_BM("extract_json#readmacro €%.9s o_resobj=%s lineno#%ld colpos#%ld o_jsvar=%s v_extractor=%s o_parser=%s",
                                     "_7Gcop8vDYZT_7m7qR3MuU0P",
                                     objectdbg_BM( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),
                                     (long int) ( /*i_lineno:*/_.n_6x2LYnlYgQG_6FXtmtwODgo),
                                     (long int) ( /*i_colpos:*/_.n_2sygPI8PHgL_4RgFW0PkZbd),
                                     objectdbg1_BM( /*o_jsvar:*/_.o_2FRfGeiauCO_9CdjKseaigc),
                                     OUTSTRVALUE_BM( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),
                                     objectdbg2_BM( /*o_parser:*/_.o_5fGGXIme43z_0mc4HIwzzMj));;
                    } // end run _7Gcop8vDYZT_7m7qR3MuU0P

                    if /*cond _0irx8Y0FXiq_6gtFr6NUf2Q*/
                    /*when _76fkBgDaGiN_3W7oI0G3NPL:*/
                    (/*not:*/ (! (/*objectisinstance:*/ objectisinstance_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[122] /*!basiclo_extractjsonstmt*/))))))   //body when _76fkBgDaGiN_3W7oI0G3NPL
                        {
                            {
                                // start cexpansion _8f6pQKcFj7A_0usrGCfaW2c - objputclass
                                /*objputclass:*/objputclass_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[122] /*!basiclo_extractjsonstmt*/)));
                            } // end cexpansion _8f6pQKcFj7A_0usrGCfaW2c - objputclass

                        } //endwhen _76fkBgDaGiN_3W7oI0G3NPL
                    /*endcond _0irx8Y0FXiq_6gtFr6NUf2Q*/

//+ #2/7 of lockobj _0kZ9svhUUIT_2zI3SPQhfGs ::
                    {
                        // start cexpansion _4jNX6WSUQdx_8QHojeACOOP - objputattr
                        /*objputattr:*/objputattr_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[99] /*!json_object*/)),( /*o_jsvar:*/_.o_2FRfGeiauCO_9CdjKseaigc));
                    } // end cexpansion _4jNX6WSUQdx_8QHojeACOOP - objputattr

                    {
                        // start cexpansion _1fUZ2OOn262_3etmkiSA1dd - objputattr
                        /*objputattr:*/objputattr_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[86] /*!extract_json*/)),( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm));
                    } // end cexpansion _1fUZ2OOn262_3etmkiSA1dd - objputattr

//+ #4/7 of lockobj _0kZ9svhUUIT_2zI3SPQhfGs ::
                    {
                        //for-up _6wQQGXqOyor_2xaWNeX1Mf3
                        intptr_t cnt_6wQQGXqOyor_2xaWNeX1Mf3 = /*substract_int:*/(( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) - ( /*i_start:*/_.n_4Dke6KoVx5r_1CoVhK8mVmc));
                        for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;
                                     /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_6wQQGXqOyor_2xaWNeX1Mf3;
                                     /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++)
                            {
// for-up _6wQQGXqOyor_2xaWNeX1Mf3 #0 :
                                /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb = //assign _0dMaVldspfJ_8enHfCHKmXn
                                    /*val_to_object:*/objectcast_BM(/*nodenthson:*/nodenthson_BM(( /*v_node:*/_.v_2BkOxf2KbS8_3bswrKbmgjy),(/*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( /*i_start:*/_.n_4Dke6KoVx5r_1CoVhK8mVmc)))));

// for-up _6wQQGXqOyor_2xaWNeX1Mf3 #1 :

                                {
                                    // run _4fn815fHAPm_1Ka209zgjlp
                                    /*debug extract_json#readmacro ii o_comp o_resobj lineno*/
                                    DBGPRINTF_BM("debug extract_json#readmacro €%.9s ii#%ld o_comp=%s o_resobj=%s lineno#%ld",
                                                 "_4fn815fHAPm_1Ka209zgjlp",
                                                 (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
                                                 objectdbg_BM( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),
                                                 objectdbg1_BM( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),
                                                 (long int) ( /*i_lineno:*/_.n_6x2LYnlYgQG_6FXtmtwODgo));;
                                } // end run _4fn815fHAPm_1Ka209zgjlp

// for-up _6wQQGXqOyor_2xaWNeX1Mf3 #2 :
                                {
                                    // start cexpansion _1Od4sbNNevE_7JfpcgG2EKD - objappendcomp
                                    /*objappendcomp:*/objappendcomp_BM(( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb));
                                } // end cexpansion _1Od4sbNNevE_7JfpcgG2EKD - objappendcomp

                            }
                    } // end for-up _6wQQGXqOyor_2xaWNeX1Mf3


                    {
                        // run _2A3Kvjf1DsV_6MGNtS7eKfj
                        /*debug extract_json#readmacro end o_resobj lineno*/
                        DBGPRINTF_BM("debug extract_json#readmacro €%.9s end o_resobj=%s lineno#%ld",
                                     "_2A3Kvjf1DsV_6MGNtS7eKfj",
                                     objectdbg1_BM( /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx),
                                     (long int) ( /*i_lineno:*/_.n_6x2LYnlYgQG_6FXtmtwODgo));;
                    } // end run _2A3Kvjf1DsV_6MGNtS7eKfj

                    /*return _172YnPPugV9_4WAq0jtEnSx:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned
                        /*o_resobj:*/_.o_4jyHvEiEzZ1_9ck99ShNTHx;
                    goto epilog_0jZB3m3ntxR_7JPnMzyIoBg;

                    objunlock_BM (locked_0kZ9svhUUIT_2zI3SPQhfGs), locked_0kZ9svhUUIT_2zI3SPQhfGs = NULL;
                }
        } // end objlock _0kZ9svhUUIT_2zI3SPQhfGs
        /* !endingblock _1L7vF06qZON_9wSPaww8E2X */
        goto endblock__1L7vF06qZON_9wSPaww8E2X;
endblock__1L7vF06qZON_9wSPaww8E2X:
        ;
    } /*-block _1L7vF06qZON_9wSPaww8E2X */

epilog_0jZB3m3ntxR_7JPnMzyIoBg:
    __attribute__ ((unused)); // routine _0jZB3m3ntxR_7JPnMzyIoBg epilogue:
    // unlocking 1:
    if (locked_0kZ9svhUUIT_2zI3SPQhfGs != NULL)
        objunlock_BM(locked_0kZ9svhUUIT_2zI3SPQhfGs), locked_0kZ9svhUUIT_2zI3SPQhfGs = NULL; // for o_resobj
    if (stkf) stkf->stkfram_callfun = NULL;
    return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _0jZB3m3ntxR_7JPnMzyIoBg routine#3 _0jZB3m3ntxR_7JPnMzyIoBg




value_tyBM crout_0vCFi47Ctm6_70R5Tci6JuH_BM //#4
(struct stackframe_stBM* stkf, //
//!emit_block°basiclo_for_up_loop  < o_block (o_modgen o_routprep v_depth)
 // 4 arguments
 const value_tyBM arg0,  // o_block
 const value_tyBM arg1,  // o_modgen
 const value_tyBM arg2,  // o_routprep
 const value_tyBM arg3,  // v_depth
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
    // start of _0vCFi47Ctm6_70R5Tci6JuH
    struct frame_0vCFi47Ctm6_70R5Tci6JuH_BMst
    {
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
        /// 0 scalar values:
    } _;
    memset (&_, 0, sizeof(struct frame_0vCFi47Ctm6_70R5Tci6JuH_BMst));
    _.stkfram_head.htyp = typayl_StackFrame_BM;
    _.stkfram_head.hgc = 0;
    _.stkfram_head.rlen = 9;
    _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[9] /*|_0vCFi47Ctm6_70R5Tci6JuH*/;
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

startblock__6Jnvc0ZxFCj_9aOT6FGpvp2:
    __attribute__((unused));
    {
        /* +block _6Jnvc0ZxFCj_9aOT6FGpvp2 */
        /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _6NXI94hE78R_31gCNvG9obz
            /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ;



        {
            // run _1y5LOd8TMK1_4Evm0WxnUBJ
            /*debug emit_block°basiclo_for_up_loop start o_block o_modgen o_routprep depth*/
            DBGPRINTF_BM("emit_block°basiclo_for_up_loop start €%.9s o_block=%s o_modgen=%s/L%u o_routprep=%s depth#%ld",
                         "_1y5LOd8TMK1_4Evm0WxnUBJ",
                         objectdbg_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),
                         objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objectdbg2_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                         (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;
        } // end run _1y5LOd8TMK1_4Evm0WxnUBJ



        {
            // begin lockobj _8rkMLIm7zSu_1cmUNDHOEwG
            objectval_tyBM* curlockedob_8rkMLIm7zSu_1cmUNDHOEwG = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
            if (objlock_BM (curlockedob_8rkMLIm7zSu_1cmUNDHOEwG))
                {
                    locked_8rkMLIm7zSu_1cmUNDHOEwG = curlockedob_8rkMLIm7zSu_1cmUNDHOEwG;

                    /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4 = //assign _7ZXI6Zdr37M_9tDIRYKWyAS
                        /*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[88] /*!index*/))));

                    /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU = //assign _6LSBFvxlbNc_0rY6zQlblXq
                        /*objgetattr:*/objgetattr_BM(( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[75] /*!count*/)));

//+ #2/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::

                    {
                        // run _9RlrVeqVaJ4_7Q2XB4mXHj3
                        /*debug emit_block°basiclo_for_up_loop o_block o_varindex v_countexp depth*/
                        DBGPRINTF_BM("emit_block°basiclo_for_up_loop €%.9s o_block=%s o_varindex=%s v_countexp=%s depth#%ld",
                                     "_9RlrVeqVaJ4_7Q2XB4mXHj3",
                                     objectdbg_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),
                                     objectdbg1_BM( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4),
                                     OUTSTRVALUE_BM( /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU),
                                     (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;
                    } // end run _9RlrVeqVaJ4_7Q2XB4mXHj3

                    {
                        // start cexpansion _18JuYhtt3U6_1G2hLBZKcLY - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "{ //for-up "));
                    } // end cexpansion _18JuYhtt3U6_1G2hLBZKcLY - objstrbufferappendcstrpayl

//+ #4/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::
                    {
                        // start cexpansion _9GpOgboir8I_171IKtULnOE - objstrbufferprintobject
                        /*objstrbufferprintobject _9GpOgboir8I_171IKtULnOE:*/
                        objectval_tyBM* obsbuf_9GpOgboir8I_171IKtULnOE = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                        objectval_tyBM* ob_9GpOgboir8I_171IKtULnOE = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
                        if (objhasstrbufferpayl_BM(obsbuf_9GpOgboir8I_171IKtULnOE) && isobject_BM(ob_9GpOgboir8I_171IKtULnOE))
                            objstrbufferappendcstrpayl_BM(obsbuf_9GpOgboir8I_171IKtULnOE, objectdbg_BM(ob_9GpOgboir8I_171IKtULnOE));
// end objstrbufferprintobject _9GpOgboir8I_171IKtULnOE
                        ;
                    } // end cexpansion _9GpOgboir8I_171IKtULnOE - objstrbufferprintobject

                    {
                        // start cexpansion _7wZBpo5VBr6_6jSVDUVjePE - objstrbuffersetindentpayl
                        /*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                    } // end cexpansion _7wZBpo5VBr6_6jSVDUVjePE - objstrbuffersetindentpayl

//+ #6/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::
                    {
                        // start cexpansion _5933FfICfAg_8KivZyDlzYL - objstrbuffernewlinepayl
                        /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                    } // end cexpansion _5933FfICfAg_8KivZyDlzYL - objstrbuffernewlinepayl

                    {
                        // start cexpansion _7mlzwCbTf8a_9MWM2yGWjXl - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "intptr_t cnt"));
                    } // end cexpansion _7mlzwCbTf8a_9MWM2yGWjXl - objstrbufferappendcstrpayl

//+ #8/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::
                    {
                        // start cexpansion _8wf8lanEjIc_7Pkvsh2ZPzV - objstrbufferprintobjid
                        /*objstrbufferprintobjid _8wf8lanEjIc_7Pkvsh2ZPzV:*/
                        objectval_tyBM *obsbuf__8wf8lanEjIc_7Pkvsh2ZPzV = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                        objectval_tyBM *ob__8wf8lanEjIc_7Pkvsh2ZPzV = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
                        if (objhasstrbufferpayl_BM(obsbuf__8wf8lanEjIc_7Pkvsh2ZPzV) && isobject_BM(ob__8wf8lanEjIc_7Pkvsh2ZPzV))
                            {
                                char idbuf__8wf8lanEjIc_7Pkvsh2ZPzV [32];
                                memset (idbuf__8wf8lanEjIc_7Pkvsh2ZPzV, 0, sizeof(idbuf__8wf8lanEjIc_7Pkvsh2ZPzV));
                                idtocbuf32_BM (objid_BM (ob__8wf8lanEjIc_7Pkvsh2ZPzV), idbuf__8wf8lanEjIc_7Pkvsh2ZPzV);
                                objstrbufferappendcstrpayl_BM(obsbuf__8wf8lanEjIc_7Pkvsh2ZPzV, idbuf__8wf8lanEjIc_7Pkvsh2ZPzV);
                            };
// end objstrbufferprintobjid _8wf8lanEjIc_7Pkvsh2ZPzV
                        ;
                    } // end cexpansion _8wf8lanEjIc_7Pkvsh2ZPzV - objstrbufferprintobjid

                    {
                        // start cexpansion _6HS1ctWa2cx_8kR6FVRd5gz - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " = "));
                    } // end cexpansion _6HS1ctWa2cx_8kR6FVRd5gz - objstrbufferappendcstrpayl

//+ #10/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::
                    {
                        // start cexpansion _8Ux2RkzGGBL_1jntmBiiFTE - miniemit_expression
                        /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                ( /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                    } // end cexpansion _8Ux2RkzGGBL_1jntmBiiFTE - miniemit_expression

                    {
                        // start cexpansion _2B5X8R9i8ty_1ucz1kI8GDH - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ";"));
                    } // end cexpansion _2B5X8R9i8ty_1ucz1kI8GDH - objstrbufferappendcstrpayl

//+ #12/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::
                    {
                        // start cexpansion _0vpJQXO13zS_2L5lG1Mj9Jl - objstrbuffernewlinepayl
                        /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                    } // end cexpansion _0vpJQXO13zS_2L5lG1Mj9Jl - objstrbuffernewlinepayl

                    /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _61MCdztYidF_16139B2zGKg
                        0;

//+ #14/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::
                    /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _5aEMMsDVPT8_5OOBY9RA7UT
                        /*objnbcomps:*/ objnbcomps_BM ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);

                    {
                        // start cexpansion _4j0SrCTPKX5_578JTKzM0IO - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "for ("));
                    } // end cexpansion _4j0SrCTPKX5_578JTKzM0IO - objstrbufferappendcstrpayl

//+ #16/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::
                    {
                        // start cexpansion _9VLKy0D7b3d_3C7v96GTfEI - miniemit_var
                        /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                           ( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
                    } // end cexpansion _9VLKy0D7b3d_3C7v96GTfEI - miniemit_var

                    {
                        // start cexpansion _1bVTR9o3Bsm_4S0wt09vteL - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " =0;"));
                    } // end cexpansion _1bVTR9o3Bsm_4S0wt09vteL - objstrbufferappendcstrpayl

//+ #18/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::
                    {
                        // start cexpansion _3dqnISCnpKV_9cd4oa4lD8e - objstrbuffernewlinepayl
                        /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                    } // end cexpansion _3dqnISCnpKV_9cd4oa4lD8e - objstrbuffernewlinepayl

                    {
                        // start cexpansion _7FhLjwiMrkL_0S5nfILsPPH - miniemit_var
                        /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                           ( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
                    } // end cexpansion _7FhLjwiMrkL_0S5nfILsPPH - miniemit_var

//+ #20/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::
                    {
                        // start cexpansion _87dePnNzTl4_0O8JWYSX5zV - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " < cnt"));
                    } // end cexpansion _87dePnNzTl4_0O8JWYSX5zV - objstrbufferappendcstrpayl

                    {
                        // start cexpansion _9o0MX6Ie2We_0ErK51uBv2S - objstrbufferprintobjid
                        /*objstrbufferprintobjid _9o0MX6Ie2We_0ErK51uBv2S:*/
                        objectval_tyBM *obsbuf__9o0MX6Ie2We_0ErK51uBv2S = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                        objectval_tyBM *ob__9o0MX6Ie2We_0ErK51uBv2S = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
                        if (objhasstrbufferpayl_BM(obsbuf__9o0MX6Ie2We_0ErK51uBv2S) && isobject_BM(ob__9o0MX6Ie2We_0ErK51uBv2S))
                            {
                                char idbuf__9o0MX6Ie2We_0ErK51uBv2S [32];
                                memset (idbuf__9o0MX6Ie2We_0ErK51uBv2S, 0, sizeof(idbuf__9o0MX6Ie2We_0ErK51uBv2S));
                                idtocbuf32_BM (objid_BM (ob__9o0MX6Ie2We_0ErK51uBv2S), idbuf__9o0MX6Ie2We_0ErK51uBv2S);
                                objstrbufferappendcstrpayl_BM(obsbuf__9o0MX6Ie2We_0ErK51uBv2S, idbuf__9o0MX6Ie2We_0ErK51uBv2S);
                            };
// end objstrbufferprintobjid _9o0MX6Ie2We_0ErK51uBv2S
                        ;
                    } // end cexpansion _9o0MX6Ie2We_0ErK51uBv2S - objstrbufferprintobjid

//+ #22/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::
                    {
                        // start cexpansion _0v5VUOseyTZ_0GTuiDe6qjP - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ";"));
                    } // end cexpansion _0v5VUOseyTZ_0GTuiDe6qjP - objstrbufferappendcstrpayl

                    {
                        // start cexpansion _0ajssbXBH1t_86eb7MoTPzX - objstrbuffernewlinepayl
                        /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                    } // end cexpansion _0ajssbXBH1t_86eb7MoTPzX - objstrbuffernewlinepayl

//+ #24/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::
                    {
                        // start cexpansion _2fEiBwWFSaE_0vU58gZVuk2 - miniemit_var
                        /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                           ( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
                    } // end cexpansion _2fEiBwWFSaE_0vU58gZVuk2 - miniemit_var

                    {
                        // start cexpansion _6nRAx5X9S18_4ndrVCGDGid - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "++) {"));
                    } // end cexpansion _6nRAx5X9S18_4ndrVCGDGid - objstrbufferappendcstrpayl

//+ #26/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::

//// +while _8azNt3uvDua_0vznLIRcXQ7
startblock__8azNt3uvDua_0vznLIRcXQ7:  /*+!while*/
                    ;
                    {
                        /* +while _8azNt3uvDua_0vznLIRcXQ7 */
                        if (!(/*while _8azNt3uvDua_0vznLIRcXQ7 cond:*/ (/*less_int:*/( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) < ( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k)))) //: testwhile _8azNt3uvDua_0vznLIRcXQ7 failing
                            goto endblock__8azNt3uvDua_0vznLIRcXQ7; //failwhile
// while _8azNt3uvDua_0vznLIRcXQ7 body:
// while _8azNt3uvDua_0vznLIRcXQ7 comp#0:
                        /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb = //assign _3ILFBLwMl1u_6ucVMPW4LUg
                            /*val_to_object:*/objectcast_BM(/*objgetcomp:*/objgetcomp_BM (( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)));
// while _8azNt3uvDua_0vznLIRcXQ7 comp#1:
                        if /*cond _3KcGmQSYuqY_1dj3Tb5qQwT*/
                        /*when _9NZCCksbBTL_1lELN9cqwB6:*/
                        ( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb)   //body when _9NZCCksbBTL_1lELN9cqwB6
                            {

                                {
                                    // run _6yU6G9JLfzp_7ifGjU3aSQy
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
                                {
                                    // start cexpansion _0DPBIFwbcm4_4l1ir7iZTuR - objstrbuffersetindentpayl
                                    /*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                } // end cexpansion _0DPBIFwbcm4_4l1ir7iZTuR - objstrbuffersetindentpayl
                                {
                                    // start cexpansion _99sshqy7Sjj_0hU1fNbVw2x - objstrbuffernewlinepayl
                                    /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                                } // end cexpansion _99sshqy7Sjj_0hU1fNbVw2x - objstrbuffernewlinepayl
                                {
                                    // start cexpansion _5vgsLFSo0RQ_0yFxUpyUa6k - objstrbufferappendcstrpayl
                                    /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "// for-up "));
                                } // end cexpansion _5vgsLFSo0RQ_0yFxUpyUa6k - objstrbufferappendcstrpayl
                                {
                                    // start cexpansion _4fwDvpq5srl_8hN8Q4lxInc - objstrbufferprintobjid
                                    /*objstrbufferprintobjid _4fwDvpq5srl_8hN8Q4lxInc:*/
                                    objectval_tyBM *obsbuf__4fwDvpq5srl_8hN8Q4lxInc = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                                    objectval_tyBM *ob__4fwDvpq5srl_8hN8Q4lxInc = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
                                    if (objhasstrbufferpayl_BM(obsbuf__4fwDvpq5srl_8hN8Q4lxInc) && isobject_BM(ob__4fwDvpq5srl_8hN8Q4lxInc))
                                        {
                                            char idbuf__4fwDvpq5srl_8hN8Q4lxInc [32];
                                            memset (idbuf__4fwDvpq5srl_8hN8Q4lxInc, 0, sizeof(idbuf__4fwDvpq5srl_8hN8Q4lxInc));
                                            idtocbuf32_BM (objid_BM (ob__4fwDvpq5srl_8hN8Q4lxInc), idbuf__4fwDvpq5srl_8hN8Q4lxInc);
                                            objstrbufferappendcstrpayl_BM(obsbuf__4fwDvpq5srl_8hN8Q4lxInc, idbuf__4fwDvpq5srl_8hN8Q4lxInc);
                                        };
// end objstrbufferprintobjid _4fwDvpq5srl_8hN8Q4lxInc
                                    ;
                                } // end cexpansion _4fwDvpq5srl_8hN8Q4lxInc - objstrbufferprintobjid
                                {
                                    // start cexpansion _3dJQpojlpw0_5d9iHzwxHt0 - objstrbufferappendcstrpayl
                                    /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " #"));
                                } // end cexpansion _3dJQpojlpw0_5d9iHzwxHt0 - objstrbufferappendcstrpayl
                                {
                                    // start cexpansion _2AQKWLCUFvL_1nhtg5qyMOW - objstrbufferprintint
                                    /*objstrbufferprintint:*/if (objhasstrbufferpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv))
                                        {
                                            char buf_2AQKWLCUFvL_1nhtg5qyMOW[32];
                                            memset (buf_2AQKWLCUFvL_1nhtg5qyMOW, 0, sizeof(buf_2AQKWLCUFvL_1nhtg5qyMOW));
                                            snprintf(buf_2AQKWLCUFvL_1nhtg5qyMOW, sizeof(buf_2AQKWLCUFvL_1nhtg5qyMOW), "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
                                            objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), buf_2AQKWLCUFvL_1nhtg5qyMOW);
                                        } //end objstrbufferprintint _2AQKWLCUFvL_1nhtg5qyMOW
                                    ;
                                } // end cexpansion _2AQKWLCUFvL_1nhtg5qyMOW - objstrbufferprintint
                                {
                                    // start cexpansion _78NeiHidc0B_0v6yK8esTnj - objstrbufferappendcstrpayl
                                    /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " :"));
                                } // end cexpansion _78NeiHidc0B_0v6yK8esTnj - objstrbufferappendcstrpayl
                                {
                                    // start cexpansion _9ZltE2hANvA_7WHBrdvAnhY - objstrbuffernewlinepayl
                                    /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                                } // end cexpansion _9ZltE2hANvA_7WHBrdvAnhY - objstrbuffernewlinepayl

                                {
                                    // begin lockobj _6Yjljnt0m8g_6LWfXAh0c3u
                                    objectval_tyBM* curlockedob_6Yjljnt0m8g_6LWfXAh0c3u = ( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb);
                                    if (objlock_BM (curlockedob_6Yjljnt0m8g_6LWfXAh0c3u))
                                        {
                                            locked_6Yjljnt0m8g_6LWfXAh0c3u = curlockedob_6Yjljnt0m8g_6LWfXAh0c3u;

                                            if /*cond _2EhWIVvxjvU_1ISxJRsN8RH*/
                                            /*when _0XHPA7cptAe_4i19aTf4Gxq:*/
                                            (/*objectisinstance:*/ objectisinstance_BM(( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[49] /*!basiclo_block*/))))   //body when _0XHPA7cptAe_4i19aTf4Gxq
                                                {
                                                    /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _1FhisSY6VvV_9wuNntndHjA
                                                        (send3_BM (( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), /*sel:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[81] /*!emit_block*/)), ((struct stackframe_stBM*)&_),
                                                                   ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),  ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                                                                   (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));

                                                } //endwhen _0XHPA7cptAe_4i19aTf4Gxq
                                            else if
                                            /*when _0H7JvNndU7R_1y4eLjc1NUL:*/
                                            (/*objectisinstance:*/ objectisinstance_BM(( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[51] /*!basiclo_statement*/))))   //body when _0H7JvNndU7R_1y4eLjc1NUL
                                                {
                                                    /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _2mKWX3OmQZn_4ros3plkqLz
                                                        (send3_BM (( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), /*sel:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[22] /*!emit_statement*/)), ((struct stackframe_stBM*)&_),
                                                                   ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),  ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                                                                   (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));

                                                } //endwhen _0H7JvNndU7R_1y4eLjc1NUL
                                            else   /*cond else _2EhWIVvxjvU_1ISxJRsN8RH*/
                                                {
//failure _6MTJtvsUEYW_9WuS0LnLfmm
                                                    PLACEDFAILURE_BM(__LINE__,
                                                                     /*failreason:*/ (((value_tyBM) makenode5_BM
                                                                                       (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[56] /*!failure_bad_class*/)),
                                                                                               /*make_node 5 sons:*/
                                                                                               ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[9] /*!_0vCFi47Ctm6_70R5Tci6JuH*/)),

                                                                                               ( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),

                                                                                               (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                                               ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),

                                                                                               ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW)))),
                                                                     /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[91] /*|_6MTJtvsUEYW_9WuS0LnLfmm*/)),
                                                                     ((struct stackframe_stBM *) &_));
                                                } /*cond else _2EhWIVvxjvU_1ISxJRsN8RH*/
                                            /*endcond _2EhWIVvxjvU_1ISxJRsN8RH*/


                                            {
                                                // run _0iLVtU6WXeV_1Q97ZeNzYpy
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
                                            (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL))   //body when _7erONaq08kk_4kMHqRc79hd
                                                {
//failure _3CZ4Lq3VkJF_3Qt5nkQ9R3w
                                                    PLACEDFAILURE_BM(__LINE__,
                                                                     /*failreason:*/ (((value_tyBM) makenode5_BM
                                                                                       (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                                               /*make_node 5 sons:*/
                                                                                               ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[9] /*!_0vCFi47Ctm6_70R5Tci6JuH*/)),

                                                                                               ( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),

                                                                                               (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                                               ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),

                                                                                               ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW)))),
                                                                     /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[44] /*|_3CZ4Lq3VkJF_3Qt5nkQ9R3w*/)),
                                                                     ((struct stackframe_stBM *) &_));

                                                } //endwhen _7erONaq08kk_4kMHqRc79hd
                                            /*endcond _6lacdJDQoOJ_2mjBKMBpZVX*/

                                            objunlock_BM (locked_6Yjljnt0m8g_6LWfXAh0c3u), locked_6Yjljnt0m8g_6LWfXAh0c3u = NULL;
                                        }
                                } // end objlock _6Yjljnt0m8g_6LWfXAh0c3u

                            } //endwhen _9NZCCksbBTL_1lELN9cqwB6
                        /*endcond _3KcGmQSYuqY_1dj3Tb5qQwT*/
// while _8azNt3uvDua_0vznLIRcXQ7 comp#2:
                        /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _894QWyZSi2X_11HWCDneRlh
                            /*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1));

                        goto startblock__8azNt3uvDua_0vznLIRcXQ7; // repeatwhile
endblock__8azNt3uvDua_0vznLIRcXQ7: /*endingwhile*/
                        ;
                    } /*-endwhile _8azNt3uvDua_0vznLIRcXQ7 */


                    {
                        // start cexpansion _5seJMeyVMag_6jwlAf81tPv - objstrbuffersetindentpayl
                        /*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
                    } // end cexpansion _5seJMeyVMag_6jwlAf81tPv - objstrbuffersetindentpayl

//+ #28/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::
                    {
                        // start cexpansion _86q4oBOlppk_1830Im1NZjk - objstrbuffernewlinepayl
                        /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                    } // end cexpansion _86q4oBOlppk_1830Im1NZjk - objstrbuffernewlinepayl

                    {
                        // start cexpansion _5EtdhJgLlVL_5U1X2vmfp0y - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "}} // end for-up "));
                    } // end cexpansion _5EtdhJgLlVL_5U1X2vmfp0y - objstrbufferappendcstrpayl

//+ #30/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::
                    {
                        // start cexpansion _0d5SVBzCltH_1ZscGvcgwrx - objstrbufferprintobjid
                        /*objstrbufferprintobjid _0d5SVBzCltH_1ZscGvcgwrx:*/
                        objectval_tyBM *obsbuf__0d5SVBzCltH_1ZscGvcgwrx = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                        objectval_tyBM *ob__0d5SVBzCltH_1ZscGvcgwrx = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
                        if (objhasstrbufferpayl_BM(obsbuf__0d5SVBzCltH_1ZscGvcgwrx) && isobject_BM(ob__0d5SVBzCltH_1ZscGvcgwrx))
                            {
                                char idbuf__0d5SVBzCltH_1ZscGvcgwrx [32];
                                memset (idbuf__0d5SVBzCltH_1ZscGvcgwrx, 0, sizeof(idbuf__0d5SVBzCltH_1ZscGvcgwrx));
                                idtocbuf32_BM (objid_BM (ob__0d5SVBzCltH_1ZscGvcgwrx), idbuf__0d5SVBzCltH_1ZscGvcgwrx);
                                objstrbufferappendcstrpayl_BM(obsbuf__0d5SVBzCltH_1ZscGvcgwrx, idbuf__0d5SVBzCltH_1ZscGvcgwrx);
                            };
// end objstrbufferprintobjid _0d5SVBzCltH_1ZscGvcgwrx
                        ;
                    } // end cexpansion _0d5SVBzCltH_1ZscGvcgwrx - objstrbufferprintobjid

                    {
                        // start cexpansion _0YqaJV0TdmB_1bQnzdTXMfo - objstrbuffernewlinepayl
                        /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                    } // end cexpansion _0YqaJV0TdmB_1bQnzdTXMfo - objstrbuffernewlinepayl

//+ #32/34 of lockobj _8rkMLIm7zSu_1cmUNDHOEwG ::

                    {
                        // run _49h6SrVH7Ar_2cjBCTsDzF4
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
                }
        } // end objlock _8rkMLIm7zSu_1cmUNDHOEwG
        /* !endingblock _6Jnvc0ZxFCj_9aOT6FGpvp2 */
        goto endblock__6Jnvc0ZxFCj_9aOT6FGpvp2;
endblock__6Jnvc0ZxFCj_9aOT6FGpvp2:
        ;
    } /*-block _6Jnvc0ZxFCj_9aOT6FGpvp2 */

epilog_0vCFi47Ctm6_70R5Tci6JuH:
    __attribute__ ((unused)); // routine _0vCFi47Ctm6_70R5Tci6JuH epilogue:
    // unlocking 2:
    if (locked_6Yjljnt0m8g_6LWfXAh0c3u != NULL)
        objunlock_BM(locked_6Yjljnt0m8g_6LWfXAh0c3u), locked_6Yjljnt0m8g_6LWfXAh0c3u = NULL; // for o_comp
    if (locked_8rkMLIm7zSu_1cmUNDHOEwG != NULL)
        objunlock_BM(locked_8rkMLIm7zSu_1cmUNDHOEwG), locked_8rkMLIm7zSu_1cmUNDHOEwG = NULL; // for o_block
    if (stkf) stkf->stkfram_callfun = NULL;
    return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _0vCFi47Ctm6_70R5Tci6JuH routine#4 _0vCFi47Ctm6_70R5Tci6JuH




value_tyBM crout_0UTjJP38fIh_02d0wLwrdAc_BM //#5
(struct stackframe_stBM* stkf, //
//!miniscan_node_conn#lazy-bool (o_conn  o_routprep v_depth v_expr o_from)
 // 5 arguments
 const value_tyBM arg0,  // o_conn
 const value_tyBM arg1,  // o_routprep
 const value_tyBM arg2,  // v_depth
 const value_tyBM arg3,  // v_expr
 const quasinode_tyBM * restargs /* 1 extrargs */)
{
    // start of _0UTjJP38fIh_02d0wLwrdAc
    struct frame_0UTjJP38fIh_02d0wLwrdAc_BMst
    {
        typedhead_tyBM stkfram_head;
        struct stackframe_stBM *stkfram_prev;
        objectval_tyBM *stkfram_descr;
        value_tyBM stkfram_callfun;
        int stkfram_state;
        int stkfram_extra;
        /// 8 local values:
        value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
        objectval_tyBM* o_13K9OfeXRZR_84nyRTtoj81; // o_conn
        value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
        objectval_tyBM* o_4gykCX1QdLb_9Aooqa2FWTq; // o_scan
        value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
        value_tyBM v_6CmIdtsXyBX_3lpk31Mve5M; // v_expr
        objectval_tyBM* o_6RpSqxAOt2p_35laNqeU6KH; // o_routprep
        objectval_tyBM* o_89nz0KaXXZh_8eSgMmqnK37; // o_from
        /// 3 local numbers:
        intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
        intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
        intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
        /// 0 scalar values:
    } _;
    memset (&_, 0, sizeof(struct frame_0UTjJP38fIh_02d0wLwrdAc_BMst));
    _.stkfram_head.htyp = typayl_StackFrame_BM;
    _.stkfram_head.hgc = 0;
    _.stkfram_head.rlen = 8;
    _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[14] /*|_0UTjJP38fIh_02d0wLwrdAc*/;
    ASSERT_BM (!stkf
               || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
               || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
    _.stkfram_prev = stkf;
    // fetch 5 arguments:
    unsigned nbrestargs = treewidth_BM((value_tyBM)restargs);
    _.o_13K9OfeXRZR_84nyRTtoj81 = objectcast_BM (arg0); // o_conn
    _.o_6RpSqxAOt2p_35laNqeU6KH = objectcast_BM (arg1); // o_routprep
    _.v_4nJKFtMqlkA_1teQSqofNux = arg2; // v_depth
    _.v_6CmIdtsXyBX_3lpk31Mve5M = arg3; // v_expr
    if (nbrestargs > 0)
        _.o_89nz0KaXXZh_8eSgMmqnK37 = objectcast_BM(restargs->nodt_sons[0]); // o_from
    // fetched 5 arguments.
    // no closed values in _0UTjJP38fIh_02d0wLwrdAc.
    const closure_tyBM* callclos_0UTjJP38fIh_02d0wLwrdAc __attribute__((unused)) =
        (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
        ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
    const unsigned nbclosed_0UTjJP38fIh_02d0wLwrdAc  __attribute__((unused)) = 0;
    // routine _0UTjJP38fIh_02d0wLwrdAc body:

startblock__1IZyBil2Dgd_6qawsMUaqmM:
    __attribute__((unused));
    {
        /* +block _1IZyBil2Dgd_6qawsMUaqmM */
        /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _0WMYDGykVnl_2UqJ8QaaErF
            /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ;



        {
            // run _93Pw2WxKLe3_6BE9DMza1ak
            /*debug miniscan_node_conn#lazy-bool start o_conn o_routprep depth v_expr o_from*/
            DBGPRINTF_BM("miniscan_node_conn#lazy-bool start €%.9s o_conn=%s o_routprep=%s depth#%ld v_expr=%s o_from=%s",
                         "_93Pw2WxKLe3_6BE9DMza1ak",
                         objectdbg_BM( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),
                         objectdbg1_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                         (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
                         OUTSTRVALUE_BM( /*v_expr:*/_.v_6CmIdtsXyBX_3lpk31Mve5M),
                         objectdbg2_BM( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37));;
        } // end run _93Pw2WxKLe3_6BE9DMza1ak

//+ #2/5 of block _1IZyBil2Dgd_6qawsMUaqmM ::

        /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _0jnUQ1fnLRe_8rI1jQLC888
            /*nodewidth:*/(intptr_t)nodewidth_BM( /*v_expr:*/_.v_6CmIdtsXyBX_3lpk31Mve5M);


        {
            //for-up _19Y62we4Vmc_3w2d2YoTBJw
            intptr_t cnt_19Y62we4Vmc_3w2d2YoTBJw =  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k;
            for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;
                         /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_19Y62we4Vmc_3w2d2YoTBJw;
                         /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++)
                {
// for-up _19Y62we4Vmc_3w2d2YoTBJw #0 :
                    /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _7IGZBX69pSe_4r12sfQh6KZ
                        /*nodenthson:*/nodenthson_BM(( /*v_expr:*/_.v_6CmIdtsXyBX_3lpk31Mve5M),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));

// for-up _19Y62we4Vmc_3w2d2YoTBJw #1 :

                    {
                        // run _97qbknERZ3e_4ScCrGEP5ba
                        /*debug miniscan_node_conn#lazy-bool for ii v_comp o_routprep o_from*/
                        DBGPRINTF_BM("miniscan_node_conn#lazy-bool for €%.9s ii#%ld v_comp=%s o_routprep=%s o_from=%s",
                                     "_97qbknERZ3e_4ScCrGEP5ba",
                                     (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
                                     OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
                                     objectdbg_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                                     objectdbg1_BM( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37));;
                    } // end run _97qbknERZ3e_4ScCrGEP5ba

// for-up _19Y62we4Vmc_3w2d2YoTBJw #2 :
                    /*o_scan:*/_.o_4gykCX1QdLb_9Aooqa2FWTq = //assign _5GnSkHcGWeO_2ACZOivR55m
                        /*miniscan_expr:*/miniscan_expr_BM (( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37), CURFRAME_BM);

// for-up _19Y62we4Vmc_3w2d2YoTBJw #3 :

                    {
                        // run _6eYZ9sqIsbo_209NfiO2H4F
                        /*debug miniscan_node_conn#lazy-bool after miniscan_expr o_scan ii v_comp o_routprep o_from*/
                        DBGPRINTF_BM("miniscan_node_conn#lazy-bool after miniscan_expr €%.9s o_scan=%s ii#%ld v_comp=%s o_routprep=%s o_from=%s",
                                     "_6eYZ9sqIsbo_209NfiO2H4F",
                                     objectdbg_BM( /*o_scan:*/_.o_4gykCX1QdLb_9Aooqa2FWTq),
                                     (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
                                     OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
                                     objectdbg1_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                                     objectdbg2_BM( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37));;
                    } // end run _6eYZ9sqIsbo_209NfiO2H4F

// for-up _19Y62we4Vmc_3w2d2YoTBJw #4 :
                    if /*cond _2oAvaUII7oV_69DFh8LFZdf*/
                    /*when _6KeTl9KXXS8_1G71NrKrxew:*/
                    (/*is_null:*/(( /*o_scan:*/_.o_4gykCX1QdLb_9Aooqa2FWTq)==NULL))   //body when _6KeTl9KXXS8_1G71NrKrxew
                        {
//failure _06VtiJOTUI8_3WHyKhJi3sy
                            PLACEDFAILURE_BM(__LINE__,
                                             /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                               (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                /*make_node 7 sons:*/
                                                                ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[100] /*!miniscan_expr*/)),

                                                                ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

                                                                (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                ( /*v_expr:*/_.v_6CmIdtsXyBX_3lpk31Mve5M),

                                                                ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[0] /*|_06VtiJOTUI8_3WHyKhJi3sy*/)),
                                             ((struct stackframe_stBM *) &_));

                        } //endwhen _6KeTl9KXXS8_1G71NrKrxew
                    /*endcond _2oAvaUII7oV_69DFh8LFZdf*/

                }
        } // end for-up _19Y62we4Vmc_3w2d2YoTBJw

        /*return _0mCVoS8uQFf_63j3QGhxqKw:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned
            (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[8] /*!int*/);
        goto epilog_0UTjJP38fIh_02d0wLwrdAc;

        /* !endingblock _1IZyBil2Dgd_6qawsMUaqmM */
        goto endblock__1IZyBil2Dgd_6qawsMUaqmM;
endblock__1IZyBil2Dgd_6qawsMUaqmM:
        ;
    } /*-block _1IZyBil2Dgd_6qawsMUaqmM */

epilog_0UTjJP38fIh_02d0wLwrdAc:
    __attribute__ ((unused)); // routine _0UTjJP38fIh_02d0wLwrdAc epilogue:
    if (stkf) stkf->stkfram_callfun = NULL;
    return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _0UTjJP38fIh_02d0wLwrdAc routine#5 _0UTjJP38fIh_02d0wLwrdAc




value_tyBM crout_17b3bhqLPeu_04FWlRjdMvD_BM //#6
(struct stackframe_stBM* stkf, //
//!miniscan_block°basiclo_labeled_block < o_block (o_routprep v_depth o_from)
 // 4 arguments
 const value_tyBM arg0,  // o_block
 const value_tyBM arg1,  // o_routprep
 const value_tyBM arg2,  // v_depth
 const value_tyBM arg3,  // o_from
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
    // start of _17b3bhqLPeu_04FWlRjdMvD
    struct frame_17b3bhqLPeu_04FWlRjdMvD_BMst
    {
        typedhead_tyBM stkfram_head;
        struct stackframe_stBM *stkfram_prev;
        objectval_tyBM *stkfram_descr;
        value_tyBM stkfram_callfun;
        int stkfram_state;
        int stkfram_extra;
        /// 12 local values:
        objectval_tyBM* o_04acU7oHmQr_5HjwDBDPfvT; // o_blockhset
        objectval_tyBM* o_0H23AXQRcQ6_5Vw1gVzCjxh; // o_label
        value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
        value_tyBM v_14bZuNJeHA7_1reECNXu6Ly; // v_with_label
        objectval_tyBM* o_34Qtvf1thwK_9rziG6sk6Vl; // o_stmt
        value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
        value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
        value_tyBM v_5wKdFyGNJ5j_50nIjxm7LLY; // v_scanres
        objectval_tyBM* o_5XGKMg1Kevs_6eAce4ib9XW; // o_block
        objectval_tyBM* o_6RpSqxAOt2p_35laNqeU6KH; // o_routprep
        objectval_tyBM* o_6Z4UU939WbU_8BK9xcKsXNb; // o_comp
        objectval_tyBM* o_89nz0KaXXZh_8eSgMmqnK37; // o_from
        /// 3 local numbers:
        intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
        intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
        intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
        /// 0 scalar values:
    } _;
    memset (&_, 0, sizeof(struct frame_17b3bhqLPeu_04FWlRjdMvD_BMst));
    _.stkfram_head.htyp = typayl_StackFrame_BM;
    _.stkfram_head.hgc = 0;
    _.stkfram_head.rlen = 12;
    _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[15] /*|_17b3bhqLPeu_04FWlRjdMvD*/;
    ASSERT_BM (!stkf
               || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
               || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
    _.stkfram_prev = stkf;
    // locking 1:
    objectval_tyBM* locked_4Y1gfisHGIp_2kD67Pglb2s = NULL; // for o_blockhset
    // fetch 4 arguments:
    _.o_5XGKMg1Kevs_6eAce4ib9XW = objectcast_BM (arg0); // o_block
    _.o_6RpSqxAOt2p_35laNqeU6KH = objectcast_BM (arg1); // o_routprep
    _.v_4nJKFtMqlkA_1teQSqofNux = arg2; // v_depth
    _.o_89nz0KaXXZh_8eSgMmqnK37 = objectcast_BM (arg3); // o_from
    // fetched 4 arguments.
    {
        // fetch 1 closed values in _17b3bhqLPeu_04FWlRjdMvD:
        const closure_tyBM* callclos_17b3bhqLPeu_04FWlRjdMvD =
            (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
            ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
        const unsigned nbclosed_17b3bhqLPeu_04FWlRjdMvD = closurewidth_BM ((const value_tyBM) callclos_17b3bhqLPeu_04FWlRjdMvD);
        if (nbclosed_17b3bhqLPeu_04FWlRjdMvD > 0)
            _.v_14bZuNJeHA7_1reECNXu6Ly = callclos_17b3bhqLPeu_04FWlRjdMvD->nodt_sons[0]; // v_with_label
    } // fetched 1 closed values in _17b3bhqLPeu_04FWlRjdMvD.
    // routine _17b3bhqLPeu_04FWlRjdMvD body:

startblock__5jr2Oa4uMKm_7ByXSRL0umI:
    __attribute__((unused));
    {
        /* +block _5jr2Oa4uMKm_7ByXSRL0umI */
        /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _6LsY57GioDB_0Y6NIoq59hL
            /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ;


        /*o_label:*/_.o_0H23AXQRcQ6_5Vw1gVzCjxh = //assign _9kguKgvNmZx_7wBfARcd14h
            /*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[47] /*!label*/))));

//+ #2/8 of block _5jr2Oa4uMKm_7ByXSRL0umI ::


        {
            // run _4GXCnmBGznF_3E6F2jy9bbD
            /*debug miniscan_block°basiclo_labeled_block start o_block o_routprep depth o_from o_label v_with_label*/
            DBGPRINTF_BM("miniscan_block°basiclo_labeled_block start €%.9s o_block=%s o_routprep=%s depth#%ld o_from=%s; o_label=%s v_with_label=%s",
                         "_4GXCnmBGznF_3E6F2jy9bbD",
                         objectdbg_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),
                         objectdbg1_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                         (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
                         objectdbg2_BM( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37),
                         objectdbg3_BM( /*o_label:*/_.o_0H23AXQRcQ6_5Vw1gVzCjxh),
                         OUTSTRVALUE_BM( /*v_with_label:*/_.v_14bZuNJeHA7_1reECNXu6Ly));;
        } // end run _4GXCnmBGznF_3E6F2jy9bbD


        /*o_blockhset:*/_.o_04acU7oHmQr_5HjwDBDPfvT = //assign _1h1R6CiuNj7_0yjfM6fGldU
            /*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[28] /*!blocks*/))));

//+ #4/8 of block _5jr2Oa4uMKm_7ByXSRL0umI ::


        {
            // begin lockobj _4Y1gfisHGIp_2kD67Pglb2s
            objectval_tyBM* curlockedob_4Y1gfisHGIp_2kD67Pglb2s = ( /*o_blockhset:*/_.o_04acU7oHmQr_5HjwDBDPfvT);
            if (objlock_BM (curlockedob_4Y1gfisHGIp_2kD67Pglb2s))
                {
                    locked_4Y1gfisHGIp_2kD67Pglb2s = curlockedob_4Y1gfisHGIp_2kD67Pglb2s;

                    if /*cond _6TV10KEfLcr_82h6ovLuuJF*/
                    /*when _3p8hf2u0up1_9dqk9fjxRAT:*/
                    (/*objhashsetcontainspayl:*/  objhashsetcontainspayl_BM (( /*o_blockhset:*/_.o_04acU7oHmQr_5HjwDBDPfvT), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW)))   //body when _3p8hf2u0up1_9dqk9fjxRAT
                        {
//failure _4bYmNw22J07_8hqiBv4W94U
                            PLACEDFAILURE_BM(__LINE__,
                                             /*failreason:*/ (((value_tyBM) makenode5_BM
                                                               (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[39] /*!duplicate*/)),
                                                                       /*make_node 5 sons:*/
                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[15] /*!_17b3bhqLPeu_04FWlRjdMvD*/)),

                                                                       ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),

                                                                       ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

// make_node arg #4
                                                                       (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                       ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[48] /*|_4bYmNw22J07_8hqiBv4W94U*/)),
                                             ((struct stackframe_stBM *) &_));

                        } //endwhen _3p8hf2u0up1_9dqk9fjxRAT
                    /*endcond _6TV10KEfLcr_82h6ovLuuJF*/

                    {
                        // start cexpansion _1r9o3IzeKp7_8jNLtBHj8FT - objhashsetaddpayl
                        /*objhashsetaddpayl:*/ objhashsetaddpayl_BM (( /*o_blockhset:*/_.o_04acU7oHmQr_5HjwDBDPfvT), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW));
                    } // end cexpansion _1r9o3IzeKp7_8jNLtBHj8FT - objhashsetaddpayl

                    objunlock_BM (locked_4Y1gfisHGIp_2kD67Pglb2s), locked_4Y1gfisHGIp_2kD67Pglb2s = NULL;
                }
        } // end objlock _4Y1gfisHGIp_2kD67Pglb2s

        if /*cond _1SMM8Gtower_4x51iESiEJ8*/
        /*when _8c1jRxeOrdB_9SX1nvf4kSP:*/
        ( /*v_with_label:*/_.v_14bZuNJeHA7_1reECNXu6Ly)   //body when _8c1jRxeOrdB_9SX1nvf4kSP
            {
                /*o_label:*/_.o_0H23AXQRcQ6_5Vw1gVzCjxh = //assign _6l4074fxmqc_1dz3DYT79I7
                    /*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[47] /*!label*/))));
                if /*cond _37bFZCPYu12_7z00iIqWzVK*/
                /*when _8NCsU3tZIZY_1n11jrnJvpB:*/
                (/*not:*/ (! (/*objectisinstance:*/ objectisinstance_BM(( /*o_label:*/_.o_0H23AXQRcQ6_5Vw1gVzCjxh),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[83] /*!basiclo_label*/))))))   //body when _8NCsU3tZIZY_1n11jrnJvpB
                    {
//failure _8WAizZ04huN_09Xhiag4jid
                        PLACEDFAILURE_BM(__LINE__,
                                         /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                           (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[118] /*!failure_type_error*/)),
                                                            /*make_node 7 sons:*/
                                                            ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[5] /*!in*/)),

                                                            ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[47] /*!label*/)),

                                                            ( /*o_label:*/_.o_0H23AXQRcQ6_5Vw1gVzCjxh),

// make_node arg #4
                                                            ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),

                                                            ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                            (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                            ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                         /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[117] /*|_8WAizZ04huN_09Xhiag4jid*/)),
                                         ((struct stackframe_stBM *) &_));

                    } //endwhen _8NCsU3tZIZY_1n11jrnJvpB
                /*endcond _37bFZCPYu12_7z00iIqWzVK*/

            } //endwhen _8c1jRxeOrdB_9SX1nvf4kSP
        /*endcond _1SMM8Gtower_4x51iESiEJ8*/

//+ #6/8 of block _5jr2Oa4uMKm_7ByXSRL0umI ::

        /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _10VifzlScsY_0aHVcNts9zg
            /*objnbcomps:*/ objnbcomps_BM ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);


        {
            //for-up _52ud8hT9fla_8ruKXOZ7y9w
            intptr_t cnt_52ud8hT9fla_8ruKXOZ7y9w =  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k;
            for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;
                         /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_52ud8hT9fla_8ruKXOZ7y9w;
                         /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++)
                {
// for-up _52ud8hT9fla_8ruKXOZ7y9w #0 :
                    /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _8dvJY3W2DNa_4DEbeXDXeHO
                        /*objgetcomp:*/objgetcomp_BM (( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));

                }
        } // end for-up _52ud8hT9fla_8ruKXOZ7y9w
        /* !endingblock _5jr2Oa4uMKm_7ByXSRL0umI */
        goto endblock__5jr2Oa4uMKm_7ByXSRL0umI;
endblock__5jr2Oa4uMKm_7ByXSRL0umI:
        ;
    } /*-block _5jr2Oa4uMKm_7ByXSRL0umI */

epilog_17b3bhqLPeu_04FWlRjdMvD:
    __attribute__ ((unused)); // routine _17b3bhqLPeu_04FWlRjdMvD epilogue:
    // unlocking 1:
    if (locked_4Y1gfisHGIp_2kD67Pglb2s != NULL)
        objunlock_BM(locked_4Y1gfisHGIp_2kD67Pglb2s), locked_4Y1gfisHGIp_2kD67Pglb2s = NULL; // for o_blockhset
    if (stkf) stkf->stkfram_callfun = NULL;
    return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _17b3bhqLPeu_04FWlRjdMvD routine#6 _17b3bhqLPeu_04FWlRjdMvD




value_tyBM crout_1kz7viwMzTp_6PgLhdZzMEy_BM //#7
(struct stackframe_stBM* stkf, //
//!miniscan_stmt°basiclo_outstmt < o_stmt (o_routprep v_depth o_from)
 // 4 arguments
 const value_tyBM arg0,  // o_stmt
 const value_tyBM arg1,  // o_routprep
 const value_tyBM arg2,  // v_depth
 const value_tyBM arg3,  // o_from
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
    // start of _1kz7viwMzTp_6PgLhdZzMEy
    struct frame_1kz7viwMzTp_6PgLhdZzMEy_BMst
    {
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
        /// 0 scalar values:
    } _;
    memset (&_, 0, sizeof(struct frame_1kz7viwMzTp_6PgLhdZzMEy_BMst));
    _.stkfram_head.htyp = typayl_StackFrame_BM;
    _.stkfram_head.hgc = 0;
    _.stkfram_head.rlen = 12;
    _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[18] /*|_1kz7viwMzTp_6PgLhdZzMEy*/;
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

startblock__2z5wZyWhJId_3qRwMQOiLBm:
    __attribute__((unused));
    {
        /* +block _2z5wZyWhJId_3qRwMQOiLBm */
        /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _74XT4f1vWl9_7pfkRaZCCjn
            /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ;


        /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV = //assign _5nVWpRtEEts_2uWUDb4OAKl
            /*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[11] /*!out*/))));

//+ #2/9 of block _2z5wZyWhJId_3qRwMQOiLBm ::

        /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _1a4rnGQ9X5p_4tJnSawMpZZ
            /*objnbcomps:*/ objnbcomps_BM ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);



        {
            // run _1mcZijyVnzr_1xEWETupmkp
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
        (/*is_null:*/(( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV)==NULL))   //body when _9AQ254qOzzB_9MWUVdb8wEe
            {
//failure _1m5rw0BZl8f_4M9cndtjRl8
                PLACEDFAILURE_BM(__LINE__,
                                 /*failreason:*/ (((value_tyBM) makenode6_BM
                                                   (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                           /*make_node 6 sons:*/
                                                           ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[18] /*!_1kz7viwMzTp_6PgLhdZzMEy*/)),

                                                           ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[11] /*!out*/)),

                                                           ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

// make_node arg #4
                                                           ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                           (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                           ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[21] /*|_1m5rw0BZl8f_4M9cndtjRl8*/)),
                                 ((struct stackframe_stBM *) &_));

            } //endwhen _9AQ254qOzzB_9MWUVdb8wEe
        /*endcond _5VxN0iVhyqn_26Sl2TGladQ*/



        {
            // begin lockobj _1mO4b6i93tJ_8qQI7qdBqdy
            objectval_tyBM* curlockedob_1mO4b6i93tJ_8qQI7qdBqdy = ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV);
            if (objlock_BM (curlockedob_1mO4b6i93tJ_8qQI7qdBqdy))
                {
                    locked_1mO4b6i93tJ_8qQI7qdBqdy = curlockedob_1mO4b6i93tJ_8qQI7qdBqdy;

                    /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I = //assign _0cq3euqLSO5_6Ucuzrr3vxl
                        /*miniscan_var:*/ miniscan_var_BM (( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM);


                    {
                        // run _4RKeQdff5vV_0dyAyd7S7dt
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
                    (/*unequal_value*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[105] /*!object*/))))   //body when _6wuhAPMNDcY_0RSyScYXYj6
                        {
//failure _6cS5VddZd7n_9Nnn2wYWAeL
                            PLACEDFAILURE_BM(__LINE__,
                                             /*failreason:*/ (((value_tyBM) makenode6_BM
                                                               (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                       /*make_node 6 sons:*/
                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[80] /*!miniscan_var*/)),

                                                                       ( /*o_varout:*/_.o_68pH0LfBXQ1_9SRMhSZJlQV),

                                                                       ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

// make_node arg #4
                                                                       (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1)))),

                                                                       ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                       ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[78] /*|_6cS5VddZd7n_9Nnn2wYWAeL*/)),
                                             ((struct stackframe_stBM *) &_));

                        } //endwhen _6wuhAPMNDcY_0RSyScYXYj6
                    /*endcond _4eHwSv2Q87p_02OWtoIcKUc*/

                    objunlock_BM (locked_1mO4b6i93tJ_8qQI7qdBqdy), locked_1mO4b6i93tJ_8qQI7qdBqdy = NULL;
                }
        } // end objlock _1mO4b6i93tJ_8qQI7qdBqdy
//+ #6/9 of block _2z5wZyWhJId_3qRwMQOiLBm ::

        {
            //for-up _0tD16ZfI6r2_4QaWuN6poQA
            intptr_t cnt_0tD16ZfI6r2_4QaWuN6poQA =  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k;
            for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;
                         /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_0tD16ZfI6r2_4QaWuN6poQA;
                         /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++)
                {
// for-up _0tD16ZfI6r2_4QaWuN6poQA #0 :
                    /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _8wqqyJEwgUf_7TGATyKMLYH
                        /*objgetcomp:*/objgetcomp_BM (( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));

// for-up _0tD16ZfI6r2_4QaWuN6poQA #1 :

                    {
                        // run _2lDiLBXEGvY_3QGIrHwVlgs
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
                    (/*is_stringv:*/ isstring_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe))   //body when _3kHUgpOuycP_0n0jO2VY4Dh
                        {

                            {
                                // run _0jQHXwEYl0E_6pSxiLZ4MGZ
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
                    (/*isnode:*/isnode_BM(( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)))   //body when _7gliKK4XRvp_9hHvC2gJHKE
                        {
                            /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81 = //assign _4yPhtDSXsAM_5IfJKyK2c05
                                /*nodeconn:*/nodeconn_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe);

                            {
                                // begin objswitch _3WmrD9dWzVs_6l9CVwfdtYt
//!objswitch! obj-switch o_conn .. miniscan_stmt°basiclo_outstmt .
                                objectval_tyBM* objswexp_3WmrD9dWzVs_6l9CVwfdtYt = ( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81);
                                switch (objecthash_BM (objswexp_3WmrD9dWzVs_6l9CVwfdtYt) % 64)
                                    {
                                    case 0:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[37] /*|utf8_enc*/)) goto whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z;
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[67] /*|less_indent*/)) goto whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 2:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[98] /*|nlsp*/)) goto whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 5:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[84] /*|c_enc*/)) goto whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 6:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[32] /*|newline*/)) goto whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 11:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[105] /*|object*/)) goto whenobj3WmrD9dW__1wFGt8trU1A_1Nb4JV3o0QV;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 15:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[45] /*|html_enc*/)) goto whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 18:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[31] /*|half_id*/)) goto whenobj3WmrD9dW__1wFGt8trU1A_1Nb4JV3o0QV;
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[55] /*|double_plain*/)) goto whenobj3WmrD9dW__157NBYH3VXp_1nEo0skjEyQ;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 19:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[20] /*|octa*/)) goto whenobj3WmrD9dW__3Q9LapaKOXA_9lQQ7ENfb8d;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 22:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[41] /*|space*/)) goto whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m;
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[72] /*|json_indented*/)) goto whenobj3WmrD9dW__0msPpd1UF1h_6Q13YXMYlaN;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 30:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[8] /*|int*/)) goto whenobj3WmrD9dW__3Q9LapaKOXA_9lQQ7ENfb8d;
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[10] /*|prefixed_lines*/)) goto whenobj3WmrD9dW__3S5MXOVnhRg_2OUoTkvbDYP;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 31:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[97] /*|value*/)) goto whenobj3WmrD9dW__5FrwHPgIxS4_6QYhDVrIvKP;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 34:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[109] /*|hexa*/)) goto whenobj3WmrD9dW__3Q9LapaKOXA_9lQQ7ENfb8d;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 36:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[7] /*|more_indent*/)) goto whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 41:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[38] /*|local_time*/)) goto whenobj3WmrD9dW__157NBYH3VXp_1nEo0skjEyQ;
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[68] /*|literal_c_string*/)) goto whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 42:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[17] /*|name*/)) goto whenobj3WmrD9dW__1wFGt8trU1A_1Nb4JV3o0QV;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 47:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[53] /*|json_compact*/)) goto whenobj3WmrD9dW__0msPpd1UF1h_6Q13YXMYlaN;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 51:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[33] /*|set_indent*/)) goto whenobj3WmrD9dW__3Q9LapaKOXA_9lQQ7ENfb8d;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 54:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[30] /*|double_float*/)) goto whenobj3WmrD9dW__157NBYH3VXp_1nEo0skjEyQ;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;
                                    case 55:
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[59] /*|string*/)) goto whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z;
                                        if (objswexp_3WmrD9dWzVs_6l9CVwfdtYt ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[107] /*|id*/)) goto whenobj3WmrD9dW__1wFGt8trU1A_1Nb4JV3o0QV;
                                        goto defobj_3WmrD9dWzVs_6l9CVwfdtYt;

                                    default:
defobj_3WmrD9dWzVs_6l9CVwfdtYt:
                                        ;

// objswitch _3WmrD9dWzVs_6l9CVwfdtYt default#0 statement:
//failure _5J4f6u42le4_9UZMTZziEEw
                                        PLACEDFAILURE_BM(__LINE__,
                                                         /*failreason:*/ (((value_tyBM) makenode6_BM
                                                                           (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                                   /*make_node 6 sons:*/
                                                                                   ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

                                                                                   (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

                                                                                   ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

// make_node arg #4
                                                                                   ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                   (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                   ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                         /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[73] /*|_5J4f6u42le4_9UZMTZziEEw*/)),
                                                         ((struct stackframe_stBM *) &_));

                                        break; // end objswitch _3WmrD9dWzVs_6l9CVwfdtYt default
// objswitch _3WmrD9dWzVs_6l9CVwfdtYt with 8 whens:

whenobj3WmrD9dW__0msPpd1UF1h_6Q13YXMYlaN:; // when #0 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt
// objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _0msPpd1UF1h_6Q13YXMYlaN #0 statement:
                                        if /*cond _9yQol9uXYsR_59RMrumL33A*/
                                        /*when _2wErgMBgydm_19t3GtzTchr:*/
                                        ((/*equal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) == ( 0)))   //body when _2wErgMBgydm_19t3GtzTchr
                                            {
//failure _8QmDbXEU8lU_33mrgrh3zUR
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                                    /*make_node 7 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[79] /*!arity*/)),

                                                                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[116] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
                                                                 ((struct stackframe_stBM *) &_));

                                            } //endwhen _2wErgMBgydm_19t3GtzTchr
                                        else if
                                        /*when _5AOCJ23yr6D_7kvbaU8MJQi:*/
                                        ((/*greater_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) > ( 2)))   //body when _5AOCJ23yr6D_7kvbaU8MJQi
                                            {
//failure _8QmDbXEU8lU_33mrgrh3zUR
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                                    /*make_node 7 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[79] /*!arity*/)),

                                                                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[116] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
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

                                        {
                                            // run _9ZN4tL5btf4_8In65Qnv7Q0
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
                                        (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[97] /*!value*/))))   //body when _3FcUnG66DXT_7sllObXQZl3
                                            {
//failure _9umIVqZhssC_2WJZljFrGaA
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[118] /*!failure_type_error*/)),
                                                                                    /*make_node 8 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[97] /*!value*/)),

                                                                                    ( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I),

                                                                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

// make_node arg #4
                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[119] /*|_9umIVqZhssC_2WJZljFrGaA*/)),
                                                                 ((struct stackframe_stBM *) &_));

                                            } //endwhen _3FcUnG66DXT_7sllObXQZl3
                                        /*endcond _6m3V5fOZK2n_9AFeHjYt2ZV*/

// objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _0msPpd1UF1h_6Q13YXMYlaN #6 statement:
                                        if /*cond _3L9x4LFGCuY_3oHKGr2Cr7s*/
                                        /*when _5Cu0QpuvxD7_8rpyE1LiWIA:*/
                                        ( /*v_expctx:*/_.v_96vo6uBKhke_6E1vyN3kIKD)   //body when _5Cu0QpuvxD7_8rpyE1LiWIA
                                            {
                                                /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I = //assign _3sn46xmHUCY_3garOQ6etZ2
                                                    /*miniscan_expr:*/miniscan_expr_BM (( /*v_expctx:*/_.v_96vo6uBKhke_6E1vyN3kIKD), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM);
                                                if /*cond _6m3V5fOZK2n_9AFeHjYt2ZV*/
                                                /*when _3FcUnG66DXT_7sllObXQZl3:*/
                                                (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[97] /*!value*/))))   //body when _3FcUnG66DXT_7sllObXQZl3
                                                    {
//failure _9umIVqZhssC_2WJZljFrGaA
                                                        PLACEDFAILURE_BM(__LINE__,
                                                                         /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                           (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[118] /*!failure_type_error*/)),
                                                                                            /*make_node 8 sons:*/
                                                                                            ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[97] /*!value*/)),

                                                                                            ( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I),

                                                                                            ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

// make_node arg #4
                                                                                            (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

                                                                                            ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                            ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                            (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                            ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                         /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[119] /*|_9umIVqZhssC_2WJZljFrGaA*/)),
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
                                        ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 1)))   //body when _2vEPbWPCAJU_1xk1toAGUy4
                                            {
//failure _8QmDbXEU8lU_33mrgrh3zUR
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                                    /*make_node 7 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[79] /*!arity*/)),

                                                                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[116] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
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
                                        (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[30] /*!double_float*/))))   //body when _7aBjoERVXzl_1NNbIyjvx42
                                            {
//failure _4WkaKNhBpsa_9VlfEzlClhm
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[118] /*!failure_type_error*/)),
                                                                                    /*make_node 8 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[30] /*!double_float*/)),

                                                                                    ( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I),

                                                                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

// make_node arg #4
                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[60] /*|_4WkaKNhBpsa_9VlfEzlClhm*/)),
                                                                 ((struct stackframe_stBM *) &_));

                                            } //endwhen _7aBjoERVXzl_1NNbIyjvx42
                                        /*endcond _662Hp5KuXpF_9TsL9wOchLw*/


                                        break; // end when _157NBYH3VXp_1nEo0skjEyQ #1 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt

whenobj3WmrD9dW__1wFGt8trU1A_1Nb4JV3o0QV:; // when #2 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt
// objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _1wFGt8trU1A_1Nb4JV3o0QV #0 statement:
                                        if /*cond _0tPLTqqQhJ7_9Tr1hT1PRhR*/
                                        /*when _2vEPbWPCAJU_1xk1toAGUy4:*/
                                        ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 1)))   //body when _2vEPbWPCAJU_1xk1toAGUy4
                                            {
//failure _8QmDbXEU8lU_33mrgrh3zUR
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                                    /*make_node 7 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[79] /*!arity*/)),

                                                                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[116] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
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
                                        (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[105] /*!object*/))))   //body when _3dZuGA19JWs_2g4uoKzoqro
                                            {
//failure _2eREyARXfUb_2mTxUngIL6Y
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[118] /*!failure_type_error*/)),
                                                                                    /*make_node 8 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[105] /*!object*/)),

                                                                                    ( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I),

                                                                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

// make_node arg #4
                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[26] /*|_2eREyARXfUb_2mTxUngIL6Y*/)),
                                                                 ((struct stackframe_stBM *) &_));

                                            } //endwhen _3dZuGA19JWs_2g4uoKzoqro
                                        /*endcond _6wbaBUuIONg_9YGzdsfJjeb*/


                                        break; // end when _1wFGt8trU1A_1Nb4JV3o0QV #2 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt

whenobj3WmrD9dW__3Q9LapaKOXA_9lQQ7ENfb8d:; // when #3 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt
// objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _3Q9LapaKOXA_9lQQ7ENfb8d #0 statement:
                                        if /*cond _0tPLTqqQhJ7_9Tr1hT1PRhR*/
                                        /*when _2vEPbWPCAJU_1xk1toAGUy4:*/
                                        ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 1)))   //body when _2vEPbWPCAJU_1xk1toAGUy4
                                            {
//failure _8QmDbXEU8lU_33mrgrh3zUR
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                                    /*make_node 7 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[79] /*!arity*/)),

                                                                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[116] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
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
                                        (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[8] /*!int*/))))   //body when _8dLGLcW3TGC_4jPYDTI7ixi
                                            {
//failure _26UbzubL5aT_2vDJc23p59r
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[118] /*!failure_type_error*/)),
                                                                                    /*make_node 8 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[8] /*!int*/)),

                                                                                    ( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I),

                                                                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

// make_node arg #4
                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[25] /*|_26UbzubL5aT_2vDJc23p59r*/)),
                                                                 ((struct stackframe_stBM *) &_));

                                            } //endwhen _8dLGLcW3TGC_4jPYDTI7ixi
                                        /*endcond _8oSBVSRNj1v_3bsqcnGUWLD*/


                                        break; // end when _3Q9LapaKOXA_9lQQ7ENfb8d #3 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt

whenobj3WmrD9dW__3S5MXOVnhRg_2OUoTkvbDYP:; // when #4 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt
// objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _3S5MXOVnhRg_2OUoTkvbDYP #0 statement:
                                        if /*cond _5H81hkR38QC_0dH3bxpWZjc*/
                                        /*when _8ZHaOXIAYpR_5zTFuaj29yH:*/
                                        ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 2)))   //body when _8ZHaOXIAYpR_5zTFuaj29yH
                                            {
//failure _8QmDbXEU8lU_33mrgrh3zUR
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                                    /*make_node 7 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[79] /*!arity*/)),

                                                                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[116] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
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
                                        (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[59] /*!string*/))))   //body when _9BPjp8ame7V_0AzorRD9WNm
                                            {
//failure _4HAZLawO9HO_91oo1k4Ajat
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[118] /*!failure_type_error*/)),
                                                                                    /*make_node 8 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[59] /*!string*/)),

                                                                                    ( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I),

                                                                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

// make_node arg #4
                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[57] /*|_4HAZLawO9HO_91oo1k4Ajat*/)),
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
                                        (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[59] /*!string*/))))   //body when _9BPjp8ame7V_0AzorRD9WNm
                                            {
//failure _4HAZLawO9HO_91oo1k4Ajat
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[118] /*!failure_type_error*/)),
                                                                                    /*make_node 8 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[59] /*!string*/)),

                                                                                    ( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I),

                                                                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

// make_node arg #4
                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[57] /*|_4HAZLawO9HO_91oo1k4Ajat*/)),
                                                                 ((struct stackframe_stBM *) &_));

                                            } //endwhen _9BPjp8ame7V_0AzorRD9WNm
                                        /*endcond _6cOi4TgZpEg_7mN9SsWpWte*/


                                        break; // end when _3S5MXOVnhRg_2OUoTkvbDYP #4 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt

whenobj3WmrD9dW__5FrwHPgIxS4_6QYhDVrIvKP:; // when #5 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt
// objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _5FrwHPgIxS4_6QYhDVrIvKP #0 statement:
                                        if /*cond _0tPLTqqQhJ7_9Tr1hT1PRhR*/
                                        /*when _2vEPbWPCAJU_1xk1toAGUy4:*/
                                        ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 1)))   //body when _2vEPbWPCAJU_1xk1toAGUy4
                                            {
//failure _8QmDbXEU8lU_33mrgrh3zUR
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                                    /*make_node 7 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[79] /*!arity*/)),

                                                                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[116] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
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
                                        (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[97] /*!value*/))))   //body when _3FcUnG66DXT_7sllObXQZl3
                                            {
//failure _9umIVqZhssC_2WJZljFrGaA
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[118] /*!failure_type_error*/)),
                                                                                    /*make_node 8 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[97] /*!value*/)),

                                                                                    ( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I),

                                                                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

// make_node arg #4
                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[119] /*|_9umIVqZhssC_2WJZljFrGaA*/)),
                                                                 ((struct stackframe_stBM *) &_));

                                            } //endwhen _3FcUnG66DXT_7sllObXQZl3
                                        /*endcond _6m3V5fOZK2n_9AFeHjYt2ZV*/


                                        break; // end when _5FrwHPgIxS4_6QYhDVrIvKP #5 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt

whenobj3WmrD9dW__88RDzd8IqdR_360tNT6O81m:; // when #6 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt
// objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _88RDzd8IqdR_360tNT6O81m #0 statement:
                                        if /*cond _5Z3dh9fajGI_8Mjr3quXaAc*/
                                        /*when _2ahnIdkMBrO_2xvuzm6XiD6:*/
                                        ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 0)))   //body when _2ahnIdkMBrO_2xvuzm6XiD6
                                            {
//failure _8QmDbXEU8lU_33mrgrh3zUR
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                                    /*make_node 7 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[79] /*!arity*/)),

                                                                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[116] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
                                                                 ((struct stackframe_stBM *) &_));

                                            } //endwhen _2ahnIdkMBrO_2xvuzm6XiD6
                                        /*endcond _5Z3dh9fajGI_8Mjr3quXaAc*/


                                        break; // end when _88RDzd8IqdR_360tNT6O81m #6 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt

whenobj3WmrD9dW__8v0XmN9JZTY_0xJ6ntfrc0z:; // when #7 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt
// objswitch _3WmrD9dWzVs_6l9CVwfdtYt when _8v0XmN9JZTY_0xJ6ntfrc0z #0 statement:
                                        if /*cond _0tPLTqqQhJ7_9Tr1hT1PRhR*/
                                        /*when _2vEPbWPCAJU_1xk1toAGUy4:*/
                                        ((/*unequal_int:*/(/*nodewidth:*/(intptr_t)nodewidth_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe)) != ( 1)))   //body when _2vEPbWPCAJU_1xk1toAGUy4
                                            {
//failure _8QmDbXEU8lU_33mrgrh3zUR
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                                    /*make_node 7 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[79] /*!arity*/)),

                                                                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[116] /*|_8QmDbXEU8lU_33mrgrh3zUR*/)),
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
                                        (/*unequal_object:*/(( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[59] /*!string*/))))   //body when _9BPjp8ame7V_0AzorRD9WNm
                                            {
//failure _4HAZLawO9HO_91oo1k4Ajat
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (8U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[118] /*!failure_type_error*/)),
                                                                                    /*make_node 8 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[59] /*!string*/)),

                                                                                    ( /*o_restype:*/_.o_0uATzRk8Ajt_6bIBwn6a86I),

                                                                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),

// make_node arg #4
                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[57] /*|_4HAZLawO9HO_91oo1k4Ajat*/)),
                                                                 ((struct stackframe_stBM *) &_));

                                            } //endwhen _9BPjp8ame7V_0AzorRD9WNm
                                        /*endcond _6cOi4TgZpEg_7mN9SsWpWte*/


                                        break; // end when _8v0XmN9JZTY_0xJ6ntfrc0z #7 of objswitch _3WmrD9dWzVs_6l9CVwfdtYt

                                    }
                            } // end objswitch _3WmrD9dWzVs_6l9CVwfdtYt

                        } //endwhen _7gliKK4XRvp_9hHvC2gJHKE
                    /*endcond _10BvirGtJ7c_4nWC6tymo1Z*/

// for-up _0tD16ZfI6r2_4QaWuN6poQA #3 :

                    {
                        // run _5D1l5MRqI8v_7r77JwJEhQz
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

                }
        } // end for-up _0tD16ZfI6r2_4QaWuN6poQA


        {
            // run _5Tgt53DTTR4_2cLi9xyVDWE
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
endblock__2z5wZyWhJId_3qRwMQOiLBm:
        ;
    } /*-block _2z5wZyWhJId_3qRwMQOiLBm */

epilog_1kz7viwMzTp_6PgLhdZzMEy:
    __attribute__ ((unused)); // routine _1kz7viwMzTp_6PgLhdZzMEy epilogue:
    // unlocking 1:
    if (locked_1mO4b6i93tJ_8qQI7qdBqdy != NULL)
        objunlock_BM(locked_1mO4b6i93tJ_8qQI7qdBqdy), locked_1mO4b6i93tJ_8qQI7qdBqdy = NULL; // for o_varout
    if (stkf) stkf->stkfram_callfun = NULL;
    return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _1kz7viwMzTp_6PgLhdZzMEy routine#7 _1kz7viwMzTp_6PgLhdZzMEy




value_tyBM crout_55k0ot2Zxca_48c9pjWuNWQ_BM //#8
(struct stackframe_stBM* stkf, //
//!emit_statement°basiclo_extractjsonstmt <o_stmt(o_modgen o_routprep v_depth)
 // 4 arguments
 const value_tyBM arg0,  // o_stmt
 const value_tyBM arg1,  // o_modgen
 const value_tyBM arg2,  // o_routprep
 const value_tyBM arg3,  // v_depth
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
    // start of _55k0ot2Zxca_48c9pjWuNWQ
    struct frame_55k0ot2Zxca_48c9pjWuNWQ_BMst
    {
        typedhead_tyBM stkfram_head;
        struct stackframe_stBM *stkfram_prev;
        objectval_tyBM *stkfram_descr;
        value_tyBM stkfram_callfun;
        int stkfram_state;
        int stkfram_extra;
        /// 12 local values:
        value_tyBM v_0qTBOEAT5pa_2fz1SKfHrMV; // v_resemit
        objectval_tyBM* o_0uATzRk8Ajt_6bIBwn6a86I; // o_restype
        value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
        objectval_tyBM* o_13K9OfeXRZR_84nyRTtoj81; // o_conn
        objectval_tyBM* o_1NOlyGkbWyD_5JUfiTznxM2; // o_substmt
        objectval_tyBM* o_2FRfGeiauCO_9CdjKseaigc; // o_jsvar
        objectval_tyBM* o_2RUj1oyJ2rf_1ICZWr844Sv; // o_modgen
        objectval_tyBM* o_34Qtvf1thwK_9rziG6sk6Vl; // o_stmt
        value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
        value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
        objectval_tyBM* o_6RpSqxAOt2p_35laNqeU6KH; // o_routprep
        value_tyBM v_9L1R3E9dI8L_6D8VI16BtDm; // v_extractor
        /// 3 local numbers:
        intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
        intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
        intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
        /// 0 scalar values:
    } _;
    memset (&_, 0, sizeof(struct frame_55k0ot2Zxca_48c9pjWuNWQ_BMst));
    _.stkfram_head.htyp = typayl_StackFrame_BM;
    _.stkfram_head.hgc = 0;
    _.stkfram_head.rlen = 12;
    _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[62] /*|_55k0ot2Zxca_48c9pjWuNWQ*/;
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
    // no closed values in _55k0ot2Zxca_48c9pjWuNWQ.
    const closure_tyBM* callclos_55k0ot2Zxca_48c9pjWuNWQ __attribute__((unused)) =
        (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
        ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
    const unsigned nbclosed_55k0ot2Zxca_48c9pjWuNWQ  __attribute__((unused)) = 0;
    // routine _55k0ot2Zxca_48c9pjWuNWQ body:

startblock__7M7FP9ekU4U_2PyaIgpAPcG:
    __attribute__((unused));
    {
        /* +block _7M7FP9ekU4U_2PyaIgpAPcG */
        /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _9UCpWRXllpw_4ClutKIdNOG
            /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ;



        {
            // run _7T3rglF55ms_2DtAHTozBA9
            /*debug emit_statement°basiclo_extractjsonstmt start o_stmt o_modgen o_routprep depth*/
            DBGPRINTF_BM("emit_statement°basiclo_extractjsonstmt start €%.9s o_stmt=%s\n... o_modgen=%s/L%u (lin.%d, col.%d last'%s') o_routprep=%s depth#%ld",
                         "_7T3rglF55ms_2DtAHTozBA9",
                         objectdbg_BM( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),
                         objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objstrbufferlinecountpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objstrbuffercolumnpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objstrbuffercurrentlastlinepayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objectdbg2_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                         (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;
        } // end run _7T3rglF55ms_2DtAHTozBA9

        /* !endingblock _7M7FP9ekU4U_2PyaIgpAPcG */
        goto endblock__7M7FP9ekU4U_2PyaIgpAPcG;
endblock__7M7FP9ekU4U_2PyaIgpAPcG:
        ;
    } /*-block _7M7FP9ekU4U_2PyaIgpAPcG */

epilog_55k0ot2Zxca_48c9pjWuNWQ:
    __attribute__ ((unused)); // routine _55k0ot2Zxca_48c9pjWuNWQ epilogue:
    if (stkf) stkf->stkfram_callfun = NULL;
    return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _55k0ot2Zxca_48c9pjWuNWQ routine#8 _55k0ot2Zxca_48c9pjWuNWQ




value_tyBM crout_5x0WWw3QRXe_8u5OLA7sKJG_BM //#9
(struct stackframe_stBM* stkf, //
//!miniscan_stmt°basiclo_extractjsonstmt < o_stmt (o_routprep v_depth o_from)
 // 4 arguments
 const value_tyBM arg0,  // o_stmt
 const value_tyBM arg1,  // o_routprep
 const value_tyBM arg2,  // v_depth
 const value_tyBM arg3,  // o_from
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
    // start of _5x0WWw3QRXe_8u5OLA7sKJG
    struct frame_5x0WWw3QRXe_8u5OLA7sKJG_BMst
    {
        typedhead_tyBM stkfram_head;
        struct stackframe_stBM *stkfram_prev;
        objectval_tyBM *stkfram_descr;
        value_tyBM stkfram_callfun;
        int stkfram_state;
        int stkfram_extra;
        /// 14 local values:
        objectval_tyBM* o_0uATzRk8Ajt_6bIBwn6a86I; // o_restype
        value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
        objectval_tyBM* o_13K9OfeXRZR_84nyRTtoj81; // o_conn
        objectval_tyBM* o_1xtK3luxH12_3zWtEuuvBAG; // o_stmtprops
        objectval_tyBM* o_2FRfGeiauCO_9CdjKseaigc; // o_jsvar
        objectval_tyBM* o_34Qtvf1thwK_9rziG6sk6Vl; // o_stmt
        value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
        value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
        value_tyBM v_5wKdFyGNJ5j_50nIjxm7LLY; // v_scanres
        objectval_tyBM* o_6Jkz6rphVkn_1KZto79j46r; // o_vihset
        objectval_tyBM* o_6RpSqxAOt2p_35laNqeU6KH; // o_routprep
        objectval_tyBM* o_89nz0KaXXZh_8eSgMmqnK37; // o_from
        value_tyBM v_96vo6uBKhke_6E1vyN3kIKD; // v_expctx
        value_tyBM v_9L1R3E9dI8L_6D8VI16BtDm; // v_extractor
        /// 3 local numbers:
        intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
        intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
        intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
        /// 0 scalar values:
    } _;
    memset (&_, 0, sizeof(struct frame_5x0WWw3QRXe_8u5OLA7sKJG_BMst));
    _.stkfram_head.htyp = typayl_StackFrame_BM;
    _.stkfram_head.hgc = 0;
    _.stkfram_head.rlen = 14;
    _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[69] /*|_5x0WWw3QRXe_8u5OLA7sKJG*/;
    ASSERT_BM (!stkf
               || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
               || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
    _.stkfram_prev = stkf;
    // locking 1:
    objectval_tyBM* locked_4BdrGEISZ5x_3EiC9UtUU6j = NULL; // for o_stmtprops
    // fetch 4 arguments:
    _.o_34Qtvf1thwK_9rziG6sk6Vl = objectcast_BM (arg0); // o_stmt
    _.o_6RpSqxAOt2p_35laNqeU6KH = objectcast_BM (arg1); // o_routprep
    _.v_4nJKFtMqlkA_1teQSqofNux = arg2; // v_depth
    _.o_89nz0KaXXZh_8eSgMmqnK37 = objectcast_BM (arg3); // o_from
    // fetched 4 arguments.
    // no closed values in _5x0WWw3QRXe_8u5OLA7sKJG.
    const closure_tyBM* callclos_5x0WWw3QRXe_8u5OLA7sKJG __attribute__((unused)) =
        (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
        ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
    const unsigned nbclosed_5x0WWw3QRXe_8u5OLA7sKJG  __attribute__((unused)) = 0;
    // routine _5x0WWw3QRXe_8u5OLA7sKJG body:

startblock__343D9JZkhoc_445lnDmWul4:
    __attribute__((unused));
    {
        /* +block _343D9JZkhoc_445lnDmWul4 */
        /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _74XT4f1vWl9_7pfkRaZCCjn
            /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ;


        /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _1a4rnGQ9X5p_4tJnSawMpZZ
            /*objnbcomps:*/ objnbcomps_BM ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl);

//+ #2/7 of block _343D9JZkhoc_445lnDmWul4 ::

        /*o_jsvar:*/_.o_2FRfGeiauCO_9CdjKseaigc = //assign _2JxwUzZQ2RV_8bQ2glsRJHp
            /*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[99] /*!json_object*/))));


        /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm = //assign _1FOTvzCLRJB_4QzK8cffadO
            /*objgetattr:*/objgetattr_BM(( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[86] /*!extract_json*/)));

//+ #4/7 of block _343D9JZkhoc_445lnDmWul4 ::

        /*o_stmtprops:*/_.o_1xtK3luxH12_3zWtEuuvBAG = //assign _9zk6qXScDWL_5w0SLx5QVxW
            /*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[13] /*!statement_properties*/))));



        {
            // run _3Uco7hC02N1_1PFcN4zQiuY
            /*miniscan_stmt°basiclo_extractjsonstmt start o_stmt o_routprep depth o_from leni o_jsvar v_extractor o_stmtprops*/
            DBGPRINTF_BM("debug miniscan_stmt°basiclo_extractjsonstmt start €%.9s o_stmt=%s o_routprep=%s depth#%ld o_from=%s leni#%ld o_jsvar=%s v_extractor=%s o_stmtprops=%s",
                         "_3Uco7hC02N1_1PFcN4zQiuY",
                         objectdbg_BM( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),
                         objectdbg1_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                         (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
                         objectdbg2_BM( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37),
                         (long int) ( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k),
                         objectdbg3_BM( /*o_jsvar:*/_.o_2FRfGeiauCO_9CdjKseaigc),
                         OUTSTRVALUE_BM( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),
                         objectdbg4_BM( /*o_stmtprops:*/_.o_1xtK3luxH12_3zWtEuuvBAG));
            ;
        } // end run _3Uco7hC02N1_1PFcN4zQiuY



        {
            // begin lockobj _4BdrGEISZ5x_3EiC9UtUU6j
            objectval_tyBM* curlockedob_4BdrGEISZ5x_3EiC9UtUU6j = ( /*o_stmtprops:*/_.o_1xtK3luxH12_3zWtEuuvBAG);
            if (objlock_BM (curlockedob_4BdrGEISZ5x_3EiC9UtUU6j))
                {
                    locked_4BdrGEISZ5x_3EiC9UtUU6j = curlockedob_4BdrGEISZ5x_3EiC9UtUU6j;


                    {
                        // run _7OwvVlij1oe_0ei0s7DWjbm
                        /*weakasserts about o_stmtprops:*/
                        WEAKASSERT_BM(isobject_BM ( /*o_stmtprops:*/_.o_1xtK3luxH12_3zWtEuuvBAG));
                        WEAKASSERT_BM(objhasassocpayl_BM( /*o_stmtprops:*/_.o_1xtK3luxH12_3zWtEuuvBAG));
                        ;
                    } // end run _7OwvVlij1oe_0ei0s7DWjbm

                    /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r = //assign _07IexIiZKaA_2Bdpdoo87IO
                        /*val_to_object:*/objectcast_BM(/*objassocgetattrpayl:*/objassocgetattrpayl_BM (( /*o_stmtprops:*/_.o_1xtK3luxH12_3zWtEuuvBAG), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl)));

//+ #2/10 of lockobj _4BdrGEISZ5x_3EiC9UtUU6j ::
                    if /*cond _6JQv7ElQK7r_5e0wCzqDKKh*/
                    /*when _273t0HkMfFy_6LdqTPGkLmP:*/
                    ( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r)   //body when _273t0HkMfFy_6LdqTPGkLmP
                        {
//failure _2JGuJeX3rdZ_193JJPCC8Jh
                            PLACEDFAILURE_BM(__LINE__,
                                             /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                               (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[39] /*!duplicate*/)),
                                                                /*make_node 7 sons:*/
                                                                ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[69] /*!_5x0WWw3QRXe_8u5OLA7sKJG*/)),

                                                                ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                ( /*o_stmtprops:*/_.o_1xtK3luxH12_3zWtEuuvBAG),

// make_node arg #4
                                                                ( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),

                                                                ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[35] /*|_2JGuJeX3rdZ_193JJPCC8Jh*/)),
                                             ((struct stackframe_stBM *) &_));

                        } //endwhen _273t0HkMfFy_6LdqTPGkLmP
                    /*endcond _6JQv7ElQK7r_5e0wCzqDKKh*/

                    /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r = //assign _0nXPELF2Nor_1AuyYzJUjpU
                        /*makeobj:*/makeobj_BM();

//+ #4/10 of lockobj _4BdrGEISZ5x_3EiC9UtUU6j ::
                    {
                        // start cexpansion _2i32BebJ6xg_6L8P7oUtpf1 - objputclass
                        /*objputclass:*/objputclass_BM(( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[34] /*!hashset_jsonvar_object*/)));
                    } // end cexpansion _2i32BebJ6xg_6L8P7oUtpf1 - objputclass

                    {
                        // start cexpansion _7Lfm3bWaxHL_4f6DPOofzjy - objputattr
                        /*objputattr:*/objputattr_BM(( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[82] /*!prepare_routine*/)),( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH));
                    } // end cexpansion _7Lfm3bWaxHL_4f6DPOofzjy - objputattr

//+ #6/10 of lockobj _4BdrGEISZ5x_3EiC9UtUU6j ::
                    {
                        // start cexpansion _37x3JrJ8BBx_6ffpUzc2Dg4 - objputattr
                        /*objputattr:*/objputattr_BM(( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[23] /*!from*/)),( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37));
                    } // end cexpansion _37x3JrJ8BBx_6ffpUzc2Dg4 - objputattr

                    {
                        // start cexpansion _4tF0ZKRbDxU_2TzHVlZ9NST - objputattr
                        /*objputattr:*/objputattr_BM(( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[5] /*!in*/)),( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl));
                    } // end cexpansion _4tF0ZKRbDxU_2TzHVlZ9NST - objputattr

//+ #8/10 of lockobj _4BdrGEISZ5x_3EiC9UtUU6j ::
                    {
                        // start cexpansion _1HKl9lZR2aw_1KkpPkpukWl - objhashsetvalreorganizepayl
                        /*objhashsetvalreorganizepayl:*/ objhashsetvalreorganizepayl_BM(( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r), (unsigned) ( 10));
                    } // end cexpansion _1HKl9lZR2aw_1KkpPkpukWl - objhashsetvalreorganizepayl

                    {
                        // start cexpansion _6715Z3M2AHB_66NnKpXBC2J - objassocaddattrpayl
                        /*objassocaddattrpayl:*/ objassocaddattrpayl_BM(( /*o_stmtprops:*/_.o_1xtK3luxH12_3zWtEuuvBAG),( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r));
                    } // end cexpansion _6715Z3M2AHB_66NnKpXBC2J - objassocaddattrpayl

                    objunlock_BM (locked_4BdrGEISZ5x_3EiC9UtUU6j), locked_4BdrGEISZ5x_3EiC9UtUU6j = NULL;
                }
        } // end objlock _4BdrGEISZ5x_3EiC9UtUU6j
        /* !endingblock _343D9JZkhoc_445lnDmWul4 */
        goto endblock__343D9JZkhoc_445lnDmWul4;
endblock__343D9JZkhoc_445lnDmWul4:
        ;
    } /*-block _343D9JZkhoc_445lnDmWul4 */

epilog_5x0WWw3QRXe_8u5OLA7sKJG:
    __attribute__ ((unused)); // routine _5x0WWw3QRXe_8u5OLA7sKJG epilogue:
    // unlocking 1:
    if (locked_4BdrGEISZ5x_3EiC9UtUU6j != NULL)
        objunlock_BM(locked_4BdrGEISZ5x_3EiC9UtUU6j), locked_4BdrGEISZ5x_3EiC9UtUU6j = NULL; // for o_stmtprops
    if (stkf) stkf->stkfram_callfun = NULL;
    return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _5x0WWw3QRXe_8u5OLA7sKJG routine#9 _5x0WWw3QRXe_8u5OLA7sKJG




value_tyBM crout_73hC7TDRQc7_7AAWITxnirb_BM //#10
(struct stackframe_stBM* stkf, //
//!miniscan_json_extractor(v_extractor o_vihset v_depth)
 // 3 arguments
 const value_tyBM arg0,  // v_extractor
 const value_tyBM arg1,  // o_vihset
 const value_tyBM arg2,  // v_depth
 const value_tyBM arg3_ __attribute__((unused)),
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
    // start of _73hC7TDRQc7_7AAWITxnirb
    struct frame_73hC7TDRQc7_7AAWITxnirb_BMst
    {
        typedhead_tyBM stkfram_head;
        struct stackframe_stBM *stkfram_prev;
        objectval_tyBM *stkfram_descr;
        value_tyBM stkfram_callfun;
        int stkfram_state;
        int stkfram_extra;
        /// 14 local values:
        value_tyBM v_0ZL8gaI6sH8_7UPhmAQcwMe; // v_comp
        objectval_tyBM* o_13K9OfeXRZR_84nyRTtoj81; // o_conn
        value_tyBM v_167WczZjWtG_3FofhJxQWJi; // v_str
        value_tyBM v_2BkOxf2KbS8_3bswrKbmgjy; // v_node
        objectval_tyBM* o_34Qtvf1thwK_9rziG6sk6Vl; // o_stmt
        value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
        value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
        value_tyBM v_4vxTzYY836O_03Zx8TO4YLy; // v_subextractor
        value_tyBM v_5wKdFyGNJ5j_50nIjxm7LLY; // v_scanres
        value_tyBM v_6CmIdtsXyBX_3lpk31Mve5M; // v_expr
        objectval_tyBM* o_6Jkz6rphVkn_1KZto79j46r; // o_vihset
        objectval_tyBM* o_6RpSqxAOt2p_35laNqeU6KH; // o_routprep
        objectval_tyBM* o_7safxUAyjq9_7LcGUlnwwD1; // o_variable
        value_tyBM v_9L1R3E9dI8L_6D8VI16BtDm; // v_extractor
        /// 3 local numbers:
        intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
        intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
        intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
        /// 0 scalar values:
    } _;
    memset (&_, 0, sizeof(struct frame_73hC7TDRQc7_7AAWITxnirb_BMst));
    _.stkfram_head.htyp = typayl_StackFrame_BM;
    _.stkfram_head.hgc = 0;
    _.stkfram_head.rlen = 14;
    _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[95] /*|_73hC7TDRQc7_7AAWITxnirb*/;
    ASSERT_BM (!stkf
               || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
               || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
    _.stkfram_prev = stkf;
    // fetch 3 arguments:
    _.v_9L1R3E9dI8L_6D8VI16BtDm = arg0; // v_extractor
    _.o_6Jkz6rphVkn_1KZto79j46r = objectcast_BM (arg1); // o_vihset
    _.v_4nJKFtMqlkA_1teQSqofNux = arg2; // v_depth
    // fetched 3 arguments.
    // no closed values in _73hC7TDRQc7_7AAWITxnirb.
    const closure_tyBM* callclos_73hC7TDRQc7_7AAWITxnirb __attribute__((unused)) =
        (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
        ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
    const unsigned nbclosed_73hC7TDRQc7_7AAWITxnirb  __attribute__((unused)) = 0;
    // routine _73hC7TDRQc7_7AAWITxnirb body:

startblock__12FSPZ0qRUL_0iXrZB1pEB7:
    __attribute__((unused));
    {
        /* +block _12FSPZ0qRUL_0iXrZB1pEB7 */
        /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _74XT4f1vWl9_7pfkRaZCCjn
            /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ;


        /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl = //assign _7DsnXgxaurX_5dxoI6CqUAz
            /*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[5] /*!in*/))));

//+ #2/9 of block _12FSPZ0qRUL_0iXrZB1pEB7 ::

        /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH = //assign _1ogiqA5yuFO_4bdmkL2sI9n
            /*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[82] /*!prepare_routine*/))));



        {
            // run _61zy52rNVsI_2P6SMlpgPOx
            /*debug miniscan_json_extractor start v_extractor o_vihset depth; o_stmt o_routprep*/
            DBGPRINTF_BM("miniscan_json_extractor start €%.9s v_extractor=%s o_vihset=%s depth#%ld; o_stmt=%s o_routprep=%s",
                         "_61zy52rNVsI_2P6SMlpgPOx",
                         OUTSTRVALUE_BM( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),
                         objectdbg_BM( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),
                         (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
                         objectdbg1_BM( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),
                         objectdbg2_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH));;
        } // end run _61zy52rNVsI_2P6SMlpgPOx

//+ #4/9 of block _12FSPZ0qRUL_0iXrZB1pEB7 ::

        /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81 = //assign _2ODrqjM74Ti_7kZOmh7FmKw
            /*nodeconn:*/nodeconn_BM( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm);


        if /*cond _0NIwuDyzxsO_935ZagzKR6G*/
        /*when _5EOAlsC0enM_1OE8KBstbWu:*/
        (/*is_null:*/(( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81)==NULL))   //body when _5EOAlsC0enM_1OE8KBstbWu
            {
//failure _7WynVNCkQpd_4DPrtlIjox3
                PLACEDFAILURE_BM(__LINE__,
                                 /*failreason:*/ (((value_tyBM) makenode4_BM
                                                   (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[118] /*!failure_type_error*/)),
                                                           /*make_node 4 sons:*/
                                                           ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[95] /*!_73hC7TDRQc7_7AAWITxnirb*/)),

                                                           ( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),

                                                           ( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),

                                                           (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[108] /*|_7WynVNCkQpd_4DPrtlIjox3*/)),
                                 ((struct stackframe_stBM *) &_));

            } //endwhen _5EOAlsC0enM_1OE8KBstbWu
        else if
        /*when _1Nq8cCeqVKd_1wOZ5CorWgB:*/
        ((/*greater_int:*/( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) > ( 100)))   //body when _1Nq8cCeqVKd_1wOZ5CorWgB
            {
//failure _9Zrfsj91qog_1eIHNIe3Fjo
                PLACEDFAILURE_BM(__LINE__,
                                 /*failreason:*/ (((value_tyBM) makenode4_BM
                                                   (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[114] /*!failure_bad_rank*/)),
                                                           /*make_node 4 sons:*/
                                                           ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[95] /*!_73hC7TDRQc7_7AAWITxnirb*/)),

                                                           ( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),

                                                           ( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),

                                                           (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[123] /*|_9Zrfsj91qog_1eIHNIe3Fjo*/)),
                                 ((struct stackframe_stBM *) &_));

            } //endwhen _1Nq8cCeqVKd_1wOZ5CorWgB
        /*endcond _0NIwuDyzxsO_935ZagzKR6G*/

//+ #6/9 of block _12FSPZ0qRUL_0iXrZB1pEB7 ::

        /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _2vEZRv41Cco_5FKDY4RRUEQ
            /*nodewidth:*/(intptr_t)nodewidth_BM( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm);



        {
            // begin objswitch _8kMEBcfqeWz_5JRhiMICep2
//!objswitch! objswitch o_conn // miniscan_json_extractor .
            objectval_tyBM* objswexp_8kMEBcfqeWz_5JRhiMICep2 = ( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81);
            switch (objecthash_BM (objswexp_8kMEBcfqeWz_5JRhiMICep2) % 32)
                {
                case 1:
                    if (objswexp_8kMEBcfqeWz_5JRhiMICep2 ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[29] /*|set*/)) goto whenobj8kMEBcfq__2sqV9Dl4VRQ_1ToexeWybdB;
                    goto defobj_8kMEBcfqeWz_5JRhiMICep2;
                case 5:
                    if (objswexp_8kMEBcfqeWz_5JRhiMICep2 ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[43] /*|json_entry_object*/)) goto whenobj8kMEBcfq__6EpJ2KoyuiU_8s0JUiNhxei;
                    if (objswexp_8kMEBcfqeWz_5JRhiMICep2 ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[93] /*|json_null*/)) goto whenobj8kMEBcfq__2bMHBytN5Xo_5RIQJZTjsYf;
                    goto defobj_8kMEBcfqeWz_5JRhiMICep2;
                case 10:
                    if (objswexp_8kMEBcfqeWz_5JRhiMICep2 ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[99] /*|json_object*/)) goto whenobj8kMEBcfq__1keBRJyZiEA_7lQUiazpMnA;
                    goto defobj_8kMEBcfqeWz_5JRhiMICep2;
                case 12:
                    if (objswexp_8kMEBcfqeWz_5JRhiMICep2 ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[63] /*|json_array*/)) goto whenobj8kMEBcfq__1keBRJyZiEA_7lQUiazpMnA;
                    goto defobj_8kMEBcfqeWz_5JRhiMICep2;
                case 13:
                    if (objswexp_8kMEBcfqeWz_5JRhiMICep2 ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[90] /*|and_then*/)) goto whenobj8kMEBcfq__1keBRJyZiEA_7lQUiazpMnA;
                    goto defobj_8kMEBcfqeWz_5JRhiMICep2;
                case 16:
                    if (objswexp_8kMEBcfqeWz_5JRhiMICep2 ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[16] /*|json_false*/)) goto whenobj8kMEBcfq__2bMHBytN5Xo_5RIQJZTjsYf;
                    goto defobj_8kMEBcfqeWz_5JRhiMICep2;
                case 22:
                    if (objswexp_8kMEBcfqeWz_5JRhiMICep2 ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[3] /*|json_true*/)) goto whenobj8kMEBcfq__2bMHBytN5Xo_5RIQJZTjsYf;
                    if (objswexp_8kMEBcfqeWz_5JRhiMICep2 ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[30] /*|double_float*/)) goto whenobj8kMEBcfq__2sqV9Dl4VRQ_1ToexeWybdB;
                    goto defobj_8kMEBcfqeWz_5JRhiMICep2;
                case 23:
                    if (objswexp_8kMEBcfqeWz_5JRhiMICep2 ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[59] /*|string*/)) goto whenobj8kMEBcfq__2sqV9Dl4VRQ_1ToexeWybdB;
                    goto defobj_8kMEBcfqeWz_5JRhiMICep2;
                case 25:
                    if (objswexp_8kMEBcfqeWz_5JRhiMICep2 ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[74] /*|json_value*/)) goto whenobj8kMEBcfq__2sqV9Dl4VRQ_1ToexeWybdB;
                    goto defobj_8kMEBcfqeWz_5JRhiMICep2;
                case 26:
                    if (objswexp_8kMEBcfqeWz_5JRhiMICep2 ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[40] /*|or_else*/)) goto whenobj8kMEBcfq__1keBRJyZiEA_7lQUiazpMnA;
                    goto defobj_8kMEBcfqeWz_5JRhiMICep2;
                case 30:
                    if (objswexp_8kMEBcfqeWz_5JRhiMICep2 ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[8] /*|int*/)) goto whenobj8kMEBcfq__8M0gq6Ilc80_7xXcAmJOstP;
                    if (objswexp_8kMEBcfqeWz_5JRhiMICep2 ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[96] /*|json_entry*/)) goto whenobj8kMEBcfq__6EpJ2KoyuiU_8s0JUiNhxei;
                    goto defobj_8kMEBcfqeWz_5JRhiMICep2;
                case 31:
                    if (objswexp_8kMEBcfqeWz_5JRhiMICep2 ==  (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[97] /*|value*/)) goto whenobj8kMEBcfq__2sqV9Dl4VRQ_1ToexeWybdB;
                    goto defobj_8kMEBcfqeWz_5JRhiMICep2;

                default:
defobj_8kMEBcfqeWz_5JRhiMICep2:
                    ;

                    break; // end objswitch _8kMEBcfqeWz_5JRhiMICep2 default
// objswitch _8kMEBcfqeWz_5JRhiMICep2 with 5 whens:

whenobj8kMEBcfq__1keBRJyZiEA_7lQUiazpMnA:; // when #0 of objswitch _8kMEBcfqeWz_5JRhiMICep2
// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _1keBRJyZiEA_7lQUiazpMnA #0 statement:

                    {
                        // run _0TCp6EYAFhx_8oomGup3w0i
                        /*debug miniscan_json_extractor variadic-extractor v_extractor o_vihset depth*/
                        DBGPRINTF_BM(" miniscan_json_extractor variadic-extractor €%.9s v_extractor=%s o_vihset=%s depth#%ld",
                                     "_0TCp6EYAFhx_8oomGup3w0i",
                                     OUTSTRVALUE_BM( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),
                                     objectdbg_BM( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),
                                     (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;
                    } // end run _0TCp6EYAFhx_8oomGup3w0i

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _1keBRJyZiEA_7lQUiazpMnA #1 statement:
                    /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY = //assign _4vI97FeROeO_7sERP0mphxF
                        (apply4_BM (( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[95] /*!_73hC7TDRQc7_7AAWITxnirb*/)), ((struct stackframe_stBM*)&_),
                                    ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),  ( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),
                                    (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1)))),
                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl)));

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _1keBRJyZiEA_7lQUiazpMnA #2 statement:

                    {
                        // run _5xe30X7Os4M_8bGDeAnqyD8
                        /*debug miniscan_json_extractor end variadic extractor o_conn v_extractor o_vihset depth*/
                        DBGPRINTF_BM("miniscan_json_extractor end variadic extractor €%.9s o_conn=%s v_extractor=%s o_vihset=%s depth#%ld\n",
                                     "_5xe30X7Os4M_8bGDeAnqyD8",
                                     objectdbg_BM( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),
                                     OUTSTRVALUE_BM( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),
                                     objectdbg1_BM( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),
                                     (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;
                    } // end run _5xe30X7Os4M_8bGDeAnqyD8

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _1keBRJyZiEA_7lQUiazpMnA #3 statement:
                    /*return _3D75CSHww0u_5ePusHYW8c7:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned
                        /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81;
                    goto epilog_73hC7TDRQc7_7AAWITxnirb;


                    break; // end when _1keBRJyZiEA_7lQUiazpMnA #0 of objswitch _8kMEBcfqeWz_5JRhiMICep2

whenobj8kMEBcfq__2bMHBytN5Xo_5RIQJZTjsYf:; // when #1 of objswitch _8kMEBcfqeWz_5JRhiMICep2
// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _2bMHBytN5Xo_5RIQJZTjsYf #0 statement:
                    if /*cond _913NZfIY3g1_8w9IxFmtXd9*/
                    /*when _80QjHBKCbjh_8MDhSwLqFBI:*/
                    ((/*greater_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) > ( 0)))   //body when _80QjHBKCbjh_8MDhSwLqFBI
                        {
//failure _5oysKNBbMrG_0dniL1OrlJz
                            PLACEDFAILURE_BM(__LINE__,
                                             /*failreason:*/ (((value_tyBM) makenode5_BM
                                                               (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[114] /*!failure_bad_rank*/)),
                                                                       /*make_node 5 sons:*/
                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[95] /*!_73hC7TDRQc7_7AAWITxnirb*/)),

                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[64] /*!constants*/)),

                                                                       ( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),

// make_node arg #4
                                                                       ( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),

                                                                       (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[65] /*|_5oysKNBbMrG_0dniL1OrlJz*/)),
                                             ((struct stackframe_stBM *) &_));

                        } //endwhen _80QjHBKCbjh_8MDhSwLqFBI
                    /*endcond _913NZfIY3g1_8w9IxFmtXd9*/

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _2bMHBytN5Xo_5RIQJZTjsYf #1 statement:

                    {
                        // run _4jcWx6AizVD_2nzqO7HNWzC
                        /*debug 0arity end miniscan_json_extractor o_conn v_extractor o_vihset depth*/
                        DBGPRINTF_BM("miniscan_json_extractor €%.9s 0arity end o_conn=%s v_extractor=%s o_vihset=%s depth#%ld",
                                     "_4jcWx6AizVD_2nzqO7HNWzC",
                                     objectdbg_BM( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),
                                     OUTSTRVALUE_BM( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),
                                     objectdbg1_BM( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),
                                     (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;
                    } // end run _4jcWx6AizVD_2nzqO7HNWzC

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _2bMHBytN5Xo_5RIQJZTjsYf #2 statement:
                    /*return _311DkeU7Shp_2f2UWlPnBy4:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned
                        /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81;
                    goto epilog_73hC7TDRQc7_7AAWITxnirb;


                    break; // end when _2bMHBytN5Xo_5RIQJZTjsYf #1 of objswitch _8kMEBcfqeWz_5JRhiMICep2

whenobj8kMEBcfq__2sqV9Dl4VRQ_1ToexeWybdB:; // when #2 of objswitch _8kMEBcfqeWz_5JRhiMICep2
// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _2sqV9Dl4VRQ_1ToexeWybdB #0 statement:
                    if /*cond _3H6PzuYCBcL_7VzbmMdP4Xa*/
                    /*when _8pmGJQw3Lvk_5BqxiCFx4o2:*/
                    ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1)))   //body when _8pmGJQw3Lvk_5BqxiCFx4o2
                        {
//failure _8M5QuJZid40_07X694Ezsiz
                            PLACEDFAILURE_BM(__LINE__,
                                             /*failreason:*/ (((value_tyBM) makenode5_BM
                                                               (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[114] /*!failure_bad_rank*/)),
                                                                       /*make_node 5 sons:*/
                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[95] /*!_73hC7TDRQc7_7AAWITxnirb*/)),

                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[97] /*!value*/)),

                                                                       ( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),

// make_node arg #4
                                                                       ( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),

                                                                       (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[113] /*|_8M5QuJZid40_07X694Ezsiz*/)),
                                             ((struct stackframe_stBM *) &_));

                        } //endwhen _8pmGJQw3Lvk_5BqxiCFx4o2
                    /*endcond _3H6PzuYCBcL_7VzbmMdP4Xa*/

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _2sqV9Dl4VRQ_1ToexeWybdB #1 statement:
                    /*o_variable:*/_.o_7safxUAyjq9_7LcGUlnwwD1 = //assign _67sfJmZYsXE_9I3vYI8eJEH
                        /*val_to_object:*/objectcast_BM(/*nodenthson:*/nodenthson_BM(( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),( 0)));

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _2sqV9Dl4VRQ_1ToexeWybdB #2 statement:
                    if /*cond _96Y5nrwoje7_1e4LZNxQTQX*/
                    /*when _7XgxvQc17Dc_71t90fzpUvV:*/
                    (/*is_null:*/(( /*o_variable:*/_.o_7safxUAyjq9_7LcGUlnwwD1)==NULL))   //body when _7XgxvQc17Dc_71t90fzpUvV
                        {
//failure _7usb01gzlIN_2l3H7qTAe1g
                            PLACEDFAILURE_BM(__LINE__,
                                             /*failreason:*/ (((value_tyBM) makenode5_BM
                                                               (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                       /*make_node 5 sons:*/
                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[95] /*!_73hC7TDRQc7_7AAWITxnirb*/)),

                                                                       ( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),

                                                                       ( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),

// make_node arg #4
                                                                       ( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),

                                                                       (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[102] /*|_7usb01gzlIN_2l3H7qTAe1g*/)),
                                             ((struct stackframe_stBM *) &_));

                        } //endwhen _7XgxvQc17Dc_71t90fzpUvV
                    /*endcond _96Y5nrwoje7_1e4LZNxQTQX*/

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _2sqV9Dl4VRQ_1ToexeWybdB #3 statement:

                    {
                        // run _4G7iJdXK8IT_8oz8HiLEuGe
                        /*debug 1-arity value miniscan_json_extractor o_variable v_extractor o_vihset depth*/
                        DBGPRINTF_BM("1-arity value miniscan_json_extractor €%.9s o_variable=%s v_extractor=%s o_vihset=%s depth#%ld",
                                     "_4G7iJdXK8IT_8oz8HiLEuGe",
                                     objectdbg_BM( /*o_variable:*/_.o_7safxUAyjq9_7LcGUlnwwD1),
                                     OUTSTRVALUE_BM( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),
                                     objectdbg1_BM( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),
                                     (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;
                    } // end run _4G7iJdXK8IT_8oz8HiLEuGe

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _2sqV9Dl4VRQ_1ToexeWybdB #4 statement:
                    /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY = //assign _4zlASReWgsz_4NpSAjjGIgw
                        /*miniscan_var:*/ miniscan_var_BM (( /*o_variable:*/_.o_7safxUAyjq9_7LcGUlnwwD1), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM);

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _2sqV9Dl4VRQ_1ToexeWybdB #5 statement:

                    {
                        // run _7cSLFpnscio_8FATJyYSrAD
                        /*debug 1-arity value miniscan_json_extractor v_scanres o_variable v_extractor o_vihset depth*/
                        DBGPRINTF_BM("1-arity value miniscan_json_extractor €%.9s v_scanres=%s o_variable=%s v_extractor=%s o_vihset=%s depth#%ld",
                                     "_7cSLFpnscio_8FATJyYSrAD",
                                     OUTSTRVALUE_BM( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY),
                                     objectdbg_BM( /*o_variable:*/_.o_7safxUAyjq9_7LcGUlnwwD1),
                                     OUTSTRVALUE_BM( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),
                                     objectdbg1_BM( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),
                                     (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;
                    } // end run _7cSLFpnscio_8FATJyYSrAD

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _2sqV9Dl4VRQ_1ToexeWybdB #6 statement:
                    if /*cond _0QkzNYmsGFf_67FqhVSfLLQ*/
                    /*when _3mhbc6zSSsi_0TXfPz5gNu5:*/
                    (/*unequal_value*/(( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[97] /*!value*/))))   //body when _3mhbc6zSSsi_0TXfPz5gNu5
                        {
//failure _6XhkvXDG3ac_5qqvPwzOjKh
                            PLACEDFAILURE_BM(__LINE__,
                                             /*failreason:*/ (((value_tyBM) makenode6_BM
                                                               (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[118] /*!failure_type_error*/)),
                                                                       /*make_node 6 sons:*/
                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[95] /*!_73hC7TDRQc7_7AAWITxnirb*/)),

                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[97] /*!value*/)),

                                                                       ( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY),

// make_node arg #4
                                                                       ( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),

                                                                       ( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),

                                                                       (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[94] /*|_6XhkvXDG3ac_5qqvPwzOjKh*/)),
                                             ((struct stackframe_stBM *) &_));

                        } //endwhen _3mhbc6zSSsi_0TXfPz5gNu5
                    /*endcond _0QkzNYmsGFf_67FqhVSfLLQ*/

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _2sqV9Dl4VRQ_1ToexeWybdB #7 statement:
                    {
                        // start cexpansion _0aXCagClstN_7ZzZJshvTWn - objhashsetaddpayl
                        /*objhashsetaddpayl:*/ objhashsetaddpayl_BM (( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r), ( /*o_variable:*/_.o_7safxUAyjq9_7LcGUlnwwD1));
                    } // end cexpansion _0aXCagClstN_7ZzZJshvTWn - objhashsetaddpayl

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _2sqV9Dl4VRQ_1ToexeWybdB #8 statement:
                    /*return _1LlXUsmU5LA_63prt17MkZy:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned
                        /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY;
                    goto epilog_73hC7TDRQc7_7AAWITxnirb;


                    break; // end when _2sqV9Dl4VRQ_1ToexeWybdB #2 of objswitch _8kMEBcfqeWz_5JRhiMICep2

whenobj8kMEBcfq__6EpJ2KoyuiU_8s0JUiNhxei:; // when #3 of objswitch _8kMEBcfqeWz_5JRhiMICep2
// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _6EpJ2KoyuiU_8s0JUiNhxei #0 statement:
                    if /*cond _6UhYwDJja6O_9INWrGwiLpv*/
                    /*when _6emmALpqE2n_3Lsv1b9cd16:*/
                    ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 2)))   //body when _6emmALpqE2n_3Lsv1b9cd16
                        {
//failure _4Khc0e9fPzW_1PzgQNc07d6
                            PLACEDFAILURE_BM(__LINE__,
                                             /*failreason:*/ (((value_tyBM) makenode5_BM
                                                               (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[114] /*!failure_bad_rank*/)),
                                                                       /*make_node 5 sons:*/
                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[95] /*!_73hC7TDRQc7_7AAWITxnirb*/)),

                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[96] /*!json_entry*/)),

                                                                       ( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),

// make_node arg #4
                                                                       ( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),

                                                                       (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[58] /*|_4Khc0e9fPzW_1PzgQNc07d6*/)),
                                             ((struct stackframe_stBM *) &_));

                        } //endwhen _6emmALpqE2n_3Lsv1b9cd16
                    /*endcond _6UhYwDJja6O_9INWrGwiLpv*/

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _6EpJ2KoyuiU_8s0JUiNhxei #1 statement:
                    /*v_expr:*/_.v_6CmIdtsXyBX_3lpk31Mve5M = //assign _1Ldv1NmrfhQ_27rJjZI8H8T
                        /*nodenthson:*/nodenthson_BM(( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),( 0));

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _6EpJ2KoyuiU_8s0JUiNhxei #2 statement:
                    /*v_subextractor:*/_.v_4vxTzYY836O_03Zx8TO4YLy = //assign _3zIPh1A3yCC_0RFMeN2cBFq
                        /*nodenthson:*/nodenthson_BM(( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),( 1));

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _6EpJ2KoyuiU_8s0JUiNhxei #3 statement:

                    {
                        // run _6JoruTt0zcz_58tnnEJzOO1
                        /*debug miniscan_json_extractor json_entry: v_extractor v_expr v_subextractor o_vihset depth o_routprep*/
                        DBGPRINTF_BM("miniscan_json_extractor json_entry €%.9s: v_extractor=%s v_expr=%s v_subextractor=%s o_vihset=%s depth=#%ld, o_routprep=%s",
                                     "_6JoruTt0zcz_58tnnEJzOO1",
                                     OUTSTRVALUE_BM( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),
                                     OUTSTRVALUE_BM( /*v_expr:*/_.v_6CmIdtsXyBX_3lpk31Mve5M),
                                     OUTSTRVALUE_BM( /*v_subextractor:*/_.v_4vxTzYY836O_03Zx8TO4YLy),
                                     objectdbg_BM( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),
                                     (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
                                     objectdbg1_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH)
                                    );;
                    } // end run _6JoruTt0zcz_58tnnEJzOO1

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _6EpJ2KoyuiU_8s0JUiNhxei #4 statement:
                    /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY = //assign _5mIduBO76BI_4bP7I0OowLW
                        /*miniscan_expr:*/miniscan_expr_BM (( /*v_expr:*/_.v_6CmIdtsXyBX_3lpk31Mve5M), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM);

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _6EpJ2KoyuiU_8s0JUiNhxei #5 statement:

                    {
                        // run _1S7kvxv8MCN_3lJLGLRum4c
                        /*debug miniscan_json_extractor json_entry after miniscan_expr: v_scanres v_extractor v_expr o_vihset depth, o_routprep*/
                        DBGPRINTF_BM("miniscan_json_extractor json_entry after miniscan_expr €%.9s: v_scanres=%s v_extractor=%s v_expr=%s o_vihset=%s depth#%ld, o_routprep=%s",
                                     "_1S7kvxv8MCN_3lJLGLRum4c",
                                     OUTSTRVALUE_BM( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY),
                                     OUTSTRVALUE_BM( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),
                                     OUTSTRVALUE_BM( /*v_expr:*/_.v_6CmIdtsXyBX_3lpk31Mve5M),
                                     objectdbg_BM( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),
                                     (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
                                     objectdbg1_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH));;
                    } // end run _1S7kvxv8MCN_3lJLGLRum4c

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _6EpJ2KoyuiU_8s0JUiNhxei #6 statement:
                    if /*cond _84tedeXfEqr_9UXnBhy3AZO*/
                    /*when _52JVWS59lpI_9b8pXDI10Pr:*/
                    (/*not:*/ (! (/*lazy or_else:*/ (intptr_t) (0 || (/*lazy and_then:*/ (intptr_t) (1 && ((/*equal_val:*/valequal_BM(( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[59] /*!string*/))))) && (/*equal_object:*/(( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81) == ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[96] /*!json_entry*/)))))) || (/*lazy and_then:*/ (intptr_t) (1 && ((/*equal_val:*/valequal_BM(( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[105] /*!object*/))))) && (/*equal_object:*/(( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81) == ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[43] /*!json_entry_object*/))))))))))   //body when _52JVWS59lpI_9b8pXDI10Pr
                        {
//failure _7TlPdNzYigl_2djAOJ1SLjA
                            PLACEDFAILURE_BM(__LINE__,
                                             /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                               (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[118] /*!failure_type_error*/)),
                                                                /*make_node 7 sons:*/
                                                                ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[95] /*!_73hC7TDRQc7_7AAWITxnirb*/)),

                                                                ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[96] /*!json_entry*/)),

                                                                ( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),

// make_node arg #4
                                                                ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[59] /*!string*/)),

                                                                ( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),

                                                                (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                                ( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY)))),
                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[106] /*|_7TlPdNzYigl_2djAOJ1SLjA*/)),
                                             ((struct stackframe_stBM *) &_));

                        } //endwhen _52JVWS59lpI_9b8pXDI10Pr
                    /*endcond _84tedeXfEqr_9UXnBhy3AZO*/

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _6EpJ2KoyuiU_8s0JUiNhxei #7 statement:
                    /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY = //assign _6wvfe1Xp8j5_5PaTPWZ4qHH
                        (apply3_BM (( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[95] /*!_73hC7TDRQc7_7AAWITxnirb*/)), ((struct stackframe_stBM*)&_),
                                    ( /*v_subextractor:*/_.v_4vxTzYY836O_03Zx8TO4YLy),  ( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),
                                    (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _6EpJ2KoyuiU_8s0JUiNhxei #8 statement:

                    {
                        // run _9nUcUA7CnSG_7eCYFlxlnrD
                        /*debug miniscan_json_extractor json_entry after miniscan_json_extractor: v_scanres v_extractor v_subextractor o_vihset depth*/
                        DBGPRINTF_BM("miniscan_json_extractor json_entry after miniscan_json_extractor €%.9s: v_scanres=%s v_extractor=%s v_subextractor=%s o_vihset=%s depth#%ld",
                                     "_9nUcUA7CnSG_7eCYFlxlnrD",
                                     OUTSTRVALUE_BM( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY),
                                     OUTSTRVALUE_BM( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),
                                     OUTSTRVALUE_BM( /*v_subextractor:*/_.v_4vxTzYY836O_03Zx8TO4YLy),
                                     objectdbg_BM( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),
                                     (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;
                    } // end run _9nUcUA7CnSG_7eCYFlxlnrD

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _6EpJ2KoyuiU_8s0JUiNhxei #9 statement:
                    if /*cond _2QUwhpWvIj7_3BymVwALWTZ*/
                    /*when _9zTfQy64rvK_8qKXJ1U5tWT:*/
                    (/*is_null:*/(( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY)==NULL))   //body when _9zTfQy64rvK_8qKXJ1U5tWT
                        {
//failure _8rI09jovjG4_9QYF1rLp2B1
                            PLACEDFAILURE_BM(__LINE__,
                                             /*failreason:*/ (((value_tyBM) makenode6_BM
                                                               (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                       /*make_node 6 sons:*/
                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[86] /*!extract_json*/)),

                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[96] /*!json_entry*/)),

                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[52] /*!_4vI97FeROeO_7sERP0mphxF*/)),

// make_node arg #4
                                                                       ( /*v_subextractor:*/_.v_4vxTzYY836O_03Zx8TO4YLy),

                                                                       ( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),

                                                                       (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[111] /*|_8rI09jovjG4_9QYF1rLp2B1*/)),
                                             ((struct stackframe_stBM *) &_));

                        } //endwhen _9zTfQy64rvK_8qKXJ1U5tWT
                    /*endcond _2QUwhpWvIj7_3BymVwALWTZ*/

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _6EpJ2KoyuiU_8s0JUiNhxei #10 statement:
                    /*return _6J4QmqjPSLA_4qiLw5hEgSn:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned
                        /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY;
                    goto epilog_73hC7TDRQc7_7AAWITxnirb;


                    break; // end when _6EpJ2KoyuiU_8s0JUiNhxei #3 of objswitch _8kMEBcfqeWz_5JRhiMICep2

whenobj8kMEBcfq__8M0gq6Ilc80_7xXcAmJOstP:; // when #4 of objswitch _8kMEBcfqeWz_5JRhiMICep2
// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _8M0gq6Ilc80_7xXcAmJOstP #0 statement:
                    if /*cond _1J3UMJ7CDfY_2VDeFmVWOuN*/
                    /*when _3UHO7tANVVK_9t45WAWKu8Z:*/
                    ((/*unequal_int:*/( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k) != ( 1)))   //body when _3UHO7tANVVK_9t45WAWKu8Z
                        {
//failure _7w1Ga569HPb_9tLT45D1bZM
                            PLACEDFAILURE_BM(__LINE__,
                                             /*failreason:*/ (((value_tyBM) makenode5_BM
                                                               (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[114] /*!failure_bad_rank*/)),
                                                                       /*make_node 5 sons:*/
                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[95] /*!_73hC7TDRQc7_7AAWITxnirb*/)),

                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[8] /*!int*/)),

                                                                       ( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),

// make_node arg #4
                                                                       ( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),

                                                                       (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[103] /*|_7w1Ga569HPb_9tLT45D1bZM*/)),
                                             ((struct stackframe_stBM *) &_));

                        } //endwhen _3UHO7tANVVK_9t45WAWKu8Z
                    /*endcond _1J3UMJ7CDfY_2VDeFmVWOuN*/

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _8M0gq6Ilc80_7xXcAmJOstP #1 statement:
                    /*o_variable:*/_.o_7safxUAyjq9_7LcGUlnwwD1 = //assign _67sfJmZYsXE_9I3vYI8eJEH
                        /*val_to_object:*/objectcast_BM(/*nodenthson:*/nodenthson_BM(( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),( 0)));

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _8M0gq6Ilc80_7xXcAmJOstP #2 statement:

                    {
                        // run _3caq8gfHpDo_3wODM4tRLpA
                        /*debug miniscan_json_extractor int o_variable v_extractor o_vihset depth*/
                        DBGPRINTF_BM("miniscan_json_extractor int €%.9s o_variable=%s v_extractor=%s o_vihset=%s depth#%ld",
                                     "_3caq8gfHpDo_3wODM4tRLpA",
                                     objectdbg_BM( /*o_variable:*/_.o_7safxUAyjq9_7LcGUlnwwD1),
                                     OUTSTRVALUE_BM( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),
                                     objectdbg1_BM( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),
                                     (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;
                    } // end run _3caq8gfHpDo_3wODM4tRLpA

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _8M0gq6Ilc80_7xXcAmJOstP #3 statement:
                    if /*cond _96Y5nrwoje7_1e4LZNxQTQX*/
                    /*when _7XgxvQc17Dc_71t90fzpUvV:*/
                    (/*is_null:*/(( /*o_variable:*/_.o_7safxUAyjq9_7LcGUlnwwD1)==NULL))   //body when _7XgxvQc17Dc_71t90fzpUvV
                        {
//failure _7usb01gzlIN_2l3H7qTAe1g
                            PLACEDFAILURE_BM(__LINE__,
                                             /*failreason:*/ (((value_tyBM) makenode5_BM
                                                               (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                       /*make_node 5 sons:*/
                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[95] /*!_73hC7TDRQc7_7AAWITxnirb*/)),

                                                                       ( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),

                                                                       ( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),

// make_node arg #4
                                                                       ( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),

                                                                       (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[102] /*|_7usb01gzlIN_2l3H7qTAe1g*/)),
                                             ((struct stackframe_stBM *) &_));

                        } //endwhen _7XgxvQc17Dc_71t90fzpUvV
                    /*endcond _96Y5nrwoje7_1e4LZNxQTQX*/

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _8M0gq6Ilc80_7xXcAmJOstP #4 statement:
                    /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY = //assign _4zlASReWgsz_4NpSAjjGIgw
                        /*miniscan_var:*/ miniscan_var_BM (( /*o_variable:*/_.o_7safxUAyjq9_7LcGUlnwwD1), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM);

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _8M0gq6Ilc80_7xXcAmJOstP #5 statement:

                    {
                        // run _5E4C1rI970T_4VTQSSZDU1m
                        /*debug miniscan_json_extractor int v_scanres o_variable v_extractor o_vihset depth*/
                        DBGPRINTF_BM("debug miniscan_json_extractor int €%.9s v_scanres=%s o_variable=%s v_extractor=%s o_vihset=%s depth#%ld",
                                     "_5E4C1rI970T_4VTQSSZDU1m",
                                     OUTSTRVALUE_BM( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY),
                                     objectdbg_BM( /*o_variable:*/_.o_7safxUAyjq9_7LcGUlnwwD1),
                                     OUTSTRVALUE_BM( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),
                                     objectdbg1_BM( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),
                                     (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;
                    } // end run _5E4C1rI970T_4VTQSSZDU1m

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _8M0gq6Ilc80_7xXcAmJOstP #6 statement:
                    if /*cond _3eEVbbh4B9s_2BujOzYO5Ne*/
                    /*when _4iCIR7XmzLK_0JBM7Zbpccd:*/
                    (/*unequal_value*/(( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[8] /*!int*/))))   //body when _4iCIR7XmzLK_0JBM7Zbpccd
                        {
//failure _4yM7AxSjWC1_5rZcq1pceU0
                            PLACEDFAILURE_BM(__LINE__,
                                             /*failreason:*/ (((value_tyBM) makenode5_BM
                                                               (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[118] /*!failure_type_error*/)),
                                                                       /*make_node 5 sons:*/
                                                                       ( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY),

                                                                       ( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),

                                                                       ( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),

// make_node arg #4
                                                                       ( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),

                                                                       (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[54] /*|_4yM7AxSjWC1_5rZcq1pceU0*/)),
                                             ((struct stackframe_stBM *) &_));

                        } //endwhen _4iCIR7XmzLK_0JBM7Zbpccd
                    /*endcond _3eEVbbh4B9s_2BujOzYO5Ne*/

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _8M0gq6Ilc80_7xXcAmJOstP #7 statement:
                    {
                        // start cexpansion _0aXCagClstN_7ZzZJshvTWn - objhashsetaddpayl
                        /*objhashsetaddpayl:*/ objhashsetaddpayl_BM (( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r), ( /*o_variable:*/_.o_7safxUAyjq9_7LcGUlnwwD1));
                    } // end cexpansion _0aXCagClstN_7ZzZJshvTWn - objhashsetaddpayl

// objswitch _8kMEBcfqeWz_5JRhiMICep2 when _8M0gq6Ilc80_7xXcAmJOstP #8 statement:
                    /*return _5R2v6jNByHm_6tLsz7V8T3T:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned
                        /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY;
                    goto epilog_73hC7TDRQc7_7AAWITxnirb;


                    break; // end when _8M0gq6Ilc80_7xXcAmJOstP #4 of objswitch _8kMEBcfqeWz_5JRhiMICep2

                }
        } // end objswitch _8kMEBcfqeWz_5JRhiMICep2



        {
            // run _1nXL6vx4GWU_2d1IQFjgm7C
            /*debug miniscan_json_extractor after objswitch v_extractor o_vihset depth; o_stmt o_routprep*/
            DBGBACKTRACEPRINTF_BM("debug miniscan_json_extractor after objswitch €%.9s v_extractor=%s o_vihset=%s depth#%ld; o_stmt=%s o_routprep=%s",
                                  "_1nXL6vx4GWU_2d1IQFjgm7C",
                                  OUTSTRVALUE_BM( /*v_extractor:*/_.v_9L1R3E9dI8L_6D8VI16BtDm),
                                  objectdbg_BM( /*o_vihset:*/_.o_6Jkz6rphVkn_1KZto79j46r),
                                  (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
                                  objectdbg1_BM( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),
                                  objectdbg2_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH));;
        } // end run _1nXL6vx4GWU_2d1IQFjgm7C

        /* !endingblock _12FSPZ0qRUL_0iXrZB1pEB7 */
        goto endblock__12FSPZ0qRUL_0iXrZB1pEB7;
endblock__12FSPZ0qRUL_0iXrZB1pEB7:
        ;
    } /*-block _12FSPZ0qRUL_0iXrZB1pEB7 */

epilog_73hC7TDRQc7_7AAWITxnirb:
    __attribute__ ((unused)); // routine _73hC7TDRQc7_7AAWITxnirb epilogue:
    if (stkf) stkf->stkfram_callfun = NULL;
    return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _73hC7TDRQc7_7AAWITxnirb routine#10 _73hC7TDRQc7_7AAWITxnirb




value_tyBM crout_7IvnLvG7HVK_2qnOaIBtgVh_BM //#11
(struct stackframe_stBM* stkf, //
//!miniemit_node_conn#lazy-bool [v_init v_separ] (o_conn v_expr o_modgen o_routprep v_depth o_from)
 // 5 arguments
 const value_tyBM arg0,  // v_expr
 const value_tyBM arg1,  // o_modgen
 const value_tyBM arg2,  // o_routprep
 const value_tyBM arg3,  // v_depth
 const quasinode_tyBM * restargs /* 1 extrargs */)
{
    // start of _7IvnLvG7HVK_2qnOaIBtgVh
    struct frame_7IvnLvG7HVK_2qnOaIBtgVh_BMst
    {
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
        value_tyBM v_3qw9bnATIhq_8loBraLeXzQ; // v_r
        value_tyBM v_4nJKFtMqlkA_1teQSqofNux; // v_depth
        value_tyBM v_5Ed4AYrZZw4_8gOXzth8EQn; // v_init
        value_tyBM v_6CmIdtsXyBX_3lpk31Mve5M; // v_expr
        objectval_tyBM* o_6RpSqxAOt2p_35laNqeU6KH; // o_routprep
        objectval_tyBM* o_89nz0KaXXZh_8eSgMmqnK37; // o_from
        value_tyBM v_9rTjH62XTQr_2Emf0VIx9Ys; // v_separ
        /// 3 local numbers:
        intptr_t n_2W7Ckt2WxEM_4NVYgEWE73B; // ii
        intptr_t n_6Y20GNUgnSZ_4LkbrcRMU8f; // i_depth
        intptr_t n_833x2jYqhZh_8vDIuJhwz1k; // leni
        /// 0 scalar values:
    } _;
    memset (&_, 0, sizeof(struct frame_7IvnLvG7HVK_2qnOaIBtgVh_BMst));
    _.stkfram_head.htyp = typayl_StackFrame_BM;
    _.stkfram_head.hgc = 0;
    _.stkfram_head.rlen = 11;
    _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[104] /*|_7IvnLvG7HVK_2qnOaIBtgVh*/;
    ASSERT_BM (!stkf
               || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
               || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
    _.stkfram_prev = stkf;
    // fetch 5 arguments:
    unsigned nbrestargs = treewidth_BM((value_tyBM)restargs);
    _.v_6CmIdtsXyBX_3lpk31Mve5M = arg0; // v_expr
    _.o_2RUj1oyJ2rf_1ICZWr844Sv = objectcast_BM (arg1); // o_modgen
    _.o_6RpSqxAOt2p_35laNqeU6KH = objectcast_BM (arg2); // o_routprep
    _.v_4nJKFtMqlkA_1teQSqofNux = arg3; // v_depth
    if (nbrestargs > 0)
        _.o_89nz0KaXXZh_8eSgMmqnK37 = objectcast_BM(restargs->nodt_sons[0]); // o_from
    // fetched 5 arguments.
    {
        // fetch 2 closed values in _7IvnLvG7HVK_2qnOaIBtgVh:
        const closure_tyBM* callclos_7IvnLvG7HVK_2qnOaIBtgVh =
            (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
            ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
        const unsigned nbclosed_7IvnLvG7HVK_2qnOaIBtgVh = closurewidth_BM ((const value_tyBM) callclos_7IvnLvG7HVK_2qnOaIBtgVh);
        if (nbclosed_7IvnLvG7HVK_2qnOaIBtgVh > 0)
            _.v_5Ed4AYrZZw4_8gOXzth8EQn = callclos_7IvnLvG7HVK_2qnOaIBtgVh->nodt_sons[0]; // v_init
        if (nbclosed_7IvnLvG7HVK_2qnOaIBtgVh > 1)
            _.v_9rTjH62XTQr_2Emf0VIx9Ys = callclos_7IvnLvG7HVK_2qnOaIBtgVh->nodt_sons[1]; // v_separ
    } // fetched 2 closed values in _7IvnLvG7HVK_2qnOaIBtgVh.
    // routine _7IvnLvG7HVK_2qnOaIBtgVh body:

startblock__7NMa7lSwvXP_9j5Hh30tuXg:
    __attribute__((unused));
    {
        /* +block _7NMa7lSwvXP_9j5Hh30tuXg */
        /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _0LnHhhNiBY3_4VR3kMAFQf2
            /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ;


        /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81 = //assign _3RLJ8RBQJ1M_1hSsUsZA6K0
            /*nodeconn:*/nodeconn_BM( /*v_expr:*/_.v_6CmIdtsXyBX_3lpk31Mve5M);

//+ #2/9 of block _7NMa7lSwvXP_9j5Hh30tuXg ::


        {
            // run _210M01XittR_84fKNMVa6pD
            /*debug miniemit_node_conn#lazy-bool start [v_init v_separ] (o_conn v_expr o_modgen o_routprep depth o_from*/
            DBGPRINTF_BM("miniemit_node_conn#lazy-bool start €%.9s [v_init=%s v_separ=%s] (o_conn=%s v_expr=%s o_modgen=%s/L%u o_routprep=%s depth#%ld o_from=%s",
                         "_210M01XittR_84fKNMVa6pD",
                         OUTSTRVALUE_BM( /*v_init:*/_.v_5Ed4AYrZZw4_8gOXzth8EQn),
                         OUTSTRVALUE_BM( /*v_separ:*/_.v_9rTjH62XTQr_2Emf0VIx9Ys),
                         objectdbg_BM( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81),
                         OUTSTRVALUE_BM( /*v_expr:*/_.v_6CmIdtsXyBX_3lpk31Mve5M),
                         objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objectdbg2_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                         (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
                         objectdbg3_BM( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37));;
        } // end run _210M01XittR_84fKNMVa6pD


        {
            // start out _4qUtUCtxb5R_3wIO2NNv5SO to o_modgen
            /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "/*lazy ");
            /*out object:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, objectdbg_BM ( /*o_conn:*/_.o_13K9OfeXRZR_84nyRTtoj81));
            /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, ":*/ (intptr_t) (");
            /*out int:*/ objstrbufferprintfpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, "%lld", (long long)  /* val_to_int */ getint_BM( /*v_init:*/_.v_5Ed4AYrZZw4_8gOXzth8EQn) );
        } // end out _4qUtUCtxb5R_3wIO2NNv5SO

//+ #4/9 of block _7NMa7lSwvXP_9j5Hh30tuXg ::

        /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _4GthV3VnHqQ_2aMR6Cff6ZL
            /*nodewidth:*/(intptr_t)nodewidth_BM( /*v_expr:*/_.v_6CmIdtsXyBX_3lpk31Mve5M);


        {
            //for-up _48DIBYw2nm1_27rqv1dIn2D
            intptr_t cnt_48DIBYw2nm1_27rqv1dIn2D =  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k;
            for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;
                         /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_48DIBYw2nm1_27rqv1dIn2D;
                         /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++)
                {
// for-up _48DIBYw2nm1_27rqv1dIn2D #0 :
                    /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe = //assign _9xc6pKXQZ4j_32lO8F2c3Gi
                        /*nodenthson:*/nodenthson_BM(( /*v_expr:*/_.v_6CmIdtsXyBX_3lpk31Mve5M),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B));

// for-up _48DIBYw2nm1_27rqv1dIn2D #1 :

                    {
                        // run _5ZP8FhBKF9U_7aktVsOMBrz
                        /*debug miniemit_node_conn#lazy-bool for v_comp ii v_expr o_modgen o_routprep depth o_from*/
                        DBGPRINTF_BM("miniemit_node_conn#lazy-bool €%.9s for v_comp=%s ii#%ld v_expr=%s o_modgen=%s/L%u o_routprep=%s depth#%ld o_from=%s",
                                     "_5ZP8FhBKF9U_7aktVsOMBrz",
                                     OUTSTRVALUE_BM( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe),
                                     (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
                                     OUTSTRVALUE_BM( /*v_expr:*/_.v_6CmIdtsXyBX_3lpk31Mve5M),
                                     objectdbg_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                                     objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                                     objectdbg1_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                                     (long int) ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
                                     objectdbg2_BM( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37));;
                    } // end run _5ZP8FhBKF9U_7aktVsOMBrz

// for-up _48DIBYw2nm1_27rqv1dIn2D #2 :
                    {
                        // start out _4WnmFruQxLD_6oK1TI7UDVs to o_modgen
                        /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, " ");
                        /*out string:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, /*bytstring:*/bytstring_BM((const stringval_tyBM*)( /*v_separ:*/_.v_9rTjH62XTQr_2Emf0VIx9Ys)));
                        /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, " (");
                    } // end out _4WnmFruQxLD_6oK1TI7UDVs

// for-up _48DIBYw2nm1_27rqv1dIn2D #3 :
                    {
                        // start cexpansion _8qPKpstyuB9_2VHiLPb2KW8 - miniemit_expression
                        /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                ( /*v_comp:*/_.v_0ZL8gaI6sH8_7UPhmAQcwMe), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                    } // end cexpansion _8qPKpstyuB9_2VHiLPb2KW8 - miniemit_expression

// for-up _48DIBYw2nm1_27rqv1dIn2D #4 :
                    {
                        // start out _0gRK4BGl8n7_35yQqElfhHT to o_modgen
                        /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, ")");
                    } // end out _0gRK4BGl8n7_35yQqElfhHT

                }
        } // end for-up _48DIBYw2nm1_27rqv1dIn2D
//+ #6/9 of block _7NMa7lSwvXP_9j5Hh30tuXg ::

        {
            // start out _1rsKHNjPFsu_3aPtIim2oGS to o_modgen
            /*out literal:*/ objstrbufferappendcstrpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv, ")");
        } // end out _1rsKHNjPFsu_3aPtIim2oGS



        {
            // run _7poQO9jPFZN_79HDyTMqWZo
            /*debug miniemit_node_conn#lazy-bool end v_expr o_modgen depth o_from*/
            DBGBACKTRACEPRINTF_BM("miniemit_node_conn#lazy-bool end €%.9s v_expr=%s o_modgen=%s/L%u depth#%ld o_from=%s",
                                  "_7poQO9jPFZN_79HDyTMqWZo",
                                  OUTSTRVALUE_BM( /*v_expr:*/_.v_6CmIdtsXyBX_3lpk31Mve5M),
                                  objectdbg_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                                  objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                                  (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f),
                                  objectdbg1_BM( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37));;
        } // end run _7poQO9jPFZN_79HDyTMqWZo


        /*return _0knavdDjRkM_149KbBkXyE9:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned
            /*v_expr:*/_.v_6CmIdtsXyBX_3lpk31Mve5M;
        goto epilog_7IvnLvG7HVK_2qnOaIBtgVh;

        /* !endingblock _7NMa7lSwvXP_9j5Hh30tuXg */
        goto endblock__7NMa7lSwvXP_9j5Hh30tuXg;
endblock__7NMa7lSwvXP_9j5Hh30tuXg:
        ;
    } /*-block _7NMa7lSwvXP_9j5Hh30tuXg */

epilog_7IvnLvG7HVK_2qnOaIBtgVh:
    __attribute__ ((unused)); // routine _7IvnLvG7HVK_2qnOaIBtgVh epilogue:
    if (stkf) stkf->stkfram_callfun = NULL;
    return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _7IvnLvG7HVK_2qnOaIBtgVh routine#11 _7IvnLvG7HVK_2qnOaIBtgVh




value_tyBM crout_85xjvzYjcd6_9mNZNPF6i2J_BM //#12
(struct stackframe_stBM* stkf, //
//!miniscan_stmt°basiclo_countloop < o_stmt (o_routprep v_depth o_from)
 // 4 arguments
 const value_tyBM arg0,  // o_stmt
 const value_tyBM arg1,  // o_routprep
 const value_tyBM arg2,  // v_depth
 const value_tyBM arg3,  // o_from
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
    // start of _85xjvzYjcd6_9mNZNPF6i2J
    struct frame_85xjvzYjcd6_9mNZNPF6i2J_BMst
    {
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
        /// 0 scalar values:
    } _;
    memset (&_, 0, sizeof(struct frame_85xjvzYjcd6_9mNZNPF6i2J_BMst));
    _.stkfram_head.htyp = typayl_StackFrame_BM;
    _.stkfram_head.hgc = 0;
    _.stkfram_head.rlen = 11;
    _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[110] /*|_85xjvzYjcd6_9mNZNPF6i2J*/;
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

startblock__0knuZ8Npcw8_6Jj2YIvenZB:
    __attribute__((unused));
    {
        /* +block _0knuZ8Npcw8_6Jj2YIvenZB */
        /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _74XT4f1vWl9_7pfkRaZCCjn
            /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ;


        /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4 = //assign _9pqI2UGxUWS_2CBJ8rAZ82i
            /*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[88] /*!index*/))));

//+ #2/15 of block _0knuZ8Npcw8_6Jj2YIvenZB ::

        /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU = //assign _3432lagVKwU_591r9WA1UM7
            /*objgetattr:*/objgetattr_BM(( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[75] /*!count*/)));



        {
            // run _87LNOwdCnqL_9Z0b3QKGp5B
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



        {
            // run _3PEOwbhRvWp_6hH8N2yKT9y
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
        (/*unequal_object:*/(( /*o_typcount:*/_.o_48tt3ewgFzG_8U9hwUq2GY6) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[8] /*!int*/))))   //body when _8Qv6mNnpd1C_5xmOXXiwNGC
            {
//failure _6Rc660mzjXf_6rWF1nupKVt
                PLACEDFAILURE_BM(__LINE__,
                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                   (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[118] /*!failure_type_error*/)),
                                                    /*make_node 7 sons:*/
                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[75] /*!count*/)),

                                                    ( /*o_typcount:*/_.o_48tt3ewgFzG_8U9hwUq2GY6),

                                                    ( /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU),

// make_node arg #4
                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[92] /*|_6Rc660mzjXf_6rWF1nupKVt*/)),
                                 ((struct stackframe_stBM *) &_));

            } //endwhen _8Qv6mNnpd1C_5xmOXXiwNGC
        /*endcond _7KmS6tYm3q4_1IcuMa7JPp8*/


        /*o_typindex:*/_.o_2nKz6bXzYe0_5F1HxV9bQRu = //assign _0ULwQ3GvZnM_9zrslX7LdFF
            /*miniscan_var:*/ miniscan_var_BM (( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))), ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl), CURFRAME_BM);

//+ #8/15 of block _0knuZ8Npcw8_6Jj2YIvenZB ::


        {
            // run _9kNbtEAA7uz_7q5zk1aGoci
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
        (/*unequal_object:*/(( /*o_typindex:*/_.o_2nKz6bXzYe0_5F1HxV9bQRu) != ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[8] /*!int*/))))   //body when _25gAJE4HRuv_89hQbm1jNh8
            {
//failure _5zaZ8sDu1TQ_49hqJMJDKIq
                PLACEDFAILURE_BM(__LINE__,
                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                   (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[118] /*!failure_type_error*/)),
                                                    /*make_node 7 sons:*/
                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[88] /*!index*/)),

                                                    ( /*o_typindex:*/_.o_2nKz6bXzYe0_5F1HxV9bQRu),

                                                    ( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4),

// make_node arg #4
                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f)),

                                                    ( /*o_from:*/_.o_89nz0KaXXZh_8eSgMmqnK37)))),
                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[70] /*|_5zaZ8sDu1TQ_49hqJMJDKIq*/)),
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
startblock__5BJGeu6Rib0_1jHW94atiIm:  /*+!while*/
        ;
        {
            /* +while _5BJGeu6Rib0_1jHW94atiIm */
            if (!(/*while _5BJGeu6Rib0_1jHW94atiIm cond:*/ (/*less_int:*/( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) < ( /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k)))) //: testwhile _5BJGeu6Rib0_1jHW94atiIm failing
                goto endblock__5BJGeu6Rib0_1jHW94atiIm; //failwhile
// while _5BJGeu6Rib0_1jHW94atiIm body:
// while _5BJGeu6Rib0_1jHW94atiIm comp#0:
            /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2 = //assign _6kPpR9K4hYf_4vVcztNjQgZ
                /*val_to_object:*/objectcast_BM(/*objgetcomp:*/objgetcomp_BM (( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)));
// while _5BJGeu6Rib0_1jHW94atiIm comp#1:

            {
                // run _2cjXG3IXlV2_5AQnd3JjO3Y
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
            ( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2)   //body when _7lA4UB4g8lU_55OVWFQNpIA
                {

                    {
                        // begin lockobj _5pCnYlCZrUY_5zgmm9wjYdu
                        objectval_tyBM* curlockedob_5pCnYlCZrUY_5zgmm9wjYdu = ( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2);
                        if (objlock_BM (curlockedob_5pCnYlCZrUY_5zgmm9wjYdu))
                            {
                                locked_5pCnYlCZrUY_5zgmm9wjYdu = curlockedob_5pCnYlCZrUY_5zgmm9wjYdu;

                                if /*cond _8GpBvvm7FCj_8MezDXgKCOe*/
                                /*when _2Hvz5h8r9Av_3Yv9HV7md5M:*/
                                (/*objectisinstance:*/ objectisinstance_BM(( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[51] /*!basiclo_statement*/))))   //body when _2Hvz5h8r9Av_3Yv9HV7md5M
                                    {
                                        /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY = //assign _8sgR7i31pzL_42EKpWujqoM
                                            (send3_BM (( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2), /*sel:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[87] /*!miniscan_stmt*/)), ((struct stackframe_stBM*)&_),
                                                       ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1)))),
                                                       ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl)));
                                        if /*cond _4vZIvqj37yD_8V1cygCMbVf*/
                                        /*when _65JCkS6AuG7_6tVxePro2Ph:*/
                                        (/*is_null:*/(( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY)==NULL))   //body when _65JCkS6AuG7_6tVxePro2Ph
                                            {
//failure _227kofebdwq_9fj8R3qXt7B
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                                    /*make_node 7 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[110] /*!_85xjvzYjcd6_9mNZNPF6i2J*/)),

                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[87] /*!miniscan_stmt*/)),

                                                                                    ( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2),

// make_node arg #4
                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[24] /*|_227kofebdwq_9fj8R3qXt7B*/)),
                                                                 ((struct stackframe_stBM *) &_));

                                            } //endwhen _65JCkS6AuG7_6tVxePro2Ph
                                        /*endcond _4vZIvqj37yD_8V1cygCMbVf*/

                                    } //endwhen _2Hvz5h8r9Av_3Yv9HV7md5M
                                else if
                                /*when _8UhAB14P5OV_4SzOu2Seitj:*/
                                (/*objectisinstance:*/ objectisinstance_BM(( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[49] /*!basiclo_block*/))))   //body when _8UhAB14P5OV_4SzOu2Seitj
                                    {
                                        /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY = //assign _86xNO9NKgrq_1i3ph3xKuZk
                                            (send3_BM (( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2), /*sel:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[27] /*!miniscan_block*/)), ((struct stackframe_stBM*)&_),
                                                       ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),  (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1)))),
                                                       ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl)));
                                        if /*cond _7vA3sGtaCEa_4clk6xjbqLS*/
                                        /*when _2WH4J5GZlQ7_3gpZRxe8LNm:*/
                                        (/*is_null:*/(( /*v_scanres:*/_.v_5wKdFyGNJ5j_50nIjxm7LLY)==NULL))   //body when _2WH4J5GZlQ7_3gpZRxe8LNm
                                            {
//failure _5oVb4fNe3eO_4GyCgc0vkQp
                                                PLACEDFAILURE_BM(__LINE__,
                                                                 /*failreason:*/ (((value_tyBM) makesizednode_BM
                                                                                   (7U,/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                                    /*make_node 7 sons:*/
                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[110] /*!_85xjvzYjcd6_9mNZNPF6i2J*/)),

                                                                                    ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[27] /*!miniscan_block*/)),

                                                                                    ( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2),

// make_node arg #4
                                                                                    (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

                                                                                    ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                    ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                    (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                                                                 /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[66] /*|_5oVb4fNe3eO_4GyCgc0vkQp*/)),
                                                                 ((struct stackframe_stBM *) &_));

                                            } //endwhen _2WH4J5GZlQ7_3gpZRxe8LNm
                                        /*endcond _7vA3sGtaCEa_4clk6xjbqLS*/

                                    } //endwhen _8UhAB14P5OV_4SzOu2Seitj
                                else   /*cond else _8GpBvvm7FCj_8MezDXgKCOe*/
                                    {
//failure _0HZ6LhCuD3B_3wOqehpkD81
                                        PLACEDFAILURE_BM(__LINE__,
                                                         /*failreason:*/ (((value_tyBM) makenode6_BM
                                                                           (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[56] /*!failure_bad_class*/)),
                                                                                   /*make_node 6 sons:*/
                                                                                   ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[110] /*!_85xjvzYjcd6_9mNZNPF6i2J*/)),

                                                                                   ( /*o_substmt:*/_.o_1NOlyGkbWyD_5JUfiTznxM2),

                                                                                   (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                                   ( /*o_stmt:*/_.o_34Qtvf1thwK_9rziG6sk6Vl),

                                                                                   ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),

                                                                                   (/*taggedint:*/ taggedint_BM ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f))))),
                                                         /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[12] /*|_0HZ6LhCuD3B_3wOqehpkD81*/)),
                                                         ((struct stackframe_stBM *) &_));
                                    } /*cond else _8GpBvvm7FCj_8MezDXgKCOe*/
                                /*endcond _8GpBvvm7FCj_8MezDXgKCOe*/

                                objunlock_BM (locked_5pCnYlCZrUY_5zgmm9wjYdu), locked_5pCnYlCZrUY_5zgmm9wjYdu = NULL;
                            }
                    } // end objlock _5pCnYlCZrUY_5zgmm9wjYdu

                } //endwhen _7lA4UB4g8lU_55OVWFQNpIA
            /*endcond _1ibJngatIV4_0zFDxkfo8GR*/
// while _5BJGeu6Rib0_1jHW94atiIm comp#3:
            /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _9joCoPDJZPz_78kcVz01COq
                /*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1));

            goto startblock__5BJGeu6Rib0_1jHW94atiIm; // repeatwhile
endblock__5BJGeu6Rib0_1jHW94atiIm: /*endingwhile*/
            ;
        } /*-endwhile _5BJGeu6Rib0_1jHW94atiIm */




        {
            // run _3VHKozAi0fc_0sPZAQQdLWv
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
endblock__0knuZ8Npcw8_6Jj2YIvenZB:
        ;
    } /*-block _0knuZ8Npcw8_6Jj2YIvenZB */

epilog_85xjvzYjcd6_9mNZNPF6i2J:
    __attribute__ ((unused)); // routine _85xjvzYjcd6_9mNZNPF6i2J epilogue:
    // unlocking 1:
    if (locked_5pCnYlCZrUY_5zgmm9wjYdu != NULL)
        objunlock_BM(locked_5pCnYlCZrUY_5zgmm9wjYdu), locked_5pCnYlCZrUY_5zgmm9wjYdu = NULL; // for o_substmt
    if (stkf) stkf->stkfram_callfun = NULL;
    return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _85xjvzYjcd6_9mNZNPF6i2J routine#12 _85xjvzYjcd6_9mNZNPF6i2J




value_tyBM crout_8NgOdlJACWN_8pbYZXkHpCj_BM //#13
(struct stackframe_stBM* stkf, //
//!emit_block°basiclo_for_down_loop  < o_block (o_modgen o_routprep v_depth)
 // 4 arguments
 const value_tyBM arg0,  // o_block
 const value_tyBM arg1,  // o_modgen
 const value_tyBM arg2,  // o_routprep
 const value_tyBM arg3,  // v_depth
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
    // start of _8NgOdlJACWN_8pbYZXkHpCj
    struct frame_8NgOdlJACWN_8pbYZXkHpCj_BMst
    {
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
        /// 0 scalar values:
    } _;
    memset (&_, 0, sizeof(struct frame_8NgOdlJACWN_8pbYZXkHpCj_BMst));
    _.stkfram_head.htyp = typayl_StackFrame_BM;
    _.stkfram_head.hgc = 0;
    _.stkfram_head.rlen = 9;
    _.stkfram_descr = constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[115] /*|_8NgOdlJACWN_8pbYZXkHpCj*/;
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

startblock__0V7X1Z5gIQp_4SZI2S9RSG0:
    __attribute__((unused));
    {
        /* +block _0V7X1Z5gIQp_4SZI2S9RSG0 */
        /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f = //assign _1MOZNoNsgVi_3UmtfBE7TEv
            /* val_to_int */ getint_BM( /*v_depth:*/_.v_4nJKFtMqlkA_1teQSqofNux) ;



        {
            // run _79GhuWKrhVL_5bSNNKWwje4
            /*debug emit_block°basiclo_for_down_loop  start o_block o_modgen o_routprep depth*/
            DBGPRINTF_BM("emit_block°basiclo_for_down_loop  start €%.9s o_block=%s o_modgen=%s/L%u o_routprep=%s depth#%ld",
                         "_79GhuWKrhVL_5bSNNKWwje4",
                         objectdbg_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),
                         objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objstrbufferlengthpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                         objectdbg2_BM( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                         (long int)( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));;
        } // end run _79GhuWKrhVL_5bSNNKWwje4



        {
            // begin lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE
            objectval_tyBM* curlockedob_4a5PI4Gi0yN_0Vg2cbkuXjE = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
            if (objlock_BM (curlockedob_4a5PI4Gi0yN_0Vg2cbkuXjE))
                {
                    locked_4a5PI4Gi0yN_0Vg2cbkuXjE = curlockedob_4a5PI4Gi0yN_0Vg2cbkuXjE;

                    /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4 = //assign _0ueKJsCvh64_2RNLZqdlw0A
                        /*val_to_object:*/objectcast_BM(/*objgetattr:*/objgetattr_BM(( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[88] /*!index*/))));

                    /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU = //assign _5seYtoR5pxJ_37Qi2lVAneY
                        /*objgetattr:*/objgetattr_BM(( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[75] /*!count*/)));

//+ #2/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::

                    {
                        // run _1mTrwgoPbKF_8mcsO9qzS13
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

                    {
                        // start cexpansion _5hGkE3qmw8e_3lVUu6wesD5 - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "{ //for-down "));
                    } // end cexpansion _5hGkE3qmw8e_3lVUu6wesD5 - objstrbufferappendcstrpayl

//+ #4/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::
                    {
                        // start cexpansion _2xnAOqlCcPw_5Bzey6lbzTC - objstrbufferprintobject
                        /*objstrbufferprintobject _2xnAOqlCcPw_5Bzey6lbzTC:*/
                        objectval_tyBM* obsbuf_2xnAOqlCcPw_5Bzey6lbzTC = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                        objectval_tyBM* ob_2xnAOqlCcPw_5Bzey6lbzTC = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
                        if (objhasstrbufferpayl_BM(obsbuf_2xnAOqlCcPw_5Bzey6lbzTC) && isobject_BM(ob_2xnAOqlCcPw_5Bzey6lbzTC))
                            objstrbufferappendcstrpayl_BM(obsbuf_2xnAOqlCcPw_5Bzey6lbzTC, objectdbg_BM(ob_2xnAOqlCcPw_5Bzey6lbzTC));
// end objstrbufferprintobject _2xnAOqlCcPw_5Bzey6lbzTC
                        ;
                    } // end cexpansion _2xnAOqlCcPw_5Bzey6lbzTC - objstrbufferprintobject

                    {
                        // start cexpansion _9oPXYiXVx3z_4QMTusazjXN - objstrbuffersetindentpayl
                        /*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                    } // end cexpansion _9oPXYiXVx3z_4QMTusazjXN - objstrbuffersetindentpayl

//+ #6/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::
                    {
                        // start cexpansion _9aqYHQ1DxPz_1yUEPlMNMi3 - objstrbuffernewlinepayl
                        /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                    } // end cexpansion _9aqYHQ1DxPz_1yUEPlMNMi3 - objstrbuffernewlinepayl

                    {
                        // start cexpansion _3zgSe1zf9an_9zcqOCriaRf - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "intptr_t cnt"));
                    } // end cexpansion _3zgSe1zf9an_9zcqOCriaRf - objstrbufferappendcstrpayl

//+ #8/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::
                    {
                        // start cexpansion _9pAN1UadjT9_4HQXK5j1f2m - objstrbufferprintobjid
                        /*objstrbufferprintobjid _9pAN1UadjT9_4HQXK5j1f2m:*/
                        objectval_tyBM *obsbuf__9pAN1UadjT9_4HQXK5j1f2m = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                        objectval_tyBM *ob__9pAN1UadjT9_4HQXK5j1f2m = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
                        if (objhasstrbufferpayl_BM(obsbuf__9pAN1UadjT9_4HQXK5j1f2m) && isobject_BM(ob__9pAN1UadjT9_4HQXK5j1f2m))
                            {
                                char idbuf__9pAN1UadjT9_4HQXK5j1f2m [32];
                                memset (idbuf__9pAN1UadjT9_4HQXK5j1f2m, 0, sizeof(idbuf__9pAN1UadjT9_4HQXK5j1f2m));
                                idtocbuf32_BM (objid_BM (ob__9pAN1UadjT9_4HQXK5j1f2m), idbuf__9pAN1UadjT9_4HQXK5j1f2m);
                                objstrbufferappendcstrpayl_BM(obsbuf__9pAN1UadjT9_4HQXK5j1f2m, idbuf__9pAN1UadjT9_4HQXK5j1f2m);
                            };
// end objstrbufferprintobjid _9pAN1UadjT9_4HQXK5j1f2m
                        ;
                    } // end cexpansion _9pAN1UadjT9_4HQXK5j1f2m - objstrbufferprintobjid

                    {
                        // start cexpansion _6HS1ctWa2cx_8kR6FVRd5gz - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " = "));
                    } // end cexpansion _6HS1ctWa2cx_8kR6FVRd5gz - objstrbufferappendcstrpayl

//+ #10/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::
                    {
                        // start cexpansion _8Ux2RkzGGBL_1jntmBiiFTE - miniemit_expression
                        /*miniemit_expression:*/miniemit_expression_BM(CURFRAME_BM,
                                ( /*v_countexp:*/_.v_4leeeoANgjm_31PbCGhynlU), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                    } // end cexpansion _8Ux2RkzGGBL_1jntmBiiFTE - miniemit_expression

                    {
                        // start cexpansion _2B5X8R9i8ty_1ucz1kI8GDH - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( ";"));
                    } // end cexpansion _2B5X8R9i8ty_1ucz1kI8GDH - objstrbufferappendcstrpayl

//+ #12/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::
                    /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k = //assign _5aEMMsDVPT8_5OOBY9RA7UT
                        /*objnbcomps:*/ objnbcomps_BM ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);

                    {
                        // start cexpansion _0vpJQXO13zS_2L5lG1Mj9Jl - objstrbuffernewlinepayl
                        /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                    } // end cexpansion _0vpJQXO13zS_2L5lG1Mj9Jl - objstrbuffernewlinepayl

//+ #14/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::
                    {
                        // start cexpansion _4j0SrCTPKX5_578JTKzM0IO - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "for ("));
                    } // end cexpansion _4j0SrCTPKX5_578JTKzM0IO - objstrbufferappendcstrpayl

                    {
                        // start cexpansion _9VLKy0D7b3d_3C7v96GTfEI - miniemit_var
                        /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                           ( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
                    } // end cexpansion _9VLKy0D7b3d_3C7v96GTfEI - miniemit_var

//+ #16/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::
                    {
                        // start cexpansion _1sg4pwsDKCo_25auC3DIdDb - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " = cnt"));
                    } // end cexpansion _1sg4pwsDKCo_25auC3DIdDb - objstrbufferappendcstrpayl

                    {
                        // start cexpansion _9o0MX6Ie2We_0ErK51uBv2S - objstrbufferprintobjid
                        /*objstrbufferprintobjid _9o0MX6Ie2We_0ErK51uBv2S:*/
                        objectval_tyBM *obsbuf__9o0MX6Ie2We_0ErK51uBv2S = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                        objectval_tyBM *ob__9o0MX6Ie2We_0ErK51uBv2S = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
                        if (objhasstrbufferpayl_BM(obsbuf__9o0MX6Ie2We_0ErK51uBv2S) && isobject_BM(ob__9o0MX6Ie2We_0ErK51uBv2S))
                            {
                                char idbuf__9o0MX6Ie2We_0ErK51uBv2S [32];
                                memset (idbuf__9o0MX6Ie2We_0ErK51uBv2S, 0, sizeof(idbuf__9o0MX6Ie2We_0ErK51uBv2S));
                                idtocbuf32_BM (objid_BM (ob__9o0MX6Ie2We_0ErK51uBv2S), idbuf__9o0MX6Ie2We_0ErK51uBv2S);
                                objstrbufferappendcstrpayl_BM(obsbuf__9o0MX6Ie2We_0ErK51uBv2S, idbuf__9o0MX6Ie2We_0ErK51uBv2S);
                            };
// end objstrbufferprintobjid _9o0MX6Ie2We_0ErK51uBv2S
                        ;
                    } // end cexpansion _9o0MX6Ie2We_0ErK51uBv2S - objstrbufferprintobjid

//+ #18/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::
                    {
                        // start cexpansion _5PHQZpCbyj0_0Qu4OPP8J7O - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " - 1;"));
                    } // end cexpansion _5PHQZpCbyj0_0Qu4OPP8J7O - objstrbufferappendcstrpayl

                    {
                        // start cexpansion _3dqnISCnpKV_9cd4oa4lD8e - objstrbuffernewlinepayl
                        /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                    } // end cexpansion _3dqnISCnpKV_9cd4oa4lD8e - objstrbuffernewlinepayl

//+ #20/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::
                    {
                        // start cexpansion _7FhLjwiMrkL_0S5nfILsPPH - miniemit_var
                        /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                           ( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
                    } // end cexpansion _7FhLjwiMrkL_0S5nfILsPPH - miniemit_var

                    {
                        // start cexpansion _9wHUn8AEJW0_5mpOZSxpfOb - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " >= 0;"));
                    } // end cexpansion _9wHUn8AEJW0_5mpOZSxpfOb - objstrbufferappendcstrpayl

//+ #22/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::
                    {
                        // start cexpansion _0ajssbXBH1t_86eb7MoTPzX - objstrbuffernewlinepayl
                        /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                    } // end cexpansion _0ajssbXBH1t_86eb7MoTPzX - objstrbuffernewlinepayl

                    {
                        // start cexpansion _2fEiBwWFSaE_0vU58gZVuk2 - miniemit_var
                        /*miniemit_var:*/ miniemit_var_BM (CURFRAME_BM,
                                                           ( /*o_varindex:*/_.o_4QkDiZYXmJR_8VofvgKqcu4), ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH), ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
                    } // end cexpansion _2fEiBwWFSaE_0vU58gZVuk2 - miniemit_var

//+ #24/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::
                    {
                        // start cexpansion _2pOCIPB2UNg_05FSSKyZG7P - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " --) {"));
                    } // end cexpansion _2pOCIPB2UNg_05FSSKyZG7P - objstrbufferappendcstrpayl

                    {
                        //for-up _4pQc5GTSQCv_6wQlgOgKiCo
                        intptr_t cnt_4pQc5GTSQCv_6wQlgOgKiCo =  /*leni:*/_.n_833x2jYqhZh_8vDIuJhwz1k;
                        for ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B =0;
                                     /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B < cnt_4pQc5GTSQCv_6wQlgOgKiCo;
                                     /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B++)
                            {
// for-up _4pQc5GTSQCv_6wQlgOgKiCo #0 :
                                /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb = //assign _8Y4SyGKKT8Y_4ppoSkatlDr
                                    /*val_to_object:*/objectcast_BM(/*objgetcomp:*/objgetcomp_BM (( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW),( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)));

// for-up _4pQc5GTSQCv_6wQlgOgKiCo #1 :
                                if /*cond _69InabNi0ZZ_8nrzCwNE4PJ*/
                                /*when _8TSxMYEi7d2_5ZZyFEsVt4h:*/
                                ( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb)   //body when _8TSxMYEi7d2_5ZZyFEsVt4h
                                    {

                                        {
                                            // begin lockobj _0Wp7h8yI3oe_8LDnl3npXfl
                                            objectval_tyBM* curlockedob_0Wp7h8yI3oe_8LDnl3npXfl = ( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb);
                                            if (objlock_BM (curlockedob_0Wp7h8yI3oe_8LDnl3npXfl))
                                                {
                                                    locked_0Wp7h8yI3oe_8LDnl3npXfl = curlockedob_0Wp7h8yI3oe_8LDnl3npXfl;


                                                    {
                                                        // run _9Pt0y2rYY9X_1zywHJQtSbK
                                                        /*debug emit_block°basiclo_for_down_loop o_comp ii o_modgen o_block*/
                                                        DBGPRINTF_BM("emit_block°basiclo_for_down_loop €%.9s o_comp=%s ii#%ld o_modgen=%s/L%u o_block=%s",
                                                                     "_9Pt0y2rYY9X_1zywHJQtSbK",
                                                                     objectdbg_BM( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),
                                                                     (long int) ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B),
                                                                     objectdbg1_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                                                                     objstrbufferlengthpayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),
                                                                     objectdbg2_BM( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW));;
                                                    } // end run _9Pt0y2rYY9X_1zywHJQtSbK

                                                    {
                                                        // start cexpansion _1M8S2Mwfvvt_7b0TSkcWxHp - objstrbuffersetindentpayl
                                                        /*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))));
                                                    } // end cexpansion _1M8S2Mwfvvt_7b0TSkcWxHp - objstrbuffersetindentpayl

//+ #2/11 of lockobj _0Wp7h8yI3oe_8LDnl3npXfl ::
                                                    {
                                                        // start cexpansion _7slZIyHc2bf_6tUhk6lWWlE - objstrbuffernewlinepayl
                                                        /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                                                    } // end cexpansion _7slZIyHc2bf_6tUhk6lWWlE - objstrbuffernewlinepayl

                                                    {
                                                        // start cexpansion _1WlvridOvCE_4nfoeo6qsSE - objstrbufferappendcstrpayl
                                                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "// for-down "));
                                                    } // end cexpansion _1WlvridOvCE_4nfoeo6qsSE - objstrbufferappendcstrpayl

//+ #4/11 of lockobj _0Wp7h8yI3oe_8LDnl3npXfl ::
                                                    {
                                                        // start cexpansion _59NJcWlZqo7_5IZY8Qh9pKe - objstrbufferprintobject
                                                        /*objstrbufferprintobject _59NJcWlZqo7_5IZY8Qh9pKe:*/
                                                        objectval_tyBM* obsbuf_59NJcWlZqo7_5IZY8Qh9pKe = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                                                        objectval_tyBM* ob_59NJcWlZqo7_5IZY8Qh9pKe = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
                                                        if (objhasstrbufferpayl_BM(obsbuf_59NJcWlZqo7_5IZY8Qh9pKe) && isobject_BM(ob_59NJcWlZqo7_5IZY8Qh9pKe))
                                                            objstrbufferappendcstrpayl_BM(obsbuf_59NJcWlZqo7_5IZY8Qh9pKe, objectdbg_BM(ob_59NJcWlZqo7_5IZY8Qh9pKe));
// end objstrbufferprintobject _59NJcWlZqo7_5IZY8Qh9pKe
                                                        ;
                                                    } // end cexpansion _59NJcWlZqo7_5IZY8Qh9pKe - objstrbufferprintobject

                                                    {
                                                        // start cexpansion _67MGFrqvi8V_86YtGUqOXlD - objstrbufferappendcstrpayl
                                                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( " #"));
                                                    } // end cexpansion _67MGFrqvi8V_86YtGUqOXlD - objstrbufferappendcstrpayl

//+ #6/11 of lockobj _0Wp7h8yI3oe_8LDnl3npXfl ::
                                                    {
                                                        // start cexpansion _2YxyEcSJdKJ_9HEGTRUj9Wq - objstrbufferprintint
                                                        /*objstrbufferprintint:*/if (objhasstrbufferpayl_BM( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv))
                                                            {
                                                                char buf_2YxyEcSJdKJ_9HEGTRUj9Wq[32];
                                                                memset (buf_2YxyEcSJdKJ_9HEGTRUj9Wq, 0, sizeof(buf_2YxyEcSJdKJ_9HEGTRUj9Wq));
                                                                snprintf(buf_2YxyEcSJdKJ_9HEGTRUj9Wq, sizeof(buf_2YxyEcSJdKJ_9HEGTRUj9Wq), "%lld", (long long)  /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B);
                                                                objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), buf_2YxyEcSJdKJ_9HEGTRUj9Wq);
                                                            } //end objstrbufferprintint _2YxyEcSJdKJ_9HEGTRUj9Wq
                                                        ;
                                                    } // end cexpansion _2YxyEcSJdKJ_9HEGTRUj9Wq - objstrbufferprintint

                                                    {
                                                        // start cexpansion _9yBQYtAaH9M_8ktwf6cYm1k - objstrbuffernewlinepayl
                                                        /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                                                    } // end cexpansion _9yBQYtAaH9M_8ktwf6cYm1k - objstrbuffernewlinepayl

//+ #8/11 of lockobj _0Wp7h8yI3oe_8LDnl3npXfl ::
                                                    if /*cond _91XVXtprccW_28DRbTiOzSR*/
                                                    /*when _4KA7D8V97uE_0GKeafNCOjg:*/
                                                    (/*objectisinstance:*/ objectisinstance_BM(( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[49] /*!basiclo_block*/))))   //body when _4KA7D8V97uE_0GKeafNCOjg
                                                        {
                                                            /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _7qms8dDaskD_9n8IbyY8sp0
                                                                (send3_BM (( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), /*sel:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[81] /*!emit_block*/)), ((struct stackframe_stBM*)&_),
                                                                           ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),  ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                                                                           (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));

                                                        } //endwhen _4KA7D8V97uE_0GKeafNCOjg
                                                    else if
                                                    /*when _5fJtp7BHeaI_3SdQy8HSkeb:*/
                                                    (/*objectisinstance:*/ objectisinstance_BM(( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[51] /*!basiclo_statement*/))))   //body when _5fJtp7BHeaI_3SdQy8HSkeb
                                                        {
                                                            /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV = //assign _7nNnwMcKtuN_455Z1RFw66Z
                                                                (send3_BM (( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb), /*sel:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[22] /*!emit_statement*/)), ((struct stackframe_stBM*)&_),
                                                                           ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),  ( /*o_routprep:*/_.o_6RpSqxAOt2p_35laNqeU6KH),
                                                                           (/*taggedint:*/ taggedint_BM (/*add_int:*/(( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f) + ( 1))))));

                                                        } //endwhen _5fJtp7BHeaI_3SdQy8HSkeb
                                                    else   /*cond else _91XVXtprccW_28DRbTiOzSR*/
                                                        {
//failure _2MJKx6JJ45K_6rmHWbevG98
                                                            PLACEDFAILURE_BM(__LINE__,
                                                                             /*failreason:*/ (((value_tyBM) makenode5_BM
                                                                                               (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[56] /*!failure_bad_class*/)),
                                                                                                       /*make_node 5 sons:*/
                                                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[115] /*!_8NgOdlJACWN_8pbYZXkHpCj*/)),

                                                                                                       ( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),

                                                                                                       (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                                                       ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),

                                                                                                       ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW)))),
                                                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[36] /*|_2MJKx6JJ45K_6rmHWbevG98*/)),
                                                                             ((struct stackframe_stBM *) &_));
                                                        } /*cond else _91XVXtprccW_28DRbTiOzSR*/
                                                    /*endcond _91XVXtprccW_28DRbTiOzSR*/


                                                    {
                                                        // run _3iEKJp3QXd7_3utjt3P1kWR
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
                                                    (/*is_null:*/(( /*v_resemit:*/_.v_0qTBOEAT5pa_2fz1SKfHrMV)==NULL))   //body when _9HjGiFLRWyt_58OpYxNuI1N
                                                        {
//failure _5XtoXsvceoR_1Q6dI4J6G4X
                                                            PLACEDFAILURE_BM(__LINE__,
                                                                             /*failreason:*/ (((value_tyBM) makenode5_BM
                                                                                               (/*make_node conn:*/( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[61] /*!failure_miss*/)),
                                                                                                       /*make_node 5 sons:*/
                                                                                                       ( (constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[115] /*!_8NgOdlJACWN_8pbYZXkHpCj*/)),

                                                                                                       ( /*o_comp:*/_.o_6Z4UU939WbU_8BK9xcKsXNb),

                                                                                                       (/*taggedint:*/ taggedint_BM ( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B)),

// make_node arg #4
                                                                                                       ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv),

                                                                                                       ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW)))),
                                                                             /*failplace:*/ ( /*modconst:*/(constob_1lhXvXtIyPu_3nhuy4kN3wd_BM[77] /*|_5XtoXsvceoR_1Q6dI4J6G4X*/)),
                                                                             ((struct stackframe_stBM *) &_));

                                                        } //endwhen _9HjGiFLRWyt_58OpYxNuI1N
                                                    /*endcond _0D25uP6R82R_6ALVU5tS9tk*/

                                                    objunlock_BM (locked_0Wp7h8yI3oe_8LDnl3npXfl), locked_0Wp7h8yI3oe_8LDnl3npXfl = NULL;
                                                }
                                        } // end objlock _0Wp7h8yI3oe_8LDnl3npXfl

                                    } //endwhen _8TSxMYEi7d2_5ZZyFEsVt4h
                                /*endcond _69InabNi0ZZ_8nrzCwNE4PJ*/

                            }
                    } // end for-up _4pQc5GTSQCv_6wQlgOgKiCo

//+ #26/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::
                    {
                        // start cexpansion _8nSFXfKkUWb_6LwNMKTP35B - objstrbuffersetindentpayl
                        /*objstrbuffersetindentpayl:*/ objstrbuffersetindentpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( /*i_depth:*/_.n_6Y20GNUgnSZ_4LkbrcRMU8f));
                    } // end cexpansion _8nSFXfKkUWb_6LwNMKTP35B - objstrbuffersetindentpayl

                    {
                        // start cexpansion _1cf6xfCgklr_6Z5cYDvFYA1 - objstrbuffernewlinepayl
                        /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                    } // end cexpansion _1cf6xfCgklr_6Z5cYDvFYA1 - objstrbuffernewlinepayl

//+ #28/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::
                    {
                        // start cexpansion _67oLoMEzzaW_7lq2nZFaC5i - objstrbufferappendcstrpayl
                        /*objstrbufferappendcstrpayl:*/ objstrbufferappendcstrpayl_BM(( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv), ( "} } // end for-down "));
                    } // end cexpansion _67oLoMEzzaW_7lq2nZFaC5i - objstrbufferappendcstrpayl

                    {
                        // start cexpansion _4oHFEaEwUEh_47ScLMAXHby - objstrbufferprintobject
                        /*objstrbufferprintobject _4oHFEaEwUEh_47ScLMAXHby:*/
                        objectval_tyBM* obsbuf_4oHFEaEwUEh_47ScLMAXHby = ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                        objectval_tyBM* ob_4oHFEaEwUEh_47ScLMAXHby = ( /*o_block:*/_.o_5XGKMg1Kevs_6eAce4ib9XW);
                        if (objhasstrbufferpayl_BM(obsbuf_4oHFEaEwUEh_47ScLMAXHby) && isobject_BM(ob_4oHFEaEwUEh_47ScLMAXHby))
                            objstrbufferappendcstrpayl_BM(obsbuf_4oHFEaEwUEh_47ScLMAXHby, objectdbg_BM(ob_4oHFEaEwUEh_47ScLMAXHby));
// end objstrbufferprintobject _4oHFEaEwUEh_47ScLMAXHby
                        ;
                    } // end cexpansion _4oHFEaEwUEh_47ScLMAXHby - objstrbufferprintobject

//+ #30/33 of lockobj _4a5PI4Gi0yN_0Vg2cbkuXjE ::
                    {
                        // start cexpansion _6QxKswSMMuI_7eAKQJNPnX4 - objstrbuffernewlinepayl
                        /*objstrbuffernewlinepayl:*/objstrbuffernewlinepayl_BM ( /*o_modgen:*/_.o_2RUj1oyJ2rf_1ICZWr844Sv);
                    } // end cexpansion _6QxKswSMMuI_7eAKQJNPnX4 - objstrbuffernewlinepayl


                    {
                        // run _5o3ckSOo8Ob_0C7nhOZEQa5
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
                }
        } // end objlock _4a5PI4Gi0yN_0Vg2cbkuXjE
        /* !endingblock _0V7X1Z5gIQp_4SZI2S9RSG0 */
        goto endblock__0V7X1Z5gIQp_4SZI2S9RSG0;
endblock__0V7X1Z5gIQp_4SZI2S9RSG0:
        ;
    } /*-block _0V7X1Z5gIQp_4SZI2S9RSG0 */

epilog_8NgOdlJACWN_8pbYZXkHpCj:
    __attribute__ ((unused)); // routine _8NgOdlJACWN_8pbYZXkHpCj epilogue:
    // unlocking 2:
    if (locked_0Wp7h8yI3oe_8LDnl3npXfl != NULL)
        objunlock_BM(locked_0Wp7h8yI3oe_8LDnl3npXfl), locked_0Wp7h8yI3oe_8LDnl3npXfl = NULL; // for o_comp
    if (locked_4a5PI4Gi0yN_0Vg2cbkuXjE != NULL)
        objunlock_BM(locked_4a5PI4Gi0yN_0Vg2cbkuXjE), locked_4a5PI4Gi0yN_0Vg2cbkuXjE = NULL; // for o_block
    if (stkf) stkf->stkfram_callfun = NULL;
    return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _8NgOdlJACWN_8pbYZXkHpCj routine#13 _8NgOdlJACWN_8pbYZXkHpCj




// end of 14 generated routines


// the constant ids for 124 constants:
const char* const constid_1lhXvXtIyPu_3nhuy4kN3wd_BM[124+1] =
{
    /*0:*/
    "_06VtiJOTUI8_3WHyKhJi3sy", //! fail miss miniscan_expr v_comp ii o_routprep depth v_expr o_from miniscan_node_conn#lazy-bool
    "_08PMymoD6YJ_8rspWoCg4Xu", //! emit_statement°basiclo_outstmt < o_stmt (o_modgen o_routprep v_depth)
    "_09YrB2RcKY0_8qXAVUhGxat", //! emit_label°basiclo_jsonex_label < o_label (o_modgen o_routprep depth)
    "_0ekuRPtKaIF_3nrHrhB59Kn",//json_true
    "_0eLqstoeREp_44oHD9QEdRx", //! emit_block°basiclo_labeled_block [v_with_label] < o_block (o_modgen o_routprep v_depth)
    /*5:*/
    "_0eMGYofuNVh_8ZP2mXdhtHO",//in
    "_0jZB3m3ntxR_7JPnMzyIoBg", //! extract_json#readmacro(v_node v_lineno v_colpos o_parser)
    "_0o8bMUSb0El_8cRNhyRuvjD",//more_indent
    "_0vgCFjXblkx_4zCMhMAWjVK",//int
    "_0vCFi47Ctm6_70R5Tci6JuH", //! emit_block°basiclo_for_up_loop  < o_block (o_modgen o_routprep v_depth)
    /*10:*/
    "_0xjHtHT70tB_7ABtNzelPi8",//prefixed_lines
    "_0EmM9kH8Wgr_7fpd0oIo9xQ",//out
    "_0HZ6LhCuD3B_3wOqehpkD81", //! else fail bad-class miniscan_stmt°basiclo_countloop o_substmt ii o_stmt o_routprep depth
    "_0OM3NoUpOBd_1nzwCJKw54A",//statement_properties
    "_0UTjJP38fIh_02d0wLwrdAc", //! miniscan_node_conn#lazy-bool (o_conn  o_routprep v_depth v_expr o_from)
    /*15:*/
    "_17b3bhqLPeu_04FWlRjdMvD", //! miniscan_block°basiclo_labeled_block < o_block (o_routprep v_depth o_from)
    "_1h1MMlmQi6f_2Z2g6rGMcPB",//json_false
    "_1jJjA6LcXiX_1V4ZcXlje09",//name
    "_1kz7viwMzTp_6PgLhdZzMEy", //! miniscan_stmt°basiclo_outstmt < o_stmt (o_routprep v_depth o_from)
    "_1lhXvXtIyPu_3nhuy4kN3wd",//code_generator_module
    /*20:*/
    "_1lCz1IP7t5R_8NTFVv0tnOi",//octa
    "_1m5rw0BZl8f_4M9cndtjRl8", //! fail failure-miss out o_stmt o_routprep depth o_from
    "_1ERH9PxNhPb_2o869yOMuH0",//emit_statement
    "_1YX5DiyMYdm_8wQmGBtI3SD",//from
    "_227kofebdwq_9fj8R3qXt7B", //! fail-miss  miniscan_stmt°basiclo_countloop miniscan_stmt o_substmt ii o_stmt o_routprep depth
    /*25:*/
    "_26UbzubL5aT_2vDJc23p59r", //! fail-typerr int o_restype v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
    "_2eREyARXfUb_2mTxUngIL6Y", //! fail-typerr object o_restype v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
    "_2gthNYOWogO_4sVTU1JbmUH",//miniscan_block
    "_2lCuMosXupr_5GAoqVgJ8PZ",//blocks
    "_2mYaTh9kH4I_7ENiXcymRmy",//set
    /*30:*/
    "_2qDaJRPDbEG_45AvdxtQXAM",//double_float
    "_2u9YAFmxxSj_1WizQTT1BHQ",//half_id
    "_2wGWzItVmrN_2CBwG6iHWFO",//newline
    "_2yhrFze2uwV_6G7BfGXfplP",//set_indent
    "_2EwlACZSMng_4EsOBaICJHA",//hashset_jsonvar_object
    /*35:*/
    "_2JGuJeX3rdZ_193JJPCC8Jh", //! fail-duplicate miniscan_stmt°basiclo_extractjsonstmt o_stmt o_stmtprops o_vihset o_routprep depth o_from // duplicate extract_json statement
    "_2MJKx6JJ45K_6rmHWbevG98", //! fail-bad-class emit_block°basiclo_for_down_loop o_comp ii o_modgen o_block
    "_2P7OoZumXdx_5sUQ9SPbVwn",//utf8_enc
    "_2W2LFnO44dr_973izSVn0hU",//local_time
    "_2YrbiKQ6lxP_3KNUOnU6TF5",//duplicate
    /*40:*/
    "_34djinarLyR_73Q8MXulzOy",//or_else
    "_35gLacRFhq5_90zAPxiDIlh",//space
    "_3hMno2PB1II_6IrKetMkipy", //! else/bad o_conn fail-miss emit_statement°basiclo_outstmt unexpected o_conn v_comp ii o_stmt o_modgen o_routprep
    "_3tC5AFXTXB7_96qbnLbmViD",//json_entry_object
    "_3CZ4Lq3VkJF_3Qt5nkQ9R3w", //! fail-miss emit_block°basiclo_for_up_loop o_comp ii o_modgen o_block
    /*45:*/
    "_3QmxfIKpDVI_0C4Z01aFVxK",//html_enc
    "_3RUddTzPPB8_5j4EYXKOe2g", //! else fail-miss v_comp ii o_stmt o_modgen o_routprep in emit_statement°basiclo_outstmt
    "_3XBrePAliOo_37VlAqBsb5C",//label
    "_4bYmNw22J07_8hqiBv4W94U", //! fail
    "_4bYUiDmxrKK_6nPPlEl8y8x",//basiclo_block
    /*50:*/
    "_4dP92aF5D9l_4ROvrH6SnE3", //! fail-miss send o_comp ii o_block o_modgen o_routprep depth v_str //emit_block°basiclo_labeled_block
    "_4lKK08v9A0t_0GGsir35UxP",//basiclo_statement
    "_4vI97FeROeO_7sERP0mphxF", //! v_scanres := miniscan_json_extractor(v_comp o_vihset depth+1 o_stmt) // miniscan_json_extractor variadic
    "_4wmsNr582JT_9YyamGEMhJk",//json_compact
    "_4yM7AxSjWC1_5rZcq1pceU0", //! fail-type_error v_scanres o_conn v_extractor o_vihset depth ///miniscan_json_extractor
    /*55:*/
    "_4BSjKuvOgrt_81MLC8NyKiS",//double_plain
    "_4HgYLk6htvP_4Ac2FCPfQ1C",//failure_bad_class
    "_4HAZLawO9HO_91oo1k4Ajat", //! fail-typerr string o_restype v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
    "_4Khc0e9fPzW_1PzgQNc07d6", //! fail-bad_rank miniscan_json_extractor json_entry v_extractor o_vihset 0-arity
    "_4T8am97muLl_5969SR22Ecq",//string
    /*60:*/
    "_4WkaKNhBpsa_9VlfEzlClhm", //! fail-typerr double_float o_restype v_cimp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
    "_52XwytpOPVl_3ZjmQCtadbK",//failure_miss
    "_55k0ot2Zxca_48c9pjWuNWQ", //! emit_statement°basiclo_extractjsonstmt <o_stmt(o_modgen o_routprep v_depth)
    "_56Om4CG9rer_8xF06AhNZ1I",//json_array
    "_5l2zSKsFaVm_9zs6qDOP87i",//constants
    /*65:*/
    "_5oysKNBbMrG_0dniL1OrlJz", //! fail-bad_rank miniscan_json_extractor constants v_extractor o_vihset 0-arity
    "_5oVb4fNe3eO_4GyCgc0vkQp", //! fail-miss  miniscan_stmt°basiclo_countloop miniscan_block o_substmt ii o_stmt o_routprep depth
    "_5t5nLVnGAqW_9IbjlqpPdp3",//less_indent
    "_5wNedaaTb99_3ZQe6xm9HNx",//literal_c_string
    "_5x0WWw3QRXe_8u5OLA7sKJG", //! miniscan_stmt°basiclo_extractjsonstmt < o_stmt (o_routprep v_depth o_from)
    /*70:*/
    "_5zaZ8sDu1TQ_49hqJMJDKIq", //! fail type-error index typindex varindex stmt routprep depth from
    "_5GBZ4ZkvOUP_4710156ZNKJ", //! fail-miss label emit_block°basiclo_labeled_block o_block o_modgen o_routprep depth
    "_5J3InN9BK1k_3C8vurQQEGh",//json_indented
    "_5J4f6u42le4_9UZMTZziEEw", //! else fail-miss v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
    "_5LSPYWdN50R_3nt54XhyWMW",//json_value
    /*75:*/
    "_5OiKmAdUjY5_9BPLOECag6g",//count
    "_5P2fpxElfqT_7NlO7H9TYGI",//send
    "_5XtoXsvceoR_1Q6dI4J6G4X", //! fail-miss emit_block°basiclo_for_down_loop o_comp ii o_modgen o_block
    "_6cS5VddZd7n_9Nnn2wYWAeL", //! fail-miss miniscan_var o_varout o_routprep depth+1 o_stmt o_from in miniscan_stmt°basiclo_outstmt
    "_6fPPUXnZhy5_8Lh5DOOe0Nu",//arity
    /*80:*/
    "_6jh60mO0Cgd_84B0HiNphqA",//miniscan_var
    "_6mk5eos8067_1odgCpnWMOj",//emit_block
    "_6qi1DW0Ygkl_4Aqdxq4n5IV",//prepare_routine
    "_6rqacMdYDSJ_0C6DWcO4C0t",//basiclo_label
    "_6xxbA8aTjZm_1sCJbVkU3Pm",//c_enc
    /*85:*/
    "_6yWldsq3Rmk_01WqTfwSIDV",//failure_non_object
    "_6zj5YoW4CVg_7Az2Wsmlesm",//extract_json
    "_6DdZwyaWLyK_7tS2BmECOJ0",//miniscan_stmt
    "_6EG5W7z0BRb_4TBM1gyenqk",//index
    "_6EJRQxPiepy_50fow66D4Qn",//is_null
    /*90:*/
    "_6GcgFxSMvWY_4vzl0zmI5FA",//and_then
    "_6MTJtvsUEYW_9WuS0LnLfmm", //! fail-bad-class emit_block°basiclo_for_up_loop o_comp ii o_modgen o_block
    "_6Rc660mzjXf_6rWF1nupKVt", //! fail type-error count countexp stmt routprep depth from
    "_6WOSg1mpNxQ_6Dw2klXZFSk",//json_null
    "_6XhkvXDG3ac_5qqvPwzOjKh", //! fail-type_error miniscan_json_extractor value 1-arity v_scanres v_extractor o_vihset depth
    /*95:*/
    "_73hC7TDRQc7_7AAWITxnirb", //! miniscan_json_extractor(v_extractor o_vihset v_depth)
    "_78X6jYDHXpW_3opwNmDlnqc",//json_entry
    "_7bbeIqUSje9_4jVgC7ZJmvx",//value
    "_7coI3Hezrvp_6CG1u3MlT83",//nlsp
    "_7hNqn2hxg1M_3wNHCtOf9IF",//json_object
    /*100:*/
    "_7k3xb0vred0_9ZRHcZmhw77",//miniscan_expr
    "_7rJLemfzAk2_3B7wzh3wwTy",//emit_label
    "_7usb01gzlIN_2l3H7qTAe1g", //! fail-bad_miss miniscan_json_extractor o_conn v_extractor o_vihset  //miniscan_json_extractor
    "_7w1Ga569HPb_9tLT45D1bZM", //! fail-bad_rank miniscan_json_extractor int v_extractor o_vihset 0-arity
    "_7IvnLvG7HVK_2qnOaIBtgVh", //! miniemit_node_conn#lazy-bool [v_init v_separ] (o_conn v_expr o_modgen o_routprep v_depth o_from)
    /*105:*/
    "_7T9OwSFlgov_0wVJaK1eZbn",//object
    "_7TlPdNzYigl_2djAOJ1SLjA", //! fail-type_error miniscan_json_extractor json_entry v_extractor string o_vihset depth v_scanres
    "_7WjaQkqwdaZ_6PRtbDrJHnf",//id
    "_7WynVNCkQpd_4DPrtlIjox3", //! fail-type_error miniscan_json_extractor v_extractor o_vihset depth //non-node
    "_7YmEzAVe2hC_9iA0FVXAIqp",//hexa
    /*110:*/
    "_85xjvzYjcd6_9mNZNPF6i2J", //! miniscan_stmt°basiclo_countloop < o_stmt (o_routprep v_depth o_from)
    "_8rI09jovjG4_9QYF1rLp2B1", //! fail-miss extract_json json_entry miniscan_json_extractor v_subextractor o_vihset depth
    "_8zRh2medTlP_0ImnPyO8NKH",//rank
    "_8M5QuJZid40_07X694Ezsiz", //! fail-bad_rank miniscan_json_extractor valuevar v_extractor o_vihset 1-arity
    "_8MFQuVGkedx_8OkpYlCQFip",//failure_bad_rank
    /*115:*/
    "_8NgOdlJACWN_8pbYZXkHpCj", //! emit_block°basiclo_for_down_loop  < o_block (o_modgen o_routprep v_depth)
    "_8QmDbXEU8lU_33mrgrh3zUR", //! fail-miss arity v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
    "_8WAizZ04huN_09Xhiag4jid", //! fail-type_error miniscan_block°basiclo_labeled_block label o_label o_block o_routprep depth o_from
    "_95hdJENHNkN_3QuKIJTCQQQ",//failure_type_error
    "_9umIVqZhssC_2WJZljFrGaA", //! fail-typerr value o_restype v_comp ii o_stmt o_routprep depth o_from miniscan_stmt°basiclo_outstmt
    /*120:*/
    "_9ESZAHA4lZM_6MuzJ1ObwKc",//prefix_string
    "_9NMJjOqScc9_5rvKgT8VMEx", //! fail-nonobj v_comp  ii o_block o_routprep depth //emit_block°basiclo_labeled_block
    "_9U8L2fXpZ9o_4x751rhsyve",//basiclo_extractjsonstmt
    "_9Zrfsj91qog_1eIHNIe3Fjo", //! fail-rank miniscan_json_extractor v_extractor o_vihset depth //too deep
    NULL
}; // end 124 constant ids



// the routine ids for 14 routines:
const char* const routid_1lhXvXtIyPu_3nhuy4kN3wd_BM[14+1] =
{
    /*0:*/
    "_08PMymoD6YJ_8rspWoCg4Xu", //!emit_statement°basiclo_outstmt < o_stmt (o_modgen o_routprep v_depth)
    "_09YrB2RcKY0_8qXAVUhGxat", //!emit_label°basiclo_jsonex_label < o_label (o_modgen o_routprep depth)
    "_0eLqstoeREp_44oHD9QEdRx", //!emit_block°basiclo_labeled_block [v_with_label] < o_block (o_modgen o_routprep v_depth)
    "_0jZB3m3ntxR_7JPnMzyIoBg", //!extract_json#readmacro(v_node v_lineno v_colpos o_parser)
    "_0vCFi47Ctm6_70R5Tci6JuH", //!emit_block°basiclo_for_up_loop  < o_block (o_modgen o_routprep v_depth)
    "_0UTjJP38fIh_02d0wLwrdAc", //!miniscan_node_conn#lazy-bool (o_conn  o_routprep v_depth v_expr o_from)
    "_17b3bhqLPeu_04FWlRjdMvD", //!miniscan_block°basiclo_labeled_block < o_block (o_routprep v_depth o_from)
    "_1kz7viwMzTp_6PgLhdZzMEy", //!miniscan_stmt°basiclo_outstmt < o_stmt (o_routprep v_depth o_from)
    /*8:*/
    "_55k0ot2Zxca_48c9pjWuNWQ", //!emit_statement°basiclo_extractjsonstmt <o_stmt(o_modgen o_routprep v_depth)
    "_5x0WWw3QRXe_8u5OLA7sKJG", //!miniscan_stmt°basiclo_extractjsonstmt < o_stmt (o_routprep v_depth o_from)
    "_73hC7TDRQc7_7AAWITxnirb", //!miniscan_json_extractor(v_extractor o_vihset v_depth)
    "_7IvnLvG7HVK_2qnOaIBtgVh", //!miniemit_node_conn#lazy-bool [v_init v_separ] (o_conn v_expr o_modgen o_routprep v_depth o_from)
    "_85xjvzYjcd6_9mNZNPF6i2J", //!miniscan_stmt°basiclo_countloop < o_stmt (o_routprep v_depth o_from)
    "_8NgOdlJACWN_8pbYZXkHpCj", //!emit_block°basiclo_for_down_loop  < o_block (o_modgen o_routprep v_depth)

    NULL
}; // end 14 routine ids




// basiclo*module initialization
#ifdef BISMON_MODID
value_tyBM moduleinit_1lhXvXtIyPu_3nhuy4kN3wd_BM
(struct stackframe_stBM *stkf, //
 const value_tyBM arg1, //
 const value_tyBM arg2, //
 const value_tyBM arg3, //
 void* dlh)
{
    LOCALFRAME_BM(/*prev:*/stkf,
                           /*descr:*/lockedfindobjofstrid_BM("  _.arg1v = arg1;//
                                   _.arg2v = arg2;//
                                   _.arg3v = arg3;//
                                   "),//
                                   value_tyBM arg1v, arg2v, arg3v;//
                                                            );//
                           INFOPRINTF_BM("§initializing simple module _1lhXvXtIyPu_3nhuy4kN3wd with arguments (%s, %s, %s); module counter 5",
                                         debug_outstr_value_BM (_.arg1v, CURFRAME_BM, 0),//
                                         debug_outstr_value_BM (_.arg2v, CURFRAME_BM, 0),//
                                         debug_outstr_value_BM (_.arg3v, CURFRAME_BM, 0),//
                                         module_count_BM()); //
                           return simple_module_initialize_BM(arg1, arg2, arg3, //
                                   "_1lhXvXtIyPu_3nhuy4kN3wd",//
                                   constob_1lhXvXtIyPu_3nhuy4kN3wd_BM, //
                                   constid_1lhXvXtIyPu_3nhuy4kN3wd_BM, //
                                   routid_1lhXvXtIyPu_3nhuy4kN3wd_BM, //
                                   dlh, CURFRAME_BM);
} // end moduleinit_1lhXvXtIyPu_3nhuy4kN3wd_BM
#endif /*BISMON_MODID*/




/************
 ** for Emacs:
 ** Local Variables: ;;
 ** compile-command: "make -k -j -C .. modules" ;;
 ** End: ;;
 ************/



// end of generated persistent module code_generator_module in file modbm_1lhXvXtIyPu_3nhuy4kN3wd.c
