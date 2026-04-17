#include <iostream>
#include <vector>

// Template di classe: inventario generico
template <typename T>
class Inventario {
private:
    std::vector<T> items;
public:
    void addItem(const T& item) {
        items.push_back(item);
    }

    void usaItem(int index) {
        if (index >= 0 && index < items.size()) {
            items[index].usa(); // T deve avere un metodo usa()
        }
    }

    void listaItems() const {
        for (const auto& item : items) {
            item.descrivi(); // T deve avere un metodo descrivi()
        }
    }
};


