#include <ncurses.h>
#pragma once

struct coordinate{
    int x;
    int y;
};


struct position{
    coordinate pos[8];
};


class Block {
    private:
        int rotationState;
        int rowOffset;  
        int colOffset;
    public:
        Block();
        int id;
        position cells[4];
        void Draw(WINDOW *, int);
        void move(int, int);
        position getPos();
};