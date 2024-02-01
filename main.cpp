#include <iostream>
#include <ncurses.h>
#include <array>

using namespace std;

void start();

const int mH = 15;
const int mW = 30;
// const int  = 4;
// const int  = 5;

int main (int argc, char ** argv) {
    initscr();      // start ncurses
    noecho();       // don't print input values
    cbreak();       // terminate ncurses on ctrl + c
    curs_set(0);    // hide the cursor
    
    int yMax, xMax; // to store the size of the window
    getmaxyx(stdscr, yMax, xMax); // get screen size

    WINDOW * menuwin = newwin(mH, mW, (yMax-mH)/2, (xMax-mW)/2);
    wborder(menuwin, '|', '|', '-', '-', '+', '+', '+', '+'); // set the border
    refresh();      // refresh the screen
    wrefresh(menuwin);  // refresh the menuwin
    keypad(menuwin, true); // to get key input (up, down, left, right);
    nodelay(stdscr, TRUE); // to not wait for input

    int menuyMax, menuxMax; 
    getmaxyx(menuwin, menuyMax, menuxMax);

    array<string, 3> scelte = {"start", "Classifica", "info"};
    int choice; 
    int highlight = 0;

    while(1) { // loop until a choice is made
        for(int i = 0; i < scelte.size(); i++) { // print all choices
            if(i == highlight) // highlight the current choice
                wattron(menuwin, A_REVERSE); 
            mvwprintw(menuwin, i+1, 1, scelte[i].c_str());
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
                if(highlight > scelte.size()-1)
                    highlight = scelte.size()-1;
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
    int yMax, xMax; // to store the size of the window
    getmaxyx(stdscr, yMax, xMax); // get screen size

    if (xMax < 35 || yMax < 35) {
        cout << "La finestra è troppo piccola, ingrandiscila e riprova" << endl;
        return;
    }

    /*FINESTRA GIOCO*/
    WINDOW * gamewin = newwin(35, 35, (yMax-35)/2, (xMax-35)/2);
    box(gamewin, 0, 0);
    keypad(gamewin, true); // to get key input (up, down, left, right);
    nodelay(stdscr, TRUE); // to not wait for input
    int gmYMax, gmXMax;
    getmaxyx(gamewin, gmYMax, gmXMax);

    /*FINESTRA INFO*/

    /*LOOP DI GIOCO*/
    bool loop = true;

    while (loop){
        box(gamewin, 0, 0);
        wborder(gamewin, '|', '|', '-', '-', '+', '+', '+', '+'); // set the border
        wrefresh(gamewin);
    }
    
}