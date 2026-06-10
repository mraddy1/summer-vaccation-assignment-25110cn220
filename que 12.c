#include <stdio.h>
#include <stdlib.h> // for abs()

// Function to compute GCD using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return abs(a); // GCD is always positive
}

// Function to compute LCM
int lcm(int a, int b) {
    if (a == 0 || b == 0) {
        return 0; // LCM involving zero is zero
    }
    return abs(a * b) / gcd(a, b);
}

int main() {
    int num1, num2;

    printf("Enter two integers: ");
    // Input validation
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input! Please enter integers only.\n");
        return 1;
    }

    int result = lcm(num1, num2);
    printf("LCM of %d and %d is: %d\n", num1, num2, result);

    return 0;
}


