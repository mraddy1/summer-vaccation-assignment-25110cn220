#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n;

    // Input array size
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int arr[n];
    bool visited[n]; // To track counted elements

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
        visited[i] = false; // Initialize visited array
    }

    // Count frequency of each element
    printf("\nFrequency of each element:\n");
    for (int i = 0; i < n; i++) {
        if (visited[i] == true) {
            continue; // Skip already counted elements
        }

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }

        printf("%d occurs %d time(s)\n", arr[i], count);
    }

    return 0;
}












