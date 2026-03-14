#include<stdio.h>
#include<math.h>

int fenjie(int num,int min)
{
    int fjfa=1;
    for(int i=min;i*i<=num;i++)
    {
        if((num%i)==0)
        {
            fjfa+=fenjie(num/i,i);
        }
    }
    return fjfa;
}

int main()
{
    int n;
    scanf("%d",&n);
    int num[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",fenjie(num[i],2));
    }
    return 0;
}