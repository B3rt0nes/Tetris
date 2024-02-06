#pragma once
// #include "grid.cpp"
// #include "Blocks.cpp"
#include "block.h"

class Game {
    public: 
        Game();
        // Block getRandomBlock();
        // Grid grid;
        void getAllBlocks();
        // void draw();
    private:
        int blocks[7];
        // Block currentBlock;
        // Block nextBlock;
};