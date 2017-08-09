// file _bm_delim.h
#ifndef HAS_DELIM_BM
#error missing HAS_DELIM_BM
#endif

#undef BM_NB_DELIM
#define BM_NB_DELIM 29
 
/// these should be sorted in ascending UTF8 order
// HAS_DELIM_BM(String,Delimname)
HAS_DELIM_BM("!#",exclamhash)
HAS_DELIM_BM("!$",exclamdollar)
HAS_DELIM_BM("!%",exclampercent)
HAS_DELIM_BM("!&",exclamand)
HAS_DELIM_BM("!(",exclamleft)
HAS_DELIM_BM("!)",exclamright)
HAS_DELIM_BM("!*",exclamstar)
HAS_DELIM_BM("!:",exclamcolon)
HAS_DELIM_BM("!@",exclamat)
HAS_DELIM_BM("!^",exclamcaret)
HAS_DELIM_BM("!~",exclamtilde)
HAS_DELIM_BM("#{",hashleftbrace)
HAS_DELIM_BM("%",percent)
HAS_DELIM_BM("(",leftparen)
HAS_DELIM_BM("(~",leftparentilde)
HAS_DELIM_BM(")",rightparen)
HAS_DELIM_BM("*",star)
HAS_DELIM_BM(",",comma)
HAS_DELIM_BM(":",colon)
HAS_DELIM_BM(";",semicolon)
HAS_DELIM_BM("[",leftbracket)
HAS_DELIM_BM("]",rightbracket)
HAS_DELIM_BM("{",leftbrace)
HAS_DELIM_BM("}",rightbrace)
HAS_DELIM_BM("}#",rightbracehash)
HAS_DELIM_BM("~",tilde)
HAS_DELIM_BM("~)",tilderightparen)
HAS_DELIM_BM("~:",tildecolon)
HAS_DELIM_BM("°",degree)

#undef HAS_DELIM_BM


