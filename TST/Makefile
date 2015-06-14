CPP=g++
CPPFLAGS=--std=c++11 -g -Wall -Wextra
GTEST=-lgtest

test: test_tst.cpp TST.cpp TST.h
	${CPP} ${CPPFLAGS} ${GTEST} $< -o $@

clean: test
	rm test *~
