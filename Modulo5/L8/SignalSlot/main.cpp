#include <iostream>
#include <functional>
#include <vector>

template <typename... Args>
class Signal {
public:
    using Slot = std::function<void(Args...)>;

    void connect(const Slot& slot) {
        slots.push_back(slot);
    }

    void emit(Args... args) {
        for (auto& slot : slots)
            slot(args...);
    }

private:
    std::vector<Slot> slots;
};


class Emitter {
public:
    Signal<int> valueChanged;   // Segnale

    void doWork() {
        int result = 42;
        valueChanged.emit(result); // Emette l'evento
    }
};


class Receiver {
public:
    void onValueChanged(int x) {
        std::cout << "Il ricevitore ha letto: " << x << "\n";
    }
};


int main() {
    Emitter emitter;
    Receiver receiver;

    // Connect the signal to the slot
    emitter.valueChanged.connect(
        [&](int v) { receiver.onValueChanged(v); }
    );
    
    // Trigger event
    emitter.doWork();
}
