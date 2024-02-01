#include "Tetramin.hpp"
// CampoDiGioco.h
class CampoDiGioco {
private:
    int griglia[20][10];
public:
    void aggiungiPezzo(Tetramino t);
    bool verificaLinea();
    void rimuoviLinea();
    bool fineGioco();
};