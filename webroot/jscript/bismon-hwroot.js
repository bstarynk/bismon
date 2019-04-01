// file jscript/bismon-hwroot.js

// handwritten JavaScript for bismon root

/***
    BISMON 
    Copyright © 2019 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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

"use strict";

// VERY INCOMPLETE

import {bismonjs_timestamp, bismonjs_timelong, bismonjs_lastgitcommit}
  from "/jscript/_timestamp.mjs";

export var appmenu_button;
export var appmenu_menu;
export var dump_menuitem;
export var exit_menuitem;
export var quit_menuitem;

function show_appmenu(ev) {
    console.debug("show_appmenu %o", ev);
    appmenu_menu.show();
    return false;
};

function hide_appmenu(ev) {
    console.debug("show_appmenu %o", ev);
    appmenu_menu.hide();
    return false;
};

$(function () {
    var topmenu_title = $("#topmtitle_6G1xOyeten5_7SqZ4EcQe8T")
    console.group("bismon-hwroot start");
    appmenu_button = $("#topbut_4m9twhDXB7k_88CBTgLfGvs");
    appmenu_menu = $("#topmenu_2hnb4LnCzga_48CQrsBJofR");
    dump_menuitem = $("#topmitem_1SiDnlyQRR6_5meHUV4d3iF");
    exit_menuitem = $("#topmitem_9ZmJrhdpjae_79WiEHOVpbE");
    quit_menuitem = $("#topmitem_2nguorns5mY_2UnseYw0xRf");
    console.debug("bismon-hwroot start topmenu_title=%o\n.. appmenu_button=%o appmenu_menu=%o dump_menuitem=%o exit_menuitem=%o quit_menuitem=%o",
		  topmenu_title, appmenu_button, appmenu_menu, dump_menuitem,  exit_menuitem, quit_menuitem);
    appmenu_menu.menu();
    appmenu_button.contextmenu(show_appmenu);
    appmenu_button.click(show_appmenu);
    appmenu_button.mouseup(hide_appmenu);
    topmenu_title.mouseup(hide_appmenu);
    appmenu_menu.mouseup(hide_appmenu);
    appmenu_menu.hide();
    console.trace();
    console.debug("bismon-hwroot started");
    console.groupEnd();
});



console.info("loaded bismon-hwroot.js from commit %s built %s",
	     bismonjs_lastgitcommit, bismonjs_timestamp);
// end of file bismon-hwroot.js
