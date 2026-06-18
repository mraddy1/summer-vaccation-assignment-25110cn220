#include <stdio.h>
#include <limits.h>

// Function to find the second largest distinct element
int findSecondLargest(int arr[], int n) {
    if (n < 2) {
        return INT_MIN; // Not enough elements
    }

    int first = INT_MIN, second = INT_MIN;

    for (int i = 0; i < n; i++) {
        int num = arr[i];

        // Update first and second largest
        if (num > first) {
            second = first;
            first = num;
        }
        else if (num > second && num < first) {
            second = num;
        }
    }

    return second;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    int secondLargest = findSecondLargest(arr, n);

    if (secondLargest == INT_MIN) {
        printf("Second largest element does not exist.\n");
    } else {
        printf("The second largest distinct element is: %d\n", secondLargest);
    }

    return 0;
}













