// file bismon.h
#ifndef BISMON_INCLUDED
#define BISMON_INCLUDED

/**
    BISMON 
    Copyright © 2018 Basile Starynkevitch (working at CEA, LIST, France)
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

#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif

#include <stddef.h>
#include <stdint.h>

#if __cplusplus
using std::atomic_bool;
using std::atomic_load;
using std::atomic_store;
#else
// notice that <stdatomic.h> is not C++11 compatible
#include <stdatomic.h>
/// Glibc dont have yet threads.h
#define thread_local _Thread_local
#endif


#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <setjmp.h>
#include <math.h>
#include <dlfcn.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <pthread.h>
#include <execinfo.h>


#include <gtk/gtk.h>

#include "cmacros_BM.h"
#include "types_BM.h"
#include "globals_BM.h"
#include "fundecl_BM.h"
#include "inline_BM.h"

#endif /*BISMON_INCLUDED*/
