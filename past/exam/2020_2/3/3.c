#include<stdio.h>

int main()
{
    int n,t;
    int a[1005];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    scanf("%d",&t);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]+a[j]==t)
            {
                printf("%d %d",i,j);
                return 0;
            }
        }
    }
    return 0;
}