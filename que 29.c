#include <stdio.h>

int main() {
    int rows;

    // Prompt user for number of rows
    printf("Enter the number of rows for the half pyramid: ");
    if (scanf("%d", &rows) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1; // Exit with error
    }

    // Validate positive number of rows
    if (rows <= 0) {
        printf("Number of rows must be greater than zero.\n");
        return 1;
    }

    // Print half pyramid
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
