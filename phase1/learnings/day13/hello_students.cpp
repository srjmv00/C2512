#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

void student_read(int& id, char name[]);
void student_print(int& id, char name[]);

int main() {
	int N;
	cout << "Number of Students:"; cin >> N;

	int ids[N];
	char names[N][255];

	for(int I = 0; I < N; I++) {
		cout << "Enter " << (I+1) << " th student details." << endl;  student_read(ids[I], names[I]);
	}

	for(int I = 0; I < N; I++) {
		student_print(ids[I], names[I]); 
	}

	return EXIT_SUCCESS;
}

void student_read(int& id, char name[]) {
	cout << "Enter id:";
	cin >> id;
	cout << "Enter name:";
	cin >> name;
}

void student_print(int& id, char name[]) {
	cout << "Hello " << name << " of id " << id << "!!!" << endl;
}
