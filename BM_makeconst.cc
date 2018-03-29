// file BM_makeconst.cc

/***
    BM_makeconst: a program to scan and collect BMK_<digit> constant names
    for example BMK_0eMGYofuNVh_8ZP2mXdhtHO is the 'in' predefined constant

    Copyright (C) 2017 - 2018 Basile Starynkevitch

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
#include "cmacros_BM.h"

int totalnbocc;

int parse_cfile(const char*path, std::set<std::string>& bmconstset, bool verbose=false)
{
  if (access(path, R_OK))
    {
      fprintf(stderr, "cannot access C file %s (%m)\n", path);
      exit(EXIT_FAILURE);
    };
  std::ifstream srcin(path);
  int linecnt = 0;
  int nbocc = 0;
  do
    {
      std::string line;
      std::getline(srcin, line);
      auto linesize = line.size();
      ssize_t pos=0;
      while (pos<(ssize_t)linesize)
        {
          pos=line.find("BMK_", pos);
          if (pos<0)
            break;
          size_t startpos = pos+4;
          /// ignore BMK_ if following a letter, digit or underscore,
          /// or if not followed by digit
          if (pos>0 && ((isalnum(line[pos-1]) || line[pos-1]=='_')
                        || (startpos >= linesize || !isdigit(line[startpos]))))
            {
              while (pos>0 && pos<(ssize_t)linesize && (isalnum(line[pos])||line[pos]=='_'))
                pos++;
              continue;
            };
          int badpos = -1;
          int ix = -1;
          const char*badmsg = nullptr;
          size_t endpos = 0;
          for (ix=startpos;
               badpos<0 && ix<(int)startpos+2*(SERIALDIGITS_BM);
               ix++)
            {
              if (ix>=(int)linesize)
                (badpos = ix), (badmsg="too short");
              else if (ix == (int)startpos+SERIALDIGITS_BM)
                {
                  if (line[ix]!='_')
                    (badpos=ix),(badmsg="no middle underscore");
                }
              else if (!isalnum(line[ix]))
                (badpos = ix), (badmsg="alphanum expected");
            };
          if (startpos+2*(SERIALDIGITS_BM + 1)<linesize)
            {
              char nc = line[startpos +2*(SERIALDIGITS_BM + 1)];
              if (isalnum(nc) || nc=='_')
                (badpos=startpos +2*(SERIALDIGITS_BM + 1)),
                (badmsg="too long id");
            };
          if (badpos>0)
            {
              fprintf(stderr, "%s:%d:%d: bad BMK_ constant, %s:: %s\n",
                      path, linecnt+1, badpos+1, badmsg, line.c_str()+pos);
              exit(EXIT_FAILURE);
            };
          endpos = startpos+2*(SERIALDIGITS_BM)+1;
          std::string curid = line.substr(startpos, endpos-startpos);
          pos = endpos;
          bmconstset.insert(curid);
          totalnbocc++;
          nbocc++;
        };
      linecnt++;
    }
  while (srcin);
  if (verbose)
    {
      printf("processed %d lines from %s with %d occurrences\n",
             linecnt, path, nbocc);
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
      std::set<std::string> bmconstset;
      for (int ix=3; ix<argc; ix++)
        parse_cfile(argv[ix], bmconstset, true);
      std::ofstream outh(hpath);
      outh << "// generated header " << hpath << " for "
           << bmconstset.size() << " constants. DONT EDIT" << std::endl;
      for (auto id: bmconstset)
        {
          outh << "extern void*bmconst_" << id << ";" << std::endl;
          outh << "#define BMK_" << id << " bmconst_" << id <<std::endl;
        }
      outh << "//- eof generated header " << hpath << std::endl;
    }
  else if (!strcmp(argv[1], "-C"))
    {
      auto spath = argv[2];
      std::set<std::string> bmconstset;
      int nblines = 0;
      for (int ix=3; ix<argc; ix++)
        nblines += parse_cfile(argv[ix], bmconstset, false);
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
          outs << "void*bmconst_" << id << ";" << std::endl;
        };
      outs << std::endl;
      outs << "const int bmnbconsts=" << bmconstset.size() << ";" << std::endl;
      outs << "void** const bmconstaddrs[] = {" << std::endl;
      for (auto id: bmconstset)
        {
          outs << "  &bmconst_" << id << "," << std::endl;
        }
      outs << " (void**)0 };" << std::endl;
      outs << "const char* bmconstidstrings[] = {" << std::endl;
      for (auto id: bmconstset)
        {
          outs << " \"_" << id << "\"," << std::endl;
        }
      outs << " (const char*)0 };" << std::endl;
      outs << "//- eof generated constant file " << spath << std::endl;
      printf("processed %d lines in %d files with %d occurrences of %d constants\n",
             nblines, argc-3, totalnbocc, (int) bmconstset.size());
    }
  else
    {
      fprintf(stderr, "%s: expects -H <header> <C-source> or -C <code> <C-source-files>\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  return 0;
}


