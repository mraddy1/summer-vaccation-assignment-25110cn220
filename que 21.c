#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary and print it
void decimalToBinary(int num) {
    // Special case for zero
    if (num == 0) {
        printf("Binary: 0\n");
        return;
    }

    unsigned int absNum = (num < 0) ? -num : num; // Handle negatives
    int binary[32]; // Array to store binary digits (max 32 bits for int)
    int index = 0;

    // Conversion logic
    while (absNum > 0) {
        binary[index++] = absNum % 2;
        absNum /= 2;
    }

    // Print sign for negative numbers
    if (num < 0) {
        printf("Binary (magnitude): -");
    } else {
        printf("Binary: ");
    }

    // Print binary in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main() {
    int decimal;

    printf("Enter a decimal number: ");
    // Input validation
    if (scanf("%d", &decimal) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    decimalToBinary(decimal);

    return 0;
}


