// automobile.cpp
#include "automobile.h"

// Costruttore
Automobile::Automobile(std::string colore, std::string marca) 
    : colore(colore), marca(marca), velocita(0) {}

// Metodi
void Automobile::accelera(int incremento) {
    velocita += incremento;
    std::cout << "Accelerazione! Velocita': " << velocita << " km/h\n";
}

void Automobile::frena(int decremento) {
    velocita -= decremento;
    if (velocita < 0) velocita = 0;
    std::cout << "Frenata! Velocita': " << velocita << " km/h\n";
}

void Automobile::suonaClacson() {
    std::cout << "Bip Bip! (" << marca << " ti saluta)\n";
}

// Getter
std::string Automobile::getColore() const { return colore; }
std::string Automobile::getMarca() const { return marca; }
int Automobile::getVelocita() const { return velocita; }