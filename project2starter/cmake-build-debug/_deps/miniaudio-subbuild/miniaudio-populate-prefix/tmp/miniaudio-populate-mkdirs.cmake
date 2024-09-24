# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/auden_garrard/Desktop/Code/School/CSE 335 /project2starter/cmake-build-debug/_deps/miniaudio-src"
  "/Users/auden_garrard/Desktop/Code/School/CSE 335 /project2starter/cmake-build-debug/_deps/miniaudio-build"
  "/Users/auden_garrard/Desktop/Code/School/CSE 335 /project2starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix"
  "/Users/auden_garrard/Desktop/Code/School/CSE 335 /project2starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix/tmp"
  "/Users/auden_garrard/Desktop/Code/School/CSE 335 /project2starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src/miniaudio-populate-stamp"
  "/Users/auden_garrard/Desktop/Code/School/CSE 335 /project2starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src"
  "/Users/auden_garrard/Desktop/Code/School/CSE 335 /project2starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src/miniaudio-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/auden_garrard/Desktop/Code/School/CSE 335 /project2starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src/miniaudio-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/auden_garrard/Desktop/Code/School/CSE 335 /project2starter/cmake-build-debug/_deps/miniaudio-subbuild/miniaudio-populate-prefix/src/miniaudio-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
