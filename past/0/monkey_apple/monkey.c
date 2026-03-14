#include<stdio.h>
int main()
{
    long n,k,m=1;
    scanf("%d%d",&n,&k);
    m=n+k;
    while(1)
    {
        long current=m;
        int valid=1;

        for(int i=0;i<n-1;i++)
        {
            if((current*n)%(n-1)!=0){
                valid=0;
                break;
            }
            current =(current*n)/(n-1)+k;
        }
        if(valid)
        {
            printf("%ld\n",current);
            break;
        }
        m+=n;
    }
    return 0;
}