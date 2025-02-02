#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>

#include "grid.hpp"

class Game {
    public:
    void update(sf::RenderWindow& window);
    Grid gameboard;

    private:

};

#endif