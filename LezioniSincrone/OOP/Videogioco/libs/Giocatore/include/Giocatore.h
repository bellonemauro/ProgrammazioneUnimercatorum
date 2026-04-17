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
#include <string>

class Giocatore {
private:
    std::string nome;
    int x;
    int y;

public:

    void assegnaPosizione(int _x, int _y);
    void mostraPosizione();
    void muovi(char direzione);
    void assegnaNome(std::string _nome);
};


#endif // GIOCATORE_H
