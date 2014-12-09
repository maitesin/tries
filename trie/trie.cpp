#include "trie.h"
#include <string>

template <class T>
const T & get(const std::string key) {
  node<T> * node = get(root, key, 0);
  if (root != nullptr) return node->value;
  else return nullptr; //review that
}

template <class T>
node<T> * get(node<T> * n, const std::string key, int d) {
  if (key.size() == d || n == nullptr) return nullptr;
  if (key.size() == d+1) return n;
  if (n->sons[key[d]] != nullptr) {
    return get(n->sons[key[d]], key, d+1);
  }
}

template <class T>
void put(const std::string key, const T value) {
  root = put(root, key, value, 0);
}

template <class T>
node<T> * put(node<T> * n, const std::string key, const T value, int d) {
  if (key.size() == d+1) {
    n->value = value;
    return n;
  }
  if (n->sons[key[d]] == nullptr) {
    n->sons[key[d]] = new node(n->R);
  }
  return (n->sons[key[d]], key, value, d+1);
}
