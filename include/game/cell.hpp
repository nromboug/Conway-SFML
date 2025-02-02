#ifndef CELL_HPP
#define CELL_HPP

class Cell {
    private:
    bool alive;
    bool nextAlive;

    public:
    bool isAlive();
    void setNextAlive(bool val);
    Cell(bool alive);
    void update();
};

#endif