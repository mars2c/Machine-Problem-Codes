#include <stdio.h>
int main(){
    int num, sec, min, hr, day, month, year;

    printf("Enter time in seconds: "); //this should represent the seconds in time
    scanf("%d",&num);

    //compute how many years, months, days, hours, minutes, and seconds it has been from Jan. 1, 1970

    year = num/(12*30*24*3600);
    month = (num%31104000)/(30*24*3600);
    day = (num%2592000)/(24*3600);
    hr = (num%86400)/3600;
    min = (num%3600)/60;
    sec = num % 60;

    printf("%d seconds/s is %d year/s, %d month/s, %d day/s, %d hour/s, %d minute/s, and %d second/s",num,year,month,day,hr,min,sec);

    return 0;

}
//NOTE! 
//1 min = 60 secs
//1 hr = 3,600 secs
//1 day = 86,400 secs
//1 month = 2,592,000 secs
//1 year = 31,104,000 secs