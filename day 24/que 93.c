#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if s2 is a rotation of s1
int isRotation(const char *s1, const char *s2) {
    // Check for NULL pointers
    if (s1 == NULL || s2 == NULL) {
        return 0;
    }

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // If lengths differ, they can't be rotations
    if (len1 != len2) {
        return 0;
    }

    // If both are empty strings, they are rotations
    if (len1 == 0) {
        return 1;
    }

    // Allocate memory for concatenated string
    char *concat = (char *)malloc((len1 * 2 + 1) * sizeof(char));
    if (!concat) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Concatenate s1 with itself
    strcpy(concat, s1);
    strcat(concat, s1);

    // Check if s2 is a substring of concatenated string
    int result = (strstr(concat, s2) != NULL);

    free(concat);
    return result;
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    if (scanf("%99s", str1) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter second string: ");
    if (scanf("%99s", str2) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (isRotation(str1, str2)) {
        printf("\"%s\" is a rotation of \"%s\".\n", str2, str1);
    } else {
        printf("\"%s\" is NOT a rotation of \"%s\".\n", str2, str1);
    }

    return 0;
}










