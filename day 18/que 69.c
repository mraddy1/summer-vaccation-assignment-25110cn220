#include <stdio.h>
void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}
void bubbleSort(int arr[], int n) {
   for (int i = 0; i < n - 1; i++) {
       int swapped = 0;
       for (int j = 0; j < n - i - 1; j++) {
           if (arr[j] > arr[j + 1]) {
               swap(&arr[j], &arr[j + 1]);
               swapped = 1;
           }
       }
       if (!swapped) break; // Optimization: stop if already sorted
   }
}
void selectionSort(int arr[], int n) {
   for (int i = 0; i < n - 1; i++) {
       int minIndex = i;
       for (int j = i + 1; j < n; j++) {
           if (arr[j] < arr[minIndex])
               minIndex = j;
       }
       swap(&arr[minIndex], &arr[i]);
   }
}
void printArray(int arr[], int n) {
   for (int i = 0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
int main() {
   int arr1[] = {64, 25, 12, 22, 11};
   int arr2[] = {64, 25, 12, 22, 11};
   int n = sizeof(arr1) / sizeof(arr1[0]);
   printf("Original array: ");
   printArray(arr1, n);
   bubbleSort(arr1, n);
   printf("Sorted with Bubble Sort: ");
   printArray(arr1, n);
   selectionSort(arr2, n);
   printf("Sorted with Selection Sort: ");
   printArray(arr2, n);
   return 0;
}






















