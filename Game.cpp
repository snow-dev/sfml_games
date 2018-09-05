//
// Created by kharl on 9/4/18.
//

#include "includes/Game.h"

namespace game {

    Game::Game() : _window(sf::VideoMode(640, 480), "SFML App"), _player() {
        _player.setRadius(40.f);
        _player.setPosition(100.f, 100.f);
        _player.setFillColor(sf::Color::Cyan);
    }

    void Game::run() {
        sf::Clock clock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
        while (_window.isOpen()){
            processEvents();
            timeSinceLastUpdate += clock.restart();
            while (timeSinceLastUpdate > TimePerFrame){
                timeSinceLastUpdate -= TimePerFrame;
                processEvents();
                update(TimePerFrame);
            }
            render();
        }

    }

    void Game::processEvents() {
        sf::Event event;
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
}
