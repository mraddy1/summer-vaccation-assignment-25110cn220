#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to find the largest prime factor
long long largestPrimeFactor(long long n) {
    if (n <= 1) {
        return -1; // No prime factors for numbers <= 1
    }

    long long maxPrime = -1;

    // Remove all factors of 2
    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }

    // Remove all factors of 3
    while (n % 3 == 0) {
        maxPrime = 3;
        n /= 3;
    }

    // Check for factors of the form 6k ± 1
    for (long long i = 5; i * i <= n; i += 6) {
        while (n % i == 0) {
            maxPrime = i;
            n /= i;
        }
        while (n % (i + 2) == 0) {
            maxPrime = i + 2;
            n /= (i + 2);
        }
    }

    // If n is still > 4, then n itself is prime
    if (n > 4) {
        maxPrime = n;
    }

    return maxPrime;
}

int main() {
    long long num;

    printf("Enter a positive integer: ");
    if (scanf("%lld", &num) != 1 || num <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    long long result = largestPrimeFactor(num);

    if (result == -1) {
        printf("No prime factors found.\n");
    } else {
        printf("Largest prime factor of %lld is: %lld\n", num, result);
    }

    return 0;
}


