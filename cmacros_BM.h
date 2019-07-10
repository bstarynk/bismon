// file cmacros_BM.h

/***
    BISMON 
    Copyright © 2018, 2019 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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
#ifndef CMACROS_BM_INCLUDED
#define CMACROS_BM_INCLUDED


// the first second of this millenium, date --date "2000-01-01 00:00:00 GMT" +"%s"
#define Y2KEPOCH_BM 946684800
#define MAXDEPTHGC_BM 256
#define MAXDEPTHPARSE_BM 96
#define MAXDEPTHMETHOD_BM 96
#define MAXINDENT_BM 128
#define MAXAPPLYARGS_BM 128

#define MARKGC_BM 1
#define CLEARMGC_BM 0
#define GCMAGIC_BM 24501383     /*0x175dc87 */

#define VERBOSE_BM true
#define SILENT_BM false
#define CHECKDNS_BM true
#define DONTCHECKDNS_BM false

#define MILLION_BM (1000*1000)
#define BILLION_BM (1000*MILLION_BM)
// see https://stackoverflow.com/a/11376759/841108
// integer log in base 2, for a positive X
#define ILOG2_BM(X) ((unsigned) (8*sizeof (unsigned long long) \
				 - __builtin_clzll((X)) - 1))
// optimization hints:
#define LIKELY_BM(Test) !__builtin_expect(!(Test),0)
#define UNLIKELY_BM(Test) __builtin_expect(!!(Test),0)

#define FAILUREHANDLEMAGIC_BM    853401645      /*Ox32dde02d */

#define VALUEGCPROC_BM(Gc,Val,Depth)		\
  do { if ((Val)!=NULL)				\
      Val = (typeof(Val))(valuegcproc_BM ((Gc),	\
					  (void*)(Val),(Depth))); } while(0)

#define EXTENDEDGCPROC_BM(Gc,Xval,Fromob,Depth)				\
  do { Xval = (typeof(Xval)) (extendedgcproc_BM((Gc),			\
				(void*)(Xval),(Fromob),(Depth))); } while(0)

// practically speaking, a pointer-like value in some part of the
// address space which is never mapped.  Useful in hashtables for empty
// slots.
#define HASHEMPTYSLOT_BM ((void*)(-(sizeof(void*))))

#define STRBUFFERWANTEDWIDTH_BM 80
#define LOADERMAGIC_BM 281610361        /*0x10c90879 */
#define MAXLOADEDFILES_BM 64




//================================================================
//////////////////////////////////////////////////////////////////
//////////////// about the store files.....
// The first line of every store*.bmon file should start with the
// following magic UTF-8 characters; the fourth character is the Euro
// sign.
#define STORE_CONTENTMAGIC_PREFIX_BM "//!€Bismon"



/***
 * Beware that some of the below prefixes and their ALTernatives should
 * absolutely have the same byte length (as given by strlen or sizeof).
 *
 * Notice that the TERDELIM-s below are never used, except when we
 * temporarily change the delimiters because LaTeX don't like them
 * See also https://tex.stackexchange.com/a/342804/42406
 ***/



// also delim_dblanglequotleft & delim_exclamleft in load_second_pass_BM
#define STORE_OBJECTOPEN_PREFIX_BM "«" /*U+00AB LEFT-POINTING DOUBLE ANGLE QUOTATION MARK */
#define STORE_OBJECTOPEN_ALTPREFIX_BM "!("
#define STORE_OBJECTOPEN_TERPREFIX_BM NULL
#define STORE_OBJECTOPEN_DELIM_BM delim_dblanglequotleft
#define STORE_OBJECTOPEN_ALTDELIM_BM delim_exclamleft
#define STORE_OBJECTOPEN_TERDELIM_BM delim__NONE

// also delim_dblanglequotright & delim_exclamright in load_second_pass_BM
#define STORE_OBJECTCLOSE_PREFIX_BM "»"        /*U+00BB RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK */
#define STORE_OBJECTCLOSE_ALTPREFIX_BM "!)"
#define STORE_OBJECTCLOSE_TERPREFIX_BM NULL
#define STORE_OBJECTCLOSE_DELIM_BM delim_dblanglequotright
#define STORE_OBJECTCLOSE_ALTDELIM_BM delim_exclamright
#define STORE_OBJECTCLOSE_TERDELIM_BM delim__NONE

// also delim_mu & delim_exclamcaret in load_second_pass_BM
#define STORE_MODULE_PREFIX_BM "µ"
#define STORE_MODULE_ALTPREFIX_BM "!^"
#define STORE_MODULE_TERPREFIX_BM NULL
#define STORE_MODULE_DELIM_BM delim_mu
#define STORE_MODULE_ATLDELIM_BM delim_exclamcaret
#define STORE_MODULE_TERDELIM_BM delim__NONE

// also delim_exclambar & delim_greekcapsigma  in load_second_pass_BM
#define STORE_FUNSIGNATURE_PREFIX_BM "Σ"       /*U+03A3 GREEK CAPITAL LETTER SIGMA */
#define STORE_FUNSIGNATURE_ALTPREFIX_BM "!|"
#define STORE_FUNSIGNATURE_TERPREFIX_BM NULL
#define STORE_FUNSIGNATURE_DELIM_BM delim_greekcapsigma
#define STORE_FUNSIGNATURE_ALTDELIM_BM delim_exclambar
#define STORE_FUNSIGNATURE_TERDELIM_BM delim__NONE

// also delim_element & delim_exclamdollar
#define STORE_CLASS_PREFIX_BM "∈"     /*U+2208 ELEMENT OF */
#define STORE_CLASS_ALTPREFIX_BM "!$"
#define STORE_CLASS_TERPREFIX_BM NULL
#define STORE_CLASS_DELIM_BM delim_element
#define STORE_CLASS_ALTDELIM_BM delim_exclamdollar
#define STORE_CLASS_TERDELIM_BM delim__NONE


// also delim_rightfrombar & delim_exclamcolon
#define STORE_ATTRIBUTE_PREFIX_BM "↦" /*U+21A6 RIGHTWARDS ARROW FROM BAR */
#define STORE_ATTRIBUTE_ALTPREFIX_BM "!:"
#define STORE_ATTRIBUTE_TERPREFIX_BM NULL
#define STORE_ATTRIBUTE_DELIM_BM delim_rightfrombar
#define STORE_ATTRIBUTE_ALTDELIM_BM delim_exclamcolon
#define STORE_ATTRIBUTE_TERDELIM_BM delim__NONE


// also delim_downtipright & delim_exclamand
#define STORE_COMPONENT_PREFIX_BM "↳" /*U+21B3 DOWNWARDS ARROW WITH TIP RIGHTWARDS */
#define STORE_COMPONENT_ALTPREFIX_BM "!&"
#define STORE_COMPONENT_TERPREFIX_BM "!&"
#define STORE_COMPONENT_DELIM_BM delim_downtipright
#define STORE_COMPONENT_ALTDELIM_BM delim_exclamand
#define STORE_COMPONENT_TERDELIM_BM delim__NONE

// also delim_plusminus & delim_exclamat
#define STORE_MODTIME_PREFIX_BM "±"    /*U+00B1 PLUS-MINUS SIGN */
#define STORE_MODTIME_ALTPREFIX_BM "!@"
#define STORE_MODTIME_TERPREFIX_BM NULL
#define STORE_MODTIME_DELIM_BM delim_plusminus
#define STORE_MODTIME_ALTDELIM_BM delim_exclamat
#define STORE_MODTIME_TERDELIM_BM delim__NONE

////////////////////////////////////////////////////////////////

#define EMPTY_TOKEN_BM (struct parstoken_stBM) { \
    .tok_kind= plex__NONE, .tok_line= -1, .tok_col= -1, .tok_ptr= NULL }

#define CONTRIBUTORS_FILE_BM "contributors_BM"
#define PASSWORDS_FILE_BM "passwords_BM"
#define MODULESRCDIR_BM "modules"
#define MODULEBINDIR_BM "modubin"
#define MODULEPREFIX_BM "modbm"
#define TEMPMODULEPREFIX_BM "tmpmobm"

/// each module should have DECLARE_MODULE_BM(BISMON_MODID); after inclusion of "bismon.h"
#define DECLARE_MODULE_BM(Id) const char module_id_BM[] = #Id

#define MAXSIZE_BM ((1<<30)-1)
#define TINYSIZE_BM 15

#define PARSERMEMOLINERATIO_BM 16
#define PARSOPMAGIC_BM 3144351953       /*0xbb6b00d1 */
// only used by FATAL_BM macro
extern void fatal_stop_at_BM (const char *, int) __attribute__((noreturn));
#define FATAL_AT_BIS_BM(Fil,Lin,Fmt,...) do {                   \
    fprintf(stderr, "BM FATAL:%s:%d: <%s>\n " Fmt "\n\n",       \
            Fil, Lin, __func__, ##__VA_ARGS__);                 \
    fatal_stop_at_BM(Fil,Lin); } while(0)

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
  prevfram_##Lin->stkfram_callfun = NULL;		\
  return;						\
 } while(0)
#define LOCALJUSTRETURN_ATLIN_BM(Lin) LOCALJUSTRETURN_ATLIN_BIS_BM(Lin)
#define LOCALJUSTRETURN_BM() LOCALJUSTRETURN_ATLIN_BM(__LINE__)


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
#define CONSTOBARRPREFIX_BM "constob"
#define CONSTIDARRPREFIX_BM "constid"
#define ROUTIDARRPREFIX_BM "routid"
#define ROUTINESUFFIX_BM "_BM"

/// the initializer of module of id _9oXtCgAbkqv_4y1xhhF5Nhz is
/// modulinit_9oXtCgAbkqv_4y1xhhF5Nhz_BM of type moduleinit_sigBM
#define MODULEINITPREFIX_BM "moduleinit"
#define MODULEINITSUFFIX_BM "_BM"

/// the checksum of module of id _9oXtCgAbkqv_4y1xhhF5Nhz is some
/// const char modulmd5chksum_9oXtCgAbkqv_4y1xhhF5Nhz_BM[]
#define MODULEMD5CHECKSUMPREFIX_BM "modulmd5chksum"
#define MODULEMD5CHECKSUMSUFFIX_BM "_BM"

#define GLOBAL_BM(Gnam) globdata_##Gnam##_BM


// we could use DBGPRINTF_BM and later replace it by NONPRINTF_BM
#define DBGPRINTFATBIS_BM(Fil,Lin,Fmt,...) do { \
    if (debugmsg_BM) {				\
      printf("%s:%d+ ", basename_BM((Fil)),	\
	     (Lin));				\
      printf(Fmt "\n", ##__VA_ARGS__); }	\
  } while(0)

#define DBGPRINTFAT_BM(Fil,Lin,Fmt,...) \
  DBGPRINTFATBIS_BM(Fil,Lin,Fmt,##__VA_ARGS__)

#define DBGPRINTF_BM(Fmt,...) \
  DBGPRINTFAT_BM(__FILE__,__LINE__,Fmt,##__VA_ARGS__)


////////////////

#define WARNPRINTFATBIS_BM(Fil,Lin,Fmt,...) do {	\
    fprintf(stderr, "%s:%d: ** " Fmt "\n",		\
	   basename_BM((Fil)), (Lin),			\
	 ##__VA_ARGS__);				\
} while(0)

#define WARNPRINTFAT_BM(Fil,Lin,Fmt,...) \
  WARNPRINTFATBIS_BM(Fil,Lin,Fmt,##__VA_ARGS__)

#define WARNPRINTF_BM(Fmt,...) \
  WARNPRINTFAT_BM(__FILE__,__LINE__,Fmt,##__VA_ARGS__)

////////////////
#define INFOPRINTFATBIS_BM(Fil,Lin,Fmt,...) do {	\
    fprintf(stderr, "%s:%d: !! " Fmt "\n",		\
	   basename_BM((Fil)), (Lin),			\
	 ##__VA_ARGS__);				\
} while(0)

#define INFOPRINTFAT_BM(Fil,Lin,Fmt,...) \
  INFOPRINTFATBIS_BM(Fil,Lin,Fmt,##__VA_ARGS__)

#define INFOPRINTF_BM(Fmt,...) \
  INFOPRINTFAT_BM(__FILE__,__LINE__,Fmt,##__VA_ARGS__)


//// to ease display of strbuffer objects
#define FMTOBJSTRBUF_BM "%s L/%u (lin.%d, col.%d, end'%s')"
#define OBJSTRBUFOUTMAC_BM(Mac,Ob) Mac(Ob),	\
  objstrbufferlengthpayl_BM(Ob),		\
  objstrbufferlinecountpayl_BM(Ob),		\
  objstrbuffercolumnpayl_BM(Ob),		\
  objstrbuffercurrentlastlinepayl_BM(Ob)

#define OBJSTRBUFOUT_BM(Ob) OBJSTRBUFOUTMAC_BM(objectdbg_BM, Ob)
#define OBJ1STRBUFOUT_BM(Ob) OBJSTRBUFOUTMAC_BM(objectdbg1_BM, Ob)
#define OBJ2STRBUFOUT_BM(Ob) OBJSTRBUFOUTMAC_BM(objectdbg2_BM, Ob)
#define OBJ3STRBUFOUT_BM(Ob) OBJSTRBUFOUTMAC_BM(objectdbg3_BM, Ob)
#define OBJ4STRBUFOUT_BM(Ob) OBJSTRBUFOUTMAC_BM(objectdbg4_BM, Ob)
#define OBJ5STRBUFOUT_BM(Ob) OBJSTRBUFOUTMAC_BM(objectdbg5_BM, Ob)
#define OBJ6STRBUFOUT_BM(Ob) OBJSTRBUFOUTMAC_BM(objectdbg6_BM, Ob)
#define OBJ7STRBUFOUT_BM(Ob) OBJSTRBUFOUTMAC_BM(objectdbg7_BM, Ob)

////////////////
/* the literal string used for local time, to the centisecond */
#define LOCAL_TIME_CENTISECOND_FMT_BM "%Y %b %d, %H:%M:%S.__ %Z"
////////////////

#define DBGBACKTRACEPRINTFATBIS_BM(Fil,Lin,Fmt,...) do {	\
    if (debugmsg_BM) { printf("%s:%d:+ " Fmt "\n",		\
			      basename_BM((Fil)), (Lin),	\
			      ##__VA_ARGS__);			\
      backtrace_print_BM					\
	((struct backtrace_state *) backtracestate_BM, 0,	\
	 stdout);						\
      printf("%s:%d: **** endbacktraceprintf ***\n\n",		\
	     basename_BM((Fil)), (Lin));			\
      fflush(stdout); }						\
} while(0)

#define DBGBACKTRACEPRINTFAT_BM(Fil,Lin,Fmt,...) \
  DBGBACKTRACEPRINTFATBIS_BM(Fil,Lin,Fmt,##__VA_ARGS__)

#define DBGBACKTRACEPRINTF_BM(Fmt,...) \
  DBGBACKTRACEPRINTFAT_BM(__FILE__,__LINE__,Fmt,##__VA_ARGS__)

#define DBGNONBACKTRACEPRINTF_FM(Fmt,...) DBGPRINTF_BM(Fmt,##__VA_ARGS__)

  ////////////////
#define NONPRINTF_BM(Fmt,...) do { if (false) \
      DBGPRINTF_BM(Fmt,##__VA_ARGS__); } while(0)

#define FAILURE_AT_BIS_BM(Fcod,Fil,Lin,Reason,Place,Stack)		\
  do {failure_at_BM((Fcod),(Fil),(Lin),(Reason),(Place),(Stack));} while(0)

#define FAILURE_AT_BM(Fcod,Fil,Lin,Reason,Place,Stack) \
  FAILURE_AT_BIS_BM(Fcod,Fil,Lin,Reason,Place,Stack)
#define PLAINFAILURE_BM(FailCod,Reason,Stack) FAILURE_AT_BM((FailCod),__FILE__,__LINE__,(Reason),taggedint_BM(FailCod),(Stack))
#define PLACEDFAILURE_BM(FailCod,Reason,Place,Stack) FAILURE_AT_BM((FailCod),__FILE__,__LINE__,(Reason),(Place),(Stack))

#define CURFRAME_BM ((struct stackframe_stBM*)&_)



#define OUTSTRVALUE_BM(Val) debug_outstr_value_BM((Val),CURFRAME_BM,0)


#define LOCAL_FAILURE_HANDLE_ATBIS_BM(Fil,Lin,Lockset,Flabel,FcodVar,ReasonVar,PlaceVar) \
  struct failurehandler_stBM fh_##Lin					\
   = {									\
     .pA = {.htyp = typayl_FailureHandler_BM},				\
     .failh_magic = FAILUREHANDLEMAGIC_BM,				\
     .failh_lockset = Lockset,						\
     .failh_reason = NULL,						\
     .failh_jmpbuf = {}};						\
  curfailurehandle_BM = &fh_##Lin;					\
  volatile int failcod_##Lin =  setjmp(fh_##Lin.failh_jmpbuf);		\
  FcodVar = failcod_##Lin;						\
  if (failcod_##Lin) {							\
    ReasonVar = fh_##Lin.failh_reason;					\
    PlaceVar = fh_##Lin.failh_place;					\
    goto Flabel;							\
  };									\
  (void)0

#define LOCAL_FAILURE_HANDLE_AT_BM(Fil,Lin,Lockset,Flabel,FcodVar,ReasonVar,PlaceVar) \
  LOCAL_FAILURE_HANDLE_ATBIS_BM(Fil,Lin,Lockset,Flabel,FcodVar,ReasonVar,PlaceVar)

/// code using LOCAL_FAILURE_HANDLE_BM should probably backup and
/// restore the curfailurehandle_BM
#define LOCAL_FAILURE_HANDLE_BM(Lockset,Flabel,FcodVar,ReasonVar,PlaceVar)	\
  LOCAL_FAILURE_HANDLE_AT_BM(__FILE__,__LINE__,Lockset,Flabel,FcodVar,ReasonVar,PlaceVar)

// weak assert dont abort
extern void weakassertfailureat_BM (const char *condmsg, const char *fil,
                                    int lin);
#ifndef NDEBUG
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
#define MAXNBWORKJOBS_BM 24
#define MINNBWORKJOBS_BM 2
#endif /*CMACROS_BM_INCLUDED */
