#include <stdio.h>
#include <stdlib.h>

// Function to merge two arrays into a third array
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i, j;

    // Copy elements of first array
    for (i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }

    // Copy elements of second array
    for (j = 0; j < size2; j++) {
        merged[i + j] = arr2[j];
    }
}

int main() {
    int size1, size2;

    // Input sizes of arrays
    printf("Enter size of first array: ");
    if (scanf("%d", &size1) != 1 || size1 < 0) {
        printf("Invalid size. Must be a non-negative integer.\n");
        return 1;
    }

    printf("Enter size of second array: ");
    if (scanf("%d", &size2) != 1 || size2 < 0) {
        printf("Invalid size. Must be a non-negative integer.\n");
        return 1;
    }

    // Allocate memory for arrays
    int arr1[size1], arr2[size2], merged[size1 + size2];

    // Input elements for first array
    printf("Enter %d elements for first array:\n", size1);
    for (int i = 0; i < size1; i++) {
        if (scanf("%d", &arr1[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    // Input elements for second array
    printf("Enter %d elements for second array:\n", size2);
    for (int i = 0; i < size2; i++) {
        if (scanf("%d", &arr2[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    // Merge arrays
    mergeArrays(arr1, size1, arr2, size2, merged);

    // Display merged array
    printf("Merged array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}




















