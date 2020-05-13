#include "PlayerShoots.h"

///Default Constructor
PlayerShoots::PlayerShoots(sf::Vector2f _pos, int _direction): pos(_pos), direction(_direction){}

///fait avancer le tir dans la bonne direction
void PlayerShoots::move(){
    if(!hit){
        if(direction == 0)
            pos.x += speed;
        else
            pos.x -= speed;
    }
}

///affiche le tir/impact à la bonne position en fonction de s'il y a un impact ou non
bool PlayerShoots::display(sf::RenderWindow& window, sf::Sprite& sprite_1, sf::Sprite& sprite_2){
    if(!hit){
        sprite_1.setPosition(sf::Vector2f(pos.x, pos.y + 2));
        window.draw(sprite_1);
    }
    else{
        sprite_2.setTextureRect(sf::IntRect(hit_sprite * 12, direction * 12, 12, 12));
        sprite_2.setPosition(sf::Vector2f(pos.x, pos.y - 2));
        window.draw(sprite_2);
        hit_sprite++;
    }

    return hit_sprite >= 4;
}

///Vérifie les collisions entre la balle et les murs
void PlayerShoots::wallCollisions(vector<sf::Vector2i>& walls){
    if(!hit){
        for(auto& wall : walls){
            if(((pos.x < wall.x && pos.x + size.x > wall.x) ||
                (pos.x > wall.x && pos.x + size.x < wall.x + 32.f) ||
                (pos.x < wall.x + 32.f && pos.x + size.x > wall.x + 32.f)) &&
               ((pos.y < wall.y && pos.y + size.y > wall.y) ||
                (pos.y > wall.y && pos.y + size.y < wall.y + 32.f) ||
                (pos.y < wall.y + 32.f && pos.y + size.y > wall.y + 32.f))){
                hit = true;
                if(direction == 0)
                    pos.x = wall.x - 6;
                else
                    pos.x = wall.x + 32 - 6;
            }
        }
    }
}

///vérifie les collisions entre la balle et les ennemis
void PlayerShoots::ennemiesCollisions(vector<Turrets> &turrets){
    for(auto& turret : turrets){
        bool hit_turret = turret.isHit(size, pos, damages);
        if(hit_turret){
            hit = true;
            damages = 0;
            break;
        }
    }
}

///vérifie si la balle est toujours visible à l'écran
bool PlayerShoots::isOnScreen(sf::Vector2f player_pos){
    if(pos.x > player_pos.x + 1300 || pos.x < player_pos.x - 1300)
        return false;
    else
        return true;
}
