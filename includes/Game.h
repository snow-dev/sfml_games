//
// Created by kharl on 9/4/18.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SFML/Window.hpp>
#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>

namespace game {
    class Game {
    public:
        Game();
        void run();

    private:
        void processEvents();
        void update(sf::Time deltaTime);
        void render();
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

        sf::RenderWindow _window;
        sf::CircleShape _player;
        int PlayerSpeed = 60;
        sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

        bool _isMovingUp;
        bool _isMovingDown;
        bool _isMovingLeft;
        bool _isMovingRight;
    };

}


#endif //GAME_GAME_H
