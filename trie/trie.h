// Copyright 2014 Maitesin
#ifndef TRIE_TRIE_H_
#define TRIE_TRIE_H_

#include <string>
#include <vector>
#include <array>
#include <memory>

/*************************
 *** Node for the Trie ***
 *************************/
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

/************
 *** Trie ***
 ************/
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
  /*
   * This method return the value stored in the trie
   * for a specific key provided as parameter. If there
   * is no the key in the trie return default value for
   * the value type.
   */
  const T & get(const std::string key);

  /*
   * This method is used to add a new key to the trie.
   * You must provide the key and the value to store.
   * If the key was not before in the trie it will
   * create the path to it and store the value.
   * Otherwise, if the key was already in the trie it
   * will update the value of the key with the new one.
   */
  void put(const std::string & key,
           const T & value);

  /*
   * This method return the amount of elements stored
   * in the trie.
   */
  int size() {return s;}

  /*
   * This is an auxiliary method to print in the screen
   * the current set of keys of the trie.
   */
  void show();

  /*
   * This method is to remove a value from the trie.
   * You must provide the key that holds the value.
   * If the key exist deletes the value and delete
   * the path to it if there are no other keys that
   * are using it. Otherwise, if the key is not there
   * nothing will happen.
   */
  void remove(const std::string & key);

  /*
   * This method tells you if a given key is in the
   * trie.
   */
  bool contains(const std::string & key);

  /*
   *
   *
   */
  std::vector<std::string> get_keys_with_prefix(const std::string & prefix);
  std::vector<std::string> get_keys();

 private:
  // Atributes
  std::unique_ptr<node<T,R>> root;
  int r;
  int s;
  // Methods
  std::unique_ptr<node<T,R>> get(std::unique_ptr<node<T,R>> & n,
                                 const std::string & key,
                                 int d);
  std::unique_ptr<node<T,R>> put(std::unique_ptr<node<T,R>> n,
                                 const std::string & key,
                                 const T & value,
                                 int d);
  void clean(std::unique_ptr<node<T,R>> n);
  bool remove(std::unique_ptr<node<T,R>> & n,
              const std::string & key,
              int d);
  bool contains(std::unique_ptr<node<T,R>> & n,
                const std::string & key,
                int d);
  void get_keys_with_prefix(std::unique_ptr<node<T,R>> & n,
			    std::string prefix,
			    int d,
			    std::unique_ptr<std::vector<std::string>> & v);
  void gather_keys(std::unique_ptr<node<T,R>> & n,
                   std::string prefix,
                   std::unique_ptr<std::vector<std::string>> & v);
};

#endif  // TRIE_TRIE_H_
