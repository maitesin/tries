project(Tries)
cmake_minimum_required(VERSION 3.4)

include(conanbuildinfo.cmake)
CONAN_BASIC_SETUP()

add_subdirectory(trie)
add_subdirectory(TST)
add_subdirectory(Radix_Tree)
