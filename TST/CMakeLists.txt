PROJECT(Ternary_Search_Tree)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage --std=c++11")

include(../conanbuildinfo.cmake)
CONAN_BASIC_SETUP()

INCLUDE_DIRECTORIES(lib)
ADD_EXECUTABLE(tst_test gtest/main.cpp)
TARGET_LINK_LIBRARIES(tst_test ${CONAN_LIBS})

enable_testing()
add_test(NAME TST
        COMMAND ./bin/tst_test)
