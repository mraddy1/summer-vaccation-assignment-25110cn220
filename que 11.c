#include <stdio.h>
#include <stdlib.h> // For abs()

// Function to compute GCD using Euclidean algorithm
int gcd(int a, int b) {
    // Ensure both numbers are non-negative
    a = abs(a);
    b = abs(b);

    // Euclidean algorithm
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a; // GCD is always non-negative
}

int main() {
    int num1, num2;

    printf("Enter two integers: ");

    // Input validation
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input. Please enter integers only.\n");
        return 1; // Exit with error
    }

    // Special case: both numbers are zero
    if (num1 == 0 && num2 == 0) {
        printf("GCD is undefined for both numbers being zero.\n");
        return 0;
    }

    int result = gcd(num1, num2);
    printf("GCD of %d and %d is: %d\n", num1, num2, result);

    return 0;
}

