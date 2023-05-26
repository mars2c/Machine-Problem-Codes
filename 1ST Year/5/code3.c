#include <stdio.h>

int main(){
int num1 = 10, num2 = 25;

num1++;
num2--;

printf("num1's  value is now %i.\n",num1);
printf("num2's  value is now %i.\n",num2); 

printf("num1's  value is now %i.\n",num1++);
printf("num2's  value is now %i.\n",num2--);  

printf("num1's  value is now %i.\n",num1);
printf("num2's  value is now %i.\n",num2); 

++num1;
--num2;

printf("num1's  value is now %i.\n",num1);
printf("num2's  value is now %i.\n",num2);  

printf("num1's  value is now %i.\n",++num1);
printf("num2's  value is now %i.\n",--num2); 
}