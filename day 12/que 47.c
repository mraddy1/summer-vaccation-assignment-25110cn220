#include <stdio.h>
#include <stdlib.h>

// Function to print Fibonacci series up to n terms
void fibonacci(int n) {
    if (n <= 0) {
        printf("Number of terms must be positive.\n");
        return;
    }

    long long first = 0, second = 1; // Use long long for larger values
    printf("Fibonacci Series: ");

    for (int i = 1; i <= n; i++) {
        printf("%lld", first);
        if (i < n) printf(", "); // Formatting

        long long next = first + second;
        first = second;
        second = next;
    }
    printf("\n");
}

int main() {
    int terms;

    printf("Enter the number of terms: ");
    if (scanf("%d", &terms) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    fibonacci(terms);

    return 0;
}





