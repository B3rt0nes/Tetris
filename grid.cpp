#include "grid.hpp"


Grid::Grid()
{
    numCol = 20;
    numRow = 20;
    score = 0;
    lines = 0;
    initGrid();
}

void Grid::initGrid(){
    for(int row = 0; row < numRow; row++){
        for(int col = 0; col < numCol; col++){
            grid[row][col] = '1';
        }
    }
}

void Grid::printGrid(WINDOW * win){
    box(win, 0, 0);
    wborder(win, '|', '|', '-', '-', '+', '+', '+', '+'); // set the border
    
    for(int row = 0; row <= numRow; row++){
        for(int col = 0; col <= numCol; col++){
            if (grid[row][col] == '1') {
                wattron(win, COLOR_PAIR(1));
                mvwprintw(win, row+1, col+1, "%c", grid[row][col]);
                wattroff(win, COLOR_PAIR(1));
            } else if (grid[row][col] == '2') {
                wattron(win, COLOR_PAIR(2));
                mvwprintw(win, row+1, col+1, "%c", grid[row][col]);
                wattroff(win, COLOR_PAIR(2));
            } else if (grid[row][col] == '3') {
                wattron(win, COLOR_PAIR(3));
                mvwprintw(win, row+1, col+1, "%c", grid[row][col]);
                wattroff(win, COLOR_PAIR(3));
            } else if (grid[row][col] == '4') {
                wattron(win, COLOR_PAIR(4));
                mvwprintw(win, row+1, col+1, "%c", grid[row][col]);
                wattroff(win, COLOR_PAIR(4));
            } else if (grid[row][col] == '5') { 
                wattron(win, COLOR_PAIR(5));
                mvwprintw(win, row+1, col+1, "%c", grid[row][col]);
                wattroff(win, COLOR_PAIR(5));
            } else if (grid[row][col] == '6') {
                wattron(win, COLOR_PAIR(6));
                mvwprintw(win, row+1, col+1, "%c", grid[row][col]);
                wattroff(win, COLOR_PAIR(6));
            } else if (grid[row][col] == '7') {
                wattron(win, COLOR_PAIR(7));
                mvwprintw(win, row+1, col+1, "%c", grid[row][col]);
                wattroff(win, COLOR_PAIR(7));
            } else if (grid[row][col] == '/') {
                wattron(win, COLOR_PAIR(8));
                mvwprintw(win, row+1, col+1, "%c", grid[row][col]);
                wattroff(win, COLOR_PAIR(8));
            }
            /*  COLORI DA IMPLEMENTARE
             * 1 -> Background   (nero)
             * 2 -> I            (ciano)
             * 3 -> Z            (rosso)
             * 4 -> S            (verde)
             * 5 -> J            (blu)
             * 6 -> T            (magenta)
             * 7 -> O            (giallo)
             * 8 -> L            (bianco)
             */
        }
    }
    wrefresh(win);
}

bool Grid::isCellOutside(int row, int column) {
    if (row >= 0 && row < numRow && column >= 0 && column < numCol) {
        return false;
    }
    return true;
}

bool Grid::isCellEmpty(int row, int column) {
    if (grid[row][column] == '1') {
        return false;
    }
    return true;
}

int Grid::clearFullRows() {
    int completed = 0;
    for (int row = numRow-1; row >= 0; row--) {
        if (isRowFull(row)) {
            deleteRow(row);
            completed++; 
        } else if (completed > 0) {
            if (completed >= 4) {
                score += 10;
            }
            moveRowsDown(row, completed);
        }
    }
    return completed;
}

bool Grid::isRowFull(int row) {
    for (int col = 0; col < numCol; col++) {
        if (grid[row][col] == '1') {
            return false;
        }
    }
    score += 10;
    lines++;
    return true;
}

void Grid::deleteRow(int row) {
    for (int col = 0; col < numCol; col++) {
        grid[row][col] = '1';
    }
}

void Grid::moveRowsDown(int row, int numRow) {
    for (int col = 0; col < numCol; col++) {
        grid[row + numRow][col] = grid[row][col];
        grid[row][col] = '1';
    }
}
