/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Dinamic dispatch                                              |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */

 #include <iostream>
#include <string>
#include <memory>
#include <vector>

class Entita {
protected:
    float x{}, y{}; // posizione

public:
    Entita() = default;
    Entita(float x_, float y_) : x{x_}, y{y_} {}

    void muovi(float dx, float dy) noexcept {
        x += dx; y += dy;
        std::cout << "Entita' spostata a (" << x << ", " << y << ")\n";
    }

    virtual void visualizza() const = 0;
    virtual ~Entita() = default;
};

class Giocatore : public Entita {
    std::string nome;

public:
    Giocatore(std::string n, float x0 = 0.f, float y0 = 0.f)
        : Entita{x0, y0}, nome{std::move(n)} {}

    void attacca() {
        std::cout << nome << " attacca!\n";
    }

    void visualizza() const override {
        std::cout << "Giocatore \"" << nome << "\" @ (" << x << ", " << y << ")\n";
    }
};

class Automobile : public Entita {
    std::string nome;

public:
    Automobile(std::string n, float x0 = 0.f, float y0 = 0.f)
        : Entita{x0, y0}, nome{std::move(n)} {}

    void visualizza() const override {
        std::cout << "Automobile \"" << nome << "\" @ (" << x << ", " << y << ")\n";
    }
};


int main() {
    std::vector<std::unique_ptr<Entita>> scena;
    scena.push_back(std::make_unique<Giocatore>("Mauro", 1.f, 2.f));
    scena.push_back(std::make_unique<Automobile>("Panda", -3.f, 0.5f));
    
    std::cout << "Demo dynamic dispatch:" << std::endl;
    std::cin.get();

    for (auto& e : scena) {
        e->visualizza();    // dynamic dispatch: chiama la versione corretta
        e->muovi(0.5f, 0.0f);
        std::cout << "Premi invio per continuare" << std::endl;
        std::cin.get();
    }
}

