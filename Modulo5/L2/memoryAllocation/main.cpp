/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Esempio creazione di un puntatore                             |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */

#include <iostream>
#include <memory>
#include <string>

int main() {
     int* array = (int*)malloc(10 * sizeof(int));
     if (array == NULL) {
         printf("Errore di allocazione\n");
         return 0;
     }
 
     int* array_calloc = (int*)calloc(10, sizeof(int));
     if (array_calloc == NULL) {
         printf("Errore di allocazione\n");
         return 0;
     }
 
     for (int i = 0; i < 10; i++) {
         printf("Indirizzo %p inizializzato a %d \n", &array[i], array[i]);
     }
 
     for (int i = 0; i < 10; i++) {
         printf("Indirizzo %p inizializzato a %d \n", &array_calloc[i], array_calloc[i]);
     }
 
     free(array);  
     free(array_calloc); 
 }
//
//#include <iostream>
//#include <memory>
//#include <string>
//
//class GameEntity {
//    int* data;
//public:
//    GameEntity(const std::string& nome) : nome_(nome) {
//        data = new int[3*1024*768];
//        //std::cout << "Entity " << nome_ << " creata.\n";
//    }
//
//    ~GameEntity() {
//        //std::cout << "Entity " << nome_ << " distrutta.\n";
//        delete data;
//    }
//
//    void update() {
//        //std::cout << "Updating " << nome_ << ".\n";
//    }
//
//private:
//    std::string nome_;
//};
//
//int main()
//{
//    int num_players = 1000;
//    for (int i = 0; i < num_players; i++)
//    {
//        // Creazione di un'entità con ownership esclusiva
//        std::unique_ptr<GameEntity> play_safe =
//            std::make_unique<GameEntity>("Safe");
//
//
//        // Uso delle entità
//        play_safe->update();
//    }
//    // qua il distruttore di player viene chiamato 
//    // automaticamente per play_safe
//    std::cout << "Giocatori correttamente creati e usati. Premi invio" << std::endl;
//    std::cin.get();
//
//    for (int i = 0; i < num_players; i++)
//    {
//        // Creazione di un'entità con il metodo classico
//        GameEntity* play_leak = new GameEntity("Leak");
//
//        play_leak->update();
//        // delete play_leak; 
//        // se la linea precedente non è chiamata esplicitamente 
//        // si ha un memory leak
//    }
//
//    std::cout << "Giocatori correttamente creati e usati" << std::endl;
//
//    return 0;
//}




//#include <stdio.h>
//#include <stdlib.h>
//
//
//int main() {
//
//	int valore = 7;
//	int* prt_valore = &valore;
//
//	printf("Il mio puntatore %p\n", prt_valore);
//	printf("Il mio valore %d\n", valore);
//
//	// deferenziazione 
//	*prt_valore = 9;
//	printf("Il mio valore %d\n", valore);
//}



















