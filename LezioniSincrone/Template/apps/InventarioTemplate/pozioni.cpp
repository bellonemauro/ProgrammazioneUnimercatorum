#include <iostream>
#include <vector>


// Classe Pozione
class Pozione {
    int cura = 30;
public:
    void usa() const {
        std::cout << "Bevo la pozione!\n";
    }

    void descrivi() const {
        std::cout << "Una pozione magica. Cura: " << cura << "\n";
    }

    int getPowerLevel() const {
        return cura;
    }
};
