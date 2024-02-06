#include "block.h"

Block::Block(){
    id = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cells[i].pos[j].x = 0;
            cells[i].pos[j].y = 0;
        }
    }
    rotationState = 0;
    rowOffset = 0;
    colOffset = 0;
}

void Block::Draw(WINDOW * win, int rotationState){
    position tiles = getPos();
    
    for (int row = 0; row < 8 ; row++){
        wattron(win, COLOR_PAIR(id));
        switch(id) {
            case 1:
                mvwaddch(win, tiles.pos[row].x + 1, tiles.pos[row].y + 1, '1');
                break;
            case 2:
                mvwaddch(win, tiles.pos[row].x + 1, tiles.pos[row].y + 1, '2');
                break;
            case 3:
                mvwaddch(win, tiles.pos[row].x + 1, tiles.pos[row].y + 1, '3');
                break;
            case 4:
                mvwaddch(win, tiles.pos[row].x + 1, tiles.pos[row].y + 1, '4');
                break;
            case 5:
                mvwaddch(win, tiles.pos[row].x + 1, tiles.pos[row].y + 1, '5');
                break;
            case 6:
                mvwaddch(win, tiles.pos[row].x + 1, tiles.pos[row].y + 1, '6');
                break;
            case 7:
                mvwaddch(win, tiles.pos[row].x + 1, tiles.pos[row].y + 1, '7');
                break;
            case 8:
                mvwaddch(win, tiles.pos[row].x + 1, tiles.pos[row].y + 1, '8');
                break;
        }
        wattroff(win, COLOR_PAIR(id));
    }
}

void Block::move(int row, int col){
    rowOffset += row;
    colOffset += col;
}

void Block::rotate() {
    rotationState++;
    if (rotationState > 3){
        rotationState = 0;
    }
}

void Block::undoRotation() {
    rotationState--;
    if (rotationState < 0){
        rotationState = 3;
    }
}

position Block::getPos(){
    position current = cells[rotationState];
    position moved;
    for (int i = 0; i < 8; i++){
        moved.pos[i].x = current.pos[i].x + rowOffset;
        moved.pos[i].y = current.pos[i].y + colOffset;
    }
    return moved;
}