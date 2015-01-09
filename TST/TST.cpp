//Copyright 2015 Maitesin
#include <string>
#include <vector>
#include <iostream>
#include "./TST.h"

template <class T>
const T & TST::TST::get(const std::string & key) {
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
node_ptr<T> TST::TST::get(TST::node_ptr<T> & n,
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
		if (n->c <  key[d]) return get(n->left,   key, d+1);
		if (n->c >  key[d]) return get(n->right,  key, d+1);
		if (n->c == key[d]) return get(n->middle, key, d+1);
	}
}

template <class T>
void TST::TST::put(const std::string & key,
		   const T & value) {
	root = put(std::move(root), key, value, 0);
	++s;
}

template <class T>
node_ptr<T> TST::TST::put(TST::node_ptr<T> n,
			  const std::string & key,
			  unsigned int d) {
	if (key.size() == d) {
		n->value = value;
		return n;
	} else {
		if (n->c < key[d]) {
			if (n->left == nullptr)
				n->left = TST::node_ptr<T>(new node<T>());
			n->left = put(std::move(n->left), key, value, d+1);
		}
		if (n->c == key[d]) {
			if (n->middle == nullptr)
				n->middle = TST::node_ptr<T>(new node<T>());
			n->middle = put(std::move(n->middle), key, value, d+1);
		}
		if (n->c > key[d]) {
			if (n->right == nullptr)
				n->right = TST::node_ptr<T>(new node<T>());
			n->right = put(std::move(n->right), key, value, d+1);
		}
		return n;
	}
}

template <class T>
void TST::TST::clean(TST::node_ptr<T> n) {
	if (n->left   == nullptr) clean(n->left);
	if (n->middle == nullptr) clean(n->middle);
	if (n->right  == nullptr) clean(n->right);
	n.reset();
}

template <class T>
bool TST::TST::contains(const std::string & key) {

}

template <class T>
bool TST::TST::contains(TST::node_ptr<T> & n,
			const std::string & key,
			unsigned int d) {

}

template <class T>
void TST::TST::remove(const std::string & key) {

}

template <class T>
bool TST::TST::remove(TST::node_ptr<T> & n,
		      const std::string & key,
		      unsigned int d) {

}

template <class T>
std::vector<std::string> TST::TST::get_keys() {

}

template <class T>
std::vector<std::string> TST::TST::get_keys_with_prefix(const std::string & prefix) {

}

template <class T>
void TST::TST::get_keys_with_prefix(TST::node_ptr<T> & n,
				    std::string prefix,
				    unsigned int d,
				    TST::vec_ptr & v) {

}


template <class T>
void TST::TST::gather_keys(TST::node_ptr<T> & n,
			   std::string prefix,
			   TST::vec_ptr & v) {

}

template <class T>
void TST::TST::show() {

}
