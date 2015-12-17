#include "TST.cpp"
#include <iostream>

int main() {

  TST::tst<int> t;
  std::string hello = "Hello", world = "World", wololo = "Wololo", he = "He", kthulu = "Kthulu", no = "No", hes = "Hes";

  t.put(hello, 1);  
  t.put(world, 2);
  t.put(wololo, 3);
  t.put(kthulu, 4);
  t.put(he, 5);
  t.put(no, 6);
  t.put(hes, 7);

  t.show();
  
  return 0;
}
