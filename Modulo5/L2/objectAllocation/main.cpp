#include <iostream>
#include <string>

class Giocatore {
    std::string nome;
    int salute;

public:
    Giocatore(const std::string& n, int s) : nome(n), salute(s) {
        std::cout << "Costruttore: " << nome << "\n";
    }

    ~Giocatore() {
        std::cout << "Distruttore: " << nome << "\n";
    }

    void stampa() const {
        std::cout << "Giocatore: " << nome << ", Salute: " << salute << "\n";
    }
};

int main() {
    const int N = 3;

    std::cout << "\n=== Stack: oggetti locali ===\n";
    for (int i = 0; i < N; ++i) {
        Giocatore g("StackPlayer" + std::to_string(i), 100 + i);
        g.stampa();
        // Distruttore chiamato automaticamente a fine iterazione
    }
    std::cout<<"Premi invio per continuare" << std::endl;
    std::cin.get();

    std::cout << "\n=== Heap: oggetti con new (senza delete!) ===\n";
    for (int i = 0; i < N; ++i) {
        Giocatore* g = new Giocatore("HeapPlayer" + std::to_string(i), 200 + i);
        g->stampa();
        // delete g; //  Commentato per memory leak
    }

    std::cout << "\nFine del programma.\n";
    return 0;
}