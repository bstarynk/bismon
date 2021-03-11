// file gencode_BM.c
// SPDX-License-Identifier: GPL-3.0-or-later
/***
    BISMON 
    Copyright © 2018 - 2021 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch (working at CEA, LIST, France)
    <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>

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
#include "gencode_BM.const.h"

#define MAXINTCASES_BM 16384

extern const char *asprintf_prev_module_BM (const char *srcdir,
                                            objectval_tyBM * obmodule);

const char *
asprintf_prev_module_BM (const char *srcdir, objectval_tyBM * obmodule)
{
  char *pathstr = NULL;
  char modulidbuf[32];
  objectval_tyBM *k_plain_temporary_module = BMK_1oEp0eAAyFN_4lsobepyr1T;
  memset (modulidbuf, 0, sizeof (modulidbuf));
  ASSERT_BM (srcdir && strlen (srcdir) > 0);
  ASSERT_BM (isobject_BM (obmodule));
  bool modulistemporary =
    (objectisinstance_BM (obmodule, k_plain_temporary_module));
  idtocbuf32_BM (objid_BM (obmodule), modulidbuf);
  if (modulistemporary)
    asprintf (&pathstr, "%s/" TEMPMODULEPREFIX_BM "%s.c-prev%d~",
              srcdir, modulidbuf, (int) getpid ());
  else
    asprintf (&pathstr, "%s/" MODULEPREFIX_BM "%s.c-prev%d~",
              srcdir, modulidbuf, (int) getpid ());
  if (!pathstr)
    FATAL_BM ("failed asprintf_prev_module srcdir %s obmodule %s - %m",
              srcdir, objectdbg_BM (obmodule));
  return pathstr;
}                               /* end asprintf_prev_module_BM */



////////////////


//// for the method prepare_routine°basiclo_minifunction
extern objrout_sigBM ROUTINEOBJNAME_BM (_07qYMXftJRR_9dde2ASz4e9);

value_tyBM
ROUTINEOBJNAME_BM (_07qYMXftJRR_9dde2ASz4e9)    //  prepare_routine°basiclo_minifunction
(struct stackframe_stBM * stkf, const value_tyBM arg1,  // reciever
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // prepvalset
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))      //
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ BMK_07qYMXftJRR_9dde2ASz4e9,
                 objectval_tyBM * modgenob;     //
                 const setval_tyBM * prepvalset;        //
                 objectval_tyBM * curprepob;    //
                 objectval_tyBM * curtypob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * obhsetblock;  //
                 objectval_tyBM * typob;        //
                 objectval_tyBM * bodyob;       //
                 objectval_tyBM * obmodhsetconst;       //
                 objectval_tyBM * stmtpropob;   //
                 value_tyBM recv;       //
                 value_tyBM attrv;      //
                 const tupleval_tyBM * tupargs; //
                 const tupleval_tyBM * tupclosed;       //
                 objectval_tyBM * obresult;     //
                 const setval_tyBM * setlocals; //
                 const setval_tyBM * setnumbers;        //
                 const setval_tyBM * setscalars;        //
                 const setval_tyBM * setconsts; //
                 objectval_tyBM * curvar;       //
                 objectval_tyBM * scalctypob;   //
                 value_tyBM curol;      //
                 value_tyBM oldrol;     //
                 value_tyBM bodyv;      //
                 value_tyBM msblov;     //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
    );
  objectval_tyBM *k_c_type = BMK_83kM1HtO8K3_6k0F2KYQT3W;
  objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  objectval_tyBM *k_result = BMK_7bD9VtDkGSn_7lxHeYuuFLR;
  objectval_tyBM *k_closed = BMK_2TwOyPJxIz8_1rIeqaN7oRz;
  objectval_tyBM *k_locals = BMK_24sSVIADeHm_0Sx34wQfG7W;
  objectval_tyBM *k_numbers = BMK_32eKNcTZ9HN_80t0nk47Mha;
  objectval_tyBM *k_body = BMK_7DQyvJFMOrC_9IfC3CtYknn;
  objectval_tyBM *k_scalars = BMK_3pPxQecoSkC_7izL0jcxZiS;
  objectval_tyBM *k_scalar_c_type = BMK_68ZSdtDWjWk_4Dex1apSdO7;
  objectval_tyBM *k_simple_routine_preparation = BMK_80060zKi6Un_3isCStegT8A;
  objectval_tyBM *k_hset_object = BMK_8c9otZ4pwR6_55k81qyyYV2;
  objectval_tyBM *k_assoc_object = BMK_6ZQ05nCv3Ys_8LA6B5LkZgm;
  objectval_tyBM *k_blocks = BMK_2lCuMosXupr_5GAoqVgJ8PZ;
  objectval_tyBM *k_statement_properties = BMK_0OM3NoUpOBd_1nzwCJKw54A;
  objectval_tyBM *k_prepare_routine = BMK_6qi1DW0Ygkl_4Aqdxq4n5IV;
  objectval_tyBM *k_in = BMK_0eMGYofuNVh_8ZP2mXdhtHO;
  objectval_tyBM *k_modgenob = BMK_0Bl5ro9usp6_1Hll14QwC8f;
  objectval_tyBM *k_miniscan_block = BMK_2gthNYOWogO_4sVTU1JbmUH;
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  // retrieve arguments
  _.recv = objectcast_BM (arg1);
  WEAKASSERT_BM (isobject_BM (_.recv));
  _.modgenob = objectcast_BM (arg2);
  _.prepvalset = setcast_BM (arg3);     /// unneeded, set of all routines
  WEAKASSERT_BM (_.modgenob != NULL);
  _.obmodhsetconst = objectcast_BM (objgetattr_BM (_.modgenob, k_constants));
  WEAKASSERT_BM (_.prepvalset != NULL);
  unsigned nbprep = setcardinal_BM (_.prepvalset);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ;  _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("start prepare_routine°basiclo_minifunction recv=%s modgenob=%s nbprep=%u obmodhsetconst=%s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.modgenob), nbprep,
     objectdbg2_BM (_.obmodhsetconst));
  {
    _.attrv = objgetattr_BM (_.recv, k_arguments);
    _.tupargs = tuplecast_BM (_.attrv);
    if (_.attrv && !_.tupargs)
      FAILHERE (makenode1_BM (k_arguments, _.attrv));
    _.attrv = NULL;
  }
  {
    _.attrv = objgetattr_BM (_.recv, k_closed);
    _.tupclosed = tuplecast_BM (_.attrv);
    if (_.attrv && !_.tupclosed)
      FAILHERE (makenode1_BM (k_closed, _.attrv));
    _.attrv = NULL;
  }
  {
    _.attrv = objgetattr_BM (_.recv, k_result);
    _.obresult = objectcast_BM (_.attrv);
    if (_.attrv && !_.obresult)
      FAILHERE (makenode1_BM (k_result, _.attrv));
    _.attrv = NULL;
  }
  {
    _.attrv = objgetattr_BM (_.recv, k_locals);
    _.setlocals = setcast_BM (_.attrv);
    if (_.attrv && !_.setlocals)
      FAILHERE (makenode1_BM (k_locals, _.attrv));
    _.attrv = NULL;
  }
  {
    _.attrv = objgetattr_BM (_.recv, k_numbers);
    _.setnumbers = setcast_BM (_.attrv);
    if (_.attrv && !_.setnumbers)
      FAILHERE (makenode1_BM (k_numbers, _.attrv));
    _.attrv = NULL;
  }
  {
    _.attrv = objgetattr_BM (_.recv, k_scalars);
    _.setscalars = setcast_BM (_.attrv);
    if (_.attrv && !_.setscalars)
      FAILHERE (makenode1_BM (k_scalars, _.attrv));
    DBGPRINTF_BM
      ("prepare_routine°basiclo_minifunction recv=%s setscalars %s",
       objectdbg_BM (_.recv), OUTSTRVALUE_BM ((value_tyBM)_.setscalars));
    _.attrv = NULL;
  }
  {
    _.attrv = objgetattr_BM (_.recv, k_constants);
    _.setconsts = setcast_BM (_.attrv);
    if (_.attrv && !_.setconsts)
      FAILHERE (makenode1_BM (k_constants, _.attrv));
    _.attrv = NULL;
  }
  DBGPRINTF_BM
    ("prepare_routine°basiclo_minifunction recv=%s tupargs=%s tupclosed=%s  obresult=%s",
     objectdbg_BM (_.recv), OUTSTRVALUE_BM ((value_tyBM)_.tupargs),
     OUTSTRVALUE_BM ((value_tyBM)_.tupclosed), objectdbg2_BM (_.obresult));
  DBGPRINTF_BM
    ("prepare_routine°basiclo_minifunction recv=%s setlocals=%s, setnumbers=%s, setscalars=%s, setconsts=%s",
     objectdbg_BM (_.recv),
     OUTSTRVALUE_BM ((value_tyBM)_.setlocals), OUTSTRVALUE_BM ((value_tyBM)_.setnumbers),
     OUTSTRVALUE_BM ((value_tyBM)_.setscalars), OUTSTRVALUE_BM ((value_tyBM)_.setconsts));
  _.bodyv = objgetattr_BM (_.recv, k_body);
  if (!isobject_BM (_.bodyv))
    {
      FAILHERE (makenode1_BM (k_body, _.bodyv));
    }
  _.bodyob = objectcast_BM (_.bodyv);
  if (!isobject_BM (_.obresult))
    FAILHERE (makenode1_BM (k_result, _.recv));
  WEAKASSERT_BM (_.bodyob);
  WEAKASSERT_BM (isobject_BM (_.obmodhsetconst)
                 && objhashashsetpayl_BM (_.obmodhsetconst));
  objhashsetaddpayl_BM (_.obmodhsetconst, _.recv);
  _.routprepob = makeobj_BM ();
  objputclass_BM (_.routprepob,
                  (objectval_tyBM *) k_simple_routine_preparation);
  objputattr_BM (_.routprepob, k_in, _.recv);
  objputattr_BM (_.routprepob, k_modgenob, _.modgenob);
  unsigned nbargs = tuplesize_BM (_.tupargs);
  unsigned nbclosed = tuplesize_BM (_.tupclosed);
  unsigned nblocals = setcardinal_BM (_.setlocals);
  unsigned nbnumbers = setcardinal_BM (_.setnumbers);
  unsigned nbscalars = setcardinal_BM (_.setscalars);
  unsigned nbconsts = setcardinal_BM (_.setconsts);
  DBGPRINTF_BM
    ("start prepare_routine°basiclo_minifunction recv %s routprepob %s nbargs=%u nbclosed=%u nblocals=%u nbnumbers=%u nbscalars=%u nbconsts=%u",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob), nbargs, nbclosed,
     nblocals, nbnumbers, nbscalars, nbconsts);
  objputassocpayl_BM (_.routprepob,
                      2 + nbargs + nbclosed + nblocals + nbnumbers
                      + nbscalars + nbconsts);
  objtouchnow_BM (_.routprepob);
  DBGPRINTF_BM
    ("start prepare_routine°basiclo_minifunction recv %s routprepob %s obresult %s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob),
     objectdbg2_BM (_.obresult));
  //// check and bind the result
  if (_.obresult)
    {
      objlock_BM (_.obresult);
      _.typob = objectcast_BM (objgetattr_BM (_.obresult, k_c_type));
      objunlock_BM (_.obresult);
      if (_.typob != BMP_value && _.typob != BMP_object)
        FAILHERE (makenode1_BM (k_result, _.obresult));
      objassocaddattrpayl_BM (_.routprepob, _.obresult,
                              (value_tyBM) k_result);
    }
  DBGPRINTF_BM
    ("start prepare_routine°basiclo_minifunction recv %s routprepob %s tupargs %s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob),
     debug_outstr_value_BM ((value_tyBM) _.tupargs, CURFRAME_BM, 0));
  /// bind the arguments
  for (unsigned argix = 0; argix < nbargs; argix++)
    {
      _.curvar = tuplecompnth_BM (_.tupargs, argix);
      _.curtypob = NULL;
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction argix=%u argum curvar=%s",
         argix, objectdbg_BM (_.curvar));
      _.oldrol = objassocgetattrpayl_BM (_.routprepob, _.curvar);
      if (_.oldrol)
        FAILHERE (makenode2_BM (k_arguments, _.curvar, _.oldrol));
      objlock_BM (_.curvar);
      _.curtypob = objectcast_BM (objgetattr_BM (_.curvar, k_c_type));
      objunlock_BM (_.curvar);
      if (!_.curtypob)
        _.curtypob = BMP_value;
      if (_.curtypob != BMP_value && _.curtypob != BMP_object)
        FAILHERE (makenode2_BM (k_arguments, _.curvar, _.curtypob));
      _.curol =
        (value_tyBM) makenode2_BM (k_arguments, taggedint_BM (argix),
                                   _.curtypob);
      objassocaddattrpayl_BM (_.routprepob, _.curvar, _.curol);
      _.curol = NULL;
      _.curtypob = NULL;
    }
  DBGPRINTF_BM
    ("start prepare_routine°basiclo_minifunction recv %s routprepob %s tupclosed %s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob),
     debug_outstr_value_BM ((value_tyBM) _.tupclosed, CURFRAME_BM, 0));
  /// bind the closed
  for (unsigned cloix = 0; cloix < nbclosed; cloix++)
    {
      _.curvar = tuplecompnth_BM (_.tupclosed, cloix);
      _.curtypob = NULL;
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction cloix=%u closed curvar=%s",
         cloix, objectdbg_BM (_.curvar));
      _.oldrol = objassocgetattrpayl_BM (_.routprepob, _.curvar);
      if (_.oldrol)
        FAILHERE (makenode2_BM (k_closed, _.curvar, _.oldrol));
      objlock_BM (_.curvar);
      _.curtypob = objectcast_BM (objgetattr_BM (_.curvar, k_c_type));
      objunlock_BM (_.curvar);
      if (!_.curtypob)
        _.curtypob = BMP_value;
      if (_.curtypob != BMP_value && _.curtypob != BMP_object)
        FAILHERE (makenode2_BM (k_arguments, _.curvar, _.curtypob));
      _.curol =
        (value_tyBM) makenode2_BM (k_closed, taggedint_BM (cloix),
                                   _.curtypob);
      objassocaddattrpayl_BM (_.routprepob, _.curvar, _.curol);
      _.curol = NULL;
      _.curtypob = NULL;
    }
  /// bind the locals
  DBGPRINTF_BM
    ("prepare_routine°basiclo_minifunction recv %s routprepob %s setlocals %s nb#%d",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob),
     OUTSTRVALUE_BM ((value_tyBM) _.setlocals), nblocals);
  for (unsigned locix = 0; locix < nblocals; locix++)
    {
      _.curvar = setelemnth_BM (_.setlocals, locix);
      DBGPRINTF_BM
        ("prepare_routine°basiclo_minifunction locix=%u local curvar=%s",
         locix, objectdbg_BM (_.curvar));
      _.oldrol = objassocgetattrpayl_BM (_.routprepob, _.curvar);
      if (_.oldrol)
        {
          FAILHERE (makenode2_BM (k_locals, _.curvar, _.oldrol));
        }
      objlock_BM (_.curvar);
      _.curtypob = objectcast_BM (objgetattr_BM (_.curvar, k_c_type));
      objunlock_BM (_.curvar);
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction recv %s, routprepob %s, curvar %s, curtypob %s",
         objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob),
         objectdbg2_BM (_.curvar), objectdbg3_BM (_.curtypob));
      if (!_.curtypob)
        _.curtypob = BMP_value;
      if (_.curtypob != BMP_value && _.curtypob != BMP_object)
        FAILHERE (makenode2_BM (k_locals, _.curvar, _.curtypob));
      _.curol =
        (value_tyBM) makenode2_BM (k_locals, taggedint_BM (locix),
                                   _.curtypob);
      objassocaddattrpayl_BM (_.routprepob, _.curvar, _.curol);
      _.curol = NULL;
    }
  /// bind the numbers
  DBGPRINTF_BM
    ("prepare_routine°basiclo_minifunction recv %s routprepob %s setnumbers %s nb#%u",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob),
     OUTSTRVALUE_BM ((value_tyBM) _.setnumbers), nbnumbers);
  // bind the number vars
  for (unsigned numix = 0; numix < nbnumbers; numix++)
    {
      _.curvar = setelemnth_BM (_.setnumbers, numix);
      DBGPRINTF_BM
        ("start prepare_routine°basiclo_minifunction numix=%u number curvar=%s",
         numix, objectdbg_BM (_.curvar));
      _.oldrol = objassocgetattrpayl_BM (_.routprepob, _.curvar);
      if (_.oldrol)
        {
          FAILHERE (makenode2_BM (k_numbers, _.curvar, _.oldrol));
        }
      _.curol = (value_tyBM) makenode1_BM (k_numbers, taggedint_BM (numix));
      objassocaddattrpayl_BM (_.routprepob, _.curvar, _.curol);
      _.curol = NULL;
    }
  ///
  /// bind the scalars
  DBGPRINTF_BM
    ("prepare_routine°basiclo_minifunction recv %s routprepob %s setscalars %s nb#%u",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob),
     OUTSTRVALUE_BM ((value_tyBM) _.setscalars), nbscalars);
  // bind the scalars vars
  for (unsigned scalix = 0; scalix < nbscalars; scalix++)
    {
      _.curvar = setelemnth_BM (_.setscalars, scalix);
      DBGPRINTF_BM
        ("prepare_routine°basiclo_minifunction scalix=%u scalar curvar=%s",
         scalix, objectdbg_BM (_.curvar));
      _.oldrol = objassocgetattrpayl_BM (_.routprepob, _.curvar);
      if (_.oldrol)
        {
          FAILHERE (makenode2_BM (k_scalars, _.curvar, _.oldrol));
        };
      {
        objlock_BM (_.curvar);
        _.curtypob = objectcast_BM (objgetattr_BM (_.curvar, k_c_type));
        objunlock_BM (_.curvar);
        DBGBACKTRACEPRINTF_BM
          ("prepare_routine°basiclo_minifunction scalix=%u scalar curvar=%s curtypob=%s",
           scalix, objectdbg_BM (_.curvar), objectdbg1_BM (_.curtypob));
        if (!_.curtypob)
          {
            FAILHERE (makenode2_BM (k_scalars, _.curvar, k_c_type));
          };
        _.scalctypob = NULL;
        objlock_BM (_.curtypob);
        _.scalctypob =
          objectcast_BM (objgetattr_BM (_.curtypob, k_scalar_c_type));
        objunlock_BM (_.curtypob);
        DBGBACKTRACEPRINTF_BM
          ("start prepare_routine°basiclo_minifunction scalar curvar=%s curtypob=%s scalctypob=%s",
           objectdbg_BM (_.curvar), objectdbg1_BM (_.curtypob),
           objectdbg2_BM (_.scalctypob));
        if (!_.scalctypob)
          {
            FAILHERE (makenode2_BM (k_scalar_c_type, _.curvar, _.curtypob));
          }
      }
      _.curol =
        (value_tyBM) makenode2_BM (k_scalars, taggedint_BM (scalix),
                                   _.curtypob);
      objassocaddattrpayl_BM (_.routprepob, _.curvar, _.curol);
      DBGBACKTRACEPRINTF_BM
        ("start prepare_routine°basiclo_minifunction scalar#%d routprepob=%s curvar=%s curol=%s",
         scalix, objectdbg1_BM (_.routprepob), objectdbg1_BM (_.curvar),
         OUTSTRVALUE_BM (_.curol));
      _.curol = NULL;
    }
  ///
  ///
  // bind the constants
  DBGPRINTF_BM
    (" prepare_routine°basiclo_minifunction recv %s routprepob %s setconsts %s nb#%u",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob),
     OUTSTRVALUE_BM ((value_tyBM) _.setconsts), nbconsts);
  for (unsigned cstix = 0; cstix < nbconsts; cstix++)
    {
      _.curvar = setelemnth_BM (_.setconsts, cstix);
      DBGPRINTF_BM
        ("prepare_routine°basiclo_minifunction cstix=%u constant curvar=%s",
         cstix, objectdbg_BM (_.curvar));
      _.oldrol = objassocgetattrpayl_BM (_.routprepob, _.curvar);
      if (_.oldrol)
        {
          FAILHERE (makenode2_BM (k_constants, _.curvar, _.oldrol));
        }
      _.curol = (value_tyBM) makenode1_BM (k_constants, taggedint_BM (cstix));
      objassocaddattrpayl_BM (_.routprepob, _.curvar, _.curol);
      objhashsetaddpayl_BM (_.obmodhsetconst, _.curvar);
      _.curol = NULL;
    }
  _.obhsetblock = makeobj_BM ();
  objputhashsetpayl_BM (_.obhsetblock, 15);
  objputclass_BM (_.obhsetblock, (objectval_tyBM *) k_hset_object);
  objputattr_BM (_.routprepob, k_blocks, _.obhsetblock);
  objputattr_BM (_.routprepob, k_prepare_routine, _.recv);
  objputattr_BM (_.routprepob, k_in, _.modgenob);
  objputattr_BM (_.obhsetblock, k_in, _.routprepob);
  _.stmtpropob = makeobj_BM ();
  objputassocpayl_BM (_.stmtpropob, 15);
  objputclass_BM (_.stmtpropob, (objectval_tyBM *) k_assoc_object);
  objputattr_BM (_.stmtpropob, k_in, _.routprepob);
  objputattr_BM (_.routprepob, k_statement_properties, _.stmtpropob);
  objtouchnow_BM (_.obhsetblock);
  objtouchnow_BM (_.routprepob);
  DBGPRINTF_BM
    ("prepare_routine°basiclo_minifunction before miniscan_block recv %s routprep %s bodyob %s of %s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob),
     objectdbg2_BM (_.bodyob), objectdbg3_BM (objclass_BM (_.bodyob)));
  {
    objlock_BM (_.bodyob);
    if (!objectisinstance_BM (_.bodyob, k_basiclo_block))
      {
        DBGPRINTF_BM
          ("prepare_routine°basiclo_minifunction recv %s bad bodyob %s of %s",
           objectdbg_BM (_.recv), objectdbg_BM (_.bodyob),
           objectdbg3_BM (objclass_BM (_.bodyob)));
        FAILHERE (makenode2_BM (k_body, _.bodyob, _.recv));
      }
    DBGPRINTF_BM
      ("prepare_routine°basiclo_minifunction recv %s before send miniscan_block to body %s routprepob %s",
       objectdbg_BM (_.recv), objectdbg1_BM (_.bodyob),
       objectdbg2_BM (_.routprepob));
    _.msblov =
      send3_BM (_.bodyob, k_miniscan_block, CURFRAME_BM, _.routprepob,
                taggedint_BM (0), _.recv);
    objunlock_BM (_.bodyob);
  }
  if (!_.msblov)
    {
      DBGPRINTF_BM
        ("prepare_routine°basiclo_minifunction failed miniscan_block bodyob=%s of %s",
         objectdbg_BM (_.bodyob), objectdbg1_BM (objclass_BM (_.bodyob)));
      FAILHERE (makenode1_BM (k_miniscan_block, _.bodyob));
    }
  DBGPRINTF_BM
    ("prepare_routine°basiclo_minifunction after miniscan_block recv %s routprep %s bodyob=%s msblov=%s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob),
     objectdbg2_BM (_.bodyob),
     debug_outstr_value_BM (_.msblov, CURFRAME_BM, 0));
  LOCALRETURN_BM (_.routprepob);
failure:
  _.errorv = (value_tyBM)
    makenode4_BM (k_prepare_routine, _.recv, _.modgenob,
                  (value_tyBM) _.prepvalset, _.causev);
  DBGPRINTF_BM
    ("failure prepare_routine°basiclo_minifunction  failin %d errorv %s",
     failin, debug_outstr_value_BM (_.errorv, CURFRAME_BM, 0));
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end prepare_routine°basiclo_minifunction  _07qYMXftJRR_9dde2ASz4e9  */





// return the ctype of a variable
extern objectval_tyBM *miniscan_var_BM (objectval_tyBM * varob,
                                        objectval_tyBM * routprepob,
                                        int depth, objectval_tyBM * fromob,
                                        struct stackframe_stBM *stkf);
// return the ctype of an expression
extern objectval_tyBM *miniscan_expr_BM (value_tyBM expv,
                                         objectval_tyBM * routprepob,
                                         int depth, objectval_tyBM * fromob,
                                         struct stackframe_stBM *stkf);

// test if two types are compatible and return their common supertype
extern objectval_tyBM *miniscan_compatype_BM (objectval_tyBM * typ1ob,
                                              objectval_tyBM * typ2ob,
                                              struct stackframe_stBM *stkf);



////////////////////////////////////////////////////////////////

objectval_tyBM *
miniscan_compatype_BM (objectval_tyBM * typ1ob, objectval_tyBM * typ2ob,
                       struct stackframe_stBM *stkf)
{
  if (!typ1ob || !typ2ob)
    return false;
  WEAKASSERT_BM (isobject_BM (typ1ob));
  WEAKASSERT_BM (isobject_BM (typ2ob));
  if (typ1ob == typ2ob)
    return typ1ob;
  objectval_tyBM *k_miniscan_compatype = BMK_82pYC6bEP7E_3cfHx6ELZFi;
  objectval_tyBM *k_object = BMK_7T9OwSFlgov_0wVJaK1eZbn;
  objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  //objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
  //objectval_tyBM *k_string = BMK_4T8am97muLl_5969SR22Ecq;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ k_miniscan_compatype,
                 objectval_tyBM * typ1ob;
                 objectval_tyBM * typ2ob;
    );
  _.typ1ob = typ1ob;
  _.typ2ob = typ2ob;
  if ((_.typ1ob == k_object && _.typ2ob == k_value)
      || (_.typ1ob == k_value && _.typ2ob == k_object))
    LOCALRETURN_BM (k_value);
  LOCALRETURN_BM (NULL);
}                               /* end miniscan_compatype_BM */



objectval_tyBM *
miniscan_var_BM (objectval_tyBM * varob,
                 objectval_tyBM * routprepob, int depth,
                 objectval_tyBM * fromob, struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  objectval_tyBM *k_closed = BMK_2TwOyPJxIz8_1rIeqaN7oRz;
  objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
  objectval_tyBM *k_locals = BMK_24sSVIADeHm_0Sx34wQfG7W;
  objectval_tyBM *k_miniscan_var = BMK_6jh60mO0Cgd_84B0HiNphqA;
  objectval_tyBM *k_numbers = BMK_32eKNcTZ9HN_80t0nk47Mha;
  objectval_tyBM *k_scalars = BMK_3pPxQecoSkC_7izL0jcxZiS;
  objectval_tyBM *k_result = BMK_7bD9VtDkGSn_7lxHeYuuFLR;
  objectval_tyBM *k_simple_routine_preparation = BMK_80060zKi6Un_3isCStegT8A;
  objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ k_miniscan_var,
                 objectval_tyBM * varob;        //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 value_tyBM vrolv;      //
                 objectval_tyBM * rolconnob;    //
                 value_tyBM causev;
                 value_tyBM errorv;
    );
  int failin = -1;
#define FAILHERE(V) do { failin = __LINE__ ; _.causev = (value_tyBM)(V); \
    goto failure; } while(0)
  _.varob = objectcast_BM (varob);
  _.routprepob = objectcast_BM (routprepob);
  _.fromob = objectcast_BM (fromob);
  if (!_.varob)
    FAILHERE (NULL);
  if (!_.routprepob)
    FAILHERE (NULL);
  if (!_.fromob)
    FAILHERE (NULL);
  DBGPRINTF_BM
    ("miniscan_var start varob=%s routprepob=%s depth#%d fromob=%s",
     objectdbg_BM (_.varob), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromob));
  WEAKASSERT_BM (objhasassocpayl_BM (_.routprepob));
  _.vrolv = objassocgetattrpayl_BM (_.routprepob, _.varob);
  DBGPRINTF_BM ("miniscan_var vrol=%s", //
                OUTSTRVALUE_BM (_.vrolv));
  if (isnode_BM (_.vrolv))
    {
      _.rolconnob = nodeconn_BM (_.vrolv);
      if (_.rolconnob == k_arguments || _.rolconnob == k_locals
          || _.rolconnob == k_closed)
        {
          if (nodewidth_BM (_.vrolv) == 2)
            LOCALRETURN_BM (nodenthson_BM (_.vrolv, 1));
          LOCALRETURN_BM (k_value);
        }
      else if (_.rolconnob == k_constants)
        {
          if (nodewidth_BM (_.vrolv) == 2)
            LOCALRETURN_BM (nodenthson_BM (_.vrolv, 1));
          LOCALRETURN_BM (BMP_object);
        }
      else if (_.rolconnob == k_numbers)
        {
          LOCALRETURN_BM (k_int);
        }
      else if (_.rolconnob == k_scalars)
        {
          DBGBACKTRACEPRINTF_BM
            ("scalar miniscan_var vrol=%s routprepob=%s depth#%d fromob=%s",
             OUTSTRVALUE_BM (_.vrolv), objectdbg_BM (_.routprepob), depth,
             objectdbg1_BM (_.fromob));
          if (nodewidth_BM (_.vrolv) == 2)
            {
              DBGPRINTF_BM ("miniscan_var scalar varob=%s =gives %s",
                            objectdbg_BM (_.varob),
                            OUTSTRVALUE_BM (nodenthson_BM (_.vrolv, 1)));
              LOCALRETURN_BM (nodenthson_BM (_.vrolv, 1));
            }
          FAILHERE (_.vrolv);
        }
      else
        FAILHERE (_.vrolv);
    }
  else if (_.vrolv == k_result)
    {
      if (objectisinstance_BM (_.routprepob, k_simple_routine_preparation))
        LOCALRETURN_BM (k_value);
      else
        FAILHERE (_.vrolv);
    }
  else
    {
      DBGBACKTRACEPRINTF_BM
        ("miniscan_var failing routprepob=%s varob=%s vrolv=%s",
         objectdbg_BM (_.routprepob), objectdbg1_BM (_.varob),
         OUTSTRVALUE_BM (_.vrolv));
      FAILHERE (_.vrolv);
    }
#warning incomplete miniscan_var_BM
  DBGPRINTF_BM ("miniscan_var end varob=%s", objectdbg_BM (_.varob));
  LOCALRETURN_BM (NULL);
failure:
  _.errorv = (value_tyBM)
    makenode5_BM (k_miniscan_var, _.varob, _.routprepob, taggedint_BM (depth),
                  _.fromob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end miniscan_var_BM */


objectval_tyBM *
miniscan_expr_BM (value_tyBM expv, objectval_tyBM * routpreparg,
                  int depth, objectval_tyBM * fromarg,
                  struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_miniscan_expr = BMK_7k3xb0vred0_9ZRHcZmhw77;
  objectval_tyBM *k_miniscan_node_conn = BMK_5EGLdtUAQxA_1nebCsDKqOF;
  objectval_tyBM *k_basiclo_constant_object = BMK_9bCobYhqBV5_5tIWuHnUPMX;
  objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
  objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  objectval_tyBM *k_set = BMK_2mYaTh9kH4I_7ENiXcymRmy;
  objectval_tyBM *k_tuple = BMK_6TmLNh9vtVY_0pwkHRtJ44k;
  objectval_tyBM *k_string = BMK_4T8am97muLl_5969SR22Ecq;
  objectval_tyBM *k_closure = BMK_93zjUzZVAaj_9ppXv7C34GR;
  objectval_tyBM *k_depth = BMK_17YdW6dWrBA_2mn4QmBjMNs;
  objectval_tyBM *k_basiclo_connective = BMK_3DQ7z3EuAiT_4faSRNsy2lr;
  objectval_tyBM *k_exclam = BMK_0e54seiZEXF_1Myf620cHoB;
  objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  objectval_tyBM *k_unspecified = BMK_55eJRRPyZDz_4uW8bzq75PI;
  objectval_tyBM *k_simple_routine_preparation = BMK_80060zKi6Un_3isCStegT8A;
  objectval_tyBM *k_simple_module_generation = BMK_2HlKptD03wA_7JJCG7lN5nS;
  objectval_tyBM *k_undefined = BMK_1z3DQ3EVAGs_3KlGdHJpWbX;
  // objectval_tyBM *k_hset_object = BMK_8c9otZ4pwR6_55k81qyyYV2;
  objectval_tyBM *k_current_closure = BMK_8zYmVLSwVrR_4o3f5Gbjkih;
  objectval_tyBM *k_current_closure_size = BMK_2g7mdZfl2sa_80JC86F5fWc;
  objectval_tyBM *k_current_module = BMK_9zefWWg5iwJ_7IDjDEU8ucb;
  objectval_tyBM *k_current_routine = BMK_5oJ9QOQFfbX_6psQHyINASW;
  objectval_tyBM *k_null_object = BMK_5wZJ5RA9Dww_2S0cGLDXup0;
  objectval_tyBM *k_null_value = BMK_2rFOCfhpUXp_9z1SVC5OYo9;
  objectval_tyBM *k_modgenob = BMK_0Bl5ro9usp6_1Hll14QwC8f;
  objectval_tyBM *k_failure_miss = BMK_52XwytpOPVl_3ZjmQCtadbK;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ k_miniscan_expr,
                 objectval_tyBM * connob;       //
                 objectval_tyBM * indirconnob;  //
                 objectval_tyBM * consthsetobj; //
                 objectval_tyBM * exclamob;     //
                 objectval_tyBM * expob;        //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * typob;        //
                 value_tyBM avalv;      //
                 value_tyBM errorv;     //
                 value_tyBM causev;     //
                 value_tyBM exclamsonv; //
                 value_tyBM expv;       //
                 value_tyBM chunkv;     //
                 value_tyBM resv;       //
    );
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM) (Cause); goto failure; } while(0)
  _.expv = expv;
  _.routprepob = objectcast_BM (routpreparg);
  _.fromob = objectcast_BM (fromarg);
  DBGPRINTF_BM ("miniscan_expr start expv=%s routprepob=%s depth#%d fromob=%s", //
                debug_outstr_value_BM (_.expv, CURFRAME_BM, 0), //
                objectdbg1_BM (_.routprepob), depth,
                objectdbg2_BM (_.fromob));
  if (!_.routprepob)
    FAILHERE (routpreparg);
  if (!_.fromob)
    FAILHERE (fromarg);
  WEAKASSERT_BM (objectisinstance_BM (_.routprepob,
                                      k_simple_routine_preparation));
  _.modgenob = objgetattr_BM (_.routprepob, k_modgenob);
  WEAKASSERT_BM (objectisinstance_BM (_.modgenob,
                                      k_simple_module_generation));
  int ke = valtype_BM (_.expv);
  if (depth > MAXDEPTHPARSE_BM || depth < 0)
    FAILHERE (makenode1_BM (k_depth, taggedint_BM (depth)));
  switch (ke)
    {
    case tyNone_BM:
      LOCALRETURN_BM (k_value);
    case tyInt_BM:
      LOCALRETURN_BM (k_int);
    case tyDouble_BM:
      LOCALRETURN_BM (BMP_double_float);
    case tyString_BM:
      LOCALRETURN_BM (k_string);
    case tySet_BM:
      FAILHERE (k_set);
    case tyTuple_BM:
      FAILHERE (k_tuple);
    case tyClosure_BM:
      FAILHERE (k_closure);
    case tyUnspecified_BM:
      FAILHERE (k_unspecified);
    case tyObject_BM:
      {
        _.expob = objectcast_BM (_.expv);
        _.avalv = objassocgetattrpayl_BM (_.routprepob, _.expob);
        DBGPRINTF_BM ("miniscan_expr expob=%s avalv=%s",
                      objectdbg_BM (_.expob),
                      debug_outstr_value_BM (_.avalv, CURFRAME_BM, 0));
        if (_.expob == k_current_closure)
          {
            LOCALRETURN_BM (BMP_value);
          }
        else if (_.expob == k_null_value)
          {
            LOCALRETURN_BM (BMP_value);
          }
        else if (_.expob == k_null_object)
          {
            LOCALRETURN_BM (BMP_object);
          }
        else if (_.expob == k_current_routine)
          {
            LOCALRETURN_BM (BMP_object);
          }
        else if (_.expob == k_current_module)
          {
            LOCALRETURN_BM (BMP_object);
          }
        else if (_.expob == k_current_closure_size)
          {
            LOCALRETURN_BM (BMP_int);
          }
        if (_.avalv != NULL)
          {
            _.typob =
              miniscan_var_BM (_.expob, _.routprepob, depth, _.fromob,
                               CURFRAME_BM);
            DBGPRINTF_BM ("miniscan_expr var expob=%s typob=%s",
                          objectdbg_BM (_.expob), objectdbg1_BM (_.typob));
            LOCALRETURN_BM (_.typob);
          }
        else if (objectisinstance_BM (_.expob, k_basiclo_constant_object))
          {
            /// actually, the _expob object should be locked till the
            /// end of the compilation of the current module.
#warning an instance of basiclo_constant_object should be locked till end of compilation of module
            objlock_BM (_.expob);
            _.typob = objectcast_BM (objgetattr_BM (_.expob, BMP_c_type));
            _.avalv = objgetattr_BM (_.expob, BMP_value);
            _.chunkv = objgetattr_BM (_.expob, BMP_chunk);
            objunlock_BM (_.expob);
            DBGPRINTF_BM
              ("miniscan_expr constob expob=%s typob=%s avalv=%s chunkv=%s",
               objectdbg_BM (_.expob), objectdbg1_BM (_.typob),
               OUTSTRVALUE_BM (_.avalv), OUTSTRVALUE_BM (_.chunkv));
            if (!_.typob)
              FAILHERE (BMP_c_type);    // no c_type in constant object
            if (_.avalv && _.chunkv)
              FAILHERE (k_failure_miss);        // both chunk & value given in constant object
            if (_.chunkv && nodeconn_BM (_.chunkv) != BMP_chunk)
              FAILHERE (BMP_chunk);     // invalid chunk in constant object
            if (_.avalv)
              {
                if (_.typob == BMP_int && !istaggedint_BM (_.avalv))
                  FAILHERE (BMP_int);
                if (_.typob == BMP_object && !isobject_BM (_.avalv))
                  FAILHERE (BMP_object);
              }
            LOCALRETURN_BM (_.typob);
          }
        else
          FAILHERE (k_undefined);
        if (_.avalv)
          {
            _.consthsetobj =
              objectcast_BM (objgetattr_BM (_.modgenob, k_constants));
            WEAKASSERT_BM (objhashashsetpayl_BM (_.consthsetobj));
            DBGPRINTF_BM
              ("miniscan_expr constob expob=%s added to consthsetobj=%s",
               objectdbg_BM (_.expob), objectdbg1_BM (_.consthsetobj));
            objhashsetaddpayl_BM (_.consthsetobj, _.expob);
          }
        break;
      }
    case tyNode_BM:
      {
        _.connob = nodeconn_BM (_.expv);
        unsigned arity = nodewidth_BM (_.expv);
        DBGPRINTF_BM
          ("miniscan_expr node expv=%s connob=%s arity#%d",
           debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
           objectdbg_BM (_.connob), arity);
        if (_.connob == k_exclam && arity == 1)
          {
            _.exclamsonv = nodenthson_BM (_.expv, 0);
            _.exclamob = objectcast_BM (_.exclamsonv);
            if (_.exclamob)
              {
                _.consthsetobj =
                  objectcast_BM (objgetattr_BM (_.modgenob, k_constants));
                DBGPRINTF_BM
                  ("miniscan_expr exclamob=%s routprepob=%s consthsetobj=%s",
                   objectdbg_BM (_.exclamob), objectdbg1_BM (_.routprepob),
                   objectdbg2_BM (_.consthsetobj));
                WEAKASSERT_BM (objhashashsetpayl_BM (_.consthsetobj));
                objhashsetaddpayl_BM (_.consthsetobj, _.exclamob);
                LOCALRETURN_BM (BMP_object);
              }
            else if (istaggedint_BM (_.exclamsonv))
              LOCALRETURN_BM (BMP_value);
            // we don't accept quotation of nil, since it is not a value
            // else if (_.exclamsonv == NULL)
            //   LOCALRETURN_BM (BMP_value);
            else
              FAILHERE (k_undefined);
          }
        {
          objlock_BM (_.connob);
          if (objectisinstance_BM (_.connob, k_basiclo_connective))
            {
              DBGPRINTF_BM
                ("miniscan_expr miniscan_node_conn->%s arity %d routprepob %s fromob %s before",
                 objectdbg_BM (_.connob), arity, objectdbg1_BM (_.routprepob),
                 objectdbg2_BM (_.fromob));
              _.resv = send4_BM (_.connob, k_miniscan_node_conn,        //
                                 CURFRAME_BM,   //
                                 _.routprepob,
                                 taggedint_BM (depth), _.expv, _.fromob);
              DBGPRINTF_BM ("miniscan_expr miniscan_node_conn->%s done resv=%s",        //
                            objectdbg_BM (_.connob),    //
                            debug_outstr_value_BM (_.resv, CURFRAME_BM, 0));
              if (!_.resv)
                FAILHERE (k_undefined);
              {
                objunlock_BM (_.connob);
                _.connob = NULL;
                LOCALRETURN_BM (_.resv);
              }
            };
          _.indirconnob =
            objectcast_BM (objgetattr_BM (_.connob, k_basiclo_connective));
          if (_.indirconnob
              && objectisinstance_BM (_.indirconnob, k_basiclo_connective))
            {
              DBGPRINTF_BM
                ("miniscan_expr miniscan_node_conn indirect %s arity %d routprepob %s fromob %s before, depth %d",
                 objectdbg_BM (_.indirconnob), arity,
                 objectdbg1_BM (_.routprepob), objectdbg2_BM (_.fromob),
                 depth);
              if (depth + 1 > MAXDEPTHPARSE_BM || depth < 0)
                FAILHERE (makenode2_BM
                          (k_depth, taggedint_BM (depth), _.indirconnob));
              objlock_BM (_.indirconnob);
              _.resv = send4_BM (_.indirconnob, k_miniscan_node_conn,   //
                                 CURFRAME_BM,   //
                                 _.routprepob,
                                 taggedint_BM (depth + 1), _.expv, _.fromob);
              objunlock_BM (_.indirconnob);
              DBGPRINTF_BM ("miniscan_expr miniscan_node_conn indirect %s done resv=%s",        //
                            objectdbg_BM (_.indirconnob),       //
                            debug_outstr_value_BM (_.resv, CURFRAME_BM, 0));
              if (!_.resv)
                FAILHERE (makenode1_BM (k_undefined, _.indirconnob));
              {
                objunlock_BM (_.connob);
                _.connob = NULL;
                LOCALRETURN_BM (_.resv);
              }
            }
          objunlock_BM (_.connob);
        }
        break;
      }
    default:
      FAILHERE (k_undefined);
    }
#warning incomplete miniscan_expr_BM
  DBGPRINTF_BM ("miniscan_expr end expv=%s",    //
                debug_outstr_value_BM (_.expv, CURFRAME_BM, 0));
  LOCALRETURN_BM (NULL);
failure:
  DBGPRINTF_BM ("miniscan_expr failin %d cause %s", failin,
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv = (value_tyBM)
    makenode5_BM (k_miniscan_expr, _.expv, _.causev, _.routprepob,
                  taggedint_BM (depth), _.fromob);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end miniscan_expr_BM */




////////////////////////////////////////////////////////////////
// for the method miniscan_stmt°basiclo_cond 
extern objrout_sigBM ROUTINEOBJNAME_BM (_0zzJJsAL6Qm_2uw3eoWQHEq);
value_tyBM
ROUTINEOBJNAME_BM (_0zzJJsAL6Qm_2uw3eoWQHEq)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving cond
 const value_tyBM arg2,         // routine preparation
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // containingblock
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * recv; //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromblockob;  //
                 objectval_tyBM * compob;       //
                 objectval_tyBM * seqcompob;    //
                 value_tyBM seqcompv;   //
                 value_tyBM compv;      //
                 value_tyBM testexpv; value_tyBM resv;
                 value_tyBM errorv;
                 value_tyBM causev;
    );
  objectval_tyBM *k_basiclo_when = BMK_3fvdRZNCmJS_5bTAPr83mXg;
  objectval_tyBM *k_test = BMK_2j84OTHlFdJ_1pMyQfgsmAz;
  // objectval_tyBM *k_miniscan_expr = BMK_7k3xb0vred0_9ZRHcZmhw77;
  objectval_tyBM *k_miniscan_block = BMK_2gthNYOWogO_4sVTU1JbmUH;
  objectval_tyBM *k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_nb_conds = BMK_8dLpuaNoSGN_2tdmkpINCsu;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  int depth = 0;
  _.recv = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  depth = getint_BM (arg3);
  _.fromblockob = objectcast_BM (arg4);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev= (value_tyBM)(Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_cond start recv=%s routprepob=%s depth#%d fromblockob=%s start",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromblockob));
  objlock_BM (_.recv);
  unsigned nbsons = objnbcomps_BM (_.recv);
  int nbconds = getint_BM (objgetattr_BM (_.recv, k_nb_conds));
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_cond recv=%s nbconds=%d nbsons=%u",
     objectdbg_BM (_.recv), nbconds, nbsons);
  WEAKASSERT_BM ((int) nbconds <= (int) nbsons);
  for (int ix = 0; ix < nbconds; ix++)
    {
      _.compv = objgetcomp_BM (_.recv, ix);
      _.compob = objectcast_BM (_.compv);
      DBGPRINTF_BM
        ("miniscan_stmt°basiclo_cond recv=%s ix=%u compob=%s",
         objectdbg_BM (_.recv), ix, objectdbg1_BM (_.compob));
      if (!_.compob)
        FAILHERE (makenode2_BM (k_curcomp, _.compv, taggedint_BM (ix)));
      objlock_BM (_.compob);
      if (objectisinstance_BM (_.compob, k_basiclo_when))
        {
          _.testexpv = objgetattr_BM (_.compob, k_test);
          miniscan_expr_BM (_.testexpv, _.routprepob, depth + 1, _.recv,
                            CURFRAME_BM);
          unsigned nbsubcomp = objnbcomps_BM (_.compob);
          for (unsigned cix = 0; cix < nbsubcomp; cix++)
            {
              _.seqcompv = objgetcomp_BM (_.compob, cix);
              _.seqcompob = objectcast_BM (_.seqcompv);
              DBGPRINTF_BM
                ("miniscan_stmt°basiclo_cond recv=%s ix=%u compob=%s cix=%u seqcomp=%s",
                 objectdbg_BM (_.recv), ix, objectdbg1_BM (_.compob), cix,
                 objectdbg2_BM (_.seqcompob));
              if (!_.seqcompob)
                {
                  if (_.seqcompv != NULL)
                    FAILHERE (makenode3_BM
                              (k_curcomp, _.seqcompv, taggedint_BM (cix),
                               taggedint_BM (ix)));
                  continue;
                }
              objlock_BM (_.seqcompob);
              if (objectisinstance_BM (_.seqcompob, k_basiclo_block))
                {
                  DBGPRINTF_BM
                    ("miniscan_stmt°basiclo_cond seqcompob %s is block of %s",
                     objectdbg_BM (_.seqcompob),
                     objectdbg1_BM (objclass_BM (_.seqcompob)));
                  _.resv =
                    send3_BM (_.seqcompob, k_miniscan_block,
                              CURFRAME_BM, _.routprepob,
                              taggedint_BM (depth + 1), _.compob);
                  DBGPRINTF_BM
                    ("miniscan_stmt°basiclo_cond seqcompob after miniscan_block->%s resv=%s",
                     objectdbg_BM (_.seqcompob),
                     debug_outstr_value_BM (_.resv, CURFRAME_BM, 0));
                  if (!_.resv)
                    FAILHERE (makenode3_BM
                              (k_miniscan_block, _.seqcompob,
                               taggedint_BM (cix), taggedint_BM (ix)));
                }
              else if (objectisinstance_BM (_.seqcompob, k_basiclo_statement))
                {
                  DBGPRINTF_BM
                    ("miniscan_stmt°basiclo_cond seqcompob %s is statement of %s",
                     objectdbg_BM (_.seqcompob),
                     objectdbg1_BM (objclass_BM (_.seqcompob)));
                  _.resv =
                    send3_BM (_.seqcompob, k_miniscan_stmt,
                              CURFRAME_BM, _.routprepob,
                              taggedint_BM (depth + 1), _.compob);
                  DBGPRINTF_BM
                    ("miniscan_stmt°basiclo_cond seqcompob after miniscan_stmt->%s resv=%s",
                     objectdbg_BM (_.seqcompob),
                     debug_outstr_value_BM (_.resv, CURFRAME_BM, 0));
                  if (!_.resv)
                    FAILHERE (makenode3_BM
                              (k_miniscan_stmt, _.seqcompob,
                               taggedint_BM (cix), taggedint_BM (ix)));
                }
              else
                FAILHERE (makenode3_BM
                          (k_curcomp, _.seqcompob, taggedint_BM (cix),
                           taggedint_BM (ix)));
              objunlock_BM (_.seqcompob);

            }
        }
      else
        FAILHERE (makenode2_BM (k_curcomp, _.compob, taggedint_BM (ix)));
      objunlock_BM (_.compob);
      DBGPRINTF_BM
        ("miniscan_stmt°basiclo_cond recv=%s ix=%u done compob=%s",
         objectdbg_BM (_.recv), ix, objectdbg1_BM (_.compob));
    }
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_cond recv=%s remaining %d from nbconds %d to nbsons %d",
     objectdbg_BM (_.recv), nbsons - nbconds, nbconds, nbsons);
  for (unsigned ix = nbconds; ix < nbsons; ix++)
    {
      _.compv = objgetcomp_BM (_.recv, ix);
      _.compob = objectcast_BM (_.compv);
      DBGPRINTF_BM ("miniscan_stmt°basiclo_cond recv=%s ix=%u compob=%s",
                    objectdbg_BM (_.recv), ix, objectdbg1_BM (_.compob));
      if (!_.compob)
        {
          if (_.compv != NULL)
            FAILHERE (makenode2_BM (k_curcomp, _.compv, taggedint_BM (ix)));
          continue;
        }
      objlock_BM (_.compob);
      if (objectisinstance_BM (_.compob, k_basiclo_statement))
        {
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_cond recv=%s compob %s #%d is statement",
             objectdbg_BM (_.recv), objectdbg1_BM (_.compob), ix);
          _.resv =
            send3_BM (_.compob, k_miniscan_stmt, CURFRAME_BM, _.routprepob,
                      taggedint_BM (depth + 1), _.recv);
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_cond after miniscan_stmt->%s resv=%s",
             objectdbg_BM (_.compob), debug_outstr_value_BM (_.resv,
                                                             CURFRAME_BM, 0));
          if (!_.resv)
            FAILHERE (makenode2_BM
                      (k_miniscan_stmt, _.compob, taggedint_BM (ix)));
        }
      else if (objectisinstance_BM (_.compob, k_basiclo_block))
        {
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_cond recv=%s compob %s #%d is block",
             objectdbg_BM (_.recv), objectdbg1_BM (_.compob), ix);
          _.resv =
            send3_BM (_.compob, k_miniscan_block, CURFRAME_BM, _.routprepob,
                      taggedint_BM (depth + 1), _.recv);
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_cond after miniscan_block->%s resv=%s",
             objectdbg_BM (_.compob), debug_outstr_value_BM (_.resv,
                                                             CURFRAME_BM, 0));
          if (!_.resv)
            FAILHERE (makenode2_BM
                      (k_miniscan_block, _.compob, taggedint_BM (ix)));
        }
      else
        FAILHERE (makenode2_BM (k_curcomp, _.compob, taggedint_BM (ix)));

    }
  objunlock_BM (_.recv);
  DBGPRINTF_BM ("miniscan_stmt°basiclo_cond ending recv=%s",
                objectdbg_BM (_.recv));
  LOCALRETURN_BM (_.recv);
failure:
#undef FAILHERE
  DBGPRINTF_BM ("miniscan_stmt°basiclo_cond  failin %d recv=%s", failin,
                objectdbg_BM (_.recv));
  _.errorv = (value_tyBM)
    makenode4_BM (k_miniscan_stmt, _.recv, _.routprepob, taggedint_BM (depth),
                  _.fromblockob);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end routine miniscan_stmt°basiclo_cond _0zzJJsAL6Qm_2uw3eoWQHEq */

////////////////


// miniscan_stmt°basiclo_while _2Cj1ZVDhCVO_8qT2Um5Ok7f

extern objrout_sigBM ROUTINEOBJNAME_BM (_2Cj1ZVDhCVO_8qT2Um5Ok7f);

value_tyBM
ROUTINEOBJNAME_BM (_2Cj1ZVDhCVO_8qT2Um5Ok7f)    //miniscan_stmt°basiclo_while 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         //recieving while obstmt
 const value_tyBM arg2,         //routine preparation
 const value_tyBM arg3,         //depth
 const value_tyBM arg4,         //fromob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_duplicate = BMK_2YrbiKQ6lxP_3KNUOnU6TF5;
  objectval_tyBM *k_while = BMK_7GNnckYYtcH_7wtOnPP4eKU;
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_miniscan_block = BMK_2gthNYOWogO_4sVTU1JbmUH;
  objectval_tyBM *k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  objectval_tyBM *k_object = BMK_7T9OwSFlgov_0wVJaK1eZbn;
  objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
  objectval_tyBM *k_string = BMK_4T8am97muLl_5969SR22Ecq;
  objectval_tyBM *k_blocks = BMK_2lCuMosXupr_5GAoqVgJ8PZ;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_2Cj1ZVDhCVO_8qT2Um5Ok7f,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * compob;       //
                 value_tyBM whilexpv;   //
                 value_tyBM compv;      //
                 objectval_tyBM * whiltypob;    //
                 objectval_tyBM * hsetblockob;  //
                 value_tyBM resv;       //
                 value_tyBM resultv;    //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
    );
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev= (value_tyBM)(Cause); goto failure; } while(0)
  _.stmtob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  int depth = getint_BM (arg3);
  _.fromob = objectcast_BM (arg4);
  _.hsetblockob = objectcast_BM (objgetattr_BM (_.routprepob, k_blocks));
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_while start stmtob=%s routprepob=%s depth#%d fromob=%s hsetblockob=%s start",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromob), objectdbg3_BM (_.hsetblockob));
  WEAKASSERT_BM (_.hsetblockob);
  WEAKASSERT_BM (objhashashsetpayl_BM (_.hsetblockob));
  if (objhashsetcontainspayl_BM (_.hsetblockob, _.stmtob))
    FAILHERE (k_duplicate);
  objhashsetaddpayl_BM (_.hsetblockob, _.stmtob);
  _.whilexpv = objgetattr_BM (_.stmtob, k_while);
  if (!_.whilexpv)
    FAILHERE (k_while);
  _.whiltypob =
    miniscan_expr_BM (_.whilexpv, _.routprepob, 0, _.stmtob, CURFRAME_BM);
  if (_.whiltypob != k_object && _.whiltypob != k_value
      && _.whiltypob != k_int && _.whiltypob != k_string
      && !miniscan_compatype_BM (_.whiltypob, k_value, CURFRAME_BM)
      && !miniscan_compatype_BM (_.whiltypob, k_int, CURFRAME_BM))
    FAILHERE (makenode2_BM (k_while, _.whilexpv, _.whiltypob));
  unsigned stmtlen = objnbcomps_BM (_.stmtob);
  for (int ix = 0; ix < (int) stmtlen; ix++)
    {
      _.compob = NULL;
      _.compv = objgetcomp_BM (_.stmtob, ix);
      if (!_.compv)
        continue;
      _.compob = objectcast_BM (_.compv);
      if (!_.compob)
        FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (ix), _.compv));
      objlock_BM (_.compob);
      if (objectisinstance_BM (_.compob, k_basiclo_block))
        {
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_while compob %s is block of %s",
             objectdbg_BM (_.compob), objectdbg1_BM (objclass_BM (_.compob)));
          _.resv =
            send3_BM (_.compob, k_miniscan_block,
                      CURFRAME_BM, _.routprepob,
                      taggedint_BM (depth + 1), _.stmtob);
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_while compob after miniscan_block->%s resv=%s",
             objectdbg_BM (_.compob),
             debug_outstr_value_BM (_.resv, CURFRAME_BM, 0));
          if (!_.resv)
            FAILHERE (makenode2_BM
                      (k_miniscan_block, _.compob, taggedint_BM (ix)));
        }
      else if (objectisinstance_BM (_.compob, k_basiclo_statement))
        {
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_while compob %s is statement of %s",
             objectdbg_BM (_.compob), objectdbg1_BM (objclass_BM (_.compob)));
          _.resv =
            send3_BM (_.compob, k_miniscan_stmt,
                      CURFRAME_BM, _.routprepob,
                      taggedint_BM (depth + 1), _.stmtob);
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_while compob after miniscan_stmt->%s resv=%s",
             objectdbg_BM (_.compob),
             debug_outstr_value_BM (_.resv, CURFRAME_BM, 0));
          if (!_.resv)
            FAILHERE (makenode2_BM
                      (k_miniscan_stmt, _.compob, taggedint_BM (ix)));
        }
      else
        FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (ix), _.compob));
      objunlock_BM (_.compob);
    }
  objhashsetremovepayl_BM (_.hsetblockob, _.stmtob);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_while end stmtob=%s routprepob=%s depth#%d fromob=%s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromob));
  LOCALRETURN_BM (_.stmtob);
failure:
#undef FAILHERE
  DBGPRINTF_BM ("miniscan_stmt°basiclo_while failin %d stmtob=%s causev %s",
                failin, objectdbg_BM (_.stmtob),
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode5_BM (k_miniscan_stmt, _.stmtob, _.causev,
                               _.routprepob, taggedint_BM (depth), _.fromob);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniscan_stmt°basiclo_while _2Cj1ZVDhCVO_8qT2Um5Ok7f */



////////////////

// miniscan_stmt°basiclo_lockobj  _8fKRsxM1q9w_3hFovzBicI7

extern objrout_sigBM ROUTINEOBJNAME_BM (_8fKRsxM1q9w_3hFovzBicI7);

value_tyBM
ROUTINEOBJNAME_BM (_8fKRsxM1q9w_3hFovzBicI7)    // miniscan_stmt°basiclo_lockobj
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving lockob stmt
 const value_tyBM arg2,         // routine preparation
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // containingblock
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_duplicate = BMK_2YrbiKQ6lxP_3KNUOnU6TF5;
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  objectval_tyBM *k_hset_object = BMK_8c9otZ4pwR6_55k81qyyYV2;
  objectval_tyBM *k_locking = BMK_8yqFC2Qz7I2_7KoZMWLE0U3;
  objectval_tyBM *k_lockobj = BMK_9dso3pFLYwm_3JwHqiJK3UL;
  objectval_tyBM *k_miniscan_block = BMK_2gthNYOWogO_4sVTU1JbmUH;
  objectval_tyBM *k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  objectval_tyBM *k_in = BMK_0eMGYofuNVh_8ZP2mXdhtHO;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_8fKRsxM1q9w_3hFovzBicI7,
                 value_tyBM resv;       //
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromblockob;  //
                 objectval_tyBM * destob;       //
                 objectval_tyBM * typob;        //
                 objectval_tyBM * compob;       //
                 objectval_tyBM * lockhsetob;   //
                 value_tyBM compv;      //
                 value_tyBM lobexpv;    //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
    );
  int depth = -1;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev= (value_tyBM)(Cause); goto failure; } while(0)
  _.stmtob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  depth = getint_BM (arg3);
  _.fromblockob = objectcast_BM (arg4);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_lockobj start stmtob=%s routprepob=%s depth#%d fromblockob=%s start",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromblockob));
  _.lockhsetob = objgetattr_BM (_.routprepob, k_locking);
  if (!_.lockhsetob)
    {
      _.lockhsetob = makeobj_BM ();
      objputhashsetpayl_BM (_.lockhsetob, 15);
      objputclass_BM (_.lockhsetob, k_hset_object);
      objputattr_BM (_.lockhsetob, k_in, _.routprepob);
      objputattr_BM (_.routprepob, k_locking, _.lockhsetob);
      DBGPRINTF_BM
        ("miniscan_stmt°basiclo_lockobj stmtob=%s put lockhsetob=%s "
         " in routprepob=%s",
         objectdbg_BM (_.stmtob), objectdbg1_BM (_.lockhsetob),
         objectdbg2_BM (_.routprepob));
    }
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_lockobj stmtob=%s lockhsetob=%s "
     " in routprepob=%s", objectdbg_BM (_.stmtob),
     objectdbg1_BM (_.lockhsetob), objectdbg2_BM (_.routprepob));
  objlock_BM (_.stmtob);
  _.lobexpv = objgetattr_BM (_.stmtob, k_lockobj);
  _.typob =
    miniscan_expr_BM (_.lobexpv, _.routprepob, depth + 1, _.stmtob,
                      CURFRAME_BM);
  if (_.typob != BMP_object)
    FAILHERE (makenode2_BM (k_lockobj, _.lobexpv, _.typob));
  unsigned stmtlen = objnbcomps_BM (_.stmtob);
  for (int ix = 0; ix < (int) stmtlen; ix++)
    {
      _.compv = objgetcomp_BM (_.stmtob, ix);
      if (!_.compv)
        continue;
      _.compob = objectcast_BM (_.compv);
      if (!_.compob)
        FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (ix), _.compv));
      objlock_BM (_.compob);
      if (objectisinstance_BM (_.compob, k_basiclo_block))
        {
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_lockobj compob %s is block of %s",
             objectdbg_BM (_.compob), objectdbg1_BM (objclass_BM (_.compob)));
          _.resv =
            send3_BM (_.compob, k_miniscan_block,
                      CURFRAME_BM, _.routprepob,
                      taggedint_BM (depth + 1), _.stmtob);
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_lockobj compob after miniscan_block->%s resv=%s",
             objectdbg_BM (_.compob),
             debug_outstr_value_BM (_.resv, CURFRAME_BM, 0));
          if (!_.resv)
            FAILHERE (makenode2_BM
                      (k_miniscan_block, _.compob, taggedint_BM (ix)));
        }
      else if (objectisinstance_BM (_.compob, k_basiclo_statement))
        {
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_lockobj compob %s is statement of %s",
             objectdbg_BM (_.compob), objectdbg1_BM (objclass_BM (_.compob)));
          _.resv =
            send3_BM (_.compob, k_miniscan_stmt,
                      CURFRAME_BM, _.routprepob,
                      taggedint_BM (depth + 1), _.stmtob);
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_lockobj compob after miniscan_stmt->%s resv=%s",
             objectdbg_BM (_.compob),
             debug_outstr_value_BM (_.resv, CURFRAME_BM, 0));
          if (!_.resv)
            FAILHERE (makenode2_BM
                      (k_miniscan_stmt, _.compob, taggedint_BM (ix)));
        }
      else
        FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (ix), _.compob));
      objunlock_BM (_.compob);
    }
  {
    objlock_BM (_.lockhsetob);
    if (objhashsetcontainspayl_BM (_.lockhsetob, _.stmtob))
      FAILHERE (makenode1_BM (k_duplicate, _.stmtob));
    objhashsetaddpayl_BM (_.lockhsetob, _.stmtob);
    objunlock_BM (_.lockhsetob);
  }
  objunlock_BM (_.stmtob);
  LOCALRETURN_BM (_.stmtob);
failure:
#undef FAILHERE
  DBGPRINTF_BM ("miniscan_stmt°basiclo_lockobj failin %d stmtob=%s cause %s",
                failin, objectdbg_BM (_.stmtob),
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode5_BM (k_miniscan_stmt, _.stmtob, _.causev,
                               _.routprepob, taggedint_BM (depth),
                               _.fromblockob);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniscan_stmt°basiclo_lockobj  _8fKRsxM1q9w_3hFovzBicI7 */




////////////////


// miniscan_stmt°basiclo_assign _7LNRlilrowp_0GG6ZLUFovu
extern objrout_sigBM ROUTINEOBJNAME_BM (_7LNRlilrowp_0GG6ZLUFovu);

value_tyBM
ROUTINEOBJNAME_BM (_7LNRlilrowp_0GG6ZLUFovu)    //miniscan_stmt°basiclo_assign
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving assign
 const value_tyBM arg2,         // routine preparation
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // containingblock
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_failure_type_error = BMK_95hdJENHNkN_3QuKIJTCQQQ;
  objectval_tyBM *k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_7LNRlilrowp_0GG6ZLUFovu,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromblockob;  //
                 objectval_tyBM * destob;       //
                 value_tyBM srcexpv;    //
                 objectval_tyBM * vartypob;     //
                 objectval_tyBM * srctypob;     //
                 objectval_tyBM * compatypob;   //
                 value_tyBM resv;       //
                 value_tyBM failv;      //
    );
  int depth = 0;
  bool ok = false;
  _.stmtob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  depth = getint_BM (arg3);
  _.fromblockob = objectcast_BM (arg4);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_assign start stmtob=%s routprepob=%s depth#%d fromblockob=%s start",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromblockob));
  objlock_BM (_.stmtob);
  WEAKASSERT_BM (objnbcomps_BM (_.stmtob) == 2);
  _.destob = objectcast_BM (objgetcomp_BM (_.stmtob, 0));
  _.srcexpv = objgetcomp_BM (_.stmtob, 1);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_assign stmtob=%s destob=%s of %s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.destob),
     objectdbg2_BM (objclass_BM (_.destob)));
  WEAKASSERT_BM (isobject_BM (_.destob));
  _.vartypob = miniscan_var_BM (_.destob, _.routprepob, depth + 1, _.stmtob,
                                CURFRAME_BM);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_assign after miniscan_var->%s vartypob=%s",
     objectdbg_BM (_.destob), objectdbg1_BM (_.vartypob));
  DBGPRINTF_BM ("miniscan_stmt°basiclo_assign stmtob=%s srcexpv=%s", objectdbg_BM (_.stmtob),  //
                debug_outstr_value_BM (_.srcexpv, CURFRAME_BM, 0));
  _.srctypob = miniscan_expr_BM (_.srcexpv, _.routprepob, depth + 1, _.stmtob,
                                 CURFRAME_BM);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_assign after miniscan_expr->%s srctypob=%s vartypob=%s destob=%s",
     debug_outstr_value_BM (_.srcexpv, CURFRAME_BM, 0),
     objectdbg_BM (_.srctypob), objectdbg1_BM (_.vartypob),
     objectdbg2_BM (_.destob));
  _.compatypob = NULL;
  objunlock_BM (_.stmtob);
  if (_.srctypob == _.vartypob && _.srctypob != NULL)
    {
      ok = true;
      _.compatypob = _.vartypob;
    }
  else if (_.vartypob == BMP_value
           && (_.compatypob = miniscan_compatype_BM (_.vartypob, _.srctypob,
                                                     CURFRAME_BM))
           == BMP_value)
    ok = true;
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_assign end stmtob=%s ok=%s compatypob=%s",
     objectdbg_BM (_.stmtob), ok ? "true" : "false",
     objectdbg1_BM (_.compatypob));
  if (ok)
    LOCALRETURN_BM (_.stmtob);
  else
    {
      DBGPRINTF_BM
        ("miniscan_stmt°basiclo_assign stmtob=%s type mismatch srctypob=%s vartypob=%s",
         objectdbg_BM (_.stmtob), objectdbg1_BM (_.srctypob),
         objectdbg2_BM (_.vartypob));

      _.failv = (value_tyBM)
        makenode4_BM (k_miniscan_stmt, k_failure_type_error, _.stmtob,
                      _.srctypob, _.vartypob);
      PLAINFAILURE_BM (__LINE__, _.failv, CURFRAME_BM);
    }
}                               /* end miniscan_stmt°basiclo_assign _7LNRlilrowp_0GG6ZLUFovu */




// miniscan_stmt°basiclo_exit  _23F5sZIfO5Y_5m9O2FPHdzX

extern objrout_sigBM ROUTINEOBJNAME_BM (_23F5sZIfO5Y_5m9O2FPHdzX);

value_tyBM
ROUTINEOBJNAME_BM (_23F5sZIfO5Y_5m9O2FPHdzX)    // miniscan_stmt°basiclo_exit 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         //stmtob recieving exit 
 const value_tyBM arg2,         //routprepob
 const value_tyBM arg3,         //depth
 const value_tyBM arg4,         //fromob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_exit = BMK_41gbFesxqzD_3l56OLiNdl2;
  objectval_tyBM *k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  objectval_tyBM *k_blocks = BMK_2lCuMosXupr_5GAoqVgJ8PZ;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_23F5sZIfO5Y_5m9O2FPHdzX,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * exitob;       //
                 objectval_tyBM * hsetblockob;  //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
    );
  int depth = 0;
  _.stmtob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  depth = getint_BM (arg3);
  _.fromob = objectcast_BM (arg4);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_exit start stmtob=%s routprepob=%s depth#%d fromob=%s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromob));
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev= (value_tyBM)(Cause); goto failure; } while(0)
  WEAKASSERT_BM (_.stmtob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (arg3) && depth >= 0);
  WEAKASSERT_BM (_.fromob);
  _.exitob = objectcast_BM (objgetattr_BM (_.stmtob, k_exit));
  _.hsetblockob = objectcast_BM (objgetattr_BM (_.routprepob, k_blocks));
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_exit stmtob=%s routprepob=%s exitob=%s hsetblockob=%s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),
     objectdbg2_BM (_.exitob), objectdbg3_BM (_.hsetblockob));
  if (!isobject_BM (_.exitob))
    FAILHERE (k_exit);
  if (!isobject_BM (_.hsetblockob))
    FAILHERE (k_blocks);
  if (!objhashashsetpayl_BM (_.hsetblockob))
    FAILHERE (makenode1_BM (k_blocks, _.hsetblockob));
  if (!objhashsetcontainspayl_BM (_.hsetblockob, _.exitob))
    {
      DBGPRINTF_BM
        ("miniscan_stmt°basiclo_exit stmtob=%s exitob=%s not in hsetblockob=%s",
         objectdbg_BM (_.stmtob), objectdbg1_BM (_.exitob),
         objectdbg2_BM (_.hsetblockob));
      FAILHERE (makenode1_BM (k_exit, _.exitob));
    }
  LOCALRETURN_BM (_.exitob);
failure:
  DBGPRINTF_BM ("miniscan_stmt°basiclo_exit failin %d stmtob=%s causev=%s routprepob=%s",      //
                failin, objectdbg_BM (_.stmtob),        //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0),       //
                objectdbg1_BM (_.routprepob));
  _.errorv = (value_tyBM)
    makenode5_BM (k_miniscan_stmt, _.stmtob, _.routprepob,
                  taggedint_BM (depth), _.fromob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end miniscan_stmt°basiclo_exit  _23F5sZIfO5Y_5m9O2FPHdzX */




// miniscan_stmt°basiclo_run _6pA1Fxh7omw_0vJfR3s4tty

extern objrout_sigBM ROUTINEOBJNAME_BM (_6pA1Fxh7omw_0vJfR3s4tty);

value_tyBM
ROUTINEOBJNAME_BM (_6pA1Fxh7omw_0vJfR3s4tty)    //miniscan_stmt°basiclo_run
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         //stmtob - an intswitch 
 const value_tyBM arg2,         //routprepob
 const value_tyBM arg3,         //depth
 const value_tyBM arg4,         //fromob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  objectval_tyBM *k_run = BMK_4RFtYFUdfau_7Vm5jZ4Wm8e;
  objectval_tyBM *k_chunk = BMK_3pQnBS9ZjkQ_0uGmqUUhAum;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  objectval_tyBM *k_variable = BMK_5ucAZimYynS_4VA0XHvr1nW;
  objectval_tyBM *k_stmtid = BMK_5Z5WNOYHi9A_29s2a7qpJej;
  objectval_tyBM *k_string = BMK_4T8am97muLl_5969SR22Ecq;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_6pA1Fxh7omw_0vJfR3s4tty,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * runtypob;     //
                 objectval_tyBM * connob;       //
                 objectval_tyBM * subconnob;    //
                 objectval_tyBM * varob;        //
                 objectval_tyBM * typsubob;     //
                 value_tyBM runv;
                 value_tyBM resultv;
                 value_tyBM compv;
                 value_tyBM subcompv;
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
    );
  int depth = 0;
  _.stmtob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  depth = getint_BM (arg3);
  _.fromob = objectcast_BM (arg4);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev= (value_tyBM)(Cause); goto failure; } while(0)
  WEAKASSERT_BM (_.stmtob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (arg3) && depth >= 0);
  WEAKASSERT_BM (_.fromob);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_run start stmtob=%s routprepob=%s depth#%d fromob=%s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromob));
  _.runv = objgetattr_BM (_.stmtob, k_run);
  if (isnode_BM (_.runv) && ((_.connob = nodeconn_BM (_.runv)) == k_chunk))
    {
      DBGPRINTF_BM ("miniscan_stmt°basiclo_run  stmtob=%s chunk runv=%s",      //
                    objectdbg_BM (_.stmtob),    //
                    OUTSTRVALUE_BM (_.runv));
      int chklen = nodewidth_BM (_.runv);
      for (int cix = 0; cix < chklen; cix++)
        {
          _.compv = nodenthson_BM (_.runv, cix);
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_run  stmtob=%s chunk cix#%d compv=%s",
             objectdbg_BM (_.stmtob), cix, OUTSTRVALUE_BM (_.compv));
          if (!_.compv)
            {
              WARNPRINTF_BM ("run in basiclo_run %s with nil son#%d",
                             objectdbg_BM (_.stmtob), cix);
              FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (cix), _.runv));
            }
          else if (isnode_BM (_.compv))
            {
              _.subconnob = nodeconn_BM (_.compv);
              if (nodewidth_BM (_.compv) == 1 && _.subconnob == k_variable)
                {
                  _.varob = objectcast_BM (nodenthson_BM (_.compv, 0));
                  if (!_.varob)
                    {
                      WARNPRINTF_BM
                        ("run in basiclo_run %s with bad variable node #%d : %s",
                         objectdbg_BM (_.stmtob), cix,
                         OUTSTRVALUE_BM (_.compv));
                      FAILHERE (makenode2_BM
                                (k_variable, taggedint_BM (cix), _.compv));
                    }
                  if (_.varob == k_stmtid)
                    {
                      _.typsubob = k_string;
                    }
                  else
                    {
                      _.typsubob =
                        miniscan_var_BM (_.varob, _.routprepob, depth + 1,
                                         _.stmtob, CURFRAME_BM);
                    }
                  if (!_.typsubob)
                    {
                      WARNPRINTF_BM
                        ("run in basiclo_run %s with unbound variable node #%d : %s",
                         objectdbg_BM (_.stmtob), cix,
                         OUTSTRVALUE_BM (_.compv));
                      FAILHERE (makenode2_BM
                                (k_variable, taggedint_BM (cix), _.compv));
                    }
                }
              else
                {
                  _.typsubob =
                    miniscan_expr_BM (_.compv, _.routprepob, depth + 1,
                                      _.stmtob, CURFRAME_BM);
                  if (!_.typsubob)
                    {
                      WARNPRINTF_BM
                        ("run in basiclo_run %s with unbound son node #%d : %s",
                         objectdbg_BM (_.stmtob), cix,
                         OUTSTRVALUE_BM (_.compv));
                      FAILHERE (makenode2_BM
                                (k_curcomp, taggedint_BM (cix), _.compv));
                    }
                }
            }
          else if (isstring_BM (_.compv) || istaggedint_BM (_.compv)
                   || isobject_BM (_.compv))
            continue;
          else
            {
              WARNPRINTF_BM
                ("run in basiclo_run %s with bad son #%d : %s",
                 objectdbg_BM (_.stmtob), cix, OUTSTRVALUE_BM (_.compv));
              FAILHERE (makenode2_BM
                        (k_curcomp, taggedint_BM (cix), _.compv));
            }
        }
    }
  else if (_.runv)
    {
      DBGPRINTF_BM ("miniscan_stmt°basiclo_run  stmtob=%s nonchunk runv=%s", objectdbg_BM (_.stmtob),  //
                    debug_outstr_value_BM (_.runv, CURFRAME_BM, 0));
      _.runtypob =
        miniscan_expr_BM (_.runv, _.routprepob, depth + 1, _.stmtob,
                          CURFRAME_BM);
      if (!_.runtypob)
        FAILHERE (makenode1_BM (k_run, _.runv));
    }
  DBGPRINTF_BM ("miniscan_stmt°basiclo_run end stmtob=%s",
                objectdbg_BM (_.stmtob));
  LOCALRETURN_BM (_.stmtob);
failure:
  DBGPRINTF_BM ("miniscan_stmt°basiclo_run failin %d stmtob=%s causev=%s routprepob=%s",       //
                failin, objectdbg_BM (_.stmtob),        //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0),       //
                objectdbg1_BM (_.routprepob));
  _.errorv = (value_tyBM)
    makenode5_BM (k_miniscan_stmt, _.stmtob, _.routprepob,
                  taggedint_BM (depth), _.fromob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end miniscan_stmt°basiclo_run  _6pA1Fxh7omw_0vJfR3s4tty */



//miniscan_stmt°basiclo_intswitch _2CKEpke8P0q_8s0Vli5gjxM

extern objrout_sigBM ROUTINEOBJNAME_BM (_2CKEpke8P0q_8s0Vli5gjxM);

value_tyBM
ROUTINEOBJNAME_BM (_2CKEpke8P0q_8s0Vli5gjxM)    //miniscan_stmt°basiclo_intswitch 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         //stmtob - an intswitch 
 const value_tyBM arg2,         //routprepob
 const value_tyBM arg3,         //depth
 const value_tyBM arg4,         //fromob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_basiclo_when = BMK_3fvdRZNCmJS_5bTAPr83mXg;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  objectval_tyBM *k_for = BMK_1SolDiQA2WM_4IDOJKBiPFc;
  objectval_tyBM *k_when = BMK_7KdDnQYcbeY_4LbTWNwFIFY;
  objectval_tyBM *k_default = BMK_0Ost4Do2yhq_95ticPFRmQO;
  objectval_tyBM *k_hashmapval_object = BMK_1DdzQEqzTvJ_1mjRDRDUdTw;
  objectval_tyBM *k_in = BMK_0eMGYofuNVh_8ZP2mXdhtHO;
  objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
  objectval_tyBM *k_miniscan_block = BMK_2gthNYOWogO_4sVTU1JbmUH;
  objectval_tyBM *k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  objectval_tyBM *k_statement_properties = BMK_0OM3NoUpOBd_1nzwCJKw54A;
  objectval_tyBM *k_switch = BMK_5PJV21P82kA_2KfQTz95vdH;
  objectval_tyBM *k_test = BMK_2j84OTHlFdJ_1pMyQfgsmAz;
  objectval_tyBM *kk_intswitchwhenminiscan = BMK_7X7mHMa1QpC_1TQBkXwqeik;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_2CKEpke8P0q_8s0Vli5gjxM,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * hashmapob;    //
                 objectval_tyBM * compob;       //
                 objectval_tyBM * switchtypob;  //
                 objectval_tyBM * subcompob;    //
                 objectval_tyBM * stmtpropob;   //
                 value_tyBM switchexpv; //
                 value_tyBM compv;      //
                 value_tyBM subcompv;   //
                 value_tyBM testv;      //
                 value_tyBM restestv;   //
                 value_tyBM whensetv;   //
                 value_tyBM defaulttupv;        //
                 value_tyBM oldv;       //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
                 value_tyBM resultv;
    );
  int depth = 0;
  _.stmtob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  depth = getint_BM (arg3);
  _.fromob = objectcast_BM (arg4);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev= (value_tyBM)(Cause); goto failure; } while(0)
  WEAKASSERT_BM (_.stmtob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (arg3) && depth >= 0);
  WEAKASSERT_BM (_.fromob);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_intswitch start stmtob=%s routprepob=%s depth#%d fromob=%s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromob));
  _.hashmapob = makeobj_BM ();
  int stmtlen = objnbcomps_BM (_.stmtob);
  objputclass_BM (_.hashmapob, k_hashmapval_object);
  objputhashmapvalpayl_BM (_.hashmapob, prime_above_BM (10 + 3 * stmtlen));
  objputattr_BM (_.hashmapob, k_for, _.stmtob);
  objputattr_BM (_.hashmapob, k_in, _.routprepob);
  _.switchexpv = objgetattr_BM (_.stmtob, k_switch);
  DBGPRINTF_BM ("miniscan_stmt°basiclo_intswitch stmtob=%s hashmapob=%s switchexp=%s stmtlen=%d",      //
                objectdbg_BM (_.stmtob), objectdbg1_BM (_.hashmapob),
                debug_outstr_value_BM (_.switchexpv, CURFRAME_BM, 0),
                stmtlen);
  _.switchtypob =
    miniscan_expr_BM (_.switchexpv, _.routprepob, depth + 1, _.stmtob,
                      CURFRAME_BM);
  DBGPRINTF_BM ("miniscan_stmt°basiclo_intswitch stmtob=%s switchtypob=%s",
                objectdbg_BM (_.stmtob), objectdbg1_BM (_.switchtypob));
  if (_.switchtypob != k_int)
    {
      FAILHERE (makenode2_BM (k_int, _.switchexpv, _.switchtypob));
    }
  WEAKASSERT_BM (objhashashmapvalpayl_BM (_.hashmapob));
  int lastwhenix = -1;
  for (int wix = 0; wix < stmtlen; wix++)
    {
      _.compv = objgetcomp_BM (_.stmtob, wix);
      if (!_.compv)
        continue;
      _.compob = objectcast_BM (_.compv);
      DBGPRINTF_BM ("miniscan_stmt°basiclo_intswitch stmtob=%s wix=%d compob=%s",      //
                    objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.compob));
      if (!_.compob)
        FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (wix), _.compv));
      objlock_BM (_.compob);
      if (!objectisinstance_BM (_.compob, k_basiclo_when))
        {
          objunlock_BM (_.compob);
          break;
        }
      _.testv = objgetattr_BM (_.compob, k_test);
      DBGPRINTF_BM
        ("miniscan_stmt°basiclo_intswitch stmtob=%s wix=%d compob=%s testv=%s hashmapob=%s routprepob=%s",
         objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.compob),
         debug_outstr_value_BM (_.testv, CURFRAME_BM, 0),
         objectdbg2_BM (_.hashmapob), objectdbg3_BM (_.routprepob));
      _.restestv =
        apply7_BM (kk_intswitchwhenminiscan, CURFRAME_BM, _.testv,
                   _.hashmapob, _.routprepob, taggedint_BM (depth), _.compob,
                   _.stmtob, taggedint_BM (wix));
      DBGPRINTF_BM ("miniscan_stmt°basiclo_intswitch stmtob=%s wix=%d compob=%s\n"     //
                    ".. after int-switch-when-miniscan hashmapob %s restestv %s",       //
                    objectdbg_BM (_.stmtob), wix,       //
                    objectdbg1_BM (_.compob),
                    objectdbg2_BM (_.hashmapob),
                    debug_outstr_value_BM (_.restestv, CURFRAME_BM, 0));
      unsigned complen = objnbcomps_BM (_.compob);
      for (unsigned cix = 0; cix < complen; cix++)
        {
          _.subcompv = objgetcomp_BM (_.compob, cix);
          if (!_.subcompv)
            continue;
          _.subcompob = objectcast_BM (_.subcompv);
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_intswitch stmtob=%s wix#%d compob=%s cix#%d subcompob=%s",
             objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.compob), cix,
             objectdbg2_BM (_.subcompob));
          if (!_.subcompob)
            {
              FAILHERE (makenode3_BM
                        (k_curcomp, taggedint_BM (wix), taggedint_BM (cix),
                         _.subcompv));
            };
          if (objectisinstance_BM (_.subcompob, k_basiclo_block))
            {
              DBGPRINTF_BM
                ("miniscan_stmt°basiclo_intswitch stmtob=%s wix#%d compob=%s cix#%d subcompob=%s before miniscan_block",
                 objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.compob), cix,
                 objectdbg2_BM (_.subcompob));
              _.resultv =
                send3_BM (_.subcompob, k_miniscan_block,
                          CURFRAME_BM, _.routprepob,
                          taggedint_BM (depth + 1), _.compob);
              DBGPRINTF_BM
                ("miniscan_stmt°basiclo_intswitch stmtob=%s wix#%d compob=%s cix#%d subcompob=%s after miniscan_block resultv=%s",
                 objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.compob), cix,
                 objectdbg2_BM (_.subcompob),
                 debug_outstr_value_BM (_.resultv, CURFRAME_BM, 0));
              if (!_.resultv)
                FAILHERE (makenode2_BM
                          (k_miniscan_block, taggedint_BM (wix),
                           taggedint_BM (cix)));
            }
          else if (objectisinstance_BM (_.subcompob, k_basiclo_statement))
            {
              DBGPRINTF_BM
                ("miniscan_stmt°basiclo_intswitch stmtob=%s wix#%d compob=%s cix#%d subcompob=%s before miniscan_stmt",
                 objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.compob), cix,
                 objectdbg2_BM (_.subcompob));
              _.resultv =
                send3_BM (_.subcompob, k_miniscan_stmt, CURFRAME_BM,
                          _.routprepob, taggedint_BM (depth + 1), _.compob);
              DBGPRINTF_BM
                ("miniscan_stmt°basiclo_intswitch stmtob=%s wix#%d compob=%s cix#%d subcompob=%s after miniscan_stmt°basiclo_intswitch resultv=%s",
                 objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.compob), cix,
                 objectdbg2_BM (_.subcompob),
                 debug_outstr_value_BM (_.resultv, CURFRAME_BM, 0));
              if (!_.resultv)
                FAILHERE (makenode2_BM
                          (k_miniscan_stmt, taggedint_BM (wix),
                           taggedint_BM (cix)));
            }
          else
            {
              FAILHERE (makenode3_BM
                        (k_curcomp, taggedint_BM (wix), _.subcompob,
                         taggedint_BM (cix)));
            }
        }
      lastwhenix = wix;
      objunlock_BM (_.compob);
    }
  _.whensetv = (value_tyBM)
    makeset_BM ((const objectval_tyBM **) objcompdata_BM (_.stmtob),
                lastwhenix + 1);
  _.defaulttupv = (value_tyBM)
    maketuple_BM ((objectval_tyBM **) objcompdata_BM (_.stmtob) + lastwhenix +
                  1, stmtlen - lastwhenix - 1);
  objputattr_BM (_.hashmapob, k_when, _.whensetv);
  objputattr_BM (_.hashmapob, k_default, _.defaulttupv);
  objtouchnow_BM (_.hashmapob);
  // put hashmapob
  _.stmtpropob =
    objectcast_BM (objgetattr_BM (_.routprepob, k_statement_properties));
  DBGPRINTF_BM ("miniscan_stmt°basiclo_intswitch ending stmtob=%s\n"   //
                ".. routprepob=%s hashmapob=%s stmtpropob=%s stmtlen=%d lastwhenix=%d\n"        //
                ".. whenset=%s defaulttup=%s",  //
                objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),
                objectdbg2_BM (_.hashmapob), objectdbg3_BM (_.stmtpropob),
                stmtlen, lastwhenix,
                debug_outstr_value_BM (_.whensetv, CURFRAME_BM, 0),
                debug_outstr_value_BM (_.defaulttupv, CURFRAME_BM, 0));
  WEAKASSERT_BM (isobject_BM (_.stmtpropob));
  WEAKASSERT_BM (objhasassocpayl_BM (_.stmtpropob));
  _.oldv = objassocgetattrpayl_BM (_.stmtpropob, _.stmtob);
  if (_.oldv)
    FAILHERE (makenode4_BM
              (k_statement_properties, _.stmtpropob, _.stmtob, _.oldv,
               _.hashmapob));
  objassocaddattrpayl_BM (_.stmtpropob, _.stmtob, _.hashmapob);
  LOCALRETURN_BM (_.stmtob);
failure:
  DBGPRINTF_BM ("miniscan_stmt°basiclo_intswitch failin %d stmtob=%s causev=%s routprepob=%s", //
                failin, objectdbg_BM (_.stmtob),        //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0),       //
                objectdbg1_BM (_.routprepob));
  _.errorv = (value_tyBM)
    makenode5_BM (k_miniscan_stmt, _.stmtob, _.routprepob,
                  taggedint_BM (depth), _.fromob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end miniscan_stmt°basiclo_intswitch  _2CKEpke8P0q_8s0Vli5gjxM */



// int-switch-when-miniscan _7X7mHMa1QpC_1TQBkXwqeik

extern objrout_sigBM ROUTINEOBJNAME_BM (_7X7mHMa1QpC_1TQBkXwqeik);

value_tyBM
ROUTINEOBJNAME_BM (_7X7mHMa1QpC_1TQBkXwqeik)    // int-switch-when-miniscan
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // testv
 const value_tyBM arg2,         // hashmapob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * /*compob, stmtob, wix. */ restargs)
{
  objectval_tyBM * k_duplicate = BMK_2YrbiKQ6lxP_3KNUOnU6TF5;
  objectval_tyBM *k_overflow = BMK_18VEwdmWZ1v_5cpJ8tDhbwH;
  objectval_tyBM *k_range = BMK_2A0PhF7YCym_7D4TZoZ5DUp;
  objectval_tyBM *k_test = BMK_2j84OTHlFdJ_1pMyQfgsmAz;
  objectval_tyBM *k_or = BMK_8kgO3yCQf1K_9HShuVu6MBo;
  objectval_tyBM *k_depth = BMK_17YdW6dWrBA_2mn4QmBjMNs;
  objectval_tyBM *kk_intswitchwhenminiscan = BMK_7X7mHMa1QpC_1TQBkXwqeik;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_7X7mHMa1QpC_1TQBkXwqeik,
                 value_tyBM testv;      //
                 objectval_tyBM * hashmapob;    //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * connob;       //
                 objectval_tyBM * compob;       //
                 value_tyBM resultv;    //
                 value_tyBM hashv;      //
                 value_tyBM errorv;     //
                 value_tyBM tson0v; value_tyBM tson1v;
                 value_tyBM tmpv;
                 value_tyBM causev;
    );
  _.testv = arg1;
  _.hashmapob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  unsigned nbrestargs = treewidth_BM ((value_tyBM) restargs);
  int wix = -1;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  if (nbrestargs >= 3)
    {
      _.compob = objectcast_BM (restargs->nodt_sons[0]);
      _.stmtob = objectcast_BM (restargs->nodt_sons[1]);
      wix = getint_BM (restargs->nodt_sons[2]);
    };
  DBGPRINTF_BM
    ("int-switch-when-miniscan start testv=%s hashmapob=%s routprepob=%s depth=%d compob=%s stmtob=%s wix=%d",
     debug_outstr_value_BM (_.testv, CURFRAME_BM, 0),
     objectdbg_BM (_.hashmapob), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.compob), objectdbg3_BM (_.stmtob), wix);
  WEAKASSERT_BM (_.hashmapob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (_.stmtob);
  WEAKASSERT_BM (_.compob);
  WEAKASSERT_BM (objhashashmapvalpayl_BM (_.hashmapob));
  unsigned nbhval = objhashmapvalsizepayl_BM (_.hashmapob);
  if (nbhval > MAXINTCASES_BM)
    {
      FAILHERE (makenode1_BM (k_overflow, taggedint_BM (nbhval)));
    }
  if (depth >= MAXDEPTHPARSE_BM)
    FAILHERE (makenode1_BM (k_depth, taggedint_BM (depth)));
  if (istaggedint_BM (_.testv))
    {
      _.hashv = objhashmapvalgetpayl_BM (_.hashmapob, _.testv);
      if (_.hashv)
        {
          FAILHERE (makenode3_BM (k_duplicate, _.testv, _.hashv, _.stmtob));
        }
      objhashmapvalputpayl_BM (_.hashmapob, _.testv, _.compob);
      LOCALRETURN_BM (_.testv);
    }
  else if (isnode_BM (_.testv))
    {
      _.connob = nodeconn_BM (_.testv);
      unsigned tarity = nodewidth_BM (_.testv);
      if (tarity == 2 && _.connob == k_range)
        {
          _.tson0v = nodenthson_BM (_.testv, 0);
          _.tson1v = nodenthson_BM (_.testv, 1);
          if (istaggedint_BM (_.tson0v) && istaggedint_BM (_.tson1v))
            {
              intptr_t i0 = getint_BM (_.tson0v);
              intptr_t i1 = getint_BM (_.tson1v);
              if (i0 > i1)
                FAILHERE (makenode1_BM (k_range, _.testv));
              if (i1 > i0 + MAXINTCASES_BM / 2)
                FAILHERE (makenode1_BM (k_range, _.testv));
              for (intptr_t i = i0; i < i1; i++)
                {
                  _.tmpv = taggedint_BM (i);
                  _.hashv = objhashmapvalgetpayl_BM (_.hashmapob, _.tmpv);
                  if (_.hashv)
                    {
                      FAILHERE (makenode4_BM
                                (k_duplicate, _.tmpv, _.hashv, _.testv,
                                 _.stmtob));
                    }
                  objhashmapvalputpayl_BM (_.hashmapob, _.tmpv, _.compob);
                }
              LOCALRETURN_BM (_.testv);
            }
        }
      else if (_.connob == k_or && tarity > 0)
        {
          DBGPRINTF_BM
            ("int-switch-when-miniscan or testv=%s hashmapob=%s routprepob=%s depth=%d stmtob=%s wix=%d",
             debug_outstr_value_BM (_.testv, CURFRAME_BM, 0),
             objectdbg_BM (_.hashmapob), objectdbg1_BM (_.routprepob), depth,
             objectdbg2_BM (_.stmtob), wix);
          for (int ix = 0; ix < (int) tarity; ix++)
            {
              _.tmpv = nodenthson_BM (_.testv, ix);
              DBGPRINTF_BM
                ("int-switch-when-miniscan or tmpv=%s ix#%d",
                 debug_outstr_value_BM (_.tmpv, CURFRAME_BM, 0), ix);
              _.resultv =
                apply7_BM (kk_intswitchwhenminiscan, CURFRAME_BM, _.tmpv,
                           _.hashmapob, _.routprepob,
                           taggedint_BM (depth + 1), _.compob, _.stmtob,
                           taggedint_BM (wix));
              DBGPRINTF_BM
                ("int-switch-when-miniscan or did tmpv=%s ix#%d result %s",
                 debug_outstr_value_BM (_.tmpv, CURFRAME_BM, 0), ix,
                 debug_outstr_value_BM (_.resultv, CURFRAME_BM, 0));
              if (!_.resultv)
                FAILHERE (makenode2_BM (k_or, taggedint_BM (ix), _.tmpv));
            }
          LOCALRETURN_BM (_.testv);
        }
    }
  FAILHERE (makenode1_BM (k_test, _.testv));
#undef FAILHERE
failure:
  DBGPRINTF_BM
    ("int-switch-when-miniscan failin %d testv=%s causev=%s hashmapob=%s routprepob=%s depth=%d stmtob=%s wix=%d",
     failin, debug_outstr_value_BM (_.testv, CURFRAME_BM, 0),
     debug_outstr_value_BM (_.causev, CURFRAME_BM, 0),
     objectdbg_BM (_.hashmapob), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.stmtob), wix);
  _.errorv =
    (value_tyBM) makenode7_BM (BMK_7X7mHMa1QpC_1TQBkXwqeik, _.testv, _.causev,
                               _.hashmapob, _.routprepob,
                               taggedint_BM (depth), _.stmtob,
                               taggedint_BM (wix));
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end int-switch-when-miniscan _7X7mHMa1QpC_1TQBkXwqeik */



////////////////////////////////////////////////////////////////
///// scanning objswitch
// return true if compob is not a when
static bool
stopscan_objswitch_comp_bm (struct stackframe_stBM *stkf,
                            objectval_tyBM * compob,
                            int compix,
                            objectval_tyBM * stmtob,
                            objectval_tyBM * fromob,
                            objectval_tyBM * assocob,
                            objectval_tyBM * routprepob, int depth)
{
  objectval_tyBM *k_basiclo_when = BMK_3fvdRZNCmJS_5bTAPr83mXg;
  objectval_tyBM *k_test = BMK_2j84OTHlFdJ_1pMyQfgsmAz;
  //objectval_tyBM *k_when = BMK_7KdDnQYcbeY_4LbTWNwFIFY;
  objectval_tyBM *k_duplicate = BMK_2YrbiKQ6lxP_3KNUOnU6TF5;
  objectval_tyBM *k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  LOCALFRAME_BM (stkf, NULL, objectval_tyBM * compob;   //
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * assocob;      //
                 objectval_tyBM * testob;       //
                 objectval_tyBM * routprepob;   //
                 value_tyBM testv; value_tyBM oldwhenv;
                 value_tyBM causev;
                 value_tyBM errorv;
    );
  _.compob = compob;
  _.stmtob = stmtob;
  _.fromob = fromob;
  _.assocob = assocob;
  _.routprepob = routprepob;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev= (value_tyBM)(Cause); goto failure; } while(0)
  if (objectisinstance_BM (_.compob, k_basiclo_when))
    {
      _.testv = objgetattr_BM (_.compob, k_test);
      _.testob = NULL;
      _.oldwhenv = NULL;
      DBGPRINTF_BM
        ("stopscan_objswitch_comp_bm compob=%s when compix#%d testv=%s stmtob=%s fromob=%s",
         objectdbg_BM (_.compob), compix, OUTSTRVALUE_BM (_.testv),
         objectdbg1_BM (_.stmtob), objectdbg2_BM (_.fromob));
      if (isobject_BM (_.testv))
        {
          _.testob = objectcast_BM (_.testv);
          _.oldwhenv = objassocgetattrpayl_BM (_.assocob, _.testob);
          if (_.oldwhenv)
            {
              FAILHERE (makenode4_BM
                        (k_duplicate, _.testob, _.compob, _.oldwhenv,
                         _.assocob));
            }
          DBGPRINTF_BM
            ("stopscan_objswitch_comp_bm +assocob=%s single testob=%s compob=%s\n"
             ".. stmtob=%s compix#%d", objectdbg_BM (_.assocob),
             objectdbg1_BM (_.testob), objectdbg2_BM (_.compob),
             objectdbg3_BM (_.stmtob), compix);
          objassocaddattrpayl_BM (_.assocob, _.testob, _.compob);
        }
      else if (issequence_BM (_.testv))
        {
          int nbtests = sequencesize_BM (_.testv);
          for (int tix = 0; tix < nbtests; tix++)
            {
              _.testob = sequencenthcomp_BM (_.testv, tix);
              if (!_.testob)
                continue;
              _.oldwhenv = objassocgetattrpayl_BM (_.assocob, _.testob);
              if (_.oldwhenv)
                {
                  FAILHERE (makenode4_BM
                            (k_duplicate, _.testob, _.compob, _.oldwhenv,
                             _.assocob));
                }
              DBGPRINTF_BM
                ("stopscan_objswitch_comp_bm +assocob=%s comp testob=%s tix#%d compob=%s\n"
                 ".. stmtob=%s compix#%d", objectdbg_BM (_.assocob),
                 objectdbg1_BM (_.testob), tix, objectdbg2_BM (_.compob),
                 objectdbg3_BM (_.stmtob), compix);
              objassocaddattrpayl_BM (_.assocob, _.testob, _.compob);
            }
        }
      else
        {
          // invalid test in basiclo_when
          FAILHERE (makenode2_BM (k_test, _.testv, _.compob));
        }
      DBGPRINTF_BM
        ("stopscan_objswitch_comp_bm ending/when compob=%s compix#%d assocob=%s of keys %s",
         objectdbg_BM (_.compob), compix, objectdbg1_BM (_.assocob),
         OUTSTRVALUE_BM ((value_tyBM) objassocsetattrspayl_BM (_.assocob)));
      return false;
    }                           /* end if compob is a basiclo_when */
  else                          /* compob is not a basiclo_when */
    {
      DBGPRINTF_BM
        ("stopscan_objswitch_comp_bm compob=%s compix#%d STOP notwhen",
         objectdbg_BM (_.compob), compix);
      return true;
    }
failure:
  DBGPRINTF_BM ("stopscan_objswitch_comp_bm failin %d compob=%s compix#%d stmtob=%s causev=%s routprepob=%s",   //
                failin, objectdbg_BM (_.compob), compix, objectdbg1_BM (_.stmtob),      //
                OUTSTRVALUE_BM (_.causev), objectdbg2_BM (_.routprepob));
  _.errorv = (value_tyBM)
    makenode6_BM (k_miniscan_stmt, _.stmtob, taggedint_BM (compix),
                  _.routprepob, taggedint_BM (depth), _.fromob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end stopscan_objswitch_comp_bm */



//miniscan_stmt°basiclo_objswitch  _5nFFthyf8y9_00k5H4R0G6b

extern objrout_sigBM ROUTINEOBJNAME_BM (_5nFFthyf8y9_00k5H4R0G6b);

value_tyBM
ROUTINEOBJNAME_BM (_5nFFthyf8y9_00k5H4R0G6b)    //miniscan_stmt°basiclo_objswitch 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         //stmtob - an objswitch 
 const value_tyBM arg2,         //routprepob
 const value_tyBM arg3,         //depth
 const value_tyBM arg4,         //fromob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_assoc_object = BMK_6ZQ05nCv3Ys_8LA6B5LkZgm;
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_basiclo_when = BMK_3fvdRZNCmJS_5bTAPr83mXg;
  objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  objectval_tyBM *k_default = BMK_0Ost4Do2yhq_95ticPFRmQO;
  objectval_tyBM *k_duplicate = BMK_2YrbiKQ6lxP_3KNUOnU6TF5;
  objectval_tyBM *k_for = BMK_1SolDiQA2WM_4IDOJKBiPFc;
  objectval_tyBM *k_in = BMK_0eMGYofuNVh_8ZP2mXdhtHO;
  objectval_tyBM *k_miniscan_block = BMK_2gthNYOWogO_4sVTU1JbmUH;
  objectval_tyBM *k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  objectval_tyBM *k_modgenob = BMK_0Bl5ro9usp6_1Hll14QwC8f;
  objectval_tyBM *k_statement_properties = BMK_0OM3NoUpOBd_1nzwCJKw54A;
  objectval_tyBM *k_switch = BMK_5PJV21P82kA_2KfQTz95vdH;
  //objectval_tyBM *k_test = BMK_2j84OTHlFdJ_1pMyQfgsmAz;
  objectval_tyBM *k_when = BMK_7KdDnQYcbeY_4LbTWNwFIFY;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_5nFFthyf8y9_00k5H4R0G6b,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * assocob;      //
                 objectval_tyBM * switchtypob;  //
                 objectval_tyBM * compob;       //
                 objectval_tyBM * caseob;       //
                 objectval_tyBM * subcompob;    //
                 objectval_tyBM * stmtpropob;   //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * consthsetob;  //
                 value_tyBM compv;      //
                 value_tyBM subcompv;   //
                 value_tyBM switchexpv; //
                 value_tyBM oldwhenv;   //
                 value_tyBM whensetv;   //
                 value_tyBM oldv;       //
                 value_tyBM keysetv;    //
                 value_tyBM defaulttupv;        //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
                 value_tyBM resultv;
    );
  int depth = 0;
  _.stmtob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  depth = getint_BM (arg3);
  _.fromob = objectcast_BM (arg4);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev= (value_tyBM)(Cause); goto failure; } while(0)
  WEAKASSERT_BM (_.stmtob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (arg3) && depth >= 0);
  WEAKASSERT_BM (_.fromob);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_objswitch start stmtob=%s routprepob=%s depth#%d fromob=%s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromob));
  int stmtlen = objnbcomps_BM (_.stmtob);
  _.assocob = makeobj_BM ();
  objputassocpayl_BM (_.assocob, prime_above_BM (10 + 3 * stmtlen));
  objputattr_BM (_.assocob, k_for, _.stmtob);
  objputattr_BM (_.assocob, k_in, _.routprepob);
  objputclass_BM (_.assocob, k_assoc_object);
  _.switchexpv = objgetattr_BM (_.stmtob, k_switch);
  _.modgenob = objectcast_BM (objgetattr_BM (_.routprepob, k_modgenob));
  _.consthsetob = objectcast_BM (objgetattr_BM (_.modgenob, k_constants));
  DBGPRINTF_BM ("miniscan_stmt°basiclo_objswitch stmtob=%s assocob=%s switchexp=%s stmtlen=%d modgenob=%s consthsetob=%s",     //
                objectdbg_BM (_.stmtob), objectdbg1_BM (_.assocob),
                debug_outstr_value_BM (_.switchexpv, CURFRAME_BM, 0),
                stmtlen,
                objectdbg2_BM (_.modgenob), objectdbg3_BM (_.consthsetob));
  _.switchtypob =
    miniscan_expr_BM (_.switchexpv, _.routprepob, depth + 1, _.stmtob,
                      CURFRAME_BM);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_objswitch stmtob=%s switchtypob=%s assocob=%s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.switchtypob),
     objectdbg2_BM (_.assocob));
  if (_.switchtypob != BMP_object)
    {
      FAILHERE (makenode2_BM (BMP_object, _.switchexpv, _.switchtypob));
    }
  int nbwhens = 0;
  ////////////////
  /// first loop to count the whens and collect in assocob the cases
  for (int wix = 0; wix < stmtlen; wix++)
    {
      _.compob = NULL;
      _.compv = objgetcomp_BM (_.stmtob, wix);
      if (!_.compv)
        continue;
      _.compob = objectcast_BM (_.compv);
      DBGPRINTF_BM
        ("miniscan_stmt°basiclo_objswitch stmtob=%s compob=%s fromob=%s wix=%d",
         objectdbg_BM (_.stmtob),
         objectdbg1_BM (_.compob), objectdbg2_BM (_.fromob), wix);
      if (!_.compob)
        FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (wix), _.compv));
      bool ending = false;
      objlock_BM (_.compob);
      ending =                  //
        stopscan_objswitch_comp_bm (CURFRAME_BM, _.compob, wix, //
                                    _.stmtob, _.fromob, _.assocob, _.routprepob,        //
                                    depth);
      objunlock_BM (_.compob);
      if (ending)
        {
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_objswitch stmtob=%s compob=%s of %s fromob=%s wix=%d ENDING",
             objectdbg_BM (_.stmtob),
             objectdbg1_BM (_.compob),
             objectdbg2_BM (objclass_BM (_.compob)),
             objectdbg3_BM (_.fromob), wix);
          break;
        }
      else
        {
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_objswitch stmtob=%s compob=%s of %s fromob=%s wix=%d stmtlen=%d again",
             objectdbg_BM (_.stmtob),
             objectdbg1_BM (_.compob),
             objectdbg2_BM (objclass_BM (_.compob)),
             objectdbg3_BM (_.fromob), wix, stmtlen);
          nbwhens++;
        }
    }
  _.keysetv = (value_tyBM) objassocsetattrspayl_BM (_.assocob);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_objswitch stmtob=%s assocob=%s, keysetv %s, nbwhens=%d, stmtlen=%d",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.assocob),
     OUTSTRVALUE_BM (_.keysetv), nbwhens, stmtlen);
  /// add all the keys as module constants
  {
    unsigned nbkeys = setcardinal_BM (_.keysetv);
    DBGPRINTF_BM
      ("miniscan_stmt°basiclo_objswitch stmtob=%s consthsetob=%s",
       objectdbg_BM (_.stmtob), objectdbg1_BM (_.consthsetob));
    WEAKASSERT_BM (objhashashsetpayl_BM (_.consthsetob));
    for (unsigned kix = 0; kix < nbkeys; kix++)
      {
        _.caseob = setelemnth_BM (_.keysetv, kix);
        objhashsetaddpayl_BM (_.consthsetob, _.caseob);
      }
    _.caseob = NULL;
  }
  ////////////////
  /// second loop to scan the statements and blocks inside the when-s
  for (int wix = 0; wix < nbwhens; wix++)
    {
      _.compob = NULL;
      _.compv = NULL;
      _.compob = objectcast_BM (objgetcomp_BM (_.stmtob, wix));
      DBGPRINTF_BM ("miniscan_stmt°basiclo_objswitch stmtob=%s wix=%d compob=%s",      //
                    objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.compob));
      objlock_BM (_.compob);
      WEAKASSERT_BM (objectisinstance_BM (_.compob, k_basiclo_when));
      _.subcompv = NULL;
      unsigned complen = objnbcomps_BM (_.compob);
      DBGPRINTF_BM
        ("miniscan_stmt°basiclo_objswitch stmtob=%s wix=%d compob=%s:L%u assocob=%s routprepob=%s",
         objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.compob), complen,
         objectdbg2_BM (_.assocob), objectdbg3_BM (_.routprepob));
      for (unsigned cix = 0; cix < complen; cix++)
        {
          _.subcompv = objgetcomp_BM (_.compob, cix);
          if (!_.subcompv)
            continue;
          _.subcompob = objectcast_BM (_.subcompv);
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_objswitch stmtob=%s wix#%d compob=%s cix#%d subcompob=%s",
             objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.compob), cix,
             objectdbg2_BM (_.subcompob));
          if (!_.subcompob)
            {
              FAILHERE (makenode3_BM
                        (k_curcomp, taggedint_BM (wix), taggedint_BM (cix),
                         _.subcompv));
            };
          if (objectisinstance_BM (_.subcompob, k_basiclo_block))
            {
              DBGPRINTF_BM
                ("miniscan_stmt°basiclo_objswitch stmtob=%s wix#%d compob=%s cix#%d subcompob=%s before miniscan_block",
                 objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.compob), cix,
                 objectdbg2_BM (_.subcompob));
              _.resultv =
                send3_BM (_.subcompob, k_miniscan_block,
                          CURFRAME_BM, _.routprepob,
                          taggedint_BM (depth + 1), _.compob);
              DBGPRINTF_BM
                ("miniscan_stmt°basiclo_objswitch stmtob=%s wix#%d compob=%s cix#%d subcompob=%s after miniscan_block resultv=%s",
                 objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.compob), cix,
                 objectdbg2_BM (_.subcompob),
                 debug_outstr_value_BM (_.resultv, CURFRAME_BM, 0));
              if (!_.resultv)
                FAILHERE (makenode2_BM
                          (k_miniscan_block, taggedint_BM (wix),
                           taggedint_BM (cix)));
            }
          else if (objectisinstance_BM (_.subcompob, k_basiclo_statement))
            {
              DBGPRINTF_BM
                ("miniscan_stmt°basiclo_objswitch stmtob=%s wix#%d compob=%s cix#%d subcompob=%s before miniscan_stmt",
                 objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.compob), cix,
                 objectdbg2_BM (_.subcompob));
              _.resultv =
                send3_BM (_.subcompob, k_miniscan_stmt, CURFRAME_BM,
                          _.routprepob, taggedint_BM (depth + 1), _.compob);
              DBGPRINTF_BM
                ("miniscan_stmt°basiclo_objswitch stmtob=%s wix#%d compob=%s cix#%d subcompob=%s after miniscan_stmt°basiclo_intswitch resultv=%s",
                 objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.compob), cix,
                 objectdbg2_BM (_.subcompob),
                 debug_outstr_value_BM (_.resultv, CURFRAME_BM, 0));
              if (!_.resultv)
                FAILHERE (makenode2_BM
                          (k_miniscan_stmt, taggedint_BM (wix),
                           taggedint_BM (cix)));
            }
          else
            {
              FAILHERE (makenode3_BM
                        (k_curcomp, taggedint_BM (wix), _.subcompob,
                         taggedint_BM (cix)));
            }
        }                       /* end for cix */
      DBGPRINTF_BM
        ("miniscan_stmt°basiclo_objswitch stmtob=%s wix#%d compob=%s",
         objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.compob));
      _.subcompob = NULL;
      objunlock_BM (_.compob);
      _.compob = NULL;
      DBGPRINTF_BM ("miniscan_stmt°basiclo_objswitch stmtob=%s end wix=%d\n",
                    objectdbg_BM (_.stmtob), wix);
    }                           // end second loop for wix

  ////////////////
  //// third loop to scan the else-statements
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_objswitch stmtob=%s, nbwhens=%d, stmtlen=%d",
     objectdbg_BM (_.stmtob), nbwhens, stmtlen);
  for (int dix = nbwhens; dix < stmtlen; dix++)
    {
      _.compv = objgetcomp_BM (_.stmtob, dix);
      if (!_.compv)
        continue;
      _.compob = objectcast_BM (_.compv);
      DBGPRINTF_BM ("miniscan_stmt°basiclo_objswitch stmtob=%s dix=%d compob=%s",      //
                    objectdbg_BM (_.stmtob), dix, objectdbg1_BM (_.compob));
      if (!_.compob)
        FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (dix), _.compv));
      objlock_BM (_.compob);
      _.resultv = NULL;
      if (objectisinstance_BM (_.compob, k_basiclo_block))
        {
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_objswitch stmtob=%s dix#%d compob=%s block",
             objectdbg_BM (_.stmtob), dix, objectdbg1_BM (_.compob));
          _.resultv =
            send3_BM (_.compob, k_miniscan_block,
                      CURFRAME_BM, _.routprepob,
                      taggedint_BM (depth + 1), _.stmtob);
          if (!_.resultv)
            {
              objunlock_BM (_.compob);
              FAILHERE (makenode2_BM
                        (k_miniscan_block, taggedint_BM (dix), _.compob));
            }
        }
      else if (objectisinstance_BM (_.compob, k_basiclo_statement))
        {
          DBGPRINTF_BM
            ("miniscan_stmt°basiclo_objswitch stmtob=%s dix#%d compob=%s statement",
             objectdbg_BM (_.stmtob), dix, objectdbg1_BM (_.compob));
          _.resultv =
            send3_BM (_.compob, k_miniscan_stmt, CURFRAME_BM,
                      _.routprepob, taggedint_BM (depth + 1), _.stmtob);
          if (!_.resultv)
            {
              objunlock_BM (_.compob);
              FAILHERE (makenode2_BM
                        (k_miniscan_stmt, taggedint_BM (dix), _.compob));
            }
        }
      else
        {
          DBGPRINTF_BM ("strange compob %s of class %s dix#%d stmtob %s",
                        objectdbg_BM (_.compob),
                        objectdbg1_BM (objclass_BM (_.compob)),
                        dix, objectdbg2_BM (_.stmtob));
          objunlock_BM (_.compob);
          FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (dix), _.compob));
        }
      objunlock_BM (_.compob);
      DBGPRINTF_BM
        ("miniscan_stmt°basiclo_objswitch stmtob=%s dix#%d compob=%s result=%s",
         objectdbg_BM (_.stmtob), dix, objectdbg1_BM (_.compob),
         debug_outstr_value_BM (_.resultv, CURFRAME_BM, 0));
      _.resultv = NULL;
    }
  _.whensetv = (value_tyBM)
    makeset_BM ((const objectval_tyBM **) objcompdata_BM (_.stmtob), nbwhens);
  _.defaulttupv = (value_tyBM)
    maketuple_BM ((objectval_tyBM **) objcompdata_BM (_.stmtob) + nbwhens,
                  stmtlen - nbwhens);
  objputattr_BM (_.assocob, k_when, _.whensetv);
  objputattr_BM (_.assocob, k_default, _.defaulttupv);
  objtouchnow_BM (_.assocob);
  DBGPRINTF_BM ("miniscan_stmt°basiclo_objswitch stmtob=%s adding assocob=%s to routprepob=%s\n"       //
                ".. whenset=%s defaulttup=%s",  //
                objectdbg_BM (_.stmtob), objectdbg1_BM (_.assocob), objectdbg2_BM (_.routprepob),       //
                debug_outstr_value_BM (_.whensetv, CURFRAME_BM, 0),     //
                debug_outstr_value_BM (_.defaulttupv, CURFRAME_BM, 0));
  _.stmtpropob =
    objectcast_BM (objgetattr_BM (_.routprepob, k_statement_properties));
  /// should add the assocob
  DBGPRINTF_BM ("miniscan_stmt°basiclo_objswitch ending stmtob=%s\n"   //
                ".. routprepob=%s assocob=%s stmtpropob=%s stmtlen=%d nbwhens=%d\n"     //
                ".. whenset=%s defaulttup=%s",  //
                objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),
                objectdbg2_BM (_.assocob), objectdbg3_BM (_.stmtpropob),
                stmtlen, nbwhens,
                debug_outstr_value_BM (_.whensetv, CURFRAME_BM, 0),
                debug_outstr_value_BM (_.defaulttupv, CURFRAME_BM, 0));
  WEAKASSERT_BM (isobject_BM (_.stmtpropob));
  WEAKASSERT_BM (objhasassocpayl_BM (_.stmtpropob));
  _.oldv = objassocgetattrpayl_BM (_.stmtpropob, _.stmtob);
  if (_.oldv)
    FAILHERE (makenode4_BM
              (k_statement_properties, _.stmtpropob, _.stmtob, _.oldv,
               _.assocob));
  objassocaddattrpayl_BM (_.stmtpropob, _.stmtob, _.assocob);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_objswitch ended stmtob=%s routprepob=%s assocob=%s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),
     objectdbg2_BM (_.assocob));
  LOCALRETURN_BM (_.stmtob);
failure:
  DBGPRINTF_BM ("miniscan_stmt°basiclo_objswitch failin %d stmtob=%s causev=%s routprepob=%s", //
                failin, objectdbg_BM (_.stmtob),        //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0),       //
                objectdbg1_BM (_.routprepob));
  _.errorv = (value_tyBM)
    makenode5_BM (k_miniscan_stmt, _.stmtob, _.routprepob,
                  taggedint_BM (depth), _.fromob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end miniscan_stmt°basiclo_objswitch _5nFFthyf8y9_00k5H4R0G6b */




////////////////////////////////////////////////////////////////
// miniscan_node_conn°basiclo_primitive  _1vuSUudDrEr_9UjFr4Pcy8r
extern objrout_sigBM ROUTINEOBJNAME_BM (_1vuSUudDrEr_9UjFr4Pcy8r);
value_tyBM
ROUTINEOBJNAME_BM (_1vuSUudDrEr_9UjFr4Pcy8r)    // miniscan_node_conn°basiclo_primitive
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // connob
 const value_tyBM arg2,         // routprepob
 const value_tyBM arg3,         // depthv
 const value_tyBM arg4,         // expv
 const quasinode_tyBM * restargs /*fromob. */ )
{
  objectval_tyBM * k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  objectval_tyBM *k_result_type = BMK_8oZ9fPJGhmS_24c2sSYsdr2;
  objectval_tyBM *k_miniscan_node_conn = BMK_5EGLdtUAQxA_1nebCsDKqOF;
  objectval_tyBM *k_arity = BMK_6fPPUXnZhy5_8Lh5DOOe0Nu;
  objectval_tyBM *k_c_type = BMK_83kM1HtO8K3_6k0F2KYQT3W;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_1vuSUudDrEr_9UjFr4Pcy8r,
                 objectval_tyBM * connob;       //
                 objectval_tyBM * routprepob;   //
                 value_tyBM expv;       //
                 objectval_tyBM * fromob;       //
                 value_tyBM connargsv;  //
                 objectval_tyBM * restypob;     //
                 value_tyBM resultv;    //
                 value_tyBM errorv;     //
                 value_tyBM cursonv;
                 objectval_tyBM * curargob;     //
                 objectval_tyBM * curtypob;     //
                 objectval_tyBM * curargctypob; //
                 objectval_tyBM * connrestypob; //
                 objectval_tyBM * curcomptypob; //
                 value_tyBM extraerrorv;        //
    );
  int failin = -1;
#define FAILHERE(Xtra) do { failin = __LINE__ ; _.extraerrorv = (value_tyBM)(Xtra); goto failure; } while(0)
  _.connob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  int depth = getint_BM (arg3);
  _.expv = arg4;
  _.fromob = objectcast_BM (treenthson_BM ((value_tyBM) restargs, 0));
  DBGPRINTF_BM ("miniscan_node_conn°basiclo_primitive start connob %s" //
                "\n... routprepob %s depth %d expv %s fromob %s",       //
                objectdbg_BM (_.connob), objectdbg1_BM (_.routprepob), depth,   //
                debug_outstr_value_BM (_.expv, CURFRAME_BM, 0), //
                objectdbg2_BM (_.fromob));
  if (!_.routprepob)
    FAILHERE (NULL);
  if (!_.fromob)
    FAILHERE (NULL);
  {
    objlock_BM (_.connob);
    _.connargsv = objgetattr_BM (_.connob, k_arguments);
    _.connrestypob = objectcast_BM (objgetattr_BM (_.connob, k_result_type));
    objunlock_BM (_.connob);
  }
  DBGPRINTF_BM ("miniscan_node_conn°basiclo_primitive  connob %s"      //
                "\n... connargs %s connrestyp %s",      //
                objectdbg_BM (_.connob),        //
                debug_outstr_value_BM (_.connargsv, CURFRAME_BM, 0),    //
                objectdbg1_BM (_.connrestypob));        //
  if (!istuple_BM (_.connargsv))
    FAILHERE (makenode1_BM (k_arguments, _.connargsv));
  unsigned nbconnargs = tuplesize_BM (_.connargsv);
  unsigned nbexpargs = nodewidth_BM (_.expv);
  if (nbconnargs != nbexpargs)
    FAILHERE (k_arity);
  if (!isobject_BM (_.connrestypob))
    {
      WARNPRINTF_BM
        ("primitive connective %s with bad result_type for expression %s depth#%d from %s"
         " (miniscan_node_conn°basiclo_primitive)", objectdbg_BM (_.connob),
         OUTSTRVALUE_BM (_.expv), depth, objectdbg1_BM (_.fromob));
      FAILHERE (k_result_type);
    }
  for (unsigned ix = 0; ix < nbconnargs; ix++)
    {
      _.cursonv = nodenthson_BM (_.expv, ix);
      _.curargob = tuplecompnth_BM (_.connargsv, ix);
      _.curargctypob = NULL;
      _.curtypob = NULL;
      objlock_BM (_.curargob);
      _.curargctypob = objgetattr_BM (_.curargob, k_c_type);
      objunlock_BM (_.curargob);
      DBGPRINTF_BM ("miniscan_node_conn°basiclo_primitive ix#%d cursonv=%s curargob=%s", ix,   //
                    debug_outstr_value_BM (_.cursonv, CURFRAME_BM, 0),  //
                    objectdbg_BM (_.curargob));
      _.curtypob =
        miniscan_expr_BM (_.cursonv, _.routprepob, depth + 1, _.fromob,
                          CURFRAME_BM);
      DBGPRINTF_BM ("miniscan_node_conn°basiclo_primitive ix#%d "      //
                    " cursonv=%s" " curtypob %s curargob=%s curargctypob=%s",   //
                    ix, debug_outstr_value_BM (_.cursonv, CURFRAME_BM, 0),      //
                    objectdbg_BM (_.curtypob), objectdbg1_BM (_.curargob),      //
                    objectdbg2_BM (_.curargctypob));
      _.curcomptypob =
        miniscan_compatype_BM (_.curargctypob, _.curtypob, CURFRAME_BM);
      if (!_.curcomptypob)
        FAILHERE (makenode4_BM
                  (k_arguments, taggedint_BM (ix), _.cursonv, _.curargctypob,
                   _.curtypob));
    }
  DBGPRINTF_BM
    ("miniscan_node_conn°basiclo_primitive done expv=%s result connrestypob=%s",
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg_BM (_.connrestypob));
  LOCALRETURN_BM (_.connrestypob);
failure:
#undef FAILHERE
  DBGPRINTF_BM ("miniscan_node_conn°basiclo_primitive failin %d expv %s; extraerror %s", failin, debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),       //
                debug_outstr_value_BM (_.extraerrorv, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode5_BM (k_miniscan_node_conn, _.expv,
                               _.routprepob, taggedint_BM (depth),
                               _.fromob, _.extraerrorv);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniscan_node_conn°basiclo_primitive  _1vuSUudDrEr_9UjFr4Pcy8r */






////////////////////////////////////////////////////////////////
// miniscan_stmt°basiclo_return _7vlMCZ0yvva_6tx0lFlqBG8
extern objrout_sigBM ROUTINEOBJNAME_BM (_7vlMCZ0yvva_6tx0lFlqBG8);
value_tyBM
ROUTINEOBJNAME_BM (_7vlMCZ0yvva_6tx0lFlqBG8)    // miniscan_stmt°basiclo_return
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recv
 const value_tyBM arg2,         // routprep
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // containingblock
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_7vlMCZ0yvva_6tx0lFlqBG8,
                 objectval_tyBM * recv;
                 objectval_tyBM * routprepob; objectval_tyBM * fromblockob;
                 value_tyBM retexpv; objectval_tyBM * retypob;
                 value_tyBM resultv; value_tyBM errorv;);
  int failin = -1;
#define FAILHERE() do { failin = __LINE__ ; goto failure; } while(0)
  objectval_tyBM *k_return = BMK_2DH0ucElTgh_62vxjxLcfev;
  objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  int depth = 0;
  _.recv = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  depth = getint_BM (arg3);
  _.fromblockob = objectcast_BM (arg4);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_return start recv=%s routprepob=%s depth#%d fromblockob=%s start",
     objectdbg_BM (_.recv), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromblockob));
  objlock_BM (_.recv);
  _.retexpv = objgetattr_BM (_.recv, k_return);
  objunlock_BM (_.recv);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_return recv=%s retexpv=%s",
     objectdbg_BM (_.recv),
     debug_outstr_value_BM (_.retexpv, CURFRAME_BM, 0));
  _.retypob =
    miniscan_expr_BM (_.retexpv, _.routprepob, depth, _.recv, CURFRAME_BM);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_return recv=%s retypob=%s",
     objectdbg_BM (_.recv), objectdbg1_BM (_.retypob));
  // perhaps we could handle other cases, e.g. for something else than
  // basiclo_function-s.
  if (_.retypob != k_value && _.retypob != BMP_object)
    FAILHERE ();
  LOCALRETURN_BM (_.retypob);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("miniscan_stmt°basiclo_return failin %d", failin);
  _.errorv =
    (value_tyBM) makenode4_BM (k_return, _.retexpv, _.routprepob,
                               taggedint_BM (depth), _.recv);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end  miniscan_stmt°basiclo_return  _7vlMCZ0yvva_6tx0lFlqBG8 */


////////////////


// miniscan_stmt°basiclo_wrong _0Jvu8JxkNZZ_6K0zshkn9cP

extern objrout_sigBM ROUTINEOBJNAME_BM (_0Jvu8JxkNZZ_6K0zshkn9cP);
value_tyBM
ROUTINEOBJNAME_BM (_0Jvu8JxkNZZ_6K0zshkn9cP)    // miniscan_stmt°basiclo_wrong
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recvob
 const value_tyBM arg2,         // routprepob
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // fromob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  objectval_tyBM *k_origin = BMK_1xhcI0ZnQ6f_5xOLATXqawx;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_0Jvu8JxkNZZ_6K0zshkn9cP,
                 objectval_tyBM * recvob;       //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 value_tyBM resultv;    //
                 value_tyBM subexpv;    //
                 objectval_tyBM * subtypob;     //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
    );
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.recvob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  int depth = getint_BM (arg3);
  _.fromob = objectcast_BM (arg4);
  DBGPRINTF_BM ("miniscan_stmt°basiclo_wrong start recvob %s routprepob %s depth %d fromob %s", objectdbg1_BM (_.recvob), objectdbg2_BM (_.routprepob), depth, //
                objectdbg3_BM (_.fromob));
  if (!_.fromob)
    FAILHERE (k_origin);
  WEAKASSERT_BM (_.recvob);
  if (!_.routprepob)
    FAILHERE (NULL);
  WEAKASSERT_BM (_.routprepob);
  if (!_.routprepob)
    LOCALRETURN_BM (NULL);
  unsigned nbsons = objnbcomps_BM (_.recvob);
  for (unsigned ix = 0; ix < nbsons; ix++)
    {
      _.subexpv = objgetcomp_BM (_.recvob, ix);
      _.subtypob =
        miniscan_expr_BM (_.subexpv, _.routprepob, 0, _.recvob, CURFRAME_BM);
      if (!_.subtypob)
        FAILHERE (makenode2_BM (k_curcomp, _.subexpv, taggedint_BM (ix)));
    }
  DBGPRINTF_BM ("miniscan_stmt°basiclo_wrong end recvob %s",
                objectdbg_BM (_.recvob));
  LOCALRETURN_BM (_.recvob);
failure:
#undef FAILHERE
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_wrong failin %d recvob %s, routprepob %s, fromob %s, cause %s",
     failin, objectdbg_BM (_.recvob), objectdbg1_BM (_.routprepob),
     objectdbg2_BM (_.fromob), debug_outstr_value_BM (_.causev, CURFRAME_BM,
                                                      0));
  _.errorv =
    (value_tyBM) makenode4_BM (k_miniscan_stmt, _.recvob, _.routprepob,
                               _.fromob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniscan_stmt°basiclo_wrong _0Jvu8JxkNZZ_6K0zshkn9cP */



////////////////

//miniscan_stmt°basiclo_cexpansion  _0Qplg2cn9xR_5pfROAJjrXZ

extern objrout_sigBM ROUTINEOBJNAME_BM (_0Qplg2cn9xR_5pfROAJjrXZ);

value_tyBM
ROUTINEOBJNAME_BM (_0Qplg2cn9xR_5pfROAJjrXZ)    //miniscan_stmt°basiclo_cexpansion
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recvob
 const value_tyBM arg2,         // routprepob
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // fromob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_c_type = BMK_83kM1HtO8K3_6k0F2KYQT3W;
  objectval_tyBM *k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  //objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  objectval_tyBM *k_origin = BMK_1xhcI0ZnQ6f_5xOLATXqawx;
  //objectval_tyBM *k_basiclo_cexpansion = BMK_4GJJnvyrLyW_5mhopCYvh8h;
  objectval_tyBM *k_basiclo_cexpander = BMK_9pJUJ57N6RL_2nsXFzR6S3E;
  objectval_tyBM *k_results = BMK_5ve5gbSjN0r_1n61nNRPtnN;
  objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  //objectval_tyBM *k_body = BMK_7DQyvJFMOrC_9IfC3CtYknn;
  objectval_tyBM *k_expander = BMK_9OzBvYbDWm8_3XA4wkArOmo;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_0Qplg2cn9xR_5pfROAJjrXZ,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 value_tyBM resultv;    //
                 value_tyBM subexpv;    //
                 objectval_tyBM * subtypob;     //
                 objectval_tyBM * expandob;     //
                 objectval_tyBM * curesob;      //
                 objectval_tyBM * curestypob;   //
                 objectval_tyBM * curexptypob;  //
                 objectval_tyBM * curvarob;     //
                 objectval_tyBM * curvartypob;  //
                 objectval_tyBM * commontypob;  //
                 value_tyBM expresultsv;        //
                 value_tyBM stmtresultsv;       //
                 value_tyBM expargsv;   //
                 value_tyBM curargexpv; //
                 value_tyBM stmtargsv;  //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
    );
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.stmtob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  int depth = getint_BM (arg3);
  _.fromob = objectcast_BM (arg4);
  DBGPRINTF_BM ("miniscan_stmt°basiclo_cexpansion start stmtob %s routprepob %s depth %d fromob %s", objectdbg1_BM (_.stmtob), objectdbg2_BM (_.routprepob), depth,    //
                objectdbg3_BM (_.fromob));
  if (!_.fromob)
    FAILHERE (k_origin);
  WEAKASSERT_BM (_.stmtob);
  if (!_.routprepob)
    FAILHERE (NULL);
  _.expandob = objectcast_BM (objgetattr_BM (_.stmtob, k_expander));
  if (!_.expandob)
    FAILHERE (k_expander);
  DBGPRINTF_BM ("miniscan_stmt°basiclo_cexpansion stmtob %s expandob %s",
                objectdbg_BM (_.stmtob), objectdbg1_BM (_.expandob));
  objlock_BM (_.expandob);
  if (!objectisinstance_BM (_.expandob, k_basiclo_cexpander))
    FAILHERE (makenode1_BM (k_expander, _.expandob));
  _.expresultsv = objgetattr_BM (_.expandob, k_results);
  _.stmtresultsv = objgetattr_BM (_.stmtob, k_results);
  _.expargsv = objgetattr_BM (_.expandob, k_arguments);
  _.stmtargsv = objgetattr_BM (_.stmtob, k_arguments);
  DBGPRINTF_BM ("miniscan_stmt°basiclo_cexpansion stmtob %s\n" //
                ".. expresults %s stmtresults %s expargs %s stmtargs %s",       //
                objectdbg_BM (_.stmtob),        //
                debug_outstr_value_BM (_.expresultsv, CURFRAME_BM, 0),  //
                debug_outstr_value_BM (_.stmtresultsv, CURFRAME_BM, 0), //
                debug_outstr_value_BM (_.expargsv, CURFRAME_BM, 0),     //
                debug_outstr_value_BM (_.stmtargsv, CURFRAME_BM, 0));   //
  int nbstmtresults = tuplesize_BM (_.stmtresultsv);
  // match expresults with stmtresultsv
  {
    if (isobject_BM (_.expresultsv))
      {
        if (nbstmtresults != 1)
          FAILHERE (makenode2_BM (k_results, _.expresultsv, _.stmtresultsv));
        _.curesob = tuplecompnth_BM (_.stmtresultsv, 0);
        _.curvarob = objectcast_BM (_.expresultsv);
        objlock_BM (_.curvarob);
        _.curvartypob = objgetattr_BM (_.curvarob, k_c_type);
        objunlock_BM (_.curvarob);
        objlock_BM (_.curesob);
        _.curestypob =
          miniscan_var_BM (_.curesob, _.routprepob, depth + 1, _.stmtob,
                           CURFRAME_BM);
        objunlock_BM (_.curesob);
        if (miniscan_compatype_BM (_.curvartypob, _.curesob, CURFRAME_BM) !=
            _.curvartypob)
          FAILHERE (makenode3_BM
                    (k_results, _.expresultsv, _.stmtresultsv, _.curestypob));
      }
    else if (istuple_BM (_.expresultsv))
      {
        if (nbstmtresults != (int) tuplesize_BM (_.expresultsv))
          FAILHERE (makenode2_BM (k_results, _.expresultsv, _.stmtresultsv));
        for (int rix = 0; rix < nbstmtresults; rix++)
          {
            _.curesob = tuplecompnth_BM (_.stmtresultsv, rix);
            _.curvarob = tuplecompnth_BM (_.expresultsv, rix);
            objlock_BM (_.curvarob);
            _.curvartypob = objgetattr_BM (_.curvarob, k_c_type);
            objunlock_BM (_.curvarob);
            objlock_BM (_.curesob);
            _.curestypob =
              miniscan_var_BM (_.curesob, _.routprepob, depth + 1, _.stmtob,
                               CURFRAME_BM);
            objunlock_BM (_.curesob);
            _.commontypob =
              miniscan_compatype_BM (_.curvartypob, _.curestypob,
                                     CURFRAME_BM);
            if (_.commontypob != _.curvartypob)
              {
                DBGPRINTF_BM
                  ("miniscan_stmt°basiclo_cexpansion stmtob %s expandob %s\n"
                   "... result mismatch rix#%d curesob %s curvarob %s\n"
                   "... curvartypob %s curestypob %s commontypob %s",
                   objectdbg_BM (_.stmtob), objectdbg1_BM (_.expandob), rix,
                   objectdbg2_BM (_.curesob), objectdbg3_BM (_.curvarob),
                   objectdbg4_BM (_.curvartypob),
                   objectdbg5_BM (_.curestypob),
                   objectdbg6_BM (_.commontypob));
                FAILHERE (makenode4_BM
                          (k_results, _.expresultsv, _.stmtresultsv,
                           _.curestypob, taggedint_BM (rix)));
              }
          }
      }
    else if (_.expresultsv || _.stmtresultsv)
      FAILHERE (makenode2_BM (k_results, _.expresultsv, _.stmtresultsv));
    _.curvartypob = NULL;
    _.curestypob = NULL;
    _.curesob = NULL;
    _.curvarob = NULL;
  }
  // match expargsv with stmtargsv
  {
    int nbstmtargs = nodewidth_BM (_.stmtargsv);
    if (nbstmtargs != (int) tuplesize_BM (_.expargsv))
      FAILHERE (makenode2_BM (k_arguments, _.expresultsv, _.stmtresultsv));
    for (int aix = 0; aix < nbstmtargs; aix++)
      {
        _.curvarob = tuplecompnth_BM (_.expargsv, aix);
        _.curargexpv = nodenthson_BM (_.stmtargsv, aix);
        objlock_BM (_.curvarob);
        _.curvartypob = objgetattr_BM (_.curvarob, k_c_type);
        objunlock_BM (_.curvarob);
        _.curexptypob =
          miniscan_expr_BM (_.curargexpv, _.routprepob, depth + 1, _.stmtob,
                            CURFRAME_BM);
        _.commontypob =
          miniscan_compatype_BM (_.curvartypob, _.curexptypob, CURFRAME_BM);
        if (_.commontypob != _.curvartypob)
          {
            DBGPRINTF_BM
              ("miniscan_stmt°basiclo_cexpansion stmtob=%s argumfailure aix=%d curvarob=%s curargexpv=%s\n"
               "... curvartypob %s,  curexptypob %s, commontypob %s",
               objectdbg_BM (_.stmtob), aix, objectdbg1_BM (_.curvarob),
               debug_outstr_value_BM (_.curargexpv, CURFRAME_BM, 0),
               objectdbg2_BM (_.curvartypob), objectdbg3_BM (_.curexptypob),
               objectdbg4_BM (_.commontypob));
            FAILHERE (makenode6_BM
                      (k_arguments, _.expresultsv, _.stmtresultsv,
                       _.curexptypob, _.curargexpv, _.stmtob,
                       taggedint_BM (aix)));
          }
      }
    _.curvartypob = NULL;
    _.curexptypob = NULL;
    _.curesob = NULL;
    _.curvarob = NULL;
    _.curargexpv = NULL;
  }
  objunlock_BM (_.expandob);
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_cexpansion end stmtob=%s expandob=%s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.expandob));
  LOCALRETURN_BM (_.stmtob);
failure:
#undef FAILHERE
  DBGPRINTF_BM ("miniscan_stmt°basiclo_cexpansion failin %d stmtob %s, routprepob %s, fromob %s, cause %s", failin, objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob), objectdbg2_BM (_.fromob),   //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode4_BM (k_miniscan_stmt, _.stmtob, _.routprepob,
                               _.fromob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniscan_stmt°basiclo_cexpansion  _0Qplg2cn9xR_5pfROAJjrXZ */



////////////////


// miniscan_stmt°basiclo_fail _2oeeFe9Sdzx_8NaM3HUadSP

extern objrout_sigBM ROUTINEOBJNAME_BM (_2oeeFe9Sdzx_8NaM3HUadSP);

value_tyBM
ROUTINEOBJNAME_BM (_2oeeFe9Sdzx_8NaM3HUadSP)    // miniscan_stmt°basiclo_fail 
(struct stackframe_stBM * stkf, //
 const value_tyBM recvarg,      //
 const value_tyBM routpreparg,  //
 const value_tyBM deptharg,     //
 const value_tyBM fromarg,      //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_fail = BMK_085lT8c13Ik_11pcWJfcLeM;
  objectval_tyBM *k_origin = BMK_1xhcI0ZnQ6f_5xOLATXqawx;
  objectval_tyBM *k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  objectval_tyBM *k_modgenob = BMK_0Bl5ro9usp6_1Hll14QwC8f;
  objectval_tyBM *k_failure_set = BMK_9QCfVAnPhdt_5NVyy8KOaLP;
  objectval_tyBM *k_hset_object = BMK_8c9otZ4pwR6_55k81qyyYV2;
  objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_2oeeFe9Sdzx_8NaM3HUadSP,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * failtypob;    //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * failhsetob;   //
                 objectval_tyBM * consthsetob;  //
                 value_tyBM resultv;    //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
                 value_tyBM failexpv;   //
    );
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.stmtob = objectcast_BM (recvarg);
  _.routprepob = objectcast_BM (routpreparg);
  int depth = getint_BM (deptharg);
  _.fromob = objectcast_BM (fromarg);
  DBGPRINTF_BM ("miniscan_stmt°basiclo_fail start stmtob %s routprepob %s depth %d fromob %s", objectdbg1_BM (_.stmtob), objectdbg2_BM (_.routprepob), depth,  //
                objectdbg3_BM (_.fromob));
  if (!_.fromob)
    FAILHERE (k_origin);
  WEAKASSERT_BM (_.stmtob);
  if (!_.routprepob)
    FAILHERE (NULL);
  _.failexpv = objgetattr_BM (_.stmtob, k_fail);
  if (!_.failexpv)
    FAILHERE (k_fail);
  _.failtypob =
    miniscan_expr_BM (_.failexpv, _.routprepob, depth + 1, _.stmtob,
                      CURFRAME_BM);
  if (!miniscan_compatype_BM (_.failtypob, BMP_object, CURFRAME_BM))
    FAILHERE (makenode2_BM (k_fail, _.failexpv, _.failtypob));
  _.modgenob = objgetattr_BM (_.routprepob, k_modgenob);
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  DBGPRINTF_BM ("miniscan_stmt°basiclo_fail stmtob %s modgenob %s",
                objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob));
  _.failhsetob = objectcast_BM (objgetattr_BM (_.modgenob, k_failure_set));
  if (!_.failhsetob)
    {
      _.failhsetob = makeobj_BM ();
      objputclass_BM (_.failhsetob, k_hset_object);
      objputhashsetpayl_BM (_.failhsetob, 32);
      objtouchnow_BM (_.failhsetob);
      objputattr_BM (_.modgenob, k_failure_set, _.failhsetob);
      DBGPRINTF_BM
        ("miniscan_stmt°basiclo_fail stmtob %s modgenob %s made failhsetob %s",
         objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
         objectdbg2_BM (_.failhsetob));
    }
  else
    DBGPRINTF_BM
      ("miniscan_stmt°basiclo_fail stmtob %s modgenob %s got failhsetob %s containing %s",
       objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
       objectdbg2_BM (_.failhsetob),
       debug_outstr_value_BM ((value_tyBM)
                              objhashsettosetpayl_BM (_.failhsetob),
                              CURFRAME_BM, 0));
  _.consthsetob = objectcast_BM (objgetattr_BM (_.modgenob, k_constants));
  DBGPRINTF_BM
    ("miniscan_stmt°basiclo_fail stmtob %s modgenob %s  failhsetob %s consthsetob %s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.failhsetob), objectdbg3_BM (_.consthsetob));
  WEAKASSERT_BM (objhashashsetpayl_BM (_.failhsetob));
  WEAKASSERT_BM (objhashashsetpayl_BM (_.consthsetob));
  {
    objlock_BM (_.failhsetob);
    objhashsetaddpayl_BM (_.failhsetob, _.stmtob);
    objunlock_BM (_.failhsetob);
  }
  {
    objlock_BM (_.consthsetob);
    objhashsetaddpayl_BM (_.consthsetob, _.stmtob);
    objunlock_BM (_.consthsetob);
  }
  LOCALRETURN_BM (_.stmtob);
failure:
#undef FAILHERE
  DBGPRINTF_BM ("miniscan_stmt°basiclo_fail failin %d stmtob %s, routprepob %s, fromob %s, cause %s", failin, objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob), objectdbg2_BM (_.fromob), //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode4_BM (k_miniscan_stmt, _.stmtob, _.routprepob,
                               _.fromob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end  miniscan_stmt°basiclo_fail  _2oeeFe9Sdzx_8NaM3HUadSP */

////////////////////////////////////////////////////////////////










//miniscan_node_conn°basiclo_simple_connective _2ROGZRBpeCl_6HhgOZ5Uj7F

extern objrout_sigBM ROUTINEOBJNAME_BM (_2ROGZRBpeCl_6HhgOZ5Uj7F);
value_tyBM
ROUTINEOBJNAME_BM (_2ROGZRBpeCl_6HhgOZ5Uj7F)    //miniscan_node_conn°basiclo_simple_connective
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // connob
 const value_tyBM arg2,         // routprepob
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // expv
 const quasinode_tyBM * restargs /*fromob. */ )
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_2ROGZRBpeCl_6HhgOZ5Uj7F,
                 objectval_tyBM * connob;       //
                 objectval_tyBM * routprepob;   //
                 value_tyBM expv;       //
                 objectval_tyBM * fromob;       //
                 value_tyBM resultv;    //
                 value_tyBM funv;       //
                 value_tyBM errorv;     //
                 value_tyBM causev;     //
    );
  objectval_tyBM *k_miniscan_node_conn = BMK_5EGLdtUAQxA_1nebCsDKqOF;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.connob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  int depth = getint_BM (arg3);
  _.expv = arg4;
  _.fromob = objectcast_BM (treenthson_BM ((value_tyBM) restargs, 0));
  DBGPRINTF_BM ("miniscan_node_conn°basiclo_simple_connective start connob %s" //
                "\n... routprepob %s depth %d expv %s fromob %s",       //
                objectdbg_BM (_.connob), objectdbg1_BM (_.routprepob), depth,   //
                debug_outstr_value_BM (_.expv, CURFRAME_BM, 0), //
                objectdbg2_BM (_.fromob));
  if (!_.routprepob)
    FAILHERE (NULL);
  if (!_.fromob)
    FAILHERE (NULL);
  objlock_BM (_.connob);
  _.funv = objgetattr_BM (_.connob, k_miniscan_node_conn);
  objunlock_BM (_.connob);
  if (!_.funv)
    FAILHERE (k_miniscan_node_conn);
  DBGPRINTF_BM
    ("miniscan_node_conn°basiclo_simple_connective connob %s has funv %s routpepob %s",
     objectdbg_BM (_.connob), debug_outstr_value_BM (_.funv, CURFRAME_BM, 0),
     objectdbg1_BM (_.routprepob));
  if (!isobject_BM (_.funv) && !isclosure_BM (_.funv))
    FAILHERE (makenode1_BM (k_miniscan_node_conn, _.funv));
  _.resultv =
    apply5_BM (_.funv, CURFRAME_BM, _.connob, _.routprepob,
               taggedint_BM (depth), _.expv, _.fromob);
  DBGPRINTF_BM ("miniscan_node_conn°basiclo_simple_connective connob %s expv %s routprepob %s resultv %s",     //
                objectdbg_BM (_.connob), debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),        //
                objectdbg1_BM (_.routprepob),
                debug_outstr_value_BM (_.resultv, CURFRAME_BM, 0));
  if (!_.resultv)
    FAILHERE (_.funv);
  LOCALRETURN_BM (_.resultv);
failure:
#undef FAILHERE
  DBGPRINTF_BM ("failure miniscan_node_conn°basiclo_simple_connective failin %d\n"     //
                ".. connob %s expv %s routprepob %s causev %s", failin, objectdbg_BM (_.connob),        //
                debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
                objectdbg1_BM (_.routprepob), debug_outstr_value_BM (_.causev,
                                                                     CURFRAME_BM,
                                                                     0));
  _.errorv =
    (value_tyBM) makenode5_BM (k_miniscan_node_conn, _.expv, _.routprepob,
                               taggedint_BM (depth), _.fromob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniscan_node_conn°basiclo_simple_connective _2ROGZRBpeCl_6HhgOZ5Uj7F */














////////////////
// for the method to prepare_module in basiclo_temporary_module &
// basiclo_dumpable_module -- prepare_module°basiclo*module

extern objrout_sigBM ROUTINEOBJNAME_BM (_8zNBXSMY2Ts_1VI5dmY4umA);      // prepare_module°basiclo*module 
value_tyBM
ROUTINEOBJNAME_BM (_8zNBXSMY2Ts_1VI5dmY4umA)    // prepare_module°basiclo*module
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving module
 const value_tyBM arg2,         // module generator
 const value_tyBM arg3 __attribute__((unused)),
 const value_tyBM arg4 __attribute__((unused)),
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * modulob;      //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * funhsetob;    //
                 objectval_tyBM * consthsetob;
                 objectval_tyBM * prepvecob;    //
                 objectval_tyBM * curfunob;     //
                 objectval_tyBM * failhsetob;   //
                 value_tyBM curcomp;    //
                 seqobval_tyBM * curseq;        //
                 value_tyBM partres;    //
                 setval_tyBM * setfun;  //
                 setval_tyBM * setconst;        //
                 value_tyBM setfail;    //
                 value_tyBM errorv;
                 value_tyBM causev;);
  objectval_tyBM *k_failure_set = BMK_9QCfVAnPhdt_5NVyy8KOaLP;
  objectval_tyBM *k_hset_object = BMK_8c9otZ4pwR6_55k81qyyYV2;
  objectval_tyBM *k_functions_set = BMK_9stpgEfdDDE_7LUgqylTeFI;
  objectval_tyBM *k_basiclo_function = BMK_2Ir1i8qnrA4_3jSkierlc5z;
  objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  objectval_tyBM *k_prepare_routine = BMK_6qi1DW0Ygkl_4Aqdxq4n5IV;
  objectval_tyBM *k_prepared_routines = BMK_9qn0Hp8HaF5_7yeAJiNYtp5;
  if (!isobject_BM (arg1))
    LOCALRETURN_BM (NULL);
  _.modulob = (objectval_tyBM *) arg1;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM) (Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("@@prepare_module°basiclo*module _8zNBXSMY2Ts_1VI5dmY4umA"
     "  modulob=%s\n" "... is a %s\n", objectdbg_BM (_.modulob),
     objectdbg1_BM (objclass_BM (_.modulob)));
  if (!isobject_BM (arg2))
    LOCALRETURN_BM (NULL);
  _.modgenob = (objectval_tyBM *) arg2;
  DBGPRINTF_BM ("@@prepare_module°basiclo*module modgenob=%s\n"
                ".... is a %s\n", objectdbg_BM (_.modgenob),
                objectdbg1_BM (objclass_BM (_.modgenob)));
  objectval_tyBM *k_simple_module_generation = BMK_2HlKptD03wA_7JJCG7lN5nS;
  if (!objectisinstance_BM (_.modgenob, k_simple_module_generation))
    FAILHERE (makenode1_BM (k_simple_module_generation, _.modgenob));
  _.funhsetob = makeobj_BM ();
  objputclass_BM (_.funhsetob, k_hset_object);
  objputhashsetpayl_BM (_.funhsetob, objnbcomps_BM (_.modulob) + 1);
  _.consthsetob = makeobj_BM ();
  objputclass_BM (_.consthsetob, k_hset_object);
  objputhashsetpayl_BM (_.consthsetob, 5 * objnbcomps_BM (_.modulob) + 10);
  objhashsetaddpayl_BM (_.consthsetob, _.modulob);
  objputattr_BM (_.modgenob, k_functions_set, _.funhsetob);
  objputattr_BM (_.modgenob, k_constants, _.consthsetob);
  DBGPRINTF_BM
    ("@@prepare_module°basiclo*module modgenob=%s funhsetob=%s consthsetob=%s",
     objectdbg_BM (_.modgenob), objectdbg1_BM (_.funhsetob),
     objectdbg2_BM (_.consthsetob));
  for (unsigned ix = 0; ix < objnbcomps_BM (_.modulob); ix++)
    {
      DBGPRINTF_BM ("@@prepare_module°basiclo*module ix=%u", ix);
      _.curcomp = objgetcomp_BM (_.modulob, ix);
      if (isobject_BM (_.curcomp))
        {
          DBGPRINTF_BM
            ("@@prepare_module°basiclo*module object at ix=%u", ix);
          if (objectisinstance_BM (_.curcomp, k_basiclo_function))
            {
              objhashsetaddpayl_BM (_.funhsetob, _.curcomp);
              DBGPRINTF_BM
                ("@@prepare_module°basiclo*module adding curcomp %s",
                 objectdbg_BM ((objectval_tyBM *) _.curcomp));
            }
          else
            {
              DBGPRINTF_BM
                ("@@prepare_module°basiclo*module bad object curcomp %s",
                 objectdbg_BM ((objectval_tyBM *) _.curcomp));
              FAILHERE (makenode2_BM
                        (k_basiclo_function, _.curcomp, taggedint_BM (ix)));
            }
        }
      else if (issequence_BM (_.curcomp))
        {
          _.curseq = (seqobval_tyBM *) _.curcomp;
          unsigned sqlen = sequencesize_BM (_.curseq);
          DBGPRINTF_BM
            ("@@prepare_module°basiclo*module seqlen %u at ix=%u", sqlen,
             ix);
          for (unsigned j = 0; j < sqlen; j++)
            {
              _.curcomp = sequencenthcomp_BM (_.curseq, j);
              if (objectisinstance_BM (_.curcomp, k_basiclo_function))
                {
                  DBGPRINTF_BM
                    ("@@prepare_module°basiclo*module adding curcomp %s",
                     objectdbg_BM ((objectval_tyBM *) _.curcomp));
                  objhashsetaddpayl_BM (_.funhsetob, _.curcomp);
                }
              else
                {
                  DBGPRINTF_BM
                    ("@@prepare_module°basiclo*module bad seq curcomp %s",
                     objectdbg_BM ((objectval_tyBM *) _.curcomp));
                  FAILHERE (makenode3_BM
                            (k_basiclo_function, _.curcomp, taggedint_BM (ix),
                             taggedint_BM (j)));
                }
            }
          DBGPRINTF_BM
            ("@@prepare_module°basiclo*module done seqlen %u at ix=%u",
             sqlen, ix);
        }
      else if (isclosure_BM (_.curcomp))
        {
          DBGPRINTF_BM
            ("@@prepare_module°basiclo*module closure at ix=%u", ix);
          _.partres =
            apply2_BM ((closure_tyBM *) _.curcomp, CURFRAME_BM, _.modulob,
                       _.modgenob);
          if (isobject_BM (_.partres)
              && objectisinstance_BM (_.partres, k_basiclo_function))
            {
              DBGPRINTF_BM
                ("@@prepare_module°basiclo*module adding partres %s",
                 objectdbg_BM ((objectval_tyBM *) _.partres));
              objhashsetaddpayl_BM (_.funhsetob, _.partres);
            }
          else if (issequence_BM (_.partres))
            {
              _.curseq = (seqobval_tyBM *) _.partres;
              unsigned sqlen = sequencesize_BM (_.curseq);
              DBGPRINTF_BM
                ("@@prepare_module°basiclo*module ix=%u partres sqlen=%u",
                 ix, sqlen);
              for (unsigned j = 0; j < sqlen; j++)
                {
                  _.curcomp = sequencenthcomp_BM (_.curseq, j);
                  if (objectisinstance_BM (_.curcomp, k_basiclo_function))
                    {
                      DBGPRINTF_BM
                        ("@@prepare_module°basiclo*module adding curcomp %s",
                         objectdbg_BM ((objectval_tyBM *) _.curcomp));
                      objhashsetaddpayl_BM (_.funhsetob, _.curcomp);
                    }
                  else
                    {
                      DBGPRINTF_BM
                        ("@@prepare_module°basiclo*module ix=%u j=%u bad curcomp %s",
                         ix, j, objectdbg_BM ((objectval_tyBM *) _.curcomp));
                      FAILHERE (makenode3_BM
                                (k_basiclo_function, _.curcomp, _.partres,
                                 taggedint_BM (ix)));
                    }
                }
            }
          else
            {
              DBGPRINTF_BM
                ("@@prepare_module°basiclo*module ix=%u bad partres", ix);
              FAILHERE (makenode3_BM
                        (k_basiclo_function, _.curcomp, _.partres,
                         taggedint_BM (ix)));
            }
        }
      else
        {
          DBGPRINTF_BM
            ("@@prepare_module°basiclo*module ix=%u bad curcomp", ix);
          FAILHERE (makenode2_BM
                    (k_basiclo_function, _.curcomp, taggedint_BM (ix)));
        }
    }
  _.setfun = (setval_tyBM *) objhashsettosetpayl_BM (_.funhsetob);
  DBGPRINTF_BM ("@@prepare_module°basiclo*module funhsetob %s setfun %s modgenob %s", objectdbg_BM (_.funhsetob),      //
                debug_outstr_value_BM
                (_.setfun, CURFRAME_BM, 0), objectdbg1_BM (_.modgenob));
  objputattr_BM (_.modgenob, k_functions_set, _.setfun);
  int nbfunc = setcardinal_BM (_.setfun);
  _.prepvecob = makeobj_BM ();
  objputclass_BM (_.prepvecob, BMP_vector_object);
  objputdatavectpayl_BM (_.prepvecob, nbfunc + 1);
  objputattr_BM (_.prepvecob, BMP_in, _.modgenob);
  objputattr_BM (_.modgenob, k_prepared_routines, _.prepvecob);
  DBGPRINTF_BM
    ("@@prepare_module°basiclo*module modulob %s modgenob %s prepvecob %s",
     objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.prepvecob));
  for (int fix = 0; fix < nbfunc; fix++)
    {
      _.curfunob = setelemnth_BM (_.setfun, fix);
      DBGPRINTF_BM
        ("@@prepare_module°basiclo*module modulob %s modgenob %s fix#%d curfunob %s",
         objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob), fix,
         objectdbg2_BM (_.curfunob));
      _.partres =
        send2_BM (_.curfunob, k_prepare_routine, CURFRAME_BM,
                  _.modgenob, _.setfun);
      DBGPRINTF_BM
        ("@@prepare_module°basiclo*module modulob %s curfunob %s fix#%d prepare_routine gave %s",
         objectdbg_BM (_.modulob), objectdbg1_BM (_.curfunob), fix,
         debug_outstr_value_BM (_.partres, CURFRAME_BM, 0));
      if (isobject_BM (_.partres))
        {
          objdatavectappendpayl_BM (_.prepvecob, _.partres);
        }
      else
        {
          FAILHERE (makenode3_BM
                    (k_prepare_routine, _.curfunob, taggedint_BM (fix),
                     _.partres));
        }
    }
  _.partres = NULL;
  _.curseq = (value_tyBM) objdatavecttotuplepayl_BM (_.prepvecob);
  objputattr_BM (_.modgenob, k_prepared_routines, _.curseq);
  DBGPRINTF_BM ("@@prepare_module°basiclo*module modulob %s modgenob %s prepvecob %s prepared routines %s consthsetob %s",     //
                objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),   //
                objectdbg2_BM (_.prepvecob), debug_outstr_value_BM (_.curseq,
                                                                    CURFRAME_BM,
                                                                    0),
                objectdbg3_BM (_.consthsetob));
  _.setconst = (value_tyBM) objhashsettosetpayl_BM (_.consthsetob);
  DBGPRINTF_BM ("@@prepare_module°basiclo*module modulob %s modgenob %s setconst %s",  //
                objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),   //
                debug_outstr_value_BM (_.setconst, CURFRAME_BM, 0));
  _.failhsetob = objgetattr_BM (_.modgenob, k_failure_set);
  if (_.failhsetob)
    {
      DBGPRINTF_BM ("@@prepare_module°basiclo*module modulob %s modgenob %s failhsetob %s", objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),      //
                    objectdbg2_BM (_.failhsetob));
      WEAKASSERT_BM (isobject_BM (_.failhsetob));
      WEAKASSERT_BM (objhashashsetpayl_BM (_.failhsetob));
      _.setfail = (value_tyBM) objhashsettosetpayl_BM (_.failhsetob);
      objputattr_BM (_.modgenob, k_failure_set, _.setfail);
    };

  objputattr_BM (_.modgenob, k_constants, _.setconst);
  DBGPRINTF_BM
    ("@@prepare_module°basiclo*module done complete_module modulob=%s modgenob=%s",
     objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob));
  LOCALRETURN_BM (_.modgenob);
failure:

  DBGPRINTF_BM
    ("prepare_module°basiclo*module  failin %d cause %s", failin,
     debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode3_BM (BMP_emit_module, _.modulob,
                               _.modgenob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end  prepare_module°basiclo*module _8zNBXSMY2Ts_1VI5dmY4umA */




// miniscan_block°basiclo_block _2PbDEXpkK5W_7MSfDy2pWkH

extern objrout_sigBM ROUTINEOBJNAME_BM (_2PbDEXpkK5W_7MSfDy2pWkH);
value_tyBM
ROUTINEOBJNAME_BM (_2PbDEXpkK5W_7MSfDy2pWkH)    // miniscan_block°basiclo_block 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // blockob
 const value_tyBM arg2,         // routprepob
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // fromob
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_2PbDEXpkK5W_7MSfDy2pWkH,
                 objectval_tyBM * blockob;      //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * blockshsetob; //
                 objectval_tyBM * compob;       //
                 value_tyBM compv;      //
                 value_tyBM subresv;    //
                 value_tyBM resultv;    //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
    );
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  const objectval_tyBM *k_miniscan_block = BMK_2gthNYOWogO_4sVTU1JbmUH;
  const objectval_tyBM *k_miniscan_stmt = BMK_6DdZwyaWLyK_7tS2BmECOJ0;
  const objectval_tyBM *k_blocks = BMK_2lCuMosXupr_5GAoqVgJ8PZ;
  const objectval_tyBM *k_duplicate = BMK_2YrbiKQ6lxP_3KNUOnU6TF5;
  const objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  _.blockob = objectcast_BM (arg1);
  _.routprepob = objectcast_BM (arg2);
  int depth = getint_BM (arg3);
  _.fromob = objectcast_BM (arg4);
  WEAKASSERT_BM (_.blockob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (arg3));
  WEAKASSERT_BM (_.fromob);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM) (Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("miniscan_block°basiclo_block start blockob=%s of %s routprepob=%s depth=%d fromob=%s",
     objectdbg_BM (_.blockob),
     objectdbg1_BM (objclass_BM (_.blockob)),
     objectdbg2_BM (_.routprepob), depth, objectdbg3_BM (_.fromob));
  _.blockshsetob = objgetattr_BM (_.routprepob, k_blocks);
  DBGPRINTF_BM
    ("miniscan_block°basiclo_block blockob %s blockshsetob %s",
     objectdbg_BM (_.blockob), objectdbg1_BM (_.blockshsetob));
  WEAKASSERT_BM (objhashashsetpayl_BM (_.blockshsetob));
  bool duplicateblock = false;
  {
    objlock_BM (_.blockshsetob);
    duplicateblock = objhashsetcontainspayl_BM (_.blockshsetob, _.blockob);
    objhashsetaddpayl_BM (_.blockshsetob, _.blockob);
    objunlock_BM (_.blockshsetob);
  }
  if (duplicateblock)
    FAILHERE (k_duplicate);
  int nbcomp = objnbcomps_BM (_.blockob);
  for (int ix = 0; ix < nbcomp; ix++)
    {
      _.compv = objgetcomp_BM (_.blockob, ix);
      if (!_.compv)
        continue;
      _.compob = objectcast_BM (_.compv);
      if (!_.compob)
        FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (ix), _.compv));
      objlock_BM (_.compob);
      if (objectisinstance_BM (_.compob, k_basiclo_block))
        {
          DBGPRINTF_BM
            ("miniscan_block°basiclo_block blockob %s ix#%d compob %s is block of %s",
             objectdbg_BM (_.blockob), ix, objectdbg1_BM (_.compob),
             objectdbg2_BM (objclass_BM (_.compob)));
          _.subresv =
            send3_BM (_.compob, k_miniscan_block,
                      CURFRAME_BM, _.routprepob,
                      taggedint_BM (depth + 1), _.blockob);
          DBGPRINTF_BM
            ("miniscan_block°basiclo_block blockob %s ix#%d compob %s miniscan_block gave %s",
             objectdbg_BM (_.blockob), ix, objectdbg1_BM (_.compob),
             debug_outstr_value_BM (_.subresv, CURFRAME_BM, 0));
          if (!_.subresv)
            FAILHERE (makenode3_BM
                      (k_miniscan_block, _.compob, taggedint_BM (ix),
                       _.blockob));
        }
      else if (objectisinstance_BM (_.compob, k_basiclo_statement))
        {
          DBGPRINTF_BM
            ("miniscan_block°basiclo_block blockob %s ix#%d compob %s is statement of %s",
             objectdbg_BM (_.blockob), ix, objectdbg1_BM (_.compob),
             objectdbg2_BM (objclass_BM (_.compob)));
          _.subresv =
            send3_BM (_.compob, k_miniscan_stmt,
                      CURFRAME_BM, _.routprepob,
                      taggedint_BM (depth + 1), _.blockob);
          DBGPRINTF_BM
            ("miniscan_block°basiclo_block blockob %s ix#%d compob %s miniscan_stmt gave %s",
             objectdbg_BM (_.blockob), ix, objectdbg1_BM (_.compob),
             debug_outstr_value_BM (_.subresv, CURFRAME_BM, 0));
          if (!_.subresv)
            FAILHERE (makenode3_BM
                      (k_miniscan_stmt, _.compob, taggedint_BM (ix),
                       _.blockob));
        }
      else
        {
          DBGPRINTF_BM
            ("miniscan_block°basiclo_block blockob %s ix#%d compob %s bad of %s",
             objectdbg_BM (_.blockob), ix, objectdbg1_BM (_.compob),
             objectdbg2_BM (objclass_BM (_.compob)));
          FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (ix), _.compob));
        }
      objunlock_BM (_.compob);
    }
  DBGPRINTF_BM
    ("miniscan_block°basiclo_block end blockob=%s routprepob=%s depth=%d fromob=%s",
     objectdbg_BM (_.blockob), objectdbg1_BM (_.routprepob), depth,
     objectdbg2_BM (_.fromob));
  LOCALRETURN_BM (_.blockob);
failure:
  DBGPRINTF_BM ("miniscan_block°basiclo_block  failin %d blockob %s cause %s", failin, objectdbg_BM (_.blockob),       //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode5_BM (k_miniscan_block, _.blockob,
                               _.routprepob, taggedint_BM (depth),
                               _.fromob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end miniscan_block°basiclo_block _2PbDEXpkK5W_7MSfDy2pWkH */






// for the method to generate_module in basiclo_temporary_module &
// basiclo_dumpable_module/ generate_module°basiclo*module

extern objrout_sigBM ROUTINEOBJNAME_BM (_50d65bJypCN_6IJeVtssx9I);      // generate_module°basiclo*module
value_tyBM
ROUTINEOBJNAME_BM (_50d65bJypCN_6IJeVtssx9I)    // generate_module°basiclo*module
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving module
 const value_tyBM arg2,         // module generator
 const value_tyBM arg3,         // preparation
 const value_tyBM arg4 __attribute__((unused)), //
 const quasinode_tyBM * restargs __attribute__((unused)))
{
  //objectval_tyBM *k_prepare_routine = BMK_6qi1DW0Ygkl_4Aqdxq4n5IV;
  objectval_tyBM * k_failure_set = BMK_9QCfVAnPhdt_5NVyy8KOaLP;
  objectval_tyBM *k_prepared_routines = BMK_9qn0Hp8HaF5_7yeAJiNYtp5;
  //objectval_tyBM *k_vector_object = BMK_0Ie11LN3K5q_0mcL2jRBwgk;
  objectval_tyBM *k_emit_declaration = BMK_3NGaoN3yhbn_8yUwbtZfvp9;
  objectval_tyBM *k_emit_definition = BMK_1g8s9B96Irf_6Ix2Cyy8Hq0;
  objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  objectval_tyBM *k_functions_set = BMK_9stpgEfdDDE_7LUgqylTeFI;
  objectval_tyBM *k_generate_module = BMK_9mq0jsuz4XQ_4doHfd987Q6;
  objectval_tyBM *k_modgenob = BMK_0Bl5ro9usp6_1Hll14QwC8f;
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 objectval_tyBM * modulob;      //
                 objectval_tyBM * curfunob;     //
                 objectval_tyBM * curoutprepob; //
                 objectval_tyBM * curconstob;   //
                 objectval_tyBM * modgenob;     //
                 value_tyBM prepval;    //
                 value_tyBM preproutval;        //
                 objectval_tyBM * vectprepob;   //
                 value_tyBM preptupv;   //
                 value_tyBM prepmod;    //
                 value_tyBM emitv;      //
                 value_tyBM constsetv;  //
                 value_tyBM commentv;   //
                 value_tyBM routsetv;   //
                 value_tyBM failsetv;   //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
    );
  _.modulob = arg1;
  ASSERT_BM (isobject_BM (_.modulob));
  char modulidbuf[32];
  memset (modulidbuf, 0, sizeof (modulidbuf));
  idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
  _.modgenob = objectcast_BM (arg2);
  _.prepval = arg3;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("@@generate_module°basiclo*module start modulob=%s /%s\n"
     "... is a %s, modgenob %s, prepval %s\n\n",
     objectdbg_BM (_.modulob), modulidbuf,
     objectdbg1_BM (objclass_BM (_.modulob)),
     objectdbg2_BM (_.modgenob), debug_outstr_value_BM (_.prepval,
                                                        CURFRAME_BM, 0));
  if (!_.modgenob)
    {
      DBGPRINTF_BM ("@@generate_module°basiclo*module bad modgenob");
      FAILHERE (k_modgenob);
    };
  _.constsetv = objgetattr_BM (_.modgenob, k_constants);
  DBGPRINTF_BM ("@@generate_module°basiclo*module modgenob=%s is a %s prepval=%s constsetv=%s\n",      //
                objectdbg_BM (_.modgenob), objectdbg1_BM (objclass_BM (_.modgenob)),    //
                debug_outstr_value_BM ((value_tyBM) _.prepval, CURFRAME_BM, 1), //
                debug_outstr_value_BM
                ((value_tyBM) _.constsetv, CURFRAME_BM, 1));
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.modgenob));
  WEAKASSERT_BM (!_.constsetv || isset_BM (_.constsetv));
  objstrbufferprintfpayl_BM (_.modgenob, "\n\n" "#include \"bismon.h\"\n\n");
  objstrbufferprintfpayl_BM (_.modgenob,
                             "#ifdef BISMON_MODID\n"
                             "DECLARE_MODULE_BM(%s);\n"
                             "extern moduleinit_sigBM " MODULEINITPREFIX_BM
                             "%s" MODULEINITSUFFIX_BM ";\n"
                             "#endif /*BISMON_MODID*/\n\n", modulidbuf,
                             modulidbuf);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "#ifdef BISMON_MOMD5\n"
                             "const char " MODULEMD5CHECKSUMPREFIX_BM "%s"
                             MODULEMD5CHECKSUMSUFFIX_BM "[] = BISMON_MOMD5;\n"
                             "#endif /*BISMON_MOMD5*/\n\n", modulidbuf);
  DBGPRINTF_BM
    ("@@generate_module°basiclo*module incomplete modgenob=%s prepmod=%s",
     objectdbg_BM (_.modgenob), debug_outstr_value_BM (_.prepmod, CURFRAME_BM,
                                                       0));
  _.routsetv = objgetattr_BM (_.modgenob, k_functions_set);
  _.preptupv = objgetattr_BM (_.modgenob, k_prepared_routines);
  _.failsetv = objgetattr_BM (_.modgenob, k_failure_set);
  unsigned nbrout = setcardinal_BM (_.routsetv);
  WEAKASSERT_BM (isset_BM (_.routsetv));
  WEAKASSERT_BM (istuple_BM (_.preptupv));
  WEAKASSERT_BM (nbrout == tuplesize_BM (_.preptupv));
  //////
  // we should now declare the routines
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n\n// declare %u routines\n\n", nbrout);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "extern const char *const "
                             ROUTIDARRPREFIX_BM "%s"
                             ROUTINESUFFIX_BM "[%d+1];\n",
                             modulidbuf, nbrout);
  _.preproutval = NULL;
  unsigned nbfail = setcardinal_BM (_.failsetv);
  if (nbfail == 0)
    objstrbufferprintfpayl_BM (_.modgenob, "\n\n// no failure\n");
  else
    {
      objstrbufferprintfpayl_BM (_.modgenob, "\n\n// %u failures\n", nbfail);
    };
  // we should now emit each routine's declaration...
  for (unsigned routix = 0; routix < nbrout; routix++)
    {
      _.curfunob = setelemnth_BM (_.routsetv, routix);
      _.curoutprepob = tuplecompnth_BM (_.preptupv, routix);
      _.emitv = NULL;
      DBGPRINTF_BM
        ("@@generate_module°basiclo*module declaring routix#%d before emit_declaration"
         "\n ... curfunob %s curoutprepob %s modgenob %s",
         routix, objectdbg_BM (_.curfunob),
         objectdbg1_BM (_.curoutprepob), objectdbg2_BM (_.modgenob));
      WEAKASSERT_BM (isobject_BM (_.curfunob));
      WEAKASSERT_BM (isobject_BM (_.curoutprepob));
      _.emitv =
        send2_BM (_.curoutprepob, k_emit_declaration, CURFRAME_BM,
                  _.modgenob, taggedint_BM (routix));
      DBGPRINTF_BM
        ("@@generate_module°basiclo*module declared routix#%d curoutprepob %s curfunob %s emitv %s",
         routix, objectdbg_BM (_.curoutprepob),
         objectdbg1_BM (_.curfunob), debug_outstr_value_BM (_.emitv,
                                                            CURFRAME_BM, 0));
      if (!_.emitv)
        {
          DBGPRINTF_BM
            ("@@generate_module°basiclo*module emit_declaration of %s for %s failed",
             objectdbg_BM (_.curoutprepob), objectdbg1_BM (_.curfunob));
          FAILHERE (makenode3_BM
                    (k_emit_declaration, _.curoutprepob, _.curfunob,
                     taggedint_BM (routix)));
        }
    }
  //// we should now emit the declarations of constants and of their ids
  unsigned nbconst = setcardinal_BM (_.constsetv);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n\n// declare %u constants\n", nbconst);
  if (nbconst > 0)
    {
      objstrbufferprintfpayl_BM (_.modgenob, "objectval_tyBM* "
                                 CONSTOBARRPREFIX_BM
                                 "%s" ROUTINESUFFIX_BM
                                 "[%d+1];\n", modulidbuf, nbconst);
      objstrbufferprintfpayl_BM (_.modgenob, "const char* const "
                                 CONSTIDARRPREFIX_BM
                                 "%s" ROUTINESUFFIX_BM
                                 "[%d+1];\n", modulidbuf, nbconst);
    }
  //////
  // we should now define the routines
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n\n// define %u routines\n", nbrout);
  _.preproutval = NULL;
  // we should now emit each routine's definition...
  for (unsigned routix = 0; routix < nbrout; routix++)
    {
      _.curfunob = setelemnth_BM (_.routsetv, routix);
      _.curoutprepob = tuplecompnth_BM (_.preptupv, routix);
      _.emitv = NULL;
      DBGPRINTF_BM
        ("@@generate_module°basiclo*module defining routix#%d curoutprepob %s curfunob %s",
         routix, objectdbg_BM (_.curoutprepob), objectdbg1_BM (_.curfunob));
      WEAKASSERT_BM (isobject_BM (_.curoutprepob));
      _.emitv =
        send2_BM (_.curoutprepob, k_emit_definition, CURFRAME_BM,
                  _.modgenob, taggedint_BM (routix));
      DBGPRINTF_BM
        ("@@generate_module°basiclo*module defined routix#%d curoutprepob %s curfunob %s emitv %s",
         routix, objectdbg_BM (_.curoutprepob),
         objectdbg1_BM (_.curfunob), debug_outstr_value_BM (_.emitv,
                                                            CURFRAME_BM, 0));
      if (!_.emitv)
        {
          DBGPRINTF_BM
            ("@@generate_module°basiclo*module emit_declaration of %s for %s failed routix#%d",
             objectdbg_BM (_.curoutprepob), objectdbg1_BM (_.curfunob),
             routix);
          FAILHERE (makenode3_BM
                    (k_emit_definition, _.curoutprepob, _.curfunob,
                     taggedint_BM (routix)));
        }
    }
  // ending comment of routines
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n\n// end of %u generated routines\n\n",
                             nbrout);
  // constant ids
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n// the constant ids for %d constants:\n",
                             nbconst);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "const char* const "
                             CONSTIDARRPREFIX_BM "%s"
                             ROUTINESUFFIX_BM "[%d+1] = {",
                             modulidbuf, nbconst);
  for (int kix = 0; kix < (int) nbconst; kix++)
    {
      _.commentv = NULL;
      if (kix % 5 == 0)
        objstrbufferprintfpayl_BM (_.modgenob, "\n /*%d:*/", kix);
      _.curconstob = setelemnth_BM (_.constsetv, kix);
      objlock_BM (_.curconstob);
      _.commentv = objgetattr_BM (_.curconstob, BMP_comment);
      objunlock_BM (_.curconstob);
      const char *curconstname = findobjectname_BM (_.curconstob);
      char constidbuf[32];
      memset (constidbuf, 0, sizeof (constidbuf));
      idtocbuf32_BM (objid_BM (_.curconstob), constidbuf);
      if (curconstname)
        objstrbufferprintfpayl_BM (_.modgenob, "\n \"%s\",//%s",
                                   constidbuf, curconstname);
      else if (isstring_BM (_.commentv))
        {
          const char *comstr = bytstring_BM (_.commentv);
          const char *nl = strchr (comstr, '\n');
          int comlen = lenstring_BM (_.commentv);
          if (nl)
            comlen = nl - comstr - 1;
          if (comlen > 2)
            objstrbufferprintfpayl_BM (_.modgenob, "\n \"%s\", //! %.*s",
                                       constidbuf, comlen, comstr);
          else
            objstrbufferprintfpayl_BM (_.modgenob, "\n \"%s\",", constidbuf);
        }
      else
        objstrbufferprintfpayl_BM (_.modgenob, "\n \"%s\",", constidbuf);
    }
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n NULL}; // end %d constant ids\n\n", nbconst);
  _.curconstob = NULL;
  _.commentv = NULL;
  // routine ids
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n\n// the routine ids for %d routines:\n",
                             nbrout);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "const char* const "
                             ROUTIDARRPREFIX_BM "%s"
                             ROUTINESUFFIX_BM "[%d+1] = {\n",
                             modulidbuf, nbrout);
  for (unsigned routix = 0; routix < nbrout; routix++)
    {
      _.curfunob = setelemnth_BM (_.routsetv, routix);
      if (routix % 8 == 0)
        objstrbufferprintfpayl_BM (_.modgenob, "  /*%d:*/\n", routix);
      _.commentv = objgetattr_BM (_.curfunob, BMP_comment);
      const char *curfunname = findobjectname_BM (_.curfunob);
      char funidbuf[32];
      memset (funidbuf, 0, sizeof (funidbuf));
      idtocbuf32_BM (objid_BM (_.curfunob), funidbuf);
      if (curfunname)
        objstrbufferprintfpayl_BM (_.modgenob, "  \"%s\",//%s\n",
                                   funidbuf, curfunname);
      else if (isstring_BM (_.commentv))
        {
          const char *comby = bytstring_BM (_.commentv);
          int comlen = lenstring_BM (_.commentv);
          const char *eol = strchr (comby, '\n');
          if (eol)
            comlen = eol - comby;
          if (comlen > 1)
            objstrbufferprintfpayl_BM (_.modgenob, "  \"%s\", //!%.*s\n",
                                       funidbuf, comlen, comby);
          else
            objstrbufferprintfpayl_BM (_.modgenob, "  \"%s\",\n", funidbuf);
        }
      else
        objstrbufferprintfpayl_BM (_.modgenob, "  \"%s\",\n", funidbuf);
    }
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n NULL}; // end %d routine ids\n\n", nbrout);
  /// emit the module initialization
  objstrbufferprintfpayl_BM (_.modgenob, "\n\n// basiclo*module initialization\n"       //
                             "#ifdef BISMON_MODID\n" "value_tyBM "
                             MODULEINITPREFIX_BM "%s" MODULEINITSUFFIX_BM "\n"
                             "  (struct stackframe_stBM *stkf, //\n"
                             "   const value_tyBM arg1, //\n"
                             "   const value_tyBM arg2, //\n"
                             "   const value_tyBM arg3, //\n"
                             "   void* dlh) {\n", modulidbuf);
  objstrbufferprintfpayl_BM (_.modgenob, "  return simple_module_initialize_BM(arg1, arg2, arg3, //\n"  //
                             "        \"%s\",//\n", modulidbuf);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "       " CONSTOBARRPREFIX_BM "%s"
                             ROUTINESUFFIX_BM ", //\n", modulidbuf);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "       " CONSTIDARRPREFIX_BM "%s"
                             ROUTINESUFFIX_BM ", //\n", modulidbuf);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "       " ROUTIDARRPREFIX_BM "%s"
                             ROUTINESUFFIX_BM ", //\n", modulidbuf);
  objstrbufferprintfpayl_BM (_.modgenob, "       dlh, stkf);\n");
  objstrbufferprintfpayl_BM (_.modgenob,
                             "} // end " MODULEINITPREFIX_BM "%s"
                             MODULEINITSUFFIX_BM "\n"
                             "#endif /*BISMON_MODID*/\n\n", modulidbuf);
  DBGPRINTF_BM
    ("@@generate_module°basiclo*module end modulob %s modgenob %s",
     objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob));
  LOCALRETURN_BM (_.modgenob);
failure:
#undef FAILHERE
  DBGPRINTF_BM
    ("@@generate_module°basiclo*module failure failin %d  modulob %s modgenob %s cause %s",
     failin, objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),
     debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode4_BM (k_generate_module, _.modulob, _.modgenob,
                               _.prepval, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end generate_module°basiclo*module  _50d65bJypCN_6IJeVtssx9I */



// defer-compilation-of-module  _9EqBenFWb40_86MuuXslynk
extern objrout_sigBM ROUTINEOBJNAME_BM (_9EqBenFWb40_86MuuXslynk);
value_tyBM
ROUTINEOBJNAME_BM (_9EqBenFWb40_86MuuXslynk)    // defer-compilation-of-module 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // modulob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // srcdirstrv
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * kk_after_compilation_of_module =
    BMK_9le67LL7S9y_5VGpniEUNDA;
  objectval_tyBM *k_plain_temporary_module = BMK_1oEp0eAAyFN_4lsobepyr1T;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_9EqBenFWb40_86MuuXslynk,
                 value_tyBM resultv;
                 objectval_tyBM * modulob; objectval_tyBM * modgenob;
                 value_tyBM srcdirstrv; value_tyBM pardirstrv;
                 value_tyBM compilnodv; value_tyBM aftercompilclosv;
                 value_tyBM argstrarr[8];);
  _.modulob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  char modulidbuf[32];
  memset (modulidbuf, 0, sizeof (modulidbuf));
  idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
  _.srcdirstrv = arg3;
  bool modulistemporary =
    (objectisinstance_BM (_.modulob, k_plain_temporary_module));
  {
    char cwdbuf[80];
    DBGPRINTF_BM
      ("defer-compilation-of-module start %s modulob %s /%s modgenob %s srcdirstrv %s in %s",
       modulistemporary ? "temporary" : "persistent",
       objectdbg_BM (_.modulob), modulidbuf, objectdbg1_BM (_.modgenob),
       debug_outstr_value_BM (_.srcdirstrv, CURFRAME_BM, 0),
       getcwd (cwdbuf, sizeof (cwdbuf)) ? : "??");
  }
  WEAKASSERT_BM (_.modulob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (isstring_BM (_.srcdirstrv));
  WEAKASSERT_BM (pthread_self () == mainthreadid_BM);
  log_begin_message_BM ();
  log_printf_message_BM ("should compile %s module ",
                         modulistemporary ? "temporary" : "persistent");
  log_object_message_BM (_.modulob);
  log_puts_message_BM (" for generation ");
  log_object_message_BM (_.modgenob);
  log_printf_message_BM (" in source directory: %s.",
                         bytstring_BM (_.srcdirstrv));
  log_end_message_BM ();
  char cwdpath[128];
  memset (cwdpath, 0, sizeof (cwdpath));
  if (!getcwd (cwdpath, sizeof (cwdpath)))
    FATAL_BM("failed to getcwd in defer-compilation-of-modgenob for source dir %s",
	     bytstring_BM (_.srcdirstrv));
  DBGPRINTF_BM
    ("defer-compilation-of-modgenob modulob %s srcdir %s cwdpath %s",
     objectdbg_BM (_.modulob), bytstring_BM (_.srcdirstrv), cwdpath);
  char *realsrcdir = realpath (bytstring_BM (_.srcdirstrv), NULL);
  if (!realsrcdir)
    FATAL_BM
      ("failed to get realsrcdir from %s in defer-compilation-of-module modulob %s modgenob %s",
       bytstring_BM (_.srcdirstrv), objectdbg_BM (_.modulob),
       objectdbg1_BM (_.modgenob));
  char *realpardir = NULL;
  {
    char *lastslash = strrchr (realsrcdir, '/');
    if (lastslash)
      {
        *lastslash = (char) 0;
        realpardir = strdup (realsrcdir);
        *lastslash = '/';
      }
  }
  DBGPRINTF_BM ("defer-compilation-of-module modulob %s realpardir %s",
                objectdbg_BM (_.modulob), realpardir);
  {
    char *modubindir = NULL;
    if (asprintf (&modubindir, "%s/modubin", realpardir) < 0 || !modubindir)
      FATAL_BM
        ("defer-compilation-of-modgenob failed to asprintf the modubin directory from %s",
         realpardir);
    if (g_mkdir_with_parents (modubindir, 0750))
      FATAL_BM ("failed to mkdir with parents modbin directory %s",
                modubindir);
    DBGPRINTF_BM ("defer-compilation-of-module modubindir %s", modubindir);
    free (modubindir), modubindir = NULL;
  }
  // check that the full source path exists
  {
    char *fullsrcpath = NULL;
    asprintf (&fullsrcpath, "%s/%s%s.c",
              realsrcdir,
              modulistemporary ? TEMPMODULEPREFIX_BM : MODULEPREFIX_BM,
              modulidbuf);
    if (!fullsrcpath)
      FATAL_BM ("asprintf fullsrcpath failure");
    DBGPRINTF_BM ("defer-compilation-of-module fullsrcpath %s", fullsrcpath);
    if (access (fullsrcpath, R_OK))
      FATAL_BM
        ("defer-compilation-of-module cannot access full source path %s - %m",
         fullsrcpath);
    free (fullsrcpath), fullsrcpath = NULL;
  }
  DBGPRINTF_BM
    ("defer-compilation-of-module realsrcdir %s realpardir %s bismondir %s cwdpath %s",
     realsrcdir, realpardir, bismon_directory, cwdpath);
  if (!realpardir)
    FATAL_BM
      ("failed to compute real parent directory in defer-compilation-of-module"
       " modulob %s modgenob %s for realsrcdir %s",
       objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob), realsrcdir);
  char *compilargs[8] = {
  };
  char buildscriptbuf[128];
  memset (buildscriptbuf, 0, sizeof (buildscriptbuf));
  if (modulistemporary)
    snprintf (buildscriptbuf, sizeof (buildscriptbuf),
              "%s/build-bismon-temporary-module.sh", bismon_directory);
  else
    snprintf (buildscriptbuf, sizeof (buildscriptbuf),
              "%s/build-bismon-persistent-module.sh", bismon_directory);
  compilargs[0] = buildscriptbuf;
  compilargs[1] = modulidbuf;
  int nbargs = 2;
  DBGPRINTF_BM ("defer-compilation-of-module nbargs=%d", nbargs);
  for (int ix = 0; ix < nbargs; ix++)
    DBGPRINTF_BM ("..[%d]: %s", ix, compilargs[ix]);
  memset (_.argstrarr, 0, sizeof (_.argstrarr));
  for (int ix = 0; ix < nbargs; ix++)
    _.argstrarr[ix] = (value_tyBM) makestring_BM (compilargs[ix]);
  _.compilnodv = (value_tyBM) makenode_BM (BMP_node, nbargs, _.argstrarr);
  _.pardirstrv = (value_tyBM) makestring_BM (realpardir);
  _.aftercompilclosv =
    (value_tyBM) makeclosure3_BM (kk_after_compilation_of_module, _.modulob,
                                  _.modgenob, _.pardirstrv);
  char cwdbuf[80];
  DBGPRINTF_BM
    ("defer-compilation-of-module pardirstrv=%s compilnodv=%s aftercompilclosv=%s before queue_process_BM in dir %s",
     debug_outstr_value_BM (_.pardirstrv, CURFRAME_BM, 0),
     debug_outstr_value_BM (_.compilnodv, CURFRAME_BM, 0),
     debug_outstr_value_BM (_.aftercompilclosv, CURFRAME_BM, 0),
     getcwd (cwdbuf, sizeof (cwdbuf)) ? : "!!");
  queue_process_BM (_.pardirstrv, _.compilnodv, _.aftercompilclosv,
                    CURFRAME_BM);
  LOCALRETURN_BM (_.aftercompilclosv);
}                               /* end  defer-compilation-of-module _9EqBenFWb40_86MuuXslynk */




// after-compilation-of-module _9le67LL7S9y_5VGpniEUNDA, closure called by process ending

extern objrout_sigBM ROUTINEOBJNAME_BM (_9le67LL7S9y_5VGpniEUNDA);
value_tyBM
ROUTINEOBJNAME_BM (_9le67LL7S9y_5VGpniEUNDA)    // after-compilation-of-module, process ending
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // outstr
 const value_tyBM arg2,         // status
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * kk_after_compilation_of_module =
    BMK_9le67LL7S9y_5VGpniEUNDA;
  objectval_tyBM *kk_after_load_of_module = BMK_0UHZG9vDlR2_2Aqx86LMFuq;
  objectval_tyBM *k_plain_temporary_module = BMK_1oEp0eAAyFN_4lsobepyr1T;
  LOCALFRAME_BM (stkf, /*descr: */ kk_after_compilation_of_module,
                 value_tyBM outstrv;    //
                 value_tyBM resultv;    //
                 value_tyBM callingclosv;       //
                 objectval_tyBM * modulob;      //
                 value_tyBM postclosv;  //
                 objectval_tyBM * modgenob;
                 value_tyBM moddirstrv;);
  int status = -1;
  _.outstrv = arg1;
  status = getint_BM (arg2);
  LOCALGETFUNV_BM (_.callingclosv);
  _.modulob = objectcast_BM (closurenthson_BM (_.callingclosv, 0));
  _.modgenob = objectcast_BM (closurenthson_BM (_.callingclosv, 1));
  _.moddirstrv = closurenthson_BM (_.callingclosv, 2);
  bool modulistemporary =
    (objectisinstance_BM (_.modulob, k_plain_temporary_module));
  DBGBACKTRACEPRINTF_BM ("start after-compilation-of-module %s status %d outstr %s callingclos %s\n"    //
                         ".. modulob=%s %s modgenob=%s moddirstr=%s\n", //
                         objectdbg_BM (kk_after_compilation_of_module), status, //
                         OUTSTRVALUE_BM (_.outstrv),    //
                         OUTSTRVALUE_BM (_.callingclosv),       //
                         objectdbg1_BM (_.modulob),     //
                         modulistemporary ? "temporary" : "persistent", //
                         objectdbg2_BM (_.modgenob),    //
                         OUTSTRVALUE_BM (_.moddirstrv));
  WEAKASSERT_BM (_.modulob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (isstring_BM (_.moddirstrv));
  char modulidbuf[32];
  memset (modulidbuf, 0, sizeof (modulidbuf));
  idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
  WEAKASSERT_BM (isclosure_BM (_.callingclosv)
                 && closurewidth_BM (_.callingclosv) >= 2);
  ASSERT_BM (isstring_BM (_.outstrv));
  ASSERT_BM (istaggedint_BM (arg2));
  if (pthread_self () == mainthreadid_BM && gui_is_running_BM)
    {
      log_begin_message_BM ();
      log_printf_message_BM ("compilation of %s module ",
                             modulistemporary ? "temporary" : "persistent");
      log_object_message_BM (_.modulob);
      log_printf_message_BM (" /%s with module generation ", modulidbuf);
      log_object_message_BM (_.modgenob);
      log_printf_message_BM (" ");
      if (status)
        {
          if (WIFEXITED (status))
            log_printf_message_BM ("failed, exited %d.\n",
                                   WEXITSTATUS (status));
          else if (WIFSIGNALED (status))
            log_printf_message_BM ("failed, terminated %s.\n",
                                   strsignal (WTERMSIG (status)));
          else
            log_printf_message_BM ("failed (status %d=%#x).\n", status,
                                   status);
        }
      else
        {
          log_printf_message_BM (" successful.\n");
        }
      unsigned lenout = lenstring_BM (_.outstrv);
      if (lenout > 0)
        log_printf_message_BM
          ("+++++ (%d bytes)\n%s\n----- compile log of %s\n", lenout,
           bytstring_BM (_.outstrv), objectdbg_BM (_.modulob));
    }
  const char *prevpathstr = NULL;
  char *srcpathstr = NULL;
  if (status)
    {
      int err = 0;
      char *badpathstr = NULL;
      const char *moddirstr = bytstring_BM (_.moddirstrv);
      if (modulistemporary)
        asprintf (&srcpathstr, "%s/" TEMPMODULEPREFIX_BM "%s.c",
                  moddirstr, modulidbuf);
      else
        asprintf (&srcpathstr, "%s/" MODULEPREFIX_BM "%s.c",
                  moddirstr, modulidbuf);
      prevpathstr = asprintf_prev_module_BM (moddirstr, _.modulob);
      asprintf (&badpathstr, "%s/" MODULEPREFIX_BM "%s.c-p%d-bad~",
                moddirstr, modulidbuf, (int) getpid ());
      DBGPRINTF_BM ("after-compilation-of-module modulob %s %s moddirstr %s srcpathstr %s badpathstr %s prevpathstr %s", objectdbg_BM (_.modulob),      //
                    modulistemporary ? "temporary" : "persistent",
                    moddirstr, srcpathstr, badpathstr, prevpathstr);
      fflush (NULL);
      rename (srcpathstr, badpathstr);
      if (rename (prevpathstr, srcpathstr))
        err = errno;
      WARNPRINTF_BM ("compilation of %s module %s failed (%d=%#x);"
                     "... restored previous %s from %s with bad new source in %s\n",
                     modulistemporary ? "temporary" : "persistent",
                     objectdbg_BM (_.modulob), status, status, srcpathstr,
                     prevpathstr, badpathstr);
      if (err > 0)
        {
          char cwdbuf[80];
          memset (cwdbuf, 0, sizeof (cwdbuf));
          if (!getcwd (cwdbuf, sizeof (cwdbuf)))
	    FATAL_BM("after-compilation-of-module %s failed to getcwd",
		     objectdbg_BM (_.modulob));
          DBGPRINTF_BM
            ("after-compilation-of-module %s failed renaming %s -> %s failed with #%d: %s in %s",
             objectdbg_BM (_.modulob), prevpathstr, srcpathstr, err,
             strerror (err), cwdbuf);
          WARNPRINTF_BM ("renaming %s -> %s failed with %s\n",
                         prevpathstr, srcpathstr, strerror (err));
        }
      if (pthread_self () == mainthreadid_BM && gui_is_running_BM)
        {
          log_printf_message_BM
            ("restored previous %s from %s,\n.. bad new source in %s.\n",
             srcpathstr, prevpathstr, badpathstr);
          if (err > 0)
            log_printf_message_BM
              ("... renaming %s -> %s failed with %s\n",
               prevpathstr, srcpathstr, strerror (err));
        }
      free (badpathstr), badpathstr = NULL;
    }
  else
    INFOPRINTF_BM ("successful compilation of module %s\n",
                   objectdbg_BM (_.modulob));
  if (pthread_self () == mainthreadid_BM && gui_is_running_BM)
    {
      log_end_message_BM ();
    }
  DBGPRINTF_BM
    ("after-compilation-of-module modulob %s modgenob %s status %d",
     objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob), status);
  if (prevpathstr && srcpathstr && !access (prevpathstr, F_OK))
    {
      char *bak1pathstr = NULL;
      char *bak2pathstr = NULL;
      asprintf (&bak1pathstr, "%s~%%", srcpathstr);
      asprintf (&bak2pathstr, "%s~%%~", srcpathstr);
      (void) rename (bak1pathstr, bak2pathstr);
      DBGPRINTF_BM
        ("after-compilation-of-module modulob %s prevpathstr %s bak1pathstr %s bak2pathstr %s",
         objectdbg_BM (_.modulob), prevpathstr, bak1pathstr, bak2pathstr);
      if (rename (prevpathstr, bak1pathstr))
        FATAL_BM
          ("after-compilation-of-modgenob %s failed to rename %s -> %s",
           objectdbg_BM (_.modulob), prevpathstr, bak1pathstr);
    }
  if (prevpathstr)
    free ((void *) prevpathstr), prevpathstr = NULL;
  if (srcpathstr)
    free ((void *) srcpathstr), srcpathstr = NULL;
  if (status)
    LOCALRETURN_BM (NULL);
  _.postclosv = (value_tyBM)
    makeclosure3_BM (kk_after_load_of_module, _.modulob, _.modgenob,
                     _.moddirstrv);
  DBGBACKTRACEPRINTF_BM ("after-compilation-of-module modulob %s postclosv=%s before defer_module_dynload", objectdbg_BM (_.modulob),   //
                         OUTSTRVALUE_BM (_.postclosv));
  defer_module_dynload_BM (_.modulob, _.postclosv, _.modulob, _.modgenob,
                           NULL, CURFRAME_BM);
  DBGPRINTF_BM
    ("after-compilation-of-module modulob=%s modgenob=%s postclosv=%s end\n",
     objectdbg_BM (_.modulob), objectdbg_BM (_.modgenob),
     OUTSTRVALUE_BM (_.postclosv));
  LOCALRETURN_BM (_.modgenob);
}                               /* end after-compilation-of-module _9le67LL7S9y_5VGpniEUNDA */


////////////////////////////////////////////////////////////////
// after-load-of-module _0UHZG9vDlR2_2Aqx86LMFuq
extern objrout_sigBM ROUTINEOBJNAME_BM (_0UHZG9vDlR2_2Aqx86LMFuq);
value_tyBM
ROUTINEOBJNAME_BM (_0UHZG9vDlR2_2Aqx86LMFuq)    // after-load-of-module
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // resmod
 const value_tyBM arg2_ __attribute__((unused)),        //
 const value_tyBM arg3_ __attribute__((unused)),        //
 const value_tyBM arg4_ __attribute__((unused)),        //
 const quasinode_tyBM * restargs_ __attribute__((unused)))
{
  objectval_tyBM * k_plain_temporary_module = BMK_1oEp0eAAyFN_4lsobepyr1T;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_0UHZG9vDlR2_2Aqx86LMFuq,
                 value_tyBM resultv;    //
                 value_tyBM resmodv;    //
                 objectval_tyBM * modulob;      //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * taskletob;    //
                 value_tyBM callingclosv;       //
                 value_tyBM todoclosv;  //
                 value_tyBM moddirstrv; //
    );
  objectval_tyBM *k_todo_after_module_load = BMK_5DXq2adUiam_4ySWA06AoyV;
  _.resmodv = arg1;
  LOCALGETFUNV_BM (_.callingclosv);
  _.modulob = objectcast_BM (closurenthson_BM (_.callingclosv, 0));
  _.modgenob = objectcast_BM (closurenthson_BM (_.callingclosv, 1));
  _.moddirstrv = closurenthson_BM (_.callingclosv, 2);
  DBGPRINTF_BM ("after-load-of-module €_0UHZG9vDl start resmodv=%s callingclosv=%s modulob=%s modgenob=%s moddirstr=%s",      //
                OUTSTRVALUE_BM (_.resmodv),     //
                OUTSTRVALUE_BM (_.callingclosv),        //
                objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),
                OUTSTRVALUE_BM (_.moddirstrv));
  WEAKASSERT_BM (isobject_BM (_.modulob));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (closurewidth_BM (_.callingclosv) >= 2);
  bool modulistemporary =
    (objectisinstance_BM (_.modulob, k_plain_temporary_module));
  if (pthread_self () == mainthreadid_BM)
    {
      log_begin_message_BM ();
      log_printf_message_BM ("Loaded %s module ",
                             modulistemporary ? "temporary" : "persistent");
      log_object_message_BM (_.modulob);
      log_puts_message_BM (" with generation ");
      log_object_message_BM (_.modgenob);
      log_puts_message_BM (".");
      log_end_message_BM ();
    };
  INFOPRINTF_BM ("loaded %s module %s with generation %s\n",
                 modulistemporary ? "temporary" : "persistent",
                 objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob));
  {
    objlock_BM (_.modgenob);
    _.todoclosv = objgetattr_BM (_.modgenob, k_todo_after_module_load);
    objunlock_BM (_.modgenob);
  }
  DBGPRINTF_BM
    ("after-load-of-module modulob %s modgenob %s got todoclosv %s",
     objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),
     debug_outstr_value_BM (_.todoclosv, CURFRAME_BM, 0));
  if (_.todoclosv)
    {
      _.taskletob =
        objectcast_BM (apply3_BM
                       (_.todoclosv, CURFRAME_BM, _.modulob,
                        _.modgenob, _.resmodv));
      DBGPRINTF_BM
        ("after-load-of-module modulob %s +modgenob %s taskletob %s",
         objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),
         objectdbg2_BM (_.taskletob));
    }
  else
    {
      objlock_BM (_.modulob);
      _.todoclosv = objgetattr_BM (_.modulob, k_todo_after_module_load);
      objunlock_BM (_.modulob);
      _.taskletob =
        objectcast_BM (apply3_BM
                       (_.todoclosv, CURFRAME_BM, _.modulob,
                        _.modgenob, _.resmodv));
      DBGPRINTF_BM
        ("after-load-of-module +modulob %s modgenob %s taskletob %s",
         objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),
         objectdbg2_BM (_.taskletob));
    }
  if (isstring_BM (_.moddirstrv))
    {
      const char *prevstr =
        asprintf_prev_module_BM (bytstring_BM (_.moddirstrv), _.modulob);
      if (!access (prevstr, R_OK))
        {
          char modulidbuf[32];
          memset (modulidbuf, 0, sizeof (modulidbuf));
          idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
          char *bak1str = NULL;
          char *bak2str = NULL;
          if (modulistemporary)
            asprintf (&bak1str, "%s/" TEMPMODULEPREFIX_BM "%s.c~%%",
                      bytstring_BM (_.moddirstrv), modulidbuf);
          else
            asprintf (&bak1str, "%s/" MODULEPREFIX_BM "%s.c~%%",
                      bytstring_BM (_.moddirstrv), modulidbuf);
          if (bak1str)
            asprintf (&bak2str, "%s~", bak1str);        // so make a file ending with .c~%~
          if (bak1str && bak2str)
            (void) rename (bak1str, bak2str);
          if (bak1str)
            (void) rename (prevstr, bak1str);
          free (bak1str), bak1str = NULL;
          free (bak2str), bak2str = NULL;
        }
      free ((void *) prevstr), prevstr = NULL;
    }
  if (_.taskletob)
    {
      agenda_add_very_high_priority_tasklet_BM (_.taskletob);
      LOCALRETURN_BM (_.taskletob);
    };
  DBGPRINTF_BM
    ("after-load-of-module modulob %s modgenob %s no taskletob resmodv %s",
     objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),
     debug_outstr_value_BM (_.resmodv, CURFRAME_BM, 0));
  LOCALRETURN_BM (_.resmodv);
}                               /* end after-load-of-module _0UHZG9vDlR2_2Aqx86LMFuq */



/// In practice, this simple_module_initialize is the body of the
/// moduleinit routine of generated modules.
value_tyBM
simple_module_initialize_BM (const value_tyBM arg1,     //
                             const value_tyBM arg2,     //
                             const value_tyBM arg3,     //
                             const char *modulid,       //
                             objectval_tyBM ** constobjarr,     //
                             const char *const *constidarr,     //
                             const char *const *routidarr,      //
                             void *dlh, // dlopened handle
                             struct stackframe_stBM *stkf)
{
  objectval_tyBM *k_simple_module_initialize = BMK_3XOzJccMA25_76EfdJqsCSL;
  LOCALFRAME_BM (stkf, /*descr: */ k_simple_module_initialize,
                 value_tyBM arg1v;      //
                 value_tyBM arg2v;      //
                 value_tyBM arg3v;      //
                 value_tyBM constsetv;  //
                 value_tyBM routupv;    //
                 objectval_tyBM * curob;        //
                 objectval_tyBM * routob;       //
                 objectval_tyBM * modulob;      //
    );
  _.arg1v = arg1;
  _.arg2v = arg2;
  _.arg3v = arg3;
  DBGBACKTRACEPRINTF_BM ("simple_module_initialize start modulid %s"    //
                         " arg1=%s arg2=%s arg3=%s",
                         modulid,
                         OUTSTRVALUE_BM (_.arg1v),
                         OUTSTRVALUE_BM (_.arg2v), OUTSTRVALUE_BM (_.arg3v));
  {
    rawid_tyBM modid = parse_rawid_BM (modulid, NULL);
    _.modulob = findobjofid_BM (modid);
    if (!_.modulob)
      FATAL_BM
        ("simple_module_initialize cannot find modulob of %s", modulid);
  }
  ASSERT_BM (constobjarr != NULL);
  ASSERT_BM (constidarr != NULL);
  ASSERT_BM (routidarr != NULL);
  unsigned nbconstid = 0;
  for (int ix = 0; ix < MAXSIZE_BM; ix++)
    if (constidarr[ix] == NULL)
      {
        nbconstid = ix;
        break;
      };
  unsigned nbroutid = 0;
  for (int ix = 0; ix < MAXSIZE_BM; ix++)
    if (routidarr[ix] == NULL)
      {
        nbroutid = ix;
        break;
      };
  NONPRINTF_BM
    ("simple_module_initialize modulid %s nbconstid %u, nbroutid %u.",
     modulid, nbconstid, nbroutid);
  for (unsigned oix = 0; oix < nbconstid; oix++)
    {
      _.curob = NULL;
      rawid_tyBM objid = parse_rawid_BM (constidarr[oix], NULL);
      ASSERT_BM (objid.id_hi != 0 && validid_BM (objid));
      _.curob = findobjofid_BM (objid);
      if (!_.curob)
        FATAL_BM
          ("simple_module_initialize: cannot find constant#%d %s for module %s",
           oix, constidarr[oix], objectdbg_BM (_.modulob));
      constobjarr[oix] = _.curob;
    }
  _.constsetv =
    (value_tyBM) makeset_BM ((const objectval_tyBM **) constobjarr,
                             nbconstid);
  objectval_tyBM **routarr = calloc (nbroutid + 1, sizeof (objectval_tyBM *));
  if (!routarr)
    FATAL_BM ("calloc failed for %d routines", nbroutid);
  for (unsigned rix = 0; rix < nbroutid; rix++)
    {
      _.routob = NULL;
      rawid_tyBM routid = parse_rawid_BM (routidarr[rix], NULL);
      ASSERT_BM (routid.id_hi != 0 && validid_BM (routid));
      _.routob = findobjofid_BM (routid);
      if (!_.routob)
        FATAL_BM
          ("simple_module_initialize: cannot find routine#%d %s for module %s",
           rix, routidarr[rix], objectdbg_BM (_.modulob));
      routarr[rix] = _.routob;
      ASSERT_BM (setcontains_BM (_.constsetv, _.routob));
      char routidbuf[32];
      memset (routidbuf, 0, sizeof (routidbuf));
      idtocbuf32_BM (objid_BM (_.routob), routidbuf);
      ASSERT_BM (!strcmp (routidbuf, routidarr[rix]));
      char routname[48];
      memset (routname, 0, sizeof (routname));
      snprintf (routname, sizeof (routname),
                ROUTINEOBJPREFIX_BM "%s" ROUTINESUFFIX_BM, routidbuf);
      if (rix < 10)
        DBGPRINTF_BM ("simple_module_initialize dlsyming '%s' in dlh@%p",
                      routname, dlh);
      objrout_sigBM *routr = (objrout_sigBM *) dlsym (dlh, routname);
      if (!routr)
        FATAL_BM
          ("simple_module_initialize: dlsym of %s in %s /%s failed: %s",
           routname, objectdbg_BM (_.modulob), modulid, dlerror ());
      _.routob->ob_rout = routr;
      _.routob->ob_sig = BMP_function_sig;
      if (rix < 10)
        DBGPRINTF_BM
          ("simple_module_initialize modulob %s rix#%d routob %s routname %s routr@%p",
           objectdbg_BM (_.modulob), rix, objectdbg_BM (_.routob), routname,
           (void *) routr);
    }
  _.routupv = (value_tyBM) maketuple_BM (routarr, nbroutid);
  DBGPRINTF_BM ("simple_module_initialize ending modulob %s modulid %s\n"       //
                ".. constset %s\n" ".. routup %s\n"     //
                ".. arg1 %s arg2 %s arg3 %s\n", objectdbg_BM (_.modulob), modulid,      //
                OUTSTRVALUE_BM (_.constsetv),   //
                OUTSTRVALUE_BM (_.routupv),     //
                OUTSTRVALUE_BM (_.arg1v),       //
                OUTSTRVALUE_BM (_.arg2v),       //
                OUTSTRVALUE_BM (_.arg3v));
  free (routarr), routarr = NULL;
  time_t nowtim = time (NULL);
  struct tm nowtm = {
  };
  localtime_r (&nowtim, &nowtm);
  char nowbuf[64];
  memset (nowbuf, 0, sizeof (nowbuf));
  strftime (nowbuf, sizeof (nowbuf), "%c", &nowtm);
  INFOPRINTF_BM
    ("initialized simple module %s /%s with %u constants and %u routines at %s\n",
     objectdbg_BM (_.modulob), modulid, nbconstid, nbroutid, nowbuf);
  if (pthread_self () == mainthreadid_BM && gui_is_running_BM)
    {
      log_begin_message_BM ();
      log_puts_message_BM ("Initialized simple module ");
      log_object_message_BM (_.modulob);
      log_printf_message_BM (" /%s with %u constants and %u routines at %s.",
                             modulid, nbconstid, nbroutid, nowbuf);
      log_end_message_BM ();
    }
  return (value_tyBM) makenode5_BM (k_simple_module_initialize, _.constsetv,
                                    _.routupv, _.arg1v, _.arg2v, _.arg3v);
}                               /* end simple_module_initialize_BM */



////////////////////////////////////////////////////////////////

// miniscan_node_conn#apply _1X94b6LizfY_2W2ODAL1F3D

extern objrout_sigBM ROUTINEOBJNAME_BM (_1X94b6LizfY_2W2ODAL1F3D);
value_tyBM
ROUTINEOBJNAME_BM (_1X94b6LizfY_2W2ODAL1F3D)    //miniscan_node_conn#apply
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // connob
 const value_tyBM arg2,         // routprepob
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // expv
 const quasinode_tyBM * restargs /*fromob. */ )
{
  objectval_tyBM * k_apply = BMK_3Nl6LhfUZVb_1itsyWMBfYl;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_1X94b6LizfY_2W2ODAL1F3D,
                 objectval_tyBM * connob;       //
                 objectval_tyBM * routprepob;   //
                 value_tyBM expv;       //
                 value_tyBM subexpv;    //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * subtypob;     //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
                 value_tyBM resultv;    //
    );
  int depth = -1;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  WEAKASSERT_BM (isobject_BM (arg1));
  _.connob = objectcast_BM (arg1);
  WEAKASSERT_BM (isobject_BM (arg2));
  _.routprepob = objectcast_BM (arg2);
  WEAKASSERT_BM (istaggedint_BM (arg3));
  depth = getint_BM (arg3);
  _.expv = arg4;
  if (restargs)
    _.fromob = objectcast_BM (treenthson_BM ((value_tyBM) restargs, 0));
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (_.fromob);
  DBGPRINTF_BM
    ("miniscan_node_conn#apply start routprepob %s depth %d exp %s fromob %s",
     objectdbg_BM (_.routprepob), depth,
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg1_BM (_.fromob));
  int nbsons = (int) nodewidth_BM ((value_tyBM) _.expv);
  if (nbsons < 1)
    FAILHERE (BMP_node);
  if (nbsons >= MAXAPPLYARGS_BM)
    FAILHERE (BMP_node);
  for (int ix = 0; ix < nbsons; ix++)
    {
      _.subexpv = (value_tyBM) nodenthson_BM ((value_tyBM) _.expv, ix);
      _.subtypob =
        miniscan_expr_BM (_.subexpv, _.routprepob, depth + 1,
                          _.fromob, CURFRAME_BM);
      if (_.subtypob != BMP_object && _.subtypob != BMP_value)
        FAILHERE (makenode2_BM (BMP_node, taggedint_BM (ix), _.subtypob));
      _.subexpv = NULL;
      _.subtypob = NULL;
    }
  DBGPRINTF_BM ("miniscan_node_conn#apply end routprepob %s depth %d exp %s",
                objectdbg_BM (_.routprepob), depth,
                debug_outstr_value_BM (_.expv, CURFRAME_BM, 0));
  LOCALRETURN_BM (BMP_value);
failure:
#undef FAILHERE
  DBGPRINTF_BM
    ("miniscan_node_conn#apply failure failin %d exp %s routprepob %s cause %s",
     failin, debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg_BM (_.routprepob), debug_outstr_value_BM (_.causev,
                                                         CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode4_BM (k_apply, _.expv, _.routprepob, _.fromob,
                               _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniscan_node_conn#apply _1X94b6LizfY_2W2ODAL1F3D */

////////////////

// miniscan_node_conn#send  _9BWLfKtt9ID_2YwNGH3zu9Q

extern objrout_sigBM ROUTINEOBJNAME_BM (_9BWLfKtt9ID_2YwNGH3zu9Q);

value_tyBM
ROUTINEOBJNAME_BM (_9BWLfKtt9ID_2YwNGH3zu9Q)    // miniscan_node_conn#send 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // connob
 const value_tyBM arg2,         // routprepob
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // expv
 const quasinode_tyBM * restargs /*fromob. */ )
{
  objectval_tyBM * k_send = BMK_5P2fpxElfqT_7NlO7H9TYGI;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_9BWLfKtt9ID_2YwNGH3zu9Q,
                 objectval_tyBM * connob;       //
                 objectval_tyBM * routprepob;   //
                 value_tyBM expv;       //
                 value_tyBM subexpv;    //
                 value_tyBM exprecv;    //
                 value_tyBM expselv;    //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * subtypob;     //
                 objectval_tyBM * recvtypob;    //
                 objectval_tyBM * seltypob;     //
                 value_tyBM subctypv;   //
                 value_tyBM subscalv;   //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
                 value_tyBM resultv;    //
    );
  objectval_tyBM *k_c_type = BMK_83kM1HtO8K3_6k0F2KYQT3W;
  objectval_tyBM *k_scalar_c_type = BMK_68ZSdtDWjWk_4Dex1apSdO7;
  int depth = -1;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  WEAKASSERT_BM (isobject_BM (arg1));
  _.connob = objectcast_BM (arg1);
  WEAKASSERT_BM (isobject_BM (arg2));
  _.routprepob = objectcast_BM (arg2);
  WEAKASSERT_BM (istaggedint_BM (arg3));
  depth = getint_BM (arg3);
  _.expv = arg4;
  if (restargs)
    _.fromob = objectcast_BM (treenthson_BM ((value_tyBM) restargs, 0));
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (_.fromob);
  DBGPRINTF_BM
    ("miniscan_node_conn#send start routprepob %s depth %d exp %s fromob %s",
     objectdbg_BM (_.routprepob), depth,
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg1_BM (_.fromob));
  int nbsons = (int) nodewidth_BM ((value_tyBM) _.expv);
  if (nbsons < 2)
    FAILHERE (BMP_node);
  _.exprecv = nodenthson_BM ((value_tyBM) _.expv, 0);
  _.expselv = nodenthson_BM ((value_tyBM) _.expv, 1);
  int nbsendarg = nbsons - 2;
  if (nbsendarg >= MAXAPPLYARGS_BM - 1)
    FAILHERE (BMP_node);
  _.recvtypob =
    miniscan_expr_BM (_.exprecv, _.routprepob, depth + 1,
                      _.fromob, CURFRAME_BM);
  if (_.recvtypob != BMP_object && _.recvtypob != BMP_value)
    FAILHERE (makenode2_BM (BMP_node, taggedint_BM (0), _.recvtypob));
  _.seltypob =
    miniscan_expr_BM (_.expselv, _.routprepob, depth + 1,
                      _.fromob, CURFRAME_BM);
  if (_.seltypob != BMP_object)
    FAILHERE (makenode2_BM (BMP_node, taggedint_BM (1), _.seltypob));
  for (int ix = 0; ix < nbsendarg; ix++)
    {
      _.subexpv = (value_tyBM) nodenthson_BM ((value_tyBM) _.expv, ix + 2);
      _.subtypob =
        miniscan_expr_BM (_.subexpv, _.routprepob, depth + 1,
                          _.fromob, CURFRAME_BM);
      if (!_.subtypob)
        {
          WARNPRINTF_BM
            ("miniscan_node_conn#send failing ix#%d connob %s routprepob %s depth#%d expv %s subexpv %s no subtypob",
             ix, objectdbg_BM (_.connob), objectdbg1_BM (_.routprepob), depth,
             OUTSTRVALUE_BM (_.expv), OUTSTRVALUE_BM (_.subexpv));
          FAILHERE (makenode1_BM (BMP_node, taggedint_BM (ix + 2)));
        }
      else if (_.subtypob != BMP_object && _.subtypob != BMP_value)
        {
          objlock_BM (_.subtypob);
          _.subctypv = objgetattr_BM (_.subtypob, k_c_type);
          _.subscalv = objgetattr_BM (_.subtypob, k_scalar_c_type);
          objunlock_BM (_.subtypob);
          if (_.subscalv)
            {
              DBGPRINTF_BM
                ("miniscan_node_conn#send  ix#%d connob %s routprepob %s depth#%d expv %s subexpv %s scalar subtypob %s subctypv %s subscalv %s",
                 ix, objectdbg_BM (_.connob), objectdbg1_BM (_.routprepob),
                 depth, OUTSTRVALUE_BM (_.expv), OUTSTRVALUE_BM (_.subexpv),
                 objectdbg2_BM (_.subtypob), OUTSTRVALUE_BM (_.subctypv),
                 OUTSTRVALUE_BM (_.subscalv));
              LOCALRETURN_BM (_.subtypob);
            }
          else
            {
              WARNPRINTF_BM
                ("miniscan_node_conn#send failing ix#%d connob %s routprepob %s depth#%d expv %s subexpv %s strange subtypob %s subctypv %s subscalv %s",
                 ix, objectdbg_BM (_.connob), objectdbg1_BM (_.routprepob),
                 depth, OUTSTRVALUE_BM (_.expv), OUTSTRVALUE_BM (_.subexpv),
                 objectdbg2_BM (_.subtypob), OUTSTRVALUE_BM (_.subctypv),
                 OUTSTRVALUE_BM (_.subscalv));
              FAILHERE (makenode2_BM
                        (BMP_node, taggedint_BM (ix + 2), _.subtypob));
            }
        }
      _.subexpv = NULL;
      _.subtypob = NULL;
      _.subscalv = NULL;
      _.subctypv = NULL;
    }
  DBGPRINTF_BM ("miniscan_node_conn#send end routprepob %s depth %d exp %s",
                objectdbg_BM (_.routprepob), depth, OUTSTRVALUE_BM (_.expv));
  LOCALRETURN_BM (BMP_value);
failure:
#undef FAILHERE
  DBGPRINTF_BM
    ("miniscan_node_conn#send failure failin %d exp %s routprepob %s cause %s",
     failin, debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg_BM (_.routprepob), debug_outstr_value_BM (_.causev,
                                                         CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode4_BM (k_send, _.expv, _.routprepob, _.fromob,
                               _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniscan_node_conn#send  _9BWLfKtt9ID_2YwNGH3zu9Q */


////////////////

// miniscan_node_conn#make_sequence _1nHMifVeQIt_0mCPhG89MWu
// for make_tuple or make_set

extern objrout_sigBM ROUTINEOBJNAME_BM (_1nHMifVeQIt_0mCPhG89MWu);

value_tyBM
ROUTINEOBJNAME_BM (_1nHMifVeQIt_0mCPhG89MWu)    //miniscan_node_conn#make_sequence
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // connob
 const value_tyBM arg2,         // routprepob
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // expv
 const quasinode_tyBM * restargs /*fromob. */ )
{
  objectval_tyBM * k_tuple = BMK_6TmLNh9vtVY_0pwkHRtJ44k;
  objectval_tyBM *k_set = BMK_2mYaTh9kH4I_7ENiXcymRmy;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_1nHMifVeQIt_0mCPhG89MWu,
                 objectval_tyBM * connob;       //
                 objectval_tyBM * routprepob;   //
                 value_tyBM expv;       //
                 value_tyBM subexpv;    //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * seqtypob;     //
                 objectval_tyBM * subtypob;     //
                 value_tyBM callingclosv;       //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
                 value_tyBM resultv;    //
    );
  int depth = -1;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  LOCALGETFUNV_BM (_.callingclosv);
  WEAKASSERT_BM (isobject_BM (arg1));
  _.connob = objectcast_BM (arg1);
  WEAKASSERT_BM (isobject_BM (arg2));
  _.routprepob = objectcast_BM (arg2);
  WEAKASSERT_BM (istaggedint_BM (arg3));
  depth = getint_BM (arg3);
  _.expv = arg4;
  if (restargs)
    _.fromob = objectcast_BM (treenthson_BM ((value_tyBM) restargs, 0));
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (_.fromob);
  DBGPRINTF_BM
    ("miniscan_node_conn#make_sequence start routprepob %s depth %d exp %s fromob %s",
     objectdbg_BM (_.routprepob), depth,
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg1_BM (_.fromob));
  _.seqtypob = objectcast_BM (closurenthson_BM (_.callingclosv, 0));
  WEAKASSERT_BM (_.seqtypob == k_tuple || _.seqtypob == k_set);
  int nbsons = (int) nodewidth_BM ((value_tyBM) _.expv);
  for (int ix = 0; ix < nbsons; ix++)
    {
      _.subexpv = (value_tyBM) nodenthson_BM ((value_tyBM) _.expv, ix);
      _.subtypob =
        miniscan_expr_BM (_.subexpv, _.routprepob, depth + 1,
                          _.fromob, CURFRAME_BM);
      if (_.subtypob != BMP_object
          || miniscan_compatype_BM (_.subtypob, BMP_object,
                                    CURFRAME_BM) != BMP_object)
        FAILHERE (makenode2_BM (BMP_node, taggedint_BM (ix), _.subtypob));
      _.subexpv = NULL;
      _.subtypob = NULL;
    }
  LOCALRETURN_BM (BMP_value);
failure:
  DBGPRINTF_BM ("miniscan_node_conn#make_sequence failure failin %d exp %s routprepob %s cause %s", failin, debug_outstr_value_BM (_.expv, CURFRAME_BM, 0), objectdbg_BM (_.routprepob),        //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode4_BM (_.connob ? _.connob :
                               BMK_1nHMifVeQIt_0mCPhG89MWu, _.expv,
                               _.routprepob, _.fromob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniscan_node_conn#make_sequence  _1nHMifVeQIt_0mCPhG89MWu */


////////////////

// miniscan_node_conn#collect_sequence  _9FtctWvW1qr_5mEGPxjn1co

extern objrout_sigBM ROUTINEOBJNAME_BM (_9FtctWvW1qr_5mEGPxjn1co);

value_tyBM
ROUTINEOBJNAME_BM (_9FtctWvW1qr_5mEGPxjn1co)    //miniscan_node_conn#collect_sequence
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // connob
 const value_tyBM arg2,         // routprepob
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // expv
 const quasinode_tyBM * restargs /*fromob. */ )
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_9FtctWvW1qr_5mEGPxjn1co,
                 objectval_tyBM * connob;       //
                 objectval_tyBM * routprepob;   //
                 value_tyBM expv;       //
                 value_tyBM subexpv;    //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * seqtypob;     //
                 objectval_tyBM * subtypob;     //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
                 value_tyBM resultv;    //
    );
  int depth = -1;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  WEAKASSERT_BM (isobject_BM (arg1));
  _.connob = objectcast_BM (arg1);
  WEAKASSERT_BM (isobject_BM (arg2));
  _.routprepob = objectcast_BM (arg2);
  WEAKASSERT_BM (istaggedint_BM (arg3));
  depth = getint_BM (arg3);
  _.expv = arg4;
  if (restargs)
    _.fromob = objectcast_BM (treenthson_BM ((value_tyBM) restargs, 0));
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (_.fromob);
  DBGPRINTF_BM
    ("miniscan_node_conn#collect_sequence start routprepob %s depth %d exp %s fromob %s",
     objectdbg_BM (_.routprepob), depth,
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg1_BM (_.fromob));
  int nbsons = nodewidth_BM ((value_tyBM) _.expv);
  for (int ix = 0; ix < nbsons; ix++)
    {
      _.subexpv = (value_tyBM) nodenthson_BM ((value_tyBM) _.expv, ix);
      _.subtypob =
        miniscan_expr_BM (_.subexpv, _.routprepob, depth + 1,
                          _.fromob, CURFRAME_BM);
      if ((_.subtypob != BMP_object && _.subtypob != BMP_value)
          || miniscan_compatype_BM (_.subtypob, BMP_value,
                                    CURFRAME_BM) != BMP_value)
        FAILHERE (makenode2_BM (BMP_node, taggedint_BM (ix), _.subtypob));
      _.subexpv = NULL;
      _.subtypob = NULL;
    }
  LOCALRETURN_BM (BMP_value);
failure:
  DBGPRINTF_BM ("miniscan_node_conn#make_sequence failure failin %d exp %s routprepob %s cause %s", failin, debug_outstr_value_BM (_.expv, CURFRAME_BM, 0), objectdbg_BM (_.routprepob),        //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode4_BM (_.connob ? _.connob :
                               BMK_9FtctWvW1qr_5mEGPxjn1co, _.expv,
                               _.routprepob, _.fromob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniscan_node_conn#collect_sequence _9FtctWvW1qr_5mEGPxjn1co */


////////////////


// miniscan_node_conn#make_tree _8ru2DB8XTmJ_7h8mj1NTpKM

extern objrout_sigBM ROUTINEOBJNAME_BM (_8ru2DB8XTmJ_7h8mj1NTpKM);

value_tyBM
ROUTINEOBJNAME_BM (_8ru2DB8XTmJ_7h8mj1NTpKM)    // miniscan_node_conn#make_tree 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // connob
 const value_tyBM arg2,         // routprepob
 const value_tyBM arg3,         // depth
 const value_tyBM arg4,         // expv
 const quasinode_tyBM * restargs /*fromob. */ )
{
  objectval_tyBM * k_arity = BMK_6fPPUXnZhy5_8Lh5DOOe0Nu;
  objectval_tyBM *k_node = BMK_7D8xcWnEiys_8oqOVSkCxkA;
  objectval_tyBM *k_closure = BMK_93zjUzZVAaj_9ppXv7C34GR;
  //objectval_tyBM *k_connective = BMK_64FyzTwMoeT_9W2OIW95K2H;
  objectval_tyBM *k_object = BMK_7T9OwSFlgov_0wVJaK1eZbn;
  //objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_8ru2DB8XTmJ_7h8mj1NTpKM,
                 objectval_tyBM * connob;       //
                 objectval_tyBM * routprepob;   //
                 value_tyBM expv;       //
                 value_tyBM subexpv;    //
                 value_tyBM connexpv;   //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * seqtypob;     //
                 objectval_tyBM * subtypob;     //
                 objectval_tyBM * conntypob;    //
                 value_tyBM callingclosv;       //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
                 value_tyBM resultv;    //
    );
  int depth = -1;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  LOCALGETFUNV_BM (_.callingclosv);
  WEAKASSERT_BM (isobject_BM (arg1));
  _.connob = objectcast_BM (arg1);
  WEAKASSERT_BM (isobject_BM (arg2));
  _.routprepob = objectcast_BM (arg2);
  WEAKASSERT_BM (istaggedint_BM (arg3));
  depth = getint_BM (arg3);
  _.expv = arg4;
  if (restargs)
    _.fromob = objectcast_BM (treenthson_BM ((value_tyBM) restargs, 0));
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (_.fromob);
  DBGPRINTF_BM
    ("miniscan_node_conn#make_tree start routprepob %s depth %d exp %s fromob %s",
     objectdbg_BM (_.routprepob), depth,
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg1_BM (_.fromob));
  _.seqtypob = objectcast_BM (closurenthson_BM (_.callingclosv, 0));
  WEAKASSERT_BM (_.seqtypob == k_node || _.seqtypob == k_closure);
  int nbsons = nodewidth_BM ((value_tyBM) _.expv);
  if (nbsons == 0)
    FAILHERE (k_arity);
  _.connexpv = nodenthson_BM ((value_tyBM) _.expv, 0);
  _.conntypob =
    miniscan_expr_BM (_.connexpv, _.routprepob, depth + 1,
                      _.fromob, CURFRAME_BM);
  if (_.conntypob != k_object
      || miniscan_compatype_BM (_.conntypob, k_object,
                                CURFRAME_BM) != k_object)
    FAILHERE (makenode1_BM (k_arity, _.conntypob));
  for (int ix = 1; ix < nbsons; ix++)
    {
      _.subexpv = (value_tyBM) nodenthson_BM ((value_tyBM) _.expv, ix);
      _.subtypob =
        miniscan_expr_BM (_.subexpv, _.routprepob, depth + 1,
                          _.fromob, CURFRAME_BM);
      if ((_.subtypob != BMP_object && _.subtypob != BMP_value)
          || miniscan_compatype_BM (_.subtypob, BMP_value,
                                    CURFRAME_BM) != BMP_value)
        FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (ix), _.subtypob));
      _.subexpv = NULL;
      _.subtypob = NULL;
    }
  LOCALRETURN_BM (BMP_value);
failure:
  DBGPRINTF_BM ("miniscan_node_conn#make_tree failure failin %d exp %s routprepob %s cause %s", //
                failin, debug_outstr_value_BM (_.expv, CURFRAME_BM, 0), objectdbg_BM (_.routprepob),    //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode4_BM (_.connob ? _.connob :
                               BMK_8ru2DB8XTmJ_7h8mj1NTpKM, _.expv,
                               _.routprepob, _.fromob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniscan_node_conn#make_tree  _8ru2DB8XTmJ_7h8mj1NTpKM */

///// end of file gencode_BM.c
