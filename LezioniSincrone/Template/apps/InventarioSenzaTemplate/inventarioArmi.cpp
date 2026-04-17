#pragma once
#include <iostream>
#include <vector>

#include "armi.cpp"

// Inventario per Arma
class InventarioArmi {
private:
    std::vector<Arma> items;
public:
    void addItem(const Arma& item) {
        items.push_back(item);
    }

    void usaItem(int index) {
        if (index >= 0 && index < items.size()) {
            items[index].usa();
        }
    }

    void listaItems() const {
        for (const auto& item : items) {
            item.descrivi();
        }
    }
};
