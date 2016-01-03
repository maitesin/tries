PROJECT(Trie)
cmake_minimum_required(VERSION 2.8)

include(../conanbuildinfo.cmake)
CONAN_BASIC_SETUP()

INCLUDE_DIRECTORIES(lib)
ADD_EXECUTABLE(trie_test gtest/main.cpp)
TARGET_LINK_LIBRARIES(trie_test ${CONAN_LIBS})

add_test(NAME trie
        COMMAND ./bin/trie_test)
