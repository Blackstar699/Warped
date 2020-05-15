#ifndef WARPED_SHOOTS_H
#define WARPED_SHOOTS_H

#include "../includes.h"

class Shoots{
private:
    sf::Vector2i size{12, 8};
    sf::Vector2f pos;
    int direction;
    int speed;
    bool hit{false};
    int hit_sprite{0};
public:
    explicit Shoots(sf::Vector2f _pos, int _direction, int _speed);
    void move();
    bool display(sf::RenderWindow& window, sf::Sprite& sprite_1, sf::Sprite& sprite_2);
    void wallCollisions(vector<sf::Vector2i>& walls);
//    void ennemiesCollisions(Player& player, vector<Turrets>& turrets);
    bool isOnScreen(sf::Vector2f player_pos);
    bool isHit();
    void isHit(bool state);
    sf::Vector2f returnPos();
};

#endif //WARPED_SHOOTS_H
