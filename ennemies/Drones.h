#ifndef WARPED_DRONES_H
#define WARPED_DRONES_H

#include "../includes.h"
#include "../fonctions/fonctions.h"

class Drones{
private:
    sf::Vector2i size{55, 52};
    sf::Vector2f pos;
    int direction{0};
    float move_pos{0};
    int move_direction{0};
    int health;
    bool alive{true};
    int sprite{0};
    int death_sprite{0};
    sf::Clock sprite_clock;
    sf::Clock shoot_clock;
public:
    explicit Drones(sf::Vector2f _pos, int _health);
    bool display(sf::RenderWindow& window, sf::Sprite& sprite_1, sf::Sprite& sprite_2);
    void setDirection(int player_size_x, int player_pos_x);
    void move();
};

#endif //WARPED_DRONES_H
