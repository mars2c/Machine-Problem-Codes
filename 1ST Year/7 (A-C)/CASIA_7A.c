#include <stdio.h>
int main(){
    int number[3];    
    int a, b, c, d;

    printf("Enter three values: ");
    scanf("%d %d %d", &a, &b, &c);
    if((a>=b) && (a>=c))
    {
        if(b>=c)
        {
            printf("Descending order: %d &d &d", a, b, c);
        }
        else
        {
            printf("Descending order: %d %d %d", a, c, b);
        }
    }
    else if((b>=a) && (b>=c))
    {
        if(a>=c)
        {
            printf("Descending order: %d %d %d", b, a, c);
        }
        else
        {
            printf("Descending order: %d %d %d", b, c, a);
        }
    }
    else if((c>=a) && (c>=b))
    {
        if(a>=b)
        {
            printf("Descending order: %d %d %d", c, a, b);
        }
        else
        {
            printf("Descending order: %d %d %d", c, b, a);
        }
    }
    return 0;
}