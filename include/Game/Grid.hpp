#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <string>
#include "Game/Cell.hpp"
#include "Core/Config.hpp"

class Grid {
    private:
        int n_r;
        int n_c;
        std::vector<Cell> grid;
        
        void updateState(int row, int col);
        int arrayAccessor(int row, int col);
        void calcNextGen();

    public:
        Grid(int n_rows, int n_cols);
        Cell& get(int row, int col);
        void initialize(double percent_alive);
        void update();
        std::string toString();
};

#endif