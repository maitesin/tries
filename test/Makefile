CXX=g++
CXXFLAGS=-O2 -DALPHANUM -DMAX_SIZE=100 --std=c++11
TRIE_SOURCE=../trie/lib
RADIX_SOURCE=../Radix_Tree/lib
TST_SOURCE=../TST/lib
SRC=src
INSERT=$(SRC)/insert.cpp
REMOVE_FOUND=$(SRC)/remove_found.cpp
REMOVE_NOT_FOUND=$(SRC)/remove_not_found.cpp
SEARCH_FOUND=$(SRC)/search_found.cpp
SEARCH_NOT_FOUND=$(SRC)/search_not_found.cpp
BIN=bin


all:
	$(MAKE) insert
	$(MAKE) remove
	$(MAKE) search

clean:
	$(MAKE) clean_insert
	$(MAKE) clean_remove
	$(MAKE) clean_search

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
