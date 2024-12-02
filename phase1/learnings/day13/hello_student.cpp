#include<iostream>
#include<cstdlib>
using std::endl; 
using std::cout;
using std::cin;  

int main()
{
	int id;
	char name[255];

	cout << "enter the name" ;
	cin >> name;
	
	cout << "enter the id" ;
	cin >> id;

	std::cout << "hello " << name << " having id " << id << " !!! " <<endl;
	return EXIT_SUCCESS;
}


