// file engine_BM.c

/***
    BISMON 
    Copyright © 2018 Basile Starynkevitch (working at CEA, LIST, France)
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
***/


#include "bismon.h"
#include "engine_BM.const.h"

#define MAXMINIFRAMEDEPTH_BM 256
// expertise command_handler _5W4PPQFYdj2_3HYUlMsu3oZ
extern objrout_sigBM ROUTINEOBJNAME_BM (_5W4PPQFYdj2_3HYUlMsu3oZ);

value_tyBM
ROUTINEOBJNAME_BM (_5W4PPQFYdj2_3HYUlMsu3oZ)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // the reciever
 const value_tyBM arg2,         // the comment or origin
 const value_tyBM arg3_ __attribute__ ((unused)),       //
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_5W4PPQFYdj2_3HYUlMsu3oZ,
                 value_tyBM argv;
                 objectval_tyBM * prevexpertiseob;
                 objectval_tyBM * thisexpertiseob;
                 value_tyBM exprocv;
    );
  objectval_tyBM *k_current_expertise = BMK_1Lw70JO0z4y_7VFmnlVAN2U;
  objectval_tyBM *k_expertise = BMK_3BK1iRJQKks_9em7267pi4g;
  objectval_tyBM *k_expertise_processor = BMK_3MH3SdE0EjN_03eZz7SPOY1;
  _.argv = arg1;
  if (isobject_BM (_.argv))
    {
      _.thisexpertiseob = _.argv;
      bool good = false;
      objlock_BM (_.thisexpertiseob);
      if (objclass_BM (_.thisexpertiseob) == BMP_object)
        {
          objputclass_BM (_.thisexpertiseob, k_expertise);
          objtouchnow_BM (_.thisexpertiseob);
          good = true;
        }
      else
        good = objectisinstance_BM (_.thisexpertiseob, k_expertise);
      objunlock_BM (_.thisexpertiseob);
      if (!good)
        {
          if (pthread_self () == mainthreadid_BM)
            {
              log_begin_message_BM ();
              log_puts_message_BM
                ("invalid argument to ,expertise command: ");
              log_object_message_BM (_.thisexpertiseob);
              log_puts_message_BM
                ("; should be a plain `object`, or an instance of `expertise` or a string.");
              log_end_message_BM ();
            };
          LOCALRETURN_BM (NULL);
        }
    }
  else if (isstring_BM (_.argv))
    {
      _.thisexpertiseob = makeobj_BM ();
      objputclass_BM (_.thisexpertiseob, k_expertise);
      objputspacenum_BM (_.thisexpertiseob, GlobalSp_BM);
      objputattr_BM (_.thisexpertiseob, BMP_comment, _.argv);
      if (pthread_self () == mainthreadid_BM)
        {
          log_begin_message_BM ();
          log_puts_message_BM (",expertise created ");
          log_object_message_BM (_.thisexpertiseob);
          log_printf_message_BM (" : %s", bytstring_BM (_.argv));
          log_end_message_BM ();
        };
    }
  else
    {
      if (pthread_self () == mainthreadid_BM)
        {
          log_begin_message_BM ();
          log_puts_message_BM
            ("bad argument to ,expertise command, object or comment-string expected");
          log_end_message_BM ();
        };
      LOCALRETURN_BM (NULL);
    }
  {
    objlock_BM (BMP_the_system);
    _.prevexpertiseob =
      objectcast_BM (objgetattr_BM (BMP_the_system, k_current_expertise));
    _.exprocv = objgetattr_BM (BMP_the_system, k_expertise_processor);
    if (_.prevexpertiseob != _.thisexpertiseob)
      {
        objputattr_BM (BMP_the_system, k_current_expertise,
                       _.thisexpertiseob);
        objtouchnow_BM (BMP_the_system);
      }
    objunlock_BM (BMP_the_system);
  }
  if (isobject_BM (_.prevexpertiseob)
      && _.prevexpertiseob != _.thisexpertiseob)
    {
      apply1_BM (_.exprocv, (struct stackframe_stBM *) &_, _.prevexpertiseob);
    }
  LOCALRETURN_BM (_.argv);
}                               /* end expertise command_handler _5W4PPQFYdj2_3HYUlMsu3oZ */




// method run_tasklet°tiny_tasklet _1etImV3nBtp_5rnHSE87XRj
extern objrout_sigBM ROUTINEOBJNAME_BM (_1etImV3nBtp_5rnHSE87XRj);

value_tyBM
ROUTINEOBJNAME_BM (_1etImV3nBtp_5rnHSE87XRj)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recv
 const value_tyBM arg2_ __attribute__ ((unused)),       //
 const value_tyBM arg3_ __attribute__ ((unused)),       //
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_1etImV3nBtp_5rnHSE87XRj,
                 objectval_tyBM * recv; value_tyBM * todov;
                 value_tyBM * resv;
    );
  objectval_tyBM *k_todo = BMK_7ljWW4bj70g_9PL9dZkgBxZ;
  _.recv = objectcast_BM (arg1);
  WEAKASSERT_BM (_.recv != NULL);
  NONPRINTF_BM ("run_tasklet°tiny_tasklet recv %s", objectdbg_BM (_.recv));
  objlock_BM (_.recv);
  _.todov = objgetattr_BM (_.recv, k_todo);
  _.resv = apply1_BM (_.todov, (struct stackframe_stBM *) &_, _.recv);
  objunlock_BM (_.recv);
  NONPRINTF_BM ("run_tasklet°tiny_tasklet recv %s applied todo %s",    //
                objectdbg_BM (_.recv),  //
                debug_outstr_value_BM (_.todov, //
                                       (struct stackframe_stBM *) &_, 0));
  LOCALRETURN_BM (_.resv);
}                               /* end run_tasklet°tiny_tasklet  _1etImV3nBtp_5rnHSE87XRj */

// run a mini frame, and returns true if the current tasklet should be interrupted
static bool run_mini_frame_BM (objectval_tyBM * framob,
                               objectval_tyBM * taskob,
                               struct stackframe_stBM *stkf);

// run_tasklet°mini_tasklet _8gAuOE933W3_5s7IF0hgpkz
extern objrout_sigBM ROUTINEOBJNAME_BM (_8gAuOE933W3_5s7IF0hgpkz);
#define MINICPUTHRESHOLD_BM 0.005
#define MINIELAPSEDTHRESHOLD_BM 0.03
value_tyBM
ROUTINEOBJNAME_BM (_8gAuOE933W3_5s7IF0hgpkz)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         //taskob
 const value_tyBM arg2_ __attribute__ ((unused)),       //
 const value_tyBM arg3_ __attribute__ ((unused)),       //
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_8gAuOE933W3_5s7IF0hgpkz,
                 objectval_tyBM * taskob; objectval_tyBM * framob;
                 objectval_tyBM * frclassob;
    );
  objectval_tyBM *k_mini_frame = BMK_7iXMCmAFuoe_5IaAOnyr7vZ;
  _.taskob = arg1;
  do
    {
      unsigned nbc = objnbcomps_BM (_.taskob);
      if (!nbc)
        break;
      _.frclassob = NULL;
      _.framob = objectcast_BM (objlastcomp_BM (_.taskob));
      objpoplastcomp_BM (_.taskob);
      if (!_.framob)
        continue;
      {
        bool stoprun = false;
        objlock_BM (_.framob);
        _.frclassob = objclass_BM (_.framob);
        if (_.frclassob == k_mini_frame)
          stoprun = run_mini_frame_BM (_.framob, _.taskob,
                                       (struct stackframe_stBM *) &_);
        objunlock_BM (_.framob);
        if (stoprun)
          break;
      }
    }
  while (taskletcputime_BM () < MINICPUTHRESHOLD_BM
         && taskletelapsedtime_BM () < MINIELAPSEDTHRESHOLD_BM);
#warning unimplemented _8gAuOE933W3_5s7IF0hgpkz routine
  WEAKASSERT_BM (false && "unimplemented _8gAuOE933W3_5s7IF0hgpkz routine");
  LOCALRETURN_BM (_.taskob);
}                               /* end run_tasklet°mini_tasklet _8gAuOE933W3_5s7IF0hgpkz */

enum minievalstate_enBM
{
  mes__NONE,
  mes_withresult,
  mes_framechange,
  mes_taskletchange,
};

static value_tyBM
evaluate_in_mini_frame_BM (value_tyBM expv,
                           objectval_tyBM * framob,
                           objectval_tyBM * taskob,
                           enum minievalstate_enBM *pevalstate,
                           struct stackframe_stBM *stkf);

bool
run_mini_frame_BM (objectval_tyBM * framob, objectval_tyBM * taskob,
                   struct stackframe_stBM *stkf)
{
  LOCALFRAME_BM (stkf, /*descr: */ NULL,
                 objectval_tyBM * taskob;
                 objectval_tyBM * framob; objectval_tyBM * curstatev;
                 value_tyBM curseqv; value_tyBM curcompv;
                 value_tyBM curvalv;
    );
  objectval_tyBM *k_state = BMK_5zHhLVgR3Dv_1zf1cxOQlJ4;
  objectval_tyBM *k_evaluate_sequence = BMK_8gAuOE933W3_5s7IF0hgpkz;
  objectval_tyBM *k_rank = BMK_8zRh2medTlP_0ImnPyO8NKH;
  objectval_tyBM *k_mini_frame = BMK_7iXMCmAFuoe_5IaAOnyr7vZ;
  _.framob = framob;
  _.taskob = taskob;
  WEAKASSERT_BM (objectisinstance_BM (_.framob, k_mini_frame));
  _.curstatev = objgetattr_BM (_.framob, k_state);
  if (_.curstatev == k_evaluate_sequence)
    {
      enum minievalstate_enBM es = mes__NONE;
      _.curseqv = objgetattr_BM (_.framob, k_evaluate_sequence);
      int rk = getint_BM (objgetattr_BM (_.framob, k_rank));
      _.curcompv = nodenthson_BM (_.curseqv, rk);
      _.curvalv = NULL;
      _.curvalv =
        evaluate_in_mini_frame_BM (_.curcompv, _.framob, _.taskob, &es,
                                   (struct stackframe_stBM *) &_);
      objputattr_BM (_.framob, k_rank, taggedint_BM (rk + 1));
      WEAKASSERT_BM (es >= mes_withresult && es <= mes_taskletchange);
      if (es == mes_framechange || mes_withresult)
        return false;
      else if (es == mes_taskletchange)
        return true;
    }
  WEAKASSERT_BM (false && "unimplemented run_mini_frame_BM");
#warning unimplemented run_mini_frame_BM
}                               /* end run_mini_frame_BM */



value_tyBM
evaluate_in_mini_frame_BM (value_tyBM expv, objectval_tyBM * framob,
                           objectval_tyBM * taskob,
                           enum minievalstate_enBM * pevalstate,
                           struct stackframe_stBM * stkf)
{
  LOCALFRAME_BM (stkf, /*descr: */ NULL,
                 objectval_tyBM * taskob; objectval_tyBM * framob;
                 objectval_tyBM * initialframob; objectval_tyBM * connob;
                 objectval_tyBM * varob; value_tyBM expv;
                 value_tyBM valv;
                 value_tyBM errorv;);
  objectval_tyBM *k_syntax_error = BMK_7UGHYP5h2vc_5O70fk0ifBL;
  objectval_tyBM *k_unbound_variable_error = BMK_68PQkZp1UAq_8RNb44Ea88z;
  objectval_tyBM *k_mini_frame = BMK_7iXMCmAFuoe_5IaAOnyr7vZ;
  objectval_tyBM *k_previous_frame = BMK_7ALBmiM4ZPF_2LtorcTj8gO;
  _.expv = expv;
  _.taskob = taskob;
  _.framob = framob;
  WEAKASSERT_BM (isobject_BM (_.taskob));
  WEAKASSERT_BM (isobject_BM (_.framob));
  _.initialframob = _.framob;
  ASSERT_BM (pevalstate != NULL);
  if (!isnode_BM (_.expv))
    {
      *pevalstate = mes_withresult;
      LOCALRETURN_BM (_.expv);
    }
  _.connob = nodeconn_BM (_.expv);
  unsigned exparity = nodewidth_BM (_.expv);
  // ?var retrieves the var's value
  if (_.connob == BMP_question && exparity == 1)
    {
      _.varob = objectcast_BM (nodenthson_BM (_.expv, 0));
      if (!_.varob)
        {
          _.errorv = makenodevar_BM (k_syntax_error, _.expv, NULL);
          FAILURE_BM (__LINE__, _.errorv, (struct stackframe_stBM *) &_);
        }
      // find _.varob's binding in some frame
      int framedepth = 0;
      while (isobject_BM (_.framob))
        {
          framedepth++;
          if (framedepth > MAXMINIFRAMEDEPTH_BM
              || !objectisinstance_BM (_.framob, k_mini_frame)
              || !objhasassocpayl_BM (_.framob))
            {
              _.errorv = makenodevar_BM (k_mini_frame, _.framob,
                                         taggedint_BM (framedepth), NULL);
              FAILURE_BM (__LINE__, _.errorv, (struct stackframe_stBM *) &_);
            }
          _.valv = objassocgetattrpayl_BM (_.framob, _.varob);
          if (_.valv)
            {
              *pevalstate = mes_withresult;
              LOCALRETURN_BM (_.valv);
            }
          _.framob = objgetattr_BM (_.framob, k_previous_frame);
        }
      {
        _.errorv =
          makenodevar_BM (k_unbound_variable_error, _.varob, _.framob, NULL);
        FAILURE_BM (__LINE__, _.errorv, (struct stackframe_stBM *) &_);
      }
    }                           /* end ?var */
  // !thing gives the thing (like quote in lisp)
  else if (_.connob == BMP_exclam && exparity == 1)
    {
      _.valv = objectcast_BM (nodenthson_BM (_.expv, 0));
      *pevalstate = mes_withresult;
      LOCALRETURN_BM (_.valv);
    }
#warning evaluate_in_mini_frame_BM very incomplete
  WEAKASSERT_BM (false && "unimplemented evaluate_in_mini_frame_BM");
}                               /* end evaluate_in_mini_frame_BM */
