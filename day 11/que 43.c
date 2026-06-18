#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a number is prime
bool isPrime(int num) {
    // Prime numbers are greater than 1
    if (num <= 1) {
        return false;
    }

    // 2 and 3 are prime numbers
    if (num == 2 || num == 3) {
        return true;
    }

    // Eliminate even numbers and multiples of 3
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    // Check divisors from 5 to sqrt(num) using 6k ± 1 optimization
    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int number;

    printf("Enter an integer: ");
    // Validate input
    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    // Check and display result
    if (isPrime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0;
}


