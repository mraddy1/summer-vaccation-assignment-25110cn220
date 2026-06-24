#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LEN 1000  // Maximum string length

// Function to check if two strings are anagrams
bool areAnagrams(const char *str1, const char *str2) {
    int count[256] = {0}; // ASCII character frequency table

    // Count frequency from first string
    for (int i = 0; str1[i] != '\0'; i++) {
        if (!isspace((unsigned char)str1[i])) { // Ignore spaces
            count[tolower((unsigned char)str1[i])]++; // Case-insensitive
        }
    }

    // Subtract frequency using second string
    for (int i = 0; str2[i] != '\0'; i++) {
        if (!isspace((unsigned char)str2[i])) {
            count[tolower((unsigned char)str2[i])]--;
        }
    }

    // If all counts are zero, they are anagrams
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];

    printf("Enter first string: ");
    if (!fgets(str1, sizeof(str1), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }

    printf("Enter second string: ");
    if (!fgets(str2, sizeof(str2), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline characters from fgets
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    if (areAnagrams(str1, str2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are NOT anagrams.\n");
    }

    return 0;
}









