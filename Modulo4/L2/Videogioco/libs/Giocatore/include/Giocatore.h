/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Esempio Giocatore                                             |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */

#ifndef GIOCATORE_H
#define GIOCATORE_H

#include <iostream>

class Giocatore {
public:
    int x;
    int y;

    void assegnaPosizione(int _x, int _y);
    void mostraPosizione();
    void muovi(char direzione);
};

#endif // GIOCATORE_H
