#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to count words in a sentence
int countWords(const char *str) {
    int count = 0;
    int inWord = 0; // Flag to track if we are inside a word

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace((unsigned char)str[i])) {
            // If we encounter a non-space character and we are not already in a word
            if (!inWord) {
                inWord = 1;
                count++;
            }
        } else {
            // If we encounter a space, mark that we are no longer in a word
            inWord = 0;
        }
    }
    return count;
}

int main() {
    char sentence[1000];

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline if present
    size_t len = strlen(sentence);
    if (len > 0 && sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }

    int wordCount = countWords(sentence);
    printf("Total number of words: %d\n", wordCount);

    return 0;
}




