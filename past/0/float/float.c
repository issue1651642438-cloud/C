#include <stdio.h>

int main()
{
    int a,b;

    scanf("%d%d",&a,&b);

    double c=(double)a/b;

    printf("%.9lf",c);

    return 0;
}