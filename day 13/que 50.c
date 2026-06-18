#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    double sum = 0.0, average = 0.0;

    // Ask for number of elements
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer for array size.\n");
        return 1;
    }

    double *arr = (double *)malloc(n * sizeof(double));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input array elements
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &arr[i]) != 1) {
            printf("Invalid input. Please enter numeric values only.\n");
            free(arr);
            return 1;
        }
        sum += arr[i];
    }

    // Calculate average
    average = sum / n;

    // Output results
    printf("\nSum of array elements: %.2lf\n", sum);
    printf("Average of array elements: %.2lf\n", average);

    // Free allocated memory
    free(arr);
    return 0;
}








