#include<stdio.h>
#include<math.h>

int main()
{
    int k=0;
    long double num,power;
    scanf("%d",&k);

    num=sqrtl(2.0);

    for(int i=0;i<k-2;i++)
    {
        num=sqrt(2+num);
    }
    num=sqrtl(2-num);
    power=powl(2,k);
    printf("%.8Lf\n",power*num);
    return 0;
}