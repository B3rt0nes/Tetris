// #include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
// #include <ncurses.h>

// using namespace std;



// int main (int argc, char ** argv) {
    
// // START
//     initscr();
//     noecho();
//     cbreak();
//     curs_set(0);
    
//     int maxY, maxX;
//     getmaxyx(stdscr, maxY, maxX); // get screen size

//     // gameTitle(xMax, yMax);

// // COME CREARE IL MENU
//     WINDOW * menuwin = newwin(5, maxX-12, maxY/2+4, 5);
//     wborder(menuwin, 0, 0, (int)'=', (int)'=', (int)'<', (int)'>', (int)'<', (int)'>');
//     refresh();
//     wrefresh(menuwin);
//     keypad(menuwin, true); // to get key input (up, down, left, right);
//     nodelay(stdscr, TRUE);

//     int menuyMax, menuxMax;
//     getmaxyx(menuwin, menuyMax, menuxMax);

//     string scelte[3] = {"start", "continue", "info"};
//     int choice;
//     int highlights = 0;

//     // loadItems();
//     bool open = true;
//     while (open){
//         for (int i = 0; i < 3; i++){ // costruisco il menu
//             if (i == highlights) wattron(menuwin, A_REVERSE);
//             mvwprintw(menuwin, i+1, menuxMax/2-10, "%s", scelte[i].c_str());
//             wattroff(menuwin, A_REVERSE);
//         }
//         choice = wgetch(menuwin);

//         switch(choice){            // mi muovo nel menu
//             case KEY_UP:
//                 highlights--;
//                 if (highlights == -1) highlights = 0;
//                 break;
//             case KEY_DOWN:
//                 highlights++;
//                 if (highlights == 3) highlights = 2;
//                 break;
//             case 10: 
//                 open = false;
//                 break;
//             default:
//                 break;
//         }
//     }

//     if (highlights <= 1){
//         clear();
//         // if(highlights == 1) current_game.continueLast();
//         // start();
//     }

//     getch();
//     endwin();
//     /*END*/

//     return 0;
// }

#include <ncurses.h>

int main() {
    initscr(); // inizializza ncurses
    noecho(); // disabilita l'eco dell'input
    cbreak(); // disabilita la bufferizzazione dell'input

    int height = 10;
    int width = 20;
    int start_y = (LINES - height) / 2; // centra la finestra verticalmente
    int start_x = (COLS - width) / 2; // centra la finestra orizzontalmente

    WINDOW *win = newwin(height, width, start_y, start_x); // crea una nuova finestra

    box(win, 0, 0); // disegna una scatola attorno alla finestra
    mvwprintw(win, 1, 1, "Ciao, mondo!"); // stampa una stringa nella finestra
    wrefresh(win); // aggiorna la finestra

    getch(); // aspetta che l'utente prema un tasto
    delwin(win); // rilascia la finestra

    endwin(); // termina ncurses
    return 0;
}