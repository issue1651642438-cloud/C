#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    scanf("%d",&n);

    int isprime_=1,i=0;
    for(i=2;i*i<n;i++)
    {
        int n0=n;
        if(n0%i==0)
        {
            isprime_=0;

            while(n0>=i)
            {
                n0/=i;
                if(n0==1)
                {
                    isprime_=1;
                    break;
                }
            }
        }
        if(n0==1)
        {
            isprime_=1;
            break;
        }
    }

    if(isprime_)
    {
        printf("YES");
    }else{
        printf("NO");
    }

    return 0;
}