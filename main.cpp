#include <iostream>
#include <ncurses.h>
#include <array>

#include "game.h"


using namespace std;

void start();

const int mH = 15;
const int mW = 20;
const int dimensione = 20+2;
string info[4] = {  "Punteggio:\t", "Livello:\t", "Linee:\t" , "Tempo:\t"};

int main (int argc, char ** argv) {
    initscr();      // start ncurses
    noecho();       // don't print input values
    cbreak();       // terminate ncurses on ctrl + c
    curs_set(0);    // hide the cursor

    start_color(); // inizializza i colori
    
    init_pair(1, COLOR_BLACK,   COLOR_BLACK);       // 1 -> Background
    init_pair(2, COLOR_CYAN,    COLOR_CYAN);        // 2 -> I
    init_pair(3, COLOR_RED,   COLOR_RED);           // 3 -> Z
    init_pair(4, COLOR_GREEN,   COLOR_GREEN);       // 4 -> S
    init_pair(5, COLOR_BLUE,    COLOR_BLUE);        // 5 -> J
    init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);     // 6 -> T
    init_pair(7, COLOR_YELLOW,  COLOR_YELLOW);      // 7 -> O
    init_pair(8, COLOR_WHITE,   COLOR_WHITE);       // 8 -> L
    

    // init_pair(1, COLOR_WHITE, COLOR_BLACK);         // 1 -> Background
    // init_pair(2, COLOR_WHITE, COLOR_CYAN);          // 2 -> I
    // init_pair(3, COLOR_WHITE, COLOR_RED);           // 3 -> Z
    // init_pair(4, COLOR_WHITE, COLOR_GREEN);         // 4 -> S
    // init_pair(5, COLOR_WHITE, COLOR_BLUE);          // 5 -> J
    // init_pair(6, COLOR_WHITE, COLOR_MAGENTA);       // 6 -> T
    // init_pair(7, COLOR_WHITE, COLOR_YELLOW);        // 7 -> O
    // init_pair(8, COLOR_WHITE, COLOR_WHITE);         // 8 -> L


    int yMax, xMax; // to store the size of the window
    getmaxyx(stdscr, yMax, xMax); // get screen size

    if (yMax >= dimensione +  12) {

    WINDOW * titlewin = newwin(0, 42, 2, (xMax-42)/2);
    refresh();
    wrefresh(titlewin);
    nodelay(titlewin, TRUE); // to not wait for input
    keypad(titlewin, true);
    mvwprintw(titlewin, 1, 1, "MMMMMM MMMMMM MMMMMM MMMML   MMMMM MMMMMM");
    mvwprintw(titlewin, 2, 1, "  MM   MM       MM   M   M     M   MM    ");
    mvwprintw(titlewin, 3, 1, "  MM   MMMM     MM   MMMMP     M   MMMMMM");
    mvwprintw(titlewin, 4, 1, "  MM   MM       MM   M  M,     M       MM");
    mvwprintw(titlewin, 5, 1, "  MM   MM       MM   M  'M,    M       MM");
    mvwprintw(titlewin, 6, 1, "  MM   MMMMMM   MM   M   'M  MMMMM MMMMMM");

    wrefresh(titlewin);
    } else if (yMax >= dimensione + 2) {
        WINDOW * titlewin = newwin(0, 20, 2, (xMax-20)/2);
        refresh();
        wrefresh(titlewin);
        nodelay(titlewin, TRUE); // to not wait for input
        mvwprintw(titlewin, 0, 8, "TETRIS");

        wrefresh(titlewin);
    }

    WINDOW * menuwin = newwin(mH, mW, (yMax-mH)/2, (xMax-mW)/2);
    wborder(menuwin, '|', '|', '-', '-', '+', '+', '+', '+'); // set the border
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
            mvwprintw(menuwin, i+2, 3, scelte[i].c_str());
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
    WINDOW * gamewin = newwin(dimensione, dimensione, (yMax-dimensione)/2, (xMax)/2+1);
    box(gamewin, 0, 0); 
    keypad(gamewin, true); // to get key input (up, down, left, right);
    nodelay(stdscr, TRUE); // to not wait for input

    /*FINESTRA INFO*/
    WINDOW * infowin = newwin(12, dimensione, (yMax-dimensione)/2, (xMax/2)-dimensione+1);
    box(infowin, 0, 0);
    nodelay(stdscr, TRUE);

    /*FINESTRA CLASSIFICA*/
    WINDOW * classwin = newwin(11, dimensione, (yMax-dimensione+22)/2, (xMax/2)-dimensione+1);
    box(classwin, 0, 0);
    nodelay(stdscr, TRUE);

// OGGETTI DALLE CLASSI
    Game game = Game();

    /*LOOP DI GIOCO*/
    bool loop = true;
    bool isTetramino = false;
    int cont = 0;
    while (loop){
        box(infowin, 0, 0);
        wborder(infowin, '|', ' ', '-', '-', '+', '-', '+', '-'); // set the border
        for(int i = 0; i < 4; i++) { // print all choices
            mvwprintw(infowin, i+1, 1, info[i].c_str());
        }
        box(classwin, 0, 0);
        wborder(classwin, '|', ' ', '-', '-', '+', '-', '+', '-'); // set the border
        mvwprintw(classwin, 1, 1, "Classifica:");

// ==================================================

        
        // 1. EVENT HANDLING
        // 2. UPDATING POSITIONS
        // 3. DRWING OBJECTS
        game.draw(gamewin);
        // block.Draw(gamewin, 0);


        wrefresh(gamewin);
        wrefresh(infowin);
        wrefresh(classwin);
        
        game.handleInput(gamewin);

        cont++;
    }
    
}