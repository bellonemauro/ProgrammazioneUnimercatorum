/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Esempio template function                                     |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */
 
 #include <iostream>
#include <string>

template<typename T>
T mymax(T a, T b) {
    return (a > b) ? a : b;
}

class Punto {
public:
    int x, y;

    // Definisce come confrontare i punti
    bool operator>(const Punto& other) const {
        if (x != other.x) return x > other.x;
        return y > other.y;
    }
};

int main()
{
    int a = 5, b = 10;
    std::cout << mymax(a, b) << "\n";  // Output: 10

    std::string s1 = "apple", s2 = "banana";
    std::cout << mymax(s1, s2) << "\n";  // Output: banana

    Punto p = mymax(Punto{1,2}, Punto{3,4});
    std::cout << p.x << ", " << p.y << "\n";  // Output: 3, 4

    return 0;
}
