#include "radix_tree.cpp"
#include "gtest/gtest.h"

class RadixTest : public testing::Test {
protected:
  virtual void TearDown() {
    t.clear();
  }

  RadixTree::radix_tree<int, 256> t;
}; // class

TEST_F(RadixTest, MethodPut) {
  const std::string key = "hi";
  const std::string no_key = "no";
  const int value = 42;
  EXPECT_EQ(0, t.size()) << "This should be 0 due it is an emplty trie";
  t.insert(key, value);
  EXPECT_EQ(1, t.size()) << "This should be 1. It only has a value";
  EXPECT_EQ(42, t.find(key)) << "This should be 42. It is the value we insert";
  EXPECT_EQ(0, t.find(no_key)) << "This should be the default value for the content. We never inserted any value with this key";
}

TEST_F(RadixTest, MethodClean) {
  const std::string key = "hi";
  const int value = 42;
  EXPECT_EQ(0, t.size()) << "This should be 0 due it is an emplty trie";
  t.insert(key, value);
  EXPECT_EQ(1, t.size()) << "This should be 1. It only has a value";
  t.clear();
  EXPECT_EQ(0, t.size()) << "This should be 0 due it is an emplty trie";
  EXPECT_EQ(0, t.find(key)) << "This should be 0 due we just cleared the trie";
}

TEST_F(RadixTest, MethodGetRemove) {
  std::string hello = "Hello", he = "He", hes = "Hes";
  t.insert(hello, 1);
  t.insert(he, 2);
  t.insert(hes, 3);
  EXPECT_EQ(3, t.size()) << "This should be 3";
  EXPECT_EQ(1, t.find(hello)) << "This should be 1";
  EXPECT_EQ(2, t.find(he)) << "This should be 2";
  EXPECT_EQ(3, t.find(hes)) << "This should be 3";
  t.erase(he);
  EXPECT_EQ(2, t.size()) << "This should be 2";
  EXPECT_EQ(1, t.find(hello)) << "This should be 1";
  EXPECT_EQ(0, t.find(he)) << "This should be 0";
  EXPECT_EQ(3, t.find(hes)) << "This should be 3";
  t.erase(hes);
  EXPECT_EQ(1, t.size()) << "This should be 1";
  EXPECT_EQ(1, t.find(hello)) << "This should be 1";
  EXPECT_EQ(0, t.find(he)) << "This should be 0";
  EXPECT_EQ(0, t.find(hes)) << "This should be 0";
  t.insert(hes, 3);
  EXPECT_EQ(2, t.size()) << "This should be 2";
  EXPECT_EQ(1, t.find(hello)) << "This should be 1";
  EXPECT_EQ(0, t.find(he)) << "This should be 0";
  EXPECT_EQ(3, t.find(hes)) << "This should be 3";
  t.insert(he, 2);
  EXPECT_EQ(3, t.size()) << "This should be 3";
  EXPECT_EQ(1, t.find(hello)) << "This should be 1";
  EXPECT_EQ(2, t.find(he)) << "This should be 2";
  EXPECT_EQ(3, t.find(hes)) << "This should be 3";
  t.erase(hello);
  EXPECT_EQ(2, t.size()) << "This should be 2";
  EXPECT_EQ(0, t.find(hello)) << "This should be 0";
  EXPECT_EQ(2, t.find(he)) << "This should be 2";
  EXPECT_EQ(3, t.find(hes)) << "This should be 3";
  t.insert(hello, 1);
  EXPECT_EQ(3, t.size()) << "This should be 3";
  EXPECT_EQ(1, t.find(hello)) << "This should be 1";
  EXPECT_EQ(2, t.find(he)) << "This should be 2";
  EXPECT_EQ(3, t.find(hes)) << "This should be 3";
  // Check things are not in the trie
  EXPECT_EQ(0, t.find("HelloS")) << "This should be 0";
  EXPECT_EQ(0, t.find("H")) << "This should be 0";
  EXPECT_EQ(0, t.find("Hel")) << "This should be 0";
}

TEST_F(RadixTest, MethodContains) {
  std::string hello = "Hello", he = "He", hes = "Hes";
  t.insert(hello, 1);
  t.insert(he, 2);
  t.insert(hes, 3);
  EXPECT_EQ(3, t.size()) << "This should be 3";
  EXPECT_EQ(1, t.find(hello)) << "This should be 1";
  EXPECT_EQ(2, t.find(he)) << "This should be 2";
  EXPECT_EQ(3, t.find(hes)) << "This should be 3";
  EXPECT_EQ(true, t.contains(hello)) << "This should contain 'Hello'";
  EXPECT_EQ(true, t.contains(he)) << "This should contain 'He'";
  EXPECT_EQ(true, t.contains(hes)) << "This should contain 'Hes'";
  EXPECT_EQ(false, t.contains("he")) << "This should NOT contain 'he'";
  EXPECT_EQ(false, t.contains("Hel")) << "This should NOT contain 'Hel'";
  EXPECT_EQ(false, t.contains("HelloS")) << "This should NOT contain 'HelloS'";
}

TEST_F(RadixTest, MethodGetKeys) {
  std::string hello = "Hello", he = "He", hes = "Hes";
  t.insert(hello, 1);
  t.insert(he, 2);
  t.insert(hes, 3);
  EXPECT_EQ(3, t.size()) << "This should be 3";
  EXPECT_EQ(1, t.find(hello)) << "This should be 1";
  EXPECT_EQ(2, t.find(he)) << "This should be 2";
  EXPECT_EQ(3, t.find(hes)) << "This should be 3";
  std::vector<std::string> vec;
  vec = t.keys();
  EXPECT_EQ(3, vec.size()) << "This should be 3";
  EXPECT_EQ(he, vec[0]) << "This should be 'He'";
  EXPECT_EQ(hello, vec[1]) << "This should be 'Hello'";
  EXPECT_EQ(hes, vec[2]) << "This should be 'Hes'";
  t.erase(he);
  vec = t.keys();
  EXPECT_EQ(2, vec.size()) << "This should be 2";
  EXPECT_EQ(hello, vec[0]) << "This should be 'Hello'";
  EXPECT_EQ(hes, vec[1]) << "This should be 'Hes'";
  t.insert(he, 2);
  vec = t.keys();
  EXPECT_EQ(3, vec.size()) << "This should be 3";
  EXPECT_EQ(he, vec[0]) << "This should be 'He'";
  EXPECT_EQ(hello, vec[1]) << "This should be 'Hello'";
  EXPECT_EQ(hes, vec[2]) << "This should be 'Hes'";
  t.erase(hello);
  vec = t.keys();
  EXPECT_EQ(2, vec.size()) << "This should be 2";
  EXPECT_EQ(he, vec[0]) << "This should be 'He'";
  EXPECT_EQ(hes, vec[1]) << "This should be 'Hes'";  
}

TEST_F(RadixTest, MethodGetKeyWithPrefix) {
  std::string hello = "Hello", world = "World", wololo = "Wololo", he = "He", kthulu = "Kthulu", no = "No", hes = "Hes";
  t.insert(hello, 1);  
  t.insert(world, 2);
  t.insert(wololo, 3);
  t.insert(he, 4);
  t.insert(kthulu, 5);
  t.insert(no, 6);
  t.insert(hes, 7);
  EXPECT_EQ(7, t.size()) << "This should be 7";

  std::vector<std::string> vec;
  // With prefix Hel
  vec = t.keys("Hel");
  EXPECT_EQ(1, vec.size()) << "This should be 1";
  EXPECT_EQ(hello, vec[0]) << "This should be 'Hello'";
  // With prefix N
  vec = t.keys("N");
  EXPECT_EQ(1, vec.size()) << "This should be 1";
  EXPECT_EQ(no, vec[0]) << "This should be 'No'";
  // With prefix No
  vec = t.keys("No");
  EXPECT_EQ(1, vec.size()) << "This should be 1";
  EXPECT_EQ(no, vec[0]) << "This should be 'No'";
  // With prefix Nos
  vec = t.keys("Nos");
  EXPECT_EQ(0, vec.size()) << "This should be 0";
  // With prefix W
  vec = t.keys("W");
  EXPECT_EQ(2, vec.size()) << "This should be 2";
  EXPECT_EQ(wololo, vec[0]) << "This should be 'Wololo'";
  EXPECT_EQ(world, vec[1]) << "This should be 'World'";
  // With prefix Wo
  vec = t.keys("Wo");
  EXPECT_EQ(2, vec.size()) << "This should be 2";
  EXPECT_EQ(wololo, vec[0]) << "This should be 'Wololo'";
  EXPECT_EQ(world, vec[1]) << "This should be 'World'";
  // With prefix Wou
  vec = t.keys("Wou");
  EXPECT_EQ(0, vec.size()) << "This should be 0";
}

TEST_F(RadixTest, RemoveEmptyTest) {
	std::string hello = "Hello", he = "He", hes = "Hes";

	t.insert(he, 1);
	t.insert(hes, 2);
	t.insert(hello, 3);

	t.erase(hes);
	t.erase(he);
	t.erase(hello);

	EXPECT_EQ(0, t.size()) << "Size should be 0";

	t.insert(he, 1);
	t.insert(hes, 2);
	t.insert(hello, 3);
	t.insert(hes, 4);

	t.erase(hes);
	t.erase(he);
	t.erase(hello);

	EXPECT_EQ(0, t.size()) << "Size should be 0";
}

TEST_F(RadixTest, EmptyStringParameterTest) {
	std::string hello = "Hello", he = "He", hes = "Hes";

	t.insert(he, 1);
	t.insert(hes, 2);
	t.insert(hello, 3);

	EXPECT_EQ(0, t.find("")) << "Get from an empty string should be 0 ALWAYS";
	t.insert("", 1);
	t.erase("");
	EXPECT_EQ(false, t.contains("")) << "Contains from an empty string should be 0 ALWAYS";
	EXPECT_EQ(3, t.size()) << "Even after all those attempts the size should remain 3";
	std::vector<std::string> vec;
	vec = t.keys("");
	EXPECT_EQ(3, vec.size()) << "This should be easy";
}

TEST_F(RadixTest, LongTest) {
  std::string hello = "Hello", world = "World", wololo = "Wololo", he = "He", kthulu = "Kthulu", no = "No", hes = "Hes";

  t.insert(hello, 1);  
  t.insert(world, 2);
  t.insert(wololo, 3);
  EXPECT_EQ(3, t.size()) << "This should be 3";
  EXPECT_EQ(1, t.find(hello)) << "This should be 1";
  EXPECT_EQ(2, t.find(world)) << "This should be 2";
  EXPECT_EQ(3, t.find(wololo)) << "This should be 3";

  // Checking before and after adding Kthulu. The prefix is new in the trie.
  EXPECT_EQ(0, t.find(kthulu)) << "This should be 0";
  t.insert(kthulu, 4);
  EXPECT_EQ(4, t.size()) << "This should be 4";
  EXPECT_EQ(4, t.find(kthulu)) << "This should be 4";
  
  // Checking before and after adding He. The prefix was alreay in the trie.
  EXPECT_EQ(0, t.find(he)) << "This should be 0";
  t.insert(he, 5);
  EXPECT_EQ(5, t.size()) << "This should be 5";
  EXPECT_EQ(5, t.find(he)) << "This should be 5";

  // Checking content that is not in the trie
  EXPECT_EQ(0, t.find(no)) << "This should be 0";
  EXPECT_EQ(0, t.find(hes)) << "This should be 0";

  // Getting some keys with prefix "He". Should be 2.
  std::vector<std::string> keys;
  keys = t.keys("He");
  EXPECT_EQ(2, keys.size()) << "This should be 2";
  EXPECT_EQ(he, keys[0]);
  EXPECT_EQ(hello, keys[1]);

  // Getting some keys with prefix "Hi". Should be none
  keys = t.keys("His");
  EXPECT_EQ(0, keys.size()) << "This should be 0";

  // Gettin some keys with prefix "H". Should be 2.
  keys = t.keys("H");
  EXPECT_EQ(2, keys.size()) << "This should be 2";
  EXPECT_EQ(he, keys[0]);
  EXPECT_EQ(hello, keys[1]);

  // Updating value of "He"
  EXPECT_EQ(5, t.find(he)) << "This should be 5";
  t.insert(he, 7);
  EXPECT_EQ(7, t.find(he)) << "This should be 7";
  EXPECT_EQ(5, t.size()) << "This should be 5";

  // Removing hello
  t.erase(hello);
  EXPECT_EQ(4, t.size()) << "This should be 4";
  keys = t.keys("He");
  EXPECT_EQ(1, keys.size()) << "This should be 1";
  EXPECT_EQ(he, keys[0]);
  EXPECT_EQ(0, t.find(hello)) << "This should be 0";
  // Removing hello again. Shoul not make any difference
  t.erase(hello);
  EXPECT_EQ(4, t.size()) << "This should be 4";
  keys = t.keys("He");
  EXPECT_EQ(1, keys.size()) << "This should be 1";
  EXPECT_EQ(he, keys[0]);
  EXPECT_EQ(0, t.find(hello)) << "This should be 0";
  // Re-adding hello again
  t.insert(hello, 1);
  EXPECT_EQ(5, t.size()) << "This should be 5";
  keys = t.keys("He");
  EXPECT_EQ(2, keys.size()) << "This should be 2";
  EXPECT_EQ(he, keys[0]);
  EXPECT_EQ(hello, keys[1]);
  EXPECT_EQ(1, t.find(hello)) << "This should be 1";

  // Removing he
  t.erase(he);
  EXPECT_EQ(4, t.size()) << "This should be 4";
  keys = t.keys("He");
  EXPECT_EQ(1, keys.size()) << "This should be 1";
  EXPECT_EQ(hello, keys[0]);
  EXPECT_EQ(0, t.find(he)) << "This should be 0";
  // Removing hello again. Shoul not make any difference
  t.erase(he);
  EXPECT_EQ(4, t.size()) << "This should be 4";
  keys = t.keys("He");
  EXPECT_EQ(1, keys.size()) << "This should be 1";
  EXPECT_EQ(hello, keys[0]);
  EXPECT_EQ(0, t.find(he)) << "This should be 0";
  // Re-adding hello again
  t.insert(he, 7);
  EXPECT_EQ(5, t.size()) << "This should be 5";
  keys = t.keys("He");
  EXPECT_EQ(2, keys.size()) << "This should be 2";
  EXPECT_EQ(he, keys[0]);
  EXPECT_EQ(hello, keys[1]);
  EXPECT_EQ(7, t.find(he)) << "This should be 7";

  // Finally removing hello
  t.erase(hello);
  EXPECT_EQ(4, t.size()) << "This should be 4";
  t.erase(he);
  EXPECT_EQ(3, t.size()) << "This should be 3";
  t.erase(hes);
  EXPECT_EQ(3, t.size()) << "This should be 3";
  t.erase(no);
  EXPECT_EQ(3, t.size()) << "This should be 3";
}

int main(int argc, char * argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
