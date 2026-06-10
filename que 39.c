#include <stdio.h>

int main() {
    int n;

    // Prompt user for number of rows
    printf("Enter number of rows: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // Loop through each row
    for (int i = 1; i <= n; i++) {
        // Print leading spaces for pyramid alignment
        for (int space = 1; space <= n - i; space++) {
            printf(" ");
        }

        // Print increasing numbers from 1 to i
        for (int num = 1; num <= i; num++) {
            printf("%d", num);
        }

        // Print decreasing numbers from i-1 down to 1
        for (int num = i - 1; num >= 1; num--) {
            printf("%d", num);
        }

        // Move to next line
        printf("\n");
    }

    return 0;
}








