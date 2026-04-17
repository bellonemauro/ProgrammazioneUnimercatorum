#include <iostream>
#include <vector>
#include <memory> // Per smart pointer

#include "inventario.cpp"
#include "armi.cpp"
#include "pozioni.cpp"


// Template di funzione: confronto tra oggetti
template <typename T1, typename T2>
bool confrontaItems(const T1& a, const T2& b) {
    return a.getPowerLevel() > b.getPowerLevel();
}

// Funzione principale
int main() {
    Inventario<Arma> inventarioArmi;

    inventarioArmi.addItem(std::make_shared<Spada>());
    inventarioArmi.addItem(std::make_shared<Lancia>());

    std::cout << "Listiamo le armi:\n";
    inventarioArmi.listaItems();

    std::cout << "\nUsiamo le armi:\n";
    inventarioArmi.usaItem(0);
    inventarioArmi.usaItem(1);

    std::cout << "\nConfrontiamo le armi:\n";
    Spada spada;
    Lancia lancia;

    if (confrontaItems(spada, lancia)) {
        std::cout << "La spada è più forte della lancia.\n";
    }
    else {
        std::cout << "La lancia è più forte della spada.\n";
    }

    // Inventario di pozioni
    Inventario<Pozione> inventarioPozioni;
    inventarioPozioni.addItem(std::make_shared<Erba>());
    inventarioPozioni.addItem(std::make_shared<Vaccino>());

    std::cout << "\nLista delle pozioni:\n";
    inventarioPozioni.listaItems();

    std::cout << "\nUsiamo le pozioni:\n";
    inventarioPozioni.usaItem(0);
    inventarioPozioni.usaItem(1);

    Vaccino vaccino;
    Erba erba;

    std::cout << "\nConfrontiamo le pozioni:\n";
    if (confrontaItems(erba, vaccino)) {
        std::cout << "L'erba è più forte del vaccino.\n";
    }
    else {
        std::cout << "Il vaccino è più forte dell'erba.\n";
    }

    std::cout << "\nConfronto oggetti diversi:\n";
    if (confrontaItems(spada, vaccino)) {
        std::cout << "La spada è più forte del vaccino.\n";
    }
    else {
        std::cout << "Il vaccino è più forte della spada.\n";
    }

    return 0;
}