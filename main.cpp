#include "includes.h"
#include "fonctions/events.h"
#include "fonctions/menus.h"
#include "game/environment.h"
#include "game/player.h"
#include "ennemies/ennemies.h"


int main(){
    sf::err().rdbuf(nullptr);
    cout << "Lancement du jeu" << endl;

    //set fenetre
    const sf::Vector2i screen_size(1200, 700);
    sf::RenderWindow window(sf::VideoMode(screen_size.x, screen_size.y), "Warped - The Game", sf::Style::Close);
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(360, 190));

    //set global
    string path = "../../resources/";
    int display_key = 0;  //définit la partie du jeu qui doit être affichée: 0 = accueil, 1 = menu principal, 10 = jeu, 11 = gameover
    int difficulty_value = 2;

    //set home/menu
    int home_alpha_value = 1;
    sf::Clock home_clock;
    sf::Clock shapes_clock;
    int menu_clic_position = 1;

    //set game
    sf::View player_view;
    Player player;
    vector<PlayerShoots> player_shoots;
    vector<Turrets> turrets;
    std::map<std::pair<int, int>, int> map1_turrets = getMap(path + "maps/map1_turrets.csv");
    vector<TurretsShoots> turrets_shoots;
    vector<Drones> drones;
    std::map<std::pair<int, int>, int> map1_drones = getMap(path + "maps/map1_drones.csv");
//    vector<DronesShoots> drones_shoots;
    std::map<std::pair<int, int>, int> map1_1 = getMap(path + "maps/map1_1.csv");
    vector<int> tileset1_walls = {25, 31, 32, 37, 43, 44, 49, 55, 56, 67, 68};
    vector<int> tileset1_grounds = {103, 104, 105};
    vector<int> tileset1_ladders = {2, 14};
    vector<sf::Vector2i> map1_1_walls = untraversablesTileset1(map1_1, tileset1_walls);
    vector<sf::Vector2i> map1_1_grounds = untraversablesTileset1(map1_1, tileset1_grounds);
    vector<sf::Vector2i> map1_1_ladders = untraversablesTileset1(map1_1, tileset1_ladders);
    std::map<std::pair<int, int>, int> map1_2 = getMap(path + "maps/map1_2.csv");
    vector<sf::Texture> textures;
    vector<string> files = {
            "Sprites/home/background.png",
            "Sprites/home/press-enter.png",
            "Sprites/menu/background.png",
            "Sprites/menu/play.png",
            "Sprites/menu/difficulty.png",
            "Sprites/menu/difficulties.png",
            "Sprites/game/background-back-city.png",
            "Sprites/game/tileset1.png",
            "Sprites/game/player.png",
            "Sprites/game/player_shoot.png",
            "Sprites/game/player_shoot_impact.png",
            "Sprites/game/enemy-explosion.png",
            "Sprites/game/turret.png",
            "Sprites/game/turret_shoot.png",
            "Sprites/game/turret_shoot_impact.png",
            "Sprites/game/drone.png"
    };

    for(const auto& file : files){
        sf::Texture texture = loadTexture(path + file);
        textures.push_back(texture);
    }


    while(window.isOpen()){

        sf::Event event{};
        while(window.pollEvent(event)){

            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed){
                if(display_key == 0)
                    homeEvents(event, display_key, shapes_clock);
                else if(display_key == 1)
                    menuEvents(event, display_key, difficulty_value, menu_clic_position, player, map1_turrets, turrets, map1_drones, drones);
            }
        }

        window.clear();
        switch(display_key){
            case 0:
                home(window, home_alpha_value, home_clock, textures[0], textures[1]);
                break;

            case 1:
                menu(window, menu_clic_position, difficulty_value, textures[2], textures[3], textures[4], textures[5]);
                break;

            case 10:
                ///////////////////////////////////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////////////////////////////////
                background(window, textures[6]);

                setPlayerView(player_view, screen_size, player.pos);

                window.setView(player_view);
                environment(window, map1_1, player.pos, textures[7]);
                environment(window, map1_2, player.pos, textures[7]);
                gameEvents(player, player_shoots);
                playerCollisions(player, map1_1_walls, map1_1_grounds, map1_1_ladders);
                ///props (powerup, pièces, ...)
                turretsDisplay(window, turrets, player, textures[12], textures[11]);
                dronesDisplay(window, drones, player, textures[15], textures[11]);
                ///Ennemis
                playerDisplay(window, player, textures[8]);
                turretsShoots(player, turrets, turrets_shoots);
                turretsShootsDisplay(window, turrets_shoots, player, map1_1_walls, textures[13], textures[14]);
                ///tirs ennemis
                playerShootsDisplay(window, player_shoots, player, map1_1_walls, textures[9], textures[10], turrets);
                window.setView(window.getDefaultView());
                playerHUD(window, player);
                playerIsAlive(player.health, display_key);
                ///////////////////////////////////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////////////////////////////////
                break;

            case 11:
                gameOverScreen(window, display_key);
                break;

            default:
                cerr << "Error, invalid display key (" << display_key << ")" << endl;
        }

        window.display();
    }

    cout << "Fermeture du jeu" << endl;
    return EXIT_SUCCESS;
}
