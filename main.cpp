#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "core/application.hpp"
#include "game/cell.hpp"

int main()
{
    Application app;
    app.run();

    std::vector vec{Cell(true), Cell(true), Cell(true)};
    
    for (auto it : vec)
        std::cout << it.isAlive() << std::endl;

    std::cout << std::endl;

    Cell& cell = vec[1];
    cell.setNextAlive(false);
    cell.update();

    for (auto it : vec)
        std::cout << it.isAlive() << std::endl;

    return 0;
}