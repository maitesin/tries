// Copyright 2014 Maitesin
#ifndef TRIE_TRIE_H_
#define TRIE_TRIE_H_

#include <string>
#include <vector>
#include <array>
#include <memory>

namespace Trie {
	/*
	 * Node
	 */
	template <class T, size_t R>
		struct node {
			T value;
			std::array<std::unique_ptr<node<T,R>>, R> sons;
			unsigned int s;
			unsigned int r;

			explicit node(T v = T()) : value(v), s(0), r(R) {
				sons = std::array<std::unique_ptr<node<T,R>>, R>();
				for (unsigned int i = 0; i < r; ++i) {
					sons[i] = nullptr;
				}
			}
		};

	/*
	 * Utils
	 */
	template <class T, size_t R>
		using node_ptr = std::unique_ptr<node<T,R>>;	
	using vec_ptr = std::unique_ptr<std::vector<std::string>>;
	
	/*
	 * Trie
	 */
	template <class T, size_t R>
		class trie {
	public:
		// Constructor
		explicit trie() : r(R), s(0) {
			root = node_ptr<T,R>(new node<T,R>);
		}
		// Destructor
		~trie() {
			clean(std::move(root));
		}
		// Methods
		/*
		 * This method is to allow the user to clean the
		 * content of the trie. Basically does the same
		 * as the destructor.
		 */
		void clean() {
		  clean(std::move(root));
		  s = 0;
		  root = node_ptr<T,R>(new node<T,R>);
		}
		
		/*
		 * This method return the value stored in the trie
		 * for a specific key provided as parameter. If there
		 * is no the key in the trie return default value for
		 * the value type.
		 */
		const T & get(const std::string & key);
		
		/*
		 * This method is used to add a new key to the trie.
		 * You must provide the key and the value to store.
		 * If the key was not before in the trie it will
		 * create the path to it and store the value.
		 * Otherwise, if the key was already in the trie it
		 * will update the value of the key with the new one.
		 */
		void put(const std::string & key,
			 const T & value);
		
		/*
		 * This method return the amount of elements stored
		 * in the trie.
		 */
		unsigned int size() {return s;}
		
		/*
		 * This is an auxiliary method to print in the screen
		 * the current set of keys of the trie.
		 */
		void show();
		
		/*
		 * This method is to remove a value from the trie.
		 * You must provide the key that holds the value.
		 * If the key exist deletes the value and delete
		 * the path to it if there are no other keys that
		 * are using it. Otherwise, if the key is not there
		 * nothing will happen.
		 */
		void remove(const std::string & key);
		
		/*
		 * This method tells you if a given key is in the
		 * trie.
		 */
		bool contains(const std::string & key);
		
		/*
		 * This method returns a vector of all keys in the
		 * trie with the prefix provided.
		 */
		std::vector<std::string> get_keys_with_prefix(const std::string & prefix);
		
		/*
		 * This method returns all the keys in the trie.
		 *
		 */
		std::vector<std::string> get_keys();
		
	private:
		// Atributes
		node_ptr<T,R> root;
		unsigned int r;
		unsigned int s;
		// Default value of T to return.
		const T def = T();
		// Auxiliar value to help return found values.
		T aux_ret;
		// Methods
		/*
		 * Given a node it checks if the d-th position in
		 * the key exists in the node's sons. If that is
		 * true call himself but with d+1. When the key
		 * length is equal to d we check if the value
		 * is diferent from the default value for T.
		 */
		node_ptr<T,R> get(node_ptr<T,R> & n,
				  const std::string & key,
				  unsigned int d);
		
		/*
		 * Given a node it checks if the d-th position in
		 * the key exists, if not exists it is created.
		 * When the key length is equal to d we assign
		 * the value to the node's value.
		 */
		node_ptr<T,R> put(node_ptr<T,R> n,
				  const std::string & key,
				  const T & value,
				  unsigned int d,
				  bool & created);
		
		/*
		 * Given a node deleted everything under it.
		 */
		void clean(node_ptr<T,R> n);
		
		/*
		 * Given a node it checks if the d-th position in
		 * the key exists. When the key length is equal to
		 * d we begin to delete all the nodes from that
		 * one up to the first node with at least one son.
		 */		
		bool remove(node_ptr<T,R> & n,
			    const std::string & key,
			    unsigned int d,
			    bool & decrease);

		/*
		 * Given a node it checks if the d-th position in
		 * the key exists. When the key length is equal to
		 * d we check if the value is different from the
		 * default value of T. If all that happens return
		 * true else return false.
		 */		
		bool contains(node_ptr<T,R> & n,
			      const std::string & key,
			      unsigned int d);

		/*
		 * Given a node it checks if the d-th position in
		 * the prefix exists. When the prefix length is
		 * equal to d then it calls gather keys to get
		 * all keys with that prefix.
		 */		
		void get_keys_with_prefix(node_ptr<T,R> & n,
					  std::string prefix,
					  unsigned int d,
					  vec_ptr & v);

		/*
		 * Given a node goes to all its sons to gather
		 * all the keys that are under the given node.
		 * All those keys are stored in the vector.
		 */		
		void gather_keys(node_ptr<T,R> & n,
				 std::string prefix,
				 vec_ptr & v);


		/*
		 * Given a node prints the its value and the
		 * ones for its sons in the 'dot' format.
		 */
		void show_label(node_ptr<T,R> & n, int pos, int & label);
		void show(node_ptr<T,R> & n, int pos, int & label);
	}; // TRIE_CLASS
	
}; // TRIE_NAMESPACE

#endif  // TRIE_TRIE_H_
