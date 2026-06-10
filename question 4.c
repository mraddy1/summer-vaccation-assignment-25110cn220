#include <stdio.h>
#include <stdlib.h> 
int countDigits(int num) {
    if (num == 0) {
        return 1;
    }

    int count = 0;
    num = abs(num); 

    while (num > 0) {
        num /= 10; 
        count++;
    }
    return count;
}

int main() {
    int number;

    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    int digits = countDigits(number);
    printf("Number of digits: %d\n", digits);

    return 0;
}

