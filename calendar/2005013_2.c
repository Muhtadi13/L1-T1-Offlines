#include <stdio.h>

void showcalendar(int y, int m)
{
    int h, ytemp=y, daycount, i, gap;

    if(m==1 || m==2)
    {
        m+=12;
        y=y-1;
    }
    h=(1+((26*(m+1))/10)+y+(y/4)+6*(y/100)+(y/400))%7;

    if(m==13||m==3||m==5||m==7||m==8||m==10||m==12)
        daycount=31;

    if(m==4||m==6 || m==9 ||m==11)
        daycount=30;

    if(m==14)
    {
        if(ytemp%4==0)
        {
            if(ytemp%100==0 && ((ytemp/100)%4)!=0)
            daycount=28;
            else daycount=29;

        }
        else daycount=28;
    }
    printf("\n\nCalendar for:\n\n");

    switch(m)
    {
        case 3: printf("MARCH");
         break;
        case 4: printf("APRIL");
         break;
        case 5: printf("MAY");
         break;
        case 6: printf("JUNE");
         break;
        case 7: printf("JULY");
         break;
        case 8: printf("AUGUST");
         break;
        case 9: printf("SEPTEBBER");
         break;
        case 10: printf("OCTOBER");
         break;
        case 11: printf("NOVEMBER");
         break;
        case 12: printf("DECEMBER");
         break;
        case 13: printf("JANUARY");
         break;
        case 14: printf("FEBRUARY");
    }


    printf(",%d \n \n", ytemp);

    printf("SUN  MON  TUE  WED  THU  FRI  SAT\n");

    gap=(h+6)%7;

    for(i=0; i<gap; i++)
    {
        printf("     ");
    }
    for(i=0;i<daycount;i++)
    {
        printf("%-2d   ", i+1);
        if((i+gap+1)%7==0) printf("\n");
    }

    printf("\n\n");


}

int main()
{
    int year, month;

    printf("Enter year : ");
    scanf("%d", &year);

    printf("Enter month(1-12) : ");
    scanf("%d", &month);


    showcalendar(year, month);
    return 0;
}
