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
        void updateStatistics(sf::Time elapsedTime);
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

        static const float PlayerSpeed;
        static const sf::Time TimePerFrame;

        sf::RenderWindow _window;
        sf::Texture _texture;
        sf::Sprite _player;
        sf::Text _statisticsText;
        sf::Font _font;
        sf::Time _statisticsUpdateTime;

        std::size_t _statisticsNumFrames;
        bool _isMovingUp;
        bool _isMovingDown;
        bool _isMovingLeft;
        bool _isMovingRight;
    };

}


#endif //GAME_GAME_H
