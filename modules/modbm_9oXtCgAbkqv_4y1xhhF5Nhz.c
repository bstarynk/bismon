// generated persistent module first_test_module
// in file modbm_9oXtCgAbkqv_4y1xhhF5Nhz.c -- DONT EDIT
// SPDX-License-Identifier: GPL-3.0-or-later
// this generated code (from bismon git a9f64e8482e517f5+) is GPLv3+ licensed.


#include "bismon.h"

#ifdef BISMON_MODID
DECLARE_MODULE_BM(_9oXtCgAbkqv_4y1xhhF5Nhz);
extern moduleinit_sigBM moduleinit_9oXtCgAbkqv_4y1xhhF5Nhz_BM;
#endif /*BISMON_MODID*/

#ifdef BISMON_MOMD5
const char modulmd5chksum_9oXtCgAbkqv_4y1xhhF5Nhz_BM[] = BISMON_MOMD5;
#endif /*BISMON_MOMD5*/



// declare 3 routines

extern const char *const routid_9oXtCgAbkqv_4y1xhhF5Nhz_BM[3+1];


// no failure

extern objrout_sigBM crout_0qxuQEfimtp_1Wp2YuKHsJ3_BM; //#0 !test-objswitch(o1) minifunc

extern objrout_sigBM crout_43Y25VLmh6s_3JRpERevcR4_BM; //#1 successor_test_minifunc

extern objrout_sigBM crout_9O2lgu1TweO_0mVlpTwrBG1_BM; //#2 second_test_minifunc


// declare 8 constants
objectval_tyBM* constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM[8+1];
const char* const constid_9oXtCgAbkqv_4y1xhhF5Nhz_BM[8+1];


// define 3 routines


value_tyBM crout_0qxuQEfimtp_1Wp2YuKHsJ3_BM //#0
(struct stackframe_stBM* stkf, //
//!test-objswitch(o1) minifunc
 // 1 arguments
 const value_tyBM arg0,  // o1
 const value_tyBM arg1_ __attribute__((unused)),
 const value_tyBM arg2_ __attribute__((unused)),
 const value_tyBM arg3_ __attribute__((unused)),
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
    // start of _0qxuQEfimtp_1Wp2YuKHsJ3
    struct frame_0qxuQEfimtp_1Wp2YuKHsJ3_BMst
    {
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
        /// 0 scalar values:
    } _;
    memset (&_, 0, sizeof(struct frame_0qxuQEfimtp_1Wp2YuKHsJ3_BMst));
    _.stkfram_head.htyp = typayl_StackFrame_BM;
    _.stkfram_head.hgc = 0;
    _.stkfram_head.rlen = 2;
    _.stkfram_descr = constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM[0] /*|_0qxuQEfimtp_1Wp2YuKHsJ3*/;
    ASSERT_BM (!stkf
               || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
               || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
    _.stkfram_prev = stkf;
    // fetch 1 arguments:
    _.o_97rnxb0KFqq_44veN75DG2E = objectcast_BM (arg0); // o1
    // fetched 1 arguments.
    // no closed values in _0qxuQEfimtp_1Wp2YuKHsJ3.
    const closure_tyBM* callclos_0qxuQEfimtp_1Wp2YuKHsJ3 __attribute__((unused)) =
        (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
        ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
    const unsigned nbclosed_0qxuQEfimtp_1Wp2YuKHsJ3  __attribute__((unused)) = 0;
    // routine _0qxuQEfimtp_1Wp2YuKHsJ3 body:

startblock__7eNL9Vje1Be_8iB8cXzHjcs:
    __attribute__((unused));
    {
        /* +block _7eNL9Vje1Be_8iB8cXzHjcs */

        {
            // begin objswitch _411NjvTH7B8_3FGcvfkrAZJ
//!objswitch! test objswitch o1 .
            objectval_tyBM* objswexp_411NjvTH7B8_3FGcvfkrAZJ = ( /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E);
            switch (objecthash_BM (objswexp_411NjvTH7B8_3FGcvfkrAZJ) % 16)
                {
                case 2:
                    if (objswexp_411NjvTH7B8_3FGcvfkrAZJ ==  (constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM[5] /*|hexa*/)) goto whenobj411NjvTH__8fWwRu3PMxA_6HlILozsTHd;
                    goto defobj_411NjvTH7B8_3FGcvfkrAZJ;
                case 11:
                    if (objswexp_411NjvTH7B8_3FGcvfkrAZJ ==  (constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM[4] /*|object*/)) goto whenobj411NjvTH__4BAGBRTZl7S_0xvgsAotvsa;
                    goto defobj_411NjvTH7B8_3FGcvfkrAZJ;
                case 14:
                    if (objswexp_411NjvTH7B8_3FGcvfkrAZJ ==  (constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM[1] /*|int*/)) goto whenobj411NjvTH__8fWwRu3PMxA_6HlILozsTHd;
                    goto defobj_411NjvTH7B8_3FGcvfkrAZJ;
                case 15:
                    if (objswexp_411NjvTH7B8_3FGcvfkrAZJ ==  (constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM[3] /*|value*/)) goto whenobj411NjvTH__4BAGBRTZl7S_0xvgsAotvsa;
                    goto defobj_411NjvTH7B8_3FGcvfkrAZJ;

                default:
defobj_411NjvTH7B8_3FGcvfkrAZJ:
                    ;

// objswitch _411NjvTH7B8_3FGcvfkrAZJ default#0 statement:

                    {
                        // run _2yQgJq1KeQl_57pLyAPExgp
                        /*debug else case*/
                        DBGPRINTF_BM("else case €%.9s o1=%s",
                                     "_2yQgJq1KeQl_57pLyAPExgp",
                                     objectdbg_BM( /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E));;
                    } // end run _2yQgJq1KeQl_57pLyAPExgp

                    break; // end objswitch _411NjvTH7B8_3FGcvfkrAZJ default
// objswitch _411NjvTH7B8_3FGcvfkrAZJ with 2 whens:

whenobj411NjvTH__4BAGBRTZl7S_0xvgsAotvsa:; // when #0 of objswitch _411NjvTH7B8_3FGcvfkrAZJ
// objswitch _411NjvTH7B8_3FGcvfkrAZJ when _4BAGBRTZl7S_0xvgsAotvsa #0 statement:

                    {
                        // run _07EJzYvQNwn_2ugilIxE5q3
                        /*debug object value case*/
                        DBGPRINTF_BM("object-value case €%.9s o1=%s",
                                     "_07EJzYvQNwn_2ugilIxE5q3",
                                     objectdbg_BM( /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E));;
                    } // end run _07EJzYvQNwn_2ugilIxE5q3


                    break; // end when _4BAGBRTZl7S_0xvgsAotvsa #0 of objswitch _411NjvTH7B8_3FGcvfkrAZJ

whenobj411NjvTH__8fWwRu3PMxA_6HlILozsTHd:; // when #1 of objswitch _411NjvTH7B8_3FGcvfkrAZJ
// objswitch _411NjvTH7B8_3FGcvfkrAZJ when _8fWwRu3PMxA_6HlILozsTHd #0 statement:

                    {
                        // run _2Y4mmlqkySL_0Kbidfml3Q7
                        /*debug int hexa case*/
                        DBGPRINTF_BM("int-hexa case €%.9s o1=%s",
                                     "_2Y4mmlqkySL_0Kbidfml3Q7",
                                     objectdbg_BM( /*o1:*/_.o_97rnxb0KFqq_44veN75DG2E));;
                    } // end run _2Y4mmlqkySL_0Kbidfml3Q7


                    break; // end when _8fWwRu3PMxA_6HlILozsTHd #1 of objswitch _411NjvTH7B8_3FGcvfkrAZJ

                }
        } // end objswitch _411NjvTH7B8_3FGcvfkrAZJ

        /* !endingblock _7eNL9Vje1Be_8iB8cXzHjcs */
        goto endblock__7eNL9Vje1Be_8iB8cXzHjcs;
endblock__7eNL9Vje1Be_8iB8cXzHjcs:
        ;
    } /*-block _7eNL9Vje1Be_8iB8cXzHjcs */

epilog_0qxuQEfimtp_1Wp2YuKHsJ3:
    __attribute__ ((unused)); // routine _0qxuQEfimtp_1Wp2YuKHsJ3 epilogue:
    if (stkf) stkf->stkfram_callfun = NULL;
    return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _0qxuQEfimtp_1Wp2YuKHsJ3 routine#0 _0qxuQEfimtp_1Wp2YuKHsJ3




value_tyBM crout_43Y25VLmh6s_3JRpERevcR4_BM //#1+
(struct stackframe_stBM* stkf, // successor_test_minifunc
//!first minifunc in first_test_module; if its argument is a number value, return its successor as a taggedint value
 // 1 arguments
 const value_tyBM arg0,  // v_i
 const value_tyBM arg1_ __attribute__((unused)),
 const value_tyBM arg2_ __attribute__((unused)),
 const value_tyBM arg3_ __attribute__((unused)),
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
    // start of successor_test_minifunc
    struct frame_43Y25VLmh6s_3JRpERevcR4_BMst
    {
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
        /// 0 scalar values:
    } _;
    memset (&_, 0, sizeof(struct frame_43Y25VLmh6s_3JRpERevcR4_BMst));
    _.stkfram_head.htyp = typayl_StackFrame_BM;
    _.stkfram_head.hgc = 0;
    _.stkfram_head.rlen = 2;
    _.stkfram_descr = constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM[2] /*|successor_test_minifunc*/;
    ASSERT_BM (!stkf
               || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
               || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
    _.stkfram_prev = stkf;
    // fetch 1 arguments:
    _.v_3vRFuniDv1K_4bQ7DeekM2I = arg0; // v_i
    // fetched 1 arguments.
    // no closed values in successor_test_minifunc.
    const closure_tyBM* callclos_43Y25VLmh6s_3JRpERevcR4 __attribute__((unused)) =
        (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
        ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
    const unsigned nbclosed_43Y25VLmh6s_3JRpERevcR4  __attribute__((unused)) = 0;
    // routine _43Y25VLmh6s_3JRpERevcR4 body:

startblock__7XasLoEUKwe_9upxyFeheD5:
    __attribute__((unused));
    {
        /* +block _7XasLoEUKwe_9upxyFeheD5 */
        if /*cond _1UM3ERNWFgo_6pqkY9UiIDv*/
        /*when _5mfKaUSS5M3_7TkY2bYFtdL:*/
        (/*is_intv*/ istaggedint_BM (  /*v_i:*/_.v_3vRFuniDv1K_4bQ7DeekM2I ))   //body when _5mfKaUSS5M3_7TkY2bYFtdL
            {
                /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B = //assign _4BlNNkRvjfq_3MnqGoiP3nH
                    /* val_to_int */ getint_BM( /*v_i:*/_.v_3vRFuniDv1K_4bQ7DeekM2I) ;
                /*return _860kWTaFg9p_8Jhm1G5uvqC:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned
                    /*taggedint:*/ taggedint_BM (/*add_int:*/(( /*ii:*/_.n_2W7Ckt2WxEM_4NVYgEWE73B) + ( 1)));
                goto epilog_43Y25VLmh6s_3JRpERevcR4;

            } //endwhen _5mfKaUSS5M3_7TkY2bYFtdL
        /*endcond _1UM3ERNWFgo_6pqkY9UiIDv*/

        /* !endingblock _7XasLoEUKwe_9upxyFeheD5 */
        goto endblock__7XasLoEUKwe_9upxyFeheD5;
endblock__7XasLoEUKwe_9upxyFeheD5:
        ;
    } /*-block _7XasLoEUKwe_9upxyFeheD5 */

epilog_43Y25VLmh6s_3JRpERevcR4:
    __attribute__ ((unused)); // routine _43Y25VLmh6s_3JRpERevcR4 epilogue:
    if (stkf) stkf->stkfram_callfun = NULL;
    return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _43Y25VLmh6s_3JRpERevcR4 routine#1 successor_test_minifunc




value_tyBM crout_9O2lgu1TweO_0mVlpTwrBG1_BM //#2+
(struct stackframe_stBM* stkf, // second_test_minifunc
//!second minifunc in test module
 // 1 arguments
 const value_tyBM arg0,  // v1
 const value_tyBM arg1_ __attribute__((unused)),
 const value_tyBM arg2_ __attribute__((unused)),
 const value_tyBM arg3_ __attribute__((unused)),
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
    // start of second_test_minifunc
    struct frame_9O2lgu1TweO_0mVlpTwrBG1_BMst
    {
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
        /// 0 scalar values:
    } _;
    memset (&_, 0, sizeof(struct frame_9O2lgu1TweO_0mVlpTwrBG1_BMst));
    _.stkfram_head.htyp = typayl_StackFrame_BM;
    _.stkfram_head.hgc = 0;
    _.stkfram_head.rlen = 2;
    _.stkfram_descr = constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM[7] /*|second_test_minifunc*/;
    ASSERT_BM (!stkf
               || stkf->stkfram_pA.htyp == typayl_StackFrame_BM
               || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);
    _.stkfram_prev = stkf;
    // fetch 1 arguments:
    _.v_5EEITf6IFH7_4DbKG99zcPW = arg0; // v1
    // fetched 1 arguments.
    // no closed values in second_test_minifunc.
    const closure_tyBM* callclos_9O2lgu1TweO_0mVlpTwrBG1 __attribute__((unused)) =
        (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)
        ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;
    const unsigned nbclosed_9O2lgu1TweO_0mVlpTwrBG1  __attribute__((unused)) = 0;
    // routine _9O2lgu1TweO_0mVlpTwrBG1 body:

startblock__8yXqsN7LuB3_0vODsT2M9Lh:
    __attribute__((unused));
    {
        /* +block _8yXqsN7LuB3_0vODsT2M9Lh */
        if /*cond _1rIoTXPOfGY_2AFqgfS5G7T*/
        /*when _2rCc2usyvqv_1TUCxOmrdFs:*/
        (/*is_intv*/ istaggedint_BM (  /*v1:*/_.v_5EEITf6IFH7_4DbKG99zcPW ))   //body when _2rCc2usyvqv_1TUCxOmrdFs
            {
                /*return _3g94RQiswhV_2O5raZogJao:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned
                    (constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM[1] /*!int*/);
                goto epilog_9O2lgu1TweO_0mVlpTwrBG1;

            } //endwhen _2rCc2usyvqv_1TUCxOmrdFs
        else if
        /*when _8ICBYlvMuJw_9rv1czcQPGI:*/
        (/*is_objectv*/ isobject_BM( /*v1:*/_.v_5EEITf6IFH7_4DbKG99zcPW))   //body when _8ICBYlvMuJw_9rv1czcQPGI
            {
                /*return _4NQMyG7YDk8_44PdNNG87Sr:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned
                    (constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM[4] /*!object*/);
                goto epilog_9O2lgu1TweO_0mVlpTwrBG1;

            } //endwhen _8ICBYlvMuJw_9rv1czcQPGI
        else   /*cond else _1rIoTXPOfGY_2AFqgfS5G7T*/
            {
                /*return _6NBwHeONub1_23PSzwWuTsb:*/  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ = // returned
                    (constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM[3] /*!value*/);
                goto epilog_9O2lgu1TweO_0mVlpTwrBG1;
            } /*cond else _1rIoTXPOfGY_2AFqgfS5G7T*/
        /*endcond _1rIoTXPOfGY_2AFqgfS5G7T*/

        /* !endingblock _8yXqsN7LuB3_0vODsT2M9Lh */
        goto endblock__8yXqsN7LuB3_0vODsT2M9Lh;
endblock__8yXqsN7LuB3_0vODsT2M9Lh:
        ;
    } /*-block _8yXqsN7LuB3_0vODsT2M9Lh */

epilog_9O2lgu1TweO_0mVlpTwrBG1:
    __attribute__ ((unused)); // routine _9O2lgu1TweO_0mVlpTwrBG1 epilogue:
    if (stkf) stkf->stkfram_callfun = NULL;
    return  /*v_r:*/_.v_3qw9bnATIhq_8loBraLeXzQ;
} // end _9O2lgu1TweO_0mVlpTwrBG1 routine#2 second_test_minifunc




// end of 3 generated routines


// the constant ids for 8 constants:
const char* const constid_9oXtCgAbkqv_4y1xhhF5Nhz_BM[8+1] =
{
    /*0:*/
    "_0qxuQEfimtp_1Wp2YuKHsJ3", //! test-objswitch(o1) minifunc
    "_0vgCFjXblkx_4zCMhMAWjVK",//int
    "_43Y25VLmh6s_3JRpERevcR4",//successor_test_minifunc
    "_7bbeIqUSje9_4jVgC7ZJmvx",//value
    "_7T9OwSFlgov_0wVJaK1eZbn",//object
    /*5:*/
    "_7YmEzAVe2hC_9iA0FVXAIqp",//hexa
    "_9oXtCgAbkqv_4y1xhhF5Nhz",//first_test_module
    "_9O2lgu1TweO_0mVlpTwrBG1",//second_test_minifunc
    NULL
}; // end 8 constant ids



// the routine ids for 3 routines:
const char* const routid_9oXtCgAbkqv_4y1xhhF5Nhz_BM[3+1] =
{
    /*0:*/
    "_0qxuQEfimtp_1Wp2YuKHsJ3", //!test-objswitch(o1) minifunc
    "_43Y25VLmh6s_3JRpERevcR4",//successor_test_minifunc
    "_9O2lgu1TweO_0mVlpTwrBG1",//second_test_minifunc

    NULL
}; // end 3 routine ids




// basiclo*module initialization
#ifdef BISMON_MODID
value_tyBM moduleinit_9oXtCgAbkqv_4y1xhhF5Nhz_BM
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
                           INFOPRINTF_BM("§initializing simple module _9oXtCgAbkqv_4y1xhhF5Nhz with arguments (%s, %s, %s); module counter 1",
                                         debug_outstr_value_BM (_.arg1v, CURFRAME_BM, 0),//
                                         debug_outstr_value_BM (_.arg2v, CURFRAME_BM, 0),//
                                         debug_outstr_value_BM (_.arg3v, CURFRAME_BM, 0),//
                                         module_count_BM()); //
                           return simple_module_initialize_BM(arg1, arg2, arg3, //
                                   "_9oXtCgAbkqv_4y1xhhF5Nhz",//
                                   constob_9oXtCgAbkqv_4y1xhhF5Nhz_BM, //
                                   constid_9oXtCgAbkqv_4y1xhhF5Nhz_BM, //
                                   routid_9oXtCgAbkqv_4y1xhhF5Nhz_BM, //
                                   dlh, CURFRAME_BM);
} // end moduleinit_9oXtCgAbkqv_4y1xhhF5Nhz_BM
#endif /*BISMON_MODID*/




/************
 ** for Emacs:
 ** Local Variables: ;;
 ** compile-command: "make -k -j -C .. modules" ;;
 ** End: ;;
 ************/



// end of generated persistent module first_test_module in file modbm_9oXtCgAbkqv_4y1xhhF5Nhz.c
