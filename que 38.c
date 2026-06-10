#include <stdio.h>

int main() {
    int rows;

    // Ask user for number of rows
    printf("Enter number of rows for the reverse pyramid: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // Loop for each row
    for (int i = 0; i < rows; i++) {
        // Print leading spaces
        for (int space = 0; space < i; space++) {
            printf(" ");
        }
        // Print stars
        for (int star = 0; star < (2 * (rows - i) - 1); star++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}







