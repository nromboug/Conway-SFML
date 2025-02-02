#include <stdexcept>
#include <sstream>
#include <random>
#include <numeric>

#include "game/grid.hpp"

Grid::Grid(int n_rows, int n_cols) : n_r(n_rows + 2), n_c(n_cols + 2), grid((n_rows + 2) * (n_cols + 2), Cell(false)) {}

void Grid::calcNextGen() {
    for (int r = 1; r < n_r-1; r++) {
        for (int c = 1; c < n_c-1; c++) {
            updateState(r, c);
        }
    }
}

Cell& Grid::get(int row, int col)
{
    if (row >= n_r-1 || col >= n_c-1 || row < 1 || col < 1)
    {
        throw std::out_of_range("Selections were outside of grid range.");
    }
    return grid[arrayAccessor(row, col)];
}

int Grid::arrayAccessor(int row, int col) {
    return n_c*row + col;
}

void Grid::updateState(int row, int col) {

    Cell& cell = grid[arrayAccessor(row, col)];

    std::vector<Cell> neighbors{
        grid[arrayAccessor(row-1, col-1)],
        grid[arrayAccessor(row, col-1)],
        grid[arrayAccessor(row+1, col-1)],
        grid[arrayAccessor(row-1, col)],
        grid[arrayAccessor(row+1, col)],
        grid[arrayAccessor(row-1, col+1)],
        grid[arrayAccessor(row, col+1)],
        grid[arrayAccessor(row+1, col+1)]
    };

    int n_aliveNeighbors = std::accumulate(
        neighbors.begin(), 
        neighbors.end(), 
        0, 
        [](int& sum, Cell& curr) {
            return sum + (curr.isAlive() ? 1 : 0);
        });

    if (cell.isAlive() && (n_aliveNeighbors > 3 || n_aliveNeighbors < 2)) {
        cell.setNextAlive(false);
    } else if (!cell.isAlive() && n_aliveNeighbors == 3) {
        cell.setNextAlive(true);
    }
}

void Grid::update()
{
    calcNextGen();
    for (int i = 1; i < grid.size(); i++)
    {
            grid[i].update();
    }
}

void Grid::initialize(double percent_alive)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    for (int i = 1; i < grid.size(); i++)
    {
        if (i % n_c != 0 && i % n_c != n_c - 1 && dist(generator) < percent_alive)
        {
            grid[i].setNextAlive(true);
            grid[i].update();
        }
    }
}

std::string Grid::toString() {
    std::stringstream ss;
    for (auto it : grid) {
        ss << it.isAlive() << ", ";
    }
    return ss.str();
}