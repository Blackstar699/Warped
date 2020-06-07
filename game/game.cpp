#include "game.h"

///appliqué si la partie est perdu (en cas de mort du joueur)
void gameOver(int& display_key){
    sf::sleep(sf::seconds(1));
    display_key = 11;
    cout << "Game Over" << endl;
}


///affiche l'écran gameover
void gameOverScreen(sf::RenderWindow& window, int& display_key, int& menu_clic_position, Player& player, sf::Texture& background){
    sf::Font font;
    if(!font.loadFromFile("resources/BalooBhaina2-Medium.ttf")){
        cerr << "erreur chargement font" << endl;
    }

    sf::Sprite background_s(background);

    sf::Text gameover;
    gameover.setFont(font);
    gameover.setString("Game Over !");
    gameover.setCharacterSize(150);
    gameover.setFillColor(sf::Color(0xfcb824ff));
    gameover.setPosition(sf::Vector2f(200, 50));

    sf::Text points;
    points.setFont(font);
    string points_string = "SCORE: " + std::to_string(player.points) + "pts";
    points.setString(points_string);
    points.setCharacterSize(50);
    points.setFillColor(sf::Color(0xfcb824ff));
    points.setPosition(sf::Vector2f(450, 250));

    sf::Text returnmenu;
    returnmenu.setFont(font);
    returnmenu.setString("Press Enter to return to the menu");
    returnmenu.setCharacterSize(30);
    returnmenu.setFillColor(sf::Color(0xfcb824ff));
    returnmenu.setPosition(sf::Vector2f(400, 350));

    window.draw(background_s);
    window.draw(gameover);
    window.draw(points);
    window.draw(returnmenu);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        display_key = 1;
        menu_clic_position = 2;
        cout << "Menu principal" << endl;
    }
}


///détermine si le joueur est arrivé à la fin de la map
void gameIsWin(Player& player, int& display_key){
    if(player.pos.x >= 11520){
        gameWin(display_key);
        player.points += player.health * 2;
    }
}


///appliqué si le joueur gagne la partie
void gameWin(int& display_key){
    sf::sleep(sf::seconds(1));
    display_key = 12;
    cout << "Game Win" << endl;
}


///affiche l'écran game win
void gameWinScreen(sf::RenderWindow& window, int& display_key, int& menu_clic_position, Player& player, sf::Texture& background){
    sf::Font font;
    if(!font.loadFromFile("resources/BalooBhaina2-Medium.ttf")){
        cerr << "erreur chargement font" << endl;
    }

    int mins = floor(player.game_time / 60);
    int secs = floor(player.game_time - 60 * mins);
    string game_time;
    if(mins < 10)
        game_time += "0";
    game_time += std::to_string(mins);
    game_time += ":";
    if(secs < 10)
        game_time += "0";
    game_time += std::to_string(secs);

    sf::Sprite background_s(background);

    sf::Text gamewin;
    gamewin.setFont(font);
    gamewin.setString("Game Win !");
    gamewin.setCharacterSize(150);
    gamewin.setFillColor(sf::Color(0xfcb824ff));
    gamewin.setPosition(sf::Vector2f(250, 10));

    sf::Text gametime;
    gametime.setFont(font);
    string gametime_string = "TIME: " + game_time;
    gametime.setString(gametime_string);
    gametime.setCharacterSize(50);
    gametime.setFillColor(sf::Color(0xfcb824ff));
    gametime.setPosition(sf::Vector2f(450, 200));

    sf::Text hp;
    hp.setFont(font);
    string hp_string = "PV: " + std::to_string(player.health);
    hp.setString(hp_string);
    hp.setCharacterSize(50);
    hp.setFillColor(sf::Color(0xfcb824ff));
    hp.setPosition(sf::Vector2f(450, 250));

    sf::Text points;
    points.setFont(font);
    string points_string = "SCORE: " + std::to_string(player.points) + "pts";
    points.setString(points_string);
    points.setCharacterSize(50);
    points.setFillColor(sf::Color(0xfcb824ff));
    points.setPosition(sf::Vector2f(450, 300));

    sf::Text returnmenu;
    returnmenu.setFont(font);
    returnmenu.setString("Press Enter to return to the menu");
    returnmenu.setCharacterSize(30);
    returnmenu.setFillColor(sf::Color(0xfcb824ff));
    returnmenu.setPosition(sf::Vector2f(400, 400));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        display_key = 1;
        menu_clic_position = 2;
        cout << "Menu principal" << endl;
    }

    window.draw(background_s);
    window.draw(gamewin);
    window.draw(gametime);
    window.draw(hp);
    window.draw(points);
    window.draw(returnmenu);
}


///rempli le vecteur des tourelles avec le fichier csv correspondant
void setTurrets(std::map<std::pair<int, int>, int>& map1_turrets, vector<Turrets>& turrets, int difficulty_value){
    turrets = {};

    for(auto& turret : map1_turrets){
        const float x = turret.first.first, y = turret.first.second;
        turrets.push_back(Turrets({x * 32, y * 32 - 14}, difficulty_value));
    }
}


///rempli le vecteur des drones avec le fichier csv correspondant
void setDrones(std::map<std::pair<int, int>, int>& map1_drones, vector<Drones>& drones, int difficulty_value){
    drones = {};

    for(auto& turret : map1_drones){
        const float x = turret.first.first, y = turret.first.second;
        drones.push_back(Drones({x * 32, y * 32 - 20 - 55}, difficulty_value));
    }
}
