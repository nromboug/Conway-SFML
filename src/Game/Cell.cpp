#include "Game/Cell.hpp"

Cell::Cell(bool alive) : alive(alive), nextAlive(false) {}

void Cell::update()
{
    alive = nextAlive;
}

bool Cell::isAlive() { return alive; };

void Cell::setNextAlive(bool val) {
    nextAlive = val;
}