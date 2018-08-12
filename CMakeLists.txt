cmake_minimum_required(VERSION 3.12)
project(bismon)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# update module path to ensure our custom modules are found (e.g Libonion)
list(INSERT CMAKE_MODULE_PATH 0 ${bismon_SOURCE_DIR}/cmake)

# Libonion
find_package(Libonion REQUIRED)

# glib, gtk+
include(FindPkgConfig)
pkg_check_modules(bm_gtk_package REQUIRED gtk+-3.0>=3.22 IMPORTED_TARGET)
pkg_check_modules(bm_glib_package REQUIRED glib-2.0 IMPORTED_TARGET)

# pthreads
set(CMAKE_THREAD_PREFER_PTHREAD 1)
set(THREADS_PREFER_PTHREAD_FLAG 1)
find_package(Threads REQUIRED)

# libbacktrace
find_package(libbacktrace REQUIRED)

# BM_makeconst
add_executable(BM_makeconst BM_makeconst.cc)

# crypt
find_library(CRYPT_LIBRARY crypt)
if(NOT CRYPT_LIBRARY)
  message(FATAL_ERROR "error: crypt library not found")
endif()

# collect bismon sources
file(GLOB bm_cfiles CONFIGURE_DEPENDS "[a-z]*BM.c")
file(GLOB bm_cxxfiles CONFIGURE_DEPENDS "[a-z]*BM.cc")
file(GLOB bm_webtemplates CONFIGURE_DEPENDS "[a-z]*BM.thtml")

# timestamp the bismon program
add_custom_command(
  OUTPUT ${bismon_BINARY_DIR}/__timestamp.c
  DEPENDS ${bm_cfiles} ${bm_cxxfiles}
  COMMAND ${bismon_SOURCE_DIR}/timestamp-emit.sh ${bm_cfiles} ${bm_cxxfiles}
  WORKING_DIRECTORY ${bismon_BINARY_DIR}
  )
list(APPEND bm_cfiles ${bismon_BINARY_DIR}/__timestamp.c)

# make a XXX_BM.const.h header with constants in XXX_BM.c
set(bm_const_hfiles)
foreach(bm_cfile IN LISTS bm_cfiles)
  get_filename_component(bm_cfile_basename ${bm_cfile} NAME_WE)
  set(h_output ${bismon_BINARY_DIR}/${bm_cfile_basename}.const.h)
  add_custom_command(
    OUTPUT ${h_output}
    DEPENDS ${bm_cfile}
    COMMAND BM_makeconst -H ${h_output} ${bm_cfile}
    WORKING_DIRECTORY ${bismon_BINARY_DIR}
    COMMENT "BMCONSTH ${h_output}"
    )
  list(APPEND bm_const_hfiles ${h_output})
endforeach()

# make the _bm_allconsts.c file
set(c_output ${bismon_BINARY_DIR}/_bm_allconsts.c)
add_custom_command(
  OUTPUT ${c_output}
  DEPENDS ${bm_cfiles}
  COMMAND BM_makeconst -C ${c_output} ${bm_cfiles}
  WORKING_DIRECTORY ${bismon_BINARY_DIR}
  COMMENT "BMALLCONSTSC ${c_output}"
  )
list(APPEND bm_cfiles ${c_output})

# build from webtemplates
foreach(template IN LISTS bm_webtemplates)
  get_filename_component(template_basename ${template} NAME_WE)
  set(c_output ${bismon_BINARY_DIR}/${template_basename}.c)
  set(h_output ${bismon_BINARY_DIR}/_${template_basename}.h)
  add_custom_command(
    OUTPUT ${c_output} ${h_output}
    DEPENDS ${template}
    COMMAND ${Libonion_OTEMPLATE_EXECUTABLE} -a ${h_output} ${template} ${c_output}
    WORKING_DIRECTORY ${bismon_BINARY_DIR}
    )
  list(APPEND bm_cfiles ${c_output})
endforeach()

# bismon executable
add_executable(bismon
  ${bm_cfiles}
  ${bm_cxxfiles}
  ${bm_const_hfiles}
  )
target_compile_definitions(bismon
  PRIVATE
    BISMONION
    BISMONGTK
    GDK_DISABLE_DEPRECATED
    GTK_DISABLE_DEPRECATED
  )
target_link_libraries(bismon
  PRIVATE
    ${CMAKE_DL_LIBS}
    ${CRYPT_LIBRARY}
    libbacktrace::libbacktrace
    Libonion::Libonion
    Libonion::LibonionCpp
    PkgConfig::bm_glib_package
    PkgConfig::bm_gtk_package
    Threads::Threads
  )

# bismon executable symlinks
add_custom_command(TARGET bismon POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E create_symlink $<TARGET_FILE:bismon> bismonion
  COMMAND ${CMAKE_COMMAND} -E create_symlink $<TARGET_FILE:bismon> bismongtk
  WORKING_DIRECTORY ${bismon_BINARY_DIR}
  )

function(bm_add_module src type)
  get_filename_component(name ${src} NAME_WE)

  # id, md5
  string(REGEX REPLACE "[0-9a-zA-Z]+(\_.+)" "\\1" id ${name})
  file(MD5 ${src} md5)

  message(STATUS "  ${type} [id:${id}, md5:${md5}]")

  add_library(${name} MODULE ${src})
  target_link_libraries(${name}
    PRIVATE
      PkgConfig::bm_glib_package)
  target_compile_definitions(${name}
    PRIVATE
      BISMON_MODID=${id}
      BISMON_MOMD5="${md5}"
      ${type}
    )
  set_target_properties(${name}
    PROPERTIES
      OUTPUT_NAME "${name}"
      PREFIX ""
      LIBRARY_OUTPUT_DIRECTORY "modubin"
    )
  get_filename_component(src_name ${src} NAME)
  add_custom_command(TARGET ${name} PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${bismon_BINARY_DIR}/modubin
    COMMAND ${CMAKE_COMMAND} -E copy ${src} ${bismon_BINARY_DIR}/modules/${src_name}
    )
endfunction()

# add modules
message(STATUS "Adding bismon modules")

file(GLOB bm_modules CONFIGURE_DEPENDS "modules/modbm_*.c")
foreach(bm_module IN LISTS bm_modules)
  bm_add_module(${bm_module} BISMON_PERSISTENT_MODULE)
endforeach()

file(GLOB bm_modules CONFIGURE_DEPENDS "modules/tmpmobm_*.c")
foreach(bm_module IN LISTS bm_modules)
  bm_add_module(${bm_module} BISMON_TEMPORARY_MODULE)
endforeach()

# Copy *.bmon to build directory
file(GLOB bmon_stores RELATIVE ${bismon_SOURCE_DIR} CONFIGURE_DEPENDS "*.bmon")
foreach(bmon_store IN LISTS bmon_stores)
  configure_file(${bmon_store} ${bismon_BINARY_DIR}/${bmon_store} COPYONLY)
endforeach()
