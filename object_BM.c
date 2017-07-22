// file object_BM.c
#include "bismon.h"

#define BM_HAS_PREDEF(Id,Hi,Lo,Hash) objectval_tyBM predefdata##Id##_BM = { \
 .pA = (typedhead_tyBM){.htyp= tyObject_BM, .hgc=0, .hash= Hash}, \
 .ob_id = (rawid_tyBM){.id_hi= Hi, .id_lo= Lo} \
  }; \
  objectval_tyBM* predefptr##Id##_BM = &predefdata##Id##_BM;

#include "_bm_predef.h"
