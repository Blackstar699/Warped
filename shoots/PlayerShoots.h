#ifndef WARPED_PLAYERSHOOTS_H
#define WARPED_PLAYERSHOOTS_H

#include "../includes.h"
#include "Shoots.h"
#include "../fonctions/fonctions.h"
#include "../ennemies/ennemies.h"

class PlayerShoots : public Shoots{
private:
    sf::Vector2i size{12, 8};
    sf::Vector2f pos;
    int damages{20};
public:
    explicit PlayerShoots(sf::Vector2f _pos, int _direction, int _speed);
    void ennemiesCollisions(Player& player, vector<Turrets>& turrets, vector<Drones>& drones);
};

#endif //WARPED_PLAYERSHOOTS_H
