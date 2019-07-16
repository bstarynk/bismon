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
  )


;;; convention: public Guile names start with bm-
;;; and private Guile names might end with -BM

;;;;;;;;;;;;;;;; constants
(define bm-packages '("glib-2.0" "jansson" "gtk+-3.0"))
(define bm-gcc "gcc")
(define bm-g++ "g++")

(format #t "*** file tree **** ~%")
(pretty-print
 (file-system-tree "."
		   (lambda (filnam filstat)
		     (format #t "filnam=~s filstat=~a~%"
			     filnam filstat)
		     (eq? "." filnam))))


(format #t "~%*** scandir **** ~%")
(pretty-print
 (scandir "."))
;; ================================================================
;; ================================================================
;; ---------------- end of file generate-ninja-build.scm ----------
