#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the element with maximum frequency
int findMaxFrequencyElement(int arr[], int n, int *maxFreq) {
    int maxElement = arr[0];
    *maxFreq = 1;

    for (int i = 0; i < n; i++) {
        int count = 1; // Count current element
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        // Update if higher frequency found or same frequency but larger element
        if (count > *maxFreq || (count == *maxFreq && arr[i] > maxElement)) {
            *maxFreq = count;
            maxElement = arr[i];
        }
    }
    return maxElement;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(arr);
            return 1;
        }
    }

    int maxFreq;
    int maxElement = findMaxFrequencyElement(arr, n, &maxFreq);

    printf("Element with maximum frequency: %d\n", maxElement);
    printf("Frequency: %d\n", maxFreq);

    free(arr);
    return 0;
}


















