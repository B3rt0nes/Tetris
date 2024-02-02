#include "block.h"

Block::Block(){
    id = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cells[i].pos[j].x = 0;
            cells[i].pos[j].y = 0;
        }
    }
}

void Block::Draw(WINDOW * win, int rotationState){
    
    for (int row = 0; row < 8 ; row++){
        if (id == 1) {
            wattron(win, COLOR_PAIR(1));
            mvwaddch(win, cells[rotationState].pos[row].x + 1, cells[rotationState].pos[row].y + 1, '1');
            wattroff(win, COLOR_PAIR(1));
        } else if (id == 2) {
            wattron(win, COLOR_PAIR(2));
            mvwaddch(win, cells[rotationState].pos[row].x + 1, cells[rotationState].pos[row].y + 1, '2');
            wattroff(win, COLOR_PAIR(2));
        } else if (id == 3) {
            wattron(win, COLOR_PAIR(3));
            mvwaddch(win, cells[rotationState].pos[row].x + 1, cells[rotationState].pos[row].y + 1, '3');
            wattroff(win, COLOR_PAIR(3));
        } else if (id == 4) {
            wattron(win, COLOR_PAIR(4));
            mvwaddch(win, cells[rotationState].pos[row].x + 1, cells[rotationState].pos[row].y + 1, '4');
            wattroff(win, COLOR_PAIR(4));
        } else if (id == 5) {
            wattron(win, COLOR_PAIR(5));
            mvwaddch(win, cells[rotationState].pos[row].x + 1, cells[rotationState].pos[row].y + 1, '5');
            wattroff(win, COLOR_PAIR(5));
        } else if (id == 6) {
            wattron(win, COLOR_PAIR(6));
            mvwaddch(win, cells[rotationState].pos[row].x + 1, cells[rotationState].pos[row].y + 1, '6');
            wattroff(win, COLOR_PAIR(6));
        } else if (id == 7) {
            wattron(win, COLOR_PAIR(7));
            mvwaddch(win, cells[rotationState].pos[row].x + 1, cells[rotationState].pos[row].y + 1, '7');
            wattroff(win, COLOR_PAIR(7));
        } else if (id == 8) {
            wattron(win, COLOR_PAIR(8));
            mvwaddch(win, cells[rotationState].pos[row].x + 1, cells[rotationState].pos[row].y + 1, '8');
            wattroff(win, COLOR_PAIR(8));
        }

    }
    

}