#include "Game/Grid.hpp"
#include <iostream>

int main() {
    Grid grid{3, 3};

    grid.get(1, 1).setNextAlive(true);
    grid.get(1, 1).update();

    grid.get(2, 2).setNextAlive(true);
    grid.get(2, 2).update();

    grid.get(3, 3).setNextAlive(true);
    grid.get(3, 3).update();


    grid.get(1, 3).setNextAlive(true);
    grid.get(1, 3).update();

    std::string before{"0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "};
    if(grid.toString() != before)
        return 1;

    grid.update();

    std::string after{"0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "};

    std::cout << grid.toString();
    if (grid.toString() != after)
        return 1;

    return 0;
}   