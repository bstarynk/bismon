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

extern struct allalloc_stBM* allocationvec_vBM /*¤ allocgc_BM.c*/;

#define BM_HAS_PREDEF(Id,Hi,Lo,Hash) \
  extern objectval_tyBM predefdata##Id##_BM; \
  extern objectval_tyBM* predefptr##Id##_BM;
#include "_bm_predef.h"

#define BM_PREDEF(Id) (predefptr##Id##_BM)
#endif /*GLOBALS_BM_INCLUDED*/
