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

node(int radix) : R(radix) {
    sons = new node<T>*[R];
    for (int i = 0; i < R; ++i) {
      sons[i] = nullptr;
    }
    s = 0;
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
  //std::vector<std::string> get_keys_with_preffix(std::string preffix);
  //std::vector<std::string> get_keys(std::string preffix);
  
 private:
  //Atributes
  node<T> * root;
  int R; //Radix
  int s;
  //Methods
  node<T> * get(node<T> * n, const std::string key, int d);
  node<T> * put(node<T> * n, const std::string key, const T value, int d);
  void clean(node<T> * n);
  void remove(node<T> * n, std::string key, int d);
  void delete_if_no_sons(node<T> * n);
  bool contains(node<T> * n, std::string key, int d);
  void show(node<T> * n);
  //std::vector<std::string> get_keys_with_preffix(node<T> * n,  std::string preffix, int d, std::vector<std::string> v);
};

#endif
