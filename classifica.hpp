#include <fstream>
#include <iostream>
#include <ncurses.h>
#pragma once

struct player {
    char nome[3];
    int punteggio;
};


/**
 * @brief The Classifica class represents a leaderboard for the game.
 * 
 * It stores the top 10 players' scores in the 'podio' array.
 */
class Classifica {
    public:
        Classifica();
        player podio[11];
        player giocatore;
        char buffer[500];
        void getName();
        void printClassifica();
        void addScore(int);
        void addPlayer();
        void ordinaClassifica();
        int partition(player arr[], int low, int high);
        void quickSort(player arr[], int low, int high);
        void createArray();
        void endGame(int punteggio);
        void scriviPunteggio(int punteggio);

    protected:
        int NUM_RIGHE;
        int yMax, xMax;
        WINDOW * classWin;
};