// file fundecl_BM.h
#ifndef FUNDECL_BM_INCLUDED
#define FUNDECL_BM_INCLUDED

extern void abort_BM (void) __attribute__ ((noreturn));

static inline bool istaggedint_BM (value_tyBM v);
static inline intptr_t getint_BM (value_tyBM v);
static inline value_tyBM taggedint_BM (intptr_t i);

static inline int valtype_BM (const value_tyBM v);

static inline bool validserial63_BM (serial63_tyBM s);
extern serial63_tyBM randomserial63_BM (void);
extern int serial63tocbuf16_BM (serial63_tyBM s, char cbuf[static 16]);
extern serial63_tyBM parse_serial63_BM (const char *buf, const char **pend);
extern rawid_tyBM randomid_BM (void);
static inline bool validid_BM (rawid_tyBM id);
static inline hash_tyBM hashid_BM (rawid_tyBM id);
static inline int cmpid_BM (rawid_tyBM id1, rawid_tyBM id2);
static inline bool equalid_BM (rawid_tyBM id1, rawid_tyBM id2);
extern int idtocbuf32_BM (rawid_tyBM id, char cbuf[static 32]);
extern rawid_tyBM parse_rawid_BM (const char *buf, const char **pend);
extern void *allocgcty_BM (unsigned type, size_t sz);
extern void *allocinternalty_BM (unsigned type, size_t sz);

extern hash_tyBM stringhash_BM (const char *str);
extern const stringval_tyBM *stringmake_BM (const char *str);
extern const stringval_tyBM *stringprintf_BM (const char *fmt, ...)
  __attribute__ ((format (printf, 1, 2)));
extern int lenstring_BM (const stringval_tyBM *);
extern const char *bytstring_BM (const stringval_tyBM *);

extern const tupleval_tyBM *tuplemake_BM (objectval_tyBM ** arr,
                                          unsigned rawsiz);
extern unsigned tuplesize_BM (const tupleval_tyBM * tup);
extern objectval_tyBM *tuplecompnth_BM (const tupleval_tyBM * tup, int rk);

extern const setval_tyBM *setmake_BM (objectval_tyBM ** arr, unsigned rawsiz);
extern bool setcontains_BM (const objectval_tyBM * obelem,
                            const setval_tyBM * setv);
extern unsigned setcardinal_BM (const setval_tyBM * setv);
extern objectval_tyBM *setelemnth_BM (const setval_tyBM * set, int rk);


static inline hash_tyBM objecthash_BM (const objectval_tyBM *);

static inline int objectcmp_BM (const objectval_tyBM * ob1,
                                const objectval_tyBM * ob2);
extern void sortobjarr_BM (const objectval_tyBM ** obarr, size_t arrsiz);

extern int64_t prime_above_BM (int64_t n);
extern int64_t prime_below_BM (int64_t n);

static inline bool isassoc_BM (value_tyBM);
static inline unsigned assoc_nbkeys_BM (const anyassoc_tyBM * assoc);

extern void assoc_reorganize_BM (anyassoc_tyBM ** passoc, unsigned gap);

extern const setval_tyBM *assoc_setattrs_BM (const anyassoc_tyBM * assoc);
extern value_tyBM assoc_getattr_BM (const anyassoc_tyBM * assoc,
                                    const objectval_tyBM * obattr);
extern anyassoc_tyBM *assoc_addattr_BM (anyassoc_tyBM * assoc,
                                        const objectval_tyBM * obattr,
                                        value_tyBM val);
extern anyassoc_tyBM *assoc_removeattr_BM (anyassoc_tyBM * assoc,
                                           const objectval_tyBM * obattr);

#endif /*FUNDECL_BM_INCLUDED */
