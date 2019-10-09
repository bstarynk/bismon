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
(format #t "#; bm-attachment::: ~a~%" bm-attachment)

(define bm-body-list #f)

(define bm-allowed-to-send-email? #t)

(define bm-contributor-name #f)

(define bm-contributor-email #f)

(define bm-contributor-alias #f)

(define bm-bismon-from-addr "bismon@localhost")

(define bm-simple-mail-program "/usr/bin/mail")
(define bm-attached-mail-program "/usr/bin/mail.mailutils")

;; the function to send an email
;; see https://stackoverflow.com/a/47351450/841108
(define (bm-really-emit-just-email email)
  ;; use bm-simple-mail-program, usually /usr/bin/mail
  (let ( (mailcmdstr
	  (if (string? bm-contributor-alias)
	      (format #f "~a -a'Content-Type:text/html;charset=UTF-8' -r ~s -s ~s -c ~s ~s"
		      bm-simple-mail-program
		      bm-bismon-from-addr
		      bm-subject
		      bm-contributor-alias
		      bm-contributor-email)
	      (format #f "~a -a'Content-Type:text/html;charset=UTF-8' -r ~s -s ~s ~s"
		      bm-simple-mail-program
		      bm-bismon-from-addr
		      bm-subject
		      bm-contributor-email))
	  )
	 )
    (format #t ";;bm-really-emit-just-email mailcmd ~s~%body ~a~%" mailcmdstr bm-body-list)
    (let ( (mailcmdport (open-output-pipe mailcmdstr))
	   )
      (if bm-body-list
	  (begin
	    (for-each (lambda (curline)
			(put-string mailcmdport curline)
			(put-char mailcmdport #\newline)
			)
		      bm-body-list)
	    (put-char mailcmdport #\return)
	    (put-char mailcmdport #\newline)
	    (force-output mailcmdport)
	    )
	  )
      (let ( (closemail (close-pipe mailcmdport))
	     )
	(format #t ";;bm-really-emit-just-email closemail ~a~%" closemail)
	closemail
	)
      )
    )
  )					;end of bm-really-emit-just-email



;; the function to send an email with a single file attachment
(define (bm-really-emit-email-with-attachment email)
  (format #t ";; bm-really-emit-email-with-attachment ~s~%" email)
  ;; use bm-attached-mail-program, usually /usr/bin/mail.mailutils
  (let ( (mailcmdstr
	  (if (string? bm-contributor-alias)
	      (format #f "~a -a'Content-Type:text/html;charset=UTF-8' -r ~s -s ~s -c ~s ~s"
		      bm-attached-mail-program
		      bm-bismon-from-addr
		      bm-subject
		      bm-contributor-alias
		      bm-contributor-email)
	      (format #f "~a -a'Content-Type:text/html;charset=UTF-8' -r ~s -s ~s -A ~s ~s"
		      bm-attached-mail-program
		      bm-bismon-from-addr
		      bm-subject
		      bm-attachment
		      bm-contributor-email))
	  )
	 )
    (format #t ";;bm-really-emit-email-with-attachment mailcmd ~s~%body ~a~%" mailcmd bm-body-list)
    (let ( (mailcmdport (open-output-pipe mailcmdstr))
	   )
      (if bm-body-list
	  (begin
	    (for-each (lambda (curline)
			(put-string mailcmdport curline)
			(put-char mailcmdport #\newline)
			)
		      bm-body-list)
	    (put-char mailcmdport #\return)
	    (put-char mailcmdport #\newline)
	    (force-output mailcmdport)
	    )
	  )
      (let ( (closemail (close-pipe mailcmdport))
	     )
	(format #t ";;bm-really-emit-email-with-attachment closemail ~a~%" closemail)
	closemail
	)
      )
    )
  )	;end of bm-really-emit-email-with-attachment 

(define (bm-email-host-part email)
  (and (string? email)
       (let ( (atix (string-rindex email #\@))
	      )
	 (and atix (substring email (+ atix 1)))))
  )


;; only the primary email could be faked or indirect
;; the alias is missing or a genuine email
(define (bm-fake-email-addr? email)
  (format #t ";;bm-fake-email-addr? email= ~s~%" email)
  (let ( (hostpart (bm-email-host-part email))
	 )
    (format #t ";;bm-fake-email-addr? hostpart=~s~%" hostpart)
    (equal? hostpart "fake.email")
    ))

(define (bm-fake-indirect-addr? email)
  (format #t ";;bm-fake-indirect-addr? email= ~s~%" email)
  (let ( (hostpart (bm-email-host-part email))
	 )
    (format #t ";;bm-fake-indirect-addr? hostpart=~s~%" hostpart)
    (equal? hostpart "fake.indirect")
    ))

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
	(set! bm-body-list (readloop))
	(format #t "#; bm-body-list becomes ~a~%" bm-body-list)
	)
      )
    )
  #:guess-encoding #f 					;dont guess encoding
  #:encoding "UTF-8" 				;force input encoding
  )
(format #t "#; bm-body-list::: ~a~%" bm-body-list)

(define (bm-emit-simple-email!)
  (format #t "; bm-emit-simple-email! oid ~s, name ~s, email ~s, alias ~s ~%"
	  bm-contributor-oid bm-contributor-name bm-contributor-email bm-contributor-alias)
  (bm-really-emit-just-email bm-contributor-email)
  (format #t "; bm-emit-simple-email! done oid ~s, email ~s~%"
	  bm-contributor-oid bm-contributor-email)
  )

(define (bm-emit-attached-email!)
  (format #t "; bm-emit-attached-email! oid ~s, name ~s, email ~s, alias ~s, attach ~s ~%"
	  bm-contributor-oid bm-contributor-name bm-contributor-email bm-contributor-alias bm-attachment)
  (bm-really-emit-email-with-attachment bm-contributor-email)
  (format #t "; bm-emit-attached-email! done oid ~s, email ~s~%"
	  bm-contributor-oid bm-contributor-email)
  )

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
    (let* ( (closecontrib (close-pipe contribcmdport))
	    (contriblist (string-split contribstr #\tab))
	    )
      (format #t ";; closecontrib ~a contriblist ~s ~%"
	      closecontrib contriblist)
      (let ( (contribname (car contriblist))
	     (contriboid (cadr contriblist))
	     (contribemail (caddr contriblist))
	     (contribalias (and (pair? (cdddr contriblist))
				(cadddr contriblist)))
	     )
	(format #t ";; contribname ~s; contriboid ~s; contribemail ~s; contribalias ~s; ~%"
		contribname contriboid contribemail contribalias)
	(cond
	 ( (equal? contriboid bm-contributor-oid)
	   (set! bm-contributor-name contribname)
	   (set! bm-contributor-email contribemail)
	   (set! bm-contributor-alias contribalias)
	   (format #t ";; good contributor ~a ~%" bm-contributor-name)
	   (format #t ";; hostemail ~s ~%" (bm-email-host-part contribemail))
	   (format #t ";; hostalias ~s ~%" (bm-email-host-part contribalias))
	   (cond ( (not bm-allowed-to-send-email?)
		   (format #t "email is not sent to ~s cc ~s; subject: ~s~%Body:~%~s~%......~a.......~%~% ~%"
			   bm-contributor-email
			   bm-contributor-alias
			   bm-subject
			   bm-body-list
			   bm-contributor-oid)
		   )
		 ( bm-attachment
		   (cond
		    ( (bm-fake-email-addr? bm-contributor-email)
		      (format #t "email with fake ~s and attachment ~s ~%" bm-contributor-email bm-attachment)
		      )
		    ( (bm-fake-indirect-addr? bm-contributor-email)
		      (format #t "email with indirection ~s  and attachment ~s ~%" bm-contributor-email bm-attachment))
		    (else
		     (format #t "email to ~s with attachment ~s ~%" bm-contributor-email  bm-attachment)
		     (bm-emit-attached-email!)
		     )
		    )
		   )
		 ( (bm-fake-email-addr? bm-contributor-email)
		   (format #t "email with fake ~s no attachment ~%" bm-contributor-email)
		   ;;; TODO: incomplete code, should handle @fake.email
		   ;;------------------------
		   )
		 ( (bm-fake-indirect-addr? bm-contributor-email)
		   (format #t "email with indirection ~s  no attachment ~%" bm-contributor-email)
		   ;;; TODO: incomplete code, should handle @fake.indirect
		   ;;------------------------
		   )
		 (else
		  (format #t "email to ~s no attachment. Body:~%~s~%......~a.......~%~%"
			  bm-contributor-email
			  bm-body-list bm-contributor-oid)
		  (bm-emit-simple-email!)
		  )
		 )
	   )
	 (else
	  (format #t ";; bad contributor ~s ~%" bm-contributor-oid)
	  )
	 )
	)
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
