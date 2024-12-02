#include<iostream>
#include<cstdlib>
using std::endl; 
using std::cout;
using std::cin;  

struct student {
	int id;
	char name[255];
};

int main()
{
	student student1;
	student student2;

	cout << "enter the name1 " ;
	cin >> student1.name;

	cout << "enter the id2 " ;
	cin >> student1.id;

	cout << "enter the name2 " ;
        cin >> student2.name;

        cout << "enter the id2 " ;
        cin >> student2.id;
	cout << "hello " << student1.name << " having id " << student1.id << " !!! " <<endl;
	cout << "hello " << student2.name << " having id " << student2.id << " !!! " <<endl;

	return EXIT_SUCCESS;
}



