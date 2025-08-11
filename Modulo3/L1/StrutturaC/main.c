/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Esempio definizione struttura studente                        |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */
 
#include <stdio.h>
#include <stdbool.h> 

// Definizione della struttura Studente
struct Studente {
    char nome[50];
    int matricola;
    float votoEsame;
    bool esameSuperato;
};

int main() {
    // Esempio di utilizzo
    struct Studente s1 = {"Luca Rossi", 123456, 28.5, true};

    printf("Nome: %s\n", s1.nome);
    printf("Matricola: %d\n", s1.matricola);
    printf("Voto Esame: %.1f\n", s1.votoEsame);
    printf("Esame Superato: %s\n", s1.esameSuperato ? "Sì" : "No");

}