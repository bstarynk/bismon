

#if !defined(HAS_PREDEF_BM) && !defined(HAS_NAMED_PREDEF_BM)
#error missing HAS_PREDEF_BM or HAS_NAMED_PREDEF_BM
#endif

#undef BM_NB_PREDEFINED


#define BM_NB_PREDEFINED 13

#ifdef HAS_PREDEF_BM

// HAS_PREDEF_BM(Id,Hi,Lo,Hash)
HAS_PREDEF_BM(_01h86SAfOfg_1q2oMegGRwW,17277432066359042,1191787554516715966,3394097885)      /*=comment*/
HAS_PREDEF_BM(_0LK4TzFd6u1_0JFUsrQ4odG,646303955676276197,618319665240386928,3360562782)      /*=class*/
HAS_PREDEF_BM(_0vgCFjXblkx_4zCMhMAWjVK,423279293069254533,3839462464230137848,3654230598)     /*=int*/
HAS_PREDEF_BM(_1JSykdLcLdl_8rWxtDBaPGN,1460379509660363239,7092677886587085321,1096209377)    /*=none*/
HAS_PREDEF_BM(_1jJjA6LcXiX_1V4ZcXlje09,1106398276679039699,1612002213888230169,1983056072)    /*=name*/
HAS_PREDEF_BM(_1z3DQ3EVAGs_3KlGdHJpWbX,1313892715239389360,3145337907231778997,2712776755)    /*=undefined*/
HAS_PREDEF_BM(_2mYaTh9kH4I_7ENiXcymRmy,1989553397960768864,6427344439880832506,3372873735)    /*=set*/
HAS_PREDEF_BM(_33imugvOze0_0wdPqjmME0U,2562518673800987088,436206287747275864,2706493850)     /*=embed*/
HAS_PREDEF_BM(_4T8am97muLl_5969SR22Ecq,4103520418467771663,4319675459220983826,1161704456)    /*=string*/
HAS_PREDEF_BM(_55eJRRPyZDz_4uW8bzq75PI,4267400555937946057,3776002616155157090,4145552779)    /*=unspecified*/
HAS_PREDEF_BM(_6TmLNh9vtVY_0pwkHRtJ44k,5785307752390188214,345486970731853988,753345157)      /*=tuple*/
HAS_PREDEF_BM(_7D8xcWnEiys_8oqOVSkCxkA,6404905605597335568,7045141214921877264,378355676)     /*=node*/
HAS_PREDEF_BM(_7T9OwSFlgov_0wVJaK1eZbn,6621778330493060695,445791238318866325,300201260)      /*=object*/
HAS_PREDEF_BM(_93zjUzZVAaj_9ppXv7C34GR,7602017580619764023,7897789502155506201,3359137725)    /*=closure*/     

#undef HAS_PREDEF_BM
#endif /*HAS_PREDEF_BM*/

////////////////////////////////////////////////////////////////


#define BMP_class                PREDEF_BM(_0LK4TzFd6u1_0JFUsrQ4odG)
#define BMP_closure              PREDEF_BM(_93zjUzZVAaj_9ppXv7C34GR)
#define BMP_comment              PREDEF_BM(_01h86SAfOfg_1q2oMegGRwW)
#define BMP_embed                PREDEF_BM(_33imugvOze0_0wdPqjmME0U)
#define BMP_int                  PREDEF_BM(_0vgCFjXblkx_4zCMhMAWjVK)
#define BMP_name                 PREDEF_BM(_1jJjA6LcXiX_1V4ZcXlje09)
#define BMP_node                 PREDEF_BM(_7D8xcWnEiys_8oqOVSkCxkA)
#define BMP_none                 PREDEF_BM(_1JSykdLcLdl_8rWxtDBaPGN)
#define BMP_object               PREDEF_BM(_7T9OwSFlgov_0wVJaK1eZbn)
#define BMP_set                  PREDEF_BM(_2mYaTh9kH4I_7ENiXcymRmy)
#define BMP_string               PREDEF_BM(_4T8am97muLl_5969SR22Ecq)
#define BMP_tuple                PREDEF_BM(_6TmLNh9vtVY_0pwkHRtJ44k)
#define BMP_undefined            PREDEF_BM(_1z3DQ3EVAGs_3KlGdHJpWbX)
#define BMP_unspecified          PREDEF_BM(_55eJRRPyZDz_4uW8bzq75PI)

////////////////////////////////////////////////////////////////

#define BMPNID_class                _0LK4TzFd6u1_0JFUsrQ4odG
#define BMPNID_closure              _93zjUzZVAaj_9ppXv7C34GR
#define BMPNID_comment              _01h86SAfOfg_1q2oMegGRwW
#define BMPNID_embed                _33imugvOze0_0wdPqjmME0U
#define BMPNID_int                  _0vgCFjXblkx_4zCMhMAWjVK
#define BMPNID_name                 _1jJjA6LcXiX_1V4ZcXlje09
#define BMPNID_node                 _7D8xcWnEiys_8oqOVSkCxkA
#define BMPNID_none                 _1JSykdLcLdl_8rWxtDBaPGN
#define BMPNID_object               _7T9OwSFlgov_0wVJaK1eZbn
#define BMPNID_set                  _2mYaTh9kH4I_7ENiXcymRmy
#define BMPNID_string               _4T8am97muLl_5969SR22Ecq
#define BMPNID_tuple                _6TmLNh9vtVY_0pwkHRtJ44k
#define BMPNID_undefined            _1z3DQ3EVAGs_3KlGdHJpWbX
#define BMPNID_unspecified          _55eJRRPyZDz_4uW8bzq75PI

////////////////////////////////////////////////////////////////
#ifdef HAS_NAMED_PREDEF_BM
// HAS_NAMED_PREDEF_BM(Nam,Id)
HAS_NAMED_PREDEF_BM(class,_0LK4TzFd6u1_0JFUsrQ4odG)
HAS_NAMED_PREDEF_BM(closure,_93zjUzZVAaj_9ppXv7C34GR)
HAS_NAMED_PREDEF_BM(comment,_01h86SAfOfg_1q2oMegGRwW)
HAS_NAMED_PREDEF_BM(embed,_33imugvOze0_0wdPqjmME0U)
HAS_NAMED_PREDEF_BM(int,_0vgCFjXblkx_4zCMhMAWjVK)
HAS_NAMED_PREDEF_BM(name,_1jJjA6LcXiX_1V4ZcXlje09)
HAS_NAMED_PREDEF_BM(node,_7D8xcWnEiys_8oqOVSkCxkA)
HAS_NAMED_PREDEF_BM(none,_1JSykdLcLdl_8rWxtDBaPGN)
HAS_NAMED_PREDEF_BM(object,_7T9OwSFlgov_0wVJaK1eZbn)
HAS_NAMED_PREDEF_BM(set,_2mYaTh9kH4I_7ENiXcymRmy)
HAS_NAMED_PREDEF_BM(string,_4T8am97muLl_5969SR22Ecq)
HAS_NAMED_PREDEF_BM(tuple,_6TmLNh9vtVY_0pwkHRtJ44k)
HAS_NAMED_PREDEF_BM(undefined,_1z3DQ3EVAGs_3KlGdHJpWbX)
HAS_NAMED_PREDEF_BM(unspecified,_55eJRRPyZDz_4uW8bzq75PI)

#undef HAS_NAMED_PREDEF_BM
#endif /*HAS_NAMED_PREDEF_BM*/

