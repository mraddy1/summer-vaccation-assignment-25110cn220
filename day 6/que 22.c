#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to validate if the input string is a valid binary number
int isValidBinary(const char *bin) {
    for (int i = 0; bin[i] != '\0'; i++) {
        if (bin[i] != '0' && bin[i] != '1') {
            return 0; // Invalid character found
        }
    }
    return 1; // Valid binary
}

// Function to convert binary string to decimal integer
unsigned long long binaryToDecimal(const char *bin) {
    unsigned long long decimal = 0;
    for (int i = 0; bin[i] != '\0'; i++) {
        decimal = decimal * 2 + (bin[i] - '0');
    }
    return decimal;
}

int main() {
    char binary[65]; // Supports up to 64-bit binary numbers

    printf("Enter a binary number: ");
    if (scanf("%64s", binary) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Validate binary input
    if (!isValidBinary(binary)) {
        printf("Error: Input must contain only 0s and 1s.\n");
        return 1;
    }

    // Convert and display result
    unsigned long long decimal = binaryToDecimal(binary);
    printf("Decimal equivalent: %llu\n", decimal);

    return 0;
}



