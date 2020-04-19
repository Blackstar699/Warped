cmake_minimum_required(VERSION 3.10)
project(Warped)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(Warped main.cpp fonctions.h fonctions.cpp menus.cpp menus.h includes.h events.cpp events.h player.cpp player.h CSVReader.cpp CSVReader.hpp environment.cpp environment.h game.cpp game.h)
target_link_libraries(Warped ${CONAN_LIBS})