#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRINGS 50
#define MAX_LEN 100

// Function to find common characters in all strings
void findCommonChars(char strings[][MAX_LEN], int n) {
    int freq[256] = {0}; // Frequency array for ASCII characters
    int temp[256];
    
    // Initialize frequency with first string's characters
    for (int i = 0; strings[0][i] != '\0'; i++) {
        unsigned char ch = strings[0][i];
        freq[ch] = 1; // Mark presence in first string
    }

    // Process remaining strings
    for (int s = 1; s < n; s++) {
        memset(temp, 0, sizeof(temp)); // Reset temp array
        for (int i = 0; strings[s][i] != '\0'; i++) {
            unsigned char ch = strings[s][i];
            temp[ch] = 1; // Mark presence in current string
        }
        // Update freq: keep only chars present in all processed strings
        for (int c = 0; c < 256; c++) {
            if (freq[c] == 1 && temp[c] == 1) {
                freq[c] = 1; // Still common
            } else {
                freq[c] = 0; // Not common anymore
            }
        }
    }

    // Display common characters
    printf("Common characters: ");
    int found = 0;
    for (int c = 0; c < 256; c++) {
        if (freq[c] == 1 && c != ' ' && c != '\n') { // Ignore spaces/newlines
            printf("%c ", c);
            found = 1;
        }
    }
    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    int n;
    char strings[MAX_STRINGS][MAX_LEN];

    printf("Enter number of strings: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_STRINGS) {
        printf("Invalid number of strings.\n");
        return 1;
    }
    getchar(); // Clear newline from buffer

    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        if (!fgets(strings[i], sizeof(strings[i]), stdin)) {
            printf("Error reading string.\n");
            return 1;
        }
        strings[i][strcspn(strings[i], "\n")] = '\0'; // Remove newline
    }

    findCommonChars(strings, n);

    return 0;
}















