#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

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
#define MAP_FUNCTION
#include <map>
#endif
#ifdef UMAP
#define MAP_FUNCTION
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

#ifdef MAP
std::vector<std::string> get_map_keys_with_prefix(std::map<std::string, int> & m, std::string & prefix) {
#endif
#ifdef UMAP
  std::vector<std::string> get_map_keys_with_prefix(std::unordered_map<std::string, int> & m, std::string & prefix) {
#endif
#ifdef MAP_FUNCTION
	std::vector<std::string> keys;
	for (auto it = m.begin(); it != m.end(); ++it) {
	  std::cout << "s: " << it->first << "; p: " << prefix;
	  if  (it->first.substring(0, prefix.size()) == prefix) {
	    std::cout << " -> Valid prefix";
	    keys.push_back(it->first);
	  }
	  std::cout << std::endl;
	}
	return keys;
}
#endif

 int main(int argc, char * argv[]) {
   time_t t_init;
   float us;
   int size, counter;
   bool random = true;
   std::ifstream f;
   std::string prefix;

   if (argc > 0) {
     f = infile(argv[1]);
     prefix = argv[2];
     random = false;
   }

   if (random) {
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
		srand(SALT);
		for (unsigned int j = 0; j < size; ++j) {
			aux = get_random_string(rand()%size);
#ifndef MAP
			t.put(aux, 1);
#else
			m.insert(std::pair<std::string, int>(aux, 1));
#endif
		}
		counter = 0;
		prefix = get_random_string(rand()%(size/10));
		t_init = clock();
		while (clock() - t_init < SECONDS_LOOP * CLOCKS_PER_SEC) {
#ifndef MAP
			t.get_keys_with_prefix(prefix);
#else
			get_map_keys_with_prefix(m, prefix);
#endif
			++counter;			
		}
		us = 1e6*float(clock() - t_init)/CLOCKS_PER_SEC;
		std::cout << size << "\t" << us/counter << std::endl;
	}
   }
   else {
     //Reading input from a file
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
		std::string line;
		while (f >> line) {
#ifndef MAP
			t.put(line, 1);
#else
			m.insert(std::pair<std::string, int>(line, 1));
#endif
		}
		counter = 0;
		t_init = clock();
		while (clock() - t_init < SECONDS_LOOP * CLOCKS_PER_SEC) {
#ifndef MAP
			t.get_keys_with_prefix(prefix);
#else
			get_map_keys_with_prefix(m, prefix);
#endif
			++counter;
		}
		us = 1e6*float(clock() - t_init)/CLOCKS_PER_SEC;
		std::cout << size << "\t" << us/counter << std::endl;
	}
	return 0;
}
