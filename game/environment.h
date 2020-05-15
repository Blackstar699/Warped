#ifndef WARPED_ENVIRONMENT_H
#define WARPED_ENVIRONMENT_H

#include "../includes.h"
#include "../fonctions/fonctions.h"

void background(sf::RenderWindow& window, sf::Texture& texture);
void environment(sf::RenderWindow& window, const std::map<std::pair<int, int>, int>& map, sf::Vector2f player_pos, sf::Texture& texture);
sf::Sprite tileset1(sf::Sprite& sprite, int sprite_number);
void setPlayerView(sf::View& view, sf::Vector2i screen_size, sf::Vector2f player_pos);
vector<sf::Vector2i> untraversablesTileset1(std::map<std::pair<int, int>, int>& map, const vector<int>& untraversables_blocks);

#endif //WARPED_ENVIRONMENT_H
