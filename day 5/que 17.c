#include <stdio.h>
// Function to check if a number is perfect
int isPerfect(int num) {
   int sum = 0;
   for (int i = 1; i <= num / 2; i++) {
       if (num % i == 0) {
           sum += i;
       }
   }
   return (sum == num);
}
int main() {
   int num;
   printf("Enter a number: ");
   scanf("%d", &num);
   if (isPerfect(num)) {
       printf("%d is a Perfect Number.\n", num);
   } else {
       printf("%d is Not a Perfect Number.\n", num);
   }
   return 0;
}