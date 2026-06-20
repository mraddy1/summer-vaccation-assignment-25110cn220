#include<stdio.h>
int main(){
    int num,reverse=0,rem;
    printf("enter a number: ");
    scanf("%d\n",&num);
    
    while(num !=0){
        rem = num%10;
        reverse = reverse * 10 + rem;
        num = num/10;
    }
    
    printf("reverse number = %d", reverse);
    
    return 0;
}