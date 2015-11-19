#include <string>

// How many different characters can have our strings. Basicly, Extended ASCII
#define LENGTH 256

//////////////////////
// Useful functions //
//////////////////////

std::string get_random_string(unsigned int len) {
	std::string result = "";
	for (unsigned int i = 0; i < len; ++i){
		result += static_cast<char>(rand()%LENGTH);
	}
	return result;
}
