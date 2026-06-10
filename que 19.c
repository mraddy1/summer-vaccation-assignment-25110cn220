#include <stdio.h>
#include <stdlib.h>

// Function to print all factors of a number
void printFactors(int n) {
    int absN = abs(n); // Factors are usually considered for absolute value
    printf("Factors of %d are: ", n);

    for (int i = 1; i <= absN; i++) {
        if (absN % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int num;

    printf("Enter an integer: ");
    // Validate input
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    // Special case: zero has infinite factors
    if (num == 0) {
        printf("0 has infinitely many factors.\n");
        return 0;
    }

    printFactors(num);

    return 0;
}

