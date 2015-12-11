// Copyright 2014 Maitesin
#ifndef TRIE_TRIE_H_
#define TRIE_TRIE_H_

#include <string>
#include <vector>
#include <array>
#include <memory>

namespace Trie {
	/*
	 * Trie
	 */
	template <class T, size_t R>
		class trie {
	public:
		// Constructor
		explicit trie() : r(R), s(0) {
			root = node_ptr(new node);
		}
		// Destructor
		~trie() {
			clear(std::move(root));
		}
		// Methods
		/**
		 * This method is to allow the user to clear the
		 * content of the trie. Basically does the same
		 * as the destructor.
		 */
		void clear() {
		  clear(std::move(root));
		  s = 0;
		  root = node_ptr(new node);
		}

		/**
		 * This method return the value stored in the trie
		 * for a specific key provided as parameter. If there
		 * is no the key in the trie return default value for
		 * the value type.
		 */
		const T & find(const std::string & key);

		/**
		 * This method is used to add a new key to the trie.
		 * You must provide the key and the value to store.
		 * If the key was not before in the trie it will
		 * create the path to it and store the value.
		 * Otherwise, if the key was already in the trie it
		 * will update the value of the key with the new one.
		 */
		void insert(const std::string & key,
			 const T & value);

		/**
		 * This method return the amount of elements stored
		 * in the trie.
		 */
		size_t size() {return s;}

		/**
		 * This is an auxiliary method to print in the screen
		 * the current set of keys of the trie.
		 */
		void show();

		/**
		 * This method is to remove a value from the trie.
		 * You must provide the key that holds the value.
		 * If the key exist deletes the value and delete
		 * the path to it if there are no other keys that
		 * are using it. Otherwise, if the key is not there
		 * nothing will happen.
		 */
		void erase(const std::string & key);

		/**
		 * This method tells you if a given key is in the
		 * trie.
		 */
		bool contains(const std::string & key);

		/**
		 * This method returns a vector of all keys in the
		 * trie with the prefix provided. If there is no
		 * prefix provided it will return all the keys in
		 * the trie.
		 */
		std::vector<std::string> keys(const std::string & prefix = "");

		/**
		 * This method returns the longest common prefix
		 * of the content in the Trie.
		 */
		std::string lcp();

	private:
		/*
		 * Node
		 */
		struct node {
			T value;
			std::array<std::unique_ptr<node>, R> sons;
			size_t s;
			size_t r;

			explicit node(T v = T()) : value(v), s(0), r(R) {
				sons = std::array<std::unique_ptr<node>, R>();
				for (size_t i = 0; i < r; ++i) {
					sons[i] = nullptr;
				}
			}
		};

		/*
		 * Utils
		 */
		using node_ptr = std::unique_ptr<node>;
		using vec_ptr = std::unique_ptr<std::vector<std::string>>;


		// Attributes
		node_ptr root;
		size_t r;
		size_t s;
		// Default value of T to return.
		const T def = T();
		// Helper value to help return found values.
		T aux_ret;
		// Methods
		/*
		 * Given a node it checks if the d-th position in
		 * the key exists in the node's sons. If that is
		 * true call himself but with d+1. When the key
		 * length is equal to d we check if the value
		 * is diferent from the default value for T.
		 */
		node_ptr find(node_ptr & n,
				  const std::string & key,
				  size_t d);

		/*
		 * Given a node it checks if the d-th position in
		 * the key exists, if not exists it is created.
		 * When the key length is equal to d we assign
		 * the value to the node's value.
		 */
		node_ptr insert(node_ptr n,
				  const std::string & key,
				  const T & value,
				  size_t d,
				  bool & created);

		/*
		 * Given a node deleted everything under it.
		 */
		void clear(node_ptr n);

		/*
		 * Given a node it checks if the d-th position in
		 * the key exists. When the key length is equal to
		 * d we begin to delete all the nodes from that
		 * one up to the first node with at least one son.
		 */
		bool erase(node_ptr & n,
			    const std::string & key,
			    size_t d,
			    bool & decrease);

		/*
		 * Given a node it checks if the d-th position in
		 * the key exists. When the key length is equal to
		 * d we check if the value is different from the
		 * default value of T. If all that happens return
		 * true else return false.
		 */
		bool contains(node_ptr & n,
			      const std::string & key,
			      size_t d);

		/*
		 * Given a node it checks if the d-th position in
		 * the prefix exists. When the prefix length is
		 * equal to d then it calls gather keys to get
		 * all keys with that prefix.
		 */
		void keys(node_ptr & n,
			      std::string prefix,
			      size_t d,
			      vec_ptr & v);
		/*
		 * Given a node goes to all its sons to gather
		 * all the keys that are under the given node.
		 * All those keys are stored in the vector.
		 */
		void gather_keys(node_ptr & n,
				 std::string prefix,
				 vec_ptr & v);


		/*
		 * Given a node prints the its value and the
		 * ones for its sons in the 'dot' format.
		 */
		void show_label(node_ptr & n, size_t pos, size_t & label);
		void show(node_ptr & n, size_t pos, size_t & label);

		/*
		 * Returns the longest common prefix
		 */
		std::string lcp(node_ptr &n, std::string s);
	}; // TRIE_CLASS

}; // TRIE_NAMESPACE

#endif  // TRIE_TRIE_H_
