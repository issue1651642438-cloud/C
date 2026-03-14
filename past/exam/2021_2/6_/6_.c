#include<stdio.h>

void ni(int n,int m)
{
    int m0=m,sum=0;
    while(1)
    {
        sum+=m0;
        m0+=2;
        if(sum>=n)
        {
            break;
        }
    }
    if(sum==n)
    {
        printf("%d",m);
        for(int i=m+2;i<=m0-2;i+=2)
        {
            printf("+%d",i);
        }
    }else{
        ni(n,m+2);
    }
}

int main()
{
    int n=0;
    scanf("%d",&n);
    printf("%d*%d*%d=%d=",n,n,n,n*n*n);
    ni(n*n*n,1);
    return 0;
}