#ifndef WARPED_EVENTS_H
#define WARPED_EVENTS_H

#include "includes.h"

void homeEvents(sf::Event& event, int& display_key, sf::Clock& clock);
void menuEvents(sf::Event& event, int& display_key, int& difficulty_value, int& menu_clic_position, sf::Clock& player_clock);
void gameEvents(Player& player);

#endif //WARPED_EVENTS_H
