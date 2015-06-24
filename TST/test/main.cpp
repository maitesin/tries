#include "TST.cpp"
#include "gtest/gtest.h"

class TstTest : public testing::Test {
protected:
  virtual void TearDown() {
    t.clean();
  }    
  
  TST::tst<int> t;
}; // class

TEST_F(TstTest, MethodPut) {
  const std::string key = "hi";
  const std::string no_key = "no";
  const int value = 42;
  EXPECT_EQ(0, t.size()) << "This should be 0 due it is an emplty trie";
  t.put(key, value);
  EXPECT_EQ(1, t.size()) << "This should be 1. It only has a value";
  EXPECT_EQ(42, t.get(key)) << "This should be 42. It is the value we put";
  EXPECT_EQ(0, t.get(no_key)) << "This should be the default value for the content. We never inserted any value with this key";
}

TEST_F(TstTest, MethodClean) {
  const std::string key = "hi";
  const int value = 42;
  EXPECT_EQ(0, t.size()) << "This should be 0 due it is an emplty trie";
  t.put(key, value);
  EXPECT_EQ(1, t.size()) << "This should be 1. It only has a value";
  t.clean();
  EXPECT_EQ(0, t.size()) << "This should be 0 due it is an emplty trie";
  EXPECT_EQ(0, t.get(key)) << "This should be 0 due we just cleaned the trie";
}

TEST_F(TstTest, MethodGetRemove) {
  std::string hello = "Hello", he = "He", hes = "Hes";
  t.put(hello, 1);
  t.put(he, 2);
  t.put(hes, 3);
  EXPECT_EQ(3, t.size()) << "This should be 3";
  EXPECT_EQ(1, t.get(hello)) << "This should be 1";
  EXPECT_EQ(2, t.get(he)) << "This should be 2";
  EXPECT_EQ(3, t.get(hes)) << "This should be 3";
  t.remove(he);
  EXPECT_EQ(2, t.size()) << "This should be 2";
  EXPECT_EQ(1, t.get(hello)) << "This should be 1";
  EXPECT_EQ(0, t.get(he)) << "This should be 0";
  EXPECT_EQ(3, t.get(hes)) << "This should be 3";
  t.remove(hes);
  EXPECT_EQ(1, t.size()) << "This should be 1";
  EXPECT_EQ(1, t.get(hello)) << "This should be 1";
  EXPECT_EQ(0, t.get(he)) << "This should be 0";
  EXPECT_EQ(0, t.get(hes)) << "This should be 0";
  t.put(hes, 3);
  EXPECT_EQ(2, t.size()) << "This should be 2";
  EXPECT_EQ(1, t.get(hello)) << "This should be 1";
  EXPECT_EQ(0, t.get(he)) << "This should be 0";
  EXPECT_EQ(3, t.get(hes)) << "This should be 3";
  t.put(he, 2);
  EXPECT_EQ(3, t.size()) << "This should be 3";
  EXPECT_EQ(1, t.get(hello)) << "This should be 1";
  EXPECT_EQ(2, t.get(he)) << "This should be 2";
  EXPECT_EQ(3, t.get(hes)) << "This should be 3";
  t.remove(hello);
  EXPECT_EQ(2, t.size()) << "This should be 2";
  EXPECT_EQ(0, t.get(hello)) << "This should be 0";
  EXPECT_EQ(2, t.get(he)) << "This should be 2";
  EXPECT_EQ(3, t.get(hes)) << "This should be 3";
  t.put(hello, 1);
  EXPECT_EQ(3, t.size()) << "This should be 3";
  EXPECT_EQ(1, t.get(hello)) << "This should be 1";
  EXPECT_EQ(2, t.get(he)) << "This should be 2";
  EXPECT_EQ(3, t.get(hes)) << "This should be 3";
  // Check things are not in the trie
  EXPECT_EQ(0, t.get("HelloS")) << "This should be 0";
  EXPECT_EQ(0, t.get("H")) << "This should be 0";
  EXPECT_EQ(0, t.get("Hel")) << "This should be 0";
}

TEST_F(TstTest, MethodContains) {
  std::string hello = "Hello", he = "He", hes = "Hes";
  t.put(hello, 1);
  t.put(he, 2);
  t.put(hes, 3);
  EXPECT_EQ(3, t.size()) << "This should be 3";
  EXPECT_EQ(1, t.get(hello)) << "This should be 1";
  EXPECT_EQ(2, t.get(he)) << "This should be 2";
  EXPECT_EQ(3, t.get(hes)) << "This should be 3";
  EXPECT_EQ(true, t.contains(hello)) << "This should contain 'Hello'";
  EXPECT_EQ(true, t.contains(he)) << "This should contain 'He'";
  EXPECT_EQ(true, t.contains(hes)) << "This should contain 'Hes'";
  EXPECT_EQ(false, t.contains("he")) << "This should NOT contain 'he'";
  EXPECT_EQ(false, t.contains("Hel")) << "This should NOT contain 'Hel'";
  EXPECT_EQ(false, t.contains("HelloS")) << "This should NOT contain 'HelloS'";
}

TEST_F(TstTest, MethodGetKeys) {
  std::string hello = "Hello", he = "He", hes = "Hes";
  t.put(hello, 1);
  t.put(he, 2);
  t.put(hes, 3);
  EXPECT_EQ(3, t.size()) << "This should be 3";
  EXPECT_EQ(1, t.get(hello)) << "This should be 1";
  EXPECT_EQ(2, t.get(he)) << "This should be 2";
  EXPECT_EQ(3, t.get(hes)) << "This should be 3";
  std::vector<std::string> vec;
  vec = t.get_keys();
  EXPECT_EQ(3, vec.size()) << "This should be 3";
  EXPECT_EQ(he, vec[0]) << "This should be 'He'";
  EXPECT_EQ(hello, vec[1]) << "This should be 'Hello'";
  EXPECT_EQ(hes, vec[2]) << "This should be 'Hes'";
  t.remove(he);
  vec = t.get_keys();
  EXPECT_EQ(2, vec.size()) << "This should be 2";
  EXPECT_EQ(hello, vec[0]) << "This should be 'Hello'";
  EXPECT_EQ(hes, vec[1]) << "This should be 'Hes'";
  t.put(he, 2);
  vec = t.get_keys();
  EXPECT_EQ(3, vec.size()) << "This should be 3";
  EXPECT_EQ(he, vec[0]) << "This should be 'He'";
  EXPECT_EQ(hello, vec[1]) << "This should be 'Hello'";
  EXPECT_EQ(hes, vec[2]) << "This should be 'Hes'";
  t.remove(hello);
  vec = t.get_keys();
  EXPECT_EQ(2, vec.size()) << "This should be 2";
  EXPECT_EQ(he, vec[0]) << "This should be 'He'";
  EXPECT_EQ(hes, vec[1]) << "This should be 'Hes'";  
}

TEST_F(TstTest, MethodGetKeyWithPrefix) {
  std::string hello = "Hello", world = "World", wololo = "Wololo", he = "He", kthulu = "Kthulu", no = "No", hes = "Hes";
  t.put(hello, 1);  
  t.put(world, 2);
  t.put(wololo, 3);
  t.put(he, 4);
  t.put(kthulu, 5);
  t.put(no, 6);
  t.put(hes, 7);
  EXPECT_EQ(7, t.size()) << "This should be 7";

  std::vector<std::string> vec;
  // With prefix Hel
  vec = t.get_keys_with_prefix("Hel");
  EXPECT_EQ(1, vec.size()) << "This should be 1";
  EXPECT_EQ(hello, vec[0]) << "This should be 'Hello'";
  // With prefix N
  vec = t.get_keys_with_prefix("N");
  EXPECT_EQ(1, vec.size()) << "This should be 1";
  EXPECT_EQ(no, vec[0]) << "This should be 'No'";
  // With prefix No
  vec = t.get_keys_with_prefix("No");
  EXPECT_EQ(1, vec.size()) << "This should be 1";
  EXPECT_EQ(no, vec[0]) << "This should be 'No'";
  // With prefix Nos
  vec = t.get_keys_with_prefix("Nos");
  EXPECT_EQ(0, vec.size()) << "This should be 0";
  // With prefix W
  vec = t.get_keys_with_prefix("W");
  EXPECT_EQ(2, vec.size()) << "This should be 2";
  EXPECT_EQ(wololo, vec[0]) << "This should be 'Wololo'";
  EXPECT_EQ(world, vec[1]) << "This should be 'World'";
  // With prefix Wo
  vec = t.get_keys_with_prefix("Wo");
  EXPECT_EQ(2, vec.size()) << "This should be 2";
  EXPECT_EQ(wololo, vec[0]) << "This should be 'Wololo'";
  EXPECT_EQ(world, vec[1]) << "This should be 'World'";
  // With prefix Wou
  vec = t.get_keys_with_prefix("Wou");
  EXPECT_EQ(0, vec.size()) << "This should be 0";
}

TEST_F(TstTest, EmptyKeyTest) {
	std::string empty = "";
	t.put(empty, 1);
	EXPECT_EQ(0, t.size());
	EXPECT_EQ(0, t.get(empty));
}

TEST_F(TstTest, RemoveEmptyTest) {
	std::string hello = "Hello", he = "He", hes = "Hes";

	t.put(he, 1);
	t.put(hes, 2);
	t.put(hello, 3);

	t.remove(hes);
	t.remove(he);
	t.remove(hello);

	EXPECT_EQ(0, t.size()) << "Size should be 0";

	t.put(he, 1);
	t.put(hes, 2);
	t.put(hello, 3);
	t.put(hes, 4);

	t.remove(hes);
	t.remove(he);
	t.remove(hello);

	EXPECT_EQ(0, t.size()) << "Size should be 0";
}

TEST_F(TstTest, LongTest) {
  std::string hello = "Hello", world = "World", wololo = "Wololo", he = "He", kthulu = "Kthulu", no = "No", hes = "Hes";

  t.put(hello, 1);  
  t.put(world, 2);
  t.put(wololo, 3);
  EXPECT_EQ(3, t.size()) << "This should be 3";
  EXPECT_EQ(1, t.get(hello)) << "This should be 1";
  EXPECT_EQ(2, t.get(world)) << "This should be 2";
  EXPECT_EQ(3, t.get(wololo)) << "This should be 3";

  // Checking before and after adding Kthulu. The prefix is new in the trie.
  EXPECT_EQ(0, t.get(kthulu)) << "This should be 0";
  t.put(kthulu, 4);
  EXPECT_EQ(4, t.size()) << "This should be 4";
  EXPECT_EQ(4, t.get(kthulu)) << "This should be 4";
  
  // Checking before and after adding He. The prefix was alreay in the trie.
  EXPECT_EQ(0, t.get(he)) << "This should be 0";
  t.put(he, 5);
  EXPECT_EQ(5, t.size()) << "This should be 5";
  EXPECT_EQ(5, t.get(he)) << "This should be 5";

  // Checking content that is not in the trie
  EXPECT_EQ(0, t.get(no)) << "This should be 0";
  EXPECT_EQ(0, t.get(hes)) << "This should be 0";

  // Getting some keys with prefix "He". Should be 2.
  std::vector<std::string> keys;
  keys = t.get_keys_with_prefix("He");
  EXPECT_EQ(2, keys.size()) << "This should be 2";
  EXPECT_EQ(he, keys[0]);
  EXPECT_EQ(hello, keys[1]);

  // Getting some keys with prefix "Hi". Should be none
  keys = t.get_keys_with_prefix("His");
  EXPECT_EQ(0, keys.size()) << "This should be 0";

  // Gettin some keys with prefix "H". Should be 2.
  keys = t.get_keys_with_prefix("H");
  EXPECT_EQ(2, keys.size()) << "This should be 2";
  EXPECT_EQ(he, keys[0]);
  EXPECT_EQ(hello, keys[1]);

  // Updating value of "He"
  EXPECT_EQ(5, t.get(he)) << "This should be 5";
  t.put(he, 7);
  EXPECT_EQ(7, t.get(he)) << "This should be 7";
  EXPECT_EQ(5, t.size()) << "This should be 5";

  // Removing hello
  t.remove(hello);
  EXPECT_EQ(4, t.size()) << "This should be 4";
  keys = t.get_keys_with_prefix("He");
  EXPECT_EQ(1, keys.size()) << "This should be 1";
  EXPECT_EQ(he, keys[0]);
  EXPECT_EQ(0, t.get(hello)) << "This should be 0";
  // Removing hello again. Shoul not make any difference
  t.remove(hello);
  EXPECT_EQ(4, t.size()) << "This should be 4";
  keys = t.get_keys_with_prefix("He");
  EXPECT_EQ(1, keys.size()) << "This should be 1";
  EXPECT_EQ(he, keys[0]);
  EXPECT_EQ(0, t.get(hello)) << "This should be 0";
  // Re-adding hello again
  t.put(hello, 1);
  EXPECT_EQ(5, t.size()) << "This should be 5";
  keys = t.get_keys_with_prefix("He");
  EXPECT_EQ(2, keys.size()) << "This should be 2";
  EXPECT_EQ(he, keys[0]);
  EXPECT_EQ(hello, keys[1]);
  EXPECT_EQ(1, t.get(hello)) << "This should be 1";

  // Removing he
  t.remove(he);
  EXPECT_EQ(4, t.size()) << "This should be 4";
  keys = t.get_keys_with_prefix("He");
  EXPECT_EQ(1, keys.size()) << "This should be 1";
  EXPECT_EQ(hello, keys[0]);
  EXPECT_EQ(0, t.get(he)) << "This should be 0";
  // Removing hello again. Shoul not make any difference
  t.remove(he);
  EXPECT_EQ(4, t.size()) << "This should be 4";
  keys = t.get_keys_with_prefix("He");
  EXPECT_EQ(1, keys.size()) << "This should be 1";
  EXPECT_EQ(hello, keys[0]);
  EXPECT_EQ(0, t.get(he)) << "This should be 0";
  // Re-adding hello again
  t.put(he, 7);
  EXPECT_EQ(5, t.size()) << "This should be 5";
  keys = t.get_keys_with_prefix("He");
  EXPECT_EQ(2, keys.size()) << "This should be 2";
  EXPECT_EQ(he, keys[0]);
  EXPECT_EQ(hello, keys[1]);
  EXPECT_EQ(7, t.get(he)) << "This should be 7";

  // Finally removing hello
  t.remove(hello);
  EXPECT_EQ(4, t.size()) << "This should be 4";
  t.remove(he);
  EXPECT_EQ(3, t.size()) << "This should be 3";
  t.remove(hes);
  EXPECT_EQ(3, t.size()) << "This should be 3";
  t.remove(no);
  EXPECT_EQ(3, t.size()) << "This should be 3";
}

int main(int argc, char * argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
