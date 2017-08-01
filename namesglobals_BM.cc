// file namesglobals_BM.cc
extern "C" {
#include "bismon.h"
};

#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <string>

//// order with strcmp
struct StrcmpLess_BM
{
  inline bool operator() (const char*s1, const char*s2) const
  {
    assert (s1 != nullptr);
    assert (s2 != nullptr);
    return strcmp(s1,s2)<0;
  }
};

struct ObjectHash_BM
{
  inline size_t operator() (const objectval_tyBM*pob) const
  {
    return objecthash_BM(pob);
  };
};

struct ObjectLess_BM
{
  inline bool operator() (const objectval_tyBM*pob1, const objectval_tyBM*pob2) const
  {
    return objectcmp_BM(pob1, pob2)<0;
  };
};

// keys are strdup-ed strings, values are objectval_tyBM*
static std::map<const char*,objectval_tyBM*,StrcmpLess_BM> namemap_BM;


// keys are objectval_tyBM*, values are strdup-ed strings
static std::unordered_map<objectval_tyBM*,const char*,ObjectHash_BM> objhashtable_BM;



bool
validname_BM (const char *nam)
{
  if (!nam)
    return false;
  if (!isalpha (nam[0]))
    return false;
  const char *pc = nam;
  for (; *pc; pc++)
    {
      if (isalnum (*pc))
        continue;
      else if (*pc == '_')
        {
          if (!isalnum (pc[1]))
            return false;
          if (!isalnum (pc[-1]))
            return false;
          continue;
        }
      else
        return false;
    }
  return true;
}                               /* end validname_BM */


static void
add_predefined_name_BM (const char *name, objectval_tyBM * obj)
{
  assert (validname_BM (name));
  assert (isobject_BM (obj));
  char *dupname = strdup (name);
  if (!dupname)
    FATAL_BM ("strdup %s failed (%m)", name);
  assert (namemap_BM.find(name) == namemap_BM.end());
  assert (objhashtable_BM.find(obj) == objhashtable_BM.end());
  namemap_BM.insert({dupname,obj});
  objhashtable_BM.insert({obj,dupname});
}                               /* end add_predefined_name_BM */

void
initialize_predefined_names_BM (void)
{
  objhashtable_BM.reserve(3*BM_NB_PREDEFINED+100);
#define HAS_NAMED_PREDEF_BM(Nam,Id) \
  add_predefined_name_BM(#Nam,PREDEF_BM(Id));
#include "_bm_predef.h"
}                               /* end initialize_predefined_names_BM */


const objectval_tyBM *
findnamedobj_BM (const char *nam)
{
  if (!nam || !nam[0] || !validname_BM (nam))
    return nullptr;
  auto it = namemap_BM.find(nam);
  if (it != namemap_BM.end())
    return it->second;
  return nullptr;
}                               /* end findnamedobj_BM */

const char *
findobjectname_BM (const objectval_tyBM * obj)
{
  if (!isobject_BM ((const value_tyBM) obj))
    return nullptr;
  auto it = objhashtable_BM.find(const_cast<objectval_tyBM*>(obj));
  if (it != objhashtable_BM.end())
    return it->second;
  return nullptr;
}                               /* end findobjectname_BM */


bool
registername_BM (const objectval_tyBM * obj, const char *nam)
{
  static long regcount;
  if (!isobject_BM ((const value_tyBM) obj))
    return false;
  if (!validname_BM (nam))
    return false;
  if (namemap_BM.find(nam) != namemap_BM.end())
    return false;
  if (objhashtable_BM.find(const_cast<objectval_tyBM*>(obj))
      != objhashtable_BM.end())
    return false;
  char *dupname = strdup (nam);
  if (!dupname)
    FATAL_BM ("strdup %s failed (%m)", nam);
  namemap_BM.insert({dupname,const_cast<objectval_tyBM*>(obj)});
  objhashtable_BM.emplace(const_cast<objectval_tyBM*>(obj),dupname);
  regcount++;
  if (regcount % 128)
    objhashtable_BM.rehash(0);
  return true;
}                               /* end registername_BM */


bool
forgetnamedobject_BM (const objectval_tyBM * obj)
{
  if (!isobject_BM ((const value_tyBM) obj))
    return false;
  auto itob = objhashtable_BM.find(const_cast<objectval_tyBM*>(obj));
  if (itob == objhashtable_BM.end())
    return false;
  const char* nam = itob->second;
  auto itn = namemap_BM.find(nam);
  assert (itn != namemap_BM.end() && itn->second == obj);
  objhashtable_BM.erase(itob);
  namemap_BM.erase(itn);
  free ((void*)nam);
  return true;
} /* end forgetnamedobject_BM */


bool
forgetnamestring_BM (const char *nam)
{
  if (!nam || !validname_BM(nam)) return false;
  auto itn = namemap_BM.find(nam);
  if (itn == namemap_BM.end())
    return false;
  objectval_tyBM* ob = itn->second;
  assert (isobject_BM(ob));
  auto itob = objhashtable_BM.find(ob);
  assert (itob != objhashtable_BM.end());
  const char*dupnam = itob->second;
  objhashtable_BM.erase(itob);
  namemap_BM.erase(itn);
  free ((void*)dupnam);
  return true;
} /* end forgetnamestring_BM */


const setval_tyBM *
setofnamedobjects_BM (void)
{
  std::vector<const objectval_tyBM *> vectobj;
  vectobj.reserve(namemap_BM.size());
  for (auto itn: namemap_BM)
    {
      const objectval_tyBM* ob = itn.second;
      assert (isobject_BM((const value_tyBM)ob));
      vectobj.push_back(ob);
    };
  return makeset_BM(vectobj.data(), vectobj.size());
} // end setofnamedobjects_BM


const char*
findnameafter_BM(const char*prefix)
{
  if (!prefix || prefix[0]==(char)0)
    {
      if (namemap_BM.empty()) return nullptr;
      auto firstn = namemap_BM.begin();
      return firstn->first;
    }
  auto itn = namemap_BM.upper_bound(prefix);
  if (itn != namemap_BM.end())
    return itn->first;
  return nullptr;
} // end of findnameafter_BM


const char*
findnamesameorafter_BM(const char*prefix)
{
  if (!prefix || prefix[0]==(char)0)
    {
      if (namemap_BM.empty()) return nullptr;
      auto firstn = namemap_BM.begin();
      return firstn->first;
    }
  auto itn = namemap_BM.lower_bound(prefix);
  if (itn != namemap_BM.end())
    return itn->first;
  return nullptr;
} // end of findnamesameorafter_BM


const char*
findnamebefore_BM(const char*prefix)
{
  if (!prefix || prefix[0]==(char)0)
    {
      if (namemap_BM.empty())
        return nullptr;
      auto lastn = namemap_BM.end();
      lastn--;
      return lastn->first;
    }
  auto itn = namemap_BM.lower_bound(prefix);
  if (itn != namemap_BM.begin())
    itn--;
  else
    return nullptr;
  if (itn != namemap_BM.end())
    return itn->first;
  return nullptr;
} // end of findnamebefore_BM



////////////////////////////////////////////////////////////////

static std::map<std::string, objectval_tyBM**> mapglobals_BM;

void initialize_globals_BM(void)
{
#define HAS_GLOBAL_BM(Gnam) do {		\
  assert (mapglobals_BM.find(#Gnam)		\
	  == mapglobals_BM.end());		\
  mapglobals_BM[#Gnam] = &GLOBAL_BM(Gnam);	\
} while(0);
#include "_bm_global.h"
} // end of initialize_globals_BM

void
gcmarkglobals_BM(struct garbcoll_stBM*gc)
{
  for (auto it: mapglobals_BM)
    if (it.second)
      gcmark_BM(gc, it.second, 0);
} // end gcmarkglobals_BM


const node_tyBM *
nodeglobalnames_BM (const objectval_tyBM * connob)
{
  if (!isobject_BM((const value_tyBM)connob))
    return nullptr;
  std::vector<value_tyBM> vecstr;
  vecstr.reserve(mapglobals_BM.size());
  for (auto it: mapglobals_BM)
    {
      const std::string& curname = it.first;
      vecstr.push_back((value_tyBM)makestring_BM(curname.c_str()));
    }
  return makenode_BM (connob, vecstr.size(), vecstr.data());
} // end nodeglobalnames_BM


const setval_tyBM *
setglobalobjects_BM(void)
{
  std::vector<objectval_tyBM*> vecobj;
  std::set<objectval_tyBM*,ObjectLess_BM> setobj;
  vecobj.reserve(mapglobals_BM.size());
  for (auto it: mapglobals_BM)
    {
      objectval_tyBM* curob = *(it.second);
      if (!curob || valtype_BM((const value_tyBM)curob) != tyObject_BM)
        continue;
      if (setobj.find (curob) != setobj.end()) continue;
      vecobj.push_back(curob);
    };
  return makeset_BM((const objectval_tyBM**)(vecobj.data()), vecobj.size());
} // end setglobalobjects_BM
