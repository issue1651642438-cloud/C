#include<stdio.h>
#define MAX 100
int main()
{
    int n,m,temp;
    int a[MAX];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++)
    {
        temp =a[n-1];
        for(int i=n-1;i>0;i--)
        {
            a[i]=a[i-1];
        }
        a[0]=temp;
    }
    printf("%d",a[0]);
    for(int i=1;i<n;i++)
    {
        printf(" %d",a[i]);
    }
    return 0;
}