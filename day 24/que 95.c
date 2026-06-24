#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to find the longest word in a string
void findLongestWord(const char *str, char *longestWord) {
    int maxLen = 0, currLen = 0;
    const char *wordStart = NULL;
    const char *ptr = str;

    while (*ptr) {
        // Skip leading spaces or punctuation
        while (*ptr && !isalnum((unsigned char)*ptr)) {
            ptr++;
        }

        // Start of a word
        wordStart = ptr;
        currLen = 0;

        // Count characters in the word
        while (*ptr && isalnum((unsigned char)*ptr)) {
            currLen++;
            ptr++;
        }

        // Update longest word if needed
        if (currLen > maxLen) {
            maxLen = currLen;
            strncpy(longestWord, wordStart, currLen);
            longestWord[currLen] = '\0'; // Null-terminate
        }
    }
}

int main() {
    char str[256];
    char longestWord[256] = "";

    printf("Enter a string: ");
    if (!fgets(str, sizeof(str), stdin)) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline if present
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    if (strlen(str) == 0) {
        printf("Empty string entered.\n");
        return 0;
    }

    findLongestWord(str, longestWord);

    if (strlen(longestWord) > 0) {
        printf("Longest word: %s\n", longestWord);
        printf("Length: %zu\n", strlen(longestWord));
    } else {
        printf("No valid word found.\n");
    }

    return 0;
}












