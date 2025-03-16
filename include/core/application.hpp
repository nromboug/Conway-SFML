#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "game/cell.hpp"

class Application {
    private:
    sf::RenderWindow window;

    public:
    Application();
    void run();

};

#endif