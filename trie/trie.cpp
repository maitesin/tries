// Copyright 2014 Maitesin
#include <string>
#include <vector>
#include <iostream>
#include "./trie.h"

template <class T, size_t R>
const T & Trie::trie<T,R>::get(const std::string key) {
	node_ptr<T,R> node (get(root, key, 0));
	if (node != nullptr){
		aux_ret = node->value;
		node.release();
		return aux_ret;
	} else {
		return def;
	}
}

template <class T, size_t R>
Trie::node_ptr<T,R> Trie::trie<T,R>::get(Trie::node_ptr<T,R> & n,
					 const std::string & key,
					 unsigned int d) {
	if (key.size() == d) {
		if (n == nullptr) {
			return nullptr;
		} else {
			if (n->value != T())
				return node_ptr<T,R>(n.get());
			else
				return nullptr;
		}
	} else {
		if (n->sons[key[d]] != nullptr) {
			return get(n->sons[key[d]], key, d+1);
		}
	}
	return nullptr;
}

template <class T, size_t R>
void Trie::trie<T,R>::put(const std::string & key,
			  const T & value) {
	root = put(std::move(root), key, value, 0);
	++s;
}

template <class T, size_t R>
Trie::node_ptr<T,R> Trie::trie<T,R>::put(Trie::node_ptr<T,R> n,
					 const std::string & key,
					 const T & value,
					 unsigned int d) {
	if (key.size() == d) {
		n->value = value;
		return n;
	} else {
		if (n->sons[key[d]] == nullptr) {
			n->sons[key[d]] = Trie::node_ptr<T,R>(new node<T,R>());
			++n->s;
		}
		n->sons[key[d]] = put(std::move(n->sons[key[d]]), key, value, d+1);
		return n;
	}
}

template <class T, size_t R>
void Trie::trie<T,R>::clean(Trie::node_ptr<T,R> n) {
	for (int i = 0; i < n->r; ++i) {
		if (n->sons[i] != nullptr) clean(std::move(n->sons[i]));
	}
	n.reset();
}

template <class T, size_t R>
bool Trie::trie<T,R>::contains(const std::string & key) {
	return contains(root, key, 0);
}

template <class T, size_t R>
bool Trie::trie<T,R>::contains(Trie::node_ptr<T,R> & n,
			       const std::string & key,
			       unsigned int d) {
	if (key.size() ==d) {
		if (n == nullptr) return false;
		if (n->value != T()) return true;
		return false;
	} else {
		if (n->sons[key[d]] != nullptr) {
			return contains(n->sons[key[d]], key, d+1);
		}
		return false;
	}
}


template <class T, size_t R>
void Trie::trie<T,R>::remove(const std::string & key) {
	remove(root, key, 0);
}

template <class T, size_t R>
bool Trie::trie<T,R>::remove(Trie::node_ptr<T,R> & n,
			     const std::string & key,
			     unsigned int d) {
	if (key.size() == d && n != nullptr) {
		n->value = T();
		if (n->s == 0) {
			return true;
		}
		return false;
	} else {
		if (n->sons[key[d]] != nullptr) {
			bool deleted = remove(n->sons[key[d]], key, d+1);
			if (deleted) {
				n->sons[key[d]].reset();
				--n->s;
				if (n->s == 0 && n->value == T())
					return true;
			}
			return false;
		}
		return false;
	}
}


template <class T, size_t R>
std::vector<std::string> Trie::trie<T,R>::get_keys() {
	vec_ptr vec;
	vec = vec_ptr(new std::vector<std::string>());
	gather_keys(root, "", vec);
	return *vec;
}

template <class T, size_t R>
std::vector<std::string> Trie::trie<T,R>::get_keys_with_prefix(const std::string & prefix) {
	vec_ptr vec;
	vec = vec_ptr(new std::vector<std::string>());
	get_keys_with_prefix(root, prefix, 0, vec);
	return *vec;
}

template <class T, size_t R>
void Trie::trie<T,R>::get_keys_with_prefix(Trie::node_ptr<T,R> & n,
					   std::string prefix,
					   unsigned int d,
					   vec_ptr & v) {
	if (prefix.size() == d) {
		gather_keys(n, prefix, v);
	} else {
		if (n->sons[prefix[d]] != nullptr)
			get_keys_with_prefix(n->sons[prefix[d]], prefix, d+1, v);
	}  
}

template <class T, size_t R>
void Trie::trie<T,R>::gather_keys(Trie::node_ptr<T,R> & n,
				  std::string prefix,
				  vec_ptr & v) {
	if (n->value != T()) {
		v->push_back(prefix);
	}
	if (n->s != 0) {
		for (int i = 0; i < n->r; ++i) {
			if (n->sons[i] != nullptr) {
				gather_keys(n->sons[i], prefix + static_cast<char>(i), v);
			}
		}
	}
}

template <class T, size_t R>
void Trie::trie<T,R>::show() {
	std::cout << "new trie to show" << std::endl;
	for (auto key : get_keys()) {
		std::cout << key << std::endl;
	}
}
