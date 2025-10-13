/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Race condition                                                |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */ 

 #include <iostream>
#include <thread>
#include <mutex>

int counter = 0;

void incrementa() {
    for (int i = 0; i < 1000000; ++i)
      ++counter;
}


int main() {
    std::thread t1(incrementa);
    std::thread t2(incrementa);
    std::thread t3(incrementa);
    t1.join();
    t2.join();
    t3.join();
    std::cout << "Counter: " 
              << counter << "\n";

}