#include <iostream>
#include <vector>
#include <memory> // Per smart pointer


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
