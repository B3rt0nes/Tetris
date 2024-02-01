class Tetramino {
private:
    int forma[4][4];
    int posizione[2];
public:
    void ruota();
    void muovi(int dx, int dy);
    bool verificaCollisione(int campoDiGioco[20][10]);
};