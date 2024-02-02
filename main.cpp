#include <iostream>
#include <ncurses.h>
#include <array>
#include <ctime>
#include <cstdlib>
#include "grid.h"
#include "blocks.cpp"


using namespace std;

void start();

const int mH = 15;
const int mW = 30;
const int dimensione = 42;
string info[4] = {  "Punteggio:\t", "Livello:\t", "Linee:\t" , "Tempo:\t"};

int main (int argc, char ** argv) {
    initscr();      // start ncurses
    noecho();       // don't print input values
    cbreak();       // terminate ncurses on ctrl + c
    curs_set(0);    // hide the cursor

    start_color(); // inizializza i colori
    init_pair(1, COLOR_BLACK,   COLOR_BLACK);   // 1 -> Background
    init_pair(2, COLOR_CYAN,    COLOR_CYAN);    // 2 -> I
    init_pair(3, COLOR_WHITE,     COLOR_RED);     // 3 -> Z
    init_pair(4, COLOR_GREEN,   COLOR_GREEN);   // 4 -> S
    init_pair(5, COLOR_BLUE,    COLOR_BLUE);    // 5 -> J
    init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA); // 6 -> T
    init_pair(7, COLOR_YELLOW,  COLOR_YELLOW);  // 7 -> O
    init_pair(8, COLOR_WHITE,   COLOR_WHITE);   // 8 -> L
    

    // init_pair(1, COLOR_WHITE,   COLOR_BLACK);   // 1 -> Background
    // init_pair(2, COLOR_WHITE,    COLOR_CYAN);    // 2 -> I
    // init_pair(3, COLOR_WHITE,     COLOR_RED);     // 3 -> Z
    // init_pair(4, COLOR_WHITE,   COLOR_GREEN);   // 4 -> S
    // init_pair(5, COLOR_WHITE,    COLOR_BLUE);    // 5 -> J
    // init_pair(6, COLOR_WHITE, COLOR_MAGENTA); // 6 -> T
    // init_pair(7, COLOR_WHITE,  COLOR_YELLOW);  // 7 -> O
    // init_pair(8, COLOR_WHITE,   COLOR_WHITE);   // 8 -> L


    int yMax, xMax; // to store the size of the window
    getmaxyx(stdscr, yMax, xMax); // get screen size

    WINDOW * menuwin = newwin(mH, mW, (yMax-mH)/2, (xMax-mW)/2);
    wborder(menuwin, '#', '#', '=', '=', '#', '#', '#', '#'); // set the border
    refresh();      // refresh the screen
    wrefresh(menuwin);  // refresh the menuwin
    keypad(menuwin, true); // to get key input (up, down, left, right);
    nodelay(stdscr, TRUE); // to not wait for input

    int menuyMax, menuxMax; 
    getmaxyx(menuwin, menuyMax, menuxMax);

    string scelte[3] = {"start", "classifica", "info"};
    int choice; 
    int highlight = 0;

    while(1) { // loop until a choice is made
        for(int i = 0; i < 3; i++) { // print all choices
            if(i == highlight) // highlight the current choice
                wattron(menuwin, A_REVERSE); 
            mvwprintw(menuwin, i+1, 3, scelte[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin); // get user input

        switch(choice) {
            case KEY_UP:
                highlight--;
                if(highlight < 0)
                    highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight > 3-1)
                    highlight = 3-1;
                break;
            default:
                break;
        }
        if(choice == 10) // if the user presses enter
            break;
    }
    // handle the choice
    switch(highlight) {
        case 0:
            delwin(menuwin);
            start();
            break;
        case 1:
            // Classifica
            break;
        case 2:
            // info
            break;
        default:
            break;
    }

    getch();
    endwin();
    delwin(menuwin); // delete the window to free memory

    return 0;
}

void start() {
// TUTTE LE FUNZIONI PER LE FINESTRE...
    int yMax, xMax; // to store the size of the window
    getmaxyx(stdscr, yMax, xMax); // get screen size

    if (xMax < dimensione || yMax < dimensione) {
        cout << "La finestra è troppo piccola, ingrandiscila e riprova" << endl;
        return;
    }

    /*FINESTRA GIOCO*/
    WINDOW * gamewin = newwin(dimensione, dimensione, (yMax-dimensione)/2, (xMax-dimensione)/2);
    box(gamewin, 0, 0);
    keypad(gamewin, true); // to get key input (up, down, left, right);
    nodelay(stdscr, TRUE); // to not wait for input
    int gmYMax, gmXMax;
    getmaxyx(gamewin, gmYMax, gmXMax);

    /*FINESTRA INFO*/
    // WINDOW * infowin = newwin(17, 23, (yMax/2)-17, (xMax/2-40));
    // box(infowin, 0, 0);
    // nodelay(stdscr, TRUE);

// OGGETTI DALLE CLASSI
    Grid grid = Grid();
    OBloc block = OBloc();

    /*LOOP DI GIOCO*/
    bool loop = true;
    bool isTetramino = false;
    int cont = 0;
    while (loop){
        // box(infowin, 0, 0);
        // wborder(infowin, '#', ' ', '=', '=', '#', '=', '#', '='); // set the border
        // for(int i = 0; i < 4; i++) { // print all choices
        //     mvwprintw(infowin, i+1, 2, info[i].c_str());
        // }

// ==================================================
        /*{
            for (int x = 1; x < dimensione-1; x++) {
            for (int y = 1; y < dimensione-1; y++) {
                mvwprintw(gamewin, x, y, "%c", matrice[x][y]);
            }
        }
        
        {
            if (!isTetramino) { // se non c'è un tetramino

            char tetraminoChar = gameControl.generateRandomTetramin();  // genera un tetramino random
            // tetraminoObj.setTetramino(tetraminoChar);                   // setta il tetramino
            tetraminoObj.setTetraminoMatrix(tetraminoChar, tetraminoObj.tetraminoMatrix); // setta la matrice del tetramino
            
            for (int x = 0; x < 4; x++) {   // add on top of the game matrix the tetramino
                for (int y = 0; y < 4; y++) {
                    if (tetraminoObj.tetraminoMatrix[x][y] != ' ') {
                        matrice[x][y+13] = tetraminoObj.tetraminoMatrix[x][y];
                    }
                }
            }
            isTetramino = true;
        } if (isTetramino){
            // muovi tetramino
            tetraminoObj.moveTetramino(10, 10);
        }
        }*/
        
        // 1. EVENT HANDLING
        // 2. UPDATING POSITIONS
        // 3. DRWING OBJECTS
        // grid.printGrid(gamewin);
        block.Draw(gamewin, 0);



        wrefresh(gamewin);
        // wrefresh(infowin);
        cont++;
    }
    
}