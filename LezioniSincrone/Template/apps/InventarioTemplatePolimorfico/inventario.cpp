#include <iostream>
#include <vector>
#include <memory> // Per smart pointer

// Template di classe: inventario generico
template <typename T>
class Inventario {
private:
    std::vector<std::shared_ptr<T>> items;
public:
    void addItem(std::shared_ptr<T> item) {
        items.push_back(item);
    }

    void usaItem(int index) {
        if (index >= 0 && index < items.size()) {
            items[index]->usa(); // uso polimorfico
        }
    }

    void listaItems() const {
        for (const auto& item : items) {
            item->descrivi(); // uso polimorfico
        }
    }
};