#include<stdio.h>
#include<math.h>


long long henoi(long k,long n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(k==3) return 2*henoi(k,n-1)+1;
    long long min_step=__LONG_LONG_MAX__;
    for(int m=1;m<n;m++)
    {
        long long step=2*henoi(k,n-m)+henoi(k-1,m);
        if(step<min_step)min_step=step;
    }
    return min_step;
}


int main()
{
    long long k,n;
    scanf("%lld%lld",&k,&n);
    long long number=henoi(k,n);
    printf("%d",number);
    return 0;
}