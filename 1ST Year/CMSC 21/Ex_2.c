#include <stdio.h>
//#include <conio.h>

int main(){
    int i, a, b;
    int quotient;
    int x, hcf; 
    int N, number[20], h, temp;

    scanf("%d", &i);

        if(i == 1 || i == 2){
            scanf("%d %d", &a, &b);
        }
        else if(i == 3){
            scanf("%d", &a);
        }

    switch(i){
        case 1: 
            
            quotient = 0;

            while(a < 1 || b < 1){
                return main();
            }

            while(a >= b){
                a -= b;
                quotient += 1;
            }

            printf("%d", quotient);

        break;

        case 2: 
            
            for(x = 1; x <= a; x++){
                if(a % x == 0 && b % x == 0){
                    hcf = x;
                }
            }

            if(hcf == 1){
                printf("1");
            }
            else{
                printf("0");
            }

        break;            

        case 3: 

            for (b = 0; b < a; ++b){
               scanf("%d", &number[b]);
            }

            scanf("%d", &N);

            for(b = 0; b < a; ++b){
                if(number[b] == N){
                    printf("1");
                    return 0;
                }
            }
            printf("0");
            
        break;            
    }

return 0;
}
