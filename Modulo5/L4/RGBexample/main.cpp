/*  +---------------------------------------------------------------------------+
 *  |                                                                           |
 *  |  Corso di Programmazione                                                  |
 *  |  Tutorial : Esempio allocazione e passaggio immagine RGB per riferimento  |
 *  |                                                                           |
 *  |  Autore: Mauro Bellone, https://www.maurobellone.com                      |
 *  |  Released under BDS License                                               |
 *  |                                                                           |
 *  +---------------------------------------------------------------------------+ */
 
 #include <iostream>
#include <chrono>
#include <algorithm>
#include <iomanip>  

class RGBImage {
private:
    int width;
    int height;
    int* data;

public:
    RGBImage(int w, int h) : width(w), height(h) {
        data = new int[3 * width * height];
        std::fill(data, data + 3 * width * height, 100);  // inizializzazione a grigio medio
    }

    RGBImage(const RGBImage& other) : width(other.width), height(other.height) {
        data = new int[3 * width * height];
        std::copy(other.data, other.data + 3 * width * height, data);
    }
    
    ~RGBImage() {
        delete[] data;
    }
};

class ImageFilter {
public:
    static void increaseBrightnessByValue(RGBImage img, int delta) {
        std::cout << "Eseguo la mia funzione sulla copia" << std::endl;
    }

    static void increaseBrightnessByPointer(RGBImage* img, int delta) {
        std::cout << "Eseguo la mia funzione sul puntatore" << std::endl;
    }
};

int main() {
    // 352×240
    // 720×576
    // 1024 x 768
    // full hd 1920x1080
    // immagine 4k 3840×2160
    
    const int width [5] = {352, 720, 1024, 1920, 3840}; 
    const int height [5] = {240, 576, 768, 1080, 2160};

    for (int i = 0; i<5; i++)
    {
        std::cout << "Lavoro con immagini " << width[i] << " x " << height[i] << std::endl;
        RGBImage imgStack(width[i], height[i]);
        RGBImage* imgHeap = new RGBImage(width[1], height[i]);
    
        // Misura tempo con passaggio per valore (copia)
        auto startValue = std::chrono::high_resolution_clock::now();
        ImageFilter::increaseBrightnessByValue(imgStack, 10);
        auto endValue = std::chrono::high_resolution_clock::now();
    
        std::cout << std::fixed << std::setprecision(10)
                  << "Tempo con passaggio per valore (copia): \n"
                  << std::chrono::duration<double>(endValue - startValue).count()
                  << " secondi \n" << std::endl;
    
        // Misura tempo con passaggio per puntatore (senza copia)
        auto startPointer = std::chrono::high_resolution_clock::now();
        ImageFilter::increaseBrightnessByPointer(imgHeap, 10);
        auto endPointer = std::chrono::high_resolution_clock::now();
    
        std::cout << std::fixed << std::setprecision(10)
                  << "Tempo con passaggio per puntatore: \n"
                  << std::chrono::duration<double>(endPointer - startPointer).count()
                  << " secondi \n\n" << std::endl;
    
        delete imgHeap;
    }
    return 0;
}