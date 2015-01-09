//Copyright 2015 Maitesin
#include <string>
#include <vector>
#include <iostream>
#include "./TST.h"

template <class T>
const T & TST::TST::get(const std::string & key) {

}

template <class T>
node_ptr<T> TST::TST::get(TST::node_ptr<T> & n,
			  const std::string & key,
			  unsigned int d) {

}

template <class T>
void TST::TST::put(const std::string & key,
		   const T & value) {

}

template <class T>
node_ptr<T> TST::TST::put(TST::node_ptr<T> n,
			  const std::string & key,
			  unsigned int d) {

}

template <class T>
void TST::TST::clean(TST::node_ptr<T> n) {

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
