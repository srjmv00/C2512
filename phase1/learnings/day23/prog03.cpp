#include <iostream>
using namespace std;

class Animal{
    public:
        void Eat(){
            cout << "Eating...." << endl;
        }
};
class Dog:public Animal{
    public:
        void Bark(){
            cout << "Barking...." << endl;
        } 
};
class Pup:public Dog{
    public:
        void Weep(){
            cout << "Weeping...." <<endl;
        }
};

int main(){
    Pup jimmy;
    jimmy.Eat();
    jimmy.Bark();
    jimmy.Weep();

    return 0;
}