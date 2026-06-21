#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string in place
void reverseString(char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    // Swap characters from both ends moving towards the center
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

int main() {
    char str[256]; // Buffer for input string

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

    // Handle empty string case
    if (strlen(str) == 0) {
        printf("Empty string entered.\n");
        return 0;
    }

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}

