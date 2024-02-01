#include "Punteggio.hpp"

class Classifica {
private:
    char file[100];
public:
    void salvaPunteggio(Punteggio p);
    void leggiPunteggi();
};