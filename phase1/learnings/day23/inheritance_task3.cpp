//Problem 14: `Appliance and Refrigerator`
//- `Base Class:` `Appliance`  
//- Fields: `brand`, `powerConsumption`  
//- Pure Virtual Behaviors: `turnOn()`, `turnOff()`.  

#include <iostream>
#include <cstring>
using namespace std;


class Appliance {
protected:
    char* brand;             
    float powerConsumption;   

public:
    Appliance(const char* b, float power) {
        brand = new char[strlen(b) + 1];
        strcpy(brand, b);
        powerConsumption = power;
        cout << "Appliance constructor...." << endl;
    }

    virtual ~Appliance() {
        delete[] brand;
        cout << "Appliance destructor...." << endl;
    }

    virtual void turnOn() const = 0;
    virtual void turnOff() const = 0;

    virtual void display() const {
        cout << "Brand: " << brand << ", Power Consumption: " << powerConsumption << " watts" << endl;
    }
};

class Refrigerator : public Appliance {
private:
    float capacity;  
    char* doorType; 
public:
    Refrigerator(const char* b, float power, float cap, const char* door)
        : Appliance(b, power), capacity(cap) {
        doorType = new char[strlen(door) + 1];
        strcpy(doorType, door);
        cout << "Refrigerator constructor...."<< endl;
    }

    ~Refrigerator() override {
        delete[] doorType;
        cout << "Refrigerator destructor...." << endl;
    }

    // Override pure virtual functions
    void turnOn() const override {
        cout << "Refrigerator is now ON...." << endl;
    }

    void turnOff() const override {
        cout << "Refrigerator is now OFF...." << endl;
    }

    void display() const override {
        Appliance::display();
        cout << "Capacity: " << capacity << " liters, Door Type: " << doorType << endl;
    }
};

//one two dynamic/static objects of the Derived class 
//pointed by base class pointer
//and call all behaviours using Base class pointer 

int main() {
    Appliance* ref1 = new Refrigerator("Samsung", 150, 350, "Double Door");
    Appliance* ref2 = new Refrigerator("LG", 120, 300, "Single Door");

    cout << "Details of Refrigerator 1:" << endl;
    ref1->display();
    ref1->turnOn();
    ref1->turnOff();

    cout << "\nDetails of Refrigerator 2:" << endl;
    ref2->display();
    ref2->turnOn();
    ref2->turnOff();

    delete ref1;
    delete ref2;

    return 0;
}
