#include <stdio.h>

int main() {
    int n;

    // Ask user for number of rows
    printf("Enter number of rows: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1; // Exit with error
    }

    // Outer loop for rows
    for (int i = n; i >= 1; i--) {
        // Inner loop for stars
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n"); // Move to next line after each row
    }

    return 0;
}




