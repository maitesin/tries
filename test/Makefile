CXX=g++
CXXFLAGS=-O2 -DMAX_SIZE=1000000 --std=c++11
TRIE_SOURCE=../trie/lib
RADIX_SOURCE=../Radix_Tree/lib
TST_SOURCE=../TST/lib
SRC=src
INSERT=$(SRC)/insert.cpp
REMOVE_FOUND=$(SRC)/remove_found.cpp
REMOVE_NOT_FOUND=$(SRC)/remove_not_found.cpp
SEARCH_FOUND=$(SRC)/search_found.cpp
SEARCH_NOT_FOUND=$(SRC)/search_not_found.cpp
GET_KEYS=$(SRC)/get_keys.cpp
GET_KEYS_PREFIX=$(SRC)/get_keys_with_prefix.cpp
BIN=bin
DICT=dict


all:
	$(MAKE) insert
	$(MAKE) remove
	$(MAKE) search
	$(MAKE) keys
	$(MAKE) keys_prefix
	$(MAKE) dicts
	$(MAKE) run
	$(MAKE) graphics

clean:
	$(MAKE) clean_insert
	$(MAKE) clean_remove
	$(MAKE) clean_search
	$(MAKE) clean_keys
	$(MAKE) clean_keys_prefix

insert: $(INSERT)
	$(CXX) $(INSERT) $(CXXFLAGS) -I$(TRIE_SOURCE) -DTRIE -o $(BIN)/trie_insert
	$(CXX) $(INSERT) $(CXXFLAGS) -I$(TST_SOURCE) -DTERNARY -o $(BIN)/tst_insert
	$(CXX) $(INSERT) $(CXXFLAGS) -I$(RADIX_SOURCE) -DRADIX -o $(BIN)/radix_insert
	$(CXX) $(INSERT) $(CXXFLAGS) -DMAP -o $(BIN)/map_insert
	$(CXX) $(INSERT) $(CXXFLAGS) -DUMAP -o $(BIN)/umap_insert

clean_insert:
	rm $(wildcard $(BIN)/*_insert)

remove_found: $(REMOVE_FOUND)
	$(CXX) $(REMOVE_FOUND) $(CXXFLAGS) -I$(TRIE_SOURCE) -DTRIE -o $(BIN)/trie_remove_found
	$(CXX) $(REMOVE_FOUND) $(CXXFLAGS) -I$(TST_SOURCE) -DTERNARY -o $(BIN)/tst_remove_found
	$(CXX) $(REMOVE_FOUND) $(CXXFLAGS) -I$(RADIX_SOURCE) -DRADIX -o $(BIN)/radix_remove_found
	$(CXX) $(REMOVE_FOUND) $(CXXFLAGS) -DMAP -o $(BIN)/map_remove_found
	$(CXX) $(REMOVE_FOUND) $(CXXFLAGS) -DUMAP -o $(BIN)/umap_remove_found

remove_not_found: $(REMOVE_NOT_FOUND)
	$(CXX) $(REMOVE_NOT_FOUND) $(CXXFLAGS) -I$(TRIE_SOURCE) -DTRIE -o $(BIN)/trie_remove_not_found
	$(CXX) $(REMOVE_NOT_FOUND) $(CXXFLAGS) -I$(TST_SOURCE) -DTERNARY -o $(BIN)/tst_remove_not_found
	$(CXX) $(REMOVE_NOT_FOUND) $(CXXFLAGS) -I$(RADIX_SOURCE) -DRADIX -o $(BIN)/radix_remove_not_found
	$(CXX) $(REMOVE_NOT_FOUND) $(CXXFLAGS) -DMAP -o $(BIN)/map_remove_not_found
	$(CXX) $(REMOVE_NOT_FOUND) $(CXXFLAGS) -DUMAP -o $(BIN)/umap_remove_not_found

remove:
	$(MAKE) remove_found
	$(MAKE) remove_not_found

clean_remove:
	rm $(wildcard $(BIN)/*remove_found)
	rm $(wildcard $(BIN)/*remove_not_found)

search_found: $(SEARCH_FOUND)
	$(CXX) $(SEARCH_FOUND) $(CXXFLAGS) -I$(TRIE_SOURCE) -DTRIE -o $(BIN)/trie_search_found
	$(CXX) $(SEARCH_FOUND) $(CXXFLAGS) -I$(TST_SOURCE) -DTERNARY -o $(BIN)/tst_search_found
	$(CXX) $(SEARCH_FOUND) $(CXXFLAGS) -I$(RADIX_SOURCE) -DRADIX -o $(BIN)/radix_search_found
	$(CXX) $(SEARCH_FOUND) $(CXXFLAGS) -DMAP -o $(BIN)/map_search_found
	$(CXX) $(SEARCH_FOUND) $(CXXFLAGS) -DUMAP -o $(BIN)/umap_search_found

search_not_found: $(SEARCH_NOT_FOUND)
	$(CXX) $(SEARCH_NOT_FOUND) $(CXXFLAGS) -I$(TRIE_SOURCE) -DTRIE -o $(BIN)/trie_search_not_found
	$(CXX) $(SEARCH_NOT_FOUND) $(CXXFLAGS) -I$(TST_SOURCE) -DTERNARY -o $(BIN)/tst_search_not_found
	$(CXX) $(SEARCH_NOT_FOUND) $(CXXFLAGS) -I$(RADIX_SOURCE) -DRADIX -o $(BIN)/radix_search_not_found
	$(CXX) $(SEARCH_NOT_FOUND) $(CXXFLAGS) -DMAP -o $(BIN)/map_search_not_found
	$(CXX) $(SEARCH_NOT_FOUND) $(CXXFLAGS) -DUMAP -o $(BIN)/umap_search_not_found

search:
	$(MAKE) search_found
	$(MAKE) search_not_found

clean_search:
	rm $(wildcard $(BIN)/*_search_found)
	rm $(wildcard $(BIN)/*_search_not_found)

keys: $(GET_KEYS)
	$(CXX) $(GET_KEYS) $(CXXFLAGS) -I$(TRIE_SOURCE) -DTRIE -o $(BIN)/trie_get_keys
	$(CXX) $(GET_KEYS) $(CXXFLAGS) -I$(TST_SOURCE) -DTERNARY -o $(BIN)/tst_get_keys
	$(CXX) $(GET_KEYS) $(CXXFLAGS) -I$(RADIX_SOURCE) -DRADIX -o $(BIN)/radix_get_keys
	$(CXX) $(GET_KEYS) $(CXXFLAGS) -DMAP -o $(BIN)/map_get_keys
	$(CXX) $(GET_KEYS) $(CXXFLAGS) -DUMAP -o $(BIN)/umap_get_keys

clean_keys:
	rm $(wildcard $(BIN)/*_get_keys)

keys_prefix: $(GET_KEYS_PREFIX)
	$(CXX) $(GET_KEYS_PREFIX) $(CXXFLAGS) -I$(TRIE_SOURCE) -DTRIE -o $(BIN)/trie_get_keys_prefix
	$(CXX) $(GET_KEYS_PREFIX) $(CXXFLAGS) -I$(TST_SOURCE) -DTERNARY -o $(BIN)/tst_get_keys_prefix
	$(CXX) $(GET_KEYS_PREFIX) $(CXXFLAGS) -I$(RADIX_SOURCE) -DRADIX -o $(BIN)/radix_get_keys_prefix
	$(CXX) $(GET_KEYS_PREFIX) $(CXXFLAGS) -DMAP -o $(BIN)/map_get_keys_prefix
	$(CXX) $(GET_KEYS_PREFIX) $(CXXFLAGS) -DUMAP -o $(BIN)/umap_get_keys_prefix

clean_keys_prefix:
	rm $(wildcard $(BIN)/*_get_keys_prefix)

dicts:
	tar zxf $(DICT)/dicts.tar.gz -C $(DICT)

run:
	echo "Executing: insert.sh"
	cd scripts && ./insert.sh
	echo "Executing: remove_found.sh"
	cd scripts && ./remove_found.sh
	echo "Executing: remove_not_found.sh"
	cd scripts && ./remove_not_found.sh
	echo "Executing: search_found.sh"
	cd scripts && ./search_found.sh
	echo "Executing: get_keys.sh"
	cd scripts && ./get_keys.sh
	echo "Executing: get_keys_prefix.sh"
	cd scripts && ./get_keys_prefix.sh

graphics:
	echo "Executing: insert.py"
	cd plots && ./insert.py
	echo "Executing: remove_found.py"
	cd plots && ./remove_found.py
	echo "Executing: remove_not_found.py"
	cd plots && ./remove_not_found.py
	echo "Executing: search_found.py"
	cd plots && ./search_found.py
	echo "Executing: get_keys.py"
	cd plots && ./get_keys.py
	echo "Executing: get_keys_prefix.py"
	cd plots && ./get_keys_prefix.py
