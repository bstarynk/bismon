// file jscript/bismon-hwroot.js

// handwritten JavaScript for bismon root

/***
    BISMON 
    Copyright © 2019, 2020 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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
export var appmenu_menuid;
export var appmenu_menu;
export var dump_menuitem;
export var exit_menuitem;
export var quit_menuitem;
export var neweval_button;

var neweval_counter=0;

function show_appmenu(ev) {
    console.debug("show_appmenu %o", ev);
    // WRONG
    appmenu_menu.position({
	my: "left+3 bottom-3",
	of:  appmenu_menuid,
	at: "left+5 bottom-10",
	collision: "fit"
    });
    appmenu_menu.show();
    return false;
};

function hide_appmenu(ev) {
    console.debug("hide_appmenu %o", ev);
    appmenu_menu.hide();
    return false;
};

var bm_default_canvas;

class Canvas_element_bm {
    constructor (canv) {
	if (canv == undefined || canv == null) {
	    canv = bm_default_canvas;
	};
	this.bm_canvas = canv;
	console.debug("Canvas_element_bm this=%o", this);
    }
    canvas () { return this.bm_canvas; }
};				// end Canvas_element_bm


class Canvas_string_bm extends Canvas_element_bm {
    constructor (canv, str) {
	super (canv);
	if (typeof(str) != "string") {
	    console.error("bad str %o to Canvas_element_bm", str);
	    throw new Error("bad string to Canvas_string_bm:" + str);
	}
	this.bm_str = str;
    }
};				// end Canvas_string_bm

class Canvas_box_bm extends Canvas_element_bm {
    constructor (canv) {
	super (canv);
	this.bm_sons = new Array();
    }
    append1(son) {
	if (!son)
	    return;
	else if (Array.isArray(son)) {
	    for (comp in son) {
		if (comp)
		    this.append1(comp);
	    }
	}
	else if (typeof(son) == "object" && (son instanceof Canvas_element_bm)) {
	    bm_sons.push(son);
	}
	return this;
    }
    append(...etc) {
	var curson;
	for (curson in etc) {
	    if (!curson) {
		continue;
	    }
	    else
		append1(curson);
	}
	return this;
    }
}; // end class  Canvas_box_bm 

class Canvas_hbox_bm extends Canvas_box_bm {
    constructor (canv, ...etc) {
	super(canv);
	append1(etc);
    }
};				// end Canvas_hbox_bm


class Canvas_vbox_bm extends Canvas_box_bm {
    constructor (canv, ...etc) {
	super(canv);
	append1(etc);
    }
};				// end Canvas_vbox_bm


function bmhwroot_create_neweval_dialog(ev, cnt, id) {
    console.group("bmhwroot_create_neweval_dialog start");
    console.debug("ev=%o cnt=%d id=%o", ev, cnt, id);
    var newevaldiv = $("<div>", {id: "nwevdial" + id, "class": "bmcl_neweval"});
    var newevalbox = null;
    var newevalcanvas = null;
    var jsonsettings = null;
    $.ajax({
	url: "/_bismon_settings.json",
	dataType: "json",
	type: "get",
	contentType: "application/json",
	success: function(data,textStatus,jQxhr){
	    console.debug("bismonsettings id=%o newevaldiv=%o success data=%o, textStatus=%o, jQxhr=%o",
			  id, newevaldiv, data, textStatus, jQxhr);
	},
	error: function(jqXhr,textStatus,errorThrown){
	    console.log("bismonsettings id=%o newevaldiv=%o error jqXhr=%o, textStatus=%o, errorThrown=%o",
			id, newevaldiv, jqXhr, textStatus, errorThrown);
	}
    }); // end AJAX of bismonsettings
    $('body').append(newevaldiv);
    newevaldiv.dialog({
	title: "neweval#" + cnt,
	resizable: true,
	minWidth: 320,
	minHeight: 210,
	classes: {
	    "ui-dialog_content": "bmcl_neweval"
	},
	resizeStart: function (evresiz, ui) {
	    console.group("create_neweval_dialog resizeStart");
	    console.debug("neweval_dialog resizeStart evresiz=%o ui=%o newevaldiv=%o h=%d w=%d",
			  evresiz, ui, newevaldiv, newevaldiv.height(), newevaldiv.width());
	    console.groupEnd();
	},
	resizeStop: function (evresiz, ui) {
	    console.group("create_neweval_dialog resizeStop");
	    console.debug("neweval_dialog resizeStop evresiz=%o ui=%o newevaldiv=%o", evresiz, ui, newevaldiv);
	    var oldwidth = ui.originalSize.width;
	    var oldheight = ui.originalSize.height;
	    var widthnew = ui.size.width;
	    var heightnew = ui.size.height;
	    console.debug("neweval_dialog resizeStop oldwidth=%f oldheight=%f widthnew=%f heightnew=%f newevaldiv=%o newevalbox=%o newevalcanvas=%o",
			  oldwidth, oldheight, widthnew, heightnew, newevaldiv, newevalbox, newevalcanvas);
	    //https://stackoverflow.com/a/18953446/841108
	    var boxheight = Math.ceil(0.9*heightnew/5)*5;
	    var boxwidth = Math.ceil(0.9*widthnew/5)*5;
	    newevalbox.height(boxheight);
	    newevalbox.width(boxwidth);
	    var canvheight = boxheight-4;
	    var canvwidth = boxwidth-4;
	    newevalcanvas.height(canvheight);
	    newevalcanvas.width(canvwidth);
	    // don't work, since the coordinates are relative to the body newevalcanvas.offset({top:boxheight-2, left:2});
	    /// we should redraw and probably reorganize the canvas
	    console.debug("neweval_dialog resizeStop newevalcanvas=%o boxheight=%d boxwidth=%d canvheight=%d canvwidth=%d",
			  newevalcanvas, boxheight, boxwidth, canvheight, canvwidth);
	    console.groupEnd();
	},
	close: function (evclose, ui) {
	    console.group("create_neweval_dialog close");
	    console.debug("newevaldialog close evclose=%o ui=%o newevaldiv=%o cnt=%d id=%o", evclose, ui, newevaldiv, cnt, id);
	    /// should do some AJAX here
	    $.ajax({
		url: "/newevclose_ajax",
		dataType: "json",
		type: "post",
		contentType: "application/json",
                data: JSON.stringify( { "newevclose_rank": cnt, "newevclose_id": id } ),
		success: function(data,textStatus,jQxhr){
		    console.debug("newevclose_ajax id=%o newevaldiv=%o success data=%o, textStatus=%o, jQxhr=%o",
				  id, newevaldiv, data, textStatus, jQxhr);
		},
		error: function(jqXhr,textStatus,errorThrown){
		    console.log("newevclose_ajax id=%o newevaldiv=%o error jqXhr=%o, textStatus=%o, errorThrown=%o",
				id, newevaldiv, jqXhr, textStatus, errorThrown);
		}
	    }); // end AJAX of newevclose_ajax
	    console.groupEnd();
	}
    });
    console.debug("newevaldiv=%o", newevaldiv);
     newevalbox =  $("<div>", {id: "nwevdialbox" + id,
				  "class": "bmcl_newevalbox",
					height: 0.9*newevaldiv.height() + 5,
					width: 0.9*newevaldiv.width() + 5
				 });
    newevaldiv.append(newevalbox);
    newevaldiv.bmevalbox = newevalbox;
    // should consider a canvas approach, using perhaps
    // https://projects.calebevans.me/jcanvas/
    newevalcanvas = $("<canvas>",  {id: "nwevdialcanvas" + id,
				    "class": "bmcl_newevalcanvas",
				    height: 0.9*newevalbox.height() + 5,
				    width: 0.9*newevalbox.width() + 5,
				    tabindex: 0,
				   });
    newevalbox.append(newevalcanvas);
    newevaldiv.bmevalcanvas = newevalcanvas;
    console.debug("newevalbox=%o, newevalcanvas=%o",
		  newevalbox, newevalcanvas);
    /***
    newevaltransptext.keypress(function(ev) {
	var keystr= ev.key;
	console.debug("newevaldialog keypress newevalbox=%o, ev=%o key=%o charcode=%d",
		      newevalbox, ev, keystr, ev.charCode);
	//https://stackoverflow.com/a/32567789/841108 test for a letter
	if (keystr.toLowerCase() != keystr.toUpperCase()) {
	    console.debug("newevaldialog keypress letter keystr=%o", keystr);
	    //newevalbox.append(keystr);
	    return true;
	}
    });
    ***/
    newevalcanvas.keypress(function (ev) {
	var keystr= ev.key;
	console.debug("newevaldialog keypress newevalcanvas=%o, newevalbox=%o, ev=%o key=%o charcode=%d",
		      newevalcanvas, newevalbox, ev, keystr, ev.charCode);
    });
    newevalcanvas.drawText({
	text: "⁈",
	x: 10, y: 10,
	fontFamily: "Verdana, sans-serif",
	fillStyle: '#f12',
	fontSize: 16
    });
    newevalcanvas.keydown(function(ev) {
	console.debug("newevaldialog keydown newevalcanvas=%o, ev=%o key=%o charcode=%d",
		      newevalcanvas, ev, ev.key, ev.charCode);
    });
    console.debug("again newevalbox=%o, newevalcanvas=%o",
		  newevalbox, newevalcanvas);
    console.groupEnd();
    return newevaldiv;
}; // end bmhwroot_create_neweval_dialog



function bmhwroot_initialize() {
    var topmenu_title = $("#topmtitle_6G1xOyeten5_7SqZ4EcQe8T")
    console.group("bismon-hwroot start");
    appmenu_button = $("#topbut_4m9twhDXB7k_88CBTgLfGvs");
    appmenu_menuid = "#topmenu_2hnb4LnCzga_48CQrsBJofR";
    appmenu_menu = $(appmenu_menuid);
    neweval_button = $("#topbut_3ayHp9M82jt_864Z18Gf0eU");
    dump_menuitem = $("#topmitem_1SiDnlyQRR6_5meHUV4d3iF");
    exit_menuitem = $("#topmitem_9ZmJrhdpjae_79WiEHOVpbE");
    quit_menuitem = $("#topmitem_2nguorns5mY_2UnseYw0xRf");
    console.debug("bismon-hwroot start topmenu_title=%o\n.. appmenu_button=%o appmenu_menu=%o dump_menuitem=%o exit_menuitem=%o quit_menuitem=%o neweval_button=%o",
		  topmenu_title, appmenu_button, appmenu_menu, dump_menuitem,  exit_menuitem, quit_menuitem, neweval_button);
    appmenu_menu.menu();
    appmenu_button.contextmenu(show_appmenu);
    appmenu_button.click(show_appmenu);
    appmenu_button.mouseup(hide_appmenu);
    topmenu_title.mouseup(hide_appmenu);
    appmenu_menu.mouseup(hide_appmenu);
    /// the neweval_button should trigger an /neweval_ajax POST request with AJAX
    neweval_button.click(
	function (ev) {
	    console.group ("neweval_button!click");
	    neweval_counter++
	    console.debug("newevalclick ev=%o, neweval_counter=%d", ev, neweval_counter);
	    $.ajax({
		url: "/neweval_ajax",
		dataType: "json",
		type: "post",
		contentType: "application/json",
                data: JSON.stringify( { "neweval_counter":neweval_counter } ),
		success: function(data,textStatus,jQxhr){
		    var curcnt = data.neweval_counter;
		    var curid = data.neweval_id;
		    console.debug("newevalclick ajax#%d success data=%o, textStatus=%o, jQxhr=%o\n.. curcnt=%d, curid=%s",
				  neweval_counter, data, textStatus, jQxhr, curcnt, curid);
		    bmhwroot_create_neweval_dialog(ev, curcnt, curid);
		},
		error: function(jqXhr,textStatus,errorThrown){
		    console.log("newevalclick ajax#%d error: jqXhr=%o, textStatus=%o, errorThrown=%o",
				neweval_counter, jqXhr, textStatus, errorThrown);
		}
	    });
	    console.debug("newevalclick#%d ev=%o ending", neweval_counter, ev);
	    console.groupEnd();
	}
    );
    appmenu_menu.hide();
    console.debug("bismon-hwroot hided appmenu_menu=%o", appmenu_menu);
    console.trace();
    console.debug("bismon-hwroot did start");
    console.groupEnd();
};

$(function() {
    console.debug("bismon-hwroot document initialize");
    bmhwroot_initialize();
});



console.info("loaded bismon-hwroot.js from commit %s built %s",
	     bismonjs_lastgitcommit, bismonjs_timestamp);
// end of file bismon-hwroot.js
