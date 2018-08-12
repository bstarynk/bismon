
#
# This was file is based of CMake/Module/FindZLIB.cmake and was created to
# demonstrate the use of CMake to build the "bismon" project.
#
# What should really be done is improving the onion project so that it
# created a "config-file" package. Since it already uses CMake, it should
# be fairly straighforward.
#
# See https://cmake.org/cmake/help/v3.12/manual/cmake-packages.7.html
#

# Hints
# ^^^^^
#
# A user may set ``Libonion_ROOT`` to a libonion installation root to tell this
# module where to look.
#

# Search Libonion_DIR first if it is set.
find_program(Libonion_OTEMPLATE_EXECUTABLE otemplate PATH_SUFFIXES bin)
find_library(Libonion_CPP_LIBRARY onioncpp PATH_SUFFIXES lib)
find_library(Libonion_C_LIBRARY onion PATH_SUFFIXES lib)
#find_library(Libonion_C_STATIC_LIBRARY onion_static PATH_SUFFIXES lib)
find_path(Libonion_INCLUDE_DIR onion/onion.h PATH_SUFFIXES include)

mark_as_advanced(Libonion_INCLUDE_DIR)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Libonion
  REQUIRED_VARS
    Libonion_OTEMPLATE_EXECUTABLE
    Libonion_CPP_LIBRARY
    Libonion_INCLUDE_DIR
  #VERSION_VAR Libonion_VERSION_STRING
)

if(Libonion_FOUND)
    set(Libonion_INCLUDE_DIRS ${Libonion_INCLUDE_DIR})
    set(Libonion_LIBRARIES ${Libonion_CPP_LIBRARY} ${Libonion_C_LIBRARY})

    if(NOT TARGET Libonion::Libonion)
      add_library(Libonion::Libonion UNKNOWN IMPORTED)
      set_target_properties(Libonion::Libonion PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${Libonion_INCLUDE_DIRS}")

      set_property(TARGET Libonion::Libonion APPEND PROPERTY
        IMPORTED_LOCATION "${Libonion_C_LIBRARY}")
    endif()

    if(NOT TARGET Libonion::LibonionCpp)
      add_library(Libonion::LibonionCpp UNKNOWN IMPORTED)
      set_target_properties(Libonion::LibonionCpp PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${Libonion_INCLUDE_DIRS}")

      set_property(TARGET Libonion::LibonionCpp APPEND PROPERTY
        IMPORTED_LOCATION "${Libonion_CPP_LIBRARY}")
    endif()
endif()
