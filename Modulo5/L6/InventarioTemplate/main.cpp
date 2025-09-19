#include <iostream>
#include <vector>

// Template di classe: inventario generico
template <typename T>
class Inventario {
private:
    std::vector<T> items;
public:
    void addItem(const T& item) {
        items.push_back(item);
    }

    void usaItem(int index) {
        if (index >= 0 && index < items.size()) {
            items[index].usa(); // T deve avere un metodo usa()
        }
    }

    void listaItems() const {
        for (const auto& item : items) {
            item.descrivi(); // T deve avere un metodo descrivi()
        }
    }
};

// Classe Weapon con metodi richiesti
class Arma {
    int danno = 50;
public:
    void usa() const {
        std::cout << "Attacca usando un'arma!\n";
    }

    void descrivi() const {
        std::cout << "Una spada. Danno: " << danno << "\n";
    }

    int getPowerLevel() const {
        return danno;
    }
};

// Classe Pozione con metodi richiesti
class Pozione {
    int cura = 30;
public:
    void usa() const {
        std::cout << "Prendo la pozione!\n";
    }

    void descrivi() const {
        std::cout << "Una pozione magica. Cura: " << cura << "\n";
    }

    int getPowerLevel() const {
        return cura;
    }
};

// Template di funzione: confronto tra oggetti di tipo diverso
template <typename T1, typename T2>
bool confrontaItems(const T1& a, const T2& b) {
    return a.getPowerLevel() > b.getPowerLevel();
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
    Pozione sciroppo;

    std::cout << "\nConfronto i livelli di potenza:\n";
    if (confrontaItems(spada, sciroppo)) {
        std::cout << "La spada è più forte dello sciroppo.\n";
    } else {
        std::cout << "Lo sciroppo è più forte della spada.\n";
    }

    return 0;
}
