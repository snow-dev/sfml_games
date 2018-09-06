//
// Created by kharl on 9/4/18.
//

#include "includes/Game.h"
#include "includes/StringHelper.h"


namespace game {

    const float Game::PlayerSpeed = 100.f;
    const  sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

    Game::Game() : _window(sf::VideoMode(640, 480), "SFML App", sf::Style::Close),
    _player(),
    _texture(),
    _statisticsText(),
    _font(),
    _statisticsUpdateTime(),
    _statisticsNumFrames(0),
    _isMovingRight(false),
    _isMovingLeft(false),
    _isMovingUp(false),
    _isMovingDown(false)
    {
        if (!_texture.loadFromFile("../Media/Textures/Eagle.png")){
            // Handle loading error.
        }
        _player.setTexture(_texture);
        _player.setPosition(100.f, 100.f);

        _font.loadFromFile("../Media/Sansation.ttf");
        _statisticsText.setFont(_font);
        _statisticsText.setPosition(5.f, 5.f);
        _statisticsText.setCharacterSize(10);
    }

    void Game::run() {
        sf::Clock clock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
        while (_window.isOpen()){
            processEvents();
            sf::Time elapsedTime = clock.restart();
            timeSinceLastUpdate += elapsedTime;

            while (timeSinceLastUpdate > TimePerFrame){
                timeSinceLastUpdate -= TimePerFrame;
                processEvents();
                update(TimePerFrame);
            }
            updateStatistics(elapsedTime);
            render();
        }

    }

    void Game::processEvents() {
        sf::Event event{};
        while (_window.pollEvent(event)){
            switch (event.type){
                case sf::Event::KeyPressed:
                    handlePlayerInput(event.key.code, true);
                    break;
                case sf::Event::KeyReleased:
                    handlePlayerInput(event.key.code, false);
                    break;
                case sf::Event::Closed:
                    _window.close();
                    break;
            }
        }
    }

    void Game::update(sf::Time deltaTime) {
        sf::Vector2f movement(0.f, 0.f);
        if(_isMovingUp)
            movement.y -= PlayerSpeed;
        if(_isMovingDown)
            movement.y += PlayerSpeed;
        if(_isMovingLeft)
            movement.x -= PlayerSpeed;
        if(_isMovingRight)
            movement.x += PlayerSpeed;

        _player.move(movement * deltaTime.asSeconds());
    }

    void Game::render() {
        _window.clear();
        _window.draw(_player);
        _window.draw(_statisticsText);
        _window.display();
    }

    void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
        if(key == sf::Keyboard::W){
            _isMovingUp = isPressed;
        }
        else if (key == sf::Keyboard::S)
            _isMovingDown = isPressed;
        else if (key == sf::Keyboard::A)
            _isMovingLeft = isPressed;
        else if (key == sf::Keyboard::D)
            _isMovingRight = isPressed;
    }

    void Game::updateStatistics(sf::Time elapsedTime) {
        _statisticsUpdateTime += elapsedTime;
        _statisticsNumFrames += 1;

        if(_statisticsUpdateTime >= sf::seconds(1.0f)){
            _statisticsText.setString("Frames / Seconds =" + toString(_statisticsNumFrames) + "\n" +
            "Time / Update = " + toString(_statisticsUpdateTime.asMicroseconds() / _statisticsNumFrames) + "us" );
            _statisticsUpdateTime -= sf::seconds(1.0f);
            _statisticsNumFrames = 0;
        }

    }
}
