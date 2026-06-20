#include <stdio.h>

#define MAX_ROWS 50
#define MAX_COLS 50

int main() {
    int rows, cols;
    int matrix[MAX_ROWS][MAX_COLS];

    // Input matrix dimensions
    printf("Enter number of rows (1-%d): ", MAX_ROWS);
    if (scanf("%d", &rows) != 1 || rows < 1 || rows > MAX_ROWS) {
        printf("Invalid number of rows.\n");
        return 1;
    }

    printf("Enter number of columns (1-%d): ", MAX_COLS);
    if (scanf("%d", &cols) != 1 || cols < 1 || cols > MAX_COLS) {
        printf("Invalid number of columns.\n");
        return 1;
    }

    // Input matrix elements
    printf("Enter %d elements of the matrix:\n", rows * cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input. Please enter integers only.\n");
                return 1;
            }
        }
    }

    // Calculate and display row-wise sum
    printf("\nRow-wise sums:\n");
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        printf("Sum of row %d = %d\n", i + 1, sum);
    }

    return 0;
}






























