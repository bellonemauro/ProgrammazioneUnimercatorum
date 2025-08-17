/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Esempio Giocatore                                             |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */

#include "Giocatore.h"

void Giocatore::assegnaPosizione(int _x, int _y) {
    x = _x;
    y = _y;
}

void Giocatore::mostraPosizione() {
    std::cout << "Posizione: (" << x << ", " << y << ")" << std::endl;
}

void Giocatore::muovi(char direzione) {
    switch (direzione) {
        case 'w': // avanti
            this->y += 1;
            break;
        case 's': // indietro
            this->y -= 1;
            break;
        case 'a': // sinistra
            this->x -= 1;
            break;
        case 'd': // destra
            this->x += 1;
            break;
        default:
            std::cout << "Direzione non valida." <<std::endl;
    }
}
