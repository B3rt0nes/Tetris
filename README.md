#Gioco Tetris ASCII

Questo progetto è una versione ASCII semplificata del classico gioco Tetris. È sviluppato in C++ e utilizza la libreria `ncurses.h` per la grafica.

## Contenuti del gioco

- Il gioco è controllato tramite tastiera.
- La griglia è realizzata con grafica ASCII ed è una matrice di dimensioni 20x10.
- Le regole del gioco seguono quelle del classico Tetris: l'obiettivo è completare le linee orizzontali del campo di gioco. Quando una linea viene completata, scompare e il giocatore guadagna punti.
- Game Over: il gioco termina quando un nuovo tetramino non può più essere inserito nel campo di gioco perché il nuovo pezzo ha toccato la parte superiore della griglia.
- Ad ogni giro, il nuovo pezzo (tetramino) da inserire viene scelto casualmente dall'insieme di forme predefinite.
- Movimento laterale: il giocatore può muovere il tetramino a sinistra o a destra finché non colpisce un altro pezzo o raggiunge il bordo del campo di gioco.
- Rotazione: il giocatore può ruotare il tetramino di 90° in senso orario.
- Punteggio: il punteggio aumenta ogni volta che il giocatore completa una riga. Il completamento di più righe contemporaneamente produce un punteggio più alto.
- Il gioco prevede quindi un menu iniziale con le seguenti opzioni:
   - Nuovo gioco
   - Classifica

## How to run

Per eseguire il gioco, esegui il comando `$ make`