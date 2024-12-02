#include <iostream>
#include <iomanip>
using namespace std;

#include "bookingmanager.h"
#include "const.h"
#include "global.h"
#include "menu.h"

void createBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int &numBookings) {
    if (numBookings >= MAX_BOOKINGS) {
        cout << "Error: Maximum booking limit reached.\n";
        return;
    }

    int ticketAmount, foodAmount;

    cout << "Enter Ticket Amount for the Booking ID "<< numBookings+1 <<": ";
    cin >> ticketAmount;
    cout << "Enter Food Amount "<< numBookings+1 <<": ";
    cin >> foodAmount;

    // Assign next available booking ID
    booking_ids[numBookings] = nextBookingID++;
    ticket_amounts[numBookings] = ticketAmount;
    food_amounts[numBookings] = foodAmount;
    numBookings++;

    cout << "Booking created successfully with ID: " << booking_ids[numBookings - 1] << "\n";
}


void displayBookings(const int booking_ids[], const int ticket_amounts[], const int food_amounts[], int numBookings) {
    if (numBookings == 0) {
        cout << "No bookings available to display.\n";
        return;
    }

    cout << "------------------------------------------------\n";
    cout << "| Booking ID | Ticket Amount | Food Amount    |\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < numBookings; i++) {
        cout << "| " << setw(10) << booking_ids[i] << " | "
             << setw(13) << ticket_amounts[i] << " | "
             << setw(14) << food_amounts[i] << " |\n";
    }
    cout << "------------------------------------------------\n";
}


int binarySearch(const int booking_ids[], int numBookings, int id) {
    int left = 0, right = numBookings - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (booking_ids[mid] == id) {
            return mid;
        } else if (booking_ids[mid] < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}


void editBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int numBookings) {
    int id;
    cout << "Enter Booking ID to edit: ";
    cin >> id;

    int index = binarySearch(booking_ids, numBookings, id);
    if (index == -1) {
        cout << "Error: Booking ID not found.\n";
        return;
    }

    cout << "Current Details - Ticket Amount: " << ticket_amounts[index] 
         << ", Food Amount: " << food_amounts[index] << "\n";

    cout << "Enter New Ticket Amount: ";
    cin >> ticket_amounts[index];
    cout << "Enter New Food Amount: ";
    cin >> food_amounts[index];

    cout << "Booking updated successfully.\n";
}



void deleteBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int &numBookings) {
    int id;
    cout << "Enter Booking ID to delete: ";
    cin >> id;

    int index = binarySearch(booking_ids, numBookings, id);
    if (index == -1) {
        cout << "Error: Booking ID not found.\n";
        return;
    }

    // Shift data to fill the gap
    for (int i = index; i < numBookings - 1; i++) {
        booking_ids[i] = booking_ids[i + 1];
        ticket_amounts[i] = ticket_amounts[i + 1];
        food_amounts[i] = food_amounts[i + 1];
    }
    numBookings--;

    cout << "Booking deleted successfully.\n";
}
