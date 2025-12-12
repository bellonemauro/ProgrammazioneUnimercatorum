#include <iostream>
#include <functional>
#include <string_view>
#include <vector>

using Handler = std::function<void(int, std::string_view)>;

struct EventBus {
    std::vector<Handler> handlers;

    void on(Handler h) { handlers.push_back(std::move(h)); }

    void emit(int code, std::string_view payload) {
        for (auto& h : handlers)
            h(code, payload);
    }
};

void print_handler(int code, std::string_view p) {
    std::cout << "code= " << code << " payload= " << p << '\n';
}

int main() {
    EventBus bus;
    
    // come puntatore a funzione
    bus.on ( &print_handler);
    
    // in stile funzione lambda
    bus.on([](int c, std::string_view p) {
        std::cout << "Lambda - code= " << c << " payload= " << p << "\n"; 
    });
    
    bus.emit(1, "tick");
}