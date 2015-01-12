CPP=g++
CPPFLAGS=--std=c++11 -g

test: test.cpp radix_tree.cpp radix_tree.h
	${CPP} ${CPPFLAGS} *.cpp -o $@

clean: test
	rm test *~
