#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[100],b[100];
    int n;
    while(scanf("%d",&n)==1)
    {
        int suma=0,sumb=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            suma+=a[i];
        }
        for(int j=0;j<n;j++)
        {
            scanf("%d",&b[j]);
            sumb+=b[j];
        }
        if(suma>=55) suma-=20;
        if(suma>sumb)
        {
            printf("2\n");
        }else if(suma<sumb)
        {
            printf("1\n");
        }else
        {
            printf("3\n");
        }
    }
    return 0;
}