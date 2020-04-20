#include "player.h"

///affiche la sprite du joueur correspondante à l'animation en cours
void playerDisplay(sf::RenderWindow& window, Player& player){
    string path = "../../";

    if(player.sprite_y < 14 && player.direction == 1)
        player.sprite_y += 1;

    playerReset(player.sprite_x, player.sprite_y);

    if(!player.jump || player.sprite_x[player.sprite_y] != 3){
        if(player.update){
            if(player.sprite_x[player.sprite_y] == player.spritesheet[player.sprite_y]-1)
                player.sprite_x[player.sprite_y] = 0;
            else
                player.sprite_x[player.sprite_y]++;
        }
    }

    sf::Texture psg_T = loadTexture(path + "resources/Sprites/game/player.png");
    sf::Sprite psg(psg_T);
    psg.setTextureRect(sf::IntRect(player.sprite_x[player.sprite_y] * 142, player.sprite_y * 134, 142, 134));
    psg.setPosition(player.pos.x, player.pos.y);
    window.draw(psg);
}


///remet à 0 les compteurs d'animations non utilisés actuellement
void playerReset(vector<int>& sprite_x, int sprite_y){
    int saut = 0;
    if(sprite_y == 2 || sprite_y == 3)
        saut = sprite_x[sprite_y];

    for(int i = 0; i < 15; i++){
        if(i != sprite_y){
            sprite_x[i] = 0;
        }
    }

    sprite_x[2] = sprite_x[3] = saut;
}


///vérifie si le joueur est encore en vie et déclenche la fin de la partie si ce n'est pas le cas
void playerIsAlive(int player_health, int& display_key){
    if(player_health <= 0){
        gameOver(display_key);
    }
}


///vérifie s'il y a des collisions entre le joueur et les murs/sols/échelles
void playerCollisions(Player& player, vector<sf::Vector2i>& walls, vector<sf::Vector2i>& grounds, vector<sf::Vector2i>& ladders){
    player.onground = false;
    player.ladder = false;

    //vérification sols
    for(auto& block : grounds){
        if(((block.x > (player.pos.x + player.size.x / 2) - 24 && block.x < (player.pos.x + player.size.x / 2) + 24) ||
        (block.x + 32.f > (player.pos.x + player.size.x / 2) - 24 && block.x + 32.f < (player.pos.x + player.size.x / 2) + 24)) &&
        (block.y <= player.pos.y + player.size.y && block.y + 32.f > player.pos.y + player.size.y)){
            player.pos.y = block.y - player.size.y;
            player.onground = true;
            break;
        }
    }

    //vérification murs gauches
    for(auto& block : walls){
        if((block.x + 32.f > player.pos.x + 30 && block.x < player.pos.x + 30) &&
        ((block.y > player.pos.y && block.y < player.pos.y + player.size.y) ||
        (block.y + 32.f > player.pos.y && block.y + 32.f < player.pos.y + player.size.y))){
            player.pos.x = block.x + 32.f - 30;
            break;
        }
    }

    //vérification murs droites
    for(auto& block : walls){
        if((block.x < player.pos.x + player.size.x - 30 && block.x + 32.f > player.pos.x + player.size.x - 30) &&
        ((block.y > player.pos.y && block.y < player.pos.y + player.size.y) ||
        (block.y + 32.f > player.pos.y && block.y + 32.f < player.pos.y + player.size.y))){
            player.pos.x = block.x - player.size.x + 30;
            break;
        }
    }

    //vérification échelles
    for(auto& block : ladders){
        if(((block.x > (player.pos.x + player.size.x / 2) - 20 && block.x < (player.pos.x + player.size.x / 2) + 20) ||
        (block.x + 32.f > (player.pos.x + player.size.x / 2) - 20 && block.x + 32.f < (player.pos.x + player.size.x / 2) + 20)) &&
        ((block.y > player.pos.y && block.y <= player.pos.y + player.size.y) ||
        (block.y + 32.f > player.pos.y && block.y + 32.f < player.pos.y + player.size.y))){
            player.ladder = true;
            if(block.y == player.pos.y + player.size.y){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                    player.onground = false;
                    player.pos.y += 35;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                    player.ladder = false;

                }
            }
            break;
        }
    }
}


///affiche les informations du joueur pendant la partie, comme la vie ou le temps écoulé
void playerHUD(sf::RenderWindow& window, Player& player){
    string path = "../../";
    player.game_time = player.game_clock.getElapsedTime().asSeconds();
    int mins = floor(player.game_time / 60);
    int secs = floor(player.game_time - 60 * mins);
    string game_time;
    game_time += std::to_string(mins);
    game_time += " : ";
    game_time += std::to_string(secs);

    sf::RectangleShape hp1(sf::Vector2f(304, 24));
    hp1.setFillColor(sf::Color::White);
    hp1.setPosition(sf::Vector2f(10, 10));
    sf::RectangleShape hp2(sf::Vector2f(player.health * 3, 20));
    hp2.setFillColor(sf::Color::Red);
    hp2.setPosition(sf::Vector2f(12, 12));

    sf::Font font;
    if(!font.loadFromFile(path + "resources/BalooBhaina2-Medium.ttf"))
        cerr << "erreur chargement font" << endl;
    sf::Text gametime;
    gametime.setFont(font);
    gametime.setString(game_time);
    gametime.setCharacterSize(25);
    gametime.setFillColor(sf::Color::White);
    gametime.setPosition(sf::Vector2f(10, 40));

    window.draw(hp1);
    window.draw(hp2);
    window.draw(gametime);
}


///affichage des tirs du joueur
void playerShootsDisplay(sf::RenderWindow& window, vector<PlayerShoots>& player_shoots, sf::Vector2f player_pos, vector<sf::Vector2i>& walls){
    int pos = 0;

    vector<int> deletes;
    for(auto& shoot : player_shoots){
        shoot.collisions(walls);
        bool delete_shoot1 = shoot.isOnScreen(player_pos);
        bool delete_shoot2 = shoot.display(window);
        shoot.move();
        if(!delete_shoot1 || delete_shoot2)
            deletes.push_back(pos);
        pos++;
    }

    for(auto& shoot : deletes){
        player_shoots.erase(player_shoots.begin() + shoot);
    }
}
