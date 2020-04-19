#ifndef WARPED_PLAYER_H
#define WARPED_PLAYER_H

#include "includes.h"
#include "fonctions.h"

void playerDisplay(sf::RenderWindow& window, Player& player);
//void playerIdle(sf::Sprite& sprite, sf::Vector2i player_sprite);
//void playerJump(sf::Sprite& sprite, sf::Vector2i player_sprite);
//void playerRun(sf::Sprite& sprite, sf::Vector2i player_sprite);
//void playerRunShoot(sf::Sprite& sprite, sf::Vector2i player_sprite);
//void playerCrouch(sf::Sprite& sprite, sf::Vector2i player_sprite);
//void playerHurt(sf::Sprite& sprite, sf::Vector2i player_sprite);
//void playerShoot(sf::Sprite& sprite, sf::Vector2i player_sprite);
//void playerClimb(sf::Sprite& sprite, sf::Vector2i player_sprite);
void playerReset(vector<int>& sprite_x, int sprite_y);
void playerIsAlive(int player_health);
void playerCollisions(Player& player, vector<sf::Vector2i>& walls, vector<sf::Vector2i>& grounds, vector<sf::Vector2i>& ladders);

#endif //WARPED_PLAYER_H
