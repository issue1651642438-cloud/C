#include<stdio.h>
double f(int x)
{
    return 1.0/(1.0*x*(2*x-1));
}

int main()
{
    double d,total=0;
    int x=1;
    scanf("%lf",&d);

    while(f(x)>d)
    {
        total+=f(x);
        x++;
    }
    printf("%.6f %d",total,x-1);
    return 0;
}