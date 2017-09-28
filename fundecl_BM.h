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
extern const closure_tyBM *valfindmethod_BM (const value_tyBM recv,
                                             const objectval_tyBM *
                                             obselector);
static inline hash_tyBM valhash_BM (const value_tyBM v);
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
// to be called from debugger
extern const char *iddbg_BM (rawid_tyBM id);    // non reentrant!
extern const char *objectdbg_BM (const objectval_tyBM * obj);   // non reentrant!
extern const char *gobjectclassnamedbg_BM (GObject * ptr);
// return an static string for a textiter, for debugging only
extern const char *textiterstrdbg_BM (GtkTextIter *);

extern rawid_tyBM parse_rawid_BM (const char *buf, const char **pend);
extern void *allocgcty_BM (unsigned type, size_t sz);


static inline bool isstring_BM (const value_tyBM v);
static inline const stringval_tyBM *stringcast_BM (const value_tyBM);
extern hash_tyBM stringhash_BM (const char *str);
extern hash_tyBM stringhashlen_BM (const char *str, long len);
extern const stringval_tyBM *makestring_BM (const char *str);
extern const stringval_tyBM *makestringlen_BM (const char *str, long len);
extern const stringval_tyBM *sprintfstring_BM (const char *fmt, ...)
  __attribute__ ((format (printf, 1, 2)));
extern int lenstring_BM (const stringval_tyBM *);       // length in bytes
extern const char *bytstring_BM (const stringval_tyBM *);
extern void stringgcdestroy_BM (struct garbcoll_stBM *, stringval_tyBM *);

extern void stringgckeep_BM (struct garbcoll_stBM *, stringval_tyBM *);

static inline bool istuple_BM (const value_tyBM v);
static inline const tupleval_tyBM *tuplecast_BM (const value_tyBM);
extern const tupleval_tyBM *maketuple_BM (objectval_tyBM ** arr,
                                          unsigned rawsiz);
extern unsigned tuplesize_BM (const tupleval_tyBM * tup);
extern objectval_tyBM *tuplecompnth_BM (const tupleval_tyBM * tup, int rk);
extern void tuplegcmark_BM (struct garbcoll_stBM *gc, tupleval_tyBM * tup);
extern void tuplegcdestroy_BM (struct garbcoll_stBM *gc, tupleval_tyBM * tup);
extern void tuplegckeep_BM (struct garbcoll_stBM *gc, tupleval_tyBM * tup);


static inline bool issequence_BM (const value_tyBM v);
static inline const seqobval_tyBM *sequencecast_BM (const value_tyBM v);
extern unsigned sequencesize_BM (const seqobval_tyBM * sq);
extern objectval_tyBM *sequencenthcomp_BM (const seqobval_tyBM * sq, int rk);
static inline bool isset_BM (const value_tyBM v);
static inline const setval_tyBM *setcast_BM (const value_tyBM v);
extern const setval_tyBM *makeset_BM (const objectval_tyBM ** arr,
                                      unsigned rawsiz);
static inline bool setcontains_BM (const setval_tyBM * setv,
                                   const objectval_tyBM * obelem);
/* return the index in setv of element obelem or else -1 */
extern int setelemindex_BM (const setval_tyBM * setv,
                            const objectval_tyBM * obelem);

extern unsigned setcardinal_BM (const setval_tyBM * setv);
extern objectval_tyBM *setelemnth_BM (const setval_tyBM * set, int rk);
extern void setgcmark_BM (struct garbcoll_stBM *gc, setval_tyBM * set);
extern void setgcdestroy_BM (struct garbcoll_stBM *gc, setval_tyBM * set);
extern void setgckeep_BM (struct garbcoll_stBM *gc, setval_tyBM * set);

extern void initialize_garbage_collector_BM (void);
extern void initialize_predefined_objects_BM (void);

static inline bool isobject_BM (const value_tyBM v);
static inline objectval_tyBM *objectcast_BM (const value_tyBM v);
static inline hash_tyBM objecthash_BM (const objectval_tyBM *);

/// compare by id
static inline int objectcmp_BM (const objectval_tyBM * ob1,
                                const objectval_tyBM * ob2);

/// compare by name or id
static inline int objectnamedcmp_BM (const objectval_tyBM * ob1,
                                     const objectval_tyBM * ob2);


extern void sortobjarr_BM (const objectval_tyBM ** obarr, size_t arrsiz);
extern void sortnamedobjarr_BM (const objectval_tyBM ** obarr, size_t arrsiz);

extern objectval_tyBM *findobjofid_BM (const rawid_tyBM id);
extern objectval_tyBM *makeobjofid_BM (const rawid_tyBM id);
// find the set of objects of an id prefixed by some prefix of at
// least three characters starting with _ then a digit
extern const setval_tyBM *setobjectsofidprefixed_BM (const char *prefix);
extern objectval_tyBM *makeobj_BM (void);
static inline rawid_tyBM objid_BM (const objectval_tyBM * obj);
static inline double objmtime_BM (const objectval_tyBM * obj);
static inline void objtouchmtime_BM (objectval_tyBM * obj, double mtime);
static inline void objtouchnow_BM (objectval_tyBM * obj);
extern void objputspacenum_BM (objectval_tyBM * obj, unsigned spanum);
static inline unsigned objspacenum_BM (const objectval_tyBM * obj);
static inline objectval_tyBM *objclass_BM (const objectval_tyBM * obj);
extern void objputclass_BM (objectval_tyBM * obj, objectval_tyBM * objclass);

static inline value_tyBM objgetattr_BM (const objectval_tyBM * obj,
                                        const objectval_tyBM * objattr);
static inline unsigned objnbattrs_BM (const objectval_tyBM * obj);
static inline const setval_tyBM *objsetattrs_BM (const objectval_tyBM * obj);

extern void objputattr_BM (objectval_tyBM * obj,
                           const objectval_tyBM * objattr,
                           const value_tyBM valattr);
extern void objremoveattr_BM (objectval_tyBM * obj,
                              const objectval_tyBM * objattr);
extern void objresetattrs_BM (objectval_tyBM * obj, unsigned nbattrhint);

static inline bool objhasclassinfo_BM (const objectval_tyBM * obj);
// put a fresh classinfo as an object's data
extern void objputclassinfo_BM (objectval_tyBM * obj,
                                objectval_tyBM * superclass);
static inline objectval_tyBM *  //
  objgetclassinfosuperclass_BM (const objectval_tyBM * obj);

static inline const closure_tyBM *      //
  objgetclassinfomethod_BM (const objectval_tyBM * obj, //
                            const objectval_tyBM * obselector);

extern void
objclassinfoputmethod_BM (objectval_tyBM * obj, objectval_tyBM * obselector,
                          const closure_tyBM * clos);

extern void
objclassinforemovemethod_BM (objectval_tyBM * obj,
                             objectval_tyBM * obselector);

static inline const setval_tyBM *       //
  objgetclassinfosetofselectors_BM (const objectval_tyBM * obj);

// is obj a subclass of obclass?
extern bool
objclassinfoissubclass_BM (const objectval_tyBM * obj,
                           const objectval_tyBM * obclass);

// is obj an instance of obclass?
static inline bool
objectisinstance_BM (const objectval_tyBM * obj,
                     const objectval_tyBM * obclass);

/// message sending

extern value_tyBM send0_BM (const value_tyBM recv,
                            const objectval_tyBM * obselector,
                            struct stackframe_stBM *stkf);
extern value_tyBM send1_BM (const value_tyBM recv,
                            const objectval_tyBM * obselector,
                            struct stackframe_stBM *stkf,
                            const value_tyBM arg1);
extern value_tyBM send2_BM (const value_tyBM recv,
                            const objectval_tyBM * obselector,
                            struct stackframe_stBM *stkf,
                            const value_tyBM arg1, const value_tyBM arg2);
extern value_tyBM send3_BM (const value_tyBM recv,
                            const objectval_tyBM * obselector,
                            struct stackframe_stBM *stkf,
                            const value_tyBM arg1, const value_tyBM arg2,
                            const value_tyBM arg3);
extern value_tyBM send4_BM (const value_tyBM recv,
                            const objectval_tyBM * obselector,
                            struct stackframe_stBM *stkf,
                            const value_tyBM arg1, const value_tyBM arg2,
                            const value_tyBM arg3, const value_tyBM arg4);
extern value_tyBM send5_BM (const value_tyBM recv,
                            const objectval_tyBM * obselector,
                            struct stackframe_stBM *stkf,
                            const value_tyBM arg1, const value_tyBM arg2,
                            const value_tyBM arg3, const value_tyBM arg4,
                            const value_tyBM arg5);
extern value_tyBM send6_BM (const value_tyBM recv,
                            const objectval_tyBM * obselector,
                            struct stackframe_stBM *stkf,
                            const value_tyBM arg1, const value_tyBM arg2,
                            const value_tyBM arg3, const value_tyBM arg4,
                            const value_tyBM arg5, const value_tyBM arg6);
extern value_tyBM send7_BM (const value_tyBM recv,
                            const objectval_tyBM * obselector,
                            struct stackframe_stBM *stkf,
                            const value_tyBM arg1, const value_tyBM arg2,
                            const value_tyBM arg3, const value_tyBM arg4,
                            const value_tyBM arg5, const value_tyBM arg6,
                            const value_tyBM arg7);
extern value_tyBM send8_BM (const value_tyBM recv,
                            const objectval_tyBM * obselector,
                            struct stackframe_stBM *stkf,
                            const value_tyBM arg1, const value_tyBM arg2,
                            const value_tyBM arg3, const value_tyBM arg4,
                            const value_tyBM arg5, const value_tyBM arg6,
                            const value_tyBM arg7, const value_tyBM arg8);


static inline unsigned objnbcomps_BM (const objectval_tyBM * obj);
static inline value_tyBM objgetcomp_BM (const objectval_tyBM * obj, int rk);
static inline void objreservecomps_BM (objectval_tyBM * obj, unsigned gap);
static inline void objresetcomps_BM (objectval_tyBM * obj, unsigned len);
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
extern void strbufferreset_BM (struct strbuffer_stBM *sbuf);
extern unsigned strbufferlength_BM (struct strbuffer_stBM *sbuf);
/// raw printf
extern void strbufferrawprintf_BM (struct strbuffer_stBM *sbuf,
                                   const char *fmt, ...)
  __attribute__ ((format (printf, 2, 3)));
/// cooked printf: the tabs become spaces or indented-newlines, the
/// newlines become indented
extern void strbufferprintf_BM (struct strbuffer_stBM *sbuf, const char *fmt,
                                ...) __attribute__ ((format (printf, 2, 3)));
/// indented newline
extern void strbuffernewline_BM (struct strbuffer_stBM *sbuf);
/// output UTF8 encoded à la JSON
extern void strbufferencodedutf8_BM (struct strbuffer_stBM *sbuf,
                                     const char *str, ssize_t bytelen);
/// output bytes encoded à la C
extern void strbufferencodedc_BM (struct strbuffer_stBM *sbuf,
                                  const char *str, ssize_t bytelen);

/// write the content to a file, if different
extern void strbufferwritetofile_BM (struct strbuffer_stBM *sbuf,
                                     const char *filepath);

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

static inline const value_tyBM *datavectdata_BM (const struct datavectval_stBM
                                                 *dvec);

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
static inline unsigned hashsetobj_cardinal_BM (struct hashsetobj_stBM *hset);

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
static inline const closure_tyBM *closurecast_BM (const value_tyBM);
static inline bool isnode_BM (const value_tyBM v);
static inline const node_tyBM *nodecast_BM (const value_tyBM);

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

extern const node_tyBM *makenode_BM (const objectval_tyBM * connob,
                                     unsigned nbval,
                                     const value_tyBM * sonvalarr);
extern const node_tyBM *makenodevar_BM (const objectval_tyBM * connob, ...)
  __attribute__ ((sentinel));

extern const closure_tyBM *makeclosure_BM (const objectval_tyBM * conn,
                                           unsigned nbclos,
                                           const value_tyBM * closvalarr);
extern const closure_tyBM *makeclosurevar_BM (const objectval_tyBM * connob,
                                              ...) __attribute__ ((sentinel));

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

////////////////
extern struct dict_stBM *dictmake_BM (void);
static inline bool isdict_BM (const value_tyBM v);
extern void dictgcmark_BM (struct garbcoll_stBM *gc, struct dict_stBM *dict,
                           int depth);
extern void dictgcdestroy_BM (struct garbcoll_stBM *gc,
                              struct dict_stBM *dict);
extern void dictgckeep_BM (struct garbcoll_stBM *gc, struct dict_stBM *dict);
extern value_tyBM dictget_BM (const struct dict_stBM *dict,
                              const stringval_tyBM * str);
extern void dictput_BM (struct dict_stBM *dict, const stringval_tyBM * str,
                        const value_tyBM val);
extern void dictremove_BM (struct dict_stBM *dict,
                           const stringval_tyBM * str);
extern const stringval_tyBM *dictkeyafter_BM (struct dict_stBM *dict,
                                              const stringval_tyBM * str);
extern const stringval_tyBM *dictkeysameorafter_BM (struct dict_stBM *dict,
                                                    const stringval_tyBM *
                                                    str);
extern const stringval_tyBM *dictkeybefore_BM (struct dict_stBM *dict,
                                               const stringval_tyBM * str);
extern const node_tyBM *dictnodeofkeys_BM (struct dict_stBM *dict,
                                           const objectval_tyBM * obj);
////////////////
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
extern void loadergcdestroy_BM (struct garbcoll_stBM *gc,
                                struct loader_stBM *ld);
extern void loadergckeep_BM (struct garbcoll_stBM *gc,
                             struct loader_stBM *ld);

////////////////
extern struct dumpinfo_stBM dump_BM (const char *dirname,
                                     struct stackframe_stBM *stkf);
extern void dumpgcmark_BM (struct garbcoll_stBM *gc, struct dumper_stBM *du);
extern void dumpgcdestroy_BM (struct garbcoll_stBM *gc,
                              struct dumper_stBM *du);
extern void dumpgckeep_BM (struct garbcoll_stBM *gc, struct dumper_stBM *du);
extern bool dumpobjisdumpable_BM (struct dumper_stBM *du,
                                  const objectval_tyBM * obj);
extern bool dumpvalisdumpable_BM (struct dumper_stBM *du,
                                  const value_tyBM val);

extern void dumpscanobj_BM (struct dumper_stBM *du,
                            const objectval_tyBM * obj);
extern void dumpscanvalue_BM (struct dumper_stBM *du, const value_tyBM val,
                              int depth);

//// parsing
extern const char *lexkindname_BM (enum parslexkind_enBM k);
extern const char *delimstr_BM (enum lexdelim_enBM d);

extern struct parser_stBM *makeparser_of_file_BM (FILE * f);
extern struct parser_stBM *makeparser_memopen_BM (const char *filemem,
                                                  long size);
static inline bool isparser_BM (const value_tyBM v);
static inline const struct parser_stBM *parsercast_BM (const value_tyBM v);
extern void parsergcmark_BM (struct garbcoll_stBM *gc,
                             struct parser_stBM *pars);
extern void parsergcdestroy_BM (struct garbcoll_stBM *gc,
                                struct parser_stBM *pars);
extern void parsergckeep_BM (struct garbcoll_stBM *gc,
                             struct parser_stBM *pars);
extern bool parsernextline_BM (struct parser_stBM *pars);       // return false on EOF
extern objectval_tyBM *parsergetobject_BM
  (struct parser_stBM *pars,
   struct stackframe_stBM *stkf, int depth, bool * pgotobj);
///
extern value_tyBM parsergetvalue_BM
  (struct parser_stBM *pars,
   struct stackframe_stBM *stkf, int depth, bool * pgotval);

extern value_tyBM parsergetchunk_BM
  (struct parser_stBM *pars,
   struct stackframe_stBM *stkf, int depth, bool * pgotchunk);

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
static inline void garbage_collect_if_wanted_BM (struct stackframe_stBM
                                                 *stkfram);

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
extern const setval_tyBM *setofprefixednamedobjects_BM (const char *prefix);
extern const setval_tyBM *setofmatchednamedobjects_BM (const char *fnmatcher);
// globals, see misc_BM.cc
extern void initialize_globals_BM (void);
extern objectval_tyBM **findglobalnamed_BM (const char *nam);
extern bool forgetglobalnamed_BM (const char *nam);
// make a node with the global names
extern const node_tyBM *nodeglobalnames_BM (const objectval_tyBM * conn);
// make a set with the global objects
extern const setval_tyBM *setglobalobjects_BM (void);

extern void gcmarkglobals_BM (struct garbcoll_stBM *gc);

/// open a module, returns true if ok
extern bool openmoduleforloader_BM (const rawid_tyBM modid,
                                    struct loader_stBM *ld,
                                    struct stackframe_stBM *stkf);
static inline bool openmodule_BM (const rawid_tyBM modid,
                                  struct stackframe_stBM *stkf);

/// support for GUI, in misc_BM.cc
void cmd_clear_parens_BM (void);        /* clear all parenthesis in cmd */
void cmd_add_parens_BM (struct parenoffset_stBM *par);
bool parens_surrounds_BM (struct parenoffset_stBM *par, int off);
struct parenoffset_stBM *cmd_find_enclosing_parens_BM (int off);
///
extern void initialize_gui_BM (const char *builderfile, const char *cssfile);
// browse the object objbrows, using the selector objsel
extern void browse_object_gui_BM (const objectval_tyBM * objbrows,
                                  const objectval_tyBM * objsel,
                                  int browsdepth,
                                  struct stackframe_stBM *stkf);
extern void hide_object_gui_BM (const objectval_tyBM * objbrows,
                                struct stackframe_stBM *stkf);

// browse the named value
extern void browse_named_value_gui_BM (const stringval_tyBM * namev,
                                       const value_tyBM val,
                                       const objectval_tyBM * objsel,
                                       int browsdepth,
                                       struct stackframe_stBM *stkf);
extern void hide_named_value_gui_BM (const stringval_tyBM * namev,
                                     struct stackframe_stBM *stkf);
extern value_tyBM find_named_value_gui_BM (const char *name);

// internal, inside browsing methods
extern void browse_value_BM (const value_tyBM val,
                             struct stackframe_stBM *stkf,
                             int maxdepth, int curdepth);

extern void gcmarkgui_BM (struct garbcoll_stBM *gc);
extern void gui_gc_message_BM (const char *msg);
#endif /*FUNDECL_BM_INCLUDED */
