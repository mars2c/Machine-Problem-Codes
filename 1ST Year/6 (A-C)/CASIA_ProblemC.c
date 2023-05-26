#include <stdio.h>
int main(){
    int num1, num2, num3, num4, numerator, denominator;

    printf("Enter first value (1st numerator): ");
    scanf("%d", &num1);

    printf("Enter second value (1st denominator): ");
    scanf("%d", &num2);

    printf("Enter third value (2nd numerator): ");
    scanf("%d", &num3);
    
    printf("Enter fourth value (2nd denominator): ");
    scanf("%d", &num4);

    numerator = (num1*num4)-(num2*num3);
    denominator = num2*num4;

    if(numerator == 0){
        printf("0");
        return 0;
    }

    if(denominator == 0){
        printf("Error\n");
        return 0;
    }

    printf("%d/%d - %d/%d = %d/%d",num1,num2,num3,num4,numerator,denominator);

    return 0;
}