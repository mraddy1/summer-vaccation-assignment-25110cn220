#include <stdio.h>
#include <stdlib.h>

// Recursive helper function to reverse digits
int reverseHelper(int num, int rev) {
    if (num == 0) {
        return rev; // Base case: return the reversed number
    }
    return reverseHelper(num / 10, rev * 10 + num % 10);
}

// Main reverse function that handles negatives
int reverseNumber(int num) {
    int isNegative = (num < 0);
    num = abs(num); // Work with positive equivalent
    int reversed = reverseHelper(num, 0);
    return isNegative ? -reversed : reversed;
}

int main() {
    int num;

    printf("Enter an integer: ");
    // Input validation
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    int reversed = reverseNumber(num);
    printf("Reversed number: %d\n", reversed);

    return 0;
}







