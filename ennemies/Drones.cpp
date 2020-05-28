#include "Drones.h"

///Class Constructor
Drones::Drones(sf::Vector2f _pos, int _health): pos(_pos), health(20 * _health){}

///affiche le drone/explosion a la bonne position et dans le bon sens
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

///fait bouger le drone de haut en bas
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

///vérifie si la tourelle est touchée par un tir du joueur
bool Drones::isHit(Player &player, sf::Vector2i &shoot_size, sf::Vector2f &shoot_pos, int damages){
    if(alive){
        if(((shoot_pos.x + shoot_size.x >= pos.x + 15 && shoot_pos.x <= pos.x + 15) ||
            (shoot_pos.x + shoot_size.x >= pos.x + 15 && shoot_pos.x <= pos.x + size.x - 15) ||
            (shoot_pos.x + shoot_size.x >= pos.x + size.x - 15 && shoot_pos.x <= pos.x + size.x - 15)) &&
            ((shoot_pos.y + shoot_size.y >= pos.y && shoot_pos.y <= pos.y) ||
            (shoot_pos.y + shoot_size.y >= pos.y && shoot_pos.y <= pos.y + size.y) ||
            (shoot_pos.y + shoot_size.y >= pos.y + size.y && shoot_pos.y <= pos.y + size.y))){
            health -= damages;
            if(health <= 0){
                alive = false;
                player.points += 60;
            }
            return true;
        }
        else
            return false;
    }
    else
        return false;
}


bool Drones::isNextToPlayer(sf::Vector2f p_size, sf::Vector2f p_pos){
    if((p_pos.x + p_size.x >= pos.x - 300 || p_pos.x <= pos.x + size.x + 300) &&
       (pos.y + size.y >= p_pos.y && pos.y + size.y <= p_pos.y + p_size.y)){
        return true;
    }
    else
        return false;
}

bool Drones::canShoot(){
    if(shoot_clock.getElapsedTime().asMilliseconds() >= 1000){
        shoot_clock.restart();
        return true;
    }
    else
        return false;
}

int Drones::returnDirection(){
    return direction;
}

sf::Vector2f Drones::returnPos(){
    return pos;
}
