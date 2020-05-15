#include "environment.h"

///affiche le background du jeu
void background(sf::RenderWindow& window, sf::Texture& texture){
    sf::Sprite sprite(texture);
    sprite.setPosition(0,0);
    window.draw(sprite);
}


///affiche l'environnement correspondant aux données de la map en paramètre
void environment(sf::RenderWindow& window, const std::map<std::pair<int, int>, int>& map, sf::Vector2f player_pos, sf::Texture& texture){
    sf::Sprite sprite(texture);

    for(auto& ligne : map){
        const int x = ligne.first.first, y = ligne.first.second, sprite_nbr = ligne.second;
        if(sprite_nbr != -1 && !(x * 32 > player_pos.x + 1300 || x * 32 < player_pos.x - 1300 || y * 32 > player_pos.y + 500 || y * 32 < player_pos.y - 500)){
            sprite = tileset1(sprite, sprite_nbr);
            sprite.setPosition(sf::Vector2f(x * 32, y * 32));
            window.draw(sprite);
        }
    }
}


///découpe correctement la tileset 1
sf::Sprite tileset1(sf::Sprite& sprite, int sprite_number){
    sf::Vector2i position(0, 0);
    position.x = sprite_number - floor(sprite_number / 12) * 12;
    position.y = floor(sprite_number / 12);
    sprite.setTextureRect(sf::IntRect(position.x * 32, position.y * 32, 32, 32));
    return sprite;
}


///reset la vue en fonction de l'emplacement du personnage
void setPlayerView(sf::View& view, sf::Vector2i screen_size, sf::Vector2f player_pos){
    view.reset(sf::FloatRect(0, 0, screen_size.x, screen_size.y));
    sf::Vector2i position(screen_size.x/2, screen_size.y/2);
    position.x = player_pos.x + 70 - screen_size.x/2.f;
    position.y = player_pos.y + 66 - screen_size.y/1.5f;
    if(position.x <= 0)
        position.x = 0;
    if(position.y + screen_size.y >= 352)
        position.y = 352 - screen_size.y;
    view.reset(sf::FloatRect(position.x, position.y, screen_size.x, screen_size.y));
}


///met dans un vector les coordonnées de chaque élément de décors non traversable
vector<sf::Vector2i> untraversablesTileset1(std::map<std::pair<int, int>, int>& map,  const vector<int>& untraversables_blocks){
    vector<sf::Vector2i> vector;

    for(auto& ligne : map){
        const int x = ligne.first.first, y = ligne.first.second, sprite_nbr = ligne.second;
        for(int untraversables_block : untraversables_blocks){
            if(sprite_nbr == untraversables_block){
                sf::Vector2i block(x * 32, y * 32);
                vector.push_back(block);
                break;
            }
        }
    }

    return vector;
}
