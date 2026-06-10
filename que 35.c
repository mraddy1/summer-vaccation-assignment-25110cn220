#include <stdio.h>
#include <ctype.h> // for isalpha

int main() {
    int n = 5; // Number of lines (A to E)
    
    // Validate n to be between 1 and 26 (A-Z)
    if (n < 1 || n > 26) {
        printf("Error: Number of lines must be between 1 and 26.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        char ch = 'A' + i; // Current character
        for (int j = 0; j <= i; j++) {
            printf("%c", ch);
        }
        printf("\n"); // Move to next line
    }

    return 0;
}





