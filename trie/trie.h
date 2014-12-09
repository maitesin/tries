#ifndef __TRIE_H__
#define __TRIE_H__

#include <string>

template <class T>
typedef struct _node {
  T value;
  _node * sons[];
  int R;

_node(int radix) : R(radix)
  {
    sons = new _node<T>*[R];
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
 trie(int radix = 256) : R(radix) {}
  //Destructor
  ~trie() {
    clean();
  }
  //Methods
  const T & get(const std::string key);
  void put(const std::string key, const T value);
  
 private:
  //Atributes
  node<T> * root;
  int R; //Radix
  //Methods
  node<T> * get(node<T> * n, const std::string key, int d);
  node<T> * put(node<T> * n, const std::string key, const T value, int d);
};

#endif
