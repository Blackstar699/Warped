#include "includes.h"
#include "events.h"
#include "menus.h"
#include "environment.h"
#include "player.h"


int main(){
    sf::err().rdbuf(nullptr);
    cout << "Lancement du jeu" << endl;

    //set fenetre
    const sf::Vector2i screen_size(1200, 700);
    sf::RenderWindow window(sf::VideoMode(screen_size.x, screen_size.y), "Warped - The Game", sf::Style::Close);
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(360, 190));

    //set global
    string path = "../../";
    int display_key = 0;  //définit la partie du jeu qui doit être affichée: 0 = accueil, 1 = menu principal, 10 = jeu
    int difficulty_value = 2;

    //set home/menu
    int home_alpha_value = 1;
    sf::Clock home_clock;
    sf::Clock shapes_clock;
    int menu_clic_position = 1;

    //set game
    sf::View player_view;
    Player player;
    std::map<std::pair<int, int>, int> map1_1 = getMap(path + "resources/maps/map1_1.csv");
    vector<int> tileset1_walls = {25, 31, 32, 37, 43, 44, 49, 55, 56, 67, 68};
    vector<int> tileset1_grounds = {103, 104, 105};
    vector<int> tileset1_ladders = {2, 14};
    vector<sf::Vector2i> map1_1_walls = untraversablesTileset1(map1_1, tileset1_walls);
    vector<sf::Vector2i> map1_1_grounds = untraversablesTileset1(map1_1, tileset1_grounds);
    vector<sf::Vector2i> map1_1_ladders = untraversablesTileset1(map1_1, tileset1_ladders);
    std::map<std::pair<int, int>, int> map1_2 = getMap(path + "resources/maps/map1_2.csv");


    while(window.isOpen()){

        sf::Event event{};
        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed){
                if(display_key == 0)
                    homeEvents(event, display_key, shapes_clock);
                else if(display_key == 2)
                    menuEvents(event, display_key, difficulty_value, menu_clic_position, player.clock);
            }
        }

        window.clear();

        switch(display_key){
            case 0:
                home(window, home_alpha_value, home_clock);
                break;

            case 1:
                shapesDemo(window, shapes_clock, display_key);
                break;

            case 2:
                menu(window, menu_clic_position, difficulty_value);
                break;

            case 10:
                ///////////////////////////////////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////////////////////////////////
                window.setView(window.getDefaultView());
                background(window, path + "resources/Sprites/game/background-back-city.png");

                setPlayerView(player_view, screen_size, player.pos);

                window.setView(player_view);
                environment(window, map1_1);
                environment(window, map1_2);
                gameEvents(player);
                playerCollisions(player, map1_1_walls, map1_1_grounds, map1_1_ladders);
                playerDisplay(window, player);
                playerIsAlive(player.health);
                ///////////////////////////////////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////////////////////////////////
                break;

            default:
                cerr << "Error, invalid display key (" << display_key << ")" << endl;
        }

        window.display();
    }

    cout << "Fermeture du jeu" << endl;
    return EXIT_SUCCESS;
}
