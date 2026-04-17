/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Esempio inventario senza template                             |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */

#include <iostream>
#include <vector>

#include "armi.cpp"
#include "pozioni.cpp"
#include "inventarioArmi.cpp"
#include "inventarioPozioni.cpp"


// Funzione di confronto tra Weapon e Potion
bool confrontaItems(const Arma& a, const Pozione& p) {
    return a.getPowerLevel() > p.getPowerLevel();
}

bool confrontaItems(const Pozione& a, const Arma& p) {
    return a.getPowerLevel() > p.getPowerLevel();
}

// Funzione di confronto tra Weapon e Potion
bool confrontaItems(const Arma& a1, const Arma& a2) {
    return a1.getPowerLevel() > a2.getPowerLevel();
}

// Funzione di confronto tra Weapon e Potion
bool confrontaItems(const Pozione& p1, const Pozione& p2) {
    return p1.getPowerLevel() > p2.getPowerLevel();
}


int main() {
    
    InventarioArmi inventarioArmi;
    inventarioArmi.addItem(Arma());
    inventarioArmi.listaItems();
    inventarioArmi.usaItem(0);

    InventarioPozioni inventarioPozioni;
    inventarioPozioni.addItem(Pozione());
    inventarioPozioni.listaItems();
    inventarioPozioni.usaItem(0);

    Arma spada;
    Pozione sciroppo;

    std::cout << "\nConfronto livelli di potenza:\n";
    if (confrontaItems(spada, sciroppo)) {
        std::cout << "L'arma è più forte della pozione.\n";
    } else {
        std::cout << "La pozione è più forte dell'arma.\n";
    }
    
    if (confrontaItems(spada, spada)) {
        std::cout << "L'arma1 è più forte dell'arma 2.\n";
    } else {
        std::cout << "L'arma2 è più forte dell'arma 1.\n";
    }

    return 0;
}
