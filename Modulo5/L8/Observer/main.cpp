
// Esempio ispirato e modificato da https://www.geeksforgeeks.org/system-design/observer-pattern-c-design-patterns/
#include <iostream>
#include <algorithm>
#include <vector>

class Subject;   
class Observer {
protected:
    Subject* subject = nullptr;

public:
    Observer(Subject* s) : subject(s) {}
    virtual ~Observer();

    virtual void update(float temperature, float humidity, float pressure) = 0;
};

class Subject {
public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() {}
};


class WeatherStation : public Subject {
private:
    std::vector<Observer*> observers;
    float temperature, humidity, pressure;

public:
    void registerObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() override {
        for (Observer* observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
        std::cout << " \n Tutti gli osservatori attivi sono aggiornati \n\n\n"; 
    }

    void setMeasurements(float temp, float hum, float pres) {
        temperature = temp;
        humidity = hum;
        pressure = pres;
        notifyObservers(); // Invia la notifica
    }
};

class Display : public Observer {
private: 
    std::string name;
public:
    Display(Subject* s) : Observer(s) {}
    void setName(std::string _name) {name = _name;}
    void update(float temperature, float humidity, float pressure) override {
        std::cout << "Display " << name << ":\n  Temperatura = " << temperature
                  << "°C, \n  Umidità = " << humidity
                  << "%, \n  Pressione = " << pressure << " hPa\n";
    }
    

};


Observer::~Observer() {
    if (subject) {
        subject->removeObserver(this);
    }
}

int main() {
    WeatherStation station;

    Display display1(&station);
    display1.setName("D1");
    {
        Display display2(&station);
        display2.setName("D2");
        
        {
            Display display3(&station);
            display3.setName("D3");
        
            station.registerObserver(&display1);
            station.registerObserver(&display2);
            station.registerObserver(&display3);
            
            // Primo update 
            station.setMeasurements(24.5, 65.0, 1013.9);
        }
    
        // Secondo update 
        station.setMeasurements(25.5, 60.0, 1013.2);
    }
    // Terzo update
    station.setMeasurements(24.8, 58.0, 1014.5);

    return 0;
} 