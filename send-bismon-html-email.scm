#!/usr/bin/guile --debug
;; file send-bismon-html-email.scm -*- scheme -*-
;; GPLv3+ licensed, see http://github.com/bstarynk/bismon/
;; invocation: send-bismon-html-email.scm <subject> <contributor-oid> [<attached-file>]
;; the stdin being the HTML body of the message
;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
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
!#     ;; this is ending a block comment
;;;###############################################################


(use-modules
 ;; see https://www.gnu.org/software/guile/manual/html_node/Modules.html
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
 ;; https://www.gnu.org/software/guile/manual/html_node/Textual-I_002fO.html
 (ice-9 textual-ports)
 ;;;
 ;; https://www.gnu.org/software/guile/manual/html_node/Pipes.html
 (ice-9 popen)
  ;;;
 ;; https://www.gnu.org/software/guile/docs/master/guile.html/Line_002fDelimited.html
 (ice-9 rdelim)
 )

(define bm-script-arglist (command-line))
(format #t "#; bm-script-arglist::: ~a~%" bm-script-arglist)

(define bm-subject (cadr bm-script-arglist))
(format #t "#; bm-subject::: ~a~%" bm-subject)

(define bm-contributor-oid (caddr bm-script-arglist))
(format #t "#; bm-contributor-oid::: ~a~%" bm-contributor-oid)

(define bm-attachment (and (pair? (cdddr bm-script-arglist))
			   (cadddr bm-script-arglist)))
(format #t "#; bm-attachement::: ~a~%" bm-attachment)

(define bm-body #f)

(define bm-send-email? #t)

(define bm-email-to #f)

(call-with-input-file
    "/dev/stdin"
  (lambda (inp)
    (format #t "#; stdin inp ~a~%" inp)
    (let ( (bodylist (list))
	   )
      (format #t "#; bodylist ~a~%" bodylist)
      (letrec (
	       (lincount 0)
	       (readloop
		(lambda ()
		  (let ( (curlin (get-line (current-input-port)) )
			 )
		    (set! lincount (+ lincount 1))
		    (format #t "#; lincount ~a; curlin ~s~%"
			    lincount curlin)
		    (cond ( (eof-object? curlin)
			    bodylist)
			  (else 
			   (set! bodylist (append bodylist (list curlin)))
			   (readloop)))
		    )
		  )
		)
	       )
	(format #t "#; readloop ~a~%" readloop)
	(set! bm-body (readloop))
	(format #t "#; bm-body becomes ~a~%" bm-body)
	)
      )
    )
  #:guess-encoding #f 					;dont guess encoding
  #:encoding "UTF-8" 				;force input encoding
  )
(format #t "#; bm-body::: ~a~%" bm-body)

;; should load ~/.bismon-mail.scm if it exists
(let ( (configsrcpath (format #f "~a/.bismon-mail.scm" (getenv "HOME")))
       )
  (format #t "; configsrcpath= ~a~%" configsrcpath)
  (cond ( (access? configsrcpath R_OK)
	  (format #t "; loading accessible configsrcpath= ~a ....~%"
		  configsrcpath)
	  (load configsrcpath))
	(else
	 (format #t "; inaccessible configsrcpath= ~a~%" configsrcpath)
	 )))


;; use "./bismon --print-contributor-of-oid=<oid>" command since it
;; would output with separating tabs, the (name, oid, email, alias)
;; tuple...
(let ( (cmdstr (format #f "./bismon --print-contributor-of-oid=~a"
		       bm-contributor-oid))
       )
  (format #t ";; cmdstr= ~s~%" cmdstr)
  (let* ( (contribcmdport (open-input-pipe cmdstr))
	  (contribstr (read-line contribcmdport))
	  )
    (format #t ";; contribcmdport= ~a contribstr= ~s~%"
	    contribcmdport contribstr)
    (let ( (closecontrib (close-pipe contribcmdport))
	   )
      (format #t ";; closecontrib ~a~%" closecontrib)
      )
    )
  )


;; should add debug, etc...



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; how to test this script?
;;;;;;;; without attachment
;;; ./send-bismon-html-email.scm test-subject _6UYrSn7piPM_3eYhLtoXlmL < /etc/motd
;;;;;;;; with an attachment
;;; ./send-bismon-html-email.scm test-attach  _6UYrSn7piPM_3eYhLtoXlmL webroot/favicon.ico < /etc/motd
;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; end of send-bismon-html-email.scm
