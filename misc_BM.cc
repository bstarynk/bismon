// file misc_BM.cc
// SPDX-License-Identifier: GPL-3.0-or-later
// see https://github.com/bstarynk/bismon/
/***
    BISMON
    Copyright © 2018 - 2021 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch (working at CEA, LIST, France)
    <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>
    with help from Franck Védrine.

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

#include <fnmatch.h>
#include <map>
#include <new>
#include <set>
#include <vector>
#include <deque>
#include <mutex>
#include <condition_variable>
#include <unordered_map>
#include <string>
#include <atomic>
#include <thread>
#include <ratio>
#include <chrono>
#include <functional>
#include <cmath>
#ifdef BISMONGTK
#include <gtk/gtk.h>
#endif /*BISMONGTK*/
#include <glib.h>
#include "bismon.h"

static_assert (sizeof(std::atomic<objectval_tyBM*>) == sizeof(objectval_tyBM*), "pointer to objects have same size as their atomic");

static_assert (alignof(std::atomic<objectval_tyBM*>) == alignof(objectval_tyBM*), "pointer to objects have same alignment as their atomic");

//// order with strcmp
struct StrcmpLess_BM
{
  inline bool operator() (const char*s1, const char*s2) const
  {
    ASSERT_BM (s1 != nullptr);
    ASSERT_BM (s2 != nullptr);
    return strcmp(s1,s2)<0;
  }
};				// end StrcmpLess_BM

//// order with
struct ValStringLess_BM
{
  inline bool operator() ( stringval_tyBM*vs1,  stringval_tyBM*vs2) const
  {
    ASSERT_BM (valtype_BM((const value_tyBM)vs1) == tyString_BM);
    ASSERT_BM (valtype_BM((const value_tyBM)vs2) == tyString_BM);
    return strcmp(vs1->strv_bytes,vs2->strv_bytes)<0;
  }
};				// end ValStringLess_BM

struct ObjectHash_BM
{
  inline size_t operator() (const objectval_tyBM*pob) const
  {
    return objecthash_BM(pob);
  };
};				// end Objecthash_BM

struct ObjectLess_BM
{
  inline bool operator() (const objectval_tyBM*pob1, const objectval_tyBM*pob2) const
  {
    return objectcmp_BM(pob1, pob2)<0;
  };
};				// end ObjectLess_BM


struct threadinfo_stBM;

// keys are strdup-ed strings, values are objectval_tyBM*
static std::map<const char*,objectval_tyBM*,StrcmpLess_BM> namemap_BM;


// keys are objectval_tyBM*, values are strdup-ed strings
static std::unordered_map<objectval_tyBM*,const char*,ObjectHash_BM> objhashtable_BM;

struct failurelockset_stBM
{
  friend void register_failock_BM (struct failurelockset_stBM *,
                                   objectval_tyBM *);
  friend void unregister_failock_BM (struct failurelockset_stBM *,
                                     objectval_tyBM *);
  std::multiset<objectval_tyBM*,ObjectLess_BM> flhobjset;
  failurelockset_stBM () {};
  ~failurelockset_stBM ()
  {
    for (objectval_tyBM* ob : flhobjset)
      {
        ASSERT_BM (valtype_BM(ob) == tyObject_BM);
        pthread_mutex_unlock(&ob->ob_mutex);
      }
  }
  friend void initialize_failurelockset_BM(struct failurelockset_stBM *, size_t);
  friend void destroy_failurelockset_BM(struct failurelockset_stBM *);
};

struct ModuleData_BM
{
  rawid_tyBM mod_id;
  void* mod_dlh;		// the dlopen handle
  objectval_tyBM* mod_obj;	// the module object
  value_tyBM mod_data;		// its data
};

static std::map<rawid_tyBM,ModuleData_BM,IdLess_BM> modulemap_BM;



////////////////
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
  ASSERT_BM (validname_BM (name));
  ASSERT_BM (isobject_BM (obj));
  char *dupname = strdup (name);
  if (!dupname)
    FATAL_BM ("strdup %s failed (%m)", name);
  ASSERT_BM (namemap_BM.find(name) == namemap_BM.end());
  ASSERT_BM (objhashtable_BM.find(obj) == objhashtable_BM.end());
  namemap_BM.insert({dupname,obj});
  objhashtable_BM.insert({obj,dupname});
}                               /* end add_predefined_name_BM */

void
initialize_predefined_names_BM (void)
{
  objhashtable_BM.reserve(3*BM_NB_PREDEFINED+100);
#define HAS_NAMED_PREDEF_BM(Nam,Id) \
  add_predefined_name_BM(#Nam,PREDEF_BM(Id));
#include "_genbm_predef.h"
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
  ASSERT_BM (itn != namemap_BM.end() && itn->second == obj);
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
  ASSERT_BM (isobject_BM(ob));
  auto itob = objhashtable_BM.find(ob);
  ASSERT_BM (itob != objhashtable_BM.end());
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
      ASSERT_BM (isobject_BM((const value_tyBM)ob));
      vectobj.push_back(ob);
    };
  return makeset_BM(vectobj.data(), vectobj.size());
} // end setofnamedobjects_BM


const setval_tyBM *
setofprefixednamedobjects_BM (const char*prefix)
{
  if (!prefix || !prefix[0]) return setofnamedobjects_BM();
  int prefixlen = strlen(prefix);
  std::vector<const objectval_tyBM *> vectobj;
  vectobj.reserve(2*TINYSIZE_BM);
  for (auto itn = namemap_BM.lower_bound(prefix);
       itn != namemap_BM.end(); itn++)
    {
      int cmp = strncmp(itn->first, prefix, prefixlen);
      if (cmp) break;
      const objectval_tyBM* ob = itn->second;
      ASSERT_BM (isobject_BM((const value_tyBM)ob));
      vectobj.push_back(ob);
    }
  return makeset_BM(vectobj.data(), vectobj.size());
} // end setofprefixednamedobjects_BM


const setval_tyBM*
setofmatchednamedobjects_BM(const char*fnmatcher)
{
  if (!fnmatcher || !fnmatcher[0]) return setofnamedobjects_BM();
  std::vector<const objectval_tyBM *> vectobj;
  vectobj.reserve(namemap_BM.size()/16+10);
  bool allcases = (fnmatcher[0] == '~');
  for (auto itn : namemap_BM)
    {
      const objectval_tyBM* ob = itn.second;
      ASSERT_BM (isobject_BM((const value_tyBM)ob));
      if (!fnmatch(allcases?(fnmatcher+1):fnmatcher, itn.first,
                   allcases ? (FNM_EXTMATCH | FNM_CASEFOLD)
                   : FNM_EXTMATCH))
        vectobj.push_back(ob);
    }
  return makeset_BM(vectobj.data(), vectobj.size());
} // end setofmatchednamedobjects_BM

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
  ASSERT_BM (mapglobals_BM.find(#Gnam)		\
	  == mapglobals_BM.end());		\
  mapglobals_BM[#Gnam] = &GLOBAL_BM(Gnam);	\
} while(0);
#include "_genbm_global.h"
} // end of initialize_globals_BM

void
gcmarkglobals_BM(struct garbcoll_stBM*gc)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  for (auto it: mapglobals_BM)
    if (it.second && *it.second)
      gcobjmark_BM(gc, *it.second);
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



bool
open_module_for_loader_BM (const rawid_tyBM modid, struct loader_stBM*ld, struct  stackframe_stBM *stkf)
{
  struct thisframe
  {
    STACKFRAMEFIELDS_BM;
    objectval_tyBM* modulob;
    value_tyBM moduldata;
  } _;
  memset ((void*)&_, 0, sizeof(_));
  _.stkfram_pA.htyp = typayl_StackFrame_BM;
  _.stkfram_pA.rlen = (sizeof(_) - sizeof(struct emptystackframe_stBM))/sizeof(value_tyBM);
  _.stkfram_prev = stkf;
  ASSERT_BM (ld && ld->ld_magic == LOADERMAGIC_BM);
  if (modid.id_hi == 0) return false;
  char modidbuf[32];
  memset (modidbuf, 0, sizeof(modidbuf));
  idtocbuf32_BM(modid, modidbuf);

  std::string srcmodpath = //
    std::string{bismon_directory} + "/" + MODULESRCDIR_BM + "/" + MODULEPREFIX_BM + modidbuf + ".c";
  std::string binmodpath =  //
    std::string{bismon_directory} + "/" + MODULEBINDIR_BM + "/" + MODULEPREFIX_BM + modidbuf   + ".so";
  DBGPRINTF_BM("open_module_for_loader_BM modidbuf:%s srcmodpath:%s binmodpath:%s",
               modidbuf, srcmodpath.c_str(),
               binmodpath.c_str());
  struct stat srcmodstat = {};
  struct stat binmodstat = {};
  if (::stat(srcmodpath.c_str(), &srcmodstat))
    {
      WARNPRINTF_BM("missing module source %s (%m)\n", srcmodpath.c_str());
      return false;
    }
  bool shouldrebuild = false;
  if (::stat(binmodpath.c_str(), &binmodstat))
    {
      WARNPRINTF_BM("missing module binary %s (%m) related to module source %s\n",
                    binmodpath.c_str(), srcmodpath.c_str());
      shouldrebuild = true;
    }
  else if (srcmodstat.st_mtime > binmodstat.st_mtime)
    {
      WARNPRINTF_BM("Bismon module binary %s is older than module source %s by %ld seconds\n",
                    binmodpath.c_str(), srcmodpath.c_str(),
                    (unsigned long)(srcmodstat.st_mtime - binmodstat.st_mtime));
      /// run a safe ls -l command,assume GNU coreutils ls(1)...
      std::string lscmdstr = "/bin/ls -lst --time-style=long-iso ";
      ASSERT_BM (binmodpath.c_str() != nullptr);
      gchar* quotbinmodcstr = g_shell_quote(binmodpath.c_str());
      ASSERT_BM (quotbinmodcstr != nullptr);
      lscmdstr += std::string(quotbinmodcstr);
      lscmdstr += " ";
      ASSERT_BM (srcmodpath.c_str() != nullptr);
      gchar* quotsrcmodcstr = g_shell_quote(srcmodpath.c_str());
      ASSERT_BM (quotsrcmodcstr != nullptr);
      lscmdstr += std::string(quotsrcmodcstr);
      lscmdstr += " > /dev/stderr";
      DBGPRINTF_BM("lscmdstr: %s", lscmdstr.c_str());
      fflush(nullptr);
      if (system (lscmdstr.c_str()))
        FATAL_BM("failed command %s", lscmdstr.c_str());
      g_free(quotbinmodcstr), quotbinmodcstr=nullptr;
      g_free(quotsrcmodcstr), quotsrcmodcstr=nullptr;
      shouldrebuild = true;
    };
  if (shouldrebuild)
    {
      INFOPRINTF_BM("before running %s/persistent-module-build-bismon.sh %s",
                    bismon_directory, modidbuf);
      fflush(nullptr);
      usleep (32768);
      std::string buildcmd{bismon_directory};
      buildcmd += "/persistent-module-build-bismon.sh ";
      buildcmd += modidbuf;
      int buildret = system(buildcmd.c_str());
      if (buildret)
        {
          WARNPRINTF_BM("module build %s failed with %d",
                        buildcmd.c_str(), buildret);
          return false;
        }
      else if (!access(binmodpath.c_str(), R_OK))
        INFOPRINTF_BM("module of id %s was successfully compiled to binary %s",
                      modidbuf, binmodpath.c_str());
      else
        FATAL_BM("unexpected failure of %s to build %s", buildcmd.c_str(), binmodpath.c_str());
      if (::stat(binmodpath.c_str(), &binmodstat))
        FATAL_BM("unexpected stat failure of %s (%m) after module build", binmodpath.c_str());
    }
  if (modulemap_BM.find(modid) != modulemap_BM.end())
    {
      // module already loaded
      DBGPRINTF_BM("open_module_for_loader modid %s already loaded",
                   modidbuf);
      return true;
    }
  DBGBACKTRACEPRINTF_BM("open_module_for_loader before dlopen %s",
                        binmodpath.c_str());
  void*dlh = dlopen(binmodpath.c_str(), RTLD_NOW | RTLD_GLOBAL);
  if (!dlh)
    {
      WARNPRINTF_BM("module dlopen failure %s\n", dlerror());
      return false;
    }
  DBGPRINTF_BM("open_module_for_loader dlsym-ing module_id_BM in dlh@%p for %s",
               dlh, binmodpath.c_str());
  const char*modidad = (const char*)dlsym(dlh,"module_id_BM");
  if (!modidad || strcmp(modidad,modidbuf))
    {
      WARNPRINTF_BM("bad module_id_BM in %s : %s\n",
                    binmodpath.c_str(), (modidad?"modid mismatch":dlerror()));
      dlclose(dlh);
      return false;
    }
  objectval_tyBM* objmod = makeobjofid_BM(modid);
  if (!objmod)
    {
      WARNPRINTF_BM("no object for module %s\n", modidbuf);
      dlclose(dlh);
      return false;
    }
  _.modulob = objmod;
  {
    char cwdbuf[128];
    memset(cwdbuf, 0, sizeof(cwdbuf));
    if (getcwd(cwdbuf, sizeof(cwdbuf)-1))
      INFOPRINTF_BM("open_module_for_loader module %s dlopened %s from %s",
                    objectdbg_BM(_.modulob), binmodpath.c_str(), cwdbuf);
    else
      INFOPRINTF_BM("open_module_for_loader module %s dlopened %s",
                    objectdbg_BM(_.modulob), binmodpath.c_str());
  }
  ld->ld_modhset = hashsetobj_add_BM(ld->ld_modhset, objmod);
  (void) modulemap_BM.insert({modid,ModuleData_BM{.mod_id=modid, .mod_dlh=dlh, .mod_obj=_.modulob, .mod_data=nullptr}});
  ////
  const closure_tyBM*closloadm = makeclosure1_BM (BMP_load_module, _.modulob);
  DBGPRINTF_BM("open_module_for_loader closloadm %s", OUTSTRVALUE_BM((void*)closloadm));
  load_addtodo_BM (closloadm);
  ld->ld_nbmodules++;
  return true;
} // end of open_module_for_loader_BM



extern "C" void postpone_loader_module_BM (objectval_tyBM*modulob, struct stackframe_stBM * stkf);

extern "C" void deferred_do_module_dynload_BM (value_tyBM * valarr, unsigned nbval, void *data);

/// called only indirectly thru agenda defer mechanism, see defer_module_dynload_BM
void deferred_do_module_dynload_BM (value_tyBM * valarr, unsigned nbval, void *data)
{
  struct thisframe
  {
    STACKFRAMEFIELDS_BM;
    objectval_tyBM* modulob;
    const closure_tyBM* postclos;
    value_tyBM arg1v; //
    value_tyBM arg2v; //
    value_tyBM arg3v; //
    value_tyBM modresv; //
    value_tyBM appresv; //
  } _;
  memset ((void*)&_, 0, sizeof(_));
  _.stkfram_pA.htyp = typayl_StackFrame_BM;
  _.stkfram_pA.rlen = (sizeof(_) - sizeof(struct emptystackframe_stBM))/sizeof(value_tyBM);
  _.stkfram_prev = NULL;
  ASSERT_BM(nbval == 5);
  ASSERT_BM(valarr != NULL);
  ASSERT_BM(data != NULL);
  char*binmodulpath = (char*)data;
  _.modulob = objectcast_BM(valarr[0]);
  _.postclos = closurecast_BM(valarr[1]);
  _.arg1v = valarr[2];
  _.arg2v = valarr[3];
  _.arg3v = valarr[4];
  char modulidbuf[32];
  memset (modulidbuf, 0, sizeof (modulidbuf));
  idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
  DBGBACKTRACEPRINTF_BM("deferred_do_module_dynload modulob=%s/%s postclos=%s" //
                        " arg1=%s arg2=%s arg3=%s binmodulpath=%s",
                        objectdbg_BM(_.modulob), modulidbuf,
                        OUTSTRVALUE_BM((value_tyBM)_.postclos),
                        OUTSTRVALUE_BM(_.arg1v),
                        OUTSTRVALUE_BM(_.arg2v),
                        OUTSTRVALUE_BM(_.arg3v),
                        binmodulpath);
  if (!strstr(binmodulpath, modulidbuf))
    FATAL_BM("bad binary module path %s for %s /%s", binmodulpath, objectdbg_BM(_.modulob), modulidbuf);
  DBGPRINTF_BM("deferred_do_module_dynload before dlopen %s", binmodulpath);
  void*dlh = dlopen(binmodulpath, RTLD_NOW | RTLD_GLOBAL);
  if (!dlh)
    FATAL_BM("module %s dlopen failed for %s : %s", binmodulpath, objectdbg_BM(_.modulob), dlerror());
  DBGPRINTF_BM("deferred_do_module_dynload dlsym-ing module_id_BM in dlh@%p for %s", dlh, binmodulpath);
  const char*modidad = (const char*)dlsym(dlh,"module_id_BM");
  if (!modidad || strcmp(modidad,modulidbuf))
    FATAL_BM("bad module_id_BM in %s for %s: %s",
             binmodulpath,  objectdbg_BM(_.modulob), (modidad?"modid mismatch":dlerror()));
  modulemap_BM.insert({objid_BM (_.modulob),ModuleData_BM{.mod_id=objid_BM (_.modulob), .mod_dlh=dlh, .mod_obj=_.modulob, .mod_data=nullptr}});
  INFOPRINTF_BM("deferred_do_module_dynload modulob=%s binmodulpath='%s'",
                objectdbg_BM(_.modulob), binmodulpath);
  char modulinitname[48];
  memset (modulinitname, 0, sizeof(modulinitname));
  snprintf(modulinitname, sizeof(modulinitname),
           MODULEINITPREFIX_BM "%s" MODULEINITSUFFIX_BM,
           modulidbuf);
  DBGPRINTF_BM("deferred_do_module_dynload dlsym-ing '%s' in dlh@%p for %s",
               modulinitname, dlh, binmodulpath);
  moduleinit_sigBM*modinitr = (moduleinit_sigBM*)dlsym(dlh, modulinitname);
  if (!modinitr)
    FATAL_BM("deferred_do_module_dynload: missing module initializer %s in %s: %s\n",
             modulinitname, objectdbg_BM(_.modulob), dlerror());
  DBGBACKTRACEPRINTF_BM("deferred_do_module_dynload dlsym-ed modulinitname=%s modinitr@%p", modulinitname, (void*)modinitr);
  _.modresv = (*modinitr) (CURFRAME_BM, BMP_dynload_module, _.modulob, nullptr, dlh);
  DBGPRINTF_BM("deferred_do_module_dynload after moduleinit of modulob=%s modresv=%s",
               objectdbg_BM(_.modulob), OUTSTRVALUE_BM(_.modresv));
  binmodulpath[0] = (char)0;
  free (binmodulpath), binmodulpath = NULL;
  DBGPRINTF_BM("deferred_do_module_dynload before deferapply postclos=%s" //
               " arg1=%s arg2=%s arg3=%s",
               OUTSTRVALUE_BM((value_tyBM)_.postclos),
               OUTSTRVALUE_BM(_.arg1v),
               OUTSTRVALUE_BM(_.arg2v),
               OUTSTRVALUE_BM(_.arg3v));
  do_main_defer_apply3_BM((value_tyBM)_.postclos, _.arg1v, _.arg2v, _.arg3v, CURFRAME_BM);
  DBGBACKTRACEPRINTF_BM("deferred_do_module_dynload ending after deferapply postclos=%s" //
                        " arg1=%s arg2=%s arg3=%s\n",
                        OUTSTRVALUE_BM((value_tyBM)_.postclos),
                        OUTSTRVALUE_BM(_.arg1v),
                        OUTSTRVALUE_BM(_.arg2v),
                        OUTSTRVALUE_BM(_.arg3v));
} // end deferred_do_module_dynload_BM


void postpone_loader_module_BM (objectval_tyBM*modulobarg, struct stackframe_stBM * stkf) // called from load_module routine
{
  struct thisframe
  {
    STACKFRAMEFIELDS_BM;
    objectval_tyBM* modulob;
    value_tyBM appresv; //
    value_tyBM modresv; //
  } _;
  memset ((void*)&_, 0, sizeof(_));
  _.stkfram_pA.htyp = typayl_StackFrame_BM;
  _.stkfram_pA.rlen = (sizeof(_) - sizeof(struct emptystackframe_stBM))/sizeof(value_tyBM);
  _.stkfram_prev = stkf;
  _.modulob = objectcast_BM(modulobarg);
  DBGPRINTF_BM("postpone_loader_module start modulob %s", objectdbg_BM(_.modulob));
  char modulidbuf[32];
  memset (modulidbuf, 0, sizeof(modulidbuf));
  idtocbuf32_BM (objid_BM (_.modulob), modulidbuf);
  auto it = modulemap_BM.find(objid_BM (_.modulob));
  ASSERT_BM(it != modulemap_BM.end());
  void*dlh = it->second.mod_dlh;
  ASSERT_BM(dlh != nullptr);
  char modulinitname[48];
  memset (modulinitname, 0, sizeof(modulinitname));
  snprintf(modulinitname, sizeof(modulinitname),
           MODULEINITPREFIX_BM "%s" MODULEINITSUFFIX_BM,
           modulidbuf);
  DBGPRINTF_BM("postpone_loader_module modulob %s dlsym-ing modulinitname %s in dlh@%p",
               objectdbg_BM(_.modulob), modulinitname, (void*)dlh);
  moduleinit_sigBM*modinitr = (moduleinit_sigBM*)dlsym(dlh, modulinitname);
  if (!modinitr)
    FATAL_BM("postpone_loader_module: missing module initializer %s in %s: %s\n",
             modulinitname, objectdbg_BM(_.modulob), dlerror());
  DBGBACKTRACEPRINTF_BM("postpone_loader_module modulob %s/%s before calling %s",
                        objectdbg_BM(_.modulob),
                        modulidbuf,
                        modulinitname);
  _.modresv = (*modinitr) (CURFRAME_BM, BMP_load_module, nullptr, nullptr, dlh);
  ASSERT_BM(_.modresv != nullptr);
  it->second.mod_data = _.modresv;
  DBGPRINTF_BM("postpone_loader_module end modulob %s modresv %s",
               objectdbg_BM(_.modulob),
               debug_outstr_value_BM(_.modresv, CURFRAME_BM, 0));
} // end postpone_loader_module_BM




void gcmarkmodules_BM(struct garbcoll_stBM*gc)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  for (auto it: modulemap_BM)
    {
      gcobjmark_BM(gc, it.second.mod_obj);
      VALUEGCPROC_BM(gc, it.second.mod_data, 0);
    }
} // end gcmarkmodules_BM
////////////////////////////////////////////////////////////////

typedef std::map<stringval_tyBM*,value_tyBM,ValStringLess_BM> dictmap_claBM;

struct dict_stBM*
dictmake_BM(void)
{
  struct dict_stBM*dict = //
    (struct dict_stBM*)allocgcty_BM(typayl_dict_BM, sizeof(struct dict_stBM));
  static_assert (sizeof (dict->dict_data) >= sizeof(dictmap_claBM), "too small dictdata");
  static_assert (alignof (dict->dict_data) >= alignof(dictmap_claBM), "too small dictdata");
  new(dict->dict_data) dictmap_claBM();
  return dict;
} // end dictmake_BM


void
dictgcmark_BM(struct garbcoll_stBM *gc, struct dict_stBM*dict,
              objectval_tyBM* fromob, int depth)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (isdict_BM (dict));
  ASSERT_BM (!fromob || isobject_BM(fromob));
  uint8_t oldmark = ((typedhead_tyBM *) dict)->hgc;
  if (oldmark)
    return;
  ((typedhead_tyBM *)dict)->hgc = MARKGC_BM;
  auto& dicm = *(dictmap_claBM*)dict->dict_data;
  for (auto& it : dicm)
    {
      VALUEGCPROC_BM(gc, *(void**) &it.first, depth+1);
      VALUEGCPROC_BM(gc, *(void**) &it.second, depth+1);
    }
} // end dictgcmark_BM


void dictgcdestroy_BM (struct garbcoll_stBM *gc, struct dict_stBM*dict)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (isdict_BM (dict));
  auto& dicm = *(dictmap_claBM*)dict->dict_data;
  size_t siz = dicm.size();
  dicm.clear();
  dicm.~dictmap_claBM();
  gc->gc_freedbytes += sizeof(*dict) + siz*2*sizeof(void*);
  memset(dict, 0, sizeof(*dict));
  free (dict);
} // end dictgcdestroy_BM


void dictgckeep_BM (struct garbcoll_stBM *gc, struct dict_stBM*dict)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  ASSERT_BM (isdict_BM (dict));
  auto& dicm = *(dictmap_claBM*)dict->dict_data;
  size_t siz = dicm.size();
  gc->gc_keptbytes += sizeof(*dict) + siz*2*sizeof(void*);
} // end dictgckeep_BM


value_tyBM
dictget_BM(const struct dict_stBM* dict, const stringval_tyBM*str)
{
  if (!isdict_BM((const value_tyBM)dict))
    return nullptr;
  if (!isstring_BM((const value_tyBM)str))
    return nullptr;
  auto& dicm = *(dictmap_claBM*)dict->dict_data;
  auto it = dicm.find(const_cast<stringval_tyBM*>(str));
  if (it == dicm.end()) return nullptr;
  return it->second;
} // end dictget_BM


unsigned
dictsize_BM(const struct dict_stBM* dict)
{
  if (!isdict_BM((const value_tyBM)dict))
    return 0;
  auto& dicm = *(dictmap_claBM*)dict->dict_data;
  return dicm.size();
} // end dictsize_BM


void dictput_BM(struct dict_stBM* dict, const stringval_tyBM*str, const value_tyBM val)
{
  if (!isdict_BM((const value_tyBM)dict))
    return;
  if (!isstring_BM((const value_tyBM)str))
    return;
  auto& dicm = *(dictmap_claBM*)dict->dict_data;
  if (dicm.size() > MAXSIZE_BM)
    FATAL_BM("too big dict %lu", (long) dicm.size());
  if (val) dicm.insert({const_cast<stringval_tyBM*>(str),(void*)val});
  else dicm.erase(const_cast<stringval_tyBM*>(str));
} // end dictput_BM


void dictremove_BM(struct dict_stBM* dict, const stringval_tyBM*str)
{
  if (!isdict_BM((const value_tyBM)dict))
    return;
  if (!isstring_BM((const value_tyBM)str))
    return;
  auto& dicm = *(dictmap_claBM*)dict->dict_data;
  dicm.erase(const_cast<stringval_tyBM*>(str));
} // end dictremove_BM

const stringval_tyBM*
dictfirstkey_BM(struct dict_stBM* dict)
{
  if (!isdict_BM((const value_tyBM)dict))
    return nullptr;
  auto& dicm = *(dictmap_claBM*)dict->dict_data;
  if (dicm.empty()) return nullptr;
  auto firstn = dicm.begin();
  return firstn->first;
} // end dictfirstkey_BM

const stringval_tyBM*
dictlastkey_BM(struct dict_stBM* dict)
{
  if (!isdict_BM((const value_tyBM)dict))
    return nullptr;
  auto& dicm = *(dictmap_claBM*)dict->dict_data;
  if (dicm.empty()) return nullptr;
  auto endn = dicm.end();
  endn--;
  return endn->first;
} // end dictlastkey_BM

const stringval_tyBM*
dictkeyafter_BM(struct dict_stBM* dict, const stringval_tyBM*str)
{
  if (!isdict_BM((const value_tyBM)dict))
    return nullptr;
  auto& dicm = *(dictmap_claBM*)dict->dict_data;
  if (!isstring_BM((const value_tyBM)str)
      || !bytstring_BM(str)[0])
    return nullptr;
  auto itn = dicm.upper_bound(const_cast<stringval_tyBM*>(str));
  if (itn != dicm.end())
    return itn->first;
  return nullptr;
} // end of dictkeyafter_BM


extern const stringval_tyBM*
dictkeysameorafter_BM(struct dict_stBM* dict, const stringval_tyBM*str)
{
  if (!isdict_BM((const value_tyBM)dict))
    return nullptr;
  auto& dicm = *(dictmap_claBM*)dict->dict_data;
  if (!isstring_BM((const value_tyBM)str)
      || !bytstring_BM(str)[0])
    return nullptr;
  auto itn = dicm.lower_bound(const_cast<stringval_tyBM*>(str));
  if (itn != dicm.end())
    return itn->first;
  return nullptr;
} // end of dictkeysameorafter_BM

const stringval_tyBM*
dictkeybefore_BM(struct dict_stBM* dict, const stringval_tyBM*str)
{
  if (!isdict_BM((const value_tyBM)dict))
    return nullptr;
  auto& dicm = *(dictmap_claBM*)dict->dict_data;
  if (!isstring_BM((const value_tyBM)str)
      || !bytstring_BM(str)[0])
    return nullptr;
  auto itn = dicm.lower_bound(const_cast<stringval_tyBM*>(str));
  if (itn != dicm.begin())
    itn--;
  else
    return nullptr;
  if (itn != dicm.end())
    return itn->first;
  return nullptr;
} // end dictkeybefore_BM

const node_tyBM*
dictnodeofkeys_BM(struct dict_stBM* dict, const objectval_tyBM*obj)
{
  if (!isdict_BM((const value_tyBM)dict))
    return nullptr;
  if (!isobject_BM((const value_tyBM)obj))
    return nullptr;
  auto& dicm = *(dictmap_claBM*)dict->dict_data;
  value_tyBM*arr = (value_tyBM*) calloc(dicm.size(), sizeof(value_tyBM));
  if (!arr) FATAL_BM("calloc failure for %u keys", (unsigned) dicm.size());
  int cnt = 0;
  for (auto it : dicm)
    {
      arr[cnt++] = (value_tyBM)it.first;
    }
  const node_tyBM* nodv = makenode_BM(obj, cnt, arr);
  free (arr);
  return nodv;
} // end dictnodeofkeys_BM

////////////////////////////////////////////////////////////////
/// some support for doubles
/// compare of double-s inside boxed doubles, so they cannot be NaN
int doublecmp_BM(double x, double y)
{
  if (std::isnan(x) || std::isnan(y) || std::isunordered(x,y))
    FATAL_BM("doublecmp_BM with Not-a-number x=%g y=%g", x,y);
  /// IEEE 754 distinguishes +0.0 from -0.0, but they compare equal
  if (x==y)
    {
      bool signx = std::signbit(x), signy = std::signbit(y);
      if (signx != signy) return signx ? -1 /* x <= 0 && y >= 0 */ : +1;
      return 0;
    };
  if (x<y) return -1;
  if (x>y) return +1;
  // this should never be reached
  FATAL_BM("doublecmp_BM fail to compare x=%g, y=%g", x, y);
} // end doublecmp_BM

hash_tyBM doublehash_BM (double x)
{
  std::size_t hs = std::hash<double> {}(x);
  hash_tyBM h = (hash_tyBM) hs;
  if (h == 0)
    {
      h = hs % 12001057;
      if (h == 0)
        h = 1051079;
    }
  return h;
} // end doublehash_BM

////////////////////////////////////////////////////////////////
/****** support for command window and paren blinking ******/

static std::map<int,parenoffset_stBM> cmd_openmap_BM;
static std::map<int,parenoffset_stBM> cmd_closemap_BM;

void
cmd_clear_parens_BM(void)
{
  cmd_openmap_BM.clear();
  cmd_closemap_BM.clear();
} // end cmd_clear_parens_BM


void
cmd_add_parens_BM (struct parenoffset_stBM*par)
{
  ASSERT_BM (par != nullptr);
  cmd_openmap_BM.insert({par->paroff_open,*par});
  cmd_closemap_BM.insert({par->paroff_close,*par});
} // end cmd_add_parens_BM

bool
parens_surrounds_BM(struct parenoffset_stBM*par, int off)
{
  if (!par)
    return false;
  /// when ( ^ ) or [ ^ ] or { ^ }
  if (par->paroff_open <= off && off <= par->paroff_close)
    return true;
  /// when * conn ^ ( ... )
  if (par->paroff_xtralen > 0 && par->paroff_xtra >= 0 && par->paroff_xtra <= off
      && off <= par->paroff_open && par->paroff_xtra < par->paroff_open)
    return true;
  return false;
} // end cmd_parens_surrounds_BM

struct parenoffset_stBM*
cmd_find_enclosing_parens_BM(int off)
{
  // we probably might code something faster, but is it worth the hassle?
  if (cmd_closemap_BM.empty())
    return nullptr;
  auto it = cmd_closemap_BM.lower_bound (off);
  if (it == cmd_closemap_BM.end())
    return nullptr;
  do
    {
      struct parenoffset_stBM*po = &it->second;
      if (parens_surrounds_BM(po, off))
        return po;
      it--;
    }
  while (it != cmd_closemap_BM.begin());
  return nullptr;
} // end cmd_find_enclosing_parens_BM


////////////////////////////////////////////////////////////////

struct deferdoappl_stBM
{
  union
  {
    value_tyBM defer_fun;
    objectval_tyBM* defer_obsel;
  };
  value_tyBM defer_recv;
  value_tyBM defer_arg1;
  value_tyBM defer_arg2;
  value_tyBM defer_arg3;
};
static std::deque<deferdoappl_stBM> deferdeque_BM;
static std::mutex deferqmtx_BM;

void
gcmarkdefer_BM(struct garbcoll_stBM*gc)
{
  ASSERT_BM (gc && gc->gc_magic == GCMAGIC_BM);
  std::lock_guard<std::mutex> _g(deferqmtx_BM);
  for (auto itd : deferdeque_BM)
    {
      if (itd.defer_recv)
        {
          VALUEGCPROC_BM (gc, itd.defer_fun, 0);
          gcobjmark_BM(gc, itd.defer_obsel);
        }
      else
        VALUEGCPROC_BM (gc, itd.defer_fun, 0);
      if (itd.defer_arg1)
        VALUEGCPROC_BM (gc, itd.defer_arg1, 0);
      if (itd.defer_arg2)
        VALUEGCPROC_BM (gc, itd.defer_arg2, 0);
      if (itd.defer_arg3)
        VALUEGCPROC_BM (gc, itd.defer_arg3, 0);
    }
} // end gcmarkdefer_BM



extern "C" void
do_internal_deferred_send3_BM(value_tyBM recv, objectval_tyBM*obsel, value_tyBM arg1, value_tyBM arg2, value_tyBM arg3);

extern "C" void
do_internal_deferred_apply3_BM(value_tyBM fun, value_tyBM arg1, value_tyBM arg2, value_tyBM arg3);

extern "C" bool did_deferred_BM (void);

bool
did_deferred_BM (void)
{
  value_tyBM dfunv = nullptr;
  objectval_tyBM* dobsel = nullptr;
  value_tyBM darg1v = nullptr;
  value_tyBM darg2v = nullptr;
  value_tyBM darg3v = nullptr;
  value_tyBM drecv = nullptr;
  NONPRINTF_BM("did_deferred_BM start tid#%ld elapsed %.3f s",
               (long)gettid_BM(), elapsedtime_BM());
  {
    std::lock_guard<std::mutex> _g(deferqmtx_BM);
    if (deferdeque_BM.empty())
      {
        NONPRINTF_BM("did_deferred_BM empty tid#%ld",
                     (long)gettid_BM());
        return false;
      }
    auto f = deferdeque_BM.front();
    if (f.defer_recv)
      {
        drecv = f.defer_recv;
        dobsel = f.defer_obsel;
      }
    else
      {
        dfunv = f.defer_fun;
        drecv = nullptr;
      };
    darg1v = f.defer_arg1;
    darg2v = f.defer_arg2;
    darg3v = f.defer_arg3;
    deferdeque_BM.pop_front();
  }
  NONPRINTF_BM("did_deferred_BM tid#%ld before dointernal",
               (long)gettid_BM());
  if (drecv)
    do_internal_deferred_send3_BM(drecv, dobsel, darg1v, darg2v, darg3v);
  else
    do_internal_deferred_apply3_BM(dfunv, darg1v, darg2v, darg3v);
  NONPRINTF_BM("did_deferred_BM tid#%ld end",
               (long)gettid_BM());
  return true;
} // end did_deferred_BM




////////////////////////////////////////////////////////////////

extern "C" void add_defer_command_onion_BM (void);

#ifdef BISMONGTK
extern "C" void add_defer_command_gtk_BM (void);
#endif /*BISMONGTK*/

////////////////
void
do_main_defer_apply3_BM (value_tyBM funv, value_tyBM arg1, value_tyBM arg2, value_tyBM arg3,
                         struct stackframe_stBM*stkf)
{
  struct thisframe
  {
    STACKFRAMEFIELDS_BM;
    value_tyBM funv;
    value_tyBM arg1;
    value_tyBM arg2;
    value_tyBM arg3;
  } _;
  memset ((void*)&_, 0, sizeof(_));
  _.stkfram_pA.htyp = typayl_StackFrame_BM;
  _.stkfram_pA.rlen = (sizeof(_) - sizeof(struct emptystackframe_stBM))/sizeof(value_tyBM);
  _.stkfram_prev = stkf;
  //
  _.funv = funv;
  _.arg1 = arg1;
  _.arg2 = arg2;
  _.arg3 = arg3;
  DBGBACKTRACEPRINTF_BM("do_main_defer_apply start tid#%ld funv %s arg1 %s arg2 %s arg3 %s",
                        (long)gettid_BM(),
                        OUTSTRVALUE_BM (_.funv), //
                        OUTSTRVALUE_BM (_.arg1), //
                        OUTSTRVALUE_BM (_.arg2), //
                        OUTSTRVALUE_BM (_.arg3) //
                       );
  if (!isclosure_BM(funv) && !isobject_BM(funv))
    {
      WARNPRINTF_BM("do_main_defer_apply bad funv %s, arg1=%s, arg2=%s, arg3=%s",
                    OUTSTRVALUE_BM (_.funv),
                    OUTSTRVALUE_BM (_.arg1),
                    OUTSTRVALUE_BM (_.arg2),
                    OUTSTRVALUE_BM (_.arg3));
      return;
    }
  {
    std::lock_guard<std::mutex> _g(deferqmtx_BM);
    struct deferdoappl_stBM dap = {};
    dap.defer_fun = _.funv;
    dap.defer_recv = nullptr;
    dap.defer_arg1 = arg1;
    dap.defer_arg2 = arg2;
    dap.defer_arg3 = arg3;
    deferdeque_BM.emplace_back(dap);
  }
  DBGPRINTF_BM("do_main_defer_apply elapsed %.3f s", elapsedtime_BM());
  ////
  if (bismon_has_web_BM())
    add_defer_command_onion_BM ();
#if defined (BISMONGTK)
  if (bismon_has_gui_BM())
    add_defer_command_gtk_BM ();
#endif /* or BISMONGTK*/
  ////
  DBGPRINTF_BM("do_main_defer_apply end tid#%ld funv %s arg1 %s arg2 %s arg3 %s",
               (long)gettid_BM(),
               OUTSTRVALUE_BM (_.funv), //
               OUTSTRVALUE_BM (_.arg1), //
               OUTSTRVALUE_BM (_.arg2), //
               OUTSTRVALUE_BM (_.arg3) //
              );
} // end do_main_defer_apply3_BM


void
do_main_defer_send3_BM(value_tyBM recv, objectval_tyBM*obsel,  value_tyBM arg1, value_tyBM arg2, value_tyBM arg3)
{
  if (!recv) return;
  if (!isobject_BM(obsel)) return;
  {
    std::lock_guard<std::mutex> _g(deferqmtx_BM);
    struct deferdoappl_stBM dap = {};
    dap.defer_obsel = obsel;
    dap.defer_recv = recv;
    dap.defer_arg1 = arg1;
    dap.defer_arg2 = arg2;
    dap.defer_arg3 = arg3;
    deferdeque_BM.emplace_back(dap);
  }
  ////
  add_defer_command_onion_BM ();
#if defined (BISMONGTK)
  add_defer_command_gtk_BM ();
#endif /*BISMONGTK*/
} // end of do_main_defer_send3_BM

////////////////

void initialize_failurelockset_BM(struct failurelockset_stBM *fs, size_t sz)
{
  if (sz < sizeof(*fs))
    FATAL_BM("initialize_failurelockset_BM too small size %zd want %zd",
             sz, sizeof(*fs));
  new ((void*)fs) failurelockset_stBM;
} // end initialize_failurelockset_BM

void destroy_failurelockset_BM(struct failurelockset_stBM *fs)
{
  fs->~failurelockset_stBM();
} // end destroy_failurelockset_BM

void
register_failock_BM(struct failurelockset_stBM*flh, objectval_tyBM*ob)
{
  ASSERT_BM (flh != nullptr);
  ASSERT_BM (isobject_BM(ob));
  flh->flhobjset.insert(ob);
} // end register_failock_BM

void
unregister_failock_BM(struct failurelockset_stBM*flh, objectval_tyBM* ob)
{
  ASSERT_BM (flh != nullptr);
  ASSERT_BM (isobject_BM(ob));
  flh->flhobjset.erase(ob);
} // end unregister_failock_BM



// make valgrind happy for C++ data here
void
final_miscdata_cleanup_BM (void)
{
  {
    std::vector<const char*> namevec;
    namevec.reserve(namemap_BM.size()+1);
    for (auto it : namemap_BM)
      namevec.push_back(it.first);
    namemap_BM.clear();
    objhashtable_BM.clear();
    for (const char*ptr : namevec)
      free ((void*)ptr);
  }
  namemap_BM = typeof(namemap_BM) {};
  objhashtable_BM = typeof(objhashtable_BM) {};
  {
    std::vector<std::pair<void*, rawid_tyBM>> vecmodu;
    vecmodu.reserve(modulemap_BM.size());
    for (auto modit : modulemap_BM)
      {
        rawid_tyBM modid = modit.first;
        ModuleData_BM& modata = modit.second;
        ASSERT_BM(equalid_BM(modid, modata.mod_id));
        void*modlh = modata.mod_dlh;
        if (modlh) vecmodu.push_back({modlh,modid});
        modata.mod_dlh = nullptr;
        modata.mod_obj = nullptr;
        modata.mod_data = nullptr;
      }
    modulemap_BM.clear();
    modulemap_BM = typeof(modulemap_BM) {};
    int modcnt = 0;
    for (auto it: vecmodu)
      {
        void* dlh = it.first;
        rawid_tyBM modit = it.second;
        if (dlclose(dlh))
          {
            char modidbuf[32];
            memset (modidbuf, 0, sizeof(modidbuf));
            idtocbuf32_BM(modit, modidbuf);
            WARNPRINTF_BM("dlclose of %p (module %s) failed: %s", dlh, modidbuf, dlerror());
          }
        else modcnt++;
      }
    INFOPRINTF_BM("dlclosed %d modules", modcnt);
  }
} // end final_miscdata_cleanup_BM

// end of file misc_BM.cc
