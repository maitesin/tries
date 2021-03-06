// Copyright 2015 Maitesin
#ifndef TRIE_TST_H_
#define TRIE_TST_H_

#include <string>
#include <vector>
#include <array>
#include <memory>

namespace TST {

/*
 * Ternary Search Tree (TST)
 */
template <class T> class tst {
public:
  // Constructor
  explicit tst() : root(nullptr), s(0) { aux_ret = T(); }

  // Destructor
  ~tst() {
    if (root != nullptr)
      clear(std::move(root));
  }

  // Methods
  /**
   * This method is to allow the user to clean the
   * content of the trie. Basically does the same
   * as the destructor.
   */
  void clear() {
    if (root != nullptr)
      clear(std::move(root));
    s = 0;
    root = nullptr;
  }

  /**
   * This method return the value stored in the TST
   * for a specific key provided as parameter. If there
   * is no the key in the TST return default value for
   * the value type.
   */
  const T &find(const std::string &key);

  /**
   * This method is used to add a new key to the TST.
   * You must provide the key and the value to store.
   * If the key was not before in the TST it will
   * create the path to it and store the value.
   * Otherwise, if the key was already in the TST it
   * will update the value of the key with the new one.
   */
  void insert(const std::string &key, const T &value);

  /**
   * This method return the amount of elements stored
   * in the TST.
   */
  size_t size() { return s; }

  /**
   * This is an auxiliary method to print in the screen
   * the current set of keys of the TST.
   */
  void show();

  /**
   * This method is to remove a value from the TST.
   * You must provide the key that holds the value.
   * If the key exist deletes the value and delete
   * the path to it if there are no other keys that
   * are using it. Otherwise, if the key is not there
   * nothing will happen.
   */
  void erase(const std::string &key);

  /**
   * This method tells you if a given key is in the
   * TST.
   */
  bool contains(const std::string &key);

  /**
   * This method returns a vector of all keys in the
   * TST with the prefix provided. Moreover, if there
   * is no prefix provided it will return all keys in
   * the TST.
   */
  std::vector<std::string> keys(const std::string &prefix = "");

  /**
   * This method returns the longest common path.
   */
  std::string lcp();

private:
  /**
   * Node
   */
  struct node {
    T value;
    char c;
    std::unique_ptr<node> left, right, middle;
    explicit node(char ch, T v = T())
        : value(v), c(ch), left(nullptr), right(nullptr), middle(nullptr) {}
  };

  /**
   * Utils
   */
  using node_ptr = std::unique_ptr<node>;
  using vec_ptr = std::unique_ptr<std::vector<std::string>>;
  // Attributes
  node_ptr root;
  size_t s;
  const T def = T();
  T aux_ret;

  // Methods
  /*
   * Given a node goes down in the tree checking if
   * the d-th position in the key is equal to the char
   * hold by the node. If that is true we call the
   * method with the middle pointer and d+1. If the
   * char is less than the d-th position in the key
   * it calls the method with the left pointer and d.
   * If the char is greater than the d-th position in
   * the key it calls the method with the right pointer
   * and d.
   *
   * When key length is equal to d we are in the proper
   * place to check if the is any information stored.
   * For that we have to check if the value stored is
   * different from the default value for T.
   */
  node_ptr find(node_ptr &n, const std::string &key, size_t d);

  /*
   * Given a node it check if the tree contains a
   * node with in the d-th position, if not exists
   * is created. When the key legnth is equal to d
   * it assign the value tot he node's value.
   */
  node_ptr insert(node_ptr n, const std::string &key, const T &value, size_t d,
                  bool &created);

  /*
   * Given a node deleted everything under it.
   */
  void clear(node_ptr n);

  /*
   * Given a node it checks if the d-th position in
   * the key exists. When the key length is equal to
   * d we begin to delete all the nodes from that
   * one up to the first node with at least one of
   * the pointers different from nullptr.
   */
  bool erase(node_ptr &n, const std::string &key, size_t d, bool &decrease);

  /*
   * Given a node it checks if the d-th position in
   * the key exists. When the key length is equal to
   * d we check if the value is different from the
   * default value of T. If all that happens return
   * true else return false.
   */
  bool contains(node_ptr &n, const std::string &key, size_t d);

  /*
   * Given a node it checks if the d-th position in
   * the prefix exists. When the prefix length is
   * equal to d then it calls gather keys to get
   * all keys with that prefix.
   */
  void keys(node_ptr &n, std::string prefix, size_t d, vec_ptr &v);

  /*
   * Given a node goes to all its sons to gather
   * all the keys that are under the given node.
   * All those keys are stored in the vector.
   */
  void gather_keys(node_ptr &n, std::string prefix, vec_ptr &v);

  void show_label(node_ptr &n, size_t &label);

  void show(node_ptr &n, size_t &label);

  /*
   * Returns the longest common path from all the
   * strings contended in the TST.
   */
  std::string lcp(node_ptr &n, std::string s);
  std::string lcp_clean_before(node_ptr &n);
}; // TST_CLASS

}; // TST_NAMESPACE

#endif // TRIE_TST_H_
