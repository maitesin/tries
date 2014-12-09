#ifndef __TRIE_H__
#define __TRIE_H__

#include <string>

template <class T>
typedef struct _node {
  T value;
  _node sons[];
  int R;

_node(int radix, T v) : R(radix), value(v)
  {
    sons = new _node<T>[R];
    for (int i = 0; i < R; ++i) {
      sons[i] = nullptr;
    }
  }
  ~_node() {
    delete [] sons;
  }
} node;

template <class T>
class trie {
 public:
  //Constructor
 trie(int radix) : R(radix) {}
  //Destructor
  ~trie() {
    clean();
  }
  //Methods
  const T & get(const string key);
  void put(const string key, const T value);
  
 private:
  //Atributes
  node<T> * root;
  int R; //Radix
  //Methods
  node<T> & get(node<T> n, const string key, int d);
  node<T> & put(node<T> n, const string key, const T value, int d);
};

#endif
