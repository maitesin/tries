CPP=g++
CPPFLAGS=--std=c++11 -g -Wall -Wextra

test: test.cpp TST.cpp TST.h
	${CPP} ${CPPFLAGS} *.cpp -o $@

clean: test
	rm test *~
