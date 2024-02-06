#include <ncurses.h>
#include "grid.h"
    

Grid::Grid(){
    numCol = 21;
    numRow = 21;
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
    
    for(int row = 1; row < numRow; row++){      // 0 e 34 sono i bordi
        for(int col = 1; col < numCol; col++){  // 0 e 34 sono i bordi
            if (grid[row][col] == '1') {
                wattron(win, COLOR_PAIR(1));
                mvwprintw(win, row, col, "%c", grid[row][col]);
                wattroff(win, COLOR_PAIR(1));
            } else if (grid[row][col] == '2') {
                    wattron(win, COLOR_PAIR(2));
                    mvwprintw(win, row, col, "%c", grid[row][col]);
                    wattroff(win, COLOR_PAIR(2));
            } else if (grid[row][col] == '3') {
                    wattron(win, COLOR_PAIR(3));
                    mvwprintw(win, row, col, "%c", grid[row][col]);
                    wattroff(win, COLOR_PAIR(3));
            } else if (grid[row][col] == '4') {
                    wattron(win, COLOR_PAIR(4));
                    mvwprintw(win, row, col, "%c", grid[row][col]);
                    wattroff(win, COLOR_PAIR(4));
            } else if (grid[row][col] == '5') { 
                    wattron(win, COLOR_PAIR(5));
                    mvwprintw(win, row, col, "%c", grid[row][col]);
                    wattroff(win, COLOR_PAIR(5));
            } else if (grid[row][col] == '6') {
                    wattron(win, COLOR_PAIR(6));
                    mvwprintw(win, row, col, "%c", grid[row][col]);
                    wattroff(win, COLOR_PAIR(6));
            } else if (grid[row][col] == '7') {
                    wattron(win, COLOR_PAIR(7));
                    mvwprintw(win, row, col, "%c", grid[row][col]);
                    wattroff(win, COLOR_PAIR(7));
            } else if (grid[row][col] == '/') {
                    wattron(win, COLOR_PAIR(8));
                    mvwprintw(win, row, col, "%c", grid[row][col]);
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