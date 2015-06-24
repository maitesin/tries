#include "TST.cpp"
#include <iostream>

int main() {

	TST::tst<int> t;
	
	std::string hello = "Hello", he = "He", hes = "Hes";
	  
	t.put(hello, 1);
	t.put(he, 2);
	t.put(hes, 3);
	std::cout << "Starting the party" << std::endl;
	std::cout << t.size() << " == 3" << std::endl;
	std::cout << t.get(hello) << " == 1" << std::endl;
	std::cout << t.get(he) << " == 2" << std::endl;
	std::cout << t.get(hes) << " == 3" << std::endl;
	t.remove(he);
	std::cout << "Removed he" << std::endl;
	std::cout << t.size() << " == 2" << std::endl;
	std::cout << t.get(hello) << " == 1" << std::endl;
	std::cout << t.get(he) << " == 0" << std::endl;
	std::cout << t.get(hes) << " == 3" << std::endl;
	t.remove(hes);
	std::cout << "Removed hes" << std::endl;
	std::cout << t.size() << " == 1" << std::endl;
	std::cout << t.get(hello) << " == 1" << std::endl;
	std::cout << t.get(he) << " == 0" << std::endl;
	std::cout << t.get(hes) << " == 0" << std::endl;
	t.put(hes, 3);
	std::cout << "Put hes" << std::endl;
	std::cout << t.size() << " == 2" << std::endl;
	std::cout << t.get(hello) << " == 1" << std::endl;
	std::cout << t.get(he) << " == 0" << std::endl;
	std::cout << t.get(hes) << " == 3" << std::endl;
	t.put(he, 2);
	std::cout << "Put he" << std::endl;
	std::cout << t.size() << " == 3" << std::endl;
	std::cout << t.get(hello) << " == 1" << std::endl;
	std::cout << t.get(he) << " == 2" << std::endl;
	std::cout << t.get(hes) << " == 3" << std::endl;
	t.remove(hello);
	std::cout << "Removed hello" << std::endl;
	std::cout << t.size() << " == 2" << std::endl;
	std::cout << t.get(hello) << " == 0" << std::endl;
	std::cout << t.get(he) << " == 2" << std::endl;
	std::cout << t.get(hes) << " == 3" << std::endl;
	t.put(hello, 1);
	std::cout << "Put hello" << std::endl;
	std::cout << t.size() << " == 3" << std::endl;
	std::cout << t.get(hello) << " == 1" << std::endl;
	std::cout << t.get(he) << " == 2" << std::endl;
	std::cout << t.get(hes) << " == 3" << std::endl;
	std::cout << "Trying to remove stuff that is not in the tst" << std::endl;
	// Check things are not in the trie
	std::cout << t.get("HelloS") << " == 0" << std::endl;
	std::cout << t.get("H") << " == 0" << std::endl;
	std::cout << t.get("Hel") << " == 0" << std::endl;

	return 0;
}
