# CMakeList.txt : CMake project for Leetcode, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Leetcode")

# Add source to this project's executable.
add_executable (Leetcode "Leetcode.cpp" "Leetcode.h" "BinaryIndexedTree.cpp" "BinaryIndexedTree.h"  "Notes.cpp" "Notes.h" "Solution01.cpp" "Solution01.h" "Solution02.cpp" "Solution02.h" "Solution03.cpp" "Solution03.h" "Solution04.cpp" "Solution04.h" "TrieTree.cpp" "TrieTree.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Leetcode PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
