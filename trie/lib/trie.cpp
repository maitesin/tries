// Copyright 2014 Maitesin
#include <string>
#include <vector>
#include <iostream>
#include "./trie.h"

template <class T, size_t R>
const T & Trie::trie<T,R>::find(const std::string & key) {
	if (key != "") {
		node_ptr<T,R> node (find(root, key, 0));
		if (node != nullptr){
			aux_ret = node->value;
			node.release();
			return aux_ret;
		} else {
			return def;
		}
	}
	return def;
}

template <class T, size_t R>
Trie::node_ptr<T,R> Trie::trie<T,R>::find(Trie::node_ptr<T,R> & n,
					 const std::string & key,
					 size_t d) {
	if (key.size() == d) {
		if (n == nullptr) {
			return nullptr;
		} else {
			if (n->value != def)
				return node_ptr<T,R>(n.get());
			else
				return nullptr;
		}
	} else {
		if (n->sons[key[d]] != nullptr) {
			return find(n->sons[key[d]], key, d+1);
		}
	}
	return nullptr;
}

template <class T, size_t R>
void Trie::trie<T,R>::insert(const std::string & key,
			  const T & value) {
	if (key != ""){
		bool created = false;
		root = insert(std::move(root), key, value, 0, created);
		if (created)
			++s;
	}
}

template <class T, size_t R>
Trie::node_ptr<T,R> Trie::trie<T,R>::insert(Trie::node_ptr<T,R> n,
					 const std::string & key,
					 const T & value,
					 size_t d,
					 bool & created) {
	if (key.size() == d) {
		if (n->value == def)
			created = true;
		n->value = value;
		return n;
	} else {
		if (n->sons[key[d]] == nullptr) {
			n->sons[key[d]] = Trie::node_ptr<T,R>(new node<T,R>());
			++n->s;
		}
		n->sons[key[d]] = insert(std::move(n->sons[key[d]]), key, value, d+1, created);
		return n;
	}
}

template <class T, size_t R>
void Trie::trie<T,R>::clear(Trie::node_ptr<T,R> n) {
	for (size_t i = 0; i < n->r; ++i) {
		if (n->sons[i] != nullptr) clear(std::move(n->sons[i]));
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
			       size_t d) {
	if (key.size() ==d) {
		if (n == nullptr) return false;
		return n->value != def;
	} else {
		if (n->sons[key[d]] != nullptr) {
			return contains(n->sons[key[d]], key, d+1);
		}
		return false;
	}
}


template <class T, size_t R>
void Trie::trie<T,R>::erase(const std::string & key) {
	bool decrease = false;
	erase(root, key, 0, decrease);
	if (decrease)
		--s;
}

template <class T, size_t R>
bool Trie::trie<T,R>::erase(Trie::node_ptr<T,R> & n,
			     const std::string & key,
			     size_t d,
			     bool & decrease) {
	if (key.size() == d && n != nullptr) {
		if (n->value != def)
			decrease = true;
		n->value = T();
		return n->s == 0;
	} else {
		if (n != nullptr && n->sons[key[d]] != nullptr) {
			bool deleted = erase(n->sons[key[d]], key, d+1, decrease);
			if (deleted) {
				n->sons[key[d]].reset();
				--n->s;
				if (n->s == 0 && n->value == def)
					return true;
			}
			return false;
		}
		return false;
	}
}


template <class T, size_t R>
std::vector<std::string> Trie::trie<T,R>::keys(const std::string & prefix) {
	vec_ptr vec;
	vec = vec_ptr(new std::vector<std::string>());
	keys(root, prefix, 0, vec);
	return *vec;
}

template <class T, size_t R>
void Trie::trie<T,R>::keys(Trie::node_ptr<T,R> & n,
			       std::string prefix,
			       size_t d,
			       vec_ptr & v) {
	if (prefix.size() == d) {
		gather_keys(n, prefix, v);
	} else {
		if (n->sons[prefix[d]] != nullptr)
			keys(n->sons[prefix[d]], prefix, d+1, v);
	}
}

template <class T, size_t R>
void Trie::trie<T,R>::gather_keys(Trie::node_ptr<T,R> & n,
				  std::string prefix,
				  vec_ptr & v) {
	if (n->value != def) {
		v->push_back(prefix);
	}
	if (n->s != 0) {
		for (size_t i = 0; i < n->r; ++i) {
			if (n->sons[i] != nullptr) {
				gather_keys(n->sons[i], prefix + static_cast<char>(i), v);
			}
		}
	}
}

template <class T, size_t R>
void Trie::trie<T,R>::show() {
        std::cout << "digraph graphName{" << std::endl;
	std::cout << "node [shape=record];" << std::endl;
	// Node labels
	size_t label = 0;
	std::cout << label << " [shape=record,label=\"{Root}\"];" << std::endl;;
	for (size_t i = 0; i < root->r; ++i) {
	        if (root->sons[i] != nullptr) {
			++label;
			show_label(root->sons[i], i, label);
		}
	}
	// Node hierarchy
	label = 0;
	for (size_t i = 0; i < root->r; ++i) {
	        if (root->sons[i] != nullptr) {
                        std::cout << 0 << "->";
			++label;
			show(root->sons[i], i, label);
		}
	}
	std::cout << "}"<< std::endl;
}


template <class T, size_t R>
void Trie::trie<T,R>::show_label(Trie::node_ptr<T,R> & n, size_t pos, size_t & label) {
         std::cout << label << " [shape=record,label=\"{ <data>" << static_cast<char>(pos);
	 if (n->value != T())
	         std::cout << " | <value> " << n->value;
	 std::cout << "}\"";
	 if (n->value != T())
	         std::cout << "color=\"blue\"";
	 std:: cout << "];" << std::endl;
         for (size_t i = 0; i < n->r; ++i) {
	        if (n->sons[i] != nullptr) {
		        ++label;
			show_label(n->sons[i], i, label);
		}
	}
}

template <class T, size_t R>
void Trie::trie<T,R>::show(Trie::node_ptr<T,R> & n, size_t pos, size_t & label) {
         std::cout << label << std::endl;
	 size_t copy_label = label;
         for (unsigned int i = 0; i < n->r; ++i) {
	        if (n->sons[i] != nullptr) {
		        std::cout << copy_label << "->";
			++label;
			show(n->sons[i], i, label);
		}
	}
}

template <class T, size_t R>
std::string Trie::trie<T,R>::lcp() {
	return lcp(root, "");
}

template <class T, size_t R>
std::string Trie::trie<T,R>::lcp(Trie::node_ptr<T,R> &n, std::string s) {
	if (n->s == 1) {
		for (unsigned int i = 0; i < n->r; ++i) {
			if (n->sons[i] != nullptr) {
				return lcp(n->sons[i], s + static_cast<char>(i));
			}
		}
	}
	return s;
};
