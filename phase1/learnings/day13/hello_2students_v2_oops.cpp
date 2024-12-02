#include<iostream>
#include<cstdlib>
using std::endl;
using std::cout;
using std::cin;

struct student{
	int id;
	char name[255];
};
void student_read(student& student);
void student_print(student& student);
int main()
{
	student student1 {};
	student student2 {};


	cout << "enter 1 " <<endl;
	student_read(student1);
	cout << "enter 2 " <<endl;
	student_read(student2);

	student_print(student1);
	student_print(student2);

	return EXIT_SUCCESS;
}

void student_read(student& student){
	cout << "enetr id " ;
	cin >> student.id;
	cout << "enter name ";
	cin >> student.name;
}

void student_print(student& student){
	cout << "hello " << student.name << " having id " <<student.id<< " !!!" <<endl;
}
