#.rst:
# Findlibbacktrace
# ----------------
#
# Find the libbacktrace headers and library.
# See https://github.com/ianlancetaylor/libbacktrace
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines :prop_tgt:`IMPORTED` target ``libbacktrace::libbacktrace``, if
# libbacktrace has been found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# ``libbacktrace_INCLUDE_DIRS``
#   The include directories needed to use libbacktrace header.
# ``libbacktrace_LIBRARIES``
#   The libraries (linker flags) needed to use libbacktrace, if any.
# ``libbacktrace_FOUND``
#   Is set if and only if libbacktrace support detected.
#
# The following cache variables are also available to set or use:
#
# ``libbacktrace_LIBRARY``
#   The external library providing libbacktrace, if any.
# ``libbacktrace_INCLUDE_DIR``
#   The directory holding the libbacktrace header.
#

include(CMakePushCheckState)
include(CheckSymbolExists)

find_path(libbacktrace_INCLUDE_DIR "backtrace.h" PATH_SUFFIXES include)
find_library(libbacktrace_LIBRARY "backtrace" PATH_SUFFIXES lib)

#if (NOT DEFINED libbacktrace_LIBRARY)
#  # First, check if we already have backtrace(), e.g., in libc
#  cmake_push_check_state(RESET)
#  set(CMAKE_REQUIRED_INCLUDES ${libbacktrace_INCLUDE_DIR})
#  set(CMAKE_REQUIRED_QUIET ${libbacktrace_FIND_QUIETLY})
#  check_symbol_exists("backtrace_create_state" "backtrace.h" HAVE_BACKTRACE_CREATE_STATE)
#  check_symbol_exists("backtrace_full" "backtrace.h" HAVE_BACKTRACE_FULL)
#  cmake_pop_check_state()
#endif()

mark_as_advanced(libbacktrace_INCLUDE_DIR libbacktrace_LIBRARY)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(libbacktrace
  REQUIRED_VARS
    libbacktrace_INCLUDE_DIR
    libbacktrace_LIBRARY
)

if(libbacktrace_FOUND)
    set(libbacktrace_INCLUDE_DIRS ${libbacktrace_INCLUDE_DIR})
    set(libbacktrace_LIBRARIES ${libbacktrace_LIBRARY})

    if(NOT TARGET libbacktrace::libbacktrace)
      add_library(libbacktrace::libbacktrace UNKNOWN IMPORTED)
      set_target_properties(libbacktrace::libbacktrace PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${libbacktrace_INCLUDE_DIRS}")

      set_property(TARGET libbacktrace::libbacktrace APPEND PROPERTY
        IMPORTED_LOCATION "${libbacktrace_LIBRARY}")
    endif()
endif()
