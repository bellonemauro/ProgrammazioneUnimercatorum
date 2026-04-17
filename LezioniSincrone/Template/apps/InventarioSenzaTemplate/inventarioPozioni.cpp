#pragma once
#include <iostream>
#include <vector>

#include "pozioni.cpp"

// Inventario per Potion
class InventarioPozioni{
private:
    std::vector<Pozione> items;
public:
    void addItem(const Pozione& item) {
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

