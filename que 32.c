#include <stdio.h>

int main() {
    int n = 5; // Number of rows in the pattern

    // Outer loop for rows
    for (int i = 1; i <= n; i++) {
        // Inner loop to print the number 'i', i times
        for (int j = 1; j <= i; j++) {
            printf("%d", i);
        }
        printf("\n"); // Move to the next line after each row
    }

    return 0;
}



