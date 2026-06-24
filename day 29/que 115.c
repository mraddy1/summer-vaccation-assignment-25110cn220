#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 200

// Function to safely read a string from stdin
void readString(char *str, int size) {
    if (fgets(str, size, stdin) != NULL) {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0'; // Remove newline
        }
    }
}

// Function to convert string to uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

// Function to convert string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    int choice;

    printf("Enter first string: ");
    readString(str1, MAX_LEN);

    printf("Enter second string: ");
    readString(str2, MAX_LEN);

    do {
        printf("\n===== STRING OPERATIONS MENU =====\n");
        printf("1. Length of strings\n");
        printf("2. Compare strings\n");
        printf("3. Concatenate strings\n");
        printf("4. Copy string 2 to string 1\n");
        printf("5. Convert string 1 to uppercase\n");
        printf("6. Convert string 2 to lowercase\n");
        printf("7. Reverse string 1\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        while (getchar() != '\n'); // Clear newline from buffer

        switch (choice) {
            case 1:
                printf("Length of string 1: %zu\n", strlen(str1));
                printf("Length of string 2: %zu\n", strlen(str2));
                break;

            case 2:
                if (strcmp(str1, str2) == 0)
                    printf("Strings are equal.\n");
                else
                    printf("Strings are not equal.\n");
                break;

            case 3:
                if (strlen(str1) + strlen(str2) < MAX_LEN) {
                    strcat(str1, str2);
                    printf("Concatenated string: %s\n", str1);
                } else {
                    printf("Error: Concatenation would exceed buffer size.\n");
                }
                break;

            case 4:
                strcpy(str1, str2);
                printf("String 1 after copy: %s\n", str1);
                break;

            case 5:
                toUpperCase(str1);
                printf("String 1 in uppercase: %s\n", str1);
                break;

            case 6:
                toLowerCase(str2);
                printf("String 2 in lowercase: %s\n", str2);
                break;

            case 7:
                reverseString(str1);
                printf("Reversed string 1: %s\n", str1);
                break;

            case 8:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}































