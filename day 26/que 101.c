#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    int secretNumber, guess, attempts = 0, maxAttempts = 10;
    char playAgain;

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    do {
        // Generate a random number between 1 and 100
        secretNumber = rand() % 100 + 1;
        attempts = 0;

        printf("\n=== Number Guessing Game ===\n");
        printf("I have chosen a number between 1 and 100.\n");
        printf("You have %d attempts to guess it.\n", maxAttempts);

        while (attempts < maxAttempts) {
            printf("\nAttempt %d: Enter your guess: ", attempts + 1);

            // Validate input
            if (scanf("%d", &guess) != 1) {
                printf("Invalid input! Please enter an integer.\n");
                clearInputBuffer();
                continue;
            }

            attempts++;

            if (guess < 1 || guess > 100) {
                printf("Please guess a number between 1 and 100.\n");
                continue;
            }

            if (guess == secretNumber) {
                printf("🎉 Congratulations! You guessed the number in %d attempts.\n", attempts);
                break;
            } else if (guess < secretNumber) {
                printf("Too low! Try again.\n");
            } else {
                printf("Too high! Try again.\n");
            }
        }

        if (attempts == maxAttempts && guess != secretNumber) {
            printf("\n❌ You've used all attempts! The number was %d.\n", secretNumber);
        }

        // Ask if the player wants to play again
        printf("\nDo you want to play again? (y/n): ");
        clearInputBuffer();
        playAgain = getchar();
        playAgain = tolower(playAgain);

    } while (playAgain == 'y');

    printf("\nThanks for playing! Goodbye.\n");
    return 0;
}


















