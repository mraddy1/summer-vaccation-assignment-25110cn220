#include <stdio.h>
#include <stdlib.h>

// Function to find maximum between two integers
int findMax(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int num1, num2;

    printf("Enter two integers: ");
    // Validate input
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input. Please enter integers only.\n");
        return 1; // Exit with error
    }

    int maxValue = findMax(num1, num2);
    printf("Maximum of %d and %d is: %d\n", num1, num2, maxValue);

    return 0;
}

