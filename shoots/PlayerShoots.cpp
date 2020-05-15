#include "PlayerShoots.h"

///Default Constructor
PlayerShoots::PlayerShoots(sf::Vector2f _pos, int _direction, int _speed): Shoots(_pos, _direction, _speed), pos(_pos){}

///vérifie les collisions entre la balle et les ennemis
void PlayerShoots::ennemiesCollisions(Player& player, vector<Turrets> &turrets){
    bool hit = isHit();
    pos = returnPos();
    if(!hit){
        for(auto& turret : turrets){
            bool hit_turret = turret.isHit(player, size, pos, damages);
            if(hit_turret){
                isHit(true);
                break;
            }
        }
    }
}
