/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Template                                                      |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */
 
#include <iostream>
#include <string>

// Parametric polymorphism: stessa logica per tipi diversi.
template<typename T>
T max_val(const T& a, const T& b) {
    return (a < b) ? b : a;// condizione, ritorna il massimo tra a e b
}

int main() {
    int mi = max_val(3, 7);  // istanziazione con T = int
    std::cout << "Restituisce il massimo tra due interi " << mi << std::endl;
    std::cin.get();
    
    double md = max_val(2.5, 1.2);      // istanziazione con T = double
    std::cout << "Restituisce il massimo tra due double " << md << std::endl;
    // Richiede che l'operatore < sia definito per T.
}