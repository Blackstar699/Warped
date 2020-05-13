#include "Turrets.h"

Turrets::Turrets(sf::Vector2f _pos, int _health): pos(_pos), health(20 * _health){}

///affiche la tourelle/explosion a la bonne position et dans le bon sens
bool Turrets::display(sf::RenderWindow& window, sf::Sprite &sprite_1, sf::Sprite &sprite_2){
    if(alive){
        if(sprite_clock.getElapsedTime().asMilliseconds() >= 50){
            sprite_clock.restart();
            if(direction == 0 && sprite != 4){
                sprite++;
            }
            else if(direction == 1 && sprite != 0){
                sprite--;
            }
        }
        sprite_1.setTextureRect(sf::IntRect(sprite * size.x, 0, size.x, size.y));
        sprite_1.setPosition(sf::Vector2f(pos.x, pos.y));
        window.draw(sprite_1);
    }
    else{
        sprite_2.setTextureRect(sf::IntRect(death_sprite * 55, 0, 55, 52));
        sprite_2.setPosition(sf::Vector2f(pos.x - 2, pos.y - 3));
        window.draw(sprite_2);
        if(sprite_clock.getElapsedTime().asMilliseconds() >= 50){
            sprite_clock.restart();
            death_sprite++;
        }
    }

    return death_sprite >= 6;
}

///règle la direction de la tourelle en fonction de la direction du joueur
void Turrets::setDirection(int player_size_x, int player_pos_x){
    if(player_pos_x + player_size_x - 50 <= pos.x){
        direction = 1;
    }
    else if(player_pos_x + 50 >= pos.x + size.x){
        direction = 0;
    }
}

bool Turrets::isHit(sf::Vector2i &shoot_size, sf::Vector2f &shoot_pos, int damages){
    if(((shoot_pos.x + shoot_size.x >= pos.x + 10 && shoot_pos.x <= pos.x + 10) ||
    (shoot_pos.x + shoot_size.x >= pos.x + 10 && shoot_pos.x <= pos.x + size.x - 10) ||
    (shoot_pos.x + shoot_size.x >= pos.x + size.x - 10 && shoot_pos.x <= pos.x + size.x - 10)) &&
    ((shoot_pos.y + shoot_size.y >= pos.y && shoot_pos.y <= pos.y) ||
    (shoot_pos.y + shoot_size.y >= pos.y + size.y && shoot_pos.y <= pos.y + size.y))){
        health -= damages;
        if(health <= 0)
            alive = false;
        return true;
    }
    else
        return false;
}
