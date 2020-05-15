#ifndef WARPED_ENNEMIES_H
#define WARPED_ENNEMIES_H

#include "../includes.h"
#include "Turrets.h"
#include "../shoots/TurretsShoots.h"

void turretsDisplay(sf::RenderWindow& window, vector<Turrets>& turrets, Player& player, sf::Texture& texture_1, sf::Texture& texture_2);
void turretsShoots(Player& player, vector<Turrets>& turrets, vector<TurretsShoots>& turrets_shoots);
void turretsShootsDisplay(sf::RenderWindow& window, vector<TurretsShoots>& turrets_shoots, Player& player, vector<sf::Vector2i>& walls, sf::Texture& texture_1, sf::Texture& texture_2);

#endif //WARPED_ENNEMIES_H
