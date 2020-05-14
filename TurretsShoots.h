#ifndef WARPED_TURRETSSHOOTS_H
#define WARPED_TURRETSSHOOTS_H

#include "includes.h"
#include "Shoots.h"

class TurretsShoots : public Shoots{
private:
    sf::Vector2i size{12, 8};
    sf::Vector2f pos;
    int damages{5};
public:
    explicit TurretsShoots(sf::Vector2f _pos, int _direction, int _speed);
    void playerCollisions(Player& player);
};

#endif //WARPED_TURRETSSHOOTS_H
