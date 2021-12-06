# CMake module to find R
# - Try to find R.  If found, defines:
#
#  R_FOUND        - system has R
#  R_EXEC         - the system R command
#  R_ROOT_DIR     - the R root directory
#  R_INCLUDE_DIRS - the R include directories

set(TEMP_CMAKE_FIND_APPBUNDLE ${CMAKE_FIND_APPBUNDLE})
set(CMAKE_FIND_APPBUNDLE "NEVER")
find_program(R_EXEC NAMES R R.exe HINTS ENV R_HOME PATH_SUFFIXES bin)
message(STATUS "R_EXEC=${R_EXEC}")
set(CMAKE_FIND_APPBUNDLE ${TEMP_CMAKE_FIND_APPBUNDLE})

#---Find includes and libraries if R exists
if(R_EXEC)

  set(R_FOUND TRUE)

  if((CMAKE_HOST_SOLARIS) AND (DEFINED ENV{R_HOME}))
      message(STATUS "Unsetting R_HOME on Solaris.")
      unset(ENV{R_HOME})
  endif()

  execute_process(WORKING_DIRECTORY .
  COMMAND ${R_EXEC} RHOME
  OUTPUT_VARIABLE R_ROOT_DIR
  OUTPUT_STRIP_TRAILING_WHITESPACE)

  message(STATUS "foobar")
  find_path(R_INCLUDE_DIRS R.h
            PATHS /usr/local/lib /usr/local/lib64 /usr/share /usr/include ${R_ROOT_DIR} PATH_SUFFIXES include R R/include)
  message(STATUS "R_ROOT_DIR=${R_ROOT_DIR}")
  message(STATUS "R_INCLUDE_DIRS=${R_INCLUDE_DIRS}")
  message(STATUS "barfoo")

endif()

mark_as_advanced(R_FOUND R_EXEC R_ROOT_DIR R_INCLUDE_DIRS)
