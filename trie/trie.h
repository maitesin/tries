#ifndef __TRIE_H__
#define __TRIE_H__

#include <string>

template <class T>
struct node {
  T value;
  node ** sons;
  int R;

node(int radix) : R(radix) {
    sons = new node<T>*[R];
    for (int i = 0; i < R; ++i) {
      sons[i] = nullptr;
    }
  }
  ~node() {
    delete[] sons;
  }
};

template <class T>
class trie {
 public:
  //Constructor
 trie(int radix = 256) : R(radix) {
    root = new node<T>(R);
    s = 0;
  }
  //Destructor
  ~trie() {
    clean(root);
  }
  //Methods
  const T & get(const std::string key);
  void put(const std::string key, const T value);
  int size() {return s;}
  void show();
 private:
  //Atributes
  node<T> * root;
  int R; //Radix
  int s;
  //Methods
  node<T> * get(node<T> * n, const std::string key, int d);
  node<T> * put(node<T> * n, const std::string key, const T value, int d);
  void clean(node<T> * n);
  void show(node<T> * n);
};

#endif
