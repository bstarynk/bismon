// file fundecl_BM.h

/***
    BISMON 
    Copyright © 2018 Basile Starynkevitch (working at CEA, LIST, France)
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
***/
#ifndef FUNDECL_BM_INCLUDED
#define FUNDECL_BM_INCLUDED

extern void abort_BM (void) __attribute__ ((noreturn));
static inline pid_t gettid_BM (void);

extern int64_t prime_above_BM (int64_t n);
extern int64_t prime_below_BM (int64_t n);


static inline double clocktime_BM (clockid_t);
static inline double cputime_BM (void);
static inline double elapsedtime_BM (void);
static inline void get_realtimespec_delayedms_BM (struct timespec *pts,
                                                  unsigned millisec);
extern double taskletcputime_BM (void);
extern double taskletelapsedtime_BM (void);
static inline bool istaggedint_BM (value_tyBM v);
static inline intptr_t getint_BM (value_tyBM v);
static inline value_tyBM taggedint_BM (intptr_t i);

static inline int valtype_BM (const value_tyBM v);
extern const char *typestring_BM (int ty);
static inline bool isgenuineval_BM (const value_tyBM v);
static inline objectval_tyBM *valclass_BM (const value_tyBM v);
extern const closure_tyBM *valfindmethod_BM (const value_tyBM recv,
                                             const objectval_tyBM *
                                             obselector);
static inline hash_tyBM valhash_BM (const value_tyBM v);
void valgcdestroy_BM (struct garbcoll_stBM *, value_tyBM v);
void valgckeep_BM (struct garbcoll_stBM *, value_tyBM v);
static inline bool valequal_BM (const value_tyBM v1, const value_tyBM v2);
extern bool valsamecontent_BM (const value_tyBM v1, const value_tyBM v2,
                               int depth);
static inline int valcmp_BM (const value_tyBM v1, const value_tyBM v2);
extern int valqcmp_BM (const void *, const void *);     // for qsort
static inline void valarrqsort_BM (value_tyBM * arr, unsigned siz);
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

extern const char *iddbg1_BM (rawid_tyBM id);   // non reentrant!
extern const char *objectdbg1_BM (const objectval_tyBM * obj);  // non reentrant!

extern const char *iddbg2_BM (rawid_tyBM id);   // non reentrant!
extern const char *objectdbg2_BM (const objectval_tyBM * obj);  // non reentrant!

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
extern void *stringgcproc_BM (struct garbcoll_stBM *gc, stringval_tyBM * str)
  __attribute__ ((warn_unused_result));
extern void stringgcdestroy_BM (struct garbcoll_stBM *, stringval_tyBM *);

extern void stringgckeep_BM (struct garbcoll_stBM *, stringval_tyBM *);

static inline bool istuple_BM (const value_tyBM v);
static inline const tupleval_tyBM *tuplecast_BM (const value_tyBM);
extern const tupleval_tyBM *maketuple_BM (objectval_tyBM ** arr,
                                          unsigned rawsiz);
extern unsigned tuplesize_BM (const tupleval_tyBM * tup);
extern objectval_tyBM *tuplecompnth_BM (const tupleval_tyBM * tup, int rk);
extern void *tuplegcproc_BM (struct garbcoll_stBM *gc, tupleval_tyBM * tup)
  __attribute__ ((warn_unused_result));
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
extern const tupleval_tyBM *settonamedsortedtuple_BM (const setval_tyBM *
                                                      setv);
/* return the index in setv of element obelem or else -1 */
extern int setelemindex_BM (const setval_tyBM * setv,
                            const objectval_tyBM * obelem);

extern unsigned setcardinal_BM (const setval_tyBM * setv);
extern objectval_tyBM *setelemnth_BM (const setval_tyBM * set, int rk);
extern void *setgcproc_BM (struct garbcoll_stBM *gc, setval_tyBM * set)
  __attribute__ ((warn_unused_result));
extern void setgcdestroy_BM (struct garbcoll_stBM *gc, setval_tyBM * set);
extern void setgckeep_BM (struct garbcoll_stBM *gc, setval_tyBM * set);



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

extern void *nodegcproc_BM (struct garbcoll_stBM *gc, node_tyBM * nod,
                            int depth) __attribute__ ((warn_unused_result));
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

extern void *closuregcproc_BM (struct garbcoll_stBM *gc, closure_tyBM * clos,
                               int depth)
  __attribute__ ((warn_unused_result));
extern void closuregcdestroy_BM (struct garbcoll_stBM *gc,
                                 closure_tyBM * clos);
extern void closuregckeep_BM (struct garbcoll_stBM *gc, closure_tyBM * clos);

extern void *quasinodegcproc_BM (struct garbcoll_stBM *gc,
                                 quasinode_tyBM * quasi, int depth)
  __attribute__ ((warn_unused_result));
////////////////

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


extern void sortobjarr_BM (objectval_tyBM ** obarr, size_t arrsiz);
extern void sortnamedobjarr_BM (objectval_tyBM ** obarr, size_t arrsiz);

extern objectval_tyBM *findobjofid_BM (const rawid_tyBM id);
extern objectval_tyBM *makeobjofid_BM (const rawid_tyBM id);
// find the set of objects of an id prefixed by some prefix of at
// least three characters starting with _ then a digit
extern const setval_tyBM *setobjectsofidprefixed_BM (const char *prefix);
extern objectval_tyBM *makeobj_BM (void);
static inline rawid_tyBM objid_BM (const objectval_tyBM * obj);
static inline double objmtime_BM (const objectval_tyBM * obj);
static inline objectval_tyBM *objsignature_BM (const objectval_tyBM * obj);
static inline void *objroutaddr_BM (const objectval_tyBM * obj,
                                    const objectval_tyBM * objsig);

extern objrout_sigBM objrout_placeholder_BM;
static inline void objtouchmtime_BM (objectval_tyBM * obj, double mtime);
static inline void objtouchnow_BM (objectval_tyBM * obj);
extern void objputspacenum_BM (objectval_tyBM * obj, unsigned spanum);
static inline unsigned objspacenum_BM (const objectval_tyBM * obj);
static inline objectval_tyBM *objclass_BM (const objectval_tyBM * obj);
extern void objputclass_BM (objectval_tyBM * obj, objectval_tyBM * objclass);
// return true on success
static inline bool objlock_BM (objectval_tyBM * obj);
static inline bool objunlock_BM (objectval_tyBM * obj);
static inline bool objtrylock_BM (objectval_tyBM * obj);
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


/// raise a failure; see also macro FAILURE_BM
extern void failure_BM (int failcode, const value_tyBM reasonv,
                        struct stackframe_stBM *stkf)
  __attribute__ ((noreturn));
extern void failure_at_BM (int failcode, const char *fil, int lineno,
                           const value_tyBM reasonv,
                           struct stackframe_stBM *stkf)
  __attribute__ ((noreturn));

extern void register_failock_BM (struct failurelockset_stBM *,
                                 objectval_tyBM *);
extern void unregister_failock_BM (struct failurelockset_stBM *,
                                   objectval_tyBM *);
extern void initialize_failurelockset_BM (struct failurelockset_stBM *,
                                          size_t);
extern void destroy_failurelockset_BM (struct failurelockset_stBM *);
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
static inline value_tyBM sendvar_BM (const value_tyBM recv, const objectval_tyBM * obselector, struct stackframe_stBM *stkf, unsigned nbargs,   // no more than MAXAPPLYARGS_BM-1
                                     const value_tyBM * argarr);

static inline unsigned objnbcomps_BM (const objectval_tyBM * obj);
static inline value_tyBM *objcompdata_BM (const objectval_tyBM * obj);
static inline value_tyBM objgetcomp_BM (const objectval_tyBM * obj, int rk);
static inline void objputcomp_BM (objectval_tyBM * obj, int rk,
                                  const value_tyBM compval);
static inline void objreservecomps_BM (objectval_tyBM * obj, unsigned gap);
static inline void objresetcomps_BM (objectval_tyBM * obj, unsigned len);
static inline void objappendcomp_BM (objectval_tyBM * obj,
                                     value_tyBM compval);
static inline value_tyBM objlastcomp_BM (const objectval_tyBM * obj);
static inline void objpoplastcomp_BM (objectval_tyBM * obj);
static inline void objgrowcomps_BM (objectval_tyBM * obj, unsigned gap);

///
extern void deleteobjectpayload_BM (objectval_tyBM * obj,
                                    extendedval_tyBM payl);
static inline void objclearpayload_BM (objectval_tyBM * obj);
static inline void objputpayload_BM (objectval_tyBM * obj,
                                     extendedval_tyBM payl);
static inline extendedval_tyBM objpayload_BM (const objectval_tyBM * obj);

///
extern const setval_tyBM *setpredefinedobjects_BM (void);
extern void gcmarkpredefinedobjects_BM (struct garbcoll_stBM *gc);

extern void objectinteriorgcmark_BM (struct garbcoll_stBM *gc,
                                     objectval_tyBM * obj);
extern void objectgcdestroy_BM (struct garbcoll_stBM *gc,
                                objectval_tyBM * obj);
extern void objectgckeep_BM (struct garbcoll_stBM *gc, objectval_tyBM * obj);



////////////////
/// notice the naming convention objXXXXXpayl_BM for functions dealing
/// with particular payloads in objects.
extern bool objputstrbufferpayl_BM (objectval_tyBM * obj, unsigned maxsize);
static inline bool objhasstrbufferpayl_BM (const objectval_tyBM * obj);
static inline struct strbuffer_stBM *objgetstrbufferpayl_BM (objectval_tyBM
                                                             * obj);
extern void objstrbufferreservepayl_BM (objectval_tyBM * obj, unsigned gap);
extern const char *objstrbufferbytespayl_BM (objectval_tyBM * obj);
extern int objstrbufferindentationpayl_BM (objectval_tyBM * obj);
extern void objstrbufferclearindentpayl_BM (objectval_tyBM * obj);
extern void objstrbuffermoreindentpayl_BM (objectval_tyBM * obj);
extern void objstrbufferlessindentpayl_BM (objectval_tyBM * obj);
extern void objstrbufferappendcstrpayl_BM (objectval_tyBM * obj,
                                           const char *cstr);
extern void objstrbufferresetpayl_BM (objectval_tyBM * obj);
extern unsigned objstrbufferlengthpayl_BM (const objectval_tyBM * obj);
/// raw printf
extern void objstrbufferrawprintfpayl_BM (objectval_tyBM * obj,
                                          const char *fmt, ...)
  __attribute__ ((format (printf, 2, 3)));
/// cooked printf: the tabs become spaces or indented-newlines, the
/// newlines become indented
extern void objstrbufferprintfpayl_BM (objectval_tyBM * obj, const char *fmt,
                                       ...)
  __attribute__ ((format (printf, 2, 3)));
/// indented newline
extern void objstrbuffernewlinepayl_BM (objectval_tyBM * obj);
/// output UTF8 encoded à la JSON
extern void objstrbufferencodedutf8payl_BM (objectval_tyBM * obj,
                                            const char *str, ssize_t bytelen);
/// output bytes encoded à la C
extern void objstrbufferencodedcpayl_BM (objectval_tyBM * obj,
                                         const char *str, ssize_t bytelen);

/// write the content to a file, if different
extern void objstrbufferwritetofilepayl_BM (objectval_tyBM * obj,
                                            const char *filepath);
///////

extern void strbuffergcmark_BM (struct garbcoll_stBM *gc,
                                struct strbuffer_stBM *sbuf, int depth);
extern void strbuffergcdestroy_BM (struct garbcoll_stBM *gc,
                                   struct strbuffer_stBM *sbuf);
extern void strbuffergckeep_BM (struct garbcoll_stBM *gc,
                                struct strbuffer_stBM *sbuf);
////////////////


static inline bool isassoc_BM (value_tyBM v);
static inline anyassoc_tyBM *assoccast_BM (value_tyBM v);
extern void *assocgcproc_BM (struct garbcoll_stBM *gc, anyassoc_tyBM * assoc,
                             int depth) __attribute__ ((warn_unused_result));
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
static inline anyassoc_tyBM *make_assoc_BM (unsigned ulen);
extern const setval_tyBM *assoc_setattrs_BM (const anyassoc_tyBM * assoc);
extern value_tyBM assoc_getattr_BM (const anyassoc_tyBM * assoc,
                                    const objectval_tyBM * obattr);
extern anyassoc_tyBM *assoc_addattr_BM (anyassoc_tyBM * assoc,
                                        const objectval_tyBM * obattr,
                                        value_tyBM val);
extern anyassoc_tyBM *assoc_removeattr_BM (anyassoc_tyBM * assoc,
                                           const objectval_tyBM * obattr);

//// assoc payload support

extern bool objputassocpayl_BM (objectval_tyBM * obj, unsigned maxsize);
static inline bool objhasassocpayl_BM (const objectval_tyBM * obj);
static inline unsigned objassocnbkeyspayl_BM (const objectval_tyBM * obj);
static inline anyassoc_tyBM *objgetassocpayl_BM (objectval_tyBM * obj);
static inline const setval_tyBM *objassocsetattrspayl_BM (objectval_tyBM *
                                                          obj);
static inline value_tyBM objassocgetattrpayl_BM (objectval_tyBM * obj,
                                                 const objectval_tyBM *
                                                 obattr);
static inline void objassocaddattrpayl_BM (objectval_tyBM * obj,
                                           const objectval_tyBM * obattr,
                                           value_tyBM val);
static inline void objassocremoveattrpayl_BM (objectval_tyBM * obj,
                                              const objectval_tyBM * obattr);
static inline void objassocreorganizepayl_BM (objectval_tyBM * obj,
                                              unsigned gap);


//////////////// hashed and mutable set of objects
extern struct hashsetobj_stBM *hashsetobj_grow_BM (struct hashsetobj_stBM
                                                   *hset, unsigned gap);
static inline struct hashsetobj_stBM *hashsetobjcast_BM (const value_tyBM v);
extern void hashsetgcmark_BM (struct garbcoll_stBM *gc,
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
// pick some random element, and keep it in the hashset
extern objectval_tyBM *hashsetobj_pick_random_BM (struct hashsetobj_stBM
                                                  *hset);
// take some random element, and remove it from the hashset - without reorganizing it
extern objectval_tyBM *hashsetobj_take_random_BM (struct hashsetobj_stBM
                                                  *hset);
extern const setval_tyBM *hashsetobj_to_set_BM (struct hashsetobj_stBM *hset);
static inline unsigned hashsetobj_cardinal_BM (struct hashsetobj_stBM *hset);

//// obj hashset payload support

extern void objputhashsetpayl_BM (objectval_tyBM * obj, unsigned inisiz);
static inline struct hashsetobj_stBM *objgethashsetpayl_BM (objectval_tyBM *
                                                            obj);
static inline bool objhashashsetpayl_BM (objectval_tyBM * obj);
static inline bool objhashsetcontainspayl_BM (objectval_tyBM * obj,
                                              const objectval_tyBM * obelem);
static inline void objhashsetaddpayl_BM (objectval_tyBM * obj,
                                         objectval_tyBM * obelem);
static inline void objhashsetremovepayl_BM (objectval_tyBM * obj,
                                            objectval_tyBM * obelem);
static inline void objhashsetgrowpayl_BM (objectval_tyBM * obj, unsigned gap);
static inline unsigned objhashsetcardinalpayl_BM (objectval_tyBM * obj);
static inline const setval_tyBM *objhashsettosetpayl_BM (objectval_tyBM *
                                                         obj);
static inline objectval_tyBM *objhashsetpickrandompayl_BM (objectval_tyBM *
                                                           obj);
static inline objectval_tyBM *objhashsettakerandompayl_BM (objectval_tyBM *
                                                           obj);

//////////////// mutable data vector of values

static inline unsigned datavectlen_BM (const struct datavectval_stBM *dvec);

static inline const value_tyBM *datavectdata_BM (const struct datavectval_stBM
                                                 *dvec);

extern struct datavectval_stBM *datavect_grow_BM (struct datavectval_stBM
                                                  *dvec, unsigned gap);

extern struct datavectval_stBM *datavect_reserve_BM (struct datavectval_stBM
                                                     *dvec, unsigned gap);

extern struct datavectval_stBM *datavect_append_BM (struct datavectval_stBM
                                                    *dvec, value_tyBM val);

extern struct datavectval_stBM *datavect_pop_BM (struct datavectval_stBM
                                                 *dvec);
extern struct datavectval_stBM *datavect_insert_BM (struct datavectval_stBM
                                                    *dvec, int rk,
                                                    value_tyBM * valarr,
                                                    unsigned len);
static inline struct datavectval_stBM *datavect_insertone_BM (struct
                                                              datavectval_stBM
                                                              *dvec, int rk,
                                                              value_tyBM val);
extern struct datavectval_stBM *datavect_remove_BM (struct datavectval_stBM
                                                    *dvec, int rk,
                                                    unsigned len);

extern const node_tyBM *datavect_to_node_BM (struct datavectval_stBM *dvec,
                                             const objectval_tyBM * obconn);
static inline value_tyBM datavectnth_BM (const struct datavectval_stBM *dvec,
                                         int rk);
static inline value_tyBM datavectlast_BM (const struct datavectval_stBM
                                          *dvec);
static inline void datavectputnth_BM (struct datavectval_stBM *dvec, int rk,
                                      const value_tyBM valcomp);
extern void *datavectgcproc_BM (struct garbcoll_stBM *gc,
                                struct datavectval_stBM *dvec, int depth)
  __attribute__ ((warn_unused_result));
extern void datavectgcdestroy_BM (struct garbcoll_stBM *gc,
                                  struct datavectval_stBM *dvec);
extern void datavectgckeep_BM (struct garbcoll_stBM *gc,
                               struct datavectval_stBM *dvec);


//////////////// obj datavect payload
extern void objputdatavectpayl_BM (objectval_tyBM * obj, unsigned inisiz);
static inline struct datavectval_stBM *objgetdatavectpayl_BM    //
  (objectval_tyBM * obj);
static inline bool objhasdatavectpayl_BM (objectval_tyBM * obj);
static inline unsigned objdatavectlengthpayl_BM (objectval_tyBM * obj);
static inline const value_tyBM *objdatavectdatapayl_BM (objectval_tyBM * obj);
static inline void objdatavectgrowpayl_BM (objectval_tyBM * obj,
                                           unsigned gap);
static inline void objdatavectreservepayl_BM (objectval_tyBM * obj,
                                              unsigned gap);
static inline void objdatavectappendpayl_BM (objectval_tyBM * obj,
                                             value_tyBM val);
static inline void objdatavectinsertpayl_BM (objectval_tyBM * obj,
                                             int rk,
                                             value_tyBM * valarr,
                                             unsigned len);
static inline void objdatavectinsertonepayl_BM (objectval_tyBM * obj,
                                                int rk, value_tyBM val);

static inline void objdatavectremovepayl_BM (objectval_tyBM * obj, int rk,
                                             unsigned len);
static inline const node_tyBM *objdatavecttonodepayl_BM //
  (objectval_tyBM * obj, const objectval_tyBM * obconn);
static inline value_tyBM objdatavectnthpayl_BM (objectval_tyBM * obj, int rk);
static inline void objdatavectputnthpayl_BM (objectval_tyBM * obj,
                                             int rk,
                                             const value_tyBM valcomp);
////////////////////////////////


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
extern void listgcmark_BM (struct garbcoll_stBM *gc,
                           struct listtop_stBM *lis, int depth);
extern void listgcdestroy_BM (struct garbcoll_stBM *gc,
                              struct listtop_stBM *lis);
extern void listgckeep_BM (struct garbcoll_stBM *gc,
                           struct listtop_stBM *lis);
// make a node from all components of the list
extern const node_tyBM *list_to_node_BM (const struct listtop_stBM *lis,
                                         const objectval_tyBM * conn);
// make a tuple from the objects in the list
extern const tupleval_tyBM *list_to_tuple_BM (const struct listtop_stBM *lis);

//////////////// obj list payload

extern void objputlistpayl_BM (objectval_tyBM * obj);
static inline struct listtop_stBM *objgetlistpayl_BM (objectval_tyBM * obj);
static inline bool objhaslistpayl_BM (objectval_tyBM * obj);
static inline value_tyBM objlistfirstpayl_BM (objectval_tyBM * obj);
static inline value_tyBM objlistlastpayl_BM (objectval_tyBM * obj);
static inline unsigned objlistlengthpayl_BM (objectval_tyBM * obj);
static inline void objlistclearpayl_BM (objectval_tyBM * obj);
static inline void objlistappendpayl_BM (objectval_tyBM * obj,
                                         value_tyBM val);
static inline void objlistprependpayl_BM (objectval_tyBM * obj,
                                          value_tyBM val);
static inline void objlistpopfirstpayl_BM (objectval_tyBM * obj);
static inline void objlistpoplastpayl_BM (objectval_tyBM * obj);
static inline const node_tyBM *objlisttonodepayl_BM (objectval_tyBM * obj,
                                                     const objectval_tyBM *
                                                     obconn);
static inline const tupleval_tyBM *objlisttotuplepayl_BM (objectval_tyBM *
                                                          obj);
////////////////////////////////


extern void classinfogcmark_BM (struct garbcoll_stBM *gc,
                                struct classinfo_stBM *clinf, int depth);
extern void classinfogcdestroy_BM (struct garbcoll_stBM *gc,
                                   struct classinfo_stBM *clinf);
extern void classinfogckeep_BM (struct garbcoll_stBM *gc,
                                struct classinfo_stBM *clinf);

////////////////////////////////
extern struct dict_stBM *dictmake_BM (void);
static inline bool isdict_BM (const value_tyBM v);
extern unsigned dictsize_BM (const struct dict_stBM *dict);
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

//////////////// obj dict payload
extern void objputdictpayl_BM (objectval_tyBM * obj);
static inline struct dict_stBM *objgetdictpayl_BM (objectval_tyBM * obj);
static inline bool objhasdictpayl_BM (objectval_tyBM * obj);
static inline unsigned objdictsizepayl_BM (objectval_tyBM * obj);
static inline value_tyBM objdictgetpayl_BM (objectval_tyBM * obj,
                                            const stringval_tyBM * str);
static inline void objdictputpayl_BM (objectval_tyBM * obj,
                                      const stringval_tyBM * str,
                                      const value_tyBM val);
static inline void objdictremovepayl_BM (objectval_tyBM * obj,
                                         const stringval_tyBM * str);
static inline const stringval_tyBM *objdictkeyafterpayl_BM
  (objectval_tyBM * obj, const stringval_tyBM * str);
static inline const stringval_tyBM
  * objdictkeysameorafterpayl_BM (objectval_tyBM * obj,
                                  const stringval_tyBM * str);

static inline const stringval_tyBM *objdictkeybeforepayl_BM
  (objectval_tyBM * obj, const stringval_tyBM * str);

static inline const node_tyBM *objdictnodeofkeyspayl_BM
  (objectval_tyBM * obj, const objectval_tyBM * obconn);
////////////////////////////////
static inline bool ishashsetval_BM (const value_tyBM v);
static inline bool ishashsetvbucket_BM (const value_tyBM v);
extern void hashsetvalgcmark_BM (struct garbcoll_stBM *gc,
                                 struct hashsetval_stBM *hsv, int depth);
extern void hashsetvbucketgcmark_BM (struct garbcoll_stBM *gc,
                                     struct hashsetvbucket_stBM *hvb,
                                     int depth);
extern void hashsetvalgcdestroy_BM (struct garbcoll_stBM *gc,
                                    struct hashsetval_stBM *hsv);
extern void hashsetvbucketgcdestroy_BM (struct garbcoll_stBM *gc,
                                        struct hashsetvbucket_stBM *hvb);
extern void hashsetvalgckeep_BM (struct garbcoll_stBM *gc,
                                 struct hashsetval_stBM *hsv);
extern void hashsetvbucketgckeep_BM (struct garbcoll_stBM *gc,
                                     struct hashsetvbucket_stBM *hvb);
extern bool hashsetvalcontains_BM (struct hashsetval_stBM *hsv,
                                   value_tyBM val);
extern struct hashsetval_stBM *hashsetvalreorganize_BM
  (struct hashsetval_stBM *hsv, unsigned gap);
extern struct hashsetval_stBM *hashsetvalput_BM (struct hashsetval_stBM *hsv,
                                                 value_tyBM val);
extern struct hashsetval_stBM *hashsetvalremove_BM (struct hashsetval_stBM
                                                    *hsv, value_tyBM val);

/** to iterate in an hashsetval using
  for (value_tyBM v = hashsetvalfirst_BM(hsv); v!=NULL;
       v = hashsetvalnext_BM(hsv, v))
 which makes only sense with an unchanged hashsetval
 (so no insertion or deletion or reorganization inside the loop body)
 **/
extern value_tyBM hashsetvalfirst_BM (struct hashsetval_stBM *hsv);
extern value_tyBM hashsetvalnext_BM (struct hashsetval_stBM *hsv,
                                     value_tyBM prev);
/* make a wide node from all the (sorted) values inside an hashsetval */
extern value_tyBM hashsetvalmakenode_BM (struct hashsetval_stBM *hsv,
                                         objectval_tyBM * connob);

//////////////// obj hashsetval payload

static inline void objputhashsetvalpayl_BM (objectval_tyBM * obj,
                                            unsigned gap);
static inline struct hashsetval_stBM *objgethashsetvalpayl_BM (objectval_tyBM
                                                               * obj);
static inline bool objhashashsetvalpayl_BM (objectval_tyBM * obj);
static inline bool objhashsetvalcontainspayl_BM (objectval_tyBM * obj,
                                                 value_tyBM val);
static inline void objhashsetvalreorganizepayl_BM (objectval_tyBM * obj,
                                                   unsigned gap);
static inline void objhashsetvalputpayl_BM (objectval_tyBM * obj,
                                            value_tyBM val);
static inline void objhashsetvalremovepayl_BM (objectval_tyBM * obj,
                                               value_tyBM val);

/** to iterate in an hashsetval obj payload using
  for (value_tyBM v = objhashsetvalfirstpayl_BM(obhs); v!=NULL;
       v = objhashsetvalnextpayl_BM(obhs, v))
 which makes only sense with an unchanged hashsetval
 (so no insertion or deletion or reorganization inside the loop body)
 **/
static inline value_tyBM objhashsetvalfirstpayl_BM (objectval_tyBM * obj);
static inline value_tyBM objhashsetvalnextpayl_BM (objectval_tyBM * obj,
                                                   value_tyBM prev);
static inline value_tyBM objhashsetvalmakenodepayl_BM (objectval_tyBM * obj,
                                                       objectval_tyBM *
                                                       connob);
////////////////////////////////
//// hash maps associating values to values
static inline bool ishashmapval_BM (const value_tyBM v);
static inline bool ishashmapbucket_BM (const value_tyBM v);
extern void hashmapvalgcmark_BM (struct garbcoll_stBM *gc,
                                 struct hashmapval_stBM *hsv, int depth);
extern void hashmapbucketgcmark_BM (struct garbcoll_stBM *gc,
                                    struct hashmapbucket_stBM *hvb,
                                    int depth);
extern void hashmapvalgcdestroy_BM (struct garbcoll_stBM *gc,
                                    struct hashmapval_stBM *hsv);
extern void hashmapbucketgcdestroy_BM (struct garbcoll_stBM *gc,
                                       struct hashmapbucket_stBM *hvb);
extern void hashmapvalgckeep_BM (struct garbcoll_stBM *gc,
                                 struct hashmapval_stBM *hsv);
extern void hashmapbucketgckeep_BM (struct garbcoll_stBM *gc,
                                    struct hashmapbucket_stBM *hvb);

extern value_tyBM
hashmapvalget_BM (struct hashmapval_stBM *hmv, value_tyBM keyv);

extern struct hashmapval_stBM *hashmapvalreorganize_BM
  (struct hashmapval_stBM *hmv, unsigned gap);

extern struct hashmapval_stBM *hashmapvalput_BM
  (struct hashmapval_stBM *hmv, value_tyBM keyv, value_tyBM valv);

extern struct hashmapval_stBM *hashmapvalremove_BM
  (struct hashmapval_stBM *hmv, value_tyBM keyv);

/** to iterate in an hashmapval using
  for (value_tyBM kv = hashmapvalfirstkey_BM(hmv); kv!=NULL;
       kv = hashmapvalnextkey_BM(hsv, kv))
 which makes only sense with an unchanged hashmapval
 (so no insertion or deletion or reorganization inside the loop body)
 **/
extern value_tyBM hashmapvalfirstkey_BM (struct hashmapval_stBM *hmv);
extern value_tyBM hashmapvalnextkey_BM (struct hashmapval_stBM *hmv,
                                        value_tyBM prevk);

extern value_tyBM
  hashmapvalmakenodeofkeys_BM
  (struct hashmapval_stBM *hmv, objectval_tyBM * connob);

//////////////// obj hashmapval payload 

extern void objputhashmapvalpayl_BM (objectval_tyBM * obj, unsigned gap);
static inline struct hashmapval_stBM *objgethashmapvalpayl_BM
  (objectval_tyBM * obj);
static inline bool objhashashmapvalpayl_BM (objectval_tyBM * obj);
static inline value_tyBM objhashmapvalgetpayl_BM (objectval_tyBM * obj,
                                                  value_tyBM keyv);
static inline void objhashmapvalreorganizepayl_BM (objectval_tyBM * obj,
                                                   unsigned gap);
static inline void objhashmapvalputpayl_BM (objectval_tyBM * obj,
                                            value_tyBM keyv, value_tyBM valv);
static inline void objhashmapvalremovepayl_BM (objectval_tyBM * obj,
                                               value_tyBM keyv);
static inline value_tyBM objhashmapvalfirstkeypayl_BM (objectval_tyBM * obj);
static inline value_tyBM objhashmapvalnextkeypayl_BM (objectval_tyBM * obj,
                                                      value_tyBM prevk);
static inline value_tyBM objhashmapvalmakenodeofkeyspayl_BM
  (objectval_tyBM * obj, objectval_tyBM * connob);
////////////////////////////////////////////////////////////////
////////////////
/** apply a closure, or directly an object; so applying OBJ is same as
    applying closure % OBJ () without closed values */

extern value_tyBM apply0_BM (const value_tyBM funv,
                             struct stackframe_stBM *stkf);

extern value_tyBM apply1_BM (const value_tyBM funv,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1);

extern value_tyBM apply2_BM (const value_tyBM funv,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1, const value_tyBM arg2);

extern value_tyBM apply3_BM (const value_tyBM funv,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1, const value_tyBM arg2,
                             const value_tyBM arg3);

extern value_tyBM apply4_BM (const value_tyBM funv,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1, const value_tyBM arg2,
                             const value_tyBM arg3, const value_tyBM arg4);

extern value_tyBM apply5_BM (const value_tyBM funv,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1, const value_tyBM arg2,
                             const value_tyBM arg3, const value_tyBM arg4,
                             const value_tyBM arg5);

extern value_tyBM apply6_BM (const value_tyBM funv,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1, const value_tyBM arg2,
                             const value_tyBM arg3, const value_tyBM arg4,
                             const value_tyBM arg5, const value_tyBM arg6);

extern value_tyBM apply7_BM (const value_tyBM funv,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1, const value_tyBM arg2,
                             const value_tyBM arg3, const value_tyBM arg4,
                             const value_tyBM arg5, const value_tyBM arg6,
                             const value_tyBM arg7);

extern value_tyBM apply8_BM (const value_tyBM funv,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1, const value_tyBM arg2,
                             const value_tyBM arg3, const value_tyBM arg4,
                             const value_tyBM arg5, const value_tyBM arg6,
                             const value_tyBM arg7, const value_tyBM arg8);
extern value_tyBM apply9_BM (const value_tyBM funv,
                             struct stackframe_stBM *stkf,
                             const value_tyBM arg1, const value_tyBM arg2,
                             const value_tyBM arg3, const value_tyBM arg4,
                             const value_tyBM arg5, const value_tyBM arg6,
                             const value_tyBM arg7, const value_tyBM arg8,
                             const value_tyBM arg9);

extern value_tyBM applyvar_BM (const value_tyBM funv, struct stackframe_stBM *stkf, unsigned nbargs,    // no more than MAXAPPLYARGS_BM
                               const value_tyBM * argarr);

// send dump_value, making a buffer object, giving its byte contents
extern const char *debug_outstr_value_BM (const value_tyBM val,
                                          struct stackframe_stBM *stkf,
                                          int curdepth);

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

static inline struct dumper_stBM *obdumpgetdumper_BM (objectval_tyBM *
                                                      dumpob);
extern bool obdumpobjisdumpable_BM (objectval_tyBM * dumpob,
                                    const objectval_tyBM * obj);
extern bool obdumpvalisdumpable_BM (objectval_tyBM * dumpob,
                                    const value_tyBM val);

// true if the value (and every son or component) is dumpable
extern bool obdumpvalisfullydumpable_BM (objectval_tyBM * dumpob,
                                         const value_tyBM val);

extern void obdumpscanobj_BM (objectval_tyBM * dumpob,
                              const objectval_tyBM * obj);
extern void obdumpscanvalue_BM (objectval_tyBM * dumpob, const value_tyBM val,
                                int depth);

//// parsing
extern const char *lexkindname_BM (enum parslexkind_enBM k);
extern const char *delimstr_BM (enum lexdelim_enBM d);

extern struct parser_stBM *makeparser_of_file_BM (FILE * f,
                                                  objectval_tyBM * owner);
extern struct parser_stBM *makeparser_memopen_BM (const char *filemem,
                                                  long size,
                                                  objectval_tyBM * owner);
static inline bool isparser_BM (const extendedval_tyBM v);
static inline objectval_tyBM *parserowner_BM (const extendedval_tyBM v);
static inline struct parser_stBM *objparserpayload_BM (objectval_tyBM * obj);
static inline objectval_tyBM *checkedparserowner_BM (const extendedval_tyBM
                                                     v);
static inline struct parser_stBM *parsercast_BM (const value_tyBM v);
extern void parsergcmark_BM (struct garbcoll_stBM *gc,
                             struct parser_stBM *pars);
extern void parsergcdestroy_BM (struct garbcoll_stBM *gc,
                                struct parser_stBM *pars);
extern void parsergckeep_BM (struct garbcoll_stBM *gc,
                             struct parser_stBM *pars);
extern bool parsernextline_BM (struct parser_stBM *pars);       // return false on EOF
/// test if a token can start an object
extern bool parsertokenstartobject_BM (struct parser_stBM *pars,
                                       parstoken_tyBM tok);
// get the parsed object
extern objectval_tyBM *parsergetobject_BM
  (struct parser_stBM *pars,
   struct stackframe_stBM *stkf, int depth, bool * pgotobj);

/// test if a token can start a value
extern bool parsertokenstartvalue_BM (struct parser_stBM *pars,
                                      parstoken_tyBM tok);
/// get the parsed value
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
extern void parsererrorprintf_BM (struct parser_stBM *pars,
                                  struct stackframe_stBM *stkf, unsigned line,
                                  unsigned col, const char *fmt, ...)
  __attribute__ ((format (printf, 5, 6), noreturn));
// skip spaces and comments
extern void parserskipspaces_BM (struct parser_stBM *pars,
                                 struct stackframe_stBM *stkf);
extern parstoken_tyBM parsertokenget_BM (struct parser_stBM *pars,
                                         struct stackframe_stBM *stkf);

// internal GC related routines

// used by VALUEGCPROC_BM macro
extern void *valuegcproc_BM (struct garbcoll_stBM *gc, value_tyBM val,
                             int depth) __attribute__ ((warn_unused_result));
// used by EXTENDEDGCPROC_BM macro
extern void *extendedgcproc_BM (struct garbcoll_stBM *gc,
                                extendedval_tyBM xval, int depth)
  __attribute__ ((warn_unused_result));

extern void gcobjmark_BM (struct garbcoll_stBM *gc, objectval_tyBM * obj);
extern void gcframemark_BM (struct garbcoll_stBM *gc,
                            struct stackframe_stBM *stkfram, int depth);
extern void gctokenmark_BM (struct garbcoll_stBM *gc,
                            struct parstoken_stBM *tok);

/// the full garbage collector
extern void full_garbage_collection_BM (struct stackframe_stBM *stkfram);
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
extern void gcmarkdefergtk_BM (struct garbcoll_stBM *gc);
extern void gcmarkconstants_BM (struct garbcoll_stBM *gc);

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
extern void initialize_newgui_BM (const char *builderfile,
                                  const char *cssfile);
extern void initialize_gui_tags_BM (GtkBuilder * bld);
extern GtkWidget *initialize_gui_menubar_BM (GtkWidget * mainvbox,
                                             GtkBuilder * bld);
extern GtkWidget *initialize_oldgui_command_scrollview_BM (void);
extern GtkWidget *initialize_newgui_command_scrollview_BM (void);
extern GtkWidget *initialize_log_scrollview_BM (void);


// the periodic GC function
extern gboolean guiperiodicgarbagecollection_BM (gpointer);

////////////////////////////////////////////////////////////////

/******** GUI functions ***********/
// browse the object objbrows, using the selector objsel
extern void browse_object_gui_BM (const objectval_tyBM * objbrows,
                                  const objectval_tyBM * objsel,
                                  int browsdepth,
                                  struct stackframe_stBM *stkf);
extern void hide_object_gui_BM (const objectval_tyBM * objbrows,
                                struct stackframe_stBM *stkf);


// defer an application, running in the (GTK) main thread
void
gtk_defer_apply3_BM (value_tyBM closv, value_tyBM arg1, value_tyBM arg2,
                     value_tyBM arg3, struct stackframe_stBM *stkf);

// defer a message send, running in the (GTK) main thread
void
gtk_defer_send3_BM (value_tyBM recv, objectval_tyBM * obsel, value_tyBM arg1,
                    value_tyBM arg2, value_tyBM arg3,
                    struct stackframe_stBM *stkf);

extern void clear_command_BM (void);
// internal, inside browsing methods
extern void browse_value_BM (const value_tyBM val,
                             struct stackframe_stBM *stkf,
                             int maxdepth, int curdepth);


extern void browsespacefordepth_BM (int depth);
extern void browsenewlinefordepth_BM (int depth);

// the function to handle tabautocomplete in command
void tabautocomplete_gui_cmd_BM (void);
extern void gcmarkoldgui_BM (struct garbcoll_stBM *gc);
extern void gcmarknewgui_BM (struct garbcoll_stBM *gc);
extern void gui_gc_message_BM (const char *msg);
extern void
browse_value_BM (const value_tyBM val,
                 struct stackframe_stBM *stkf, int maxdepth, int curdepth);

extern int browse_show_start_offset_BM (void);

extern struct browsedobj_stBM *find_browsed_object_BM
  (const objectval_tyBM * obj);

extern struct browsedval_stBM *find_browsed_named_value_BM
  (const char *valname);

extern void browse_add_parens_BM (int openoff, int closeoff,
                                  int xtraoff, unsigned openlen,
                                  unsigned closelen, unsigned xtralen,
                                  int depth, struct stackframe_stBM *stkf);
extern void newgui_browse_add_parens_BM (int openoff, int closeoff,
                                         int xtraoff, unsigned openlen,
                                         unsigned closelen, unsigned xtralen,
                                         int depth,
                                         struct stackframe_stBM *stkf);

extern const char *textiterstrdbg_BM (GtkTextIter * it);

extern void cssparsingerror_BM (GtkCssProvider *, GtkCssSection *, GError *,
                                gpointer) __attribute__ ((noreturn));

extern void quitgui_BM (void);
extern void exitgui_BM (void);
extern void dumpgui_BM (void);
extern void garbcollgui_BM (void);
extern bool deletemainwin_BM (GtkWidget *, GdkEvent *, gpointer);
extern GtkTextBuffer *newgui_get_browsebuf_BM (void);


extern void log_begin_message_BM (void);
extern void log_object_message_BM (const objectval_tyBM * obj);
extern void log_puts_message_BM (const char *msg);
extern void log_printf_message_BM (const char *fmt, ...)
  __attribute__ ((format (printf, 1, 2)));
extern void log_end_message_BM (void);






// decorate e.g. // or | with commentsign_cmdtag
extern parser_decorate_comment_sign_sigBM parscommentsign_guicmd_BM;

// decorate with commentinside_cmdtag
extern parser_decorate_comment_inside_sigBM parscommentinside_guicmd_BM;

// decorate with delim_cmdtag
extern parser_decorate_delimiter_sigBM parsdelim_guicmd_BM;

// decorate with id_cmdtag
extern parser_decorate_id_sigBM parsid_guicmd_BM;

// decorate with knowname_cmdtag
extern parser_decorate_name_sigBM parsknowname_guicmd_BM;

// decorate with newname_cmdtag
extern parser_decorate_name_sigBM parsnewname_guicmd_BM;

// decorate open/close with nesting_cmdtag & open/close tags
extern parser_decorate_nesting_sigBM parsnesting_guicmd_BM;

// decorate start/open/close with nesting_cmdtag & start/open/close tags
extern parser_decorate_start_nesting_sigBM parsstartnesting_guicmd_BM;

// decorate numbers
extern parser_decorate_number_sigBM parsnumber_guicmd_BM;

// decorate strings
extern parser_decorate_string_sign_sigBM parsstringsign_guicmd_BM;
extern parser_decorate_string_inside_sigBM parsstringinside_guicmd_BM;
////////////////////////////////////////////////////////////////

/******** agenda functions ***********/
extern void initialize_agenda_BM (void);
extern int agenda_nb_work_jobs_BM (void);
extern void gcmarkagenda_BM (struct garbcoll_stBM *gc);
extern void start_agenda_work_threads_BM (int nbjobs);
extern void stop_agenda_work_threads_BM (void);
// inside the GC, wait for all work thread to idle for garbage collection
extern void agenda_suspend_for_gc_BM (void);
extern void agenda_continue_after_gc_BM (void);
extern void agenda_add_very_high_priority_tasklet_BM (objectval_tyBM *);
extern void agenda_add_high_priority_tasklet_BM (objectval_tyBM *);
extern void agenda_add_normal_priority_tasklet_BM (objectval_tyBM *);
extern void agenda_add_low_priority_tasklet_BM (objectval_tyBM *);
extern void agenda_add_very_low_priority_tasklet_BM (objectval_tyBM *);
extern bool agenda_remove_tasklet_BM (objectval_tyBM *);
extern bool agenda_has_tasklet_BM (objectval_tyBM *);
// return total number of tasklets
extern long agenda_get_counts_BM (long *pveryhigh, long *phigh, long *pnormal,
                                  long *plow, long *pverylow);
extern long agenda_get_sets_BM (value_tyBM * pveryhighset,
                                value_tyBM * phighset, value_tyBM * pnormset,
                                value_tyBM * plowset,
                                value_tyBM * pverylowset);
#endif /*FUNDECL_BM_INCLUDED */
