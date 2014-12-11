#include <string>
#include <iostream>
#include "trie.cpp"

int main(int argc, char * argv[] ) {

  trie<int> t;
  std::string hello = "Hello", world = "World", wololo = "Wololo";
  std::cout << hello << "(" << hello.size() << ")"<< std::endl;
  
  t.put(hello, 1);
  t.put(world, 2);
  t.put(wololo, 3);
  
  std::cout << "Current size should be 3; size = " << t.size() << std::endl;

  t.show();

  return 0;
}
