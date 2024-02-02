#include "block.h"

/*  * 2 -> I            (ciano)
    * 3 -> Z            (rosso)
    * 4 -> S            (verde)
    * 5 -> J            (blu)
    * 6 -> T            (magenta)
    * 7 -> O            (giallo)
    * 8 -> L            (bianco)*/



class IBloc : public Block {
    public:
        IBloc(){
            id = 2;

            cells[0].pos[0].x = 1;
            cells[0].pos[0].y = 0;
            cells[0].pos[1].x = 1;
            cells[0].pos[1].y = 1;
            cells[0].pos[2].x = 1;
            cells[0].pos[2].y = 2;
            cells[0].pos[3].x = 1;
            cells[0].pos[3].y = 3;
            cells[0].pos[4].x = 1;
            cells[0].pos[4].y = 4;
            cells[0].pos[5].x = 1;
            cells[0].pos[5].y = 5;
            cells[0].pos[6].x = 1;
            cells[0].pos[6].y = 6;
            cells[0].pos[7].x = 1;
            cells[0].pos[7].y = 7;

            cells[1].pos[0].x = 0;
            cells[1].pos[0].y = 4;
            cells[1].pos[1].x = 0;
            cells[1].pos[1].y = 5;
            cells[1].pos[2].x = 1;
            cells[1].pos[2].y = 4;
            cells[1].pos[3].x = 1;
            cells[1].pos[3].y = 5;
            cells[1].pos[4].x = 2;
            cells[1].pos[4].y = 4;
            cells[1].pos[5].x = 2;
            cells[1].pos[5].y = 5;
            cells[1].pos[6].x = 3;
            cells[1].pos[6].y = 4;
            cells[1].pos[7].x = 3;
            cells[1].pos[7].y = 5;

            cells[2].pos[0].x = 2;
            cells[2].pos[0].y = 0;
            cells[2].pos[1].x = 2;
            cells[2].pos[1].y = 1;
            cells[2].pos[2].x = 2;
            cells[2].pos[2].y = 2;
            cells[2].pos[3].x = 2;
            cells[2].pos[3].y = 3;
            cells[2].pos[4].x = 2;
            cells[2].pos[4].y = 4;
            cells[2].pos[5].x = 2;
            cells[2].pos[5].y = 5;
            cells[2].pos[6].x = 2;
            cells[2].pos[6].y = 6;
            cells[2].pos[7].x = 2;
            cells[2].pos[7].y = 7;

            cells[3].pos[0].x = 0;
            cells[3].pos[0].y = 2;
            cells[3].pos[1].x = 0;
            cells[3].pos[1].y = 3;
            cells[3].pos[2].x = 1;
            cells[3].pos[2].y = 2;
            cells[3].pos[3].x = 1;
            cells[3].pos[3].y = 3;
            cells[3].pos[4].x = 2;
            cells[3].pos[4].y = 2;
            cells[3].pos[5].x = 2;
            cells[3].pos[5].y = 3;
            cells[3].pos[6].x = 3;
            cells[3].pos[6].y = 2;
            cells[3].pos[7].x = 3;
            cells[3].pos[7].y = 3;
        }
};

class ZBloc : public Block {
    public:
        ZBloc(){
            id = 3;

            cells[0].pos[0].x = 0;
            cells[0].pos[0].y = 0;
            cells[0].pos[1].x = 0;
            cells[0].pos[1].y = 1;
            cells[0].pos[2].x = 0;
            cells[0].pos[2].y = 2;
            cells[0].pos[3].x = 0;
            cells[0].pos[3].y = 3;
            cells[0].pos[4].x = 1;
            cells[0].pos[4].y = 2;
            cells[0].pos[5].x = 1;
            cells[0].pos[5].y = 3;
            cells[0].pos[6].x = 1;
            cells[0].pos[6].y = 4;
            cells[0].pos[7].x = 1;
            cells[0].pos[7].y = 5;

            cells[1].pos[0].x = 0;
            cells[1].pos[0].y = 4;
            cells[1].pos[1].x = 0;
            cells[1].pos[1].y = 5;
            cells[1].pos[2].x = 1;
            cells[1].pos[2].y = 2;
            cells[1].pos[3].x = 1;
            cells[1].pos[3].y = 3;
            cells[1].pos[4].x = 1;
            cells[1].pos[4].y = 4;
            cells[1].pos[5].x = 1;
            cells[1].pos[5].y = 5;
            cells[1].pos[6].x = 2;
            cells[1].pos[6].y = 2;
            cells[1].pos[7].x = 2;
            cells[1].pos[7].y = 3;

            cells[2].pos[0].x = 1;
            cells[2].pos[0].y = 0;
            cells[2].pos[1].x = 1;
            cells[2].pos[1].y = 1;
            cells[2].pos[2].x = 1;
            cells[2].pos[2].y = 2;
            cells[2].pos[3].x = 1;
            cells[2].pos[3].y = 3;
            cells[2].pos[4].x = 2;
            cells[2].pos[4].y = 2;
            cells[2].pos[5].x = 2;
            cells[2].pos[5].y = 3;
            cells[2].pos[6].x = 2;
            cells[2].pos[6].y = 4;
            cells[2].pos[7].x = 2;
            cells[2].pos[7].y = 5;

            cells[3].pos[0].x = 0;
            cells[3].pos[0].y = 2;
            cells[3].pos[1].x = 0;
            cells[3].pos[1].y = 3;
            cells[3].pos[2].x = 1;
            cells[3].pos[2].y = 0;
            cells[3].pos[3].x = 1;
            cells[3].pos[3].y = 1;
            cells[3].pos[4].x = 1;
            cells[3].pos[4].y = 2;
            cells[3].pos[5].x = 1;
            cells[3].pos[5].y = 3;
            cells[3].pos[6].x = 2;
            cells[3].pos[6].y = 0;
            cells[3].pos[7].x = 2;
            cells[3].pos[7].y = 1;
        }
};

class SBloc : public Block {
    public:
        SBloc(){
            id = 4;

            cells[0].pos[0].x = 0;
            cells[0].pos[0].y = 2;
            cells[0].pos[1].x = 0;
            cells[0].pos[1].y = 3;
            cells[0].pos[2].x = 0;
            cells[0].pos[2].y = 4;
            cells[0].pos[3].x = 0;
            cells[0].pos[3].y = 5;
            cells[0].pos[4].x = 1;
            cells[0].pos[4].y = 0;
            cells[0].pos[5].x = 1;
            cells[0].pos[5].y = 1;
            cells[0].pos[6].x = 1;
            cells[0].pos[6].y = 2;
            cells[0].pos[7].x = 1;
            cells[0].pos[7].y = 3;

            cells[1].pos[0].x = 0;
            cells[1].pos[0].y = 2;
            cells[1].pos[1].x = 0;
            cells[1].pos[1].y = 3;
            cells[1].pos[2].x = 1;
            cells[1].pos[2].y = 2;
            cells[1].pos[3].x = 1;
            cells[1].pos[3].y = 3;
            cells[1].pos[4].x = 1;
            cells[1].pos[4].y = 4;
            cells[1].pos[5].x = 1;
            cells[1].pos[5].y = 5;
            cells[1].pos[6].x = 2;
            cells[1].pos[6].y = 4;
            cells[1].pos[7].x = 2;
            cells[1].pos[7].y = 5;

            cells[2].pos[0].x = 1;
            cells[2].pos[0].y = 2;
            cells[2].pos[1].x = 1;
            cells[2].pos[1].y = 3;
            cells[2].pos[2].x = 1;
            cells[2].pos[2].y = 4;
            cells[2].pos[3].x = 1;
            cells[2].pos[3].y = 5;
            cells[2].pos[4].x = 2;
            cells[2].pos[4].y = 0;
            cells[2].pos[5].x = 2;
            cells[2].pos[5].y = 1;
            cells[2].pos[6].x = 2;
            cells[2].pos[6].y = 2;
            cells[2].pos[7].x = 2;
            cells[2].pos[7].y = 3;

            cells[3].pos[0].x = 0;
            cells[3].pos[0].y = 0;
            cells[3].pos[1].x = 0;
            cells[3].pos[1].y = 1;
            cells[3].pos[2].x = 1;
            cells[3].pos[2].y = 0;
            cells[3].pos[3].x = 1;
            cells[3].pos[3].y = 1;
            cells[3].pos[4].x = 1;
            cells[3].pos[4].y = 2;
            cells[3].pos[5].x = 1;
            cells[3].pos[5].y = 3;
            cells[3].pos[6].x = 2;
            cells[3].pos[6].y = 2;
            cells[3].pos[7].x = 2;
            cells[3].pos[7].y = 3;
        }
};

class JBloc : public Block {
    public:
        JBloc(){
            id = 5;

            cells[0].pos[0].x = 0;
            cells[0].pos[0].y = 0;
            cells[0].pos[1].x = 0;
            cells[0].pos[1].y = 1;
            cells[0].pos[2].x = 1;
            cells[0].pos[2].y = 0;
            cells[0].pos[3].x = 1;
            cells[0].pos[3].y = 1;
            cells[0].pos[4].x = 1;
            cells[0].pos[4].y = 2;
            cells[0].pos[5].x = 1;
            cells[0].pos[5].y = 3;
            cells[0].pos[6].x = 1;
            cells[0].pos[6].y = 4;
            cells[0].pos[7].x = 1;
            cells[0].pos[7].y = 5;

            cells[1].pos[0].x = 0;
            cells[1].pos[0].y = 2;
            cells[1].pos[1].x = 0;
            cells[1].pos[1].y = 3;
            cells[1].pos[2].x = 0;
            cells[1].pos[2].y = 4;
            cells[1].pos[3].x = 0;
            cells[1].pos[3].y = 5;
            cells[1].pos[4].x = 1;
            cells[1].pos[4].y = 2;
            cells[1].pos[5].x = 1;
            cells[1].pos[5].y = 3;
            cells[1].pos[6].x = 2;
            cells[1].pos[6].y = 2;
            cells[1].pos[7].x = 2;
            cells[1].pos[7].y = 3;

            cells[2].pos[0].x = 1;
            cells[2].pos[0].y = 0;
            cells[2].pos[1].x = 1;
            cells[2].pos[1].y = 1;
            cells[2].pos[2].x = 1;
            cells[2].pos[2].y = 2;
            cells[2].pos[3].x = 1;
            cells[2].pos[3].y = 3;
            cells[2].pos[4].x = 1;
            cells[2].pos[4].y = 4;
            cells[2].pos[5].x = 1;
            cells[2].pos[5].y = 5;
            cells[2].pos[6].x = 2;
            cells[2].pos[6].y = 4;
            cells[2].pos[7].x = 2;
            cells[2].pos[7].y = 5;

            cells[3].pos[0].x = 0;
            cells[3].pos[0].y = 2;
            cells[3].pos[1].x = 0;
            cells[3].pos[1].y = 3;
            cells[3].pos[2].x = 1;
            cells[3].pos[2].y = 2;
            cells[3].pos[3].x = 1;
            cells[3].pos[3].y = 3;
            cells[3].pos[4].x = 2;
            cells[3].pos[4].y = 0;
            cells[3].pos[5].x = 2;
            cells[3].pos[5].y = 1;
            cells[3].pos[6].x = 2;
            cells[3].pos[6].y = 2;
            cells[3].pos[7].x = 2;
            cells[3].pos[7].y = 3;
        }
};

class TBloc : public Block {
    public:
        TBloc(){
            id = 6;

            cells[0].pos[0].x = 0;
            cells[0].pos[0].y = 0;
            cells[0].pos[1].x = 0;
            cells[0].pos[1].y = 1;
            cells[0].pos[2].x = 0;
            cells[0].pos[2].y = 2;
            cells[0].pos[3].x = 0;
            cells[0].pos[3].y = 3;
            cells[0].pos[4].x = 0;
            cells[0].pos[4].y = 4;
            cells[0].pos[5].x = 0;
            cells[0].pos[5].y = 5;
            cells[0].pos[6].x = 1;
            cells[0].pos[6].y = 2;
            cells[0].pos[7].x = 1;
            cells[0].pos[7].y = 3;

            cells[1].pos[0].x = 0;
            cells[1].pos[0].y = 2;
            cells[1].pos[1].x = 0;
            cells[1].pos[1].y = 3;
            cells[1].pos[2].x = 1;
            cells[1].pos[2].y = 2;
            cells[1].pos[3].x = 1;
            cells[1].pos[3].y = 3;
            cells[1].pos[4].x = 1;
            cells[1].pos[4].y = 4;
            cells[1].pos[5].x = 1;
            cells[1].pos[5].y = 5;
            cells[1].pos[6].x = 2;
            cells[1].pos[6].y = 2;
            cells[1].pos[7].x = 2;
            cells[1].pos[7].y = 3;

            cells[2].pos[0].x = 1;
            cells[2].pos[0].y = 0;
            cells[2].pos[1].x = 1;
            cells[2].pos[1].y = 1;
            cells[2].pos[2].x = 1;
            cells[2].pos[2].y = 2;
            cells[2].pos[3].x = 1;
            cells[2].pos[3].y = 3;
            cells[2].pos[4].x = 1;
            cells[2].pos[4].y = 4;
            cells[2].pos[5].x = 1;
            cells[2].pos[5].y = 5;
            cells[2].pos[6].x = 2;
            cells[2].pos[6].y = 2;
            cells[2].pos[7].x = 2;
            cells[2].pos[7].y = 3;

            cells[3].pos[0].x = 0;
            cells[3].pos[0].y = 2;
            cells[3].pos[1].x = 0;
            cells[3].pos[1].y = 3;
            cells[3].pos[2].x = 1;
            cells[3].pos[2].y = 0;
            cells[3].pos[3].x = 1;
            cells[3].pos[3].y = 1;
            cells[3].pos[4].x = 1;
            cells[3].pos[4].y = 2;
            cells[3].pos[5].x = 1;
            cells[3].pos[5].y = 3;
            cells[3].pos[6].x = 2;
            cells[3].pos[6].y = 2;
            cells[3].pos[7].x = 2;
            cells[3].pos[7].y = 3;
        }
};

class OBloc : public Block {
    public:
        OBloc(){
            id = 7;
            for (int i = 0; i < 4; i++) {
                cells[i].pos[0].x = 0;
                cells[i].pos[0].y = 0;
                cells[i].pos[1].x = 0;
                cells[i].pos[1].y = 1;
                cells[i].pos[2].x = 0;
                cells[i].pos[2].y = 2;
                cells[i].pos[3].x = 0;
                cells[i].pos[3].y = 3;
                cells[i].pos[4].x = 1;
                cells[i].pos[4].y = 0;
                cells[i].pos[5].x = 1;
                cells[i].pos[5].y = 1;
                cells[i].pos[6].x = 1;
                cells[i].pos[6].y = 2;
                cells[i].pos[7].x = 1;
                cells[i].pos[7].y = 3;
            }
        }
};

class LBloc : public Block {
    public:
        LBloc(){
            id = 8;

            cells[0].pos[0].x = 0;
            cells[0].pos[0].y = 4;            
            cells[0].pos[1].x = 0;
            cells[0].pos[1].y = 5;
            cells[0].pos[2].x = 1;
            cells[0].pos[2].y = 0;
            cells[0].pos[3].x = 1;
            cells[0].pos[3].y = 1;
            cells[0].pos[4].x = 1;
            cells[0].pos[4].y = 2;
            cells[0].pos[5].x = 1;
            cells[0].pos[5].y = 3;
            cells[0].pos[6].x = 1;
            cells[0].pos[6].y = 4;
            cells[0].pos[7].x = 1;
            cells[0].pos[7].y = 5;

            cells[1].pos[0].x = 0;
            cells[1].pos[0].y = 2;
            cells[1].pos[1].x = 0;
            cells[1].pos[1].y = 3;
            cells[1].pos[2].x = 1;
            cells[1].pos[2].y = 2;
            cells[1].pos[3].x = 1;
            cells[1].pos[3].y = 3;
            cells[1].pos[4].x = 2;
            cells[1].pos[4].y = 2;
            cells[1].pos[5].x = 2;
            cells[1].pos[5].y = 3;
            cells[1].pos[6].x = 2;
            cells[1].pos[6].y = 4;
            cells[1].pos[7].x = 2;
            cells[1].pos[7].y = 5;

            cells[2].pos[0].x = 1;
            cells[2].pos[0].y = 0;
            cells[2].pos[1].x = 1;
            cells[2].pos[1].y = 1;
            cells[2].pos[2].x = 1;
            cells[2].pos[2].y = 2;
            cells[2].pos[3].x = 1;
            cells[2].pos[3].y = 3;
            cells[2].pos[4].x = 1;
            cells[2].pos[4].y = 4;
            cells[2].pos[5].x = 1;
            cells[2].pos[5].y = 5;
            cells[2].pos[6].x = 2;
            cells[2].pos[6].y = 0;
            cells[2].pos[7].x = 2;
            cells[2].pos[7].y = 1;

            cells[3].pos[0].x = 0;
            cells[3].pos[0].y = 0;
            cells[3].pos[1].x = 0;
            cells[3].pos[1].y = 1;
            cells[3].pos[2].x = 0;
            cells[3].pos[2].y = 2;
            cells[3].pos[3].x = 0;
            cells[3].pos[3].y = 3;
            cells[3].pos[4].x = 1;
            cells[3].pos[4].y = 2;
            cells[3].pos[5].x = 1;
            cells[3].pos[5].y = 3;
            cells[3].pos[6].x = 2;
            cells[3].pos[6].y = 2;
            cells[3].pos[7].x = 2;
            cells[3].pos[7].y = 3;
        }
};