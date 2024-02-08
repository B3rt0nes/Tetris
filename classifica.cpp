#include "classifica.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ncurses.h>
#include <cstring>

using namespace std;
const int MAX_RIGHE = 11;

// Costruttore
Classifica::Classifica() {
    NUM_RIGHE = 10; // Assicurati che NUM_RIGHE sia coerente con la dimensione di podio
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
    while (i < NUM_COLONNE) {
        giocatore.nome[i] = 'Z'; // Inizializzazione di giocatore.nome
        i++;
    }
    giocatore.punteggio = 0;
}

void Classifica::getName() {
    WINDOW *nameWin = newwin(15, 20, (yMax - 15) / 2, (xMax - 20) / 2);
    box(nameWin, 0, 0);
    mvwprintw(nameWin, 1, 1, "ENTER NAME:");
    echo();
    mvwgetnstr(nameWin, 2, 1, giocatore.nome, 3); // Utilizza mvwgetnstr per leggere una stringa di lunghezza massima 3
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
// Funzione per ordinare la classifica
void Classifica::ordinaClassifica() {
    quickSort(podio, 0, NUM_RIGHE - 1);
}

// Funzione helper per il Quick Sort
int Classifica::partition(player arr[], int low, int high) {
    int pivot = arr[high].punteggio;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].punteggio > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Funzione Quick Sort
void Classifica::quickSort(player arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
