// Copyright 2015 Maitesin
#include <string>
#include <vector>
#include <iostream>
#include "./radix_tree.h"

template <class T, size_t R>
const T & RadixTree::radix_tree<T,R>::get(const std::string & key) {
	// TODO
}

template <class T, size_t R>
RadixTree::node_ptr<T,R> RadixTree::radix_tree<T,R>::get(RadixTree::node_ptr<T,R> & n,
							 const std::string & key,
							 unsigned int d) {
	// TODO
}

template <class T, size_t R>
void RadixTree::radix_tree<T,R>::put(const std::string & key,
				     const T & value) {
	// TODO
}

template <class T, size_t R>
RadixTree::node_ptr<T,R> RadixTree::radix_tree<T,R>::put(RadixTree::node_ptr<T,R> n,
							 const std::string & key,
							 const T & value,
							 unsigned int d) {
	// TODO
}

template <class T, size_t R>
void RadixTree::radix_tree<T,R>::clean(RadixTree::node_ptr<T,R> n) {
	// TODO
}

template <class T, size_t R>
bool RadixTree::radix_tree<T,R>::contains(const std::string & key) {
	// TODO
}

template <class T, size_t R>
bool RadixTree::radix_tree<T,R>::contains(RadixTree::node_ptr<T,R> & n,
					  const std::string & key,
					  unsigned int d) {
	// TODO
}


template <class T, size_t R>
void RadixTree::radix_tree<T,R>::remove(const std::string & key) {
	// TODO
}

template <class T, size_t R>
bool RadixTree::radix_tree<T,R>::remove(RadixTree::node_ptr<T,R> & n,
					const std::string & key,
					unsigned int d,
					bool & decrease) {
	// TODO
}


template <class T, size_t R>
std::vector<std::string> RadixTree::radix_tree<T,R>::get_keys() {
	// TODO
}

template <class T, size_t R>
std::vector<std::string> RadixTree::radix_tree<T,R>::get_keys_with_prefix(const std::string & prefix) {
	// TODO
}

template <class T, size_t R>
void RadixTree::radix_tree<T,R>::get_keys_with_prefix(RadixTree::node_ptr<T,R> & n,
						      std::string prefix,
						      unsigned int d,
						      vec_ptr & v) {
	// TODO
}

template <class T, size_t R>
void RadixTree::radix_tree<T,R>::gather_keys(RadixTree::node_ptr<T,R> & n,
					     std::string prefix,
					     vec_ptr & v) {
	// TODO
}

template <class T, size_t R>
void RadixTree::radix_tree<T,R>::show() {
	// TODO
}
