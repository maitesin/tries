#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "test_utils.h"

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

//////////////////////
// Useful functions //
//////////////////////

#ifdef MAP
std::string get_map_longest_common_prefix(std::map<std::string, int> &m) {
#endif
#ifdef UMAP
  std::string get_map_longest_common_prefix(
      std::unordered_map<std::string, int> & m) {
#endif
#ifdef MAP_FUNCTION
    std::vector<std::string> strs;
    for (auto it = m.begin(); it != m.end(); ++it) {
      strs.push_back(it->first);
    }
    int i, j, n = strs.size();
    if (n == 0)
      return "";
    sort(strs.begin(), strs.begin() + n);
    for (j = 0; j < strs[0].size() && j < strs[n - 1].size() &&
                strs[0][j] == strs[n - 1][j];
         j++)
      ;
    return strs[0].substr(0, j);
  }
#endif

  //////////
  // Main //
  //////////

  int main(int argc, char *argv[]) {
    time_t t_init;
    float us;
    int size, counter;
    bool random = true;
    std::ifstream f;

    if (argc > 1) {
      f.open(argv[1]);
      random = false;
    }

    if (random) {
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
        std::unordered_map<std::string, int> m;
#endif
        std::string aux;
        counter = 0;
        srand(SALT);
        for (unsigned int j = 0; j < MAX_SIZE; ++j) {
          aux = get_random_string(rand() % size);
#ifndef MAP_FUNCTION
          t.insert(aux, 1);
#else
        m.insert(std::pair<std::string, int>(aux, 1));
#endif
        }
        counter = 0;
        t_init = clock();
        while (clock() - t_init < SECONDS_LOOP * CLOCKS_PER_SEC) {
#ifndef MAP_FUNCTION
          t.lcp();
#else
        get_map_longest_common_prefix(m);
#endif
          ++counter;
        }
        us = 1e6 * float(clock() - t_init) / CLOCKS_PER_SEC;
        std::cout << size << "\t" << us / counter << std::endl;
      }
    } else {
// Reading input from a file
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
      std::unordered_map<std::string, int> m;
#endif
      std::string aux;
      std::string line;
      while (f >> line) {
#ifndef MAP_FUNCTION
        t.insert(line, 1);
#else
				m.insert(std::pair<std::string, int>(line, 1));
#endif
      }
      f.close();

      counter = 0;
      t_init = clock();
      while (clock() - t_init < SECONDS_LOOP * CLOCKS_PER_SEC) {
#ifndef MAP_FUNCTION
        t.lcp();
#else
				get_map_longest_common_prefix(m);
#endif
        ++counter;
      }
      us = 1e6 * float(clock() - t_init) / CLOCKS_PER_SEC;
      std::cout << us / counter << std::endl;
    }
    return 0;
  }
