#include <stdio.h>

int main() {
    int n, i, j;

    // Ask user for number of rows
    printf("Enter number of rows (1-26): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 26) {
        printf("Invalid input. Please enter an integer between 1 and 26.\n");
        return 1;
    }

    // Outer loop for rows
    for (i = 1; i <= n; i++) {
        // Inner loop for characters in each row
        for (j = 0; j < i; j++) {
            printf("%c", 'A' + j); // Print letters starting from 'A'
        }
        printf("\n"); // Move to next line
    }

    return 0;
}


