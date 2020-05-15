#include "Drones.h"

///Default Constructor
Drones::Drones(sf::Vector2f _pos, int _health): pos(_pos), health(10 * _health){}

bool Drones::display(sf::RenderWindow &window, sf::Sprite &sprite_1, sf::Sprite &sprite_2){
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
        sprite_2.setTextureRect(sf::IntRect(death_sprite * size.x, 0, size.x, size.y));
        sprite_2.setPosition(sf::Vector2f(pos.x, pos.y));
        window.draw(sprite_2);
        if(sprite_clock.getElapsedTime().asMilliseconds() >= 50){
            sprite_clock.restart();
            death_sprite++;
        }
    }

    return death_sprite >= 6;
}

///règle la direction du drone en fonction de la position du joueur
void Drones::setDirection(int player_size_x, int player_pos_x){
    if(player_pos_x + player_size_x - 50 <= pos.x){
        direction = 1;
    }
    else if(player_pos_x + 50 >= pos.x + size.x){
        direction = 0;
    }
}


void Drones::move(){
    if(move_pos <= 20 && move_direction == 1){
        if(move_pos != 20){
            move_pos++;
            pos.y -= 0.5;
        }
        else
            move_direction = 0;
    }
    else if(move_pos >= 0 && move_direction == 0){
        if(move_pos != 0){
            move_pos--;
            pos.y += 0.5;
        }
        else
            move_direction = 1;
    }
}
