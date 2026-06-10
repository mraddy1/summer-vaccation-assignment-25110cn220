#include <stdio.h>
#include <stdlib.h>

// Function to find the nth Fibonacci number iteratively
unsigned long long fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    unsigned long long prev = 0, curr = 1, next;
    for (int i = 2; i <= n; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    int n;

    printf("Enter the term number (n): ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    // Limit check to prevent overflow for unsigned long long
    if (n > 92) {
        printf("Value too large. This program supports n up to 92.\n");
        return 1;
    }

    unsigned long long result = fibonacci(n);
    printf("The %d-th Fibonacci term is: %llu\n", n, result);

    return 0;
}




