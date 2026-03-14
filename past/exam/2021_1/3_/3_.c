#include<stdio.h>
#include<math.h>

long long int katelanshu(int n)
{
    if(n==0) return 1;
    if(n==1) return 1;
    return ((4*n-2)*katelanshu(n-1))/(n+1);
}

int main()
{
    int n=0;
    scanf("%d",&n);
    long long int m=katelanshu(n);
    printf("%lld",m);
    return 0;
}