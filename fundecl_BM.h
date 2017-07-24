// file fundecl_BM.h
#ifndef FUNDECL_BM_INCLUDED
#define FUNDECL_BM_INCLUDED

extern void abort_BM (void) __attribute__ ((noreturn));

static inline double clocktime_BM (clockid_t);
static inline double cputime_BM (void);
static inline double elapsedtime_BM (void);
static inline bool istaggedint_BM (value_tyBM v);
static inline intptr_t getint_BM (value_tyBM v);
static inline value_tyBM taggedint_BM (intptr_t i);

static inline int valtype_BM (const value_tyBM v);

static inline bool validserial63_BM (serial63_tyBM s);
extern serial63_tyBM randomserial63_BM (void);
extern int serial63tocbuf16_BM (serial63_tyBM s, char cbuf[static 16]);
extern serial63_tyBM parse_serial63_BM (const char *buf, const char **pend);
static inline unsigned bucknumserial63_BM (serial63_tyBM s);
static inline uint64_t buckoffserial63_BM (serial63_tyBM s);

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

extern const setval_tyBM *setmake_BM (const objectval_tyBM ** arr,
                                      unsigned rawsiz);
extern bool setcontains_BM (const objectval_tyBM * obelem,
                            const setval_tyBM * setv);
extern unsigned setcardinal_BM (const setval_tyBM * setv);
extern objectval_tyBM *setelemnth_BM (const setval_tyBM * set, int rk);




static inline hash_tyBM objecthash_BM (const objectval_tyBM *);

static inline int objectcmp_BM (const objectval_tyBM * ob1,
                                const objectval_tyBM * ob2);
extern void sortobjarr_BM (const objectval_tyBM ** obarr, size_t arrsiz);

extern objectval_tyBM *findobjofid_BM (const rawid_tyBM id);
extern objectval_tyBM *makeobjofid_BM (const rawid_tyBM id);
extern objectval_tyBM *makeobj_BM (void);
static inline rawid_tyBM objid_BM (const objectval_tyBM * obj);
static inline void objtouchmtime_BM (objectval_tyBM * obj, double mtime);
static inline void objtouchnow_BM (objectval_tyBM * obj);
extern void initialize_predefined_objects_BM (void);

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


static inline unsigned datavectlen_BM (const struct datavectval_stBM *dvec);

extern struct datavectval_stBM *datavect_grow_BM (struct datavectval_stBM
                                                  *dvec, unsigned gap);

extern struct datavectval_stBM *datavect_reserve_BM (struct datavectval_stBM
                                                     *dvec, unsigned gap);

extern struct datavectval_stBM *datavect_append_BM (struct datavectval_stBM
                                                    *dvec, value_tyBM val);

static inline value_tyBM datavectnth_BM (const struct datavectval_stBM *dvec,
                                         int rk);

extern struct hashsetobj_stBM *hashsetobj_grow_BM (struct hashsetobj_stBM
                                                   *hset, unsigned gap);
extern bool hashsetobj_contains_BM (struct hashsetobj_stBM *hset,
                                    const objectval_tyBM * obj);
extern struct hashsetobj_stBM *hashsetobj_add_BM (struct hashsetobj_stBM
                                                  *hset,
                                                  const objectval_tyBM * obj);
extern struct hashsetobj_stBM *hashsetobj_remove_BM (struct hashsetobj_stBM
                                                     *hset,
                                                     const objectval_tyBM *
                                                     obj);
extern const setval_tyBM *hashsetobj_to_set_BM (struct hashsetobj_stBM *hset);

extern struct listtop_stBM *listmake_BM (void);
static inline bool islist_BM (const value_tyBM);
static inline value_tyBM listfirst_BM (const struct listtop_stBM *);
static inline value_tyBM listlast_BM (const struct listtop_stBM *);
static inline unsigned listlength_BM (const struct listtop_stBM *);
extern void listappend_BM (struct listtop_stBM *lis, value_tyBM val);
extern void listprepend_BM (struct listtop_stBM *lis, value_tyBM val);
extern void listpopfirst (struct listtop_stBM *lis);
extern void listpoplast (struct listtop_stBM *lis);
extern const node_tyBM *list_to_node_BM (const struct listtop_stBM *lis,
                                         const objectval_tyBM * conn);



extern void load_initial_BM (const char *);
#endif /*FUNDECL_BM_INCLUDED */
