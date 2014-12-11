#include "trie.h"
#include <string>
#include <iostream>

template <class T>
const T & trie<T>::get(const std::string key) {
  node<T> * node = get(root, key, 0);
  if (root != nullptr) return node->value;
  else return nullptr; //review that
}

template <class T>
node<T> * trie<T>::get(node<T> * n, const std::string key, int d) {
  if (key.size() == d || n == nullptr) return nullptr;
  if (key.size() == d+1) return n;
  if (n->sons[key[d]] != nullptr) {
    return get(n->sons[key[d]], key, d+1);
  }
}

template <class T>
void trie<T>::put(const std::string key, const T value) {
  root = put(root, key, value, 0);
  ++s;
}

template <class T>
node<T> * trie<T>::put(node<T> * n, const std::string key, const T value, int d) {
  if (key.size() == d+1) {
    n->value = value;
    return n;
  }
  if (n->sons[key[d]] == nullptr) {
    n->sons[key[d]] = new node<T>(n->R);
  }
  return put(n->sons[key[d]], key, value, d+1);
}

template <class T>
void trie<T>::clean(node<T> * node) {
  for (int i = 0; i < node->R; ++i) {
    if (node->sons[i] != nullptr) clean(node->sons[i]);
  }
  delete node;
}

template <class T>
void trie<T>::show() {
  show(root);
}

template <class T>
void trie<T>::show(node<T> * node) {
  if (node->value != T()) std::cout << "value = " << node->value << std::endl;
  for (int i = 0; i < node->R; ++i) {
    if (node->sons[i] != nullptr) show(node->sons[i]);
  }
}
