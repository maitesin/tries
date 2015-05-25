#include "trie.cpp"
#include "gtest/gtest.h"

class TrieTest : public testing::Test {
protected:
  virtual void TearDown() {
    t.clean();
  }    
  
  Trie::trie<int, 256> t;
}; // class

TEST_F(TrieTest, MethodPut) {
  const std::string key = "hi";
  const std::string no_key = "no";
  const int value = 42;
  EXPECT_EQ(0, t.size()) << "This should be 0 due it is an emplty trie";
  t.put(key, value);
  EXPECT_EQ(1, t.size()) << "This should be 1. It only has a value";
  EXPECT_EQ(42, t.get(key)) << "This should be 42. It is the value we put";
  EXPECT_EQ(0, t.get(no_key)) << "This should be the default value for the content. We never inserted any value with this key";
}

TEST_F(TrieTest, MethodClean) {
  const std::string key = "hi";
  const int value = 42;
  EXPECT_EQ(0, t.size()) << "This should be 0 due it is an emplty trie";
  t.put(key, value);
  EXPECT_EQ(1, t.size()) << "This should be 1. It only has a value";
  t.clean();
  EXPECT_EQ(0, t.size()) << "This should be 0 due it is an emplty trie";
  EXPECT_EQ(0, t.get(key)) << "This should be 0 due we just cleaned the trie";
}

int main(int argc, char * argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
