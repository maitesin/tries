#include <iostream>
#include <ctime>
#include <cstdlib>

// Conditional include for dependencies
#ifdef TRIE
#include <../trie/trie.cpp>
#endif
#ifdef TST
#include <../TST/TST.cpp>
#endif
#ifdef RADIX
#include <../Radix_Tree/radix_tree.cpp>
#endif

// Definition of the default parameters
#ifndef MIN_SIZE
#define MIN_SIZE 100
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

int main(void) {
	time_t t_init;
	float us;
	int size, counter, operation;

	srand(SALT);

	for (size = MIN_SIZE; size <= MAX_SIZE; size *= 2) {
#ifdef TRIE
		trie<int, 256> t;
#endif
#ifdef TST
		tst<int, 256> t;
#endif
#ifdef RADIX
		radix_tree<int, 256> t;
#endif
		counter = 0;
		t_init = clock();

		while (clock() - t_init < SECONDS_LOOP * CLOCKS_PER_SEC) {
			//DO WORK
		}
		us = 1e6*float(clock() - t_init)/CLOCKS_PER_SEC;
		std::cout << size << "\t" << us/counter << std::endl;
	}

	return 0;
}
