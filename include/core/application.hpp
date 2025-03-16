#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "game/cell.hpp"
#include "game/game.hpp"

class Application {
    private:
    sf::RenderWindow window;
    Game game;

    public:
    Application();
    void run();

};

#endif