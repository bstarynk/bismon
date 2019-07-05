// This file bm_delim.h is included several times.  It was previously
// _bm_delim.h but is renamed since we won't have enough developer
// time to generate that file, even if conceptually we should.

/**
    BISMON 
    Copyright © 2018, 2019 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch.

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

----
    Contact me (Basile Starynkevitch) by email
    basile@starynkevitch.net and/or basile.starynkevitch@cea.fr
**/
#ifndef HAS_DELIM_BM
#error missing HAS_DELIM_BM
#endif

#undef BM_NB_DELIM
#define BM_NB_DELIM 57
 
/// these should be sorted in ascending UTF8 order
// HAS_DELIM_BM(String,Delimname)
HAS_DELIM_BM("!",exclam)
HAS_DELIM_BM("!#",exclamhash)
HAS_DELIM_BM("!$",exclamdollar) /*STOREALTCLASSPREFIX_BM*/
HAS_DELIM_BM("!%",exclampercent)
HAS_DELIM_BM("!&",exclamand)
HAS_DELIM_BM("!(",exclamleft) /*STOREOBJECTALTOPENPREFIX_BM*/
HAS_DELIM_BM("!)",exclamright) /*STOREOBJECTALTCLOSEPREFIX_BM*/
HAS_DELIM_BM("!*",exclamstar)
HAS_DELIM_BM("!-",exclamminus)
HAS_DELIM_BM("!.",exclamdot)
HAS_DELIM_BM("!:",exclamcolon) /*STOREALTATTRIBUTEPREFIX_BM*/
HAS_DELIM_BM("!>",exclamgreater)
HAS_DELIM_BM("!@",exclamat) /*STOREALTMODPREFIX_BM*/
HAS_DELIM_BM("!^",exclamcaret) /*STOREMODULEALTPREFIX_BM*/
HAS_DELIM_BM("!|",exclambar) /*STOREFUNSIGNATUREALTPREFIX_BM*/
HAS_DELIM_BM("!~",exclamtilde)
HAS_DELIM_BM("#{",hashleftbrace)
HAS_DELIM_BM("$",dollar)
HAS_DELIM_BM("$%",dollarpercent)
HAS_DELIM_BM("$(",dollarleftparen)
HAS_DELIM_BM("$*",dollarstar)
HAS_DELIM_BM("$:",dollarcolon)
HAS_DELIM_BM("$=",dollarequal)
HAS_DELIM_BM("$[",dollarleftbracket)
HAS_DELIM_BM("%",percent)
HAS_DELIM_BM("(",leftparen)
HAS_DELIM_BM("(~",leftparentilde)
HAS_DELIM_BM(")",rightparen)
HAS_DELIM_BM("*",star)
HAS_DELIM_BM(",",comma)
HAS_DELIM_BM(":",colon)
HAS_DELIM_BM(";",semicolon)
HAS_DELIM_BM(";;",doublesemicolon)
HAS_DELIM_BM("=",equal)
HAS_DELIM_BM("?",question)
HAS_DELIM_BM("?#",questionhash)
HAS_DELIM_BM("?$",questiondollar)
HAS_DELIM_BM("?$-",questiondollarminus)
HAS_DELIM_BM("?*",questionstar)
HAS_DELIM_BM("?-",questionminus)
HAS_DELIM_BM("?.",questiondot)
HAS_DELIM_BM("[",leftbracket)
HAS_DELIM_BM("]",rightbracket)
HAS_DELIM_BM("^",caret)
HAS_DELIM_BM("{",leftbrace)
HAS_DELIM_BM("}",rightbrace)
HAS_DELIM_BM("}#",rightbracehash)
HAS_DELIM_BM("~",tilde)
HAS_DELIM_BM("~)",tilderightparen)
HAS_DELIM_BM("~:",tildecolon)
HAS_DELIM_BM("«", dblanglequotleft) /*STOREOBJECTOPENPREFIX_BM*/
HAS_DELIM_BM("°",degree)
HAS_DELIM_BM("±",plusminus) /*STOREMODTIMEPREFIX_BM*/
HAS_DELIM_BM("µ", mu) /*STOREMODULEPREFIX_BM*/
HAS_DELIM_BM("»", dblanglequotright) /*STOREOBJECTCLOSEPREFIX_BM*/
HAS_DELIM_BM("Σ", greekcapsigma) /*STOREFUNSIGNATUREPREFIX_BM*/
HAS_DELIM_BM("€",euro)
HAS_DELIM_BM("↦", rightfrombar) /*STOREATTRIBUTEPREFIX_BM*/
HAS_DELIM_BM("↳", downtipright) /*STORECOMPONENTPREFIX_BM*/
HAS_DELIM_BM("∈",element) /*STORECLASSPREFIX_BM*/

#undef HAS_DELIM_BM


