#include "game.h"

///appliqué si la partie est perdu (en cas de mort du joueur)
void gameOver(int& display_key){
    sf::Clock clock;
    while(clock.getElapsedTime().asSeconds() < 1){}
    display_key = 11;
    cout << "Game Over" << endl;
}


///affiche l'écran gameover
void gameOverScreen(sf::RenderWindow& window, int& display_key){
    string path = "../../";

    sf::Font font;
    if(!font.loadFromFile(path + "resources/BalooBhaina2-Medium.ttf")){
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
        display_key = 2;
        cout << "Menu principal" << endl;
    }
}


///appliqué si le joueur gagne la partie
void gameWin(){

}
