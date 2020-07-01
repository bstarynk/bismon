// file BM_makeconst.cc
// SPDX-License-Identifier: GPL-3.0-or-later

/***
    BISMON
    Copyright © 2018, 2019 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
    contributed by Basile Starynkevitch (working at CEA, LIST, France)
    <basile@starynkevitch.net> or <basile.starynkevitch@cea.fr>

    BM_makeconst: a standalone program to scan and collect BMK_<digit><alphanum> constant names
    for example BMK_0eMGYofuNVh_8ZP2mXdhtHO is the 'in' predefined constant

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
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <set>
#include <string>
#include <unistd.h>
#include "id_BM.h"

/** examples of invocation:
To process a single file and generate its header
    ./BM_makeconst -H user_BM.const.h user_BM.c

To process all the files and generate the constants
    ./BM_makeconst -C _bm_allconsts.c *_BM.c misc_BM.cc
***/

#define BMPREFIXSIZE 4 /* the length of both "BMK_" and "BMH_" prefixes */
typedef std::set<rawid_tyBM, IdLess_BM> set_of_ids_BM;


int totalnbkocc;		// total cumulated number of occurrences of BMK_ for constants

int totalnbhocc;		// total cumulated number of occurrences of BMH_ for hashes

int parse_cfile(const char*path, set_of_ids_BM &bmconstset, set_of_ids_BM &bmhashset, bool verbose=false)
{
  if (access(path, R_OK))
    {
      fprintf(stderr, "cannot access C file %s (%m)\n", path);
      exit(EXIT_FAILURE);
    };
  std::ifstream srcin(path);
  int linecnt = 0;
  int nbkocc = 0;
  int nbhocc = 0;
  do
    {
      std::string line;
      std::getline(srcin, line);
      ssize_t linesize = line.size();
      ssize_t bmkpos=0;
      ssize_t bmhpos=0;
      while (bmkpos<(ssize_t)linesize && bmhpos<(ssize_t)linesize)
        {
          bmkpos=line.find("BMK_", bmkpos);
          bmhpos=line.find("BMH_", bmhpos);
          if (bmkpos>0 && bmhpos > 0)
            {
              fprintf(stderr, "%s:%d: cannot have both BMK_ and BMH_ on the same line\n",
                      path, linecnt+1);
              exit(EXIT_FAILURE);
            };
          if (bmkpos < 0 && bmhpos < 0)
            break;
          ///
          /// ignore BMK_ if following a letter, digit or underscore,
          /// or if not followed by digit
          if (bmkpos>0 && ((isalnum(line[bmkpos-1]) || line[bmkpos-1]=='_')
                           || (bmkpos+BMPREFIXSIZE >= linesize || !isdigit(line[bmkpos+BMPREFIXSIZE]))))
            {
              while (bmkpos>0 && bmkpos<(ssize_t)linesize && (isalnum(line[bmkpos])||line[bmkpos]=='_'))
                bmkpos++;
              continue;
            };
          ///
          /// ignore BMH_ if following a letter, digit or underscore,
          /// or if not followed by digit
          if (bmhpos>0 && ((isalnum(line[bmhpos-1]) || line[bmhpos-1]=='_')
                           || (bmhpos+BMPREFIXSIZE >= linesize || !isdigit(line[bmhpos+BMPREFIXSIZE]))))
            {
              while (bmhpos>0 && bmhpos<(ssize_t)linesize && (isalnum(line[bmhpos])||line[bmhpos]=='_'))
                bmhpos++;
              continue;
            };
          ///
          ///
          /// handle the id after BMK_
          if (bmkpos > 0)
            {
              const char*bmkcptr = line.c_str() + bmkpos;
              const char*endbmk = nullptr;
              rawid_tyBM bmkid = parse_rawid_BM(bmkcptr+BMPREFIXSIZE-1, &endbmk);
              if (validid_BM(bmkid) && endbmk != nullptr)
                {
                  bmconstset.insert(bmkid);
                  totalnbkocc++;
                  nbkocc++;
                  bmkpos = endbmk - line.c_str();
                }
              else bmkpos += BMPREFIXSIZE;
            }
          ///
          ///
          /// handle the id after BMH_
          if (bmhpos > 0)
            {
              const char*bmhcptr = line.c_str() + bmhpos;
              const char*endbmh = nullptr;
              rawid_tyBM bmhid = parse_rawid_BM(bmhcptr+BMPREFIXSIZE-1, &endbmh);
              if (validid_BM(bmhid) && endbmh != nullptr)
                {
                  bmhashset.insert(bmhid);
                  totalnbhocc++;
                  nbhocc++;
                  bmhpos = endbmh - line.c_str();
                }
              else bmhpos += BMPREFIXSIZE;
            }
        };			// end while
      linecnt++;
    }
  while (srcin);
  if (verbose)
    {
      printf("processed %d lines from %s with %d constant occurrences, %d hashes\n",
             linecnt, path, nbkocc, nbhocc);
      fflush(nullptr);
    }
  return linecnt;
} // end parse_cfile



int main(int argc, char**argv)
{
  if (argc < 3)
    {
      fprintf(stderr, "%s expects at least three arguments:\n"
              "\t -H <generated-header> <C-file>\n"
              "\t -C <generated-code> <C-files>...\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  if (!strcmp(argv[1], "-H"))
    {
      auto hpath = argv[2];
      set_of_ids_BM bmconstset;
      set_of_ids_BM bmhashset;
      for (int ix=3; ix<argc; ix++)
        parse_cfile(argv[ix], bmconstset, bmhashset, true);
      std::ofstream outh(hpath);
      outh << "// generated header " << hpath << " for "
           << bmconstset.size() << " constants and "
           << bmhashset.size() << " hashes;"
           " DONT EDIT" << std::endl;
      outh << std::endl << "// " << bmconstset.size() << " constants:" << std::endl;
      for (auto id: bmconstset)
        {
          char bufid[32];
          memset (bufid, 0, sizeof(bufid));
          idtocbuf32_BM(id, bufid);
          outh << "extern void*bmconst" << bufid << ";" << std::endl;
          outh << "#define BMK" << bufid << " bmconst" << bufid <<std::endl;
        }
      outh << std::endl << "// " << bmhashset.size() << " hashes:" << std::endl;
      for (auto id: bmhashset)
        {
          char bufid[32];
          memset (bufid, 0, sizeof(bufid));
          idtocbuf32_BM(id, bufid);
          hash_tyBM h = hashid_BM(id);
          outh << "#define BMH" << bufid << " " << h << std::endl;
        }
      outh << "//- eof generated header " << hpath << std::endl;
    }
  else if (!strcmp(argv[1], "-C"))
    {
      auto spath = argv[2];
      int nblines = 0;
      set_of_ids_BM bmconstset;
      set_of_ids_BM bmhashset;
      for (int ix=3; ix<argc; ix++)
        nblines += parse_cfile(argv[ix], bmconstset, bmhashset, false);
      std::ofstream outs(spath);
      outs << "/** generated constant file " << spath << std::endl;
      outs << "  from:";
      for (int ix=3; ix<argc; ix++)
        {
          if ((ix - 3) % 4 == 0)
            outs << std::endl << " ...";
          outs<< ' ' << argv[ix];
        }
      outs << std::endl << " DONT EDIT**/" << std::endl;
      outs << std::endl << std::endl;
      for (auto id: bmconstset)
        {
          char bufid[32];
          memset (bufid, 0, sizeof(bufid));
          idtocbuf32_BM(id, bufid);
          outs << "void*bmconst" << bufid << ";" << std::endl;
        };
      outs << std::endl;
      outs << "const int bmnbconsts=" << bmconstset.size() << ";" << std::endl;
      outs << "void** bmconstaddrs[] = {" << std::endl;
      for (auto id: bmconstset)
        {
          char bufid[32];
          memset (bufid, 0, sizeof(bufid));
          idtocbuf32_BM(id, bufid);
          outs << "  &bmconst" << bufid << "," << std::endl;
        }
      outs << " (void**)0 };" << std::endl;
      outs << "const char* bmconstidstrings[] = {" << std::endl;
      for (auto id: bmconstset)
        {
          char bufid[32];
          memset (bufid, 0, sizeof(bufid));
          idtocbuf32_BM(id, bufid);
          outs << " \"" << bufid << "\"," << std::endl;
        }
      outs << " (const char*)0 };" << std::endl;
      outs << "//- eof generated constant file " << spath << std::endl;
      printf("processed %d lines in %d files with %d occurrences of %d constants\n",
             nblines, argc-3, totalnbkocc, (int) bmconstset.size());
    }
  else
    {
      fprintf(stderr, "%s: expects -H <header> <C-source> or -C <code> <C-source-files>\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  return 0;
} // end main

/// eof BM_makeconst.cc


