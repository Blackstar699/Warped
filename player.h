#ifndef WARPED_PLAYER_H
#define WARPED_PLAYER_H

#include "includes.h"
#include "game.h"
#include "PlayerShoots.h"

void playerDisplay(sf::RenderWindow& window, Player& player, sf::Texture& psg);
void playerReset(vector<int>& sprite_x, int sprite_y);
void playerIsAlive(int player_health, int& display_key);
void playerCollisions(Player& player, vector<sf::Vector2i>& walls, vector<sf::Vector2i>& grounds, vector<sf::Vector2i>& ladders);
void playerHUD(sf::RenderWindow& window, Player& player);
void playerShootsDisplay(sf::RenderWindow& window, vector<PlayerShoots>& player_shoots, sf::Vector2f player_pos, vector<sf::Vector2i>& walls, sf::Texture& texture_1, sf::Texture& texture_2, vector<Turrets>& turrets);

#endif //WARPED_PLAYER_H
