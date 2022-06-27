// file bismon.h
#ifndef BISMON_INCLUDED
#define BISMON_INCLUDED
// SPDX-License-Identifier: GPL-3.0-or-later
/**
    BISMON 
    Copyright © 2018 - 2022 CEA (Commissariat à l'énergie atomique et aux énergies alternatives)
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

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stddef.h>
#include <stdint.h>

#if __cplusplus
#include <memory>
#include <atomic>
using std::atomic_bool;
using std::atomic_int;
using std::atomic_load;
using std::atomic_store;
#else
// notice that <stdatomic.h> is not C++11 compatible
#include <stdatomic.h>
/// Glibc dont have yet threads.h
#define thread_local _Thread_local
#endif

/// usual GNU/Linux header files
/// see also man7.org/linux/man-pages/man2/syscalls.2.html
/// and man7.org/linux/man-pages/man3/intro.3.html

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <utime.h>
#include <setjmp.h>
#include <math.h>
#include <dlfcn.h>
#include <dirent.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <poll.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/file.h>
#include <sys/signalfd.h>
#include <sys/timerfd.h>
#include <elf.h>
#include <errno.h>
#include <netdb.h>
#include <locale.h>
#include <crypt.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <pthread.h>
#include <execinfo.h>
#include <backtrace.h>
#include <regex.h>

/// the Jansson JSON library from digip.org/jansson/ - see also
/// www.json.org/json-en.html for more about JSON
#include <jansson.h>

/// the Glib low-level utility library from developer.gnome.org/glib/
#include <glib.h>


/// We need the GNU readline 8 library from www.gnu.org/software/readline/
#include <readline/readline.h>


#include "cmacros_BM.h"
#include "id_BM.h"
#include "types_BM.h"
#include "globals_BM.h"
#include "fundecl_BM.h"
#include "inline_BM.h"
/****************
 **                           for Emacs...
 ** Local Variables: ;;
 ** compile-command: "./Build" ;;
 ** End: ;;
 ****************/
#endif /*BISMON_INCLUDED */
