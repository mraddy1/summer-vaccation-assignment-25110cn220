#include <stdio.h>

// Function to calculate power using Exponentiation by Squaring
double power(double base, int exponent) {
    double result = 1.0;
    int exp = exponent;

    // Handle negative exponents
    if (exp < 0) {
        base = 1.0 / base;
        exp = -exp;
    }

    // Fast exponentiation loop
    while (exp > 0) {
        if (exp % 2 == 1) { // If exponent is odd
            result *= base;
        }
        base *= base; // Square the base
        exp /= 2;     // Halve the exponent
    }

    return result;
}

int main() {
    double x;
    int n;

    printf("Enter base (x): ");
    if (scanf("%lf", &x) != 1) {
        printf("Invalid input for base.\n");
        return 1;
    }

    printf("Enter exponent (n): ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input for exponent.\n");
        return 1;
    }

    // Special case: 0^0 is undefined
    if (x == 0 && n == 0) {
        printf("0^0 is undefined.\n");
        return 1;
    }

    double result = power(x, n);
    printf("%.6lf^%d = %.6lf\n", x, n, result);

    return 0;
}




