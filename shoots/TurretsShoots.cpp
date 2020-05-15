#include "TurretsShoots.h"

///Default Constructor
TurretsShoots::TurretsShoots(sf::Vector2f _pos, int _direction, int _speed): Shoots(_pos, _direction, _speed), pos(_pos){}

///Vérifie si les balles touchent le joueur
void TurretsShoots::playerCollisions(Player &player){
    bool hit = isHit();
    pos = returnPos();
    if(!hit && !player.jump){
        bool hit_player = player.isHit(size, pos, damages);
        if(hit_player){
            isHit(true);
        }
    }
}
