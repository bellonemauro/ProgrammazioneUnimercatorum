#include <iostream>
#include <vector>
#include <memory> // Per smart pointer

// Template di classe: inventario generico
template <typename T>
class Inventario {
private:
    std::vector<std::shared_ptr<T>> items;
public:
    void addItem(std::shared_ptr<T> item) {
        items.push_back(item);
    }

    void usaItem(int index) {
        if (index >= 0 && index < items.size()) {
            items[index]->usa(); // uso polimorfico
        }
    }

    void listaItems() const {
        for (const auto& item : items) {
            item->descrivi(); // uso polimorfico
        }
    }
};


// Classe base Weapon con metodi virtuali
class Arma {
protected:
    int danno;
public:
    Arma(int dmg) : danno(dmg) {}
    virtual ~Arma() = default;

    virtual void usa() const {
        std::cout << "Uso un'arma generica. Danno: " << danno << "\n";
    }

    virtual void descrivi() const {
        std::cout << "Arma generica.\n";
    }

    virtual int getPowerLevel() const {
        return danno;
    }
};

// Classe derivata Spada
class Spada : public Arma {
public:
    Spada() : Arma(50) {}

    void usa() const override {
        std::cout << "Uso la spada! Danno: " << danno << "\n";
    }

    void descrivi() const override {
        std::cout << "Una forte spada.\n";
    }
};

// Classe derivata Lancia
class Lancia : public Arma {
public:
    Lancia() : Arma(40) {}

    void usa() const override {
        std::cout << "Lancio la lancia! Danno: " << danno << "\n";
    }

    void descrivi() const override {
        std::cout << "Una lunga lancia.\n";
    }
};



// Classe base Pozione con metodi virtuali
class Pozione {
protected:
    int cura;
public:
    Pozione(int hlg) : cura(hlg) {}
    virtual ~Pozione() = default;

    virtual void usa() const {
        std::cout << "Sto usando una pozione magica. Cura: " << cura << "\n";
    }

    virtual void descrivi() const {
        std::cout << "Pozione generica.\n";
    }

    virtual int getPowerLevel() const {
        return cura;
    }
};

// Classe derivata Potion
class Erba : public Pozione {
public:
    Erba() : Pozione(20) {}

    void usa() const override {
        std::cout << "Prendo l'erba magica! Cura: " << cura << "\n";
    }

    void descrivi() const override {
        std::cout << "Questa è un'erba magica.\n";
    }
};

// Classe derivata Potion
class Vaccino : public Pozione {
public:
    Vaccino() : Pozione(100) {}

    void usa() const override {
        std::cout << "Vaccinazione! cura e immunità: " << cura << "\n";
    }

    void descrivi() const override {
        std::cout << "Un vaccino.\n";
    }
};

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
    } else {
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
    } else {
        std::cout << "Il vaccino è più forte dell'erba.\n";
    }
    
    std::cout << "\nConfronto oggetti diversi:\n";
    if (confrontaItems(spada, vaccino)) {
        std::cout << "La spada è più forte del vaccino.\n";
    } else {
        std::cout << "Il vaccino è più forte della spada.\n";
    }

    return 0;
}
