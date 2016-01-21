// Copyright 2015 Maitesin
#include <string>
#include <vector>
#include <iostream>
#include "./TST.h"

template <class T> const T &TST::tst<T>::find(const std::string &key) {
  node_ptr node(find(root, key, 0));
  if (node != nullptr) {
    aux_ret = node->value;
    node.release();
    return aux_ret;
  } else {
    return def;
  }
}

template <class T>
typename TST::tst<T>::node_ptr
TST::tst<T>::find(TST::tst<T>::node_ptr &n, const std::string &key, size_t d) {
  if (key.size() == d + 1) {
    if (n == nullptr)
      return nullptr;
    else {
      if (n->c > key[d] && n->left != nullptr) {
        return find(n->left, key, d);
      }
      if (n->c == key[d]) {
        if (n->value != def)
          return node_ptr(n.get());
        else
          return nullptr;
      }
      if (n->c < key[d] && n->right != nullptr) {
        return find(n->right, key, d);
      }
    }
  } else {
    if (n != nullptr) {
      if (n->c > key[d] && n->left != nullptr) {
        return find(n->left, key, d);
      }
      if (n->c == key[d])
        return find(n->middle, key, d + 1);
      if (n->c < key[d] && n->right != nullptr) {
        return find(n->right, key, d);
      }
    }
  }
  return nullptr;
}

template <class T>
void TST::tst<T>::insert(const std::string &key, const T &value) {
  if (key == "")
    return;
  if (root == nullptr)
    root = node_ptr(new node(key[0]));
  bool created = false;
  root = insert(std::move(root), key, value, 0, created);
  if (created)
    ++s;
}

template <class T>
typename TST::tst<T>::node_ptr
TST::tst<T>::insert(TST::tst<T>::node_ptr n, const std::string &key,
                    const T &value, size_t d, bool &created) {
  if (key.size() == d + 1) {
    if (n->c > key[d]) {
      if (n->left == nullptr)
        n->left = node_ptr(new node(key[d]));
      n->left = insert(std::move(n->left), key, value, d, created);
    }
    if (n->c == key[d]) {
      if (n->value == def)
        created = true;
      n->value = value;
    }
    if (n->c < key[d]) {
      if (n->right == nullptr)
        n->right = node_ptr(new node(key[d]));
      n->right = insert(std::move(n->right), key, value, d, created);
    }
    return n;
  } else {
    if (n->c > key[d]) {
      if (n->left == nullptr)
        n->left = node_ptr(new node(key[d]));
      n->left = insert(std::move(n->left), key, value, d, created);
    }
    if (n->c == key[d]) {
      if (n->middle == nullptr)
        n->middle = node_ptr(new node(key[d + 1]));
      n->middle = insert(std::move(n->middle), key, value, d + 1, created);
    }
    if (n->c < key[d]) {
      if (n->right == nullptr)
        n->right = node_ptr(new node(key[d]));
      n->right = insert(std::move(n->right), key, value, d, created);
    }
    return n;
  }
}

template <class T> void TST::tst<T>::clear(TST::tst<T>::node_ptr n) {
  if (n->left != nullptr)
    clear(std::move(n->left));
  if (n->middle != nullptr)
    clear(std::move(n->middle));
  if (n->right != nullptr)
    clear(std::move(n->right));
  n.reset();
}

template <class T> bool TST::tst<T>::contains(const std::string &key) {
  return contains(root, key, 0);
}

template <class T>
bool TST::tst<T>::contains(TST::tst<T>::node_ptr &n, const std::string &key,
                           size_t d) {
  if (key.size() == d + 1) {
    if (n == nullptr)
      return false;
    if (n->c > key[d] && n->left != nullptr) {
      return contains(n->left, key, d);
    }
    if (n->c == key[d]) {
      return n->value != def;
    }
    if (n->c < key[d] && n->right != nullptr) {
      return contains(n->right, key, d);
    }
  } else {
    if (n->c > key[d] && n->left != nullptr) {
      return contains(n->left, key, d);
    }
    if (n->c == key[d]) {
      if (n->middle != nullptr)
        return contains(n->middle, key, d + 1);
      return false;
    }
    if (n->c < key[d] && n->right != nullptr) {
      return contains(n->right, key, d);
    }
  }
  return false;
}

template <class T> void TST::tst<T>::erase(const std::string &key) {
  bool decrease = false;
  erase(root, key, 0, decrease);
  if (decrease)
    --s;
}

template <class T>
bool TST::tst<T>::erase(TST::tst<T>::node_ptr &n, const std::string &key,
                        size_t d, bool &decrease) {
  if (key.size() == d + 1 && n != nullptr) {
    if (n->left != nullptr && n->c > key[d]) {
      if (n->left->c == key[d]) {
        bool deleted = erase(n->left, key, d, decrease);
        if (deleted) {
          n->left.reset();
          if (n->left == nullptr
	      && n->middle == nullptr
	      && n->right == nullptr
	      && n->value == def)
            return true;
        }
        return false;
      } else {
        return erase(n->left, key, d, decrease);
      }
    }
    if (n->c == key[d]) {
      if (n->value != def)
        decrease = true;
      n->value = T();
      if (n->left == nullptr
	  && n->middle == nullptr
	  && n->right == nullptr)
        return true;
    }
    if (n->right != nullptr && n->c < key[d]) {
      if (n->right->c == key[d]) {
        bool deleted = erase(n->right, key, d, decrease);
        if (deleted) {
          n->right.reset();
          if (n->left == nullptr
	      && n->middle == nullptr
	      && n->right == nullptr
	      && n->value == def)
            return true;
        }
        return false;
      } else {
        return erase(n->right, key, d, decrease);
      }
    }
  } else {
    if (n->left != nullptr && n->c > key[d]) {
      if (n->left->c == key[d]) {
        bool deleted = erase(n->left, key, d, decrease);
        if (deleted) {
          n->left.reset();
          if (n->left == nullptr
	      && n->middle == nullptr
	      && n->right == nullptr
	      && n->value == def)
            return true;
        }
        return false;
      } else {
        return erase(n->left, key, d, decrease);
      }
    }
    if (n->middle != nullptr && n->c == key[d]) {
      bool deleted = erase(n->middle, key, d + 1, decrease);
      if (deleted) {
        n->middle.reset();
        if (n->left == nullptr
	    && n->middle == nullptr
	    && n->right == nullptr
	    && n->value == def)
          return true;
      }
      return false;
    }
    if (n->right != nullptr && n->c < key[d]) {
      if (n->right->c == key[d]) {
        bool deleted = erase(n->right, key, d, decrease);
        if (deleted) {
          n->middle.reset();
          if (n->left == nullptr
	      && n->middle == nullptr
	      && n->right == nullptr
	      && n->value == def)
            return true;
        }
        return false;
      }
      if (n->right != nullptr && n->c < key[d]) {
        if (n->right->c == key[d]) {
          bool deleted = erase(n->right, key, d, decrease);
          if (deleted) {
            n->right.reset();
            if (n->left == nullptr
		&& n->middle == nullptr
		&& n->right == nullptr
		&& n->value == def)
              return true;
          }
          return false;
        } else {
          return erase(n->right, key, d, decrease);
        }
      } else {
        return erase(n->right, key, d, decrease);
      }
    }
  }
  return false;
}

template <class T>
std::vector<std::string> TST::tst<T>::keys(const std::string &prefix) {
  vec_ptr vec;
  vec = vec_ptr(new std::vector<std::string>());
  keys(root, prefix, 0, vec);
  return *vec;
}

template <class T>
void TST::tst<T>::keys(TST::tst<T>::node_ptr &n, std::string prefix, size_t d,
                       TST::tst<T>::vec_ptr &v) {
  if (prefix.size() <= d + 1) {
    if (prefix.size() == d + 1) {
      if (n->c > prefix[d] && n->left != nullptr)
        keys(n->left, prefix, d, v);
      if (n->c == prefix[d]) {
        if (n->value != def)
          v->push_back(prefix);
        gather_keys(n->middle, prefix, v);
      }
      if (n->c < prefix[d] && n->right != nullptr)
        keys(n->right, prefix, d, v);
    } else
      gather_keys(n, prefix, v);
  } else {
    if (n->c > prefix[d] && n->left != nullptr) {
      keys(n->left, prefix, d, v);
    }
    if (n->c == prefix[d] && n->middle != nullptr)
      keys(n->middle, prefix, d + 1, v);
    if (n->c < prefix[d] && n->right != nullptr) {
      keys(n->right, prefix, d, v);
    }
  }
}

template <class T>
void TST::tst<T>::gather_keys(TST::tst<T>::node_ptr &n, std::string prefix,
                              TST::tst<T>::vec_ptr &v) {
  if (n == nullptr)
    return;
  if (n->value != def) {
    v->push_back(prefix + n->c);
  }
  gather_keys(n->left, prefix, v);
  gather_keys(n->middle, prefix + n->c, v);
  gather_keys(n->right, prefix, v);
}

template <class T> void TST::tst<T>::show() {
  std::cout << "digraph graphName{" << std::endl;
  std::cout << "node [shape=record];" << std::endl;
  // Node labels
  size_t label = 0;
  std::cout << label << " [shape=record,label=\"{ <data> " << root->c
            << " | {<left> l | <middle> m | <right> r}}\"];" << std::endl;
  if (root->left != nullptr) {
    ++label;
    show_label(root->left, label);
  }
  if (root->middle != nullptr) {
    ++label;
    show_label(root->middle, label);
  }
  if (root->right != nullptr) {
    ++label;
    show_label(root->right, label);
  }
  // Node hierarchy
  label = 0;
  if (root->left != nullptr) {
    std::cout << "0:left"
              << "->";
    ++label;
    show(root->left, label);
  }
  if (root->middle != nullptr) {
    std::cout << "0:middle"
              << "->";
    ++label;
    show(root->middle, label);
  }
  if (root->right != nullptr) {
    std::cout << "0:right"
              << "->";
    ++label;
    show(root->right, label);
  }
  std::cout << "}" << std::endl;
}

template <class T>
void TST::tst<T>::show_label(TST::tst<T>::node_ptr &n, size_t &label) {
  std::cout << label << " [shape=record,label=\"{<data> " << n->c;
  if (n->value != T())
    std::cout << " | <value> " << n->value;
  std::cout << " | {<left> l | <middle> m | <right> r}}\"";
  if (n->value != T())
    std::cout << "color=\"blue\"";
  std::cout << "];" << std::endl;
  if (n->left != nullptr) {
    ++label;
    show_label(n->left, label);
  }
  if (n->middle != nullptr) {
    ++label;
    show_label(n->middle, label);
  }
  if (n->right != nullptr) {
    ++label;
    show_label(n->right, label);
  }
}

template <class T>
void TST::tst<T>::show(TST::tst<T>::node_ptr &n, size_t &label) {
  std::cout << label << ":data" << std::endl;
  size_t copy_label = label;
  if (n->left != nullptr) {
    std::cout << copy_label << ":left"
              << "->";
    ++label;
    show(n->left, label);
  }
  if (n->middle != nullptr) {
    std::cout << copy_label << ":middle"
              << "->";
    ++label;
    show(n->middle, label);
  }
  if (n->right != nullptr) {
    std::cout << copy_label << ":right"
              << "->";
    ++label;
    show(n->right, label);
  }
}

template <class T> std::string TST::tst<T>::lcp() {
  return lcp_clean_before(root);
}

template <class T>
std::string TST::tst<T>::lcp_clean_before(TST::tst<T>::node_ptr &n) {
  if (n == nullptr) {
    return "";
  }
  if (n->middle == nullptr) {
    if (n->left == nullptr && n->right != nullptr) {
      return lcp_clean_before(n->right);
    } else if (n->left != nullptr && n->right == nullptr) {
      return lcp_clean_before(n->left);
    } else if (n->left == nullptr && n->right == nullptr) {
      return "";
    }
  } else {
    return lcp(n, "");
  }
  return "";
}

template <class T>
std::string TST::tst<T>::lcp(TST::tst<T>::node_ptr &n, std::string s) {
  if (n != nullptr
      && n->left == nullptr
      && n->right == nullptr) {
    return lcp(n->middle, s + n->c);
  }
  return s;
}
