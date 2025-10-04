#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;

void incrementa() {
    for (int i = 0; i < 1000000; ++i)
      ++counter;
}

std::mutex mtx;

void incrementa_threadSafe() {
    for (int i = 0; i < 10000000; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++counter;
    }
}

int main() {
    std::thread t1(incrementa_threadSafe);
    std::thread t2(incrementa_threadSafe);
    std::thread t3(incrementa_threadSafe);
    t1.join();
    t2.join();
    t3.join();
    std::cout << "Counter: " 
              << counter << "\n";
}