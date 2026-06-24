#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000  // Maximum string length

// Function to find the first non-repeating character
char firstNonRepeatingChar(const char *str) {
    int freq[256] = {0}; // Frequency array for all ASCII characters
    int len = strlen(str);

    // Count frequency of each character
    for (int i = 0; i < len; i++) {
        unsigned char ch = (unsigned char)str[i];
        freq[ch]++;
    }

    // Find the first character with frequency 1
    for (int i = 0; i < len; i++) {
        unsigned char ch = (unsigned char)str[i];
        if (freq[ch] == 1) {
            return ch;
        }
    }

    return '\0'; // Return null character if no non-repeating character found
}

int main() {
    char str[MAX_LEN];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline character if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Validate non-empty input
    if (strlen(str) == 0) {
        printf("Empty string entered.\n");
        return 1;
    }

    char result = firstNonRepeatingChar(str);

    if (result != '\0') {
        printf("First non-repeating character: '%c'\n", result);
    } else {
        printf("No non-repeating character found.\n");
    }

    return 0;
}







