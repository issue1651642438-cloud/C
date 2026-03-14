#include<stdio.h>
#include<string.h>
long long int day,reday;

int monthday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int huiwen()
{
    reday=0;
    long long int day0=day;
    while(day0!=0)
    {
        reday=reday*10+day0%10;
        day0/=10;
    }   
    if(reday==day) return 1;
    return 0;
}

int runnian(int n)
{
    if(n%400==0) return 1;
    if(n%100==0) return 0;
    if(n%4==0) return 1;
    return 0;
}

int hefa()
{
    int year,month,day_;
    year=day/10000;
    month=(day%10000)/100;
    day_=day%100;
    if(month>=13)return 0;
    if(day_==0||month==0)return 0;

    if(month!=2){
        if(day_>monthday[month]) return 0;
    }else if(runnian(year))
    {
        if(day_>29) return 0;
    }else{
        if(day_>28) return 0;
    }
    return 1;
}


int main()
{
    long long n;
    scanf("%lld",&n);
    for(long long int i=10000101;i<n;i+=1)
    {
        day=i;
        if(!hefa()) continue;
        if(!huiwen()) continue;
        

       printf("%lld ",i);
    }
    return 0;
}
