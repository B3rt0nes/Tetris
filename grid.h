#pragma once

class Grid {
    private:
        int numRow;
        int numCol;
    public:
        Grid();
        char grid[42][42];
        void initGrid();
        void printGrid(WINDOW * win);
};