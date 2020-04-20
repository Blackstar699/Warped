#ifndef WARPED_EVENTS_H
#define WARPED_EVENTS_H

#include "includes.h"
#include "PlayerShoots.h"

void homeEvents(sf::Event& event, int& display_key, sf::Clock& clock);
void menuEvents(sf::Event& event, int& display_key, int& difficulty_value, int& menu_clic_position, Player& player);
void gameEvents(Player& player, vector<PlayerShoots>& player_shoots);

#endif //WARPED_EVENTS_H
