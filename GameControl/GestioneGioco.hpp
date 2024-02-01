#include "Punteggio.hpp"
#include "CampoDiGioco.hpp"

class GestioneGioco {
private:
    CampoDiGioco campoDiGioco;
    Punteggio punteggio;
public:
    void gestisciInput();
    void aggiornaGioco();
};