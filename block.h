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
        
    public:
        Block();
        int id;
        position cells[4];
        void Draw(WINDOW *, int);
};