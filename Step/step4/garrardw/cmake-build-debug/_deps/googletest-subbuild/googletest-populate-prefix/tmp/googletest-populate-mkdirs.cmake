# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/auden_garrard/Desktop/Code/School/CSE 335 /Step/step4/garrardw/cmake-build-debug/_deps/googletest-src"
  "/Users/auden_garrard/Desktop/Code/School/CSE 335 /Step/step4/garrardw/cmake-build-debug/_deps/googletest-build"
  "/Users/auden_garrard/Desktop/Code/School/CSE 335 /Step/step4/garrardw/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "/Users/auden_garrard/Desktop/Code/School/CSE 335 /Step/step4/garrardw/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/Users/auden_garrard/Desktop/Code/School/CSE 335 /Step/step4/garrardw/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/Users/auden_garrard/Desktop/Code/School/CSE 335 /Step/step4/garrardw/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/Users/auden_garrard/Desktop/Code/School/CSE 335 /Step/step4/garrardw/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/auden_garrard/Desktop/Code/School/CSE 335 /Step/step4/garrardw/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/auden_garrard/Desktop/Code/School/CSE 335 /Step/step4/garrardw/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
