// file emitcode_BM.c

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
#include "emitcode_BM.const.h"


extern const char *asprintf_prev_module_BM (const char *srcdir,
                                            objectval_tyBM * obmodule);

//// for the method emit_c_type:c_opaque
extern objrout_sigBM ROUTINEOBJNAME_BM (_6gRlN8loM4E_4pSsNmiCeIa);

value_tyBM
ROUTINEOBJNAME_BM (_6gRlN8loM4E_4pSsNmiCeIa)    // emit_c_type:c_opaque
(struct stackframe_stBM * stkf, const value_tyBM arg1,  //
 const value_tyBM arg2,         //
 const value_tyBM arg3_ __attribute__ ((unused)),       //
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM recv;
                 objectval_tyBM * bufob;
    );
  // retrieve arguments
  _.recv = /*ctype */ (arg1);
  WEAKASSERT_BM (isobject_BM (_.recv));
  _.bufob = objectcast_BM (arg2);
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.bufob));
  DBGPRINTF_BM
    ("start  emit_c_type:c_opaque _6gRlN8loM4E_4pSsNmiCeIa recv=%s",
     objectdbg_BM (_.recv));
  const char *nam = findobjectname_BM (_.recv);
  char idbuf[32] = { };
  idtocbuf32_BM (objid_BM (_.recv), idbuf);
  if (nam)
    {
      objstrbufferprintfpayl_BM (_.bufob, "\n// opaque named type\n");
      objstrbufferprintfpayl_BM (_.bufob, "typedef void* %s_TyBM;\n", nam);
      objstrbufferprintfpayl_BM (_.bufob, "#define %s_TyBM %s_TyBM\n", idbuf,
                                 nam);
    }
  else
    {
      objstrbufferprintfpayl_BM (_.bufob, "\n// opaque anonymous type\n");
      objstrbufferprintfpayl_BM (_.bufob, "typedef void* %s_TyBM;\n", idbuf);
    }
  LOCALRETURN_BM (_.recv);
}                               /* end emit_c_type:c_opaque _6gRlN8loM4E_4pSsNmiCeIa */




//// for the method emit_c_type:c_enum
extern objrout_sigBM ROUTINEOBJNAME_BM (_979hCujWp2g_9tjRbM8Ht1l);

value_tyBM
ROUTINEOBJNAME_BM (_979hCujWp2g_9tjRbM8Ht1l)    // emit_c_type:c_enum
(struct stackframe_stBM * stkf, const value_tyBM arg1,  //
 const value_tyBM arg2,         //
 const value_tyBM arg3_ __attribute__ ((unused)),       //
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf, /*descr: */ NULL,
                 value_tyBM recv;
                 objectval_tyBM * prbufob;
                 const objectval_tyBM * extendingob;
                 const tupleval_tyBM * ownenumtup;
    );
  // retrieve arguments
  _.recv = /*ctype */ (arg1);
  WEAKASSERT_BM (isobject_BM (_.recv));
  WEAKASSERT_BM (objhasstrbufferpayl_BM (arg2));
  _.prbufob = objectcast_BM (arg2);
  DBGPRINTF_BM
    ("start emit_c_type:c_enum _979hCujWp2g_9tjRbM8Ht1l recv=%s",
     objectdbg_BM (_.recv));
  const objectval_tyBM *k_extending = BMK_2bqFfs5OYL2_0HRi4lcgFcu;
  const objectval_tyBM *k_own_enumeration = BMK_4ot0ZxxA31Y_8GVFlcbckIH;
  //const objectval_tyBM *k_enumeration = BMK_7BROpIWQHzA_8b1C6i49Pkz;
  //
  //const char *nam = findobjectname_BM (_.recv);
  char idbuf[32] = { };
  idtocbuf32_BM (objid_BM (_.recv), idbuf);
  _.extendingob = objectcast_BM (objgetattr_BM (_.recv, k_extending));
  _.ownenumtup = tuplecast_BM (objgetattr_BM (_.recv, k_own_enumeration));
#warning emit_c_type:c_enum _979hCujWp2g_9tjRbM8Ht1l unimplemented
  LOCALRETURN_BM (NULL);
}                               /* end emit_c_type:c_enum _979hCujWp2g_9tjRbM8Ht1l  */


// emit_declaration°simple_routine_preparation _9M3BqmOS7mA_96DTa52k7Xq
extern objrout_sigBM ROUTINEOBJNAME_BM (_9M3BqmOS7mA_96DTa52k7Xq);
value_tyBM
ROUTINEOBJNAME_BM (_9M3BqmOS7mA_96DTa52k7Xq)    // emit_declaration°simple_routine_preparation 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recv
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // index
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_9M3BqmOS7mA_96DTa52k7Xq,
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routob;       //
                 objectval_tyBM * lockhsetob;   //
                 objectval_tyBM * hsetblockob;  //
                 value_tyBM blocksetv;  //
                 objectval_tyBM * hsetvalob;    //
                 objectval_tyBM * hsetnumob;    //
                 objectval_tyBM * keyob;        //
                 objectval_tyBM * bindconnob;   //
                 value_tyBM resultv;    //
                 value_tyBM keysetv;    //
                 value_tyBM setv;       //
                 value_tyBM keybindv;   //
                 value_tyBM errorv;     //
                 value_tyBM commentv;   //
                 value_tyBM errcausev;);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.errcausev = (value_tyBM)(Cause); goto failure; } while(0)
  objectval_tyBM *k_blocks = BMK_2lCuMosXupr_5GAoqVgJ8PZ;
  objectval_tyBM *k_prepare_routine = BMK_6qi1DW0Ygkl_4Aqdxq4n5IV;
  objectval_tyBM *k_hset_object = BMK_8c9otZ4pwR6_55k81qyyYV2;
  objectval_tyBM *k_value_set = BMK_6Fl0Z0OTtV9_8QTsq3uDu4q;
  objectval_tyBM *k_number_set = BMK_5uPst3m4mdx_05Xl1AoTnZL;
  objectval_tyBM *k_in = BMK_0eMGYofuNVh_8ZP2mXdhtHO;
  objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  objectval_tyBM *k_locals = BMK_24sSVIADeHm_0Sx34wQfG7W;
  objectval_tyBM *k_numbers = BMK_32eKNcTZ9HN_80t0nk47Mha;
  objectval_tyBM *k_result = BMK_7bD9VtDkGSn_7lxHeYuuFLR;
  objectval_tyBM *k_closed = BMK_2TwOyPJxIz8_1rIeqaN7oRz;
  objectval_tyBM *k_binding = BMK_6zu0x6tqX60_8QhJjiAOwul;
  //objectval_tyBM *k_c_type = BMK_83kM1HtO8K3_6k0F2KYQT3W;
  objectval_tyBM *k_emit_declaration = BMK_3NGaoN3yhbn_8yUwbtZfvp9;
  objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  objectval_tyBM *k_locking = BMK_8yqFC2Qz7I2_7KoZMWLE0U3;
  WEAKASSERT_BM (isobject_BM (arg1));
  _.routprepob = objectcast_BM (arg1);
  WEAKASSERT_BM (isobject_BM (arg2));
  _.modgenob = objectcast_BM (arg2);
  WEAKASSERT_BM (istaggedint_BM (arg3));
  int rank = getint_BM (arg3);
  DBGPRINTF_BM
    ("emit_declaration°simple_routine_preparation start routprepob=%s modgenob=%s rank#%d",
     objectdbg_BM (_.routprepob), objectdbg1_BM (_.modgenob), rank);
  {
    objlock_BM (_.routprepob);
    _.routob =
      objectcast_BM (objgetattr_BM (_.routprepob, k_prepare_routine));
    _.hsetblockob = objectcast_BM (objgetattr_BM (_.routprepob, k_blocks));
    _.lockhsetob = objectcast_BM (objgetattr_BM (_.routprepob, k_locking));
    DBGPRINTF_BM
      ("emit_declaration°simple_routine_preparation routprepob=%s routob=%s hsetblockob=%s lockhsetob=%s",
       objectdbg_BM (_.routprepob), objectdbg1_BM (_.routob),
       objectdbg2_BM (_.hsetblockob), objectdbg3_BM (_.lockhsetob));
    {
      objlock_BM (_.hsetblockob);
      WEAKASSERT_BM (isobject_BM (_.hsetblockob));
      _.blocksetv = (value_tyBM) objhashsettosetpayl_BM (_.hsetblockob);
      objunlock_BM (_.hsetblockob);
      DBGPRINTF_BM
        ("emit_declaration°simple_routine_preparation routprepob=%s blocksetv=%s",
         objectdbg_BM (_.routprepob),
         debug_outstr_value_BM (_.blocksetv, CURFRAME_BM, 0));
      if (_.blocksetv)
        objputattr_BM (_.routprepob, k_blocks, _.blocksetv);
    }
    {
      _.hsetvalob = makeobj_BM ();
      objputclass_BM (_.hsetvalob, k_hset_object);
      objputattr_BM (_.routprepob, k_value_set, _.hsetvalob);
      objputattr_BM (_.hsetvalob, k_in, _.routprepob);
      objputhashsetpayl_BM (_.hsetvalob, 5);
      _.hsetnumob = makeobj_BM ();
      objputclass_BM (_.hsetnumob, k_hset_object);
      objputattr_BM (_.routprepob, k_number_set, _.hsetnumob);
      objputattr_BM (_.hsetnumob, k_in, _.routprepob);
      objputhashsetpayl_BM (_.hsetnumob, 11);
      _.keysetv = (value_tyBM) objassocsetattrspayl_BM (_.routprepob);
      DBGPRINTF_BM ("emit_declaration°simple_routine_preparation routprepob=%s hsetvalob=%s hsetnumob=%s keyset=%s", objectdbg_BM (_.routprepob), objectdbg1_BM (_.hsetvalob), objectdbg2_BM (_.hsetnumob),    //
                    debug_outstr_value_BM (_.keysetv, CURFRAME_BM, 0));
      unsigned nbkeys = setcardinal_BM (_.keysetv);
      for (unsigned kix = 0; kix < nbkeys; kix++)
        {
          _.bindconnob = NULL;
          _.keyob = setelemnth_BM (_.keysetv, kix);
          _.keybindv = objassocgetattrpayl_BM (_.routprepob, _.keyob);
          DBGPRINTF_BM
            ("emit_declaration°simple_routine_preparation routprepob=%s kix#%d keyob=%s keybind=%s",
             objectdbg_BM (_.routprepob), kix, objectdbg1_BM (_.keyob),
             debug_outstr_value_BM (_.keybindv, CURFRAME_BM, 0));
          WEAKASSERT_BM (_.keybindv == k_result || isnode_BM (_.keybindv));
          if (_.keybindv == k_result)
            {
              objhashsetaddpayl_BM (_.hsetvalob, _.keyob);
            }
          else
            if ((_.bindconnob = nodeconn_BM (_.keybindv))
                && _.bindconnob == k_arguments)
            {
              objhashsetaddpayl_BM (_.hsetvalob, _.keyob);
            }
          else if (_.bindconnob == k_locals)
            {
              objhashsetaddpayl_BM (_.hsetvalob, _.keyob);
            }
          else if (_.bindconnob == k_closed)
            {
              objhashsetaddpayl_BM (_.hsetvalob, _.keyob);
            }
          else if (_.bindconnob == k_numbers)
            {
              objhashsetaddpayl_BM (_.hsetnumob, _.keyob);
            }
          else if (_.bindconnob == k_constants)
            {
            }
          else
            FAILHERE (makenode1_BM (k_binding, _.keybindv));
        }
      _.setv = (value_tyBM) objhashsettosetpayl_BM (_.hsetvalob);
      objputattr_BM (_.routprepob, k_value_set, _.setv);
      DBGPRINTF_BM ("emit_declaration°simple_routine_preparation routprepob=%s value_set %s",  //
                    objectdbg_BM (_.routprepob),        //
                    debug_outstr_value_BM (_.setv, CURFRAME_BM, 0));
      _.setv = (value_tyBM) objhashsettosetpayl_BM (_.hsetnumob);
      objputattr_BM (_.routprepob, k_number_set, _.setv);
      DBGPRINTF_BM ("emit_declaration°simple_routine_preparation routprepob=%s number_set %s", //
                    objectdbg_BM (_.routprepob),        //
                    debug_outstr_value_BM (_.setv, CURFRAME_BM, 0));
      _.setv = NULL;
    }
    if (_.lockhsetob)
      {
        _.setv = (value_tyBM) objhashsettosetpayl_BM (_.lockhsetob);
        objputattr_BM (_.routprepob, k_locking, _.setv);
        DBGPRINTF_BM ("emit_declaration°simple_routine_preparation routprepob=%s locking %s",  //
                      objectdbg_BM (_.routprepob),      //
                      debug_outstr_value_BM (_.setv, CURFRAME_BM, 0));
        _.setv = NULL;
      }
    objunlock_BM (_.routprepob);
  }
  WEAKASSERT_BM (isobject_BM (_.routob));
  {
    char routidbuf[32];
    memset (routidbuf, 0, sizeof (routidbuf));
    idtocbuf32_BM (objid_BM (_.routob), routidbuf);
    objlock_BM (_.modgenob);
    _.commentv = objgetattr_BM (_.routob, BMP_comment);
    const char *routname = findobjectname_BM (_.routob);
    WEAKASSERT_BM (objhasstrbufferpayl_BM (_.modgenob));
    if (routname)
      objstrbufferprintfpayl_BM (_.modgenob, "\n"
                                 "extern objrout_sigBM crout%s_BM; //#%d %s\n",
                                 routidbuf, rank, routname);
    else if (isstring_BM (_.commentv))
      {
        const char *bytcom = bytstring_BM (_.commentv);
        int comlen = lenstring_BM (_.commentv);
        const char *eol = strchr (bytcom, '\n');
        if (eol)
          comlen = eol - bytcom - 1;
        if (comlen > 1)
          objstrbufferprintfpayl_BM (_.modgenob, "\n"
                                     "extern objrout_sigBM crout%s_BM; //#%d !%.*s\n",
                                     routidbuf, rank, comlen, bytcom);
        else
          goto plainrout;
      }
    else
    plainrout:
      objstrbufferprintfpayl_BM (_.modgenob, "\n"
                                 "extern objrout_sigBM crout%s_BM; //#%d\n",
                                 routidbuf, rank);
    objunlock_BM (_.modgenob);
  }
  DBGPRINTF_BM
    ("emit_declaration°simple_routine_preparation end routprepob %s",
     objectdbg1_BM (_.routprepob));
  LOCALRETURN_BM (_.routprepob);
failure:
  DBGPRINTF_BM
    ("emit_declaration°simple_routine_preparation failed failin %d errcause %s routprepob %s",
     failin, debug_outstr_value_BM (_.errcausev, CURFRAME_BM, 0),
     objectdbg1_BM (_.routprepob));
  _.errorv =
    (value_tyBM) makenode4_BM (k_emit_declaration, _.routprepob,
                               _.modgenob, taggedint_BM (rank), _.errcausev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end emit_declaration°simple_routine_preparation _9M3BqmOS7mA_96DTa52k7Xq */


///////
// emit_definition°simple_routine_preparation _2Lk2DjTDzQh_3aTEVKDE2Ip
extern objrout_sigBM ROUTINEOBJNAME_BM (_2Lk2DjTDzQh_3aTEVKDE2Ip);
value_tyBM
ROUTINEOBJNAME_BM (_2Lk2DjTDzQh_3aTEVKDE2Ip)    // emit_definition°simple_routine_preparation 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recv
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // index
 const value_tyBM arg4_ __attribute__ ((unused)),       //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  objectval_tyBM *k_locking = BMK_8yqFC2Qz7I2_7KoZMWLE0U3;
  objectval_tyBM *k_lockobj = BMK_9dso3pFLYwm_3JwHqiJK3UL;
  objectval_tyBM *k_emit_definition = BMK_1g8s9B96Irf_6Ix2Cyy8Hq0;
  //objectval_tyBM *k_blocks = BMK_2lCuMosXupr_5GAoqVgJ8PZ;
  objectval_tyBM *k_prepare_routine = BMK_6qi1DW0Ygkl_4Aqdxq4n5IV;
  objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  objectval_tyBM *k_body = BMK_7DQyvJFMOrC_9IfC3CtYknn;
  objectval_tyBM *k_result = BMK_7bD9VtDkGSn_7lxHeYuuFLR;
  objectval_tyBM *k_value_set = BMK_6Fl0Z0OTtV9_8QTsq3uDu4q;
  objectval_tyBM *k_number_set = BMK_5uPst3m4mdx_05Xl1AoTnZL;
  objectval_tyBM *k_c_type = BMK_83kM1HtO8K3_6k0F2KYQT3W;
  objectval_tyBM *k_object = BMK_7T9OwSFlgov_0wVJaK1eZbn;
  objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  objectval_tyBM *k_closed = BMK_2TwOyPJxIz8_1rIeqaN7oRz;
  //objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
  //objectval_tyBM *k_emit_expression = BMK_9lXSe7DrOl6_7hghYt0LhTF;
  //objectval_tyBM *k_emit_tatement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_emit_block = BMK_6mk5eos8067_1odgCpnWMOj;
  //objectval_tyBM *k_emit_reference = BMK_6qzzDyr2eIo_3SapnOUpg6S;
  objectval_tyBM *k_plain_module = BMK_8g1WBJBhDT9_1QK8IcuWYx2;
  objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_2Lk2DjTDzQh_3aTEVKDE2Ip,
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * modulob;      //
                 objectval_tyBM * routob;       //
                 objectval_tyBM * hsetblockob;  //
                 objectval_tyBM * bodyob;       //
                 objectval_tyBM * resultob;     //
                 objectval_tyBM * curclosob;    //
                 value_tyBM blocksetv;  //
                 value_tyBM argtupv;
                 value_tyBM closedseqv; //
                 value_tyBM commentv;   //
                 value_tyBM setnumv;    //
                 value_tyBM setvalv;    //
                 value_tyBM setconstv;  //
                 value_tyBM setlockingv;        //
                 objectval_tyBM * varob;        //
                 objectval_tyBM * lockob;       //
                 value_tyBM emitv;      //
                 objectval_tyBM * typob;        //
                 value_tyBM errorv;     //
                 value_tyBM causev;);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  char routidbuf[32];
  memset (routidbuf, 0, sizeof (routidbuf));
  char modulidbuf[32];
  memset (modulidbuf, 0, sizeof (modulidbuf));
  WEAKASSERT_BM (isobject_BM (arg1));
  _.routprepob = objectcast_BM (arg1);
  WEAKASSERT_BM (isobject_BM (arg2));
  _.modgenob = objectcast_BM (arg2);
  WEAKASSERT_BM (istaggedint_BM (arg3));
  int rank = getint_BM (arg3);
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation start routprepob=%s modgenob=%s rank#%d",
     objectdbg_BM (_.routprepob), objectdbg1_BM (_.modgenob), rank);
  objlock_BM (_.modgenob);
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.modgenob));
  _.modulob = objectcast_BM (objgetattr_BM (_.modgenob, k_plain_module));
  _.setconstv = objgetattr_BM (_.modgenob, k_constants);
  WEAKASSERT_BM (_.modulob);
  WEAKASSERT_BM (isset_BM (_.setconstv));
  idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
  {
    objlock_BM (_.routprepob);
    _.routob =
      objectcast_BM (objgetattr_BM (_.routprepob, k_prepare_routine));
    _.setnumv =
      (value_tyBM) setcast_BM (objgetattr_BM (_.routprepob, k_number_set));
    _.setvalv =
      (value_tyBM) setcast_BM (objgetattr_BM (_.routprepob, k_value_set));
    _.setlockingv =
      (value_tyBM) setcast_BM (objgetattr_BM (_.routprepob, k_locking));
    objunlock_BM (_.routprepob);
    idtocbuf32_BM (objid_BM (_.routob), routidbuf);
  }
  DBGPRINTF_BM ("emit_definition°simple_routine_preparation routprepob=%s routob=%s modulob=%s\n"      //
                ".. setnum=%s setval=%s", objectdbg_BM (_.routprepob), objectdbg1_BM (_.routob),        //
                objectdbg2_BM (_.modulob), debug_outstr_value_BM (_.setnumv, CURFRAME_BM, 0),   //
                debug_outstr_value_BM (_.setvalv, CURFRAME_BM, 0));
  WEAKASSERT_BM (isobject_BM (_.routob));
  {
    objlock_BM (_.routob);
    _.commentv = objgetattr_BM (_.routob, BMP_comment);
    _.argtupv = objgetattr_BM (_.routob, k_arguments);
    _.closedseqv = objgetattr_BM (_.routob, k_closed);
    _.bodyob = objectcast_BM (objgetattr_BM (_.routob, k_body));
    _.resultob = objectcast_BM (objgetattr_BM (_.routob, k_result));
    objunlock_BM (_.routob);
  }
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation routob=%s rank#%d argtup=%s closedseq=%s bodyob=%s resultob=%s",
     objectdbg_BM (_.routob), rank,
     debug_outstr_value_BM (_.argtupv, CURFRAME_BM, 0),
     debug_outstr_value_BM (_.closedseqv, CURFRAME_BM, 0),
     objectdbg1_BM (_.bodyob), objectdbg2_BM (_.resultob));
  {
    objlock_BM (_.resultob);
    _.typob = objectcast_BM (objgetattr_BM (_.resultob, k_c_type));
    objunlock_BM (_.resultob);
  }
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation routprepob=%s rank#%d argtupv=%s bodyob=%s resultob=%s of type %s",
     objectdbg_BM (_.routprepob), rank,
     debug_outstr_value_BM (_.argtupv, CURFRAME_BM, 0),
     objectdbg1_BM (_.bodyob), objectdbg2_BM (_.resultob),
     objectdbg3_BM (_.typob));
  WEAKASSERT_BM (isobject_BM (_.resultob));
  int nbargs = tuplesize_BM (_.argtupv);
  {
    const char *routname = findobjectname_BM (_.routob);
    char routidbuf[32];
    memset (routidbuf, 0, sizeof (routidbuf));
    idtocbuf32_BM (objid_BM (_.routob), routidbuf);
    if (routname)
      objstrbufferprintfpayl_BM (_.modgenob, "\n\n"
                                 "value_tyBM crout%s_BM //#%d+\n"
                                 " (struct stackframe_stBM* stkf, // %s\n",
                                 routidbuf, rank, routname);
    else
      objstrbufferprintfpayl_BM (_.modgenob, "\n\n"
                                 "value_tyBM crout%s_BM //#%d\n"
                                 " (struct stackframe_stBM* stkf, //\n",
                                 routidbuf, rank);
    if (isstring_BM (_.commentv))
      {
        const char *combytes = bytstring_BM (_.commentv);
        int comlen = lenstring_BM (_.commentv);
        const char *eol = strchr (combytes, '\n');
        if (eol)
          comlen = eol - combytes - 1;
        if (comlen > 1)
          objstrbufferprintfpayl_BM (_.modgenob, "//!%.*s\n", comlen,
                                     combytes);
      }
    objstrbufferprintfpayl_BM (_.modgenob, "  // %d arguments\n", nbargs);
    for (int aix = 0; aix < 4; aix++)
      {
        if (aix < nbargs)
          objstrbufferprintfpayl_BM (_.modgenob,
                                     "  const value_tyBM arg%d,  // %s\n",
                                     aix,
                                     objectdbg_BM (tuplecompnth_BM
                                                   (_.argtupv, aix)));
        else
          objstrbufferprintfpayl_BM (_.modgenob,
                                     "  const value_tyBM arg%d_ __attribute__((unused)),\n",
                                     aix);
      };
    if (nbargs > 4)
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "  const quasinode_tyBM * restargs /* %d extrargs */)\n",
                                 nbargs - 4);
    else
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "  const quasinode_tyBM * restargs_ __attribute__((unused)))\n");
  }
  objstrbufferprintfpayl_BM (_.modgenob, "{ // start of %s\n",
                             objectdbg_BM (_.routob));
  objstrbufferprintfpayl_BM (_.modgenob,
                             "  struct frame%s_BMst {\n", routidbuf);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "    typedhead_tyBM stkfram_head;\n");
  objstrbufferprintfpayl_BM (_.modgenob,
                             "    struct stackframe_stBM *stkfram_prev;\n");
  objstrbufferprintfpayl_BM (_.modgenob,
                             "    objectval_tyBM *stkfram_descr;\n");
  objstrbufferprintfpayl_BM (_.modgenob, "    value_tyBM stkfram_callfun;\n");
  objstrbufferprintfpayl_BM (_.modgenob, "    int stkfram_state;\n");
  objstrbufferprintfpayl_BM (_.modgenob, "    int stkfram_extra;\n");
  unsigned nbval = setcardinal_BM (_.setvalv);
  objstrbufferprintfpayl_BM (_.modgenob, "    /// %d local values:\n", nbval);
  for (unsigned vix = 0; vix < nbval; vix++)
    {
      _.varob = setelemnth_BM (_.setvalv, vix);
      _.typob = NULL;
      DBGPRINTF_BM
        ("emit_definition°simple_routine_preparation routprepob=%s vix#%d value varob=%s",
         objectdbg_BM (_.routprepob), vix, objectdbg1_BM (_.varob));
      char varidbuf[32];
      memset (varidbuf, 0, sizeof (varidbuf));
      idtocbuf32_BM (objid_BM (_.varob), varidbuf);
      objlock_BM (_.varob);
      _.typob = objectcast_BM (objgetattr_BM (_.varob, k_c_type));
      objunlock_BM (_.varob);
      if (_.typob == k_value)
        objstrbufferprintfpayl_BM (_.modgenob,
                                   "    value_tyBM v%s; // %s\n",
                                   varidbuf, objectdbg_BM (_.varob));
      else if (_.typob == k_object)
        objstrbufferprintfpayl_BM (_.modgenob,
                                   "    objectval_tyBM* o%s; // %s\n",
                                   varidbuf, objectdbg_BM (_.varob));
      else
        {
          DBGPRINTF_BM
            ("emit_definition°simple_routine_preparation routprepob=%s vix#%d varob %s typob %s",
             objectdbg_BM (_.routprepob), vix, objectdbg1_BM (_.varob),
             objectdbg2_BM (_.typob));
          WEAKASSERT_BM (false && "unexpected type of variable");
        }
      _.varob = NULL;
      _.typob = NULL;
    }
  unsigned nbnum = setcardinal_BM (_.setnumv);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "    /// %d local numbers:\n", nbnum);
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation routprepob=%s nbnum=%d bodyob=%s",
     objectdbg_BM (_.routprepob), nbnum, objectdbg1_BM (_.bodyob));
  for (unsigned vix = 0; vix < nbnum; vix++)
    {
      _.varob = setelemnth_BM (_.setnumv, vix);
      _.typob = NULL;
      DBGPRINTF_BM
        ("emit_definition°simple_routine_preparation routprepob=%s vix#%d number varob=%s",
         objectdbg_BM (_.routprepob), vix, objectdbg1_BM (_.varob));
      char varidbuf[32];
      memset (varidbuf, 0, sizeof (varidbuf));
      idtocbuf32_BM (objid_BM (_.varob), varidbuf);
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "    intptr_t n%s; // %s\n",
                                 varidbuf, objectdbg_BM (_.varob));
    }
  objstrbufferprintfpayl_BM (_.modgenob, "   } _;\n");
  objstrbufferprintfpayl_BM (_.modgenob,
                             "   memset (&_, 0, sizeof(struct frame%s_BMst));\n",
                             routidbuf);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "   _.stkfram_head.htyp = typayl_StackFrame_BM;\n");
  objstrbufferprintfpayl_BM (_.modgenob, "   _.stkfram_head.hgc = 0;\n");
  objstrbufferprintfpayl_BM (_.modgenob,
                             "   _.stkfram_head.rlen = %d;\n", nbval);
  int kroutix = setelemindex_BM (_.setconstv, _.routob);
  WEAKASSERT_BM (kroutix >= 0);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "   _.stkfram_descr = "
                             CONSTOBARRPREFIX_BM "%s"
                             ROUTINESUFFIX_BM "[%d] /*|%s*/;\n",
                             modulidbuf, kroutix, objectdbg2_BM (_.routob));
  objstrbufferprintfpayl_BM (_.modgenob,
                             "   ASSERT_BM (!stkf\n"
                             "             || stkf->stkfram_pA.htyp == typayl_StackFrame_BM\n"
                             "             || stkf->stkfram_pA.htyp == typayl_SpecialFrame_BM);\n");
  objstrbufferprintfpayl_BM (_.modgenob, "   _.stkfram_prev = stkf;\n");
  //// emit the locking variables, if any
  if (_.setlockingv)
    {
      int nblocking = setcardinal_BM (_.setlockingv);
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "   // locking %d:\n", nblocking);
      DBGPRINTF_BM ("emit_definition°simple_routine_preparation routprepob=%s setlocking=%s nblocking=%d", objectdbg_BM (_.routprepob),        //
                    debug_outstr_value_BM (_.setlockingv, CURFRAME_BM, 0),      //
                    nblocking);
      for (int lkix = 0; lkix < nblocking; lkix++)
        {
          _.lockob = setelemnth_BM (_.setlockingv, lkix);
          _.varob = NULL;
          char *lockobnam = NULL;
          {
            ASSERT_BM (isobject_BM (_.lockob));
            objlock_BM (_.lockob);
            _.varob = objectcast_BM (objgetattr_BM (_.lockob, k_lockobj));
            objunlock_BM (_.lockob);
            if (isobject_BM (_.varob))
              lockobnam = findobjectname_BM (_.varob);
          }
          char lockidbuf[32];
          memset (lockidbuf, 0, sizeof (lockidbuf));
          idtocbuf32_BM (objid_BM (_.lockob), lockidbuf);
          if (lockobnam)
            objstrbufferprintfpayl_BM (_.modgenob,
                                       "    objectval_tyBM* locked%s = NULL; // for %s\n",
                                       lockidbuf, lockobnam);
          else
            objstrbufferprintfpayl_BM (_.modgenob,
                                       "    objectval_tyBM* locked%s = NULL; // for %s\n",
                                       lockidbuf, objectdbg_BM (_.varob));

        }
      _.lockob = NULL;
      _.varob = NULL;
    }
  //// emit the fetching of arguments
  objstrbufferprintfpayl_BM (_.modgenob,
                             "   // fetch %d arguments:\n", nbargs);
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation routprepob=%s nbargs=%d bodyob=%s",
     objectdbg_BM (_.routprepob), nbargs, objectdbg1_BM (_.bodyob));
  if (nbargs > 4)
    objstrbufferprintfpayl_BM (_.modgenob,
                               "   unsigned nbrestargs = treewidth_BM((value_tyBM)restargs);\n");
  for (int aix = 0; aix < nbargs; aix++)
    {
      _.varob = tuplecompnth_BM (_.argtupv, aix);
      char *varobnam = findobjectname_BM (_.varob);
      _.typob = NULL;
      DBGPRINTF_BM
        ("emit_definition°simple_routine_preparation routprepob=%s aix#%d arg varob=%s bodyob=%s",
         objectdbg_BM (_.routprepob), aix, objectdbg1_BM (_.varob),
         objectdbg2_BM (_.bodyob));
      objlock_BM (_.varob);
      _.typob = objectcast_BM (objgetattr_BM (_.varob, k_c_type));
      objunlock_BM (_.varob);
      char varidbuf[32];
      memset (varidbuf, 0, sizeof (varidbuf));
      idtocbuf32_BM (objid_BM (_.varob), varidbuf);
      DBGPRINTF_BM
        ("emit_definition°simple_routine_preparation routprepob=%s arg varob=%s |%s typob=%s aix#%d",
         objectdbg_BM (_.routprepob), objectdbg1_BM (_.varob),
         varidbuf, objectdbg2_BM (_.typob), aix);
      WEAKASSERT_BM (_.typob == k_value || _.typob == k_object);
      if (aix < 4)
        {
          if (_.typob == k_value)
            {
              if (varobnam)
                objstrbufferprintfpayl_BM (_.modgenob,
                                           "   _.v%s = arg%d; // %s\n",
                                           varidbuf, aix, varobnam);
              else
                objstrbufferprintfpayl_BM (_.modgenob, "   _.v%s = arg%d;\n",
                                           varidbuf, aix);
            }
          else if (_.typob == k_object)
            {
              if (varobnam)
                objstrbufferprintfpayl_BM (_.modgenob,
                                           "   _.o%s = objectcast_BM (arg%d); // %s\n",
                                           varidbuf, aix, varobnam);
              else
                objstrbufferprintfpayl_BM (_.modgenob,
                                           "   _.o%s = objectcast_BM (arg%d);\n",
                                           varidbuf, aix);
            }
          else
            {
              objstrbufferprintfpayl_BM (_.modgenob,
                                         "#error fail fetch #%d %s of type %s\n",
                                         aix, varidbuf,
                                         objectdbg_BM (_.typob));
              FAILHERE (makenode3_BM
                        (k_arguments, _.varob, _.typob, taggedint_BM (aix)));
            }
        }
      else
        {
          objstrbufferprintfpayl_BM (_.modgenob,
                                     "    if (nbrestargs > %d)\n", aix - 4);
          if (_.typob == k_value)
            {
              if (varobnam)
                objstrbufferprintfpayl_BM (_.modgenob,
                                           "    _.v%s = restargs->nodt_sons[%d]; // %s\n",
                                           varidbuf, aix - 4, varobnam);
              else
                objstrbufferprintfpayl_BM (_.modgenob,
                                           "    _.v%s = restargs->nodt_sons[%d];\n",
                                           varidbuf, aix - 4);
            }
          else if (_.typob == k_object)
            {
              if (varobnam)
                objstrbufferprintfpayl_BM (_.modgenob,
                                           "    _.o%s = objectcast_BM(restargs->nodt_sons[%d]); // %s\n",
                                           varidbuf, aix - 4, varobnam);
              else
                objstrbufferprintfpayl_BM (_.modgenob,
                                           "    _.o%s = objectcast_BM(restargs->nodt_sons[%d]);\n",
                                           varidbuf, aix - 4);
            }
          else
            {
              objstrbufferprintfpayl_BM (_.modgenob,
                                         "#error fail fetch xtra #%d %s of type %s\n",
                                         aix, varidbuf,
                                         objectdbg_BM (_.typob));
              FAILHERE (makenode3_BM
                        (k_arguments, _.varob, _.typob, taggedint_BM (aix)));
            }
        }
    }
  objstrbufferprintfpayl_BM (_.modgenob, "   // fetched %d arguments.\n",
                             nbargs);
  /// emit the fetching of closed values
  int nbclosed = sequencesize_BM (_.closedseqv);
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation routprepob=%s closedseq=%s nbclosed#%d",
     objectdbg_BM (_.routprepob), debug_outstr_value_BM (_.closedseqv,
                                                         CURFRAME_BM, 0),
     nbclosed);
  if (nbclosed == 0)
    objstrbufferprintfpayl_BM (_.modgenob, "   // no closed values in %s.\n",
                               objectdbg_BM (_.routob));
  else
    {
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "   { // fetch %d closed values in %s:\n",
                                 nbclosed, objectdbg_BM (_.routob));
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "   const closure_tyBM* callclos%s =\n",
                                 routidbuf);
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "     (stkf&&stkf->stkfram_pA.htyp == typayl_StackFrame_BM)\n");
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "     ? (closurecast_BM(stkf->stkfram_callfun)) : NULL;\n");
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "   unsigned nbclosed%s = closurewidth_BM ((const value_tyBM) callclos%s);\n",
                                 routidbuf, routidbuf);
      for (int clix = 0; clix < nbclosed; clix++)
        {
          _.varob = sequencenthcomp_BM (_.closedseqv, clix);
          char *varobnam = findobjectname_BM (_.varob);
          WEAKASSERT_BM (_.varob);
          objlock_BM (_.varob);
          _.typob = objectcast_BM (objgetattr_BM (_.varob, k_c_type));
          objunlock_BM (_.varob);
          DBGPRINTF_BM
            ("emit_definition°simple_routine_preparation routprepob=%s routob=%s clix#%d closed varob=%s typob=%s",
             objectdbg_BM (_.routprepob), objectdbg1_BM (_.routob), clix,
             objectdbg2_BM (_.varob), objectdbg3_BM (_.typob));
          char varidbuf[32];
          memset (varidbuf, 0, sizeof (varidbuf));
          idtocbuf32_BM (objid_BM (_.varob), varidbuf);
          objstrbufferprintfpayl_BM (_.modgenob, "   if (nbclosed%s > %d)\n",
                                     routidbuf, clix);
          if (_.typob == k_value)
            {
              if (varobnam)
                objstrbufferprintfpayl_BM (_.modgenob,
                                           "      _.v%s = callclos%s->nodt_sons[%d]; // %s\n",
                                           varidbuf, routidbuf, clix,
                                           varobnam);
              else
                objstrbufferprintfpayl_BM (_.modgenob,
                                           "      _.v%s = callclos%s->nodt_sons[%d];\n",
                                           varidbuf, routidbuf, clix);
            }
          else if (_.typob == k_object)
            {
              if (varobnam)
                objstrbufferprintfpayl_BM (_.modgenob,
                                           "      _.o%s = objectcast_BM (callclos%s->nodt_sons[%d]); // %s\n",
                                           varidbuf, routidbuf, clix,
                                           varobnam);
              else
                objstrbufferprintfpayl_BM (_.modgenob,
                                           "      _.o%s = objectcast_BM (callclos%s->nodt_sons[%d]);\n",
                                           varidbuf, routidbuf, clix);
            }
          else
            {
              objstrbufferprintfpayl_BM (_.modgenob,
                                         "#error unexpected type %s for closed %s\n"
                                         "      ;\n", objectdbg_BM (_.typob),
                                         varidbuf);
              FAILHERE (makenode3_BM
                        (k_closed, _.varob, _.typob, taggedint_BM (clix)));
            }
        }
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "   } // fetched %d closed values in %s.\n",
                                 nbclosed, routidbuf);
    }
  /// emit the body
  objstrbufferprintfpayl_BM (_.modgenob, "   // routine %s body:\n",
                             routidbuf);
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation routprepob=%s before emit_block bodyob=%s of %s",
     objectdbg_BM (_.routprepob), objectdbg1_BM (_.bodyob),
     objectdbg2_BM (objclass_BM (_.bodyob)));
  _.emitv = send3_BM (_.bodyob, k_emit_block, CURFRAME_BM,      //
                      _.modgenob, _.routprepob, taggedint_BM (0)        /*depth of block */
    );
  if (!_.emitv)
    FAILHERE (k_body);
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation routprepob=%s after emit_block bodyob=%s emitv=%s",
     objectdbg_BM (_.routprepob), objectdbg_BM (_.bodyob),
     debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
  objstrbuffersetindentpayl_BM (_.modgenob, 0);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob,
                             " epilog%s: __attribute__ ((unused)); // routine %s epilogue:\n",
                             routidbuf, routidbuf);
  if (_.setlockingv)
    {
      int nblocking = setcardinal_BM (_.setlockingv);
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "   // unlocking %d:\n", nblocking);
      DBGPRINTF_BM ("emit_definition°simple_routine_preparation epilogue routprepob=%s setlocking=%s nblocking=%d", objectdbg_BM (_.routprepob),       //
                    debug_outstr_value_BM (_.setlockingv, CURFRAME_BM, 0),      //
                    nblocking);
      for (int lkix = 0; lkix < nblocking; lkix++)
        {
          _.lockob = setelemnth_BM (_.setlockingv, lkix);
          _.varob = NULL;
          char lockidbuf[32];
          memset (lockidbuf, 0, sizeof (lockidbuf));
          idtocbuf32_BM (objid_BM (_.lockob), lockidbuf);
          {
            objlock_BM (_.lockob);
            _.varob = objectcast_BM (objgetattr_BM (_.lockob, k_lockobj));
            objunlock_BM (_.lockob);
          }
          if (_.varob)
            objstrbufferprintfpayl_BM (_.modgenob,
                                       "    if (locked%s != NULL)\n"
                                       "       objunlock_BM(locked%s), locked%s = NULL; // for %s\n",
                                       lockidbuf, lockidbuf, lockidbuf,
                                       objectdbg_BM (_.varob));
          else
            objstrbufferprintfpayl_BM (_.modgenob,
                                       "    if (locked%s != NULL)\n"
                                       "       objunlock_BM(locked%s), locked%s = NULL;\n",
                                       lockidbuf, lockidbuf, lockidbuf);

        }
      _.lockob = NULL;
      _.varob = NULL;
    }
  objstrbufferprintfpayl_BM (_.modgenob,
                             "   if (stkf) stkf->stkfram_callfun = NULL;\n");
  objstrbufferprintfpayl_BM (_.modgenob, "   return ");
  miniemit_var_BM (CURFRAME_BM, _.resultob, _.modgenob, _.routprepob,
                   _.routob, 0);
  objstrbufferprintfpayl_BM (_.modgenob,
                             ";\n" "} // end %s routine#%d %s\n\n\n",
                             routidbuf, rank, objectdbg_BM (_.routob));
  objunlock_BM (_.modgenob);
  DBGPRINTF_BM
    ("emit_definition°simple_routine_preparation end routprepob=%s",
     objectdbg_BM (_.routprepob));
  LOCALRETURN_BM (_.routprepob);
failure:
#undef FAILHERE
  DBGPRINTF_BM ("emit_definition°simple_routine_preparation failin %d routprep %s cause %s",   //
                failin, objectdbg_BM (_.routprepob),    //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode4_BM (k_emit_definition, _.routprepob, _.modgenob,
                               taggedint_BM (rank), _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_definition°simple_routine_preparation  _2Lk2DjTDzQh_3aTEVKDE2Ip */





/////
//emit_block°basiclo_block  _8UGpvfrcKbM_99IeP3BuxA5
extern objrout_sigBM ROUTINEOBJNAME_BM (_8UGpvfrcKbM_99IeP3BuxA5);
value_tyBM
ROUTINEOBJNAME_BM (_8UGpvfrcKbM_99IeP3BuxA5)    // emit_block°basiclo_block
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // blockob reciever
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_emit_block = BMK_6mk5eos8067_1odgCpnWMOj;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_8UGpvfrcKbM_99IeP3BuxA5,
                 objectval_tyBM * blockob;      //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * stmtob;       //
                 value_tyBM stmtv;      //
                 value_tyBM resultv;    //
                 value_tyBM emitv;      //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
    );
  _.blockob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  int failin = -1;
  char blockidbuf[32];
  memset (blockidbuf, 0, sizeof (blockidbuf));
  idtocbuf32_BM (objid_BM (_.blockob), blockidbuf);
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("emit_block°basiclo_block start blockob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.blockob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  WEAKASSERT_BM (isobject_BM (_.blockob));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.routprepob));
  WEAKASSERT_BM (istaggedint_BM (arg4));
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.modgenob));
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n"
                             "startblock_%s: __attribute__((unused));\n"
                             "{ /* +block %s */", blockidbuf, blockidbuf);
  int indepth = depth + 1;
  unsigned blocklen = objnbcomps_BM (_.blockob);
  for (unsigned insix = 0; insix < blocklen; insix++)
    {
      _.stmtv = objgetcomp_BM (_.blockob, insix);
      if (!_.stmtv)
        continue;
      _.stmtob = objectcast_BM (_.stmtv);
      DBGPRINTF_BM
        ("emit_block°basiclo_block blockob %s insix#%d stmtob %s of %s",
         objectdbg_BM (_.blockob), insix, objectdbg2_BM (_.stmtob),
         objectdbg3_BM (objclass_BM (_.stmtob)));
      if (!_.stmtob)
        FAILHERE (makenode2_BM (k_curcomp, _.stmtv, taggedint_BM (insix)));
      {
        objlock_BM (_.stmtob);
        objstrbuffersetindentpayl_BM (_.modgenob, indepth);
        objstrbuffernewlinepayl_BM (_.modgenob);
        if (objectisinstance_BM (_.stmtob, k_basiclo_statement))
          {
            DBGPRINTF_BM
              ("emit_block°basiclo_block blockob %s insix#%d stmtob %s is statement of %s",
               objectdbg_BM (_.blockob), insix,
               objectdbg1_BM (_.stmtob),
               objectdbg2_BM (objclass_BM (_.stmtob)));
            _.emitv = send3_BM (_.stmtob, k_emit_statement, CURFRAME_BM,        //
                                _.modgenob,
                                _.routprepob, taggedint_BM (indepth));
            objstrbuffernewlinepayl_BM (_.modgenob);
            if (!_.emitv)
              FAILHERE (makenode2_BM
                        (k_emit_statement, _.stmtob, taggedint_BM (insix)));
          }
        else if (objectisinstance_BM (_.stmtob, k_basiclo_block))
          {
            DBGPRINTF_BM
              ("emit_block°basiclo_block blockob %s insix#%d stmtob %s is block",
               objectdbg_BM (_.blockob), insix, objectdbg2_BM (_.stmtob));
            _.emitv = send3_BM (_.stmtob, k_emit_block, CURFRAME_BM,    //
                                _.modgenob,
                                _.routprepob, taggedint_BM (indepth));
            if (!_.emitv)
              FAILHERE (makenode2_BM (k_emit_block, _.stmtob,
                                      taggedint_BM (insix)));
          }
        else
          FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (insix), _.stmtob));
        objunlock_BM (_.stmtob);
      }
    }
  objstrbuffersetindentpayl_BM (_.modgenob, indepth);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "/* !endingblock %s */\n" "goto endblock_%s;\n"
                             "endblock_%s: ;\n", blockidbuf, blockidbuf,
                             blockidbuf);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, "} /*-block %s */\n", blockidbuf);
  DBGPRINTF_BM
    ("emit_block°basiclo_block end blockob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.blockob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  LOCALRETURN_BM (_.blockob);
failure:
  DBGPRINTF_BM ("emit_block°basiclo_block failin %d routprep %s cause %s", failin, objectdbg_BM (_.routprepob),        //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode4_BM (k_emit_block, _.blockob, _.routprepob,
                               _.modgenob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_block°basiclo_block _8UGpvfrcKbM_99IeP3BuxA5 */



// emit_block°basiclo_loop _56pDwW9peiP_8flH2fMQUnD

extern objrout_sigBM ROUTINEOBJNAME_BM (_56pDwW9peiP_8flH2fMQUnD);
value_tyBM
ROUTINEOBJNAME_BM (_56pDwW9peiP_8flH2fMQUnD)    //emit_block°basiclo_loop
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recvob - loop
 const value_tyBM arg2,         // modgenob 
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_emit_block = BMK_6mk5eos8067_1odgCpnWMOj;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_56pDwW9peiP_8flH2fMQUnD,
                 objectval_tyBM * blockob;      //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * stmtob;       //
                 value_tyBM stmtv;      //
                 value_tyBM resultv;    //
                 value_tyBM emitv;      //
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
    );
  _.blockob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  int failin = -1;
  char blockidbuf[32];
  memset (blockidbuf, 0, sizeof (blockidbuf));
  idtocbuf32_BM (objid_BM (_.blockob), blockidbuf);
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("emit_block°basiclo_loop start blockob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.blockob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  WEAKASSERT_BM (isobject_BM (_.blockob));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.routprepob));
  WEAKASSERT_BM (istaggedint_BM (arg4));
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.modgenob));
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n"
                             "startblock_%s: __attribute__((unused));\n"
                             "{ /* +loop %s */\n", blockidbuf, blockidbuf);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "  startloop_%s: __attribute__((unused));\n",
                             blockidbuf);
  int indepth = depth + 1;
  unsigned blocklen = objnbcomps_BM (_.blockob);
  for (unsigned insix = 0; insix < blocklen; insix++)
    {
      _.stmtv = objgetcomp_BM (_.blockob, insix);
      if (!_.stmtv)
        continue;
      _.stmtob = objectcast_BM (_.stmtv);
      DBGPRINTF_BM
        ("emit_block°basiclo_loop blockob %s insix#%d stmtob %s of %s",
         objectdbg_BM (_.blockob), insix, objectdbg2_BM (_.stmtob),
         objectdbg3_BM (objclass_BM (_.stmtob)));
      if (!_.stmtob)
        FAILHERE (makenode2_BM (k_curcomp, _.stmtv, taggedint_BM (insix)));

      {
        objlock_BM (_.stmtob);
        objstrbuffersetindentpayl_BM (_.modgenob, indepth);
        objstrbuffernewlinepayl_BM (_.modgenob);
        {
          objlock_BM (_.stmtob);
          objstrbuffersetindentpayl_BM (_.modgenob, indepth);
          objstrbuffernewlinepayl_BM (_.modgenob);
          if (objectisinstance_BM (_.stmtob, k_basiclo_statement))
            {
              DBGPRINTF_BM
                ("emit_block°basiclo_loop blockob %s insix#%d stmtob %s is statement",
                 objectdbg_BM (_.blockob), insix, objectdbg2_BM (_.stmtob));
              _.emitv = send3_BM (_.stmtob, k_emit_statement, CURFRAME_BM,      //
                                  _.modgenob,
                                  _.routprepob, taggedint_BM (indepth));
              objstrbuffernewlinepayl_BM (_.modgenob);
              if (!_.emitv)
                FAILHERE (makenode2_BM
                          (k_emit_statement, _.stmtob, taggedint_BM (insix)));
            }
          else if (objectisinstance_BM (_.stmtob, k_basiclo_block))
            {
              DBGPRINTF_BM
                ("emit_block°basiclo_loop blockob %s insix#%d stmtob %s is block",
                 objectdbg_BM (_.blockob), insix, objectdbg2_BM (_.stmtob));
              _.emitv = send3_BM (_.stmtob, k_emit_block, CURFRAME_BM,  //
                                  _.modgenob,
                                  _.routprepob, taggedint_BM (indepth));
              if (!_.emitv)
                FAILHERE (makenode2_BM (k_emit_block, _.stmtob,
                                        taggedint_BM (insix)));
            }
          else
            FAILHERE (makenode2_BM
                      (k_curcomp, taggedint_BM (insix), _.stmtob));
          objunlock_BM (_.stmtob);
        }
        objstrbuffernewlinepayl_BM (_.modgenob);
      }
      if (!_.emitv)
        FAILHERE (makenode1_BM (k_emit_statement, _.stmtob));
    }
  objstrbuffersetindentpayl_BM (_.modgenob, indepth);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "\n/* !endingloop %s */\n" "goto startloop_%s;\n"
                             "endblock_%s: __attribute__((unused));\n",
                             blockidbuf, blockidbuf, blockidbuf);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, "} /*-loop %s */\n", blockidbuf);
  DBGPRINTF_BM
    ("emit_block°basiclo_loop end blockob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.blockob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  LOCALRETURN_BM (_.blockob);
failure:
  DBGPRINTF_BM ("emit_block°basiclo_loop failin %d routprep %s cause %s", failin, objectdbg_BM (_.routprepob), //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode4_BM (k_emit_block, _.blockob, _.routprepob,
                               _.modgenob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_block°basiclo_loop _56pDwW9peiP_8flH2fMQUnD */



////////////////
// emit_statement°basiclo_cond _2gpamAdSc26_6d1JjCmKHyw

extern objrout_sigBM ROUTINEOBJNAME_BM (_2gpamAdSc26_6d1JjCmKHyw);
value_tyBM
ROUTINEOBJNAME_BM (_2gpamAdSc26_6d1JjCmKHyw)    //emit_statment°basiclo_cond 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // stmtob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_2gpamAdSc26_6d1JjCmKHyw,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * compob;       //
                 value_tyBM tmpv;       //
                 value_tyBM compv;      //
                 value_tyBM resultv;    //
                 value_tyBM emitv;      //            
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
    );
  objectval_tyBM *k_emit_when = BMK_8BRpelfZZnA_85HsuPjg0G7;
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_basiclo_when = BMK_3fvdRZNCmJS_5bTAPr83mXg;
  objectval_tyBM *k_emit_block = BMK_6mk5eos8067_1odgCpnWMOj;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_nb_conds = BMK_8dLpuaNoSGN_2tdmkpINCsu;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  _.stmtob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  WEAKASSERT_BM (istaggedint_BM (arg4));
  char condidbuf[32];
  memset (condidbuf, 0, sizeof (condidbuf));
  idtocbuf32_BM (objid_BM (_.stmtob), condidbuf);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  int depth = getint_BM (arg4);
  WEAKASSERT_BM (isobject_BM (_.stmtob));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.routprepob));
  DBGPRINTF_BM
    ("emit_statment°basiclo_cond start stmtob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.stmtob), objectdbg2_BM (_.modgenob),
     objectdbg3_BM (_.routprepob), depth);
  int nbconds = -1;
  int stmtsiz = objnbcomps_BM (_.stmtob);
  {
    _.tmpv = objgetattr_BM (_.stmtob, k_nb_conds);
    WEAKASSERT_BM (istaggedint_BM (_.tmpv));
    nbconds = getint_BM (_.tmpv);
    _.tmpv = NULL;
  }
  DBGPRINTF_BM
    ("emit_statment°basiclo_cond stmtob=%s nbconds=%d stmtsiz=%d condidbuf=%s",
     objectdbg_BM (_.stmtob), nbconds, stmtsiz, condidbuf);
  for (int ix = 0; ix < nbconds; ix++)
    {
      _.compv = objgetcomp_BM (_.stmtob, ix);
      if (!_.compv)
        continue;
      _.compob = objectcast_BM (_.compv);
      DBGPRINTF_BM
        ("emit_statment°basiclo_cond stmtob=%s ix#%d when compob=%s",
         objectdbg_BM (_.stmtob), ix, objectdbg2_BM (_.modgenob));
      if (!_.compob)
        FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (ix), _.compv));
      WEAKASSERT_BM (isobject_BM (_.compob));
      objlock_BM (_.compob);
      if (objectisinstance_BM (_.compob, k_basiclo_when))
        {
          if (ix > 0)
            objstrbufferprintfpayl_BM (_.modgenob, "else if ");
          else
            objstrbufferprintfpayl_BM (_.modgenob, "if /*cond %s*/ ",
                                       condidbuf);
          _.emitv = send3_BM (_.compob, k_emit_when, CURFRAME_BM,       //
                              _.modgenob, _.routprepob, taggedint_BM (depth));
          DBGPRINTF_BM
            ("emit_statment°basiclo_cond stmtob=%s compob=%s emit_when -> %s",
             objectdbg_BM (_.stmtob), objectdbg2_BM (_.compob),
             debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
          if (!_.emitv)
            FAILHERE (makenode2_BM (k_emit_when,
                                    taggedint_BM (ix), _.compob));
        }
      else
        FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (ix), _.compob));
      objunlock_BM (_.compob);
    }
  if (nbconds < stmtsiz)
    {
      int indepth = depth + 1;
      objstrbuffersetindentpayl_BM (_.modgenob, indepth);
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "else { /*cond else %s*/\n", condidbuf);
      for (int ix = nbconds; ix < stmtsiz; ix++)
        {
          _.compv = objgetcomp_BM (_.stmtob, ix);
          if (!_.compv)
            continue;
          _.compob = objectcast_BM (_.compv);
          if (!_.compob)
            FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (ix), _.compv));
          objlock_BM (_.compob);
          DBGPRINTF_BM
            ("emit_statment°basiclo_cond stmtob=%s ix#%d else compob=%s",
             objectdbg_BM (_.stmtob), ix, objectdbg2_BM (_.modgenob));
          WEAKASSERT_BM (isobject_BM (_.compob));
          if (objectisinstance_BM (_.compob, k_basiclo_block))
            {
              _.emitv = send3_BM (_.compob, k_emit_block, CURFRAME_BM,  //
                                  _.modgenob, _.routprepob,
                                  taggedint_BM (depth));
              DBGPRINTF_BM
                ("emit_statment°basiclo_cond stmtob=%s compob=%s emit_block -> %s",
                 objectdbg_BM (_.stmtob), objectdbg2_BM (_.compob),
                 debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
              if (!_.emitv)
                FAILHERE (makenode2_BM
                          (k_emit_block, taggedint_BM (ix), _.compob));
            }
          else if (objectisinstance_BM (_.compob, k_basiclo_statement))
            {
              _.emitv = send3_BM (_.compob, k_emit_statement, CURFRAME_BM,      //
                                  _.modgenob, _.routprepob,
                                  taggedint_BM (depth));
              DBGPRINTF_BM
                ("emit_statement°basiclo_cond stmtob=%s compob=%s emit_statment -> %s",
                 objectdbg_BM (_.stmtob), objectdbg2_BM (_.compob),
                 debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
              if (!_.emitv)
                FAILHERE (makenode2_BM
                          (k_emit_statement, taggedint_BM (ix), _.compob));
            }
          else
            FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (ix), _.compob));
          objunlock_BM (_.compob);
        }
      objstrbuffersetindentpayl_BM (_.modgenob, indepth);
      objstrbufferprintfpayl_BM (_.modgenob, "} /*cond else %s*/\n",
                                 condidbuf);
    }
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, "/*endcond %s*/\n", condidbuf);
  LOCALRETURN_BM (_.stmtob);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("emit_statment°basiclo_cond failin %d stmtob %s routprep %s cause %s", failin, objectdbg_BM (_.stmtob),        //
                objectdbg1_BM (_.routprepob),   //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode4_BM (k_emit_statement, _.stmtob, _.routprepob,
                               _.modgenob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_statment°basiclo_cond _2gpamAdSc26_6d1JjCmKHyw */


////////////////

// emit_statement°basiclo_while _6eRPTujgMx5_9mLxL25hmr9

extern objrout_sigBM ROUTINEOBJNAME_BM (_6eRPTujgMx5_9mLxL25hmr9);

value_tyBM
ROUTINEOBJNAME_BM (_6eRPTujgMx5_9mLxL25hmr9)    // emit_statement°basiclo_while
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // stmtob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  objectval_tyBM *k_emit_block = BMK_6mk5eos8067_1odgCpnWMOj;
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_while = BMK_7GNnckYYtcH_7wtOnPP4eKU;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_6eRPTujgMx5_9mLxL25hmr9,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * compob;       //
                 value_tyBM whilexpv;   //
                 value_tyBM compv;      //
                 value_tyBM tmpv;       //
                 value_tyBM resultv;    //
                 value_tyBM emitv;      //            
                 value_tyBM causev;     //
                 value_tyBM errorv;     //
    );
  _.stmtob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  WEAKASSERT_BM (istaggedint_BM (arg4));
  char condidbuf[32];
  memset (condidbuf, 0, sizeof (condidbuf));
  idtocbuf32_BM (objid_BM (_.stmtob), condidbuf);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  int depth = getint_BM (arg4);
  WEAKASSERT_BM (isobject_BM (_.stmtob));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.routprepob));
  char whilidbuf[32];
  memset (whilidbuf, 0, sizeof (whilidbuf));
  idtocbuf32_BM (objid_BM (_.stmtob), whilidbuf);
  _.whilexpv = objgetattr_BM (_.stmtob, k_while);
  DBGPRINTF_BM ("emit_statment°basiclo_while start stmtob=%s modgenob=%s routprepob=%s depth#%d whilexp %s", objectdbg_BM (_.stmtob), objectdbg2_BM (_.modgenob), objectdbg3_BM (_.routprepob), depth, //
                debug_outstr_value_BM (_.whilexpv, CURFRAME_BM, 0));
  if (!_.whilexpv)
    FAILHERE (k_while);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, "\n//// +while %s\n", whilidbuf);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "startblock_%s:  /*+!while*/;\n"
                             "{ /* +while %s */", whilidbuf, whilidbuf);
  int indepth = depth + 1;
  objstrbuffersetindentpayl_BM (_.modgenob, indepth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob, "if (!(/*while %s cond:*/ ",
                             whilidbuf);
  miniemit_expression_BM (CURFRAME_BM, _.whilexpv, _.modgenob, _.routprepob,
                          _.stmtob, indepth);
  objstrbufferprintfpayl_BM (_.modgenob, ")) //: testwhile %s failing\n",
                             whilidbuf);
  objstrbufferprintfpayl_BM (_.modgenob, "  goto endblock_%s; //failwhile\n",
                             whilidbuf);
  objstrbufferprintfpayl_BM (_.modgenob, "// while %s body:\n", whilidbuf);
  int stmtlen = objnbcomps_BM (_.stmtob);
  for (int cix = 0; cix < stmtlen; cix++)
    {
      _.compv = objgetcomp_BM (_.stmtob, cix);
      if (!_.compv)
        continue;
      _.compob = objectcast_BM (_.compv);
      _.emitv = NULL;
      objstrbuffersetindentpayl_BM (_.modgenob, indepth);
      DBGPRINTF_BM
        ("emit_statment°basiclo_while stmtob=%s cix#%d compob=%s routprepob=%s",
         objectdbg_BM (_.stmtob), cix, objectdbg1_BM (_.compob),
         objectdbg2_BM (_.routprepob));
      if (!_.compob)
        FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (cix), _.compv));
      objstrbufferprintfpayl_BM (_.modgenob, "// while %s comp#%d:\n",
                                 whilidbuf, cix);
      objlock_BM (_.compob);
      if (objectisinstance_BM (_.compob, k_basiclo_statement))
        {
          DBGPRINTF_BM
            ("emit_statement°basiclo_while stmtob=%s cix#%d compob=%s statement",
             objectdbg_BM (_.stmtob), cix, objectdbg1_BM (_.compob));
          _.emitv = send3_BM (_.compob, k_emit_statement, CURFRAME_BM,  //
                              _.modgenob,
                              _.routprepob, taggedint_BM (depth + 1));
        }
      else if (objectisinstance_BM (_.compob, k_basiclo_block))
        {
          DBGPRINTF_BM
            ("emit_statement°basiclo_while stmtob=%s cix#%d compob=%s block",
             objectdbg_BM (_.stmtob), cix, objectdbg1_BM (_.compob));
          _.emitv = send3_BM (_.compob, k_emit_block, CURFRAME_BM,      //
                              _.modgenob,
                              _.routprepob, taggedint_BM (depth + 1));
        }
      else
        FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (cix), _.compob));
      DBGPRINTF_BM
        ("emit_statement°basiclo_while stmtob=%s cix#%d compob=%s got emitv=%s",
         objectdbg_BM (_.stmtob), cix, objectdbg1_BM (_.compob),
         debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
      if (!_.emitv)
        FAILHERE (makenode2_BM (k_curcomp, taggedint_BM (cix), _.compob));
    }
  objstrbuffersetindentpayl_BM (_.modgenob, indepth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "goto startblock_%s; // repeatwhile\n",
                             whilidbuf);
  objstrbufferprintfpayl_BM (_.modgenob, "endblock_%s: /*endingwhile*/;\n",
                             whilidbuf);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, "} /*-endwhile %s */\n", whilidbuf);
  objstrbuffernewlinepayl_BM (_.modgenob);
  DBGPRINTF_BM
    ("emit_statement°basiclo_while end stmtob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  LOCALRETURN_BM (_.stmtob);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("emit_statment°basiclo_while failin %d stmtob %s routprep %s cause %s", failin, objectdbg_BM (_.stmtob),       //
                objectdbg1_BM (_.routprepob),   //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode4_BM (k_emit_statement, _.stmtob, _.routprepob,
                               _.modgenob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_statement°basiclo_while _6eRPTujgMx5_9mLxL25hmr9 */



////////////////

// emit_when°basiclo_when  _9Wk97VJLuH1_0FwsSpfatDg

extern objrout_sigBM ROUTINEOBJNAME_BM (_9Wk97VJLuH1_0FwsSpfatDg);
value_tyBM
ROUTINEOBJNAME_BM (_9Wk97VJLuH1_0FwsSpfatDg)    // emit_when°basiclo_when
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // whenob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_9Wk97VJLuH1_0FwsSpfatDg,
                 objectval_tyBM * whenob;       //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * compob;       //
                 value_tyBM tmpv;       //
                 value_tyBM compv;      //
                 value_tyBM resultv;    //
                 value_tyBM emitv;      //
                 value_tyBM causev;     //
                 value_tyBM testexpv;   //
                 value_tyBM errorv;     //
    );
  objectval_tyBM *k_emit_when = BMK_8BRpelfZZnA_85HsuPjg0G7;
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_emit_block = BMK_6mk5eos8067_1odgCpnWMOj;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_test = BMK_2j84OTHlFdJ_1pMyQfgsmAz;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  _.whenob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  WEAKASSERT_BM (istaggedint_BM (arg4));
  int depth = getint_BM (arg4);
  char whenidbuf[32];
  memset (whenidbuf, 0, sizeof (whenidbuf));
  idtocbuf32_BM (objid_BM (_.whenob), whenidbuf);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  WEAKASSERT_BM (isobject_BM (_.whenob));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.routprepob));
  _.testexpv = objgetattr_BM (_.whenob, k_test);
  DBGPRINTF_BM
    ("emit_when°basiclo_when start whenob=%s whenid=%s modgenob=%s routprepob=%s testexp=%s",
     objectdbg_BM (_.whenob), whenidbuf,
     objectdbg2_BM (_.modgenob), objectdbg3_BM (_.routprepob),
     debug_outstr_value_BM (_.testexpv, CURFRAME_BM, 0));
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  // whenob is locked by caller emit_statment°basiclo_cond
  objstrbufferprintfpayl_BM (_.modgenob, "/*when %s:*/\n (",
                             objectdbg_BM (_.whenob));
  miniemit_expression_BM (CURFRAME_BM, _.testexpv, _.modgenob,
                          _.routprepob, _.whenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, ") { //body when %s",
                             objectdbg_BM (_.whenob));
  int indepth = depth + 1;
  objstrbuffersetindentpayl_BM (_.modgenob, indepth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  int whenlen = objnbcomps_BM (_.whenob);
  DBGPRINTF_BM
    ("emit_when°basiclo_when whenob=%s whenlen=%d routprepob=%s",
     objectdbg_BM (_.whenob), whenlen, objectdbg1_BM (_.routprepob));
  for (int wix = 0; wix < whenlen; wix++)
    {
      _.compv = objgetcomp_BM (_.whenob, wix);
      if (!_.compv)
        continue;
      _.compob = objectcast_BM (_.compv);
      if (!_.compob)
        FAILHERE (makenode2_BM (k_curcomp, _.compv, taggedint_BM (wix)));
      DBGPRINTF_BM
        ("emit_when°basiclo_when whenob=%s wix#%d compob=%s of %s",
         objectdbg_BM (_.whenob), wix, objectdbg1_BM (_.compob),
         objectdbg2_BM (objclass_BM (_.compob)));
      if (objectisinstance_BM (_.compob, k_basiclo_block))
        {
          DBGPRINTF_BM
            ("emit_when°basiclo_when whenob=%s routprepob=%s before emit_block wix#%d compob=%s",
             objectdbg_BM (_.whenob), objectdbg1_BM (_.routprepob), wix,
             objectdbg2_BM (_.compob));
          _.emitv = send3_BM (_.compob, k_emit_block, CURFRAME_BM,      //
                              _.modgenob,
                              _.routprepob, taggedint_BM (depth + 1));
          DBGPRINTF_BM
            ("emit_when°basiclo_when whenob=%s after emit_block wix#%d compob=%s emitv=%s",
             objectdbg_BM (_.whenob), wix, objectdbg1_BM (_.compob),
             debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
          if (!_.emitv)
            FAILHERE (makenode2_BM (k_emit_block, _.compob,
                                    taggedint_BM (wix)));
        }
      else if (objectisinstance_BM (_.compob, k_basiclo_statement))
        {
          DBGPRINTF_BM
            ("emit_when°basiclo_when whenob=%s routprepob=%s before emit_statment wix#%d compob=%s",
             objectdbg_BM (_.whenob), objectdbg1_BM (_.routprepob), wix,
             objectdbg2_BM (_.compob));
          _.emitv = send3_BM (_.compob, k_emit_statement, CURFRAME_BM,  //
                              _.modgenob,
                              _.routprepob, taggedint_BM (depth + 1));
          DBGPRINTF_BM
            ("emit_when°basiclo_when whenob=%s after emit_statment wix#%d compob=%s emitv=%s",
             objectdbg_BM (_.whenob), wix, objectdbg1_BM (_.compob),
             debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
          if (!_.emitv)
            FAILHERE (makenode2_BM
                      (k_emit_statement, _.compob, taggedint_BM (wix)));
        }
      else
        FAILHERE (makenode2_BM (k_curcomp, _.compob, taggedint_BM (wix)));
    }
  objstrbuffersetindentpayl_BM (_.modgenob, indepth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob, "} //endwhen %s\n", whenidbuf);
  DBGPRINTF_BM ("emit_when°basiclo_when end whenob=%s",
                objectdbg_BM (_.whenob));
  LOCALRETURN_BM (_.whenob);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("emit_when°basiclo_when failin %d whenob %s routprep %s cause %s",     //
                failin, objectdbg_BM (_.whenob), objectdbg2_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode4_BM (k_emit_when, _.whenob, _.routprepob,
                               _.modgenob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_when°basiclo_when _9Wk97VJLuH1_0FwsSpfatDg */




extern void
miniemit_expression_BM (struct stackframe_stBM *stkf,
                        value_tyBM expv,
                        objectval_tyBM * modgenob,
                        objectval_tyBM * routprepob,
                        objectval_tyBM * fromob, int depth)
{
  objectval_tyBM *k_emit_expression = BMK_9lXSe7DrOl6_7hghYt0LhTF;
  //objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
  //objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  //objectval_tyBM *k_string = BMK_4T8am97muLl_5969SR22Ecq;
  objectval_tyBM *k_miniemit_node_conn = BMK_7L782rSgJBB_9vjsBdqAoz7;
  objectval_tyBM *k_variable = BMK_5ucAZimYynS_4VA0XHvr1nW;
  objectval_tyBM *k_basiclo_connective = BMK_3DQ7z3EuAiT_4faSRNsy2lr;
  objectval_tyBM *k_exclam = BMK_0e54seiZEXF_1Myf620cHoB;
  objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  objectval_tyBM *k_plain_module = BMK_8g1WBJBhDT9_1QK8IcuWYx2;
  objectval_tyBM *k_depth = BMK_17YdW6dWrBA_2mn4QmBjMNs;
  LOCALFRAME_BM (stkf, /*descr: */ k_emit_expression,
                 value_tyBM expv;       //
                 value_tyBM avalv;      //
                 objectval_tyBM * expob;        //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * modulob;      //
                 objectval_tyBM * typob;        //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * connob;       //
                 objectval_tyBM * indirconnob;  //
                 value_tyBM exclamv;    //
                 objectval_tyBM * exclamob;     //
                 value_tyBM errorv;     //
                 value_tyBM causev;     //
                 value_tyBM resv;       //
                 value_tyBM constantsv; //
    );
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.expv = expv;
  _.modgenob = objectcast_BM (modgenob);
  _.routprepob = objectcast_BM (routprepob);
  _.fromob = objectcast_BM (fromob);
  WEAKASSERTRET_BM (_.modgenob);
  WEAKASSERTRET_BM (_.routprepob);
  _.modulob = objgetattr_BM (_.modgenob, k_plain_module);
  DBGPRINTF_BM
    ("emit_expression start expv %s modgenob %s routprepob %s modulob %s depth %d",
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg_BM (_.modgenob), objectdbg1_BM (_.routprepob),
     objectdbg2_BM (_.modulob), depth);
  if (depth > MAXDEPTHPARSE_BM || depth < 0)
    FAILHERE (makenode1_BM (k_depth, taggedint_BM (depth)));
  int ke = valtype_BM (_.expv);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  switch (ke)
    {
    case tyNone_BM:
      objstrbufferprintfpayl_BM (_.modgenob, " NULL");
      LOCALJUSTRETURN_BM ();
    case tyInt_BM:
      objstrbufferprintfpayl_BM (_.modgenob, " %lld",
                                 (long long) getint_BM (_.expv));
      LOCALJUSTRETURN_BM ();
    case tyString_BM:
      objstrbufferappendcstrpayl_BM (_.modgenob, " \"");
      objstrbufferencodedcpayl_BM (_.modgenob, bytstring_BM (_.expv), -1);
      objstrbufferappendcstrpayl_BM (_.modgenob, "\"");
      LOCALJUSTRETURN_BM ();
    case tySet_BM:
      FAILHERE (BMP_set);
    case tyTuple_BM:
      FAILHERE (BMP_tuple);
    case tyClosure_BM:
      FAILHERE (BMP_closure);
    case tyUnspecified_BM:
      FAILHERE (BMP_unspecified);
#warning emit_expr very incomplete
    case tyObject_BM:
      {
        _.expob = objectcast_BM (_.expv);
        _.avalv = objassocgetattrpayl_BM (_.routprepob, _.expob);
        char varidbuf[32];
        memset (varidbuf, 0, sizeof (varidbuf));
        idtocbuf32_BM (objid_BM (_.expob), varidbuf);
        DBGPRINTF_BM ("emit_expr expob=%s avalv=%s routprepob=%s",
                      objectdbg_BM (_.expob),
                      debug_outstr_value_BM (_.avalv, CURFRAME_BM, 0),
                      objectdbg2_BM (_.routprepob));
        if (_.avalv != NULL)
          {
            _.typob =
              miniscan_var_BM (_.expob, _.routprepob, depth, _.fromob,
                               CURFRAME_BM);
            DBGPRINTF_BM ("emit_expr expob=%s avalv=%s typob=%s",
                          objectdbg_BM (_.expob),
                          debug_outstr_value_BM (_.avalv, CURFRAME_BM, 0),
                          objectdbg2_BM (_.typob));
            if (_.typob == BMP_value)
              {
                const char *varnam = findobjectname_BM (_.expob);
                if (varnam)
                  objstrbufferprintfpayl_BM (_.modgenob, " /*%s:*/_.v%s",
                                             varnam, varidbuf);
                else
                  objstrbufferprintfpayl_BM (_.modgenob, " _.v%s", varidbuf);
              }
            else if (_.typob == BMP_object)
              {
                if (isnode_BM (_.avalv)
                    && nodeconn_BM (_.avalv) == k_constants)
                  {
                    char modulidbuf[32];
                    memset (modulidbuf, 0, sizeof (modulidbuf));
                    idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
                    _.constantsv = objgetattr_BM (_.modgenob, k_constants);
                    WEAKASSERTRET_BM (isset_BM (_.constantsv));
                    int kix =
                      setelemindex_BM (setcast_BM (_.constantsv), _.expob);
                    WEAKASSERTRET_BM (kix >= 0);
                    objstrbufferprintfpayl_BM (_.modgenob,
                                               " (" CONSTOBARRPREFIX_BM "%s"
                                               ROUTINESUFFIX_BM
                                               "[%d] /*|%s*/)", modulidbuf,
                                               kix, objectdbg2_BM (_.expob));
                  }
                else
                  {
                    const char *varnam = findobjectname_BM (_.expob);
                    if (varnam)
                      objstrbufferprintfpayl_BM (_.modgenob, " /*%s:*/_.o%s",
                                                 varnam, varidbuf);
                    else
                      objstrbufferprintfpayl_BM (_.modgenob, " _.o%s",
                                                 varidbuf);
                  }
              }
            else if (_.typob == BMP_int)
              {
                const char *varnam = findobjectname_BM (_.expob);
                if (varnam)
                  objstrbufferprintfpayl_BM (_.modgenob, " /*%s:*/_.n%s",
                                             varnam, varidbuf);
                else
                  objstrbufferprintfpayl_BM (_.modgenob, " _.n%s", varidbuf);
              }
            else
              FAILHERE (makenode2_BM (k_variable, _.expob, _.typob));
            LOCALJUSTRETURN_BM ();
          }
        else
          {
            _.constantsv = objgetattr_BM (_.modgenob, k_constants);
            WEAKASSERTRET_BM (isset_BM (_.constantsv));
            int kix = setelemindex_BM (setcast_BM (_.constantsv), _.expob);
            if (kix >= 0)
              {
                char modulidbuf[32];
                memset (modulidbuf, 0, sizeof (modulidbuf));
                idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
                objstrbufferprintfpayl_BM (_.modgenob,
                                           " /*modconst:*/("
                                           CONSTOBARRPREFIX_BM "%s"
                                           ROUTINESUFFIX_BM "[%d] /*|%s*/)",
                                           modulidbuf, kix,
                                           objectdbg2_BM (_.expob));
                LOCALJUSTRETURN_BM ();
              }
            else
              FAILHERE (BMP_object);
          }
        break;
      }
    case tyNode_BM:
      {
        _.connob = nodeconn_BM (_.expv);
        objlock_BM (_.connob);
        unsigned arity = nodewidth_BM (_.expv);
        char modulidbuf[32];
        memset (modulidbuf, 0, sizeof (modulidbuf));
        idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
        DBGPRINTF_BM
          ("emit_expression connob %s arity %d routprepob %s modgenob %s fromob %s expv %s before",
           objectdbg_BM (_.connob), arity, objectdbg1_BM (_.routprepob),
           objectdbg2_BM (_.modgenob), objectdbg3_BM (_.fromob),
           debug_outstr_value_BM (_.expv, CURFRAME_BM, 0));
        if (_.connob == k_exclam && arity == 1)
          {
            _.exclamv = nodenthson_BM (_.expv, 0);
            if (isobject_BM (_.exclamv))
              {
                _.exclamob = (objectval_tyBM *) _.exclamv;
                _.constantsv = objgetattr_BM (_.modgenob, k_constants);
                WEAKASSERTRET_BM (isset_BM (_.constantsv));
                int kix =
                  setelemindex_BM (setcast_BM (_.constantsv), _.exclamob);
                DBGPRINTF_BM
                  ("emit_expression !exclamob %s, constants %s, kix=%d",
                   objectdbg_BM (_.exclamob), OUTSTRVALUE_BM (_.constantsv),
                   kix);
                WEAKASSERTRET_BM (kix >= 0);
                DBGPRINTF_BM
                  ("emit_expression !exclamob %s, constants[%d] is %s",
                   objectdbg_BM (_.exclamob), kix,
                   objectdbg1_BM (setelemnth_BM (_.constantsv, kix)));
                WEAKASSERTRET_BM (setelemnth_BM (_.constantsv, kix) ==
                                  _.exclamob);
                objstrbufferprintfpayl_BM (_.modgenob,
                                           " (" CONSTOBARRPREFIX_BM "%s"
                                           ROUTINESUFFIX_BM "[%d] /*!%s*/)",
                                           modulidbuf, kix,
                                           objectdbg_BM (_.exclamob));
              }
            else if (istaggedint_BM (_.exclamv))
              {
                intptr_t numexclam = getint_BM (_.exclamv);
                objstrbufferprintfpayl_BM (_.modgenob,
                                           " ((value_tyBM)%#llx /*!%lld*/)",
                                           (long long) _.exclamv,
                                           (long long) numexclam);
              }
            /// this should never happen, since we don't accept
            /// quotation of nil
            /// else if (_.exclamv == NULL)
            ///  objstrbufferprintfpayl_BM (_.modgenob,
            ///                             "(/*!__:*/(value_tyBM) NULL)");
            else
              WEAKASSERTRET_BM (false
                                &&
                                "unimplemented miniemit_expression_BM exclam");
          }
        else if (objectisinstance_BM (_.connob, k_basiclo_connective))
          {
            _.resv = send5_BM (_.connob, k_miniemit_node_conn,  //
                               CURFRAME_BM,     //
                               _.expv, _.modgenob, _.routprepob,
                               taggedint_BM (depth), _.fromob);
            DBGPRINTF_BM ("emit_expression miniscan_node_conn->%s done resv=%s",        //
                          objectdbg_BM (_.connob),      //
                          debug_outstr_value_BM (_.resv, CURFRAME_BM, 0));
            if (!_.resv)
              {
                objunlock_BM (_.connob);
                FAILHERE (NULL);
              }
          }
        else
          if ((_.indirconnob =
               objgetattr_BM (_.connob, k_basiclo_connective)) != NULL
              && objectisinstance_BM (_.indirconnob, k_basiclo_connective))
          {
            if (depth + 1 > MAXDEPTHPARSE_BM || depth < 0)
              FAILHERE (makenode2_BM
                        (k_depth, taggedint_BM (depth), _.indirconnob));
            objlock_BM (_.indirconnob);
            _.resv = send5_BM (_.indirconnob, k_miniemit_node_conn,     //
                               CURFRAME_BM,     //
                               _.expv, _.modgenob, _.routprepob,
                               taggedint_BM (depth + 1), _.fromob);
            DBGPRINTF_BM ("emit_expression miniscan_node_conn indirect %s done resv=%s",        //
                          objectdbg_BM (_.indirconnob), //
                          debug_outstr_value_BM (_.resv, CURFRAME_BM, 0));
            objunlock_BM (_.indirconnob);
            if (!_.resv)
              {
                objunlock_BM (_.connob);
                _.connob = NULL;
                FAILHERE (NULL);
              }
          }
        else
          FAILHERE (BMP_node);
        objunlock_BM (_.connob);
        LOCALJUSTRETURN_BM ();
      }
    default:
      FAILHERE (NULL);
    }
  DBGPRINTF_BM
    ("emit_expression unimplemented for expv %s modgen %s routprep %s",
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg_BM (_.modgenob), objectdbg1_BM (_.routprepob));
  WEAKASSERTRET_BM (false && "unimplemented miniemit_expression_BM");
#warning unimplemented miniemit_expression_BM
  LOCALJUSTRETURN_BM ();
failure:
#undef FAILHERE
  DBGPRINTF_BM ("miniemit_expression_BM failin %d expv %s routprep %s cause %s", failin, debug_outstr_value_BM (_.expv, CURFRAME_BM, 0), objectdbg2_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode4_BM (k_emit_expression, expv, _.routprepob,
                               _.modgenob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniemit_expression_BM */




void
miniemit_var_BM (struct stackframe_stBM *stkf,
                 objectval_tyBM * refob,
                 objectval_tyBM * modgenob,
                 objectval_tyBM * routprepob,
                 objectval_tyBM * fromob, int depth)
{
  objectval_tyBM *k_emit_reference = BMK_6qzzDyr2eIo_3SapnOUpg6S;
  objectval_tyBM *k_variable = BMK_5ucAZimYynS_4VA0XHvr1nW;
  //objectval_tyBM *k_int = BMK_0vgCFjXblkx_4zCMhMAWjVK;
  //objectval_tyBM *k_value = BMK_7bbeIqUSje9_4jVgC7ZJmvx;
  //objectval_tyBM *k_object = BMK_7T9OwSFlgov_0wVJaK1eZbn;
  LOCALFRAME_BM (stkf, /*descr: */ k_emit_reference,
                 objectval_tyBM * refob;        //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 value_tyBM avalv;      //
                 objectval_tyBM * connob;       //
                 objectval_tyBM * typob;        //
                 value_tyBM errorv;     //
                 value_tyBM causev;);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.refob = objectcast_BM (refob);
  _.modgenob = objectcast_BM (modgenob);
  _.routprepob = objectcast_BM (routprepob);
  _.fromob = objectcast_BM (fromob);
  WEAKASSERTRET_BM (_.refob);
  WEAKASSERTRET_BM (_.modgenob);
  WEAKASSERTRET_BM (_.routprepob);
  DBGPRINTF_BM
    ("miniemit_var_BM start refob %s modgen %s routprep %s depth %d",
     objectdbg_BM (_.refob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  _.avalv = objassocgetattrpayl_BM (_.routprepob, _.refob);
  DBGPRINTF_BM ("miniemit_var_BM refob %s avalv %s", objectdbg_BM (_.refob),    //
                debug_outstr_value_BM (_.avalv, CURFRAME_BM, 0));
  char varidbuf[32];
  memset (varidbuf, 0, sizeof (varidbuf));
  idtocbuf32_BM (objid_BM (_.refob), varidbuf);
  if (_.avalv != NULL)
    {
      _.typob =
        miniscan_var_BM (_.refob, _.routprepob, depth, _.fromob, CURFRAME_BM);
      DBGPRINTF_BM ("emit_var refob=%s avalv=%s typob=%s",
                    objectdbg_BM (_.refob),
                    debug_outstr_value_BM (_.avalv, CURFRAME_BM, 0),
                    objectdbg2_BM (_.typob));
      if (_.typob == BMP_value)
        {
          const char *varnam = findobjectname_BM (_.refob);
          if (varnam)
            objstrbufferprintfpayl_BM (_.modgenob, " /*%s:*/_.v%s", varnam,
                                       varidbuf);
          else
            objstrbufferprintfpayl_BM (_.modgenob, " _.v%s", varidbuf);
        }
      else if (_.typob == BMP_object)
        {
          const char *varnam = findobjectname_BM (_.refob);
          if (varnam)
            objstrbufferprintfpayl_BM (_.modgenob, " /*%s:*/_.o%s", varnam,
                                       varidbuf);
          else
            objstrbufferprintfpayl_BM (_.modgenob, " _.o%s", varidbuf);
        }
      else if (_.typob == BMP_int)
        {
          const char *varnam = findobjectname_BM (_.refob);
          if (varnam)
            objstrbufferprintfpayl_BM (_.modgenob, " /*%s:*/_.n%s", varnam,
                                       varidbuf);
          else
            objstrbufferprintfpayl_BM (_.modgenob, " _.n%s", varidbuf);
        }
      else
        FAILHERE (makenode3_BM (k_variable, _.refob, _.avalv, _.typob));
    }
  else
    FAILHERE (NULL);
  LOCALJUSTRETURN_BM ();
failure:
#undef FAILHERE
  DBGPRINTF_BM ("miniemit_var_BM failin %d ref %s routprep %s cause %s",        //
                failin, objectdbg_BM (_.refob), objectdbg1_BM (_.routprepob),   //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode4_BM (k_emit_reference, refob, _.routprepob,
                               _.modgenob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniemit_var_BM */



//  miniemit_node_conn°basiclo_primitive _0BaXSIhDAHO_9x6t4zdbUhj

extern objrout_sigBM ROUTINEOBJNAME_BM (_0BaXSIhDAHO_9x6t4zdbUhj);
value_tyBM
ROUTINEOBJNAME_BM (_0BaXSIhDAHO_9x6t4zdbUhj)    // miniemit_node_conn°basiclo_primitive
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // connob
 const value_tyBM arg2,         // expv
 const value_tyBM arg3,         // modgenob
 const value_tyBM arg4,         // routprepob
 const quasinode_tyBM * restargs)       // depth, fromob
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_0BaXSIhDAHO_9x6t4zdbUhj,
                 value_tyBM resultv;    //
                 objectval_tyBM * connob;       //
                 value_tyBM expv;       //
                 value_tyBM cursubexpv; //
                 value_tyBM connargsv;  //
                 value_tyBM conncexpansionv;    //
                 value_tyBM connchunkv; //
                 value_tyBM chunksonv;  //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * substob;      //
                 objectval_tyBM * varob;        //
                 objectval_tyBM * curargob;     //
                 objectval_tyBM * chunkob;      //
                 objectval_tyBM * emptybindhsetob;      //
                 value_tyBM errorv;     //
                 value_tyBM causev;);
  int depth = -1;
  objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  objectval_tyBM *k_cexpansion = BMK_7yoiT31GmV4_2iTjHx3P2hb;
  objectval_tyBM *k_chunk = BMK_3pQnBS9ZjkQ_0uGmqUUhAum;
  objectval_tyBM *k_assoc_object = BMK_6ZQ05nCv3Ys_8LA6B5LkZgm;
  objectval_tyBM *k_hset_object = BMK_8c9otZ4pwR6_55k81qyyYV2;
  objectval_tyBM *k_variable = BMK_5ucAZimYynS_4VA0XHvr1nW;
  objectval_tyBM *k_emit_expression = BMK_9lXSe7DrOl6_7hghYt0LhTF;
  objectval_tyBM *k_unbound_variable_error = BMK_68PQkZp1UAq_8RNb44Ea88z;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.connob = objectcast_BM (arg1);
  _.expv = arg2;
  _.modgenob = objectcast_BM (arg3);
  _.routprepob = objectcast_BM (arg4);
  unsigned nbrestargs = treewidth_BM ((value_tyBM) restargs);
  if (nbrestargs >= 2)
    {
      if (istaggedint_BM (restargs->nodt_sons[0]))
        depth = getint_BM (restargs->nodt_sons[0]);
      _.fromob = objectcast_BM (restargs->nodt_sons[1]);
    }
  WEAKASSERT_BM (_.connob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (_.routprepob);
  DBGPRINTF_BM
    ("miniemit_node_conn°basiclo_primitive start connob=%s expv=%s modgenob=%s\n"
     ".. routprepob=%s depth#%d fromob=%s", objectdbg_BM (_.connob),
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg1_BM (_.modgenob), objectdbg2_BM (_.routprepob), depth,
     objectdbg3_BM (_.fromob));
  _.connargsv = objgetattr_BM (_.connob, k_arguments);
  _.conncexpansionv = objgetattr_BM (_.connob, k_cexpansion);
  DBGPRINTF_BM ("miniemit_node_conn°basiclo_primitive connob=%s connargs=%s conncexpansion=%s",        //
                objectdbg_BM (_.connob),        //
                debug_outstr_value_BM
                (_.connargsv,
                 CURFRAME_BM,
                 0),
                debug_outstr_value_BM (_.conncexpansionv, CURFRAME_BM, 0));
  WEAKASSERT_BM (istuple_BM (_.connargsv));
  WEAKASSERT_BM (isnode_BM (_.conncexpansionv)
                 && nodeconn_BM (_.conncexpansionv) == k_chunk);
  unsigned nbargs = tuplesize_BM (_.connargsv);
  unsigned nbcexp = nodewidth_BM (_.conncexpansionv);
  _.substob = makeobj_BM ();
  objputclass_BM (_.substob, k_assoc_object);
  objputassocpayl_BM (_.substob, 3 * nbargs / 2 + 2);
  DBGPRINTF_BM
    ("miniemit_node_conn°basiclo_primitive connob=%s substob=%s nbargs=%d nbcexp=%d",
     objectdbg_BM (_.connob), objectdbg1_BM (_.substob), nbargs, nbcexp);
  for (unsigned aix = 0; aix < nbargs; aix++)
    {
      _.curargob = tuplecompnth_BM (_.connargsv, aix);
      _.cursubexpv = nodenthson_BM (_.expv, aix);
      DBGPRINTF_BM
        ("miniemit_node_conn°basiclo_primitive connob=%s aix#%d curargob=%s cursubexp=%s",
         objectdbg_BM (_.connob), aix, objectdbg1_BM (_.curargob),
         debug_outstr_value_BM (_.cursubexpv, CURFRAME_BM, 0));
      if (_.cursubexpv)
        objassocaddattrpayl_BM (_.substob, _.curargob, _.cursubexpv);
      else
        {
          if (!_.emptybindhsetob)
            {
              _.emptybindhsetob = makeobj_BM ();
              objputclass_BM (_.emptybindhsetob, k_hset_object);
              objputhashsetpayl_BM (_.emptybindhsetob, 5 * nbargs / 4 + 1);
            }
          objhashsetaddpayl_BM (_.emptybindhsetob, _.curargob);
        }
    };
  DBGPRINTF_BM
    ("miniemit_node_conn°basiclo_primitive connob=%s substob=%s emptybindhsetob=%s nbcexp#%d",
     objectdbg_BM (_.connob), objectdbg1_BM (_.substob),
     objectdbg2_BM (_.emptybindhsetob), nbcexp);
  for (unsigned cix = 0; cix < nbcexp; cix++)
    {
      _.chunksonv = nodenthson_BM (_.conncexpansionv, cix);
      if (isstring_BM (_.chunksonv))
        objstrbufferappendcstrpayl_BM (_.modgenob,
                                       bytstring_BM (_.chunksonv));
      else if (istaggedint_BM (_.chunksonv))
        objstrbufferprintfpayl_BM (_.modgenob, "%lld",
                                   (long long) getint_BM (_.chunksonv));
      else if (isobject_BM (_.chunksonv))
        {
          _.chunkob = (objectval_tyBM *) (_.chunksonv);
          DBGPRINTF_BM
            ("miniemit_node_conn°basiclo_primitive connob=%s cix#%d chunkob=%s",
             objectdbg_BM (_.connob), cix, objectdbg1_BM (_.chunkob));
          const char *chunkname = findobjectname_BM (_.chunkob);
          if (chunkname)
            objstrbufferappendcstrpayl_BM (_.modgenob, chunkname);
          else
            {
              char chunkidbuf[32];
              memset (chunkidbuf, 0, sizeof (chunkidbuf));
              idtocbuf32_BM (objid_BM (_.chunkob), chunkidbuf);
              objstrbufferappendcstrpayl_BM (_.modgenob, chunkidbuf);
            }
        }
      else
        if (isnode_BM (_.chunksonv)
            && nodeconn_BM (_.chunksonv) == k_variable
            && nodewidth_BM (_.chunksonv) == 1)
        {
          _.varob = objectcast_BM (nodenthson_BM (_.chunksonv, 0));
          WEAKASSERT_BM (_.varob);
          _.cursubexpv = objassocgetattrpayl_BM (_.substob, _.varob);
          if (_.cursubexpv)
            {
              miniemit_expression_BM (CURFRAME_BM, _.cursubexpv,
                                      _.modgenob,
                                      _.routprepob, _.fromob, depth + 1);
            }
          else if (objhashsetcontainspayl_BM (_.emptybindhsetob, _.varob))
            {
              objstrbufferprintfpayl_BM (_.modgenob, " NULL");
            }
          else
            {
              DBGPRINTF_BM
                ("miniemit_node_conn°basiclo_primitive connob=%s unbound varob=%s cix#%d fromob %s substob %s expv %s",
                 objectdbg_BM (_.connob), objectdbg1_BM (_.varob), cix,
                 objectdbg2_BM (_.fromob), objectdbg3_BM (_.substob),
                 debug_outstr_value_BM (_.expv, CURFRAME_BM, 0));
              FAILHERE (makenode4_BM
                        (k_unbound_variable_error, _.varob, _.expv, _.substob,
                         taggedint_BM (cix)));
            }
        }
      else
        FAILHERE (makenode2_BM (k_chunk, _.chunksonv, taggedint_BM (cix)));
    }
  DBGPRINTF_BM
    ("miniemit_node_conn°basiclo_primitive connob=%s exp=%s ended",
     objectdbg_BM (_.connob), debug_outstr_value_BM (_.expv, CURFRAME_BM, 0));
  LOCALRETURN_BM (_.connob);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("miniemit_node_conn°basiclo_primitive failin %d connob %s routprep %s cause %s",       //
                failin, objectdbg_BM (_.connob), objectdbg1_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode5_BM (k_emit_expression, _.connob, _.routprepob,
                               _.modgenob, _.expv, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniemit_node_conn°basiclo_primitive _0BaXSIhDAHO_9x6t4zdbUhj */




// miniemit_node_conn°basiclo_simple_connective _48l341uEMuG_3gJ2HHIwYhn

extern objrout_sigBM ROUTINEOBJNAME_BM (_48l341uEMuG_3gJ2HHIwYhn);
value_tyBM
ROUTINEOBJNAME_BM (_48l341uEMuG_3gJ2HHIwYhn)    //miniemit_node_conn°basiclo_simple_connective
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // connob
 const value_tyBM arg2,         // expv
 const value_tyBM arg3,         // modgenob
 const value_tyBM arg4,         // routprepob
 const quasinode_tyBM * restargs /*depth, fromob. */ )
{
  objectval_tyBM *k_emit_expression = BMK_9lXSe7DrOl6_7hghYt0LhTF;
  objectval_tyBM *k_miniemit_node_conn = BMK_7L782rSgJBB_9vjsBdqAoz7;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_48l341uEMuG_3gJ2HHIwYhn,
                 value_tyBM resultv; objectval_tyBM * connob; value_tyBM expv;  //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 value_tyBM funv;       //
                 value_tyBM errorv;     //
                 value_tyBM causev;);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM) (Cause); goto failure; } while(0)
  _.connob = objectcast_BM (arg1);
  _.expv = arg2;
  _.modgenob = objectcast_BM (arg3);
  _.routprepob = objectcast_BM (arg4);
  unsigned nbrestargs = treewidth_BM ((value_tyBM) restargs);
  int depth = 0;
  if (nbrestargs >= 2)
    {
      if (istaggedint_BM (restargs->nodt_sons[0]))
        depth = getint_BM (restargs->nodt_sons[0]);
      _.fromob = objectcast_BM (restargs->nodt_sons[1]);
    }
  WEAKASSERT_BM (_.connob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (_.routprepob);
  DBGPRINTF_BM
    ("miniemit_node_conn°basiclo_simple_connective start connob=%s expv=%s modgenob=%s\n"
     ".. routprepob=%s depth#%d fromob=%s", objectdbg_BM (_.connob),
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg1_BM (_.modgenob), objectdbg2_BM (_.routprepob), depth,
     objectdbg3_BM (_.fromob));
  objlock_BM (_.connob);
  _.funv = objgetattr_BM (_.connob, k_miniemit_node_conn);
  objunlock_BM (_.connob);
  if (!_.funv)
    FAILHERE (k_miniemit_node_conn);
  DBGPRINTF_BM
    ("miniemit_node_conn°basiclo_simple_connective connob %s has funv %s",
     objectdbg_BM (_.connob), debug_outstr_value_BM (_.funv, CURFRAME_BM, 0));
  if (!isobject_BM (_.funv) && !isclosure_BM (_.funv))
    FAILHERE (makenode1_BM (k_miniemit_node_conn, _.funv));
  _.resultv =
    apply5_BM (_.funv, CURFRAME_BM, _.expv, _.modgenob, _.routprepob,
               taggedint_BM (depth), _.fromob);
  DBGPRINTF_BM ("miniemit_node_conn°basiclo_simple_connective connob %s expv %s routprepob %s resultv %s",     //
                objectdbg_BM (_.connob),        //
                debug_outstr_value_BM (_.expv, CURFRAME_BM, 0), //
                objectdbg1_BM
                (_.routprepob),
                debug_outstr_value_BM (_.resultv, CURFRAME_BM, 0));
  if (!_.resultv)
    FAILHERE (_.funv);
  LOCALRETURN_BM (_.resultv);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("miniemit_node_conn°basiclo_simple_connective failin %d connob %s routprep %s cause %s",       //
                failin, objectdbg_BM (_.connob), objectdbg1_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode5_BM (k_emit_expression, _.connob, _.routprepob,
                               _.modgenob, _.expv, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniemit_node_conn°basiclo_simple_connective _48l341uEMuG_3gJ2HHIwYhn */

////////////////////////////////////////////////////////////////



// emit_statement°basiclo_assign _22wwtRd69oP_3IH6VRfTzu6
extern objrout_sigBM ROUTINEOBJNAME_BM (_22wwtRd69oP_3IH6VRfTzu6);
value_tyBM
ROUTINEOBJNAME_BM (_22wwtRd69oP_3IH6VRfTzu6)    //
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // stmtob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ BMK_22wwtRd69oP_3IH6VRfTzu6,
                 objectval_tyBM * stmtob;
                 objectval_tyBM * modgenob; objectval_tyBM * routprepob;
                 objectval_tyBM * destob; value_tyBM srcexpv;
                 value_tyBM resultv; value_tyBM errorv;
                 value_tyBM causev;);
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  _.stmtob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  WEAKASSERT_BM (_.stmtob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (arg4));
  int depth = getint_BM (arg4);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("emit_statement°basiclo_assign start stmtob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  WEAKASSERT_BM (objnbcomps_BM (_.stmtob) == 2);
  _.destob = objectcast_BM (objgetcomp_BM (_.stmtob, 0));
  _.srcexpv = objgetcomp_BM (_.stmtob, 1);
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("emit_statement°basiclo_assign start stmtob=%s destob=%s srcexpv=%s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.destob),
     debug_outstr_value_BM (_.srcexpv, CURFRAME_BM, 0));
  miniemit_var_BM (CURFRAME_BM, _.destob, _.modgenob,
                   _.routprepob, _.stmtob, 0);
  objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
  objstrbufferprintfpayl_BM (_.modgenob, " = //assign %s\n",
                             objectdbg_BM (_.stmtob));
  miniemit_expression_BM (CURFRAME_BM, _.srcexpv, _.modgenob,
                          _.routprepob, _.stmtob, 0);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, ";\n");
  LOCALRETURN_BM (_.stmtob);
#undef FAILHERE
failure:__attribute ((unused));
  DBGPRINTF_BM ("emit_statement°basiclo_assign failin %d stmtob %s routprep %s cause %s",      //
                failin, objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode5_BM (k_emit_statement, _.stmtob, _.routprepob,
                               _.modgenob, taggedint_BM (depth), _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_statement°basiclo_assign  _22wwtRd69oP_3IH6VRfTzu6 */



////
// emit_statement°basiclo_return 
extern objrout_sigBM ROUTINEOBJNAME_BM (_7DErEWkQBmz_5hPwF6ARmJ7);
value_tyBM
ROUTINEOBJNAME_BM (_7DErEWkQBmz_5hPwF6ARmJ7)    //emit_statement°basiclo_return 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // stmtob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  LOCALFRAME_BM (stkf, /*descr: */ NULL,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * retvarob;     //
                 objectval_tyBM * routob;       //
                 value_tyBM srcexpv;    //
                 value_tyBM resultv;    //
                 value_tyBM errorv;     //
                 value_tyBM causev;     //
    );
  //objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_return = BMK_2DH0ucElTgh_62vxjxLcfev;
  objectval_tyBM *k_prepare_routine = BMK_6qi1DW0Ygkl_4Aqdxq4n5IV;
  const objectval_tyBM *k_result = BMK_7bD9VtDkGSn_7lxHeYuuFLR;
  _.stmtob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  WEAKASSERT_BM (_.stmtob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (arg4));
  int depth = getint_BM (arg4);
  DBGPRINTF_BM
    ("emit_statement°basiclo_return start stmtob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  _.srcexpv = objgetattr_BM (_.stmtob, k_return);
  DBGPRINTF_BM ("emit_statement°basiclo_return stmtob=%s srcexpv=%s", objectdbg_BM (_.stmtob), //
                debug_outstr_value_BM (_.srcexpv, CURFRAME_BM, 0));
  // compute the retvarob from routprepob...
  _.routob = objgetattr_BM (_.routprepob, k_prepare_routine);
  _.retvarob = objgetattr_BM (_.routob, k_result);
  char routidbuf[32];
  memset (routidbuf, 0, sizeof (routidbuf));
  idtocbuf32_BM (objid_BM (_.routob), routidbuf);
  /// we could need a *null() primitive...
  DBGPRINTF_BM ("emit_statement°basiclo_return stmtob=%s routob=%s retvarob=%s", objectdbg_BM (_.stmtob),      //
                objectdbg_BM (_.routob),        //
                objectdbg_BM (_.retvarob));
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, "/*return %s:*/ ",
                             objectdbg_BM (_.stmtob));
  if (_.srcexpv)
    {
      DBGPRINTF_BM
        ("emit_statement°basiclo_return stmtob=%s routprepob=%s retvarob=%s srcexp=%s",
         objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),
         objectdbg2_BM (_.retvarob), debug_outstr_value_BM (_.srcexpv,
                                                            CURFRAME_BM, 0));
      miniemit_var_BM (CURFRAME_BM, _.retvarob, _.modgenob,
                       _.routprepob, _.stmtob, depth);
      objstrbufferprintfpayl_BM (_.modgenob, " = // returned\n");
      objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
      miniemit_expression_BM (CURFRAME_BM, _.srcexpv, _.modgenob,
                              _.routprepob, _.stmtob, depth);
      objstrbuffersetindentpayl_BM (_.modgenob, depth);
      objstrbufferprintfpayl_BM (_.modgenob, ";\n");
    }
  objstrbufferprintfpayl_BM (_.modgenob, " goto epilog%s;\n", routidbuf);
  LOCALRETURN_BM (_.stmtob);
}                               /* end emit_statement°basiclo_return _7DErEWkQBmz_5hPwF6ARmJ7 */



////////////////

// emit_statement°basiclo_run _0AUL5kbXVmq_06A8ZbHZi1Y

extern objrout_sigBM ROUTINEOBJNAME_BM (_0AUL5kbXVmq_06A8ZbHZi1Y);

value_tyBM
ROUTINEOBJNAME_BM (_0AUL5kbXVmq_06A8ZbHZi1Y)    //emit_statement°basiclo_run
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // stmtob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_run = BMK_4RFtYFUdfau_7Vm5jZ4Wm8e;
  objectval_tyBM *k_chunk = BMK_3pQnBS9ZjkQ_0uGmqUUhAum;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  objectval_tyBM *k_variable = BMK_5ucAZimYynS_4VA0XHvr1nW;
  objectval_tyBM *k_stmtid = BMK_5Z5WNOYHi9A_29s2a7qpJej;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_0AUL5kbXVmq_06A8ZbHZi1Y,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * routob;       //
                 objectval_tyBM * exitob;       //
                 objectval_tyBM * connob;       //
                 objectval_tyBM * varob;        //
                 value_tyBM runv;       //
                 value_tyBM compv;      //
                 value_tyBM errorv;     //
                 value_tyBM causev;     //
                 value_tyBM resultv;
    );
  _.stmtob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  WEAKASSERT_BM (_.stmtob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (arg4));
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM) (Cause); goto failure; } while(0)
  char stmtidbuf[32];
  memset (stmtidbuf, 0, sizeof (stmtidbuf));
  idtocbuf32_BM (objid_BM (_.stmtob), stmtidbuf);
  DBGPRINTF_BM
    ("emit_statement°basiclo_run start stmtob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob, "{ // run %s\n", stmtidbuf);
  _.runv = objgetattr_BM (_.stmtob, k_run);
  if (isnode_BM (_.runv) && ((_.connob = nodeconn_BM (_.runv)) == k_chunk))
    {
      DBGPRINTF_BM ("emit_statement°basiclo_run stmtob=%s chunk runv=%s",      //
                    objectdbg_BM (_.stmtob),    //
                    debug_outstr_value_BM (_.runv, CURFRAME_BM, 0));
      int chklen = nodewidth_BM (_.runv);
      for (int cix = 0; cix < chklen; cix++)
        {
          _.compv = nodenthson_BM (_.runv, cix);
          DBGPRINTF_BM ("emit_statement°basiclo_run stmtob=%s chunk cix#%d compv=%s", objectdbg_BM (_.stmtob), cix,    //
                        debug_outstr_value_BM (_.compv, CURFRAME_BM, 0));

          if (istaggedint_BM (_.compv))
            objstrbufferprintfpayl_BM (_.modgenob, "%lld",
                                       (long long) getint_BM (_.compv));
          else if (isstring_BM (_.compv))
            objstrbufferappendcstrpayl_BM (_.modgenob,
                                           bytstring_BM (_.compv));
          else if (isobject_BM (_.compv))
            {
              const char *compnam = findobjectname_BM (_.compv);
              if (compnam)
                objstrbufferappendcstrpayl_BM (_.modgenob, compnam);
              else
                {
                  char compidbuf[32];
                  memset (compidbuf, 0, sizeof (compidbuf));
                  idtocbuf32_BM (objid_BM ((objectval_tyBM *) _.compv),
                                 compidbuf);
                  objstrbufferappendcstrpayl_BM (_.modgenob, compidbuf);
                }
            }
          else if (isnode_BM (_.compv))
            {
              _.connob = nodeconn_BM (_.compv);
              int complen = nodewidth_BM (_.compv);
              if (_.connob == k_variable && complen == 1)
                {
                  _.varob = objectcast_BM (nodenthson_BM (_.compv, 0));
                  if (!_.varob)
                    {
                      WARNPRINTF_BM
                        ("in run statement %s component #%d : %s is not a variable",
                         objectdbg_BM (_.stmtob), cix,
                         OUTSTRVALUE_BM (_.compv));
                      FAILHERE (makenode3_BM
                                (k_variable, _.compv, taggedint_BM (cix),
                                 _.stmtob));
                    }
                  else if (_.varob == k_stmtid)
                    {
                      objstrbufferappendcstrpayl_BM (_.modgenob, stmtidbuf);
                    }
                  else
                    miniemit_expression_BM (CURFRAME_BM, _.varob, _.modgenob,
                                            _.routprepob, _.stmtob,
                                            depth + 1);
                }
              else
                {
                  WARNPRINTF_BM
                    ("in run statement %s component #%d : %s is some strange node",
                     objectdbg_BM (_.stmtob), cix, OUTSTRVALUE_BM (_.compv));
                  FAILHERE (makenode3_BM
                            (k_curcomp, _.compv, taggedint_BM (cix),
                             _.stmtob));
                }
            }
          else
            {
              WARNPRINTF_BM
                ("in run statement %s component #%d : %s unexpected",
                 objectdbg_BM (_.stmtob), cix, OUTSTRVALUE_BM (_.compv));
              FAILHERE (makenode3_BM
                        (k_curcomp, _.compv, taggedint_BM (cix), _.stmtob));
            }
        }
    }
  else if (_.runv)
    {
      DBGPRINTF_BM ("emit_statement°basiclo_run  stmtob=%s nonchunk runv=%s", objectdbg_BM (_.stmtob), //
                    debug_outstr_value_BM (_.runv, CURFRAME_BM, 0));
      miniemit_expression_BM (CURFRAME_BM, _.runv, _.modgenob, _.routprepob,
                              _.stmtob, depth + 1);
    }
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, ";\n} // end run %s\n", stmtidbuf);
  DBGPRINTF_BM
    ("emit_statement°basiclo_run end stmtob=%s", objectdbg_BM (_.stmtob));
  LOCALRETURN_BM (_.stmtob);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("emit_statement°basiclo_run failin %d stmtob %s routprep %s cause %s", //
                failin, objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode5_BM (k_emit_statement, _.stmtob, _.routprepob,
                               _.modgenob, taggedint_BM (depth), _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end  emit_statement°basiclo_run _0AUL5kbXVmq_06A8ZbHZi1Y */


////////////////

// emit_statement°basiclo_cexpansion _7CWfvQEHVOQ_1iBMi9mvgOY

extern objrout_sigBM ROUTINEOBJNAME_BM (_7CWfvQEHVOQ_1iBMi9mvgOY);

value_tyBM
ROUTINEOBJNAME_BM (_7CWfvQEHVOQ_1iBMi9mvgOY)    // emit_statement°basiclo_cexpansion
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // stmtob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  objectval_tyBM *k_assoc_object = BMK_6ZQ05nCv3Ys_8LA6B5LkZgm;
  objectval_tyBM *k_in = BMK_0eMGYofuNVh_8ZP2mXdhtHO;
  objectval_tyBM *k_origin = BMK_1xhcI0ZnQ6f_5xOLATXqawx;
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_expander = BMK_9OzBvYbDWm8_3XA4wkArOmo;
  objectval_tyBM *k_basiclo_cexpander = BMK_9pJUJ57N6RL_2nsXFzR6S3E;
  objectval_tyBM *k_cexpansion = BMK_7yoiT31GmV4_2iTjHx3P2hb;
  objectval_tyBM *k_chunk = BMK_3pQnBS9ZjkQ_0uGmqUUhAum;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  objectval_tyBM *k_results = BMK_5ve5gbSjN0r_1n61nNRPtnN;
  objectval_tyBM *k_arguments = BMK_0jFqaPPHgYH_5JpjOPxQ67p;
  objectval_tyBM *k_duplicate = BMK_2YrbiKQ6lxP_3KNUOnU6TF5;
  objectval_tyBM *k_variable = BMK_5ucAZimYynS_4VA0XHvr1nW;
  objectval_tyBM *k_stmtid = BMK_5Z5WNOYHi9A_29s2a7qpJej;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_7CWfvQEHVOQ_1iBMi9mvgOY,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * expandob;     //
                 objectval_tyBM * routob;       //
                 objectval_tyBM * substob;      //
                 objectval_tyBM * curesob;      //
                 objectval_tyBM * expresob;     //
                 objectval_tyBM * expargob;     //
                 objectval_tyBM * connob;       //
                 objectval_tyBM * varob;        //
                 value_tyBM cexpansionv;        //
                 value_tyBM expresultsv;        //
                 value_tyBM stmtresultsv;       //
                 value_tyBM expargsv;   //
                 value_tyBM curargexpv; //
                 value_tyBM stmtargsv;  //
                 value_tyBM compv;      //
                 value_tyBM errorv;     //
                 value_tyBM causev;     //
    );
  _.stmtob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.expandob = objectcast_BM (objgetattr_BM (_.stmtob, k_expander));
  DBGPRINTF_BM
    ("emit_statement°basiclo_cexpansion start stmtob=%s modgenob=%s routprepob=%s depth#%d expandob=%s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth, objectdbg3_BM (_.expandob));
  if (!_.expandob)
    FAILHERE (k_expander);
  objlock_BM (_.expandob);
  if (!objectisinstance_BM (_.expandob, k_basiclo_cexpander))
    FAILHERE (k_expander);
  _.expresultsv = objgetattr_BM (_.expandob, k_results);
  _.stmtresultsv = objgetattr_BM (_.stmtob, k_results);
  _.expargsv = objgetattr_BM (_.expandob, k_arguments);
  _.stmtargsv = objgetattr_BM (_.stmtob, k_arguments);
  _.cexpansionv = objgetattr_BM (_.expandob, k_cexpansion);
  _.substob = makeobj_BM ();
  objputattr_BM (_.substob, k_in, _.routprepob);
  objputattr_BM (_.substob, k_origin, _.stmtob);
  objputassocpayl_BM (_.substob,
                      5 * (tuplesize_BM (_.expargsv) +
                           tuplesize_BM (_.expresultsv)) / 4 + 2);
  objputclass_BM (_.substob, k_assoc_object);
  // bind the results in substob
  {
    int nbresults = tuplesize_BM (_.stmtresultsv);
    if (isobject_BM (_.expresultsv))
      {
        if (nbresults != 1)
          FAILHERE (makenode2_BM (k_results, _.expresultsv, _.stmtresultsv));
        objassocaddattrpayl_BM (_.substob, objectcast_BM (_.expresultsv),
                                tuplecompnth_BM (_.stmtresultsv, 0));
      }
    else if (istuple_BM (_.expresultsv))
      {
        if ((int) tuplesize_BM (_.expresultsv) != nbresults)
          FAILHERE (makenode2_BM (k_results, _.expresultsv, _.stmtresultsv));
        for (int rix = 0; rix < nbresults; rix++)
          {
            _.curesob = tuplecompnth_BM (_.stmtresultsv, rix);
            _.expresob = tuplecompnth_BM (_.expresultsv, rix);
            if (objassocgetattrpayl_BM (_.substob, _.expresob) != NULL)
              FAILHERE (makenode3_BM
                        (k_duplicate, _.expresob, _.curesob,
                         taggedint_BM (rix)));
            objassocaddattrpayl_BM (_.substob, _.expresob, _.curesob);
          }
      }
    else if (_.expresultsv || _.stmtresultsv)
      FAILHERE (makenode2_BM (k_results, _.expresultsv, _.stmtresultsv));
    _.curesob = NULL;
    _.expresob = NULL;
  }
  // bind the arguments in substob
  {
    int nbargs = nodewidth_BM (_.stmtargsv);
    if (nbargs == (int) tuplesize_BM (_.expargsv))
      {
      }
    else if (_.expargsv || _.stmtargsv)
      FAILHERE (makenode2_BM (k_arguments, _.expargsv, _.stmtargsv));
    for (int aix = 0; aix < nbargs; aix++)
      {
        _.curargexpv = nodenthson_BM (_.stmtargsv, aix);
        _.expargob = tuplecompnth_BM (_.expargsv, aix);
        if (objassocgetattrpayl_BM (_.substob, _.expargob) != NULL)
          FAILHERE (makenode3_BM
                    (k_duplicate, _.expargob, _.curargexpv,
                     taggedint_BM (aix)));
        objassocaddattrpayl_BM (_.substob, _.expargob, _.curargexpv);
      }
    _.curargexpv = NULL;
    _.expargob = NULL;
  }
  /// should emit the code chunk, using substob
  objunlock_BM (_.expandob);
  if (!isnode_BM (_.cexpansionv) || nodeconn_BM (_.cexpansionv) != k_chunk)
    FAILHERE (makenode1_BM (k_cexpansion, _.cexpansionv));
  {
    int chklen = nodewidth_BM (_.cexpansionv);
    char stmtidbuf[32];
    memset (stmtidbuf, 0, sizeof (stmtidbuf));
    idtocbuf32_BM (objid_BM (_.stmtob), stmtidbuf);
    objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
    objstrbufferprintfpayl_BM (_.modgenob, "{ // start cexpansion %s - %s\n",
                               stmtidbuf, objectdbg_BM (_.expandob));
    for (int cix = 0; cix < chklen; cix++)
      {
        _.compv = nodenthson_BM (_.cexpansionv, cix);
        DBGPRINTF_BM ("emit_statement°basiclo_cexpansion stmtob=%s chunk cix#%d compv=%s", objectdbg_BM (_.stmtob), cix,       //
                      debug_outstr_value_BM (_.compv, CURFRAME_BM, 0));
        if (istaggedint_BM (_.compv))
          objstrbufferprintfpayl_BM (_.modgenob, "%lld",
                                     (long long) getint_BM (_.compv));
        else if (isstring_BM (_.compv))
          objstrbufferappendcstrpayl_BM (_.modgenob, bytstring_BM (_.compv));
        else if (isobject_BM (_.compv))
          {
            const char *compnam = findobjectname_BM (_.compv);
            if (compnam)
              objstrbufferappendcstrpayl_BM (_.modgenob, compnam);
            else
              {
                char compidbuf[32];
                memset (compidbuf, 0, sizeof (compidbuf));
                idtocbuf32_BM (objid_BM ((objectval_tyBM *) _.compv),
                               compidbuf);
                objstrbufferappendcstrpayl_BM (_.modgenob, compidbuf);
              }
          }
        else if (isnode_BM (_.compv))
          {
            _.connob = nodeconn_BM (_.compv);
            int complen = nodewidth_BM (_.compv);
            if (_.connob == k_variable && complen == 1)
              {
                _.varob = nodenthson_BM (_.compv, 0);
                if (!_.varob)
                  FAILHERE (makenode2_BM
                            (k_variable, _.compv, taggedint_BM (cix)));
                if (_.varob == k_stmtid)
                  {
                    objstrbufferappendcstrpayl_BM (_.modgenob, stmtidbuf);
                  }
                else
                  {
                    _.expargob = objassocgetattrpayl_BM (_.substob, _.varob);
                    miniemit_expression_BM (CURFRAME_BM, _.expargob,
                                            _.modgenob, _.routprepob,
                                            _.stmtob, depth + 1);
                  }
              }
            else
              FAILHERE (makenode2_BM
                        (k_curcomp, _.compv, taggedint_BM (cix)));
          }
        else
          FAILHERE (makenode2_BM (k_curcomp, _.compv, taggedint_BM (cix)));
      }
    objstrbufferprintfpayl_BM (_.modgenob, ";\n} // end cexpansion %s - %s\n",
                               stmtidbuf, objectdbg_BM (_.expandob));
  }
  LOCALRETURN_BM (_.stmtob);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("emit_statement°basiclo_cexpansion failin %d stmtob %s routprep %s cause %s",  //
                failin, objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode6_BM (k_emit_statement, _.stmtob, _.routprepob,
                               _.modgenob, taggedint_BM (depth), _.expandob,
                               _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_statement°basiclo_cexpansion _7CWfvQEHVOQ_1iBMi9mvgOY */


////////////////

// emit_statement°basiclo_exit _4hS1jncZQAY_9pGS66eIlw9

extern objrout_sigBM ROUTINEOBJNAME_BM (_4hS1jncZQAY_9pGS66eIlw9);
value_tyBM
ROUTINEOBJNAME_BM (_4hS1jncZQAY_9pGS66eIlw9)    //emit_statement°basiclo_exit
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // stmtob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_exit = BMK_41gbFesxqzD_3l56OLiNdl2;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_4hS1jncZQAY_9pGS66eIlw9,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * routob;       //
                 objectval_tyBM * exitob;       //
                 value_tyBM errorv;     //
                 value_tyBM causev;     //
    );
  _.stmtob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("emit_statement°basiclo_exit start stmtob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  _.exitob = objectcast_BM (objgetattr_BM (_.stmtob, k_exit));
  if (!_.exitob)
    FAILHERE (k_exit);
  char exitidbuf[32];
  memset (exitidbuf, 0, sizeof (exitidbuf));
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, "// exit %s\n",
                             objectdbg_BM (_.stmtob));
  idtocbuf32_BM (objid_BM (_.exitob), exitidbuf);
  objstrbufferprintfpayl_BM (_.modgenob, "goto endblock_%s;\n", exitidbuf);
  LOCALRETURN_BM (_.exitob);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("emit_statement°basiclo_exit failin %d stmtob %s routprep %s cause %s",        //
                failin, objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode5_BM (k_emit_statement, _.stmtob, _.routprepob,
                               _.modgenob, taggedint_BM (depth), _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_statement°basiclo_exit _4hS1jncZQAY_9pGS66eIlw9 */



// emit_statement°basiclo_wrong _1EFhqSytjSK_9Uchza7qmUD

extern objrout_sigBM ROUTINEOBJNAME_BM (_1EFhqSytjSK_9Uchza7qmUD);
value_tyBM
ROUTINEOBJNAME_BM (_1EFhqSytjSK_9Uchza7qmUD)    //emit_statement°basiclo_wrong 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // stmtob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  //objectval_tyBM *k_wrong = BMK_2qtlhVU3gil_1SmwpjiT7Jm;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_1EFhqSytjSK_9Uchza7qmUD,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * routob;       //
                 value_tyBM subexpv;    //
                 value_tyBM firstsubexpv;       //
                 objectval_tyBM * subtypob;     //
                 value_tyBM resultv;    //
                 value_tyBM errorv;     //
                 value_tyBM causev;     //
    );
  _.stmtob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  bool gotmessage = false;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM) (Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("emit_statement°basiclo_wrong start stmtob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  WEAKASSERT_BM (_.stmtob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (arg4));
  int stmtlen = objnbcomps_BM (_.stmtob);
  _.firstsubexpv = objgetcomp_BM (_.stmtob, 0);
  char stmtidbuf[32];
  memset (stmtidbuf, 0, sizeof (stmtidbuf));
  idtocbuf32_BM (objid_BM (_.stmtob), stmtidbuf);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob, "{ // wrong %s\n", stmtidbuf);
  if (isstring_BM (_.firstsubexpv))
    {
      gotmessage = true;
      objstrbufferprintfpayl_BM (_.modgenob, "#error wrong %s: ", stmtidbuf);
      objstrbufferencodedcpayl_BM (_.modgenob,
                                   bytstring_BM (_.firstsubexpv),
                                   lenstring_BM (_.firstsubexpv));
      objstrbuffernewlinepayl_BM (_.modgenob);
    }
  else
    {
      objstrbuffernewlinepayl_BM (_.modgenob);
      objstrbufferprintfpayl_BM (_.modgenob, "#error wrong %s\n", stmtidbuf);
    }
  for (int ix = gotmessage ? 1 : 0; ix < stmtlen; ix++)
    {
      _.subexpv = objgetcomp_BM (_.stmtob, ix);
      _.subtypob =
        miniscan_expr_BM (_.subexpv, _.routprepob, depth, _.stmtob,
                          CURFRAME_BM);
      if (!_.subtypob)
        FAILHERE (makenode2_BM (k_curcomp, _.subexpv, taggedint_BM (ix)));
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "// wrong %s #%d typed %s:\n",
                                 stmtidbuf, ix, objectdbg_BM (_.subtypob));
      char *submsg =
        strdup (debug_outstr_value_BM (_.subexpv, CURFRAME_BM, 0));
      if (!submsg)
        FATAL_BM ("failed to strdup wrong %s arg #%d", stmtidbuf, ix);
      char *nextline = NULL;
      for (char *pc = submsg; pc != NULL && *pc != 0; pc = nextline)
        {
          nextline = NULL;
          const char *nl = strchr (pc, '\n');
          if (nl)
            nextline = (char *) nl + 1;
          const char *ret = strchr (pc, '\r');
          if (ret && ret < nextline)
            nextline = (char *) ret + 1;
          const char *ff = strchr (pc, '\f');
          if (ff && ff < nextline)
            nextline = (char *) ff + 1;
          if (nextline && nextline > submsg)
            nextline[-1] = (char) 0;
          objstrbufferprintfpayl_BM (_.modgenob, "//// %s\n", pc);
        }
      free (submsg);
    }
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob, "} // end wrong %s\n", stmtidbuf);
  LOCALRETURN_BM (_.stmtob);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("emit_statement°basiclo_wrong failin %d stmtob %s routprep %s cause %s",       //
                failin, objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode5_BM (k_emit_statement, _.stmtob, _.routprepob,
                               _.modgenob, taggedint_BM (depth), _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_statement°basiclo_wrong _1EFhqSytjSK_9Uchza7qmUD */





// emit_statement°basiclo_intswitch _273rNzykHOg_9NXqNHvVIHG

extern objrout_sigBM ROUTINEOBJNAME_BM (_273rNzykHOg_9NXqNHvVIHG);

value_tyBM
ROUTINEOBJNAME_BM (_273rNzykHOg_9NXqNHvVIHG)    //emit_statement°basiclo_intswitch
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // stmtob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_basiclo_when = BMK_3fvdRZNCmJS_5bTAPr83mXg;
  objectval_tyBM *k_default = BMK_0Ost4Do2yhq_95ticPFRmQO;
  objectval_tyBM *k_emit_block = BMK_6mk5eos8067_1odgCpnWMOj;
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_statement_properties = BMK_0OM3NoUpOBd_1nzwCJKw54A;
  objectval_tyBM *k_switch = BMK_5PJV21P82kA_2KfQTz95vdH;
  objectval_tyBM *k_when = BMK_7KdDnQYcbeY_4LbTWNwFIFY;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_273rNzykHOg_9NXqNHvVIHG,
                 value_tyBM resultv;    //
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * stmtpropob;   //
                 objectval_tyBM * propob;       //
                 objectval_tyBM * compob;       //
                 objectval_tyBM * curwhenob;    //
                 value_tyBM compv;      //
                 value_tyBM whensetv;   //
                 value_tyBM defaulttupv;        //
                 value_tyBM emitv;      //
                 value_tyBM propv;      //
                 value_tyBM switchexpv; //
                 value_tyBM keysnodv;   //
                 value_tyBM curkeyv;    //
                 value_tyBM errorv;     //
                 value_tyBM causev;     //
    );
  _.stmtob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM) (Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("emit_statement°basiclo_intswitch start stmtob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  WEAKASSERT_BM (_.stmtob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (arg4));
  _.stmtpropob =
    objectcast_BM (objgetattr_BM (_.routprepob, k_statement_properties));
  _.switchexpv = objgetattr_BM (_.stmtob, k_switch);
  WEAKASSERT_BM (_.stmtpropob);
  WEAKASSERT_BM (objhasassocpayl_BM (_.stmtpropob));
  _.propv = objassocgetattrpayl_BM (_.stmtpropob, _.stmtob);
  DBGPRINTF_BM
    ("emit_statement°basiclo_intswitch stmtob=%s (of %s) stmtpropob=%s (of %s) propv=%s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (objclass_BM (_.stmtob)),
     objectdbg2_BM (_.stmtpropob), objectdbg3_BM (objclass_BM (_.stmtpropob)),
     debug_outstr_value_BM (_.propv, CURFRAME_BM, 0));
  WEAKASSERT_BM (isobject_BM (_.propv));
  _.propob = objectcast_BM (_.propv);
  WEAKASSERT_BM (objhashashmapvalpayl_BM (_.propob));
  _.whensetv = objgetattr_BM (_.propob, k_when);
  _.defaulttupv = objgetattr_BM (_.propob, k_default);
  char stmtidbuf[32];
  memset (stmtidbuf, 0, sizeof (stmtidbuf));
  idtocbuf32_BM (objid_BM (_.stmtob), stmtidbuf);
  char stmtpref[16];
  memset (stmtpref, 0, sizeof (stmtpref));
  memcpy (stmtpref, stmtidbuf + 1, 8);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob, "{ // begin intswitch %s\n",
                             stmtidbuf);
  objstrbufferprintfpayl_BM (_.modgenob, " switch (");
  miniemit_expression_BM (CURFRAME_BM, _.switchexpv, _.modgenob,
                          _.routprepob, _.stmtob, depth + 1);
  objstrbufferprintfpayl_BM (_.modgenob, ") { // cases intswitch %s\n",
                             stmtidbuf);
  DBGPRINTF_BM ("emit_statement°basiclo_intswitch stmtob=%s propob=%s before nodeofkeys\n" "... whenset=%s defaulttup=%s",     //
                objectdbg_BM (_.stmtob), objectdbg1_BM (_.propob),
                debug_outstr_value_BM (_.whensetv, CURFRAME_BM, 0),
                debug_outstr_value_BM (_.defaulttupv, CURFRAME_BM, 0));
  _.keysnodv = objhashmapvalmakenodeofkeyspayl_BM (_.propob, BMP_node);
  DBGPRINTF_BM ("emit_statement°basiclo_intswitch stmtob=%s /%s propob=%s keysnodv=%s",        //
                objectdbg_BM (_.stmtob), stmtidbuf,     //
                objectdbg1_BM (_.propob),       //
                debug_outstr_value_BM (_.keysnodv, CURFRAME_BM, 0));
  int nbkeys = nodewidth_BM (_.keysnodv);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob, "// %d cases in intswitch %s\n",
                             nbkeys, stmtidbuf);
  for (int kix = 0; kix < nbkeys; kix++)
    {
      _.curkeyv = nodenthson_BM (_.keysnodv, kix);
      _.curwhenob =
        objectcast_BM (objhashmapvalgetpayl_BM (_.propob, _.curkeyv));
      WEAKASSERT_BM (istaggedint_BM (_.curkeyv));
      intptr_t curkeynum = getint_BM (_.curkeyv);
      DBGPRINTF_BM
        ("emit_statement°basiclo_intswitch stmtob=%s kix#%d curkeynum=%lld curwhenob=%s",
         objectdbg_BM (_.stmtob), kix, (long long) curkeynum,
         objectdbg1_BM (_.curwhenob));
      char whenidbuf[32];
      memset (whenidbuf, 0, sizeof (whenidbuf));
      idtocbuf32_BM (objid_BM (_.curwhenob), whenidbuf);
      objstrbuffersetindentpayl_BM (_.modgenob, depth);
      objstrbuffernewlinepayl_BM (_.modgenob);
      objstrbufferprintfpayl_BM (_.modgenob,
                                 " case %lld: goto whenint%s_%s;\n",
                                 (long long) curkeynum, stmtpref, whenidbuf);
    }
  DBGPRINTF_BM
    ("emit_statement°basiclo_intswitch stmtob=%s propob=%s routprepob=%s modgenob=%s incomplete",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.propob),
     objectdbg2_BM (_.routprepob), objectdbg3_BM (_.modgenob));
  int nbdef = tuplesize_BM (_.defaulttupv);
  objstrbufferprintfpayl_BM (_.modgenob,
                             " default:; // default intswitch %s: %d components\n",
                             stmtidbuf, nbdef);
  for (int dix = 0; dix < nbdef; dix++)
    {
      _.compob = tuplecompnth_BM (_.defaulttupv, dix);
      if (!_.compob)
        continue;
      _.emitv = NULL;
      objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
      objstrbuffernewlinepayl_BM (_.modgenob);
      DBGPRINTF_BM
        ("emit_statement°basiclo_intswitch stmtob=%s dix#%d compob=%s",
         objectdbg_BM (_.stmtob), dix, objectdbg1_BM (_.compob));
      objlock_BM (_.compob);
      if (objectisinstance_BM (_.compob, k_basiclo_statement))
        {
          DBGPRINTF_BM
            ("emit_statement°basiclo_intswitch stmtob=%s dix#%d compob=%s statement",
             objectdbg_BM (_.stmtob), dix, objectdbg1_BM (_.compob));
          _.emitv = send3_BM (_.compob, k_emit_statement, CURFRAME_BM,  //
                              _.modgenob,
                              _.routprepob, taggedint_BM (depth + 1));
        }
      else if (objectisinstance_BM (_.compob, k_basiclo_block))
        {
          DBGPRINTF_BM
            ("emit_statement°basiclo_intswitch stmtob=%s dix#%d compob=%s block",
             objectdbg_BM (_.stmtob), dix, objectdbg1_BM (_.compob));
          _.emitv = send3_BM (_.compob, k_emit_block, CURFRAME_BM,      //
                              _.modgenob,
                              _.routprepob, taggedint_BM (depth + 1));
        }
      else
        FAILHERE (makenode2_BM (k_default, taggedint_BM (dix), _.compob));
      DBGPRINTF_BM
        ("emit_statement°basiclo_intswitch stmtob=%s dix#%d compob=%s got emitv=%s",
         objectdbg_BM (_.stmtob), dix, objectdbg1_BM (_.compob),
         debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
      if (!_.emitv)
        FAILHERE (makenode2_BM (k_default, taggedint_BM (dix), _.compob));

      objunlock_BM (_.compob);
      _.compob = NULL;
    }
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob,
                             " break; // end default intswitch %s\n",
                             stmtidbuf);
  int nbwhen = setcardinal_BM (_.whensetv);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "// %d when cases of intswitch %s:\n",
                             nbwhen, stmtidbuf);
  for (int wix = 0; wix < nbwhen; wix++)
    {
      _.emitv = NULL;
      _.curwhenob = setelemnth_BM (_.whensetv, wix);
      objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
      objstrbuffernewlinepayl_BM (_.modgenob);
      DBGPRINTF_BM
        ("emit_statement°basiclo_intswitch stmtob=%s wix#%d curwhenob=%s routprepob=%s",
         objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.curwhenob),
         objectdbg2_BM (_.routprepob));
      char whenidbuf[32];
      memset (whenidbuf, 0, sizeof (whenidbuf));
      idtocbuf32_BM (objid_BM (_.curwhenob), whenidbuf);
      objstrbufferprintfpayl_BM (_.modgenob,
                                 " whenint%s_%s:;\n", stmtpref, whenidbuf);
      objlock_BM (_.curwhenob);
      WEAKASSERT_BM (objectisinstance_BM (_.curwhenob, k_basiclo_when));
      int whenlen = objnbcomps_BM (_.curwhenob);
      for (int cix = 0; cix < whenlen; cix++)
        {
          _.compob = NULL;
          _.compv = objgetcomp_BM (_.curwhenob, cix);
          if (!_.compv)
            continue;
          _.compob = objectcast_BM (_.compv);
          if (!_.compob)
            FAILHERE (makenode3_BM
                      (k_when, _.curwhenob, taggedint_BM (cix), _.compv));
          DBGPRINTF_BM
            ("emit_statement°basiclo_intswitch stmtob=%s wix#%d compob=%s cix#%d",
             objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.compob), cix);
          objlock_BM (_.compob);
          _.emitv = NULL;
          if (objectisinstance_BM (_.compob, k_basiclo_statement))
            {
              DBGPRINTF_BM
                ("emit_statement°basiclo_intswitch stmtob=%s cix#%d compob=%s statement",
                 objectdbg_BM (_.stmtob), cix, objectdbg1_BM (_.compob));
              _.emitv = send3_BM (_.compob, k_emit_statement, CURFRAME_BM,      //
                                  _.modgenob,
                                  _.routprepob, taggedint_BM (depth + 1));
            }
          else if (objectisinstance_BM (_.compob, k_basiclo_block))
            {
              DBGPRINTF_BM
                ("emit_statement°basiclo_intswitch stmtob=%s cix#%d compob=%s block",
                 objectdbg_BM (_.stmtob), cix, objectdbg1_BM (_.compob));
              _.emitv = send3_BM (_.compob, k_emit_block, CURFRAME_BM,  //
                                  _.modgenob,
                                  _.routprepob, taggedint_BM (depth + 1));
            }
          else
            FAILHERE (makenode3_BM
                      (k_when, _.curwhenob, taggedint_BM (cix), _.compob));
          DBGPRINTF_BM ("emit_statement°basiclo_intswitch stmtob=%s cix#%d compob=%s curwhenob=%s got emitv=%s", objectdbg_BM (_.stmtob), cix, objectdbg1_BM (_.compob), objectdbg2_BM (_.curwhenob),  //
                        debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
          if (!_.emitv)
            FAILHERE (makenode2_BM (k_default, taggedint_BM (cix), _.compob));

          objunlock_BM (_.compob);
          _.compob = NULL;
          _.compv = NULL;
        }
      objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
      objstrbuffernewlinepayl_BM (_.modgenob);
      objstrbufferprintfpayl_BM (_.modgenob, " break; // end when %s\n",
                                 whenidbuf);
      objunlock_BM (_.curwhenob);
      _.curwhenob = NULL;
    }
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob, "} } // end intswitch %s\n",
                             stmtidbuf);
  DBGPRINTF_BM
    ("emit_statement°basiclo_intswitch end stmtob=%s propob=%s routprepob=%s\n",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.propob),
     objectdbg2_BM (_.routprepob));
  LOCALRETURN_BM (_.propob);
#undef FAILHERE
failure:
  DBGPRINTF_BM ("emit_statement°basiclo_intswitch failin %d stmtob %s routprep %s cause %s",   //
                failin, objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode5_BM (k_emit_statement, _.stmtob, _.routprepob,
                               _.modgenob, taggedint_BM (depth), _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end  emit_statement°basiclo_intswitch _273rNzykHOg_9NXqNHvVIHG */




// emit_statement°basiclo_objswitch _9d7mulcEVXf_7ZymszyOWDY

extern objrout_sigBM ROUTINEOBJNAME_BM (_9d7mulcEVXf_7ZymszyOWDY);

value_tyBM
ROUTINEOBJNAME_BM (_9d7mulcEVXf_7ZymszyOWDY)    //emit_statement°basiclo_objswitch
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // stmtob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  //objectval_tyBM *k_basiclo_when = BMK_3fvdRZNCmJS_5bTAPr83mXg;
  objectval_tyBM *k_constants = BMK_5l2zSKsFaVm_9zs6qDOP87i;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  objectval_tyBM *k_default = BMK_0Ost4Do2yhq_95ticPFRmQO;
  objectval_tyBM *k_emit_block = BMK_6mk5eos8067_1odgCpnWMOj;
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_in = BMK_0eMGYofuNVh_8ZP2mXdhtHO;
  objectval_tyBM *k_plain_module = BMK_8g1WBJBhDT9_1QK8IcuWYx2;
  objectval_tyBM *k_statement_properties = BMK_0OM3NoUpOBd_1nzwCJKw54A;
  objectval_tyBM *k_switch = BMK_5PJV21P82kA_2KfQTz95vdH;
  objectval_tyBM *k_when = BMK_7KdDnQYcbeY_4LbTWNwFIFY;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_9d7mulcEVXf_7ZymszyOWDY,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * stmtpropob;   //
                 objectval_tyBM * propob;       //
                 objectval_tyBM * compob;       //
                 objectval_tyBM * curwhenob;    //
                 objectval_tyBM * curcaseob;    //
                 objectval_tyBM * switchob;     //
                 objectval_tyBM * modulob;      //
                 value_tyBM compv;      //
                 value_tyBM whensetv;   //
                 value_tyBM defaulttupv;        //
                 value_tyBM emitv;      //
                 value_tyBM propv;      //
                 value_tyBM switchexpv; //
                 value_tyBM keysnodv;   //
                 value_tyBM curkeyv;    //
                 value_tyBM curswitchv; //
                 value_tyBM setkeysv;   //
                 value_tyBM resultv;    //
                 value_tyBM constantsv; //
                 value_tyBM errorv;     //
                 value_tyBM causev;     //
    );
  _.stmtob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM) (Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("emit_statement°basiclo_intswitch start stmtob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  WEAKASSERT_BM (_.stmtob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (arg4));
  _.stmtpropob =
    objectcast_BM (objgetattr_BM (_.routprepob, k_statement_properties));
  _.constantsv = objgetattr_BM (_.modgenob, k_constants);
  _.switchexpv = objectcast_BM (objgetattr_BM (_.stmtob, k_switch));
  _.modulob = objgetattr_BM (_.modgenob, k_plain_module);
  WEAKASSERT_BM (_.stmtpropob);
  WEAKASSERT_BM (objhasassocpayl_BM (_.stmtpropob));
  WEAKASSERT_BM (_.modulob);
  char modulidbuf[32];
  memset (modulidbuf, 0, sizeof (modulidbuf));
  idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
  _.propv = objassocgetattrpayl_BM (_.stmtpropob, _.stmtob);
  DBGPRINTF_BM
    ("emit_statement°basiclo_objswitch stmtob=%s (of %s) stmtpropob=%s (of %s) propv=%s constantsv=%s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (objclass_BM (_.stmtob)),
     objectdbg2_BM (_.stmtpropob), objectdbg3_BM (objclass_BM (_.stmtpropob)),
     debug_outstr_value_BM (_.propv, CURFRAME_BM, 0),
     debug_outstr_value_BM (_.constantsv, CURFRAME_BM, 0));
  WEAKASSERT_BM (isobject_BM (_.propv));
  _.propob = objectcast_BM (_.propv);
  WEAKASSERT_BM (objhasassocpayl_BM (_.propob));
  _.whensetv = objgetattr_BM (_.propob, k_when);
  _.defaulttupv = objgetattr_BM (_.propob, k_default);
  _.switchexpv = objgetattr_BM (_.stmtob, k_switch);
  char stmtidbuf[32];
  memset (stmtidbuf, 0, sizeof (stmtidbuf));
  idtocbuf32_BM (objid_BM (_.stmtob), stmtidbuf);
  char stmtpref[16];
  memset (stmtpref, 0, sizeof (stmtpref));
  memcpy (stmtpref, stmtidbuf + 1, 8);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob, "{ // begin objswitch %s\n",
                             stmtidbuf);
  objstrbufferprintfpayl_BM (_.modgenob, " objectval_tyBM* objswexp%s = (",
                             stmtidbuf);
  miniemit_expression_BM (CURFRAME_BM, _.switchexpv, _.modgenob,
                          _.routprepob, _.stmtob, depth + 1);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, ");\n");
  memset (modulidbuf, 0, sizeof (modulidbuf));
  idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
  int nbwhen = setcardinal_BM (_.whensetv);
  int nbcases = objassocnbkeyspayl_BM (_.propob);
  unsigned long nbobjmod =
    1 << ILOG2_BM (2 * nbcases + nbwhen + nbcases / 2 + 10);
  DBGPRINTF_BM
    ("emit_statement°basiclo_objswitch stmtob=%s propob=%s nbwhen=%d nbcases=%d nbobjmod=%ld=%#lx",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.propob), nbwhen, nbcases,
     nbobjmod, nbobjmod);
  _.switchob = makeobj_BM ();
  objputattr_BM (_.switchob, k_in, _.propob);
  objputattr_BM (_.propob, k_switch, _.switchob);
  objtouchnow_BM (_.propob);
  objreservecomps_BM (_.switchob, nbobjmod);
  for (int ix = 0; ix < (int) nbobjmod; ix++)
    objappendcomp_BM (_.switchob, (value_tyBM) makeset_BM (NULL, 0));
  DBGPRINTF_BM
    ("emit_statement°basiclo_objswitch stmtob=%s switchob=%s",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.switchob));
  objstrbufferprintfpayl_BM (_.modgenob,
                             " switch (objecthash_BM (objswexp%s) %% %lu) {\n",
                             stmtidbuf, nbobjmod);
  _.setkeysv = (value_tyBM) objassocsetattrspayl_BM (_.propob);
  DBGPRINTF_BM ("emit_statement°basiclo_objswitch stmtob=%s setkeysv=%s",      //
                objectdbg_BM (_.stmtob),        //
                debug_outstr_value_BM (_.setkeysv, CURFRAME_BM, 0));
  WEAKASSERT_BM ((int) setcardinal_BM (_.setkeysv) == nbcases);
  for (int casix = 0; casix < nbcases; casix++)
    {
      _.curcaseob = setelemnth_BM (_.setkeysv, casix);
      ASSERT_BM (isobject_BM (_.curcaseob));
      unsigned hmod = objecthash_BM (_.curcaseob) % nbobjmod;
      _.curswitchv = objgetcomp_BM (_.switchob, hmod);
      DBGPRINTF_BM ("emit_statement°basiclo_objswitch stmtob=%s curcaseob=%s casix#%d hmod#%d old curswitch=%s",       //
                    objectdbg_BM (_.stmtob), objectdbg1_BM (_.curcaseob), casix, hmod,  //
                    debug_outstr_value_BM (_.curswitchv, CURFRAME_BM, 0));
      _.curswitchv =
        (value_tyBM) MAKESETCOLLECT_BM (_.curcaseob, _.curswitchv);
      objputcomp_BM (_.switchob, hmod, _.curswitchv);
      DBGPRINTF_BM ("emit_statement°basiclo_objswitch stmtob=%s casix#%d curcaseob=%s curswitch=%s", objectdbg_BM (_.stmtob), casix, objectdbg1_BM (_.curcaseob),      //
                    debug_outstr_value_BM (_.curswitchv, CURFRAME_BM, 0));
    }
  WEAKASSERT_BM (isset_BM (_.constantsv));
  for (int mix = 0; mix < (int) nbobjmod; mix++)
    {
      _.curswitchv = objgetcomp_BM (_.switchob, mix);
      if (!_.curswitchv || setcardinal_BM (_.curswitchv) == 0)
        continue;
      DBGPRINTF_BM ("emit_statement°basiclo_objswitch stmtob=%s mix#%d curswitch=%s", objectdbg_BM (_.stmtob), mix,    //
                    debug_outstr_value_BM (_.curswitchv, CURFRAME_BM, 0));
      objstrbufferprintfpayl_BM (_.modgenob, " case %d:\n", mix);
      // should iterate on the small set curswitchv
      WEAKASSERT_BM (isset_BM (_.curswitchv));
      int lenswitch = setcardinal_BM (_.curswitchv);
      for (int six = 0; six < lenswitch; six++)
        {
          _.curcaseob = setelemnth_BM (_.curswitchv, six);
          int kix = setelemindex_BM (setcast_BM (_.constantsv), _.curcaseob);
          char whenidbuf[32];
          memset (whenidbuf, 0, sizeof (whenidbuf));
          _.curwhenob = objassocgetattrpayl_BM (_.propob, _.curcaseob);
          idtocbuf32_BM (objid_BM (_.curwhenob), whenidbuf);
          DBGPRINTF_BM
            ("emit_statement°basiclo_objswitch stmtob=%s mix#%d curcaseob=%s kix#%d curwhenob=%s",
             objectdbg_BM (_.stmtob), mix, objectdbg1_BM (_.curcaseob), kix,
             objectdbg2_BM (_.curwhenob));
          WEAKASSERT_BM (kix >= 0);
          objstrbufferprintfpayl_BM (_.modgenob, "  if (objswexp%s == ",
                                     stmtidbuf);
          objstrbufferprintfpayl_BM (_.modgenob,
                                     " (" CONSTOBARRPREFIX_BM "%s"
                                     ROUTINESUFFIX_BM
                                     "[%d] /*|%s*/)) goto whenobj%s_%s;\n",
                                     modulidbuf, kix,
                                     objectdbg1_BM (_.curcaseob), stmtpref,
                                     whenidbuf);
        };
      objstrbufferprintfpayl_BM (_.modgenob, "  goto defobj%s;\n", stmtidbuf);
    }
  //// emit the default
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob, "  default: defobj%s:;\n",
                             stmtidbuf);
  objstrbuffernewlinepayl_BM (_.modgenob);
  int nbdef = tuplesize_BM (_.defaulttupv);
  for (int dfix = 0; dfix < nbdef; dfix++)
    {
      _.compob = tuplecompnth_BM (_.defaulttupv, dfix);
      if (!_.compob)
        continue;
      _.emitv = NULL;
      if (objectisinstance_BM (_.compob, k_basiclo_statement))
        {
          DBGPRINTF_BM
            ("emit_statement°basiclo_objswitch compob %s dfix#%d in stmtob %s is statement of %s",
             objectdbg_BM (_.compob), dfix,
             objectdbg1_BM (_.stmtob),
             objectdbg2_BM (objclass_BM (_.compob)));
          objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
          objstrbufferprintfpayl_BM (_.modgenob,
                                     " // objswitch %s default#%d statement:\n",
                                     stmtidbuf, dfix);
          _.emitv = send3_BM (_.compob, k_emit_statement, CURFRAME_BM,  //
                              _.modgenob,
                              _.routprepob, taggedint_BM (depth + 1));
          if (!_.emitv)
            FAILHERE (makenode2_BM
                      (k_emit_statement, _.compob, taggedint_BM (dfix)));
          objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
          objstrbuffernewlinepayl_BM (_.modgenob);
        }
      else if (objectisinstance_BM (_.compob, k_basiclo_block))
        {
          DBGPRINTF_BM
            ("emit_statement°basiclo_objswitch compob %s dfix#%d in stmtob %s is block of %s",
             objectdbg_BM (_.compob), dfix,
             objectdbg1_BM (_.stmtob),
             objectdbg2_BM (objclass_BM (_.compob)));
          objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
          objstrbufferprintfpayl_BM (_.modgenob,
                                     " // objswitch %s default#%d block:\n",
                                     stmtidbuf, dfix);
          _.emitv = send3_BM (_.compob, k_emit_block, CURFRAME_BM,      //
                              _.modgenob,
                              _.routprepob, taggedint_BM (depth + 1));
          if (!_.emitv)
            FAILHERE (makenode2_BM
                      (k_emit_block, _.compob, taggedint_BM (dfix)));
        }
      else
        FAILHERE (makenode2_BM (k_curcomp, _.compob, taggedint_BM (dfix)));
      DBGPRINTF_BM
        ("emit_statement°basiclo_objswitch compob %s dfix#%d in stmtob %s emitv=%s",
         objectdbg_BM (_.compob), dfix,
         objectdbg1_BM (_.stmtob), debug_outstr_value_BM (_.emitv,
                                                          CURFRAME_BM, 0));
    }
  objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "break; // end objswitch %s default\n",
                             stmtidbuf);
  //// emit the when-s
  objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "// objswitch %s with %d whens:\n",
                             stmtidbuf, nbwhen);
  for (int wix = 0; wix < nbwhen; wix++)
    {
      objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
      _.curwhenob = setelemnth_BM (_.whensetv, wix);
      char whenidbuf[32];
      memset (whenidbuf, 0, sizeof (whenidbuf));
      idtocbuf32_BM (objid_BM (_.curwhenob), whenidbuf);
      DBGPRINTF_BM
        ("emit_statement°basiclo_objswitch stmtob=%s wix#%d emit curwhenob=%s",
         objectdbg_BM (_.stmtob), wix, objectdbg1_BM (_.curwhenob));
      objstrbuffernewlinepayl_BM (_.modgenob);
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "whenobj%s_%s:; // when #%d of objswitch %s\n",
                                 stmtpref, whenidbuf, wix,
                                 objectdbg_BM (_.stmtob));
      int whenlen = objnbcomps_BM (_.curwhenob);
      for (int six = 0; six < whenlen; six++)
        {
          _.compob = NULL;
          _.compv = objgetcomp_BM (_.curwhenob, six);
          if (!_.compv)
            continue;
          _.compob = objectcast_BM (_.compv);
          if (!_.compob)
            FAILHERE (makenode3_BM
                      (k_curcomp, _.compv, taggedint_BM (six), _.curwhenob));
          objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
          _.emitv = NULL;
          if (objectisinstance_BM (_.compob, k_basiclo_statement))
            {
              DBGPRINTF_BM
                ("emit_statement°basiclo_objswitch compob %s six#%d in stmtob %s is statement of %s",
                 objectdbg_BM (_.compob), six,
                 objectdbg1_BM (_.stmtob),
                 objectdbg2_BM (objclass_BM (_.compob)));
              objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
              objstrbufferprintfpayl_BM (_.modgenob,
                                         " // objswitch %s when %s #%d statement:\n",
                                         stmtidbuf,
                                         objectdbg_BM (_.curwhenob), six);
              _.emitv = send3_BM (_.compob, k_emit_statement, CURFRAME_BM,      //
                                  _.modgenob,
                                  _.routprepob, taggedint_BM (depth + 1));
              if (!_.emitv)
                FAILHERE (makenode2_BM
                          (k_emit_statement, _.compob, taggedint_BM (six)));
              objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
              objstrbuffernewlinepayl_BM (_.modgenob);
            }
          else if (objectisinstance_BM (_.compob, k_basiclo_block))
            {
              DBGPRINTF_BM
                ("emit_statement°basiclo_objswitch compob %s six#%d in stmtob %s is block of %s",
                 objectdbg_BM (_.compob), six,
                 objectdbg1_BM (_.stmtob),
                 objectdbg2_BM (objclass_BM (_.compob)));
              objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
              objstrbufferprintfpayl_BM (_.modgenob,
                                         " // objswitch %s when %s #%d block:\n",
                                         stmtidbuf,
                                         objectdbg_BM (_.curwhenob), six);
              _.emitv = send3_BM (_.compob, k_emit_block, CURFRAME_BM,  //
                                  _.modgenob,
                                  _.routprepob, taggedint_BM (depth + 1));
              if (!_.emitv)
                FAILHERE (makenode2_BM
                          (k_emit_block, _.compob, taggedint_BM (six)));
            }
          else                  // should not happen
            FAILHERE (makenode3_BM
                      (k_curcomp, _.compob, taggedint_BM (six), _.curwhenob));
          DBGPRINTF_BM
            ("emit_statement°basiclo_objswitch done compob %s six#%d in stmtob %s wix#%d curwhenob %s\n",
             objectdbg_BM (_.compob), six, objectdbg1_BM (_.stmtob), wix,
             objectdbg2_BM (_.curwhenob));
        }
      DBGPRINTF_BM
        ("emit_statement°basiclo_objswitch done in stmtob %s wix#%d curwhenob %s\n",
         objectdbg1_BM (_.stmtob), wix, objectdbg2_BM (_.curwhenob));
      objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
      objstrbuffernewlinepayl_BM (_.modgenob);
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "break; // end when %s #%d of objswitch %s\n",
                                 objectdbg_BM (_.curwhenob), wix,
                                 objectdbg1_BM (_.stmtob));
    }                           /* end for wix */
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "} } // end objswitch %s\n",
                             objectdbg1_BM (_.stmtob));
  DBGPRINTF_BM
    ("emit_statement°basiclo_objswitch end stmtob %s\n",
     objectdbg_BM (_.stmtob));
  LOCALRETURN_BM (_.stmtob);
failure:
#undef FAILHERE
  DBGPRINTF_BM ("emit_statement°basiclo_objswitch failin %d stmtob %s routprep %s cause %s",   //
                failin, objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode5_BM (k_emit_statement, _.stmtob, _.routprepob,
                               _.modgenob, taggedint_BM (depth), _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end emit_statement°basiclo_objswitch  _9d7mulcEVXf_7ZymszyOWDY */


// emit_statement°basiclo_fail _8XIt55nuPul_3MZfto9hmgy

extern objrout_sigBM ROUTINEOBJNAME_BM (_8XIt55nuPul_3MZfto9hmgy);

value_tyBM
ROUTINEOBJNAME_BM (_8XIt55nuPul_3MZfto9hmgy)    // emit_statement°basiclo_fail
(struct stackframe_stBM * stkf, //
 const value_tyBM stmtarg,      //
 const value_tyBM modgenarg,    //
 const value_tyBM routpreparg,  //
 const value_tyBM deptharg,     //
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  //objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_fail = BMK_085lT8c13Ik_11pcWJfcLeM;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_8XIt55nuPul_3MZfto9hmgy,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 value_tyBM failexpv;   //
                 value_tyBM resultv;    //
    );
  _.stmtob = objectcast_BM (stmtarg);
  _.modgenob = objectcast_BM (modgenarg);
  _.routprepob = objectcast_BM (routpreparg);
  int depth = getint_BM (deptharg);
  DBGPRINTF_BM
    ("emit_statement°basiclo_fail start stmtob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  WEAKASSERT_BM (_.stmtob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (deptharg));
  _.failexpv = objgetattr_BM (_.stmtob, k_fail);
  objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
  objstrbufferprintfpayl_BM (_.modgenob, "//failure %s\n",
                             objectdbg_BM (_.stmtob));
  objstrbufferprintfpayl_BM (_.modgenob,
                             "PLACEDFAILURE_BM(__LINE__,\n          /*failreason:*/ (");
  miniemit_expression_BM (CURFRAME_BM, _.failexpv, _.modgenob, _.routprepob,
                          _.stmtob, 0);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "),\n                /*failplace:*/ (");
  miniemit_expression_BM (CURFRAME_BM, (value_tyBM) _.stmtob, _.modgenob,
                          _.routprepob, _.stmtob, 0);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "),\n                ((struct stackframe_stBM *) &_));\n");
  LOCALRETURN_BM (_.stmtob);
}                               /* end emit_statement°basiclo_fail _8XIt55nuPul_3MZfto9hmgy */


////////////////
// emit_block°basiclo_lockobj  _5XbwuHte8rl_1KjFdwMeolr

extern objrout_sigBM ROUTINEOBJNAME_BM (_5XbwuHte8rl_1KjFdwMeolr);

value_tyBM
ROUTINEOBJNAME_BM (_5XbwuHte8rl_1KjFdwMeolr)    //emit_block°basiclo_lockobj 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // stmtob
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs_ __attribute__ ((unused)))
{
  objectval_tyBM *k_locking = BMK_8yqFC2Qz7I2_7KoZMWLE0U3;
  objectval_tyBM *k_lockobj = BMK_9dso3pFLYwm_3JwHqiJK3UL;
  objectval_tyBM *k_curcomp = BMK_12cTZAaLTTx_4Bq4ez6eGJM;
  objectval_tyBM *k_basiclo_block = BMK_4bYUiDmxrKK_6nPPlEl8y8x;
  objectval_tyBM *k_basiclo_statement = BMK_4lKK08v9A0t_0GGsir35UxP;
  objectval_tyBM *k_emit_statement = BMK_1ERH9PxNhPb_2o869yOMuH0;
  objectval_tyBM *k_emit_block = BMK_6mk5eos8067_1odgCpnWMOj;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_5XbwuHte8rl_1KjFdwMeolr,
                 objectval_tyBM * stmtob;       //
                 objectval_tyBM * modgenob;     //
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * stmtpropob;   //
                 objectval_tyBM * propob;       //
                 objectval_tyBM * compob;       //
                 value_tyBM compv;      //
                 value_tyBM resultv;    //
                 value_tyBM locksetv;   //
                 value_tyBM lobexpv;    //
                 value_tyBM errorv;     //
                 value_tyBM causev;     //
                 value_tyBM emitv;      //
    );
  _.stmtob = objectcast_BM (arg1);
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM) (Cause); goto failure; } while(0)
  DBGPRINTF_BM
    ("emit_block°basiclo_lockobj start stmtob=%s modgenob=%s routprepob=%s depth#%d",
     objectdbg_BM (_.stmtob), objectdbg1_BM (_.modgenob),
     objectdbg2_BM (_.routprepob), depth);
  WEAKASSERT_BM (_.stmtob);
  WEAKASSERT_BM (_.modgenob);
  WEAKASSERT_BM (_.routprepob);
  WEAKASSERT_BM (istaggedint_BM (arg4));
  _.locksetv = objgetattr_BM (_.routprepob, k_locking);
  if (!_.locksetv)
    FAILHERE (k_locking);
  if (!isset_BM (_.locksetv))
    FAILHERE (makenode1_BM (k_locking, _.locksetv));
  if (!setcontains_BM (_.locksetv, _.stmtob))
    FAILHERE (makenode2_BM (k_locking, _.locksetv, _.stmtob));
  _.lobexpv = objgetattr_BM (_.stmtob, k_lockobj);
  WEAKASSERT_BM (_.lobexpv != NULL);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  char stmtidbuf[32];
  memset (stmtidbuf, 0, sizeof (stmtidbuf));
  idtocbuf32_BM (objid_BM (_.stmtob), stmtidbuf);
  int stmtlen = objnbcomps_BM (_.stmtob);
  objstrbufferprintfpayl_BM (_.modgenob, "{ // begin lockobj %s\n",
                             stmtidbuf);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "  objectval_tyBM* curlockedob%s = (",
                             stmtidbuf);
  miniemit_expression_BM (CURFRAME_BM, _.lobexpv, _.modgenob, _.routprepob,
                          _.stmtob, depth + 1);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, ");\n");
  objstrbufferprintfpayl_BM (_.modgenob, "if (objlock_BM (curlockedob%s)) {",
                             stmtidbuf);
  objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob, "locked%s = curlockedob%s;\n",
                             stmtidbuf, stmtidbuf);
  for (int cix = 0; cix < stmtlen; cix++)
    {
      _.compob = NULL;
      _.compv = objgetcomp_BM (_.stmtob, cix);
      if (!_.compv)
        continue;
      _.compob = objectcast_BM (_.compv);
      if (!_.compob)
        FAILHERE (makenode2_BM (k_curcomp, _.compv, taggedint_BM (cix)));
      DBGPRINTF_BM
        ("emit_block°basiclo_lockobj stmtob %s cix#%d compob %s",
         objectdbg_BM (_.stmtob), cix, objectdbg1_BM (_.compob));
      objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
      objstrbuffernewlinepayl_BM (_.modgenob);
      if (objectisinstance_BM (_.compob, k_basiclo_statement))
        {
          _.emitv = send3_BM (_.compob, k_emit_statement, CURFRAME_BM,  //
                              _.modgenob, _.routprepob, taggedint_BM (depth));
          DBGPRINTF_BM
            ("emit_block°basiclo_lockobj stmtob=%s compob=%s emit_statment -> %s",
             objectdbg_BM (_.stmtob), objectdbg2_BM (_.compob),
             debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
          if (!_.emitv)
            FAILHERE (makenode2_BM
                      (k_emit_statement, taggedint_BM (cix), _.compob));
        }
      else if (objectisinstance_BM (_.compob, k_basiclo_block))
        {
          _.emitv = send3_BM (_.compob, k_emit_block, CURFRAME_BM,      //
                              _.modgenob, _.routprepob, taggedint_BM (depth));
          DBGPRINTF_BM
            ("emit_statment°basiclo_lockobj stmtob=%s compob=%s emit_block -> %s",
             objectdbg_BM (_.stmtob), objectdbg2_BM (_.compob),
             debug_outstr_value_BM (_.emitv, CURFRAME_BM, 0));
          if (!_.emitv)
            FAILHERE (makenode2_BM
                      (k_emit_block, taggedint_BM (cix), _.compob));
        }
      else
        FAILHERE (makenode2_BM (k_curcomp, _.compob, taggedint_BM (cix)));
    }
  objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "objunlock_BM (locked%s), locked%s = NULL;",
                             stmtidbuf, stmtidbuf);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbuffernewlinepayl_BM (_.modgenob);
  objstrbufferprintfpayl_BM (_.modgenob, "} } // end objlock %s\n",
                             stmtidbuf);
  LOCALRETURN_BM (_.stmtob);
failure:
#undef FAILHERE
  DBGPRINTF_BM ("emit_block°basiclo_lockobj failin %d stmtob %s routprep %s cause %s", //
                failin, objectdbg_BM (_.stmtob), objectdbg1_BM (_.routprepob),  //
                debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode5_BM (k_emit_statement, _.stmtob, _.routprepob,
                               _.modgenob, taggedint_BM (depth), _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end  emit_block°basiclo_lockobj  _5XbwuHte8rl_1KjFdwMeolr */


////////////////////////////////////////////////////////////////
/// for the routine to emit_module in plain_module-s
extern objrout_sigBM ROUTINEOBJNAME_BM (_1gME6zn82Kf_8hzWibLFRfz);
value_tyBM
ROUTINEOBJNAME_BM (_1gME6zn82Kf_8hzWibLFRfz)    // emit_module°plain_module
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // recieving module
 const value_tyBM arg2,         /* optional dumperob or prefix */
 const value_tyBM arg3,         // optional closgenv closure to process the module generator
 const value_tyBM arg4 __attribute__ ((unused)),
 const quasinode_tyBM * restargs __attribute__ ((unused)))
{
  LOCALFRAME_BM ( /*prev: */ stkf,      /*descr: */
                 BMK_1gME6zn82Kf_8hzWibLFRfz, objectval_tyBM * modulob; //
                 objectval_tyBM * modgenob;     //
                 value_tyBM resprep;    //
                 value_tyBM resgen;     //
                 value_tyBM prefixv;    //
                 objectval_tyBM * dumpob; value_tyBM errorv;    //
                 value_tyBM closgenv;   //
                 value_tyBM srcdirstrv; //
                 value_tyBM causev;     //
    );
  // all these are heap allocated, e.g. strdup-ed or asprintf-ed
  char *srcdirstr = NULL;
  char *pardirstr = NULL;
  char *realpardirstr = NULL;
  char *realsrcdirstr = NULL;
  char *srcpathstr = NULL;
  char *prevsrcpathstr = NULL;
  objectval_tyBM *k_simple_module_generation = BMK_2HlKptD03wA_7JJCG7lN5nS;
  objectval_tyBM *k_prepare_module = BMK_17mrxkMdNtH_2CduQ2WDIy5;
  objectval_tyBM *k_plain_module = BMK_8g1WBJBhDT9_1QK8IcuWYx2;
  objectval_tyBM *k_generate_module = BMK_9mq0jsuz4XQ_4doHfd987Q6;
  objectval_tyBM *k_plain_temporary_module = BMK_1oEp0eAAyFN_4lsobepyr1T;
  objectval_tyBM *kk_deferred_compilation_of_module =
    BMK_9EqBenFWb40_86MuuXslynk;
  if (!isobject_BM (arg1))
    LOCALRETURN_BM (NULL);
  _.modulob = (objectval_tyBM *) arg1;
  _.prefixv = arg2;
  _.closgenv = arg3;
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  char modulidbuf[32];
  memset (modulidbuf, 0, sizeof (modulidbuf));
  idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
  bool modulistemporary =
    (objectisinstance_BM (_.modulob, k_plain_temporary_module));
  if (isstring_BM (_.prefixv))
    srcdirstr = strdup (bytstring_BM (_.prefixv));
  else if (isobject_BM (_.prefixv))
    {
      struct dumper_stBM *du =
        obdumpgetdumper_BM ((objectval_tyBM *) _.prefixv);
      if (du)
        {
          _.dumpob = (objectval_tyBM *) _.prefixv;
          asprintf (&srcdirstr, "%s/modules", bytstring_BM (du->dump_dir));
        }
      else
        FAILHERE (makenode1_BM (BMP_object, _.prefixv));
    }
  else
    srcdirstr = strdup ("modules");
  if (!srcdirstr)
    FATAL_BM ("failed to compute source dir for module %s - %m",
              objectdbg_BM (_.modulob));
  if (g_mkdir_with_parents (srcdirstr, 0750))
    {
      WARNPRINTF_BM ("cannot mkdir with parents %s (%m)\n", srcdirstr);
      FAILHERE (makestring_BM (srcdirstr));
    }
  {
    char cwdbuf[80];
    DBGPRINTF_BM
      ("emit_module°plain_module modulob %s /%s srcdirstr '%s' cwd %s",
       objectdbg_BM (_.modulob), modulidbuf, srcdirstr,
       getcwd (cwdbuf, sizeof (cwdbuf)) ? : "./");
  }
  {
    realsrcdirstr = realpath (srcdirstr, NULL);
    if (!realsrcdirstr || !strchr (realsrcdirstr, '/'))
      FATAL_BM
        ("failed to compute real source dir for module %s from srcdirstr %s - %m",
         objectdbg_BM (_.modulob), srcdirstr);
    DBGPRINTF_BM
      ("emit_module°plain_module realsrcdirstr %s for modulob %s /%s",
       realsrcdirstr, objectdbg_BM (_.modulob), modulidbuf);
    char *lastslash = strrchr (realsrcdirstr, '/');
    ASSERT_BM (lastslash != NULL);
    realpardirstr = malloc (lastslash - realsrcdirstr + 2);
    if (!realpardirstr)
      FATAL_BM ("failed to malloc realpardirstr of %zd bytes",
                lastslash - realsrcdirstr + 2);
    memset (realpardirstr, 0, lastslash - realsrcdirstr + 2);
    memcpy (realpardirstr, realsrcdirstr, lastslash - realsrcdirstr);
  }
  DBGPRINTF_BM
    ("emit_module°plain_module modulob %s /%s realsrcdirstr '%s' realpardirstr '%s'",
     objectdbg_BM (_.modulob), modulidbuf, realsrcdirstr, realpardirstr);
  _.modgenob = makeobj_BM ();
  objputclass_BM (_.modgenob, k_simple_module_generation);
  objputattr_BM (_.modgenob, k_plain_module, _.modulob);
  objputstrbufferpayl_BM (_.modgenob, (1024 * 1024));
  objtouchnow_BM (_.modgenob);
  DBGPRINTF_BM
    ("@@emit_module°plain_module modulob=%s /%s made modgenob=%s *sbuf*",
     objectdbg_BM (_.modulob), modulidbuf, objectdbg1_BM (_.modgenob));
  DBGPRINTF_BM ("@@emit_module°plain_module made modgenob=%s @%p",
                objectdbg_BM (_.modgenob), (void *) _.modgenob);
  if (isclosure_BM (_.closgenv))
    {
      DBGPRINTF_BM
        ("@@emit_module°plain_module modulob=%s closgenv=%s modgenob=%s",
         objectdbg_BM (_.modulob),
         debug_outstr_value_BM (_.closgenv, CURFRAME_BM, 0),
         objectdbg1_BM (_.modgenob));
      apply1_BM ((closure_tyBM *) _.closgenv, CURFRAME_BM, _.modgenob);
      DBGPRINTF_BM
        ("@@emit_module°plain_module modulob=%s after apply closgenv=%s modgenob=%s",
         objectdbg_BM (_.modulob),
         debug_outstr_value_BM (_.closgenv, CURFRAME_BM, 0),
         objectdbg1_BM (_.modgenob));
    }
  _.resprep = send1_BM (_.modulob, k_prepare_module, CURFRAME_BM, _.modgenob);
  DBGPRINTF_BM ("@@emit_module modulob=%s modgenob=%s resprep=%s",      //
                objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),   //
                debug_outstr_value_BM (_.resprep,       //
                                       CURFRAME_BM, 0));
  if (!_.resprep)
    {
      DBGPRINTF_BM
        ("@@emit_module modulob=%s prepare_module failed",
         objectdbg_BM (_.modulob));
      LOCALRETURN_BM (NULL);
    }
  else
    DBGPRINTF_BM ("@@emit_module modulob=%s prepare_module done before generate_module modgenob=%s resprep=%s", //
                  objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob), //
                  debug_outstr_value_BM (_.resprep,     //
                                         CURFRAME_BM, 0));
  WEAKASSERT_BM (objhasstrbufferpayl_BM (_.modgenob));
  if (modulistemporary)
    {
      char tmpnowbuf[64];
      struct tm tmpnowtm = { };
      time_t tmpnowt = 0;
      time (&tmpnowt);
      ASSERT_BM (tmpnowt > (time_t) 1000000000);
      localtime_r (&tmpnowt, &tmpnowtm);
      strftime (tmpnowbuf, sizeof (tmpnowbuf), "%c", &tmpnowtm);
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "// generated temporary module %s at %s pid #%d on %s\n"
                                 "// in file "
                                 TEMPMODULEPREFIX_BM "%s.c -- DONT EDIT\n",
                                 objectdbg_BM (_.modulob), tmpnowbuf,
                                 (int) getpid (), myhostname_BM, modulidbuf);
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "// generating bismon checksum %s\n",
                                 bismon_checksum);
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "// generating bismon directory %s\n",
                                 bismon_directory);
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "// generating bismon timestamp %s\n",
                                 bismon_timestamp);
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "// generating bismon lastgitcommit %s\n",
                                 bismon_lastgitcommit);
      objstrbuffernewlinepayl_BM (_.modgenob);
      objstrbuffernewlinepayl_BM (_.modgenob);
    }
  else
    objstrbufferprintfpayl_BM (_.modgenob,
                               "// generated persistent module %s\n"
                               "// in file "
                               MODULEPREFIX_BM "%s.c -- DONT EDIT\n",
                               objectdbg_BM (_.modulob), modulidbuf);
  objstrbufferprintfpayl_BM (_.modgenob,
                             "// this generated code is GPLv3+ licensed.\n");
  _.resgen =
    send2_BM (_.modulob, k_generate_module, CURFRAME_BM,
              _.modgenob, _.resprep);
  if (!_.resgen)
    {
      DBGPRINTF_BM
        ("@@emit_module modulob=%s generate_module failed modgenob=%s sbuf.l%u '''\n%s\n'''\n",
         objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),
         objstrbufferlengthpayl_BM (_.modgenob),
         objstrbufferbytespayl_BM (_.modgenob));
      LOCALRETURN_BM (NULL);
    }
  else
    DBGPRINTF_BM
      ("@@emit_module°plain_module modulob=%s generate_module done resgen=%s",
       objectdbg_BM (_.modulob), debug_outstr_value_BM (_.resgen,
                                                        CURFRAME_BM, 0));
  if (modulistemporary)
    {
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "\n\n"
                                 "// end of generated temporary module %s in file "
                                 TEMPMODULEPREFIX_BM "%s.c\n",
                                 objectdbg_BM (_.modulob), modulidbuf);
      if (asprintf (&srcpathstr, "%s/" TEMPMODULEPREFIX_BM "%s.c", srcdirstr,
                    modulidbuf) < 0)
        FATAL_BM ("asprintf failure for srcdir %s", srcdirstr);
    }
  else
    {
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "\n\n"
                                 "// end of generated persistent module %s in file "
                                 MODULEPREFIX_BM "%s.c\n",
                                 objectdbg_BM (_.modulob), modulidbuf);
      if (asprintf (&srcpathstr, "%s/" MODULEPREFIX_BM "%s.c", srcdirstr,
                    modulidbuf) < 0)
        FATAL_BM ("asprintf failure for srcdir %s", srcdirstr);
    }
  if (!srcpathstr)
    FATAL_BM
      ("failed to allocate srcpathstr dir %s modulidbuf %s",
       srcdirstr, modulidbuf);
  DBGPRINTF_BM
    ("emit_module°plain_module modulob %s /%s srcpathstr '%s' realsrcdirstr '%s'",
     objectdbg_BM (_.modulob), modulidbuf, srcpathstr, realsrcdirstr);
  if (!access (srcpathstr, F_OK))
    {
      char cwdbuf[80];
      memset (cwdbuf, 0, sizeof (cwdbuf));
      prevsrcpathstr =
        (char *) asprintf_prev_module_BM (realsrcdirstr, _.modulob);
      DBGPRINTF_BM
        ("emit_module°plain_module %s /%s rename srcpathstr '%s' -> prevsrcpathstr='%s' in %s",
         objectdbg_BM (_.modulob), modulidbuf, srcpathstr, prevsrcpathstr,
         (getcwd (cwdbuf, sizeof (cwdbuf))));
      if (rename (srcpathstr, prevsrcpathstr))
        FATAL_BM ("failed to rename '%s' -> '%s' in %s - %m",
                  srcpathstr, prevsrcpathstr, getcwd (cwdbuf,
                                                      sizeof (cwdbuf)));
    }
  {
    char cwdbuf[80];
    DBGPRINTF_BM
      ("emit_module°plain_module %s /%s writing to srcpathstr '%s' in %s",
       objectdbg_BM (_.modulob), modulidbuf, srcpathstr,
       (memset (cwdbuf, 0, sizeof (cwdbuf)),
        getcwd (cwdbuf, sizeof (cwdbuf))));
  }
  objstrbufferwritetofilepayl_BM (_.modgenob, srcpathstr);
  {
    char *indentcmdstr = NULL;
    char *quotpardir = g_shell_quote (realpardirstr);
    if (prevsrcpathstr)
      {
        char *quotprev = g_shell_quote (prevsrcpathstr);
        int a = -1;
        if (modulistemporary)
          a = asprintf (&indentcmdstr,
                        "make -f %s -C %s indenttempmodule MODULEID=%s PREVIOUSMODULESOURCE=%s",
                        bismon_makefile, quotpardir, modulidbuf, quotprev);
        else
          a = asprintf (&indentcmdstr,
                        "make -f %s -C %s indentsinglemodule MODULEID=%s PREVIOUSMODULESOURCE=%s",
                        bismon_makefile, quotpardir, modulidbuf, quotprev);
        if (a <= 0)
          FATAL_BM ("asprintf failed for indent command of modulid %s",
                    modulidbuf);
        g_free (quotprev);
      }
    else
      {
        if (modulistemporary)
          asprintf (&indentcmdstr,
                    "make -f %s -C %s indenttempmodule MODULEID=%s",
                    bismon_makefile, quotpardir, modulidbuf);
        else
          asprintf (&indentcmdstr,
                    "make -f %s -C %s indentsinglemodule MODULEID=%s",
                    bismon_makefile, quotpardir, modulidbuf);
      }
    if (!indentcmdstr)
      FATAL_BM ("failed to build indent command modulidbuf %s", modulidbuf);
    g_free (quotpardir), quotpardir = NULL;
    int fd = open (srcpathstr, O_RDONLY);
    if (fd < 0)
      FATAL_BM ("failed to open %s - %m", srcpathstr);
    flock (fd, LOCK_EX);
    DBGPRINTF_BM ("emit_module°plain_module indentcmdstr=%s", indentcmdstr);
    fflush (NULL);
    /// indent run quite quickly enough, often in a few dozens of milliseconds
    int cmdcod = system (indentcmdstr);
    if (cmdcod)
      {
        DBGPRINTF_BM
          ("emit_module°plain_module indentcmdstr=%s failed cmdcod=%d",
           indentcmdstr, cmdcod);
        FAILHERE (makestring_BM (indentcmdstr));
      }
    flock (fd, LOCK_UN);
    close (fd);
    free (indentcmdstr), indentcmdstr = NULL;
  }
  struct stat srcstat;
  memset (&srcstat, 0, sizeof (srcstat));
  if (stat (srcpathstr, &srcstat))
    FATAL_BM ("emit_module°plain_module failed to stat %s - %m", srcpathstr);
  DBGPRINTF_BM ("emit_module°plain_module srcpath %s st_size %ld",
                srcpathstr, (long) srcstat.st_size);
  const char *modulname = findobjectname_BM (_.modulob);
  if (modulname)
    {
      char *linkstr = NULL;
      asprintf (&linkstr, "%s/_%s_.c", srcdirstr, modulname);
      if (!linkstr)
        FATAL_BM ("failed to build symlink in %s for %s", srcdirstr,
                  modulname);
      DBGPRINTF_BM ("emit_module°plain_module linkstr=%s", linkstr);
      symlink (basename (srcpathstr), linkstr);
      free (linkstr), linkstr = NULL;
    }
  ///
#ifdef BISMONGTK
  if (gui_is_running_BM)
    {
      _.srcdirstrv = (value_tyBM) makestring_BM (srcdirstr);
      char cwdbuf[64];
      DBGBACKTRACEPRINTF_BM
        ("emit_module°plain_module srcdirstr= %s, modulob= %s\n"
         "... modgenob= %s, deferred_compilation_of_module= %s, cwd= %s",
         srcdirstr, objectdbg_BM (_.modulob),
         objectdbg1_BM (_.modgenob),
         objectdbg2_BM (kk_deferred_compilation_of_module),
         getcwd (cwdbuf, sizeof (cwdbuf)));
      do_main_defer_apply3_BM (kk_deferred_compilation_of_module,
                               _.modulob, _.modgenob, _.srcdirstrv,
                               CURFRAME_BM);
    }
#else
#warning emit_module°plain_module should be improved without BISMONGTK
  WARNPRINTF_BM ("emit_module°plain_module BISMONION not implemented...\n"     //
                 " ... srcpathstr %s modulob %s modgenob %s srcdirstrv %s\n",   //
                 srcpathstr, objectdbg_BM (_.modulob), objectdbg1_BM (_.modgenob),      //
                 debug_outstr_value_BM (_.srcdirstrv, CURFRAME_BM, 0));
  fflush (stderr);
#endif /*BISMONGTK*/
    if (srcdirstr)
    free (srcdirstr), srcdirstr = NULL;
  if (pardirstr)
    free (pardirstr), pardirstr = NULL;
  if (realpardirstr)
    free (realpardirstr), realpardirstr = NULL;
  if (realsrcdirstr)
    free (realsrcdirstr), realsrcdirstr = NULL;
  if (srcpathstr)
    free (srcpathstr), srcpathstr = NULL;
  if (prevsrcpathstr)
    free (prevsrcpathstr), prevsrcpathstr = NULL;
  LOCALRETURN_BM (_.modgenob);
failure:
  if (srcdirstr)
    free (srcdirstr), srcdirstr = NULL;
  if (pardirstr)
    free (pardirstr), pardirstr = NULL;
  if (realpardirstr)
    free (realpardirstr), realpardirstr = NULL;
  if (realsrcdirstr)
    free (realsrcdirstr), realsrcdirstr = NULL;
  if (srcpathstr)
    free (srcpathstr), srcpathstr = NULL;
  if (prevsrcpathstr)
    free (prevsrcpathstr), prevsrcpathstr = NULL;
  DBGPRINTF_BM
    ("emit_module°plain_module failin %d modulob %s cause %s",
     failin, objectdbg_BM (_.modulob),
     debug_outstr_value_BM (_.causev, CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode3_BM (BMP_emit_module, _.modulob,
                               _.modgenob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
#undef FAILHERE
}                               /* end emit_module°plain_module _1gME6zn82Kf_8hzWibLFRfz */





////////////////


// miniemit_node_conn#apply _6lTDbwKEMMc_0wsIKviDSce

extern objrout_sigBM ROUTINEOBJNAME_BM (_6lTDbwKEMMc_0wsIKviDSce);
value_tyBM
ROUTINEOBJNAME_BM (_6lTDbwKEMMc_0wsIKviDSce)    //miniemit_node_conn#apply 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // expv
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs /*fromob. */ )
{
  objectval_tyBM *k_apply = BMK_3Nl6LhfUZVb_1itsyWMBfYl;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_6lTDbwKEMMc_0wsIKviDSce,
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * modgenob;     //
                 value_tyBM expv;       //
                 value_tyBM subexpv;    //
                 objectval_tyBM * subtypob;     //
                 value_tyBM resultv;    //
                 value_tyBM funexpv;    //
                 value_tyBM causev;     //
                 value_tyBM errorv;);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.expv = arg1;
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  if (restargs)
    _.fromob = objectcast_BM (treenthson_BM ((value_tyBM) restargs, 0));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.routprepob));
  int nbsons = nodewidth_BM ((value_tyBM) _.expv);
  bool many = false;
  int nbappargs = nbsons - 1;
  if (nbsons == 0)
    FAILHERE (k_apply);
  else if (nbappargs <= 9)
    {
      objstrbufferprintfpayl_BM (_.modgenob, "(apply%d_BM ((", nbappargs);
    }
  else if (nbappargs < MAXAPPLYARGS_BM)
    {
      many = true;
      objstrbufferprintfpayl_BM (_.modgenob, "(applymany_BM ((");
    }
  else
    FAILHERE (k_apply);
  _.funexpv = nodenthson_BM (_.expv, 0);
  miniemit_expression_BM (CURFRAME_BM, _.funexpv, _.modgenob,
                          _.routprepob, _.fromob, depth + 1);
  _.funexpv = NULL;
  objstrbufferprintfpayl_BM (_.modgenob, "), ((struct stackframe_stBM*)&_)");
  if (many)
    objstrbufferprintfpayl_BM (_.modgenob, ", /*nbargs=*/%d", nbsons - 1);
  for (int ix = 1; ix < nbsons; ix++)
    {
      _.subexpv = nodenthson_BM (_.expv, ix);
      objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
      objstrbufferprintfpayl_BM (_.modgenob, ",\t (");
      miniemit_expression_BM (CURFRAME_BM, _.subexpv, _.modgenob,
                              _.routprepob, _.fromob, depth + 1);
      objstrbufferprintfpayl_BM (_.modgenob, ")");
    }
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, "))");
  LOCALRETURN_BM (_.expv);
failure:
#undef FAILHERE
  DBGPRINTF_BM
    ("miniemit_node_conn#apply failure failin %d exp %s routprepob %s cause %s",
     failin, debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg_BM (_.routprepob), debug_outstr_value_BM (_.causev,
                                                         CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode3_BM (k_apply, _.expv, _.routprepob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniemit_node_conn#apply _6lTDbwKEMMc_0wsIKviDSce */

////////////////

//miniemit_node_conn#send _5ul3FB4ewSJ_7GbPhk05UVR

extern objrout_sigBM ROUTINEOBJNAME_BM (_5ul3FB4ewSJ_7GbPhk05UVR);

value_tyBM
ROUTINEOBJNAME_BM (_5ul3FB4ewSJ_7GbPhk05UVR)    ///miniemit_node_conn#send 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // expv
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs /*fromob. */ )
{
  objectval_tyBM *k_send = BMK_5P2fpxElfqT_7NlO7H9TYGI;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_5ul3FB4ewSJ_7GbPhk05UVR,
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * modgenob;     //
                 value_tyBM expv;       //
                 value_tyBM subexpv;    //
                 value_tyBM recvexpv;   //
                 value_tyBM selexpv;    //
                 objectval_tyBM * subtypob;     //
                 value_tyBM resultv;    //
                 value_tyBM funexpv;    //
                 value_tyBM causev;     //
                 value_tyBM errorv;);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.expv = arg1;
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  if (restargs)
    _.fromob = objectcast_BM (treenthson_BM ((value_tyBM) restargs, 0));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.routprepob));
  int nbsons = nodewidth_BM ((value_tyBM) _.expv);
  bool many = false;
  int nbsendargs = nbsons - 2;
  if (nbsons < 2)
    FAILHERE (k_send);
  else if (nbsendargs <= 9)
    {
      objstrbufferprintfpayl_BM (_.modgenob, "(send%d_BM ((", nbsendargs);
    }
  else if (nbsendargs < MAXAPPLYARGS_BM - 1)
    {
      many = true;
      objstrbufferprintfpayl_BM (_.modgenob, "(sendmany_BM ((");
    }
  else
    FAILHERE (k_send);
  _.recvexpv = nodenthson_BM (_.expv, 0);
  _.selexpv = nodenthson_BM (_.expv, 1);
  miniemit_expression_BM (CURFRAME_BM, _.recvexpv, _.modgenob,
                          _.routprepob, _.fromob, depth + 1);
  objstrbufferprintfpayl_BM (_.modgenob, "), /*sel:*/(");
  miniemit_expression_BM (CURFRAME_BM, _.selexpv, _.modgenob,
                          _.routprepob, _.fromob, depth + 1);
  _.funexpv = NULL;
  objstrbufferprintfpayl_BM (_.modgenob, "), ((struct stackframe_stBM*)&_)");
  if (many)
    objstrbufferprintfpayl_BM (_.modgenob, ", /*nbargs=*/%d", nbsendargs);
  for (int ix = 2; ix < nbsons; ix++)
    {
      _.subexpv = nodenthson_BM (_.expv, ix);
      objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
      objstrbufferprintfpayl_BM (_.modgenob, ",\t (");
      miniemit_expression_BM (CURFRAME_BM, _.subexpv, _.modgenob,
                              _.routprepob, _.fromob, depth + 1);
      objstrbufferprintfpayl_BM (_.modgenob, ")");
    }
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, "))");
  LOCALRETURN_BM (_.expv);
failure:
#undef FAILHERE
  DBGPRINTF_BM
    ("miniemit_node_conn#send failure failin %d exp %s routprepob %s cause %s",
     failin, debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg_BM (_.routprepob), debug_outstr_value_BM (_.causev,
                                                         CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode3_BM (k_send, _.expv, _.routprepob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end routine _5ul3FB4ewSJ_7GbPhk05UVR */



////////////////
// miniemit_node_conn#make_sequence  _0DW82XG9HTW_0SblkfpwJi3

extern objrout_sigBM ROUTINEOBJNAME_BM (_0DW82XG9HTW_0SblkfpwJi3);

value_tyBM
ROUTINEOBJNAME_BM (_0DW82XG9HTW_0SblkfpwJi3)    //miniemit_node_conn#make_sequence
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // expv
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs /*fromob. */ )
{
  objectval_tyBM *k_tuple = BMK_6TmLNh9vtVY_0pwkHRtJ44k;
  objectval_tyBM *k_set = BMK_2mYaTh9kH4I_7ENiXcymRmy;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_0DW82XG9HTW_0SblkfpwJi3,
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * modgenob;     //
                 value_tyBM expv;       //
                 value_tyBM subexpv;    //
                 objectval_tyBM * connob;       //
                 objectval_tyBM * subtypob;     //
                 objectval_tyBM * seqtypob;     //
                 value_tyBM resultv;    //
                 value_tyBM callingclosv;       //
                 value_tyBM funexpv;    //
                 value_tyBM causev;     //
                 value_tyBM errorv;);
  LOCALGETFUNV_BM (_.callingclosv);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.expv = arg1;
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  if (restargs)
    _.fromob = objectcast_BM (treenthson_BM ((value_tyBM) restargs, 0));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.routprepob));
  _.connob = nodeconn_BM ((value_tyBM) _.expv);
  int nbsons = nodewidth_BM ((value_tyBM) _.expv);
  _.seqtypob = objectcast_BM (closurenthson_BM (_.callingclosv, 0));
  WEAKASSERT_BM (_.seqtypob == k_tuple || _.seqtypob == k_set);
  if (_.seqtypob == k_set)
    {
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "((value_tyBM) makesizedset_BM (%dU,",
                                 nbsons);
    }
  else if (_.seqtypob == k_tuple)
    {
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "((value_tyBM) makesizedtuple_BM (%dU,",
                                 nbsons);
    }
  else
    FAILHERE (_.seqtypob);
  for (int ix = 0; ix < nbsons; ix++)
    {
      _.subexpv = nodenthson_BM (_.expv, ix);
      objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
      objstrbuffernewlinepayl_BM (_.modgenob);
      if (ix > 0 && ix % 4 == 0 && ix + 1 < nbsons)
        {
          if (_.seqtypob == k_set)
            {
              objstrbufferprintfpayl_BM (_.modgenob, "// elem #%d\n", ix);
            }
          else if (_.seqtypob == k_tuple)
            {
              objstrbufferprintfpayl_BM (_.modgenob, "// comp #%d\n", ix);
            }
        }
      objstrbufferprintfpayl_BM (_.modgenob, "(");
      miniemit_expression_BM (CURFRAME_BM, _.subexpv, _.modgenob,
                              _.routprepob, _.fromob, depth + 1);
      objstrbufferprintfpayl_BM (_.modgenob, ")");
      if (ix + 1 < nbsons)
        {
          objstrbufferprintfpayl_BM (_.modgenob, ",");
          objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
          objstrbuffernewlinepayl_BM (_.modgenob);
        }
    }
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, ")");
  LOCALRETURN_BM (_.modgenob);
failure:
#undef FAILHERE
  DBGPRINTF_BM
    ("miniemit_node_conn#make_sequence failure failin %d exp %s routprepob %s cause %s",
     failin, debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg_BM (_.routprepob), debug_outstr_value_BM (_.causev,
                                                         CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode3_BM (_.connob ? _.connob :
                               BMK_0DW82XG9HTW_0SblkfpwJi3, _.expv,
                               _.routprepob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniemit_node_conn#make_sequence _0DW82XG9HTW_0SblkfpwJi3 */




////////////////

// miniemit_node_conn#collect_sequence _4qDfwZTHqD2_7Xti5ibNj8Z

extern objrout_sigBM ROUTINEOBJNAME_BM (_4qDfwZTHqD2_7Xti5ibNj8Z);

value_tyBM
ROUTINEOBJNAME_BM (_4qDfwZTHqD2_7Xti5ibNj8Z)    // miniemit_node_conn#collect_sequence 
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // expv
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs /*fromob. */ )
{
  objectval_tyBM *k_tuple = BMK_6TmLNh9vtVY_0pwkHRtJ44k;
  objectval_tyBM *k_set = BMK_2mYaTh9kH4I_7ENiXcymRmy;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_4qDfwZTHqD2_7Xti5ibNj8Z,
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * modgenob;     //
                 value_tyBM expv;       //
                 value_tyBM subexpv;    //
                 objectval_tyBM * connob;       //
                 objectval_tyBM * subtypob;     //
                 objectval_tyBM * seqtypob;     //
                 value_tyBM resultv;    //
                 value_tyBM callingclosv;       //
                 value_tyBM funexpv;    //
                 value_tyBM causev;     //
                 value_tyBM errorv;);
  LOCALGETFUNV_BM (_.callingclosv);
  int failin = -1;
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.expv = arg1;
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  if (restargs)
    _.fromob = objectcast_BM (treenthson_BM ((value_tyBM) restargs, 0));
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.routprepob));
  _.connob = nodeconn_BM ((value_tyBM) _.expv);
  int nbsons = nodewidth_BM ((value_tyBM) _.expv);
  _.seqtypob = objectcast_BM (closurenthson_BM (_.callingclosv, 0));
  WEAKASSERT_BM (_.seqtypob == k_tuple || _.seqtypob == k_set);
  if (_.seqtypob == k_set)
    {
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "((value_tyBM) makesizedcollectset_BM (%dU,",
                                 nbsons);
    }
  else if (_.seqtypob == k_tuple)
    {
      objstrbufferprintfpayl_BM (_.modgenob,
                                 "((value_tyBM) makesizedcollecttuple_BM (%dU,",
                                 nbsons);
    }
  else
    FAILHERE (_.seqtypob);
  for (int ix = 0; ix < nbsons; ix++)
    {
      _.subexpv = nodenthson_BM (_.expv, ix);
      objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
      objstrbuffernewlinepayl_BM (_.modgenob);
      if (ix > 0 && ix % 8 == 0 && ix + 1 < nbsons)
        {
          objstrbufferprintfpayl_BM (_.modgenob, "// collectarg #%d\n", ix);
        };
      objstrbufferprintfpayl_BM (_.modgenob, "(");
      miniemit_expression_BM (CURFRAME_BM, _.subexpv, _.modgenob,
                              _.routprepob, _.fromob, depth + 1);
      objstrbufferprintfpayl_BM (_.modgenob, ")");
      if (ix + 1 < nbsons)
        {
          objstrbufferprintfpayl_BM (_.modgenob, ",");
          objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
          objstrbuffernewlinepayl_BM (_.modgenob);
        }
    }
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, ")");
  LOCALRETURN_BM (_.modgenob);
failure:
#undef FAILHERE
  DBGPRINTF_BM
    ("miniemit_node_conn#make_sequence failure failin %d exp %s routprepob %s cause %s",
     failin, debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg_BM (_.routprepob), debug_outstr_value_BM (_.causev,
                                                         CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode3_BM (_.connob ? _.connob :
                               BMK_4qDfwZTHqD2_7Xti5ibNj8Z, _.expv,
                               _.routprepob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniemit_node_conn#collect_sequence _4qDfwZTHqD2_7Xti5ibNj8Z */


////////////////

// miniemit_node_conn°make_tree _1nsAyqOOy7S_1zodeivnxlm

extern objrout_sigBM ROUTINEOBJNAME_BM (_1nsAyqOOy7S_1zodeivnxlm);

value_tyBM
ROUTINEOBJNAME_BM (_1nsAyqOOy7S_1zodeivnxlm)    // miniemit_node_conn°make_tree
(struct stackframe_stBM * stkf, //
 const value_tyBM arg1,         // expv
 const value_tyBM arg2,         // modgenob
 const value_tyBM arg3,         // routprepob
 const value_tyBM arg4,         // depth
 const quasinode_tyBM * restargs /*fromob. */ )
{
  objectval_tyBM *k_node = BMK_7D8xcWnEiys_8oqOVSkCxkA;
  objectval_tyBM *k_closure = BMK_93zjUzZVAaj_9ppXv7C34GR;
  LOCALFRAME_BM (stkf, /*descr: */ BMK_1nsAyqOOy7S_1zodeivnxlm,
                 objectval_tyBM * routprepob;   //
                 objectval_tyBM * fromob;       //
                 objectval_tyBM * modgenob;     //
                 value_tyBM expv;       //
                 value_tyBM connexpv;   //
                 value_tyBM subexpv;    //
                 objectval_tyBM * connob;       //
                 objectval_tyBM * subtypob;     //
                 objectval_tyBM * seqtypob;     //
                 value_tyBM resultv;    //
                 value_tyBM callingclosv;       //
                 value_tyBM funexpv;    //
                 value_tyBM causev;     //
                 value_tyBM errorv;);
  LOCALGETFUNV_BM (_.callingclosv);
  int failin = -1;
#define MAXTREEOPTIMARGS_BM 8
#define FAILHERE(Cause) do { failin = __LINE__ ; _.causev = (value_tyBM)(Cause); goto failure; } while(0)
  _.expv = arg1;
  _.modgenob = objectcast_BM (arg2);
  _.routprepob = objectcast_BM (arg3);
  int depth = getint_BM (arg4);
  if (restargs)
    _.fromob = objectcast_BM (treenthson_BM ((value_tyBM) restargs, 0));
  DBGPRINTF_BM
    (" miniemit_node_conn°make_tree start expv %s modgenob %s routprepob %s fromob %s depth#%d",
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg_BM (_.modgenob), objectdbg1_BM (_.routprepob),
     objectdbg2_BM (_.fromob), depth);
  WEAKASSERT_BM (isobject_BM (_.modgenob));
  WEAKASSERT_BM (isobject_BM (_.routprepob));
  _.connob = nodeconn_BM ((value_tyBM) _.expv);
  int nbsons = nodewidth_BM ((value_tyBM) _.expv);
  int previndent = objstrbufferindentationpayl_BM (_.modgenob);
  _.seqtypob = objectcast_BM (closurenthson_BM (_.callingclosv, 0));
  DBGPRINTF_BM
    (" miniemit_node_conn°make_tree nbsons %d fromob %s seqtypob %s", nbsons,
     objectdbg_BM (_.fromob), objectdbg1_BM (_.seqtypob));
  WEAKASSERT_BM (_.seqtypob == k_node || _.seqtypob == k_closure);
  WEAKASSERT_BM (nbsons > 0);
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  if (_.seqtypob == k_node)
    {
      if (nbsons < MAXTREEOPTIMARGS_BM)
        objstrbufferprintfpayl_BM (_.modgenob,
                                   "((value_tyBM) makenode%u_BM\n (",
                                   (unsigned) nbsons - 1);
      else
        objstrbufferprintfpayl_BM (_.modgenob,
                                   "((value_tyBM) makesizednode_BM\n (%dU,",
                                   (unsigned) nbsons - 1);

    }
  else if (_.seqtypob == k_closure)
    {
      if (nbsons < MAXTREEOPTIMARGS_BM)
        objstrbufferprintfpayl_BM (_.modgenob,
                                   "((value_tyBM) makeclosure%u_BM\n (",
                                   (unsigned) nbsons - 1);
      else
        objstrbufferprintfpayl_BM (_.modgenob,
                                   "((value_tyBM) makesizedclosure_BM\n (%dU,",
                                   (unsigned) nbsons - 1);
    }
  else
    FAILHERE (_.seqtypob);
#undef MAXTREEOPTIMARGS_BM
  _.connexpv = nodenthson_BM (_.expv, 0);
  objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
  objstrbufferprintfpayl_BM (_.modgenob, "/*%s conn:*/",
                             objectdbg_BM (_.connob));
  objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
  objstrbufferprintfpayl_BM (_.modgenob, "(");
  miniemit_expression_BM (CURFRAME_BM, _.connexpv, _.modgenob,
                          _.routprepob, _.fromob, depth + 1);
  if (nbsons > 1)
    objstrbufferprintfpayl_BM (_.modgenob, "),\n /*%s %d sons:*/",
                               objectdbg_BM (_.connob), nbsons - 1);
  else
    objstrbufferprintfpayl_BM (_.modgenob, ")");
  DBGPRINTF_BM (" miniemit_node_conn°make_tree expv %s fromob %s nbsons#%d",
                debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
                objectdbg2_BM (_.fromob), nbsons);
  for (int ix = 1; ix < nbsons; ix++)
    {
      objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
      _.subexpv = nodenthson_BM (_.expv, ix);
      DBGPRINTF_BM
        (" miniemit_node_conn°make_tree subexpv %s fromob %s ix#%d",
         debug_outstr_value_BM (_.subexpv, CURFRAME_BM, 0),
         objectdbg2_BM (_.fromob), ix);
      objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
      objstrbuffernewlinepayl_BM (_.modgenob);
      if (ix > 0 && ix % 4 == 0 && ix + 1 < nbsons)
        {
          objstrbufferprintfpayl_BM (_.modgenob, "// %s arg #%d\n",
                                     objectdbg_BM (_.connob), ix);
        };
      objstrbufferprintfpayl_BM (_.modgenob, "(");
      miniemit_expression_BM (CURFRAME_BM, _.subexpv, _.modgenob,
                              _.routprepob, _.fromob, depth + 1);
      objstrbufferprintfpayl_BM (_.modgenob, ")");
      DBGPRINTF_BM
        (" miniemit_node_conn°make_tree done subexpv %s fromob %s ix#%d nbsons %d",
         debug_outstr_value_BM (_.subexpv, CURFRAME_BM, 0),
         objectdbg2_BM (_.fromob), ix, nbsons);
      if (ix + 1 < nbsons)
        {
          objstrbufferprintfpayl_BM (_.modgenob, ",");
          objstrbuffersetindentpayl_BM (_.modgenob, depth + 1);
          objstrbuffernewlinepayl_BM (_.modgenob);
        }
    }
  objstrbuffersetindentpayl_BM (_.modgenob, depth);
  objstrbufferprintfpayl_BM (_.modgenob, "))");
  DBGPRINTF_BM
    (" miniemit_node_conn°make_tree end expv %s modgenob %s routprepob %s fromob %s depth#%d",
     debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg_BM (_.modgenob), objectdbg1_BM (_.routprepob),
     objectdbg2_BM (_.fromob), depth);
  objstrbuffersetindentpayl_BM (_.modgenob, previndent);
  LOCALRETURN_BM (_.modgenob);
failure:
#undef FAILHERE
  DBGPRINTF_BM
    ("miniemit_node_conn°make_tree failure failin %d exp %s routprepob %s cause %s",
     failin, debug_outstr_value_BM (_.expv, CURFRAME_BM, 0),
     objectdbg_BM (_.routprepob), debug_outstr_value_BM (_.causev,
                                                         CURFRAME_BM, 0));
  _.errorv =
    (value_tyBM) makenode3_BM (_.connob ? _.connob :
                               BMK_1nsAyqOOy7S_1zodeivnxlm, _.expv,
                               _.routprepob, _.causev);
  PLAINFAILURE_BM (failin, _.errorv, CURFRAME_BM);
}                               /* end miniemit_node_conn°make_tree _1nsAyqOOy7S_1zodeivnxlm */

/*** end of file emitcode_BM.c ***/
