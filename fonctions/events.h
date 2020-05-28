#ifndef WARPED_EVENTS_H
#define WARPED_EVENTS_H

#include "../includes.h"
#include "../shoots/PlayerShoots.h"
#include "../game/game.h"

void homeEvents(sf::Event& event, int& display_key, sf::Clock& clock);
void menuEvents(sf::Event& event, int& display_key, int& difficulty_value, bool& instantdeath, int& menu_clic_position, Player& player, std::map<std::pair<int, int>, int>& map1_turrets, vector<Turrets>& turrets, std::map<std::pair<int, int>, int>& map1_drones, vector<Drones>& drones);
void gameEvents(Player& player, vector<PlayerShoots>& player_shoots);

#endif //WARPED_EVENTS_H
