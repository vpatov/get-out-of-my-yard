#ifndef GETOUT_H
#define GETOUT_H

#include <glfw3.h>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

int get_keycode(std::string key);
void split(const std::string &s, char delim, std::vector<std::string> result);
std::vector<std::string> split(const std::string &s, char delim);

#endif
