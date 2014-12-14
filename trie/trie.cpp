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
bool trie<T>::remove(node<T> * n, std::string key, int d) {
  if (key.size() == d && n != nullptr) {
    n->value = T();
    if (n->s == 0)  {
      return true;
    }
    else return false;
  }
  else {
    if (n->sons[key[d]] != nullptr) {
      bool deleted = remove(n->sons[key[d]], key, d+1);
      if (deleted) {
	delete n->sons[key[d]];
	n->sons[key[d]] = nullptr;
	--n->s;
	if (n->s == 0 && n->value == T()) return true;
      }
      return false;
    }
  }
}


template <class T>
std::vector<std::string> trie<T>::get_keys() {
  std::vector<std::string> vec;
  gather_keys(root, "", vec);
  return vec;
}

template <class T>
std::vector<std::string> trie<T>::get_keys_with_prefix(std::string prefix) {
  node<T> * n = root;
  for (int i = 0; i < prefix.size(); ++i)
    if (n->sons[prefix[i]] != nullptr)
      n = n->sons[prefix[i]];
    else
      return std::vector<std::string>();
  std::vector<std::string> vec;
  gather_keys(n, prefix, vec);
  return vec;
}

template <class T>
void trie<T>::gather_keys(node <T> * n, std::string prefix, std::vector<std::string> & v) {
  if (n->value != T()) {
    v.push_back(prefix);
  }
  if (n->s != 0) {
    for (int i = 0; i < n->R; ++i) {
      if (n->sons[i] != nullptr) {
	gather_keys(n->sons[i], prefix + char(i), v); 
      }
    }
  }
}

template <class T>
void trie<T>::show() {
  std::cout << "new trie to show" << std::endl;
  for (auto key : get_keys()){
    std::cout << key << std::endl;
  }
}

