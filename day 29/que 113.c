#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double add(double a, double b)        { return a + b; }
double subtract(double a, double b)   { return a - b; }
double multiply(double a, double b)   { return a * b; }
double divide(double a, double b)     { return b != 0 ? a / b : NAN; }
int modulo(int a, int b)              { return b != 0 ? a % b : 0; }
double power(double a, double b)      { return pow(a, b); }

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    int choice;
    double num1, num2;
    int intNum1, intNum2;

    while (1) {
        printf("\n===== MENU-DRIVEN CALCULATOR =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulo\n");
        printf("6. Power\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        if (choice == 7) {
            printf("Exiting calculator. Goodbye!\n");
            break;
        }

        // For modulo, we use integers
        if (choice == 5) {
            printf("Enter two integers: ");
            if (scanf("%d %d", &intNum1, &intNum2) != 2) {
                printf("Invalid input! Please enter integers only.\n");
                clearInputBuffer();
                continue;
            }
        } else {
            printf("Enter two numbers: ");
            if (scanf("%lf %lf", &num1, &num2) != 2) {
                printf("Invalid input! Please enter numbers only.\n");
                clearInputBuffer();
                continue;
            }
        }

        switch (choice) {
            case 1:
                printf("Result: %.2lf\n", add(num1, num2));
                break;
            case 2:
                printf("Result: %.2lf\n", subtract(num1, num2));
                break;
            case 3:
                printf("Result: %.2lf\n", multiply(num1, num2));
                break;
            case 4:
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    printf("Result: %.2lf\n", divide(num1, num2));
                }
                break;
            case 5:
                if (intNum2 == 0) {
                    printf("Error: Modulo by zero is not allowed.\n");
                } else {
                    printf("Result: %d\n", modulo(intNum1, intNum2));
                }
                break;
            case 6:
                printf("Result: %.2lf\n", power(num1, num2));
                break;
            default:
                printf("Invalid choice! Please select between 1 and 7.\n");
        }
    }

    return 0;
}





























