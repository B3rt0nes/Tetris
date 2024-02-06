#pragma once

class Grid {
    private:
        int numRow;
        int numCol;
    public:
        char grid[22][22];
        
        Grid();
        void initGrid();
        void printGrid(WINDOW * win);
};