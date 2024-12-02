#pragma once
// Function Prototypes

void createBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int &numBookings);
void displayBookings(const int booking_ids[], const int ticket_amounts[], const int food_amounts[], int numBookings);
int binarySearch(const int booking_ids[], int numBookings, int id);
void editBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int numBookings);
void deleteBooking(int booking_ids[], int ticket_amounts[], int food_amounts[], int &numBookings);
