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
static inline hash_tyBM valhash_BM (const value_tyBM v);
static inline uint8_t valgcmark_BM (const value_tyBM v);
static inline bool valequal_BM (const value_tyBM v1, const value_tyBM v2);
extern bool valsamecontent_BM (const value_tyBM v1, const value_tyBM v2);

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
extern const stringval_tyBM *makestring_BM (const char *str);
extern const stringval_tyBM *sprintfstring_BM (const char *fmt, ...)
  __attribute__ ((format (printf, 1, 2)));
extern int lenstring_BM (const stringval_tyBM *);
extern const char *bytstring_BM (const stringval_tyBM *);

extern const tupleval_tyBM *maketuple_BM (objectval_tyBM ** arr,
                                          unsigned rawsiz);
extern unsigned tuplesize_BM (const tupleval_tyBM * tup);
extern objectval_tyBM *tuplecompnth_BM (const tupleval_tyBM * tup, int rk);
extern void tuplegcmark_BM (struct garbcoll_stBM *gc, tupleval_tyBM * tup);

extern const setval_tyBM *makeset_BM (const objectval_tyBM ** arr,
                                      unsigned rawsiz);
extern bool setcontains_BM (const objectval_tyBM * obelem,
                            const setval_tyBM * setv);
extern unsigned setcardinal_BM (const setval_tyBM * setv);
extern objectval_tyBM *setelemnth_BM (const setval_tyBM * set, int rk);
extern void setgcmark_BM (struct garbcoll_stBM *gc, setval_tyBM * set);


static inline bool isobject_BM (const value_tyBM v);
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
void assocgcmark_BM (struct garbcoll_stBM *gc, anyassoc_tyBM * assoc,
                     int depth);

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
void hashsetgcmark_BM (struct garbcoll_stBM *gc,
                       struct hashsetobj_stBM *hset);
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

extern struct listtop_stBM *makelist_BM (void);
static inline bool islist_BM (const value_tyBM);
static inline value_tyBM listfirst_BM (const struct listtop_stBM *);
static inline value_tyBM listlast_BM (const struct listtop_stBM *);
static inline unsigned listlength_BM (const struct listtop_stBM *);
extern void listclear_BM (struct listtop_stBM *lis);
extern void listappend_BM (struct listtop_stBM *lis, value_tyBM val);
extern void listprepend_BM (struct listtop_stBM *lis, value_tyBM val);
extern void listpopfirst_BM (struct listtop_stBM *lis);
extern void listpoplast_BM (struct listtop_stBM *lis);
extern void list_destroy_BM (struct listtop_stBM *lis);
extern void listgcmark_BM (struct garbcoll_stBM *gc, struct listtop_stBM *lis,
                           int depth);
// make a node from all components of the list
extern const node_tyBM *list_to_node_BM (const struct listtop_stBM *lis,
                                         const objectval_tyBM * conn);
// make a tuple from the objects in the list
extern const tupleval_tyBM *list_to_tuple_BM (const struct listtop_stBM *lis);


static inline bool istree_BM (const value_tyBM v);
static inline bool isclosure_BM (const value_tyBM v);
static inline bool isnode_BM (const value_tyBM v);

static inline objectval_tyBM *treeconn_BM (const value_tyBM);
static inline objectval_tyBM *closureconn_BM (const value_tyBM);
static inline objectval_tyBM *nodeconn_BM (const value_tyBM);

static inline unsigned treewidth_BM (const value_tyBM);
static inline unsigned closurewidth_BM (const value_tyBM);
static inline unsigned nodewidth_BM (const value_tyBM);

static inline value_tyBM treenthson_BM (const value_tyBM tr, int rk);
static inline value_tyBM closurenthson_BM (const value_tyBM clo, int rk);
static inline value_tyBM nodenthson_BM (const value_tyBM nod, int rk);

extern void nodegcmark_BM (struct garbcoll_stBM *gc, node_tyBM * nod,
                           int depth);

const node_tyBM *makenode_BM (const objectval_tyBM * connob, unsigned nbval,
                              const value_tyBM * sonvalarr);

extern const closure_tyBM *makeclosure_BM (const objectval_tyBM * conn,
                                           unsigned nbclos,
                                           const value_tyBM * closvalarr);
extern void closuregcmark_BM (struct garbcoll_stBM *gc, closure_tyBM * clos,
                              int depth);

extern void load_initial_BM (const char *);
extern void loadergcmark_BM (struct garbcoll_stBM *gc,
                             struct loader_stBM *ld);

//// parsing
extern struct parser_stBM *makeparser_of_file_BM (FILE * f);
extern struct parser_stBM *makeparser_memopen_BM (const char *filemem,
                                                  long size);
static inline bool isparser_BM (const value_tyBM v);
extern void parsergcmark_BM (struct garbcoll_stBM *gc,
                             struct parser_stBM *pars);
extern bool parsernextline_BM (struct parser_stBM *pars);       // return false on EOL
static inline unsigned parserlineno_BM (const struct parser_stBM *pars);
static inline unsigned parsercolpos_BM (const struct parser_stBM *pars);
static inline const char *parserrestline_BM (const struct parser_stBM *pars);
extern void parserseek_BM (struct parser_stBM *pars, unsigned line,
                           unsigned col);
void parsererrorprintf_BM (struct parser_stBM *, unsigned line, unsigned col,
                           const char *fmt, ...)
  __attribute__ ((format (printf, 4, 5), noreturn));
// skip spaces and comments
void parserskipspaces_BM (struct parser_stBM *pars);

// internal routines
void gcmark_BM (struct garbcoll_stBM *gc, value_tyBM val, int depth);
void gcobjmark_BM (struct garbcoll_stBM *gc, objectval_tyBM * obj);
void gcframemark_BM (struct garbcoll_stBM *gc,
                     struct stackframe_stBM *stkfram, int depth);

#endif /*FUNDECL_BM_INCLUDED */
