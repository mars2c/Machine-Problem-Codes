#include <stdio.h>
#include <stdlib.h>

struct Fractions{
    int num;
    int den;
};
typedef struct Fractions Fractions;

int subgcd(int n, int d){
    int gcd, r;

    r = 0;

    while(n != 0){
        r = d % n;
        d = n;
        n = r;  
    }

    gcd = d;

    return gcd;
}

int main(){
    Fractions frac;
    int in;
    int numA, denA = 1, numB, denB = 1;
    int num5, den5;
    int sum, diff, prod, quotient;
    int numeX, numeY, deno;

//input values from 1 to 5
    scanf("%d", &in);

//input values depending on what number was chosen
        if(in == 1 || in == 2 || in == 3 || in == 4){
            scanf("%d/%d %d/%d", &numA, &denA, &numB, &denB);
        }
        else if(in == 5){
            scanf("%d/%d", &num5, &den5);
        }
    
    sum = 0;
    diff = 0;
    prod = 0;
    quotient = 0;
    numeX = 0;
    numeY = 0;
    deno = 0;

    switch(in){
        case 1: //sum of fractions

            if(denA == denB){

                sum = numA + numB;

                if(sum == 0){
                    printf("0");
                }
                else{

                    frac.num = sum / subgcd(sum, denA);
                    frac.den = denA / subgcd(sum, denA);

                    if(frac.den == 1){
                        printf("%d", frac.num);
                    }
                    else{
                        printf("%d/%d", frac.num, frac.den);
                    }

                }

            }
            else{

                deno = denA * denB;
                numeX = numA * denB;
                numeY = numB * denA;

                sum = numeX + numeY;

                 if(sum == 0){
                    printf("0");
                }
                else if(deno == 0){
                    printf("Math Error");
                }
                else{

                    frac.num = sum / subgcd(sum, deno);
                    frac.den = deno / subgcd(sum, deno);

                    if(frac.den == 1){
                        printf("%d", frac.num);
                    }
                    else{
                        printf("%d/%d", frac.num, frac.den);
                    }

                }

            }

            break;

        case 2: // difference of fractions

            if(denA == denB){

                diff = numA - numB;
                
                if(diff == 0){
                    printf("0");
                }
                else{
                    
                    frac.num = diff / subgcd(diff, denA);
                    frac.den = denA / subgcd(diff, denA);

                    if(frac.den == 1){
                        printf("%d", frac.num);
                    }
                    else{
                        printf("%d/%d", frac.num, frac.den);
                    }

                }

            }
            else{

                deno = denA * denB;
                numeX = numA * denB;
                numeY = numB * denA;

                diff = numeX - numeY;

                if(diff == 0){
                    printf("0");
                }
                else if(deno == 0){
                    printf("Math Error");
                }
                else{
                    
                    frac.num = diff / subgcd(diff, deno);
                    frac.den = deno / subgcd(diff, deno);

                    if(frac.den == 1){
                        printf("%d", frac.num);
                    }
                    else{
                        printf("%d/%d", frac.num, frac.den);
                    }

                }

            }

            break;

        case 3: //product of fractions

            numeX = numA * numB;
            deno = denA * denB;

            if(numeX == 0){
                printf("0");
            }
            else if(deno == 0){
                printf("Math Error");
            }
            else{

                frac.num = numeX / subgcd(numeX, deno);
                frac.den = deno / subgcd(numeX, deno);

                if(frac.den == 1){
                    printf("%d", frac.num);
                }
                else{
                    printf("%d/%d", frac.num, frac.den);
                }


            }

            break;

        case 4: //quotient of fractions

            numeY = numA * denB;
            deno = denA * numB;

            if(numeY == 0){
                printf("0");
            }
            else if(deno == 0){
                printf("Math Error");
            }
            else{

                frac.num = numeY / subgcd(numeY, deno);
                frac.den = deno / subgcd(numeY, deno);

                if(frac.den == 1){
                    printf("%d", frac.num);
                }
                else{
                    printf("%d/%d", frac.num, frac.den);
                }

                
            }

            break;

        case 5: //simplified fraction

        frac.num = num5 / subgcd(num5, den5);
        frac.den = den5 / subgcd(num5, den5);

        printf("%d/%d", frac.num, frac.den);

            break;
    }

return 0;
}
