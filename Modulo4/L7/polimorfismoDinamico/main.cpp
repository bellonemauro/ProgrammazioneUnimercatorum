/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Polimorfismo dinamico                                         |
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
    Entita(float x_ = 0.f, float y_ = 0.f) : x{x_}, y{y_} {}

    virtual void muovi(float dx, float dy) noexcept {
        x += dx; y += dy;
        std::cout << "[Base] Entita' spostata a (" << x << ", " << y << ")\n";
    }

    virtual void visualizza() const = 0; // metodo polimorfico puro
    virtual ~Entita() = default;
};

class Giocatore : public Entita {
    std::string nome;

public:
    Giocatore(std::string n, float x0 = 0.f, float y0 = 0.f)
        : Entita{x0, y0}, nome{std::move(n)} {}

    void attacca() const {
        std::cout << nome << " attacca!\n";
    }

    void visualizza() const override {
        std::cout << "[Giocatore] \"" << nome << "\" @ (" << x << ", " << y << ")\n";
    }

    void muovi(float dx, float dy) noexcept override {
        x += dx; y += dy;
        std::cout << "[Giocatore] si muove a (" << x << ", " << y << ")\n";
    }
};

class Automobile : public Entita {
    std::string modello;

public:
    Automobile(std::string m, float x0 = 0.f, float y0 = 0.f)
        : Entita{x0, y0}, modello{std::move(m)} {}

    void visualizza() const override {
        std::cout << "[Auto] \"" << modello << "\" @ (" << x << ", " << y << ")\n";
    }
};

class Nemico : public Entita {
    int livello;

public:
    Nemico(int lvl, float x0 = 0.f, float y0 = 0.f)
        : Entita{x0, y0}, livello{lvl} {}

    void visualizza() const override {
        std::cout << "[Nemico] livello " << livello << " @ (" << x << ", " << y << ")\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Entita>> scena;
    scena.push_back(std::make_unique<Giocatore>("Mauro", 1.f, 2.f));
    scena.push_back(std::make_unique<Automobile>("Panda", -3.f, 0.5f));
    scena.push_back(std::make_unique<Nemico>(5, 0.f, -1.f));

    std::cout << "=== Demo Polimorfismo Dinamico ===\n";

    for (auto& e : scena) {
        e->visualizza();    // dynamic dispatch
        e->muovi(0.5f, 0.0f); // override dimostrato
        std::cout << "-----------------------------\n";
    }
}