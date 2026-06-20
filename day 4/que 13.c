#include <stdio.h>
#include <stdlib.h>

// Function to generate Fibonacci series
void generateFibonacci(int n) {
    long long first = 0, second = 1, next;

    printf("Fibonacci Series: ");

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%lld", first);
        } else if (i == 1) {
            printf(", %lld", second);
        } else {
            next = first + second;
            printf(", %lld", next);
            first = second;
            second = next;
        }
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

    if (terms <= 0) {
        printf("Number of terms must be a positive integer.\n");
        return 1;
    }

    generateFibonacci(terms);

    return 0;
}



