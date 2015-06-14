CPP=g++
CPPFLAGS=--std=c++11 -g
GTEST=-lgtest

test: test_radix.cpp radix_tree.cpp radix_tree.h
	${CPP} ${CPPFLAGS} ${GTEST} $< -o $@

clean: test
	rm test *~
