#include <stdio.h>

unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num;

    printf("Enter a non-negative integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } 
    else {
        unsigned long long result = factorial(num);
        printf("Factorial of %d = %llu\n", num, result);
    }

    return 0;
}
