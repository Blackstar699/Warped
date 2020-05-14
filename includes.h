#ifndef WARPED_INCLUDES_H
#define WARPED_INCLUDES_H

#include <iostream>
#include <SFML/Graphics.hpp>
///#include <SFML/Audio.hpp>
using std::cout, std::cerr, std::endl, std::string, std::vector;

struct Player{
    sf::Vector2f size;
    sf::Vector2f pos;
    int direction;
    int health;
    float speed;
    bool onground;
    int fall;
    bool jump;
    bool hit;
    bool update;
    bool ladder;
    vector<int> spritesheet;
    int sprite_y;
    vector<int> sprite_x;
    int coins;
    int points;
    float game_time;
    sf::Clock clock;
    sf::Clock game_clock;
    sf::Clock shoot_clock;

    Player(){
        size.x = 142;
        size.y = 134;
        pos.x = 0;
        pos.y = 0 - size.y;
        direction = 0;
        health = 100;
        speed = 7;
        onground = true;
        fall = 0;
        jump = false;
        hit = false;
        update = false;
        ladder = false;
        spritesheet = {4, 4, 4, 4, 8, 8, 8, 8, 1, 1, 1, 1, 1, 1, 6};
        sprite_y = 0;
        sprite_x = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        coins = 0;
        points = 0;
        game_time = 0;
    }

    bool isHit(sf::Vector2i &shoot_size, sf::Vector2f &shoot_pos, int damages){
        if(((shoot_pos.x + shoot_size.x >= pos.x + 57 && shoot_pos.x <= pos.x + 57) ||
            (shoot_pos.x + shoot_size.x >= pos.x + 57 && shoot_pos.x <= pos.x + size.x - 57) ||
            (shoot_pos.x + shoot_size.x >= pos.x + size.x - 57 && shoot_pos.x <= pos.x + size.x - 57)) &&
            ((shoot_pos.y + shoot_size.y >= pos.y && shoot_pos.y <= pos.y) ||
            (shoot_pos.y + shoot_size.y >= pos.y && shoot_pos.y <= pos.y + size.y) ||
            (shoot_pos.y + shoot_size.y >= pos.y + size.y && shoot_pos.y <= pos.y + size.y))){
            health -= damages;
            return true;
        }
        else
            return false;
    }
};

#endif //WARPED_INCLUDES_H
