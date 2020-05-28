#include "menus.h"


void home(sf::RenderWindow& window, int& home_alpha_value, sf::Clock& clock, sf::Texture& background, sf::Texture& enter){
    if(clock.getElapsedTime().asSeconds() >= 0.5){
        clock.restart();
        home_alpha_value *= -1;
    }

    sf::Sprite background_s(background);
    background_s.setPosition(0,0);

    sf::Sprite enter_s(enter);

    window.draw(background_s);
    window.draw(homeEnterText(enter_s, home_alpha_value));
}


sf::Sprite homeEnterText(sf::Sprite sprite, int alpha_nbr){
    sprite.setPosition(480,400);
    if(alpha_nbr == 1)
        sprite.setColor(sf::Color(255,255,255, 255));
    else
        sprite.setColor(sf::Color(255,255,255, 0));
    return sprite;
}


void menu(sf::RenderWindow& window, int clic_position, int difficulty_value, bool instantdeath_value, sf::Texture& background, sf::Texture& play, sf::Texture& difficulty, sf::Texture& difficulties, sf::Texture& instantdeath, sf::Texture& yes_no){
    sf::Sprite background_s(background);
    background_s.setPosition(0,0);

    sf::Sprite play_s(play);
    play_s.setScale(sf::Vector2f(0.75, 0.75));
    play_s.setColor(sf::Color(0, 168, 243));
    play_s.setPosition(50,150);

    sf::Sprite difficulty_s(difficulty);
    difficulty_s.setScale(sf::Vector2f(0.75, 0.75));
    difficulty_s.setPosition(50,210);

    sf::Sprite difficulties_s(difficulties);
    difficulties_s.setTextureRect(sf::IntRect(0, (56*difficulty_value)-56, 296, 56));
    difficulties_s.setScale(sf::Vector2f(0.75, 0.75));
    difficulties_s.setColor(sf::Color(0, 168, 243));
    difficulties_s.setPosition(300,210);

    sf::Sprite instantdeath_s(instantdeath);
    instantdeath_s.setScale(sf::Vector2f(0.75, 0.75));
    instantdeath_s.setPosition(50,270);

    sf::Sprite yesno_s(yes_no);
    yesno_s.setTextureRect(sf::IntRect(0, (56 * instantdeath_value), 200, 56));
    yesno_s.setScale(sf::Vector2f(0.75, 0.75));
    yesno_s.setColor(sf::Color(0, 168, 243));
    yesno_s.setPosition(420,270);

    if(clic_position == 1)
        play_s.setColor(sf::Color(236, 28, 36));
    else if(clic_position == 2)
        difficulties_s.setColor(sf::Color(236, 28, 36));
    else if(clic_position == 3)
        yesno_s.setColor(sf::Color(236, 28, 36));

    window.draw(background_s);
    window.draw(play_s);
    window.draw(difficulty_s);
    window.draw(difficulties_s);
    window.draw(instantdeath_s);
    window.draw(yesno_s);
}
