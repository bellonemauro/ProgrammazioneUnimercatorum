/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Esempio Giocatore                                             |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */

#include <iostream>
#include <cstring>
#include <conio.h>

struct Giocatore {
    int x;
    int y;
    char nome[50];
};

void assegnaPosizione(Giocatore* g, int x, int y) {
    g->x = x;
    g->y = y;
}

void assegnaNome(Giocatore* g, const char* nome) {
    std::strncpy(g->nome, nome, sizeof(g->nome) - 1);
    g->nome[sizeof(g->nome) - 1] = '\0';
}

void mostraPosizione(const Giocatore* g) {
    std::cout << g->nome << " si trova in (" << g->x << ", " << g->y << ")\n";
}

void muovi(Giocatore* g, char comando) {
    switch (comando) {
    case 'w':  // avanti
        g->y--; 
        break;
    case 's':  // indietro
        g->y++; 
        break;
    case 'a':  // sinistra
        g->x--; 
        break;
    case 'd': // destra
        g->x++; 
        break;
    }
}

int main() {
    Giocatore g;
    assegnaPosizione(&g, 0, 0);
    assegnaNome(&g, "Mauro");

    Giocatore g1;
    assegnaPosizione(&g1, 0, 0);
    assegnaNome(&g1, "Bellone");

    int maxGiocatori = 10;
    Giocatore gTanti[10];

    for (int num_giocatori = 0; num_giocatori < maxGiocatori; num_giocatori++) {
        assegnaPosizione(&gTanti[num_giocatori], 10, 10);
        assegnaNome(&gTanti[num_giocatori], "Mauro");
    }

    char comando;
    std::cout << "Controlla il giocatore con WASD. Premi 'q' per uscire.\n";

    do {
        mostraPosizione(&g);
        mostraPosizione(&g1);

        std::cout << "Comando: ";
        comando = _getch();
        std::cout << comando << "\n";

        if (comando == 'w' || comando == 'a' || comando == 's' || comando == 'd') {
            muovi(&g, comando);
            muovi(&g1, comando);
        }
        else if (comando != 'q') {
            std::cout << "Comando non valido.\n";
        }

    } while (comando != 'q');

    std::cout << "Gioco terminato.\n";
    return 0;
}