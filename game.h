#pragma once
#include "grid.h"
#include "Blocks.cpp"

class Game {
    public: 
        Game();
        Block getRandomBlock();
        Grid grid;
        void getAllBlocks(int[], int);
        void draw(WINDOW * win);
        void handleInput(WINDOW * win);
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();

    private:
        int blocks[7];
        Block currentBlock;
        Block nextBlock;
        bool isBlockOutside();
        void rotateBlock();
        void lockBlock();
        bool blockFits();
};