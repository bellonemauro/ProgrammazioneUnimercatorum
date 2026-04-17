#include <iostream>
#include <vector>

#include "armi.cpp"
#include "pozioni.cpp"
#include "inventario.cpp"

// Template di funzione: confronto tra oggetti di tipo diverso
template <typename T1, typename T2>
bool confrontaItems(const T1& a, const T2& b) {
    bool success = a.getPowerLevel() > b.getPowerLevel();
    if (success)
    {
        std::cout << "La tipo a è più forte del tipo b.\n";
    }
    else {
        std::cout << "Lo tipo b è più forte del tipo a.\n";
    }
    return success;
}

// Funzione principale
int main() {
    // Inventario di armi
    Inventario<Arma> inventarioArmi;
    inventarioArmi.addItem(Arma());
    inventarioArmi.listaItems();
    inventarioArmi.usaItem(0);

    // Inventario di pozioni
    Inventario<Pozione> inventarioPozioni;
    inventarioPozioni.addItem(Pozione());
    inventarioPozioni.listaItems();
    inventarioPozioni.usaItem(0);

    // Confronto tra oggetti di tipo diverso
    Arma spada;
    Arma pugnale;

    pugnale.setDanno(150);

    Pozione sciroppo;

    std::cout << "\nConfronto i livelli di potenza:\n";
    confrontaItems(spada, sciroppo);

    confrontaItems(spada, pugnale);

    spada.setDanno(180);

    confrontaItems(spada, pugnale);

    return 0;
}
