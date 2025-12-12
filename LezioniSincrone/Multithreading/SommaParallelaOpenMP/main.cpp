/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Esempio Somma Parallela con OpenMP                            |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */
 
 #include <iostream>
#include <vector>
#include <numeric>
#include <future>
#include <chrono>
#include <omp.h>



long long somma_parallela(const std::vector<int>& data, int threads)
{
    // vettore di -future- tipo standard che indica che gli elementi saranno inizializzati in seguito
    std::vector<std::future<long long>> futures;
    size_t block = data.size() / threads; // divido i dati in blocchi per il numero di threads

    // per ogni blocco avvio un thread
    for (int t = 0; t < threads; ++t)
    {
        size_t start = t * block;
        size_t end = (t == threads - 1) ? data.size() : start + block;

        long long valore_inziale = 0;
        // 1. Lancia un nuovo thread asincrono che calcola
        //    la somma parziale di un blocco del vettore.
        std::future<long long> block_sum_value = std::async(
            std::launch::async,                 // forza l'esecuzione in un nuovo thread 
            [&, start, end] {                   // funzione lambda eseguita
                return std::accumulate(
                    data.begin() + start,       // inizio del blocco
                    data.begin() + end,         // fine del blocco 
                    valore_inziale              // valore iniziale
                );
            }
        );

        // 2. Store the future result in the vector of futures.
        //    We will later call future.get() to retrieve the partial sum.
        futures.push_back(std::move(block_sum_value));
    }

    // sommiamo tutti i componenti
    long long total = 0;
    for (auto& f : futures)
        total += f.get(); // NOTA: std::future<T>::get() Blocca il thread chiamante finché il risultato del task asincrono non è pronto.

    return total;
}

int main() {

    // vetore di dati
    std::vector<int> data(2'500'000'000, 1); //5'000'000'000 vedremo diverse performance
    // n_dati * n_byte = memoria_occupata
    
    {
        // accumulo usando la funzione standard std::accumulate che contiene solo un ciclo 
        auto t0 = std::chrono::high_resolution_clock::now();  // il tipo qua è std::chrono::time_point<std::chrono::high_resolution_clock>
        long long seq = std::accumulate(data.begin(), data.end(), 0LL);  // https://en.cppreference.com/w/cpp/algorithm/accumulate.html
        auto t1 = std::chrono::high_resolution_clock::now();
        std::cout << "Somma sequenziale: " << seq << '\n';
        std::cout << std::chrono::duration<double>(t1 - t0).count() << " s\n";
    }

    {
        // accumulo usando la funzione di somma parallela 
        auto t0 = std::chrono::high_resolution_clock::now();
        long long par = somma_parallela(data, 8);  // 16 è il numero di threads
        auto t1 = std::chrono::high_resolution_clock::now();
        std::cout << "Somma parallela:   " << par << '\n';
        std::cout << std::chrono::duration<double>(t1 - t0).count() << " s\n";

    }

    {
        long long sum = 0;
        auto t0 = std::chrono::high_resolution_clock::now();

#pragma omp parallel for reduction(+:sum)
        for (long long i = 0; i < data.size(); i++) {
            sum += data[i];
        }
        auto t1 = std::chrono::high_resolution_clock::now();
        std::cout << "Somma parallela con openMP:   " << sum << '\n';
        std::cout << std::chrono::duration<double>(t1 - t0).count() << " s\n";
    }
    // 1. #pragma omp parallel — crea i thread in openMP
    // 2. for — specifica l'operazione da parallelizzare sui thread 
    // 3. reduction(+:sum) — ogni thread avrà la sua copia dei dati (in questo caso sum)
    //   Il comando reduction indica che:
    //    -  ogni thread riceve la sua copia dei dati.
    //    -  Al termine del ciclo, OpenMP combinerà automaticamente il risultato usando l'operatore +.

}
