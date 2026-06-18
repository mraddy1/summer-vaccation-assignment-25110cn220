#include <stdio.h>
#include <stdlib.h>

// Recursive Binary Search function
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid; // Found

        if (arr[mid] > target)
            return binarySearchRecursive(arr, left, mid - 1, target);

        return binarySearchRecursive(arr, mid + 1, right, target);
    }
    return -1; // Not found
}

// Iterative Binary Search function
int binarySearchIterative(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid; // Found

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Not found
}

int main() {
    int n, target;

    printf("Enter number of elements in sorted array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d sorted integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    printf("Enter the element to search: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    // Iterative search
    int resultIter = binarySearchIterative(arr, n, target);
    if (resultIter != -1)
        printf("[Iterative] Element found at index %d\n", resultIter);
    else
        printf("[Iterative] Element not found.\n");

    // Recursive search
    int resultRec = binarySearchRecursive(arr, 0, n - 1, target);
    if (resultRec != -1)
        printf("[Recursive] Element found at index %d\n", resultRec);
    else
        printf("[Recursive] Element not found.\n");

    return 0;
}
























