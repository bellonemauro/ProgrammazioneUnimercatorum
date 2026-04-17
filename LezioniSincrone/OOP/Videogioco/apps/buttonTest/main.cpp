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
    g.assegnaNome("Mauro");

    Giocatore* g1 = new Giocatore();
    g1->assegnaPosizione(0, 0);
    g1->assegnaNome("Bellone");

    int maxGiocatori = 10;
    for (int num_giocatori = 0; num_giocatori < maxGiocatori; num_giocatori++)
    {
        Giocatore *gTanti = new Giocatore();
        gTanti->assegnaPosizione(10, 10);
        gTanti->assegnaNome("Mauro");
        //delete gTanti;    // il commento su questa linea questa genera un memory leak
    }

    char comando;
    std::cout << "Controlla il giocatore con WASD. Premi 'q' per uscire.\n";

    do {
        g.mostraPosizione();
        g1->mostraPosizione();
        std::cout << "Comando: ";
        comando = _getch();  
        std::cout << comando << "\n";

        if (comando == 'w' || comando == 'a' || comando == 's' || comando == 'd') {
            g.muovi(comando);
            g1->muovi(comando);
        }
        else if (comando != 'q') {
            std::cout << "Comando non valido.\n";
        }

    } while (comando != 'q');


    delete g1; // l'assenza di questo comando genera un memory leak
    std::cout << "Gioco terminato.\n";
    return 0;
}
