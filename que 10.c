#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false; // 0, 1, and negatives are not prime
    if (num == 2) return true;  // 2 is prime
    if (num % 2 == 0) return false; // Even numbers > 2 are not prime

    // Check divisors up to sqrt(num)
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int lower, upper;

    printf("Enter lower and upper range: ");
    if (scanf("%d %d", &lower, &upper) != 2) {
        printf("Invalid input. Please enter integers only.\n");
        return 1;
    }

    if (lower > upper) {
        printf("Invalid range. Lower bound must be <= upper bound.\n");
        return 1;
    }

    printf("Prime numbers between %d and %d are:\n", lower, upper);
    bool found = false;

    for (int num = lower; num <= upper; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
            found = true;
        }
    }

    if (!found) {
        printf("No prime numbers found in the given range.");
    }

    printf("\n");
    return 0;
}

