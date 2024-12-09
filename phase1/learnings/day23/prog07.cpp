// #include <iostream>
// #include <string>

// // Base class Bird
// class Bird {
// public:
//     // Declare Sound as a virtual function
//     virtual void Sound() {
//         std::cout << "Bird makes a sound..." << std::endl;
//     }
// };

// // Derived class Crow
// class Crow : public Bird {
// public:
//     // Override the Sound method for Crow
//     void Sound() override {
//         std::cout << "Crow caws..." << std::endl;
//     }
// };

// // Derived class Parrot
// class Parrot : public Bird {
// public:
//     // Override the Sound method for Parrot
//     void Sound() override {
//         std::cout << "Parrot squawks..." << std::endl;
//     }
// };

// int main(){
//    Bird* bird = new Bird();
//    Bird* crow = new Crow();
//    Bird* parrot = new Parrot();

//    bird -> Sound(); 
//    crow -> Sound(); 
//    parrot -> Sound(); 

//    delete bird;
//    delete crow;
//    delete parrot;

//    return 0;
// }

