#include<iostream>
using namespace std;

#include "menu.h"
#include "const.h"
#include "bookingmanager.h"

int main() {
    // Arrays to hold booking details
    int booking_ids[MAX_BOOKINGS] = {0};
    int ticket_amounts[MAX_BOOKINGS] = {0};
    int food_amounts[MAX_BOOKINGS] = {0};
    int numBookings = 0; // Counter for current bookings

    int choice; // User's menu choice

    do {
        printMenu(); // Display menu
        cout << "Enter your choice: ";
        cin >> choice;

        // Menu-driven functionality
        switch (choice) {
            case 1:
                createBooking(booking_ids, ticket_amounts, food_amounts, numBookings);
                break;
            case 2:
                displayBookings(booking_ids, ticket_amounts, food_amounts, numBookings);
                break;
            case 3:
                editBooking(booking_ids, ticket_amounts, food_amounts, numBookings);
                break;
            case 4:
                deleteBooking(booking_ids, ticket_amounts, food_amounts, numBookings);
                break;
            case 5:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
