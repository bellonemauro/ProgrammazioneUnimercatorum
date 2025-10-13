#include <iostream>
#include <memory>
#include <string>

class GameEntity {
public:
    GameEntity(const std::string& name) : name(name) {
        std::cout << "Costruito GameEntity: " << name << "\n";
    }
    void greet() const {
        std::cout << "Ciao, sono " << name << "\n";
    }
    ~GameEntity() {
        std::cout << "Distrutto GameEntity: " << name << "\n";
    }
private:
    std::string name;
};

class GameEntityWrapper {
public:
    GameEntityWrapper() : ptr(std::make_unique<GameEntity>("Default")) {}
    GameEntityWrapper(const std::string& name) : ptr(std::make_unique<GameEntity>(name)) {}

    GameEntity* operator->() { return ptr.get(); }
    const GameEntity* operator->() const { return ptr.get(); }

    GameEntity& operator*() { return *ptr; }
    const GameEntity& operator*() const { return *ptr; }

private:
    std::unique_ptr<GameEntity> ptr;
};

int main() {
    GameEntityWrapper p("Alice");
    p->greet();
    (*p).greet();
    return 0;
}