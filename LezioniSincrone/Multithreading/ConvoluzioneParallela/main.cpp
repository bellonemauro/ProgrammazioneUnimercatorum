/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Esempio Benchmark convoluzione parallela                      |
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


void convoluzione_sequenziale(
    const std::vector<float>& in,  // verttore in input
    const std::vector<float>& K,   // kernel 
    std::vector<float>& out)       // vettore in output
{
    size_t n = in.size();
    for (size_t i = 1; i < n - 1; ++i) 
    {
        out[i] = in[i - 1] * K[0] +
                 in[i]     * K[1] +
                 in[i + 1] * K[2];
    }
}


void convoluzione_sequenziale_in_blocchi(
    const std::vector<float>& in,  // verttore in input
    const std::vector<float>& K,   // kernel 
    std::vector<float>& out,       // vettore in output
    size_t start,
    size_t end)
{
    for (size_t i = start; i < end; ++i) {
        out[i] = in[i - 1] * K[0] +
                 in[i] * K[1] +
                 in[i + 1] * K[2];
    }
}


void convoluzione_con_thread(
    const std::vector<float>& in,  // verttore in input
    const std::vector<float>& K,   // kernel 
    std::vector<float>& out,       // vettore in output
    unsigned num_threads)
{
    size_t n = in.size();
    size_t block = n / num_threads;

    std::vector<std::thread> threads;
    threads.reserve(num_threads);

    for (unsigned t = 0; t < num_threads; ++t) 
    {
        size_t start = 1 + t * block;
        size_t end = (t == num_threads - 1) ?
            (n - 1) : (start + block);

        threads.emplace_back(  // costruisce un nuovo std::thread all’interno del vettore, passando i parametri al costruttore di std::thread.
            convoluzione_sequenziale_in_blocchi,  // puntatore alla funzione da eseguire nel thread
            //NOTA: Per impostazione predefinita, std::thread copia gli argomenti, mandiamo i riferimenti espliciti
            std::cref(in),  // passa in per riferimento costante(const&).
            std::cref(K),   // 
            std::ref(out),  // passa out per riferimento non-const (&) --> il thread scrive qua!
            start,          // inizio del blocco
            end             // fine del blocco
        );
    }

    // questo ciclo termina al termine dell'ultimo thread
    for (auto& th : threads) {
        th.join();
    }
}




void convoluzione_openmp(const std::vector<float>& B,
    const std::vector<float>& K,
    std::vector<float>& A)
{
    size_t n = B.size();

#pragma omp parallel for
    for (long long i = 1; i < (long long)n - 1; ++i) {
        A[i] = B[i - 1] * K[0] +
               B[i] *     K[1] +
               B[i + 1] * K[2];
    }
}


int main() {

    
    // Setup large input
    const size_t N = 1'000'000'000;  
    

    std::cout << "Dimensione del vettore: " << N << "\n";
    std::cout << "Esecuzione sequenziale ... " << "\n";

    // Esecuzione sequenziale
    {
        std::vector<float> V(N, 1.0f);   // vettore su cui effettuare la confoluzione
        std::vector<float> kernel = { 0.25f, 0.5f, 0.25f };
        std::vector<float> risultato(N, 0.0f);

        std::fill(risultato.begin(), risultato.end(), 0.0f);

        auto start = std::chrono::high_resolution_clock::now();
        convoluzione_sequenziale(V, kernel, risultato);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff = end - start;
        std::cout << "Durata: " << diff.count() << " secondi\n\n";
    }


    // Threaded 
    unsigned num_threads = std::thread::hardware_concurrency(); // uso il massimo numero di threads disponibili
    std::cout << "Esecuzione parallela ... " << "\n"; 
    std::cout << "Uso " << num_threads << " threads\n";
    {
        std::vector<float> V(N, 1.0f);   // vettore su cui effettuare la confoluzione
        std::vector<float> kernel = { 0.25f, 0.5f, 0.25f };
        std::vector<float> risultato(N, 0.0f);

        std::fill(risultato.begin(), risultato.end(), 0.f);

        auto t1 = std::chrono::high_resolution_clock::now();
        convoluzione_con_thread(V, kernel, risultato, num_threads);
        auto t2 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> d = t2 - t1;
        std::cout << "Durata con std::thread: " << d.count() << " secondi\n\n";
    }


    // OpenMP 
    std::cout << "Esecuzione con OpenMP ... " << "\n";
    std::cout << "Uso " << omp_get_max_threads() << " threads\n\n";
    {
        std::vector<float> V(N, 1.0f);   // vettore su cui effettuare la confoluzione
        std::vector<float> kernel = { 0.25f, 0.5f, 0.25f };
        std::vector<float> risultato(N, 0.0f);

        std::fill(risultato.begin(), risultato.end(), 0.0f);

        auto start = std::chrono::high_resolution_clock::now();
        convoluzione_openmp(V, kernel, risultato);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff = end - start;
        std::cout << "Durata con OpenMP:     " << diff.count() << " secondi\n";
    }

}

