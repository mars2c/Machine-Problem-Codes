#include <stdio.h>
int main(){
    float euro, rate, pesos;

    printf("Enter first value (money in Euro/s): \n");
    scanf("%f", &euro);
    printf("Enter second value (exchange rate): \n");
    scanf("%f", &rate);

    //convert euros to pesos with the exchange rate
    
    pesos = euro*rate;

    printf("%0.2f Euro/s with exchange rate of %0.2f is equal to %0.2f pesos.",euro,rate,pesos);

    return 0;
}
