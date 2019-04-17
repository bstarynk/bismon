<!-- file webinterface.md -->

# Web interface #

See first the *§4.1 Web interface internal design* of
[bismon-chariot-doc.pdf](http://starynkevitch.net/Basile/bismon-chariot-doc.pdf).


Use the [Firefox HTML Validator](http://users.skynet.be/mgueury/mozilla/index.html) to check the generated XHTML5.

## organization of the root HTML tree (only HTML elements are shown)

* `<html` top root-html-element €_3poYCpSsB
    * `<head` element €_1sitXrzOd
        * `<title` element €_1yXAklDk0
        * `<script` for `jquery.js`  element €_7pzlWqA1e
        * `<script` for `jquery-ui.js`  element €_37OSgkA0Y
        * `<script` for generated `bismon-root-jsmodule.js` element €_7CbJCH86J
        * `<script` for handwritten `bismon-hwroot.js` element €_1ekuIkeTL
        * `<link` for the theme stylesheet element €_278dlMgNG
        * `<link` for the jquery-ui stylesheet element €_5eUsNI0Fz
    * `<body` element €_46W9FNT1h
        * `<h1` for *Bismon* element €_95vgIuQG
	* `<nav` element €_8LMWqayq5 of class `bmcl_topnav`
	    * `<button` element €_4m9twhDXB  for app-menu
	* `<p` element €_0uAT1v6dH for hello-paragraph of class `bmcl_hellopara` with `hello` then
	    * a closure for emit-websession-contributor €_3owspX08b,
	    * `your session is `
	    * a node of connective €_3Sa7WXi2wO emitting ...
	       * `<tt`  element of class `bmcl_cookie` with closure for emit-websession-cookie €_5T8fxyaeO
	* `<ul` element €_2hnb4LnCz for app-menuitems of class `bmcl_topmenu`
	    * `<li` element €_6G1xOyete for app-menu-titleitem of class `bmcl_topmenutitle` and `ui-menu-item` 
	    * `<li` element €_1SiDnlyQR for dump app-menuitem of class `bmcl_topmenuitem` and `ui-menu-item`
	    * `<li` element €_9ZmJrhdpj for exit app-menuitem of class `bmcl_topmenuitem` and `ui-menu-item`
	    * `<li` element €_2nguorns5 for quit app-menitem of class `bmcl_topmenuitem` and `ui-menu-item`

## suggestions

Perhaps use [jquery-ui-contextmenu](https://github.com/mar10/jquery-ui-contextmenu)
