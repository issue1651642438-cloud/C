#include<stdio.h>
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)==3)
    {
        int first=0;
        if(a+b==c)
        {
            printf("+");
            first++;
        }
        if(a-b==c)
        {
            if(first!=0)
            {
                printf(" ");
            }
            printf("-");
            first++;
        }
        if(a*b==c)
        {
            if(first!=0)
            {
                printf(" ");
            }
            printf("*");
            first++;
        }
        if(a/b==c)
        {
            if(first!=0)
            {
                printf(" ");
            }
            printf("/");
            first++;
        }
        if(a%b==c)
        {
            if(first!=0)
            {
                printf(" ");
            }
            printf("%%");
            first++;
        }
        if(first==0)
        {
            printf("No");
        }
        printf("\n");
    }
}