// main.cpp
#include "automobile.h"

int main() {
    // Creazione oggetto
    Automobile miaAuto("Rosso", "Ferrari");

    // Utilizzo
    std::cout << "La mia " << miaAuto.getColore() << " " 
              << miaAuto.getMarca() << " è pronta!\n";
    miaAuto.accelera(50);
    miaAuto.suonaClacson();
    miaAuto.frena(20);

    return 0;
}