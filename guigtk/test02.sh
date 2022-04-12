#!./minilisp-bismongtk --script
## BISMON file guigtk/test02.sh
## see https://github.com/bstarynk/bismon/
;;;+++

;;; consider building with:
;;;         env BISMON_OPTIM='-O0 -g' ./build.sh
;;; then debugging with:
;;;         gdb --args ./minilisp-bismongtk --verbose --script test02.sh
;


(define mybuilder ())


(setq mybuilder
 (gtk_builder

#"ABC(
  <interface>
  <object class="GtkDialog" id="dialog1">
    <child internal-child="vbox">
      <object class="GtkBox" id="vbox1">
        <property name="border-width">10</property>
        <child internal-child="action_area">
          <object class="GtkButtonBox" id="hbuttonbox1">
            <property name="border-width">20</property>
            <child>
              <object class="GtkButton" id="ok_button">
                <property name="label">gtk-ok</property>
                <property name="use-stock">TRUE</property>
                <!-- signal name="clicked" handler="ok_button_clicked" -->
              </object>
            </child>
          </object>
        </child>
      </object>
    </child>
  </object>
</interface>
)ABC"
 )
)

mybuilder

(define okbutton (gtk_builder_get mybuilder "ok_button"))

okbutton

(define dialog1 (gtk_builder_get mybuilder "dialog1"))

dialog1

(gtk_application_activate
	(println "gtk-application-activated")
	(gtk_widget_show_all dialog1)
	(gtk_application_add_window dialog1)
        (gtk_window_present dialog1)
)

(gtk_loop)

