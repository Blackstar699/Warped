#ifndef WARPED_PLAYERSHOOTS_H
#define WARPED_PLAYERSHOOTS_H

#include "includes.h"
#include "fonctions.h"

class PlayerShoots{
private:
    sf::Vector2i size{12, 8};
    sf::Vector2f pos;
    //int damages{20};
    int direction;
    int speed{30};
    bool hit{false};
    int hit_sprite{0};
public:
    explicit PlayerShoots(sf::Vector2f _pos, int _direction);
    void move();
    bool display(sf::RenderWindow& window);
    void collisions(vector<sf::Vector2i>& walls);
    bool isOnScreen(sf::Vector2f player_pos);
};

#endif //WARPED_PLAYERSHOOTS_H
