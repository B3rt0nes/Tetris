# `Tetris`

## RoadMap
- Definizione delle classi: Definisci una classe base Tetramino che rappresenta un pezzo generico di Tetris. Questa classe dovrebbe avere metodi per ruotare il pezzo, spostarlo e rilevare le collisioni. Poi, crea classi figlie per ogni tipo specifico di pezzo (I, O, T, S, Z, J, L), che ereditano da Tetramino.

- Gestione del campo di gioco: Crea una classe CampoDiGioco che gestisce la griglia di gioco. Questa classe dovrebbe avere metodi per aggiungere un pezzo al campo di gioco, controllare se una linea è completa, rimuovere le linee complete e verificare se il gioco è finito.

- Gestione del punteggio: Aggiungi una classe Punteggio che tiene traccia del punteggio corrente, del livello e delle linee completate. Questa classe dovrebbe avere metodi per aumentare il punteggio, aumentare il livello e aggiornare il numero di linee completate.

- Gestione del gioco: Crea una classe GestioneGioco che gestisce il flusso del gioco. Questa classe dovrebbe creare e gestire le istanze delle classi CampoDiGioco e Punteggio, gestire l’input dell’utente e aggiornare il gioco ad ogni frame.

- Salvataggio della classifica: Aggiungi un metodo alla classe Punteggio per salvare il punteggio corrente in un file esterno ogni volta che il gioco finisce. Potresti anche voler creare una classe Classifica per gestire la lettura e la scrittura dei punteggi sul file.

- Organizzazione del codice: Suddividi il tuo codice in più file. Ad esempio, potresti avere un file per ogni classe (Tetramino.h, CampoDiGioco.h, ecc.) e un file main.cpp che include tutti gli altri file e contiene la funzione main.


##### Cosa consegnare
- Codice sorgente
- File README
- Screen recording che mostri l'esecuzione del gioco
- Relazione (3/4 pagine) in cui descrivere le scelte nell'implementazione del progetto

#### contenuti del gioco
- implementare una versione ASCII semplificata di Tetris
- con punteggio
- il gioco si controlla da tastiera

#### Requisiti
- [x] utilizzare SOLO le librerie grafiche `ncurses.h`
- [x] la griglia di deve essere realizzata con grafica ASCII e deve essere una matrice con dimensioni almeno 20x10
- [ ] Le regole del gioco seguono quelle del Tetris classico: lo scopo è completare linee orizzontali nel campo di gioco. Quando una linea viene completata, scompare e il giocatore guadagna punti.
- [ ] Non esistono traguardi
- [ ] **GameOver:** la partita termina quando un nuovo tetramino non può più essere inserito nel campo di gioco perché il nuovo pezzo ha toccato la parte superiore della griglia
- [ ] Si richiede di implementare **almeno 2** tra tutte le forme di tetramini disponibili.
- [ ] Caduta dei pezzi: i tetramini cadono dall'alto dello schermo verso il basso.
- [ ] Ogni turno il nuovo pezzo (tetramino) da inserire è scelto casualmente tra l'insieme di forme predeﬁnite.
- [ ] Spostamento laterale: il giocatore può muovere il tetramino a sinistra o a destra ﬁnché non colpisce un altro pezzo o raggiunge il bordo del campo di gioco.
- [ ] Rotazione: il giocatore può far ruotare il tetramino di 90° in senso orario o antiorario.
- [ ] Punteggio: il punteggio aumenta ogni volta che il giocatore completa una linea. Completando più linee contemporaneamente si deve ottenere un punteggio maggiore.
- [ ] Il gioco deve quindi prevedere un menù iniziale con le seguenti opzioni:
  - Nuova partita
  - Visualizza classiﬁca ordinata in modo decrescente (punteggi delle partite terminate)
- [ ] Al termine della partita (game over) il giocatore torna al
menù iniziale.
