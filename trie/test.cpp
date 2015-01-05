#include <string>
#include <iostream>
#include "trie.cpp"

int main(int argc, char * argv[] ) {

	Trie::trie<int, 256> t;
	std::string hello = "Hello", world = "World", wololo = "Wololo", he = "He", kthulu = "Kthulu", no = "No", hes = "Hes";
	
	t.put(hello, 1);  
	t.put(world, 2);
	t.put(wololo, 3);
	t.show();
	std::cout << "Current size should be 3; size = " << t.size() << std::endl;
	
	std::cout << "Get Hello = " << t.get(hello) << std::endl;
	std::cout << "Get World = " << t.get(world) << std::endl;
	std::cout << "Get Wololo = " << t.get(wololo) << std::endl;
	std::cout << "Get Kthulu = " << t.get(kthulu) << std::endl;
	t.show();
	t.put(kthulu, 4);
	t.show();
	std::cout << "Get Kthulu = " << t.get(kthulu) << std::endl;
	std::cout << "Get He = " << t.get(he) << std::endl;
	t.put(he, 5);
	std::cout << "Get He = " << t.get(he) << std::endl;
	
	t.show();
	
	std::cout << "Contains He? " << t.contains(he) << std::endl;
	std::cout << "Contains No? " << t.contains(no) << std::endl;
	std::cout << "Contains Hes? " << t.contains(hes) << std::endl;
	
	std::cout << "Keys with prefix He" << std::endl;
	for (auto key : t.get_keys_with_prefix("He")) {
		std::cout << key << std::endl;
	}
	
	std::cout << "Keys with prefix Hi" << std::endl;
	for (auto key : t.get_keys_with_prefix("Hi")) {
		std::cout << key << std::endl;
	}
	
	std::cout << "Removing Hello" << std::endl;
	t.remove(hello);
	t.show();
	std::cout << "Removing He" << std::endl;
	t.remove(he);
	t.show();
	std::cout << "Removing no" << std::endl;
	t.remove(no);
	t.show();
	return 0;
}
