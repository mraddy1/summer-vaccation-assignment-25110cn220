#include <stdio.h>

// Function to find string length without using strlen()
int stringLength(const char *str) {
    int length = 0;

    // Validate input
    if (str == NULL) {
        return -1; // Return -1 for NULL pointer
    }

    // Count characters until null terminator
    while (str[length] != '\0') {
        length++;
    }

    return length;
}

int main() {
    char str[100];

    printf("Enter a string: ");

    // Read input safely (avoids buffer overflow)
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline character if present
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }

    int length = stringLength(str);

    if (length == -1) {
        printf("Invalid string.\n");
    } else {
        printf("Length of the string: %d\n", length);
    }

    return 0;
}
