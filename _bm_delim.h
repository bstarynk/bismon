// file _bm_delim.h
#ifndef HAS_DELIM_BM
#error missing HAS_DELIM_BM
#endif

#undef BM_NB_DELIM
#define BM_NB_DELIM 51
 
/// these should be sorted in ascending UTF8 order
// HAS_DELIM_BM(String,Delimname)
HAS_DELIM_BM("!",exclam)
HAS_DELIM_BM("!#",exclamhash)
HAS_DELIM_BM("!$",exclamdollar)
HAS_DELIM_BM("!%",exclampercent)
HAS_DELIM_BM("!&",exclamand)
HAS_DELIM_BM("!(",exclamleft)
HAS_DELIM_BM("!)",exclamright)
HAS_DELIM_BM("!*",exclamstar)
HAS_DELIM_BM("!-",exclamminus)
HAS_DELIM_BM("!.",exclamdot)
HAS_DELIM_BM("!:",exclamcolon)
HAS_DELIM_BM("!>",exclamgreater)
HAS_DELIM_BM("!@",exclamat)
HAS_DELIM_BM("!^",exclamcaret)
HAS_DELIM_BM("!|",exclambar)
HAS_DELIM_BM("!~",exclamtilde)
HAS_DELIM_BM("#{",hashleftbrace)
HAS_DELIM_BM("$",dollar)
HAS_DELIM_BM("$%",dollarpercent)
HAS_DELIM_BM("$(",dollarleftparen)
HAS_DELIM_BM("$*",dollarstar)
HAS_DELIM_BM("$:",dollarcolon)
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
HAS_DELIM_BM("°",degree)
HAS_DELIM_BM("€",euro)

#undef HAS_DELIM_BM


