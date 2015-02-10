CXX=g++
CXXFLAGS=-O3 -DALPHANUM -DMAX_SIZE=100000 --std=c++11
TRIE_SOURCE=../trie
RADIX_SOURCE=../Radix_Tree
TST_SOURCE=../TST
SPEED=speed_test.cpp

speed: $(SPEED)
	$(CXX) $(SPEED) $(CXXFLAGS) -I$(TRIE_SOURCE) -DTRIE -o trie_speed
	$(CXX) $(SPEED) $(CXXFLAGS) -I$(TST_SOURCE) -DTERNARY -o tst_speed
	$(CXX) $(SPEED) $(CXXFLAGS) -I$(RADIX_SOURCE) -DRADIX -o radix_speed
	$(CXX) $(SPEED) $(CXXFLAGS) -DMAP -o map_speed
	$(CXX) $(SPEED) $(CXXFLAGS) -DUMAP -o umap_speed





clean:
	rm *_speed; rm *~;
