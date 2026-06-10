#include <stdio.h>

int main() {
    int n;

    // Input size of square
    printf("Enter the size of the square (>=2): ");
    if (scanf("%d", &n) != 1 || n < 2) {
        printf("Invalid input. Please enter an integer >= 2.\n");
        return 1;
    }

    // Loop through rows
    for (int i = 0; i < n; i++) {
        // Loop through columns
        for (int j = 0; j < n; j++) {
            // Print star for first/last row or first/last column
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n"); // Move to next row
    }

    return 0;
}






