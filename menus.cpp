#include "menus.h"


void home(sf::RenderWindow& window, int& home_alpha_value, sf::Clock& clock){
    string path = "../../";

    if(clock.getElapsedTime().asSeconds() >= 0.5){
        clock.restart();
        home_alpha_value *= -1;
    }

    sf::Texture background_home_T = loadTexture(path + "resources/Sprites/home/background.png");
    sf::Sprite background_home(background_home_T);
    background_home.setPosition(0,0);

    sf::Texture enter_T = loadTexture(path + "resources/Sprites/home/press-enter.png");
    sf::Sprite enter(enter_T);

    window.draw(background_home);
    window.draw(homeEnterText(enter, home_alpha_value));
}


sf::Sprite homeEnterText(sf::Sprite sprite, int alpha_nbr){
    sprite.setPosition(480,400);
    if(alpha_nbr == 1)
        sprite.setColor(sf::Color(255,255,255, 255));
    else
        sprite.setColor(sf::Color(255,255,255, 0));
    return sprite;
}


///montrer que je sais faire des formes et du texte
void shapesDemo(sf::RenderWindow& window, sf::Clock& clock, int& display_key){
    string path = "../../";

    sf::Font font;
    if(!font.loadFromFile(path + "resources/BalooBhaina2-Medium.ttf")){
        cerr << "erreur chargement font" << endl;
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Voila, je sais afficher des formes (et du texte du coup), \n mais pour la suite c'est que des sprites !");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(200, 50));

    if(clock.getElapsedTime().asSeconds() < 1){
        sf::RectangleShape rect(sf::Vector2f(400, 200));
        rect.setFillColor(sf::Color(200, 0, 0));
        rect.setPosition(sf::Vector2f(200, 300));
        sf::CircleShape circle(50, 50);
        circle.setFillColor(sf::Color(0, 200, 0));
        circle.setPosition(sf::Vector2f(800, 350));
        window.draw(text);
        window.draw(rect);
        window.draw(circle);
    } else if(clock.getElapsedTime().asSeconds() > 1){
        display_key = 2;
    }
}


void menu(sf::RenderWindow& window, int clic_position, int difficulty_value){
    string path = "../../";

    sf::Texture menu_background_T = loadTexture(path + "resources/Sprites/menu/background.png");
    sf::Sprite menu_background(menu_background_T);
    menu_background.setPosition(0,0);

    sf::Texture menu_play_T = loadTexture(path + "resources/Sprites/menu/play.png");
    sf::Sprite menu_play(menu_play_T);
    menu_play.setScale(sf::Vector2f(0.75, 0.75));
    menu_play.setColor(sf::Color(0, 168, 243));
    menu_play.setPosition(50,150);

    sf::Texture menu_difficulty_T = loadTexture(path + "resources/Sprites/menu/difficulty.png");
    sf::Sprite menu_difficulty(menu_difficulty_T);
    menu_difficulty.setScale(sf::Vector2f(0.75, 0.75));
    menu_difficulty.setPosition(50,210);

    sf::Texture menu_difficulties_T = loadTexture(path + "resources/Sprites/menu/difficulties.png");
    sf::Sprite menu_difficulties(menu_difficulties_T);
    menu_difficulties.setTextureRect(sf::IntRect(0, (56*difficulty_value)-56, 296, 56));
    menu_difficulties.setScale(sf::Vector2f(0.75, 0.75));
    menu_difficulties.setColor(sf::Color(0, 168, 243));  //236 28 36
    menu_difficulties.setPosition(300,210);

//            sf::Texture options_menu_T = loadTexture(path + "menu/options.png");
//            sf::Sprite options_menu(options_menu_T);
//            options_menu.setScale(sf::Vector2f(0.75, 0.75));
//            options_menu.setPosition(50,350);

//            sf::Texture scores_menu_T = loadTexture(path + "menu/scores.png");
//            sf::Sprite scores_menu(scores_menu_T);
//            scores_menu.setScale(sf::Vector2f(0.75, 0.75));
//            scores_menu.setPosition(100,410);

    if(clic_position == 1){
        menu_play.setColor(sf::Color(236, 28, 36));
    } else if(clic_position == 2){
        menu_difficulties.setColor(sf::Color(236, 28, 36));
    }

    window.draw(menu_background);
    window.draw(menu_play);
    window.draw(menu_difficulty);
    window.draw(menu_difficulties);
//            window.draw(options_menu);
//            window.draw(scores_menu);
}
