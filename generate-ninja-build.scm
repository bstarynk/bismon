#!/usr/bin/env guile
;; a GPLv3+ licensed Guile script from http://github.com/bstarynk/bismon
;; file generate-ninja-build.scm is generating the build.ninja file
;; in replacement of generate-ninja-builder.sh
;; 
;;    BISMON 
;;   Copyright © 2019 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
;;   contributed by Basile Starynkevitch.
;;
;;   This program is free software: you can redistribute it and/or modify
;;   it under the terms of the GNU General Public License as published by
;;   the Free Software Foundation, either version 3 of the License, or
;;   (at your option) any later version.
;;
;;   This program is distributed in the hope that it will be useful,
;;   but WITHOUT ANY WARRANTY; without even the implied warranty of
;;   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;;   GNU General Public License for more details.
;;
;;   You should have received a copy of the GNU General Public License
;;   along with this program.  If not, see <http://www.gnu.org/licenses/>.
;;
;;---
;;   Contact me (Basile Starynkevitch) by email
;;   basile@starynkevitch.net and/or basile.starynkevitch@cea.fr
;; for http://ninja-build.org/ (i.e. Debian ninja-build package)
!#     ;; this is ending a block comment
;;;###############################################################
(use-modules
 ;; see https://www.gnu.org/software/guile/manual/html_node/Modules.html
 ;;;
 ;;; posix is not a module, https://stackoverflow.com/a/57040696/841108
 ;;; https://www.gnu.org/software/guile/manual/html_node/POSIX.html
 ;;;
 (ice-9 readline)
 ;;;
 ;; https://www.gnu.org/software/guile/manual/html_node/Formatted-Output.html ::
 (ice-9 format)
 ;;;
 (ice-9 pretty-print)
 ;;;
 ;; https://www.gnu.org/software/guile/manual/html_node/File-Tree-Walk.html
 (ice-9 ftw)
 ;;;
 ;;;
 ;; https://www.gnu.org/software/guile/manual/html_node/Textual-I_002fO.html
 (ice-9 textual-ports)
 ;;;
 ;; https://www.gnu.org/software/guile/manual/html_node/Pipes.html
 (ice-9 popen)
  ;;;
 ;; https://www.gnu.org/software/guile/docs/master/guile.html/Line_002fDelimited.html
 (ice-9 rdelim)
 ;;
 ;; https://www.gnu.org/software/guile/manual/html_node/SRFI_002d1-Searching.html#index-every
 (srfi srfi-1)
 )


;;; convention: public Guile names start with bm-
;;; and private Guile names might end with -BM

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;; functions
;; collect in the current directory the list of files with the given suffix
(define (files-ending-with-BM suffixstr)
  (let ( (suffixlen (string-length suffixstr))
	 )
    (let ( (is-good-path
	    (lambda (filpath)
	      (let ( (filpathlen (string-length filpath))
		     )
		(and (> filpathlen suffixlen)
		     (let* (  (endstr (substring filpath
						 (- filpathlen suffixlen)
						 filpathlen))
			      (good?
			       (string=? suffixstr endstr))
			      )
		       ;; (format #t "is-good-path ~s endstr ~s: good? ~a ... ~%"
		       ;;       filpath endstr good?)
		       good?
		       )
		     )
		)
	      )
	    )
	   )
      (scandir "."
	       is-good-path
	       ))
    ))					;end files-ending-with-BM



;; from some given list of files, remove those not starting with a letter
(define (filter-files-starting-alpha-BM listfiles)
  (filter (lambda (filpath)
	    (and (> (string-length filpath) 1)
		 (char-alphabetic? (string-ref filpath 0)))
	    )
	  listfiles)
  )					;end filter-files-starting-alpha-BM



;; do a thunk with input from a popen command
(define (with-input-popen-BM cmdstr thunk)
  (let ( (cmdport (open-input-pipe cmdstr))
	 )
    (and (port? cmdport)
	 (procedure? thunk)
	 (let ( (res (thunk cmdport))
		)
	   (if res
	       (let (
		     (clostat (close-pipe cmdport))
		     )
		 (let ( (cloex (status:exit-val clostat))
			(signum #f)
			)
		   (cond ((> cloex 0)
			  (format (current-error-port)
				  "failed popen ~s got error code ~a~%" cmdstr cloex)
			  #f)
			 ((eq? cloex 0)
			  res)
			 ( (let ( (termsig (status:term-sig clostat))
				  )
			     (and termsig (set! signum termsig) #t))
			   (format (current-error-port)
				   "failed popen ~s got terminating signal ~a~%" cmdstr signum)
			   #f
			   )
			 ( (let ( (stopsig (status:stop-sig clostat))
				  )
			     (and stopsig (set! signum stopsig) #t))
			   (format (current-error-port)
				   "failed popen ~s got stopping signal ~a~%" cmdstr signum)
			   #f
			   )
			 )
		   )
		 res))))
    ))					;end with-input-popen-BM


(define (input-popen-first-line-BM cmdstr)
  (let ( (linstr #f)
	 )
    (with-input-popen-BM
     cmdstr
     (lambda (pipeport)
       (set! linstr (read-line pipeport))
       linstr
       ))))				;end input-popen-first-line-BM

;;;;;;;;;;;;;;;; constants
(define bm-packages '("glib-2.0" "jansson" "gtk+-3.0"))
(define bm-gcc "gcc")
(define bm-g++ "g++")
(define bm-pkgconfig "pkg-config")
(define bm-cfiles
  (filter-files-starting-alpha-BM (files-ending-with-BM "BM.c")))
(define bm-cxxfiles
  (filter-files-starting-alpha-BM (files-ending-with-BM "BM.cc")))
(define bm-webtemplates
  (filter-files-starting-alpha-BM (files-ending-with-BM "BM.thtml")))

(format #t "## DONT EDIT this build.ninja file ; it was generated ...~%")
(format #t "## ... at ~a by generate-ninja-build.scm ~%~%"
	(strftime "%c" (localtime (current-time))))
(format #t "ninja_required_version = 1.8~%~%")
(format #t "#; bm-cfiles::: ~a~%" bm-cfiles)
(format #t "#; bm-cxxfiles::: ~a~%" bm-cxxfiles)
(format #t "#; bm-webtemplates::: ~a~%" bm-webtemplates)

(let ( (cflagslist (list))
       (libslist (list))
       )
  (for-each
   (lambda (curpkg)
     (format #t "#; curpkg::: ~a~%" curpkg)
     (let ( (testcmd (format #f "~a ~a" bm-pkgconfig curpkg))
	    (cflagcmd (format #f "~a --cflags ~a" bm-pkgconfig curpkg))
	    (libescmd (format #f "~a --libs ~a" bm-pkgconfig curpkg))
	    )
       (format #t "##; testcmd ~s cflagcmd ~s libescmd ~s~%" testcmd cflagcmd libescmd)
       (and (with-input-popen-BM testcmd
				 (lambda (piport)
				   #t))
	    (let* (
		   (cflagstr (input-popen-first-line-BM cflagcmd))
		   (libestr (input-popen-first-line-BM libescmd))
		   )
	      (format #t "##; curpkg ~s, cflagstr ~s, libestr ~s ~%" curpkg cflagstr libestr)
	      (set! cflagslist (append cflagslist (list cflagstr)))
	      (set! libslist (append libslist (list libestr)))
	      )
	    )
       )
     )
   bm-packages)
  (format #t "#; cflagslist ~a;~%#; libslist ~a;~%~%" cflagslist libslist)
  (format #t "~%pkg_cflags = ")
  (for-each (lambda (curcflag) (format #t " ~a" curcflag)) cflagslist)
  (format #t "~%")
  (format #t "~%pkg_libes = ")
  (for-each (lambda (curlib) (format #t " ~a" curlib)) libslist)
  (format #t "~%~%")
  )

(format #t "~%~%###### our compilers and their flags ######~%")
(format #t "cc = ~a~%" bm-gcc)
(format #t "cxx = ~a~%" bm-g++)
(format #t "bm_commonwarnflags =  -Wall -Wextra -Wstack-usage=2048 -fdiagnostics-color=auto~%")
(format #t "cwarnflags = $bm_commonwarnflags -Wmissing-prototypes~%")
(format #t "cxxwarnflags = $bm_commonwarnflags~%")
(format #t "defpreproflags = -DBISMONION -DBISMONGTK  -DGDK_DISABLE_DEPRECATED -DGTK_DISABLE_DEPRECATED~%")
(format #t "incflags = -I. -I/usr/local/include~%")
(let ( (envoptim (getenv "OPTIMFLAGS"))
       (envbmopt (getenv "BISMON_OPTIMFLAGS"))
       )
  (cond
   (envoptim
    (format #t "optimflags = -DBISMON_WITH_OPTIMFLAGS ~a~%" envoptim))
   (envbmopt
    (format #t "optimflags = -DBISMON_HAS_OPTIMFLAGS ~a~%" envbmopt))
   (else
    (format #t "optimflags = -DBISMON_DEFAULT_OPTIMFLAGS -O1 -g3~%"))
   ))

(format #t "cflags = $cwarnflags $defpreproflags $incflags $optimflags $pkg_cflags~%")
(format #t "cxxflags = $cxxwarnflags $defpreproflags $incflags $optimflags $pkg_cflags~%")

(format #t "~%~%#for web template files *.thtml related to onion otemplate generator~%")
(format #t "otemplate = otemplate~%~%~%")

(format #t "#our link flags for bismon ~%")
(format #t "bm_ldflags = -L/usr/local/lib -rdynamic -pthread~%~%")
(format #t "#our libraries for bismon ~%")
(format #t "bm_libs =  -lonion -lbacktrace $pkg_libes -lcrypt -ldl -lm~%~%")

(let ( (bmheaderslist (filter-files-starting-alpha-BM  (files-ending-with-BM "BM.h")))
       )
  (format #t "~%# handwritten C/C++ headers:~%bm_headers = bismon.h ")
  (for-each (lambda (curh) (format #t " ~a" curh))
	    bmheaderslist)
  (format #t " $~%~%")
  )

(let ( (bmtemplist  bm-webtemplates)
       )
  (format #t "~%# handwritten web templates for onion~%bm_webtemplates = ")
  (for-each (lambda (curt) (format #t " ~a" curt))
	    bmtemplist)
  (format #t " $~%~%")
  )

(let ( (allh (files-ending-with-BM ".h"))
       )
  (format #t "~%# generated persistent headers~%bm_generated_headers = ")
  (for-each (lambda (curh)
	      (if (string=? (string-take curh 3) "_bm")
		  (format #t " ~a" curh))
	      )
	    allh)
  (format #t " $~%~%"))

(format #t "~%~%######## RULES for ninja~%~%")
(format #t "~%~%# compile a C file into an object file~%")
(format #t "rule CC_r~%")
(format #t "  command = $cc -MMD -MT $out -MF $out.mkd $cflags -c $in -o $out~%")
(format #t "  description = CC $out~%")
(format #t "  depfile = $out.mkd~%")
(format #t "  deps = gcc~%")

(format #t "~%~%# compile a naked C file into an object file~%")
(format #t "rule NAKEDCC_r~%")
(format #t "  command = $cc  -Wall -g -O -o $out -c $in~%")
(format #t "  description = NAKEDCC $out~%")

(format #t "~%~%# compile a C++ file into an object file~%")
(format #t "rule CXX_r~%")
(format #t "  command = $cxx -MMD -MT $out -MF $out.mkd $cflags -c $in -o $out~%")
(format #t "  description = CXX $out~%")
(format #t "  depfile = $out.mkd~%")
(format #t "  deps = gcc~%")

(format #t "~%~%# compile a selfsufficient C++ program with Glib & id_BM.o~%")
(format #t "rule SOLOCXXPROG_r~%")
(format #t "  command = $cxx -MMD -MT $out -MF $out.mkd $cflags -c $in -o $out id_BM.o $pkg_libes~%")
(format #t "  description = SOLOCXXPROG $out~%")


(format #t "~%~%# make a XXX_BM.const.h header with constants in XXX_BM.c~%")
(format #t "rule BMCONSTH_r~%")
(format #t "  command = ./BM_makeconst -H $out $in~%")
(format #t "  description = BMCONSTH $out~%")


(format #t "~%~%# make _XXX_ONIONBM.c & _XXX_ONIONBM.h from web template XXX_ONIONBM.thtml~%")
(format #t "rule OTEMPLATE_r~%")
(format #t "  command = $otemplate -a $out_h $in_thtml $out_c~%")
(format #t "  description = OTEMPLATE asset $out_h code $out_c template $in_thtml~%")


(format #t "~%~%# make the _bm_allconsts.c file~%")
(format #t "rule BMALLCONSTSC_r~%")
(format #t "  command = ./BM_makeconst -C $out $in~%")
(format #t "  description = BMALLCONSTSC $out~%")


(format #t "~%~%# link the entire bismon program~%")
(format #t "rule LINKALLBISMON_r~%")
(format #t "  command =  $cxx  $cxxwarnflags  $incflags $optimflags $in $bm_ldflags $bm_libs -o $out && mv -vf __timestamp.c __timestamp.c~~ && rm __timestamp.o ~%")
(format #t "  description = LINKALLBISMON $out~%")


(format #t "~%~%# timestamp the bismon program~%")
(format #t "rule TIMESTAMP_r~%")
(format #t "  command = ./timestamp-emit.sh $in~%")
(format #t "  description = TIMESTAMP $out~%")

(format #t "~%~%# cflags for modules~%")
(format #t "rule CFLAGSMODULE_r~%")
(format #t "  command =  (printf '#generated %s file from %s'\\nBISMONMODULECFLAGS = %s\\nBISMONHEADERS = %s\\n\"  $out $in \"$cflags\" \"$bm_headers $bm_generatedheaders\"; date +\"#generated %c%n\") > $out' ~%")
(format #t "  description = CFLAGSMODULE $out~%")


(format #t "~%~%# reconfiguration ~%")
(format #t "rule CONFIG_r~%")
(format #t "  command =./generate-ninja-build.scm > $out.tmp ; mv -v --backup $out.tmp $out ~%")
(format #t "  description = CONFIG $out~%")

(format #t "~%~%# BUILD ninja statements ~%")

(define bm-constfiles-list #f)
(format #t "~%~%# hand-written C files: ~%")
(let ( (basetemplist (map
		      (lambda (curtempl)  (basename curtempl ".thtml"))
		      bm-webtemplates))
       (htblconstfiles (make-hash-table
			(+ 10 (length bm-webtemplates) (length bm-cfiles) (length bm-cxxfiles))))
       )
  (format #t "#; basetemplist ~a bm-cfiles ~a ~%" basetemplist bm-cfiles)
  (for-each
   (lambda (curcf)
     (let* ( (curbasnam (basename curcf ".c"))
	     (curconstf (format #f "~a.const.h" curbasnam))
	     (occlin #f)
	     (curevlistempbase (list))
	     )
       ;; (format #t "#; curcf= ~a; curbasnam ~a; curconstf ~a ~%"
       ;;	     curcf curbasnam curconstf)
       (call-with-input-file curcf
	 (lambda (inp)
	   (letrec ( (loopread
		      (lambda (cnt)
			(if (> cnt 100)
			    #f
			    (let ( (curlin (get-line inp) )
				   )
			      (cond ( (not (string? curlin))
				      #f)
				    ( (string-contains curlin curconstf)
				      (hashq-set! htblconstfiles curconstf curconstf)
				      (set! occlin cnt)
				      )
				    ( (any (lambda (curtempbase)
					     (and (string-contains curlin curtempbase)
						  (begin (set! curevlistempbase (cons curtempbase curevlistempbase))
							 ;; (format #t "#; curlin ~a curtempbase ~a~%" curlin curtempbase)
							 #t)
						  )
					     )
					   basetemplist)
				      )
				    )
			      (loopread (+ cnt 1))
			      )
			    )
			)
		      )
		     )
	     (set! occlin (loopread 0))
	     )
	   )
	 #:guess-encoding #f		;dont guess encoding
	 #:encoding "UTF-8"		;force input encoding
	 )
       ;; (format #t "#; curcf ~a; occlin ~a curconstf ~s curevlistempbase ~a ~%" curcf occlin curconstf curevlistempbase)
       (format #t "~%build ~a.o: CC_r ~a" curbasnam curcf)
       (cond (occlin
	      (format #t " | ~a" curconstf))
	     ((pair? curevlistempbase)
	      (format #t " |  ")
	      ))
       (for-each
	(lambda (curtempbase)
	  (format #t " _~a.h" curtempbase))
	(reverse curevlistempbase))
       )
     (format #t "~%~%")
     )
   bm-cfiles)
  (let ( (rawconstfilist '())
	 )
    (hash-for-each
     (lambda (key val) (set! rawconstfilist (cons key rawconstfilist)))
     htblconstfiles)
    (format #t "#; rawconstfilist ~a ~%" rawconstfilist)
    (if (pair? rawconstfilist)
	(set!  bm-constfiles-list (sort-list rawconstfilist string<)))
    (format #t "#; bm-constfiles-list ~a ~%" bm-constfiles-list)
    )
  )

;;; the hand-written C++ files
(format #t "~%~%# hand-written C++ files: ~%")
(for-each
 (lambda (curcxxf)
   (format #t "~%build ~a.o: CXX_r ~a~%"
	   (basename curcxxf ".cc")
	   curcxxf))
 bm-cxxfiles)



;;; the BM_makeconst metaprogram
(format #t "~%~%#solo C++ program to deal with BISMON constants~%")
(format #t "build BM_makeconst: SOLOCXXPROG_r BM_makeconst.cc | id_BM.o~%~%")


;; the generated constant headers
(format #t "~%~%#generated constant header files~%")
(for-each
 (lambda (curconstfil)
   (format #t "build ~a: BMCONSTH_r ~a.c | BM_makeconst ~%"
	   curconstfil (basename curconstfil ".const.h"))
   )
 bm-constfiles-list)


;; the single generated all-constants file
(format #t "~%~%#generated all constants summary C file and corresponding object file~%")
(format #t "build _bm_allconsts.c: BMALLCONSTSC_r ")
(for-each
 (lambda (curconstfil)
   (format #t " ~a.c" (basename curconstfil ".const.h")))
 bm-constfiles-list)
(format #t " | BM_makeconst~%")
(format #t "build _bm_allconsts.o: NAKEDCC_r _bm_allconsts.c~%")

;; the web templates
(format #t "~%~%# web templates for onion~%")
(for-each
 (lambda (curtempl)
   (format #t "~%#; curtempl ~a ~%" curtempl)
   (let ( (curtempbas (basename curtempl ".thtml"))
	  )
     (format #t "~%build _~a.c _~a.h : OTEMPLATE_r ~a~%"
	     curtempbas curtempbas curtempl)
     (format #t "  in_thtml = ~a~%" curtempl)
     (format #t "  out_h = _~a.h~%" curtempbas)
     (format #t "  out_c = _~a.c~%" curtempbas)
     (format #t "~%build  _~a.o: CC_r _~a.c~%" curtempbas curtempbas)
   ))
 bm-webtemplates)


(format #t "~%~%# build of the bismon server program~%")
(format #t "build bismon: LINKALLBISMON_r __timestamp.o _bm_allconsts.o $~% ")

(for-each
 (lambda (curcsrc)
   (format #t " ~a.o" (basename curcsrc ".c"))
   )
 bm-cfiles)
(format #t " $~% ")
(for-each
 (lambda (curcxsrc)
   (format #t " ~a.o" (basename curcxsrc ".cc"))
   )
 bm-cxxfiles)
(format #t " $~% ")
(for-each
 (lambda (curtempl)
   (format #t " _~a.o" (basename curtempl ".thtml")))
 bm-webtemplates)
(format #t "~%~%# build of the cflags for make-ing modules~%")
(format #t "build _cflagsmodule.mk: CFLAGSMODULE_r build.ninja~%")
(format #t "~%~%# build the timestamp and its object file~%")
(format #t "build __timestamp.c: TIMESTAMP_r ")
(for-each 
 (lambda (curcsrc)   (format #t " ~a" curcsrc))
 bm-cfiles)
(format #t " $~% ")
(for-each 
 (lambda (curcxxsrc)   (format #t " ~a" curcxxsrc))
 bm-cxxfiles)
(format #t " $~% ")
(for-each 
 (lambda (curwtempl)   (format #t " ~a" curwtempl))
 bm-webtemplates)
(format #t "~%build __timestamp.o: NAKEDCC_r __timestamp.c~%")

(format #t "~%~%#### default build~%")
(format #t "default bismon _cflagsmodule.mk~%")
(format #t "~%#==================================================~%")


(format #t "~%~%###### for Emacs ~%")
(format #t "## Local ~a: ;;~%" "variables")
(format #t "## mode-name: ~s ;;~%" "ninja-mode")
(format #t "## compile-command: ~s ;;~%" "ninja")
(format #t "## End: ~a ~%" ";;")
(format #t "########### end of generated build.ninja by generate-ninja-build.scm~%~%")


;;;;;;;;;;;;;;;;
;; possible test command:
;;; ./generate-ninja-build.scm > /tmp/guile-ninjabismon; ninja -f /tmp/guile-ninjabismon
;;;;;;;;;;;;;;;;;;;

;; ================================================================
;; ---------------- end of file generate-ninja-build.scm ----------
