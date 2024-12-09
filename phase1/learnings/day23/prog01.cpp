#include<iostream>
#include<string>
using namespace std;
class Animal{
public:
	void me(){
		cout << "me animal" << endl;
	}
};
class Dog:public Animal{
private:
	string name;
public:
	void mee(){
	cout << "me dog" << endl;
	}
	void setname( const string& e_name){
		name = e_name;
	}
	void display(){
		cout << name;
	}
};
int main(){
	Dog pup;
	pup.me();
	pup.mee();
	pup.setname("golu");
	pup.display();
}
