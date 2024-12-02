#include <iostream>
#include <iomanip>

using namespace std;

// ---Const.h-----
const int MAX_SURGERYS = 100;

// ---Surgery.h-----
class Surgery {
    private:
        string SurgeryID;
		int Duration;
    public:
        bool GreaterThan(const Surgery& other);
        bool LessThan(const Surgery& other);
         //getters-setters
        string GetSurgeryID();
        int GetDuration();

    friend class SurgeryManager;
};

// ---SurgeryManager.cpp----
class SurgeryManager{
    friend class SurgeryAggregator;
    friend int main();
    private:
        Surgery surgerys[MAX_SURGERYS];
        int numSurgery;
    
    public:
        // support 
        int findIndexById(string SurgeryID);

        // behaviours
        void create();
        void displayAll();
        void editById();
        void deleteById();

        // constructor
        SurgeryManager();

};

class SurgeryAggregator {
    public:
        int findMin(SurgeryManager& manager);
        int findMax(SurgeryManager& manager);
        int findSecondMin(SurgeryManager& manager);
        int findSecondMax(SurgeryManager& manager);
};

// menu.h

void printMenu();

// main.cpp

int main(){
    SurgeryManager manager;
    SurgeryAggregator aggregator;

    int choice; //user choice

     do {
        printMenu(); // Display menu
        cout << "Enter your choice: ";
        cin >> choice;

        // Menu-driven functionality
        switch (choice) {
            case 1: manager.create();    break;
            case 2: manager.displayAll();  break;
            case 3: manager.editById();      break;
            case 4: manager.deleteById();    break;
            case 5: 
                std::cout << "Surgery with Min Duration: " 
                    << manager.surgerys[aggregator.findMin(manager)].GetSurgeryID() 
                    << " with Durations " 
                    << manager.surgerys[aggregator.findMin(manager)].GetDuration() 
                    << std::endl;
                break;
            case 6: 
                std::cout << "Surgery with Max Duration: " 
                    << manager.surgerys[aggregator.findMax(manager)].GetSurgeryID() 
                    << " with Durations " 
                    << manager.surgerys[aggregator.findMax(manager)].GetDuration() 
                    << std::endl;
                break;
            case 7: 
                std::cout << "Surgery with 2nd Min Duration: " 
                    << manager.surgerys[aggregator.findSecondMin(manager)].GetSurgeryID() 
                    << " with Durations " 
                    << manager.surgerys[aggregator.findSecondMin(manager)].GetDuration() 
                    << std::endl;
                break;
            case 8: 
                std::cout << "Surgery with 2nd Max Duration: " 
                    << manager.surgerys[aggregator.findSecondMax(manager)].GetSurgeryID() 
                    << " with Durations " 
                    << manager.surgerys[aggregator.findSecondMax(manager)].GetDuration() 
                    << std::endl;
                break;
            case 9:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 9);

    return 0;
}

// SurgeryManager.cpp

// Creates a new hospital duration and stores details in arrays. 

void SurgeryManager::create(){
    if (numSurgery >= MAX_SURGERYS) {
        cout << "Error: Maximum hospital duration limit reached.\n";
        return;
    }
    
    string SurgeryID;
    int Duration;

    cout << "Enter Surgery SurgeryID : ";
    cin >> SurgeryID;

    // Ensure Surgery SurgeryID is unique
    if (findIndexById(SurgeryID) != -1) {
        cout << "Error: Surgery SurgeryID already exists. Please use a unique SurgeryID.\n";
        return;
    }

    cout << "Enter Durations : ";
    cin >> Duration;

    surgerys[numSurgery].SurgeryID = SurgeryID;
    surgerys[numSurgery].Duration = Duration;
    numSurgery++;

    cout << "Surgery created successfully.\n";
}

//  brief Displays all existing surgerys in a tabular format.

    void SurgeryManager::displayAll() {
    if (numSurgery == 0){
        cout << "No Surgery available to display.\n";
        return;
    }

    cout << "------------------------- \n";
    cout << "|   SURGERYID | Duration |\n";
    cout << "--------------------------\n";
    for (int i = 0; i < numSurgery; i++) {
        cout << "| " << setw(10) <<     surgerys[i].SurgeryID << " | "
             << setw(9) << surgerys[i].Duration << " |\n";
    }
    cout << "--------------------------\n";
}

// Finds the index of a surgery duration by surgeryid.
// return Index of the surgery  if found, -1 otherwise.

int SurgeryManager::findIndexById(string SurgeryID) {
    for (int i = 0; i < numSurgery; i++) {
        if (surgerys[i].SurgeryID == SurgeryID) {
            return i;
        }
    }
    return -1;
}

// Edits an existing hospital duration by SurgeryID.

void SurgeryManager::editById() {
    string SurgeryID;
    cout << "Enter Surgery SurgeryID to edit: ";
    cin >> SurgeryID;

    int index = findIndexById(SurgeryID);
    if (index == -1) {
        cout << "Error: Surgery SurgeryID not found.\n";
        return;
    }

    cout << "Current Details - Duration: " << surgerys[index].Duration << "\n";

    cout << "Enter New Duration: ";
    cin >> surgerys[index].Duration;

    cout << "Surgey updated successfully.\n";
}

// Deletes an existing Surgery by SurgeryID.

void SurgeryManager::deleteById() {
    string SurgeryID;
    cout << "Enter Surgery SurgeryID to delete: ";
    cin >> SurgeryID;

    int index = findIndexById(SurgeryID);
    if (index == -1) {
        cout << "Error: Surgery SurgeryID not found.\n";
        return;
    }

    // Shift data to fill the gap
    for (int i = index; i < numSurgery - 1; i++) {
        surgerys[i] = surgerys[i + 1];
    }
    numSurgery--;

    cout << "Surgery deleted successfully.\n";
}

SurgeryManager::SurgeryManager() {
    numSurgery = 0;
}

// Menu.cpp
void printMenu() {
    cout << "\n=== Surgery Management Module ===\n";
    cout << "1. Create Surgery\n";
    cout << "2. Display All Surgery\n";
    cout << "3. Edit Surgery\n";
    cout << "4. Delete Surgery\n";
    cout << "5. Find Min Stay\n";
    cout << "6. Find Max Stay\n";
    cout << "7. Find Second Min Stay\n";
    cout << "8. Find Second Max Stay\n";
    cout << "9. Exit\n";
}

// Surgery.cpp

bool Surgery::GreaterThan(const Surgery& other)
{
    return (Duration > other.Duration);
}

bool Surgery::LessThan(const Surgery& other)
{
    return (Duration < other.Duration);
}

//getters-setters
string Surgery::GetSurgeryID()
{
    return SurgeryID;
}
int Surgery::GetDuration()
{
    return Duration;
}

// SurgeryAggregator.cpp


// Function to find the index of the Surgery with the minimum years of Stay
int SurgeryAggregator::findMin(SurgeryManager& manager) {
    Surgery* arr = manager.surgerys;
    int& n = manager.numSurgery;
    //
    int minIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i].LessThan(arr[minIndex])) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to find the index of the Surgery with the maximum years of Stay
int SurgeryAggregator::findMax(SurgeryManager& manager) {
    Surgery* arr = manager.surgerys;
    int& n = manager.numSurgery;
    //
    int maxIndex = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i].GreaterThan(arr[maxIndex])) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Function to find the index of the Surgery with the second minimum years of Stay
int SurgeryAggregator::findSecondMin(SurgeryManager& manager) {
    Surgery* arr = manager.surgerys;
    int& n = manager.numSurgery;
    //
    int minIndex = findMin(manager);
    int secondMinIndex = (minIndex == 0) ? 1 : 0;
    
    for (int i = 0; i < n; ++i) {
        if (i != minIndex) {
            if (arr[i].LessThan(arr[secondMinIndex])) {
                secondMinIndex = i;
            }
        }
    }
    return secondMinIndex;
}

// Function to find the index of the Surgery with the second maximum years of Stay
int SurgeryAggregator::findSecondMax(SurgeryManager& manager) {
    Surgery* arr = manager.surgerys;
    int& n = manager.numSurgery;
    //
    int maxIndex = findMax(manager);
    int secondMaxIndex = (maxIndex == 0) ? 1 : 0;
    
    for (int i = 0; i < n; ++i) {
        if (i != maxIndex) {
            if (arr[i].GreaterThan(arr[secondMaxIndex])) {
                secondMaxIndex = i;
            }
        }
    }
    return secondMaxIndex;
}