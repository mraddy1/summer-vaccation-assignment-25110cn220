#include <stdio.h>
#include <stdlib.h>

// Function to right rotate the array by k positions
void rightRotate(int arr[], int n, int k) {
    if (n <= 0) return; // No rotation for empty array

    k = k % n; // Handle cases where k >= n
    if (k == 0) return; // No rotation needed

    int *temp = (int *)malloc(k * sizeof(int));
    if (!temp) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Step 1: Copy last k elements to temp
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Step 2: Shift remaining elements to the right
    for (int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    // Step 3: Copy temp elements to the front
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }

    free(temp);
}

int main() {
    int n, k;

    // Input array size
    printf("Enter number of elements in array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Must be a positive integer.\n");
        return 1;
    }

    int arr[n];

    // Input array elements
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    // Input rotation count
    printf("Enter number of positions to rotate right: ");
    if (scanf("%d", &k) != 1 || k < 0) {
        printf("Invalid rotation count. Must be non-negative.\n");
        return 1;
    }

    // Perform rotation
    rightRotate(arr, n, k);

    // Output rotated array
    printf("Array after right rotation: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}















