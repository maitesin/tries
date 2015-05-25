CPP=g++
CPPFLAGS=--std=c++11 -g -Wall -Wextra
GTEST=-lgtest

test: test_trie.cpp trie.cpp trie.h
	${CPP} ${CPPFLAGS} ${GTEST} $< -o $@

clean: test
	rm test *~
