#include "game.h"
#include "block.h"
// #include "Blocks.cpp"



// #include <cstdlib>
// #include <ctime>

Game::Game() {
    // grid = Grid();
    for (int i = 0; i < 7; i++) {
        blocks[i] = i + 2;
    }
    // currentBlock = IBloc();
    // nextBlock = getRandomBlock();
}

// Block Game::getRandomBlock() {
//     if (blocks[0] == 0 && blocks[1] == 0 && 
//         blocks[2] == 0 && blocks[3] == 0 && 
//         blocks[4] == 0 && blocks[5] == 0 && 
//         blocks[6] == 0) {
//         getAllBlocks();
//     }
//     srand(time(0));
//     int randomIndex = (rand() % 7); // 0 - 6
    
    
    
//     switch (randomIndex) {
//         case 0:
//             block = IBloc();
//             break;
//         case 1:
//             block = ZBloc();
//             break;
//         case 2:
//             block = SBloc();
//             break;
//         case 3:
//             block = JBloc();
//             break;
//         case 4:
//             block = TBloc();
//             break;
//         case 5:
//             block = OBloc();
//             break;
//         case 6:
//             block = LBloc();
//             break;
//         default:
//             break;
//     }
//     blocks[randomIndex] = 0;

//     return block;
// }

void Game::getAllBlocks() {
    for (int i = 0; i < 7; i++) {
        blocks[i] = i + 2;
    }
}

// void Game::draw() {
//     grid.printGrid();
//     currentBlock.Draw();
// }