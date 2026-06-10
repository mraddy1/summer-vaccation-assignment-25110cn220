#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false; // 0, 1, and negative numbers are not prime
    }
    if (n == 2) {
        return true; // 2 is the only even prime number
    }
    if (n % 2 == 0) {
        return false; // Even numbers greater than 2 are not prime
    }

    // Check divisors from 3 to sqrt(n), skipping even numbers
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;

    printf("Enter an integer: ");
    // Validate input
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    // Check and display result
    if (isPrime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}
