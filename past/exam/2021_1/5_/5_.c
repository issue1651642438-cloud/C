#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int monthday[]={31,28,31,30,31,30,31,31,30,31,30,31};
char weekdayname[7][20]={
    "Saturday","Sunday","Monday","Tuesday",
    "Wednesday","Thursday","Friday",
};


int year0=2000,month0=1,day0=1,week0=0;


int isrunnian(int year)
{
    if(year%400==0) return 1;
    if(year%100==0) return 0;
    if(year%4==0) return 1;

    return 0;
}


void rili(int n)
{
    int daysofyear=365,daysofmonth=monthday[month0-1];
    if(isrunnian(year0))
    {
        daysofyear++;
        if(month0==2) daysofmonth++;
    }
    if(n>=daysofyear)
    {
        year0++;
        rili(n-daysofyear);
    }else if(n>=daysofmonth)
    {
        month0++;
        rili(n-daysofmonth);
    }else{
        day0+=n;
    }
}


void week(int n)
{
    week0=n%7;
}


int main()
{
    int n=0;
    while(scanf("%d",&n)==1)
    {
        if(n==-1) break;
        year0=2000;month0=1;day0=1;week0=0;
        rili(n);week(n);
        printf("%d-%02d-%02d %s\n",year0,month0,day0,weekdayname[week0]);

    }
    return 0;
}