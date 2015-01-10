//Copyright 2015 Maitesin
#include <string>
#include <vector>
#include <iostream>
#include "./TST.h"

template <class T>
const T & TST::tst<T>::get(const std::string & key) {
	node_ptr<T> node (get(root, key, 0));
	if (node != nullptr) {
		aux_ret = node->value;
		node.release();
		return aux_ret;
	}
	else {
		return def;
	}
}

template <class T>
TST::node_ptr<T> TST::tst<T>::get(TST::node_ptr<T> & n,
				  const std::string & key,
				  unsigned int d) {
	if (key.size() == d) {
		if (n == nullptr)
			return nullptr;
		else {
			if (n->value != def)
				return node_ptr<T>(n.get());
			else
				return nullptr;
		}
	} else {
		if (n != nullptr) {
			if (n->c <  key[d]) return get(n->left,   key, d);
			if (n->c == key[d]) return get(n->middle, key, d+1);
			if (n->c >  key[d]) return get(n->right,  key, d);
		}
	}
	return nullptr;
}

template <class T>
void TST::tst<T>::put(const std::string & key,
		      const T & value) {
	if (root == nullptr)
		root = TST::node_ptr<T>(new node<T>(key[0]));
	root = put(std::move(root), key, value, 0);
	++s;
}

template <class T>
TST::node_ptr<T> TST::tst<T>::put(TST::node_ptr<T> n,
				  const std::string & key,
				  const T & value,
				  unsigned int d) {
	if (key.size() == d) {
		n->value = value;
		return n;
	} else {
		if (n->c < key[d]) {
			if (n->left == nullptr)
				n->left = TST::node_ptr<T>(new node<T>(key[d]));
			n->left = put(std::move(n->left), key, value, d);
		}
		if (n->c == key[d]) {
			if (n->middle == nullptr)
				n->middle = TST::node_ptr<T>(new node<T>(key[d]));
			n->middle = put(std::move(n->middle), key, value, d+1);
		}
		if (n->c > key[d]) {
			if (n->right == nullptr)
				n->right = TST::node_ptr<T>(new node<T>(key[d]));
			n->right = put(std::move(n->right), key, value, d);
		}
		return n;
	}
}

template <class T>
void TST::tst<T>::clean(TST::node_ptr<T> n) {
	if (n->left   != nullptr) clean(std::move(n->left));
	if (n->middle != nullptr) clean(std::move(n->middle));
	if (n->right  != nullptr) clean(std::move(n->right));
	n.reset();
}

template <class T>
bool TST::tst<T>::contains(const std::string & key) {
	return contains(root, key, 0);
}

template <class T>
bool TST::tst<T>::contains(TST::node_ptr<T> & n,
			const std::string & key,
			unsigned int d) {
	if (key.size() == d) {
		if (n == nullptr) return false;
		if (n->value != def) return true;
		return false;
	}
	else {
		if (n->c < key[d]) {
			if (n->left != nullptr) return contains(n->left, key, d);
			return false;
		}
		if (n->c == key[d]) {
			if (n->middle != nullptr) return contains(n->middle, key, d+1);
			return false;
		}
		if (n->c > key[d]) {
			if (n->right != nullptr) return contains(n->right, key, d);
			return false;
		}
		return false;
	}
}

template <class T>
void TST::tst<T>::remove(const std::string & key) {
	remove(root, key, 0);
}

template <class T>
bool TST::tst<T>::remove(TST::node_ptr<T> & n,
		      const std::string & key,
		      unsigned int d) {
	if (key.size() == d && n != nullptr) {
		n->value = T();
		if (n->left == nullptr &&
		    n->middle == nullptr &&
		    n->right == nullptr)
			return true;
		return false;
	} else {
		if (n->left != nullptr && n->c < key[d]) {
			bool deleted = remove(n->left, key, d);
			if (deleted) {
				n->left.reset();
				if (n->left == nullptr &&
				    n->middle == nullptr &&
				    n->right == nullptr &&
				    n->value == def)
					return true;
			}
			return false;
		}
		if (n->middle != nullptr && n->c == key[d]) {
			bool deleted = remove(n->middle, key, d+1);
			if (deleted) {
				n->middle.reset();
				if (n->left == nullptr &&
				    n->middle == nullptr &&
				    n->right == nullptr &&
				    n->value == def)
					return true;
			}
			return false;
		}
		if (n->right != nullptr && n->c > key[d]) {
			bool deleted = remove(n->right, key, d);
			if (deleted) {
				n->right.reset();
				if (n->left == nullptr &&
				    n->middle == nullptr &&
				    n->right == nullptr &&
				    n->value == def)
					return true;
			}
			return false;
		}
		return false;
	}
}

template <class T>
std::vector<std::string> TST::tst<T>::get_keys() {
	vec_ptr vec;
	vec = vec_ptr(new std::vector<std::string>());
	get_keys_with_prefix(root, "", 0, vec);
	return *vec;
}

template <class T>
std::vector<std::string> TST::tst<T>::get_keys_with_prefix(const std::string & prefix) {
	vec_ptr vec;
	vec = vec_ptr(new std::vector<std::string>());
	get_keys_with_prefix(root, prefix, 0, vec);
	return *vec;
}

template <class T>
void TST::tst<T>::get_keys_with_prefix(TST::node_ptr<T> & n,
				    std::string prefix,
				    unsigned int d,
				    TST::vec_ptr & v) {
	if (prefix.size() == d) {
		gather_keys(n, prefix, v);
	} else {
		if (n->c < prefix[d] && n->left != nullptr)
			get_keys_with_prefix(n->left, prefix, d, v);
		if (n->c == prefix[d] && n->middle != nullptr)
			get_keys_with_prefix(n->middle, prefix, d+1, v);
		if (n->c > prefix[d] && n->right != nullptr)
			get_keys_with_prefix(n->right, prefix, d, v);
	}
}


template <class T>
void TST::tst<T>::gather_keys(TST::node_ptr<T> & n,
			   std::string prefix,
			   TST::vec_ptr & v) {
	if (n == nullptr) return;
	if (n->value != def) {
		v->push_back(prefix);
	}
	gather_keys(n->left, prefix, v);
	gather_keys(n->middle, prefix + n->c, v);
	gather_keys(n->right, prefix, v);
}

template <class T>
void TST::tst<T>::show() {
	std::cout << "new TST to show" << std::endl;
	for (auto key : get_keys()) {
		std::cout << key << std::endl;
	}
}
