#include<stdio.h>

int isperfect(int n)
{
    int i=1,sum=0;
    for(i=1;i<=n/2;i++){
        ( n%i==0 )?(sum+=i):(sum+=0);
    }
    if(sum==n) printf("%d ",n);
    return 0;
}

int main()
{
    int max=0;
    scanf("%d",&max);
    int m=0;
    for(m=1;m<max;m++){
        isperfect(m);
    }
    return 0;
}