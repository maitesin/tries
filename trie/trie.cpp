#include "trie.h"
#include <string>
#include <iostream>

template <class T>
const T & trie<T>::get(const std::string key) {
  node<T> * node = get(root, key, 0);
  if (node != nullptr) return node->value;
  else return T(); //review that
}

template <class T>
node<T> * trie<T>::get(node<T> * n, const std::string key, int d) {
  if (key.size() == d && n == nullptr) return nullptr;
  if (key.size() == d) return n;
  if (n->sons[key[d]] != nullptr) {
    return get(n->sons[key[d]], key, d+1);
  }
}

template <class T>
void trie<T>::put(const std::string key, const T value) {
  put(root, key, value, 0);
  ++s;
}

template <class T>
node<T> * trie<T>::put(node<T> * n, const std::string key, const T value, int d) {
  if (key.size() == d) {
    n->value = value;
    return n;
  }
  if (n->sons[key[d]] == nullptr) {
    n->sons[key[d]] = new node<T>(n->R);
    ++n->s;
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
  std::cout << "new trie to show" << std::endl;
  show(root);
}

template <class T>
void trie<T>::show(node<T> * node) {
  if (node->value != T()) std::cout << "value = " << node->value << std::endl;
  for (int i = 0; i < node->R; ++i) {
    if (node->sons[i] != nullptr) {
      std::cout << char(i) << std::endl;
      show(node->sons[i]);
    }
  }
}

template <class T>
bool trie<T>::contains(std::string key) {
  return contains(root, key, 0);
}

template <class T>
bool trie<T>::contains(node<T> * n, std::string key, int d) {
  if (key.size() == d && n == nullptr) return false;
  if (key.size() == d && n->value != T()) return true;
  if (n->sons[key[d]] != nullptr) {
    return contains(n->sons[key[d]], key, d+1);
  }
  return false;
}

template <class T>
void trie<T>::remove(std::string key) {
  remove(root, key, 0);
}

template <class T>
void trie<T>::remove(node<T> * n, std::string key, int d) {
  if (key.size() == d && n != nullptr) {
    n->value = T();
    return;
  }
  else {
    if (n->sons[key[d]] != nullptr) {
      remove(n->sons[key[d]], key, d+1);
    }
  }
}
