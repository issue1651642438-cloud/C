#include<stdio.h>

int is7(int num)
{
    if(num%7==0) return 1;

    while(num!=0)
    {
        if(num%10==7) return 1;
        num/=10;
    }
    return 0;
}

int main()
{
    int max=0,total=0;
    scanf("%d",&max);

    for(int i=1;i<=max;i++)
    {
        if(is7(i)==0) total+=i*i;
    }

    printf("%d",total);
    return 0;
}