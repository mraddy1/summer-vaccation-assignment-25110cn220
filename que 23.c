#include <stdio.h>
int countSetBits(unsigned int num) {
   int count = 0;
   while (num) {
       count += num & 1; // Check if the least significant bit is 1
       num >>= 1; // Right shift to process the next bit
   }
   return count;
}
int main() {
   unsigned int num = 103;
   printf("Number of set bits: %d\n", countSetBits(num));
   return 0;
}



