// #include <iostream>
// #include <string>

// using namespace std;

// class Animal{
//     public:
//         void Eat(){
//             cout << "eating ...." << endl;
//         }
// };

// class Mammal: virtual public Animal{
//     public:
//         void Walk(){
//             cout << "walking...." << endl;
//         }
// }; 

// class Bird:virtual public Animal{
//     public:
//     void Fly(){
//         cout << "flying...." << endl;
//     }
// };

// class Bat:public Mammal,public Bird{
//     public:
//         void Hang(){
//             cout << "hanging...." << endl;
//         }
// };

// int main(){
//     Bat b;
//     b.Hang();
//     b.Fly();
//     b.Walk();
//     b.Eat();

//     return 0;

// }

// ====================using constructor===================

#include <iostream>
#include <string>

using namespace std;

class Animal{
    protected:
        string name;
        int age;

    public:
        Animal(const string name,int age):name(name),age(age){

            cout << "animal constructor " << name<<"  " <<age << endl;
        }
        void Sound(){
            cout << name << "makes sound" << endl;
        }
        ~Animal(){
            cout << "destructor of animal " << name << endl;
        }
};

class Dog:public Animal{
    private:
       string breed;
       double weight;

    public:
        Dog(const string name, int age, const string breed, double weight):Animal(name,age),breed(breed),weight(weight){
            cout << "dog constructor " << name << endl;
        } 
        void sound(){
            cout << name << " barks"<<endl;
        }
        ~Dog(){
            cout << "dog destructor " << name << endl;
        }
};

int main(){
    Dog d("rex",2,"germen",5);
    d.sound();
}
