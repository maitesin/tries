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
#ifdef MAP
#include <map>
#endif
#ifdef UMAP
#include <unordered_map>
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
#ifdef ALPHANUM
#define ALPHABET "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LENGTH 62
#else
#define LENGTH 256
#endif

std::string get_random_string(unsigned int len) {
	std::string result = "";
	for (unsigned int i = 0; i < len; ++i){
		#ifdef ALPHANUM
		result += ALPHABET[rand()%LENGTH];
		#else
		result += static_cast<char>(rand()%LENGTH);
		#endif
	}
	return result;
}

int main(void) {
	time_t t_init;
	float us;
	int size, counter;

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
#ifdef MAP
		std::map<std::string, int> m;
#endif
#ifdef UMAP
#define MAP
		std::unordered_map<std::string, int> m;
#endif
		std::string aux;
		counter = 0;
		t_init = clock();
		while (clock() - t_init < SECONDS_LOOP * CLOCKS_PER_SEC) {
			aux = get_random_string(rand()%size);
#ifndef MAP
			t.put(aux, 1);
#else
			m.insert(std::pair<std::string, int>(aux, 1));
#endif
		}

		t_init = clock();
		while (clock() - t_init < SECONDS_LOOP * CLOCKS_PER_SEC) {
		  aux = get_random_string(rand()%size);
#ifndef MAP
			t.get(aux);
#else
			m.find(aux);
#endif
			++counter;			
		}
		us = 1e6*float(clock() - t_init)/CLOCKS_PER_SEC;
		std::cout << size << "\t" << us/counter << std::endl;
	}

	return 0;
}
