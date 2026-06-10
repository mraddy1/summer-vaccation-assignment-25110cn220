#include <stdio.h>
#include <math.h>
int main() {
   int number, originalNumber, remainder, sum = 0, digits = 0;
   // Input the number
   printf("Enter an integer: ");
   scanf("%d", &number);
   originalNumber = number;
   // Calculate the number of digits
   while (originalNumber != 0) {
       originalNumber /= 10;
       digits++;
   }
   originalNumber = number;
   // Calculate the sum of each digit raised to the power of 'digits'
   while (originalNumber != 0) {
       remainder = originalNumber % 10;
       sum += pow(remainder, digits);
       originalNumber /= 10;
   }
   // Check if the sum equals the original number
   if (sum == number)
       printf("%d is an Armstrong number.\n", number);
   else
       printf("%d is not an Armstrong number.\n", number);
   return 0;
}



