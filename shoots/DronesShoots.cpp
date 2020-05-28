#include "DronesShoots.h"

///Class Constructor
DronesShoots::DronesShoots(sf::Vector2f _pos, int _direction, int _speed, bool _instantdeath): Shoots(_pos, _direction, _speed), pos(_pos){
    if(_instantdeath)
        damages = 100;
    else
        damages = 5;
}

///Vérifie si les balles touchent le joueur
void DronesShoots::playerCollisions(Player &player){
    bool hit = isHit();
    pos = returnPos();
    if(!hit && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        bool hit_player = player.isHit(size, pos, damages);
        if(hit_player){
            isHit(true);
        }
    }
}

