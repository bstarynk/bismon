// file cmacros_BM.h

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
#ifndef CMACROS_BM_INCLUDED
#define CMACROS_BM_INCLUDED


#define MAXDEPTHGC_BM 256
#define MAXDEPTHPARSE_BM 96
#define MAXDEPTHMETHOD_BM 96

#define MAXAPPLYARGS_BM 128

#define MARKGC_BM 1
#define CLEARMGC_BM 0
#define GCMAGIC_BM 24501383     /*0x175dc87 */

#define MILLION_BM (1000*1000)
#define BILLION_BM (1000*MILLION_BM)
// see https://stackoverflow.com/a/11376759/841108
// integer log in base 2, for a positive X
#define ILOG2_BM(X) ((unsigned) (8*sizeof (unsigned long long) \
				 - __builtin_clzll((X)) - 1))
#define FAILUREHANDLEMAGIC_BM    853401645      /*Ox32dde02d */

#define VALUEGCPROC_BM(Gc,Val,Depth)		\
  do { if ((Val)!=NULL)				\
      Val = (typeof(Val))(valuegcproc_BM ((Gc),	\
					  (void*)(Val),(Depth))); } while(0)

#define EXTENDEDGCPROC_BM(Gc,Xval,Depth) \
  do { Xval = extendedgcproc_BM((Gc),(Xval),(Depth)); } while(0)

#define HASHEMPTYSLOT_BM ((void*)(-1))

#define STRBUFFERWANTEDWIDTH_BM 80
#define LOADERMAGIC_BM 281610361        /*0x10c90879 */
#define MAXLOADEDFILES_BM 64

#define MINSERIAL_BM (62*62)    /*3884 */
#define MAXSERIAL_BM ((uint64_t)10 * 62 * (62* 62*62) * (62*62*62) * (62*62*62))        /*8392993658683402240 */
#define DELTASERIAL_BM (MAXSERIAL_BM-MINSERIAL_BM)
#define MAXBUCKETS_BM (10*62)
#define B62DIGITS_BM   "0123456789"  "abcdefghijklmnopqrstuvwxyz"  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

#define SERIALDIGITS_BM 11
#define SERIALBASE_BM 62

#define EMPTY_TOKEN_BM (struct parstoken_stBM) { \
    .tok_kind= plex__NONE, .tok_line= -1, .tok_col= -1, .tok_ptr= NULL }

#define MODULEDIR_BM "modules"
#define MODULEPREFIX_BM "modbm"

/// each module should have DECLARE_MODULE_BM(BISMON_MODID); after inclusion of "bismon.h"
#define DECLARE_MODULE_BM(Id) const char module_id_BM[] = #Id

#define IDLEN_BM 24
#define MAXSIZE_BM ((1<<30)-1)
#define TINYSIZE_BM 15

#define PARSERMEMOLINERATIO_BM 16
#define PARSOPMAGIC_BM 3144351953       /*0xbb6b00d1 */
#define FATAL_AT_BIS_BM(Fil,Lin,Fmt,...) do {                   \
    fprintf(stderr, "BM FATAL:%s:%d: <%s>\n " Fmt "\n\n",       \
            Fil, Lin, __func__, ##__VA_ARGS__);                 \
    void* backarr[2*TINYSIZE_BM];				\
    memset (backarr, 0, sizeof(backarr));			\
    int backdepth =						\
      backtrace(backarr, sizeof(backarr)/sizeof(void*));	\
    backtrace_symbols_fd(backarr, backdepth,			\
			 STDERR_FILENO);			\
    abort_BM(); } while(0)

#define FATAL_AT_BM(Fil,Lin,Fmt,...) FATAL_AT_BIS_BM(Fil,Lin,Fmt,##__VA_ARGS__)

#define FATAL_BM(Fmt,...) FATAL_AT_BM(__FILE__,__LINE__,Fmt,##__VA_ARGS__)

#ifndef NDEBUG
#define ASSERT_BM(Cond) do { if (!(Cond)) FATAL_AT_BM (__FILE__,__LINE__,\
	     "ASSERT failure: %s (in %s)", \
	     #Cond, __PRETTY_FUNCTION__); } while(0)
#else
#define ASSERT_BM(Cond) do { if (false && !(Cond)) abort(); } while(0)
#endif /* ASSERT_BM */

#define LOCALFRAME_BM(Prev,Descr,...) struct                    \
  { struct stackframe_stBM __frame; __VA_ARGS__; } _ =          \
    { .__frame = {.stkfram_pA=                                  \
                  (typedhead_tyBM)                              \
                  {.htyp= typayl_StackFrame_BM,                 \
                   .hgc=0,                                      \
                   .rlen=(sizeof(_)                             \
                          - offsetof(struct stackframe_stBM,    \
                                     stkfram_locals))           \
                   /sizeof(value_tyBM)},                        \
                  .stkfram_prev=(Prev),                         \
                  .stkfram_descr=(Descr),                       \
                  .stkfram_state=0,                             \
                  .stkfram_xtra=0 } }

#define LOCALGETFUNV_ATLIN_BIS_BM(Lin,Funv) do {			\
  struct stackframe_stBM*prevfram_##Lin					\
    = _.__frame.stkfram_prev;						\
  ASSERT_BM (prevfram_##Lin						\
	  && ((typedhead_tyBM *)prevfram_##Lin)->htyp			\
	  == typayl_StackFrame_BM);					\
  ASSERT_BM (isclosure_BM ((value_tyBM)prevfram_##Lin->stkfram_callfun)	\
	  || isobject_BM ((value_tyBM)prevfram_##Lin->stkfram_callfun)); \
  Funv = (void*)prevfram_##Lin->stkfram_callfun;			\
 } while(0)
#define LOCALGETFUNV_ATLIN_BM(Lin,Clos) LOCALGETFUNV_ATLIN_BIS_BM(Lin,Clos)
#define LOCALGETFUNV_BM(Clos) LOCALGETFUNV_ATLIN_BM(__LINE__,Clos)

#define LOCALRETURN_ATLIN_BIS_BM(Lin,Res) do {		\
  struct stackframe_stBM*prevfram_##Lin			\
    = _.__frame.stkfram_prev;				\
  ASSERT_BM (prevfram_##Lin				\
	  && ((typedhead_tyBM *)prevfram_##Lin)->htyp	\
	  == typayl_StackFrame_BM);			\
  prevfram_##Lin->stkfram_callfun = NULL;		\
  return (value_tyBM)(Res);				\
 } while(0)
#define LOCALRETURN_ATLIN_BM(Lin,Res) LOCALRETURN_ATLIN_BIS_BM(Lin,Res)
#define LOCALRETURN_BM(Res) LOCALRETURN_ATLIN_BM(__LINE__,(Res))

#define LOCALJUSTRETURN_ATLIN_BIS_BM(Lin) do {		\
  struct stackframe_stBM*prevfram_##Lin			\
    = _.__frame.stkfram_prev;				\
  ASSERT_BM (prevfram_##Lin				\
	  && ((typedhead_tyBM *)prevfram_##Lin)->htyp	\
	  == typayl_StackFrame_BM);			\
  prevfram_##Lin->stkfram_callclos = NULL;		\
  return;						\
 } while(0)
#define LOCALJUSTRETURN_ATLIN_BM(Lin) LOCALJUSTRETURN_ATLIN_BIS_BM(Lin)
#define LOCALJUSTRETURN_BM() LOCALRETURN_ATLIN_BM(__LINE__)


#define LOCALQNODESIZED_BM(Qnam,Conn,Siz) struct {			\
    struct nodetree_stBM __ntree; value_tyBM qsons[Siz]; } Qnam =	\
      { .__ntree = { .pA = { .pS =					\
			     {.pA = { .htyp= typayl_quasinode_BM,	\
				      .hgc=0, .hash=0 }, .size = (Siz) } }, \
		     .nodt_conn= (Conn) }, .qsons= {} }

#define LOCALQNODEFIELDED_BM(Qnam,Conn,...) struct {			\
  struct nodetree_stBM __ftree; __VA_ARGS__; } Qnam =			\
      { .__ftree = { .pA						\
		     = { .pS = 						\
			 {.pa = { .htyp= typayl_quasinode_BM,		\
			     .hgc=0, .hash=0 },				\
			 .size =					\
			  ((sizeof(Qnam)-offsetof(tree_tyBM,nodt_sons)) \
			   /sizeof(value_tyBM)) } },			\
		     .nodt_conn= (Conn) } }

/// the routine inside object of id _60mLNh9vtVY_0pwkHRtJ44k would be
/// named crout_60mLNh9vtVY_0pwkHRtJ44k_BM
#define ROUTINEOBJNAME_BM(Id) crout##Id##_BM
#define ROUTINEOBJPREFIX_BM "crout"
#define ROUTINESUFFIX_BM "_BM"

#define GLOBAL_BM(Gnam) globdata_##Gnam##_BM

// we could use DBGPRINTF_BM and later replace it by NONPRINTF_BM
#define DBGPRINTFATBIS_BM(Fil,Lin,Fmt,...) do { \
    printf("%s:%d: " Fmt "\n",			\
	   basename((Fil)), (Lin),		\
	 ##__VA_ARGS__);			\
} while(0)

#define DBGPRINTFAT_BM(Fil,Lin,Fmt,...) \
  DBGPRINTFATBIS_BM(Fil,Lin,Fmt,##__VA_ARGS__)

#define DBGPRINTF_BM(Fmt,...) \
  DBGPRINTFAT_BM(__FILE__,__LINE__,Fmt,##__VA_ARGS__)

#define NONPRINTF_BM(Fmt,...) do { if (false) \
      DBGPRINTF_BM(Fmt,##__VA_ARGS__); } while(0)

#define FAILURE_AT_BIS_BM(Fcod,Fil,Lin,Reason,Stack) \
  do {failure_at_BM((Fcod),(Fil),(Lin),(Reason),(Stack));} while(0)

#define FAILURE_AT_BM(Fcod,Fil,Lin,Reason,Stack) \
       FAILURE_AT_BIS_BM(Fcod,Fil,Lin,Reason,Stack)
#define FAILURE_BM(FailCod,Reason,Stack) FAILURE_AT_BM((FailCod),__FILE__,__LINE__,(Reason),(Stack))


#define LOCAL_FAILURE_HANDLE_ATBIS_BM(Fil,Lin,FcodVar,ReasonVar)	\
  struct failurehandler_stBM fh_##Lin					\
   = {									\
     .pA = {.htyp = typayl_FailureHandler_BM},				\
     .failh_magic = FAILUREHANDLEMAGIC_BM,				\
     .failh_lockset = NULL,						\
     .failh_reason = NULL,						\
     .failh_jmpbuf = {}};						\
  curfailurehandle_BM = &fh_##Lin;					\
  volatile int failcod_##Lin =  setjmp(fh_##Lin.failh_jmpbuf);		\
  FcodVar = failcod_##Lin;						\
  if (failcod_##Lin) {							\
    ReasonVar = fh_##Lin.failh_reason;					\
  };									\
  (void)0

#define LOCAL_FAILURE_HANDLE_AT_BM(Fil,Lin,FcodVar,ReasonVar) \
  LOCAL_FAILURE_HANDLE_ATBIS_BM(Fil,Lin,FcodVar,ReasonVar)

/// code using LOCAL_FAILURE_HANDLE_BM should probably backup and
/// restore the curfailurehandle_BM
#define LOCAL_FAILURE_HANDLE_BM(FcodVar,ReasonVar) \
  LOCAL_FAILURE_HANDLE_AT_BM(__FILE__,__LINE__,FcodVar,ReasonVar)

// weak assert dont abort
#ifndef NDEBUG
extern void weakassertfailureat_BM (const char *condmsg, const char *fil,
                                    int lin);
#define WEAKASSERT_BM(Cond) do { if(!(Cond)) \
      { weakassertfailureat_BM(#Cond,__FILE__,__LINE__); return 0; }} \
  while(0)
#define WEAKASSERTRET_BM(Cond) do { if(!(Cond)) \
      { weakassertfailureat_BM(#Cond,__FILE__,__LINE__); return; }} \
  while(0)
#define WEAKASSERTWARN_BM(Cond) do { if(!(Cond)) \
      { weakassertfailureat_BM(#Cond,__FILE__,__LINE__); }} \
  while(0)
#else
#define WEAKASSERT_BM(Cond) do if(false && !(Cond)) \
      {  return 0; }} while(0)
#define WEAKASSERTRET_BM(Cond) do if(false && !(Cond)) \
      {  return; }} while(0)
#define WEAKASSERTWARN_BM(Cond) do { if(false && !(Cond)) \
      { weakassertfailureat_BM(#Cond,__FILE__,__LINE__); } \
  while(0)
#endif /*NDEBUG*/
// for readability, gravity argument to gtk_text_buffer_create_mark
#define RIGHT_GRAVITY_BM FALSE
#define LEFT_GRAVITY_BM TRUE
// initial empty text iter
#define EMPTY_TEXT_ITER_BM (GtkTextIter){}
// for readability in gtk_box_pack_start etc...
#define BOXEXPAND_BM TRUE
#define BOXNOEXPAND_BM FALSE
#define BOXFILL_BM TRUE
#define BOXNOFILL_BM FALSE
// agenda support
#define MAXNBWORKJOBS_BM 16
#define MINNBWORKJOBS_BM 2
#endif /*CMACROS_BM_INCLUDED */
