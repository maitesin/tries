// Copyright 2014 Maitesin
#ifndef TRIE_TRIE_H_
#define TRIE_TRIE_H_

#include <string>
#include <vector>
#include <array>
#include <memory>

template <class T, size_t R>
struct node {
  T value;
  std::array<std::unique_ptr<node<T,R>>, R> sons;
  int s;
  int r;
  
  explicit node(T v = T()) : r(R) {
    sons = std::array<std::unique_ptr<node<T,R>>, R>();
    for (int i = 0; i < r; ++i) {
      sons[i] = nullptr;
    }
    s = 0;
    value = v;
  }
};

template <class T, size_t R>
class trie {
 public:
  // Constructor
 trie() : r(R) {
    root = std::unique_ptr<node<T,R>>(new node<T,R>);
    s = 0;
  }
  // Destructor
  ~trie() {
    clean(std::move(root));
  }
  // Methods
  const T & get(const std::string key);
  void put(const std::string & key, const T & value);
  int size() {return s;}
  void show();
  //void remove(const std::string & key);
  bool contains(const std::string & key);
  std::vector<std::string> get_keys_with_prefix(const std::string & prefix);
  std::vector<std::string> get_keys();

 private:
  // Atributes
  std::unique_ptr<node<T,R>> root;
  // Radix
  int r;
  int s;
  // Methods
  std::unique_ptr<node<T,R>> get(std::unique_ptr<node<T,R>> & n, const std::string & key, int d);
  std::unique_ptr<node<T,R>> put(std::unique_ptr<node<T,R>> n, const std::string & key, const T & value, int d);
  void clean(std::unique_ptr<node<T,R>> n);
  //bool remove(std::unique_ptr<node<T,R>> n, const std::string & key, int d);
  bool contains(std::unique_ptr<node<T,R>> & n, const std::string & key, int d);
  void gather_keys(std::unique_ptr<node<T,R>> & n,
                   std::string prefix,
                   std::unique_ptr<std::vector<std::string>> & v);
};

#endif  // TRIE_TRIE_H_
