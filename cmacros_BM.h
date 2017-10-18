// file cmacros_BM.h
#ifndef CMACROS_BM_INCLUDED
#define CMACROS_BM_INCLUDED

#define MAXDEPTHGC_BM 256
#define MAXDEPTHPARSE_BM 96
#define MAXDEPTHMETHOD_BM 96
#define MARKGC_BM 1
#define CLEARMGC_BM 0
#define GCMAGIC_BM 24501383     /*0x175dc87 */

#define HASHSETEMPTYSLOT_BM ((void*)(-1))

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

#define LOCALFRAME_BM(Prev,Descr,...) struct                    \
  { struct stackframe_stBM __frame; __VA_ARGS__; } _ =          \
    { .__frame = {.stkfram_pA=                                  \
                  (typedhead_tyBM)                              \
                  {.htyp= tydata_StackFrame_BM,                 \
                   .hgc=0,                                      \
                   .rlen=(sizeof(_)                             \
                          - offsetof(struct stackframe_stBM,    \
                                     stkfram_locals))           \
                   /sizeof(value_tyBM)},                        \
                  .stkfram_prev=(Prev),                         \
                  .stkfram_descr=(Descr),                       \
                  .stkfram_state=0,                             \
                  .stkfram_xtra=0 } }

#define LOCALQNODESIZED_BM(Qnam,Conn,Siz) struct {			\
    struct nodetree_stBM __ntree; value_tyBM qsons[Siz]; } Qnam =	\
      { .__ntree = { .pA = { .pA					\
			     = { .htyp= tydata_quasinode_BM,		\
				 .hgc=0, .hash=0 }, .size = (Siz) },	\
		     .nodt_conn= (Conn) }, .qsons= {} }

#define LOCALQNODEFIELDED_BM(Qnam,Conn,...) struct {			\
  struct nodetree_stBM __ftree; __VA_ARGS__; } Qnam =			\
      { .__ftree = { .pA						\
		     = { .pA						\
			 = { .htyp= tydata_quasinode_BM,		\
			     .hgc=0, .hash=0 },				\
			 .size =					\
			  ((sizeof(Qnam)-offsetof(tree_tyBM,nodt_sons)) \
			   /sizeof(value_tyBM)) },			\
		     .nodt_conn= (Conn) } }

/// the routine inside object of id _60mLNh9vtVY_0pwkHRtJ44k would be
/// named crout_60mLNh9vtVY_0pwkHRtJ44k_BM
#define ROUTINEOBJNAME_BM(Id) crout##Id##_BM
#define ROUTINEOBJPREFIX_BM "crout"
#define ROUTINEOBJSUFFIX_BM "_BM"

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

// weak assert dont abort
#ifndef NDEBUG
extern void weakassertfailureat_BM (const char *condmsg, const char *fil,
                                    int lin);
#define WEAKASSERT_BM(Cond) do { if(!(Cond)) \
      { weakassertfailureat_BM(#Cond,__FILE__,__LINE__); return 0; }} \
  while(0)
#else
#define WEAKASSERT_BM(Cond) do if(false && !(Cond)) \
      {  return 0; }} while(0)
#endif /*NDEBUG*/
#endif /*CMACROS_BM_INCLUDED */
