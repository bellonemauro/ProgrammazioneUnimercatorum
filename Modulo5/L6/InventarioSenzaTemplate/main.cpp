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

// Classe Arma
class Arma {
    int danno = 50;
public:
    void usa() const {
        std::cout << "Attacco!\n";
    }

    void descrivi() const {
        std::cout << "Attaco tramite spada. Danno: " << danno << "\n";
    }

    int getPowerLevel() const {
        return danno;
    }
};

// Classe Pozione
class Pozione {
    int cura = 30;
public:
    void usa() const {
        std::cout << "Bevo la pozione!\n";
    }

    void descrivi() const {
        std::cout << "Una pozione magica. Cura: " << cura << "\n";
    }

    int getPowerLevel() const {
        return cura;
    }
};

// Inventario per Arma
class InventarioArmi {
private:
    std::vector<Arma> items;
public:
    void addItem(const Arma& item) {
        items.push_back(item);
    }

    void usaItem(int index) {
        if (index >= 0 && index < items.size()) {
            items[index].usa();
        }
    }

    void listaItems() const {
        for (const auto& item : items) {
            item.descrivi();
        }
    }
};

// Inventario per Potion
class InventarioPozioni{
private:
    std::vector<Pozione> items;
public:
    void addItem(const Pozione& item) {
        items.push_back(item);
    }

    void usaItem(int index) {
        if (index >= 0 && index < items.size()) {
            items[index].usa();
        }
    }

    void listaItems() const {
        for (const auto& item : items) {
            item.descrivi();
        }
    }
};

// Funzione di confronto tra Weapon e Potion
bool confrontaItems(const Arma& a, const Pozione& p) {
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
