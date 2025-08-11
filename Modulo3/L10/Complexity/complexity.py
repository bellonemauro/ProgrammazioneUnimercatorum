#  +---------------------------------------------------------------------------+
#  |                                                                           |
#  |  Corso di Programmazione                                                  |
#  |  Tutorial : Esempio complessità computazionale                            |
#  |                                                                           |
#  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
#  |  Released under BDS License                                               |
#  |                                                                           |
#  +---------------------------------------------------------------------------+ 

import time
import math
import matplotlib.pyplot as plt
import numpy as np

# Definiamo degli algoritmi con complessità nota

def tempo_costante(n):
    return n + 1  # O(1)

def tempo_logaritmico(n):
    count = 0
    while n > 1:
        n = n // 2
        count += 1
    return count  # O(log n)

def tempo_nlogn(n):
    count = 0
    for i in range(n):  # ripeti n volte
        x = n
        while x > 1:
            x = x // 2
            count += 1
    return count  # O(n log n)

def tempo_lineare(n):
    total = 0
    for i in range(n):
        total += i
    return total  # O(n)

def tempo_quadratico(n):
    total = 0
    for i in range(n):
        for j in range(n):
            total += i * j
    return total  # O(n^2)

# Misuriamo il tempo di esecuzione
def misura_durata(func, input_sizes):
    times = []
    for n in input_sizes:
        start = time.perf_counter()
        func(n)
        end = time.perf_counter()
        times.append(end - start)
    return times

# Misuriamo il tempo di esecuzione
def misura_operazioni(func, input_sizes):
    operazioni = []
    for n in input_sizes:
        operazioni.append(func(n))
    return operazioni

# Dimensione dell'input
input_sizes = [2**i for i in range(4, 15)]  # da 16 a 16384


# Misuriamo tutte le fuzioni e inseriamo il risultato in una struttura dati
results = {
    #"O(1)": misura_operazioni(tempo_costante, input_sizes),
    "O(log n)": misura_operazioni(tempo_logaritmico, input_sizes),
    "O(nlog n)": misura_operazioni(tempo_nlogn, input_sizes),
    "O(n)": misura_operazioni(tempo_lineare, input_sizes),
    "O(n²)": misura_operazioni(tempo_quadratico, input_sizes[:9]),  # reduce size for n^2
}

# Plotting
plt.figure(figsize=(10, 6))
for label, times in results.items():
    trimmed_inputs = input_sizes if len(times) == len(input_sizes) else input_sizes[:len(times)]
    plt.plot(trimmed_inputs, times, label=label, marker='o')

plt.xlabel("Dimensione input (n)", fontsize=32)
#plt.ylabel("Tempo (seconds)", fontsize=22)
plt.ylabel("Operazioni #", fontsize=32)
#plt.title("Complessità algoritmica: Durata vs Dimensione input", fontsize=22)
plt.legend(fontsize=20)
plt.xticks(fontsize=20)
plt.yticks(fontsize=20)
plt.grid(True)
plt.tight_layout()
plt.show()

# Misuriamo tutte le fuzioni e inseriamo il risultato in una struttura dati
results = {
    "O(1)": misura_durata(tempo_costante, input_sizes),
    "O(log n)": misura_durata(tempo_logaritmico, input_sizes),
    "O(nlog n)": misura_durata(tempo_nlogn, input_sizes),
    "O(n)": misura_durata(tempo_lineare, input_sizes),
    "O(n²)": misura_durata(tempo_quadratico, input_sizes[:9]),  # reduce size for n^2
}

# Plotting
plt.figure(figsize=(10, 6))
for label, times in results.items():
    trimmed_inputs = input_sizes if len(times) == len(input_sizes) else input_sizes[:len(times)]
    plt.plot(trimmed_inputs, times, label=label, marker='o')

plt.xlabel("Dimensione input (n)", fontsize=32)
plt.ylabel("Tempo (seconds)", fontsize=22)
plt.legend(fontsize=20)
plt.xticks(fontsize=20)
plt.yticks(fontsize=20)
plt.grid(True)
plt.tight_layout()
plt.show()