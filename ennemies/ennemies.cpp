#include "ennemies.h"

///affiche et gère toutes les tourelles du jeu via la classe Turrets
void turretsDisplay(sf::RenderWindow& window, vector<Turrets>& turrets, Player& player, sf::Texture& texture_1, sf::Texture& texture_2){
    int pos = 0;
    sf::Sprite sprite_1(texture_1);
    sf::Sprite sprite_2(texture_2);

    vector<int> deletes;

    for(auto& turret : turrets){
        turret.setDirection(player.size.x, player.pos.x);
        bool delete_turret = turret.display(window, sprite_1, sprite_2);

        if(delete_turret)
            deletes.push_back(pos);
        pos++;
    }

    int pos2 = 0;
    for(auto& turret : deletes){
        turret -= pos2;
        turrets.erase(turrets.begin() + turret);
        pos2++;
    }
}

///détermine si une tourelle doit tirer
void turretsShoots(Player& player, vector<Turrets>& turrets, vector<TurretsShoots>& turrets_shoots){
    for(auto& turret : turrets){
        if(turret.isNextToPlayer(player.size, player.pos) && turret.canShoot()){
            int direction = turret.returnDirection();
            sf::Vector2f turret_pos = turret.returnPos();
            if(direction == 0)
                turrets_shoots.push_back(TurretsShoots({turret_pos.x + 50 - 10, turret_pos.y + 7}, direction, 5));
            else if(direction == 1)
                turrets_shoots.push_back(TurretsShoots({turret_pos.x + 10, turret_pos.y + 7}, direction, 5));
        }
    }
}

///affiche les tirs des tourelles
void turretsShootsDisplay(sf::RenderWindow& window, vector<TurretsShoots>& turrets_shoots, Player& player, vector<sf::Vector2i>& walls, sf::Texture& texture_1, sf::Texture& texture_2){
    int pos = 0;
    sf::Sprite sprite_1(texture_1);
    sf::Sprite sprite_2(texture_2);

    vector<int> deletes;

    for(auto& shoot : turrets_shoots){
        shoot.wallCollisions(walls);
        bool delete_shoot1 = shoot.isOnScreen(player.pos);
        shoot.playerCollisions(player);
        bool delete_shoot2 = shoot.display(window, sprite_1, sprite_2);
        shoot.move();
        if(!delete_shoot1 || delete_shoot2)
            deletes.push_back(pos);
        pos++;
    }

    int pos2 = 0;
    for(auto& shoot : deletes){
        shoot -= pos2;
        turrets_shoots.erase(turrets_shoots.begin() + shoot);
        pos2++;
    }
}

///affiche et gère touts les drones du jeu via la classe Drones
void dronesDisplay(sf::RenderWindow& window, vector<Drones>& drones, Player& player, sf::Texture& texture_1, sf::Texture& texture_2){
    int pos = 0;
    sf::Sprite sprite_1(texture_1);
    sf::Sprite sprite_2(texture_2);

    vector<int> deletes;

    for(auto& drone : drones){
        drone.setDirection(player.size.x, player.pos.x);
        bool delete_turret = drone.display(window, sprite_1, sprite_2);
        drone.move();

        if(delete_turret)
            deletes.push_back(pos);
        pos++;
    }

    int pos2 = 0;
    for(auto& drone : deletes){
        drone -= pos2;
        drones.erase(drones.begin() + drone);
        pos2++;
    }
}
