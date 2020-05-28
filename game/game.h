#ifndef WARPED_GAME_H
#define WARPED_GAME_H

#include "../includes.h"
#include "../ennemies/Turrets.h"
#include "../ennemies/Drones.h"

void gameOver(int& display_key);
void gameOverScreen(sf::RenderWindow& window, int& display_key, int& menu_clic_position);
void gameWin();
void setTurrets(std::map<std::pair<int, int>, int>& map1_turrets, vector<Turrets>& turrets, int difficulty_value);
void setDrones(std::map<std::pair<int, int>, int>& map1_drones, vector<Drones>& drones, int difficulty_value);

#endif //WARPED_GAME_H
