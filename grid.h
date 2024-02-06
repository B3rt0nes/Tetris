#pragma once
#include <ncurses.h>

class Grid {
    private:
        bool isRowFull(int row);
        void deleteRow(int row);
        void moveRowsDown(int row, int numRow);

        int numRow;
        int numCol;
    public:
        Grid();
        void initGrid();
        void printGrid(WINDOW * win);
        bool isCellOutside(int row, int column);
        bool isCellEmpty(int row, int column);
        int clearFullRows();

        char grid[22][22];
};