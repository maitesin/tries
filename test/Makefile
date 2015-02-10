CXX=g++
CXXFLAGS=-O3 -DALPHANUM -DMAX_SIZE=10000 --std=c++11
TRIE_SOURCE=../trie
RADIX_SOURCE=../Radix_Tree
TST_SOURCE=../TST
INSERT=insert.cpp
REMOVE=remove.cpp

insert: $(INSERT)
	$(CXX) $(INSERT) $(CXXFLAGS) -I$(TRIE_SOURCE) -DTRIE -o trie_insert
	$(CXX) $(INSERT) $(CXXFLAGS) -I$(TST_SOURCE) -DTERNARY -o tst_insert
	$(CXX) $(INSERT) $(CXXFLAGS) -I$(RADIX_SOURCE) -DRADIX -o radix_insert
	$(CXX) $(INSERT) $(CXXFLAGS) -DMAP -o map_insert
	$(CXX) $(INSERT) $(CXXFLAGS) -DUMAP -o umap_insert

remove: $(REMOVE)
	$(CXX) $(REMOVE) $(CXXFLAGS) -I$(TRIE_SOURCE) -DTRIE -o trie_remove
	$(CXX) $(REMOVE) $(CXXFLAGS) -I$(TST_SOURCE) -DTERNARY -o tst_remove
	$(CXX) $(REMOVE) $(CXXFLAGS) -I$(RADIX_SOURCE) -DRADIX -o radix_remove
	$(CXX) $(REMOVE) $(CXXFLAGS) -DMAP -o map_remove
	$(CXX) $(REMOVE) $(CXXFLAGS) -DUMAP -o umap_remove


clean:
	rm *_insert; rm *_remove; rm *~;
