PROJECT(Radix_Tree)
cmake_minimum_required(VERSION 2.8)

INCLUDE_DIRECTORIES(lib)
ADD_EXECUTABLE(radix_test gtest/main.cpp)
TARGET_LINK_LIBRARIES(radix_test ${CONAN_LIBS})

enable_testing()
add_test(NAME Radix
        COMMAND ./bin/radix_test)
