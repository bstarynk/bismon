// file object_BM.c
#include "bismon.h"

#define HAS_PREDEF_BM(Id,Hi,Lo,Hash) objectval_tyBM predefdata##Id##_BM = { \
 .pA = (typedhead_tyBM){.htyp= tyObject_BM, .hgc=0, .hash= Hash}, \
 .ob_id = (rawid_tyBM){.id_hi= Hi, .id_lo= Lo} \
  }; \
  objectval_tyBM* predefptr##Id##_BM = &predefdata##Id##_BM;

#include "_bm_predef.h"

// for qsort
static int
objptrqcmp_BM (const void *p1, const void *p2)
{
  return objectcmp_BM (*(const objectval_tyBM **) p1,
                       *(const objectval_tyBM **) p2);
}                               /* end objptrqcmp_BM */

void
sortobjarr_BM (const objectval_tyBM ** obarr, size_t arrsiz)
{
  if (obarr == NULL)
    arrsiz = 0;
  if (arrsiz > 1)
    qsort (obarr, arrsiz, sizeof (const objectval_tyBM *), objptrqcmp_BM);
}                               /* end sortobjarr_BM */
