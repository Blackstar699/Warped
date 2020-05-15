#ifndef WARPED_ENNEMIES_H
#define WARPED_ENNEMIES_H

#include "../includes.h"
#include "Turrets.h"
#include "../shoots/TurretsShoots.h"
#include "Drones.h"
#include "../shoots/DronesShoots.h"

void turretsDisplay(sf::RenderWindow& window, vector<Turrets>& turrets, Player& player, sf::Texture& texture_1, sf::Texture& texture_2);
void turretsShoots(Player& player, vector<Turrets>& turrets, vector<TurretsShoots>& turrets_shoots);
void turretsShootsDisplay(sf::RenderWindow& window, vector<TurretsShoots>& turrets_shoots, Player& player, vector<sf::Vector2i>& walls, sf::Texture& texture_1, sf::Texture& texture_2);
void dronesDisplay(sf::RenderWindow& window, vector<Drones>& drones, Player& player, sf::Texture& texture_1, sf::Texture& texture_2);
void dronesShoots(Player& player, vector<Drones>& drones, vector<DronesShoots>& drone_shoots);
void dronesShootsDisplay(sf::RenderWindow& window, vector<DronesShoots>& drones_shoots, Player& player, vector<sf::Vector2i>& walls, sf::Texture& texture_1, sf::Texture& texture_2);

#endif //WARPED_ENNEMIES_H
