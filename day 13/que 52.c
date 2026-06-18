#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Ask for the number of elements
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int arr[n];
    int evenCount = 0, oddCount = 0;

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    // Count even and odd numbers
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    // Display results
    printf("Total even numbers: %d\n", evenCount);
    printf("Total odd numbers: %d\n", oddCount);

    return 0;
}










