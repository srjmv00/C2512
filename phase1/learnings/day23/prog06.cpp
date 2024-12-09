#include <iostream>
#include <string>

// Base class Bird
class Bird {
public:
    void Sound() {
        std::cout << "Bird makes a sound..." << std::endl;
    }
};

// Derived class Crow
class Crow : public Bird {
public:
    // Override the Sound method for Crow
    void Sound() {
        std::cout << "Crow caws..." << std::endl;
    }
};

// Derived class Parrot
class Parrot : public Bird {
public:
    // Override the Sound method for Parrot
    void Sound() {
        std::cout << "Parrot squawks..." << std::endl;
    }
};

int main() {
    Bird bird;
    Crow crow;
    Parrot parrot;

    // Call Sound on each object
    bird.Sound();    // Calls Bird's Sound
    crow.Sound();    // Calls Crow's Sound
    parrot.Sound();  // Calls Parrot's Sound

    return 0;
}