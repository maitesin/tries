#include <iostream>
#include <ctime>
#include <cstdlib>

//////////////////////////////////////////
// Conditional include for dependencies //
//////////////////////////////////////////

// Trie
#ifdef TRIE
#include <trie.cpp>
#endif

// Ternary Search Tree
#ifdef TERNARY
#include <TST.cpp>
#endif

// Radix Tree
#ifdef RADIX
#include <radix_tree.cpp>
#endif

// Map
#ifdef MAP
#define MAP_FUNCTION
#include <map>
#endif
// Unordered Map
#ifdef UMAP
#define MAP_FUNCTION
#include <unordered_map>
#endif

//////////////////////////////////////////
// Definition of the default parameters //
//////////////////////////////////////////

// Minimum size of the generated strings 
#ifndef MIN_SIZE
#define MIN_SIZE 10
#endif

// Maximum size of the generated strings
#ifndef MAX_SIZE
#define MAX_SIZE 100000000
#endif

// Amount of time running the test
#ifndef SECONDS_LOOP
#define SECONDS_LOOP 10.0
#endif

// Salt for the random to generate strings
#ifndef SALT
#define SALT 0
#endif

// How many different characters can have our strings. Basicly, Extended ASCII
#define LENGTH 256


//////////////////////
// Useful functions //
//////////////////////

std::string get_random_string(unsigned int len) {
	std::string result = "";
	for (unsigned int i = 0; i < len; ++i){
		result += static_cast<char>(rand()%LENGTH);
	}
	return result;
}

int main(void) {
	time_t t_init;
	float us;
	int size, counter;

	for (size = MIN_SIZE; size <= MAX_SIZE; size *= 2) {
#ifdef TRIE
		Trie::trie<int, LENGTH> t;
#endif
#ifdef TERNARY
		TST::tst<int> t;
#endif
#ifdef RADIX
		RadixTree::radix_tree<int, LENGTH> t;
#endif
#ifdef MAP
		std::map<std::string, int> m;
#endif
#ifdef UMAP
#define MAP
		std::unordered_map<std::string, int> m;
#endif
		std::string aux;
		counter = 0;
		srand(SALT);
		t_init = clock();
		while (clock() - t_init < SECONDS_LOOP * CLOCKS_PER_SEC) {
			aux = get_random_string(rand()%size);
#ifndef MAP
			t.put(aux, 1);
#else
			m.insert(std::pair<std::string, int>(aux, 1));
#endif
		}

		srand(SALT);
		t_init = clock();
		while (clock() - t_init < SECONDS_LOOP * CLOCKS_PER_SEC) {
			aux = get_random_string(rand()%size);
#ifndef MAP
			t.remove(aux);
#else
			m.erase(aux);
#endif
			++counter;
		}
		us = 1e6*float(clock() - t_init)/CLOCKS_PER_SEC;
		std::cout << size << "\t" << us/counter << std::endl;
	}
	return 0;
}
