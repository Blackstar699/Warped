#ifndef WARPED_TURRETS_H
#define WARPED_TURRETS_H

#include "includes.h"
#include "fonctions.h"

class Turrets{
private:
    sf::Vector2i size{50, 46};
    sf::Vector2f pos;
    int direction{0};
    int health;
    bool alive{true};
    int sprite{0};
    int death_sprite{0};
    sf::Clock sprite_clock;
public:
    explicit Turrets(sf::Vector2f _pos, int _health);
    bool display(sf::RenderWindow& window, sf::Sprite& sprite_1, sf::Sprite& sprite_2);
    void setDirection(int player_size_x, int player_pos_x);
    bool isHit(sf::Vector2i& shoot_size, sf::Vector2f& shoot_pos, int damages);
};

#endif //WARPED_TURRETS_H
