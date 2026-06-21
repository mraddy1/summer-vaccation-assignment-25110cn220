#include <stdio.h>
#include <ctype.h>   // For tolower() and isalpha()
#include <string.h>  // For strlen()

// Function to check if a character is a vowel
int isVowel(char ch) {
    ch = tolower((unsigned char)ch); // Convert to lowercase for uniformity
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    char str[500];
    int vowels = 0, consonants = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Loop through each character
    for (size_t i = 0; i < strlen(str); i++) {
        if (isalpha((unsigned char)str[i])) { // Check if it's a letter
            if (isVowel(str[i]))
                vowels++;
            else
                consonants++;
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}


