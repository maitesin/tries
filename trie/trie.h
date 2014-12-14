#ifndef __TRIE_H__
#define __TRIE_H__

#include <string>
#include <vector>

template <class T>
struct node {
  T value;
  node ** sons;
  int s;
  int R;

node(int radix, T v = T()) : R(radix) {
    sons = new node<T>*[R];
    for (int i = 0; i < R; ++i) {
      sons[i] = nullptr;
    }
    s = 0;
    value = v;
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
  void remove(std::string key);
  bool contains(std::string key);
  std::vector<std::string> get_keys_with_prefix(std::string prefix);
  std::vector<std::string> get_keys();
  
 private:
  //Atributes
  node<T> * root;
  int R; //Radix
  int s;
  //Methods
  node<T> * get(node<T> * n, const std::string key, int d);
  node<T> * put(node<T> * n, const std::string key, const T value, int d);
  void clean(node<T> * n);
  bool remove(node<T> * n, std::string key, int d);
  bool contains(node<T> * n, std::string key, int d);
  void gather_keys(node<T> * n,  std::string prefix, std::vector<std::string> & v);
};

#endif
