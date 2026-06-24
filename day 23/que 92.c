#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000 // Maximum input string length

int main() {
    char str[MAX_LEN];
    int freq[256] = {0}; // Frequency array for all ASCII characters
    int i, maxFreq = 0;
    char maxChar = '\0';

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    // Count frequency of each character
    for (i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];
        freq[ch]++;
    }

    // Find the character with maximum frequency
    for (i = 0; i < 256; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = (char)i;
        }
    }

    if (maxFreq > 0) {
        printf("Maximum occurring character: '%c'\n", maxChar);
        printf("Frequency: %d\n", maxFreq);
    } else {
        printf("No characters found in the input.\n");
    }

    return 0;
}









