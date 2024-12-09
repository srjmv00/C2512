#include<iostream>
using namespace std;

class Animal{
    public:
        void Eat(){
            cout << "animal eating" << endl;
        }
};

class Mammal:public Animal{
    public:
        void Walk(){
            cout << "mammal walking" << endl;
        }
};
class Bird:public Animal{
    public:
        void Fly(){
            cout << "bird flying" << endl;
        }
};

int main(){
    Mammal dog;
    dog.Eat();
    dog.Walk();

    Bird crow;
    crow.Eat();
    crow.Fly();
    
    return 0;
}