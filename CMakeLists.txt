cmake_minimum_required(VERSION 3.10)
project(Warped)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(Warped main.cpp fonctions/fonctions.h fonctions/fonctions.cpp fonctions/menus.cpp fonctions/menus.h includes.h fonctions/events.cpp fonctions/events.h game/player.cpp game/player.h fonctions/CSVReader.cpp fonctions/CSVReader.hpp game/environment.cpp game/environment.h game/game.cpp game/game.h shoots/PlayerShoots.cpp shoots/PlayerShoots.h ennemies/Turrets.cpp ennemies/Turrets.h ennemies/ennemies.cpp ennemies/ennemies.h fonctions/fonctions.h shoots/TurretsShoots.cpp shoots/TurretsShoots.h shoots/Shoots.cpp shoots/Shoots.h ennemies/Drones.cpp ennemies/Drones.h)
target_link_libraries(Warped ${CONAN_LIBS})