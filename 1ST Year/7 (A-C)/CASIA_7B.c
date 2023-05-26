#include <stdio.h>
int main(){

    float mm;

    printf("Enter a rainfall measurement in mm: ");
    scanf("%f", &mm);

    if(mm < 2.5)
    {
        printf("%f mm: Light Rainfall", mm);
    }
    else if((mm >= 2.5) && (mm <= 7.5))
    {
        printf("%f mm: Moderate Rainfall", mm);
    }
    else if((mm > 7.5) && (mm <= 15))
    {
        printf("%f mm: Heavy Rainfall [Yellow Warning: Flooding is possible.]", mm);
    }
    else if((mm > 15) && (mm <= 30))
    {
        printf("%f mm: Intense Rainfall [Orange Warning: Flooding is threatening.]", mm);
    }
    else if(mm > 30)
    {
        printf("%f mm: Torrential Rainfall [Red Warning: Serious flooding is expected in low lying areas. Residents are advised to evacuate.]", mm);
    }

return 0;
}