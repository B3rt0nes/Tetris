#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <array>
#include <ctime>
#include <string>
#include <cstring>

#include "game.hpp"

using namespace std;

void game();
void menu();
void checkClassifica();
void classifica();
void removeLastLine();

const int mH = 15;
const int mW = 20;
const int dimensione = 20+2;
char opt[2][50] = { "Gioca", "Classifica" };
int yMax, xMax;

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

    menu();

    return 0;
}

void menu() {
    WINDOW * menuwin = newwin(dimensione, dimensione*2, (yMax-dimensione)/2, (xMax/2)-dimensione+1);
    wborder(menuwin, '|', '|', '-', '-', '+', '+', '+', '+');
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);
    nodelay(stdscr, TRUE);

    int choice; 
    int highlight = 0;

    while(1) { // loop until a choice is made
        for (int i = 0; i < 2; i++) {
            if (i == highlight)
                wattron(menuwin, A_REVERSE); // Evidenzia la scelta corrente
            mvwprintw(menuwin, i+2, 3, opt[i]);
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
            game();
            break;
        case 1:
            delwin(menuwin);
            classifica();
            break;
        default:
            break;
    }

    getch();
    endwin();
    delwin(menuwin); // delete the window to free memory
}

void game() {
// TUTTE LE FUNZIONI PER LE FINESTRE...

    // la classifica deve avere 11 righe, la 11esima riga è quella del giocatore
    // che viene aggiornata ogni volta che si avvia il gioco.
    // controlli per classifica.txt
    checkClassifica();
    removeLastLine();

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
    


// OGGETTI DALLE CLASSI
    Game game = Game();
    game.classifica.getName();

    /*LOOP DI GIOCO*/
    bool loop = game.isGameOver();
    int nap = 0;
    int currentNext = game.nextBlock.id;
    double lastUpdateTime = 0;
    while (!loop){
        loop = game.isGameOver();
        box(infowin, 0, 0);
        wborder(infowin, '|', ' ', '-', '-', '+', '-', '+', '-'); // set the border
        mvwprintw(infowin, 1, 1, "Nome:");
        for (int i = 0; i < 3; i++) {
            mvwprintw(infowin, 1, 16+i, "%c", game.classifica.giocatore.nome[i]);
        }
        
        mvwprintw(infowin, 2, 1, "Punteggio:\t%d", game.classifica.giocatore.punteggio);
        mvwprintw(infowin, 3, 1, "Linee:\t\t%d", game.grid.lines);
        
        game.classifica.printClassifica();

        box(next, 0, 0);
        wborder(next, '|', ' ', ' ', '-', '|', ' ', '+', '-'); // set the border
        mvwprintw(next, 0, 1, "Prossimo blocco:");
        if (currentNext != game.nextBlock.id) {
            currentNext = game.nextBlock.id;
            wclear(next);
        }
        game.nextBlock.Draw(next, 0);   // disegna il prossimo blocco
// ==================================================
                

        wrefresh(gamewin);
        wrefresh(infowin);  
        wrefresh(next);
        
        timeout(0); 
        
        game.handleInput(gamewin);

        // Se sono passati 200ms dall'ultimo aggiornamento, muovi il blocco in basso
        if ((clock() - lastUpdateTime) / CLOCKS_PER_SEC >= 0.2) {
            game.draw(gamewin);
            game.MoveBlockDown();
            lastUpdateTime = clock();
        }

        if (game.isGameOver() == true) {
            game.classifica.endGame(game.grid.score);

            game.grid.initGrid();
            game.grid.printGrid(gamewin);

            mvwprintw(gamewin, 10, 6, "GAME OVER");
            wrefresh(gamewin);
            game.gameOver = false;
            menu();
        }
        napms(nap);
    }

    
}

void classifica() {
    WINDOW * classwin = newwin(dimensione, dimensione*2, (yMax-dimensione)/2, (xMax/2)-dimensione+1);
    wborder(classwin, '|', '|', '-', '-', '+', '+', '+', '+');
    refresh();
    wrefresh(classwin);
    keypad(classwin, true); 
    nodelay(stdscr, FALSE);  

    std::ifstream inFile("classifica.txt");

    // Leggi e stampa ogni carattere del file
    char carattere;
    int riga = 5;
    int colonna = 1;
    while (inFile.get(carattere)) {
        if (carattere == '\n') {
            riga++;
            colonna = 1;
        } else {
            if (colonna == 1) {
                mvwprintw(classwin, riga, colonna+2, "#%d", riga-4);
            }
            // mvwaddch(classwin, riga, colonna, riga);
            // mvwaddch(classwin, riga, colonna+1, '°');
            mvwaddch(classwin, riga, colonna+6, carattere);
            colonna++;
        }
    }

    // Chiudi il file
    inFile.close();

    
    int choice; 
    int highlight = 0;
    while(1) { // loop until a choice is made
        for (int i = 0; i < 2; i++) {
            if (i == highlight)
                wattron(classwin, A_REVERSE); // Evidenzia la scelta corrente
            mvwprintw(classwin, i+2, 3, opt[i]);
            wattroff(classwin, A_REVERSE);
        }
        choice = wgetch(classwin); // get user input

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
            delwin(classwin);
            game();
            break;
        case 1:
            delwin(classwin);
            classifica();
            break;
        default:
            break;
    }

    getch();
    endwin();
    delwin(classwin); // delete the window to free memory
}

void removeLastLine() {
    const int MAX_RIGHE = 11;
    const int MAX_CARATTERI = 256;

    char lines[MAX_RIGHE][MAX_CARATTERI];
    char line[MAX_CARATTERI];
    ifstream file("classifica.txt");

    // Leggi tutte le righe in un array
    int i = 0;
    while (file.getline(line, MAX_CARATTERI) && i < MAX_RIGHE) {
        strncpy(lines[i], line, MAX_CARATTERI);
        i++;
    }
    file.close();

    // Riscrivi il file con le righe rimanenti, tranne l'ultima
    ofstream outputFile("classifica.txt");
    for (int j = 0; j < i - 1; j++) {
        outputFile << lines[j] << endl;
    }
    outputFile.close();
}

void checkClassifica() {
    ifstream inFile("classifica.txt");
    if (!inFile) {
        cerr << "Unable to open file classifica.txt";
        exit(1);
    }

    int count = 0;
    char ch;
    bool lastCharIsNewline = false;

    while (inFile.get(ch)) {
        if (ch == '\n') {
            count++;
            lastCharIsNewline = true;
        } else {
            lastCharIsNewline = false;
        }
    }

    inFile.close();

    if (!lastCharIsNewline) {
        ofstream outFile;
        outFile.open("classifica.txt", ios_base::app);
        outFile << "\n";
        outFile.close();
        count++;
    }

    if (count < 11) {
        ofstream outFile;
        outFile.open("classifica.txt", ios_base::app);  
        for (int i = count; i < 11; i++) {
            outFile << "AAA 0\n";   
        }
        outFile.close();
    }
}