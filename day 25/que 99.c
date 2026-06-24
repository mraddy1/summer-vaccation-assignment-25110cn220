#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAMES 100     // Maximum number of names
#define MAX_LENGTH 100    // Maximum length of each name

// Function to safely read a string (removes newline)
void readString(char *str, int size) {
    if (fgets(str, size, stdin)) {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0'; // Remove newline
        }
    }
}

int main() {
    char names[MAX_NAMES][MAX_LENGTH];
    int n;

    printf("Enter number of names (1-%d): ", MAX_NAMES);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_NAMES) {
        printf("Invalid number of names.\n");
        return 1;
    }

    // Clear input buffer after reading integer
    while (getchar() != '\n');

    // Input names
    for (int i = 0; i < n; i++) {
        printf("Enter name %d: ", i + 1);
        readString(names[i], MAX_LENGTH);

        // Validate non-empty name
        if (strlen(names[i]) == 0) {
            printf("Name cannot be empty.\n");
            return 1;
        }
    }

    // Sorting using simple bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                char temp[MAX_LENGTH];
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    // Display sorted names
    printf("\nNames in alphabetical order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
















