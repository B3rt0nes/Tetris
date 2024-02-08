#include "classifica.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ncurses.h>
#include <cstring>

using namespace std;

// Costruttore
Classifica::Classifica() {
    NUM_RIGHE = 10;
    NUM_COLONNE = 3;
    ifstream file("classifica.txt");

    for (int riga = 0; riga < NUM_RIGHE; riga++) {
        char tempPunteggio[10] = {0}; // Temporary array to store the score as characters
        int indexPunteggio = 0; // Index for the temporary score array
        for (int colonna = 0; colonna < NUM_COLONNE+2+4; colonna++) {
            char carattere;
            file.get(carattere);
            if ((carattere >= 'A' && carattere <= 'Z') || (carattere >= 'a' && carattere <= 'z')) {
                podio[riga].nome[colonna] = carattere;
            } else if (carattere == ' ') {
                podio[riga].nome[colonna] = '\0';
            } else if (carattere >= '0' && carattere <= '9') {
                tempPunteggio[indexPunteggio++] = carattere; // Store the score character
            } else if (carattere == '\n') {
                podio[riga].punteggio = atoi(tempPunteggio); // Convert the score characters to an integer
                break;
            } else {
                podio[riga].nome[colonna] = ' ';
                break;
            }
        }
    }

    file.close();
    getmaxyx(stdscr, yMax, xMax);
    classWin = newwin(13, 22, (yMax-22+18)/2, (xMax/2)-22+1);

    for (int i = 0; i < NUM_RIGHE; i++) {
        for (int j = 0; j < NUM_COLONNE; j++) {
            giocatore.nome[j] = 'Z';
        }
    }
    giocatore.punteggio = 0;
    buffer[0] = '\0';
}

void Classifica::getName() {
    WINDOW * nameWin = newwin(15, 20, (yMax-15)/2, (xMax-20)/2);
    box(nameWin, 0, 0);
    mvwprintw(nameWin, 1, 1, "ENTER NAME:");
    echo();
    // mvwgetstr(nameWin, 2, 1, giocatore.nome);
    nodelay(stdscr, TRUE); 
    for (int i = 0; i < 3; ++i) {
        char c = mvwgetch(nameWin, 2, i+1);
        giocatore.nome[i] = c;
        mvwprintw(nameWin, 2, i+1, &c);
        mvwprintw(nameWin, 2, i+2, "_");
        mvwprintw(nameWin, 2, i+3, " ");
        wrefresh(nameWin);
    }
    addPlayer();
    noecho(); 
    wrefresh(nameWin);
    
    napms(2000); // Sleep for 1 second
    delwin(nameWin); // Delete the window to free up memory
}

// Funzione per stampare la classifica
void Classifica::printClassifica() {
    box(classWin, 0, 0);
    wborder(classWin, '|', ' ', ' ', '-', '|', ' ', '+', '-'); // set the border
    mvwprintw(classWin, 0, 1, "CLASSIFICA");
    for (int i = 0; i < NUM_RIGHE; i++) {
        mvwprintw(classWin, i+1, 1, "%d", i+1);
        for (int j = 0; j < NUM_COLONNE; j++) {
            mvwprintw(classWin, i+1, 4+j, "%c", podio[i].nome[j]);
        }
        mvwprintw(classWin, i+1, 12, "%d", podio[i].punteggio);
    }
    wrefresh(classWin);

}

void Classifica::addScore(int score) {
    giocatore.punteggio = score;
    addPlayer();
    ordinaClassifica();
    createArray();  
}

// Funzione per aggiungere un giocatore alla classifica
void Classifica::addPlayer() {
    for (int i = 0; i < 3; i++) {
        podio[NUM_RIGHE+1].nome[i] = giocatore.nome[i];
    }
    podio[NUM_RIGHE+1].punteggio = giocatore.punteggio;
}

// Funzione per aggiornare la classifica
void Classifica::ordinaClassifica() {
    for (int i = 0; i < NUM_RIGHE+1; i++) {   // Bubble sort
        for (int j = i+1; j < NUM_RIGHE+1; j++) {
            if (podio[i].punteggio < podio[j].punteggio) {
                player temp = podio[i];
                podio[i] = podio[j];
                podio[j] = temp;
            }
        }
    }
}

// Funnzione per creare array di giocatore+score
void Classifica::createArray() {
    ofstream outputFile;
    outputFile.open("classifica.txt");

    for (int i = 0; i < NUM_RIGHE; i++) {
        char temp[50]; // Temporary buffer for each player
        sprintf(temp, "%s %d\n", podio[i].nome, podio[i].punteggio);
        outputFile << temp;
    }
    outputFile.close();
}

// Funzione per salvare la classifica su file

// Funzione per caricare la classifica da file

// Funzione per ordinare la classifica