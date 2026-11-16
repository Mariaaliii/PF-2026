#include <stdio.h>
struct manageFlight {
    int flightNumber;
    char departure[50];
    char destination[50];
    char date[20];
    int availableSeats;
};
void displayFlight(struct manageFlight f) {
    printf("\nFlight Number: %d\n", f.flightNumber);
    printf("Departure City: %s\n", f.departure);
    printf("Destination City: %s\n", f.destination);
    printf("Date: %s\n", f.date);
    printf("Available Seats: %d\n", f.availableSeats);
}
void bookSeat(struct manageFlight *f) {
    if (f->availableSeats > 0) {
        f->availableSeats--;
        printf("Seat booked successfully!\n");
        printf("Remaining Seats: %d\n", f->availableSeats);
    } else {
        printf("Sorry! No seats available.\n");
    }
}
int main() {
    struct manageFlight F[3];
    int choice, searchNum, found, i;
    for (i = 0; i < 3; i++) {
        printf("\nEnter details for Flight %d:\n", i + 1);
        printf("Enter flight number: ");
        scanf("%d", &F[i].flightNumber);
        printf("Enter departure city: ");
        scanf("%s", F[i].departure);
        printf("Enter destination city: ");
        scanf("%s", F[i].destination);
        printf("Enter date: ");
        scanf("%s", F[i].date);
        printf("Enter available seats: ");
        scanf("%d", &F[i].availableSeats);
    }
    do {
        printf("\n=== Menu ===\n");
        printf("1. Display All Flights\n");
        printf("2. Book a Seat\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            for (i = 0; i < 3; i++) {
                displayFlight(F[i]);
            }
        }
        else if (choice == 2) {
            printf("Enter flight number to book seat: ");
            scanf("%d", &searchNum);
            found = 0;
            for (i = 0; i < 3; i++) {
                if (F[i].flightNumber == searchNum) {
                    bookSeat(&F[i]);
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                printf("Flight not found!\n");
            }
        }
    } while (choice != 3);
    printf("Program ended.\n");
    return 0;
}
