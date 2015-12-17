PROJECT(Radix_Tree)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")

include(../conanbuildinfo.cmake)
CONAN_BASIC_SETUP()

INCLUDE_DIRECTORIES(lib)
ADD_EXECUTABLE(radix_test gtest/main.cpp)
TARGET_LINK_LIBRARIES(radix_test ${CONAN_LIBS})

add_custom_command(TARGET radix_test POST_BUILD COMMAND ./bin/radix_test)
