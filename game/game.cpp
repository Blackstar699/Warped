#include "game.h"

///appliqué si la partie est perdu (en cas de mort du joueur)
void gameOver(int& display_key){
    sf::sleep(sf::seconds(1));
    display_key = 11;
    cout << "Game Over" << endl;
}


///affiche l'écran gameover
void gameOverScreen(sf::RenderWindow& window, int& display_key, int& menu_clic_position){
    sf::Font font;
    if(!font.loadFromFile("resources/BalooBhaina2-Medium.ttf")){
        cerr << "erreur chargement font" << endl;
    }

    sf::Text gameover;
    gameover.setFont(font);
    gameover.setString("Game Over !");
    gameover.setCharacterSize(150);
    gameover.setFillColor(sf::Color::White);
    gameover.setPosition(sf::Vector2f(200, 50));

    sf::Text returnmenu;
    returnmenu.setFont(font);
    returnmenu.setString("Press Enter to return to the menu");
    returnmenu.setCharacterSize(30);
    returnmenu.setFillColor(sf::Color::White);
    returnmenu.setPosition(sf::Vector2f(400, 500));

    window.draw(gameover);
    window.draw(returnmenu);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        display_key = 1;
        menu_clic_position = 2;
        cout << "Menu principal" << endl;
    }
}


///appliqué si le joueur gagne la partie
void gameWin(){

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
