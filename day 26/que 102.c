#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check voting eligibility
void checkVotingEligibility(int age) {
    if (age < 0) {
        printf("Age cannot be negative.\n");
    } else if (age < 18) {
        printf("You are NOT eligible to vote. You must be at least 18 years old.\n");
    } else {
        printf("You ARE eligible to vote.\n");
    }
}

int main() {
    int age;
    char ch;

    printf("=== Voting Eligibility System ===\n");

    // Input loop for retry on invalid input
    while (1) {
        printf("Enter your age: ");

        // Validate integer input
        if (scanf("%d", &age) != 1) {
            printf("Invalid input. Please enter a valid integer.\n");

            // Clear invalid input from buffer
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        // Check eligibility
        checkVotingEligibility(age);
        break; // Exit loop after valid check
    }

    return 0;
}



















