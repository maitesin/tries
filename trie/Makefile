CXX=g++
CXXFLAGS=--std=c++11 -lgtest -Wall -Wextra
LIB_FOLDER=lib
TEST_FOLDER=test

unit_test: $(TEST_FOLDER)/main.cpp
	$(CXX) $(CXXFLAGS) $< -o $(TEST_FOLDER)/test -I$(LIB_FOLDER)

clean:
	rm $(TEST_FOLDER)/test $(wildcard $(LIB_FOLDER)/*~) $(wildcard $(TEST_FOLDER)/*~)
