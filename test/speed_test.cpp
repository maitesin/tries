#include <iostream>
#include <ctime>
#include <cstdlib>

// Conditional include for dependencies
#ifdef TRIE
#include <trie.cpp>
#endif
#ifdef TERNARY
#include <TST.cpp>
#endif
#ifdef RADIX
#include <radix_tree.cpp>
#endif

// Definition of the default parameters
#ifndef MIN_SIZE
#define MIN_SIZE 10
#endif
#ifndef MAX_SIZE
#define MAX_SIZE 100000000
#endif
#ifndef SECONDS_LOOP
#define SECONDS_LOOP 10.0
#endif
#ifndef SALT
#define SALT 0
#endif

std::string get_random_string(int len) {
	std::string result = "";
	for (unsigned int i = 0; i < len; ++i){
		result += static_cast<char>(rand()%256);
	}
	return result;
}

int main(void) {
	time_t t_init;
	float us;
	int size, counter, operation;

	srand(SALT);

	for (size = MIN_SIZE; size <= MAX_SIZE; size *= 2) {
#ifdef TRIE
		Trie::trie<int, 256> t;
#endif
#ifdef TERNARY
		TST::tst<int> t;
#endif
#ifdef RADIX
		RadixTree::radix_tree<int, 256> t;
#endif
		counter = 0;
		t_init = clock();
		std::string key;
		unsigned int length;
		while (clock() - t_init < SECONDS_LOOP * CLOCKS_PER_SEC) {
			t.put(get_random_string(rand()%size), 1);
			++counter;
		}
		us = 1e6*float(clock() - t_init)/CLOCKS_PER_SEC;
		std::cout << size << "\t" << us/counter << std::endl;
	}

	return 0;
}
