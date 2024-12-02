#include<iostream>
#include<cstdlib>
using std::endl;
using std::cout;
using std::cin;

void student_read(int& id, char name[]);
void student_print(int& id, char name[]);
int main()
{
	int id1;
	char name1[255];

	int id2;
        char name2[255];


	cout << "enter 1 " <<endl;
	student_read(id1,name1);
	cout << "enter 2 " <<endl;
	student_read(id2,name2);

	student_print(id1,name1);
	student_print(id2,name2);

	return EXIT_SUCCESS;
}

void student_read(int& id, char name[]){
	cout << "enetr id " ;
	cin >> id;
	cout << "enter name ";
	cin >> name;
}

void student_print(int& id, char name[]){
	cout << "hello " << name << " having id " <<id<< " !!!" <<endl;
}
