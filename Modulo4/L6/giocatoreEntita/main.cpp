/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Entità giocatore                                              |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */
 
#include <iostream>
#include <string>

// Classe base: Entità
class Entita {
protected:
    int x, y;

public:
    Entita(int x_init, int y_init) : x(x_init), y(y_init) {}

    void muovi(int dx, int dy) {
        x += dx;
        y += dy;
        std::cout << "Entità spostata a (" << x << ", " << y << ")\n";
    }

    void posizione() const {
        std::cout << "Posizione attuale: (" << x << ", " << y << ")\n";
    }
};

// Classe derivata: Giocatore
class Giocatore : public Entita {
private:
    std::string nome;
    int forza;

public:
    Giocatore(std::string nome_init, int forza_init, int x_init, int y_init)
        : Entita(x_init, y_init), nome(nome_init), forza(forza_init) {}

    void attacca() const {
        std::cout << nome << " attacca con forza " << forza << "!\n";
    }

    void info() const {
        std::cout << "Giocatore: " << nome << ", Forza: " << forza << "\n";
        posizione();
    }
};

int main() {
    Giocatore g("Mauro", 10, 0, 0);
    g.info();
    g.muovi(2, 3);
    g.attacca();

    return 0;
}