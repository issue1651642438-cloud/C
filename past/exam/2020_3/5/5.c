#include<stdio.h>
#include<stdlib.h>

int isrun(int y)
{
    if(y%400==0) return 1;
    if(y%100==0) return 0;
    if(y%4==0) return 1;
    return 0;
}

int week(int year)
{
    int day=0;
    for(int i=1900;i<year;i++)
    {
        day+=365+isrun(i);
    }
    day+=31+28+31+30+4+isrun(year);

    return (day+1)%7;
}

int main()
{
    int t,x[11], idex[11];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&x[i]);
        int n=week(x[i]);
        if(n==0||n==6) idex[i]=0;
        else idex[i]=1;
    }
    for(int i=0;i<t;i++)
    {
        if(idex[i]==0)printf("No\n");
        else printf("Yes\n");
    }
}