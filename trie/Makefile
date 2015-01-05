CPP=g++
CPPFLAGS=--std=c++11 -g -Wall -Wextra

test: test.cpp trie.cpp trie.h
	${CPP} ${CPPFLAGS} *.cpp -o $@

clean: test
	rm test *~
