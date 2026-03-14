#include<stdio.h>
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        int b[8]={0},totalbit=0;
        for(int i=0;i<8;i++)
        {
            b[i] = n%2;
            totalbit+=b[i];
            n/=2;
        }
        if(b[7]==1)
        {
            printf("is not ASCII!\n");
            continue;
        }
        if(totalbit%2!=m)
        {
            b[7]=1;
        }
        for(int i=7;i>=0;i--)
        {
            printf("%2d",b[i]);
        }
        printf("\n");
    }
    return 0;
}