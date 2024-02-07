#pragma once
#include "grid.hpp"
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
        void Reset();
        bool isGameOver();

        bool gameOver;
        Block nextBlock;

    private:
        int blocks[7];
        Block currentBlock;
        bool isBlockOutside();
        void rotateBlock();
        void lockBlock();
        bool blockFits();
};