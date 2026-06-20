#include <stdio.h>
#include <stdlib.h>

// Recursive function to calculate nth Fibonacci number
long long fibonacci(int n) {
    if (n == 0) return 0; // Base case
    if (n == 1) return 1; // Base case
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

int main() {
    int terms;

    // Ask user for number of terms
    printf("Enter the number of terms in Fibonacci series: ");
    if (scanf("%d", &terms) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    // Validate input
    if (terms < 0) {
        printf("Number of terms cannot be negative.\n");
        return 1;
    }

    printf("Fibonacci Series (%d terms):\n", terms);
    for (int i = 0; i < terms; i++) {
        printf("%lld ", fibonacci(i));
    }
    printf("\n");

    return 0;
}






