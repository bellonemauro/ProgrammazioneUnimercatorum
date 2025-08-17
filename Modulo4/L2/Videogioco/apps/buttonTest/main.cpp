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
#include <conio.h> // funziona solo su windows e serve per il comando _getch() 
#include "Giocatore.h"

int main() {
    Giocatore g;
    g.assegnaPosizione(0, 0);

    char comando;
    std::cout << "Controlla il giocatore con WASD. Premi 'q' per uscire.\n";

    do {
        g.mostraPosizione();
        std::cout << "Comando: ";
        comando = _getch();  
        std::cout << comando << "\n";

        if (comando == 'w' || comando == 'a' || comando == 's' || comando == 'd') {
            g.muovi(comando);
        }
        else if (comando != 'q') {
            std::cout << "Comando non valido.\n";
        }

    } while (comando != 'q');


    std::cout << "Gioco terminato.\n";
    return 0;
}
