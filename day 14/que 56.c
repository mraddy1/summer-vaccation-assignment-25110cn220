#include <stdio.h>
#include <stdlib.h>

// Function to find and print duplicates in the array
void findDuplicates(int arr[], int n) {
    int found = 0;

    printf("Duplicate elements: ");
    for (int i = 0; i < n; i++) {
        // Skip if already checked
        int isChecked = 0;
        for (int k = 0; k < i; k++) {
            if (arr[k] == arr[i]) {
                isChecked = 1;
                break;
            }
        }
        if (isChecked) continue;

        // Count occurrences
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        // If count > 1, it's a duplicate
        if (count > 1) {
            printf("%d ", arr[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    int n;

    // Input array size
    printf("Enter number of elements in array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input array elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(arr);
            return 1;
        }
    }

    // Find and print duplicates
    findDuplicates(arr, n);

    free(arr);
    return 0;
}














