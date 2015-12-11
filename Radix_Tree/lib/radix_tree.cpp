// Copyright 2015 Maitesin
#include <string>
#include <vector>
#include <iostream>
#include "./radix_tree.h"

template <class T, size_t R>
const T & RadixTree::radix_tree<T,R>::find(const std::string & key) {
	if (key != "") {
		if (roots[key[0]] != nullptr){
			node_ptr node (find(roots[key[0]], key, 0));
			if (node != nullptr){
				aux_ret = node->value;
				node.release();
				return aux_ret;
			}
		}
		return def;
	}
	return def;
}

template <class T, size_t R>
typename RadixTree::radix_tree<T,R>::node_ptr RadixTree::radix_tree<T,R>::find(RadixTree::radix_tree<T,R>::node_ptr & n,
							 const std::string & key,
							 size_t d) {
	if (n != nullptr) {
		if (key.size() < d + n->path.size()) {
			return nullptr;
		}
		else {
			std::string sub = key.substr(d, n->path.size());
			if (n->path == sub) {
				if (key.size() > d + n->path.size()) {
					// Call it again
					return find(n->sons[key[d+n->path.size()]], key, d+n->path.size());
				}
				else {
					// We found it
					if (n->value != def) {
						return node_ptr(n.get());
					}
				}
			}
		}
	}
	return nullptr;
}

template <class T, size_t R>
void RadixTree::radix_tree<T,R>::insert(const std::string & key,
				     const T & value) {
	if (key != ""){
		bool created = false;
		roots[key[0]] = insert(std::move(roots[key[0]]), key, value, 0, created);
		if (created)
			++s;
	}
}

template <class T, size_t R>
typename RadixTree::radix_tree<T,R>::node_ptr RadixTree::radix_tree<T,R>::insert(RadixTree::radix_tree<T,R>::node_ptr n,
							 const std::string & key,
							 const T & value,
							 size_t d,
							 bool & created) {
	if (n != nullptr) {
		if (key.size() < d + n->path.size()) {
			// We have to split this node
			std::string sub_key = key.substr(d, key.size()-d);
			std::string sub_path = n->path.substr(0, sub_key.size());
			if (sub_key == sub_path) {
				// The path for the key already exists, now split a this point.
				created = true;
				split(n, value, sub_path.size());
				return n;
			}
			else {
				// The path does not match. Find where begin the difference and split there
				created = true;
				find_diff_and_split(n, key, value);
				return n;
			}
		}
		else {
			std::string sub_key = key.substr(d, n->path.size());
			if (n->path == sub_key) {
				if (key.size() > d + n->path.size()) {
					// Call it again with the right son and updating the depth
					n->s += n->sons[key[d+n->path.size()]] != nullptr ? 1 : 0;
					// Added 1 to the size of n if the right son is null
					n->sons[key[d+n->path.size()]] = insert(std::move(n->sons[key[d+n->path.size()]]), key, value, d+n->path.size(), created);
					++n->s;
					return n;
				}
				else {
					// We found it
					if (n->value == def)
						created = true;
					n->value = value;
					return n;
				}
			}
			else {
				// The path does not match. Find where begin the difference and split there
				created = true;
				find_diff_and_split(n, key, value);
				return n;
			}
		}
	}
	else {
		// Create a new node with the information remaining
		created = true;
		return radix_tree<T,R>::node_ptr(new node(key.substr(d, key.size()-d), value));
	}
}

template <class T, size_t R>
void RadixTree::radix_tree<T,R>::split(RadixTree::radix_tree<T,R>::node_ptr & n,
				       const T & value,
				       size_t p) {
	std::string upper_path = n->path.substr(0, p);
	std::string lower_path = n->path.substr(p, n->path.size()-p);
	n->sons[lower_path[0]] = node_ptr(new node(lower_path, n->value));
	n->sons[lower_path[0]]->s = n->s;
	n->value = value;
	n->path = upper_path;
	++n->s;
}

template <class T, size_t R>
void RadixTree::radix_tree<T,R>::find_diff_and_split(RadixTree::radix_tree<T,R>::node_ptr & n,
						     const std::string & key,
						     const T & value) {
	size_t p_s = n->path.size();
	size_t k_s = key.size();
	size_t len = p_s < k_s ? p_s : k_s; // Take the min of both sizes
	for (size_t i = 0; i < len; ++i) {
		if (n->path[i] != key[i]){
			split(n, T(), i);
			std::string branch = key.substr(i, key.size()-i);
			n->sons[branch[0]] = node_ptr(new node(branch, value));
			++n->s;
			return ;
		}
	}
}

template <class T, size_t R>
void RadixTree::radix_tree<T,R>::clear(RadixTree::radix_tree<T,R>::node_ptr n) {
	for (size_t i = 0; i < n->r; ++i) {
		if (n->sons[i] != nullptr) clear(std::move(n->sons[i]));
	}
	n.reset();
}

template <class T, size_t R>
bool RadixTree::radix_tree<T,R>::contains(const std::string & key) {
	if (roots[key[0]] != nullptr) {
		return contains(roots[key[0]], key, 0);
	}
	return false;
}

template <class T, size_t R>
bool RadixTree::radix_tree<T,R>::contains(RadixTree::radix_tree<T,R>::node_ptr & n,
					  const std::string & key,
					  size_t d) {
	if (n != nullptr) {
		if (key.size() < d + n->path.size()) {
			return false;
		}
		else {
			std::string sub = key.substr(d, n->path.size());
			if (n->path == sub) {
				if (key.size() > d + n->path.size()) {
					// Call it again
					return contains(n->sons[key[d+n->path.size()]], key, d+n->path.size());
				}
				else {
					// We found it
					if (n->value != def) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

template <class T, size_t R>
void RadixTree::radix_tree<T,R>::erase(const std::string & key) {
	bool decrease = false;
	if (roots[key[0]] != nullptr)
		erase(roots[key[0]], key, 0, decrease);
	if (decrease)
		--s;
}

template <class T, size_t R>
bool RadixTree::radix_tree<T,R>::erase(RadixTree::radix_tree<T,R>::node_ptr & n,
					const std::string & key,
					size_t d,
					bool & decrease) {
	if (n != nullptr) {
		if (key.size() < d + n->path.size()) {
			return false;
		}
		else {
			std::string sub = key.substr(d, n->path.size());
			if (n->path == sub) {
				if (key.size() > d + n->path.size()) {
					// Call it again
					bool deleted = erase(n->sons[key[d+n->path.size()]], key, d+n->path.size(), decrease);
					if (deleted) {
						n->sons[key[d+n->path.size()]].reset();
						n->sons[key[d+n->path.size()]] =
							nullptr;
						--n->s;
						if (n->s == 1 && n->value == T()) {
							merge_with_only_son(n);
							return true;
						}
					}
					return false;
				}
				else {
					// We found it
					if (n->value != def) {
						decrease = true;
						n->value = T();
						if (n->s == 0) {
							return true;
						}
						if (n->s == 1) {
							merge_with_only_son(n);
							return true;
						}
						return false;
					}
				}
			}
		}
	}
	return false;
}

template <class T, size_t R>
void RadixTree::radix_tree<T,R>::merge_with_only_son(RadixTree::radix_tree<T,R>::node_ptr & n) {
	if (n->s == 1){
		for (size_t i = 0; i < r; ++i) {
			if (n->sons[i] != nullptr) {
				merge(n, n->sons[i]);
				break;
			}
		}
	}
}

template <class T, size_t R>
void RadixTree::radix_tree<T,R>::merge(RadixTree::radix_tree<T,R>::node_ptr & father,
				       RadixTree::radix_tree<T,R>::node_ptr & son) {
	father->value = son->value;
	father->s = son->s;
	father->path += son->path;
	if (father->s != 0) {
	        size_t left = 0;
	        for(size_t i = 0; i < r && left < father->s; ++i) {
		        if (son->sons[i] != nullptr) {
		                father->sons[i] = std::move(son->sons[i]);
				++left;
		        }
		}
	}
}

template <class T, size_t R>
std::vector<std::string> RadixTree::radix_tree<T,R>::keys(const std::string & prefix) {
	vec_ptr vec;
	vec = vec_ptr(new std::vector<std::string>());
	if (prefix == "") {
		for (size_t i = 0; i < r; ++i) {
			if (roots[i] != nullptr) {
				gather_keys(roots[i], "", vec);
			}
		}
	}
	else if (roots[prefix[0]] != nullptr)
		keys(roots[prefix[0]], prefix, 0, vec);
	return *vec;
}

template <class T, size_t R>
void RadixTree::radix_tree<T,R>::keys(RadixTree::radix_tree<T,R>::node_ptr & n,
					  std::string prefix,
					  size_t d,
					  vec_ptr & v) {
	if (prefix.size() < d + n->path.size()) {
		for (size_t i = d; i < prefix.size(); ++i){
			if (prefix[i] != n->path[i-d])
				return;
		}
		// Is sure the begining is equal
		gather_keys(n, prefix_cut(prefix, d), v);
		return;
	}
	else {
		std::string sub = prefix.substr(d, n->path.size());
		if (n->path == sub) {
			if (prefix.size() > d + n->path.size()) {
				// Call it again
			        if (n->sons[prefix[d+n->path.size()]] != nullptr) {
				  keys(n->sons[prefix[d+n->path.size()]], prefix_cut(prefix, d+n->path.size()), d+n->path.size(), v);
				}
				return;
			}
			else {
				// We found it
				gather_keys(n, prefix_cut(prefix, d), v);
				return;
			}
		}
	}
}

template <class T, size_t R>
std::string RadixTree::radix_tree<T,R>::prefix_cut(std::string & prefix, size_t d) {
	std::string cut = "";
	for (size_t i = 0; i < d; ++i) {
		cut += prefix[i];
	}
	return cut;
}

template <class T, size_t R>
void RadixTree::radix_tree<T,R>::gather_keys(RadixTree::radix_tree<T,R>::node_ptr & n,
					     std::string prefix,
					     vec_ptr & v) {
	if (n->value != def) {
		v->push_back(prefix + n->path);
	}
	if (n->s != 0) {
		for (size_t i = 0; i < n->r; ++i) {
			if (n->sons[i] != nullptr) {
				gather_keys(n->sons[i], prefix + n->path, v);
			}
		}
	}
}

template <class T, size_t R>
void RadixTree::radix_tree<T,R>::show() {
	std::cout << "digraph graphName{" << std::endl;
	std::cout << "node [shape=record];" << std::endl;
	// Node labels
	size_t label = 0;
	std::cout << label << " [shape=record,label=\"{Root}\"];" << std::endl;;
	for (size_t i = 0; i < r; ++i) {
	        if (roots[i] != nullptr) {
			++label;
			show_label(roots[i], label);
		}
	}
	// Node hierarchy
	label = 0;
	for (size_t i = 0; i < r; ++i) {
	        if (roots[i] != nullptr) {
                        std::cout << 0 << "->";
			++label;
			show(roots[i], label);
		}
	}
	std::cout << "}"<< std::endl;
}

template <class T, size_t R>
void RadixTree::radix_tree<T,R>::show_label(RadixTree::radix_tree<T,R>::node_ptr & n,
					    size_t & label) {
         std::cout << label << " [shape=record,label=\"{ <data> " << n->path;
	 if (n->value != T())
	         std::cout << " | <value> " << n->value;
	 std::cout << "}\"";
	 if (n->value != T())
	         std::cout << "color=\"blue\"";
	 std:: cout << "];" << std::endl;
         for (size_t i = 0; i < n->r; ++i) {
	        if (n->sons[i] != nullptr) {
		        ++label;
			show_label(n->sons[i], label);
		}
	}
}

template <class T, size_t R>
void RadixTree::radix_tree<T,R>::show(RadixTree::radix_tree<T,R>::node_ptr & n,
				      size_t & label) {
         std::cout << label << std::endl;
	 size_t copy_label = label;
         for (size_t i = 0; i < n->r; ++i) {
	        if (n->sons[i] != nullptr) {
		        std::cout << copy_label << "->";
			++label;
			show(n->sons[i], label);
		}
	}
}

template <class T, size_t R>
std::string RadixTree::radix_tree<T,R>::lcp(){
	unsigned int founds = 0;
	std::string lcp = "";
	for (unsigned int i = 0; i < r; ++i){
		if (roots[i] != nullptr && roots[i]->s > 0) {
			++founds;
			lcp = roots[i]->path;
		}
	}
	return founds == 1 ? lcp : "";
};
