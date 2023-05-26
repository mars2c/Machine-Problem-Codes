#include <stdio.h>
#include <string.h>

struct date{
    int year;
    int month;
    int day;
};
typedef struct date date;

int birthdate(date Date){
    int dates[12] = {19, 18, 20, 19, 20, 20, 22, 22, 22, 22, 21, 21};
    int z = 9;

    if(Date.day <= dates[Date.month - 1]){
        z = 8;
    }

    return (Date.month + z) % 12;
}

char* zodiac(date M){
    switch (M.month){
        case 1:
            if(M.day >= 1 && M.day <= 19){
                return "Capricorn";
            }
            else if(M.day >= 20  && M.day <= 31){
                return "Aquarius";
            }

        case 2:
            if(M.day >= 1 && M.day <= 18){
                return "Aquarius";
            }
            else if(M.day >= 19 && M.day <= 29){
                return "Pisces";
            }

        case 3:
            if(M.day >= 1 && M.day <= 20){
                return "Pisces";
            }
            else if(M.day >= 21 && M.day <= 31){
                return "Aries";
            }

        case 4:
            if(M.day >= 1 && M.day <= 19){
                return "Aries";
            }
            else if(M.day >= 20 && M.day <= 30){
                return "Taurus";
            }

        case 5:
            if(M.day >= 1 && M.day <= 20){
                return "Taurus";
            }
            else if(M.day >= 21 && M.day <= 31){
                return "Gemini";
            }

        case 6:
            if(M.day >= 1 && M.day <= 20){
                return "Gemini";
            }
            else if(M.day >= 21 && M.day <= 30){
                return "Cancer";
            }
            
        case 7:
            if(M.day >= 1 && M.day <= 22){
                return "Cancer";
            }
            else if(M.day >= 23 && M.day <= 31){
                return "Leo";
            }

        case 8:
            if(M.day >= 1 && M.day <= 22){
                return "Leo";
            }
            else if(M.day >= 23 && M.day <= 31){
                return "Virgo";
            }

        case 9:
            if(M.day >= 1 && M.day <= 22){
                return "Virgo";
            }
            else if(M.day >= 23 && M.day <= 30){
                return "Libra";
            }

        case 10:
            if(M.day >= 1 && M.day <= 22){
                return "Libra";
            }
            else if(M.day >= 23 && M.day <= 31){
                return "Scorpio";
            }

        case 11:
            if(M.day >= 1 && M.day <= 21){
                return "Scorpio";
            }
            else if(M.day >= 22 && M.day <= 30){
                return "Sagittarius";
            }

        case 12:
            if(M.day >= 1 && M.day <= 21){
                return "Sagittarius";
            }
            else if(M.day >= 22 && M.day <= 31){
                return "Capricorn";
            }
    }
}

int main(){
    FILE* fp = fopen("data.for", "r");
    FILE* fp2 = fopen("data.in", "a+");
    date D, comp;
    char name;
    char* zod;
    int temp;
    int i = 0, j = 0;

    if(!fp || !fp2){
        printf("Oh no, an error occurred!");
        return -1;
    }

    scanf("%d %d %d", &D.year, &D.month, &D.day);
    zod = zodiac(D);
    temp = birthdate(D);

    while(fscanf(fp2, "%d-%d-%d", &comp.year,&comp.month,&comp.day) != EOF){
        if(birthdate(D) == temp){
            j++;
        }

        j %= 5;

    }

    printf("%s: ", zod);
    while(fscanf(fp, "%c", &name) != EOF){
        if(i == temp + (j * 12)){
            printf("%c", name);
        }

        if(name == '\n'){
            i++;
        }
    }

    fprintf(fp2, "%d-", D.year);
    if(D.month < 10){
        fprintf(fp2, "0%d-", D.month);
    }
    else{
        fprintf(fp2, "%d-", D.month);
    }

    if(D.day < 10){
        fprintf(fp2, "0%d-", D.day);
    }
    else{
        fprintf(fp2, "%d-", D.day);
    }


    fclose(fp2);
    fclose(fp);

    return 0; 

}