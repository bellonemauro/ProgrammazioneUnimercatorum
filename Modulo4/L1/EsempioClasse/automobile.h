// automobile.h
#ifndef AUTOMOBILE_H  // Header guard per evitare inclusioni multiple
#define AUTOMOBILE_H

#include <string>
#include <iostream>

class Automobile {
private:
    std::string colore;
    std::string marca;
    int velocita;

public:
    // Costruttore
    Automobile(std::string colore, std::string marca);

    // Metodi
    void accelera(int incremento);
    void frena(int decremento);
    void suonaClacson();

    // Getter (const per sicurezza)
    std::string getColore() const;
    std::string getMarca() const;
    int getVelocita() const;
};

#endif // AUTOMOBILE_H