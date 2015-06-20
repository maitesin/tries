CXX=g++
CXXFLAGS=-O2 -DALPHANUM -DMAX_SIZE=10000 --std=c++11
TRIE_SOURCE=../trie
RADIX_SOURCE=../Radix_Tree
TST_SOURCE=../TST
INSERT=insert.cpp
REMOVE_FOUND=remove_found.cpp
REMOVE_NOT_FOUND=remove_not_found.cpp
SEARCH_FOUND=search_found.cpp
SEARCH_NOT_FOUND=search_not_found.cpp


all:
	$(MAKE) insert
	$(MAKE) remove
	$(MAKE) search

clean:
	rm *_insert; rm *_remove_found; rm *_remove_not_found; rm *_search_found; rm *_search_not_found; rm *~;

insert: $(INSERT)
	$(CXX) $(INSERT) $(CXXFLAGS) -I$(TRIE_SOURCE) -DTRIE -o trie_insert
	$(CXX) $(INSERT) $(CXXFLAGS) -I$(TST_SOURCE) -DTERNARY -o tst_insert
	$(CXX) $(INSERT) $(CXXFLAGS) -I$(RADIX_SOURCE) -DRADIX -o radix_insert
	$(CXX) $(INSERT) $(CXXFLAGS) -DMAP -o map_insert
	$(CXX) $(INSERT) $(CXXFLAGS) -DUMAP -o umap_insert

remove_found: $(REMOVE_FOUND)
	$(CXX) $(REMOVE_FOUND) $(CXXFLAGS) -I$(TRIE_SOURCE) -DTRIE -o trie_remove_found
	$(CXX) $(REMOVE_FOUND) $(CXXFLAGS) -I$(TST_SOURCE) -DTERNARY -o tst_remove_found
	$(CXX) $(REMOVE_FOUND) $(CXXFLAGS) -I$(RADIX_SOURCE) -DRADIX -o radix_remove_found
	$(CXX) $(REMOVE_FOUND) $(CXXFLAGS) -DMAP -o map_remove_found
	$(CXX) $(REMOVE_FOUND) $(CXXFLAGS) -DUMAP -o umap_remove_found

remove_not_found: $(REMOVE_NOT_FOUND)
	$(CXX) $(REMOVE_NOT_FOUND) $(CXXFLAGS) -I$(TRIE_SOURCE) -DTRIE -o trie_remove_not_found
	$(CXX) $(REMOVE_NOT_FOUND) $(CXXFLAGS) -I$(TST_SOURCE) -DTERNARY -o tst_remove_not_found
	$(CXX) $(REMOVE_NOT_FOUND) $(CXXFLAGS) -I$(RADIX_SOURCE) -DRADIX -o radix_remove_not_found
	$(CXX) $(REMOVE_NOT_FOUND) $(CXXFLAGS) -DMAP -o map_remove_not_found
	$(CXX) $(REMOVE_NOT_FOUND) $(CXXFLAGS) -DUMAP -o umap_remove_not_found

remove:
	$(MAKE) remove_found
	$(MAKE) remove_not_found

search_found: $(SEARCH_FOUND)
	$(CXX) $(SEARCH_FOUND) $(CXXFLAGS) -I$(TRIE_SOURCE) -DTRIE -o trie_search_found
	$(CXX) $(SEARCH_FOUND) $(CXXFLAGS) -I$(TST_SOURCE) -DTERNARY -o tst_search_found
	$(CXX) $(SEARCH_FOUND) $(CXXFLAGS) -I$(RADIX_SOURCE) -DRADIX -o radix_search_found
	$(CXX) $(SEARCH_FOUND) $(CXXFLAGS) -DMAP -o map_search_found
	$(CXX) $(SEARCH_FOUND) $(CXXFLAGS) -DUMAP -o umap_search_found

search_not_found: $(SEARCH_NOT_FOUND)
	$(CXX) $(SEARCH_NOT_FOUND) $(CXXFLAGS) -I$(TRIE_SOURCE) -DTRIE -o trie_search_not_found
	$(CXX) $(SEARCH_NOT_FOUND) $(CXXFLAGS) -I$(TST_SOURCE) -DTERNARY -o tst_search_not_found
	$(CXX) $(SEARCH_NOT_FOUND) $(CXXFLAGS) -I$(RADIX_SOURCE) -DRADIX -o radix_search_not_found
	$(CXX) $(SEARCH_NOT_FOUND) $(CXXFLAGS) -DMAP -o map_search_not_found
	$(CXX) $(SEARCH_NOT_FOUND) $(CXXFLAGS) -DUMAP -o umap_search_not_found

search:
	$(MAKE) search_found
	$(MAKE) search_not_found
