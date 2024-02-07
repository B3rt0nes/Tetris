#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <array>
#include <ctime>

#include "game.hpp"


using namespace std;

// const int NUM_RIGHE = 11;
// const int NUM_COLONNE = 17;

void start();
// void getName();
// void leggiFile(char matrice[NUM_RIGHE][NUM_COLONNE], const std::string& nomeFile);
// void stampaMatrice(WINDOW* win, char matrice[NUM_RIGHE][NUM_COLONNE]);

const int mH = 15;
const int mW = 20;
const int dimensione = 20+2;
string info[2] = {  "Punteggio:\t", "Linee:\t"};
char name[50];

int main (int argc, char ** argv) {
    initscr();
    noecho();
    cbreak();
    curs_set(0);

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
    wborder(menuwin, '|', '|', '-', '-', '+', '+', '+', '+');
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);
    nodelay(stdscr, TRUE);

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
    // getName();

    // ifstream inputFile;
    // inputFile.open("classifica.txt");

    // ifstream inputFile("classifica.txt");

    // char classifica[NUM_RIGHE][NUM_COLONNE];
    // leggiFile(classifica, "classifica.txt");
    // char classifica[dimensione-2];

    // /* lettura dati */
    // for (int i = 0; !inputFile.eof(); i++) {
    //     // for (int j = 0; j < 10; j++) {
    //         // inputFile.get(classifica[j][i]);
    //         inputFile.get(classifica[i]);
    //         // if (classifica[j][i] == '\n') {
    //         //     j = 10;
    //         // }
    // //    }
    // }
    // inputFile.close();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    /*FINESTRA GIOCO*/
    WINDOW * gamewin = newwin(dimensione, dimensione, (yMax-dimensione)/2, (xMax)/2+1);
    box(gamewin, 0, 0); 
    keypad(gamewin, true);
    nodelay(gamewin, TRUE);
    nodelay(stdscr, TRUE);

    /*FINESTRA INFO*/
    WINDOW * infowin = newwin(5, dimensione, (yMax-dimensione)/2, (xMax/2)-dimensione+1);
    box(infowin, 0, 0);
    nodelay(stdscr, TRUE);
    /*FINESTRA PROSSIMO BLOCCO*/
    WINDOW * next = newwin(4, dimensione, (yMax-dimensione+10)/2, (xMax/2)-dimensione+1);
    box(next, 0, 0);
    nodelay(stdscr, TRUE);
    /*FINESTRA CLASSIFICA*/
    WINDOW * classwin = newwin(13, dimensione, (yMax-dimensione+18)/2, (xMax/2)-dimensione+1);
    box(classwin, 0, 0);
    nodelay(stdscr, TRUE);


// OGGETTI DALLE CLASSI
    Game game = Game();

    /*LOOP DI GIOCO*/
    bool loop = game.isGameOver();
    int nap = 0;
    int currentNext = game.nextBlock.id;
    double lastUpdateTime = 0;
    while (!loop){
        box(infowin, 0, 0);
        wborder(infowin, '|', ' ', '-', '-', '+', '-', '+', '-'); // set the border
        mvwprintw(infowin, 1, 1, "Nome: \t\t%s", name);
        mvwprintw(infowin, 2, 1, "Punteggio:\t%d", game.grid.score);
        mvwprintw(infowin, 3, 1, "Linee:\t\t%d", game.grid.lines);
        
        box(classwin, 0, 0);
        wborder(classwin, '|', ' ', ' ', '-', '|', ' ', '+', '-'); // set the border
        mvwprintw(classwin, 0, 1, "Classifica:");
        // for (int i = 0; i < 10; i++) {
        //     mvwprintw(classwin, i+1, 1, "%c", classifica[i]);
        // }
        // mvwprintw(classwin, 1, 1, "%s", line.c_str());
        // for (int r = 1; r <= 11; r++) {
        //     for (int c = 0; c < dimensione-2; c++) {
        //         // mvwprintw(classwin, 1, c+1, "%c", classifica[c]);
        //         mvwprintw(classwin, r+1, c+1, "%c", classifica[r][c]);
        //     }
        // }

        // stampaMatrice(classwin, classifica);

        box(next, 0, 0);
        wborder(next, '|', ' ', ' ', '-', '|', ' ', '+', '-'); // set the border
        mvwprintw(next, 0, 1, "Prossimo blocco:");
        if (currentNext != game.nextBlock.id) {
            currentNext = game.nextBlock.id;
            wclear(next);
        }
        game.nextBlock.Draw(next, 0);
// ==================================================
        loop = game.isGameOver();
        

        wrefresh(gamewin);
        wrefresh(infowin);
        wrefresh(classwin);
        wrefresh(next);
        
        timeout(0); // Setta il timer a 0
    
        game.handleInput(gamewin);

        // Se sono passati 200ms dall'ultimo aggiornamento, muovi il blocco in basso
        if ((clock() - lastUpdateTime) / CLOCKS_PER_SEC >= 0.2) {
            game.draw(gamewin);
            game.MoveBlockDown();
            lastUpdateTime = clock();
        }

        if (game.isGameOver() == true) {
            game.grid.initGrid();
            game.grid.printGrid(gamewin);

            mvwprintw(gamewin, 10, 6, "GAME OVER");
            wrefresh(gamewin);
            nap = 2000; 
            game.gameOver = false;
        }
        napms(nap);
    }

    
}

// void getName() {
//     int yMax, xMax; // to store the size of the window
//     getmaxyx(stdscr, yMax, xMax); // get screen size
//     WINDOW * nameWin = newwin(mH, mW, (yMax-mH)/2, (xMax-mW)/2);
//     box(nameWin, 0, 0);
//     refresh();
//     wrefresh(nameWin);
//     nodelay(nameWin, FALSE);
//     mvwprintw(nameWin, 1, 1, "ENTER NAME:");
//     wrefresh(nameWin);
//     echo(); // enable echoing of characters
//     mvwgetstr(nameWin, 2, 1, name); // get the name from the user
//     noecho(); // disable echoing
//     wrefresh(nameWin);  // refresh the menuwin
//     nodelay(stdscr, TRUE); // to not wait for input
// }

// void leggiFile(char matrice[NUM_RIGHE][NUM_COLONNE], const std::string& nomeFile) {
//     ifstream file(nomeFile);

//     for (int riga = 0; riga < NUM_RIGHE; ++riga) {
//         for (int colonna = 0; colonna < NUM_COLONNE; ++colonna) {
//             char carattere;
//             file.get(carattere); // Leggi un carattere alla volta dal file
//             if (carattere == '\n' || carattere == EOF) {
//                 for (int i = colonna; i < NUM_COLONNE; ++i) {
//                     matrice[riga][i] = ' ';
//                 }
//                 break;
//             } 
//             matrice[riga][colonna] = carattere; // Memorizza il carattere nella matrice
//         }
//     }

//     file.close();
// }

// void stampaMatrice(WINDOW* win, char matrice[NUM_RIGHE][NUM_COLONNE]) {
//     for (int riga = 0; riga < NUM_RIGHE-1 ; ++riga) {
//         int pos = riga+1;
//         mvwprintw(win, riga+1, 1, "%d", pos);
//         mvwprintw(win, riga+1, 2, "%c", "°");
//         mvwprintw(win, riga+1, 3, "%c", " ");
//         for (int colonna = 0; colonna < NUM_COLONNE; ++colonna) {
//             mvwprintw(win, riga+1, colonna+4, "%c", matrice[riga][colonna]);
//         }
//     }
// }