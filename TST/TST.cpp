//Copyright 2015 Maitesin
#include <string>
#include <vector>
#include <iostream>
#include "./TST.h"

template <class T>
const T & TST::TST<T>::get(const std::string & key) {
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
TST::node_ptr<T> TST::TST<T>::get(TST::node_ptr<T> & n,
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
		if (n->c <  key[d]) return get(n->left,   key, d);
		if (n->c == key[d]) return get(n->middle, key, d+1);
		if (n->c >  key[d]) return get(n->right,  key, d);
	}
}

template <class T>
void TST::TST<T>::put(const std::string & key,
		   const T & value) {
	root = put(std::move(root), key, value, 0);
	++s;
}

template <class T>
TST::node_ptr<T> TST::TST<T>::put(TST::node_ptr<T> n,
			  const std::string & key,
			  unsigned int d) {
	if (key.size() == d) {
		n->value = value;
		return n;
	} else {
		if (n->c < key[d]) {
			if (n->left == nullptr)
				n->left = TST::node_ptr<T>(new node<T>());
			n->left = put(std::move(n->left), key, value, d);
		}
		if (n->c == key[d]) {
			if (n->middle == nullptr)
				n->middle = TST::node_ptr<T>(new node<T>());
			n->middle = put(std::move(n->middle), key, value, d+1);
		}
		if (n->c > key[d]) {
			if (n->right == nullptr)
				n->right = TST::node_ptr<T>(new node<T>());
			n->right = put(std::move(n->right), key, value, d);
		}
		return n;
	}
}

template <class T>
void TST::TST<T>::clean(TST::node_ptr<T> n) {
	if (n->left   == nullptr) clean(n->left);
	if (n->middle == nullptr) clean(n->middle);
	if (n->right  == nullptr) clean(n->right);
	n.reset();
}

template <class T>
bool TST::TST<T>::contains(const std::string & key) {
	return contains(root, key, 0);
}

template <class T>
bool TST::TST<T>::contains(TST::node_ptr<T> & n,
			const std::string & key,
			unsigned int d) {
	if (key.size() == d) {
		if (n == nullptr) return false;
		if (n->value != def) return true;
		return false;
	}
	else {
		if (n->c < key[d]) {
			if (n->left != null) return contains(n->left, key, d);
			return false;
		}
		if (n->c == key[d]) {
			if (n->middle != null) return contains(n->middle, key, d+1);
			return false;
		}
		if (n->c > key[d]) {
			if (n->right != null) return contains(n->right, key, d);
			return false;
		}
		return false;
	}
}

template <class T>
void TST::TST<T>::remove(const std::string & key) {
	//think about it
}

template <class T>
bool TST::TST<T>::remove(TST::node_ptr<T> & n,
		      const std::string & key,
		      unsigned int d) {
	//think about it
}

template <class T>
std::vector<std::string> TST::TST<T>::get_keys() {
	vec_ptr vec;
	vec = vec_ptr(new std::vector<std::string>());
	get_keys_with_prefix(root, "", 0, vec);
	return *vec;
}

template <class T>
std::vector<std::string> TST::TST<T>::get_keys_with_prefix(const std::string & prefix) {
	vec_ptr vec;
	vec = vec_ptr(new std::vector<std::string>());
	get_keys_with_prefix(root, prefix, 0, vec);
	return *vec;
}

template <class T>
void TST::TST<T>::get_keys_with_prefix(TST::node_ptr<T> & n,
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
void TST::TST<T>::gather_keys(TST::node_ptr<T> & n,
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
void TST::TST<T>::show() {
	std::cout << "new TST to show" << std::endl;
	for (auto key : get_keys()) {
		std::cout << key << std::endl;
	}
}
