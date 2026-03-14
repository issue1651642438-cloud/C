#include<stdio.h>

int prime[11],count=0;

int isprime(int p)
{
    if(p%2==0&&p!=2)
    {
        return 0;
    }else if(p==2)
    {
        prime[count++]=p;
        return 1;
    }else
    {
        for(int i=3;i*i<=p;i+=2)
        {
            if(p%i==0)
            {
                return 0;
            }
        }
    }
    prime[count++]=p;
    return 1;
}

int main()
{
    int m,k;
    scanf("%d%d",&m,&k);
    while(count!=k)
    {
        m++;
        isprime(m);
    }

    printf("%d",prime[0]);
    for(int i=1;i<k;i++)
    {
        printf(" %d",prime[i]);
    }
    return 0;
}