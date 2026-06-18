#include <stdio.h>

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n < 0) {
        // Factorial is not defined for negative numbers
        return 0;
    }
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num;

    printf("Enter a non-negative integer: ");
    // Validate input
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    if (num < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return 1;
    }

    unsigned long long result = factorial(num);
    printf("Factorial of %d is: %llu\n", num, result);

    return 0;
}



