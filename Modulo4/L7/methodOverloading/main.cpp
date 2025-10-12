/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Method overloading                                            |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */
 
#include <iostream>
#include <string>

// Stessa "interfaccia" concettuale: calcolare l'area.
// Implementazioni diverse selezionate a compile-time.
double area(double r) {            // cerchio
    return 3.141592653589793 * r * r;
}
double area(double base, double h) { // rettangolo
    return base * h;
}

int main() {
    auto a1 = area(1.5);     // chiama area(double)  -> cerchio
    std::cout << "L'area del cerchio di raggio 1.5 è " << a1 << std::endl;
    std::cin.get();
    
    auto a2 = area(3.0, 2.0); // chiama area(double,double) -> rettangolo
    std::cout << "L'area del rettangolo con base 3 e altezza 2 è " << a2 << std::endl;
}