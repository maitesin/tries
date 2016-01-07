#include "trie.cpp"
#include <iostream>

int main() {

  Trie::trie<int, 256> t;
  std::string hello = "Hello", world = "World", wololo = "Wololo", worst = "Worst", he = "He", kthulu = "Kthulu", no = "No", he_l = "he";

  t.insert(hello, 1); 
  t.insert(world, 2);
  t.insert(wololo, 3);
  t.insert(kthulu, 4);
  t.insert(he, 5);
  t.insert(no, 6);
  t.insert(he_l, 7);
  t.insert(worst, 8);

  t.show();
 
  return 0;
}
