// file fundecl_BM.h
#ifndef FUNDECL_BM_INCLUDED
#define FUNDECL_BM_INCLUDED

extern void abort_BM (void) __attribute__ ((noreturn));

extern int64_t prime_above_BM (int64_t n);
extern int64_t prime_below_BM (int64_t n);


static inline double clocktime_BM (clockid_t);
static inline double cputime_BM (void);
static inline double elapsedtime_BM (void);
static inline bool istaggedint_BM (value_tyBM v);
static inline intptr_t getint_BM (value_tyBM v);
static inline value_tyBM taggedint_BM (intptr_t i);

static inline int valtype_BM (const value_tyBM v);
static inline objectval_tyBM *valclass_BM (const value_tyBM v);
static inline hash_tyBM valhash_BM (const value_tyBM v);
static inline uint8_t valgcmark_BM (const value_tyBM v);
void valgcdestroy_BM (struct garbcoll_stBM *, value_tyBM v);
void valgckeep_BM (struct garbcoll_stBM *, value_tyBM v);
static inline bool valequal_BM (const value_tyBM v1, const value_tyBM v2);
extern bool valsamecontent_BM (const value_tyBM v1, const value_tyBM v2);

static inline bool validserial63_BM (serial63_tyBM s);
extern serial63_tyBM randomserial63_BM (void);
#if __cplusplus
extern int serial63tocbuf16_BM (serial63_tyBM s, char cbuf[]);
#else
extern int serial63tocbuf16_BM (serial63_tyBM s, char cbuf[static 16]);
#endif

extern serial63_tyBM parse_serial63_BM (const char *buf, const char **pend);
static inline unsigned bucknumserial63_BM (serial63_tyBM s);
static inline uint64_t buckoffserial63_BM (serial63_tyBM s);

extern rawid_tyBM randomid_BM (void);
static inline bool validid_BM (rawid_tyBM id);
static inline hash_tyBM hashid_BM (rawid_tyBM id);
static inline int cmpid_BM (rawid_tyBM id1, rawid_tyBM id2);
static inline bool equalid_BM (rawid_tyBM id1, rawid_tyBM id2);
#if __cplusplus
extern int idtocbuf32_BM (rawid_tyBM id, char cbuf[]);
#else
extern int idtocbuf32_BM (rawid_tyBM id, char cbuf[static 32]);
#endif
extern rawid_tyBM parse_rawid_BM (const char *buf, const char **pend);
extern void *allocgcty_BM (unsigned type, size_t sz);
extern void *allocinternalty_BM (unsigned type, size_t sz);

extern hash_tyBM stringhash_BM (const char *str);
extern const stringval_tyBM *makestring_BM (const char *str);
extern const stringval_tyBM *sprintfstring_BM (const char *fmt, ...)
  __attribute__ ((format (printf, 1, 2)));
extern int lenstring_BM (const stringval_tyBM *);
extern const char *bytstring_BM (const stringval_tyBM *);
extern void stringgcdestroy_BM (struct garbcoll_stBM *, stringval_tyBM *);

extern void stringgckeep_BM (struct garbcoll_stBM *, stringval_tyBM *);

extern const tupleval_tyBM *maketuple_BM (objectval_tyBM ** arr,
                                          unsigned rawsiz);
extern unsigned tuplesize_BM (const tupleval_tyBM * tup);
extern objectval_tyBM *tuplecompnth_BM (const tupleval_tyBM * tup, int rk);
extern void tuplegcmark_BM (struct garbcoll_stBM *gc, tupleval_tyBM * tup);
extern void tuplegcdestroy_BM (struct garbcoll_stBM *gc, tupleval_tyBM * tup);
extern void tuplegckeep_BM (struct garbcoll_stBM *gc, tupleval_tyBM * tup);

extern const setval_tyBM *makeset_BM (const objectval_tyBM ** arr,
                                      unsigned rawsiz);
extern bool setcontains_BM (const objectval_tyBM * obelem,
                            const setval_tyBM * setv);
extern unsigned setcardinal_BM (const setval_tyBM * setv);
extern objectval_tyBM *setelemnth_BM (const setval_tyBM * set, int rk);
extern void setgcmark_BM (struct garbcoll_stBM *gc, setval_tyBM * set);
extern void setgcdestroy_BM (struct garbcoll_stBM *gc, setval_tyBM * set);
extern void setgckeep_BM (struct garbcoll_stBM *gc, setval_tyBM * set);


extern void initialize_predefined_objects_BM (void);

static inline bool isobject_BM (const value_tyBM v);
static inline hash_tyBM objecthash_BM (const objectval_tyBM *);

static inline int objectcmp_BM (const objectval_tyBM * ob1,
                                const objectval_tyBM * ob2);
extern void sortobjarr_BM (const objectval_tyBM ** obarr, size_t arrsiz);

extern objectval_tyBM *findobjofid_BM (const rawid_tyBM id);
extern objectval_tyBM *makeobjofid_BM (const rawid_tyBM id);
extern objectval_tyBM *makeobj_BM (void);
static inline rawid_tyBM objid_BM (const objectval_tyBM * obj);
static inline double objmtime_BM (const objectval_tyBM * obj);
static inline void objtouchmtime_BM (objectval_tyBM * obj, double mtime);
static inline void objtouchnow_BM (objectval_tyBM * obj);
extern void objputspacenum_BM (objectval_tyBM * obj, unsigned spanum);
static inline unsigned objspacenum_BM (objectval_tyBM * obj);
static inline objectval_tyBM *objclass_BM (objectval_tyBM * obj);
extern void objputclass_BM (objectval_tyBM * obj, objectval_tyBM * objclass);

static inline value_tyBM objgetattr_BM (objectval_tyBM * obj,
                                        objectval_tyBM * objattr);
static inline unsigned objnbattrs_BM (objectval_tyBM * obj);
static inline const setval_tyBM *objsetattrs_BM (objectval_tyBM * obj);

extern void objputattr_BM (objectval_tyBM * obj, objectval_tyBM * objattr,
                           value_tyBM valattr);
extern void objremoveattr_BM (objectval_tyBM * obj, objectval_tyBM * objattr);

static inline bool objhasclassinfo_BM (objectval_tyBM * obj);
// put a fresh classinfo as an object's data
extern void objputclassinfo_BM (objectval_tyBM * obj,
                                objectval_tyBM * superclass);
static inline objectval_tyBM *  //
  objgetclassinfosuperclass_BM (objectval_tyBM * obj);

static inline const closure_tyBM *      //

 objgetclassinfomethod_BM (objectval_tyBM * obj, objectval_tyBM * obselector);

extern void
objclassinfoputmethod_BM (objectval_tyBM * obj, objectval_tyBM * obselector,
                          const closure_tyBM * clos);

extern void
objclassinforemovemethod_BM (objectval_tyBM * obj,
                             objectval_tyBM * obselector);

static inline const setval_tyBM *       //
  objgetclassinfosetofselectors_BM (objectval_tyBM * obj);

static inline unsigned objnbcomps_BM (objectval_tyBM * obj);
static inline value_tyBM objgetcomp_BM (objectval_tyBM * obj, int rk);
static inline void objreservecomps_BM (objectval_tyBM * obj, unsigned gap);
static inline void objappendcomp_BM (objectval_tyBM * obj,
                                     value_tyBM compval);
static inline void objgrowcomps_BM (objectval_tyBM * obj, unsigned gap);

extern const setval_tyBM *setpredefinedobjects_BM (void);
extern void gcmarkpredefinedobjects_BM (struct garbcoll_stBM *gc);

extern void objectinteriorgcmark_BM (struct garbcoll_stBM *gc,
                                     objectval_tyBM * obj);
extern void objectgcdestroy_BM (struct garbcoll_stBM *gc,
                                objectval_tyBM * obj);
extern void objectgckeep_BM (struct garbcoll_stBM *gc, objectval_tyBM * obj);



////////////////
extern struct strbuffer_stBM *strbuffermake_BM (unsigned maxsize);
static inline bool isstrbuffer_BM (const value_tyBM val);
extern void strbufferreserve_BM (struct strbuffer_stBM *sbuf, unsigned gap);
static inline const char *strbufferbytes_BM (struct strbuffer_stBM *sbuf);
static inline int strbufferindentation_BM (struct strbuffer_stBM *sbuf);
extern void strbufferclearindent_BM (struct strbuffer_stBM *sbuf);
extern void strbuffermoreindent_BM (struct strbuffer_stBM *sbuf);
extern void strbufferlessindent_BM (struct strbuffer_stBM *sbuf);
extern void strbufferappendcstr_BM (struct strbuffer_stBM *sbuf,
                                    const char *cstr);
/// raw printf
extern void strbufferrawprintf_BM (struct strbuffer_stBM *sbuf,
                                   const char *fmt, ...)
  __attribute__ ((format (printf, 2, 3)));
/// cooked printf: the tabs become spaces or indented-newlines, the
/// newlinesb become indented
extern void strbufferprintf_BM (struct strbuffer_stBM *sbuf, const char *fmt,
                                ...) __attribute__ ((format (printf, 2, 3)));
/// indented newline
extern void strbuffernewline_BM (struct strbuffer_stBM *sbuf);

extern void strbuffergcmark_BM (struct garbcoll_stBM *gc,
                                struct strbuffer_stBM *sbuf, int depth);
extern void strbuffergcdestroy_BM (struct garbcoll_stBM *gc,
                                   struct strbuffer_stBM *sbuf);
extern void strbuffergckeep_BM (struct garbcoll_stBM *gc,
                                struct strbuffer_stBM *sbuf);
////////////////


static inline bool isassoc_BM (value_tyBM);
extern void assocgcmark_BM (struct garbcoll_stBM *gc, anyassoc_tyBM * assoc,
                            int depth);
extern void assocpairgcdestroy_BM (struct garbcoll_stBM *gc,
                                   struct assocpairs_stBM *assocpair);
extern void assocbucketgcdestroy_BM (struct garbcoll_stBM *gc,
                                     struct assocbucket_stBM *assocbuck);
extern void assocpairgckeep_BM (struct garbcoll_stBM *gc,
                                struct assocpairs_stBM *assocpair);
extern void assocbucketgckeep_BM (struct garbcoll_stBM *gc,
                                  struct assocbucket_stBM *assocbuck);

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
extern void datavectgcmark_BM (struct garbcoll_stBM *gc,
                               const struct datavectval_stBM *dvec,
                               int depth);
extern void datavectgcdestroy_BM (struct garbcoll_stBM *gc,
                                  struct datavectval_stBM *dvec);
extern void datavectgckeep_BM (struct garbcoll_stBM *gc,
                               struct datavectval_stBM *dvec);

extern struct hashsetobj_stBM *hashsetobj_grow_BM (struct hashsetobj_stBM
                                                   *hset, unsigned gap);
void hashsetgcmark_BM (struct garbcoll_stBM *gc,
                       struct hashsetobj_stBM *hset);
void hashsetgcdestroy_BM (struct garbcoll_stBM *gc,
                          struct hashsetobj_stBM *hset);
void hashsetgckeep_BM (struct garbcoll_stBM *gc,
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
extern void listgcdestroy_BM (struct garbcoll_stBM *gc,
                              struct listtop_stBM *lis);
extern void listgckeep_BM (struct garbcoll_stBM *gc,
                           struct listtop_stBM *lis);
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
extern void nodegcdestroy_BM (struct garbcoll_stBM *gc, node_tyBM * nod);
extern void nodegckeep_BM (struct garbcoll_stBM *gc, node_tyBM * nod);

const node_tyBM *makenode_BM (const objectval_tyBM * connob, unsigned nbval,
                              const value_tyBM * sonvalarr);

extern const closure_tyBM *makeclosure_BM (const objectval_tyBM * conn,
                                           unsigned nbclos,
                                           const value_tyBM * closvalarr);
extern void closuregcmark_BM (struct garbcoll_stBM *gc, closure_tyBM * clos,
                              int depth);
extern void closuregcdestroy_BM (struct garbcoll_stBM *gc,
                                 closure_tyBM * clos);
extern void closuregckeep_BM (struct garbcoll_stBM *gc, closure_tyBM * clos);

extern void quasinodegcmark_BM (struct garbcoll_stBM *gc,
                                quasinode_tyBM * quasi, int depth);

extern void classinfogcmark_BM (struct garbcoll_stBM *gc,
                                struct classinfo_stBM *clinf, int depth);
extern void classinfogcdestroy_BM (struct garbcoll_stBM *gc,
                                   struct classinfo_stBM *clinf);
extern void classinfogckeep_BM (struct garbcoll_stBM *gc,
                                struct classinfo_stBM *clinf);

extern value_tyBM apply0_BM (const closure_tyBM * clos,
                             struct stackframe_stBM *stkf);

extern value_tyBM apply1_BM (const closure_tyBM * clos,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1);

extern value_tyBM apply2_BM (const closure_tyBM * clos,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1, const value_tyBM arg2);

extern value_tyBM apply3_BM (const closure_tyBM * clos,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1, const value_tyBM arg2,
                             const value_tyBM arg3);

extern value_tyBM apply4_BM (const closure_tyBM * clos,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1, const value_tyBM arg2,
                             const value_tyBM arg3, const value_tyBM arg4);

extern value_tyBM apply5_BM (const closure_tyBM * clos,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1, const value_tyBM arg2,
                             const value_tyBM arg3, const value_tyBM arg4,
                             const value_tyBM arg5);

extern value_tyBM apply6_BM (const closure_tyBM * clos,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1, const value_tyBM arg2,
                             const value_tyBM arg3, const value_tyBM arg4,
                             const value_tyBM arg5, const value_tyBM arg6);

extern value_tyBM apply7_BM (const closure_tyBM * clos,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1, const value_tyBM arg2,
                             const value_tyBM arg3, const value_tyBM arg4,
                             const value_tyBM arg5, const value_tyBM arg6,
                             const value_tyBM arg7);

extern value_tyBM apply8_BM (const closure_tyBM * clos,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1, const value_tyBM arg2,
                             const value_tyBM arg3, const value_tyBM arg4,
                             const value_tyBM arg5, const value_tyBM arg6,
                             const value_tyBM arg7, const value_tyBM arg8);
extern value_tyBM apply9_BM (const closure_tyBM * clos,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1, const value_tyBM arg2,
                             const value_tyBM arg3, const value_tyBM arg4,
                             const value_tyBM arg5, const value_tyBM arg6,
                             const value_tyBM arg7, const value_tyBM arg8,
                             const value_tyBM arg9);

////////////////
extern void load_initial_BM (const char *dirname);
extern void load_addtodo_BM (const closure_tyBM * clos);

extern void loadergcmark_BM (struct garbcoll_stBM *gc,
                             struct loader_stBM *ld);

//// parsing
extern struct parser_stBM *makeparser_of_file_BM (FILE * f);
extern struct parser_stBM *makeparser_memopen_BM (const char *filemem,
                                                  long size);
static inline bool isparser_BM (const value_tyBM v);
extern void parsergcmark_BM (struct garbcoll_stBM *gc,
                             struct parser_stBM *pars);
extern void parsergcdestroy_BM (struct garbcoll_stBM *gc,
                                struct parser_stBM *pars);
extern void parsergckeep_BM (struct garbcoll_stBM *gc,
                             struct parser_stBM *pars);
extern bool parsernextline_BM (struct parser_stBM *pars);       // return false on EOL
extern objectval_tyBM *parsergetobject_BM
  (struct parser_stBM *pars,
   struct stackframe_stBM *stkf, int depth, bool * pgotobj);
///
extern value_tyBM parsergetvalue_BM
  (struct parser_stBM *pars,
   struct stackframe_stBM *stkf, int depth, bool * pgotval);
///
static inline unsigned parserlineno_BM (const struct parser_stBM *pars);
static inline unsigned parsercolpos_BM (const struct parser_stBM *pars);
static inline const char *parserrestline_BM (const struct parser_stBM *pars);
static inline gunichar parserunichar_BM (const struct parser_stBM *pars);
static inline bool parsereol_BM (const struct parser_stBM *pars);
static inline bool parserendoffile_BM (const struct parser_stBM *pars);
// advance nbc UTF8 characters on current line
static inline bool parseradvanceutf8_BM (struct parser_stBM *pars,
                                         unsigned nbc);

extern void parserseek_BM (struct parser_stBM *pars, unsigned line,
                           unsigned col);
extern void parsererrorprintf_BM (struct parser_stBM *, unsigned line,
                                  unsigned col, const char *fmt, ...)
  __attribute__ ((format (printf, 4, 5), noreturn));
// skip spaces and comments
extern void parserskipspaces_BM (struct parser_stBM *pars);
extern parstoken_tyBM parsertokenget_BM (struct parser_stBM *pars);

// internal routines
extern void gcmark_BM (struct garbcoll_stBM *gc, value_tyBM val, int depth);
extern void gcobjmark_BM (struct garbcoll_stBM *gc, objectval_tyBM * obj);
extern void gcframemark_BM (struct garbcoll_stBM *gc,
                            struct stackframe_stBM *stkfram, int depth);
extern void gctokenmark_BM (struct garbcoll_stBM *gc,
                            struct parstoken_stBM *tok);

/// the full garbage collector
extern void fullgarbagecollection_BM (struct stackframe_stBM *stkfram);


// names
extern void initialize_predefined_names_BM (void);
extern bool validname_BM (const char *nam);
extern const objectval_tyBM *findnamedobj_BM (const char *nam);
extern const char *findobjectname_BM (const objectval_tyBM * obj);
extern const char *findnamesameorafter_BM (const char *prefix);
extern const char *findnameafter_BM (const char *prefix);
extern const char *findnamebefore_BM (const char *prefix);
extern bool registername_BM (const objectval_tyBM * obj, const char *nam);
extern bool forgetnamedobject_BM (const objectval_tyBM * obj);
extern bool forgetnamestring_BM (const char *nam);
extern const setval_tyBM *setofnamedobjects_BM (void);

// globals
extern void initialize_globals_BM (void);
extern objectval_tyBM **findglobalnamed_BM (const char *nam);
extern bool forgetglobalnamed_BM (const char *nam);
// make a node with the global names
extern const node_tyBM *nodeglobalnames_BM (const objectval_tyBM * conn);
// make a set with the global objects
extern const setval_tyBM *nodeglobalset_BM (void);

extern void gcmarkglobals_BM (struct garbcoll_stBM *gc);

#endif /*FUNDECL_BM_INCLUDED */
