CXX=g++
CXXFLAGS=--std=c++11 -lgtest -Wall -Wextra
LIB_FOLDER=lib
TEST_FOLDER=gtest

test: $(TEST_FOLDER)/main.cpp
	$(CXX) $(CXXFLAGS) $< -o $(TEST_FOLDER)/test -I$(LIB_FOLDER)
	./$(TEST_FOLDER)/test

clean:
	rm $(TEST_FOLDER)/test $(wildcard $(LIB_FOLDER)/*~) $(wildcard $(TEST_FOLDER)/*~)
