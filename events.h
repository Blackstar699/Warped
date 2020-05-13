#ifndef WARPED_EVENTS_H
#define WARPED_EVENTS_H

#include "includes.h"
#include "PlayerShoots.h"
#include "game.h"

void homeEvents(sf::Event& event, int& display_key, sf::Clock& clock);
void menuEvents(sf::Event& event, int& display_key, int& difficulty_value, int& menu_clic_position, Player& player, std::map<std::pair<int, int>, int>& map1_turrets, vector<Turrets>& turrets);
void gameEvents(Player& player, vector<PlayerShoots>& player_shoots);

#endif //WARPED_EVENTS_H
