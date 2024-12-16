// //1.4 
//     // replace dynamic fields as smart pointers 
//     // prove that Employee virtual destructor is not needed.
//     // create the dynamic programmer object assigned to employee smart pointer

// #include <iostream>
// #include <algorithm>
// #include <string>
// using namespace std;
// #include<memory>
// #include<vector>

// class Employee {
// public:
//     unique_ptr<int>id;
//     unique_ptr<int>age;
//     unique_ptr<string>name;

// public:
//     Employee(int v_id, int v_age, string v_name):id(make_unique<id>(v_id),age(make_unique<int>(v_age),name(make_unique<string>(v_name)))){ 
//     }

//     virtual void printDetails() {
//         cout << *id << " " << *age << " " << *name; 
//     }

//     virtual void swap(Employee& other) {
//         std::swap(id, other.id);  
//         std::swap(age, other.age);
//         std::swap(name, other.name);
//     }

//     friend ostream& operator<<(ostream& os,Employee& );
// };


// class Programmer : public Employee {
// public:
//     unique_ptr<string[]>tasks;
//     unique_ptr<int>taskCount;  

// public:
//     Programmer(int v_id, int v_age, string v_name, string* v_tasks, int v_taskCount)
//         : Employee(v_id, v_age, v_name), taskCount(make_unique<int>(v_taskCount)) {
//         tasks = make_unique<string[]>(taskCount);   
//         for (int i = 0; i < taskCount; i++) {
//             tasks[i] = v_tasks[i];  
//         }
//     }

//     void swap(Programmer& other){
//         std::swap(tasks, other.tasks);
//         std::swap(taskCount, other.taskCount);
        
//         Employee::swap(other);
//     }

//     void printDetails() override {
//         Employee::printDetails(); 
//         cout << " Tasks: ";
//         for (int i = 0; i < taskCount; i++) {
//             cout << tasks[i]<<" ";  
//         }
//     }

//     friend ostream& operator<<(ostream& os, Programmer& );
// };

// ostream& operator<<(ostream& os, Employee& e) {
//     e.printDetails();
//     return os; 
// }

// ostream& operator<<(ostream& os,Programmer& p) {
//     p.printDetails();
//     return os;  
// }

// int main() {
//     // Create task array for Programmer 1
//     string tasks1[] = {"Task10", "Task11", "Task12"};
//     unique_ptr <Employee> p1 = make_unique <Programmer>(101, 22, "Athira", tasks1, 3);

//     // Create task array for Programmer 2
//     string tasks2[] = {"Task20", "Task21", "Task22"};
//    unique_ptr<Employee> p2 = make_unique <Programmer> (102, 23, "Bhagya", tasks2, 3);

//     cout << "p1: " << *p1 << endl;  
//     cout << "p2: " << *p2 << endl; 

//     p1->swap(*p2);

//     cout << "after swap" << endl;
//     cout << "p1: " << *p1 << endl;  
//     cout << "p2: " << *p2 << endl;  

//     return 0;
// }


#include <iostream>
#include <algorithm>
#include <string>
#include <memory>  // For smart pointers
#include <vector>  // For vector
using namespace std;

class Employee {
public:
    unique_ptr<int> id;      // Using unique_ptr for dynamic id
    unique_ptr<int> age;     // Using unique_ptr for dynamic age
    unique_ptr<string> name; // Using unique_ptr for dynamic name

public:
    Employee(int v_id, int v_age, string v_name)
        : id(make_unique<int>(v_id)), age(make_unique<int>(v_age)), name(make_unique<string>(v_name)) {}

    virtual void printDetails() const {
        cout << *id << " " << *age << " " << *name;
    }

    virtual void swap(Employee& other) {
        using std::swap;
        swap(id, other.id);
        swap(age, other.age);
        swap(name, other.name);
    }

    friend ostream& operator<<(ostream& os, const Employee& e);
};

class Programmer : public Employee {
public:
    unique_ptr<string[]> tasks;  // Using unique_ptr for dynamic array of tasks
    int taskCount;               // Number of tasks

public:
    Programmer(int v_id, int v_age, string v_name, string* v_tasks, int v_taskCount)
        : Employee(v_id, v_age, v_name), taskCount(v_taskCount) {
        tasks = make_unique<string[]>(taskCount);
        for (int i = 0; i < taskCount; ++i) {
            tasks[i] = v_tasks[i];  // Assign each task to the dynamically allocated array
        }
    }

    void swap(Programmer& other) {
        using std::swap;
        swap(tasks, other.tasks);
        swap(taskCount, other.taskCount);
        
        Employee::swap(other);
    }

    void printDetails() const override {
        Employee::printDetails();
        cout << " Tasks: ";
        for (int i = 0; i < taskCount; ++i) {
            cout << tasks[i] << " ";
        }
    }

    friend ostream& operator<<(ostream& os, const Programmer& p);
};

ostream& operator<<(ostream& os, const Employee& e) {
    e.printDetails();
    return os;  // Return the ostream object to allow chaining
}

ostream& operator<<(ostream& os, const Programmer& p) {
    p.printDetails();
    return os;  // Return the ostream object to allow chaining
}

int main() {
    // Create task array for Programmer 1
    string tasks1[] = {"Task1", "Task2", "Task3"};
    unique_ptr<Employee> p1 = make_unique<Programmer>(101, 22, "Athira", tasks1, 3);

    // Create task array for Programmer 2
    string tasks2[] = {"TaskA", "TaskB", "TaskC"};
    unique_ptr<Employee> p2 = make_unique<Programmer>(102, 23, "Bhagya", tasks2, 3);

    cout << "p1: " << *p1 << endl;  // Output: 101 22 Athira Tasks: Task1 Task2 Task3
    cout << "p2: " << *p2 << endl;  // Output: 102 23 Bhagya Tasks: TaskA TaskB TaskC

    p1->swap(*p2);  // Swap p1 and p2

    cout << "after swap" << endl;
    cout << "p1: " << *p1 << endl;  // Output: 102 23 Bhagya Tasks: TaskA TaskB TaskC
    cout << "p2: " << *p2 << endl;  // Output: 101 22 Athira Tasks: Task1 Task2 Task3

    // No need to manually delete objects, smart pointers handle cleanup automatically

    return 0;
}
