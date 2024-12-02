#include<iostream>
#include<cstdlib>
using std::endl; 
using std::cout;
using std::cin;  

int main()
{
	char name[255];
	cout << "enter the name" ;
	cin >> name;
	std::cout << "hello" << name << " !!! " <<endl;
	return EXIT_SUCCESS;
}


