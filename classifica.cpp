#include "classifica.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ncurses.h>
#include <string>
#include <cstring>

using namespace std;
const int MAX_RIGHE = 11;

// Costruttore
Classifica::Classifica() {
    NUM_RIGHE = 10; // Assicurati che NUM_RIGHE sia coerente con la 22 di podio
    ifstream file("classifica.txt");

    int riga = 0;
    while (riga < NUM_RIGHE+1) {
        file >> podio[riga].nome >> podio[riga].punteggio;
        riga++;
    }
    file.close();

    getmaxyx(stdscr, yMax, xMax);
    classWin = newwin(13, 22, (yMax - 22 + 18) / 2, (xMax / 2) - 22 + 1);

    int i = 0;
    while (i < 3) {
        giocatore.nome[i] = 'Z'; // Inizializzazione di giocatore.nome
        i++;
    }
    giocatore.punteggio = 0;
}

void Classifica::getName() {
    WINDOW * nameWin = newwin(22, 22*2, (yMax-22)/2, (xMax/2)-22+1);
    box(nameWin, 0, 0);
    wborder(nameWin, '|', '|', '-', '-', '+', '+', '+', '+');
    mvwprintw(nameWin, 2, (44-12)/2, "ENTER NAME:");
    echo();
    mvwgetnstr(nameWin, 4, (44-4)/2, giocatore.nome, 3); // Utilizza mvwgetnstr per leggere una stringa di lunghezza massima 3
    addPlayer();
    createArray();
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
        mvwprintw(classWin, i + 1, 1, "%d", i + 1);
        mvwprintw(classWin, i + 1, 4, "%s", podio[i].nome);
        mvwprintw(classWin, i + 1, 12, "%d", podio[i].punteggio);
    }
    wrefresh(classWin);
}

void Classifica::addScore(int score) {
    giocatore.punteggio = score;
    podio[NUM_RIGHE].punteggio = giocatore.punteggio;
    ordinaClassifica();
    createArray();
}

// Funzione per aggiungere un giocatore alla classifica
void Classifica::addPlayer() {
    if (NUM_RIGHE < MAX_RIGHE) {
        podio[NUM_RIGHE] = giocatore;
        NUM_RIGHE++;
    }
}

// Funzione per ordinare la classifica
void Classifica::ordinaClassifica() {
    for (int i = 0; i < NUM_RIGHE; i++) {
        for (int j = 0; j < NUM_RIGHE - 1; j++) {
            if (podio[j].punteggio < podio[j + 1].punteggio) {
                player temp = podio[j];
                podio[j] = podio[j + 1];
                podio[j + 1] = temp;
            }
        }
    }
}

// Funzione per creare array di giocatore+score
void Classifica::createArray() {
    ofstream outputFile("classifica.txt");

    for (int i = 0; i < NUM_RIGHE; i++) {
        outputFile << podio[i].nome << " " << podio[i].punteggio << endl;
    }
    outputFile.close();
}

void Classifica::endGame(int punteggio) {
    scriviPunteggio(punteggio);
    podio[10].punteggio = punteggio;
    ordinaClassifica();
    createArray();
}

void Classifica::scriviPunteggio(int punteggio) {
    fstream file("classifica.txt", ios::in | ios::out);

    // Vai alla fine del file
    file.seekg(0, ios::end);

    // Memorizza la posizione corrente del cursore
    streampos pos = file.tellg();

    // Leggi il contenuto del file all'indietro finché non trovi uno spazio
    char ch;
    do {
        pos = pos - 1;
        file.seekg(pos);
        file.get(ch);
    } while (ch != ' ' && pos > 0);

    // Torna indietro di un carattere per posizionarti proprio prima dello spazio
    if (pos > 0) {
        file.seekp(pos + 1);
    } else {
        file.seekp(0);
    }

    // Scrivi il punteggio dopo lo spazio
    file << punteggio;
    file << endl;

    // Chiudi il file
    file.close();
}