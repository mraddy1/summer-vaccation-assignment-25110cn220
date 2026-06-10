#include <stdio.h>

int main() {
    int rows;

    // Ask user for number of rows
    printf("Enter number of rows: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1; // Exit with error
    }

    // Outer loop for rows
    for (int i = 1; i <= rows; i++) {
        // Inner loop for printing numbers from 1 to i
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n"); // Move to next line after each row
    }

    return 0;
}

