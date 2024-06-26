// file fundecl_BM.h
// SPDX-License-Identifier: GPL-3.0-or-later
/***
    BISMON 
    Copyright © 2018 - 2022 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch (working at CEA, LIST, France)
    <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>

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

#ifdef __cplusplus
extern "C"
{
#endif /*__cplusplus*/

  extern void abort_BM (void) __attribute__((noreturn));
  static inline pid_t gettid_BM (void);

  extern int64_t prime_above_BM (int64_t n);
  extern int64_t prime_below_BM (int64_t n);


  static inline const char *basename_BM (const char *);
  extern const char *bismon_home_BM (void);

  extern void
    backtrace_print_BM (struct backtrace_state *state, int skip, FILE * f);

  extern void warning_at_BM(const char*fil, int lin);

  static inline double clocktime_BM (clockid_t);

// convert some absolute Unix Epoch time into milliseconds since Y2K
  static inline intptr_t timetoY2Kmillisec_BM (double t);
// convert milliseconds since Y2K to absolute Unix Epoch time
  static inline double Y2Kmillisectotime_BM (intptr_t);

  static inline double cputime_BM (void);
  static inline double elapsedtime_BM (void);
  /// return a static buffer containing the real executable path
  extern const char* get_real_executable_path_BM(void);
  static inline void get_realtimespec_delayedms_BM (struct timespec *pts,
                                                    unsigned millisec);
  extern double taskletcputime_BM (void);
  extern double taskletelapsedtime_BM (void);
  static inline bool istaggedint_BM (value_tyBM v);
  static inline intptr_t getint_BM (value_tyBM v);
  static inline intptr_t getintdefault_BM (value_tyBM v, intptr_t df);
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
  extern int valcmpdepth_BM (const value_tyBM v1, const value_tyBM v2,
                             int depth);
  extern int valqcmp_BM (const void *, const void *);   // for qsort
  static inline void valarrqsort_BM (value_tyBM * arr, unsigned siz);





  extern const char *objectdbg_BM (const objectval_tyBM * obj); // non reentrant!
  extern const char *objectdbg1_BM (const objectval_tyBM * obj);        // non reentrant!
  extern const char *objectdbg2_BM (const objectval_tyBM * obj);        // non reentrant!
  extern const char *objectdbg3_BM (const objectval_tyBM * obj);        // non reentrant!
  extern const char *objectdbg4_BM (const objectval_tyBM * obj);        // non reentrant!
  extern const char *objectdbg5_BM (const objectval_tyBM * obj);        // non reentrant!
  extern const char *objectdbg6_BM (const objectval_tyBM * obj);        // non reentrant!
  extern const char *objectdbg7_BM (const objectval_tyBM * obj);        // non reentrant!


  /* see the objrout_sigBM signature in types_BM.h */
extern value_tyBM crashing_objrout_BM (struct stackframe_stBM *stkf,
				       const value_tyBM arg1,
				       const value_tyBM arg2,
				       const value_tyBM arg3,
				       const value_tyBM arg4,
				       const quasinode_tyBM * restargs);
extern value_tyBM warning_objrout_BM(struct stackframe_stBM *stkf,
				     const value_tyBM arg1,
				     const value_tyBM arg2,
				     const value_tyBM arg3,
				     const value_tyBM arg4,
				     const quasinode_tyBM * restargs);


  extern void *allocgcty_BM (unsigned type, size_t sz);


  static inline bool isstring_BM (const value_tyBM v);
  static inline bool hasstring_BM (const value_tyBM v, const char *str);
  static inline const stringval_tyBM *stringcast_BM (const value_tyBM);
  extern hash_tyBM stringhash_BM (const char *str);
  extern hash_tyBM stringhashlen_BM (const char *str, long len);
  extern const stringval_tyBM *makestring_BM (const char *str);
  extern const stringval_tyBM *makestringlen_BM (const char *str, long len);
  extern const stringval_tyBM *sprintfstring_BM (const char *fmt, ...)
    __attribute__((format (printf, 1, 2)));
// stringify the strftime of localtime, of gmtime...
  extern const stringval_tyBM *flocaltimestring_BM (const char *fmt,
                                                    time_t ti);
  extern const stringval_tyBM *fgmtimestring_BM (const char *fmt, time_t ti);
// stringify the strftime, but a .__ is replaced by two decimal digits
  extern const stringval_tyBM *flocaltimedblstring_BM (const char *fmt,
                                                       double ti);
  extern const stringval_tyBM *fgmtimedblstring_BM (const char *fmt,
                                                    double ti);
// stringify a raw string, up to its first space character
  extern const stringval_tyBM *prefixtofirstspacestring_BM (const char *str);

// stringify the lastgitcommit
  extern const stringval_tyBM *lastgitcommitstring_BM (void);

  extern int lenstring_BM (const stringval_tyBM *);     // length in bytes
  extern const char *bytstring_BM (const stringval_tyBM *);
  extern void *stringgcproc_BM (struct garbcoll_stBM *gc,
                                stringval_tyBM * str)
    __attribute__((warn_unused_result));
  extern void stringgcdestroy_BM (struct garbcoll_stBM *, stringval_tyBM *);

  extern void stringgckeep_BM (struct garbcoll_stBM *, stringval_tyBM *);

  static inline bool istuple_BM (const value_tyBM v);
  static inline const tupleval_tyBM *tuplecast_BM (const value_tyBM);
  extern const tupleval_tyBM *maketuple_BM (objectval_tyBM ** arr,
                                            unsigned rawsiz);
  extern const tupleval_tyBM *makesizedtuple_BM (unsigned nbargs, ...);
// collect objects or sequences into a tuple
  extern const tupleval_tyBM *maketuplecollect_BM (value_tyBM, ...)
    __attribute__((sentinel));
#define MAKETUPLECOLLECT_BM(...) maketuplecollect_BM(__VA_ARGS__, NULL)
  extern const tupleval_tyBM *makesizedcollecttuple_BM (unsigned nbargs, ...);
  extern unsigned tuplesize_BM (const tupleval_tyBM * tup);
  extern objectval_tyBM *tuplecompnth_BM (const tupleval_tyBM * tup, int rk);
  extern void *tuplegcproc_BM (struct garbcoll_stBM *gc, tupleval_tyBM * tup)
    __attribute__((warn_unused_result));
  extern void tuplegcdestroy_BM (struct garbcoll_stBM *gc,
                                 tupleval_tyBM * tup);
  extern void tuplegckeep_BM (struct garbcoll_stBM *gc, tupleval_tyBM * tup);


  static inline bool issequence_BM (const value_tyBM v);
  static inline const seqobval_tyBM *sequencecast_BM (const value_tyBM v);
  extern unsigned sequencesize_BM (const seqobval_tyBM * sq);
  extern objectval_tyBM *sequencenthcomp_BM (const seqobval_tyBM * sq,
                                             int rk);
  static inline bool isset_BM (const value_tyBM v);
  static inline const setval_tyBM *setcast_BM (const value_tyBM v);
  extern const setval_tyBM *makeset_BM (const objectval_tyBM ** arr,
                                        unsigned rawsiz);
  extern const setval_tyBM *makesizedset_BM (unsigned nbargs, ...);
// collect objects or sequences into a set
  extern const setval_tyBM *makesetcollect_BM (value_tyBM, ...)
    __attribute__((sentinel));
#define MAKESETCOLLECT_BM(...) makesetcollect_BM(__VA_ARGS__, NULL)
  extern const setval_tyBM *makesizedcollectset_BM (unsigned nbargs, ...);
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
    __attribute__((warn_unused_result));
  extern void setgcdestroy_BM (struct garbcoll_stBM *gc, setval_tyBM * set);
  extern void setgckeep_BM (struct garbcoll_stBM *gc, setval_tyBM * set);



  static inline bool istree_BM (const value_tyBM v);
  static inline const tree_tyBM *treecast_BM (const value_tyBM);
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
                              int depth) __attribute__((warn_unused_result));
  extern void nodegcdestroy_BM (struct garbcoll_stBM *gc, node_tyBM * nod);
  extern void nodegckeep_BM (struct garbcoll_stBM *gc, node_tyBM * nod);

  extern const node_tyBM *makenode_BM (const objectval_tyBM * connob,
                                       unsigned nbval,
                                       const value_tyBM * sonvalarr);

  static inline const node_tyBM *makenode0_BM (const objectval_tyBM * connob);
  static inline const node_tyBM *makenode1_BM (const objectval_tyBM * connob,
                                               value_tyBM v0);
  static inline const node_tyBM *makenode2_BM (const objectval_tyBM * connob,
                                               value_tyBM v0, value_tyBM v1);
  static inline const node_tyBM *makenode3_BM (const objectval_tyBM * connob,
                                               value_tyBM v0, value_tyBM v1,
                                               value_tyBM v2);
  static inline const node_tyBM *makenode4_BM (const objectval_tyBM * connob,
                                               value_tyBM v0, value_tyBM v1,
                                               value_tyBM v2, value_tyBM v3);
  static inline const node_tyBM *makenode5_BM (const objectval_tyBM * connob,
                                               value_tyBM v0, value_tyBM v1,
                                               value_tyBM v2, value_tyBM v3,
                                               value_tyBM v4);
  static inline const node_tyBM *makenode6_BM (const objectval_tyBM * connob,
                                               value_tyBM v0, value_tyBM v1,
                                               value_tyBM v2, value_tyBM v3,
                                               value_tyBM v4, value_tyBM v5);
  static inline const node_tyBM *makenode7_BM (const objectval_tyBM * connob,
                                               value_tyBM v0, value_tyBM v1,
                                               value_tyBM v2, value_tyBM v3,
                                               value_tyBM v4, value_tyBM v5,
                                               value_tyBM v6);
  static inline const node_tyBM *makenode8_BM (const objectval_tyBM * connob,
                                               value_tyBM v0, value_tyBM v1,
                                               value_tyBM v2, value_tyBM v3,
                                               value_tyBM v4, value_tyBM v5,
                                               value_tyBM v6, value_tyBM v7);

/// make a node from the rest of some tree (node, closure or quasinode) value, with a starting index startix
  extern const node_tyBM *makenodetreerest_BM (const objectval_tyBM * connob,
                                               value_tyBM treev, int startix);

  extern const node_tyBM *makesizednode_BM (unsigned siz,
                                            const objectval_tyBM * connob,
                                            ...);

  extern const node_tyBM *makenodevar_BM (const objectval_tyBM * connob, ...)
    __attribute__((sentinel));

////////
  extern const closure_tyBM *makeclosure_BM (const objectval_tyBM * conn,
                                             unsigned nbclos,
                                             const value_tyBM * closvalarr);

  static inline const closure_tyBM *makeclosure0_BM (const objectval_tyBM *
                                                     connob);
  static inline const closure_tyBM *makeclosure1_BM (const objectval_tyBM *
                                                     connob, value_tyBM v0);
  static inline const closure_tyBM *makeclosure2_BM (const objectval_tyBM *
                                                     connob, value_tyBM v0,
                                                     value_tyBM v1);
  static inline const closure_tyBM *makeclosure3_BM (const objectval_tyBM *
                                                     connob, value_tyBM v0,
                                                     value_tyBM v1,
                                                     value_tyBM v2);
  static inline const closure_tyBM *makeclosure4_BM (const objectval_tyBM *
                                                     connob, value_tyBM v0,
                                                     value_tyBM v1,
                                                     value_tyBM v2,
                                                     value_tyBM v3);
  static inline const closure_tyBM *makeclosure5_BM (const objectval_tyBM *
                                                     connob, value_tyBM v0,
                                                     value_tyBM v1,
                                                     value_tyBM v2,
                                                     value_tyBM v3,
                                                     value_tyBM v4);
  static inline const closure_tyBM *makeclosure6_BM (const objectval_tyBM *
                                                     connob, value_tyBM v0,
                                                     value_tyBM v1,
                                                     value_tyBM v2,
                                                     value_tyBM v3,
                                                     value_tyBM v4,
                                                     value_tyBM v5);
  static inline const closure_tyBM *makeclosure7_BM (const objectval_tyBM *
                                                     connob, value_tyBM v0,
                                                     value_tyBM v1,
                                                     value_tyBM v2,
                                                     value_tyBM v3,
                                                     value_tyBM v4,
                                                     value_tyBM v5,
                                                     value_tyBM v6);
  static inline const closure_tyBM *makeclosure8_BM (const objectval_tyBM *
                                                     connob, value_tyBM v0,
                                                     value_tyBM v1,
                                                     value_tyBM v2,
                                                     value_tyBM v3,
                                                     value_tyBM v4,
                                                     value_tyBM v5,
                                                     value_tyBM v6,
                                                     value_tyBM v7);

  extern const closure_tyBM *makesizedclosure_BM (unsigned siz,
                                                  const objectval_tyBM *
                                                  connob, ...);

  extern const closure_tyBM *makeclosurevar_BM (const objectval_tyBM * connob,
                                                ...)
    __attribute__((sentinel));

  extern void *closuregcproc_BM (struct garbcoll_stBM *gc,
                                 closure_tyBM * clos, int depth)
    __attribute__((warn_unused_result));
  extern void closuregcdestroy_BM (struct garbcoll_stBM *gc,
                                   closure_tyBM * clos);
  extern void closuregckeep_BM (struct garbcoll_stBM *gc,
                                closure_tyBM * clos);

  extern void *quasinodegcproc_BM (struct garbcoll_stBM *gc,
                                   quasinode_tyBM * quasi, int depth)
    __attribute__((warn_unused_result));
////////////////
// support for boxed doubles
  extern void *doublegcproc_BM (struct garbcoll_stBM *gc,
                                doubleval_tyBM * dbl);
  extern void doublegcdestroy_BM (struct garbcoll_stBM *gc,
                                  doubleval_tyBM * dblv);
  extern void doublegckeep_BM (struct garbcoll_stBM *gc,
                               doubleval_tyBM * dblv);
  extern value_tyBM makedouble_BM (double x);   /* gives the boxed double, or else `nan_double` if it is NaN */
  static inline bool isdouble_BM (const value_tyBM val);
  static inline const doubleval_tyBM *doublecast_BM (const value_tyBM val);
  static inline double getdouble_BM (const value_tyBM val);     /* unbox the double or else gives NaN */

// a total order, but x and y cannot be NaN, e.g. because the are from
// a boxed double:
  extern int doublecmp_BM (double x, double y); /* in misc_BM.cc */
// the hash of doubles
  extern hash_tyBM doublehash_BM (double x);    /* in misc_BM.cc */
////////////////

// initialize the GC and mainthreadid_BM
  extern void initialize_garbage_collector_BM (void);
  extern void initialize_predefined_objects_BM (void);

// cleanup C++ miscellanous data; also dlclose-s modules!
  extern void final_miscdata_cleanup_BM (void);

// final cleanup of memory to make valgrind happy
  extern void final_cleanup_BM (void);

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
  extern objectval_tyBM *findobjofstrid_BM (const char *idstr);
  extern objectval_tyBM *lockedfindobjofstrid_BM (const char *idstr);
  extern objectval_tyBM *makeobjofid_BM (const rawid_tyBM id);

// from obconst, instance of basiclo_constant_object, retrieves its
// value, whose hash is given
  extern value_tyBM constobjvaluehashed_BM (objectval_tyBM * obconst,
                                            hash_tyBM hash);
// find the set of objects of an id prefixed by some prefix of at
// least three characters starting with _ then a digit
  extern const setval_tyBM *setobjectsofidprefixed_BM (const char *prefix);
  extern objectval_tyBM *makeobj_BM (void);
  static inline rawid_tyBM objid_BM (const objectval_tyBM * obj);
  static inline double objmtime_BM (const objectval_tyBM * obj);
  static inline intptr_t objmtimeY2Kmilli_BM (const objectval_tyBM * obj);
  static inline objectval_tyBM *objsignature_BM (const objectval_tyBM * obj);
  static inline void *objroutaddr_BM (const objectval_tyBM * obj,
                                      const objectval_tyBM * objsig);

  extern objrout_sigBM objrout_placeholder_BM;
  extern bool read_sigfd_BM();
  static inline void objtouchmtime_BM (objectval_tyBM * obj, double mtime);
  static inline void objtouchnow_BM (objectval_tyBM * obj);

// the cleared object has no payload, no components, no attributes, no
// routine, no signature, and becomes a transient instance of BMP_object
  extern void objcompletelyclear_BM (objectval_tyBM * obj);
  extern void objputspacenum_BM (objectval_tyBM * obj, unsigned spanum);
  static inline unsigned objspacenum_BM (const objectval_tyBM * obj);
  static inline objectval_tyBM *objclass_BM (const objectval_tyBM * obj);
  extern void objputclass_BM (objectval_tyBM * obj,
                              objectval_tyBM * objclass);
// return true on success
  static inline bool objlock_BM (objectval_tyBM * obj);
  static inline bool objunlock_BM (objectval_tyBM * obj);
  static inline bool objtrylock_BM (objectval_tyBM * obj);
// return true if the object was already locked in the same thread
  static inline bool objislocked_BM (objectval_tyBM * obj);
  static inline value_tyBM objgetattr_BM (const objectval_tyBM * obj,
                                          const objectval_tyBM * objattr);
  static inline unsigned objnbattrs_BM (const objectval_tyBM * obj);
  static inline const setval_tyBM *objsetattrs_BM (const objectval_tyBM *
                                                   obj);

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
  static inline objectval_tyBM *        //
    objgetclassinfosuperclass_BM (const objectval_tyBM * obj);

  static inline const closure_tyBM *    //
    objgetclassinfomethod_BM (const objectval_tyBM * obj,       //
                              const objectval_tyBM * obselector);

  extern void
    objclassinfoputmethod_BM (objectval_tyBM * obj,
                              objectval_tyBM * obselector,
                              const closure_tyBM * clos);

  extern void
    objclassinforemovemethod_BM (objectval_tyBM * obj,
                                 objectval_tyBM * obselector);

  static inline const setval_tyBM *     //
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
    __attribute__((noreturn));
// see PLAINFAILURE_BM & PLACEDFAILURE_BM macros
  extern void failure_at_BM (int failcode, const char *fil, int lineno,
                             const value_tyBM reasonv,
                             const value_tyBM placev,
                             struct stackframe_stBM *stkf)
    __attribute__((noreturn));

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
  static inline value_tyBM sendvar_BM (const value_tyBM recv, const objectval_tyBM * obselector, struct stackframe_stBM *stkf, unsigned nbargs, // no more than MAXAPPLYARGS_BM-1
                                       const value_tyBM * argarr);
  extern value_tyBM sendmany_BM (const value_tyBM recv,
                                 const objectval_tyBM * obselector,
                                 struct stackframe_stBM *stkf,
                                 unsigned nbargs, ...);

  static inline unsigned objnbcomps_BM (const objectval_tyBM * obj);
  static inline value_tyBM *objcompdata_BM (const objectval_tyBM * obj);
  static inline value_tyBM objgetcomp_BM (const objectval_tyBM * obj, int rk);
  static inline void objputcomp_BM (objectval_tyBM * obj, int rk,
                                    const value_tyBM compval);
  static inline void objreservecomps_BM (objectval_tyBM * obj, unsigned gap);
  static inline void objremoveonecomp_BM (objectval_tyBM * obj, int rk);
  static inline void objinsertonecomp_BM (objectval_tyBM * obj, int rk,
                                          const value_tyBM compval);
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
  extern void objectgckeep_BM (struct garbcoll_stBM *gc,
                               objectval_tyBM * obj);



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
  extern void objstrbuffersetindentpayl_BM (objectval_tyBM * obj, int indent);
  extern void objstrbufferlessindentpayl_BM (objectval_tyBM * obj);
  extern void objstrbufferappendcstrpayl_BM (objectval_tyBM * obj,
                                             const char *cstr);
  extern bool objstrbufferispercentfullpayl_BM (const objectval_tyBM * obj,
                                                int percentage);
  extern void objstrbufferresetpayl_BM (objectval_tyBM * obj);
  extern unsigned objstrbufferlengthpayl_BM (const objectval_tyBM * obj);
  extern unsigned objstrbufferlimitpayl_BM (const objectval_tyBM * obj);

  extern unsigned objstrbufferlinecountpayl_BM (const objectval_tyBM * obj);
  extern unsigned objstrbuffercolumnpayl_BM (const objectval_tyBM * obj);
// the current last line is invalid as soon as more content is added
// to the buffer.
  extern const char *objstrbuffercurrentlastlinepayl_BM (const objectval_tyBM
                                                         * obj);
/// raw printf
  extern void objstrbufferrawprintfpayl_BM (objectval_tyBM * obj,
                                            const char *fmt, ...)
    __attribute__((format (printf, 2, 3)));
  extern void objstrbufferspaceornewlinepayl_BM (objectval_tyBM * obj);
/// cooked printf: the tabs become spaces or indented-newlines, the
/// newlines become indented
  extern void objstrbufferprintfpayl_BM (objectval_tyBM * obj,
                                         const char *fmt, ...)
    __attribute__((format (printf, 2, 3)));
/// indented newline
  extern void objstrbuffernewlinepayl_BM (objectval_tyBM * obj);
/// output UTF8 encoded à la JSON
  extern void objstrbufferencodedutf8payl_BM (objectval_tyBM * obj,
                                              const char *str,
                                              ssize_t bytelen);

/// output into buffer `obj` the first `len` bytes of string `cstr`
  extern void
    objstrbufferappendstartstrpayl_BM (objectval_tyBM * obj, const char *cstr,
                                       int len);

/// output into buffer `obj` every line of `lines` with the given
/// `prefix`; could be used to safely emit a C or C++ comment starting
/// with a prefix like //!
  extern void
    objstrbufferoutputprefixlinespayl_BM (objectval_tyBM * obj,
                                          const char *prefix,
                                          const char *lines);

  extern void writefencodedutf8_BM (FILE * fil, const char *str,
                                    ssize_t bytelen);

/// output a double number as precisely as possible, with at least a
/// dot or an E for the exponent, so that it won't be parsed as long
/// integer. Returns true when hexadecimal %#a was used
  extern bool objstrbufferoutdoublepayl_BM (objectval_tyBM * obj, double x);

/// output a double, as a local time
  extern void objstrbufferencodelocaltimepayl_BM (objectval_tyBM * obj,
                                                  double tid);

/// output bytes encoded à la C
  extern void objstrbufferencodedcpayl_BM (objectval_tyBM * obj,
                                           const char *str, ssize_t bytelen);

/// output literal string, with the double quotes, à la C
  extern void objstrbufferliteralcstringpayl_BM (objectval_tyBM * obj,
                                                 const char *str,
                                                 ssize_t bytelen);

  extern void writefencodedc_BM (FILE * fil, const char *str,
                                 ssize_t bytelen);

/// output bytes encoded à la HTML
  extern void objstrbufferencodedhtmlpayl_BM (objectval_tyBM * obj,
                                              const char *str,
                                              ssize_t bytelen);

  extern void writefencodedhtml_BM (FILE * fil, const char *str,
                                    ssize_t bytelen);

/// output a JSON value, either indented, or compacted
  extern void objstrbufferoutputjsonindentedvaluepayl_BM (objectval_tyBM *
                                                          obj, value_tyBM val,
                                                          value_tyBM ctx,
                                                          struct
                                                          stackframe_stBM
                                                          *stkf);
  extern void objstrbufferoutputjsoncompactedvaluepayl_BM (objectval_tyBM *
                                                           obj,
                                                           value_tyBM val,
                                                           value_tyBM ctx,
                                                           struct
                                                           stackframe_stBM
                                                           *stkf);

/// write the content to a file, if different
  extern void objstrbufferwritetofilepayl_BM (objectval_tyBM * obj,
                                              const char *filepath);

/// make a string value from the content of an objstrbuffer, or else
/// NULL:
  extern value_tyBM objstrbuffertostringvaluepayl_BM (objectval_tyBM * obj);
///////

  extern void strbuffergcmark_BM (struct garbcoll_stBM *gc,
                                  struct strbuffer_stBM *sbuf,
                                  objectval_tyBM * fromob, int depth);
  extern void strbuffergcdestroy_BM (struct garbcoll_stBM *gc,
                                     struct strbuffer_stBM *sbuf);
  extern void strbuffergckeep_BM (struct garbcoll_stBM *gc,
                                  struct strbuffer_stBM *sbuf);
////////////////


  static inline bool isassoc_BM (value_tyBM v);
  static inline anyassoc_tyBM *assoccast_BM (value_tyBM v);
  extern void *assocgcproc_BM (struct garbcoll_stBM *gc,
                               anyassoc_tyBM * assoc, objectval_tyBM * fromob,
                               int depth) __attribute__((warn_unused_result));
  extern void *assocpairsgcproc_BM (struct garbcoll_stBM *gc,
                                    struct assocpairs_stBM *apairs,
                                    objectval_tyBM * fromob, int depth)
    __attribute__((warn_unused_result));
  extern void *assoctablegcproc_BM (struct garbcoll_stBM *gc,
                                    struct assoctable_stBM *atable,
                                    objectval_tyBM * fromob, int depth)
    __attribute__((warn_unused_result));
  extern void assocpairgcdestroy_BM (struct garbcoll_stBM *gc,
                                     struct assocpairs_stBM *assocpair);
  extern void assoctablegcdestroy_BM (struct garbcoll_stBM *gc,
                                      struct assoctable_stBM *assocbuck);
  extern void assocpairgckeep_BM (struct garbcoll_stBM *gc,
                                  struct assocpairs_stBM *assocpair);
  extern void assoctablegckeep_BM (struct garbcoll_stBM *gc,
                                   struct assoctable_stBM *assocbuck);

  extern unsigned assoc_nbkeys_BM (const anyassoc_tyBM * assoc);

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

  extern bool objputassocpayl_BM (objectval_tyBM * obj, unsigned initsize);
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
                                                const objectval_tyBM *
                                                obattr);
  static inline void objassocreorganizepayl_BM (objectval_tyBM * obj,
                                                unsigned gap);


//////////////// hashed and mutable set of objects
  extern struct hashsetobj_stBM *hashsetobj_grow_BM (struct hashsetobj_stBM
                                                     *hset, unsigned gap);
  static inline struct hashsetobj_stBM *hashsetobjcast_BM (const value_tyBM
                                                           v);
  extern void hashsetgcmark_BM (struct garbcoll_stBM *gc,
                                struct hashsetobj_stBM *hset,
                                objectval_tyBM * fromob);
  void hashsetgcdestroy_BM (struct garbcoll_stBM *gc,
                            struct hashsetobj_stBM *hset);
  void hashsetgckeep_BM (struct garbcoll_stBM *gc,
                         struct hashsetobj_stBM *hset);
  extern bool hashsetobj_contains_BM (struct hashsetobj_stBM *hset,
                                      const objectval_tyBM * obj);
  extern struct hashsetobj_stBM *hashsetobj_add_BM (struct hashsetobj_stBM
                                                    *hset,
                                                    const objectval_tyBM *
                                                    obj);
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
  extern const setval_tyBM *hashsetobj_to_set_BM (struct hashsetobj_stBM
                                                  *hset);
  static inline unsigned hashsetobj_cardinal_BM (struct hashsetobj_stBM
                                                 *hset);

//// obj hashset payload support

  extern bool objputhashsetpayl_BM (objectval_tyBM * obj, unsigned inisiz);
  static inline struct hashsetobj_stBM *objgethashsetpayl_BM (objectval_tyBM *
                                                              obj);
  static inline bool objhashashsetpayl_BM (objectval_tyBM * obj);
  static inline bool objhashsetcontainspayl_BM (objectval_tyBM * obj,
                                                const objectval_tyBM *
                                                obelem);
  static inline void objhashsetaddpayl_BM (objectval_tyBM * obj,
                                           objectval_tyBM * obelem);
  static inline void objhashsetremovepayl_BM (objectval_tyBM * obj,
                                              objectval_tyBM * obelem);
  static inline void objhashsetgrowpayl_BM (objectval_tyBM * obj,
                                            unsigned gap);
  static inline unsigned objhashsetcardinalpayl_BM (objectval_tyBM * obj);
  static inline const setval_tyBM *objhashsettosetpayl_BM (objectval_tyBM *
                                                           obj);
  static inline objectval_tyBM *objhashsetpickrandompayl_BM (objectval_tyBM *
                                                             obj);
  static inline objectval_tyBM *objhashsettakerandompayl_BM (objectval_tyBM *
                                                             obj);

//////////////// mutable data vector of values

  static inline unsigned datavectlen_BM (const struct datavectval_stBM *dvec);

  static inline const value_tyBM *datavectdata_BM (const struct
                                                   datavectval_stBM *dvec);

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
                                                                value_tyBM
                                                                val);
  extern struct datavectval_stBM *datavect_remove_BM (struct datavectval_stBM
                                                      *dvec, int rk,
                                                      unsigned len);

  extern struct datavectval_stBM *datavect_removeone_BM (struct
                                                         datavectval_stBM
                                                         *dvec, int ix);

  extern const node_tyBM *datavect_to_node_BM (struct datavectval_stBM *dvec,
                                               const objectval_tyBM * obconn);
  extern const tupleval_tyBM *datavect_to_tuple_BM (struct datavectval_stBM
                                                    *dvec);
  static inline value_tyBM datavectnth_BM (const struct datavectval_stBM
                                           *dvec, int rk);
  static inline value_tyBM datavectlast_BM (const struct datavectval_stBM
                                            *dvec);
  static inline void datavectputnth_BM (struct datavectval_stBM *dvec, int rk,
                                        const value_tyBM valcomp);
  extern void *datavectgcproc_BM (struct garbcoll_stBM *gc,
                                  struct datavectval_stBM *dvec,
                                  objectval_tyBM * fromob, int depth)
    __attribute__((warn_unused_result));
  extern void datavectgcdestroy_BM (struct garbcoll_stBM *gc,
                                    struct datavectval_stBM *dvec);
  extern void datavectgckeep_BM (struct garbcoll_stBM *gc,
                                 struct datavectval_stBM *dvec);


//////////////// obj datavect payload
// return true if ok
  extern bool objputdatavectpayl_BM (objectval_tyBM * obj, unsigned inisiz);
  static inline struct datavectval_stBM *objgetdatavectpayl_BM  //
    (objectval_tyBM * obj);
  static inline bool objhasdatavectpayl_BM (objectval_tyBM * obj);
  static inline unsigned objdatavectlengthpayl_BM (objectval_tyBM * obj);
  static inline const value_tyBM *objdatavectdatapayl_BM (objectval_tyBM *
                                                          obj);
  static inline void objdatavectgrowpayl_BM (objectval_tyBM * obj,
                                             unsigned gap);
  static inline void objdatavectreservepayl_BM (objectval_tyBM * obj,
                                                unsigned gap);
  static inline void objdatavectappendpayl_BM (objectval_tyBM * obj,
                                               value_tyBM val);
  static inline void objdatavectinsertpayl_BM (objectval_tyBM * obj, int rk,
                                               value_tyBM * valarr,
                                               unsigned len);
  extern void objdatavectinsertcomponentspayl_BM (objectval_tyBM * obj,
                                                  int rk,
                                                  objectval_tyBM * obsrc,
                                                  int srcrk, unsigned len);
  static inline void objdatavectinsertonepayl_BM (objectval_tyBM * obj,
                                                  int rk, value_tyBM val);

  static inline void objdatavectremovepayl_BM (objectval_tyBM * obj, int rk,
                                               unsigned len);
  static inline const node_tyBM *objdatavecttonodepayl_BM       //
    (objectval_tyBM * obj, const objectval_tyBM * obconn);
  static inline const tupleval_tyBM *objdatavecttotuplepayl_BM (objectval_tyBM
                                                                * obj);
  static inline value_tyBM objdatavectnthpayl_BM (objectval_tyBM * obj,
                                                  int rk);
  static inline void objdatavectputnthpayl_BM (objectval_tyBM * obj, int rk,
                                               const value_tyBM valcomp);
////////////////////////////////

/// decayed vectors payload, for typayl_decayed_BM

  static inline unsigned decayedvectlen_BM (const struct decayedvectpayl_stBM *dvec);   // used length
  static inline unsigned
    decayedvectallocsize_BM (const struct decayedvectpayl_stBM *dvec);
  static inline bool isdecayedvect_BM (const value_tyBM v);
  static inline bool islivedecayedvect_BM (const value_tyBM v);
  static inline const value_tyBM *decayedvectdata_BM (const struct
                                                      decayedvectpayl_stBM
                                                      *dvec);
/// return 0.0 if non decayedvect
  static inline double decayedvectlimitime_BM (const struct
                                               decayedvectpayl_stBM *dvec);
  static inline value_tyBM decayedvectnth_BM (const struct
                                              decayedvectpayl_stBM *dvec,
                                              int rk);
  static inline value_tyBM decayedvectlast_BM (const struct
                                               decayedvectpayl_stBM *dvec);
  static inline bool decayedvectputnth_BM (struct decayedvectpayl_stBM *dvec,
                                           int rk, const value_tyBM valcomp);
  static inline bool decayedvectappend_BM (struct decayedvectpayl_stBM *dvec,
                                           const value_tyBM valcomp);
// GC support for decayed vector
  extern void decayedvectorgcmark_BM (struct garbcoll_stBM *gc,
                                      struct decayedvectpayl_stBM *dvec,
                                      objectval_tyBM * fromob, int depth);
  extern void decayedvectordestroy_BM (struct garbcoll_stBM *gc,
                                       struct decayedvectpayl_stBM *dvec);
  extern void decayedvectorgckeep_BM (struct garbcoll_stBM *gc,
                                      struct decayedvectpayl_stBM *dvec);

  extern bool objputdecayedvectorpayl_BM (objectval_tyBM * obj, unsigned asiz,
                                          unsigned delayms);
  static inline struct decayedvectpayl_stBM
    *objgetdecayedvectorpayl_BM (objectval_tyBM * obj);
  static inline bool objhasdecayedvectorpayl_BM (objectval_tyBM * obj);
  static inline double objdecayedvectorlimitimepayl_BM (objectval_tyBM * obj);
  static inline value_tyBM objdecayedvectornthpayl_BM (objectval_tyBM * obj,
                                                       int rk);
  static inline value_tyBM objdecayedvectorlastpayl_BM (objectval_tyBM * obj);
  static inline const value_tyBM *objdecayedvectdatapayl_BM (objectval_tyBM *
                                                             obj);
  static inline unsigned objdecayedvectlenpayl_BM (objectval_tyBM * obj);
  static inline unsigned objdecayedvectallocsizepayl_BM (objectval_tyBM *
                                                         obj);
  static inline bool objdecayedvectorputnthpayl_BM (objectval_tyBM * obj,
                                                    int rk,
                                                    const value_tyBM valcomp);
  static inline bool objdecayedvectorappendpayl_BM (objectval_tyBM * obj,
                                                    const value_tyBM valcomp);
///////////////////////////////

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
                             struct listtop_stBM *lis,
                             objectval_tyBM * fromob, int depth);
  extern void listgcdestroy_BM (struct garbcoll_stBM *gc,
                                struct listtop_stBM *lis);
  extern void listgckeep_BM (struct garbcoll_stBM *gc,
                             struct listtop_stBM *lis);
// make a node from all components of the list
  extern const node_tyBM *list_to_node_BM (const struct listtop_stBM *lis,
                                           const objectval_tyBM * conn);
// make a tuple from the objects in the list
  extern const tupleval_tyBM *list_to_tuple_BM (const struct listtop_stBM
                                                *lis);

//////////////// obj list payload

  extern bool objputlistpayl_BM (objectval_tyBM * obj);
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
                                  struct classinfo_stBM *clinf,
                                  objectval_tyBM * fromob, int depth);
  extern void classinfogcdestroy_BM (struct garbcoll_stBM *gc,
                                     struct classinfo_stBM *clinf);
  extern void classinfogckeep_BM (struct garbcoll_stBM *gc,
                                  struct classinfo_stBM *clinf);

////////////////////////////////
  extern struct dict_stBM *dictmake_BM (void);
  static inline bool isdict_BM (const value_tyBM v);
  extern unsigned dictsize_BM (const struct dict_stBM *dict);
  extern void dictgcmark_BM (struct garbcoll_stBM *gc, struct dict_stBM *dict,
                             objectval_tyBM * fromob, int depth);
  extern void dictgcdestroy_BM (struct garbcoll_stBM *gc,
                                struct dict_stBM *dict);
  extern void dictgckeep_BM (struct garbcoll_stBM *gc,
                             struct dict_stBM *dict);
  extern value_tyBM dictget_BM (const struct dict_stBM *dict,
                                const stringval_tyBM * str);
  extern void dictput_BM (struct dict_stBM *dict, const stringval_tyBM * str,
                          const value_tyBM val);
  extern void dictremove_BM (struct dict_stBM *dict,
                             const stringval_tyBM * str);
  extern const stringval_tyBM *dictfirstkey_BM (struct dict_stBM *dict);
  extern const stringval_tyBM *dictlastkey_BM (struct dict_stBM *dict);
  extern const stringval_tyBM *dictkeyafter_BM (struct dict_stBM *dict,
                                                const stringval_tyBM * str);
/// so iterate on a dict with
/// for (const stringval_tyBM* ks = dictfirstkey_BM(dict);
///      ks != NULL;
///      ks = dictkeyafter_BM(dict, ks) { dosomethingwith(ks) }
  extern const stringval_tyBM *dictkeysameorafter_BM (struct dict_stBM *dict,
                                                      const stringval_tyBM *
                                                      str);
  extern const stringval_tyBM *dictkeybefore_BM (struct dict_stBM *dict,
                                                 const stringval_tyBM * str);
  extern const node_tyBM *dictnodeofkeys_BM (struct dict_stBM *dict,
                                             const objectval_tyBM * obj);

//////////////// obj dict payload
  extern bool objputdictpayl_BM (objectval_tyBM * obj);
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
  static inline const stringval_tyBM *objdictfirstkeypayl_BM
    (objectval_tyBM * obj);
  static inline const stringval_tyBM *objdictlastkeypayl_BM
    (objectval_tyBM * obj);
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
                                   struct hashsetval_stBM *hsv,
                                   objectval_tyBM * fromob, int depth);
  extern void hashsetvbucketgcmark_BM (struct garbcoll_stBM *gc,
                                       struct hashsetvbucket_stBM *hvb,
                                       objectval_tyBM * fromob, int depth);
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
  extern struct hashsetval_stBM *hashsetvalreorganize_BM (struct
                                                          hashsetval_stBM
                                                          *hsv, unsigned gap);
  extern struct hashsetval_stBM *hashsetvalput_BM (struct hashsetval_stBM
                                                   *hsv, value_tyBM val);
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

  static inline bool objputhashsetvalpayl_BM (objectval_tyBM * obj,
                                              unsigned gap);
  static inline struct hashsetval_stBM
    *objgethashsetvalpayl_BM (objectval_tyBM * obj);
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
  static inline unsigned hashmapvalsize_BM (const value_tyBM v);
  extern void hashmapvalgcmark_BM (struct garbcoll_stBM *gc,
                                   struct hashmapval_stBM *hsv,
                                   objectval_tyBM * fromob, int depth);
  extern void hashmapbucketgcmark_BM (struct garbcoll_stBM *gc,
                                      struct hashmapbucket_stBM *hvb,
                                      objectval_tyBM * fromob, int depth);
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

//////////////// obj jansson JSON payload
  extern void jansjsongcmark_BM (struct garbcoll_stBM *gc,
                                 struct jansjson_stBM *jjs,
                                 objectval_tyBM * fromob, int depth);

  extern void jansjsongcdestroy_BM (struct garbcoll_stBM *gc,
                                    struct jansjson_stBM *jjs);

  extern void jansjsongckeep_BM (struct garbcoll_stBM *gc,
                                 struct jansjson_stBM *jjs);

  static inline bool objhasjansjsonpayl_BM (const objectval_tyBM * obj);
  static inline json_t *objgetjansjsonpayl_BM (const objectval_tyBM * obj);
  extern bool objputjansjsonpayl_BM (objectval_tyBM * obj, json_t * js);
  extern bool objputincrefjansjsonpayl_BM (objectval_tyBM * obj, json_t * js);
  extern bool objputjansjsoncstrpayl_BM (objectval_tyBM * obj,
                                         const char *cstr);
  extern json_t *jansjsonfromvalue_BM (value_tyBM val, value_tyBM src,
                                       value_tyBM ctx, int depth,
                                       struct stackframe_stBM *stkf);
  extern objectval_tyBM *  objkindjansjsonpayl_BM (const objectval_tyBM * obj);
// FIXME: we need to explain how json_sequence, json_set, json_tuple,
// jsonable_closure, jsonable_object are used.

/// gives null or {"@object": id}; if the object has a jsonable_object
/// which is not `none`
  extern json_t *jansjsonifyobject_BM (objectval_tyBM * obj,
                                       struct stackframe_stBM *stkf);

  extern json_t *jansjsonifynode_BM (value_tyBM val, value_tyBM src,
                                     value_tyBM ctx, int depth,
                                     struct stackframe_stBM *stkf);

  extern json_t *jansjsonifyclosure_BM (value_tyBM val, value_tyBM src,
                                        value_tyBM ctx, int depth,
                                        struct stackframe_stBM *stkf);

  extern json_t *jansjsonifyvalue_BM (value_tyBM val, value_tyBM src,
                                      value_tyBM ctx, int depth,
                                      struct stackframe_stBM *stkf);

  extern json_t *canonjsonifyvalue_BM (value_tyBM val,
                                       objectval_tyBM * ctxob, int depth,
                                       struct stackframe_stBM *stkf);

/// unimplemented, not even sure of the signature
  extern value_tyBM value_of_json_BM (json_t * json, value_tyBM src,
                                      value_tyBM ctx, int depth,
                                      struct stackframe_stBM *stkf);

  extern void objputjanssonpayl_BM (objectval_tyBM * objarg,
                                    value_tyBM valarg, value_tyBM ctxarg,
                                    struct stackframe_stBM *stkf);

//////////////// obj hashmapval payload 

  extern bool objputhashmapvalpayl_BM (objectval_tyBM * obj, unsigned gap);
  static inline struct hashmapval_stBM *objgethashmapvalpayl_BM
    (objectval_tyBM * obj);
  static inline bool objhashashmapvalpayl_BM (objectval_tyBM * obj);
  static inline unsigned objhashmapvalsizepayl_BM (objectval_tyBM * obj);

  static inline value_tyBM objhashmapvalgetpayl_BM (objectval_tyBM * obj,
                                                    value_tyBM keyv);
  static inline void objhashmapvalreorganizepayl_BM (objectval_tyBM * obj,
                                                     unsigned gap);
  static inline void objhashmapvalputpayl_BM (objectval_tyBM * obj,
                                              value_tyBM keyv,
                                              value_tyBM valv);
  static inline void objhashmapvalremovepayl_BM (objectval_tyBM * obj,
                                                 value_tyBM keyv);
  static inline value_tyBM objhashmapvalfirstkeypayl_BM (objectval_tyBM *
                                                         obj);
  static inline value_tyBM objhashmapvalnextkeypayl_BM (objectval_tyBM * obj,
                                                        value_tyBM prevk);
  static inline value_tyBM objhashmapvalmakenodeofkeyspayl_BM (objectval_tyBM
                                                               * obj,
                                                               objectval_tyBM
                                                               * connob);
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


// the argmore should be a tree: node, closure, or quasinode; it gives
// the rest of the arguments to apply.
  extern value_tyBM apply4more_BM (const value_tyBM funv,
                                   struct stackframe_stBM *stkf,
                                   const value_tyBM arg1,
                                   const value_tyBM arg2,
                                   const value_tyBM arg3,
                                   const value_tyBM arg4,
                                   const value_tyBM argmore);

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

  extern value_tyBM applyvar_BM (const value_tyBM funv, struct stackframe_stBM *stkf, unsigned nbargs,  // no more than MAXAPPLYARGS_BM
                                 const value_tyBM * argarr);

  extern value_tyBM applymany_BM (const value_tyBM funv,
                                  struct stackframe_stBM *stkf,
                                  unsigned nbargs, ...);

// send dump_value, making a buffer object, giving its byte contents
  extern const char *debug_outstr_value_BM (const value_tyBM val,
                                            struct stackframe_stBM *stkf,
                                            int curdepth);

////////////////
// fill `the_system` object with various `bismon_*` attributes
  extern void fill_the_system_with_bismon_BM (struct stackframe_stBM *stkf);
// forget in  `the_system` object the `bismon_*` attributes added above
  extern void forget_the_system_with_bismon_BM (struct stackframe_stBM *stkf);


/* If an object has no routine pointer, load it from existing modules
   or main program; return the dlsym-ed pointer; would be sometimes
   called by apply routines... */
  extern void* try_dlsym_routine_BM (objectval_tyBM* ob);
  /* find a routine using dlsym in loaded modules and in main program:*/
extern void*dlsym_in_modules_and_program_BM(const char*routname);


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
/// dumping should be done from the main thread
  extern struct dumpinfo_stBM dump_BM (const char *dirname,
                                       struct stackframe_stBM *stkf);


  extern void dumpgcmark_BM (struct garbcoll_stBM *gc, struct dumper_stBM *du,
                             objectval_tyBM * fromob);
  extern void dumpgcdestroy_BM (struct garbcoll_stBM *gc,
                                struct dumper_stBM *du);
  extern void dumpgckeep_BM (struct garbcoll_stBM *gc,
                             struct dumper_stBM *du);

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
  extern void obdumpscanvalue_BM (objectval_tyBM * dumpob,
                                  const value_tyBM val, int depth);

//// parsing
  extern const char *lexkindname_BM (enum parslexkind_enBM k);
  extern const char *delimstr_BM (enum lexdelim_enBM d);

  extern struct parser_stBM *makeparser_of_file_BM (FILE * f,
						    const char* path,
                                                    objectval_tyBM * owner);
  extern struct parser_stBM *makeparser_memopen_BM (const char *filemem,
                                                    long size,
                                                    objectval_tyBM * owner);
  static inline bool isparser_BM (const extendedval_tyBM v);
  static inline objectval_tyBM *parserowner_BM (const extendedval_tyBM v);
  static inline struct parser_stBM *objparserpayload_BM (objectval_tyBM *
                                                         obj);
  static inline objectval_tyBM *checkedparserowner_BM (const extendedval_tyBM
                                                       v);
  static inline struct parser_stBM *parsercast_BM (const value_tyBM v);
  extern void parsergcmark_BM (struct garbcoll_stBM *gc,
                               struct parser_stBM *pars,
                               objectval_tyBM * fromob);
  extern void parsergcdestroy_BM (struct garbcoll_stBM *gc,
                                  struct parser_stBM *pars);
  extern void parsergckeep_BM (struct garbcoll_stBM *gc,
                               struct parser_stBM *pars);
  extern bool parsernextline_BM (struct parser_stBM *pars);     // return false on EOF
/// test if a token can start an object
  extern bool parsertokenstartobject_BM (struct parser_stBM *pars,
                                         parstoken_tyBM tok);
// get the parsed object
  extern objectval_tyBM *parsergetobject_BM
    (struct parser_stBM *pars,
     struct stackframe_stBM *stkf, int depth, bool *pgotobj);

/// test if a token can start a value
  extern bool parsertokenstartvalue_BM (struct parser_stBM *pars,
                                        parstoken_tyBM tok);
/// get the parsed value
  extern value_tyBM parsergetvalue_BM
    (struct parser_stBM *pars,
     struct stackframe_stBM *stkf, int depth, bool *pgotval);

  extern value_tyBM parsergetchunk_BM
    (struct parser_stBM *pars,
     struct stackframe_stBM *stkf, int depth, bool *pgotchunk);

///
  static inline unsigned parserlineno_BM (const struct parser_stBM *pars);
  static inline unsigned parsercolpos_BM (const struct parser_stBM *pars);
  static inline const char *parserrestline_BM (const struct parser_stBM
                                               *pars);
  static inline gunichar parserunichar_BM (const struct parser_stBM *pars);
  static inline bool parsereol_BM (const struct parser_stBM *pars);
  static inline bool parserendoffile_BM (const struct parser_stBM *pars);
// advance nbc UTF8 characters on current line
  static inline bool parseradvanceutf8_BM (struct parser_stBM *pars,
                                           unsigned nbc);

  extern void parserseek_BM (struct parser_stBM *pars, unsigned line,
                             unsigned col);
  extern void parsererrorprintf_BM (struct parser_stBM *pars,
                                    struct stackframe_stBM *stkf,
                                    unsigned line, unsigned col,
                                    const char *fmt, ...)
    __attribute__((format (printf, 5, 6), noreturn));
  extern void objparserrorprintf_BM (objectval_tyBM * obpars,
                                     struct stackframe_stBM *stkf,
                                     unsigned line, unsigned col,
                                     const char *fmt, ...)
    __attribute__((format (printf, 5, 6), noreturn));
// skip spaces and comments
  extern void parserskipspaces_BM (struct parser_stBM *pars,
                                   struct stackframe_stBM *stkf);
  extern parstoken_tyBM parsertokenget_BM (struct parser_stBM *pars,
                                           struct stackframe_stBM *stkf);

// internal GC related routines

// used by VALUEGCPROC_BM macro
  extern void *valuegcproc_BM (struct garbcoll_stBM *gc, value_tyBM val,
                               int depth) __attribute__((warn_unused_result));
// used by EXTENDEDGCPROC_BM macro
  extern void *extendedgcproc_BM (struct garbcoll_stBM *gc,
                                  extendedval_tyBM xval,
                                  objectval_tyBM * fromob, int depth)
    __attribute__((warn_unused_result));

  extern void gcobjmark_BM (struct garbcoll_stBM *gc, objectval_tyBM * obj);
  extern void gcframemark_BM (struct garbcoll_stBM *gc,
                              struct stackframe_stBM *stkfram, int depth);
  extern void gctokenmark_BM (struct garbcoll_stBM *gc,
                              struct parstoken_stBM *tok);

/// the full garbage collector, to be called from the main thread
  extern void full_garbage_collection_BM (struct stackframe_stBM *stkf);
// conditional GC, to be called from the main thread
  static inline void garbage_collect_if_wanted_BM (struct stackframe_stBM
                                                   *stkf);
// request some GC in the future
  extern void request_delayed_garbage_collection_BM (void);
  // some GC has been requested but not yet done....
  extern bool wanting_garbage_collection_BM (void);
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
  extern const setval_tyBM *setofmatchednamedobjects_BM (const char
                                                         *fnmatcher);
// globals, see misc_BM.cc
  extern void initialize_globals_BM (void);
  extern objectval_tyBM **findglobalnamed_BM (const char *nam);
  extern bool forgetglobalnamed_BM (const char *nam);
// make a node with the global names
  extern const node_tyBM *nodeglobalnames_BM (const objectval_tyBM * conn);
// make a set with the global objects
  extern const setval_tyBM *setglobalobjects_BM (void);

  extern void gcmarkglobals_BM (struct garbcoll_stBM *gc);
  extern void gcmarkdefer_BM (struct garbcoll_stBM *gc);
  extern void gcmarkconstants_BM (struct garbcoll_stBM *gc);
  extern void gcmarkevloop_BM (struct garbcoll_stBM*gc);

/// open a module during loading, returns true if ok
  extern bool open_module_for_loader_BM (const rawid_tyBM modid,
                                         struct loader_stBM *ld,
                                         struct stackframe_stBM *stkf);
  extern unsigned module_count_BM(void);



/// simple module initialization
  extern value_tyBM simple_module_initialize_BM (const value_tyBM arg1, //
                                                 const value_tyBM arg2, //
                                                 const value_tyBM arg3, //
                                                 const char *modulid,   //
                                                 objectval_tyBM ** constobjarr, //
                                                 const char *const *constidarr, //
                                                 const char *const *routidarr,  //
                                                 void *dlh,     // dlopened handle
                                                 struct stackframe_stBM
                                                 *stkf);

  extern void gcmarkmodules_BM (struct garbcoll_stBM *gc);
  extern void gcmarkpostponed_BM (struct garbcoll_stBM *gc);

    value_tyBM
    run_postponed_node_BM (value_tyBM nodarg, struct stackframe_stBM *stkf);

// defer an application, running in the main thread
  void
    do_main_defer_apply3_BM (value_tyBM closv, value_tyBM arg1,
                             value_tyBM arg2, value_tyBM arg3,
                             struct stackframe_stBM *stkf);

// defer a message send, running in the main thread
  void
    do_main_defer_send3_BM (value_tyBM recv, objectval_tyBM * obsel,
                            value_tyBM arg1, value_tyBM arg2, value_tyBM arg3,
                            struct stackframe_stBM *stkf);


// postpone after a delay an application or a message send, running in
// postpone thread
  void
    do_postpone_defer_apply3_BM (int delaymillisec, value_tyBM closv,
                                 value_tyBM arg1, value_tyBM arg2,
                                 value_tyBM arg3,
                                 struct stackframe_stBM *stkf);

// defer a message send, running in the main thread
  void
    do_postpone_defer_send3_BM (int delaymillisec, value_tyBM recv,
                                objectval_tyBM * obsel, value_tyBM arg1,
                                value_tyBM arg2, value_tyBM arg3,
                                struct stackframe_stBM *stkf);

  value_tyBM get_newest_postpone_BM (double *pdelay,
                                     struct stackframe_stBM *stkf);
  value_tyBM pop_newest_postpone_BM (double *pdelay,
                                     struct stackframe_stBM *stkf);

  double timestamp_newest_postpone_BM (void);
////////////////////////////////////////////////////////////////
//**************************************************************
//**************************************************************
////////////////////////////////////////////////////////////////
  extern void
  fork_process_at_slot_BM (int slotpos,
			   const stringval_tyBM * dirstrarg,
			   const node_tyBM * cmdnodarg,
			   const closure_tyBM * endclosarg,
			   struct stackframe_stBM *stkf);
  /* lock/unlock some mutex related to running or runnable process. */
  extern void lock_runproc_mtx_at_BM (int lineno);
  extern void unlock_runproc_mtx_at_BM (int lineno);


////////////////

  extern void create_commandpipe_BM(void);
  extern void plain_event_loop_BM (void);
  extern void stop_event_loop_BM (void);
  
  extern void add_defer_command_BM (void);
  extern void add_rungarbcoll_command_BM (void);
  extern void stop_unix_json_socket_processing_BM(void);
  extern void initialize_unix_json_socket_processing_BM (const char *ujsname);



// given a decayed object, returns the string value of the URL for forgotten password
  extern
    value_tyBM
    forgotpasswd_urlstring_BM (objectval_tyBM * decayforgotarg,
                               struct stackframe_stBM *stkf);
////////////////////////////////////////////////////////////////
// user data support - in scalar_BM.c
/// user in GC
  extern void usergcmark_BM (struct garbcoll_stBM *gc,
                             struct user_stBM *us,
                             objectval_tyBM * fromob, int depth);
  extern void usergcdestroy_BM (struct garbcoll_stBM *gc,
                                struct user_stBM *us);
  extern void usergckeep_BM (struct garbcoll_stBM *gc, struct user_stBM *us);
// payload delete support for user
  extern void userdelete_BM (objectval_tyBM * ownobj, struct user_stBM *us);

// the error message is asprintf-ed into perrmsg when perrmsg is not null
  extern objectval_tyBM *add_contributor_user_BM
    (const char *str, char **perrmsg, struct stackframe_stBM *stkf);
  extern objectval_tyBM *remove_contributor_by_name_BM  // callable only from main!
    (const char *str, struct stackframe_stBM *stkf);
  extern bool valid_email_BM (const char *email, bool checkdns,
                              char **perrmsg);
  extern bool valid_contributor_name_BM (const char *name, char **perrmsg);
  extern bool valid_password_BM (const char *name, char **perrmsg);

// check then load the contributors (and password) files at startup, during the load
  extern void check_and_load_contributors_file_BM (struct loader_stBM *ld,
                                                   struct stackframe_stBM
                                                   *stkf);

  extern void check_passwords_file_BM (struct loader_stBM *ld,
                                       struct stackframe_stBM *stkf);

  extern bool
    check_contributor_password_BM (objectval_tyBM * contribobarg,
                                   const char *passwd,
                                   struct stackframe_stBM *stkf);
  extern bool
    put_contributor_password_BM (objectval_tyBM * contribobarg,
                                 const char *passwd,
                                 struct stackframe_stBM *stkf);

// find an existing contributor by his/her name or primary email by
// parsing the contributors file. Returns NULL if that does not exist.
// secondary emails are ignored.

  objectval_tyBM *find_contributor_BM (const char *str,
                                       struct stackframe_stBM *stkf);

// the only operations doable on user objects after load since adding
// contributors is only possible on the command line!
  static inline bool objhascontributorpayl_BM (const objectval_tyBM * obj);
  const stringval_tyBM *objcontributornamepayl_BM (const objectval_tyBM *
                                                   obj);
  const stringval_tyBM *objcontributoremailpayl_BM (const objectval_tyBM *
                                                    obj);

// for the --print-contributor-of-oid option
  extern void tabular_print_contributor_of_objid_BM (const char *oidstr);

  extern void
    send_html_email_to_contributor_BM (const char *subject,
                                       const char *htmlbody,
                                       const char *attachment,
                                       objectval_tyBM * contribobarg,
                                       struct stackframe_stBM *stkf);
////////////////////////////////////////////////////////////////
// defer a dump (after a GC) while the agenda is running. Once dump is
// completed, the closure is called on the arg1v, arg2v, arg3v, and a
// node summarizing the dumpinfo....
  void defer_dump_BM (const char *dirname, const closure_tyBM * postclosv,
                      value_tyBM * arg1v, value_tyBM * arg2v,
                      value_tyBM * arg3v, struct stackframe_stBM *stkf);

// defer a module dynamic-load (after a GC) while the agenda is running. the 3
// arguments are passed to the module initialization. Its result is
// given to the closure.
  void defer_module_dynload_BM (objectval_tyBM * modulob, const closure_tyBM * postclosv,       //
                                value_tyBM arg1v,
                                value_tyBM arg2v, value_tyBM arg3v,
                                struct stackframe_stBM *stkf);
////////////////////////////////////////////////////////////////
// Since we generate C code, we need to run external processes to
// compile them in dlopen(3)-ed plugins....  We could also need to run
// other external processes (e.g. GNU indent, mailer user agents,
// etc...).
/////
// The queue_process_BM routine queue some external command, a bit
// like the batch(1) Linux utility; when running in some process, its
// stdin is /dev/null; both stdout & stderr are merged & captured in
// some output string...; That final string is given to the closure.
// dirstrv is the string of the directory to run it in (if NULL, use
// cwd) cmdnodv is a node with all sons being strings, for the command
// to run. And the closure endclosv is the closure getting the status
// and some stringoutput, could fail.  Several command processes could
// run in parallel, taking advantage of some multi-core processor.
  extern void queue_process_BM (const stringval_tyBM * dirstr,
                                const node_tyBM * cmdnodv,
                                const closure_tyBM * endclosv,
                                struct stackframe_stBM *stkf);

  extern void log_begin_message_BM (void) __attribute__((deprecated));
  extern void log_object_message_BM (const objectval_tyBM * obj) __attribute__((deprecated));
  extern void log_puts_message_BM (const char *msg) __attribute__((deprecated));
  extern void log_printf_message_BM (const char *fmt, ...)
    __attribute__((deprecated, format (printf, 1, 2)));
  extern void log_end_message_BM (void) __attribute__((deprecated));






////////////////////////////////////////////////////////////////

/******** agenda functions ***********/
  extern void initialize_agenda_BM (void);
  extern void agenda_notify_BM (void);
  extern void agenda_wait_gc_BM (void);
  extern bool agenda_need_gc_BM (void);
  extern int agenda_nb_work_jobs_BM (void);
  extern void gcmarkagenda_BM (struct garbcoll_stBM *gc);
  extern void start_agenda_work_threads_BM (int nbjobs);
  extern void stop_agenda_work_threads_BM (void);
// inside the GC, wait for all work thread to idle for garbage collection
  extern void agenda_suspend_for_gc_BM (void);
  extern void agenda_run_deferred_after_gc_BM (void);
  extern void agenda_defer_after_gc_BM (deferredaftergc_sigBM * rout,
                                        value_tyBM * valarr,
                                        unsigned nbval, void *data);
  extern void agenda_continue_after_gc_BM (void);
  extern void agenda_add_very_high_priority_tasklet_BM (objectval_tyBM *);
  extern void agenda_add_high_priority_tasklet_BM (objectval_tyBM *);
  extern void agenda_add_normal_priority_tasklet_BM (objectval_tyBM *);
  extern void agenda_add_low_priority_tasklet_BM (objectval_tyBM *);
  extern void agenda_add_very_low_priority_tasklet_BM (objectval_tyBM *);
  extern bool agenda_remove_tasklet_BM (objectval_tyBM *);
  extern bool agenda_has_tasklet_BM (objectval_tyBM *);
// return total number of tasklets
  extern long agenda_get_counts_BM (long *pveryhigh, long *phigh,
                                    long *pnormal, long *plow,
                                    long *pverylow);
  extern long agenda_get_sets_BM (value_tyBM * pveryhighset,
                                  value_tyBM * phighset,
                                  value_tyBM * pnormset, value_tyBM * plowset,
                                  value_tyBM * pverylowset);


/// C code generation see gencode_BM.c
// return the ctype of a variable
  extern objectval_tyBM *miniscan_var_BM (objectval_tyBM * varob,
                                          objectval_tyBM * routprepob,
                                          int depth, objectval_tyBM * fromob,
                                          struct stackframe_stBM *stkf);
// return the ctype of an expression
  extern objectval_tyBM *miniscan_expr_BM (value_tyBM expv,
                                           objectval_tyBM * routprepob,
                                           int depth, objectval_tyBM * fromob,
                                           struct stackframe_stBM *stkf);

// test if two types are compatible and return their common supertype
  extern objectval_tyBM *miniscan_compatype_BM (objectval_tyBM * typ1ob,
                                                objectval_tyBM * typ2ob,
                                                struct stackframe_stBM *stkf);

  extern void miniemit_expression_BM (struct stackframe_stBM *stkf,
                                      value_tyBM expv,
                                      objectval_tyBM * modgenob,
                                      objectval_tyBM * routprepob,
                                      objectval_tyBM * fromob, int depth);

// emit magic variables $stmtid $modulid $routid or else return false
  extern bool miniemit_magic_variable_BM (struct stackframe_stBM *stkf,
                                          objectval_tyBM * varob,
                                          objectval_tyBM * modgenob,
                                          objectval_tyBM * routprepob,
                                          objectval_tyBM * fromob, int depth);

  extern void miniemit_var_BM (struct stackframe_stBM *stkf,
                               objectval_tyBM * refob,
                               objectval_tyBM * modgenob,
                               objectval_tyBM * routprepob,
                               objectval_tyBM * fromob, int depth);

#ifdef __cplusplus
};                              /* end extern "C" */
#endif /*__cplusplus*/


#endif /*FUNDECL_BM_INCLUDED */
