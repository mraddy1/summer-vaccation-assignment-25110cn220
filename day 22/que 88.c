#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove all spaces from a string (in-place)
void removeSpaces(char *str) {
    if (str == NULL) return; // Null pointer check

    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (!isspace((unsigned char)str[i])) { // Keep only non-space characters
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0'; // Null-terminate the modified string
}

int main() {
    char str[256]; // Buffer for input string

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove trailing newline from fgets
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    removeSpaces(str);

    printf("String without spaces: \"%s\"\n", str);

    return 0;
}






