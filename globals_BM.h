// file globals_BM.h
#ifndef GLOBALS_BM_INCLUDED
#define GLOBALS_BM_INCLUDED
// from generated _timestamp.c
extern const char bismon_timestamp[];
extern const unsigned long bismon_timelong;
extern const char bismon_lastgitcommit[];
extern const char bismon_lastgittag[];
extern const char bismon_checksum[];
extern const char bismon_directory[];
extern const char bismon_makefile[];


extern void *dlprog_BM;         // dlopen of entire program
extern struct timespec startrealtimespec_BM;

extern struct allalloc_stBM *allocationvec_vBM /*¤ allocgc_BM.c */ ;

#define HAS_PREDEF_BM(Id,Hi,Lo,Hash) \
  extern objectval_tyBM predefdata##Id##_BM; \
  extern objectval_tyBM* predefptr##Id##_BM;
#include "_bm_predef.h"

#define PREDEF_BM(Id) (predefptr##Id##_BM)

extern const typedhead_tyBM unspecifieddata_BM;

#define UNSPECIFIED_BM ((void*)(&unspecifieddata_BM))
#endif /*GLOBALS_BM_INCLUDED */
