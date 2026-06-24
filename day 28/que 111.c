#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 20
#define NAME_LEN 50

// Structure to store passenger details
typedef struct {
    int seatNumber;
    char name[NAME_LEN];
    int booked; // 0 = available, 1 = booked
} Seat;

// Function prototypes
void initializeSeats(Seat seats[]);
void displaySeats(Seat seats[]);
void bookTicket(Seat seats[]);
void cancelTicket(Seat seats[]);
void viewPassengerList(Seat seats[]);

int main() {
    Seat seats[MAX_SEATS];
    int choice;

    initializeSeats(seats);

    while (1) {
        printf("\n===== Ticket Booking System =====\n");
        printf("1. View Available Seats\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. View Passenger List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                displaySeats(seats);
                break;
            case 2:
                bookTicket(seats);
                break;
            case 3:
                cancelTicket(seats);
                break;
            case 4:
                viewPassengerList(seats);
                break;
            case 5:
                printf("Exiting... Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Initialize all seats as available
void initializeSeats(Seat seats[]) {
    for (int i = 0; i < MAX_SEATS; i++) {
        seats[i].seatNumber = i + 1;
        seats[i].booked = 0;
        strcpy(seats[i].name, "");
    }
}

// Display available seats
void displaySeats(Seat seats[]) {
    printf("\nAvailable Seats:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (!seats[i].booked) {
            printf("Seat %d\t", seats[i].seatNumber);
        }
    }
    printf("\n");
}

// Book a ticket
void bookTicket(Seat seats[]) {
    int seatNum;
    char name[NAME_LEN];

    printf("Enter seat number to book (1-%d): ", MAX_SEATS);
    if (scanf("%d", &seatNum) != 1 || seatNum < 1 || seatNum > MAX_SEATS) {
        printf("Invalid seat number!\n");
        while (getchar() != '\n');
        return;
    }

    if (seats[seatNum - 1].booked) {
        printf("Seat %d is already booked!\n", seatNum);
        return;
    }

    printf("Enter passenger name: ");
    while (getchar() != '\n'); // clear buffer
    fgets(name, NAME_LEN, stdin);
    name[strcspn(name, "\n")] = '\0'; // remove newline

    seats[seatNum - 1].booked = 1;
    strcpy(seats[seatNum - 1].name, name);

    printf("Ticket booked successfully for %s (Seat %d)\n", name, seatNum);
}

// Cancel a ticket
void cancelTicket(Seat seats[]) {
    int seatNum;

    printf("Enter seat number to cancel (1-%d): ", MAX_SEATS);
    if (scanf("%d", &seatNum) != 1 || seatNum < 1 || seatNum > MAX_SEATS) {
        printf("Invalid seat number!\n");
        while (getchar() != '\n');
        return;
    }

    if (!seats[seatNum - 1].booked) {
        printf("Seat %d is not booked!\n", seatNum);
        return;
    }

    seats[seatNum - 1].booked = 0;
    strcpy(seats[seatNum - 1].name, "");

    printf("Booking for seat %d has been cancelled.\n", seatNum);
}

// View passenger list
void viewPassengerList(Seat seats[]) {
    printf("\nPassenger List:\n");
    int found = 0;
    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i].booked) {
            printf("Seat %d: %s\n", seats[i].seatNumber, seats[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No passengers booked yet.\n");
    }
}




























