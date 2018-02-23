#ifndef GETOUT_H
#define GETOUT_H

#include <glfw3.h>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include <glfw3.h>
#include <ft2build.h>


//#include <SFML/Audio.hpp>

#include FT_FREETYPE_H
#include FT_GLYPH_H
#include FT_OUTLINE_H
#include FT_TRIGONOMETRY_H


int get_keycode(std::string key);
void split(const std::string &s, char delim, std::vector<std::string> result);
std::vector<std::string> split(const std::string &s, char delim);
void get_keys(GLFWwindow *window, std::vector<int> *keys);

#endif
