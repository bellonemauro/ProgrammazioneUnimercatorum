#pragma once
#ifndef ARMI
#define ARMI

#include <iostream>
#include <vector>

// Classe Arma
class Arma {
    int danno = 50;
public:
    void usa() const {
        std::cout << "Attacco!\n";
    }

    void descrivi() const {
        std::cout << "Attaco tramite spada. Danno: " << danno << "\n";
    }

    void setDanno(int _danno) { danno = _danno; }

    int getPowerLevel() const {
        return danno;
    }
};

#endif // !ARMI
