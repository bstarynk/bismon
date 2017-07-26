// file cmacros_BM.h
#ifndef CMACROS_BM_INCLUDED
#define CMACROS_BM_INCLUDED

#define MAXDEPTHGC_BM 256
#define MARKGC_BM 1
#define GCMAGIC_BM 24501383     /*0x175dc87 */

#define LOADERMAGIC_BM 281610361        /*0x10c90879 */
#define MAXLOADEDFILES_BM 64

#define MINSERIAL_BM (62*62)    /*3884 */
#define MAXSERIAL_BM ((uint64_t)10 * 62 * (62* 62*62) * (62*62*62) * (62*62*62))        /*8392993658683402240 */
#define DELTASERIAL_BM (MAXSERIAL_BM-MINSERIAL_BM)
#define MAXBUCKETS_BM (10*62)
#define B62DIGITS_BM   "0123456789"  "abcdefghijklmnopqrstuvwxyz"  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

#define SERIALDIGITS_BM 11
#define SERIALBASE_BM 62

#define IDLEN_BM 24
#define MAXSIZE_BM ((1<<30)-1)
#define TINYSIZE_BM 15

#define PARSERMEMOLINERATIO_BM 16
#define PARSOPMAGIC_BM 3144351953       /*0xbb6b00d1 */
#define FATAL_AT_BIS_BM(Fil,Lin,Fmt,...) do {                   \
    fprintf(stderr, "BM FATAL:%s:%d: <%s>\n " Fmt "\n\n",       \
            Fil, Lin, __func__, ##__VA_ARGS__);                 \
    abort_BM(); } while(0)

#define FATAL_AT_BM(Fil,Lin,Fmt,...) FATAL_AT_BIS_BM(Fil,Lin,Fmt,##__VA_ARGS__)

#define FATAL_BM(Fmt,...) FATAL_AT_BM(__FILE__,__LINE__,Fmt,##__VA_ARGS__)

#endif /*CMACROS_BM_INCLUDED */
