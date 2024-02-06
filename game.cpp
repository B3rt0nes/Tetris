#include "game.h"
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

Game::Game() {
    grid = Grid();
    for (int i = 0; i < 7; i++) {
        blocks[i] = i + 2;
    }
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
}

Block Game::getRandomBlock() {
    
    if (blocks[0] == 0 && blocks[1] == 0 && 
        blocks[2] == 0 && blocks[3] == 0 && 
        blocks[4] == 0 && blocks[5] == 0 && 
        blocks[6] == 0) {
        getAllBlocks(blocks, 7);
    }
    srand(time(0));
    int randomIndex = (rand() % 7); // 0 - 6
    Block block;
    
    
    switch (randomIndex) {
        case 0:
            block = IBloc();
            break;
        case 1:
            block = ZBloc();
            break;
        case 2:
            block = SBloc();
            break;
        case 3:
            block = JBloc();
            break;
        case 4:
            block = TBloc();
            break;
        case 5:
            block = OBloc();
            break;
        case 6:
            block = LBloc();
            break;
        default:
            break;
    }
    blocks[randomIndex] = 0;

    return block;
}

void Game::getAllBlocks(int blocks[], int size) {
    for (int i = 0; i < size; i++) {
        blocks[i] = i + 2;
    }
}

void Game::draw(WINDOW * win) {
    grid.printGrid(win);
    currentBlock.Draw(win, 0);
}

void Game::handleInput(WINDOW * gamewin) {
    int keyPressed = wgetch(gamewin);
    switch (keyPressed) {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_DOWN:
        MoveBlockDown();
        break;
    // case KEY_UP:
        
    //     break;
    
    default:
        break;
    }
}

void Game::MoveBlockLeft() {
    currentBlock.move(0, -2);
    if (isBlockOutside()) {
        currentBlock.move(0, 2);
    }
}

void Game::MoveBlockRight() {
    currentBlock.move(0, 2);
    if (isBlockOutside()) {
        currentBlock.move(0, -2);
    }
}

void Game::MoveBlockDown() {
    currentBlock.move(1, 0);
    if (isBlockOutside()) {
        currentBlock.move(-1, 0);
    }
}

bool Game::isBlockOutside() {
    // std::vector<position> tiles = currentBlock.getPos();
    position tiles = currentBlock.getPos();
    for (int i = 0; i < 8; i++) {
        if (grid.isCellOutside(tiles.pos[i].x, tiles.pos[i].y)) {
            return true;
        }
    }
    return false;
}