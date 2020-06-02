
/**
    BISMON related GCC8 plugin gcc8plugin-demo-chariot-2019Q2.cc
    Copyright © 2019 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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

**/

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

#include <cstdio>
#include <cassert>

#include <unistd.h>
#include <time.h>
#include <math.h>

#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>


#include <curl/curl.h>


#include "gcc-plugin.h"
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "stringpool.h"
#include "toplev.h"
#include "basic-block.h"
#include "hash-table.h"
#include "vec.h"
#include "ggc.h"
#include "basic-block.h"
#include "tree-ssa-alias.h"
#include "internal-fn.h"
#include "gimple-fold.h"
#include "tree-eh.h"
#include "gimple-expr.h"
#include "is-a.h"
#include "gimple.h"
#include "gimple-iterator.h"
#include "tree.h"
#include "tree-pass.h"
#include "toplev.h"
#include "intl.h"
#include "plugin-version.h"
#include "diagnostic.h"
#include "context.h"



int plugin_is_GPL_compatible;

#ifdef PLUGINGITID
const char chariot_plugin_gitid[] = PLUGINGITID;
#pragma message "plugin has gitid " PLUGINGITID
#endif

////////////////////////////////////////////////////////////////
// our global variables

std::unordered_map<tree,function*> chariot_map_decl_to_fun;
void chariot_ggc_marker_callback(void*,void*);

class Func_chariot_data
{
  friend void chariot_ggc_marker_callback(void*,void*);
  int _chfun_rank;
  function* _chfun_func;
  std::unordered_set<tree> _chfun_calleeset;
  static int _chfun_count;
public:
  Func_chariot_data(function*curfun):
    _chfun_rank (++_chfun_count),
    _chfun_func(curfun),
    _chfun_calleeset()
  {
    assert (curfun != nullptr);
  };
  ~Func_chariot_data()
  {
    _chfun_func=nullptr;
    _chfun_rank=0;
  };
  Func_chariot_data(const Func_chariot_data&) = default;
  Func_chariot_data(Func_chariot_data&&) = default;
};

int Func_chariot_data::_chfun_count;
std::unordered_map<function*,Func_chariot_data> chariot_map_func_to_data;

std::string chariot_bismoncookiestr;

std::string chariot_bismonurlprefixstr;

std::string chariot_bismonprojectstr;

std::string chariot_translationunitstr;

bool chariot_show_http;

bool chariot_faking;

CURL* chariot_curl;

int chariot_timeout_millisec = 1600;

////////////////////////////////////////////////////////////////
/// the marking routine
void chariot_ggc_marker_callback(void*,void*)
{
  for (auto it : chariot_map_decl_to_fun)
    {
      tree tr = it.first;
      function* fun = it.second;
      ggc_mark(tr);
      ggc_mark(fun);
    }
  for (auto itd : chariot_map_func_to_data)
    {
      function* fun = itd.first;
      Func_chariot_data* cda = &itd.second;
      ggc_mark(fun);
      ggc_mark(cda->_chfun_func);
      assert (fun == cda->_chfun_func);
      for (auto itc : cda->_chfun_calleeset)
        {
          tree tr = itc;
          ggc_mark(tr);
        }
    }
} // end chariot_ggc_marker_callback


// give elapsed process CPU time in seconds
double
chariot_cputime(void)
{
  struct timespec ts = {0,0};
  if (clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts))
    return NAN;
  return (double) ts.tv_sec + 1.0e-9*ts.tv_nsec;
} // end chariot_cputime



/// GCC callback which gets called before processing a translation unit
void
chariot_starting(void*gccdata __attribute__((unused)), void*userdata __attribute((unused)))
{
  char cputimbuf[32];
  memset (cputimbuf, 0, sizeof(cputimbuf));
  snprintf(cputimbuf, sizeof (cputimbuf), "%.3f s", chariot_cputime());
  inform(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO: ****starting project %s translunit %s, cputime %s (l@%d)",
         chariot_bismonprojectstr.c_str(),
         chariot_translationunitstr.c_str(),
         cputimbuf, __LINE__);
} // end chariot_starting


/// GCC callback which gets called near end, and may be useful for summary processing.
void
chariot_finishing(void*gccdata __attribute__((unused)), void*userdata __attribute((unused)))
{
  char cputimbuf[32];
  memset (cputimbuf, 0, sizeof(cputimbuf));
  snprintf(cputimbuf, sizeof (cputimbuf), "%.3f s", chariot_cputime());
  inform(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO: ****finishing project %s translunit %s, cputime %s (l@%d)",
         chariot_bismonprojectstr.c_str(),
         chariot_translationunitstr.c_str(),
         cputimbuf, __LINE__);
} // end chariot_finishing

////////////////////////////////////////////////////////////////
/// low-level routine to make an HTTP REST POST call to Bismon using
/// libcurl; a bit long, but trivial to understand.
void chariot_bismon_post_restcall(const char*urlsuffix,
                                  Json::Value*jinput, Json::Value*joutput)
{
  // the suffix of the URL for all our REST POST requests, this is
  // known by the webdict_root object €_5pSDWgvxs of Bismon
  static long callnum;
  callnum++;
  // the suffix of the URL for all our REST POST requests
#define CHARIOTDEMO_URLSUFFIX "restchariot2q19"
  assert (urlsuffix != nullptr);
  std::string inputstr;
  if (jinput)
    {
      if (chariot_faking)
        {
          Json::StyledWriter jwri;
          inputstr = jwri.write(*jinput);
        }
      else
        {
          Json::FastWriter jfwri;
          inputstr = jfwri.write(*jinput);
        }
      inputstr.push_back('\n');
    }
  if (chariot_faking)
    {
      inform(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO: faking REST-http-call to %s **\n%s\n****", urlsuffix, inputstr.c_str());
    }
  else
    {
      struct curl_slist* list = NULL;
      assert(chariot_bismonurlprefixstr.back() == '/');
      std::string urlstr = chariot_bismonurlprefixstr;
      urlstr.append(CHARIOTDEMO_URLSUFFIX "/");
      urlstr.append(urlsuffix);
      if (chariot_show_http)
        inform(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO:: start REST POST HTTP request#%ld for %s ...\n***\n%s\n***\n",
               callnum, urlstr.c_str(), inputstr.c_str());
      CURLcode cc= CURLE_FAILED_INIT;
      /// CURLOPT_VERBOSE for verbosity
      cc = curl_easy_setopt(chariot_curl, CURLOPT_VERBOSE,
                            (long)chariot_show_http);
      if (cc != CURLE_OK)
        fatal_error(UNKNOWN_LOCATION,
                    "CHARIOTPLUGINDEMO: CURLOPT_VERBOSE failed (%s) #%d /%s",
                    chariot_show_http?"yes":"no",
                    cc, curl_easy_strerror(cc));
      /// CURLOPT_TIMEOUT_MS for the timeout delay
      cc = curl_easy_setopt(chariot_curl, CURLOPT_TIMEOUT_MS,
                            (long)chariot_timeout_millisec);
      if (cc != CURLE_OK)
        fatal_error(UNKNOWN_LOCATION,
                    "CHARIOTPLUGINDEMO: CURLOPT_TIMEOUT_MS failed (%d ms) #%d /%s",
                    chariot_timeout_millisec,
                    cc, curl_easy_strerror(cc));
      /// CURLOPT_URL for the URL
      cc = curl_easy_setopt(chariot_curl, CURLOPT_URL,
                            urlstr.c_str());
      if (cc != CURLE_OK)
        fatal_error(UNKNOWN_LOCATION,
                    "CHARIOTPLUGINDEMO: CURLOPT_URL '%s' failed #%d /%s",
                    urlstr.c_str(),
                    cc, curl_easy_strerror(cc));
      /// CURLOPT_POST to make a POST request
      cc = curl_easy_setopt(chariot_curl, CURLOPT_POST,
                            (long)1);
      if (cc != CURLE_OK)
        fatal_error(UNKNOWN_LOCATION,
                    "CHARIOTPLUGINDEMO: CURLOPT_POST failed #%d /%s",
                    cc, curl_easy_strerror(cc));
      /// CURLOPT_FAILONERROR to e.g. curl-fail on HTTP_NOT_FOUND
      cc = curl_easy_setopt(chariot_curl, CURLOPT_FAILONERROR,
                            (long)1);
      if (cc != CURLE_OK)
        fatal_error(UNKNOWN_LOCATION,
                    "CHARIOTPLUGINDEMO: CURLOPT_FAILONERROR failed #%d /%s",
                    cc, curl_easy_strerror(cc));
      /// cookie handling
      char cookiebuf[128];
      memset (cookiebuf, 0, sizeof(cookiebuf));
      if (!chariot_bismoncookiestr.empty())
        {
          /// CURLOPT_COOKIE for BISMONCOOKIE
          snprintf(cookiebuf, sizeof(cookiebuf), "BISMONCOOKIE=%s",
                   chariot_bismoncookiestr.c_str());
          cc = curl_easy_setopt(chariot_curl, CURLOPT_COOKIE, cookiebuf);
          if (cc != CURLE_OK)
            fatal_error(UNKNOWN_LOCATION,
                        "CHARIOTPLUGINDEMO: CURLOPT_COOKIE '%s' failed #%d /%s",
                        cookiebuf, cc, curl_easy_strerror(cc));
        }
      /// CURLOPT_USERAGENT set to  this C++ source file
      cc = curl_easy_setopt(chariot_curl, CURLOPT_USERAGENT, __FILE__);
      if (cc != CURLE_OK)
        fatal_error(UNKNOWN_LOCATION,
                    "CHARIOTPLUGINDEMO: CURLOPT_USERAGENT '%s' failed #%d /%s",
                    __FILE__, cc, curl_easy_strerror(cc));
      {
        /// curlopt_HTTPHEADER for application/json MIME type
        list = curl_slist_append(list, "Content-Type: application/json");
        cc= curl_easy_setopt (chariot_curl, CURLOPT_HTTPHEADER, list);
        if (cc != CURLE_OK)
          fatal_error(UNKNOWN_LOCATION,
                      "CHARIOTPLUGINDEMO: CURLOPT_HTTPHEADER failed #%d /%s",
                      cc, curl_easy_strerror(cc));
        /// CURLOPT_POSTFIELDS for the JSON input data to POST
        cc = curl_easy_setopt(chariot_curl, CURLOPT_POSTFIELDS,
                              inputstr.c_str());
        if (cc != CURLE_OK)
          fatal_error(UNKNOWN_LOCATION,
                      "CHARIOTPLUGINDEMO: CURLOPT_POSTFIELDS failed #%d /%s:\n%s\n",
                      cc, curl_easy_strerror(cc), inputstr.c_str());
      }
      /// CURLOPT_ERRORBUFFER
      char errbuf[CURL_ERROR_SIZE];
      memset (errbuf, 0, sizeof(errbuf));
      cc = curl_easy_setopt(chariot_curl, CURLOPT_ERRORBUFFER,
                            errbuf);
      if (cc != CURLE_OK)
        fatal_error(UNKNOWN_LOCATION,
                    "CHARIOTPLUGINDEMO: CURLOPT_ERRORBUFFER failed #%d /%s",
                    cc, curl_easy_strerror(cc));
      /// we create a FILE* handle to a buffer containing the result
      /// JSON and it will become the CURLOPT_WRITEDATA
      size_t respjsonsiz = 1024;
      char*respjsonbuf = (char*)xmalloc(respjsonsiz);
      if (!respjsonsiz)
        fatal_error(UNKNOWN_LOCATION,
                    "CHARIOTPLUGINDEMO: malloc %d failure for respjsonbuf",
                    (int) respjsonsiz);
      memset(respjsonbuf, 0, respjsonsiz);
      FILE* respfil = open_memstream(&respjsonbuf, &respjsonsiz);
      if (!respfil)
        fatal_error(UNKNOWN_LOCATION,
                    "CHARIOTPLUGINDEMO: open_memstream failure");
      cc = curl_easy_setopt(chariot_curl, CURLOPT_WRITEDATA,
                            respfil);
      if (cc != CURLE_OK)
        fatal_error(UNKNOWN_LOCATION,
                    "CHARIOTPLUGINDEMO: CURLOPT_WRITEDATA failed #%d /%s",
                    cc, curl_easy_strerror(cc));
      /// perform the HTTP POST request itself:
      cc = curl_easy_perform(chariot_curl);
      fputc('\n', respfil);
      fflush(respfil);
      long lnresp = ftell(respfil);
      if (cc != CURLE_OK)
        fatal_error(UNKNOWN_LOCATION,
                    "CHARIOTPLUGINDEMO: curl_easy_perform '%s' failed (with error: %s) for  #%d /%s; got %ld bytes:\n+++ %s +++\n",
                    urlsuffix, errbuf, cc, curl_easy_strerror(cc),
                    lnresp, respjsonbuf);
#warning incomplete chariot_bismon_post_restcall
      // TODO: check the HTTP resulting code.
      // probably unneeded, because of CURLOPT_FAILONERROR above
      /////////
      // parse the resulting JSON from respjsonbuf
      fputc('\n', respfil);
      fflush(respfil);
      respjsonbuf[lnresp] = (char)0;
      if (chariot_show_http)
        inform(UNKNOWN_LOCATION,
               "CHARIOTPLUGINDEMO:: done REST POST HTTP request#%ld for %s, got %ld bytes:\n***\n%s\n***",
               callnum, urlstr.c_str(), lnresp, respjsonbuf);
      /// decode the respjsonbuf as JSON
      Json::Reader jread(Json::Features::strictMode());
      Json::Value rootjs;
      if (!jread.parse(respjsonbuf, respjsonbuf+lnresp, rootjs, false))
        {
          warning(UNKNOWN_LOCATION,
                  "CHARIOTPLUGINDEMO: REST POST HTTP request#%ld for %s fails JSON decoding:\n***\n%s\n***\n",
                  callnum, urlstr.c_str(), jread.getFormattedErrorMessages().c_str());
        }
      else
        {
          if (chariot_show_http)
            inform(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO:: REST POST HTTP request#%ld for %s got:\n***\n%s\n***\n",
                   callnum, urlstr.c_str(), rootjs.toStyledString().c_str());
          if (joutput)
            *joutput = rootjs;
          else
            warning(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO: REST POST HTTP request#%ld for %s ignored",
                    callnum, urlstr.c_str());
        }
      /////////
      /// epilogue
      {
        free (respjsonbuf), respjsonbuf = NULL;
        respjsonsiz = 0;
        curl_slist_free_all(list);
        list = NULL;
        curl_easy_cleanup(chariot_curl);
      }
    }
} // end chariot_bismon_post_restcall





////////////////////////////////////////////////////////////////
//// the call graph related CHARIOT pass
const pass_data pass_data_chariot_callgraph =
{
  GIMPLE_PASS, /* type */
  "chariot_callgraph", /* name */
  OPTGROUP_NONE, /* optinfo_flags */
  TV_NONE, /* tv_id */
  PROP_ssa, /* properties_required */
  0, /* properties_provided */
  0, /* properties_destroyed */
  0, /* todo_flags_start */
  0, /* todo_flags_finish */
};

class pass_chariot_callgraph : public gimple_opt_pass
{
public:
  pass_chariot_callgraph(gcc::context *ctxt)
    : gimple_opt_pass(pass_data_chariot_callgraph, ctxt)
  {}

  /* opt_pass methods: */
  virtual unsigned int execute (function *);

}; // class pass_chariot_callgraph

unsigned int
pass_chariot_callgraph::execute (function *fun)
{
  gimple_stmt_iterator gsi;
  basic_block bb;
  int bbcount = 0;
  int stmtcount = 0;
  int nbcalls = 0;
  auto funstartloc = (fun && fun->function_start_locus)
                     ?  fun->function_start_locus
                     : UNKNOWN_LOCATION;
  auto funendloc = (fun && fun->function_end_locus)
                   ?  fun->function_end_locus
                   : UNKNOWN_LOCATION;
  inform (funstartloc,
          "CHARIOTPLUGINDEMO: callgraph start examining %qD @@ %s:%d",
          fun->decl, __FILE__, __LINE__);
  Func_chariot_data chdafun(fun);
  chariot_map_decl_to_fun.insert({fun->decl,fun});
  chariot_map_func_to_data.insert({fun,chdafun});
  usleep (1); // we could set a breakpoint here
  FOR_EACH_BB_FN (bb, fun)
  {
    bbcount++;
    for (gsi = gsi_start_bb (bb); !gsi_end_p (gsi); gsi_next (&gsi))
      {
        stmtcount++;
        auto curstmt = gsi_stmt(gsi);
        if (gimple_code(curstmt) == GIMPLE_CALL)
          {
            nbcalls++;
            tree callee = gimple_call_fndecl(curstmt);
            if (callee)
              inform(gimple_location(curstmt), "CHARIOTPLUGINDEMO: callgraph in %qD call to %qD",
                     fun->decl, callee);
            else
              warning(gimple_location(curstmt), "CHARIOTPLUGINDEMO: callgraph no callee in %qD", fun->decl);
          }
      };
  }
  inform(funstartloc,
         "CHARIOTPLUGINDEMO: callgraph function %qD has %d basic-blocks and %d statements",
         fun->decl, bbcount, stmtcount);
  inform(funendloc,  "CHARIOTPLUGINDEMO: callgraph function %qD (@%p) has %d calls",
         fun->decl, (void*)fun, nbcalls);

#warning the stack size is available in some later pass
  //#if 0
  /* the fun->su exists as soon as -fstack-usage is passed, but it is
     filled much later, by the RTL pass named "pro_and_epilogue" at
     gcc-8.3.0/gcc/config/i386/i386.c:13930 in function
     ix86_expand_prologue; that pass is
     pass_data_thread_prologue_and_epilogue defined in gcc/function.c
     line 6553 ... */
  if (fun && fun->su)
    {
      auto fsu = fun->su;
      inform(funendloc, "CHARIOTPLUGINDEMO: callgraph function %qD size: static stack %ld, dynamic stack %ld",
             fun->decl, (long) fsu->static_stack_size, (long) fsu->dynamic_stack_size);
    }
  else
    inform(funendloc, "CHARIOTPLUGINDEMO: callgraph function %qD has no stack usage", fun->decl);
  //#endif

  return 0;
} // end pass_chariot_callgraph::execute




gimple_opt_pass *
make_pass_chariot_callgraph (gcc::context *ctxt)
{
  return new pass_chariot_callgraph (ctxt);
}

////////////////////////////////////////////////////////////////

//// the frame size related CHARIOT pass.  We are inserting it after
//// the "ira" (Integrated Register Allocator) pass.


// Since the framesize pass is an RTL pass (not a GIMPLE one), it is indirectly called
// from expand_all_functions in gcc/cgraphunit.c:2275

const pass_data pass_data_chariot_framesize =
{
  RTL_PASS, /* type */
  "chariot_framesize", /* name */
  OPTGROUP_NONE, /* optinfo_flags */
  TV_NONE, /* tv_id */
  PROP_ssa, /* properties_required */
  0, /* properties_provided */
  0, /* properties_destroyed */
  0, /* todo_flags_start */
  0, /* todo_flags_finish */
};

class pass_chariot_framesize : public rtl_opt_pass
{
public:
  pass_chariot_framesize(gcc::context *ctxt)
    : rtl_opt_pass(pass_data_chariot_framesize, ctxt)
  {}

  /* opt_pass methods: */
  virtual unsigned int execute (function *);

}; // class pass_chariot_framesize

unsigned int
pass_chariot_framesize::execute (function *fun)
{
  auto funstartloc = (fun && fun->function_start_locus)
                     ?  fun->function_start_locus
                     : UNKNOWN_LOCATION;
  auto funendloc = (fun && fun->function_end_locus)
                   ?  fun->function_end_locus
                   : UNKNOWN_LOCATION;
  inform (funstartloc,
          "CHARIOTPLUGINDEMO: framesize start examining %qD @@ %s:%d", fun->decl,
          __FILE__, __LINE__);
  usleep (1); // we could set a breakpoint here
  inform(funendloc, "CHARIOTPLUGINDEMO: framesize current_function_decl %qD (@%p, fun.decl@%p)",
         current_function_decl, (void*)current_function_decl, (void*)fun->decl);
  if (fun && fun->su)
    {
      auto fsu = fun->su;
      inform(funendloc, "CHARIOTPLUGINDEMO: framesize function %qD (@%p) size: static stack %ld, dynamic stack %ld",
             fun->decl, (void*)fun, (long) fsu->static_stack_size, (long) fsu->dynamic_stack_size);
    }
  else
    warning(funendloc, "CHARIOTPLUGINDEMO: framesize function %qD has no stack usage", fun->decl);

  return 0;

} // end pass_chariot_framesize


rtl_opt_pass *
make_pass_chariot_framesize (gcc::context *ctxt)
{
  return new pass_chariot_framesize (ctxt);
}
////////////////////////////////////////////////////////////////


void parse_plugin_arguments (const char*plugin_name, struct plugin_name_args* plargs)
{
  int plargc = plargs->argc;
  int ix= 0;
  static char versbuf[128];
  snprintf(versbuf, sizeof(versbuf),
           "CHARIOT-CEA-DEMO "
#ifdef PLUGINGITID
           "git-commit %.12s, "
#else
           "unversioned %.3s, "
#endif /*PLUGINGITID*/
           "built on %s",
#ifdef PLUGINGITID
           chariot_plugin_gitid,
#else
           "??? ",
#endif /*PLUGINGITID*/
           __DATE__ "@" __TIME__);
  assert (plargs->version == NULL);
  plargs->version = versbuf;
  assert (plargs->help == NULL);
  plargs->help = "http://www.chariotproject.eu/ CEA DEMO 2019Q2; use the 'help' plugin argument for more help.";
  //
  for (struct plugin_argument* plcurarg = plargs->argv;
       (ix<plargc)?(plcurarg = plargs->argv+ix):nullptr; ix++)
    {
      const char*curkey = plcurarg->key;
      const char*curval = plcurarg->value;
      if (!strcmp(curkey, "bismoncookie") && curval)
        {
          chariot_bismoncookiestr = std::string(curval);
        }
      else if (!strcmp(curkey, "bismonurlprefix") && curval)
        {
          if (strcmp(curval, "-") && strcmp(curval, "."))
            {
              chariot_bismonurlprefixstr.clear();
              chariot_bismonurlprefixstr.insert(0, curval);
              inform(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO: with HTTP bismonurlprefix=%s (l@%d)",
                     curval,
                     __LINE__);
              chariot_faking = false;
            }
          else
            {
              inform(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO: just faking HTTP bismonurlprefix=%s (l@%d)",
                     curval,
                     __LINE__);
              chariot_faking = true;
            }

        }
      else if (!strcmp(curkey, "bismonproject") && curval)
        {
          chariot_bismonprojectstr = std::string(curval);
        }
      else if (!strcmp(curkey, "timeoutmilli") && curval)
        {
          chariot_timeout_millisec = atoi(curval);
          if (chariot_timeout_millisec < 50)
            chariot_timeout_millisec = 50;
          inform(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO: HTTP timeout to %d millisecond (l@%d)",
                 chariot_timeout_millisec, __LINE__);
        }
      else if (!strcmp(curkey, "translationunit") && curval)
        {
          chariot_translationunitstr = std::string(curval);
        }
      else if (!strcmp(curkey, "show-http"))
        {
          inform (UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO plugin %s will show HTTP REST requests", plugin_name);
          chariot_show_http = true;
        }
      else if (!strcmp(curkey, "http"))
        {
          inform (UNKNOWN_LOCATION,
                  "CHARIOTPLUGINDEMO plugin %s: showing HTTP exchanges", plugin_name);
          chariot_show_http = true;
        }
      else if (!strcmp(curkey, "help"))
        {
          inform (UNKNOWN_LOCATION,
                  "CHARIOTPLUGINDEMO plugin %s help:\n", plugin_name);
          printf("\t -fplugin-arg-%s-http #to show HTTP exchanges\n", plugin_name);
          printf("\t -fplugin-arg-%s-bismoncookie=<cookie> or $BISMONCOOKIE\n", plugin_name);
          printf("\t -fplugin-arg-%s-bismonurlprefix=<url> or $BISMONURL #or . to fake\n", plugin_name);
          printf("\t -fplugin-arg-%s-bismonproject=<projectname> or $BISMONPROJECT\n", plugin_name);
          printf("\t -fplugin-arg-%s-translationunit=<basename>\n", plugin_name);
          printf("\t -fplugin-arg-%s-timeoutmilli=<basename>\n", plugin_name);
          printf("\t -fplugin-arg-%s-help #this help\n", plugin_name);
          printf("\t -fplugin-arg-%s-show-http # show HTTP REST requests\n", plugin_name);
          printf("\t -fplugin-arg-%s-translationunit=<basename>\n", plugin_name);
        }
      else
        {
          if (curval)
            warning(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO: unexpected plugin %s argument %s=%s",
                    plugin_name, curkey, curval);
          else
            warning(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO: unexpected plugin %s argument %s",
                    plugin_name, curkey);
        }
    }
} // end parse_plugin_arguments

////////////////////////////////////////////////////////////////
int
plugin_init (struct plugin_name_args *plugin_info,
             struct plugin_gcc_version *version)
{
  const char *plugin_name = plugin_info->base_name;
  if (!plugin_default_version_check (version, &gcc_version))
    {
      warning(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO: fail version check for %s:\n"
              " got %s/%s/%s/%s wanted %s/%s/%s/%s", plugin_name,
              version->basever, version->datestamp, version->devphase, version->revision,
              gcc_version.basever, gcc_version.datestamp, gcc_version.devphase, gcc_version.revision);
      return 1;
    }

  inform(UNKNOWN_LOCATION,
         "CHARIOTPLUGINDEMO: %s starting %s:%d\n... for gcc %s/%s/%s/%s on filename %s\n... curlversion %s"
#ifdef PLUGINGITID
         "\n... gitid " PLUGINGITID
#endif /*PLUGINGITID*/
         "\n****************\n",
         plugin_name,
         __FILE__, __LINE__,
         gcc_version.basever, gcc_version.datestamp, gcc_version.devphase, gcc_version.revision,
         main_input_filename, curl_version());
  if (!flag_expensive_optimizations)
    error("CHARIOTPLUGINDEMO: expensive optimizations should be enabled, e.g. with -O2 or -Os");
  register_callback (plugin_name, PLUGIN_GGC_MARKING,
                     chariot_ggc_marker_callback, nullptr);

  /// initialize global state from arguments, and give information about this plugin
  parse_plugin_arguments (plugin_name, plugin_info);
  {
    const char*bc = getenv("BISMONCOOKIE");
    if (chariot_bismoncookiestr.empty() && bc)
      chariot_bismoncookiestr = std::string(bc);
  };
  {
    const char*us = getenv("BISMONURL");
    if (chariot_bismonurlprefixstr.empty() && us)
      chariot_bismonurlprefixstr = us;
  };
  if (chariot_bismoncookiestr.empty() && !chariot_faking)
    warning(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO: missing Bismon cookie (l@%d);\n"
            "... provide it with -fplugin-arg-%s-bismoncookie=<cookie>\n"
            "... or with $BISMONCOOKIE environment variable",
            __LINE__,
            plugin_name);
  if (chariot_bismonurlprefixstr.empty() && !chariot_faking)
    {
      chariot_bismonurlprefixstr = "http://localhost:8086/";
      inform(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO: %s uses %s as default Bismon URL prefix (l@%d)",
             plugin_name, chariot_bismonurlprefixstr.c_str(), __LINE__);
    }
  else
    inform(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO: %s uses %s as Bismon URL prefix (l@%d)",
           plugin_name, chariot_bismonurlprefixstr.c_str(), __LINE__);
  if (chariot_bismonurlprefixstr.find("localhost") == std::string::npos)
    warning(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO: %s would probably fail since Bismon URL prefix %s is not on localhost",
            plugin_name, chariot_bismonurlprefixstr.c_str());

  if (chariot_bismonprojectstr.empty())
    warning(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO: missing Bismon project;\n"
            "... provide it with -fplugin-arg-%s-bismonproject=<projectname>\n"
            "... or with $BISMONPROJECT environment variable", plugin_name);
  if (chariot_translationunitstr.empty())
    {
      auto lastdot = strchr(main_input_filename, '.');
      if (lastdot)
        {
          chariot_translationunitstr
            = std::string(main_input_filename, lastdot - main_input_filename);
        }
    }
  inform(UNKNOWN_LOCATION,
         "CHARIOTPLUGINDEMO: translation unit %s for main file %s",
         chariot_translationunitstr.c_str(), main_input_filename);

  // initialize CURL HTTP client library
  {
    int err=  curl_global_init(CURL_GLOBAL_ALL);
    if (err)
      fatal_error(UNKNOWN_LOCATION,
                  "CHARIOTPLUGINDEMO: cannot initialize CURL HTTP global library (%d)", err);
    chariot_curl = curl_easy_init ();
    if (!chariot_curl)
      fatal_error(UNKNOWN_LOCATION,
                  "CHARIOTPLUGINDEMO: cannot initialize CURL HTTP easy client library");
  }
  /// first curl REST request
  {
    Json::Value jtop(Json::objectValue);
    jtop["chariotproject"] = chariot_bismonprojectstr;
    jtop["translunit"] = chariot_translationunitstr;
    Json::Value jres;
    chariot_bismon_post_restcall("startchariot", &jtop, &jres);
#warning should handle result of startchariot
  }
  //
  struct register_pass_info my_callgraph_pass_info;
  my_callgraph_pass_info.pass = make_pass_chariot_callgraph (g);
  my_callgraph_pass_info.reference_pass_name = "sra";
  my_callgraph_pass_info.ref_pass_instance_number = 1;
  my_callgraph_pass_info.pos_op = PASS_POS_INSERT_AFTER;
  register_callback (plugin_name, PLUGIN_PASS_MANAGER_SETUP, NULL,
                     &my_callgraph_pass_info);
  //
  struct register_pass_info my_framesize_pass_info;
  my_framesize_pass_info.pass = make_pass_chariot_framesize (g);
  //#warning the below reference pass name is wrong for my_framesize_pass_info
  my_framesize_pass_info.reference_pass_name = "pro_and_epilogue";
  my_framesize_pass_info.ref_pass_instance_number = 1;
  my_framesize_pass_info.pos_op = PASS_POS_INSERT_AFTER;
  register_callback (plugin_name, PLUGIN_PASS_MANAGER_SETUP, NULL,
                     &my_framesize_pass_info);
  ///
  register_callback (plugin_name, PLUGIN_START_UNIT, chariot_starting, NULL);
  register_callback (plugin_name, PLUGIN_FINISH_UNIT, chariot_finishing, NULL);
  ///
  inform(UNKNOWN_LOCATION, "CHARIOTPLUGINDEMO: built " __DATE__ " on " __TIME__ " process %d"
#ifdef PLUGINGITID
         "\n(gitid " PLUGINGITID ") "
#endif
         " (l@%d)\n",
         (int) getpid(), __LINE__);

  return 0;
} // end plugin_init
