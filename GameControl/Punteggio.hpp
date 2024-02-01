// Punteggio.h
class Punteggio {
private:
    int punteggio;
    int livello;
    int linee;
public:
    void aumentaPunteggio(int punti);
    void aumentaLivello();
    void aggiornaLinee(int n);
};