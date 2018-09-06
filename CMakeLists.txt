cmake_minimum_required(VERSION 3.12)
project(game)

set(CMAKE_CXX_STANDARD 11)
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(game main.cpp Game.cpp includes/Game.h StringHelper.cpp includes/StringHelper.h)
target_link_libraries(game sfml-graphics sfml-system sfml-window)