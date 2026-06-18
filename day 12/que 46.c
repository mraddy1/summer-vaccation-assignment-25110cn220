#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

// Function to check if a number is Armstrong
int isArmstrong(int num) {
    if (num < 0) {
        return 0; // Negative numbers are not Armstrong numbers
    }

    int originalNum = num;
    int sum = 0;
    int digits = 0;

    // Count digits
    int temp = num;
    while (temp != 0) {
        temp /= 10;
        digits++;
    }

    // Special case: 0 is considered Armstrong
    if (digits == 0) digits = 1;

    // Calculate sum of digits raised to the power of digits
    temp = num;
    while (temp != 0) {
        int digit = temp % 10;
        sum += (int)pow(digit, digits);
        temp /= 10;
    }

    return (sum == originalNum);
}

int main() {
    int number;

    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}





