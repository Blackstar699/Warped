#include "events.h"

void homeEvents(sf::Event& event, int& display_key, sf::Clock& clock){
    if(event.key.code == sf::Keyboard::Enter){
        display_key = 1;
        cout << "Menu principal" << endl;
        clock.restart();
    }
}


void menuEvents(sf::Event& event, int& display_key, int& difficulty_value, int& menu_clic_position, Player& player){
    if(menu_clic_position == 1){
        if(event.key.code == sf::Keyboard::Enter){
            display_key = 10;
            cout << "Lancement d'une partie en difficulte " << difficulty_value << "/4" << endl;
            player.pos.x = 0;
            player.pos.y = 0 - player.size.y;
            player.direction = 0;
            player.health = 100;
            player.fall = 0;
            player.coins = 0;
            player.game_time = 0;
            player.clock.restart();
            player.game_clock.restart();
        }
        else if(event.key.code == sf::Keyboard::Down)
            menu_clic_position = 2;
    }

    else if(menu_clic_position == 2){
        if(event.key.code == sf::Keyboard::Up)
            menu_clic_position = 1;
        else if(event.key.code == sf::Keyboard::Left && difficulty_value != 1)
            difficulty_value--;
        else if(event.key.code == sf::Keyboard::Right && difficulty_value != 4)
            difficulty_value++;
    }
}


void gameEvents(Player& player, vector<PlayerShoots>& player_shoots){
    if(player.clock.getElapsedTime().asMilliseconds() >= 100){
        player.update = true;
        player.clock.restart();
    } else{
        player.update = false;
    }


    bool shoot;
    if(player.shoot_clock.getElapsedTime().asMilliseconds() > 250){
        shoot = true;
        player.shoot_clock.restart();
    }
    else
        shoot = false;


    if(player.onground)
        player.fall = 0;


    //détermine les actions et animations en fonction des touches pressées
    if(!player.hit && !player.jump){
        if(!player.onground){
            if(player.ladder){
                player.sprite_y = 14;
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    player.pos.y -= player.speed;
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    player.pos.y += player.speed;
                if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    player.update = false;
            }
            if(!player.ladder){
                player.pos.y += player.speed * 2;
                player.fall++;
                if(player.fall >= 35)
                    player.health = 0;
            }
        }
        else{
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                if(player.ladder){
                    player.pos.y -= player.speed;
                    player.sprite_y = 14;
                }
                else{
                    if(player.onground)
                        player.jump = true;
                }
            }
            else{
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
                    ///fonction bomb
                }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                        if(player.ladder){
                            player.pos.y += player.speed;
                            player.sprite_y = 14;
                        }
                        else{
                            player.sprite_y = 8;
                            if(shoot){
                                player.shoot_clock.restart();
                                if(player.direction == 0)
                                    player_shoots.push_back(PlayerShoots({player.pos.x + 108, player.pos.y + 84}, player.direction));
                                else
                                    player_shoots.push_back(PlayerShoots({player.pos.x + 34 - 6, player.pos.y + 84}, player.direction));
                            }
                        }
                    }
                    else{
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                            player.pos.x += player.speed;
                            player.sprite_y = 6;
                            player.direction = 0;
//                            cout << "x: " << player.pos.x << endl;
                            if(shoot){
                                player.shoot_clock.restart();
                                player_shoots.push_back(PlayerShoots({player.pos.x + 126, player.pos.y + 56}, player.direction));
                            }
                        }
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                            player.pos.x -= player.speed;
                            if(player.pos.x <= 0)
                                player.pos.x = 0;
                            player.sprite_y = 6;
                            player.direction = 1;
//                            cout << "x: " << player.pos.x << endl;
                            if(shoot){
                                player.shoot_clock.restart();
                                player_shoots.push_back(PlayerShoots({player.pos.x + 16 - 6, player.pos.y + 56}, player.direction));
                            }
                        }
                        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                            player.sprite_y = 12;
                            if(shoot){
                                player.shoot_clock.restart();
                                if(player.direction == 0)
                                    player_shoots.push_back(PlayerShoots({player.pos.x + 110, player.pos.y + 48}, player.direction));
                                else
                                    player_shoots.push_back(PlayerShoots({player.pos.x + 32 - 6, player.pos.y + 48}, player.direction));
                            }
                        }
                    }
                }
                else{
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                        if(player.ladder){
                            player.pos.y += player.speed;
                            player.sprite_y = 14;
                        }
                        else{
                            player.sprite_y = 8;
                        }
                    }
                    else{
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                            player.pos.x += player.speed;
                            player.sprite_y = 4;
                            player.direction = 0;
//                            cout << "x: " << player.pos.x << endl;
                        }
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                            player.pos.x -= player.speed;
                            if(player.pos.x <= 0)
                                player.pos.x = 0;
                            player.sprite_y = 4;
                            player.direction = 1;
//                            cout << "x: " << player.pos.x << endl;
                        }
                        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                            player.sprite_y = 0;
                        }
                    }
                }
            }
        }
    }
    if(player.hit || player.jump){
        if(player.hit){
            ///fonction hit
        }
        if(player.jump){
            player.sprite_y = 2;
            if(player.sprite_x[player.sprite_y] <= 1){
                player.pos.y -= player.speed;
            }
            else if(player.sprite_x[player.sprite_y] <= 3){
                player.pos.y += player.speed;
                if(player.sprite_x[player.sprite_y] == 3){
                    if(player.onground)
                        player.jump = false;
                    else{
                        player.fall++;
                        if(player.fall >= 35)
                            player.health = 0;
                        if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
                            if(shoot){
                                player.shoot_clock.restart();
                                if(player.direction == 0)
                                    player_shoots.push_back(PlayerShoots({player.pos.x + 114, player.pos.y + 50}, player.direction));
                                else
                                    player_shoots.push_back(PlayerShoots({player.pos.x + 28 - 6, player.pos.y + 50}, player.direction));
                            }
                        }
                    }
                }
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                player.pos.x += player.speed * 2;
                player.direction = 0;
//                cout << "x: " << player.pos.x << endl;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                player.pos.x -= player.speed * 2;
                if(player.pos.x <= 0)
                    player.pos.x = 0;
                player.direction = 1;
//                cout << "x: " << player.pos.x << endl;
            }
        }
    }
}
