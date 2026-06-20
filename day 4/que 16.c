#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

// Function to check if a number is an Armstrong number
int isArmstrong(int num) {
    if (num < 0) return 0; // Armstrong numbers are non-negative

    int originalNum = num;
    int digits = 0;
    int sum = 0;

    // Count digits
    int temp = num;
    while (temp != 0) {
        temp /= 10;
        digits++;
    }

    // Special case for 0
    if (num == 0) return 1;

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
    int start, end;

    printf("Enter the start and end of the range: ");
    if (scanf("%d %d", &start, &end) != 2) {
        printf("Invalid input. Please enter integers only.\n");
        return 1;
    }

    // Swap if start > end
    if (start > end) {
        int temp = start;
        start = end;
        end = temp;
    }

    printf("Armstrong numbers between %d and %d are:\n", start, end);
    int found = 0;
    for (int i = start; i <= end; i++) {
        if (isArmstrong(i)) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");

    return 0;
}




