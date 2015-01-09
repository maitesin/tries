// Copyright 2015 Maitesin
#ifndef TRIE_TST_H_
#define TRIE_TST_H_

#include <string>
#include <vector>
#include <array>
#include <memory>

namespace TST {

	/**
	 * Node
	 */
	template <class T>
		struct node {
			T value;
			std::unique_ptr<node<T>> left, right, middle;
			char c;
			
			explicit node(char ch, T v = T()) : c(ch), value(v), left(nullptr), right(nullptr), middle(nullptr) {}
		};

	/**
	 * Utils
	 */
	template <class T>
		using node_ptr = std::unique_ptr<node<T>>;
	using vec_ptr = std::unique_ptr<std::vector<std::string>>;
	
	/**
	 * Ternary Search Tree (TST)
	 */
	template <class T>
		class tst {
	public:
		// Constructor
		explicit tst() : root(nullptr), s(0){}
		
		// Destructor
		~tst() {
			clean(std::move(root));
		}
		
		// Methods
		const T & get(const std::string & key);
		void put(const std::string & key,
			 const T & value);
		unsigned int size() {return s;}
		void show();
		void remove(const std::string & key);
		bool contains(const std::string & key);
		std::vector<std::string> get_keys_with_prefix(const std::string & prefix);
		std::vector<std::string> get_keys();
		
	private:
		// Atributes
		node_ptr<T> root;
		unsigned int s;
		const T def = T();
		T aux_ret;

		//Methods
		node_ptr<T> get(node_ptr<T> & n,
				const std::string & key,
				unsigned int d);
		node_ptr<T> put(node_ptr<T> n,
				const std::string & key,
				const T & value,
				unsigned int d);
		void clean(node_ptr<T> n);
		bool remove(node_ptr<T> & n,
			    const std::string & key,
			    unsigned int d);
		bool contains(node_ptr<T> & n,
			      const std::string & key,
			      unsigned int d);
		void get_keys_with_prefix(node_ptr<T> & n,
					  std::string prefix,
					  unsigned int d,
					  vec_ptr & v);
		void gather_keys(node_ptr<T> & n,
				 std::string prefix,
				 vec_ptr & v);
	}; // TST_CLASS

}; // TST_NAMESPACE

#endif // TRIE_TST_H_
