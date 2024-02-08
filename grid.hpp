#pragma once
#include <ncurses.h>

class Grid {
    public:
        Grid();
        void initGrid();
        void printGrid(WINDOW * win);
        bool isCellOutside(int row, int column);
        bool isCellEmpty(int row, int column);
        int clearFullRows();

        char grid[20][20];
        int score;
        int lines;
        
    private:
        bool isRowFull(int row);
        void deleteRow(int row);
        void moveRowsDown(int row, int numRow);

        int numRow;
        int numCol;
};