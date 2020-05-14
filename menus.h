#ifndef WARPED_MENUS_H
#define WARPED_MENUS_H

#include "includes.h"
#include "fonctions.h"

sf::Sprite homeEnterText(sf::Sprite sprite, int alpha);
void home(sf::RenderWindow& window, int& home_alpha_value, sf::Clock& clock, sf::Texture& background, sf::Texture& enter);
void menu(sf::RenderWindow& window, int clic_position, int difficulty_value, sf::Texture& background, sf::Texture& play, sf::Texture& difficulty, sf::Texture& difficulties);

#endif //WARPED_MENUS_H
