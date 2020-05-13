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

    for(auto& turret : deletes){
        turrets.erase(turrets.begin() + turret);
    }
}
