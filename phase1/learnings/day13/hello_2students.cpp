#include<iostream>
#include<cstdlib>
using std::endl; 
using std::cout;
using std::cin;  

int main()
{
	int id1;
	char name1[255];
	
	int id2;
        char name2[255];


	cout << "enter the name1 " ;
	cin >> name1;
	
	cout << "enter the id2 " ;
	cin >> id1;

	cout << "enter the name2 " ;
        cin >> name2;

        cout << "enter the id2 " ;
        cin >> id2;
	std::cout << "hello " << name1 << " having id " << id1 << " !!! " <<endl;
	std::cout << "hello " << name2 << " having id " << id2 << " !!! " <<endl;
	
	return EXIT_SUCCESS;
}



