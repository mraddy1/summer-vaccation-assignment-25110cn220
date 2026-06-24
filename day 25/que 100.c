#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN 100

// Structure to store word and its original position (for stable sorting)
typedef struct {
    char word[MAX_LEN];
    int original_index;
} Word;

// Comparator for qsort: sort by length, then by original index for stability
int compare_words(const void *a, const void *b) {
    const Word *wa = (const Word *)a;
    const Word *wb = (const Word *)b;

    int len_a = strlen(wa->word);
    int len_b = strlen(wb->word);

    if (len_a != len_b) {
        return len_a - len_b; // shorter words first
    }
    return wa->original_index - wb->original_index; // preserve original order
}

int main() {
    Word words[MAX_WORDS];
    int n;

    printf("Enter number of words (max %d): ", MAX_WORDS);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_WORDS) {
        printf("Invalid number of words.\n");
        return 1;
    }

    printf("Enter %d words:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%99s", words[i].word) != 1) { // limit to avoid buffer overflow
            printf("Invalid input.\n");
            return 1;
        }
        words[i].original_index = i;
    }

    // Sort words by length
    qsort(words, n, sizeof(Word), compare_words);

    printf("\nWords sorted by length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i].word);
    }

    return 0;
}

















