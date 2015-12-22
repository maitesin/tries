// Copyright 2015 Maitesin
#ifndef TRIE_RADIX_TREE_H
#define TRIE_RADIX_TREE_H

#include <string>
#include <vector>
#include <array>
#include <memory>

namespace RadixTree {
	/*
	 * Radix Tree
	 */
	template <class T, size_t R>
		class radix_tree {
	public:
		// Constructor
		explicit radix_tree() : r(R), s(0) {
			roots = std::array<node_ptr, R>();
			for (size_t i = 0; i < r; ++i) {
				roots[i] = nullptr;
			}
			aux_ret = T();
		}
		// Destructor
		~radix_tree() {
			for (size_t i = 0; i < r; ++i) {
				if (roots[i] != nullptr)
					clear(std::move(roots[i]));
			}
		}

		// Methods
		/**
		 * This method is to allow the user to clear the
		 * content of the trie. Basically does the same
		 * as the destructor.
		 */
		void clear() {
		  for (size_t i = 0; i < r; ++i) {
		    if (roots[i] != nullptr)
		      clear(std::move(roots[i]));
		  }
		  s = 0;
		  roots = std::array<node_ptr, R>();
		  for (size_t i = 0; i < r; ++i) {
		    roots[i] = nullptr;
		  }
		}
		/**
		 * This method return the value stored in the radix tree
		 * for a specific key provided as parameter. If there
		 * is no the key in the radix tree return default value
		 * for the value type.
		 */
		const T & find(const std::string & key);

		/**
		 * This method is used to add a new key to the radix tree.
		 * You must provide the key and the value to store.
		 * If the key was not before in the radix tree it will
		 * create the path to it and store the value.
		 * Otherwise, if the key was already in the radix tree it
		 * will update the value of the key with the new one.
		 */
		void insert(const std::string & key,
			 const T & value);

		/**
		 * This method return the amount of elements stored
		 * in the radix tree.
		 */
		size_t size() {return s;}

		/**
		 * This is an auxiliary method to print in the screen
		 * the current set of keys of the radix tree.
		 */
		void show();

		/**
		 * This method is to erase a value from the radix tree.
		 * You must provide the key that holds the value.
		 * If the key exist deletes the value and delete
		 * the path to it if there are no other keys that
		 * are using it. Otherwise, if the key is not there
		 * nothing will happen.
		 */
		void erase(const std::string & key);

		/**
		 * This method tells you if a given key is in the
		 * radix tree.
		 */
		bool contains(const std::string & key);

		/**
		 * This method returns a vector of all keys in the
		 * radix tree with the prefix provided. Moreover, if
		 * there is not prefix provided it will return all 
		 * keys in the Radix Tree.
		 */
		std::vector<std::string> keys(const std::string & prefix = "");

		/**
		 * This method returns the longest common path
		 * of the content in the Radix Tree.
		 */
		std::string lcp();

	private:
		/*
		 * Node
		 */
		struct node {
			T value;
			std::string path;
			size_t s;
			size_t r;
			std::array<std::unique_ptr<node>, R> sons;

			explicit node(std::string p, T v = T()) : value(v), path(p), s(0), r(R) {
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
		std::array<node_ptr, R> roots;
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
		 * Auxiliar method to split a node in two from
		 * the given position in the path.
		 */
		node_ptr split(node_ptr n,
			       const T & value,
			       size_t p);

		/*
		 * Auxiliar method that find where begins the
		 * difference and splits there
		 */
		node_ptr find_diff_and_split(node_ptr n,
					     const std::string & key,
					     const T & value);

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

		void merge_with_only_son(node_ptr & n);
		void merge(node_ptr & father,
			   node_ptr & son);

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
		 * equal to d then it calls gather keys to find
		 * all keys with that prefix.
		 */
		void keys(node_ptr & n,
			      std::string prefix,
			      size_t d,
			      vec_ptr & v);

		std::string prefix_cut(std::string & prefix,
					size_t d);

		/*
		 * Given a node goes to all its sons to gather
		 * all the keys that are under the given node.
		 * All those keys are stored in the vector.
		 */
		void gather_keys(node_ptr & n,
				 std::string prefix,
				 vec_ptr & v);


		void show_label(node_ptr & n,
				size_t & label);

		void show(node_ptr & n,
			  size_t & label);
	}; // RADIX_TREE_CLASS

}; // RADIX_TREE_NAMESPACE

#endif // TRIE_RADIX_TREE_H
