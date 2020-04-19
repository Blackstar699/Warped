#ifndef WARPED_FONCTIONS_H
#define WARPED_FONCTIONS_H

#include "includes.h"
#include "CSVReader.hpp"

sf::Texture loadTexture(const std::string& filename);
std::map<std::pair<int, int>, int> getMap(const string& fileName);

#endif //WARPED_FONCTIONS_H
