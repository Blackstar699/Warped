#ifndef WARPED_MENUS_H
#define WARPED_MENUS_H

#include "includes.h"
#include "fonctions.h"

sf::Sprite homeEnterText(sf::Sprite sprite, int alpha);
void home(sf::RenderWindow& window, int& home_alpha_value, sf::Clock& clock);
void menu(sf::RenderWindow& window, int clic_position, int difficulty_value);
void shapesDemo(sf::RenderWindow& window, sf::Clock& clock, int& display_key);

#endif //WARPED_MENUS_H
