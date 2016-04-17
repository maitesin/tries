project(Tries)
cmake_minimum_required(VERSION 2.8)

include(conanbuildinfo.cmake)
conan_basic_setup()

enable_testing()

set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage --std=c++11")

add_subdirectory(trie)
add_subdirectory(TST)
add_subdirectory(Radix_Tree)
