#include <stdio.h>
#include <stdlib.h>

// Recursive function to calculate sum of digits
int sumOfDigits(int n) {
    // Convert negative numbers to positive
    if (n < 0) {
        n = -n;
    }

    // Base case: single digit
    if (n < 10) {
        return n;
    }

    // Recursive case: last digit + sum of remaining digits
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    long long num; // Support large numbers

    printf("Enter an integer: ");
    // Input validation
    if (scanf("%lld", &num) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    int result = sumOfDigits((int)num);
    printf("Sum of digits of %lld is: %d\n", num, result);

    return 0;
}






