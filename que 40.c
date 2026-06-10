#include <stdio.h>
#include <ctype.h> // for toupper()

// Function to print the character pyramid
void printCharPyramid(int rows) {
    if (rows <= 0 || rows > 26) { // Limit to alphabet size
        printf("Error: Rows must be between 1 and 26.\n");
        return;
    }

    for (int i = 1; i <= rows; i++) {
        // Print leading spaces
        for (int space = 1; space <= rows - i; space++) {
            printf(" ");
        }

        // Print ascending characters
        for (char ch = 'A'; ch < 'A' + i; ch++) {
            printf("%c", ch);
        }

        // Print descending characters
        for (char ch = 'A' + i - 2; ch >= 'A'; ch--) {
            printf("%c", ch);
        }

        printf("\n");
    }
}

int main() {
    int rows;

    printf("Enter number of rows (1-26): ");
    if (scanf("%d", &rows) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    printCharPyramid(rows);

    return 0;
}









