<!-- file webinterface.md -->

# Web interface #

See first the *§4.1 Web interface internal design* of
[bismon-chariot-doc.pdf](http://starynkevitch.net/Basile/bismon-chariot-doc.pdf).


Use the [Firefox HTML Validator](http://users.skynet.be/mgueury/mozilla/index.html) to check the generated XHTML5.

## organization of the root HTML tree

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
