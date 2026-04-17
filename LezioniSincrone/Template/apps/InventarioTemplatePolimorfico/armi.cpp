#include <iostream>
#include <vector>
#include <memory> // Per smart pointer


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
