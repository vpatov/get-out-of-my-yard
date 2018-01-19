#include "getout.h"
#include <glfw3.h>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>



//Thank you, "https://stackoverflow.com/questions/236129/the-most-elegant-way-to-iterate-the-words-of-a-string"

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}