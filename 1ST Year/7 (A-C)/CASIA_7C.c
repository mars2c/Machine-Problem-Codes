#include <stdio.h>
int main(){

    int m, d;

    printf("Enter birth month (numerical form): ");
    scanf("%d", &m);

    printf("Enter birth day: ");
    scanf("%d", &d);

    if((m == 1) && (d >= 1) && (d <= 19) || (m == 12) && (d >= 22) && (d <= 31))
    {
        printf("Zodiac Sign: Capricorn \n Horoscope: Of course you have a purpose -- to find a purpose."); 
    }
    else if((m == 1) && (d >= 20) && (d <= 31) || (m == 2) && (d >= 1) && (d <= 18))
    {
        printf("Zodiac Sign: Aquarius \n Horoscope: Are you a turtle?");
    }
    else if((m == 2) && (d >= 19) && (d <= 29) || (m == 3) && (d >= 1) && (d <= 20))
    {
        printf("Zodiac Sign: Pisces \n Horoscope: Write yourself a threatening letter and pen a defiant reply.");
    }
    else if((m == 3) && (d >= 21) && (d <= 31) || (m == 4) && (d >= 1) && (d <= 19))
    {
        printf("Zodiac Sign: Aries \n Horoscope: You will pay for your sins. If you have already paid, please disregard this message.");
    }
    else if((m == 4) && (d >= 20) && (d <= 30) || (m == 5) && (d >= 1) && (d <= 20))
    {
        printf("Zodiac Sign: Taurus \n Horoscope: Be free and open and breezy! Enjoy! Things won't get any better so get used to it.");
    }
    else if((m == 5) && (d >= 21) && (d <= 31) || (m == 6) && (d >= 1) && (d <=20))
    {
        printf("Zodiac Sign: Gemini \n Horoscope: You two ought to be more careful--your love could drag on for years and years.");
    }
    else if((m == 6) && (d >= 21) && (d <=30) || (m == 7) && (d >= 1) && (d <= 22))
    {
        printf("Zodiac Sign: Cancer \n Horoscope: A few hours grace before the madness begins again.");
    }
    else if((m == 7) && (d >= 23) && (d <= 31) || (m == 8) && (d >= 1) && (d <= 22))
    {
        printf("Zodiac Sign: Leo \n Horoscope: Good news. Ten weeks from Friday will be a pretty good day.");
    }
    else if((m == 8) && (d >= 23) && (d <= 31) || (m == 9) && (d >= 1) && (d <= 22))
    {
        printf("Zodiac Sign: Virgo \n Horoscope: Don't look now, but there is a multi-legged creature on your shoulder.");
    }
    else if ((m == 9) && (d >= 23) && (d <= 30) || (m == 10) && (d >= 1) && (d <= 22))
    {
        printf("Zodiac Sign: Libra \n Horoscope: You are scrupulously honest, frank, and straightforward. Therefore you have few friends.You are scrupulously honest, frank, and straightforward. Therefore you have few friends.");
    }
    else if((m == 10) && (d >= 23) && (d <= 31) || (m == 11) && (d >= 1) && (d <= 21))
    {
        printf("Zodiac Sign: Scorpio \n Horoscope: You have the body of a 19 year old. Please return it before it gets wrinkled.");
    }
    else if((m == 11) && (d >= 22) && (d <= 30) || (m == 12) && (d >= 1) && (d <= 21))
    {
        printf("Zodiac Sign: Saigttarius \n Horoscope: If you learn one useless thing every day, in a single year you'll learn 365 useless things.");
    }
    else if((m > 12) && (d > 31))
    {
        printf("This date does not exist.");
    }
return 0;

}