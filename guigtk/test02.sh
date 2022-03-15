#!./minilisp-bismongtk --script
## BISMON file guigtk/test02.sh
## see https://github.com/bstarynk/bismon/
;;;+++

;;; consider building with:
;;;         env BISMON_OPTIM='-O0 -g' ./build.sh
;;; then debugging with:
;;;         gdb --args ./minilisp-bismongtk --verbose --script test02.sh
;

#"ABC(xxy\tk)ABC"  34

(gtk_loop)

