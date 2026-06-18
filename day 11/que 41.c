#include <stdio.h>
#include <stdlib.h>

// Function to calculate sum of two integers
int sum(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2;

    printf("Enter two integers: ");

    // Validate input to ensure integers are entered
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input. Please enter integers only.\n");
        return 1; // Exit with error code
    }

    // Call the sum function and display result
    int result = sum(num1, num2);
    printf("Sum of %d and %d is: %d\n", num1, num2, result);

    return 0; // Successful execution
}
